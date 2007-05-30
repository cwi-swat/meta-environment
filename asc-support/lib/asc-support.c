/* $Id$ */

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
#include "asc-muasf2pt.h"
#include "asc-prod2str.h"
#include "asc-ambiguity.h"
#include "asc-termstore.h"

/*}}}  */

/*{{{  profiling declarations */

unsigned int rewrite_steps = 0;

#ifdef MEMO_PROFILING
ATermTable prof_table = NULL;
AFun record_sym = -1;
#endif

/*}}}  */
/*{{{  global variables */

/* A table to convert integers to ATermInts. 
 */
ATerm char_table[256] = {NULL};

AFun tuplesym;
AFun make_listsym;
AFun concsym;    

/* The ambiguity cache is needed to prevent exponential 
 * behavior in case of nested ambiguities.
 */
ATermTable ambiguityCache = NULL;

/* 
 * configuration options that guide the mapping
 * from parse trees to muasf terms and back
 */
ATbool keep_annotations = ATfalse;
ATbool keep_layout = ATfalse;

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

//*{{{  void setKeepLayout(ATbool on)  */

void setKeepLayout(ATbool on) 
{
  keep_layout = on;
}

/*}}}  */
/*{{{  ATbool getKeepLayout()  */

ATbool getKeepLayout(ATbool on) 
{
  return keep_layout;
}

/*}}}  */
/*{{{  void setKeepAnnotations(ATbool on)  */

void setKeepAnnotations(ATbool on) 
{
  keep_annotations = on;
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
  ATerm annos = keep_annotations ? PT_getTreeAnnotations(tree) : NULL;

  if (!keep_layout && PT_isTreeLayout(tree)) {
    result = NULL;
  }
  else if (!keep_layout && PT_isTreeLit(tree)) {
    result = NULL;
  }
  else if (!keep_layout && PT_isTreeCilit(tree)) {
    result = NULL;
  }
  else if (PT_isTreeAppl(tree)) {
    PT_Production prod = PT_getTreeProd(tree);
    PT_Args args = PT_getTreeArgs(tree);

    if (PT_hasProductionBracketAttr(prod)) {
      result = innermost(PT_getArgsTreeAt(args, 2));    
    }
    else {
      if (ASF_isTreeTraversalFunction((ASF_Tree) tree)) {
	ATwarning("Warning: traversal functions are not activated in input term\n");
      }

      if (PT_isTreeApplList(tree) 
	  && PT_prodHasIterSepAsRhs(PT_getTreeProd(tree))) {
	/* remove separators */
	args = PT_removeArgsLiterals(args);
      }

      result = call(prod, innermost_list(args));
    }
  } else if (PT_isTreeAmb(tree)) {
    ATerm memo = ATtableGet(ambiguityCache, (ATerm) tree);

    if (memo == NULL) {
      PT_Tree constructor = ASC_ambToConstructor(tree);
      result = innermost(constructor);
      ATtablePut(ambiguityCache, (ATerm) tree, result);
    }
    else {
      result = memo;
    }
  }

  if (annos != NULL && result != NULL) {
    result = ATsetAnnotations(result, annos);
  }

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
  int idx = 0;

  if (length > 0) {
    TERM_STORE_FRAME(length,
    while(PT_hasArgsHead(args)) {
      TERM_STORE[idx++] = PT_TreeToTerm(PT_getArgsHead(args));
      args = PT_getArgsTail(args);
    }
    assert(idx == length);

    for(--idx; idx>=0; idx--) {
      el = innermost(PT_TreeFromTerm(TERM_STORE[idx]));
      if (el) {
	if (ATgetType(el) == AT_LIST) {
	  /* happens only when a function returns a list directly */
	  result = ATconcat(result, (ATermList) el);
	}
	else {
	  result = ATinsert(result, el);
	}
      }
    }
    )		
  }
  return result;
}

/*}}}  */
/*{{{  static ATerm call_unknown(PT_Production prod, ATermList args) */

