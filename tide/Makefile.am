
SUBDIRS		= . tide lib-c examples

data_DATA	= tide.tb tide.tifs

EXTRA_DIST	= tide.tb tide.sh.src

bin_SCRIPTS	= tide

tide.tifs: ${srcdir}/tide.tb
	cp ${srcdir}/tide.tb tmp-tide.tb
	${TOOLBUS}/bin/toolbus -gentifs tmp-tide.tb
	mv tmp-tide.tifs tide.tifs
	rm tmp-tide.tb

%: %.sh.src Makefile
	sed 's@__JARDIR__@${datadir}@g;\
	     s@__TBDIR__@${datadir}@g;\
	' < $< > $@ && chmod +x $@


