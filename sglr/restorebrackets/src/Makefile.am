# $Id$

include ${top_srcdir}/make_rules

EXTRA_DIST		= restorebrackets.idef

INCLUDES		= -I$(top_srcdir)/libsglr \
			-I$(PT_SUPPORT)/include \
			-I$(TOOLBUSLIB)/include \
			-I$(SGLR)/include \
			-I$(ATERM)/include

pkgdata_DATA		= restorebrackets.idef

bin_PROGRAMS		= restorebrackets 

restorebrackets_SOURCES	= restorebrackets.tif.c restorebrackets.tif.h restorebrackets-main.c
restorebrackets_LDADD	= -L$(top_builddir)/libsglr -lsglr \
			-L$(PT_SUPPORT)/lib -lmept \
			-L$(TOOLBUSLIB)/lib -lATB \
			-L$(ATERM)/lib -lATerm \
			-L$(SGLR)/lib -lsglr \
			$(SOCKLIBS)
