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
    case SG_NRAMB_ZERO:
      return nr_ambiguities = 0;
    case SG_NRAMB_INC:
      return nr_ambiguities++;
    case SG_NRAMB_DEC:
      return nr_ambiguities--;
    case SG_NRAMB_ASK:
    default:
      return nr_ambiguities;
  }
}

int SGnrAmb(int mode)
{
  static int nr_ambiguities = 0;

  switch(mode) {
    case SG_NRAMB_ZERO:
      return nr_ambiguities = 0;
    case SG_NRAMB_INC:
      return ++nr_ambiguities;
    case SG_NRAMB_DEC:
      return --nr_ambiguities;
    case SG_NRAMB_ASK:
    default:
      return nr_ambiguities;
  }
}

ATerm SG_ApplLabel(void)
{
  static ATerm label = NULL;

  if(!label) {
    label = ATmake("<str>", SG_APPLLABEL);
    ATprotect(&label);
  }
  return label;
}

ATerm SG_RejectLabel(void)
{
  static ATerm label = NULL;

  if(!label) {
    label = ATmake("<str>", SG_REJECTLABEL);
    ATprotect(&label);
  }
  return label;
}

AFun  SG_ApplAFun(void)
{
  static AFun fun = (AFun) NULL;

  if(!fun) {
    fun = ATmakeAFun("appl", 2, ATfalse);
    ATprotectAFun(fun);
  }
  return fun;
}


AFun  SG_AprodAFun(void)
{
  static AFun fun = (AFun) NULL;

  if(!fun) {
    fun = ATmakeAFun("aprod", 1, ATfalse);
    ATprotectAFun(fun);
  }
  return fun;
}

