
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

#include "eval-tide.h"
#include "preparation.h"

#ifdef USE_TIDE
#include <tide-adapter.h>
#endif

/*}}}  */

#ifdef USE_TIDE

/*{{{  variables */

static ATbool connected = ATfalse;

static int pid;
static ATerm env = NULL;

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

  /*{{{  Lookup variable in environment */

  while (list && !ATisEmpty(list)) {
    ATermAppl tuple = (ATermAppl) ATgetFirst(list);
    ATermAppl variable = (ATermAppl) ATgetArgument(tuple, 0);
    ATerm name = ATgetArgument(variable, 0);
    if (ATisEqual(name, var)) {
      PT_Tree val = PT_makeTreeFromTerm(ATgetArgument(tuple, 1));
      val = RWrestoreTerm(val);
      return ATmake("<str>", PT_yieldTree(val));
    }
    list = ATgetNext(list);
  }

  /*}}}  */

  return ATmake(result, "error(\"unknown variable\",<str>)", var);
}

/*}}}  */
/*{{{  static TA_Expr eval_source_var(int pid, AFun fun, TA_ExprList args) */

#define MAX_VAR_LENGTH 256

static TA_Expr eval_source_var(int pid, AFun fun, TA_ExprList args)
{
#if 0
  int i, pos, linenr, column, posstart, start, end, len;
  int diff_start, length, dist, nat_value;
  char *line, *str_value;
  char var[MAX_VAR_LENGTH];
  AFun name;
  ATerm value;


  pos    = ATgetInt((ATermInt)ATgetFirst(args));
  args   = ATgetNext(args);
  linenr = ATgetInt((ATermInt)ATgetFirst(args));
  args   = ATgetNext(args);
  column = ATgetInt((ATermInt)ATgetFirst(args));
  args   = ATgetNext(args);
  name   = ATgetAFun((ATermAppl)ATgetFirst(args));
  line   = ATgetName(name);

  len = strlen(line);
  if (len <= column) {
    return ATparse("error(\"illegal column\"");
  }

  for (dist=0; dist<len; dist++) {
    int left, right;

    right = column + dist;
    if (right < len && isalnum(line[right])) {
      pos += (right-column);
      column = right;
      break;
    }

    left = column - dist;
    if (left >= 0 && isalnum(line[left])) {
      pos -= (column-left);
      column = left;
      break;
    }
  }

  /* Extend start to the left */
  start = column;
  while(ATtrue) {
    while (start > 1 && isalpha(line[start-1])) {
      start--;
    }
    for (posstart=start-1; posstart > 0 && isdigit(line[posstart]); posstart--) {
    }
    if (isalpha(line[posstart])) {
      start = posstart;
    } else {
      break;
    }
  }

  /* Extend end to the right */
  end = column;
  while (end < (len-1) && isalnum(line[end+1])) {
    end++;
  }

  diff_start = start - column;
  length     = end   - start + 1;

  length = MIN(length, MAX_VAR_LENGTH-1);

  strncpy(var, line+start, length);
  var[length] = '\0';
  
  fprintf(stderr, "looking up variable: %s\n", var);

  value = ATparse("unknown");

  for(i=0; i<nr_vars; i++) {
    if(strcmp(variables[i].name, var) == 0) {
      switch(variables[i].type) {
	case TYPE_NAT:
	  if (done) {
	    nat_value = variables[i].value.nat_value;
	  } else {
	    nat_value = *variables[i].address.nat_ptr;
	  }
	  fprintf(stderr, "retrieving var %s, done=%d, value=%d\n",
		  var, done, nat_value);
	  value = (ATerm)ATmakeInt(nat_value);
	  break;

	case TYPE_STR:
	  if (done) {
	    str_value = variables[i].value.str_value;
	  } else {
	    str_value = *variables[i].address.str_ptr;
	  }
	  value = ATmake("<str>", str_value);
	  break;
      }
    }
  }
  return ATmake("var(<str>,<term>,<int>,<int>,<int>,<int>)", var, value,
		pos + diff_start, linenr, column + diff_start, length);
#endif
  return ATmake("error(\"function not supported\",src-var)");
}

/*}}}  */

/*{{{  void Tide_connect() */

/*
 * Connect to tide
 */

void Tide_connect()
{
  char *name = "Asf+Sdf";

  TA_connect();

  TA_registerFunction(ATmakeAFun("resume", 0, ATfalse), eval_resume);
  TA_registerFunction(ATmakeAFun("break",  0, ATfalse), eval_break);
  TA_registerFunction(ATmakeAFun("var",    1, ATfalse), eval_var);
  TA_registerFunction(ATmakeAFun("source-var", 4, ATfalse), eval_source_var);

  pid = TA_createProcess(name);

  connected = ATtrue;
}

/*}}}  */
/*{{{  void Tide_disconnect() */

void Tide_disconnect()
{
  /* Switch off debugging */
  TA_disconnect(ATtrue);
  fprintf(stderr, "tide connection terminated.\n");

  connected = ATfalse;
}

/*}}}  */
/*{{{  void Tide_step(ATerm position, ATerm env, int level) */

/*
 * An atomic step is about to be executed
 */

void Tide_step(ATerm position, ATerm newenv, int level)
{
  if (connected) {
    env = newenv;

    TA_atCPE(pid, TA_makeLocationFromTerm(position));
    TA_activateRules(pid, TA_makePortStep());

    if (TA_getProcessState(pid) == STATE_STOPPED) {
      TA_activateRules(pid, TA_makePortStopped());

      while (TA_getProcessState(pid) == STATE_STOPPED) {
	TA_handleOne();
      }

      if (connected) {
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
