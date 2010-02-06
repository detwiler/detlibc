# Makefile.am

check_PROGRAMS = test-err-dump \
		 test-err-msg \
		 test-err-quit

EXTRA_DIST = test-err-dump.c \
	     test-err-msg.c \
	     test-err-quit.c

TESTSUITE_AT = testsuite.at \
	       local.at \
	       err-dump.at \
	       err-msg.at \
	       err-quit.at

AM_CPPFLAGS = -I$(top_srcdir)/include \
	      -I$(top_srcdir)/det

LDADD = ../det/libdet.la

$(srcdir)/package.m4: $(top_srcdir)/configure.ac
	:;{ \
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
