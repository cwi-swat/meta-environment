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
bin_PROGRAMS = tcltk-adapter
pkgdata_DATA    = tcltk.tcl tide.tcl
noinst_DATA  = adapters.ps


EXTRA_DIST   = tcltk-adapter.c.tex tcltk-adapter.guide.tex test.tcl.nw \
               tide.tcl.nw adapters.fig standalone.tcl tcltk.tcl tide.tcl \
               adapters.ps

tcltk_adapter_SOURCES = tcltk-adapter.c tcltk-tide.c tcltk-tide.h
tcltk_adapter_LDADD   = -L$(TCLTK)/lib -ltk8.0 -ltcl8.0 \
			-L${top_builddir}/aterm -lATB \
                        -L$(x_libraries) -lX11 -ldl \
                        -L$(ATERM)/lib -lATerm

CLEANFILES   = adapters.ps
TCLTK_DEFS   = -DLIBDIR=\"$(pkgdatadir)\"

INCLUDES     = -I$(TCLTK)/include -I$(ATERM)/include $(TCLTK_DEFS) \
               $(TIDEINC) $(TIDEDEF)


% %.tex : %.nw
	$(NOWEB) $<

adapters.ps: adapters.fig
	fig2dev -Lps adapters.fig adapters.ps

