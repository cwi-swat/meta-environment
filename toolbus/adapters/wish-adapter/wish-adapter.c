#line 2 "wish-adapter.c.nw"
/* -*-C-*-
 * wish-adapter -- Generic adapter for ToolBus <-> wish connection
 *
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
 * Author: Paul Klint, March, 1994 & Februari 1995

 * May 24, Pieter Olivier
 * - added -lazy-exec option
 * - added -wish option
 * March 1994, Pieter Olivier
 * - added support for binary strings and lists
 * April 5, Paul Klint
 * - clean up of terminate/disconnect code
 * - monitor code surrounded by a catch construct
 *
 * Purpose: pass term coming from ToolBus to wish, e.g.,
 *
 *    do(mk-button(3))  ==> mk-button 3
 *
 *
 * Architecture:
 *
 *         ================== ToolBus
 *           |           ^
 *           v           |    (sockets)
 *         +---------------+
 *         | wish-adapter  |
 *         +---------------+
 *           |           ^
 *           |           |
 *           |  +------+ |
 *           +->| wish |-+    (standard input/output)
 *              +------+
 *
 */

#include "TB.h"
#include <unistd.h>
#include <signal.h>

FILE *to_wish;  /* file descriptor connected to std input of wish */

/* Some utility functions */
void pr_type_wish(type *tp);
void pr_term_list_wish(const term_list *tl, char sep);
void pr_env_wish(const env *e);
void pr_string_wish(char *s, int len);
term *handle_input_from_wish(term *e);
void connect_to_wish(char *script, char *name, TBcallbackTerm handler);

/* arguments passed to script */

char *def_args[] = {NULL};
char **script_args = def_args;

/* Variables needed for lazy execution */
TBbool lazy_exec = TBfalse;
char *name = "wish-adapter";
char *script = NULL;
char *wish_exec = "wish";

TBbool is_to_tool_comm(char *s)
{
  return streq(s, "snd-eval") || streq(s, "snd-cancel") || 
    streq(s, "snd-do") || streq(s, "snd-ack-event") ||
    streq(s, "snd-terminate");
}

TBbool is_from_tool_comm(char *s)
{
  return streq(s, "rec-value") ||  streq(s, "rec-event") || streq(s, "rec-disconnect");
}

term *dummy_check_in_sign(term *t)
{
  return NULL;
}

require_fun(char *fname, term_list *fargs)
{
  TBprintf(to_wish, "TBrequire %s %s %d\n", tool_name, fname, list_length(fargs));
}

check_in_sign()
{ char *atf, *tn;
  term *tid;
  term_list *arg;
  extern term_list *tool_in_sign;
  term_list *reqs = tool_in_sign;
  char pat[128];

  /* construct match pattern, e.g. ``%f(<calc>,%l)'' */
  sprintf(pat, "%%f(<%s>, %%l)", tool_name); 

  for(; reqs; reqs = next(reqs)){
    if(TBmatch(first(reqs), pat, &atf, &arg)){
	if(streq(atf, "rec-do") || streq(atf, "rec-eval"))
	  require_fun(get_txt(fun_sym(first(arg))), fun_args(first(arg)));
	else if(streq(atf, "rec-ack-event"))
	  require_fun("rec-ack-event", arg);
	else if(streq(atf, "rec-terminate"))
	  require_fun("rec-terminate", arg);
	else
	  TBmsg("check_in_sign: skipped %t\n", first(reqs));
  } else
	TBmsg("check_in_sign: skipped %t\n", first(reqs));	
  }
}

int bytes_in_term(term *t)
{
  return 8 /* LENSPEC */ + strlen(TBsprintf("%t", t));
}

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

void print_escaped_char(char c)
{
  /* In a string, we just escape the character. */
  char Buf[6];
  int i;
  
  sprintf(Buf, "\\%o", ((unsigned int)c) & 0xFF);
  for(i=0; i<strlen(Buf); i++)
    fputc(Buf[i], to_wish);
}

void printn_wish(const char *s, int n)
{
  static TBbool instring = TBfalse;
  static TBbool prev_escaped = TBfalse;

  while(n){
    if(*s == '"') {
      putc('\\', to_wish);
      if(instring)
	{
	  instring = TBfalse;
	  prev_escaped = TBfalse;
	}
      else
	instring = TBtrue;
    }

    if(instring)
      {
	if(*s == '\\' || *s == '[' || *s == ']')
	  fputc('\\', to_wish);
        prev_escaped = TBfalse;
      }

    if(isprint(*s))
      {
        /* We don't want an octal digit after an escaped number! */
	if(prev_escaped && *s >= '0' && *s <= '7')
	  print_escaped_char(*s++);
	else
	  fputc(*s++, to_wish);
	prev_escaped = TBfalse;
      }
    else
      {
	/* We have a non-printable character */
	print_escaped_char(*s++);
	prev_escaped = TBtrue;
      }

    n--;
  }
}

