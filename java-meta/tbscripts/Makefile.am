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
	    java-meta.tb \
	    java-namespace.h \
	    sdf-progress-listener.tb \
	    java-utils.tb
  
GENERATED_TBSCRIPTS = \
		      java-language.tb \
		      java-initialize.tb \
		      start-meta-studio.tb

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
