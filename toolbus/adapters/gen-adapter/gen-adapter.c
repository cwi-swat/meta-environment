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
 * gen-adapter -- Generic adapter for ToolBus <-> cmd connection
 *
 * Synopsis: gen-adapter [-cmd C1 C2 ...]
 *
 * where C1 C2 ... is the default command (including arguments) to be invoked.
 *
 * Author:       Paul Klint, March, 1994
 * Last updated: March 1995.
 *
 * Purpose: Generic adapter for arbitrary command
 * tools that transform their standard input into
 * standard output. The tool is invoked for each "rec-eval"
 * request coming from the ToolBus,i.e.
 *
 *    rec-eval(cmd("wc", input("a b")))  will
 *    - execute wc as child process
 *    - write "a b" to the child's standard input
 *    - wait for completion of P
 *    - read P's standard output
 *    - return: snd-value(output(Text))
 *      where text is C's standard output
 * Caveats:
 *    - i/o redirection is currently done using files
 *    - the output of the command is limited to MAXOUTPUT bytes
 *
 * Architecture:
 *
 *         ================== ToolBus
 *           |           ^
 *           v           |    (sockets)
 *         +---------------+
 *         |  gen-adapter  |
 *         +---------------+
 *           |           ^
 *           |           |
 *           |  +------+ |
 *           +->| cmd  |-+    (standard input/output)
 *              +------+
 *
 * Fri Apr 28 09:17:18 MET DST 1995: <P>
 * - Added possibility to send binary strings instead of just text.
 * Wed May 17 13:12:05 MDT 1995: paulk
 * - Added -help
 * Mon May  3 17:10:40 MET DST 1999: mdejonge
 *   added -term_output and -string_output command line options to specify
 *  output format. string_output is the default output type.
 *
 */

/*}}}  */

/*{{{  includes */

#include "TB.h"
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <signal.h>

/*}}}  */

/*{{{  defines */

#define MAXARG 20           /* # of args per command */
#define MAXCMD 1024         /* max length of command */
#define MAXOUTPUT 10000     /* max size of output of executed cmd */

/*}}}  */

/*{{{  variables */

int cmd_pid;                /* process ID of cmd process */
char *tmp_in  ="tmp_in";    /* temp file name for cmd input */
char *tmp_out = "tmp_out";  /* temp file name for cmd output */

char *cmd[MAXARG];          /* command array for exec */
char **def_cmd = NULL;      /* default command array */
char **the_cmd;             /* current command array */
char cmd_buf[MAXCMD];       /* copy of command with ' ' replaced by '\0' */
TBbool keepnewline = TBfalse;
TBbool addnewline = TBfalse;
TBbool obinary = TBfalse;

/*}}}  */

enum  _output_type{tb_string, tb_bstring, tb_term } output_type = tb_string;

void exec_cmd(char *, int);

/* Split a string into separate strings as needed by exec */

/*{{{  void split_args(char *s) */

void split_args(char *s)
{
  int i = 0;
  char *cp = cmd_buf;

  if(strlen(s) > MAXCMD)
    err_fatal("Command too long");

  cmd[i] = cp;

  while(*s){
    if(*s == ' '){
      *cp++ = '\0';
      if(i == MAXARG)
	err_fatal("Command has too many arguments");
      i++;
      cmd[i] = cp;
    } else
      *cp++ = *s;
    s++;
  } 
  *cp = '\0';

  cmd[i+1] = NULL;
}

/*}}}  */

/*{{{  term *handle_input_from_toolbus(term *e) */

