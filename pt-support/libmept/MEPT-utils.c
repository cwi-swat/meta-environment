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

  ATerror("PT_isLexicalProd: not a production: %t\n", prod);
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

  ATerror("PT_isLexicalInjectionProd: not a production: %t\n", prod);
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

PT_Symbol PT_getIterSepSeparator(PT_Symbol symbol)
{
  PT_Symbol listSymbol = PT_getSymbolSymbol(symbol);
  return PT_getSymbolSeparator(listSymbol);
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

ATbool PT_isProductionList(PT_Production prod)
{                                       
  return PT_prodHasIterAsRhs(prod) ||
         PT_prodHasIterSepAsRhs(prod);
}

ATbool PT_isTreeApplList(PT_Tree tree)
{
  if (PT_isTreeAppl(tree)) {
    PT_Production prod = PT_getTreeProd(tree);
    if (PT_isProductionList(prod)) {
      PT_Args args = PT_getTreeArgs(tree);
      if (PT_hasArgsHead(args)) {
        PT_Tree arg = PT_getArgsHead(args);
        args = PT_getArgsTail(args);
        if (PT_isTreeList(arg) && PT_isArgsEmpty(args)) {
          return ATtrue;
        }
      }
    }
  }
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

PT_Symbols PT_concatSymbols(PT_Symbols symbols1, PT_Symbols symbols2)
{
  return PT_makeSymbolsFromTerm(
           (ATerm)ATconcat((ATermList)PT_makeTermFromSymbols(symbols1),
                           (ATermList)PT_makeTermFromSymbols(symbols2)));
}

PT_Args PT_sliceArgs(PT_Args args, int start, int end)
{
  return PT_makeArgsFromTerm(
           (ATerm)ATgetSlice((ATermList)PT_makeTermFromArgs(args),
                              start, end));
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
    tree = PT_setTreeAnnotation(tree, ATparse(ANNO_LENGTH),
                                ATmake("<int>", *length));
  }
  else if (PT_isTreeChar(tree)) {
    *length = 1;
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
            PT_makeTermFromTree(tree));
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

PT_Tree PT_makeTreeLayoutNonEmpty(PT_Args args)
{
  PT_Symbol layoutSymbolRhs = PT_makeSymbolCf(
                                PT_makeSymbolOpt(PT_makeSymbolLayout()));
  PT_Symbol layoutSymbolLhs = PT_makeSymbolCf(PT_makeSymbolLayout());
  PT_Symbols layoutLhs = PT_makeSymbolsList(layoutSymbolLhs, 
                                            PT_makeSymbolsEmpty());
  PT_Production optLayoutProd = PT_makeProductionDefault(
                                  layoutLhs,
                                  layoutSymbolRhs,
                                  PT_makeAttributesNoAttrs());
  return PT_makeTreeAppl(optLayoutProd, args);
}

ATbool PT_isTreeLayout(PT_Tree tree)
{
  if (PT_isTreeAppl(tree)) {
    PT_Production prod = PT_getTreeProd(tree);
    return PT_isOptLayoutProd(prod);
  }
  return ATfalse;
}

ATbool PT_isTreeLexical(PT_Tree tree)
{
  if (PT_isTreeAppl(tree)) {
    PT_Production prod = PT_getTreeProd(tree);
    return PT_isLexicalInjectionProd(prod);
  }
  return ATfalse;
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
/*{{{  ATbool PT_isTreeVar(PT_Tree tree) */

ATbool PT_isTreeVar(PT_Tree tree) 
{
  if (PT_isTreeAppl(tree)) {
    PT_Production prod = PT_getTreeProd(tree);
    return PT_isVarDefault(prod);
  }
  return ATfalse;
}

ATbool PT_isTreeVarList(PT_Tree tree)
{
  if (PT_isTreeAppl(tree)) {
    PT_Production prod = PT_getTreeProd(tree);
    if (PT_isVarDefault(prod)) {
      PT_Symbol rhssym = PT_getProductionRhs(prod);
      if (PT_isSymbolCf(rhssym)) {
        PT_Symbol cfsym = PT_getSymbolSymbol(rhssym);
        return PT_isSymbolIterPlus(cfsym) 
               || PT_isSymbolIterStar(cfsym)
               || PT_isSymbolIterPlusSep(cfsym) 
               || PT_isSymbolIterStarSep(cfsym);
      }
    }
  }
  return ATfalse;
}

ATbool PT_isTreeVarListStar(PT_Tree tree)
{
  if (PT_isTreeAppl(tree)) {
    PT_Production prod = PT_getTreeProd(tree);
    if (PT_isVarDefault(prod)) {
      PT_Symbol rhssym = PT_getProductionRhs(prod);
      if (PT_isSymbolCf(rhssym)) {
        PT_Symbol cfsym = PT_getSymbolSymbol(rhssym);
        return PT_isSymbolIterStar(cfsym)
               || PT_isSymbolIterStarSep(cfsym);
      }
    }
  }
  return ATfalse;
}              

ATbool PT_isTreeVarListPlus(PT_Tree tree)
{
  if (PT_isTreeAppl(tree)) {
    PT_Production prod = PT_getTreeProd(tree);
    if (PT_isVarDefault(prod)) {
      PT_Symbol rhssym = PT_getProductionRhs(prod);
      if (PT_isSymbolCf(rhssym)) {
        PT_Symbol cfsym = PT_getSymbolSymbol(rhssym);
        return PT_isSymbolIterPlus(cfsym) 
               || PT_isSymbolIterPlusSep(cfsym);
      }
    }
  }
  return ATfalse;
}


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
                     PT_makeTermFromAttr(
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

  newAttrs = PT_makeAttrsSingle(PT_makeAttrFromTerm(ATgetFirst(store)));
  store = ATgetNext(store);

  /* create new list */
  for (; !ATisEmpty(store); store = ATgetNext(store)) {
    PT_Attr newAttr = PT_makeAttrFromTerm(ATgetFirst(store));
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

  if (PT_isAttributesNoAttrs(attributes)) {
    return ATfalse;
  }

  attrs = PT_getAttributesAttrs(attributes);

  data.bool = ATfalse;
  data.attr = attr;

  PT_foreachAttrInAttrs(attrs, PT_matchAttr, (PT_AttrVisitorData)&data);    

  return data.bool;
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
  return PT_hasProductionCertainAttr(prod, PT_makeAttrMemo());
}

/*}}}  */   
/*{{{  ATbool PT_hasProductionTraverseAttr(PT_Production prod) */

ATbool PT_hasProductionTraverseAttr(PT_Production prod)
{
  return PT_hasProductionCertainAttr(prod, PT_makeAttrTraverse());
}

/*}}}  */       
/*{{{  PT_Symbol makeSymbolAllChars() */

PT_Symbol makeSymbolAllChars()
{
  PT_CharRanges ranges = PT_makeCharRangesList(
                           PT_makeCharRangeRange(0,255),
                           PT_makeCharRangesEmpty());
  return PT_makeSymbolIterStar(
           PT_makeSymbolCharClass(ranges));
}  

/*}}}  */
/*{{{  PT_Tree PT_makeTreeFlatLexical(PT_Args charList) */

PT_Tree PT_makeTreeFlatLexical(PT_Args charList)
{
  return PT_makeTreeList(makeSymbolAllChars(), charList);
}

/*}}}  */

PT_Tree PT_getParseTreeTop(PT_ParseTree parseTree)
{
  ATerm ATparseTree = PT_makeTermFromParseTree(parseTree);
  
  return PT_makeTreeFromTerm(ATgetArgument(ATparseTree,0));
}

PT_ParseTree PT_setParseTreeTop(PT_ParseTree parseTree, PT_Tree top)
{
  ATerm ATparseTree = PT_makeTermFromParseTree(parseTree);
  
  return PT_makeParseTreeFromTerm(
           (ATerm) ATsetArgument((ATermAppl) ATparseTree,
              PT_makeTermFromTree(top),0));
}
