/*
 $Id$
 */

#include <stdlib.h>

#include <aterm2.h>

#include "mem-alloc.h"
#include "forest.h"
#include "parse-table.h"
#include "sglr.h"
#include "sglr-strings.h"

int SG_ProdType_AFun(AFun f);
int SG_ProdType_Tree(tree t);

extern long sg_nr_rejects;

int SG_InjectionFilterSucceeded(int mode)
{
  static int nr_ambiguities = 0;

  switch(mode) {
    case SG_NR_ZERO:
      return nr_ambiguities = 0;
    case SG_NR_INC:
      return nr_ambiguities++;
    case SG_NR_DEC:
      return nr_ambiguities--;
    case SG_NR_ASK:
    default:
      return nr_ambiguities;
  }
}

int SG_MultiSetFilterSucceeded(int mode)
{
  static int nr_ambiguities = 0;

  switch(mode) {
    case SG_NR_ZERO:
      return nr_ambiguities = 0;
    case SG_NR_INC:
      return nr_ambiguities++;
    case SG_NR_DEC:
      return nr_ambiguities--;
    case SG_NR_ASK:
    default:
      return nr_ambiguities;
  }
}

int SG_InjectionCountCalls(int mode)
{
  static int nr_ambiguities = 0;

  switch(mode) {
    case SG_NR_ZERO:
      return nr_ambiguities = 0;
    case SG_NR_INC:
      return nr_ambiguities++;
    case SG_NR_DEC:
      return nr_ambiguities--;
    case SG_NR_ASK:
    default:
      return nr_ambiguities;
  }
}

int SG_MultiSetGtrCalls(int mode)
{
  static int nr_ambiguities = 0;

  switch(mode) {
    case SG_NR_ZERO:
      return nr_ambiguities = 0;
    case SG_NR_INC:
      return nr_ambiguities++;
    case SG_NR_DEC:
      return nr_ambiguities--;
    case SG_NR_ASK:
    default:
      return nr_ambiguities;
  }
}

int SG_AmbCalls(int mode)
{
  static int nr_ambiguities = 0;

  switch(mode) {
    case SG_NR_ZERO:
      return nr_ambiguities = 0;
    case SG_NR_INC:
      return nr_ambiguities++;
    case SG_NR_DEC:
      return nr_ambiguities--;
    case SG_NR_ASK:
    default:
      return nr_ambiguities;
  }
}

int SG_MaxNrAmb(int mode)
{
  static int nr_ambiguities = 0;

  switch(mode) {
    case SG_NR_ZERO:
      return nr_ambiguities = 0;
    case SG_NR_INC:
      return nr_ambiguities++;
    case SG_NR_DEC:
      return nr_ambiguities--;
    case SG_NR_ASK:
    default:
      return nr_ambiguities;
  }
}

int SGnrAmb(int mode)
{
  static int nr_ambiguities = 0;

  switch(mode) {
    case SG_NR_ZERO:
      return nr_ambiguities = 0;
    case SG_NR_INC:
      return ++nr_ambiguities;
    case SG_NR_DEC:
      return --nr_ambiguities;
    case SG_NR_ASK:
    default:
      return nr_ambiguities;
  }
}


ATbool SG_StartInjection(parse_table *pt, label l)
{
  return ATmatch((ATerm) SG_LookupProduction(pt, l),
                 "prod([cf(opt(layout)),cf(sort(<str>)),cf(opt(layout))],"
                 "sort(\"<START>\"),no-attrs)",
                 NULL, NULL, NULL);
}


static ATerm sg_posinfo_label = NULL;
static ATerm sg_injections_label = NULL;

ATerm SG_GetPosInfoLabel(forest t)
{
  if(!SG_POSINFO)
    return NULL;

  if(!sg_posinfo_label) {
    sg_posinfo_label = ATmake("<str>", SG_POSITION_ATTR);
  }
  return ATgetAnnotation((ATerm) t, sg_posinfo_label);
}

forest SG_SetPosInfoLabel(forest t, ATerm pi)
{
  if(!SG_POSINFO)
    return t;

  if(!sg_posinfo_label) {
    sg_posinfo_label = ATmake("<str>", SG_POSITION_ATTR);
  }
  return (forest) ATsetAnnotation((ATerm) t, sg_posinfo_label, pi);
}

ATermInt SG_GetInjectionsLabel(forest t)
{
  if(!sg_injections_label) {
    sg_injections_label = ATmake("<str>", SG_INJECTIONS_ATTR);
  }
  return (ATermInt) ATgetAnnotation((ATerm) t, sg_injections_label);
}

