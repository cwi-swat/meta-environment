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

bin_PROGRAMS      = evaluator
noinst_LIBRARIES  = libeval.a

data_DATA         = evaluator.idef

EXTRA_DIST        = evaluator.idef

CLEANFILES        = evaluator.tif.c evaluator.tif.h evaluator.tifs

libeval_a_SOURCES = evaluator.c evaluator.h asfix_utils.c asfix_utils.h \
                    preparation.c preparation.h eval-tide.c eval-tide.h \
                    traversals.c traversals.h memotable.h memotable.c
 
libeval_a_LIBADD  = evaluator.tif.o

evaluator_SOURCES = main.c
evaluator_LDADD   = libeval.a \
                   -L$(top_srcdir)/asc-support -lasc-support \
                   -L$(top_srcdir)/asfix/libasfix -lAsFix \
                   -L$(ATERMLIB) -lATB -lATerm $(SOCKLIBS)

INCLUDES          = ${TIDEINC} -I$(top_srcdir)/asc-support \
                    -I$(top_srcdir)/asfix/libasfix -I$(ATERMINC) \
                    ${TIDEDEF} ${TRAVERSALSDEF} ${LAYOUTDEF}

evaluator.o : evaluator.tif.h
