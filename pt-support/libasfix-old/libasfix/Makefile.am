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

include ../make_rules

INCLUDES                 = -I$(ATERMINC)

# The following libraries are compiled to static libraries.
lib_LIBRARIES            = libAsFix.a @ASFIX_LIB_GCC@ @ASFIX_LIB_CC@ @ASFIX_LIB_DBG@ \
			   @ASFIX_LIB_PROF@ @ASFIX_LIB_CC64@ @ASFIX_LIB_SHARED@

EXTRA_LIBRARIES		= libAsFix-gcc.a libAsFix-cc.a libAsFix-dbg.a libAsFix-prof.a \
			libAsFix-cc64.a

ALLSRCS                  = abbrevs.c asfix.c asfix2src.c expand2asfix.c \
                           init-patterns.c posinfo.c AsFix-access.c

PUBLIC_INCL              = AsFix-abbrevs.h AsFix-init-patterns.h AsFix2sym.h \
		           AsFix-expand.h AsFix.h aterm-macs.h AsFix-fun.h \
		           AsFix2src.h AsFix-access.h

PRIVATE_INCL	         = 

ALLINCLUDES	         = ${PUBLIC_INCL} ${PRIVATE_INCL}

include_HEADERS          = $(PUBLIC_INCL)

EXTRA_DIST               = $(ALLSRCS)

# static only libraries
libAsFix_a_SOURCES	  =
libAsFix_cc_a_SOURCES     =
libAsFix_cc64_a_SOURCES   =
libAsFix_gcc_a_SOURCES    = 
libAsFix_dbg_a_SOURCES    =
libAsFix_prof_a_SOURCES   =

libAsFix_a_LIBADD	  = $(ALLSRCS:.c=.o)
libAsFix_cc_a_LIBADD      = $(ALLSRCS:.c=-cc.o)
libAsFix_cc64_a_LIBADD    = $(ALLSRCS:.c=-64.o)
libAsFix_gcc_a_LIBADD     = $(ALLSRCS:.c=-gcc.o)
libAsFix_dbg_a_LIBADD     = $(ALLSRCS:.c=-dbg.o)
libAsFix_prof_a_LIBADD    = $(ALLSRCS:.c=-prof.o)




