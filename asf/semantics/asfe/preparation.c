

#include <ctype.h>
#include <stdlib.h>
#include <assert.h>
#include <strings.h>

#include <AsFix.h>
#include <deprecated.h>
#include "preparation.h"

static equation_table *tables = NULL;
static equation_table *equations = NULL;

/*{{{  equation_table *create_equation_table(int size) */

/*
Allocate memory for an equation table.
*/

equation_table *create_equation_table(int size)
{
  int i;
  equation_table *table = (equation_table *)malloc(sizeof(equation_table));

  if(!table)
    ATerror("out of memory in create_equation_table\n");
  table->next = NULL;
  table->module = NULL;
  table->size = size;
  table->table = (equation_entry **)malloc(sizeof(equation_entry *)*size);
  for(i=0; i<size; i++)
    table->table[i] = NULL;
  if(!table->table)
    ATerror("out of memory in create_equation_table\n");

  return table;
}

/*}}}  */
/*{{{  void flush_equations(equation_table *table) */

void flush_equations(equation_table *table)
{
  int i;
  equation_entry *old, *entry;

  for(i=0; i<table->size; i++) {
    entry = table->table[i];
    while(entry) {
      old = entry;
      entry = entry->hnext;
      ATunprotect(&old->equation);
      free(old);
    }
    table->table[i] = NULL;
  }
}


/*}}}  */
/*{{{  void destroy_equation_table(equation_table *table) */

/*
Free all memory associated with an equation table.
*/

void destroy_equation_table(equation_table *table)
{
  flush_equations(table);
  free(table->table);
  free(table);
}

/*}}}  */
/*{{{  unsigned hash_function(equation_table *table, ATerm top_ofs, ATerm first_ofs) */

static unsigned hash_function(equation_table *table, ATerm top_ofs, ATerm first_ofs)
{
	return (((int)top_ofs >> 2) * 3007 + ((int)first_ofs >> 2)) % table->size;
}

/*}}}  */
/*{{{  void enter_equation(equation_table *table, ATerm equation) */

/*
Enter an equation in an equation table.
*/

void enter_equation(equation_table *table, ATerm equation)
{
  ATerm lhs = asfix_get_equ_lhs(equation);
  ATermList lhsargs = (ATermList)asfix_get_appl_args(lhs);
  ATerm top_ofs = asfix_get_appl_ofs(lhs);
  ATerm first_ofs;
  equation_entry *entry = (equation_entry *)malloc(sizeof(equation_entry));
  unsigned hnr;

  if(!entry)
    ATerror("out of memory in enter_equation");

  while(!ATisEmpty(lhsargs) && !asfix_is_appl(ATgetFirst(lhsargs)) 
				&& !asfix_is_var(ATgetFirst(lhsargs))) {
    lhsargs = ATgetNext(lhsargs);
  }

  if(ATisEmpty(lhsargs) || asfix_is_var(ATgetFirst(lhsargs))
		 || asfix_is_default_equ(equation))
    first_ofs = (ATerm)ATempty; /* <PO> ? */
  else
    first_ofs = asfix_get_appl_ofs(ATgetFirst(lhsargs));

  hnr = hash_function(table, top_ofs, first_ofs);
/*  ATfprintf(stderr, "entering equation with top-ofs = %t, first-ofs = %t\n", top_ofs,first_ofs);
  ATfprintf(stderr, "\t hash-nr=%d\n", hnr); 
*/

  entry->hashnr = hnr;
  entry->top_ofs = top_ofs;
  entry->first_ofs = first_ofs;
  entry->equation = equation;
  ATprotect(&entry->equation);  
  if(asfix_is_default_equ(equation)) {
    equation_entry *cur = table->table[hnr];
    entry->hnext = NULL;
    if(cur) {
      while(cur->hnext)
        cur = cur->hnext;
      cur->hnext = entry;
    } else {
      table->table[hnr] = entry;
    }
  } else {
    entry->hnext = table->table[hnr];
    table->table[hnr] = entry;
  }
}

