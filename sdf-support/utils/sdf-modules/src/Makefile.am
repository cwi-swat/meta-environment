# $Id$

include $(top_srcdir)/Makefile.meta

bin_PROGRAMS = sdf-modules
pkgdata_DATA = sdf-modules.idef

noinst_HEADERS = sdf-imports.h module-table.h

INCLUDES = \
	-I$(top_srcdir)/lib  \
	$(SDF_SUPPORT_CFLAGS) \
	$(PT_SUPPORT_CFLAGS) \
	$(ERROR_SUPPORT_CFLAGS) \
	$(TOOLBUSLIB_CFLAGS) \
	$(ATERM_CFLAGS)

sdf_modules_SOURCES = \
		      main.c \
		      module-table.c \
		      sdf-imports.c \
		      sdf-modules.isrc

sdf_modules_LDADD = \
	-L$(top_builddir)/lib -lSDFME  \
	$(PT_SUPPORT_LIBS) \
	$(ERROR_SUPPORT_LIBS) \
	$(TOOLBUSLIB_LIBS) \
	$(ATERM_LIBS) 

