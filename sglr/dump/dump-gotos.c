/*

    SGLR - the Scannerless Generalized LR parser.
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
/*
 $Id$
 */

#include "dump-skel.h"

void DumpOneGoto(FILE *out, parse_table *pt, int s)
{
  state  target;
  int    l, nxt = 0;

  for(l = 0; l < (pt->numprods+SG_PROD_START); l++) {
    if((target = SG_LookupGoto(pt, SG_SETSTATE(s), SG_SETLABEL(l))) >= 0) {
      if(!nxt++)
        ATfprintf(out,"%d", s);
      ATfprintf(out,"\t%d\t%d\n", l, target);
    }
  }
}

void DumpAllGotos(FILE *out, parse_table *pt)
{
  int s;

  for(s=0; s<pt->numstates; s++)
    DumpOneGoto(out, pt, s);
}

void DoDump(parse_table *pt, int requested)
{
  if(requested >= 0)
    DumpOneGoto(stdout, pt, requested);
  else
    DumpAllGotos(stdout, pt);
}
