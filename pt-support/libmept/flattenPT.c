/*
    $Id$  
*/

#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <MEPT-utils.h>

/*{{{  patterns for matching SDF2 regular syntax in AsFix2 trees */

/* Pattern for literal */
static ATerm asfix2_literal = NULL;

/* Pattern for layout cons */
static ATerm asfix2_layout_layout_to_layout = NULL;
static ATerm asfix2_lex_layout_to_cf_layout = NULL;
static ATerm asfix3_lex_iter_layout_to_cf_layout = NULL;

/* Patterns to deal with unflattened lists for lexicals */
static ATerm asfix2_empty_to_star_lex_sort = NULL;
static ATerm asfix2_single_to_plus_lex_sort = NULL;
static ATerm asfix2_plus_to_star_lex_sort = NULL;
static ATerm asfix2_plus_plus_to_plus_lex_sort = NULL;
static ATerm asfix2_star_star_to_star_lex_sort = NULL;
static ATerm asfix2_star_plus_to_plus_lex_sort = NULL;
static ATerm asfix2_plus_star_to_plus_lex_sort = NULL;

/* Patterns to deal with unflattened lists for charclasses */
static ATerm asfix2_empty_to_star_lex_charclass = NULL;
static ATerm asfix2_single_to_plus_lex_charclass = NULL;
static ATerm asfix2_plus_to_star_lex_charclass = NULL;
static ATerm asfix2_plus_plus_to_plus_lex_charclass = NULL;
static ATerm asfix2_star_star_to_star_lex_charclass = NULL;
static ATerm asfix2_star_plus_to_plus_lex_charclass = NULL;
static ATerm asfix2_plus_star_to_plus_lex_charclass = NULL;

/* Patterns to deal with unflattened lists without separators */
static ATerm asfix2_empty_to_star = NULL;
static ATerm asfix2_single_to_plus = NULL;
static ATerm asfix2_plus_to_star = NULL;
static ATerm asfix2_plus_plus_to_plus = NULL;
static ATerm asfix2_star_star_to_star = NULL;
static ATerm asfix2_star_plus_to_plus = NULL;
static ATerm asfix2_plus_star_to_plus = NULL;  

/* Patterns to deal with unflattened lists with separators */
static ATerm asfix2_empty_to_star_sep = NULL;
static ATerm asfix2_single_to_plus_sep = NULL;
static ATerm asfix2_plus_sep_to_star_sep = NULL;
static ATerm asfix2_plus_sep_plus_sep_to_plus_sep = NULL;
static ATerm asfix2_star_sep_star_sep_to_star_sep = NULL;
static ATerm asfix2_star_sep_plus_sep_to_plus_sep = NULL;
static ATerm asfix2_plus_sep_star_sep_to_plus_sep = NULL; 

/*}}}  */
/*{{{  static void init_asfix_patterns() */

