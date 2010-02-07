# Makefile.am

lib_LTLIBRARIES = libdet.la

libdet_la_SOURCES = error.c

noinst_HEADERS = system.h

# libdet_la_LIBADD = ../gl/gnulib.la

AM_CPPFLAGS = -I$(top_srcdir)/include

AM_CFLAGS = @DET_CFLAGS@

if DET_GOBS_WARN
AM_CFLAGS += -Wstrict-prototypes -Wold-style-definition
endif
