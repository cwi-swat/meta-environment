#line 46 "buscontrol.c.nw"
#include <signal.h>
#include <sys/time.h>
#include <sys/types.h>
#include <limits.h>

#include <TB.h>
#include "viewer.tif.c"
#include "debug-adapter.tif.c"
#include "dap.h"

#define PUF_WAITING	PUF_START
#line 64 "buscontrol.c.nw"
#define MAX(a,b) 	((a)>(b)?(a):(b))

#define INIT_PID 	0

int global_exec_state = ES_STOP;

int Tid = -1;
int control_bus;
int viewer;
int RID = 0;

static func_entry func_table[] =
{ 
  { NULL, 0, NULL, NULL, NULL }
};

static act_entry act_table[] =
{
  { NULL, 0, NULL, NULL, NULL }
};

char *inf_table[] =
{ "name",		NULL,
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

#line 107 "buscontrol.c.nw"
void init()
{
  dap_init(control_bus, inf_table, func_table, act_table);
#line 116 "buscontrol.c.nw"
  /* Initialize INIT process */
  dap_process_created(0, INIT_PID, "INIT", ES_STOP);
}
#line 128 "buscontrol.c.nw"
term_list *get_process_vars(int pid)
{
  return (term_list *)dap_get_process_data(0, pid);
}
#line 141 "buscontrol.c.nw"
void set_process_vars(int pid, term_list *vars)
{
  dap_set_process_data(0, pid, (void *)vars);
}
#line 284 "buscontrol.c.nw"
void continue_process(int pid)
{
  if(dap_check_process_flags(0, pid, PUF_WAITING)){ 
    TB_send(viewer, TB_make("snd-continue(<int>)", pid));
    dap_clear_process_flags(0, pid, PUF_WAITING);
  }
}
#line 153 "buscontrol.c.nw"
void cbdap_process_created(int dapid, int pid)
{
  TBprotect((term_list **)&dap_get_process(dapid, pid)->udata);
}
#line 165 "buscontrol.c.nw"
void cbdap_process_destroyed(int dapid, int pid)
{
  TBunprotect((term_list **)&dap_get_process(dapid, pid)->udata);
}
#line 178 "buscontrol.c.nw"
void cbdap_change_exec_state(int pid, int exec_state)
{
  switch(exec_state) {
    case ES_RUN:
    case ES_SINGLE_STEP:
	if(dap_check_process_flags(0, pid, PUF_WAITING))
	  continue_process(pid);
	break;
  }
}
#line 197 "buscontrol.c.nw"
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

#line 219 "buscontrol.c.nw"
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
#line 251 "buscontrol.c.nw"
void set_var_value(int pid, term *var, term *val)
{
  /* A variable is identified by a term represention. */
  term *vars, *cur_var;
  process *p;

  vars = get_process_vars(pid);
  p = dap_get_process(0, pid);
  TBprintf(stderr, "set_var_value in %s: %t vars: %t\n", p->name,
	var, vars);

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
#line 300 "buscontrol.c.nw"
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
#line 320 "buscontrol.c.nw"
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
    dap_process_created(0, new_pid, name, ES_STOP);
 
    /*TBprintf(stderr, "create_process: %t (%d, %s)\n", 
		args, new_pid, proc_db[new_pid]->name);*/
    dap_activate_rules(new_pid, TB_make("[process-creation,at]"));
  } else {
    TBprintf(stderr, "cannot find pid of created process: %t", args);
  }  
}

