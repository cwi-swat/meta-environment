# $Id$

include $(top_srcdir)/make_rules

TOOL = findSortDefinition

SOURCE = \
	$(TOOL).c \
	$(TOOL).tif.c \
	$(TOOL).tif.h

EXTRA_DIST = $(TOOL).idef

bin_PROGRAMS = $(TOOL)
pkgdata_DATA = $(TOOL).idef

INCLUDES = \
	-I$(TOOLBUSLIB)/include \
	-I$(PT_SUPPORT)/include \
	-I$(SDF_SUPPORT)/include \
	-I$(ASF_SUPPORT)/include \
	-I$(ATERM)/include


findSortDefinition_SOURCES = $(SOURCE)
findSortDefinition_LDADD = \
	-L$(SDF_SUPPORT)/lib -lPT2SDF -lSDFME \
	-L$(ASF_SUPPORT)/lib -lASFME \
	-L$(PT_SUPPORT)/lib -lmept \
	-L$(TOOLBUSLIB)/lib -lATB \
	-L$(ATERM)/lib -lATerm \
	$(SOCKLIBS)
