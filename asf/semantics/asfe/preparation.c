

#include <ctype.h>
#include <stdlib.h>
#include <assert.h>
#include <strings.h>

#include <AsFix.h>
#include <aterm2.h>
#include "AsFix-access.h"
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
  equation_entry *entry;

  ATerm equ, lhs = NULL, top_ofs,first_ofs, tag = NULL , rhs = NULL;
  ATermList lhsargs, conds = ATempty;
  ATerm condlist, conditions;
  unsigned hnr;

  if(AFTisSimpleCondEqu(equation)) {
    tag = AFTgetSimpleCondEquTag(equation); 
    equ = AFTgetSimpleCondEquEqu(equation); 
 
    lhs = AFTgetSimpleEquLHS(equ); 
    rhs = AFTgetSimpleEquRHS(equ); 
    conds = ATempty;
  }
  else if(AFTisImpliesCondEqu(equation)) {
    tag = AFTgetImpliesCondEquTag(equation); 
    equ = AFTgetImpliesCondEquEqu(equation);  
		conditions = AFTgetImpliesCondEquConds(equation);
		condlist = AFTgetCondsCondList(conditions);
    conds = AFTgetListElements(condlist);
 
    lhs = AFTgetSimpleEquLHS(equ); 
    rhs = AFTgetSimpleEquRHS(equ);
  }
  else if(AFTisWhenCondEqu(equation)) {
    tag = AFTgetWhenCondEquTag(equation); 
    equ = AFTgetWhenCondEquEqu(equation);  
		conditions = AFTgetWhenCondEquConds(equation);
		condlist = AFTgetCondsCondList(conditions);
    conds = AFTgetListElements(condlist);

    lhs = AFTgetSimpleEquLHS(equ); 
    rhs = AFTgetSimpleEquRHS(equ);
  }
  else
    ATerror("Strange equation %t\n",equation); 

  lhsargs = (ATermList)asfix_get_appl_args(lhs); 
  top_ofs = asfix_get_appl_ofs(lhs);  

  entry = (equation_entry *)malloc(sizeof(equation_entry)); 
  if(!entry)
    ATerror("out of memory in enter_equation");

  while(!ATisEmpty(lhsargs) && !asfix_is_appl(ATgetFirst(lhsargs)) 
				&& !asfix_is_var(ATgetFirst(lhsargs))) {
    lhsargs = ATgetNext(lhsargs);
  }

  if(ATisEmpty(lhsargs) || asfix_is_var(ATgetFirst(lhsargs))
		 || AFTisDefaultTag(tag))
    first_ofs = (ATerm)ATempty; /* <PO> ? */
  else
    first_ofs = asfix_get_appl_ofs(ATgetFirst(lhsargs));

  hnr = hash_function(table, top_ofs, first_ofs); 

  entry->hashnr = hnr;
  entry->top_ofs = top_ofs;
  entry->first_ofs = first_ofs;
  entry->equation = equation;
  ATprotect(&entry->equation); 
  entry->tag = tag;
  ATprotect(&entry->tag);    
  entry->lhs = lhs;
  ATprotect(&entry->lhs);     
  entry->rhs = rhs;
  ATprotect(&entry->rhs);       
  entry->conds = conds;
  ATprotect((ATerm*)&entry->conds);   
  if(AFTisDefaultTag(tag)) {
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

/*
  {
    ATerm anno = ATgetAnnotation(equation, ATparse("pos-info"));
    if(anno)
      ATfprintf(stderr, "annotations of %t: %t\n", entry->tag, anno);
    else
      ATfprintf(stderr, "no annotations.\n");
  }
*/
}

/*}}}  */

/*{{{  equation_entry *find_equation(equation_entry *prev, ATerm top_ofs, ATerm first) */

equation_entry *find_equation(equation_entry *from, ATerm top_ofs,
                              ATerm first_ofs)
{
	/*ATfprintf(stderr, "looking for equation with ofs: %t\n", top_ofs);*/
  if(equations->size == 0)
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
		 !ATisEqual(from->first_ofs,first_ofs))) {
    from = from->hnext;
  }
/*	if(from) {
		equation_entry *result;
    ATfprintf(stderr, "found: %t\n", from->tag);
		result = from;
		from = from->hnext;
		while(from) {
			ATfprintf(stderr, "todo: %t\n", from->tag);
			from = from->hnext;
		}
		return result;
  } else
    ATfprintf(stderr, "no luck!\n");
		*/

  return from;
}

/*}}}  */
/*{{{  void select_equations(char *module) */