void pr_term_wish(term *t)
{
  char cbuf[100], *ftxt;

  /* TBprintf(stderr, "Term: %t\n", t);*/
  if(!t){
    printn_wish("{}",2);
    return;
  }
  switch(tkind(t))
    {
    case t_str:
      pr_string_wish(str_val(t), strlen(str_val(t)));
      break;

    case t_bstr:
      pr_string_wish(bstr_val(t), bstr_len(t));
      break;

    case t_bool:
      if(bool_val(t)) 
	printn_wish("true", 4);
      else
	printn_wish("false", 4);
      break;

    case t_int:
      sprintf(cbuf, "%d", int_val(t));
      printn_wish(cbuf, strlen(cbuf));
      break;

    case t_real:
      sprintf(cbuf, "%f", real_val(t));
      printn_wish(cbuf, strlen(cbuf));
      break;

    case t_var: /* Can't occur ??? */
      ftxt = get_txt(var_sym(t));
      printn_wish(ftxt, strlen(ftxt));
      pr_type_wish(var_type(t));
      if(var_result(t))
	printn_wish("?",1);
      break;

    case t_placeholder:
      printn_wish("<",1);
      pr_term_wish(placeholder_type(t));
      printn_wish(">",1);
      break;

    case t_appl:
      ftxt = get_txt(fun_sym(t));
      printn_wish(ftxt, strlen(ftxt));
      if(fun_args(t) != NULL || isupper(ftxt[0])){
	printn_wish("(", 1);
	pr_term_list_wish(fun_args(t), ',');
	printn_wish(")", 1);
      }
      break;

    case t_list:
      printn_wish("{", 1); 
      pr_term_list_wish(t, ' ');
      printn_wish("}", 1);
      break;

    case t_env:
      pr_env(t);
      break;
    }
}

void pr_string_wish(char *s, int len)
{
  fputc('\"', to_wish);
/*  printn_wish("\"", 1);*/
  printn_wish(s, len);
  fputc('\"', to_wish);
/*  printn_wish("\"", 1);*/
}

void pr_type_wish(type *tp)
{
  printn_wish(":", 1); 
  pr_term_wish(tp);
}

void pr_term_list_wish(const term_list *tl, char sep)
{
  TBbool first = TBtrue;

  for( ; tl; tl = next(tl)){
    assert(is_list(tl));    
    if(first)
      first = TBfalse;
    else
      printn_wish(&sep, 1);
    pr_term_wish(first(tl));
  }
}

void pr_env_wish(const env *e)
{
  TBbool first = TBtrue;
  char *ftxt;

  printn_wish("{", 1);
  for( ; e; e = env_next(e)){
    assert(is_env(e));    
    if(first)
      first = TBfalse;
    else
      printn_wish(" ", 1);
    printn_wish("{", 1);
    ftxt = get_txt(env_sym(e));
    printn_wish(ftxt, strlen(ftxt));
    printn_wish(" ", 1);
    pr_term_wish(env_val(e));
    printn_wish("}",1);
  }
  printn_wish("}", 1);
}


print_escaped(term *t)
{
  char *s = TBsprintf("%t", t);
  int c;
  TBbool instring = TBfalse;

  fputc('{', to_wish);
  while(*s){
    c = *s++;
    switch(c){
    case '{': case '}':
      if(!instring)
	fputc('\\', to_wish);
      break;
    case '"':      
      if(instring)
	instring = TBfalse;
      else
	instring = TBtrue;
      break;
    case '\\':
      fputc('\\', to_wish);
      if(*s)
	fputc(*s++, to_wish);
      continue;
    default:;
    }
    fputc(c, to_wish);
  }
  fputc('}', to_wish);
  fputc(' ', to_wish);
}


