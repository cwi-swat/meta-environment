#ifndef _ERRORAPI_H
#define _ERRORAPI_H

/*{{{  includes */

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "ErrorAPI_dict.h"

/*}}}  */

/*{{{  typedefs */

typedef struct _ERR_Normal *ERR_Normal;
typedef struct _ERR_Escaped *ERR_Escaped;
typedef struct _ERR_StrCon *ERR_StrCon;
typedef struct _ERR_NatCon *ERR_NatCon;
typedef struct _ERR_Summary *ERR_Summary;
typedef struct _ERR_FeedbackList *ERR_FeedbackList;
typedef struct _ERR_Feedback *ERR_Feedback;
typedef struct _ERR_SubjectList *ERR_SubjectList;
typedef struct _ERR_Subject *ERR_Subject;
typedef struct _ERR_Location *ERR_Location;
typedef struct _ERR_Area *ERR_Area;

/*}}}  */

/*{{{  definition of bottom types */


/*}}}  */

void ERR_initErrorAPIApi(void);

/*{{{  protect functions */

void ERR_protectNormal(ERR_Normal * arg);
void ERR_protectEscaped(ERR_Escaped * arg);
void ERR_protectStrCon(ERR_StrCon * arg);
void ERR_protectNatCon(ERR_NatCon * arg);
void ERR_protectSummary(ERR_Summary * arg);
void ERR_protectFeedbackList(ERR_FeedbackList * arg);
void ERR_protectFeedback(ERR_Feedback * arg);
void ERR_protectSubjectList(ERR_SubjectList * arg);
void ERR_protectSubject(ERR_Subject * arg);
void ERR_protectLocation(ERR_Location * arg);
void ERR_protectArea(ERR_Area * arg);

/*}}}  */
/*{{{  term conversion functions */

ERR_Normal ERR_NormalFromTerm(ATerm t);
ATerm ERR_NormalToTerm(ERR_Normal arg);
ERR_Escaped ERR_EscapedFromTerm(ATerm t);
ATerm ERR_EscapedToTerm(ERR_Escaped arg);
ERR_StrCon ERR_StrConFromTerm(ATerm t);
ATerm ERR_StrConToTerm(ERR_StrCon arg);
ERR_NatCon ERR_NatConFromTerm(ATerm t);
ATerm ERR_NatConToTerm(ERR_NatCon arg);
ERR_Summary ERR_SummaryFromTerm(ATerm t);
ATerm ERR_SummaryToTerm(ERR_Summary arg);
ERR_FeedbackList ERR_FeedbackListFromTerm(ATerm t);
ATerm ERR_FeedbackListToTerm(ERR_FeedbackList arg);
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

int ERR_getFeedbackListLength(ERR_FeedbackList arg);
ERR_FeedbackList ERR_reverseFeedbackList(ERR_FeedbackList arg);
ERR_FeedbackList ERR_appendFeedbackList(ERR_FeedbackList arg,
					ERR_Feedback elem);
ERR_FeedbackList ERR_concatFeedbackList(ERR_FeedbackList arg0,
					ERR_FeedbackList arg1);
ERR_FeedbackList ERR_sliceFeedbackList(ERR_FeedbackList arg, int start,
				       int end);
ERR_Feedback ERR_getFeedbackListFeedbackAt(ERR_FeedbackList arg, int index);
ERR_FeedbackList ERR_replaceFeedbackListFeedbackAt(ERR_FeedbackList arg,
						   ERR_Feedback elem,
						   int index);
ERR_FeedbackList ERR_makeFeedbackList2(ERR_Feedback elem1,
				       ERR_Feedback elem2);
ERR_FeedbackList ERR_makeFeedbackList3(ERR_Feedback elem1, ERR_Feedback elem2,
				       ERR_Feedback elem3);
ERR_FeedbackList ERR_makeFeedbackList4(ERR_Feedback elem1, ERR_Feedback elem2,
				       ERR_Feedback elem3,
				       ERR_Feedback elem4);
