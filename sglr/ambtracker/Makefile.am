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

include $(top_srcdir)/make_rules

bin_PROGRAMS     = ambtracker

SRCS             = ambtracker.c
HDRS             =

ambtracker_SOURCES = $(SRCS) $(HDRS)

LDADD            =  -L${SGLR}/libsglr -lsglr \
                    -L${SGLR}/libtree2dot -ltree2dot \
                    -L${TREE}/libasfix-old/libasfix -lAsFix \
                    -L$(ATERM)/lib -lATerm -lATB $(SOCKLIBS)

ambtracker.o: ${SGLR}/libsglr/libsglr.a
