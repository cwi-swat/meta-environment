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

bin_PROGRAMS = parse-client

EXTRA_DIST   = parse-client.tb

SRCS         = parse-client.c
HDRS         = 

parse_client_SOURCES = $(SRCS) $(HDRS)

LDADD        = -L$(ATERMLIB) -lATerm -lAsFix -lATB $(SOCKLIBS)

# make sure generates files are removed during "make clean"
CLEANFILES   = parse-client.tif.c parse-client.tif.h


# extra dependency for parse-client.c to generate parse-client.tif.[ch]
${srcdir}/parse-client.c : parse-client.tif.h parse-client.tif.c
