#ifndef _LIBRARY_H
#define _LIBRARY_H

/*{{{  includes */

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "Library_dict.h"

/*}}}  */

/*{{{  typedefs */

typedef struct _CO_BoolCon *CO_BoolCon;
typedef struct _CO_Boolean *CO_Boolean;
typedef struct _CO_Measure *CO_Measure;
typedef struct _CO_ParseResult *CO_ParseResult;
typedef struct _CO_BytesResult *CO_BytesResult;
typedef struct _CO_WriteResult *CO_WriteResult;
typedef struct _CO_Start *CO_Start;
typedef struct _CO_OptLayout *CO_OptLayout;

/*}}}  */

/*{{{  definition of bottom types */

typedef ATerm CO_Bytes;
typedef ATerm CO_NatCon;
typedef ATerm CO_Feedback;

/*}}}  */

void CO_initLibraryApi(void);

/*{{{  term conversion functions */

CO_BoolCon CO_BoolConFromTerm(ATerm t);
ATerm CO_BoolConToTerm(CO_BoolCon arg);
CO_Boolean CO_BooleanFromTerm(ATerm t);
ATerm CO_BooleanToTerm(CO_Boolean arg);
CO_Measure CO_MeasureFromTerm(ATerm t);
ATerm CO_MeasureToTerm(CO_Measure arg);
CO_ParseResult CO_ParseResultFromTerm(ATerm t);
ATerm CO_ParseResultToTerm(CO_ParseResult arg);
CO_BytesResult CO_BytesResultFromTerm(ATerm t);
ATerm CO_BytesResultToTerm(CO_BytesResult arg);
CO_WriteResult CO_WriteResultFromTerm(ATerm t);
ATerm CO_WriteResultToTerm(CO_WriteResult arg);
CO_Start CO_StartFromTerm(ATerm t);
ATerm CO_StartToTerm(CO_Start arg);
CO_OptLayout CO_OptLayoutFromTerm(ATerm t);
ATerm CO_OptLayoutToTerm(CO_OptLayout arg);

/*}}}  */
/*{{{  list functions */


/*}}}  */
/*{{{  constructors */

CO_BoolCon CO_makeBoolConTrue();
CO_BoolCon CO_makeBoolConFalse();
CO_Boolean CO_makeBooleanConstant(CO_BoolCon BoolCon);
CO_Boolean CO_makeBooleanOr(CO_Boolean lhs, CO_OptLayout wsAfterLhs, CO_OptLayout wsAfterBar, CO_Boolean rhs);
CO_Boolean CO_makeBooleanAnd(CO_Boolean lhs, CO_OptLayout wsAfterLhs, CO_OptLayout wsAfterAmp, CO_Boolean rhs);
CO_Boolean CO_makeBooleanNot(CO_OptLayout wsAfterNot, CO_OptLayout wsAfterParenOpen, CO_Boolean Boolean, CO_OptLayout wsAfterBoolean);
CO_Boolean CO_makeBooleanBracket(CO_OptLayout wsAfterParenOpen, CO_Boolean Boolean, CO_OptLayout wsAfterBoolean);
CO_Measure CO_makeMeasureLess();
CO_Measure CO_makeMeasureGreater();
CO_Measure CO_makeMeasureEqual();
CO_ParseResult CO_makeParseResultSuccess(char* treeSort, CO_OptLayout wsAfterParseTree, CO_OptLayout wsAfterParenOpen, CO_Bytes leftLayout, CO_OptLayout wsAfterLeftLayout, CO_OptLayout wsAfterComma, ATerm tree, CO_OptLayout wsAfterTree, CO_OptLayout wsAfterComma1, CO_Bytes rightLayout, CO_OptLayout wsAfterRightLayout, CO_OptLayout wsAfterComma2, CO_NatCon ambCnt, CO_OptLayout wsAfterAmbCnt);
CO_ParseResult CO_makeParseResultFailure(CO_OptLayout wsAfterParseError, CO_OptLayout wsAfterParenOpen, CO_Feedback Feedback, CO_OptLayout wsAfterFeedback);
CO_BytesResult CO_makeBytesResultSuccess(CO_OptLayout wsAfterRead, CO_OptLayout wsAfterParenOpen, CO_Bytes Bytes, CO_OptLayout wsAfterBytes);
CO_BytesResult CO_makeBytesResultFailure(CO_OptLayout wsAfterReadError, CO_OptLayout wsAfterParenOpen, CO_Feedback Feedback, CO_OptLayout wsAfterFeedback);
CO_WriteResult CO_makeWriteResultSuccess();
CO_WriteResult CO_makeWriteResultFailure();
CO_Start CO_makeStartParseResult(CO_OptLayout wsBefore, CO_ParseResult topParseResult, CO_OptLayout wsAfter, int ambCnt);
CO_Start CO_makeStartBytesResult(CO_OptLayout wsBefore, CO_BytesResult topBytesResult, CO_OptLayout wsAfter, int ambCnt);
CO_Start CO_makeStartWriteResult(CO_OptLayout wsBefore, CO_WriteResult topWriteResult, CO_OptLayout wsAfter, int ambCnt);
CO_Start CO_makeStartMeasure(CO_OptLayout wsBefore, CO_Measure topMeasure, CO_OptLayout wsAfter, int ambCnt);
CO_Start CO_makeStartBoolCon(CO_OptLayout wsBefore, CO_BoolCon topBoolCon, CO_OptLayout wsAfter, int ambCnt);
CO_Start CO_makeStartBoolean(CO_OptLayout wsBefore, CO_Boolean topBoolean, CO_OptLayout wsAfter, int ambCnt);
CO_OptLayout CO_makeOptLayoutAbsent();
CO_OptLayout CO_makeOptLayoutPresent(char* string);

