/* Mark van den Brand, Pieter Olivier, Jurgen Vinju 
 * $Id$
 */


/*{{{  standard includes */

#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/*}}}  */
/*{{{  meta includes */

#include <MEPT-utils.h>
#include <ASFME-utils.h>

/*}}}  */
/*{{{  local includes */

#include "asc-support-me.h"
#include "asc-traversals.h"
#include "muasf2pt.h"
#include "prod2str.h"

/*}}}  */

/*{{{  profiling declarations */

unsigned int rewrite_steps = 0;

#ifdef MEMO_PROFILING
ATermTable prof_table = NULL;
Symbol record_sym = -1;
#endif

/*}}}  */
/*{{{  global variables */

/* This term_store is used for temporary storage of
 * list elements, e.g. used in slice.
 */
#define MAX_STORE 10240
static ATerm term_store[MAX_STORE];

/* A table to convert integers to ATermInts. 
 */
ATerm char_table[256] = {NULL};

/* These quoted symbols are used in combination with
 * outermost evaluation! So, 
 * "if" Bool "then" S "else" S "fi" -> S {delay2, delay3}
 * Symbols are quoted to prevent innermost reduction of
 * functions. Also symbols related to list (matching)
 * have to be quoted: make_listsym, concsym and conssym.
 */
Symbol sym_quote0;
Symbol sym_quote1;
Symbol sym_quote2;
Symbol sym_quote3;
Symbol sym_quote4;
Symbol sym_quote5;
Symbol sym_quote6;
Symbol sym_quote7;

Symbol tuplesym;
Symbol make_listsym;
Symbol concsym;    


/*}}}  */
/*{{{  declarations for memotables */

#define MAX_MEMO_TABLES 1024
static int nr_memo_tables = 0;
static ATermTable *memo_tables[MAX_MEMO_TABLES];
static char *memo_table_names[MAX_MEMO_TABLES];


/*}}}  */
/*{{{  local function declarations */

static ATerm call_unknown(PT_Production prod, ATermList args);
static ATerm call(PT_Production prod, ATermList args);
static ATermList innermost_list(PT_Args args);

/*}}}  */

/*{{{  void reg_memo_table(ATermTable *db, char *name) */

void reg_memo_table(ATermTable *db, char *name)
{
  memo_tables[nr_memo_tables] = db;
  memo_table_names[nr_memo_tables] = name;

  nr_memo_tables++;
}

/*}}}  */
/*{{{  void print_memo_table_sizes() */

void print_memo_table_sizes()
{
  int i, nr_key_nodes, nr_value_nodes;
  ATermList keys, values;

  for (i=0; i<nr_memo_tables; i++) {
    keys = ATtableKeys(*memo_tables[i]);
    values = ATtableValues(*memo_tables[i]);
    nr_key_nodes = ATcalcUniqueSubterms((ATerm) keys);
    nr_value_nodes = ATcalcUniqueSubterms((ATerm) values);

    fprintf(stderr, "table %s has %d elements, %d + %d = %d unique nodes.\n",
	    memo_table_names[i], ATgetLength(keys), 
	    nr_key_nodes, nr_value_nodes, nr_key_nodes+nr_value_nodes);
  }
}

/*}}}  */


/*{{{  ATerm innermost(PT_Tree tree) */

/* This function is the core of the innermost reduction strategy. Given the
 * AsFIx representation of a term to be reduced the c functions for rewriting
 * are called in an innermost manner.  Here we use the "call-by-value" mechanism
 * of C to implement the innermost strategy.
 */

ATerm innermost(PT_Tree tree)
{
  ATerm result = (ATerm) tree;
#ifdef KEEP_ANNOTATIONS  
  ATerm annos = PT_getTreeAnnotations(tree);
#endif

  if (PT_isTreeLayout(tree)) {
    result = NULL;
  }
  else if (PT_isTreeLit(tree)) {
    result = NULL;
  }
  else if (PT_isTreeAppl(tree)) {
    PT_Production prod = PT_getTreeProd(tree);
    PT_Args args = PT_getTreeArgs(tree);

    if (PT_hasProductionBracketAttr(prod)) {
      result = innermost(PT_getArgsArgumentAt(args, 2));    
    }
    else if (ASF_isTreeTraversalFunction((ASF_Tree) tree)) {
      PT_Production origProd = PT_getTreeProd(tree);
      PT_Production prod;
      PT_Args args;

      tree = ASC_transformTraversalFunction(tree);
      prod = PT_getTreeProd(tree);
      args = PT_getTreeArgs(tree);

      result = call(prod, innermost_list(args));

      if (ATgetAFun((ATermAppl) result) == tuplesym) {
       result = correct_tuple(result, (ATerm) PT_getProductionRhs(origProd));
      }       
    }
    else {
      result = call(prod, innermost_list(args));
    }
  } else if (PT_isTreeAmb(tree)) {
    ATerror("Ambiguous parse tree not supported\n");
    return NULL;
  }

#ifdef KEEP_ANNOTATIONS  
  if (annos != NULL) {
    result = ATsetAnnotations(result, annos);
  }
#endif

  return result;
}

