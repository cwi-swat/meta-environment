#line 3 "preparation.c.nw"
#include <ctype.h>
#include <asfix.h>
#include "preparation.h"

static equation_table *tables = NULL;
static equation_table *equations = NULL;

#line 28 "preparation.c.nw"
equation_table *create_equation_table(int size)
{
  int i;
  equation_table *table = (equation_table *)malloc(sizeof(equation_table));

  if(!table)
    fatal_error("out of memory in create_equation_table\n");
  table->next = NULL;
  table->module = NULL;
  table->size = size;
  table->table = (equation_entry **)malloc(sizeof(equation_entry *)*size);
  for(i=0; i<size; i++)
    table->table[i] = NULL;
  if(!table->table)
    fatal_error("out of memory in create_equation_table\n");

  return table;
}
#line 66 "preparation.c.nw"
void flush_equations(equation_table *table)
{
  int i;
  equation_entry *old, *entry;

  for(i=0; i<table->size; i++) {
    entry = table->table[i];
    while(entry) {
      old = entry;
      entry = entry->hnext;
      t_unprotect(old->equation);
      free(old);
    }
    table->table[i] = NULL;
  }
}
#line 54 "preparation.c.nw"
void destroy_equation_table(equation_table *table)
{
  flush_equations(table);
  free(table->table);
  free(table);
}
#line 88 "preparation.c.nw"
static unsigned hash_function(equation_table *table, aterm *top_ofs, aterm *first_ofs)
{
  return (top_ofs->hnr ^ first_ofs->hnr) % table->size;
}
#line 100 "preparation.c.nw"
void enter_equation(equation_table *table, aterm *equation)
{
  aterm *lhs = asfix_get_equ_lhs(equation);
  aterm_list *lhsargs = asfix_get_appl_args(lhs);
  aterm *top_ofs = asfix_get_appl_ofs(lhs);
  aterm *first_ofs;
  equation_entry *entry = (equation_entry *)malloc(sizeof(equation_entry));
  unsigned hnr;

  if(!entry)
    fatal_error("out of memory in enter_equation");

  while(!t_is_empty(lhsargs) && !asfix_is_appl(t_list_first(lhsargs)) 
                                && !asfix_is_var(t_list_first(lhsargs))) {
    lhsargs = t_list_next(lhsargs);
  }

  if(t_is_empty(lhsargs) || asfix_is_var(t_list_first(lhsargs)))
    first_ofs = t_empty(t_world(equation));
  else
    first_ofs = asfix_get_appl_ofs(t_list_first(lhsargs));

  hnr = hash_function(table, top_ofs, first_ofs);
/*  Tprintf(stderr, "entering equation with top-ofs = %t, first-ofs = %t\n", top_ofs,first_ofs);
  Tprintf(stderr, "\t hash-nr=%d\n", hnr); 
*/
  entry->hnext = table->table[hnr];
  table->table[hnr] = entry;
  entry->hashnr = hnr;
  entry->top_ofs = top_ofs;
  entry->first_ofs = first_ofs;
  entry->equation = equation;
  t_protect(equation);  
}
#line 142 "preparation.c.nw"
equation_entry *find_equation(equation_entry *from, aterm *top_ofs, 
                                                        aterm *first_ofs)
{
  if(from) {
    from = from->hnext;
  } else {
    int hnr = hash_function(equations, top_ofs, first_ofs);
/*    Tprintf(stderr, "first try, finding top_ofs=%t, first_ofs=%t\n", top_ofs,first_ofs);
    Tprintf(stderr, "\t hnr = %d\n", hnr);
*/
    from = equations->table[hnr];
  }
  while(from && (!t_equal(from->top_ofs,top_ofs) || 
                 !t_equal(from->first_ofs,first_ofs)))
    from = from->hnext;
/*  if(from)
    Tprintf(stderr, "found: %t\n", from->equation);
  else
    Tprintf(stderr, "no luck!\n");
*/
  return from;
}
#line 170 "preparation.c.nw"
void select_equations(aterm *module)
{
  equation_table *cur = tables;

  while(cur && !t_equal(cur->module, module))
    cur = cur->next;

  if(!cur)
    fatal_error("equations of module %t have not been registered.");

  equations = cur;
}
#line 188 "preparation.c.nw"
void enter_equations(aterm *module, aterm_list *eqs)
{
  equation_table *cur = tables;

  while(cur && !t_equal(cur->module, module))
    cur = cur->next;

  if(!cur) {
    cur = create_equation_table(TlistSize(eqs)*2);
    cur->module = module;
    Tprotect(cur->module);
    cur->next = tables;
    tables = cur;
  }

  equations = cur;
  flush_equations(equations);

  while(!t_is_empty(eqs)) {
    enter_equation(equations, t_list_first(eqs));
    do {
      eqs = t_list_next(eqs);
    } while(!t_is_empty(eqs) && asfix_is_layout(t_list_first(eqs)));
  }
}

