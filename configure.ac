# $Id$
#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_INIT([detlibc],[0.0.1],[mike.detwiler@gmail.com])
AC_PREREQ(2.63)
AC_REVISION([$Revision$])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([src/fatest.c])
AC_CONFIG_HEADER([config.h])

AM_INIT_AUTOMAKE([-Wall -Werror])
AM_SILENT_RULES

AC_GNU_SOURCE

# Checks for programs.
AC_PROG_CC
AX_CFLAGS_GCC_OPTION([-std=gnu99])
AX_CFLAGS_WARN_ALL
AX_CFLAGS_GCC_OPTION([-Wextra])
AX_CFLAGS_GCC_OPTION([-pedantic])
AX_CFLAGS_GCC_OPTION([-Wformat=2])
AX_CFLAGS_GCC_OPTION([-Winit-self])
AX_CFLAGS_GCC_OPTION([-Wmissing-include-dirs])
AX_CFLAGS_GCC_OPTION([-Wswitch-default])
AX_CFLAGS_GCC_OPTION([-Wswitch-enum])
AX_CFLAGS_GCC_OPTION([-Wfloat-equal])
AX_CFLAGS_GCC_OPTION([-Wtraditional-conversion])
AX_CFLAGS_GCC_OPTION([-Wundef])
AX_CFLAGS_GCC_OPTION([-Wshadow])
AX_CFLAGS_GCC_OPTION([-Wbad-function-cast])
AX_CFLAGS_GCC_OPTION([-Wcast-qual])
AX_CFLAGS_GCC_OPTION([-Wcast-align])
AX_CFLAGS_GCC_OPTION([-Wwrite-strings])
AX_CFLAGS_GCC_OPTION([-Wconversion])
AX_CFLAGS_GCC_OPTION([-Wlogical-op])
AX_CFLAGS_GCC_OPTION([-Waggregate-return])
AX_CFLAGS_GCC_OPTION([-Wstrict-prototypes])
AX_CFLAGS_GCC_OPTION([-Wold-style-definition])
AX_CFLAGS_GCC_OPTION([-Wmissing-prototypes])
AX_CFLAGS_GCC_OPTION([-Wmissing-declarations])
AX_CFLAGS_GCC_OPTION([-Wmissing-noreturn])
AX_CFLAGS_GCC_OPTION([-Wmissing-format-attribute])
AX_CFLAGS_GCC_OPTION([-Wpacked])
AX_CFLAGS_GCC_OPTION([-Wpadded])
AX_CFLAGS_GCC_OPTION([-Wredundant-decls])
AX_CFLAGS_GCC_OPTION([-Wnested-externs])
AX_CFLAGS_GCC_OPTION([-Winline])
AX_CFLAGS_GCC_OPTION([-Wvolatile-register-var])
AX_CFLAGS_GCC_OPTION([-Werror])

# Checks for libraries.
AC_CHECK_LIB([fa], [fa_compile])

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([assert.h sys/types.h sys/stat.h inttypes.h stddef.h stdint.h strings.h errno.h unistd.h])
AC_HEADER_STDBOOL

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 lib/Makefile
                 lib/det/Makefile
                 src/Makefile])
AC_OUTPUT
