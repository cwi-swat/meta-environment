/*
 $Id$
 */

#include <stdlib.h>

#include <atb-tool.h>
#include <AsFix.h>

#include "parser.h"
#include "sglr.h"

void DumpProd(FILE *out, ATermTable prods, ATerm prod)
{
  ATerm     val;

  if(!prods)
    return;

  val = ATtableGet(prods, prod);
  if(ATgetType(val) != AT_INT)
    ATfprintf(out,"%t: %t\n", prod, val);
}

void DumpAllProds(ATermTable prods)
{
  FILE      *out;
  ATermList keys;

  if(!prods)
    return;

  if (NULL == (out = popen ("sort -n", "w")))
    out = stdout;

  for(keys = ATtableKeys(prods); keys && !ATisEmpty(keys);
      keys = ATgetNext(keys)) {
    DumpProd(out, prods, ATgetFirst(keys));
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
  if(ATmatch(SGopenLanguage("dump-prods", 0, pt_name, pt_name),
             "snd-value(open-language-failed(<str>,<str>))", &err, NULL)) {
    ATfprintf(stderr, "could not open %s as a parse table\n", err);
    return 1;
  }

  if((pt = SG_LookupParseTable(pt_name, ATtrue)) == NULL) {
    ATfprintf(stderr, "failed to find parse table for languate %s\n", pt_name);
    return 1;
  }
  if(requested)
    DumpProd(stdout, pt->productions, requested);
  else
    DumpAllProds(pt->productions);
  return 0;
}
