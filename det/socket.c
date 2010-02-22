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

#include <det/socket.h>

ssize_t
det_send_message(int fd, struct iovec *iov, size_t iovlen)
{
  if (!iov)
  {
    errno = EINVAL;
    det_derr_ret("null parameter");
    return (-1);
  }

  struct msghdr msg;

  msg.msg_name = NULL;
  msg.msg_namelen = 0;
  msg.msg_iov = iov;
  msg.msg_iovlen = iovlen;
  msg.msg_control = NULL;
  msg.msg_controllen = 0;

  return (sendmsg(fd, &msg, 0));
} // det_send_message()

ssize_t
det_receive_message(int fd, struct iovec *iov, size_t iovlen)
{
  if (!iov)
  {
    errno = EINVAL;
    det_derr_ret("null parameter");
    return (-1);
  }

  struct msghdr msg;

  msg.msg_name = NULL;
  msg.msg_namelen = 0;
  msg.msg_iov = iov;
  msg.msg_iovlen = iovlen;
  msg.msg_control = NULL;
  msg.msg_controllen = 0;

  return (recvmsg(fd, &msg, 0));
} // det_receive_message()
