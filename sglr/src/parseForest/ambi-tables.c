/*$Id$*/

/** \file
 * \ingroup parseForest
 *
 * Ambiguity tables provide a mapping from terms to sets of terms,
 * reflecting the ambiguity relation.  Note that terms can be
 * `prioritized out' or rejected, so that the mapping may or may not
 * yield a set containing the key term.
 *
 * The implementation consists of a two-level mapping, as follows:
 * \li a mapping from terms to indexes (of ambiguity clusters)
 * \li a mapping from indexes to sets of terms (the ambiguity cluster)
 *
 * Maintenance is relatively simple: for new ambiguity clusters, simply
 * create.  Updates to existing ambiguity clusters can be performed
 * simply by looking up the index from one of the terms that share the
 * ambiguity, and update the ambiguity cluster that is found as desired.
 */

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <MEPT-utils.h>

#include "ambi-tables.h"
#include "mainOptions.h"
#include "parserStatistics.h"

static ATermTable cluster_table = NULL;  
static ATermTable index_table = NULL;  

/** 
 * Used to store the positions in the string that are derived in more than one
 * way ie., the positions that are ambiguous.
 */
static Bitmap InputAmbiMap;
static int ambiguityClustersCreated = 0;
 
void SG_CreateInputAmbiMap(int length) {
  InputAmbiMap = BitmapCreate(length+1);
}

void SG_DestroyInputAmbiMap() {
  BitmapDestroy(InputAmbiMap);
}

/** 
 * Determines if there is an ambiguity at the given position in the input 
 * string. This is used as an efficient way to see if there is an ambiguity 
 * before accessing the ambiTable.
 * 
 * \param index the position in the input string
 * 
 * \return 1 if there is an ambiguity in the given position; 0 otherwise
 */
int SG_InputAmbiMapIsSet(int index) {
  return BitmapIsSet(InputAmbiMap, index);
}

static void SG_InputAmbiMapSet(int index) {
  InputAmbiMap = BitmapSet(InputAmbiMap, index);
}

ATerm SG_CreateAmbiArgsKey(PT_Args key, size_t pos) {
  /* note the hack */
  return SG_CreateAmbiTreeKey((PT_Tree) key, pos);
}

ATerm SG_CreateAmbiTreeKey(PT_Tree key, size_t pos) {
  return (ATerm) ATmakeList2((ATerm) key, (ATerm) ATmakeInt(pos));
}  

void SG_AmbiTablesDestroy() {
  if (cluster_table) {
    ATtableDestroy(cluster_table);
    cluster_table = NULL;
  }
  if (index_table) {
    ATtableDestroy(index_table);
    index_table = NULL;
  }
}

static void SG_AmbiTablesCreate() {
  if (cluster_table || index_table) {
    SG_AmbiTablesDestroy();
  }
  cluster_table = ATtableCreate(4096, 75);
  index_table = ATtableCreate(4096, 75);
} 

static ATerm SG_IndexTableGet(PT_Tree key, size_t pos) {
  ATerm idx = NULL;
  ATerm ambikey = SG_CreateAmbiTreeKey(key, pos);

  if (index_table) {
    idx = (ATerm)ATtableGet(index_table, ambikey);
  }
  return idx;
}

static PT_Args SG_ClusterTableGet(ATerm idx) {
  PT_Args cluster = NULL;

  if (cluster_table && idx) {
    cluster = (PT_Args)ATtableGet(cluster_table, idx);
  }
  if (cluster) {
    return cluster;
  }
  else {
     return PT_makeArgsEmpty();
  }
}

/** 
 * Returns the children of an ambiguity node. The first child created is used to
 * index into the table. The list of children returned may include the child 
 * that was used in the key if it was not already filtered.
 * 
 * \param key 
 * \param pos 
 * 
 * \return 
 */
PT_Args SG_AmbiTablesGetCluster(PT_Tree key, size_t pos) {
  ATerm idx = SG_IndexTableGet(key, pos);
  return SG_ClusterTableGet(idx);
}

