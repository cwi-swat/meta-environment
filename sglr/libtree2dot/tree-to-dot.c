/*

    SGLR - the Scannerless Generalized LR parser.
    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, The Netherlands.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/
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
#include  "sg_growbuf.h"

ATerm prev_char_parent;
char  prev_char;
ATbool print_prods = ATtrue;

char *SG_EscapeChar(int c)
{
  static char  escbuf[8];

  escbuf[0] = 0;
  switch(c) {
    case '\r' : strcpy(escbuf, "\\\\r");
      break;
    case '\n' : strcpy(escbuf, "\\\\n");
      break;
    case ' '  : strcpy(escbuf, "\\\\32");
      break;
    case '\t' : strcpy(escbuf, "\\\\t");
      break;

      /*
       * Treat the next chars with extra care
       */
    case '\\' : strcpy(escbuf, "\\\\");
      break;
    case '"'  : strcpy(escbuf, "\\\"");
      break;

    default :
      if(isprint(c))
        sprintf(escbuf, "%c", c);
      else
        sprintf(escbuf, "\\\\%d", c);
  }
  return escbuf;
}

void SG_PrintChar(FILE *dot, int c)
{
  ATfprintf(dot, "%s", SG_EscapeChar(c));
}


sg_growbuf *SG_PrintSymbolToGrowBuf(sg_growbuf *gb, ATerm t, ATbool escaped)
{
  char *name;
  ATerm     arg, arg2;
  ATermList args;
  int  c1, c2;

  if (ATmatch(t, "layout")) {
    SG_AddStringToGrowBuf(gb, "L");
  } else if (ATmatch(t, "sort(<str>)", &name)) {
    SG_AddStringToGrowBuf(gb, name);
  } else if (ATmatch(t, "lit(<str>)", &name)) {
    int n;
    SG_AddStringToGrowBuf(gb, escaped ? "\\\"" : "\"");
		if(escaped) {
			for(n = 0; name[n] != '\0'; n++) {
				char *thischar = SG_EscapeChar(name[n]);
				SG_AddStringToGrowBuf(gb, thischar);
			}
		} else {
			SG_AddStringToGrowBuf(gb, name);
		}
    SG_AddStringToGrowBuf(gb, escaped ? "\\\"" : "\"");
  } else if (ATmatch(t, "lex(<term>)", &arg)) {
    SG_AddStringToGrowBuf(gb, "<");
    SG_PrintSymbolToGrowBuf(gb, arg, escaped);
    SG_AddStringToGrowBuf(gb, "-LEX>");
  } else if (ATmatch(t, "cf(<term>)", &arg)) {
    SG_AddStringToGrowBuf(gb, "<");
    SG_PrintSymbolToGrowBuf(gb, arg, escaped);
    SG_AddStringToGrowBuf(gb, "-CF>");
  } else if (ATmatch(t, "iter-star(<term>)", &arg)) {
    SG_PrintSymbolToGrowBuf(gb, arg, escaped);
    SG_AddStringToGrowBuf(gb, "*");
  } else if (ATmatch(t, "iter(<term>)", &arg)) {
    SG_PrintSymbolToGrowBuf(gb, arg, escaped);
    SG_AddStringToGrowBuf(gb, "+");
  } else if (ATmatch(t, "iter-sep(<term>,<term>)", &arg, &arg2)) {
    SG_AddStringToGrowBuf(gb, "{");
    SG_PrintSymbolToGrowBuf(gb, arg, escaped);
    SG_AddStringToGrowBuf(gb, escaped ? "\\ " : " ");
    SG_PrintSymbolToGrowBuf(gb, arg2, escaped);
    SG_AddStringToGrowBuf(gb, "}+");
  } else if (ATmatch(t, "iter-star-sep(<term>,<term>)", &arg, &arg2)) {
    SG_AddStringToGrowBuf(gb, "{");
    SG_PrintSymbolToGrowBuf(gb, arg, escaped);
    SG_AddStringToGrowBuf(gb, escaped ? "\\ " : " ");
    SG_PrintSymbolToGrowBuf(gb, arg2, escaped);
    SG_AddStringToGrowBuf(gb, "}*");
  } else if (ATmatch(t, "iter-n(<term>, <int>)", &arg, &c1)) {
    char thissort[64];

    SG_PrintSymbolToGrowBuf(gb, arg, escaped);
    sprintf(thissort, "%d+", c1);
    SG_AddStringToGrowBuf(gb, thissort);
  } else if (ATmatch(t, "iter-sep-n(<term>,<term>,<int>)", &arg, &arg2, &c1)) {
    char thissort[64];

    SG_AddStringToGrowBuf(gb, "{");
    SG_PrintSymbolToGrowBuf(gb, arg, escaped);
    SG_AddStringToGrowBuf(gb, escaped ? "\\ " : " ");
    SG_PrintSymbolToGrowBuf(gb, arg2, escaped);
    sprintf(thissort, "}%d+", c1);
    SG_AddStringToGrowBuf(gb, thissort);
  } else if (ATmatch(t, "seq([<list>])", &args)) {
    SG_AddStringToGrowBuf(gb, "(");
    while (!ATisEmpty(args)) {
      arg = ATgetFirst(args);
      args = ATgetNext(args);
      SG_PrintSymbolToGrowBuf(gb, arg, escaped);
      if (args) SG_AddStringToGrowBuf(gb, escaped ? "\\ " : " ");
    }
    SG_AddStringToGrowBuf(gb, ")");
  } else if (ATmatch(t, "opt(<term>)", &arg)) {
    SG_PrintSymbolToGrowBuf(gb, arg, escaped);
    SG_AddStringToGrowBuf(gb, "?");
  } else if (ATmatch(t, "alt(<term>,<term>)", &arg, &arg2)) {
    SG_PrintSymbolToGrowBuf(gb, arg, escaped);
    SG_AddStringToGrowBuf(gb, "|");
    SG_PrintSymbolToGrowBuf(gb, arg2, escaped);
  } else if (ATmatch(t, "char-class([<list>])", &args)) {
    SG_AddStringToGrowBuf(gb, "[");
    while (!ATisEmpty(args)) {
      char *thischar = NULL;
      arg = ATgetFirst(args);
      args = ATgetNext(args);
      if (ATmatch(arg, "range(<int>,<int>)", &c1, &c2)) {

				if(escaped) {
					thischar = SG_EscapeChar(c1);
				} else {
					thischar[0] = c1;
					thischar[1] = '\0';
				}
				SG_AddStringToGrowBuf(gb, thischar);
        SG_AddStringToGrowBuf(gb, "-");
				if(escaped) {
					thischar = SG_EscapeChar(c2);
				} else {
					thischar[0] = c2;
					thischar[1] = '\0';
				}
				SG_AddStringToGrowBuf(gb, thischar);
			} else if (ATmatch(arg, "<int>", &c1)) {
				if(escaped) {
					thischar = SG_EscapeChar(c1);
				} else {
					thischar[0] = c1;
					thischar[1] = '\0';
				}
				SG_AddStringToGrowBuf(gb, thischar);
			}
    }
    SG_AddStringToGrowBuf(gb, "]");
  } else if (ATmatch(t, "varsym(<term>)", &arg)) {
    SG_AddStringToGrowBuf(gb, "<");
    SG_PrintSymbolToGrowBuf(gb, arg, escaped);
    SG_AddStringToGrowBuf(gb, "-VAR>");
  } else
    ATerror("SG_PrintSymbol: strange symbol %t\n", t);

  return gb;
}


