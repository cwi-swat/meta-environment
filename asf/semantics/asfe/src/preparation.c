
/*{{{  file header */

/*

    Meta-Environment - An environment for language prototyping.
    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, 
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

*/

/*}}}  */
/*{{{  includes */

#include <ctype.h>
#include <stdlib.h>
#include <assert.h>
#include <strings.h>
#include <string.h>
#include <aterm2.h>
#include <deprecated.h>
#include "preparation.h"
#include "asfix_utils.h"
#include "asfe.h"
#include "asf-api.h"

#include <MEPT.h>
#include <ASFME-utils.h>

/*}}}  */
/*{{{  defines */

/* These constants are dependent on Asfix2ME!!! */
#define DEPTH_OF_CONDITIONS_AND_EQUATION       2
#define DEPTH_OF_CONDITION_SIDES_IN_CONDITIONS 4
#define DEPTH_OF_EQUATION_SIDES_IN_EQUATION    2

/* New layout is marked by a layout tree that exists, but is empty.
 * This can never be the result of parsing, but it is still valid AsFix.
 */
#define PRETTY_PRINT_MARKER ""

/*}}}  */
/*{{{  variables */

equation_entry *currentRule = NULL;

static equation_table *tables = NULL;
equation_table *equations = NULL;

extern ATbool runVerbose;
static ATbool mark_new_layout;
static ATbool in_equations;

/*}}}  */
/*{{{  local function declarations */

static PT_Tree prepareTerm(PT_Tree tree, PT_TreeVisitorData data);
static PT_Tree restoreTerm(PT_Tree tree, PT_TreeVisitorData data);

/*}}}  */

/*{{{  equation_table *create_equation_table(int size) */

/* Allocate memory for an equation table.
*/

equation_table *create_equation_table(int size)
{
  int i;
  equation_table *table = (equation_table *) malloc(sizeof(equation_table));

  if (!table)
    ATerror("out of memory in create_equation_table\n");
  table->next = NULL;
  table->module = NULL;
  ATprotect(&table->module);
  table->size = size;
  table->table = (equation_entry **) malloc(sizeof(equation_entry *) * size);
  if (!table->table) {
    ATerror("out of memory in create_equation_table\n");
  }

  for (i = 0; i < size; i++) {
    table->table[i] = NULL;
  }

  return table;
}

/*}}}  */
/*{{{  void flush_equations(equation_table * table) */

void flush_equations(equation_table * table)
{
  int i;
  equation_entry *old, *entry;

  for (i = 0; i < table->size; i++) {
    entry = table->table[i];
    while (entry) {
      old = entry;
      entry = entry->hnext;
      ATunprotect((ATerm*)&old->equation);
      ATunprotect((ATerm*)&old->top_ofs);
      ATunprotect((ATerm*)&old->first_ofs);
      ATunprotect((ATerm*)&old->tag);
      ATunprotect((ATerm*)&old->lhs);
      ATunprotect((ATerm*)&old->rhs);
      ATunprotect((ATerm*)&old->conds);
      free(old);
    }
    table->table[i] = NULL;
  }
}

/*}}}  */
/*{{{  void destroy_equation_table(equation_table * table) */


/*
Free all memory associated with an equation table.
*/


void destroy_equation_table(equation_table * table)
{
  flush_equations(table);
  ATunprotect(&table->module);
  free(table->table);
  free(table);
}

/*}}}  */
/*{{{  static unsigned hash_function(table, top_ofs, first_ofs) */

static unsigned hash_function(equation_table *table, PT_Production top_ofs,
			      PT_Production first_ofs)
{
  return (((int) top_ofs >> 2) * 3007 + ((int) first_ofs >> 2)) % table->size;
}

/*}}}  */

/*{{{  ASF_CondEquation add_equ_pos_info(ASF_CondEquation equ) */

