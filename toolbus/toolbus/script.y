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
%{
#include "toolbus.h"
#include "terms.h"
#include "env.h"                
#include "procs.h"               
#include "match.h"
#include "tools.h"            
#include "utils.h"
#include "typecheck.h"
#include "interpreter.h"
#include "script.h"
#include <fcntl.h>

extern int yyparse(void);
extern int yylex(void);
extern int get_token(int);

term *script_name = NULL;  /* term representing source file */
int lino = 1;              /* line number in source file */
int pos = 0;               /* position in line */

/* Switch to other source file (used to implement preprocessor
   directives of the form:
   # n name
 */

void switch_source(char *name, int n)
  {
    script_name = mk_str(name);
    lino = n;
  }

/* Create temporary name with appropriate suffix */

#define ABS_PATH_MAX 1024   /* guess max abs path name */

char *TBtmpname(char *name, char *suf)
  {
    char *tmp = getenv("TMPDIR");
    if(!tmp)
      tmp = "/var/tmp";
    sprintf(name, "%s/TB%d%s", tmp, (int) getpid(), suf);
    if(strlen(name) >= ABS_PATH_MAX)
      err_fatal("TBtmpname: name `%s' too long", name);
    return name;
  }

/* First preprocess script from file `name' and then parse it.
   Note: for portability reasons, the C preprocessor should be called with
   a file ending on `.c'. Therefore we first copy the input script `name.tb' 
   to a file `name.tb.c' and use that as input for cpp.
*/

#define CMD_MAX 1024
#define PP_LINE_MAX 1024

TBbool parse_script(char *name, int argc, char **argv)
{ int org_stdin, pres;
  char cmd[CMD_MAX], namec[ABS_PATH_MAX], namei[ABS_PATH_MAX], line[PP_LINE_MAX];
  FILE *fnamec, *fname;
  int i;
  TBbool in_string = TBfalse;
   
  /* Open original file */
  if((fname = fopen(name, "rb")) == NULL)
    err_sys_fatal("cannot open file `%s'", name);

  /* Create a copy of it */

  TBtmpname(namec, ".c");
  TBtmpname(namei, ".i");
  
  if((fnamec = fopen(namec, "wb")) == NULL)
    err_sys_fatal("cannot create temp file `%s' for preprocessor", namec);

  fprintf(fnamec, "# 1 \"%s\"\n", name);  /* set original file name */

  /* Copy original file. Remove comments to avoid possible lexical
     errors because the comment conventions in T scripts and C programs
     are different.
     */

  while(fgets(line, PP_LINE_MAX, fname)){
    char *cp;

    for(cp = line; *cp; cp++){
      if(in_string){             /* inside string constant */
	if(*cp == '"') {
	  in_string = TBfalse;
	} else if(*cp == '\\')
	  cp++;
      } else if(*cp == '"'){     /* start of string constant */
	  in_string = TBtrue;
      } else if(cp[0] == '%'){
	if(cp[1] == '%'){        /* %% style comment */
	  *cp++ = '\n'; *cp++ = '\0';
	  break;
	} 
      }
    }
    fputs(line, fnamec);
  }
  fputs("\n", fnamec);           /* make sure file ends on newline character */
  fclose(fname);
  fclose(fnamec);

  /* Construct the command cpp command. Any -D or -I arguments from
     the toolbus command line are passed to cpp. (They define
     macro definitions and include directories)
   */

  strcpy(cmd, CPP); strcat(cmd, " ");
  for(i = 1; i < argc; i++){
    if((argv[i][0] == '-') && ((argv[i][1] == 'I') || (argv[i][1] == 'D'))){
      strcat(cmd, argv[i]);
      strcat(cmd, " ");
    }
  }
  strcat(cmd, namec);
  strcat(cmd, ">");
  strcat(cmd, namei);

  if(strlen(cmd) >= CMD_MAX)
    err_fatal("parse_script: command too long");

  /* Now execute cpp */

  if(system(cmd) != 0){
    remove(namec);
    remove(namei);
    err_sys_fatal("errors during execution of C preprocessor");
  }

  org_stdin = dup(0); /* disguise fd_script as stdin */
  close (0);

  if(open(namei, O_RDONLY) < 0)
    err_sys_fatal("cannot open intermediate file %s created by C preprocessor");
  
  lino = 1;
  pos = 0;
  pres = yyparse();  /* at last, the actual parse */

  remove(namec);
  remove(namei);

  close(0);
  dup(org_stdin);  /* restore old stdin */
  
  return (pres == 0) ? TBtrue : TBfalse;
}

/* every non-terminal yields its begin and end coordinates
 * as four tuple (lino, pos, elino, epos). The following macro's
 * expect:
 * - res  (in all cases $$ of the current rule)
 * - b, e (the rule element, e.g. $i, defining the desired values)
 */

#define range(res,b,e)  res.lino = b.lino; res.pos = b.pos;\
                      res.elino = e.elino; res.epos = e.epos;
#define empty_range(res) res.lino = res.elino = lino; res.pos = res.epos = pos;


/* Name of the current process or tool definition */
char *current_def_name = "";

/*------------------ Management of scopes ----------------------*/

/* During parsing of the T script we maintain:                  */
/* - current_formals: fixed list of formal parameters for       */
/*                    current process definition                */
/* - current_vars:    dynamic set of local variables, which is  */
/*                    extended by each new let construct        */
/* - current_scopes:  a list of nested scopes, needed to remove */
/*                    variables when leaving a let construct    */

/* parameter list of current definition */
term_list *current_formals = NULL;

/* list of variables declared in current definition */
term_list *current_vars = NULL;

#define MAX_SCOPE      128
term_list *current_scopes[MAX_SCOPE];
int n_scope = 0;

void new_scope(term_list *locals)
{
  current_scopes[n_scope] = current_vars;
  if(n_scope == MAX_SCOPE)
    err_fatal("More than %d nested scopes", MAX_SCOPE);
  n_scope++;
  current_vars = list_concat(list_copy(locals), current_vars);
}

void old_scope(void)
{
  n_scope--;
  if(n_scope < 0)
    err_fatal("Illegal nesting of scopes");
  current_vars = current_scopes[n_scope];
}
/*------------------------------------------------------------*/
                          
/* process applications in toolbus configuration
 * (used by create_toolbus)
 */
proc *initial_toolbus_proc;

term *assign_var(char *str, int lino)
{ term_list *tl;
  term *t;
 
  for(tl = current_vars; tl; tl = next(tl)){
    if(streq_unres(str, get_txt(var_sym(first(tl))))){
      return mk_result_var(str, current_def_name, var_type(first(tl)));
    }
  }          
  for(tl = current_formals; tl; tl = next(tl)){
    if(streq_unres(str, get_txt(var_sym(first(tl))))){		       
      t = mk_result_var(str, current_def_name, var_type(first(tl)));
      var_formal(t) = TBtrue;
      if(!var_result(first(tl)))
	tc_ill_result("variable", str, script_name, lino);
      return t;
    }
  }
  tc_not_decl("variable", str, script_name, lino);
  return mk_result_var(str, current_def_name, Term);
}

term *use_var(char *str, int lino)
{ term_list *tl;
  term *t;

  for(tl = current_vars; tl; tl = next(tl)){
    if(streq_unres(str, get_txt(var_sym(first(tl))))){
      return first(tl);
    }
  }
  for(tl = current_formals; tl; tl = next(tl)){
    if(streq_unres(str, get_txt(var_sym(first(tl))))){
      t = mk_var(str,current_def_name, var_type(first(tl)));
      var_formal(t) = TBtrue;
      return t;
    }
  }
  tc_not_decl("variable", str, script_name, lino);
  return mk_var(str, current_def_name, Term);
}               

%}

