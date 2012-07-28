/*$Id$ */

#include <assert.h>

#include "environment.h"
#include "values.h"

ATerm fail_env = NULL;

#define LISTVAR "*list-variable*"
#define PLAINVAR "*variable*"

static ATerm varName(PT_Tree var) 
{
  static ATermTable cache = NULL;
  ATerm result = NULL;

  if (cache == NULL) {
    cache = ATtableCreate(1024, 75);
  }

  result = ATtableGet(cache, (ATerm) var);

  if (result == NULL) {
    result = ATmake("<str>", PT_yieldTreeToString(var, ATfalse));
    ATtablePut(cache, (ATerm) var, result);
  }

  return result;
}

/* Retrieve the value of a variable. */
PT_Tree getVariableValue(ATerm env, PT_Tree var) {
  PT_Production prod = PT_getTreeProd(var);
  PT_Symbol symbol = PT_getProductionRhs(prod);
  
  if (PT_isIterSepSymbol(symbol) || 
      PT_isIterSymbol(symbol)) {
    Slice slice = getListVariableValue(env, var);
    PT_Args newelems;
    
    if (slice) {
      newelems = appendSlice(PT_makeArgsEmpty(), slice);

      return PT_makeTreeAppl(PT_makeProductionList(symbol), newelems);
    }
  }
  else {
    ATermList list = (ATermList) env;
    ATerm atVar = varName(var);

    while (!ATisEmpty(list)) {
      ATermAppl tuple = (ATermAppl) ATgetFirst(list);
      if (ATisEqual(ATgetArgument(tuple, 0), atVar)) {
        return PT_TreeFromTerm(ATgetArgument(tuple, 1));
      }

      list = ATgetNext(list);
    }
  }

  return NULL;
}


/* Retrieve the value of a list variable. */
Slice getListVariableValue(ATerm env, PT_Tree var) {
  ATermList list = (ATermList) env;
  ATerm atVar = varName(var);

  while (!ATisEmpty(list)) {
    ATermAppl tuple = (ATermAppl) ATgetFirst(list);
    if (ATisEqual(ATgetArgument(tuple, 0), atVar)) {
      return (Slice) tuple;
    }

    list = ATgetNext(list);
  }

  return NULL;
}


/* Store the value of a variable in the value environment. */
ATerm putVariableValue(ATerm env, PT_Tree var, PT_Tree value) {
  ATerm atVar = varName(var);
  ATerm atValue = PT_TreeToTerm(value);

  return (ATerm) ATinsert((ATermList) env,
			  (ATerm) ATmakeAppl2(ATmakeAFun(PLAINVAR,2,ATtrue), 
					      atVar, atValue));
}


ATerm putListVariableValue(ATerm env, PT_Tree var, PT_Args start, PT_Args end) {
  ATerm atVar = varName(var);
  ATerm atStart = PT_ArgsToTerm(start);
  ATerm atEnd = PT_ArgsToTerm(end);

  return (ATerm) ATinsert((ATermList) env,
			  (ATerm) ATmakeAppl3(ATmakeAFun(LISTVAR,3,ATtrue), 
					      atVar, atStart, atEnd));
}


/* See if a variable is bound. */
ATbool isBoundVariable(ATerm env, PT_Tree var) {
  ATermList list = (ATermList) env;
  ATerm atVar = varName(var);

  while (!ATisEmpty(list)) {
    ATermAppl tuple = (ATermAppl) ATgetFirst(list);
    if (ATisEqual(ATgetArgument(tuple, 0), atVar)) {
      return ATtrue;
    }
    list = ATgetNext(list);
  }

  return ATfalse;
}


ATbool no_new_vars(PT_Tree trm, ATerm env) {
  PT_Tree arg;
  PT_Args args;
  ATbool existing;

  if (PT_isTreeVar(trm)) {
    if (isBoundVariable(env, trm))
      return ATtrue;
    else
      return ATfalse;
  }
  else if (PT_isTreeAppl(trm)) {
    existing = ATtrue;
    args = PT_getTreeArgs(trm);
    while (existing && PT_hasArgsHead(args)) {
      arg = PT_getArgsHead(args);
      existing = no_new_vars(arg, env);
      args = PT_getArgsTail(args);
    };
    return existing;
  }
  else {
    return ATtrue;
  }
}

