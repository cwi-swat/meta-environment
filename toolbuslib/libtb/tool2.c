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
#include "toolbus.h"
#include "terms.h"
#include "tools.h"
#include "tool2.h"
#include "tool.h"
#include "procs.h"
#include "sockets.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

tb_connection *connections[MAX_CONNECTIONS] = { NULL };

#define assert_valid_cid(c) assert(c >= 0 && c < MAX_CONNECTIONS); \
                            assert(connections[c])


/*{{{  int TB_init() */

int TB_init()
{
  ToolBus = TBfalse;
  init_terms();
  init_utils();
  return gethostname(this_host, MAXHOSTNAMELEN);
}

/*}}}  */
/*{{{  int TB_newConnection(char *tool_name, char *host, int port, .2) */

int TB_newConnection(char *tool_name, char *host, int port, 
		       TBcallback handler, TBsigcheck checker)
{
  int i = 0;

  for(i=0; i<MAX_CONNECTIONS && connections[i]; i++)
    ;

  if(i<MAX_CONNECTIONS) {
    connections[i] = malloc(sizeof(tb_connection));
    if(connections[i]) {
      connections[i]->tool_name	= tool_name ? strdup(tool_name) : NULL;
      connections[i]->host	= host ? strdup(host) : NULL;
      connections[i]->port	= port;
      connections[i]->handler	= handler;
      connections[i]->sigchecker= checker;
      connections[i]->verbose	= TBfalse;
      connections[i]->tid	= -1;
      connections[i]->suspended = TBfalse;
      connections[i]->socket	= -1;

      return i;
    }
  }

  return -1;
}

/*}}}  */
/*{{{  int TB_parseArgs(int argc, char *argv, TBcallback handler, .1) */

int TB_parseArgs(int argc, char *argv[], TBcallback handler, TBsigcheck checker)
{
  int i;
  int cid = TB_newConnection(NULL, NULL, TB_PORT, handler, checker);
  if(cid >= 0) {
    for(i=0; i<argc; i++) {
      if(streq(argv[i], "-TB_TOOL_NAME")) {
        TB_setTool(cid, argv[++i]);
      } else if(streq(argv[i], "-TB_HOST")) {
	TB_setHost(cid, argv[++i]);
      } else if(streq(argv[i], "-TB_PORT")) {
        TB_setPort(cid, atoi(argv[++i]));
      } else if(streq(argv[i], "-TB_TOOL_ID")) {
	TB_setTid(cid, atoi(argv[++i]));
      } else if(streq(argv[i], "-TB_VERBOSE")) {
	TB_setVerbose(argc, TBtrue);
      }
	/* <PO>: TB_SINGLE / TB_LOCAL_PORTS not implemented (yet?) */
    }
  }
  return cid;
}

/*}}}  */

/*{{{  int TB_connect(int cid) */

int TB_connect(int cid)
{
  int r, dummy;
  term *trm, *in_sign, *out_sign;
  assert_valid_cid(cid);
  
  WellKnownSocketPort = connections[cid]->port;
  r = mkports(TBfalse, connections[cid]->tool_name, connections[cid]->host,
	     &connections[cid]->tid, &connections[cid]->socket, &dummy);
  if(r == TB_ERROR) {
    if(connections[cid]->verbose)
      TBmsg("TB_connect: failed to connect to ToolBus port %d\n",
	    connections[cid]->port);
    return -1;
  }

  if(connections[cid]->verbose)
    TBmsg("TB_connect: connected to ToolBus port %d, tid = %d\n",
	  connections[cid]->port, connections[cid]->tid);

  trm = TBread(connections[cid]->socket); /* obtain the tool signature from the ToolBus */

  if(TBmatch(trm, "rec-do(signature(%t,%t))", &in_sign, &out_sign)){
    TBwrite(connections[cid]->socket, TBmake("snd-void()"));
    if(connections[cid]->sigchecker){
      trm = (*connections[cid]->sigchecker)(cid, in_sign);
      if(trm)
	err_warn("TBconnect -- NOT IN INPUT SIGNATURE: %t", trm);
    }
  } else
    err_fatal("signature information garbled: %t", trm);
 
  return 0;
}

/*}}}  */

/*{{{  int TB_send(int cid, term *t) */

int TB_send(int cid, term *t)
{
  assert_valid_cid(cid);

  /* We might want error reporting from TBwrite (void now) */
  TBwrite(connections[cid]->socket, t);

  return 0;
}

/*}}}  */
/*{{{  term *TB_receive(int cid) */

