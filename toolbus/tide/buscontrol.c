#line 50 "buscontrol.c.nw"
#include <signal.h>
#include <sys/time.h>
#include <sys/types.h>
#include <limits.h>

#include <TB.h>
#include "viewer.tif.c"
#include "debug-adapter.tif.c"
#include "dap.h"

#define PUF_WAITING	PUF_START
#line 68 "buscontrol.c.nw"
#define MAX(a,b) 	((a)>(b)?(a):(b))

#define INIT_PID 	0

int global_exec_state = ES_STOP;

int Tid = -1;
int control_bus;
int viewer;
int RID = 0;

TBbool eval_aliases(term_list *args, int pid, term **result, char **msg)
{
  *result = TB_make("[alias(toolbus(<int>),<appl>)]", TB_getPort(viewer),
		dap_get_process_name(0, pid), mk_list1(mk_int(pid)));
  return TBtrue;  
}

static func_entry func_table[] =
{ 
  { "aliases", 0, eval_aliases, NULL, "retrieve the aliases of a process" },
  { NULL, 0, NULL, NULL, NULL }
};

static act_entry act_table[] =
{
  { NULL, 0, NULL, NULL, NULL }
};

char *inf_table[] =
{ "name",		NULL,
  "type",		"\"ToolBus\"",
  "search-paths",	NULL,
  "ports",		"[[exec-state,at], [always, after],"\
			"[location, after], [process-creation, at],"\
			"[process-destruction, at]]",
  "exec-control",	"[single-step, run, stop]",
  "actions",		NULL,
  "expressions",	NULL,
  "multi-process",	"true",
  NULL,			NULL
};

#line 120 "buscontrol.c.nw"
void init()
{
  dap_init(control_bus, inf_table, func_table, act_table);
#line 129 "buscontrol.c.nw"
  /* Initialize INIT process */
  dap_process_created(0, INIT_PID, "INIT", ES_STOP);
}
#line 141 "buscontrol.c.nw"
term_list *get_process_vars(int pid)
{
  return (term_list *)dap_get_process_data(0, pid);
}
#line 154 "buscontrol.c.nw"
void set_process_vars(int pid, term_list *vars)
{
  dap_set_process_data(0, pid, (void *)vars);
}
#line 344 "buscontrol.c.nw"
void continue_process(int pid)
{
  if(dap_check_process_flags(0, pid, PUF_WAITING)){ 
    TB_send(viewer, TB_make("snd-continue(<int>)", pid));
    dap_clear_process_flags(0, pid, PUF_WAITING);
  }
}
#line 166 "buscontrol.c.nw"
void cbdap_process_created(int dapid, int pid)
{
  TBprotect((term_list **)&dap_get_process(dapid, pid)->udata);
}
#line 178 "buscontrol.c.nw"
void cbdap_process_destroyed(int dapid, int pid)
{
  TBunprotect((term_list **)&dap_get_process(dapid, pid)->udata);
}
#line 191 "buscontrol.c.nw"
void cbdap_change_exec_state(int pid, int exec_state)
{
  switch(exec_state) {
    case ES_SINGLE_STEP:
	dap_get_process(0, pid)->new_es = ES_STOP;
    case ES_RUN:
	if(dap_check_process_flags(0, pid, PUF_WAITING))
	  continue_process(pid);
	break;
  }
}
#line 211 "buscontrol.c.nw"
term *cbdap_supply_info(char *key)
{
  static char buf[_POSIX_PATH_MAX];
  if(streq(key, "search-paths")) {
    getcwd(buf, _POSIX_PATH_MAX);

    return TB_make("[[config, [<str>]], [source, [<str>]]]", buf, buf);
  }
  if(streq(key, "name")) {
    int port = TB_getPort(viewer);
    sprintf(buf, "toolbus-%d", port);
    return TB_make("<str>", buf);
  }
  return NULL;
}

