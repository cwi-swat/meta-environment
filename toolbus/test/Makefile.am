#
#    ToolBus -- The ToolBus Application Architecture
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
TESTS           = TBmatch1 TermIO test-removesocket read test-annos dyncall \
		  concat rightchoice1 rightchoice2 $(OK_TESTS) $(ERROR_TESTS)\
	dyncall-param-passing \
	create-param-passing \
	boolean \
	boolean2 

noinst_PROGRAMS = TBmatch1 TermIO

EXTRA_DIST      = bind.tb expr-errors.tb expr.tb garbage.tb if.tb msg.tb \
                  notes.tb scope.tb tc-errors.tb tc.tb types.tb \
                  expr-errors.tb.ref scope.tb.ref tc-errors.tb.ref \
                  test-removesocket.src anno.tb test-annos.src read.src \
		  read.tb bug-481.tb bug-481.tb.ref dyncall.tb dyncall.src \
		  concat.tb concat.src rightchoice1.tb  rightchoice1.src \
		  rightchoice2.src \
		  rightchoice2.tb \
                  dyncall-param-passing.tb \
                  create-param-passing.tb \
                  boolean.tb \
                  boolean2.tb \
                  dyncall-param-passing.src \
                  create-param-passing.src \
                  boolean.src \
                  boolean2.src 

LDADD           = -L$(top_builddir)/libdeprecated-toolbus-adapter -ldeprecated-toolbus-adapter
AM_CPPFLAGS     = -I$(top_srcdir)/libdeprecated-toolbus-adapter

OK_TESTS = \
	if-ok \
	msg-ok \
	notes-ok \
	bind-ok \
	expr-ok \
	types-ok \
	garbage-ok  

ERROR_TESTS = \
	      expr-errors-fail \
	      tc-errors-fail \
	      scope-fail \
	      bug-481-fail

GENERATED_BY_TESTS = \
	fa \
	fb \
	fc \
	fd \
	fe \
	ff \
	fbin \
	test.ref \
	blobby  
	

CLEANFILES = \
	$(OK_TESTS) \
	$(ERROR_TESTS) \
	$(GENERATED_BY_TESTS) \
	test-removesocket \
	test-annos \
	concat \
	dyncall \
	rightchoice1 \
	rightchoice2 \
	read \
	dyncall-param-passing \
	create-param-passing \
	boolean \
	boolean2 


%-ok : %.tb
	echo '#!/bin/sh'  > $@
	echo '$(top_builddir)/toolbus/toolbus -TB_PORT 9999 $< 2>/dev/null >/dev/null'  >> $@
	chmod +x $@

%-fail : %.tb
	echo '#!/bin/sh'  > $@
	echo 'trap "rm -f tmp" 0' >> $@
	echo '$(top_builddir)/toolbus/toolbus -TB_PORT 9999 $< 2>&1 >/dev/null \' >> $@
	echo "| sed 's/^[^,]*, //' > tmp" >> $@
	echo 'diff $<.ref tmp' >> $@
	chmod +x $@

% : %.src Makefile
	sed "s@__TOP_BUILDDIR__@$(top_builddir)@g;\
             s@__SRCDIR__@$(srcdir)@g" <$< > $@
	chmod +x $@

