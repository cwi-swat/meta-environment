#include <stdio.h>
#include <assert.h>
#include <MEPT-utils.h>
#include <ASFAPI.h>
#include <asc-builtins.h>

#define CF_PREFIX_API_FIRST_ARG 4
#define LEX_PREFIX_API_FIRST_ARG 2
#define CF_PREFIX_API_SECOND_ARG 8
#define LEX_PREFIX_API_SECOND_ARG 4
#define DEFAULT_API_LAYOUT " "

/*{{{  static getArgument(PT_Tree tree, int nrarg) */

static PT_Tree getArgument(PT_Tree tree, int nrarg)
{
  PT_Production prod;

  prod = PT_getTreeProd(tree);

  return PT_getArgsArgumentAt(PT_getTreeArgs(tree), nrarg);
}

/*}}}  */
/*{{{  static PT_getArgs getConstructorArguments(PT_Tree in) */

static PT_Args getConstructorArguments(PT_Tree in)
{
  PT_Production prod;
  PT_Args args;
  int length;
  int start, end;
  ATbool cf;

  prod = PT_getTreeProd(in);
  args = PT_getTreeArgs(in);
  length = PT_getArgsLength(args);
  cf = PT_isSymbolCf(PT_getProductionRhs(prod));
  start = cf ? CF_PREFIX_API_FIRST_ARG : LEX_PREFIX_API_FIRST_ARG;
  end = length - (cf ? 2 : 1); 

  return (PT_Args) ATgetSlice((ATermList) args,  start, end);
}

/*}}}  */

/*{{{  static PT_Tree getFirstArgument(PT_Tree tree) */

static PT_Tree getFirstArgument(PT_Tree tree)
{
  PT_Production prod;
  int nrarg;

  prod = PT_getTreeProd(tree);
  nrarg = PT_isSymbolCf(PT_getProductionRhs(prod)) ? CF_PREFIX_API_FIRST_ARG :
    LEX_PREFIX_API_FIRST_ARG;

  return getArgument(tree, nrarg);
}

/*}}}  */
/*{{{  static PT_Tree getSecondArgument(PT_Tree tree) */

static PT_Tree getSecondArgument(PT_Tree tree)
{
  PT_Production prod;
  int nrarg;

  prod = PT_getTreeProd(tree);
  nrarg = PT_isSymbolCf(PT_getProductionRhs(prod)) ? CF_PREFIX_API_SECOND_ARG :
    LEX_PREFIX_API_SECOND_ARG;

  return getArgument(tree, nrarg);
}

/*}}}  */

/*{{{  static PT_Attr getAPIAttr(PT_Attr attr, PT_Attr* found) */

static PT_Attr getAPICalls(PT_Attr attr, PT_AttrVisitorData found)
{
  AA_Calls* calls = (AA_Calls*) found;

  if (PT_isAttrTerm(attr)) {
    AA_Call term = (AA_Call) PT_getAttrTerm(attr);

    if (AA_isValidCall((AA_Call) term)) {
      *calls = AA_makeCallsList(term, *calls);
    }
  }

  return attr;
}

/*}}}  */

/*{{{  AA_Calls getTreeAPICalls(PT_Tree tree) */

AA_Calls getTreeAPICalls(PT_Tree tree)
{
  PT_Production prod;
  PT_Attributes attributes;
  PT_Attrs attrs;
  AA_Calls calls = AA_makeCallsEmpty();

  if (PT_hasTreeProd(tree)) {
    prod = PT_getTreeProd(tree);

    if (PT_hasProductionAttributes(prod)) {
      attributes = PT_getProductionAttributes(prod);
      if (PT_hasAttributesAttrs(attributes)) {
	attrs = PT_getAttributesAttrs(attributes);
	PT_foreachAttrInAttrs(attrs, getAPICalls, (PT_AttrVisitorData)&calls);
      }
    } 
  }

  return calls;
}

/*}}}  */

/*{{{  PT_Tree interpretConstructorCall(PT_Tree in, AA_Calls calls) */

PT_Tree interpretConstructorCall(PT_Tree in, AA_Calls calls)
{
  AA_Call call;
  PT_Production prod;
  PT_Args args, newargs;
  PT_Symbols lhs;

/*  assert((ATgetLength((ATermList) calls) == 1) && "ambiguous constructor");*/
  
  call = AA_getCallsHead(calls);

  if (!AA_isCallConstructor(call)) {
    return in;
  }

  prod = (PT_Production) AA_getCallProduction(call);
  lhs = PT_getProductionLhs(prod);
  args = getConstructorArguments(in);

  
  for(newargs = PT_makeArgsEmpty();
      !PT_isSymbolsEmpty(lhs); 
      lhs = PT_getSymbolsTail(lhs)) {
    PT_Symbol sym = PT_getSymbolsHead(lhs);
    PT_Tree newarg;

    if (PT_isSymbolLit(sym)) {
      newarg = PT_makeTreeLit(PT_getSymbolString(sym));
    }
    else if (PT_isOptLayoutSymbol(sym)) {
      newarg = PT_makeTreeLayoutFromString(DEFAULT_API_LAYOUT);
    }
    else {
      PT_Tree head =(PT_Tree) ATremoveAnnotations((ATerm) PT_getArgsHead(args));

      for(; !PT_isArgsEmpty(args); args = PT_getArgsTail(args)) {
	if (!PT_isTreeLayout(head) &&
	    !PT_isTreeLit(head)) {
	  break;
	}
	head = (PT_Tree) ATremoveAnnotations((ATerm) PT_getArgsHead(args));
      }

      newarg = head;

      if (PT_hasArgsTail(args)) {
	args = PT_getArgsTail(args);
      }
    }

    newargs = PT_makeArgsList(newarg, newargs);
  }


  return PT_makeTreeAppl(prod, PT_reverseArgs(newargs));
}

