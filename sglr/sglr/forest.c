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


ATerm     CycleStart = NULL;
ATbool    CycleShown;
ATermList Cycle;

void SG_ShowCycle(ATerm CurrTerm, ATerm CycleStart)
{
  ATermList ambs;
  ATermInt  idx;
  AFun      fun;

  if(CycleShown)
    return;

  if(ATisEqual(CurrTerm,CycleStart)) {
    CycleShown = ATtrue;
    return;
  }

  if(CurrTerm == NULL) {
    Cycle      = ATempty;
    CycleShown = ATfalse;
    CurrTerm   = CycleStart;
  }

  switch(ATgetType(CurrTerm)) {
    case AT_APPL:

      fun  = ATgetAFun((ATermAppl) CurrTerm);
      if(fun == SG_ApplAFun()) {
        Cycle = ATinsert(Cycle, (ATerm) SG_GetApplProdLabel((ATermAppl) CurrTerm));
//        ATfprintf(stderr, "Cycle: aprod[%t]\n", SG_GetApplProdLabel((ATermAppl) CurrTerm));
      } else if (fun == SG_AprodAFun()) {
        Cycle = ATinsert(Cycle, (ATerm) SG_GetProdLabel((ATermAppl) CurrTerm));
//        ATfprintf(stderr, "Cycle: prod[%t]\n", SG_GetProdLabel((ATermAppl) CurrTerm));
      }

      idx  = (ATermInt) ATgetAnnotation((ATerm) CurrTerm, SG_ApplLabel());
      /*  Ambiguity cluster?  */
      if(!idx || ATisEmpty(ambs = SG_AmbTable(SG_AMBTBL_LOOKUP, idx, NULL))) {
        /*  No ambiguity  */
        SG_ShowCycle(ATgetArgument((ATermAppl) CurrTerm, 1), CycleStart);
      } else {
        /*  Encountered an ambiguity cluster  */
        SG_ShowCycle((ATerm) ambs, CycleStart);
      }
      break;
    case AT_LIST:
      if(!ATisEmpty((ATermList) CurrTerm)) {
        SG_ShowCycle(      ATgetFirst((ATermList) CurrTerm), CycleStart);
        SG_ShowCycle((ATerm)ATgetNext((ATermList) CurrTerm), CycleStart);
      }
    default:
      break;
  }
}

#ifdef TABLE_INSTEAD_OF_MARKS
  ATermTable MarkTable;
  #define SG_IS_MARKED(t)	(ATtableGet(MarkTable, t) != NULL)
  #define SG_MARK(t)		ATtablePut(MarkTable, t, SG_ApplAFun())
  #define SG_UNMARK(t)		ATtableRemove(MarkTable, t)
#endif

void SG_TermIsCyclic(ATerm t)
{
  ATermList ambs;
  ATermInt  idx;
  AFun      fun;

  if(CycleStart)
    return;

  if(SG_IS_MARKED(t)) {                     /*  Cycle detected  */
    CycleStart = t;
    return;
  } else {
    SG_MARK(t);
  }

  switch(ATgetType(t)) {
    case AT_APPL:
      if((fun  = ATgetAFun(t)) == SG_AmbAFun()) {
        SG_TermIsCyclic(ATgetArgument((ATermAppl) t, 0));
        break;
      }
      if(fun == SG_AprodAFun()) {
        break;
      }

      idx  = (ATermInt) ATgetAnnotation((ATerm) t, SG_ApplLabel());
      /*  Ambiguity cluster?  */
      if(!idx || ATisEmpty(ambs = SG_AmbTable(SG_AMBTBL_LOOKUP, idx, NULL))) {
        /*  No ambiguity  */
        SG_TermIsCyclic(ATgetArgument((ATermAppl) t, 1));
      } else {
        /*  Encountered an ambiguity cluster  */
         SG_TermIsCyclic((ATerm) ambs);
      }
      break;

    case AT_LIST:
      if(!ATisEmpty((ATermList) t)) {
        SG_TermIsCyclic(      ATgetFirst((ATermList) t));
        SG_TermIsCyclic((ATerm)ATgetNext((ATermList) t));
      }
      break;

    default:
      break;
  }

  SG_UNMARK(t);
}


