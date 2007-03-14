# $Id$

EXTRA_DIST		= restorebrackets.idef

restorebrackets_CPPFLAGS = \
			-I$(top_srcdir)/src \
			-I$(top_srcdir)/src/utils \
			-I$(top_srcdir)/src/parseForest \
			-I$(top_srcdir)/src/parseTable \
			-I$(top_srcdir)/src/parser \
			$(PT_SUPPORT_CFLAGS) \
			$(ERROR_SUPPORT_CFLAGS) \
			$(CONFIG_SUPPORT_CFLAGS) \
			$(C_LIBRARY_CFLAGS) \
			$(TOOLBUSLIB_CFLAGS) \
			$(PTABLE_SUPPORT_CFLAGS) \
			$(ATERM_CFLAGS) 

pkgdata_DATA		= restorebrackets.idef

bin_PROGRAMS		= restorebrackets 

restorebrackets_SOURCES	= restorebrackets.tif.c restorebrackets.tif.h restorebrackets-main.c
restorebrackets_LDADD	= -L$(top_builddir)/src -lsglr \
			$(PT_SUPPORT_LIBS) \
			$(PTABLE_SUPPORT_LIBS) \
			$(CONFIG_SUPPORT_LIBS) \
			$(C_LIBRARY_LIBS) \
			$(ERROR_SUPPORT_LIBS) \
			$(TOOLBUSLIB_LIBS) \
			$(ATERM_LIBS)

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@

