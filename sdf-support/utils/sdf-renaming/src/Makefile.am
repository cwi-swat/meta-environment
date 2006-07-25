# $Id$

include ${top_srcdir}/Makefile.meta

EXTRA_DIST = sdf-renaming.idef.src

CLEANFILES = sdf-renaming.idef

pkgdata_DATA = sdf-renaming.idef

bin_PROGRAMS = sdf-renaming

sdf_renaming_SOURCES = sdf-renaming.c sdf-renaming.tif.c
sdf_renaming_LDADD = -L$(top_builddir)/lib -lSDFME -lSDF2PT \
		 $(PT_SUPPORT_LIBS) \
		 $(ERROR_SUPPORT_LIBS) \
                 $(TOOLBUSLIB_LIBS) \
                 $(ATERM_LIBS) 

noinst_HEADERS		= sdf-renaming.tif.h

INCLUDES	        = -I$(top_srcdir)/lib \
                          $(ATERM_CFLAGS) \
                          $(TOOLBUSLIB_CFLAGS) \
                          $(SDF_SUPPORT_CFLAGS) \
                          $(ERROR_SUPPORT_CFLAGS) \
                          $(PT_SUPPORT_CFLAGS) 

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@
