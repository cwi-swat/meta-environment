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
#include "ksdf2table.h"

extern ATermTable state_nr_pairs;
extern ATermTable nr_state_pairs;

extern int nr_of_states;

extern ATermList ATunion(ATermList l1, ATermList l2);

/*{{{  ATerm update_states(ATermList vertex) */

ATerm update_states(ATermList vertex)
{
  ATerm nr;
	ATermList orig;

	orig = ATsosInsert(state_sos, vertex);
	
  nr = ATtableGet(state_nr_pairs, (ATerm)orig);
  if(!nr) {
    nr = (ATerm)ATmakeInt(nr_of_states);
/*
ATwarning("Stored %t with nr %t\n", vertex, nr);
*/
    ATtablePut(state_nr_pairs,(ATerm)orig,nr);
    ATtablePut(nr_state_pairs,nr,(ATerm)orig);
    nr_of_states++;
  }
  return nr;
}

/*}}}  */



