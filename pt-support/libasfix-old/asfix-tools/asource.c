/*

    AsFix -- The AsFix (ASF+SDF Prefix) library
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
/* $Id$
 *
 * asource -- generic source text reconstruction for AsFix terms
 * ToolBus version, based on command line version by
 * Paul Klint, 1996.
 *
 * Two ToolBus interface procedures:
 *
 * aterm *unparse_asfix(int cid, aterm *t)
 * takes an asfix term t and returns its string representation (its source):
 * snd-value(unparsed-text(<str>)
 *
 * void file_conssource(int cid, aterm *t, char *file)
 * writes the string representation of asfix term t to a file with filename
 * file
 *
 * <PO> Thu Mar  5 10:14:03 MET 1998
 *      Replaced asource code with call to AFsource in the asfix library.
 *      asource is now MUCH faster.
 *      asource can now also be used in standalone mode.
 *
 */

#include <stdlib.h>
#include <unistd.h>
#include <aterm2.h>
#include <AsFix.h>
#include <AsFix2src.h>

#ifdef WIN32
#include <string.h>
#include <fcntl.h>
#include <io.h>
#define streq(a,b) (!strcmp((a),(b)))
#else
#include <atb-tool.h>
#include "asource.tif.h"
#endif

static char *stout = NULL;
static int size = 0;

static ATbool run_verbose = ATfalse;

/* Commandline arguments */
static char myarguments[] = "hi:o:vV";

static char myname[] = "asource";
static char myversion[] = "0.1";

ATerm unparse_asfix(int cid, ATerm t)
{
  ATerm result;

  int needed = AFsourceSize(t)+1; /* including '\0' */
  if(needed > size) {
    if(stout)
      free(stout);
    if (!(stout = (char *)malloc(needed))) {
      ATerror("unparse_asfix: Not enough memory\n");
    }
    size = needed;
  }
  stout[0] = '\0';
  AFsource(t, stout);

  result = ATmake("snd-value(unparsed-text(<str>))", stout);

  return result;
}

void rec_terminate(int cid, ATerm t)
{
  if (run_verbose) {
    ATwarning("%s: exiting.\n", myname);
  }
  exit(0);
}

void usage(char *prg)
{
  ATwarning("Usage: %s [options]\n"
            "Options:\n"
            "\t-at-help        display ATermLibrary options\n"
            "\t-h              display help information (usage)\n"
            "\t-i filename     input from file (default stdin)\n"
            "\t-o filename     output to file (default stdout)\n"
            "\t-v              verbose mode\n"
            "\t-V              reveal program version (i.e. %s)\n",
            prg, myversion);
}

void version(const char *prg)
{
  ATwarning("%s v%s\n", prg, myversion);
}

int main(int argc, char **argv)
{
  int cid, c, toolbus_mode = 0;
  char *inputName = "-";
  char *outputName = "-";
  ATerm bottomOfStack, term;
  FILE *inputFile = NULL;
  FILE *outputFile = NULL;

  /* Check whether we're a ToolBus process */
  for (c=1; !toolbus_mode && c < argc; c++) {
    toolbus_mode = !strcmp(argv[c], "-TB_TOOL_NAME");
  }

  if (toolbus_mode) {
#ifndef WIN32 /* Code with Toolbus calls, non Windows */
    /* Initialize the ATerm library */
    ATBinit(argc, argv, &bottomOfStack);
    cid = ATBconnect(NULL, NULL, -1, asource_handler);
    ATBeventloop();
#else
    ATwarning("asource: Toolbus cannot be used in Windows.\n");
#endif
  } else {
    /* Initialize AsFix library */
    AFinit(argc, argv, &bottomOfStack);

    /* Handle commandline arguments */
    while ((c = getopt(argc, argv, myarguments)) != -1) {
      switch (c) {
        case 'v':  run_verbose = ATtrue;     break;
        case 'i':  inputName=optarg;         break;
        case 'o':  outputName=optarg;        break;
        case 'V':  version(myname); exit(0); break;

        case 'h':  usage(myname); exit(0);   break;
        default:   usage(myname); exit(1);   break;
      }
    }

#ifdef WIN32
    if( _setmode( _fileno( stdin ), _O_BINARY ) == -1 ) {
      perror( "Warning: Cannot set stdin to binary mode." );
    }
#endif

    if (!strcmp(inputName, "") || !strcmp(inputName, "-")) {
      inputFile = stdin;
    } else if (!(inputFile = fopen(inputName, "r"))) {
      ATerror("%s: cannot open %s for reading\n", argv[0], inputName);
    }

    if (!strcmp(outputName, "") || !strcmp(outputName, "-")) {
      outputFile = stdout;
    } else if (!(outputFile = fopen(outputName, "w"))) {
      ATerror("%s: cannot open %s for writing\n", argv[0], outputName);
    }

    term = ATreadFromFile(inputFile);
    if (term == NULL) {
      ATerror("asource: parse error in input term.\n");
    } else {
      AFsourceToFile(term, outputFile);
    }
  }
  return 0;
}
