#line 62 "wish-adapter.c.nw"
/*
 * Praktikum: Programmeer Omgevingen II
 * File:      ./serie3/src/wa.c
 * Opgave:    Eindopdracht
 * Datum:     Thu Aug 22 1996
 * Auteur(s): Merijn de Jonge   mdejonge   9577483
*/

/*
 * Modified, nowebbed, and documented by Pieter Olivier.
 * Date:     Wed Aug 28 10:09:23 MET DST 1996
 * 
 */

/*
 * Synopsis: wish-adapter [options] -script Script [-script-args A1..An]
 * options:
 *      -help                 print help message
 *      -wish Wish            use Wish as wish executable
 *      -lazy-exec            postpone execution of wish until needed
 * 
 * where N is the toolname
 * and   S is a name of Tcl script to be executed
 * and   ... are arguments to be passed on to wish
 * 
 */

/*
 * notes:
 *    -not very well tested yet
 *
 */
#line 103 "wish-adapter.c.nw"
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <TB.h>
#line 118 "wish-adapter.c.nw"
#ifndef WISH
#define WISH    "wish"
#endif

#ifndef TBTCL
#define TBTCL   "/usr/local/lib/tb.tcl"
#endif

#define MAX_ARG 50


#define USAGE_MSG \
   "\n" \
   "Synopsis: wa [options]\n" \
   "\n" \
   "Options are:\n" \
   "-help                 print this message\n" \
   "-wish Wish            use Wish as wish executable\n" \
   "-lazy-exec            postpone execution of wish until needed\n" \
   "-script Name          use Name as Tcl script for wish\n" \
   "-script-args A1 ...   use A1 ... as arguments for the wish execution\n"

#ifdef DEBUG_ON
#define CHAR2WISH(c)			fputc(c, to_wish); \
					fputc(c, stderr)
#define PRINT2WISH0(s)			fputs(s, to_wish); \
					fputs(s, stderr)
#define PRINT2WISH1(fmt,a)		fprintf(to_wish, fmt, a); \
					fprintf(stderr, fmt, a)
#define PRINT2WISH2(fmt,a1,a2)		fprintf(to_wish, fmt, a1, a2); \
					fprintf(stderr, fmt, a1, a2)
#define PRINT2WISH3(fmt,a1,a2,a3)	fprintf(to_wish, fmt, a1, a2, a3); \
					fprintf(stderr, fmt, a1, a2, a3)
#define PRINT2WISH7(fmt,a1,a2,a3,a4,a5,a6,a7) \
		fprintf(to_wish, fmt, a1, a2, a3, a4, a5, a6, a7); \
		fprintf(stderr, fmt, a1, a2, a3, a4, a5, a6, a7)
#else
#define CHAR2WISH(c)			fputc(c, to_wish)
#define PRINT2WISH0(s)			fputs(s, to_wish)
#define PRINT2WISH1(fmt,a)		fprintf(to_wish, fmt, a)
#define PRINT2WISH2(fmt,a1,a2)		fprintf(to_wish, fmt, a1, a2)
#define PRINT2WISH3(fmt,a1,a2,a3)	fprintf(to_wish, fmt, a1, a2, a3)
#define PRINT2WISH7(fmt,a1,a2,a3,a4,a5,a6,a7) \
		fprintf(to_wish, fmt, a1, a2, a3, a4, a5, a6, a7)
#endif
#line 171 "wish-adapter.c.nw"
static char*  progname             = WISH;
static char*  script               = NULL;
static char*  script_args[MAX_ARG];
static int    script_nr_args       = 0;
static pid_t  pgid                 = -1;
static FILE*  to_wish              = NULL;
static FILE*  from_wish            = NULL;
static TBbool connected            = TBfalse;
static TBbool lazy_exec            = TBfalse;
static char*  name                 = NULL;
static char   backslashes[16]	   = "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\";

extern term_list* tool_in_sign; /* for check_in_sign */
extern char*      tool_name;    /* idem */
#line 191 "wish-adapter.c.nw"
static void error(const char* msg);
static void print_string(char* s, int n, int depth);
static void print_var(term* e, int depth);
static void print_env(env* e, int depth);
static void print_term(term* t, int depth);
static void print_list(term_list* l, char* left, char* sep, char* right, int depth);
static TBbool is_to_tool_comm(const char* s );
static TBbool is_from_tool_comm(char* s );
static int bytes_in_term(term* t);
static TBbool rec_monitor(term* e, term** out);
static TBbool rec_do(term* e, term** out);
static TBbool rec_eval(term* e, term** out);
static TBbool rec_ack_event(term* e, term** out);
static TBbool rec_terminate(term* e, term** out);

