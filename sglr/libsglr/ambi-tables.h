/* $Id */

#ifndef _AMBI_CLUSTER_H_
#define _AMBI_CLUSTER_H_  1

#include <aterm2.h>

void      SG_AmbiTablesDestroy();
ATermList SG_AmbiTablesGetCluster(ATerm key, size_t pos);
ATermList SG_AmbiTablesGetClusterOnIndex(ATermInt idx);
ATermInt  SG_AmbiTablesGetIndex(ATerm key, size_t pos);
void      SG_AmbiTablesAddIndex(ATerm key, size_t pos, ATermInt idx);
void      SG_AmbiTablesUpdateCluster(ATermInt idx, ATermList cluster);

#endif  /* _AMBI_CLUSTER_H_ */
