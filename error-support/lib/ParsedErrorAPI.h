#ifndef _PARSEDERRORAPI_H
#define _PARSEDERRORAPI_H

/*{{{  includes */

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "ParsedErrorAPI_dict.h"

/*}}}  */

/*{{{  typedefs */

typedef struct _PERR_Summary *PERR_Summary;
typedef struct _PERR_FeedbackList *PERR_FeedbackList;
typedef struct _PERR_Feedback *PERR_Feedback;
typedef struct _PERR_SubjectList *PERR_SubjectList;
typedef struct _PERR_Subject *PERR_Subject;
typedef struct _PERR_Location *PERR_Location;
typedef struct _PERR_Area *PERR_Area;
typedef struct _PERR_NatCon *PERR_NatCon;
typedef struct _PERR_StrCon *PERR_StrCon;
typedef struct _PERR_OptLayout *PERR_OptLayout;
typedef struct _PERR_Start *PERR_Start;

/*}}}  */

/*{{{  definition of bottom types */


/*}}}  */

void PERR_initParsedErrorAPIApi(void);

/*{{{  term conversion functions */

PERR_Summary PERR_SummaryFromTerm(ATerm t);
ATerm PERR_SummaryToTerm(PERR_Summary arg);
PERR_FeedbackList PERR_FeedbackListFromTerm(ATerm t);
ATerm PERR_FeedbackListToTerm(PERR_FeedbackList arg);
PERR_Feedback PERR_FeedbackFromTerm(ATerm t);
ATerm PERR_FeedbackToTerm(PERR_Feedback arg);
PERR_SubjectList PERR_SubjectListFromTerm(ATerm t);
ATerm PERR_SubjectListToTerm(PERR_SubjectList arg);
PERR_Subject PERR_SubjectFromTerm(ATerm t);
ATerm PERR_SubjectToTerm(PERR_Subject arg);
PERR_Location PERR_LocationFromTerm(ATerm t);
ATerm PERR_LocationToTerm(PERR_Location arg);
PERR_Area PERR_AreaFromTerm(ATerm t);
ATerm PERR_AreaToTerm(PERR_Area arg);
PERR_NatCon PERR_NatConFromTerm(ATerm t);
ATerm PERR_NatConToTerm(PERR_NatCon arg);
PERR_StrCon PERR_StrConFromTerm(ATerm t);
ATerm PERR_StrConToTerm(PERR_StrCon arg);
PERR_OptLayout PERR_OptLayoutFromTerm(ATerm t);
ATerm PERR_OptLayoutToTerm(PERR_OptLayout arg);
PERR_Start PERR_StartFromTerm(ATerm t);
ATerm PERR_StartToTerm(PERR_Start arg);

/*}}}  */
/*{{{  list functions */

int PERR_getFeedbackListLength(PERR_FeedbackList arg);
PERR_FeedbackList reverseFeedbackList(PERR_FeedbackList arg);
PERR_FeedbackList PERR_appendFeedbackList(PERR_FeedbackList arg0,
					  PERR_OptLayout wsAfterHead,
					  PERR_OptLayout wsAfterSep,
					  PERR_Feedback arg1);
PERR_FeedbackList PERR_concatFeedbackList(PERR_FeedbackList arg0,
					  PERR_OptLayout wsAfterHead,
					  PERR_OptLayout wsAfterSep,
					  PERR_FeedbackList arg1);
PERR_FeedbackList PERR_sliceFeedbackList(PERR_FeedbackList arg, int start,
					 int end);
PERR_Feedback PERR_getFeedbackListFeedbackAt(PERR_FeedbackList arg,
					     int index);
PERR_FeedbackList PERR_replaceFeedbackListFeedbackAt(PERR_FeedbackList arg,
						     PERR_Feedback elem,
						     int index);
PERR_FeedbackList PERR_makeFeedbackList2(PERR_OptLayout wsAfterHead,
					 PERR_OptLayout wsAfterSep,
					 PERR_Feedback elem1,
					 PERR_Feedback elem2);
PERR_FeedbackList PERR_makeFeedbackList3(PERR_OptLayout wsAfterHead,
					 PERR_OptLayout wsAfterSep,
					 PERR_Feedback elem1,
					 PERR_Feedback elem2,
					 PERR_Feedback elem3);
PERR_FeedbackList PERR_makeFeedbackList4(PERR_OptLayout wsAfterHead,
					 PERR_OptLayout wsAfterSep,
					 PERR_Feedback elem1,
					 PERR_Feedback elem2,
					 PERR_Feedback elem3,
					 PERR_Feedback elem4);
PERR_FeedbackList PERR_makeFeedbackList5(PERR_OptLayout wsAfterHead,
					 PERR_OptLayout wsAfterSep,
					 PERR_Feedback elem1,
					 PERR_Feedback elem2,
					 PERR_Feedback elem3,
					 PERR_Feedback elem4,
					 PERR_Feedback elem5);
PERR_FeedbackList PERR_makeFeedbackList6(PERR_OptLayout wsAfterHead,
					 PERR_OptLayout wsAfterSep,
					 PERR_Feedback elem1,
					 PERR_Feedback elem2,
					 PERR_Feedback elem3,
					 PERR_Feedback elem4,
					 PERR_Feedback elem5,
					 PERR_Feedback elem6);
int PERR_getSubjectListLength(PERR_SubjectList arg);
PERR_SubjectList reverseSubjectList(PERR_SubjectList arg);
PERR_SubjectList PERR_appendSubjectList(PERR_SubjectList arg0,
					PERR_OptLayout wsAfterHead,
					PERR_OptLayout wsAfterSep,
					PERR_Subject arg1);
PERR_SubjectList PERR_concatSubjectList(PERR_SubjectList arg0,
					PERR_OptLayout wsAfterHead,
					PERR_OptLayout wsAfterSep,
					PERR_SubjectList arg1);
PERR_SubjectList PERR_sliceSubjectList(PERR_SubjectList arg, int start,
				       int end);
PERR_Subject PERR_getSubjectListSubjectAt(PERR_SubjectList arg, int index);
PERR_SubjectList PERR_replaceSubjectListSubjectAt(PERR_SubjectList arg,
						  PERR_Subject elem,
						  int index);
PERR_SubjectList PERR_makeSubjectList2(PERR_OptLayout wsAfterHead,
				       PERR_OptLayout wsAfterSep,
				       PERR_Subject elem1,
				       PERR_Subject elem2);
