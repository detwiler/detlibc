/*
 * Copyright (C) 2010  J. Michael Detwiler
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * Based on code from APUE
 */

#include "system.h"

#include <det/daemon.h>

int
det_daemonize(
    const char *cmd
    )
{
  int result = -1;

  if (unlikely(!cmd))
  {
    errno = EINVAL;
    det_derr_ret("NULL parameter");
    goto errout;
  }

  umask(0); // clear file creation mask

  struct rlimit rl;

  // get max number of file descriptors
  if ((result = getrlimit(RLIMIT_NOFILE, &rl)) < 0)
  {
    det_derr_ret("%s: Failed to get file limit", cmd);
    goto errout;
  }

  pid_t pid;

  // become a session leader to lose controlling TTY
  if ((pid = fork()) < 0)
  {
    det_derr_ret("%s: Failed to fork", cmd);
    goto errout;
  }
  else if (pid != 0) // parent
  {
    det_derr_msg("Parent exiting");
    exit (0);
  }

  if ((pid = setsid()) < 0)
  {
    det_derr_ret("%s: Failed to create new session", cmd);
    goto errout;
  }

  // ensure future opens won't allocate controlling TTYs
  struct sigaction sa;
  sa.sa_handler = SIG_IGN;

  if ((result = sigemptyset(&sa.sa_mask)) < 0)
  {
    det_derr_ret("%s: Failed to clear signal set", cmd);
    goto errout;
  }

  sa.sa_flags = 0;

  if ((result = sigaction(SIGHUP, &sa, NULL)) < 0)
  {
    det_derr_ret("%s: cannot ignore SIGHUP", cmd);
    goto errout;
  }

  if ((pid = fork()) < 0)
  {
    det_derr_ret("%s: Failed to fork", cmd);
    goto errout;
  }
  else if (pid != 0) // parent
  {
    det_derr_msg("Parent exiting");
    exit (0);
  }

  /* change directory to the root so we don't prevent filesystems from
   * being unmounted
  */ 
  if ((result = chdir("/")) < 0)
  {
    det_derr_ret("%s: Failed to change directory to root", cmd);
    goto errout;
  }

  // close all open file descriptors
  if (rl.rlim_max == RLIM_INFINITY)
    rl.rlim_max = 1024;

  for (int fd = 0; fd < (int) rl.rlim_max; fd++)
    close(fd);

  // attach file descriptors 0, 1, and 2 to /dev/null
  int fd0 = open("/dev/null", O_RDWR);
  int fd1 = dup(0);
  int fd2 = dup(0);

  openlog(cmd, LOG_CONS, LOG_DAEMON);

  if (fd0 != 0 || fd1 != 1 || fd2 != 2)
  {
    syslog(LOG_ERR, "unexpected file descriptors %d %d %d",
        fd0, fd1, fd2);
    result = -1;
    goto errout;
  }

  result = 0;

errout:

  return (result);
} // det_daemonize
