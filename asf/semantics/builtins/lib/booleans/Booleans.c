#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "Booleans.h"

/*{{{  typedefs */

typedef struct ATerm _B_BoolCon;
typedef struct ATerm _B_Boolean;
typedef struct ATerm _B_Start;
typedef struct ATerm _B_OptLayout;

/*}}}  */

/*{{{  void B_initBooleansApi(void) */

void B_initBooleansApi(void)
{
  init_Booleans_dict();
}

/*}}}  */

/*{{{  term conversion functions */

/*{{{  B_BoolCon B_BoolConFromTerm(ATerm t) */

B_BoolCon B_BoolConFromTerm(ATerm t)
{
  return (B_BoolCon)t;
}

/*}}}  */
/*{{{  ATerm B_BoolConToTerm(B_BoolCon arg) */

ATerm B_BoolConToTerm(B_BoolCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  B_Boolean B_BooleanFromTerm(ATerm t) */

B_Boolean B_BooleanFromTerm(ATerm t)
{
  return (B_Boolean)t;
}

/*}}}  */
/*{{{  ATerm B_BooleanToTerm(B_Boolean arg) */

ATerm B_BooleanToTerm(B_Boolean arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  B_Start B_StartFromTerm(ATerm t) */

B_Start B_StartFromTerm(ATerm t)
{
  return (B_Start)t;
}

/*}}}  */
/*{{{  ATerm B_StartToTerm(B_Start arg) */

ATerm B_StartToTerm(B_Start arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  B_OptLayout B_OptLayoutFromTerm(ATerm t) */

B_OptLayout B_OptLayoutFromTerm(ATerm t)
{
  return (B_OptLayout)t;
}

/*}}}  */
/*{{{  ATerm B_OptLayoutToTerm(B_OptLayout arg) */

ATerm B_OptLayoutToTerm(B_OptLayout arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*}}}  */
/*{{{  constructors */

/*{{{  B_BoolCon B_makeBoolConTrue() */

B_BoolCon B_makeBoolConTrue()
{
  return (B_BoolCon)(ATerm)ATmakeAppl2(B_afun0, (ATerm)ATmakeAppl3(B_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(B_afun2, (ATerm)ATmakeAppl0(B_afun3))), (ATerm)ATmakeAppl1(B_afun4, (ATerm)ATmakeAppl1(B_afun5, (ATerm)ATmakeAppl0(B_afun6))), (ATerm)ATmakeAppl1(B_afun7, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(B_afun8, (ATerm)ATmakeAppl1(B_afun9, (ATerm)ATmakeAppl0(B_afun3)))), (ATerm)ATmakeAppl1(B_afun8, (ATerm)ATmakeAppl0(B_afun10))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(B_afun2, (ATerm)ATmakeAppl0(B_afun3))));
}

/*}}}  */
/*{{{  B_BoolCon B_makeBoolConFalse() */

B_BoolCon B_makeBoolConFalse()
{
  return (B_BoolCon)(ATerm)ATmakeAppl2(B_afun0, (ATerm)ATmakeAppl3(B_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(B_afun2, (ATerm)ATmakeAppl0(B_afun11))), (ATerm)ATmakeAppl1(B_afun4, (ATerm)ATmakeAppl1(B_afun5, (ATerm)ATmakeAppl0(B_afun6))), (ATerm)ATmakeAppl1(B_afun7, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(B_afun8, (ATerm)ATmakeAppl1(B_afun9, (ATerm)ATmakeAppl0(B_afun11)))), (ATerm)ATmakeAppl1(B_afun8, (ATerm)ATmakeAppl0(B_afun10))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(B_afun2, (ATerm)ATmakeAppl0(B_afun11))));
}

/*}}}  */
/*{{{  B_Boolean B_makeBooleanConstant(B_BoolCon BoolCon) */

B_Boolean B_makeBooleanConstant(B_BoolCon BoolCon)
{
  return (B_Boolean)(ATerm)ATmakeAppl2(B_afun0, (ATerm)ATmakeAppl3(B_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(B_afun4, (ATerm)ATmakeAppl1(B_afun5, (ATerm)ATmakeAppl0(B_afun6)))), (ATerm)ATmakeAppl1(B_afun4, (ATerm)ATmakeAppl1(B_afun5, (ATerm)ATmakeAppl0(B_afun12))), (ATerm)ATmakeAppl1(B_afun7, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(B_afun8, (ATerm)ATmakeAppl1(B_afun9, (ATerm)ATmakeAppl0(B_afun13)))))), (ATerm)ATmakeList1((ATerm)BoolCon));
}

/*}}}  */
/*{{{  B_Boolean B_makeBooleanOr(B_Boolean lhs, B_OptLayout wsAfterLhs, B_OptLayout wsAfterBar, B_Boolean rhs) */

