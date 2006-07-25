# $Id$

include ${top_srcdir}/Makefile.meta

bin_PROGRAMS = structure-editor
lib_LIBRARIES = libStructureEditor.a
pkgdata_DATA = structure-editor.idef
noinst_HEADERS = \
	StructureEditor.h \
	StructureEditor_dict.h \
	structure-editor.tif.h \
	slice-tree.h

INCLUDES = \
	$(ERROR_SUPPORT_CFLAGS) \
	$(PT_SUPPORT_CFLAGS) \
	$(TOOLBUSLIB_CFLAGS) \
	$(ATERM_CFLAGS) 

structure_editor_SOURCES = \
	structure-editor.c \
	structure-editor.tif.c \
	slice-tree.c

structure_editor_LDADD = \
	-L$(top_builddir)/src -lStructureEditor \
	$(PT_SUPPORT_LIBS) \
	$(ERROR_SUPPORT_LIBS) \
	$(TOOLBUSLIB_LIBS) \
	$(ATERM_LIBS) 

libStructureEditor_a_SOURCES = \
	StructureEditor.c \
	StructureEditor_dict.c

EXTRA_DIST = structure-editor.idef.src

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@

CLEANFILES = structure-editor.tifs structure-editor.idef

if MAINTAINER_MODE

api: StructureEditor.sdf
	(echo definition; cat $<) > `basename $< .sdf`.def
	sdf2-to-adt \
		--imploded \
		--input `basename $< .sdf`.def \
		--output `basename $< .sdf`.adt
	adt-to-c \
		--input `basename $< .sdf`.adt \
		--prefix SE_ \
		--prologue StructureEditor.pro \
		--name StructureEditor

api-clean:
	rm -f StructureEditor.{adt,c,dict,h} StructureEditor_dict.*

endif
