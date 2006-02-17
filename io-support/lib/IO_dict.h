#ifndef __IO_dict_H
#define __IO_dict_H

#include <aterm2.h>

extern AFun IO_afun0;
extern AFun IO_afun2;
extern AFun IO_afun1;

extern ATerm IO_patternStrConStrCon;
extern ATerm IO_patternStrCharStrChar;
extern ATerm IO_patternSegmentListMany;
extern ATerm IO_patternSegmentListSingle;
extern ATerm IO_patternSegmentListEmpty;
extern ATerm IO_patternSegmentSegment;
extern ATerm IO_patternPathPath;
extern ATerm IO_patternFileFile;

extern void init_IO_dict();

#endif /* __IO_dict_H */
