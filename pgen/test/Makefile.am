# $Id$

SUBDIRS    = grammars tables terms erroneous modules

EXTRA_DIST = regressionTests.sh.src loadTests.sh.src

TESTS      = regressionTests loadTests

CLEANFILES = $(TESTS)  Load.tbl

% : %.sh.src Makefile
	sed "s@__TOP_BUILDDIR__@$(top_builddir)@g;\
             s@__TOP_SRCDIR__@$(top_srcdir)@g;\
             s@__SGLR__@$(SGLR_PREFIX)@g;\
             s@__PT_SUPPORT__@$(PT_SUPPORT_PREFIX)@g;\
             s@__ERROR_SUPPORT__@$(ERROR_SUPPORT_PREFIX)@g;\
             s@__ATERM__@$(ATERM_PREFIX)@g" < $< > $@ && \
	chmod +x $@
