#ifndef _LIBRARY_H
#define _LIBRARY_H

/*{{{  includes */

#include <aterm1.h>
#include "Library_dict.h"

/*}}}  */

/*{{{  prologue */

typedef ATerm CO_Bytes;
typedef ATerm CO_NatCon;
typedef struct _CO_CHARLIST *CO_CHARLIST;

ATbool CO_isValidCHARLIST(CO_CHARLIST arg);
ATbool CO_isCHARLISTString(CO_CHARLIST arg);
char*  CO_getCHARLISTString(CO_CHARLIST arg);
CO_CHARLIST  CO_setCHARLISTString(CO_CHARLIST arg, char *str);
ATerm  CO_CHARLISTToTerm(CO_CHARLIST arg);
CO_CHARLIST CO_CHARLISTFromTerm(ATerm trm);
CO_CHARLIST CO_makeCHARLISTString(char *str);

/*}}}  */
/*{{{  typedefs */

typedef struct _CO_BoolCon *CO_BoolCon;
typedef struct _CO_Boolean *CO_Boolean;
typedef struct _CO_Measure *CO_Measure;
typedef struct _CO_ParseResult *CO_ParseResult;
typedef struct _CO_Start *CO_Start;
typedef struct _CO_OptLayout *CO_OptLayout;

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
CO_ParseResult CO_makeParseResultTree(char* treeSort, CO_OptLayout wsAfterParseTree, CO_OptLayout wsAfterParenOpen, CO_Bytes leftLayout, CO_OptLayout wsAfterLeftLayout, CO_OptLayout wsAfterC1, ATerm tree, CO_OptLayout wsAfterTree, CO_OptLayout wsAfterC2, CO_Bytes rightLayout, CO_OptLayout wsAfterRightLayout, CO_OptLayout wsAfterC3, CO_NatCon ambCnt, CO_OptLayout wsAfterAmbCnt);
CO_ParseResult CO_makeParseResultError(CO_OptLayout wsAfterParseError, CO_OptLayout wsAfterParenOpen, CO_NatCon line, CO_OptLayout wsAfterLine, CO_OptLayout wsAfterC1, CO_NatCon column, CO_OptLayout wsAfterColumn, CO_OptLayout wsAfterC2, CO_NatCon offset, CO_OptLayout wsAfterOffset);
CO_ParseResult CO_makeParseResultNoParsetable();
CO_ParseResult CO_makeParseResultNoValidResult();
CO_Start CO_makeStartParseResult(CO_OptLayout wsBefore, CO_ParseResult topParseResult, CO_OptLayout wsAfter, int ambCnt);
CO_Start CO_makeStartMeasure(CO_OptLayout wsBefore, CO_Measure topMeasure, CO_OptLayout wsAfter, int ambCnt);
CO_Start CO_makeStartBoolCon(CO_OptLayout wsBefore, CO_BoolCon topBoolCon, CO_OptLayout wsAfter, int ambCnt);
CO_Start CO_makeStartBoolean(CO_OptLayout wsBefore, CO_Boolean topBoolean, CO_OptLayout wsAfter, int ambCnt);
CO_OptLayout CO_makeOptLayoutAbsent();
CO_OptLayout CO_makeOptLayoutPresent(CO_CHARLIST chars);

/*}}}  */
/*{{{  equality functions */