PT_Args SG_AmbiTablesGetClusterOnIndex(ATerm idx) {
  return SG_ClusterTableGet(idx);
}

ATerm SG_AmbiTablesGetIndex(PT_Tree key, size_t pos) {
  return SG_IndexTableGet(key, pos);
}

static void SG_AmbiTablesAddIndex(PT_Tree key, size_t pos, ATerm idx) {
  ATerm ambikey = SG_CreateAmbiTreeKey(key, pos);

  if (!cluster_table || !index_table) {
    SG_AmbiTablesCreate();
  }
  ATtablePut(index_table, ambikey, idx);
}

void SG_AmbiTablesUpdateCluster(ATerm idx, PT_Args cluster) {
  if (!cluster_table || !index_table) {
    SG_AmbiTablesCreate();
  }
  ATtablePut(cluster_table, idx, (ATerm)cluster);
}

/**
 * Maintains the ambiguity table, needed for the mapping from terms to 
 * ambiguity clusters.  On a new ambiguity, it makes a new entry. The #pos 
 * is needed to differentiate between nodes that are labelled by the same 
 * production, but are used in different derivations.
 * 
 * \param existing the existing parse tree node (may already be an ambiguity)
 * \param new the new parse tree node that may be added to the ambiguity node 
 * if it is not already there
 * \param pos the start position of the sub-string in the input string that the 
 * new node derives 
 */
void SG_CreateAmbCluster(PT_Tree existing, PT_Tree new, size_t pos) {
  PT_Args newambs;
  ATerm  ambidx;

  if (!new) {
    return;
  }
  
  ambidx = SG_AmbiTablesGetIndex(existing, pos);
  if (!ambidx) { 
    /* New ambiguity */
    ambidx = (ATerm) ATmakeInt(ambiguityClustersCreated++);
    SGLR_STATS_incrementCount(SGLR_STATS_ambiguityClustersCreated);
    /* Add mapping for existing term also */
    SG_AmbiTablesAddIndex(existing, pos, ambidx);

    newambs = PT_makeArgsMany(existing, PT_makeArgsSingle(new));
    if (MAIN_getStatsFlag) {
      int newambsLength = PT_getArgsLength(newambs);
      if (SGLR_STATS_maxClusterLength < newambsLength) {
        SGLR_STATS_maxClusterLength = newambsLength;
      }
    }
  }
  else {
    /* Expand (or update) existing ambiguity */
    PT_Args oldambs;

    oldambs = SG_AmbiTablesGetClusterOnIndex(ambidx);
    if (PT_indexOfTreeInArgs(oldambs,  new) != -1) {
      SGLR_STATS_incrementCount(SGLR_STATS_existingAmbiguityClustersFound);
      return;  /*  Already present?  Done.  */
    }
    newambs = PT_makeArgsMany(new, oldambs);
    if (MAIN_getStatsFlag) {
      int newambsLength = PT_getArgsLength(newambs);
      if(SGLR_STATS_maxClusterLength < newambsLength) {
        SGLR_STATS_maxClusterLength = newambsLength;
      }
    }
  }

  /*   Update ambiguity cluster  */
  SG_AmbiTablesAddIndex(new, pos, ambidx);
  SG_AmbiTablesUpdateCluster(ambidx, newambs);
  SG_InputAmbiMapSet(pos);

  return;
}

#if SGLR_COLLECT_STATISTICS
void SG_collectAmbiTableStats(void) {
  if (cluster_table) {
    ATermList keys = ATtableKeys(cluster_table);

    assert(SGLR_STATS_clusterHistogram && "The cluster length histogram has not been initialized!");

    while (!ATisEmpty(keys)) {
      ATerm key = ATgetFirst(keys);
      PT_Args cluster = (PT_Args)ATtableGet(cluster_table, key);
      int clusterLength = PT_getArgsLength(cluster);

      SGLR_STATS_clusterHistogramPut(clusterLength);
      keys = ATgetNext(keys);
    }
  }
}
#else 
void SG_collectAmbiTableStats(void) {
;
}
#endif
