/* $Id$

   Emacs adapter. Chunks in this file are stolen by Tobias Kuipers either from
   the gen-adapter or the wish-adapter. Thanks: Pieter Olivier, Paul Klint,
   Merijn de Jonge.
*/

#include "TB.h"
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

int cmd_pid;                /* process ID of cmd process */
char *tmp_in  ="tmp_in";    /* temp file name for cmd input */
char *tmp_out = "tmp_out";  /* temp file name for cmd output */
static pid_t  pgid                 = -1;

#ifndef TBEL
#define TBEL "tb.el"        /* The location of the TB lisp file. Should
			       be overridden in Makefile */
#endif
#define MAXARG 20           /* # of args per command */
#define MAXCMD 1024         /* max length of command */
#define MAXOUTPUT 10000     /* max size of output of executed cmd */

char *gnuclient = "gnuclient"; /* The name of the gnuclient executable */
char *gnuc_flag1 = "-batch";
char *gnuc_flag2 = "-f";          
char *gnuc_func; /* command array for exec */

char **def_cmd = NULL;      /* default command array */
char **the_cmd;             /* current command array */
char cmd_buf[MAXCMD];       /* copy of command with ' ' replaced by '\0' */
char tmp[1024];
TBbool keepnewline = TBfalse;
TBbool addnewline = TBfalse;
TBbool obinary = TBfalse;

void exec_cmd(void);
static void print_term(term *);

static void print_var(term* e) {
    char* txt;
    txt = get_txt(var_sym(e));
    strcat(cmd_buf,txt);
    strcat(cmd_buf,":");
    print_term(var_type(e));
    if(var_result(e))
	strcat(cmd_buf,"?");
}

static void print_env(env* e) {
    TBbool first = TBtrue;
    char* txt;
    
    strcat(cmd_buf,"\"");
    while(e != NULL) {
	assert(is_env(e));
	if(first)
	    first = TBfalse;
	else
	    strcat(cmd_buf," ");
	txt = get_txt(env_sym(e));
	strcat(cmd_buf,txt);
	strcat(cmd_buf," ");
	print_term(env_val(e));
	e = env_next(e);
    }
    strcat(cmd_buf,"\"");
}

static void print_list(term_list* l, char* left, char* sep, char* right) {
    int i;
    strcat(cmd_buf,left);
    for(i=1; i<=list_length(l); i++) {
	if(i>1) {
	    strcat(cmd_buf,sep);
	}
	print_term(list_index(l, i));
    }
    strcat(cmd_buf,right);
}

static void print_term(term* t) {
    switch(tkind(t)) {
    case t_str:
	strcat(cmd_buf,"\"");
	strcat(cmd_buf,str_val(t));
	strcat(cmd_buf,"\"");
	break;
    case t_bstr:
	strcat(cmd_buf,bstr_val(t));
	break;
    case t_bool:
	if(bool_val(t) == TBtrue) {
            strcat(cmd_buf,"true");
	} else {
            strcat(cmd_buf,"false");
	}
	break;
    case t_int:
         sprintf(tmp,"%d", int_val(t));
	 strcat(cmd_buf,tmp);
         break;
      case t_real:
         sprintf(tmp,"%f", real_val(t));
	 strcat(cmd_buf,tmp);
         break;
      case t_var:
         print_var(t);
         break;
      case t_placeholder:
         strcat(cmd_buf,"<");
         print_term(placeholder_type(t));
         strcat(cmd_buf,">");
         break;
      case t_appl:
         strcat(cmd_buf,"(");
	 sprintf(tmp,"%s", get_txt(fun_sym(t)));
	 strcat(cmd_buf,tmp);
         if(fun_args(t) != NULL)
            print_list(fun_args(t), "(", " ", ")");
         break;
      case t_list:
         print_list(t, "(", " ", ")");
         break;
      case t_env:
         print_env(t);
         break;
   }
}

void print_args(term_list *args) {
    while(args) {
	/*	if(!is_list(list_first(args)))
	    	    wprintf(""); */
	print_term(list_first(args));
	/*	if(!is_list(list_first(args)))
		wprintf("}");*/
	strcat(cmd_buf," ");
	args = list_next(args);
    }
}