int SG_GetInjections(forest t)
{
  ATermInt cnt = SG_GetInjectionsLabel(t);

  return cnt ? ATgetInt(cnt) : 0;
}

forest SG_SetInjectionsLabel(forest t, ATermInt cnt)
{
  if(!sg_injections_label) {
    sg_injections_label = ATmake("<str>", SG_INJECTIONS_ATTR);
  }
  return (forest) ATsetAnnotation((ATerm) t, sg_injections_label, (ATerm) cnt);
}

/*  The function |SG_Apply| is defined directly in terms of ATerm functions.  */

tree SG_Apply(parse_table *pt, label l, ATermList ts, int attr, ATerm pi)
{
  tree t;
  AFun fun = (AFun) NULL;
#ifndef NO_EAGERNESS
  int       injections;
#endif

#ifdef KEEPINJECTCOUNT
  ATermList args;
  ATerm     arg;
  ATermInt  annot;
#endif

  IF_STATISTICS(if(attr == SG_PT_REJECT) sg_nr_rejects++;);

  if(!SG_NEED_TOP)
    return (tree) ATempty;

#ifdef KEEPINJECTCOUNT
  injections = SG_ProdIsInjection(pt, l) ? 1 : 0;
  /*  Compute sum of argument injection counts  */
  for(args = ts; !ATisEmpty(args); args = ATgetNext(args)) {
    arg = ATgetFirst(args);
    if((annot = SG_GetInjectionsLabel((forest) arg)))
      injections += ATgetInt(annot);
  }
#endif

#ifndef NO_EAGERNESS
  /*  Regular injection's attributes may get overridden... */
  if(attr == SG_PT_REGULAR && ts && !ATisEmpty(ts)) {
#ifndef KEEPINJECTCOUNT
    injections = SG_ProdIsInjection(pt, l) ? 1 : 0;
#endif
    if(injections) {
      int  nattr;

      nattr = SG_ProdType_AFun(ATgetAFun(ATgetFirst(ts)));
      attr = (nattr >= 0) ? nattr : attr;
    }
  }
#endif  /*  EAGERNESS  */

  switch(attr)
  {
    case SG_PT_REGULAR:
      fun = SG_Regular_AFun;
      break;
    case SG_PT_REJECT:
      fun = SG_Reject_AFun;
      break;
#ifndef NO_EAGERNESS
    case SG_PT_EAGER:
      fun = SG_Eager_AFun;
      break;
    case SG_PT_UNEAGER:
      fun = SG_Uneager_AFun;
      break;
#endif
  }
  t = (tree) ATmakeAppl2(fun,
                         (ATerm) ATmakeAppl1(SG_Aprod_AFun,
                                             (ATerm) SG_GetATint(l, 0)),
                         (ATerm) ts);

#ifdef KEEPINJECTCOUNT
  if(injections)
    t = SG_SetInjectionsLabel((forest) t, SG_GetATint(injections,0));
#endif

  if(!SG_POSINFO || !pi)
    return t;

  return (tree) SG_SetPosInfoLabel((forest) t, pi);
}


/*  Managing Cyclic Syntax...  */

ATermList Cycle = NULL;

