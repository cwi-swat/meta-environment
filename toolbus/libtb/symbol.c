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
#include "toolbus.h"
#include "terms.h"
#include "symbol.h"
#include "procs.h"
#include "tools.h"
#include "utils.h"

/* We use a hash-table to map names to id's. Every symbol also has
   a module number, to make it easy to find the module in which a
   function is implemented, and optionally a function that implements
   the symbol when it is an expression or action.
*/

/* Take a prime number as hash-table size */
#define NAME_TABLE_SIZE	5009
#define MAXNAME NAME_TABLE_SIZE*2

/* static sym_idx n_name = 0; */

/*static char *name_table[MAXNAME];*/

/* Create a hash table initialized to 0. */
static name_bucket *hash_table[NAME_TABLE_SIZE] = { NULL };
static name_bucket *idx_table[MAXNAME];
static sym_idx ID = 0;

/* Calculate the hash index */
static unsigned hash_it(char *n)
{
  unsigned i, nr = n[0];

  for(i=1; n[i]; i++) {
    /* For now, we just try a simple xor hash function. */
    nr ^= n[i];
  }
  return nr % NAME_TABLE_SIZE; 
}

/* Retrieve the bucket address of a symbol, updating it's module
   when necessary. */
static name_bucket *lookup_bucket(char *name, sym_idx module)
{
  name_bucket *cur;
  unsigned nr = hash_it(name);

  cur = hash_table[nr];
  while(cur && !streq(cur->name, name)) {
    cur = cur->nb_next;
  }
  if(cur) {
    /* Newer definitions override older ones */
    /* except when module is ALL or INTERNAL. */
    if(module != IDM_ALL && module != IDM_INTERNAL)
      cur->module = module; 
    return cur;
  }

  /* if module == IDM_ALL, we are looking for an existing bucket! */
  if(module == IDM_ALL)
    return NULL;

  if(ID == MAXNAME)
    /* We might want to just 'realloc'ate more space for names */
    err_fatal("lookup -- too many names");

  cur = malloc(sizeof(name_bucket));
  cur->nb_next = hash_table[nr];
  hash_table[nr] = cur;
  cur->name = strdup(name);
  idx_table[ID] = cur;
  cur->id = ID++;
  /* Module type defaults to system_module */
  if(module == IDM_ALL)
    cur->module = system_module;
  else
    cur->module = module;
  cur->u.sig = NULL;

  return cur;
}

/* Lookup the index of symbol ``name'', if undefined add it to name_table */
/* and allocate a fresh copy of name */
sym_idx TBlookup(register char *name)
{
  name_bucket *b = lookup_bucket(name, IDM_INTERNAL);
  assert(b);
  return b->id;
}

sym_idx lookupn(register char *bgn, register char *end)
{ char name[256];
  register char *s = name;

  if(end - bgn > 256)
    err_fatal("lookupn -- name too long");

  while(bgn < end)
    *s++ = *bgn++;
  *s = '\0';
  return TBlookup(name); 
}

/* Retrieve the textual representation of a symbol */
char *get_txt(sym_idx idx)
{
  if(idx >= 0 && idx < ID) {
    assert(idx_table[idx]);
    return idx_table[idx]->name;
  }
  err_fatal("get_txt -- illegal index");
  return NULL;
}

/* Retrieve the signature of an expression function */
struct expr_sign *get_expr_sign(sym_idx sym)
{
  name_bucket *bucket;

  assert(sym >= 0 && sym < ID);
  bucket = idx_table[sym];
  assert(bucket);

  if(bucket->type == IDT_EXPR_FUN)
    return bucket->u.sig;
  return NULL;
}

/* Register a new module. */
sym_idx register_module(char *name)
{
  name_bucket *bucket = lookup_bucket(name, system_module);

  bucket->type = IDT_MODULE;
  return bucket->id;
}

/* Frontend for register_func function. */
sym_idx register_function(char *name, sym_idx module, expr_sign *sig)
{
  name_bucket *bucket = lookup_bucket(name, module);
  
  bucket->type = IDT_EXPR_FUN;
  sig->name = bucket->id;
  bucket->u.sig = sig;

  return bucket->id;
}

/* Register a function so the ToolBus can typecheck and evaluate it. */
sym_idx register_func(char *name, sym_idx module, type *restype, TBbool eval, 
		      TBbool chkargs, int nargs, type *args[], 
		      term *(*func)(int, term **, term *), char *descr)
{
  int i;

  expr_sign *sig = malloc(sizeof(expr_sign));
  sig->restype   = restype;
  sig->evargs    = eval;
  sig->chkargs   = chkargs;
  sig->nargs     = nargs;
  if(nargs)
    sig->argtype = malloc(sizeof(type *)*nargs);
  else
    sig->argtype = NULL;
  for(i=0; i<nargs; i++)
    sig->argtype[i] = args[i];
  sig->func      = func;
  sig->descr     = strdup(descr);
  return register_function(name, module, sig);
}

/* Register a function with 0 arguments. */
sym_idx register_func0(char *name, sym_idx module, type *restype,
		       term *(*fn)(int, term **, term *), char *descr)
{
  return register_func(name, module, restype, TBfalse, TBtrue, 0, NULL, fn, descr);
}

