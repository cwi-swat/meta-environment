# $Id$

CFLAGS += -Wno-unused-variable -Werror

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
	asfc -c -i $<

%.c: %.eqs
	asfc -t -i $< -o $@

%.idef: %.eqs
	asfc -t -i $< -o `basename $@ .idef`.c

%.tifs: %.idef
	idef2tif $<

toolDisplayQuery.tif.c toolDisplayQuery.tif.h: DisplayQuery.tifs
	tifstoc -tool toolDisplayQuery DisplayQuery.tifs

CLEANFILES = \
	DisplayQuery.c \
	DisplayQuery.idef \
	DisplayQuery.tifs \
	toolDisplayQuery.tif.c \
	toolDisplayQuery.tif.h