PERR_SubjectList PERR_makeSubjectList3(PERR_OptLayout wsAfterHead,
				       PERR_OptLayout wsAfterSep,
				       PERR_Subject elem1, PERR_Subject elem2,
				       PERR_Subject elem3);
PERR_SubjectList PERR_makeSubjectList4(PERR_OptLayout wsAfterHead,
				       PERR_OptLayout wsAfterSep,
				       PERR_Subject elem1, PERR_Subject elem2,
				       PERR_Subject elem3,
				       PERR_Subject elem4);
PERR_SubjectList PERR_makeSubjectList5(PERR_OptLayout wsAfterHead,
				       PERR_OptLayout wsAfterSep,
				       PERR_Subject elem1, PERR_Subject elem2,
				       PERR_Subject elem3, PERR_Subject elem4,
				       PERR_Subject elem5);
PERR_SubjectList PERR_makeSubjectList6(PERR_OptLayout wsAfterHead,
				       PERR_OptLayout wsAfterSep,
				       PERR_Subject elem1, PERR_Subject elem2,
				       PERR_Subject elem3, PERR_Subject elem4,
				       PERR_Subject elem5,
				       PERR_Subject elem6);

/*}}}  */
/*{{{  constructors */

PERR_Summary PERR_makeSummaryFeedback(PERR_OptLayout wsAfterFeedback,
				      PERR_OptLayout wsAfterParenOpen,
				      PERR_OptLayout wsAfterBracketOpen,
				      PERR_FeedbackList list,
				      PERR_OptLayout wsAfterList,
				      PERR_OptLayout wsAfterBracketClose);
PERR_FeedbackList PERR_makeFeedbackListEmpty();
PERR_FeedbackList PERR_makeFeedbackListSingle(PERR_Feedback head);
PERR_FeedbackList PERR_makeFeedbackListMany(PERR_Feedback head,
					    PERR_OptLayout wsAfterHead,
					    PERR_OptLayout wsAfterSep,
					    PERR_FeedbackList tail);
PERR_Feedback PERR_makeFeedbackInfo(PERR_OptLayout wsAfterInfo,
				    PERR_OptLayout wsAfterParenOpen,
				    PERR_StrCon id, PERR_OptLayout wsAfterId,
				    PERR_OptLayout wsAfterComma,
				    PERR_StrCon producerId,
				    PERR_OptLayout wsAfterProducerId,
				    PERR_OptLayout wsAfterComma1,
				    PERR_StrCon producerType,
				    PERR_OptLayout wsAfterProducerType,
				    PERR_OptLayout wsAfterComma2,
				    PERR_StrCon description,
				    PERR_OptLayout wsAfterDescription,
				    PERR_OptLayout wsAfterComma3,
				    PERR_OptLayout wsAfterBracketOpen,
				    PERR_SubjectList list,
				    PERR_OptLayout wsAfterList,
				    PERR_OptLayout wsAfterBracketClose);
PERR_Feedback PERR_makeFeedbackWarning(PERR_OptLayout wsAfterWarning,
				       PERR_OptLayout wsAfterParenOpen,
				       PERR_StrCon id,
				       PERR_OptLayout wsAfterId,
				       PERR_OptLayout wsAfterComma,
				       PERR_StrCon producerId,
				       PERR_OptLayout wsAfterProducerId,
				       PERR_OptLayout wsAfterComma1,
				       PERR_StrCon producerType,
				       PERR_OptLayout wsAfterProducerType,
				       PERR_OptLayout wsAfterComma2,
				       PERR_StrCon description,
				       PERR_OptLayout wsAfterDescription,
				       PERR_OptLayout wsAfterComma3,
				       PERR_OptLayout wsAfterBracketOpen,
				       PERR_SubjectList list,
				       PERR_OptLayout wsAfterList,
				       PERR_OptLayout wsAfterBracketClose);
PERR_Feedback PERR_makeFeedbackError(PERR_OptLayout wsAfterError,
				     PERR_OptLayout wsAfterParenOpen,
				     PERR_StrCon id, PERR_OptLayout wsAfterId,
				     PERR_OptLayout wsAfterComma,
				     PERR_StrCon producerId,
				     PERR_OptLayout wsAfterProducerId,
				     PERR_OptLayout wsAfterComma1,
				     PERR_StrCon producerType,
				     PERR_OptLayout wsAfterProducerType,
				     PERR_OptLayout wsAfterComma2,
				     PERR_StrCon description,
				     PERR_OptLayout wsAfterDescription,
				     PERR_OptLayout wsAfterComma3,
				     PERR_OptLayout wsAfterBracketOpen,
				     PERR_SubjectList list,
				     PERR_OptLayout wsAfterList,
				     PERR_OptLayout wsAfterBracketClose);
PERR_Feedback PERR_makeFeedbackFatalError(PERR_OptLayout wsAfterFatalError,
					  PERR_OptLayout wsAfterParenOpen,
					  PERR_StrCon id,
					  PERR_OptLayout wsAfterId,
					  PERR_OptLayout wsAfterComma,
					  PERR_StrCon producerId,
					  PERR_OptLayout wsAfterProducerId,
					  PERR_OptLayout wsAfterComma1,
					  PERR_StrCon producerType,
					  PERR_OptLayout wsAfterProducerType,
					  PERR_OptLayout wsAfterComma2,
					  PERR_StrCon description,
					  PERR_OptLayout wsAfterDescription,
					  PERR_OptLayout wsAfterComma3,
					  PERR_OptLayout wsAfterBracketOpen,
					  PERR_SubjectList list,
					  PERR_OptLayout wsAfterList,
					  PERR_OptLayout wsAfterBracketClose);
PERR_SubjectList PERR_makeSubjectListEmpty();
PERR_SubjectList PERR_makeSubjectListSingle(PERR_Subject head);
PERR_SubjectList PERR_makeSubjectListMany(PERR_Subject head,
					  PERR_OptLayout wsAfterHead,
					  PERR_OptLayout wsAfterSep,
					  PERR_SubjectList tail);
PERR_Subject PERR_makeSubjectSubject(PERR_OptLayout wsAfterSubject,
				     PERR_OptLayout wsAfterParenOpen,
				     PERR_StrCon id, PERR_OptLayout wsAfterId,
				     PERR_OptLayout wsAfterComma,
				     PERR_Location Location,
				     PERR_OptLayout wsAfterLocation);
