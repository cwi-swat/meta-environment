#ifndef _PARSEDERRORS_H
#define _PARSEDERRORS_H

/*{{{  includes */

#include <aterm1.h>
#include "ParsedErrors_dict.h"

/*}}}  */

/*{{{  prologue */

typedef struct _PME_CHARLIST *PME_CHARLIST;

ATbool PME_isValidCHARLIST(PME_CHARLIST arg);
ATbool PME_isCHARLISTString(PME_CHARLIST arg);
char*  PME_getCHARLISTString(PME_CHARLIST arg);
PME_CHARLIST  PME_setCHARLISTString(PME_CHARLIST arg, char *str);
ATerm  PME_CHARLISTToTerm(PME_CHARLIST arg);
PME_CHARLIST PME_CHARLISTFromTerm(ATerm trm);
PME_CHARLIST PME_makeCHARLISTString(char *str);

typedef ATerm PME_String;
typedef ATerm PME_NatCon;

/*}}}  */
/*{{{  typedefs */

typedef struct _PME_Feedback *PME_Feedback;
typedef struct _PME_Information *PME_Information;
typedef struct _PME_Warning *PME_Warning;
typedef struct _PME_Error *PME_Error;
typedef struct _PME_FatalError *PME_FatalError;
typedef struct _PME_Producer *PME_Producer;
typedef struct _PME_Description *PME_Description;
typedef struct _PME_Subjects *PME_Subjects;
typedef struct _PME_SubjectSubjectList *PME_SubjectSubjectList;
typedef struct _PME_Subject *PME_Subject;
typedef struct _PME_Location *PME_Location;
typedef struct _PME_Area *PME_Area;
typedef struct _PME_Start *PME_Start;
typedef struct _PME_OptLayout *PME_OptLayout;

/*}}}  */

void PME_initParsedErrorsApi(void);

/*{{{  term conversion functions */

PME_Feedback PME_FeedbackFromTerm(ATerm t);
ATerm PME_FeedbackToTerm(PME_Feedback arg);
PME_Information PME_InformationFromTerm(ATerm t);
ATerm PME_InformationToTerm(PME_Information arg);
PME_Warning PME_WarningFromTerm(ATerm t);
ATerm PME_WarningToTerm(PME_Warning arg);
PME_Error PME_ErrorFromTerm(ATerm t);
ATerm PME_ErrorToTerm(PME_Error arg);
PME_FatalError PME_FatalErrorFromTerm(ATerm t);
ATerm PME_FatalErrorToTerm(PME_FatalError arg);
PME_Producer PME_ProducerFromTerm(ATerm t);
ATerm PME_ProducerToTerm(PME_Producer arg);
PME_Description PME_DescriptionFromTerm(ATerm t);
ATerm PME_DescriptionToTerm(PME_Description arg);
PME_Subjects PME_SubjectsFromTerm(ATerm t);
ATerm PME_SubjectsToTerm(PME_Subjects arg);
PME_SubjectSubjectList PME_SubjectSubjectListFromTerm(ATerm t);
ATerm PME_SubjectSubjectListToTerm(PME_SubjectSubjectList arg);
PME_Subject PME_SubjectFromTerm(ATerm t);
ATerm PME_SubjectToTerm(PME_Subject arg);
PME_Location PME_LocationFromTerm(ATerm t);
ATerm PME_LocationToTerm(PME_Location arg);
PME_Area PME_AreaFromTerm(ATerm t);
ATerm PME_AreaToTerm(PME_Area arg);
PME_Start PME_StartFromTerm(ATerm t);
ATerm PME_StartToTerm(PME_Start arg);
PME_OptLayout PME_OptLayoutFromTerm(ATerm t);
ATerm PME_OptLayoutToTerm(PME_OptLayout arg);

/*}}}  */
/*{{{  list functions */

int PME_getSubjectSubjectListLength (PME_SubjectSubjectList arg);
PME_SubjectSubjectList PME_appendSubjectSubjectList(PME_SubjectSubjectList arg0, PME_OptLayout wsAfterFirst, char* sep, PME_OptLayout wsAfterSep, PME_Subject arg1);
PME_SubjectSubjectList PME_concatSubjectSubjectList(PME_SubjectSubjectList arg0, PME_OptLayout wsAfterFirst, char* sep, PME_OptLayout wsAfterSep, PME_SubjectSubjectList arg1);
PME_SubjectSubjectList reverseSubjectSubjectList(PME_SubjectSubjectList arg);

/*}}}  */
/*{{{  constructors */