B_Boolean B_makeBooleanOr(B_Boolean lhs, B_OptLayout wsAfterLhs, B_OptLayout wsAfterBar, B_Boolean rhs)
{
  return (B_Boolean)(ATerm)ATmakeAppl2(B_afun0, (ATerm)ATmakeAppl3(B_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(B_afun4, (ATerm)ATmakeAppl1(B_afun5, (ATerm)ATmakeAppl0(B_afun12)))), (ATerm)ATmakeAppl1(B_afun4, (ATerm)ATmakeAppl1(B_afun14, (ATerm)ATmakeAppl0(B_afun15)))), (ATerm)ATmakeAppl1(B_afun2, (ATerm)ATmakeAppl0(B_afun16))), (ATerm)ATmakeAppl1(B_afun4, (ATerm)ATmakeAppl1(B_afun14, (ATerm)ATmakeAppl0(B_afun15)))), (ATerm)ATmakeAppl1(B_afun4, (ATerm)ATmakeAppl1(B_afun5, (ATerm)ATmakeAppl0(B_afun12)))), (ATerm)ATmakeAppl1(B_afun4, (ATerm)ATmakeAppl1(B_afun5, (ATerm)ATmakeAppl0(B_afun12))), (ATerm)ATmakeAppl1(B_afun7, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(B_afun8, (ATerm)ATmakeAppl1(B_afun9, (ATerm)ATmakeAppl0(B_afun17)))), (ATerm)ATmakeAppl1(B_afun18, (ATerm)ATmakeAppl0(B_afun19))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)rhs), (ATerm)wsAfterBar), (ATerm)ATmakeAppl1(B_afun2, (ATerm)ATmakeAppl0(B_afun16))), (ATerm)wsAfterLhs), (ATerm)lhs));
}

/*}}}  */
/*{{{  B_Boolean B_makeBooleanAnd(B_Boolean lhs, B_OptLayout wsAfterLhs, B_OptLayout wsAfterAmp, B_Boolean rhs) */

B_Boolean B_makeBooleanAnd(B_Boolean lhs, B_OptLayout wsAfterLhs, B_OptLayout wsAfterAmp, B_Boolean rhs)
{
  return (B_Boolean)(ATerm)ATmakeAppl2(B_afun0, (ATerm)ATmakeAppl3(B_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(B_afun4, (ATerm)ATmakeAppl1(B_afun5, (ATerm)ATmakeAppl0(B_afun12)))), (ATerm)ATmakeAppl1(B_afun4, (ATerm)ATmakeAppl1(B_afun14, (ATerm)ATmakeAppl0(B_afun15)))), (ATerm)ATmakeAppl1(B_afun2, (ATerm)ATmakeAppl0(B_afun20))), (ATerm)ATmakeAppl1(B_afun4, (ATerm)ATmakeAppl1(B_afun14, (ATerm)ATmakeAppl0(B_afun15)))), (ATerm)ATmakeAppl1(B_afun4, (ATerm)ATmakeAppl1(B_afun5, (ATerm)ATmakeAppl0(B_afun12)))), (ATerm)ATmakeAppl1(B_afun4, (ATerm)ATmakeAppl1(B_afun5, (ATerm)ATmakeAppl0(B_afun12))), (ATerm)ATmakeAppl1(B_afun7, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(B_afun8, (ATerm)ATmakeAppl1(B_afun9, (ATerm)ATmakeAppl0(B_afun21)))), (ATerm)ATmakeAppl1(B_afun18, (ATerm)ATmakeAppl0(B_afun19))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)rhs), (ATerm)wsAfterAmp), (ATerm)ATmakeAppl1(B_afun2, (ATerm)ATmakeAppl0(B_afun20))), (ATerm)wsAfterLhs), (ATerm)lhs));
}

/*}}}  */
/*{{{  B_Boolean B_makeBooleanNot(B_OptLayout wsAfterNot, B_OptLayout wsAfterParenOpen, B_Boolean Boolean, B_OptLayout wsAfterBoolean) */

B_Boolean B_makeBooleanNot(B_OptLayout wsAfterNot, B_OptLayout wsAfterParenOpen, B_Boolean Boolean, B_OptLayout wsAfterBoolean)
{
  return (B_Boolean)(ATerm)ATmakeAppl2(B_afun0, (ATerm)ATmakeAppl3(B_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(B_afun2, (ATerm)ATmakeAppl0(B_afun22))), (ATerm)ATmakeAppl1(B_afun4, (ATerm)ATmakeAppl1(B_afun14, (ATerm)ATmakeAppl0(B_afun15)))), (ATerm)ATmakeAppl1(B_afun4, (ATerm)ATmakeAppl1(B_afun5, (ATerm)ATmakeAppl0(B_afun12)))), (ATerm)ATmakeAppl1(B_afun4, (ATerm)ATmakeAppl1(B_afun14, (ATerm)ATmakeAppl0(B_afun15)))), (ATerm)ATmakeAppl1(B_afun2, (ATerm)ATmakeAppl0(B_afun23))), (ATerm)ATmakeAppl1(B_afun4, (ATerm)ATmakeAppl1(B_afun14, (ATerm)ATmakeAppl0(B_afun15)))), (ATerm)ATmakeAppl1(B_afun2, (ATerm)ATmakeAppl0(B_afun24))), (ATerm)ATmakeAppl1(B_afun4, (ATerm)ATmakeAppl1(B_afun5, (ATerm)ATmakeAppl0(B_afun12))), (ATerm)ATmakeAppl1(B_afun7, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(B_afun8, (ATerm)ATmakeAppl1(B_afun9, (ATerm)ATmakeAppl0(B_afun24)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(B_afun2, (ATerm)ATmakeAppl0(B_afun22))), (ATerm)wsAfterBoolean), (ATerm)Boolean), (ATerm)wsAfterParenOpen), (ATerm)ATmakeAppl1(B_afun2, (ATerm)ATmakeAppl0(B_afun23))), (ATerm)wsAfterNot), (ATerm)ATmakeAppl1(B_afun2, (ATerm)ATmakeAppl0(B_afun24))));
}

