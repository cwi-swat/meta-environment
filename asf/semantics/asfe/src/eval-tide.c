
/*
	$Id$
*/

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

#include "asfe.h"
#include "eval-tide.h"
#include "preparation.h"

#ifdef USE_TIDE
#include <tide-adapter.h>
#endif

/*}}}  */

#ifdef USE_TIDE

/*{{{  variables */

static int pid;
static ATerm env = NULL;

static int             stack_level = -1;
static ASF_Tag         tag_stack[MAX_DEPTH];
static equation_entry *rule_stack[MAX_DEPTH];
static ATerm           env_stack[MAX_DEPTH];
static ATerm	       position_stack[MAX_DEPTH];

/*}}}  */

/*{{{  static PT_Tree find_variable(tree, line, col, target_line, target_col) */

static PT_Tree find_variable(PT_Tree tree, int *line, int *col,
			     int target_line, int target_col)
{
  char *yield;
  int i, length, cur_line, cur_col;

  if (PT_isTreeVar(tree)) {
    return tree;
  }

  if (PT_isTreeAppl(tree)) {
    PT_Args args = PT_getTreeArgs(tree);
    while (!PT_isArgsEmpty(args)) {
      PT_Tree arg = PT_getArgsHead(args);
      yield = PT_yieldTree(arg);
      length = strlen(yield);
      cur_line = *line;
      cur_col  = *col;
      for (i=0; i<length; i++) {
	if (yield[i] == '\n') {
	  cur_line++;
	  cur_col = 0;
	} else {
	  cur_col++;
	}
      }
      if (cur_line > target_line
	  || (cur_line == target_line && cur_col >= target_col)) {
	return find_variable(arg, line, col, target_line, target_col);
      }
      *line = cur_line;
      *col  = cur_col;
      args = PT_getArgsTail(args);
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
    /*ATwarning("tuple=%t\n\n\n", tuple);*/
    if (ATgetArity(ATgetAFun((ATermAppl)tuple)) == 3) {
      PT_Args args = appendSlice(PT_makeArgsEmpty(), (Slice)tuple);
      args = RWrestoreArgs(args, ATfalse);
      value = PT_yieldArgs(args);
    } else {
      ATerm val = ATgetArgument(tuple, 1);
      PT_Tree tree = PT_TreeFromTerm(val);
      tree = RWrestoreTerm(tree, ATfalse);
      value = PT_yieldTree(tree);
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
      PT_Tree val = PT_makeTreeFromTerm(ATgetArgument(tuple, 1));
      val = RWrestoreTerm(val, ATfalse);
      return ATmake("<str>", PT_yieldTree(val));
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
  char *req_file, *file, *name, *yield;
  int req_pos, req_line, req_col, diff_start;
  int start_line, start_col, end_line, end_col;
  int line, col;
  PT_Tree equ_tree;
  ATerm pos_anno;
  PT_Tree var, value, restored;
  ATerm val;


  /*ATfprintf(stderr, "getting source var: %t\n", args);*/

  if (!currentRule) {
    return TA_makeExprError("no current rule", NULL);
  }

  if (!ATmatch((ATerm)args, "[<str>,<int>,<int>,<int>,<str>]",
	       &req_file, &req_pos, &req_line, &req_col, NULL)) {
    return TA_makeExprError("illegal arguments", (ATerm)args);
  }

  equ_tree =
    PT_makeTreeFromTerm(ASF_makeTermFromCondEquation(currentRule->equation));
  pos_anno = PT_getTreeAnnotation(equ_tree, posinfo);

  /*
  ATfprintf(stderr, "finding variable at line %d, col %d in %s (%t)\n",
	    req_line, req_col, PT_yieldTree(equ_tree), pos_anno);
   */

  if (!pos_anno) {
    return TA_makeExprError("no position information on equation", NULL);
  }

  if (!ATmatch(pos_anno, "area(<str>,<int>,<int>,<int>,<int>)",
	       &file, &start_line, &start_col, &end_line, &end_col)) {
    return TA_makeExprError("malformed position information", pos_anno);
  }
    
  if ((strcmp(file, req_file) != 0)
      || (req_line < start_line)
      || (req_line == start_line && req_col < start_col)
      || (req_line > end_line)
      || (req_line == end_line && req_col >= end_col)) {
    return TA_makeExprVarUnknown("outside current equation");
  }

  /*fprintf(stderr, "coordinates are inside current equation\n");*/

  line = start_line;
  col  = start_col;

  var = find_variable(equ_tree, &line, &col, req_line, req_col);

  if (var == NULL) {
    return TA_makeExprError("not a variable", NULL);
  }
  diff_start = col - req_col;

  /*fprintf(stderr, "variable found: '%s' at %d,%d (diff_start=%d)\n",*/
	  /*PT_yieldTree(var), line, col, diff_start);*/

  value = getVariableValue(env, var);

  if (value == NULL) {
    yield = "<uninitialized>";
  } else {
    restored = RWrestoreTerm(value, ATfalse);
    yield = PT_yieldTree(restored);
  }
  
  /*fprintf(stderr, "value = '%s'\n", yield);*/

  val = ATmake("<str>", yield);
  name = PT_yieldTree(var);
  
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
      frame_name = PT_yieldTree(PT_TreeFromTerm(ASF_TagToTerm(tag_stack[i])));

      frame = ATmake("frame(<int>,<str>,location(<term>),<term>)",
		     i, frame_name, position_stack[i], var_list);
    }
    frames = ATinsert(frames, frame);
  }

  return ATmake("stack(<term>)", frames);
}

/*}}}  */

/*{{{  void Tide_connect() */

/*
 * Connect to tide
 */

void Tide_connect()
{
  char *name = "Asf+Sdf";

  TA_registerFunction(ATmakeAFun("resume",     0, ATfalse), eval_resume);
  TA_registerFunction(ATmakeAFun("break",      0, ATfalse), eval_break);
  TA_registerFunction(ATmakeAFun("var",        1, ATfalse), eval_var);
  TA_registerFunction(ATmakeAFun("source-var", 5, ATfalse), eval_source_var);
  TA_registerFunction(ATmakeAFun("list-sources", 0, ATfalse), eval_list_sources);
  TA_registerFunction(ATmakeAFun("stack-trace",0, ATfalse), eval_stack_trace);

  TA_connect();

  pid = TA_createProcess(name);
}

/*}}}  */
/*{{{  void Tide_disconnect() */

void Tide_disconnect()
{
  /* Switch off debugging */
  if (TA_isConnected()) {
    TA_disconnect(ATtrue);
  }
}

/*}}}  */
/*{{{  void Tide_step(ATerm position, ATerm env, int level) */

/*
 * An atomic step is about to be executed
 */

void Tide_step(ATerm position, ATerm newenv, int level)
{
  /*
  PT_Tree equ_tree =
    PT_makeTreeFromTerm(ASF_makeTermFromCondEquation(currentRule->equation));
  fprintf(stderr, "Tide_step: cureq = %s\n", PT_yieldTree(equ_tree));
   */


  stack_level       = level;
  tag_stack[level]  = tagCurrentRule;
  rule_stack[level] = currentRule;
  position_stack[level] = position;
  env_stack[level] = newenv;

  if (TA_isConnected()) {
    int old_state;

    assert(tagCurrentRule);
    assert(currentRule);
    assert(position);

    if (!position) {
      static ATbool warning_printed = ATfalse;
      if (!warning_printed) {
	ATwarning("Position information not available or incomplete, "
		  "debugging will probably not work!\n");
	warning_printed = ATtrue;
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
	TA_handleOne();
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
  TA_disconnect(ATtrue);
  exit(1);
}

/*}}}  */

#endif