PME_Feedback PME_makeFeedbackInfo(PME_Information Information);
PME_Feedback PME_makeFeedbackWarning(PME_Warning Warning);
PME_Feedback PME_makeFeedbackError(PME_Error Error);
PME_Feedback PME_makeFeedbackFatalError(PME_FatalError FatalError);
PME_Information PME_makeInformationInformation(PME_OptLayout wsAfterInformation, PME_OptLayout wsAfterParenOpen, PME_String id, PME_OptLayout wsAfterId, PME_OptLayout wsAfterC1, PME_Producer producer, PME_OptLayout wsAfterProducer, PME_OptLayout wsAfterC2, PME_Description description, PME_OptLayout wsAfterDescription, PME_OptLayout wsAfterC3, PME_Subjects subjects, PME_OptLayout wsAfterSubjects);
PME_Warning PME_makeWarningWarning(PME_OptLayout wsAfterWarning, PME_OptLayout wsAfterParenOpen, PME_String id, PME_OptLayout wsAfterId, PME_OptLayout wsAfterC1, PME_Producer producer, PME_OptLayout wsAfterProducer, PME_OptLayout wsAfterC2, PME_Description description, PME_OptLayout wsAfterDescription, PME_OptLayout wsAfterC3, PME_Subjects subjects, PME_OptLayout wsAfterSubjects);
PME_Error PME_makeErrorError(PME_OptLayout wsAfterError, PME_OptLayout wsAfterParenOpen, PME_String id, PME_OptLayout wsAfterId, PME_OptLayout wsAfterC1, PME_Producer producer, PME_OptLayout wsAfterProducer, PME_OptLayout wsAfterC2, PME_Description description, PME_OptLayout wsAfterDescription, PME_OptLayout wsAfterC3, PME_Subjects subjects, PME_OptLayout wsAfterSubjects);
PME_FatalError PME_makeFatalErrorFatalError(PME_OptLayout wsAfterFatalError, PME_OptLayout wsAfterParenOpen, PME_String id, PME_OptLayout wsAfterId, PME_OptLayout wsAfterC1, PME_Producer producer, PME_OptLayout wsAfterProducer, PME_OptLayout wsAfterC2, PME_Description description, PME_OptLayout wsAfterDescription, PME_OptLayout wsAfterC3, PME_Subjects subjects, PME_OptLayout wsAfterSubjects);
PME_Producer PME_makeProducerProducer(PME_OptLayout wsAfterProducer, PME_OptLayout wsAfterParenOpen, PME_String id, PME_OptLayout wsAfterId, PME_OptLayout wsAfterComma, PME_String type, PME_OptLayout wsAfterType);
PME_Description PME_makeDescriptionDescription(PME_OptLayout wsAfterDescription, PME_OptLayout wsAfterParenOpen, PME_String String, PME_OptLayout wsAfterString);
PME_Subjects PME_makeSubjectsSubjects(PME_OptLayout wsAfterBracketOpen, PME_SubjectSubjectList subjectList, PME_OptLayout wsAfterSubjectList);
PME_SubjectSubjectList PME_makeSubjectSubjectListMany(PME_Subject head, PME_OptLayout wsAfterFirst, char* sep, PME_OptLayout wsAfterSep, PME_SubjectSubjectList tail);
PME_SubjectSubjectList PME_makeSubjectSubjectListEmpty();
PME_SubjectSubjectList PME_makeSubjectSubjectListSingle(PME_Subject head);
PME_Subject PME_makeSubjectWithoutLocation(PME_OptLayout wsAfterSubject, PME_OptLayout wsAfterParenOpen, PME_String id, PME_OptLayout wsAfterId, PME_OptLayout wsAfterComma, PME_Location location, PME_OptLayout wsAfterLocation);
PME_Subject PME_makeSubjectWithLocation(PME_OptLayout wsAfterSubject, PME_OptLayout wsAfterParenOpen, PME_String id, PME_OptLayout wsAfterId);
PME_Location PME_makeLocationLocation(PME_OptLayout wsAfterLocation, PME_OptLayout wsAfterParenOpen, PME_String file, PME_OptLayout wsAfterFile, PME_OptLayout wsAfterComma, PME_Area area, PME_OptLayout wsAfterArea);
PME_Area PME_makeAreaArea(PME_OptLayout wsAfterArea, PME_OptLayout wsAfterParenOpen, PME_NatCon startLine, PME_OptLayout wsAfterStartLine, PME_OptLayout wsAfterC1, PME_NatCon startColumn, PME_OptLayout wsAfterStartColumn, PME_OptLayout wsAfterC2, PME_NatCon endLine, PME_OptLayout wsAfterEndLine, PME_OptLayout wsAfterC3, PME_NatCon endColumn, PME_OptLayout wsAfterEndColumn, PME_OptLayout wsAfterC4, PME_NatCon startOffset, PME_OptLayout wsAfterStartOffset, PME_OptLayout wsAfterC5, PME_NatCon endOffset, PME_OptLayout wsAfterEndOffset);
PME_Start PME_makeStartArea(PME_OptLayout wsBefore, PME_Area topArea, PME_OptLayout wsAfter, int ambCnt);
PME_Start PME_makeStartLocation(PME_OptLayout wsBefore, PME_Location topLocation, PME_OptLayout wsAfter, int ambCnt);
PME_Start PME_makeStartFeedback(PME_OptLayout wsBefore, PME_Feedback topFeedback, PME_OptLayout wsAfter, int ambCnt);
PME_Start PME_makeStartDescription(PME_OptLayout wsBefore, PME_Description topDescription, PME_OptLayout wsAfter, int ambCnt);
PME_Start PME_makeStartProducer(PME_OptLayout wsBefore, PME_Producer topProducer, PME_OptLayout wsAfter, int ambCnt);
PME_Start PME_makeStartInformation(PME_OptLayout wsBefore, PME_Information topInformation, PME_OptLayout wsAfter, int ambCnt);
PME_Start PME_makeStartWarning(PME_OptLayout wsBefore, PME_Warning topWarning, PME_OptLayout wsAfter, int ambCnt);
PME_Start PME_makeStartFatalError(PME_OptLayout wsBefore, PME_FatalError topFatalError, PME_OptLayout wsAfter, int ambCnt);
PME_Start PME_makeStartError(PME_OptLayout wsBefore, PME_Error topError, PME_OptLayout wsAfter, int ambCnt);
PME_OptLayout PME_makeOptLayoutAbsent();
PME_OptLayout PME_makeOptLayoutPresent(PME_CHARLIST chars);

/*}}}  */
/*{{{  equality functions */

ATbool PME_isEqualFeedback(PME_Feedback arg0, PME_Feedback arg1);
ATbool PME_isEqualInformation(PME_Information arg0, PME_Information arg1);
ATbool PME_isEqualWarning(PME_Warning arg0, PME_Warning arg1);
ATbool PME_isEqualError(PME_Error arg0, PME_Error arg1);
ATbool PME_isEqualFatalError(PME_FatalError arg0, PME_FatalError arg1);
ATbool PME_isEqualProducer(PME_Producer arg0, PME_Producer arg1);
ATbool PME_isEqualDescription(PME_Description arg0, PME_Description arg1);
ATbool PME_isEqualSubjects(PME_Subjects arg0, PME_Subjects arg1);
ATbool PME_isEqualSubjectSubjectList(PME_SubjectSubjectList arg0, PME_SubjectSubjectList arg1);
ATbool PME_isEqualSubject(PME_Subject arg0, PME_Subject arg1);
ATbool PME_isEqualLocation(PME_Location arg0, PME_Location arg1);
ATbool PME_isEqualArea(PME_Area arg0, PME_Area arg1);
ATbool PME_isEqualStart(PME_Start arg0, PME_Start arg1);
ATbool PME_isEqualOptLayout(PME_OptLayout arg0, PME_OptLayout arg1);

/*}}}  */
/*{{{  PME_Feedback accessors */

ATbool PME_isValidFeedback(PME_Feedback arg);
inline ATbool PME_isFeedbackInfo(PME_Feedback arg);
inline ATbool PME_isFeedbackWarning(PME_Feedback arg);
inline ATbool PME_isFeedbackError(PME_Feedback arg);
inline ATbool PME_isFeedbackFatalError(PME_Feedback arg);
ATbool PME_hasFeedbackInformation(PME_Feedback arg);
PME_Information PME_getFeedbackInformation(PME_Feedback arg);
PME_Feedback PME_setFeedbackInformation(PME_Feedback arg, PME_Information Information);
ATbool PME_hasFeedbackWarning(PME_Feedback arg);
PME_Warning PME_getFeedbackWarning(PME_Feedback arg);
PME_Feedback PME_setFeedbackWarning(PME_Feedback arg, PME_Warning Warning);
ATbool PME_hasFeedbackError(PME_Feedback arg);
PME_Error PME_getFeedbackError(PME_Feedback arg);
PME_Feedback PME_setFeedbackError(PME_Feedback arg, PME_Error Error);
ATbool PME_hasFeedbackFatalError(PME_Feedback arg);
PME_FatalError PME_getFeedbackFatalError(PME_Feedback arg);
PME_Feedback PME_setFeedbackFatalError(PME_Feedback arg, PME_FatalError FatalError);

/*}}}  */
/*{{{  PME_Information accessors */

