
pkgdata_DATA	= $(wildcard *.tb) control.tb tide.tifs
noinst_SCRIPTS  = tide.tifs

EXTRA_DIST	= $(wildcard *.tb) control.tb.src tide.tifs

CLEANFILES = control.tb

INCLUDES = \
	-I. \
	-I${srcdir} \
	-I${TIDE_SUPPORT}/share/tide-support

tifs: tide.tb 
	${TOOLBUS}/bin/toolbus ${INCLUDES} -gentifs $< -output tide.tifs

control.tb: control.tb.src
	sed 's@__PKGDATA__@${pkgdatadir}@' < $< > $@
