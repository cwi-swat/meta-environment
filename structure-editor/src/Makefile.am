# $Id$

include $(top_srcdir)/Makefile.meta

pkgdata_DATA = structure-editor.idef

bin_PROGRAMS = structure-editor

noinst_HEADERS = \
	StructureEditor.h \
	StructureEditor_dict.h \
	slice-tree.h

AM_CPPFLAGS += \
	$(ERROR_SUPPORT_CFLAGS) \
	$(PT_SUPPORT_CFLAGS) \
	$(TOOLBUSLIB_CFLAGS) \
	$(ATERM_CFLAGS) 

structure_editor_SOURCES = \
	structure-editor.isrc \
	main.c \
	slice-tree.c \
	StructureEditor.c \
	StructureEditor_dict.c

structure_editor_LDADD = \
	$(PT_SUPPORT_LIBS) \
	$(ERROR_SUPPORT_LIBS) \
	$(TOOLBUSLIB_LIBS) \
	$(ATERM_LIBS) 

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