PERR_Location PERR_makeLocationLocation(PERR_OptLayout wsAfterLocation,
					PERR_OptLayout wsAfterParenOpen,
					PERR_StrCon filename,
					PERR_OptLayout wsAfterFilename,
					PERR_OptLayout wsAfterComma,
					PERR_Area Area,
					PERR_OptLayout wsAfterArea);
PERR_Location PERR_makeLocationNoLocation();
PERR_Area PERR_makeAreaArea(PERR_OptLayout wsAfterArea,
			    PERR_OptLayout wsAfterParenOpen,
			    PERR_NatCon beginLine,
			    PERR_OptLayout wsAfterBeginLine,
			    PERR_OptLayout wsAfterComma,
			    PERR_NatCon beginColumn,
			    PERR_OptLayout wsAfterBeginColumn,
			    PERR_OptLayout wsAfterComma1, PERR_NatCon endLine,
			    PERR_OptLayout wsAfterEndLine,
			    PERR_OptLayout wsAfterComma2,
			    PERR_NatCon endColumn,
			    PERR_OptLayout wsAfterEndColumn,
			    PERR_OptLayout wsAfterComma3,
			    PERR_NatCon beginOffset,
			    PERR_OptLayout wsAfterBeginOffset,
			    PERR_OptLayout wsAfterComma4,
			    PERR_NatCon endOffset,
			    PERR_OptLayout wsAfterEndOffset);
PERR_Area PERR_makeAreaNoArea();
PERR_NatCon PERR_makeNatConString(char *string);
PERR_StrCon PERR_makeStrConString(char *string);
PERR_OptLayout PERR_makeOptLayoutAbsent();
PERR_OptLayout PERR_makeOptLayoutPresent(char *string);
PERR_Start PERR_makeStartArea(PERR_OptLayout wsBefore, PERR_Area topArea,
			      PERR_OptLayout wsAfter, int ambCnt);
PERR_Start PERR_makeStartLocation(PERR_OptLayout wsBefore,
				  PERR_Location topLocation,
				  PERR_OptLayout wsAfter, int ambCnt);
PERR_Start PERR_makeStartSubject(PERR_OptLayout wsBefore,
				 PERR_Subject topSubject,
				 PERR_OptLayout wsAfter, int ambCnt);
PERR_Start PERR_makeStartFeedback(PERR_OptLayout wsBefore,
				  PERR_Feedback topFeedback,
				  PERR_OptLayout wsAfter, int ambCnt);
PERR_Start PERR_makeStartSummary(PERR_OptLayout wsBefore,
				 PERR_Summary topSummary,
				 PERR_OptLayout wsAfter, int ambCnt);

/*}}}  */
/*{{{  equality functions */

ATbool PERR_isEqualSummary(PERR_Summary arg0, PERR_Summary arg1);
ATbool PERR_isEqualFeedbackList(PERR_FeedbackList arg0,
				PERR_FeedbackList arg1);
ATbool PERR_isEqualFeedback(PERR_Feedback arg0, PERR_Feedback arg1);
ATbool PERR_isEqualSubjectList(PERR_SubjectList arg0, PERR_SubjectList arg1);
ATbool PERR_isEqualSubject(PERR_Subject arg0, PERR_Subject arg1);
ATbool PERR_isEqualLocation(PERR_Location arg0, PERR_Location arg1);
ATbool PERR_isEqualArea(PERR_Area arg0, PERR_Area arg1);
ATbool PERR_isEqualNatCon(PERR_NatCon arg0, PERR_NatCon arg1);
ATbool PERR_isEqualStrCon(PERR_StrCon arg0, PERR_StrCon arg1);
ATbool PERR_isEqualOptLayout(PERR_OptLayout arg0, PERR_OptLayout arg1);
ATbool PERR_isEqualStart(PERR_Start arg0, PERR_Start arg1);

/*}}}  */
/*{{{  PERR_Summary accessors */

ATbool PERR_isValidSummary(PERR_Summary arg);
inline ATbool PERR_isSummaryFeedback(PERR_Summary arg);
ATbool PERR_hasSummaryWsAfterFeedback(PERR_Summary arg);
PERR_OptLayout PERR_getSummaryWsAfterFeedback(PERR_Summary arg);
PERR_Summary PERR_setSummaryWsAfterFeedback(PERR_Summary arg,
					    PERR_OptLayout wsAfterFeedback);
ATbool PERR_hasSummaryWsAfterParenOpen(PERR_Summary arg);
PERR_OptLayout PERR_getSummaryWsAfterParenOpen(PERR_Summary arg);
PERR_Summary PERR_setSummaryWsAfterParenOpen(PERR_Summary arg,
					     PERR_OptLayout wsAfterParenOpen);
ATbool PERR_hasSummaryWsAfterBracketOpen(PERR_Summary arg);
PERR_OptLayout PERR_getSummaryWsAfterBracketOpen(PERR_Summary arg);
PERR_Summary PERR_setSummaryWsAfterBracketOpen(PERR_Summary arg,
					       PERR_OptLayout
					       wsAfterBracketOpen);
ATbool PERR_hasSummaryList(PERR_Summary arg);
PERR_FeedbackList PERR_getSummaryList(PERR_Summary arg);
PERR_Summary PERR_setSummaryList(PERR_Summary arg, PERR_FeedbackList list);
ATbool PERR_hasSummaryWsAfterList(PERR_Summary arg);
PERR_OptLayout PERR_getSummaryWsAfterList(PERR_Summary arg);
PERR_Summary PERR_setSummaryWsAfterList(PERR_Summary arg,
					PERR_OptLayout wsAfterList);
ATbool PERR_hasSummaryWsAfterBracketClose(PERR_Summary arg);
PERR_OptLayout PERR_getSummaryWsAfterBracketClose(PERR_Summary arg);
PERR_Summary PERR_setSummaryWsAfterBracketClose(PERR_Summary arg,
						PERR_OptLayout
						wsAfterBracketClose);

/*}}}  */
/*{{{  PERR_FeedbackList accessors */

ATbool PERR_isValidFeedbackList(PERR_FeedbackList arg);
inline ATbool PERR_isFeedbackListEmpty(PERR_FeedbackList arg);
inline ATbool PERR_isFeedbackListSingle(PERR_FeedbackList arg);
inline ATbool PERR_isFeedbackListMany(PERR_FeedbackList arg);
ATbool PERR_hasFeedbackListHead(PERR_FeedbackList arg);
PERR_Feedback PERR_getFeedbackListHead(PERR_FeedbackList arg);
PERR_FeedbackList PERR_setFeedbackListHead(PERR_FeedbackList arg,
					   PERR_Feedback head);