/*}}}  */
/*{{{  B_Boolean B_makeBooleanBracket(B_OptLayout wsAfterParenOpen, B_Boolean Boolean, B_OptLayout wsAfterBoolean) */

B_Boolean B_makeBooleanBracket(B_OptLayout wsAfterParenOpen, B_Boolean Boolean, B_OptLayout wsAfterBoolean)
{
  return (B_Boolean)(ATerm)ATmakeAppl2(B_afun0, (ATerm)ATmakeAppl3(B_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(B_afun2, (ATerm)ATmakeAppl0(B_afun22))), (ATerm)ATmakeAppl1(B_afun4, (ATerm)ATmakeAppl1(B_afun14, (ATerm)ATmakeAppl0(B_afun15)))), (ATerm)ATmakeAppl1(B_afun4, (ATerm)ATmakeAppl1(B_afun5, (ATerm)ATmakeAppl0(B_afun12)))), (ATerm)ATmakeAppl1(B_afun4, (ATerm)ATmakeAppl1(B_afun14, (ATerm)ATmakeAppl0(B_afun15)))), (ATerm)ATmakeAppl1(B_afun2, (ATerm)ATmakeAppl0(B_afun23))), (ATerm)ATmakeAppl1(B_afun4, (ATerm)ATmakeAppl1(B_afun5, (ATerm)ATmakeAppl0(B_afun12))), (ATerm)ATmakeAppl1(B_afun7, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(B_afun8, (ATerm)ATmakeAppl1(B_afun9, (ATerm)ATmakeAppl0(B_afun25)))), (ATerm)ATmakeAppl0(B_afun26)))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(B_afun2, (ATerm)ATmakeAppl0(B_afun22))), (ATerm)wsAfterBoolean), (ATerm)Boolean), (ATerm)wsAfterParenOpen), (ATerm)ATmakeAppl1(B_afun2, (ATerm)ATmakeAppl0(B_afun23))));
}

/*}}}  */
/*{{{  B_Start B_makeStartBoolCon(B_OptLayout wsBefore, B_BoolCon topBoolCon, B_OptLayout wsAfter, int ambCnt) */

B_Start B_makeStartBoolCon(B_OptLayout wsBefore, B_BoolCon topBoolCon, B_OptLayout wsAfter, int ambCnt)
{
  return (B_Start)(ATerm)ATmakeAppl2(B_afun27, (ATerm)ATmakeAppl2(B_afun0, (ATerm)ATmakeAppl3(B_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(B_afun4, (ATerm)ATmakeAppl1(B_afun14, (ATerm)ATmakeAppl0(B_afun15)))), (ATerm)ATmakeAppl1(B_afun4, (ATerm)ATmakeAppl1(B_afun5, (ATerm)ATmakeAppl0(B_afun6)))), (ATerm)ATmakeAppl1(B_afun4, (ATerm)ATmakeAppl1(B_afun14, (ATerm)ATmakeAppl0(B_afun15)))), (ATerm)ATmakeAppl1(B_afun5, (ATerm)ATmakeAppl0(B_afun28)), (ATerm)ATmakeAppl0(B_afun29)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topBoolCon), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  B_Start B_makeStartBoolean(B_OptLayout wsBefore, B_Boolean topBoolean, B_OptLayout wsAfter, int ambCnt) */

B_Start B_makeStartBoolean(B_OptLayout wsBefore, B_Boolean topBoolean, B_OptLayout wsAfter, int ambCnt)
{
  return (B_Start)(ATerm)ATmakeAppl2(B_afun27, (ATerm)ATmakeAppl2(B_afun0, (ATerm)ATmakeAppl3(B_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(B_afun4, (ATerm)ATmakeAppl1(B_afun14, (ATerm)ATmakeAppl0(B_afun15)))), (ATerm)ATmakeAppl1(B_afun4, (ATerm)ATmakeAppl1(B_afun5, (ATerm)ATmakeAppl0(B_afun12)))), (ATerm)ATmakeAppl1(B_afun4, (ATerm)ATmakeAppl1(B_afun14, (ATerm)ATmakeAppl0(B_afun15)))), (ATerm)ATmakeAppl1(B_afun5, (ATerm)ATmakeAppl0(B_afun28)), (ATerm)ATmakeAppl0(B_afun29)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topBoolean), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  B_OptLayout B_makeOptLayoutAbsent() */

B_OptLayout B_makeOptLayoutAbsent()
{
  return (B_OptLayout)(ATerm)ATmakeAppl2(B_afun0, (ATerm)ATmakeAppl3(B_afun1, (ATerm)ATempty, (ATerm)ATmakeAppl1(B_afun4, (ATerm)ATmakeAppl1(B_afun14, (ATerm)ATmakeAppl0(B_afun15))), (ATerm)ATmakeAppl0(B_afun29)), (ATerm)ATempty);
}

/*}}}  */
/*{{{  B_OptLayout B_makeOptLayoutPresent(B_CHARLIST chars) */

