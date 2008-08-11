# $Id$

EXTRA_DIST = $(wildcard *.sh.src)

bin_SCRIPTS = \
	extract-relations \
	merge-rstores \
	rscript \
	rstore2rviz 

CLEANFILES = \
	extract-relations \
	merge-rstores \
	rscript \
	rstore2rviz 

% : %.sh.src Makefile
	sed "s@__PREFIX__@$(prefix)@g;\
             s@__BINDIR__@$(bindir)@g;\
             s@__DATADIR__@$(pkgdatadir)@g;\
             s@__SGLR__@$(SGLR_PREFIX)@g;\
             s@__PT_SUPPORT__@$(PT_SUPPORT_PREFIX)@g;\
             s@__ERROR_SUPPORT__@$(ERROR_SUPPORT_PREFIX)@g;" < $< > $@ && chmod +x $@
