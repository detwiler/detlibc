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

AM_INIT_AUTOMAKE([-Wall -Werror color-tests dist-xz])
AM_SILENT_RULES([yes])

AC_USE_SYSTEM_EXTENSIONS

# Checks for programs.
AC_PROG_CC
AC_PROG_CC_C99
AC_PROG_CC_C_O

# gnulib!
gl_EARLY

# AM_PROG_AR is not available in automake 1.11.1 (CentOS 6.x), but its use is
# required in automake 1.12 onward, so we used it only if it exists.
# Ref: https://lists.gnu.org/archive/html/automake/2012-05/msg00014.html
m4_ifdef([AM_PROG_AR], [AM_PROG_AR])

# Workaround for new GNU binutils ar(1) warning which libtool has yet to deal with
# Ref: https://bugzilla.redhat.com/show_bug.cgi?id=1216905
# Ref: https://bugzilla.redhat.com/show_bug.cgi?id=1155273#c13
AS_IF([test "x$AR_FLAGS" = x],
      [AC_SUBST([AR_FLAGS], [cr])])

LT_PREREQ([2.2])
LT_INIT

AC_PROG_AWK
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
PKG_PROG_PKG_CONFIG

# additional configure options

# conditionally enable debug
DET_ARG_ENABLE([debug], [no])
AM_CONDITIONAL([DET_DEBUG], [test "x$enable_debug" = xyes])

# conditionally make warnings be errors
DET_ARG_ENABLE([warn_error], [no])
AM_CONDITIONAL([DET_WARN_ERROR], [test "x$enable_warn_error" = xyes])

# Checks for libraries.

AC_CHECK_LIB([gmp], [__gmpz_init],
             [AC_SUBST([GMP_LIBS], [-lgmp])],
             [AC_MSG_ERROR([Could not find gmp library])])

# TODO make pkg-config data
# TODO rewrite tests to remove dependency on check
PKG_CHECK_MODULES([CHECK], [check >= 0.9.8])

# Checks for header files.

# gnulib!
gl_INIT

AC_HEADER_STDC
AC_HEADER_ASSERT
AC_HEADER_TIME
AC_CHECK_HEADERS([fcntl.h gmp.h sys/resource.h sys/socket.h sys/stat.h])
AC_CHECK_HEADERS([sys/time.h sys/types.h sys/un.h sys/wait.h syslog.h unistd.h])

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

# Remove these warnings.
nw=
nw="$nw -Wsystem-headers"
nw="$nw -Wvla"

gl_MANYWARN_COMPLEMENT([warnings], [$warnings], [$nw])
for w in $warnings; do
  gl_WARN_ADD([$w])
done

gl_WARN_ADD([-fdiagnostics-show-option])

# We use a slightly smaller set of warning options for gl/.
# Remove the following and save the result in GNULIB_WARN_CFLAGS.
nw=
nw="$nw -Wold-style-definition"
nw="$nw -Wstrict-prototypes"
nw="$nw -Wsuggest-attribute=pure"
nw="$nw -Wsuggest-attribute=const"

gl_MANYWARN_COMPLEMENT([GNULIB_WARN_CFLAGS], [$WARN_CFLAGS], [$nw])

# These warnings are enabled by other warnings (e.g.: -Wextra),
# so we have to specifically disable them.
gl_WARN_ADD([-Wno-unused-parameter], [GNULIB_WARN_CFLAGS])
gl_WARN_ADD([-Wno-sign-compare], [GNULIB_WARN_CFLAGS])

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
