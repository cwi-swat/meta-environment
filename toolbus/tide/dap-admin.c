#line 208 "dap-admin.c.nw"
#include "dap-admin.h"

dap *daps[MAX_DAPS];

#line 259 "dap-admin.c.nw"
void dap_admin_init()
{
  int i;

  for(i=0; i<MAX_DAPS; i++)
    daps[i] = NULL;
}
#line 274 "dap-admin.c.nw"
void dap_new(int dapid, term_list *info)
{
  int i;

  if(!daps[dapid]) {
    daps[dapid] = (dap *)malloc(sizeof(dap));
    if(!daps[dapid]) {
      fprintf(stderr, "out of memory in dap_dap_connected\n");
      exit(1);
    }
    daps[dapid]->id = dapid;
    daps[dapid]->info = NULL;
    TBprotect(&daps[dapid]->info);
    for(i=0; i<MAX_PROCESSES; i++)
      daps[dapid]->procs[i] = NULL;
    for(i=0; i<MAX_EVENT_RULES; i++)
      daps[dapid]->rules[i] = NULL;
    for(i=0; i<NR_PORT_TYPES; i++)
      daps[dapid]->ports[i] = NULL;
  }
  if(info)
    daps[dapid]->info = info;
}
#line 305 "dap-admin.c.nw"
void dap_delete(int dapid)
{
  int i;

  assert(daps[dapid]);
  for(i=0; i<MAX_PROCESSES; i++) {
    if(daps[dapid]->procs[i])
      dap_process_destroyed(dapid, i);
  }
  for(i=0; i<MAX_EVENT_RULES; i++) {
    if(daps[dapid]->rules[i])
      free(daps[dapid]->rules[i]);
  }
  TBunprotect(&daps[dapid]->info);
}
#line 328 "dap-admin.c.nw"
dap *dap_get(int dapid)
{
  return daps[dapid];
}
#line 340 "dap-admin.c.nw"
int dap_id(term *d)
{
  int dapid;

  if(!TB_match(d, "debug-adapter(<int>)", &dapid)) {
    TBprintf(stderr, "illegal dap term: %t\n", d);
    exit(1);
  }
  return dapid;
}

