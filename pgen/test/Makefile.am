# $Id$

SUBDIRS    = grammars tables

EXTRA_DIST = lang-types regress-lang.sh.src 

TESTS      = regress-lang

CLEANFILES = $(TESTS)

% : %.sh.src Makefile
	sed 's@__TOP_BUILDDIR__@$(top_builddir)@g;\
             s@__TOP_SRCDIR__@$(top_srcdir)@g;\
             s@__ATERM__@$(ATERM)@g' < $< > $@ && \
	chmod +x $@
