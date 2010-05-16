#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_INIT([detlibc],
        [m4_esyscmd([build-aux/git-version-gen .tarball-version])],
        [mike.detwiler@gmail.com])

AC_PREREQ(2.63)
AC_REVISION([$Revision$])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([det/system.h])
AC_CONFIG_HEADER([config.h])

# it seems that if we're using system extensions and we're using libtool, then
# this macro needs to be called before libtool is initialized
AM_INIT_AUTOMAKE([-Wall -Werror color-tests dist-bzip2])
AM_SILENT_RULES([yes])

AC_USE_SYSTEM_EXTENSIONS

LT_PREREQ([2.2])
LT_INIT

AC_PREFIX_DEFAULT([$HOME/usr])

# additional configure options

# conditionally enable debug
AC_ARG_ENABLE([debug],
              [AS_HELP_STRING([--enable-debug],
                              [enable debug (default no)])],
              [case "$enableval" in
                 yes) det_debug="yes" ;;
                 no) det_debug="no" ;;
                 *) AC_MSG_ERROR(
                      [bad value $enableval for --enable-debug]) ;;
              esac], [det_debug="no"])
AM_CONDITIONAL([DET_DEBUG], [test "x$det_debug" = xyes])

# conditionally enable warnings
AC_ARG_ENABLE([warnings],
              [AS_HELP_STRING([--enable-warnings],
                              [enable warnings (default yes)])],
              [case "$enableval" in
                 yes) det_warn="yes" ;;
                 no) det_warn="no" ;;
                 *) AC_MSG_ERROR(
                      [bad value $enableval for --enable-warnings]) ;;
              esac], [det_warn="yes"])
AM_CONDITIONAL([DET_WARN], [test "x$det_warn" = xyes])

# conditionally enable extra warnings
AC_ARG_ENABLE([extra-warnings],
              [AS_HELP_STRING([--enable-extra-warnings],
                              [enable extra warnings (default yes)])],
              [case "$enableval" in
                 yes) det_extra_warn="yes" ;;
                 no) det_extra_warn="no" ;;
                 *) AC_MSG_ERROR(
                      [bad value $enableval for --enable-extra-warnings]) ;;
              esac], [det_extra_warn="yes"])
AM_CONDITIONAL([DET_EXTRA_WARN], [test "x$det_extra_warn" = xyes])

# conditionally enable pedantic warnings
AC_ARG_ENABLE([pedantic],
              [AS_HELP_STRING([--enable-pedantic],
                              [enable pedantic warnings (default no)])],
              [case "$enableval" in
                 yes) det_pedantic="yes" ;;
                 no) det_pedantic="no" ;;
                 *) AC_MSG_ERROR(
                      [bad value $enableval for --enable-pedantic]) ;;
              esac], [det_pedantic="no"])
AM_CONDITIONAL([DET_PEDANTIC], [test "x$det_pedantic" = xyes])

# conditionally enable gobs of warnings
AC_ARG_ENABLE([gobs-of-warnings],
              [AS_HELP_STRING([--enable-gobs-of-warnings],
                              [enable gobs of warnings (default no)])],
              [case "$enableval" in
                 yes) det_gobs_warn="yes" ;;
                 no) det_gobs_warn="no" ;;
                 *) AC_MSG_ERROR(
                      [bad value $enableval for --enable-gobs-of-warnings]) ;;
              esac], [det_gobs_warn="no"])
AM_CONDITIONAL([DET_GOBS_WARN], [test "x$det_gobs_warn" = xyes])

# conditionally make warnings be errors
AC_ARG_ENABLE([warn-error],
              [AS_HELP_STRING(
               [--enable-warn-error],
               [enable treating warnings as errors (default yes)])],
              [case "$enableval" in
                 yes) det_warn_error="yes" ;;
                 no) det_warn_error="no" ;;
                 *) AC_MSG_ERROR(
                      [bad value $enableval for --enable-warn-error]) ;;
              esac], [det_warn_error="yes"])
AM_CONDITIONAL([DET_WARN_ERROR], [test "x$det_warn_error" = xyes])

# Checks for programs.
AC_PROG_CC
AC_PROG_CC_C99
AC_PROG_CC_C_O

# gnulib!
gl_EARLY

AC_PROG_AWK
AC_PROG_MAKE_SET
AC_PROG_INSTALL
AC_PROG_LN_S

# Checks for libraries.

# Checks for header files.

# gnulib!
gl_INIT

