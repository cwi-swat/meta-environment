/*
  $Id$

  file: tree-to-dot.c

  Purpose: dumping parse trees as dot graphs, i.e., input for
  the dot graph layout program.

*/

#include <ctype.h>

#include <aterm2.h>

#include "forest.h"
#include  "tree-to-dot.h"

ATerm prev_char_parent;
char  prev_char;


void SG_PrintChar(FILE *dot, int c)
{
  switch(c) {
  case '\n' : ATfprintf(dot, "\\\\n");
    break;
  case 32   : ATfprintf(dot, "\\\\32");
    break;
  case '\t' : ATfprintf(dot, "\\\\t");
    break;

/*
 * Treat the next chars with extra care
 */
  case '\\' : ATfprintf(dot, "\\\\");
    break;
  case '"'  : ATfprintf(dot, "\\\"");
    break;

  default :
    if(isprint(c)) ATfprintf(dot, "%c", c);
    else ATfprintf(dot, "\\\\%i", c);
  }
}

void SG_PrintSymbol(FILE *dot, ATerm t)
{
  char *name;
  ATerm     arg, arg2;
  ATermList args;
  int  c1, c2;

  if (ATmatch(t, "layout"))
    ATfprintf(dot, "L");
  else if (ATmatch(t, "sort(<str>)", &name))
    ATfprintf(dot, "%s", name);
  else if (ATmatch(t, "lit(<str>)", &name)) {
    int n;

    ATfprintf(dot, "\\\"");
    for(n = 0; name[n] != '\0'; n++)
      switch (name[n]) {
        case '\\': ATfprintf(dot, "\\\\"); break;
        case '"' : ATfprintf(dot, "\\\""); break;
        default  : ATfprintf(dot, "%c", name[n]);
    }
    ATfprintf(dot, "\\\"");
  } else if (ATmatch(t, "lex(<term>)", &arg)) {
    ATfprintf(dot, "<");
    SG_PrintSymbol(dot, arg);
    ATfprintf(dot, "-LEX>");
  }
  else if (ATmatch(t, "cf(<term>)", &arg)) {
    ATfprintf(dot, "<");
    SG_PrintSymbol(dot, arg);
    ATfprintf(dot, "-CF>");
  } else if (ATmatch(t, "iter-star(<term>)", &arg)) {
    SG_PrintSymbol(dot, arg);
    ATfprintf(dot, "*");
  } else if (ATmatch(t, "iter(<term>)", &arg)) {
    SG_PrintSymbol(dot, arg);
    ATfprintf(dot, "+");
  } else if (ATmatch(t, "iter-sep(<term>,<term>)", &arg, &arg2)) {
    ATfprintf(dot, "{");
    SG_PrintSymbol(dot, arg);
    ATfprintf(dot, "\\ ");
    SG_PrintSymbol(dot, arg2);
    ATfprintf(dot, "}+");
  } else if (ATmatch(t, "iter-star-sep(<term>,<term>)", &arg, &arg2)) {
    ATfprintf(dot, "{");
    SG_PrintSymbol(dot, arg);
    ATfprintf(dot, "\\ ");
    SG_PrintSymbol(dot, arg2);
    ATfprintf(dot, "}*");
  } else if (ATmatch(t, "iter-n(<term>, <int>)", &arg, &c1)) {
    SG_PrintSymbol(dot, arg);
    ATfprintf(dot, "%d+", c1);
  } else if (ATmatch(t, "iter-sep-n(<term>,<term>,<int>)", &arg, &arg2, &c1)) {
    ATfprintf(dot, "{");
    SG_PrintSymbol(dot, arg);
    ATfprintf(dot, "\\ ");
    SG_PrintSymbol(dot, arg2);
    ATfprintf(dot, "}%d+", c1);
  } else if (ATmatch(t, "seq([<list>])", &args)) {
    ATfprintf(dot, "(");
    while (!ATisEmpty(args)) {
      arg = ATgetFirst(args);
      args = ATgetNext(args);
      SG_PrintSymbol(dot, arg);
      if (args) ATfprintf(dot, "\\ ");
    }
    ATfprintf(dot, ")");
  } else if (ATmatch(t, "opt(<term>)", &arg)) {
    SG_PrintSymbol(dot, arg);
    ATfprintf(dot, "?");
  } else if (ATmatch(t, "alt(<term>,<term>)", &arg, &arg2)) {
    SG_PrintSymbol(dot, arg);
    ATfprintf(dot, "|");
    SG_PrintSymbol(dot, arg2);
  } else if (ATmatch(t, "char-class([<list>])", &args)) {
    ATfprintf(dot, "[");
    while (!ATisEmpty(args)) {
      arg = ATgetFirst(args);
      args = ATgetNext(args);
      if (ATmatch(arg, "range(<int>,<int>)", &c1, &c2)) {
        SG_PrintChar(dot, c1);
        ATfprintf(dot, "-");
        SG_PrintChar(dot, c2);
      } else if (ATmatch(arg, "<int>", &c1))
        SG_PrintChar(dot, c1);
    }
    ATfprintf(dot, "]");
  } else if (ATmatch(t, "varsym(<term>)", &arg)) {
    ATfprintf(dot, "<");
    SG_PrintSymbol(dot, arg);
    ATfprintf(dot, "-VAR>");
  }
  else
    ATerror("SG_PrintSymbol: strange symbol %t\n", t);
}