ATbool SG_TermIsCyclic(forest t)
{
  ATermList ambs;
  AFun      fun;

  if(Cycle) {
    /*  Cycle has been detected, done  */
    return ATtrue;
  }

  if(SG_IS_MARKED(t)) {
    /*  Cycle detected  */
    Cycle = ATempty;
    return ATtrue;
  }

  SG_MARK(t);
  switch(ATgetType(t)) {
    case AT_APPL:
      if(ATisEqual((fun = ATgetAFun(t)), SG_Amb_AFun)) {
        SG_TermIsCyclic((forest) ATgetArgument((ATermAppl) t, 0));
        break;
      }
      if(ATisEqual(fun, SG_Aprod_AFun)) {
        break;
      }
      /*  Ambiguity cluster?  */
      if(ATisEmpty(ambs = (ATermList) SG_AmbTable(SG_AMBTBL_GET,
                                                  (ATerm) t, NULL))) {
        /*  No ambiguity  */
        SG_TermIsCyclic((forest) ATgetArgument((ATermAppl) t, 1));
      } else {
        /*  Encountered an ambiguity cluster  */
        if(ATindexOf(ambs, (ATerm) t, 0) < 0) {  /*  t not in cluster  */
          for(; !ATisEmpty(ambs); ambs = ATgetNext(ambs)) {
            SG_TermIsCyclic((forest) ATgetFirst(ambs));
          }
        } else {                                 /*  t in cluster  */
          ATerm idx;
          ATermList tmp_ambs;

          /*  First check whether or not t itself is cyclic...  */
          SG_TermIsCyclic((forest) ATgetArgument((ATermAppl) t, 1));

          /*  If not, check rest of amb cluster, _disregarding_ t  */
          idx = SG_AmbTable(SG_AMBTBL_LOOKUP_INDEX, (ATerm) t, NULL);
          tmp_ambs = ATremoveAll(ambs, (ATerm) t);
          if(!ATisEmpty(tmp_ambs)) {
            /*  remove t from ambiguity cluster while checking it  */
            SG_AmbTable(SG_AMBTBL_UPDATE_CLUSTER, idx, (ATerm) tmp_ambs);
            for(; !ATisEmpty(tmp_ambs); tmp_ambs = ATgetNext(tmp_ambs)) {
              SG_TermIsCyclic((forest) ATgetFirst(tmp_ambs));
            }
            /*  restore original ambiguity cluster  */
            SG_AmbTable(SG_AMBTBL_UPDATE_CLUSTER, idx, (ATerm) ambs);
          }
        }

      }
      break;
    case AT_LIST:
      if(!ATisEmpty((ATermList) t)) {
        SG_TermIsCyclic((forest) ATgetFirst((ATermList) t));
        SG_TermIsCyclic((forest) ATgetNext((ATermList) t));
      }
      break;
    default:
      break;
  }

  /*  Out of recursion here: restore term state  */
  SG_UNMARK(t);

  /*  Remember labels of productions in cycle */
  if(Cycle && ATgetType(t) == AT_APPL) {
    if(ATisEqual(ATgetAFun(ATgetArgument(t, 0)), SG_Aprod_AFun)) {
      Cycle = ATinsert(Cycle,
                      (ATerm) SG_GetATint(SG_GetApplProdLabel((tree) t), 0));
    }
  }
  return Cycle && !ATisEmpty(Cycle);
}

ATbool SG_CycleEncountered(int Mode)
{
  static ATbool CycleEncountered = ATfalse;

  switch(Mode) {
    case SG_CYCLE_ENCOUNTERED:
      CycleEncountered = ATtrue;
      break;
    case SG_CYCLE_RESET:
      if(CycleEncountered) {
        CycleEncountered = ATfalse;
        return ATtrue;
      }
      break;
  }
  return CycleEncountered;
}

ATermList SG_CyclicTerm(forest t)
{
  Cycle = NULL;

  if(!SG_TermIsCyclic(t))
    return ATempty;

  if(Cycle)
    return ATreverse(Cycle);

  return ATempty;
}

