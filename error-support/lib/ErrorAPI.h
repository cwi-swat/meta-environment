#ifndef _ERRORAPI_H
#define _ERRORAPI_H

/*{{{  includes */

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "ErrorAPI_dict.h"

/*}}}  */

/*{{{  typedefs */

typedef struct _ERR_Feedback *ERR_Feedback;
typedef struct _ERR_SubjectList *ERR_SubjectList;
typedef struct _ERR_Subject *ERR_Subject;
typedef struct _ERR_Location *ERR_Location;
typedef struct _ERR_Area *ERR_Area;

/*}}}  */

/*{{{  definition of bottom types */


/*}}}  */

void ERR_initErrorAPIApi(void);

/*{{{  term conversion functions */

ERR_Feedback ERR_FeedbackFromTerm(ATerm t);
ATerm ERR_FeedbackToTerm(ERR_Feedback arg);
ERR_SubjectList ERR_SubjectListFromTerm(ATerm t);
ATerm ERR_SubjectListToTerm(ERR_SubjectList arg);
ERR_Subject ERR_SubjectFromTerm(ATerm t);
ATerm ERR_SubjectToTerm(ERR_Subject arg);
ERR_Location ERR_LocationFromTerm(ATerm t);
ATerm ERR_LocationToTerm(ERR_Location arg);
ERR_Area ERR_AreaFromTerm(ATerm t);
ATerm ERR_AreaToTerm(ERR_Area arg);

/*}}}  */
/*{{{  list functions */

int ERR_getSubjectListLength(ERR_SubjectList arg);
ERR_SubjectList ERR_reverseSubjectList(ERR_SubjectList arg);
ERR_SubjectList ERR_appendSubjectList(ERR_SubjectList arg, ERR_Subject elem);
ERR_SubjectList ERR_concatSubjectList(ERR_SubjectList arg0,
				      ERR_SubjectList arg1);
ERR_SubjectList ERR_sliceSubjectList(ERR_SubjectList arg, int start, int end);
ERR_Subject ERR_getSubjectListSubjectAt(ERR_SubjectList arg, int index);
ERR_SubjectList ERR_replaceSubjectListSubjectAt(ERR_SubjectList arg,
						ERR_Subject elem, int index);
ERR_SubjectList ERR_makeSubjectList2(ERR_Subject elem1, ERR_Subject elem2);
ERR_SubjectList ERR_makeSubjectList3(ERR_Subject elem1, ERR_Subject elem2,
				     ERR_Subject elem3);
ERR_SubjectList ERR_makeSubjectList4(ERR_Subject elem1, ERR_Subject elem2,
				     ERR_Subject elem3, ERR_Subject elem4);
ERR_SubjectList ERR_makeSubjectList5(ERR_Subject elem1, ERR_Subject elem2,
				     ERR_Subject elem3, ERR_Subject elem4,
				     ERR_Subject elem5);
ERR_SubjectList ERR_makeSubjectList6(ERR_Subject elem1, ERR_Subject elem2,
				     ERR_Subject elem3, ERR_Subject elem4,
				     ERR_Subject elem5, ERR_Subject elem6);

/*}}}  */
/*{{{  constructors */

ERR_Feedback ERR_makeFeedbackInfo(char *id, char *producerId,
				  char *producerType, char *description,
				  ERR_SubjectList list);
ERR_Feedback ERR_makeFeedbackWarning(char *id, char *producerId,
				     char *producerType, char *description,
				     ERR_SubjectList list);
ERR_Feedback ERR_makeFeedbackError(char *id, char *producerId,
				   char *producerType, char *description,
				   ERR_SubjectList list);
ERR_Feedback ERR_makeFeedbackFatalError(char *id, char *producerId,
					char *producerType, char *description,
					ERR_SubjectList list);
ERR_SubjectList ERR_makeSubjectListEmpty();
ERR_SubjectList ERR_makeSubjectListSingle(ERR_Subject head);
ERR_SubjectList ERR_makeSubjectListMany(ERR_Subject head,
					ERR_SubjectList tail);
