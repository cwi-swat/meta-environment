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

INCLUDES			= -I$(top_srcdir)/libsglr \
				-I$(ATERM)/include

bin_PROGRAMS			= dump-actions dump-gotos dump-priorities \
				dump-productions

dump_actions_SOURCES		= dump-actions.c dump-skel.c dump-skel.h

dump_gotos_SOURCES		= dump-gotos.c dump-skel.c dump-skel.h

dump_priorities_SOURCES		= dump-priorities.c dump-skel.c dump-skel.h

dump_productions_SOURCES	= dump-productions.c dump-skel.c dump-skel.h


LDADD     = -L$(top_srcdir)/libsglr -lsglr \
            -L$(top_srcdir)/libtree2dot -ltree2dot \
            -L$(PT_SUPPORT)/lib -lconversion -lmept -lasfix2 \
            -L$(ATERM)/lib -lATerm -lATB $(SOCKLIBS)

