# $Id$

include ${top_srcdir}/make_rules

bin_PROGRAMS = structure-editor
lib_LIBRARIES = libStructureEditor.a
pkgdata_DATA = structure-editor.idef
noinst_HEADERS = \
	StructureEditor.h \
	StructureEditor_dict.h \
	structure-editor.tif.h

AM_CFLAGS = -Wall -Werror -g -O2

IDEF2TIF = $(TOOLBUS)/bin/idef2tif
TIFSTOC = $(TOOLBUS)/bin/tifstoc

INCLUDES = \
	-I$(ERROR_SUPPORT)/include \
	-I$(PT_SUPPORT)/include \
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
	-L$(PT_SUPPORT)/lib -lmept \
	-L$(ERROR_SUPPORT)/lib -lErrorAPI -lLocationAPI \
	-L$(TOOLBUSLIB)/lib -lATB \
	-L$(ATERM)/lib -lATerm \
	$(SOCKLIBS)

libStructureEditor_a_SOURCES = \
	StructureEditor.c \
	StructureEditor_dict.c

CLEANFILES = structure-editor.tifs

EXTRA_DIST = structure-editor.idef

# Developers
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