ASF_CondEquation add_equ_pos_info(ASF_CondEquation equ)
{
  PT_Tree tree;
  char *path;
  int start_line, start_col, end_line, end_col;
  ASF_Equation equation;

  tree = PT_TreeFromTerm(ASF_CondEquationToTerm(equ));

  if (!PT_getTreePosInfo(tree, &path, &start_line,
			 &start_col, &end_line, &end_col)) {
    ATwarning("No pos. info, cannot debug equation %s tree=%t\n",
      PT_yieldTree(
        PT_TreeFromTerm(ASF_TagToTerm(ASF_getCondEquationTag(equ)))), tree);
    return equ;
  }
  /*
  fprintf(stderr, "pos-info to start equ %s: %s,%d,%d,%d,%d\n",
	  PT_yieldTree(PT_TreeFromTerm(ASF_TagToTerm(ASF_getCondEquationTag(equ)))), path, start_line, start_col, end_line, end_col);
	  */


  /* Annotate to a depth so that the list of conditions is annotated */
  tree = PT_addTreePosInfoToDepth(path, tree, DEPTH_OF_CONDITIONS_AND_EQUATION,
				  start_line, start_col);
  /*ATwarning("tree after annotating the equations: %t\n", tree);*/
  equ = ASF_CondEquationFromTerm(PT_TreeToTerm(tree));

  if (ASF_hasCondEquationConditions(equ)) {
    ASF_Conditions conds = ASF_getCondEquationConditions(equ);
    tree = PT_TreeFromTerm(ASF_ConditionsToTerm(conds));
    if (!PT_getTreePosInfo(tree, &path, &start_line,
			   &start_col, &end_line, &end_col)) {
      ATwarning("no position information on conditions, "
		"crippled debugging: %t\n", tree);
    } else {
      /* Annotate to a depth so that the lhs and rhs of the conditions is
       * annotated
       */
      tree = PT_addTreePosInfoToDepth(path, tree,
				      DEPTH_OF_CONDITION_SIDES_IN_CONDITIONS,
				      start_line, start_col);
      conds = ASF_ConditionsFromTerm(PT_TreeToTerm(tree));
      equ = ASF_setCondEquationConditions(equ, conds);
      /*ATwarning("tree after annotating the conditions: %t\n", tree);*/
    }
  }

  equation = ASF_getCondEquationEquation(equ);
  tree = PT_TreeFromTerm(ASF_EquationToTerm(equation));
  if (!PT_getTreePosInfo(tree, &path, &start_line, &start_col,
			 &end_line, &end_col)) {
    ATwarning("no position information on equation, crippled debugging: %t\n",
	      tree);
  } else {
    tree = PT_addTreePosInfoToDepth(path, tree,
				    DEPTH_OF_EQUATION_SIDES_IN_EQUATION,
				    start_line, start_col);
    equation = ASF_EquationFromTerm(PT_TreeToTerm(tree));

    equ = ASF_setCondEquationEquation(equ, equation);
  }

  return equ;
}

/*}}}  */

/*{{{  ATerm getPosInfoEquals(ASF_Equation equ) */

ATerm getPosInfoEquals(ASF_Equation equ)
{
  PT_Tree tree = PT_makeTreeFromTerm(ASF_makeTermFromEquation(equ));
  PT_Tree equals = PT_getArgsArgumentAt(PT_getTreeArgs(tree), 2);
  return ATgetAnnotation(PT_makeTermFromTree(equals), posinfo);
}

/*}}}  */

/*{{{  void enter_equation(equation_table * table, ASF_CondEquation equation) */

/* Enter an equation in an equation table.
*/