forest SG_ExpandApplNode(parse_table *pt, forest t, ATbool recurse,
                         ATbool doamb)
{
  forest    res;
  ATermList ambs, trms;
  AFun      fun;
  ATermList args;
  ATerm     pos_info;

  if(ATisEmpty((ATermList) t))
    return t;

  fun      = ATgetAFun(t);
  args     = ATgetArguments((ATermAppl) t);
  pos_info = SG_GetPosInfoLabel(t);

  /*  A small sanity check  */
  if(fun == SG_Reject_AFun) {
    IF_DEBUG(ATfprintf(SGlog(), "Reject seeped through:\n\t%t\n",
                       SG_LookupProduction(pt,SG_GetRejectProdLabel((tree) t))))
    return NULL;
  }

  /*  Expand aprod  */
  if(ATisEqual(fun, SG_Aprod_AFun)) {
    res = (forest) SG_LookupProduction(pt, SG_GetProdLabel((tree) t));
    return res;
  }

  /*  Expand appl(prod())-argument list  */
  if(fun != SG_Regular_AFun
#ifndef NO_EAGERNESS
     && fun != SG_Eager_AFun &&  fun != SG_Uneager_AFun
#endif
     ) {
    if(!(res = SG_YieldPT(pt, (forest) args)))
      return NULL;

    t = (forest) ATmakeApplList(fun, (ATermList) res);
    return pos_info ? SG_SetPosInfoLabel(t, pos_info) : t;
  }

  /*  Expand {appl|eager|avoid}(prod())s, handling ambiguity resolution  */
  /*  Are we encountering an ambiguity cluster?  */
  if(!doamb
     /*
      Are we even interested?  If not, we were invoked
      to expand terms that are part of an ambiguity
      cluster, for which the ambiguity-lookup would
      simply recurse infinitely
      */
     || ATisEmpty(ambs = (ATermList) SG_AmbTable(SG_AMBTBL_GET,
                                                 (ATerm) t, NULL))) {
    /*  Is this one mapped to an ambiguity cluster?  */

    /*  No ambiguity, or we're doing one that's part of an ambiguity cluster */
    /*  First argument is an `aprod(X'), to be expanded  */
    t = (forest) ATgetFirst(args);
    if(!(t = SG_ExpandApplNode(pt, t, ATfalse, ATtrue))) {
      return NULL;
    }
    if(recurse) {
      if(!(res = SG_YieldPT(pt, (forest) ATelementAt(args, 1)))) {
        return NULL;
      }
      res = (forest) ATmakeAppl2(SG_Appl_AFun, (ATerm) t, (ATerm) res);
    } else {
      res = (forest) ATmakeAppl2(SG_Appl_AFun, (ATerm) t, ATelementAt(args, 1));
    }
  } else {
    ATbool RemovedSome = ATfalse;

    /*  Encountered an ambiguity cluster; resolve it */
    SG_MaxNrAmb(SG_NR_DEC);

    /*
     Expand all terms in this ambiguity cluster; note that all these
     terms (of course) are mapped onto the ambiguity cluster, making
     some extra caution to prevent an infinite recursion necessary
     */
    for(trms=ATempty; !ATisEmpty(ambs); ambs=ATgetNext(ambs)) {
      if((res = SG_ExpandApplNode(pt, (forest) ATgetFirst(ambs),
                                  recurse, ATfalse))) {
        trms = ATinsert(trms, (ATerm) res);
      } else IF_DEBUG(
                      RemovedSome = ATtrue;
                      fprintf(SGlog(), "Removing term from ambiguity cluster\n");
                      )
    }
      if(ATisEmpty(trms))
        return NULL;
      if (ATgetLength(trms) == 1)
        trms = ATreverse(trms);

      if (ATgetLength(trms) == 1) {
        /*  Only one left: ambiguity resolved  */
        IF_DEBUG(if(RemovedSome) fprintf(SGlog(), "Resolved entire ambiguity\n"))
        res = (forest) ATgetFirst(trms);
      } else {
        /*  Multiple terms left: this is truly an ambiguous node  */
        SGnrAmb(SG_NR_INC);
        res = (forest) ATmakeAppl1(SG_Amb_AFun, (ATerm) trms);
      }
  }

  if(pos_info)
    res = SG_SetPosInfoLabel(res, pos_info);

  return res;
}

forest SG_YieldPT(parse_table *pt, forest t)
{
  forest    elt, res;
  ATermList args, l;

  if(!t)
    return NULL;

  switch(ATgetType(t)) {
    case AT_APPL:
      res = SG_ExpandApplNode(pt, t, ATtrue, ATtrue);
      return res;
    case AT_LIST:
      if(ATisEmpty((ATermList) t))
        return (forest) ATempty;
      for(l = ATempty, args = (ATermList) t;
          !ATisEmpty(args); args = ATgetNext(args)) {
        elt = (forest) ATgetFirst(args);
        if(!(res = SG_YieldPT(pt, elt))) {
          return NULL;
        }
        l = ATinsert(l, (ATerm) res);
      }
        return (forest) ATreverse(l);
    case AT_INT:
    case AT_REAL:
    case AT_PLACEHOLDER:
    case AT_BLOB:
    default:
      return t;
  }
}

/*
 Ambiguity Tables provide a mapping from terms to sets of terms,
 reflecting the ambiguity relation.  Note that terms can be
 `prioritized out' or rejected, so that the mapping may or may not
 yield a set containing the key term.

 The implementation consists of a two-level mapping, as follows:

 * a mapping from terms to indexes (of ambiguity clusters)
 * a mapping from indexes to sets of terms (the ambiguity cluster)

 Maintenance is relatively simple: for new ambiguity clusters, simply
 create.  Updates to existing ambiguity clusters can be performed
 simply by looking up the index from one of the terms that share the
 ambiguity, and update the ambiguity cluster that is found as desired.
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

label SG_GetProdLabel(tree aprod)
{
  return ATgetInt((ATermInt) ATgetArgument(aprod, 0));
}

label SG_GetApplProdLabel(tree appl)
{
  return SG_GetProdLabel((tree) ATgetArgument(appl, 0));
}

label SG_GetRejectProdLabel(tree appl)
{
  return SG_GetProdLabel((tree) ATgetArgument(appl, 0));
}

/*
 SG_GtrPriority(l0, l1) returns true iff priority(l0) > priority(l0)
 */

