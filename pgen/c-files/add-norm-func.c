#include <stdlib.h>
#include <aterm2.h>
#include <AsFix.h>
#include <AsFix-expand.h>
#include <AsFix-init-patterns.h>
#include <AsFix2src.h>
#include <atb-tool.h>
#include <deprecated.h>
#include "add-norm-func.tif.h"

static char *name;

extern ATerm pattern_asfix_term;
void AFinitExpansionTerms();

ATerm make_function_term(ATerm term)
{
  ATerm t_name;
  ATerm t_mod_name;
  ATerm prod, appl;
  ATerm abbrevs;
  ATerm term_open, term_close, term_ws;
  ATerm lit[2],w[4],id,arg;

  if(ATmatchTerm(term,pattern_asfix_term,
                 &lit[0],&w[0],&lit[1],&w[1],&id,&w[2],&arg,&w[3],NULL)) {
    /*    a_name = ATparse("l(Risla)");
     */
    t_mod_name = ATparse("id(\"Sdf2-Parse-Table\")");
    t_name = ATparse("l(\"normalize\")");
    abbrevs = ATparse("abbreviations([])");
    term_open = ATparse("l(\"(\")");
    term_close = ATparse("l(\")\")");
    term_ws = ATparse("w(\"\")");

    prod = AFmakeProd(t_mod_name,
                      ATmakeList(7,t_name,term_ws,term_open,term_ws,
                                 ATparse("sort(\"SDF\")"),
                                 term_ws,term_close),
                      ATparse("sort(\"Grammar\")"),
                      ATparse("no-attrs"));
    appl = AFmakeAppl(prod,
                      ATmakeList(7,t_name,term_ws,term_open,term_ws,
                                 arg,
                                 term_ws,term_close));
    return ATmake("term(<term>,<term>,<term>,<term>,<term>,<term>," \
                  "<term>,<term>,<term>)",
                   ATparse("l(\"term\")"),
                   term_ws,lit[1],term_ws,id,term_ws,
                   appl,term_ws,abbrevs);
  } 
  else {
    ATerror("Illegal term %t\n", term);
    return NULL; /* Silence the compiler */
  }
}

ATerm get_name(int cid)
{
  return ATmake("snd-value(name(<str>))", name);
}


void rec_terminate(int cid, ATerm t) {
  exit(0);
}

ATerm addfunction(int cid, ATerm t) 
{
  ATerm tin, tout;

  tin = AFexpandTerm(t);
  tout = make_function_term(tin);
  return ATmake("snd-value(result(<term>))", tout);
}

int main(int argc, char **argv) {
  int i, cid, use_toolbus = 0;
  ATerm bottomOfStack;

  for(i=1; i<argc; i++)
    if(streq(argv[i], "-TB_TOOL_NAME"))
      use_toolbus = 1;

  if(use_toolbus) {
    ATBinit(argc, argv, &bottomOfStack);  /* Initialize the Aterm library */
    cid = ATBconnect(NULL, NULL, -1, add_norm_func_handler);
    ATBeventloop();

  } else {
    ATerm tin, tout;

    AFinit(argc, argv, &bottomOfStack);

    AFinitAsFixPatterns();

    tin = ATreadFromFile(stdin);
    tin = AFexpandTerm(tin);
    tout = make_function_term(tin);
    /*ATwriteToTextFile(tout,stdout); */
    ATwriteToBinaryFile(tout,stdout);
  }
  return 0;
}
