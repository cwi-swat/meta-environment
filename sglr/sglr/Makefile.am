#
#    SGLR - the Scannerless Generalized LR parser.
#    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, The Netherlands. 
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

include ../make_rules

bin_PROGRAMS      = sglr
data_DATA         = sglr.idef

EXTRA_DIST        = sglr.idef sglr.tif.c sglr.tif.h

SRCS              = sglr-main.c  getopt.c getopt1.c 
HDRS              = getopt.h

sglr_SOURCES      = $(SRCS) $(HDRS)
sglr_LDADD        = -L$(top_builddir)/libsglr -lsglr \
                    -L$(top_builddir)/libtree2dot -ltree2dot \
                    -L$(ASFIXLIB) -lAsFix \
                    -L$(ATERMLIB) -lATerm -lATB $(SOCKLIBS)

# sglr_prof_SOURCES = $(HDRS)
# sglr_prof_LDFLAGS = -pg
# sglr_prof_LDADD   = $(SRCS:.c=-prof.o) \
#                     -L$(top_builddir)/libsglr -lsglr-prof \
#                     -L$(top_builddir)/libtree2dot -ltree2dot-prof \
#                     -L$(top_builddir)/liba2toa1 -la2toa1-prof \
#                     -L$(ATERMLIB) -lATerm-prof -lAsFix-prof -lATB-prof \
#                     $(SOCKLIBS)


# remove built files during "make clean"
CLEANFILES = sglr.tifs

# extra dependency for sglr-main.c to generate sglr.tif.[ch]
sglr-main.o : sglr.tif.c sglr.tif.h
