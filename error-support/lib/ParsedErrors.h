#ifndef _PARSEDERRORS_H
#define _PARSEDERRORS_H

/*{{{  includes */

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "ParsedErrors_dict.h"

/*}}}  */

/*{{{  typedefs */

typedef struct _PME_Feedback *PME_Feedback;
typedef struct _PME_SubjectList *PME_SubjectList;
typedef struct _PME_Subject *PME_Subject;
typedef struct _PME_Location *PME_Location;
typedef struct _PME_Area *PME_Area;
typedef struct _PME_NatCon *PME_NatCon;
typedef struct _PME_String *PME_String;
typedef struct _PME_OptLayout *PME_OptLayout;
typedef struct _PME_Start *PME_Start;

/*}}}  */

/*{{{  definition of bottom types */


/*}}}  */

void PME_initParsedErrorsApi(void);

/*{{{  term conversion functions */

PME_Feedback PME_FeedbackFromTerm(ATerm t);
ATerm PME_FeedbackToTerm(PME_Feedback arg);
PME_SubjectList PME_SubjectListFromTerm(ATerm t);
ATerm PME_SubjectListToTerm(PME_SubjectList arg);
PME_Subject PME_SubjectFromTerm(ATerm t);
ATerm PME_SubjectToTerm(PME_Subject arg);
PME_Location PME_LocationFromTerm(ATerm t);
ATerm PME_LocationToTerm(PME_Location arg);
PME_Area PME_AreaFromTerm(ATerm t);
ATerm PME_AreaToTerm(PME_Area arg);
PME_NatCon PME_NatConFromTerm(ATerm t);
ATerm PME_NatConToTerm(PME_NatCon arg);
PME_String PME_StringFromTerm(ATerm t);
ATerm PME_StringToTerm(PME_String arg);
PME_OptLayout PME_OptLayoutFromTerm(ATerm t);
ATerm PME_OptLayoutToTerm(PME_OptLayout arg);
PME_Start PME_StartFromTerm(ATerm t);
ATerm PME_StartToTerm(PME_Start arg);

/*}}}  */
/*{{{  list functions */

int PME_getSubjectListLength(PME_SubjectList arg);
PME_SubjectList reverseSubjectList(PME_SubjectList arg);
PME_SubjectList PME_appendSubjectList(PME_SubjectList arg0,
				      PME_OptLayout wsAfterHead,
				      PME_OptLayout wsAfterSep,
				      PME_Subject arg1);
PME_SubjectList PME_concatSubjectList(PME_SubjectList arg0,
				      PME_OptLayout wsAfterHead,
				      PME_OptLayout wsAfterSep,
				      PME_SubjectList arg1);
PME_SubjectList PME_sliceSubjectList(PME_SubjectList arg, int start, int end);
PME_Subject PME_getSubjectListSubjectAt(PME_SubjectList arg, int index);
PME_SubjectList PME_replaceSubjectListSubjectAt(PME_SubjectList arg,
						PME_Subject elem, int index);
PME_SubjectList PME_makeSubjectList2(PME_OptLayout wsAfterHead,
				     PME_OptLayout wsAfterSep,
				     PME_Subject elem1, PME_Subject elem2);
PME_SubjectList PME_makeSubjectList3(PME_OptLayout wsAfterHead,
				     PME_OptLayout wsAfterSep,
				     PME_Subject elem1, PME_Subject elem2,
				     PME_Subject elem3);
PME_SubjectList PME_makeSubjectList4(PME_OptLayout wsAfterHead,
				     PME_OptLayout wsAfterSep,
				     PME_Subject elem1, PME_Subject elem2,
				     PME_Subject elem3, PME_Subject elem4);
PME_SubjectList PME_makeSubjectList5(PME_OptLayout wsAfterHead,
				     PME_OptLayout wsAfterSep,
				     PME_Subject elem1, PME_Subject elem2,
				     PME_Subject elem3, PME_Subject elem4,
				     PME_Subject elem5);
PME_SubjectList PME_makeSubjectList6(PME_OptLayout wsAfterHead,
				     PME_OptLayout wsAfterSep,
				     PME_Subject elem1, PME_Subject elem2,
				     PME_Subject elem3, PME_Subject elem4,
				     PME_Subject elem5, PME_Subject elem6);

/*}}}  */
/*{{{  constructors */

