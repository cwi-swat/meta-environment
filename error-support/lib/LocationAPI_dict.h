#ifndef __LocationAPI_dict_H
#define __LocationAPI_dict_H

#include <aterm2.h>

extern AFun LOC_afun0;
extern AFun LOC_afun2;
extern AFun LOC_afun3;
extern AFun LOC_afun1;

extern ATerm LOC_patternAreaNoArea;
extern ATerm LOC_patternAreaArea;
extern ATerm LOC_patternLocationNoLocation;
extern ATerm LOC_patternLocationLocation;
extern ATerm LOC_patternNatConNatCon;
extern ATerm LOC_patternStrConStrCon;
extern ATerm LOC_patternEscapedEscaped;
extern ATerm LOC_patternNormalNormal;

extern void init_LocationAPI_dict();

#endif /* __LocationAPI_dict_H */