%token INT    
%token REAL
%token STRING
%token IDENT
%token SND_MSG                   
%token REC_MSG                   
%token SND_NOTE                  
%token REC_NOTE
%token NO_NOTE
%token SUBSCRIBE
%token UNSUBSCRIBE   
%token PRINTF          
%token READ   
%token REC_EVENT                 
%token SND_ACK_EVENT
%token SND_EVAL    
%token SND_CANCEL              
%token SND_DO                    
%token REC_VALUE
%token TOOLBUS                   
%token PROCESS
%token IS
%token CREATE
%token REC_CONNECT
%token REC_DISCONNECT
%token EXECUTE
%token SND_TERMINATE
%token SHUTDOWN
%token IF
%token THEN
%token ELSE
%token FI
%token ASSIGN
%token FMERGE
%token REL_DELAY
%token ABS_DELAY
%token REL_TIMEOUT
%token ABS_TIMEOUT
%token LET
%token IN
%token ENDLET
%token TYPE
%token NAME
%token DELTA
%token TAU                  
%token TOOL    
%token HOST
%token COMMAND     
%token DETAILS
%token DETAILS_STRING             

%start script    /* Start symbol of the grammar */

%left FMERGE
%left '+'                        
%right '.'                       
%left '*'                        
 
%%

term : INT                       { $$.u.term =  mk_int(atoi($1.u.string)); free($1.u.string); }
     | REAL                      { $$.u.term =  mk_real(atof($1.u.string)); free($1.u.string); }
     | STRING                    { $$.u.term =  mk_str($1.u.string); free($1.u.string); }
     | var
     | result_var
     | IDENT                     { $$.u.term = mk_appl(TBlookup($1.u.string),NULL); free($1.u.string);}
     | IDENT '(' term_list ')'   { $$.u.term = mk_appl(TBlookup($1.u.string), $3.u.term_list);
                                   range($$,$1,$4);
				   free($1.u.string);
                                 }    
     | '[' term_list ']'         { $$.u.term_list = $2.u.term_list; range($$,$1,$3);}
     | '<' type '>'              { $$.u.term = mk_placeholder($2.u.term); range($$,$1,$3); }
     ;

