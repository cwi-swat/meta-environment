/*{{{  header */

/*

   ToolBus -- The ToolBus Application Architecture
   Copyright (C) 1998-2000  Stichting Mathematisch Centrum, Amsterdam, 
   The  Netherlands.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/

/*}}}  */
/*{{{  includes */

#include "toolbus.h"
#include "terms.h"
#include "env.h"
#include "procs.h"
#include "tools.h"

#include "interpreter.h"

#include "utils.h"
#include "monitor.h"
#include "typecheck.h"
#include "interpreter.h"
#include <sys/types.h>
#include <sys/socket.h>
#include "sockets.h"

#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>

/*}}}  */

/*{{{  externals */

extern int accept_client(TBbool);
extern TBbool parse_script(char *);

/*}}}  */

/*{{{  variables */

TBbool local_ports = TBfalse;

static int pgid = -1;

/*}}}  */

/*{{{  void chld_handler(int sig) */

void chld_handler(int sig)
{
  if(pgid != -1)
  {
    /* wait for childs in process group pgid */
    waitpid(-pgid, NULL, WNOHANG);
  }
}

/*}}}  */


/*--- tool definitions ------------------------------------*/

static tool_def_list *tool_defs = NULL;   /* PROTECTED */

/*{{{  tool_def *get_tool_defs() */

tool_def *get_tool_defs()
{
  return tool_defs;
}

/*}}}  */

/*{{{  tool_def *find_tool_def(sym_idx tname) */

tool_def *find_tool_def(sym_idx tname)
{
  tool_def_list *tdl;
  tool_def *td;

  /* fprintf(stderr, "find_tool_def, tool_defs = "); pr_term(tool_defs);*/
  for(tdl = tool_defs; tdl; tdl = next(tdl)){
    td = first(tdl);
    if(tname == td_name(td))
      return td;
  }
  return NULL;
}

/*}}}  */

/*{{{  add_tool_def(....) */

void add_tool_def(char *id, term_list *formals, 
		  char *host, char *command, char *details,
		  term *script_name, int lino)
{
  tool_def * td;

  if(find_tool_def(TBlookup(id))){
    tc_double_decl("tool name", id, script_name, lino);
    return;
  } else {
    check_formals_vars(formals, NULL, script_name, lino);
    if(streq(host, ""))
      host = this_host;

    td = mk_tool_def(id, formals, host, command, details);
    tool_defs = mk_list(td, tool_defs);
  }
}

/*}}}  */

/*
 * complete_tool_sigs adds to the signature of each tool definition:
 * to td_out_sign:
 * - snd-connect(tool-name(<int>))
 * to td_in_sign:
 * - rec-terminate(tool-id(<int>), <term>)
 *
 * and writes to the tool interfaces file, if needed.
 */

/*{{{  void complete_tool_sigs() */

void complete_tool_sigs()
{
  tool_def_list *tds;
  term *placeT = mk_placeholder(Term);
  term *tld, *trm, *con;
  tool_def *td;

  for(tds = tool_defs; tds; tds = next(tds)){
    td = first(tds);
    /* tld = mk_placeholder(mk_appl1(td_name(td), Int)); */
    tld = mk_placeholder(mk_appl(td_name(td), NULL));

    trm = mk_appl2(a_rec_terminate, tld, placeT);
    con = mk_appl1(a_snd_connect, tld);

    td_in_sign(td) = mk_list(trm, td_in_sign(td));
    td_out_sign(td) = mk_list(con, td_out_sign(td));
  }  
}

/*}}}  */

/* -------- tool instances ------------------------ */

int n_tool_inst = 0;    /* tool inst counter */

tool_inst_list *Tools;  /* PROTECTED */

/* Check if a certain event is present in a list of event types.
   The event matches an event type when teh event type is a prefix
   of the event. For instance:
   foo(bar) matches foo, but not foo(boo).
   foo(1,2,3) matches foo(1,2), but not foo(1,3) etc.
   */

/*{{{  TBbool has_prefix(term *t, term *p) */

