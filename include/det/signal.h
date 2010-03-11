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

#ifndef __DET_SIGNAL_H__
#define __DET_SIGNAL_H__ 1

#include <det/common.h>

__DET_BEGIN_C_DECLS__

void
det_signal_wait(void) DETLIB_EXPORT;

void
det_signal_parent(
    pid_t pid
    ) DETLIB_EXPORT;

void
det_wait_parent(void) DETLIB_EXPORT;

void
det_signal_child(
    pid_t pid
    ) DETLIB_EXPORT;

void
det_wait_child(void) DETLIB_EXPORT;

__DET_END_C_DECLS__

#endif /* !__DET_SIGNAL_H__ */
