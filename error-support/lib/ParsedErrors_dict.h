#ifndef __ParsedErrors_dict_H
#define __ParsedErrors_dict_H

#include <aterm2.h>

extern AFun PME_afun17;
extern AFun PME_afun3;
extern AFun PME_afun48;
extern AFun PME_afun34;
extern AFun PME_afun37;
extern AFun PME_afun26;
extern AFun PME_afun19;
extern AFun PME_afun2;
extern AFun PME_afun47;
extern AFun PME_afun42;
extern AFun PME_afun25;
extern AFun PME_afun15;
extern AFun PME_afun18;
extern AFun PME_afun31;
extern AFun PME_afun43;
extern AFun PME_afun0;
extern AFun PME_afun38;
extern AFun PME_afun33;
extern AFun PME_afun16;
extern AFun PME_afun10;
extern AFun PME_afun13;
extern AFun PME_afun40;
extern AFun PME_afun14;
extern AFun PME_afun30;
extern AFun PME_afun7;
extern AFun PME_afun35;
extern AFun PME_afun29;
extern AFun PME_afun6;
extern AFun PME_afun1;
extern AFun PME_afun39;
extern AFun PME_afun22;
extern AFun PME_afun44;
extern AFun PME_afun9;
extern AFun PME_afun41;
extern AFun PME_afun12;
extern AFun PME_afun20;
extern AFun PME_afun28;
extern AFun PME_afun8;
extern AFun PME_afun21;
extern AFun PME_afun32;
extern AFun PME_afun11;
extern AFun PME_afun27;
extern AFun PME_afun5;
extern AFun PME_afun4;
extern AFun PME_afun23;
extern AFun PME_afun49;
extern AFun PME_afun45;
extern AFun PME_afun36;
extern AFun PME_afun24;
extern AFun PME_afun46;

extern ATerm PME_patternStartError;
extern ATerm PME_patternStartFatalError;
extern ATerm PME_patternStartWarning;
extern ATerm PME_patternStartInformation;
extern ATerm PME_patternStartProducer;
extern ATerm PME_patternStartDescription;
extern ATerm PME_patternStartFeedback;
extern ATerm PME_patternStartLocation;
extern ATerm PME_patternStartArea;
extern ATerm PME_patternOptLayoutPresent;
extern ATerm PME_patternOptLayoutAbsent;
extern ATerm PME_patternStringString;
extern ATerm PME_patternNatConString;
extern ATerm PME_patternAreaArea;
extern ATerm PME_patternLocationLocation;
extern ATerm PME_patternSubjectWithLocation;
extern ATerm PME_patternSubjectWithoutLocation;
extern ATerm PME_patternSubjectSubjectListMany;
extern ATerm PME_patternSubjectSubjectListSingle;
extern ATerm PME_patternSubjectSubjectListEmpty;
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

extern void init_ParsedErrors_dict();

#endif /* __ParsedErrors_dict_H */
