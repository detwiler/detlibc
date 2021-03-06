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

#ifndef __DET_COMMON_H__
#define __DET_COMMON_H__ 1

#ifdef __cplusplus
# define __DET_BEGIN_C_DECLS__ extern "C" {
# define __DET_END_C_DECLS__ }
#else
# define __DET_BEGIN_C_DECLS__
# define __DET_END_C_DECLS__
#endif /* __cplusplus */

#if BUILDING_LIBDET && HAVE_VISIBILITY
# define DETLIB_EXPORT __attribute__ ((__visibility__("default")))
#else
# define DETLIB_EXPORT
#endif /* BUILDING_LIBDET && HAVE_VISIBILITY */

#endif /* !__DET_COMMON_H__ */
