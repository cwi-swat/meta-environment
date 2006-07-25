# $Id$

include ${top_srcdir}/Makefile.meta

EXTRA_DIST = sglr.idef.src

CLEANFILES = sglr.idef

INCLUDES = \
	-I$(top_srcdir)/libsglr \
	$(PT_SUPPORT_CFLAGS) \
	$(TOOLBUSLIB_CFLAGS) \
	$(ERROR_SUPPORT_CFLAGS) \
	$(ATERM_CFLAGS) 

pkgdata_DATA = sglr.idef
noinst_HEADERS = getopt.h sglr.tif.h

bin_PROGRAMS = sglr 

sglr_SOURCES = sglr.tif.c sglr-main.c getopt.c getopt1.c

sglr_LDADD = \
	-L$(top_builddir)/libsglr -lsglr \
	$(PT_SUPPORT_LIBS) \
	$(ERROR_SUPPORT_LIBS) \
	$(TOOLBUSLIB_LIBS) \
	$(ATERM_LIBS) 

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@