PME_Feedback PME_makeFeedbackInfo(PME_OptLayout wsAfterInfo,
				  PME_OptLayout wsAfterParenOpen,
				  PME_String id, PME_OptLayout wsAfterId,
				  PME_OptLayout wsAfterComma,
				  PME_String producerId,
				  PME_OptLayout wsAfterProducerId,
				  PME_OptLayout wsAfterComma1,
				  PME_String producerType,
				  PME_OptLayout wsAfterProducerType,
				  PME_OptLayout wsAfterComma2,
				  PME_String description,
				  PME_OptLayout wsAfterDescription,
				  PME_OptLayout wsAfterComma3,
				  PME_OptLayout wsAfterBracketOpen,
				  PME_SubjectList list,
				  PME_OptLayout wsAfterList,
				  PME_OptLayout wsAfterBracketClose);
PME_Feedback PME_makeFeedbackWarning(PME_OptLayout wsAfterWarning,
				     PME_OptLayout wsAfterParenOpen,
				     PME_String id, PME_OptLayout wsAfterId,
				     PME_OptLayout wsAfterComma,
				     PME_String producerId,
				     PME_OptLayout wsAfterProducerId,
				     PME_OptLayout wsAfterComma1,
				     PME_String producerType,
				     PME_OptLayout wsAfterProducerType,
				     PME_OptLayout wsAfterComma2,
				     PME_String description,
				     PME_OptLayout wsAfterDescription,
				     PME_OptLayout wsAfterComma3,
				     PME_OptLayout wsAfterBracketOpen,
				     PME_SubjectList list,
				     PME_OptLayout wsAfterList,
				     PME_OptLayout wsAfterBracketClose);
PME_Feedback PME_makeFeedbackError(PME_OptLayout wsAfterError,
				   PME_OptLayout wsAfterParenOpen,
				   PME_String id, PME_OptLayout wsAfterId,
				   PME_OptLayout wsAfterComma,
				   PME_String producerId,
				   PME_OptLayout wsAfterProducerId,
				   PME_OptLayout wsAfterComma1,
				   PME_String producerType,
				   PME_OptLayout wsAfterProducerType,
				   PME_OptLayout wsAfterComma2,
				   PME_String description,
				   PME_OptLayout wsAfterDescription,
				   PME_OptLayout wsAfterComma3,
				   PME_OptLayout wsAfterBracketOpen,
				   PME_SubjectList list,
				   PME_OptLayout wsAfterList,
				   PME_OptLayout wsAfterBracketClose);
PME_Feedback PME_makeFeedbackFatalError(PME_OptLayout wsAfterFatalError,
					PME_OptLayout wsAfterParenOpen,
					PME_String id,
					PME_OptLayout wsAfterId,
					PME_OptLayout wsAfterComma,
					PME_String producerId,
					PME_OptLayout wsAfterProducerId,
					PME_OptLayout wsAfterComma1,
					PME_String producerType,
					PME_OptLayout wsAfterProducerType,
					PME_OptLayout wsAfterComma2,
					PME_String description,
					PME_OptLayout wsAfterDescription,
					PME_OptLayout wsAfterComma3,
					PME_OptLayout wsAfterBracketOpen,
					PME_SubjectList list,
					PME_OptLayout wsAfterList,
					PME_OptLayout wsAfterBracketClose);
PME_SubjectList PME_makeSubjectListEmpty();
PME_SubjectList PME_makeSubjectListSingle(PME_Subject head);
PME_SubjectList PME_makeSubjectListMany(PME_Subject head,
					PME_OptLayout wsAfterHead,
					PME_OptLayout wsAfterSep,
					PME_SubjectList tail);
PME_Subject PME_makeSubjectLocatable(PME_OptLayout wsAfterSubject,
				     PME_OptLayout wsAfterParenOpen,
				     PME_String id, PME_OptLayout wsAfterId,
				     PME_OptLayout wsAfterComma,
				     PME_Location Location,
				     PME_OptLayout wsAfterLocation);
PME_Subject PME_makeSubjectUnlocatable(PME_OptLayout wsAfterSubject,
				       PME_OptLayout wsAfterParenOpen,
				       PME_String id,
				       PME_OptLayout wsAfterId);
PME_Location PME_makeLocationLocation(PME_OptLayout wsAfterLocation,
				      PME_OptLayout wsAfterParenOpen,
				      PME_String filename,
				      PME_OptLayout wsAfterFilename,
				      PME_OptLayout wsAfterComma,
				      PME_Area Area,
				      PME_OptLayout wsAfterArea);
PME_Area PME_makeAreaArea(PME_OptLayout wsAfterArea,
			  PME_OptLayout wsAfterParenOpen,
			  PME_NatCon startLine,
			  PME_OptLayout wsAfterStartLine,
			  PME_OptLayout wsAfterComma, PME_NatCon startColumn,
			  PME_OptLayout wsAfterStartColumn,
			  PME_OptLayout wsAfterComma1, PME_NatCon endLine,
			  PME_OptLayout wsAfterEndLine,
			  PME_OptLayout wsAfterComma2, PME_NatCon endColumn,
			  PME_OptLayout wsAfterEndColumn,
			  PME_OptLayout wsAfterComma3, PME_NatCon startOffset,
			  PME_OptLayout wsAfterStartOffset,
			  PME_OptLayout wsAfterComma4, PME_NatCon endOffset,
			  PME_OptLayout wsAfterEndOffset);
