# $Id$

include ${top_srcdir}/make_rules

bin_PROGRAMS = structure-editor
lib_LIBRARIES = libStructureEditor.a
pkgdata_DATA = structure-editor.idef
noinst_HEADERS = \
	StructureEditor.h \
	StructureEditor_dict.h \
	structure-editor.tif.h \
	slice-tree.h

AM_CFLAGS = -Wall -Werror -g -O2

INCLUDES = \
	-I$(ERROR_SUPPORT)/include \
	-I$(PT_SUPPORT)/include \
	-I$(TOOLBUSLIB)/include \
	-I$(ATERM)/include

structure_editor_SOURCES = \
	structure-editor.c \
	structure-editor.tif.c \
	slice-tree.c

structure_editor_LDADD = \
	-L$(top_builddir)/src -lStructureEditor \
	-L$(PT_SUPPORT)/lib -lmept \
	-L$(ERROR_SUPPORT)/lib -lErrorAPI -lLocationAPI \
	-L$(TOOLBUSLIB)/lib -lATB \
	-L$(ATERM)/lib -lATerm \
	$(SOCKLIBS)

libStructureEditor_a_SOURCES = \
	StructureEditor.c \
	StructureEditor_dict.c

EXTRA_DIST = structure-editor.idef.src

%.idef: %.idef.src Makefile
	sed 's@__PREFIX__@${prefix}@g' < $< > $@

if MAINTAINER_MODE

CLEANFILES = structure-editor.tifs

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