/*}}}  */

/*{{{  equation_entry *find_equation(equation_entry *prev, ATerm top_ofs, ATerm first) */

equation_entry *find_equation(equation_entry *from, ATerm top_ofs, 
															ATerm first_ofs)
{
  if(!equations)
    return NULL;
  if(from) {
    from = from->hnext;
  } else {
    int hnr = hash_function(equations, top_ofs, first_ofs);
/*    ATfprintf(stderr, "first try, finding top_ofs=%t, first_ofs=%t\n", top_ofs,first_ofs);
    ATfprintf(stderr, "\t hnr = %d\n", hnr);
*/
    from = equations->table[hnr];
  }
  while(from && (!ATisEqual(from->top_ofs,top_ofs) || 
								 !ATisEqual(from->first_ofs,first_ofs)))
    from = from->hnext;
/*  if(from)
    ATfprintf(stderr, "found: %t\n", from->equation);
  else
    ATfprintf(stderr, "no luck!\n");
*/
  return from;
}

/*}}}  */
/*{{{  void select_equations(ATerm module) */

void select_equations(ATerm module)
{
  equation_table *cur = tables;

  while(cur && !ATisEqual(cur->module, module))
    cur = cur->next;

  if(!cur)
    ATerror("equations of module %t have not been registered.");

  equations = cur;
}


/*}}}  */
/*{{{  void enter_equations(ATerm module, ATermList eqs) */

void enter_equations(ATerm module, ATermList eqs)
{
  equation_table *cur = tables;

  while(cur && !ATisEqual(cur->module, module))
    cur = cur->next;

  if(!cur) {
    cur = create_equation_table(ATgetLength(eqs)*2);
    cur->module = module;
		ATprotect(&cur->module);
    cur->next = tables;
    tables = cur;
  }

  equations = cur;
  flush_equations(equations);

  while(!ATisEmpty(eqs)) {
    enter_equation(equations, ATgetFirst(eqs));
    do {
      eqs = ATgetNext(eqs);
    } while(!ATisEmpty(eqs) && asfix_is_layout(ATgetFirst(eqs)));
  }
}

/*}}}  */


/*{{{  Preparation */

/*{{{  void update_geometry_whitespace(ATerm ws, int *line, int *col) */

void update_geometry_whitespace(ATerm ws, int *line, int *col)
{
  int i;
  char *w;

	if(!ATmatchTerm(ws, pattern_whitespace, &w))
		ATerror("not whitespace: %t\n", ws);

  for(i=0; w[i]; i++) {
    if(w[i] == '\n') {
      (*line)++;
      (*col) = 0;
    } else
      (*col)++;
  }
}

/*}}}  */
/*{{{  void update_geometry_literal(ATerm lit, int *line, int *col) */

void update_geometry_literal(ATerm lit, int *line, int *col)
{
  int i;
  char *l;

 if(!ATmatchTerm(lit, pattern_literal, &l))
	 ATerror("not a literal: %t\n", lit);

  for(i=0; l[i]; i++) {
    if(l[i] == '\n') {
      (*line)++;
      *col = 0;
    } else
      (*col)++;
  }
}

/*}}}  */
/*{{{  void update_geometry_variable(ATerm var, int *line, int *col) */

void update_geometry_variable(ATerm var, int *line, int *col)
{
  int i;
  char *name;
  ATerm sort;

 if(!ATmatchTerm(var, pattern_var, &name, &sort))
	 ATerror("not a variable: %t\n", var);

  for(i=0; name[i]; i++) {
    if(name[i] == '\n') {
      (*line)++;
      *col = 0;
    } else
      (*col)++;
  }
}

/*}}}  */
/*{{{  void update_geometry_term(ATerm trm, int *line, int *col) */