AFun  SG_AmbAFun(void)
{
  static AFun fun = (AFun) NULL;

  if(!fun) {
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
  return (ATerm) ATmakeAppl2(SG_ApplAFun(),
                             (ATerm) ATmakeAppl1(SG_AprodAFun(),
                                                 (ATerm) ATmakeInt(l)),
                             (ATerm) ts);
}


ATerm     CycleStart = NULL;
ATbool    CycleShown;
ATermList Cycle;

void SG_ShowCycle(ATerm CurrTerm, ATerm CycleStart)
{
  ATermList ambs;
  AFun      fun;

  if(CycleShown)
    return;

  if(ATisEqual(CurrTerm,CycleStart)) {
    CycleShown = ATtrue;
    return;
  }

  if(!CurrTerm) {
    Cycle      = ATempty;
    CycleShown = ATfalse;
    CurrTerm   = CycleStart;
  }

  switch(ATgetType(CurrTerm)) {
    case AT_APPL:

      fun  = ATgetAFun((ATermAppl) CurrTerm);
      if(ATisEqual(fun, SG_ApplAFun())) {
        Cycle = ATinsert(Cycle, (ATerm) SG_GetApplProdLabel((ATermAppl) CurrTerm));
      } else if (ATisEqual(fun, SG_AprodAFun())) {
        Cycle = ATinsert(Cycle, (ATerm) SG_GetProdLabel((ATermAppl) CurrTerm));
      }

      /*  Ambiguity cluster?  */
      if(ATisEmpty(ambs = (ATermList) SG_AmbTable(SG_AMBTBL_GET,
                                                  CurrTerm, NULL))) {
        /*  No ambiguity  */
        SG_ShowCycle(ATgetArgument((ATermAppl) CurrTerm, 1), CycleStart);
      } else {
        ATerm amb;
        /*  Encountered an ambiguity cluster  */
        for(; !ATisEmpty(ambs); ambs = ATgetNext(ambs)) {
          amb = ATgetFirst(ambs);
          if(!ATisEqual(CurrTerm, amb))
            SG_ShowCycle(amb, CycleStart);
        }
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
  #define SG_IS_MARKED(t)	ATtableGet(MarkTable, t)
  #define SG_MARK(t)		ATtablePut(MarkTable, t, SG_ApplAFun())
  #define SG_UNMARK(t)		ATtableRemove(MarkTable, t)
#endif

void SG_TermIsCyclic(ATerm t)
{
  ATermList ambs;
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
      if(ATisEqual((fun = ATgetAFun(t)), SG_AmbAFun())) {
        SG_TermIsCyclic(ATgetArgument((ATermAppl) t, 0));
        break;
      }
      if(ATisEqual(fun, SG_AprodAFun())) {
        break;
      }

      /*  Ambiguity cluster?  */
      if(ATisEmpty(ambs = (ATermList) SG_AmbTable(SG_AMBTBL_GET, t, NULL))) {
        /*  No ambiguity  */
        SG_TermIsCyclic(ATgetArgument((ATermAppl) t, 1));
      } else {
        ATerm amb;
        /*  Encountered an ambiguity cluster  */
        for(; !ATisEmpty(ambs); ambs = ATgetNext(ambs)) {
          amb = ATgetFirst(ambs);
          if(!ATisEqual(t, amb))
            SG_TermIsCyclic(amb);
        }
            
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

  return(CycleStart?ATreverse(Cycle):ATempty);
}


ATermAppl SG_ExpandApplNode(parse_table *pt, ATermAppl t,
                            ATbool recurse, ATbool doamb)
{
  ATermList ambs, trms;
  AFun      fun  = ATgetAFun(t);
  ATermList args = ATgetArguments((ATermAppl) t);

  if(ATisEqual(fun, SG_AprodAFun())) {
    return SG_ABBREV ? t :
          (ATermAppl) SG_LookupProduction(pt, ATgetInt(SG_GetProdLabel(t)));
  }

  if(!ATisEqual(fun, SG_ApplAFun())) {
    return ATmakeApplList(fun, (ATermList) SG_YieldPT(pt, (ATerm)args));
  }

  /*  Are we encountering an ambiguity cluster?  */
  if(!doamb         /*  Are we even interested?  */
     || ATisEmpty(ambs = (ATermList) SG_AmbTable(SG_AMBTBL_GET,
                                                 (ATerm) t, NULL))) {
    /*  No ambiguity, or we're ignoring it...  */
    if(SG_ABBREV && !recurse)
      return t;
    t = (ATermAppl) ATgetFirst(args);
    if(!SG_ABBREV)
      t = SG_ExpandApplNode(pt, t, ATfalse, ATtrue);
    if(recurse)
      return ATmakeAppl2(SG_ApplAFun(), (ATerm) t,
                         SG_YieldPT(pt, ATelementAt(args, 1)));
    return ATmakeAppl2(SG_ApplAFun(), (ATerm) t, ATelementAt(args, 1));
  }

  /*  Encountered an ambiguity cluster  */
  SG_MaxNrAmb(SG_NRAMB_DEC);
  /*  Singular?  */
  if (ATgetLength(ambs) == 1) {
    t = (ATermAppl) ATgetFirst(ambs);
    if(!recurse && SG_ABBREV)
      return t;
    else
      return (ATermAppl) SG_ExpandApplNode(pt, t, recurse, ATfalse);
  }
  /*  Multiple: this is truly an ambiguous node  */
  SGnrAmb(SG_NRAMB_INC);
  if(recurse || !SG_ABBREV)
    for(trms=ATempty; !ATisEmpty(ambs); ambs=ATgetPrefix(ambs))
      trms = ATinsert(trms,
                      (ATerm) SG_ExpandApplNode(pt, (ATermAppl) ATgetLast(ambs),
                                                recurse, ATfalse));
  else
    trms=ambs;

  return ATmakeAppl1(SG_AmbAFun(), (ATerm) trms);
}

ATerm SG_YieldPT(parse_table *pt, ATerm t)
{
  ATerm     elt;
  ATermList args, l;

  switch(ATgetType(t)) {
    case AT_APPL:
      return (ATerm) SG_ExpandApplNode(pt, (ATermAppl) t, ATtrue, ATtrue);
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


/*
    Ambiguity Tables provide a mapping from terms to sets of terms,
    reflecting the ambiguity relation.  Note that terms can be
    `prioritized out' or rejected, so that the mapping may or may not
    yield a set containing the key term.

    One implementation: a one-level lookup.  In that case, the Ambiguity
    Table is a table of Ambiguity Clusters.  It maps terms |t| onto
    AmbClusters |<i,a>|; here, t is a member of i, and _may_ be a member
    of a.  Furthermore, <i,a> is shared between all t' in i.  This
    sharing must be explicitly maintained.

    Alternative implementation: a two-level mapping:

    * a mapping from terms to indexes (of ambiguity clusters)
    * a mapping from indexes to sets of terms (the ambiguity cluster)

   Maintenance in the latter approach is simple: for new ambiguity
   clusters, simply create them; updates to existing ambiguity
   clusters can be performed simply by looking up the index from
   one of the terms that share the ambiguity, and update the
   ambiguity cluster as desired.

 */
ATerm SG_AmbTable(int Mode, ATerm key, ATerm value)
{
  static  ATermTable  ambtbl = NULL;
  ATerm               ret = (ATerm) ATempty, idx = NULL;

  switch(Mode) {

    case SG_AMBTBL_GET:
      if((idx = SG_AmbTable(SG_AMBTBL_LOOKUP_INDEX, key, NULL)))
        ret = SG_AmbTable(SG_AMBTBL_LOOKUP_CLUSTER, idx, NULL);
      break;
      
    case SG_AMBTBL_INIT:
      if(ambtbl)
        SG_AmbTable(SG_AMBTBL_CLEAR, NULL, NULL);
      ambtbl = ATtableCreate(2048, 75);
      break;

    case SG_AMBTBL_CLEAR:
      if(ambtbl) {
        ATtableDestroy(ambtbl);
        ambtbl = NULL;
      }
      break;
      
    case SG_AMBTBL_ADD_INDEX:
    case SG_AMBTBL_ADD_CLUSTER:
    case SG_AMBTBL_UPDATE_INDEX:
    case SG_AMBTBL_UPDATE_CLUSTER:
      if(!ambtbl)
        SG_AmbTable(SG_AMBTBL_INIT, NULL, NULL);
      ATtablePut(ambtbl, key, value);
      break;
   
    case SG_AMBTBL_REMOVE:
      if(!ambtbl)
        break;
      if((idx = SG_AmbTable(SG_AMBTBL_LOOKUP_INDEX, key, NULL))) {
        ATtableRemove(ambtbl, key);
        if(!ATisEmpty((ATermList) SG_AmbTable(SG_AMBTBL_LOOKUP_CLUSTER,
                                              idx, NULL)))
          ATtableRemove(ambtbl, idx);
      }
      break;

    case SG_AMBTBL_LOOKUP_INDEX:
    case SG_AMBTBL_LOOKUP_CLUSTER:
      if(!ambtbl)
        return (ATerm) ATempty;
      ret = ATtableGet(ambtbl, key);
      ret=ret?ret:(ATerm) ATempty;
      break;

#ifdef DEBUG
    case SG_AMBTBL_DUMP:
      if(ambtbl) SG_Dump_ATtable(ambtbl, "Ambs");
      break;
#endif
  }
  return ret;
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

  if(!t2)
    return ATfalse;
  if(!t1)
    return ATtrue;

  /*  Now check if all the keys in t1 exist in t2, with equal values  */
  for(keys = ATtableKeys(t1); keys && !ATisEmpty(keys);
            keys=ATgetNext(keys)) {
    key = ATgetFirst(keys);
    if(!ATisEqual(ATtableGet(t1, key), ATtableGet(t2, key)))
      return ATfalse;
  }
  return ATtrue;
}

ATbool ATtableIsEqual(ATermTable t1, ATermTable t2)
{
  if(t1 == t2)
    return ATtrue;

  if(!t1 || !t2)
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
    if(SG_Injection(pt, (ATermInt) key)) {
      ret += ATgetInt((ATermInt) ATtableGet(T, key));
/*
      ATfprintf(stderr, "Count: %d, Term: %t\n",
                ATgetInt((ATermInt) ATtableGet(T, key)), key);
 */
    }
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
    if(SG_MultiSetGtr(pt, m1, m0)) {
      if(max) {                             /*  shouldn't happen, really  */
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
  if(!max) {
    int in0, in1;

    in0 = SG_CountInjections(pt, m0);
    in1 = SG_CountInjections(pt, m1);
/*
ATfprintf(stderr, "t0: #injections: %d, term: %t\n", in0, t0);
ATfprintf(stderr, "t1: #injections: %d, term: %t\n", in1, t1);
 */
    if(in0 > in1) {
      if(SG_DEBUG)
        ATfprintf(SGlog(), "Injection Priority: %t < %t (%d > %d)\n",
                  l0, l1, in0, in1);
      max = t1;
    } else if(in0 < in1) {
      if(SG_DEBUG)
        ATfprintf(SGlog(), "Injection Priority: %t > %t (%d < %d)\n",
                  l0, l1, in0, in1);
      max = t0;
    }
  }
#endif

  ATtableDestroy(m0);
  ATtableDestroy(m1);

/*
  if(max)
    ATfprintf(stderr, "t0: %t\nt1: %t\n",
              SG_ExpandApplNode(pt, t0, ATtrue, ATtrue),
              SG_ExpandApplNode(pt, t1, ATtrue, ATtrue));
 */
  return max;
}


/*
  The function |amb| creates a term of the form |amb([t1,...,tn])|,
  where the |ti| are the alternatives of the ambiguous node. If
  the first argument term |t1| of |amb| is an application a new
  |amb| node is created by overwriting the application node and
  creating a new application node as one of the arguments of
  this |amb| node. If |t1| is already an ambiguous node the ne
  term |t2| is simply added to the list of its arguments.
*/

void SG_Amb(parse_table *pt, ATermAppl existing, ATermAppl new) {
  ATermList newambs;
  ATerm     ambidx;
  ATermAppl max;

  ambidx = SG_AmbTable(SG_AMBTBL_LOOKUP_INDEX, (ATerm) existing, NULL);
  if(!ambidx || ATisEmpty((ATermList) ambidx)) {
    /* New ambiguity */
    ambidx = (ATerm) ATmakeInt(SG_MaxNrAmb(SG_NRAMB_INC));
    /* Add mapping for existing term also */
    SG_AmbTable(SG_AMBTBL_ADD_INDEX, (ATerm) existing, ambidx);

    /*  Filter the two  */
    if(!(max = SG_Filter(pt, existing, new))) {
      /*  max and new are not priority-related */
      newambs = ATmakeList2((ATerm) existing, (ATerm) new);
    } else {
      /*  new and existing are in a priority relation, max is top  */
      newambs = ATmakeList1((ATerm) max);
      if(max && SG_DEBUG)
        ATfprintf(SGlog(), "Priority: %t %c %t (new amb)\n",
                  SG_GetApplProdLabel(existing),
                  ATisEqual(max, existing)?'>':'<',
                  SG_GetApplProdLabel(new));
    }
  } else {
    /* Expand (or update) existing ambiguity */
    ATermList oldambs;
    ATermAppl prev;
    ATbool    nw_has_lower_priority = ATfalse;

    oldambs = (ATermList) SG_AmbTable(SG_AMBTBL_LOOKUP_CLUSTER, ambidx, NULL);

    if(ATindexOf(oldambs, (ATerm) new, 0) != -1) {  /*  Already present?  Done.  */
      return;
    }

    /*  Filter new with against existing terms in ambiguity cluster  */
    newambs = ATempty;
    for(; !ATisEmpty(oldambs); oldambs = ATgetNext(oldambs)) {
      prev = (ATermAppl) ATgetFirst(oldambs);

      /* add prev to newambs, unless new has a higher priority  */
      if(!(max = SG_Filter(pt, prev, new))
      || ATisEqual(max, prev)) {
        newambs = ATinsert(newambs, (ATerm) prev);
      }
      if(max) {
        if(ATisEqual(max, prev))
          nw_has_lower_priority = ATtrue;
        if(SG_DEBUG)
          ATfprintf(SGlog(), "Priority: %t %c %t (old amb)\n",
                    SG_GetApplProdLabel(prev),
                    ATisEqual(max, prev)?'>':'<',
                    SG_GetApplProdLabel(new));
      }
    }
    if(!nw_has_lower_priority)
      newambs = ATinsert(newambs, (ATerm) new);
  }

  /*   Update ambiguity cluster  */
  SG_AmbTable(SG_AMBTBL_ADD_INDEX, (ATerm) new, ambidx);
  SG_AmbTable(SG_AMBTBL_UPDATE_CLUSTER, ambidx, (ATerm) newambs);

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
        if(!tmp) {
          tmp = (char *) SG_Malloc(TYA_TMPCHUNK);
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
          tmp = (char *)SG_Realloc(tmp, tmpsize + TYA_TMPCHUNK);
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
      if(ATisEqual(fun = ATgetAFun((ATermAppl) t), SG_ApplAFun())) {
        args = (ATermList) ATelementAt(ATgetArguments((ATermAppl) t), 1);
        if(ATgetLength(args) > 1) {
          SG_TYAuxBuf(TYA_ADD, '[');
          SG_DotTermYieldAux((ATerm) args);
          SG_TYAuxBuf(TYA_ADD, ']');
        } else {
          SG_DotTermYieldAux((ATerm) args);
        }
      } else if(ATisEqual(fun, SG_AmbAFun())) {
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