/*}}}  */
/*{{{  equality functions */

ATbool CO_isEqualBoolCon(CO_BoolCon arg0, CO_BoolCon arg1);
ATbool CO_isEqualBoolean(CO_Boolean arg0, CO_Boolean arg1);
ATbool CO_isEqualMeasure(CO_Measure arg0, CO_Measure arg1);
ATbool CO_isEqualParseResult(CO_ParseResult arg0, CO_ParseResult arg1);
ATbool CO_isEqualBytesResult(CO_BytesResult arg0, CO_BytesResult arg1);
ATbool CO_isEqualWriteResult(CO_WriteResult arg0, CO_WriteResult arg1);
ATbool CO_isEqualStart(CO_Start arg0, CO_Start arg1);
ATbool CO_isEqualOptLayout(CO_OptLayout arg0, CO_OptLayout arg1);

/*}}}  */
/*{{{  CO_BoolCon accessors */

ATbool CO_isValidBoolCon(CO_BoolCon arg);
inline ATbool CO_isBoolConTrue(CO_BoolCon arg);
inline ATbool CO_isBoolConFalse(CO_BoolCon arg);

/*}}}  */
/*{{{  CO_Boolean accessors */

ATbool CO_isValidBoolean(CO_Boolean arg);
inline ATbool CO_isBooleanConstant(CO_Boolean arg);
inline ATbool CO_isBooleanOr(CO_Boolean arg);
inline ATbool CO_isBooleanAnd(CO_Boolean arg);
inline ATbool CO_isBooleanNot(CO_Boolean arg);
inline ATbool CO_isBooleanBracket(CO_Boolean arg);
ATbool CO_hasBooleanBoolCon(CO_Boolean arg);
CO_BoolCon CO_getBooleanBoolCon(CO_Boolean arg);
CO_Boolean CO_setBooleanBoolCon(CO_Boolean arg, CO_BoolCon BoolCon);
ATbool CO_hasBooleanLhs(CO_Boolean arg);
CO_Boolean CO_getBooleanLhs(CO_Boolean arg);
CO_Boolean CO_setBooleanLhs(CO_Boolean arg, CO_Boolean lhs);
ATbool CO_hasBooleanWsAfterLhs(CO_Boolean arg);
CO_OptLayout CO_getBooleanWsAfterLhs(CO_Boolean arg);
CO_Boolean CO_setBooleanWsAfterLhs(CO_Boolean arg, CO_OptLayout wsAfterLhs);
ATbool CO_hasBooleanWsAfterBar(CO_Boolean arg);
CO_OptLayout CO_getBooleanWsAfterBar(CO_Boolean arg);
CO_Boolean CO_setBooleanWsAfterBar(CO_Boolean arg, CO_OptLayout wsAfterBar);
ATbool CO_hasBooleanRhs(CO_Boolean arg);
CO_Boolean CO_getBooleanRhs(CO_Boolean arg);
CO_Boolean CO_setBooleanRhs(CO_Boolean arg, CO_Boolean rhs);
ATbool CO_hasBooleanWsAfterAmp(CO_Boolean arg);
CO_OptLayout CO_getBooleanWsAfterAmp(CO_Boolean arg);
CO_Boolean CO_setBooleanWsAfterAmp(CO_Boolean arg, CO_OptLayout wsAfterAmp);
ATbool CO_hasBooleanWsAfterNot(CO_Boolean arg);
CO_OptLayout CO_getBooleanWsAfterNot(CO_Boolean arg);
CO_Boolean CO_setBooleanWsAfterNot(CO_Boolean arg, CO_OptLayout wsAfterNot);
ATbool CO_hasBooleanWsAfterParenOpen(CO_Boolean arg);
CO_OptLayout CO_getBooleanWsAfterParenOpen(CO_Boolean arg);
CO_Boolean CO_setBooleanWsAfterParenOpen(CO_Boolean arg, CO_OptLayout wsAfterParenOpen);
ATbool CO_hasBooleanBoolean(CO_Boolean arg);
CO_Boolean CO_getBooleanBoolean(CO_Boolean arg);
CO_Boolean CO_setBooleanBoolean(CO_Boolean arg, CO_Boolean Boolean);
ATbool CO_hasBooleanWsAfterBoolean(CO_Boolean arg);
CO_OptLayout CO_getBooleanWsAfterBoolean(CO_Boolean arg);
CO_Boolean CO_setBooleanWsAfterBoolean(CO_Boolean arg, CO_OptLayout wsAfterBoolean);

