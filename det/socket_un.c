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

#include "system.h"

#include <det/socket_un.h>

int
det_serv_listen_un(const char *name)
{
  if (strnlen(name, DET_MAX_SUN_PATHLEN) == DET_MAX_SUN_PATHLEN)
  {
    errno = EINVAL;
    det_derr_ret("name too long");
    return (-1);
  }

  int fd;

  if ((fd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0)
  {
    det_derr_ret("socket failure");
    return (-1);
  }

  (void) unlink(name);

  struct sockaddr_un sun;

  memclr(&sun, sizeof(sun));
  sun.sun_family = AF_UNIX;
  strncpy(sun.sun_path, name, DET_MAX_SUN_PATHLEN);

  size_t length = offsetof(struct sockaddr_un, sun_path) + strlen(sun.sun_path);

  if (bind(fd, (struct sockaddr*) &sun, length) < 0)
  {
    det_derr_ret("bind failure");
    goto errout;
  }

  if (listen(fd, DET_SERV_QLEN) < 0)
  {
    det_derr_ret("listen failure");
    goto errout;
  }

  return (fd);

  int error;

errout:

  error = errno;
  close(fd);
  errno = error;

  return (-1);
} // det_serv_listen_un()

int
det_serv_accept_un(int listenfd, uid_t *uidptr)
{
  int clifd;
  struct sockaddr_un sun;
  socklen_t length = sizeof(sun);

  if ((clifd = accept(listenfd, (struct sockaddr*) &sun, &length)) < 0)
  {
    det_derr_ret("accept failure");
    return (-1);
  }

  length -= offsetof(struct sockaddr_un, sun_path); // path length
  sun.sun_path[length] = '\0';

  struct stat sb;

  if (stat(sun.sun_path, &sb) < 0)
  {
    det_derr_ret("stat failure");
    goto errout;
  }

  if (!S_ISSOCK(sb.st_mode))
  {
    det_derr_msg("%s is not socket", sun.sun_path);
    goto errout;
  }

  if (uidptr)
    *uidptr = sb.st_uid;

  (void) unlink(sun.sun_path);

  return (clifd);

  int error;

errout:

  error = errno;
  close(clifd);
  errno = error;

  return (-1);
} // det_serv_accept_un()


int
det_cli_conn_un(const char *server, const char *client)
{
  if (strnlen(server, DET_MAX_SUN_PATHLEN) == DET_MAX_SUN_PATHLEN)
  {
    errno = EINVAL;
    det_derr_ret("name too long");
    return (-1);
  }

  if (strnlen(client, DET_MAX_SUN_PATHLEN) == DET_MAX_SUN_PATHLEN)
  {
    errno = EINVAL;
    det_derr_ret("name too long");
    return (-1);
  }

  int fd;

  if ((fd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0)
  {
    det_derr_ret("socket failure");
    return (-1);
  }

  struct sockaddr_un sun;

  memclr(&sun, sizeof(sun));
  sun.sun_family = AF_UNIX;
  strncpy(sun.sun_path, client, DET_MAX_SUN_PATHLEN);

  size_t length = offsetof(struct sockaddr_un, sun_path) + strlen(sun.sun_path);

  (void) unlink(sun.sun_path);

  if (bind(fd, (struct sockaddr*) &sun, length) < 0)
  {
    det_derr_ret("bind failure");
    goto errout;
  }

  memclr(&sun, sizeof(sun));
  sun.sun_family = AF_UNIX;
  strncpy(sun.sun_path, server, DET_MAX_SUN_PATHLEN);
  length = offsetof(struct sockaddr_un, sun_path) + strlen(sun.sun_path);

  if (connect(fd, (struct sockaddr*) &sun, length) < 0)
  {
    det_derr_ret("connect failure");
    goto errout;
  }

  return (fd);

  int error;

errout:

  error = errno;
  close(fd);
  errno = error;

  return (-1);
} // det_cli_conn_un()
