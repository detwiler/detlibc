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

#ifdef HAVE_SYS_RESOURCE_H
# include <sys/resource.h>
#endif /* HAVE_SYS_RESOURCE_H */

#ifdef HAVE_SYS_TYPES_H
# include <sys/types.h>
#endif /* HAVE_SYS_TYPES_H */

#if HAVE_UNISTD_H
# include <unistd.h>
#endif /* HAVE_UNISTD_H */

#ifdef HAVE_SYS_STAT_H
# include <sys/stat.h>
#endif /* HAVE_SYS_STAT_H */

#if HAVE_FCNTL_H
# include <fcntl.h>
#endif /* HAVE_FCNTL_H */

#ifdef HAVE_SYS_SOCKET_H
# include <sys/socket.h>
#endif /* HAVE_SYS_SOCKET_H */

#ifdef HAVE_SYS_UN_H
# include <sys/un.h>
#endif /* HAVE_SYS_UN_H */

#ifdef HAVE_SYS_WAIT_H
# include <sys/wait.h>
#endif /* HAVE_SYS_WAIT_H */

#if HAVE_SYSLOG_H
# include <syslog.h>
#endif /* HAVE_SYSLOG_H */

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

#if HAVE_GMP_H
# include <gmp.h>
#endif /* HAVE_GMP_H */

/* gnulib ensures presence */
#include <minmax.h>
#include <stdbool.h>
#include <xalloc.h>

/* error functions and debug macros */
#include <det/error.h>
#include <det/debug.h>

#ifdef __cplusplus
# define BEGIN_C_DECLS extern "C" {
# define END_C_DECLS }
#else
# define BEGIN_C_DECLS
# define END_C_DECLS
#endif /* __cplusplus */

#endif /* !DET_SYSTEM_H */
