#ifndef __ParsedErrorAPI_dict_H
#define __ParsedErrorAPI_dict_H

#include <aterm2.h>

extern AFun PERR_afun39;
extern AFun PERR_afun17;
extern AFun PERR_afun22;
extern AFun PERR_afun3;
extern AFun PERR_afun9;
extern AFun PERR_afun34;
extern AFun PERR_afun19;
extern AFun PERR_afun26;
extern AFun PERR_afun37;
extern AFun PERR_afun2;
extern AFun PERR_afun41;
extern AFun PERR_afun12;
extern AFun PERR_afun42;
extern AFun PERR_afun15;
extern AFun PERR_afun25;
extern AFun PERR_afun18;
extern AFun PERR_afun20;
extern AFun PERR_afun31;
extern AFun PERR_afun8;
extern AFun PERR_afun28;
extern AFun PERR_afun21;
extern AFun PERR_afun32;
extern AFun PERR_afun0;
extern AFun PERR_afun11;
extern AFun PERR_afun5;
extern AFun PERR_afun27;
extern AFun PERR_afun33;
extern AFun PERR_afun38;
extern AFun PERR_afun16;
extern AFun PERR_afun10;
extern AFun PERR_afun13;
extern AFun PERR_afun4;
extern AFun PERR_afun14;
extern AFun PERR_afun40;
extern AFun PERR_afun23;
extern AFun PERR_afun30;
extern AFun PERR_afun7;
extern AFun PERR_afun36;
extern AFun PERR_afun24;
extern AFun PERR_afun35;
extern AFun PERR_afun29;
extern AFun PERR_afun1;
extern AFun PERR_afun6;

extern ATerm PERR_patternOptLayoutPresent;
extern ATerm PERR_patternOptLayoutAbsent;
extern ATerm PERR_patternStartStrCon;
extern ATerm PERR_patternStartNormal;
extern ATerm PERR_patternStartEscaped;
extern ATerm PERR_patternStartNatCon;
extern ATerm PERR_patternStartSummary;
extern ATerm PERR_patternStartFeedback;
extern ATerm PERR_patternStartSubject;
extern ATerm PERR_patternStartLocation;
extern ATerm PERR_patternStartArea;
extern ATerm PERR_patternAreaNoArea;
extern ATerm PERR_patternAreaArea;
extern ATerm PERR_patternLocationNoLocation;
extern ATerm PERR_patternLocationLocation;
extern ATerm PERR_patternSubjectSubject;
extern ATerm PERR_patternSubjectListMany;
extern ATerm PERR_patternSubjectListSingle;
extern ATerm PERR_patternSubjectListEmpty;
extern ATerm PERR_patternFeedbackFatalError;
extern ATerm PERR_patternFeedbackError;
extern ATerm PERR_patternFeedbackWarning;
extern ATerm PERR_patternFeedbackInfo;
extern ATerm PERR_patternFeedbackListMany;
extern ATerm PERR_patternFeedbackListSingle;
extern ATerm PERR_patternFeedbackListEmpty;
extern ATerm PERR_patternSummaryFeedback;
extern ATerm PERR_patternNatConDefault;
extern ATerm PERR_patternStrConDefault;
extern ATerm PERR_patternEscapedOctal;
extern ATerm PERR_patternEscapedSpecialCharacter;
extern ATerm PERR_patternNormalDefault;

extern void init_ParsedErrorAPI_dict();

#endif /* __ParsedErrorAPI_dict_H */
