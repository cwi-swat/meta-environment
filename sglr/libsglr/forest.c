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

#include <unistd.h>          
#include <string.h>   

#include <stdlib.h>
#include <assert.h>

#include <aterm2.h>
#include <a2toa1.h>

#include "multisets.h"
#include "bitmap.h"
#include "mem-alloc.h"
#include "forest.h"
#include "parse-table.h"
#include "sglr.h"
#include "sglr-strings.h"

int SG_ProdType_AFun(AFun f);
int SG_ProdType_Tree(tree t);

extern long sg_nr_rejects;

ATermTable resolvedtable = NULL;

/* struct used by AmbTracker to generate handy error messages */
typedef struct linecolpos_tag {
  size_t line;
  size_t col;
  size_t pos;
} linecolpos;

int SG_InjectionFilterSucceeded(int mode)
{
  static int count = 0;

  switch(mode) {
    case SG_NR_ZERO:
      return count = 0;
    case SG_NR_INC:
      return count++;
    case SG_NR_DEC:
      return count--;
    case SG_NR_ASK:
    default:
      return count;
  }
}

int SG_MultiSetFilterSucceeded(int mode)
{
  static int count = 0;

  switch(mode) {
    case SG_NR_ZERO:
      return count = 0;
    case SG_NR_INC:
      return count++;
    case SG_NR_DEC:
      return count--;
    case SG_NR_ASK:
    default:
      return count;
  }
}

int SG_InjectionCountCalls(int mode)
{
  static int count = 0;

  switch(mode) {
    case SG_NR_ZERO:
      return count = 0;
    case SG_NR_INC:
      return count++;
    case SG_NR_DEC:
      return count--;
    case SG_NR_ASK:
    default:
      return count;
  }
}

int SG_MultiSetGtrCalls(int mode)
{
  static int count = 0;

  switch(mode) {
    case SG_NR_ZERO:
      return count = 0;
    case SG_NR_INC:
      return count++;
    case SG_NR_DEC:
      return count--;
    case SG_NR_ASK:
    default:
      return count;
  }
}

int SG_PreferAndAvoidCalls(int mode)
{
  static int count = 0;

  switch(mode) {
    case SG_NR_ZERO:
      return count = 0;
    case SG_NR_INC:
      return count++;
    case SG_NR_DEC:
      return count--;
    case SG_NR_ASK:
    default:
      return count;
  }
}
               
int SG_AmbCalls(int mode)
{
  static int count = 0;

  switch(mode) {
    case SG_NR_ZERO:
      return count = 0;
    case SG_NR_INC:
      return count++;
    case SG_NR_DEC:
      return count--;
    case SG_NR_ASK:
    default:
      return count;
  }
}

int SG_MaxNrAmb(int mode)
{
  static int count = 0;

  switch(mode) {
    case SG_NR_ZERO:
      return count = 0;
    case SG_NR_INC:
      return count++;
    case SG_NR_DEC:
      return count--;
    case SG_NR_ASK:
    default:
      return count;
  }
}