void update_geometry_list(ATermList l, int *line, int *col);
void update_geometry_term(ATerm trm, int *line, int *col)
{
  ATerm prod, w, sym;
  ATermList args, elems;

  if(ATmatchTerm(trm, pattern_appl, &prod, &w, &args)) {
    update_geometry_whitespace(w, line, col);
    update_geometry_list(args, line, col);
  } else if(ATmatchTerm(trm, pattern_list, &sym, &w, &elems)) {
    update_geometry_whitespace(w, line, col);
    update_geometry_list(elems, line, col);
  } else if(asfix_is_whitespace(trm)) {
    update_geometry_whitespace(trm, line, col);
  } else if(asfix_is_literal(trm)) {
    update_geometry_literal(trm, line, col);
  } else if(asfix_is_var(trm)) {
    update_geometry_variable(trm, line, col);
  } else {
    ATfprintf(stderr, "unknown construction in term: %t\n", trm);
  }
}

/*}}}  */
/*{{{  void update_geometry_list(ATermList l, int *line, int *col)*/

void update_geometry_list(ATermList l, int *line, int *col)
{
  while(!ATisEmpty(l)) {
    update_geometry_term(ATgetFirst(l), line, col);
    l = ATgetNext(l);
  }
}


/*}}}  */
/*{{{  void update_geometry_list_sep(ATerm ws, int *line, int *col)*/

void update_geometry_list_sep(ATerm sep, int *line, int *col)
{
  ATfprintf(stderr, "update_geometry_list_sep: %t\n", sep);
  
}


/*}}}  */

/*{{{  ATermList *prepare_list(ATermList *l, ATbool lexcons)*/

/*
Prepare a list of AsFix terms. This includes removing any layout,
and translating lexical constructors into lists.
*/

ATerm prepare_term(ATerm el, ATbool lexcons);

ATermList prepare_list(ATermList l, ATbool lexcons)
{
  ATerm el;
  ATermList result = ATempty;

  while(!ATisEmpty(l)) {
    do {
      el = ATgetFirst(l);
      l = ATgetNext(l);
    } while(asfix_is_whitespace(el) || asfix_is_list_sep(el));
    result = ATappend(result, prepare_term(el, lexcons)); 
  }
  return result;
}

/*}}}  */
/*{{{  ATermList prepare_conds(ATermList conds)*/

/*
Remove all layout from a list of conditions.
*/

ATermList prepare_conds(ATermList conds)
{
  ATerm cond, lhs, w[2], lit, rhs;
  ATerm newlhs, newrhs, newcond;
  ATermList newconds = ATempty;

  while(!ATisEmpty(conds)) {
    do {
      cond = ATgetFirst(conds);
      conds = ATgetNext(conds);
    } while(asfix_is_whitespace(cond) || asfix_is_list_sep(cond));
    if(ATmatch(cond, "condition(<term>,<term>,<term>,<term>,<term>)",
			&lhs, &w[0], &lit, &w[1], &rhs)) {
      newlhs = prepare_term(lhs, ATfalse);
      newrhs = prepare_term(rhs, ATfalse);
      newcond = ATmake("condition(<term>,<term>,<term>,<term>,<term>)",
			newlhs, w[0], lit, w[1], newrhs);
      newconds = ATappend(newconds, newcond);
    }
  }
  return newconds;
}

/*}}}  */
/*{{{  ATerm prepare_equ(ATerm equ, int *line, int *col)*/

/*
Prepare an equation for rewriting. This includes removing the layout,
and translating lexicals into lists.
*/

