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

void exec_cmd(char *);
static char *print_term(term *);

/** Return the representation of a variable
    result of this needs to be free'd
*/
static char *print_var(term* e) {
  char *txt1,*txt2,*result;

  /* Allocate the size of e for the string */
  result = (char *) malloc(TBsize(e)); 
  /* Get the name of the variable */
  txt1 = get_txt(var_sym(e));
  /* Get the sort of the variable */
  txt2 = print_term(var_type(e));
  if(var_result(e)){
    /* If it is a result variable, add a question mark */
    sprintf(result,"%s:%s?",txt1,txt2);
  } else {
    /* If not, print the regular variable representation */
    sprintf(result,"%s:%s",txt1,txt2);
  }
  /* Free txt2, because it was alloc'd in print_term */
  free(txt2);
  /* And return the thing */
  return result;
}

/* Turn an environment into a string. I suspect this is hardly ever
   used. I haven't tested it, and am not sure if this is the way
   emacs-lisp likes to see environments. Currently, they are converted
   to lists. 
   The result of this needs to be free'd later 
*/
static char *print_env(env *e) {
  TBbool first = TBtrue;
  char *result,*tmp;
  
  /* allocate the size of the environment for the result */
  result = (char *) malloc(TBsize(e));
  /* Make result the empty string */
  result[0] = '\0';
  /* Set the start of the list */
  strcat(result,"'(");
  /* while there is still something in the environment */
  while(e != NULL) {
    /* Make sure we _are_ dealing with an environment */
    assert(is_env(e));
    if(first)
      /* we do not print a separator */
      first = TBfalse;
    else {
      /* we do print a separator */
      strcat(result," ");
    }
    /* Print the '(symbol value) tuple */
    strcat(result,"'(");
    strcat(result,get_txt(env_sym(e)));
    strcat(result," ");
    tmp = print_term(env_val(e));
    strcat(result,tmp);
    strcat(result,")");
    /* tmp was malloc'd in print_term */
    free(tmp);
    /* And take the next env from the list */
    e = env_next(e);
  }
  /* Close the whole '(...) tuple list */
  strcat(result,")");
  return result;
}

/** Generic list printer:
    l     -- the list itself
    left  -- the string that starts the list
    sep   -- separates elements of the list
    right -- the string that end the list

    The result of this needs to be free'd later.
*/
static char *print_list(term_list *l, char *left, char *sep, char *right) {
  int i;
  char *result,*tmp;

  /* allocate twice the elements of the list, to allow for the
     separators and left and right. This is a rough guestimate. If sep
     is a huge string, then this will fail, otherwise it probably
     allocates much too much in general. There is room for improvement
     here. */
  result = (char *) malloc(TBsize(l)*2); /* To be on the safe side */
  /*  make result empty */
  result[0] = '\0';
  /* And write the left part of the list */
  strcat(result,left);
  /* loop over the list */
  for(i=1; i<=list_length(l); i++) {
    if(i>1) {
      /* if we're not on the first element, write the separator */
      strcat(result,sep);
    }
    /* print the actual term at this position in the list */
    tmp = print_term(list_index(l, i));
    strcat(result, tmp);
    /* tmp was malloc'd in print_term */
    free(tmp);
  }
  /* And finish with the right side of the list */
  strcat(result,right);
  return result;
}

/** Print any term 
    The result of this function needs to be free'd later
*/
static char *print_term(term* t) {
  char *result,*tmp;
  
  /* Allocate the size of the term for the string */
  result = (char *) malloc(TBsize(t));
  /* make the result empty */
  result[0] = '\0';
  /* Switch to the right type of term */
  switch(tkind(t)) {
    /* It's a string */
  case t_str:
    /* Start the string with a " */
    strcat(result,"\"");
    /* get the actual value, and write it to result, with a " */
    tmp = str_val(t);
    strcat(result,tmp);
    strcat(result,"\"");
    break;
  case t_bstr:
    /* It's a binary string */
    tmp = bstr_val(t);
    strcat(result,tmp);
    break;
  case t_bool:
    /* it's a bool */
    if(bool_val(t) == TBtrue) {
      strcat(result,"true");
    } else {
      strcat(result,"false");
    }
    break;
  case t_int:
    /* It's an integer */
    sprintf(result,"%d", int_val(t));
    break;
  case t_real:
    /* It's a float */
    sprintf(result,"%f", real_val(t));
    break;
  case t_var:
    /* It's a variable */
    tmp = print_var(t);
    strcat(result,tmp);
    /* free tmp, it was malloc'd in print_var */
    free(tmp);
    break;
  case t_placeholder:
    /* it's a placeholder */
    tmp = print_term(placeholder_type(t));
    sprintf(result,"<%s>", tmp);
    /* tmp was malloc'd in print_term */
    free(tmp);
    break;
  case t_appl:
    /* It's an application */
    if(fun_args(t) != NULL) {
      tmp = print_list(fun_args(t), "(", " ", ")");
      sprintf(result,"(%s %s)", get_txt(fun_sym(t)), tmp);
      /* tmp was malloc'd in print_list */
      free(tmp);
    } else {
      sprintf(result,"(%s)", get_txt(fun_sym(t)));
    }
    break;
  case t_list:
    /* It's a list */
    tmp = print_list(t, "(", " ", ")");
    strcat(result, tmp);
    /* tmp was malloc'd in print_list*/
    free(tmp);
    break;
  case t_env:
    /* It's a variable environment */
    tmp = print_env(t);
    strcat(result,tmp);
    /* free tmp, it was malloc'd in print_env */
    free(tmp);
    break;
  }
  return result;
}