ATbool PME_isValidInformation(PME_Information arg);
inline ATbool PME_isInformationInformation(PME_Information arg);
ATbool PME_hasInformationWsAfterInformation(PME_Information arg);
PME_OptLayout PME_getInformationWsAfterInformation(PME_Information arg);
PME_Information PME_setInformationWsAfterInformation(PME_Information arg, PME_OptLayout wsAfterInformation);
ATbool PME_hasInformationWsAfterParenOpen(PME_Information arg);
PME_OptLayout PME_getInformationWsAfterParenOpen(PME_Information arg);
PME_Information PME_setInformationWsAfterParenOpen(PME_Information arg, PME_OptLayout wsAfterParenOpen);
ATbool PME_hasInformationId(PME_Information arg);
PME_String PME_getInformationId(PME_Information arg);
PME_Information PME_setInformationId(PME_Information arg, PME_String id);
ATbool PME_hasInformationWsAfterId(PME_Information arg);
PME_OptLayout PME_getInformationWsAfterId(PME_Information arg);
PME_Information PME_setInformationWsAfterId(PME_Information arg, PME_OptLayout wsAfterId);
ATbool PME_hasInformationWsAfterC1(PME_Information arg);
PME_OptLayout PME_getInformationWsAfterC1(PME_Information arg);
PME_Information PME_setInformationWsAfterC1(PME_Information arg, PME_OptLayout wsAfterC1);
ATbool PME_hasInformationProducer(PME_Information arg);
PME_Producer PME_getInformationProducer(PME_Information arg);
PME_Information PME_setInformationProducer(PME_Information arg, PME_Producer producer);
ATbool PME_hasInformationWsAfterProducer(PME_Information arg);
PME_OptLayout PME_getInformationWsAfterProducer(PME_Information arg);
PME_Information PME_setInformationWsAfterProducer(PME_Information arg, PME_OptLayout wsAfterProducer);
ATbool PME_hasInformationWsAfterC2(PME_Information arg);
PME_OptLayout PME_getInformationWsAfterC2(PME_Information arg);
PME_Information PME_setInformationWsAfterC2(PME_Information arg, PME_OptLayout wsAfterC2);
ATbool PME_hasInformationDescription(PME_Information arg);
PME_Description PME_getInformationDescription(PME_Information arg);
PME_Information PME_setInformationDescription(PME_Information arg, PME_Description description);
ATbool PME_hasInformationWsAfterDescription(PME_Information arg);
PME_OptLayout PME_getInformationWsAfterDescription(PME_Information arg);
PME_Information PME_setInformationWsAfterDescription(PME_Information arg, PME_OptLayout wsAfterDescription);
ATbool PME_hasInformationWsAfterC3(PME_Information arg);
PME_OptLayout PME_getInformationWsAfterC3(PME_Information arg);
PME_Information PME_setInformationWsAfterC3(PME_Information arg, PME_OptLayout wsAfterC3);
ATbool PME_hasInformationSubjects(PME_Information arg);
PME_Subjects PME_getInformationSubjects(PME_Information arg);
PME_Information PME_setInformationSubjects(PME_Information arg, PME_Subjects subjects);
ATbool PME_hasInformationWsAfterSubjects(PME_Information arg);
PME_OptLayout PME_getInformationWsAfterSubjects(PME_Information arg);
PME_Information PME_setInformationWsAfterSubjects(PME_Information arg, PME_OptLayout wsAfterSubjects);

/*}}}  */
/*{{{  PME_Warning accessors */

ATbool PME_isValidWarning(PME_Warning arg);
inline ATbool PME_isWarningWarning(PME_Warning arg);
ATbool PME_hasWarningWsAfterWarning(PME_Warning arg);
PME_OptLayout PME_getWarningWsAfterWarning(PME_Warning arg);
PME_Warning PME_setWarningWsAfterWarning(PME_Warning arg, PME_OptLayout wsAfterWarning);
ATbool PME_hasWarningWsAfterParenOpen(PME_Warning arg);
PME_OptLayout PME_getWarningWsAfterParenOpen(PME_Warning arg);
PME_Warning PME_setWarningWsAfterParenOpen(PME_Warning arg, PME_OptLayout wsAfterParenOpen);
ATbool PME_hasWarningId(PME_Warning arg);
PME_String PME_getWarningId(PME_Warning arg);
PME_Warning PME_setWarningId(PME_Warning arg, PME_String id);
ATbool PME_hasWarningWsAfterId(PME_Warning arg);
PME_OptLayout PME_getWarningWsAfterId(PME_Warning arg);
PME_Warning PME_setWarningWsAfterId(PME_Warning arg, PME_OptLayout wsAfterId);
ATbool PME_hasWarningWsAfterC1(PME_Warning arg);
PME_OptLayout PME_getWarningWsAfterC1(PME_Warning arg);
PME_Warning PME_setWarningWsAfterC1(PME_Warning arg, PME_OptLayout wsAfterC1);
ATbool PME_hasWarningProducer(PME_Warning arg);
PME_Producer PME_getWarningProducer(PME_Warning arg);
PME_Warning PME_setWarningProducer(PME_Warning arg, PME_Producer producer);
ATbool PME_hasWarningWsAfterProducer(PME_Warning arg);
PME_OptLayout PME_getWarningWsAfterProducer(PME_Warning arg);
PME_Warning PME_setWarningWsAfterProducer(PME_Warning arg, PME_OptLayout wsAfterProducer);
ATbool PME_hasWarningWsAfterC2(PME_Warning arg);
PME_OptLayout PME_getWarningWsAfterC2(PME_Warning arg);
PME_Warning PME_setWarningWsAfterC2(PME_Warning arg, PME_OptLayout wsAfterC2);
ATbool PME_hasWarningDescription(PME_Warning arg);
PME_Description PME_getWarningDescription(PME_Warning arg);
PME_Warning PME_setWarningDescription(PME_Warning arg, PME_Description description);
ATbool PME_hasWarningWsAfterDescription(PME_Warning arg);
PME_OptLayout PME_getWarningWsAfterDescription(PME_Warning arg);
PME_Warning PME_setWarningWsAfterDescription(PME_Warning arg, PME_OptLayout wsAfterDescription);
ATbool PME_hasWarningWsAfterC3(PME_Warning arg);
PME_OptLayout PME_getWarningWsAfterC3(PME_Warning arg);
PME_Warning PME_setWarningWsAfterC3(PME_Warning arg, PME_OptLayout wsAfterC3);
ATbool PME_hasWarningSubjects(PME_Warning arg);
PME_Subjects PME_getWarningSubjects(PME_Warning arg);
PME_Warning PME_setWarningSubjects(PME_Warning arg, PME_Subjects subjects);
ATbool PME_hasWarningWsAfterSubjects(PME_Warning arg);
PME_OptLayout PME_getWarningWsAfterSubjects(PME_Warning arg);
PME_Warning PME_setWarningWsAfterSubjects(PME_Warning arg, PME_OptLayout wsAfterSubjects);

/*}}}  */
/*{{{  PME_Error accessors */

