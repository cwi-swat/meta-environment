#
#    ATerm -- The ATerm (Annotated Term) library
#    Copyright (C) 1998-2000  Stichting Mathematisch Centrum, Amsterdam, 
#                             The  Netherlands.
#
#    This program is free software; you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation; either version 2 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program; if not, write to the Free Software
#    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
#
# $Id$
#
# vim:ts=8:sw=8
include ../make_rules

TESTS	          = asfixtest-stub asource-test-1 asource-test-2

EXTRA_DIST        = Test.asfix asource-test-1.src asource-test-2.src \
                    Test.asfix1 Test.asfix2 Test.trm asfixtest-stub.src

CLEANFILES        = asource-test-1 asource-test-2 asfixtest-stub

INCLUDES          = -I../libasfix -I$(ATERMINC) 

LDLIBS 		  = -L../libasfix -lAsFix \
		    -L$(ATERMLIB) -lATB -lATerm 

noinst_PROGRAMS	  = asfixtest

asfixtest_SOURCES = asfixtest.c
asfixtest_LDADD   = $(LDLIBS) 

test: asfixtest
	./asfixtest

% : %.src Makefile
	sed 's@__TOP_BUILDDIR__@$(top_builddir)@g; \
             s@__SRCDIR__@$(srcdir)@g' \
	   < $< >$@ && \
	chmod +x $@