/**
  * Library support for rewriting terms.
  *
  * Pieter Olivier
  * Thu Aug 14 11:36:34 MET DST 1997
  */

#include <stdio.h>
#include <assert.h>
#include <ctype.h>

#include <asfix.h>
#include <tb-tool.h>

#include "support.h"
#include "rewriter.tif.c"

FATAL_ERROR

/*{{{  globals */

static arena *ar;
static char *name;

extern aterm *pattern_asfix_term;

aterm *innermost(arena *ar, aterm *t);
aterm *toasfix(arena *ar, aterm *t, aterm *f, aterm *n);
void init_patterns(arena *ar);
void c_rehash(int newsize);

/*}}}  */
/*{{{  aterm *get_name(int cid) */

aterm *get_name(int cid)
{
  return Tmake(ar, "snd-value(name(<str>))", name);
}

/*}}}  */
/*{{{  aterm *reduce(int cid, aterm *t) */

aterm *reduce(int cid, aterm *t)
{
  aterm *reduct, *asfix, *file, *modname, *trm;

  t = AFexpandTerm(ar, t);
  if(TmatchTerm(t, pattern_asfix_term, NULL, NULL,
                &file, NULL, &modname, NULL, &trm, NULL, NULL)) {
    Tprintf(stderr,"Reducing ... \n",trm);
    reduct = innermost(ar, trm);
    /*Tprintf(stdout, "%t\n", reduct);*/
    Tprintf(stderr,"Reducing finished.\n");
    asfix = toasfix(ar, reduct, file, modname);
  } else
    Tprintf(stderr, "not an asfix term: %t\n", t);
  return Tmake(ar, "snd-value(reduct(<term>))", asfix);
}

/*}}}  */
/*{{{  void rec_terminate(int cid) */

void rec_terminate(int cid, aterm *arg)
{
  exit(0);
}

/*}}}  */
/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  aterm *t, *trm, *reduct, *asfix, *file, *modname;
  Tbool printstats = Tfalse, use_toolbus = Tfalse;
  static arena local;
  int i, cid;

Tprintf(stderr,"Main entered\n");
  name = argv[0];
  for(i=1; i<argc; i++) {
Tprintf(stderr,"arg is %s\n", argv[i]);
    if(streq(argv[i], "-stats"))
      printstats = Ttrue;
    else if(streq(argv[i], "-TB_TOOL_NAME"))
      use_toolbus = Ttrue;
    else if(streq(argv[i], "-name"))
      name = argv[++i];
  }
Tprintf(stderr,"use_toolbus is %d\n",use_toolbus);
 
  if(use_toolbus) {
    TBinit(argc, argv);
    cid = TBnewConnection(NULL, NULL, NULL, -1,
                          rewriter_handler, rewriter_check_in_sign);
    TBconnect(cid);
    ar = TBgetArena(cid);
  } else {
    Tinit(argc, argv);

    TinitArena(NULL, &local);
    ar = &local;
  }
  AFinit(the_world);

  w = the_world;
  init_patterns(ar);

  c_rehash(INITIAL_TABLE_SIZE);
  register_all();
  resolve_all();

  oksym = TmkSymbol("ok", 0);
  tuplesym = TmkSymbol("tuple", 0);
  nullsym = TmkSymbol("null", 0);

Tprintf(stderr,"Registering and resolving finished\n");
  TflushArena(ar);
  if(use_toolbus) {
    TBeventloop();
  } else {
    if(TreadTermFile(stdin, ar, &t) >= 0) {
Tprintf(stderr,"Term read\n");
      t = AFexpandTerm(ar, t);
      if(TmatchTerm(t, pattern_asfix_term, NULL, NULL,
                    &file, NULL, &modname, NULL, &trm, NULL, NULL)) {
Tprintf(stderr,"Reducing ... \n",trm);
        reduct = innermost(ar, trm);
        /*Tprintf(stdout, "%t\n", reduct);*/
Tprintf(stderr,"Reducing finished.\n");
        asfix = toasfix(ar, reduct, file, modname);
        Tprintf(stdout, "%t\n", asfix);
        /* if(printstats)
        TprintHashStats(stderr, w); */
      } else
        Tprintf(stderr, "not an asfix term: %t\n", t);
    } else {
      fprintf(stderr, "parse error\n");
      exit(1);
    }
  }
  return 0;
}

/*}}}  */
