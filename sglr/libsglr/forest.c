/*

    SGLR - the Scannerless Generalized LR parser.
    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, 
                        The Netherlands.

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
 */

#include <stdlib.h>
#include <assert.h>

#include <aterm2.h>
#include <a2toa1.h>

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

/*  The function |SG_Apply| is defined directly in terms of ATerm functions.  */

tree SG_Apply(parse_table *pt, label l, ATermList ts, int attr, ATerm pi)
{
  tree t;
  AFun fun = (AFun) NULL;


  IF_STATISTICS(if(attr == SG_PT_REJECT) sg_nr_rejects++;);

  if(!SG_NEED_TOP)
    return (tree) ATempty;

  switch(attr)
  {
    case SG_PT_REGULAR:
      fun = SG_Regular_AFun;
      break;
    case SG_PT_REJECT:
      fun = SG_Reject_AFun;
      break;
    case SG_PT_EAGER:
      fun = SG_Eager_AFun;
      break;
    case SG_PT_UNEAGER:
      fun = SG_Uneager_AFun;
      break;
  }
  t = (tree) ATmakeAppl2(fun,
                         (ATerm) ATmakeAppl1(SG_Aprod_AFun,
                                             (ATerm) SG_GetATint(l, 0)),
                         (ATerm) ts);

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

ATermList SG_CyclicTerm(parse_table *pt, forest t)
{
  Cycle = NULL;

  if(!SG_TermIsCyclic(t))
    return ATempty;

  if(Cycle) {
    ATermList cycleprods = ATempty;

    for(; !ATisEmpty(Cycle); Cycle = ATgetNext(Cycle)) {
      cycleprods = ATinsert(cycleprods,
                            (ATerm) SG_LookupProduction(pt,
                              (label) ATgetInt((ATermInt) ATgetFirst(Cycle))));
    }
    return cycleprods;
  }
  return ATempty;
}

void SG_PrintTree(tree t, ATbool inAmbs);
void SG_PrintAmbs(ATermList ambs)
{
  tree amb;

  ATfprintf(SG_log(), "AMB%d(", ATgetLength(ambs));
  for (; !ATisEmpty(ambs); ambs=ATgetNext(ambs)) {
    amb = (tree) ATgetFirst(ambs);
    SG_PrintTree(amb, ATtrue);
    if (!ATisEmpty(ATgetNext(ambs))) {
      ATfprintf(SG_log(), ",\n");
    }
  }
  ATfprintf(SG_log(), ")");
}

void SG_PrintTree(tree t, ATbool inAmbs)
{
  tree elt;
  ATermList args, ambs;
  AFun      fun;
  int       treetype;

  treetype = ATgetType(t);

  /*  AT_LIST  */

  if (treetype == AT_LIST) {
    ATfprintf(SG_log(), "[");
    for (args = (ATermList) t;
        !ATisEmpty(args); args = ATgetNext(args)) {
      elt = (tree) ATgetFirst(args);
      SG_PrintTree(elt, ATfalse);
      if (!ATisEmpty(ATgetNext(args))) {
	ATfprintf(SG_log(), ",");
      }
    }
    ATfprintf(SG_log(), "]");
  } else if (treetype != AT_APPL) {
    ATfprintf(SG_log(), "%t", (ATerm) t);
  } else {
    /*  AT_APPL  */

    fun      = ATgetAFun(t);

    if (!inAmbs) {
      ambs = (ATermList) SG_AmbTable(SG_AMBTBL_GET, (ATerm) t, NULL);
      assert(ambs);
      if (!ATisEmpty(ambs)) {
	SG_PrintAmbs(ambs);
	return;
      }
    }

    ATfprintf(SG_log(), "%y(%t,", fun, ATgetArgument(t, 0));
    SG_PrintTree((tree)ATgetArgument(t, 1), ATfalse);
    ATfprintf(SG_log(), ")");
  }
}

forest     SG_YieldForest(parse_table *pt, forest t,
                          ATbool recurse, ATbool doambs)
{
  forest    elt, res;
  ATermList args, trms, ambs;
  AFun      fun;
  ATerm     pos_info;
  int       treetype;

  if(!t)
    return NULL;

  treetype = ATgetType(t);

  /*  AT_LIST  */

  if(treetype == AT_LIST) {
    for(trms = ATempty, args = (ATermList) t;
        !ATisEmpty(args); args = ATgetNext(args)) {
      elt = (forest) ATgetFirst(args);
      if(!(res = SG_YieldForest(pt, elt, recurse, doambs))) {
        return NULL;
      }
      trms = ATinsert(trms, (ATerm) res);
    }
    return (forest) ATreverse(trms);
  }

  /*  AT_INT, AT_REAL, AT_PLACEHOLDER, AT_BLOB, ...  */

  if(treetype != AT_APPL) {
      return t;
  }

  /*  AT_APPL  */

  fun      = ATgetAFun(t);
  args     = ATgetArguments((ATermAppl) t);
  pos_info = SG_GetPosInfoLabel(t);

  /*  A small sanity check  */
  if (fun == SG_Reject_AFun) {
    IF_DEBUG(ATfprintf(SG_log(), "Reject seeped through:\n\t%t\n",
                       SG_LookupProduction(pt,
                                           SG_GetRejectProdLabel((tree) t))))
    return NULL;
  }

  /*  Expand aprod  */
  if (ATisEqual(fun, SG_Aprod_AFun)) {
    res = (forest) SG_LookupProduction(pt, SG_GetProdLabel((tree) t));
    return res;
  }

  /*
      Expand appl(prod())-argument list, and other possibly partially
      expanded bits (including, possibly, a top-level amb() node)
   */
  if (fun != SG_Regular_AFun
     && fun != SG_Eager_AFun &&  fun != SG_Uneager_AFun
      ) { 
/* node is already converted to AsFix, now proceed to convert the 
 * children to AsFix
 */
    if(!(res = SG_YieldForest(pt, (forest) args, recurse, doambs)))
      return NULL;

    t = (forest) ATmakeApplList(fun, (ATermList) res);
    return pos_info ? SG_SetPosInfoLabel(t, pos_info) : t;
  }

  /*  Expand {regular|eager|avoid}(prod())s, handling ambiguity resolution  */
  /*  Are we encountering an ambiguity cluster?  */
	ambs = (ATermList) SG_AmbTable(SG_AMBTBL_GET, (ATerm) t, NULL);

  /* Are we even interested?  If not, we were invoked to expand
   * terms that are part of an ambiguity cluster, for which the
   * ambiguity-lookup would simply recurse infinitely
   */
	if(!doambs 
		 /*  Is this one mapped to an ambiguity cluster?  */
		 || ATisEmpty(ambs)) {
   
    /*  No ambiguity, or we're doing one that's part of an ambiguity cluster */
    /*  First argument is an `aprod(X'), to be expanded  */

    t = (forest) ATgetFirst(args);
    if(!(t = SG_YieldForest(pt, t, ATfalse, ATtrue))) {
      return NULL;
    }
    if(recurse) {
      if(!(res = SG_YieldForest(pt, (forest) ATelementAt(args, 1),
                                recurse, ATtrue))) {
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
      forest thisamb = (forest) ATgetFirst(ambs);
      if((res = SG_YieldForest(pt, thisamb, recurse, ATfalse))) {
        /*
            After the first one added, the current position counter
            must be reset for every consecutive subtree, or it will be
            incremented in multiplicate for every amb node
         */
        trms = ATinsert(trms, (ATerm) res);
      } else IF_DEBUG(
                      RemovedSome = ATtrue;
                      fprintf(SG_log(), "Removing term from ambiguity cluster\n");
                      );
    }

    if(ATisEmpty(trms))
      return NULL;

    if (ATgetLength(trms) == 1) {
      /*  Only one left: ambiguity resolved  */
      IF_DEBUG(if(RemovedSome) fprintf(SG_log(), "Resolved entire ambiguity\n"))
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

/* ============================================================== */

ATermList  SG_AmbTrakker(forest t, size_t *currpos)
{
  ATermList res, args, trms;
  AFun      fun;
  int       treetype;

  if(!t)
    return NULL;

  treetype = ATgetType(t);

  /*  AT_LIST  */

  if(treetype == AT_LIST) {
    for(trms = ATempty, args = (ATermList) t;
        !ATisEmpty(args); args = ATgetNext(args)) {
      res = SG_AmbTrakker((forest) ATgetFirst(args), currpos);
      if(res && !ATisEmpty((ATermList) res)) {
        trms = ATconcat(trms, res);
      }
    }
    return trms; // ATreverse(trms);
  }

  /*  AT_INT, AT_REAL, AT_PLACEHOLDER, AT_BLOB, ...  */

  if(treetype != AT_APPL) {
    return ATempty;
  }

  /*  AT_APPL  */

  fun  = ATgetAFun(t);
  args = ATgetArguments((ATermAppl) t);

  /*  aprod  */
  if(ATisEqual(fun, SG_Aprod_AFun)) {
    return ATempty;
  }

  if(ATisEqual(fun, SG_Amb_AFun)) {
    ATermList ambs, thisamb = ATempty;
    forest    thistree;
    size_t    old_currpos, new_currpos;

    ambs = (ATermList) ATgetFirst(ATgetArguments(t));

    old_currpos = new_currpos = *currpos;
    for(trms=ATempty; !ATisEmpty(ambs); ambs=ATgetNext(ambs)) {
      *currpos = old_currpos;
      thistree = (forest) ATgetFirst(ambs);
      res = SG_AmbTrakker(thistree, currpos);
        /*
            After the first one added, the current position counter
            must be reset for every consecutive subtree, or it will be
            incremented in multiplicate for every amb node
         */
      if(ATisEmpty(thisamb)) {
         new_currpos = *currpos;
      }
      /*  Add this node to current ambiguity  */
      thisamb = ATinsert(thisamb, AF2ProdToText(ATgetArgument(thistree, 0)));

      /*  Join existing ambiguities from subtrees  */
      if(res && !ATisEmpty((ATermList) res)) {
        trms = ATconcat(trms, res);
      }
    }
    *currpos = new_currpos;
    thisamb = (ATermList) ATmakeAppl2(SG_Amb_Node_AFun,
                            (ATerm) ATmakeAppl1(SG_Position_AFun,
                                                (ATerm) ATmakeInt(old_currpos)),
                            (ATerm) ATmakeAppl1(SG_Productions_AFun,
                                                (ATerm) ATreverse(thisamb)));

    res = ATinsert(trms, (ATerm) thisamb);

    return res;
  }
  /*
      Handle appl(prod())-argument list, and other possibly partially
      expanded bits (including, possibly, amb() nodes)
   */

  /*  If it's an end node, increment the current position counter  */
  if(ATisEqual(fun, SG_Appl_AFun)) {
    ATerm cc = ATelementAt(args, 1);
    if(ATgetType(cc) == AT_LIST && ATgetLength(cc) == 1
    && ATgetType(ATgetFirst((ATermList) cc)) == AT_INT) {
      (*currpos)++;
    }
  }

  res = SG_AmbTrakker((forest) args, currpos);
  if(!res || ATisEmpty((ATermList) res)) {
    return ATempty;
  }

  return res;
}

ATerm SG_AmbTracker(forest t)
{
  size_t    currpos = 0;
  ATermList amblist = ATempty;

  amblist = SG_AmbTrakker(t, &currpos);

  if(ATisEmpty(amblist)) {
    return NULL;
  }

  return (ATerm) ATmakeAppl2(SG_Amb_Error_AFun,
                             (ATerm) ATmakeInt(ATgetLength(amblist)),
                             (ATerm) amblist);
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

  if((prios = SG_LookupGtrPriority(pt, ATgetInt(lt0)))
     && (ATindexOf(prios, (ATerm) lt1, 0) != -1))
    return ATtrue;
  return ATfalse;
}

int SG_ProdType_Label(parse_table *pt, ATermInt prodlbl)
{
  ATerm        attr;
  ATermList    attrs;
  static ATerm reject_attr = NULL;
  static ATerm eager_attr = NULL, avoid_attr = NULL;

  attr = ATgetArgument(SG_LookupProduction(pt, ATgetInt(prodlbl)), 2);
  if(!ATmatch(attr, "attrs([<list>])", &attrs))
    return SG_PT_REGULAR;

  if(!reject_attr)
    reject_attr = ATmake("atr(<str>)", SG_REJECT_ATTR);
  if(!eager_attr)
    eager_attr = ATmake("atr(<str>)", SG_PREFER_ATTR);
  if(!avoid_attr)
    avoid_attr = ATmake("atr(<str>)", SG_AVOID_ATTR);

  for(; !ATisEmpty(attrs); attrs = ATgetNext(attrs)) {
    attr = ATgetFirst(attrs);
    if(ATisEqual(attr, reject_attr)) {
      return SG_PT_REJECT;
    }

    if(ATisEqual(attr, eager_attr)) {
      return SG_PT_EAGER;
    }
    if(ATisEqual(attr, avoid_attr)) {
      return SG_PT_UNEAGER;
    }

  }

  return SG_PT_REGULAR;
}

int SG_ProdType_AFun(AFun f)
{
  if(f == SG_Regular_AFun)
    return SG_PT_REGULAR;
  if(f == SG_Reject_AFun)
    return SG_PT_REJECT;
  if(f == SG_Eager_AFun)
    return SG_PT_EAGER;
  if(f == SG_Uneager_AFun)
    return SG_PT_UNEAGER;

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
  /*  Don't even bother comparing if there are no preferences anyway  */
  if(!SG_PT_HAS_PREFERENCES(pt))
    return ATfalse;

  return SG_MoreEager(SG_ProdType_Label(pt, lt0), SG_ProdType_Label(pt, lt1));
}

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

multiset SG_GetMultiSet(register tree t, register multiset ms);
multiset SG_GetMultiSetInAmbCluster(ATermList ambs, register multiset ms)
{
	if(ATgetLength(ambs) > 1) {
		/* This is a real ambiguity. We don't know how to
		 * calculate a multiset over ambiguity clusters, so 
		 * bail out!
		 */
		ms = NULL;
	} else {
		ms = SG_GetMultiSet((tree) ATgetFirst(ambs), ms);
  }

  return ms;
}

/* For each production in the tree the number of occurrences is
 * calculated.
 */
multiset SG_GetMultiSetRecursive(register tree t, register multiset ms)
{
  label    l;
  int      count;
  ATermList ambs;

  switch (ATgetType(t)) {
    case AT_APPL:
      ambs = (ATermList) SG_AmbTable(SG_AMBTBL_GET, (ATerm) t, NULL);
      if (ATisEmpty(ambs)) { 
        l = SG_GetApplProdLabel(t);
        count = 1 + SG_GetMultiSetEntry(ms, SG_GetATint(l, 0));
        ms = SG_PutMultiSetEntry(ms, SG_GetATint(l,0), SG_GetATint(count, 0));
        ms = SG_GetMultiSetRecursive((tree) ATgetArgument((ATermAppl) t, 1), ms);
      }
      else {
        ms = SG_GetMultiSetInAmbCluster(ambs, ms);
      }
      break;
    case AT_LIST:
      if (ATisEmpty((ATermList) t)) {
        break;
      }
      for (; !ATisEmpty((ATermList) t); t = (tree) ATgetNext((ATermList) t)) {
        ms = SG_GetMultiSetRecursive((tree) ATgetFirst((ATermList) t), ms);
				if(!ms) {
					/* if one of the elements contains an ambiguity, we can stop now */
					break;
				}
      }
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

multiset SG_GetMultiSet(register tree t, register multiset ms)
{
  label    l;
  int      count;

  switch (ATgetType(t)) {
    case AT_APPL:
      l = SG_GetApplProdLabel(t);
      count = 1 + SG_GetMultiSetEntry(ms, SG_GetATint(l, 0));
      ms = SG_PutMultiSetEntry(ms, SG_GetATint(l,0), SG_GetATint(count, 0));
      ms = SG_GetMultiSetRecursive((tree) ATgetArgument((ATermAppl) t, 1), ms);
      break;
    case AT_LIST:
      if (ATisEmpty((ATermList) t)) {
        break;
      }
      for (; !ATisEmpty((ATermList) t); t = (tree) ATgetNext((ATermList) t)) {
        ms = SG_GetMultiSetRecursive((tree) ATgetFirst((ATermList) t), ms);
				if(!ms) {
					/* if one of the elements contains an ambiguity, we can stop now */
					break;
				}
      }
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
  register ATermList M, N;
  register ATermInt x, y;
  ATbool somethingtocheck;

  IF_STATISTICS(SG_MultiSetGtrCalls(SG_NR_INC));

  /*  Initialize key lists if we have to  */
  if (!kM) {
    kM = SG_GetMultiSetKeys (msM);
  }
  if (!kN) {
    kN = SG_GetMultiSetKeys (msN);
	}

	if(!kM || !kN) {
		/* one of the multisets is not calculated, probably because
		 * an amb node was encountered
		 */
		return ATfalse;
	}

  /*  multi-prio is irreflexive  */
  /*
   if (SG_MultiSetEqual(multiset1, multiset2, NULL, NULL)) {
     return ATfalse;
   }
   */


  /*  For all y in M such thatN(y) < M(y) ...  */

  for (M = kM, somethingtocheck = ATfalse; !ATisEmpty(M); M = ATgetNext(M)) {
    ATbool    foundone;

    y = (ATermInt) ATgetFirst(M);

    if (SG_GetMultiSetEntry(msN, y) < SG_GetMultiSetEntry(msM, y)) {
      somethingtocheck = ATtrue;
      foundone         = ATfalse;

      /*  ... there exists an x in N such that ( y >> x and M(x) < N(x) )  */

      for (N = kN; !(foundone||ATisEmpty(N)); N = ATgetNext(N)) {
        x = (ATermInt) ATgetFirst(N);

        foundone =
          (  (SG_GetMultiSetEntry(msM, x) < SG_GetMultiSetEntry(msN, x))
             && (  SG_GtrPriority(pt, y, x)
                   || SG_EagerPriority(pt, y, x)

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
  ATerm key;
  register ATermList keys;

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

ATbool SG_HasPreferredProds(tree t);
/* Looking depth-first for a prefer attribute in an ambiguity
 * cluster. We assume that an ambiguity cluster only contains appls.
 */
ATbool SG_HasPreferredProdsInAmbCluster(ATermList ambs)
{
  for (; !ATisEmpty(ambs); ambs = ATgetNext(ambs)) {
    tree thisamb = (tree) ATgetFirst(ambs); 
    switch (ATgetType(thisamb)) {
      case AT_APPL:
        {
          AFun fun;

          fun = ATgetAFun(thisamb);
          if (ATisEqual(fun, SG_Eager_AFun)) {
            return ATtrue;
          }
          if (SG_HasPreferredProds((forest) ATgetArgument((ATermAppl) thisamb,
                                                          1))) {
            return ATtrue;
          }
        }
     default: 
       {
         IF_DEBUG(fprintf(SG_log(), 
                          "A non appl node found in an ambiguity cluster\n"));
         return ATfalse;
       }
    }
  }
  return ATfalse;
}

ATbool SG_HasPreferredProds(tree t)
{
  switch (ATgetType(t)) {
    case AT_APPL:
      {
        AFun fun;
        ATermList ambs;

        ambs = (ATermList) SG_AmbTable(SG_AMBTBL_GET, (ATerm) t, NULL);
        if (ATisEmpty(ambs)) {
          fun = ATgetAFun(t);
          if (ATisEqual(fun, SG_Eager_AFun)) {
            return ATtrue;
          }
          /*  Preferred subtrees in trees that are to be avoided don't count  */
          if (ATisEqual(fun, SG_Uneager_AFun)
              || ATisEqual(fun, SG_Reject_AFun)) {
            return ATfalse;
          }
          return SG_HasPreferredProds((forest) ATgetArgument((ATermAppl) t, 1));
        }
        else { /* We have an ambiguity cluster. Then the nodes of this
                  cluster have to be inspected. */
          return SG_HasPreferredProdsInAmbCluster(ambs);
        }
      }
    case AT_LIST:
      for (; !ATisEmpty((ATermList) t); t = (tree) ATgetNext((ATermList) t)) {
        if (SG_HasPreferredProds((tree) ATgetFirst((ATermList) t))) {
          return ATtrue;
        }
      }
      return ATfalse;
    case AT_INT:
    default:
      return ATfalse;
  }
}

/* Looking depth-first for an avoid attribute in an ambiguity
 * cluster. We assume that an ambiguity cluster only contains appls.
 */
ATbool SG_HasAvoidedProds(tree t);
ATbool SG_HasAvoidedProdsInAmbCluster(ATermList ambs)
{
  for (; !ATisEmpty(ambs); ambs = ATgetNext(ambs)) {
    tree thisamb = (tree) ATgetFirst(ambs); 
    switch (ATgetType(thisamb)) {
      case AT_APPL:
        {
          AFun fun;
  
          fun = ATgetAFun(thisamb);
          if(ATisEqual(fun, SG_Uneager_AFun)) {
            return ATtrue;
          }
          
          if (SG_HasAvoidedProds((forest) ATgetArgument((ATermAppl) thisamb,
                                                            1))) {
            return ATtrue;
          }
       }
     default: 
       {
         IF_DEBUG(fprintf(SG_log(), 
                          "A non appl node found in an ambiguity cluster\n"));
         return ATfalse;
       }
    }
  }
  return ATfalse;
}

ATbool SG_HasAvoidedProds(tree t)
{
  switch(ATgetType(t)) {
    case AT_APPL:
      {
        AFun fun;
        ATermList ambs;

        ambs = (ATermList) SG_AmbTable(SG_AMBTBL_GET, (ATerm) t, NULL);
        if (ATisEmpty(ambs)) {
          fun = ATgetAFun(t);
          if(ATisEqual(fun, SG_Uneager_AFun)) {
            return ATtrue;
          }
          /*  Avoided subtrees in trees that are to be preferred don't count  */
          if(ATisEqual(fun, SG_Eager_AFun)) {
            return ATfalse;
          }
        
          return SG_HasAvoidedProds((forest) ATgetArgument((ATermAppl) t, 1));
        }
        else {
          return SG_HasAvoidedProdsInAmbCluster(ambs);
        }
      }
    case AT_LIST:
      for(; !ATisEmpty((ATermList) t); t = (tree) ATgetNext((ATermList) t)) {
        if(SG_HasAvoidedProds((tree) ATgetFirst((ATermList) t))) {
          return ATtrue;
        }
      }
      return ATfalse;
    case AT_INT:
    default:
      return ATfalse;
  }
}

size_t SG_CountInjections(parse_table *pt, multiset ms, register ATermList keys)
{
  size_t ret = 0;
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

/* SG_CountInjectionsInTree counts injections using
 * a parse tree, instead of using the multiset directly.
 *
 * this is due to the fact that the multiset is not defined
 * on ambiguity clusters, but injection count is.
 */
size_t SG_CountInjectionsInTree(parse_table *pt, tree t, size_t injections);

size_t SG_CountInjectionsInTreeRecursive(parse_table *pt, tree t, size_t injections)
{
	label l;
	ATermList ambs;
	ATerm kids;

  switch (ATgetType(t)) {
	case AT_APPL:
		l = SG_GetApplProdLabel(t);
		ambs = (ATermList) SG_AmbTable(SG_AMBTBL_GET, (ATerm) t, NULL);

		if(ATisEmpty(ambs)) {
			kids = ATgetArgument((ATermAppl) t, 1);

			if(SG_ProdIsInjection(pt, l)) {
				injections++;
			}
			
			injections = SG_CountInjectionsInTreeRecursive(pt, (tree) kids, injections);
		} else {
			/* Either we have a singleton or
			 * the injection count of all elements in the cluster are
			 * equal due to earlier filtering, so we just take the first.
			 */
			tree first = (tree) ATgetFirst(ambs);
			injections = SG_CountInjectionsInTree(pt, first, injections);
		}
				
		break;
	case AT_LIST:
		for (; !ATisEmpty((ATermList) t); t = (tree) ATgetNext((ATermList) t)) {
			ATerm elem = ATgetFirst((ATermList) t);
			injections = SG_CountInjectionsInTreeRecursive(pt, (tree) elem, injections);
		}
		break;
	case AT_INT:
	case AT_REAL:
	case AT_PLACEHOLDER:
	case AT_BLOB:
	default:
		break;
  }

  return injections;
}    

size_t SG_CountInjectionsInTree(parse_table *pt, tree t, size_t injections)
{
	label    l;
	ATerm kids;

  switch (ATgetType(t)) {
	case AT_APPL:
		l = SG_GetApplProdLabel(t);
		kids = ATgetArgument((ATermAppl) t, 1);
		
		if(SG_ProdIsInjection(pt, l)) {
			injections++;
		}
		
		injections = SG_CountInjectionsInTreeRecursive(pt, (tree) kids, injections);
		break;
	case AT_LIST:
		for (; !ATisEmpty((ATermList) t); t = (tree) ATgetNext((ATermList) t)) {
			ATerm elem = ATgetFirst((ATermList) t);
			injections = SG_CountInjectionsInTreeRecursive(pt, (tree) elem, injections);
		}
		break;
	case AT_INT:
	case AT_REAL:
	case AT_PLACEHOLDER:
	case AT_BLOB:
	default:
		break;
  }

  return injections;
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
  multiset   m1  = NULL;
  tree       max = NULL;
  ATermList  k1  = NULL;
  ATbool     m0made = ATfalse;

/* If one of the terms is cyclic, no comparison is possible.
 * This should be improved one way or the other.
 */
  if (SG_TermIsCyclic(t0)) {
    return NULL;
  }
  if (SG_TermIsCyclic(t1)) {
    return NULL;
  } 

  /*  Always apply direct priority filtering first  */
  l0 = SG_GetATint(SG_GetApplProdLabel(t0), 0);
  l1 = SG_GetATint(SG_GetApplProdLabel(t1), 0);

  if (SG_GtrPriority(pt, l0, l1)) {
    IF_DEBUG(ATfprintf(SG_log(), "Direct Priority: %t > %t\n", l0, l1))
    return t0;
  }
  if (SG_GtrPriority(pt, l1, l0)) {
    IF_DEBUG(ATfprintf(SG_log(), "Direct Priority: %t < %t\n", l0, l1))
    return t1;
  }

  /*  Next, inspect eager/avoid status  */

  /*  Don't even bother unless there are preferred actions  */
  if (SG_PT_HAS_PREFERENCES(pt)) {
    if (SG_EagerPriority_Tree(t0, t1)) {
      IF_DEBUG(ATfprintf(SG_log(), "(Un)Eagerness Priority: %t > %t\n", l0, l1))
      return t0;
    }
    if (SG_EagerPriority_Tree(t1, t0)) {
      IF_DEBUG(ATfprintf(SG_log(), "(Un)Eagerness Priority: %t < %t\n", l0, l1))
      return t1;
    }
  }

  /*
     Don't even bother filtering any further if filtering is disabled
     or there's nothing to filter with (no prios, no preferences)
   */
  if (!SG_FILTER) {
    return NULL;
  }

	/* the next code is a filter that finds the topmost preference in both
	 * trees. If one of them is prefered or avoided, and the other has no
	 * explicit preference, then it throws one of them away.
	 */
	
/* The next ifdef maybe removed when it is clear that
 * this code has no effect. (03-10-2000) 
 * Mark
 */
#ifdef MAYBE_OBSOLETE
  /*  Don't even bother unless there are preferred actions  */
  if (SG_PT_HAS_PREFERENCES(pt)) {
    /* search for prefers */
    ATbool has_prefs0  = SG_HasPreferredProds(t0);
    ATbool has_prefs1  = SG_HasPreferredProds(t1);
    /* search for avoids */
    ATbool has_avoids0 = SG_HasAvoidedProds(t0);
    ATbool has_avoids1 = SG_HasAvoidedProds(t1);
	
    /* draw safe conclusions */
    if (has_prefs0 && !has_prefs1) {
      IF_DEBUG(ATfprintf(SG_log(), 
                         "Implicit Preference Priority: %t > %t\n", l0, l1))
      return t0;
    } else if (has_prefs1 && !has_prefs0) {
      IF_DEBUG(ATfprintf(SG_log(), 
                         "Implicit Preference Priority: %t < %t\n", l0, l1))
      return t1;
    }

    if (has_avoids0 && !has_avoids1) {
      IF_DEBUG(ATfprintf(SG_log(), 
                         "Implicit Preference Priority: %t < %t\n", l0, l1))
      return t1;
    } else if (has_avoids1 && !has_avoids0) {
      IF_DEBUG(ATfprintf(SG_log(), 
                         "Implicit Preference Priority: %t > %t\n", l0, l1))
      return t0;
    }
  }
#endif

  /*  Don't filter START symbols when start symbol subselection is on  */
  if (SG_STARTSYMBOL && SG_StartInjection(pt, ATgetInt(l0))) {
    return (tree) NULL;
  }

  /*
      No direct priority relation?  Apply multiset ordering,
      if there is anything to filter on
   */
  if (SG_PT_HAS_PRIORITIES(pt) || SG_PT_HAS_PREFERENCES(pt)) {
    if (!m0) {
      m0made = ATtrue;
      m0 = SG_GetMultiSet(t0, SG_NewMultiSet(SG_PT_NUMPRODS(pt)));
    }
    m1 = SG_GetMultiSet(t1, SG_NewMultiSet(SG_PT_NUMPRODS(pt)));

		if(!m0 || !m1) {
			/* at least one of the multisets wasn't calculated.
			 * probably due to an ambiguity node in the tree.
			 * So bail out!
			 */
			return NULL;
		}

    if (!k0) {
      k0 = SG_GetMultiSetKeys(m0);
    }
    k1 = SG_GetMultiSetKeys(m1);

    if (!ATisEqual(t0, t1) && !SG_MultiSetEqual(m0, m1, k0, k1)) {
      /*  multi-prio is irreflexive  */
      if (SG_MultiSetGtr(pt, m0, k0, m1, k1)) {
        IF_DEBUG(ATfprintf(SG_log(), "Multiset Priority: %t > %t\n", l0, l1))
        max = t0;
      }
      if (SG_MultiSetGtr(pt, m1, k1, m0, k0)) {
        if (max) {                             /*  shouldn't happen, really  */
          IF_DEBUG(fprintf(SG_log(),
                           "Symmetric multiset priority relation ignored\n"))
          ATwarning("Ignoring symmetric multiset priority relation\n");
          max = NULL;
        } else {
          IF_DEBUG(ATfprintf(SG_log(), "Multiset Priority: %t < %t\n", l0, l1))
          max = t1;
        }
      }
    }
    else {          
       IF_DEBUG(fprintf(SG_log(), "Multisets were equal\n"))
    }
  }

  /*  Did we find a multiset ordering?  */
  if (max) {
    IF_STATISTICS(SG_MultiSetFilterSucceeded(SG_NR_INC));
  } else {
  /*  No multiset ordering either?  Count injections.  */
    size_t in0 = 0, in1 = 0;

		in0 = SG_CountInjectionsInTree(pt, t0, 0);
		in1 = SG_CountInjectionsInTree(pt, t1, 0);
		
    IF_STATISTICS(
      if (in0 != in1) {
        SG_InjectionFilterSucceeded(SG_NR_INC);
      }
    );
    if (in0 > in1) {
      IF_DEBUG(ATfprintf(SG_log(), "Injection Priority: %t < %t (%d > %d)\n",
                         l0, l1, in0, in1))
      max = t1;
    } else if (in0 < in1) {
      IF_DEBUG(ATfprintf(SG_log(), "Injection Priority: %t > %t (%d < %d)\n",
                         l0, l1, in0, in1))
      max = t0;
    }
  }

  if (m0made) {
    ATtableDestroy(m0);
  }
  if (m1) {
    ATtableDestroy(m1);
  }

  IF_DEBUG(ATfprintf(SG_log(), "max = %p returned \n"));
  return max;
}

ATermList SG_FilterList(parse_table *pt, ATermList old, tree t)
{
  multiset   m = NULL;
  ATermList  k = ATempty, new = ATempty;
  tree       prev, max;
  ATbool     term_filtered_out = ATfalse;

  if (ATisEmpty(old))
    return ATmakeList1((ATerm) t);

  if (SG_TermIsCyclic(t)) {
    return ATinsert(old, (ATerm) t);
  }

  /*  Multiset construction is needed only when really filtering  */
  if (SG_FILTER) {
    m = SG_GetMultiSet(t, SG_NewMultiSet(SG_PT_NUMPRODS(pt)));
		
		if(m) {
			/* if m is NULL, then the multiset would not have been
			 * calculated due to an ambiuity node inside the tree
			 */ 
			k = SG_GetMultiSetKeys(m);
		} 
	}

	if(m) {	
		/*  Filter term against existing terms in ambiguity cluster  */

		IF_DEBUG(fprintf(SG_log(), "original tree:"));
		IF_DEBUG(SG_PrintTree(t, ATfalse));
		IF_DEBUG(fprintf(SG_log(), "\n"));

		for (;!ATisEmpty(old); old = ATgetNext(old)) {
			prev = (tree) ATgetFirst(old);
			
			IF_DEBUG(fprintf(SG_log(), "previous tree:"));
			IF_DEBUG(SG_PrintTree(prev, ATfalse));
			IF_DEBUG(fprintf(SG_log(), "\n"));

			/* Add prev to new, unless t has a higher priority  */
			max = SG_Filter(pt, t, prev, m, k);
			if (!max || (term_filtered_out=ATisEqual(max, prev))) {
				new = ATinsert(new, (ATerm) prev);
			}
			if (max) {
				if (SG_GetApplProdLabel(prev) == SG_GetApplProdLabel(t)) {
          IF_DEBUG(fprintf(SG_log(), "\nmax:"));
          IF_DEBUG(SG_PrintTree(max, ATfalse));
          IF_DEBUG(fprintf(SG_log(), "\n"));
        }
				IF_DEBUG(fprintf(SG_log(), "Priority: %d %c %d (old amb)\n",
												 SG_GetApplProdLabel(prev),
												 ATisEqual(max, prev)?'>':'<',
												 SG_GetApplProdLabel(t))
								 );
			}
		}
		if (!term_filtered_out) {
			new = ATinsert(new, (ATerm) t);
		}
		
		if (m) {
			ATtableDestroy(m);
		}
		
	} else {
		/* no multiset for this term, so we give up */
		new =  ATinsert(old, (ATerm) t);
	}
	
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
	/* What the hAck is going on here? What does ATisEmpty((ATermList) ambidx) mean? */
	/* Maybe it has something to do with cycle detection ???? Or whatever. */
  if(!ambidx  || ATisEmpty((ATermList) ambidx) ) { 
    /* New ambiguity */
    ambidx = (ATerm) ATmakeInt(SG_MaxNrAmb(SG_NR_INC));
    /* Add mapping for existing term also */
    SG_AmbTable(SG_AMBTBL_ADD_INDEX, (ATerm) existing, ambidx);

    /*  Filter the two  */
    if(!(max = SG_Filter(pt, new, existing, NULL, NULL))) {
      /*  existing and new are not priority-related */
      newambs = ATmakeList2((ATerm) existing, (ATerm) new);
    } else {
      /*  new and existing are in a priority relation, max is top  */
      newambs = ATmakeList1((ATerm) max);
      if (max) {
        if (SG_GetApplProdLabel(existing) == SG_GetApplProdLabel(new)) {
          IF_DEBUG(fprintf(SG_log(), "existing:"));
          IF_DEBUG(SG_PrintTree(existing, ATfalse));
          IF_DEBUG(fprintf(SG_log(), "\nnew:"));
          IF_DEBUG(SG_PrintTree(new, ATfalse));
          IF_DEBUG(fprintf(SG_log(), "\nmax"));
          IF_DEBUG(SG_PrintTree(max, ATfalse));
          IF_DEBUG(fprintf(SG_log(), "\n"));
        }
        IF_DEBUG(fprintf(SG_log(), "Priority: %d %c %d (new amb)\n",
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
    if(ATindexOf(oldambs, (ATerm) new, 0) != -1) {
      return;  /*  Already present?  Done.  */
    }
    newambs = SG_FilterList(pt, oldambs, new);
  }

  /*   Update ambiguity cluster  */
  SG_AmbTable(SG_AMBTBL_ADD_INDEX, (ATerm) new, ambidx);
  SG_AmbTable(SG_AMBTBL_UPDATE_CLUSTER, ambidx, (ATerm) newambs);

  return;
}
