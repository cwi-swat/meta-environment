
/*
	$Id$
*/

/*{{{  eval-tide.c */

/**
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
#include <AsFix.h>
#include <atb-tool.h>

#include "eval-tide.h"
#include "preparation.h"

#ifdef USE_TIDE
#include <debug-adapter.tif.h>
#include <debug-adapter.tif.c>
#endif

/*}}}  */
/*{{{  defines */

#define MAX_RULES   1024

/*}}}  */
/*{{{  types */

typedef struct
{
  ATbool enabled;
  ATerm type;
  ATerm port;
  int porttype;
  ATerm cond;
  ATerm act;
  union {
    struct {
      char *filename;
      int   linenr;
      int   column;
    } location;
  } data;
} Rule;

/*}}}  */

#ifdef USE_TIDE

/*{{{  variables */

int exec_state = STATE_STOPPED;
ATerm cpe = NULL;

static int tide = -1;
static char the_pid[32];

static Rule rules[MAX_RULES] = { { ATfalse, NULL, NULL, -1, NULL, NULL } };
static int  nr_enabled_rules[NR_PORT_TYPES] = { 0 };
static int  enabled_rules[NR_PORT_TYPES][MAX_RULES];

static int cur_rid = -1;

static ATerm env = NULL;
static int start_level = 0;
static int stack_level = 0;

/*}}}  */

/*{{{  static int get_porttype(ATerm port) */

/**
	* Determine the type of the port
	*/

static int get_porttype(ATerm port)
{
  AFun fun = ATgetAFun((ATermAppl)port);
  char *name = ATgetName(fun);

  if(strcmp(name, "step") == 0)
    return PORT_STEP;

  if(strcmp(name, "location") == 0)
    return PORT_LOCATION;

  if(strcmp(name, "var-access") == 0)
    return PORT_VAR_ACCESS;

  if(strcmp(name, "expr-changed") == 0)
    return PORT_EXPR_CHANGED;

  if(strcmp(name, "method-entry") == 0)
    return PORT_METHOD_ENTRY;

  if(strcmp(name, "method-exit") == 0)
    return PORT_METHOD_EXIT;

  if(strcmp(name, "stopped") == 0)
    return PORT_STOPPED;

  if(strcmp(name, "started") == 0)
    return PORT_STARTED;

  if(strcmp(name, "exception") == 0)
    return PORT_EXCEPTION;

  ATabort("uknown port: %t\n", port);
  return -1;
}

/*}}}  */
/*{{{  static void analyze_port(Rule *rule, ATerm port) */

/**
 * Analyze a port specification
 */

static void analyze_port(Rule *rule, ATerm port)
{
  rule->porttype = get_porttype(port);
	
  switch(rule->porttype) {
  case PORT_LOCATION:
    /*{{{  Analyze location spec. */

    {
      int linenr, column;
      char *filename;

      if(ATmatch(port, "location(pos(<str>,<int>,<int>))",
		 &filename, &linenr, &column)) {
	rule->data.location.filename = filename;
	rule->data.location.linenr   = linenr;
	rule->data.location.column   = column;
      } else if(ATmatch(port, "location(line(<str>,<int>))", 
			&filename, &linenr)) {
	rule->data.location.filename = filename;
	rule->data.location.linenr = linenr;
	rule->data.location.column = 0;
      } else {
	ATerror("illegal port spec: %t\n", port);
      }
    }

    /*}}}  */
    break;
  }
}

/*}}}  */

/*{{{  static void generate_watchpoint(int rid, ATerm watchpoint) */

static void generate_watchpoint(int rid, ATerm watchpoint)
{
  ATBpostEvent(tide, ATmake("watchpoint(<str>,<int>,<term>)",
			    the_pid, rid, watchpoint));
}

/*}}}  */
/*{{{  static ATerm eval_expr(ATerm expr) */

