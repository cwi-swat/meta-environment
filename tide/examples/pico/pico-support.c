
/*{{{  includes */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>

#include <tide-adapter.h>
#include <atb-tool.h>

#include "pico-support.h"

/*}}}  */
/*{{{  defines */

#define MAX_VARS 256
#define TYPE_NAT 0
#define TYPE_STR 1

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
  } u;
  string name;
} Var;

/*}}}  */
/*{{{  variables */

static Var variables[MAX_VARS];
static int nr_vars;

static int pid = -1;
static int last_line = -1;

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
  var->u.nat_ptr = address;
  
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
  var->u.str_ptr = address;
  
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
  
  for(i=0; i<nr_vars; i++) {
    var = &variables[i];
    switch(var->type) {
    case TYPE_NAT:
      printf("natural %s = %d\n", var->name, *var->u.nat_ptr);
      break;
    case TYPE_STR:
      printf("string %s = \"%s\"\n", var->name, *var->u.str_ptr);
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
    TA_Location cpe = TA_makeLocationLine(pid, linenr);
    last_line = linenr;

    TA_atCPE(pid, cpe);

    TA_activateRules(pid, TA_makePortStep());

    if(TA_getProcessState(pid) == STATE_STOPPED) {
      TA_activateRules(pid, TA_makePortStopped());
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

/*{{{  static TA_Value eval_resume(int pid, AFun fun, TA_Values args) */

static TA_Value eval_resume(int pid, AFun fun, TA_Values args)
{
  if (!TA_isValuesEmpty(args)) {
    ATerror("resume expects no arguments: %t\n", TA_makeTermFromValues(args));
  }

  TA_setProcessState(pid, STATE_RUNNING);

  return TA_makeValueTrue();
}

/*}}}  */
/*{{{  static TA_Value eval_break(int pid, AFun fun, TA_Values args) */

static TA_Value eval_break(int pid, AFun fun, TA_Values args)
{
  if (!TA_isValuesEmpty(args)) {
    ATerror("break expects no arguments: %t\n", TA_makeTermFromValues(args));
  }

  TA_setProcessState(pid, STATE_STOPPED);

  return TA_makeValueTrue();
}

/*}}}  */
/*{{{  static TA_Value eval_var(int pid, AFun fun, TA_Values args) */

static TA_Value eval_var(int pid, AFun fun, TA_Values args)
{
  int i;

  if (TA_isValuesList(args)) {
    TA_Value name = TA_getValuesHead(args);
    if (TA_isValueStrConst(name) && TA_isValuesEmpty(TA_getValuesTail(args))) {
      char *var = TA_getValueString(name);
      for(i=0; i<nr_vars; i++) {
	if(strcmp(variables[i].name, var) == 0) {
	  switch(variables[i].type) {
	    case TYPE_NAT:
	      return TA_makeValueIntConst(*variables[i].u.nat_ptr);

	    case TYPE_STR:
	      return TA_makeValueStrConst(*variables[i].u.str_ptr);

	    default:
	      return TA_makeValueError("illegal variable type",
				       TA_makeValueIntConst(variables[i].type));
	  }
	}
      }
      return TA_makeValueError("unknown variable", name);
    }
  }

  return TA_makeValueError("strange var spec", TA_makeValueList(args));
}

/*}}}  */

/*{{{  void init_debugging() */

static void init_debugging()
{
  TA_connect();

  TA_registerFunction(ATmakeAFun("resume", 0, ATfalse), eval_resume);
  TA_registerFunction(ATmakeAFun("break",  0, ATfalse), eval_break);
  TA_registerFunction(ATmakeAFun("var",    1, ATfalse), eval_var);

  pid = TA_createProcess(source);
}

/*}}}  */

void signal_handler(int sig)
{
  fprintf(stderr, "signal handler called: %d\n", sig);
  TA_disconnect(ATtrue);
  exit(1);
}

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
