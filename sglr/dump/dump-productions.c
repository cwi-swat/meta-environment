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