result_var : NAME '?'            { $$.u.term = assign_var($1.u.string, $1.lino);
                                   range($$,$1,$2);
				   free($1.u.string);
                                 }
    ;

var :  NAME                      { $$.u.term = use_var($1.u.string, $1.lino);
                                   range($$,$1,$1);
				   free($1.u.string);
                                 } 
    ;

term_list:
       /* empty */               { $$.u.term_list = NULL; empty_range($$);}
    |
       term                      { $$.u.term_list = mk_list1($1.u.term);}
     | term ',' term_list        { $$.u.term_list = mk_list($1.u.term, $3.u.term_list);
                                   range($$,$1,$3);
                                 }
     ;

atom: comm_atom | note_atom | tool_atom | delta_tau | create | read_print | assign | shutdown;

comm_atom:
       SND_MSG '(' term_list ')'
         { $$.u.proc =
           mk_atom(a_snd_msg, $3.u.term_list, 
		   mk_coords(script_name, $1.lino, $1.pos, $4.elino, $4.epos));
           range($$,$1,$4);
         }
     | REC_MSG '(' term_list ')'
         { $$.u.proc =
           mk_atom(a_rec_msg, $3.u.term_list,
		   mk_coords(script_name, $1.lino, $1.pos, $4.elino, $4.epos));
           range($$,$1,$4);
         } 
     ;

note_atom:   
       SUBSCRIBE '(' term ')'
         { $$.u.proc =
           mk_atom(a_subscribe, mk_list1($3.u.term),
		   mk_coords(script_name, $1.lino, $1.pos, $4.elino, $4.epos));
           range($$,$1,$4);
         }
     | UNSUBSCRIBE '(' term ')'
         { $$.u.proc =
           mk_atom(a_unsubscribe, mk_list1($3.u.term), 
		   mk_coords(script_name, $1.lino, $1.pos, $4.elino, $4.epos));
           range($$,$1,$4);
         }
     | SND_NOTE '(' term ')'
         { $$.u.proc =
            mk_atom(a_snd_note, mk_list1($3.u.term),
		    mk_coords(script_name, $1.lino, $1.pos, $4.elino, $4.epos));
           range($$,$1,$4);
         }
     | REC_NOTE '(' term ')'
         { $$.u.proc =
           mk_atom(a_rec_note, mk_list1($3.u.term), 
		   mk_coords(script_name, $1.lino, $1.pos, $4.elino, $4.epos));  
           range($$,$1,$4);
         }
     | NO_NOTE '(' term ')'
         { $$.u.proc =
           mk_atom(a_no_note, mk_list1($3.u.term), 
		   mk_coords(script_name, $1.lino, $1.pos, $4.elino, $4.epos));
           range($$,$1,$4); 
         }
     ;