/*
    The following #defines are TEMPORARY, until there's a true
    interface (sort of) to access the internal `mark' bit in aterms
    we're abusing here
*/
/* Taken from @ATERMDIST@/aterm/encoding.h */
#define MASK_MARK         (1<<1)
#define IS_MARKED(h)      ((h) & MASK_MARK)
#define SET_MARK(h)       ((h) |= MASK_MARK)
#define CLR_MARK(h)       ((h) &= ~MASK_MARK)

#define SG_IS_PRINTED(t)     IS_MARKED(t->header)
#define SG_MARK_PRINTED(t)   SET_MARK(t->header)
#define SG_MARK_UNPRINTED(t) CLR_MARK(t->header)
/*   End of TEMPORARY hack */


void SG_ApplNode(FILE *dot, ATerm t, ATerm fun, int n)
{
  ATerm args, res, attrs;

  if (SG_IS_PRINTED(t)) return;
  SG_MARK_PRINTED(t);

  if (ATmatch(fun, "prod([<list>], <term>, <term>)", &args, &res, &attrs)) {
    ATfprintf(dot, "\tN%d [label=\"", (int)t);
    SG_PrintSymbol(dot, res);
    if(ATmatch(attrs,"attrs([atr(\"reject\"),<list>])", &attrs))
      ATfprintf(dot, " (reject)");
    ATfprintf(dot, "\"]\n");
  } else
    ATerror("SG_ApplNode: not a production %t\n", fun);
}

void SG_AmbNode(FILE *dot, ATerm t, ATerm arg)
{
  ATerm args, res, attrs, args2;

  if (ATmatch(arg, "appl(prod([<list>],<term>,<term>),[<list>])",
              &args, &res, &attrs, &args2)) {
    ATfprintf(dot, "\tN%d [label=\"", (int)t);
    SG_PrintSymbol(dot, res);
    ATfprintf(dot, " (amb)\"]\n");
  } else
    ATerror("SG_AmbNode: warning strange node %d\n", t);
}


/* Check whether a term is the top of a `lexical' tree */

ATbool SG_IsLexical(ATerm fun)
{
  ATerm dummy;

  if(ATmatch(fun, "prod(<term>,cf(layout),<term>)", &dummy, &dummy))
    return(ATtrue);

  if(ATmatch(fun, "prod(<term>,lit(<term>),<term>)", &dummy, &dummy, &dummy))
    return(ATtrue);

  if(ATmatch(fun, "prod(<term>,lex(<term>),<term>)", &dummy, &dummy, &dummy))
    return(ATtrue);

  return(ATfalse);
}


void SG_TreeToDot(FILE *dot, ATerm t, int child, ATerm parent,
                  ATbool suppress_lexicals)
{
  ATerm     fun, arg;
  ATermList args;
  int       c, n=0;

  if (ATmatch(t, "<int>", &c)) {
    ATfprintf(dot, "\tN%d%d%d [label=\"", (int) parent, child, c);
    SG_PrintChar(dot, c);
    ATfprintf(dot, "\"]\n");
    ATfprintf(dot, "\tN%d -> N%d%d%d\n", parent, parent, child, c);
    prev_char_parent = parent;
    prev_char = c;
  }
  if (SG_IS_PRINTED(t)) return;

  if (ATmatch(t, "appl(<term>,[<list>])", &fun, &args)) {
    if(!suppress_lexicals || !SG_IsLexical(fun)) {
      while (!ATisEmpty(args)) {
        arg = ATgetFirst(args);
        args = ATgetNext(args);
        n++;
        if (ATgetType(arg) != AT_INT)
          ATfprintf(dot, "\tN%d -> N%d\n", (int)t, (int)arg);
        SG_TreeToDot(dot, arg, n, t, suppress_lexicals);
      }
    }
    SG_ApplNode(dot, t, fun, n);
  } else if (ATmatch(t, "amb(<list>)", &args)) {
      if(!ATisEmpty(args)) SG_AmbNode(dot, t, ATgetFirst(args));
      while (!ATisEmpty(args)) {
        arg = ATgetFirst(args);
        args = ATgetNext(args);
        n++;
        ATfprintf(dot, "\tN%d -> N%d\n", (int)t, (int)arg);
        SG_TreeToDot(dot, arg, n, t, suppress_lexicals);
      }
  } else if (ATmatch(t, "parsetree(<term>, <int>)", &arg, &c))
      SG_TreeToDot(dot, arg, 1, t, suppress_lexicals);
}

