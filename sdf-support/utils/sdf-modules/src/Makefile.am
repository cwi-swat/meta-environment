# $Id$

include ${top_srcdir}/make_rules

EXTRA_DIST = sdf-modules.idef
pkgdata_DATA = sdf-modules.idef

bin_PROGRAMS = sdf-modules

sdf_modules_SOURCES = sdf-modules.c sdf-modules.tif.c \
	module-table.c \
	get-imports.c

sdf_modules_LDADD =\
                 -L$(ATERM)/lib -lATerm-dbg \
                 -L$(TOOLBUSLIB)/lib -lATB \
		 -L$(top_builddir)/lib -lSDFME -lmept \
                 $(SOCKLIBS)

noinst_HEADERS = sdf-modules.tif.h \
	module-table.h \
	get-imports.h

INCLUDES = \
	-I$(ATERM)/include  \
	-I$(TOOLBUSLIB)/include \
	-I$(SDF_SUPPORT)/include \
	-I$(top_srcdir)/lib 
