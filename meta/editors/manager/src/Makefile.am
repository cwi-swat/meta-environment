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
# $Id$
#

include $(top_srcdir)/make_rules

bin_PROGRAMS      = editor-manager
data_DATA         = editor-manager.idef

EXTRA_DIST        = editor-manager.idef

CLEANFILES        = editor-manager.tifs editor-manager.tif.[ch]

editor_manager_SOURCES = editor-manager.c
editor_manager_LDADD   = editor-manager.tif.o \
                    -L$(ATERM)/lib -lATB -lATerm $(SOCKLIBS)

INCLUDES          = -I$(ATERM)/include -DBINDIR=\"$(bindir)\"

editor-manager.o: editor-manager.tif.h