TBbool has_prefix(term *t, term *p)
{
  term_list *argt, *argp;

  if(is_appl(t)) {
    if(!is_appl(p) || fun_sym(t) != fun_sym(p))
      return TBfalse;
    argt = fun_args(t);
    argp = fun_args(p);
    while(argp) {
      if(!argt || !term_equal(first(argt), first(argp)))
	return TBfalse;
      argt = next(argt);
      argp = next(argp);
    }  
    return TBtrue;
  }
  return term_equal(t,p);
}

/*}}}  */

/*{{{  TBbool event_present(term *ev, term *l) */

TBbool event_present(term *ev, term *l)
{
  term *et;

  while(l) {
    et = first(l);
    l = next(l);
    if(has_prefix(ev, et))
      return TBtrue;
  }
  return TBfalse;
}

/*}}}  */

/*{{{  term_list *event_delete(term_list *l, term *ev) */

term_list *event_delete(term_list *l, term *ev)
{
  term *et;
  term_list *result = NULL;
  TBbool removed = TBfalse;

  while(l) {
    et = first(l);
    l = next(l);
    if(removed || !has_prefix(ev, et))
      result = list_concat_term(result, et);
    else
      removed = TBtrue;
  }
  return result;
}

/*}}}  */

/*
 * Transition function for Tool Control Protocol.
 * Note that the protocol is defined from the
 * perspective of the *tool*, i.e., we use
 * a_snd_value rather than a_rec_value.
 * ti:     the tool_instance for which a transition is required
 * event:  the event
 * update: true => update ti, false => ti unchanged
 *
 * Returns: PHASE1, PHASE2, PHASE3 when legal transition
*          -1 for illegal transition
 *
 * Note there is one deviation from the "official" TCP protocol.
 * Similar to the rec-eval/snd-value pair we introduce a new
 * message snd-void to form the pair rec-do/snd-void.
 * Motivation: to avoid buffer overflow in the operating system's
 * kernel when *many* do's are being sent to the same tool.
 */

#define return_phase(PH) {if(update) ti_phase(ti) = PH; return PH;}

/*{{{  int TCP_transition(tool_inst *ti, term *event, TBbool update) */

int TCP_transition(tool_inst *ti, term *event, TBbool update)
{
  sym_idx ev = fun_sym(event);
  term_list *pending;
  term *t;

  /*TBmsg("TCP_transition(%t,%t)\n", ti, event);*/
  switch(ti_phase(ti)){
    case PHASE1:
      if(ev == a_snd_connect){
	return_phase(PHASE2);
      } else
	return -1;

    case PHASE2:
      switch(ev){
	case a_rec_do:
	case a_rec_eval:      return_phase(PHASE3);

	case a_rec_terminate:
	case a_snd_attach_monitor:
	case a_snd_detach_monitor:
	case a_rec_monitor:
	case a_snd_continue:
			      return_phase(PHASE2);
	case a_snd_event:
			      pending = ti_pending(ti);
			      assert(list_length(fun_args(event)) >= 2);
			      t = first(next(fun_args(event)));
			      if(list_elem(t, pending))
				return -1;
			      else {
				if(update)
				  ti_pending(ti) = mk_list(t, pending);
				return_phase(PHASE2);
			      }
	case a_rec_ack_event:
			      pending = ti_pending(ti);
			      t = first(fun_args(event));
			      if(event_present(t, pending)){
				if(update)
				  ti_pending(ti) = event_delete(pending, t);
				return_phase(PHASE2);
			      } else
				return -1;

	case a_snd_disconnect: return_phase(PHASE1);

	case a_rec_cancel:
	case a_snd_value:
	case a_snd_connect:    return -1;

	default:
			       err_fatal("TCP_transition -- PHASE2, event: %t", event);
			       return -1; /* pedantic */
      }    
    case PHASE3:
      switch(ev){
	case a_rec_cancel:
	case a_snd_void:   
	case a_snd_value:          return_phase(PHASE2);
	case a_rec_monitor:
	case a_snd_continue:
	case a_rec_terminate:      return_phase(PHASE3);

	case a_snd_event:
				   pending = ti_pending(ti);
				   assert(list_length(fun_args(event)) >= 2);
				   t = first(next(fun_args(event)));
				   if(list_elem(t, pending))
				     return -1;
				   else {
				     if(update)
				       ti_pending(ti) = mk_list(t, pending);
				     return_phase(PHASE3);
				   }
	case a_rec_ack_event:
				   pending = ti_pending(ti);
				   t = first(fun_args(event));
				   if(event_present(t, pending)){
				     if(update)
				       ti_pending(ti) = event_delete(pending, t);
				     return_phase(PHASE3);
				   } else
				     return -1;

	case a_rec_eval:
	case a_rec_do:
	case a_snd_connect:
	case a_snd_disconnect:
	case a_snd_attach_monitor:
	case a_snd_detach_monitor:
				   return -1;
	default:

				   err_fatal("TCP_transition -- PHASE3, event: %t", event);
				   return -1; /* pedantic */
      }
    default:
      err_fatal("TCP_transition -- illegal PHASE");
      return -1; /* pedantic */
  }
}

