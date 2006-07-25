# $Id$

include ${top_srcdir}/Makefile.meta

EXTRA_DIST		= restorebrackets.idef.src

CLEANFILES = restorebrackets.idef

INCLUDES		= -I$(top_srcdir)/libsglr \
			$(PT_SUPPORT_CFLAGS) \
			$(ERROR_SUPPORT_CFLAGS) \
			$(TOOLBUSLIB_CFLAGS) \
			$(SGLR_CFLAGS) \
			$(ATERM_CFLAGS) 

pkgdata_DATA		= restorebrackets.idef

bin_PROGRAMS		= restorebrackets 

restorebrackets_SOURCES	= restorebrackets.tif.c restorebrackets.tif.h restorebrackets-main.c

restorebrackets_LDADD	= -L$(top_builddir)/libsglr -lsglr \
			$(PT_SUPPORT_LIBS) \
			$(ERROR_SUPPORT_LIBS) \
			$(TOOLBUSLIB_LIBS) \
			$(ATERM_LIBS) 

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@

