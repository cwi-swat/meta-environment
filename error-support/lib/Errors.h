#ifndef _ERRORS_H
#define _ERRORS_H

/*{{{  includes */

#include <aterm1.h>
#include "Errors_dict.h"

/*}}}  */

/*{{{  prologue */


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

/*}}}  */

void PME_initErrorsApi(void);

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

/*}}}  */
/*{{{  list functions */

int PME_getSubjectSubjectListLength (PME_SubjectSubjectList arg);
PME_SubjectSubjectList PME_reverseSubjectSubjectList(PME_SubjectSubjectList arg);
PME_SubjectSubjectList PME_appendSubjectSubjectList(PME_SubjectSubjectList arg, PME_Subject elem);
PME_SubjectSubjectList PME_concatSubjectSubjectList(PME_SubjectSubjectList arg0, PME_SubjectSubjectList arg1);
PME_SubjectSubjectList PME_sliceSubjectSubjectList(PME_SubjectSubjectList arg, int start, int end);
PME_Subject PME_getSubjectSubjectListSubjectAt(PME_SubjectSubjectList arg, int index);
PME_SubjectSubjectList PME_replaceSubjectSubjectListSubjectAt(PME_SubjectSubjectList arg, PME_Subject elem, int index);
PME_SubjectSubjectList PME_makeSubjectSubjectList1(PME_Subject elem1);
PME_SubjectSubjectList PME_makeSubjectSubjectList2(PME_Subject elem1, PME_Subject elem2);
PME_SubjectSubjectList PME_makeSubjectSubjectList3(PME_Subject elem1, PME_Subject elem2, PME_Subject elem3);
PME_SubjectSubjectList PME_makeSubjectSubjectList4(PME_Subject elem1, PME_Subject elem2, PME_Subject elem3, PME_Subject elem4);
PME_SubjectSubjectList PME_makeSubjectSubjectList5(PME_Subject elem1, PME_Subject elem2, PME_Subject elem3, PME_Subject elem4, PME_Subject elem5);
PME_SubjectSubjectList PME_makeSubjectSubjectList6(PME_Subject elem1, PME_Subject elem2, PME_Subject elem3, PME_Subject elem4, PME_Subject elem5, PME_Subject elem6);

/*}}}  */
/*{{{  constructors */

PME_Feedback PME_makeFeedbackInfo(PME_Info Info);
PME_Feedback PME_makeFeedbackWarning(PME_Warning Warning);
PME_Feedback PME_makeFeedbackError(PME_Error Error);
PME_Feedback PME_makeFeedbackFatalError(PME_FatalError FatalError);
PME_Information PME_makeInformationInformation(PME_String id, PME_Producer producer, PME_Description description, PME_Subjects subjects);
PME_Warning PME_makeWarningWarning(PME_String id, PME_Producer producer, PME_Description description, PME_Subjects subjects);
PME_Error PME_makeErrorError(PME_String id, PME_Producer producer, PME_Description description, PME_Subjects subjects);
PME_FatalError PME_makeFatalErrorFatalError(PME_String id, PME_Producer producer, PME_Description description, PME_Subjects subjects);
PME_Producer PME_makeProducerProducer(PME_String id, PME_String type);
PME_Description PME_makeDescriptionDescription(PME_String String);
PME_Subjects PME_makeSubjectsSubjects(PME_SubjectSubjectList subjectList);
PME_SubjectSubjectList PME_makeSubjectSubjectListMany(PME_Subject head, PME_SubjectSubjectList tail);
PME_SubjectSubjectList PME_makeSubjectSubjectListEmpty();
PME_Subject PME_makeSubjectWithoutLocation(PME_String id, PME_Location location);
PME_Subject PME_makeSubjectWithLocation(PME_String id);
PME_Location PME_makeLocationLocation(PME_String file, PME_Area area);
PME_Area PME_makeAreaArea(PME_NatCon startLine, PME_NatCon startColumn, PME_NatCon endLine, PME_NatCon endColumn, PME_NatCon startOffset, PME_NatCon endOffset);

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

/*}}}  */
/*{{{  PME_Feedback accessors */

