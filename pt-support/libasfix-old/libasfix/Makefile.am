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

INCLUDES                 = -I$(ATERM)/include

# The following libraries are compiled to static libraries.
lib_LIBRARIES            = libAsFix.a 

SRCS                     = abbrevs.c asfix.c asfix2src.c expand2asfix.c \
                           init-patterns.c posinfo.c AsFix-access.c a2toa1.c \
                           buffer.c

HDRS                     = AsFix-abbrevs.h AsFix-init-patterns.h AsFix2sym.h \
		           AsFix-expand.h AsFix.h aterm-macs.h AsFix-fun.h \
		           AsFix2src.h AsFix-access.h a2toa1.h buffer.h

libAsFix_a_SOURCES        = $(SRCS) $(HDRS)
