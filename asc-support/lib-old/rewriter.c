/*

    Asf Sdf Compiler Runtime Library
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
#ifndef WIN32
/* These files can not be included in Windows NT*/
#include <atb-tool.h>
#include "rewriter.tif.h"
#else
#include <stdlib.h>	/* used for exit(0) */
#endif

#include <stdio.h>
#include <assert.h>
#include <ctype.h>

#include "asc-support2.h"

static char *name; 

ATerm get_name(int cid)
{
  return ATmake("snd-value(name(<str>))", name);
}


ATerm reduce(int cid, ATerm t)
{
  ATerm reduct;
  PT_ParseTree pt;
  PT_ParseTree asfix = NULL;
  PT_Tree trm;

  pt = PT_makeParseTreeFromTerm(t);

  if (PT_isValidParseTree(pt)) {
    trm = PT_getParseTreeTree(pt);
    reduct = innermost(trm);
    asfix = toasfix(reduct);
  } else {
    ATerror("not an asfix term: %t\n", t);
  }
  
  return ATmake("snd-value(reduct(<term>))", PT_makeTermFromParseTree(asfix));
}

void rec_terminate(int cid, ATerm arg)
{
  exit(0);
}


/**
 * Print usage information and exit
 */

void usage(char *prg)
{
  fprintf(stderr, "usage: %s [aterm-options] [toolbus-options] [options]",prg);
  fprintf(stderr, "options:\n");
  fprintf(stderr, "  -stats/-s:        print statistics.\n");
  fprintf(stderr, "  -name/-n <name>   set the name of the specifications.\n");
  fprintf(stderr, "  -verbose/-v       verbose mode.\n");
  fprintf(stderr, "use %s -at-help to get more aterm/toolbus options.\n", prg);
  exit(1);
}


int main(int argc, char *argv[])
{
  ATerm bottomOfStack;
  PT_ParseTree pt;
  PT_ParseTree asfix;
  PT_Tree trm;
  ATerm t, reduct;
  ATbool printstats = ATfalse, use_toolbus = ATfalse,
         run_verbose = ATfalse;
  int i, cid;
  name = argv[0];

  for(i=1; i<argc; i++) {
    if(streq(argv[i], "-stats") || streq(argv[i], "-s")) {
      printstats = ATtrue;
    } else if(streq(argv[i], "-TB_TOOL_NAME") || streq(argv[i], "-at-help")) {
      use_toolbus = ATtrue;
    } else if(streq(argv[i], "-name") || streq(argv[i], "-n")) {
      name = argv[++i];
    } else if(streq(argv[i], "-v")) {
      run_verbose = ATtrue;
    } else if(streq(argv[i], "-h")) {
      usage(argv[0]);
    }
  }
 
  if(use_toolbus) {
    ATBinit(argc, argv, &bottomOfStack);  /* Initialize the Aterm library */
    cid = ATBconnect(NULL, NULL, -1, rewriter_handler);
  }

  ATinit(argc, argv, &bottomOfStack);
  ASC_initRunTime(INITIAL_TABLE_SIZE);

  register_all();
  resolve_all();
  init_all();

  if(use_toolbus) {
    ATBeventloop();
  } 
  else {
    t = ATreadFromFile(stdin);
    pt = PT_makeParseTreeFromTerm(t);

    if (PT_isValidParseTree(pt)) {
      trm = PT_getParseTreeTree(pt);
      
      if(run_verbose) {
	ATfprintf(stderr,"Reducing ...\n");
      }
      
      reduct = innermost(trm);
      
      if(run_verbose) {
	ATfprintf(stderr,"Reducing finished.\n");
      }

      asfix = toasfix(reduct);

      ATwriteToBinaryFile(PT_makeTermFromParseTree(asfix),stdout);
    }
    else { 
      ATfprintf(stderr, "not an asfix term: %t\n", t);
    }
  }
  return 0;
}


