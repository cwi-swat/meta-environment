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

bin_PROGRAMS      = configmanager

data_DATA         = configmanager.idef

EXTRA_DIST        = configmanager.idef

CLEANFILES        = configmanager.tif.c configmanager.tif.h configmanager.tifs

configmanager_SOURCES = configmanager.c configmanager.h
configmanager_LDADD   = configmanager.tif.o \
			-L$(ASFIX)/lib -lAsFix \
			-L$(ATERM)/lib -lATB -lATerm $(SOCKLIBS)

INCLUDES          = -I$(ASC_SUPPORT)/include -I$(ASFIX)/include -I$(ATERM)/include \
			-DBINDIR=\"$(bindir)\"

configmanager.o : configmanager.tif.h
