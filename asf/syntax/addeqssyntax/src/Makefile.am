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

INCLUDES         = -I$(ASC_SUPPORT)/include \
                   -I$(PT_SUPPORT)/include \
                   -I$(SDF_SUPPORT)/include \
                   -I$(ASF_SUPPORT)/include \
                   -I$(ATERM)/include

bin_PROGRAMS = addeqssyntax
man_MANS     = addeqssyntax.1

data_DATA    = addeqssyntax.idef

EXTRA_DIST   = addeqssyntax.idef addeqssyntax.tif.c addeqssyntax.tif.h \
	       addeqssyntax.pod

addeqssyntax_SOURCES = addeqssyntax.c
addeqssyntax_LDADD   = addeqssyntax.tif.o \
                       -L$(top_builddir)/addeqssyntax/c-source \
                       -lAdd-Eqs-Syntax \
                       -L$(ASC_SUPPORT)/lib -lasc-support \
                       -L$(SDF_SUPPORT)/lib -lSDF \
                       -L$(ASF_SUPPORT)/lib -lASF \
                       -L$(PT_SUPPORT)/lib -lPT \
                       -L$(ATERM)/lib -lATB -lATerm $(SOCKLIBS)


CLEANFILES = addeqssyntax.tifs addeqssyntax.1

addeqssyntax.o: addeqssyntax.tif.h $(top_builddir)/addeqssyntax/c-source/libAdd-Eqs-Syntax.a
