#line 167 "dap.c.nw"
#include "dap-admin.h"
#include "dap.h"
#include <procs.h>
#line 176 "dap.c.nw"
static int tide_cid;
static char **inf_table;
static function_table func_table;
static action_table act_table;
static int RID = 0;

/* Some event queues */
#define EVQ_WATCHPOINT          0
#define EVQ_RULE_DESTROYED	1
#define EVQ_LAST                EVQ_RULE_DESTROYED

/* Queue limits */
#define MAX_QUEUE_SIZE          512
#define HIGH_WATER_MARK         128     /* Must be <<< MAX_QUEUE_SIZE */
#define LOW_WATER_MARK          8       /* Not all events have to be ack'd */

static event_queue *evq[EVQ_LAST+1] = { NULL };
static int outstanding_events = 0;
static TBbool high_water_reached = TBfalse;

TBbool eval_cpe_0(term_list *args, int pid, term **result, char **msg);
TBbool eval_cpe_1(term_list *args, int pid, term **result, char **msg);
TBbool eval_always(term_list *args, int pid, term **result, char **msg);
TBbool eval_exec_state(term_list *args, int pid, term **result, char **msg);
TBbool eval_process_name(term_list *args, int pid, term **result, char **msg);
TBbool exec_watch_1(term_list *args, int pid, term **result, char **msg);
TBbool exec_halt_0(term_list *args, int pid, term **result, char **msg);
TBbool exec_single_step_0(term_list *args, int pid, term **result, char **msg);
TBbool exec_step_over_0(term_list *args, int pid, term **result, char **msg);
TBbool exec_run_0(term_list *args, int pid, term **result, char **msg);
TBbool exec_run_until_parent_0(term_list *args, int pid, term **result, char **msg);

/* Default function/action tables */
func_entry default_func_table[] =
{
  { "cpe", 0, eval_cpe_0, NULL, 
	"returns the current point of execution in the current process." },
  { "cpe", 1, eval_cpe_1, NULL, 
	"returns the current point of execution in a specific process" },
  { "always", 0, eval_always, NULL, "returns 1." },
  { "true",   0, eval_always, NULL, "returns 1." },
  { "exec-state", 0, eval_exec_state, NULL, 
	"returns the execution state of the current process." },
  { "process-name", 0, eval_process_name, NULL,
	"returns the name of the current process." },
  { NULL, 0, NULL, NULL, NULL }
};

act_entry default_act_table[] =
{
  { "watch",	1, exec_watch_1, NULL, "generate a watchpoint event" }, 
  { "halt",	0, exec_halt_0,  NULL, "stop execution of a process" },
  { "break",	0, exec_halt_0,  NULL, "stop execution of a process" },
  { "stop",	0, exec_halt_0,  NULL, "stop execution of a process" },
  { "single-step", 0, exec_single_step_0, NULL, "put a process in single step mode" },
  { "step-over",0, exec_step_over_0, NULL, "put a process in step-over mode" },
  { "run",	0, exec_run_0,	NULL,	"put a process in run mode" },
  { "run-until-parent", 0, exec_run_until_parent_0, NULL,
					"put a process in run-until-parent mode" },
  { NULL,    0, NULL,         NULL, NULL }
};

