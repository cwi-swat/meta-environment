/*
 $Id$
 */

#include "dump-skel.h"

void DumpOneProduction(FILE *out, parse_table *pt, int l)
{
    production pr;

    if((pr = SG_LookupProduction(pt, SG_SETLABEL(l))))
        ATfprintf(out,"%d\t%t\n", l, pr);
}

void DumpAllProductions(FILE *out, parse_table *pt)
{
    int l;

    for(l=SG_PROD_START; l < (SG_PROD_START + pt->numprods); l++)
        DumpOneProduction(out, pt, l);
}

void DoDump(parse_table *pt, int requested)
{
    if(requested >= 0)
        DumpOneProduction(stdout, pt, requested);
    else
        DumpAllProductions(stdout, pt);
}
