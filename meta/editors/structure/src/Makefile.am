# $Id$

include $(top_srcdir)/make_rules

EXTRA_DIST = se.idef

bin_PROGRAMS = se
lib_LIBRARIES = libStructure.a
pkgdata_DATA = se.idef

noinst_HEADERS = \
	EditorData.h \
	EditorData_dict.h \
	area.h \
	editor.h \
	focus.h \
	length.h \
	path.h \
	se.tif.h \
	sort.h \
	tree.h

se_SOURCES = \
	se.tif.c \
	se.c \
	area.c \
	editor.c \
	focus.c \
	path.c \
	sort.c \
	tree.c \
	length.c

se_LDADD = \
	-L$(top_builddir)/editors/structure/src -lStructure \
	-L$(PT_SUPPORT)/lib -lmept \
	-L$(TOOLBUSLIB)/lib -lATB \
	-L$(ATERM)/lib -lATerm \
	$(SOCKLIBS)

INCLUDES = \
	-I$(PT_SUPPORT)/include \
	-I$(ATERM)/include \
	-I$(TOOLBUSLIB)/include

libStructure_a_SOURCES = \
	EditorData.c EditorData_dict.c

# Only useful for maintainers having 'apigen'
api: EditorData.adt
	upgrade-adt -i $< -o $<.1
	adt-to-c \
	--compat-term \
	--prefix SE_  \
	--prologue EditorData.pro  \
	--input $<.1