#line 1259 "dap.c.nw"
static void post_event(int queue, term *event)
{
  int i;

  /*TBprintf(stderr, "posting event %t in queue %d\n", event, queue);*/
  TBevq_post(evq[queue], event);
  outstanding_events++;
  if(outstanding_events >= HIGH_WATER_MARK) {
    high_water_reached = TBtrue;
    for(i=0; i<MAX_PROCESSES; i++) {
      process *p = dap_get_process(0, i);
      if(p) {
        p->hw_exec_state = ES_HIGH_WATER;
        cbdap_change_exec_state(i, ES_HIGH_WATER);
      }
    }
  }
}
#line 261 "dap.c.nw"
TBbool eval_cpe_0(term_list *args, int pid, term **result, char **msg)
{
  process *p = dap_get_process(0, pid); 

  assert(!args);
  if(p->cpe.module)
    *result = TB_make("[location,<term>,<str>,<int>,<int>,<int>,<int>]", 
	dap_when2term(p->cpe.when), p->cpe.module,
	p->cpe.start_line, p->cpe.start_col, p->cpe.end_line, p->cpe.end_col);
  else
    *result = TB_make("nothing");

  return TBtrue;  
}
#line 281 "dap.c.nw"
TBbool eval_cpe_1(term_list *args, int pid, term **result, char **msg)
{
  if(TBmatch(args, "[<int>]", &pid)) {
    process *p = dap_get_process(0, pid);
    *result = TB_make("[<str>,<int>,<int>,<int>,<int>]", p->cpe.module,
	p->cpe.start_line, p->cpe.start_col, p->cpe.end_line, p->cpe.end_col);
    return TBtrue;
  }
  *msg = "function cpe expects an integer argument";
  *result = list_first(args);

  return TBfalse;
}
#line 300 "dap.c.nw"
TBbool eval_always(term_list *args, int pid, term **result, char **msg)
{
  *result = TB_make("1");

  return TBtrue;  
}
#line 312 "dap.c.nw"
TBbool eval_exec_state(term_list *args, int pid, term **result, char **msg)
{
  *result = dap_es2term(dap_get_exec_state(0, pid));

  return TBtrue;  
}
#line 324 "dap.c.nw"
TBbool eval_process_name(term_list *args, int pid, term **result, char **msg)
{
  *result = TB_make("<str>", dap_get_process_name(0, pid));

  return TBtrue;  
}

#line 337 "dap.c.nw"
TBbool exec_halt_0(term_list *args, int pid, term **result, char **msg)
{
  dap_change_exec_state(pid, ES_STOP);
  return TBtrue;
}
#line 348 "dap.c.nw"
TBbool exec_single_step_0(term_list *args, int pid, term **result, char **msg)
{
  dap_change_exec_state(pid, ES_SINGLE_STEP);
  return TBtrue;
}
#line 359 "dap.c.nw"
TBbool exec_step_over_0(term_list *args, int pid, term **result, char **msg)
{
  dap_change_exec_state(pid, ES_STEP_OVER);
  return TBtrue;
}
#line 370 "dap.c.nw"
TBbool exec_run_0(term_list *args, int pid, term **result, char **msg)
{
  dap_change_exec_state(pid, ES_RUN);
  return TBtrue;
}
#line 381 "dap.c.nw"
TBbool exec_run_until_parent_0(term_list *args, int pid, term **result, char **msg)
{
  dap_change_exec_state(pid, ES_RUN_UNTIL_PARENT);
  return TBtrue;
}
#line 392 "dap.c.nw"
TBbool exec_watch_1(term_list *args, int pid, term **result, char **msg)
{
  process *p = dap_get_process(0, pid);
  term *expr = list_first(args);

  if(!dap_evaluate(expr, pid, result, msg))
    return TBfalse;

  *result = TB_make("[<term>,<term>]", expr, *result);
  
  return TBtrue;
}
#line 1288 "dap.c.nw"
TBbool typecheck_expr(term *expr, int pid, term **at, char **msg)
{
  /* This function is not implemented yet */
  return TBtrue;
}
#line 1304 "dap.c.nw"
TBbool typecheck_action(term *action, int pid, term **at, char **msg)
{
  /* This function is not implemented yet */
  return TBtrue;
}

#line 415 "dap.c.nw"
void dap_init(int cid, char **itable, function_table ftable, action_table atable)
{
  int i;

  tide_cid = cid;
  inf_table  = itable;
  func_table = ftable;
  act_table  = atable;

  dap_admin_init();
  dap_new(0, dap_get_info(cid));

  for(i=0; i<=EVQ_LAST; i++) {
    evq[i] = TBevq_create(MAX_QUEUE_SIZE, tide_cid);
    if(!evq[i]) {
      fprintf(stderr, "event queues exhausted\n");
      exit(1);
    }
  }  
}
#line 465 "dap.c.nw"
TBbool dap_evaluate(term *expr, int pid, term **result, char **msg);

