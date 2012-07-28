/* $Id$ */

#ifndef __RSRC_USAGE_H__
#define __RSRC_USAGE_H__

double STATS_Timer(void);
long STATS_Allocated(void);
void STATS_PageFlt(long *maj, long *min);
long STATS_ResidentSetSize(void);

#endif /* __RSRC_USAGE_H__ */