ERR_FeedbackList ERR_makeFeedbackList5(ERR_Feedback elem1, ERR_Feedback elem2,
				       ERR_Feedback elem3, ERR_Feedback elem4,
				       ERR_Feedback elem5);
ERR_FeedbackList ERR_makeFeedbackList6(ERR_Feedback elem1, ERR_Feedback elem2,
				       ERR_Feedback elem3, ERR_Feedback elem4,
				       ERR_Feedback elem5,
				       ERR_Feedback elem6);
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

ERR_Normal ERR_makeNormalNormal(char *string);
ERR_Escaped ERR_makeEscapedEscaped(char *string);
ERR_StrCon ERR_makeStrConStrCon(char *string);
ERR_NatCon ERR_makeNatConNatCon(char *string);
ERR_Summary ERR_makeSummaryFeedback(char *producer, char *id,
				    ERR_FeedbackList list);
ERR_FeedbackList ERR_makeFeedbackListEmpty();
ERR_FeedbackList ERR_makeFeedbackListSingle(ERR_Feedback head);
ERR_FeedbackList ERR_makeFeedbackListMany(ERR_Feedback head,
					  ERR_FeedbackList tail);
ERR_Feedback ERR_makeFeedbackInfo(char *description, ERR_SubjectList list);
ERR_Feedback ERR_makeFeedbackWarning(char *description, ERR_SubjectList list);
ERR_Feedback ERR_makeFeedbackError(char *description, ERR_SubjectList list);
ERR_Feedback ERR_makeFeedbackFatalError(char *description,
					ERR_SubjectList list);
ERR_SubjectList ERR_makeSubjectListEmpty();
ERR_SubjectList ERR_makeSubjectListSingle(ERR_Subject head);
ERR_SubjectList ERR_makeSubjectListMany(ERR_Subject head,
					ERR_SubjectList tail);
ERR_Subject ERR_makeSubjectSubject(char *description, ERR_Location Location);
ERR_Location ERR_makeLocationLocation(char *filename, ERR_Area Area);
ERR_Location ERR_makeLocationNoLocation();
ERR_Area ERR_makeAreaArea(int beginLine, int beginColumn, int endLine,
			  int endColumn, int offset, int length);
ERR_Area ERR_makeAreaNoArea();

/*}}}  */
/*{{{  equality functions */

ATbool ERR_isEqualNormal(ERR_Normal arg0, ERR_Normal arg1);
ATbool ERR_isEqualEscaped(ERR_Escaped arg0, ERR_Escaped arg1);
ATbool ERR_isEqualStrCon(ERR_StrCon arg0, ERR_StrCon arg1);
ATbool ERR_isEqualNatCon(ERR_NatCon arg0, ERR_NatCon arg1);
ATbool ERR_isEqualSummary(ERR_Summary arg0, ERR_Summary arg1);
ATbool ERR_isEqualFeedbackList(ERR_FeedbackList arg0, ERR_FeedbackList arg1);
ATbool ERR_isEqualFeedback(ERR_Feedback arg0, ERR_Feedback arg1);
ATbool ERR_isEqualSubjectList(ERR_SubjectList arg0, ERR_SubjectList arg1);
ATbool ERR_isEqualSubject(ERR_Subject arg0, ERR_Subject arg1);
ATbool ERR_isEqualLocation(ERR_Location arg0, ERR_Location arg1);
ATbool ERR_isEqualArea(ERR_Area arg0, ERR_Area arg1);

/*}}}  */
/*{{{  ERR_Normal accessors */

ATbool ERR_isValidNormal(ERR_Normal arg);
inline ATbool ERR_isNormalNormal(ERR_Normal arg);
ATbool ERR_hasNormalString(ERR_Normal arg);
char *ERR_getNormalString(ERR_Normal arg);
ERR_Normal ERR_setNormalString(ERR_Normal arg, char *string);