void enter_equation(equation_table * table, ASF_CondEquation equation)
{
  equation_entry *entry;

  ASF_Equation equ;
  PT_Tree lhs = NULL, rhs = NULL;
  PT_Production top_ofs, first_ofs;
  ASF_Tag tag = NULL; 
  PT_Args lhsargs;
  ASF_ConditionList conds; 
  ASF_Conditions conditions;
  unsigned hnr;

  if (ASF_isCondEquationImplies(equation) 
      || ASF_isCondEquationWhen(equation)) {
    conditions = ASF_getCondEquationConditions(equation);
    conds = ASF_getConditionsList(conditions);
  }
  else {
    conds = (ASF_ConditionList) NULL;
  }

  tag = ASF_getCondEquationTag(equation);
  equ = ASF_getCondEquationEquation(equation);

  /* this is where we switch API's from ASF_ to PT_ for the user-defined
   * term syntax
   */

  lhs = ASFtoPT(ASF_getEquationLhs(equ));
  rhs = ASFtoPT(ASF_getEquationRhs(equ));

  lhsargs = PT_getTreeArgs(lhs);
  top_ofs = PT_getTreeProd(lhs);

  if (runVerbose) {
    ATwarning("enter_equation:  top_ofs = %s\n", PT_yieldProduction(top_ofs));
  } 

  /* find first appl or var argument of the outermost function symbol */ 
  while (PT_hasArgsHead(lhsargs) && 
         (PT_isTreeLit(PT_getArgsHead(lhsargs)) || 
          PT_isTreeLayout(PT_getArgsHead(lhsargs)))) {
    lhsargs = PT_getArgsTail(lhsargs);
  }

  /* if it is a variable or we have a default equation */
  if (PT_isArgsEmpty(lhsargs) || ASF_isTagDefault(tag)) { 
    first_ofs = (PT_Production) NULL;
  }
  else {
    PT_Tree firstArg = PT_getArgsHead(lhsargs);
    if (PT_isTreeVar(firstArg)) {
      first_ofs = (PT_Production) NULL;
    }
    else {
      first_ofs = PT_getTreeProd(firstArg);

      if (runVerbose) {
        ATwarning("...............first_ofs = %s\n", 
          PT_yieldProduction(first_ofs));
      } 
    }
  }

  hnr = hash_function(table, top_ofs, first_ofs);

  /* now fill in the entry */
  entry = (equation_entry *) malloc(sizeof(equation_entry));
  if (!entry) {
    ATerror("out of memory in enter_equation");
  }

  entry->hashnr = hnr;

  entry->top_ofs = top_ofs;
  ATprotect((ATerm*)&entry->top_ofs);

  entry->first_ofs = first_ofs;
  ATprotect((ATerm*)&entry->first_ofs);

  entry->equation = equation;
  ATprotect((ATerm*)&entry->equation);

  entry->tag = tag;
  ATprotect((ATerm*)&entry->tag);

  entry->lhs = lhs;
  ATprotect((ATerm*)&entry->lhs);

  entry->rhs = rhs;
  ATprotect((ATerm*)&entry->rhs);

  entry->posinfo_equals = getPosInfoEquals(equ);
  ATprotect((ATerm *)&entry->posinfo_equals);

  entry->conds = conds;
  ATprotect((ATerm *) (&entry->conds));

  if (ASF_isTagDefault(tag)) {
    equation_entry *cur = table->table[hnr];
    entry->hnext = NULL;
    if (cur) {
      while (cur->hnext) {
	cur = cur->hnext;
      }
      cur->hnext = entry;
    }
    else {
      table->table[hnr] = entry;
    }
  }
  else {
    entry->hnext = table->table[hnr];
    table->table[hnr] = entry;
  }
}

/*}}}  */
/*{{{  equation_entry *find_equation(from, top_ofs, first_ofs) */

equation_entry *find_equation(equation_entry * from, PT_Production top_ofs, 
			      PT_Production first_ofs)
{
  if (runVerbose) {
    ATwarning("looking for equation with ofs: %s\n",
	      PT_yieldProduction(top_ofs));
    if (first_ofs) {
    ATwarning("................and first ofs: %s\n",
	      PT_yieldProduction(first_ofs));
    }
  }

  if (equations->size == 0) {
    return NULL;
  }
  if (from) {
    from = from->hnext;
  }
  else {
    int hnr = hash_function(equations, top_ofs, first_ofs);
    from = equations->table[hnr];
  }

  if (first_ofs != NULL) {
    while (from && (!PT_isEqualProduction(from->top_ofs, top_ofs))) {
      from = from->hnext;
    }
  }
  else {
    while (from && (!PT_isEqualProduction(from->top_ofs, top_ofs) ||
		    !PT_isEqualProduction(from->first_ofs, first_ofs))) {
      from = from->hnext;
    }
  }

  return from;
}

/*}}}  */
/*{{{  void select_equations(char *module) */

