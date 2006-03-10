# $Id$

include ${top_srcdir}/make_rules

EXTRA_DIST = sdf-renaming.idef.src

CLEANFILES = sdf-renaming.idef

pkgdata_DATA = sdf-renaming.idef

bin_PROGRAMS = sdf-renaming

if MAINTAINER_MODE
ATERM_LIB = ATerm-dbg
else
ATERM_LIB = ATerm
endif

sdf_renaming_SOURCES = sdf-renaming.c sdf-renaming.tif.c
sdf_renaming_LDADD = -L$(top_builddir)/lib -lSDFME -lSDF2PT \
		 -L$(PT_SUPPORT)/lib -lmept \
		 -L$(ERROR_SUPPORT)/lib -lErrorAPI \
                 -L$(ATERM)/lib -l$(ATERM_LIB) \
                 -L$(TOOLBUSLIB)/lib -lATB \
                 $(SOCKLIBS)

noinst_HEADERS		= sdf-renaming.tif.h

INCLUDES	        = -I$(top_srcdir)/lib \
                          -I$(ATERM)/include  \
                          -I$(TOOLBUSLIB)/include \
                          -I$(SDF_SUPPORT)/include \
                          -I$(ERROR_SUPPORT)/include \
                          -I$(PT_SUPPORT)/include

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@
