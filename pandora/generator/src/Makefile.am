# $Id$

SUBDIRS=examples

INCLUDES = \
	-I$(top_srcdir)/libsglr \
	-I$(PT_SUPPORT)/include \
	-I$(SDF_SUPPORT)/include \
	-I$(TOOLBUSLIB)/include \
	-I$(ERROR_SUPPORT)/include \
	-I$(ATERM)/include

bin_PROGRAMS = pandora 

noinst_HEADERS = pandora.h Box.h

#pkgdata_DATA = ptpretty.idef
#EXTRA_DIST = ptpretty.idef

pandora_SOURCES = main.c pandora.c Box.c
pandora_LDADD = \
	-L$(SDF_SUPPORT)/lib -lSDFME -lSDF2PT \
	-L$(PT_SUPPORT)/lib -lmept \
	-L$(ERROR_SUPPORT)/lib -lErrorAPI \
	-L$(TOOLBUSLIB)/lib -lATB \
	-L$(ATERM)/lib -lATerm  \
	$(SOCKLIBS)

#tif:
#	for i in `ls *.idef`; do \
#          idef2tif $$i; \
#          tifstoc -tool `basename $$i .idef` `basename $$i .idef`.tifs; \
#        done
#
#tif-clean:
#	rm -f *.tifs *.tif.[ch]
#
