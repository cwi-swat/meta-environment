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

SUBDIRS         = terms eqs ref fail

TESTS           = reduce-test prepare-restore-test \
                  equalModuloWhitespace-test whitespace-test regress-test

EXTRA_DIST      = reduce-test.sh.src prepare-restore-test.sh.src \
                  equalModuloWhitespace-test.sh.src whitespace-test.sh.src \
                  reduce-test-1.tb reduce-test-2.tb regress-test.sh.src 

noinst_PROGRAMS = prepare-restore equalModuloWhitespace whitespace

CLEANFILES                    = $(TESTS)

prepare_restore_SOURCES = \
                  prepare-restore.c

prepare_restore_LDADD = \
                  -L../src -leval \
                  -L$(ASFIXLIB) -lAsFix \
                  -L$(ATERMLIB) -lATB -lATerm $(SOCKLIBS)

equalModuloWhitespace_SOURCES = \
                  equalModuloWhitespace.c

equalModuloWhitespace_LDADD   = \
                 -L../src -leval \
                 -L$(ASFIXLIB) -lAsFix \
                 -L$(ATERMLIB) -lATB -lATerm $(SOCKLIBS)

whitespace_SOURCES = \
                 whitespace.c

prepare-restore.o: ../src/libeval.a
equalModuloWhitespace.o: ../src/libeval.a
whitespace.o: ../src/libeval.a

whitespace_LDADD   = \
                 -L../src -leval \
                 -L$(ASCLIB) -lasc-support \
                 -L$(ASFIXLIB) -lAsFix \
                 -L$(ATERMLIB) -lATB -lATerm $(SOCKLIBS)

INCLUDES       = -I$(srcdir)/../src -I$(ASCINC) -I$(ASFIXINC) -I$(ATERMINC)

% : %.sh.src Makefile
	sed 's@__TOOLBUS__@$(TOOLBUSBIN)/toolbus@g;\
	     s@__DATADIR__@$(datadir)@g;\
	     s@__SRCDIR__@$(srcdir)@g' < $< > $@ && \
	chmod +x $@