ATbool PERR_hasFeedbackListWsAfterHead(PERR_FeedbackList arg);
PERR_OptLayout PERR_getFeedbackListWsAfterHead(PERR_FeedbackList arg);
PERR_FeedbackList PERR_setFeedbackListWsAfterHead(PERR_FeedbackList arg,
						  PERR_OptLayout wsAfterHead);
ATbool PERR_hasFeedbackListWsAfterSep(PERR_FeedbackList arg);
PERR_OptLayout PERR_getFeedbackListWsAfterSep(PERR_FeedbackList arg);
PERR_FeedbackList PERR_setFeedbackListWsAfterSep(PERR_FeedbackList arg,
						 PERR_OptLayout wsAfterSep);
ATbool PERR_hasFeedbackListTail(PERR_FeedbackList arg);
PERR_FeedbackList PERR_getFeedbackListTail(PERR_FeedbackList arg);
PERR_FeedbackList PERR_setFeedbackListTail(PERR_FeedbackList arg,
					   PERR_FeedbackList tail);

/*}}}  */
/*{{{  PERR_Feedback accessors */

ATbool PERR_isValidFeedback(PERR_Feedback arg);
inline ATbool PERR_isFeedbackInfo(PERR_Feedback arg);
inline ATbool PERR_isFeedbackWarning(PERR_Feedback arg);
inline ATbool PERR_isFeedbackError(PERR_Feedback arg);
inline ATbool PERR_isFeedbackFatalError(PERR_Feedback arg);
ATbool PERR_hasFeedbackWsAfterInfo(PERR_Feedback arg);
PERR_OptLayout PERR_getFeedbackWsAfterInfo(PERR_Feedback arg);
PERR_Feedback PERR_setFeedbackWsAfterInfo(PERR_Feedback arg,
					  PERR_OptLayout wsAfterInfo);
ATbool PERR_hasFeedbackWsAfterParenOpen(PERR_Feedback arg);
PERR_OptLayout PERR_getFeedbackWsAfterParenOpen(PERR_Feedback arg);
PERR_Feedback PERR_setFeedbackWsAfterParenOpen(PERR_Feedback arg,
					       PERR_OptLayout
					       wsAfterParenOpen);
ATbool PERR_hasFeedbackId(PERR_Feedback arg);
PERR_StrCon PERR_getFeedbackId(PERR_Feedback arg);
PERR_Feedback PERR_setFeedbackId(PERR_Feedback arg, PERR_StrCon id);
ATbool PERR_hasFeedbackWsAfterId(PERR_Feedback arg);
PERR_OptLayout PERR_getFeedbackWsAfterId(PERR_Feedback arg);
PERR_Feedback PERR_setFeedbackWsAfterId(PERR_Feedback arg,
					PERR_OptLayout wsAfterId);
ATbool PERR_hasFeedbackWsAfterComma(PERR_Feedback arg);
PERR_OptLayout PERR_getFeedbackWsAfterComma(PERR_Feedback arg);
PERR_Feedback PERR_setFeedbackWsAfterComma(PERR_Feedback arg,
					   PERR_OptLayout wsAfterComma);
ATbool PERR_hasFeedbackProducerId(PERR_Feedback arg);
PERR_StrCon PERR_getFeedbackProducerId(PERR_Feedback arg);
PERR_Feedback PERR_setFeedbackProducerId(PERR_Feedback arg,
					 PERR_StrCon producerId);
ATbool PERR_hasFeedbackWsAfterProducerId(PERR_Feedback arg);
PERR_OptLayout PERR_getFeedbackWsAfterProducerId(PERR_Feedback arg);
PERR_Feedback PERR_setFeedbackWsAfterProducerId(PERR_Feedback arg,
						PERR_OptLayout
						wsAfterProducerId);
ATbool PERR_hasFeedbackWsAfterComma1(PERR_Feedback arg);
PERR_OptLayout PERR_getFeedbackWsAfterComma1(PERR_Feedback arg);
PERR_Feedback PERR_setFeedbackWsAfterComma1(PERR_Feedback arg,
					    PERR_OptLayout wsAfterComma1);
ATbool PERR_hasFeedbackProducerType(PERR_Feedback arg);
PERR_StrCon PERR_getFeedbackProducerType(PERR_Feedback arg);
PERR_Feedback PERR_setFeedbackProducerType(PERR_Feedback arg,
					   PERR_StrCon producerType);
ATbool PERR_hasFeedbackWsAfterProducerType(PERR_Feedback arg);
PERR_OptLayout PERR_getFeedbackWsAfterProducerType(PERR_Feedback arg);
PERR_Feedback PERR_setFeedbackWsAfterProducerType(PERR_Feedback arg,
						  PERR_OptLayout
						  wsAfterProducerType);
ATbool PERR_hasFeedbackWsAfterComma2(PERR_Feedback arg);
PERR_OptLayout PERR_getFeedbackWsAfterComma2(PERR_Feedback arg);
PERR_Feedback PERR_setFeedbackWsAfterComma2(PERR_Feedback arg,
					    PERR_OptLayout wsAfterComma2);
ATbool PERR_hasFeedbackDescription(PERR_Feedback arg);
PERR_StrCon PERR_getFeedbackDescription(PERR_Feedback arg);
PERR_Feedback PERR_setFeedbackDescription(PERR_Feedback arg,
					  PERR_StrCon description);
ATbool PERR_hasFeedbackWsAfterDescription(PERR_Feedback arg);
PERR_OptLayout PERR_getFeedbackWsAfterDescription(PERR_Feedback arg);
PERR_Feedback PERR_setFeedbackWsAfterDescription(PERR_Feedback arg,
						 PERR_OptLayout
						 wsAfterDescription);
ATbool PERR_hasFeedbackWsAfterComma3(PERR_Feedback arg);
PERR_OptLayout PERR_getFeedbackWsAfterComma3(PERR_Feedback arg);
PERR_Feedback PERR_setFeedbackWsAfterComma3(PERR_Feedback arg,
					    PERR_OptLayout wsAfterComma3);
ATbool PERR_hasFeedbackWsAfterBracketOpen(PERR_Feedback arg);
PERR_OptLayout PERR_getFeedbackWsAfterBracketOpen(PERR_Feedback arg);
PERR_Feedback PERR_setFeedbackWsAfterBracketOpen(PERR_Feedback arg,
						 PERR_OptLayout
						 wsAfterBracketOpen);
