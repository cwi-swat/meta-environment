# $Id$

include ${top_srcdir}/make_rules

INCLUDES		= -I$(PT_SUPPORT)/include \
			-I$(ASF_SUPPORT)/include \
			-I$(SDF_SUPPORT)/include \
			-I$(TOOLBUSLIB)/include \
			-I$(ATERM)/include

bin_PROGRAMS = asfoperations

pkgdata_DATA    = asfoperations.idef

EXTRA_DIST   = asfoperations.idef asfoperations.tif.c asfoperations.tif.h

noinst_HEADERS 	= renaming-symbols.h

asfoperations_SOURCES = asfoperations.c renaming-symbols.c
asfoperations_LDADD   = asfoperations.tif.o \
                       -L$(ASF_SUPPORT)/lib -lASFME \
                       -L$(SDF_SUPPORT)/lib -lSDFME \
                       -L$(PT_SUPPORT)/lib -lmept \
                       -L$(TOOLBUSLIB)/lib -lATB \
                       -L$(ATERM)/lib -lATerm \
			$(SOCKLIBS)


CLEANFILES = asfoperations.tifs

asfoperations.o : asfoperations.tif.h
