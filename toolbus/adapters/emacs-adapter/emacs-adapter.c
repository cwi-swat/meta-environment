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

#define MAXARG 20           /* # of args per command */
#define MAXCMD 1024         /* max length of command */

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
    print_term(list_first(args));
    if (list_next(args))
      strcat(cmd_buf," ");
    args = list_next(args);
  }
}

term *handle_input_from_toolbus(term *e) {
  term *result;
  term *arg;
  char *fname;
  term_list *fargs;
  
  /*  TBprintf(stderr, "Get term from toolbus: %t", e);*/
  /*    printf("In handle_input\n");*/
  /* rec-terminate appears to fail sometimes. So far, it only fails when 
     the ToolBus is run in regular mode. If it runs in -viewer mode 
     rec-terminate appears to work well. 
  */
  if(TBmatch(e, "rec-terminate(%t)", &arg)){
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
  int r;       /* Return value of wait()'ing for child process to terminate */
  int status;  /* The status of the child process */
  int cmd_pid; /* The pid of the child process */

  gnuc_func = cmd_buf;

#ifdef 0  
  if ((cmd_pid = fork())) {
    /* This is the parent process */
    if (cmd_pid < 0)
      err_sys_fatal("Can't fork");
  } else {
    /* This is the chid process */
    if (execlp(gnuclient, gnuclient, gnuc_flag1, gnuc_flag2, gnuc_func, NULL) < 0 ) {
      err_sys_fatal("Can't execute %s", gnuclient);
    }
  }

  /* We need to sleep here for some time, in order to prevent execs
     following each other too rapidly. This is obviously not the most
     elegant solution. So far it appears to work. Timing is still
     experimental, though. */
  
  usleep((long)1000);

  /*while ((r = wait(&status)) != cmd_pid && r != 0)
    fprintf(stderr, "wait = %d\n", r);  
*/
#endif
  fprintf(stdout,"(%s)\n",gnuc_func);
  fflush(NULL);
}

term *handle_input_from_emacs(term *e) {
  /*  TBprintf(stderr,"term from emacs: %t\n", e);*/
  return e;
}

/* #include <signal.h>*/
/*
void interrupt_handler(int sig){
  kill(0, SIGKILL);
  exit(-1);
}
*/

void help(void) {
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
-gnuclient file       use file as gnuclient. Default is gnuclient\n\
-initfile file        load e-lisp file file before accepting commands\n\
                      from the ToolBus";
  fprintf(stderr, str);
}

int main(int argc, char *argv[]) {
  char *name = "text-edit"; /* The name of the adapter told to the ToolBus*/
/* This name needs to be parameterized, obviously... */
  int new_stdin;        /* The fd into which stdin gets dupped */
  
  /*  signal(SIGINT, interrupt_handler);
  signal(SIGKILL, interrupt_handler);
  signal(SIGTERM, interrupt_handler);
  */

/* stdin gets closed on the following exec. Therefor we dup() it. The 
   dupped fd is identical (also stdin), but it is not closed on exec.
*/
  new_stdin = dup(STDIN_FILENO);
  if ((fcntl(new_stdin, F_SETFD, (long) 0)) != -1) {
    /*    fprintf(stderr,"**********THE FD COMING FROM EMACS IS: %d *************************************\n",new_stdin);*/
  } else {
    fprintf(stderr,"Unsetting close-on-exec on stdin failed\n");
  }

  /* fprintf(stderr,"The value of the fcntl flags of stdin: %d\n", fcntl(new_stdin, F_GETFL));*/
 
 
 

  /* Tell emacs about LENSPEC and MIN_MSG_SIZE */
  sprintf(cmd_buf,"set-lenspec %d", LENSPEC);
  exec_cmd();
  sprintf(cmd_buf,"set-minmsgsize %d", MIN_MSG_SIZE);
  exec_cmd();  
 
/* Now init the TB libarary, and add a port that listens to our dupped
   stdin.
*/
  TBinit(name, argc, argv, handle_input_from_toolbus, NULL);
  TBaddTermPort(new_stdin, handle_input_from_emacs); 
  
/* And start the main event loop */
  TBeventloop();

  /* To keep gcc happy */
  return 0;
}