ATbool PERR_hasFeedbackList(PERR_Feedback arg);
PERR_SubjectList PERR_getFeedbackList(PERR_Feedback arg);
PERR_Feedback PERR_setFeedbackList(PERR_Feedback arg, PERR_SubjectList list);
ATbool PERR_hasFeedbackWsAfterList(PERR_Feedback arg);
PERR_OptLayout PERR_getFeedbackWsAfterList(PERR_Feedback arg);
PERR_Feedback PERR_setFeedbackWsAfterList(PERR_Feedback arg,
					  PERR_OptLayout wsAfterList);
ATbool PERR_hasFeedbackWsAfterBracketClose(PERR_Feedback arg);
PERR_OptLayout PERR_getFeedbackWsAfterBracketClose(PERR_Feedback arg);
PERR_Feedback PERR_setFeedbackWsAfterBracketClose(PERR_Feedback arg,
						  PERR_OptLayout
						  wsAfterBracketClose);
ATbool PERR_hasFeedbackWsAfterWarning(PERR_Feedback arg);
PERR_OptLayout PERR_getFeedbackWsAfterWarning(PERR_Feedback arg);
PERR_Feedback PERR_setFeedbackWsAfterWarning(PERR_Feedback arg,
					     PERR_OptLayout wsAfterWarning);
ATbool PERR_hasFeedbackWsAfterError(PERR_Feedback arg);
PERR_OptLayout PERR_getFeedbackWsAfterError(PERR_Feedback arg);
PERR_Feedback PERR_setFeedbackWsAfterError(PERR_Feedback arg,
					   PERR_OptLayout wsAfterError);
ATbool PERR_hasFeedbackWsAfterFatalError(PERR_Feedback arg);
PERR_OptLayout PERR_getFeedbackWsAfterFatalError(PERR_Feedback arg);
PERR_Feedback PERR_setFeedbackWsAfterFatalError(PERR_Feedback arg,
						PERR_OptLayout
						wsAfterFatalError);

/*}}}  */
/*{{{  PERR_SubjectList accessors */

ATbool PERR_isValidSubjectList(PERR_SubjectList arg);
inline ATbool PERR_isSubjectListEmpty(PERR_SubjectList arg);
inline ATbool PERR_isSubjectListSingle(PERR_SubjectList arg);
inline ATbool PERR_isSubjectListMany(PERR_SubjectList arg);
ATbool PERR_hasSubjectListHead(PERR_SubjectList arg);
PERR_Subject PERR_getSubjectListHead(PERR_SubjectList arg);
PERR_SubjectList PERR_setSubjectListHead(PERR_SubjectList arg,
					 PERR_Subject head);
ATbool PERR_hasSubjectListWsAfterHead(PERR_SubjectList arg);
PERR_OptLayout PERR_getSubjectListWsAfterHead(PERR_SubjectList arg);
PERR_SubjectList PERR_setSubjectListWsAfterHead(PERR_SubjectList arg,
						PERR_OptLayout wsAfterHead);
ATbool PERR_hasSubjectListWsAfterSep(PERR_SubjectList arg);
PERR_OptLayout PERR_getSubjectListWsAfterSep(PERR_SubjectList arg);
PERR_SubjectList PERR_setSubjectListWsAfterSep(PERR_SubjectList arg,
					       PERR_OptLayout wsAfterSep);
ATbool PERR_hasSubjectListTail(PERR_SubjectList arg);
PERR_SubjectList PERR_getSubjectListTail(PERR_SubjectList arg);
PERR_SubjectList PERR_setSubjectListTail(PERR_SubjectList arg,
					 PERR_SubjectList tail);

/*}}}  */
/*{{{  PERR_Subject accessors */

ATbool PERR_isValidSubject(PERR_Subject arg);
inline ATbool PERR_isSubjectSubject(PERR_Subject arg);
ATbool PERR_hasSubjectWsAfterSubject(PERR_Subject arg);
PERR_OptLayout PERR_getSubjectWsAfterSubject(PERR_Subject arg);
PERR_Subject PERR_setSubjectWsAfterSubject(PERR_Subject arg,
					   PERR_OptLayout wsAfterSubject);
ATbool PERR_hasSubjectWsAfterParenOpen(PERR_Subject arg);
PERR_OptLayout PERR_getSubjectWsAfterParenOpen(PERR_Subject arg);
PERR_Subject PERR_setSubjectWsAfterParenOpen(PERR_Subject arg,
					     PERR_OptLayout wsAfterParenOpen);
ATbool PERR_hasSubjectId(PERR_Subject arg);
PERR_StrCon PERR_getSubjectId(PERR_Subject arg);
PERR_Subject PERR_setSubjectId(PERR_Subject arg, PERR_StrCon id);
ATbool PERR_hasSubjectWsAfterId(PERR_Subject arg);
PERR_OptLayout PERR_getSubjectWsAfterId(PERR_Subject arg);
PERR_Subject PERR_setSubjectWsAfterId(PERR_Subject arg,
				      PERR_OptLayout wsAfterId);
ATbool PERR_hasSubjectWsAfterComma(PERR_Subject arg);
PERR_OptLayout PERR_getSubjectWsAfterComma(PERR_Subject arg);
PERR_Subject PERR_setSubjectWsAfterComma(PERR_Subject arg,
					 PERR_OptLayout wsAfterComma);
ATbool PERR_hasSubjectLocation(PERR_Subject arg);
PERR_Location PERR_getSubjectLocation(PERR_Subject arg);
PERR_Subject PERR_setSubjectLocation(PERR_Subject arg,
				     PERR_Location Location);
ATbool PERR_hasSubjectWsAfterLocation(PERR_Subject arg);
PERR_OptLayout PERR_getSubjectWsAfterLocation(PERR_Subject arg);
PERR_Subject PERR_setSubjectWsAfterLocation(PERR_Subject arg,
					    PERR_OptLayout wsAfterLocation);

/*}}}  */
/*{{{  PERR_Location accessors */

ATbool PERR_isValidLocation(PERR_Location arg);
inline ATbool PERR_isLocationLocation(PERR_Location arg);
inline ATbool PERR_isLocationNoLocation(PERR_Location arg);
ATbool PERR_hasLocationWsAfterLocation(PERR_Location arg);
PERR_OptLayout PERR_getLocationWsAfterLocation(PERR_Location arg);
PERR_Location PERR_setLocationWsAfterLocation(PERR_Location arg,
					      PERR_OptLayout wsAfterLocation);
