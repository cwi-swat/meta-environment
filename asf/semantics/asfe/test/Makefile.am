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

TESTS           = reduce-test prepare-restore-test  regress-test

EXTRA_DIST      = reduce-test.sh.src prepare-restore-test.sh.src \
                  reduce-test-1.tb reduce-test-2.tb regress-test.sh.src 

noinst_PROGRAMS = prepare-restore 

CLEANFILES                    = $(TESTS)

prepare_restore_SOURCES = \
                  prepare-restore.c

prepare_restore_LDADD = \
                  -L../src -leval \
                  -L$(PT_SUPPORT)/lib -lPT \
                  -L$(ATERM)/lib -lATB -lATerm $(SOCKLIBS) \
		  -L$(ASF_SUPPORT)/lib -lASF

prepare-restore.o: ../src/libeval.a

INCLUDES       = -I$(srcdir)/../src -I$(ASC)/include -I$(PT_SUPPORT)/include \
                 -I$(ATERM)/include -I$(ASF_SUPPORT)/include

% : %.sh.src Makefile
	sed 's@__TOOLBUS__@$(TOOLBUS)/bin/toolbus@g;\
	     s@__DATADIR__@$(datadir)@g;\
	     s@__ATERM__@$(ATERM)@g;\
	     s@__SRCDIR__@$(srcdir)@g' < $< > $@ && \
	chmod +x $@
