
pkgdata_DATA	= $(wildcard *.tb) tide.tb tide.tifs
noinst_SCRIPTS  = tide.tifs

EXTRA_DIST	= $(wildcard *.tb) tide.tifs

INCLUDES = \
	-I. \
	-I${srcdir} \
	-I${TIDE_SUPPORT}/share/tide-support

tifs: tide.tb 
	${TOOLBUS}/bin/toolbus ${INCLUDES} -gentifs $< -output tide.tifs