static void init_asfix_patterns()
{
  ATprotect(&asfix2_literal);
  asfix2_literal = ATparse("lit(<term>)"); 

  ATprotect(&asfix2_empty_to_star_lex_sort);
  asfix2_empty_to_star_lex_sort  =
    ATparse("prod([],lex(iter-star(sort(<term>))),no-attrs)"); 

  ATprotect(&asfix2_single_to_plus_lex_sort);
  asfix2_single_to_plus_lex_sort =
    ATparse("prod([lex(sort(<term>))],lex(iter(sort(<term>))),no-attrs)");

  ATprotect(&asfix2_plus_to_star_lex_sort);
  asfix2_plus_to_star_lex_sort =
    ATparse("prod([lex(iter(sort(<term>)))]," \
            "lex(iter-star(sort(<term>))),no-attrs)");

  ATprotect(&asfix2_plus_plus_to_plus_lex_sort);
  asfix2_plus_plus_to_plus_lex_sort =
    ATparse("prod([lex(iter(sort(<term>))),lex(iter(sort(<term>)))]," \
            "lex(iter(sort(<term>))),<term>)"); 

  ATprotect(&asfix2_star_star_to_star_lex_sort);
  asfix2_star_star_to_star_lex_sort =
    ATparse("prod([lex(sort(iter-star(<term>)))," \
            "lex(iter-star(sort(<term>)))]," \
            "lex(iter-star(sort(<term>))),<term>)");  

  ATprotect(&asfix2_star_plus_to_plus_lex_sort);
  asfix2_star_plus_to_plus_lex_sort =
    ATparse("prod([lex(iter-star(sort(<term>))),lex(iter(sort(<term>)))]," \
            "lex(iter(sort(<term>))),<term>)");     

  ATprotect(&asfix2_plus_star_to_plus_lex_sort);
  asfix2_plus_star_to_plus_lex_sort =
    ATparse("prod([lex(iter(sort(<term>))),lex(iter-star(sort(<term>)))]," \
            "lex(iter(sort(<term>))),<term>)");  

  ATprotect(&asfix2_empty_to_star_lex_charclass);
  asfix2_empty_to_star_lex_charclass  =
    ATparse("prod([],lex(iter-star(char-class(<term>))),no-attrs)"); 

  ATprotect(&asfix2_single_to_plus_lex_charclass);
  asfix2_single_to_plus_lex_charclass =
    ATparse("prod([char-class(<term>)]," \
            "lex(iter(char-class(<term>))),no-attrs)");             

  ATprotect(&asfix2_plus_to_star_lex_charclass);
  asfix2_plus_to_star_lex_charclass =
    ATparse("prod([lex(iter(char-class(<term>)))]," \
            "lex(iter-star(char-class(<term>))),no-attrs)");  

  ATprotect(&asfix2_plus_plus_to_plus_lex_charclass);
  asfix2_plus_plus_to_plus_lex_charclass =
    ATparse("prod([lex(iter(char-class(<term>)))," \
            "lex(iter(char-class(<term>)))]," \
            "lex(iter(char-class(<term>))),<term>)");       

  ATprotect(&asfix2_star_star_to_star_lex_charclass);
  asfix2_star_star_to_star_lex_charclass =
    ATparse("prod([lex(iter-star(char-class(<term>)))," \
            "lex(iter-star(char-class(<term>)))]," \
            "lex(iter-star(char-class(<term>))),<term>)");  

  ATprotect(&asfix2_star_plus_to_plus_lex_charclass);
  asfix2_star_plus_to_plus_lex_charclass =
    ATparse("prod([lex(iter-star(char-class(<term>)))," \
            "lex(iter(char-class(<term>)))]," \
            "lex(iter(char-class(<term>))),<term>)");      

  ATprotect(&asfix2_plus_star_to_plus_lex_charclass);
  asfix2_plus_star_to_plus_lex_charclass =
    ATparse("prod([lex(iter(char-class(<term>)))," \
            "lex(iter-star(char-class(<term>)))]," \
            "lex(iter(char-class(<term>))),<term>)");   

  ATprotect(&asfix2_layout_layout_to_layout);
  asfix2_layout_layout_to_layout = 
    ATparse("prod([cf(layout),cf(layout)],cf(layout),attrs([assoc(left)]))");

  ATprotect(&asfix2_lex_layout_to_cf_layout);
  asfix2_lex_layout_to_cf_layout = 
    ATparse("prod([lex(layout)],cf(layout),no-attrs)");

  ATprotect(&asfix3_lex_iter_layout_to_cf_layout);
  asfix3_lex_iter_layout_to_cf_layout =
    ATparse("prod([lex(iter(layout))],cf(layout),no-attrs)");

  ATprotect(&asfix2_empty_to_star);
  asfix2_empty_to_star  =
    ATparse("prod([],cf(iter-star(<term>)),no-attrs)"); 

  ATprotect(&asfix2_single_to_plus);
  asfix2_single_to_plus =
    ATparse("prod([cf(<term>)],cf(iter(<term>)),no-attrs)");    

  ATprotect(&asfix2_plus_to_star);
  asfix2_plus_to_star =
    ATparse("prod([cf(iter(<term>))],cf(iter-star(<term>)),no-attrs)");   

  ATprotect(&asfix2_plus_plus_to_plus);
  asfix2_plus_plus_to_plus =
    ATparse("prod([cf(iter(<term>)),cf(opt(layout)),cf(iter(<term>))]," \
            "cf(iter(<term>)),<term>)");

  ATprotect(&asfix2_star_star_to_star);
  asfix2_star_star_to_star =
    ATparse("prod([cf(iter-star(<term>)),cf(opt(layout))," \
            "cf(iter-star(<term>))],cf(iter-star(<term>)),<term>)"); 

  ATprotect(&asfix2_star_plus_to_plus);
  asfix2_star_plus_to_plus =
    ATparse("prod([cf(iter-star(<term>)),cf(opt(layout)),cf(iter(<term>))]," \
            "cf(iter(<term>)),<term>)"); 

  ATprotect(&asfix2_plus_star_to_plus);
  asfix2_plus_star_to_plus =
    ATparse("prod([cf(iter(<term>)),cf(opt(layout)),cf(iter-star(<term>))]," \
            "cf(iter(<term>)),<term>)");

  ATprotect(&asfix2_empty_to_star_sep);
  asfix2_empty_to_star_sep =
    ATparse("prod([],cf(iter-star-sep(<term>,<term>)),no-attrs)");   

  ATprotect(&asfix2_single_to_plus_sep);
  asfix2_single_to_plus_sep =
    ATparse("prod([cf(<term>)],cf(iter-sep(<term>,<term>)),no-attrs)");  

  ATprotect(&asfix2_plus_sep_to_star_sep);
  asfix2_plus_sep_to_star_sep =
    ATparse("prod([cf(iter-sep(<term>,<term>))],cf(iter-star-sep(<term>,<term>)),no-attrs)"); 

  ATprotect(&asfix2_plus_sep_plus_sep_to_plus_sep);
  asfix2_plus_sep_plus_sep_to_plus_sep =
    ATparse("prod([cf(iter-sep(<term>,<term>)),cf(opt(layout)),<term>," \
            "cf(opt(layout)),cf(iter-sep(<term>,<term>))],"
	    "cf(iter-sep(<term>,<term>)),<term>)");

  ATprotect(&asfix2_star_sep_star_sep_to_star_sep);
  asfix2_star_sep_star_sep_to_star_sep =
    ATparse("prod([cf(iter-star-sep(<term>,<term>)),cf(opt(layout)),<term>," \
            "cf(opt(layout)),cf(iter-star-sep(<term>,<term>))]," \
            "cf(iter-star-sep(<term>,<term>)),<term>)");    

  ATprotect(&asfix2_star_sep_plus_sep_to_plus_sep);
  asfix2_star_sep_plus_sep_to_plus_sep =
    ATparse("prod([cf(iter-star-sep(<term>,<term>)),cf(opt(layout)),<term>," \
            "cf(opt(layout)),cf(iter-sep(<term>,<term>))],"
	    "cf(iter-sep(<term>,<term>)),<term>)");                             
  ATprotect(&asfix2_plus_sep_star_sep_to_plus_sep);
  asfix2_plus_sep_star_sep_to_plus_sep =
    ATparse("prod([cf(iter-sep(<term>,<term>)),cf(opt(layout)),<term>," \
            "cf(opt(layout)),cf(iter-star-sep(<term>,<term>))],"
	    "cf(iter-sep(<term>,<term>)),<term>)"); 

}