B_OptLayout B_makeOptLayoutPresent(B_CHARLIST chars)
{
  return (B_OptLayout)(ATerm)ATmakeAppl2(B_afun0, (ATerm)ATmakeAppl3(B_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(B_afun4, (ATerm)ATmakeAppl0(B_afun15))), (ATerm)ATmakeAppl1(B_afun4, (ATerm)ATmakeAppl1(B_afun14, (ATerm)ATmakeAppl0(B_afun15))), (ATerm)ATmakeAppl0(B_afun29)), (ATerm)chars);
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool B_isEqualBoolCon(B_BoolCon arg0, B_BoolCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool B_isEqualBoolean(B_Boolean arg0, B_Boolean arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool B_isEqualStart(B_Start arg0, B_Start arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool B_isEqualOptLayout(B_OptLayout arg0, B_OptLayout arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  B_BoolCon accessors */

/*{{{  ATbool B_isValidBoolCon(B_BoolCon arg) */

ATbool B_isValidBoolCon(B_BoolCon arg)
{
  if (B_isBoolConTrue(arg)) {
    return ATtrue;
  }
  else if (B_isBoolConFalse(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool B_isBoolConTrue(B_BoolCon arg) */

inline ATbool B_isBoolConTrue(B_BoolCon arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, B_patternBoolConTrue);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool B_isBoolConFalse(B_BoolCon arg) */

inline ATbool B_isBoolConFalse(B_BoolCon arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, B_patternBoolConFalse);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */

/*}}}  */
/*{{{  B_Boolean accessors */

/*{{{  ATbool B_isValidBoolean(B_Boolean arg) */

ATbool B_isValidBoolean(B_Boolean arg)
{
  if (B_isBooleanConstant(arg)) {
    return ATtrue;
  }
  else if (B_isBooleanOr(arg)) {
    return ATtrue;
  }
  else if (B_isBooleanAnd(arg)) {
    return ATtrue;
  }
  else if (B_isBooleanNot(arg)) {
    return ATtrue;
  }
  else if (B_isBooleanBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool B_isBooleanConstant(B_Boolean arg) */

inline ATbool B_isBooleanConstant(B_Boolean arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, B_patternBooleanConstant, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool B_isBooleanOr(B_Boolean arg) */

inline ATbool B_isBooleanOr(B_Boolean arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, B_patternBooleanOr, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool B_isBooleanAnd(B_Boolean arg) */

inline ATbool B_isBooleanAnd(B_Boolean arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, B_patternBooleanAnd, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool B_isBooleanNot(B_Boolean arg) */

inline ATbool B_isBooleanNot(B_Boolean arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, B_patternBooleanNot, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool B_isBooleanBracket(B_Boolean arg) */

inline ATbool B_isBooleanBracket(B_Boolean arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, B_patternBooleanBracket, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool B_hasBooleanBoolCon(B_Boolean arg) */

ATbool B_hasBooleanBoolCon(B_Boolean arg)
{
  if (B_isBooleanConstant(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  B_BoolCon B_getBooleanBoolCon(B_Boolean arg) */

B_BoolCon B_getBooleanBoolCon(B_Boolean arg)
{
  
    return (B_BoolCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  B_Boolean B_setBooleanBoolCon(B_Boolean arg, B_BoolCon BoolCon) */

B_Boolean B_setBooleanBoolCon(B_Boolean arg, B_BoolCon BoolCon)
{
  if (B_isBooleanConstant(arg)) {
    return (B_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)BoolCon, 0), 1);
  }

  ATabort("Boolean has no BoolCon: %t\n", arg);
  return (B_Boolean)NULL;
}

/*}}}  */
/*{{{  ATbool B_hasBooleanLhs(B_Boolean arg) */

ATbool B_hasBooleanLhs(B_Boolean arg)
{
  if (B_isBooleanOr(arg)) {
    return ATtrue;
  }
  else if (B_isBooleanAnd(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  B_Boolean B_getBooleanLhs(B_Boolean arg) */

B_Boolean B_getBooleanLhs(B_Boolean arg)
{
  if (B_isBooleanOr(arg)) {
    return (B_Boolean)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (B_Boolean)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  B_Boolean B_setBooleanLhs(B_Boolean arg, B_Boolean lhs) */

B_Boolean B_setBooleanLhs(B_Boolean arg, B_Boolean lhs)
{
  if (B_isBooleanOr(arg)) {
    return (B_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)lhs, 0), 1);
  }
  else if (B_isBooleanAnd(arg)) {
    return (B_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)lhs, 0), 1);
  }

  ATabort("Boolean has no Lhs: %t\n", arg);
  return (B_Boolean)NULL;
}

/*}}}  */
/*{{{  ATbool B_hasBooleanWsAfterLhs(B_Boolean arg) */

ATbool B_hasBooleanWsAfterLhs(B_Boolean arg)
{
  if (B_isBooleanOr(arg)) {
    return ATtrue;
  }
  else if (B_isBooleanAnd(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  B_OptLayout B_getBooleanWsAfterLhs(B_Boolean arg) */

B_OptLayout B_getBooleanWsAfterLhs(B_Boolean arg)
{
  if (B_isBooleanOr(arg)) {
    return (B_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else 
    return (B_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  B_Boolean B_setBooleanWsAfterLhs(B_Boolean arg, B_OptLayout wsAfterLhs) */

B_Boolean B_setBooleanWsAfterLhs(B_Boolean arg, B_OptLayout wsAfterLhs)
{
  if (B_isBooleanOr(arg)) {
    return (B_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLhs, 1), 1);
  }
  else if (B_isBooleanAnd(arg)) {
    return (B_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLhs, 1), 1);
  }

  ATabort("Boolean has no WsAfterLhs: %t\n", arg);
  return (B_Boolean)NULL;
}

/*}}}  */
/*{{{  ATbool B_hasBooleanWsAfterBar(B_Boolean arg) */

ATbool B_hasBooleanWsAfterBar(B_Boolean arg)
{
  if (B_isBooleanOr(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  B_OptLayout B_getBooleanWsAfterBar(B_Boolean arg) */

B_OptLayout B_getBooleanWsAfterBar(B_Boolean arg)
{
  
    return (B_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  B_Boolean B_setBooleanWsAfterBar(B_Boolean arg, B_OptLayout wsAfterBar) */

B_Boolean B_setBooleanWsAfterBar(B_Boolean arg, B_OptLayout wsAfterBar)
{
  if (B_isBooleanOr(arg)) {
    return (B_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterBar, 3), 1);
  }

  ATabort("Boolean has no WsAfterBar: %t\n", arg);
  return (B_Boolean)NULL;
}

/*}}}  */
/*{{{  ATbool B_hasBooleanRhs(B_Boolean arg) */

ATbool B_hasBooleanRhs(B_Boolean arg)
{
  if (B_isBooleanOr(arg)) {
    return ATtrue;
  }
  else if (B_isBooleanAnd(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  B_Boolean B_getBooleanRhs(B_Boolean arg) */

B_Boolean B_getBooleanRhs(B_Boolean arg)
{
  if (B_isBooleanOr(arg)) {
    return (B_Boolean)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (B_Boolean)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  B_Boolean B_setBooleanRhs(B_Boolean arg, B_Boolean rhs) */

B_Boolean B_setBooleanRhs(B_Boolean arg, B_Boolean rhs)
{
  if (B_isBooleanOr(arg)) {
    return (B_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)rhs, 4), 1);
  }
  else if (B_isBooleanAnd(arg)) {
    return (B_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)rhs, 4), 1);
  }

  ATabort("Boolean has no Rhs: %t\n", arg);
  return (B_Boolean)NULL;
}

/*}}}  */
/*{{{  ATbool B_hasBooleanWsAfterAmp(B_Boolean arg) */

ATbool B_hasBooleanWsAfterAmp(B_Boolean arg)
{
  if (B_isBooleanAnd(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  B_OptLayout B_getBooleanWsAfterAmp(B_Boolean arg) */

B_OptLayout B_getBooleanWsAfterAmp(B_Boolean arg)
{
  
    return (B_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  B_Boolean B_setBooleanWsAfterAmp(B_Boolean arg, B_OptLayout wsAfterAmp) */

B_Boolean B_setBooleanWsAfterAmp(B_Boolean arg, B_OptLayout wsAfterAmp)
{
  if (B_isBooleanAnd(arg)) {
    return (B_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterAmp, 3), 1);
  }

  ATabort("Boolean has no WsAfterAmp: %t\n", arg);
  return (B_Boolean)NULL;
}

/*}}}  */
/*{{{  ATbool B_hasBooleanWsAfterNot(B_Boolean arg) */

ATbool B_hasBooleanWsAfterNot(B_Boolean arg)
{
  if (B_isBooleanNot(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  B_OptLayout B_getBooleanWsAfterNot(B_Boolean arg) */

B_OptLayout B_getBooleanWsAfterNot(B_Boolean arg)
{
  
    return (B_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  B_Boolean B_setBooleanWsAfterNot(B_Boolean arg, B_OptLayout wsAfterNot) */

B_Boolean B_setBooleanWsAfterNot(B_Boolean arg, B_OptLayout wsAfterNot)
{
  if (B_isBooleanNot(arg)) {
    return (B_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterNot, 1), 1);
  }

  ATabort("Boolean has no WsAfterNot: %t\n", arg);
  return (B_Boolean)NULL;
}

/*}}}  */
/*{{{  ATbool B_hasBooleanWsAfterParenOpen(B_Boolean arg) */

ATbool B_hasBooleanWsAfterParenOpen(B_Boolean arg)
{
  if (B_isBooleanNot(arg)) {
    return ATtrue;
  }
  else if (B_isBooleanBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  B_OptLayout B_getBooleanWsAfterParenOpen(B_Boolean arg) */

B_OptLayout B_getBooleanWsAfterParenOpen(B_Boolean arg)
{
  if (B_isBooleanNot(arg)) {
    return (B_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (B_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  B_Boolean B_setBooleanWsAfterParenOpen(B_Boolean arg, B_OptLayout wsAfterParenOpen) */

B_Boolean B_setBooleanWsAfterParenOpen(B_Boolean arg, B_OptLayout wsAfterParenOpen)
{
  if (B_isBooleanNot(arg)) {
    return (B_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenOpen, 3), 1);
  }
  else if (B_isBooleanBracket(arg)) {
    return (B_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenOpen, 1), 1);
  }

  ATabort("Boolean has no WsAfterParenOpen: %t\n", arg);
  return (B_Boolean)NULL;
}

/*}}}  */
/*{{{  ATbool B_hasBooleanBoolean(B_Boolean arg) */

ATbool B_hasBooleanBoolean(B_Boolean arg)
{
  if (B_isBooleanNot(arg)) {
    return ATtrue;
  }
  else if (B_isBooleanBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  B_Boolean B_getBooleanBoolean(B_Boolean arg) */

B_Boolean B_getBooleanBoolean(B_Boolean arg)
{
  if (B_isBooleanNot(arg)) {
    return (B_Boolean)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (B_Boolean)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  B_Boolean B_setBooleanBoolean(B_Boolean arg, B_Boolean Boolean) */

B_Boolean B_setBooleanBoolean(B_Boolean arg, B_Boolean Boolean)
{
  if (B_isBooleanNot(arg)) {
    return (B_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Boolean, 4), 1);
  }
  else if (B_isBooleanBracket(arg)) {
    return (B_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Boolean, 2), 1);
  }

  ATabort("Boolean has no Boolean: %t\n", arg);
  return (B_Boolean)NULL;
}

/*}}}  */
/*{{{  ATbool B_hasBooleanWsAfterBoolean(B_Boolean arg) */

ATbool B_hasBooleanWsAfterBoolean(B_Boolean arg)
{
  if (B_isBooleanNot(arg)) {
    return ATtrue;
  }
  else if (B_isBooleanBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  B_OptLayout B_getBooleanWsAfterBoolean(B_Boolean arg) */

B_OptLayout B_getBooleanWsAfterBoolean(B_Boolean arg)
{
  if (B_isBooleanNot(arg)) {
    return (B_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else 
    return (B_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  B_Boolean B_setBooleanWsAfterBoolean(B_Boolean arg, B_OptLayout wsAfterBoolean) */

B_Boolean B_setBooleanWsAfterBoolean(B_Boolean arg, B_OptLayout wsAfterBoolean)
{
  if (B_isBooleanNot(arg)) {
    return (B_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterBoolean, 5), 1);
  }
  else if (B_isBooleanBracket(arg)) {
    return (B_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterBoolean, 3), 1);
  }

  ATabort("Boolean has no WsAfterBoolean: %t\n", arg);
  return (B_Boolean)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  B_Start accessors */

/*{{{  ATbool B_isValidStart(B_Start arg) */

ATbool B_isValidStart(B_Start arg)
{
  if (B_isStartBoolCon(arg)) {
    return ATtrue;
  }
  else if (B_isStartBoolean(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool B_isStartBoolCon(B_Start arg) */

inline ATbool B_isStartBoolCon(B_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, B_patternStartBoolCon, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool B_isStartBoolean(B_Start arg) */

inline ATbool B_isStartBoolean(B_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, B_patternStartBoolean, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool B_hasStartWsBefore(B_Start arg) */

ATbool B_hasStartWsBefore(B_Start arg)
{
  if (B_isStartBoolCon(arg)) {
    return ATtrue;
  }
  else if (B_isStartBoolean(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  B_OptLayout B_getStartWsBefore(B_Start arg) */

B_OptLayout B_getStartWsBefore(B_Start arg)
{
  if (B_isStartBoolCon(arg)) {
    return (B_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else 
    return (B_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
}

/*}}}  */
/*{{{  B_Start B_setStartWsBefore(B_Start arg, B_OptLayout wsBefore) */

B_Start B_setStartWsBefore(B_Start arg, B_OptLayout wsBefore)
{
  if (B_isStartBoolCon(arg)) {
    return (B_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (B_isStartBoolean(arg)) {
    return (B_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }

  ATabort("Start has no WsBefore: %t\n", arg);
  return (B_Start)NULL;
}

/*}}}  */
/*{{{  ATbool B_hasStartTopBoolCon(B_Start arg) */

ATbool B_hasStartTopBoolCon(B_Start arg)
{
  if (B_isStartBoolCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  B_BoolCon B_getStartTopBoolCon(B_Start arg) */

B_BoolCon B_getStartTopBoolCon(B_Start arg)
{
  
    return (B_BoolCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  B_Start B_setStartTopBoolCon(B_Start arg, B_BoolCon topBoolCon) */

B_Start B_setStartTopBoolCon(B_Start arg, B_BoolCon topBoolCon)
{
  if (B_isStartBoolCon(arg)) {
    return (B_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topBoolCon, 1), 1), 0);
  }

  ATabort("Start has no TopBoolCon: %t\n", arg);
  return (B_Start)NULL;
}

/*}}}  */
/*{{{  ATbool B_hasStartWsAfter(B_Start arg) */

ATbool B_hasStartWsAfter(B_Start arg)
{
  if (B_isStartBoolCon(arg)) {
    return ATtrue;
  }
  else if (B_isStartBoolean(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  B_OptLayout B_getStartWsAfter(B_Start arg) */

B_OptLayout B_getStartWsAfter(B_Start arg)
{
  if (B_isStartBoolCon(arg)) {
    return (B_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else 
    return (B_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
}

/*}}}  */
/*{{{  B_Start B_setStartWsAfter(B_Start arg, B_OptLayout wsAfter) */

B_Start B_setStartWsAfter(B_Start arg, B_OptLayout wsAfter)
{
  if (B_isStartBoolCon(arg)) {
    return (B_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (B_isStartBoolean(arg)) {
    return (B_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }

  ATabort("Start has no WsAfter: %t\n", arg);
  return (B_Start)NULL;
}

/*}}}  */
/*{{{  ATbool B_hasStartAmbCnt(B_Start arg) */

ATbool B_hasStartAmbCnt(B_Start arg)
{
  if (B_isStartBoolCon(arg)) {
    return ATtrue;
  }
  else if (B_isStartBoolean(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int B_getStartAmbCnt(B_Start arg) */

int B_getStartAmbCnt(B_Start arg)
{
  if (B_isStartBoolCon(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  B_Start B_setStartAmbCnt(B_Start arg, int ambCnt) */

B_Start B_setStartAmbCnt(B_Start arg, int ambCnt)
{
  if (B_isStartBoolCon(arg)) {
    return (B_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (B_isStartBoolean(arg)) {
    return (B_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }

  ATabort("Start has no AmbCnt: %t\n", arg);
  return (B_Start)NULL;
}

/*}}}  */
/*{{{  ATbool B_hasStartTopBoolean(B_Start arg) */

ATbool B_hasStartTopBoolean(B_Start arg)
{
  if (B_isStartBoolean(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  B_Boolean B_getStartTopBoolean(B_Start arg) */

B_Boolean B_getStartTopBoolean(B_Start arg)
{
  
    return (B_Boolean)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  B_Start B_setStartTopBoolean(B_Start arg, B_Boolean topBoolean) */

B_Start B_setStartTopBoolean(B_Start arg, B_Boolean topBoolean)
{
  if (B_isStartBoolean(arg)) {
    return (B_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topBoolean, 1), 1), 0);
  }

  ATabort("Start has no TopBoolean: %t\n", arg);
  return (B_Start)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  B_OptLayout accessors */

/*{{{  ATbool B_isValidOptLayout(B_OptLayout arg) */

ATbool B_isValidOptLayout(B_OptLayout arg)
{
  if (B_isOptLayoutAbsent(arg)) {
    return ATtrue;
  }
  else if (B_isOptLayoutPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool B_isOptLayoutAbsent(B_OptLayout arg) */

inline ATbool B_isOptLayoutAbsent(B_OptLayout arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, B_patternOptLayoutAbsent);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool B_isOptLayoutPresent(B_OptLayout arg) */

inline ATbool B_isOptLayoutPresent(B_OptLayout arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, B_patternOptLayoutPresent, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool B_hasOptLayoutChars(B_OptLayout arg) */

ATbool B_hasOptLayoutChars(B_OptLayout arg)
{
  if (B_isOptLayoutPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  B_CHARLIST B_getOptLayoutChars(B_OptLayout arg) */

B_CHARLIST B_getOptLayoutChars(B_OptLayout arg)
{
  
    return (B_CHARLIST)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  B_OptLayout B_setOptLayoutChars(B_OptLayout arg, B_CHARLIST chars) */

B_OptLayout B_setOptLayoutChars(B_OptLayout arg, B_CHARLIST chars)
{
  if (B_isOptLayoutPresent(arg)) {
    return (B_OptLayout)ATsetArgument((ATermAppl)arg, (ATerm)chars, 1);
  }

  ATabort("OptLayout has no Chars: %t\n", arg);
  return (B_OptLayout)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  B_BoolCon B_visitBoolCon(B_BoolCon arg) */

B_BoolCon B_visitBoolCon(B_BoolCon arg)
{
  if (B_isBoolConTrue(arg)) {
    return B_makeBoolConTrue();
  }
  if (B_isBoolConFalse(arg)) {
    return B_makeBoolConFalse();
  }
  ATabort("not a BoolCon: %t\n", arg);
  return (B_BoolCon)NULL;
}

/*}}}  */
/*{{{  B_Boolean B_visitBoolean(B_Boolean arg, B_BoolCon (*acceptBoolCon)(B_BoolCon), B_OptLayout (*acceptWsAfterLhs)(B_OptLayout), B_OptLayout (*acceptWsAfterBar)(B_OptLayout), B_OptLayout (*acceptWsAfterAmp)(B_OptLayout), B_OptLayout (*acceptWsAfterNot)(B_OptLayout), B_OptLayout (*acceptWsAfterParenOpen)(B_OptLayout), B_OptLayout (*acceptWsAfterBoolean)(B_OptLayout)) */

B_Boolean B_visitBoolean(B_Boolean arg, B_BoolCon (*acceptBoolCon)(B_BoolCon), B_OptLayout (*acceptWsAfterLhs)(B_OptLayout), B_OptLayout (*acceptWsAfterBar)(B_OptLayout), B_OptLayout (*acceptWsAfterAmp)(B_OptLayout), B_OptLayout (*acceptWsAfterNot)(B_OptLayout), B_OptLayout (*acceptWsAfterParenOpen)(B_OptLayout), B_OptLayout (*acceptWsAfterBoolean)(B_OptLayout))
{
  if (B_isBooleanConstant(arg)) {
    return B_makeBooleanConstant(
        acceptBoolCon ? acceptBoolCon(B_getBooleanBoolCon(arg)) : B_getBooleanBoolCon(arg));
  }
  if (B_isBooleanOr(arg)) {
    return B_makeBooleanOr(
        B_visitBoolean(B_getBooleanLhs(arg), acceptBoolCon, acceptWsAfterLhs, acceptWsAfterBar, acceptWsAfterAmp, acceptWsAfterNot, acceptWsAfterParenOpen, acceptWsAfterBoolean),
        acceptWsAfterLhs ? acceptWsAfterLhs(B_getBooleanWsAfterLhs(arg)) : B_getBooleanWsAfterLhs(arg),
        acceptWsAfterBar ? acceptWsAfterBar(B_getBooleanWsAfterBar(arg)) : B_getBooleanWsAfterBar(arg),
        B_visitBoolean(B_getBooleanRhs(arg), acceptBoolCon, acceptWsAfterLhs, acceptWsAfterBar, acceptWsAfterAmp, acceptWsAfterNot, acceptWsAfterParenOpen, acceptWsAfterBoolean));
  }
  if (B_isBooleanAnd(arg)) {
    return B_makeBooleanAnd(
        B_visitBoolean(B_getBooleanLhs(arg), acceptBoolCon, acceptWsAfterLhs, acceptWsAfterBar, acceptWsAfterAmp, acceptWsAfterNot, acceptWsAfterParenOpen, acceptWsAfterBoolean),
        acceptWsAfterLhs ? acceptWsAfterLhs(B_getBooleanWsAfterLhs(arg)) : B_getBooleanWsAfterLhs(arg),
        acceptWsAfterAmp ? acceptWsAfterAmp(B_getBooleanWsAfterAmp(arg)) : B_getBooleanWsAfterAmp(arg),
        B_visitBoolean(B_getBooleanRhs(arg), acceptBoolCon, acceptWsAfterLhs, acceptWsAfterBar, acceptWsAfterAmp, acceptWsAfterNot, acceptWsAfterParenOpen, acceptWsAfterBoolean));
  }
  if (B_isBooleanNot(arg)) {
    return B_makeBooleanNot(
        acceptWsAfterNot ? acceptWsAfterNot(B_getBooleanWsAfterNot(arg)) : B_getBooleanWsAfterNot(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(B_getBooleanWsAfterParenOpen(arg)) : B_getBooleanWsAfterParenOpen(arg),
        B_visitBoolean(B_getBooleanBoolean(arg), acceptBoolCon, acceptWsAfterLhs, acceptWsAfterBar, acceptWsAfterAmp, acceptWsAfterNot, acceptWsAfterParenOpen, acceptWsAfterBoolean),
        acceptWsAfterBoolean ? acceptWsAfterBoolean(B_getBooleanWsAfterBoolean(arg)) : B_getBooleanWsAfterBoolean(arg));
  }
  if (B_isBooleanBracket(arg)) {
    return B_makeBooleanBracket(
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(B_getBooleanWsAfterParenOpen(arg)) : B_getBooleanWsAfterParenOpen(arg),
        B_visitBoolean(B_getBooleanBoolean(arg), acceptBoolCon, acceptWsAfterLhs, acceptWsAfterBar, acceptWsAfterAmp, acceptWsAfterNot, acceptWsAfterParenOpen, acceptWsAfterBoolean),
        acceptWsAfterBoolean ? acceptWsAfterBoolean(B_getBooleanWsAfterBoolean(arg)) : B_getBooleanWsAfterBoolean(arg));
  }
  ATabort("not a Boolean: %t\n", arg);
  return (B_Boolean)NULL;
}

/*}}}  */
/*{{{  B_Start B_visitStart(B_Start arg, B_OptLayout (*acceptWsBefore)(B_OptLayout), B_BoolCon (*acceptTopBoolCon)(B_BoolCon), B_OptLayout (*acceptWsAfter)(B_OptLayout), int (*acceptAmbCnt)(int), B_Boolean (*acceptTopBoolean)(B_Boolean)) */

B_Start B_visitStart(B_Start arg, B_OptLayout (*acceptWsBefore)(B_OptLayout), B_BoolCon (*acceptTopBoolCon)(B_BoolCon), B_OptLayout (*acceptWsAfter)(B_OptLayout), int (*acceptAmbCnt)(int), B_Boolean (*acceptTopBoolean)(B_Boolean))
{
  if (B_isStartBoolCon(arg)) {
    return B_makeStartBoolCon(
        acceptWsBefore ? acceptWsBefore(B_getStartWsBefore(arg)) : B_getStartWsBefore(arg),
        acceptTopBoolCon ? acceptTopBoolCon(B_getStartTopBoolCon(arg)) : B_getStartTopBoolCon(arg),
        acceptWsAfter ? acceptWsAfter(B_getStartWsAfter(arg)) : B_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(B_getStartAmbCnt(arg)) : B_getStartAmbCnt(arg));
  }
  if (B_isStartBoolean(arg)) {
    return B_makeStartBoolean(
        acceptWsBefore ? acceptWsBefore(B_getStartWsBefore(arg)) : B_getStartWsBefore(arg),
        acceptTopBoolean ? acceptTopBoolean(B_getStartTopBoolean(arg)) : B_getStartTopBoolean(arg),
        acceptWsAfter ? acceptWsAfter(B_getStartWsAfter(arg)) : B_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(B_getStartAmbCnt(arg)) : B_getStartAmbCnt(arg));
  }
  ATabort("not a Start: %t\n", arg);
  return (B_Start)NULL;
}

/*}}}  */
/*{{{  B_OptLayout B_visitOptLayout(B_OptLayout arg, B_CHARLIST (*acceptChars)(B_CHARLIST)) */

B_OptLayout B_visitOptLayout(B_OptLayout arg, B_CHARLIST (*acceptChars)(B_CHARLIST))
{
  if (B_isOptLayoutAbsent(arg)) {
    return B_makeOptLayoutAbsent();
  }
  if (B_isOptLayoutPresent(arg)) {
    return B_makeOptLayoutPresent(
        acceptChars ? acceptChars(B_getOptLayoutChars(arg)) : B_getOptLayoutChars(arg));
  }
  ATabort("not a OptLayout: %t\n", arg);
  return (B_OptLayout)NULL;
}

/*}}}  */

/*}}}  */
