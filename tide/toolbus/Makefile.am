
pkgdata_DATA	= tide.tb tide.tifs

EXTRA_DIST	= tide.tb

tide.tifs: ${srcdir}/tide.tb
	cp ${srcdir}/tide.tb tmp-tide.tb
	${TOOLBUS}/bin/toolbus -gentifs tmp-tide.tb
	mv tmp-tide.tifs tide.tifs
	rm tmp-tide.tb