void SGtreeToDotFile(char *prg, char *file, ATerm t, ATbool suppress)
{
  FILE *dot;

  if (strcmp(file, "") == 0)
    file = "parse.dot";
  if ((dot = fopen(file, "w")) == NULL)
    ATerror("%s: cannot create dotfile %s\n", prg, file);

  prev_char_parent = NULL;

  ATfprintf(dot, "strict digraph ParseTree {\n"
                 "\tordering=out\n"
                 "\tedge[dir=none]\n\n");
  SG_TreeToDot(dot, t, 0, NULL, suppress);
  ATfprintf(dot, "}\n");
}

void SG_LinkToDot(FILE *dot, stack *st, st_link *l)
{
  int  c;
  ATerm t, tree;

  ATfprintf(dot, "N%d [label=\"%d\" shape=box height=0.2, width=0.2]\n",
            (int) st, SG_ST_STATE(st));
  ATfprintf(dot, "N%d -> N%d [label=\"", (int) SG_LK_STACK(l), (int) st);
  tree = SG_LK_TREE(l);
  t = SG_TreeType(tree);
  if(ATmatch(t, "<int>", &c)) {
    SG_PrintChar(dot, c);
  } else {
    ATfprintf(dot, "%s : ", SG_DotTermYield(tree));
    SG_PrintSymbol(dot, t);
  }
  ATfprintf(dot, "\"");
#if 0
  if(SG_LK_REJECTED(l)) ATfprintf(dot, " style = dotted");
#else
  if(SG_Rejected(st)) ATfprintf(dot, " style = dotted");
#endif
  ATfprintf(dot, "]\n");
}

void SG_LinksToDot(FILE *dot, stack *st)
{
  st_links *ls;

  ls = SG_ST_LINKS(st);
  while(ls) {
    SG_LinkToDot(dot, st, head(ls));
    ls = tail(ls);
  }
}

void SG_StackToDot(FILE *dot, stack *st)
{
  st_links *ls;

  if(st == NULL) return;
  ATfprintf(dot, "N%d [label=\"%d\" shape=box height=0.2, width=0.2]\n",
            (int) st, SG_ST_STATE(st));
  ls = SG_ST_LINKS(st);
  SG_LinksToDot(dot, st);
  while(ls) {
    SG_StackToDot(dot, SG_LK_STACK(head(ls)));
    ls = tail(ls);
  }
}

void SG_StacksToDot(FILE *dot, stacks *sts)
{
  while(sts) {
    SG_StackToDot(dot, head(sts));
    sts = tail(sts);
  }
}

FILE *SG_StackDotFP = NULL;

FILE  *SG_StackDot(void)
{
  return SG_StackDotFP;
}

char *SG_StackDotOut(char *s)
{
  static char *sdo = NULL;

  if(s != NULL) sdo = s;
  return sdo;
}

void SG_StacksToDotFile(stacks *sts, int sg_tokens_read)
{
  char stk_file[256];

  sprintf(stk_file, "%s%d.dot", SG_StackDotOut(NULL), sg_tokens_read);

  if ((SG_StackDotFP = fopen(stk_file, "w")) == NULL) {
    ATfprintf(stderr, "Cannot create stack dotfile %s\n", stk_file);
    return;
  }

  prev_char_parent = NULL;

  ATfprintf(SG_StackDotFP, "strict digraph ParseTree { \n"
            "rankdir = LR; \n"
            "edge [dir = back]; \n"
           );
  SG_StacksToDot(SG_StackDotFP, sts);
  ATfprintf(SG_StackDotFP, "}\n");
  fclose(SG_StackDotFP);
}
