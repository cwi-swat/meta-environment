#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "Library.h"

/*{{{  typedefs */

typedef struct ATerm _CO_BoolCon;
typedef struct ATerm _CO_Boolean;
typedef struct ATerm _CO_Measure;
typedef struct ATerm _CO_ParseResult;
typedef struct ATerm _CO_Start;
typedef struct ATerm _CO_OptLayout;

/*}}}  */

/*{{{  void CO_initLibraryApi(void) */

void CO_initLibraryApi(void)
{
  init_Library_dict();
}

/*}}}  */

/*{{{  term conversion functions */

/*{{{  CO_BoolCon CO_BoolConFromTerm(ATerm t) */

CO_BoolCon CO_BoolConFromTerm(ATerm t)
{
  return (CO_BoolCon)t;
}

/*}}}  */
/*{{{  ATerm CO_BoolConToTerm(CO_BoolCon arg) */

ATerm CO_BoolConToTerm(CO_BoolCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CO_Boolean CO_BooleanFromTerm(ATerm t) */

CO_Boolean CO_BooleanFromTerm(ATerm t)
{
  return (CO_Boolean)t;
}

/*}}}  */
/*{{{  ATerm CO_BooleanToTerm(CO_Boolean arg) */

ATerm CO_BooleanToTerm(CO_Boolean arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CO_Measure CO_MeasureFromTerm(ATerm t) */

CO_Measure CO_MeasureFromTerm(ATerm t)
{
  return (CO_Measure)t;
}

/*}}}  */
/*{{{  ATerm CO_MeasureToTerm(CO_Measure arg) */

ATerm CO_MeasureToTerm(CO_Measure arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CO_ParseResult CO_ParseResultFromTerm(ATerm t) */

CO_ParseResult CO_ParseResultFromTerm(ATerm t)
{
  return (CO_ParseResult)t;
}

/*}}}  */
/*{{{  ATerm CO_ParseResultToTerm(CO_ParseResult arg) */

ATerm CO_ParseResultToTerm(CO_ParseResult arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CO_Start CO_StartFromTerm(ATerm t) */

CO_Start CO_StartFromTerm(ATerm t)
{
  return (CO_Start)t;
}

/*}}}  */
/*{{{  ATerm CO_StartToTerm(CO_Start arg) */

ATerm CO_StartToTerm(CO_Start arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CO_OptLayout CO_OptLayoutFromTerm(ATerm t) */

CO_OptLayout CO_OptLayoutFromTerm(ATerm t)
{
  return (CO_OptLayout)t;
}

/*}}}  */
/*{{{  ATerm CO_OptLayoutToTerm(CO_OptLayout arg) */

ATerm CO_OptLayoutToTerm(CO_OptLayout arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*}}}  */
/*{{{  list functions */


/*}}}  */
/*{{{  constructors */

/*{{{  CO_BoolCon CO_makeBoolConTrue() */

CO_BoolCon CO_makeBoolConTrue()
{
  return (CO_BoolCon)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun3))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun5, (ATerm)ATmakeAppl0(CO_afun6))), (ATerm)ATmakeAppl1(CO_afun7, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun8, (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeAppl0(CO_afun3)))), (ATerm)ATmakeAppl1(CO_afun8, (ATerm)ATmakeAppl0(CO_afun10))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun3))));
}

/*}}}  */
/*{{{  CO_BoolCon CO_makeBoolConFalse() */

CO_BoolCon CO_makeBoolConFalse()
{
  return (CO_BoolCon)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun11))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun5, (ATerm)ATmakeAppl0(CO_afun6))), (ATerm)ATmakeAppl1(CO_afun7, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun8, (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeAppl0(CO_afun11)))), (ATerm)ATmakeAppl1(CO_afun8, (ATerm)ATmakeAppl0(CO_afun10))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun11))));
}

/*}}}  */
/*{{{  CO_Boolean CO_makeBooleanConstant(CO_BoolCon BoolCon) */

CO_Boolean CO_makeBooleanConstant(CO_BoolCon BoolCon)
{
  return (CO_Boolean)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun5, (ATerm)ATmakeAppl0(CO_afun6)))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun5, (ATerm)ATmakeAppl0(CO_afun12))), (ATerm)ATmakeAppl1(CO_afun7, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun8, (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeAppl0(CO_afun13)))))), (ATerm)ATmakeList1((ATerm)BoolCon));
}

/*}}}  */
/*{{{  CO_Boolean CO_makeBooleanOr(CO_Boolean lhs, CO_OptLayout wsAfterLhs, CO_OptLayout wsAfterBar, CO_Boolean rhs) */

CO_Boolean CO_makeBooleanOr(CO_Boolean lhs, CO_OptLayout wsAfterLhs, CO_OptLayout wsAfterBar, CO_Boolean rhs)
{
  return (CO_Boolean)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun5, (ATerm)ATmakeAppl0(CO_afun12)))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun14, (ATerm)ATmakeAppl0(CO_afun15)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun16))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun14, (ATerm)ATmakeAppl0(CO_afun15)))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun5, (ATerm)ATmakeAppl0(CO_afun12)))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun5, (ATerm)ATmakeAppl0(CO_afun12))), (ATerm)ATmakeAppl1(CO_afun7, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun8, (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeAppl0(CO_afun17)))), (ATerm)ATmakeAppl1(CO_afun18, (ATerm)ATmakeAppl0(CO_afun19))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)rhs), (ATerm)wsAfterBar), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun16))), (ATerm)wsAfterLhs), (ATerm)lhs));
}

/*}}}  */
/*{{{  CO_Boolean CO_makeBooleanAnd(CO_Boolean lhs, CO_OptLayout wsAfterLhs, CO_OptLayout wsAfterAmp, CO_Boolean rhs) */

CO_Boolean CO_makeBooleanAnd(CO_Boolean lhs, CO_OptLayout wsAfterLhs, CO_OptLayout wsAfterAmp, CO_Boolean rhs)
{
  return (CO_Boolean)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun5, (ATerm)ATmakeAppl0(CO_afun12)))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun14, (ATerm)ATmakeAppl0(CO_afun15)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun20))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun14, (ATerm)ATmakeAppl0(CO_afun15)))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun5, (ATerm)ATmakeAppl0(CO_afun12)))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun5, (ATerm)ATmakeAppl0(CO_afun12))), (ATerm)ATmakeAppl1(CO_afun7, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun8, (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeAppl0(CO_afun21)))), (ATerm)ATmakeAppl1(CO_afun18, (ATerm)ATmakeAppl0(CO_afun19))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)rhs), (ATerm)wsAfterAmp), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun20))), (ATerm)wsAfterLhs), (ATerm)lhs));
}

/*}}}  */
/*{{{  CO_Boolean CO_makeBooleanNot(CO_OptLayout wsAfterNot, CO_OptLayout wsAfterParenOpen, CO_Boolean Boolean, CO_OptLayout wsAfterBoolean) */

CO_Boolean CO_makeBooleanNot(CO_OptLayout wsAfterNot, CO_OptLayout wsAfterParenOpen, CO_Boolean Boolean, CO_OptLayout wsAfterBoolean)
{
  return (CO_Boolean)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun22))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun14, (ATerm)ATmakeAppl0(CO_afun15)))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun5, (ATerm)ATmakeAppl0(CO_afun12)))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun14, (ATerm)ATmakeAppl0(CO_afun15)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun23))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun14, (ATerm)ATmakeAppl0(CO_afun15)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun24))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun5, (ATerm)ATmakeAppl0(CO_afun12))), (ATerm)ATmakeAppl1(CO_afun7, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun8, (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeAppl0(CO_afun24)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun22))), (ATerm)wsAfterBoolean), (ATerm)Boolean), (ATerm)wsAfterParenOpen), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun23))), (ATerm)wsAfterNot), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun24))));
}

/*}}}  */
/*{{{  CO_Boolean CO_makeBooleanBracket(CO_OptLayout wsAfterParenOpen, CO_Boolean Boolean, CO_OptLayout wsAfterBoolean) */

CO_Boolean CO_makeBooleanBracket(CO_OptLayout wsAfterParenOpen, CO_Boolean Boolean, CO_OptLayout wsAfterBoolean)
{
  return (CO_Boolean)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun22))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun14, (ATerm)ATmakeAppl0(CO_afun15)))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun5, (ATerm)ATmakeAppl0(CO_afun12)))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun14, (ATerm)ATmakeAppl0(CO_afun15)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun23))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun5, (ATerm)ATmakeAppl0(CO_afun12))), (ATerm)ATmakeAppl1(CO_afun7, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun8, (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeAppl0(CO_afun25)))), (ATerm)ATmakeAppl0(CO_afun26)))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun22))), (ATerm)wsAfterBoolean), (ATerm)Boolean), (ATerm)wsAfterParenOpen), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun23))));
}

/*}}}  */
/*{{{  CO_Measure CO_makeMeasureLess() */

CO_Measure CO_makeMeasureLess()
{
  return (CO_Measure)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun27))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun5, (ATerm)ATmakeAppl0(CO_afun28))), (ATerm)ATmakeAppl1(CO_afun7, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun8, (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeAppl0(CO_afun27)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun27))));
}

/*}}}  */
/*{{{  CO_Measure CO_makeMeasureGreater() */

CO_Measure CO_makeMeasureGreater()
{
  return (CO_Measure)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun29))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun5, (ATerm)ATmakeAppl0(CO_afun28))), (ATerm)ATmakeAppl1(CO_afun7, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun8, (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeAppl0(CO_afun29)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun29))));
}

/*}}}  */
/*{{{  CO_Measure CO_makeMeasureEqual() */

CO_Measure CO_makeMeasureEqual()
{
  return (CO_Measure)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun30))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun5, (ATerm)ATmakeAppl0(CO_afun28))), (ATerm)ATmakeAppl1(CO_afun7, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun8, (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeAppl0(CO_afun30)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun30))));
}