/*}}}  */
/*{{{  CO_Measure accessors */

ATbool CO_isValidMeasure(CO_Measure arg);
inline ATbool CO_isMeasureLess(CO_Measure arg);
inline ATbool CO_isMeasureGreater(CO_Measure arg);
inline ATbool CO_isMeasureEqual(CO_Measure arg);

/*}}}  */
/*{{{  CO_ParseResult accessors */

ATbool CO_isValidParseResult(CO_ParseResult arg);
inline ATbool CO_isParseResultSuccess(CO_ParseResult arg);
inline ATbool CO_isParseResultFailure(CO_ParseResult arg);
ATbool CO_hasParseResultTreeSort(CO_ParseResult arg);
char* CO_getParseResultTreeSort(CO_ParseResult arg);
CO_ParseResult CO_setParseResultTreeSort(CO_ParseResult arg, char* treeSort);
ATbool CO_hasParseResultWsAfterParseTree(CO_ParseResult arg);
CO_OptLayout CO_getParseResultWsAfterParseTree(CO_ParseResult arg);
CO_ParseResult CO_setParseResultWsAfterParseTree(CO_ParseResult arg, CO_OptLayout wsAfterParseTree);
ATbool CO_hasParseResultWsAfterParenOpen(CO_ParseResult arg);
CO_OptLayout CO_getParseResultWsAfterParenOpen(CO_ParseResult arg);
CO_ParseResult CO_setParseResultWsAfterParenOpen(CO_ParseResult arg, CO_OptLayout wsAfterParenOpen);
ATbool CO_hasParseResultLeftLayout(CO_ParseResult arg);
CO_Bytes CO_getParseResultLeftLayout(CO_ParseResult arg);
CO_ParseResult CO_setParseResultLeftLayout(CO_ParseResult arg, CO_Bytes leftLayout);
ATbool CO_hasParseResultWsAfterLeftLayout(CO_ParseResult arg);
CO_OptLayout CO_getParseResultWsAfterLeftLayout(CO_ParseResult arg);
CO_ParseResult CO_setParseResultWsAfterLeftLayout(CO_ParseResult arg, CO_OptLayout wsAfterLeftLayout);
ATbool CO_hasParseResultWsAfterComma(CO_ParseResult arg);
CO_OptLayout CO_getParseResultWsAfterComma(CO_ParseResult arg);
CO_ParseResult CO_setParseResultWsAfterComma(CO_ParseResult arg, CO_OptLayout wsAfterComma);
ATbool CO_hasParseResultTree(CO_ParseResult arg);
ATerm CO_getParseResultTree(CO_ParseResult arg);
CO_ParseResult CO_setParseResultTree(CO_ParseResult arg, ATerm tree);
ATbool CO_hasParseResultWsAfterTree(CO_ParseResult arg);
CO_OptLayout CO_getParseResultWsAfterTree(CO_ParseResult arg);
CO_ParseResult CO_setParseResultWsAfterTree(CO_ParseResult arg, CO_OptLayout wsAfterTree);
ATbool CO_hasParseResultWsAfterComma1(CO_ParseResult arg);
CO_OptLayout CO_getParseResultWsAfterComma1(CO_ParseResult arg);
CO_ParseResult CO_setParseResultWsAfterComma1(CO_ParseResult arg, CO_OptLayout wsAfterComma1);
ATbool CO_hasParseResultRightLayout(CO_ParseResult arg);
CO_Bytes CO_getParseResultRightLayout(CO_ParseResult arg);
CO_ParseResult CO_setParseResultRightLayout(CO_ParseResult arg, CO_Bytes rightLayout);
ATbool CO_hasParseResultWsAfterRightLayout(CO_ParseResult arg);
CO_OptLayout CO_getParseResultWsAfterRightLayout(CO_ParseResult arg);
CO_ParseResult CO_setParseResultWsAfterRightLayout(CO_ParseResult arg, CO_OptLayout wsAfterRightLayout);
ATbool CO_hasParseResultWsAfterComma2(CO_ParseResult arg);
CO_OptLayout CO_getParseResultWsAfterComma2(CO_ParseResult arg);
CO_ParseResult CO_setParseResultWsAfterComma2(CO_ParseResult arg, CO_OptLayout wsAfterComma2);
ATbool CO_hasParseResultAmbCnt(CO_ParseResult arg);
CO_NatCon CO_getParseResultAmbCnt(CO_ParseResult arg);
CO_ParseResult CO_setParseResultAmbCnt(CO_ParseResult arg, CO_NatCon ambCnt);
ATbool CO_hasParseResultWsAfterAmbCnt(CO_ParseResult arg);
CO_OptLayout CO_getParseResultWsAfterAmbCnt(CO_ParseResult arg);
CO_ParseResult CO_setParseResultWsAfterAmbCnt(CO_ParseResult arg, CO_OptLayout wsAfterAmbCnt);
ATbool CO_hasParseResultWsAfterParseError(CO_ParseResult arg);
CO_OptLayout CO_getParseResultWsAfterParseError(CO_ParseResult arg);
CO_ParseResult CO_setParseResultWsAfterParseError(CO_ParseResult arg, CO_OptLayout wsAfterParseError);
ATbool CO_hasParseResultFeedback(CO_ParseResult arg);
CO_Feedback CO_getParseResultFeedback(CO_ParseResult arg);
CO_ParseResult CO_setParseResultFeedback(CO_ParseResult arg, CO_Feedback Feedback);
ATbool CO_hasParseResultWsAfterFeedback(CO_ParseResult arg);
CO_OptLayout CO_getParseResultWsAfterFeedback(CO_ParseResult arg);
CO_ParseResult CO_setParseResultWsAfterFeedback(CO_ParseResult arg, CO_OptLayout wsAfterFeedback);