PME_Area PME_makeAreaNoArea();
PME_NatCon PME_makeNatConString(char *string);
PME_String PME_makeStringString(char *string);
PME_OptLayout PME_makeOptLayoutAbsent();
PME_OptLayout PME_makeOptLayoutPresent(char *string);
PME_Start PME_makeStartArea(PME_OptLayout wsBefore, PME_Area topArea,
			    PME_OptLayout wsAfter, int ambCnt);
PME_Start PME_makeStartLocation(PME_OptLayout wsBefore,
				PME_Location topLocation,
				PME_OptLayout wsAfter, int ambCnt);
PME_Start PME_makeStartSubject(PME_OptLayout wsBefore, PME_Subject topSubject,
			       PME_OptLayout wsAfter, int ambCnt);
PME_Start PME_makeStartFeedback(PME_OptLayout wsBefore,
				PME_Feedback topFeedback,
				PME_OptLayout wsAfter, int ambCnt);

/*}}}  */
/*{{{  equality functions */

ATbool PME_isEqualFeedback(PME_Feedback arg0, PME_Feedback arg1);
ATbool PME_isEqualSubjectList(PME_SubjectList arg0, PME_SubjectList arg1);
ATbool PME_isEqualSubject(PME_Subject arg0, PME_Subject arg1);
ATbool PME_isEqualLocation(PME_Location arg0, PME_Location arg1);
ATbool PME_isEqualArea(PME_Area arg0, PME_Area arg1);
ATbool PME_isEqualNatCon(PME_NatCon arg0, PME_NatCon arg1);
ATbool PME_isEqualString(PME_String arg0, PME_String arg1);
ATbool PME_isEqualOptLayout(PME_OptLayout arg0, PME_OptLayout arg1);
ATbool PME_isEqualStart(PME_Start arg0, PME_Start arg1);

/*}}}  */
/*{{{  PME_Feedback accessors */

ATbool PME_isValidFeedback(PME_Feedback arg);
inline ATbool PME_isFeedbackInfo(PME_Feedback arg);
inline ATbool PME_isFeedbackWarning(PME_Feedback arg);
inline ATbool PME_isFeedbackError(PME_Feedback arg);
inline ATbool PME_isFeedbackFatalError(PME_Feedback arg);
ATbool PME_hasFeedbackWsAfterInfo(PME_Feedback arg);
PME_OptLayout PME_getFeedbackWsAfterInfo(PME_Feedback arg);
PME_Feedback PME_setFeedbackWsAfterInfo(PME_Feedback arg,
					PME_OptLayout wsAfterInfo);
ATbool PME_hasFeedbackWsAfterParenOpen(PME_Feedback arg);
PME_OptLayout PME_getFeedbackWsAfterParenOpen(PME_Feedback arg);
PME_Feedback PME_setFeedbackWsAfterParenOpen(PME_Feedback arg,
					     PME_OptLayout wsAfterParenOpen);
ATbool PME_hasFeedbackId(PME_Feedback arg);
PME_String PME_getFeedbackId(PME_Feedback arg);
PME_Feedback PME_setFeedbackId(PME_Feedback arg, PME_String id);
ATbool PME_hasFeedbackWsAfterId(PME_Feedback arg);
PME_OptLayout PME_getFeedbackWsAfterId(PME_Feedback arg);
PME_Feedback PME_setFeedbackWsAfterId(PME_Feedback arg,
				      PME_OptLayout wsAfterId);
ATbool PME_hasFeedbackWsAfterComma(PME_Feedback arg);
PME_OptLayout PME_getFeedbackWsAfterComma(PME_Feedback arg);
PME_Feedback PME_setFeedbackWsAfterComma(PME_Feedback arg,
					 PME_OptLayout wsAfterComma);
ATbool PME_hasFeedbackProducerId(PME_Feedback arg);
PME_String PME_getFeedbackProducerId(PME_Feedback arg);
PME_Feedback PME_setFeedbackProducerId(PME_Feedback arg,
				       PME_String producerId);
ATbool PME_hasFeedbackWsAfterProducerId(PME_Feedback arg);
PME_OptLayout PME_getFeedbackWsAfterProducerId(PME_Feedback arg);
PME_Feedback PME_setFeedbackWsAfterProducerId(PME_Feedback arg,
					      PME_OptLayout
					      wsAfterProducerId);
