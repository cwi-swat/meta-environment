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
bin_PROGRAMS         = wish-adapter
pkgdata_DATA            = tb.tcl

EXTRA_DIST           = wish-adapter.guide.tex tb.tcl

wish_adapter_SOURCES = wish-adapter.c
wish_adapter_LDADD   = -L$(top_builddir)/libdeprecated-toolbus-adapter -ldeprecated-toolbus-adapter


WISH_DEFS            = -DWISH=\"$(WISH)\" \
                       -DTBTCL=\"$(pkgdatadir)/tb.tcl\" \
                       -DLIBDIR=\"$(pkgdatadir)\"

INCLUDES             = -I $(top_srcdir)/libdeprecated-toolbus-adapter $(WISH_DEFS)

