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

bin_PROGRAMS      = asfe
noinst_LIBRARIES  = libeval.a

data_DATA         = asfe.idef

EXTRA_DIST        = asfe.idef

CLEANFILES        = asfe.tif.c asfe.tif.h asfe.tifs

libeval_a_SOURCES = asfe.c asfe.h asfix_utils.c asfix_utils.h \
                    preparation.c preparation.h eval-tide.c eval-tide.h \
                    traversals.c traversals.h memotable.h memotable.c
 
libeval_a_LIBADD  = asfe.tif.o

asfe_SOURCES = main.c
asfe_LDADD   = libeval.a \
                   -L$(ASC)/lib -lasc-support \
                   -L$(PT_SUPPORT)/lib -lAsFix \
                   -L$(ATERM)/lib -lATB -lATerm $(SOCKLIBS)

INCLUDES          = ${TIDE} \
                    -I$(ASC)/include \
                    -I$(PT_SUPPORT)/include -I$(ATERM)/include \
                    ${TIDEDEF} ${TRAVERSALSDEF} ${LAYOUTDEF}

asfe.o : asfe.tif.h
