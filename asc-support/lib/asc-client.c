#include <stdlib.h>

#include <asc-support2-me.h>
#include <MEPT-utils.h>
#include <PTMEPT-utils.h>
#include <Error-utils.h>
#include "Library.h"
#include "builtin-common.h"

static ATerm apply(ATerm input);

ATerm asf_toolbus_handler(int conn, ATerm term)
{
  ATerm in, out;
  ATerm t0;

  if(ATmatch(term, "rec-terminate(<term>)", &t0)) {
    exit(0);
    return NULL;
  }
  else if (ATmatch(term, "rec-do(signature(<term>,<term>))", &in, &out)) {
    return NULL; 
  }
  else if(ATmatch(term, "rec-eval(<term>)", &t0)) {
    return apply(t0);
  }
  else if(ATmatch(term, "rec-do(<term>)", &t0)) {
    /* an ASF specification with side-effects might use this. */
    (void) apply(t0);
    return NULL;
  }

  ATerror("tool addeqssyntax cannot handle term %t", term);
  return NULL; /* Silence the compiler */
}

static ATerm convert(const char* name, PT_Tree tree)
{
  if (PT_isTreeAppl(tree)) {
    PT_Production prod = PT_getTreeProd(tree);
    PT_Symbol rhs = PT_getProductionRhs(prod);
    PT_Symbol aterm = PT_makeSymbolSort("ATerm"); 
    PT_Symbol summary = PT_makeSymbolSort("Summary"); 
    PT_Symbol strcon = PT_makeSymbolSort("StrCon");
    PT_Symbol natcon = PT_makeSymbolSort("NatCon"); 
    ATerm result = NULL;

    rhs = (PT_isSymbolCf(rhs) || PT_isSymbolLex(rhs)) ? 
      PT_getSymbolSymbol(rhs) : rhs;

    if (PT_isEqualSymbol(rhs, aterm)) {
      result = PTPT_lowerATerm((PTPT_ATerm) tree);
    }
    else if (PT_isEqualSymbol(rhs, summary)) {
      result = (ATerm) PERR_lowerSummary((PERR_Summary) tree);
    }
    else if (PT_isEqualSymbol(rhs, strcon)) {
      /* a StrCon has (not by accident) the same syntax as
       * ATerm quoted function symbols
       */
      result = ATparse(PT_yieldTree(tree));
    }
    else if (PT_isEqualSymbol(rhs, natcon)) {
      result = ATparse(PT_yieldTree(tree));
    }
    else {
      /* a possible very big parse tree should be packed */
      result = ATBpack((ATerm) tree);
    }

    return (ATerm) ATmakeAppl(ATmakeAFun(name, 1, ATfalse), result);
  }
  
  ATwarning("warning: rewriting result is not convertible.");
  return ATparse("non-convertible-result");
}

static PT_Args kidsToArgs(ATermList kids) 
{
  PT_Args args = PT_makeArgsEmpty();

  for ( ; !ATisEmpty(kids); kids = ATgetNext(kids)) {
    ATerm kid = ATBunpack(ATgetFirst(kids));
    PT_Tree arg = NULL;
    const char* string = NULL;
    int natural;

    if (ATmatch(kid, "<str>", &string)) {
      arg = (PT_Tree) CO_makeStrCon(string);
    }
    else if (ATmatch(kid,"<int>", &natural)) {
      char str[512];
      sprintf(str, "%d", natural);
      arg = (PT_Tree) CO_makeNatConLexToCf(CO_makeLexNatConDigits(str));
    }
    else if (ATmatch(kid, "parsetree(<term>,<int>)", NULL, NULL)) {
      arg = PT_getParseTreeTree((PT_ParseTree) kid);
    }
    else if (ATmatch(kid, "appl(<term>,<term>)", NULL, NULL)) {
      arg = (PT_Tree) kid;
    }
    else {
      arg = (PT_Tree) PTPT_liftATerm(kid);
    }

    args = PT_makeArgsMany(arg, args);
  }

  return PT_reverseArgs(args);
}

static ATerm apply(ATerm input) 
{
  if (ATgetType(input) == AT_APPL) {
    AFun fun = ATgetAFun((ATermAppl) input);
    const char* name = ATgetName(fun);
    ATermList kids = ATgetArguments((ATermAppl) input);
    PT_Args args = kidsToArgs(kids);
    PT_Tree tempTree = PT_applyFunctionToArgs(name, "*bogus*", args);
    PT_Production prod = PT_getTreeProd(tempTree);
    PT_Symbols lhs = PT_getProductionLhs(prod); 
    funcptr func = prefix_lookup_func(lhs);
    ATermList normalforms = ATempty;

    for ( ; !PT_isArgsEmpty(args); args = PT_getArgsTail(args)) {
      PT_Tree term = PT_getArgsHead(args);
      ATerm reduct = innermost(term);
      normalforms = ATinsert(normalforms, reduct);
    }
    normalforms = ATreverse(normalforms);

    if (func) {
      ATerm result = call_using_list(func, normalforms);
      PT_Tree tree = toasfix(result);
      return ATmake("snd-value(<term>)", convert(name, tree));
    }
    else {
      ATwarning("warning: no function named %s found in tool\n", name);
    }
  }

  return ATmake("snd-value(rewriting-failed)");
}
