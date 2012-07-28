/*{{{  includes */

#include <string.h>
#include <assert.h>

#include <atb-tool.h>

#include "tide-adapter.h"

/*}}}  */

/*{{{  defines */

#define PID_FREE -1
#define RID_FREE -1
#define MAX_FUNCTIONS 256

/*
#define ASSERT_VALID_PID(pid)	(assert((pid) >= 0 && (pid) < MAX_PROCESSES && \
					processes[(pid)].id == (pid)))
*/
#define ASSERT_VALID_PID(pid)	(assert((pid) >= 0 && (pid) < MAX_PROCESSES))

/*}}}  */

/*{{{  typedef struct TA_Rule */

typedef struct TA_Rule
{
  struct TA_Rule *next;
  struct TA_Rule *prev;

  int id;
  ATbool enabled;
  int port_type;
  TA_Port port;
  TA_Expr condition;
  TA_Expr action;
  ATerm   tag;
} TA_Rule;

/*}}}  */
/*{{{  typedef struct TA_Process */

typedef struct
{
  int         id;
  int         cid;
  char       *name;
  int         state;
  int         stack_level;
  int         start_level;
  TA_Location cpe;
  TA_Rule    *enabled_rules[MAX_PORT_TYPES];
  TA_Rule     rules[MAX_EVENT_RULES];
} TA_Process;

/*}}}  */
/*{{{  typedef struct TA_FunctionRecord */

typedef struct
{
  AFun name;
  TA_Function function;
} TA_FunctionRecord;

/*}}}  */

/*{{{  globals */

//static int tide_cid = -1;
static ATbool connected = ATfalse;

static TA_Process processes[MAX_PROCESSES];

static TA_FunctionRecord functions[MAX_PROCESSES][MAX_FUNCTIONS];	// functions are associated with a certain process
static int nr_functions[MAX_PROCESSES];									// and so are function amounts

#if DEVELOP
static int message_mask = TA_WARNING | TA_DEBUG;
#else
static int message_mask = TA_WARNING;
#endif


/*}}}  */

/*{{{  TA_Process *findProcess(int pid) */

TA_Process *findProcess(int pid)
{
  ASSERT_VALID_PID(pid);
  return &processes[pid];
}

/*}}}  */
/*{{{  TA_Rule *findRule(int pid, int rid) */

TA_Rule *findRule(int pid, int rid)
{
  TA_Process *process = findProcess(pid);

  assert(rid >= 0 && rid < MAX_EVENT_RULES && process->rules[rid].id != RID_FREE);

  return &process->rules[rid];
}

/*}}}  */

/*{{{  int TA_getPortType(TA_Port port) */

int TA_getPortType(TA_Port port)
{
  if (TA_isPortStep(port)) {
    return PORT_STEP;
  } else if (TA_isPortStopped(port)) {
    return PORT_STOPPED;
  } else if (TA_isPortStarted(port)) {
    return PORT_STARTED;
  }

  ATerror("unknown port: %t\n", TA_PortToTerm(port));
  return -1;
}

/*}}}  */

/*{{{  TA_Expr eval_true(int pid, AFun fun, TA_ExprList args) */

TA_Expr eval_true(int pid, AFun fun, TA_ExprList args)
{
  return ATparse("true");
}

/*}}}  */
/*{{{  TA_Expr eval_false(int pid, AFun fun, TA_ExprList args) */

TA_Expr eval_false(int pid, AFun fun, TA_ExprList args)
{
  return ATparse("false");
}

/*}}}  */
/*{{{  TA_Expr eval_cpe(int pid, AFun fun, TA_ExprList args) */

TA_Expr eval_cpe(int pid, AFun fun, TA_ExprList args)
{
  ASSERT_VALID_PID(pid);
  return ATmake("location(<term>)", processes[pid].cpe);
}

/*}}}  */
/*{{{  TA_Expr eval_location(int pid, AFun fun, TA_ExprList args) */

