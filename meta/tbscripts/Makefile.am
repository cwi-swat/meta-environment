# $Id$

TBSCRIPTS     = clear-all.tb close-module.tb editor-creator.tb \
                edit-equations.tb edit-syntax.tb edit-term.tb \
                file-creator.tb meta.tb notification.tb \
                open-modules.tb process-eqs.tb parse-focusses.tb \
                revert-module.tb error-display.tb save-module.tb \
                set-parsetable.tb get-parsetable.tb status-display.tb \
                ui.tb asf-syntax.tb dump-equations.tb dump-parsetable.tb \
                rename-module.tb print-module.tb compile-module.tb \
                pt-dumper.tb standalone-pt-dumper.tb \
                eqs-dumper.tb standalone-eqs-dumper.tb \
                standalone-status-display.tb graph-browser.tb gen.tb

GEN_TBSCRIPTS = sdf2-language.tb help.tb

EXTRA_DIST    = $(TBSCRIPTS) $(GEN_TBSCRIPTS:.tb=.tb.src)

CLEANFILES    = sdf2-language.tb help.tb

data_DATA     = $(TBSCRIPTS) $(GEN_TBSCRIPTS)

%.tb : %.tb.src Makefile
	sed 's@__SDF2TABLE__@$(PGEN)/share/pgen/Sdf2.baf@g;\
	     s@__PKGDATA__@$(pkgdatadir)@g' < $< > $@ 
