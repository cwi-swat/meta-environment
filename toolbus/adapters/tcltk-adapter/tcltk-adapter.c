#line 39 "tcltk-adapter.c.nw"
#include <TB.h>
#include <tcl.h>
#include <tk.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/types.h>
#line 53 "tcltk-adapter.c.nw"
/* 20 Kb should suffice for most applications. */
#define DEFAULT_BUF_SIZE	20480

char *script;
char *name;

Tcl_Interp *global_interp;

int bufsize = DEFAULT_BUF_SIZE;
char *BUF;
int offset;

TBbool use_toolbus = TBfalse;
int cid;
Tcl_File toolbus_file;
#line 76 "tcltk-adapter.c.nw"
void pr_type_wish(type *tp);
void pr_term_list_wish(const term_list *tl, char sep);
void pr_env_wish(const env *e);
void pr_string_wish(char *s, int len);
static void print_term(term *t);
static void print_list(term_list* l, char* left, char* sep, char* right);
#line 112 "tcltk-adapter.c.nw"
void reset_buffer()
{
  offset = 0;
  BUF[0] = '\0';
}
#line 125 "tcltk-adapter.c.nw"
char *wish_type_string(tkind kind)
{
  static char *types[] =
    { "term", "bool", "int", "real", "str", "bstr", "var",
      "placeholder", "appl", "env", "list"
    };

  if(kind >= t_term && kind <= t_list)
    return types[kind];

  return "unknown";
}
#line 165 "tcltk-adapter.c.nw"
void printb_char(char c)
{
  if(offset >= bufsize)
    TBprintf(stderr, "Buffer overflow, ignoring %c\n", c);
  else {
    BUF[offset++] = c;
    BUF[offset] = '\0';
  }
}
#line 146 "tcltk-adapter.c.nw"
void printb_str(char *str)
{
  int len = strlen(str);

  if(offset + len > bufsize)
    TBprintf(stderr, "Buffer overflow, ignoring %s\n", str);
  else {
    strcpy(&BUF[offset], str);
    offset += len;
    BUF[offset] = '\0';
  }
}
#line 183 "tcltk-adapter.c.nw"
static void error( const char* msg )
{
   fprintf(stderr, "fatal error: %s\n", msg); 
   exit(1);
}
#line 197 "tcltk-adapter.c.nw"
static void wputc( int c )
{
   printb_char(c);
   #ifdef DEBUG_ON
      fputc( c, stderr );
   #endif
}
#line 213 "tcltk-adapter.c.nw"
static void wprintf(char* fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);
  vsprintf(&BUF[offset], fmt, ap);
  offset += strlen(&BUF[offset]);
  #ifdef DEBUG_ON
    vfprintf(stderr, fmt, ap);
  #endif
  va_end(ap);
}
#line 235 "tcltk-adapter.c.nw"
static void print_string(char* s, int n)
{
  wputc('"');
  while(n--)
  {
    if(isprint(*s)) {
      switch (*s) {
	case '\\':
	case '"':
	case '{':
	case '}':
	case '[':
	case ']':
/*	case ' ':*/
	case ';':
	case '$':	wputc('\\');
	default:	wputc(*s);
      }
    } else {
	wputc(*s);
/*      wprintf("\\%03o", (unsigned int)*s);*/
    }
    s++;
  }
  wputc('"');
}
#line 269 "tcltk-adapter.c.nw"
static void print_var(term* e)
{
   char* txt;
   txt = get_txt(var_sym(e));
   print_string(txt, strlen(txt));
   wputc(':');
   print_term(var_type(e));
   if(var_result(e))
     wputc('?');
}
#line 287 "tcltk-adapter.c.nw"
static void print_env(env* e)
{
   TBbool first = TBtrue;
   char* txt;
   
   wputc('"');
   while(e != NULL)
   {
      assert(is_env(e));
      if(first)
        first = TBfalse;
      else
	wputc(' ');
      txt = get_txt(env_sym(e));
      print_string(txt, strlen(txt));
      wputc(' ');
      print_term(env_val(e));
      e = env_next(e);
   }
   wputc('"');
}
#line 317 "tcltk-adapter.c.nw"
static void print_term(term* t)
{
   switch(tkind(t))
   {
      case t_str:
         print_string(str_val(t), strlen(str_val(t)));
         break;
      case t_bstr:
         print_string(bstr_val(t), bstr_len(t));
         break;
      case t_bool:
         if(bool_val(t) == TBtrue) {
            wprintf("true");
         } else {
            wprintf("false");
         }
         break;
      case t_int:
         wprintf("%d", int_val(t));
         break;
      case t_real:
         wprintf("%f", real_val(t));
         break;
      case t_var:
         print_var(t);
         break;
      case t_placeholder:
         wputc('<');
         print_term(placeholder_type(t));
         wputc('>');
         break;
      case t_appl:
         wprintf("%s", get_txt(fun_sym(t)));
         if(fun_args(t) != NULL)
            print_list(fun_args(t), "(", ",", ")");
         break;
      case t_list:
         print_list(t, "{", " ", "}");
         break;
      case t_env:
         print_env(t);
         break;
   }
}
#line 369 "tcltk-adapter.c.nw"
static void print_list(term_list* l, char* left, char* sep, char* right)
{
   int i;
   wprintf(left);
   for(i=1; i<=list_length(l); i++) {
      if(i>1) {
         wprintf(sep);
      }
      print_term(list_index(l, i));
   }
   wprintf(right);
}
#line 389 "tcltk-adapter.c.nw"
static void print_args(term_list *args)
{
  while(args) {
    if(!is_list(list_first(args)))
      wprintf("{");
    print_term(list_first(args));
    if(!is_list(list_first(args)))
      wprintf("}");
    wputc(' ');
    args = list_next(args);
  }
}

