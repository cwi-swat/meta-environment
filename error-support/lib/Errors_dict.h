#ifndef __Errors_dict_H
#define __Errors_dict_H

#include <aterm2.h>

extern AFun ME_afun8;
extern AFun ME_afun0;
extern AFun ME_afun11;
extern AFun ME_afun5;
extern AFun ME_afun3;
extern AFun ME_afun9;
extern AFun ME_afun10;
extern AFun ME_afun4;
extern AFun ME_afun13;
extern AFun ME_afun14;
extern AFun ME_afun2;
extern AFun ME_afun7;
extern AFun ME_afun12;
extern AFun ME_afun6;
extern AFun ME_afun1;

extern ATerm ME_patternAreaArea;
extern ATerm ME_patternLocationLocation;
extern ATerm ME_patternSubjectWithLocation;
extern ATerm ME_patternSubjectWithoutLocation;
extern ATerm ME_patternSubjectSubjectListEmpty;
extern ATerm ME_patternSubjectSubjectListMany;
extern ATerm ME_patternSubjectsSubjects;
extern ATerm ME_patternDescriptionDescription;
extern ATerm ME_patternProducerProducer;
extern ATerm ME_patternFatalErrorFatalError;
extern ATerm ME_patternErrorError;
extern ATerm ME_patternWarningWarning;
extern ATerm ME_patternInformationInformation;
extern ATerm ME_patternFeedbackFatalError;
extern ATerm ME_patternFeedbackError;
extern ATerm ME_patternFeedbackWarning;
extern ATerm ME_patternFeedbackInfo;

extern void init_Errors_dict();

#endif /* __Errors_dict_H */