/*}}}  */

/*{{{  TBbool write_to_tool(sym_idx af, term_list *args) */

TBbool write_to_tool(sym_idx af, term_list *args)
{
  int out;
  tool_inst_list *tools = Tools;
  tool_inst *ti;
  tool_id *tid;
  term *e;

  if(TBverbose) TBmsg("write_to_tool(%s,%t)\n", get_txt(af), args);

  if(!(is_appl(first(args)) && (list_length(fun_args(first(args))) == 1) &&
       is_int(first(fun_args(first(args)))))){
    err_warn("illegal tool identifier in: %f(%l)", get_txt(af), args);
    return TBfalse;
  }

  tid = first(fun_args(first(args)));

  e = mk_appl(reverse_role(af), next(args)); /* excludes tool id (first arg) */

  /* TBprintf(stderr, "tid = %t, e = %t\n", tid, e); 
     TBprintf(stderr, "\nTools: "); pr_term(Tools); fprintf(stderr, "\n"); */

  for(tools = Tools; tools; tools = next(tools)){
    ti = first(tools);
    assert(is_tool_inst(ti));

    if(equal_tool_id(tid, ti_tid(ti))){
      if((out = ti_out(ti)) < 0) {
	if(stand_alone){
	  TBprintf(stdout, "send to %s: %t\n", get_txt(ti_name(ti)), e);
	  return TBtrue;
	} else {
	  return TBfalse;
	}
      }
      if(TCP_transition(ti, e, TBtrue) >= 0){
	void destroy_ports_for_tool(tool_inst *);
	TBwrite(out,e);
	if(af == a_snd_terminate){
	  destroy_ports_for_tool(ti);
	  Tools = list_delete(Tools, ti);
	}
	return TBtrue;
      } else
	return TBfalse;
    }
  }
  return TBfalse;
}

/*}}}  */
/*{{{  TBbool connect_tool(int tid, int in, int out) */

TBbool connect_tool(int tid, int in, int out)
{
  tool_inst_list *tools;
  tool_inst *ti;

  for(tools = Tools; tools; tools = next(tools)){
    ti = first(tools);
    if(int_val(ti_tid(ti)) == tid){
      ti_in(ti) = in;
      ti_out(ti) = out;    
      if(TBverbose) TBmsg("connect_tool(%d,%d,%d) ... %t\n", tid, in, out, ti);
      rec_from_tool_step(ti, 
			 mk_appl1(a_snd_connect,
				  mk_appl1(fun_sym(ti_creator(ti)),  mk_int(tid))));
      return TBtrue;
    }
  }
  err_warn("connect_tool: no tool instance matches %d, %d, %d\n", tid, in , out);
  return TBfalse;
}

/*}}}  */

/*{{{  int add_tool(char *id, char *host) */

int add_tool(char *id, char *host)
{
  sym_idx idx = TBlookup(id);
  term *creator = mk_appl(idx, NULL);
  tool_def *td = find_tool_def(idx);

  if(!td){
    err_warn("no definition for tool `%s'", id);
    return -1;
  }

  if(TBverbose)
    TBmsg("adding tool, id=%s, host=%s, tid=%d\n", id, host, n_tool_inst);

  Tools = mk_list(mk_tool_inst(creator, n_tool_inst, host, -1,-1,PHASE1), Tools);
  return n_tool_inst++;
}

/*}}}  */

/*{{{  void destroy_ports_for_tool(tool_inst *ti) */