TBbool dap_evaluate_list(term_list *exprs, int pid, term **result, char **msg)
{
  term_list *el, *l = NULL;

  while(exprs) {
    if(!dap_evaluate(list_first(exprs), pid, &el, msg)) {
      *result = el;
      return TBfalse;
    }
    l = list_concat_term(l, el);
    exprs = list_next(exprs);
  }
  *result = l;
  return TBtrue;
}
#line 490 "dap.c.nw"
TBbool dap_evaluate_appl(term *appl, int pid, term **result, char **msg)
{
  int i, arity;
  char *func;
  term_list *args, *args_eval;

  TB_match(appl, "<appl>", &func, &args);
  arity = list_length(args);
  

  /* Search for the appropriate function in the function table */
  for(i=0; func_table[i].name; i++) {
    if(streq(func_table[i].name, func) && 
       (func_table[i].arity == -1 || func_table[i].arity == arity)) {
      /* Firste evaluate the arguments */
      if(!dap_evaluate_list(args, pid, &args_eval, msg)) {
        /* An error occured while evaluating the arguments */
        *result = args_eval;
        return TBfalse;
      }
      return (func_table[i].eval)(args, pid, result, msg);
    }
  }

  /* Search for the appropriate function in the function table */
  for(i=0; default_func_table[i].name; i++) {
    if(streq(default_func_table[i].name, func) && 
       (default_func_table[i].arity == -1 || 
        default_func_table[i].arity == arity)) {
      /* Firste evaluate the arguments */
      if(!dap_evaluate_list(args, pid, &args_eval, msg)) {
        /* An error occured while evaluating the arguments */
        *result = args_eval;
        return TBfalse;
      }
      return (default_func_table[i].eval)(args, pid, result, msg);
    }
  }

  /* The function does not exist */
  *msg = "no such function";
  *result = appl;
  return TBfalse;
}
#line 449 "dap.c.nw"
TBbool dap_evaluate(term *expr, int pid, term **result, char **msg)
{
  switch(tkind(expr)) {
    case t_appl:	return dap_evaluate_appl(expr, pid, result, msg);
    case t_list:	return dap_evaluate_list(expr, pid, result, msg);
  }
  *result = expr;
  return TBtrue;
}
#line 567 "dap.c.nw"
static TBbool dap_execute_list(term_list *actions, int pid, term **result, char **msg)
{
  term_list *el, *l = NULL;

  while(actions) {
    el = NULL;
    if(!dap_execute(list_first(actions), pid, &el, msg)) {
      *result = el;
      return TBfalse;
    }
    if(el)
      l = list_concat_term(l, el);
    actions = list_next(actions);
  }
  *result = l;
  return TBtrue;
}
#line 592 "dap.c.nw"
static TBbool dap_execute_appl(term *appl, int pid, term **result, char **msg)
{
  int i, arity;
  char *func;
  term_list *args, *args_eval;

  TB_match(appl, "<appl>", &func, &args);
  arity = list_length(args);
  
  if(!dap_evaluate_list(args, pid, &args_eval, msg)) {
    /* An error occured while evaluating the arguments */
    *result = args_eval;
    return TBfalse;
  }

  /* Search for the appropriate function in the action table */
  for(i=0; act_table[i].name; i++) {
    if(streq(act_table[i].name, func) && 
       (act_table[i].arity == -1 || act_table[i].arity == arity)) {
      return (act_table[i].execute)(args, pid, result, msg);
    }
  }

  /* Search for the appropriate function in the action table */
  for(i=0; default_act_table[i].name; i++) {
    if(streq(default_act_table[i].name, func) && 
       (default_act_table[i].arity == -1 || 
	default_act_table[i].arity == arity)) {
      return (default_act_table[i].execute)(args, pid, result, msg);
    }
  }

  /* The action does not exist */
  *msg = "no such action";
  *result = appl;
  return TBfalse;
}
#line 550 "dap.c.nw"
TBbool dap_execute(term *action, int pid, term **result, char **msg)
{
  switch(tkind(action)) {
    case t_appl:	return dap_execute_appl(action, pid, result, msg);
    case t_list:	return dap_execute_list(action, pid, result, msg);
  }
  *result = action;
  *msg = "illegal action";
  return TBfalse;
}
#line 688 "dap.c.nw"
TBbool dap_exec(term *procs, term *acts, term **result, char **msg)
{
  int i, pid;

  if(TBmatch(procs, "all")) {
    for(i=0; i<MAX_PROCESSES; i++) {
      if(dap_get_process(0, i))
        if(!dap_execute_list(acts, i, result, msg))
	  return TBfalse;
    }
  } else {
    while(procs) {
      TB_match(list_first(procs), "<int>", &pid);
      procs = list_next(procs);  
      if(!dap_execute_list(acts, pid, result, msg))
	return TBfalse;
    }
  }
}
#line 639 "dap.c.nw"
term *dap_get_info(int cid)
{
  int i,j;
  term *key, *val;
  term_list *info = NULL;

  for(i=0; inf_table[2*i] != NULL; i++) {
    key = TBmake(inf_table[2*i]);
    if(streq(inf_table[2*i], "expressions")) {
      val = NULL;
      for(j=0; func_table[j].name; j++) {
        val = list_concat_term(val, TB_make("[<str>,<int>,<str>]", 
		func_table[j].name, func_table[j].arity, func_table[j].doc));
      }
      for(j=0; default_func_table[j].name; j++) {
        val = list_concat_term(val, TB_make("[<str>,<int>,<str>]", 
		default_func_table[j].name, default_func_table[j].arity,
				   		default_func_table[j].doc));
      }
    } else if(streq(inf_table[2*i], "actions")) {
      val = NULL;
      for(j=0; act_table[j].name; j++) {
        val = list_concat_term(val, TB_make("[<str>,<int>,<str>]", 
		act_table[j].name, act_table[j].arity, act_table[j].doc));
      }
      for(j=0; default_act_table[j].name; j++) {
        val = list_concat_term(val, TB_make("[<str>,<int>,<str>]",
		 default_act_table[j].name, default_act_table[j].arity,
					  default_act_table[j].doc));
      }
    } else {
      if(inf_table[2*i+1]) {
        val = TBmake(inf_table[2*i+1]);
      } else {
        val = cbdap_supply_info(inf_table[2*i]);
      }
    }
    info = list_concat_term(info, mk_list2(key, val));
  }
  return info;
}
#line 1184 "dap.c.nw"
TBbool dap_change_exec_state(int pid, int new_state)
{
  int old_state;
  process *p = dap_get_process(0, pid);

  if(p->exec_state == ES_HIGH_WATER) {
    old_state = p->hw_exec_state;
    p->hw_exec_state = new_state;
  } else {
    old_state = p->exec_state;
    p->exec_state = new_state;
  }
  if(new_state != old_state) {
    cbdap_change_exec_state(pid, new_state);
    dap_activate_rules(pid, TB_make("[exec-state,at,<term>]", 
						dap_es2term(new_state)));
    return TBtrue;
  }
  return TBfalse;
}
#line 1214 "dap.c.nw"
void dap_rec_ack_event(int cid, term *event)
{
  int i;

  /*TBprintf(stderr, "Received acknowledment: %t", ev);*/
  for(i=0; i<=EVQ_LAST; i++) {
    if(TBevq_ack_event(evq[i], event)) {
      outstanding_events--;
      if(high_water_reached && outstanding_events <= LOW_WATER_MARK) {
        int i;
        high_water_reached = TBfalse;
        for(i=0; i<MAX_PROCESSES; i++) {
          process *p = dap_get_process(0, i);
          if(p && p->exec_state == ES_HIGH_WATER) {
            p->exec_state = p->hw_exec_state;
	    cbdap_change_exec_state(i, p->exec_state);
          }
        }
      }
      return;
    }
  }
}
#line 1243 "dap.c.nw"
void dap_rec_terminate(int cid, term *arg)
{
  if(cid != tide_cid) {
    TB_send(tide_cid, TB_make("snd-disconnect"));
  }
}