/*}}}  */

/*{{{  static ATermList innermost_list(PT_Args args) */

/* The function innermost_list takes care of the normalization
 * of the elements of a list (of arguments) with respect to the innermost
 * reduction strategy. Here we use the "call-by-value" mechanism
 * of C to implement the innermost strategy.
 */

static ATermList innermost_list(PT_Args args)
{
  ATermList result = ATempty;
  int length = PT_getArgsLength(args);
  ATerm el;
 
  /* When a list is shorter than 16 elements, we assume that
     it is not worth it to malloc a buffer. We use ATreverse
     to restore the correct list order. */
  if(length < 16) {
    while(PT_hasArgsHead(args)) {
      el = innermost(PT_getArgsHead(args));
      if(el)  
	result = ATinsert(result, el); 
      args = PT_getArgsTail(args);
    }
    return ATreverse(result);
  } else {

    /* We don't use term_store here because of the
     * recursive calls to innermost, and the fact that
     * slice (which uses term_store) may be called by
     * the generated code.
     */
    int idx = 0;
    ATerm *elems = (ATerm *)malloc(sizeof(ATerm)*length);
    if(!elems) {
      ATabort("innermost_list: no room for %d elements.\n", length);
    }

    while(PT_hasArgsHead(args)) {
      elems[idx++] = PT_makeTermFromTree(PT_getArgsHead(args));
      args = PT_getArgsTail(args);
    }
    assert(idx == length);

    for(--idx; idx>=0; idx--) {
      el = innermost(PT_makeTreeFromTerm(elems[idx]));
      if(el) {
	result = ATinsert(result, el);
      }
    }
		
    free(elems);
    return result;
  }
}

/*}}}  */
/*{{{  static ATerm call_unknown(PT_Production prod, ATermList args) */

static ATerm call_unknown(PT_Production prod, ATermList args)
{
  char *escaped = prodToEscapedString(prod);
  ATerm result = NULL;
  int arity;
  Symbol sym;
  
  if (PT_isProductionDefault(prod)) {
    arity = ATgetLength(args);
    sym = ATmakeAFun(escaped, arity, ATfalse);
    ATprotectAFun(sym);
    register_prod((ATerm) prod, (funcptr) NULL, sym);
    result = (ATerm) ATmakeApplList(sym, args); 
  }
  else {
    arity = 1;
    sym = ATmakeAFun(escaped, arity, ATfalse);
    ATprotectAFun(sym);
    register_prod((ATerm) prod, (funcptr) NULL, sym);
    result = (ATerm) ATmakeAppl1(sym, (ATerm) args);
  }

  free(escaped);

  return result;
}

/*}}}  */

/*{{{  static ATerm call_using_array(funcptr func, ATerm *arg, int arity) */

