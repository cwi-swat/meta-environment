
pkgdata_DATA	= $(wildcard *.tb) tide.tb tide.tifs

EXTRA_DIST	= $(wildcard *.tb)

tide.tifs: ${srcdir}/tide.tb
	cp ${srcdir}/tide.tb tmp-tide.tb
	${TOOLBUS}/bin/toolbus -I. -gentifs tmp-tide.tb
	mv tmp-tide.tifs tide.tifs
	rm tmp-tide.tb