#line 103 "tcltk-adapter.c.nw"
void pr_term_wish(term *t)
{
  print_term(t);
}

#line 411 "tcltk-adapter.c.nw"
term *TclString2Term(char *str)
{
  return TBmake(str);
}


#line 13 "tcltk-adapter.c.nw"
#ifdef USE_TIDE
#line 806 "tcltk-adapter.c.nw"
#include <dap.h>
#include "debug-adapter.tif.c"
#include <limits.h>
#line 815 "tcltk-adapter.c.nw"
TBbool use_tide = TBfalse;
TBbool trace_ports = TBfalse;
int tide_cid = -1;
Tcl_Interp *tide_interp = NULL;
Tcl_File tide_file = NULL;

#line 844 "tcltk-adapter.c.nw"
TBbool eval_call_signs(term_list *args, int pid, term **result, char **msg)
{
  *result = TB_make("[call-sign(toolbus(<int>),<appl>)]", TB_getPort(cid),
		TB_getTool(cid), mk_list1(mk_int(TB_getTid(cid))));
  return TBtrue;  
}
#line 853 "tcltk-adapter.c.nw"
TBbool eval_eval_1(term_list *args, int pid, term **result, char **msg)
{
  char *expr;

  if(!TB_match(args, "[<str>]", &expr)) {
    *result = list_first(args);
    *msg = "eval takes one string argument";
    return TBfalse;
  }

  Tcl_Eval(tide_interp, expr);
  *result = TB_make("<str>", tide_interp->result);
  Tcl_ResetResult(tide_interp);
  return TBtrue;
}
#line 871 "tcltk-adapter.c.nw"
TBbool eval_var_1(term_list *args, int pid, term **result, char **msg)
{
  char *var;
  char expr[64];

  if(!TB_match(args, "[<str>]", &var)) {
    *result = list_first(args);
    *msg = "var takes one string argument";
    return TBfalse;
  }

  strcpy(expr, "set ");
  strncat(expr, var, 58);

  Tcl_Eval(tide_interp, expr);
  *result = TB_make("<str>", tide_interp->result);
  Tcl_ResetResult(tide_interp);
  return TBtrue;
}

#line 835 "tcltk-adapter.c.nw"
func_entry func_table[] =
{ { "call-signs", 0, eval_call_signs, NULL, "retrieve the call-signs of a process" },
  { "eval", 1, eval_eval_1, NULL, "evaluate an expression" },
  { "var", 1, eval_var_1, NULL, "return the value of a variable" },
  { NULL, 0, NULL, NULL, NULL }
};
#line 896 "tcltk-adapter.c.nw"
act_entry act_table[] =
{ { NULL, 0, NULL, NULL, NULL }
};
#line 905 "tcltk-adapter.c.nw"
char *information_table[] =
{ "name",		NULL,
  "type",		"\"Tcl/Tk\"",
  "search-paths", 	NULL,
  "ports",		"[[exec-state,at], [always,before], [always,after]," \
			"[location,before], [location,after]," \
			"[exception,at]]",
  "exec-control",	"[single-step, step-over, run, stop]",
  "actions",		NULL,
  "expressions",	NULL,
  "connections",	NULL,
  NULL,			NULL
};

