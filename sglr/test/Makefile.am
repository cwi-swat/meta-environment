# $Id$

SUBDIRS    = erroneous tables terms

EXTRA_DIST = lang-types regress-terms.sh.src

TESTS      = regress-terms

CLEANFILES = regress-terms

% : %.sh.src 
	sed 's@__ATERM__@$(ATERM)@g;\
	     s@__ERROR_SUPPORT__@$(ERROR_SUPPORT)@g;\
	     s@__SRCDIR__@$(srcdir)@g' < $< > $@ && \
	chmod +x $@
