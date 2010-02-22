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

#include <det/signal.h>

static volatile sig_atomic_t sigflag; // set nonzero by sig handler

static sigset_t newmask, oldmask, zeromask;

static void
sig_usr(int signo __attribute__((unused)))
{
  sigflag = 1;
} // sig_usr

void
det_signal_wait(void)
{
  if (signal(SIGUSR1, sig_usr) == SIG_ERR)
    det_err_sys("signal(SIGUSR1) error");

  if (signal(SIGUSR2, sig_usr) == SIG_ERR)
    det_err_sys("signal(SIGUSR2) error");

  sigemptyset(&zeromask);
  sigemptyset(&newmask);

  sigaddset(&newmask, SIGUSR1);
  sigaddset(&newmask, SIGUSR2);

  // Block SIGUSR1 and SIGUSR2, and save current signal mask.
  if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
    det_err_sys("SIG_BLOCK error");
} // det_signal_wait()

void
det_signal_parent(pid_t pid)
{
  kill(pid, SIGUSR2); // tell the parent we're done
} // det_signal_parent()

void
det_wait_parent(void)
{
  while (sigflag == 0)
    sigsuspend(&zeromask); // and wait for parent

  sigflag = 0;

  // reset signal mask to original value
  if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
    det_err_sys("SIG_SETMASK error");
} // det_wait_parent()

void
det_signal_child(pid_t pid)
{
  kill(pid, SIGUSR1); // tell the child we're done
} // det_signal_child()

void
det_wait_child(void)
{
  while (sigflag == 0)
    sigsuspend(&zeromask); // and wait for child

  sigflag = 0;

  // reset signal mask to original value
  if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
    det_err_sys("SIG_SETMASK error");
} // det_wait_child()
