# $Id$

# Alphabetical list of ToolBus scripts
TBSCRIPTS = \
	    idle-state.tb \
	    parsetable-utils.tb \
	    sdf-module-actions.tb \
	    sdf-actions.tb \
	    sdf-editor-actions.tb \
	    sdf-editor-utils.tb \
	    sdf-listeners.tb \
	    sdf-meta.tb \
	    sdf-namespace.h \
	    sdf-utils.tb \
	    term-actions.tb \
	    term-editor-actions.tb \
	    term-editor-utils.tb \
	    term-parsetable.tb \
	    term-utils.tb
  
GENERATED_TBSCRIPTS = sdf2-language.tb

EXTRA_DIST = $(TBSCRIPTS) $(GENERATED_TBSCRIPTS:.tb=.tb.src)

CLEANFILES = $(GENERATED_TBSCRIPTS)

pkgdata_DATA = $(TBSCRIPTS) $(GENERATED_TBSCRIPTS)

%.tb: %.tb.src Makefile
	sed 's@__SDF2TABLE__@$(PGEN)/share/pgen/Sdf2.baf@g;' \
             < $< > $@ 