tool_atom:
       REC_CONNECT '(' result_var ')'
         { $$.u.proc =
           mk_atom(a_rec_connect, mk_list1($3.u.term),
		   mk_coords(script_name, $1.lino, $1.pos, $4.elino, $4.epos));
           range($$,$1,$4);
           tc_tool_atom($$.u.proc);
         }
     | REC_DISCONNECT '(' term_list ')'
         { $$.u.proc =
           mk_atom(a_rec_disconnect, $3.u.term_list, 
		   mk_coords(script_name, $1.lino, $1.pos, $4.elino, $4.epos));
           range($$,$1,$4);
           tc_tool_atom($$.u.proc);
         }  
     | SND_TERMINATE '(' term_list ')'
         { $$.u.proc =
           mk_atom(a_snd_terminate, $3.u.term_list,
		   mk_coords(script_name, $1.lino, $1.pos, $4.elino, $4.epos));
           range($$,$1,$4);
           tc_tool_atom($$.u.proc);
         }

     | REC_EVENT '(' term_list ')'
         { $$.u.proc =
           mk_atom(a_rec_event, $3.u.term_list,
		   mk_coords(script_name, $1.lino, $1.pos, $4.elino, $4.epos));
           range($$,$1,$4);
           tc_tool_atom($$.u.proc);
         }
     | SND_ACK_EVENT '(' term_list  ')'
         { $$.u.proc =
           mk_atom(a_snd_ack_event, $3.u.term_list,
		   mk_coords(script_name, $1.lino, $1.pos, $4.elino, $4.epos));
           range($$,$1,$4);
           tc_tool_atom($$.u.proc);
         }
     | SND_EVAL '(' term_list')'
         { $$.u.proc =
           mk_atom(a_snd_eval, $3.u.term_list,
		   mk_coords(script_name, $1.lino, $1.pos, $4.elino, $4.epos));
           range($$,$1,$4);
           tc_tool_atom($$.u.proc);
         }   
     | SND_CANCEL '(' term_list ')'
         { $$.u.proc =
           mk_atom(a_snd_cancel, $3.u.term_list,
		   mk_coords(script_name, $1.lino, $1.pos, $4.elino, $4.epos));
           range($$,$1,$4);
           tc_tool_atom($$.u.proc);
         }   
     | SND_DO '(' term_list  ')'
         { $$.u.proc =
           mk_atom(a_snd_do, $3.u.term_list,
		   mk_coords(script_name, $1.lino, $1.pos, $4.elino, $4.epos));
           range($$,$1,$4);
           tc_tool_atom($$.u.proc);
         }    
     | REC_VALUE '(' term_list  ')'
         { $$.u.proc =
           mk_atom(a_rec_value, $3.u.term_list,
		   mk_coords(script_name,  $1.lino, $1.pos, $4.elino, $4.epos));
           range($$,$1,$4);
           tc_tool_atom($$.u.proc);
         }
     ;

delta_tau:
      DELTA
         { $$.u.proc =
           mk_atom(a_delta, NULL, 
		   mk_coords(script_name, $1.lino, $1.pos, $1.elino, $1.epos)); 
         }   
     | TAU
         { $$.u.proc =
           mk_atom(a_tau, NULL,
		   mk_coords(script_name, $1.lino, $1.pos, $1.elino, $1.epos));
         }
     ;
create:
       CREATE '(' NAME actuals ',' result_var ')'
         { $$.u.proc =
           mk_create($3.u.string, $4.u.term_list, $6.u.term,
		     mk_coords(script_name, $1.lino, $1.pos, $7.elino, $7.epos));
           tc_create($$.u.proc);
           range($$,$1,$7);
	   free($3.u.string);
         }
     ;
read_print:
       PRINTF '(' term_list ')'
         { $$.u.proc =
           mk_atom(a_printf, $3.u.term_list, 
		   mk_coords(script_name, $1.lino, $1.pos, $4.elino, $4.epos));
           range($$,$1,$4);
           tc_printf($$.u.proc);
         }
     | READ '(' term_list ')'
         { $$.u.proc =
           mk_atom(a_read, $3.u.term_list, 
		   mk_coords(script_name, $1.lino, $1.pos, $4.elino, $4.epos));
           range($$,$1,$4);
         }

shutdown:
       SHUTDOWN '(' term ')'
         { $$.u.proc =
           mk_atom(a_shutdown, mk_list1($3.u.term),
		   mk_coords(script_name, $1.lino, $1.pos, $4.elino, $4.epos));
           range($$,$1,$4);
         }
     ;

assign:
        NAME ASSIGN term
         { var *v = assign_var($1.u.string, $1.lino);
           $$.u.proc =
           mk_atom(a_assign, mk_list2(v, $3.u.term), 
		   mk_coords(script_name, $1.lino, $1.pos, $3.elino, $3.epos));
           tc_assign($$.u.proc);
           range($$,$1,$3);
	   free($1.u.string);
         }
     ;
   
