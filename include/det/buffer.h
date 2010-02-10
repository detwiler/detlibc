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

#ifndef __DET_BUFFER_H__
#define __DET_BUFFER_H__ 1

#include <det/common.h>

__DET_BEGIN_C_DECLS__

struct det_buffer;

struct det_buffer*
det_buffer_malloc(
    size_t size
    );

struct det_buffer*
det_buffer_zalloc(
    size_t size
    );

struct det_buffer*
det_buffer_calloc(
    size_t size,
    size_t nmemb
    );

void
det_buffer_free(
    struct det_buffer *buffer
    );

ssize_t
det_buffer_get_size(
    const struct det_buffer *buffer
    );

ssize_t
det_buffer_get_capacity(
    const struct det_buffer *buffer
    );

ssize_t
det_buffer_get_remaining(
    const struct det_buffer *buffer
    );

const void*
det_buffer_get_data(
    const struct det_buffer *buffer
    );

ssize_t
det_buffer_clear(
    struct det_buffer *buffer
    );

ssize_t
det_buffer_fread(
    struct det_buffer *buffer,
    size_t size,
    size_t nmemb,
    FILE *stream
    );

ssize_t
det_buffer_read(
    struct det_buffer *buffer,
    int fd,
    size_t size
    );

ssize_t
det_buffer_fread_all(
    struct det_buffer *buffer,
    FILE *stream
    );

__DET_END_C_DECLS__

#endif /* !__DET_BUFFER_H__ */