TA_Expr eval_location(int pid, AFun fun, TA_ExprList args)
{
  TA_Expr arg = ATgetFirst(args);
  TA_Location location = TA_LocationFromTerm(arg);
  TA_Location cpe = processes[pid].cpe;

  if (cpe == NULL) {
    return ATparse("false");
  }

  if (TA_isLocationLineCol(location)) {
    char *file = TA_getLocationFile(location);
    int   line = TA_getLocationLine(location);
    int   col  = TA_getLocationCol(location);

    char *cpe_file = TA_getLocationFile(cpe);

    if (strcmp(file, cpe_file) == 0) {
      if (TA_isLocationLine(cpe)) {
	if (line == TA_getLocationLine(cpe)) {
	  return ATparse("true");
	}
      } else if (TA_isLocationArea(cpe)) {
	int start_line = TA_getLocationStartLine(cpe);
	int start_col  = TA_getLocationStartCol(cpe);
	int end_line   = TA_getLocationEndLine(cpe);
	int end_col    = TA_getLocationEndCol(cpe);

	if (start_line < line || (start_line == line && start_col <= col)) {
	  if (end_line > line || (end_line == line && end_col >= col)) {
	    return ATparse("true");
	  }
	}
      }
    }
    return ATparse("false");
  } else {
    return ATmake("error(\"unsupported location\",<term>)", arg);
  }
}

/*}}}  */
/*{{{  TA_Expr eval_stack_level(int pid, AFun fun, TA_ExprList args) */

TA_Expr eval_stack_level(int pid, AFun fun, TA_ExprList args)
{
  TA_debug("stack_level=%d\n", processes[pid].stack_level);
  return (ATerm)ATmakeInt(processes[pid].stack_level);
}

/*}}}  */
/*{{{  TA_Expr eval_start_level(int pid, AFun fun, TA_ExprList args) */

TA_Expr eval_start_level(int pid, AFun fun, TA_ExprList args)
{
  TA_debug("start_level=%d\n", processes[pid].start_level);
  return (ATerm)ATmakeInt(processes[pid].start_level);
}

/*}}}  */
/*{{{  TA_Expr eval_equal(int pid, AFun fun, TA_ExprList args) */

TA_Expr eval_equal(int pid, AFun fun, TA_ExprList args)
{
  TA_Expr left = ATgetFirst(args);
  TA_Expr right = ATgetFirst(ATgetNext(args));

  if (ATgetType(left) != AT_INT || ATgetType(right) != AT_INT) {
    return ATmake("error(\"equal expects two integers\",<term>)", args);
  }

  if (ATgetInt((ATermInt)left) == ATgetInt((ATermInt)right)) {
    return ATparse("true");
  } else {
    return ATparse("false");
  }
}

/*}}}  */
/*{{{  TA_Expr eval_higher_equal(int pid, AFun fun, TA_ExprList args) */

TA_Expr eval_higher_equal(int pid, AFun fun, TA_ExprList args)
{
  TA_Expr left = ATgetFirst(args);
  TA_Expr right = ATgetFirst(ATgetNext(args));

  if (ATgetType(left) != AT_INT || ATgetType(right) != AT_INT) {
    return ATmake("error(\"higher-equal expects two integers\",<term>)", args);
  }

  if (ATgetInt((ATermInt)left) >= ATgetInt((ATermInt)right)) {
    return ATparse("true");
  } else {
    return ATparse("false");
  }
}

/*}}}  */
/*{{{  TA_Expr eval_less_equal(int pid, AFun fun, TA_ExprList args) */

TA_Expr eval_less_equal(int pid, AFun fun, TA_ExprList args)
{
  TA_Expr left = ATgetFirst(args);
  TA_Expr right = ATgetFirst(ATgetNext(args));

  if (ATgetType(left) != AT_INT || ATgetType(right) != AT_INT) {
    return ATmake("error(\"less-equal expects two integers\",<term>)", args);
  }

  if (ATgetInt((ATermInt)left) <= ATgetInt((ATermInt)right)) {
    return ATparse("true");
  } else {
    return ATparse("false");
  }
}

