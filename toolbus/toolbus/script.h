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

