#    Meta-Environment - An environment for language prototyping.
#    Copyright (C) 2000  Stichting Mathematisch Centrum,
#                        Amsterdam, The Netherlands.
#
#    This program is free software; you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation; either version 2 of the License, or (at
#    your option) any later version.
#
#    This program is distributed in the hope that it will be useful, but
#    WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#    General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program; if not, write to the Free Software
#    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
#    USA
#
#
# $Id$

include $(top_srcdir)/make_rules

bin_PROGRAMS      = se
data_DATA         = se.idef

EXTRA_DIST        = se.idef \
				  Editor.h Editor_dict.h \
                  area.h editor.h focus.h path.h sort.h tree.h \
				  length.h

CLEANFILES        = se.tifs se.tif.c se.tif.h

	     

se_SOURCES = Editor.c Editor_dict.c se.c \
			 area.c editor.c focus.c path.c sort.c tree.c length.c

se_LDADD   = se.tif.o \
			-L$(PT_SUPPORT)/lib -lmept -L$(ATERM)/lib -lATB -lATerm $(SOCKLIBS)

INCLUDES          = -I$(PT_SUPPORT)/include -I$(ATERM)/include

se.o : se.tif.h