/*}}}  */
/*{{{  TA_Expr eval_higher(int pid, AFun fun, TA_ExprList args) */

TA_Expr eval_higher(int pid, AFun fun, TA_ExprList args)
{
  TA_Expr left = ATgetFirst(args);
  TA_Expr right = ATgetFirst(ATgetNext(args));

  if (ATgetType(left) != AT_INT || ATgetType(right) != AT_INT) {
    return ATmake("error(\"higher expects two integers\",<term>)", args);
  }

  if (ATgetInt((ATermInt)left) > ATgetInt((ATermInt)right)) {
    return ATparse("true");
  } else {
    return ATparse("false");
  }
}

/*}}}  */
/*{{{  TA_Expr eval_less(int pid, AFun fun, TA_ExprList args) */

TA_Expr eval_less(int pid, AFun fun, TA_ExprList args)
{
  TA_Expr left = ATgetFirst(args);
  TA_Expr right = ATgetFirst(ATgetNext(args));

  if (ATgetType(left) != AT_INT || ATgetType(right) != AT_INT) {
    return ATmake("error(\"less expects two integers\",<term>)", args);
  }

  if (ATgetInt((ATermInt)left) < ATgetInt((ATermInt)right)) {
    return ATparse("true");
  } else {
    return ATparse("false");
  }
}

/*}}}  */
/*{{{  int TA_connect(int port) */

int TA_connect(int port)
{
  int proc_cid = ATBconnect("debug-adapter", NULL, port, debug_adapter_handler);
  int pid;
  
  if (proc_cid < 0) {
    ATerror("could not connect to tide.\n");
  }

  if (connected) {	// already a process in existence, so skip remaining inits
    return proc_cid;
  }

  TA_initTAApi();

  for (pid=1; pid<MAX_PROCESSES; pid++) {
    processes[pid].id = PID_FREE;
  }

/* general functions are associated with pid=0 */
  TA_registerFunction(0, ATmakeAFun("true",         0, ATfalse), eval_true);
  TA_registerFunction(0, ATmakeAFun("false",        0, ATfalse), eval_false);
  TA_registerFunction(0, ATmakeAFun("cpe",          0, ATfalse), eval_cpe);
  TA_registerFunction(0, ATmakeAFun("location",     1, ATfalse), eval_location);
  TA_registerFunction(0, ATmakeAFun("stack-level",  0, ATfalse), eval_stack_level);
  TA_registerFunction(0, ATmakeAFun("start-level",  0, ATfalse), eval_start_level);
  TA_registerFunction(0, ATmakeAFun("equal",        2, ATfalse), eval_equal);
  TA_registerFunction(0, ATmakeAFun("higher-equal", 2, ATfalse), eval_higher_equal);
  TA_registerFunction(0, ATmakeAFun("less-equal",   2, ATfalse), eval_less_equal);
  TA_registerFunction(0, ATmakeAFun("higher",       2, ATfalse), eval_higher);
  TA_registerFunction(0, ATmakeAFun("less",         2, ATfalse), eval_less);

  connected = ATtrue;

  return proc_cid;
}

/*}}}  */
/*{{{  ATbool TA_isConnected() */

ATbool TA_isConnected()
{
  return connected;
}

/*}}}  */
/*{{{  void TA_handleOne() */

void TA_handleOne(int pid)
{
  int cid = findProcess(pid)->cid;
  
  if (ATBhandleOne(cid) < 0) {
    TA_disconnect(ATfalse, cid);
  }
}

void TA_handleAny(int pid)
{
  int cid = findProcess(pid)->cid;
  
  while (ATBhandleAny() != cid) {
	  if (!ATBisValidConnection(cid)) {
		  TA_disconnect(ATfalse, cid);
	  }
  }
}

