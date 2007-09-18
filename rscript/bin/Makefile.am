# $Id: Makefile.am 21596 2007-03-01 10:29:19Z kooiker $

EXTRA_DIST = $(wildcard *.sh.src)

SUBDIRS = check run test

bin_SCRIPTS = \
	extract-relations \
	merge-rstores \
	rscript \
	rstore2rviz \
	init-rscript

CLEANFILES = \
	extract-relations \
	merge-rstores \
	rscript \
	rstore2rviz \
	init-rscript

% : %.sh.src Makefile
	sed "s@__PREFIX__@$(prefix)@g;\
             s@__BINDIR__@$(bindir)@g;\
             s@__DATADIR__@$(pkgdatadir)@g;\
             s@__SGLR__@$(SGLR_PREFIX)@g;\
             s@__PT_SUPPORT__@$(PT_SUPPORT_PREFIX)@g;" < $< > $@ && chmod +x $@
