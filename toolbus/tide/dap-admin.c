#line 200 "dap-admin.c.nw"
#include "dap-admin.h"

dap *daps[MAX_DAPS];

#line 243 "dap-admin.c.nw"
void dap_admin_init()
{
  int i;

  for(i=0; i<MAX_DAPS; i++)
    daps[i] = NULL;
}
#line 258 "dap-admin.c.nw"
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
#line 289 "dap-admin.c.nw"
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
#line 312 "dap-admin.c.nw"
dap *dap_get(int dapid)
{
  return daps[dapid];
}
#line 324 "dap-admin.c.nw"
int dap_id(term *d)
{
  int dapid;

  if(!TB_match(d, "debug-adapter(<int>)", &dapid)) {
    TBprintf(stderr, "illegal dap term: %t\n", d);
    exit(1);
  }
  return dapid;
}

#line 341 "dap-admin.c.nw"
void dap_rule_created(int dapid, int rid, term_list *procs, 
		term *port, term *cond, term *acts, term *lifetime)
{
  event_rule *rule;

  assert(daps[dapid]);
  assert(!daps[dapid]->rules[rid]);
  
#line 367 "dap-admin.c.nw"
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
#line 349 "dap-admin.c.nw"
  assert(rule);

  rule->pids = procs;
  rule->cond = cond;
  rule->acts = acts;
  rule->lifetime = dap_eventlife(lifetime);

  
#line 390 "dap-admin.c.nw"
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
#line 357 "dap-admin.c.nw"
  
#line 432 "dap-admin.c.nw"
  if(TBmatch(lifetime, "one-shot"))
    rule->lifetime = ONE_SHOT;
  else
    rule->lifetime = PERSISTENT;

#line 359 "dap-admin.c.nw"
  rule->next = daps[dapid]->ports[rule->port.type];
  daps[dapid]->ports[rule->port.type] = rule;
}
#line 446 "dap-admin.c.nw"
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

  
#line 472 "dap-admin.c.nw"
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
#line 461 "dap-admin.c.nw"
  
#line 499 "dap-admin.c.nw"
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
#line 462 "dap-admin.c.nw"
  
#line 541 "dap-admin.c.nw"
  if(TBmatch(lifetime, "one-shot"))
    rule->lifetime = ONE_SHOT;
  else
    rule->lifetime = PERSISTENT;

#line 464 "dap-admin.c.nw"
  rule->next = daps[dapid]->ports[rule->port.type];
  daps[dapid]->ports[rule->port.type] = rule;
}
#line 555 "dap-admin.c.nw"
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
#line 600 "dap-admin.c.nw"
event_rule *dap_get_rule(int dapid, int ruleid)
{
  return daps[dapid]->rules[ruleid];
}
#line 612 "dap-admin.c.nw"
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
#line 651 "dap-admin.c.nw"
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
#line 669 "dap-admin.c.nw"
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
#line 687 "dap-admin.c.nw"
int dap_eventlife(term *life)
{
  if(TBmatch(life, "one-shot"))
    return ONE_SHOT;
  if(!TBmatch(life, "persistent"))
    TBprintf(stderr, "illegal event lifetime: %t\n", life);

  return PERSISTENT;  
}
#line 704 "dap-admin.c.nw"
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

#line 726 "dap-admin.c.nw"
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
  p->ruleid = -1;
  p->subterms = NULL;

  TBprotect(&p->subterms);

  p->uflags = 0;
  p->udata = NULL;
  d->procs[pid] = p;

  cbdap_process_created(dapid, pid);
}
#line 772 "dap-admin.c.nw"
void dap_process_destroyed(int dapid, int pid)
{
  assert(daps[dapid]);
  assert(daps[dapid]->procs[pid]);
  cbdap_process_destroyed(dapid, pid);
  TBunprotect(&daps[dapid]->procs[pid]->subterms);
  if(daps[dapid]->procs[pid]->udata)
    free(daps[dapid]->procs[pid]->udata);
  free(daps[dapid]->procs[pid]->name);
  free(daps[dapid]->procs[pid]);
  daps[dapid]->procs[pid] = NULL;
}
#line 790 "dap-admin.c.nw"
process *dap_get_process(int dapid, int pid)
{
  assert(daps[dapid]);
  return daps[dapid]->procs[pid];  
}
#line 803 "dap-admin.c.nw"
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
#line 830 "dap-admin.c.nw"
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
#line 847 "dap-admin.c.nw"
int dap_get_stop_level(int dapid, int pid)
{
  return dap_get_process(dapid, pid)->stop_level;
}
#line 857 "dap-admin.c.nw"
int dap_get_exec_state(int dapid, int pid)
{
  return dap_get_process(dapid, pid)->exec_state;
}
#line 867 "dap-admin.c.nw"
char *dap_get_process_name(int dapid, int pid)
{
  return dap_get_process(dapid, pid)->name;
}

#line 893 "dap-admin.c.nw"
void *dap_get_process_data(int dapid, int pid)
{
  return dap_get_process(dapid, pid)->udata;
}
#line 881 "dap-admin.c.nw"
void  dap_set_process_data(int dapid, int pid, void *udata)
{
  dap_get_process(dapid, pid)->udata = udata;
}
#line 906 "dap-admin.c.nw"
void  dap_set_process_flags(int dapid, int pid, int uflags)
{
  dap_get_process(dapid, pid)->uflags |= uflags;
}
#line 919 "dap-admin.c.nw"
void  dap_clear_process_flags(int dapid, int pid, int uflags)
{
  dap_get_process(dapid, pid)->uflags &= ~uflags;
}
#line 932 "dap-admin.c.nw"
unsigned  dap_check_process_flags(int dapid, int pid, int uflags)
{
  return dap_get_process(dapid, pid)->uflags & uflags;
}
