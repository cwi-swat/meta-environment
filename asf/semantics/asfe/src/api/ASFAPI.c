#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "ASFAPI.h"

/*{{{  typedefs */

typedef struct ATerm _AA_Call;
typedef struct ATerm _AA_Calls;
typedef struct ATerm _AA_Result;

/*}}}  */

/*{{{  void AA_initASFAPIApi(void) */

void AA_initASFAPIApi(void)
{
  init_ASFAPI_dict();
}

/*}}}  */

/*{{{  term conversion functions */

/*{{{  AA_Call AA_CallFromTerm(ATerm t) */

AA_Call AA_CallFromTerm(ATerm t)
{
  return (AA_Call)t;
}

/*}}}  */
/*{{{  ATerm AA_CallToTerm(AA_Call arg) */

ATerm AA_CallToTerm(AA_Call arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  AA_Calls AA_CallsFromTerm(ATerm t) */

AA_Calls AA_CallsFromTerm(ATerm t)
{
  return (AA_Calls)t;
}

/*}}}  */
/*{{{  ATerm AA_CallsToTerm(AA_Calls arg) */

ATerm AA_CallsToTerm(AA_Calls arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  AA_Result AA_ResultFromTerm(ATerm t) */

AA_Result AA_ResultFromTerm(ATerm t)
{
  return (AA_Result)t;
}

/*}}}  */
/*{{{  ATerm AA_ResultToTerm(AA_Result arg) */

ATerm AA_ResultToTerm(AA_Result arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*}}}  */
/*{{{  constructors */

/*{{{  AA_Call AA_makeCallConstructor(ATerm production) */

AA_Call AA_makeCallConstructor(ATerm production)
{
  return (AA_Call)(ATerm)ATmakeAppl1(AA_afun0, (ATerm)production);
}

/*}}}  */
/*{{{  AA_Call AA_makeCallPredicate(ATerm production) */

AA_Call AA_makeCallPredicate(ATerm production)
{
  return (AA_Call)(ATerm)ATmakeAppl1(AA_afun1, (ATerm)production);
}

/*}}}  */
/*{{{  AA_Call AA_makeCallGetter(ATerm production, int argNr) */

AA_Call AA_makeCallGetter(ATerm production, int argNr)
{
  return (AA_Call)(ATerm)ATmakeAppl2(AA_afun2, (ATerm)production, (ATerm)ATmakeInt(argNr));
}

/*}}}  */
/*{{{  AA_Call AA_makeCallSetter(ATerm production, int argNr) */

AA_Call AA_makeCallSetter(ATerm production, int argNr)
{
  return (AA_Call)(ATerm)ATmakeAppl2(AA_afun3, (ATerm)production, (ATerm)ATmakeInt(argNr));
}

/*}}}  */
/*{{{  AA_Calls AA_makeCallsEmpty() */

AA_Calls AA_makeCallsEmpty()
{
  return (AA_Calls)(ATerm)ATempty;
}

/*}}}  */
/*{{{  AA_Calls AA_makeCallsList(AA_Call head, AA_Calls tail) */

AA_Calls AA_makeCallsList(AA_Call head, AA_Calls tail)
{
  return (AA_Calls)(ATerm)ATinsert((ATermList)tail, (ATerm)head);
}

/*}}}  */
/*{{{  AA_Result AA_makeResultTrue() */

AA_Result AA_makeResultTrue()
{
  return (AA_Result)(ATerm)ATmakeAppl2(AA_afun4, (ATerm)ATmakeAppl3(AA_afun5, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(AA_afun6, (ATerm)ATmakeAppl0(AA_afun7))), (ATerm)ATmakeAppl1(AA_afun8, (ATerm)ATmakeAppl2(AA_afun9, (ATerm)ATmakeAppl1(AA_afun6, (ATerm)ATmakeAppl0(AA_afun7)), (ATerm)ATmakeAppl1(AA_afun6, (ATerm)ATmakeAppl0(AA_afun10)))), (ATerm)ATmakeAppl0(AA_afun11)), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(AA_afun6, (ATerm)ATmakeAppl0(AA_afun7))));
}

/*}}}  */
/*{{{  AA_Result AA_makeResultFalse() */