ATbool PME_hasFeedbackWsAfterComma1(PME_Feedback arg);
PME_OptLayout PME_getFeedbackWsAfterComma1(PME_Feedback arg);
PME_Feedback PME_setFeedbackWsAfterComma1(PME_Feedback arg,
					  PME_OptLayout wsAfterComma1);
ATbool PME_hasFeedbackProducerType(PME_Feedback arg);
PME_String PME_getFeedbackProducerType(PME_Feedback arg);
PME_Feedback PME_setFeedbackProducerType(PME_Feedback arg,
					 PME_String producerType);
ATbool PME_hasFeedbackWsAfterProducerType(PME_Feedback arg);
PME_OptLayout PME_getFeedbackWsAfterProducerType(PME_Feedback arg);
PME_Feedback PME_setFeedbackWsAfterProducerType(PME_Feedback arg,
						PME_OptLayout
						wsAfterProducerType);
ATbool PME_hasFeedbackWsAfterComma2(PME_Feedback arg);
PME_OptLayout PME_getFeedbackWsAfterComma2(PME_Feedback arg);
PME_Feedback PME_setFeedbackWsAfterComma2(PME_Feedback arg,
					  PME_OptLayout wsAfterComma2);
ATbool PME_hasFeedbackDescription(PME_Feedback arg);
PME_String PME_getFeedbackDescription(PME_Feedback arg);
PME_Feedback PME_setFeedbackDescription(PME_Feedback arg,
					PME_String description);
ATbool PME_hasFeedbackWsAfterDescription(PME_Feedback arg);
PME_OptLayout PME_getFeedbackWsAfterDescription(PME_Feedback arg);
PME_Feedback PME_setFeedbackWsAfterDescription(PME_Feedback arg,
					       PME_OptLayout
					       wsAfterDescription);
ATbool PME_hasFeedbackWsAfterComma3(PME_Feedback arg);
PME_OptLayout PME_getFeedbackWsAfterComma3(PME_Feedback arg);
PME_Feedback PME_setFeedbackWsAfterComma3(PME_Feedback arg,
					  PME_OptLayout wsAfterComma3);
ATbool PME_hasFeedbackWsAfterBracketOpen(PME_Feedback arg);
PME_OptLayout PME_getFeedbackWsAfterBracketOpen(PME_Feedback arg);
PME_Feedback PME_setFeedbackWsAfterBracketOpen(PME_Feedback arg,
					       PME_OptLayout
					       wsAfterBracketOpen);
ATbool PME_hasFeedbackList(PME_Feedback arg);
PME_SubjectList PME_getFeedbackList(PME_Feedback arg);
PME_Feedback PME_setFeedbackList(PME_Feedback arg, PME_SubjectList list);
ATbool PME_hasFeedbackWsAfterList(PME_Feedback arg);
PME_OptLayout PME_getFeedbackWsAfterList(PME_Feedback arg);
PME_Feedback PME_setFeedbackWsAfterList(PME_Feedback arg,
					PME_OptLayout wsAfterList);
ATbool PME_hasFeedbackWsAfterBracketClose(PME_Feedback arg);
PME_OptLayout PME_getFeedbackWsAfterBracketClose(PME_Feedback arg);
PME_Feedback PME_setFeedbackWsAfterBracketClose(PME_Feedback arg,
						PME_OptLayout
						wsAfterBracketClose);
ATbool PME_hasFeedbackWsAfterWarning(PME_Feedback arg);
PME_OptLayout PME_getFeedbackWsAfterWarning(PME_Feedback arg);
PME_Feedback PME_setFeedbackWsAfterWarning(PME_Feedback arg,
					   PME_OptLayout wsAfterWarning);
ATbool PME_hasFeedbackWsAfterError(PME_Feedback arg);
PME_OptLayout PME_getFeedbackWsAfterError(PME_Feedback arg);
PME_Feedback PME_setFeedbackWsAfterError(PME_Feedback arg,
					 PME_OptLayout wsAfterError);
ATbool PME_hasFeedbackWsAfterFatalError(PME_Feedback arg);
PME_OptLayout PME_getFeedbackWsAfterFatalError(PME_Feedback arg);
PME_Feedback PME_setFeedbackWsAfterFatalError(PME_Feedback arg,
					      PME_OptLayout
					      wsAfterFatalError);

/*}}}  */
/*{{{  PME_SubjectList accessors */