ATbool PERR_hasLocationWsAfterParenOpen(PERR_Location arg);
PERR_OptLayout PERR_getLocationWsAfterParenOpen(PERR_Location arg);
PERR_Location PERR_setLocationWsAfterParenOpen(PERR_Location arg,
					       PERR_OptLayout
					       wsAfterParenOpen);
ATbool PERR_hasLocationFilename(PERR_Location arg);
PERR_StrCon PERR_getLocationFilename(PERR_Location arg);
PERR_Location PERR_setLocationFilename(PERR_Location arg,
				       PERR_StrCon filename);
ATbool PERR_hasLocationWsAfterFilename(PERR_Location arg);
PERR_OptLayout PERR_getLocationWsAfterFilename(PERR_Location arg);
PERR_Location PERR_setLocationWsAfterFilename(PERR_Location arg,
					      PERR_OptLayout wsAfterFilename);
ATbool PERR_hasLocationWsAfterComma(PERR_Location arg);
PERR_OptLayout PERR_getLocationWsAfterComma(PERR_Location arg);
PERR_Location PERR_setLocationWsAfterComma(PERR_Location arg,
					   PERR_OptLayout wsAfterComma);
ATbool PERR_hasLocationArea(PERR_Location arg);
PERR_Area PERR_getLocationArea(PERR_Location arg);
PERR_Location PERR_setLocationArea(PERR_Location arg, PERR_Area Area);
ATbool PERR_hasLocationWsAfterArea(PERR_Location arg);
PERR_OptLayout PERR_getLocationWsAfterArea(PERR_Location arg);
PERR_Location PERR_setLocationWsAfterArea(PERR_Location arg,
					  PERR_OptLayout wsAfterArea);

/*}}}  */
/*{{{  PERR_Area accessors */

ATbool PERR_isValidArea(PERR_Area arg);
inline ATbool PERR_isAreaArea(PERR_Area arg);
inline ATbool PERR_isAreaNoArea(PERR_Area arg);
ATbool PERR_hasAreaWsAfterArea(PERR_Area arg);
PERR_OptLayout PERR_getAreaWsAfterArea(PERR_Area arg);
PERR_Area PERR_setAreaWsAfterArea(PERR_Area arg, PERR_OptLayout wsAfterArea);
ATbool PERR_hasAreaWsAfterParenOpen(PERR_Area arg);
PERR_OptLayout PERR_getAreaWsAfterParenOpen(PERR_Area arg);
PERR_Area PERR_setAreaWsAfterParenOpen(PERR_Area arg,
				       PERR_OptLayout wsAfterParenOpen);
ATbool PERR_hasAreaBeginLine(PERR_Area arg);
PERR_NatCon PERR_getAreaBeginLine(PERR_Area arg);
PERR_Area PERR_setAreaBeginLine(PERR_Area arg, PERR_NatCon beginLine);
ATbool PERR_hasAreaWsAfterBeginLine(PERR_Area arg);
PERR_OptLayout PERR_getAreaWsAfterBeginLine(PERR_Area arg);
PERR_Area PERR_setAreaWsAfterBeginLine(PERR_Area arg,
				       PERR_OptLayout wsAfterBeginLine);
ATbool PERR_hasAreaWsAfterComma(PERR_Area arg);
PERR_OptLayout PERR_getAreaWsAfterComma(PERR_Area arg);
PERR_Area PERR_setAreaWsAfterComma(PERR_Area arg,
				   PERR_OptLayout wsAfterComma);
ATbool PERR_hasAreaBeginColumn(PERR_Area arg);
PERR_NatCon PERR_getAreaBeginColumn(PERR_Area arg);
PERR_Area PERR_setAreaBeginColumn(PERR_Area arg, PERR_NatCon beginColumn);
ATbool PERR_hasAreaWsAfterBeginColumn(PERR_Area arg);
PERR_OptLayout PERR_getAreaWsAfterBeginColumn(PERR_Area arg);
PERR_Area PERR_setAreaWsAfterBeginColumn(PERR_Area arg,
					 PERR_OptLayout wsAfterBeginColumn);
ATbool PERR_hasAreaWsAfterComma1(PERR_Area arg);
PERR_OptLayout PERR_getAreaWsAfterComma1(PERR_Area arg);
PERR_Area PERR_setAreaWsAfterComma1(PERR_Area arg,
				    PERR_OptLayout wsAfterComma1);
ATbool PERR_hasAreaEndLine(PERR_Area arg);
PERR_NatCon PERR_getAreaEndLine(PERR_Area arg);
PERR_Area PERR_setAreaEndLine(PERR_Area arg, PERR_NatCon endLine);
ATbool PERR_hasAreaWsAfterEndLine(PERR_Area arg);
PERR_OptLayout PERR_getAreaWsAfterEndLine(PERR_Area arg);
PERR_Area PERR_setAreaWsAfterEndLine(PERR_Area arg,
				     PERR_OptLayout wsAfterEndLine);
ATbool PERR_hasAreaWsAfterComma2(PERR_Area arg);
PERR_OptLayout PERR_getAreaWsAfterComma2(PERR_Area arg);
PERR_Area PERR_setAreaWsAfterComma2(PERR_Area arg,
				    PERR_OptLayout wsAfterComma2);
ATbool PERR_hasAreaEndColumn(PERR_Area arg);
PERR_NatCon PERR_getAreaEndColumn(PERR_Area arg);
PERR_Area PERR_setAreaEndColumn(PERR_Area arg, PERR_NatCon endColumn);
ATbool PERR_hasAreaWsAfterEndColumn(PERR_Area arg);
PERR_OptLayout PERR_getAreaWsAfterEndColumn(PERR_Area arg);
PERR_Area PERR_setAreaWsAfterEndColumn(PERR_Area arg,
				       PERR_OptLayout wsAfterEndColumn);
ATbool PERR_hasAreaWsAfterComma3(PERR_Area arg);
PERR_OptLayout PERR_getAreaWsAfterComma3(PERR_Area arg);
PERR_Area PERR_setAreaWsAfterComma3(PERR_Area arg,
				    PERR_OptLayout wsAfterComma3);
