# $Id$

SUBDIRS=examples

INCLUDES = \
	-I$(top_srcdir)/libsglr \
	-I$(PT_SUPPORT)/include \
	-I$(SDF_SUPPORT)/include \
	-I$(TOOLBUSLIB)/include \
	-I$(ATERM)/include

bin_PROGRAMS = ptpretty 

noinst_HEADERS = pretty.h ptpretty.tif.h

pkgdata_DATA = ptpretty.idef
EXTRA_DIST = ptpretty.idef

ptpretty_SOURCES = main.c pretty.c ptpretty.tif.c
ptpretty_LDADD = \
	-L$(SDF_SUPPORT)/lib -lSDFME -lSDF2PT \
	-L$(PT_SUPPORT)/lib -lmept \
	-L$(TOOLBUSLIB)/lib -lATB \
	-L$(ATERM)/lib -lATerm  \
	$(SOCKLIBS)

tif:
	for i in `ls *.idef`; do \
          idef2tif $$i; \
          tifstoc -tool `basename $$i .idef` `basename $$i .idef`.tifs; \
        done

tif-clean:
	rm -f *.tifs *.tif.[ch]

