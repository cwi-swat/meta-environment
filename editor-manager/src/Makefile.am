# $Id$

include $(top_srcdir)/Makefile.meta

bin_PROGRAMS = editor-manager
pkgdata_DATA = editor-manager.idef
noinst_HEADERS = \
	EditorManager_dict.h \
	EditorManager.h

editor_manager_SOURCES = \
	editor-manager.isrc \
	main.c \
	EditorManager.c \
	EditorManager_dict.c

AM_CPPFLAGS += $(TOOLBUSLIB_CFLAGS)

editor_manager_LDADD = $(TOOLBUSLIB_LIBS) 

if MAINTAINER_MODE

api: EditorManager.sdf
	(echo definition; cat $<) > `basename $< .sdf`.def
	sdf2-to-c \
		--imploded \
		--input `basename $< .sdf`.def \
		--prefix EM_

api-clean:
	rm -f EditorManager.{adt,c,dict,h} EditorManager_dict.*

endif
