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

ATbool interpret_cons = ATfalse;
ATbool remove_layout = ATfalse;
ATbool lexical_to_string = ATtrue;
ATbool layout_to_string = ATtrue;
ATbool remove_literals = ATfalse;
 
static PT_Tree implodeTerm(PT_Tree t);
static PT_Tree implodeLayout(PT_Tree t);
static PT_Tree implodeLexical(PT_Tree t);
static PT_Tree implodeVar(PT_Tree t);
static PT_Production implodeProd(PT_Production prod);

static PT_Args implodeArgs(PT_Args args)
{
  PT_Tree newTerm;

  if (PT_isArgsEmpty(args)) {
    return args;
  }

  newTerm = implodeTerm(PT_getArgsHead(args));
  if (newTerm) {
    return PT_makeArgsList(newTerm, implodeArgs(PT_getArgsTail(args)));
  }
  else {
    return implodeArgs(PT_getArgsTail(args));
  }
}

static PT_Args implodeList(PT_Args list)
{
  PT_Args newList = PT_makeArgsEmpty();
  
  if (PT_hasArgsHead(list)) {
    PT_Tree argHead = PT_getArgsHead(list);

    if (PT_isTreeList(argHead)) {
      PT_Args argList = PT_getTreeArgs(argHead);

      while (PT_hasArgsHead(argList)) {
        PT_Tree elem = PT_getArgsHead(argList);
        PT_Tree newElem = implodeTerm(elem);
        if (newElem) {
          newList = PT_appendArgs(newList, newElem);
        }

        argList = PT_getArgsTail(argList);
      }
    }
  }
  return newList;
}

static PT_Production implodeProd(PT_Production prod)
{
  /*
  if (interpret_cons) {
    PT_Attributes attrs = PT_getProductionAttrs(prod);
    
    if (!PT_isAttributesNoAttrs(attrs)) {
      PT_Attrs attrList = PT_getAttributesAttrs(attrs);

      while(PT_hasAttrsHead(attrList)) {
        PT_Attr attr = PT_getAttrsHead(attrList);
        attrList = PT_getAttrsTail(attrList);

        if (PT_isAttrCons(attr)) {
          char *lit = PT_getAttrString(attr);
        }
      }
    }
  }
  */
  return prod;
}

static PT_Tree implodeLexical(PT_Tree tree)
{
  if (lexical_to_string) {
    return PT_makeTreeFlatLexical(PT_yieldTree(tree));
  }
  else { 
    return tree;
  }
}

static PT_Tree implodeLayout(PT_Tree tree)
{
  if (!remove_layout) {
    if (layout_to_string) {
      return PT_makeTreeFlatLayout(PT_yieldTree(tree));
    }
    else {
      return tree;
    }
  }
  else {
    return NULL;
  }
}

static PT_Tree implodeLiteral(PT_Tree tree)
{
  if (remove_literals) {
    return NULL;
  }

  return tree;
}

static PT_Tree implodeVar(PT_Tree tree)
{
  return tree;
}

static PT_Tree implodeApplication(PT_Tree tree)
{
  PT_Production prod = PT_getTreeProd(tree);
  PT_Args       args = PT_getTreeArgs(tree);
  PT_Args       newList;
     
  if (PT_isOptLayoutProd(prod)) {
    return implodeLayout(tree);
  }

  if (PT_prodHasLexAsLhsAndCfAsRhs(prod)) {
    return implodeLexical(tree);
  }

  if (PT_isVarDefault(prod)) {
    return implodeVar(tree);
  }

  if (PT_prodHasIterSepAsRhs(prod) || PT_prodHasIterAsRhs(prod)) {
    newList = implodeList(args);
  }
  else {
    newList = implodeArgs(args);
  }
  return PT_makeTreeAppl(implodeProd(prod), newList);
}

static PT_Tree implodeTerm(PT_Tree tree)
{
  PT_Args args;

  if (PT_isTreeAmb(tree)) {
    args = PT_getTreeArgs(tree);
    return PT_setTreeArgs(tree, implodeArgs(args));
  }

  if (PT_isTreeLit(tree)) { 
    return implodeLiteral(tree);
  }                        

  if (!PT_isTreeAppl(tree)) {
    ATerror("implodeTerm: not an application term: %t\n", tree);
  }

  return implodeApplication(tree);
}

PT_ParseTree implodeParseTree(PT_ParseTree tree)
{
  if (PT_isParseTreeTree(tree)) {
    PT_Tree newTree = PT_getParseTreeTree(tree);

    if (PT_isTreeAppl(newTree)) {
      PT_Production prod = PT_getTreeProd(newTree);
      if (PT_prodHasSTARTAsRhs(prod)) {
        PT_Args args = PT_getTreeArgs(newTree);
        PT_Args newArgs = implodeArgs(args);
        
        newTree = PT_setTreeArgs(newTree, newArgs);
        return PT_setParseTreeTree(tree, newTree);
      }
    }
  }

  ATerror("implodeParseTree: not a parsetree: %t\n", tree);
  return NULL;
}
