# $Id$

# Alphabetical list of ToolBus scripts
TBSCRIPTS = \
  abort.tb \
  clear-all.tb \
  compile-module.tb \
  dump-equations.tb \
  dump-parsetable.tb \
  edit-equations.tb \
  edit-syntax.tb \
  edit-term.tb \
  editor-creator.tb \
  eqs-dumper.tb \
  file-creator.tb \
  gen.tb \
  get-parsetable.tb \
  meta.tb \
  module-utils.tb \
  notification.tb \
  syntax-editor.tb \
  equations-editor.tb \
  term-editor.tb \
  open-modules.tb \
  parse-focusses.tb \
  parse-utils.tb \
  print-module.tb \
  process-eqs.tb \
  pt-dumper.tb \
  query.tb \
  restore-term-brackets.tb \
  save-module.tb \
  set-parsetable.tb \
  standalone-syntax-editor.tb \
  standalone-equations-editor.tb \
  standalone-term-editor.tb \
  standalone-eqs-dumper.tb \
  standalone-pt-dumper.tb \
  standalone-status-display.tb \
  ui.tb \
  button-actions.tb
  
# Alphabetical list of Generated ToolBus scripts
GENERATED_TBSCRIPTS = \
  help.tb \
  sdf2-language.tb

EXTRA_DIST = $(TBSCRIPTS) $(GENERATED_TBSCRIPTS:.tb=.tb.src)

CLEANFILES = $(GENERATED_TBSCRIPTS)

pkgdata_DATA = $(TBSCRIPTS) $(GENERATED_TBSCRIPTS)

%.tb: %.tb.src Makefile
	sed 's@__SDF2TABLE__@$(PGEN)/share/pgen/Sdf2.baf@g;\
	     s@__PKGDATA__@$(pkgdatadir)@g' < $< > $@ 