#line 233 "buscontrol.c.nw"
TBbool get_var_value(int pid, term *var, term **val)
{
  term *vars, *cur_var;

  /*TBprintf(stderr, "get_var_value in %s: %t vars: %t\n",
	proc_db[pid]->name, var, proc_db[pid]->vars);*/
  vars = get_process_vars(pid);

  while(vars) {
    /* Now search for the variable */
    cur_var = list_first(vars);

    if(term_equal(var, list_first(cur_var))) {
      /*TBprintf(stderr, "\tvalue: %t=%t\n", var, first(next(cur_var)));*/
      *val = list_first(list_next(cur_var));
      return TBtrue;
    } else {
      /*TBprintf(stderr, "\t*** %t != %t\n", var, first(cur_var));*/
    }

    /*TBprintf(stderr, "\t*** env_next(%t) = %t\n", vars, next(vars));*/
    vars = list_next(vars);
  }
  /*TBprintf(stderr, "\tnot found!\n");*/
  return TBfalse;
}
#line 265 "buscontrol.c.nw"
void set_var_value(int pid, term *var, term *val)
{
  /* A variable is identified by a term represention. */
  term *vars, *cur_var;
  process *p;

  vars = get_process_vars(pid);
  p = dap_get_process(0, pid);
  /*TBprintf(stderr, "set_var_value in %s: %t vars: %t\n", p->name,
	var, vars);*/

  while(vars) {
    cur_var = list_first(vars);

    if(term_equal(list_first(cur_var), var)) {
      /*TBprintf(stderr, "\tset value: %t=%t\n", var, first(next(cur_var)));*/
      list_first(list_next(cur_var)) = val;
      return;
    }
    vars = list_next(vars);
  }
  /*TBprintf(stderr, "\tnot found, adding var %t (%t)!\n", var, val);*/
  set_process_vars(pid, 
	list_concat_term(get_process_vars(pid),mk_list2(var,val)));
}
#line 298 "buscontrol.c.nw"
term_list *clean_vars_list(term_list *l);

term *clean_variables(term *t)
{
  term *r;

  switch(tkind(t)) {
    case t_bool:
    case t_int:
    case t_real:
    case t_str:
    case t_bstr:  return t;

    case t_var:	  r = mk_appl(var_sym(t), NULL);
		  fun_str_sym(r) = TBtrue;
		  return r;

    case t_appl:  r = mk_appl(fun_sym(t), clean_vars_list(fun_args(t)));
		  fun_str_sym(r) = fun_str_sym(t);
		  return r;

    case t_list:  return clean_vars_list(t);
  }
  return NULL;
}

term_list *clean_vars_list(term_list *l)
{
  term_list *r = NULL;
  term_list *el;
  int idx;

  for(idx = list_length(l); idx > 0; idx--) {
    el = clean_variables(list_index(l, idx));
    r = mk_list(el, r);
  }
  return r;
}
#line 360 "buscontrol.c.nw"
void update_process(int pid, term *env)
{
  term *var, *val;
  TBbool changed = TBfalse;

  if(!dap_get_process(0, pid))
    return;

  while(env) {
    var = list_first(env);
    set_var_value(pid, list_first(var), list_first(list_next(var)));
    env = list_next(env);    
  }
}
#line 380 "buscontrol.c.nw"
void create_process(int pid, term *args)
{
  int new_pid;
  term *pid_trm, *dummy;
  char *name;

  /* The pid is stored in the variable indicated by the second
     argument of creating process */
  pid_trm = NULL;
  /*TBprintf(stderr, "create_process: args = %t\n", args);*/
  get_var_value(pid,  first(next(args)), &pid_trm);
  if(pid_trm) {
    TB_match(pid_trm, "<int>", &new_pid);
    TB_match(first(args), "<appl>", &name, &dummy);
    dap_process_created(0, new_pid, name, dap_get_new_exec_state(0, pid));
    dap_activate_rules(new_pid, TB_make("[process-creation,at]"));
  } else {
    TBprintf(stderr, "cannot find pid of created process: %t", args);
  }  
}
#line 406 "buscontrol.c.nw"
void tool_connected(int pid, term *args)
{
  term *toolid = NULL;
  get_var_value(pid, list_first(args), &toolid);
  TBprintf(stderr, "tool_connected: %t\n", toolid);
  dap_connected(TB_make("callsign(toolbus(<int>),<term>)", TB_getPort(viewer),toolid));
}
#line 419 "buscontrol.c.nw"
void tool_disconnected(int pid, term *args)
{
  term *toolid = NULL;
  get_var_value(pid, list_first(args), &toolid);
  TBprintf(stderr, "tool_disconnected: %t\n", toolid);
  dap_disconnected(TB_make("callsign(toolbus(<int>),<term>)", TB_getPort(viewer),toolid));
}