static ATerm eval_expr(ATerm expr)
{
  char *var;
  int n1, n2;
  ATerm t1, t2;

  if (ATgetType(expr) == AT_LIST) {
    ATermList list   = (ATermList) expr;
    ATermList result = ATempty;
    while (!ATisEmpty(list)) {
      ATerm res = eval_expr(ATgetFirst(list));
      list = ATgetNext(list);
      if (!ATisEqual(res, ATparse("true")))
	result = ATappend(result, res);
    }
    if (ATisEmpty(result))
      return ATparse("true");
    return (ATerm) result;
  }
	
  if (ATisEqual(expr, ATparse("true")))
    return expr;
	
  if (ATisEqual(expr, ATparse("false")))
    return expr;
	
  if (ATisEqual(expr, ATparse("break"))) {
    exec_state = STATE_STOPPED;
    return ATparse("true");
  }

  if (ATisEqual(expr, ATparse("resume"))) {
    exec_state = STATE_RUNNING;
    start_level = stack_level;
    return ATparse("true");
  }

  if (ATisEqual(expr, ATparse("cpe"))) {
    if(cpe)
      return ATmake("cpe(<term>)", cpe);
    else
      return ATmake("cpe(unknown)");
  }
	
  if (ATisEqual(expr, ATparse("state"))) {
    if (exec_state == STATE_RUNNING)
      return ATparse("running");
    else
      return ATparse("stopped");
  }

  if (ATisEqual(expr, ATparse("disable"))) {
    disable_rule(tide, the_pid, cur_rid);
    ATBpostEvent(tide, ATmake("rule-disabled(proc(<str>),<int>)", 
			      the_pid, cur_rid));
    return ATparse("true");
  }

  if(ATmatch(expr, "var(<term>)", &var)) {
    char result[BUFSIZ];
    ATermList list = (ATermList)env;

    /*{{{  Lookup variable in environment */

    while(list && !ATisEmpty(list)) {
      ATermAppl tuple    = (ATermAppl)ATgetFirst(list);
      ATermAppl variable = (ATermAppl)ATgetArgument(tuple, 0);
      ATerm name         = ATgetArgument(variable, 0);
      if(ATisEqual(name, var)) {
	ATerm val = ATgetArgument(tuple, 1);
	val = RWrestoreTerm(val);
	return ATmake("<str>", AFsourceToBuf(val));
      }
      list = ATgetNext(list);
    }

    /*}}}  */

    sprintf(result, "error(\"unknown variable: %s\")", 
	    ATgetName(ATgetAFun((ATermAppl)var)));
    return ATparse(result);
  }

  if(ATmatch(expr, "start-level")) {
    return ATmake("<int>", start_level);
  }

  if(ATmatch(expr, "stack-level")) {
    return ATmake("<int>", stack_level);
  }

  if(ATmatch(expr, "higher-equal(<term>,<term>)", &t1, &t2)) {
    t1 = eval_expr(t1);
    t2 = eval_expr(t2);
    /*ATfprintf(stderr, "higher-equal: %t,%t\n", t1, t2);*/
    if(ATgetType(t1) == AT_INT && ATgetType(t2) == AT_INT) {
      n1 = ATgetInt((ATermInt)t1);
      n2 = ATgetInt((ATermInt)t2);
      if(n1 >= n2)
	return ATmake("true");
    }
    return ATmake("false");
  }

  if(ATmatch(expr, "equal(<term>,<term>)", &t1, &t2)) {
    return ATisEqual(eval_expr(t1), eval_expr(t2)) ? 
      ATmake("true") : ATmake("false");
  }

	
  return ATmake("unknown-expression(<term>)", expr);
}

/*}}}  */
/*{{{  static void activate_rule(int rid) */