/*}}}  */

/*{{{  void TA_registerFunction(AFun name, TA_Function func) */

void TA_registerFunction(int pid, AFun name, TA_Function func)
{
  if (nr_functions[pid] == MAX_FUNCTIONS) {
    ATabort("TA_registerFunction: too many functions (%d) for this process\n", MAX_FUNCTIONS);
  }
  functions[pid][nr_functions[pid]].name = name;
  ATprotectAFun(functions[pid][nr_functions[pid]].name);
  functions[pid][nr_functions[pid]].function = func;
  nr_functions[pid]++;
}

/*}}}  */
/*{{{  void TA_disconnect(ATbool close) */

void TA_disconnect(ATbool close, int pid)
{
  int cid = findProcess(pid)->cid;
  
  ATBdisconnect(cid);

  /* Activate all processes */
  for (pid=1; pid<MAX_PROCESSES; pid++) {
    if (processes[pid].id != PID_FREE) {
      TA_setProcessState(pid, STATE_RUNNING);
    }
  }  

  connected = ATfalse;
}

/*}}}  */

/*{{{  int TA_createProcess(int proc_cid, char *name) */

int TA_createProcess(int proc_cid, char *name)
{
  int pid;

  for (pid=1; pid<MAX_PROCESSES; pid++) {
    if (processes[pid].id == PID_FREE) {
      int port, rid;

      processes[pid].id = pid;
      processes[pid].cid = proc_cid;
      processes[pid].name = strdup(name);
      if (processes[pid].name == NULL) {
        ATerror("TA_createProcess: out of memory\n");
      }
      processes[pid].state = STATE_STOPPED;
      processes[pid].cpe = TA_makeLocationUnknown();
      TA_protectLocation(&processes[pid].cpe);
      for (port=0; port<MAX_PORT_TYPES; port++) {
        processes[pid].enabled_rules[port] = NULL;
      }
      for (rid=0; rid<MAX_EVENT_RULES; rid++) {
        processes[pid].rules[rid].id = RID_FREE;
      }
      ATBpostEvent(proc_cid, ATmake("process-created(<int>,<str>)", pid, name));
      ATBhandleOne(proc_cid);

      return pid;
    }
  }

  ATerror("TA_createProcess: too many processes (%d)\n", MAX_PROCESSES);
  return -1;
}

/*}}}  */
/*{{{  int TA_createRule(int pid, TA_Port port, TA_Expr cond, act, tag, enabled) */

int TA_createRule(int pid, TA_Port port, TA_Expr cond, TA_Expr act, ATerm tag,
		  ATbool enabled)
{
  int rid;
  TA_Process *process;

  ASSERT_VALID_PID(pid);

  process = &processes[pid];

  for (rid=0; rid<MAX_EVENT_RULES; rid++) {
    if (process->rules[rid].id == RID_FREE) {
      TA_Rule *rule = &process->rules[rid];

      rule->next      = NULL;
      rule->prev      = NULL;
      rule->id        = rid;
      rule->enabled   = ATfalse;
      rule->port_type = TA_getPortType(port);
      rule->port      = port;
      rule->condition = cond;
      rule->action    = act;
      rule->tag       = tag;

      ATprotectTerm(&rule->port);
      ATprotect((ATerm *)&rule->condition);
      ATprotect((ATerm *)&rule->action);
      ATprotect((ATerm *)&rule->tag);

      if (enabled) {
	     TA_enableRule(pid, rid);
      }

      return rid;
    }
  }

  ATabort("TA_createRule: too many rules (%d)\n", MAX_EVENT_RULES);

  return -1;
}

/*}}}  */
/*{{{  void TA_modifyRule(int pid, int rid, port, cond, act, enabled) */

