/* $Id$ */

/*

    PGEN - the SDF2 parse table generator.
    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, The Netherlands. 

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/
#ifndef ATSETS_H
#define ATSETS_H

#include <aterm2.h>

typedef struct _ATermSOS *ATermSOS;

ATermList ATunion(ATermList l1, ATermList l2);
ATermList ATunionSetList(ATermList sets);
ATermList ATaddElement(ATermList l, ATerm elem);
ATbool ATsetEqual(ATermList l1, ATermList l2);
ATermSOS ATsosCreate(int initial_size);
void ATsosResize(ATermSOS sos, int newsize);
ATermList ATsosInsert(ATermSOS sos, ATermList set);
void ATsosDestroy(ATermSOS sos);

#endif