static ATerm call_using_array(funcptr func, ATerm *arg, int arity)
{
  /* We cannot use C's variable argument list support,
     because there is no portable way to build a va_list 
     from an arbitrary list.
   */
  switch(arity) {
  case  0: return (*func)();
  case  1: return (*func)(arg[0]);
  case  2: return (*func)(arg[0],arg[1]);
  case  3: return (*func)(arg[0],arg[1],arg[2]);
  case  4: return (*func)(arg[0],arg[1],arg[2],arg[3]);
  case  5: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4]);
  case  6: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5]);
  case  7: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6]);
  case  8: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7]);
  case  9: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8]);
  case 10: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9]);
  case 11: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10]);
  case 12: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11]);
  case 13: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11],
			  arg[12]);
  case 14: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11],
			  arg[12],arg[13]);
  case 15: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11],
			  arg[12],arg[13],arg[14]);
  case 16: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11],
			  arg[12],arg[13],arg[14],arg[15]);
  case 17: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11],
			  arg[12],arg[13],arg[14],arg[15],arg[16]);
  case 18: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11],
			  arg[12],arg[13],arg[14],arg[15],arg[16],arg[17]);
  case 19: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11],
			  arg[12],arg[13],arg[14],arg[15],arg[16],arg[17],
			  arg[18]);
  case 20: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11],
			  arg[12],arg[13],arg[14],arg[15],arg[16],arg[17],
			  arg[18],arg[19]);
  case 21: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11],
			  arg[12],arg[13],arg[14],arg[15],arg[16],arg[17],
			  arg[18],arg[19],arg[20]);
  case 22: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11],
			  arg[12],arg[13],arg[14],arg[15],arg[16],arg[17],
			  arg[18],arg[19],arg[20],arg[21]);
  case 23: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11],
			  arg[12],arg[13],arg[14],arg[15],arg[16],arg[17],
			  arg[18],arg[19],arg[20],arg[21],arg[22]);
  case 24: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11],
			  arg[12],arg[13],arg[14],arg[15],arg[16],arg[17],
			  arg[18],arg[19],arg[20],arg[21],arg[22],arg[23]);
  case 25: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11],
			  arg[12],arg[13],arg[14],arg[15],arg[16],arg[17],
			  arg[18],arg[19],arg[20],arg[21],arg[22],arg[23],
			  arg[24]);
  case 26: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11],
			  arg[12],arg[13],arg[14],arg[15],arg[16],arg[17],
			  arg[18],arg[19],arg[20],arg[21],arg[22],arg[23],
			  arg[24],arg[25]);
  case 27: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11],
			  arg[12],arg[13],arg[14],arg[15],arg[16],arg[17],
			  arg[18],arg[19],arg[20],arg[21],arg[22],arg[23],
			  arg[24],arg[25],arg[26]);
  case 28: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11],
			  arg[12],arg[13],arg[14],arg[15],arg[16],arg[17],
			  arg[18],arg[19],arg[20],arg[21],arg[22],arg[23],
			  arg[24],arg[25],arg[26],arg[27]);
  case 29: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11],
			  arg[12],arg[13],arg[14],arg[15],arg[16],arg[17],
			  arg[18],arg[19],arg[20],arg[21],arg[22],arg[23],
			  arg[24],arg[25],arg[26],arg[27],arg[28]);
  case 30: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11],
			  arg[12],arg[13],arg[14],arg[15],arg[16],arg[17],
			  arg[18],arg[19],arg[20],arg[21],arg[22],arg[23],
			  arg[24],arg[25],arg[26],arg[27],arg[28],arg[29]);
  case 31: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11]
			  ,arg[12],arg[13],arg[14],arg[15],arg[16],arg[17],
			  arg[18],arg[19],arg[20],arg[21],arg[22],arg[23],
			  arg[24],arg[25],arg[26],arg[27],arg[28],arg[29],
			  arg[30]);
  case 32: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11],
			  arg[12],arg[13],arg[14],arg[15],arg[16],arg[17],
			  arg[18],arg[19],arg[20],arg[21],arg[22],arg[23],
			  arg[24],arg[25],arg[26],arg[27],arg[28],arg[29],
			  arg[30],arg[31]);
  case 33: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],
			  arg[6],arg[7],arg[8],arg[9],arg[10],arg[11],
			  arg[12],arg[13],arg[14],arg[15],arg[16],arg[17],
			  arg[18],arg[19],arg[20],arg[21],arg[22],arg[23],
			  arg[24],arg[25],arg[26],arg[27],arg[28],arg[29],
			  arg[30],arg[31],arg[32]);
  default:
    ATabort("too many arguments: %d\n", arity);
  }
  return NULL;
}

/*}}}  */
/*{{{  static ATerm call_using_list(funcptr func, ATermList arg) */

static ATerm call_using_list(funcptr func, ATermList args)
{
  ATermList list = args;
  ATerm arg[33];
  int idx = 0;

  while(!ATisEmpty(list)) {
    arg[idx++] = ATgetFirst(list);
    list = ATgetNext(list);
  }

  return call_using_array(func, arg, ATgetLength(args));
}

/*}}}  */