void TA_modifyRule(int pid, int rid, TA_Port port, TA_Expr cond,
		   TA_Expr act, ATbool enabled)
{
  TA_Rule *rule = findRule(pid, rid);

  assert(rule);

  if (rule->enabled) {
    TA_disableRule(pid, rid);
  }

  rule->port      = port;
  rule->port_type = TA_getPortType(port);
  rule->condition = cond;
  rule->action    = act;

  if (enabled) {
    TA_enableRule(pid, rid);
  }
}

/*}}}  */
/*{{{  void TA_enableRule(int pid, int rid) */

void TA_enableRule(int pid, int rid)
{
  TA_Process *process = findProcess(pid);
  TA_Rule *rule       = findRule(pid, rid);
  TA_Rule *last;

  assert(rule);
  assert(rule->enabled == ATfalse);

  rule->enabled = ATtrue;

  last = process->enabled_rules[rule->port_type];
  if (last == NULL) {
    process->enabled_rules[rule->port_type] = rule;
    rule->prev = NULL;
  } else {
    while (last->next) {
      last = last->next;
    }
    last->next = rule;
    rule->next = NULL;
    rule->prev = last;
  }
}

/*}}}  */
/*{{{  void TA_disableRule(int pid, int rid) */

void TA_disableRule(int pid, int rid)
{
  TA_Process *process = findProcess(pid);
  TA_Rule *rule       = findRule(pid, rid);

  assert(rule);
  assert(rule->enabled == ATtrue);

  rule->enabled = ATfalse;

  if (rule->next) {
    rule->next->prev = rule->prev;
  }

  if (rule->prev) {
    rule->prev->next = rule->next;
  } else {
    process->enabled_rules[rule->port_type] = rule->next;
  }

  rule->next = NULL;
  rule->prev = NULL;
}

/*}}}  */
/*{{{  void TA_deleteRule(int pid, int rid) */

void TA_deleteRule(int pid, int rid)
{
  TA_Rule *rule       = findRule(pid, rid);

  assert(rule);
  if (rule->enabled == ATtrue) {
    TA_disableRule(pid, rid);
  }

  rule->id = RID_FREE;
  rule->port_type = -1;
  rule->port = NULL;
  rule->condition = NULL;
  rule->action = NULL;
  rule->tag = NULL;
}

/*}}}  */

/*{{{  void TA_atCPE(int pid, TA_Location cpe) */

void TA_atCPE(int pid, TA_Location cpe, int stack_level)
{
  ASSERT_VALID_PID(pid);
  processes[pid].cpe = cpe;
  processes[pid].stack_level = stack_level;
}

/*}}}  */

/*{{{  static void triggerRule(int pid, TA_Rule *rule) */

static void triggerRule(int pid, TA_Rule *rule)
{
  int cid = findProcess(pid)->cid;

  TA_Expr value = TA_evaluate(pid, rule->action);

  ATBpostEvent(cid, ATmake("event(<int>,<int>,<term>)", pid, rule->id, value)); 
  ATBhandleOne(cid);
}

/*}}}  */
/*{{{  static void activateRule(int pid, TA_Rule *rule) */

static void activateRule(int pid, TA_Rule *rule)
{
  TA_Expr value = TA_evaluate(pid, rule->condition);

  if (ATisEqual(value, ATparse("true"))) {
    triggerRule(pid, rule);
  }
}

/*}}}  */
/*{{{  void TA_activateRules(int pid, TA_Port port) */

void TA_activateRules(int pid, TA_Port port)
{
  TA_Rule *rules;
  int port_type;

  ASSERT_VALID_PID(pid);

  port_type = TA_getPortType(port);

  rules = processes[pid].enabled_rules[port_type];

  while (rules) {
    activateRule(pid, rules);
    rules = rules->next;
  }
}

/*}}}  */
/*{{{  int TA_getProcessState(int pid) */

int TA_getProcessState(int pid)
{
  ASSERT_VALID_PID(pid);
  return processes[pid].state;
}

/*}}}  */
/*{{{  void TA_setProcessState(int pid, int state) */

