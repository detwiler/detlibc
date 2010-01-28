# Makefile.am

noinst_LTLIBRARIES = libcommon.la

libcommon_la_SOURCES =

noinst_HEADERS = common.h

AM_CFLAGS = $(DET_CFLAGS)

if DET_GOBS_WARN
AM_CFLAGS += -Wstrict-prototypes -Wold-style-definition
endif
