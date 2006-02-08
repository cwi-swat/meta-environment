# $Id$

# Alphabetical list of ToolBus scripts
TBSCRIPTS = \
	    idle-state.tb \
	    parsetable-utils.tb \
	    sdf-module-actions.tb \
	    sdf-actions.tb \
	    sdf-editor-actions.tb \
	    sdf-editor-utils.tb \
	    sdf-initialize.tb \
	    sdf-listeners.tb \
	    sdf-meta.tb \
	    sdf-namespace.h \
	    sdf-progress-listener.tb \
	    sdf-utils.tb \
	    term-actions.tb \
	    term-editor-actions.tb \
	    term-editor-utils.tb \
	    term-parsetable.tb \
	    term-utils.tb
  
GENERATED_TBSCRIPTS = \
		      sdf2-language.tb \
		      start-meta-studio.tb \
		      start-pt-dump.tb

EXTRA_DIST = \
	     $(TBSCRIPTS) \
	     $(GENERATED_TBSCRIPTS:.tb=.tb.src) \
	     standard.sdf.actions.src

CLEANFILES = \
	     $(GENERATED_TBSCRIPTS) \
	     standard.sdf.buttons

pkgdata_DATA = \
	       $(TBSCRIPTS) \
	       $(GENERATED_TBSCRIPTS) \
	       standard.sdf.actions

LIBRARY_LOCATION = \
		   ${ASF_LIBRARY}/share/asf-library/library

%.tb: %.tb.src Makefile
	sed 's@__SDF2TABLE__@$(PGEN)/share/pgen/Sdf2.baf@g; \
             s@__SDF_META__@$(prefix)/share/sdf-meta@g;' \
	    < $< > $@ 

standard.sdf.actions:  standard.sdf.actions.src Makefile
	sed 's@__ASF_LIBRARY__@${LIBRARY_LOCATION}@g;' < $< > $@