char *SG_PrintSymbolToString(ATerm t, ATbool escaped)
{
  static sg_growbuf *gb = NULL;
  char  *symbstr = NULL;

  if(!gb) {
	gb = SG_Create_GrowBuf(32, 16, sizeof(char));
  } else {
    gb = SG_Reset_GrowBuf(gb);
  }

  SG_PrintSymbolToGrowBuf(gb, t, escaped);
  SG_AddToGrowBuf(gb, "\0", 1);    /*  Null string termination  */
  symbstr = strdup(SG_GetGrowBufContent(gb));

  if(!symbstr) {
    ATerror("error allocating string duplicate\n");
    return NULL;
  }

  return symbstr;
}

void SG_PrintSymbol(FILE *dot, ATerm t)
{
  static sg_growbuf *gb = NULL;

  if(!gb) {
    gb = SG_Create_GrowBuf(32, 16, sizeof(char));
  } else {
    gb = SG_Reset_GrowBuf(gb);
  }

  SG_WriteGrowBuf(dot, SG_PrintSymbolToGrowBuf(gb, t, ATtrue));
}

void SG_PrintAttrs(FILE *dot,  ATerm attrs)
{
	ATermList list;
	char *str;
	
	if(ATmatch(attrs, "no-attrs")) {
		return;
	} else {
		if(ATmatch(attrs, "attrs([<list>])", &list)) {

			if(!ATisEmpty(list)) {
							
				for(; !ATisEmpty(list); list = ATgetNext(list)) {
					ATerm first = ATgetFirst(list);
					
					
					if(ATmatch(first, "cons(<str>)", &str)) {
						ATfprintf(dot,"cons(");
						ATfprintf(dot, str);
						ATfprintf(dot,")");
					} else if(ATmatch(first, "aterm(cons(<str>))", &str)) {
						ATfprintf(dot,"aterm(cons(");
						ATfprintf(dot, str);
						ATfprintf(dot,"))");
					} else if(ATmatch(first,"atr(<str>)", &str)) {
						ATfprintf(dot, str);
					} else if(ATmatch(first,"id(<str>)", &str)) {
						/* We don't print id's because they are not
						 * inserted by the user 
						 */
					} else if(ATmatch(first, "traverse")) {
						ATfprintf(dot, "traverse");
					}
					
					ATfprintf(dot," ");
				}
			}
		}
	}
	return;
}

