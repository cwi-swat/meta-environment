# $Id$
#
EXTRA_DIST = standard.rscript.actions.src

pkgdata_DATA = standard.rscript.actions
CLEANFILES=${pkgdata_DATA}

standard.rscript.actions:  standard.rscript.actions.src Makefile
	sed 's@__LIBRARY__@${pkgdatadir}/spec@g' < $< > $@
