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

#ifndef __DET_DEBUG_H__
#define __DET_DEBUG_H__ 1


#include <det/error.h>

__DET_BEGIN_C_DECLS__

#ifdef DET_DEBUG

#define det_derr_dump(fmt, ...) \
  do \
  { \
    det_err_dump("[%s:%d] %s: " fmt, __FILE__, __LINE__, \
        __FUNCTION__, ##__VA_ARGS__); \
  } while (0)

#define det_derr_exit(error, fmt, ...) \
  do \
  { \
    det_err_exit((error), "[%s:%d] %s: " fmt, __FILE__, __LINE__, \
        __FUNCTION__, ##__VA_ARGS__); \
  } while (0)

#define det_derr_msg(fmt, ...) \
  do \
  { \
    det_err_msg("[%s:%d] %s: " fmt, __FILE__, __LINE__, \
        __FUNCTION__, ##__VA_ARGS__); \
  } while (0)

#define det_derr_ret(fmt, ...) \
  do \
  { \
    det_err_ret("[%s:%d] %s: " fmt, __FILE__, __LINE__, \
        __FUNCTION__, ##__VA_ARGS__); \
  } while (0)

#define det_derr_sys(fmt, ...) \
  do \
  { \
    det_err_sys("[%s:%d] %s: " fmt, __FILE__, __LINE__, \
        __FUNCTION__, ##__VA_ARGS__); \
  } while (0)

#define det_derr_quit(fmt, ...) \
  do \
  { \
    det_err_quit("[%s:%d] %s: " fmt, __FILE__, __LINE__, \
        __FUNCTION__, ##__VA_ARGS__); \
  } while (0)

#else /* DET_DEBUG */

#define det_derr_dump(fmt, ...)
#define det_derr_exit(error, fmt, ...)
#define det_derr_msg(fmt, ...)
#define det_derr_ret(fmt, ...)
#define det_derr_sys(fmt, ...)
#define det_derr_quit(fmt, ...)

#endif /* DET_DEBUG */

__DET_END_C_DECLS__

#endif /* !__DET_DEBUG_H__ */
