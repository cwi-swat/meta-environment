/*
 $Id:
 */

#include <unistd.h>
#include <string.h>

#include <stdlib.h>
#include <assert.h>

#include "ambi-tables.h"

static ATermTable cluster_table = NULL;  
static ATermTable index_table = NULL;  

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

static ATerm SG_CreateAmbiKey(ATerm key, size_t pos)
{
  return (ATerm) ATmakeList2(key, (ATerm) ATmakeInt(pos));
}  

void SG_AmbiTablesDestroy()
{
  if (cluster_table) {
    ATtableDestroy(cluster_table);
    cluster_table = NULL;
  }
  if (index_table) {
    ATtableDestroy(index_table);
    index_table = NULL;
  }
}

static void SG_AmbiTablesCreate()
{
  if (cluster_table || index_table) {
    SG_AmbiTablesDestroy();
  }
  cluster_table = ATtableCreate(4096, 75);
  index_table = ATtableCreate(4096, 75);
} 

static ATermInt SG_IndexTableGet(ATerm key, size_t pos)
{
  ATermInt idx = NULL;
  ATerm ambikey = SG_CreateAmbiKey(key, pos);

  if (index_table) {
    idx = (ATermInt)ATtableGet(index_table, ambikey);
  }
  return idx;
}

static ATermList SG_ClusterTableGet(ATermInt idx)
{
  ATermList cluster = NULL;

  if (cluster_table && idx) {
    cluster = (ATermList)ATtableGet(cluster_table, (ATerm)idx);
  }
  if (cluster) {
    return cluster;
  }
  else {
     return ATempty;
  }
}

ATermList SG_AmbiTablesGetCluster(ATerm key, size_t pos)
{
  ATermInt idx = SG_IndexTableGet(key, pos);
  return SG_ClusterTableGet(idx);
}

ATermList SG_AmbiTablesGetClusterOnIndex(ATermInt idx)
{
  return SG_ClusterTableGet(idx);
}

ATermInt SG_AmbiTablesGetIndex(ATerm key, size_t pos)
{
  return (ATermInt)SG_IndexTableGet(key, pos);
}

void SG_AmbiTablesAddIndex(ATerm key, size_t pos, ATermInt idx)
{
  ATerm ambikey = SG_CreateAmbiKey(key, pos);

  if (!cluster_table || !index_table) {
    SG_AmbiTablesCreate();
  }
  ATtablePut(index_table, ambikey, (ATerm)idx);
}

void SG_AmbiTablesUpdateCluster(ATermInt idx, ATermList cluster)
{
  if (!cluster_table || !index_table) {
    SG_AmbiTablesCreate();
  }
  ATtablePut(cluster_table, (ATerm)idx, (ATerm)cluster);
}