static ATerm call_unknown(PT_Production prod, ATermList args)
{
  char *escaped = prodToEscapedString(prod);
  ATerm result = NULL;
  int arity;
  AFun sym;
  
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
  case 34: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],arg[6],
			  arg[7],arg[8],arg[9],arg[10],arg[11],arg[12],
			  arg[13],arg[14],arg[15],arg[16],arg[17],arg[18],
			  arg[19],arg[20],arg[21],arg[22],arg[23],arg[24],
			  arg[25],arg[26],arg[27],arg[28],arg[29],arg[30],
			  arg[31],arg[32],arg[33]);
  case 35: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],arg[6],
			  arg[7],arg[8],arg[9],arg[10],arg[11],arg[12],
			  arg[13],arg[14],arg[15],arg[16],arg[17],arg[18],
			  arg[19],arg[20],arg[21],arg[22],arg[23],arg[24],
			  arg[25],arg[26],arg[27],arg[28],arg[29],arg[30],
			  arg[31],arg[32],arg[33],arg[34]);
  case 36: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],arg[6],
			  arg[7],arg[8],arg[9],arg[10],arg[11],arg[12],
			  arg[13],arg[14],arg[15],arg[16],arg[17],arg[18],
			  arg[19],arg[20],arg[21],arg[22],arg[23],arg[24],
			  arg[25],arg[26],arg[27],arg[28],arg[29],arg[30],
			  arg[31],arg[32],arg[33],arg[34],arg[35]);
  case 37: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],arg[6],
			  arg[7],arg[8],arg[9],arg[10],arg[11],arg[12],
			  arg[13],arg[14],arg[15],arg[16],arg[17],arg[18],
			  arg[19],arg[20],arg[21],arg[22],arg[23],arg[24],
			  arg[25],arg[26],arg[27],arg[28],arg[29],arg[30],
			  arg[31],arg[32],arg[33],arg[34],arg[35],arg[36]
			 );
  case 38: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],arg[6],
			  arg[7],arg[8],arg[9],arg[10],arg[11],arg[12],
			  arg[13],arg[14],arg[15],arg[16],arg[17],arg[18],
			  arg[19],arg[20],arg[21],arg[22],arg[23],arg[24],
			  arg[25],arg[26],arg[27],arg[28],arg[29],arg[30],
			  arg[31],arg[32],arg[33],arg[34],arg[35],arg[36],
			  arg[37]);
  case 39: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],arg[6],
			  arg[7],arg[8],arg[9],arg[10],arg[11],arg[12],
			  arg[13],arg[14],arg[15],arg[16],arg[17],arg[18],
			  arg[19],arg[20],arg[21],arg[22],arg[23],arg[24],
			  arg[25],arg[26],arg[27],arg[28],arg[29],arg[30],
			  arg[31],arg[32],arg[33],arg[34],arg[35],arg[36],
			  arg[37],arg[38]);
  case 40: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],arg[6],
			  arg[7],arg[8],arg[9],arg[10],arg[11],arg[12],
			  arg[13],arg[14],arg[15],arg[16],arg[17],arg[18],
			  arg[19],arg[20],arg[21],arg[22],arg[23],arg[24],
			  arg[25],arg[26],arg[27],arg[28],arg[29],arg[30],
			  arg[31],arg[32],arg[33],arg[34],arg[35],arg[36],
			  arg[37],arg[38],arg[39]);
  case 41: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],arg[6],
			  arg[7],arg[8],arg[9],arg[10],arg[11],arg[12],
			  arg[13],arg[14],arg[15],arg[16],arg[17],arg[18],
			  arg[19],arg[20],arg[21],arg[22],arg[23],arg[24],
			  arg[25],arg[26],arg[27],arg[28],arg[29],arg[30],
			  arg[31],arg[32],arg[33],arg[34],arg[35],arg[36],
			  arg[37],arg[38],arg[39],arg[40]);
  case 42: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],arg[6],
			  arg[7],arg[8],arg[9],arg[10],arg[11],arg[12],
			  arg[13],arg[14],arg[15],arg[16],arg[17],arg[18],
			  arg[19],arg[20],arg[21],arg[22],arg[23],arg[24],
			  arg[25],arg[26],arg[27],arg[28],arg[29],arg[30],
			  arg[31],arg[32],arg[33],arg[34],arg[35],arg[36],
			  arg[37],arg[38],arg[39],arg[40],arg[41]);
  case 43: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],arg[6],
			  arg[7],arg[8],arg[9],arg[10],arg[11],arg[12],
			  arg[13],arg[14],arg[15],arg[16],arg[17],arg[18],
			  arg[19],arg[20],arg[21],arg[22],arg[23],arg[24],
			  arg[25],arg[26],arg[27],arg[28],arg[29],arg[30],
			  arg[31],arg[32],arg[33],arg[34],arg[35],arg[36],
			  arg[37],arg[38],arg[39],arg[40],arg[41],arg[42]
			 );
  case 44: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],arg[6],
			  arg[7],arg[8],arg[9],arg[10],arg[11],arg[12],
			  arg[13],arg[14],arg[15],arg[16],arg[17],arg[18],
			  arg[19],arg[20],arg[21],arg[22],arg[23],arg[24],
			  arg[25],arg[26],arg[27],arg[28],arg[29],arg[30],
			  arg[31],arg[32],arg[33],arg[34],arg[35],arg[36],
			  arg[37],arg[38],arg[39],arg[40],arg[41],arg[42],
			  arg[43]);
  case 45: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],arg[6],
			  arg[7],arg[8],arg[9],arg[10],arg[11],arg[12],
			  arg[13],arg[14],arg[15],arg[16],arg[17],arg[18],
			  arg[19],arg[20],arg[21],arg[22],arg[23],arg[24],
			  arg[25],arg[26],arg[27],arg[28],arg[29],arg[30],
			  arg[31],arg[32],arg[33],arg[34],arg[35],arg[36],
			  arg[37],arg[38],arg[39],arg[40],arg[41],arg[42],
			  arg[43],arg[44]);
  case 46: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],arg[6],
			  arg[7],arg[8],arg[9],arg[10],arg[11],arg[12],
			  arg[13],arg[14],arg[15],arg[16],arg[17],arg[18],
			  arg[19],arg[20],arg[21],arg[22],arg[23],arg[24],
			  arg[25],arg[26],arg[27],arg[28],arg[29],arg[30],
			  arg[31],arg[32],arg[33],arg[34],arg[35],arg[36],
			  arg[37],arg[38],arg[39],arg[40],arg[41],arg[42],
			  arg[43],arg[44],arg[45]);
  case 47: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],arg[6],
			  arg[7],arg[8],arg[9],arg[10],arg[11],arg[12],
			  arg[13],arg[14],arg[15],arg[16],arg[17],arg[18],
			  arg[19],arg[20],arg[21],arg[22],arg[23],arg[24],
			  arg[25],arg[26],arg[27],arg[28],arg[29],arg[30],
			  arg[31],arg[32],arg[33],arg[34],arg[35],arg[36],
			  arg[37],arg[38],arg[39],arg[40],arg[41],arg[42],
			  arg[43],arg[44],arg[45],arg[46]);
  case 48: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],arg[6],
			  arg[7],arg[8],arg[9],arg[10],arg[11],arg[12],
			  arg[13],arg[14],arg[15],arg[16],arg[17],arg[18],
			  arg[19],arg[20],arg[21],arg[22],arg[23],arg[24],
			  arg[25],arg[26],arg[27],arg[28],arg[29],arg[30],
			  arg[31],arg[32],arg[33],arg[34],arg[35],arg[36],
			  arg[37],arg[38],arg[39],arg[40],arg[41],arg[42],
			  arg[43],arg[44],arg[45],arg[46],arg[47]);
  case 49: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],arg[6],
			  arg[7],arg[8],arg[9],arg[10],arg[11],arg[12],
			  arg[13],arg[14],arg[15],arg[16],arg[17],arg[18],
			  arg[19],arg[20],arg[21],arg[22],arg[23],arg[24],
			  arg[25],arg[26],arg[27],arg[28],arg[29],arg[30],
			  arg[31],arg[32],arg[33],arg[34],arg[35],arg[36],
			  arg[37],arg[38],arg[39],arg[40],arg[41],arg[42],
			  arg[43],arg[44],arg[45],arg[46],arg[47],arg[48]
			 );
  case 50: return (*func)(arg[0],arg[1],arg[2],arg[3],arg[4],arg[5],arg[6],
			  arg[7],arg[8],arg[9],arg[10],arg[11],arg[12],
			  arg[13],arg[14],arg[15],arg[16],arg[17],arg[18],
			  arg[19],arg[20],arg[21],arg[22],arg[23],arg[24],
			  arg[25],arg[26],arg[27],arg[28],arg[29],arg[30],
			  arg[31],arg[32],arg[33],arg[34],arg[35],arg[36],
			  arg[37],arg[38],arg[39],arg[40],arg[41],arg[42],
			  arg[43],arg[44],arg[45],arg[46],arg[47],arg[48],
			  arg[49]);
  default:
    ATabort("too many arguments: %d\n", arity);
  }
  return NULL;
}