term *handle_input_from_toolbus(term *e) {
    char output[MAXOUTPUT], *outp;
    int n;
    FILE *from_cmd;
    term *result;
    term *arg;
    char *fname;
    term_list *fargs;
    
    outp = output; 
    
    /*    printf("In handle_input\n");*/
    /* rec-terminate appears to fail sometimes. So far, it only fails when 
       the ToolBus is run in regular mode. If it runs in -viewer mode 
       rec-terminate appears to work well. 
    */
    if(TBmatch(e, "rec-terminate(%t)", &arg)){
      unlink(tmp_in);
      unlink(tmp_out);
      /*	printf("Matched rec-terminate\nCurrently disabled for debugging purposes\n"); */
      cmd_buf[0] = '\0';
      strcat(cmd_buf,"save-buffers-kill-emacs");
      exec_cmd();
      exit(0);
    } else if(TBmatch(e, "rec-ack-event(%t)", &fname)){
      result = NULL;
    } else if(TBmatch(e, "rec-do(%f(%l))", &fname, &fargs)){  
      /* empty commandbuffer */
      cmd_buf[0] = '\0';
      /*    printf("Matched rec-do\n");*/
      strcat(cmd_buf,fname);
      strcat(cmd_buf," ");
      print_args(fargs);
      exec_cmd();
      result = NULL;
    } else if(TBmatch(e, "rec-eval(%f(%l))", &fname, &fargs)){  
      /* empty commandbuffer */
      cmd_buf[0] = '\0';
      /*    printf("Matched rec-eval\n");*/
      strcat(cmd_buf,fname);
      strcat(cmd_buf," ");
      print_args(fargs);
      exec_cmd();
      result = NULL;
  }
  return result;
}

void exec_cmd(void) {
  int old_stdin, old_stdout, fd_to_cmd, r, status;
  printf("Args are: %s\n", cmd_buf);
  gnuc_func = cmd_buf;
  
  old_stdin = dup(0);
  old_stdout = dup(1);
  /*  fprintf(stderr,"Just dup'd stdio\n");*/
  
  if((fd_to_cmd = creat(tmp_in, 0777)) < 0)
    err_sys_fatal("Can't create tmp input file");
  /*if(write(fd_to_cmd, inp, len) < 0)
    err_sys_fatal("Can't write to tmp input file");
  */
  if(close(fd_to_cmd) < 0)
    err_sys_fatal("Can't close tmp input file");
  
  close(0); close(1);
  
  /*  fprintf(stderr,"Just closed i and o\n");*/
  
  if(open(tmp_in, O_RDONLY) < 0)
    err_sys_fatal("Can't open tmp input file");
  
  if(creat(tmp_out, 0777) < 0)
    err_sys_fatal("Can't create tmp output file");
  
  /*  fprintf(stderr, "Opened tmp out\n");*/
  if ((cmd_pid = fork())) {
    /*    fprintf(stderr,"Just forked (says main)\n");*/
    /*sleep(2);*/
    if (cmd_pid < 0)
      err_sys_fatal("Can't fork");
    close(0); close(1);
    dup(old_stdin);
    dup(old_stdout);
    close(old_stdin);
    close(old_stdout); 
  } else {
    /*    fprintf(stderr,"Just forked (says forked process)\n");*/
    if (execlp(gnuclient, gnuclient, gnuc_flag1, gnuc_flag2, gnuc_func, NULL) < 0 ) {
      /*      fprintf(stderr,"execlp failed\n");*/
      err_sys_fatal("Can't execute %s", gnuclient);
    }
  }
  while ((r = wait(&status)) != cmd_pid && r != -1)
    fprintf(stderr, "wait = %d\n", r);  

  /*  fprintf(stderr,"Finished exec_cmd\n");*/
}

static term *handle_input_from_emacs(term *e) {
  /*  TBprintf(stderr,"term from emacs: %t\n", e);*/
  return e;
}

#include <signal.h>