/* This function is used in innermost to call a c function for
 * a given AsFix production. Note that the arguments are in normal form
 * because of the innermost reduction strategy. Apparently there is
 * an upper limit on the number of arguments of a production (32)!
 *
 * The functionality of this function is to convert the argument list in
 * ATermList form to a c function call and to lookup the actual funcptr.
 */

/*{{{  static ATerm call(PT_Production prod, ATermList args) */

static ATerm call(PT_Production prod, ATermList args)
{
  funcptr func = basic_lookup_func(PT_makeTermFromProduction(prod));
 
  if (func == NULL) {
    return call_unknown(prod, args); 
  }

  if (PT_isProductionList(prod)) {
    return (*func)((ATerm) args);
  }

  /* otherwise we have a normal function application */

  return call_using_list(func, args);
}



/*}}}  */

/*{{{  ATerm unquote(ATerm t) */

/* Code to unqoute delayed reduction of terms, in order to implement
 * the outermost strategy. This algorithm is known to be 'not optimal'.
 * We refer to the work of Wan Fokkink, Pum Walters and Jasper Kamperman
 * for better implementation ideas.
 */

ATerm unquote(ATerm t)
{
  Symbol s;
  ATerm a0,a1,a2,a3,a4,a5,a6;

  if (ATmatch(t,"quote(<int>)",&s)) {
    funcptr func = lookup_func_given_sym(s);
    return (*func)();
  }
  if (ATmatch(t,"quote(<int>,<term>)",&s,&a0)) {
    if (s == make_listsym)
      return make_list(unquote(a0));
    else {
      funcptr func = lookup_func_given_sym(s);
      return (*func)(unquote(a0));
    }
  }
  if (ATmatch(t,"quote(<int>,<term>,<term>)",&s,&a0,&a1)) {
    if (s == concsym)
      return (ATerm)ATconcat((ATermList)unquote(a0),(ATermList)unquote(a1));
    else {
      funcptr func = lookup_func_given_sym(s);
      return (*func)(unquote(a0),unquote(a1));
    }
  }
  if (ATmatch(t,"quote(<int>,<term>,<term>,<term>)",&s,&a0,&a1,&a2)) {
    funcptr func = lookup_func_given_sym(s);
    return (*func)(unquote(a0),unquote(a1),unquote(a2));
  }
  if (ATmatch(t,"quote(<int>,<term>,<term>,<term>,<term>)",
              &s,&a0,&a1,&a2,&a3)) {
    funcptr func = lookup_func_given_sym(s);
    return (*func)(unquote(a0),unquote(a1),unquote(a2),unquote(a3));
  }
  if (ATmatch(t,"quote(<int>,<term>,<term>,<term>,<term>,<term>)",
              &s,&a0,&a1,&a2,&a3,&a4)) {
    funcptr func = lookup_func_given_sym(s);
    return (*func)(unquote(a0),unquote(a1),unquote(a2),unquote(a3),unquote(a4));
  }
  if (ATmatch(t,"quote(<int>,<term>,<term>,<term>,<term>,<term>,<term>)",
              &s,&a0,&a1,&a2,&a3,&a4,&a5)) {
    funcptr func = lookup_func_given_sym(s);
    return (*func)(unquote(a0),unquote(a1),unquote(a2),unquote(a3),unquote(a4),unquote(a5));
  }
  if (ATmatch(t,"quote(<int>,<term>,<term>,<term>,<term>,<term>,<term>,<term>)",
              &s,&a0,&a1,&a2,&a3,&a4,&a5,&a6)) {
    funcptr func = lookup_func_given_sym(s);
    return (*func)(unquote(a0),unquote(a1),unquote(a2),unquote(a3),unquote(a4),unquote(a5),unquote(a6));
  }

  return t;
}

/*}}}  */
/*{{{  ATerm slice(ATerm l1, ATerm l2) */

/* Constructs the slice of a list starting at index "l1" and ending JUST BEFORE 
 * index "l2". If the slice fits into the term_store a fast way of
 * copying can be used, otherwise the term_store is filled and the
 * rest is processed in a less efficient way.
 */