/*}}}  */

/*{{{  PT_Tree interpretPredicateCall(PT_Tree in, AA_Call call) */

PT_Tree interpretPredicateCall(PT_Tree in, AA_Calls calls)
{
  PT_Tree arg;
  PT_Production childprod;
  PT_Production ref;
  PT_Tree result;
  AA_Call call;

  assert((ATgetLength((ATermList) calls) == 1) && "ambiguous predicate");

  call = AA_getCallsHead(calls);
  ref = (PT_Production) AA_getCallProduction(call);

  if (!AA_isCallPredicate(call)) {
    return in;
  }

  arg = getFirstArgument(in);
  childprod = PT_getTreeProd(arg);

  if (PT_isEqualProduction(childprod, ref)) {
    result = (PT_Tree) AA_makeResultTrue();
  }
  else {
    result = (PT_Tree) AA_makeResultFalse();
  }

  return result;
}

/*}}}  */

/*{{{  PT_Tree interpretGetterCall(PT_Tree in, AA_Call call) */

PT_Tree interpretGetterCall(PT_Tree in, AA_Calls calls)
{
  PT_Tree arg;
  PT_Production childprod;
  ATbool cf;

  arg = getFirstArgument(in);
  childprod = PT_getTreeProd(arg);
  cf = PT_isSymbolCf(PT_getProductionRhs(childprod));

  /* look for a getter prod that matches, the getters that look
   * the same have been unified by the SDF2 normalizer, and their
   * attributes have been concatenated
   */
  for(;!AA_isCallsEmpty(calls);calls = AA_getCallsTail(calls)) {
    AA_Call call = AA_getCallsHead(calls);
    PT_Production ref = (PT_Production) AA_getCallProduction(call);

    if (!AA_isCallGetter(call)) {
      continue;
    }

    if (PT_isEqualProduction(childprod, ref)) {
      int argnr = AA_getCallArgNr(call);
      PT_Args args = PT_getTreeArgs(arg);
      return PT_getArgsArgumentAt(args, cf ? argnr * 2 : argnr);
    }
  }

  /* if nothing matches, we return the getter */
  return NULL;
}

/*}}}  */

/*{{{  PT_Tree interpretSetterCall(PT_Tree in, AA_Calls calls) */

PT_Tree interpretSetterCall(PT_Tree in, AA_Calls calls)
{
  PT_Tree arg, set_to;
  PT_Production childprod;
  ATbool cf;

  arg = getFirstArgument(in);
  set_to = getSecondArgument(in);

  childprod = PT_getTreeProd(arg);
  cf = PT_isSymbolCf(PT_getProductionRhs(childprod));

  /* look for a setter prod that matches, the getters that look
   * the same have been unified by the SDF2 normalizer, and their
   * attributes have been concatenated
   */
  for(;!AA_isCallsEmpty(calls);calls = AA_getCallsTail(calls)) {
    AA_Call call = AA_getCallsHead(calls);
    PT_Production ref = (PT_Production) AA_getCallProduction(call);

    if (!AA_isCallSetter(call)) {
      continue;
    }

    if (PT_isEqualProduction(childprod, ref)) {
      int argnr = AA_getCallArgNr(call);
      PT_Args args = PT_getTreeArgs(arg);
      args = PT_setArgsArgumentAt(args, set_to, cf ? argnr * 2 : argnr);
      return PT_setTreeArgs(arg, args);
    }
  }

  /* if nothing matches, we return the getter */
  return in;
}

/*}}}  */

/*{{{  PT_Tree interpretBuiltinCall(PT_Tree in, AA_Calls calls) */

PT_Tree interpretBuiltinCall(PT_Tree in, AA_Calls calls)
{
  ATerm func;
  AA_Call call;

  assert((ATgetLength((ATermList) calls) == 1) && "ambiguous builtin");

  call = AA_getCallsHead(calls);
  func = AA_getCallFunction(call);

  return forwardBuiltin(func, in);
}

/*}}}  */

/*{{{  PT_Tree interpretAPICall(PT_Tree in) */

PT_Tree interpretAPICall(PT_Tree in)
{
  AA_Calls calls = getTreeAPICalls(in);
  PT_Tree result = NULL;

  assert(!AA_isCallsEmpty(calls));

  if (AA_isCallConstructor(AA_getCallsHead(calls))) {
    result = interpretConstructorCall(in, calls);
  }
  else if (AA_isCallPredicate(AA_getCallsHead(calls))) {
    result = interpretPredicateCall(in, calls);
  } 
  else if (AA_isCallGetter(AA_getCallsHead(calls))) {
    result = interpretGetterCall(in, calls);
  }
  else if (AA_isCallSetter(AA_getCallsHead(calls))) {
    result = interpretSetterCall(in, calls);
  }
  else if (AA_isCallBuiltin(AA_getCallsHead(calls))) {
    result = interpretBuiltinCall(in, calls);
  }
  else {
    ATerror("interpretAPICall: unknown ASF api call %t\n", calls);
    return NULL;
  }

  return result;
}

/*}}}  */

/*{{{  ATbool isTreeAPIFunction(PT_Tree in) */

ATbool isTreeAPIFunction(PT_Tree in)
{
  return !AA_isCallsEmpty(getTreeAPICalls(in));
}

/*}}}  */