void destroy_ports_for_tool(tool_inst *ti)
{
  assert(is_tool_inst(ti));

  /* TBmsg("destroy_ports_for_tool(%t)\n", ti); */
  TBdestroyPort(ti_in(ti));
  TBdestroyPort(ti_out(ti));
}

/*}}}  */
/*{{{  void destroy_ports(void) */

void destroy_ports(void)
{ 
  tool_inst_list *tools;

  for(tools = Tools; tools; tools = next(tools)){
    destroy_ports_for_tool(first(tools)); 
  }
}

/*}}}  */

/*
 * Copy and substitute a part of a tool definition.
 *
 * pbuf    - pointer to pointer in result buffer (changed)
 * bmax    - end of result buffer
 * psrc    - pointer to pointer in src text (changed)
 * formals - parameter list of tool definition
 * creator - the term creating the current tool instance
 * stop_at_space
*         - return on first space character (used for expanding
*           the arguments of a command.
 * 
 *
 * Effect: copy src text until '\0' or ' ' to result buffer.
 * Whenever an uppercase letter occurs, check whether a formal
 * parameter name follows. If so, output its actual value.
 * If not, copy the name verbatim to the result.
 *
 * Returns the start address in the result buffer if text was
 * copied, and NULL otherwise.
 */

/*{{{  copy_and_subs(....) */

char *copy_and_subs(char **pbuf, char *bmax, char **psrc, term_list *formals,
		    term *creator, TBbool stop_at_space)
{
  char *org_buf = *pbuf, *buf = *pbuf, base_par_name[64], par_name[64], *s;
  char *src = *psrc;
  sym_idx id = fun_sym(creator);
  term_list * actuals = fun_args(creator), *args, *forms;
  int i;
  TBbool in_quote = TBfalse, escape = TBfalse;

  while(*src && isspace((int)*src))
    src++;

  if(!*src)
    return NULL;

loop:

  while(!isupper((int)*src)){
    if(!*src || (stop_at_space && !in_quote && isspace((int)*src))){
      *buf++ = '\0';
      *pbuf = buf;
      *psrc = src;      
      return org_buf;
    }
    if(!escape && *src == '\'') {
      if(in_quote)
	in_quote = TBfalse;
      else
	in_quote = TBtrue;
      src++;
    } else {
      if(!escape && *src == '\\') {
	escape = TBtrue;
	src++;
      } else {
	if(escape)
	  ; /* Here we can check for special escape sequences,
	       like '\n', '\t' etc. */
	escape = TBfalse;
	if(buf < bmax)
	  *buf++ = *src++;
	else {
too_long:
	  err_warn("%t: expanded tool definition is too long\n", creator);
	  return NULL;
	}
      }
    }
  }

  for(i = 0; isupper((int)*src); i++, src++){
    base_par_name[i] = par_name[i] = *src;
  }
  base_par_name[i] = '\0';

  sprintf(&par_name[i], "$%s", get_txt(id));
  args = actuals;
  for(forms = formals; forms; forms = next(forms)){
    if(streq(get_txt(var_sym(first(forms))), par_name)){
      switch(tkind(first(args))){
	case t_int:
	  if(buf + 16 > bmax)
	    goto too_long;
	  sprintf(buf, "%d", int_val(first(args)));
	  buf += strlen(buf);
	  goto loop;
	case t_str:
	  s = str_val(first(args));
	  if(buf + strlen(s) > bmax)
	    goto too_long;
	  if(*s)
	  {
	    sprintf(buf, "%s", s);
	    buf += strlen(buf);
	  }
	  goto loop;
	default:
	  err_warn("%t: integer or string argument required\n", creator);
	  return TBfalse;
      }
    } else {
      args = next(args);
    }
  }
  if(buf + strlen(base_par_name) > bmax)
    goto too_long;
  sprintf(buf, "%s", base_par_name);
  buf += strlen(buf);
  goto loop;  
}

/*}}}  */

#include <sys/types.h>
#include <unistd.h>

#define NTOOLARGS    20
#define EXP_TOOL_DEF (5*1024)

/*{{{  tool_id *create_tool(term *creator, term_list *args) */

