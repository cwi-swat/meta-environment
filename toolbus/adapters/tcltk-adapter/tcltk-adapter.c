#line 37 "tcltk-adapter.c.nw"
#include <TB.h>
#include <tcl.h>
#include <tk.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/types.h>
#line 51 "tcltk-adapter.c.nw"
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
#line 74 "tcltk-adapter.c.nw"
void pr_type_wish(type *tp);
void pr_term_list_wish(const term_list *tl, char sep);
void pr_env_wish(const env *e);
void pr_string_wish(char *s, int len);
static void print_term(term *t);
static void print_list(term_list* l, char* left, char* sep, char* right);
#line 110 "tcltk-adapter.c.nw"
void reset_buffer()
{
  offset = 0;
  BUF[0] = '\0';
}
#line 123 "tcltk-adapter.c.nw"
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
#line 163 "tcltk-adapter.c.nw"
void printb_char(char c)
{
  if(offset >= bufsize)
    TBprintf(stderr, "Buffer overflow, ignoring %c\n", c);
  else {
    BUF[offset++] = c;
    BUF[offset] = '\0';
  }
}
#line 144 "tcltk-adapter.c.nw"
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
#line 181 "tcltk-adapter.c.nw"
static void error( const char* msg )
{
   fprintf(stderr, "fatal error: %s\n", msg); 
   exit(1);
}
#line 195 "tcltk-adapter.c.nw"
static void wputc( int c )
{
   printb_char(c);
   #ifdef DEBUG_ON
      fputc( c, stderr );
   #endif
}
#line 211 "tcltk-adapter.c.nw"
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
#line 233 "tcltk-adapter.c.nw"
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
#line 267 "tcltk-adapter.c.nw"
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
#line 285 "tcltk-adapter.c.nw"
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
#line 315 "tcltk-adapter.c.nw"
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
#line 367 "tcltk-adapter.c.nw"
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
#line 387 "tcltk-adapter.c.nw"
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

#line 101 "tcltk-adapter.c.nw"
void pr_term_wish(term *t)
{
  print_term(t);
}

#line 409 "tcltk-adapter.c.nw"
term *TclString2Term(char *str)
{
  return TBmake(str);
}


#line 803 "tcltk-adapter.c.nw"
#include <tide.h>
#include "debug-adapter.tif.c"
#include <limits.h>
#line 812 "tcltk-adapter.c.nw"
TBbool use_tide = TBfalse;
TBbool trace_ports = TBfalse;
int tide_cid = -1;
Tcl_Interp *tide_interp = NULL;
Tcl_File tide_file = NULL;

#line 837 "tcltk-adapter.c.nw"
TBbool eval_eval_1(term_list *args, int pid, term **result, char **msg)
{
  char *expr;

  if(!TB_match(args, "[<str>]", &expr)) {
    *result = list_first(args);
    *msg = "eval takes one string argument";
    return TBfalse;
  }

  if(Tcl_Eval(tide_interp, expr) == TCL_OK) {
    *result = TB_make("<str>", tide_interp->result);
    return TBtrue;
  }

  *result = list_first(args);
  *msg = "error while evaluating expression";
  return TBfalse;
}

#line 830 "tcltk-adapter.c.nw"
func_entry func_table[] =
{ { "eval", 1, eval_eval_1, NULL, "evaluate an expression" },
  { NULL, 0, NULL, NULL, NULL }
};
#line 862 "tcltk-adapter.c.nw"
act_entry act_table[] =
{ { NULL, 0, NULL, NULL, NULL }
};
#line 871 "tcltk-adapter.c.nw"
char *information_table[] =
{ "search-paths", 		NULL,
  "observation-ports",		"[[on-halt,at,[]], [every-stat,before,[]]," \
				"[loc,before,[lc]],[exception,at,[]]]",
  "exec-control",		"[single-step, step-over, run, stop]",
  "actions",			NULL,
  "expressions",		NULL,
  NULL,				NULL
};

#line 889 "tcltk-adapter.c.nw"
int handle_tide_error(Tcl_Interp *interp, char *code, char *msg, char *info)
{
  if(use_tide) {
    dap_exception(0, "error", msg, info);
    dap_exec_control(0, ES_STOP, -1);
    return 1;
  }
  return 0;
}
#line 939 "tcltk-adapter.c.nw"
void tcl_tide_handler(ClientData data, int mask)
{
  if(TB_peek(tide_cid))
    TB_handle_one(tide_cid);
}
#line 950 "tcltk-adapter.c.nw"
void tide_event_loop()
{
  while(dap_exec_state(0) == ES_STOP || 
        dap_exec_state(0) == ES_HIGH_WATER) {
    TB_handle_one(tide_cid);
  }
}
#line 1009 "tcltk-adapter.c.nw"
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
    dap_check_observation_points(0, port);
    switch(dap_exec_state(0)) {
      case ES_STOP:		dap_stop_process(0);
				break;
      case ES_SINGLE_STEP:	dap_stop_process(0);
				break;
      case ES_RUN_UNTIL_PARENT:
      case ES_STEP_OVER:	Tcl_Eval(interp, "info level");
				level = atoi(interp->result);
				if(level <= dap_stop_level(0))
				  dap_stop_process(0);
				break;
    }
    tide_event_loop();
  }

  if(strlen(argv[2]) != 0) {
    fprintf(stderr, "executing: %s\n", argv[2]);
    return Tcl_Eval(interp, argv[2]);
  }
}

