# $Id$

SUBDIRS    = grammars tables terms erroneous

EXTRA_DIST = lang-types regress-lang.sh.src regress-terms.sh.src

TESTS      = regress-lang regress-terms

CLEANFILES = $(TESTS) 

% : %.sh.src Makefile
	sed "s@__TOP_BUILDDIR__@$(top_builddir)@g;\
             s@__TOP_SRCDIR__@$(top_srcdir)@g;\
             s@__SGLR__@$(SGLR)@g;\
             s@__ERROR_SUPPORT__@$(ERROR_SUPPORT)@g;\
             s@__ATERM__@$(ATERM)@g" < $< > $@ && \
	chmod +x $@