/*}}}  */
/*{{{  CO_BytesResult accessors */

ATbool CO_isValidBytesResult(CO_BytesResult arg);
inline ATbool CO_isBytesResultSuccess(CO_BytesResult arg);
inline ATbool CO_isBytesResultFailure(CO_BytesResult arg);
ATbool CO_hasBytesResultWsAfterRead(CO_BytesResult arg);
CO_OptLayout CO_getBytesResultWsAfterRead(CO_BytesResult arg);
CO_BytesResult CO_setBytesResultWsAfterRead(CO_BytesResult arg, CO_OptLayout wsAfterRead);
ATbool CO_hasBytesResultWsAfterParenOpen(CO_BytesResult arg);
CO_OptLayout CO_getBytesResultWsAfterParenOpen(CO_BytesResult arg);
CO_BytesResult CO_setBytesResultWsAfterParenOpen(CO_BytesResult arg, CO_OptLayout wsAfterParenOpen);
ATbool CO_hasBytesResultBytes(CO_BytesResult arg);
CO_Bytes CO_getBytesResultBytes(CO_BytesResult arg);
CO_BytesResult CO_setBytesResultBytes(CO_BytesResult arg, CO_Bytes Bytes);
ATbool CO_hasBytesResultWsAfterBytes(CO_BytesResult arg);
CO_OptLayout CO_getBytesResultWsAfterBytes(CO_BytesResult arg);
CO_BytesResult CO_setBytesResultWsAfterBytes(CO_BytesResult arg, CO_OptLayout wsAfterBytes);
ATbool CO_hasBytesResultWsAfterReadError(CO_BytesResult arg);
CO_OptLayout CO_getBytesResultWsAfterReadError(CO_BytesResult arg);
CO_BytesResult CO_setBytesResultWsAfterReadError(CO_BytesResult arg, CO_OptLayout wsAfterReadError);
ATbool CO_hasBytesResultFeedback(CO_BytesResult arg);
CO_Feedback CO_getBytesResultFeedback(CO_BytesResult arg);
CO_BytesResult CO_setBytesResultFeedback(CO_BytesResult arg, CO_Feedback Feedback);
ATbool CO_hasBytesResultWsAfterFeedback(CO_BytesResult arg);
CO_OptLayout CO_getBytesResultWsAfterFeedback(CO_BytesResult arg);
CO_BytesResult CO_setBytesResultWsAfterFeedback(CO_BytesResult arg, CO_OptLayout wsAfterFeedback);

