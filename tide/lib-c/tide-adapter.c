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

#define ASSERT_VALID_PID(pid)	(assert((pid) >= 0 && (pid) < MAX_PROCESSES && \
					processes[(pid)].id == (pid)))

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
  char       *name;
  int         state;
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

static int tide_cid = -1;
static ATbool connected = ATfalse;

static TA_Process processes[MAX_PROCESSES];

static int nr_functions = 0;
static TA_FunctionRecord functions[MAX_FUNCTIONS];


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

  ATerror("unknown port: %t\n", TA_makeTermFromPort(port));
  return -1;
}

/*}}}  */

/*{{{  TA_Value eval_unknown(int pid, AFun fun, TA_Values args) */

TA_Value eval_unknown(int pid, AFun fun, TA_Values args)
{
  return TA_makeValueError("unknown function", TA_makeValueStrConst(ATgetName(fun)));
}

/*}}}  */
/*{{{  TA_Value eval_true(int pid, AFun fun, TA_Values args) */

TA_Value eval_true(int pid, AFun fun, TA_Values args)
{
  return TA_makeValueTrue();
}

/*}}}  */
/*{{{  TA_Value eval_false(int pid, AFun fun, TA_Values args) */

TA_Value eval_false(int pid, AFun fun, TA_Values args)
{
  return TA_makeValueFalse();
}

/*}}}  */
/*{{{  TA_Value eval_cpe(int pid, AFun fun, TA_Values args) */

TA_Value eval_cpe(int pid, AFun fun, TA_Values args)
{
  ASSERT_VALID_PID(pid);
  return TA_makeValueLocation(processes[pid].cpe);
}

/*}}}  */

/*{{{  void TA_connect() */

void TA_connect()
{
  int pid;

  tide_cid = ATBconnect("debug-adapter", NULL, TIDE_PORT,
			debug_adapter_handler);
  if (tide_cid < 0) {
    ATerror("could not connect to tide.\n");
  }

  TA_initTAApi();

  for (pid=0; pid<MAX_PROCESSES; pid++) {
    processes[pid].id = PID_FREE;
  }

  TA_registerFunction(ATmakeAFun("true",  0, ATfalse), eval_true);
  TA_registerFunction(ATmakeAFun("false", 0, ATfalse), eval_false);
  TA_registerFunction(ATmakeAFun("cpe",   0, ATfalse), eval_cpe);

  connected = ATtrue;
}

/*}}}  */
/*{{{  ATbool TA_isConnected() */

ATbool TA_isConnected()
{
  return connected;
}

/*}}}  */
/*{{{  void TA_handleOne() */

void TA_handleOne()
{
  if (ATBhandleOne(tide_cid) < 0) {
    TA_disconnect(ATfalse);
  }
}

/*}}}  */

/*{{{  void TA_registerFunction(AFun name, TA_Function func) */

void TA_registerFunction(AFun name, TA_Function func)
{
  if (nr_functions == MAX_FUNCTIONS) {
    ATabort("TA_registerFunction: too many functions (%d)\n", MAX_FUNCTIONS);
  }
  functions[nr_functions].name = name;
  ATprotectAFun(functions[nr_functions].name);
  functions[nr_functions].function = func;
  nr_functions++;
}

/*}}}  */
/*{{{  void TA_disconnect(ATbool close) */

void TA_disconnect(ATbool close)
{
  int pid;

  if (close) {
    ATBwriteTerm(tide_cid, ATparse("snd-disconnect"));
  }

  /* Activate all processes */
  for (pid=0; pid<MAX_PROCESSES; pid++) {
    if (processes[pid].id != PID_FREE) {
      TA_setProcessState(pid, STATE_RUNNING);
    }
  }  

  connected = ATfalse;
}

/*}}}  */

/*{{{  int TA_createProcess(char *name) */

