# $Id$

include ${top_srcdir}/make_rules

INCLUDES		= -I$(PT_SUPPORT)/include \
			-I$(ASF_SUPPORT)/include \
			-I$(TOOLBUSLIB)/include \
			-I$(ATERM)/include \
			-I$(ERROR_SUPPORT)/include

bin_PROGRAMS = asfchecker

pkgdata_DATA    = asfchecker.idef

EXTRA_DIST   = asfchecker.idef asfchecker.tif.c asfchecker.tif.h

noinst_HEADERS 	= equationChecker.h asfchecker.tif.h

asfchecker_SOURCES = asfchecker.c equationChecker.c asfchecker.tif.c
asfchecker_LDADD   = \
	-L$(ERROR_SUPPORT)/lib -lErrorAPI \
	-L$(ASF_SUPPORT)/lib -lASFME \
        -L$(PT_SUPPORT)/lib -lmept \
        -L$(TOOLBUSLIB)/lib -lATB \
        -L$(ATERM)/lib -lATerm \
	$(SOCKLIBS)

