/*
 $Id$
 */

#include <stdlib.h>

#include <atb-tool.h>
#include <AsFix.h>

#include "parser.h"
#include "sglr.h"

void DoDump(parse_table *pt, int requested);

int main (int argc, char **argv)
{
  ATerm       bottomOfStack;
  char        *ATlibArgv[] = {"", "-silent"};
  char        *err;
  char        *pt_name;
  parse_table *pt;
  int         requested = -1;

  ATinit(2, ATlibArgv, &bottomOfStack);     /* Initialize Aterm library */
  switch(argc) {
    case 1:
      pt_name = "-";
      break;
    case 3:
      requested = atoi(argv[2]);
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
  DoDump(pt, requested);
  return 0;
}
