# $Id$

EXTRA_DIST  = $(wildcard *.src)

bin_SCRIPTS = meta-config

TBSCRIPTS = \
	    -I$(prefix)/share/meta \
	    -I$(TERM_STORE)/share/term-store \
	    -I$(EDITOR_MANAGER)/share/editor-manager \
	    -I$(EDITOR_PLUGIN)/share/editor-plugin \
	    -I$(STRUCTURE_EDITOR)/share/structure-editor \
	    -I$(ERROR_SUPPORT)/share/error-support \
	    -I$(ERROR_GUI)/share/error-gui \
	    -I$(GRAPH_SUPPORT)/share/graph-support \
	    -I$(DIALOG_GUI)/share/dialog-gui \
	    -I$(META_STUDIO)/share/meta-studio \
	    -I$(PROGRESS_GUI)/share/progress-gui \
	    -I$(MODULE_DETAILS_GUI)/share/module-details-gui \
	    -I$(IO_SUPPORT)/share/io-support \
	    -I$(MODULE_MANAGER)/share/module-manager \
	    -I$(NAVIGATOR_GUI)/share/navigator-gui \
	    -I$(SGLR)/share/sglr \
	    -I$(PT_SUPPORT)/share/pt-support \
	    -I$(ERROR_SUPPORT)/share/error-support \
	    -I$(PANDORA)/share/pandora \
	    -I$(TIDE)/share/tide \
	    -I$(TIDE_SUPPORT)/share/tide-support \
	    -I$(CONFIGURATION_MANAGER)/share/configuration-manager \
	    -I$(GRAPH_GUI)/share/graph-gui

CLEANFILES  = meta-config

% : %.sh.src Makefile
	sed 's@__PREFIX__@$(prefix)@g;\
	     s@__TBSCRIPTS__@$(TBSCRIPTS)@g;' < $< > $@ && chmod +x $@
