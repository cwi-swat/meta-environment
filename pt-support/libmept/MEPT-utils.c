/* $Id$ */

/*{{{  includes */

#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "MEPT-utils.h"

/*}}}  */

/*{{{  defines */

#define ANNO_LENGTH "length"  

/*}}}  */

/* Productions */
/*{{{  ATbool PT_prodHasLitAsRhs(PT_Production prod) */

ATbool PT_prodHasLitAsRhs(PT_Production prod)
{
  /* This implements: "prod([<list>],lit(<str>),no-attrs)" */
  if (PT_isProductionDefault(prod)) {
    PT_Symbol rhs = PT_getProductionRhs(prod);

    return PT_isSymbolLit(rhs);
  }

  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isLexicalProd(PT_Production prod) */

ATbool PT_isLexicalProd(PT_Production prod)
{
  /* This implements: "prod([<list>],lex(sort(<term>)),<term>)" */
  if (PT_isProductionDefault(prod)) {
    PT_Symbol rhs = PT_getProductionRhs(prod);

    if (PT_isSymbolLex(rhs)) {
      PT_Symbol symbol = PT_getSymbolSymbol(rhs);
      return PT_isSymbolSort(symbol);
    }
    return ATfalse;
  }

  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isProductionInjection(PT_Production prod) */

ATbool PT_isProductionInjection(PT_Production prod)
{
  PT_Symbols lhs = PT_getProductionLhs(prod);

  if (PT_getSymbolsLength(lhs) == 1) {
    PT_Symbol symbol = PT_getSymbolsHead(lhs);

    if (!PT_isSymbolLit(symbol)) {
      return ATtrue;
    }
  }

  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_prodHasLexLayoutAsRhs(PT_Production  prod) */

ATbool PT_prodHasLexLayoutAsRhs(PT_Production  prod)
{
  /* This implements: "prod([<list>],lex(layout),<term>)" */
  if (PT_isProductionDefault(prod)) {
    PT_Symbol rhs = PT_getProductionRhs(prod);

    if (PT_isSymbolLex(rhs)) {
      PT_Symbol symbol = PT_getSymbolSymbol(rhs);
      return PT_isSymbolLayout(symbol);
    }
    return ATfalse;
  }

  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_prodHasCfLayoutAsRhs(PT_Production prod) */

ATbool PT_prodHasCfLayoutAsRhs(PT_Production prod)
{
  /* This implements: "prod([<list>],cf(layout),<term>)" */
  if (PT_isProductionDefault(prod)) {
    PT_Symbol rhs = PT_getProductionRhs(prod);

    if (PT_isSymbolCf(rhs)) {
      PT_Symbol symbol = PT_getSymbolSymbol(rhs);
      return PT_isSymbolLayout(symbol);
    }
    return ATfalse;
  }

  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isOptLayoutProd(PT_Production  prod) */

ATbool PT_isOptLayoutProd(PT_Production  prod)
{
  /* This implements: "prod([<list>],cf(opt(layout)),<term>)" */
  if (PT_isProductionDefault(prod)) {
    PT_Symbol rhs = PT_getProductionRhs(prod);
    return PT_isOptLayoutSymbol(rhs);
  }

  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_prodHasVarSymAsRhs(PT_Production prod) */

ATbool PT_prodHasVarSymAsRhs(PT_Production prod)
{
  /* This implements: "prod([<list>],varsym(<str>),no-attrs)" */
  if (PT_isProductionDefault(prod)) {
    PT_Symbol rhs = PT_getProductionRhs(prod);
    return PT_isSymbolVarSym(rhs);
  }

  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isProductionVariable(PT_Production prod) */

ATbool PT_isProductionVariable(PT_Production prod)
{
  /* This implements: "prod([varsym(<term>)],<term>,<term>)" */

  if (PT_isProductionDefault(prod)) {
    PT_Symbols lhs = PT_getProductionLhs(prod);

    if (PT_hasSymbolsHead(lhs)) {
      PT_Symbol lhssym = PT_getSymbolsHead(lhs);
      PT_Symbols tail = PT_getSymbolsTail(lhs);

      if (PT_isSymbolsEmpty(tail)) {
	if (PT_isSymbolCf(lhssym) || PT_isSymbolLex(lhssym)) {
	  lhssym = PT_getSymbolSymbol(lhssym);
	}

	return PT_isSymbolVarSym(lhssym);
      }
    }
  }

  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isLexicalInjectionProd(PT_Production prod) */

ATbool PT_isLexicalInjectionProd(PT_Production prod)
{
  /* This implements: "prod([lex(<term>)],cf(<term>),<term>)" */
  if (PT_isProductionDefault(prod)) {
    PT_Symbols lhs = PT_getProductionLhs(prod);
    PT_Symbol rhs = PT_getProductionRhs(prod);

    if (PT_isSymbolCf(rhs) && PT_hasSymbolsHead(lhs)) {
      PT_Symbol rhsNestedSymbol = PT_getSymbolSymbol(rhs);
      PT_Symbol lhssym = PT_getSymbolsHead(lhs);
      PT_Symbols tail = PT_getSymbolsTail(lhs);
      if (PT_isSymbolsEmpty(tail) && PT_isSymbolLex(lhssym)) {
        PT_Symbol lhsNestedSymbol = PT_getSymbolSymbol(lhssym);
        return PT_isEqualSymbol(rhsNestedSymbol, lhsNestedSymbol);
      }
    }
    return ATfalse;
  }

  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_prodHasIterSepAsRhs(PT_Production prod) */

ATbool PT_prodHasIterSepAsRhs(PT_Production prod)
{
  /* This implements: 
   * "prod([<list>],cf(iter-star-sep(<term>,lit(<str>))),<term>)" and
   * "prod([<list>],cf(iter-sep(<term>,lit(<str>))),<term>)" 
   */
  if (PT_isProductionDefault(prod)) {
    PT_Symbol rhs = PT_getProductionRhs(prod);
    return PT_isIterSepSymbol(rhs);
  }

  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_prodHasIterAsRhs(PT_Production prod) */

ATbool PT_prodHasIterAsRhs(PT_Production prod)
{
  /* This implements: 
   * "prod([<list>],cf(iter-star(<term>,lit(<str>))),<term>)"
   * "prod([<list>],cf(iter(<term>,lit(<str>))),<term>)"
   */
  if (PT_isProductionDefault(prod)) {
    PT_Symbol rhs = PT_getProductionRhs(prod);
    return PT_isIterSymbol(rhs);
  }

  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_prodHasSTARTAsRhs(PT_Production prod) */

ATbool PT_prodHasSTARTAsRhs(PT_Production prod)
{
  /* This implements: 
   * "prod([<list>],sort(\"<START>\"),no-attrs)"
   */
  if (PT_isProductionDefault(prod)) {
    PT_Symbol rhs = PT_getProductionRhs(prod);
    if (PT_isSymbolSort(rhs)) {
      char *startsym = PT_getSymbolString(rhs);
      return strcmp(startsym,"<START>") == 0;
    }
  }

  return ATfalse;
}

/*}}}  */

/* Symbols */
/*{{{  ATbool PT_isIterSepSymbol(PT_Symbol symbol) */

ATbool PT_isIterSepSymbol(PT_Symbol symbol)
{
  /* This implements: 
   * "cf(iter-star-sep(<term>,lit(<str>)))" and
   * "cf(iter-sep(<term>,lit(<str>)))" 
   */
  if (PT_isSymbolCf(symbol) || PT_isSymbolLex(symbol)) {
    PT_Symbol listsym = PT_getSymbolSymbol(symbol);
    return PT_isSymbolIterPlusSep(listsym) || PT_isSymbolIterStarSep(listsym);
  }

  return ATfalse;
}

/*}}}  */
/*{{{  PT_Symbol PT_getIterSepSeparator(PT_Symbol symbol) */

PT_Symbol PT_getIterSepSeparator(PT_Symbol symbol)
{
  PT_Symbol listSymbol = PT_getSymbolSymbol(symbol);
  return PT_getSymbolSeparator(listSymbol);
}

/*}}}  */
/*{{{  ATbool PT_isIterSymbol(PT_Symbol symbol) */

ATbool PT_isIterSymbol(PT_Symbol symbol)
{
  /* This implements: 
   * "cf(iter-star(<term>))"
   * "cf(iter(<term>))"
   */
  if (PT_isSymbolCf(symbol) || PT_isSymbolLex(symbol)) {
    PT_Symbol listsym = PT_getSymbolSymbol(symbol);
    return PT_isSymbolIterPlus(listsym) || PT_isSymbolIterStar(listsym);
  }

  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isOptLayoutSymbol(PT_Symbol symbol) */

ATbool PT_isOptLayoutSymbol(PT_Symbol symbol)
{
  /* This implements: "cf(opt(layout))" */
  if (PT_isSymbolCf(symbol)) {
    PT_Symbol cfsym = PT_getSymbolSymbol(symbol);
    if (PT_isSymbolOpt(cfsym)) {
      PT_Symbol optsym = PT_getSymbolSymbol(cfsym);
      return PT_isSymbolLayout(optsym);
    }
    return ATfalse;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Symbol PT_makeOptLayoutSymbol() */

PT_Symbol PT_makeOptLayoutSymbol()
{
  return PT_makeSymbolCf(PT_makeSymbolOpt(PT_makeSymbolLayout()));
}

/*}}}  */

/*{{{  PT_Symbols PT_foreachSymbolInSymbols(symbols, visitor, data)  */

PT_Symbols PT_foreachSymbolInSymbols(PT_Symbols symbols,
				     PT_SymbolVisitor visitor,
                                     PT_SymbolVisitorData data)
{
  ATermList store;
  PT_Symbols newSymbols = PT_makeSymbolsEmpty();

  /* apply func to each element */
  store = ATempty;
  while (PT_hasSymbolsHead(symbols)) {
    store = ATinsert(store,
                     PT_SymbolToTerm(
                     visitor(PT_getSymbolsHead(symbols), data)));
    if (PT_hasSymbolsTail(symbols)) {
      symbols = PT_getSymbolsTail(symbols);
    }
    else {
      break;
    }
  }

  /* create new list */
  for (; !ATisEmpty(store); store = ATgetNext(store)) {
    PT_Symbol newSymbol = PT_SymbolFromTerm(ATgetFirst(store));
    newSymbols = PT_makeSymbolsMany(newSymbol, newSymbols);
  }

  return newSymbols;
}

/*}}}  */

/*{{{  PT_Symbol makeSymbolAllChars() */

PT_Symbol makeSymbolAllChars()
{
  PT_CharRanges ranges
    = PT_makeCharRangesSingle(PT_makeCharRangeRange(0, 255));

  return PT_makeSymbolIterStar(
           PT_makeSymbolCharClass(ranges));
}  

/*}}}  */

/* Trees */
/*{{{  ATbool PT_isTreeAlt(PT_Tree tree) */

ATbool PT_isTreeAlt(PT_Tree tree)
{
  PT_Production prod;
  PT_Symbol rhs;

  if (PT_hasTreeProd(tree)) {
    prod = PT_getTreeProd(tree);
    rhs = PT_getProductionRhs(prod);
    if (PT_isSymbolCf(rhs) || PT_isSymbolLex(rhs)) {
      rhs = PT_getSymbolSymbol(rhs);
    }

    if (PT_isSymbolAlt(rhs)) {
      return ATtrue;
    }
  }

  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isTreeSeq(PT_Tree tree) */

ATbool PT_isTreeSeq(PT_Tree tree)
{
  PT_Production prod;
  PT_Symbol rhs;

  if (PT_hasTreeProd(tree)) {
    prod = PT_getTreeProd(tree);
    rhs = PT_getProductionRhs(prod);

    if (PT_isSymbolCf(rhs) || PT_isSymbolLex(rhs)) {
      rhs = PT_getSymbolSymbol(rhs);
    }

    if (PT_isSymbolSeq(rhs)) {
      return ATtrue;
    }
  }

  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isTreeOpt(PT_Tree tree) */

ATbool PT_isTreeOpt(PT_Tree tree)
{
  PT_Production prod;
  PT_Symbol rhs;

  if (PT_hasTreeProd(tree)) {
    prod = PT_getTreeProd(tree);
    rhs = PT_getProductionRhs(prod);

    if (PT_isSymbolCf(rhs) || PT_isSymbolLex(rhs)) {
      rhs = PT_getSymbolSymbol(rhs);
    }

    if (PT_isSymbolOpt(rhs)) {
      return ATtrue;
    }
  }

  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isTreeApplList(PT_Tree tree) */

ATbool PT_isTreeApplList(PT_Tree tree)
{
  if (PT_isTreeAppl(tree)) {
    PT_Production prod = PT_getTreeProd(tree);
    return PT_isProductionList(prod);
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isTreeLit(PT_Tree tree) */

ATbool PT_isTreeLit(PT_Tree tree)
{
  if (PT_hasTreeProd(tree)) {
    return PT_isSymbolLit(PT_getProductionRhs(PT_getTreeProd(tree)));
  }
  else {
    return ATfalse;
  }
}

/*}}}  */
/*{{{  ATbool PT_isTreeCiLit(PT_Tree tree) */

ATbool PT_isTreeCilit(PT_Tree tree)
{
  if (PT_hasTreeProd(tree)) {
    return PT_isSymbolCilit(PT_getProductionRhs(PT_getTreeProd(tree)));
  }
  else {
    return ATfalse;
  }
}

/*}}}  */

/*{{{  ATbool PT_isTreeVar(PT_Tree tree)  */

ATbool PT_isTreeVar(PT_Tree tree) 
{
  if (PT_isTreeAppl(tree)) {
    PT_Production prod = PT_getTreeProd(tree);
    if (PT_isProductionVariable(prod)) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isTreeVarList(PT_Tree tree) */

ATbool PT_isTreeVarList(PT_Tree tree)
{
  if (PT_isTreeAppl(tree)) {
    PT_Production prod = PT_getTreeProd(tree);
    if (PT_isProductionVariable(prod)) {
      PT_Symbol rhssym = PT_getProductionRhs(prod);
      if (PT_isSymbolCf(rhssym) || PT_isSymbolLex(rhssym)) {
        PT_Symbol sym = PT_getSymbolSymbol(rhssym);
        return PT_isSymbolIterPlus(sym) 
               || PT_isSymbolIterStar(sym)
               || PT_isSymbolIterPlusSep(sym) 
               || PT_isSymbolIterStarSep(sym);
      }
    }
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isTreeVarListStar(PT_Tree tree) */

ATbool PT_isTreeVarListStar(PT_Tree tree)
{
  if (PT_isTreeAppl(tree)) {
    PT_Production prod = PT_getTreeProd(tree);
    if (PT_isProductionVariable(prod)) {
      PT_Symbol rhssym = PT_getProductionRhs(prod);
      if (PT_isSymbolCf(rhssym) || PT_isSymbolLex(rhssym)) {
        PT_Symbol sym = PT_getSymbolSymbol(rhssym);

	if (PT_isSymbolIterStar(sym) || PT_isSymbolIterStarSep(sym)) {
	  return ATtrue;
	}
      }
    }
  }
  return ATfalse;
}              

/*}}}  */
/*{{{  ATbool PT_isTreeVarListPlus(PT_Tree tree) */

ATbool PT_isTreeVarListPlus(PT_Tree tree)
{
  if (PT_isTreeAppl(tree)) {
    PT_Production prod = PT_getTreeProd(tree);
    if (PT_isProductionVariable(prod)) {
      PT_Symbol rhssym = PT_getProductionRhs(prod);
      if (PT_isSymbolCf(rhssym) || PT_isSymbolLex(rhssym)) {
        PT_Symbol sym = PT_getSymbolSymbol(rhssym);
        return PT_isSymbolIterPlus(sym) 
               || PT_isSymbolIterPlusSep(sym);
      }
    }
  }
  return ATfalse;
}

/*}}}  */

/*{{{  ATbool PT_isTreeBracket(PT_Tree tree) */

ATbool PT_isTreeBracket(PT_Tree tree)
{
  if (PT_isTreeAppl(tree)) {
    PT_Production prod = PT_getTreeProd(tree);
    if (PT_isProductionDefault(prod)) {
      return PT_hasProductionBracketAttr(prod);
    }
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Tree PT_getTreeBracketTree(PT_Tree tree) */

PT_Tree PT_getTreeBracketTree(PT_Tree tree)
{
  if (PT_isTreeBracket(tree)) {
    return PT_getArgsArgumentAt(PT_getTreeArgs(tree),2);
  }
  return NULL;
}

/*}}}  */

/*{{{  PT_Args PT_removeArgsAllLayoutAndAnnotations(PT_Args args) */

PT_Args PT_removeArgsAllLayoutAndAnnotations(PT_Args args)
{
  PT_Args new = PT_makeArgsEmpty();

  for (; !PT_isArgsEmpty(args); args = PT_getArgsTail(args)) {
    new = PT_makeArgsMany(PT_removeTreeAllLayoutAndAnnotations(
		       PT_getArgsHead(args)),
		       new);
  }

  return PT_reverseArgs(new);
}

/*}}}  */
/*{{{  PT_Tree PT_removeTreeAllLayoutAndAnnotations(PT_Tree tree) */

PT_Tree PT_removeTreeAllLayoutAndAnnotations(PT_Tree tree)
{
  if (PT_isTreeLayout(tree)) {
    return PT_makeTreeLayoutEmpty();
  }
  else if (PT_isTreeAmb(tree)) {
    return PT_makeTreeAmb(PT_removeArgsAllLayoutAndAnnotations(
			       PT_getTreeArgs(tree)));
  }
  else if (PT_isTreeAppl(tree)) {
    return PT_makeTreeAppl(PT_getTreeProd(tree),
			   PT_removeArgsAllLayoutAndAnnotations(
				PT_getTreeArgs(tree)));
  }
  else {
    return PT_removeTreeAnnotations(tree);
  }
}

/*}}}  */

/*{{{  PT_Tree PT_findTreeParent(PT_Tree needle, PT_Tree haystack) */

PT_Tree PT_findTreeParent(PT_Tree needle, PT_Tree haystack)
{
  assert(needle != NULL);
  assert(haystack != NULL);

  assert(needle != haystack);

  if (PT_hasTreeArgs(haystack)) {
    PT_Args children = PT_getTreeArgs(haystack);
    while (!PT_isArgsEmpty(children)) {
      PT_Tree child = PT_getArgsHead(children);
      if (PT_isEqualTree(child, needle)) {
	return haystack;
      }
      else {
	PT_Tree suspect = PT_findTreeParent(needle, child);
	if (suspect != NULL) {
	  return suspect;
	}
      }
      children = PT_getArgsTail(children);
    }
  }

  return NULL;
}

/*}}}  */

/* This function does not support the full SDF literal notation */
/*{{{  PT_Tree PT_makeTreeLit(const char* string) */

PT_Tree PT_makeTreeLit(const char* string)
{
  int len = strlen(string);
  int i;
  PT_Args args = PT_makeArgsEmpty();
  PT_Symbols symbols = PT_makeSymbolsEmpty();
  PT_Symbol symbol = PT_makeSymbolLit(string);
  PT_Attributes attrs = PT_makeAttributesNoAttrs();
  PT_Production prod;

  for (i = len - 1; i >= 0; i--) {
    PT_Tree arg;
    PT_Symbol symbol;

    arg = PT_makeTreeChar(string[i]);
    args = PT_makeArgsMany(arg, args);

    symbol = PT_makeSymbolCharClass(
	      PT_makeCharRangesSingle(
	        PT_makeCharRangeCharacter(string[i])));
    symbols = PT_makeSymbolsMany(symbol, symbols);
  }

  prod = PT_makeProductionDefault(symbols, symbol, attrs);

  return PT_makeTreeAppl(prod, args);
}

/*}}}  */
/*{{{  PT_Tree PT_makeTreeCilit(const char* string) */

PT_Tree PT_makeTreeCilit(const char* string)
{
  int len = strlen(string);
  int i;
  PT_Args args = PT_makeArgsEmpty();
  PT_Symbols symbols = PT_makeSymbolsEmpty();
  PT_Symbol symbol = PT_makeSymbolCilit(string);
  PT_Attributes attrs = PT_makeAttributesNoAttrs();
  PT_Production prod;

  for (i = len - 1; i >= 0; i--) {
    PT_Tree arg;
    PT_Symbol symbol;

    arg = PT_makeTreeChar(string[i]);
    args = PT_makeArgsMany(arg, args);

    if (string[i] >= 'A' && string[i] <= 'Z') {
      PT_CharRanges range1 =  PT_makeCharRangesSingle(              
	                         PT_makeCharRangeCharacter(string[i]));
      PT_CharRanges range2 =  PT_makeCharRangesSingle(              
	                         PT_makeCharRangeCharacter(string[i]+
							   ('a' - 'A')));
      symbol = PT_makeSymbolCharClass(PT_concatCharRanges(range1,range2));
    }
    else if (string[i] >= 'a' && string[i] <= 'z') {
      PT_CharRanges range1 =  PT_makeCharRangesSingle(              
	                         PT_makeCharRangeCharacter(string[i]));
      PT_CharRanges range2 =  PT_makeCharRangesSingle(              
	                         PT_makeCharRangeCharacter(string[i]-
							   ('a' - 'A')));
      symbol = PT_makeSymbolCharClass(PT_concatCharRanges(range2,range1));
    }
    else {
      symbol = PT_makeSymbolCharClass(
	         PT_makeCharRangesSingle(
	           PT_makeCharRangeCharacter(string[i])));
    }

    symbols = PT_makeSymbolsMany(symbol, symbols);
  }

  prod = PT_makeProductionDefault(symbols, symbol, attrs);

  return PT_makeTreeAppl(prod, args);
}

/*}}}  */

/* Args */
/*{{{  PT_Args PT_foreachTreeInArgs(PT_Args args, PT_TreeVisitor visitor, */

PT_Args PT_foreachTreeInArgs(PT_Args args, PT_TreeVisitor visitor,
                             PT_TreeVisitorData data)
{
  ATermList store;
  PT_Args newArgs = PT_makeArgsEmpty();

  /* apply func to each element */
  for (store = ATempty;
      PT_hasArgsHead(args);
      args = PT_getArgsTail(args)) {
    store = ATinsert(store,
                     PT_TreeToTerm(
                     visitor(PT_getArgsHead(args),data)));
  }

  /* create new list */
  for (; !ATisEmpty(store); store = ATgetNext(store)) {
    PT_Tree newTree = PT_TreeFromTerm(ATgetFirst(store));
    newArgs = PT_makeArgsMany(newTree, newArgs);
  }

  return newArgs;
}

/*}}}  */   
/*{{{  PT_Tree PT_getArgsArgumentAt(PT_Args args, int arg_nr) */

PT_Tree PT_getArgsArgumentAt(PT_Args args, int arg_nr)
{
  ATermList arg_list = (ATermList)PT_ArgsToTerm(args);
  ATerm arg = ATelementAt(arg_list, arg_nr);
  return PT_TreeFromTerm(arg);
}

/*}}}  */
/*{{{  PT_Args PT_setArgsArgumentAt(PT_Args args, PT_Tree arg, int arg_nr) */

PT_Args PT_setArgsArgumentAt(PT_Args args, PT_Tree arg, int arg_nr)
{
  ATermList arg_list = (ATermList)PT_ArgsToTerm(args);
  arg_list = ATreplace(arg_list, PT_TreeToTerm(arg), arg_nr);
  return PT_ArgsFromTerm((ATerm)arg_list);
}

/*}}}  */

/*{{{  PT_Tree PT_makeTreeLayoutEmpty() */

PT_Tree PT_makeTreeLayoutEmpty()
{
  PT_Symbol layoutSymbol = PT_makeSymbolCf(
                             PT_makeSymbolOpt(PT_makeSymbolLayout()));
  PT_Production optLayoutProd = PT_makeProductionDefault(
                                  PT_makeSymbolsEmpty(),
                                  layoutSymbol,
                                  PT_makeAttributesNoAttrs());
  return PT_makeTreeAppl(optLayoutProd, PT_makeArgsEmpty());
}

/*}}}  */
/*{{{  PT_Tree PT_makeTreeLayoutNonEmpty(PT_Args args) */

PT_Tree PT_makeTreeLayoutNonEmpty(PT_Args args)
{
  PT_Symbol layoutSymbolRhs = PT_makeSymbolCf(
                                PT_makeSymbolOpt(PT_makeSymbolLayout()));
  PT_Symbol layoutSymbolLhs = PT_makeSymbolCf(PT_makeSymbolLayout());
  PT_Symbols layoutLhs = PT_makeSymbolsSingle(layoutSymbolLhs);
  PT_Production optLayoutProd = PT_makeProductionDefault(
                                  layoutLhs,
                                  layoutSymbolRhs,
                                  PT_makeAttributesNoAttrs());
  return PT_makeTreeAppl(optLayoutProd, args);
}

/*}}}  */
/*{{{  PT_Tree PT_makeTreeLayoutFromString(const char *str) */

PT_Tree PT_makeTreeLayoutFromString(const char *str)
{
  PT_Args args = PT_makeArgsEmpty();
  int i;

  for (i = strlen(str) -1; i >= 0; i--) {
    args = PT_makeArgsMany(PT_makeTreeChar((int) str[i]), args);
  }

  return PT_makeTreeLayoutNonEmpty(args);
}

/*}}}  */
/*{{{  PT_Tree PT_makeTreeLexToCf(PT_Symbol sym, PT_Tree tree) */

PT_Tree PT_makeTreeLexToCf(PT_Symbol sym, PT_Tree tree)
{
  PT_Symbol lexSymbol = PT_makeSymbolLex(sym);
  PT_Symbol cfSymbol = PT_makeSymbolCf(sym);
  PT_Symbols lhs = PT_makeSymbolsSingle(lexSymbol);
  PT_Attributes noattrs = PT_makeAttributesNoAttrs();
  PT_Production prod = PT_makeProductionDefault(lhs, cfSymbol, noattrs);
  PT_Args args = PT_makeArgsSingle(tree);

  return PT_makeTreeAppl(prod, args);
}

/*}}}  */
/*{{{  ATbool PT_isTreeLayout(PT_Tree tree) */

ATbool PT_isTreeLayout(PT_Tree tree)
{
  if (PT_isTreeAppl(tree)) {
    PT_Production prod = PT_getTreeProd(tree);
    return PT_isOptLayoutProd(prod);
  }

  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isTreeLexical(PT_Tree tree) */

ATbool PT_isTreeLexical(PT_Tree tree)
{
  if (PT_isTreeAppl(tree)) {
    PT_Production prod = PT_getTreeProd(tree);
    PT_Symbol rhs = PT_getProductionRhs(prod);

    return PT_isSymbolLex(rhs);
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isTreeLexicalInjection(PT_Tree tree) */

ATbool PT_isTreeLexicalInjection(PT_Tree tree)
{
  if (PT_hasTreeProd(tree)) {
    PT_Production prod = PT_getTreeProd(tree);

    return PT_isLexicalInjectionProd(prod);
  }

  return ATfalse;
}

/*}}}  */

/*{{{  PT_Args PT_removeArgsLiterals(PT_Args args) */

PT_Args PT_removeArgsLiterals(PT_Args args)
{
  /* This function removes any elements that are literal trees
   */
  PT_Args new = PT_makeArgsEmpty();

  for ( ; !PT_isArgsEmpty(args); args = PT_getArgsTail(args)) {
    PT_Tree arg = PT_getArgsHead(args);

    if (!PT_isTreeLit(arg)) {
      new = PT_makeArgsMany(arg, new);
    }
  }

  return PT_reverseArgs(new);
}

/*}}}  */

/* ATerm annotations */
/*{{{  ATerm PT_getTreeAnnotations(PT_Tree tree) */

ATerm PT_getTreeAnnotations(PT_Tree tree)
{
  return AT_getAnnotations((ATerm) tree);
}

/*}}}  */
/*{{{  PT_Tree PT_setTreeAnnotations(PT_Tree tree, ATerm annos) */

PT_Tree PT_setTreeAnnotations(PT_Tree tree, ATerm annos)
{
  return (PT_Tree)AT_setAnnotations((ATerm) tree, annos);
}

/*}}}  */
/*{{{  PT_Tree PT_removeTreeAnnotations(PT_Tree arg) */

PT_Tree PT_removeTreeAnnotations(PT_Tree arg)
{
  ATerm atArg = PT_TreeToTerm(arg);

  if (AT_getAnnotations(atArg) != NULL) {
    atArg = AT_removeAnnotations(atArg);
  }

  return PT_TreeFromTerm(atArg);
}

/*}}}  */
/*{{{  ATerm PT_getTreeAnnotation(PT_Tree tree, ATerm key) */

ATerm PT_getTreeAnnotation(PT_Tree tree, ATerm key)
{
  ATerm atTree = PT_TreeToTerm(tree);

  return ATgetAnnotation(atTree, key);
}
                                                                                /*}}}  */  
/*{{{  PT_Tree PT_setTreeAnnotation(PT_Tree tree, ATerm key, ATerm value) */

PT_Tree PT_setTreeAnnotation(PT_Tree tree, ATerm key, ATerm value)
{
  ATerm t = PT_TreeToTerm(tree);

  t = ATsetAnnotation(t, key, value);

  return PT_TreeFromTerm(t);
}

/*}}}  */
/*{{{  ATerm PT_getParseTreeAnnotation(PT_ParseTree parse_tree, ATerm key) */

ATerm PT_getParseTreeAnnotation(PT_ParseTree parse_tree, ATerm key)
{
  ATerm atParseTree = PT_ParseTreeToTerm(parse_tree);

  return ATgetAnnotation(atParseTree, key);
}

/*}}}  */
/*{{{  PT_ParseTree PT_setParseTreeAnnotation(parse_tree, ATerm key, ATerm value) */

PT_ParseTree PT_setParseTreeAnnotation(PT_ParseTree parse_tree, ATerm key, ATerm value)
{
  ATerm t = PT_ParseTreeToTerm(parse_tree);

  t = ATsetAnnotation(t, key, value);

  return PT_ParseTreeFromTerm(t);
}

/*}}}  */
/*{{{  ATermList PT_getParseTreeAnnotations(PT_ParseTree pt) */

ATerm PT_getParseTreeAnnotations(PT_ParseTree pt)
{
  return AT_getAnnotations((ATerm) pt);
}

/*}}}  */

/* Length annotations */
/*{{{  static PT_Args annotateAmbArgsWithLength(PT_Args args, int *length) */
 
static PT_Tree annotateTreeWithLength(PT_Tree tree, int *length);

static PT_Args annotateAmbArgsWithLength(PT_Args args, int *length)
{
  PT_Tree head;
  PT_Args tail;
  int head_length, tail_length;
 
  if (PT_isArgsEmpty(args)) {
    *length = 0;
    return args;
  }
 
  head = PT_getArgsHead(args);
  tail = PT_getArgsTail(args);
 
  head = annotateTreeWithLength(head, &head_length);
  tail = annotateAmbArgsWithLength(tail, &tail_length);

  *length = head_length;

  return PT_makeArgsMany(head, tail);
}

/*}}}  */
/*{{{  static PT_Args annotateArgsWithLength(PT_Args args, int *length) */

static PT_Args annotateArgsWithLength(PT_Args args, int *length)
{
  PT_Tree head;
  PT_Args tail;
  int head_length, tail_length;

  if (PT_isArgsEmpty(args)) {
    *length = 0;
    return args;
  }

  head = PT_getArgsHead(args);
  tail = PT_getArgsTail(args);

  head = annotateTreeWithLength(head, &head_length);
  tail = annotateArgsWithLength(tail, &tail_length);

  *length = head_length + tail_length;

  return PT_makeArgsMany(head, tail);
}

/*}}}  */
/*{{{  static PT_Tree annotateTreeWithLength(PT_Tree tree, int *length) */

static PT_Tree annotateTreeWithLength(PT_Tree tree, int *length)
{
  if (PT_isTreeChar(tree)) {
    *length = 1;
  }
  else if (PT_isTreeAmb(tree)) {
    PT_Args args = PT_getTreeArgs(tree);
    args = annotateAmbArgsWithLength(args, length);
    tree = PT_setTreeArgs(tree, args);
    tree = PT_setTreeAnnotation(tree, ATparse(ANNO_LENGTH),
                                ATmake("<int>", *length));
  }
  else if (PT_hasTreeArgs(tree)) {
    PT_Args args = PT_getTreeArgs(tree);
    args = annotateArgsWithLength(args, length);
    tree = PT_setTreeArgs(tree, args);
    tree = PT_setTreeAnnotation(tree, ATparse(ANNO_LENGTH),
                                ATmake("<int>", *length));
  }
  else {
    ATabort("annotateTreeWithLength: unknown tree type: %t\n", 
            PT_TreeToTerm(tree));
  }
  return tree;
}

/*}}}  */
/*{{{  PT_Tree PT_annotateTreeWithLength(PT_Tree tree) */

PT_Tree PT_annotateTreeWithLength(PT_Tree tree)
{
  int length;

  return annotateTreeWithLength(tree, &length);
}

/*}}}  */
/*{{{  PT_ParseTree PT_annotateParseTreeWithLength(PT_ParseTree parse_tree) */

PT_ParseTree PT_annotateParseTreeWithLength(PT_ParseTree parse_tree)
{
  int length;

  PT_Tree tree = PT_getParseTreeTop(parse_tree);
  tree = PT_annotateTreeWithLength(tree);
  parse_tree = PT_setParseTreeTop(parse_tree, tree);

  length = PT_getTreeLengthAnno(tree);

  parse_tree = PT_setParseTreeLengthAnno(parse_tree, length);

  return parse_tree;
}

/*}}}  */
/*{{{  int PT_getParseTreeLengthAnno(PT_ParseTree parse_tree) */

int PT_getParseTreeLengthAnno(PT_ParseTree parse_tree)
{
  ATerm anno = PT_getParseTreeAnnotation(parse_tree, ATparse(ANNO_LENGTH));

  assert(anno && ATgetType(anno) == AT_INT);

  return ATgetInt((ATermInt)anno);
}

/*}}}  */ 
/*{{{  PT_ParseTree PT_setParseTreeLengthAnno(PT_ParseTree parse_tree, int length) */

PT_ParseTree PT_setParseTreeLengthAnno(PT_ParseTree parse_tree, int length)
{
  return PT_setParseTreeAnnotation(parse_tree, ATparse(ANNO_LENGTH),
                                   (ATerm)ATmakeInt(length));
}

/*}}}  */
/*{{{  int PT_getTreeLengthAnno(PT_Tree tree) */

int PT_getTreeLengthAnno(PT_Tree tree)
{
  if (PT_isTreeChar(tree)) {
    return 1;
  } 
  else {
    ATerm anno = PT_getTreeAnnotation(tree, ATparse(ANNO_LENGTH));
    assert(anno);
    return ATgetInt((ATermInt)anno);
  }
}

/*}}}  */ 
/*{{{  PT_Tree PT_setTreeLengthAnno(PT_Tree tree, int length) */

PT_Tree PT_setTreeLengthAnno(PT_Tree tree, int length)
{
  return PT_setTreeAnnotation(tree, ATparse(ANNO_LENGTH),
                             (ATerm)ATmakeInt(length));
}

/*}}}  */

/* Production Attributes */
/*{{{  PT_Attrs PT_foreachAttrInAttrs(PT_Attrs attrs, PT_AttrVisitor visitor, */

PT_Attrs PT_foreachAttrInAttrs(PT_Attrs attrs, PT_AttrVisitor visitor,
                               PT_AttrVisitorData data)
{
  ATermList store;
  PT_Attrs newAttrs;

  /* apply func to each element */
  store = ATempty;
  while (PT_hasAttrsHead(attrs)) {
    store = ATinsert(store,
                     PT_AttrToTerm(
                     visitor(PT_getAttrsHead(attrs), data)));
    if (PT_hasAttrsTail(attrs)) {
      attrs = PT_getAttrsTail(attrs);
    }
    else {
      break;
    }
  }        

  if (ATisEmpty(store)) {
    ATabort("PT_foreachAttrInAttrs: plus list contains no elements");
    return (PT_Attrs) NULL;
  }

  newAttrs = PT_makeAttrsSingle(PT_AttrFromTerm(ATgetFirst(store)));
  store = ATgetNext(store);

  /* create new list */
  for (; !ATisEmpty(store); store = ATgetNext(store)) {
    PT_Attr newAttr = PT_AttrFromTerm(ATgetFirst(store));
    newAttrs = PT_makeAttrsMany(newAttr,newAttrs);
  }

  return newAttrs;
}

/*}}}  */   
/*{{{  static PT_Attr PT_matchAttr(PT_Attr attr, PT_AttrVisitorData data) */

/*{{{  typedef struct PT_BoolAttrTuple_Tag */

typedef struct PT_BoolAttrTuple_Tag {
  ATbool bool;
  PT_Attr attr;
} PT_BoolAttrTuple;


/*}}}  */

static PT_Attr PT_matchAttr(PT_Attr attr, PT_AttrVisitorData data)
{
  if (PT_isEqualAttr(((PT_BoolAttrTuple*)data)->attr,attr)) {
    ((PT_BoolAttrTuple*)data)->bool = ATtrue;
  }

  return attr;
}           

/*}}}  */
/*{{{  ATbool PT_hasProductionCertainAttr(PT_Production prod, PT_Attr attr) */

ATbool PT_hasProductionCertainAttr(PT_Production prod, PT_Attr attr)
{
  PT_Attributes attributes = PT_getProductionAttributes(prod);
  PT_Attrs attrs;
  PT_BoolAttrTuple data;

  if (PT_isProductionDefault(prod)) {
    if (PT_isAttributesNoAttrs(attributes)) {
      return ATfalse;
    }

    attrs = PT_getAttributesAttrs(attributes);

    data.bool = ATfalse;
    data.attr = attr;

    PT_foreachAttrInAttrs(attrs, PT_matchAttr, (PT_AttrVisitorData)&data);    

    return data.bool;
  }

  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_hasProductionBracketAttr(PT_Production prod) */

ATbool PT_hasProductionBracketAttr(PT_Production prod)
{
  return PT_hasProductionCertainAttr(prod, PT_makeAttrBracket());
}

/*}}}  */
/*{{{  ATbool PT_hasProductionMemoAttr(PT_Production prod) */

ATbool PT_hasProductionMemoAttr(PT_Production prod)
{
  return PT_hasProductionCertainAttr(prod, PT_makeAttrTerm(ATparse("memo")));
}

/*}}}  */   
/*{{{  ATbool PT_hasProductionTraversalAttribute(PT_Production prod) */

ATbool PT_hasProductionTraversalAttribute(PT_Production prod)
{
  return PT_hasProductionCertainAttr(prod, 
				     PT_makeAttrTerm(ATparse("traversal")));
}

/*}}}  */       
/*{{{  ATbool PT_hasProductionLexicalConstructorAttr(PT_Production prod) */

ATbool PT_hasProductionLexicalConstructorAttr(PT_Production prod)
{
  return PT_hasProductionCertainAttr(prod, 
				     PT_makeAttrTerm(ATparse("lexical-constructor")));
}

/*}}}  */       
/*{{{  ATbool PT_hasProductionConstructorAttr(PT_Production prod) */

ATbool PT_hasProductionConstructorAttr(PT_Production prod)
{
  return PT_hasProductionCertainAttr(prod, 
				     PT_makeAttrTerm(ATparse("constructor")));
}

/*}}}  */       

/* Parse trees */
/*{{{  PT_ParseTree PT_makeParseTree(PT_Tree tree) */
PT_ParseTree PT_makeValidParseTreeFromTree(PT_Tree tree)
{
  PT_Tree origTree = tree;
  PT_Production prod;
  PT_Symbol rhs;
  PT_Symbols lhs;

  if (PT_isTreeAmb(tree)) {
    PT_Args ambs = PT_getTreeArgs(tree);
    tree = PT_getArgsHead(ambs);
  }

  prod = PT_getTreeProd(tree);
  rhs = PT_getProductionRhs(prod);
  lhs = PT_makeSymbolsMany(PT_makeOptLayoutSymbol(),
		  PT_makeSymbolsMany(
			  rhs,
			  PT_makeSymbolsSingle(PT_makeOptLayoutSymbol())));

  return PT_makeParseTreeTree(lhs,
                              PT_makeTreeLayoutEmpty(),
                              origTree,
                              PT_makeTreeLayoutEmpty(), 0);
}

/*}}}  */
/*{{{  PT_ParseTree PT_makeParseTreeTree(PT_Symbols lhs, PT_Tree wsBefore,  */

PT_ParseTree PT_makeParseTreeTree(PT_Symbols lhs, PT_Tree wsBefore, 
				  PT_Tree tree, PT_Tree wsAfter, int ambs)
{
  PT_Production prod;
  PT_Symbol rhs;
  PT_Args args;
  PT_Tree top;

  rhs = PT_makeSymbolSort("<START>");
  prod = PT_makeProductionDefault(lhs, rhs, PT_makeAttributesNoAttrs());

  args = PT_makeArgsMany(wsBefore, 
			 PT_makeArgsMany(tree,
					 PT_makeArgsSingle(wsAfter)));

  top = PT_makeTreeAppl(prod, args);

  return PT_makeParseTreeTop(top, ambs);
}

/*}}}  */
/*{{{  PT_Tree PT_getParseTreeTree(PT_ParseTree parsetree) */

PT_Tree PT_getParseTreeTree(PT_ParseTree parsetree)
{
  PT_Tree top;
  PT_Args args;
  
  top = PT_getParseTreeTop(parsetree);
  
  if (PT_isTreeAmb(top)) {
    return top;
  }

  args = PT_getTreeArgs(top);

  return PT_getArgsArgumentAt(args, 1);
}

/*}}}  */
/*{{{  PT_Tree PT_getParseTreeLayoutBeforeTree(PT_ParseTree parsetree) */

PT_Tree PT_getParseTreeLayoutBeforeTree(PT_ParseTree parsetree)
{
  PT_Tree top = PT_getParseTreeTop(parsetree);
  PT_Args args = PT_getTreeArgs(top);

  return PT_getArgsArgumentAt(args, 0);
}

/*}}}  */
/*{{{  PT_Tree PT_getParseTreeLayoutAfterTree(PT_ParseTree parsetree) */

PT_Tree PT_getParseTreeLayoutAfterTree(PT_ParseTree parsetree)
{
  PT_Tree top = PT_getParseTreeTop(parsetree);
  PT_Args args = PT_getTreeArgs(top);

  return PT_getArgsArgumentAt(args, 2);
}

/*}}}  */
/*{{{  PT_ParseTree PT_setParseTreeTree(PT_ParseTree parsetree, PT_Tree tree) */

PT_ParseTree PT_setParseTreeTree(PT_ParseTree parsetree, PT_Tree tree)
{
  PT_Tree top = PT_getParseTreeTop(parsetree);
  PT_Args args = PT_getTreeArgs(top);

  args = PT_setArgsArgumentAt(args, tree, 1);
  top = PT_setTreeArgs(top, args);

  return PT_setParseTreeTop(parsetree, top);
}

/*}}}  */
/*{{{  PT_ParseTree PT_setParseTreeLayoutBeforeTree(PT_ParseTree parsetree, PT_Tree tree) */

PT_ParseTree PT_setParseTreeLayoutBeforeTree(PT_ParseTree parsetree, PT_Tree tree)
{
  PT_Tree top = PT_getParseTreeTop(parsetree);
  PT_Args args = PT_getTreeArgs(top);

  args = PT_setArgsArgumentAt(args, tree, 0);
  top = PT_setTreeArgs(top, args);

  return PT_setParseTreeTop(parsetree, top);
}

/*}}}  */
/*{{{  PT_ParseTree PT_setParseTreeTree(PT_ParseTree parsetree, PT_Tree tree) */

PT_ParseTree PT_setParseTreeLayoutAfterTree(PT_ParseTree parsetree, PT_Tree tree)
{
  PT_Tree top = PT_getParseTreeTop(parsetree);
  PT_Args args = PT_getTreeArgs(top);

  args = PT_setArgsArgumentAt(args, tree, 2);
  top = PT_setTreeArgs(top, args);

  return PT_setParseTreeTop(parsetree, top);
}

/*}}}  */

/* replace all layout algorithm */

/*{{{  PT_Args PT_replaceArgsLayout(PT_Args args, PT_Tree layout) */

PT_Args PT_replaceArgsLayout(PT_Args args, PT_Tree layout)
{
  PT_Args result = PT_makeArgsEmpty();

  for ( ; !PT_isArgsEmpty(args); args = PT_getArgsTail(args)) {
    PT_Tree head = PT_getArgsHead(args);

    if (PT_isTreeLayout(head)) {
      head = layout;
    }
    else {
      head = PT_replaceTreeLayout(head, layout);
    }



    result = PT_makeArgsMany(head, result);
  }

  return PT_reverseArgs(result);
}

/*}}}  */
/*{{{  PT_Tree PT_replaceTreeLayout(PT_Tree tree, PT_Tree layout) */

PT_Tree PT_replaceTreeLayout(PT_Tree tree, PT_Tree layout)
{
  if (PT_hasTreeArgs(tree)) {
    PT_Args args = PT_getTreeArgs(tree);

    args = PT_replaceArgsLayout(args, layout);

    tree = PT_setTreeArgs(tree, args);
  }

  return tree;
}

/*}}}  */
/*{{{  PT_ParseTree PT_replaceParseTreeLayout(PT_ParseTree tree, PT_Tree layout) */

PT_ParseTree PT_replaceParseTreeLayout(PT_ParseTree tree, PT_Tree layout)
{
  PT_Tree top = PT_getParseTreeTop(tree);

  top = PT_replaceTreeLayout(top, layout);

  return PT_setParseTreeTop(tree, top);
}

/*}}}  */