ATbool PME_isValidSubjectList(PME_SubjectList arg);
inline ATbool PME_isSubjectListEmpty(PME_SubjectList arg);
inline ATbool PME_isSubjectListSingle(PME_SubjectList arg);
inline ATbool PME_isSubjectListMany(PME_SubjectList arg);
ATbool PME_hasSubjectListHead(PME_SubjectList arg);
PME_Subject PME_getSubjectListHead(PME_SubjectList arg);
PME_SubjectList PME_setSubjectListHead(PME_SubjectList arg, PME_Subject head);
ATbool PME_hasSubjectListWsAfterHead(PME_SubjectList arg);
PME_OptLayout PME_getSubjectListWsAfterHead(PME_SubjectList arg);
PME_SubjectList PME_setSubjectListWsAfterHead(PME_SubjectList arg,
					      PME_OptLayout wsAfterHead);
ATbool PME_hasSubjectListWsAfterSep(PME_SubjectList arg);
PME_OptLayout PME_getSubjectListWsAfterSep(PME_SubjectList arg);
PME_SubjectList PME_setSubjectListWsAfterSep(PME_SubjectList arg,
					     PME_OptLayout wsAfterSep);
ATbool PME_hasSubjectListTail(PME_SubjectList arg);
PME_SubjectList PME_getSubjectListTail(PME_SubjectList arg);
PME_SubjectList PME_setSubjectListTail(PME_SubjectList arg,
				       PME_SubjectList tail);

/*}}}  */
/*{{{  PME_Subject accessors */

ATbool PME_isValidSubject(PME_Subject arg);
inline ATbool PME_isSubjectLocatable(PME_Subject arg);
inline ATbool PME_isSubjectUnlocatable(PME_Subject arg);
ATbool PME_hasSubjectWsAfterSubject(PME_Subject arg);
PME_OptLayout PME_getSubjectWsAfterSubject(PME_Subject arg);
PME_Subject PME_setSubjectWsAfterSubject(PME_Subject arg,
					 PME_OptLayout wsAfterSubject);
ATbool PME_hasSubjectWsAfterParenOpen(PME_Subject arg);
PME_OptLayout PME_getSubjectWsAfterParenOpen(PME_Subject arg);
PME_Subject PME_setSubjectWsAfterParenOpen(PME_Subject arg,
					   PME_OptLayout wsAfterParenOpen);
ATbool PME_hasSubjectId(PME_Subject arg);
PME_String PME_getSubjectId(PME_Subject arg);
PME_Subject PME_setSubjectId(PME_Subject arg, PME_String id);
ATbool PME_hasSubjectWsAfterId(PME_Subject arg);
PME_OptLayout PME_getSubjectWsAfterId(PME_Subject arg);
PME_Subject PME_setSubjectWsAfterId(PME_Subject arg, PME_OptLayout wsAfterId);
ATbool PME_hasSubjectWsAfterComma(PME_Subject arg);
PME_OptLayout PME_getSubjectWsAfterComma(PME_Subject arg);
PME_Subject PME_setSubjectWsAfterComma(PME_Subject arg,
				       PME_OptLayout wsAfterComma);
ATbool PME_hasSubjectLocation(PME_Subject arg);
PME_Location PME_getSubjectLocation(PME_Subject arg);
PME_Subject PME_setSubjectLocation(PME_Subject arg, PME_Location Location);
ATbool PME_hasSubjectWsAfterLocation(PME_Subject arg);
PME_OptLayout PME_getSubjectWsAfterLocation(PME_Subject arg);
PME_Subject PME_setSubjectWsAfterLocation(PME_Subject arg,
					  PME_OptLayout wsAfterLocation);

/*}}}  */
/*{{{  PME_Location accessors */

ATbool PME_isValidLocation(PME_Location arg);
inline ATbool PME_isLocationLocation(PME_Location arg);
ATbool PME_hasLocationWsAfterLocation(PME_Location arg);
PME_OptLayout PME_getLocationWsAfterLocation(PME_Location arg);
PME_Location PME_setLocationWsAfterLocation(PME_Location arg,
					    PME_OptLayout wsAfterLocation);
ATbool PME_hasLocationWsAfterParenOpen(PME_Location arg);
PME_OptLayout PME_getLocationWsAfterParenOpen(PME_Location arg);
PME_Location PME_setLocationWsAfterParenOpen(PME_Location arg,
					     PME_OptLayout wsAfterParenOpen);
ATbool PME_hasLocationFilename(PME_Location arg);
PME_String PME_getLocationFilename(PME_Location arg);
PME_Location PME_setLocationFilename(PME_Location arg, PME_String filename);
ATbool PME_hasLocationWsAfterFilename(PME_Location arg);
PME_OptLayout PME_getLocationWsAfterFilename(PME_Location arg);
PME_Location PME_setLocationWsAfterFilename(PME_Location arg,
					    PME_OptLayout wsAfterFilename);
ATbool PME_hasLocationWsAfterComma(PME_Location arg);
PME_OptLayout PME_getLocationWsAfterComma(PME_Location arg);
PME_Location PME_setLocationWsAfterComma(PME_Location arg,
					 PME_OptLayout wsAfterComma);