/*}}}  */
/*{{{  static void init_patterns(void) */

static void init_patterns(void)
{
  static int patterns_initialized = 0;

  if (patterns_initialized) {
    return;
  }
  patterns_initialized = 1;

  init_asfix_patterns();
}

/*}}}  */

/*{{{  ATbool isListProd(PT_Production prod) */

ATbool isListProd(PT_Production prod)
{
  ATerm sort1, sort2, sort3;
  ATerm sep1, sep2, sep3, sep4;
  ATerm cc1, cc2, cc3;

  /* TODO: implement some kind of caching here, that would improve
   * efficiency a lot, since productions are shared plenty in an
   * average AsFix tree
   */

  if (ATmatchTerm((ATerm)prod, asfix2_layout_layout_to_layout )) {
    return ATtrue;
  }

  if (ATmatchTerm((ATerm)prod, asfix2_lex_layout_to_cf_layout)) {
    return ATtrue;
  }

  if (ATmatchTerm((ATerm)prod, asfix2_empty_to_star, NULL)) {
    return ATtrue;
  }

  if (ATmatchTerm((ATerm)prod, asfix2_single_to_plus, &sort1, &sort2)
      ||
      ATmatchTerm((ATerm)prod, asfix2_plus_to_star, &sort1, &sort2)) {
    return ATisEqual(sort1, sort2);
  }

  if (ATmatchTerm((ATerm)prod, asfix2_plus_plus_to_plus,
                  &sort1, &sort2, &sort3, NULL)
      ||
      ATmatchTerm((ATerm)prod, asfix2_star_star_to_star,
                  &sort1, &sort2, &sort3, NULL)
      ||
      ATmatchTerm((ATerm)prod, asfix2_star_plus_to_plus,
                  &sort1, &sort2, &sort3, NULL)
      ||
      ATmatchTerm((ATerm)prod, asfix2_plus_star_to_plus,
                  &sort1, &sort2, &sort3, NULL)) {
    return ATisEqual(sort1, sort2) && ATisEqual(sort1, sort3);
  }

  if (ATmatchTerm((ATerm)prod, asfix2_empty_to_star_lex_sort, NULL)) {
    return ATtrue;
  }

  if (ATmatchTerm((ATerm)prod, asfix2_single_to_plus_lex_sort, &sort1, &sort2)
      ||
      ATmatchTerm((ATerm)prod, asfix2_plus_to_star_lex_sort, &sort1, &sort2)) {
    return ATisEqual(sort1, sort2);
  } 

  if (ATmatchTerm((ATerm)prod, asfix2_plus_plus_to_plus_lex_sort,
                  &sort1, &sort2, &sort3, NULL)
      ||
      ATmatchTerm((ATerm)prod, asfix2_star_star_to_star_lex_sort,
                  &sort1, &sort2, &sort3, NULL)
      ||
      ATmatchTerm((ATerm)prod, asfix2_star_plus_to_plus_lex_sort,
                  &sort1, &sort2, &sort3, NULL)
      ||
      ATmatchTerm((ATerm)prod, asfix2_plus_star_to_plus_lex_sort,
                  &sort1, &sort2, &sort3, NULL)) {
    return ATisEqual(sort1, sort2) && ATisEqual(sort1, sort3);
  }

  if (ATmatchTerm((ATerm)prod, asfix2_empty_to_star_sep, NULL, NULL)) {
    return ATtrue;
  }

  if (ATmatchTerm((ATerm)prod, 
                  asfix2_single_to_plus_sep, &sort1, &sort2, NULL)) {
    return ATisEqual(sort1, sort2);
  }

  if (ATmatchTerm((ATerm)prod, 
                  asfix2_plus_sep_to_star_sep, &sort1, &sep1, &sort2, &sep2, NULL)) {
    return ATisEqual(sort1, sort2) && ATisEqual(sep1, sep2);
  }

  if (ATmatchTerm((ATerm)prod, asfix2_plus_sep_plus_sep_to_plus_sep,
                  &sort1, &sep1, &sep4, &sort2, &sep2, &sort3, &sep3, NULL)
      ||
      ATmatchTerm((ATerm)prod, asfix2_star_sep_star_sep_to_star_sep,
                  &sort1, &sep1, &sep4, &sort2, &sep2, &sort3, &sep3, NULL)
      ||
      ATmatchTerm((ATerm)prod, asfix2_star_sep_plus_sep_to_plus_sep,
                  &sort1, &sep1, &sep4, &sort2, &sep2, &sort3, &sep3, NULL)
      ||
      ATmatchTerm((ATerm)prod, asfix2_plus_sep_star_sep_to_plus_sep,
                  &sort1, &sep1, &sep4, &sort2, &sep2, &sort3, &sep3, NULL)) {
    return ATisEqual(sort1, sort2) && ATisEqual(sort2, sort3) &&
      ATisEqual(sep1, sep2) && ATisEqual(sep2, sep3) && ATisEqual(sep3, sep4);
  }

 if (ATmatchTerm((ATerm)prod, asfix2_empty_to_star_lex_charclass, NULL)) {
    return ATtrue;
  }

  if (ATmatchTerm((ATerm)prod, asfix2_single_to_plus_lex_charclass, &cc1, &cc2)
      ||
      ATmatchTerm((ATerm)prod, asfix2_plus_to_star_lex_charclass, &cc1, &cc2)) {
    return ATisEqual(cc1, cc2);
  }

  if (ATmatchTerm((ATerm)prod, asfix2_plus_plus_to_plus_lex_charclass,
                  &cc1, &cc2, &cc3, NULL)
      ||
      ATmatchTerm((ATerm)prod, asfix2_star_star_to_star_lex_charclass,
                  &cc1, &cc2, &cc3, NULL)
      ||
      ATmatchTerm((ATerm)prod, asfix2_star_plus_to_plus_lex_charclass,
                  &cc1, &cc2, &cc3, NULL)
      ||
      ATmatchTerm((ATerm)prod, asfix2_plus_star_to_plus_lex_charclass,
                  &cc1, &cc2, &cc3, NULL)) {
    return ATisEqual(cc1, cc2) && ATisEqual(cc1, cc3);
  }


  return ATfalse;
}

