/*
 $Id$
 */

#include "dump-skel.h"

void DumpOnePriority(FILE *out, parse_table *pt, int l)
{
    ATermList pr;

    if((pr = SG_LookupPriority(pt, SG_SETLABEL(l))))
        ATfprintf(out,"%d\t%t\n", l, pr);
}

void DumpAllPriorities(FILE *out, parse_table *pt)
{
    int l;

    for(l=SG_PROD_START; l < (SG_PROD_START + pt->numprods); l++)
        DumpOnePriority(out, pt, l);
}

void DoDump(parse_table *pt, int requested)
{
    if(requested >= 0)
        DumpOnePriority(stdout, pt, requested);
    else
        DumpAllPriorities(stdout, pt);
}
