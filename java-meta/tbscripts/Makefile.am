# $Id: Makefile.am 20376 2006-10-04 13:47:15Z jurgenv $

# Alphabetical list of ToolBus scripts
TBSCRIPTS = \
	    idle-state.tb \
	    parsetable-utils.tb \
	    sdf-module-actions.tb \
	    sdf-actions.tb \
	    sdf-editor-actions.tb \
	    sdf-editor-listeners.tb \
	    sdf-editor-utils.tb \
	    sdf-listeners.tb \
	    sdf-meta.tb \
	    java-namespace.h \
	    sdf-progress-listener.tb \
	    sdf-utils.tb \
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
	     standard.java.actions

CLEANFILES = \
	     $(GENERATED_TBSCRIPTS)

pkgdata_DATA = \
	       $(TBSCRIPTS) \
	       $(GENERATED_TBSCRIPTS) \
	       standard.java.actions

%.tb: %.tb.src Makefile
	sed "s@__JAVATABLE__@/ufs/sen1/software/installed/java-source-analysis-0.1/linux/i386/share/java-source-analysis/grammar/Java.trm.tbl@g; \
             s@__JAVA_META__@$(prefix)/share/java-meta@g;" \
	    < $< > $@ 
