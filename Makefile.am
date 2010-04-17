# Makefile.am

SUBDIRS = include \
	  gl \
	  det \
	  tests

pkgdata_DATA = $(PACKAGE)-release

CLEANFILES = $(pkgdata_DATA)

.PHONY: $(PACKAGE)-release
$(PACKAGE)-release:
	$(AM_V_GEN)echo "$(PACKAGE) release $(VERSION)" > $@-t && mv $@-t $@

BUILT_SOURCES = $(top_srcdir)/.version

$(top_srcdir)/.version:
	$(AM_V_GEN)echo $(VERSION) > $@-t && mv $@-t $@

dist-hook: gen-ChangeLog
	$(AM_V_GEN)echo $(VERSION) > $(distdir)/.tarball-version

.PHONY: gen-ChangeLog
gen-ChangeLog:
	$(AM_V_GEN)if test -d .git; then				\
	  $(top_srcdir)/build-aux/gitlog-to-changelog > $(distdir)/cl-t;\
	  rm -f $(distdir)/ChangeLog;					\
	  mv $(distdir)/cl-t $(distdir)/ChangeLog;			\
	fi

EXTRA_DIST = .version

ACLOCAL_AMFLAGS = -I m4 -I gl/m4
