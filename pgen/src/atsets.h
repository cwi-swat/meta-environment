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

typedef struct
{
  int size;
	int nr_sets;

	ATermList *table;
} ATermSOS;

extern ATermList ATunionSetList(ATermList sets);
extern ATermList ATaddElement(ATermList l, ATerm elem);
extern ATermList ATunion(ATermList l1, ATermList l2);
extern ATermList ATunion1(ATermList l1, ATermList l2);
extern ATermList ATunion2(ATermList l1, ATermList l2);
extern ATermList ATunion3(ATermList l1, ATermList l2);
extern ATermList ATunion4(ATermList l1, ATermList l2);
extern ATermList ATunion5(ATermList l1, ATermList l2);
extern ATermList ATunion6(ATermList l1, ATermList l2);
extern ATermList ATunion7(ATermList l1, ATermList l2);
extern ATbool ATsetEqual(ATermList l1, ATermList l2);
extern ATermSOS *ATsosCreate(int initial_size);
extern void ATsosResize(ATermSOS *sos, int newsize);
extern ATermList ATsosInsert(ATermSOS *sos, ATermList set);
extern void ATsosDestroy(ATermSOS *sos);

#endif
