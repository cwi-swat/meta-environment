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

#include "mem-alloc.h"
#include "forest.h"
#include "sglr.h"


int SG_MaxNrAmb(int mode)
{
  static int nr_ambiguities = 0;

  switch(mode) {
    case SG_NRAMB_ASK:
      return nr_ambiguities;
    case SG_NRAMB_ZERO:
      return nr_ambiguities = 0;
    case SG_NRAMB_INC:
      return ++nr_ambiguities;
    case SG_NRAMB_DEC:
      return --nr_ambiguities;
    default:
      return nr_ambiguities;  /* silence the compiler */
  }
}

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
    case SG_NRAMB_DEC:
      return --nr_ambiguities;
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

ATerm SG_ApplLabel(void)
{
  static ATerm label = NULL;

  if(label == NULL) {
    label = ATmake("<str>", SG_APPLLABEL);
    ATprotect(&label);
  }
  return label;
}

ATerm SG_RejectLabel(void)
{
  static ATerm label = NULL;

  if(label == NULL) {
    label = ATmake("<str>", SG_REJECTLABEL);
    ATprotect(&label);
  }
  return label;
}

AFun  SG_ApplAFun(void)
{
  static AFun fun = (AFun) NULL;

  if(fun == (AFun) NULL) {
    fun = ATmakeAFun("appl", 2, ATfalse);
    ATprotectAFun(fun);
  }
  return fun;
}


AFun  SG_AprodAFun(void)
{
  static AFun fun = (AFun) NULL;

  if(fun == (AFun) NULL) {
    fun = ATmakeAFun("aprod", 1, ATfalse);
    ATprotectAFun(fun);
  }
  return fun;
}

AFun  SG_AmbAFun(void)
{
  static AFun fun = (AFun) NULL;

  if(fun == (AFun) NULL) {
    fun = ATmakeAFun("amb", 1, ATfalse);
    ATprotectAFun(fun);
  }
  return fun;
}

/*
  The functions |apply| and |cons| are defined directly in terms
  of ATerm functions.
  Note: the appl is annotated with a (unique) id, for ambiguity chain
  forming
*/

ATerm SG_Apply(parse_table *pt, label l, ATermList ts, ATbool reject)
{
  ATerm t;

/*
  if(1 || SG_ABBREV)
    t = (ATerm) ATmakeAppl2(SG_ApplAFun(),
                            (ATerm) ATmakeAppl1(SG_AprodAFun(),
                                                (ATerm) ATmakeInt(l)),
                            (ATerm) ts);
  else
    t = (ATerm) ATmakeAppl2(SG_ApplAFun(), SG_LookupProduction(pt,l),
                            (ATerm) ts);
#if 0
  if(reject)
    t = ATsetAnnotation(t, SG_RejectLabel(), (ATerm) ATmakeInt(1));
#endif
 */
  t = (ATerm) ATmakeAppl2(SG_ApplAFun(),
                          (ATerm) ATmakeAppl1(SG_AprodAFun(),
                                              (ATerm) ATmakeInt(l)),
                          (ATerm) ts);
  return ATsetAnnotation(t, SG_ApplLabel(),
                        (ATerm) ATmakeInt(SG_ApplID(SG_APPLID_INC)));
}

