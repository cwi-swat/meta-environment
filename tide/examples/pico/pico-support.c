
/*{{{  includes */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <ctype.h>

#include <tide-adapter.h>
#include <atb-tool.h>

#include "pico-support.h"

/*}}}  */
/*{{{  defines */

#define MAX_VARS 256
#define TYPE_NAT 0
#define TYPE_STR 1

#define MAX_VAR_LENGTH 64

/*}}}  */
/*{{{  function declarations */

extern void picomain();

/*}}}  */
/*{{{  types */

typedef struct
{
  int type;
  union {
    int    *nat_ptr;
    string *str_ptr;
  } address;
  union {
    int    nat_value;
    string str_value;
  } value;
  string name;
} Var;

/*}}}  */
/*{{{  variables */

static Var variables[MAX_VARS];
static int nr_vars;

static int pid = -1;
static int last_line = -1;

static ATbool done;

/*}}}  */

/*{{{  int pico_natural(int *address, string name) */

int pico_natural(int *address, string name)
{
  Var *var;
  
  if(nr_vars == MAX_VARS) {
    fprintf(stderr, "too many variables (%d)!\n", nr_vars);
    abort();
  }
  
  var = &variables[nr_vars++];
  
  var->type = TYPE_NAT;
  var->name = name;
  var->address.nat_ptr = address;
  
  return 0;
}

/*}}}  */
/*{{{  string pico_string(string *address, string name) */

string pico_string(string *address, string name)
{
  Var *var;
  
  if(nr_vars == MAX_VARS) {
    fprintf(stderr, "too many variables (%d)!\n", nr_vars);
    abort();
  }
  
  var = &variables[nr_vars++];
  
  var->type = TYPE_STR;
  var->name = name;
  var->address.str_ptr = address;
  
  return "";
}

/*}}}  */
/*{{{  string pico_concat(string s1, string s2) */

string pico_concat(string s1, string s2)
{
  string result = (string)malloc(strlen(s1) + strlen(s2) + 1);
  if(result == NULL) {
    fprintf(stderr, "out of memory in pico_concat!\n");
    abort();
  }
  
  strcpy(result, s1);
  strcat(result, s2);
  
  return result;
}

/*}}}  */
/*{{{  void finish() */

void finish()
{
  int i;
  Var *var;
  
  done = ATtrue;
  for(i=0; i<nr_vars; i++) {
    var = &variables[i];
    switch(var->type) {
    case TYPE_NAT:
      var->value.nat_value = *var->address.nat_ptr;
      printf("natural %s = %d\n", var->name, var->value.nat_value);
      break;
    case TYPE_STR:
      var->value.str_value = *var->address.str_ptr;
      printf("string %s = \"%s\"\n", var->name, var->value.str_value);
      break;
    default:
      fprintf(stderr, "illegal variable type %d\n", var->type);
      abort();
    }
  }
}

/*}}}  */

/*{{{  void debugstep(int linenr) */

void debugstep(int linenr)
{
  if (TA_isConnected()) {
    int old_state = TA_getProcessState(pid);
    TA_Location cpe = TA_makeLocationLine(source, linenr);
    last_line = linenr;

    TA_atCPE(pid, cpe, 0);


    TA_activateRules(pid, TA_makePortStep());

    if(TA_getProcessState(pid) == STATE_STOPPED) {
      if (old_state != STATE_STOPPED) {
	TA_activateRules(pid, TA_makePortStopped());
      }
      while(TA_getProcessState(pid) == STATE_STOPPED) {
	TA_handleOne();
      }
      if (TA_isConnected()) {
	TA_activateRules(pid, TA_makePortStarted());
      }
    }
  }
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
  int i, nat_value;
  string str_value;

  AFun name = ATgetAFun((ATermAppl)ATgetFirst(args));
  char *var = ATgetName(name);
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
	  return (ATerm)ATmakeInt(nat_value);

	case TYPE_STR:
	  if (done) {
	    str_value = variables[i].value.str_value;
	  } else {
	    str_value = *variables[i].address.str_ptr;
	  }
	  return ATmake("<str>", str_value);
      }
    }
  }
  return ATmake("error(\"unknown variable\",<term>)", ATgetFirst(args));
}

/*}}}  */
/*{{{  static TA_Expr eval_source_var(int pid, AFun fun, TA_ExprList args) */

static TA_Expr eval_source_var(int pid, AFun fun, TA_ExprList args)
{
  int i, pos, linenr, column, posstart, start, end, len;
  int diff_start, length, dist, nat_value;
  char *line, *str_value;
  char var[MAX_VAR_LENGTH];
  AFun name;
  ATerm value;


  args   = ATgetNext(args); /* Skip source filename */
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
    if (right < len && isalnum((int)line[right])) {
      pos += (right-column);
      column = right;
      break;
    }

    left = column - dist;
    if (left >= 0 && isalnum((int)line[left])) {
      pos -= (column-left);
      column = left;
      break;
    }
  }

  /* Extend start to the left */
  start = column;
  while(ATtrue) {
    while (start > 1 && isalpha((int)line[start-1])) {
      start--;
    }
    for (posstart=start-1; posstart > 0 && isdigit((int)line[posstart]); 
	 posstart--) {
    }
    if (isalpha((int)line[posstart])) {
      start = posstart;
    } else {
      break;
    }
  }

  /* Extend end to the right */
  end = column;
  while (end < (len-1) && isalnum((int) line[end+1])) {
    end++;
  }

  diff_start = start - column;
  length     = end   - start + 1;

  length = MIN(length, MAX_VAR_LENGTH-1);

  strncpy(var, line+start, length);
  var[length] = '\0';
  
  fprintf(stderr, "looking up variable: %s\n", var);

  value = NULL;

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

  if (value == NULL) {
    return TA_makeExprVarUnknown(var);
  }
  
  return ATmake("var(<str>,<term>,<int>,<int>,<int>,<int>)", var, value,
		pos + diff_start, linenr, column + diff_start, length);
}

/*}}}  */

/*{{{  void init_debugging() */

static void init_debugging()
{
  char *name;

  TA_connect(TIDE_PORT);

  TA_registerFunction(ATmakeAFun("resume", 0, ATfalse), eval_resume);
  TA_registerFunction(ATmakeAFun("break",  0, ATfalse), eval_break);
  TA_registerFunction(ATmakeAFun("var",    1, ATfalse), eval_var);
  TA_registerFunction(ATmakeAFun("source-var", 5, ATfalse), eval_source_var);

  name = strrchr(source, '/');
  if (name) {
    name++; /* Skip '/' character */
  } else {
    name = source;
  }

  pid = TA_createProcess(name);
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

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  int i;
  ATerm stack_bottom;
  ATbool use_tide = ATfalse;
  
  /*{{{  Analyze arguments */
  
  for (i=1; i<argc; i++) {
    if (strcmp(argv[i], "-tide") == 0) {
      use_tide = ATtrue;
    }
  }
  
  /*}}}  */
  
  done = ATfalse;
  if(use_tide) {
    if (ATBinit(argc, argv, &stack_bottom)) {
      ATerror("could not initialize toolbus library.\n");
    }
    init_debugging();
  }
  
  picomain();
  
  if(use_tide) {
    TA_setProcessState(pid, STATE_STOPPED);
    debugstep(last_line+1);
  }
  
  return 0;
}

/*}}}  */
