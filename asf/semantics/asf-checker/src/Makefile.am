# $Id$

include ${top_srcdir}/make_rules

INCLUDES		= -I$(PT_SUPPORT)/include \
			-I$(ASF_SUPPORT)/include \
			-I$(TOOLBUSLIB)/include \
			-I$(ATERM)/include

bin_PROGRAMS = asfchecker

data_DATA    = asfchecker.idef

EXTRA_DIST   = asfchecker.idef asfchecker.tif.c asfchecker.tif.h

noinst_HEADERS 	= equationChecker.h

asfchecker_SOURCES = asfchecker.c equationChecker.c
asfchecker_LDADD   = asfchecker.tif.o \
                       -L$(ASF_SUPPORT)/lib -lASFME \
                       -L$(PT_SUPPORT)/lib -lmept \
                       -L$(TOOLBUSLIB)/lib -lATB \
                       -L$(ATERM)/lib -lATerm \
			$(SOCKLIBS)


CLEANFILES = asfchecker.tifs

asfchecker.o : asfchecker.tif.h
