
pkgdata_DATA	= $(wildcard *.tb) tide.tb tide.tifs
noinst_SCRIPTS  = tide.tifs

EXTRA_DIST	= $(wildcard *.tb) tide.tifs

tifs: tide.tb 
	${TOOLBUS}/bin/toolbus -I${srcdir} -gentifs $< -output tide.tifs