#line 434 "buscontrol.c.nw"
term *get_info(int cid)
{
  return TB_make("snd-value(info(<list>))", dap_get_info(cid));
}
#line 446 "buscontrol.c.nw"
term *get_processes(int cid)
{
  int i;
  term_list *procs = NULL;

  for(i=0; i<MAX_PROCESSES; i++) {
    process *p = dap_get_process(0, i);
    if(p) {
      term *callsigns = TB_make("[callsign(<int>,<appl>)]", TB_getPort(viewer),
		dap_get_process_name(0, i), mk_list1(mk_int(i)));
      procs = list_concat_term(procs, TB_make("[<int>,<str>,<list>]", 
						i, p->name, callsigns));
    }
  }
  return TB_make("snd-value(processes(<term>))", procs);
}
#line 485 "buscontrol.c.nw"
term *exec_actions(int cid, term *procs, term *acts)
{
  char *msg;
  term *result;

  TBbool ok = dap_exec(procs, acts, &result, &msg);
  if(ok)
    return TB_make("snd-value(exec-result(ok(<term>)))", result);

  return TB_make("snd-value(exec-result(error(<str>)))", msg);
}
#line 470 "buscontrol.c.nw"
term *create_rule(int cid, term *procs, term *port, term *cond, term *acts, term *life)
{
  int rid = dap_create_rule(procs, port, cond, acts, life);
  return TB_make(
	"snd-value(create-rule(<term>,<term>,<term>,<term>,<term>,<int>))",
	procs, port, cond, acts, life, rid);
}
#line 504 "buscontrol.c.nw"
void modify_rule(int cid, int rid, term *procs, term *port, 
				term *cond, term *acts, term *life)
{
  dap_rule_modified(0, rid, procs, port, cond, acts, life);
}
#line 517 "buscontrol.c.nw"
void destroy_rule(int cid, term *procs, int rid)
{
  dap_destroy_rule(rid);
}

#line 623 "buscontrol.c.nw"
TBbool is_to_tool_comm(char *s)
{
   return streq(s, "snd-eval") 
         || streq(s, "snd-cancel") 
         || streq(s, "snd-do") 
         || streq(s, "snd-ack-event") 
         || streq(s, "snd-terminate");
}
#line 637 "buscontrol.c.nw"
TBbool is_from_tool_comm(char *s)
{
  return streq(s, "rec-value") 
         || streq(s, "rec-event") 
         || streq(s, "rec-disconnect");
}

