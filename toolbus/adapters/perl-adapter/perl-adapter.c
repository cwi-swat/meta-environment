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

/*{{{  schematic overview */

/*
 * perl-adapter -- Generic adapter for ToolBus <-> perl connection
 *
 * Synopsis: perl-adapter [-name N] [-script S]
 *
 * where N is a toolname (only used by TBmsg)
 * and   S is a name of Perl script to be executed
 *
 * Author: Paul Klint, Februari, 1995
 *
 * Purpose: pass term coming from ToolBus to perl, i.e.
 *
*    do(xx,print-text(3))  ==> do print_text(3)
 *
 * where receiveTB is a function defined in the Perl script
 * capable of interpreting its argument and executing
 * application dependent tcl functions as needed.
 *
 *
 * Architecture:
 *
*         ================== ToolBus
*           |           ^
*           v           |    (sockets)
*         +---------------+
*         | perl-adapter  |
*         +---------------+
*           |           ^
*           |           |
*           |  +------+ |
*           +->| perl |-+    (standard input/output)
*              +------+
 * 
 * Wed May 17 13:12:05 MDT 1995: paulk
 * - Added -help
 */

/*}}}  */

/*{{{  includes */

#include "TB.h"
#include <unistd.h>
#include <signal.h>

/*}}}  */

/*{{{  variables */

FILE *to_perl;  /* file descriptor connected to std input of perl */
term *tname = NULL;
char tmpname[512] = "perl-adapterXXXXXX";

/*}}}  */

/*{{{  void unlink_tmp(void) */

void unlink_tmp(void)
{ 
  remove(tmpname);
}

/*}}}  */

/*{{{  void print_escaped(term *t) */

void print_escaped(term *t)
{
  char *s = TBsprintf("%t", t);
  int c;
  TBbool instring = TBfalse;

  fputc('"', to_perl);
  while(*s){
    c = *s++;
    switch(c){
      case '"':      
	if(instring)
	  instring = TBfalse;
	else
	  instring = TBtrue;
	break;
      case '\n':
	fputc('\\', to_perl); fputc('n', to_perl);
	continue;
      case '\\':
	fputc('\\', to_perl);
	if(*s)
	  fputc(*s++, to_perl);
	continue;
      default:;
    }
    fputc(c, to_perl);
  }
  fputc('"', to_perl);
  fputc(' ', to_perl);
}

/*}}}  */
/*{{{  void print_fun_name(FILE *fout, char *s) */

void print_fun_name(FILE *fout, char *s)
{
  while(*s){
    if(*s == '-')
      fputc('_', fout);
    else
      fputc(*s, fout);
    s++;
  }
}

/*}}}  */

/*{{{  void require_fun(FILE *ftmp, char *fname, term_list *fargs) */

void require_fun(FILE *ftmp, char *fname, term_list *fargs)
{
  TBprintf(ftmp, "if(! defined &");
  print_fun_name(ftmp, fname);
  TBprintf(ftmp, "){print STDERR \"%s: *** WARNING: subroutine ", tool_name);
  print_fun_name(ftmp, fname);
  TBprintf(ftmp, " (with %d arguments) is missing\\n\";}\n",
	   list_length(fargs));
}

/*}}}  */
/*{{{  void check_in_sign(FILE *ftmp) */

void check_in_sign(FILE *ftmp)
{
  char *atf;
  term_list *arg;
  extern term_list *tool_in_sign;
  term_list *reqs = tool_in_sign;
  char pat[128];

  /* construct match pattern, e.g. ``%f(<calc>,%l)'' */
  sprintf(pat, "%%f(<%s>, %%l)", tool_name); 

  for(; reqs; reqs = next(reqs)){
    if(TBmatch(first(reqs), pat, &atf, &arg)){
      if(streq(atf, "rec-do") || streq(atf, "rec-eval"))
	require_fun(ftmp, get_txt(fun_sym(first(arg))), fun_args(first(arg)));
      else if(streq(atf, "rec-ack-event"))
	require_fun(ftmp, "rec-ack-event", arg);
      else if(streq(atf, "rec-terminate"))
	require_fun(ftmp, "rec-terminate", arg);
      else
	TBmsg("check_in_sign: skipped %t\n", first(reqs));
    } else
      TBmsg("check_in_sign: skipped %t\n", first(reqs));	
  }
}

/*}}}  */

/*{{{  term *handle_input_from_toolbus(term *e) */

