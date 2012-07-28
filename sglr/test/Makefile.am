# $Id$

SUBDIRS    = erroneous tables terms

EXTRA_DIST = lang-types regressionTests.sh.src

TESTS      = regressionTests

CLEANFILES = regressionTests

% : %.sh.src Makefile 
	sed "s@__ATERM__@$(ATERM_PREFIX)@g;\
	     s@__PT_SUPPORT__@$(PT_SUPPORT_PREFIX)@g;\
	     s@__ERROR_SUPPORT__@$(ERROR_SUPPORT_PREFIX)@g;\
	     s@__SGLR_BINARY__@$(top_builddir)/src/sglr@g;\
	     s@__SGLR__@$(top_builddir)@g;\
	     s@__SRCDIR__@$(srcdir)@g" < $< > $@ && \
	chmod +x $@
