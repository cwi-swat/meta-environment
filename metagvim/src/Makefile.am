# $Id$

bin_PROGRAMS = gvim-editor
lib_LTLIBRARIES = libmeta_gvim.la
data_DATA = meta.vim

gvim_editor_SOURCES = gvim-editor.c text-editor.tif.c
gvim_editor_LDADD = \
	-L$(TOOLBUSLIB)/lib -lATB \
	-L$(ATERM)/lib -lATerm \
	$(SOCKLIBS)

libmeta_gvim_la_SOURCES	= meta_gvim.c

meta.vim: meta.vim.src
	sed 's@__LIBDIR__@$(libdir)@g' < $< > $@

EXTRA_DIST = \
	meta.vim.src \
	text-editor.tif.c \
	text-editor.tif.h

CLEANFILES = $(data_DATA)

INCLUDES = \
	-I$(TOOLBUSLIB)/include \
	-I$(ATERM)/include \
	-DLIBDIR="\"$(libdir)\"" \
	-DDATADIR="\"$(datadir)\""

# Only useful for upstream maintainer at CWI
DISTFILE = ${distdir}.tar.gz
WWWDIR = /hosts/www/projects/MetaEnv/unreleased

www-dist: distcheck
	install --mode=0664 --group=sen ${DISTFILE} ${WWWDIR}
	install --mode=0664 --group=sen ChangeLog \
		${WWWDIR}/metagvim.ChangeLog.txt
