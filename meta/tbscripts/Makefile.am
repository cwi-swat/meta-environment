#    Meta-Environment - An environment for language prototyping.
#    Copyright (C) 2000  Stichting Mathematisch Centrum,
#                        Amsterdam, The Netherlands.
#
#    This program is free software; you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation; either version 2 of the License, or (at
#    your option) any later version.
#
#    This program is distributed in the hope that it will be useful, but
#    WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#    General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program; if not, write to the Free Software
#    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
#    USA
#
#
# $Id$

SUBDIRS       = test

TBSCRIPTS     = clear-all.tb close-module.tb editor-creator.tb \
                edit-equations.tb edit-syntax.tb edit-term.tb \
                file-creator.tb meta.tb notification.tb \
                open-modules.tb process-eqs.tb parse-focusses.tb \
                revert-module.tb rewrite-errors.tb save-module.tb \
                set-parsetable.tb status-display.tb \
                ui.tb asf-syntax.tb dump-equations.tb \
                compile-module.tb

GEN_TBSCRIPTS = sdf2-language.tb help.tb

EXTRA_DIST    = $(TBSCRIPTS) $(GEN_TBSCRIPTS:.tb=.tb.src)

CLEANFILES    = sdf2-language.tb help.tb

data_DATA     = $(TBSCRIPTS) $(GEN_TBSCRIPTS)

%.tb : %.tb.src Makefile
	sed 's@__SDF2TABLE__@$(SDF)/share/sdf/Sdf2.baf@g;\
	     s@__PKGDATA__@$(pkgdatadir)@g' < $< > $@ 
