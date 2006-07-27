# $Id$

include $(top_srcdir)/Makefile.meta

bin_PROGRAMS = editor-manager
pkgdata_DATA = editor-manager.idef
noinst_HEADERS = \
	editor-manager.tif.h \
	EditorManager_dict.h \
	EditorManager.h

editor_manager_SOURCES = \
	editor-manager.tif.c \
	editor-manager.c \
	EditorManager.c \
	EditorManager_dict.c

editor_manager_LDADD = \
	$(TOOLBUSLIB_LIBS) \
	$(ATERM_LIBS) 

EXTRA_DIST = editor-manager.idef.src

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@

CLEANFILES += \
	     editor-manager.tifs \
	     editor-manager.idef

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
