# $Id: Makefile.am 20376 2006-10-04 13:47:15Z jurgenv $

# Alphabetical list of ToolBus scripts
TBSCRIPTS = \
	    idle-state.tb \
	    parsetable-utils.tb \
	    java-module-actions.tb \
	    java-actions.tb \
	    java-editor-actions.tb \
	    java-editor-listeners.tb \
	    java-editor-utils.tb \
	    java-listeners.tb \
	    java-meta.tb \
	    java-namespace.h \
	    java-progress-listener.tb \
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
