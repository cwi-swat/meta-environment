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

noinst_DATA = ambi-test.tb

EXTRA_DIST  = toolbus-test.sh.src module-test.sh.src parser-test.sh.src \
              new-eqs-test.tb new-module-test-1.tb new-module-test-2.tb \
              new-module-test-3.tb open-eqs-test.tb open-sdf2-lang-test.tb \
              open-table-test-1.tb open-table-test-2.tb update-test-module.tb \
              Empty.sdf.baf Pico-Booleans.sdf.baf ambi-test.tb.src

CLEANFILES  = $(TESTS)

% : %.sh.src
	sed 's@__TOOLBUSBIN__@$(TOOLBUS)/bin@g;\
	     s@__DATADIR__@$(datadir)@g;\
	     s@__SGLR__@/$(SGLR)@g' < $< > $@ && \
	chmod +x $@

%.tb : %.tb.src
	sed 's@__DATADIR__@$(datadir)@g;' < $< > $@