void SG_ApplNode(FILE *dot, ATerm t, ATerm fun, int n, ATbool print_prods)
{
  ATerm args, res, attrs;

  if (SG_IS_MARKED(t))
    return;

  SG_MARK(t);

	if(!print_prods) {
		if (ATmatch(fun, "prod([<list>], <term>, <term>)", &args, &res, &attrs)) {
			ATfprintf(dot, "\tN%d [label=\"", (int)t);
			SG_PrintSymbol(dot, res);
			if(ATmatch(attrs,"attrs([atr(\"reject\"),<list>])", &attrs))
				ATfprintf(dot, " (reject)");
			ATfprintf(dot, "\"]\n");
		} else {
			ATerror("SG_ApplNode: not a production %t\n", fun);
		}
	} else { /* printing prods instead of result sorts */
		ATermList arglist;

		if (ATmatch(fun, "prod([<list>], <term>, <term>)", &arglist, &res, &attrs)) {
			ATfprintf(dot, "\tN%d [shape=box label=\" ", (int)t);
			for(;!ATisEmpty(arglist); arglist = ATgetNext(arglist)) {
				SG_PrintSymbol(dot, ATgetFirst(arglist));
				ATfprintf(dot," ");
			}
			ATfprintf(dot, " -> ");
			SG_PrintSymbol(dot, res);
			ATfprintf(dot, " ");
			SG_PrintAttrs(dot, attrs);
			ATfprintf(dot, " \"]\n");
		}
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

  if(ATmatch(t, "appl(aprod(<int>),<list>)", NULL, NULL) ||
     ATmatch(t, "regular(aprod(<int>),<list>)",NULL,NULL) || 
     ATmatch(t, "avoid(aprod(<int>),<list>)",NULL,NULL) || 
		 ATmatch(t, "prefer(aprod(<int>),<list>)",NULL,NULL) || 
		 ATmatch(t, "reject(aprod(<int>),<list>)", NULL, NULL)) {
    extern    parse_table *table;

    return SG_TreeType(
                       ATmake("appl(<term>,[])",
                              SG_LookupProduction(table, SG_GetApplProdLabel((tree) t))));
  }

  ATerror("SG_TreeType: tree not well-formed\n%t\n", t);
  return NULL;   /* Silence the compiler */
}


void SG_TreeToDot(FILE *dot, ATerm t, int child, ATerm parent,
                  ATbool suppress_lexicals, ATbool print_prods)
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
        SG_TreeToDot(dot, arg, n, t, suppress_lexicals, print_prods);
      }
    }
    SG_ApplNode(dot, t, fun, n, print_prods);
  } else if (ATmatch(t, "amb([<list>])", &args)) {
    if(!ATisEmpty(args)) SG_AmbNode(dot, t, ATgetFirst(args));
    while (!ATisEmpty(args)) {
      arg = ATgetFirst(args);
      args = ATgetNext(args);
      n++;
      ATfprintf(dot, "\tN%d -> N%d\n", (int)t, (int)arg);
      SG_TreeToDot(dot, arg, n, t, suppress_lexicals, print_prods);
    }
  } else if (ATmatch(t, "parsetree(<term>, <int>)", &arg, &c))
    SG_TreeToDot(dot, arg, 1, t, suppress_lexicals, print_prods);
}