term *handle_input_from_toolbus(term *e)
{
  term *fargs, *farg;
  char *fname, *sep = "";

  if(TBmatch(e, "rec-do(%f(%l))", &fname, &fargs) ||
     TBmatch(e, "rec-eval(%f(%l))", &fname, &fargs)){

    TBprintf(to_perl, "do ");
    print_fun_name(to_perl, fname);
    TBprintf(to_perl, "(");    
    for( ; fargs ; fargs = next(fargs)){
      TBprintf(to_perl, "%s", sep);
      sep = ",";
      print_escaped(first(fargs));
    }
    TBprintf(to_perl, ");\n");
    return NULL;
  } else if(TBmatch(e, "rec-ack-event(%t)", &farg)){
    TBprintf(to_perl, "do rec_ack_event(");
    print_escaped(farg);
    TBprintf(to_perl, ");\n");
    return NULL;
  } else if(TBmatch(e, "rec-terminate(%t)", &farg)){
    TBprintf(to_perl, "do rec_terminate(");
    if(farg)
      print_escaped(farg);
    else
      TBprintf(to_perl, "\"\"");
    TBprintf(to_perl, ");\n");
    sleep(1);
    unlink_tmp();
    kill(0, SIGKILL);
    exit(0);
  }
  TBmsg("IGNORED: %t\n", e);
  return NULL;
}

/*}}}  */
/*{{{  term *handle_input_from_perl(term *e) */

term *handle_input_from_perl(term *e)
{
  char *msg;

  if(TBmatch(e, "perlerror(%s)", &msg)){
    TBmsg("perl-error: %s\n", msg);
    return NULL;
  }
  return e;
}

/*}}}  */

/*{{{  void copy_file(FILE *fout, char *name) */

void copy_file(FILE *fout, char *name)
{
  FILE *f;
  char line[512];

  if((f = fopen(name, "rb")) == NULL)
    err_sys_fatal("Can't open `%s'", name);

  while(fgets(line, 512, f) != NULL){
    /* fputs(line, stderr); */
    fputs(line, fout);
  }
  fclose(f);
}

/*}}}  */
/*{{{  void connect_to_perl(char *script, TBcallbackTerm handler) */

void connect_to_perl(char *script, TBcallbackTerm handler)
{
  int ui2perl[2];
  int perl2ui[2];
  int pid;
  int old_stdin, old_stdout, from_perl;
  int fd;
  FILE *ftmp;

  fd = mkstemp(tmpname);
  if (fd == -1) {
    perror("mkstemp");
    exit(1);
  }
  ftmp = fdopen(fd, "w");
  if (ftmp == NULL) {
    perror("fdopen");
    exit(1);
  }

  copy_file(ftmp, script);
  copy_file(ftmp, TBPERL);
  check_in_sign(ftmp);
  fprintf(ftmp, "do TBcomm();\n");
  fclose(ftmp);

  if(pipe(ui2perl) < 0 || pipe(perl2ui) < 0)
    err_sys_fatal("Can't create pipes");
  old_stdin = dup(0);
  old_stdout = dup(1);

  to_perl = fdopen(ui2perl[1], "w");
  from_perl = perl2ui[0];

  close(0); close(1);

  if(dup(ui2perl[0]) < 0 || dup(perl2ui[1]) < 0)
    err_sys_fatal("Can't dup (1)");
  if((pid = fork())){
    /* ui: the parent */
    if(pid < 0)
      err_sys_fatal("Can't fork");
    close(0); close(1);
    dup(old_stdin);
    dup(old_stdout);
    close(old_stdin);
    close(old_stdout);
    TBaddTermPort(from_perl, handler);
  } else {
    /* perl: the child */
    if(execlp("perl", "perl", tmpname, NULL) < 0)
      err_sys_fatal("Can't execute perl");
  }
}

/*}}}  */
/*{{{  void help(void) */

void help(void)
{
  char * str =
    "\n\
    Synopsis: perl-adapter [options]\n\
    \n\
    Options are:\n\
    -help                 print this message\n\
    -script Name          use Name as Perl script\n";
  fprintf(stderr, str);

  exit(0);
}

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  int i = 1;
  char *name = "perl-adapter";
  char *script = "script";
  FILE *f;

  while(i < argc){    
    if(streq(argv[i], "-help") || streq(argv[i], "-h")){
      help();
    } else if(streq(argv[i], "-script")){
      script = argv[i+1];
      i++;
    }
    i++;
  }
  TBinit(name, argc, argv, handle_input_from_toolbus, NULL);

  if((f = fopen(script, "r")))
    fclose(f);
  else
    err_sys_fatal("Can't open perl script `%s'", script);

  tname = TBmake(name);
  connect_to_perl(script, handle_input_from_perl);
  TBeventloop();
  unlink_tmp();
  return 0;
}

/*}}}  */