/*}}}  */
/*{{{  CO_WriteResult accessors */

ATbool CO_isValidWriteResult(CO_WriteResult arg);
inline ATbool CO_isWriteResultSuccess(CO_WriteResult arg);
inline ATbool CO_isWriteResultFailure(CO_WriteResult arg);

/*}}}  */
/*{{{  CO_Start accessors */

ATbool CO_isValidStart(CO_Start arg);
inline ATbool CO_isStartParseResult(CO_Start arg);
inline ATbool CO_isStartBytesResult(CO_Start arg);
inline ATbool CO_isStartWriteResult(CO_Start arg);
inline ATbool CO_isStartMeasure(CO_Start arg);
inline ATbool CO_isStartBoolCon(CO_Start arg);
inline ATbool CO_isStartBoolean(CO_Start arg);
ATbool CO_hasStartWsBefore(CO_Start arg);
CO_OptLayout CO_getStartWsBefore(CO_Start arg);
CO_Start CO_setStartWsBefore(CO_Start arg, CO_OptLayout wsBefore);
ATbool CO_hasStartTopParseResult(CO_Start arg);
CO_ParseResult CO_getStartTopParseResult(CO_Start arg);
CO_Start CO_setStartTopParseResult(CO_Start arg, CO_ParseResult topParseResult);
ATbool CO_hasStartWsAfter(CO_Start arg);
CO_OptLayout CO_getStartWsAfter(CO_Start arg);
CO_Start CO_setStartWsAfter(CO_Start arg, CO_OptLayout wsAfter);
ATbool CO_hasStartAmbCnt(CO_Start arg);
int CO_getStartAmbCnt(CO_Start arg);
CO_Start CO_setStartAmbCnt(CO_Start arg, int ambCnt);
ATbool CO_hasStartTopBytesResult(CO_Start arg);
CO_BytesResult CO_getStartTopBytesResult(CO_Start arg);
CO_Start CO_setStartTopBytesResult(CO_Start arg, CO_BytesResult topBytesResult);
ATbool CO_hasStartTopWriteResult(CO_Start arg);
CO_WriteResult CO_getStartTopWriteResult(CO_Start arg);
CO_Start CO_setStartTopWriteResult(CO_Start arg, CO_WriteResult topWriteResult);
ATbool CO_hasStartTopMeasure(CO_Start arg);
CO_Measure CO_getStartTopMeasure(CO_Start arg);
CO_Start CO_setStartTopMeasure(CO_Start arg, CO_Measure topMeasure);
ATbool CO_hasStartTopBoolCon(CO_Start arg);
CO_BoolCon CO_getStartTopBoolCon(CO_Start arg);
CO_Start CO_setStartTopBoolCon(CO_Start arg, CO_BoolCon topBoolCon);
ATbool CO_hasStartTopBoolean(CO_Start arg);
CO_Boolean CO_getStartTopBoolean(CO_Start arg);
CO_Start CO_setStartTopBoolean(CO_Start arg, CO_Boolean topBoolean);