term *handle_input_from_toolbus(term *e)
{
  char *txt, *cmd_txt, output[MAXOUTPUT], *outp;
  int n, len, r, status;
  FILE *from_cmd;
  term *arg;

  outp = output;

  if(TBmatch(e, "rec-terminate(%t)", &arg)){
    unlink(tmp_in);
    unlink(tmp_out);
    exit(0);
  } else if(TBmatch(e, "rec-eval(cmd(%s,input(%s)))", &cmd_txt, &txt)){  
    split_args(cmd_txt);
    the_cmd = cmd;
    len = strlen(txt);
    goto exec_cmd;
  } else if(TBmatch(e, "rec-eval(input(%s))", &txt)){
    the_cmd = def_cmd;
    len = strlen(txt);
    goto exec_cmd;
  } else if(TBmatch(e, "rec-eval(input-term(%t))", &arg)) {
    the_cmd = def_cmd;
    txt = TBsprintf("%t", arg);
    len = strlen(txt);
    goto exec_cmd;
  } else if(TBmatch(e, "rec-eval(input(%b))", &txt, &len)){
    the_cmd = def_cmd;
exec_cmd:

    if(addnewline)
      txt[len++] = '\n';

    exec_cmd(txt, len);    
    while ((r = wait(&status)) != cmd_pid && r != -1)
      fprintf(stderr, "wait = %d\n", r);  

    if((from_cmd = fopen(tmp_out, "rb")) == NULL)
      err_sys_fatal("Can't open tmp output file");

    /* Mon May  3 17:36:12 MET DST 1999 mdejonge
     *
     * When output type != tb_term, we read the output of the  command that
     * we executed (stored in the file tmp_out) as string. When output type
     * equals tb_term, we use TBreadTerm to read (and parse) the contents of
     * that file to obtain an term. 
     *
     * NOTE: With the new aterm library we would probably have used the function
     * ATparse to obtain an aterm from a string.
     *
     */
    if( output_type != tb_term )
    {
      while((n=fread(outp, 1, 512, from_cmd)) > 0){
	if(outp + n > &output[MAXOUTPUT]) 
	  err_fatal("Executed command produces too long output");
	outp += n;
      }
      if(*(outp-1) == '\n' && !keepnewline) {
	if(output_type == tb_bstring)
	  outp--;
	else
	  *(outp-1) = '\0';
      } else {
	if(output_type != tb_bstring)
	  *outp++ = '\0';
      }
      fclose(from_cmd);
      switch( output_type )
      {
	case tb_bstring:
	  return TBmake("snd-value(output(%b))", output, outp-output);
	case tb_string:
	  return TBmake("snd-value(output(%s))", output);
	case tb_term:
	  return NULL;
      }
    }
    else
    {
      /* Mon May  3 17:36:12 MET DST 1999 mdejonge
       *
       * Construct a term from the contents of the file tmp_out by using
       * the function TBreadTerm.
       */
      term *t;
      t = TBreadTerm( from_cmd );
      fclose(from_cmd );
      return TBmake( "snd-value(output(%t))", t );
    }

  } 
  TBmsg("Ignore: %t\n", e);
  return NULL;
}

/*}}}  */

#define READ 0
#define WRITE 1

/*{{{  void exec_cmd(char *inp, int len) */

void exec_cmd(char *inp, int len)
{
  int old_stdin, old_stdout, fd_to_cmd;

  old_stdin = dup(0);
  old_stdout = dup(1);

  if((fd_to_cmd = creat(tmp_in, 0777)) < 0)
    err_sys_fatal("Can't create tmp input file");
  if(write(fd_to_cmd, inp, len) < 0)
    err_sys_fatal("Can't write to tmp input file");
  if(close(fd_to_cmd) < 0)
    err_sys_fatal("Can't close tmp input file");

  close(0); close(1);

  if(open(tmp_in, O_RDONLY) < 0)
    err_sys_fatal("Can't open tmp input file");
  if(creat(tmp_out, 0777) < 0)
    err_sys_fatal("Can't create tmp output file");

  if((cmd_pid = fork())){
    /* adapter: the parent */
    if(cmd_pid < 0)
      err_sys_fatal("Can't fork");
    close(0); close(1);
    dup(old_stdin);
    dup(old_stdout);
    close(old_stdin);
    close(old_stdout); 
  } else {
    /* cmd: the child */
    if(execvp(the_cmd[0], the_cmd) < 0)
      err_sys_fatal("Can't execute %s", the_cmd[0]);
  }
}

/*}}}  */

/*{{{  void interrupt_handler(int sig) */

void interrupt_handler(int sig)
{
  unlink(tmp_in);
  unlink(tmp_out);
  kill(0, SIGKILL);  /* is this drastic?? */
  /*  kill(cmd_pid, SIGKILL); */
  /*  kill(cmd_pid+1, SIGKILL); */
  exit(-1);
}

/*}}}  */

/*{{{  void help(void) */

void help(void)
{
  char * str =
    "\n\
    Synopsis: gen-adapter [options]\n\
    \n\
    Options are:\n\
    -help                 print this message\n\
    -keepnewline          keep last newline of output generated by command\n\
    -addnewline           add newline to standard input for command\n\
    -binary-output        represent output as binary string\n\
    -string-output        represent output as ordinary string (default)\n\
    -term-output          represent output as toolbus term\n\
    -cmd C1 ...           use C1 ... as the default command to execute\n";
  fprintf(stderr, str);

  exit(0);
}

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  int i = 1;
  char *name = "gen-adapter";

  while(i < argc){
    if(streq(argv[i], "-help") || streq(argv[i], "-h")){
      help();
    } else if(streq(argv[i], "-keepnewline")){
      keepnewline = TBtrue;
    } else if(streq(argv[i], "-addnewline")){
      addnewline = TBtrue;
    } else if(streq(argv[i], "-binary-output")){
      output_type = tb_bstring;
    } else if(streq(argv[i], "-term-output")){
      output_type = tb_term;
    } else if(streq(argv[i], "-string-output")){
      output_type = tb_string;
    } else if(streq(argv[i], "-cmd")){
      def_cmd = &argv[i+1];
      break;
    }
    i++;
  } 

  signal(SIGINT, interrupt_handler);
  signal(SIGKILL, interrupt_handler);
  signal(SIGTERM, interrupt_handler);
  tmp_in = tempnam(NULL, name); 
  tmp_out = tempnam(NULL, name);

  TBinit(name, argc, argv, handle_input_from_toolbus, NULL);
  TBeventloop();
  return 0;
}

/*}}}  */
