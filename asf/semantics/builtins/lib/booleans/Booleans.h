#ifndef _BOOLEANS_H
#define _BOOLEANS_H

/*{{{  includes */

#include <aterm1.h>
#include "Booleans_dict.h"

/*}}}  */

/*{{{  prologue */

typedef struct _B_CHARLIST *B_CHARLIST;

ATbool B_isValidCHARLIST(B_CHARLIST arg);
ATbool B_isCHARLISTString(B_CHARLIST arg);
char*  B_getCHARLISTString(B_CHARLIST arg);
B_CHARLIST  B_setCHARLISTString(B_CHARLIST arg, char *str);
ATerm  B_CHARLISTToTerm(B_CHARLIST arg);
B_CHARLIST B_CHARLISTFromTerm(ATerm trm);
B_CHARLIST B_makeCHARLISTString(char *str);

/*}}}  */
/*{{{  typedefs */

typedef struct _B_BoolCon *B_BoolCon;
typedef struct _B_Boolean *B_Boolean;
typedef struct _B_Start *B_Start;
typedef struct _B_OptLayout *B_OptLayout;

/*}}}  */

void B_initBooleansApi(void);

/*{{{  term conversion functions */

B_BoolCon B_BoolConFromTerm(ATerm t);
ATerm B_BoolConToTerm(B_BoolCon arg);
B_Boolean B_BooleanFromTerm(ATerm t);
ATerm B_BooleanToTerm(B_Boolean arg);
B_Start B_StartFromTerm(ATerm t);
ATerm B_StartToTerm(B_Start arg);
B_OptLayout B_OptLayoutFromTerm(ATerm t);
ATerm B_OptLayoutToTerm(B_OptLayout arg);

/*}}}  */
/*{{{  constructors */

B_BoolCon B_makeBoolConTrue();
B_BoolCon B_makeBoolConFalse();
B_Boolean B_makeBooleanConstant(B_BoolCon BoolCon);
B_Boolean B_makeBooleanOr(B_Boolean lhs, B_OptLayout wsAfterLhs, B_OptLayout wsAfterBar, B_Boolean rhs);
B_Boolean B_makeBooleanAnd(B_Boolean lhs, B_OptLayout wsAfterLhs, B_OptLayout wsAfterAmp, B_Boolean rhs);
B_Boolean B_makeBooleanNot(B_OptLayout wsAfterNot, B_OptLayout wsAfterParenOpen, B_Boolean Boolean, B_OptLayout wsAfterBoolean);
B_Boolean B_makeBooleanBracket(B_OptLayout wsAfterParenOpen, B_Boolean Boolean, B_OptLayout wsAfterBoolean);
B_Start B_makeStartBoolCon(B_OptLayout wsBefore, B_BoolCon topBoolCon, B_OptLayout wsAfter, int ambCnt);
B_Start B_makeStartBoolean(B_OptLayout wsBefore, B_Boolean topBoolean, B_OptLayout wsAfter, int ambCnt);
B_OptLayout B_makeOptLayoutAbsent();
B_OptLayout B_makeOptLayoutPresent(B_CHARLIST chars);

/*}}}  */
/*{{{  equality functions */

ATbool B_isEqualBoolCon(B_BoolCon arg0, B_BoolCon arg1);
ATbool B_isEqualBoolean(B_Boolean arg0, B_Boolean arg1);
ATbool B_isEqualStart(B_Start arg0, B_Start arg1);
ATbool B_isEqualOptLayout(B_OptLayout arg0, B_OptLayout arg1);

/*}}}  */
/*{{{  B_BoolCon accessors */

ATbool B_isValidBoolCon(B_BoolCon arg);
inline ATbool B_isBoolConTrue(B_BoolCon arg);
inline ATbool B_isBoolConFalse(B_BoolCon arg);

/*}}}  */
/*{{{  B_Boolean accessors */