void TA_setProcessState(int pid, int state)
{
  ASSERT_VALID_PID(pid);
  processes[pid].state = state;

  if (state == STATE_RUNNING) {
    processes[pid].start_level = processes[pid].stack_level;
  }
}

/*}}}  */

/*{{{  TA_Function findFunction(AFun name) */

TA_Function findFunction(int pid, AFun name)
{
  int i;

  for (i=0; i<nr_functions[0]; i++) {	  // search general functions
    if (functions[0][i].name == name) {
      return functions[0][i].function;
    }
  }
  for (i=0; i<nr_functions[pid]; i++) {  // search pid specific functions
    if (functions[pid][i].name == name) {
      return functions[pid][i].function;
    }
  }

  return NULL;
}

/*}}}  */

/*{{{  TA_ExprList evaluateList(int pid, TA_ExprList elems) */

TA_ExprList evaluateList(int pid, TA_ExprList elems)
{
  if (ATisEmpty(elems)) {
    return elems;
  }

  return ATinsert(evaluateList(pid, ATgetNext(elems)),
		  TA_evaluate(pid, ATgetFirst(elems)));
}

/*}}}  */
/*{{{  TA_Expr TA_evaluate(int pid, TA_Expr expr) */

TA_Expr TA_evaluate(int pid, TA_Expr expr)
{
  switch (ATgetType(expr)) {
    case AT_APPL:
      {
			ATermAppl appl   = (ATermAppl)expr;
			AFun afun        = ATgetAFun(appl);
			
			TA_Function fun  = findFunction(pid, afun);
			TA_ExprList args = evaluateList(pid, ATgetArguments(appl));

			if (fun == NULL) {
			  return (TA_Expr)ATmakeApplList(afun, args);
			} else {
			  return (*fun)(pid, afun, args);
			}
		}
      break;

    case AT_LIST:
      {
			TA_ExprList list = (TA_ExprList)expr;
			return (TA_Expr)evaluateList(pid, list);
      }
      break;

    default:
		return expr;
  }
}

/*}}}  */

/*{{{  TA_Expr TA_makeExprError(char *msg, ATerm data) */

TA_Expr TA_makeExprError(char *msg, ATerm data)
{
  if (data == NULL) {
    data = (ATerm)ATempty;
  }

  return ATmake("error(<str>,<term>)", msg, data);
}

/*}}}  */
/*{{{  TA_Expr TA_makeExprUnknownVar(char *msg) */

TA_Expr TA_makeExprVarUnknown(char *msg)
{
  return ATmake("var-unknown(<str>)", msg);
}

/*}}}  */
/*{{{  TA_Expr TA_makeExprVar(var, value, pos, line, column, length) */

TA_Expr TA_makeExprVar(char *var, TA_Expr value, int pos,
		       int line, int column, int length)
{
  return ATmake("var(<str>,<term>,<int>,<int>,<int>,<int>)",
		var, value, pos, line, column, length);
}

/*}}}  */

/*{{{  void TA_vmsg(int level, char *pattern, va_list args) */

void TA_vmsg(int level, char *pattern, va_list args)
{
  if (message_mask & level) {
    ATvfprintf(stderr, pattern, args);
  }
}

/*}}}  */
/*{{{  void TA_msg(int level, char *pattern, ...) */

void TA_msg(int level, char *pattern, ...)
{
  va_list args;

  va_start(args, pattern);
  TA_vmsg(level, pattern, args);
  va_end(args);
}

/*}}}  */
/*{{{  void TA_debug(char *pattern, ...) */

void TA_debug(char *pattern, ...)
{
  va_list args;

  va_start(args, pattern);
  TA_vmsg(TA_DEBUG, pattern, args);
  va_end(args);
}

/*}}}  */
/*{{{  void TA_warning(char *pattern, ...) */

void TA_warning(char *pattern, ...)
{
  va_list args;

  va_start(args, pattern);
  TA_vmsg(TA_WARNING, pattern, args);
  va_end(args);
}

/*}}}  */

