# $Id$

include $(top_srcdir)/Makefile.meta

pkgdata_DATA = sdf-renaming.idef

bin_PROGRAMS = sdf-renaming

sdf_renaming_SOURCES = main.c sdf-renaming.c
sdf_renaming_LDADD = -L$(top_builddir)/lib -lSDFME -lSDF2PT \
		 $(PT_SUPPORT_LIBS) \
		 $(ERROR_SUPPORT_LIBS) \
                 $(TOOLBUSLIB_LIBS) \
                 $(ATERM_LIBS) 

AM_CPPFLAGS += \
  -I$(top_srcdir)/lib \
  $(ATERM_CFLAGS) \
  $(TOOLBUSLIB_CFLAGS) \
  $(SDF_SUPPORT_CFLAGS) \
  $(ERROR_SUPPORT_CFLAGS) \
  $(PT_SUPPORT_CFLAGS)

