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

INCLUDES         = -I$(ASCINC) -I$(ASFIXINC) -I$(ATERMINC)

bin_PROGRAMS = removevarsyntax
man_MANS     = removevarsyntax.1

EXTRA_DIST   = removevarsyntax.idef removevarsyntax.tif.c removevarsyntax.tif.h \
               removevarsyntax.pod

removevarsyntax_SOURCES = removevarsyntax.c
removevarsyntax_LDADD   = removevarsyntax.tif.o \
                       -L$(top_builddir)/asf-syntax/removevars/c-source -lRemove-Var-Syntax \
                       -L$(ASCLIB) -lasc-support \
                       -L$(ASFIXLIB) -lAsFix \
                       -L$(ATERMLIB) -lATB -lATerm $(SOCKLIBS)


CLEANFILES = removevarsyntax.tifs removevarsyntax.1

removevarsyntax.o : removevarsyntax.tif.h
