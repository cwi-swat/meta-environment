# $Id$

include ${top_srcdir}/make_rules

EXTRA_DIST=showdot.tcl.src showdot.src

pkgdata_DATA   = showdot.tcl
bin_SCRIPTS = showdot

CLEANFILES  = showdot

% : %.src Makefile
	sed 's@__WISH__@$(WISH)@g;\
	     s@__GRAPHVIZ__@$(GRAPHVIZ)@g;\
	     s@__DATADIR__@$(pkgdatadir)@g' < $< > $@ && \
	chmod +x $@