/** Print the arguments of an application.
    The result of this function needs to be free'd later
*/
char *print_args(term_list *args) {
  char *result;
  char *tmp;

  /* Allocate the size of the args for result */
  result = (char *) malloc(TBsize(args));
  /* and make it the empty string */
  result[0] = '\0';
  while(args) {
    /* While we still have arguments left */
    if (list_next(args)){
      /* If this is not the last argument, we print the separator */
      tmp = print_term(list_first(args));
      strcat(result,tmp);
      /* tmp was malloc'd in print_term */
      free(tmp);
      strcat(result," ");
    } else {
      /* This is the last argument, no separator after this */
      tmp = print_term(list_first(args));
      strcat(result, tmp);
      /* tmp was malloc'd in print_term */
      free(tmp);
    }
    /* And get the next argument */
    args = list_next(args);
  }
  return result;
}

/** This handles incoming terms from the ToolBus */
term *handle_input_from_toolbus(term *e) {
  term *result;
  term *arg;
  char *fname;
  term_list *fargs;
  char *string,*tmp;

  /* Allocate the size of the term for the command string */
  string = (char *) malloc(TBsize(e));
  /* And make it empty */
  string[0] = '\0';
  
  if(TBmatch(e, "rec-terminate(%t)", &arg)){
    /* Tell emacs to terminate */
    exec_cmd("save-buffers-kill-emacs");
    /* And follow that example */
    exit(0);
  } else if(TBmatch(e, "rec-ack-event(%t)", &fname)){
    /* Acknowledgment accepted. we do not pass it to emacs, at the moment */
    result = NULL;
  } else if(TBmatch(e, "rec-do(%f(%l))", &fname, &fargs)){  
    /* Tell emacs to do something */
    /* Build a "function arglist" string for emacs lisp */
    tmp = TBsprintf("%f", fname);
    strcat(string,tmp);
    strcat(string," ");
    tmp = print_args(fargs);
    strcat(string,tmp);
    /* tmp was malloc'd in print_args */
    free(tmp);
    /* And exec it */
    exec_cmd(string);
    result = NULL;
  } else if(TBmatch(e, "rec-eval(%f(%l))", &fname, &fargs)){  
    /* Tell emacs to do something: eval is identical to do. We do not
       enforce currently that something is indeed being sent
       back. This is up to the user. */
    /* Build a "function arglist" string for emacs lisp */
    tmp = TBsprintf("%f", fname);
    strcat(string,tmp);
    strcat(string," ");
    tmp = print_args(fargs);
    strcat(string,tmp);
    /* tmp was malloc'd in print_args */
    free(tmp);
    /* And exec it */
    exec_cmd(string);
    result = NULL;
  }
  free(string);
  return result;
}

/** Tell emacs to exec the cmd */
void exec_cmd(char *cmd) {
  /* Since emacs listens to stdout, we can just print with brackets */
  fprintf(stdout,"(%s)\n",cmd);
  fflush(NULL);
}

/** Handle terms coming from emacs */
term *handle_input_from_emacs(term *e) {
  /* we have no interest here but to pass it along to the ToolBus */
  return e;
}

int main(int argc, char *argv[]) {
  char string[80];      /* for the init commands */
  char *name = NULL;    /* The name of the adapter told to the ToolBus*/
  char *initfile = NULL;/* The e-lisp file to be loaded initially */ 
  int new_stdin;        /* The fd into which stdin gets dupped */
  int i = 1;            /* Counter for cmdline arguments */
  
/* If we connect stdin as file descriptor 0 then the ToolBus behaves
   completely different from when it is another number... :-( Therefore
   we dup() it into something else.  
*/
  new_stdin = dup(STDIN_FILENO);
  if ((fcntl(new_stdin, F_SETFD, (long) 0)) == -1) {
    fprintf(stderr,"Unsetting close-on-exec on stdin failed\n");
  }

  /* Handle the relevant cmdline arguments */
  while(i < argc){
    if(streq(argv[i], "-initfile")) {
      i++;
      initfile = argv[i];
    } else if(streq(argv[i], "-TB_TOOL_NAME")) {
      i++;
      name = argv[i];
    }
    i++;
  } 


  /* Now init the TB library, and add a port that listens to our dupped
     stdin.
  */
  TBinit(name, argc, argv, handle_input_from_toolbus, NULL);
  TBaddTermPort(new_stdin, handle_input_from_emacs); 

  /* Tell emacs about LENSPEC and MIN_MSG_SIZE */
  sprintf(string,"set-lenspec %d",LENSPEC);
  exec_cmd(string);
  sprintf(string,"set-minmsgsize %d",MIN_MSG_SIZE);
  exec_cmd(string);  
  /* If there is an initfile */
  if (initfile != NULL) {
    /* Tell emacs about it */
    sprintf(string, "load-file \"%s\"", initfile);
    exec_cmd(string);
  } 
  
/* And start the main event loop */
  TBeventloop();

  /* To keep gcc happy */
  return 0;
}

