/*

    MEPT -- The Meta-Environment Parse Tree library

    Copyright (C) 2001  Stichting Mathematisch Centrum, Amsterdam,
                        The Netherlands.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

    $Id$
*/

#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "MEPT-utils.h"

#define ANNO_LENGTH "length"  

ATbool PT_prodHasLitAsRhs(PT_Production prod)
{
  /* This implements: "prod([<list>],lit(<str>),no-attrs)" */
  if (PT_isProductionDefault(prod)) {
    PT_Symbol rhs = PT_getProductionRhs(prod);

    return PT_isSymbolLit(rhs);
  }

  ATerror("PT_prodHasLitAsRhs: not a production: %t\n", prod);
  return ATfalse;
}

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

  ATerror("PT_prodHasLexSortAsRhs: not a production: %t\n", prod);
  return ATfalse;
}

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

  ATerror("PT_prodHasLexLayoutAsRhs: not a production: %t\n", prod);
  return ATfalse;
}

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

  ATerror("PT_prodHasCfLayoutAsRhs: not a production: %t\n", prod);
  return ATfalse;
}

ATbool PT_isOptLayoutProd(PT_Production  prod)
{
  /* This implements: "prod([<list>],cf(opt(layout)),<term>)" */
  if (PT_isProductionDefault(prod)) {
    PT_Symbol rhs = PT_getProductionRhs(prod);
    return PT_isOptLayoutSymbol(rhs);
  }

  ATerror("PT_isOptLayoutProd: not a production: %t\n", prod);
  return ATfalse;
}

ATbool PT_prodHasVarSymAsRhs(PT_Production prod)
{
  /* This implements: "prod([<list>],varsym(<str>),no-attrs)" */
  if (PT_isProductionDefault(prod)) {
    PT_Symbol rhs = PT_getProductionRhs(prod);
    return PT_isSymbolVarSym(rhs);
  }

  ATerror("PT_prodHasVarSymAsRhs: not a production: %t\n", prod);
  return ATfalse;
}

ATbool PT_isVarDefault(PT_Production prod)
{
  /* This implements: "prod([varsym(<term>)],cf(<term>),<term>)" */
  if (PT_isProductionDefault(prod)) {
    PT_Symbols lhs = PT_getProductionLhs(prod);
    PT_Symbol rhs = PT_getProductionRhs(prod);

    if (PT_isSymbolCf(rhs) && PT_hasSymbolsHead(lhs)) {
      PT_Symbol lhssym = PT_getSymbolsHead(lhs);
      PT_Symbols tail = PT_getSymbolsTail(lhs);
      return PT_isSymbolsEmpty(tail) && PT_isSymbolVarSym(lhssym);
    }
    return ATfalse;
  }

  ATerror("PT_isVarDefault: not a production: %t\n", prod);
  return ATfalse;
}

ATbool PT_prodHasLexAsLhsAndCfAsRhs(PT_Production prod)
{
  /* This implements: "prod([lex(<term>)],cf(<term>),<term>)" */
  if (PT_isProductionDefault(prod)) {
    PT_Symbols lhs = PT_getProductionLhs(prod);
    PT_Symbol rhs = PT_getProductionRhs(prod);

    if (PT_isSymbolCf(rhs) && PT_hasSymbolsHead(lhs)) {
      PT_Symbol lhssym = PT_getSymbolsHead(lhs);
      PT_Symbols tail = PT_getSymbolsTail(lhs);
      return PT_isSymbolsEmpty(tail) && PT_isSymbolLex(lhssym);
    }
    return ATfalse;
  }

  ATerror("PT_prodHasVarSymAsLhs: not a production: %t\n", prod);
  return ATfalse;
}

ATbool PT_isIterSepSymbol(PT_Symbol symbol)
{
  /* This implements: 
   * "cf(iter-star-sep(<term>,lit(<str>)))" and
   * "cf(iter-sep(<term>,lit(<str>)))" 
   */
  if (PT_isSymbolCf(symbol)) {
    PT_Symbol listsym = PT_getSymbolSymbol(symbol);
    return PT_isSymbolIterPlusSep(listsym) || PT_isSymbolIterStarSep(listsym);
  }

  return ATfalse;
}