tool_id *create_tool(term *creator, term_list *args)
{
  char buf[EXP_TOOL_DEF], *cbuf = buf, *cbufmax = &buf[EXP_TOOL_DEF];
  char *command, *host_tool, *details, *cmd_args, *cmd_arg, *p;
  char tid_buf[12], port_buf[12];
  int k, pid;
  char *std_args[NTOOLARGS];
  tool_def *td;

  assert(is_appl(creator));
  td = find_tool_def(fun_sym(creator));

  if(!td)
    err_fatal("missing tool definition: %t\n", creator);

  if(TBverbose)
    TBmsg("create_tool(%t), td = %t\n", creator, td);

  if(list_length(td_formals(td)) != list_length(fun_args(creator)))
    err_fatal("%t: %d actual(s) required", creator, list_length(fun_args(creator)));

  p = td_host(td);
  if(!(host_tool = copy_and_subs(&cbuf, cbufmax, &p, td_formals(td), creator, TBfalse)))
    host_tool = "";

  p = td_details(td);
  if(!(details = copy_and_subs(&cbuf, cbufmax, &p, td_formals(td), creator, TBfalse)))
    details = "";

  p = td_command(td);
  command = copy_and_subs(&cbuf, cbufmax, &p, td_formals(td), creator, TBtrue);
  cmd_args = p;

  if(!command)
    return TBfalse;

  if(streq(host_tool, this_host) || streq(host_tool, "")){
    std_args[0] = get_txt(td_name(td));
    k = 1;
  } else {
    std_args[0] = "rsh"; std_args[1] = host_tool; std_args[2] = command; k = 3;
    command = "rsh";
  }

  std_args[k++] = "-TB_HOST";      std_args[k++] = this_host; 
  std_args[k++] = "-TB_TOOL_NAME"; std_args[k++] = get_txt(td_name(td));

  sprintf(tid_buf, "%d", n_tool_inst);
  std_args[k++] = "-TB_TOOL_ID";   std_args[k++] = tid_buf;
  std_args[k++] = "-details";      std_args[k++] = details;

  sprintf(port_buf, "%d", WellKnownSocketPort);
  std_args[k++] = "-TB_PORT";    std_args[k++] = port_buf;

  if(local_ports){
    std_args[k++] = "-TB_LOCAL_PORTS";
  }

  while((cmd_arg = copy_and_subs(&cbuf, cbufmax, &cmd_args, td_formals(td), creator, TBtrue))){
    if(k >= NTOOLARGS)
      err_fatal("tool command has too many arguments");
    std_args[k++] = cmd_arg;
  }

  std_args[k] = NULL;

  /*
     { int j;
     for(j=0; j < k; j++)
     fprintf(stderr,"%s\n", std_args[j]);
     fprintf(stderr, "\n");
     }
     */


  if((pid = fork())){
    term *inst;
    /* toolbus: the parent */
    if(pid < 0){
      err_sys_warn("can't fork while executing `%s'", command);
      return NULL;
    }
    if(pgid == -1)
      pgid = pid;	/* One processgroup for all slaves */

    /* 
     * Set process group ID of child.
     * Note. This may fail due to a call to setpgid in the slave
     * process. The extra call here is still needed to prevent
     * from a race condition. Because of the possible failure,
     * we don't check the result value
     */
    setpgid( pid, pgid );

    /* lcc generated bad code for the next line (Probably because of
       the many recursive calls when the preprocessor expands it. I've
       tried many experiments, but haven't been able to reproduce it in
       a small example yet), so I replaced it with 'TBmake'. <PO> */
    /*inst = mk_tool_inst(creator, n_tool_inst, td_host(td), -1,-1,PHASE1);*/
    inst = TBmake("tool-inst(%t,%d,%d,%d,%s,%d,[])",
		  creator, n_tool_inst, -1, -1, td_host(td), PHASE1);
    /*TBprintf(stderr, "Inst = %t\n", inst);*/
    Tools = mk_list(inst, Tools);
    n_tool_inst++;
    return mk_int(n_tool_inst-1); /******/
  } else {
    /* tool: the child */
    /* <PO> sleep(n_tool_inst); */
    if(pgid == -1)
      pgid = getpid();

    /*
     * Set proces group ID of process. See note before
     * in parent. We thus ignore the result value here
     * to
     */
    setpgid(0, pgid);

    if(execvp(command, std_args) < 0){
      err_sys_warn("can't execute tool `%s'", command);
      exit(1);
      /* <PO> was: return NULL;*/
    }
  }
  err_fatal("create_tool, cannot come here"); /* pedantic */
  return NULL;
}

