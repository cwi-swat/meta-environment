#ifndef __Errors_dict_H
#define __Errors_dict_H

#include <aterm2.h>

extern AFun PME_afun8;
extern AFun PME_afun0;
extern AFun PME_afun11;
extern AFun PME_afun5;
extern AFun PME_afun3;
extern AFun PME_afun9;
extern AFun PME_afun10;
extern AFun PME_afun4;
extern AFun PME_afun13;
extern AFun PME_afun14;
extern AFun PME_afun2;
extern AFun PME_afun7;
extern AFun PME_afun12;
extern AFun PME_afun6;
extern AFun PME_afun1;

extern ATerm PME_patternAreaArea;
extern ATerm PME_patternLocationLocation;
extern ATerm PME_patternSubjectWithLocation;
extern ATerm PME_patternSubjectWithoutLocation;
extern ATerm PME_patternSubjectSubjectListEmpty;
extern ATerm PME_patternSubjectSubjectListMany;
extern ATerm PME_patternSubjectsSubjects;
extern ATerm PME_patternDescriptionDescription;
extern ATerm PME_patternProducerProducer;
extern ATerm PME_patternFatalErrorFatalError;
extern ATerm PME_patternErrorError;
extern ATerm PME_patternWarningWarning;
extern ATerm PME_patternInformationInformation;
extern ATerm PME_patternFeedbackFatalError;
extern ATerm PME_patternFeedbackError;
extern ATerm PME_patternFeedbackWarning;
extern ATerm PME_patternFeedbackInfo;

extern void init_Errors_dict();

#endif /* __Errors_dict_H */