term *handle_input_from_toolbus(term *e)
{
  term *trm;  

  int pid1, pid2;
  term *Env, *Subs, *Notes, *AtArgs, *Coords;
  char *AtFun;
  char *fname;
  term_list *fargs;
  term *farg;
  term *pe;
  char *mon_point;
  
  /*TBmsg("received %t from toolbus\n", e);*/
  if(TBmatch(e, "rec-monitor(%f(%d,%f,%t,%t,%t,%t,%t,%d,%t))",
		    &mon_point,
	     &pid1, &AtFun, &AtArgs, &Coords,
	     &Env, &Subs, &Notes, &pid2, &pe))
    {

      term_list *ts = Env, *pair, *args;
      term *var;
      char *name, *tname;
      char *filename;
      int blino, bpos, elino, epos;

      /* all monitor commands are generated inside a big catch construct */
      TBprintf(to_wish, "if [catch { ");

      if(!Coords){
	filename = "INIT"; blino=elino=bpos=epos=0;
      } else if(!TBmatch(Coords, "[%s,%d,%d,%d,%d]", 
			 &filename, &blino, &bpos, &elino, &epos))
	TBmsg("**** coords do not match\n");

      if(streq(AtFun, "create")){                   /* create process */
/* TBmsg("create\n"); */
	if(!TBmatch(AtArgs, "[%f(%l), %t]", &name, &args, &var))
	  TBmsg("**** args of create do not match\n");

	TBprintf(to_wish, "create_proc %t %s\n", list_get(Env, var), name);
      } else if(streq(AtFun, "rec-connect")){         /* create tool */  
	int tid;
/* TBmsg("rec-connect\n");     	 */  
	if(!TBmatch(AtArgs, "[%t]", &var))
	  TBmsg("**** args of rec-connect do not match: %t\n", AtArgs);
	if(!TBmatch(get_list_as_env(var, Env), "%f(%d)", &name, &tid)){
	  TBmsg("**** rec-connect: value of var does not match: var=%t, env=%t", var, Env);
	  TBmsg("**** value_list(var, Env) = %t\n", get_list_as_env(var, Env));
	}

	TBprintf(to_wish, "create_tool %d %s\n", tid, name);
      } else if(is_to_tool_comm(AtFun)){            /* any comm to a tool */
	int tid;
/* TBmsg("to_tool\n"); */
	if(!TBmatch(AtArgs, "[%t, %l]", &var, &args))
	  TBmsg("**** args of tool comm do not match:%t\n", AtArgs);
	if(!TBmatch(get_list_as_env(var, Env), "%f(%d)", &name, &tid))
	  TBmsg("**** to_tool: value of var does not match: var=%t, env=%t", var, Env);

	TBprintf(to_wish, "proc_tool_comm %d %d %d\n", pid1, tid, bytes_in_term(args)); 
      } else if(is_from_tool_comm(AtFun)){            /* any comm from a tool */
	int tid;
/* TBmsg("from_tool\n");*/
	if(!TBmatch(AtArgs, "[%t, %l]", &var, &args))
	  TBmsg("**** args of tool comm do not match:%t\n", AtArgs);
	if(!TBmatch(get_list_as_env(var, Env), "%f(%d)", &name, &tid))
	  TBmsg("**** from_tool: value of var does not match: var=%t, env=%t", var, Env);
 
	TBprintf(to_wish, "tool_proc_comm %d %d %d\n", pid1, tid, bytes_in_term(args)); 
      }
            
      if(pid1 > 0){
	for(ts = Env; ts; ts = next(ts)){
	  pair = first(ts);
	if(get_txt(var_sym(first(pair)))[0] != '_')		
	  TBprintf(to_wish, "update_var %d {%t} {%t}\n", 
		   pid1, first(pair), first(next(pair)));
	}
	for(ts = Subs;ts; ts=next(ts)){
	  TBprintf(to_wish, "update_subs %d {%t}\n", pid1, first(ts));  
	}
	for(ts = Notes; ts; ts=next(ts)){
	  TBprintf(to_wish, "update_notes %d {%t}\n", pid1, first(ts));  
	}
      }
   
      if(pid2 > 0){
	int dir = streq(AtFun, "snd-msg") ? 1 : -1;
	TBprintf(to_wish, "proc_proc_comm %d %d %d\n", pid1, pid2, dir);
      }

      if(streq(AtFun, "endlet")){
	if(!TBmatch(AtArgs, "[%l]", &args))
	  TBmsg("**** args of end_let do not match\n");
	for( ; args; args = next(args)){
	  TBprintf(to_wish, "delete_var %d {%t}\n", pid1, first(args));
        }
        /* complete the surrounding catch construct */
        TBprintf(to_wish, "} msg] { TBerror $msg }\n");
	return TBmake("snd-continue(%d)", pid1);
      } else	
        TBprintf(to_wish, "monitor_atom %d %s %s %d %d %d %d\n", 
	       	 pid1, AtFun, filename, blino, bpos, elino, epos);

    /* complete the surrounding catch construct */
    TBprintf(to_wish, "} msg] { TBerror $msg }\n");
/* TBmsg("wish-adapter returns\n"); */
      return NULL;   
    } else if(TBmatch(e, "rec-do(%f(%l))", &fname, &fargs) ||
	      TBmatch(e, "rec-eval(%f(%l))", &fname, &fargs)){
      TBprintf(to_wish, "if [catch {%s ", fname);
      for( ; fargs ; fargs = next(fargs))
	{
	  pr_term_wish(first(fargs));
	  printn_wish(" ", 1);
	}
      TBprintf(to_wish, "} msg] { TBerror $msg }\n");
      return NULL;
    } else if(TBmatch(e, "rec-ack-event(%t)", &farg)){
      TBprintf(to_wish, "if [catch {rec-ack-event {");
      pr_term_wish(farg);
      TBprintf(to_wish, "}} msg] { TBerror $msg }\n");

/*      TBprintf(to_wish, "if [catch {rec-ack-event {%t}} msg] { TBerror $msg }\n", farg);*/
      return NULL;
    } else if(TBmatch(e, "rec-terminate(%t)", &farg)){
      TBprintf(to_wish, "if [catch {rec-terminate {%t}} msg] { TBerror $msg };exit\n", farg);
      exit(0);
    }
    TBmsg("Ignored: %t\n", e);
    return NULL;
}

