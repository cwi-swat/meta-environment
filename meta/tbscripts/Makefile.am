# $Id$

TBSCRIPTS = \
	    assert.tb \
	    attribute-changed-event.tb \
	    cache-utils.tb \
	    config-utils.tb \
	    console-grabber.tb \
	    dependencies-changed-event.tb \
	    editing.tb \
	    editor-error-display.tb \
	    error-output.tb \
	    error-utils.tb \
	    graph-utils.tb \
	    gui-actions.tb \
	    gui-utils.tb \
	    graph-namespace.h \
	    io-utils.tb \
	    meta.tb \
	    meta-namespace.h \
	    module-manager.tb \
	    module-selection-listener.tb \
	    module-utils.tb \
	    navigator.tb \
	    parse-utils.tb \
	    parsetable-utils.tb \
	    pretty-print-utils.tb \
	    serialization-utils.tb \
	    text-utils.tb \
	    transaction-management.tb \
	    undefined.h
  
EXTRA_DIST = \
	$(TBSCRIPTS) \
	meta.actions

pkgdata_DATA = \
	$(TBSCRIPTS) \
	meta.actions

% : %.src Makefile
	sed "s@__HOME__@${HOME}@g;" < $< > $@