AA_Result AA_makeResultFalse()
{
  return (AA_Result)(ATerm)ATmakeAppl2(AA_afun4, (ATerm)ATmakeAppl3(AA_afun5, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(AA_afun6, (ATerm)ATmakeAppl0(AA_afun7))), (ATerm)ATmakeAppl1(AA_afun8, (ATerm)ATmakeAppl2(AA_afun9, (ATerm)ATmakeAppl1(AA_afun6, (ATerm)ATmakeAppl0(AA_afun7)), (ATerm)ATmakeAppl1(AA_afun6, (ATerm)ATmakeAppl0(AA_afun10)))), (ATerm)ATmakeAppl0(AA_afun11)), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(AA_afun6, (ATerm)ATmakeAppl0(AA_afun10))));
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool AA_isEqualCall(AA_Call arg0, AA_Call arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool AA_isEqualCalls(AA_Calls arg0, AA_Calls arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool AA_isEqualResult(AA_Result arg0, AA_Result arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  AA_Call accessors */

/*{{{  ATbool AA_isValidCall(AA_Call arg) */

ATbool AA_isValidCall(AA_Call arg)
{
  if (AA_isCallConstructor(arg)) {
    return ATtrue;
  }
  else if (AA_isCallPredicate(arg)) {
    return ATtrue;
  }
  else if (AA_isCallGetter(arg)) {
    return ATtrue;
  }
  else if (AA_isCallSetter(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool AA_isCallConstructor(AA_Call arg) */

inline ATbool AA_isCallConstructor(AA_Call arg)
{
  if (ATgetAFun((ATermAppl)arg) != ATgetAFun(AA_patternCallConstructor)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, AA_patternCallConstructor, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool AA_isCallPredicate(AA_Call arg) */

inline ATbool AA_isCallPredicate(AA_Call arg)
{
  if (ATgetAFun((ATermAppl)arg) != ATgetAFun(AA_patternCallPredicate)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, AA_patternCallPredicate, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool AA_isCallGetter(AA_Call arg) */

inline ATbool AA_isCallGetter(AA_Call arg)
{
  if (ATgetAFun((ATermAppl)arg) != ATgetAFun(AA_patternCallGetter)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, AA_patternCallGetter, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool AA_isCallSetter(AA_Call arg) */

inline ATbool AA_isCallSetter(AA_Call arg)
{
  if (ATgetAFun((ATermAppl)arg) != ATgetAFun(AA_patternCallSetter)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, AA_patternCallSetter, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool AA_hasCallProduction(AA_Call arg) */

ATbool AA_hasCallProduction(AA_Call arg)
{
  if (AA_isCallConstructor(arg)) {
    return ATtrue;
  }
  else if (AA_isCallPredicate(arg)) {
    return ATtrue;
  }
  else if (AA_isCallGetter(arg)) {
    return ATtrue;
  }
  else if (AA_isCallSetter(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATerm AA_getCallProduction(AA_Call arg) */

ATerm AA_getCallProduction(AA_Call arg)
{
  if (AA_isCallConstructor(arg)) {
    return (ATerm)ATgetArgument((ATermAppl)arg, 0);
  }
  else if (AA_isCallPredicate(arg)) {
    return (ATerm)ATgetArgument((ATermAppl)arg, 0);
  }
  else if (AA_isCallGetter(arg)) {
    return (ATerm)ATgetArgument((ATermAppl)arg, 0);
  }
  else 
    return (ATerm)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  AA_Call AA_setCallProduction(AA_Call arg, ATerm production) */

AA_Call AA_setCallProduction(AA_Call arg, ATerm production)
{
  if (AA_isCallConstructor(arg)) {
    return (AA_Call)ATsetArgument((ATermAppl)arg, (ATerm)production, 0);
  }
  else if (AA_isCallPredicate(arg)) {
    return (AA_Call)ATsetArgument((ATermAppl)arg, (ATerm)production, 0);
  }
  else if (AA_isCallGetter(arg)) {
    return (AA_Call)ATsetArgument((ATermAppl)arg, (ATerm)production, 0);
  }
  else if (AA_isCallSetter(arg)) {
    return (AA_Call)ATsetArgument((ATermAppl)arg, (ATerm)production, 0);
  }

  ATabort("Call has no Production: %t\n", arg);
  return (AA_Call)NULL;
}

/*}}}  */
/*{{{  ATbool AA_hasCallArgNr(AA_Call arg) */

ATbool AA_hasCallArgNr(AA_Call arg)
{
  if (AA_isCallGetter(arg)) {
    return ATtrue;
  }
  else if (AA_isCallSetter(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int AA_getCallArgNr(AA_Call arg) */

int AA_getCallArgNr(AA_Call arg)
{
  if (AA_isCallGetter(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  AA_Call AA_setCallArgNr(AA_Call arg, int argNr) */

AA_Call AA_setCallArgNr(AA_Call arg, int argNr)
{
  if (AA_isCallGetter(arg)) {
    return (AA_Call)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(argNr), 1);
  }
  else if (AA_isCallSetter(arg)) {
    return (AA_Call)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(argNr), 1);
  }

  ATabort("Call has no ArgNr: %t\n", arg);
  return (AA_Call)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  AA_Calls accessors */

/*{{{  ATbool AA_isValidCalls(AA_Calls arg) */

ATbool AA_isValidCalls(AA_Calls arg)
{
  if (AA_isCallsEmpty(arg)) {
    return ATtrue;
  }
  else if (AA_isCallsList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool AA_isCallsEmpty(AA_Calls arg) */

inline ATbool AA_isCallsEmpty(AA_Calls arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, AA_patternCallsEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool AA_isCallsList(AA_Calls arg) */

inline ATbool AA_isCallsList(AA_Calls arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, AA_patternCallsList, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool AA_hasCallsHead(AA_Calls arg) */

ATbool AA_hasCallsHead(AA_Calls arg)
{
  if (AA_isCallsList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  AA_Call AA_getCallsHead(AA_Calls arg) */

AA_Call AA_getCallsHead(AA_Calls arg)
{
  
    return (AA_Call)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  AA_Calls AA_setCallsHead(AA_Calls arg, AA_Call head) */

AA_Calls AA_setCallsHead(AA_Calls arg, AA_Call head)
{
  if (AA_isCallsList(arg)) {
    return (AA_Calls)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("Calls has no Head: %t\n", arg);
  return (AA_Calls)NULL;
}

/*}}}  */
/*{{{  ATbool AA_hasCallsTail(AA_Calls arg) */

ATbool AA_hasCallsTail(AA_Calls arg)
{
  if (AA_isCallsList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  AA_Calls AA_getCallsTail(AA_Calls arg) */

AA_Calls AA_getCallsTail(AA_Calls arg)
{
  
    return (AA_Calls)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  AA_Calls AA_setCallsTail(AA_Calls arg, AA_Calls tail) */

AA_Calls AA_setCallsTail(AA_Calls arg, AA_Calls tail)
{
  if (AA_isCallsList(arg)) {
    return (AA_Calls)ATreplaceTail((ATermList)arg, (ATermList)tail, 1);
  }

  ATabort("Calls has no Tail: %t\n", arg);
  return (AA_Calls)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  AA_Result accessors */

/*{{{  ATbool AA_isValidResult(AA_Result arg) */

ATbool AA_isValidResult(AA_Result arg)
{
  if (AA_isResultTrue(arg)) {
    return ATtrue;
  }
  else if (AA_isResultFalse(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool AA_isResultTrue(AA_Result arg) */

inline ATbool AA_isResultTrue(AA_Result arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, AA_patternResultTrue);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool AA_isResultFalse(AA_Result arg) */

inline ATbool AA_isResultFalse(AA_Result arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, AA_patternResultFalse);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  AA_Call AA_visitCall(AA_Call arg, ATerm (*acceptProduction)(ATerm), int (*acceptArgNr)(int)) */

AA_Call AA_visitCall(AA_Call arg, ATerm (*acceptProduction)(ATerm), int (*acceptArgNr)(int))
{
  if (AA_isCallConstructor(arg)) {
    return AA_makeCallConstructor(
        acceptProduction ? acceptProduction(AA_getCallProduction(arg)) : AA_getCallProduction(arg));
  }
  if (AA_isCallPredicate(arg)) {
    return AA_makeCallPredicate(
        acceptProduction ? acceptProduction(AA_getCallProduction(arg)) : AA_getCallProduction(arg));
  }
  if (AA_isCallGetter(arg)) {
    return AA_makeCallGetter(
        acceptProduction ? acceptProduction(AA_getCallProduction(arg)) : AA_getCallProduction(arg),
        acceptArgNr ? acceptArgNr(AA_getCallArgNr(arg)) : AA_getCallArgNr(arg));
  }
  if (AA_isCallSetter(arg)) {
    return AA_makeCallSetter(
        acceptProduction ? acceptProduction(AA_getCallProduction(arg)) : AA_getCallProduction(arg),
        acceptArgNr ? acceptArgNr(AA_getCallArgNr(arg)) : AA_getCallArgNr(arg));
  }
  ATabort("not a Call: %t\n", arg);
  return (AA_Call)NULL;
}

/*}}}  */
/*{{{  AA_Calls AA_visitCalls(AA_Calls arg, AA_Call (*acceptHead)(AA_Call)) */

AA_Calls AA_visitCalls(AA_Calls arg, AA_Call (*acceptHead)(AA_Call))
{
  if (AA_isCallsEmpty(arg)) {
    return AA_makeCallsEmpty();
  }
  if (AA_isCallsList(arg)) {
    return AA_makeCallsList(
        acceptHead ? acceptHead(AA_getCallsHead(arg)) : AA_getCallsHead(arg),
        AA_visitCalls(AA_getCallsTail(arg), acceptHead));
  }
  ATabort("not a Calls: %t\n", arg);
  return (AA_Calls)NULL;
}

/*}}}  */
/*{{{  AA_Result AA_visitResult(AA_Result arg) */

AA_Result AA_visitResult(AA_Result arg)
{
  if (AA_isResultTrue(arg)) {
    return AA_makeResultTrue();
  }
  if (AA_isResultFalse(arg)) {
    return AA_makeResultFalse();
  }
  ATabort("not a Result: %t\n", arg);
  return (AA_Result)NULL;
}

/*}}}  */

/*}}}  */
