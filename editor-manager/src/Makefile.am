# $Id$

include $(top_srcdir)/make_rules

bin_PROGRAMS = editor-manager
lib_LIBRARIES = libEditorManager.a
pkgdata_DATA = editor-manager.idef
noinst_HEADERS = \
	editor-manager.tif.h \
	EditorManager_dict.h \
	EditorManager.h

AM_CFLAGS = -g -O2 -Wall -Werror

INCLUDES = \
	-I$(ATERM)/include \
	-I$(TOOLBUSLIB)/include

editor_manager_SOURCES = \
	editor-manager.tif.c \
	editor-manager.c

editor_manager_LDADD = \
	-L$(top_builddir)/src -lEditorManager \
	-L$(TOOLBUSLIB)/lib -lATB \
	-L$(ATERM)/lib -lATerm \
	$(SOCKLIBS)

libEditorManager_a_SOURCES = \
	EditorManager.c \
	EditorManager_dict.c

EXTRA_DIST = editor-manager.idef.src

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@

if MAINTAINER_MODE

CLEANFILES = editor-manager.tifs editor-manager.idef

api: EditorManager.sdf
	(echo definition; cat $<) > `basename $< .sdf`.def
	sdf2-to-c \
		--imploded \
		--input `basename $< .sdf`.def \
		--prefix EM_

api-clean:
	rm -f EditorManager.{adt,c,dict,h} EditorManager_dict.*

endif
