/*{{{  eval-tide.c */

/*
 *
 * This file contains support for the tide debugging system.
 *
 */

/*}}}  */

/*{{{  includes */

#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

#include <aterm2.h>
#include <atb-tool.h>

#include "evaluator.h"
#include "debug.h"
#include "equations.h"
#include "environment.h"

#include <tide-adapter.h>
#include <asc-support-me.h>
#include <Location.h>

/*}}}  */

/*{{{  variables */

ATerm pos_info;

static int pid;
static ATerm env = NULL;

static int             stack_level = -1;
static ASF_ASFTag         tag_stack[MAX_DEPTH];
static equation_entry *rule_stack[MAX_DEPTH];
static ATerm           env_stack[MAX_DEPTH];
static ATerm	       position_stack[MAX_DEPTH];

/*}}}  */

/*{{{  static PT_Tree find_variable(tree, line, col, target_line, target_col) */

static PT_Tree find_variable(PT_Tree tree, int *line, int *col,
			     int target_line, int target_col)
{
  /* if a variable contains the pointer (according to the pos-info attribute)
   * , we return it, * otherwise just keep on searching
   */
  if (PT_isTreeVar(tree)) {
    LOC_Location loc = PT_getTreeLocation(tree);
    LOC_Area area = LOC_getLocationArea(loc);

    if (LOC_getAreaBeginLine(area) <= target_line 
	&& LOC_getAreaEndLine(area) >= target_line 
	&& LOC_getAreaBeginColumn(area) <= target_col
	&& LOC_getAreaEndColumn(area) >= target_col) {
      return tree;
    }

    return NULL;
  }
  else {
    if (PT_hasTreeArgs(tree)) {
      PT_Args args = PT_getTreeArgs(tree);
      for ( ;!PT_isArgsEmpty(args); args = PT_getArgsTail(args)) {
	PT_Tree arg = PT_getArgsHead(args);

	arg = find_variable(arg, line, col, target_line, target_col);

	if (arg != NULL) {
	  return arg;
	}
      }
    }
  }

  return NULL;
}

/*}}}  */
/*{{{  static ATermList varlist_from_env(ATerm env) */

static ATermList varlist_from_env(ATerm environment)
{
  ATermList list = ATempty;
  ATermList env = (ATermList)environment;
  char *value;

  while (env && !ATisEmpty(env)) {
    ATermAppl tuple = (ATermAppl) ATgetFirst(env);
    ATermAppl variable = (ATermAppl) ATgetArgument(tuple, 0);
    /* Check for a 'slice' (list variable) */
    if (ATgetArity(ATgetAFun((ATermAppl)tuple)) == 3) {
      PT_Args args = appendSlice(PT_makeArgsEmpty(), (Slice)tuple);
      /*args = RWrestoreArgs(args, ATfalse);*/
      value = PT_yieldArgsToString(args, ATfalse);
    } else {
      ATerm val = ATgetArgument(tuple, 1);
      PT_Tree tree = PT_TreeFromTerm(val);
      /*tree = RWrestoreTerm(tree, ATfalse);*/
      value = PT_yieldTreeToString(tree, ATfalse);
    }
    list = ATinsert(list, ATmake("variable(<term>,<str>)", variable, value));
    env = ATgetNext(env);
  }

  return list;
}

/*}}}  */

/*{{{  static TA_Expr eval_resume(int pid, AFun fun, TA_ExprList args) */

static TA_Expr eval_resume(int pid, AFun fun, TA_ExprList args)
{
  TA_setProcessState(pid, STATE_RUNNING);
  
  return ATparse("true");
}

/*}}}  */
/*{{{  static TA_Expr eval_break(int pid, AFun fun, TA_ExprList args) */

static TA_Expr eval_break(int pid, AFun fun, TA_ExprList args)
{
  TA_setProcessState(pid, STATE_STOPPED);

  return ATparse("true");
}

/*}}}  */
/*{{{  static TA_Expr eval_var(int pid, AFun fun, TA_Values args) */


static TA_Expr eval_var(int pid, AFun fun, TA_ExprList args)
{
  char *var = ATgetName(ATgetAFun((ATermAppl)ATgetFirst(args)));
  char result[BUFSIZ];
  ATermList list = (ATermList) env;

  while (list && !ATisEmpty(list)) {
    ATermAppl tuple = (ATermAppl) ATgetFirst(list);
    ATermAppl variable = (ATermAppl) ATgetArgument(tuple, 0);
    ATerm name = ATgetArgument(variable, 0);
    if (ATisEqual(name, var)) {
      PT_Tree val = PT_TreeFromTerm(ATgetArgument(tuple, 1));
      /*val = RWrestoreTerm(val, ATfalse);*/
      return ATmake("<str>", PT_yieldTreeToString(val, ATfalse));
    }
    list = ATgetNext(list);
  }

  return ATmake(result, "error(\"unknown variable\",<str>)", var);
}

/*}}}  */
/*{{{  static TA_Expr eval_source_var(int pid, AFun fun, TA_ExprList args) */

#define MAX_VAR_LENGTH 256

