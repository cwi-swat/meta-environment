# $Id$

include $(top_srcdir)/make_rules

TOOL = FindSortDefinition

SOURCE = \
	$(TOOL).c \
	toolFindSortDefinition.tif.c \
	toolFindSortDefinition.tif.h

EXTRA_DIST = $(TOOL).idef

bin_PROGRAMS = $(TOOL)
pkgdata_DATA = $(TOOL).idef

INCLUDES = \
	-I$(ASC_SUPPORT)/include \
	-I$(TOOLBUSLIB)/include \
	-I$(PT_SUPPORT)/include \
	-I$(SDF_SUPPORT)/include \
	-I$(ASF_SUPPORT)/include \
	-I$(ATERM)/include


CFLAGS += -DASF_MAIN -DTOOLBUS
FindSortDefinition_SOURCES = $(SOURCE)
FindSortDefinition_LDADD = \
	-L$(ASC_SUPPORT)/lib -ltb-asc-support-me \
	-L$(ASF_SUPPORT)/lib -lASFME \
	-L$(PT_SUPPORT)/lib -lmept \
	-L$(TOOLBUSLIB)/lib -lATB \
	-L$(ATERM)/lib -lATerm \
	$(SOCKLIBS)
