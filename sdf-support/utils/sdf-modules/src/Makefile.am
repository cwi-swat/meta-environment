# $Id$

include $(top_srcdir)/Makefile.meta

pkgdata_DATA = sdf-modules.idef

bin_PROGRAMS = sdf-modules

sdf_modules_SOURCES = \
		      main.c \
		      sdf-modules.c \
		      module-table.c \
		      sdf-imports.c

sdf_modules_LDADD = \
	-L$(top_builddir)/lib -lSDFME  \
	$(TOOLBUSLIB_LIBS) \
	$(ERROR_SUPPORT_LIBS) \
	$(PT_SUPPORT_LIBS) \
	$(ATERM_LIBS) 

AM_CPPFLAGS += \
	-I$(top_srcdir)/lib  \
	$(ATERM_CFLAGS) \
	$(TOOLBUSLIB_CFLAGS) \
	$(PT_SUPPORT_CFLAGS) \
	$(ERROR_SUPPORT_CFLAGS) \
	$(SDF_SUPPORT_CFLAGS) 