ATermAppl SG_ExpandApplNode(parse_table *pt, ATermAppl t, ATbool recurse)
{
  ATermList ambs, trms;
  ATermInt  idx;
  AFun      fun  = ATgetAFun(t);
  ATermList args = ATgetArguments((ATermAppl) t);

  if(fun == SG_AprodAFun()) {
    return SG_ABBREV ? t :
          (ATermAppl) SG_LookupProduction(pt, ATgetInt(SG_GetProdLabel(t)));
  }

  if(fun != SG_ApplAFun())
    return ATmakeApplList(fun, (ATermList) SG_YieldPT(pt, (ATerm)args));

  idx  = (ATermInt) ATgetAnnotation((ATerm) t, SG_ApplLabel());
  /*  Are we indeed encountering an ambiguity cluster?  */
  if(!idx || ATisEmpty(ambs = SG_AmbTable(SG_AMBTBL_LOOKUP, idx, NULL))) {
    if(SG_ABBREV && !recurse)
      return t;
    t = (ATermAppl) ATgetFirst(args);
    if(!SG_ABBREV)
      t = SG_ExpandApplNode(pt, t, ATfalse);
    /*  No ambiguity  */
    if(recurse)
      return ATmakeAppl2(SG_ApplAFun(), (ATerm) t,
                         SG_YieldPT(pt, ATelementAt(args, 1)));
    return ATmakeAppl2(SG_ApplAFun(), (ATerm) t, ATelementAt(args, 1));
  }
  /*  Encountered an ambiguity cluster  */
  SG_MaxNrAmb(SG_NRAMB_DEC);
  /*  Singular?  */
  trms = (ATermList) ATgetFirst(ambs);
  if (ATgetLength(trms) == 1) {
    t = (ATermAppl) ATgetFirst(trms);
    if(recurse)
      return (ATermAppl) SG_YieldPT(pt, (ATerm) t);
    else
      return t;
  }
  /*  Multiple: this is truly an ambiguous node  */
  SGnrAmb(SG_NRAMB_INC);
  if(recurse)
    trms = (ATermList) SG_YieldPT(pt, (ATerm) trms);
  else if(!SG_ABBREV)  /*  The abbreviations must still be expanded  */
    for(ambs=trms, trms=ATempty; !ATisEmpty(ambs); ambs=ATgetPrefix(ambs))
      trms = ATinsert(trms,
                      (ATerm) SG_ExpandApplNode(pt, (ATermAppl) ATgetLast(ambs),
                                                ATfalse));

  return ATmakeAppl1(SG_AmbAFun(), (ATerm) trms);
}

