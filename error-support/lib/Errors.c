#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "Errors.h"

/*{{{  conversion functions */

ATerm ME_stringToChars(const char *str)
{
  int len = strlen(str);
  int i;
  ATermList result = ATempty;

  for (i = len - 1; i >= 0; i--) {
    result = ATinsert(result, (ATerm) ATmakeInt(str[i]));
  }

  return (ATerm) result;
}

char *ME_charsToString(ATerm arg)
{
  ATermList list = (ATermList) arg;
  int len = ATgetLength(list);
  int i;
  char *str;

  str = (char *) malloc(len+1);
  if (str == NULL) {
      return NULL;
  }

  for (i = 0; !ATisEmpty(list); list = ATgetNext(list), i++) {
    str[i] = (char) ATgetInt((ATermInt) ATgetFirst(list));
  }
  str[i] = '\0';

  return str;
}


/*}}}  */

/*{{{  typedefs */

typedef struct ATerm _ME_NatCon;
typedef struct ATerm _ME_String;

/*}}}  */

/*{{{  void ME_initErrorsApi(void) */

void ME_initErrorsApi(void)
{
  init_Errors_dict();
}

/*}}}  */

/*{{{  term conversion functions */

/*{{{  ME_NatCon ME_NatConFromTerm(ATerm t) */

ME_NatCon ME_NatConFromTerm(ATerm t)
{
  return (ME_NatCon)t;
}

/*}}}  */
/*{{{  ATerm ME_NatConToTerm(ME_NatCon arg) */

ATerm ME_NatConToTerm(ME_NatCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ME_String ME_StringFromTerm(ATerm t) */

ME_String ME_StringFromTerm(ATerm t)
{
  return (ME_String)t;
}

/*}}}  */
/*{{{  ATerm ME_StringToTerm(ME_String arg) */

ATerm ME_StringToTerm(ME_String arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*}}}  */
/*{{{  list functions */


/*}}}  */
/*{{{  constructors */

/*{{{  ME_NatCon ME_makeNatConNatCon(char* string) */

ME_NatCon ME_makeNatConNatCon(char* string)
{
  return (ME_NatCon)(ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue));
}

/*}}}  */
/*{{{  ME_String ME_makeStringString(char* string) */

ME_String ME_makeStringString(char* string)
{
  return (ME_String)(ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue));
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool ME_isEqualNatCon(ME_NatCon arg0, ME_NatCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ME_isEqualString(ME_String arg0, ME_String arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  ME_NatCon accessors */

/*{{{  ATbool ME_isValidNatCon(ME_NatCon arg) */

ATbool ME_isValidNatCon(ME_NatCon arg)
{
  if (ME_isNatConNatCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ME_isNatConNatCon(ME_NatCon arg) */

inline ATbool ME_isNatConNatCon(ME_NatCon arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ME_patternNatConNatCon, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool ME_hasNatConString(ME_NatCon arg) */

ATbool ME_hasNatConString(ME_NatCon arg)
{
  if (ME_isNatConNatCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* ME_getNatConString(ME_NatCon arg) */

char* ME_getNatConString(ME_NatCon arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) arg));
}

/*}}}  */
/*{{{  ME_NatCon ME_setNatConString(ME_NatCon arg, char* string) */

ME_NatCon ME_setNatConString(ME_NatCon arg, char* string)
{
  if (ME_isNatConNatCon(arg)) {
    return (ME_NatCon)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue)));
  }

  ATabort("NatCon has no String: %t\n", arg);
  return (ME_NatCon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ME_String accessors */

/*{{{  ATbool ME_isValidString(ME_String arg) */

ATbool ME_isValidString(ME_String arg)
{
  if (ME_isStringString(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ME_isStringString(ME_String arg) */

inline ATbool ME_isStringString(ME_String arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ME_patternStringString, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool ME_hasStringString(ME_String arg) */

ATbool ME_hasStringString(ME_String arg)
{
  if (ME_isStringString(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* ME_getStringString(ME_String arg) */

char* ME_getStringString(ME_String arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) arg));
}

/*}}}  */
/*{{{  ME_String ME_setStringString(ME_String arg, char* string) */

ME_String ME_setStringString(ME_String arg, char* string)
{
  if (ME_isStringString(arg)) {
    return (ME_String)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(string, 0, ATtrue)));
  }

  ATabort("String has no String: %t\n", arg);
  return (ME_String)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  ME_NatCon ME_visitNatCon(ME_NatCon arg, char* (*acceptString)(char*)) */

ME_NatCon ME_visitNatCon(ME_NatCon arg, char* (*acceptString)(char*))
{
  if (ME_isNatConNatCon(arg)) {
    return ME_makeNatConNatCon(
        acceptString ? acceptString(ME_getNatConString(arg)) : ME_getNatConString(arg));
  }
  ATabort("not a NatCon: %t\n", arg);
  return (ME_NatCon)NULL;
}

/*}}}  */
/*{{{  ME_String ME_visitString(ME_String arg, char* (*acceptString)(char*)) */

ME_String ME_visitString(ME_String arg, char* (*acceptString)(char*))
{
  if (ME_isStringString(arg)) {
    return ME_makeStringString(
        acceptString ? acceptString(ME_getStringString(arg)) : ME_getStringString(arg));
  }
  ATabort("not a String: %t\n", arg);
  return (ME_String)NULL;
}

/*}}}  */

/*}}}  */