term *TB_receive(int cid)
{
  assert_valid_cid(cid);

  return TBread(connections[cid]->socket);
}

/*}}}  */
/*{{{  int TB_peek_next() */

int TB_peek_next()
{
  fd_set set;
  static int rr = 0;
  int count = 0;

  FD_ZERO(&set);
  TB_setFds(&set);
  while(count == 0) {
    count = select(FD_SETSIZE, &set, NULL, NULL, NULL);
    if(count > 0) {
      do {
        rr++;
        if(rr >= MAX_CONNECTIONS)
	  rr = 0;
      } while(!connections[rr] || !FD_ISSET(connections[rr]->socket, &set));
      return rr;
    }
  }
  return -1;
}

/*}}}  */
/*{{{  int TB_peek(int cid) */

TBbool TB_peek(int cid)
{
  fd_set set;
  int count = 0;
  struct timeval t;

  assert_valid_cid(cid);
  FD_ZERO(&set);
  FD_SET(connections[cid]->socket, &set);
  t.tv_sec = 0;
  t.tv_usec = 0;

  count = select(FD_SETSIZE, &set, NULL, NULL, &t);
  if(count)
    return TBtrue;
  else
    return TBfalse;
}

/*}}}  */
/*{{{  int TB_handle_one(int cid) */

int TB_handle_one(int cid)
{
  term *trm, *result;
  TBbool sndvoid = TBfalse;

  assert_valid_cid(cid);

  trm = TB_receive(cid);
  if(!trm) {
    err_fatal("contact with ToolBus lost.\n");
  }
  if(streq(get_txt(fun_sym(trm)), "rec-do")) {
    sndvoid = TBtrue;
  }
  result = connections[cid]->handler(cid, trm);
  if(result) {
    return TB_send(cid, result);
  }
  else if(sndvoid) {
    return TB_send(cid, TBmake("snd-void()"));
  }

  err_fatal("Unhandled case in TB_handle_one!\n");
  return -1;
}

/*}}}  */
/*{{{  void TB_handle_any() */

int TB_handle_any()
{
  int cid = TB_peek_next();
  if(cid >= 0)
    return TB_handle_one(cid);

  return cid;
}

/*}}}  */

/*{{{  int TB_eventloop(void) */

int TB_eventloop(void)
{
  while(TBtrue) {
    if(TB_handle_any() < 0)
      return -1;
    TBcollect();
  }
}

/*}}}  */

/*{{{  int TB_setFds(fd_set *set) */

int TB_setFds(fd_set *set)
{
  int max_fd = -1;
  int i;

  for(i=0; i<MAX_CONNECTIONS; i++) {
    if(connections[i] && connections[i]->socket >= 0) {
      FD_SET(connections[i]->socket, set);
      if(connections[i]->socket > max_fd)
	max_fd = connections[i]->socket;
    }
  }
  return max_fd;
}

/*}}}  */
/*{{{  int TB_match(char *fmt, term *trm, ...) */

/* forward decl. of two recursive functions */
int list_match(term_list *l1, term_list *l2, va_list *args);
int term_match(term *trm, term *template, va_list *args);

/*{{{  int list_match(term_list *l1, term_list *l2, va_list *args) */

int list_match(term_list *l1, term_list *l2, va_list *args)
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

/*}}}  */
/*{{{  int term_match(term *trm, term *template, va_list *args) */

