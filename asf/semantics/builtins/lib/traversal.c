#include "common.h"

/*{{{  ATerm patterns (should be apified!) */

static const char appl_pattern_str[] = "appl(prod([lit(\"<\"),cf(opt(layout)),cf(sort(\"Strategy\")),cf(opt(layout)),lit(\">\"),cf(opt(layout)),<term>],<term>,attrs([term(cons(\"apply\"))])),[lit(\"<\"),appl(prod([],cf(opt(layout)),no-attrs),[]),<term>,appl(prod([],cf(opt(layout)),no-attrs),[]),lit(\">\"),appl(prod([cf(layout)],cf(opt(layout)),no-attrs),[32]),<term>])";
static ATerm appl_pattern = NULL;

static const char fail_pattern_str[] = "appl(prod([lit(\"<\"),cf(opt(layout)),cf(sort(\"Strategy\")),cf(opt(layout)),lit(\">\"),cf(opt(layout)),<term>],<term>,attrs([term(cons(\"apply\"))])),[lit(\"<\"),appl(prod([],cf(opt(layout)),no-attrs),[]),appl(prod([lit(\"fail\")],cf(sort(\"Strategy\")),attrs([term(cons(\"fail\"))])),[lit(\"fail\")]),appl(prod([],cf(opt(layout)),no-attrs),[]),lit(\">\"),appl(prod([cf(layout)],cf(opt(layout)),no-attrs),[32]),<term>])";
static ATerm fail_pattern = NULL;

/*}}}  */

/*{{{  static void initPatterns(void) */

static void initPatterns(void)
{
  if (appl_pattern == NULL || 
      fail_pattern == NULL) {
    appl_pattern = ATparse(appl_pattern_str);
    fail_pattern = ATparse(fail_pattern_str);

    ATprotect(&appl_pattern);
    ATprotect(&fail_pattern);
  }
}

/*}}}  */

/*{{{  PT_Tree strategy_all(PT_Tree input) */

PT_Tree strategy_all(PT_Tree input)
{
  PT_Tree strategy;
  PT_Tree term;

  initPatterns();
  strategy = CO_getFunctionArgument(input, 0);
  term = CO_getFunctionArgument(input, 1);

  if (PT_isTreeLexical(term)) {
    return term;
  }
  else if (PT_isTreeAppl(term)) {
    PT_Args kids = PT_getTreeArgs(term);
    PT_Args newkids;
    PT_Production func = PT_getTreeProd(term);
    PT_Symbol type = PT_getProductionRhs(func);

    for(newkids = PT_makeArgsEmpty(); !PT_isArgsEmpty(kids); 
	kids = PT_getArgsTail(kids)) {
      PT_Tree kid = PT_getArgsHead(kids);

      if (PT_isTreeLayout(kid) || PT_isTreeLit(kid)) {
	newkids = PT_makeArgsList(kid, newkids);
      }
      else if (PT_isTreeAppl(kid)) {
	PT_Production kidprod = PT_getTreeProd(kid);
	PT_Symbol kidtype = PT_getProductionRhs(kidprod);
	PT_Tree kidappl = (PT_Tree) ATmakeTerm(appl_pattern, kidtype, kidtype, 
					       strategy, kid);
	PT_Tree newkid = rewrite(kidappl);

	if (PT_isEqualTree(newkid, kidappl)) {
	  ATwarning("Missing: imports strategies/Operators[%s]\n", 
		    PT_yieldSymbol(kidtype));
	  return term;
	}
	else if (ATmatchTerm((ATerm) newkid, fail_pattern, NULL, NULL, NULL)) {
	   return (PT_Tree) ATmakeTerm(fail_pattern, type, type, term);
	}

	newkids = PT_makeArgsList(newkid, newkids);
      }
      else {
	newkids = PT_makeArgsList(kid, newkids);
      }

    }

    return PT_makeTreeAppl(func, PT_reverseArgs(newkids));
  }

  return term; 
}

