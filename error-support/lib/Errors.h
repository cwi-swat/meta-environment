#ifndef _ERRORS_H
#define _ERRORS_H

/*{{{  includes */

#include <aterm1.h>
#include "Errors_dict.h"

/*}}}  */

/*{{{  prologue */


/*}}}  */
/*{{{  typedefs */

typedef struct _ME_Feedback *ME_Feedback;
typedef struct _ME_Information *ME_Information;
typedef struct _ME_Warning *ME_Warning;
typedef struct _ME_Error *ME_Error;
typedef struct _ME_FatalError *ME_FatalError;
typedef struct _ME_Producer *ME_Producer;
typedef struct _ME_Description *ME_Description;
typedef struct _ME_Subjects *ME_Subjects;
typedef struct _ME_SubjectSubjectList *ME_SubjectSubjectList;
typedef struct _ME_Subject *ME_Subject;
typedef struct _ME_Location *ME_Location;
typedef struct _ME_Area *ME_Area;

/*}}}  */

void ME_initErrorsApi(void);

/*{{{  term conversion functions */

ME_Feedback ME_FeedbackFromTerm(ATerm t);
ATerm ME_FeedbackToTerm(ME_Feedback arg);
ME_Information ME_InformationFromTerm(ATerm t);
ATerm ME_InformationToTerm(ME_Information arg);
ME_Warning ME_WarningFromTerm(ATerm t);
ATerm ME_WarningToTerm(ME_Warning arg);
ME_Error ME_ErrorFromTerm(ATerm t);
ATerm ME_ErrorToTerm(ME_Error arg);
ME_FatalError ME_FatalErrorFromTerm(ATerm t);
ATerm ME_FatalErrorToTerm(ME_FatalError arg);
ME_Producer ME_ProducerFromTerm(ATerm t);
ATerm ME_ProducerToTerm(ME_Producer arg);
ME_Description ME_DescriptionFromTerm(ATerm t);
ATerm ME_DescriptionToTerm(ME_Description arg);
ME_Subjects ME_SubjectsFromTerm(ATerm t);
ATerm ME_SubjectsToTerm(ME_Subjects arg);
ME_SubjectSubjectList ME_SubjectSubjectListFromTerm(ATerm t);
ATerm ME_SubjectSubjectListToTerm(ME_SubjectSubjectList arg);
ME_Subject ME_SubjectFromTerm(ATerm t);
ATerm ME_SubjectToTerm(ME_Subject arg);
ME_Location ME_LocationFromTerm(ATerm t);
ATerm ME_LocationToTerm(ME_Location arg);
ME_Area ME_AreaFromTerm(ATerm t);
ATerm ME_AreaToTerm(ME_Area arg);

/*}}}  */
/*{{{  list functions */

int ME_getSubjectSubjectListLength (ME_SubjectSubjectList arg);
ME_SubjectSubjectList ME_reverseSubjectSubjectList(ME_SubjectSubjectList arg);
ME_SubjectSubjectList ME_appendSubjectSubjectList(ME_SubjectSubjectList arg, ME_Subject elem);
ME_SubjectSubjectList ME_concatSubjectSubjectList(ME_SubjectSubjectList arg0, ME_SubjectSubjectList arg1);
ME_SubjectSubjectList ME_sliceSubjectSubjectList(ME_SubjectSubjectList arg, int start, int end);
ME_Subject ME_getSubjectSubjectListSubjectAt(ME_SubjectSubjectList arg, int index);
ME_SubjectSubjectList ME_replaceSubjectSubjectListSubjectAt(ME_SubjectSubjectList arg, ME_Subject elem, int index);
ME_SubjectSubjectList ME_makeSubjectSubjectList1(ME_Subject elem1);
ME_SubjectSubjectList ME_makeSubjectSubjectList2(ME_Subject elem1, ME_Subject elem2);
ME_SubjectSubjectList ME_makeSubjectSubjectList3(ME_Subject elem1, ME_Subject elem2, ME_Subject elem3);
ME_SubjectSubjectList ME_makeSubjectSubjectList4(ME_Subject elem1, ME_Subject elem2, ME_Subject elem3, ME_Subject elem4);
ME_SubjectSubjectList ME_makeSubjectSubjectList5(ME_Subject elem1, ME_Subject elem2, ME_Subject elem3, ME_Subject elem4, ME_Subject elem5);
ME_SubjectSubjectList ME_makeSubjectSubjectList6(ME_Subject elem1, ME_Subject elem2, ME_Subject elem3, ME_Subject elem4, ME_Subject elem5, ME_Subject elem6);

