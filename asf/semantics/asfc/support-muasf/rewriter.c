/**
  * Library support for rewriting terms.
  *
  * Pieter Olivier
  * Thu Aug 14 11:36:34 MET DST 1997
  */

#include <stdio.h>
#include <assert.h>
#include <ctype.h>

#include <AsFix.h>
#include <AsFix-expand.h>
#include <AsFix-init-patterns.h>
#include <atb-tool.h>
#include <deprecated.h>

#include "support.h"
#include "rewriter.tif.h"

/*{{{  globals */

static char *name;

extern ATerm pattern_asfix_term;

ATerm innermost(ATerm t);
ATerm toasfix(ATerm t, ATerm f, ATerm n);
void init_patterns();
void c_rehash(int newsize);

/*}}}  */
/*{{{  ATerm *get_name(int cid) */

ATerm get_name(int cid)
{
  return ATmake("snd-value(name(<str>))", name);
}

/*}}}  */
/*{{{  ATerm *reduce(int cid, ATerm *t) */

ATerm reduce(int cid, ATerm t)
{
  ATerm reduct, asfix = NULL, file, modname, trm;

  t = AFexpandTerm(t);
  if(ATmatchTerm(t, pattern_asfix_term, NULL, NULL,
                &file, NULL, &modname, NULL, &trm, NULL, NULL)) {
    ATfprintf(stderr,"Reducing ... \n");
    reduct = innermost(trm);
/*
    ATfprintf(stderr, "%t\n", reduct);
*/
    ATfprintf(stderr,"Reducing finished.\n");
    asfix = toasfix(reduct, file, modname);
  } else
    ATerror("not an asfix term: %t\n", t);
  return ATmake("snd-value(reduct(<term>))", asfix);
}

/*}}}  */
/*{{{  void rec_terminate(int cid) */

void rec_terminate(int cid, ATerm arg)
{
  exit(0);
}

/*}}}  */
/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  ATerm t, trm, reduct, asfix, file, modname;
  ATbool printstats = ATfalse, use_toolbus = ATfalse;
  int i, cid;
  ATerm bottomOfStack;

ATfprintf(stderr,"Main entered\n");
  name = argv[0];
  for(i=1; i<argc; i++) {
ATfprintf(stderr,"arg is %s\n", argv[i]);
    if(streq(argv[i], "-stats"))
      printstats = ATtrue;
    else if(streq(argv[i], "-TB_TOOL_NAME"))
      use_toolbus = ATtrue;
    else if(streq(argv[i], "-name"))
      name = argv[++i];
  }
ATfprintf(stderr,"use_toolbus is %d\n",use_toolbus);
 
  if(use_toolbus) {
    ATBinit(argc, argv, &bottomOfStack);
    cid = ATBconnect(NULL, NULL, -1, rewriter_handler);
  }
  AFinit(argc, argv, &bottomOfStack);

  init_patterns();
  AFinitAsFixPatterns();

  c_rehash(INITIAL_TABLE_SIZE);
  register_all();
  resolve_all();
  init_all();

ATfprintf(stderr,"Registering and resolving finished\n");
  if(use_toolbus) {
    ATBeventloop();
  } 
  else {
    trm = ATreadFromFile(stdin);
ATfprintf(stderr,"Term read\n");

ATfprintf(stderr,"Reducing ...\n");
    reduct = innermost(trm);
/*
ATfprintf(stderr, "%t\n", reduct);
*/
ATfprintf(stderr,"Reducing finished.\n");
/*
    asfix = toasfix(reduct, file, modname);
    ATwriteToBinaryFile(reduct,stdout);
*/
ATfprintf(stderr, "%t\n", reduct);
  }
  return 0;
}

/*}}}  */
