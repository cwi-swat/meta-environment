# $Id$

include ${top_srcdir}/make_rules

INCLUDES		= -I$(ASC_SUPPORT)/include \
			-I$(PT_SUPPORT)/include \
			-I$(SDF_SUPPORT)/include \
			-I$(ASF_SUPPORT)/include \
			-I$(TOOLBUSLIB)/include \
			-I$(ATERM)/include

bin_PROGRAMS = asfsdfchecker

pkgdata_DATA    = asfsdfchecker.idef

EXTRA_DIST   = asfsdfchecker.idef asfsdfchecker.tif.c asfsdfchecker.tif.h

asfsdfchecker_SOURCES = asfsdfchecker.c AsfSdf-Checker.c
asfsdfchecker_LDADD   = asfsdfchecker.tif.o \
                       -L$(ASC_SUPPORT)/lib -lasc-support-me \
                       -L$(SDF_SUPPORT)/lib -lSDFME \
                       -L$(ASF_SUPPORT)/lib -lASFME \
                       -L$(PT_SUPPORT)/lib -lmept \
                       -L$(TOOLBUSLIB)/lib -lATB \
                       -L$(ATERM)/lib -lATerm \
			$(SOCKLIBS)


CLEANFILES = asfsdfchecker.tifs

asfsdfchecker.o : asfsdfchecker.tif.h