int term_match(term *trm, term *template, va_list *args)
{
  /* Here, we only perform a preorder search for placeholders */
  if(is_placeholder(template)) {
    int sym;
    term **t;
    TBbool *b;
    int *i;
    float *f;
    char **s;

    /*if(tkind(placeholder_type(template)) == t_appl) {
      fprintf(stderr, "template_type = %s\n", get_txt(fun_sym(
				       placeholder_type(template))));
    }
    */
    sym = fun_sym(placeholder_type(template));
    switch(sym) {
/*{{{  case type_term: */

      case type_list:
                   if(!is_list(trm))
		     return 0;
      case type_term:
                   t = (term **)va_arg(*args, term **);
                   if(t)
		     *t = trm;
                   return 1;

/*}}}  */
/*{{{  case type_bool: */

      case type_bool: 
                   if(!is_bool(trm))
                     return 0;
                   b = (TBbool *)va_arg(*args, TBbool *);
	           if(b)
                     *b = bool_val(trm);
                   return 1;

/*}}}  */
/*{{{  case type_int: */

      case type_int: 
                   if(!is_int(trm))
                     return 0;
                   i = (int *)va_arg(*args, int *);
	           if(i)
                     *i = int_val(trm);
                   return 1;

/*}}}  */
/*{{{  case type_real: */

      case type_real: if(!is_real(trm))
                     return 0;
                   f = (float *)va_arg(*args, float *);
	           if(f)
                     *f = real_val(trm);
                   return 1;

/*}}}  */
/*{{{  case type_str: */

      case type_str: if(!is_str(trm))
                     return 0;
                   s = (char **)va_arg(*args, char **);
	           if(s)
                     *s = strdup(str_val(trm));
                   return 1;

/*}}}  */
/*{{{  case type_bstr: */

      case type_bstr: if(!is_bstr(trm))
                     return 0;
                   s = (char **)va_arg(*args, char **);
                   i = (int *)va_arg(*args, int *);
                   if(s && i) {
                     *i = bstr_len(trm);
                     *s = malloc(*i);
                     if(!*s) {
                       *i = -1;
		       return -1;
                     }
                     memcpy(*s, bstr_val(trm), *i);
                   }
                   return 1;

/*}}}  */

/*{{{  default: */

      default:     if(streq(get_txt(sym), "appl")) {
                     if(!is_appl(trm))
		       return 0;
		     s = (char **)va_arg(*args, char **);
		     t = (term **)va_arg(*args, term **);
		     *s = strdup(get_txt(fun_sym(trm)));
		     *t = fun_args(trm);
		     return 1;
		   }

/*}}}  */
    }
    return 0;
  } else if(is_appl(template)) {
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

/*}}}  */

/* A new (improved?) TBmatch function! */
int TB_match(term *trm, char *fmt, ...)
{
  va_list args;
  term *template;
  int result;

  va_start(args, fmt);

  template = TBmake(fmt);
  result = term_match(trm, template, &args);

  va_end(args);
  return result;
}

/*}}}  */
/*{{{  term  *TB_make(char *fmt, term *trm, ...) */

static term *term_make(term *template, va_list *args);

/*{{{  TBbool valid_id() */

TBbool valid_id(char *id)
{
  if(!islower((int)id[0]))
    return TBfalse;

  while(*(++id)) {
    if(!isalpha((int)*id) && !isdigit((int)*id) && *id !=  '-' && *id != '_')
      return TBfalse;
  }
  return TBtrue;
}

/*}}}  */
/*{{{  term *list_make(term_list *l, va_list *args) */

static term *list_make(term_list *l, va_list *args)
{
  term_list *cur = l;

  while(cur) {
    first(cur) = term_make(first(cur), args);
    cur = next(cur);
  }
  return l;
}

/*}}}  */
/*{{{  term *term_make(term *template, va_list *args) */

static term *term_make(term *template, va_list *args)
{
  /* Here, we only perform a preorder search for placeholders */
  if(is_placeholder(template)) {
    int sym;
    term *t;
    TBbool b;
    int i;
    double r;
    char *s;

    /*if(tkind(placeholder_type(template)) == t_appl) {
      fprintf(stderr, "template_type = %s\n", get_txt(fun_sym(
				       placeholder_type(template))));
    }
    */
    sym = fun_sym(placeholder_type(template));
    switch(sym) {
/*{{{  case type_term: */

      case type_list:
      case type_term:
                   t = (term *)va_arg(*args, term *);
                   return t;

/*}}}  */
/*{{{  case type_bool: */

      case type_bool: 
                   b = (TBbool)va_arg(*args, TBbool);
	           return mk_bool(b);

/*}}}  */
/*{{{  case type_int: */

      case type_int: 
                   i = (int)va_arg(*args, int);
	           return mk_int(i);

/*}}}  */
/*{{{  case type_real: */

      case type_real:
                   r = (double)va_arg(*args, double);
	           return mk_real(r);

/*}}}  */
/*{{{  case type_str: */

      case type_str:
                   s = (char *)va_arg(*args, char *);
	           return mk_str(s);

/*}}}  */
/*{{{  case type_bstr: */

      case type_bstr:
                   s = (char *)va_arg(*args, char *);
                   i = (int)va_arg(*args, int);
		   return mk_bstr(s, i);

/*}}}  */

/*{{{  default: */

      default:     if(streq(get_txt(sym), "appl")) {
		     s = (char *)va_arg(*args, char *);
		     t = (term *)va_arg(*args, term *);

		     t = mk_appl(TBlookup(s), t);
		     
		     if(!valid_id(s))
		       fun_str_sym(t) = TBtrue;
		     return t;
		   }

/*}}}  */
    }
    assert(0);
  } else if(is_appl(template)) {
    fun_args(template) = list_make(fun_args(template), args);
    return template;
  } else if(is_list(template)) {
    return list_make(template, args);
  }
  return template;
}

/*}}}  */

/* A new (improved?) TBmake function! */
term *TB_make(char *fmt, ...)
{
  va_list args;
  term *template;
  term *result;

  va_start(args, fmt);

  template = TBmake(fmt);
  result = term_make(template, &args);

  va_end(args);
  return result;
}

/*}}}  */

/* Some access functions */
/*{{{  void TB_setTool(int cid, char *name) */

void TB_setTool(int cid, char *name)
{
  assert_valid_cid(cid);
  connections[cid]->tool_name = name;
}

/*}}}  */
/*{{{  char *TB_getTool(int cid) */

char *TB_getTool(int cid)
{
  assert_valid_cid(cid);
  return connections[cid]->tool_name;
}

/*}}}  */
/*{{{  void  TB_setHost(int cid, char *host) */

void  TB_setHost(int cid, char *host)
{
  assert_valid_cid(cid);
  connections[cid]->host = host;
}

/*}}}  */
/*{{{  char *TB_getHost(int cid) */

char *TB_getHost(int cid)
{
  assert_valid_cid(cid);
  return connections[cid]->host;
}

/*}}}  */
/*{{{  void TB_setPort(int cid, int port) */

void TB_setPort(int cid, int port)
{
  assert_valid_cid(cid);
  connections[cid]->port = port;
}

/*}}}  */
/*{{{  int TB_getPort(int cid) */

int TB_getPort(int cid)
{
  assert_valid_cid(cid);
  return connections[cid]->port;
}

/*}}}  */
/*{{{  void TB_setTid(int cid, int tid) */

void TB_setTid(int cid, int tid)
{
  assert_valid_cid(cid);
  connections[cid]->tid = tid;
}

/*}}}  */
/*{{{  int TB_getTid(int cid) */

int TB_getTid(int cid)
{
  assert_valid_cid(cid);
  return connections[cid]->tid;
}

/*}}}  */
/*{{{  void TB_setHandler(int cid, TBcallback handler) */

void TB_setHandler(int cid, TBcallback handler)
{
  assert_valid_cid(cid);
  connections[cid]->handler = handler;
}

/*}}}  */
/*{{{  TBcallback TB_getHandler(int cid) */

TBcallback TB_getHandler(int cid)
{
  assert_valid_cid(cid);
  return connections[cid]->handler;
}

/*}}}  */
/*{{{  int TB_setSigChecker(int cid, TBsigcheck sigcheck) */

void TB_setSigChecker(int cid, TBsigcheck sigcheck)
{
  assert_valid_cid(cid);
  connections[cid]->sigchecker = sigcheck;
}

/*}}}  */
/*{{{  TBsigcheck TB_getSigChecker(int cid) */

TBsigcheck TB_getSigChecker(int cid)
{
  assert_valid_cid(cid);
  return connections[cid]->sigchecker;
}

/*}}}  */
/*{{{  int TB_setVerbose(int cid, TBbool on) */

void TB_setVerbose(int cid, TBbool on)
{
  assert_valid_cid(cid);
  connections[cid]->verbose = on;
}

/*}}}  */
/*{{{  TBbool TB_getVerbose(int cid) */

TBbool TB_getVerbose(int cid)
{
  assert_valid_cid(cid);
  return connections[cid]->verbose;
}

/*}}}  */
/*{{{  TBbool TB_validConnection(int cid) */

TBbool TB_validConnection(int cid)
{
  if(cid < 0 || cid >= MAX_CONNECTIONS || !connections[cid])
    return TBfalse;
  return TBtrue;
}

/*}}}  */
/*{{{  TBint TB_getSocket(int cid) */

int TB_getSocket(int cid)
{
  assert_valid_cid(cid);
  return connections[cid]->socket;  
}

/*}}}  */
/*{{{  term_list *TB_getConnections() */

term_list *TB_getConnections()
{
  int i;
  term_list *l = NULL;
  char *host;

  for(i=0; i<MAX_CONNECTIONS; i++) {
    if(TB_validConnection(i) && TB_getSocket(i) >= 0) {
      host = TB_getHost(i);
      host = host ? host : "";
      assert(host);
      l = list_concat_term(l, TB_make("[<int>,<str>,<int>,<int>,<int>]",
        i,
        host,
        TB_getPort(i),
        TB_getTid(i),
        TB_getSocket(i)));
    }
  }
  return l;
}

/*}}}  */
