# $Id$

include ${top_srcdir}/make_rules

EXTRA_DIST = sdf-modules.idef.src

CLEANFILES = sdf-modules.idef

pkgdata_DATA = sdf-modules.idef

bin_PROGRAMS = sdf-modules

sdf_modules_SOURCES = sdf-modules.c sdf-modules.tif.c \
	module-table.c \
	sdf-imports.c

if MAINTAINER_MODE
ATERM_LIB = ATerm-dbg
else
ATERM_LIB = ATerm
endif

sdf_modules_LDADD = \
	-L$(top_builddir)/lib -lSDFME  \
	-L$(TOOLBUSLIB)/lib -lATB \
	-L$(ERROR_SUPPORT)/lib -lErrorAPI \
	-L$(PT_SUPPORT)/lib -lmept \
	-L$(ATERM)/lib -l$(ATERM_LIB) \
	$(SOCKLIBS)

noinst_HEADERS = \
	sdf-modules.tif.h \
	module-table.h \
	sdf-imports.h

INCLUDES = \
	-I$(top_srcdir)/lib  \
	-I$(ATERM)/include  \
	-I$(TOOLBUSLIB)/include \
	-I$(PT_SUPPORT)/include \
	-I$(ERROR_SUPPORT)/include \
	-I$(SDF_SUPPORT)/include

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@
