#ifndef __script_h__
#define __script_h__
extern int lino;
extern int pos;

#include "tools.h"
#include "procs.h"


/*--- Yacc stack type --------------------------*/

typedef struct {
  int lino;
  int pos;
  int elino;
  int epos;
  union {        /* Union of types that   */
  char      *string;   /* appear on parse stack */
  TBbool    bool;
  tkind     tk;
  term      *term;
  char      *id;
  term_list *term_list;
  proc      *proc;
  proc_def  *proc_def;
  } u;
} yystype;

#define YYSTYPE yystype   /* Yacc stack entries */
extern YYSTYPE yylval;

void yyerror(char*);
#endif

