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

#include <stdlib.h>

#include <atb-tool.h>

#include "parser.h"
#include "sglr.h"
#include "MEPT.h"

void DoDump(parse_table *pt, int requested, ATbool unparsed);

void usage(char *prg)
{
  fprintf(stderr, "usage: %s [-u] [parse-table [state]]\n", prg);
  fprintf(stderr, "\t-u:\tUnparse productions\n\n");
  fprintf(stderr, "note that no -at-xxx options can be used, "
          "except -at-help :-(\n");
  exit(0);
}

int main (int argc, char **argv)
{
  ATerm       bottomOfStack;
  char        *err;
  char        *pt_name = NULL;
  ATbool      unparsed = ATfalse;
  language    lang_name;
  parse_table *pt;
  int         requested = -1;
  int         lcv;

  for(lcv = 1; lcv < argc; lcv++) {
    if (!strcmp(argv[lcv],"-u")) {
      unparsed = ATtrue;
    }
    else if (!strcmp(argv[lcv],"-h")) {
      usage(argv[0]);
      exit(0);
    }
    else if (pt_name == NULL) {
      pt_name = argv[lcv];
    }
    else if (pt_name != NULL) {
      requested = atoi(argv[lcv]);
    }
  }

  ATinit(argc, argv, &bottomOfStack);     /* Initialize Aterm library */
  PT_initMEPTApi();

  lang_name = ATmake("<str>", pt_name);
  if(ATmatch(SGopenLanguage("dump", lang_name, pt_name),
             "snd-value(open-language-failed(<str>,<str>))", &err, NULL)) {
    ATfprintf(stderr, "could not open %s as a parse table\n", err);
    return 1;
  }

  if(!(pt = SG_LookupParseTable(lang_name))) {
    ATfprintf(stderr, "failed to find parse table for languate %s\n", pt_name);
    return 1;
  }
  DoDump(pt, requested, unparsed);
  return 0;
}
