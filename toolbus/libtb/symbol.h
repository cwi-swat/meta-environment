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
#ifndef SYMBOL_H
#define SYMBOL_H

sym_idx TBlookup(char *);
sym_idx lookupn(char *, char *);
int register_module(char *name);
char *get_txt(sym_idx);

#define SYMDEF(str,sym) idx = TBlookup(str); assert(idx == sym)

typedef struct name_bucket {
  struct name_bucket *nb_next;   /* PK: renamed from next to nb_next to avoid
				    name clashes with the next macro defined
				    in terms.h */
  char *name;
  sym_idx id;
  short type;
  short module;
  union {
    struct expr_sign *sig;
  } u;
} name_bucket;

#define IDT_ALL        -1
#define IDT_INTERNAL    0
#define IDT_MODULE      1
#define IDT_EXPR_FUN    2

#define IDM_ALL        -1
#define IDM_INTERNAL	0

extern name_bucket *hash_table[];
extern name_bucket *idx_table[];

typedef struct expr_sign {
  sym_idx name;
  type   *restype;
  TBbool evargs;
  TBbool chkargs;
  int    nargs;
  type   **argtype;
  term *(*func)(int, term **, term *);
  char *descr;
} expr_sign;

struct expr_sign *get_expr_sign(sym_idx sym);
sym_idx register_function(char *name, sym_idx module, expr_sign *sig);
sym_idx register_func(char *name, sym_idx module, type *restype, TBbool eval,
		      TBbool chkargs, int nargs, type *args[], 
		      term *(*fn)(int, term **, term *), char *descr);
/* register functions with 0, 1, 2, or 3 arguments respectively. */
sym_idx register_func0(char *name, sym_idx module, type *restype,
		       term *(*fn)(int, term **, term *), char *descr);
sym_idx register_func1(char *name, sym_idx module, type *restype, TBbool eval,
		       type *arg, term *(*fn)(int, term **, term *), 
		       char *descr);
sym_idx register_func2(char *name, sym_idx module, type *restype, TBbool eval,
		       type *a1, type *a2, term *(*fn)(int, term **, term *),
		       char *descr);
sym_idx register_func3(char *name, sym_idx module, type *restype, TBbool eval,
		       type *a1, type *a2, type *a3, 
		       term *(*fn)(int, term **, term *), char *descr);
TBbool is_expr_fun(term *T);

void system_init_module();

#endif
