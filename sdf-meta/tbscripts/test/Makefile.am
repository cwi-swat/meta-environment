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

TESTS       = toolbus-test module-test parser-test

TBSCRIPTS = new-module-test-1.tb.src \
            new-module-test-2.tb.src new-module-test-3.tb.src \
            open-sdf2-lang-test.tb.src open-table-test-1.tb.src \
            open-table-test-2.tb.src update-test-module.tb.src \
            ambi-test.tb.src

EXTRA_DIST  = toolbus-test.src module-test.src parser-test.src \
              Empty.sdf Empty.sdf.baf AmbiLanguage.baf ambi-test.tb.src \
              Pico-Booleans.sdf Pico-Booleans.sdf.baf \
              ${TBSCRIPTS}

noinst_SCRIPTS = ${TBSCRIPTS:.src=}

CLEANFILES  = $(TESTS) ${TBSCRIPTS:.src=}

% : %.src Makefile
	sed 's@__TOOLBUS__@$(TOOLBUS)@g;\
             s@__TOP_SRCDIR__@$(top_srcdir)@g; \
             s@__SRCDIR__@$(srcdir)@g; \
             s@__TOP_BUILDDIR__@$(top_builddir)@g; \
             s@__BUILDDIR__@$(top_builddir)/tbscripts/test@g; \
             s@__SGLR__@$(SGLR)@g; \
	     s@__DATADIR__@$(datadir)@g' < $< > $@ && \
	chmod +x $@
