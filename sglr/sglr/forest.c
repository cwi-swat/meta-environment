/*
  %% $Id$

  \section{Parse forests}
  \label{forest.c}

  All data structures are represented by means of ToolBus terms.

  \subsection{forest.h}

  \input{forest.htx}

  \subsection{forest.c}

*/
#include <TB.h>
#include "bool.h"
#include "parse-table.h"
#include "stack.h"
#include "parser.h"
#include "forest.h"

int nr_ambiguities = 0;
extern int abbreviation_flag;
extern int debugflag;
extern FILE *log;

/*
  The functions |apply| and |cons| are defined directly in terms
  of ToolBus term functions.
*/
term *apply(parse_table *pt, label l, terms *ts)
{
  term *t;
  if (abbreviation_flag)
    t = TBmake("appl(aprod(%d),%t)", l, ts);
  else {
    t = TBmake("appl(%t,%t)", PROD(pt,l), ts);
  }
  return t;
}

/*
  The function |amb| creates a term of the form |amb([t1,...,tn])|,
  where the |ti| are the alternatives of the ambiguous node. If
  the first argument term |t1| of |amb| is an application a new
  |amb| node is created by overwriting the application node and
  creating a new application node as one of the arguments of
  this |amb| node. If |t1| is already an ambiguous node the new
  term |t2| is simply added to the list of its arguments.
*/
void amb(term *t1, term *t2) {
  term *prod, *args;

  if(debugflag)
    TBprintf(log, "creating ambiguity node for\n %t and %t\n",
             dot_term_yield(t1), dot_term_yield(t2));

  if (TBmatch(t1, "appl(%t, %t)", &prod, &args)) {
    /* Create ambiguity node. */
    fun_sym(t1)  = TBlookup("amb");
    fun_args(t1) = TBmake("[[appl(%t,%t),%t]]", prod, args, t2);
    nr_ambiguities++;
  } else if (TBmatch(t1, "amb([%l])", &args)) {
    first(fun_args(t1)) = mk_list(t2, args);
    nr_ambiguities++;
  } else {
    fprintf(stderr, "error: amb: symbolnode is not appl or amb\n");
    TBprintf(stderr, "%t\n", t1);
    exit(1);
  }
  return;
}

term *tree_type(term *t)
{
  term *types, *type, *attrs, *args;
  int n;

  if (TBmatch(t, "appl(prod(%t,%t,%t), %t)", &types, &type, &attrs, &args))
    return type;
   else if (TBmatch(t, "amb([%l])", &args))
    return tree_type(first(first(fun_args(t))));
  else if (TBmatch(t, "%d", &n))
    return t;
  else {
    fprintf(stderr, "error: tree_type: tree not well-formed\n");
    TBprintf(stderr, "%t\n", t);
    exit(1);
  }
}

static char temp[10240];
static int index;

void term_yield_aux(term *t)
{
  term *fun, *args, *first, *rest;
  int c;

  if (t == NULL)
    return;
  else if (TBmatch(t, "%d", &c)) {
    temp[index++] = c;
    temp[index] = '\0';
  } else if (TBmatch(t, "appl(%t,[%l])", &fun, &args))
    term_yield_aux(args);
   else if (TBmatch(t, "[%t,%l]", &first, &rest)) {
    term_yield_aux(first);
    term_yield_aux(rest);
  } else {
    TBprintf(stderr, "term_yield_aux: strange term: %t\n", t);
    exit(1);
  }
}

term *term_yield(term *t)
{
  index = 0;
  temp[index] = '\0';
  term_yield_aux(t);
  return TBmake("%s", temp);
}

void dot_term_yield_aux(term *t)
{
  term *fun, *args, *first, *rest;
  int c;

  /* TBprintf(stderr, "yield_aux(%t)\n", t); */

  if (t == NULL)
    return;
  else if (TBmatch(t, "%d", &c)) {
    switch(c) {
      case '\n':
        temp[index++] = '\\';
        temp[index++] = '\\';
        temp[index++] = 'n';
        break;
      default:
        temp[index++] = c;
        break;
    }
  } else if (TBmatch(t, "appl(%t,[%l])", &fun, &args)) {
    if(list_length(args) > 1) {
      temp[index++] = '[';
      dot_term_yield_aux(args);
      temp[index++] = ']';
    } else
      dot_term_yield_aux(args);
  } else if (TBmatch(t, "[%t,%l]", &first, &rest)) {
    dot_term_yield_aux(first);
    dot_term_yield_aux(rest);
  } else if (TBmatch(t, "amb([%l])", &rest)) {
    while(pop(first, rest)) {
      dot_term_yield_aux(first);
      if(rest != NULL) {
        temp[index++] = '|';
      }
    }
  } else {
    TBprintf(stderr, "term_yield_aux: strange term: %t\n", t);
    exit(1);
  }
}

term *dot_term_yield(term *t)
{
  index = 0;
  temp[index] = '\0';
  dot_term_yield_aux(t);
  temp[index] = '\0';
  return TBmake("%s", temp);
}