/*}}}  */
/*{{{  ERR_Escaped accessors */

ATbool ERR_isValidEscaped(ERR_Escaped arg);
inline ATbool ERR_isEscapedEscaped(ERR_Escaped arg);
ATbool ERR_hasEscapedString(ERR_Escaped arg);
char *ERR_getEscapedString(ERR_Escaped arg);
ERR_Escaped ERR_setEscapedString(ERR_Escaped arg, char *string);

/*}}}  */
/*{{{  ERR_StrCon accessors */

ATbool ERR_isValidStrCon(ERR_StrCon arg);
inline ATbool ERR_isStrConStrCon(ERR_StrCon arg);
ATbool ERR_hasStrConString(ERR_StrCon arg);
char *ERR_getStrConString(ERR_StrCon arg);
ERR_StrCon ERR_setStrConString(ERR_StrCon arg, char *string);

/*}}}  */
/*{{{  ERR_NatCon accessors */

ATbool ERR_isValidNatCon(ERR_NatCon arg);
inline ATbool ERR_isNatConNatCon(ERR_NatCon arg);
ATbool ERR_hasNatConString(ERR_NatCon arg);
char *ERR_getNatConString(ERR_NatCon arg);
ERR_NatCon ERR_setNatConString(ERR_NatCon arg, char *string);

/*}}}  */
/*{{{  ERR_Summary accessors */

ATbool ERR_isValidSummary(ERR_Summary arg);
inline ATbool ERR_isSummaryFeedback(ERR_Summary arg);
ATbool ERR_hasSummaryProducer(ERR_Summary arg);
char *ERR_getSummaryProducer(ERR_Summary arg);
ERR_Summary ERR_setSummaryProducer(ERR_Summary arg, char *producer);
ATbool ERR_hasSummaryId(ERR_Summary arg);
char *ERR_getSummaryId(ERR_Summary arg);
ERR_Summary ERR_setSummaryId(ERR_Summary arg, char *id);
ATbool ERR_hasSummaryList(ERR_Summary arg);
ERR_FeedbackList ERR_getSummaryList(ERR_Summary arg);
ERR_Summary ERR_setSummaryList(ERR_Summary arg, ERR_FeedbackList list);

/*}}}  */
/*{{{  ERR_FeedbackList accessors */

ATbool ERR_isValidFeedbackList(ERR_FeedbackList arg);
inline ATbool ERR_isFeedbackListEmpty(ERR_FeedbackList arg);
inline ATbool ERR_isFeedbackListSingle(ERR_FeedbackList arg);
inline ATbool ERR_isFeedbackListMany(ERR_FeedbackList arg);
ATbool ERR_hasFeedbackListHead(ERR_FeedbackList arg);
ERR_Feedback ERR_getFeedbackListHead(ERR_FeedbackList arg);
ERR_FeedbackList ERR_setFeedbackListHead(ERR_FeedbackList arg,
					 ERR_Feedback head);
ATbool ERR_hasFeedbackListTail(ERR_FeedbackList arg);
ERR_FeedbackList ERR_getFeedbackListTail(ERR_FeedbackList arg);
ERR_FeedbackList ERR_setFeedbackListTail(ERR_FeedbackList arg,
					 ERR_FeedbackList tail);

/*}}}  */
/*{{{  ERR_Feedback accessors */

ATbool ERR_isValidFeedback(ERR_Feedback arg);
inline ATbool ERR_isFeedbackInfo(ERR_Feedback arg);
inline ATbool ERR_isFeedbackWarning(ERR_Feedback arg);
inline ATbool ERR_isFeedbackError(ERR_Feedback arg);
inline ATbool ERR_isFeedbackFatalError(ERR_Feedback arg);
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
inline ATbool ERR_isSubjectSubject(ERR_Subject arg);
ATbool ERR_hasSubjectDescription(ERR_Subject arg);
char *ERR_getSubjectDescription(ERR_Subject arg);
ERR_Subject ERR_setSubjectDescription(ERR_Subject arg, char *description);
ATbool ERR_hasSubjectLocation(ERR_Subject arg);
ERR_Location ERR_getSubjectLocation(ERR_Subject arg);
ERR_Subject ERR_setSubjectLocation(ERR_Subject arg, ERR_Location Location);

