/*

    Meta-Environment - An environment for language prototyping.
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

#include <time.h>

#define TICK2SEC(t)             (((double)(t))/CLK_TCK)

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include <aterm2.h>
#include <AsFix.h>
#include <AsFix2src.h>
#include <AsFix-access.h>

#include "preparation.h"
#include "evaluator.tif.h"
#include "traversals.h"
#include "evaluator.h"

/*{{{  variables */

static char myarguments[] = "be:hi:o:tvV";
static char myname[] = "evaluator";
static char myversion[] = "0.1";

/*}}}  */
/*{{{  void usage(char *prg) */

/*     Usage: displays helpful usage information
 */

void usage(char *prg, ATbool is_err)
{
  ATwarning(
	    "Usage: %s [options]\n"
	    "Options:\n"
	    "\t-b              output terms in BAF format (default)\n"   
	    "\t-t              output terms in plaintext format\n"    
	    "\t-h              display help information (usage)\n"
	    "\t-e file         use the equations |file|\n"
	    "\t-i filename     input from file (default stdin)\n"
	    "\t-o filename     output to file (default stdout)\n"
	    "\t-v              verbose mode\n"
	    "\t-V              reveal program version (i.e. %s)\n",
	    prg, myversion);
  exit(is_err ? 1 : 0);
}

/*}}}  */
/*{{{  void version(char *prg) */

void version(char *prg)
{
  ATwarning("%s v%s\n", prg, myversion);
  exit(1);
}

/*}}}  */

/*{{{  void abort_handler(int signal) */

void abort_handler(int signal)
{
  RWsetError("aborted by user", (ATerm)ATempty);
}

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  ATerm bottomOfStack;

  FILE *iofile;
#ifdef PROFILING
  struct tms start, rewriting;
  clock_t user, system;
#endif
  int cid;
  int c, toolbus_mode = 0;
  char *input = "-";
  char *output = "-";
  char *eqsfile = "-";
  int bafmode = 1;
  char *name = "Standalone";
  int returncode = 0;
  ATerm eqs, term, aterm, realterm, newterm, newaterm, result;
  ATermList neweqs;


  /*  Check whether we're a ToolBus process  */
  for (c=1; !toolbus_mode && c < argc; c++) {
    toolbus_mode = !strcmp(argv[c], "-TB_TOOL_NAME");
  }

  signal(SIGUSR1, abort_handler);

  AFinit(argc, argv, &bottomOfStack);

  equations_db = ATdictCreate();
  ATprotect(&equations_db);

  fail_env = ATparse("[fail]");
  ATprotect(&fail_env);

  posinfo = ATparse("pos-info");
  ATprotect(&posinfo);

  list_var  = ATmakeAFun("*list-var*", 3, ATtrue);
  ATprotectAFun(list_var);

  plain_var = ATmakeAFun("*plain-var*", 2, ATtrue);
  ATprotectAFun(plain_var);

  RWclearError();

  ATprotect(&tagCurrentRule);

  if(toolbus_mode) {
#ifndef WIN32 /* Code with Toolbus calls, non Windows */
    ATBinit(argc, argv, &bottomOfStack); 
    cid = ATBconnect(NULL, NULL, -1,evaluator_handler); 
    ATBeventloop();
#else
    ATwarning("evaluator: Toolbus cannot be used in Windows.\n");
#endif
  } 
  else {
    while ((c = getopt(argc, argv, myarguments)) != -1) {
      switch (c) {
      case 'b':  bafmode = 1;                            break;
      case 't':  bafmode = 0;                            break; 
      case 'v':  run_verbose = ATtrue;                   break;
      case 'e':  eqsfile=optarg;                         break;
      case 'i':  input=optarg;                           break;
      case 'o':  output=optarg;                          break;
      case 'V':  version(argv[0]);                       break;

      case 'h':  usage(argv[0], ATfalse);                break;
      default:   usage(argv[0], ATtrue);                 break;
      }
    }

    /* Get the equations from file */
    if (!(iofile = fopen(eqsfile, "r")))
      ATerror("%s: cannot open %s\n", myname, eqsfile);

    eqs = ATreadFromFile(iofile);
    fclose(iofile);

    /* Prepare the equations and put them in the database */
    neweqs = RWprepareEqs((ATermList) eqs);

    enter_equations(name, neweqs);

    /* Get the term from file */
    if (!strcmp(input, "") || !strcmp(input, "-"))
      iofile = stdin;
    else if (!(iofile = fopen(input, "r")))
      ATerror("%s: cannot open %s\n", myname, input);
 
    term = ATreadFromFile(iofile);
    fclose(iofile);

    /* Prepare the term for rewriting */
    term = ATremoveAllAnnotations(term);
    aterm = asfix_get_term(term);
    realterm = RWprepareTerm(aterm);

    /* Rewrite the term */

    /*rewrite_steps = 0;*/
    select_equations(name);

		
    tagCurrentRule = NULL;

    if(run_verbose) 
      ATwarning("rewriting...\n");
   
#ifdef PROFILING 
    times(&start);
    newterm = rewrite(realterm,(ATerm) ATempty, 0);
    times(&rewriting);

    user = rewriting.tms_utime - start.tms_utime;
    system = rewriting.tms_stime - start.tms_stime;
   
    ATwarning("rewriting: %f user, %f system\n", TICK2SEC(user), TICK2SEC(system)); 
#else
    newterm = (ATerm) rewrite(realterm, (ATerm) ATempty, 0);
#endif


    /* Postprocessing of reduct */
    newaterm = RWrestoreTerm(newterm);
    result = asfix_put_term(term,newaterm);

    /* If we have collected errors, pretty print them now */
    returncode = (RWgetError() == NULL) ? 0 : 1;

    if (RWgetError() != NULL) {
      ATerm message, tag, subject;
      char *messageText = NULL, *tagText = NULL, *subjectText = NULL;
      ATermList error;
								
      /* The errors are tuples containing a message and a subject */
      error = (ATermList) RWgetError();
      message = ATgetFirst(error);
      tag = ATgetFirst(ATgetNext(error));
      subject = ATgetFirst(ATgetNext(ATgetNext(error)));
				
      /* Now unparse these fields to text */
      messageText = (char*) malloc(AFsourceSize(message)+1);
      tagText = (char*) malloc(AFsourceSize(tag)+1);
      subjectText = (char*) malloc(AFsourceSize(subject));
			
      if(messageText && tagText && subjectText) {
	AFsource(message, messageText);
	AFsource(tag,tagText);
	AFsource(subject,subjectText);
				
	ATwarning("%s (%s, %s)\n", messageText,tagText,subjectText);
      } else {
	ATerror("No memory available to print errors.\n");
      }
    }

    /* Communicate the reduct out of here */
    if (!strcmp(output, "") || !strcmp(output, "-"))
      iofile = stdout;
    else if (!(iofile = fopen(output, "w")))
      ATerror("%s: cannot open %s\n", myname, output);
		
    if(bafmode)
      ATwriteToBinaryFile(result, iofile);
    else
      ATwriteToTextFile(result, iofile);
		
    fclose(iofile);
  }
  
  return returncode;
}

/*}}}  */
