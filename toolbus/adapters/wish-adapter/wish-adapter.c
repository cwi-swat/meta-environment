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

#define DEBUG_ON
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
#line 172 "wish-adapter.c.nw"
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
#line 192 "wish-adapter.c.nw"
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

#line 230 "wish-adapter.c.nw"
static void error( const char* msg )
{
   disconnect();
   fprintf(stderr, "%s: %s : %s\n", progname, msg, strerror(errno));
   shutdown(1);
}
#line 245 "wish-adapter.c.nw"
int slash_mania(int level)
{
  return (1<<(level+1))-1;

/* Does the same thing as the old:
  if(level == 0)
    return 1;
  return slash_mania(level-1)*2+1;
*/
}

static void print_backslashes(int level)
{
  if(level >= 0) {
    int n = slash_mania(level);
    while(n > 16) {
      PRINT2WISH0(backslashes);
      n -= 16;
    }
    if(n > 0)
      PRINT2WISH0(&backslashes[16-n]);
  }
}
#line 279 "wish-adapter.c.nw"
static void print_string(char* s, int n, int depth)
{
  print_backslashes(depth);
  CHAR2WISH('"');
  while(n--)
  {
    if(isprint(*s)) {
      switch (*s) {
	case '\\':
	case '"':	print_backslashes(depth+1);
			CHAR2WISH(*s);
			break;
	case '{':
	case '}':
	case '[':
	case ']':
	case ' ':
	case ';':
	case '$':	print_backslashes(depth+1);
			/*CHAR2WISH('\\')*/
	default:	CHAR2WISH(*s);
      }
    } else {
      PRINT2WISH1("\\%03o", (unsigned int)*s);
    }
    s++;
  }
  print_backslashes(depth);
  CHAR2WISH('"');
}
#line 317 "wish-adapter.c.nw"
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
#line 335 "wish-adapter.c.nw"
static void print_env(env* e, int depth)
{
   TBbool first = TBtrue;
   char* txt;
   
   print_backslashes(depth);
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
   print_backslashes(depth);
   CHAR2WISH('"');
}
#line 367 "wish-adapter.c.nw"
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
            print_list(fun_args(t), "(", ",", ")", depth+1);
         break;
      case t_list:
	 print_backslashes(depth);
	 CHAR2WISH('"');
         print_list(t, "", " ", "", depth+1);	
	 print_backslashes(depth);
	 CHAR2WISH('"');
         break;
      case t_env:
         print_env(t, depth);
         break;
   }
}
#line 423 "wish-adapter.c.nw"
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
#line 443 "wish-adapter.c.nw"
static void print_args(term_list *args, int depth)
{
  print_list(args, "", " ", "", depth);
/*  while(args) {
    PRINT2WISH0(" \"");
    print_term(list_first(args), depth);
    CHAR2WISH(' ');
    PRINT2WISH0("\"");
    args = list_next(args);
  }
*/
}
#line 463 "wish-adapter.c.nw"
static TBbool is_to_tool_comm( const char* s )
{
   return streq( s, "snd-eval" )      || 
          streq( s, "snd-cancel" )    ||
          streq( s, "snd-do" )        || 
          streq( s, "snd-ack-event" ) ||
          streq( s, "snd-terminate" );
}
#line 479 "wish-adapter.c.nw"
static TBbool is_from_tool_comm( char* s )
{
   return streq( s, "rec-value" ) ||  
          streq( s, "rec-event" ) ||
          streq( s, "rec-disconnect" );
}
#line 494 "wish-adapter.c.nw"
static int bytes_in_term( term* t )
{ 
   int length;
   
   length = 8; /* LENSPEC */
   length += strlen( TBsprintf( "%t", t ) );
   return length;
}
#line 510 "wish-adapter.c.nw"
static TBbool rec_monitor( term* e, term** out )
{
  
#line 564 "wish-adapter.c.nw"
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

#line 514 "wish-adapter.c.nw"
  *out = NULL;

  
#line 594 "wish-adapter.c.nw"
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

#line 518 "wish-adapter.c.nw"
  PRINT2WISH0("if [catch { ");

  
#line 616 "wish-adapter.c.nw"
  if(Coords == NULL) {
      filename = "INIT";
      blino = elino = bpos = epos = 0;
  } else {
    if(TBmatch(Coords, "[%s,%d,%d,%d,%d]", 
		&filename, &blino, &bpos, &elino, &epos) == TBfalse )
         TBmsg( "**** coords do not match\n" );
  }
#line 521 "wish-adapter.c.nw"
   
   if(streq(AtFun, "create")) {
     
#line 633 "wish-adapter.c.nw"
  if(TBmatch(AtArgs, "[%f(%l), %t]", &name, &args, &var) == TBfalse)
    TBmsg( "**** args of create do not match\n" );
  TBprintf(to_wish, "create_proc %t %s\n", list_get(Env, var), name);
#line 524 "wish-adapter.c.nw"
   } else  if(streq(AtFun, "rec-connect")) {
     
#line 645 "wish-adapter.c.nw"
  if(TBmatch(AtArgs, "[%t]", &var ) == TBfalse)
    TBmsg( "**** args of rec-connect do not match: %t\n", AtArgs );
  if(TBmatch(get_list_as_env(var, Env), "%f(%d)", &name,&tid) == TBfalse) {
    TBmsg( "**** rec-connect: value of var does not match: var=%t, env=%t", 
								    var, Env);
    TBmsg( "**** value_list(var, Env) = %t\n", get_list_as_env(var, Env));
  }
  TBprintf( to_wish, "create_tool %d %s\n", tid, name );
#line 526 "wish-adapter.c.nw"
   }
   else if(is_to_tool_comm(AtFun)) {
     
#line 662 "wish-adapter.c.nw"
  if(TBmatch(AtArgs, "[%t, %l]", &var, &args) == TBfalse)
    TBmsg( "**** args of tool comm do not match:%t\n", AtArgs );
  if(TBmatch(get_list_as_env(var, Env ), "%f(%d)", &name, &tid) == TBfalse)
    TBmsg("**** to_tool: value of var does not match: var=%t, env=%t",var,Env);
  TBprintf(to_wish, "proc_tool_comm %d %d %d\n", pid1,tid,bytes_in_term(args));
#line 529 "wish-adapter.c.nw"
   }
   else if(is_from_tool_comm(AtFun)) {
     
#line 676 "wish-adapter.c.nw"
  if(TBmatch( AtArgs, "[%t, %l]", &var, &args) == TBfalse)
    TBmsg("**** args of tool comm do not match:%t\n", AtArgs);
  if(TBmatch(get_list_as_env(var, Env), "%f(%d)", &name, &tid) == TBfalse)
    TBmsg("**** from_tool: val of var doesn't match: var=%t, env=%t", var,Env);
  TBprintf(to_wish, "tool_proc_comm %d %d %d\n", pid1,tid,bytes_in_term(args));
#line 532 "wish-adapter.c.nw"
   }

   if(pid1 > 0) {
     
#line 689 "wish-adapter.c.nw"
  for(ts = Env; ts != NULL ; ts = next(ts)) {
    pair = first(ts);
    if(get_txt(var_sym(first(pair)))[0] != '_')
    TBprintf(to_wish, "update_var %d {%t} {%t}\n", 
				pid1, first(pair), first(next(pair)));
  }
#line 536 "wish-adapter.c.nw"
     
#line 703 "wish-adapter.c.nw"
  for(ts = Subs; ts != NULL; ts = next(ts))
    TBprintf(to_wish, "update_subs %d {%t}\n", pid1, first(ts));
#line 537 "wish-adapter.c.nw"
     
#line 708 "wish-adapter.c.nw"
  for(ts = Notes; ts != NULL; ts = next(ts))
    TBprintf(to_wish, "update_notes %d {%t}\n", pid1, first(ts));
#line 538 "wish-adapter.c.nw"
   }
   
   if( pid2 > 0 ) {
     
#line 719 "wish-adapter.c.nw"
  dir = streq(AtFun, "snd-msg") ? 1 : -1;
  TBprintf(to_wish, "proc_proc_comm %d %d %d\n", pid1, pid2, dir);
#line 542 "wish-adapter.c.nw"
   }
   
   if(streq(AtFun, "endlet")) {
     
#line 730 "wish-adapter.c.nw"
  if(TBmatch(AtArgs, "[%l]", &args) == TBfalse)
    TBmsg("**** args of end_let do not match\n");
  for( ; args != NULL; args = next(args))
    TBprintf(to_wish, "delete_var %d {%t}\n", pid1, first(args));
  TBprintf(to_wish, "} msg] { TBerror $msg }\n");
  *out = TBmake( "snd-continue(%d)", pid1);
  return TBtrue;
#line 546 "wish-adapter.c.nw"
   } else {
     PRINT2WISH7("monitor_atom %d %s %s %d %d %d %d\n",
         		pid1, AtFun, filename, blino, bpos, elino, epos);
   }

   PRINT2WISH0("} msg] { TBerror $msg }\n");
   fflush(to_wish);

   return TBtrue;
}
#line 747 "wish-adapter.c.nw"
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
     print_args(fargs, -1);
     /*print_list(fargs, "\"", "\" \"", "\"");*/
   PRINT2WISH0(" } msg] {TBerror $msg}\n");
   fflush(to_wish);
   return TBtrue;
}
#line 774 "wish-adapter.c.nw"
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
   if(fargs)
     print_args(fargs, -1);
     /*print_list(fargs, "\"", "\" \"", "\"");*/
   PRINT2WISH0("} msg] {TBerror $msg}\n");
   fflush(to_wish);
   return TBtrue;
}
#line 801 "wish-adapter.c.nw"
static TBbool rec_ack_event(term* e, term** out)
{
   term* farg;
   
   *out = NULL;
   
   /* rec-ack-event */
   if(TBmatch(e, "rec-ack-event(%t)", &farg) == TBfalse)
      return TBfalse;
   PRINT2WISH0("if [catch {rec-ack-event ");
   print_term(farg, -1);
   PRINT2WISH0("} msg] {TBerror $msg}\n" );
   fflush(to_wish);
   return TBtrue;
}
#line 826 "wish-adapter.c.nw"
static TBbool rec_terminate( term* e, term** out )
{
   term* farg;
   
   *out = NULL;
   
   /* rec-terminate */
   if(TBmatch(e, "rec-terminate(%t)", &farg) == TBfalse)
      return TBfalse;
   PRINT2WISH0("if [catch {rec-terminate ");
   print_term(farg, -1);
   PRINT2WISH0("} msg] {TBerror $msg}; exit\n" );
   fflush(to_wish);
   connected = TBfalse;
   shutdown(0);
   
   /* not reached */
   return TBtrue;
}
#line 854 "wish-adapter.c.nw"
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
#line 877 "wish-adapter.c.nw"
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
#line 902 "wish-adapter.c.nw"
term *dummy_check_in_sign( term* t )
{
   return NULL;
}
#line 915 "wish-adapter.c.nw"
static void require_fun( char* fname, term_list* fargs )
{
   PRINT2WISH3("TBrequire %s %s %d\n", tool_name, fname, list_length(fargs));
   fflush(to_wish);
}
#line 928 "wish-adapter.c.nw"
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
#line 969 "wish-adapter.c.nw"
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
#line 1016 "wish-adapter.c.nw"
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
#line 1045 "wish-adapter.c.nw"
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
#line 1074 "wish-adapter.c.nw"
static void disconnect()
{
   if(connected)
      TBsend(TBmake("snd-disconnect"));
   connected = TBfalse;
}
#line 1088 "wish-adapter.c.nw"
static void shutdown( int ret )
{
   sleep(1);
   
   if(pgid != -1)
      kill(-pgid, SIGKILL);
   
   exit(ret);
}
#line 1105 "wish-adapter.c.nw"
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
#line 1128 "wish-adapter.c.nw"
static void help()
{
   fprintf( stderr, USAGE_MSG );
}
#line 1140 "wish-adapter.c.nw"
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
#line 1177 "wish-adapter.c.nw"
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