#line 351 "buscontrol.c.nw"
term *get_info(int cid)
{
  return TB_make("snd-value(info(<list>))", dap_get_info(cid));
}
#line 363 "buscontrol.c.nw"
term *get_processes(int cid)
{
  int i;
  term_list *procs = NULL;

  for(i=0; i<MAX_PROCESSES; i++) {
    process *p = dap_get_process(0, i);
    if(p)
      procs = list_concat_term(procs, TB_make("[<int>,<str>]", i, p->name));
  }
  return TB_make("snd-value(processes(<term>))", procs);
}
#line 383 "buscontrol.c.nw"
term *create_rule(int cid, term *procs, term *port, term *cond, term *acts, term *life)
{
  int rid = dap_create_rule(procs, port, cond, acts, life);
  return TB_make(
	"snd-value(create-rule(<term>,<term>,<term>,<term>,<term>,<int>))",
	procs, port, cond, acts, life, rid);
}
#line 398 "buscontrol.c.nw"
void modify_rule(int cid, int rid, term *procs, term *port, 
				term *cond, term *acts, term *life)
{
  dap_rule_modified(0, rid, procs, port, cond, acts, life);
}
#line 411 "buscontrol.c.nw"
void destroy_rule(int cid, term *procs, int rid)
{
  dap_destroy_rule(rid);
}

#line 496 "buscontrol.c.nw"
TBbool is_to_tool_comm(char *s)
{
  return streq(s, "snd-eval") 
         || streq(s, "snd-cancel") 
         || streq(s, "snd-do") 
         || streq(s, "snd-ack-event") 
         || streq(s, "snd-terminate");
}
#line 510 "buscontrol.c.nw"
TBbool is_from_tool_comm(char *s)
{
  return streq(s, "rec-value") 
         ||  streq(s, "rec-event") 
         || streq(s, "rec-disconnect");
}

#line 428 "buscontrol.c.nw"
term *rec_monitor(int cid, term *T)
{
  char *mon_point, *at_fun;
  int pid1, pid2;
  term *at_args, *at_coords, *env, *subs, *notes, *pe;

  /*TBprintf(stderr, "monitor command received: %t\n", T);*/
  if(TBmatch(T, "%f(%d,%f,%t,%t,%t,%t,%t,%d,%t)",
	     &mon_point, &pid1, &at_fun, &at_args, &at_coords,
	     &env, &subs, &notes, &pid2, &pe)) {
    /* Any common code prefix goes here */
    update_process(pid1, env);
    if(!dap_get_process(0, pid1)) {
      /* Steps executed when the process is not officially created yet
         are invisible! */
      TB_send(viewer, TB_make("snd-continue(<int>)", pid1));
      return;
    }
      
    dap_set_process_flags(0, pid1, PUF_WAITING);

    if(streq(at_fun, "create")) {
      /* Process creation monitoring */
      create_process(pid1, at_args); 
    } else if(streq(at_fun, "rec-connect")) {
      /* Tool connection monitoring */
    } else if(is_to_tool_comm(at_fun)) {
      /* Process -> Tool communication monitoring */
    } else if(is_from_tool_comm(at_fun)) {
      /* Tool -> Process communication monitoring */
    } else if(streq(at_fun, "endlet")) {
      /* Endlet monitoring */
    } else if(pid2 >= 0) {
      /* Process <-> process communication */
    } else {
      /* Other atoms (assignment, printf, tau, etc.) */
    }

    /* Now we can activate all location rules */
    if(at_coords)
      dap_activate_rules(pid1, 
	list_concat(TB_make("[location,after]"), at_coords));

    /* Any common code postfix goes here */
    switch(dap_get_exec_state(0, pid1)) {
	case ES_STOP:
	case ES_SINGLE_STEP:	/* Later, we need to do something more
				   sophisticated here later. */
				dap_change_exec_state(pid1, ES_STOP);
				break;
	case ES_RUN:		continue_process(pid1);
				break;
        case ES_HIGH_WATER:	break;
	default:	/* An illegal exec state? better crash and burn! */
			TBmsg("process %d, exec_state = %d\n",
				pid1, dap_get_exec_state(0, pid1));
			assert(0);
    }
  } else {
    err_fatal("badly formed monitor function: %t\n", T);
  }
  return NULL;
}
#line 526 "buscontrol.c.nw"
void rec_ack_event(int cid, term *ev)
{
  dap_rec_ack_event(cid, ev);
}
#line 538 "buscontrol.c.nw"
void rec_terminate(int cid, term *arg)
{
  TBprintf(stderr, "Received termination request: %t\n", arg);
  dap_rec_terminate(cid, arg);
  exit(0);
}

#line 551 "buscontrol.c.nw"
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