static term*  handle_input_from_toolbus(term* e);
static term*  handle_input_from_wish(term* e);
static term*  dummy_check_in_sign(term* t);

static void require_fun(char* fname, term_list* fargs);
static void check_in_sign();
static void wish_create();
static void wish_start();
static void signal_handler( int sig );
static void disconnect();
static void shutdown( int ret );
static void signals_set();
static void help();
static void cmd_options( int argc, char* argv[] );

#line 229 "wish-adapter.c.nw"
static void error( const char* msg )
{
   disconnect();
   fprintf(stderr, "%s: %s : %s\n", progname, msg, strerror(errno));
   shutdown(1);
}
#line 241 "wish-adapter.c.nw"
static void print_backslashes(int n)
{
  while(n > 16) {
    PRINT2WISH0(backslashes);
    n -= 16;
  }
  if(n > 0)
    PRINT2WISH0(&backslashes[16-n]);
}
#line 261 "wish-adapter.c.nw"
static void print_string(char* s, int n, int depth)
{
  print_backslashes(depth*2);
  CHAR2WISH('"');
  while(n--)
  {
    if(isprint(*s)) {
      switch (*s) {
	case '\\':
	case '"':	print_backslashes(depth*2+1);
			CHAR2WISH(*s);
			break;
	case '{':
	case '}':
	case '[':
	case ']':
	case '$':	CHAR2WISH('\\');
	default:	CHAR2WISH(*s);
      }
    } else {
      PRINT2WISH1("\\%03o", (unsigned int)*s);
    }
    s++;
  }
  print_backslashes(depth*2);
  CHAR2WISH('"');
}
#line 296 "wish-adapter.c.nw"
static void print_var(term* e, int depth)
{
   char* txt;
   txt = get_txt(var_sym(e));
   print_string(txt, strlen(txt), depth);
   CHAR2WISH(':');
   print_term(var_type(e), depth);
   if(var_result(e))
     CHAR2WISH('?');
}
#line 314 "wish-adapter.c.nw"
static void print_env(env* e, int depth)
{
   TBbool first = TBtrue;
   char* txt;
   
   print_backslashes(depth*2);
   CHAR2WISH('"');
   while(e != NULL)
   {
      assert(is_env(e));
      if(first)
        first = TBfalse;
      else
	CHAR2WISH(' ');
      txt = get_txt(env_sym(e));
      print_string(txt, strlen(txt), depth+1);
      CHAR2WISH(' ');
      print_term(env_val(e), depth+1);
      e = env_next(e);
   }
   print_backslashes(depth*2);
   CHAR2WISH('"');
}
#line 346 "wish-adapter.c.nw"
static void print_term(term* t, int depth)
{
   switch(tkind(t))
   {
      case t_str:
         print_string(str_val(t), strlen(str_val(t)), depth);
         break;
      case t_bstr:
         print_string(bstr_val(t), bstr_len(t), depth);
         break;
      case t_bool:
         if(bool_val(t) == TBtrue) {
            PRINT2WISH0("true");
         } else {
            PRINT2WISH0("false");
         }
         break;
      case t_int:
         PRINT2WISH1("%d", int_val(t));
         break;
      case t_real:
         PRINT2WISH1("%f", real_val(t));
         break;
      case t_var:
         print_var(t, depth);
         break;
      case t_placeholder:
         CHAR2WISH('<');
         print_term(placeholder_type(t), depth);
         CHAR2WISH('>');
         break;
      case t_appl:
         PRINT2WISH1("%s", get_txt(fun_sym(t)));
         if(fun_args(t) != NULL)
            print_list(fun_args(t), "(", ",", ")", depth);
         break;
      case t_list:
	 print_backslashes(depth*2);
	 CHAR2WISH('"');
         print_list(t, "", " ", "", depth+1);	
	 print_backslashes(depth*2);
	 CHAR2WISH('"');
         break;
      case t_env:
         print_env(t, depth);
         break;
   }
}
#line 402 "wish-adapter.c.nw"
static void print_list(term_list* l, char* left, char* sep, char* right, int depth)
{
   int i;
   PRINT2WISH0(left);
   for(i=1; i<=list_length(l); i++) {
      if(i>1) {
         PRINT2WISH0(sep);
      }
      print_term(list_index(l, i), depth);
   }
   PRINT2WISH0(right);
}
#line 422 "wish-adapter.c.nw"
static void print_args(term_list *args, int depth)
{
  print_list(args, "", " ", "", depth);
/*  while(args) {
    if(tkind(first(args)) != t_list)
      PRINT2WISH0(" \"");

    print_term(first(args), depth);
    if(tkind(first(args)) != t_list)
      PRINT2WISH0("\"");

    args = list_next(args);
  }
*/
}
#line 445 "wish-adapter.c.nw"
static TBbool is_to_tool_comm( const char* s )
{
   return streq( s, "snd-eval" )      || 
          streq( s, "snd-cancel" )    ||
          streq( s, "snd-do" )        || 
          streq( s, "snd-ack-event" ) ||
          streq( s, "snd-terminate" );
}
#line 461 "wish-adapter.c.nw"
static TBbool is_from_tool_comm( char* s )
{
   return streq( s, "rec-value" ) ||  
          streq( s, "rec-event" ) ||
          streq( s, "rec-disconnect" );
}
#line 476 "wish-adapter.c.nw"
static int bytes_in_term( term* t )
{ 
   int length;
   
   length = 8; /* LENSPEC */
   length += strlen( TBsprintf( "%t", t ) );
   return length;
}
#line 492 "wish-adapter.c.nw"
static TBbool rec_monitor( term* e, term** out )
{
  
#line 546 "wish-adapter.c.nw"
  int        pid1;
  int        pid2;
  int        blino;
  int        bpos;
  int        elino;
  int        epos;
  int        tid;
  int        dir;
  term*      Env;
  term*      Subs;
  term*      Notes;
  term*      AtArgs;
  term*      Coords;
  char*      AtFun;
  term_list* ts;
  term_list* pair;
  term_list* args;
  term*      var;
  term*      pe;
  char*      mon_point;
  char*      name;
  char*      filename;

#line 496 "wish-adapter.c.nw"
  *out = NULL;

  
#line 576 "wish-adapter.c.nw"
  if( TBmatch( e, "rec-monitor(%f(%d,%f,%t,%t,%t,%t,%t,%d,%t))",
	&mon_point,
	&pid1,
	&AtFun,
	&AtArgs,
	&Coords,
	&Env,
	&Subs,
	&Notes,
	&pid2,
	&pe ) == TBfalse )
    return TBfalse;

#line 500 "wish-adapter.c.nw"
  PRINT2WISH0("if [catch { ");

  
#line 598 "wish-adapter.c.nw"
  if(Coords == NULL) {
      filename = "INIT";
      blino = elino = bpos = epos = 0;
  } else {
    if(TBmatch(Coords, "[%s,%d,%d,%d,%d]", 
		&filename, &blino, &bpos, &elino, &epos) == TBfalse )
         TBmsg( "**** coords do not match\n" );
  }
#line 503 "wish-adapter.c.nw"
   
   if(streq(AtFun, "create")) {
     
#line 615 "wish-adapter.c.nw"
  if(TBmatch(AtArgs, "[%f(%l), %t]", &name, &args, &var) == TBfalse)
    TBmsg( "**** args of create do not match\n" );
  TBprintf(to_wish, "create_proc %t %s\n", list_get(Env, var), name);
#line 506 "wish-adapter.c.nw"
   } else  if(streq(AtFun, "rec-connect")) {
     
#line 627 "wish-adapter.c.nw"
  if(TBmatch(AtArgs, "[%t]", &var ) == TBfalse)
    TBmsg( "**** args of rec-connect do not match: %t\n", AtArgs );
  if(TBmatch(get_list_as_env(var, Env), "%f(%d)", &name,&tid) == TBfalse) {
    TBmsg( "**** rec-connect: value of var does not match: var=%t, env=%t", 
								    var, Env);
    TBmsg( "**** value_list(var, Env) = %t\n", get_list_as_env(var, Env));
  }
  TBprintf( to_wish, "create_tool %d %s\n", tid, name );
#line 508 "wish-adapter.c.nw"
   }
   else if(is_to_tool_comm(AtFun)) {
     
#line 644 "wish-adapter.c.nw"
  if(TBmatch(AtArgs, "[%t, %l]", &var, &args) == TBfalse)
    TBmsg( "**** args of tool comm do not match:%t\n", AtArgs );
  if(TBmatch(get_list_as_env(var, Env ), "%f(%d)", &name, &tid) == TBfalse)
    TBmsg("**** to_tool: value of var does not match: var=%t, env=%t",var,Env);
  TBprintf(to_wish, "proc_tool_comm %d %d %d\n", pid1,tid,bytes_in_term(args));
#line 511 "wish-adapter.c.nw"
   }
   else if(is_from_tool_comm(AtFun)) {
     
#line 658 "wish-adapter.c.nw"
  if(TBmatch( AtArgs, "[%t, %l]", &var, &args) == TBfalse)
    TBmsg("**** args of tool comm do not match:%t\n", AtArgs);
  if(TBmatch(get_list_as_env(var, Env), "%f(%d)", &name, &tid) == TBfalse)
    TBmsg("**** from_tool: val of var doesn't match: var=%t, env=%t", var,Env);
  TBprintf(to_wish, "tool_proc_comm %d %d %d\n", pid1,tid,bytes_in_term(args));
#line 514 "wish-adapter.c.nw"
   }

   if(pid1 > 0) {
     
#line 671 "wish-adapter.c.nw"
  for(ts = Env; ts != NULL ; ts = next(ts)) {
    pair = first(ts);
    if(get_txt(var_sym(first(pair)))[0] != '_')
    TBprintf(to_wish, "update_var %d {%t} {%t}\n", 
				pid1, first(pair), first(next(pair)));
  }
#line 518 "wish-adapter.c.nw"
     
#line 685 "wish-adapter.c.nw"
  for(ts = Subs; ts != NULL; ts = next(ts))
    TBprintf(to_wish, "update_subs %d {%t}\n", pid1, first(ts));
#line 519 "wish-adapter.c.nw"
     
#line 690 "wish-adapter.c.nw"
  for(ts = Notes; ts != NULL; ts = next(ts))
    TBprintf(to_wish, "update_notes %d {%t}\n", pid1, first(ts));
#line 520 "wish-adapter.c.nw"
   }
   
   if( pid2 > 0 ) {
     
#line 701 "wish-adapter.c.nw"
  dir = streq(AtFun, "snd-msg") ? 1 : -1;
  TBprintf(to_wish, "proc_proc_comm %d %d %d\n", pid1, pid2, dir);
#line 524 "wish-adapter.c.nw"
   }
   
   if(streq(AtFun, "endlet")) {
     
#line 712 "wish-adapter.c.nw"
  if(TBmatch(AtArgs, "[%l]", &args) == TBfalse)
    TBmsg("**** args of end_let do not match\n");
  for( ; args != NULL; args = next(args))
    TBprintf(to_wish, "delete_var %d {%t}\n", pid1, first(args));
  TBprintf(to_wish, "} msg] { TBerror $msg }\n");
  *out = TBmake( "snd-continue(%d)", pid1);
  return TBtrue;
#line 528 "wish-adapter.c.nw"
   } else {
     PRINT2WISH7("monitor_atom %d %s %s %d %d %d %d\n",
         		pid1, AtFun, filename, blino, bpos, elino, epos);
   }

   PRINT2WISH0("} msg] { TBerror $msg }\n");
   fflush(to_wish);

   return TBtrue;
}
#line 729 "wish-adapter.c.nw"
static TBbool rec_do(term* e, term** out)
{
   char* fname;
   term_list* fargs;
   
   *out = NULL;
   
   /* rec-do */
   if(TBmatch( e, "rec-do(%f(%l))", &fname, &fargs) == TBfalse)
      return TBfalse;
   PRINT2WISH1("if [catch {%s ", fname);
   /* Only print list when list isn't empty */
   if(fargs)
     print_args(fargs, 0);
     /*print_list(fargs, "\"", "\" \"", "\"");*/
   PRINT2WISH0(" } msg] {TBerror $msg}\n");
   fflush(to_wish);
   return TBtrue;
}
#line 756 "wish-adapter.c.nw"
static TBbool rec_eval( term* e, term** out )
{
   char* fname;
   term_list* fargs;
   
   *out = NULL;
   
   /* rec-eval */
   if(TBmatch(e, "rec-eval(%f(%l))", &fname, &fargs) == TBfalse)
     return TBfalse;
   PRINT2WISH1("if [catch {%s ", fname);
   /* Only print list when list isn't empty */
   if(list_length(fargs))
     print_args(fargs, 0);
     /*print_list(fargs, "\"", "\" \"", "\"");*/
   PRINT2WISH0("} msg] {TBerror $msg}\n");
   fflush(to_wish);
   return TBtrue;
}
#line 783 "wish-adapter.c.nw"
static TBbool rec_ack_event(term* e, term** out)
{
   term* farg;
   
   *out = NULL;
   
   /* rec-ack-event */
   if(TBmatch(e, "rec-ack-event(%t)", &farg) == TBfalse)
      return TBfalse;
   PRINT2WISH0("if [catch {rec-ack-event \"");
   print_term(farg, 0);
   PRINT2WISH0("\" } msg] {TBerror $msg}\n" );
   fflush(to_wish);
   return TBtrue;
}
#line 808 "wish-adapter.c.nw"
static TBbool rec_terminate( term* e, term** out )
{
   term* farg;
   
   *out = NULL;
   
   /* rec-terminate */
   if(TBmatch(e, "rec-terminate(%t)", &farg) == TBfalse)
      return TBfalse;
   PRINT2WISH0("if [catch {rec-terminate \"");
   print_term(farg, 0);
   PRINT2WISH0("\" } msg] {TBerror $msg}; exit\n" );
   fflush(to_wish);
   connected = TBfalse;
   shutdown(0);
   
   /* not reached */
   return TBtrue;
}
#line 836 "wish-adapter.c.nw"
term* handle_input_from_toolbus( term* e )
{
   term* result;
   
   if( rec_ack_event( e, &result ) ||
       rec_terminate( e, &result ) ||
         rec_monitor( e, &result ) ||
            rec_eval( e, &result ) ||
              rec_do( e, &result ) )
      return result;

   /* error ! */
   TBmsg("Ignored: %t\n", e);
   return NULL;
}
#line 859 "wish-adapter.c.nw"
term* handle_input_from_wish( term* e ) 
{
   char* msg;

   /* wish-error */
   if(TBmatch(e, "wish-error( %s )", &msg)) {
      TBmsg("wish-error: %s\n", msg);
      return NULL;
   }

   /* snd-disconnect */
   if(TBmatch(e, "snd-disconnect")) {
      disconnect();
      shutdown( 0 );
   }
      
   return e;
}
#line 884 "wish-adapter.c.nw"
term *dummy_check_in_sign( term* t )
{
   return NULL;
}
#line 897 "wish-adapter.c.nw"
static void require_fun( char* fname, term_list* fargs )
{
   PRINT2WISH3("TBrequire %s %s %d\n", tool_name, fname, list_length(fargs));
   fflush(to_wish);
}
#line 910 "wish-adapter.c.nw"
static void check_in_sign()
{
   char*      atf;
   char       pat[128];
   term_list* arg;
   term_list* reqs;

   reqs = tool_in_sign;
   
   /* construct match pattern, e.g. ``%f( <calc>,%l )'' */
   sprintf( pat, "%%f( <%s>, %%l )", tool_name );

   for( ; reqs != NULL; reqs = next( reqs ) )
   {
      if( TBmatch( first( reqs ), pat, &atf, &arg ) )
      {
         if( streq( atf, "rec-do") || streq( atf, "rec-eval" ) )
            require_fun( get_txt( fun_sym( first( arg ) ) ), 
                         fun_args( first( arg ) ) );
         else
         if( streq( atf, "rec-ack-event" ) )
            require_fun( "rec-ack-event", arg );
         else
         if( streq( atf, "rec-terminate" ) )
            require_fun( "rec-terminate", arg );
         else
            TBmsg( "check_in_sign: skipped %t\n", first( reqs ) );
      }
      else
         TBmsg( "check_in_sign: skipped %t\n", first( reqs ) );
   }
}
#line 951 "wish-adapter.c.nw"
static void wish_create()
{
   pid_t pid;
   int   pipe_tw[2]; /* toolbus 2 wish */
   int   pipe_wt[2]; /* wish 2 toolbus */
   
   if( pipe( pipe_tw ) < 0 )
      error( "pipe" );
   if( pipe( pipe_wt ) < 0 )
      error( "pipe" );

   pid = fork();
   switch( pid )
   {
      case 0:
         if(setpgid(0, 0) == -1)
            error( "sepgid");
         dup2(pipe_tw[0], 0);
         dup2(pipe_wt[1], 1);
         
         close(pipe_tw[1]);
         close(pipe_wt[0]);
         
         execlp(progname, progname, NULL);
         fprintf(stderr, "%s: execlp: %s\n", progname, strerror(errno));
         exit(1);
      case -1:
         error("fork");
      default:
         if(pgid == -1)
            pgid = pid;
         to_wish = fdopen(pipe_tw[1], "w");
         from_wish = fdopen(pipe_wt[0], "r");
         close(pipe_tw[0]);
         close(pipe_wt[1]);
         TBaddTermPort( pipe_wt[0], handle_input_from_wish );
         return;
   }
}
#line 998 "wish-adapter.c.nw"
static void wish_start()
{
   int i;

   PRINT2WISH2("if ![file exists %s] "
                      "{puts stderr \"%s not found\"; exit 1}\n", TBTCL, TBTCL );
   PRINT2WISH2(
	"if ![file exists %s] {puts stderr \"%s not found\"; exit 1}\n",
		 					script, script);
   
   PRINT2WISH1("source %s\n", TBTCL);
   PRINT2WISH0("set argv {") ;
   for(i=0; i<script_nr_args; i++) {
     PRINT2WISH1("%s ", script_args[i]);
   }
   PRINT2WISH0("}\n");
   PRINT2WISH1("set argc %d\n", script_nr_args);
   PRINT2WISH1("source %s\n", script);
   check_in_sign();
}
#line 1027 "wish-adapter.c.nw"
static void signal_handler( int sig )
{
   int status;
   int child_exit = -1;

   switch( sig )
   {
      case SIGCHLD:
         if( waitpid( -pgid, &status, WNOHANG ) == -1 )
            error( "waitpid" );
         /* only save child's exit when it was not killed */
         if( WIFEXITED(status) )
            child_exit = WEXITSTATUS( status );
         disconnect();
         exit( child_exit );
         break;
      default:
         disconnect();
         shutdown( 1 );
   }
}
#line 1056 "wish-adapter.c.nw"
static void disconnect()
{
   if(connected)
      TBsend(TBmake("snd-disconnect"));
   connected = TBfalse;
}
#line 1070 "wish-adapter.c.nw"
static void shutdown( int ret )
{
   sleep(1);
   
   if(pgid != -1)
      kill(-pgid, SIGKILL);
   
   exit(ret);
}
#line 1087 "wish-adapter.c.nw"
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
   sigaction( SIGCHLD, &act, NULL );  
}
#line 1110 "wish-adapter.c.nw"
static void help()
{
   fprintf( stderr, USAGE_MSG );
}
#line 1122 "wish-adapter.c.nw"
static void cmd_options( int argc, char* argv[] )
{
   int i;

   i = 0;

   while( i < argc )
   {
      if( streq( argv[i], "-help" ) )
         help();
      if( streq( argv[i], "-TB_TOOL_NAME" ) )
         name = argv[++i];
      if( streq( argv[i], "-script" ) )
         script = argv[++i];
      if( streq( argv[i], "-lazy-exec" ) )
         lazy_exec = TBtrue;
      if( streq( argv[i], "-wish" ) )
         progname = argv[++i];
      if( streq( argv[i], "-script-args" ) )
      {
         i++;
         for( ; i < argc; i++ )
            script_args[script_nr_args++] = argv[i];
      }
      i++;
   }
}
#line 1159 "wish-adapter.c.nw"
void main( int argc, char* argv[] )
{
   cmd_options(argc, argv);
   signals_set();
   
   TBinit(name, argc, argv, handle_input_from_toolbus, dummy_check_in_sign);
   connected = TBtrue;

   if(script == NULL) {
      error("Missing -script argument\n");
      exit(1);
   }

   while(lazy_exec && !TBpeek())
      sleep(1);

   wish_create();
   wish_start();
   signals_set();
   
   TBeventloop();
}

#line 47 "wish-adapter.c.nw"
/*
 * EOF ./serie3/src/wa.c
 */
