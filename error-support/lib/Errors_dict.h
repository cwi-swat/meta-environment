#ifndef __Errors_dict_H
#define __Errors_dict_H

#include <aterm2.h>

extern AFun ME_afun8;
extern AFun ME_afun4;
extern AFun ME_afun0;
extern AFun ME_afun2;
extern AFun ME_afun7;
extern AFun ME_afun5;
extern AFun ME_afun3;
extern AFun ME_afun1;
extern AFun ME_afun6;

extern ATerm ME_patternAreaNoArea;
extern ATerm ME_patternAreaArea;
extern ATerm ME_patternLocationLocation;
extern ATerm ME_patternSubjectUnlocatable;
extern ATerm ME_patternSubjectLocatable;
extern ATerm ME_patternSubjectListMany;
extern ATerm ME_patternSubjectListSingle;
extern ATerm ME_patternSubjectListEmpty;
extern ATerm ME_patternFeedbackFatalError;
extern ATerm ME_patternFeedbackError;
extern ATerm ME_patternFeedbackWarning;
extern ATerm ME_patternFeedbackInfo;

extern void init_Errors_dict();

#endif /* __Errors_dict_H */