/*}}}  */
/*{{{  constructors */

ME_Feedback ME_makeFeedbackInfo(ME_Information Information);
ME_Feedback ME_makeFeedbackWarning(ME_Warning Warning);
ME_Feedback ME_makeFeedbackError(ME_Error Error);
ME_Feedback ME_makeFeedbackFatalError(ME_FatalError FatalError);
ME_Information ME_makeInformationInformation(char* id, ME_Producer producer, ME_Description description, ME_Subjects subjects);
ME_Warning ME_makeWarningWarning(char* id, ME_Producer producer, ME_Description description, ME_Subjects subjects);
ME_Error ME_makeErrorError(char* id, ME_Producer producer, ME_Description description, ME_Subjects subjects);
ME_FatalError ME_makeFatalErrorFatalError(char* id, ME_Producer producer, ME_Description description, ME_Subjects subjects);
ME_Producer ME_makeProducerProducer(char* id, char* type);
ME_Description ME_makeDescriptionDescription(char* String);
ME_Subjects ME_makeSubjectsSubjects(ME_SubjectSubjectList subjectList);
ME_SubjectSubjectList ME_makeSubjectSubjectListMany(ME_Subject head, ME_SubjectSubjectList tail);
ME_SubjectSubjectList ME_makeSubjectSubjectListEmpty();
ME_Subject ME_makeSubjectWithoutLocation(char* id, ME_Location location);
ME_Subject ME_makeSubjectWithLocation(char* id);
ME_Location ME_makeLocationLocation(char* file, ME_Area area);
ME_Area ME_makeAreaArea(int startLine, int startColumn, int endLine, int endColumn, int startOffset, int endOffset);

/*}}}  */
/*{{{  equality functions */

ATbool ME_isEqualFeedback(ME_Feedback arg0, ME_Feedback arg1);
ATbool ME_isEqualInformation(ME_Information arg0, ME_Information arg1);
ATbool ME_isEqualWarning(ME_Warning arg0, ME_Warning arg1);
ATbool ME_isEqualError(ME_Error arg0, ME_Error arg1);
ATbool ME_isEqualFatalError(ME_FatalError arg0, ME_FatalError arg1);
ATbool ME_isEqualProducer(ME_Producer arg0, ME_Producer arg1);
ATbool ME_isEqualDescription(ME_Description arg0, ME_Description arg1);
ATbool ME_isEqualSubjects(ME_Subjects arg0, ME_Subjects arg1);
ATbool ME_isEqualSubjectSubjectList(ME_SubjectSubjectList arg0, ME_SubjectSubjectList arg1);
ATbool ME_isEqualSubject(ME_Subject arg0, ME_Subject arg1);
ATbool ME_isEqualLocation(ME_Location arg0, ME_Location arg1);
ATbool ME_isEqualArea(ME_Area arg0, ME_Area arg1);

/*}}}  */
/*{{{  ME_Feedback accessors */

ATbool ME_isValidFeedback(ME_Feedback arg);
inline ATbool ME_isFeedbackInfo(ME_Feedback arg);
inline ATbool ME_isFeedbackWarning(ME_Feedback arg);
inline ATbool ME_isFeedbackError(ME_Feedback arg);
inline ATbool ME_isFeedbackFatalError(ME_Feedback arg);
ATbool ME_hasFeedbackInformation(ME_Feedback arg);
ME_Information ME_getFeedbackInformation(ME_Feedback arg);
ME_Feedback ME_setFeedbackInformation(ME_Feedback arg, ME_Information Information);
ATbool ME_hasFeedbackWarning(ME_Feedback arg);
ME_Warning ME_getFeedbackWarning(ME_Feedback arg);
ME_Feedback ME_setFeedbackWarning(ME_Feedback arg, ME_Warning Warning);
ATbool ME_hasFeedbackError(ME_Feedback arg);
ME_Error ME_getFeedbackError(ME_Feedback arg);
ME_Feedback ME_setFeedbackError(ME_Feedback arg, ME_Error Error);
ATbool ME_hasFeedbackFatalError(ME_Feedback arg);
ME_FatalError ME_getFeedbackFatalError(ME_Feedback arg);
ME_Feedback ME_setFeedbackFatalError(ME_Feedback arg, ME_FatalError FatalError);