#line 534 "buscontrol.c.nw"
term *rec_monitor(int cid, term *T)
{
  char *mon_point, *at_fun;
  int pid1, pid2, old_state, new_state;
  term *at_args, *at_coords, *env, *subs, *notes, *pe;

  /*TBprintf(stderr, "monitor command received: %t\n", T);*/
  if(TBmatch(T, "%f(%d,%f,%t,%t,%t,%t,%t,%d,%t)",
	     &mon_point, &pid1, &at_fun, &at_args, &at_coords,
	     &env, &subs, &notes, &pid2, &pe)) {

    /* Update process variables */
    update_process(pid1, env);
    if(!dap_get_process(0, pid1)) {
      /* Steps executed when the process is not officially created yet
         are invisible! */
      TB_send(viewer, TB_make("snd-continue(<int>)", pid1));
      return;
    }
      
    dap_set_process_flags(0, pid1, PUF_WAITING);

    
#line 592 "buscontrol.c.nw"
  if(streq(at_fun, "create"))
    create_process(pid1, at_args);	/* Process creation monitoring */
  else if(streq(at_fun, "rec-connect"))
    tool_connected(pid1, at_args);	/* Tool connection monitoring */
  else if(streq(at_fun, "rec-disconnect"))
    tool_disconnected(pid1, at_args);	/* Tool disconnection monitoring */
  else if(is_to_tool_comm(at_fun)) {
    /* Process -> Tool communication monitoring */
  } else if(is_from_tool_comm(at_fun)) {
    /* Tool -> Process communication monitoring */
  } else if(streq(at_fun, "endlet")) {
    /* Endlet monitoring */
  } else if(pid2 >= 0 && strncmp(at_fun, "snd", 3) == 0) {
    dap_activate_rules(pid1, 
    TB_make("[send,after,<appl>,alias(toolbus(<int>),<appl>)]", 
		at_fun, clean_variables(at_args), TB_getPort(viewer), 
		dap_get_process_name(0, pid2), mk_list1(mk_int(pid2))));
  } else if(pid2 >= 0 && strncmp(at_fun, "rec", 3) == 0) {
    dap_activate_rules(pid1,
    TB_make("[receive,after,<appl>,alias(toolbus(<int>),<appl>)]",
		at_fun, clean_variables(at_args), TB_getPort(viewer), 
		dap_get_process_name(0, pid2), mk_list1(mk_int(pid2))));
  } else {
    /* Other atoms (assignment, printf, tau, etc.) */
    TBprintf(stderr, "unrecognized atom executed: %s(%l)\n", at_fun, at_args);
  }

#line 558 "buscontrol.c.nw"
    /* Now we can activate all location rules */
    if(at_coords)
      dap_activate_rules(pid1, 
	list_concat(TB_make("[location,after]"), at_coords));

    old_state = dap_get_exec_state(0, pid1);
    new_state = dap_get_new_exec_state(0, pid1);
    TBprintf(stderr, "es of %d=%d, new_es=%d\n", 
		pid1, old_state, dap_get_new_exec_state(0, pid1));

    if(dap_get_new_exec_state(0,pid1) != dap_get_exec_state(0,pid1)) {
      int new_state = dap_get_new_exec_state(0, pid1);
      dap_get_process(0, pid1)->exec_state = new_state;
      cbdap_change_exec_state(pid1, new_state);
    }
    if(new_state == ES_SINGLE_STEP)
      dap_get_process(0, pid1)->new_es = ES_STOP;

    if(dap_get_exec_state(0, pid1) != old_state)
      dap_activate_rules(pid1, TB_make("[exec-state,at,<term>]", 
				dap_es2term(dap_get_exec_state(0, pid1))));
    if(dap_get_exec_state(0, pid1) != ES_STOP) {
      if(!dap_is_high_water(0, pid1))
        continue_process(pid1);
    }
  } else {
    err_fatal("badly formed monitor function: %t\n", T);
  }

  return NULL;
}
#line 653 "buscontrol.c.nw"
void rec_ack_event(int cid, term *ev)
{
  dap_rec_ack_event(cid, ev);
}
#line 665 "buscontrol.c.nw"
void rec_terminate(int cid, term *arg)
{
  dap_rec_terminate(cid, arg);
  exit(0);
}

#line 677 "buscontrol.c.nw"
int main(int argc, char *argv[])
{
  TB_init();

  viewer = TB_parseArgs(argc, argv, viewer_handler, viewer_check_in_sign);
  TB_connect(viewer);

  control_bus = TB_newConnection("debug-adapter", NULL, 9500,
	         debug_adapter_handler, debug_adapter_check_in_sign);
  TB_connect(control_bus);

  init();

  return TB_eventloop();
}