#line 927 "tcltk-adapter.c.nw"
int handle_tide_error(Tcl_Interp *interp, char *code, char *msg, char *info)
{
  if(use_tide) {
    dap_activate_rules(0, TB_make("[exception,at,error,<str>,<str>]", msg, info));
    /*return 1; For now, we also want to print the error. */
  }
  return 0;
}
#line 976 "tcltk-adapter.c.nw"
void tcl_tide_handler(ClientData data, int mask)
{
  if(TB_peek(tide_cid))
    TB_handle_one(tide_cid);
}
#line 987 "tcltk-adapter.c.nw"
void tide_event_loop()
{
  while(use_tide && (dap_get_exec_state(0, 0) == ES_STOP || 
        dap_get_exec_state(0, 0) == ES_HIGH_WATER)) {
    TB_handle_one(tide_cid);
  }
}
#line 1134 "tcltk-adapter.c.nw"
int Tcl_TBtide(ClientData data, Tcl_Interp *interp, int argc, char *argv[])
{
  term *port;
  int i, level;

  if(argc != 3) {
    interp->result = "TBtide expects 3 arguments";
    return TCL_ERROR;
  }

  port = TBmake(argv[1]);

  if(trace_ports)
    TBprintf(stdout, "port: %t\n", port);

  if(use_tide) {
    dap_activate_rules(0, port);

    switch(dap_get_exec_state(0, 0)) {
      case ES_STOP:		
      case ES_SINGLE_STEP:	dap_change_exec_state(0, ES_STOP);
				break;
      case ES_RUN_UNTIL_PARENT:
      case ES_STEP_OVER:	Tcl_Eval(interp, "info level");
				level = atoi(interp->result);
				if(level <= dap_get_stop_level(0, 0))
				  dap_change_exec_state(0, ES_STOP);
				break;
    }
    tide_event_loop();
  }

  if(strlen(argv[2]) != 0) {
    return Tcl_Eval(interp, argv[2]);
  }
}

#line 1044 "tcltk-adapter.c.nw"
void cbdap_process_created(int dapid, int pid)
{
}
#line 1055 "tcltk-adapter.c.nw"
void cbdap_process_destroyed(int dapid, int pid)
{
}
#line 1068 "tcltk-adapter.c.nw"
void cbdap_change_exec_state(int pid, int exec_state)
{
}
#line 1079 "tcltk-adapter.c.nw"
term *cbdap_supply_info(char *key)
{
  static char buf[_POSIX_PATH_MAX];

  
#line 1096 "tcltk-adapter.c.nw"
  if(streq(key, "name")) {
    int tid = TB_getTid(tide_cid);
    if(use_toolbus)
      sprintf(buf, "%s-%d(%d)", TB_getTool(cid), tid, TB_getTid(cid));
    else
      sprintf(buf, "%s-%d", script ? script : "wish", tide_cid);
    return TB_make("<str>", buf);
  }
#line 1084 "tcltk-adapter.c.nw"
  
#line 1109 "tcltk-adapter.c.nw"
  if(streq(key, "search-paths")) {
    getcwd(buf, _POSIX_PATH_MAX);

    return TB_make("[[config, [<str>]], [source, [<str>]]]", buf, buf);
  }
#line 1085 "tcltk-adapter.c.nw"
  
#line 1117 "tcltk-adapter.c.nw"
  if(streq(key, "connections")) {
    if(use_toolbus) {
      sprintf(buf, "toolbus-%d", TB_getPort(cid));
      return TB_make("[<str>]", buf);
    }
    /* No connections, return the empty list. */
    return NULL;
  }

#line 1087 "tcltk-adapter.c.nw"
  return NULL;
}

