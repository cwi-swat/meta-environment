#ifndef _ERRORAPI_H
#define _ERRORAPI_H

/*{{{  includes */

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "ErrorAPI_dict.h"

/*}}}  */

/*{{{  typedefs */

typedef struct _ME_Feedback *ME_Feedback;
typedef struct _ME_SubjectList *ME_SubjectList;
typedef struct _ME_Subject *ME_Subject;
typedef struct _ME_Location *ME_Location;
typedef struct _ME_Area *ME_Area;

/*}}}  */

/*{{{  definition of bottom types */


/*}}}  */

void ME_initErrorAPIApi(void);

/*{{{  term conversion functions */

ME_Feedback ME_FeedbackFromTerm(ATerm t);
ATerm ME_FeedbackToTerm(ME_Feedback arg);
ME_SubjectList ME_SubjectListFromTerm(ATerm t);
ATerm ME_SubjectListToTerm(ME_SubjectList arg);
ME_Subject ME_SubjectFromTerm(ATerm t);
ATerm ME_SubjectToTerm(ME_Subject arg);
ME_Location ME_LocationFromTerm(ATerm t);
ATerm ME_LocationToTerm(ME_Location arg);
ME_Area ME_AreaFromTerm(ATerm t);
ATerm ME_AreaToTerm(ME_Area arg);

/*}}}  */
/*{{{  list functions */

int ME_getSubjectListLength(ME_SubjectList arg);
ME_SubjectList ME_reverseSubjectList(ME_SubjectList arg);
ME_SubjectList ME_appendSubjectList(ME_SubjectList arg, ME_Subject elem);
ME_SubjectList ME_concatSubjectList(ME_SubjectList arg0, ME_SubjectList arg1);
ME_SubjectList ME_sliceSubjectList(ME_SubjectList arg, int start, int end);
ME_Subject ME_getSubjectListSubjectAt(ME_SubjectList arg, int index);
ME_SubjectList ME_replaceSubjectListSubjectAt(ME_SubjectList arg,
					      ME_Subject elem, int index);
ME_SubjectList ME_makeSubjectList2(ME_Subject elem1, ME_Subject elem2);
ME_SubjectList ME_makeSubjectList3(ME_Subject elem1, ME_Subject elem2,
				   ME_Subject elem3);
ME_SubjectList ME_makeSubjectList4(ME_Subject elem1, ME_Subject elem2,
				   ME_Subject elem3, ME_Subject elem4);
ME_SubjectList ME_makeSubjectList5(ME_Subject elem1, ME_Subject elem2,
				   ME_Subject elem3, ME_Subject elem4,
				   ME_Subject elem5);
ME_SubjectList ME_makeSubjectList6(ME_Subject elem1, ME_Subject elem2,
				   ME_Subject elem3, ME_Subject elem4,
				   ME_Subject elem5, ME_Subject elem6);

/*}}}  */
/*{{{  constructors */

ME_Feedback ME_makeFeedbackInfo(char *id, char *producerId,
				char *producerType, char *description,
				ME_SubjectList list);
ME_Feedback ME_makeFeedbackWarning(char *id, char *producerId,
				   char *producerType, char *description,
				   ME_SubjectList list);
ME_Feedback ME_makeFeedbackError(char *id, char *producerId,
				 char *producerType, char *description,
				 ME_SubjectList list);
ME_Feedback ME_makeFeedbackFatalError(char *id, char *producerId,
				      char *producerType, char *description,
				      ME_SubjectList list);
ME_SubjectList ME_makeSubjectListEmpty();
ME_SubjectList ME_makeSubjectListSingle(ME_Subject head);
ME_SubjectList ME_makeSubjectListMany(ME_Subject head, ME_SubjectList tail);
ME_Subject ME_makeSubjectLocatable(char *id, ME_Location Location);
ME_Subject ME_makeSubjectUnlocatable(char *id);
ME_Location ME_makeLocationLocation(char *filename, ME_Area Area);
ME_Area ME_makeAreaArea(int startLine, int startColumn, int endLine,
			int endColumn, int startOffset, int endOffset);
ME_Area ME_makeAreaNoArea();

/*}}}  */
/*{{{  equality functions */

