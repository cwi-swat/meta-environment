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

void DoDump(parse_table *pt, int requested, ATbool unparsed)
{
  if(requested >= 0)
    DumpOneGoto(stdout, pt, requested);
  else
    DumpAllGotos(stdout, pt);
}
