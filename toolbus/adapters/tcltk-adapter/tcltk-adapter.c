
/*{{{  includes */

#include <ctype.h>
#include <aterm2.h>
#include <atb-tool.h>
#include <tcl.h>
#include <tk.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/types.h>
#include <stdlib.h>

#include "tcltk-tide.h"

/*}}}  */
/*{{{  defines */

/* 20 Kb should suffice for most applications. */
#define DEFAULT_BUF_SIZE	20480

/*}}}  */
/*{{{  variables */

char *script = NULL;
char *name = NULL;

Tcl_Interp *global_interp;

int bufsize = DEFAULT_BUF_SIZE;
char *BUF;
int offset;

ATbool use_toolbus = ATfalse;
int cid;
/*Tcl_File toolbus_file;*/

/*}}}  */
/*{{{  predeclarations */

static void term2buf(ATerm t);
static int TB_Init(Tcl_Interp *interp);

/*}}}  */

/*{{{  static void reset_buffer() */

static void reset_buffer()
{
  offset = 0;
  BUF[0] = '\0';
}

/*}}}  */
/*{{{  static void char2buf(char c) */

static void char2buf(char c)
{
  if(offset >= bufsize)
    ATfprintf(stderr, "Buffer overflow, ignoring %c\n", c);
  else {
    BUF[offset++] = c;
    BUF[offset] = '\0';
  }
}

/*}}}  */
/*{{{  static void str2buf(char *str) */

static void str2buf(char *str)
{
  int len = strlen(str);

  if(offset + len > bufsize)
    ATfprintf(stderr, "Buffer overflow, ignoring %s\n", str);
  else {
    strcpy(&BUF[offset], str);
    offset += len;
    BUF[offset] = '\0';
  }
}

/*}}}  */
/*{{{  static void wprintf(char* fmt, ...) */

static void wprintf(char* fmt, ...)
{
  va_list ap;
  va_start(ap, fmt);
  vsprintf(&BUF[offset], fmt, ap);
  offset += strlen(&BUF[offset]);
  va_end(ap);
}

/*}}}  */
/*{{{  static void qstr2buf(char* s) */

static void qstr2buf(char* s)
{
	int n = strlen(s);
  char2buf('"');
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
				case ';':
				case '$':	char2buf('\\'); 		/* Fall-through intended */
				default:	char2buf(*s);
      }
    } else {
			char2buf(*s);
    }
    s++;
  }
  char2buf('"');
}

/*}}}  */

/*{{{  static void args2buf(ATermList args) */

static void args2buf(ATermList args)
{
  while(!ATisEmpty(args)) {
		ATerm arg = ATgetFirst(args);
		args = ATgetNext(args);
		if(ATgetType(arg) != AT_LIST)
			char2buf('{');
		term2buf(arg);
		if(ATgetType(arg) != AT_LIST)
			char2buf('}');
    char2buf(' ');
  }
}

/*}}}  */
/*{{{  static void term2buf(ATerm t) */

static void term2buf(ATerm t)
{
	ATerm annos = AT_getAnnotations(t);
	if(annos != NULL) {
		char2buf('{');
	}

	switch(ATgetType(t)) {
		case AT_INT:
			wprintf("%d", ATgetInt((ATermInt)t));
			break;
		case AT_REAL:
			wprintf("%f", ATgetReal((ATermReal)t));
			break;
		case AT_APPL:
			{
				int cur_arg, arity;
				ATermAppl appl = (ATermAppl)t;
				AFun sym = ATgetSymbol(appl);
				
				if(ATisQuoted(sym))
					qstr2buf(ATgetName(sym));
				else
					str2buf(ATgetName(sym));

				arity = ATgetArity(sym);
				if(arity > 0) {
					char2buf('(');

					for(cur_arg=0; cur_arg<arity; cur_arg++) {
						term2buf(ATgetArgument(appl, cur_arg));
						if(cur_arg < (arity-1))
							char2buf(',');
					}
					char2buf(')');
				}
			}
			break;
		case AT_LIST:
			{
				ATermList l = (ATermList)t;
				char2buf('{');
				while(!ATisEmpty(l)) {
					ATerm el = ATgetFirst(l);
					l = ATgetNext(l);
					term2buf(el);
					if(!ATisEmpty(l))
						char2buf(' ');
				}
				char2buf('}');
			}
			break;

		case AT_PLACEHOLDER:
			{
				char2buf('<');
				term2buf(ATgetPlaceholder((ATermPlaceholder)t));
				char2buf('>');
			}
			break;

		case AT_BLOB:
			ATerror("blobs are not supported by tcltk-adapter!\n");

		default:
			ATabort("illegal term type!\n");
	}

	if(annos != NULL) {
		char2buf(' ');
		term2buf(annos);
		char2buf('}');
	}
}

