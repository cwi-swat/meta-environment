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
bin_PROGRAMS         = toolbus ctif
bin_SCRIPTS          = idef2tif

data_DATA            = logger.tcl viewer.tcl

EXTRA_DIST           = txt_dbg.c logger.tcl.src viewer.tcl.src \
                       script.l script.y idef2tif.src

toolbus_SOURCES      = calls.c env.c interpreter.c  main.c match.c \
                       monitor.c procs.c server.c tools.c typecheck.c env.h \
                       interpreter.h match.h monitor.h script.h typecheck.h
toolbus_LDADD        = lex.yy.o y.tab.o  -L$(TOOLBUSLIB)/lib -ltb

ctif_SOURCES         = ctif.c
ctif_LDADD           = -L$(TOOLBUSLIB)/lib -ltb

# txt_dbg_SOURCES    = txt_dbg.c
# txt_dbg_LDADD      = -L$(TOOLBUSLIB)/lib -ltb

CLEANFILES          += lex.yy.c y.tab.c y.tab.h idef2tif

YFLAGS               = -d

TOOLBUS_DEFS         = -DCPP='"$(CPP)"' \
                       -DVIEWER_TCL=\"$(datadir)/viewer.tcl\" \
                       -DLOGGER_TCL=\"$(datadir)/logger.tcl\"

INCLUDES            = -I$(TOOLBUSLIB)/include -I$(srcdir) -I. $(TOOLBUS_DEFS)

%.tcl : %.tcl.src
	sed 's#__WISH__#$(WISH)#g;' < $< > $@

y.tab.c y.tab.h: script.y
	$(YACC) $(AM_YFLAGS) $(YFLAGS) $<

lex.yy.c : script.l y.tab.h
	$(LEX) $(AM_LFLAGS) $(LFLAGS) $<

idef2tif : idef2tif.src Makefile
	sed 's#__PERL__#$(PERL)#g;s#__TOOLBUSBIN__#$(bindir)#g;' \
	   < $< > $@ && \
	chmod +x $@

