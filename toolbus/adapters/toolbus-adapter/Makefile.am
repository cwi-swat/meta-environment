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

EXTRA_DIST		= hello.tb spawn-hello.tb
CLEANFILES		= toolbus-adapter.tif.[ch]

bin_PROGRAMS        	= toolbus-adapter
include_HEADERS		= toolbus-adapter.tbi

INCLUDES            	= -DTBPROG="\"${prefix}/bin/toolbus\"" \
			-I$(TOOLBUSLIB)/include \
			-I${top_srcdir}/aterm \
			-I$(ATERM)/include 

toolbus_adapter_SOURCES = toolbus-adapter.tif.c toolbus-adapter.tif.h \
			toolbus-adapter.c

toolbus_adapter_LDADD   = -L$(TOOLBUSLIB)/lib -ltb \
			-L${top_builddir}/aterm -lATB \
			-L$(ATERM)/lib -lATerm

%.tif.c %.tif.h: %.tifs
	$(top_builddir)/aterm/tifstoc -tool $* $<

%.tb: %.tbi
	cp $< $@
	echo "process DUMMY is delta" >> $@
	echo "toolbus(DUMMY)" >> $@
	
%.tifs: %.tb
	${top_builddir}/toolbus/toolbus -gentifs $<
