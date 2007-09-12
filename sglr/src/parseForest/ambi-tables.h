/* $Id */

/** \file
 * \ingroup parseForest
 */

#ifndef _AMBI_CLUSTER_H_
#define _AMBI_CLUSTER_H_  1

#include <aterm2.h>
#include <MEPT.h>
#include "bitmap.h"

ATerm     SG_CreateAmbiTreeKey(PT_Tree key, size_t pos);
ATerm     SG_CreateAmbiArgsKey(PT_Args key, size_t pos);
void      SG_AmbiTablesDestroy();
PT_Args   SG_AmbiTablesGetCluster(PT_Tree key, size_t pos);
PT_Args   SG_AmbiTablesGetClusterOnIndex(ATerm idx);
ATerm     SG_AmbiTablesGetIndex(PT_Tree key, size_t pos);
void      SG_AmbiTablesUpdateCluster(ATerm idx, PT_Args cluster);

void      SG_CreateAmbCluster(PT_Tree existing, PT_Tree new, size_t pos);

void      SG_CreateInputAmbiMap(int length);
void      SG_DestroyInputAmbiMap();
int       SG_InputAmbiMapIsSet(int index);
void      SG_collectAmbiTableStats(void);

#endif  /* _AMBI_CLUSTER_H_ */