ATbool PME_isValidError(PME_Error arg);
inline ATbool PME_isErrorError(PME_Error arg);
ATbool PME_hasErrorWsAfterError(PME_Error arg);
PME_OptLayout PME_getErrorWsAfterError(PME_Error arg);
PME_Error PME_setErrorWsAfterError(PME_Error arg, PME_OptLayout wsAfterError);
ATbool PME_hasErrorWsAfterParenOpen(PME_Error arg);
PME_OptLayout PME_getErrorWsAfterParenOpen(PME_Error arg);
PME_Error PME_setErrorWsAfterParenOpen(PME_Error arg, PME_OptLayout wsAfterParenOpen);
ATbool PME_hasErrorId(PME_Error arg);
PME_String PME_getErrorId(PME_Error arg);
PME_Error PME_setErrorId(PME_Error arg, PME_String id);
ATbool PME_hasErrorWsAfterId(PME_Error arg);
PME_OptLayout PME_getErrorWsAfterId(PME_Error arg);
PME_Error PME_setErrorWsAfterId(PME_Error arg, PME_OptLayout wsAfterId);
ATbool PME_hasErrorWsAfterC1(PME_Error arg);
PME_OptLayout PME_getErrorWsAfterC1(PME_Error arg);
PME_Error PME_setErrorWsAfterC1(PME_Error arg, PME_OptLayout wsAfterC1);
ATbool PME_hasErrorProducer(PME_Error arg);
PME_Producer PME_getErrorProducer(PME_Error arg);
PME_Error PME_setErrorProducer(PME_Error arg, PME_Producer producer);
ATbool PME_hasErrorWsAfterProducer(PME_Error arg);
PME_OptLayout PME_getErrorWsAfterProducer(PME_Error arg);
PME_Error PME_setErrorWsAfterProducer(PME_Error arg, PME_OptLayout wsAfterProducer);
ATbool PME_hasErrorWsAfterC2(PME_Error arg);
PME_OptLayout PME_getErrorWsAfterC2(PME_Error arg);
PME_Error PME_setErrorWsAfterC2(PME_Error arg, PME_OptLayout wsAfterC2);
ATbool PME_hasErrorDescription(PME_Error arg);
PME_Description PME_getErrorDescription(PME_Error arg);
PME_Error PME_setErrorDescription(PME_Error arg, PME_Description description);
ATbool PME_hasErrorWsAfterDescription(PME_Error arg);
PME_OptLayout PME_getErrorWsAfterDescription(PME_Error arg);
PME_Error PME_setErrorWsAfterDescription(PME_Error arg, PME_OptLayout wsAfterDescription);
ATbool PME_hasErrorWsAfterC3(PME_Error arg);
PME_OptLayout PME_getErrorWsAfterC3(PME_Error arg);
PME_Error PME_setErrorWsAfterC3(PME_Error arg, PME_OptLayout wsAfterC3);
ATbool PME_hasErrorSubjects(PME_Error arg);
PME_Subjects PME_getErrorSubjects(PME_Error arg);
PME_Error PME_setErrorSubjects(PME_Error arg, PME_Subjects subjects);
ATbool PME_hasErrorWsAfterSubjects(PME_Error arg);
PME_OptLayout PME_getErrorWsAfterSubjects(PME_Error arg);
PME_Error PME_setErrorWsAfterSubjects(PME_Error arg, PME_OptLayout wsAfterSubjects);

/*}}}  */
/*{{{  PME_FatalError accessors */

ATbool PME_isValidFatalError(PME_FatalError arg);
inline ATbool PME_isFatalErrorFatalError(PME_FatalError arg);
ATbool PME_hasFatalErrorWsAfterFatalError(PME_FatalError arg);
PME_OptLayout PME_getFatalErrorWsAfterFatalError(PME_FatalError arg);
PME_FatalError PME_setFatalErrorWsAfterFatalError(PME_FatalError arg, PME_OptLayout wsAfterFatalError);
ATbool PME_hasFatalErrorWsAfterParenOpen(PME_FatalError arg);
PME_OptLayout PME_getFatalErrorWsAfterParenOpen(PME_FatalError arg);
PME_FatalError PME_setFatalErrorWsAfterParenOpen(PME_FatalError arg, PME_OptLayout wsAfterParenOpen);
ATbool PME_hasFatalErrorId(PME_FatalError arg);
PME_String PME_getFatalErrorId(PME_FatalError arg);
PME_FatalError PME_setFatalErrorId(PME_FatalError arg, PME_String id);
ATbool PME_hasFatalErrorWsAfterId(PME_FatalError arg);
PME_OptLayout PME_getFatalErrorWsAfterId(PME_FatalError arg);
PME_FatalError PME_setFatalErrorWsAfterId(PME_FatalError arg, PME_OptLayout wsAfterId);
ATbool PME_hasFatalErrorWsAfterC1(PME_FatalError arg);
PME_OptLayout PME_getFatalErrorWsAfterC1(PME_FatalError arg);
PME_FatalError PME_setFatalErrorWsAfterC1(PME_FatalError arg, PME_OptLayout wsAfterC1);
ATbool PME_hasFatalErrorProducer(PME_FatalError arg);
PME_Producer PME_getFatalErrorProducer(PME_FatalError arg);
PME_FatalError PME_setFatalErrorProducer(PME_FatalError arg, PME_Producer producer);
ATbool PME_hasFatalErrorWsAfterProducer(PME_FatalError arg);
PME_OptLayout PME_getFatalErrorWsAfterProducer(PME_FatalError arg);
PME_FatalError PME_setFatalErrorWsAfterProducer(PME_FatalError arg, PME_OptLayout wsAfterProducer);
ATbool PME_hasFatalErrorWsAfterC2(PME_FatalError arg);
PME_OptLayout PME_getFatalErrorWsAfterC2(PME_FatalError arg);
PME_FatalError PME_setFatalErrorWsAfterC2(PME_FatalError arg, PME_OptLayout wsAfterC2);
ATbool PME_hasFatalErrorDescription(PME_FatalError arg);
PME_Description PME_getFatalErrorDescription(PME_FatalError arg);
PME_FatalError PME_setFatalErrorDescription(PME_FatalError arg, PME_Description description);
ATbool PME_hasFatalErrorWsAfterDescription(PME_FatalError arg);
PME_OptLayout PME_getFatalErrorWsAfterDescription(PME_FatalError arg);
PME_FatalError PME_setFatalErrorWsAfterDescription(PME_FatalError arg, PME_OptLayout wsAfterDescription);
ATbool PME_hasFatalErrorWsAfterC3(PME_FatalError arg);
PME_OptLayout PME_getFatalErrorWsAfterC3(PME_FatalError arg);
PME_FatalError PME_setFatalErrorWsAfterC3(PME_FatalError arg, PME_OptLayout wsAfterC3);
ATbool PME_hasFatalErrorSubjects(PME_FatalError arg);
PME_Subjects PME_getFatalErrorSubjects(PME_FatalError arg);
PME_FatalError PME_setFatalErrorSubjects(PME_FatalError arg, PME_Subjects subjects);
ATbool PME_hasFatalErrorWsAfterSubjects(PME_FatalError arg);
PME_OptLayout PME_getFatalErrorWsAfterSubjects(PME_FatalError arg);
PME_FatalError PME_setFatalErrorWsAfterSubjects(PME_FatalError arg, PME_OptLayout wsAfterSubjects);