/*}}}  */
/*{{{  static ATerm call_using_list(funcptr func, ATermList arg) */

ATerm call_using_list(funcptr func, ATermList args)
{
  ATermList list = args;
  ATerm arg[55];
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
 * an upper limit on the number of arguments of a production (55)!
 *
 * The functionality of this function is to convert the argument list in
 * ATermList form to a c function call and to lookup the actual funcptr.
 */

/*{{{  static ATerm call(PT_Production prod, ATermList args) */

static ATerm call(PT_Production prod, ATermList args)
{
  funcptr func = basic_lookup_func(PT_ProductionToTerm(prod));
 
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

/*{{{  ATerm callLiteralConstructor(PT_Symbol symbol)  */

ATerm callLiteralConstructor(PT_Symbol symbol) 
{
  PT_Production fake = PT_makeProductionDefault(PT_makeSymbolsEmpty(),
						symbol,
						PT_makeAttributesNoAttrs());

  if (basic_lookup_func((ATerm) fake) == NULL) {
    /* TODO: fix this incomplete function */
    PT_Tree tree = PT_makeTreeLit(PT_getSymbolString(symbol));
    ATwarning("new tree: %t\n", tree);
    return innermost(tree);
  }
  else {
    return call(fake, ATempty);
  }
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
  AFun s;
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
  ATermList result = ATempty;
  int i, len;

  if(ATisEmpty((ATermList)l2)) {
    return l1;
  }

  len = slice_length((ATermList) l1, (ATermList) l2);
  if (len > 0) {
  TERM_STORE_FRAME(len,

  for(i=0; i<len; i++) {
    TERM_STORE[i] = ATgetFirst((ATermList)l1);
    l1 = (ATerm)ATgetNext((ATermList)l1);
  }

  result = ATempty;

  assert(l1 == l2);

  for(i=len-1; i>=0; i--) {
    result = ATinsert(result, TERM_STORE[i]);
  }
  )
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

/* The functions for applying traversal functions to children are 
 * highly similar. Code cloning is done to prevent run-time checking
 * of which type a traversal function has. This has a small but significant
 * effect in run-time efficiency.
 */
/*{{{  static ATermList call_kids_trafo_list(funcptr trav, ATermList args) */

static ATermList call_kids_trafo_list(funcptr trav, ATermList args, 
				 ATermList extra_args)
{
  ATermList result = ATempty;
  int length = ATgetLength(args);

  if (length > 0) {
    int i = 0;
    ATbool changed = ATfalse;
    ATermList origArgs = args;

    TERM_STORE_FRAME(length,
    for ( ; !ATisEmpty(args); args = ATgetNext(args)) {
      ATerm arg = ATgetFirst(args);
      ATerm tmp = call_using_list(trav, ATinsert(extra_args, arg));
      if (tmp != arg) {
        changed = ATtrue;
      }
      TERM_STORE[i++] = tmp;
    }

    assert(i == length);

    if (changed) {
      for (--i; i >= 0; i--) {
        ATerm el = TERM_STORE[i];
  
        if (el) {
    	  if (ATgetType(el) == AT_LIST) {
  	    result = ATconcat(result, (ATermList) el);
	  }
	  else {
	    result = ATinsert(result, el);
  	  }
        }
      }
    }
    else {
      result = origArgs;
    }
    )
  }

  return result;
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
  int length = ATgetLength(args);

  if (length > 0) {
    TERM_STORE_FRAME(length,
    int i = 0;
    ATbool changed = ATfalse;
    ATermList origArgs = args;

    for(;!ATisEmpty(args); args = ATgetNext(args)) {
      ATerm arg = ATgetFirst(args);
      ATerm tmp;
      tuple = call_using_list(trav,ATinsert(
					    ATinsert(extra_args, accu),
					    arg));

      tmp = ATgetArgument((ATermAppl) tuple, 0);
      TERM_STORE[i++] = tmp;

      if (tmp != arg) {
        changed = ATtrue;
      }
      accu = ATgetArgument((ATermAppl) tuple, 1);
    }

    assert(i == length);

    if (changed) {
      for (--i; i >=0; i--) {
        ATerm el = TERM_STORE[i];
    
        if (el) {
        result = ATinsert(result, el);
        }
      }
    }
    else {
      result = origArgs;
    }
    )
  }

  return (ATerm) ATmakeAppl2(tuplesym, (ATerm) result,accu);
}

/*}}}  */

/*{{{  ATerm call_kids_trafo(funcptr trav, ATerm arg0, ATermList extra_args) */

ATerm call_kids_trafo(funcptr trav, ATerm arg0, ATermList extra_args)
{
  int type = ATgetType(arg0);
  ATerm annos = keep_annotations ? ATgetAnnotations(arg0) : NULL;

  if (type == AT_APPL) {
    AFun sym;
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

	  if (ATgetType(arg[idx]) == AT_LIST) {
	    ATwarning("Zie je wel!\n"); 
	  }
	  break;
	case AT_LIST:
	  assert(idx == 0 && "a list production has only 1 child (a list)");
	  arg[idx] = (ATerm) call_kids_trafo_list(trav, (ATermList) arg[idx],
					  extra_args);
	  break;
	case AT_INT:
	  break;
	default:
	  ATerror("Unexpected term type %d in call_kids_trafo\n", ATgetType(arg[idx]));
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

  if (arg0 != NULL && annos != NULL) {
    arg0 = ATsetAnnotations(arg0, annos);
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
	case AT_INT:
	  break;
	default:
	  ATerror("Unexpected term type %d in call_kids_accu\n", ATgetType(head));
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
/*{{{  ATerm call_kids_accutrafo(funcptr trav, AFun tuple, ATerm arg0, ATerm arg1,  */

ATerm call_kids_accutrafo(funcptr trav, ATerm arg0, ATerm arg1, 
			  ATermList extra_args)
{
  int type = ATgetType(arg0);
  ATerm annos = keep_annotations ? ATgetAnnotations(arg0) : NULL;

  if (type == AT_APPL) {
    int idx;
    ATermList args;
    AFun sym;
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
	case AT_INT:
	  tuple = (ATerm) ATmakeAppl2(tuplesym , arg[idx],arg1);
	  break;
	default:
	  ATerror("Unexpected term type %d in call_kids_accutrafo\n", ATgetType(arg[idx]));
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
     arg0 = call_kids_accutrafo_list(trav, (ATermList) arg0, arg1, extra_args);
  }

  if (arg0 != NULL && annos != NULL) {
    arg0 = ATsetAnnotations(arg0, annos);
  }

  return (ATerm) ATmakeAppl2(tuplesym , arg0,arg1);
}

/*}}}  */

/* Again, the same functions for traversal over children, but now with
 * support for detecting a failure to rewrite anywhere. The code cloning
 * is again justified by efficiency considerations.
 */
/*{{{  static ATermList call_kids_trafo_list(funcptr trav, ATermList args) */

static ATermList call_kids_trafo_list_with_fail(funcptr trav, ATermList args, 
						ATermList extra_args)
{
  ATermList result = ATempty;
  ATbool fail = ATtrue;
  int length = ATgetLength(args);

  if (length > 0) {
    int i = 0;
    ATermList origArgs = args;

    TERM_STORE_FRAME(length,
    for (; !ATisEmpty(args); args = ATgetNext(args)) {
      ATerm head = ATgetFirst(args);
      ATerm tmp = call_using_list(trav,ATinsert(extra_args,head));

      if (tmp) {
	fail = ATfalse;
	TERM_STORE[i++] = tmp;
      }
      else {
	TERM_STORE[i++] = head;
      }
    }

    assert(i == length);

    if (!fail) {
      for (--i; i >= 0; i--) {
        ATerm el = TERM_STORE[i];
        result = ATinsert(result, el);
      }
    }
    else {
      result = origArgs;
    }
    )
  }

  if (!fail) {
    return result;
  }
  else {
    return NULL;
  }
}
/*}}}  */
/*{{{  static ATermList call_kids_accu_list(funcptr trav, ATermList args,  */

static ATerm call_kids_accu_list_with_fail(funcptr trav, ATermList args, 
					   ATerm accu, ATermList extra_args)
{
  ATbool fail = ATtrue;

  for(;!ATisEmpty(args); args = ATgetNext(args)) {
    ATerm saved = accu;
    accu = call_using_list(trav,ATinsert(ATinsert(extra_args, accu),
					 ATgetFirst(args)));

    if (accu != NULL) {
      fail = ATfalse;
    }
    else {
      accu = saved;
    }
  }

  if (!fail) {
    return accu;
  }

  return NULL;
}

/*}}}  */
/*{{{  static ATerm call_kids_accutrafo_list(funcptr trav, ATermList args,  */

static ATerm call_kids_accutrafo_list_with_fail(funcptr trav, ATermList args, 
						ATerm accu, 
						ATermList extra_args)
{
  ATerm tuple;
  ATermList result = ATempty;
  ATbool fail = ATtrue;
  int length = ATgetLength(args);

  if (length > 0) {
    int i = 0;
    ATermList origArgs = args;

    TERM_STORE_FRAME(length,
    for(;!ATisEmpty(args); args = ATgetNext(args)) {
      ATerm head = ATgetFirst(args);
      tuple = call_using_list(trav,ATinsert(
					    ATinsert(extra_args, accu), head));

      if (tuple) {
	fail = ATfalse;
	TERM_STORE[i++] = ATgetArgument((ATermAppl) tuple, 0);
	accu = ATgetArgument((ATermAppl) tuple, 1);
      }
      else {
	TERM_STORE[i++] = head;
      }
    }

    assert(i == length);

    if (!fail) {
      for (--i; i >= 0; i--) {
        result = ATinsert(result, TERM_STORE[i]);
      }
    }
    else {
      result = origArgs;
    }
    )
  }

  if (!fail) {
    return (ATerm) ATmakeAppl2(tuplesym, (ATerm) result,accu);
  }
  return NULL;
}

/*}}}  */

/*{{{  ATerm call_kids_trafo(funcptr trav, ATerm arg0, ATermList extra_args) */

ATerm call_kids_trafo_with_fail(funcptr trav, ATerm arg0, ATermList extra_args)
{
  int type = ATgetType(arg0);
  ATerm annos = keep_annotations ? ATgetAnnotations(arg0) : NULL;
  ATbool fail = ATtrue;

  if (type == AT_APPL) {
    AFun sym;
    funcptr func;
    ATerm arg[33];
    int idx;
    ATermList args;
    ATermList list;
    ATerm save;

    args = ATgetArguments((ATermAppl) arg0);
    assert(ATgetLength(args) < 33);

    for(idx = 0, list = args;!ATisEmpty(list); list = ATgetNext(list), idx++) {
      arg[idx] = ATgetFirst(list);
      save =arg[idx];

      switch(ATgetType(arg[idx])) {
	case AT_APPL:
	  arg[idx] = call_using_list(trav, ATinsert(extra_args,arg[idx]));
	  break;
	case AT_LIST:
	  assert(idx == 0 && "a list production has only 1 child (a list)");
	  arg[idx] = (ATerm) call_kids_trafo_list_with_fail(trav, 
							    (ATermList)arg[idx],
							    extra_args);
	  break;
	case AT_INT:
	  break;
	default:
	  ATerror("Unexpected term type %d in call_kids_trafo\n", ATgetType(arg[idx]));
	  return NULL;
      }

      if (arg[idx] != NULL) {
	fail = ATfalse;
      }
      else {
	arg[idx] = save;
      }
    }
   
    if (!fail) { 
      sym = get_sym(arg0);
      func = lookup_func_given_sym(sym);

      if (func) {
	arg0 = call_using_array(func, arg, ATgetLength(args));
      }
      else {
	arg0 = (ATerm) ATmakeApplArray(ATgetAFun((ATermAppl) arg0), arg); 
      }
    }
  }
  else if (type == AT_LIST) {
    arg0 = (ATerm) call_kids_trafo_list_with_fail(trav, 
						  (ATermList) arg0, extra_args);

    if (arg0) {
      fail = ATfalse;
    }
  }

  if (arg0 != NULL && annos != NULL) {
    arg0 = ATsetAnnotations(arg0, annos);
  }

  if (!fail) {
    return arg0;
  }

  return NULL;
}

/*}}}  */
/*{{{  ATerm call_kids_accu(funcptr trav, ATerm arg0, ATerm arg1, ATermList extra_args) */

ATerm call_kids_accu_with_fail(funcptr trav, ATerm arg0, ATerm arg1, 
			       ATermList extra_args)
{
  int type = ATgetType(arg0);
  ATbool fail = ATtrue;
  ATerm save;

  if (type == AT_APPL) {
    int idx;
    ATermList args;
    ATermList list;

    args = ATgetArguments((ATermAppl) arg0);
    assert(ATgetLength(args) < 33);

    for(idx=0, list = args;!ATisEmpty(list); list = ATgetNext(list), idx++) {
      ATerm head = ATgetFirst(list);
      save = arg1;

      switch(ATgetType(head)) {
	case AT_APPL:
	  arg1 = call_using_list(trav, 
				 ATinsert(ATinsert(extra_args, arg1),head));
	  break;
	case AT_LIST:
	  assert(idx == 0 && "a list production has only 1 child (a list)");
	  arg1 = call_kids_accu_list_with_fail(trav, 
					       (ATermList) head, 
					       arg1, extra_args);
	  break;
	default:
	  ATerror("Unexpected term type %d in call_kids_accu\n", ATgetType(head));
	  return NULL;
      }

      if (arg1) {
	fail = ATfalse;
      }
      else {
	arg1 = save;
      }
    }
  }
  else if (type == AT_LIST) {
    arg1 = call_kids_accu_list(trav, (ATermList) arg0, arg1, extra_args);

    if (arg1) {
      fail = ATfalse;
    }
  }

  if (!fail) {
    return arg1;
  }

  return NULL;
}

/*}}}  */
/*{{{  ATerm call_kids_accutrafo(funcptr trav, AFun tuple, ATerm arg0, ATerm arg1,  */

ATerm call_kids_accutrafo_with_fail(funcptr trav, ATerm arg0, ATerm arg1, 
				    ATermList extra_args)
{
  int type = ATgetType(arg0);
  ATerm annos = keep_annotations ? ATgetAnnotations(arg0) : NULL;
  ATbool fail = ATtrue;

  if (type == AT_APPL) {
    int idx;
    ATermList args;
    AFun sym;
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
	  tuple = call_kids_accutrafo_list_with_fail(trav, 
						     (ATermList) arg[idx], arg1,
						     extra_args);
	  break;
	default:
	  ATerror("Unexpected term type %d in call_kids_accutrafo\n", ATgetType(arg[idx]));
	  return NULL;
      }

      if (tuple) {
	fail = ATfalse;
	arg[idx] = ATgetArgument((ATermAppl) tuple, 0);
	arg1 = ATgetArgument((ATermAppl) tuple, 1);
      }
    }

    if (!fail) {
      sym = get_sym(arg0);
      func = lookup_func_given_sym(sym);

      if (func) {
	arg0 = call_using_array(func, arg, ATgetLength(args));
      }
      else {
	arg0 = (ATerm) ATmakeApplArray(ATgetAFun((ATermAppl) arg0), arg); 
      }
    }
  }
  else if (type == AT_LIST) {
     arg0 = call_kids_accutrafo_list(trav, (ATermList) arg0, arg1, extra_args);

     if (arg0) {
       fail = ATfalse;
     }
  }

  if (arg0 != NULL && annos != NULL) {
    arg0 = ATsetAnnotations(arg0, annos);
  }

  if (!fail) {
    return (ATerm) ATmakeAppl2(tuplesym , arg0,arg1);
  }

  return NULL;
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
    ATerm asfix = lookup_prod(ATgetAFun((ATermAppl)key));
		
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

   make_listsym = ATmakeSymbol("make_list", 1, ATfalse);
   ATprotectSymbol(make_listsym);
   tuplesym = ATmakeSymbol("tuple", 2, ATfalse);
   ATprotectSymbol(tuplesym);

#ifdef MEMO_PROFILING
  prof_table = ATtableCreate(2048, 80);
  record_sym = ATmakeAFun("stats", 2, ATfalse);
  ATprotectAFun(record_sym);

  atexit(write_memo_profile);
#endif

  PT_initMEPTApi();
  ASF_initASFMEApi();
  initBuiltins();
  TS_create();

  ambiguityCache = ATtableCreate(1024, 75);
  c_rehash(tableSize);
}

/*}}}  */
/*{{{  PT_ParseTree toasfix(ATerm term) */

PT_Tree toasfix(ATerm term)
{
  PT_Tree tree;

  assert(term != NULL && "parameter check");

  tree = muASFToTree(term);

  return tree;
}

/*}}}  */
/*{{{  PT_ParseTree toasfixNoLayout(ATerm term) */

PT_Tree toasfixNoLayout(ATerm term)
{
  PT_Tree tree;

  tree = muASFToTreeWithLayout(term, PT_makeTreeLayoutEmpty());

  return tree;
}

/*}}}  */

/*{{{  ATerm get_sort(ATerm tree) */

ATerm get_sort(ATerm tree)
{
  if (ATgetType(tree) == AT_APPL) {
    AFun sym = get_sym(tree);

    if (sym) {
      return PT_SymbolToTerm(PT_getProductionRhs(PT_ProductionFromTerm(lookup_prod(sym)))); 
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

  lhs = PT_makeSymbolsMany(PT_makeSymbolLit("<"),
        PT_makeSymbolsMany(l,
        PT_makeSymbolsMany(PT_makeSymbolCf(left),
        PT_makeSymbolsMany(l,
        PT_makeSymbolsMany(PT_makeSymbolLit(","),
        PT_makeSymbolsMany(l,
        PT_makeSymbolsMany(PT_makeSymbolCf(right),
        PT_makeSymbolsMany(l,
        PT_makeSymbolsSingle(PT_makeSymbolLit(">"))))))))));

  prod = PT_makeProductionDefault(lhs,PT_makeSymbolCf(rhsSymbol),
				  PT_makeAttributesNoAttrs());
  return call(prod, args);
}

/*}}}  */
