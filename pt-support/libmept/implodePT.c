/*
    $Id$  
*/

#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "MEPT-utils.h"

ATbool interpret_cons = ATfalse;
ATbool remove_layout = ATfalse;
ATbool lexical_to_string = ATtrue;
ATbool remove_literals = ATfalse;
ATbool remove_injections = ATfalse;
ATbool remove_parsetree = ATfalse;
ATbool implode_lexicals = ATfalse;
ATbool keep_annotations = ATtrue;

static ATerm implodeTerm(PT_Tree t);
static ATerm implodeLayout(PT_Tree t);
static ATerm implodeVar(PT_Tree t);
static ATerm implodeProd(PT_Production prod, ATermList args);

static ATermList implodeArgs(PT_Args args)
{
  ATerm newTerm;

  if (PT_isArgsEmpty(args)) {
    return ATempty;
  }

  newTerm = implodeTerm(PT_getArgsHead(args));
  if (newTerm) {
    return ATinsert(implodeArgs(PT_getArgsTail(args)),newTerm);
  }
  else {
    return implodeArgs(PT_getArgsTail(args));
  }
}

static PT_Production removeLayoutFromProd(PT_Production prod)
{
  if (PT_isProductionDefault(prod)) {
    PT_Symbols newSymbols = PT_makeSymbolsEmpty();
    PT_Symbols symbols = PT_getProductionLhs(prod);
    while (PT_hasSymbolsHead(symbols)) {
      PT_Symbol symbol = PT_getSymbolsHead(symbols);
      symbols = PT_getSymbolsTail(symbols);

      if (!PT_isOptLayoutSymbol(symbol)) {
        newSymbols = PT_appendSymbols(newSymbols,symbol);
      }
    }
  
    return PT_setProductionLhs(prod, newSymbols);
  }

  return prod;
}

static PT_Production removeLiteralsFromProd(PT_Production prod)
{
  if (PT_isProductionDefault(prod)) {
    PT_Symbols newSymbols = PT_makeSymbolsEmpty();
    PT_Symbols symbols = PT_getProductionLhs(prod);
    while (PT_hasSymbolsHead(symbols)) {
      PT_Symbol symbol = PT_getSymbolsHead(symbols);
      symbols = PT_getSymbolsTail(symbols);

      if (!PT_isSymbolLit(symbol)) {
        newSymbols = PT_appendSymbols(newSymbols,symbol);
      }
    }
  
    return PT_setProductionLhs(prod, newSymbols);
  }

  return prod;
}

static ATerm implodeProd(PT_Production prod, ATermList args)
{
  if (interpret_cons) {
    PT_Attributes attrs = PT_getProductionAttributes(prod);
    
    if (!PT_isAttributesNoAttrs(attrs)) {
      PT_Attrs attrList = PT_getAttributesAttrs(attrs);

      while(PT_hasAttrsHead(attrList)) {
        PT_Attr attr = PT_getAttrsHead(attrList);
        attrList = PT_getAttrsTail(attrList);

        if (PT_isAttrTerm(attr)) {
          ATerm term = PT_getAttrTerm(attr);
          char *constructor;
          if (ATmatch(term, "cons(<str>)", &constructor)) {
            AFun acons = ATmakeAFun(constructor, ATgetLength(args), ATfalse);
            return (ATerm)ATmakeApplList(acons,args);
          }
        }
      }
    }
  }



  if (remove_layout) {
    prod = removeLayoutFromProd(prod);
  }

  if (remove_literals) {
    prod = removeLiteralsFromProd(prod);
  }

  if (PT_isProductionInjection(prod) && remove_injections) {
    assert(ATgetLength(args) == 1);
    return ATgetFirst(args);
  }

  return ATmake("appl(<term>,[<list>])", 
		PT_makeTermFromProduction(prod), args);
}

static ATerm implodeLayout(PT_Tree tree)
{
  if (!remove_layout) {
    return ATmake("layout([<str>])>", PT_yieldTree(tree));
  }
  else {
    return NULL;
  }
}