static void activate_rule(int rid)
{
  ATerm cond_result, act_result;

  if(rules[rid].porttype == PORT_LOCATION) {
    /*{{{  Check for the correct CPE */

    char *filename;
    int sl, sc, el, ec;
    char *fn = rules[rid].data.location.filename;
    int line = rules[rid].data.location.linenr;
    int col  = rules[rid].data.location.column;

    if(!cpe || !ATmatch(cpe, "area(<str>,<int>,<int>,<int>,<int>)",
			&filename, &sl, &sc, &el, &ec))
      return;

    if(strcmp(filename, fn) != 0)
      return;

    if(line < sl || (line == sl && col < sc))
      return;

    if(line > el || (line == el && col > ec))
      return;

    /* Position ok! */

    /*}}}  */
  }

  cond_result = eval_expr(rules[rid].cond);
  if (ATisEqual(cond_result, ATparse("true"))) {
    cur_rid = rid;
    act_result = eval_expr(rules[rid].act);
	
    if (ATisEqual(act_result, ATparse("true")))
      return;
		
    if (ATgetType(act_result) == AT_LIST) {
      ATermList list = (ATermList) act_result;
      while(!ATisEmpty(list)) {
	generate_watchpoint(rid, ATgetFirst(list));
	list = ATgetNext(list);
      }
    } else
      generate_watchpoint(rid, act_result);
  }
}

/*}}}  */
/*{{{  static void activate_rules(int porttype) */

static void activate_rules(int porttype)
{
  int i;
	
  for(i=0;i<nr_enabled_rules[porttype]; i++)
    activate_rule(enabled_rules[porttype][i]);
}

/*}}}  */

/*{{{  void disable_rule(int conn, char *pid, int rid) */

void disable_rule(int conn, char *pid, int rid)
{
  int porttype, last, i;

  if (!rules[rid].enabled)
    ATwarning("** Warning, disabling already disabled rule: %d\n", rid);

  rules[rid].enabled = ATfalse;
  porttype = rules[rid].porttype;
  last = --nr_enabled_rules[porttype];
  for(i=0; i<=last; i++)
    if(enabled_rules[porttype][i] == rid)
      break;
  if (i > last)
    ATabort("No such rule: %d\n", rid);

  enabled_rules[porttype][i] = enabled_rules[porttype][last];
}

/*}}}  */
/*{{{  void enable_rule(int conn, char *pid, int rid) */

void enable_rule(int conn, char *pid, int rid)
{
  int porttype, last;

  if (rules[rid].enabled) {
    ATwarning("** Warning, enabling already enabled rule: %d\n", rid);
    return;
  }

  porttype = rules[rid].porttype;
  last = nr_enabled_rules[porttype]++;
	
  fprintf(stderr, "enabled rule %d (porttype=%d), count=%d\n",
	  rid, porttype, nr_enabled_rules[porttype]);

  enabled_rules[porttype][last] = rid;

  rules[rid].enabled = ATtrue;
}

/*}}}  */
/*{{{  void modify_rule(conn, char *pid, rid, port, cond, act) */

void modify_rule(int conn, char *pid, int rid, 
		 ATerm port, ATerm cond, ATerm act)
{
  ATbool isActive = rules[rid].enabled;

  if(isActive)
    disable_rule(conn, pid, rid);
	
  rules[rid].port = port;
  rules[rid].cond = cond;
  rules[rid].act  = act;

  if(isActive)
    enable_rule(conn, pid, rid);
}

/*}}}  */
/*{{{  ATerm create_rule(conn, char *pid, type, port, cond, act) */

ATerm create_rule(int conn, char *pid, ATerm type, 
		  ATerm port, ATerm cond, ATerm act)
{
  int rid;

  for(rid=0; rules[rid].port && rid < MAX_RULES; rid++)
    ;
  if(rid >= MAX_RULES)
    ATerror("maximum number of rules (%d) exceeded.\n", MAX_RULES);

  rules[rid].enabled = ATfalse;
  rules[rid].type  = type;
  rules[rid].port  = port;
  rules[rid].cond  = cond;
  rules[rid].act   = act;

  rules[rid].porttype = get_porttype(port);

  ATprotect(&rules[rid].type);
  ATprotect(&rules[rid].port);
  ATprotect(&rules[rid].cond);
  ATprotect(&rules[rid].act);
	
  /*enable_rule(conn, pid, rid);*/

  return ATmake("snd-value(rule-created(<str>,<int>,<term>,<term>,<term>,"
		"<term>))", pid, rid, type, port, cond, act);
}

