#ifndef _LIBRARY_H
#define _LIBRARY_H

/*{{{  includes */

#include <aterm1.h>
#include "Library_dict.h"

/*}}}  */

/*{{{  prologue */

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
CO_Start CO_StartFromTerm(ATerm t);
ATerm CO_StartToTerm(CO_Start arg);
CO_OptLayout CO_OptLayoutFromTerm(ATerm t);
ATerm CO_OptLayoutToTerm(CO_OptLayout arg);

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
/*{{{  CO_Start accessors */

ATbool CO_isValidStart(CO_Start arg);
inline ATbool CO_isStartMeasure(CO_Start arg);
inline ATbool CO_isStartBoolCon(CO_Start arg);
inline ATbool CO_isStartBoolean(CO_Start arg);
ATbool CO_hasStartWsBefore(CO_Start arg);
CO_OptLayout CO_getStartWsBefore(CO_Start arg);
CO_Start CO_setStartWsBefore(CO_Start arg, CO_OptLayout wsBefore);
ATbool CO_hasStartTopMeasure(CO_Start arg);
CO_Measure CO_getStartTopMeasure(CO_Start arg);
CO_Start CO_setStartTopMeasure(CO_Start arg, CO_Measure topMeasure);
ATbool CO_hasStartWsAfter(CO_Start arg);
CO_OptLayout CO_getStartWsAfter(CO_Start arg);
CO_Start CO_setStartWsAfter(CO_Start arg, CO_OptLayout wsAfter);
ATbool CO_hasStartAmbCnt(CO_Start arg);
int CO_getStartAmbCnt(CO_Start arg);
CO_Start CO_setStartAmbCnt(CO_Start arg, int ambCnt);
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
CO_Start CO_visitStart(CO_Start arg, CO_OptLayout (*acceptWsBefore)(CO_OptLayout), CO_Measure (*acceptTopMeasure)(CO_Measure), CO_OptLayout (*acceptWsAfter)(CO_OptLayout), int (*acceptAmbCnt)(int), CO_BoolCon (*acceptTopBoolCon)(CO_BoolCon), CO_Boolean (*acceptTopBoolean)(CO_Boolean));
CO_OptLayout CO_visitOptLayout(CO_OptLayout arg, CO_CHARLIST (*acceptChars)(CO_CHARLIST));

/*}}}  */

#endif /* _LIBRARY_H */