int TA_createProcess(char *name)
{
  int pid;

  for (pid=0; pid<MAX_PROCESSES; pid++) {
    if (processes[pid].id == PID_FREE) {
      int port, rid;

      processes[pid].id = pid;
      processes[pid].name = strdup(name);
      if (processes[pid].name == NULL) {
	ATerror("TA_createProcess: out of memory\n");
      }
      processes[pid].cpe = NULL;
      ATprotect((ATerm *)&processes[pid].cpe);
      for (port=0; port<MAX_PORT_TYPES; port++) {
	processes[pid].enabled_rules[port] = NULL;
      }
      for (rid=0; rid<MAX_EVENT_RULES; rid++) {
	processes[pid].rules[rid].id = RID_FREE;
      } 
      ATBpostEvent(tide_cid, ATmake("process-created(<int>,<str>)", pid, name));
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

      ATprotect((ATerm *)&rule->port);
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

  assert(rule);
  assert(rule->enabled == ATfalse);

  rule->enabled = ATtrue;

  rule->next = process->enabled_rules[rule->port_type];
  rule->prev = NULL;
  process->enabled_rules[rule->port_type] = rule;
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

void TA_atCPE(int pid, TA_Location cpe)
{
  ASSERT_VALID_PID(pid);
  processes[pid].cpe = cpe;
}

/*}}}  */
/*{{{  static void triggerRule(int pid, TA_Rule *rule) */

static void triggerRule(int pid, TA_Rule *rule)
{
  TA_Value value = TA_evaluate(pid, rule->action);

  ATfprintf(stderr, "actions of rule %d (%t) evaluate to %t\n",
	    rule->id, rule->action, value);

  ATBpostEvent(tide_cid, ATmake("event(<int>,<int>,<term>)",
				pid, rule->id, TA_makeTermFromValue(value)));
}

/*}}}  */
/*{{{  static void activateRule(int pid, TA_Rule *rule) */

static void activateRule(int pid, TA_Rule *rule)
{
  TA_Value value = TA_evaluate(pid, rule->condition);

  ATfprintf(stderr, "condition of rule %d (%t,%t) evaluates to %t\n",
	    rule->id, rule->port, rule->condition, value);

  if (TA_isValueTrue(value)) {
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

  ATfprintf(stderr, "activating rules of type %d (%t)\n", port_type, port);

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
}

/*}}}  */

/*{{{  TA_Function findFunction(AFun name) */

TA_Function findFunction(AFun name)
{
  int i;

  for (i=0; i<nr_functions; i++) {
    if (functions[i].name == name) {
      return functions[i].function;
    }
  }

  return eval_unknown;
}

/*}}}  */

/*{{{  TA_Values evaluateList(int pid, ATermList elems) */

TA_Values evaluateList(int pid, ATermList elems)
{
  if (ATisEmpty(elems)) {
    return TA_makeValuesEmpty();
  }

  return TA_makeValuesList(TA_evaluate(pid, TA_makeExprFromTerm(ATgetFirst(elems))), 
			   evaluateList(pid, ATgetNext(elems)));
}

/*}}}  */
/*{{{  TA_Value TA_evaluate(int pid, TA_Expr expr) */

TA_Value TA_evaluate(int pid, TA_Expr expr)
{
  ATerm term = TA_makeTermFromExpr(expr);

  switch (ATgetType(term)) {
    case AT_APPL:
      {
	ATermAppl appl  = (ATermAppl)term;
	AFun afun       = ATgetAFun(appl);
	TA_Function fun = findFunction(afun);
	TA_Values args  = evaluateList(pid, ATgetArguments(appl));
	return (*fun)(pid, afun, args);
      }
      break;

    case AT_LIST:
      {
	ATermList list = (ATermList)term;
	TA_Values vals = evaluateList(pid, list);
	return TA_makeValueList(vals);
      }
      break;

    default:
      return TA_makeValueFromTerm(term);
  }
}

/*}}}  */

