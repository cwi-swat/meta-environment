# $Id$

include ${top_srcdir}/make_rules

INCLUDES		= -I$(PT_SUPPORT)/include \
			-I$(ASF_SUPPORT)/include \
			-I$(TOOLBUSLIB)/include \
			-I$(ATERM)/include

bin_PROGRAMS = asfoperations

pkgdata_DATA    = asfoperations.idef

EXTRA_DIST   = asfoperations.idef 

noinst_HEADERS 	= asfoperations.tif.h

asfoperations_SOURCES = asfoperations.c asfoperations.tif.c
asfoperations_LDADD   = -L$(ASF_SUPPORT)/lib -lASFME \
                       -L$(PT_SUPPORT)/lib -lmept \
                       -L$(TOOLBUSLIB)/lib -lATB \
                       -L$(ATERM)/lib -lATerm \
			$(SOCKLIBS)