ATbool PME_isValidFeedback(PME_Feedback arg);
inline ATbool PME_isFeedbackInfo(PME_Feedback arg);
inline ATbool PME_isFeedbackWarning(PME_Feedback arg);
inline ATbool PME_isFeedbackError(PME_Feedback arg);
inline ATbool PME_isFeedbackFatalError(PME_Feedback arg);
ATbool PME_hasFeedbackInfo(PME_Feedback arg);
PME_Info PME_getFeedbackInfo(PME_Feedback arg);
PME_Feedback PME_setFeedbackInfo(PME_Feedback arg, PME_Info Info);
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
ATbool PME_hasInformationId(PME_Information arg);
PME_String PME_getInformationId(PME_Information arg);
PME_Information PME_setInformationId(PME_Information arg, PME_String id);
ATbool PME_hasInformationProducer(PME_Information arg);
PME_Producer PME_getInformationProducer(PME_Information arg);
PME_Information PME_setInformationProducer(PME_Information arg, PME_Producer producer);
ATbool PME_hasInformationDescription(PME_Information arg);
PME_Description PME_getInformationDescription(PME_Information arg);
PME_Information PME_setInformationDescription(PME_Information arg, PME_Description description);
ATbool PME_hasInformationSubjects(PME_Information arg);
PME_Subjects PME_getInformationSubjects(PME_Information arg);
PME_Information PME_setInformationSubjects(PME_Information arg, PME_Subjects subjects);

/*}}}  */
/*{{{  PME_Warning accessors */

ATbool PME_isValidWarning(PME_Warning arg);
inline ATbool PME_isWarningWarning(PME_Warning arg);
ATbool PME_hasWarningId(PME_Warning arg);
PME_String PME_getWarningId(PME_Warning arg);
PME_Warning PME_setWarningId(PME_Warning arg, PME_String id);
ATbool PME_hasWarningProducer(PME_Warning arg);
PME_Producer PME_getWarningProducer(PME_Warning arg);
PME_Warning PME_setWarningProducer(PME_Warning arg, PME_Producer producer);
ATbool PME_hasWarningDescription(PME_Warning arg);
PME_Description PME_getWarningDescription(PME_Warning arg);
PME_Warning PME_setWarningDescription(PME_Warning arg, PME_Description description);
ATbool PME_hasWarningSubjects(PME_Warning arg);
PME_Subjects PME_getWarningSubjects(PME_Warning arg);
PME_Warning PME_setWarningSubjects(PME_Warning arg, PME_Subjects subjects);

/*}}}  */
/*{{{  PME_Error accessors */

ATbool PME_isValidError(PME_Error arg);
inline ATbool PME_isErrorError(PME_Error arg);
ATbool PME_hasErrorId(PME_Error arg);
PME_String PME_getErrorId(PME_Error arg);
PME_Error PME_setErrorId(PME_Error arg, PME_String id);
ATbool PME_hasErrorProducer(PME_Error arg);
PME_Producer PME_getErrorProducer(PME_Error arg);
PME_Error PME_setErrorProducer(PME_Error arg, PME_Producer producer);
ATbool PME_hasErrorDescription(PME_Error arg);
PME_Description PME_getErrorDescription(PME_Error arg);
PME_Error PME_setErrorDescription(PME_Error arg, PME_Description description);
ATbool PME_hasErrorSubjects(PME_Error arg);
PME_Subjects PME_getErrorSubjects(PME_Error arg);
PME_Error PME_setErrorSubjects(PME_Error arg, PME_Subjects subjects);

/*}}}  */
/*{{{  PME_FatalError accessors */

ATbool PME_isValidFatalError(PME_FatalError arg);
inline ATbool PME_isFatalErrorFatalError(PME_FatalError arg);
ATbool PME_hasFatalErrorId(PME_FatalError arg);
PME_String PME_getFatalErrorId(PME_FatalError arg);
PME_FatalError PME_setFatalErrorId(PME_FatalError arg, PME_String id);
ATbool PME_hasFatalErrorProducer(PME_FatalError arg);
PME_Producer PME_getFatalErrorProducer(PME_FatalError arg);
PME_FatalError PME_setFatalErrorProducer(PME_FatalError arg, PME_Producer producer);
ATbool PME_hasFatalErrorDescription(PME_FatalError arg);
PME_Description PME_getFatalErrorDescription(PME_FatalError arg);
PME_FatalError PME_setFatalErrorDescription(PME_FatalError arg, PME_Description description);
ATbool PME_hasFatalErrorSubjects(PME_FatalError arg);
PME_Subjects PME_getFatalErrorSubjects(PME_FatalError arg);
PME_FatalError PME_setFatalErrorSubjects(PME_FatalError arg, PME_Subjects subjects);