int SGnrAmb(int mode)
{
  static int count = 0;

  switch(mode) {
    case SG_NR_ZERO:
      return count = 0;
    case SG_NR_INC:
      return ++count;
    case SG_NR_DEC:
      return --count;
    case SG_NR_ASK:
    default:
      return count;
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

/* During cycle detection we assume that *NO* new terms are
 * created!!!
 */
ATbool SG_TermIsCyclicRecursive(tree t, ATbool inAmbs, Bitmap visited);

ATbool SG_TermIsCyclicAmbs(tree t, ATermList ambs, Bitmap visited)
{
  tree amb;
  ATbool hasCycle = ATfalse;

  for (; !hasCycle && !ATisEmpty(ambs); ambs = ATgetNext(ambs)) { 
    SGnrAmb(SG_NR_INC);            /* Increase for each node in cluster */
    amb = (tree) ATgetFirst(ambs);
    if (!ATisEqual((ATerm) t, (ATerm) amb)) {
      hasCycle =
        SG_TermIsCyclicRecursive((tree) amb, ATtrue, visited);
    }
  }
  return hasCycle;
}

ATbool SG_TermIsCyclicRecursive(tree t, ATbool inAmbs, Bitmap visited)
{
  ATermList ambs;

  if (Cycle) {
    /*  Cycle has been detected, done  */
    return ATtrue;
  }

  if (SG_IS_MARKED(t)) {
    /*  Cycle detected  */
    Cycle = ATempty;
    return ATtrue;
  }

  SG_MARK(t);
  switch (ATgetType(t)) {
    case AT_APPL:
      /*  Ambiguity cluster?  */
      ambs = (ATermList) SG_AmbTable(SG_AMBTBL_GET, (ATerm) t, NULL);
      if (inAmbs ||  ATisEmpty(ambs)) {
        /*  No ambiguity  */
        SG_TermIsCyclicRecursive((tree) ATgetArgument((ATermAppl) t, 1),
                                 ATfalse, visited);
      } 
      else {
        /*  Encountered an ambiguity cluster  */
        int idx = ATgetInt((ATermInt) SG_AmbTable(SG_AMBTBL_LOOKUP_INDEX, 
                                                  (ATerm) t, NULL));
        if (!BitmapIsSet(visited,idx)) {

          SGnrAmb(SG_NR_INC); /* new ambcluster */

          /*  First check whether or not t itself is cyclic...  */

          SG_TermIsCyclicRecursive((forest) ATgetArgument((ATermAppl) t, 1),
                                    ATtrue, visited);   

          SG_TermIsCyclicAmbs(t, ambs, visited);
          visited = BitmapSet(visited, idx);
        }
      }
      break;
    case AT_LIST:
      if (!ATisEmpty((ATermList) t)) {
        SG_TermIsCyclicRecursive((forest) ATgetFirst((ATermList) t), 
                                 ATfalse, visited);
        SG_TermIsCyclicRecursive((forest) ATgetNext((ATermList) t), 
                                 ATfalse, visited);
      }
      break;
    default:
      break;
  }

  /*  Out of recursion here: restore term state  */
  SG_UNMARK(t);

  /*  Remember labels of productions in cycle */
  if (Cycle && ATgetType(t) == AT_APPL) {
    if (ATisEqual(ATgetAFun(ATgetArgument(t, 0)), SG_Aprod_AFun)) {
      Cycle = ATinsert(Cycle,
                      (ATerm) SG_GetATint(SG_GetApplProdLabel((tree) t), 0));
    }
  }
  return Cycle && !ATisEmpty(Cycle);
}

ATbool SG_TermIsCyclic(tree t)
{
  ATbool cyclic;
  Bitmap visited = BitmapCreate(SG_MaxNrAmb(SG_NR_ASK));

  SGnrAmb(SG_NR_ZERO);

  cyclic = SG_TermIsCyclicRecursive(t, ATfalse, visited);

  BitmapDestroy(visited);

  /*  
  AT_assertUnmarked(t);
  */
 
  return cyclic;
}


void SG_PrintTree(tree t, ATbool inAmbs);
ATermList SG_CyclicTerm(parse_table *pt, forest t)
{
  Cycle = NULL;


  if (!SG_TermIsCyclic(t)) {
    return ATempty;
  }

  if (Cycle) {
    ATermList cycleprods = ATempty;

    for (; !ATisEmpty(Cycle); Cycle = ATgetNext(Cycle)) {
      cycleprods = ATinsert(cycleprods,
                            (ATerm) SG_LookupProduction(pt,
                              (label) ATgetInt((ATermInt) ATgetFirst(Cycle))));
    }
    return cycleprods;
  }
  return ATempty;
}

/* Yield converts aprods to AsFix */
tree SG_YieldTree(parse_table *pt, tree t)
{
  tree      arg, res, newarg;
  ATermList args, newargs, ambs, tail;
  AFun      fun;
  ATerm     pos_info;
  ATerm     prod;

  if (!t) {
    return NULL;
  }

  switch(ATgetType(t)) {
  case AT_LIST:
    args = (ATermList) t;

    if (!ATisEmpty(args)) {
      arg = (tree) ATgetFirst(args);
      tail = ATgetNext(args);

      if (ATisEmpty(tail)) {
        newargs = ATempty;
      } else {
        newargs = (ATermList)SG_YieldTree(pt, (tree) tail);
      }
    
      newarg = (tree) SG_YieldTree(pt, arg);
      if (ATisEqual(newarg, arg) && ATisEqual(newargs, tail)) {
	newargs = args;
      } else {
        newargs = ATinsert(newargs, (ATerm)newarg); 
      }
    }
    else {
      newargs = ATempty;
    }
    return (tree)newargs;
  case AT_APPL:
    fun  = ATgetAFun(t);

    /*  A small sanity check  */
    assert(fun != SG_Reject_AFun); 

    if(fun == SG_Amb_AFun) {
       SGnrAmb(SG_NR_INC);
       ambs = (ATermList) ATgetArgument((ATerm) t, 0); /* get the ambs */
       ambs = (ATermList) SG_YieldTree(pt, (tree) ambs);
       res  = ATsetArgument((ATermAppl) t, (ATerm) ambs, 0);
    } else {
      pos_info = SG_GetPosInfoLabel(t);
      prod = ATgetArgument((ATerm) t, 0); /* get the prod */
      args = (ATermList) ATgetArgument((ATerm) t, 1); /* get the args */
      args = (ATermList) SG_YieldTree(pt, (tree) args);
      prod = (ATerm) SG_LookupProduction(pt, SG_GetProdLabel((tree) prod));
 
      res  = ATmakeAppl2(SG_Appl_AFun, prod, (ATerm) args);
      if(pos_info) {
        res = SG_SetPosInfoLabel(res, pos_info);
      }
    }
    return res;
  }

  return t;
}


ATermList  SG_AmbTrackerRecursive(tree t, linecolpos *currpos)
{
  ATermList allambs, args, kidambs, ambs;
  linecolpos ambpos;
  tree      amb;
  AFun      fun;
  int       treetype;
  ATerm     amb_with_pos;
  ATermList prods;

  treetype = ATgetType(t);
  allambs = ATempty;

  switch(treetype) 
  {
  case AT_INT:
    switch(ATgetInt((ATermInt) t)) {
      case '\n':
	(currpos->line)++;
	(currpos->col) = 0;
      default:
	(currpos->col)++;
        (currpos->pos)++;
    }
    break;
  case AT_LIST:
    args = (ATermList) t;
    for(; !ATisEmpty(args); args = ATgetNext(args)) {
      kidambs = SG_AmbTrackerRecursive((tree) ATgetFirst(args), currpos);
      if(kidambs) {
         allambs = ATconcat(allambs, kidambs);
      } 
    }
    break;
  case AT_APPL:
    fun = ATgetAFun((ATermAppl) t);
    if(fun == SG_Amb_AFun) {
      ambs = (ATermList) ATgetArgument((ATermAppl) t, 0);
      ambpos = *currpos;

      prods = ATempty; /* the productions of the topnodes in this cluster */

      for(; !ATisEmpty(ambs); ambs = ATgetNext(ambs)) {
        *currpos = ambpos;
        amb = (tree) ATgetFirst(ambs);
 
        /* first we collect all nested ambiguities */
        kidambs = SG_AmbTrackerRecursive(amb, currpos);
        if(kidambs) {
         allambs = ATconcat(allambs, kidambs);
        } 

        /* here we handle THIS ambiguity */
        prods = ATinsert(prods, 
                         AF2ProdToText(ATgetArgument((ATermAppl) amb, 0))); 
      }
  
      /* construct the error message for this cluster */ 
      amb_with_pos = 
        (ATerm) ATmakeAppl2(SG_Amb_Node_AFun,
                            (ATerm) ATmakeAppl3(SG_Position_AFun,
			    (ATerm) ATmakeAppl1(SG_Line_AFun, 
						(ATerm) ATmakeInt(ambpos.line)),
			    (ATerm) ATmakeAppl1(SG_Col_AFun,
						(ATerm) ATmakeInt(ambpos.col)),
			    (ATerm) ATmakeAppl1(SG_Character_AFun,
                                                (ATerm) ATmakeInt(ambpos.pos))),
                            (ATerm) ATmakeAppl1(SG_Productions_AFun,
                                                (ATerm) ATreverse(prods)));  
 
      allambs = ATinsert(allambs, amb_with_pos);
    }
    else {
      args = (ATermList) ATgetArgument((ATermAppl) t, 1);

      allambs = SG_AmbTrackerRecursive((tree) args, currpos);
    }

    break;
  default:
    allambs = ATempty;
    break; 
  }

  return allambs;
}

ATerm SG_AmbTracker(tree t)
{
  linecolpos currpos = { 1, 0, 0 };
  ATermList amblist = ATempty;
  AFun fun;

  fun = ATgetAFun(t);

  if(fun == SG_ParseTree_AFun) {
    amblist = SG_AmbTrackerRecursive((tree) ATgetArgument((ATermAppl) t, 0), 
                                     &currpos);
  } else {
    amblist = SG_AmbTrackerRecursive(t, &currpos);
  }

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

  switch (Mode) {
    case SG_AMBTBL_GET:
      if ((idx = SG_AmbTable(SG_AMBTBL_LOOKUP_INDEX, key, NULL))) {
        ret = SG_AmbTable(SG_AMBTBL_LOOKUP_CLUSTER, idx, NULL);
      }
      break;
    case SG_AMBTBL_INIT:
      if (ambtbl) {
        SG_AmbTable(SG_AMBTBL_CLEAR, NULL, NULL);
      }
      ambtbl = ATtableCreate(4096, 75);
      break;
    case SG_AMBTBL_CLEAR:
      if (ambtbl) {
        ATtableDestroy(ambtbl);
        ambtbl = NULL;
      }
      break;
    case SG_AMBTBL_ADD_INDEX:
    case SG_AMBTBL_ADD_CLUSTER:
    case SG_AMBTBL_UPDATE_INDEX:
    case SG_AMBTBL_UPDATE_CLUSTER:
      if (!ambtbl) {
        SG_AmbTable(SG_AMBTBL_INIT, NULL, NULL);
      }
      ATtablePut(ambtbl, key, value);
      break;
    case SG_AMBTBL_REMOVE:
      if (!ambtbl) {
        break;
      }
      if ((idx = SG_AmbTable(SG_AMBTBL_LOOKUP_INDEX, key, NULL))) {
        ATtableRemove(ambtbl, key);
        if (!ATisEmpty((ATermList) SG_AmbTable(SG_AMBTBL_LOOKUP_CLUSTER,
                                              idx, NULL))) {
          ATtableRemove(ambtbl, idx);
        }
      }
        break;
    case SG_AMBTBL_LOOKUP_INDEX:
    case SG_AMBTBL_LOOKUP_CLUSTER:
      if (!ambtbl) {
        return (ATerm) ATempty;
      }
      ret = ATtableGet(ambtbl, key);
      ret=ret?ret:(ATerm) ATempty;
      break;
#ifdef DEBUG
    case SG_AMBTBL_DUMP:
      if (ambtbl) SG_Dump_ATtable(ambtbl, "Ambs");
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
  if (!SG_PT_HAS_PREFERENCES(pt)) {
    return ATfalse;
  }
  return SG_MoreEager(SG_ProdType_Label(pt, lt0), SG_ProdType_Label(pt, lt1));
}

/* For each production in the tree the number of occurrences is
 * calculated.
 */
static MultiSet SG_CreateMultiSetRecursive(parse_table *pt, MultiSetTable mst, 
                                           MultiSet ms, tree t)
{
  label    l;
  AFun     fun;

  MultiSet mstree = MultiSetTableGet(mst, (ATerm) t);

  if (mstree != NULL) {
    MultiSetMerge(ms, mstree);
    return ms;
  } 

  switch (ATgetType(t)) {
    case AT_APPL:
      fun = ATgetAFun(t);

      if (fun == SG_Amb_AFun) {
         return NULL;
      } else {
        l = SG_GetApplProdLabel(t); 
        MultiSetIncrease(ms, SG_PROD_TO_NR(l));
        ms = SG_CreateMultiSetRecursive(pt, mst, ms,
                                        (tree) ATgetArgument((ATermAppl) t, 1));
      }
      break;
    case AT_LIST:
      if (ATisEmpty((ATermList) t)) {
        break;
      }
      for (; !ATisEmpty((ATermList) t); t = (tree) ATgetNext((ATermList) t)) {
        ms = SG_CreateMultiSetRecursive(pt, mst, ms,
                                        (tree) ATgetFirst((ATermList) t));
        if (!ms) {
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

MultiSet SG_CreateMultiSetUsingTree(parse_table *pt, MultiSetTable mst, 
                                    tree t)
{
  MultiSet ms, ims;

  ims = MultiSetCreate(SG_PT_NUMPRODS(pt));

  ms = SG_CreateMultiSetRecursive(pt, mst, ims, t);

  if (!ms) {
    MultiSetDestroy(ims);
  }
  return ms;
}

ATbool SG_MultiSetEqual(MultiSet ms1, MultiSet ms2);

int SG_GetNrOfPrefers(parse_table *pt, MultiSet ms)
{
  ATermInt ly;
  int y, My;
  int prefercount = 0;
  int size = MultiSetGetSize(ms); /* equal to the other one */
  
  for (y = 0; y < size; y++) {

    My = MultiSetGetCount(ms, y);
    if (My > 0) {
      ly = SG_NR_TO_PROD(SG_GetATint(y, 0));
      
      if (SG_ProdType_Label(pt, ly) == SG_PT_EAGER) {
        prefercount = prefercount + My;
      }
    }
  }
  return prefercount;
}

int SG_GetNrOfAvoids(parse_table *pt, MultiSet ms)
{
  ATermInt ly;
  int y, My;
  int avoidcount = 0;
  int size = MultiSetGetSize(ms); /* equal to the other one */

  for (y = 0; y < size; y++) {

    My = MultiSetGetCount(ms, y);
    if (My > 0) {
      ly = SG_NR_TO_PROD(SG_GetATint(y, 0));

      if (SG_ProdType_Label(pt, ly) == SG_PT_UNEAGER) {
        avoidcount = avoidcount + My;
      }
    }
  }
  return avoidcount;
}
   
/*
 * This filter is needed because it can happen that one tree
 * contains "avoid"s and the other tree contains "prefer"s.
 * As soon as this happens the MultiSets of both trees become
 * symmetric. The filter "SG_FilterOnPreferAndAvoid" counts
 * the number of prefers and avoids in both trees and tries
 * to make a comparison between the two.
 * 
 *  t1 is prefer over t2 if 
 *  !(#prefers in t1 < #prefers in t2 && #avoids in t1 > #avoids in t2)      
 */

ATbool SG_FilterOnPreferAndAvoid(parse_table *pt, MultiSet msM, MultiSet msN)
{                                                            
  int pM, pN, aM, aN;

  IF_STATISTICS(SG_PreferAndAvoidCalls(SG_NR_INC));

  if (SG_MultiSetEqual(msM, msN)) { /* M != N */
    return ATfalse;
  }                         

  pM = SG_GetNrOfPrefers(pt, msM);
  pN = SG_GetNrOfPrefers(pt, msN);
  aM = SG_GetNrOfAvoids(pt, msM);
  aN = SG_GetNrOfAvoids(pt, msN);

  if ((pM < pN) && (aM > aN)) {
    return ATfalse;
  }
  else {
    return ATtrue;
  }
}

/* NOTE: We temporarily maintain two versions of MultiSetGtr.
 *
 * The first was developed by fixing the existing implementation of v2.40
 *
 * The second was developed from scratch by
 * implementing the multiset formula on p108 of Eelco Visser's dissertation.
 *
 * These implementations are expected to be equal.
 */
#define MULTISETGTR_ORIGINAL
#ifdef MULTISETGTR_ORIGINAL

/* MultiSetGtr is the core of the multiset algorithm. See page XXX
 * of Eelco Visser's dissertation.
 *
 * We use Visser's notation msM and msN for easy reference, instead
 * of our standard ms0 and ms1.
 */
ATbool SG_MultiSetGtr(parse_table *pt, MultiSet msM, MultiSet msN)
{
  ATermInt lx, ly;
  int x, y;
  int My, Ny, Mx, Nx;
  ATbool result, foundone, totalresult;
  int size = MultiSetGetSize(msM); /* equal to the other one */

  IF_STATISTICS(SG_MultiSetGtrCalls(SG_NR_INC));

  if (SG_MultiSetEqual(msM, msN)) { /* M != N */
    return ATfalse;
  }

  /*  For all y in M such that M(y) > N(y) ...  */

/*
ATwarning("msM: ");
MultiSetPrint(stderr, msM);
ATwarning("\nmsN: ");
MultiSetPrint(stderr, msN);
ATwarning("\n");
*/

  totalresult = ATfalse;
  for (y = 0; y < size; y++) {

    My = MultiSetGetCount(msM, y);
    if (My > 0) {
      Ny = MultiSetGetCount(msN, y);

      ly = SG_NR_TO_PROD(SG_GetATint(y, 0));

      if (My > Ny) {

        /*  ... there exists an x in N such that ( y >> x and M(x) < N(x) )  */
        result = ATfalse;
        foundone = ATfalse;
        for (x = 0; !result && (x < size); x++) {
          Nx = MultiSetGetCount(msN, x);
          if (Nx > 0) {
            Mx = MultiSetGetCount(msM, x);

            lx = SG_NR_TO_PROD(SG_GetATint(x, 0));

            if (SG_GtrPriority(pt, ly, lx) ||
                SG_EagerPriority(pt, ly, lx)) {
              result = (Mx < Nx);
/*
ATwarning("ly = %t lx = %t yields %d\n", ly,lx, result);
*/
              foundone = ATtrue;
            }
          }
        }
        if (foundone && !result) {
          return ATfalse;
        }
        else {
          totalresult = totalresult || result;
        }
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
  return totalresult;
}

#else /* MULTISETGTR translated from formula  */

/* MultiSetGtr is the core of the multiset algorithm. See page 108
 * of Eelco Visser's dissertation.
 *
 * We use Visser's notation msM and msN for easy reference, instead
 * of our standard ms0 and ms1.
 *
 * There is a difference between our
 * implementation and the formula in the dissertation! We implement
 * the formula in a straightforward manner, but by keeping two extra
 * variables: 'atleastoneresulti' and 'onegreater' we allow for SOME
 * productions to have no relation at all (!onegreater), but if ALL
 * productions have no relation at all (atleastoneresult) we cannot
 * conclude a relation off course.
 */


ATbool SG_MultiSetGtr(parse_table *pt, MultiSet msM, MultiSet msN)
{
  ATermInt ly, lx;
  int y, x;
  int My, Ny, Mx, Nx;
  ATbool oneresult, forallresult, onegreater, atleastoneresult;
  int size = MultiSetGetSize(msM);

  IF_STATISTICS(SG_MultiSetGtrCalls(SG_NR_INC));

  if (SG_MultiSetEqual(msM, msN)) { /* M != N */
    return ATfalse;
  }

  /* and */

  /* for all y in M */
  atleastoneresult = ATfalse;
  forallresult    = ATtrue;

  for (y = 0; y < size && forallresult; y++) {
    My = MultiSetGetCount(msM, y);

    if (My != 0) { /* if key */
       ATbool forallbody = ATfalse;
       Ny = MultiSetGetCount(msN, y);

       ly = SG_NR_TO_PROD(SG_GetATint(y, 0));

       if (!(My > Ny)) { /* M(y) > N(y)  */
         forallbody = ATtrue;
       }
       if (!forallbody) { /* ===> (implies) */

         /* for any x in N */
         onegreater = ATfalse;
         oneresult  = ATfalse;
         for(x = 0; x < size && !oneresult; x++) {
           Nx = MultiSetGetCount(msN, x);
           Mx = MultiSetGetCount(msM, x);

           if(Nx != 0) { /* if key */
             ATbool onebody, greater;
             lx = SG_NR_TO_PROD(SG_GetATint(x, 0));

             /* y > x && M(x) < N(x) */
             greater = (SG_GtrPriority(pt, ly, lx) ||
                        SG_EagerPriority(pt, ly, lx));
             onebody = greater && (Mx < Nx);

            /* update inner and outer loop values */
            onegreater = onegreater || greater;
            oneresult = oneresult || onebody;
            atleastoneresult = atleastoneresult || oneresult;
           }
         }
         forallbody = oneresult || !onegreater;
       }

      /* update outer loop value */
      forallresult = forallresult && forallbody;
    }
  }

  return forallresult && atleastoneresult;
}
#endif

ATbool SG_MultiSetEqual(MultiSet ms1, MultiSet ms2)
{
  return MultiSetEqual(ms1, ms2);
}

/* SG_CountInjectionsInTree counts injections using
 * a parse tree, instead of using the multiset directly.
 *
 * this is due to the fact that the multiset is not defined
 * on ambiguity clusters, but injection count is.
 */

size_t SG_CountInjectionsInTree(parse_table *pt, tree t)
{
  label l;
  ATermList ambs;
  ATerm kids;
  size_t injections = 0;
  AFun fun;
  tree first;

  switch (ATgetType(t)) {
  case AT_APPL:
    fun = ATgetAFun((ATerm) t);
    l = SG_GetApplProdLabel(t);
  
    if(fun == SG_Amb_AFun) {
      ambs = (ATermList) ATgetArgument((ATermAppl) t, 0);
      /* Either we have a singleton or
       * the injection count of all elements in the cluster are
       * equal due to earlier filtering, so we just take the first.
       */
      first = (tree) ATgetFirst(ambs);
      injections += SG_CountInjectionsInTree(pt, first);
    
    } else {
      kids = ATgetArgument((ATermAppl) t, 1);

      if(SG_ProdIsInjection(pt, l)) {
        injections++;
      }
      
      injections += SG_CountInjectionsInTree(pt, (tree) kids);
    }
    break;
  case AT_LIST:
    for (; !ATisEmpty((ATermList) t); t = (tree) ATgetNext((ATermList) t)) {
      ATerm elem = ATgetFirst((ATermList) t);
      injections += SG_CountInjectionsInTree(pt, (tree) elem);
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

/* Below we define the filters that compare two trees */

static tree SG_Priority_Filter(parse_table *pt, tree t0, tree t1)
{
  ATermInt  l0 = SG_GetATint(SG_GetApplProdLabel(t0), 0);
  ATermInt  l1 = SG_GetATint(SG_GetApplProdLabel(t1), 0);

  if (SG_GtrPriority(pt, l0, l1)) {
    IF_DEBUG(ATfprintf(SG_log(), "Direct Priority: %t > %t\n", l0, l1))
    return t0;
  }
  if (SG_GtrPriority(pt, l1, l0)) {
    IF_DEBUG(ATfprintf(SG_log(), "Direct Priority: %t < %t\n", l0, l1))
    return t1;
  }

  return NULL;
}

static tree SG_Eagerness_Filter(parse_table *pt, tree t0, tree t1)
{
 ATermInt l0 = SG_GetATint(SG_GetApplProdLabel(t0), 0);
 ATermInt l1 = SG_GetATint(SG_GetApplProdLabel(t1), 0);

  if (SG_EagerPriority_Tree(t0, t1)) {
     IF_DEBUG(ATfprintf(SG_log(), "(Un)Eagerness Priority: %t > %t\n", l0, l1))
     return t0;
  }
  if (SG_EagerPriority_Tree(t1, t0)) {
    IF_DEBUG(ATfprintf(SG_log(), "(Un)Eagerness Priority: %t < %t\n", l0, l1))
    return t1;
  }

  return NULL;
}

static tree SG_Multiset_Filter(parse_table *pt, MultiSetTable mst,
                               tree t0, tree t1)
{
  tree max = NULL;
  ATermInt  l0 = SG_GetATint(SG_GetApplProdLabel(t0), 0);
  ATermInt  l1 = SG_GetATint(SG_GetApplProdLabel(t1), 0);
  MultiSet ms0 = MultiSetTableGet(mst, (ATerm) t0);
  MultiSet ms1 = MultiSetTableGet(mst, (ATerm) t1);

  if (ms0 == NULL) {
    ms0 = SG_CreateMultiSetUsingTree(pt, mst, t0);
    if (ms0) {
      MultiSetTablePut(mst, (ATerm) t0, ms0);
    } 
  }
  if (ms1 == NULL) {
    ms1 = SG_CreateMultiSetUsingTree(pt, mst, t1);
    if (ms1) {
      MultiSetTablePut(mst, (ATerm) t1, ms1);
    }
  }

  if(!ms0 || !ms1) {
    /* at least one of the multisets wasn't calculated.
     * probably due to an ambiguity node in the tree.
     */
    return NULL;
  }
 
  if (SG_PT_HAS_PREFERS(pt) || SG_PT_HAS_AVOIDS(pt)) {
    if (SG_FilterOnPreferAndAvoid(pt, ms0, ms1)) {
      IF_DEBUG(ATfprintf(SG_log(), "Eagerness Priority: %t > %t\n", l0, l1))
      max = t0;
    }
  
    if (SG_FilterOnPreferAndAvoid(pt, ms1, ms0)) {
      if (max) {
        IF_DEBUG(ATfprintf(SG_log(),
                           "Symmetric eagerness priority relation %t %t\n", 
                           l0, l1))
        max = NULL;
      }
      else { 
        IF_DEBUG(ATfprintf(SG_log(), "Eagerness Priority: %t < %t\n", l0, l1))
        max = t1;
      }
    }
  }
  
  if (!max) {
    if (SG_MultiSetGtr(pt, ms0, ms1)) {
      IF_DEBUG(ATfprintf(SG_log(), "Multiset Priority: %t > %t\n", l0, l1))
      max = t0;
    } 

    if (SG_MultiSetGtr(pt, ms1, ms0)) {
      if (max) {
        IF_DEBUG(ATfprintf(SG_log(),
                           "Symmetric multiset priority relation %t %t\n", 
                           l0, l1))
        max = NULL;
      }
      else { 
        IF_DEBUG(ATfprintf(SG_log(), "Multiset Priority: %t < %t\n", l0, l1))
        max = t1;
      }
    }
  }
  
  if (max) {
    IF_STATISTICS(SG_MultiSetFilterSucceeded(SG_NR_INC));
  }

  return max;
}


static tree SG_InjectionCount_Filter(parse_table *pt, tree t0, tree t1)
{
  ATermInt  l0 = SG_GetATint(SG_GetApplProdLabel(t0), 0);
  ATermInt  l1 = SG_GetATint(SG_GetApplProdLabel(t1), 0);
  size_t in0   = SG_CountInjectionsInTree(pt, t0);
  size_t in1   = SG_CountInjectionsInTree(pt, t1);
 
/* 
ATwarning("tree %t has %d injections\n", l0, in0);
ATwarning("tree %t has %d injections\n", l1, in1);
*/

  IF_STATISTICS(
    SG_InjectionCountCalls(SG_NR_INC);
    if (in0 != in1) {
      SG_InjectionFilterSucceeded(SG_NR_INC);
    }
    );

  if (in0 > in1) {
    IF_DEBUG(ATfprintf(SG_log(), "Injection Priority: %t < %t (%d > %d)\n",
      				 l0, l1, in0, in1))
      return t1;
  } else if (in0 < in1) {
    IF_DEBUG(ATfprintf(SG_log(), "Injection Priority: %t > %t (%d < %d)\n",
      				 l0, l1, in0, in1))
      return t0;
  }

  return NULL;
}


/*
 SG_Filter -- a generic hook to add disambiguating `filters'

 Arguments:  the current parse table
 two terms
 Returns:    the preferred term of the two, or NULL if there is no
 filter that prefers either one of them
 */
tree SG_Filter(parse_table *pt, MultiSetTable mst, tree t0, tree t1)
{
  tree max = NULL;
 
  /* equal terms are ambiguous by definition */
  if (ATisEqual(t0, t1)) {
    return NULL;
  }
 
  /* the first filters are based on priorities and preferences */
  if (SG_PT_HAS_PRIORITIES(pt) || SG_PT_HAS_PREFERENCES(pt)) {

    /*  Always apply direct priority filtering first  */
    max = SG_Priority_Filter(pt, t0, t1);
    if(max) {
      return max;
    }

    /*  Next, inspect eager/avoid status  */
    max = SG_Eagerness_Filter(pt, t0, t1);
    if(max) {
      return max;
    }
 
    /* multiset filter */
    max = SG_Multiset_Filter(pt, mst, t0, t1);
    if (max) {
      return max;
    }
  }
 
  /* injectionscount filter always applies  */
  max = SG_InjectionCount_Filter(pt, t0, t1);
  
  return max;
}

ATermList SG_FilterList(parse_table *pt, MultiSetTable mst, ATermList ambs, 
                        tree t)
{
  ATermList  new = ATempty;
  tree       amb, max;
  ATbool     t_filtered_out = ATfalse;

  if (ATisEmpty(ambs)) {
    return ATmakeList1((ATerm) t);
  }

  /*  Filter term against all terms in ambiguity cluster  */

  for (;!ATisEmpty(ambs); ambs = ATgetNext(ambs)) {
    amb = (tree) ATgetFirst(ambs);

    /* Which of the two has a higher priority? */
    max = SG_Filter(pt, mst, t, amb);

    if(max == NULL) {
       /* it's a draw, so amb is added */
       new = ATinsert(new, (ATerm) amb);
    } else {
      if (ATisEqual(max, amb)) { 
        /* amb wins, so it is added, but
         * we prevent t from being added 
         */ 
        t_filtered_out = ATtrue;
        new = ATinsert(new, (ATerm) amb);  
      }
      /* else t wins for this case, so amb is not added */
    }

  }
  
  if (!t_filtered_out) {
    new = ATinsert(new, (ATerm) t);
  }
    
  return new;
}

static ATermList SG_Associativity_Filter(parse_table *pt, ATermList ambs)
{
  /* the rightmost child cluster of a left associative prod should
   * never be the same left associative prod, so we check for this
   *
   * Note that this can only happen in an amb cluster due to the filtering
   * algorithm because otherwise it would have been an error in the parsetable.
   *
   */
  label prodl;
  ATermList kids, newambs = ATempty;
  tree amb, lastkid, firstkid;

  for (;!ATisEmpty(ambs); ambs = ATgetNext(ambs)) {
    amb = (tree) ATgetFirst(ambs);
    prodl = SG_GetApplProdLabel(amb);

    if (SG_IsLeftAssociative(pt, prodl)) {
      kids = (ATermList) ATgetArgument((ATermAppl) amb, 1);
      lastkid = (tree) ATgetLast(kids);

      if (prodl != SG_GetApplProdLabel(lastkid)) {
        newambs = ATinsert(newambs, (ATerm) amb);
      } else {
        IF_DEBUG(ATfprintf(SG_log(),"Right associative node %d removed.\n",
                                    prodl)) 
      }
    }
    else if (SG_IsRightAssociative(pt, prodl)) {
      kids = (ATermList) ATgetArgument((ATermAppl) amb, 1);
      firstkid = (tree) ATgetFirst(kids);

      if (prodl != SG_GetApplProdLabel(firstkid)) {
        newambs = ATinsert(newambs, (ATerm) amb);
      } else {
        IF_DEBUG(ATfprintf(SG_log(),"Left associative node %d removed.\n",
                                    prodl)) 
      }
    }
    else {
      newambs = ATinsert(newambs, (ATerm) amb);
    }
  }  
  return newambs;
}         

tree SG_FilterTreeRecursive(parse_table *pt, MultiSetTable mst, 
                            tree t, ATbool inAmbs);

tree SG_FilterAmbs(parse_table *pt, MultiSetTable mst, ATermList ambs)
{
  tree t;
  ATermList newambs;
  tree amb;
 
  /* first we do the children */
  newambs = ATempty;
  for(;!ATisEmpty(ambs); ambs = ATgetNext(ambs)) {
    amb = (tree) ATgetFirst(ambs);
    newambs = ATinsert(newambs, 
                       (ATerm) SG_FilterTreeRecursive(pt, mst, amb, ATtrue));
  }
  ambs = newambs;

  if(SG_FILTER) {
    IF_DEBUG(ATfprintf(SG_log(), "Ambiguity cluster: %d nodes originally.\n", 
                       ATgetLength(ambs)))
   
    /* Remove all trees which have internal associativity conflicts. */
    ambs = SG_Associativity_Filter(pt, newambs); 

    /* now we handle this ambiguity cluster */
    if (ATgetLength(ambs) > 1) {
      ATermList ambscopy = ambs;
      ATermList ambschanged;

      /* for every node, compare it to all the others. If the node
       * has been filtered out already, we can skip it.
       */
      for(;!ATisEmpty(ambscopy); ambscopy = ATgetNext(ambscopy)) {
        amb = (tree) ATgetFirst(ambscopy);
        ambschanged = ATremoveElement(ambs, (ATerm) amb);
        if(!ATisEqual(ambs, ambschanged)) {
          ambs = SG_FilterList(pt, mst, ambschanged, amb);
        }
      }
    }       
  } 
  
  assert(ATgetLength(ambs) > 0);

  /* if there are ambiguities left, create an amb node */
  if(ATgetLength(ambs) > 1) {
    t = (tree) ATmakeAppl1(SG_Amb_AFun,(ATerm) ambs);
    IF_DEBUG(ATfprintf(SG_log(), "Ambiguity cluster: %d equivalent nodes.\n", 
                                 ATgetLength(ambs)))
  } else {
    t = (tree) ATgetFirst(ambs);
    IF_DEBUG(ATfprintf(SG_log(), "Ambiguity cluster: resolved to %d.\n",
                       SG_GetApplProdLabel(t)))
  }

  return t;
}

tree SG_FilterTreeRecursive(parse_table *pt, MultiSetTable mst, 
                            tree t, ATbool inAmbs)
{
  int type = ATgetType(t);
  ATermList args, ambs;
  ATermList newargs, tail, newtail;
  tree arg, newt, newarg;

  switch(type) {
  case AT_APPL:
    ambs = (ATermList) SG_AmbTable(SG_AMBTBL_GET, (ATerm) t, NULL);
    if (!inAmbs && !ATisEmpty(ambs)) {
      newt = (tree)ATtableGet(resolvedtable, (ATerm)t);
      if (newt == NULL) {
        newt = SG_FilterAmbs(pt, mst, ambs);
        ATtablePut(resolvedtable, (ATerm)t, (ATerm) newt);
      }
      t = newt;
    } else {
      args = (ATermList) ATgetArgument((ATerm) t, 1); /* get the kids */
      newargs = (ATermList) SG_FilterTreeRecursive(pt, mst, 
                                                   (tree) args, ATfalse);

      t = (tree) ATsetArgument((ATermAppl) t, (ATerm) newargs, 1);
    }
  break;
  case AT_LIST:
    args = (ATermList) t;

    if (!ATisEmpty(args)) {
      arg = (tree) ATgetFirst(args);
      tail = ATgetNext(args);

      if (ATisEmpty(tail)) {
        newtail = ATempty;
      } else {
        newtail = (ATermList)SG_FilterTreeRecursive(pt, mst, 
                                                    (tree)tail, ATfalse);
      }
    
      newarg = (tree) SG_FilterTreeRecursive(pt, mst, arg, ATfalse);
      if (!ATisEqual((ATerm)newarg, (ATerm)arg) || !ATisEqual(newtail, tail)) {
         t = (tree)ATinsert(newtail, (ATerm)newarg); 
      }
    }
  break;
  default:
  break;
  }

  return t;
}


tree SG_FilterTree(parse_table *pt, tree t)
{
   MultiSetTable mst;

   /* We only cache multisets for ambiguity clusters
    * so we create a table with at most 
    * #(ambiguity nodes) elements.
    */

   resolvedtable = ATtableCreate(2048, 75);
   mst = MultiSetTableCreate(SGnrAmb(SG_NR_ASK));

   t = SG_FilterTreeRecursive(pt, mst, t, ATfalse);

   MultiSetTableDestroy(mst);
   ATtableDestroy(resolvedtable);
   return t; 
}

/*
 |SG_Amb| maintains the ambiguity table, needed for the mapping from
 terms to ambiguity clusters.  On a new ambiguity, it makes a new
 entry; existing ambiguities get expanded, applying filtering wherever
 applicable.
 */

void SG_Amb(parse_table *pt, tree existing, tree new) {
  ATermList newambs;
  ATerm     ambidx;

  IF_STATISTICS(SG_AmbCalls(SG_NR_INC));
  
  ambidx = SG_AmbTable(SG_AMBTBL_LOOKUP_INDEX, (ATerm) existing, NULL);
  /* What the hAck is going on here? What does ATisEmpty((ATermList) ambidx) mean? */
  /* Maybe it has something to do with cycle detection ???? Or whatever. */
  if (!ambidx || ATisEmpty((ATermList) ambidx) ) { 
    /* New ambiguity */
    ambidx = (ATerm) ATmakeInt(SG_MaxNrAmb(SG_NR_INC));
    /* Add mapping for existing term also */
    SG_AmbTable(SG_AMBTBL_ADD_INDEX, (ATerm) existing, ambidx);

    newambs = ATmakeList2((ATerm) existing, (ATerm) new);
  } else {
    /* Expand (or update) existing ambiguity */
    ATermList oldambs;

    oldambs = (ATermList) SG_AmbTable(SG_AMBTBL_LOOKUP_CLUSTER, ambidx, NULL);
    if (ATindexOf(oldambs, (ATerm) new, 0) != -1) {
      return;  /*  Already present?  Done.  */
    }
    newambs = ATinsert(oldambs, (ATerm) new);
  }

  /*   Update ambiguity cluster  */
  SG_AmbTable(SG_AMBTBL_ADD_INDEX, (ATerm) new, ambidx);
  SG_AmbTable(SG_AMBTBL_UPDATE_CLUSTER, ambidx, (ATerm) newambs);

  return;
}

tree SG_SelectOnTopSort(parse_table *pt, tree t, char *sort)
{
  ATermList allambs;
  ATerm amb, prod;
  ATermList newambs = ATempty;
  label l;
  char *prodsort;
  ATerm index;

  index = SG_AmbTable(SG_AMBTBL_LOOKUP_INDEX, (ATerm) t, NULL);
  allambs = (ATermList) SG_AmbTable(SG_AMBTBL_LOOKUP_CLUSTER, index, NULL);

  if (!ATisEmpty(allambs)) {
/* We have at least one tree in the ambiguity cluster
 * and for all trees in this cluster we have to check
 * whether it has the sort that was expected.
 * If all trees are removed a "NULL" tree is returned.
 */
    for (; !ATisEmpty(allambs); allambs = ATgetNext(allambs)) {
      amb = ATgetFirst(allambs);
      l = SG_GetApplProdLabel((tree) amb);
      prod = (ATerm) SG_LookupProduction(pt, l);
      if (ATmatch(prod, 
                  "prod([cf(opt(layout)),cf(sort(<str>)),cf(opt(layout))],"
                  "sort(\"<START>\"),no-attrs)", &prodsort)) {
        if (!strcmp(prodsort, sort)) {
          newambs = ATinsert(newambs, amb);
        }
      }
    }
    SG_AmbTable(SG_AMBTBL_UPDATE_CLUSTER, (ATerm) index, (ATerm) newambs);
    if (ATisEmpty(newambs)) {
      return NULL;
    }
    else {
      return t;
    }
  }
  else {
/* We have only one tree and for this tree we have to check
 * whether it has the sort that was expected.
 * If this tree is removed a "NULL" tree is returned.
 */
    l = SG_GetApplProdLabel((tree) t);
    prod = (ATerm) SG_LookupProduction(pt, l);
    if (ATmatch(prod, 
                "prod([cf(opt(layout)),cf(sort(<str>)),cf(opt(layout))],"
                "sort(\"<START>\"),no-attrs)", &prodsort)) {
      if (!strcmp(prodsort, sort)) {
        return t;
      }
    }
  }
  return NULL;
}
