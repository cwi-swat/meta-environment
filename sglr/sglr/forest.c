/*
  %% $Id$

  \section{Parse forests}
  \label{forest.c}

  All data structures are represented by means of ToolBus terms.

  \subsection{forest.h}

  \input{forest.htx}

  \subsection{forest.c}

*/
#include <stdlib.h>

#include <aterm2.h>

#include "parse-table.h"
#include "stack.h"
#include "parser.h"
#include "forest.h"
#include "mem-alloc.h"
#include "sglr.h"


int SGnrAmb(int mode)
{
  static int nr_ambiguities = 0;

  switch(mode) {
    case SG_NRAMB_ASK:
      return nr_ambiguities;
    case SG_NRAMB_ZERO:
      return nr_ambiguities = 0;
    case SG_NRAMB_INC:
      return ++nr_ambiguities;
    default:
      return nr_ambiguities;  /* silence the compiler */
  }
}

int SG_ApplID(int Action)
{
  static int count = 0;

  switch(Action) {
    case SG_APPLID_ZERO:
      return (count = 0);
    default:
      return count++;
  }
}

/*
  The functions |apply| and |cons| are defined directly in terms
  of ATerm functions.
  Note: the appl is annotated with a (unique) id, for ambiguity chain
  forming
*/
ATerm SG_Apply(parse_table *pt, label l, ATermList ts)
{
/* Abbreviated:
  t =  ATmake("appl(aprod(<int>),<term>)", l, ts);
 */
  return ATmake("appl(<term>,<term>,<int>)", SG_LookupProduction(pt,l), ts, SG_ApplID(SG_APPLID_INC));
}


/* The next bit will have to do while waiting for this to be implemented */
#define AFun  Symbol
#define ATmakeAFun(s, t, f) ATmakeSymbol(s, t, f)
#define ATprotectAFun(t)    ATprotectSymbol(t)
#define ATgetAFun(t)        ATgetSymbol(t)

AFun  SG_Amb2Afun(void)
{
  static ATbool inited = ATfalse;
  static AFun fun;

  if(!inited) {
    fun = ATmakeAFun("appl", 2, ATfalse);
    ATprotectAFun(fun);
  }
  return fun;
}

AFun  SG_Amb3Afun(void)
{
  static ATbool inited = ATfalse;
  static AFun fun;

  if(!inited) {
    fun = ATmakeAFun("appl", 3, ATfalse);
    ATprotectAFun(fun);
  }
  return fun;
}

ATerm SG_YieldPT(ATerm t)
{
  ATerm     ret, t2;
  ATermList args, l;
  AFun      fun;

  switch(ATgetType(t)) {
    case AT_APPL:
      fun = ATgetAFun(t);
      args = ATgetArguments((ATermAppl) t);
      if(fun == SG_Amb3Afun()) {
        ATermList ambs;

        /* Are we indeed encountering an ambiguity cluster? */
        ambs = SG_AmbTable(SG_AMBTBL_LOOKUP, (ATermInt) ATgetLast(args), NULL);
        if(ATisEmpty(ambs))
          ret = (ATerm)ATmakeAppl2(SG_Amb2Afun(),
                                 SG_YieldPT(ATgetFirst(args)),
                                 SG_YieldPT(ATelementAt(args, 1)));
        else {
          ambs = (ATermList) ATgetFirst((ATermList)ambs);
          ret = (ATerm)ATmake("amb(<list>)",
                              (ATermList)SG_YieldPT((ATerm) ambs));
        }
      } else {
        ret = (ATerm) ATmakeApplList(fun,
                                    (ATermList) SG_YieldPT((ATerm)args));
      }
      return ret;
    case AT_LIST:
      if(ATisEmpty((ATermList) t)) return (ATerm) ATempty;
      for(l = ATempty, args = (ATermList) t;
          !ATisEmpty(args); args = ATgetPrefix(args)) {
        t2 = ATgetLast(args);
        l = ATinsert(l, SG_YieldPT(t2));
      }
      return (ATerm) l;
/*
    case AT_INT:
    case AT_REAL:
    case AT_PLACEHOLDER:
    case AT_BLOB:
*/
    default:
      return t;
  }
}