AC_HEADER_STDC
AC_HEADER_ASSERT
AC_HEADER_TIME
AC_CHECK_HEADERS([sys/socket.h sys/stat.h sys/time.h sys/types.h sys/un.h])
AC_CHECK_HEADERS([sys/wait.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
# typedefs, structures
AC_TYPE_INT8_T
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_INT64_T
AC_TYPE_INTMAX_T
AC_TYPE_INTPTR_T
AC_TYPE_SSIZE_T

AC_TYPE_UINT8_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_TYPE_UINTMAX_T
AC_TYPE_UINTPTR_T
AC_TYPE_SIZE_T

AC_TYPE_OFF_T
AC_TYPE_PID_T
AC_TYPE_UID_T

# compiler characteristics
AC_PROG_CPP
AC_C_INLINE
AC_C_RESTRICT
AC_C_VARARRAYS
AC_C_TYPEOF

AC_MSG_CHECKING([for function attribute format(gnu_printf)])
AC_COMPILE_IFELSE(
  [AC_LANG_PROGRAM(
   [void foo(const char *fmt, ...) __attribute__ ((format(gnu_printf, 1, 2)));],
   [foo("%s", "foo");])],
  [AC_MSG_RESULT([yes])
   AC_DEFINE([det_format_printf(x,y)],
             [__attribute__ ((format(gnu_printf, (x),(y))))],
             [printf format attribute])],
  [AC_MSG_RESULT([no])
   AC_MSG_CHECKING([for function attribute format(printf)])
   AC_COMPILE_IFELSE(
    [AC_LANG_PROGRAM(
     [void foo(const char *fmt, ...) __attribute__ ((format(printf, 1, 2)));],
     [foo("%s", "foo");])],
    [AC_MSG_RESULT([yes])
     AC_DEFINE([det_format_printf(x,y)],
               [__attribute ((format(printf, (x),(y))))],
               [printf format attribute])],
    [AC_MSG_RESULT([no])
     AC_DEFINE([det_format_printf(x,y)], [], [printf format attribute])])])

AM_COND_IF([DET_WARN],
           [AX_CFLAGS_GCC_OPTION([-Wall], [DET_CFLAGS])
            AX_CFLAGS_GCC_OPTION([-Wswitch-default], [DET_CFLAGS])
            AX_CFLAGS_GCC_OPTION([-Wswitch-enum], [DET_CFLAGS])
            AX_CFLAGS_GCC_OPTION([-Wmissing-prototypes], [DET_CFLAGS])
            AX_CFLAGS_GCC_OPTION([-Wmissing-declarations], [DET_CFLAGS])
            AX_CFLAGS_GCC_OPTION([-Wredundant-decls], [DET_CFLAGS])

            AX_CFLAGS_GCC_OPTION([-fdiagnostics-show-option], [DET_CFLAGS])])

AM_COND_IF([DET_EXTRA_WARN], [AX_CFLAGS_GCC_OPTION([-Wextra], [DET_CFLAGS])])

AM_COND_IF([DET_PEDANTIC], [AX_CFLAGS_GCC_OPTION([-pedantic], [DET_CFLAGS])])

AM_COND_IF([DET_GOBS_WARN],
           [AX_CFLAGS_GCC_OPTION([-Wformat=2], [DET_CFLAGS])
            AX_CFLAGS_GCC_OPTION([-Winit-self], [DET_CFLAGS])
            AX_CFLAGS_GCC_OPTION([-Wmissing-include-dirs], [DET_CFLAGS])
            AX_CFLAGS_GCC_OPTION([-Wfloat-equal], [DET_CFLAGS])
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
            AX_CFLAGS_GCC_OPTION([-Wvolatile-register-var], [DET_CFLAGS])])

AM_COND_IF([DET_WARN_ERROR], [AX_CFLAGS_GCC_OPTION([-Werror], [DET_CFLAGS])])

AM_COND_IF([DET_DEBUG],
           [AX_CFLAGS_GCC_OPTION([-g])
            AX_CFLAGS_GCC_OPTION([-O0])])

# Checks for library functions.
AC_FUNC_FORK
AC_CHECK_FUNCS([select socket strerror])

# config.h defines
AC_DEFINE([BUILDING_LIBDET], [1], [Are we building libdet?])
AM_COND_IF([DET_DEBUG], [AC_DEFINE([DET_DEBUG], [1], [enable debug])])

AC_DEFINE([memclr(s,n)],
          [memset((s), 0, (n))],
          [clear memory])

AC_DEFINE([strclr(s)],
          [memclr((s), strlen((s)))],
          [clear string])

AC_DEFINE([num_elts(a)],
          [(sizeof(a) / sizeof(a[[0]]))],
          [number of elements for static array a])

AC_DEFINE([bstring(b)],
          [((b) ? "true" : "false")],
          [convert boolean to string])

AC_DEFINE([likely(x)],
          [__builtin_expect(!!(x), 1)],
          [likely branch prediction])

AC_DEFINE([unlikely(x)],
          [__builtin_expect(!!(x), 0)],
          [unlikely branch prediction])

# substitutions
AC_SUBST([DET_CFLAGS])

# testing
AC_CONFIG_TESTDIR([tests])

AC_CONFIG_FILES([Makefile
                 include/Makefile
                 include/det/Makefile
                 gl/Makefile
                 gl/gnu/Makefile
                 gl/tests/Makefile
                 det/Makefile
                 tests/Makefile
                 tests/atlocal])
AC_OUTPUT
