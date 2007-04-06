# $Id$

include $(top_srcdir)/Makefile.meta

bin_PROGRAMS = sdf-renaming
pkgdata_DATA = sdf-renaming.idef

INCLUDES = \
  -I$(top_srcdir)/lib \
  $(SDF_SUPPORT_CFLAGS) \
  $(ERROR_SUPPORT_CFLAGS) \
  $(PT_SUPPORT_CFLAGS) \
  $(TOOLBUSLIB_CFLAGS) \
  $(ATERM_CFLAGS)

sdf_renaming_SOURCES = \
		       main.c \
		       sdf-renaming.isrc

sdf_renaming_LDADD = \
		 -L$(top_builddir)/lib -lSDFME -lSDF2PT \
		 $(ERROR_SUPPORT_LIBS) \
		 $(PT_SUPPORT_LIBS) \
                 $(TOOLBUSLIB_LIBS) \
                 $(ATERM_LIBS) 

