# $Id$

EXTRA_DIST = sdf-tool.idef
pkgdata_DATA = sdf-tool.idef

bin_PROGRAMS = sdf-tool

sdf_tool_SOURCES = sdf-tool.c sdf-tool.tif.c
sdf_tool_LDADD = -L$(top_builddir)/lib -lSDFME \
                 -L$(ATERM)/lib -lATerm \
                 -L$(TOOLBUSLIB)/lib -lATB 

noinst_HEADERS		= sdf-tool.tif.h

INCLUDES	        = -I$(ATERM)/include  \
                          -I$(TOOLBUSLIB)/include \
                          -I$(SDF_SUPPORT)/include
