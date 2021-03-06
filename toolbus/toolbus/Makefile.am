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
bin_PROGRAMS = toolbus ctif
bin_SCRIPTS = idef2tif

pkgdata_DATA = logger.tcl viewer.tcl

EXTRA_DIST = \
	txt_dbg.c \
	logger.tcl.src \
	viewer.tcl.src \
	script.l \
	script.y \
	idef2tif.src

toolbus_SOURCES = \
	calls.c \
	env.c \
	env.h \
	interpreter.c \
	interpreter.h \
	main.c \
	match.c \
	match.h \
	mkdtemp.c \
	mkdtemp.h \
	monitor.c \
	monitor.h \
	procs.c \
	script.h \
	server.c \
	tools.c \
	typecheck.c \
	typecheck.h \
	partners.c \
	partners.h

toolbus_LDADD = \
	lex.yy.o \
	y.tab.o \
	-L$(top_builddir)/libdeprecated-toolbus-adapter -ldeprecated-toolbus-adapter 

ctif_SOURCES = ctif.c
ctif_LDADD = -L$(top_builddir)/libdeprecated-toolbus-adapter -ldeprecated-toolbus-adapter

CLEANFILES = \
	lex.yy.c \
	y.tab.c \
	y.tab.h \
	logger.tcl \
	viewer.tcl \
	idef2tif

YFLAGS = -d

#DEBUG_DEFS = -DDBG_PROC_COMM

TOOLBUS_DEFS = \
	-DCPP='"$(CPP) $(CPPFLAGS)"' \
	-DVIEWER_TCL=\"$(pkgdatadir)/viewer.tcl\" \
	-DLOGGER_TCL=\"$(pkgdatadir)/logger.tcl\" \
	${DEBUG_DEFS}

INCLUDES = \
	-I$(top_srcdir)/libdeprecated-toolbus-adapter \
	-I$(srcdir) \
	-I. $(TOOLBUS_DEFS)

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