/*}}}  */
/*{{{  void prepareListSymbols(PT_Symbol symbol, PT_Symbol *plus, PT_Symbol *star) */

void prepareListSymbols(PT_Symbol symbol, PT_Symbol *plus, PT_Symbol *star)
{
  /* This function takes any list symbol, and produces both the plus
   * and the star variant of it in two return variables.
   * It should leave non-list symbols alone and copy them to *plus and *star.
   */

  if (PT_isSymbolCf(symbol) || PT_isSymbolLex(symbol)) {
    *plus = PT_getSymbolSymbol(symbol);
    *star = PT_getSymbolSymbol(symbol);
  }
  else {
    *plus = symbol;
    *star = symbol;
  }

  if (PT_isSymbolIterPlusSep(*plus)) {
    PT_Symbol elem = PT_getSymbolSymbol(*plus);
    PT_Symbol sep = PT_getSymbolSeparator(*plus);

    *star = PT_makeSymbolIterStarSep(elem, sep);
  }
  else if (PT_isSymbolIterPlus(*plus)) {
    PT_Symbol elem = PT_getSymbolSymbol(*plus);

    *star = PT_makeSymbolIterStar(elem);
  }
  else if (PT_isSymbolIterStarSep(*plus)) {
    PT_Symbol elem = PT_getSymbolSymbol(*plus);
    PT_Symbol sep = PT_getSymbolSeparator(*plus);
    
    *star = *plus;
    *plus = PT_makeSymbolIterPlusSep(elem, sep);
  }
  else if (PT_isSymbolIterStar(*plus)) {
    PT_Symbol elem = PT_getSymbolSymbol(*plus);

    *star = *plus;
    *plus = PT_makeSymbolIterPlus(elem);
  }
    
  if (PT_isSymbolCf(symbol)) {
    *star = PT_makeSymbolCf(*star);
    *plus = PT_makeSymbolCf(*plus);
  }
  else if (PT_isSymbolLex(symbol)) {
    *star = PT_makeSymbolLex(*star);
    *plus = PT_makeSymbolLex(*plus);
  }
}

