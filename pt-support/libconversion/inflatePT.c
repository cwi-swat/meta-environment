/*
    $Id $
*/

#include <stdio.h>

#include "conversion.h"


/* Forward declaration(s) of recursive functions */
static ATerm explodeTerm(ATerm term);



/* Global variables */
static ATerm asfix2_parsetree_pattern = NULL;
static ATerm asfix2_amb_pattern = NULL;
static ATerm asfix2_appl_pattern = NULL;
static ATerm asfix2_layout_pattern = NULL;
static ATerm asfix2_literal_pattern = NULL;



static void
init_asfix2_patterns(void)
{
  ATprotect(&asfix2_parsetree_pattern);
  asfix2_parsetree_pattern = ATparse("parsetree(<term>,<term>)");

  ATprotect(&asfix2_amb_pattern);
  asfix2_amb_pattern = ATparse("amb([<list>])");

  ATprotect(&asfix2_appl_pattern);
  asfix2_appl_pattern = ATparse("appl(<term>,[<list>])");

  ATprotect(&asfix2_layout_pattern);
  asfix2_layout_pattern = ATparse("layout([<list>])");
  
  ATprotect(&asfix2_literal_pattern);
  asfix2_literal_pattern = ATparse("lit(<str>)");
}

static void
init_patterns(void)
{
  static ATbool initialized = ATfalse;

  if (!initialized) {
    init_asfix2_patterns();
    initialized = ATtrue;
  }
}

static ATerm
explodeLayout(ATerm term)
{
  return term;
}

static ATerm
explodeLiteral(ATerm term)
{
  return term;
}

static ATermList
explodeArgs(ATermList args)
{
  if (ATisEmpty(args)) {
    return ATempty;
  }

  return ATinsert(explodeArgs(ATgetNext(args)), explodeTerm(ATgetFirst(args)));
}

static ATerm
explodeTerm(ATerm term)
{
  ATerm     prod;
  ATermList args;

  /* todo: char */

  if (ATmatchTerm(term, asfix2_amb_pattern, &args)) {
    return ATmakeTerm(asfix2_amb_pattern, explodeArgs(args));
  }

  if (!ATmatchTerm(term, asfix2_appl_pattern, &prod, &args)) {
    ATerror("explodeTerm: not an appl pattern: %t\n", term);
    return NULL;
  }

  if (ATmatchTerm(term, asfix2_layout_pattern, NULL)) {
    return explodeLayout(term);
  }

  if (ATmatchTerm(term, asfix2_literal_pattern, NULL)) {
    return explodeLiteral(term);
  }

  return ATmakeTerm(asfix2_appl_pattern, prod, explodeArgs(args)); 
}

static ATerm
explodeParseTree(ATerm tree)
{
  ATerm exploded;
  ATerm ambCnt;
  
  if (ATmatchTerm(tree, asfix2_parsetree_pattern, &exploded, &ambCnt)) {
    return ATmakeTerm(asfix2_parsetree_pattern, explodeTerm(exploded), ambCnt);
  }

  ATerror("explodeParseTree: not a parsetree: %t\n", tree);
  return NULL;
}

ATerm inflatePT(ATerm tree)
{
  ATerm exploded;

  init_patterns();

  exploded = explodeParseTree(tree);

  return exploded;
}
