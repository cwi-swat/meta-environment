/*
    $Id$
*/

#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "asfix2.h"

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

static void init_asfix_patterns()
{
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
    ATparse("prod([cf(iter-sep(<list>))],cf(iter-star-sep(<list>)),no-attrs)"); 

  ATprotect(&asfix2_plus_sep_plus_sep_to_plus_sep);
  asfix2_plus_sep_plus_sep_to_plus_sep =
    ATparse("prod([cf(iter-sep(<list>)),cf(opt(layout)),<term>," \
            "cf(opt(layout)),cf(iter-sep(<list>))],cf(iter-sep(<list>))," \
            "<term>)");

  ATprotect(&asfix2_star_sep_star_sep_to_star_sep);
  asfix2_star_sep_star_sep_to_star_sep =
    ATparse("prod([cf(iter-star-sep(<list>)),cf(opt(layout)),<term>," \
            "cf(opt(layout)),cf(iter-star-sep(<list>))]," \
            "cf(iter-star-sep(<list>)),<term>)");    

  ATprotect(&asfix2_star_sep_plus_sep_to_plus_sep);
  asfix2_star_sep_plus_sep_to_plus_sep =
    ATparse("prod([cf(iter-star-sep(<list>)),cf(opt(layout)),<term>," \
            "cf(opt(layout)),cf(iter-sep(<list>))],cf(iter-sep(<list>))," \
            "<term>)");                             

  ATprotect(&asfix2_plus_sep_star_sep_to_plus_sep);
  asfix2_plus_sep_star_sep_to_plus_sep =
    ATparse("prod([cf(iter-sep(<list>)),cf(opt(layout)),<term>," \
            "cf(opt(layout)),cf(iter-star-sep(<list>))],cf(iter-sep(<list>))," \
            "<term>)"); 

}

static void init_patterns(void)
{
  static int patterns_initialized = 0;

  if (patterns_initialized) {
    return;
  }
  patterns_initialized = 1;

  init_asfix_patterns();
}

ATbool isLexicalListProd(PT_Production prod)
{
  ATerm sort1, sort2, sort3;

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

  return ATfalse;
}

ATbool isCharClassListProd(PT_Production prod)
{
  ATerm cc1, cc2, cc3;

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

ATbool isListProd(PT_Production prod)
{
  ATerm sort1, sort2, sort3;

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

  return ATfalse;
}

ATbool isSepListProd(PT_Production prod)
{
  ATerm sep1, sep2;
  ATerm sort1, sort2;
  ATermList sortSep1, sortSep2, sortSep3;

  if (ATmatchTerm((ATerm)prod, asfix2_empty_to_star_sep, NULL, NULL)) {
    return ATtrue;
  }

  if (ATmatchTerm((ATerm)prod, asfix2_single_to_plus_sep, &sort1, &sort2, NULL)) {
    return ATisEqual(sort1, sort2);
  }

  if (ATmatchTerm((ATerm)prod, asfix2_plus_sep_to_star_sep, &sortSep1, &sortSep2, NULL)) {
    return ATisEqual(sortSep1, sortSep2);
  }

  if (ATmatchTerm((ATerm)prod, asfix2_plus_sep_plus_sep_to_plus_sep,
                  &sortSep1, &sep1, &sortSep2, &sortSep3, NULL)
      ||
      ATmatchTerm((ATerm)prod, asfix2_star_sep_star_sep_to_star_sep,
                  &sortSep1, &sep1, &sortSep2, &sortSep3, NULL)
      ||
      ATmatchTerm((ATerm)prod, asfix2_star_sep_plus_sep_to_plus_sep,
                  &sortSep1, &sep1, &sortSep2, &sortSep3, NULL)
      ||
      ATmatchTerm((ATerm)prod, asfix2_plus_sep_star_sep_to_plus_sep,
                  &sortSep1, &sep1, &sortSep2, &sortSep3, NULL)) {
    sep2 = ATgetArgument(sortSep1, 1);
    return ATisEqual(sortSep1, sortSep2) && 
           ATisEqual(sortSep1, sortSep3) &&
           ATisEqual(sep1, sep2);
  }

  return ATfalse;
} 

void PT_initAsFix2Api()
{
  init_patterns();
}
