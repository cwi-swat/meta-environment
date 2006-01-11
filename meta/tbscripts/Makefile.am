# $Id$

# Alphabetical list of ToolBus scripts
TBSCRIPTS = \
  asf-actions.tb \
  asf-editor-actions.tb \
  asf-editor-utils.tb \
  asf-language.tb \
  asf-listeners.tb \
  asf-namespace.h \
  asf-utils.tb \
  assert.tb \
  attribute-changed-event.tb \
  cache-utils.tb \
  child-attribute-changed-event.tb \
  config-utils.tb \
  dependencies-changed-event.tb \
  editing.tb \
  editor-error-display.tb \
  graph-utils.tb \
  gui-actions.tb \
  gui-utils.tb \
  idle-state.tb \
  io-utils.tb \
  meta.tb \
  module-actions.tb \
  module-db.tb \
  module-manager.tb \
  module-selection-listener.tb \
  module-utils.tb \
  parsetable-utils.tb \
  parse-utils.tb \
  pretty-print-utils.tb \
  sdf-actions.tb \
  sdf-editor-actions.tb \
  sdf-editor-utils.tb \
  sdf-listeners.tb \
  sdf-namespace.h \
  sdf-utils.tb \
  serialization-utils.tb \
  start-meta-eqs-dumper.tb \
  start-meta-pt-dumper.tb \
  term-actions.tb \
  term-editor-actions.tb \
  term-editor-utils.tb \
  term-parsetable.tb \
  term-utils.tb
  
# Alphabetical list of Generated ToolBus scripts
GENERATED_TBSCRIPTS = \
  sdf2-language.tb \
  start-meta-studio.tb

EXTRA_DIST = $(TBSCRIPTS) $(GENERATED_TBSCRIPTS:.tb=.tb.src)

CLEANFILES = $(GENERATED_TBSCRIPTS)

pkgdata_DATA = $(TBSCRIPTS) $(GENERATED_TBSCRIPTS)

%.tb: %.tb.src Makefile
	sed 's@__SDF2TABLE__@$(PGEN)/share/pgen/Sdf2.baf@g;\
	     s@__EXTERNAL_JARS__@$(shell echo "$(EXTERNAL_JARS)")@g;\
	     s@__PKGDATA__@$(pkgdatadir)@g'\
	     < $< > $@ 