ATerm SG_YieldPT(parse_table *pt, ATerm t)
{
  ATerm     elt;
  ATermList args, l;
/*
  int       maxambs;

  if((maxambs  = SG_MaxNrAmb(SG_NRAMB_ASK)) == 0)
    return t;
 */

  switch(ATgetType(t)) {
    case AT_APPL:
      return (ATerm) SG_ExpandApplNode(pt, (ATermAppl) t, ATtrue);
    case AT_LIST:
      if(ATisEmpty((ATermList) t)) return (ATerm) ATempty;
      for(l = ATempty, args = (ATermList) t;
          !ATisEmpty(args); args = ATgetPrefix(args)) {
        elt = ATgetLast(args);
        l = ATinsert(l, SG_YieldPT(pt, elt));
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
    case SG_AMBTBL_UPDATE:
      if(!ambtbl) SG_AmbTable(SG_AMBTBL_INIT, NULL, NULL);
      ATtablePut(ambtbl, (ATerm) index, (ATerm) value);
      break;
    case SG_AMBTBL_REMOVE:
      if(ambtbl) ATtableRemove(ambtbl, (ATerm) index);
      break;
    case SG_AMBTBL_LOOKUP:
      if (ambtbl && (ambs = (ATermList) ATtableGet(ambtbl, (ATerm) index)))
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


ATermInt SG_GetProdLabel(ATermAppl aprod)
{
  return (ATermInt) ATgetArgument(aprod, 0);
}

ATermInt SG_GetApplProdLabel(ATermAppl appl)
{
  return SG_GetProdLabel((ATermAppl) ATgetArgument(appl, 0));
}

/*
  SG_MaxPriority returns
    * lbl0,  if priority(lbl0) > priority(lbl1)
    * lbl1,  if priority(lbl1) > priority(lbl0)
    * NULL,  if there is no priority relation between lbl0 and lbl1
 */

ATbool SG_GtrPriority(parse_table *pt, ATermInt l0, ATermInt l1)
{
  ATermList prios;

  if((prios = SG_LookupPriority(pt, l0))
  && (ATindexOf(prios, (ATerm) l1, 0) != -1))
    return ATtrue;
  return ATfalse;
}

ATermInt SG_MaxPriority(parse_table *pt, ATermInt l0, ATermInt l1)
{
  if(SG_GtrPriority(pt, l0, l1))
    return l0;
  if(SG_GtrPriority(pt, l1, l0))
    return l1;
  return NULL;
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

void SG_Amb(parse_table *pt, ATermAppl existing, ATermAppl new) {
  ATermList ambs, newtrms, newidxs, lst;
  ATerm     ex_annot, nw_annot;
  ATerm     ex_cln, nw_cln;
  ATermInt  index;
  ATermInt  nw_prd, ex_prd, max_prd;

  ex_annot = ATgetAnnotation((ATerm) existing, SG_ApplLabel());
  nw_annot = ATgetAnnotation((ATerm) new,      SG_ApplLabel());

  nw_prd = SG_GetApplProdLabel(new);

  ambs   = SG_AmbTable(SG_AMBTBL_LOOKUP, (ATermInt) ex_annot, NULL);
  nw_cln = ATremoveAnnotation((ATerm) new, SG_ApplLabel());
  if(ATisEmpty(ambs)) {
    /* New ambiguity */
    SG_MaxNrAmb(SG_NRAMB_INC);
    newidxs = ATmakeList2(ex_annot, nw_annot);

    /*  Enforce prioritization, if any, upon these two lovebirds  */
    ex_prd = SG_GetApplProdLabel(existing);
    max_prd = SG_MaxPriority(pt, ex_prd, nw_prd);
    if(max_prd != nw_prd) {
      ex_cln = ATremoveAnnotation((ATerm) existing, SG_ApplLabel());
      if(max_prd == ex_prd) {
        newtrms = ATmakeList1(ex_cln);
	if(SG_DEBUG)
          ATfprintf(SGlog(), "Priority: %t > %t (new amb)\n", ex_prd, nw_prd);
      } else {
        newtrms = ATmakeList2(ex_cln, nw_cln);
      }
    } else {
        newtrms = ATmakeList1(nw_cln);
	if(SG_DEBUG)
          ATfprintf(SGlog(), "Priority: %t > %t (new amb)\n", nw_prd, ex_prd);
    }
  } else {
    /* Expand (or update) existing ambiguity */
    ATermList oldtrms;
    ATermAppl prev;
    ATermInt  prev_prd;
    ATbool    nw_has_lower_priority = ATfalse;

    newidxs = ATinsert((ATermList) ATgetLast(ambs), nw_annot);
    /*  Refilter existing ambiguities to enforce priorities  */
    newtrms = ATempty;
    for(oldtrms = (ATermList) ATgetFirst(ambs); !ATisEmpty(oldtrms);
        oldtrms = ATgetNext(oldtrms)) {
      prev = (ATermAppl) ATgetFirst(oldtrms);
      prev_prd = SG_GetApplProdLabel(prev);
      max_prd = SG_MaxPriority(pt, prev_prd, nw_prd);

      if(max_prd != nw_prd) {
        newtrms = ATinsert(newtrms, (ATerm) prev);
        if(max_prd == prev_prd) {
          nw_has_lower_priority = ATtrue;
	  if(SG_DEBUG)
            ATfprintf(SGlog(), "Priority: %t > %t (old amb)\n", prev_prd, nw_prd);
        }
      } else {
	if(SG_DEBUG)
          ATfprintf(SGlog(), "Priority: %t > %t (old amb)\n", nw_prd, prev_prd);
      }
    }
    if(!nw_has_lower_priority)
      newtrms = ATinsert(newtrms, nw_cln);
  }
  ambs = ATmakeList2((ATerm) newtrms, (ATerm) newidxs);

  /* Now update ambiguity list for all affected nodes */
  for(lst = newidxs; !ATisEmpty(lst); lst = ATgetNext(lst)) {
    index = (ATermInt) ATgetFirst(lst);
    SG_AmbTable(SG_AMBTBL_ADD, index, ambs);
  }

  return;
}

ATerm SG_TreeType(ATerm t)
{
  ATerm     type;
  ATermList args;

  if (ATgetType(t) == AT_INT)
    return t;
  if (ATmatch(t, "appl(prod(<term>,<term>,<term>),<term>)",
              NULL, &type, NULL,NULL))
    return type;
  if (ATmatch(t, "amb([<list>])", &args))
    return SG_TreeType(ATgetFirst(args));

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

ATerm SG_TermYield(ATerm t)
{
  SG_TYAuxBuf(TYA_INIT, 0);         /* Initialize (hidden) buffer */
  SG_TYAux(t);                      /* Yield to (hidden) buffer   */
                                    /* Collect & return buffer    */
  return ATmake("<str>", SG_TYAuxBuf(TYA_INQUIRE, 0));
}

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
      fun  = ATgetAFun((ATermAppl) t);
      if(fun == SG_ApplAFun()) {
        args = (ATermList) ATelementAt(ATgetArguments((ATermAppl) t), 1);
        if(ATgetLength(args) > 1) {
          SG_TYAuxBuf(TYA_ADD, '[');
          SG_DotTermYieldAux((ATerm) args);
          SG_TYAuxBuf(TYA_ADD, ']');
        } else {
          SG_DotTermYieldAux((ATerm) args);
        }
      } else if(fun == SG_AmbAFun()) {
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
