/*{{{  includes */

#include <ctype.h>
#include <stdlib.h>
#include <assert.h>
#include <strings.h>
#include <string.h>
#include <aterm2.h>
#include <deprecated.h>
#include "equations.h"
#include "values.h"
#include "evaluator.h"
#include "asf-api.h"
#include "errors.h"

#include <MEPT.h>
#include <ASFME-utils.h>

/*}}}  */
/*{{{  defines */

/* These constants are dependent on Asfix2ME!!! */
#define DEPTH_OF_CONDITIONS_AND_EQUATION       2
#define DEPTH_OF_CONDITION_SIDES_IN_CONDITIONS 4
#define DEPTH_OF_EQUATION_SIDES_IN_EQUATION    2

/*}}}  */
/*{{{  variables */

equation_entry *currentRule = NULL;

equation_table *equations = NULL;

ATerm posinfo;
/*}}}  */

/*{{{  local function declarations */


/*}}}  */

/*{{{  void print_short_equation(int stack, const char *msg, equation_entry *entry) */

void print_short_equation(int stack, const char *msg, equation_entry *entry)
{
  if (runVerbose) {
    int i;
    for (i = 0; i < stack % 20; i++) {
      ATwarning(" ");
    }
    ATwarning("%s\t: %s ", msg, PT_yieldTree((PT_Tree)entry->tag));
    ATwarning("%s = ...\n", PT_yieldTree((PT_Tree)entry->lhs));
  }
}

/*}}}  */
/*{{{  equation_table *create_equation_table(int size) */

/* Allocate memory for an equation table.
*/

equation_table *create_equation_table(int size)
{
  int i;
  equation_table *table = (equation_table *) malloc(sizeof(equation_table));

  if (!table) {
    ATerror("out of memory in create_equation_table\n");
  }
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
/*{{{  static void flush_equations(equation_table * table) */

static void flush_equations(equation_table * table)
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
	      ASF_getCHARLISTString(
	        ASF_getTagIdChars(
		  ASF_getTagTagId(ASF_getCondEquationTag(equ)))), tree);
    return equ;
  }

  /* Annotate to a depth so that the list of conditions is annotated */
  tree = PT_addTreePosInfoSome(path, tree, DEPTH_OF_CONDITIONS_AND_EQUATION,
			       ATfalse, ATtrue, start_line, start_col);
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
      tree = PT_addTreePosInfoSome(path, tree,
				      DEPTH_OF_CONDITION_SIDES_IN_CONDITIONS,
				      ATfalse, ATtrue, start_line, start_col);
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
    tree = PT_addTreePosInfoSome(path, tree,
				    DEPTH_OF_EQUATION_SIDES_IN_EQUATION,
				    ATfalse, ATtrue, start_line, start_col);
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

/*{{{  static int moreSpecificArg(PT_Tree tree1, PT_Tree tree2) */

static int compareSpecificityArgs(PT_Args lhs1args, PT_Args lhs2args);

/* The specificity is expressed in an integer value:
 * -1: tree1 is less specific than tree2
 *  0: tree1 is or as specific as tree2, e.g. tree1 == tree2
 *  1: tree1 is more specific than tree2
 */
static int compareSpecificityArg(PT_Tree tree1, PT_Tree tree2)
{
  if (PT_isEqualTree(tree1, tree2) ||
      (PT_isTreeVar(tree1) && PT_isTreeVar(tree2))) {
    return 0;
  }
  else if (PT_isTreeVar(tree1) && !PT_isTreeVar(tree2)) {
    return -1;
  }
  else if (!PT_isTreeVar(tree1) && PT_isTreeVar(tree2)) {
    return 1;
  }
  else if (PT_isTreeAppl(tree1) && PT_isTreeAppl(tree2)) {
    PT_Production prod1 = PT_getTreeProd(tree1);
    PT_Production prod2 = PT_getTreeProd(tree2);
    if (PT_isEqualProduction(prod1, prod2)) {
      return compareSpecificityArgs(PT_getTreeArgs(tree1),
                                    PT_getTreeArgs(tree2));
    }
    else {
      return 0;
    }
  }
  else {
    return 0;
  }
}

/*}}}  */
/*{{{  static int compareSpecificityArgs(PT_Args lhs1args, ...) */