ATermList SG_CyclicTerm(ATerm t) {
#ifdef TABLE_INSTEAD_OF_MARKS
  MarkTable = ATtableCreate(4096, 75);
#endif
  CycleStart = NULL;
  SG_TermIsCyclic(t);
#ifdef TABLE_INSTEAD_OF_MARKS
  ATtableDestroy(MarkTable);
#endif
  SG_ShowCycle(NULL, CycleStart);
//  ATfprintf(stderr, "cycle: %t\n", ATreverse(Cycle));

  return(CycleStart?ATreverse(Cycle):ATempty);
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

  if(fun != SG_ApplAFun()) {
    return ATmakeApplList(fun, (ATermList) SG_YieldPT(pt, (ATerm)args));
  }

  idx  = (ATermInt) ATgetAnnotation((ATerm) t, SG_ApplLabel());

  /*  Are we encountering an ambiguity cluster?  */
  if(!idx || ATisEmpty(ambs = SG_AmbTable(SG_AMBTBL_LOOKUP, idx, NULL))) {
    /*  No ambiguity  */
    if(SG_ABBREV && !recurse)
      return t;
    t = (ATermAppl) ATgetFirst(args);
    if(!SG_ABBREV)
      t = SG_ExpandApplNode(pt, t, ATfalse);
    if(recurse)
      return ATmakeAppl2(SG_ApplAFun(), (ATerm) t,
                         SG_YieldPT(pt, ATelementAt(args, 1)));
    return ATmakeAppl2(SG_ApplAFun(), (ATerm) t, ATelementAt(args, 1));
  }

  /*  Encountered an ambiguity cluster  */
  SG_MaxNrAmb(SG_NRAMB_DEC);
  trms = (ATermList) ATgetFirst(ambs);
  /*  Singular?  */
  if (ATgetLength(trms) == 1) {
    t = (ATermAppl) ATgetFirst(trms);
    if(recurse)
      return (ATermAppl) SG_YieldPT(pt, (ATerm) t);
    else
      return SG_ABBREV ? t : SG_ExpandApplNode(pt, t, ATfalse);
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
      if(ambtbl) SG_Dump_ATtable(ambtbl, "AmbTable");
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

void SG_MakeMultiSet(ATerm t, ATermTable ms)
{
  ATermInt prodlabel, prevcount;
  int      count;

  switch(ATgetType(t)) {
    case AT_APPL:
      prodlabel = SG_GetApplProdLabel((ATermAppl) t);
      if((prevcount = (ATermInt) ATtableGet(ms, (ATerm) prodlabel)))
        count = ATgetInt(prevcount) + 1;
      else
        count = 1;
      ATtablePut(ms, (ATerm) prodlabel, (ATerm) ATmakeInt(count));
      SG_MakeMultiSet(ATgetArgument((ATermAppl) t, 1), ms);
      return;
    case AT_LIST:
      if(ATisEmpty((ATermList) t))
        return;
      for(; !ATisEmpty((ATermList) t); t = (ATerm) ATgetNext((ATermList) t))
        SG_MakeMultiSet(ATgetFirst((ATermList) t), ms);
      return;
/*
    case AT_INT:
    case AT_REAL:
    case AT_PLACEHOLDER:
    case AT_BLOB:
*/
    default:
      return;
  }
  return;  /*  for the compiler's sake  */
}

int SG_GetMultiSet(ATermTable ms, ATermInt prodlabel)
{
  ATermInt val;

  if((val = (ATermInt) ATtableGet(ms, (ATerm) prodlabel)))
    return ATgetInt(val);
  return 0;
}

/*
 #define SG_MultiSetGtr(pt, M, N)	SG_MultiSetLwr(pt, N, M)
 */

ATbool SG_MultiSetGtr(parse_table *pt, ATermTable msM, ATermTable msN)
{
  ATermInt  x, y;
  ATermList M, N, RestrictedM = ATempty;
  ATbool    foundone;

  /*  multi-prio is irreflexive  */
/*
  // Tested in SG_MultiSetPriority, let's assume it's not called elsewhere 
  if(ATtableIsEqual(multiset1, multiset2))
    return NULL;
 */

  /*
     Construct restriction:
      { x in M | Exists y in N: M(x) > N(x) /\ x gtr-prio y}
   */
  for(M = ATtableKeys(msM); M && !ATisEmpty(M); M = ATgetNext(M)) {
    x = (ATermInt) ATgetFirst(M);
    foundone = ATfalse;
    for(N = ATtableKeys(msN); N && !(foundone||ATisEmpty(N));
        N = ATgetNext(N)) {
          y = (ATermInt) ATgetFirst(N);
	  if(SG_GetMultiSet(msM, x) > SG_GetMultiSet(msN, x)
          && SG_GtrPriority(pt, x, y)) {
	    RestrictedM = ATinsert(RestrictedM, (ATerm) x);
            foundone = ATtrue;
          }
    }
  }

  if(ATisEmpty(RestrictedM))
    return ATfalse;

  for(M = RestrictedM; M && !ATisEmpty(M); M = ATgetNext(M)) {
    y = (ATermInt) ATgetFirst(M);
    if(SG_GetMultiSet(msM, y) > SG_GetMultiSet(msN, y)) {
      foundone = ATfalse;
      for(N = ATtableKeys(msN); N && !(foundone||ATisEmpty(N));
          N = ATgetNext(N)) {
        x = (ATermInt) ATgetFirst(N);
        if (SG_GetMultiSet(msM, x) < SG_GetMultiSet(msN, x)
        &&  SG_GtrPriority(pt, y, x)) {
          foundone = ATtrue;
        }
      }
      if(!foundone) {
        return ATfalse;
      }
    }
  }

  return ATtrue;
}


ATbool ATsubTable(ATermTable t1, ATermTable t2)
{
  ATerm     key;
  ATermList keys;

  if(t2 == NULL)
    return ATfalse;
  if(t1 == NULL)
    return ATtrue;

  /*  Now check if all the keys in t1 exist in t2, with equal values  */
  for(keys = ATtableKeys(t1); keys && !ATisEmpty(keys);
            keys=ATgetNext(keys)) {
    key = ATgetFirst(keys);
    if(ATtableGet(t1, key) != ATtableGet(t2, key))
      return ATfalse;
  }
  return ATtrue;
}

ATbool ATtableIsEqual(ATermTable t1, ATermTable t2)
{
  if(t1 == t2)
    return ATtrue;

  if(t1 == NULL || t2 == NULL)
    return ATfalse;

  if(!ATisEqual(ATtableKeys(t1), ATtableKeys(t2)))
    return ATfalse;

  if(!ATsubTable(t1, t2))
    return ATfalse;

  if(!ATsubTable(t2, t1))
    return ATfalse;

  return ATtrue;
}

ATbool SG_Injection(parse_table *pt, ATermInt label)
{
  ATerm prod, in;

  prod = SG_LookupProduction(pt, ATgetInt(label));

  if(ATmatch(prod, "prod([<term>],cf(sort(<str>)),<term>)",
     &in, NULL, NULL)) {
    if(ATmatch(in, "lit(<str>)", NULL)) {
      return ATfalse;
    } else { 
/* ATfprintf(stderr, "CF INJECTION (%t): %t\n", in, prod); */
       return ATtrue;
    }
  }

/* Do We Want This?! */
  if(ATmatch(prod, "prod([<term>],lex(sort(<str>)),<term>)",
     &in, NULL, NULL)) {
    if(ATmatch(in, "lit(<str>)", NULL)) {
      return ATfalse;
    } else { 
/* ATfprintf(stderr, "LEX INJECTION (%t): %t\n", in, prod); */
       return ATtrue;
    }
  }

/*  ATfprintf(stderr, "Not an injection -- PROD: %t\n", prod); */
  return ATfalse;
}


int SG_CountInjections(parse_table *pt, ATermTable T)
{
  ATerm     key;
  ATermList keys;
  int       ret = 0;

  for(keys = ATtableKeys(T); keys && !ATisEmpty(keys);
            keys=ATgetNext(keys)) {
    key = ATgetFirst(keys);
    if(SG_Injection(pt, (ATermInt) key))
      ret += ATgetInt((ATermInt) ATtableGet(T, key));
  }
  return ret;
}

/*
  SG_Filter -- a generic hook to add disambiguating `filters'

  Arguments:  the current parse table
	      two terms
  Returns:    the preferred term of the two, or NULL if there is no
              filter that prefers either one of them
 */

ATermAppl SG_Filter(parse_table *pt, ATermAppl t0, ATermAppl t1)
{
  ATermInt   l0, l1;
  ATermTable m0, m1;
  ATermAppl  max = NULL;

  /*  Don't even bother unless filtering is enabled  */

  if(!SG_FILTER)
    return NULL;

  /*  First apply direct priority filtering.  */

  l0 = SG_GetApplProdLabel((ATermAppl) t0);
  l1 = SG_GetApplProdLabel((ATermAppl) t1);

  if(SG_GtrPriority(pt, l0, l1)) {
    if(SG_DEBUG)
      ATfprintf(SGlog(), "Direct Priority: %t > %t (bad parse table?)\n", l0, l1);
    return t0;
  }
  if(SG_GtrPriority(pt, l1, l0)) {
    if(SG_DEBUG)
      ATfprintf(SGlog(), "Direct Priority: %t < %t (bad parse table?)\n", l0, l1);
    return t1;
  }

  /*  No direct priority relation?  Apply multiset ordering.  */

  m0 = ATtableCreate(256, 75);
  m1 = ATtableCreate(256, 75);
  SG_MakeMultiSet((ATerm) t0, m0);
  SG_MakeMultiSet((ATerm) t1, m1);

  if(!ATisEqual(t0, t1) && !ATtableIsEqual(m0, m1)) {
                                            /*  multi-prio is irreflexive  */
    if(SG_MultiSetGtr(pt, m0, m1)) {
      if(SG_DEBUG)
        ATfprintf(SGlog(), "Multiset Priority: %t > %t\n", l0, l1);
      max = t0;
    }
  /* else */
    if(SG_MultiSetGtr(pt, m1, m0)) {
      if(max != NULL) {
        if(SG_DEBUG)
          ATfprintf(SGlog(), "Multiset priority relation is not antisymmetric, ignoring it\n");
        ATfprintf(stderr, "Multiset priority relation is not antisymmetric, ignoring it\n");
        max = NULL;
      } else {
        if(SG_DEBUG)
          ATfprintf(SGlog(), "Multiset Priority: %t < %t\n", l0, l1);
        max = t1;
      }
    }
  }

  /*  No multiset ordering either?  Count injections.  */

#if 1
  if(max == NULL) {
    int in0, in1;

    in0 = SG_CountInjections(pt, m0);
    in1 = SG_CountInjections(pt, m1);

    if(in0 > in1) {
      if(SG_DEBUG)
        ATfprintf(SGlog(), "Injection Priority: %t < %t\n", l0, l1);
      max = t1;
    } else if(in0 < in1) {
      if(SG_DEBUG)
        ATfprintf(SGlog(), "Injection Priority: %t > %t\n", l0, l1);
      max = t0;
    }
  }
#endif

  ATtableDestroy(m0);
  ATtableDestroy(m1);

  return max;
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
  ATermAppl max;

  ex_annot = ATgetAnnotation((ATerm) existing, SG_ApplLabel());
  nw_annot = ATgetAnnotation((ATerm) new,      SG_ApplLabel());

  ambs   = SG_AmbTable(SG_AMBTBL_LOOKUP, (ATermInt) ex_annot, NULL);
  nw_cln = ATremoveAnnotation((ATerm) new, SG_ApplLabel());
  if(ATisEmpty(ambs)) {
    /* New ambiguity */
    SG_MaxNrAmb(SG_NRAMB_INC);
    newidxs = ATmakeList2(ex_annot, nw_annot);

    /*  Filter the two  */
    max = SG_Filter(pt, existing, new);
    if(!ATisEqual(max, new)) {
      ex_cln = ATremoveAnnotation((ATerm) existing, SG_ApplLabel());
      if(ATisEqual(max, existing)) {
        newtrms = ATmakeList1(ex_cln);
	if(SG_DEBUG)
          ATfprintf(SGlog(), "Priority: %t > %t (new amb)\n",
                    SG_GetApplProdLabel(existing), SG_GetApplProdLabel(new));
      } else {
        newtrms = ATmakeList2(ex_cln, nw_cln);
      }
    } else {
        newtrms = ATmakeList1(nw_cln);
	if(SG_DEBUG)
          ATfprintf(SGlog(), "Priority: %t < %t (new amb)\n",
                    SG_GetApplProdLabel(existing), SG_GetApplProdLabel(new));
    }
  } else {
    /* Expand (or update) existing ambiguity */
    ATermList oldtrms;
    ATermAppl prev;
    ATbool    nw_has_lower_priority = ATfalse;

    newidxs = ATinsert((ATermList) ATgetLast(ambs), nw_annot);
    /*  Re-filter with existing ambiguities  */
    newtrms = ATempty;
    for(oldtrms = (ATermList) ATgetFirst(ambs); !ATisEmpty(oldtrms);
        oldtrms = ATgetNext(oldtrms)) {
      prev = (ATermAppl) ATgetFirst(oldtrms);
      max = SG_Filter(pt, prev, new);
      if(!ATisEqual(max, new)) {
        newtrms = ATinsert(newtrms, (ATerm) prev);
        if(ATisEqual(max, prev)) {
          nw_has_lower_priority = ATtrue;
	  if(SG_DEBUG)
            ATfprintf(SGlog(), "Priority: %t > %t (old amb)\n",
                      SG_GetApplProdLabel(prev), SG_GetApplProdLabel(new));
        }
      } else {
	if(SG_DEBUG)
          ATfprintf(SGlog(), "Priority: %t > %t (old amb)\n",
                    SG_GetApplProdLabel(prev), SG_GetApplProdLabel(new));
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
          if(tmp == NULL) {
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
          tmp = (char *)SG_Realloc(tmp, tmpsize + TYA_TMPCHUNK);
          if(tmp == NULL) {
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