/*}}}  */
/*{{{  CO_OptLayout accessors */

ATbool CO_isValidOptLayout(CO_OptLayout arg);
inline ATbool CO_isOptLayoutAbsent(CO_OptLayout arg);
inline ATbool CO_isOptLayoutPresent(CO_OptLayout arg);
ATbool CO_hasOptLayoutString(CO_OptLayout arg);
char* CO_getOptLayoutString(CO_OptLayout arg);
CO_OptLayout CO_setOptLayoutString(CO_OptLayout arg, char* string);

/*}}}  */
/*{{{  sort visitors */

CO_BoolCon CO_visitBoolCon(CO_BoolCon arg);
CO_Boolean CO_visitBoolean(CO_Boolean arg, CO_BoolCon (*acceptBoolCon)(CO_BoolCon), CO_OptLayout (*acceptWsAfterLhs)(CO_OptLayout), CO_OptLayout (*acceptWsAfterBar)(CO_OptLayout), CO_OptLayout (*acceptWsAfterAmp)(CO_OptLayout), CO_OptLayout (*acceptWsAfterNot)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_OptLayout (*acceptWsAfterBoolean)(CO_OptLayout));
CO_Measure CO_visitMeasure(CO_Measure arg);
CO_ParseResult CO_visitParseResult(CO_ParseResult arg, char* (*acceptTreeSort)(char*), CO_OptLayout (*acceptWsAfterParseTree)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_Bytes (*acceptLeftLayout)(CO_Bytes), CO_OptLayout (*acceptWsAfterLeftLayout)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma)(CO_OptLayout), ATerm (*acceptTree)(ATerm), CO_OptLayout (*acceptWsAfterTree)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma1)(CO_OptLayout), CO_Bytes (*acceptRightLayout)(CO_Bytes), CO_OptLayout (*acceptWsAfterRightLayout)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma2)(CO_OptLayout), CO_NatCon (*acceptAmbCnt)(CO_NatCon), CO_OptLayout (*acceptWsAfterAmbCnt)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParseError)(CO_OptLayout), CO_Feedback (*acceptFeedback)(CO_Feedback), CO_OptLayout (*acceptWsAfterFeedback)(CO_OptLayout));
CO_BytesResult CO_visitBytesResult(CO_BytesResult arg, CO_OptLayout (*acceptWsAfterRead)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_Bytes (*acceptBytes)(CO_Bytes), CO_OptLayout (*acceptWsAfterBytes)(CO_OptLayout), CO_OptLayout (*acceptWsAfterReadError)(CO_OptLayout), CO_Feedback (*acceptFeedback)(CO_Feedback), CO_OptLayout (*acceptWsAfterFeedback)(CO_OptLayout));
CO_WriteResult CO_visitWriteResult(CO_WriteResult arg);
CO_Start CO_visitStart(CO_Start arg, CO_OptLayout (*acceptWsBefore)(CO_OptLayout), CO_ParseResult (*acceptTopParseResult)(CO_ParseResult), CO_OptLayout (*acceptWsAfter)(CO_OptLayout), int (*acceptAmbCnt)(int), CO_BytesResult (*acceptTopBytesResult)(CO_BytesResult), CO_WriteResult (*acceptTopWriteResult)(CO_WriteResult), CO_Measure (*acceptTopMeasure)(CO_Measure), CO_BoolCon (*acceptTopBoolCon)(CO_BoolCon), CO_Boolean (*acceptTopBoolean)(CO_Boolean));
CO_OptLayout CO_visitOptLayout(CO_OptLayout arg, char* (*acceptString)(char*));

/*}}}  */

#endif /* _LIBRARY_H */
