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
