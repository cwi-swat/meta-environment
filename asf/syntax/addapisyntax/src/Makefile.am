# $Id$

include ${top_srcdir}/make_rules

INCLUDES         = -I$(ASC_SUPPORT)/include \
                   -I$(TOOLBUSLIB)/include \
                   -I$(PT_SUPPORT)/include \
                   -I$(SDF_SUPPORT)/include \
                   -I$(ASF_SUPPORT)/include \
                   -I$(ATERM)/include

bin_PROGRAMS = addapisyntax

pkgdata_DATA = addapisyntax.idef
EXTRA_DIST   = addapisyntax.idef

noinst_HEADERS = addapisyntax.tif.h
addapisyntax_SOURCES = addapisyntax.tif.c addapisyntax.c Add-API-Syntax.c
addapisyntax_LDADD   = -L$(ASC_SUPPORT)/lib -lasc-support-me \
                       -L$(SDF_SUPPORT)/lib -lSDFME \
                       -L$(ASF_SUPPORT)/lib -lASFME \
                       -L$(PT_SUPPORT)/lib -lmept \
                       -L$(TOOLBUSLIB)/lib -lATB \
                       -L$(ATERM)/lib -lATerm \
			$(SOCKLIBS)
