/*
 $Id$

 file: tree-to-dot.c

 Purpose: dumping parse trees as dot graphs, i.e., input for
 the dot graph layout program.
 */

#include <ctype.h>
#include <string.h>

#include <aterm2.h>

#include  <forest.h>

#include  "tree-to-dot.h"
#include  "mem-alloc.h"

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
      if(isprint(c))
        ATfprintf(dot, "%c", c);
      else
        ATfprintf(dot, "\\\\%i", c);
  }
}

void SG_PrintSymbol(FILE *dot, ATerm t)
{
  char *name;
  ATerm     arg, arg2;
  ATermList args;
  int  c1, c2;

  if (ATmatch(t, "layout")) {
    ATfprintf(dot, "L");
  } else if (ATmatch(t, "sort(<str>)", &name)) {
    ATfprintf(dot, "%s", name);
  } else if (ATmatch(t, "lit(<str>)", &name)) {
    int n;
    ATfprintf(dot, "\\\"");
    for(n = 0; name[n] != '\0'; n++) {
      SG_PrintChar(dot, name[n]);
    }
    ATfprintf(dot, "\\\"");
  } else if (ATmatch(t, "lex(<term>)", &arg)) {
    ATfprintf(dot, "<");
    SG_PrintSymbol(dot, arg);
    ATfprintf(dot, "-LEX>");
  } else if (ATmatch(t, "cf(<term>)", &arg)) {
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
  } else
    ATerror("SG_PrintSymbol: strange symbol %t\n", t);
}

void SG_ApplNode(FILE *dot, ATerm t, ATerm fun, int n)
{
  ATerm args, res, attrs;

  if (SG_IS_MARKED(t))
    return;

  SG_MARK(t);

  if (ATmatch(fun, "prod([<list>], <term>, <term>)", &args, &res, &attrs)) {
    ATfprintf(dot, "\tN%d [label=\"", (int)t);
    SG_PrintSymbol(dot, res);
    if(ATmatch(attrs,"attrs([atr(\"reject\"),<list>])", &attrs))
      ATfprintf(dot, " (reject)");
    ATfprintf(dot, "\"]\n");
  } else {
    ATerror("SG_ApplNode: not a production %t\n", fun);
  }
}

