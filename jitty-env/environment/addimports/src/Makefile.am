# $Id$

include ${top_srcdir}/make_rules

INCLUDES         = -I$(ASC_SUPPORT)/include \
                   -I$(TOOLBUSLIB)/include \
                   -I$(PT_SUPPORT)/include \
                   -I$(SDF_SUPPORT)/include \
                   -I$(ASF_SUPPORT)/include \
                   -I$(ATERM)/include

bin_PROGRAMS = addimports

pkgdata_DATA = addimports.idef

EXTRA_DIST   = addimports.idef 

noinst_HEADERS = addimports.tif.h
addimports_SOURCES = addimports.c AddImports.c addimports.tif.c
addimports_LDADD   = -L$(ASC_SUPPORT)/lib -lasc-support-me \
                       -L$(SDF_SUPPORT)/lib -lSDFME \
                       -L$(ASF_SUPPORT)/lib -lASFME \
                       -L$(PT_SUPPORT)/lib -lmept \
                       -L$(TOOLBUSLIB)/lib -lATB \
                       -L$(ATERM)/lib -lATerm \
			$(SOCKLIBS)
