# $Id$

include ${top_srcdir}/make_rules

EXTRA_DIST = sdf-imports.idef
pkgdata_DATA = sdf-imports.idef

bin_PROGRAMS = sdf-imports

sdf_imports_SOURCES = sdf-imports.c sdf-imports.tif.c
sdf_imports_LDADD = -L$(top_builddir)/lib -lSDFME \
                 -L$(ATERM)/lib -lATerm \
                 -L$(TOOLBUSLIB)/lib -lATB 

noinst_HEADERS		= sdf-imports.tif.h

INCLUDES	        = -I$(top_srcdir)/lib \
                          -I$(ATERM)/include  \
                          -I$(TOOLBUSLIB)/include \
                          -I$(SDF_SUPPORT)/include