proc : atom          { $$.u.proc = $1.u.proc; range($$,$1,$1); }
     | atom REL_DELAY '(' term ')'
         { $$.u.proc = mk_timer($1.u.proc, p_delay, $4.u.proc, p_no_timeout, NULL);
           range($$,$1,$5);
         }
     | atom REL_DELAY '(' term ')' REL_TIMEOUT '(' term ')' 
         { $$.u.proc = mk_timer($1.u.proc, p_delay, $4.u.proc, p_timeout, $8.u.proc);
           range($$,$1,$9);
         } 

     | atom ABS_DELAY '(' term_list ')'
         { $$.u.proc = mk_timer($1.u.proc, p_abs_delay, $4.u.proc, p_no_timeout, NULL);
           range($$,$1,$5);
         }

     | atom ABS_DELAY '(' term_list ')' ABS_TIMEOUT '(' term_list ')'  
         { $$.u.proc = mk_timer($1.u.proc, p_abs_delay, $4.u.proc, p_abs_timeout, $8.u.proc);
           range($$,$1,$9);
         }                                   
     | atom REL_TIMEOUT '(' term ')'  
         { $$.u.proc = mk_timer($1.u.proc, p_no_delay, NULL, p_timeout, $4.u.proc);
           range($$,$1,$5);
         }   
     | atom ABS_TIMEOUT '(' term_list ')' 
         { $$.u.proc = mk_timer($1.u.proc, p_no_delay, NULL, p_abs_timeout, $4.u.proc);
           range($$,$1,$5);
         }   
     | proc '+' proc  { $$.u.proc = mk_plus($1.u.proc, $3.u.proc); range($$,$1,$3); }
     | proc '.' proc  { $$.u.proc = mk_dot($1.u.proc,$3.u.proc); range($$,$1,$3); }   
     | proc '*' proc  { $$.u.proc = mk_star($1.u.proc,$3.u.proc);  range($$,$1,$3); }   
     | proc FMERGE proc  { $$.u.proc = mk_fmerge($1.u.proc,$3.u.proc);  range($$,$1,$3); }   
     | '(' proc ')'   { $$.u.proc = $2.u.proc; range($$,$1,$3); }
     | proc_call
     | let
     | IF term THEN proc FI
         { $$.u.proc = mk_if($2.u.term,$4.u.proc,NULL); range($$,$1,$5);
           tc_cond($2.u.term, mk_coords(script_name, $2.lino, $2.pos, $2.elino, $2.epos));
         }
     | IF term THEN proc ELSE proc FI
         { $$.u.proc = mk_if($2.u.term,$4.u.proc,$6.u.proc); range($$,$1,$7);
           tc_cond($2.u.term, mk_coords(script_name, $2.lino, $2.pos, $2.elino, $2.epos));
         }

     | EXECUTE '(' term ',' result_var ')'
         { $$.u.proc = mk_execute($3.u.term, $5.u.term, 
				  mk_coords(script_name, $1.lino, $1.pos, $6.elino, $6.epos));
           tc_execute($$.u.proc);
           range($$,$1,$6);
         }
     ;     

proc_call :
       NAME actuals
         { $$.u.proc =  mk_proc_call($1.u.string,$2.u.term_list);
           tc_call(current_def_name, $$.u.proc, 
		   mk_coords(script_name, $1.lino, $1.pos, $2.elino, $2.epos));
           range($$,$1,$2);
	   free($1.u.string);
         }
     ;

actuals:
       '(' term_list ')'     { $$.u.term_list = $2.u.term_list; range($$,$1,$3); }
     |   
                             { $$.u.term_list = NULL; empty_range($$); }
     ;
                                   
formals:
       '(' form_list ')'     { $$.u.term_list = current_formals = $2.u.term_list; range($$,$1,$3); }
     |
                             { $$.u.term_list = current_formals = NULL; empty_range($$); }
     ;

opt_result:
       '?'                   { $$.u.bool = TBtrue; }
     | /* empty */           { $$.u.bool = TBfalse; }
     ;
form_decl:
       NAME ':' type opt_result        
                             { $$.u.term = mk_formal($1.u.string, current_def_name, $3.u.term);
                               var_result($$.u.term) = $4.u.bool;
			       free($1.u.string);
                             }

form_list:   
       form_decl             { $$.u.term_list =  mk_list1($1.u.term); range($$,$1,$1); }     
     | form_decl ',' form_list
                             { $$.u.term_list =  mk_list($1.u.term, $3.u.term_list);
                               range($$,$1,$3);
                             }
     ;

