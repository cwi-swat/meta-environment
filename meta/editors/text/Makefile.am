# $Id$

SUBDIRS = common . gvim emacs xemacs

CFLAGS += -Werror

IDEF2TIF = $(TOOLBUS)/bin/idef2tif
TIFSTOC = $(TOOLBUS)/bin/tifstoc

INCLUDES = \
	-I$(top_srcdir)/editors/text/common \
	-I$(TOOLBUSLIB)/include \
	-I$(ATERM)/include

EXTRA_DIST = \
	editor-hive.idef \
	editor-hive.tif.c \
	editor-hive.tif.h

pkgdata_DATA = editor-hive.idef

bin_PROGRAMS = editor-hive

editor_hive_SOURCES = \
	editor-hive.c \
	editor-hive.tif.c

editor_hive_LDADD = \
	-L$(top_builddir)/editors/text/common -lTextEditor \
	-L$(TOOLBUSLIB)/lib -lATB \
	-L$(ATERM)/lib -lATerm \
	$(SOCKLIBS) -ldl

%.tifs: %.idef
	$(IDEF2TIF) $<

editor-hive.tif.c editor-hive.tif.h: editor-hive.tifs
	$(TIFSTOC) -tool editor-hive $<
