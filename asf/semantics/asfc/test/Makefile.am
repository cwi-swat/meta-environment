# $Id$

SUBDIRS = terms
TESTS = regress-compiler

EXTRA_DIST = regress-compiler.sh.src codediff

CLEANFILES = $(TESTS)

% : %.sh.src
	sed 's@__TOP_SRCDIR__@$(top_srcdir)@g;\
	     s@__TOP_BUILDDIR__@$(top_builddir)@g' < $< > $@ && \
	chmod +x $@
