#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.63])

AC_INIT([detlibc],
        [m4_esyscmd([build-aux/git-version-gen .tarball-version])],
        [mike.detwiler@gmail.com])

AC_CONFIG_SRCDIR([det/system.h])

AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADER([config.h])

AM_INIT_AUTOMAKE([-Wall -Werror color-tests dist-bzip2])
AM_SILENT_RULES([yes])

# it seems that if we're using system extensions and we're using libtool, then
# this macro needs to be called before libtool is initialized
AC_USE_SYSTEM_EXTENSIONS

LT_PREREQ([2.2])
LT_INIT

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

# additional configure options
AC_DEFUN([DET_ARG_ENABLE],
         [AC_ARG_ENABLE([m4_translit([$1], [_], [-])],
                        [AS_HELP_STRING([--enable-m4_translit([$1], [_], [-])],
                                        [enable $1 (default=$2)])],
                        [enable_[]$1=$enableval],
                        [enable_[]$1=$2])])

# conditionally enable debug
DET_ARG_ENABLE([debug], [no])
AM_CONDITIONAL([DET_DEBUG], [test "x$enable_debug" = xyes])

# conditionally make warnings be errors
DET_ARG_ENABLE([warn_error], [no])
AM_CONDITIONAL([DET_WARN_ERROR], [test "x$enable_warn_error" = xyes])

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
INIT_CFLAGS="$CFLAGS"
CFLAGS="$CFLAGS -Wformat -Werror"
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
CFLAGS="$INIT_CFLAGS"

gl_MANYWARN_ALL_GCC([warnings])

nw=
nw="$nw -Wsystem-headers"
nw="$nw -Wtraditional"
nw="$nw -Wundef"
nw="$nw -Wc++-compat"
nw="$nw -Wdeclaration-after-statement"
nw="$nw -Wunreachable-code"
nw="$nw -Wtraditional-conversion"
nw="$nw -Wvla"

gl_MANYWARN_COMPLEMENT([warnings], [$warnings], [$nw])
for w in $warnings; do
  gl_WARN_ADD([$w])
done

gl_WARN_ADD([-fdiagnostics-show-option])

# We use a slightly smaller set of warning options for gl/.
# Remove the following and save the result in GNULIB_WARN_CFLAGS.
nw=
nw="$nw -Wlogical-op"
nw="$nw -Wcast-qual"
nw="$nw -Wstrict-prototypes"
nw="$nw -Wold-style-definition"
nw="$nw -Wpadded"
nw="$nw -Wnested-externs"

gl_MANYWARN_COMPLEMENT([GNULIB_WARN_CFLAGS], [$WARN_CFLAGS], [$nw])
AC_SUBST([GNULIB_WARN_CFLAGS])

AM_COND_IF([DET_WARN_ERROR], [gl_WARN_ADD([-Werror], [WERROR_CFLAGS])])

AM_COND_IF([DET_DEBUG],
           [gl_WARN_ADD([-g], [DEBUG_CFLAGS])
            gl_WARN_ADD([-O0], [DEBUG_CFLAGS])])

gl_VISIBILITY

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