/*}}}  */
/*{{{  PME_Producer accessors */

ATbool PME_isValidProducer(PME_Producer arg);
inline ATbool PME_isProducerProducer(PME_Producer arg);
ATbool PME_hasProducerWsAfterProducer(PME_Producer arg);
PME_OptLayout PME_getProducerWsAfterProducer(PME_Producer arg);
PME_Producer PME_setProducerWsAfterProducer(PME_Producer arg, PME_OptLayout wsAfterProducer);
ATbool PME_hasProducerWsAfterParenOpen(PME_Producer arg);
PME_OptLayout PME_getProducerWsAfterParenOpen(PME_Producer arg);
PME_Producer PME_setProducerWsAfterParenOpen(PME_Producer arg, PME_OptLayout wsAfterParenOpen);
ATbool PME_hasProducerId(PME_Producer arg);
PME_String PME_getProducerId(PME_Producer arg);
PME_Producer PME_setProducerId(PME_Producer arg, PME_String id);
ATbool PME_hasProducerWsAfterId(PME_Producer arg);
PME_OptLayout PME_getProducerWsAfterId(PME_Producer arg);
PME_Producer PME_setProducerWsAfterId(PME_Producer arg, PME_OptLayout wsAfterId);
ATbool PME_hasProducerWsAfterComma(PME_Producer arg);
PME_OptLayout PME_getProducerWsAfterComma(PME_Producer arg);
PME_Producer PME_setProducerWsAfterComma(PME_Producer arg, PME_OptLayout wsAfterComma);
ATbool PME_hasProducerType(PME_Producer arg);
PME_String PME_getProducerType(PME_Producer arg);
PME_Producer PME_setProducerType(PME_Producer arg, PME_String type);
ATbool PME_hasProducerWsAfterType(PME_Producer arg);
PME_OptLayout PME_getProducerWsAfterType(PME_Producer arg);
PME_Producer PME_setProducerWsAfterType(PME_Producer arg, PME_OptLayout wsAfterType);

/*}}}  */
/*{{{  PME_Description accessors */

ATbool PME_isValidDescription(PME_Description arg);
inline ATbool PME_isDescriptionDescription(PME_Description arg);
ATbool PME_hasDescriptionWsAfterDescription(PME_Description arg);
PME_OptLayout PME_getDescriptionWsAfterDescription(PME_Description arg);
PME_Description PME_setDescriptionWsAfterDescription(PME_Description arg, PME_OptLayout wsAfterDescription);
ATbool PME_hasDescriptionWsAfterParenOpen(PME_Description arg);
PME_OptLayout PME_getDescriptionWsAfterParenOpen(PME_Description arg);
PME_Description PME_setDescriptionWsAfterParenOpen(PME_Description arg, PME_OptLayout wsAfterParenOpen);
ATbool PME_hasDescriptionString(PME_Description arg);
PME_String PME_getDescriptionString(PME_Description arg);
PME_Description PME_setDescriptionString(PME_Description arg, PME_String String);
ATbool PME_hasDescriptionWsAfterString(PME_Description arg);
PME_OptLayout PME_getDescriptionWsAfterString(PME_Description arg);
PME_Description PME_setDescriptionWsAfterString(PME_Description arg, PME_OptLayout wsAfterString);

/*}}}  */
/*{{{  PME_Subjects accessors */

ATbool PME_isValidSubjects(PME_Subjects arg);
inline ATbool PME_isSubjectsSubjects(PME_Subjects arg);
ATbool PME_hasSubjectsWsAfterBracketOpen(PME_Subjects arg);
PME_OptLayout PME_getSubjectsWsAfterBracketOpen(PME_Subjects arg);
PME_Subjects PME_setSubjectsWsAfterBracketOpen(PME_Subjects arg, PME_OptLayout wsAfterBracketOpen);
ATbool PME_hasSubjectsSubjectList(PME_Subjects arg);
PME_SubjectSubjectList PME_getSubjectsSubjectList(PME_Subjects arg);
PME_Subjects PME_setSubjectsSubjectList(PME_Subjects arg, PME_SubjectSubjectList subjectList);
ATbool PME_hasSubjectsWsAfterSubjectList(PME_Subjects arg);
PME_OptLayout PME_getSubjectsWsAfterSubjectList(PME_Subjects arg);
PME_Subjects PME_setSubjectsWsAfterSubjectList(PME_Subjects arg, PME_OptLayout wsAfterSubjectList);

/*}}}  */
/*{{{  PME_SubjectSubjectList accessors */

ATbool PME_isValidSubjectSubjectList(PME_SubjectSubjectList arg);
inline ATbool PME_isSubjectSubjectListMany(PME_SubjectSubjectList arg);
inline ATbool PME_isSubjectSubjectListEmpty(PME_SubjectSubjectList arg);
inline ATbool PME_isSubjectSubjectListSingle(PME_SubjectSubjectList arg);
ATbool PME_hasSubjectSubjectListHead(PME_SubjectSubjectList arg);
PME_Subject PME_getSubjectSubjectListHead(PME_SubjectSubjectList arg);
PME_SubjectSubjectList PME_setSubjectSubjectListHead(PME_SubjectSubjectList arg, PME_Subject head);
ATbool PME_hasSubjectSubjectListWsAfterFirst(PME_SubjectSubjectList arg);
PME_OptLayout PME_getSubjectSubjectListWsAfterFirst(PME_SubjectSubjectList arg);
PME_SubjectSubjectList PME_setSubjectSubjectListWsAfterFirst(PME_SubjectSubjectList arg, PME_OptLayout wsAfterFirst);
ATbool PME_hasSubjectSubjectListSep(PME_SubjectSubjectList arg);
char* PME_getSubjectSubjectListSep(PME_SubjectSubjectList arg);
PME_SubjectSubjectList PME_setSubjectSubjectListSep(PME_SubjectSubjectList arg, char* sep);
ATbool PME_hasSubjectSubjectListWsAfterSep(PME_SubjectSubjectList arg);
PME_OptLayout PME_getSubjectSubjectListWsAfterSep(PME_SubjectSubjectList arg);
PME_SubjectSubjectList PME_setSubjectSubjectListWsAfterSep(PME_SubjectSubjectList arg, PME_OptLayout wsAfterSep);
ATbool PME_hasSubjectSubjectListTail(PME_SubjectSubjectList arg);
PME_SubjectSubjectList PME_getSubjectSubjectListTail(PME_SubjectSubjectList arg);
PME_SubjectSubjectList PME_setSubjectSubjectListTail(PME_SubjectSubjectList arg, PME_SubjectSubjectList tail);

/*}}}  */
/*{{{  PME_Subject accessors */

