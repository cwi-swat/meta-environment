# $Id$

include ${top_srcdir}/make_rules

INCLUDES = \
	-I$(ASC_SUPPORT)/include \
	-I$(PT_SUPPORT)/include \
	-I$(SDF_SUPPORT)/include \
	-I$(ASF_SUPPORT)/include \
	-I$(TOOLBUSLIB)/include \
	-I$(ATERM)/include

bin_PROGRAMS = asfsdfchecker

pkgdata_DATA = asfsdfchecker.idef

EXTRA_DIST = asfsdfchecker.idef 
noinst_HEADERS = asfsdfchecker.tif.h

asfsdfchecker_SOURCES = asfsdfchecker.c AsfSdf-Checker.c asfsdfchecker.tif.c
asfsdfchecker_LDADD = \
	-L$(ASC_SUPPORT)/lib -lasc-support-me \
	-L$(SGLR)/lib -lsglr \
	-L$(SDF_SUPPORT)/lib -lSDFME \
	-L$(ASF_SUPPORT)/lib -lASFME \
	-L$(PT_SUPPORT)/lib -lmept -lPTMEPT \
	-L$(TOOLBUSLIB)/lib -lATB \
	-L$(ATERM)/lib -lATerm \
	$(SOCKLIBS)
