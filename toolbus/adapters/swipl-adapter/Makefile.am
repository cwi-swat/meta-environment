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
bin_PROGRAMS = swipl-adapter  
bin_SCRIPTS  = tbswipl 

EXTRA_DIST   = swipl-adapter.guide.tex swipl.c.nw test.pl test.tb tbswipl 


swipl_SOURCES = swipl.c
swipl_LDADD   = $(SWIPL_LIBS) -L$(TOOLBUSLIB)/lib -ltb


SWIPL           = /home/olivierp/pl-2.7.8
ARCH            = sparc-solaris2.4

SWIPL_INCLUDES  = -I$(SWIPL)/include
SWIPL_LIBS      = -L$(SWIPL)/runtime/$(ARCH) -lpl -ldl \
                  -lelf -lreadline -ltermcap

INCLUDES     = $(SWIPL_INCLUDES) -I $(TOOLBUSLIB)/include


% %.tex : %.nw
	$(NOWEB) $<