ATbool PT_isIterSymbol(PT_Symbol symbol)
{
  /* This implements: 
   * "cf(iter-star(<term>,lit(<str>)))"
   * "cf(iter(<term>,lit(<str>)))"
   */
  if (PT_isSymbolCf(symbol)) {
    PT_Symbol listsym = PT_getSymbolSymbol(symbol);
    return PT_isSymbolIterPlus(listsym) || PT_isSymbolIterStar(listsym);
  }

  return ATfalse;
}

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

  ATabort("PT_prodHasIterSepAsRhs: not a production: %t\n", prod);
  return ATfalse;
}

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

  ATerror("PT_prodHasListSepAsRhs: not a production: %t\n", prod);
  return ATfalse;
}

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

  ATerror("PT_prodHasSTARTAsRhs: not a production: %t\n", prod);
  return ATfalse;
}

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

PT_Args PT_concatArgs(PT_Args args1, PT_Args args2)
{
  return PT_makeArgsFromTerm((ATerm)ATconcat(
                                      (ATermList)PT_makeTermFromArgs(args1),
                                      (ATermList)PT_makeTermFromArgs(args2)));
}

PT_Args PT_appendArgs(PT_Args args, PT_Tree arg)
{
  return PT_makeArgsFromTerm((ATerm)ATappend(
                                      (ATermList)PT_makeTermFromArgs(args),
                                      (ATerm)PT_makeTermFromTree(arg)));
}

PT_Args PT_reverseArgs(PT_Args args)
{
  return PT_makeArgsFromTerm(
           (ATerm)ATreverse(
                    (ATermList)PT_makeTermFromArgs(args)));
}

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
                     PT_makeTermFromTree(
                     visitor(PT_getArgsHead(args),data)));
  }

  /* create new list */
  for (; !ATisEmpty(store); store = ATgetNext(store)) {
    PT_Tree newTree = PT_makeTreeFromTerm(ATgetFirst(store));
    newArgs = PT_makeArgsList(newTree,newArgs);
  }

  return newArgs;
}

/*}}}  */   
/*{{{  PT_Symbols PT_foreachSymbolInSymbols(symbols, visitor, data)  */

