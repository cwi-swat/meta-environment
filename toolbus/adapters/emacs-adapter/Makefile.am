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
bin_PROGRAMS          = emacs-adapter

bin_SCRIPTS           = start-emacs

pkgdata_DATA             = tb.el

EXTRA_DIST            = start-emacs.src tb.el

CLEANFILES            = start-emacs

emacs_adapter_SOURCES = emacs-adapter.c
emacs_adapter_LDADD   = -L$(top_builddir)/libdeprecated-toolbus-adapter -ldeprecated-toolbus-adapter

AM_CPPFLAGS              = -I $(top_srcdir)/libdeprecated-toolbus-adapter

start-emacs : start-emacs.src Makefile
	sed 's#__DATADIR__#$(pkgdatadir)#g' < $< > $@

