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
bin_PROGRAMS        = gen-adapter bc-adapter

EXTRA_DIST          = gen-adapter.guide.tex

gen_adapter_SOURCES = gen-adapter.c
gen_adapter_LDADD   = -L$(TOOLBUSLIB)/lib -ltb

bc_adapter_SOURCES  = bc-adapter.c
bc_adapter_LDADD    = -L$(TOOLBUSLIB)/lib -ltb

INCLUDES            = -I$(TOOLBUSLIB)/include

