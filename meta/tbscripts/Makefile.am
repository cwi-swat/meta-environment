# $Id$

TBSCRIPTS     = clear-all.tb editor-creator.tb \
                edit-equations.tb edit-syntax.tb edit-term.tb \
                file-creator.tb meta.tb notification.tb \
                open-modules.tb process-eqs.tb parse-focusses.tb \
                save-module.tb \
                set-parsetable.tb get-parsetable.tb \
                ui.tb dump-equations.tb \
		dump-parsetable.tb \
                module-utils.tb print-module.tb compile-module.tb \
                pt-dumper.tb standalone-pt-dumper.tb \
                eqs-dumper.tb standalone-eqs-dumper.tb \
                standalone-status-display.tb gen.tb \
		restore-term-brackets.tb abort.tb

GEN_TBSCRIPTS = sdf2-language.tb help.tb

EXTRA_DIST    = $(TBSCRIPTS) $(GEN_TBSCRIPTS:.tb=.tb.src)

CLEANFILES    = sdf2-language.tb help.tb

pkgdata_DATA     = $(TBSCRIPTS) $(GEN_TBSCRIPTS)

%.tb : %.tb.src Makefile
	sed 's@__SDF2TABLE__@$(PGEN)/share/pgen/Sdf2.baf@g;\
	     s@__PKGDATA__@$(pkgdatadir)@g' < $< > $@ 