static TA_Expr eval_source_var(int pid, AFun fun, TA_ExprList args)
{
  char *req_file, *name, *yield;
  int req_pos, req_line, req_col, diff_start;
  int line, col;
  PT_Tree equ_tree;
  PT_Tree var, value;
  ATerm val;

  if (!currentRule) {
    return TA_makeExprError("no current rule", NULL);
  }

  if (!ATmatch((ATerm)args, "[<str>,<int>,<int>,<int>,<str>]",
	       &req_file, &req_pos, &req_line, &req_col, NULL)) {
    return TA_makeExprError("illegal arguments", (ATerm)args);
  }

  equ_tree = (PT_Tree) currentRule->equation;

  line = 1;
  col  = 0;

  var = find_variable(equ_tree, &line, &col, req_line, req_col);

  if (var == NULL) {
    return TA_makeExprError("variable not available now", NULL);
  }
  diff_start = col - req_col;

  value = getVariableValue(env, var);

  if (value == NULL) {
    yield = "<uninitialized>";
  } else {
    yield = PT_yieldTreeToString(value, ATfalse);
  }


  val = ATmake("<str>", yield);
  name = PT_yieldTreeToString(var, ATfalse);

  return TA_makeExprVar(name, val, req_pos + diff_start, line, col, strlen(name));
}

/*}}}  */
/*{{{  static TA_Expr eval_list_sources(int pid, AFun fun, TA_ExprList args) */

static TA_Expr eval_list_sources(int pid, AFun fun, TA_ExprList args)
{
  equation_entry *entry;
  ATermList files = ATempty;
  int hnr, start_line, start_col, end_line, end_col;
  char *path;

  for (hnr=0; hnr<equations->size; hnr++) {
    for (entry=equations->table[hnr]; entry; entry=entry->hnext) {
      if (PT_getTreePosInfo(entry->lhs, &path, &start_line, &start_col,
			    &end_line, &end_col)) {
	ATerm file = (ATerm)ATmakeAppl0(ATmakeAFun(path, 0, ATtrue));
	if (ATindexOf(files, file, 0) == -1) {
	  files = ATinsert(files, file);
	}
      }
    }
  }

  return ATmake("source-list(<term>)", files);
}

/*}}}  */
/*{{{  static TA_Expr eval_stack_trace(int pid, AFun fun, TA_ExprList args) */


static TA_Expr eval_stack_trace(int pid, AFun fun, TA_ExprList args)
{
  ATermList frames = ATempty;
  ATerm frame;
  ATermList var_list;
  //static frame_name[BUFSIZ];
  char *frame_name; 
  int i;

  for (i=0; i<=stack_level; i++) {
    if (tag_stack[i] == NULL) {
      frame = ATmake("frame(<int>,\"anonymous\",location(unknown),[])", i);
    } else {
      var_list = varlist_from_env(env_stack[i]);
      frame_name = PT_yieldTreeToString(PT_TreeFromTerm(ASF_ASFTagToTerm(tag_stack[i])), ATfalse);

      frame = ATmake("frame(<int>,<str>,location(<term>),<term>)",
		     i, frame_name, position_stack[i], var_list);
    }
    frames = ATinsert(frames, frame);
  }

  return ATmake("stack(<term>)", frames);
}

/*}}}  */

/*{{{  void Tide_connect() */

void Tide_connect(int port)
{
  int cid;
  char *name = "ASF+SDF";

  pos_info = ATmake("pos-info");
  ATprotect(&pos_info);

  cid = TA_connect(port);
  setCid(cid);

  pid = TA_createProcess(cid, name);

  TA_registerFunction(pid, ATmakeAFun("resume",     0, ATfalse), eval_resume);
  TA_registerFunction(pid, ATmakeAFun("break",      0, ATfalse), eval_break);
  TA_registerFunction(pid, ATmakeAFun("var",        1, ATfalse), eval_var);
  TA_registerFunction(pid, ATmakeAFun("source-var", 5, ATfalse), eval_source_var);
  TA_registerFunction(pid, ATmakeAFun("list-sources", 0, ATfalse), eval_list_sources);
  TA_registerFunction(pid, ATmakeAFun("stack-trace",0, ATfalse), eval_stack_trace);
}

/*}}}  */
/*{{{  void Tide_disconnect() */

void Tide_disconnect()
{
  /* Switch off debugging */
  if (TA_isConnected()) {
    TA_disconnect(ATtrue, pid);
  }
  ATunprotect(&pos_info);
}

/*}}}  */
/*{{{  void Tide_step(ATerm position, ATerm env, int level) */

/*
 * An atomic step is about to be executed
 */

void Tide_step(ATerm position, ATerm newenv, int level)
{
  stack_level       = level;
  tag_stack[level]  = tagCurrentRule;
  rule_stack[level] = currentRule;
  position_stack[level] = position;
  env_stack[level] = newenv;

  if (TA_isConnected()) {
    int old_state;

    if (!position) {
      if (runVerbose) {
        ATwarning("Warning: position information not available\n");
      }
      return;
    }
	
    old_state = TA_getProcessState(pid);
    env = newenv;

    TA_atCPE(pid, TA_LocationFromTerm(position), level);
    TA_activateRules(pid, TA_makePortStep());

    if (TA_getProcessState(pid) == STATE_STOPPED) {
      if (old_state != STATE_STOPPED) {
	TA_activateRules(pid, TA_makePortStopped());
      }


      while (TA_getProcessState(pid) == STATE_STOPPED) {
	TA_handleAny(pid);
      }


      if (TA_isConnected()) {
			TA_activateRules(pid, TA_makePortStarted());
      }
    }
  }
}

/*}}}  */

/*{{{  void signal_handler(int sig) */

void signal_handler(int sig)
{
  fprintf(stderr, "signal handler called: %d\n", sig);
  TA_disconnect(ATtrue, pid);
  exit(1);
}

/*}}}  */

