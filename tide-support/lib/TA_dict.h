#ifndef __TA_dict_H
#define __TA_dict_H

#include <aterm2.h>

extern AFun TA_afun4;
extern AFun TA_afun0;
extern AFun TA_afun2;
extern AFun TA_afun7;
extern AFun TA_afun5;
extern AFun TA_afun3;
extern AFun TA_afun1;
extern AFun TA_afun6;

extern ATerm TA_patternPortStarted;
extern ATerm TA_patternPortStopped;
extern ATerm TA_patternPortStep;
extern ATerm TA_patternLocationUnknown;
extern ATerm TA_patternLocationLineCol;
extern ATerm TA_patternLocationArea;
extern ATerm TA_patternLocationLine;

extern void init_TA_dict();

#endif /* __TA_dict_H */
