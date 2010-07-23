# det_args.m4

# DET_ARG_WITH(PARAMETER, DEFAULT_VALUE)
# ------------------------------------------------
# Wrapper around AC_ARG_WITH
# e.g.: DET_ARG_WITH([foo], [no])
# will generate a configure option --with-foo. The option's argument will be 
# stored in with_foo. The default value for the option would be no.
AC_DEFUN([DET_ARG_WITH],
         [AC_ARG_WITH([m4_translit([$1], [_], [-])],
                        [AS_HELP_STRING([--with-m4_translit([$1], [_], [-])],
                                        [with $1 (default=$2)])],
                        [with_[]$1=$withval],
                        [with_[]$1=$2])])

# DET_ARG_ENABLE(PARAMETER, DEFAULT_VALUE)
# ------------------------------------------------
# Wrapper around AC_ARG_ENABLE
# e.g.: DET_ARG_ENABLE([foo], [no])
# will generate a configure option --enable-foo. The option's argument will be 
# stored in enable_foo. The default value for the option is no.
AC_DEFUN([DET_ARG_ENABLE],
         [AC_ARG_ENABLE([m4_translit([$1], [_], [-])],
                        [AS_HELP_STRING([--enable-m4_translit([$1], [_], [-])],
                                        [enable $1 (default=$2)])],
                        [enable_[]$1=$enableval],
                        [enable_[]$1=$2])])
