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

bin_PROGRAMS     = compiler
data_DATA        = compiler.idef

EXTRA_DIST       = compiler.idef compiler.tif.h compiler.tif.c

CLEANFILES       = compiler.tif.h compiler.tif.c compiler.tifs

compiler_SOURCES = compiler.c
compiler_LDADD   = compiler.tif.o \
                   -L../c-source  -lAsFix2C \
                   -L$(ASC_SUPPORT)/lib -lasc-support \
                   -L$(ASFIX)/lib -lAsFix \
                   -L$(ATERM)/lib -lATB -lATerm $(SOCKLIBS)

INCLUDES         = -I$(ASC_SUPPORT)/include -I$(ASFIX)/include -I$(ATERM)/include

compiler.o : compiler.tif.h ../c-source/libAsFix2C.a