ATbool CO_isEqualBoolCon(CO_BoolCon arg0, CO_BoolCon arg1);
ATbool CO_isEqualBoolean(CO_Boolean arg0, CO_Boolean arg1);
ATbool CO_isEqualMeasure(CO_Measure arg0, CO_Measure arg1);
ATbool CO_isEqualParseResult(CO_ParseResult arg0, CO_ParseResult arg1);
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
inline ATbool CO_isParseResultTree(CO_ParseResult arg);
inline ATbool CO_isParseResultError(CO_ParseResult arg);
inline ATbool CO_isParseResultNoParsetable(CO_ParseResult arg);
inline ATbool CO_isParseResultNoValidResult(CO_ParseResult arg);
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
ATbool CO_hasParseResultWsAfterC1(CO_ParseResult arg);
CO_OptLayout CO_getParseResultWsAfterC1(CO_ParseResult arg);
CO_ParseResult CO_setParseResultWsAfterC1(CO_ParseResult arg, CO_OptLayout wsAfterC1);
ATbool CO_hasParseResultTree(CO_ParseResult arg);
ATerm CO_getParseResultTree(CO_ParseResult arg);
CO_ParseResult CO_setParseResultTree(CO_ParseResult arg, ATerm tree);
ATbool CO_hasParseResultWsAfterTree(CO_ParseResult arg);
CO_OptLayout CO_getParseResultWsAfterTree(CO_ParseResult arg);
CO_ParseResult CO_setParseResultWsAfterTree(CO_ParseResult arg, CO_OptLayout wsAfterTree);
ATbool CO_hasParseResultWsAfterC2(CO_ParseResult arg);
CO_OptLayout CO_getParseResultWsAfterC2(CO_ParseResult arg);
CO_ParseResult CO_setParseResultWsAfterC2(CO_ParseResult arg, CO_OptLayout wsAfterC2);
ATbool CO_hasParseResultRightLayout(CO_ParseResult arg);
CO_Bytes CO_getParseResultRightLayout(CO_ParseResult arg);
CO_ParseResult CO_setParseResultRightLayout(CO_ParseResult arg, CO_Bytes rightLayout);
ATbool CO_hasParseResultWsAfterRightLayout(CO_ParseResult arg);
CO_OptLayout CO_getParseResultWsAfterRightLayout(CO_ParseResult arg);
CO_ParseResult CO_setParseResultWsAfterRightLayout(CO_ParseResult arg, CO_OptLayout wsAfterRightLayout);
ATbool CO_hasParseResultWsAfterC3(CO_ParseResult arg);
CO_OptLayout CO_getParseResultWsAfterC3(CO_ParseResult arg);
CO_ParseResult CO_setParseResultWsAfterC3(CO_ParseResult arg, CO_OptLayout wsAfterC3);
ATbool CO_hasParseResultAmbCnt(CO_ParseResult arg);
CO_NatCon CO_getParseResultAmbCnt(CO_ParseResult arg);
CO_ParseResult CO_setParseResultAmbCnt(CO_ParseResult arg, CO_NatCon ambCnt);
ATbool CO_hasParseResultWsAfterAmbCnt(CO_ParseResult arg);
CO_OptLayout CO_getParseResultWsAfterAmbCnt(CO_ParseResult arg);
CO_ParseResult CO_setParseResultWsAfterAmbCnt(CO_ParseResult arg, CO_OptLayout wsAfterAmbCnt);
ATbool CO_hasParseResultWsAfterParseError(CO_ParseResult arg);
CO_OptLayout CO_getParseResultWsAfterParseError(CO_ParseResult arg);
CO_ParseResult CO_setParseResultWsAfterParseError(CO_ParseResult arg, CO_OptLayout wsAfterParseError);
ATbool CO_hasParseResultLine(CO_ParseResult arg);
CO_NatCon CO_getParseResultLine(CO_ParseResult arg);
CO_ParseResult CO_setParseResultLine(CO_ParseResult arg, CO_NatCon line);
ATbool CO_hasParseResultWsAfterLine(CO_ParseResult arg);
CO_OptLayout CO_getParseResultWsAfterLine(CO_ParseResult arg);
CO_ParseResult CO_setParseResultWsAfterLine(CO_ParseResult arg, CO_OptLayout wsAfterLine);
ATbool CO_hasParseResultColumn(CO_ParseResult arg);
CO_NatCon CO_getParseResultColumn(CO_ParseResult arg);
CO_ParseResult CO_setParseResultColumn(CO_ParseResult arg, CO_NatCon column);
ATbool CO_hasParseResultWsAfterColumn(CO_ParseResult arg);
CO_OptLayout CO_getParseResultWsAfterColumn(CO_ParseResult arg);
CO_ParseResult CO_setParseResultWsAfterColumn(CO_ParseResult arg, CO_OptLayout wsAfterColumn);
ATbool CO_hasParseResultOffset(CO_ParseResult arg);
CO_NatCon CO_getParseResultOffset(CO_ParseResult arg);
CO_ParseResult CO_setParseResultOffset(CO_ParseResult arg, CO_NatCon offset);
ATbool CO_hasParseResultWsAfterOffset(CO_ParseResult arg);
CO_OptLayout CO_getParseResultWsAfterOffset(CO_ParseResult arg);
CO_ParseResult CO_setParseResultWsAfterOffset(CO_ParseResult arg, CO_OptLayout wsAfterOffset);