ATbool ME_isEqualFeedback(ME_Feedback arg0, ME_Feedback arg1);
ATbool ME_isEqualSubjectList(ME_SubjectList arg0, ME_SubjectList arg1);
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
ATbool ME_hasFeedbackId(ME_Feedback arg);
char *ME_getFeedbackId(ME_Feedback arg);
ME_Feedback ME_setFeedbackId(ME_Feedback arg, char *id);
ATbool ME_hasFeedbackProducerId(ME_Feedback arg);
char *ME_getFeedbackProducerId(ME_Feedback arg);
ME_Feedback ME_setFeedbackProducerId(ME_Feedback arg, char *producerId);
ATbool ME_hasFeedbackProducerType(ME_Feedback arg);
char *ME_getFeedbackProducerType(ME_Feedback arg);
ME_Feedback ME_setFeedbackProducerType(ME_Feedback arg, char *producerType);
ATbool ME_hasFeedbackDescription(ME_Feedback arg);
char *ME_getFeedbackDescription(ME_Feedback arg);
ME_Feedback ME_setFeedbackDescription(ME_Feedback arg, char *description);
ATbool ME_hasFeedbackList(ME_Feedback arg);
ME_SubjectList ME_getFeedbackList(ME_Feedback arg);
ME_Feedback ME_setFeedbackList(ME_Feedback arg, ME_SubjectList list);

/*}}}  */
/*{{{  ME_SubjectList accessors */

ATbool ME_isValidSubjectList(ME_SubjectList arg);
inline ATbool ME_isSubjectListEmpty(ME_SubjectList arg);
inline ATbool ME_isSubjectListSingle(ME_SubjectList arg);
inline ATbool ME_isSubjectListMany(ME_SubjectList arg);
ATbool ME_hasSubjectListHead(ME_SubjectList arg);
ME_Subject ME_getSubjectListHead(ME_SubjectList arg);
ME_SubjectList ME_setSubjectListHead(ME_SubjectList arg, ME_Subject head);
ATbool ME_hasSubjectListTail(ME_SubjectList arg);
ME_SubjectList ME_getSubjectListTail(ME_SubjectList arg);
ME_SubjectList ME_setSubjectListTail(ME_SubjectList arg, ME_SubjectList tail);

/*}}}  */
/*{{{  ME_Subject accessors */

ATbool ME_isValidSubject(ME_Subject arg);
inline ATbool ME_isSubjectLocatable(ME_Subject arg);
inline ATbool ME_isSubjectUnlocatable(ME_Subject arg);
ATbool ME_hasSubjectId(ME_Subject arg);
char *ME_getSubjectId(ME_Subject arg);
ME_Subject ME_setSubjectId(ME_Subject arg, char *id);
ATbool ME_hasSubjectLocation(ME_Subject arg);
ME_Location ME_getSubjectLocation(ME_Subject arg);
ME_Subject ME_setSubjectLocation(ME_Subject arg, ME_Location Location);

/*}}}  */
/*{{{  ME_Location accessors */

ATbool ME_isValidLocation(ME_Location arg);
inline ATbool ME_isLocationLocation(ME_Location arg);
ATbool ME_hasLocationFilename(ME_Location arg);
char *ME_getLocationFilename(ME_Location arg);
ME_Location ME_setLocationFilename(ME_Location arg, char *filename);
ATbool ME_hasLocationArea(ME_Location arg);
ME_Area ME_getLocationArea(ME_Location arg);
ME_Location ME_setLocationArea(ME_Location arg, ME_Area Area);

/*}}}  */
/*{{{  ME_Area accessors */

ATbool ME_isValidArea(ME_Area arg);
inline ATbool ME_isAreaArea(ME_Area arg);
inline ATbool ME_isAreaNoArea(ME_Area arg);
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

ME_Feedback ME_visitFeedback(ME_Feedback arg, char *(*acceptId) (char *),
			     char *(*acceptProducerId) (char *),
			     char *(*acceptProducerType) (char *),
			     char *(*acceptDescription) (char *),
			     ME_SubjectList(*acceptList) (ME_SubjectList));
ME_SubjectList ME_visitSubjectList(ME_SubjectList arg,
				   ME_Subject(*acceptHead) (ME_Subject));
ME_Subject ME_visitSubject(ME_Subject arg, char *(*acceptId) (char *),
			   ME_Location(*acceptLocation) (ME_Location));
ME_Location ME_visitLocation(ME_Location arg,
			     char *(*acceptFilename) (char *),
			     ME_Area(*acceptArea) (ME_Area));
ME_Area ME_visitArea(ME_Area arg, int (*acceptStartLine) (int),
		     int (*acceptStartColumn) (int),
		     int (*acceptEndLine) (int), int (*acceptEndColumn) (int),
		     int (*acceptStartOffset) (int),
		     int (*acceptEndOffset) (int));

/*}}}  */

#endif /* _ERRORAPI_H */