#line 357 "dap-admin.c.nw"
void dap_rule_created(int dapid, int rid, term_list *procs, 
		term *port, term *cond, term *acts, term *lifetime)
{
  event_rule *rule;

  assert(daps[dapid]);
  assert(!daps[dapid]->rules[rid]);
  
#line 383 "dap-admin.c.nw"
  daps[dapid]->rules[rid] = (event_rule *)malloc(sizeof(event_rule));
  rule = daps[dapid]->rules[rid];
  if(!rule) {
    fprintf(stderr, "out of memory in dap_rule_created\n");
    exit(1);
  }
  rule->id = rid;
  rule->pids = NULL;
  rule->cond = NULL;
  rule->acts = NULL;
  TBprotect(&rule->pids);
  TBprotect(&rule->cond);
  TBprotect(&rule->acts);
#line 365 "dap-admin.c.nw"
  assert(rule);

  rule->pids = procs;
  rule->cond = cond;
  rule->acts = acts;
  rule->lifetime = dap_eventlife(lifetime);

  
#line 406 "dap-admin.c.nw"
{
  term *type = list_index(port, 1);
  term *when = list_index(port, 2);

  rule->port.when = dap_eventwhen(when);
  rule->port.type = dap_eventport(type);
  switch(rule->port.type) {  
    case PORT_EXEC_STATE:
			rule->port.u.exec_state = 
					dap_term2es(list_index(port, 3));
			break;
    case PORT_LOCATION:	dap_eventlocation(list_next(list_next(port)),
				&rule->port.u.loc);
			break;
    case PORT_CALL:
    case PORT_FAIL:
    case PORT_RETRY:
    case PORT_SUCCEED:	
	rule->port.u.function = strdup(str_val(list_index(port, 3)));
	break;

    case PORT_EXCEPTION:
	rule->port.u.exception = strdup(str_val(list_index(port, 3)));
	break;

    case PORT_VARIABLE:
	rule->port.u.var = strdup(str_val(list_index(port, 3)));
	break;

    case PORT_SEND:
    case PORT_RECEIVE:
	rule->port.u.msg = list_index(port, 3);
	TBprotect(&rule->port.u.msg);
	break;
  }
}
#line 373 "dap-admin.c.nw"
  
#line 448 "dap-admin.c.nw"
  if(TBmatch(lifetime, "one-shot"))
    rule->lifetime = ONE_SHOT;
  else
    rule->lifetime = PERSISTENT;

#line 375 "dap-admin.c.nw"
  rule->next = daps[dapid]->ports[rule->port.type];
  daps[dapid]->ports[rule->port.type] = rule;
}
#line 462 "dap-admin.c.nw"
void dap_rule_modified(int dapid, int rid, term_list *procs, 
		term *port, term *cond, term *acts, term *lifetime)
{
  event_rule *rule;

  assert(daps[dapid]);
  rule = daps[dapid]->rules[rid];
  assert(rule);

  rule->pids = procs;
  rule->cond = cond;
  rule->acts = acts;
  rule->lifetime = dap_eventlife(lifetime);

  
#line 488 "dap-admin.c.nw"
  switch(rule->port.type) {
    case PORT_LOCATION:	if(rule->port.u.loc.module)
			  free(rule->port.u.loc.module);
    case PORT_CALL:
    case PORT_FAIL:
    case PORT_RETRY:
    case PORT_SUCCEED:	free(rule->port.u.function);
			break;
    case PORT_EXCEPTION:
			free(rule->port.u.exception);
			break;
    case PORT_VARIABLE:	free(rule->port.u.var);
			break;
    case PORT_SEND:
    case PORT_RECEIVE:	TBunprotect(&rule->port.u.msg);
			break;
  }
#line 477 "dap-admin.c.nw"
  
#line 515 "dap-admin.c.nw"
{
  term *type = list_index(port, 1);
  term *when = list_index(port, 2);

  rule->port.when = dap_eventwhen(when);
  rule->port.type = dap_eventport(type);
  switch(rule->port.type) {  
    case PORT_EXEC_STATE:
			rule->port.u.exec_state = 
					dap_term2es(list_index(port, 3));
			break;
    case PORT_LOCATION:	dap_eventlocation(list_next(list_next(port)),
				&rule->port.u.loc);
			break;
    case PORT_CALL:
    case PORT_FAIL:
    case PORT_RETRY:
    case PORT_SUCCEED:	
	rule->port.u.function = strdup(str_val(list_index(port, 3)));
	break;

    case PORT_EXCEPTION:
	rule->port.u.exception = strdup(str_val(list_index(port, 3)));
	break;

    case PORT_VARIABLE:
	rule->port.u.var = strdup(str_val(list_index(port, 3)));
	break;

    case PORT_SEND:
    case PORT_RECEIVE:
	rule->port.u.msg = list_index(port, 3);
	TBprotect(&rule->port.u.msg);
	break;
  }
}
#line 478 "dap-admin.c.nw"
  
#line 557 "dap-admin.c.nw"
  if(TBmatch(lifetime, "one-shot"))
    rule->lifetime = ONE_SHOT;
  else
    rule->lifetime = PERSISTENT;

#line 480 "dap-admin.c.nw"
  rule->next = daps[dapid]->ports[rule->port.type];
  daps[dapid]->ports[rule->port.type] = rule;
}
#line 571 "dap-admin.c.nw"
void dap_rule_destroyed(int dapid, int rid)
{
  event_rule *prev = NULL, *cur, *rule = daps[dapid]->rules[rid];
  assert(rule);
  daps[dapid]->rules[rid] = NULL;
  cur = daps[dapid]->ports[rule->port.type];
  while(cur && cur != rule) {
    prev = cur;
    cur = cur->next;
  }
  assert(cur);
  if(prev)
    prev->next = cur->next;
  else
    daps[dapid]->ports[rule->port.type] = cur->next;

  TBunprotect(&rule->pids);
  TBunprotect(&rule->cond);
  TBunprotect(&rule->acts);
  switch(rule->port.type) {
    case PORT_LOCATION:	if(rule->port.u.loc.module)
			  free(rule->port.u.loc.module);
    case PORT_CALL:
    case PORT_FAIL:
    case PORT_RETRY:
    case PORT_SUCCEED:	free(rule->port.u.function);
			break;
    case PORT_EXCEPTION:
			free(rule->port.u.exception);
			break;
    case PORT_VARIABLE:	free(rule->port.u.var);
			break;
    case PORT_SEND:
    case PORT_RECEIVE:	TBunprotect(&rule->port.u.msg);
			break;
  }
}
#line 616 "dap-admin.c.nw"
event_rule *dap_get_rule(int dapid, int ruleid)
{
  return daps[dapid]->rules[ruleid];
}
#line 628 "dap-admin.c.nw"
int dap_eventport(term *type)
{
  if(TBmatch(type, "exec-state")) {
    return PORT_EXEC_STATE;
  } else if(TBmatch(type, "always")) {
    return PORT_ALWAYS;
  } else if(TBmatch(type, "location")) {
    return PORT_LOCATION;
  } else if(TBmatch(type, "call")) {
    return PORT_CALL;
  } else if(TBmatch(type, "fail")) {
    return PORT_FAIL;
  } else if(TBmatch(type, "succeed")) {
    return PORT_SUCCEED;
  } else if(TBmatch(type, "fail")) {
    return PORT_FAIL;
  } else if(TBmatch(type, "exception")) {
    return PORT_EXCEPTION;
  } else if(TBmatch(type, "variable")) {
    return PORT_VARIABLE;
  } else if(TBmatch(type, "send")) {
    return PORT_SEND;
  } else if(TBmatch(type, "receive")) {
    return PORT_RECEIVE;
  } else if(TBmatch(type, "process-creation")) {
    return PORT_PROCESS_CREATION;
  } else if(TBmatch(type, "process-destruction")) {
    return PORT_PROCESS_DESTRUCTION;
  } else {
    TBprintf(stderr, "illegal porttype: %t\n", type);
    exit(1);
  }
}
#line 667 "dap-admin.c.nw"
int dap_eventwhen(term *when)
{
  if(TBmatch(when, "at"))
    return WHEN_AT;
  if(TBmatch(when, "before"))
    return WHEN_BEFORE;
  if(TBmatch(when, "after"))
    return WHEN_AFTER;

  TBprintf(stderr, "illegal activation moment: %t\n", when);
  return WHEN_AT;
}
#line 685 "dap-admin.c.nw"
term *dap_when2term(int when)
{
  switch(when) {
    case WHEN_AT:	return TBmake("at");
    case WHEN_BEFORE:	return TBmake("before");
    case WHEN_AFTER:	return TBmake("after");
  }
  assert(0);
  return NULL;
}
#line 703 "dap-admin.c.nw"
int dap_eventlife(term *life)
{
  if(TBmatch(life, "one-shot"))
    return ONE_SHOT;
  if(!TBmatch(life, "persistent"))
    TBprintf(stderr, "illegal event lifetime: %t\n", life);

  return PERSISTENT;  
}
#line 720 "dap-admin.c.nw"
void dap_eventlocation(term_list *loc_data, location *l)
{
  if(TB_match(loc_data, "[<str>,<int>,<int>,<int>,<int>]",
		&l->module,
		&l->start_line, &l->start_col, &l->end_line, &l->end_col))
    return;

  TBprintf(stderr, "Illegal location data: %t\n", loc_data);
  l->module = NULL;
  l->start_line = -1;
  l->end_line = -1;
  return;
}

