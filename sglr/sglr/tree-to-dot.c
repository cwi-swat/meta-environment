/*
  $Id$

  file: tree-to-dot.c

  purpose: dumping parse trees as dot graphs, i.e., input for
  the dot graph layout program.

*/

#include <TB.h>
#include "bool.h"
#include "parse-table.h"
#include "stack.h"
#include "parser.h"
#include "forest.h"

extern char *program_name;

term *prev_char_parent;
char  prev_char;

#define PRINTED(t) has_conds(t)

void print_character(FILE *dot, int c)
{
  switch(c) {
  case '\n' : fprintf(dot, "\\\\n");
    break;
  case 32 : fprintf(dot, "\\\\32");
    break;
  case '\t' : fprintf(dot, "\\\\t");
    break;

/*
        JS -- handle the next chars with extra care
 */
  case '\\' : fprintf(dot, "\\\\");
    break;
  case '"' : fprintf(dot, "\\\"");
    break;

  default :
    if(!isprint(c))
      fprintf(dot, "\\\\%i", c);
    else
      fprintf(dot, "%c", c);
  }
}

void print_symbol(FILE *dot, term *t)
{
  char *name;
  term *arg, *arg2, *args;
  int  c1, c2;

  if (TBmatch(t, "layout", &name))
    fprintf(dot, "L");
   else if (TBmatch(t, "sort(%s)", &name))
    fprintf(dot, "%s", name);
  else if (TBmatch(t, "lit(%s)", &name)) {
    int n;
    fprintf(dot, "\\\"");
    for(n = 0; name[n] != '\0'; n++)
      switch (name[n]) {
        case '\\': fprintf(dot, "\\\\"); break;
        case '"':  fprintf(dot, "\\\""); break;
        default:  fprintf(dot, "%c", name[n]);
    }
    fprintf(dot, "\\\"");
  } else if (TBmatch(t, "lex(%t)", &arg)) {
    fprintf(dot, "<");
    print_symbol(dot, arg);
    fprintf(dot, "-LEX>");
  }
  else if (TBmatch(t, "cf(%t)", &arg)) {
    fprintf(dot, "<");
    print_symbol(dot, arg);
    fprintf(dot, "-CF>");
  } else if (TBmatch(t, "iter-star(%t)", &arg)) {
    print_symbol(dot, arg);
    fprintf(dot, "*");
  } else if (TBmatch(t, "iter(%t)", &arg)) {
    print_symbol(dot, arg);
    fprintf(dot, "+");
  } else if (TBmatch(t, "iter-sep(%t, %t)", &arg, &arg2)) {
    fprintf(dot, "{");
    print_symbol(dot, arg);
    fprintf(dot, "\\ ");
    print_symbol(dot, arg2);
    fprintf(dot, "}+");
  } else if (TBmatch(t, "iter-star-sep(%t, %t)", &arg, &arg2)) {
    fprintf(dot, "{");
    print_symbol(dot, arg);
    fprintf(dot, "\\ ");
    print_symbol(dot, arg2);
    fprintf(dot, "}*");
  } else if (TBmatch(t, "iter-n(%t, %d)", &arg, &c1)) {
    print_symbol(dot, arg);
    fprintf(dot, "%d+", c1);
  } else if (TBmatch(t, "iter-sep-n(%t, %t, %d)", &arg, &arg2, &c1)) {
    fprintf(dot, "{");
    print_symbol(dot, arg);
    fprintf(dot, "\\ ");
    print_symbol(dot, arg2);
    fprintf(dot, "}%d+", c1);
  } else if (TBmatch(t, "seq([%l])", &args)) {
    fprintf(dot, "(");
    while (args) {
      arg = first(args);
      args = next(args);
      print_symbol(dot, arg);
      if (args)
        fprintf(dot, "\\ ");
    }
    fprintf(dot, ")");
  }
  else if (TBmatch(t, "opt(%t)", &arg))
  {
    print_symbol(dot, arg);
    fprintf(dot, "?");
  }
  else if (TBmatch(t, "alt(%t, %t)", &arg, &arg2))
  {
    print_symbol(dot, arg);
    fprintf(dot, "|");
    print_symbol(dot, arg2);
  }
  else if (TBmatch(t, "char-class([%l])", &args))
  {
    fprintf(dot, "[");
    while (args) {
      arg = first(args);
      args = next(args);
      if (TBmatch(arg, "range(%d,%d)", &c1, &c2)) {
        print_character(dot, c1);
        fprintf(dot, "-");
        print_character(dot, c2);
      } else if (TBmatch(arg, "%d", &c1))
        print_character(dot, c1);
    }
    fprintf(dot, "]");
  }
  else if (TBmatch(t, "varsym(%t)", &arg)) {
    fprintf(dot, "<");
    print_symbol(dot, arg);
    fprintf(dot, "-VAR>");
  }
  else {
    TBprintf(stderr, "%s: print_symbol: strange symbol %t\n", program_name, t);
    exit(1);
  }
}

void appl_node(FILE *dot, term* t, term *fun, int n)
{
  term *args, *res, *attrs;

  if (TBmatch(fun, "prod([%l], %t, %t)", &args, &res, &attrs)) {
    TBprintf(dot, "\tN%d [label=\"", (int)t);
    print_symbol(dot, res);
    if(TBmatch(attrs,"attrs([atr(\"reject\"),%l])", &attrs))
      TBprintf(dot, " (reject)");
    TBprintf(dot, "\"]\n", n);
  } else {
    TBprintf(stderr, "%s: appl_node: not a production %t\n", program_name, fun);
    exit(1);
  }
}