/*}}}  */
/*{{{  CO_ParseResult CO_makeParseResultTree(char* treeSort, CO_OptLayout wsAfterParseTree, CO_OptLayout wsAfterParenOpen, CO_Bytes leftLayout, CO_OptLayout wsAfterLeftLayout, CO_OptLayout wsAfterC1, ATerm tree, CO_OptLayout wsAfterTree, CO_OptLayout wsAfterC2, CO_Bytes rightLayout, CO_OptLayout wsAfterRightLayout, CO_OptLayout wsAfterC3, CO_NatCon ambCnt, CO_OptLayout wsAfterAmbCnt) */

CO_ParseResult CO_makeParseResultTree(char* treeSort, CO_OptLayout wsAfterParseTree, CO_OptLayout wsAfterParenOpen, CO_Bytes leftLayout, CO_OptLayout wsAfterLeftLayout, CO_OptLayout wsAfterC1, ATerm tree, CO_OptLayout wsAfterTree, CO_OptLayout wsAfterC2, CO_Bytes rightLayout, CO_OptLayout wsAfterRightLayout, CO_OptLayout wsAfterC3, CO_NatCon ambCnt, CO_OptLayout wsAfterAmbCnt)
{
  return (CO_ParseResult)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun22))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun14, (ATerm)ATmakeAppl0(CO_afun15)))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun5, (ATerm)ATmakeAppl0(CO_afun31)))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun14, (ATerm)ATmakeAppl0(CO_afun15)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun32))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun14, (ATerm)ATmakeAppl0(CO_afun15)))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun5, (ATerm)ATmakeAppl0(CO_afun33)))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun14, (ATerm)ATmakeAppl0(CO_afun15)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun32))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun14, (ATerm)ATmakeAppl0(CO_afun15)))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun5, (ATerm)ATmakeAppl0(ATmakeAFun(treeSort, 0, ATtrue))))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun14, (ATerm)ATmakeAppl0(CO_afun15)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun32))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun14, (ATerm)ATmakeAppl0(CO_afun15)))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun5, (ATerm)ATmakeAppl0(CO_afun33)))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun14, (ATerm)ATmakeAppl0(CO_afun15)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun23))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun14, (ATerm)ATmakeAppl0(CO_afun15)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun34))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun5, (ATerm)ATmakeAppl0(CO_afun35))), (ATerm)ATmakeAppl1(CO_afun7, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun8, (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeAppl0(CO_afun36)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun22))), (ATerm)wsAfterAmbCnt), (ATerm)ambCnt), (ATerm)wsAfterC3), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun32))), (ATerm)wsAfterRightLayout), (ATerm)rightLayout), (ATerm)wsAfterC2), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun32))), (ATerm)wsAfterTree), (ATerm)tree), (ATerm)wsAfterC1), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun32))), (ATerm)wsAfterLeftLayout), (ATerm)leftLayout), (ATerm)wsAfterParenOpen), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun23))), (ATerm)wsAfterParseTree), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun34))));
}

/*}}}  */
/*{{{  CO_ParseResult CO_makeParseResultError(CO_OptLayout wsAfterParseError, CO_OptLayout wsAfterParenOpen, CO_NatCon line, CO_OptLayout wsAfterLine, CO_OptLayout wsAfterC1, CO_NatCon column, CO_OptLayout wsAfterColumn, CO_OptLayout wsAfterC2, CO_NatCon offset, CO_OptLayout wsAfterOffset) */

CO_ParseResult CO_makeParseResultError(CO_OptLayout wsAfterParseError, CO_OptLayout wsAfterParenOpen, CO_NatCon line, CO_OptLayout wsAfterLine, CO_OptLayout wsAfterC1, CO_NatCon column, CO_OptLayout wsAfterColumn, CO_OptLayout wsAfterC2, CO_NatCon offset, CO_OptLayout wsAfterOffset)
{
  return (CO_ParseResult)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun22))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun14, (ATerm)ATmakeAppl0(CO_afun15)))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun5, (ATerm)ATmakeAppl0(CO_afun31)))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun14, (ATerm)ATmakeAppl0(CO_afun15)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun32))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun14, (ATerm)ATmakeAppl0(CO_afun15)))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun5, (ATerm)ATmakeAppl0(CO_afun31)))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun14, (ATerm)ATmakeAppl0(CO_afun15)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun32))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun14, (ATerm)ATmakeAppl0(CO_afun15)))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun5, (ATerm)ATmakeAppl0(CO_afun31)))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun14, (ATerm)ATmakeAppl0(CO_afun15)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun23))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun14, (ATerm)ATmakeAppl0(CO_afun15)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun37))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun5, (ATerm)ATmakeAppl0(CO_afun35))), (ATerm)ATmakeAppl1(CO_afun7, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun8, (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeAppl0(CO_afun38)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun22))), (ATerm)wsAfterOffset), (ATerm)offset), (ATerm)wsAfterC2), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun32))), (ATerm)wsAfterColumn), (ATerm)column), (ATerm)wsAfterC1), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun32))), (ATerm)wsAfterLine), (ATerm)line), (ATerm)wsAfterParenOpen), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun23))), (ATerm)wsAfterParseError), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun37))));
}

/*}}}  */
/*{{{  CO_ParseResult CO_makeParseResultNoParsetable() */

CO_ParseResult CO_makeParseResultNoParsetable()
{
  return (CO_ParseResult)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun39))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun5, (ATerm)ATmakeAppl0(CO_afun35))), (ATerm)ATmakeAppl1(CO_afun7, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun8, (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeAppl0(CO_afun40)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun39))));
}

/*}}}  */
/*{{{  CO_ParseResult CO_makeParseResultNoValidResult() */

CO_ParseResult CO_makeParseResultNoValidResult()
{
  return (CO_ParseResult)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun41))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun5, (ATerm)ATmakeAppl0(CO_afun35))), (ATerm)ATmakeAppl1(CO_afun7, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun8, (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeAppl0(CO_afun42)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun41))));
}

/*}}}  */
/*{{{  CO_Start CO_makeStartParseResult(CO_OptLayout wsBefore, CO_ParseResult topParseResult, CO_OptLayout wsAfter, int ambCnt) */

CO_Start CO_makeStartParseResult(CO_OptLayout wsBefore, CO_ParseResult topParseResult, CO_OptLayout wsAfter, int ambCnt)
{
  return (CO_Start)(ATerm)ATmakeAppl2(CO_afun43, (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun14, (ATerm)ATmakeAppl0(CO_afun15)))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun5, (ATerm)ATmakeAppl0(CO_afun35)))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun14, (ATerm)ATmakeAppl0(CO_afun15)))), (ATerm)ATmakeAppl1(CO_afun5, (ATerm)ATmakeAppl0(CO_afun44)), (ATerm)ATmakeAppl0(CO_afun45)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topParseResult), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  CO_Start CO_makeStartMeasure(CO_OptLayout wsBefore, CO_Measure topMeasure, CO_OptLayout wsAfter, int ambCnt) */

CO_Start CO_makeStartMeasure(CO_OptLayout wsBefore, CO_Measure topMeasure, CO_OptLayout wsAfter, int ambCnt)
{
  return (CO_Start)(ATerm)ATmakeAppl2(CO_afun43, (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun14, (ATerm)ATmakeAppl0(CO_afun15)))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun5, (ATerm)ATmakeAppl0(CO_afun28)))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun14, (ATerm)ATmakeAppl0(CO_afun15)))), (ATerm)ATmakeAppl1(CO_afun5, (ATerm)ATmakeAppl0(CO_afun44)), (ATerm)ATmakeAppl0(CO_afun45)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topMeasure), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  CO_Start CO_makeStartBoolCon(CO_OptLayout wsBefore, CO_BoolCon topBoolCon, CO_OptLayout wsAfter, int ambCnt) */

CO_Start CO_makeStartBoolCon(CO_OptLayout wsBefore, CO_BoolCon topBoolCon, CO_OptLayout wsAfter, int ambCnt)
{
  return (CO_Start)(ATerm)ATmakeAppl2(CO_afun43, (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun14, (ATerm)ATmakeAppl0(CO_afun15)))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun5, (ATerm)ATmakeAppl0(CO_afun6)))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun14, (ATerm)ATmakeAppl0(CO_afun15)))), (ATerm)ATmakeAppl1(CO_afun5, (ATerm)ATmakeAppl0(CO_afun44)), (ATerm)ATmakeAppl0(CO_afun45)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topBoolCon), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  CO_Start CO_makeStartBoolean(CO_OptLayout wsBefore, CO_Boolean topBoolean, CO_OptLayout wsAfter, int ambCnt) */

CO_Start CO_makeStartBoolean(CO_OptLayout wsBefore, CO_Boolean topBoolean, CO_OptLayout wsAfter, int ambCnt)
{
  return (CO_Start)(ATerm)ATmakeAppl2(CO_afun43, (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun14, (ATerm)ATmakeAppl0(CO_afun15)))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun5, (ATerm)ATmakeAppl0(CO_afun12)))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun14, (ATerm)ATmakeAppl0(CO_afun15)))), (ATerm)ATmakeAppl1(CO_afun5, (ATerm)ATmakeAppl0(CO_afun44)), (ATerm)ATmakeAppl0(CO_afun45)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topBoolean), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  CO_OptLayout CO_makeOptLayoutAbsent() */

CO_OptLayout CO_makeOptLayoutAbsent()
{
  return (CO_OptLayout)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATempty, (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun14, (ATerm)ATmakeAppl0(CO_afun15))), (ATerm)ATmakeAppl0(CO_afun45)), (ATerm)ATempty);
}

/*}}}  */
/*{{{  CO_OptLayout CO_makeOptLayoutPresent(CO_CHARLIST chars) */

