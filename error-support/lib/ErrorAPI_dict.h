#ifndef __ErrorAPI_dict_H
#define __ErrorAPI_dict_H

#include <aterm2.h>

extern AFun ERR_afun8;
extern AFun ERR_afun4;
extern AFun ERR_afun0;
extern AFun ERR_afun2;
extern AFun ERR_afun7;
extern AFun ERR_afun5;
extern AFun ERR_afun3;
extern AFun ERR_afun1;
extern AFun ERR_afun6;

extern ATerm ERR_patternAreaNoArea;
extern ATerm ERR_patternAreaArea;
extern ATerm ERR_patternLocationNoLocation;
extern ATerm ERR_patternLocationLocation;
extern ATerm ERR_patternSubjectSubject;
extern ATerm ERR_patternSubjectListMany;
extern ATerm ERR_patternSubjectListSingle;
extern ATerm ERR_patternSubjectListEmpty;
extern ATerm ERR_patternFeedbackFatalError;
extern ATerm ERR_patternFeedbackError;
extern ATerm ERR_patternFeedbackWarning;
extern ATerm ERR_patternFeedbackInfo;

extern void init_ErrorAPI_dict();

#endif /* __ErrorAPI_dict_H */