type:
      term                   { $$.u.term = $1.u.term; }
     ;


var_decl:
       NAME ':' type         { $$.u.term = mk_var($1.u.string, current_def_name, $3.u.term); free($1.u.string);}

var_list:   
       var_decl              { $$.u.term_list =  mk_list1($1.u.term); range($$,$1,$1); }     
     | var_decl ',' var_list
                             { $$.u.term_list =  mk_list($1.u.term, $3.u.term_list);
                               range($$,$1,$3);
                             }
     ;

let  : let_head let_tail     
       { $$.u.proc = 
         mk_let($1.u.term_list,		       
		mk_dot($2.u.proc, 
		       mk_atom(a_endlet, $1.u.term_list, 
			       mk_coords(script_name, $2.lino, $2.pos, $2.elino, $2.epos))));
       }

let_head:
       LET var_list IN       { $$.u.term_list = $2.u.term_list;
                               check_let_vars(current_formals, current_vars, $2.u.term_list, script_name, $1.lino);
                               new_scope($2.u.term_list);
                               range($$,$1,$3); 
                             }
     ;

let_tail:
       proc ENDLET           { $$.u.proc = $1.u.proc; old_scope(); range($$,$2,$2); }
     ;

proc_def_name:
       PROCESS NAME          { $$.u.string = current_def_name = $2.u.string; range($$,$1,$2);}
     ;

proc_def:
       proc_def_name formals IS proc
     
         { add_proc_def($1.u.string, current_formals, current_vars, $4.u.proc, script_name, $1.lino);
	   free(current_def_name);
           current_def_name = "";
           current_formals = NULL;
           current_vars = NULL;
           range($$,$1,$4);
         }

host:
       HOST '=' STRING         { $$.u.string = $3.u.string; range($$,$1,$3); }
     |                         { $$.u.string = ""; empty_range($$); } 
     ;

command:
       COMMAND '=' STRING      { $$.u.string = $3.u.string; }
     |                         { $$.u.string = ""; empty_range($$); } 
     ;

details:
       DETAILS '=' DETAILS_STRING
         { $$.u.string = $3.u.string; range($$,$1,$3); }
     |
         { $$.u.string = ""; empty_range($$);}
     ;

tool_def_name:
      TOOL IDENT               { $$.u.string = current_def_name = $2.u.string; range($$,$1,$2); }

tool_def:       
     tool_def_name formals IS '{' host command details '}'
         { add_tool_def($1.u.string, $2.u.term_list, $5.u.string,
                    $6.u.string, $7.u.string, script_name, $1.lino);
	   free(current_def_name);
	   current_def_name = "";
	   if(strlen($5.u.string) > 0)
	     free($5.u.string);
	   if(strlen($6.u.string) > 0)
	     free($6.u.string);
	   if(strlen($7.u.string) > 0)
	     free($7.u.string);
           range($$,$1,$8);
         } 
     ;                        

def_list:
       /* empty */            { empty_range($$); }
     | proc_def def_list      { range($$, $1, $2); }
     | tool_def def_list      { range($$, $1, $2); }
     ;

proc_call_in_tb :
       NAME actuals
         { $$.u.proc =
           mk_create($1.u.string, $2.u.term_list, mk_result_var("Pid", "INIT", Int),
		     mk_coords(script_name, $1.lino, $1.pos, $2.elino, $2.epos));
           tc_create($$.u.proc);
           range($$,$1,$2);
	   free($1.u.string);
         }
     ;

proc_call_in_tb_list:
       proc_call_in_tb
     | proc_call_in_tb ',' proc_call_in_tb_list 
         { $$.u.proc = mk_dot($1.u.proc, $3.u.proc); range($$,$1,$3); }

toolbus:
       TOOLBUS '(' proc_call_in_tb_list ')'
         { $$.u.proc = $3.u.proc; range($$,$1,$4); }            
     ;

script:
       def_list toolbus
         { initial_toolbus_proc = $2.u.proc; range($$,$1,$2); }
     ;
%%

#if 0
#include "lex.yy.c"
#endif

void yyerror(char *s)
{
  err_fatal("\"%t\", line %d: %s, near %s", script_name, lino, s,
        get_token(yychar));
}

#ifndef HAVE_YYWRAP
int yywrap()
{
  return 1;
}
#endif