#line 943 "tcltk-adapter.c.nw"
void handle_tide_args(int argc, char *argv[])
{
  int i, port = 9500;
  char *host = NULL; 

  for(i=1; i<argc; i++) {
    if(streq(argv[i], "-tide"))
      use_tide = TBtrue;
    if(streq(argv[i], "-porttrace"))
      trace_ports = TBtrue;
    if(streq(argv[i], "-TB_TIDE_PORT")) {
      port = atoi(argv[++i]);
      use_tide = TBtrue;
    }
    if(streq(argv[i], "-TB_TIDE_HOST")) {
      host = argv[++i];
      use_tide = TBtrue;
    }
  }

  if(use_tide) {
    tide_cid = TB_newConnection("debug-adapter", host, port, 
			debug_adapter_handler, debug_adapter_check_in_sign);
  }
}
#line 1002 "tcltk-adapter.c.nw"
int Tide_Init(Tcl_Interp *interp)
{
  tide_interp = interp;

  Tcl_CreateCommand(interp, "TBtide", Tcl_TBtide, NULL, NULL);

  if(use_tide || trace_ports) {
    if(Tcl_EvalFile(interp, LIBDIR "/tide.tcl") != TCL_OK) {
      /*interp->result = "cannot open file " LIBDIR "/tide.tcl";*/
      Tcl_AddErrorInfo(interp, "while loading file " LIBDIR "/tide.tcl\n");
      return TCL_ERROR;
    }
  }

  if(use_tide) {
    TB_connect(tide_cid);
    tide_file = Tcl_GetFile((ClientData)TB_getSocket(tide_cid), TCL_UNIX_FD);
    Tcl_CreateFileHandler(tide_file, TCL_READABLE, tcl_tide_handler, NULL);
  }

  if(use_tide) {
    dap_init(tide_cid, information_table, func_table, act_table);
    if(script)
      dap_process_created(0, 0, script, ES_STOP);
    else {
      char buf[32];
      sprintf(buf, "wish-%d", getpid());
      dap_process_created(0, 0, buf, ES_STOP);
    }
  }

  return TCL_OK;
}

#line 1177 "tcltk-adapter.c.nw"
term *get_info(int cid)
{
  return TB_make("snd-value(info(<list>))", dap_get_info(cid));
}
#line 1189 "tcltk-adapter.c.nw"
term *get_processes(int mycid)
{
  int i;
  term_list *procs = NULL;

  for(i=0; i<MAX_PROCESSES; i++) {
    process *p = dap_get_process(0, i);
    if(p) {
      term_list *callsigns = NULL;

      if(use_toolbus) {
        callsigns=TB_make("[callsign(toolbus(<int>),<appl>)]",TB_getPort(cid),
		 TB_getTool(cid), mk_list1(mk_int(TB_getTid(cid))));
      }
      procs = list_concat_term(procs, TB_make("[<int>,<str>,<list>]", 
						i, p->name, callsigns));
    }
  }
  return TB_make("snd-value(processes(<term>))", procs);
}
#line 1217 "tcltk-adapter.c.nw"
term *exec_actions(int cid, term *procs, term *acts)
{
  char *msg;
  term *result;

  TBbool ok = dap_exec(procs, acts, &result, &msg);
  if(ok)
    return TB_make("snd-value(exec-result(ok(<term>)))", result);

  return TB_make("snd-value(exec-result(error(<str>)))", msg);
}
#line 1236 "tcltk-adapter.c.nw"
term *create_rule(int cid, term *procs, term *port, term *cond, term *acts, term *life)
{
  int rid = dap_create_rule(procs, port, cond, acts, life);
  return TB_make(
	"snd-value(create-rule(<term>,<term>,<term>,<term>,<term>,<int>))",
	procs, port, cond, acts, life, rid);
}
#line 1251 "tcltk-adapter.c.nw"
void modify_rule(int cid, int rid, term *procs, term *port, 
				term *cond, term *acts, term *life)
{
  dap_rule_modified(0, rid, procs, port, cond, acts, life);
}
#line 1264 "tcltk-adapter.c.nw"
void destroy_rule(int cid, term *procs, int rid)
{
  dap_destroy_rule(rid);
}
#line 1277 "tcltk-adapter.c.nw"
void rec_ack_event(int cid, term *event)
{
  dap_rec_ack_event(cid, event);
}
#line 1289 "tcltk-adapter.c.nw"
void rec_terminate(int cid, term *arg)
{
  dap_rec_terminate(cid, arg);
  use_tide = TBfalse;
}
#line 15 "tcltk-adapter.c.nw"
#endif