ATbool PME_isValidSubject(PME_Subject arg);
inline ATbool PME_isSubjectWithoutLocation(PME_Subject arg);
inline ATbool PME_isSubjectWithLocation(PME_Subject arg);
ATbool PME_hasSubjectWsAfterSubject(PME_Subject arg);
PME_OptLayout PME_getSubjectWsAfterSubject(PME_Subject arg);
PME_Subject PME_setSubjectWsAfterSubject(PME_Subject arg, PME_OptLayout wsAfterSubject);
ATbool PME_hasSubjectWsAfterParenOpen(PME_Subject arg);
PME_OptLayout PME_getSubjectWsAfterParenOpen(PME_Subject arg);
PME_Subject PME_setSubjectWsAfterParenOpen(PME_Subject arg, PME_OptLayout wsAfterParenOpen);
ATbool PME_hasSubjectId(PME_Subject arg);
PME_String PME_getSubjectId(PME_Subject arg);
PME_Subject PME_setSubjectId(PME_Subject arg, PME_String id);
ATbool PME_hasSubjectWsAfterId(PME_Subject arg);
PME_OptLayout PME_getSubjectWsAfterId(PME_Subject arg);
PME_Subject PME_setSubjectWsAfterId(PME_Subject arg, PME_OptLayout wsAfterId);
ATbool PME_hasSubjectWsAfterComma(PME_Subject arg);
PME_OptLayout PME_getSubjectWsAfterComma(PME_Subject arg);
PME_Subject PME_setSubjectWsAfterComma(PME_Subject arg, PME_OptLayout wsAfterComma);
ATbool PME_hasSubjectLocation(PME_Subject arg);
PME_Location PME_getSubjectLocation(PME_Subject arg);
PME_Subject PME_setSubjectLocation(PME_Subject arg, PME_Location location);
ATbool PME_hasSubjectWsAfterLocation(PME_Subject arg);
PME_OptLayout PME_getSubjectWsAfterLocation(PME_Subject arg);
PME_Subject PME_setSubjectWsAfterLocation(PME_Subject arg, PME_OptLayout wsAfterLocation);

/*}}}  */
/*{{{  PME_Location accessors */

ATbool PME_isValidLocation(PME_Location arg);
inline ATbool PME_isLocationLocation(PME_Location arg);
ATbool PME_hasLocationWsAfterLocation(PME_Location arg);
PME_OptLayout PME_getLocationWsAfterLocation(PME_Location arg);
PME_Location PME_setLocationWsAfterLocation(PME_Location arg, PME_OptLayout wsAfterLocation);
ATbool PME_hasLocationWsAfterParenOpen(PME_Location arg);
PME_OptLayout PME_getLocationWsAfterParenOpen(PME_Location arg);
PME_Location PME_setLocationWsAfterParenOpen(PME_Location arg, PME_OptLayout wsAfterParenOpen);
ATbool PME_hasLocationFile(PME_Location arg);
PME_String PME_getLocationFile(PME_Location arg);
PME_Location PME_setLocationFile(PME_Location arg, PME_String file);
ATbool PME_hasLocationWsAfterFile(PME_Location arg);
PME_OptLayout PME_getLocationWsAfterFile(PME_Location arg);
PME_Location PME_setLocationWsAfterFile(PME_Location arg, PME_OptLayout wsAfterFile);
ATbool PME_hasLocationWsAfterComma(PME_Location arg);
PME_OptLayout PME_getLocationWsAfterComma(PME_Location arg);
PME_Location PME_setLocationWsAfterComma(PME_Location arg, PME_OptLayout wsAfterComma);
ATbool PME_hasLocationArea(PME_Location arg);
PME_Area PME_getLocationArea(PME_Location arg);
PME_Location PME_setLocationArea(PME_Location arg, PME_Area area);
ATbool PME_hasLocationWsAfterArea(PME_Location arg);
PME_OptLayout PME_getLocationWsAfterArea(PME_Location arg);
PME_Location PME_setLocationWsAfterArea(PME_Location arg, PME_OptLayout wsAfterArea);

/*}}}  */
/*{{{  PME_Area accessors */

ATbool PME_isValidArea(PME_Area arg);
inline ATbool PME_isAreaArea(PME_Area arg);
ATbool PME_hasAreaWsAfterArea(PME_Area arg);
PME_OptLayout PME_getAreaWsAfterArea(PME_Area arg);
PME_Area PME_setAreaWsAfterArea(PME_Area arg, PME_OptLayout wsAfterArea);
ATbool PME_hasAreaWsAfterParenOpen(PME_Area arg);
PME_OptLayout PME_getAreaWsAfterParenOpen(PME_Area arg);
PME_Area PME_setAreaWsAfterParenOpen(PME_Area arg, PME_OptLayout wsAfterParenOpen);
ATbool PME_hasAreaStartLine(PME_Area arg);
PME_NatCon PME_getAreaStartLine(PME_Area arg);
PME_Area PME_setAreaStartLine(PME_Area arg, PME_NatCon startLine);
ATbool PME_hasAreaWsAfterStartLine(PME_Area arg);
PME_OptLayout PME_getAreaWsAfterStartLine(PME_Area arg);
PME_Area PME_setAreaWsAfterStartLine(PME_Area arg, PME_OptLayout wsAfterStartLine);
ATbool PME_hasAreaWsAfterC1(PME_Area arg);
PME_OptLayout PME_getAreaWsAfterC1(PME_Area arg);
PME_Area PME_setAreaWsAfterC1(PME_Area arg, PME_OptLayout wsAfterC1);
ATbool PME_hasAreaStartColumn(PME_Area arg);
PME_NatCon PME_getAreaStartColumn(PME_Area arg);
PME_Area PME_setAreaStartColumn(PME_Area arg, PME_NatCon startColumn);
ATbool PME_hasAreaWsAfterStartColumn(PME_Area arg);
PME_OptLayout PME_getAreaWsAfterStartColumn(PME_Area arg);
PME_Area PME_setAreaWsAfterStartColumn(PME_Area arg, PME_OptLayout wsAfterStartColumn);
ATbool PME_hasAreaWsAfterC2(PME_Area arg);
PME_OptLayout PME_getAreaWsAfterC2(PME_Area arg);
PME_Area PME_setAreaWsAfterC2(PME_Area arg, PME_OptLayout wsAfterC2);
ATbool PME_hasAreaEndLine(PME_Area arg);
PME_NatCon PME_getAreaEndLine(PME_Area arg);
PME_Area PME_setAreaEndLine(PME_Area arg, PME_NatCon endLine);
ATbool PME_hasAreaWsAfterEndLine(PME_Area arg);
PME_OptLayout PME_getAreaWsAfterEndLine(PME_Area arg);
PME_Area PME_setAreaWsAfterEndLine(PME_Area arg, PME_OptLayout wsAfterEndLine);
ATbool PME_hasAreaWsAfterC3(PME_Area arg);
PME_OptLayout PME_getAreaWsAfterC3(PME_Area arg);
PME_Area PME_setAreaWsAfterC3(PME_Area arg, PME_OptLayout wsAfterC3);
ATbool PME_hasAreaEndColumn(PME_Area arg);
PME_NatCon PME_getAreaEndColumn(PME_Area arg);
PME_Area PME_setAreaEndColumn(PME_Area arg, PME_NatCon endColumn);
ATbool PME_hasAreaWsAfterEndColumn(PME_Area arg);
PME_OptLayout PME_getAreaWsAfterEndColumn(PME_Area arg);
PME_Area PME_setAreaWsAfterEndColumn(PME_Area arg, PME_OptLayout wsAfterEndColumn);
ATbool PME_hasAreaWsAfterC4(PME_Area arg);
PME_OptLayout PME_getAreaWsAfterC4(PME_Area arg);
PME_Area PME_setAreaWsAfterC4(PME_Area arg, PME_OptLayout wsAfterC4);
ATbool PME_hasAreaStartOffset(PME_Area arg);
PME_NatCon PME_getAreaStartOffset(PME_Area arg);
PME_Area PME_setAreaStartOffset(PME_Area arg, PME_NatCon startOffset);
ATbool PME_hasAreaWsAfterStartOffset(PME_Area arg);
PME_OptLayout PME_getAreaWsAfterStartOffset(PME_Area arg);
PME_Area PME_setAreaWsAfterStartOffset(PME_Area arg, PME_OptLayout wsAfterStartOffset);
ATbool PME_hasAreaWsAfterC5(PME_Area arg);
PME_OptLayout PME_getAreaWsAfterC5(PME_Area arg);
PME_Area PME_setAreaWsAfterC5(PME_Area arg, PME_OptLayout wsAfterC5);
ATbool PME_hasAreaEndOffset(PME_Area arg);
PME_NatCon PME_getAreaEndOffset(PME_Area arg);
PME_Area PME_setAreaEndOffset(PME_Area arg, PME_NatCon endOffset);
ATbool PME_hasAreaWsAfterEndOffset(PME_Area arg);
PME_OptLayout PME_getAreaWsAfterEndOffset(PME_Area arg);
PME_Area PME_setAreaWsAfterEndOffset(PME_Area arg, PME_OptLayout wsAfterEndOffset);

