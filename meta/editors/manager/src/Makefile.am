# $Id$

include $(top_srcdir)/make_rules

EXTRA_DIST		= editor-manager.idef

INCLUDES		= -I$(ATERM)/include \
			-I$(TOOLBUSLIB)/include \
			-DBINDIR=\"$(bindir)\"

bin_PROGRAMS		= editor-manager
pkgdata_DATA		= editor-manager.idef

noinst_HEADERS = editor-manager.tif.h
editor_manager_SOURCES	= editor-manager.tif.c editor-manager.c
editor_manager_LDADD	= -L$(ATERM)/lib -lATerm \
			-L$(TOOLBUSLIB)/lib -lATB \
			$(SOCKLIBS)
