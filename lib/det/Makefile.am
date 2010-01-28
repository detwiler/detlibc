# Makefile.am

lib_LTLIBRARIES = libdet.la

libdet_la_SOURCES =

libdet_la_LIBADD = ../common/libcommon.la

AM_CPPFLAGS = -I$(top_srcdir)/include \
	      -I$(top_srcdir)/lib/common

AM_CFLAGS = $(DET_CFLAGS)

if DET_GOBS_WARN
AM_CFLAGS += -Wstrict-prototypes -Wold-style-definition
endif
