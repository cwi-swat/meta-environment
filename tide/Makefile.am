
SUBDIRS		= . tide lib-c

data_DATA	= tide.tb tide.tifs

EXTRA_DIST	= tide.sh.src

bin_SCRIPTS	= tide

tide.tifs: tide.tb
	${TOOLBUS}/bin/toolbus -gentifs tide.tb

%: %.sh.src Makefile
	sed 's@__JARDIR__@${datadir}@g;\
	     s@__TBDIR__@${datadir}@g;\
	' < $< > $@ && chmod +x $@