#line 531 "preparation.c.nw"
aterm *lexical_to_list(arena *ar, aterm *lextrm)
{
  aterm *sort, *newtrm, *newlex, *newname, *newiter;
  aterm *newargs, *newfargs, *newprod, *newappl;
  int i, l;
  char cbuf[4] = "\" \"", *lexstr, *sortstr;
  aterm_list *newtrmlist = t_empty(t_world(lextrm));

  sort = asfix_get_lex_sort(lextrm);
  assertp(Tmatch(sort, "sort(<str>)", &sortstr));
  sortstr = strdup(sortstr);
  for(i=0; sortstr[i]; i++)
     sortstr[i] = tolower(sortstr[i]);
  /* Get the string name that represents the lexical */
  lexstr = t_sym_name(t_appl_sym(asfix_get_lex_str(lextrm)));
  l = strlen(lexstr);
  for(i=0; i<l; i++) {
    cbuf[1] = lexstr[i];
    newtrm = Tmake(ar, "lex(<str>,sort(\"CHAR\"))", cbuf, sort);
    newtrmlist = TlistAppend(ar, newtrmlist, newtrm);
  }
  newname  = Tmake(ar, "l(<str>)", sortstr);
  newiter  = Tmake(ar, "iter(sort(\"CHAR\"),w(\"\"),l(\"+\"))");
  newlex   = Tmake(ar, "list(<term>,w(\"\"),<list>)", newiter, newtrmlist);
  newfargs = Tmake(ar, "[<term>,w(\"\"),ql(\"(\"),w(\"\"),<term>,w(\"\"),ql(\")\")]",newname, newiter);
  newargs  = Tmake(ar, "[<term>,l(\"(\"),<term>,l(\")\")]", newname, newlex);
  newprod  = Tmake(ar, "prod(id(\"caller\"),w(\"\"),<term>,w(\"\")," \
                        "l(\"->\"),w(\"\"),<term>,w(\"\"),no-attrs)",newfargs,sort);
  newappl  = Tmake(ar, "appl(<term>,w(\"\"),<term>)", newprod, newargs);

  free(sortstr);
  return newappl;
}
#line 573 "preparation.c.nw"
aterm *list_to_lexical(arena *ar, aterm *lexappl)
{
  aterm *modname, *lit, *sort, *w[4], *prod, *sym, *lexlist;
  aterm *listarg, *charsort, *newlexappl;
  char *lexstr, *newlexstr;
  aterm_list *args, *lexargs, *listargs;
  int len, i;

  assertp(Tmatch(lexappl, "appl(<term>,<term>,<list>)", &prod, &w[0], &lexargs));
  assertp(Tmatch(prod, "prod(<term>,<term>,<list>,<term>,<term>,<term>," \
        "<term>,<term>,no-attrs)", &modname, &w[0], &args, &w[1], 
                                                &lit, &w[2], &sort, &w[3]));
  lexlist = TlistIndex(lexargs, 2);
  assertp(Tmatch(lexlist,"list(<term>,<term>,<list>)",&sym,&w[0],&listargs));
  len = TlistSize(listargs);
  newlexstr = (char *)malloc(len+1);
  i = 0;
  while(!t_is_empty(listargs)) {
    listarg = t_list_first(listargs);
    if(Tmatch(listarg, "lex(<str>,<term>)", &lexstr, &charsort))
      newlexstr[i++] = lexstr[1];
    listargs = t_list_next(listargs);
  }
  newlexstr[i] = '\0';
  newlexappl = Tmake(ar, "lex(<str>,<term>)", newlexstr, sort);
  free(newlexstr);
  return newlexappl;
}
#line 236 "preparation.c.nw"
aterm *prepare_term(arena *ar, aterm *el, Tbool lexcons);