ATerm slice(ATerm l1, ATerm l2)
{
  ATermList result;
  int i, len;

  if(ATisEmpty((ATermList)l2)) {
    return l1;
  }

  len = slice_length(l1, l2);
  if( MAX_STORE < len )
    len = MAX_STORE;

  for(i=0; i<len; i++) {
    term_store[i] = ATgetFirst((ATermList)l1);
    l1 = (ATerm)ATgetNext((ATermList)l1);
  }

  result = ATempty;

  while(l1 != l2) {
    result = ATappend(result, ATgetFirst((ATermList)l1));
    l1 = (ATerm)ATgetNext((ATermList)l1); 
  }

  for(i=len-1; i>=0; i--) {
    result = ATinsert(result, term_store[i]);
  }
 
  return (ATerm)result;
}

/*}}}  */
/*{{{  ATerm make_list(ATerm t) */

ATerm make_list(ATerm t)
{
  if(ATgetType(t) == AT_LIST)  {
    return t;
  }
  else {
    return singleton(t);
  }
}

/*}}}  */

/*{{{  static ATermList call_kids_trafo_list(funcptr trav, ATermList args) */

static ATermList call_kids_trafo_list(funcptr trav, ATermList args, 
				 ATermList extra_args)
{
  ATermList result = ATempty;
  ATerm el;

  for(;!ATisEmpty(args);args = ATgetNext(args)) {
    el = call_using_list(trav,ATinsert(extra_args,ATgetFirst(args)));
    
    if(el) {
      result = ATinsert(result, el);
    }
  }

  return ATreverse(result);
}
/*}}}  */
/*{{{  static ATermList call_kids_accu_list(funcptr trav, ATermList args,  */

static ATerm call_kids_accu_list(funcptr trav, ATermList args, 
	  	                 ATerm accu, ATermList extra_args)
{
  for(;!ATisEmpty(args); args = ATgetNext(args)) {
    accu = call_using_list(trav,ATinsert(
				  ATinsert(extra_args, accu),
				    ATgetFirst(args)));
  }

  return accu;
}

/*}}}  */
/*{{{  static ATerm call_kids_accutrafo_list(funcptr trav, ATermList args,  */

static ATerm call_kids_accutrafo_list(funcptr trav, ATermList args, ATerm accu, 
				      ATermList extra_args)
{
  ATerm tuple;
  ATermList result = ATempty;
  ATerm el;

  for(;!ATisEmpty(args); args = ATgetNext(args)) {
    tuple = call_using_list(trav,ATinsert(
				  ATinsert(extra_args, accu),
				    ATgetFirst(args)));

    el = ATgetArgument((ATermAppl) tuple, 0);
    accu = ATgetArgument((ATermAppl) tuple, 1);

    if (el) {
      result = ATinsert(result, el);
    }
  }

  result = ATreverse(result);

  return (ATerm) ATmakeAppl2(tuplesym, (ATerm) result,accu);
}

/*}}}  */

/*{{{  ATerm call_kids_trafo(funcptr trav, ATerm arg0, ATermList extra_args) */

ATerm call_kids_trafo(funcptr trav, ATerm arg0, ATermList extra_args)
{
  int type = ATgetType(arg0);

  if (type == AT_APPL) {
    Symbol sym;
    funcptr func;
    ATerm arg[33];
    int idx;
    ATermList args;
    ATermList list;

    args = ATgetArguments((ATermAppl) arg0);
    assert(ATgetLength(args) < 33);

    for(idx = 0, list = args;!ATisEmpty(list); list = ATgetNext(list), idx++) {
      arg[idx] = ATgetFirst(list);

      switch(ATgetType(arg[idx])) {
	case AT_APPL:
	  arg[idx] = call_using_list(trav, ATinsert(extra_args,arg[idx]));
	  break;
	case AT_LIST:
	  assert(idx == 0 && "a list production has only 1 child (a list)");
	  arg[idx] = (ATerm) call_kids_trafo_list(trav, (ATermList) arg[idx],
						  extra_args);
	  break;
	default:
	  ATerror("Unexpected term type %d in call_kids_trafo\n");
	  return NULL;
      }
    }
    
    sym = get_sym(arg0);
    func = lookup_func_given_sym(sym);

    if (func) {
      arg0 = call_using_array(func, arg, ATgetLength(args));
    }
    else {
      arg0 = (ATerm) ATmakeApplArray(ATgetAFun((ATermAppl) arg0), arg); 
    }
  }
  else if (type == AT_LIST) {
    arg0 = (ATerm) call_kids_trafo_list(trav, (ATermList) arg0, extra_args);
  }


  return arg0;
}

