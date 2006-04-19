# $Id$

TBSCRIPTS = \
	    assert.tb \
	    attribute-changed-event.tb \
	    cache-utils.tb \
	    config-utils.tb \
	    dependencies-changed-event.tb \
	    editing.tb \
	    editor-error-display.tb \
	    error-output.tb \
	    error-utils.tb \
	    graph-utils.tb \
	    gui-actions.tb \
	    gui-utils.tb \
	    initialize-plugins.tb \
	    io-utils.tb \
	    meta.tb \
	    module-manager.tb \
	    module-selection-listener.tb \
	    module-utils.tb \
	    parse-utils.tb \
	    pretty-print-utils.tb \
	    serialization-utils.tb \
	    undefined.h
  
EXTRA_DIST = $(TBSCRIPTS)

pkgdata_DATA = $(TBSCRIPTS)

% : %.src Makefile
	sed "s@__HOME__@${HOME}@g;" < $< > $@
