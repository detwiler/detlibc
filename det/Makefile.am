# Makefile.am

lib_LTLIBRARIES = libdet.la

libdet_la_SOURCES = error.c

noinst_HEADERS = system.h

AM_CPPFLAGS = -I$(top_srcdir)/include \
	      -I$(top_builddir)/gl \
	      -I$(top_srcdir)/gl

libdet_la_LDFLAGS = -version-info 0:0:0

libdet_la_LIBADD = ../gl/libgnu.la

AM_CFLAGS = @DET_CFLAGS@

if DET_GOBS_WARN
AM_CFLAGS += -Wstrict-prototypes -Wold-style-definition
endif
