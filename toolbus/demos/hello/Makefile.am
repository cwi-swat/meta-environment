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

noinst_PROGRAMS		= hello hello-gen printer producer store

INCLUDES		= -I$(TOOLBUSLIB)/include \
			-I$(ATERM)/include

EXTRA_DIST		= hello1.tb hello2.tb hello3.tb hello.tcl hello.perl \
			hello.pl hello.pl.tb pipe.tb PC.tb producer.c store.c \
			hello.py hello2py.tb no-pl.sh hello2java.tb \
			Hello.java HelloTool.java

hello_SOURCES		= hello.c
hello_LDADD		= -L$(TOOLBUSLIB)/lib -lATB \
			-L$(ATERM)/lib -lATerm

hello_gen_SOURCES	= hello-gen.c hello.tif.c hello.tif.h
hello_gen_LDADD		= -L$(TOOLBUSLIB)/lib -lATB \
			-L$(ATERM)/lib -lATerm

printer_SOURCES		= printer.c
printer_LDADD		= -L$(TOOLBUSLIB)/lib -lATB \
			-L$(ATERM)/lib -lATerm

producer_SOURCES	= producer.c
producer_LDADD		= -L$(TOOLBUSLIB)/lib -lATB \
			-L$(ATERM)/lib -lATerm

store_SOURCES		= store.c
store_LDADD		= -L$(TOOLBUSLIB)/lib -lATB \
			-L$(ATERM)/lib -lATerm

%.tif.c %.tif.h: hello2.tifs
	$(top_builddir)/aterm/tifstoc -tool $* $<

%.tifs: %.tb
	${top_builddir}/toolbus/toolbus -gentifs $<