/*}}}  */
/*{{{  PME_Producer accessors */

ATbool PME_isValidProducer(PME_Producer arg);
inline ATbool PME_isProducerProducer(PME_Producer arg);
ATbool PME_hasProducerId(PME_Producer arg);
PME_String PME_getProducerId(PME_Producer arg);
PME_Producer PME_setProducerId(PME_Producer arg, PME_String id);
ATbool PME_hasProducerType(PME_Producer arg);
PME_String PME_getProducerType(PME_Producer arg);
PME_Producer PME_setProducerType(PME_Producer arg, PME_String type);

/*}}}  */
/*{{{  PME_Description accessors */

ATbool PME_isValidDescription(PME_Description arg);
inline ATbool PME_isDescriptionDescription(PME_Description arg);
ATbool PME_hasDescriptionString(PME_Description arg);
PME_String PME_getDescriptionString(PME_Description arg);
PME_Description PME_setDescriptionString(PME_Description arg, PME_String String);

/*}}}  */
/*{{{  PME_Subjects accessors */

ATbool PME_isValidSubjects(PME_Subjects arg);
inline ATbool PME_isSubjectsSubjects(PME_Subjects arg);
ATbool PME_hasSubjectsSubjectList(PME_Subjects arg);
PME_SubjectSubjectList PME_getSubjectsSubjectList(PME_Subjects arg);
PME_Subjects PME_setSubjectsSubjectList(PME_Subjects arg, PME_SubjectSubjectList subjectList);

/*}}}  */
/*{{{  PME_SubjectSubjectList accessors */

ATbool PME_isValidSubjectSubjectList(PME_SubjectSubjectList arg);
inline ATbool PME_isSubjectSubjectListMany(PME_SubjectSubjectList arg);
inline ATbool PME_isSubjectSubjectListEmpty(PME_SubjectSubjectList arg);
ATbool PME_hasSubjectSubjectListHead(PME_SubjectSubjectList arg);
PME_Subject PME_getSubjectSubjectListHead(PME_SubjectSubjectList arg);
PME_SubjectSubjectList PME_setSubjectSubjectListHead(PME_SubjectSubjectList arg, PME_Subject head);
ATbool PME_hasSubjectSubjectListTail(PME_SubjectSubjectList arg);
PME_SubjectSubjectList PME_getSubjectSubjectListTail(PME_SubjectSubjectList arg);
PME_SubjectSubjectList PME_setSubjectSubjectListTail(PME_SubjectSubjectList arg, PME_SubjectSubjectList tail);

/*}}}  */
/*{{{  PME_Subject accessors */

ATbool PME_isValidSubject(PME_Subject arg);
inline ATbool PME_isSubjectWithoutLocation(PME_Subject arg);
inline ATbool PME_isSubjectWithLocation(PME_Subject arg);
ATbool PME_hasSubjectId(PME_Subject arg);
PME_String PME_getSubjectId(PME_Subject arg);
PME_Subject PME_setSubjectId(PME_Subject arg, PME_String id);
ATbool PME_hasSubjectLocation(PME_Subject arg);
PME_Location PME_getSubjectLocation(PME_Subject arg);
PME_Subject PME_setSubjectLocation(PME_Subject arg, PME_Location location);

/*}}}  */
/*{{{  PME_Location accessors */

ATbool PME_isValidLocation(PME_Location arg);
inline ATbool PME_isLocationLocation(PME_Location arg);
ATbool PME_hasLocationFile(PME_Location arg);
PME_String PME_getLocationFile(PME_Location arg);
PME_Location PME_setLocationFile(PME_Location arg, PME_String file);
ATbool PME_hasLocationArea(PME_Location arg);
PME_Area PME_getLocationArea(PME_Location arg);
PME_Location PME_setLocationArea(PME_Location arg, PME_Area area);

/*}}}  */
/*{{{  PME_Area accessors */