ATbool SG_GtrPriority(parse_table *pt, ATermInt lt0, ATermInt lt1)
{
  ATermList prios;

  if((prios = SG_LookupPriority(pt, ATgetInt(lt0)))
     && (ATindexOf(prios, (ATerm) lt1, 0) != -1))
    return ATtrue;
  return ATfalse;
}


int SG_ProdType_Label(parse_table *pt, ATermInt prodlbl)
{
  ATerm        attr;
  ATermList    attrs;
  static ATerm reject_attr = NULL;
#ifndef NO_EAGERNESS
  static ATerm eager_attr = NULL, avoid_attr = NULL;
#endif

  attr = ATgetArgument(SG_LookupProduction(pt, ATgetInt(prodlbl)), 2);
  if(!ATmatch(attr, "attrs([<list>])", &attrs))
    return SG_PT_REGULAR;

  if(!reject_attr)
    reject_attr = ATmake("atr(<str>)", SG_REJECT_ATTR);
#ifndef NO_EAGERNESS
  if(!eager_attr)
    eager_attr = ATmake("atr(<str>)", SG_PREFER_ATTR);
  if(!avoid_attr)
    avoid_attr = ATmake("atr(<str>)", SG_AVOID_ATTR);
#endif

  for(; !ATisEmpty(attrs); attrs = ATgetNext(attrs)) {
    attr = ATgetFirst(attrs);
    if(ATisEqual(attr, reject_attr)) {
      return SG_PT_REJECT;
    }
#ifndef NO_EAGERNESS
    if(ATisEqual(attr, eager_attr)) {
      return SG_PT_EAGER;
    }
    if(ATisEqual(attr, avoid_attr)) {
      return SG_PT_UNEAGER;
    }
#endif
  }

  return SG_PT_REGULAR;
}

int SG_ProdType_AFun(AFun f)
{
  if(f == SG_Regular_AFun)
    return SG_PT_REGULAR;
  if(f == SG_Reject_AFun)
    return SG_PT_REJECT;
#ifndef NO_EAGERNESS
  if(f == SG_Eager_AFun)
    return SG_PT_EAGER;
  if(f == SG_Uneager_AFun)
    return SG_PT_UNEAGER;
#endif
  /*  None of the above...  */
  return -1;
}

int SG_ProdType_Tree(tree t)
{
  int  TreeType = 0;

  TreeType = SG_ProdType_AFun(ATgetAFun(t));
  if(TreeType < 0)
    ATerror("TreeType exception for %t\n", t);
  return TreeType;
}


/*
 SG_MoreEager(t0, t1) returns true iff either
	- t0 is eager and t1 is regular or avoid
	- t0 is regular and t1 is avoid
 */

#ifndef NO_EAGERNESS
ATbool SG_MoreEager(int prodtype0, int prodtype1)
{
  if(prodtype0 == prodtype1
     || prodtype0 == SG_PT_REJECT
     || prodtype0 == SG_PT_UNEAGER
     || prodtype1 == SG_PT_EAGER)
    return ATfalse;

  /*
   pt1 != EAGER, and pt0 either EAGER or REGULAR.
   if pt0 == EAGER,   pt0 outranks pt1 (!=EAGER).
   if pt0 == REGULAR, pt0 outranks pt1 (!=EAGER, but also !=pt0, leaving
                                        only UNEAGER and REJECT for pt1)
   */
  return ATtrue;
}


ATbool SG_EagerPriority_Tree(tree t0, tree t1)
{
  return SG_MoreEager(SG_ProdType_Tree(t0), SG_ProdType_Tree(t1));
}

ATbool SG_EagerPriority(parse_table *pt, ATermInt lt0, ATermInt lt1)
{
  return SG_MoreEager(SG_ProdType_Label(pt, lt0), SG_ProdType_Label(pt, lt1));
}
#endif  /*  EAGERNESS  */

multiset SG_NewMultiSet(int size)
{
  return ATtableCreate(size, 75);
}

multiset SG_PutMultiSetEntry(multiset ms, ATermInt pl, ATermInt cnt)
{
  ATtablePut(ms, (ATerm) pl, (ATerm) cnt);
  return ms;
}

int SG_GetMultiSetEntry(multiset ms, ATermInt pl)
{
  ATermInt val = NULL;

  val = (ATermInt) ATtableGet(ms, (ATerm) pl);

  return val ? ATgetInt(val) : 0;
}

ATermList SG_GetMultiSetKeys(multiset ms)
{
  return ATtableKeys(ms);
}

