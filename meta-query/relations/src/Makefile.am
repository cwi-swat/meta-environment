# $Id$

CFLAGS += -Wno-unused -Werror

ASFC = $(ASF)/bin/asfc
IDEF2TIF = $(TOOLBUS)/bin/idef2tif
TIFSTOC = $(TOOLBUS)/bin/tifstoc

INCLUDES = \
	-DASF_MAIN \
	-DTOOLBUS \
	-I$(ASC_SUPPORT)/include \
	-I$(TOOLBUSLIB)/include \
	-I$(PT_SUPPORT)/include \
	-I$(SDF_SUPPORT)/include \
	-I$(ASF_SUPPORT)/include \
	-I$(ATERM)/include

bin_PROGRAMS = DisplayQuery MergeRstores
pkgdata_DATA = DisplayQuery.idef

DisplayQuery_SOURCES = \
	toolDisplayQuery.tif.h \
	toolDisplayQuery.tif.c \
	DisplayQuery.c

DisplayQuery_LDADD = \
	-L$(ASC_SUPPORT)/lib -ltb-asc-support-me \
	-L$(SDF_SUPPORT)/lib -lSDFME \
	-L$(ASF_SUPPORT)/lib -lASFME \
	-L$(PT_SUPPORT)/lib -lmept \
	-L$(TOOLBUSLIB)/lib -lATB \
	-L$(ATERM)/lib -lATerm \
	$(SOCKLIBS)

MergeRstores: MergeRstores.eqs
	$(ASF)/bin/asfc -c -i $<

%.c: %.eqs
	$(ASFC) -t -i $< -o $@

%.idef: %.eqs
	$(ASFC) -t -i $< -o `basename $@ .idef`.c

%.tifs: %.idef
	$(IDEF2TIF) $<

toolDisplayQuery.tif.c toolDisplayQuery.tif.h: DisplayQuery.tifs
	$(TIFSTOC) -tool toolDisplayQuery DisplayQuery.tifs

EXTRA_DIST = \
	DisplayQuery.idef

CLEANFILES = \
	DisplayQuery.c \
	DisplayQuery.idef \
	DisplayQuery.tifs \
	toolDisplayQuery.tif.c \
	toolDisplayQuery.tif.h
