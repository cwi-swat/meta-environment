# $Id$

# Alphabetical list of ToolBus scripts
TBSCRIPTS = \
  module-db.tb \
  abort.tb \
  close-all.tb \
  compile-module.tb \
  dump-equations.tb \
  dump-parsetable.tb \
  editors.tb \
  file-creator.tb \
  get-parsetable.tb \
  meta.tb \
  module-utils.tb \
  notification.tb \
  open-modules.tb \
  parse-focusses.tb \
  parse-utils.tb \
  print-module.tb \
  process-eqs.tb \
  restore-term-brackets.tb \
  save-module.tb \
  set-parsetable.tb \
  start-meta-syntax-editor.tb \
  start-meta-equations-editor.tb \
  start-meta-term-editor.tb \
  start-meta-eqs-dumper.tb \
  start-meta-pt-dumper.tb \
  start-meta-studio.tb \
  dummy-display-graph.tb \
  status.tb \
  button-actions.tb
  
# Alphabetical list of Generated ToolBus scripts
GENERATED_TBSCRIPTS = \
  sdf2-language.tb

EXTRA_DIST = $(TBSCRIPTS) $(GENERATED_TBSCRIPTS:.tb=.tb.src)

CLEANFILES = $(GENERATED_TBSCRIPTS)

pkgdata_DATA = $(TBSCRIPTS) $(GENERATED_TBSCRIPTS)

%.tb: %.tb.src Makefile
	sed 's@__SDF2TABLE__@$(PGEN)/share/pgen/Sdf2.baf@g;\
	     s@__PKGDATA__@$(pkgdatadir)@g' < $< > $@ 