#line 911 "dap.c.nw"
TBbool check_function(char *pattern, term *tdata)
{
  char *function;

  if(!tdata)
    return TBtrue;

  assert(tkind(list_first(tdata)) == t_str);

  function = str_val(list_first(tdata));
  
  if(!pattern || streq(pattern, "") || streq(pattern, function))
    return TBtrue;
  return TBfalse;
}
#line 932 "dap.c.nw"
TBbool check_exception(char *pattern, term *tdata)
{
  char *exception;

  if(!tdata)
    return TBtrue;

  assert(tkind(list_first(tdata)) == t_str);

  exception = str_val(list_first(tdata));
  
  if(!pattern || streq(pattern, "") || streq(pattern, exception))
    return TBtrue;
  return TBfalse;
}
#line 953 "dap.c.nw"
TBbool check_variable(char *pattern, term *tdata)
{
  char *var;

  if(!tdata)
    return TBtrue;

  assert(tkind(list_first(tdata)) == t_str);

  var = str_val(list_first(tdata));
  
  if(!pattern || streq(pattern, "") || streq(pattern, var))
    return TBtrue;
  return TBfalse;
}
#line 974 "dap.c.nw"
TBbool check_location(struct location *loc, term *loc_data)
{
  struct location loc2;
  TBbool start_before_end = TBfalse;
  TBbool end_after_start  = TBfalse;

  dap_eventlocation(loc_data, &loc2);

  if(!loc->module || streq(loc->module, "") || streq(loc->module, loc2.module)) {
    if(loc->start_line < loc2.end_line || 
       (loc->start_line == loc2.end_line && 
		(loc->start_col <= loc2.end_col |+ loc2.end_col == -1)))
      start_before_end = TBtrue;
    if(loc->end_line > loc2.start_line || 
       (loc->end_line == loc2.start_line && 
		(loc->end_col >= loc2.start_col || loc->end_col == -1)))
      end_after_start = TBtrue;

    if(start_before_end && end_after_start)
      return TBtrue;
  }

  /*fprintf(stderr, "check_location failed %s:%d.%d,%d.%d != %s:%d.%d,%d.%d\n",
	loc->module, loc->start_line, loc->start_col, loc->end_line, loc->end_col,
	loc2.module, loc2.start_line, loc2.start_col, loc2.end_line, loc2.end_col);
  */

  return TBfalse;
}
#line 1011 "dap.c.nw"
TBbool check_pid(term *pids, int pid)
{
  if(TBmatch(pids, "all"))
    return TBtrue;

  while(pids) {
    if(int_val(list_first(pids)) == pid)
      return TBtrue;
    pids = list_next(pids);
  }
  return TBfalse;
}
#line 1029 "dap.c.nw"
TBbool check_exec_state(int exec_state, term *tdata)
{
  return (dap_term2es(list_first(tdata)) & exec_state);
}
#line 1043 "dap.c.nw"
static int term_match(term *trm, term *template, term_list **args);

