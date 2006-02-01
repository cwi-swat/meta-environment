INCLUDES = ${ASC_INCLUDES}

EXTRA_DIST = \
	pandora.idef.src

bin_PROGRAMS = pandora 

noinst_HEADERS = pandora.h Box.h Box-utils.h Box_dict.h pandora.tif.h

pkgdata_DATA = pandora.idef

pandora_SOURCES = \
	main.c \
	pandora.c \
	Box.c \
	Box-utils.c \
	Box_dict.c \
	Box-to-Text.c \
	pandora.tif.c

pandora_LDADD = ${ASC_LD_FLAGS}

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@

asfc:
	asfc \
		-i ${top_builddir}/formatter/text/Box-to-Text.eqs \
		-o Box-to-Text.c -v
api:
	unparsePT < Box.def.pt > Box.def
	sdf2-to-c -i Box.def --prefix BOX_ -v

tif:
	for i in `ls *.idef`; do \
          idef2tif $$i; \
          tifstoc -tool `basename $$i .idef` `basename $$i .idef`.tifs; \
        done

tif-clean:
	rm -f *.tifs *.tif.[ch]
