/*
  \subsection {Longest Match}

*/

#include <TB.h>
#include <stdio.h>
#include "bool.h"
#include "longest_match.h"

#ifdef MAIN
FILE *log = stdout;
bool debugflag = FALSE;
#else
extern FILE *log;
extern bool debugflag;
#endif

/*
   Function |tree_width| counts the number of character leaves
   of a tree.
*/

int tree_width(term *t)
{
   int i = 0;
   term *prod, *args;

   assert(t);
   if(TBmatch(t, "%d", &i)) {
     return 1;
   } else if(TBmatch(t, "appl(%t,[%l])", &prod, &args)) {
     while(args)
       {
          i   += tree_width(list_first(args));
          args = list_next(args);
       }
     return i;
   } else if(TBmatch(t, "amb([%l])", &args)) {
     if(args != NULL)
       return tree_width(list_first(args));
     else
       return 0;
   } else {
     TBprintf(stderr, "tree_width: funny tree: %t\n", t);
     exit(1);
   }
}


/*
   Function
*/

void print_tree_yield(FILE *F, term *t)
{
  int i;
  term *prod, *args;

  assert(t);
  if(TBmatch(t, "%d", &i)) {
    fprintf(F, "%c", i);
  }
  else if(TBmatch(t, "appl(%t,[%l])", &prod, &args)) {
    while(args) {
      print_tree_yield(F, list_first(args));
      args = list_next(args);
    }
  } else if(TBmatch(t, "amb([%l])", &args)) {
    if(args != NULL)
      print_tree_yield(F, list_first(args));
  } else {
    TBprintf(stderr, "print_tree_yield: funny tree: %t\n", t);
    exit(1);
  }
}

/*
  |init_token_stream|
*/

token_stream *init_token_stream(term *t)
{
  return TBmake("stream([],[],[%t])", t);
}

/*
  |reset_token_stream|
*/

void reset_token_stream(token_stream *ts)
{
  CUR(ts) = FIRST(ts);
}

int is_token(term *prod)
{
  term_list *fargs;
  term *res, attrs, name;

  return TBmatch(prod, "prod([lex(%t)],cf(%t),%t)", &fargs, &res, &attrs)
      || TBmatch(prod, "prod([%l],sort(\"LAYOUT\"),%t)", &fargs, &attrs)
      || TBmatch(prod, "prod([%l],%s,%t)", &fargs, &name, &attrs);
}

/*
  |token_stream_next|
*/

token *token_stream_next(token_stream *ts)
{
  term *t, *prod, *tok;
  term_list *args, *stack;
  int c;

  if(FIRST(ts) == NULL || CUR(ts) == NULL)
  {
    stack = STACK(ts);
    while(stack) {
      t = list_first(stack);
      stack = list_next(stack);

      /* TBprintf(stdout, "\nfinding tokens in \n%t\n", t); */

      if(TBmatch(t, "appl(%t,[%l])", &prod, &args)) {
        if(is_token(prod)) {
          tok = TBmake("token(%t,%d)", t, tree_width(t));
          FIRST(ts) = list_concat_term(FIRST(ts),tok);
          STACK(ts) = stack;
          return tok;
        }
        else
          stack = list_append(args, stack);
      }
      else if(TBmatch(t, "%d", &c)) {
        tok = TBmake("token(%t,1)", t);
        FIRST(ts) = list_join(FIRST(ts),tok);
        STACK(ts) = stack;
        return tok;
      } else {
        TBprintf(stderr, "get_tokens: funny tree: %t\n\n", t);
        exit(1);
      }
    }
    return NULL; /* no more tokens */
  } else {
    tok = list_first(CUR(ts));
    CUR(ts) = list_next(CUR(ts));
    return tok;
  }
}

/*

  The function |get_tokens| yields a list of terms of the form
  |token(t,i)| with |t| the term representing the token and |i|
  its length.

*/

token_stream *get_tokens(term *t)
{
  term *prod, *fargs, *res, *attrs, *args, *tokens = NULL;
  int c;
  char *name;

  if(TBmatch(t, "appl(%t,[%l])", &prod, &args)) {
    if(TBmatch(prod, "prod([lex(%t)],cf(%t),%t)", &fargs, &res, &attrs))
      return TBmake("[token(%t,%d)]", t, tree_width(t));
     else if(TBmatch(prod, "prod([%l],sort(\"LAYOUT\"),%t)",
                    &fargs, &attrs))
      return TBmake("[token(%t,%d)]", t, tree_width(t));
    else if(TBmatch(prod, "prod([%l],%s,%t)",
                    &fargs, &name, &attrs))
      return TBmake("[token(%t,%d)]", t, tree_width(t));
    else {
      while(args) {
        tokens = list_join(tokens, get_tokens(list_first(args)));
        args = list_next(args);
      }
      return tokens;
    }
  } else if(TBmatch(t, "%d", &c))
    return  TBmake("[token(%t,1)]", t);
  else {
    TBprintf(stderr, "get_tokens: funny tree: %t\n\n", t);
    exit(1);
  }
}