static int list_match(term_list *l1, term_list *l2, term_list **args)
{
  if(list_length(l1) != list_length(l2))
    return 0;
  while(l1) {
    if(!term_match(first(l1), first(l2), args))
      return 0;
    l1 = next(l1);
    l2 = next(l2);
  }
  return 1;
}
#line 1063 "dap.c.nw"
static int term_match(term *trm, term *template, term_list **args)
{
  /* Here, we only perform a preorder search for placeholders */
  if(is_placeholder(template)) {
    int sym;

    sym = fun_sym(placeholder_type(template));
    switch(sym) {
      
#line 1103 "dap.c.nw"
case type_list:	if(!is_list(trm))
		  return 0;
case type_term:	*args = list_concat_term(*args, trm);
                return 1;
#line 1072 "dap.c.nw"
      
#line 1113 "dap.c.nw"
case type_bool:	if(!is_bool(trm))
		  return 0;
		*args = list_concat_term(*args, trm);
                return 1;
#line 1073 "dap.c.nw"
      
#line 1123 "dap.c.nw"
case type_int:	if(!is_int(trm))
		  return 0;
		*args = list_concat_term(*args, trm);
		return 1;
#line 1074 "dap.c.nw"
      
#line 1133 "dap.c.nw"
case type_real: if(!is_real(trm))
		  return 0;
		*args = list_concat_term(*args, trm);
		return 1;
#line 1075 "dap.c.nw"
      
#line 1143 "dap.c.nw"
case type_str:	if(!is_str(trm))
		  return 0;
		*args = list_concat_term(*args, trm);
		break;
		return 1;
#line 1076 "dap.c.nw"
      
#line 1154 "dap.c.nw"
case type_bstr:	if(!is_bstr(trm))
		  return 0;
		*args = list_concat_term(*args, trm);
		return 1;
#line 1077 "dap.c.nw"
      
#line 1164 "dap.c.nw"
default:	if(streq(get_txt(sym), "appl")) {
		  if(!is_appl(trm))
		    return 0;
		  *args = list_concat_term(*args, trm);
		  return 1;
		}
		return 0;
#line 1078 "dap.c.nw"
    }
    return 0;
  } else if(is_appl(template)) {
    term_list *templ_args, *trm_args;

    if(!is_appl(trm) || fun_sym(template) != fun_sym(trm))
      return 0;
    return list_match(fun_args(trm), fun_args(template), args);
  } else if(is_list(template)) {
    if(!is_list(trm))
      return 0;
    return list_match(trm, template, args);
  } else if(term_equal(trm, template)) {
    return 1;
  } else {
    return 0;
  }
}

