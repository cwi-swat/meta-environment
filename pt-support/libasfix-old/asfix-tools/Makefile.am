#
#    AsFix -- The AsFix (ASF+SDF Prefix) library
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
# $Id$
#
include ../make_rules

bin_PROGRAMS     = afexpand asource

EXTRA_DIST       = asource.idef asource.tif.c asource.tif.h

afexpand_SOURCES = afexpand.c
afexpand_LDADD   = -L../libasfix -lAsFix \
                   -L$(ATERMLIB) -lATB -lATerm

asource_SOURCES  = asource.c 
asource_LDADD    = asource.tif.o \
                   -L../libasfix -lAsFix \
                   -L$(ATERMLIB) -lATB -lATerm

INCLUDES         = -I../libasfix -I$(ATERMINC)

asource.o : asource.tif.h
