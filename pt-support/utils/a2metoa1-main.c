/*

    MEPT -- The ``Meta Environment Parse Tree'' Library 
    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, 
                        The Netherlands. 

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
/*  $Id$  */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <aterm2.h>

#include <MEPT-utils.h>
#include <conversion.h>

static char myname[] = "a2metoa1";
static char myversion[] = "0.0";

/*
 The argument vector: list of option letters, colons denote option
 arguments.  See Usage function, immediately below, for option
 explanation.
 */

static char myarguments[] = "bhi:o:tvV";

/*
 Usage: displays helpful usage information
 */
void usage(void)
{
  ATwarning("Usage: %s [%s]\n"
            "Options:\n"
            "\t-b              output terms in BAF format (default)\n"
            "\t-h              display help information (usage)\n"
            "\t-i filename     input from file (default stdin)\n"
            "\t-o filename     output to file (default stdout)\n"
            "\t-t              output terms in plaintext format\n"
            "\t-v              verbose mode\n"
            "\t-V              reveal program version (i.e. %s)\n",
            myname, myarguments, myversion);
}

void version(void)
{
  fprintf(stderr, "%s v%s\n", myname, myversion);
}


int main(int argc, char **argv)
{
  int c;
  ATerm bottomOfStack, translatedTerm = NULL;

  /*  Configuration items  */
  char   *input="-";
  char   *output="-";
  ATbool bafmode=ATtrue;
  ATbool verbose=ATfalse;
  ATbool proceed=ATtrue;

  extern char *optarg;
  extern int   optind;

  /*  Commandline mode  */

  while ((c = getopt(argc, argv, myarguments)) != -1) {
    switch (c) {
      case 'b':  bafmode = ATtrue;                       break;
      case 'i':  input=optarg;                           break;
      case 'o':  output=optarg;                          break;
      case 't':  bafmode = ATfalse;                      break;
      case 'v':  verbose = ATtrue;                       break;
      case 'V':  version(); proceed=ATfalse;             break;

      case 'h':
      default:   usage(); proceed=ATfalse;               break;
    }
  }
  argc -= optind;
  argv += optind;

  ATinit(argc, argv, &bottomOfStack);       /* Initialize Aterm library */
  PT_initMEPTApi();

  if(proceed) {
    ATerm term = ATreadFromNamedFile(input);
    translatedTerm = a2metoa1(PT_makeParseTreeFromTerm(term));
    if(!translatedTerm)
      ATerror("%s: conversion failed.", myname);
    if(bafmode)
      ATwriteToNamedBinaryFile(translatedTerm, output);
    else
      ATwriteToNamedTextFile(translatedTerm, output);
  }

  return 0;
}
