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
INCLUDES		= -I${top_srcdir}/libtree2dot \
			-I$(ATERM)/include \
			-I$(PT_SUPPORT)/include

lib_LIBRARIES		= libsglr.a

include_HEADERS		= sglr.h

noinst_HEADERS		= forest.h mem-alloc.h parse-table.h parser.h \
			rsrc-usage.h sglr-strings.h sglr.h stack.h \
			multisets.h bitmap.h

libsglr_a_SOURCES	= sglr-interface.c forest.c parse-table.c parser.c \
			stack.c rsrc-usage.c stack-collect.c multisets.c \
			bitmap.c
