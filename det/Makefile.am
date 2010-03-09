# Makefile.am

lib_LTLIBRARIES = libdet.la

libdet_la_SOURCES = buffer.c \
		    error.c \
		    signal.c \
		    socket.c \
		    socket_un.c

noinst_HEADERS = system.h

AM_CPPFLAGS = -I$(top_srcdir)/include \
	      -I$(top_builddir)/gl/gnu \
	      -I$(top_srcdir)/gl/gnu

libdet_la_LDFLAGS = -version-info 0:0:0

libdet_la_LIBADD = ../gl/gnu/libgnu.la

AM_CFLAGS = @DET_CFLAGS@

if DET_GOBS_WARN
AM_CFLAGS += -Wstrict-prototypes -Wold-style-definition
endif