ATbool PERR_hasAreaBeginOffset(PERR_Area arg);
PERR_NatCon PERR_getAreaBeginOffset(PERR_Area arg);
PERR_Area PERR_setAreaBeginOffset(PERR_Area arg, PERR_NatCon beginOffset);
ATbool PERR_hasAreaWsAfterBeginOffset(PERR_Area arg);
PERR_OptLayout PERR_getAreaWsAfterBeginOffset(PERR_Area arg);
PERR_Area PERR_setAreaWsAfterBeginOffset(PERR_Area arg,
					 PERR_OptLayout wsAfterBeginOffset);
ATbool PERR_hasAreaWsAfterComma4(PERR_Area arg);
PERR_OptLayout PERR_getAreaWsAfterComma4(PERR_Area arg);
PERR_Area PERR_setAreaWsAfterComma4(PERR_Area arg,
				    PERR_OptLayout wsAfterComma4);
ATbool PERR_hasAreaEndOffset(PERR_Area arg);
PERR_NatCon PERR_getAreaEndOffset(PERR_Area arg);
PERR_Area PERR_setAreaEndOffset(PERR_Area arg, PERR_NatCon endOffset);
ATbool PERR_hasAreaWsAfterEndOffset(PERR_Area arg);
PERR_OptLayout PERR_getAreaWsAfterEndOffset(PERR_Area arg);
PERR_Area PERR_setAreaWsAfterEndOffset(PERR_Area arg,
				       PERR_OptLayout wsAfterEndOffset);

/*}}}  */
/*{{{  PERR_NatCon accessors */

ATbool PERR_isValidNatCon(PERR_NatCon arg);
inline ATbool PERR_isNatConString(PERR_NatCon arg);
ATbool PERR_hasNatConString(PERR_NatCon arg);
char *PERR_getNatConString(PERR_NatCon arg);
PERR_NatCon PERR_setNatConString(PERR_NatCon arg, char *string);

/*}}}  */
/*{{{  PERR_StrCon accessors */

ATbool PERR_isValidStrCon(PERR_StrCon arg);
inline ATbool PERR_isStrConString(PERR_StrCon arg);
ATbool PERR_hasStrConString(PERR_StrCon arg);
char *PERR_getStrConString(PERR_StrCon arg);
PERR_StrCon PERR_setStrConString(PERR_StrCon arg, char *string);

/*}}}  */
/*{{{  PERR_OptLayout accessors */

ATbool PERR_isValidOptLayout(PERR_OptLayout arg);
inline ATbool PERR_isOptLayoutAbsent(PERR_OptLayout arg);
inline ATbool PERR_isOptLayoutPresent(PERR_OptLayout arg);
ATbool PERR_hasOptLayoutString(PERR_OptLayout arg);
char *PERR_getOptLayoutString(PERR_OptLayout arg);
PERR_OptLayout PERR_setOptLayoutString(PERR_OptLayout arg, char *string);

/*}}}  */
/*{{{  PERR_Start accessors */

ATbool PERR_isValidStart(PERR_Start arg);
inline ATbool PERR_isStartArea(PERR_Start arg);
inline ATbool PERR_isStartLocation(PERR_Start arg);
inline ATbool PERR_isStartSubject(PERR_Start arg);
inline ATbool PERR_isStartFeedback(PERR_Start arg);
inline ATbool PERR_isStartSummary(PERR_Start arg);
ATbool PERR_hasStartWsBefore(PERR_Start arg);
PERR_OptLayout PERR_getStartWsBefore(PERR_Start arg);
PERR_Start PERR_setStartWsBefore(PERR_Start arg, PERR_OptLayout wsBefore);
ATbool PERR_hasStartTopArea(PERR_Start arg);
PERR_Area PERR_getStartTopArea(PERR_Start arg);
PERR_Start PERR_setStartTopArea(PERR_Start arg, PERR_Area topArea);
ATbool PERR_hasStartWsAfter(PERR_Start arg);
PERR_OptLayout PERR_getStartWsAfter(PERR_Start arg);
PERR_Start PERR_setStartWsAfter(PERR_Start arg, PERR_OptLayout wsAfter);
ATbool PERR_hasStartAmbCnt(PERR_Start arg);
int PERR_getStartAmbCnt(PERR_Start arg);
PERR_Start PERR_setStartAmbCnt(PERR_Start arg, int ambCnt);
ATbool PERR_hasStartTopLocation(PERR_Start arg);
PERR_Location PERR_getStartTopLocation(PERR_Start arg);
PERR_Start PERR_setStartTopLocation(PERR_Start arg,
				    PERR_Location topLocation);
ATbool PERR_hasStartTopSubject(PERR_Start arg);
PERR_Subject PERR_getStartTopSubject(PERR_Start arg);
PERR_Start PERR_setStartTopSubject(PERR_Start arg, PERR_Subject topSubject);
ATbool PERR_hasStartTopFeedback(PERR_Start arg);
PERR_Feedback PERR_getStartTopFeedback(PERR_Start arg);
PERR_Start PERR_setStartTopFeedback(PERR_Start arg,
				    PERR_Feedback topFeedback);
ATbool PERR_hasStartTopSummary(PERR_Start arg);
PERR_Summary PERR_getStartTopSummary(PERR_Start arg);
PERR_Start PERR_setStartTopSummary(PERR_Start arg, PERR_Summary topSummary);

/*}}}  */
/*{{{  sort visitors */

PERR_Summary PERR_visitSummary(PERR_Summary arg,
			       PERR_OptLayout(*acceptWsAfterFeedback)
			       (PERR_OptLayout),
			       PERR_OptLayout(*acceptWsAfterParenOpen)
			       (PERR_OptLayout),
			       PERR_OptLayout(*acceptWsAfterBracketOpen)
			       (PERR_OptLayout),
			       PERR_FeedbackList(*acceptList)
			       (PERR_FeedbackList),
			       PERR_OptLayout(*acceptWsAfterList)
			       (PERR_OptLayout),
			       PERR_OptLayout(*acceptWsAfterBracketClose)
			       (PERR_OptLayout));
PERR_FeedbackList PERR_visitFeedbackList(PERR_FeedbackList arg,
					 PERR_Feedback(*acceptHead)
					 (PERR_Feedback),
					 PERR_OptLayout(*acceptWsAfterHead)
					 (PERR_OptLayout),
					 PERR_OptLayout(*acceptWsAfterSep)
					 (PERR_OptLayout));
