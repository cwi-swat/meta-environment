/*
 $Id$
 */

#include <stdlib.h>

#include <atb-tool.h>
#include <AsFix.h>

#include "parser.h"
#include "sglr.h"

void DoDump(parse_table *pt, int requested);

void usage(char *prg)
{
    fprintf(stderr, "usage: %s [parse-table [state]]\n", prg);
    fprintf(stderr, "note that no -at-xxx options can be used, "
            "except -at-help :-(\n");
    exit(0);
}

int main (int argc, char **argv)
{
  ATerm       bottomOfStack;
  /*char        *ATlibArgv[] = {"", "-silent"};*/
  char        *err;
  char        *pt_name;
  parse_table *pt;
  int         requested = -1;

  if(argc == 2 && strcmp(argv[1], "-h") == 0) {
    usage(argv[0]);
  }

  ATinit(argc, argv, &bottomOfStack);     /* Initialize Aterm library */
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