ATermList SG_AmbTable(int Mode, ATermInt index, ATermList value)
{
  static  ATermTable  ambtbl = NULL;
  ATermList           ambs;

  switch(Mode) {
    case SG_AMBTBL_INIT:
      if(ambtbl != NULL) SG_AmbTable(SG_AMBTBL_CLEAR, NULL, NULL);
      ambtbl = ATtableCreate(512, 75);
      break;
    case SG_AMBTBL_CLEAR:
      if(ambtbl) {
        ATtableDestroy(ambtbl);
        ambtbl = NULL;
      }
      break;
    case SG_AMBTBL_ADD:
      if(!ambtbl) SG_AmbTable(SG_AMBTBL_INIT, NULL, NULL);
      ATtablePut(ambtbl, (ATerm) index, (ATerm) value);
      break;
    case SG_AMBTBL_REMOVE:


      if(ambtbl) ATtableRemove(ambtbl, (ATerm) index);
      break;
    case SG_AMBTBL_LOOKUP:
      if (    ambtbl
          && (ambs = (ATermList) ATtableGet(ambtbl, (ATerm) index)))
        return ambs;
      break;
/*
    case SG_AMBTBL_DUMP:
      if(ambtbl) dump_ATtable(ambtbl, "AmbTable");
      break;
*/
  }
  return ATempty;
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
void SG_Amb(ATerm existing, ATerm new) {
  ATermList newidxs, newtrms, ambs, lst;
  ATerm     e0, e1, n0, n1, exist2, new2;
  ATermInt  index, e2, n2;

  /* Sanity check cum variable instantiation */
  if (   ATmatch(existing, "appl(<term>,<term>,<term>)", &e0, &e1, &e2)
      && ATmatch(new,      "appl(<term>,<term>,<term>)", &n0, &n1, &n2)) {
    /* Create/update ambiguity node. */
    ambs = SG_AmbTable(SG_AMBTBL_LOOKUP, e2, NULL);
    /* Add ambterms sans index, to prevent circular lookup when yielding */
    new2   = (ATerm) ATmakeAppl2(SG_Amb2Afun(), n0, n1);
    if(ATisEmpty(ambs)) {
      /* New ambiguity */
      exist2 = (ATerm) ATmakeAppl2(SG_Amb2Afun(), e0, e1);
      newtrms = ATmakeList2(exist2, new2);
      newidxs = ATmakeList2((ATerm) e2, (ATerm) n2);
    } else {
      /* Expand existing ambiguity */
//      ATfprintf(stderr, "Existing amb; args (%t,%t), found %t\n", existing,new,ambs);
      newtrms = ATinsert((ATermList) ATgetFirst(ambs), new2);
      newidxs = ATinsert((ATermList)  ATgetLast(ambs), (ATerm) n2);
    }
    ambs = ATmakeList2((ATerm) newtrms, (ATerm) newidxs);

    /* Now update ambiguity list for all affected nodes */
    for(lst = newidxs; !ATisEmpty(lst); lst = ATgetNext(lst)) {
      index = (ATermInt) ATgetFirst(lst);
//      ATfprintf(stderr, "AMB: updating index %t\n",index);
      SG_AmbTable(SG_AMBTBL_ADD, index, ambs);
    }
  } else
    ATerror("SG_Amb: symbolnode is not appl or amb\n%t\n", existing);

  SGnrAmb(SG_NRAMB_INC);
  return;
}

ATerm SG_TreeType(ATerm t)
{
  ATerm     type;
  ATermList args;

  if (ATmatch(t, "appl(prod(<term>,<term>,<term>),<term>,<int>)", NULL, &type, NULL,NULL,NULL))
    return type;
  if (ATmatch(t, "appl(prod(<term>,<term>,<term>), <term>)", NULL, &type, NULL,NULL))
    return type;
  else if (ATmatch(t, "amb([<list>])", &args))
    return SG_TreeType(ATgetFirst(args));
  else if (ATgetType(t) == AT_INT)
    return t;
  else
    ATerror("SG_TreeType: tree not well-formed\n%t\n", t);
  return NULL;   /* Silence the compiler */
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
        if(tmp == NULL) {
          tmp = (char *) SG_Malloc(TYA_TMPCHUNK);
          if(tmp == NULL)
            ATerror("memory allocation error\n");
          else
            tmpsize = TYA_TMPCHUNK;
        }
        tmp[0] = index = 0;
        break;
    case TYA_INQUIRE:
        break;
    case TYA_ADD:
        if((index+2) > tmpsize) {
          tmp = (char *)SG_Realloc(tmp, tmpsize + TYA_TMPCHUNK);
          if(tmp == NULL)
            ATerror("memory reallocation error\n");
          else
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
  ATermList args;

  if (ATisEmpty((ATermList) t))
    return;

  if (ATgetType(t) == AT_INT) {
   SG_TYAuxBuf(TYA_ADD, ATgetInt((ATermInt) t));
  }
  else if (ATmatch(t, "appl(<term>,[<list>])", NULL, &args) ||
           ATmatch(t, "appl(<term>,[<list>],<int>)", NULL, &args, NULL)) {
    SG_TYAux((ATerm) args);
  } else if (ATmatch(t, "[<list>]", &args)) {
      SG_TYAux(ATgetFirst(args));
      SG_TYAux((ATerm) ATgetNext(args));
  }
  else {
     ATerror("SG_TYAux: strange term: %t\n", t);
  }
}

ATerm SG_TermYield(ATerm t)
{
  SG_TYAuxBuf(TYA_INIT, 0);         /* Initialize (hidden) buffer */
  SG_TYAux(t);                      /* Yield to (hidden) buffer   */
                                    /* Collect & return buffer    */
  return ATmake("<str>", SG_TYAuxBuf(TYA_INQUIRE, 0));
}

void SG_DotTermYieldAux(ATerm t)
{
  ATermList args;
  int c;

  /* ATfprintf(stderr, "yield_aux(%t)\n", t); */

  if (ATisEmpty((ATermList) t))
    return;
  else if (ATgetType(t) == AT_INT) {
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
  } else if (ATmatch(t, "appl(<term>,[<list>])", NULL, &args) ||
             ATmatch(t, "appl(<term>,[<list>],<int>)", NULL, &args, NULL)) {
    if(ATgetLength(args) > 1) {
      SG_TYAuxBuf(TYA_ADD, '[');
      SG_TYAux((ATerm) args);
      SG_TYAuxBuf(TYA_ADD, ']');
    } else {
      SG_TYAux((ATerm) args);
    }
  } else if (ATmatch(t, "[<list>]", &args)) {
      SG_TYAux(ATgetFirst(args));
      SG_TYAux((ATerm) ATgetNext(args));
  } else if (ATmatch(t, "amb([<list>])", &args)) {
    while(!ATisEmpty(args)) {
      SG_DotTermYieldAux(ATgetFirst(args));
      args = ATgetNext(args);
      if(!ATisEmpty(args)) {
        SG_TYAuxBuf(TYA_ADD, '|');
      }
    }
  } else
     ATerror("SG_DotTermYieldAux: strange term: %t\n", t);
}

ATerm SG_DotTermYield(ATerm t)
{
  SG_TYAuxBuf(TYA_INIT, 0);          /* Initialize (hidden) buffer */
  SG_DotTermYieldAux(t);            /* Yield to (hidden) buffer   */
                                    /* Collect & return buffer    */
//ATfprintf(stderr, "Final Yield: ->%s<-\n", SG_TYAuxBuf(TYA_INQUIRE, 0));
  return ATmake("<str>", SG_TYAuxBuf(TYA_INQUIRE, 0));
}
