#ifndef _ASFAPI_H
#define _ASFAPI_H

/*{{{  includes */

#include <aterm1.h>
#include "ASFAPI_dict.h"

/*}}}  */

/*{{{  typedefs */

typedef struct _AA_Call *AA_Call;
typedef struct _AA_Calls *AA_Calls;
typedef struct _AA_Result *AA_Result;

/*}}}  */

void AA_initASFAPIApi(void);

/*{{{  term conversion functions */

#define AA_makeCallFromTerm(t) (AA_CallFromTerm(t))
AA_Call AA_CallFromTerm(ATerm t);
#define AA_makeTermFromCall(t) (AA_CallToTerm(t))
ATerm AA_CallToTerm(AA_Call arg);
#define AA_makeCallsFromTerm(t) (AA_CallsFromTerm(t))
AA_Calls AA_CallsFromTerm(ATerm t);
#define AA_makeTermFromCalls(t) (AA_CallsToTerm(t))
ATerm AA_CallsToTerm(AA_Calls arg);
#define AA_makeResultFromTerm(t) (AA_ResultFromTerm(t))
AA_Result AA_ResultFromTerm(ATerm t);
#define AA_makeTermFromResult(t) (AA_ResultToTerm(t))
ATerm AA_ResultToTerm(AA_Result arg);

/*}}}  */
/*{{{  constructors */

AA_Call AA_makeCallConstructor(ATerm production);
AA_Call AA_makeCallPredicate(ATerm production);
AA_Call AA_makeCallGetter(ATerm production, int argNr);
AA_Call AA_makeCallSetter(ATerm production, int argNr);
AA_Call AA_makeCallBuiltin(char * function);
AA_Calls AA_makeCallsEmpty();
AA_Calls AA_makeCallsList(AA_Call head, AA_Calls tail);
AA_Result AA_makeResultTrue();
AA_Result AA_makeResultFalse();

/*}}}  */
/*{{{  equality functions */

ATbool AA_isEqualCall(AA_Call arg0, AA_Call arg1);
ATbool AA_isEqualCalls(AA_Calls arg0, AA_Calls arg1);
ATbool AA_isEqualResult(AA_Result arg0, AA_Result arg1);

/*}}}  */
/*{{{  AA_Call accessors */

ATbool AA_isValidCall(AA_Call arg);
inline ATbool AA_isCallConstructor(AA_Call arg);
inline ATbool AA_isCallPredicate(AA_Call arg);
inline ATbool AA_isCallGetter(AA_Call arg);
inline ATbool AA_isCallSetter(AA_Call arg);
inline ATbool AA_isCallBuiltin(AA_Call arg);
ATbool AA_hasCallProduction(AA_Call arg);
ATerm AA_getCallProduction(AA_Call arg);
AA_Call AA_setCallProduction(AA_Call arg, ATerm production);
ATbool AA_hasCallArgNr(AA_Call arg);
int AA_getCallArgNr(AA_Call arg);
AA_Call AA_setCallArgNr(AA_Call arg, int argNr);
ATbool AA_hasCallFunction(AA_Call arg);
char * AA_getCallFunction(AA_Call arg);
AA_Call AA_setCallFunction(AA_Call arg, char * function);

/*}}}  */
/*{{{  AA_Calls accessors */

ATbool AA_isValidCalls(AA_Calls arg);
inline ATbool AA_isCallsEmpty(AA_Calls arg);
inline ATbool AA_isCallsList(AA_Calls arg);
ATbool AA_hasCallsHead(AA_Calls arg);
AA_Call AA_getCallsHead(AA_Calls arg);
AA_Calls AA_setCallsHead(AA_Calls arg, AA_Call head);
ATbool AA_hasCallsTail(AA_Calls arg);
AA_Calls AA_getCallsTail(AA_Calls arg);
AA_Calls AA_setCallsTail(AA_Calls arg, AA_Calls tail);

/*}}}  */
/*{{{  AA_Result accessors */

ATbool AA_isValidResult(AA_Result arg);
inline ATbool AA_isResultTrue(AA_Result arg);
inline ATbool AA_isResultFalse(AA_Result arg);

/*}}}  */
/*{{{  sort visitors */

AA_Call AA_visitCall(AA_Call arg, ATerm (*acceptProduction)(ATerm), int (*acceptArgNr)(int), char * (*acceptFunction)(char *));
AA_Calls AA_visitCalls(AA_Calls arg, AA_Call (*acceptHead)(AA_Call));
AA_Result AA_visitResult(AA_Result arg);

/*}}}  */

#endif /* _ASFAPI_H */