/*}}}  */

/*{{{  void PT_initAsFix2Api() */

void PT_initAsFix2Api()
{
  init_patterns();
}

/*}}}  */

/*{{{  static PT_Args flattenArgs(PT_Args tl) */

static PT_Args flattenArgs(PT_Args args)
{
  /* this algorithm uses the C stack to reverse the args list */
  PT_Tree arg;

  if (PT_isArgsEmpty(args)) {
    return args;
  }

  arg = flattenTree(PT_getArgsHead(args));

  return PT_makeArgsMany(arg, flattenArgs(PT_getArgsTail(args)));
}

/*}}}  */
/*{{{  static void flattenListRec(PT_Symbol plus, PT_Symbol star, PT_Tree tree,  */

static void flattenListRec(PT_Tree tree, 
			   PT_Symbol plus, PT_Symbol star, 
			   PT_Args *tail)
{
  PT_Tree cache[5]; /* 5 is the max arity of a list production */
  PT_Production prod;
  PT_Symbol rhs;
  PT_Args args;
  int i;

  /* characters and ambiguities are not flattened into the list */
  if (!PT_hasTreeProd(tree)) {
    *tail = PT_makeArgsMany(flattenTree(tree), *tail);
    return;
  }

  prod = PT_getTreeProd(tree);
  rhs = PT_getProductionRhs(prod);


  /* if the type of the list changes, we do not flatten */
  if (!PT_isEqualSymbol(plus,rhs) && !PT_isEqualSymbol(star,rhs)) {
    *tail = PT_makeArgsMany(flattenTree(tree), *tail);
    return;
  }
  /* if the production is not generated by the normalizer (a variable,
   * or a function returning a list), we recurse and remove one level
   * of nesting afterwards.
   */
  else if (!isListProd(prod)) {
    PT_Tree list;
    PT_Tree arg;

    list = flattenTree(tree);
    arg = PT_getArgsHead(PT_getTreeArgs(list));

    *tail = PT_makeArgsMany(arg, *tail);
    return;
  }

  assert(PT_hasTreeArgs(tree));

  args = PT_getTreeArgs(tree);

  /* We cache the arguments to be able to walk backwards */
  for (i = 0; !PT_isArgsEmpty(args); args = PT_getArgsTail(args)) {
    cache[i++] = PT_getArgsHead(args);
  }

  /* The elements of the children are inserted in the tail */
  for (i--; i >= 0; i--) {
    flattenListRec(cache[i], plus, star, tail);
  }

  return;
}

