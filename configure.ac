# $Id$
#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_INIT([detlibc],[0.0.1],[mike.detwiler@gmail.com])
AC_PREREQ(2.61)
AC_REVISION([$Revision: 164 $])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([src/fatest.c])
AC_CONFIG_HEADER([config.h])

AM_INIT_AUTOMAKE([-Wall -Werror])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([assert.h sys/types.h sys/stat.h inttypes.h stdint.h strings.h errno.h unistd.h])
AC_HEADER_STDBOOL

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 lib/Makefile
                 lib/det/Makefile
                 src/Makefile])
AC_OUTPUT