ATerm prepare_equ(ATerm equ, int *line, int *col)
{
  ATerm w[6], l[2], modname, tag, lhs, rhs;
  ATerm newlhs, newrhs;
  ATermList conds, newconds;

  if(ATmatch(equ, "ceq-equ(<term>,<term>,<term>,<term>,<term>,<term>,<term>,<term>,<term>)",    
	&modname, &w[0], &tag, &w[1], &lhs, &w[2], &l[0], &w[3], &rhs)) {
    newlhs = prepare_term(lhs, ATfalse);
    newrhs = prepare_term(rhs, ATfalse);

/*
    ATfprintf(stderr, "equation: %t starts at %d,%d, ", tag, *line, *col);
    update_geometry_whitespace(w[0], line, col);
    update_geometry_literal(tag, line, col);
    update_geometry_whitespace(w[1], line, col);
    update_geometry_term(lhs, line, col);
    update_geometry_whitespace(w[2], line, col);
    update_geometry_literal(l[0], line, col);
    update_geometry_whitespace(w[3], line, col);
    update_geometry_term(rhs, line, col);
    ATfprintf(stderr, "and ends at: %d,%d\n", *line, *col);
*/
    return ATmake("ceq-equ(<term>,<term>,<term>,<term>,<term>,"
									"<term>,<term>,<term>,<term>)",
									modname, w[0], tag, w[1], newlhs, w[2], l[0], 
									w[3], newrhs);
  }
	
  if(ATmatch(equ, "ceq-impl(<term>,<term>,<term>,<term>,<term>,<term>,<term>,"\
						 "<term>,<term>,<term>,<term>,<term>,<term>)",
						 &modname, &w[0], &tag, &w[1], &conds, &w[2], &l[0], &w[3], 
						 &lhs, &w[4], &l[1], &w[5], &rhs)) {
    newlhs = prepare_term(lhs, ATfalse);
    newrhs = prepare_term(rhs, ATfalse);
    newconds = prepare_conds(conds);
    return ATmake("ceq-impl(<term>,<term>,<term>,<term>,<term>,<term>," \
									"<term>,<term>,<term>,<term>,<term>,<term>,<term>)",
									modname, w[0], tag, w[1], newconds, w[2], l[0], w[3], 
									newlhs, w[4], l[1], w[5], newrhs);
  }
	
  if(ATmatch(equ, "ceq-when(<term>,<term>,<term>,<term>,<term>,<term>,<term>,"\
						 "<term>,<term>,<term>,<term>,<term>,<term>)",
						 &modname, &w[0], &tag, &w[1], &lhs, &w[2], &l[0], &w[3],
						 &rhs, &w[4], &l[1], &w[5], &conds)) {
    newlhs = prepare_term(lhs, ATfalse);
    newrhs = prepare_term(rhs, ATfalse);
    newconds = prepare_conds(conds);
    return ATmake("ceq-when(<term>,<term>,<term>,<term>,<term>,<term>," \
									"<term>,<term>,<term>,<term>,<term>,<term>,<term>)",
									modname, w[0], tag, w[1], newlhs, w[2], l[0], w[3],
									newrhs, w[4], l[1], w[5], newconds);
  }
  ATfprintf(stderr, "equation: %t not supported..\n", equ);
  assert(0);
  return NULL;	/* Silence the compiler */
}

/*}}}  */
/*{{{  ATerm lexical_to_list(ATerm lextrm)*/

/*
{\tt lexical\_to\_list} converts a lexical into a list.
*/