void SGtreeToDotFile(char *prg, char *file, ATerm t, ATbool suppress, ATbool print_prods)
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
  SG_TreeToDot(dot, t, 0, NULL, suppress, print_prods);
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
	the_tree = (ATerm) (SG_LK_TREE(l));
  t = SG_TreeType(the_tree); 
  if(ATgetType(the_tree) == AT_INT) {
    SG_PrintChar(dot, ATgetInt((ATermInt) t));
  } else {
		ATfprintf(dot, "%d : ", SG_GetApplProdLabel((tree) the_tree)); 
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
}

void SG_StacksToDotFileFinalize(FILE *fp)
{
	if(fp) {
		ATfprintf(fp, "}\n");
		fclose(fp);
	}
}

void SG_TermYieldToGrowBuf(sg_growbuf *gb, ATerm t)
{
  if (ATisEmpty((ATermList) t))
    return;

  switch(ATgetType(t)) {
    case AT_INT:
      SG_AddCharToGrowBuf(gb, ATgetInt((ATermInt) t));
      break;
    case AT_APPL:
      SG_TermYieldToGrowBuf(gb, ATelementAt(ATgetArguments((ATermAppl) t), 1));
      break;
    case AT_LIST:
      SG_TermYieldToGrowBuf(gb,         ATgetFirst((ATermList) t));
      SG_TermYieldToGrowBuf(gb, (ATerm) ATgetNext((ATermList) t));
      break;
    default:
      ATerror("SG_TermYieldToGrowBuf: strange term: %t\n", t);
      break;
  }
}

ATerm SG_TermYield(ATermAppl t)
{
  static sg_growbuf *gb = NULL;

  if(!gb) {
	gb = SG_Create_GrowBuf(32, 16, sizeof(char));
  } else {
    gb = SG_Reset_GrowBuf(gb);
  }
  SG_TermYieldToGrowBuf(gb, (ATerm) t);

  return ATmake("<str>", SG_GetGrowBufContent(SG_AddToGrowBuf(gb, "\0", 1)));
}

#define AFunIs(f, s, ar, q) (ATisQuoted(f)==q && ATgetArity(f)==ar     \
                             && !strcmp(s, ATgetName(f)))

void SG_DotTermYieldToGrowBuf(sg_growbuf *gb, ATerm t)
{
  AFun      fun;
  ATermList args;
  int  c;

  if (ATisEmpty((ATermList) t))
    return;

  switch(ATgetType(t)) {
    case AT_INT:
      switch(c = ATgetInt((ATermInt) t)) {
        case '\n':
          SG_AddStringToGrowBuf(gb, "\\\\n");
          break;
        default:
          SG_AddCharToGrowBuf(gb, c);
          break;
      }
      break;
    case AT_APPL:
      fun = ATgetAFun((ATermAppl) t);
      if(AFunIs(fun, "appl", 2, ATfalse)
         || AFunIs(fun, "reject", 2, ATfalse)) {
        args = (ATermList) ATelementAt(ATgetArguments((ATermAppl) t), 1);
        if(ATgetLength(args) > 1) {
          SG_AddCharToGrowBuf(gb, '[');
          SG_DotTermYieldToGrowBuf(gb, (ATerm) args);
          SG_AddCharToGrowBuf(gb, ']');
        } else {
          SG_DotTermYieldToGrowBuf(gb, (ATerm) args);
        }
      } else if(AFunIs(fun, "amb", 1, ATfalse)) {
        args = ATgetArguments((ATermAppl) t);
        while(!ATisEmpty(args)) {
          SG_DotTermYieldToGrowBuf(gb, ATgetFirst(args));
          args = ATgetNext(args);
          if(!ATisEmpty(args)) {
            SG_AddCharToGrowBuf(gb, '|');
          }
        }
			} else {
        ATerror("SG_DotTermYieldToGrowBuf: strange appl: %t\n", t);
      }
        break;
    case AT_LIST:
      SG_DotTermYieldToGrowBuf(gb, ATgetFirst((ATermList) t));
      SG_DotTermYieldToGrowBuf(gb, (ATerm) ATgetNext((ATermList) t));
      break;
    default:
      ATerror("SG_DotTermYieldToGrowBuf: strange term: %t\n", t);
      break;
  }
}

ATerm SG_DotTermYield(ATerm t)
{
  static sg_growbuf *gb = NULL;

  if(!gb) {
	gb = SG_Create_GrowBuf(32, 16, sizeof(char));
  } else {
    gb = SG_Reset_GrowBuf(gb);
  }
  SG_DotTermYieldToGrowBuf(gb, (ATerm) t);

  return ATmake("<str>", SG_GetGrowBufContent(SG_AddToGrowBuf(gb, "\0", 1)));
}
