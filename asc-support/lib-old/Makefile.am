#
#    Asf Sdf Compiler Runtime Library
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

lib_LIBRARIES            = libasc-support.a

include_HEADERS          = asc-support.h asc-apply.h asc-support2.h
EXTRA_DIST               = rewriter.tb rewriter.tif.c rewriter.tif.h

SRCS = asc-support.c asc-support.h asc-support2.h rewriter.c \
       asc-apply.c asc-apply.h
ALLSRCS = $(SRCS) rewriter.tif.c 

libasc_support_a_SOURCES = $(SRCS)
libasc_support_a_LIBADD  = rewriter.tif.o

# Default include directories
INCLUDES   = -I. -I$(ASF_SUPPORT)/include \
                 -I$(PT_SUPPORT)/include \
                 -I$(ATERM)/include

rewriter.o: rewriter.tif.h