ATerm lexical_to_list(ATerm lextrm)
{
  ATerm sort, newtrm, newlex, newname, newiter;
  ATerm newargs, newfargs, newprod, newappl;
  int i, l;
  char cbuf[4] = "\" \"", *lexstr, *sortstr;
  ATermList newtrmlist = ATempty;

  sort = asfix_get_lex_sort(lextrm);
  if(!ATmatch(sort, "sort(<str>)", &sortstr))
		ATerror("not a sort: %t\n", sort);
  sortstr = strdup(sortstr);
  for(i=0; sortstr[i]; i++)
     sortstr[i] = tolower(sortstr[i]);
  /* Get the string name that represents the lexical */
  lexstr = ATgetName(ATgetAFun((ATermAppl)asfix_get_lex_str(lextrm)));
  l = strlen(lexstr);
  for(i=0; i<l; i++) {
    cbuf[1] = lexstr[i];
    newtrm = ATmake("lex(<str>,sort(\"CHAR\"))", cbuf, sort);
    newtrmlist = ATappend(newtrmlist, newtrm);
  }
  newname  = ATmake("l(<str>)", sortstr);
  newiter  = ATmake("iter(sort(\"CHAR\"),w(\"\"),l(\"+\"))");
  newlex   = ATmake("list(<term>,w(\"\"),<list>)", newiter, newtrmlist);
  newfargs = ATmake("[<term>,w(\"\"),ql(\"(\"),w(\"\"),<term>,w(\"\"),ql(\")\")]",newname, newiter);
  newargs  = ATmake("[<term>,l(\"(\"),<term>,l(\")\")]", newname, newlex);
  newprod  = ATmake("prod(id(\"caller\"),w(\"\"),<term>,w(\"\")," \
			"l(\"->\"),w(\"\"),<term>,w(\"\"),no-attrs)",newfargs,sort);
  newappl  = ATmake("appl(<term>,w(\"\"),<term>)", newprod, newargs);

  free(sortstr);
  return newappl;
}

/*}}}  */
/*{{{  ATerm prepare_term(ATerm t, ATbool lexcons)*/

/*
Remove the layout of a term.
*/

ATerm prepare_term(ATerm t, ATbool lexcons)
{
	ATerm result;
  ATermList args, elems, newargs;

  if(asfix_is_appl(t)) {
    args = asfix_get_appl_args(t);
    if(asfix_is_lex_constructor(t))
      newargs = prepare_list(args, ATtrue);
    else
      newargs = prepare_list(args, ATfalse);
    result = asfix_put_appl_args(t, newargs);
  } else if(asfix_is_list(t)) {
    elems = asfix_get_list_elems(t);
    result = asfix_put_list_elems(t, prepare_list(elems, lexcons));
  } else if(asfix_is_lex(t) && !lexcons)
    result = lexical_to_list(t);
  else 
		result = t;

  return result;
}

/*}}}  */

/*{{{  ATerm RWprepareTerm(ATerm t)*/

ATerm RWprepareTerm(ATerm t)
{
  return prepare_term(t, ATfalse);
}


/*}}}  */
/*{{{  ATermList RWprepareEqs(ATermList eqs)*/

/*
Prepare a list of equations for rewriting.
*/

ATermList RWprepareEqs(ATermList eqs)
{
  ATerm el;
  ATermList result = ATempty;
  int line = 0, col = 0;
  
  while(!ATisEmpty(eqs)) {
    do {
      el = ATgetFirst(eqs);
      eqs = ATgetNext(eqs);
      if(asfix_is_whitespace(el))
	update_geometry_whitespace(el, &line, &col);
      if(asfix_is_list_sep(el))
        update_geometry_list_sep(el, &line, &col);
    } while(asfix_is_whitespace(el) || asfix_is_list_sep(el));
    result = ATappend(result, prepare_equ(el, &line, &col)); 
  }
  return result;
}


/*}}}  */
/*{{{  void RWflushEquations()*/

void RWflushEquations()
{
  equation_table *table;
  while(tables) {
    table = tables;
    tables = tables->next;
    destroy_equation_table(table);
  }
}


/*}}}  */

/*}}}  */
/*{{{  Restoration*/

/*{{{  ATermList restore_list(ATerm sym, ATermList l)*/

/*
Restore a list after reweriting. Insert whitespace and optionally
separators.
*/