/*}}}  */
/*{{{  ME_Information accessors */

ATbool ME_isValidInformation(ME_Information arg);
inline ATbool ME_isInformationInformation(ME_Information arg);
ATbool ME_hasInformationId(ME_Information arg);
char* ME_getInformationId(ME_Information arg);
ME_Information ME_setInformationId(ME_Information arg, char* id);
ATbool ME_hasInformationProducer(ME_Information arg);
ME_Producer ME_getInformationProducer(ME_Information arg);
ME_Information ME_setInformationProducer(ME_Information arg, ME_Producer producer);
ATbool ME_hasInformationDescription(ME_Information arg);
ME_Description ME_getInformationDescription(ME_Information arg);
ME_Information ME_setInformationDescription(ME_Information arg, ME_Description description);
ATbool ME_hasInformationSubjects(ME_Information arg);
ME_Subjects ME_getInformationSubjects(ME_Information arg);
ME_Information ME_setInformationSubjects(ME_Information arg, ME_Subjects subjects);

/*}}}  */
/*{{{  ME_Warning accessors */

ATbool ME_isValidWarning(ME_Warning arg);
inline ATbool ME_isWarningWarning(ME_Warning arg);
ATbool ME_hasWarningId(ME_Warning arg);
char* ME_getWarningId(ME_Warning arg);
ME_Warning ME_setWarningId(ME_Warning arg, char* id);
ATbool ME_hasWarningProducer(ME_Warning arg);
ME_Producer ME_getWarningProducer(ME_Warning arg);
ME_Warning ME_setWarningProducer(ME_Warning arg, ME_Producer producer);
ATbool ME_hasWarningDescription(ME_Warning arg);
ME_Description ME_getWarningDescription(ME_Warning arg);
ME_Warning ME_setWarningDescription(ME_Warning arg, ME_Description description);
ATbool ME_hasWarningSubjects(ME_Warning arg);
ME_Subjects ME_getWarningSubjects(ME_Warning arg);
ME_Warning ME_setWarningSubjects(ME_Warning arg, ME_Subjects subjects);

/*}}}  */
/*{{{  ME_Error accessors */

ATbool ME_isValidError(ME_Error arg);
inline ATbool ME_isErrorError(ME_Error arg);
ATbool ME_hasErrorId(ME_Error arg);
char* ME_getErrorId(ME_Error arg);
ME_Error ME_setErrorId(ME_Error arg, char* id);
ATbool ME_hasErrorProducer(ME_Error arg);
ME_Producer ME_getErrorProducer(ME_Error arg);
ME_Error ME_setErrorProducer(ME_Error arg, ME_Producer producer);
ATbool ME_hasErrorDescription(ME_Error arg);
ME_Description ME_getErrorDescription(ME_Error arg);
ME_Error ME_setErrorDescription(ME_Error arg, ME_Description description);
ATbool ME_hasErrorSubjects(ME_Error arg);
ME_Subjects ME_getErrorSubjects(ME_Error arg);
ME_Error ME_setErrorSubjects(ME_Error arg, ME_Subjects subjects);

/*}}}  */
/*{{{  ME_FatalError accessors */

