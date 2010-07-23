# Makefile.am

TESTS = check_buffer

check_PROGRAMS = $(TESTS) \
		 test-buffer-fread-all \
		 test-err-dump \
		 test-err-exit \
		 test-err-msg \
		 test-err-ret \
		 test-err-sys \
		 test-err-quit \
		 test-socket-signal

EXTRA_DIST = check_buffer.c \
	     test-buffer-fread-all.c \
	     test-err-dump.c \
	     test-err-exit.c \
	     test-err-msg.c \
	     test-err-ret.c \
	     test-err-sys.c \
	     test-err-quit.c \
	     test-socket-signal

TESTSUITE_AT = testsuite.at \
	       local.at \
	       buffer-fread-all.at \
	       err-dump.at \
	       err-exit.at \
	       err-msg.at \
	       err-ret.at \
	       err-sys.at \
	       err-quit.at \
	       sock-sig.at

AM_CPPFLAGS = -I$(top_srcdir)/include \
	      -I$(top_builddir)/gl/gnu \
	      -I$(top_srcdir)/gl/gnu \
	      -I$(top_srcdir)/det \
	      $(CHECK_CFLAGS)

AM_CFLAGS = $(WARN_CFLAGS) \
	    $(WERROR_CFLAGS) \
	    $(DEBUG_CFLAGS) \
	    $(CHECK_CFLAGS)

LDADD = ../det/libdet.la \
	$(CHECK_LIBS)

$(srcdir)/package.m4: $(top_srcdir)/configure.ac $(top_srcdir)/.version
	$(AM_V_GEN):;{ \
	  echo '# Signature of the current package.' && \
	  echo 'm4_define([AT_PACKAGE_NAME], [@PACKAGE_NAME@])' && \
	  echo 'm4_define([AT_PACKAGE_TARNAME], [@PACKAGE_TARNAME@])' && \
	  echo 'm4_define([AT_PACKAGE_VERSION], [@PACKAGE_VERSION@])' && \
	  echo 'm4_define([AT_PACKAGE_STRING], [@PACKAGE_STRING@])' && \
	  echo 'm4_define([AT_PACKAGE_BUGREPORT], [@PACKAGE_BUGREPORT@])'; \
	  } >'$(srcdir)/package.m4'

TESTSUITE = $(srcdir)/testsuite

EXTRA_DIST += $(TESTSUITE_AT) \
	     $(srcdir)/package.m4 \
	     $(TESTSUITE) \
	     atlocal.in

AUTOMATE = $(SHELL) $(top_srcdir)/build-aux/missing --run autom4te

AUTOTEST = $(AUTOMATE) --language=autotest

$(TESTSUITE): $(srcdir)/package.m4 $(TESTSUITE_AT)
	$(AUTOTEST) -I '$(srcdir)' -o $@.tmp $@.at
	mv $@.tmp $@

check-local: atconfig atlocal $(TESTSUITE)
	$(SHELL) '$(TESTSUITE)' $(TESTSUITEFLAGS)

# adding AUTOTEST_PATH='$(bindir)' causes distcheck to fail
installcheck-local: atconfig atlocal $(TESTSUITE)
	$(SHELL) '$(TESTSUITE)' $(TESTSUITEFLAGS)

DISTCLEANFILES = atconfig

clean-local:
	test ! -f '$(TESTSUITE)' || $(SHELL) '$(TESTSUITE)' --clean