PERR_Feedback PERR_visitFeedback(PERR_Feedback arg,
				 PERR_OptLayout(*acceptWsAfterInfo)
				 (PERR_OptLayout),
				 PERR_OptLayout(*acceptWsAfterParenOpen)
				 (PERR_OptLayout),
				 PERR_StrCon(*acceptId) (PERR_StrCon),
				 PERR_OptLayout(*acceptWsAfterId)
				 (PERR_OptLayout),
				 PERR_OptLayout(*acceptWsAfterComma)
				 (PERR_OptLayout),
				 PERR_StrCon(*acceptProducerId) (PERR_StrCon),
				 PERR_OptLayout(*acceptWsAfterProducerId)
				 (PERR_OptLayout),
				 PERR_OptLayout(*acceptWsAfterComma1)
				 (PERR_OptLayout),
				 PERR_StrCon(*acceptProducerType)
				 (PERR_StrCon),
				 PERR_OptLayout(*acceptWsAfterProducerType)
				 (PERR_OptLayout),
				 PERR_OptLayout(*acceptWsAfterComma2)
				 (PERR_OptLayout),
				 PERR_StrCon(*acceptDescription)
				 (PERR_StrCon),
				 PERR_OptLayout(*acceptWsAfterDescription)
				 (PERR_OptLayout),
				 PERR_OptLayout(*acceptWsAfterComma3)
				 (PERR_OptLayout),
				 PERR_OptLayout(*acceptWsAfterBracketOpen)
				 (PERR_OptLayout),
				 PERR_SubjectList(*acceptList)
				 (PERR_SubjectList),
				 PERR_OptLayout(*acceptWsAfterList)
				 (PERR_OptLayout),
				 PERR_OptLayout(*acceptWsAfterBracketClose)
				 (PERR_OptLayout),
				 PERR_OptLayout(*acceptWsAfterWarning)
				 (PERR_OptLayout),
				 PERR_OptLayout(*acceptWsAfterError)
				 (PERR_OptLayout),
				 PERR_OptLayout(*acceptWsAfterFatalError)
				 (PERR_OptLayout));
PERR_SubjectList PERR_visitSubjectList(PERR_SubjectList arg,
				       PERR_Subject(*acceptHead)
				       (PERR_Subject),
				       PERR_OptLayout(*acceptWsAfterHead)
				       (PERR_OptLayout),
				       PERR_OptLayout(*acceptWsAfterSep)
				       (PERR_OptLayout));
PERR_Subject PERR_visitSubject(PERR_Subject arg,
			       PERR_OptLayout(*acceptWsAfterSubject)
			       (PERR_OptLayout),
			       PERR_OptLayout(*acceptWsAfterParenOpen)
			       (PERR_OptLayout),
			       PERR_StrCon(*acceptId) (PERR_StrCon),
			       PERR_OptLayout(*acceptWsAfterId)
			       (PERR_OptLayout),
			       PERR_OptLayout(*acceptWsAfterComma)
			       (PERR_OptLayout),
			       PERR_Location(*acceptLocation) (PERR_Location),
			       PERR_OptLayout(*acceptWsAfterLocation)
			       (PERR_OptLayout));
PERR_Location PERR_visitLocation(PERR_Location arg,
				 PERR_OptLayout(*acceptWsAfterLocation)
				 (PERR_OptLayout),
				 PERR_OptLayout(*acceptWsAfterParenOpen)
				 (PERR_OptLayout),
				 PERR_StrCon(*acceptFilename) (PERR_StrCon),
				 PERR_OptLayout(*acceptWsAfterFilename)
				 (PERR_OptLayout),
				 PERR_OptLayout(*acceptWsAfterComma)
				 (PERR_OptLayout),
				 PERR_Area(*acceptArea) (PERR_Area),
				 PERR_OptLayout(*acceptWsAfterArea)
				 (PERR_OptLayout));
PERR_Area PERR_visitArea(PERR_Area arg,
			 PERR_OptLayout(*acceptWsAfterArea) (PERR_OptLayout),
			 PERR_OptLayout(*acceptWsAfterParenOpen)
			 (PERR_OptLayout),
			 PERR_NatCon(*acceptBeginLine) (PERR_NatCon),
			 PERR_OptLayout(*acceptWsAfterBeginLine)
			 (PERR_OptLayout),
			 PERR_OptLayout(*acceptWsAfterComma) (PERR_OptLayout),
			 PERR_NatCon(*acceptBeginColumn) (PERR_NatCon),
			 PERR_OptLayout(*acceptWsAfterBeginColumn)
			 (PERR_OptLayout),
			 PERR_OptLayout(*acceptWsAfterComma1)
			 (PERR_OptLayout),
			 PERR_NatCon(*acceptEndLine) (PERR_NatCon),
			 PERR_OptLayout(*acceptWsAfterEndLine)
			 (PERR_OptLayout),
			 PERR_OptLayout(*acceptWsAfterComma2)
			 (PERR_OptLayout),
			 PERR_NatCon(*acceptEndColumn) (PERR_NatCon),
			 PERR_OptLayout(*acceptWsAfterEndColumn)
			 (PERR_OptLayout),
			 PERR_OptLayout(*acceptWsAfterComma3)
			 (PERR_OptLayout),
			 PERR_NatCon(*acceptBeginOffset) (PERR_NatCon),
			 PERR_OptLayout(*acceptWsAfterBeginOffset)
			 (PERR_OptLayout),
			 PERR_OptLayout(*acceptWsAfterComma4)
			 (PERR_OptLayout),
			 PERR_NatCon(*acceptEndOffset) (PERR_NatCon),
			 PERR_OptLayout(*acceptWsAfterEndOffset)
			 (PERR_OptLayout));
PERR_NatCon PERR_visitNatCon(PERR_NatCon arg, char *(*acceptString) (char *));
PERR_StrCon PERR_visitStrCon(PERR_StrCon arg, char *(*acceptString) (char *));
PERR_OptLayout PERR_visitOptLayout(PERR_OptLayout arg,
				   char *(*acceptString) (char *));
PERR_Start PERR_visitStart(PERR_Start arg,
			   PERR_OptLayout(*acceptWsBefore) (PERR_OptLayout),
			   PERR_Area(*acceptTopArea) (PERR_Area),
			   PERR_OptLayout(*acceptWsAfter) (PERR_OptLayout),
			   int (*acceptAmbCnt) (int),
			   PERR_Location(*acceptTopLocation) (PERR_Location),
			   PERR_Subject(*acceptTopSubject) (PERR_Subject),
			   PERR_Feedback(*acceptTopFeedback) (PERR_Feedback),
			   PERR_Summary(*acceptTopSummary) (PERR_Summary));

/*}}}  */

#endif /* _PARSEDERRORAPI_H */
