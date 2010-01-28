#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_INIT([detlibc],[0.0.1],[mike.detwiler@gmail.com])
AC_PREREQ(2.63)
AC_REVISION([$Revision$])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([src/fatest.c])
AC_CONFIG_HEADER([config.h])

AM_INIT_AUTOMAKE([-Wall -Werror silent-rules dist-bzip2])

AC_USE_SYSTEM_EXTENSIONS

LT_PREREQ([2.2])
LT_INIT

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL

# Checks for libraries.
AC_CHECK_LIB([fa], [fa_compile])

# Checks for header files.
AC_HEADER_STDC
AC_HEADER_ASSERT
AC_CHECK_HEADERS([sys/types.h sys/stat.h sys/time.h inttypes.h stdint.h strings.h unistd.h])
AC_HEADER_TIME

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Checks for library functions.

# compiler options 
AX_CFLAGS_GCC_OPTION([-std=gnu99], [DET_CFLAGS])

# option to conditionally enable warnings
AC_ARG_ENABLE([warnings],
              [AS_HELP_STRING([--enable-warnings],
                              [enable warnings (default yes)])],
              [case "${enableval}" in
                 yes) det_warn="yes" ;;
                 no) det_warn="no" ;;
                 *) AC_MSG_ERROR(
                      [bad value ${enableval} for --enable-warnings]) ;;
              esac], [det_warn="yes"])
AM_CONDITIONAL([DET_WARN], [test "x${det_warn}" = xyes])
AM_COND_IF([DET_WARN],
           [
            AX_CFLAGS_GCC_OPTION([-Wall], [DET_CFLAGS])
            AX_CFLAGS_GCC_OPTION([-Wswitch-default], [DET_CFLAGS])
            AX_CFLAGS_GCC_OPTION([-Wswitch-enum], [DET_CFLAGS])
            AX_CFLAGS_GCC_OPTION([-Wmissing-prototypes], [DET_CFLAGS])
            AX_CFLAGS_GCC_OPTION([-Wmissing-declarations], [DET_CFLAGS])
            AX_CFLAGS_GCC_OPTION([-Wredundant-decls], [DET_CFLAGS])

            AX_CFLAGS_GCC_OPTION([-fdiagnostics-show-option], [DET_CFLAGS])
           ])

# option to conditionally enable extra warnings
AC_ARG_ENABLE([extra-warnings],
              [AS_HELP_STRING([--enable-extra-warnings],
                              [enable extra warnings (default yes)])],
              [case "${enableval}" in
                 yes) det_extra_warn="yes" ;;
                 no) det_extra_warn="no" ;;
                 *) AC_MSG_ERROR(
                      [bad value ${enableval} for --enable-extra-warnings]) ;;
              esac], [det_extra_warn="yes"])
AM_CONDITIONAL([DET_EXTRA_WARN], [test "x${det_extra_warn}" = xyes])
AM_COND_IF([DET_EXTRA_WARN],
           [AX_CFLAGS_GCC_OPTION([-Wextra], [DET_CFLAGS])])

# option to conditionally enable pedantic warnings
AC_ARG_ENABLE([pedantic],
              [AS_HELP_STRING([--enable-pedantic],
                              [enable pedantic warnings (default yes)])],
              [case "${enableval}" in
                 yes) det_pedantic="yes" ;;
                 no) det_pedantic="no" ;;
                 *) AC_MSG_ERROR(
                      [bad value ${enableval} for --enable-pedantic]) ;;
              esac], [det_pedantic="yes"])
AM_CONDITIONAL([DET_PEDANTIC], [test "x${det_pedantic}" = xyes])
AM_COND_IF([DET_PEDANTIC],
           [AX_CFLAGS_GCC_OPTION([-pedantic], [DET_CFLAGS])])

# option to conditionally enable gobs of warnings
AC_ARG_ENABLE([gobs-of-warnings],
              [AS_HELP_STRING([--enable-gobs-of-warnings],
                              [enable gobs of warnings (default no)])],
              [case "${enableval}" in
                 yes) det_gobs_warn="yes" ;;
                 no) det_gobs_warn="no" ;;
                 *) AC_MSG_ERROR(
                      [bad value ${enableval} for --enable-gobs-of-warnings]) ;;
              esac], [det_gobs_warn="no"])
AM_CONDITIONAL([DET_GOBS_WARN], [test "x${det_gobs_warn}" = xyes])
AM_COND_IF([DET_GOBS_WARN],
           [
            AX_CFLAGS_GCC_OPTION([-Wformat=2], [DET_CFLAGS])
            AX_CFLAGS_GCC_OPTION([-Winit-self], [DET_CFLAGS])
            AX_CFLAGS_GCC_OPTION([-Wmissing-include-dirs], [DET_CFLAGS])
            AX_CFLAGS_GCC_OPTION([-Wfloat-equal], [DET_CFLAGS])
            AX_CFLAGS_GCC_OPTION([-Wtraditional-conversion], [DET_CFLAGS])
            AX_CFLAGS_GCC_OPTION([-Wundef], [DET_CFLAGS])
            AX_CFLAGS_GCC_OPTION([-Wshadow], [DET_CFLAGS])
            AX_CFLAGS_GCC_OPTION([-Wbad-function-cast], [DET_CFLAGS])
            AX_CFLAGS_GCC_OPTION([-Wcast-qual], [DET_CFLAGS])
            AX_CFLAGS_GCC_OPTION([-Wcast-align], [DET_CFLAGS])
            AX_CFLAGS_GCC_OPTION([-Wwrite-strings], [DET_CFLAGS])
            AX_CFLAGS_GCC_OPTION([-Wconversion], [DET_CFLAGS])
            AX_CFLAGS_GCC_OPTION([-Wlogical-op], [DET_CFLAGS])
            AX_CFLAGS_GCC_OPTION([-Waggregate-return], [DET_CFLAGS])
            AX_CFLAGS_GCC_OPTION([-Wmissing-noreturn], [DET_CFLAGS])
            AX_CFLAGS_GCC_OPTION([-Wmissing-format-attribute], [DET_CFLAGS])
            AX_CFLAGS_GCC_OPTION([-Wpacked], [DET_CFLAGS])
            AX_CFLAGS_GCC_OPTION([-Wpadded], [DET_CFLAGS])
            AX_CFLAGS_GCC_OPTION([-Wnested-externs], [DET_CFLAGS])
            AX_CFLAGS_GCC_OPTION([-Winline], [DET_CFLAGS])
            AX_CFLAGS_GCC_OPTION([-Wvolatile-register-var], [DET_CFLAGS])
           ])

# option to conditionally make warnings be errors
AC_ARG_ENABLE([warn-error],
              [AS_HELP_STRING(
               [--enable-warn-error],
               [enable treating warnings as errors (default yes)])],
              [case "${enableval}" in
                 yes) det_warn_error="yes" ;;
                 no) det_warn_error="no" ;;
                 *) AC_MSG_ERROR(
                      [bad value ${enableval} for --enable-warn-error]) ;;
              esac], [det_warn_error="yes"])
AM_CONDITIONAL([DET_WARN_ERROR], [test "x${det_warn_error}" = xyes])
AM_COND_IF([DET_WARN_ERROR],
           [AX_CFLAGS_GCC_OPTION([-Werror], [DET_CFLAGS])])

AC_SUBST([DET_CFLAGS])

AC_CONFIG_FILES([Makefile
                 include/Makefile
                 include/det/Makefile
                 lib/Makefile
                 lib/common/Makefile
                 lib/det/Makefile
                 src/Makefile])
AC_OUTPUT