#line 742 "dap-admin.c.nw"
void dap_process_created(int dapid, int pid, char *name, int exec_state)
{
  dap *d = daps[dapid];
  process *p = NULL;

  assert(d);
  assert(!d->procs[pid]);
  p = (process *)malloc(sizeof(process));
  if(!p) {
    fprintf(stderr, "out of memory in dap_process_created\n");
    exit(1);
  }

  p->pid = pid;
  p->name = strdup(name);
  if(!p->name) {
    fprintf(stderr, "out of memory in dap_process_created.\n");
    exit(1);
  }
  
  p->cpe.module = NULL;
  p->cpe.start_line = -1;
  p->cpe.start_col  = -1;
  p->cpe.end_line   = -1;
  p->cpe.end_col    = -1;
  p->cpe.when	    = WHEN_AT;
  p->exec_state = exec_state;
  p->new_es = exec_state;
  p->new_es = exec_state;
  p->hw_reached = TBfalse;
  p->ruleid = -1;
  p->last_port = NULL;
  p->last_msg = NULL;
  p->last_peer = NULL;
  p->subterms = NULL;

  TBprotect(&p->last_port);
  TBprotect(&p->last_msg);
  TBprotect(&p->last_peer);
  TBprotect(&p->subterms);

  p->uflags = 0;
  p->udata = NULL;
  d->procs[pid] = p;

  dap_set_last_port(0, pid, TB_make("[exec-state,at,<term>]", dap_es2term(exec_state)));
  cbdap_process_created(dapid, pid);
}
#line 798 "dap-admin.c.nw"
void dap_process_destroyed(int dapid, int pid)
{
  assert(daps[dapid]);
  assert(daps[dapid]->procs[pid]);
  cbdap_process_destroyed(dapid, pid);
  TBunprotect(&daps[dapid]->procs[pid]->last_port);
  TBunprotect(&daps[dapid]->procs[pid]->last_msg);
  TBunprotect(&daps[dapid]->procs[pid]->last_peer);
  TBunprotect(&daps[dapid]->procs[pid]->subterms);
  if(daps[dapid]->procs[pid]->udata)
    free(daps[dapid]->procs[pid]->udata);
  free(daps[dapid]->procs[pid]->name);
  free(daps[dapid]->procs[pid]);
  daps[dapid]->procs[pid] = NULL;
}
#line 819 "dap-admin.c.nw"
process *dap_get_process(int dapid, int pid)
{
  assert(daps[dapid]);
  return daps[dapid]->procs[pid];  
}
#line 832 "dap-admin.c.nw"
int dap_term2es(term *t)
{
  if(TBmatch(t, "stop"))
    return ES_STOP;
  if(TBmatch(t, "single-step"))
    return ES_SINGLE_STEP;
  if(TBmatch(t, "step-over"))
    return ES_STEP_OVER;
  if(TBmatch(t, "run"))
    return ES_RUN;
  if(TBmatch(t, "run-until-parent"))
    return ES_RUN_UNTIL_PARENT;

  if(TBmatch(t, "all"))
    return ES_ALL;

  TBprintf(stderr, "illegal exec-control: %t, stop assumed\n", t);
  return ES_STOP;
}
#line 859 "dap-admin.c.nw"
term *dap_es2term(int es)
{
  switch(es) {
    case ES_STOP:		return TBmake("stop");
    case ES_SINGLE_STEP:	return TBmake("single-step");
    case ES_STEP_OVER:		return TBmake("step-over");
    case ES_RUN:		return TBmake("run");
    case ES_RUN_UNTIL_PARENT:	return TBmake("run-until-parent");
  }
  return TBmake("unknown");
}
#line 876 "dap-admin.c.nw"
int dap_get_stop_level(int dapid, int pid)
{
  return dap_get_process(dapid, pid)->stop_level;
}
#line 886 "dap-admin.c.nw"
int dap_get_exec_state(int dapid, int pid)
{
  return dap_get_process(dapid, pid)->exec_state;
}
#line 896 "dap-admin.c.nw"
int dap_get_new_exec_state(int dapid, int pid)
{
  return dap_get_process(dapid, pid)->new_es;
}
#line 906 "dap-admin.c.nw"
TBbool dap_is_high_water(int dapid, int pid)
{
  return dap_get_process(dapid, pid)->hw_reached;
}
#line 916 "dap-admin.c.nw"
void dap_set_high_water(int dapid, int pid, TBbool hw)
{
  dap_get_process(dapid, pid)->hw_reached = hw;
}
#line 926 "dap-admin.c.nw"
char *dap_get_process_name(int dapid, int pid)
{
  return dap_get_process(dapid, pid)->name;
}