/*}}}  */
/*{{{  PME_Start accessors */

ATbool PME_isValidStart(PME_Start arg);
inline ATbool PME_isStartArea(PME_Start arg);
inline ATbool PME_isStartLocation(PME_Start arg);
inline ATbool PME_isStartFeedback(PME_Start arg);
inline ATbool PME_isStartDescription(PME_Start arg);
inline ATbool PME_isStartProducer(PME_Start arg);
inline ATbool PME_isStartInformation(PME_Start arg);
inline ATbool PME_isStartWarning(PME_Start arg);
inline ATbool PME_isStartFatalError(PME_Start arg);
inline ATbool PME_isStartError(PME_Start arg);
ATbool PME_hasStartWsBefore(PME_Start arg);
PME_OptLayout PME_getStartWsBefore(PME_Start arg);
PME_Start PME_setStartWsBefore(PME_Start arg, PME_OptLayout wsBefore);
ATbool PME_hasStartTopArea(PME_Start arg);
PME_Area PME_getStartTopArea(PME_Start arg);
PME_Start PME_setStartTopArea(PME_Start arg, PME_Area topArea);
ATbool PME_hasStartWsAfter(PME_Start arg);
PME_OptLayout PME_getStartWsAfter(PME_Start arg);
PME_Start PME_setStartWsAfter(PME_Start arg, PME_OptLayout wsAfter);
ATbool PME_hasStartAmbCnt(PME_Start arg);
int PME_getStartAmbCnt(PME_Start arg);
PME_Start PME_setStartAmbCnt(PME_Start arg, int ambCnt);
ATbool PME_hasStartTopLocation(PME_Start arg);
PME_Location PME_getStartTopLocation(PME_Start arg);
PME_Start PME_setStartTopLocation(PME_Start arg, PME_Location topLocation);
ATbool PME_hasStartTopFeedback(PME_Start arg);
PME_Feedback PME_getStartTopFeedback(PME_Start arg);
PME_Start PME_setStartTopFeedback(PME_Start arg, PME_Feedback topFeedback);
ATbool PME_hasStartTopDescription(PME_Start arg);
PME_Description PME_getStartTopDescription(PME_Start arg);
PME_Start PME_setStartTopDescription(PME_Start arg, PME_Description topDescription);
ATbool PME_hasStartTopProducer(PME_Start arg);
PME_Producer PME_getStartTopProducer(PME_Start arg);
PME_Start PME_setStartTopProducer(PME_Start arg, PME_Producer topProducer);
ATbool PME_hasStartTopInformation(PME_Start arg);
PME_Information PME_getStartTopInformation(PME_Start arg);
PME_Start PME_setStartTopInformation(PME_Start arg, PME_Information topInformation);
ATbool PME_hasStartTopWarning(PME_Start arg);
PME_Warning PME_getStartTopWarning(PME_Start arg);
PME_Start PME_setStartTopWarning(PME_Start arg, PME_Warning topWarning);
ATbool PME_hasStartTopFatalError(PME_Start arg);
PME_FatalError PME_getStartTopFatalError(PME_Start arg);
PME_Start PME_setStartTopFatalError(PME_Start arg, PME_FatalError topFatalError);
ATbool PME_hasStartTopError(PME_Start arg);
PME_Error PME_getStartTopError(PME_Start arg);
PME_Start PME_setStartTopError(PME_Start arg, PME_Error topError);

/*}}}  */
/*{{{  PME_OptLayout accessors */

ATbool PME_isValidOptLayout(PME_OptLayout arg);
inline ATbool PME_isOptLayoutAbsent(PME_OptLayout arg);
inline ATbool PME_isOptLayoutPresent(PME_OptLayout arg);
ATbool PME_hasOptLayoutChars(PME_OptLayout arg);
PME_CHARLIST PME_getOptLayoutChars(PME_OptLayout arg);
PME_OptLayout PME_setOptLayoutChars(PME_OptLayout arg, PME_CHARLIST chars);

/*}}}  */
/*{{{  sort visitors */