#line 715 "tcltk-adapter.c.nw"
static void signal_handler(int sig)
{
#ifdef USE_TIDE
  if(use_tide)
    TB_send(tide_cid, TB_make("snd-disconnect"));
#endif
  if(use_toolbus)
    TB_send(cid, TB_make("snd-disconnect"));

  exit(1);
}
#line 734 "tcltk-adapter.c.nw"
static void signals_set()
{
   struct sigaction act;

   act.sa_handler = signal_handler;
   act.sa_flags   = SA_RESTART;

   sigemptyset( &act.sa_mask );

   sigaction( SIGINT,  &act, NULL );
   sigaction( SIGTERM, &act, NULL );
   sigaction( SIGHUP,  &act, NULL );
   sigaction( SIGQUIT, &act, NULL );
/*   sigaction( SIGCHLD, &act, NULL );*/
}

#line 423 "tcltk-adapter.c.nw"
void handle_error(Tcl_Interp *interp, char *msg)
{
  char *info = Tcl_GetVar(interp, "errorInfo", TCL_GLOBAL_ONLY);
  char *code = Tcl_GetVar(interp, "errorCode", TCL_GLOBAL_ONLY);

#ifdef USE_TIDE
  if(handle_tide_error(interp, code, msg, info))
    return;
#endif

  fprintf(stderr, "error in Tcl script: %s\n%s\n", msg, info);
}
#line 441 "tcltk-adapter.c.nw"
void tcl_toolbus_handler(ClientData data, int mask)
{
  if(TB_peek(cid))
    TB_handle_one(cid);
}
#line 453 "tcltk-adapter.c.nw"
term *from_toolbus(int cid, term *t) 
{
  char *fname;
  term *farg, *fargs, *event, *msg;
  int i, pid1, pid2;
  term *Env, *Subs, *Notes, *AtArgs, *Coords;
  char *AtFun;
  term *pe;
  char *mon_point;
 
  reset_buffer();
  if(TBmatch(t, "rec-do(%f(%l))", &fname, &fargs)) {
    printb_str(fname);
    printb_char(' ');
    if(fargs)
      print_args(fargs);
    
    /*TBprintf(stderr, "calling function %s.\n", BUF);*/
    if(Tcl_Eval(global_interp, BUF) != TCL_OK) {
      handle_error(global_interp, global_interp->result);
    }

    return NULL;
  }
  
  if(TBmatch(t, "rec-eval(%f(%l))", &fname, &fargs)) {
    printb_str(fname);
    printb_char(' ');
    if(fargs)
      print_args(fargs);

    if(Tcl_Eval(global_interp, BUF) != TCL_OK) {
      handle_error(global_interp, global_interp->result);
    }

    if(global_interp->result)
      return TclString2Term(global_interp->result);

    return NULL;
  }

  if(TBmatch(t, "rec-ack-event(%t)", &event)) {
    printb_str("rec-ack-event {");
    print_term(event);
    printb_str("}");
    /*TBprintf(stderr, "calling function %s\n", BUF);*/
    if(Tcl_Eval(global_interp, BUF) != TCL_OK) {
      handle_error(global_interp, global_interp->result);
    }

    return NULL;
  }

  if(TBmatch(t, "rec-monitor(%f(%d,%f,%t,%t,%t,%t,%t,%d,%t))",
	&mon_point, &pid1, &AtFun, &AtArgs, &Coords, 
	&Env, &Subs, &Notes, &pid2, &pe)) {
    TBmsg("Monitor commands not implemented yet: %t\n", t);
    return NULL;
  }

  if(TBmatch(t, "rec-terminate(%t)", &msg)) {
    printb_str("rec-terminate ");
    pr_term_wish(msg);
    if(Tcl_Eval(global_interp, BUF) != TCL_OK) {
      handle_error(global_interp, global_interp->result);
    }

    TBexit(0);
  }

  TBmsg("Ignored: %t\n", t);
  return NULL;
}
#line 533 "tcltk-adapter.c.nw"
int Tcl_TBsend(ClientData data, Tcl_Interp *interp, int argc, char *argv[])
{
  term *t;

  if(argc != 2) {
    interp->result = "Usage: TBsend ?term?";
    return TCL_ERROR;
  }

  t = TclString2Term(argv[1]);

  if(use_toolbus)
    TB_send(cid, t);
  else
    TBprintf(stdout, "TB_send: %t\n", t);

  return TCL_OK;
}
#line 557 "tcltk-adapter.c.nw"
int Tcl_TBstring(ClientData data, Tcl_Interp *interp, int argc, char *argv[])
{
  char *buf,*src,*dest,size;

  if(argc != 2) {
    interp->result = "Usage: TBstring ?string?";
    return TCL_ERROR;
  }

  src = argv[1];
  size = strlen(src)+3;
  while(*src) {
    if(*src == '"')
      size++;
    src++;
  }
  buf = malloc(size);
  src = argv[1];
  buf[0] = '"';
  dest = buf+1;
  while(*src) {
    if(*src == '"')
      *dest++ = '\\';
    *dest++ = *src++;
  }
  *dest++ = '"';
  *dest = '\0';
  
  Tcl_SetResult(interp, buf, TCL_DYNAMIC);
  return TCL_OK;
}
#line 594 "tcltk-adapter.c.nw"
int Tcl_bgerror(ClientData data, Tcl_Interp *interp, int argc, char *argv[])
{
  handle_error(interp, argv[1]);
  return TCL_OK;
}
#line 642 "tcltk-adapter.c.nw"
int Tcl_AppInit(Tcl_Interp *interp)
{
  if(Tcl_Init(interp) == TCL_ERROR)
    return TCL_ERROR;

  if(Tk_Init(interp) == TCL_ERROR)
    return TCL_ERROR;

  if(TB_Init(interp) == TCL_ERROR)
    return TCL_ERROR;

#ifdef USE_TIDE
  if(Tide_Init(interp) == TCL_ERROR)
    return TCL_ERROR;
#endif

  if(script) {
    if(Tcl_EvalFile(interp, script) != TCL_OK) {
      handle_error(interp, interp->result);
    }
  }

  return TCL_OK;
}
#line 609 "tcltk-adapter.c.nw"
int TB_Init(Tcl_Interp *interp)
{
  global_interp = interp;
  BUF = malloc(bufsize);
  if(!BUF) {
    TBprintf(stderr, "Not enough space to allocate text buffer!\n");
    TBexit(1);
  }

  Tcl_CreateCommand(interp, "TBsend", Tcl_TBsend, (ClientData)NULL, (Tcl_CmdDeleteProc *)NULL);
  Tcl_CreateCommand(interp, "TBstring", Tcl_TBstring, NULL, NULL);
  Tcl_CreateCommand(interp, "bgerror", Tcl_bgerror, NULL, NULL);

  if(use_toolbus) {
    TB_connect(cid);
    toolbus_file = Tcl_GetFile((ClientData)TB_getSocket(cid), TCL_UNIX_FD);
    Tcl_CreateFileHandler(toolbus_file, TCL_READABLE, tcl_toolbus_handler, NULL);
  }

  if(Tcl_EvalFile(interp, LIBDIR "/tcltk.tcl") != TCL_OK) {
    interp->result = "Cannot load file " LIBDIR "/tcltk.tcl";
    return TCL_ERROR;
  }

  Tcl_SetVar(interp, "TB_LIBDIR", LIBDIR, TCL_GLOBAL_ONLY);
}
#line 675 "tcltk-adapter.c.nw"
void handle_args(int argc, char *argv[])
{
  int i;

  TB_init();
  for(i=0; argv[i]; i++) {
    if(streq(argv[i], "-script")) {
      script = argv[++i];
      continue;
    }
    if(streq(argv[i], "-name")) {
      name = argv[++i];
      continue;
    }
    if(streq(argv[i], "-bufsize")) {
      bufsize = atoi(argv[++i]);
      if(bufsize <= 0) {
        TBprintf(stderr, "warning: illegal buffer size %d\n", bufsize);
        bufsize = DEFAULT_BUF_SIZE;
      }
    }
    if(streq(argv[i], "-TB_TOOL_NAME")) {
      use_toolbus = TBtrue;
    }
  }
  if(!name)
    name = script;

  if(!name)
    name = "noname";

  if(use_toolbus)
    cid = TB_parseArgs(argc, argv, from_toolbus, NULL);
}
#line 755 "tcltk-adapter.c.nw"
int main(int argc, char *argv[])
{
  Tk_Window main_win;
  int i, error;

  TB_init();
  handle_args(argc, argv);
#ifdef USE_TIDE
  handle_tide_args(argc, argv);
#endif
  signals_set();

  Tk_Main(argc, argv, Tcl_AppInit);
  return 0;	/* Prevent compiler warning */
}
