# $Id$


include $(top_srcdir)/make_rules

bin_PROGRAMS      = configmanager

pkgdata_DATA         = configmanager.idef

EXTRA_DIST        = configmanager.idef


noinst_HEADERS = configmanager.tif.h
configmanager_SOURCES = configmanager.c configmanager.h configmanager.tif.c
configmanager_LDADD   = -L$(TOOLBUSLIB)/lib -lATB \
			-L$(ATERM)/lib -lATerm \
			$(SOCKLIBS)

INCLUDES		= -I$(ATERM)/include \
			-I$(TOOLBUSLIB)/include \
			-DBINDIR=\"$(bindir)\"

