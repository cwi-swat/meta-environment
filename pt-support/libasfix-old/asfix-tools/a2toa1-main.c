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
/*  $Id$  */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <aterm2.h>
#include <AsFix.h>

#include "a2toa1.h"

#ifndef WIN32  /*  Not available for DOS  */
#include <atb-tool.h>
#include "a2toa1.tif.h"
#endif


static char myname[] = "a2toa1";
static char myversion[] = "1.0";

/*
 The argument vector: list of option letters, colons denote option
 arguments.  See Usage function, immediately below, for option
 explanation.
 */

static char myarguments[] = "bchi:o:tvV";

/*
 Usage: displays helpful usage information
 */
void usage(void)
{
  static char *myargumentsexplained = NULL;

  /*  Represent the argument string in a slightly friendlier manner  */
  if(!myargumentsexplained && *myarguments) {
    int  i, hyphen = 0;
    char *ptr0, *ptr1;

    for(ptr0 = myarguments, i=0; *ptr0; ptr0++)
      if(*ptr0 == ':')
        i++;
    ptr1 = myargumentsexplained =
      (char *) malloc(strlen(myarguments) + 7*i + 2);
    for(ptr0 = myarguments; *ptr0; ptr0++)
      if(!*(ptr0+1) || *(ptr0+1) != ':') {
        if(!hyphen++) {
          *ptr1++ = ' ';
          *ptr1++ = '-';
        }
        *ptr1++ = *ptr0;
      } else {
        hyphen = 0;
        if(*(ptr1-1) != ' ')
          *ptr1++ = ' ';
        *ptr1++ = '-'; *ptr1++ = *ptr0++; *ptr1++ = ' ';
        *ptr1++ = 'a'; *ptr1++ = 'r'; *ptr1++ = 'g';
      }
        *ptr1++ = '\0';
  }

  fprintf(stderr,
          "Usage: %s%s . . .\n"
          "Options:\n"
          "\t-b              output terms in BAF format (default)\n"
          "\t-c              interpret `cons' attributes\n"
          "\t-h              display help information (usage)\n"
          "\t-i filename     input from file (default stdin)\n"
          "\t-o filename     output to file (default stdout)\n"
          "\t-t              output terms in plaintext format\n"
          "\t-v              verbose mode\n"
          "\t-V              reveal program version (i.e. %s)\n",
          myname, myargumentsexplained, myversion);
}

void version(void)
{
  fprintf(stderr, "%s v%s\n", myname, myversion);
}


int main(int argc, char **argv)
{
  int i, c;
  ATbool use_toolbus = ATfalse, interpret_cons = ATfalse;
  ATerm bottomOfStack, translatedTerm = NULL;

  /*  Configuration items  */
  char   *input="-";
  char   *output="-";
  ATbool bafmode=ATtrue;
  ATbool verbose=ATfalse;
  ATbool proceed=ATtrue;

  extern char *optarg;
  extern int   optind;

  for(i=1; i<argc; i++) {
    if(!strcmp(argv[i], "-TB_TOOL_NAME"))
      use_toolbus = ATtrue;
  }

  if(use_toolbus) {
#ifndef WIN32
    int cid;

    ATBinit(argc, argv, &bottomOfStack);    /* Initialize Aterm library */
    cid = ATBconnect(NULL, NULL, -1, a2toa1_handler);
    ATBeventloop();                         /* Never returns            */
#else
    fprintf(stderr, "%s: platform lacks ToolBus functionality\n", argv[0]);
    return -1;
#endif
  }

  /*  Commandline mode  */

  while ((c = getopt(argc, argv, myarguments)) != -1) {
    switch (c) {
      case 'b':  bafmode = ATtrue;                       break;
      case 'c':  interpret_cons = ATtrue;                break;
      case 'i':  input=optarg;                           break;
      case 'o':  output=optarg;                          break;
      case 't':  bafmode = ATfalse;                      break;
      case 'v':  verbose = ATtrue;                       break;
      case 'V':  version(); proceed=ATfalse;             break;

      case 'h':
      default:   usage(); proceed=0;                     break;
    }
  }
  argc -= optind;
  argv += optind;

  AFinit(argc, argv, &bottomOfStack);       /* Initialize Aterm library */

  if(proceed) {
    translatedTerm = a2toa1(ATreadFromNamedFile(input), interpret_cons);
    if(!translatedTerm)
      ATerror("%s: conversion failed.", myname);
    if(bafmode)
      ATwriteToNamedBinaryFile(translatedTerm, output);
    else
      ATwriteToNamedTextFile(translatedTerm, output);
  }

  return 0;
}


void rec_terminate(int cid, ATerm t) {
  exit(0);
}
