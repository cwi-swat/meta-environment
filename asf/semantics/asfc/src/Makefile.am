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

bin_PROGRAMS     = asfc
data_DATA        = asfc.idef

EXTRA_DIST       = asfc.idef asfc.tif.h asfc.tif.c reshuffle.h

CLEANFILES       = asfc.tif.h asfc.tif.c asfc.tifs

asfc_SOURCES = asfc.c reshuffle.c sdf2pt.c 
asfc_LDADD   = asfc.tif.o \
                   -L../c-source  -lAsFix2C \
                   -L$(ASC_SUPPORT)/lib -lasc-support \
                   -L$(PT_SUPPORT)/lib -lPT -lAsFix \
                   -L$(SDF_SUPPORT)/lib -lSDF \
                   -L$(ASF_SUPPORT)/lib -lASF \
                   -L$(ATERM)/lib -lATB -lATerm $(SOCKLIBS)

INCLUDES         = -I$(ASC_SUPPORT)/include -I$(PT_SUPPORT)/include -I$(ATERM)/include

asfc.o : asfc.tif.h ../c-source/libAsFix2C.a
