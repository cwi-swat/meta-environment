# $Id$

include $(top_srcdir)/make_rules

EXTRA_DIST		= editor-manager.idef

INCLUDES		= -I$(ATERM)/include \
			-I$(TOOLBUSLIB)/include \
			-DBINDIR=\"$(bindir)\"

bin_PROGRAMS		= editor-manager
data_DATA		= editor-manager.idef

CLEANFILES		= editor-manager.tifs editor-manager.tif.[ch]

editor_manager_SOURCES	= editor-manager.tif.c editor-manager.c
editor_manager_LDADD	= -L$(ATERM)/lib -lATerm \
			-L$(TOOLBUSLIB)/lib -lATB \
			$(SOCKLIBS)
