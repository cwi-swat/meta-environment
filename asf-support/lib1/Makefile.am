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

lib_LIBRARIES    = libASF.a
include_HEADERS  = ASF.h ASF_dict.h ASF-utils.h
libASF_a_SOURCES = ASF.c ASF_dict.c ASF-utils.c

bin_PROGRAMS = subst-eqs

INCLUDES = -I${ATERM}/include
LDFLAGS  = -L${ATERM}/lib
LDADD    = -lATerm

EXTRA_DIST = ASF.adt

# Developers only, put location of ADT-support here:
ADT      = ${ATERM}

subst_eqs_SOURCES = subst-eqs.c
subst_eqs_LDADD   = -L${ATERM}/lib -lATerm -L${ADT}/lib -lADT

api: ASF.raw

ASF.raw: Asf.label.def 
	sdf2-to-adt -r -i $< -o ASF.raw

ASF.adt: ASF.raw subst-eqs
	subst-eqs ASF.raw > ASF.adt

ASF.c: ASF.adt
	adt-to-c -i ASF.adt --prologue ASF.pro --prefix ASF_ -o ASF


%INTERMEDIATE: ASF.raw
