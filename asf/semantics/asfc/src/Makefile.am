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

SUBDIRS = muasf

bin_PROGRAMS     = asfc
data_DATA        = asfc.idef

EXTRA_DIST       = asfc.idef

asfc_SOURCES = asfc.c \
               chars.c \
               c-code.c \
               asf2muasf.c \
               lex-cons.c \
               asfc.tif.c \
               muasf2c.c

asfc_LDADD   = -L$(top_builddir)/asfc/c-source -lCompiler \
               -L$(ASC_SUPPORT)/lib -lasc-support-me \
               -L$(PT_SUPPORT)/lib -lmept  \
               -L$(SDF_SUPPORT)/lib -lSDFME \
               -L$(ASF_SUPPORT)/lib -lASFME \
               -L./muasf -lMuASF \
               -L$(ATERM)/lib -lATB -lATerm $(SOCKLIBS)

INCLUDES  = -I$(ASC_SUPPORT)/include \
            -I$(PT_SUPPORT)/include \
            -I$(ATERM)/include \
            -I$(srcdir)/muasf \
            -DOUTPUT_MUASF

