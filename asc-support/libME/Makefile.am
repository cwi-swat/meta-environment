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

lib_LIBRARIES            = libasc-support-me.a

include_HEADERS          = asc-apply-me.h \
                           asc-support-me.h \
                           asc-support2-me.h 

noinst_HEADERS = muasf2pt.h \
                 prod2str.h

libasc_support_me_a_SOURCES = asc-apply.c \
                              asc-support.c \
                              nametable.c \
                              muasf2pt.c \
                              prod2str.c \
                              main.c

# Default include directories
INCLUDES   = -I. \
             -I$(PT_SUPPORT)/include \
             -I$(ATERM)/include
