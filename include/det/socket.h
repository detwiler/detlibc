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

#ifndef __DET_SOCKET_H__
#define __DET_SOCKET_H__ 1

#include <det/common.h>

__DET_BEGIN_C_DECLS__

ssize_t
det_send_message(
    int fd,
    struct iovec *iov,
    size_t iovlen
    ) DETLIB_EXPORT;

ssize_t
det_receive_message(
    int fd,
    struct iovec *iov,
    size_t iovlen
    ) DETLIB_EXPORT;

__DET_END_C_DECLS__

#endif /* !__DET_SOCKET_H__ */