/*}}}  */
/*{{{  static PT_Tree flattenList(PT_Tree tree) */

static PT_Tree flattenList(PT_Tree tree)
{
  PT_Production prod, list;
  PT_Symbol symbol, star = NULL, plus = NULL;
  PT_Args tail;

  prod = PT_getTreeProd(tree);
  symbol = PT_getProductionRhs(prod);


  if (isListProd(prod)) {
    prepareListSymbols(symbol, &plus, &star);

    tail = PT_makeArgsEmpty();
    flattenListRec(tree, plus, star, &tail);
  }
  else {
    PT_Args args = PT_getTreeArgs(tree);
    args = flattenArgs(args);
    tree = PT_setTreeArgs(tree, args);
    tail = PT_makeArgsSingle(tree);
  }

  list = PT_makeProductionList(symbol);
  
  return PT_makeTreeAppl(list, tail);
}

/*}}}  */
/*{{{  static PT_Tree flattenLayout(PT_Tree tree) */

static PT_Tree flattenLayout(PT_Tree tree)
{
  PT_Tree flat;
  PT_Production prod;
  PT_Production lexIterToCf;
  PT_Symbol symbol;

  /* We first reuse flattenList, and then reconstruct the layout structure
   * we want.
   */
  flat = flattenList(tree);

  prod = PT_getTreeProd(flat);
  symbol = PT_getProductionRhs(prod);

  assert(PT_isSymbolCf(symbol));

  /* replace cf(layout) by lex(iter(layout)) */
  symbol = PT_makeSymbolLex(PT_makeSymbolIterPlus(PT_getSymbolSymbol(symbol)));
  prod = PT_setProductionRhs(prod, symbol);
  flat = PT_setTreeProd(flat, prod);

  lexIterToCf = (PT_Production) asfix3_lex_iter_layout_to_cf_layout;

  return PT_makeTreeAppl(lexIterToCf, PT_makeArgsSingle(flat));
}

/*}}}  */
/*{{{  PT_Tree flattenTree(PT_Tree tree) */

PT_Tree flattenTree(PT_Tree tree)
{
  PT_Production prod;
  PT_Args args;

  if (PT_isTreeChar(tree)) {
    return tree;
  }
  else if (PT_isTreeAmb(tree)) {
    args = PT_getTreeArgs(tree);
    return PT_makeTreeAmb(flattenArgs(args));
  }

  assert(PT_isTreeAppl(tree) && "unsupported tree format");

  prod = PT_getTreeProd(tree);
  args = PT_getTreeArgs(tree);

  if ((PT_prodHasIterSepAsRhs(prod) || PT_prodHasIterAsRhs(prod))) {
    return flattenList(tree);
  } 
  else if (PT_prodHasCfLayoutAsRhs(prod)) { 
    return flattenLayout(tree);
  }
  else {
    return PT_makeTreeAppl(prod, flattenArgs(args));
  }
}

/*}}}  */

/*{{{  PT_ParseTree flattenPT(PT_ParseTree tree) */

PT_ParseTree flattenPT(PT_ParseTree tree)
{
  if (PT_isParseTreeTop(tree)) {
    PT_Tree newTree = PT_getParseTreeTop(tree);

    return PT_setParseTreeTop(tree, flattenTree(newTree));
  }

  ATerror("flattenParseTree: not a parsetree: %t\n", tree);
  return NULL;
}

/*}}}  */
