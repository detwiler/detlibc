# Makefile.am

bin_PROGRAMS = fatest

fatest_SOURCES = fatest.c

AM_CPPFLAGS = -I$(top_srcdir)/include \
	      -I$(top_srcdir)/lib/common

fatest_LDADD = ../lib/det/libdet.la

AM_CFLAGS = $(DET_CFLAGS)

if DET_GOBS_WARN
AM_CFLAGS += -Wstrict-prototypes -Wold-style-definition
endif
