#
#    SGLR - the Scannerless Generalized LR parser.
#    Copyright (C) 2001  Stichting Mathematisch Centrum, Amsterdam,
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

include $(top_srcdir)/make_rules

INCLUDES		= -I${top_srcdir}/libsglr \
			-I${top_srcdir}/libtree2dot \
			-I$(ATERM)/include

bin_PROGRAMS		= tree2dot
tree2dot_SOURCES	= tree2dot-main.c

tree2dot_LDADD		= -L${top_srcdir}/libtree2dot -ltree2dot \
			-L${top_srcdir}/libsglr -lsglr \
			-L$(PT_SUPPORT)/lib -lconversion -lmept -lasfix2 \
			-L$(ATERM)/lib -lATerm -lATB $(SOCKLIBS)
