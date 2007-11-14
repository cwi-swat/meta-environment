
pkgdata_DATA	= $(wildcard *.tb) control.tb tide.tifs
noinst_SCRIPTS  = tide.tifs

EXTRA_DIST	= \
		  adapter.tb  \
		  tide.tb  \
		  tool.tb \
		  control.tb.src \
		  tide.tifs

CLEANFILES = control.tb

INCLUDES = \
	-I. \
	-I${srcdir} \
	-I${TIDE_SUPPORT}/share/tide-support

control.tb: control.tb.src Makefile
	sed 's@__DATA__@${datadir}@' < $< > $@