/* Register a function with 1 argument. */
sym_idx register_func1(char *name, sym_idx module, type *restype, TBbool eval,
		       type *arg, term *(*fn)(int, term **, term *),
		       char *descr)
{
  return register_func(name, module, restype, eval, TBtrue, 1, &arg, fn, descr);
}

/* Register a function with 2 arguments. */
sym_idx register_func2(char *name, sym_idx module, type *restype, TBbool eval,
		       type *a1, type *a2, term *(*fn)(int, term **, term *),
		       char *descr)
{
  type *arg[2];

  arg[0] = a1;
  arg[1] = a2;
  return register_func(name, module, restype, eval, TBtrue, 2, arg, fn, descr);
}

/* Register a function with 3 arguments. */
sym_idx register_func3(char *name, sym_idx module, type *restype, TBbool eval,
		       type *a1, type *a2, type *a3, 
		       term *(*fn)(int, term **, term *), char *descr)
{
  type *arg[2];

  arg[0] = a1;
  arg[1] = a2;
  arg[2] = a3;
  return register_func(name, module, restype, eval, TBtrue, 3, arg, fn, descr);
}

/* Register a function with variable arguments. */
sym_idx register_func_var(char *name, sym_idx module, term *restype, 
		TBbool eval, term *(*fn)(int, term **, term *), char *descr)
{
  return register_func(name, module, restype, eval, TBfalse, 0, NULL, fn, descr);
}

TBbool is_expr_fun(term *T)
{
  name_bucket *bucket = idx_table[fun_sym(T)];

  if(bucket->type == IDT_EXPR_FUN)
    return TBtrue;
  return TBfalse;
}

term *make_symbol_list(int type)
{
  int i;
  term_list *list = NULL;

  for(i=0; i<ID; i++)
    if(type == IDT_ALL || idx_table[i]->type == type)
      list = mk_list(TBmake("%s", idx_table[i]->name), list);

  return list;
}


/*******************************************************\
*              functions in module 'system'             *
\*******************************************************/

term *system_functions(int nargs, term **args, term *proc_inst)
{
  return make_symbol_list(IDT_EXPR_FUN);
}

term *system_modules(int nargs, term **args, term *proc_inst)
{
  return make_symbol_list(IDT_MODULE);
}

static expr_sign *retrieve_signature(term *func)
{
  char *name;
  name_bucket *bucket;

  assert(is_str(func));

  name = str_val(func);
  bucket = lookup_bucket(name, IDM_ALL);
  if(bucket)
    return bucket->u.sig;
  return NULL;           
}

term *system_function_module(int nargs, term **args, term *proc_inst)
{
  expr_sign *sig;
  char *name;
  name_bucket *bucket;

  assert(nargs == 1);
  assert(is_str(*args));

  sig = retrieve_signature(*args);

  name = str_val(*args);
  bucket = lookup_bucket(name, IDM_ALL);
  if(!bucket)
    return mk_str("*unknown*");
  
  if(bucket->module > IDM_INTERNAL)
    return mk_str(get_txt(bucket->module));
  else
    return mk_str("*intern*");
}

term *system_function_result(int nargs, term **args, term *proc_inst)
{
  expr_sign *sig;

  assert(nargs == 1);
  sig = retrieve_signature(*args);

  if(!sig)
    return mk_str("*unknown*");

  return sig->restype;
}

term *system_function_args(int nargs, term **args, term *proc_inst)
{
  expr_sign *sig;
  term_list *result = NULL;
  int i;

  assert(nargs == 1);
  sig = retrieve_signature(*args);
  if(!sig)
    return mk_list1(mk_str("*unknown*"));

  if(!sig->chkargs)
    return mk_list1(mk_str("..."));

  for(i=sig->nargs-1; i>=0; i--)
    result = mk_list(sig->argtype[i], result);

  return result;
}

term *system_function_description(int nargs, term **args, term *proc_inst)
{
  expr_sign *sig;

  assert(nargs == 1);
  sig = retrieve_signature(args[0]);
  if(!sig)
    return mk_str("*unknown*");

  return mk_str(sig->descr);
}


void system_init_module()
{
  sym_idx mod = register_module("system");

  register_func0("functions", mod, Term, system_functions,
		 "list of known functions");
  register_func0("modules", mod, Term, system_modules,
		 "list of known modules");
  register_func1("function-module", mod, Str, TBtrue, Str,
		 system_function_module, "retrieve the module a function " \
		 "is defined in.");
  register_func1("function-result", mod, Term, TBtrue, Str,
		 system_function_result, "retrieve the result sort of a " \
		 "function.");
  register_func1("function-arguments", mod, List, TBtrue, Str,
		 system_function_args, "retrieve the list of argument types " \
		 "of a function. A list with the single string element " \
		 "\"...\" means it is a function with a variable number of "\
		 "arguments.");
  register_func1("function-description", mod, Str, TBtrue, Str,
		 system_function_description, "Retreive a short description " \
		 "of the function (like the one you are reading now).");
}
