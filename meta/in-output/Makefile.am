# $Id$

include $(top_srcdir)/make_rules

bin_PROGRAMS		= in-output
pkgdata_DATA		= in-output.idef

EXTRA_DIST		= in-output.idef

noinst_HEADERS = in-output.tif.h
in_output_SOURCES	= in-output.tif.c in-output.c
in_output_LDADD		= -L$(ATERM)/lib -lATerm \
			-L$(TOOLBUSLIB)/lib -lATB \
			$(SOCKLIBS)

INCLUDES		= -I$(ATERM)/include -I$(TOOLBUSLIB)/include
