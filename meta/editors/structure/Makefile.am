# $Id$

SUBDIRS = src

include ${top_srcdir}/make_rules

bin_PROGRAMS = structure-editor
lib_LIBRARIES = libStructureEditor.a
pkgdata_DATA = structure-editor.idef
noinst_HEADERS = structure-editor.tif.h

AM_CFLAGS = -Wall -Werror -g -O2

IDEF2TIF = $(TOOLBUS)/bin/idef2tif
TIFSTOC = $(TOOLBUS)/bin/tifstoc

INCLUDES = \
	-I$(TOOLBUSLIB)/include \
	-I$(ATERM)/include

LIBRARY_PATH = ../../../asf-library/library/basic
LOCATION_API = \
	$(LIBRARY_PATH)/Areas.sdf \
	$(LIBRARY_PATH)/Locations.sdf

structure_editor_SOURCES = \
	structure-editor.c \
	structure-editor.tif.c

structure_editor_LDADD = \
	-L$(top_builddir)/editors/structure -lStructureEditor \
	-L$(TOOLBUSLIB)/lib -lATB \
	-L$(ATERM)/lib -lATerm \
	$(SOCKLIBS)

libStructureEditor_a_SOURCES = \
	StructureEditor.c StructureEditor_dict.c

CLEANFILES = \
	structure-editor.tifs

EXTRA_DIST = \
	structure-editor.idef \
	structure-editor.tif.c \
	structure-editor.tif.h

# Developers
api: StructureEditor.sdf
	(echo definition; cat $(LOCATION_API) $<) \
	> `basename $< .sdf`.def
	sdf2-to-c --imploded --prefix SE_  \
		--input `basename $< .sdf`.def \
		--output `basename $< .sdf`

api-clean:
	rm -f StructureEditor.{adt,c,dict,h} StructureEditor_dict.*