PME_Feedback PME_visitFeedback(PME_Feedback arg, PME_Information (*acceptInformation)(PME_Information), PME_Warning (*acceptWarning)(PME_Warning), PME_Error (*acceptError)(PME_Error), PME_FatalError (*acceptFatalError)(PME_FatalError));
PME_Information PME_visitInformation(PME_Information arg, PME_OptLayout (*acceptWsAfterInformation)(PME_OptLayout), PME_OptLayout (*acceptWsAfterParenOpen)(PME_OptLayout), PME_String (*acceptId)(PME_String), PME_OptLayout (*acceptWsAfterId)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC1)(PME_OptLayout), PME_Producer (*acceptProducer)(PME_Producer), PME_OptLayout (*acceptWsAfterProducer)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC2)(PME_OptLayout), PME_Description (*acceptDescription)(PME_Description), PME_OptLayout (*acceptWsAfterDescription)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC3)(PME_OptLayout), PME_Subjects (*acceptSubjects)(PME_Subjects), PME_OptLayout (*acceptWsAfterSubjects)(PME_OptLayout));
PME_Warning PME_visitWarning(PME_Warning arg, PME_OptLayout (*acceptWsAfterWarning)(PME_OptLayout), PME_OptLayout (*acceptWsAfterParenOpen)(PME_OptLayout), PME_String (*acceptId)(PME_String), PME_OptLayout (*acceptWsAfterId)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC1)(PME_OptLayout), PME_Producer (*acceptProducer)(PME_Producer), PME_OptLayout (*acceptWsAfterProducer)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC2)(PME_OptLayout), PME_Description (*acceptDescription)(PME_Description), PME_OptLayout (*acceptWsAfterDescription)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC3)(PME_OptLayout), PME_Subjects (*acceptSubjects)(PME_Subjects), PME_OptLayout (*acceptWsAfterSubjects)(PME_OptLayout));
PME_Error PME_visitError(PME_Error arg, PME_OptLayout (*acceptWsAfterError)(PME_OptLayout), PME_OptLayout (*acceptWsAfterParenOpen)(PME_OptLayout), PME_String (*acceptId)(PME_String), PME_OptLayout (*acceptWsAfterId)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC1)(PME_OptLayout), PME_Producer (*acceptProducer)(PME_Producer), PME_OptLayout (*acceptWsAfterProducer)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC2)(PME_OptLayout), PME_Description (*acceptDescription)(PME_Description), PME_OptLayout (*acceptWsAfterDescription)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC3)(PME_OptLayout), PME_Subjects (*acceptSubjects)(PME_Subjects), PME_OptLayout (*acceptWsAfterSubjects)(PME_OptLayout));
PME_FatalError PME_visitFatalError(PME_FatalError arg, PME_OptLayout (*acceptWsAfterFatalError)(PME_OptLayout), PME_OptLayout (*acceptWsAfterParenOpen)(PME_OptLayout), PME_String (*acceptId)(PME_String), PME_OptLayout (*acceptWsAfterId)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC1)(PME_OptLayout), PME_Producer (*acceptProducer)(PME_Producer), PME_OptLayout (*acceptWsAfterProducer)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC2)(PME_OptLayout), PME_Description (*acceptDescription)(PME_Description), PME_OptLayout (*acceptWsAfterDescription)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC3)(PME_OptLayout), PME_Subjects (*acceptSubjects)(PME_Subjects), PME_OptLayout (*acceptWsAfterSubjects)(PME_OptLayout));
PME_Producer PME_visitProducer(PME_Producer arg, PME_OptLayout (*acceptWsAfterProducer)(PME_OptLayout), PME_OptLayout (*acceptWsAfterParenOpen)(PME_OptLayout), PME_String (*acceptId)(PME_String), PME_OptLayout (*acceptWsAfterId)(PME_OptLayout), PME_OptLayout (*acceptWsAfterComma)(PME_OptLayout), PME_String (*acceptType)(PME_String), PME_OptLayout (*acceptWsAfterType)(PME_OptLayout));
PME_Description PME_visitDescription(PME_Description arg, PME_OptLayout (*acceptWsAfterDescription)(PME_OptLayout), PME_OptLayout (*acceptWsAfterParenOpen)(PME_OptLayout), PME_String (*acceptString)(PME_String), PME_OptLayout (*acceptWsAfterString)(PME_OptLayout));
PME_Subjects PME_visitSubjects(PME_Subjects arg, PME_OptLayout (*acceptWsAfterBracketOpen)(PME_OptLayout), PME_SubjectSubjectList (*acceptSubjectList)(PME_SubjectSubjectList), PME_OptLayout (*acceptWsAfterSubjectList)(PME_OptLayout));
PME_SubjectSubjectList PME_visitSubjectSubjectList(PME_SubjectSubjectList arg, PME_Subject (*acceptHead)(PME_Subject), PME_OptLayout (*acceptWsAfterFirst)(PME_OptLayout), char* (*acceptSep)(char*), PME_OptLayout (*acceptWsAfterSep)(PME_OptLayout));
PME_Subject PME_visitSubject(PME_Subject arg, PME_OptLayout (*acceptWsAfterSubject)(PME_OptLayout), PME_OptLayout (*acceptWsAfterParenOpen)(PME_OptLayout), PME_String (*acceptId)(PME_String), PME_OptLayout (*acceptWsAfterId)(PME_OptLayout), PME_OptLayout (*acceptWsAfterComma)(PME_OptLayout), PME_Location (*acceptLocation)(PME_Location), PME_OptLayout (*acceptWsAfterLocation)(PME_OptLayout));
PME_Location PME_visitLocation(PME_Location arg, PME_OptLayout (*acceptWsAfterLocation)(PME_OptLayout), PME_OptLayout (*acceptWsAfterParenOpen)(PME_OptLayout), PME_String (*acceptFile)(PME_String), PME_OptLayout (*acceptWsAfterFile)(PME_OptLayout), PME_OptLayout (*acceptWsAfterComma)(PME_OptLayout), PME_Area (*acceptArea)(PME_Area), PME_OptLayout (*acceptWsAfterArea)(PME_OptLayout));
PME_Area PME_visitArea(PME_Area arg, PME_OptLayout (*acceptWsAfterArea)(PME_OptLayout), PME_OptLayout (*acceptWsAfterParenOpen)(PME_OptLayout), PME_NatCon (*acceptStartLine)(PME_NatCon), PME_OptLayout (*acceptWsAfterStartLine)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC1)(PME_OptLayout), PME_NatCon (*acceptStartColumn)(PME_NatCon), PME_OptLayout (*acceptWsAfterStartColumn)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC2)(PME_OptLayout), PME_NatCon (*acceptEndLine)(PME_NatCon), PME_OptLayout (*acceptWsAfterEndLine)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC3)(PME_OptLayout), PME_NatCon (*acceptEndColumn)(PME_NatCon), PME_OptLayout (*acceptWsAfterEndColumn)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC4)(PME_OptLayout), PME_NatCon (*acceptStartOffset)(PME_NatCon), PME_OptLayout (*acceptWsAfterStartOffset)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC5)(PME_OptLayout), PME_NatCon (*acceptEndOffset)(PME_NatCon), PME_OptLayout (*acceptWsAfterEndOffset)(PME_OptLayout));
PME_Start PME_visitStart(PME_Start arg, PME_OptLayout (*acceptWsBefore)(PME_OptLayout), PME_Area (*acceptTopArea)(PME_Area), PME_OptLayout (*acceptWsAfter)(PME_OptLayout), int (*acceptAmbCnt)(int), PME_Location (*acceptTopLocation)(PME_Location), PME_Feedback (*acceptTopFeedback)(PME_Feedback), PME_Description (*acceptTopDescription)(PME_Description), PME_Producer (*acceptTopProducer)(PME_Producer), PME_Information (*acceptTopInformation)(PME_Information), PME_Warning (*acceptTopWarning)(PME_Warning), PME_FatalError (*acceptTopFatalError)(PME_FatalError), PME_Error (*acceptTopError)(PME_Error));
PME_OptLayout PME_visitOptLayout(PME_OptLayout arg, PME_CHARLIST (*acceptChars)(PME_CHARLIST));

/*}}}  */

#endif /* _PARSEDERRORS_H */