/*}}}  */

/*{{{  ATerm TclString2Term(char *str) */

ATerm TclString2Term(char *str)
{
  return ATparse(str);
}

/*}}}  */
/*{{{  static void signal_handler(int sig) */

static void signal_handler(int sig)
{
#ifdef USE_TIDE
  if(use_tide)
    ATBwriteTerm(tide_cid, ATparse("snd-disconnect"));
#endif
  if(use_toolbus)
    ATBwriteTerm(cid, ATparse("snd-disconnect"));

  exit(1);
}

/*}}}  */
/*{{{  static void signals_set() */

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

/*}}}  */
/*{{{  void handle_error(Tcl_Interp *interp, char *msg) */

void handle_error(Tcl_Interp *interp, char *msg)
{
  char *info = Tcl_GetVar(interp, "errorInfo", TCL_GLOBAL_ONLY);
#ifdef USE_TIDE
  char *code = Tcl_GetVar(interp, "errorCode", TCL_GLOBAL_ONLY);

  if(handle_tide_error(interp, code, msg, info))
    return;
#endif

  fprintf(stderr, "error in Tcl script: %s\n%s\n", msg, info);
}

/*}}}  */
/*{{{  void tcl_toolbus_handler(ClientData data, int mask) */

void tcl_toolbus_handler(ClientData data, int mask)
{
  if(ATBpeekOne(cid))
    ATBhandleOne(cid);
}

/*}}}  */
/*{{{  ATerm from_toolbus(int cid, ATerm t)  */

ATerm from_toolbus(int cid, ATerm t) 
{
  char *fname;
  ATerm event, msg;
	ATermList fargs;
  int pid1, pid2;
  ATerm Env, Subs, Notes, AtArgs, Coords;
  char *AtFun;
  ATerm pe;
  char *mon_point;
 
  reset_buffer();
  if(ATmatch(t, "rec-do(<appl(<list>)>)", &fname, &fargs)) {
    str2buf(fname);
    char2buf(' ');
    if(!ATisEmpty(fargs))
      args2buf(fargs);
    
    /*TBprintf(stderr, "calling function %s.\n", BUF);*/
    if(Tcl_Eval(global_interp, BUF) != TCL_OK) {
      handle_error(global_interp, global_interp->result);
    }

    return NULL;
  }
  
  if(ATmatch(t, "rec-eval(<appl(<list>)>)", &fname, &fargs)) {
    str2buf(fname);
    char2buf(' ');
    if(!ATisEmpty(fargs))
      args2buf(fargs);

    if(Tcl_Eval(global_interp, BUF) != TCL_OK) {
      handle_error(global_interp, global_interp->result);
    }

    if(global_interp->result)
      return TclString2Term(global_interp->result);

    return NULL;
  }

  if(ATmatch(t, "rec-ack-event(<term>)", &event)) {
    str2buf("rec-ack-event {");
    term2buf(event);
    str2buf("}");
    /*TBprintf(stderr, "calling function %s\n", BUF);*/
    if(Tcl_Eval(global_interp, BUF) != TCL_OK) {
      handle_error(global_interp, global_interp->result);
    }

    return NULL;
  }

  if(ATmatch(t, "rec-monitor(<appl(<int>,<appl>,<term>,<term>,<term>,"
						 "<term>,<term>,<int>,<term>)>)",
						 &mon_point, &pid1, &AtFun, &AtArgs, &Coords, 
						 &Env, &Subs, &Notes, &pid2, &pe)) {
    ATwarning("Monitor commands not implemented yet: %t\n", t);
    return NULL;
  }

  if(ATmatch(t, "rec-terminate(<term>)", &msg)) {
    str2buf("rec-terminate ");
    term2buf(msg);
    if(Tcl_Eval(global_interp, BUF) != TCL_OK) {
      handle_error(global_interp, global_interp->result);
    }
  }

  ATwarning("Ignored: %t\n", t);
  return NULL;
}