ATbool PME_hasLocationArea(PME_Location arg);
PME_Area PME_getLocationArea(PME_Location arg);
PME_Location PME_setLocationArea(PME_Location arg, PME_Area Area);
ATbool PME_hasLocationWsAfterArea(PME_Location arg);
PME_OptLayout PME_getLocationWsAfterArea(PME_Location arg);
PME_Location PME_setLocationWsAfterArea(PME_Location arg,
					PME_OptLayout wsAfterArea);

/*}}}  */
/*{{{  PME_Area accessors */

ATbool PME_isValidArea(PME_Area arg);
inline ATbool PME_isAreaArea(PME_Area arg);
inline ATbool PME_isAreaNoArea(PME_Area arg);
ATbool PME_hasAreaWsAfterArea(PME_Area arg);
PME_OptLayout PME_getAreaWsAfterArea(PME_Area arg);
PME_Area PME_setAreaWsAfterArea(PME_Area arg, PME_OptLayout wsAfterArea);
ATbool PME_hasAreaWsAfterParenOpen(PME_Area arg);
PME_OptLayout PME_getAreaWsAfterParenOpen(PME_Area arg);
PME_Area PME_setAreaWsAfterParenOpen(PME_Area arg,
				     PME_OptLayout wsAfterParenOpen);
ATbool PME_hasAreaStartLine(PME_Area arg);
PME_NatCon PME_getAreaStartLine(PME_Area arg);
PME_Area PME_setAreaStartLine(PME_Area arg, PME_NatCon startLine);
ATbool PME_hasAreaWsAfterStartLine(PME_Area arg);
PME_OptLayout PME_getAreaWsAfterStartLine(PME_Area arg);
PME_Area PME_setAreaWsAfterStartLine(PME_Area arg,
				     PME_OptLayout wsAfterStartLine);
ATbool PME_hasAreaWsAfterComma(PME_Area arg);
PME_OptLayout PME_getAreaWsAfterComma(PME_Area arg);
PME_Area PME_setAreaWsAfterComma(PME_Area arg, PME_OptLayout wsAfterComma);
ATbool PME_hasAreaStartColumn(PME_Area arg);
PME_NatCon PME_getAreaStartColumn(PME_Area arg);
PME_Area PME_setAreaStartColumn(PME_Area arg, PME_NatCon startColumn);
ATbool PME_hasAreaWsAfterStartColumn(PME_Area arg);
PME_OptLayout PME_getAreaWsAfterStartColumn(PME_Area arg);
PME_Area PME_setAreaWsAfterStartColumn(PME_Area arg,
				       PME_OptLayout wsAfterStartColumn);
ATbool PME_hasAreaWsAfterComma1(PME_Area arg);
PME_OptLayout PME_getAreaWsAfterComma1(PME_Area arg);
PME_Area PME_setAreaWsAfterComma1(PME_Area arg, PME_OptLayout wsAfterComma1);
ATbool PME_hasAreaEndLine(PME_Area arg);
PME_NatCon PME_getAreaEndLine(PME_Area arg);
PME_Area PME_setAreaEndLine(PME_Area arg, PME_NatCon endLine);
ATbool PME_hasAreaWsAfterEndLine(PME_Area arg);
PME_OptLayout PME_getAreaWsAfterEndLine(PME_Area arg);
PME_Area PME_setAreaWsAfterEndLine(PME_Area arg,
				   PME_OptLayout wsAfterEndLine);
ATbool PME_hasAreaWsAfterComma2(PME_Area arg);
PME_OptLayout PME_getAreaWsAfterComma2(PME_Area arg);
PME_Area PME_setAreaWsAfterComma2(PME_Area arg, PME_OptLayout wsAfterComma2);
ATbool PME_hasAreaEndColumn(PME_Area arg);
PME_NatCon PME_getAreaEndColumn(PME_Area arg);
PME_Area PME_setAreaEndColumn(PME_Area arg, PME_NatCon endColumn);
ATbool PME_hasAreaWsAfterEndColumn(PME_Area arg);
PME_OptLayout PME_getAreaWsAfterEndColumn(PME_Area arg);
PME_Area PME_setAreaWsAfterEndColumn(PME_Area arg,
				     PME_OptLayout wsAfterEndColumn);
ATbool PME_hasAreaWsAfterComma3(PME_Area arg);
PME_OptLayout PME_getAreaWsAfterComma3(PME_Area arg);
PME_Area PME_setAreaWsAfterComma3(PME_Area arg, PME_OptLayout wsAfterComma3);
ATbool PME_hasAreaStartOffset(PME_Area arg);
PME_NatCon PME_getAreaStartOffset(PME_Area arg);
PME_Area PME_setAreaStartOffset(PME_Area arg, PME_NatCon startOffset);
ATbool PME_hasAreaWsAfterStartOffset(PME_Area arg);
PME_OptLayout PME_getAreaWsAfterStartOffset(PME_Area arg);
PME_Area PME_setAreaWsAfterStartOffset(PME_Area arg,
				       PME_OptLayout wsAfterStartOffset);