void select_equations(char *module)
{
  equation_table *cur = tables;
  ATerm t_module = ATmake("<str>", module);

  while (cur && !ATisEqual(cur->module, t_module)) {
    cur = cur->next;
  }

  if (!cur) {
    ATerror("equations of module %s have not been registered.\n", module);
  }

  equations = cur;
}

/*}}}  */
/*{{{  ATbool find_module(char *module) */

ATbool find_module(char *module)
{
  equation_table *cur = tables;
  ATerm t_module = ATmake("<str>", module);

  while (cur && !ATisEqual(cur->module, t_module)) {
    cur = cur->next;
  }

  if (cur) {
    return ATtrue;
  }
  else {
    return ATfalse;
  }
}

/*}}}  */
/*{{{  equation_table *find_equation_table(char *modname) */

equation_table *find_equation_table(char *modname)
{
  equation_table *cur = tables;
  ATerm t_module = ATmake("<str>", modname);

  while (cur && !ATisEqual(cur->module, t_module)) {
    cur = cur->next;
  }

  return cur;
}


/*}}}  */
/*{{{  void enter_equations(char *modname, ASF_CondEquationList eqsList) */

/*
  The equations are ``sorted'' by outermost function symbols.
  This is performed by the function ``sort_and_filter_on_ofs''.
  This function adds the equations with the same ofs in the
  left hand side of an equation to the database, and returns
  the original list of equations minus the equations which
  where stored.
*/


void enter_equations(char *modname, ASF_CondEquationList eqsList)
{
  equation_table *table;

  table = find_equation_table(modname);

  if (!table) {
    table = create_equation_table(ASF_getCondEquationListLength(eqsList) * 2);
    table->module = ATmake("<str>", modname);
    table->next = tables;
    tables = table;
  }

  flush_equations(table);

  while (ASF_hasCondEquationListHead(eqsList)) {
    enter_equation(table, ASF_getCondEquationListHead(eqsList));

    if (ASF_hasCondEquationListTail(eqsList)) {
      eqsList = ASF_getCondEquationListTail(eqsList);
    }
    else {
      break;
    }
  }
}

/*}}}  */
/*{{{  void delete_equations(char *modname) */

void delete_equations(char *modname)
{
  equation_table *cur = tables, *prev = NULL;
  ATerm t_module = ATmake("<str>", modname);

  while (cur && !ATisEqual(cur->module, t_module)) {
    prev = cur;
    cur = cur->next;
  }

  if (cur) {
    if (prev) {
      prev->next = cur->next;
    }
    else {
      tables = cur->next;
    }
    destroy_equation_table(cur);
  }
}

/*}}}  */
/*{{{  ASF_Condition prepare_cond(ASF_Condition cond) */

ASF_Condition prepare_cond(ASF_Condition cond)
{
  PT_Tree lhs, rhs;
  
  lhs = ASFtoPT(ASF_getConditionLhs(cond));
  cond = ASF_setConditionLhs(cond, PTtoASF(RWprepareTerm(lhs, ATfalse)));
    
  rhs = ASFtoPT(ASF_getConditionRhs(cond));
  cond = ASF_setConditionRhs(cond, PTtoASF(RWprepareTerm(rhs, ATfalse)));

  return cond;
}

/*}}}  */
/*{{{  ASF_Conditions prepareConditions(ASF_Conditions conds) */

ASF_Conditions prepareConditions(ASF_Conditions conds)
{
  ASF_ConditionList  condList = ASF_getConditionsList(conds);
  
  condList = ASF_visitConditionList(condList, prepare_cond, NULL, NULL, NULL);

  return ASF_setConditionsList(conds, condList);
}

/*}}}  */
/*{{{  ASF_CondEquation prepareEquation(ASF_CondEquation equ) */

/*
Prepare an equation for rewriting. This includes removing the layout,
and translating lexicals into lists.
*/

