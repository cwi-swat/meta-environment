# $Id$

include ${top_srcdir}/make_rules

EXTRA_DIST = sdf-imports.idef
pkgdata_DATA = sdf-imports.idef

bin_PROGRAMS = sdf-imports

sdf_imports_SOURCES = sdf-tool.c sdf-tool.tif.c
sdf_imports_LDADD = -L$(top_builddir)/lib -lSDFME \
                 -L$(ATERM)/lib -lATerm \
                 -L$(TOOLBUSLIB)/lib -lATB 

noinst_HEADERS		= sdf-imports.tif.h

INCLUDES	        = -I$(ATERM)/include  \
                          -I$(TOOLBUSLIB)/include \
                          -I$(SDF_SUPPORT)/include
