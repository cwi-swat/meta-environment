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
include $(top_srcdir)/make_rules

INCLUDES+= -I$(top_srcdir)/libasfix-old/libasfix

GENERIC_LD_ADD =  -L$(top_builddir)/libasfix-old/libasfix -lAsFix \
              -L$(ATERM)/lib -lATB -lATerm

bin_PROGRAMS     = afexpand asource a2toa1

data_DATA        = asource.idef a2toa1.idef

man_MANS         = a2toa1.1

EXTRA_DIST       = asource.idef asource.tif.c asource.tif.h \
                   a2toa1.idef a2toa1.tif.c a2toa1.tif.h \
                   a2toa1.pod

CLEANFILES       = a2toa1.1

afexpand_SOURCES = afexpand.c
afexpand_LDADD   = $(GENERIC_LD_ADD)

asource_SOURCES  = asource.c 
asource_LDADD    = asource.tif.o $(GENERIC_LD_ADD)

a2toa1_SOURCES   = a2toa1-main.c

a2toa1_LDADD     = a2toa1.tif.o $(GENERIC_LD_ADD)


asource.o : asource.tif.h

a2toa1-main.o : a2toa1.tif.h