void amb_node(FILE *dot, term *t, term *arg)
{
  term *args, *res, *attrs, *args2;
  if (TBmatch(arg, "appl(prod([%l],%t,%t),[%l])",
              &args, &res, &attrs, &args2)) {
    TBprintf(dot, "\tN%d [label=\"", (int)t);
    print_symbol(dot, res);
    TBprintf(dot, " (amb)\"]\n");
  } else
    TBprintf(stderr, "amb_node: warning strange node %d\n", t);
}

/*
 * Check whether a term is the top of a `lexical' tree
 */
bool is_lexical(term *fun)
{
  term *dummy;

  if(TBmatch(fun, "prod(%t,cf(layout),%t)", &dummy, &dummy))
    return(TRUE);

  if(TBmatch(fun, "prod(%t,lit(%t),%t)", &dummy, &dummy, &dummy))
    return(TRUE);

  if(TBmatch(fun, "prod(%t,lex(%t),%t)", &dummy, &dummy, &dummy))
    return(TRUE);

  return(FALSE);
}

void tree_to_dot(FILE *dot, term *t, int child, term *parent, bool suppress_lexicals)
{
  term *fun, *args, *arg;
  int  c;

  PRINTED(t) = FALSE;
  if (TBmatch(t, "%d", &c)) {
    TBprintf(dot, "\tN%d%d%d [label=\"", parent, child, c);
    print_character(dot, c);
    TBprintf(dot, "\"]\n", 0);
    TBprintf(dot, "\tN%d -> N%d%d%d\n", parent, parent, child, c);
    prev_char_parent = parent;
    prev_char = c;
  } else if (PRINTED(t)) {
    /* fprintf(stderr, "term already printed\n"); */
    return;
  }
  PRINTED(t) = TRUE;

  if (TBmatch(t, "appl(%t,[%l])", &fun, &args)) {
    int n = 0;

    if(!suppress_lexicals || !is_lexical(fun))
      while (args) {
        n++;
        arg = first(args);
        args = next(args);
        if (!TBmatch(arg, "%d", &c))
          fprintf(dot, "\tN%d -> N%d;\n", (int)t, (int)arg);
        tree_to_dot(dot, arg, n, t, suppress_lexicals);
      }
    appl_node(dot, t, fun, n);
  } else if (TBmatch(t, "amb([%l])", &args)) {
      int n = 0;
      if(args) amb_node(dot, t, first(args));
      while (args) {
        n++;
        arg = first(args);
        args = next(args);
        fprintf(dot, "\tN%d -> N%d;\n", (int)t, (int)arg);
        tree_to_dot(dot, arg, n, t, suppress_lexicals);
      }
  } else if (TBmatch(t, "parsetree(%t, %d)", &arg, &c))
      tree_to_dot(dot, arg, 1, t, suppress_lexicals);
}

void tree_to_dotfile(char *file, term *t, bool suppress)
{
  FILE *dot;

  if (strcmp(file, "") == 0)
    file = "parse.dot";
  if ((dot = fopen(file, "w")) == NULL) {
    fprintf(stderr, "%s: cannot create dotfile %s\n", program_name, file);
    exit(1);
  }

  prev_char_parent = NULL;

  fprintf(dot, "strict digraph ParseTree { \n\tordering=out;\n");
  tree_to_dot(dot, t, 0, NULL, suppress);
  fprintf(dot, "}\n");
}

void link_to_dot(FILE *dot, stack *st, st_link *l)
{
  int  c;
  term *t;

  fprintf(dot, "N%d [label = \"%d\" shape=box height=0.2, width=0.2];\n",
          (int) st, STATE(st));
  fprintf(dot, "N%d -> N%d [label=\"", (int) STACK(l), (int) st);
  t = tree_type(TREE(l));
  if(TBmatch(t, "%d", &c))
    print_character(dot, c);
  else {
    TBprintf(dot, "%t : ", dot_term_yield(TREE(l)));
    print_symbol(dot, t);
  }
  fprintf(dot, "\"");
  if(REJECTED(l))
    fprintf(dot, " style = dotted");
  fprintf(dot, "];\n");
}

void links_to_dot(FILE *dot, stack *st)
{
  st_link  *l;
  st_links *ls;

  ls = LINKS(st);
  while(shift(l, ls))
    link_to_dot(dot, st, l);
}

void stack_to_dot(FILE *dot, stack *st)
{
  st_link  *l;
  st_links *ls;

  if(st == NULL) return;
  fprintf(dot, "N%d [label=\"%d\" shape=box height=0.2, width=0.2];\n",
          (int) st, STATE(st));
  ls = LINKS(st);
  links_to_dot(dot, st);
  while(shift(l, ls))
    stack_to_dot(dot, STACK(l));
}

void stacks_to_dot(FILE *dot, stacks *sts1)
{
  stack  *st;
  stacks *sts2;

  sts2 = sts1;
  while(shift(st, sts2))
    stack_to_dot(dot, st);
}

extern char *stack_dotoutput;
extern int text_length;
char stack_file[256];

FILE *stack_dot;

void stacks_to_dotfile(stacks *sts)
{
  sprintf(stack_file, "%s%d.dot", stack_dotoutput, text_length);

  if ((stack_dot = fopen(stack_file, "w")) == NULL) {
    fprintf(stderr, "%s: cannot create dotfile %s\n",
            program_name, stack_file);
    return;
  }

  prev_char_parent = NULL;

  fprintf(stack_dot, "strict digraph ParseTree { \n"
          "rankdir = LR; \n"
          "edge [dir = back]; \n"
         );
  stacks_to_dot(stack_dot, sts);
  fprintf(stack_dot, "}\n");
  fclose(stack_dot);
}
