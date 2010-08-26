# Makefile.am

lib_LTLIBRARIES = libdet.la

libdet_la_SOURCES = buffer.c \
		    daemon.c \
		    error.c \
		    signal.c \
		    socket.c \
		    socket_un.c \
		    utils.c

noinst_HEADERS = system.h

AM_CPPFLAGS = -I$(top_srcdir)/include \
	      -I$(top_builddir)/gl/gnu \
	      -I$(top_srcdir)/gl/gnu

AM_CFLAGS = $(CFLAG_VISIBILITY) \
	    $(WARN_CFLAGS) \
	    $(WERROR_CFLAGS) \
	    $(DEBUG_CFLAGS)

libdet_la_LDFLAGS = -version-info 0:0:0

if HAVE_LD_VERSION_SCRIPT
libdet_la_LDFLAGS += -Wl,--version-script=$(srcdir)/libdet.map
endif

libdet_la_LIBADD = ../gl/gnu/libgnu.la

EXTRA_DIST = libdet.map