/*}}}  */
/*{{{  void delete_rule(int conn, char *pid, int rid) */

void delete_rule(int conn, char *pid, int rid)
{
  int i, porttype;

  porttype = rules[rid].porttype;

  if(rules[rid].enabled) {
    int last = --nr_enabled_rules[porttype];
    for(i=0; i<=last; i++) {
      if(enabled_rules[porttype][i] == rid) {
	enabled_rules[porttype][i] = enabled_rules[porttype][last];
	break;
      }
    }
  }

  ATunprotect(&rules[rid].type);
  ATunprotect(&rules[rid].port);
  ATunprotect(&rules[rid].cond);
  ATunprotect(&rules[rid].act);

  rules[rid].type  = NULL;
  rules[rid].port  = NULL;
  rules[rid].cond  = NULL;
  rules[rid].act   = NULL;
}

/*}}}  */
/*{{{  void rec_ack_event(int conn, ATerm evt) */

void rec_ack_event(int conn, ATerm evt)
{
}

/*}}}  */
/*{{{  ATerm evaluate(int conn, char *pid, ATerm expr) */

ATerm evaluate(int conn, char *pid, ATerm expr)
{
  return ATmake("snd-value(evaluated(<str>,<term>,<term>))",
		pid, expr, eval_expr(expr));
}

/*}}}  */

/*{{{  void Tide_connect() */

/**
 * Connect to tide
 */

void Tide_connect()
{
  ATbool inited = ATfalse;
  
  if(tide == -1) {
    tide = ATBconnect("debug-adapter", NULL, TIDE_PORT, 
		      debug_adapter_handler);
    
    if(!inited) {
      inited = ATtrue;
      ATprotect(&env);
      ATprotect(&cpe);
      atexit(Tide_disconnect);
    }
    
    if(tide >= 0) {
      fprintf(stderr, "connected to tide\n");
      sprintf(the_pid, "Asf+Sdf-%d", (int)getpid());
      ATBwriteTerm(tide, ATmake("snd-event(process-created(<str>))", the_pid));
    } else {
      fprintf(stderr, "*warning* could not connect to tide!\n");
    }
  } else {
    fprintf(stderr, "*warning* already connected to tide?\n");
  }
}

/*}}}  */
/*{{{  void Tide_disconnect() */

void Tide_disconnect()
{
  /* Switch off debugging */
  if(tide >= 0) {
    ATBdisconnect(tide);
    fprintf(stderr, "tide connection terminated.\n");
    tide = -1;
  } else {
    fprintf(stderr, "*warning* not connected to tide!\n");
  }
}

/*}}}  */
/*{{{  void Tide_handleOne() */

/**
	* Loop until execution continues
	*/

void Tide_handleOne()
{
  if(tide >= 0)
    ATBhandleOne(tide);
}

/*}}}  */
/*{{{  void Tide_activate(int porttype) */

/**
	* Activate all matching rules
	*/

void Tide_activate(int porttype)
{
  if(tide >= 0)
    activate_rules(porttype);
}

/*}}}  */
/*{{{  void Tide_step(ATerm position, ATerm env, int level) */

/**
 * An atomic step is about to be executed
 */

void Tide_step(ATerm position, ATerm newenv, int level)
{
  if(tide >= 0) {
    cpe = position;
    env = newenv;
    stack_level = level;

    Tide_activate(PORT_STEP);
    Tide_activate(PORT_LOCATION);
		
    if(exec_state == STATE_STOPPED) {
      Tide_activate(PORT_STOPPED);
			
      while(exec_state == STATE_STOPPED)
	Tide_handleOne();
			
      Tide_activate(PORT_STARTED);
    }
  }
}

/*}}}  */


#endif