void SG_AmbNode(FILE *dot, ATerm t, ATerm arg)
{
  ATerm args, res, attrs, args2;

  if (ATmatch(arg, "appl(prod([<list>],<term>,<term>),[<list>])",
              &args, &res, &attrs, &args2)) {
    ATfprintf(dot, "\tN%d [label=\"", (int)t);
    SG_PrintSymbol(dot, res);
    ATfprintf(dot, "\" shape=diamond style=\"bold,filled\"]\n");
  } else
    ATerror("SG_AmbNode: warning strange node %t\n", arg);
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


ATerm SG_TreeType(ATerm t)
{
  ATerm     type;
  ATermList args;

  if (ATgetType(t) == AT_INT)
    return t;
  if (ATmatch(t, "appl(prod(<term>,<term>,<term>),<term>)",
              NULL, &type, NULL,NULL)) {
    return type;
  }
  if (ATmatch(t, "amb([<list>])", &args))
    return SG_TreeType(ATgetFirst(args));

  if(ATmatch(t, "appl(aprod(<int>),<list>)", NULL, NULL)
     || ATmatch(t, "reject(aprod(<int>),<list>)", NULL, NULL)) {
    extern    parse_table *table;

    return SG_TreeType(
                       ATmake("appl(<term>,[])",
                              SG_LookupProduction(table, SG_GetApplProdLabel((tree) t))));
  }

  ATerror("SG_TreeType: tree not well-formed\n%t\n", t);
  return NULL;   /* Silence the compiler */
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
  if (SG_IS_MARKED(t))
    return;

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
  } else if (ATmatch(t, "amb([<list>])", &args)) {
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
  FILE *dot = NULL;

  if (!file || !strcmp(file, ""))
    file = "parse.dot";
  if(!strcmp(file, "-"))
    dot = stdout;
  else
    dot = fopen(file, "w");
  if (!dot) {
    ATfprintf(stderr, "%s: cannot create dotfile %s\n", prg, file);
    exit(1);
  }

  prev_char_parent = NULL;

  ATfprintf(dot, "digraph ParseTree {\n"
            "\tordering=out\n"
            "\tedge[dir=none]\n\n");
  SG_TreeToDot(dot, t, 0, NULL, suppress);
  ATfprintf(dot, "}\n");
  if(dot != stdout)
    fclose(dot);
}

void SG_LinkToDot(FILE *dot, stack *st, st_link *l)
{
  ATerm t, the_tree;

  ATfprintf(dot, "N%d [label=\"%d\" shape=box height=0.2, width=0.2]\n",
            (int) st, SG_ST_STATE(st));
  ATfprintf(dot, "N%d -> N%d [label=\"", (int) SG_LK_STACK(l), (int) st);
  the_tree = (ATerm) SG_LK_TREE(l);
  t = SG_TreeType(the_tree);
  if(ATgetType(the_tree) == AT_INT) {
    SG_PrintChar(dot, ATgetInt((ATermInt) t));
  } else {
    ATfprintf(dot, "%s : ", SG_DotTermYield(the_tree));
    SG_PrintSymbol(dot, t);
  }
  ATfprintf(dot, "\"");
  if(SG_Rejected(st))
    ATfprintf(dot, " style = dotted");
  ATfprintf(dot, "]\n");
}

void SG_LinksToDot(FILE *dot, stack *st)
{
  st_links *ls;

  ls = SG_ST_LINKS(st);
  while(ls) {
    SG_LinkToDot(dot, st, SG_HEAD(ls));
    ls = SG_TAIL(ls);
  }
}

void SG_StackToDot(FILE *dot, stack *st)
{
  st_links *ls;

  if(!st)
    return;

  ATfprintf(dot, "N%d [label=\"%d\" shape=box height=0.2, width=0.2]\n",
            (int) st, SG_ST_STATE(st));
  ls = SG_ST_LINKS(st);
  SG_LinksToDot(dot, st);
  while(ls) {
    SG_StackToDot(dot, SG_LK_STACK(SG_HEAD(ls)));
    ls = SG_TAIL(ls);
  }
}

void SG_StacksToDot(FILE *dot, stacks *sts)
{
  while(sts) {
    SG_StackToDot(dot, SG_HEAD(sts));
    sts = SG_TAIL(sts);
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

  return s?(sdo=s):sdo;
}

void SG_StacksToDotFile(stacks *sts, int sg_tokens_read)
{
  char stk_file[256];

  sprintf(stk_file, "%s%d.dot", SG_StackDotOut(NULL), sg_tokens_read);

  if (!(SG_StackDotFP = fopen(stk_file, "w"))) {
    ATfprintf(stderr, "Cannot create stack dotfile %s\n", stk_file);
    return;
  }

  prev_char_parent = NULL;

  ATfprintf(SG_StackDotFP, "digraph ParseStack {\n"
            "rankdir = LR\n"
            "edge [dir = back]\n"
            );
  SG_StacksToDot(SG_StackDotFP, sts);
  ATfprintf(SG_StackDotFP, "}\n");
  fclose(SG_StackDotFP);
}

#define TYA_TMPCHUNK 64
#define TYA_INIT     0
#define TYA_INQUIRE  1
#define TYA_ADD      2

char *SG_TYAuxBuf(int Mode, char c) {
  static char   *tmp = NULL;
  static size_t  tmpsize = 0;
  static int    index = 0;

  switch(Mode) {
    case TYA_INIT:
      if(!tmp) {
        tmp = (char *) SG_Malloc(1, TYA_TMPCHUNK);
        if(!tmp) {
          ATfprintf(stderr, "memory allocation error\n");
          exit(1);
        } else
          tmpsize = TYA_TMPCHUNK;
      }
      tmp[0] = index = 0;
      break;
    case TYA_INQUIRE:
      break;
    case TYA_ADD:
      if((index+2) > tmpsize) {
        tmp = (char *)SG_Realloc(tmp, tmpsize + TYA_TMPCHUNK, sizeof(char));
        if(!tmp) {
          ATfprintf(stderr, "memory reallocation error\n");
          exit(1);
        } else
          tmpsize += TYA_TMPCHUNK;
      }
      tmp[index++] = c;
      tmp[index] = 0;
      break;
  }
  return tmp;
}

void SG_TYAux(ATerm t)
{
  if (ATisEmpty((ATermList) t))
    return;

  switch(ATgetType(t)) {
    case AT_INT:
      SG_TYAuxBuf(TYA_ADD, ATgetInt((ATermInt) t));
      break;
    case AT_APPL:
      SG_TYAux(ATelementAt(ATgetArguments((ATermAppl) t), 1));
      break;
    case AT_LIST:
      SG_TYAux(ATgetFirst((ATermList) t));
      SG_TYAux((ATerm) ATgetNext((ATermList) t));
      break;
    default:
      ATerror("SG_TYAux: strange term: %t\n", t);
      break;
  }
}

ATerm SG_TermYield(ATermAppl t)
{
  SG_TYAuxBuf(TYA_INIT, 0);         /* Initialize (hidden) buffer */
  SG_TYAux((ATerm) t);              /* Yield to (hidden) buffer   */
  /* Collect & return buffer    */
  return ATmake("<str>", SG_TYAuxBuf(TYA_INQUIRE, 0));
}

#define AFunIs(f, s, ar, q) (ATisQuoted(f)==q && ATgetArity(f)==ar     \
                             && !strcmp(s, ATgetName(f)))

void SG_DotTermYieldAux(ATerm t)
{
  AFun      fun;
  ATermList args;
  int c;

  if (ATisEmpty((ATermList) t))
    return;

  switch(ATgetType(t)) {
    case AT_INT:
      switch(c = ATgetInt((ATermInt) t)) {
        case '\n':
          SG_TYAuxBuf(TYA_ADD, '\\');
          SG_TYAuxBuf(TYA_ADD, '\\');
          SG_TYAuxBuf(TYA_ADD, 'n');
          break;
        default:
          SG_TYAuxBuf(TYA_ADD, c);
          break;
      }
      break;
    case AT_APPL:
      fun = ATgetAFun((ATermAppl) t);
      if(AFunIs(fun, "appl", 2, ATfalse)
         || AFunIs(fun, "reject", 2, ATfalse)) {
        args = (ATermList) ATelementAt(ATgetArguments((ATermAppl) t), 1);
        if(ATgetLength(args) > 1) {
          SG_TYAuxBuf(TYA_ADD, '[');
          SG_DotTermYieldAux((ATerm) args);
          SG_TYAuxBuf(TYA_ADD, ']');
        } else {
          SG_DotTermYieldAux((ATerm) args);
        }
      } else if(AFunIs(fun, "amb", 1, ATfalse)) {
        args = ATgetArguments((ATermAppl) t);
        while(!ATisEmpty(args)) {
          SG_DotTermYieldAux(ATgetFirst(args));
          args = ATgetNext(args);
          if(!ATisEmpty(args)) {
            SG_TYAuxBuf(TYA_ADD, '|');
          }
        }
      } else {
        ATerror("SG_DotTermYieldAux: strange appl: %t\n", t);
      }
        break;
    case AT_LIST:
      SG_DotTermYieldAux(ATgetFirst((ATermList) t));
      SG_DotTermYieldAux((ATerm) ATgetNext((ATermList) t));
      break;
    default:
      ATerror("SG_DotTermYieldAux: strange term: %t\n", t);
      break;
  }
}

ATerm SG_DotTermYield(ATerm t)
{
  SG_TYAuxBuf(TYA_INIT, 0);         /* Initialize (hidden) buffer */
  SG_DotTermYieldAux(t);            /* Yield to (hidden) buffer   */

  /* Collect & return buffer    */
  return ATmake("<str>", SG_TYAuxBuf(TYA_INQUIRE, 0));
}
