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
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>
#include <strings.h>
#include <string.h>
#include <aterm2.h>
#include <deprecated.h>
#include "preparation.h"
#include "asfix_utils.h"

#include <MEPT.h>
#include <ASFME-utils.h>

static equation_table *tables = NULL;
static equation_table *equations = NULL;

extern ATbool runVerbose;

/*
Allocate memory for an equation table.
*/

equation_table *
create_equation_table(int size)
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


void
flush_equations(equation_table * table)
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



/*
Free all memory associated with an equation table.
*/

void
destroy_equation_table(equation_table * table)
{
  flush_equations(table);
  ATunprotect(&table->module);
  free(table->table);
  free(table);
}


static unsigned
hash_function(equation_table * table, PT_Production top_ofs, PT_Production first_ofs)
{
  return (((int) top_ofs >> 2) * 3007 + ((int) first_ofs >> 2)) % table->size;
}


/*
Enter an equation in an equation table.
*/

void
enter_equation(equation_table * table, ASF_CondEquation equation)
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

equation_entry *
find_equation(equation_entry * from, PT_Production top_ofs, 
              PT_Production first_ofs)
{
  if (runVerbose) {
    ATwarning("looking for equation with ofs: %s\n", PT_yieldProduction(top_ofs));
    if (first_ofs) {
    ATwarning("................and first ofs: %s\n", PT_yieldProduction(first_ofs));
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


void
select_equations(char *module)
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


ATbool 
find_module(char *module)
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


equation_table *
find_equation_table(char *modname)
{
  equation_table *cur = tables;
  ATerm t_module = ATmake("<str>", modname);

  while (cur && !ATisEqual(cur->module, t_module)) {
    cur = cur->next;
  }

  return cur;
}



/*
  The equations are ``sorted'' by outermost function symbols.
  This is performed by the function ``sort_and_filter_on_ofs''.
  This function adds the equations with the same ofs in the
  left hand side of an equation to the database, and returns
  the original list of equations minus the equations which
  where stored.
*/

void
enter_equations(char *modname, ASF_CondEquationList eqsList)
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


void
delete_equations(char *modname)
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

ASF_Condition prepare_cond(ASF_Condition cond)
{
  PT_Tree lhs, rhs;
  
  lhs = ASFtoPT(ASF_getConditionLhs(cond));
  cond = ASF_setConditionLhs(cond, PTtoASF(RWprepareTerm(lhs)));
    
  rhs = ASFtoPT(ASF_getConditionRhs(cond));
  cond = ASF_setConditionRhs(cond, PTtoASF(RWprepareTerm(rhs)));

  return cond;
}

ASF_Conditions prepareConditions(ASF_Conditions conds)
{
  ASF_ConditionList  condList = ASF_getConditionsList(conds);
  
  condList = ASF_visitConditionList(condList, prepare_cond, NULL, NULL, NULL);

  return ASF_setConditionsList(conds, condList);
}

/*
Prepare an equation for rewriting. This includes removing the layout,
and translating lexicals into lists.
*/

ASF_CondEquation prepareEquation(ASF_CondEquation equ)
{
  ASF_Equation equation;

  if (ASF_isCondEquationWhen(equ) || ASF_isCondEquationImplies(equ)) {
    equ = ASF_setCondEquationConditions(equ,
            prepareConditions(ASF_getCondEquationConditions(equ)));
  }

  equation = ASF_getCondEquationEquation(equ);

  equation = ASF_setEquationLhs(equation,
          PTtoASF(RWprepareTerm(ASFtoPT(ASF_getEquationLhs(equation)))));

  equation = ASF_setEquationRhs(equation,
          PTtoASF(RWprepareTerm(ASFtoPT(ASF_getEquationRhs(equation)))));

  return ASF_setCondEquationEquation(equ, equation); 
}

/*
 * lexicalToList converts a lexical into a list.
 */

static PT_Tree lexicalToList(PT_Tree lextrm)
{
  PT_Symbol sort, rhs; 
  PT_Production lexProd;
  ASF_CHAR newChar; 
  ASF_Tree newname;
  ASF_Tree newTree;
  PT_Tree newPTtree;
  PT_Args charList;
  PT_Tree treeChar;
  char *lexstr, *sortstr;
  ASF_CHARList newCharList = NULL;
  int i, l;
  ATerm annos = AT_getAnnotations(PT_makeTermFromTree(lextrm));

  lexProd = PT_getTreeProd(lextrm);
  rhs = PT_getProductionRhs(lexProd);
  sort = PT_getSymbolSymbol(rhs);

  if (!PT_isSymbolSort(sort)) {
    ATerror("not a sort: %t\n", (ATerm) sort);
  }
  sortstr = strdup(PT_getSymbolString(sort));
  
  for (i = 0; sortstr[i]; i++) {
    sortstr[i] = tolower(sortstr[i]);
  }

  /* Get the string name that represents the lexical */
  lexstr = PT_yieldTree(lextrm);
  l = strlen(lexstr);
  for (i = l-1; i >= 0; i--) {
    charList = PT_makeArgsList(
                 PT_makeTreeChar('\"'),
                 PT_makeArgsList(
                   PT_makeTreeChar(lexstr[i]),
                   PT_makeArgsList(
                     PT_makeTreeChar('\"'),
                     PT_makeArgsEmpty())));

    treeChar = PT_makeTreeFlatLexical(charList);
    newChar = ASF_makeCHARLexToCf((ASF_Lexical)treeChar);
    if (i != l-1) {
      newCharList = ASF_makeCHARListMany(newChar, 
                                         ASF_makeLayoutEmpty(), 
                                         newCharList);
    }
    else {
      newCharList = ASF_makeCHARListSingle(newChar);
    }
  }

  assert(newCharList != NULL);

  newname = PTtoASF(PT_makeTreeLit(sortstr));

  newTree = ASF_makeTreeLexicalConstructor(
              sortstr,
              (ASF_Symbol) rhs, 
              newname,
              ASF_makeLayoutEmpty(),
              ASF_makeLayoutEmpty(),
              newCharList,
              ASF_makeLayoutEmpty());
  
  free(sortstr);

  newPTtree = ASFtoPT(newTree);
  
  if (annos != NULL) {
    newPTtree = PT_makeTreeFromTerm(
                 AT_setAnnotations(PT_makeTermFromTree(newPTtree), annos));
  }

  return newPTtree;
}

static PT_Tree prepareTerm(PT_Tree tree, PT_TreeVisitorData data)
{
  PT_Tree result;
  PT_Args args, newargs;

  extern ATerm ASF_patternTreeLexicalConstructor;
  if (ATmatchTerm(PT_makeTermFromTree(tree), ASF_patternTreeLexicalConstructor, 
		  NULL, NULL, NULL, NULL, NULL, NULL, NULL)) {
  /* <PO> was: if (ASF_isTreeLexicalConstructor(PTtoASF(tree))) {*/
    result = tree;
  }
  else if (PT_isTreeLexical(tree)) {
    result = lexicalToList(tree);
  }
  else if (PT_isTreeBracket(tree)) {
    result = prepareTerm(PT_getTreeBracketTree(tree), data);
  }
  else if (PT_isTreeAppl(tree)) {
    args = PT_getTreeArgs(tree);
    newargs = PT_foreachTreeInArgs(args, prepareTerm, data);
    result = PT_setTreeArgs(tree, newargs);
  }
  else {
    result = tree;
  }

  return result;
}

PT_Tree RWprepareTerm(PT_Tree tree)
{
return  prepareTerm(tree, NULL);
}

/*
Prepare a list of equations for rewriting.
*/

ASF_CondEquationList RWprepareEquations(ASF_CondEquationList eqsList)
{
  return ASF_visitCondEquationList(eqsList, prepareEquation, NULL);
}


void
RWflushEquations()
{
  equation_table *table;
  while (tables) {
    table = tables;
    tables = tables->next;
    destroy_equation_table(table);
  }
}

static PT_Production makeLexToCfProd(PT_Symbol symbol)
{
  PT_Symbol lex = PT_makeSymbolLex(symbol);
  PT_Symbol cf = PT_makeSymbolCf(symbol);
  
  PT_Symbols symbols = PT_makeSymbolsList(lex, PT_makeSymbolsEmpty());

  return PT_makeProductionDefault(symbols, cf, PT_makeAttributesNoAttrs());
}

/* list_to_lexical converts  a list representing a lexical into a
 * lexical again. 
 */

PT_Tree listToLexical(PT_Tree lexappl)
{
  ASF_Tree tree = PTtoASF(lexappl);
  ASF_CHARList charList;
  PT_Symbol symbol;
  ATerm annos = AT_getAnnotations(PT_makeTermFromTree(lexappl));
  PT_Tree newTree, charTree, listChar;
  PT_Args listChars, newCharList = PT_makeArgsEmpty();

  if (!ASF_isTreeLexicalConstructor(tree)) {
    ATerror("listToLexical: not a lexical constructor %t\n", lexappl);
  }

  symbol = PT_getSymbolSymbol((PT_Symbol) ASF_getTreeSymbol(tree));

  charList = ASF_getTreeList(tree);
  
  while(ASF_hasCHARListHead(charList)) {
    ASF_CHAR ch = ASF_getCHARListHead(charList);
    if (ASF_isCHARLexToCf(ch)) {
      charTree = PT_makeTreeFromTerm(ASF_getCHARLex(ch));
      listChars = PT_getTreeArgs(charTree);
      listChar = PT_getArgsArgumentAt(listChars,1);
      newCharList = PT_appendArgs(newCharList, listChar);
    }
    if (ASF_hasCHARListTail(charList)) {  
      charList = ASF_getCHARListTail(charList);
    } 
    else {
      break;
    } 
  }
    
  newTree = PT_makeTreeFlatLexical(newCharList);
  newTree = PT_makeTreeAppl(makeLexToCfProd(symbol), 
              PT_makeArgsList(newTree,
                PT_makeArgsEmpty()));

  if (annos != NULL) {
    newTree = PT_makeTreeFromTerm(
                 AT_setAnnotations(PT_makeTermFromTree(newTree), annos));
  }
 
  return newTree; 
}


static PT_Tree restoreTerm(PT_Tree tree, PT_TreeVisitorData data)
{
  PT_Args args;

  if (PT_isTreeAppl(tree)) {
    extern ATerm ASF_patternTreeLexicalConstructor;
    if (ATmatchTerm(PT_makeTermFromTree(tree),
		    ASF_patternTreeLexicalConstructor,
		    NULL, NULL, NULL, NULL, NULL, NULL, NULL)) {
    /* <PO> Was: if (ASF_isTreeLexicalConstructor(PTtoASF(tree))) { */
      return listToLexical(tree);
    }

    args = PT_getTreeArgs(tree);
    args = PT_foreachTreeInArgs(args, restoreTerm, data);
    return PT_setTreeArgs(tree, args);
  }

  return tree;
}


PT_Tree RWrestoreTerm(PT_Tree tree)
{
  return restoreTerm(tree, NULL);
}
