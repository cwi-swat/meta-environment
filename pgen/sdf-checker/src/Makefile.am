# $Id$

include ${top_srcdir}/make_rules

INCLUDES		= -I$(ASC_SUPPORT)/include \
			-I$(PT_SUPPORT)/include \
			-I$(SDF_SUPPORT)/include \
			-I$(ASF_SUPPORT)/include \
			-I$(TOOLBUSLIB)/include \
			-I$(ATERM)/include

bin_PROGRAMS = sdfchecker

pkgdata_DATA    = sdfchecker.idef

EXTRA_DIST   = sdfchecker.idef 

noinst_HEADERS = sdfchecker.tif.h
sdfchecker_SOURCES = sdfchecker.c Sdf-Checker.c sdfchecker.tif.c
sdfchecker_LDADD   = -L$(ASC_SUPPORT)/lib -lasc-support-me \
                       -L$(SDF_SUPPORT)/lib -lSDFME \
                       -L$(ASF_SUPPORT)/lib -lASFME \
                       -L$(PT_SUPPORT)/lib -lmept -lPTMEPT \
                       -L$(TOOLBUSLIB)/lib -lATB \
                       -L$(ATERM)/lib -lATerm \
			$(SOCKLIBS)