aterm_list *prepare_list(arena *ar, aterm_list *l, Tbool lexcons)
{
  aterm *el;
  aterm_list *result = t_empty(t_world(l));

  while(!t_is_empty(l)) {
    do {
      el = t_list_first(l);
      l = t_list_next(l);
    } while(asfix_is_whitespace(el) || asfix_is_list_sep(el));
    result = TlistAppend(ar, result, prepare_term(ar, el, lexcons)); 
  }
  return result;
}
#line 260 "preparation.c.nw"
aterm_list *prepare_conds(arena *ar, aterm_list *conds)
{
  aterm *cond, *lhs, *w[2], *lit, *rhs;
  aterm *newlhs, *newrhs, *newcond;
  aterm_list *newconds = t_empty(NULL);

  while(!t_is_empty(conds)) {
    do {
      cond = t_list_first(conds);
      conds = t_list_next(conds);
    } while(asfix_is_whitespace(cond) || asfix_is_list_sep(cond));
    if(Tmatch(cond, "condition(<term>,<term>,<term>,<term>,<term>)",
                        &lhs, &w[0], &lit, &w[1], &rhs)) {
      newlhs = prepare_term(ar, lhs, Tfalse);
      newrhs = prepare_term(ar, rhs, Tfalse);
      newcond = Tmake(ar, "condition(<term>,<term>,<term>,<term>,<term>)",
                        newlhs, w[0], lit, w[1], newrhs);
      newconds = TlistAppend(ar, newconds, newcond);
    }
  }
  return newconds;
}
#line 291 "preparation.c.nw"
aterm_list *prepare_equ(arena *ar, aterm *equ)
{
  aterm *w[6], *l[2], *modname, *tag, *lhs, *rhs;
  aterm *newlhs, *newrhs;
  aterm_list *conds, *newconds;

  if(Tmatch(equ, "ceq-equ(<term>,<term>,<term>,<term>,<term>,<term>,<term>,<term>,<term>)",    
        &modname, &w[0], &tag, &w[1], &lhs, &w[2], &l[0], &w[3], &rhs)) {
    newlhs = prepare_term(ar, lhs, Tfalse);
    newrhs = prepare_term(ar, rhs, Tfalse);
    return Tmake(ar, "ceq-equ(<term>,<term>,<term>,<term>,<term>,<term>,<term>,<term>,<term>)",
        modname, w[0], tag, w[1], newlhs, w[2], l[0], w[3], newrhs);
  }

  if(Tmatch(equ, "ceq-impl(<term>,<term>,<term>,<term>,<term>,<term>,<term>,"\
                                "<term>,<term>,<term>,<term>,<term>,<term>)",
        &modname, &w[0], &tag, &w[1], &conds, &w[2], &l[0], &w[3], 
        &lhs, &w[4], &l[1], &w[5], &rhs)) {
    newlhs = prepare_term(ar, lhs, Tfalse);
    newrhs = prepare_term(ar, rhs, Tfalse);
    newconds = prepare_conds(ar, conds);
    return Tmake(ar, "ceq-impl(<term>,<term>,<term>,<term>,<term>,<term>," \
                        "<term>,<term>,<term>,<term>,<term>,<term>,<term>)",
        modname, w[0], tag, w[1], newconds, w[2], l[0], w[3], 
        newlhs, w[4], l[1], w[5], newrhs);
  }

  if(Tmatch(equ, "ceq-when(<term>,<term>,<term>,<term>,<term>,<term>,<term>,"\
                                "<term>,<term>,<term>,<term>,<term>,<term>)",
        &modname, &w[0], &tag, &w[1], &lhs, &w[2], &l[0], &w[3],
        &rhs, &w[4], &l[1], &w[5], &conds)) {
    newlhs = prepare_term(ar, lhs, Tfalse);
    newrhs = prepare_term(ar, rhs, Tfalse);
    newconds = prepare_conds(ar, conds);
    return Tmake(ar, "ceq-when(<term>,<term>,<term>,<term>,<term>,<term>" \
                        "<term>,<term>,<term>,<term>,<term>,<term>,<term>)",
        modname, w[0], tag, w[1], newlhs, w[2], l[0], w[3],
        newrhs, w[4], l[1], w[5], newconds);
  }
  Tprintf(stderr, "equation: %t not supported..\n", equ);
  assert(0);
  return NULL;  /* Silence the compiler */
}
#line 342 "preparation.c.nw"
aterm *prepare_term(arena *ar, aterm *t, Tbool lexcons)
{
  aterm_list *args, *elems, *newargs, *result;
  arena local;

  TinitArena(t_world(*ar), &local);

  if(asfix_is_appl(t)) {
    args = asfix_get_appl_args(t);
    if(asfix_is_lex_constructor(t))
      newargs = prepare_list(&local, args, Ttrue);
    else
      newargs = prepare_list(&local, args, Tfalse);
    result = asfix_put_appl_args(&local, t, newargs);
  } else if(asfix_is_list(t)) {
    elems = asfix_get_list_elems(t);
    result = asfix_put_list_elems(&local, t, 
                        prepare_list(&local, elems, lexcons));
  } else if(asfix_is_lex(t) && !lexcons)
    result = lexical_to_list(&local, t);
  else {
    TdestroyArena(&local);
    return t;
  }

  Tadd2Arena(ar, result);
  TdestroyArena(&local);

  return result;
}
#line 379 "preparation.c.nw"
aterm *RWprepareTerm(arena *ar, aterm *t)
{
  return prepare_term(ar, t, Tfalse);
}
#line 391 "preparation.c.nw"
aterm_list *RWprepareEqs(arena *ar, aterm_list *eqs)
{
  aterm *el;
  aterm_list *result = t_empty(t_world(*ar));

  while(!t_is_empty(eqs)) {
    do {
      el = t_list_first(eqs);
      eqs = t_list_next(eqs);
    } while(asfix_is_whitespace(el) || asfix_is_list_sep(el));
    result = TlistAppend(ar, result, prepare_equ(ar, el)); 
  }
  return result;
}
#line 426 "preparation.c.nw"
aterm_list *restore_list(arena *ar, aterm *sym, aterm_list *l)
{
  aterm *lit;
  aterm *el, *sep, *newsep, *ws[2];
  aterm_list *newl = t_empty(t_world(l));

  ws[0] = Tmake(ar, "w(\" \")");
  ws[1] = Tmake(ar, "w(\"\\n\")");
  if(asfix_is_itersep(sym)) {
    sep = asfix_get_separator(sym);
    assertp(Tmatch(sep, "ql(<term>)", &lit));
    newsep = Tmake(ar, "sep(<term>)", lit);
    while(!t_is_empty(l)) {
      el = t_list_first(l);
      newl  = TlistAppend(ar, newl, RWrestoreTerm(ar, el));
      l = t_list_next(l);
      if(!t_is_empty(l))
        newl = TlistConcat(ar, newl, TmkList_n(ar, 3, ws[0], newsep, ws[1]));
    }
  } else {
    while(!t_is_empty(l)) {
      el = t_list_first(l);
      newl  = TlistAppend(ar, newl, RWrestoreTerm(ar, el));
      l = t_list_next(l);
      if(!t_is_empty(l))
        newl = TlistAppend(ar, newl, ws[0]);
    }
  }
  return newl;
}
#line 465 "preparation.c.nw"
aterm_list *restore_args(arena *ar, aterm_list *l)
{
  aterm *arg, *ws;
  aterm_list *newl = t_empty(t_world(l));

  ws = Tmake(ar, "w(\" \")");
  while(!t_is_empty(l)) {
    arg = t_list_first(l);
    newl = TlistAppend(ar, newl, RWrestoreTerm(ar, arg));
    l = t_list_next(l);
    if(!t_is_empty(l))
      newl = TlistAppend(ar, newl, ws);
  }
  return newl;
}
#line 486 "preparation.c.nw"
aterm *RWrestoreTerm(arena *ar, aterm *t)
{
  aterm_list *args, *elems;
  aterm *sym, *result;
  arena local;
  
  TinitArena(NULL, &local);

  if(asfix_is_appl(t)) {
    if(asfix_is_lex_constructor(t))
      return list_to_lexical(&local, t);
    args = asfix_get_appl_args(t);
    result = asfix_put_appl_args(&local, t, restore_args(&local, args));    
  } else if(asfix_is_list(t)) {
    elems = asfix_get_list_elems(t);
    sym   = asfix_get_list_sym(t);
    return asfix_put_list_elems(&local, t, restore_list(&local, sym, elems));
  } else {
    TdestroyArena(&local);
    return t;
  }

  Tadd2Arena(ar, result);
  TdestroyArena(&local);
  
  return result;
}
