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
/* #include <gc.h> */

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

ATfprintf(stderr,"reducing entered\n");
  t = AFexpandTerm(t);
  if(ATmatchTerm(t, pattern_asfix_term, NULL, NULL,
                &file, NULL, &modname, NULL, &trm, NULL, NULL)) {
    reduct = innermost(trm);
    asfix = toasfix(reduct, file, modname);
  } else
    ATerror("not an asfix term: %t\n", t);
ATfprintf(stderr,"reducing finished\n");
  return ATmake("snd-value(reduct(<term>))", asfix);
}

/*}}}  */

void reduce_and_asource(int cid, ATerm t, char *name, char *ext)
{
  FILE *file;
  char full[1024];
  ATerm reduct, asfix = NULL, filename, modname, trm; 

ATfprintf(stderr,"reducing entered\n");
  t = AFexpandTerm(t);
  if(ATmatchTerm(t, pattern_asfix_term, NULL, NULL,
                 &filename, NULL, &modname, NULL, &trm, NULL, NULL)) {
    reduct = innermost(trm);
    asfix = toasfix(reduct, filename, modname);
  } else
    ATerror("not an asfix term: %t\n", t);

ATfprintf(stderr,"reducing finished\n");
  strcat(full, name);
  strcat(full, ".");
  strcat(full, ext);
  if (!(file = fopen(full, "w"))) {
    ATfprintf(stderr, "asource: Could not open %s\n", full);
    exit(1);
  }
  AFsourceToFile(asfix, file); 
  fclose(file);
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

  name = argv[0];
  for(i=1; i<argc; i++) {
    if(streq(argv[i], "-stats"))
      printstats = ATtrue;
    else if(streq(argv[i], "-TB_TOOL_NAME"))
      use_toolbus = ATtrue;
    else if(streq(argv[i], "-name"))
      name = argv[++i];
  }
 
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

  if(use_toolbus) {
    ATBeventloop();
  } 
  else {
    t = ATreadFromFile(stdin);
    t = AFexpandTerm(t);

    if(ATmatchTerm(t, pattern_asfix_term, NULL, NULL,
                  &file, NULL, &modname, NULL, &trm, NULL, NULL)) {
ATfprintf(stderr,"Reducing ...\n");
      reduct = innermost(trm);
ATfprintf(stderr,"Reducing finished.\n");
/*
{
  FILE *f = fopen("/tmp/pgen.out", "w");
  assert(f);
  AT_collect(2);
  AT_printAllAFunCounts(f);
  fclose(f);
}
*/
      asfix = toasfix(reduct, file, modname);
      ATwriteToBinaryFile(asfix,stdout);
      /*ATwriteToTextFile(asfix,stdout);*/
    }
    else
      ATfprintf(stderr, "not an asfix term: %t\n", t);
  }
  return 0;
}

/*}}}  */
