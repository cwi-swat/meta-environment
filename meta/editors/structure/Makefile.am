# $Id$

SUBDIRS = src

include ${top_srcdir}/make_rules

AM_CFLAGS = -Wall -Werror -g -O2

CLEANFILES = \
	structure-editor.tifs

IDEF2TIF = $(TOOLBUS)/bin/idef2tif
TIFSTOC = $(TOOLBUS)/bin/tifstoc

INCLUDES = \
	-I$(TOOLBUSLIB)/include \
	-I$(ATERM)/include

EXTRA_DIST = \
	structure-editor.idef \
	structure-editor.tif.c \
	structure-editor.tif.h

pkgdata_DATA = structure-editor.idef

bin_PROGRAMS = structure-editor

noinst_HEADERS = structure-editor.tif.h

structure_editor_SOURCES = \
	structure-editor.c \
	structure-editor.tif.c

structure_editor_LDADD = \
	-L$(TOOLBUSLIB)/lib -lATB \
	-L$(ATERM)/lib -lATerm \
	$(SOCKLIBS)