multiset SG_GetMultiSet(tree t, multiset ms)
{
  label    l;
  int      count;

  switch(ATgetType(t)) {
    case AT_APPL:
      l = SG_GetApplProdLabel(t);
      count = 1 + SG_GetMultiSetEntry(ms, SG_GetATint(l, 0));
      ms = SG_PutMultiSetEntry(ms, SG_GetATint(l,0), SG_GetATint(count, 0));
      ms = SG_GetMultiSet((tree) ATgetArgument((ATermAppl) t, 1), ms);
      break;
    case AT_LIST:
      if(ATisEmpty((ATermList) t))
        break;
      for(; !ATisEmpty((ATermList) t); t = (tree) ATgetNext((ATermList) t))
        ms = SG_GetMultiSet((tree) ATgetFirst((ATermList) t), ms);
        break;
    case AT_INT:
    case AT_REAL:
    case AT_PLACEHOLDER:
    case AT_BLOB:
    default:
      break;
  }
  return ms;
}


ATbool SG_MultiSetGtr(parse_table *pt, multiset msM, ATermList kM,
                      multiset msN, ATermList kN)
{
  ATermInt  x, y;
  ATermList M, N;
  ATbool    somethingtocheck;

  IF_STATISTICS(SG_MultiSetGtrCalls(SG_NR_INC));

  /*  Initialize key lists if we have to  */
  if(!kM)
    kM = SG_GetMultiSetKeys (msM);
  if(!kN)
    kN = SG_GetMultiSetKeys (msN);

  /*  multi-prio is irreflexive  */
  /*
   if(SG_MultiSetEqual(multiset1, multiset2, NULL, NULL))
     return ATfalse;
   */


  /*  For all y in M such thatN(y) < M(y) ...  */

  for(M = kM, somethingtocheck = ATfalse; !ATisEmpty(M); M = ATgetNext(M)) {
    ATbool    foundone;

    y = (ATermInt) ATgetFirst(M);

    if(SG_GetMultiSetEntry(msN, y) < SG_GetMultiSetEntry(msM, y)) {
      somethingtocheck = ATtrue;
      foundone         = ATfalse;

      /*  ... there exists an x in N such that ( y >> x and M(x) < N(x) )  */

      for(N = kN; !(foundone||ATisEmpty(N)); N = ATgetNext(N)) {
        x = (ATermInt) ATgetFirst(N);

        foundone =
          (  (SG_GetMultiSetEntry(msM, x) < SG_GetMultiSetEntry(msN, x))
             && (  SG_GtrPriority(pt, y, x)
#ifndef NO_EAGERNESS
                   || SG_EagerPriority(pt, y, x)
#endif
                   )
             );
      }
      /*  No relation if we didn't find a satisfactory "witness" for y  */
      if(!foundone) {
        return ATfalse;
      }
    }
  }

  /*
   For all candidates,  a suitable "witness" has been found if we get
   here.  However, there may have been no candidates in the first
   place: we trivially arrive here, without having found a single
   witness for the multiset priority relation.  This constitutes
   a false positive, if we don't prevent it: we also require that
   there was something to check in the first place.  If not, there's
   no relation.
   */
  return somethingtocheck;
}


ATbool ATsubTable(ATermTable t1, ATermTable t2, ATermList k1)
{
  ATerm     key;
  ATermList keys;

  if(!t2)
    return ATfalse;
  if(!t1)
    return ATtrue;

  /*  Initialise list of keys unless already available  */
  if(!k1)
    k1 = ATtableKeys(t1);

  /*  Now check if all the keys in t1 exist in t2, with equal values  */
  for(keys = k1; keys && !ATisEmpty(keys);
      keys=ATgetNext(keys)) {
    key = ATgetFirst(keys);
    if(!ATisEqual(ATtableGet(t1, key), ATtableGet(t2, key)))
      return ATfalse;
  }
  return ATtrue;
}

ATbool ATtableIsEqual(ATermTable t1, ATermTable t2, ATermList k1, ATermList k2)
{
  if(t1 == t2)
    return ATtrue;

  if(!t1 || !t2)
    return ATfalse;

  if(!k1)
    k1 = ATtableKeys(t1);
  if(!k2)
    k2 = ATtableKeys(t2);

  if(!ATisEqual(k1, k2))
    return ATfalse;

  if(!ATsubTable(t1, t2, k1))
    return ATfalse;

  if(!ATsubTable(t2, t1, k2))
    return ATfalse;

  return ATtrue;
}

ATbool SG_MultiSetEqual(multiset M1, multiset M2, ATermList k1, ATermList k2)
{
  return ATtableIsEqual(M1, M2, k1, k2);
}

