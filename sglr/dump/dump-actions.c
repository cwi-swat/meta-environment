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

void DumpOneAction(FILE *out, parse_table *pt, int s)
{
  actions  val;
  int      c, nxt = 0;

  for(c = 0; c <= SG_CHAR_CLASS_EOF; c++) {
    if((val = SG_LookupAction(pt, SG_SETSTATE(s), c)) && !ATisEmpty(val)) {
      if(!nxt++)
        ATfprintf(out,"%d", s);
      ATfprintf(out,"\t%d\t%t\n", c, val);
    }
  }
}

void DumpAllActions(FILE *out, parse_table *pt)
{
  int s;

  for(s=0; s<pt->numstates; s++)
    DumpOneAction(out, pt, s);
}

void DoDump(parse_table *pt, int requested, ATbool unparsed)
{
  if(requested >= 0)
    DumpOneAction(stdout, pt, requested);
  else
    DumpAllActions(stdout, pt);
}
