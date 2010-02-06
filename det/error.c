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

#include <det/error.h>

static void
err_doit(
    bool errnoflag,
    int error,
    const char *fmt,
    va_list ap
    ) __attribute__ ((format(gnu_printf, 3, 0)));

void
det_err_dump(const char *fmt, ...)
{
  va_list ap;

  int error = errno;

  va_start(ap, fmt);

  errno = error;

  err_doit(true, errno, fmt, ap);

  va_end(ap);

  abort(); // dump core and terminate
  exit(EXIT_FAILURE);  // shouldn't get here
} // det_err_dump()

void
det_err_msg(const char *fmt, ...)
{
  va_list ap;

  va_start(ap, fmt);

  err_doit(false, 0, fmt, ap);

  va_end(ap);
} // det_err_msg()

void
det_err_quit(const char *fmt, ...)
{
  va_list ap;

  va_start(ap, fmt);

  err_doit(false, 0, fmt, ap);

  va_end(ap);

  exit(EXIT_FAILURE);
} // det_err_quit()

void
det_err_exit(int error, const char *fmt, ...)
{
  va_list ap;

  va_start(ap, fmt);

  err_doit(true, error, fmt, ap);

  va_end(ap);

  exit(EXIT_FAILURE);
} // det_err_exit()

void
det_err_ret(const char *fmt, ...)
{
  va_list ap;

  int error = errno;

  va_start(ap, fmt);

  errno = error;

  err_doit(true, errno, fmt, ap);

  va_end(ap);
} // det_err_ret()

void
det_err_sys(const char *fmt, ...)
{
  va_list ap;

  int error = errno;

  va_start(ap, fmt);

  errno = error;

  err_doit(true, errno, fmt, ap);

  va_end(ap);

  exit(EXIT_FAILURE);
} // det_err_sys()

static void
err_doit(bool errnoflag, int error, const char *fmt, va_list ap)
{
  fflush(stdout); // in case stdout and stderr are same

  vfprintf(stderr, fmt, ap);

  if (errnoflag)
    fprintf(stderr, ": %s", strerror(error));

  fprintf(stderr, "\n");

  fflush(NULL);
} // err_doit