/*}}}  */
/*{{{  ERR_Location accessors */

ATbool ERR_isValidLocation(ERR_Location arg);
inline ATbool ERR_isLocationLocation(ERR_Location arg);
inline ATbool ERR_isLocationNoLocation(ERR_Location arg);
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
ATbool ERR_hasAreaBeginLine(ERR_Area arg);
int ERR_getAreaBeginLine(ERR_Area arg);
ERR_Area ERR_setAreaBeginLine(ERR_Area arg, int beginLine);
ATbool ERR_hasAreaBeginColumn(ERR_Area arg);
int ERR_getAreaBeginColumn(ERR_Area arg);
ERR_Area ERR_setAreaBeginColumn(ERR_Area arg, int beginColumn);
ATbool ERR_hasAreaEndLine(ERR_Area arg);
int ERR_getAreaEndLine(ERR_Area arg);
ERR_Area ERR_setAreaEndLine(ERR_Area arg, int endLine);
ATbool ERR_hasAreaEndColumn(ERR_Area arg);
int ERR_getAreaEndColumn(ERR_Area arg);
ERR_Area ERR_setAreaEndColumn(ERR_Area arg, int endColumn);
ATbool ERR_hasAreaOffset(ERR_Area arg);
int ERR_getAreaOffset(ERR_Area arg);
ERR_Area ERR_setAreaOffset(ERR_Area arg, int offset);
ATbool ERR_hasAreaLength(ERR_Area arg);
int ERR_getAreaLength(ERR_Area arg);
ERR_Area ERR_setAreaLength(ERR_Area arg, int length);

/*}}}  */
/*{{{  sort visitors */

ERR_Normal ERR_visitNormal(ERR_Normal arg, char *(*acceptString) (char *));
ERR_Escaped ERR_visitEscaped(ERR_Escaped arg, char *(*acceptString) (char *));
ERR_StrCon ERR_visitStrCon(ERR_StrCon arg, char *(*acceptString) (char *));
ERR_NatCon ERR_visitNatCon(ERR_NatCon arg, char *(*acceptString) (char *));
ERR_Summary ERR_visitSummary(ERR_Summary arg,
			     char *(*acceptProducer) (char *),
			     char *(*acceptId) (char *),
			     ERR_FeedbackList(*acceptList)
			     (ERR_FeedbackList));
ERR_FeedbackList ERR_visitFeedbackList(ERR_FeedbackList arg,
				       ERR_Feedback(*acceptHead)
				       (ERR_Feedback));
ERR_Feedback ERR_visitFeedback(ERR_Feedback arg,
			       char *(*acceptDescription) (char *),
			       ERR_SubjectList(*acceptList)
			       (ERR_SubjectList));
ERR_SubjectList ERR_visitSubjectList(ERR_SubjectList arg,
				     ERR_Subject(*acceptHead) (ERR_Subject));
ERR_Subject ERR_visitSubject(ERR_Subject arg,
			     char *(*acceptDescription) (char *),
			     ERR_Location(*acceptLocation) (ERR_Location));
ERR_Location ERR_visitLocation(ERR_Location arg,
			       char *(*acceptFilename) (char *),
			       ERR_Area(*acceptArea) (ERR_Area));
ERR_Area ERR_visitArea(ERR_Area arg, int (*acceptBeginLine) (int),
		       int (*acceptBeginColumn) (int),
		       int (*acceptEndLine) (int),
		       int (*acceptEndColumn) (int),
		       int (*acceptOffset) (int), int (*acceptLength) (int));

/*}}}  */

#endif /* _ERRORAPI_H */