#line 869 "dap.c.nw"
static void cond_trigger_rule(int pid, int rid, term *cond, term *acts)
{
  term *res;
  char *msg;
  process *p;

  /*TBprintf(stderr, "cond_trigger_rule: %t\n", cond);*/
  if(cond) {
    if(!dap_evaluate(cond, pid, &res, &msg)) {
      TBprintf(stderr, "evaluating condition failed: %t - %s\n", res, msg);
      return;
    }
    if(TB_match(res, "false"))
      return;
    if(TB_match(res, "0"))
      return;
    if(TB_match(res, "[]"))
      return;
  }

  /*TBprintf(stderr, "triggering rule: %t\n", acts);*/
  p = dap_get_process(0, pid);
  p->ruleid = rid;
  res = NULL;
  if(!dap_execute_list(acts, pid, &res, &msg))
    TBprintf(stderr, "execution failed: %t - %s\n", res, msg);


  if(res) {
    /*TBprintf(stderr, "posting result: %t\n", res);*/
    post_event(EVQ_WATCHPOINT, 
	TB_make("watchpoint([<int>],<int>,<term>)",
	pid, p->ruleid, res));
  }
}
#line 815 "dap.c.nw"
void dap_activate_rule(int pid, term *port, event_rule *rule)
{
  int   type  = dap_eventport(list_index(port, 1));
  int   when  = dap_eventwhen(list_index(port, 2));
  term *tdata = list_next(list_next(port));

  /*TBprintf(stderr, "checking rule: %d (pids=%t)\n", rule->id, rule->pids);*/
  if(check_pid(rule->pids, pid) && 
     (when == rule->port.when || rule->port.when == WHEN_AT)) {
    switch(type) {
	case PORT_EXEC_STATE:	if(check_exec_state(rule->port.u.exec_state, tdata))
				  cond_trigger_rule(pid, rule->id, rule->cond, rule->acts);
				break;

	case PORT_PROCESS_CREATION:
	case PORT_PROCESS_DESTRUCTION:
	case PORT_ALWAYS:	cond_trigger_rule(pid, rule->id, rule->cond, rule->acts);
				break;

        case PORT_LOCATION:	if(check_location(&rule->port.u.loc, tdata))
				  cond_trigger_rule(pid, rule->id, rule->cond, rule->acts);
				break;

        case PORT_CALL:
	case PORT_RETRY:
	case PORT_FAIL:
	case PORT_SUCCEED:	if(!check_function(rule->port.u.function, tdata))
				  cond_trigger_rule(pid, rule->id, rule->cond, rule->acts);
				break;

	case PORT_EXCEPTION:	if(!check_exception(rule->port.u.exception, tdata))
				  cond_trigger_rule(pid, rule->id, rule->cond, rule->acts);
				break;
	case PORT_VARIABLE:	if(!check_variable(rule->port.u.var, tdata))
				  cond_trigger_rule(pid, rule->id, rule->cond, rule->acts);
				break;
	case PORT_RECEIVE:
	case PORT_SEND:		if(term_match(list_first(tdata), rule->port.u.msg,
					&dap_get_process(0, pid)->subterms))
				  cond_trigger_rule(pid, rule->id, rule->cond, rule->acts);
				break;
	
	default:	assert(0); /* illegal port type */
    }
  }
}
#line 783 "dap.c.nw"
void dap_activate_rules(int pid, term *port)
{
  static TBbool firstloc = TBtrue;

  dap *mydap = dap_get(0);
  event_rule *cur;
  process *p = dap_get_process(0, pid);
  int   type  = dap_eventport(list_index(port, 1));
  int   when  = dap_eventwhen(list_index(port, 2));
  term *tdata = list_next(list_next(port));


  if(type == PORT_LOCATION) {
    if(TB_match(tdata, "[<str>,<int>,<int>,<int>,<int>]", &p->cpe.module,
	&p->cpe.start_line, &p->cpe.start_col, &p->cpe.end_line, &p->cpe.end_col))
      p->cpe.when = when;
  }

  if(type == PORT_EXEC_STATE)
    dap_set_last_port(0, pid, port);
 
  for(cur = mydap->ports[type]; cur; cur = cur->next)
    dap_activate_rule(pid, port, cur);
}
#line 713 "dap.c.nw"
static void cond_trigger_rule(int pid, int rid, term *cond, term *acts);