/*

  The macro |TOK_LEN| is a projection function that gives the
  second element of a token tuple, i.e., the length field.

*/

#define TOK_LEN(t)  int_val(elm2(fun_args(t)))
#define TOK_TREE(t) elm1(fun_args(t))

/*
  Function |lm_comp| compares two tokenstreams with respect to
  the longest match criterium. It returns |-1| if the first is
  larger, |0| if the streams are equal, and |1| if the second
  is larger.
*/

int lm_comp(token_stream *ts1, token_stream *ts2)
{
  int resolved = 0;
  token *tok1, *tok2;
  int k1, k2;

  tok1 = token_stream_next(ts1);
  tok2 = token_stream_next(ts2);
  while((resolved == 0) && tok1 && tok2)
  {
    if (debugflag) {
      TBprintf(log, "comparing tokens \"");
      print_tree_yield(log, TOK_TREE(tok1));
      TBprintf(log, "\" and \"");
      print_tree_yield(log, TOK_TREE(tok2));
      TBprintf(log, "\" = ");
    }

    k1 = TOK_LEN(tok1);
    k2 = TOK_LEN(tok2);
    if(k1 > k2) {
      /* |t1| has longer match than |t2|; continue with next term */
      /* TBprintf(stderr, "Current larger than next\n"); */
      resolved = -1;
    } else if(k2 > k1) {
      /* |t2| has longer match than all previous terms */
      /* TBprintf(stderr, "Next larger than current\n"); */
      resolved = 1; /* continue comparing |t1| with next term */
    } else {
      /* tokens have equal length until now; compare rest of
         token streams */
      tok1 = token_stream_next(ts1);
      tok2 = token_stream_next(ts2);
    }
    if (debugflag)
      TBprintf(log, "%d\n", resolved);
  }
  return resolved;
}

/*

  The function |longest_match| selects those trees from a list
  of trees that have the longest lexicals counting from left
  to right.

*/

term_list *longest_match(term_list *trms)
{
  term *t1, *t2;
  term_list *res_trms = NULL;
  token_stream *ts1, *ts2;

  assert(is_list(trms));
  assert(list_length(trms) > 1);

  /* get first term in the list */

  t1   = list_first(trms);
  ts1  = init_token_stream(t1);
  trms = list_next(trms);
  res_trms = mk_list(t1, NULL);

  /* TBprintf(stderr, "first token stream: %l\n", ts1a); */

  while(trms) {
    /* get next term in the list */
    t2   = list_first(trms);
    trms = list_next(trms);
    ts2  = init_token_stream(t2);

    /* TBprintf(stderr, "next token stream: %l\n", ts2a); */

    /* compare the token lists of the terms */
    switch(lm_comp(ts1, ts2)) {
      case -1:
        /* |t1| is larger than |t2|; continue with other terms */
        break;
      case 0:
        /* |t1| and |t2| are equal; join and continue comparing with |t1| */
        res_trms = mk_list(t1, res_trms);
        break;
      case 1:
        /* |t2| is larger than |t1|; continue with |t2| as |t1| */
        t1  = t2;
        ts1 = ts2;
        res_trms = mk_list(t1, NULL);
        break;
    }
    reset_token_stream(ts1);
  }
  return res_trms;
}

/*

  The function |lm_filter| applies the longest match filter to each
  ambiguity node in a tree.

*/

term *lm_filter(term *t)
{
  term *prod, *args, *new_args = NULL;
  int i;

  assert(t);
  if(TBmatch(t, "%d", &i))
    return(t);
  else if(TBmatch(t, "appl(%t,[%l])", &prod, &args)) {
    while(args) {
      new_args = list_join(new_args, lm_filter(list_first(args)));
      args = list_next(args);
    }
    return TBmake("appl(%t,[%l])", prod, new_args);
  } else if(TBmatch(t, "amb([%l])", &args)) {
    /* TBprintf(stderr, "ambiguity found\n"); */
    new_args = longest_match(args);
    assert(new_args);
    if(list_next(new_args) == NULL) {
      /* ambiguity solved */
      return(list_first(new_args));
    } else
      /* still ambiguous */
      return TBmake("amb([%l])", new_args);
  }
  else if(TBmatch(t, "parsetree(%t,%d)", &args, &i)) {
    if(i == 0) return t;
    else
      return TBmake("parsetree(%t,%d)", lm_filter(args), 0);
  }
/* Should never get here! */
  TBprintf(stderr, "error: unexpected term %t\n", t);
  return(NULL);
}

#ifdef MAIN

/*

  When compiled as a standalone tool, the longest match filter is applied
  to a term on standard input and the disambiguated term is written to
  standard output.

*/

void main(int argc, char **argv)
{
  term *t;
  TBinit(argv[0], argc, argv, NULL, NULL); /* first NULL: run stand-alone */
  t = TBreadTerm(stdin);
  TBprintf(stdout, "%t\n\n", lm_filter(t));
}

#endif