ERR_Subject ERR_makeSubjectLocatable(char *id, ERR_Location Location);
ERR_Subject ERR_makeSubjectUnlocatable(char *id);
ERR_Location ERR_makeLocationLocation(char *filename, ERR_Area Area);
ERR_Area ERR_makeAreaArea(int startLine, int startColumn, int endLine,
			  int endColumn, int startOffset, int endOffset);
ERR_Area ERR_makeAreaNoArea();

/*}}}  */
/*{{{  equality functions */

ATbool ERR_isEqualFeedback(ERR_Feedback arg0, ERR_Feedback arg1);
ATbool ERR_isEqualSubjectList(ERR_SubjectList arg0, ERR_SubjectList arg1);
ATbool ERR_isEqualSubject(ERR_Subject arg0, ERR_Subject arg1);
ATbool ERR_isEqualLocation(ERR_Location arg0, ERR_Location arg1);
ATbool ERR_isEqualArea(ERR_Area arg0, ERR_Area arg1);

/*}}}  */
/*{{{  ERR_Feedback accessors */

ATbool ERR_isValidFeedback(ERR_Feedback arg);
inline ATbool ERR_isFeedbackInfo(ERR_Feedback arg);
inline ATbool ERR_isFeedbackWarning(ERR_Feedback arg);
inline ATbool ERR_isFeedbackError(ERR_Feedback arg);
inline ATbool ERR_isFeedbackFatalError(ERR_Feedback arg);
ATbool ERR_hasFeedbackId(ERR_Feedback arg);
char *ERR_getFeedbackId(ERR_Feedback arg);
ERR_Feedback ERR_setFeedbackId(ERR_Feedback arg, char *id);
ATbool ERR_hasFeedbackProducerId(ERR_Feedback arg);
char *ERR_getFeedbackProducerId(ERR_Feedback arg);
ERR_Feedback ERR_setFeedbackProducerId(ERR_Feedback arg, char *producerId);
ATbool ERR_hasFeedbackProducerType(ERR_Feedback arg);
char *ERR_getFeedbackProducerType(ERR_Feedback arg);
ERR_Feedback ERR_setFeedbackProducerType(ERR_Feedback arg,
					 char *producerType);
ATbool ERR_hasFeedbackDescription(ERR_Feedback arg);
char *ERR_getFeedbackDescription(ERR_Feedback arg);
ERR_Feedback ERR_setFeedbackDescription(ERR_Feedback arg, char *description);
ATbool ERR_hasFeedbackList(ERR_Feedback arg);
ERR_SubjectList ERR_getFeedbackList(ERR_Feedback arg);
ERR_Feedback ERR_setFeedbackList(ERR_Feedback arg, ERR_SubjectList list);

/*}}}  */
/*{{{  ERR_SubjectList accessors */

ATbool ERR_isValidSubjectList(ERR_SubjectList arg);
inline ATbool ERR_isSubjectListEmpty(ERR_SubjectList arg);
inline ATbool ERR_isSubjectListSingle(ERR_SubjectList arg);
inline ATbool ERR_isSubjectListMany(ERR_SubjectList arg);
ATbool ERR_hasSubjectListHead(ERR_SubjectList arg);
ERR_Subject ERR_getSubjectListHead(ERR_SubjectList arg);
ERR_SubjectList ERR_setSubjectListHead(ERR_SubjectList arg, ERR_Subject head);
ATbool ERR_hasSubjectListTail(ERR_SubjectList arg);
ERR_SubjectList ERR_getSubjectListTail(ERR_SubjectList arg);
ERR_SubjectList ERR_setSubjectListTail(ERR_SubjectList arg,
				       ERR_SubjectList tail);

/*}}}  */
/*{{{  ERR_Subject accessors */