CO_OptLayout CO_makeOptLayoutPresent(CO_CHARLIST chars)
{
  return (CO_OptLayout)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl0(CO_afun15))), (ATerm)ATmakeAppl1(CO_afun4, (ATerm)ATmakeAppl1(CO_afun14, (ATerm)ATmakeAppl0(CO_afun15))), (ATerm)ATmakeAppl0(CO_afun45)), (ATerm)chars);
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool CO_isEqualBoolCon(CO_BoolCon arg0, CO_BoolCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CO_isEqualBoolean(CO_Boolean arg0, CO_Boolean arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CO_isEqualMeasure(CO_Measure arg0, CO_Measure arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CO_isEqualParseResult(CO_ParseResult arg0, CO_ParseResult arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CO_isEqualStart(CO_Start arg0, CO_Start arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CO_isEqualOptLayout(CO_OptLayout arg0, CO_OptLayout arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  CO_BoolCon accessors */

/*{{{  ATbool CO_isValidBoolCon(CO_BoolCon arg) */

ATbool CO_isValidBoolCon(CO_BoolCon arg)
{
  if (CO_isBoolConTrue(arg)) {
    return ATtrue;
  }
  else if (CO_isBoolConFalse(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CO_isBoolConTrue(CO_BoolCon arg) */

inline ATbool CO_isBoolConTrue(CO_BoolCon arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternBoolConTrue);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isBoolConFalse(CO_BoolCon arg) */

inline ATbool CO_isBoolConFalse(CO_BoolCon arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternBoolConFalse);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */

/*}}}  */
/*{{{  CO_Boolean accessors */

/*{{{  ATbool CO_isValidBoolean(CO_Boolean arg) */

ATbool CO_isValidBoolean(CO_Boolean arg)
{
  if (CO_isBooleanConstant(arg)) {
    return ATtrue;
  }
  else if (CO_isBooleanOr(arg)) {
    return ATtrue;
  }
  else if (CO_isBooleanAnd(arg)) {
    return ATtrue;
  }
  else if (CO_isBooleanNot(arg)) {
    return ATtrue;
  }
  else if (CO_isBooleanBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CO_isBooleanConstant(CO_Boolean arg) */

inline ATbool CO_isBooleanConstant(CO_Boolean arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternBooleanConstant, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isBooleanOr(CO_Boolean arg) */

inline ATbool CO_isBooleanOr(CO_Boolean arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternBooleanOr, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isBooleanAnd(CO_Boolean arg) */

inline ATbool CO_isBooleanAnd(CO_Boolean arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternBooleanAnd, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isBooleanNot(CO_Boolean arg) */

inline ATbool CO_isBooleanNot(CO_Boolean arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternBooleanNot, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isBooleanBracket(CO_Boolean arg) */

inline ATbool CO_isBooleanBracket(CO_Boolean arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternBooleanBracket, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool CO_hasBooleanBoolCon(CO_Boolean arg) */

ATbool CO_hasBooleanBoolCon(CO_Boolean arg)
{
  if (CO_isBooleanConstant(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_BoolCon CO_getBooleanBoolCon(CO_Boolean arg) */

CO_BoolCon CO_getBooleanBoolCon(CO_Boolean arg)
{
  
    return (CO_BoolCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  CO_Boolean CO_setBooleanBoolCon(CO_Boolean arg, CO_BoolCon BoolCon) */

CO_Boolean CO_setBooleanBoolCon(CO_Boolean arg, CO_BoolCon BoolCon)
{
  if (CO_isBooleanConstant(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)BoolCon, 0), 1);
  }

  ATabort("Boolean has no BoolCon: %t\n", arg);
  return (CO_Boolean)NULL;
}

/*}}}  */
/*{{{  ATbool CO_hasBooleanLhs(CO_Boolean arg) */

ATbool CO_hasBooleanLhs(CO_Boolean arg)
{
  if (CO_isBooleanOr(arg)) {
    return ATtrue;
  }
  else if (CO_isBooleanAnd(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_Boolean CO_getBooleanLhs(CO_Boolean arg) */

CO_Boolean CO_getBooleanLhs(CO_Boolean arg)
{
  if (CO_isBooleanOr(arg)) {
    return (CO_Boolean)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (CO_Boolean)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  CO_Boolean CO_setBooleanLhs(CO_Boolean arg, CO_Boolean lhs) */

CO_Boolean CO_setBooleanLhs(CO_Boolean arg, CO_Boolean lhs)
{
  if (CO_isBooleanOr(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)lhs, 0), 1);
  }
  else if (CO_isBooleanAnd(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)lhs, 0), 1);
  }

  ATabort("Boolean has no Lhs: %t\n", arg);
  return (CO_Boolean)NULL;
}

/*}}}  */
/*{{{  ATbool CO_hasBooleanWsAfterLhs(CO_Boolean arg) */

ATbool CO_hasBooleanWsAfterLhs(CO_Boolean arg)
{
  if (CO_isBooleanOr(arg)) {
    return ATtrue;
  }
  else if (CO_isBooleanAnd(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_OptLayout CO_getBooleanWsAfterLhs(CO_Boolean arg) */

CO_OptLayout CO_getBooleanWsAfterLhs(CO_Boolean arg)
{
  if (CO_isBooleanOr(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  CO_Boolean CO_setBooleanWsAfterLhs(CO_Boolean arg, CO_OptLayout wsAfterLhs) */

CO_Boolean CO_setBooleanWsAfterLhs(CO_Boolean arg, CO_OptLayout wsAfterLhs)
{
  if (CO_isBooleanOr(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLhs, 1), 1);
  }
  else if (CO_isBooleanAnd(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLhs, 1), 1);
  }

  ATabort("Boolean has no WsAfterLhs: %t\n", arg);
  return (CO_Boolean)NULL;
}

/*}}}  */
/*{{{  ATbool CO_hasBooleanWsAfterBar(CO_Boolean arg) */

ATbool CO_hasBooleanWsAfterBar(CO_Boolean arg)
{
  if (CO_isBooleanOr(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_OptLayout CO_getBooleanWsAfterBar(CO_Boolean arg) */

CO_OptLayout CO_getBooleanWsAfterBar(CO_Boolean arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  CO_Boolean CO_setBooleanWsAfterBar(CO_Boolean arg, CO_OptLayout wsAfterBar) */

CO_Boolean CO_setBooleanWsAfterBar(CO_Boolean arg, CO_OptLayout wsAfterBar)
{
  if (CO_isBooleanOr(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterBar, 3), 1);
  }

  ATabort("Boolean has no WsAfterBar: %t\n", arg);
  return (CO_Boolean)NULL;
}

/*}}}  */
/*{{{  ATbool CO_hasBooleanRhs(CO_Boolean arg) */

ATbool CO_hasBooleanRhs(CO_Boolean arg)
{
  if (CO_isBooleanOr(arg)) {
    return ATtrue;
  }
  else if (CO_isBooleanAnd(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_Boolean CO_getBooleanRhs(CO_Boolean arg) */

CO_Boolean CO_getBooleanRhs(CO_Boolean arg)
{
  if (CO_isBooleanOr(arg)) {
    return (CO_Boolean)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (CO_Boolean)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  CO_Boolean CO_setBooleanRhs(CO_Boolean arg, CO_Boolean rhs) */

CO_Boolean CO_setBooleanRhs(CO_Boolean arg, CO_Boolean rhs)
{
  if (CO_isBooleanOr(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)rhs, 4), 1);
  }
  else if (CO_isBooleanAnd(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)rhs, 4), 1);
  }

  ATabort("Boolean has no Rhs: %t\n", arg);
  return (CO_Boolean)NULL;
}

/*}}}  */
/*{{{  ATbool CO_hasBooleanWsAfterAmp(CO_Boolean arg) */

ATbool CO_hasBooleanWsAfterAmp(CO_Boolean arg)
{
  if (CO_isBooleanAnd(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_OptLayout CO_getBooleanWsAfterAmp(CO_Boolean arg) */

CO_OptLayout CO_getBooleanWsAfterAmp(CO_Boolean arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  CO_Boolean CO_setBooleanWsAfterAmp(CO_Boolean arg, CO_OptLayout wsAfterAmp) */

CO_Boolean CO_setBooleanWsAfterAmp(CO_Boolean arg, CO_OptLayout wsAfterAmp)
{
  if (CO_isBooleanAnd(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterAmp, 3), 1);
  }

  ATabort("Boolean has no WsAfterAmp: %t\n", arg);
  return (CO_Boolean)NULL;
}

/*}}}  */
/*{{{  ATbool CO_hasBooleanWsAfterNot(CO_Boolean arg) */

ATbool CO_hasBooleanWsAfterNot(CO_Boolean arg)
{
  if (CO_isBooleanNot(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_OptLayout CO_getBooleanWsAfterNot(CO_Boolean arg) */

CO_OptLayout CO_getBooleanWsAfterNot(CO_Boolean arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  CO_Boolean CO_setBooleanWsAfterNot(CO_Boolean arg, CO_OptLayout wsAfterNot) */

CO_Boolean CO_setBooleanWsAfterNot(CO_Boolean arg, CO_OptLayout wsAfterNot)
{
  if (CO_isBooleanNot(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterNot, 1), 1);
  }

  ATabort("Boolean has no WsAfterNot: %t\n", arg);
  return (CO_Boolean)NULL;
}

/*}}}  */
/*{{{  ATbool CO_hasBooleanWsAfterParenOpen(CO_Boolean arg) */

ATbool CO_hasBooleanWsAfterParenOpen(CO_Boolean arg)
{
  if (CO_isBooleanNot(arg)) {
    return ATtrue;
  }
  else if (CO_isBooleanBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_OptLayout CO_getBooleanWsAfterParenOpen(CO_Boolean arg) */

CO_OptLayout CO_getBooleanWsAfterParenOpen(CO_Boolean arg)
{
  if (CO_isBooleanNot(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  CO_Boolean CO_setBooleanWsAfterParenOpen(CO_Boolean arg, CO_OptLayout wsAfterParenOpen) */

CO_Boolean CO_setBooleanWsAfterParenOpen(CO_Boolean arg, CO_OptLayout wsAfterParenOpen)
{
  if (CO_isBooleanNot(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenOpen, 3), 1);
  }
  else if (CO_isBooleanBracket(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenOpen, 1), 1);
  }

  ATabort("Boolean has no WsAfterParenOpen: %t\n", arg);
  return (CO_Boolean)NULL;
}

/*}}}  */
/*{{{  ATbool CO_hasBooleanBoolean(CO_Boolean arg) */

ATbool CO_hasBooleanBoolean(CO_Boolean arg)
{
  if (CO_isBooleanNot(arg)) {
    return ATtrue;
  }
  else if (CO_isBooleanBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_Boolean CO_getBooleanBoolean(CO_Boolean arg) */

CO_Boolean CO_getBooleanBoolean(CO_Boolean arg)
{
  if (CO_isBooleanNot(arg)) {
    return (CO_Boolean)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (CO_Boolean)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  CO_Boolean CO_setBooleanBoolean(CO_Boolean arg, CO_Boolean Boolean) */

CO_Boolean CO_setBooleanBoolean(CO_Boolean arg, CO_Boolean Boolean)
{
  if (CO_isBooleanNot(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Boolean, 4), 1);
  }
  else if (CO_isBooleanBracket(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Boolean, 2), 1);
  }

  ATabort("Boolean has no Boolean: %t\n", arg);
  return (CO_Boolean)NULL;
}

/*}}}  */
/*{{{  ATbool CO_hasBooleanWsAfterBoolean(CO_Boolean arg) */

ATbool CO_hasBooleanWsAfterBoolean(CO_Boolean arg)
{
  if (CO_isBooleanNot(arg)) {
    return ATtrue;
  }
  else if (CO_isBooleanBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_OptLayout CO_getBooleanWsAfterBoolean(CO_Boolean arg) */

CO_OptLayout CO_getBooleanWsAfterBoolean(CO_Boolean arg)
{
  if (CO_isBooleanNot(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  CO_Boolean CO_setBooleanWsAfterBoolean(CO_Boolean arg, CO_OptLayout wsAfterBoolean) */

CO_Boolean CO_setBooleanWsAfterBoolean(CO_Boolean arg, CO_OptLayout wsAfterBoolean)
{
  if (CO_isBooleanNot(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterBoolean, 5), 1);
  }
  else if (CO_isBooleanBracket(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterBoolean, 3), 1);
  }

  ATabort("Boolean has no WsAfterBoolean: %t\n", arg);
  return (CO_Boolean)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CO_Measure accessors */

/*{{{  ATbool CO_isValidMeasure(CO_Measure arg) */

ATbool CO_isValidMeasure(CO_Measure arg)
{
  if (CO_isMeasureLess(arg)) {
    return ATtrue;
  }
  else if (CO_isMeasureGreater(arg)) {
    return ATtrue;
  }
  else if (CO_isMeasureEqual(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CO_isMeasureLess(CO_Measure arg) */

inline ATbool CO_isMeasureLess(CO_Measure arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternMeasureLess);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isMeasureGreater(CO_Measure arg) */

inline ATbool CO_isMeasureGreater(CO_Measure arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternMeasureGreater);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isMeasureEqual(CO_Measure arg) */

inline ATbool CO_isMeasureEqual(CO_Measure arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternMeasureEqual);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */

/*}}}  */
/*{{{  CO_ParseResult accessors */

/*{{{  ATbool CO_isValidParseResult(CO_ParseResult arg) */

ATbool CO_isValidParseResult(CO_ParseResult arg)
{
  if (CO_isParseResultTree(arg)) {
    return ATtrue;
  }
  else if (CO_isParseResultError(arg)) {
    return ATtrue;
  }
  else if (CO_isParseResultNoParsetable(arg)) {
    return ATtrue;
  }
  else if (CO_isParseResultNoValidResult(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CO_isParseResultTree(CO_ParseResult arg) */

inline ATbool CO_isParseResultTree(CO_ParseResult arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternParseResultTree, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isParseResultError(CO_ParseResult arg) */

inline ATbool CO_isParseResultError(CO_ParseResult arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternParseResultError, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isParseResultNoParsetable(CO_ParseResult arg) */

inline ATbool CO_isParseResultNoParsetable(CO_ParseResult arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternParseResultNoParsetable);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isParseResultNoValidResult(CO_ParseResult arg) */

inline ATbool CO_isParseResultNoValidResult(CO_ParseResult arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternParseResultNoValidResult);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool CO_hasParseResultTreeSort(CO_ParseResult arg) */

ATbool CO_hasParseResultTreeSort(CO_ParseResult arg)
{
  if (CO_isParseResultTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* CO_getParseResultTreeSort(CO_ParseResult arg) */

char* CO_getParseResultTreeSort(CO_ParseResult arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), 8), 0), 0)));
}

/*}}}  */
/*{{{  CO_ParseResult CO_setParseResultTreeSort(CO_ParseResult arg, char* treeSort) */

CO_ParseResult CO_setParseResultTreeSort(CO_ParseResult arg, char* treeSort)
{
  if (CO_isParseResultTree(arg)) {
    return (CO_ParseResult)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), 8), (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), 8), 0), (ATerm)ATmakeAppl0(ATmakeAFun(treeSort, 0, ATtrue)), 0), 0), 8), 0), 0);
  }

  ATabort("ParseResult has no TreeSort: %t\n", arg);
  return (CO_ParseResult)NULL;
}

/*}}}  */
/*{{{  ATbool CO_hasParseResultWsAfterParseTree(CO_ParseResult arg) */

ATbool CO_hasParseResultWsAfterParseTree(CO_ParseResult arg)
{
  if (CO_isParseResultTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_OptLayout CO_getParseResultWsAfterParseTree(CO_ParseResult arg) */

CO_OptLayout CO_getParseResultWsAfterParseTree(CO_ParseResult arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  CO_ParseResult CO_setParseResultWsAfterParseTree(CO_ParseResult arg, CO_OptLayout wsAfterParseTree) */

CO_ParseResult CO_setParseResultWsAfterParseTree(CO_ParseResult arg, CO_OptLayout wsAfterParseTree)
{
  if (CO_isParseResultTree(arg)) {
    return (CO_ParseResult)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParseTree, 1), 1);
  }

  ATabort("ParseResult has no WsAfterParseTree: %t\n", arg);
  return (CO_ParseResult)NULL;
}

/*}}}  */
/*{{{  ATbool CO_hasParseResultWsAfterParenOpen(CO_ParseResult arg) */

ATbool CO_hasParseResultWsAfterParenOpen(CO_ParseResult arg)
{
  if (CO_isParseResultTree(arg)) {
    return ATtrue;
  }
  else if (CO_isParseResultError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_OptLayout CO_getParseResultWsAfterParenOpen(CO_ParseResult arg) */

CO_OptLayout CO_getParseResultWsAfterParenOpen(CO_ParseResult arg)
{
  if (CO_isParseResultTree(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  CO_ParseResult CO_setParseResultWsAfterParenOpen(CO_ParseResult arg, CO_OptLayout wsAfterParenOpen) */

CO_ParseResult CO_setParseResultWsAfterParenOpen(CO_ParseResult arg, CO_OptLayout wsAfterParenOpen)
{
  if (CO_isParseResultTree(arg)) {
    return (CO_ParseResult)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenOpen, 3), 1);
  }
  else if (CO_isParseResultError(arg)) {
    return (CO_ParseResult)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenOpen, 3), 1);
  }

  ATabort("ParseResult has no WsAfterParenOpen: %t\n", arg);
  return (CO_ParseResult)NULL;
}

/*}}}  */
/*{{{  ATbool CO_hasParseResultLeftLayout(CO_ParseResult arg) */

ATbool CO_hasParseResultLeftLayout(CO_ParseResult arg)
{
  if (CO_isParseResultTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_Bytes CO_getParseResultLeftLayout(CO_ParseResult arg) */

CO_Bytes CO_getParseResultLeftLayout(CO_ParseResult arg)
{
  
    return (CO_Bytes)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  CO_ParseResult CO_setParseResultLeftLayout(CO_ParseResult arg, CO_Bytes leftLayout) */

CO_ParseResult CO_setParseResultLeftLayout(CO_ParseResult arg, CO_Bytes leftLayout)
{
  if (CO_isParseResultTree(arg)) {
    return (CO_ParseResult)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)leftLayout, 4), 1);
  }

  ATabort("ParseResult has no LeftLayout: %t\n", arg);
  return (CO_ParseResult)NULL;
}

/*}}}  */
/*{{{  ATbool CO_hasParseResultWsAfterLeftLayout(CO_ParseResult arg) */

ATbool CO_hasParseResultWsAfterLeftLayout(CO_ParseResult arg)
{
  if (CO_isParseResultTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_OptLayout CO_getParseResultWsAfterLeftLayout(CO_ParseResult arg) */

CO_OptLayout CO_getParseResultWsAfterLeftLayout(CO_ParseResult arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  CO_ParseResult CO_setParseResultWsAfterLeftLayout(CO_ParseResult arg, CO_OptLayout wsAfterLeftLayout) */

CO_ParseResult CO_setParseResultWsAfterLeftLayout(CO_ParseResult arg, CO_OptLayout wsAfterLeftLayout)
{
  if (CO_isParseResultTree(arg)) {
    return (CO_ParseResult)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLeftLayout, 5), 1);
  }

  ATabort("ParseResult has no WsAfterLeftLayout: %t\n", arg);
  return (CO_ParseResult)NULL;
}

/*}}}  */
/*{{{  ATbool CO_hasParseResultWsAfterC1(CO_ParseResult arg) */

ATbool CO_hasParseResultWsAfterC1(CO_ParseResult arg)
{
  if (CO_isParseResultTree(arg)) {
    return ATtrue;
  }
  else if (CO_isParseResultError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_OptLayout CO_getParseResultWsAfterC1(CO_ParseResult arg) */

CO_OptLayout CO_getParseResultWsAfterC1(CO_ParseResult arg)
{
  if (CO_isParseResultTree(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  CO_ParseResult CO_setParseResultWsAfterC1(CO_ParseResult arg, CO_OptLayout wsAfterC1) */

CO_ParseResult CO_setParseResultWsAfterC1(CO_ParseResult arg, CO_OptLayout wsAfterC1)
{
  if (CO_isParseResultTree(arg)) {
    return (CO_ParseResult)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterC1, 7), 1);
  }
  else if (CO_isParseResultError(arg)) {
    return (CO_ParseResult)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterC1, 7), 1);
  }

  ATabort("ParseResult has no WsAfterC1: %t\n", arg);
  return (CO_ParseResult)NULL;
}

/*}}}  */
/*{{{  ATbool CO_hasParseResultTree(CO_ParseResult arg) */

ATbool CO_hasParseResultTree(CO_ParseResult arg)
{
  if (CO_isParseResultTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATerm CO_getParseResultTree(CO_ParseResult arg) */

ATerm CO_getParseResultTree(CO_ParseResult arg)
{
  
    return (ATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/*}}}  */
/*{{{  CO_ParseResult CO_setParseResultTree(CO_ParseResult arg, ATerm tree) */

CO_ParseResult CO_setParseResultTree(CO_ParseResult arg, ATerm tree)
{
  if (CO_isParseResultTree(arg)) {
    return (CO_ParseResult)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)tree, 8), 1);
  }

  ATabort("ParseResult has no Tree: %t\n", arg);
  return (CO_ParseResult)NULL;
}

/*}}}  */
/*{{{  ATbool CO_hasParseResultWsAfterTree(CO_ParseResult arg) */

ATbool CO_hasParseResultWsAfterTree(CO_ParseResult arg)
{
  if (CO_isParseResultTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_OptLayout CO_getParseResultWsAfterTree(CO_ParseResult arg) */

CO_OptLayout CO_getParseResultWsAfterTree(CO_ParseResult arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/*}}}  */
/*{{{  CO_ParseResult CO_setParseResultWsAfterTree(CO_ParseResult arg, CO_OptLayout wsAfterTree) */

CO_ParseResult CO_setParseResultWsAfterTree(CO_ParseResult arg, CO_OptLayout wsAfterTree)
{
  if (CO_isParseResultTree(arg)) {
    return (CO_ParseResult)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterTree, 9), 1);
  }

  ATabort("ParseResult has no WsAfterTree: %t\n", arg);
  return (CO_ParseResult)NULL;
}

/*}}}  */
/*{{{  ATbool CO_hasParseResultWsAfterC2(CO_ParseResult arg) */

ATbool CO_hasParseResultWsAfterC2(CO_ParseResult arg)
{
  if (CO_isParseResultTree(arg)) {
    return ATtrue;
  }
  else if (CO_isParseResultError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_OptLayout CO_getParseResultWsAfterC2(CO_ParseResult arg) */

CO_OptLayout CO_getParseResultWsAfterC2(CO_ParseResult arg)
{
  if (CO_isParseResultTree(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 11);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 11);
}

/*}}}  */
/*{{{  CO_ParseResult CO_setParseResultWsAfterC2(CO_ParseResult arg, CO_OptLayout wsAfterC2) */

CO_ParseResult CO_setParseResultWsAfterC2(CO_ParseResult arg, CO_OptLayout wsAfterC2)
{
  if (CO_isParseResultTree(arg)) {
    return (CO_ParseResult)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterC2, 11), 1);
  }
  else if (CO_isParseResultError(arg)) {
    return (CO_ParseResult)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterC2, 11), 1);
  }

  ATabort("ParseResult has no WsAfterC2: %t\n", arg);
  return (CO_ParseResult)NULL;
}

/*}}}  */
/*{{{  ATbool CO_hasParseResultRightLayout(CO_ParseResult arg) */

ATbool CO_hasParseResultRightLayout(CO_ParseResult arg)
{
  if (CO_isParseResultTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_Bytes CO_getParseResultRightLayout(CO_ParseResult arg) */

CO_Bytes CO_getParseResultRightLayout(CO_ParseResult arg)
{
  
    return (CO_Bytes)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 12);
}

/*}}}  */
/*{{{  CO_ParseResult CO_setParseResultRightLayout(CO_ParseResult arg, CO_Bytes rightLayout) */

CO_ParseResult CO_setParseResultRightLayout(CO_ParseResult arg, CO_Bytes rightLayout)
{
  if (CO_isParseResultTree(arg)) {
    return (CO_ParseResult)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)rightLayout, 12), 1);
  }

  ATabort("ParseResult has no RightLayout: %t\n", arg);
  return (CO_ParseResult)NULL;
}

/*}}}  */
/*{{{  ATbool CO_hasParseResultWsAfterRightLayout(CO_ParseResult arg) */

ATbool CO_hasParseResultWsAfterRightLayout(CO_ParseResult arg)
{
  if (CO_isParseResultTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_OptLayout CO_getParseResultWsAfterRightLayout(CO_ParseResult arg) */

CO_OptLayout CO_getParseResultWsAfterRightLayout(CO_ParseResult arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 13);
}

/*}}}  */
/*{{{  CO_ParseResult CO_setParseResultWsAfterRightLayout(CO_ParseResult arg, CO_OptLayout wsAfterRightLayout) */

CO_ParseResult CO_setParseResultWsAfterRightLayout(CO_ParseResult arg, CO_OptLayout wsAfterRightLayout)
{
  if (CO_isParseResultTree(arg)) {
    return (CO_ParseResult)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterRightLayout, 13), 1);
  }

  ATabort("ParseResult has no WsAfterRightLayout: %t\n", arg);
  return (CO_ParseResult)NULL;
}

/*}}}  */
/*{{{  ATbool CO_hasParseResultWsAfterC3(CO_ParseResult arg) */

ATbool CO_hasParseResultWsAfterC3(CO_ParseResult arg)
{
  if (CO_isParseResultTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_OptLayout CO_getParseResultWsAfterC3(CO_ParseResult arg) */

CO_OptLayout CO_getParseResultWsAfterC3(CO_ParseResult arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 15);
}

/*}}}  */
/*{{{  CO_ParseResult CO_setParseResultWsAfterC3(CO_ParseResult arg, CO_OptLayout wsAfterC3) */

CO_ParseResult CO_setParseResultWsAfterC3(CO_ParseResult arg, CO_OptLayout wsAfterC3)
{
  if (CO_isParseResultTree(arg)) {
    return (CO_ParseResult)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterC3, 15), 1);
  }

  ATabort("ParseResult has no WsAfterC3: %t\n", arg);
  return (CO_ParseResult)NULL;
}

/*}}}  */
/*{{{  ATbool CO_hasParseResultAmbCnt(CO_ParseResult arg) */

ATbool CO_hasParseResultAmbCnt(CO_ParseResult arg)
{
  if (CO_isParseResultTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_NatCon CO_getParseResultAmbCnt(CO_ParseResult arg) */

CO_NatCon CO_getParseResultAmbCnt(CO_ParseResult arg)
{
  
    return (CO_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 16);
}

/*}}}  */
/*{{{  CO_ParseResult CO_setParseResultAmbCnt(CO_ParseResult arg, CO_NatCon ambCnt) */

CO_ParseResult CO_setParseResultAmbCnt(CO_ParseResult arg, CO_NatCon ambCnt)
{
  if (CO_isParseResultTree(arg)) {
    return (CO_ParseResult)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ambCnt, 16), 1);
  }

  ATabort("ParseResult has no AmbCnt: %t\n", arg);
  return (CO_ParseResult)NULL;
}

/*}}}  */
/*{{{  ATbool CO_hasParseResultWsAfterAmbCnt(CO_ParseResult arg) */

ATbool CO_hasParseResultWsAfterAmbCnt(CO_ParseResult arg)
{
  if (CO_isParseResultTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_OptLayout CO_getParseResultWsAfterAmbCnt(CO_ParseResult arg) */

CO_OptLayout CO_getParseResultWsAfterAmbCnt(CO_ParseResult arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 17);
}

/*}}}  */
/*{{{  CO_ParseResult CO_setParseResultWsAfterAmbCnt(CO_ParseResult arg, CO_OptLayout wsAfterAmbCnt) */

CO_ParseResult CO_setParseResultWsAfterAmbCnt(CO_ParseResult arg, CO_OptLayout wsAfterAmbCnt)
{
  if (CO_isParseResultTree(arg)) {
    return (CO_ParseResult)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterAmbCnt, 17), 1);
  }

  ATabort("ParseResult has no WsAfterAmbCnt: %t\n", arg);
  return (CO_ParseResult)NULL;
}

/*}}}  */
/*{{{  ATbool CO_hasParseResultWsAfterParseError(CO_ParseResult arg) */

ATbool CO_hasParseResultWsAfterParseError(CO_ParseResult arg)
{
  if (CO_isParseResultError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_OptLayout CO_getParseResultWsAfterParseError(CO_ParseResult arg) */

CO_OptLayout CO_getParseResultWsAfterParseError(CO_ParseResult arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  CO_ParseResult CO_setParseResultWsAfterParseError(CO_ParseResult arg, CO_OptLayout wsAfterParseError) */

CO_ParseResult CO_setParseResultWsAfterParseError(CO_ParseResult arg, CO_OptLayout wsAfterParseError)
{
  if (CO_isParseResultError(arg)) {
    return (CO_ParseResult)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParseError, 1), 1);
  }

  ATabort("ParseResult has no WsAfterParseError: %t\n", arg);
  return (CO_ParseResult)NULL;
}

/*}}}  */
/*{{{  ATbool CO_hasParseResultLine(CO_ParseResult arg) */

ATbool CO_hasParseResultLine(CO_ParseResult arg)
{
  if (CO_isParseResultError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_NatCon CO_getParseResultLine(CO_ParseResult arg) */

CO_NatCon CO_getParseResultLine(CO_ParseResult arg)
{
  
    return (CO_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  CO_ParseResult CO_setParseResultLine(CO_ParseResult arg, CO_NatCon line) */

CO_ParseResult CO_setParseResultLine(CO_ParseResult arg, CO_NatCon line)
{
  if (CO_isParseResultError(arg)) {
    return (CO_ParseResult)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)line, 4), 1);
  }

  ATabort("ParseResult has no Line: %t\n", arg);
  return (CO_ParseResult)NULL;
}

/*}}}  */
/*{{{  ATbool CO_hasParseResultWsAfterLine(CO_ParseResult arg) */

ATbool CO_hasParseResultWsAfterLine(CO_ParseResult arg)
{
  if (CO_isParseResultError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_OptLayout CO_getParseResultWsAfterLine(CO_ParseResult arg) */

CO_OptLayout CO_getParseResultWsAfterLine(CO_ParseResult arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  CO_ParseResult CO_setParseResultWsAfterLine(CO_ParseResult arg, CO_OptLayout wsAfterLine) */

CO_ParseResult CO_setParseResultWsAfterLine(CO_ParseResult arg, CO_OptLayout wsAfterLine)
{
  if (CO_isParseResultError(arg)) {
    return (CO_ParseResult)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLine, 5), 1);
  }

  ATabort("ParseResult has no WsAfterLine: %t\n", arg);
  return (CO_ParseResult)NULL;
}

/*}}}  */
/*{{{  ATbool CO_hasParseResultColumn(CO_ParseResult arg) */

ATbool CO_hasParseResultColumn(CO_ParseResult arg)
{
  if (CO_isParseResultError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_NatCon CO_getParseResultColumn(CO_ParseResult arg) */

CO_NatCon CO_getParseResultColumn(CO_ParseResult arg)
{
  
    return (CO_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/*}}}  */
/*{{{  CO_ParseResult CO_setParseResultColumn(CO_ParseResult arg, CO_NatCon column) */

CO_ParseResult CO_setParseResultColumn(CO_ParseResult arg, CO_NatCon column)
{
  if (CO_isParseResultError(arg)) {
    return (CO_ParseResult)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)column, 8), 1);
  }

  ATabort("ParseResult has no Column: %t\n", arg);
  return (CO_ParseResult)NULL;
}

/*}}}  */
/*{{{  ATbool CO_hasParseResultWsAfterColumn(CO_ParseResult arg) */

ATbool CO_hasParseResultWsAfterColumn(CO_ParseResult arg)
{
  if (CO_isParseResultError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_OptLayout CO_getParseResultWsAfterColumn(CO_ParseResult arg) */

CO_OptLayout CO_getParseResultWsAfterColumn(CO_ParseResult arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/*}}}  */
/*{{{  CO_ParseResult CO_setParseResultWsAfterColumn(CO_ParseResult arg, CO_OptLayout wsAfterColumn) */

CO_ParseResult CO_setParseResultWsAfterColumn(CO_ParseResult arg, CO_OptLayout wsAfterColumn)
{
  if (CO_isParseResultError(arg)) {
    return (CO_ParseResult)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterColumn, 9), 1);
  }

  ATabort("ParseResult has no WsAfterColumn: %t\n", arg);
  return (CO_ParseResult)NULL;
}

/*}}}  */
/*{{{  ATbool CO_hasParseResultOffset(CO_ParseResult arg) */

ATbool CO_hasParseResultOffset(CO_ParseResult arg)
{
  if (CO_isParseResultError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_NatCon CO_getParseResultOffset(CO_ParseResult arg) */

CO_NatCon CO_getParseResultOffset(CO_ParseResult arg)
{
  
    return (CO_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 12);
}

/*}}}  */
/*{{{  CO_ParseResult CO_setParseResultOffset(CO_ParseResult arg, CO_NatCon offset) */

CO_ParseResult CO_setParseResultOffset(CO_ParseResult arg, CO_NatCon offset)
{
  if (CO_isParseResultError(arg)) {
    return (CO_ParseResult)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)offset, 12), 1);
  }

  ATabort("ParseResult has no Offset: %t\n", arg);
  return (CO_ParseResult)NULL;
}

/*}}}  */
/*{{{  ATbool CO_hasParseResultWsAfterOffset(CO_ParseResult arg) */

ATbool CO_hasParseResultWsAfterOffset(CO_ParseResult arg)
{
  if (CO_isParseResultError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_OptLayout CO_getParseResultWsAfterOffset(CO_ParseResult arg) */

CO_OptLayout CO_getParseResultWsAfterOffset(CO_ParseResult arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 13);
}

/*}}}  */
/*{{{  CO_ParseResult CO_setParseResultWsAfterOffset(CO_ParseResult arg, CO_OptLayout wsAfterOffset) */

CO_ParseResult CO_setParseResultWsAfterOffset(CO_ParseResult arg, CO_OptLayout wsAfterOffset)
{
  if (CO_isParseResultError(arg)) {
    return (CO_ParseResult)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterOffset, 13), 1);
  }

  ATabort("ParseResult has no WsAfterOffset: %t\n", arg);
  return (CO_ParseResult)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CO_Start accessors */

/*{{{  ATbool CO_isValidStart(CO_Start arg) */

ATbool CO_isValidStart(CO_Start arg)
{
  if (CO_isStartParseResult(arg)) {
    return ATtrue;
  }
  else if (CO_isStartMeasure(arg)) {
    return ATtrue;
  }
  else if (CO_isStartBoolCon(arg)) {
    return ATtrue;
  }
  else if (CO_isStartBoolean(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CO_isStartParseResult(CO_Start arg) */

inline ATbool CO_isStartParseResult(CO_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternStartParseResult, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isStartMeasure(CO_Start arg) */

inline ATbool CO_isStartMeasure(CO_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternStartMeasure, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isStartBoolCon(CO_Start arg) */

inline ATbool CO_isStartBoolCon(CO_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternStartBoolCon, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isStartBoolean(CO_Start arg) */

inline ATbool CO_isStartBoolean(CO_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternStartBoolean, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool CO_hasStartWsBefore(CO_Start arg) */

ATbool CO_hasStartWsBefore(CO_Start arg)
{
  if (CO_isStartParseResult(arg)) {
    return ATtrue;
  }
  else if (CO_isStartMeasure(arg)) {
    return ATtrue;
  }
  else if (CO_isStartBoolCon(arg)) {
    return ATtrue;
  }
  else if (CO_isStartBoolean(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_OptLayout CO_getStartWsBefore(CO_Start arg) */

CO_OptLayout CO_getStartWsBefore(CO_Start arg)
{
  if (CO_isStartParseResult(arg)) {
    return (CO_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (CO_isStartMeasure(arg)) {
    return (CO_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (CO_isStartBoolCon(arg)) {
    return (CO_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else 
    return (CO_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
}

/*}}}  */
/*{{{  CO_Start CO_setStartWsBefore(CO_Start arg, CO_OptLayout wsBefore) */

CO_Start CO_setStartWsBefore(CO_Start arg, CO_OptLayout wsBefore)
{
  if (CO_isStartParseResult(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (CO_isStartMeasure(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (CO_isStartBoolCon(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (CO_isStartBoolean(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }

  ATabort("Start has no WsBefore: %t\n", arg);
  return (CO_Start)NULL;
}

/*}}}  */
/*{{{  ATbool CO_hasStartTopParseResult(CO_Start arg) */

ATbool CO_hasStartTopParseResult(CO_Start arg)
{
  if (CO_isStartParseResult(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_ParseResult CO_getStartTopParseResult(CO_Start arg) */

CO_ParseResult CO_getStartTopParseResult(CO_Start arg)
{
  
    return (CO_ParseResult)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  CO_Start CO_setStartTopParseResult(CO_Start arg, CO_ParseResult topParseResult) */

CO_Start CO_setStartTopParseResult(CO_Start arg, CO_ParseResult topParseResult)
{
  if (CO_isStartParseResult(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topParseResult, 1), 1), 0);
  }

  ATabort("Start has no TopParseResult: %t\n", arg);
  return (CO_Start)NULL;
}

/*}}}  */
/*{{{  ATbool CO_hasStartWsAfter(CO_Start arg) */

ATbool CO_hasStartWsAfter(CO_Start arg)
{
  if (CO_isStartParseResult(arg)) {
    return ATtrue;
  }
  else if (CO_isStartMeasure(arg)) {
    return ATtrue;
  }
  else if (CO_isStartBoolCon(arg)) {
    return ATtrue;
  }
  else if (CO_isStartBoolean(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_OptLayout CO_getStartWsAfter(CO_Start arg) */

CO_OptLayout CO_getStartWsAfter(CO_Start arg)
{
  if (CO_isStartParseResult(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (CO_isStartMeasure(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (CO_isStartBoolCon(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
}

/*}}}  */
/*{{{  CO_Start CO_setStartWsAfter(CO_Start arg, CO_OptLayout wsAfter) */

CO_Start CO_setStartWsAfter(CO_Start arg, CO_OptLayout wsAfter)
{
  if (CO_isStartParseResult(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (CO_isStartMeasure(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (CO_isStartBoolCon(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (CO_isStartBoolean(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }

  ATabort("Start has no WsAfter: %t\n", arg);
  return (CO_Start)NULL;
}

/*}}}  */
/*{{{  ATbool CO_hasStartAmbCnt(CO_Start arg) */

ATbool CO_hasStartAmbCnt(CO_Start arg)
{
  if (CO_isStartParseResult(arg)) {
    return ATtrue;
  }
  else if (CO_isStartMeasure(arg)) {
    return ATtrue;
  }
  else if (CO_isStartBoolCon(arg)) {
    return ATtrue;
  }
  else if (CO_isStartBoolean(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int CO_getStartAmbCnt(CO_Start arg) */

int CO_getStartAmbCnt(CO_Start arg)
{
  if (CO_isStartParseResult(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (CO_isStartMeasure(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (CO_isStartBoolCon(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  CO_Start CO_setStartAmbCnt(CO_Start arg, int ambCnt) */

CO_Start CO_setStartAmbCnt(CO_Start arg, int ambCnt)
{
  if (CO_isStartParseResult(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (CO_isStartMeasure(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (CO_isStartBoolCon(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (CO_isStartBoolean(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }

  ATabort("Start has no AmbCnt: %t\n", arg);
  return (CO_Start)NULL;
}

/*}}}  */
/*{{{  ATbool CO_hasStartTopMeasure(CO_Start arg) */

ATbool CO_hasStartTopMeasure(CO_Start arg)
{
  if (CO_isStartMeasure(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_Measure CO_getStartTopMeasure(CO_Start arg) */

CO_Measure CO_getStartTopMeasure(CO_Start arg)
{
  
    return (CO_Measure)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  CO_Start CO_setStartTopMeasure(CO_Start arg, CO_Measure topMeasure) */

CO_Start CO_setStartTopMeasure(CO_Start arg, CO_Measure topMeasure)
{
  if (CO_isStartMeasure(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topMeasure, 1), 1), 0);
  }

  ATabort("Start has no TopMeasure: %t\n", arg);
  return (CO_Start)NULL;
}

/*}}}  */
/*{{{  ATbool CO_hasStartTopBoolCon(CO_Start arg) */

ATbool CO_hasStartTopBoolCon(CO_Start arg)
{
  if (CO_isStartBoolCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_BoolCon CO_getStartTopBoolCon(CO_Start arg) */

CO_BoolCon CO_getStartTopBoolCon(CO_Start arg)
{
  
    return (CO_BoolCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  CO_Start CO_setStartTopBoolCon(CO_Start arg, CO_BoolCon topBoolCon) */

CO_Start CO_setStartTopBoolCon(CO_Start arg, CO_BoolCon topBoolCon)
{
  if (CO_isStartBoolCon(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topBoolCon, 1), 1), 0);
  }

  ATabort("Start has no TopBoolCon: %t\n", arg);
  return (CO_Start)NULL;
}

/*}}}  */
/*{{{  ATbool CO_hasStartTopBoolean(CO_Start arg) */

ATbool CO_hasStartTopBoolean(CO_Start arg)
{
  if (CO_isStartBoolean(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_Boolean CO_getStartTopBoolean(CO_Start arg) */

CO_Boolean CO_getStartTopBoolean(CO_Start arg)
{
  
    return (CO_Boolean)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  CO_Start CO_setStartTopBoolean(CO_Start arg, CO_Boolean topBoolean) */

CO_Start CO_setStartTopBoolean(CO_Start arg, CO_Boolean topBoolean)
{
  if (CO_isStartBoolean(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topBoolean, 1), 1), 0);
  }

  ATabort("Start has no TopBoolean: %t\n", arg);
  return (CO_Start)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CO_OptLayout accessors */

/*{{{  ATbool CO_isValidOptLayout(CO_OptLayout arg) */

ATbool CO_isValidOptLayout(CO_OptLayout arg)
{
  if (CO_isOptLayoutAbsent(arg)) {
    return ATtrue;
  }
  else if (CO_isOptLayoutPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CO_isOptLayoutAbsent(CO_OptLayout arg) */

inline ATbool CO_isOptLayoutAbsent(CO_OptLayout arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternOptLayoutAbsent);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isOptLayoutPresent(CO_OptLayout arg) */

inline ATbool CO_isOptLayoutPresent(CO_OptLayout arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternOptLayoutPresent, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool CO_hasOptLayoutChars(CO_OptLayout arg) */

ATbool CO_hasOptLayoutChars(CO_OptLayout arg)
{
  if (CO_isOptLayoutPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_CHARLIST CO_getOptLayoutChars(CO_OptLayout arg) */

CO_CHARLIST CO_getOptLayoutChars(CO_OptLayout arg)
{
  
    return (CO_CHARLIST)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  CO_OptLayout CO_setOptLayoutChars(CO_OptLayout arg, CO_CHARLIST chars) */

CO_OptLayout CO_setOptLayoutChars(CO_OptLayout arg, CO_CHARLIST chars)
{
  if (CO_isOptLayoutPresent(arg)) {
    return (CO_OptLayout)ATsetArgument((ATermAppl)arg, (ATerm)chars, 1);
  }

  ATabort("OptLayout has no Chars: %t\n", arg);
  return (CO_OptLayout)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  CO_BoolCon CO_visitBoolCon(CO_BoolCon arg) */

CO_BoolCon CO_visitBoolCon(CO_BoolCon arg)
{
  if (CO_isBoolConTrue(arg)) {
    return CO_makeBoolConTrue();
  }
  if (CO_isBoolConFalse(arg)) {
    return CO_makeBoolConFalse();
  }
  ATabort("not a BoolCon: %t\n", arg);
  return (CO_BoolCon)NULL;
}

/*}}}  */
/*{{{  CO_Boolean CO_visitBoolean(CO_Boolean arg, CO_BoolCon (*acceptBoolCon)(CO_BoolCon), CO_OptLayout (*acceptWsAfterLhs)(CO_OptLayout), CO_OptLayout (*acceptWsAfterBar)(CO_OptLayout), CO_OptLayout (*acceptWsAfterAmp)(CO_OptLayout), CO_OptLayout (*acceptWsAfterNot)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_OptLayout (*acceptWsAfterBoolean)(CO_OptLayout)) */

CO_Boolean CO_visitBoolean(CO_Boolean arg, CO_BoolCon (*acceptBoolCon)(CO_BoolCon), CO_OptLayout (*acceptWsAfterLhs)(CO_OptLayout), CO_OptLayout (*acceptWsAfterBar)(CO_OptLayout), CO_OptLayout (*acceptWsAfterAmp)(CO_OptLayout), CO_OptLayout (*acceptWsAfterNot)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_OptLayout (*acceptWsAfterBoolean)(CO_OptLayout))
{
  if (CO_isBooleanConstant(arg)) {
    return CO_makeBooleanConstant(
        acceptBoolCon ? acceptBoolCon(CO_getBooleanBoolCon(arg)) : CO_getBooleanBoolCon(arg));
  }
  if (CO_isBooleanOr(arg)) {
    return CO_makeBooleanOr(
        CO_visitBoolean(CO_getBooleanLhs(arg), acceptBoolCon, acceptWsAfterLhs, acceptWsAfterBar, acceptWsAfterAmp, acceptWsAfterNot, acceptWsAfterParenOpen, acceptWsAfterBoolean),
        acceptWsAfterLhs ? acceptWsAfterLhs(CO_getBooleanWsAfterLhs(arg)) : CO_getBooleanWsAfterLhs(arg),
        acceptWsAfterBar ? acceptWsAfterBar(CO_getBooleanWsAfterBar(arg)) : CO_getBooleanWsAfterBar(arg),
        CO_visitBoolean(CO_getBooleanRhs(arg), acceptBoolCon, acceptWsAfterLhs, acceptWsAfterBar, acceptWsAfterAmp, acceptWsAfterNot, acceptWsAfterParenOpen, acceptWsAfterBoolean));
  }
  if (CO_isBooleanAnd(arg)) {
    return CO_makeBooleanAnd(
        CO_visitBoolean(CO_getBooleanLhs(arg), acceptBoolCon, acceptWsAfterLhs, acceptWsAfterBar, acceptWsAfterAmp, acceptWsAfterNot, acceptWsAfterParenOpen, acceptWsAfterBoolean),
        acceptWsAfterLhs ? acceptWsAfterLhs(CO_getBooleanWsAfterLhs(arg)) : CO_getBooleanWsAfterLhs(arg),
        acceptWsAfterAmp ? acceptWsAfterAmp(CO_getBooleanWsAfterAmp(arg)) : CO_getBooleanWsAfterAmp(arg),
        CO_visitBoolean(CO_getBooleanRhs(arg), acceptBoolCon, acceptWsAfterLhs, acceptWsAfterBar, acceptWsAfterAmp, acceptWsAfterNot, acceptWsAfterParenOpen, acceptWsAfterBoolean));
  }
  if (CO_isBooleanNot(arg)) {
    return CO_makeBooleanNot(
        acceptWsAfterNot ? acceptWsAfterNot(CO_getBooleanWsAfterNot(arg)) : CO_getBooleanWsAfterNot(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(CO_getBooleanWsAfterParenOpen(arg)) : CO_getBooleanWsAfterParenOpen(arg),
        CO_visitBoolean(CO_getBooleanBoolean(arg), acceptBoolCon, acceptWsAfterLhs, acceptWsAfterBar, acceptWsAfterAmp, acceptWsAfterNot, acceptWsAfterParenOpen, acceptWsAfterBoolean),
        acceptWsAfterBoolean ? acceptWsAfterBoolean(CO_getBooleanWsAfterBoolean(arg)) : CO_getBooleanWsAfterBoolean(arg));
  }
  if (CO_isBooleanBracket(arg)) {
    return CO_makeBooleanBracket(
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(CO_getBooleanWsAfterParenOpen(arg)) : CO_getBooleanWsAfterParenOpen(arg),
        CO_visitBoolean(CO_getBooleanBoolean(arg), acceptBoolCon, acceptWsAfterLhs, acceptWsAfterBar, acceptWsAfterAmp, acceptWsAfterNot, acceptWsAfterParenOpen, acceptWsAfterBoolean),
        acceptWsAfterBoolean ? acceptWsAfterBoolean(CO_getBooleanWsAfterBoolean(arg)) : CO_getBooleanWsAfterBoolean(arg));
  }
  ATabort("not a Boolean: %t\n", arg);
  return (CO_Boolean)NULL;
}

/*}}}  */
/*{{{  CO_Measure CO_visitMeasure(CO_Measure arg) */

CO_Measure CO_visitMeasure(CO_Measure arg)
{
  if (CO_isMeasureLess(arg)) {
    return CO_makeMeasureLess();
  }
  if (CO_isMeasureGreater(arg)) {
    return CO_makeMeasureGreater();
  }
  if (CO_isMeasureEqual(arg)) {
    return CO_makeMeasureEqual();
  }
  ATabort("not a Measure: %t\n", arg);
  return (CO_Measure)NULL;
}

/*}}}  */
/*{{{  CO_ParseResult CO_visitParseResult(CO_ParseResult arg, char* (*acceptTreeSort)(char*), CO_OptLayout (*acceptWsAfterParseTree)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_Bytes (*acceptLeftLayout)(CO_Bytes), CO_OptLayout (*acceptWsAfterLeftLayout)(CO_OptLayout), CO_OptLayout (*acceptWsAfterC1)(CO_OptLayout), ATerm (*acceptTree)(ATerm), CO_OptLayout (*acceptWsAfterTree)(CO_OptLayout), CO_OptLayout (*acceptWsAfterC2)(CO_OptLayout), CO_Bytes (*acceptRightLayout)(CO_Bytes), CO_OptLayout (*acceptWsAfterRightLayout)(CO_OptLayout), CO_OptLayout (*acceptWsAfterC3)(CO_OptLayout), CO_NatCon (*acceptAmbCnt)(CO_NatCon), CO_OptLayout (*acceptWsAfterAmbCnt)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParseError)(CO_OptLayout), CO_NatCon (*acceptLine)(CO_NatCon), CO_OptLayout (*acceptWsAfterLine)(CO_OptLayout), CO_NatCon (*acceptColumn)(CO_NatCon), CO_OptLayout (*acceptWsAfterColumn)(CO_OptLayout), CO_NatCon (*acceptOffset)(CO_NatCon), CO_OptLayout (*acceptWsAfterOffset)(CO_OptLayout)) */

CO_ParseResult CO_visitParseResult(CO_ParseResult arg, char* (*acceptTreeSort)(char*), CO_OptLayout (*acceptWsAfterParseTree)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_Bytes (*acceptLeftLayout)(CO_Bytes), CO_OptLayout (*acceptWsAfterLeftLayout)(CO_OptLayout), CO_OptLayout (*acceptWsAfterC1)(CO_OptLayout), ATerm (*acceptTree)(ATerm), CO_OptLayout (*acceptWsAfterTree)(CO_OptLayout), CO_OptLayout (*acceptWsAfterC2)(CO_OptLayout), CO_Bytes (*acceptRightLayout)(CO_Bytes), CO_OptLayout (*acceptWsAfterRightLayout)(CO_OptLayout), CO_OptLayout (*acceptWsAfterC3)(CO_OptLayout), CO_NatCon (*acceptAmbCnt)(CO_NatCon), CO_OptLayout (*acceptWsAfterAmbCnt)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParseError)(CO_OptLayout), CO_NatCon (*acceptLine)(CO_NatCon), CO_OptLayout (*acceptWsAfterLine)(CO_OptLayout), CO_NatCon (*acceptColumn)(CO_NatCon), CO_OptLayout (*acceptWsAfterColumn)(CO_OptLayout), CO_NatCon (*acceptOffset)(CO_NatCon), CO_OptLayout (*acceptWsAfterOffset)(CO_OptLayout))
{
  if (CO_isParseResultTree(arg)) {
    return CO_makeParseResultTree(
        acceptTreeSort ? acceptTreeSort(CO_getParseResultTreeSort(arg)) : CO_getParseResultTreeSort(arg),
        acceptWsAfterParseTree ? acceptWsAfterParseTree(CO_getParseResultWsAfterParseTree(arg)) : CO_getParseResultWsAfterParseTree(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(CO_getParseResultWsAfterParenOpen(arg)) : CO_getParseResultWsAfterParenOpen(arg),
        acceptLeftLayout ? acceptLeftLayout(CO_getParseResultLeftLayout(arg)) : CO_getParseResultLeftLayout(arg),
        acceptWsAfterLeftLayout ? acceptWsAfterLeftLayout(CO_getParseResultWsAfterLeftLayout(arg)) : CO_getParseResultWsAfterLeftLayout(arg),
        acceptWsAfterC1 ? acceptWsAfterC1(CO_getParseResultWsAfterC1(arg)) : CO_getParseResultWsAfterC1(arg),
        acceptTree ? acceptTree(CO_getParseResultTree(arg)) : CO_getParseResultTree(arg),
        acceptWsAfterTree ? acceptWsAfterTree(CO_getParseResultWsAfterTree(arg)) : CO_getParseResultWsAfterTree(arg),
        acceptWsAfterC2 ? acceptWsAfterC2(CO_getParseResultWsAfterC2(arg)) : CO_getParseResultWsAfterC2(arg),
        acceptRightLayout ? acceptRightLayout(CO_getParseResultRightLayout(arg)) : CO_getParseResultRightLayout(arg),
        acceptWsAfterRightLayout ? acceptWsAfterRightLayout(CO_getParseResultWsAfterRightLayout(arg)) : CO_getParseResultWsAfterRightLayout(arg),
        acceptWsAfterC3 ? acceptWsAfterC3(CO_getParseResultWsAfterC3(arg)) : CO_getParseResultWsAfterC3(arg),
        acceptAmbCnt ? acceptAmbCnt(CO_getParseResultAmbCnt(arg)) : CO_getParseResultAmbCnt(arg),
        acceptWsAfterAmbCnt ? acceptWsAfterAmbCnt(CO_getParseResultWsAfterAmbCnt(arg)) : CO_getParseResultWsAfterAmbCnt(arg));
  }
  if (CO_isParseResultError(arg)) {
    return CO_makeParseResultError(
        acceptWsAfterParseError ? acceptWsAfterParseError(CO_getParseResultWsAfterParseError(arg)) : CO_getParseResultWsAfterParseError(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(CO_getParseResultWsAfterParenOpen(arg)) : CO_getParseResultWsAfterParenOpen(arg),
        acceptLine ? acceptLine(CO_getParseResultLine(arg)) : CO_getParseResultLine(arg),
        acceptWsAfterLine ? acceptWsAfterLine(CO_getParseResultWsAfterLine(arg)) : CO_getParseResultWsAfterLine(arg),
        acceptWsAfterC1 ? acceptWsAfterC1(CO_getParseResultWsAfterC1(arg)) : CO_getParseResultWsAfterC1(arg),
        acceptColumn ? acceptColumn(CO_getParseResultColumn(arg)) : CO_getParseResultColumn(arg),
        acceptWsAfterColumn ? acceptWsAfterColumn(CO_getParseResultWsAfterColumn(arg)) : CO_getParseResultWsAfterColumn(arg),
        acceptWsAfterC2 ? acceptWsAfterC2(CO_getParseResultWsAfterC2(arg)) : CO_getParseResultWsAfterC2(arg),
        acceptOffset ? acceptOffset(CO_getParseResultOffset(arg)) : CO_getParseResultOffset(arg),
        acceptWsAfterOffset ? acceptWsAfterOffset(CO_getParseResultWsAfterOffset(arg)) : CO_getParseResultWsAfterOffset(arg));
  }
  if (CO_isParseResultNoParsetable(arg)) {
    return CO_makeParseResultNoParsetable();
  }
  if (CO_isParseResultNoValidResult(arg)) {
    return CO_makeParseResultNoValidResult();
  }
  ATabort("not a ParseResult: %t\n", arg);
  return (CO_ParseResult)NULL;
}

/*}}}  */
/*{{{  CO_Start CO_visitStart(CO_Start arg, CO_OptLayout (*acceptWsBefore)(CO_OptLayout), CO_ParseResult (*acceptTopParseResult)(CO_ParseResult), CO_OptLayout (*acceptWsAfter)(CO_OptLayout), int (*acceptAmbCnt)(int), CO_Measure (*acceptTopMeasure)(CO_Measure), CO_BoolCon (*acceptTopBoolCon)(CO_BoolCon), CO_Boolean (*acceptTopBoolean)(CO_Boolean)) */

CO_Start CO_visitStart(CO_Start arg, CO_OptLayout (*acceptWsBefore)(CO_OptLayout), CO_ParseResult (*acceptTopParseResult)(CO_ParseResult), CO_OptLayout (*acceptWsAfter)(CO_OptLayout), int (*acceptAmbCnt)(int), CO_Measure (*acceptTopMeasure)(CO_Measure), CO_BoolCon (*acceptTopBoolCon)(CO_BoolCon), CO_Boolean (*acceptTopBoolean)(CO_Boolean))
{
  if (CO_isStartParseResult(arg)) {
    return CO_makeStartParseResult(
        acceptWsBefore ? acceptWsBefore(CO_getStartWsBefore(arg)) : CO_getStartWsBefore(arg),
        acceptTopParseResult ? acceptTopParseResult(CO_getStartTopParseResult(arg)) : CO_getStartTopParseResult(arg),
        acceptWsAfter ? acceptWsAfter(CO_getStartWsAfter(arg)) : CO_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(CO_getStartAmbCnt(arg)) : CO_getStartAmbCnt(arg));
  }
  if (CO_isStartMeasure(arg)) {
    return CO_makeStartMeasure(
        acceptWsBefore ? acceptWsBefore(CO_getStartWsBefore(arg)) : CO_getStartWsBefore(arg),
        acceptTopMeasure ? acceptTopMeasure(CO_getStartTopMeasure(arg)) : CO_getStartTopMeasure(arg),
        acceptWsAfter ? acceptWsAfter(CO_getStartWsAfter(arg)) : CO_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(CO_getStartAmbCnt(arg)) : CO_getStartAmbCnt(arg));
  }
  if (CO_isStartBoolCon(arg)) {
    return CO_makeStartBoolCon(
        acceptWsBefore ? acceptWsBefore(CO_getStartWsBefore(arg)) : CO_getStartWsBefore(arg),
        acceptTopBoolCon ? acceptTopBoolCon(CO_getStartTopBoolCon(arg)) : CO_getStartTopBoolCon(arg),
        acceptWsAfter ? acceptWsAfter(CO_getStartWsAfter(arg)) : CO_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(CO_getStartAmbCnt(arg)) : CO_getStartAmbCnt(arg));
  }
  if (CO_isStartBoolean(arg)) {
    return CO_makeStartBoolean(
        acceptWsBefore ? acceptWsBefore(CO_getStartWsBefore(arg)) : CO_getStartWsBefore(arg),
        acceptTopBoolean ? acceptTopBoolean(CO_getStartTopBoolean(arg)) : CO_getStartTopBoolean(arg),
        acceptWsAfter ? acceptWsAfter(CO_getStartWsAfter(arg)) : CO_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(CO_getStartAmbCnt(arg)) : CO_getStartAmbCnt(arg));
  }
  ATabort("not a Start: %t\n", arg);
  return (CO_Start)NULL;
}

/*}}}  */
/*{{{  CO_OptLayout CO_visitOptLayout(CO_OptLayout arg, CO_CHARLIST (*acceptChars)(CO_CHARLIST)) */

CO_OptLayout CO_visitOptLayout(CO_OptLayout arg, CO_CHARLIST (*acceptChars)(CO_CHARLIST))
{
  if (CO_isOptLayoutAbsent(arg)) {
    return CO_makeOptLayoutAbsent();
  }
  if (CO_isOptLayoutPresent(arg)) {
    return CO_makeOptLayoutPresent(
        acceptChars ? acceptChars(CO_getOptLayoutChars(arg)) : CO_getOptLayoutChars(arg));
  }
  ATabort("not a OptLayout: %t\n", arg);
  return (CO_OptLayout)NULL;
}

/*}}}  */

/*}}}  */