ATbool PME_hasAreaWsAfterComma4(PME_Area arg);
PME_OptLayout PME_getAreaWsAfterComma4(PME_Area arg);
PME_Area PME_setAreaWsAfterComma4(PME_Area arg, PME_OptLayout wsAfterComma4);
ATbool PME_hasAreaEndOffset(PME_Area arg);
PME_NatCon PME_getAreaEndOffset(PME_Area arg);
PME_Area PME_setAreaEndOffset(PME_Area arg, PME_NatCon endOffset);
ATbool PME_hasAreaWsAfterEndOffset(PME_Area arg);
PME_OptLayout PME_getAreaWsAfterEndOffset(PME_Area arg);
PME_Area PME_setAreaWsAfterEndOffset(PME_Area arg,
				     PME_OptLayout wsAfterEndOffset);

/*}}}  */
/*{{{  PME_NatCon accessors */

ATbool PME_isValidNatCon(PME_NatCon arg);
inline ATbool PME_isNatConString(PME_NatCon arg);
ATbool PME_hasNatConString(PME_NatCon arg);
char *PME_getNatConString(PME_NatCon arg);
PME_NatCon PME_setNatConString(PME_NatCon arg, char *string);

/*}}}  */
/*{{{  PME_String accessors */

ATbool PME_isValidString(PME_String arg);
inline ATbool PME_isStringString(PME_String arg);
ATbool PME_hasStringString(PME_String arg);
char *PME_getStringString(PME_String arg);
PME_String PME_setStringString(PME_String arg, char *string);

/*}}}  */
/*{{{  PME_OptLayout accessors */

ATbool PME_isValidOptLayout(PME_OptLayout arg);
inline ATbool PME_isOptLayoutAbsent(PME_OptLayout arg);
inline ATbool PME_isOptLayoutPresent(PME_OptLayout arg);
ATbool PME_hasOptLayoutString(PME_OptLayout arg);
char *PME_getOptLayoutString(PME_OptLayout arg);
PME_OptLayout PME_setOptLayoutString(PME_OptLayout arg, char *string);

/*}}}  */
/*{{{  PME_Start accessors */

ATbool PME_isValidStart(PME_Start arg);
inline ATbool PME_isStartArea(PME_Start arg);
inline ATbool PME_isStartLocation(PME_Start arg);
inline ATbool PME_isStartSubject(PME_Start arg);
inline ATbool PME_isStartFeedback(PME_Start arg);
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
ATbool PME_hasStartTopSubject(PME_Start arg);
PME_Subject PME_getStartTopSubject(PME_Start arg);
PME_Start PME_setStartTopSubject(PME_Start arg, PME_Subject topSubject);
ATbool PME_hasStartTopFeedback(PME_Start arg);
PME_Feedback PME_getStartTopFeedback(PME_Start arg);
PME_Start PME_setStartTopFeedback(PME_Start arg, PME_Feedback topFeedback);

/*}}}  */
/*{{{  sort visitors */

PME_Feedback PME_visitFeedback(PME_Feedback arg,
			       PME_OptLayout(*acceptWsAfterInfo)
			       (PME_OptLayout),
			       PME_OptLayout(*acceptWsAfterParenOpen)
			       (PME_OptLayout),
			       PME_String(*acceptId) (PME_String),
			       PME_OptLayout(*acceptWsAfterId)
			       (PME_OptLayout),
			       PME_OptLayout(*acceptWsAfterComma)
			       (PME_OptLayout),
			       PME_String(*acceptProducerId) (PME_String),
			       PME_OptLayout(*acceptWsAfterProducerId)
			       (PME_OptLayout),
			       PME_OptLayout(*acceptWsAfterComma1)
			       (PME_OptLayout),
			       PME_String(*acceptProducerType) (PME_String),
			       PME_OptLayout(*acceptWsAfterProducerType)
			       (PME_OptLayout),
			       PME_OptLayout(*acceptWsAfterComma2)
			       (PME_OptLayout),
			       PME_String(*acceptDescription) (PME_String),
			       PME_OptLayout(*acceptWsAfterDescription)
			       (PME_OptLayout),
			       PME_OptLayout(*acceptWsAfterComma3)
			       (PME_OptLayout),
			       PME_OptLayout(*acceptWsAfterBracketOpen)
			       (PME_OptLayout),
			       PME_SubjectList(*acceptList) (PME_SubjectList),
			       PME_OptLayout(*acceptWsAfterList)
			       (PME_OptLayout),
			       PME_OptLayout(*acceptWsAfterBracketClose)
			       (PME_OptLayout),
			       PME_OptLayout(*acceptWsAfterWarning)
			       (PME_OptLayout),
			       PME_OptLayout(*acceptWsAfterError)
			       (PME_OptLayout),
			       PME_OptLayout(*acceptWsAfterFatalError)
			       (PME_OptLayout));
