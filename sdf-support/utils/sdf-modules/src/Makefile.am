# $Id$

include ${top_srcdir}/Makefile.meta

EXTRA_DIST = sdf-modules.idef.src

CLEANFILES = sdf-modules.idef

pkgdata_DATA = sdf-modules.idef

bin_PROGRAMS = sdf-modules

sdf_modules_SOURCES = sdf-modules.c sdf-modules.tif.c \
	module-table.c \
	sdf-imports.c

sdf_modules_LDADD = \
	-L$(top_builddir)/lib -lSDFME  \
	$(TOOLBUSLIB_LIBS) \
	$(ERROR_SUPPORT_LIBS) \
	$(PT_SUPPORT_LIBS) \
	$(ATERM_LIBS) 

noinst_HEADERS = \
	sdf-modules.tif.h \
	module-table.h \
	sdf-imports.h

INCLUDES = \
	-I$(top_srcdir)/lib  \
	$(ATERM_CFLAGS) \
	$(TOOLBUSLIB_CFLAGS) \
	$(PT_SUPPORT_CFLAGS) \
	$(ERROR_SUPPORT_CFLAGS) \
	$(SDF_SUPPORT_CFLAGS) 

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@
