/*

    AsFix -- The AsFix (ASF+SDF Prefix) library
    Copyright (C) 1998-2000  Stichting Mathematisch Centrum, Amsterdam, 
                             The  Netherlands.

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

   $Id$
*/
#include <stdio.h>
#include <stdarg.h>
#include "AsFix-init-patterns.h"
#include "aterm2.h"
#include "AsFix.h"
#include "deprecated.h"
#include "aterm-macs.h"

extern ATerm pattern_asfix_module;
extern ATerm pattern_asfix_term;

void usage(char *prg, int err)
{
  FILE *f = stderr;

  ATfprintf(f, "usage: %s [input [output]]\n", prg);
  ATfprintf(f, "when input is not specified, stdin is used.\n");
  ATfprintf(f, "when output is not specified, stdout is used.\n");

  exit(err);
}

int main(int argc, char *argv[])
{
  ATerm tin, result = NULL;
  FILE *in = stdin, *out = stdout;
  ATerm bottomOfStack;

  if(argc == 2 && strcmp(argv[1], "-h") == 0) {
    usage(argv[0], 0);
  }

  if(argc > 3)
    usage(argv[0], 1);

  if(argc > 1)
    in = fopen(argv[1], "r");
  if(argc > 2)
    out = fopen(argv[2], "w");

  if(!in)
    ATerror("cannot open input file %s\n", argv[1]);
  if(!out)
    ATerror("cannot open output file %s", argv[2]);

  AFinit(argc, argv, &bottomOfStack);
 
  AFinitAsFixPatterns();

  tin = ATreadFromFile(stdin);
  if(ATmatchTerm(tin, pattern_asfix_module, 
                 NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)) {
    result = AFexpandModule(tin);
  } else if(ATmatchTerm(tin, pattern_asfix_term, 
                        NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)) {
    result = AFexpandTerm(tin);
  } else {
    ATerror("term is not an asfix term/module.\n");
  }

  ATwriteToTextFile(result, stdout);

  return 0;
}
