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
TESTS           = TBmatch1 TermIO test-removesocket read test-annos $(OK_TESTS) $(ERROR_TESTS)

noinst_PROGRAMS = TBmatch1 TermIO

EXTRA_DIST      = bind.tb expr-errors.tb expr.tb garbage.tb if.tb msg.tb \
                  notes.tb scope.tb tc-errors.tb tc.tb types.tb \
                  expr-errors.tb.out scope.tb.out tc-errors.tb.out \
                  test-removesocket.src anno.tb test-annos.src read.src read.tb

OK_TESTS        = if-ok msg-ok notes-ok bind-ok expr-ok types-ok garbage-ok 

ERROR_TESTS     = expr-errors-fail tc-errors-fail scope-fail

CLEANFILES      = $(OK_TESTS) $(ERROR_TESTS) test-removesocket test-annos read

LDADD           = -L$(TOOLBUSLIB)/lib -ltb
INCLUDES        = -I$(TOOLBUSLIB)/include

%-ok : %.tb
	echo '#!/bin/sh'  > $@
	echo '$(top_builddir)/toolbus/toolbus -TB_PORT 9999 $< 2>/dev/null >/dev/null'  >> $@
	chmod +x $@

%-fail : %.tb
	echo '#!/bin/sh'  > $@
	echo 'trap "rm -f tmp" 0' >> $@
	echo '$(top_builddir)/toolbus/toolbus -TB_PORT 9999 $< 2>&1 >/dev/null \' >> $@
	echo "| sed 's/^[^,]*, //' > tmp" >> $@
	echo 'diff $<.out tmp' >> $@
	chmod +x $@

% : %.src Makefile
	sed 's@__TOP_BUILDDIR__@$(top_builddir)@g;\
             s@__SRCDIR__@$(srcdir)@g' <$< > $@
	chmod +x $@

