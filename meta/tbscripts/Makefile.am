# $Id$

# Alphabetical list of ToolBus scripts
TBSCRIPTS = \
  assert.tb \
  asf-namespace.h \
  attribute-changed-event.tb \
  caching.tb \
  child-attribute-changed-event.tb \
  close-all.tb \
  compile-module.tb \
  dependencies-changed-event.tb \
  dump-equations.tb \
  dump-parsetable.tb \
  dump-sdf-definition.tb \
  editing.tb \
  feedback.tb \
  graph-utils.tb \
  get-parsetable.tb \
  equations-parsetable.tb \
  term-parsetable.tb \
  idle-state.tb \
  meta.tb \
  module-actions.tb \
  module-db.tb \
  module-manager.tb \
  module-utils.tb \
  module-selection-listener.tb \
  open-modules.tb \
  parse-focuses.tb \
  parse-actions.tb \
  pretty-print.tb \
  print-module.tb \
  process-eqs.tb \
  restore-term-brackets.tb \
  save-module.tb \
  sdf-modules.tb \
  sdf-namespace.h \
  standalone-errorlist.tb \
  start-meta-eqs-dumper.tb \
  start-meta-equations-editor.tb \
  start-meta-pt-dumper.tb \
  start-meta-syntax-editor.tb \
  start-meta-term-editor.tb \
  status.tb \
  status-to-progress.tb \
  user-interface.tb \
  sdf-editor-actions.tb \
  asf-editor-actions.tb \
  asfsdf-module-actions.tb \
  gui-actions.tb \
  term-actions.tb \
  term-editor-actions.tb
  
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