ATbool ME_isValidFatalError(ME_FatalError arg);
inline ATbool ME_isFatalErrorFatalError(ME_FatalError arg);
ATbool ME_hasFatalErrorId(ME_FatalError arg);
char* ME_getFatalErrorId(ME_FatalError arg);
ME_FatalError ME_setFatalErrorId(ME_FatalError arg, char* id);
ATbool ME_hasFatalErrorProducer(ME_FatalError arg);
ME_Producer ME_getFatalErrorProducer(ME_FatalError arg);
ME_FatalError ME_setFatalErrorProducer(ME_FatalError arg, ME_Producer producer);
ATbool ME_hasFatalErrorDescription(ME_FatalError arg);
ME_Description ME_getFatalErrorDescription(ME_FatalError arg);
ME_FatalError ME_setFatalErrorDescription(ME_FatalError arg, ME_Description description);
ATbool ME_hasFatalErrorSubjects(ME_FatalError arg);
ME_Subjects ME_getFatalErrorSubjects(ME_FatalError arg);
ME_FatalError ME_setFatalErrorSubjects(ME_FatalError arg, ME_Subjects subjects);

/*}}}  */
/*{{{  ME_Producer accessors */

ATbool ME_isValidProducer(ME_Producer arg);
inline ATbool ME_isProducerProducer(ME_Producer arg);
ATbool ME_hasProducerId(ME_Producer arg);
char* ME_getProducerId(ME_Producer arg);
ME_Producer ME_setProducerId(ME_Producer arg, char* id);
ATbool ME_hasProducerType(ME_Producer arg);
char* ME_getProducerType(ME_Producer arg);
ME_Producer ME_setProducerType(ME_Producer arg, char* type);

/*}}}  */
/*{{{  ME_Description accessors */

ATbool ME_isValidDescription(ME_Description arg);
inline ATbool ME_isDescriptionDescription(ME_Description arg);
ATbool ME_hasDescriptionString(ME_Description arg);
char* ME_getDescriptionString(ME_Description arg);
ME_Description ME_setDescriptionString(ME_Description arg, char* String);

/*}}}  */
/*{{{  ME_Subjects accessors */

ATbool ME_isValidSubjects(ME_Subjects arg);
inline ATbool ME_isSubjectsSubjects(ME_Subjects arg);
ATbool ME_hasSubjectsSubjectList(ME_Subjects arg);
ME_SubjectSubjectList ME_getSubjectsSubjectList(ME_Subjects arg);
ME_Subjects ME_setSubjectsSubjectList(ME_Subjects arg, ME_SubjectSubjectList subjectList);

/*}}}  */
/*{{{  ME_SubjectSubjectList accessors */

ATbool ME_isValidSubjectSubjectList(ME_SubjectSubjectList arg);
inline ATbool ME_isSubjectSubjectListMany(ME_SubjectSubjectList arg);
inline ATbool ME_isSubjectSubjectListEmpty(ME_SubjectSubjectList arg);
ATbool ME_hasSubjectSubjectListHead(ME_SubjectSubjectList arg);
ME_Subject ME_getSubjectSubjectListHead(ME_SubjectSubjectList arg);
ME_SubjectSubjectList ME_setSubjectSubjectListHead(ME_SubjectSubjectList arg, ME_Subject head);
ATbool ME_hasSubjectSubjectListTail(ME_SubjectSubjectList arg);
ME_SubjectSubjectList ME_getSubjectSubjectListTail(ME_SubjectSubjectList arg);
ME_SubjectSubjectList ME_setSubjectSubjectListTail(ME_SubjectSubjectList arg, ME_SubjectSubjectList tail);

/*}}}  */
/*{{{  ME_Subject accessors */

ATbool ME_isValidSubject(ME_Subject arg);
inline ATbool ME_isSubjectWithoutLocation(ME_Subject arg);
inline ATbool ME_isSubjectWithLocation(ME_Subject arg);
ATbool ME_hasSubjectId(ME_Subject arg);
char* ME_getSubjectId(ME_Subject arg);
ME_Subject ME_setSubjectId(ME_Subject arg, char* id);
ATbool ME_hasSubjectLocation(ME_Subject arg);
ME_Location ME_getSubjectLocation(ME_Subject arg);
ME_Subject ME_setSubjectLocation(ME_Subject arg, ME_Location location);

/*}}}  */
/*{{{  ME_Location accessors */

ATbool ME_isValidLocation(ME_Location arg);
inline ATbool ME_isLocationLocation(ME_Location arg);
ATbool ME_hasLocationFile(ME_Location arg);
char* ME_getLocationFile(ME_Location arg);
ME_Location ME_setLocationFile(ME_Location arg, char* file);
ATbool ME_hasLocationArea(ME_Location arg);
ME_Area ME_getLocationArea(ME_Location arg);
ME_Location ME_setLocationArea(ME_Location arg, ME_Area area);