ATbool PME_isValidArea(PME_Area arg);
inline ATbool PME_isAreaArea(PME_Area arg);
ATbool PME_hasAreaStartLine(PME_Area arg);
PME_NatCon PME_getAreaStartLine(PME_Area arg);
PME_Area PME_setAreaStartLine(PME_Area arg, PME_NatCon startLine);
ATbool PME_hasAreaStartColumn(PME_Area arg);
PME_NatCon PME_getAreaStartColumn(PME_Area arg);
PME_Area PME_setAreaStartColumn(PME_Area arg, PME_NatCon startColumn);
ATbool PME_hasAreaEndLine(PME_Area arg);
PME_NatCon PME_getAreaEndLine(PME_Area arg);
PME_Area PME_setAreaEndLine(PME_Area arg, PME_NatCon endLine);
ATbool PME_hasAreaEndColumn(PME_Area arg);
PME_NatCon PME_getAreaEndColumn(PME_Area arg);
PME_Area PME_setAreaEndColumn(PME_Area arg, PME_NatCon endColumn);
ATbool PME_hasAreaStartOffset(PME_Area arg);
PME_NatCon PME_getAreaStartOffset(PME_Area arg);
PME_Area PME_setAreaStartOffset(PME_Area arg, PME_NatCon startOffset);
ATbool PME_hasAreaEndOffset(PME_Area arg);
PME_NatCon PME_getAreaEndOffset(PME_Area arg);
PME_Area PME_setAreaEndOffset(PME_Area arg, PME_NatCon endOffset);

/*}}}  */
/*{{{  sort visitors */

PME_Feedback PME_visitFeedback(PME_Feedback arg, PME_Info (*acceptInfo)(PME_Info), PME_Warning (*acceptWarning)(PME_Warning), PME_Error (*acceptError)(PME_Error), PME_FatalError (*acceptFatalError)(PME_FatalError));
PME_Information PME_visitInformation(PME_Information arg, PME_String (*acceptId)(PME_String), PME_Producer (*acceptProducer)(PME_Producer), PME_Description (*acceptDescription)(PME_Description), PME_Subjects (*acceptSubjects)(PME_Subjects));
PME_Warning PME_visitWarning(PME_Warning arg, PME_String (*acceptId)(PME_String), PME_Producer (*acceptProducer)(PME_Producer), PME_Description (*acceptDescription)(PME_Description), PME_Subjects (*acceptSubjects)(PME_Subjects));
PME_Error PME_visitError(PME_Error arg, PME_String (*acceptId)(PME_String), PME_Producer (*acceptProducer)(PME_Producer), PME_Description (*acceptDescription)(PME_Description), PME_Subjects (*acceptSubjects)(PME_Subjects));
PME_FatalError PME_visitFatalError(PME_FatalError arg, PME_String (*acceptId)(PME_String), PME_Producer (*acceptProducer)(PME_Producer), PME_Description (*acceptDescription)(PME_Description), PME_Subjects (*acceptSubjects)(PME_Subjects));
PME_Producer PME_visitProducer(PME_Producer arg, PME_String (*acceptId)(PME_String), PME_String (*acceptType)(PME_String));
PME_Description PME_visitDescription(PME_Description arg, PME_String (*acceptString)(PME_String));
PME_Subjects PME_visitSubjects(PME_Subjects arg, PME_SubjectSubjectList (*acceptSubjectList)(PME_SubjectSubjectList));
PME_SubjectSubjectList PME_visitSubjectSubjectList(PME_SubjectSubjectList arg, PME_Subject (*acceptHead)(PME_Subject));
PME_Subject PME_visitSubject(PME_Subject arg, PME_String (*acceptId)(PME_String), PME_Location (*acceptLocation)(PME_Location));
PME_Location PME_visitLocation(PME_Location arg, PME_String (*acceptFile)(PME_String), PME_Area (*acceptArea)(PME_Area));
PME_Area PME_visitArea(PME_Area arg, PME_NatCon (*acceptStartLine)(PME_NatCon), PME_NatCon (*acceptStartColumn)(PME_NatCon), PME_NatCon (*acceptEndLine)(PME_NatCon), PME_NatCon (*acceptEndColumn)(PME_NatCon), PME_NatCon (*acceptStartOffset)(PME_NatCon), PME_NatCon (*acceptEndOffset)(PME_NatCon));

/*}}}  */

#endif /* _ERRORS_H */
