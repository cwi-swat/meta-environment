# $Id$

# Alphabetical list of ToolBus scripts
TBSCRIPTS = \
	    sdf-module-actions.tb \
	    sdf-actions.tb \
	    sdf-editor-actions.tb \
	    sdf-editor-listeners.tb \
	    sdf-editor-utils.tb \
	    sdf-gui-listeners.tb \
	    sdf-listeners.tb \
	    sdf-meta.tb \
	    sdf-namespace.h \
	    sdf-progress-listener.tb \
	    sdf-transactions.tb \
	    sdf-utils.tb \
	    sdf-module-utils.tb \
	    term-actions.tb \
	    term-editor-actions.tb \
	    term-editor-utils.tb \
	    term-parsetable.tb \
	    term-utils.tb
  
GENERATED_TBSCRIPTS = \
		      sdf2-language.tb \
		      sdf-initialize.tb \
		      start-meta-studio.tb \
		      start-def-dump.tb \
		      start-pt-dump.tb

EXTRA_DIST = \
	     $(TBSCRIPTS) \
	     $(GENERATED_TBSCRIPTS:.tb=.tb.src) \
	     standard.sdf.actions.src

CLEANFILES = \
	     $(GENERATED_TBSCRIPTS) \
	     standard.sdf.actions

pkgdata_DATA = \
	       $(TBSCRIPTS) \
	       $(GENERATED_TBSCRIPTS) \
	       standard.sdf.actions

LIBRARY_LOCATION = ${SDF_LIBRARY_PREFIX}/share/sdf-library/library
LIBRARY_LOCATION2 = ${ASF_LIBRARY_PREFIX}/share/asf-library/library

%.tb: %.tb.src Makefile
	sed "s@__SDF2TABLE__@$(PGEN_PREFIX)/share/pgen/Sdf2.saf@g; \
             s@__SDF_META__@$(prefix)/share/sdf-meta@g;" \
	    < $< > $@ 

standard.sdf.actions:  standard.sdf.actions.src Makefile
	sed "s@__SDF_LIBRARY__@${LIBRARY_LOCATION}@g; \
	     s@__ASF_LIBRARY__@${LIBRARY_LOCATION2}@g;" < $< > $@
