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

EXTRA_DIST      	= calc.tb ui-calc.tcl
CLEANFILES      	= *.tif.[ch] calc.tifs

INCLUDES		= -I$(TOOLBUSLIB)/include \
			-I$(ATERM)/include

noinst_PROGRAMS		= clock log calc batch

clock_SOURCES		= clock.tif.c clock.tif.h clock.c
clock_LDADD		= -L$(TOOLBUSLIB)/lib -lATB \
			-L$(ATERM)/lib -lATerm

log_SOURCES     	= log.tif.c log.tif.h log.c
log_LDADD       	= -L$(TOOLBUSLIB)/lib -lATB \
			-L$(ATERM)/lib -lATerm

calc_SOURCES		= calc.tif.c calc.tif.h calc.c
calc_LDADD		= -L$(TOOLBUSLIB)/lib -lATB \
			-L$(ATERM)/lib -lATerm

batch_SOURCES   	= batch.tif.c batch.tif.h batch.c
batch_LDADD     	= -L$(TOOLBUSLIB)/lib -lATB \
			-L$(ATERM)/lib -lATerm

%.tif.c %.tif.h: calc.tifs
	$(top_builddir)/aterm/tifstoc -tool $* $<

%.tifs: %.tb
	$(top_builddir)/toolbus/toolbus -gentifs $<