ATermList restore_list(ATerm sym, ATermList l)
{
  ATerm lit;
  ATerm el, sep, newsep, ws[2];
  ATermList newl = ATempty;

  ws[0] = ATmake("w(\" \")");
  ws[1] = ATmake("w(\"\\n\")");
  if(asfix_is_itersep(sym)) {
    sep = asfix_get_separator(sym);
    if(!ATmatch(sep, "ql(<term>)", &lit))
			ATerror("not a quoted literal: %t\n", sep);
    newsep = ATmake("sep(<term>)", lit);
    while(!ATisEmpty(l)) {
      el = ATgetFirst(l);
      newl  = ATappend(newl, RWrestoreTerm(el));
      l = ATgetNext(l);
      if(!ATisEmpty(l))
				newl = ATconcat(newl, ATmakeList3(ws[0], newsep, ws[1]));
    }
  } else {
    while(!ATisEmpty(l)) {
      el = ATgetFirst(l);
      newl  = ATappend(newl, RWrestoreTerm(el));
      l = ATgetNext(l);
      if(!ATisEmpty(l))
        newl = ATappend(newl, ws[0]);
    }
  }
  return newl;
}


/*}}}  */
/*{{{  ATermList restore_args(ATermList l)*/

/*
Restore a list of arguments after rewriting. This includes
the restoration of layout between arguments.
*/

ATermList restore_args(ATermList l)
{
  ATerm arg, ws;
  ATermList newl = ATempty;

  ws = ATmake("w(\" \")");
  while(!ATisEmpty(l)) {
    arg = ATgetFirst(l);
    newl = ATappend(newl, RWrestoreTerm(arg));
    l = ATgetNext(l);
    if(!ATisEmpty(l))
      newl = ATappend(newl, ws);
  }
  return newl;
}


/*}}}  */
/*{{{  ATerm list_to_lexical(ATerm lexappl)*/

/*{\tt list_to_lexical} converts  a list representing a lexical into a
lexical again. 
*/

ATerm list_to_lexical(ATerm lexappl)
{
  ATerm modname, lit, sort, w[4], prod, sym, lexlist;
  ATerm listarg, charsort, newlexappl;
  char *lexstr, *newlexstr;
  ATermList args, lexargs, listargs;
  int len, i;
	
  if(!ATmatch(lexappl, "appl(<term>,<term>,<list>)", &prod, &w[0], &lexargs))
    ATerror("not an appl: %t\n", lexappl);
	
  if(!ATmatch(prod, "prod(<term>,<term>,<list>,<term>,<term>,<term>," \
							"<term>,<term>,no-attrs)", &modname, &w[0], &args, &w[1], 
							&lit, &w[2], &sort, &w[3]))
		ATerror("not a prod: %t\n", prod);
  lexlist = ATelementAt(lexargs, 2);
  if(!ATmatch(lexlist,"list(<term>,<term>,<list>)",&sym,&w[0],&listargs))
		ATerror("not a list: %t\n", lexlist);
  len = ATgetLength(listargs);
  newlexstr = (char *)malloc(len+1);
  i = 0;
  while(!ATisEmpty(listargs)) {
    listarg = ATgetFirst(listargs);
    if(ATmatch(listarg, "lex(<str>,<term>)", &lexstr, &charsort))
      newlexstr[i++] = lexstr[1];
    listargs = ATgetNext(listargs);
  }
  newlexstr[i] = '\0';
  newlexappl = ATmake("lex(<str>,<term>)", newlexstr, sort);
  free(newlexstr);
  return newlexappl;
}


/*}}}  */
/*{{{  ATerm RWrestoreTerm(ATerm t)*/

ATerm RWrestoreTerm(ATerm t)
{
  ATermList args, elems;
  ATerm sym, result;
	
  if(asfix_is_appl(t)) {
    if(asfix_is_lex_constructor(t))
      return list_to_lexical(t);
    args = asfix_get_appl_args(t);
    result = asfix_put_appl_args(t, restore_args(args));    
  } else if(asfix_is_list(t)) {
    elems = asfix_get_list_elems(t);
    sym   = asfix_get_list_sym(t);
    return asfix_put_list_elems(t, restore_list(sym, elems));
  } else
    result = t;

	return result;
}

/*}}}  */

/*}}}  */
/*{{{  lexicals*/


/*}}}  */