PME_SubjectList PME_visitSubjectList(PME_SubjectList arg,
				     PME_Subject(*acceptHead) (PME_Subject),
				     PME_OptLayout(*acceptWsAfterHead)
				     (PME_OptLayout),
				     PME_OptLayout(*acceptWsAfterSep)
				     (PME_OptLayout));
PME_Subject PME_visitSubject(PME_Subject arg,
			     PME_OptLayout(*acceptWsAfterSubject)
			     (PME_OptLayout),
			     PME_OptLayout(*acceptWsAfterParenOpen)
			     (PME_OptLayout),
			     PME_String(*acceptId) (PME_String),
			     PME_OptLayout(*acceptWsAfterId) (PME_OptLayout),
			     PME_OptLayout(*acceptWsAfterComma)
			     (PME_OptLayout),
			     PME_Location(*acceptLocation) (PME_Location),
			     PME_OptLayout(*acceptWsAfterLocation)
			     (PME_OptLayout));
PME_Location PME_visitLocation(PME_Location arg,
			       PME_OptLayout(*acceptWsAfterLocation)
			       (PME_OptLayout),
			       PME_OptLayout(*acceptWsAfterParenOpen)
			       (PME_OptLayout),
			       PME_String(*acceptFilename) (PME_String),
			       PME_OptLayout(*acceptWsAfterFilename)
			       (PME_OptLayout),
			       PME_OptLayout(*acceptWsAfterComma)
			       (PME_OptLayout),
			       PME_Area(*acceptArea) (PME_Area),
			       PME_OptLayout(*acceptWsAfterArea)
			       (PME_OptLayout));
PME_Area PME_visitArea(PME_Area arg,
		       PME_OptLayout(*acceptWsAfterArea) (PME_OptLayout),
		       PME_OptLayout(*acceptWsAfterParenOpen) (PME_OptLayout),
		       PME_NatCon(*acceptStartLine) (PME_NatCon),
		       PME_OptLayout(*acceptWsAfterStartLine) (PME_OptLayout),
		       PME_OptLayout(*acceptWsAfterComma) (PME_OptLayout),
		       PME_NatCon(*acceptStartColumn) (PME_NatCon),
		       PME_OptLayout(*acceptWsAfterStartColumn)
		       (PME_OptLayout),
		       PME_OptLayout(*acceptWsAfterComma1) (PME_OptLayout),
		       PME_NatCon(*acceptEndLine) (PME_NatCon),
		       PME_OptLayout(*acceptWsAfterEndLine) (PME_OptLayout),
		       PME_OptLayout(*acceptWsAfterComma2) (PME_OptLayout),
		       PME_NatCon(*acceptEndColumn) (PME_NatCon),
		       PME_OptLayout(*acceptWsAfterEndColumn) (PME_OptLayout),
		       PME_OptLayout(*acceptWsAfterComma3) (PME_OptLayout),
		       PME_NatCon(*acceptStartOffset) (PME_NatCon),
		       PME_OptLayout(*acceptWsAfterStartOffset)
		       (PME_OptLayout),
		       PME_OptLayout(*acceptWsAfterComma4) (PME_OptLayout),
		       PME_NatCon(*acceptEndOffset) (PME_NatCon),
		       PME_OptLayout(*acceptWsAfterEndOffset)
		       (PME_OptLayout));
PME_NatCon PME_visitNatCon(PME_NatCon arg, char *(*acceptString) (char *));
PME_String PME_visitString(PME_String arg, char *(*acceptString) (char *));
PME_OptLayout PME_visitOptLayout(PME_OptLayout arg,
				 char *(*acceptString) (char *));
PME_Start PME_visitStart(PME_Start arg,
			 PME_OptLayout(*acceptWsBefore) (PME_OptLayout),
			 PME_Area(*acceptTopArea) (PME_Area),
			 PME_OptLayout(*acceptWsAfter) (PME_OptLayout),
			 int (*acceptAmbCnt) (int),
			 PME_Location(*acceptTopLocation) (PME_Location),
			 PME_Subject(*acceptTopSubject) (PME_Subject),
			 PME_Feedback(*acceptTopFeedback) (PME_Feedback));

/*}}}  */

#endif /* _PARSEDERRORS_H */
