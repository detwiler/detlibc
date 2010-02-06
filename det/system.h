/* This file is based on the file common.h obtained at
 * http://sources.redhat.com/autobook/small-2.0.tar.gz
 *
 * That file was distributed with the following license:
 *
 * Copyright (C) 2000, 2006 Gary V. Vaughan
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 51
 * Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef DET_SYSTEM_H
#define DET_SYSTEM_H 1

#if HAVE_CONFIG_H
# include <config.h>
#endif /* HAVE_CONFIG_H */

#ifdef STDC_HEADERS
# include <assert.h>
# include <ctype.h>
# include <errno.h>
# include <float.h>
# include <inttypes.h>
# include <limits.h>
# include <locale.h>
# include <math.h>
# include <setjmp.h>
# include <signal.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
#endif /* STDC_HEADERS */

#ifdef HAVE_STDBOOL_H
# include <stdbool.h>
#else /* HAVE_STDBOOL_H */
# ifndef HAVE__BOOL
#  ifdef __cplusplus
typedef bool _Bool;
#  else /* __cplusplus */
#   define _Bool signed char
#  endif /* __cplusplus */
# endif /* !HAVE__BOOL */
# define bool _Bool
# define false 0
# define true 1
# define __bool_true_false_are_defined 1
#endif /* HAVE_STDBOOL_H */

#ifdef HAVE_SYS_TYPES_H
# include <sys/types.h>
#endif /* HAVE_SYS_TYPES_H */

#if HAVE_UNISTD_H
# include <unistd.h>
#endif /* HAVE_UNISTD_H */

#ifdef HAVE_SYS_STAT_H
# include <sys/stat.h>
#endif /* HAVE_SYS_STAT_H */

#ifdef TIME_WITH_SYS_TIME
# include <sys/time.h>
# include <time.h>
#else
# ifdef HAVE_SYS_TIME
#  include <sys/time.h>
# else
#  include <time.h>
# endif /* HAVE_SYS_TIME */
#endif /* TIME_WITH_SYS_TIME */

#ifdef __cplusplus
# define BEGIN_C_DECLS extern "C" {
# define END_C_DECLS }
#else
# define BEGIN_C_DECLS
# define END_C_DECLS
#endif /* __cplusplus */

#endif /* !DET_SYSTEM_H */
