# $Id$

include $(top_srcdir)/make_rules

bin_PROGRAMS      = editor-manager
data_DATA         = editor-manager.idef

EXTRA_DIST        = editor-manager.idef

CLEANFILES        = editor-manager.tifs editor-manager.tif.[ch]

editor_manager_SOURCES	= editor-manager.tif.c editor-manager.c
editor_manager_LDADD	= -L$(ATERM)/lib -lATerm \
			-L$(TOOLBUS)/lib -lATB \
			$(SOCKLIBS)

INCLUDES		= -I$(ATERM)/include -I$(TOOBLUS)/include \
			-DBINDIR=\"$(bindir)\"