ATbool B_isValidBoolean(B_Boolean arg);
inline ATbool B_isBooleanConstant(B_Boolean arg);
inline ATbool B_isBooleanOr(B_Boolean arg);
inline ATbool B_isBooleanAnd(B_Boolean arg);
inline ATbool B_isBooleanNot(B_Boolean arg);
inline ATbool B_isBooleanBracket(B_Boolean arg);
ATbool B_hasBooleanBoolCon(B_Boolean arg);
B_BoolCon B_getBooleanBoolCon(B_Boolean arg);
B_Boolean B_setBooleanBoolCon(B_Boolean arg, B_BoolCon BoolCon);
ATbool B_hasBooleanLhs(B_Boolean arg);
B_Boolean B_getBooleanLhs(B_Boolean arg);
B_Boolean B_setBooleanLhs(B_Boolean arg, B_Boolean lhs);
ATbool B_hasBooleanWsAfterLhs(B_Boolean arg);
B_OptLayout B_getBooleanWsAfterLhs(B_Boolean arg);
B_Boolean B_setBooleanWsAfterLhs(B_Boolean arg, B_OptLayout wsAfterLhs);
ATbool B_hasBooleanWsAfterBar(B_Boolean arg);
B_OptLayout B_getBooleanWsAfterBar(B_Boolean arg);
B_Boolean B_setBooleanWsAfterBar(B_Boolean arg, B_OptLayout wsAfterBar);
ATbool B_hasBooleanRhs(B_Boolean arg);
B_Boolean B_getBooleanRhs(B_Boolean arg);
B_Boolean B_setBooleanRhs(B_Boolean arg, B_Boolean rhs);
ATbool B_hasBooleanWsAfterAmp(B_Boolean arg);
B_OptLayout B_getBooleanWsAfterAmp(B_Boolean arg);
B_Boolean B_setBooleanWsAfterAmp(B_Boolean arg, B_OptLayout wsAfterAmp);
ATbool B_hasBooleanWsAfterNot(B_Boolean arg);
B_OptLayout B_getBooleanWsAfterNot(B_Boolean arg);
B_Boolean B_setBooleanWsAfterNot(B_Boolean arg, B_OptLayout wsAfterNot);
ATbool B_hasBooleanWsAfterParenOpen(B_Boolean arg);
B_OptLayout B_getBooleanWsAfterParenOpen(B_Boolean arg);
B_Boolean B_setBooleanWsAfterParenOpen(B_Boolean arg, B_OptLayout wsAfterParenOpen);
ATbool B_hasBooleanBoolean(B_Boolean arg);
B_Boolean B_getBooleanBoolean(B_Boolean arg);
B_Boolean B_setBooleanBoolean(B_Boolean arg, B_Boolean Boolean);
ATbool B_hasBooleanWsAfterBoolean(B_Boolean arg);
B_OptLayout B_getBooleanWsAfterBoolean(B_Boolean arg);
B_Boolean B_setBooleanWsAfterBoolean(B_Boolean arg, B_OptLayout wsAfterBoolean);

/*}}}  */
/*{{{  B_Start accessors */

ATbool B_isValidStart(B_Start arg);
inline ATbool B_isStartBoolCon(B_Start arg);
inline ATbool B_isStartBoolean(B_Start arg);
ATbool B_hasStartWsBefore(B_Start arg);
B_OptLayout B_getStartWsBefore(B_Start arg);
B_Start B_setStartWsBefore(B_Start arg, B_OptLayout wsBefore);
ATbool B_hasStartTopBoolCon(B_Start arg);
B_BoolCon B_getStartTopBoolCon(B_Start arg);
B_Start B_setStartTopBoolCon(B_Start arg, B_BoolCon topBoolCon);
ATbool B_hasStartWsAfter(B_Start arg);
B_OptLayout B_getStartWsAfter(B_Start arg);
B_Start B_setStartWsAfter(B_Start arg, B_OptLayout wsAfter);
ATbool B_hasStartAmbCnt(B_Start arg);
int B_getStartAmbCnt(B_Start arg);
B_Start B_setStartAmbCnt(B_Start arg, int ambCnt);
ATbool B_hasStartTopBoolean(B_Start arg);
B_Boolean B_getStartTopBoolean(B_Start arg);
B_Start B_setStartTopBoolean(B_Start arg, B_Boolean topBoolean);

/*}}}  */
/*{{{  B_OptLayout accessors */

ATbool B_isValidOptLayout(B_OptLayout arg);
inline ATbool B_isOptLayoutAbsent(B_OptLayout arg);
inline ATbool B_isOptLayoutPresent(B_OptLayout arg);
ATbool B_hasOptLayoutChars(B_OptLayout arg);
B_CHARLIST B_getOptLayoutChars(B_OptLayout arg);
B_OptLayout B_setOptLayoutChars(B_OptLayout arg, B_CHARLIST chars);

/*}}}  */
/*{{{  sort visitors */

B_BoolCon B_visitBoolCon(B_BoolCon arg);
B_Boolean B_visitBoolean(B_Boolean arg, B_BoolCon (*acceptBoolCon)(B_BoolCon), B_OptLayout (*acceptWsAfterLhs)(B_OptLayout), B_OptLayout (*acceptWsAfterBar)(B_OptLayout), B_OptLayout (*acceptWsAfterAmp)(B_OptLayout), B_OptLayout (*acceptWsAfterNot)(B_OptLayout), B_OptLayout (*acceptWsAfterParenOpen)(B_OptLayout), B_OptLayout (*acceptWsAfterBoolean)(B_OptLayout));
B_Start B_visitStart(B_Start arg, B_OptLayout (*acceptWsBefore)(B_OptLayout), B_BoolCon (*acceptTopBoolCon)(B_BoolCon), B_OptLayout (*acceptWsAfter)(B_OptLayout), int (*acceptAmbCnt)(int), B_Boolean (*acceptTopBoolean)(B_Boolean));
B_OptLayout B_visitOptLayout(B_OptLayout arg, B_CHARLIST (*acceptChars)(B_CHARLIST));

/*}}}  */

#endif /* _BOOLEANS_H */