ASF_CondEquation prepareEquation(ASF_CondEquation equ)
{
  ASF_Equation equation;

  equ = add_equ_pos_info(equ);

  if (ASF_isCondEquationWhen(equ) || ASF_isCondEquationImplies(equ)) {
    equ = ASF_setCondEquationConditions(equ,
            prepareConditions(ASF_getCondEquationConditions(equ)));
  }

  equation = ASF_getCondEquationEquation(equ);

  equation = ASF_setEquationLhs(equation, 
          PTtoASF(RWprepareTerm(ASFtoPT(ASF_getEquationLhs(equation)),
				ATfalse)));

  equation = ASF_setEquationRhs(equation,
          PTtoASF(RWprepareTerm(ASFtoPT(ASF_getEquationRhs(equation)),
				ATfalse)));

  return ASF_setCondEquationEquation(equ, equation); 
}

/*}}}  */
/*{{{  static PT_Tree ambToAmbConstructor(PT_Tree tree) */

static PT_Tree ambToAmbConstructor(PT_Tree tree, PT_TreeVisitorData data)
{
  PT_Args ambs;
  PT_Args listargs = PT_makeArgsEmpty();
  PT_Symbol symbol;
  PT_Tree first;
  PT_Tree l = PT_makeTreeLayoutEmpty();
  PT_Tree s = PT_makeTreeLit(",");

  assert(PT_isTreeAmb(tree));
  ambs = PT_getTreeArgs(tree);

  assert(PT_hasArgsHead(ambs));

  first = PT_getArgsHead(ambs);

  symbol = PT_getProductionRhs(PT_getTreeProd(first)); 

  if (PT_isSymbolCf(symbol) || PT_isSymbolLex(symbol)) {
    symbol = PT_getSymbolSymbol(symbol);
  }

  ambs = PT_foreachTreeInArgs(ambs, prepareTerm, data);

  for (; PT_hasArgsHead(ambs); ambs = PT_getArgsTail(ambs)) {
    PT_Tree amb = PT_getArgsHead(ambs);
    listargs = PT_makeArgsList(amb, listargs);

    if (PT_hasArgsHead(PT_getArgsTail(ambs))) {
      listargs = PT_makeArgsList(l,listargs);
      listargs = PT_makeArgsList(s,listargs);
      listargs = PT_makeArgsList(l,listargs);
    }
  }

  return (PT_Tree) 
    ASF_makeTreeAmbConstructor((ASF_Symbol) symbol,
			       (ASF_Symbol) symbol,
			       (ASF_Layout) l,
			       (ASF_Layout) l,
			       (ASF_Symbol) symbol,
			       (ASF_TreeAmbs) listargs,
			       (ASF_Layout) l);
}

/*}}}  */
/*{{{  static PT_Tree APICallToNormalCall(PT_Tree tree) */

static PT_Tree APICallToNormalCall(PT_Tree tree, PT_TreeVisitorData data)
{
  AA_Calls calls = getTreeAPICalls(tree);
  AA_Call call = AA_getCallsHead(calls);
  PT_Tree result;

  if (AA_isCallConstructor(call)) {
    result = interpretConstructorCall(tree, calls);
    return prepareTerm(result, data); 
  }

  /* other API calls are interpreted at run-time */
  return tree;
}

/*}}}  */
/*{{{  static PT_Tree prepareTerm(PT_Tree tree, PT_TreeVisitorData data) */

static PT_Tree prepareTerm(PT_Tree tree, PT_TreeVisitorData data)
{
  PT_Tree result;
  PT_Args args, newargs;
  ATerm annos = AT_getAnnotations(PT_makeTermFromTree(tree));

  if (ASF_isTreeLexicalConstructorFunction((ASF_Tree) tree)) { 
    result = (PT_Tree) 
               ASF_LexicalConstructorTreeToLexicalTree((ASF_Tree) tree);
  }
  else if (isTreeAPIFunction(tree)) {
    result = APICallToNormalCall(tree, data);
  } 
  else if (PT_isTreeBracket(tree)) {
    result = prepareTerm(PT_getTreeBracketTree(tree), data);
  }
  else if (mark_new_layout && in_equations && PT_isTreeLayout(tree)) {
    result = PT_makeTreeLayoutFromString(PRETTY_PRINT_MARKER);
  }
  else if (PT_isTreeAppl(tree)) {
    args = PT_getTreeArgs(tree);
    newargs = PT_foreachTreeInArgs(args, prepareTerm, data);
    result = PT_setTreeArgs(tree, newargs);
  }
  else if (PT_isTreeAmb(tree)) {
    if (*((ATbool*) data) == ATtrue) {
      result = ambToAmbConstructor(tree,data);
    }
    else {
      RWsetError("Illegal ambiguity", (ATerm) PT_makeTreeLit(""));
      result = tree;
    }
  }
  else {
    result = tree;
  }

  if (annos != NULL) {
    result = PT_makeTreeFromTerm(
               AT_setAnnotations(PT_makeTermFromTree(result), annos));
  }

  return result;
}

