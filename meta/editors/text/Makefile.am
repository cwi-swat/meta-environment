# $Id$

if GVIM
bin_PROGRAMS		= gvim-editor
lib_LTLIBRARIES		= libmeta_gvim.la
GVIM_FILES	        = meta.vim

gvim_editor_SOURCES	= gvim-editor.c text-editor.tif.c
gvim_editor_LDADD	= -L$(TOOLBUSLIB)/lib -ltb -lATB \
			  -L$(ATERM)/lib -lATerm \
			  $(SOCKLIBS)

libmeta_gvim_la_SOURCES	= meta_gvim.c

meta.vim: meta.vim.src
	sed 's@__LIBDIR__@$(libdir)@g' < $< > $@
endif

EXTRA_DIST		= meta.el text-editor.idef \
			  meta.vim.src emacs-editor.src \
			  text-editor.tif.c text-editor.tif.h
CLEANFILES		= meta.vim emacs-editor

data_DATA		= text-editor.idef meta.el ${GVIM_FILES}
bin_SCRIPTS		= emacs-editor

INCLUDES		= -I$(TOOLBUSLIB)/include \
			  -I $(ATERM)/include \
			  -DLIBDIR="\"$(libdir)\"" \
			  -DDATADIR="\"$(datadir)\""

emacs-editor: emacs-editor.src
	sed 's@__DATADIR__@$(datadir)@g' < $< > $@ \
	&& chmod +x $@

