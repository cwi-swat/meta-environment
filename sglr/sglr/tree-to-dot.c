/*
  $Id$

  file: tree-to-dot.c

  purpose: dumping parse trees as dot graphs, i.e., input for
  the dot graph layout program.

*/

#include <TB.h>
#include "bool.h"
#include "parser.h"
#include "parse-table.h"
#include "forest.h"
#include "stack.h"

extern char *program_name;

term *prev_char_parent;
char  prev_char;

#define PRINTED(t) has_conds(t)

void
print_character(FILE *dot, int c)
{
  switch(c) {
  case '\n' : fprintf(dot, "\\\\\\\\n");
    break;
  case 32 : fprintf(dot, "\\\\\\\\32");
    break;
  case '\t' : fprintf(dot, "\\\\\\\\t");
    break;

/*
	JS -- handle the next chars with extra care
 */
  case '\\' : fprintf(dot, "\\\\");
    break;
  case '"' : fprintf(dot, "\\\"");
    break;

  default :
	if(!isprint(c)) {
		fprintf(dot, "\\\\%i", c);
	} else {
		fprintf(dot, "%c", c);
	}
  }
}

void 
print_symbol(FILE *dot, term *t)
{
  char *name;
  term *arg, *arg2, *arg3, *args;
  int c1, c2;

  if (TBmatch(t, "layout", &name))
    {
      fprintf(dot, "L", name);
    }
  else if (TBmatch(t, "sort(%s)", &name))
    {
      fprintf(dot, "%s", name);
    }
  else if (TBmatch(t, "lit(%s)", &name))
    {
      int n;
      fprintf(dot, "\\\"");
      for(n = 0; name[n] != '\0'; n++)
	switch (name[n])
	  {
	  case '\\': fprintf(dot, "\\\\"); break;
	  case '"':  fprintf(dot, "\\\""); break;
	  default:  fprintf(dot, "%c", name[n]);
	  }
      fprintf(dot, "\\\"");
    }
  else if (TBmatch(t, "lex(%t)", &arg))
    {
      fprintf(dot, "\\<");
      print_symbol(dot, arg);
      fprintf(dot, "-LEX\\>");
    }
  else if (TBmatch(t, "cf(%t)", &arg))
    {
      fprintf(dot, "\\<");
      print_symbol(dot, arg);
      fprintf(dot, "-CF\\>");
    }
  else if (TBmatch(t, "iter-star(%t)", &arg))
    {
      print_symbol(dot, arg);
      fprintf(dot, "*");
    }
  else if (TBmatch(t, "iter(%t)", &arg))
    {
      print_symbol(dot, arg);
      fprintf(dot, "+");
    }
  else if (TBmatch(t, "iter-sep(%t, %t)", &arg, &arg2))
    {
      fprintf(dot, "{");
      print_symbol(dot, arg);
      fprintf(dot, "\\ ");
      print_symbol(dot, arg2);
      fprintf(dot, "}+");
    }
  else if (TBmatch(t, "iter-star-sep(%t, %t)", &arg, &arg2))
    {
      fprintf(dot, "{");
      print_symbol(dot, arg);
      fprintf(dot, "\\ ");
      print_symbol(dot, arg2);
      fprintf(dot, "}*");
    }
  else if (TBmatch(t, "iter-n(%t, %d)", &arg, &c1))
    {
      fprintf(dot, "");
      print_symbol(dot, arg);
      fprintf(dot, "%d+", c1);
    }
  else if (TBmatch(t, "iter-sep-n(%t, %t, %d)", &arg, &arg2, &c1))
    {
      fprintf(dot, "{");
      print_symbol(dot, arg);
      fprintf(dot, "\\ ");
      print_symbol(dot, arg2);
      fprintf(dot, "}%d+", c1);
    }
  else if (TBmatch(t, "seq([%l])", &args))
    {
      fprintf(dot, "(");
      while (args) 
	{
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
      while (args) 
	{
	  arg = first(args);
	  args = next(args);
	  if (TBmatch(arg, "range(%d,%d)", &c1, &c2))
	    {
	      print_character(dot, c1);
	      fprintf(dot, "-");
	      print_character(dot, c2);
	    }
	  else if (TBmatch(arg, "%d", &c1))
	    {
	      print_character(dot, c1);
	    }
	}
      fprintf(dot, "]");
    }
  else if (TBmatch(t, "varsym(%t)", &arg))
    {
      fprintf(dot, "<");
      print_symbol(dot, arg);
      fprintf(dot, "-VAR>");
    }
  else 
    {
      TBprintf(stderr, "%s: print_symbol: strange symbol %t\n", program_name, t);
      exit(1);
    }
}

void
arrow(FILE *dot, term *t1, term *t2)
{
  fprintf(dot, "\tN%d -> N%d;\n", (int)t1, (int)t2);
}

void 
appl_node(FILE *dot, term* t, term *fun, int n)
{
  term *args, *res, *attrs;
  int c = 0;
  if (TBmatch(fun, "prod([%l], %t, %t)", &args, &res, &attrs))
    {
/*
      TBprintf(dot, "\tN%d [shape = plaintext label = \"", (int)t);
*/
      TBprintf(dot, "\tN%d [label = \"", (int)t);
      print_symbol(dot, res);
      TBprintf(dot, "\"]\n", n);
    }
  else
    {
      TBprintf(stderr, "%s: appl_node: not a production %t\n", program_name, fun);
      exit(1);
    }
}

void
amb_node(FILE *dot, term *t, term *arg)
{
  term *args, *res, *attrs, *args2;
  if (TBmatch(arg, "appl(prod([%l],%t,%t),[%l])",
	      &args, &res, &attrs, &args2))
    {
      TBprintf(dot, "\tN%d [label = \"", (int)t);
      print_symbol(dot, res);
      TBprintf(dot, "\"]\n");
    }
  else 
    {
      TBprintf(stderr, "amb_node: warning strange node %d\n", t);
    }
}

void
tree_to_dot(FILE *dot, term *t, int child, term *parent)
{
  term *fun, *args, *arg;
  int c;

  PRINTED(t) = FALSE;
  if (TBmatch(t, "%d", &c))
    {
      TBprintf(dot, "\tN%d%d%d [label = \"", parent, child, c);
      print_character(dot, c);
      TBprintf(dot, "\"]\n", 0);
      TBprintf(dot, "\tN%d -> N%d%d%d\n", parent, parent, child, c);      
/*
      fprintf(dot, "\tN%d%d%d ["
	      "label = \"",
	      parent, child, c);
      print_character(dot, c);
      fprintf(dot, "\"]\n");
      fprintf(dot, "\tN%d -> N%d%d%d\n", parent, parent, child, c);      
*/
      prev_char_parent = parent;
      prev_char = c;
    }
  else if (PRINTED(t)) {
    /* fprintf(stderr, "term already printed\n"); */
    return;
  }
  PRINTED(t) = TRUE;

  if (TBmatch(t, "appl(%t,[%l])", &fun, &args))
    {
      int n = 0;
      while (args)
	{
	  n++;
	  arg = first(args);
	  args = next(args);
	  if (!TBmatch(arg, "%d", &c))
	    fprintf(dot, "\tN%d -> N%d;\n", (int)t, (int)arg);
	  tree_to_dot(dot, arg, n, t);
	}
      appl_node(dot, t, fun, n);
    }
  else if (TBmatch(t, "amb([%l])", &args))
    {
      int n = 0;
      if(args) amb_node(dot, t, first(args));
      while (args)
	{
	  n++;
	  arg = first(args);
	  args = next(args);
	  fprintf(dot, "\tN%d -> N%d;\n", (int)t, (int)arg);
	  tree_to_dot(dot, arg, n, t);
	}
    }
  else if (TBmatch(t, "parsetree(%t, %d)", &arg, &c))
    {
      tree_to_dot(dot, arg, 1, t);
    }
}

void 
tree_to_dotfile(char *file, term *t)
{
  FILE *dot;
  if (strcmp(file, "") == 0) 
    file = "parse.dot";
  if ((dot = fopen(file, "w")) == NULL)
    {
      fprintf(stderr, "%s: cannot create dotfile %s\n", program_name, file);
      exit(1);
    }

  /* fprintf(stdout, "writing dot info to %s\n", file); */

  prev_char_parent = NULL;

  fprintf(dot, "strict digraph ParseTree { \n"
	       "\tcenter=true;\n"
	       "\tordering=out;\n"
	       "\tranksep=.44;\n"
	       "\tnode[shape=plaintext fontname=\"Helvetica-Bold\" fontsize=12 height=.32];\n\n"
	  );
  tree_to_dot(dot, t, 0, NULL);
  fprintf(dot, "}\n");
}

void
link_to_dot(FILE *dot, stack *st, st_link *l)
{
  int c;
  term *t;

  fprintf(dot, "N%d [label = \"%d\" shape = box "
	  "height = 0.2, width = 0.2];\n", st, STATE(st));

  fprintf(dot, "N%d -> N%d [ label = \"", STACK(l), st);
  t = tree_type(TREE(l));
  if(TBmatch(t, "%d", &c))
    print_character(dot, c);
  else {
    TBprintf(dot, "%t : ", dot_trm_yield(TREE(l)));
    print_symbol(dot, t);
  }
  fprintf(dot, "\"");
  if(REJECTED(l))
    fprintf(dot, " style = dotted");
  fprintf(dot, "];\n");

}

void
links_to_dot(FILE *dot, stack *st)
{
  int c;
  term *t;
  st_link *l;
  st_links *ls;
  ls = LINKS(st);
  while(pop(l, ls)) {
    link_to_dot(dot, st, l);
  }
}

void
stack_to_dot(FILE *dot, stack *st)
{
  st_link *l;
  st_links *ls;
  fprintf(dot, "N%d [label = \"%d\" shape = box "
	  "height = 0.2, width = 0.2];\n", st, STATE(st));
  ls = LINKS(st);
  links_to_dot(dot, st);
  while(pop(l, ls)) {
    stack_to_dot(dot, STACK(l));
  }
}

void
stacks_to_dot(FILE *dot, stack *sts1)
{
  st_link *l;
  st_links *ls;
  stack *st;
  stacks *sts2;

  sts2 = sts1;
  while(pop(st, sts2)) {
    stack_to_dot(dot, st);
  }
}

extern char *stack_dotoutput;
extern int text_length;
char stack_file[256];

FILE *stack_dot;

void 
stack_to_dotfile(stack *t)
{
  
  sprintf(stack_file, "%s%d.dot", stack_dotoutput, text_length);

  if ((stack_dot = fopen(stack_file, "w")) == NULL)
    {
      fprintf(stderr, "%s: cannot create dotfile %s\n", 
	      program_name, stack_file);
      exit(1);
    }

  /* fprintf(stdout, "writing dot info to %s\n", file); */

  prev_char_parent = NULL;

  fprintf(stack_dot, "strict digraph ParseTree { \n"
	  /* "\tranksep = .2; \n" */
	  /* "ordering = out; \n" */
	  "rankdir = LR; \n"
	  "edge [dir = back]; \n"
	  /* "\tnode [ fontname = Helvetica fontsize = 10 height = .05];\n" */
	  );
  stacks_to_dot(stack_dot, t);
}

void 
stack_to_dotfile_end()
{
  fprintf(stack_dot, "}\n");
}
