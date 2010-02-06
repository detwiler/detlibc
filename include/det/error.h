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

#ifndef __DET_ERROR_H__
#define __DET_ERROR_H__ 1

#include <det/common.h>

__DET_BEGIN_C_DECLS__

#if defined (__DET_DEBUG__)

#else /* __DET_DEBUG__ */

#endif /* __DET_DEBUG__ */

/*
 * Fatal error related to system call.
 * Print a message, dump core, and terminate.
 */
void
det_err_dump(
    const char *format,
    ...
    );

/*
 * Nonfatal error unrelated to system call.
 * Print a message and return.
 */
void
det_err_msg(
    const char *format,
    ...
    );

/*
 * Fatal error unrelated to system call.
 * Print a message and terminate.
 */
void
det_err_quit(
    const char *format,
    ...
    );

/*
 * Fatal error unrelated to system call.
 * Error code passed as explicit parameter.
 * Print a message and terminate.
 */
void
det_err_exit(
    int error,
    const char *format,
    ...
    );

/*
 * Nonfatal error related to system call.
 * Print a message and return.
 */
void
det_err_ret(
    const char *format,
    ...
    );

/*
 * Fatal error related to system call.
 * Print a message and terminate.
 */
void
det_err_sys(
    const char *format,
    ...
    );

__DET_END_C_DECLS__

#endif /* !__DET_ERROR_H__ */