int SG_CountInjections(parse_table *pt, multiset ms, ATermList keys)
{
  int       ret = 0;

  ATermInt  key;

  if(!keys)
    keys = SG_GetMultiSetKeys (ms);

  for(; keys && !ATisEmpty(keys); keys=ATgetNext(keys)) {
    key = (ATermInt) ATgetFirst(keys);
    if(SG_ProdIsInjection(pt, ATgetInt((ATermInt) key))) {
      ret += ATgetInt((ATermInt) ATtableGet(ms, (ATerm) key));
    }
  }

  IF_STATISTICS(SG_InjectionCountCalls(SG_NR_INC));

  return ret;
}

/*
 SG_Filter -- a generic hook to add disambiguating `filters'

 Arguments:  the current parse table
 two terms
 Returns:    the preferred term of the two, or NULL if there is no
 filter that prefers either one of them
 */

tree SG_Filter(parse_table *pt, tree t0, tree t1, multiset m0, ATermList k0)
{
  ATermInt   l0, l1;
  multiset   m1;
  tree       max = NULL;
  ATermList  k1;
  ATbool     m0made = ATfalse;

  /*  Always apply direct priority filtering first  */
  l0 = SG_GetATint(SG_GetApplProdLabel(t0), 0);
  l1 = SG_GetATint(SG_GetApplProdLabel(t1), 0);

  if(SG_GtrPriority(pt, l0, l1)) {
    IF_DEBUG(ATfprintf(SGlog(), "Direct Priority: %t > %t\n", l0, l1))
    return t0;
  }
  if(SG_GtrPriority(pt, l1, l0)) {
    IF_DEBUG(ATfprintf(SGlog(), "Direct Priority: %t < %t\n", l0, l1))
    return t1;
  }

  /*  Next, inspect eager/avoid status  */
#ifndef NO_EAGERNESS
  if(SG_EagerPriority_Tree(t0, t1)) {
    IF_DEBUG(ATfprintf(SGlog(), "(Un)Eagerness Priority: %t > %t\n", l0, l1))
    return t0;
  }
  if(SG_EagerPriority_Tree(t1, t0)) {
    IF_DEBUG(ATfprintf(SGlog(), "(Un)Eagerness Priority: %t < %t\n", l0, l1))
    return t1;
  }
#endif
  /*  Don't even bother filtering any further if filtering is disabled  */
  if(!SG_FILTER)
    return NULL;

  /*  Don't filter START symbols when start symbol subselection is on  */
  if(SG_STARTSYMBOL && SG_StartInjection(pt, ATgetInt(l0)))
    return (tree) NULL;

  /*  No direct priority relation?  Apply multiset ordering.  */
  if(!m0) {
    m0made = ATtrue;
    m0 = SG_GetMultiSet(t0, SG_NewMultiSet(SG_PT_NUMPRODS(pt)));
  }
  m1 = SG_GetMultiSet(t1, SG_NewMultiSet(SG_PT_NUMPRODS(pt)));

  if(!k0)
    k0 = SG_GetMultiSetKeys(m0);
  k1 = SG_GetMultiSetKeys(m1);

  if(!ATisEqual(t0, t1) && !SG_MultiSetEqual(m0, m1, k0, k1)) {
    /*  multi-prio is irreflexive  */
    if(SG_MultiSetGtr(pt, m0, k0, m1, k1)) {
      IF_DEBUG(ATfprintf(SGlog(), "Multiset Priority: %t > %t\n", l0, l1))
      max = t0;
    }
    if(SG_MultiSetGtr(pt, m1, k1, m0, k0)) {
      if(max) {                             /*  shouldn't happen, really  */
        IF_DEBUG(fprintf(SGlog(),
                         "Ignoring symmetric multiset priority relation\n"))
        ATwarning("Ignoring symmetric multiset priority relation\n");
        max = NULL;
      } else {
        IF_DEBUG(ATfprintf(SGlog(), "Multiset Priority: %t < %t\n", l0, l1))
        max = t1;
      }
    }
  }

  /*  No multiset ordering either?  Count injections.  */
  if(max) {
    IF_STATISTICS(SG_MultiSetFilterSucceeded(SG_NR_INC));
  } else {
    int in0, in1;

#ifdef KEEPINJECTCOUNT
    in0 = SG_GetInjections(t0);
    in1 =SG_GetInjections(t1);
#else
    in0 = SG_CountInjections(pt, m0, k0);
    in1 = SG_CountInjections(pt, m1, k1);
#endif
    IF_STATISTICS(
                  if(in0 != in1)
                  SG_InjectionFilterSucceeded(SG_NR_INC)
                  );
    if(in0 > in1) {
      IF_DEBUG(ATfprintf(SGlog(), "Injection Priority: %t < %t (%d > %d)\n",
                         l0, l1, in0, in1))
      max = t1;
    } else if(in0 < in1) {
      IF_DEBUG(ATfprintf(SGlog(), "Injection Priority: %t > %t (%d < %d)\n",
                         l0, l1, in0, in1))
      max = t0;
    }
  }

  if(m0made)
    ATtableDestroy(m0);
  ATtableDestroy(m1);

  return max;
}

