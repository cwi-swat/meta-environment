#
#    PGEN - the SDF2 parse table generator.
#    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, 
#                        The Netherlands. 
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
# $Id$

include ${top_srcdir}/make_rules

bin_PROGRAMS = traversals
man_MANS     = traversals.1
data_DATA    = traversals.idef

EXTRA_DIST   = traversals.idef traversals.tif.c traversals.tif.h \
               traversals.pod

traversals_SOURCES = traversals.c
traversals_LDADD   = traversals.tif.o \
                       -L$(top_builddir)/traversals/c-source -lTraversals \
                       -L$(ASCLIB) -lasc-support \
                       -L$(ASFIXLIB) -lAsFix \
                       -L$(ATERMLIB) -lATB -lATerm $(SOCKLIBS)


CLEANFILES = traversals.tifs traversals.1

traversals.o : traversals.tif.h
