# $Id$

data_DATA = text-editor.idef meta.el

bin_SCRIPTS = emacs-editor

EXTRA_DIST = \
	meta.el \
	emacs-editor.src \
	text-editor.idef \
	text-editor.tif.c \
	text-editor.tif.h

CLEANFILES = emacs-editor

emacs-editor: emacs-editor.src
	sed 's@__DATADIR__@$(datadir)@g' < $< > $@ \
	&& chmod +x $@