#line 906 "tcltk-adapter.c.nw"
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
#line 966 "tcltk-adapter.c.nw"
int Tide_Init(Tcl_Interp *interp)
{
  tide_interp = interp;

  Tcl_CreateCommand(interp, "TBtide", Tcl_TBtide, NULL, NULL);

  if(use_tide) {
    TB_connect(tide_cid);
    tide_file = Tcl_GetFile((ClientData)TB_getSocket(tide_cid), TCL_UNIX_FD);
    Tcl_CreateFileHandler(tide_file, TCL_READABLE, tcl_tide_handler, NULL);
  }
  dap_init(tide_cid, func_table, act_table);

  if(use_tide || trace_ports) {
    if(Tcl_EvalFile(interp, LIBDIR "/tide.tcl") != TCL_OK) {
      interp->result = "cannot open file " LIBDIR "/tide.tcl";
      return TCL_ERROR;
    }
  }

  if(use_tide) {
    if(script)
      dap_create_process(0, script, ES_STOP);
    else {
      char buf[32];
      sprintf(buf, "wish-%d", getpid());
      dap_create_process(0, buf, ES_STOP);
    }
  }
  dap_set_observation_point(tide_cid, TB_make("all"), 
	TB_make("[on-halt,at,\"\"]"), TB_make("always"), TB_make("[watch(cpe)]"));

  return TCL_OK;
}

#line 1055 "tcltk-adapter.c.nw"
void continue_process(int pid)
{
}
#line 1064 "tcltk-adapter.c.nw"
void stop_process(int pid)
{
}
#line 1074 "tcltk-adapter.c.nw"
term *supply_info(int cid, char *key)
{
  fprintf(stderr, "supply_info: %s\n", key);
  if(streq(key, "search-paths")) {
    static char path[_POSIX_PATH_MAX];
    getcwd(path, _POSIX_PATH_MAX);

    return TB_make("[[config, [<str>]], [source, [<str>]]]", path, path);
  }

  return NULL;
}

#line 1093 "tcltk-adapter.c.nw"
term *get_info(int cid)
{
  return dap_get_info(cid);
}
#line 1105 "tcltk-adapter.c.nw"
term *set_observation_point(int cid, term *pids, term *port, term *cond, term_list *acts)
{
  return dap_set_observation_point(cid, pids, port, cond, acts);
}
#line 1117 "tcltk-adapter.c.nw"
void clear_observation_point(int cid, term *pids, int oid)
{
  dap_clear_observation_point(cid, pids, oid);
}

#line 1129 "tcltk-adapter.c.nw"
void exec_control(int cid, term *pids, term *mode)
{
  int level, es = dap_term2es(mode);

  Tcl_Eval(tide_interp, "info level");
  level = atoi(tide_interp->result);
  dap_exec_control(0, es, level);
}
#line 1145 "tcltk-adapter.c.nw"
term *execute_actions(int cid, term *pids, term_list *actions)
{
  return TB_make("snd-value(execute-actions(<term>,<term>,error(<str>)))",
			pids, actions, "not implemented yet");
}

#line 1159 "tcltk-adapter.c.nw"
void rec_ack_event(int cid, term *event)
{
  dap_rec_ack_event(cid, event);
}
#line 1171 "tcltk-adapter.c.nw"
void rec_terminate(int cid, term *arg)
{
  dap_rec_terminate(cid, arg);
}

#line 712 "tcltk-adapter.c.nw"
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
#line 731 "tcltk-adapter.c.nw"
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

#line 421 "tcltk-adapter.c.nw"
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
#line 439 "tcltk-adapter.c.nw"
void tcl_toolbus_handler(ClientData data, int mask)
{
  if(TB_peek(cid))
    TB_handle_one(cid);
}
#line 451 "tcltk-adapter.c.nw"
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
    TBprintf(stderr, "returning result of function %s: %l\n", fname, fargs);
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
#line 532 "tcltk-adapter.c.nw"
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
#line 556 "tcltk-adapter.c.nw"
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
#line 593 "tcltk-adapter.c.nw"
int Tcl_bgerror(ClientData data, Tcl_Interp *interp, int argc, char *argv[])
{
  handle_error(interp, argv[1]);
  return TCL_OK;
}
#line 639 "tcltk-adapter.c.nw"
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
#line 608 "tcltk-adapter.c.nw"
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
}
#line 672 "tcltk-adapter.c.nw"
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
#line 752 "tcltk-adapter.c.nw"
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