/*}}}  */
/*{{{  ATerm call_kids_accu(funcptr trav, ATerm arg0, ATerm arg1, ATermList extra_args) */

ATerm call_kids_accu(funcptr trav, ATerm arg0, ATerm arg1, ATermList extra_args)
{
  int type = ATgetType(arg0);

  if (type == AT_APPL) {
    int idx;
    ATermList args;
    ATermList list;

    args = ATgetArguments((ATermAppl) arg0);
    assert(ATgetLength(args) < 33);

    for(idx=0, list = args;!ATisEmpty(list); list = ATgetNext(list), idx++) {
      ATerm head = ATgetFirst(list);

      switch(ATgetType(head)) {
	case AT_APPL:
	  arg1 = call_using_list(trav, 
				 ATinsert(ATinsert(extra_args, arg1),head));
	  break;
	case AT_LIST:
	  assert(idx == 0 && "a list production has only 1 child (a list)");
	  arg1 = call_kids_accu_list(trav, (ATermList) head, arg1, extra_args);
	  break;
	default:
	  ATerror("Unexpected term type %d in call_kids_accu\n");
	  return NULL;
      }
    }
  }
  else if (type == AT_LIST) {
    arg1 = call_kids_accu_list(trav, (ATermList) arg0, arg1, extra_args);
  }

  return arg1;
}

/*}}}  */
/*{{{  ATerm call_kids_accutrafo(funcptr trav, Symbol tuple, ATerm arg0, ATerm arg1,  */

ATerm call_kids_accutrafo(funcptr trav, ATerm arg0, ATerm arg1, 
			  ATermList extra_args)
{
  int type = ATgetType(arg0);

  if (type == AT_APPL) {
    int idx;
    ATermList args;
    Symbol sym;
    funcptr func;
    ATerm arg[33];
    ATermList list;
    ATerm tuple;

    args = ATgetArguments((ATermAppl) arg0);
    assert(ATgetLength(args) < 33);

    for(idx = 0, list = args;!ATisEmpty(list); list = ATgetNext(list), idx++) {
      arg[idx] = ATgetFirst(list);

      switch(ATgetType(arg[idx])) {
	case AT_APPL:
	  tuple = call_using_list(trav, ATinsert(
				 ATinsert(extra_args, arg1),arg[idx]));
	  break;
	case AT_LIST:
	  assert(idx == 0 && "a list production has only 1 child (a list)");
	  tuple = call_kids_accutrafo_list(trav, (ATermList) arg[idx], arg1,
					   extra_args);
	  break;
	default:
	  ATerror("Unexpected term type %d in call_kids_accutrafo\n");
	  return NULL;
      }

      arg[idx] = ATgetArgument((ATermAppl) tuple, 0);
      arg1 = ATgetArgument((ATermAppl) tuple, 1);
    }

    sym = get_sym(arg0);
    func = lookup_func_given_sym(sym);

    if (func) {
      arg0 = call_using_array(func, arg, ATgetLength(args));
    }
    else {
      arg0 = (ATerm) ATmakeApplArray(ATgetAFun((ATermAppl) arg0), arg); 
    }
  }
  else if (type == AT_LIST) {
     return call_kids_accutrafo_list(trav, (ATermList) arg0, arg1, extra_args);
  }

  return (ATerm) ATmakeAppl2(tuplesym , arg0,arg1);
}

/*}}}  */

/*{{{  memo profiling */

/*
 * Write memo profiling info to the file "memo.prof"
 */

#ifdef MEMO_PROFILING
void write_memo_profile()
{
  FILE *f = fopen("memo.prof", "wb");
  ATermList keys;

  if(!f)
    ATabort("cannot create file 'memo.prof'\n");

  keys = ATtableKeys(prof_table);

  while(!ATisEmpty(keys)) {
    ATerm key = ATgetFirst(keys);
    ATermAppl stats = (ATermAppl)ATtableGet(prof_table, key);
    ATerm asfix = lookup_prod(ATgetSymbol((ATermAppl)key));
		
    ATfprintf(f, "%t ", stats);
    AFsourceToFile(asfix, f);
    ATfprintf(f, "\n");
    keys = ATgetNext(keys);
  }
  ATfprintf(f, "\n");

  fclose(f);
}
#endif


/*}}}  */

