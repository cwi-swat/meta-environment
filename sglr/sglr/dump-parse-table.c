/*
 $Id$
 */

#include <stdlib.h>

#include <atb-tool.h>
#include <AsFix.h>

#include "parser.h"
#include "sglr.h"

void DumpOne(FILE *out, ATermTable tbl, ATerm key)
{
  ATerm     val;

  if(!tbl)
    return;

  if(!(val = ATtableGet(tbl, key)))
    return;

/*
  if(ATgetType(val) != AT_INT)
 */
    ATfprintf(out,"%t: %t\n", key, val);
}

void DumpAll(ATermTable tbl)
{
  FILE      *out;
  ATermList keys;

  if(!tbl)
    return;

  if (!(out = popen ("sort -n", "w")))
    out = stdout;

  for(keys = ATtableKeys(tbl); keys && !ATisEmpty(keys);
      keys = ATgetNext(keys)) {
    DumpOne(out, tbl, ATgetFirst(keys));
  }
  if(out != stdout)
    pclose(out);
}

int main (int argc, char **argv)
{
  ATerm bottomOfStack;
  char  *ATlibArgv[] = { "",
                         "-silent",   /* Choose sensible options here */
                         "-symboltable", "262144",
                         "-termtable", "20"
                        };
  char *err;
  char *pt_name;
  parse_table *pt;
  ATerm requested = NULL;

  ATinit(6, ATlibArgv, &bottomOfStack);     /* Initialize Aterm library */
  switch(argc) {
    case 1:
      pt_name = "-";
      break;
    case 3:
      requested = (ATerm) ATmakeInt(atoi(argv[2]));
    default:
      pt_name = argv[1];
      break;
  }
  if(ATmatch(SGopenLanguage("dump", 0, pt_name, pt_name),
             "snd-value(open-language-failed(<str>,<str>))", &err, NULL)) {
    ATfprintf(stderr, "could not open %s as a parse table\n", err);
    return 1;
  }

  if(!(pt = SG_LookupParseTable(pt_name, ATtrue))) {
    ATfprintf(stderr, "failed to find parse table for languate %s\n", pt_name);
    return 1;
  }
  if(requested)
    DumpOne(stdout, pt->PTPART, requested);
  else
    DumpAll(pt->PTPART);
  return 0;
}