/*}}}  */
/*{{{  int Tcl_TBsend(ClientData data, Tcl_Interp *interp, int argc, char *argv[]) */

int Tcl_TBsend(ClientData data, Tcl_Interp *interp, int argc, char *argv[])
{
  ATerm t;

  if(argc != 2) {
    interp->result = "Usage: TBsend ?term?";
    return TCL_ERROR;
  }

  t = TclString2Term(argv[1]);

  if(use_toolbus)
    ATBwriteTerm(cid, t);
  else
    ATprintf("ATBwriteTerm: %t\n", t);

  return TCL_OK;
}

/*}}}  */
/*{{{  int Tcl_TBstring(ClientData data, Tcl_Interp *interp, int argc, char *argv[]) */

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
  buf = (char *)malloc(size);
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

/*}}}  */
/*{{{  int Tcl_bgerror(ClientData data, Tcl_Interp *interp, int argc, char *argv[]) */

int Tcl_bgerror(ClientData data, Tcl_Interp *interp, int argc, char *argv[])
{
  handle_error(interp, argv[1]);
  return TCL_OK;
}

/*}}}  */
/*{{{  int Tcl_AppInit(Tcl_Interp *interp) */

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

/*}}}  */
/*{{{  static int TB_Init(Tcl_Interp *interp) */

static int TB_Init(Tcl_Interp *interp)
{
  global_interp = interp;
  BUF = (char *)malloc(bufsize);
  if(!BUF)
    ATerror("Not enough space to allocate text buffer!\n");

  Tcl_CreateCommand(interp, "TBsend", Tcl_TBsend, (ClientData)NULL, (Tcl_CmdDeleteProc *)NULL);
  Tcl_CreateCommand(interp, "TBstring", Tcl_TBstring, NULL, NULL);
  Tcl_CreateCommand(interp, "bgerror", Tcl_bgerror, NULL, NULL);

  if(use_toolbus) {
    /*TB_connect(cid);*/
    /*toolbus_file = Tcl_GetFile((ClientData)TB_getSocket(cid), TCL_UNIX_FD);*/
    Tcl_CreateFileHandler(cid, TCL_READABLE, tcl_toolbus_handler, NULL);
  }

  if(Tcl_EvalFile(interp, LIBDIR "/tcltk.tcl") != TCL_OK) {
    interp->result = "Cannot load file " LIBDIR "/tcltk.tcl";
    return TCL_ERROR;
  }

  Tcl_SetVar(interp, "TB_LIBDIR", LIBDIR, TCL_GLOBAL_ONLY);

	return !TCL_ERROR;
}

/*}}}  */
/*{{{  void handle_args(int argc, char *argv[]) */

void handle_args(int argc, char *argv[])
{
  int i;

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
        ATwarning("warning: illegal buffer size %d\n", bufsize);
        bufsize = DEFAULT_BUF_SIZE;
      }
    }
    if(streq(argv[i], "-TB_TOOL_NAME")) {
      use_toolbus = ATtrue;
    }
  }
  if(!name)
    name = script;

  if(!name)
    name = "noname";

  if(use_toolbus)
    cid = ATBconnect(NULL, NULL, -1, from_toolbus);
}

/*}}}  */
/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  ATerm bottomOfStack;

  ATBinit(argc, argv, &bottomOfStack);

  handle_args(argc, argv);

#ifdef USE_TIDE
  init_tide_support(argc, argv);
#endif

  signals_set();

  Tk_Main(argc, argv, Tcl_AppInit);
  return 0;	/* Prevent compiler warning */
}

/*}}}  */
