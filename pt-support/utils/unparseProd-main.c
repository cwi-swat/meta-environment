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

static char myname[] = "unparsePT";
static char myversion[] = "1.0";

/*
 The argument vector: list of option letters, colons denote option
 arguments.  See Usage function, immediately below, for option
 explanation.
 */

static char myarguments[] = "hi:o:vV";

/*
 Usage: displays helpful usage information
 */
void usage(void)
{
  ATwarning("Usage: %s [%s]\n"
            "Options:\n"
            "\t-h              display help information (usage)\n"
            "\t-i filename     input from file (default stdin)\n"
            "\t-o filename     output to file (default stdout)\n"
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
  ATerm bottomOfStack;

  /*  Configuration items  */
  char   *inputName = "-";
  char   *outputName = "-";
  FILE *outputFile = NULL; 
  ATbool verbose = ATfalse;
  ATbool proceed = ATtrue;

  extern char *optarg;
  extern int   optind;

  /*  Commandline mode  */

  while ((c = getopt(argc, argv, myarguments)) != -1) {
    switch (c) {
      case 'i':  inputName = optarg;             break;
      case 'o':  outputName = optarg;            break;
      case 'v':  verbose = ATtrue;               break;
      case 'V':  version(); proceed = ATfalse;   break;

      case 'h':
      default:   usage(); proceed = ATfalse;     break;
    }
  }
  argc -= optind;
  argv += optind;

  ATinit(argc, argv, &bottomOfStack);       /* Initialize Aterm library */
  PT_initMEPTApi();

  if (proceed) {
    ATerm term;

    if (!strcmp(outputName, "") || !strcmp(outputName, "-")) {
      outputFile = stdout;
    } 
    else if (!(outputFile = fopen(outputName, "w"))) {
      ATerror("%s: cannot open %s for writing\n", argv[0], outputName);
    }

    term = ATreadFromNamedFile(inputName);
    if (term == NULL) {
      ATerror("asource: parse error in input term.\n");
    }
    else {
      char *text = PT_yieldProduction(PT_makeProductionFromTerm(term));
      fprintf(outputFile, "%s", text);
      fclose(outputFile);
   }
  }

  return 0;
}