PT_Symbols PT_foreachSymbolInSymbols(PT_Symbols symbols, PT_SymbolVisitor visitor,
                                     PT_SymbolVisitorData data)
{
  ATermList store;
  PT_Symbols newSymbols = PT_makeSymbolsEmpty();

  /* apply func to each element */
  store = ATempty;
  while (PT_hasSymbolsHead(symbols)) {
    store = ATinsert(store,
                     PT_makeTermFromSymbol(
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
    PT_Symbol newSymbol = PT_makeSymbolFromTerm(ATgetFirst(store));
    newSymbols = PT_makeSymbolsList(newSymbol,newSymbols);
  }

  return newSymbols;
}

/*}}}  */
/*{{{  PT_Tree PT_removeTreeAnnotations(PT_Tree arg) */

PT_Tree PT_removeTreeAnnotations(PT_Tree arg)
{
  ATerm atArg = PT_makeTermFromTree(arg);

  if (AT_getAnnotations(atArg) != NULL) {
    atArg = AT_removeAnnotations(atArg);
  }

  return PT_makeTreeFromTerm(atArg);
}

/*}}}  */
/*{{{  ATerm PT_getTreeAnnotation(PT_Tree tree, ATerm key) */

ATerm PT_getTreeAnnotation(PT_Tree tree, ATerm key)
{
  ATerm atTree = PT_makeTermFromTree(tree);

  return ATgetAnnotation(atTree, key);
}
                                                                                /*}}}  */  
/*{{{  PT_Tree PT_setTreeAnnotation(PT_Tree tree, ATerm key, ATerm value) */

PT_Tree PT_setTreeAnnotation(PT_Tree tree, ATerm key, ATerm value)
{
  ATerm t = PT_makeTermFromTree(tree);

  t = ATsetAnnotation(t, key, value);

  return PT_makeTreeFromTerm(t);
}

/*}}}  */
/*{{{  ATerm PT_getParseTreeAnnotation(PT_ParseTree parse_tree, ATerm key) */

ATerm PT_getParseTreeAnnotation(PT_ParseTree parse_tree, ATerm key)
{
  ATerm atParseTree = PT_makeTermFromParseTree(parse_tree);

  return ATgetAnnotation(atParseTree, key);
}

/*}}}  */
/*{{{  PT_ParseTree PT_setParseTreeAnnotation(parse_tree, ATerm key, ATerm value) */

PT_ParseTree PT_setParseTreeAnnotation(PT_ParseTree parse_tree, ATerm key, ATerm value)
{
  ATerm t = PT_makeTermFromParseTree(parse_tree);

  t = ATsetAnnotation(t, key, value);

  return PT_makeParseTreeFromTerm(t);
}

/*}}}  */
/*{{{  int PT_getArgsLength(PT_Args args) */

int PT_getArgsLength(PT_Args args)
{
   return ATgetLength((ATermList)PT_makeTermFromArgs(args));
}

/*}}}  */ 
/*{{{  static PT_Args annotateArgsWithLength(PT_Args args, int *length) */

static PT_Tree annotateTreeWithLength(PT_Tree tree, int *length);

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

  return PT_makeArgsList(head, tail);
}

/*}}}  */
/*{{{  static PT_Tree annotateTreeWithLength(PT_Tree tree, int *length) */

static PT_Tree annotateTreeWithLength(PT_Tree tree, int *length)
{
  if (PT_hasTreeString(tree)) {
    *length = strlen(PT_getTreeString(tree));
  }
  else if (PT_hasTreeArgs(tree)) {
    PT_Args args = PT_getTreeArgs(tree);
    args = annotateArgsWithLength(args, length);
    tree = PT_setTreeArgs(tree, args);
  }
  else {
    ATerror("unknown tree type: %t\n", PT_makeTermFromTree(tree));
  }

  return PT_setTreeAnnotation(tree, ATparse(ANNO_LENGTH),
                              ATmake("<int>", *length));

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

  PT_Tree tree = PT_getParseTreeTree(parse_tree);
  tree = PT_annotateTreeWithLength(tree);

  length = PT_getTreeLengthAnno(tree);

  parse_tree = PT_setParseTreeTree(parse_tree, tree);
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
  ATerm anno = PT_getTreeAnnotation(tree, ATparse(ANNO_LENGTH));
  assert(anno);
  return ATgetInt((ATermInt)anno);
}

/*}}}  */ 
/*{{{  PT_Tree PT_setTreeLengthAnno(PT_Tree tree, int length) */

PT_Tree PT_setTreeLengthAnno(PT_Tree tree, int length)
{
  return PT_setTreeAnnotation(tree, ATparse(ANNO_LENGTH),
                             (ATerm)ATmakeInt(length));
}

/*}}}  */
/*{{{  PT_Tree PT_getArgsArgumentAt(PT_Args args, int arg_nr) */

PT_Tree PT_getArgsArgumentAt(PT_Args args, int arg_nr)
{
  ATermList arg_list = (ATermList)PT_makeTermFromArgs(args);
  ATerm arg = ATelementAt(arg_list, arg_nr);
  return PT_makeTreeFromTerm(arg);
}

/*}}}  */
/*{{{  PT_Args PT_setArgsArgumentAt(PT_Args args, PT_Tree arg, int arg_nr) */

PT_Args PT_setArgsArgumentAt(PT_Args args, PT_Tree arg, int arg_nr)
{
  ATermList arg_list = (ATermList)PT_makeTermFromArgs(args);
  arg_list = ATreplace(arg_list, PT_makeTermFromTree(arg), arg_nr);
  return PT_makeArgsFromTerm((ATerm)arg_list);
}

PT_Tree PT_makeLayoutEmpty()
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