static int compareSpecificityArgs(PT_Args lhs1args, PT_Args lhs2args)
{
  int specificity;

  if (PT_hasArgsHead(lhs1args) && PT_hasArgsHead(lhs2args)) {
    PT_Tree head1 = PT_getArgsHead(lhs1args);
    PT_Tree head2 = PT_getArgsHead(lhs2args);

    specificity = compareSpecificityArg(head1, head2);
  
    if (specificity != 0) {
      return specificity;
    }
    else {
      return compareSpecificityArgs(PT_getArgsTail(lhs1args),
                                    PT_getArgsTail(lhs2args));
    }
  }
  return 0;
}

/*}}}  */
/*{{{  static int compareSpecificityLhs(PT_Tree lhs1, PT_Tree lhs2) */

static int compareSpecificityLhs(PT_Tree lhs1, PT_Tree lhs2)
{
  PT_Args lhs1args = PT_getTreeArgs(lhs1);
  PT_Args lhs2args = PT_getTreeArgs(lhs2);
  return compareSpecificityArgs(lhs1args, lhs2args);
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
  equation_entry *cur;

  if (useTide) {
    equation = add_equ_pos_info(equation);
  }

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

  cur = table->table[hnr];
  if (cur) {
    if (compareSpecificityLhs(entry->lhs, cur->lhs) >= 0 &&
        (!ASF_isTagDefault(tag) ||
         (ASF_isTagDefault(tag) && 
          ASF_isTagDefault(cur->tag)))) {
      entry->hnext = cur;
      table->table[hnr] = entry;
    } 
    else {
      if (ASF_isTagDefault(tag)) {
        ATbool entered = ATfalse;

        /* Skip the non-default rules */
        while (cur->hnext && 
               !ASF_isTagDefault(cur->tag)) {
          cur = cur->hnext;
        }

        while (cur->hnext) {
          if (compareSpecificityLhs(entry->lhs, 
                                    cur->hnext->lhs) >= 0) {
            entry->hnext = cur->hnext;
            cur->hnext = entry;
            entered = ATtrue;
            break;
          }
          cur = cur->hnext;
        }

        if (!entered) {
          entry->hnext = cur->hnext;
          cur->hnext = entry;
        }
      }
      else {
        ATbool entered = ATfalse;

        while (cur->hnext && !ASF_isTagDefault(cur->tag)) {
          if (compareSpecificityLhs(entry->lhs, 
                                    cur->hnext->lhs) >= 0) {
            entry->hnext = cur->hnext;
            cur->hnext = entry;
            entered = ATtrue;
            break;
          }
          cur = cur->hnext;
        }
        if (!entered) {
          entry->hnext = cur->hnext;
          cur->hnext = entry;
        }
      }
    }
  }
  else {
    entry->hnext = NULL;
    table->table[hnr] = entry;
  }

  print_short_equation(0, "registered", entry);
}

/*}}}  */
/*{{{  equation_entry *find_equation(from, top_ofs, first_ofs) */

equation_entry *find_equation(equation_entry * from, PT_Production top_ofs, 
			      PT_Production first_ofs)
{
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
/*{{{  void enter_equations(ASF_CondEquationList eqsList) */

/*
  The equations are ``sorted'' by outermost function symbols.
  This is performed by the function ``sort_and_filter_on_ofs''.
  This function adds the equations with the same ofs in the
  left hand side of an equation to the database, and returns
  the original list of equations minus the equations which
  where stored.
*/


void enter_equations(ASF_CondEquationList eqsList)
{
  equations = create_equation_table(ASF_getCondEquationListLength(eqsList) * 2);

  if (runVerbose) {
    ATwarning("reading in equations:\n");
  }

  while (ASF_hasCondEquationListHead(eqsList)) {
    enter_equation(equations, ASF_getCondEquationListHead(eqsList));

    if (ASF_hasCondEquationListTail(eqsList)) {
      eqsList = ASF_getCondEquationListTail(eqsList);
    }
    else {
      break;
    }
  }
}

/*}}}  */
/*{{{  void destroy_equation_table(equation_table * table) */


/*
 * Free all memory associated with an equation table.
 * */


void destroy_equation_table()
{
  flush_equations(equations);
  free(equations->table);
  free(equations);
}

/*}}}  */
