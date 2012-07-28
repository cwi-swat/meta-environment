# $Id: Makefile.am 26340 2008-08-29 12:27:54Z jurgenv $

EXTRA_DIST = $(wildcard *.sh.src)

bin_SCRIPTS = \
	defacto

CLEANFILES = \
	defacto

% : %.sh.src Makefile
	sed "s@__PREFIX__@$(prefix)@g;\
             s@__BINDIR__@$(bindir)@g;\
             s@__DATADIR__@$(pkgdatadir)@g;\
             s@__SGLR__@$(SGLR_PREFIX)@g;\
             s@__RSTORE_SUPPORT__@$(RSTORE_SUPPORT_PREFIX)@g;\
             s@__PT_SUPPORT__@$(PT_SUPPORT_PREFIX)@g;\
             s@__ASF__@$(ASF_PREFIX)@g;\
             s@__PGEN__@$(PGEN_PREFIX)@g;" < $< > $@ && chmod +x $@