/*{{{  void ASC_initRunTime(int tableSize) */

void ASC_initRunTime(int tableSize)
{
  int i;

  /* make characters */
  for(i=0; i<256; i++) {
    ATprotect(&char_table[i]);
    char_table[i] = (ATerm) ATmakeInt(i);
  }

  sym_quote0 = ATmakeSymbol("quote", 1, ATfalse);
  ATprotectSymbol(sym_quote0);
  sym_quote1 = ATmakeSymbol("quote", 2, ATfalse);
  ATprotectSymbol(sym_quote1);
  sym_quote2 = ATmakeSymbol("quote", 3, ATfalse);
  ATprotectSymbol(sym_quote2);
  sym_quote3 = ATmakeSymbol("quote", 4, ATfalse);
  ATprotectSymbol(sym_quote3);
  sym_quote4 = ATmakeSymbol("quote", 5, ATfalse);
  ATprotectSymbol(sym_quote4);
  sym_quote5 = ATmakeSymbol("quote", 6, ATfalse);
  ATprotectSymbol(sym_quote5);
  sym_quote6 = ATmakeSymbol("quote", 7, ATfalse);
  ATprotectSymbol(sym_quote6);
  sym_quote7 = ATmakeSymbol("quote", 8, ATfalse);
  ATprotectSymbol(sym_quote7);
  make_listsym = ATmakeSymbol("make_list", 1, ATfalse);
  ATprotectSymbol(make_listsym);
  tuplesym = ATmakeSymbol("tuple", 2, ATfalse);
  ATprotectSymbol(tuplesym);

#ifdef MEMO_PROFILING
  prof_table = ATtableCreate(2048, 80);
  record_sym = ATmakeSymbol("stats", 2, ATfalse);
  ATprotectSymbol(record_sym);

  atexit(write_memo_profile);
#endif

  PT_initMEPTApi();

  c_rehash(tableSize);
}

/*}}}  */
/*{{{  PT_ParseTree toasfix(ATerm term) */

PT_ParseTree toasfix(ATerm term)
{
  PT_Tree tree;

  tree = muASFToTree(term);  

  return PT_makeValidParseTreeFromTree(tree);
}

/*}}}  */

/*{{{  ATerm get_sort(ATerm tree) */

ATerm get_sort(ATerm tree)
{
  if (ATgetType(tree) == AT_APPL) {
    Symbol sym = get_sym(tree);

    if (sym) {
      return ATgetArgument((ATermAppl) lookup_prod(sym),1); 
    }
  }

  return (ATerm) ATempty;
}

/*}}}  */

/*{{{  ATerm correct_tuple(ATerm arg, ATerm rhs) */

ATerm correct_tuple(ATerm arg, ATerm rhs)
{
  PT_Symbol rhsSymbol = PT_SymbolFromTerm(rhs);
  PT_Symbol left;
  PT_Symbol right;
  PT_Symbols lhs;
  PT_Symbol l = PT_makeSymbolCf(PT_makeSymbolOpt(PT_makeSymbolLayout()));
  PT_Production prod;
  ATermList args = ATgetArguments((ATermAppl) arg);


  assert(PT_isSymbolCf(rhsSymbol) && "Only context-free tuples allowed");

  rhsSymbol = PT_getSymbolSymbol(rhsSymbol);

  assert(PT_isSymbolTuple(rhsSymbol) && "expect tuple symbol in accu,trafo");

  left = PT_getSymbolLhs(rhsSymbol);
  right = PT_getSymbolsHead(PT_getSymbolRest(rhsSymbol));

  lhs = PT_makeSymbolsList(PT_makeSymbolLit("<"),
        PT_makeSymbolsList(l,
        PT_makeSymbolsList(PT_makeSymbolCf(left),
        PT_makeSymbolsList(l,
        PT_makeSymbolsList(PT_makeSymbolLit(","),
        PT_makeSymbolsList(l,
        PT_makeSymbolsList(PT_makeSymbolCf(right),
        PT_makeSymbolsList(l,
        PT_makeSymbolsList(PT_makeSymbolLit(">"),
			   PT_makeSymbolsEmpty())))))))));

  prod = PT_makeProductionDefault(lhs,PT_makeSymbolCf(rhsSymbol),
				  PT_makeAttributesNoAttrs());
  return call(prod, args);
}

/*}}}  */
