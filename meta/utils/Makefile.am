# $Id$

include ${top_srcdir}/make_rules

bin_SCRIPTS        = ps-dot

EXTRA_DIST         = ps-dot.sh.src 

CLEANFILES         = ps-dot 

% : %.sh.src Makefile
	sed 's@__BINDIR__@$(bindir)@g;\
	     s@__DATADIR__@$(datadir)@g;\
	     s@__PT_SUPPORT__@$(PT_SUPPORT)@g;\
	     s@__PGEN__@$(PGEN)@g;\
	     s@__SGLR__@$(SGLR)@g;\
	     s@__BINFILES__@$(bin_PROGRAMS) $(bin_SCRIPTS)@g;\
	     s@__VERSION__@$(VERSION)@g;\
	     s@__PERL__@$(PERL)@g' < $< > $@ && \
	chmod +x $@