/*}}}  */

int nexttool = 0; /* for scheduling below */

extern struct timeval *get_timeout(void);

/*{{{  int read_from_any_channel(tool_inst **pti) */

int read_from_any_channel(tool_inst **pti)
{
  int nelem, error, retry_cnt = 0;
  fd_set read_template;
  tool_inst_list *til;
  tool_inst *ti;

retry:
  retry_cnt++;
  if(retry_cnt > 20)
    return -1;
  FD_ZERO(&read_template);
  for(til = Tools; til; til = next(til)){
    ti = first(til);
    if(ti_in(ti) >= 0){
      FD_SET(ti_in(ti),&read_template);
    }
  }

  if(stand_alone)
    FD_SET(0,&read_template);
  else {
    FD_SET(WellKnownLocalSocket,&read_template);
    FD_SET(WellKnownGlobalSocket,&read_template);
  }

  if((error = select(FD_SETSIZE, &read_template, NULL, NULL, get_timeout())) >= 0){
    if(stand_alone){
      nelem = read_from_stdin();
      return nelem;
    } else if(FD_ISSET(WellKnownLocalSocket, &read_template)){
      if(accept_client(TBtrue) == TB_ERROR)
	err_warn("could not accept client");
      all_internal_steps();
    } else if(FD_ISSET(WellKnownGlobalSocket, &read_template)){
      if(accept_client(TBfalse) == TB_ERROR)
	err_warn("could not accept client");
      all_internal_steps();
    } else if(error == 0){           /* timeout expired */
      if(TBverbose)
	TBmsg("select: timeout expired\n");
      all_internal_steps();
      retry_cnt = 0;
      goto retry;
    }
    /* round robin scheduler */ /*  !!! temp lineair !!! */
    for(til = Tools; til; til = next(til)){
      ti = first(til);
      if((ti_in(ti) >= 0) &&
	 FD_ISSET(ti_in(ti),&read_template)){
	nelem = multi_read(ti_in(ti));
	if(nelem == 0){
	  ti_in(ti) = -1;
	  if (TBverbose) {
	    err_warn("lost connection with %t\n", ti);
	  }
	  /* <PO> was: goto retry; */
	  *pti = ti;
	  return 0;
	}
	if(nelem < 0){
	  err_sys_warn("%t: read failed", ti);
	  goto retry;
	  return -1;
	}
	*pti = ti;
	return nelem;
      }
    }
    goto retry;
  } else {
    if(errno != EINTR)
      err_sys_warn("select failed");
    goto retry;
  }   
}

/*}}}  */

/*{{{  term *read_term(tool_inst **pti) */

term *read_term(tool_inst **pti)
{
  int nelem;
  term *trm;

  while(TBtrue) {
    nelem = read_from_any_channel(pti);
    if(nelem < 0)
      err_fatal("read_term: cannot find ready input channel");
    if (nelem == 0) {
      trm = TBmake("snd-disconnect");
    } else {
      trm = parse_buffer();
    }

    if(trm){
      tool_id *tid = ti_tid(*pti);
      sym_idx tool_name = ti_name(*pti);

      if(is_appl(trm)){
	if(is_legal_from_tool(fun_sym(trm)))
	  return mk_appl(fun_sym(trm),
			 mk_list(mk_appl1(tool_name, tid), fun_args(trm)));
	else {
	  err_warn("IGNORED FROM TOOL %s TERM WITH ILLEGAL FUNCTION SYMBOL: %t", 
		   get_txt(tool_name), trm);
	}
      }
      else
	err_warn("IGNORED FROM TOOL %s MALFORMED TERM: %t", get_txt(tool_name), trm);
    }
  }
}

/*}}}  */

/*{{{  void init_tools(void) */

void init_tools(void)
{
  TBprotect(&tool_defs);
  TBprotect(&Tools);
}

/*}}}  */