ATbool ERR_isValidSubject(ERR_Subject arg);
inline ATbool ERR_isSubjectLocatable(ERR_Subject arg);
inline ATbool ERR_isSubjectUnlocatable(ERR_Subject arg);
ATbool ERR_hasSubjectId(ERR_Subject arg);
char *ERR_getSubjectId(ERR_Subject arg);
ERR_Subject ERR_setSubjectId(ERR_Subject arg, char *id);
ATbool ERR_hasSubjectLocation(ERR_Subject arg);
ERR_Location ERR_getSubjectLocation(ERR_Subject arg);
ERR_Subject ERR_setSubjectLocation(ERR_Subject arg, ERR_Location Location);

/*}}}  */
/*{{{  ERR_Location accessors */

ATbool ERR_isValidLocation(ERR_Location arg);
inline ATbool ERR_isLocationLocation(ERR_Location arg);
ATbool ERR_hasLocationFilename(ERR_Location arg);
char *ERR_getLocationFilename(ERR_Location arg);
ERR_Location ERR_setLocationFilename(ERR_Location arg, char *filename);
ATbool ERR_hasLocationArea(ERR_Location arg);
ERR_Area ERR_getLocationArea(ERR_Location arg);
ERR_Location ERR_setLocationArea(ERR_Location arg, ERR_Area Area);

/*}}}  */
/*{{{  ERR_Area accessors */

ATbool ERR_isValidArea(ERR_Area arg);
inline ATbool ERR_isAreaArea(ERR_Area arg);
inline ATbool ERR_isAreaNoArea(ERR_Area arg);
ATbool ERR_hasAreaStartLine(ERR_Area arg);
int ERR_getAreaStartLine(ERR_Area arg);
ERR_Area ERR_setAreaStartLine(ERR_Area arg, int startLine);
ATbool ERR_hasAreaStartColumn(ERR_Area arg);
int ERR_getAreaStartColumn(ERR_Area arg);
ERR_Area ERR_setAreaStartColumn(ERR_Area arg, int startColumn);
ATbool ERR_hasAreaEndLine(ERR_Area arg);
int ERR_getAreaEndLine(ERR_Area arg);
ERR_Area ERR_setAreaEndLine(ERR_Area arg, int endLine);
ATbool ERR_hasAreaEndColumn(ERR_Area arg);
int ERR_getAreaEndColumn(ERR_Area arg);
ERR_Area ERR_setAreaEndColumn(ERR_Area arg, int endColumn);
ATbool ERR_hasAreaStartOffset(ERR_Area arg);
int ERR_getAreaStartOffset(ERR_Area arg);
ERR_Area ERR_setAreaStartOffset(ERR_Area arg, int startOffset);
ATbool ERR_hasAreaEndOffset(ERR_Area arg);
int ERR_getAreaEndOffset(ERR_Area arg);
ERR_Area ERR_setAreaEndOffset(ERR_Area arg, int endOffset);

/*}}}  */
/*{{{  sort visitors */

ERR_Feedback ERR_visitFeedback(ERR_Feedback arg, char *(*acceptId) (char *),
			       char *(*acceptProducerId) (char *),
			       char *(*acceptProducerType) (char *),
			       char *(*acceptDescription) (char *),
			       ERR_SubjectList(*acceptList)
			       (ERR_SubjectList));
ERR_SubjectList ERR_visitSubjectList(ERR_SubjectList arg,
				     ERR_Subject(*acceptHead) (ERR_Subject));
ERR_Subject ERR_visitSubject(ERR_Subject arg, char *(*acceptId) (char *),
			     ERR_Location(*acceptLocation) (ERR_Location));
ERR_Location ERR_visitLocation(ERR_Location arg,
			       char *(*acceptFilename) (char *),
			       ERR_Area(*acceptArea) (ERR_Area));
ERR_Area ERR_visitArea(ERR_Area arg, int (*acceptStartLine) (int),
		       int (*acceptStartColumn) (int),
		       int (*acceptEndLine) (int),
		       int (*acceptEndColumn) (int),
		       int (*acceptStartOffset) (int),
		       int (*acceptEndOffset) (int));

/*}}}  */

#endif /* _ERRORAPI_H */
