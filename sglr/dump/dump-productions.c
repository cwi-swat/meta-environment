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
#include <MEPT-utils.h>

void DumpOneProduction(FILE *out, parse_table *pt, int l, ATbool unparsed)
{
  production pr;

  if((pr = SG_LookupProduction(pt, SG_SETLABEL(l)))) {
    if (unparsed) {
      ATfprintf(out,"%d\t%s\n", l, PT_yieldProduction((PT_Production) pr));
    }
    else {
      ATfprintf(out,"%d\t%t\n", l, pr);
    }
  }
}

void DumpAllProductions(FILE *out, parse_table *pt, ATbool unparsed)
{
  int l;

  for(l=SG_PROD_START; l < (SG_PROD_START + pt->numprods); l++) {
    DumpOneProduction(out, pt, l, unparsed);
  }
}

void DoDump(parse_table *pt, int requested, ATbool unparsed)
{
  if(requested >= 0) {
    DumpOneProduction(stdout, pt, requested, unparsed);
  }
  else {
    DumpAllProductions(stdout, pt, unparsed);
  }
}
