# $Id$

EXTRA_DIST		= meta.el text-editor.idef \
			  meta.vim.src emacs-editor.src \
			  text-editor.tif.c text-editor.tif.h
CLEANFILES		= meta.vim emacs-editor

data_DATA		= text-editor.idef meta.el # meta.vim
bin_SCRIPTS		= emacs-editor
#bin_PROGRAMS		= gvim-editor
#lib_LTLIBRARIES		= libmeta_gvim.la

INCLUDES		= -I$(TOOLBUSLIB)/include \
			  -I $(ATERM)/include \
			  -DLIBDIR="\"$(libdir)\"" \
			  -DDATADIR="\"$(datadir)\""

#gvim_editor_SOURCES	= gvim-editor.c text-editor.tif.c
#gvim_editor_LDADD	= -L$(TOOLBUSLIB)/lib -ltb -lATB \
			  -L$(ATERM)/lib -lATerm \
			  $(SOCKLIBS)

#libmeta_gvim_la_SOURCES	= meta_gvim.c

emacs-editor: emacs-editor.src
	sed 's@__DATADIR__@$(datadir)@g' < $< > $@ \
	&& chmod +x $@

#meta.vim: meta.vim.src
#	sed 's@__LIBDIR__@$(libdir)@g' < $< > $@