/*}}}  */
/*{{{  CO_Start accessors */

ATbool CO_isValidStart(CO_Start arg);
inline ATbool CO_isStartParseResult(CO_Start arg);
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
ATbool CO_hasOptLayoutChars(CO_OptLayout arg);
CO_CHARLIST CO_getOptLayoutChars(CO_OptLayout arg);
CO_OptLayout CO_setOptLayoutChars(CO_OptLayout arg, CO_CHARLIST chars);

/*}}}  */
/*{{{  sort visitors */

CO_BoolCon CO_visitBoolCon(CO_BoolCon arg);
CO_Boolean CO_visitBoolean(CO_Boolean arg, CO_BoolCon (*acceptBoolCon)(CO_BoolCon), CO_OptLayout (*acceptWsAfterLhs)(CO_OptLayout), CO_OptLayout (*acceptWsAfterBar)(CO_OptLayout), CO_OptLayout (*acceptWsAfterAmp)(CO_OptLayout), CO_OptLayout (*acceptWsAfterNot)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_OptLayout (*acceptWsAfterBoolean)(CO_OptLayout));
CO_Measure CO_visitMeasure(CO_Measure arg);
CO_ParseResult CO_visitParseResult(CO_ParseResult arg, char* (*acceptTreeSort)(char*), CO_OptLayout (*acceptWsAfterParseTree)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_Bytes (*acceptLeftLayout)(CO_Bytes), CO_OptLayout (*acceptWsAfterLeftLayout)(CO_OptLayout), CO_OptLayout (*acceptWsAfterC1)(CO_OptLayout), ATerm (*acceptTree)(ATerm), CO_OptLayout (*acceptWsAfterTree)(CO_OptLayout), CO_OptLayout (*acceptWsAfterC2)(CO_OptLayout), CO_Bytes (*acceptRightLayout)(CO_Bytes), CO_OptLayout (*acceptWsAfterRightLayout)(CO_OptLayout), CO_OptLayout (*acceptWsAfterC3)(CO_OptLayout), CO_NatCon (*acceptAmbCnt)(CO_NatCon), CO_OptLayout (*acceptWsAfterAmbCnt)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParseError)(CO_OptLayout), CO_NatCon (*acceptLine)(CO_NatCon), CO_OptLayout (*acceptWsAfterLine)(CO_OptLayout), CO_NatCon (*acceptColumn)(CO_NatCon), CO_OptLayout (*acceptWsAfterColumn)(CO_OptLayout), CO_NatCon (*acceptOffset)(CO_NatCon), CO_OptLayout (*acceptWsAfterOffset)(CO_OptLayout));
CO_Start CO_visitStart(CO_Start arg, CO_OptLayout (*acceptWsBefore)(CO_OptLayout), CO_ParseResult (*acceptTopParseResult)(CO_ParseResult), CO_OptLayout (*acceptWsAfter)(CO_OptLayout), int (*acceptAmbCnt)(int), CO_Measure (*acceptTopMeasure)(CO_Measure), CO_BoolCon (*acceptTopBoolCon)(CO_BoolCon), CO_Boolean (*acceptTopBoolean)(CO_Boolean));
CO_OptLayout CO_visitOptLayout(CO_OptLayout arg, CO_CHARLIST (*acceptChars)(CO_CHARLIST));

/*}}}  */

#endif /* _LIBRARY_H */