/*}}}  */
/*{{{  ME_Area accessors */

ATbool ME_isValidArea(ME_Area arg);
inline ATbool ME_isAreaArea(ME_Area arg);
ATbool ME_hasAreaStartLine(ME_Area arg);
int ME_getAreaStartLine(ME_Area arg);
ME_Area ME_setAreaStartLine(ME_Area arg, int startLine);
ATbool ME_hasAreaStartColumn(ME_Area arg);
int ME_getAreaStartColumn(ME_Area arg);
ME_Area ME_setAreaStartColumn(ME_Area arg, int startColumn);
ATbool ME_hasAreaEndLine(ME_Area arg);
int ME_getAreaEndLine(ME_Area arg);
ME_Area ME_setAreaEndLine(ME_Area arg, int endLine);
ATbool ME_hasAreaEndColumn(ME_Area arg);
int ME_getAreaEndColumn(ME_Area arg);
ME_Area ME_setAreaEndColumn(ME_Area arg, int endColumn);
ATbool ME_hasAreaStartOffset(ME_Area arg);
int ME_getAreaStartOffset(ME_Area arg);
ME_Area ME_setAreaStartOffset(ME_Area arg, int startOffset);
ATbool ME_hasAreaEndOffset(ME_Area arg);
int ME_getAreaEndOffset(ME_Area arg);
ME_Area ME_setAreaEndOffset(ME_Area arg, int endOffset);

/*}}}  */
/*{{{  sort visitors */

ME_Feedback ME_visitFeedback(ME_Feedback arg, ME_Information (*acceptInformation)(ME_Information), ME_Warning (*acceptWarning)(ME_Warning), ME_Error (*acceptError)(ME_Error), ME_FatalError (*acceptFatalError)(ME_FatalError));
ME_Information ME_visitInformation(ME_Information arg, char* (*acceptId)(char*), ME_Producer (*acceptProducer)(ME_Producer), ME_Description (*acceptDescription)(ME_Description), ME_Subjects (*acceptSubjects)(ME_Subjects));
ME_Warning ME_visitWarning(ME_Warning arg, char* (*acceptId)(char*), ME_Producer (*acceptProducer)(ME_Producer), ME_Description (*acceptDescription)(ME_Description), ME_Subjects (*acceptSubjects)(ME_Subjects));
ME_Error ME_visitError(ME_Error arg, char* (*acceptId)(char*), ME_Producer (*acceptProducer)(ME_Producer), ME_Description (*acceptDescription)(ME_Description), ME_Subjects (*acceptSubjects)(ME_Subjects));
ME_FatalError ME_visitFatalError(ME_FatalError arg, char* (*acceptId)(char*), ME_Producer (*acceptProducer)(ME_Producer), ME_Description (*acceptDescription)(ME_Description), ME_Subjects (*acceptSubjects)(ME_Subjects));
ME_Producer ME_visitProducer(ME_Producer arg, char* (*acceptId)(char*), char* (*acceptType)(char*));
ME_Description ME_visitDescription(ME_Description arg, char* (*acceptString)(char*));
ME_Subjects ME_visitSubjects(ME_Subjects arg, ME_SubjectSubjectList (*acceptSubjectList)(ME_SubjectSubjectList));
ME_SubjectSubjectList ME_visitSubjectSubjectList(ME_SubjectSubjectList arg, ME_Subject (*acceptHead)(ME_Subject));
ME_Subject ME_visitSubject(ME_Subject arg, char* (*acceptId)(char*), ME_Location (*acceptLocation)(ME_Location));
ME_Location ME_visitLocation(ME_Location arg, char* (*acceptFile)(char*), ME_Area (*acceptArea)(ME_Area));
ME_Area ME_visitArea(ME_Area arg, int (*acceptStartLine)(int), int (*acceptStartColumn)(int), int (*acceptEndLine)(int), int (*acceptEndColumn)(int), int (*acceptStartOffset)(int), int (*acceptEndOffset)(int));

/*}}}  */

#endif /* _ERRORS_H */