#line 952 "dap-admin.c.nw"
void *dap_get_process_data(int dapid, int pid)
{
  return dap_get_process(dapid, pid)->udata;
}
#line 940 "dap-admin.c.nw"
void  dap_set_process_data(int dapid, int pid, void *udata)
{
  dap_get_process(dapid, pid)->udata = udata;
}
#line 965 "dap-admin.c.nw"
void  dap_set_process_flags(int dapid, int pid, int uflags)
{
  dap_get_process(dapid, pid)->uflags |= uflags;
}
#line 978 "dap-admin.c.nw"
void  dap_clear_process_flags(int dapid, int pid, int uflags)
{
  dap_get_process(dapid, pid)->uflags &= ~uflags;
}
#line 991 "dap-admin.c.nw"
unsigned  dap_check_process_flags(int dapid, int pid, int uflags)
{
  return dap_get_process(dapid, pid)->uflags & uflags;
}
#line 1001 "dap-admin.c.nw"
void  dap_set_last_port(int dapid, int pid, term *port)
{
  dap_get_process(dapid, pid)->last_port = port;  
}
#line 1011 "dap-admin.c.nw"
term *dap_get_last_port(int dapid, int pid)
{
  return dap_get_process(dapid, pid)->last_port;
}
#line 1021 "dap-admin.c.nw"
void dap_set_last_msg(int dapid, int pid, term *msg)
{
  dap_get_process(dapid, pid)->last_msg = msg;
}
#line 1031 "dap-admin.c.nw"
term *dap_get_last_msg(int dapid, int pid)
{
  return dap_get_process(dapid, pid)->last_msg;
}
#line 1041 "dap-admin.c.nw"
void dap_set_last_peer(int dapid, int pid, term *peer)
{
  dap_get_process(dapid, pid)->last_peer = peer;
}
#line 1051 "dap-admin.c.nw"
term *dap_get_last_peer(int dapid, int pid)
{
  return dap_get_process(dapid, pid)->last_peer;
}
