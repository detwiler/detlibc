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

#include <det/buffer.h>

struct det_buffer
{
  size_t capacity;
  uint8_t *data;
  uint8_t *mark;
  bool zero;

  uint8_t reserved[3];

};

static size_t
det_buffer_make_room(
    struct det_buffer *buffer,
    size_t size
    );

static void
det_buffer_realloc(
    struct det_buffer *buffer,
    size_t size
    );

static ssize_t
det_buffer_fread_eof(
    struct det_buffer *buffer,
    FILE *stream
    );

struct det_buffer*
det_buffer_malloc(size_t size)
{
  struct det_buffer *result = xcalloc(1, sizeof(struct det_buffer));

  result->data = xmalloc(size);

  result->capacity = size;

  result->mark = result->data;

  result->zero = false;

  return (result);
} // det_buffer_alloc()

struct det_buffer*
det_buffer_zalloc(size_t size)
{
  struct det_buffer *result = xcalloc(1, sizeof(struct det_buffer));

  result->data = xzalloc(size);

  result->capacity = size;

  result->mark = result->data;

  result->zero = true;

  return (result);
} // det_buffer_zalloc()

struct det_buffer*
det_buffer_calloc(size_t size, size_t nmemb)
{
  return (det_buffer_zalloc(size * nmemb));
} // det_buffer_calloc()

ssize_t
det_buffer_get_size(const struct det_buffer *buffer)
{
  if (!buffer)
  {
    errno = EINVAL;
    det_derr_ret("NULL pointer");
    return (-1);
  }

  return (buffer->mark - buffer->data);
} // det_buffer_get_size()

ssize_t
det_buffer_get_capacity(const struct det_buffer *buffer)
{
  if (!buffer)
  {
    errno = EINVAL;
    det_derr_ret("NULL pointer");
    return (-1);
  }

  return ((ssize_t) buffer->capacity);
} // det_buffer_get_capacity()

ssize_t
det_buffer_get_remaining(const struct det_buffer *buffer)
{
  if (!buffer)
  {
    errno = EINVAL;
    det_derr_ret("NULL pointer");
    return (-1);
  }

  return ((ssize_t) buffer->capacity - det_buffer_get_size(buffer));
} // det_buffer_get_remaining()

const void*
det_buffer_get_data(const struct det_buffer *buffer)
{
  if (!buffer)
  {
    errno = EINVAL;
    det_derr_ret("NULL pointer");
    return (NULL);
  }

  return (buffer->data);
} // det_buffer_get_data()

ssize_t
det_buffer_clear(struct det_buffer *buffer)
{
  if (!buffer)
  {
    errno = EINVAL;
    det_derr_ret("NULL pointer");
    return (-1);
  }

  memclr(buffer->data, buffer->capacity);

  buffer->mark = buffer->data;

  buffer->zero = true;

  return((ssize_t) buffer->capacity);
} // det_buffer_clear()

ssize_t
det_buffer_fread(struct det_buffer *buffer, size_t size, size_t nmemb,
    FILE *stream)
{
  if (!buffer)
  {
    errno = EINVAL;
    det_derr_ret("NULL pointer");
    return (-1);
  }

  (void) det_buffer_make_room(buffer, (size * nmemb));

  ssize_t result = (ssize_t) fread(buffer->mark, size, nmemb, stream);

  buffer->mark += result;

  return (result);
} // det_buffer_fread()

ssize_t
det_buffer_read(struct det_buffer *buffer, int fd, size_t size)
{
  if (!buffer)
  {
    errno = EINVAL;
    det_derr_ret("NULL pointer");
    return (-1);
  }

  (void) det_buffer_make_room(buffer, size);

  ssize_t result = read(fd, buffer->mark, size);

  if (result > 0)
    buffer->mark += result;

  return (result);
} // det_buffer_read()

ssize_t
det_buffer_fread_all(struct det_buffer *buffer, FILE *stream)
{
  if (!buffer)
  {
    errno = EINVAL;
    det_derr_ret("NULL pointer");
    return (-1);
  }

  struct stat sbuf;

  if (fstat(fileno(stream), &sbuf) < 0)
  {
    det_derr_ret("Could not get file status");
    return (-1);
  }

  if (!S_ISREG(sbuf.st_mode))
    return (det_buffer_fread_eof(buffer, stream));

  // TODO finish

  return (0);
} // det_buffer_fread_all()

static void
det_buffer_realloc(struct det_buffer *buffer, size_t size)
{
  buffer->data = xrealloc(buffer->data, size);

  buffer->capacity = size;
} // det_buffer_realloc()

static size_t
det_buffer_make_room(struct det_buffer *buffer, size_t size)
{
  if (size  < (size_t) det_buffer_get_remaining(buffer))
  {
    size_t total = (size_t) det_buffer_get_size(buffer) + size;
    size_t increase = total - buffer->capacity;

    det_buffer_realloc(buffer, total);

    det_derr_msg("Insufficient remaining capacity: %d, for read of %u bytes." \
       "Reallocating to total capacity of %u bytes.", 
       det_buffer_get_remaining(buffer), size, total);

    return (increase);
  } 

  return (0);
} // det_buffer_make_room()

static ssize_t
det_buffer_fread_eof(struct det_buffer *buffer, FILE *stream)
{
  buffer = buffer;
  stream = stream;

  // TODO finish

  return (0);
} // det_buffer_fread_eof()