int dap_create_rule(term *procs, term *port, term *cond, 
					term *acts, term *life)
{
  int i, pid, rid = -1;

  if(TBmatch(life, "one-shot") && TBmatch(port, "[always,at]")) {
    if(TBmatch(procs, "all")) {
      for(i=0; i<MAX_PROCESSES; i++) {
        if(dap_get_process(0, i))
          cond_trigger_rule(i, rid, cond, acts);
      }
    } else {
      while(procs) {
        TB_match(list_first(procs), "<int>", &pid);
        procs = list_next(procs);  
        cond_trigger_rule(pid, rid, cond, acts);
      }
    }
  } else {
    rid = RID++;
    dap_rule_created(0, rid, procs, port, cond, acts, life);
    for(i=0; i<MAX_PROCESSES; i++) {
      if(dap_get_process(0, i)) {
        term *port = dap_get_last_port(0, i);
        event_rule *rule = dap_get_rule(0, rid);
        if(port && dap_eventport(list_first(port)) == rule->port.type)
          dap_activate_rule(0, port, rule);
      }
    }
  }
  return rid;
}
#line 753 "dap.c.nw"
void dap_destroy_rule(int rid)
{
  dap_rule_destroyed(0, rid);
  post_event(EVQ_RULE_DESTROYED, TB_make("rule-destroyed(<int>)", rid));
}
