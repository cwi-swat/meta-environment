# $Id$

# Alphabetical list of ToolBus scripts
TBSCRIPTS = \
  button-actions.tb \
  close-all.tb \
  compile-module.tb \
  dump-equations.tb \
  dump-parsetable.tb \
  dump-sdf-definition.tb \
  editing.tb \
  feedback.tb \
  graph-utils.tb \
  get-parsetable.tb \
  meta.tb \
  module-db.tb \
  module-utils.tb \
  open-modules.tb \
  parse-focuses.tb \
  pretty-print.tb \
  print-module.tb \
  process-eqs.tb \
  restore-term-brackets.tb \
  save-module.tb \
  standalone-errorlist.tb \
  start-meta-eqs-dumper.tb \
  start-meta-equations-editor.tb \
  start-meta-pt-dumper.tb \
  start-meta-syntax-editor.tb \
  start-meta-term-editor.tb \
  status.tb \
  user-interface.tb
  
# Alphabetical list of Generated ToolBus scripts
GENERATED_TBSCRIPTS = \
  sdf2-language.tb \
  start-meta-studio.tb

EXTRA_DIST = $(TBSCRIPTS) $(GENERATED_TBSCRIPTS:.tb=.tb.src)

CLEANFILES = $(GENERATED_TBSCRIPTS)

pkgdata_DATA = $(TBSCRIPTS) $(GENERATED_TBSCRIPTS)

%.tb: %.tb.src Makefile
	sed 's@__SDF2TABLE__@$(PGEN)/share/pgen/Sdf2.baf@g;\
	     s@__PKGDATA__@$(pkgdatadir)@g'\
	     < $< > $@ 