ATermList SG_FilterList(parse_table *pt, ATermList old, tree t)
{
  multiset   m = NULL;
  ATermList  k = ATempty, new = ATempty;
  tree       prev, max;
  ATbool     term_filtered_out = ATfalse;

  if(ATisEmpty(old))
    return ATmakeList1((ATerm) t);

  /*  Multiset construction is needed only when really filtering  */
  if(SG_FILTER) {
    m = SG_GetMultiSet(t, SG_NewMultiSet(SG_PT_NUMPRODS(pt)));
    k = SG_GetMultiSetKeys(m);
  }

  /*  Filter term against existing terms in ambiguity cluster  */
  for(; !ATisEmpty(old); old = ATgetNext(old)) {
    prev = (tree) ATgetFirst(old);

    /* Add prev to new, unless new has a higher priority  */
    max = SG_Filter(pt, t, prev, m, k);
    if(!max || (term_filtered_out=ATisEqual(max, prev)))
      new = ATinsert(new, (ATerm) prev);
    if(max) {
      IF_DEBUG(fprintf(SGlog(), "Priority: %d %c %d (old amb)\n",
                       SG_GetApplProdLabel(prev),
                       ATisEqual(max, prev)?'>':'<',
                       SG_GetApplProdLabel(t))
               );
    }
  }
  if(!term_filtered_out)
    new = ATinsert(new, (ATerm) t);

  if(m)
    ATtableDestroy(m);

  return new;
}

/*
 |SG_Amb| maintans the ambiguity table, needed for the mapping from
 terms to ambiguity clusters.  On a new ambiguity, it makes a new
 entry; existing ambiguities get expanded, applying filtering wherever
 applicable.
 */

void SG_Amb(parse_table *pt, tree existing, tree new) {
  ATermList newambs;
  ATerm     ambidx;
  tree      max;

  IF_STATISTICS(SG_AmbCalls(SG_NR_INC));

  if(!SG_NEED_TOP) {
    SG_MaxNrAmb(SG_NR_INC);
    return;
  }

  ambidx = SG_AmbTable(SG_AMBTBL_LOOKUP_INDEX, (ATerm) existing, NULL);
  if(!ambidx || ATisEmpty((ATermList) ambidx)) {
    /* New ambiguity */
    ambidx = (ATerm) ATmakeInt(SG_MaxNrAmb(SG_NR_INC));
    /* Add mapping for existing term also */
    SG_AmbTable(SG_AMBTBL_ADD_INDEX, (ATerm) existing, ambidx);

    /*  Filter the two  */
    if(!(max = SG_Filter(pt, new, existing, NULL, NULL))) {
      /*  max and new are not priority-related */
      newambs = ATmakeList2((ATerm) existing, (ATerm) new);
    } else {
      /*  new and existing are in a priority relation, max is top  */
      newambs = ATmakeList1((ATerm) max);
      if(max) {
        IF_DEBUG(fprintf(SGlog(), "Priority: %d %c %d (new amb)\n",
                         SG_GetApplProdLabel(existing),
                         ATisEqual(max, existing)?'>':'<',
                         SG_GetApplProdLabel(new))
                 );
      }
    }
  } else {
    /* Expand (or update) existing ambiguity */
    ATermList oldambs;

    oldambs = (ATermList) SG_AmbTable(SG_AMBTBL_LOOKUP_CLUSTER, ambidx, NULL);
    if(ATindexOf(oldambs, (ATerm) new, 0) != -1)
      return;  /*  Already present?  Done.  */
    newambs = SG_FilterList(pt, oldambs, new);
  }

  /*   Update ambiguity cluster  */
  SG_AmbTable(SG_AMBTBL_ADD_INDEX, (ATerm) new, ambidx);
  SG_AmbTable(SG_AMBTBL_UPDATE_CLUSTER, ambidx, (ATerm) newambs);

  return;
}