static ATerm implodeFlatList(PT_Tree tree)
{
  PT_Args args = PT_getTreeArgs(tree);
  ATermList newList = implodeArgs(args);
  
  return ATmake("<term>", newList);
}

static ATerm implodeListInjection(PT_Tree tree)
{
  ATermList newList;
  ATerm newTerm;

  PT_Tree arg = PT_getArgsHead(PT_getTreeArgs(tree));
  PT_Production prod = PT_getTreeProd(arg);

  if (PT_isProductionList(prod)) {
    newList = implodeArgs(PT_getTreeArgs(arg));
  
    return ATmake("<term>", newList);
  }
  else {
    newTerm = implodeTerm(arg);

    return ATmake("[<term>]", newTerm);
  }
}

static ATerm implodeLexical(PT_Tree tree)
{
  if (implode_lexicals) {
    return ATmake("<str>", PT_yieldTree(tree));
  }

  return PT_makeTermFromTree(tree);
}

static ATerm implodeLiteral(PT_Tree tree)
{
  if (remove_literals) {
    return NULL;
  }

  return PT_makeTermFromTree(tree);
}

static ATerm implodeAlt(PT_Tree tree)
{
  ATwarning("WARNING: Alternatives not supported by implodePT\n");

  return PT_makeTermFromTree(tree);
}

static ATerm implodeSeq(PT_Tree tree)
{
  ATwarning("WARNING: Alternatives not supported by implodePT\n");

  return PT_makeTermFromTree(tree);
}

static ATerm implodeVar(PT_Tree tree)
{
  return PT_makeTermFromTree(tree);
}

static ATerm implodeApplication(PT_Tree tree)
{
  PT_Production prod = PT_getTreeProd(tree);
  PT_Args       args = PT_getTreeArgs(tree);
  ATermList     newList;
   
  if (PT_isOptLayoutProd(prod)) {
    return implodeLayout(tree);
  }

  if (PT_isVarDefault(prod)) {
    return implodeVar(tree);
  }

  if (PT_isProductionList(prod)) {
    return implodeFlatList(tree);
  }

  newList = implodeArgs(args);
  return implodeProd(prod, newList);
}

static ATerm implodeTerm(PT_Tree tree)
{
  PT_Args args;
  ATerm result = NULL;
  ATerm annos = ATgetAnnotations((ATerm)tree);
  tree = (PT_Tree) ATremoveAnnotations((ATerm) tree);

  if (PT_isTreeAmb(tree)) {
    args = PT_getTreeArgs(tree);
    result = ATmake("amb(<list>)", implodeArgs(args));
  }
  else if (PT_isTreeLexical(tree)) {
    result = implodeLexical(tree);
  }
  else if (PT_isTreeLit(tree)) { 
    result = implodeLiteral(tree);
  }                        
  else if (PT_isTreeListInjection(tree)) {
    result = implodeListInjection(tree);
  }
  else if (PT_isTreeAlt(tree)) {
    result = implodeAlt(tree);
  }
  else if (PT_isTreeSeq(tree)) {
    result = implodeSeq(tree);
  }
  else if (PT_isTreeAppl(tree)) {
    result = implodeApplication(tree);
  }
  else {
    ATerror("implodeTerm: not an application term: %t\n", tree);
    return NULL;
  }

  if (keep_annotations && result && annos) {
    result = ATsetAnnotations(result, annos);
  }

  return result;
}

ATerm implodeParseTree(PT_ParseTree tree)
{
  ATerm atermTree;

  if (PT_isParseTreeTree(tree)) {
    PT_Tree newTree = PT_getParseTreeTop(tree);
    int     ambs = PT_getParseTreeAmbCnt(tree);

    atermTree = implodeTerm(newTree);

    if (remove_parsetree) {
      return atermTree;
    }
    else {
      return ATmake("parsetree(<term>,<int>)", atermTree, ambs);
    }
  }

  ATerror("implodeParseTree: not a parsetree: %t\n", tree);
  return NULL;
}