void interrupt_handler(int sig){
  unlink(tmp_in);
  unlink(tmp_out);
  kill(0, SIGKILL);  /* is this drastic?? */
  /*  kill(cmd_pid, SIGKILL); */
/*  kill(cmd_pid+1, SIGKILL); */
  exit(-1);
}

void help(void)
{
  char * str =
"\n\
**** Make sure your .emacs file contains the line\n\
\n\
(gnuserv-start)\n\
\n\
Synopsis: emacs-adapter [options]\n\
\n\
Options are:\n\
-help                 print this message\n\
-emacs file           use file as emacs. Default is xemacs\n\
-gnuclient file       use file as gnuclient. Default is gnuclient\n";
  fprintf(stderr, str);
}

void emacs_create(char *emacsapp) {
  /* char init_cmd[128];*/
  /*  int r, status;*/
  pid_t pid;
  FILE *from_emacs;

  /*  int   pipe_tw[2]; toolbus 2 wish */
  int   pipe_et[2]; /* emacs to toolbus */
   
  /*  if( pipe( pipe_tw ) < 0 )
      error( "pipe" );
  */
  if( pipe( pipe_et ) < 0 )
    err_sys_fatal( "failed to create pipe" );
  
  pid = fork();
  switch( pid ) {
  case 0:
    /* In child */
    if(setpgid(0, 0) == -1)
      err_sys_fatal( "Couldn't setpgid");
    /*    dup2(pipe_tw[0], 0);*/
    /* We are connecting this pipe to the standard err of emacs. Not the
       standard out, as you would assume. This is because I don't get 
       emacs to write chars to stdout. Perhaps someone who _does_ speak
       e-lisp can take a look at it */
    dup2(pipe_et[1], 2);
         
    /*    close(pipe_tw[1]);*/
    close(pipe_et[0]);
         
    execlp(emacsapp, "Help! I'm trapped inside emacs!", NULL);
    fprintf(stderr, "%s: execlp: %s\n", emacsapp, strerror(errno));
    exit(1);
    break; /* Just to keep lint happy */
  case -1:
    err_sys_fatal("Couldn't fork");
    break; /* Again, to keep lint happy */
  default:
    if(pgid == -1)
      pgid = pid;
    /* This should be a bit more clean. The idea is that we want to wait 
       for the child process (emacs) to start. After this, we should be
       able to run gnuclient, i.e. emacs must have run gnuserv-start
    */
    sleep(30);
    /* Make sure emacs loads tb.el */
    sprintf(cmd_buf,"load-file \"");
    strcat(cmd_buf,TBEL); /* TBEL is location of tb.el file from Makefile*/
    strcat(cmd_buf,"\"");
    exec_cmd();
    /* Tell emacs about LENSPEC and MIN_MSG_SIZE */
    sprintf(cmd_buf,"set-lenspec %d", LENSPEC);
    exec_cmd();
    sprintf(cmd_buf,"set-minmsgsize %d", MIN_MSG_SIZE);
    exec_cmd();
    from_emacs = fdopen(pipe_et[0], "r");
    close(pipe_et[1]);
    TBaddTermPort(pipe_et[0], handle_input_from_emacs);
    return;
  }
}

void main(int argc, char *argv[])
{
  int i = 1;
  char *name = "emacs-adapter";
  char *emacsapp = "xemacs";
  /*  int old_stdout;*/
  /*  int fd_from_emacs;*/

  while(i < argc){
    if(streq(argv[i], "-help")){
      help();
    } else if(streq(argv[i], "-emacs")){
	i++;
	emacsapp = argv[i];
    } else if(streq(argv[i], "-gnuclient")){
	i++;
	gnuclient = argv[i];
    }
    i++;
  } 

  signal(SIGINT, interrupt_handler);
  signal(SIGKILL, interrupt_handler);
  signal(SIGTERM, interrupt_handler);
  tmp_in = tempnam(NULL, name); 
  tmp_out = tempnam(NULL, name);

  TBinit(name, argc, argv, handle_input_from_toolbus, NULL);
  emacs_create(emacsapp);
  TBeventloop();
}