/*}}}  */

/*{{{  PT_Tree RWprepareTerm(PT_Tree tree) */

PT_Tree RWprepareTerm(PT_Tree tree, ATbool allow_ambs)
{
  return  prepareTerm(tree, &allow_ambs);
}

/*}}}  */
/*{{{  ASF_CondEquationList RWprepareEquations(ASF_CondEquationList eqsList) */
/*
Prepare a list of equations for rewriting.
*/


ASF_CondEquationList RWprepareEquations(ASF_CondEquationList eqsList, 
					ATbool mark_layout)
{
  ASF_CondEquationList new;
  mark_new_layout = mark_layout;
  in_equations = ATtrue;
  new = ASF_visitCondEquationList(eqsList, prepareEquation, NULL);
  in_equations = ATfalse;
  return new;
}

/*}}}  */
/*{{{  void RWflushEquations() */

void RWflushEquations()
{
  equation_table *table;
  while (tables) {
    table = tables;
    tables = tables->next;
    destroy_equation_table(table);
  }
}

/*}}}  */
/*{{{  static PT_Tree ambConstructorToAmb(PT_Tree tree, PT_TreeVisitorData data) */

static PT_Tree ambConstructorToAmb(PT_Tree tree, PT_TreeVisitorData data)
{
  ASF_Tree asfTree = PTtoASF(tree);
  PT_Args args = (PT_Args) ASF_getTreeAmbs(asfTree);
  PT_Args ambs;

  ambs = PT_makeArgsEmpty();

  if (ATisEmpty(args)) {
    RWsetError("Empty ambiguity cluster encountered", (ATerm) PT_makeTreeLit(""));
    return tree;
  }

  while (PT_hasArgsHead(args)) {
    PT_Tree arg;
    PT_Tree amb;

    arg = PT_getArgsHead(args);
    args = PT_getArgsTail(args);
    amb = restoreTerm(arg, data);
    ambs = PT_makeArgsList(amb,ambs);

    
    if (!PT_isArgsEmpty(args)) {
      args = PT_getArgsTail(args); 
      args = PT_getArgsTail(args); 
      args = PT_getArgsTail(args); 
    }
  }

  return PT_makeTreeAmb(ambs);
}

/*}}}  */

/*{{{  static PT_Tree restoreTerm(PT_Tree tree, PT_TreeVisitorData data) */

static PT_Tree restoreTerm(PT_Tree tree, PT_TreeVisitorData data)
{
  PT_Args args;

  if (PT_isTreeAppl(tree)) {
    if (ASF_isTreeAmbConstructorFunction(PTtoASF(tree))) {
      return ambConstructorToAmb(tree, data);
    }
    else if ( *((ATbool*) data) == ATtrue && PT_isTreeLayout(tree)) {
      return PT_makeTreeLayoutFromString(" ");
    }

    args = PT_getTreeArgs(tree);
    args = PT_foreachTreeInArgs(args, restoreTerm, data);
    return PT_setTreeArgs(tree, args);
  }

  return tree;
}


/*}}}  */
/*{{{  PT_Tree RWrestoreTerm(PT_Tree tree) */

PT_Tree RWrestoreTerm(PT_Tree tree, ATbool remove_layout)
{
  return restoreTerm(tree, &remove_layout);
}

/*}}}  */
/*{{{  PT_Args RWrestoreArgs(PT_Args args) */

PT_Args RWrestoreArgs(PT_Args args, ATbool remove_layout)
{
  return PT_foreachTreeInArgs(args, restoreTerm, &remove_layout);
}

/*}}}  */