/* NOTE: in the above code the arguments of ack-event and terminate should be escaped! */
 
term *handle_input_from_wish(term *e)
{
  char *msg;     
           
  /*TBmsg("handle_input_from_wish(%t)\n", e);*/
  if(TBmatch(e, "wish-error(%s)", &msg)){
    TBmsg("wish-error: %s\n", msg);
    return NULL;
  } else if(TBmatch(e,"snd-disconnect")){
    TBsend(e);
    kill(0, SIGKILL);   /* the wish child */
    sleep(1);  /* make sure any incoming data will be consumed */
    exit(0);
  }
  return e;
}

void connect_to_wish(char *script, char *name, TBcallbackTerm handler)
{
  int ui2wish[2];
  int wish2ui[2];
  int pid;
  int old_stdin, old_stdout, from_wish;
  int n_script_args;
  char **p;

  if(pipe(ui2wish) < 0 || pipe(wish2ui) < 0){
    TBmsg("Can't create pipes"); exit(1);
  }
  old_stdin = dup(0);
  old_stdout = dup(1);

  to_wish = fdopen(ui2wish[1], "w");
  from_wish = wish2ui[0];

  close(0); close(1);

  if(dup(ui2wish[0]) < 0 || dup(wish2ui[1]) < 0){
    TBmsg("Can't dup (1)\n"); exit(1);
  }
  if((pid = fork())){
    /* ui: the parent */
    if(pid < 0){
      TBmsg("Can't fork\n"); exit(1);
    }
    close(0); close(1);
    dup(old_stdin);
    dup(old_stdout);
    close(old_stdin);
    close(old_stdout);
    TBprintf(to_wish, "source %s\n", TBTCL);
    TBprintf(to_wish, "set argv {");
    n_script_args = 0;
    for(p = script_args; *p; p++){
      n_script_args++;   
      TBprintf(to_wish, "%s ", *p);
    }  
    TBprintf(to_wish, "}\nset argc %d\n", n_script_args);
    TBprintf(to_wish, "source %s\n", script);
    check_in_sign();
    TBaddTermPort(from_wish, handler);
  } else {
    /* wish: the child */
    if(execlp(wish_exec, name, NULL) < 0){
      TBmsg("Can't execute wish\n");
      exit(1);
    }
  }
}

void help(void)
{
  char * str =
"\n\
Synopsis: wish-adapter [options]\n\
\n\
Options are:\n\
-help                 print this message\n\
-wish Wish            use Wish as wish executable\n\
-lazy-exec            postpone execution of wish until needed\n\
-script Name          use Name as Tcl script for wish\n\
-script-args A1 ...   use A1 ... as arguments for the wish execution\n";
  fprintf(stderr, str);
}

void main(int argc, char *argv[])
{
  int i = 1;
  FILE *f;

  while(i < argc){
    if(streq(argv[i], "-help")){
      help();
    } else if(streq(argv[i], "-TB_TOOL_NAME")){
      name = argv[i+1]; i += 1;
    } else if(streq(argv[i], "-script")){
      script = argv[i+1]; i += 1;
    } else if(streq(argv[i], "-lazy-exec")){
      lazy_exec = TBtrue;
    } else if(streq(argv[i], "-wish")){
      wish_exec = argv[++i];
    } else if(streq(argv[i], "-script-args")){
      script_args = &argv[i+1];
      break;
    }
    i++;
  }
  TBinit(name, argc, argv, handle_input_from_toolbus, dummy_check_in_sign);

  if(!script)
    err_fatal("Missing -script argument");

  if((f = fopen(TBTCL, "r")))
    fclose(f);
  else
    err_sys_fatal("Can't open tcl script: %s", TBTCL);
  if((f = fopen(script, "r")))
    fclose(f);
  else
    err_sys_fatal("Can't open tcl script: %s\n", script);
    
  while(lazy_exec && !TBpeek())
    sleep(1);

  connect_to_wish(script, name, handle_input_from_wish);

  TBeventloop();
}