void select_equations(char *module)
{
  equation_table *cur = tables;
  ATerm t_module = ATmake("<str>", module);

  while(cur && !ATisEqual(cur->module, t_module))
    cur = cur->next;

  if(!cur)
    ATerror("equations of module %t have not been registered.");

  equations = cur;
}


/*}}}  */
/*{{{  ATbool find_module(char *module) */
ATbool find_module(char *module)
{
  equation_table *cur = tables;
  ATerm t_module = ATmake("<str>", module);
 
  while(cur && !ATisEqual(cur->module, t_module))
    cur = cur->next;

  if(cur) 
    return ATtrue;
  else
    return ATfalse;
}
/*}}}  */
/*{{{  void enter_equations(char *module, ATermList eqs) */

void enter_equations(char *module, ATermList eqs)
{
  equation_table *cur = tables;
  ATerm t_module = ATmake("<str>", module);
 
  while(cur && !ATisEqual(cur->module, t_module))
    cur = cur->next;

  if(!cur) {
    cur = create_equation_table(ATgetLength(eqs)*2);
    cur->module = t_module;
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
ATerm prepare_cond(ATerm cond)
{
  ATerm prod, lhs, w[2], lit, rhs, newlhs, newrhs, annos, newcond;

  annos = AT_getAnnotations(cond);  
  if(AFTisCond(cond)) {
    prod = AFTgetCondProd(cond);
    lhs  = AFTgetCondLHS(cond);
    newlhs = prepare_term(lhs, ATfalse);
    w[0] = AFTgetCondWS0(cond);
    lit  = AFTgetCondLit(cond);
    w[1] = AFTgetCondWS1(cond);
    rhs  = AFTgetCondRHS(cond);
    newrhs = prepare_term(rhs, ATfalse);

    newcond = AFTbuildCond(prod, newlhs, w[0], lit, w[1], newrhs);
    
    if(annos)
      newcond = AT_setAnnotations(newcond, annos);

    return newcond;
  }

  ATerror("expected condition, got: %t\n", cond);
  return NULL;
}

ATerm prepare_condlist(ATerm conds)
{
  ATerm cond, iter, wl;
  ATerm newcond;
  ATermList newconds = ATempty, list;

  if(!AFTisList(conds))
    ATerror("expected condition list, got: %t\n", conds);

  iter = AFTgetListIter(conds);
  wl   = AFTgetListWS(conds);
  list = AFTgetListElements(conds);

  while(!ATisEmpty(list)) {
    do {
      cond = ATgetFirst(list);
      list = ATgetNext(list);
    } while(asfix_is_whitespace(cond) || asfix_is_list_sep(cond));
    newcond = prepare_cond(cond);
    newconds = ATappend(newconds, newcond);
  }
  return AFTbuildList(iter, wl, newconds);
}

ATerm prepare_conds(ATerm conds)
{
	if(AFTisConds(conds)) {
		ATerm condlist = AFTgetCondsCondList(conds);
		condlist = prepare_condlist(condlist);
		return AFTbuildConds(condlist);
	}

	ATerror("expected conds, got: %t\n", conds);
	return NULL;
}

/*}}}  */
/*{{{  ATerm prepare_equ(ATerm equ) */

/*
Prepare an equation for rewriting. This includes removing the layout,
and translating lexicals into lists.
*/

ATerm prepare_simple_equ(ATerm equ)
{
  ATerm prod, w[2], l, lhs, rhs, newlhs, newrhs;

  if(AFTisSimpleEqu(equ)) {
    prod = AFTgetSimpleEquProd(equ);
    lhs  = AFTgetSimpleEquLHS(equ); 
    newlhs = prepare_term(lhs, ATfalse);
    w[0] = AFTgetSimpleEquWS0(equ);
    l = AFTgetSimpleEquLit(equ);
    w[1] = AFTgetSimpleEquWS1(equ);
    rhs  = AFTgetSimpleEquRHS(equ);
    newrhs = prepare_term(rhs, ATfalse);
    return AFTbuildSimpleEqu(prod, newlhs, w[0], l, w[1], newrhs);
  }
  else {
    ATerror("expected simple equ, got %t\n", equ);
    return NULL;
  }  
}

ATerm prepare_equ(ATerm equ)
{
  ATerm w[6], tag, simplequ, newequ, lit, lex;
  ATerm annos;
  ATerm conds, newconds;

  annos = AT_getAnnotations(equ); 

  if(AFTisSimpleCondEqu(equ)) {
    tag  = AFTgetSimpleCondEquTag(equ);
    w[0] = AFTgetSimpleCondEquWS(equ);
    simplequ = AFTgetSimpleCondEquEqu(equ);
    newequ = prepare_simple_equ(simplequ);

    equ = AFTbuildSimpleCondEqu(tag, w[0], newequ);
  }
  else if(AFTisImpliesCondEqu(equ)) {
    tag  = AFTgetImpliesCondEquTag(equ);
    w[0] = AFTgetImpliesCondEquWS0(equ);
    conds = AFTgetImpliesCondEquConds(equ);
    newconds = prepare_conds(conds);
    w[1] = AFTgetImpliesCondEquWS1(equ);
    lex  = AFTgetImpliesCondEquBarLex(equ);
    w[2] = AFTgetImpliesCondEquWS2(equ);
    simplequ = AFTgetImpliesCondEquEqu(equ);
    newequ = prepare_simple_equ(simplequ);
    equ = AFTbuildImpliesCondEqu(tag, w[0], newconds, w[1], 
                                     lex, w[2], newequ);
  }
  else if(AFTisWhenCondEqu(equ)) {
    tag  = AFTgetWhenCondEquTag(equ);
    w[0] = AFTgetWhenCondEquWS0(equ);
    simplequ = AFTgetWhenCondEquEqu(equ);
    newequ = prepare_simple_equ(simplequ);
    w[1] = AFTgetWhenCondEquWS1(equ);
    lit  = AFTgetWhenCondEquLit(equ);
    w[2] = AFTgetWhenCondEquWS2(equ); 
    conds = AFTgetWhenCondEquConds(equ);
    newconds = prepare_conds(conds); 
    equ = AFTbuildWhenCondEqu(tag, w[0], newequ, w[1], 
                                     lit, w[2], newconds);
  } else {
    ATfprintf(stderr, "equation: %t not supported..\n", equ);
    assert(0);
  }

  if(annos)
    equ = AT_setAnnotations(equ, annos);
  return equ;
}

/*}}}  */
/*{{{  ATerm lexical_to_list(ATerm lextrm)*/

/*
{\tt lexical\_to\_list} converts a lexical into a list.
*/

ATerm lexical_to_list(ATerm lextrm)
{
  ATerm sort, newtrm, newlex, newname, qnewname, newiter;
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
  qnewname = ATmake("ql(<str>)", sortstr);
  newiter  = ATmake("iter(sort(\"CHAR\"),w(\"\"),l(\"+\"))");
  newlex   = ATmake("list(<term>,w(\"\"),<term>)", newiter, newtrmlist);
  newfargs = ATmake("[<term>,w(\"\"),ql(\"(\"),w(\"\"),<term>,w(\"\"),ql(\")\")]",qnewname, newiter);
  newargs  = ATmake("[<term>,l(\"(\"),<term>,l(\")\")]", newname, newlex);
  newprod  = ATmake("prod(id(\"GEN-LexConsFuncs\"),w(\"\"),<term>,w(\"\")," \
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
  ATerm result, annos;
  ATermList args, elems, newargs;

  annos = AT_getAnnotations(t);
  if(asfix_is_appl(t)) {
    args = asfix_get_appl_args(t);
    if(AFTisLexConstructor(t)) {
      newargs = prepare_list(args, ATtrue);
    } else
      newargs = prepare_list(args, ATfalse); 
    result = asfix_put_appl_args(t, newargs); 
  } else if(asfix_is_list(t)) {
    elems = asfix_get_list_elems(t);
    result = asfix_put_list_elems(t, prepare_list(elems, lexcons));
  } else if(asfix_is_lex(t) && !lexcons)
    result = lexical_to_list(t);
  else 
    result = t;

	if(annos)
		result = AT_setAnnotations(result, annos);

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

  while(!ATisEmpty(eqs)) {
    do {
      el = ATgetFirst(eqs);
      eqs = ATgetNext(eqs);
    } while(asfix_is_whitespace(el) || asfix_is_list_sep(el)); 
    result = ATappend(result, prepare_equ(el)); 
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
	
  if(!ATmatch(lexappl, "appl(<term>,<term>,<term>)", &prod, &w[0], &lexargs))
    ATerror("not an appl: %t\n", lexappl);
	
  if(!ATmatch(prod, "prod(<term>,<term>,<term>,<term>,<term>,<term>," \
							"<term>,<term>,no-attrs)", &modname, &w[0], &args, &w[1], 
							&lit, &w[2], &sort, &w[3]))
		ATerror("not a prod: %t\n", prod);
  lexlist = ATelementAt(lexargs, 2);
  if(!ATmatch(lexlist,"list(<term>,<term>,<term>)",&sym,&w[0],&listargs))
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
    if(AFTisLexConstructor(t))
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