/*}}}  */
/*{{{  PT_Tree strategy_some(PT_Tree input) */

PT_Tree strategy_some(PT_Tree input)
{
  PT_Tree strategy;
  PT_Tree term;

  initPatterns();

  strategy = CO_getFunctionArgument(input, 0);
  term = CO_getFunctionArgument(input, 1);

  if (PT_isTreeLexical(term)) {
    return term;
  }
  else if (PT_isTreeAppl(term)) {
    PT_Args kids = PT_getTreeArgs(term);
    PT_Args newkids;
    PT_Production func = PT_getTreeProd(term);

    for(newkids = PT_makeArgsEmpty(); !PT_isArgsEmpty(kids); 
	kids = PT_getArgsTail(kids)) {
      PT_Tree kid = PT_getArgsHead(kids);

      if (PT_isTreeLayout(kid)) {
	newkids = PT_makeArgsList(kid, newkids);
      }
      else if (PT_isTreeAppl(kid)) {
	PT_Production kidprod = PT_getTreeProd(kid);
	PT_Symbol kidtype = PT_getProductionRhs(kidprod);
	PT_Tree kidappl = (PT_Tree) ATmakeTerm(appl_pattern, kidtype, kidtype, 
					       strategy, kid);
	PT_Tree newkid = rewrite(kidappl);

	if (PT_isEqualTree(newkid, kidappl)) {
	  ATwarning("Missing: imports strategies/Operators[%s]\n", 
		    PT_yieldSymbol(kidtype));
	  return term;
	}
	if (ATmatchTerm((ATerm) newkid, fail_pattern, NULL, NULL, NULL)) {
	   newkid = kid;
	}

	newkids = PT_makeArgsList(newkid, newkids);
      }
      else {
	newkids = PT_makeArgsList(kid, newkids);
      }

    }

    return PT_makeTreeAppl(func, PT_reverseArgs(newkids));
  }

  return term; 
}

/*}}}  */
/*{{{  PT_Tree strategy_one(PT_Tree input) */

PT_Tree strategy_one(PT_Tree input)
{
  PT_Tree strategy;
  PT_Tree term;

  initPatterns();

  strategy = CO_getFunctionArgument(input, 0);
  term = CO_getFunctionArgument(input, 1);

  if (PT_isTreeLexical(term)) {
    return term;
  }
  else if (PT_isTreeAppl(term)) {
    PT_Args kids = PT_getTreeArgs(term);
    PT_Args newkids = kids;
    PT_Production func = PT_getTreeProd(term);
    PT_Symbol type = PT_getProductionRhs(func);
    int i;

    for(i = 0; !PT_isArgsEmpty(kids); kids = PT_getArgsTail(kids), i++) {
      PT_Tree kid = PT_getArgsHead(kids);

      if (PT_isTreeLayout(kid)) {
	continue;
      }
      else if (PT_isTreeAppl(kid)) {
	PT_Production kidprod = PT_getTreeProd(kid);
	PT_Symbol kidtype = PT_getProductionRhs(kidprod);
	PT_Tree kidappl = (PT_Tree) ATmakeTerm(appl_pattern, kidtype, kidtype, 
					       strategy, kid);
	PT_Tree newkid = rewrite(kidappl);

	if (PT_isEqualTree(newkid, kidappl)) {
	  ATwarning("Missing: imports strategies/Operators[%s]\n", 
		    PT_yieldSymbol(kidtype));
	  return term;
	}
	if (!ATmatchTerm((ATerm) newkid, fail_pattern, NULL, NULL, NULL)) {
	  return (PT_Tree) PT_makeTreeAppl(func, 
					   PT_setArgsArgumentAt(newkids, 
								newkid, i));
	}
      }
    }

    return (PT_Tree) ATmakeTerm(fail_pattern, type);
  }

  return term; 
}

/*}}}  */
