# $Id$

include ${top_srcdir}/make_rules

EXTRA_DIST = sdf-modules.idef
pkgdata_DATA = sdf-modules.idef

bin_PROGRAMS = sdf-modules

sdf_modules_SOURCES = sdf-modules.c sdf-modules.tif.c \
	module-table.c \
	get-imports.c

sdf_modules_LDADD = -L$(top_builddir)/lib -lSDFME \
                 -L$(ATERM)/lib -lATerm \
                 -L$(TOOLBUSLIB)/lib -lATB \
                 $(SOCKLIBS)

noinst_HEADERS = sdf-modules.tif.h \
	module-table.h \
	get-imports.h

INCLUDES = -I$(top_srcdir)/lib \
	-I$(ATERM)/include  \
	-I$(TOOLBUSLIB)/include \
	-I$(SDF_SUPPORT)/include
