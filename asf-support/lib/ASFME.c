#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "ASFME.h"

/*{{{  typedefs */

typedef struct ATerm _ASF_Production;
typedef struct ATerm _ASF_Implies;
typedef struct ATerm _ASF_TagId;
typedef struct ATerm _ASF_Conditions;
typedef struct ATerm _ASF_ConditionList;
typedef struct ATerm _ASF_Equations;
typedef struct ATerm _ASF_CondEquationList;
typedef struct ATerm _ASF_CondEquation;
typedef struct ATerm _ASF_Tag;
typedef struct ATerm _ASF_Tree;
typedef struct ATerm _ASF_CHARList;
typedef struct ATerm _ASF_Equation;
typedef struct ATerm _ASF_Condition;
typedef struct ATerm _ASF_TreeAmbs;
typedef struct ATerm _ASF_CHAR;

/*}}}  */

/*{{{  void ASF_initASFMEApi(void) */

void ASF_initASFMEApi(void)
{
  init_ASFME_dict();
}

/*}}}  */

/*{{{  term conversion functions */

/*{{{  ASF_Production ASF_ProductionFromTerm(ATerm t) */

ASF_Production ASF_ProductionFromTerm(ATerm t)
{
  return (ASF_Production)t;
}

/*}}}  */
/*{{{  ATerm ASF_ProductionToTerm(ASF_Production arg) */

ATerm ASF_ProductionToTerm(ASF_Production arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_Implies ASF_ImpliesFromTerm(ATerm t) */

ASF_Implies ASF_ImpliesFromTerm(ATerm t)
{
  return (ASF_Implies)t;
}

/*}}}  */
/*{{{  ATerm ASF_ImpliesToTerm(ASF_Implies arg) */

ATerm ASF_ImpliesToTerm(ASF_Implies arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_TagId ASF_TagIdFromTerm(ATerm t) */

ASF_TagId ASF_TagIdFromTerm(ATerm t)
{
  return (ASF_TagId)t;
}

/*}}}  */
/*{{{  ATerm ASF_TagIdToTerm(ASF_TagId arg) */

ATerm ASF_TagIdToTerm(ASF_TagId arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_Conditions ASF_ConditionsFromTerm(ATerm t) */

ASF_Conditions ASF_ConditionsFromTerm(ATerm t)
{
  return (ASF_Conditions)t;
}

/*}}}  */
/*{{{  ATerm ASF_ConditionsToTerm(ASF_Conditions arg) */

ATerm ASF_ConditionsToTerm(ASF_Conditions arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_ConditionList ASF_ConditionListFromTerm(ATerm t) */

ASF_ConditionList ASF_ConditionListFromTerm(ATerm t)
{
  return (ASF_ConditionList)t;
}

/*}}}  */
/*{{{  ATerm ASF_ConditionListToTerm(ASF_ConditionList arg) */

ATerm ASF_ConditionListToTerm(ASF_ConditionList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_Equations ASF_EquationsFromTerm(ATerm t) */

ASF_Equations ASF_EquationsFromTerm(ATerm t)
{
  return (ASF_Equations)t;
}

/*}}}  */
/*{{{  ATerm ASF_EquationsToTerm(ASF_Equations arg) */

ATerm ASF_EquationsToTerm(ASF_Equations arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_CondEquationList ASF_CondEquationListFromTerm(ATerm t) */

ASF_CondEquationList ASF_CondEquationListFromTerm(ATerm t)
{
  return (ASF_CondEquationList)t;
}

/*}}}  */
/*{{{  ATerm ASF_CondEquationListToTerm(ASF_CondEquationList arg) */

ATerm ASF_CondEquationListToTerm(ASF_CondEquationList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_CondEquation ASF_CondEquationFromTerm(ATerm t) */

ASF_CondEquation ASF_CondEquationFromTerm(ATerm t)
{
  return (ASF_CondEquation)t;
}

/*}}}  */
/*{{{  ATerm ASF_CondEquationToTerm(ASF_CondEquation arg) */

ATerm ASF_CondEquationToTerm(ASF_CondEquation arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_Tag ASF_TagFromTerm(ATerm t) */

ASF_Tag ASF_TagFromTerm(ATerm t)
{
  return (ASF_Tag)t;
}

/*}}}  */
/*{{{  ATerm ASF_TagToTerm(ASF_Tag arg) */

ATerm ASF_TagToTerm(ASF_Tag arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_Tree ASF_TreeFromTerm(ATerm t) */

ASF_Tree ASF_TreeFromTerm(ATerm t)
{
  return (ASF_Tree)t;
}

/*}}}  */
/*{{{  ATerm ASF_TreeToTerm(ASF_Tree arg) */

ATerm ASF_TreeToTerm(ASF_Tree arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_CHARList ASF_CHARListFromTerm(ATerm t) */

ASF_CHARList ASF_CHARListFromTerm(ATerm t)
{
  return (ASF_CHARList)t;
}

/*}}}  */
/*{{{  ATerm ASF_CHARListToTerm(ASF_CHARList arg) */

ATerm ASF_CHARListToTerm(ASF_CHARList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_Equation ASF_EquationFromTerm(ATerm t) */

ASF_Equation ASF_EquationFromTerm(ATerm t)
{
  return (ASF_Equation)t;
}

/*}}}  */
/*{{{  ATerm ASF_EquationToTerm(ASF_Equation arg) */

ATerm ASF_EquationToTerm(ASF_Equation arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_Condition ASF_ConditionFromTerm(ATerm t) */

ASF_Condition ASF_ConditionFromTerm(ATerm t)
{
  return (ASF_Condition)t;
}

/*}}}  */
/*{{{  ATerm ASF_ConditionToTerm(ASF_Condition arg) */

ATerm ASF_ConditionToTerm(ASF_Condition arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_TreeAmbs ASF_TreeAmbsFromTerm(ATerm t) */

ASF_TreeAmbs ASF_TreeAmbsFromTerm(ATerm t)
{
  return (ASF_TreeAmbs)t;
}

/*}}}  */
/*{{{  ATerm ASF_TreeAmbsToTerm(ASF_TreeAmbs arg) */

ATerm ASF_TreeAmbsToTerm(ASF_TreeAmbs arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_CHAR ASF_CHARFromTerm(ATerm t) */

ASF_CHAR ASF_CHARFromTerm(ATerm t)
{
  return (ASF_CHAR)t;
}

/*}}}  */
/*{{{  ATerm ASF_CHARToTerm(ASF_CHAR arg) */

ATerm ASF_CHARToTerm(ASF_CHAR arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*}}}  */
/*{{{  constructors */

/*{{{  ASF_Production ASF_makeProductionLexicalConstructor(char * formalName, ASF_Symbol symbol) */

ASF_Production ASF_makeProductionLexicalConstructor(char * formalName, ASF_Symbol symbol)
{
  return (ASF_Production)(ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun2))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun8))))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun9))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ATmakeAFun(formalName, 0, ATtrue)))), (ATerm)symbol, (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun12)))));
}

/*}}}  */
/*{{{  ASF_Implies ASF_makeImpliesLexToCf(ASF_Lexical lex) */

ASF_Implies ASF_makeImpliesLexToCf(ASF_Lexical lex)
{
  return (ASF_Implies)(ATerm)ATmakeAppl2(ASF_afun13, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun15)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun15))), (ATerm)ATmakeAppl0(ASF_afun16)), (ATerm)ATmakeList1((ATerm)lex));
}

/*}}}  */
/*{{{  ASF_TagId ASF_makeTagIdLexToCf(ASF_Lexical lex) */

ASF_TagId ASF_makeTagIdLexToCf(ASF_Lexical lex)
{
  return (ASF_TagId)(ATerm)ATmakeAppl2(ASF_afun13, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun17)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun17))), (ATerm)ATmakeAppl0(ASF_afun16)), (ATerm)ATmakeList1((ATerm)lex));
}

/*}}}  */
/*{{{  ASF_Conditions ASF_makeConditionsDefault(ASF_ConditionList list) */

ASF_Conditions ASF_makeConditionsDefault(ASF_ConditionList list)
{
  return (ASF_Conditions)(ATerm)ATmakeAppl2(ASF_afun13, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl2(ASF_afun18, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun19)), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun20))))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun21))), (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun22))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(ASF_afun13, (ATerm)ATmakeAppl1(ASF_afun23, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl2(ASF_afun18, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun19)), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun20))))), (ATerm)list)));
}

/*}}}  */
/*{{{  ASF_ConditionList ASF_makeConditionListSingle(ASF_Condition head) */

ASF_ConditionList ASF_makeConditionListSingle(ASF_Condition head)
{
  return (ASF_ConditionList)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  ASF_ConditionList ASF_makeConditionListMany(ASF_Condition head, ASF_Layout wsAfterFirst, char * sep, ASF_Layout wsAfterSep, ASF_ConditionList tail) */

ASF_ConditionList ASF_makeConditionListMany(ASF_Condition head, ASF_Layout wsAfterFirst, char * sep, ASF_Layout wsAfterSep, ASF_ConditionList tail)
{
  return (ASF_ConditionList)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm)wsAfterSep), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)))), (ATerm)wsAfterFirst), (ATerm)head);
}

/*}}}  */
/*{{{  ASF_Equations ASF_makeEquationsAbsent() */

ASF_Equations ASF_makeEquationsAbsent()
{
  return (ASF_Equations)(ATerm)ATmakeAppl2(ASF_afun13, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATempty, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun22))), (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun22))))), (ATerm)ATempty);
}

/*}}}  */
/*{{{  ASF_Equations ASF_makeEquationsPresent(ASF_Layout wsAfterEquations, ASF_CondEquationList list) */

ASF_Equations ASF_makeEquationsPresent(ASF_Layout wsAfterEquations, ASF_CondEquationList list)
{
  return (ASF_Equations)(ATerm)ATmakeAppl2(ASF_afun13, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun24))))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun25))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun22))), (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun22))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(ASF_afun13, (ATerm)ATmakeAppl1(ASF_afun23, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun24))))), (ATerm)list)), (ATerm)wsAfterEquations), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun25))));
}

/*}}}  */
/*{{{  ASF_CondEquationList ASF_makeCondEquationListEmpty() */

ASF_CondEquationList ASF_makeCondEquationListEmpty()
{
  return (ASF_CondEquationList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  ASF_CondEquationList ASF_makeCondEquationListSingle(ASF_CondEquation head) */

ASF_CondEquationList ASF_makeCondEquationListSingle(ASF_CondEquation head)
{
  return (ASF_CondEquationList)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  ASF_CondEquationList ASF_makeCondEquationListMany(ASF_CondEquation head, ASF_Layout wsAfterFirst, ASF_CondEquationList tail) */

ASF_CondEquationList ASF_makeCondEquationListMany(ASF_CondEquation head, ASF_Layout wsAfterFirst, ASF_CondEquationList tail)
{
  return (ASF_CondEquationList)(ATerm)ATinsert(ATinsert((ATermList)tail, (ATerm)wsAfterFirst), (ATerm)head);
}

/*}}}  */
/*{{{  ASF_CondEquation ASF_makeCondEquationSimple(ASF_Tag Tag, ASF_Layout wsAfterTag, ASF_Equation Equation) */

ASF_CondEquation ASF_makeCondEquationSimple(ASF_Tag Tag, ASF_Layout wsAfterTag, ASF_Equation Equation)
{
  return (ASF_CondEquation)(ATerm)ATmakeAppl2(ASF_afun13, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun26)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun27)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun24))), (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun22))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)Equation), (ATerm)wsAfterTag), (ATerm)Tag));
}

/*}}}  */
/*{{{  ASF_CondEquation ASF_makeCondEquationImplies(ASF_Tag Tag, ASF_Layout wsAfterTag, ASF_Conditions Conditions, ASF_Layout wsAfterConditions, ASF_Implies Implies, ASF_Layout wsAfterImplies, ASF_Equation Equation) */

ASF_CondEquation ASF_makeCondEquationImplies(ASF_Tag Tag, ASF_Layout wsAfterTag, ASF_Conditions Conditions, ASF_Layout wsAfterConditions, ASF_Implies Implies, ASF_Layout wsAfterImplies, ASF_Equation Equation)
{
  return (ASF_CondEquation)(ATerm)ATmakeAppl2(ASF_afun13, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun26)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun15)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun21)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun27)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun24))), (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun22))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)Equation), (ATerm)wsAfterImplies), (ATerm)Implies), (ATerm)wsAfterConditions), (ATerm)Conditions), (ATerm)wsAfterTag), (ATerm)Tag));
}

/*}}}  */
/*{{{  ASF_CondEquation ASF_makeCondEquationWhen(ASF_Tag Tag, ASF_Layout wsAfterTag, ASF_Equation Equation, ASF_Layout wsAfterEquation, ASF_Layout wsAfterWhen, ASF_Conditions Conditions) */

ASF_CondEquation ASF_makeCondEquationWhen(ASF_Tag Tag, ASF_Layout wsAfterTag, ASF_Equation Equation, ASF_Layout wsAfterEquation, ASF_Layout wsAfterWhen, ASF_Conditions Conditions)
{
  return (ASF_CondEquation)(ATerm)ATmakeAppl2(ASF_afun13, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun21)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun28))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun26)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun27)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun24))), (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun22))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)Conditions), (ATerm)wsAfterWhen), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun28))), (ATerm)wsAfterEquation), (ATerm)Equation), (ATerm)wsAfterTag), (ATerm)Tag));
}

/*}}}  */
/*{{{  ASF_Tag ASF_makeTagEmpty(ASF_Layout wsAfterBracketOpen) */

ASF_Tag ASF_makeTagEmpty(ASF_Layout wsAfterBracketOpen)
{
  return (ASF_Tag)(ATerm)ATmakeAppl2(ASF_afun13, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun29))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun30))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun27))), (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun22))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun29))), (ATerm)wsAfterBracketOpen), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun30))));
}

/*}}}  */
/*{{{  ASF_Tag ASF_makeTagNotEmpty(ASF_Layout wsAfterBracketOpen, ASF_TagId TagId, ASF_Layout wsAfterTagId) */

ASF_Tag ASF_makeTagNotEmpty(ASF_Layout wsAfterBracketOpen, ASF_TagId TagId, ASF_Layout wsAfterTagId)
{
  return (ASF_Tag)(ATerm)ATmakeAppl2(ASF_afun13, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun29))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun17)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun30))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun27))), (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun22))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun29))), (ATerm)wsAfterTagId), (ATerm)TagId), (ATerm)wsAfterBracketOpen), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun30))));
}

/*}}}  */
/*{{{  ASF_Tree ASF_makeTreeLexicalConstructor(char * formalName, ASF_Symbol symbol, ASF_Tree name, ASF_Layout wsAfterName, ASF_Layout wsAfterParenOpen, ASF_CHARList list, ASF_Layout wsAfterList) */

ASF_Tree ASF_makeTreeLexicalConstructor(char * formalName, ASF_Symbol symbol, ASF_Tree name, ASF_Layout wsAfterName, ASF_Layout wsAfterParenOpen, ASF_CHARList list, ASF_Layout wsAfterList)
{
  return (ASF_Tree)(ATerm)ATmakeAppl2(ASF_afun13, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun2))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun8))))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun9))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ATmakeAFun(formalName, 0, ATtrue)))), (ATerm)symbol, (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun12))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun2))), (ATerm)wsAfterList), (ATerm)ATmakeAppl2(ASF_afun13, (ATerm)ATmakeAppl1(ASF_afun23, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun8))))), (ATerm)list)), (ATerm)wsAfterParenOpen), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun9))), (ATerm)wsAfterName), (ATerm)name));
}

/*}}}  */
/*{{{  ASF_Tree ASF_makeTreeAmbConstructor(ASF_Symbol amb, ASF_Symbol symbol, ASF_Layout wsAfterAmb, ASF_Layout wsAfterParenOpen, ASF_Symbol listSymbol, ASF_TreeAmbs ambs, ASF_Layout wsAfterAmbs) */

ASF_Tree ASF_makeTreeAmbConstructor(ASF_Symbol amb, ASF_Symbol symbol, ASF_Layout wsAfterAmb, ASF_Layout wsAfterParenOpen, ASF_Symbol listSymbol, ASF_TreeAmbs ambs, ASF_Layout wsAfterAmbs)
{
  return (ASF_Tree)(ATerm)ATmakeAppl2(ASF_afun13, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun2))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl2(ASF_afun31, (ATerm)amb, (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun20))))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun9))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun32))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)symbol), (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun33))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun2))), (ATerm)wsAfterAmbs), (ATerm)ATmakeAppl2(ASF_afun13, (ATerm)ATmakeAppl1(ASF_afun23, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl2(ASF_afun31, (ATerm)listSymbol, (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun20))))), (ATerm)ambs)), (ATerm)wsAfterParenOpen), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun9))), (ATerm)wsAfterAmb), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun32))));
}

/*}}}  */
/*{{{  ASF_CHARList ASF_makeCHARListEmpty() */

ASF_CHARList ASF_makeCHARListEmpty()
{
  return (ASF_CHARList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  ASF_CHARList ASF_makeCHARListSingle(ASF_CHAR head) */

ASF_CHARList ASF_makeCHARListSingle(ASF_CHAR head)
{
  return (ASF_CHARList)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  ASF_CHARList ASF_makeCHARListMany(ASF_CHAR head, ASF_Layout wsAfterFirst, ASF_CHARList tail) */

ASF_CHARList ASF_makeCHARListMany(ASF_CHAR head, ASF_Layout wsAfterFirst, ASF_CHARList tail)
{
  return (ASF_CHARList)(ATerm)ATinsert(ATinsert((ATermList)tail, (ATerm)wsAfterFirst), (ATerm)head);
}

/*}}}  */
/*{{{  ASF_Equation ASF_makeEquationDefault(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, ASF_Layout wsAfterLhs, ASF_Layout wsAfterEquals, ASF_Tree rhs) */

ASF_Equation ASF_makeEquationDefault(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, ASF_Layout wsAfterLhs, ASF_Layout wsAfterEquals, ASF_Tree rhs)
{
  return (ASF_Equation)(ATerm)ATmakeAppl2(ASF_afun13, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)rhsSymbol), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun34))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)lhsSymbol), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun26))), (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun33))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)rhs), (ATerm)wsAfterEquals), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun34))), (ATerm)wsAfterLhs), (ATerm)lhs));
}

/*}}}  */
/*{{{  ASF_Condition ASF_makeConditionPositive(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, ASF_Layout wsAfterLhs, ASF_Layout wsAfterEquals, ASF_Tree rhs) */

ASF_Condition ASF_makeConditionPositive(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, ASF_Layout wsAfterLhs, ASF_Layout wsAfterEquals, ASF_Tree rhs)
{
  return (ASF_Condition)(ATerm)ATmakeAppl2(ASF_afun13, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)rhsSymbol), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun34))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)lhsSymbol), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun19))), (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun33))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)rhs), (ATerm)wsAfterEquals), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun34))), (ATerm)wsAfterLhs), (ATerm)lhs));
}

/*}}}  */
/*{{{  ASF_Condition ASF_makeConditionNegative(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, ASF_Layout wsAfterLhs, ASF_Layout wsAfterUnequal, ASF_Tree rhs) */

ASF_Condition ASF_makeConditionNegative(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, ASF_Layout wsAfterLhs, ASF_Layout wsAfterUnequal, ASF_Tree rhs)
{
  return (ASF_Condition)(ATerm)ATmakeAppl2(ASF_afun13, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)rhsSymbol), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun35))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)lhsSymbol), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun19))), (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl0(ASF_afun33))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)rhs), (ATerm)wsAfterUnequal), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun35))), (ATerm)wsAfterLhs), (ATerm)lhs));
}

/*}}}  */
/*{{{  ASF_TreeAmbs ASF_makeTreeAmbsEmpty() */

ASF_TreeAmbs ASF_makeTreeAmbsEmpty()
{
  return (ASF_TreeAmbs)(ATerm)ATempty;
}

/*}}}  */
/*{{{  ASF_TreeAmbs ASF_makeTreeAmbsSingle(ASF_Tree head) */

ASF_TreeAmbs ASF_makeTreeAmbsSingle(ASF_Tree head)
{
  return (ASF_TreeAmbs)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  ASF_TreeAmbs ASF_makeTreeAmbsMany(ASF_Tree head, ASF_Layout wsAfterFirst, char * sep, ASF_Layout wsAfterSep, ASF_TreeAmbs tail) */

ASF_TreeAmbs ASF_makeTreeAmbsMany(ASF_Tree head, ASF_Layout wsAfterFirst, char * sep, ASF_Layout wsAfterSep, ASF_TreeAmbs tail)
{
  return (ASF_TreeAmbs)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm)wsAfterSep), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)))), (ATerm)wsAfterFirst), (ATerm)head);
}

/*}}}  */
/*{{{  ASF_CHAR ASF_makeCHARLexToCf(ASF_Lexical lex) */

ASF_CHAR ASF_makeCHARLexToCf(ASF_Lexical lex)
{
  return (ASF_CHAR)(ATerm)ATmakeAppl2(ASF_afun13, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun8)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun8))), (ATerm)ATmakeAppl0(ASF_afun16)), (ATerm)ATmakeList1((ATerm)lex));
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool ASF_isEqualProduction(ASF_Production arg0, ASF_Production arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualImplies(ASF_Implies arg0, ASF_Implies arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualTagId(ASF_TagId arg0, ASF_TagId arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualConditions(ASF_Conditions arg0, ASF_Conditions arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualConditionList(ASF_ConditionList arg0, ASF_ConditionList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualEquations(ASF_Equations arg0, ASF_Equations arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualCondEquationList(ASF_CondEquationList arg0, ASF_CondEquationList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualCondEquation(ASF_CondEquation arg0, ASF_CondEquation arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualTag(ASF_Tag arg0, ASF_Tag arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualTree(ASF_Tree arg0, ASF_Tree arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualCHARList(ASF_CHARList arg0, ASF_CHARList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualEquation(ASF_Equation arg0, ASF_Equation arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualCondition(ASF_Condition arg0, ASF_Condition arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualTreeAmbs(ASF_TreeAmbs arg0, ASF_TreeAmbs arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualCHAR(ASF_CHAR arg0, ASF_CHAR arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  ASF_Production accessors */

/*{{{  ATbool ASF_isValidProduction(ASF_Production arg) */

ATbool ASF_isValidProduction(ASF_Production arg)
{
  if (ASF_isProductionLexicalConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isProductionLexicalConstructor(ASF_Production arg) */

inline ATbool ASF_isProductionLexicalConstructor(ASF_Production arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ASF_patternProductionLexicalConstructor, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool ASF_hasProductionFormalName(ASF_Production arg) */

ATbool ASF_hasProductionFormalName(ASF_Production arg)
{
  if (ASF_isProductionLexicalConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * ASF_getProductionFormalName(ASF_Production arg) */

char * ASF_getProductionFormalName(ASF_Production arg)
{
  
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 0)), 0)));
}

/*}}}  */
/*{{{  ASF_Production ASF_setProductionFormalName(ASF_Production arg, char * formalName) */

ASF_Production ASF_setProductionFormalName(ASF_Production arg, char * formalName)
{
  if (ASF_isProductionLexicalConstructor(arg)) {
    return (ASF_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 0)), (ATerm)ATmakeAppl0(ATmakeAFun(formalName, 0, ATtrue)), 0), 0), 0);
  }

  ATabort("Production has no FormalName: %t\n", arg);
  return (ASF_Production)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasProductionSymbol(ASF_Production arg) */

ATbool ASF_hasProductionSymbol(ASF_Production arg)
{
  if (ASF_isProductionLexicalConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Symbol ASF_getProductionSymbol(ASF_Production arg) */

ASF_Symbol ASF_getProductionSymbol(ASF_Production arg)
{
  
    return (ASF_Symbol)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  ASF_Production ASF_setProductionSymbol(ASF_Production arg, ASF_Symbol symbol) */

ASF_Production ASF_setProductionSymbol(ASF_Production arg, ASF_Symbol symbol)
{
  if (ASF_isProductionLexicalConstructor(arg)) {
    return (ASF_Production)ATsetArgument((ATermAppl)arg, (ATerm)symbol, 1);
  }

  ATabort("Production has no Symbol: %t\n", arg);
  return (ASF_Production)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_Implies accessors */

/*{{{  ATbool ASF_isValidImplies(ASF_Implies arg) */

ATbool ASF_isValidImplies(ASF_Implies arg)
{
  if (ASF_isImpliesLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isImpliesLexToCf(ASF_Implies arg) */

inline ATbool ASF_isImpliesLexToCf(ASF_Implies arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ASF_patternImpliesLexToCf, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool ASF_hasImpliesLex(ASF_Implies arg) */

ATbool ASF_hasImpliesLex(ASF_Implies arg)
{
  if (ASF_isImpliesLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Lexical ASF_getImpliesLex(ASF_Implies arg) */

ASF_Lexical ASF_getImpliesLex(ASF_Implies arg)
{
  
    return (ASF_Lexical)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  ASF_Implies ASF_setImpliesLex(ASF_Implies arg, ASF_Lexical lex) */

ASF_Implies ASF_setImpliesLex(ASF_Implies arg, ASF_Lexical lex)
{
  if (ASF_isImpliesLexToCf(arg)) {
    return (ASF_Implies)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)lex, 0), 1);
  }

  ATabort("Implies has no Lex: %t\n", arg);
  return (ASF_Implies)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_TagId accessors */

/*{{{  ATbool ASF_isValidTagId(ASF_TagId arg) */

ATbool ASF_isValidTagId(ASF_TagId arg)
{
  if (ASF_isTagIdLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isTagIdLexToCf(ASF_TagId arg) */

inline ATbool ASF_isTagIdLexToCf(ASF_TagId arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ASF_patternTagIdLexToCf, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool ASF_hasTagIdLex(ASF_TagId arg) */

ATbool ASF_hasTagIdLex(ASF_TagId arg)
{
  if (ASF_isTagIdLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Lexical ASF_getTagIdLex(ASF_TagId arg) */

ASF_Lexical ASF_getTagIdLex(ASF_TagId arg)
{
  
    return (ASF_Lexical)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  ASF_TagId ASF_setTagIdLex(ASF_TagId arg, ASF_Lexical lex) */

ASF_TagId ASF_setTagIdLex(ASF_TagId arg, ASF_Lexical lex)
{
  if (ASF_isTagIdLexToCf(arg)) {
    return (ASF_TagId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)lex, 0), 1);
  }

  ATabort("TagId has no Lex: %t\n", arg);
  return (ASF_TagId)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_Conditions accessors */

/*{{{  ATbool ASF_isValidConditions(ASF_Conditions arg) */

ATbool ASF_isValidConditions(ASF_Conditions arg)
{
  if (ASF_isConditionsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isConditionsDefault(ASF_Conditions arg) */

inline ATbool ASF_isConditionsDefault(ASF_Conditions arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ASF_patternConditionsDefault, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool ASF_hasConditionsList(ASF_Conditions arg) */

ATbool ASF_hasConditionsList(ASF_Conditions arg)
{
  if (ASF_isConditionsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_ConditionList ASF_getConditionsList(ASF_Conditions arg) */

ASF_ConditionList ASF_getConditionsList(ASF_Conditions arg)
{
  
    return (ASF_ConditionList)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  ASF_Conditions ASF_setConditionsList(ASF_Conditions arg, ASF_ConditionList list) */

ASF_Conditions ASF_setConditionsList(ASF_Conditions arg, ASF_ConditionList list)
{
  if (ASF_isConditionsDefault(arg)) {
    return (ASF_Conditions)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)list, 1), 0), 1);
  }

  ATabort("Conditions has no List: %t\n", arg);
  return (ASF_Conditions)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_ConditionList accessors */

/*{{{  ATbool ASF_isValidConditionList(ASF_ConditionList arg) */

ATbool ASF_isValidConditionList(ASF_ConditionList arg)
{
  if (ASF_isConditionListSingle(arg)) {
    return ATtrue;
  }
  else if (ASF_isConditionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isConditionListSingle(ASF_ConditionList arg) */

inline ATbool ASF_isConditionListSingle(ASF_ConditionList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternConditionListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isConditionListMany(ASF_ConditionList arg) */

inline ATbool ASF_isConditionListMany(ASF_ConditionList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternConditionListMany, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ASF_hasConditionListHead(ASF_ConditionList arg) */

ATbool ASF_hasConditionListHead(ASF_ConditionList arg)
{
  if (ASF_isConditionListSingle(arg)) {
    return ATtrue;
  }
  else if (ASF_isConditionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Condition ASF_getConditionListHead(ASF_ConditionList arg) */

ASF_Condition ASF_getConditionListHead(ASF_ConditionList arg)
{
  if (ASF_isConditionListSingle(arg)) {
    return (ASF_Condition)ATgetFirst((ATermList)arg);
  }
  else 
    return (ASF_Condition)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  ASF_ConditionList ASF_setConditionListHead(ASF_ConditionList arg, ASF_Condition head) */

ASF_ConditionList ASF_setConditionListHead(ASF_ConditionList arg, ASF_Condition head)
{
  if (ASF_isConditionListSingle(arg)) {
    return (ASF_ConditionList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (ASF_isConditionListMany(arg)) {
    return (ASF_ConditionList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("ConditionList has no Head: %t\n", arg);
  return (ASF_ConditionList)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasConditionListWsAfterFirst(ASF_ConditionList arg) */

ATbool ASF_hasConditionListWsAfterFirst(ASF_ConditionList arg)
{
  if (ASF_isConditionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Layout ASF_getConditionListWsAfterFirst(ASF_ConditionList arg) */

ASF_Layout ASF_getConditionListWsAfterFirst(ASF_ConditionList arg)
{
  
    return (ASF_Layout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  ASF_ConditionList ASF_setConditionListWsAfterFirst(ASF_ConditionList arg, ASF_Layout wsAfterFirst) */

ASF_ConditionList ASF_setConditionListWsAfterFirst(ASF_ConditionList arg, ASF_Layout wsAfterFirst)
{
  if (ASF_isConditionListMany(arg)) {
    return (ASF_ConditionList)ATreplace((ATermList)arg, (ATerm)wsAfterFirst, 1);
  }

  ATabort("ConditionList has no WsAfterFirst: %t\n", arg);
  return (ASF_ConditionList)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasConditionListSep(ASF_ConditionList arg) */

ATbool ASF_hasConditionListSep(ASF_ConditionList arg)
{
  if (ASF_isConditionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * ASF_getConditionListSep(ASF_ConditionList arg) */

char * ASF_getConditionListSep(ASF_ConditionList arg)
{
  
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), 0)));
}

/*}}}  */
/*{{{  ASF_ConditionList ASF_setConditionListSep(ASF_ConditionList arg, char * sep) */

ASF_ConditionList ASF_setConditionListSep(ASF_ConditionList arg, char * sep)
{
  if (ASF_isConditionListMany(arg)) {
    return (ASF_ConditionList)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)), 0), 2);
  }

  ATabort("ConditionList has no Sep: %t\n", arg);
  return (ASF_ConditionList)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasConditionListWsAfterSep(ASF_ConditionList arg) */

ATbool ASF_hasConditionListWsAfterSep(ASF_ConditionList arg)
{
  if (ASF_isConditionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Layout ASF_getConditionListWsAfterSep(ASF_ConditionList arg) */

ASF_Layout ASF_getConditionListWsAfterSep(ASF_ConditionList arg)
{
  
    return (ASF_Layout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  ASF_ConditionList ASF_setConditionListWsAfterSep(ASF_ConditionList arg, ASF_Layout wsAfterSep) */

ASF_ConditionList ASF_setConditionListWsAfterSep(ASF_ConditionList arg, ASF_Layout wsAfterSep)
{
  if (ASF_isConditionListMany(arg)) {
    return (ASF_ConditionList)ATreplace((ATermList)arg, (ATerm)wsAfterSep, 3);
  }

  ATabort("ConditionList has no WsAfterSep: %t\n", arg);
  return (ASF_ConditionList)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasConditionListTail(ASF_ConditionList arg) */

ATbool ASF_hasConditionListTail(ASF_ConditionList arg)
{
  if (ASF_isConditionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_ConditionList ASF_getConditionListTail(ASF_ConditionList arg) */

ASF_ConditionList ASF_getConditionListTail(ASF_ConditionList arg)
{
  
    return (ASF_ConditionList)ATgetTail((ATermList)arg, 4);
}

/*}}}  */
/*{{{  ASF_ConditionList ASF_setConditionListTail(ASF_ConditionList arg, ASF_ConditionList tail) */

ASF_ConditionList ASF_setConditionListTail(ASF_ConditionList arg, ASF_ConditionList tail)
{
  if (ASF_isConditionListMany(arg)) {
    return (ASF_ConditionList)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("ConditionList has no Tail: %t\n", arg);
  return (ASF_ConditionList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_Equations accessors */

/*{{{  ATbool ASF_isValidEquations(ASF_Equations arg) */

ATbool ASF_isValidEquations(ASF_Equations arg)
{
  if (ASF_isEquationsAbsent(arg)) {
    return ATtrue;
  }
  else if (ASF_isEquationsPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isEquationsAbsent(ASF_Equations arg) */

inline ATbool ASF_isEquationsAbsent(ASF_Equations arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternEquationsAbsent);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isEquationsPresent(ASF_Equations arg) */

inline ATbool ASF_isEquationsPresent(ASF_Equations arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternEquationsPresent, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ASF_hasEquationsWsAfterEquations(ASF_Equations arg) */

ATbool ASF_hasEquationsWsAfterEquations(ASF_Equations arg)
{
  if (ASF_isEquationsPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Layout ASF_getEquationsWsAfterEquations(ASF_Equations arg) */

ASF_Layout ASF_getEquationsWsAfterEquations(ASF_Equations arg)
{
  
    return (ASF_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  ASF_Equations ASF_setEquationsWsAfterEquations(ASF_Equations arg, ASF_Layout wsAfterEquations) */

ASF_Equations ASF_setEquationsWsAfterEquations(ASF_Equations arg, ASF_Layout wsAfterEquations)
{
  if (ASF_isEquationsPresent(arg)) {
    return (ASF_Equations)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterEquations, 1), 1);
  }

  ATabort("Equations has no WsAfterEquations: %t\n", arg);
  return (ASF_Equations)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasEquationsList(ASF_Equations arg) */

ATbool ASF_hasEquationsList(ASF_Equations arg)
{
  if (ASF_isEquationsPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_CondEquationList ASF_getEquationsList(ASF_Equations arg) */

ASF_CondEquationList ASF_getEquationsList(ASF_Equations arg)
{
  
    return (ASF_CondEquationList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), 1);
}

/*}}}  */
/*{{{  ASF_Equations ASF_setEquationsList(ASF_Equations arg, ASF_CondEquationList list) */

ASF_Equations ASF_setEquationsList(ASF_Equations arg, ASF_CondEquationList list)
{
  if (ASF_isEquationsPresent(arg)) {
    return (ASF_Equations)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), (ATerm)list, 1), 2), 1);
  }

  ATabort("Equations has no List: %t\n", arg);
  return (ASF_Equations)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_CondEquationList accessors */

/*{{{  ATbool ASF_isValidCondEquationList(ASF_CondEquationList arg) */

ATbool ASF_isValidCondEquationList(ASF_CondEquationList arg)
{
  if (ASF_isCondEquationListEmpty(arg)) {
    return ATtrue;
  }
  else if (ASF_isCondEquationListSingle(arg)) {
    return ATtrue;
  }
  else if (ASF_isCondEquationListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isCondEquationListEmpty(ASF_CondEquationList arg) */

inline ATbool ASF_isCondEquationListEmpty(ASF_CondEquationList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ASF_patternCondEquationListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool ASF_isCondEquationListSingle(ASF_CondEquationList arg) */

inline ATbool ASF_isCondEquationListSingle(ASF_CondEquationList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternCondEquationListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isCondEquationListMany(ASF_CondEquationList arg) */

inline ATbool ASF_isCondEquationListMany(ASF_CondEquationList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternCondEquationListMany, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ASF_hasCondEquationListHead(ASF_CondEquationList arg) */

ATbool ASF_hasCondEquationListHead(ASF_CondEquationList arg)
{
  if (ASF_isCondEquationListSingle(arg)) {
    return ATtrue;
  }
  else if (ASF_isCondEquationListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_CondEquation ASF_getCondEquationListHead(ASF_CondEquationList arg) */

ASF_CondEquation ASF_getCondEquationListHead(ASF_CondEquationList arg)
{
  if (ASF_isCondEquationListSingle(arg)) {
    return (ASF_CondEquation)ATgetFirst((ATermList)arg);
  }
  else 
    return (ASF_CondEquation)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  ASF_CondEquationList ASF_setCondEquationListHead(ASF_CondEquationList arg, ASF_CondEquation head) */

ASF_CondEquationList ASF_setCondEquationListHead(ASF_CondEquationList arg, ASF_CondEquation head)
{
  if (ASF_isCondEquationListSingle(arg)) {
    return (ASF_CondEquationList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (ASF_isCondEquationListMany(arg)) {
    return (ASF_CondEquationList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("CondEquationList has no Head: %t\n", arg);
  return (ASF_CondEquationList)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasCondEquationListWsAfterFirst(ASF_CondEquationList arg) */

ATbool ASF_hasCondEquationListWsAfterFirst(ASF_CondEquationList arg)
{
  if (ASF_isCondEquationListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Layout ASF_getCondEquationListWsAfterFirst(ASF_CondEquationList arg) */

ASF_Layout ASF_getCondEquationListWsAfterFirst(ASF_CondEquationList arg)
{
  
    return (ASF_Layout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  ASF_CondEquationList ASF_setCondEquationListWsAfterFirst(ASF_CondEquationList arg, ASF_Layout wsAfterFirst) */

ASF_CondEquationList ASF_setCondEquationListWsAfterFirst(ASF_CondEquationList arg, ASF_Layout wsAfterFirst)
{
  if (ASF_isCondEquationListMany(arg)) {
    return (ASF_CondEquationList)ATreplace((ATermList)arg, (ATerm)wsAfterFirst, 1);
  }

  ATabort("CondEquationList has no WsAfterFirst: %t\n", arg);
  return (ASF_CondEquationList)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasCondEquationListTail(ASF_CondEquationList arg) */

ATbool ASF_hasCondEquationListTail(ASF_CondEquationList arg)
{
  if (ASF_isCondEquationListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_CondEquationList ASF_getCondEquationListTail(ASF_CondEquationList arg) */

ASF_CondEquationList ASF_getCondEquationListTail(ASF_CondEquationList arg)
{
  
    return (ASF_CondEquationList)ATgetTail((ATermList)arg, 2);
}

/*}}}  */
/*{{{  ASF_CondEquationList ASF_setCondEquationListTail(ASF_CondEquationList arg, ASF_CondEquationList tail) */

ASF_CondEquationList ASF_setCondEquationListTail(ASF_CondEquationList arg, ASF_CondEquationList tail)
{
  if (ASF_isCondEquationListMany(arg)) {
    return (ASF_CondEquationList)ATreplaceTail((ATermList)arg, (ATermList)tail, 2);
  }

  ATabort("CondEquationList has no Tail: %t\n", arg);
  return (ASF_CondEquationList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_CondEquation accessors */

/*{{{  ATbool ASF_isValidCondEquation(ASF_CondEquation arg) */

ATbool ASF_isValidCondEquation(ASF_CondEquation arg)
{
  if (ASF_isCondEquationSimple(arg)) {
    return ATtrue;
  }
  else if (ASF_isCondEquationImplies(arg)) {
    return ATtrue;
  }
  else if (ASF_isCondEquationWhen(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isCondEquationSimple(ASF_CondEquation arg) */

inline ATbool ASF_isCondEquationSimple(ASF_CondEquation arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternCondEquationSimple, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isCondEquationImplies(ASF_CondEquation arg) */

inline ATbool ASF_isCondEquationImplies(ASF_CondEquation arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternCondEquationImplies, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isCondEquationWhen(ASF_CondEquation arg) */

inline ATbool ASF_isCondEquationWhen(ASF_CondEquation arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternCondEquationWhen, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ASF_hasCondEquationTag(ASF_CondEquation arg) */

ATbool ASF_hasCondEquationTag(ASF_CondEquation arg)
{
  if (ASF_isCondEquationSimple(arg)) {
    return ATtrue;
  }
  else if (ASF_isCondEquationImplies(arg)) {
    return ATtrue;
  }
  else if (ASF_isCondEquationWhen(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Tag ASF_getCondEquationTag(ASF_CondEquation arg) */

ASF_Tag ASF_getCondEquationTag(ASF_CondEquation arg)
{
  if (ASF_isCondEquationSimple(arg)) {
    return (ASF_Tag)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (ASF_isCondEquationImplies(arg)) {
    return (ASF_Tag)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (ASF_Tag)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  ASF_CondEquation ASF_setCondEquationTag(ASF_CondEquation arg, ASF_Tag Tag) */

ASF_CondEquation ASF_setCondEquationTag(ASF_CondEquation arg, ASF_Tag Tag)
{
  if (ASF_isCondEquationSimple(arg)) {
    return (ASF_CondEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Tag, 0), 1);
  }
  else if (ASF_isCondEquationImplies(arg)) {
    return (ASF_CondEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Tag, 0), 1);
  }
  else if (ASF_isCondEquationWhen(arg)) {
    return (ASF_CondEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Tag, 0), 1);
  }

  ATabort("CondEquation has no Tag: %t\n", arg);
  return (ASF_CondEquation)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasCondEquationWsAfterTag(ASF_CondEquation arg) */

ATbool ASF_hasCondEquationWsAfterTag(ASF_CondEquation arg)
{
  if (ASF_isCondEquationSimple(arg)) {
    return ATtrue;
  }
  else if (ASF_isCondEquationImplies(arg)) {
    return ATtrue;
  }
  else if (ASF_isCondEquationWhen(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Layout ASF_getCondEquationWsAfterTag(ASF_CondEquation arg) */

ASF_Layout ASF_getCondEquationWsAfterTag(ASF_CondEquation arg)
{
  if (ASF_isCondEquationSimple(arg)) {
    return (ASF_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else if (ASF_isCondEquationImplies(arg)) {
    return (ASF_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else 
    return (ASF_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  ASF_CondEquation ASF_setCondEquationWsAfterTag(ASF_CondEquation arg, ASF_Layout wsAfterTag) */

ASF_CondEquation ASF_setCondEquationWsAfterTag(ASF_CondEquation arg, ASF_Layout wsAfterTag)
{
  if (ASF_isCondEquationSimple(arg)) {
    return (ASF_CondEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterTag, 1), 1);
  }
  else if (ASF_isCondEquationImplies(arg)) {
    return (ASF_CondEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterTag, 1), 1);
  }
  else if (ASF_isCondEquationWhen(arg)) {
    return (ASF_CondEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterTag, 1), 1);
  }

  ATabort("CondEquation has no WsAfterTag: %t\n", arg);
  return (ASF_CondEquation)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasCondEquationEquation(ASF_CondEquation arg) */

ATbool ASF_hasCondEquationEquation(ASF_CondEquation arg)
{
  if (ASF_isCondEquationSimple(arg)) {
    return ATtrue;
  }
  else if (ASF_isCondEquationImplies(arg)) {
    return ATtrue;
  }
  else if (ASF_isCondEquationWhen(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Equation ASF_getCondEquationEquation(ASF_CondEquation arg) */

ASF_Equation ASF_getCondEquationEquation(ASF_CondEquation arg)
{
  if (ASF_isCondEquationSimple(arg)) {
    return (ASF_Equation)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else if (ASF_isCondEquationImplies(arg)) {
    return (ASF_Equation)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6);
  }
  else 
    return (ASF_Equation)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  ASF_CondEquation ASF_setCondEquationEquation(ASF_CondEquation arg, ASF_Equation Equation) */

ASF_CondEquation ASF_setCondEquationEquation(ASF_CondEquation arg, ASF_Equation Equation)
{
  if (ASF_isCondEquationSimple(arg)) {
    return (ASF_CondEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Equation, 2), 1);
  }
  else if (ASF_isCondEquationImplies(arg)) {
    return (ASF_CondEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Equation, 6), 1);
  }
  else if (ASF_isCondEquationWhen(arg)) {
    return (ASF_CondEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Equation, 2), 1);
  }

  ATabort("CondEquation has no Equation: %t\n", arg);
  return (ASF_CondEquation)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasCondEquationConditions(ASF_CondEquation arg) */

ATbool ASF_hasCondEquationConditions(ASF_CondEquation arg)
{
  if (ASF_isCondEquationImplies(arg)) {
    return ATtrue;
  }
  else if (ASF_isCondEquationWhen(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Conditions ASF_getCondEquationConditions(ASF_CondEquation arg) */

ASF_Conditions ASF_getCondEquationConditions(ASF_CondEquation arg)
{
  if (ASF_isCondEquationImplies(arg)) {
    return (ASF_Conditions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else 
    return (ASF_Conditions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6);
}

/*}}}  */
/*{{{  ASF_CondEquation ASF_setCondEquationConditions(ASF_CondEquation arg, ASF_Conditions Conditions) */

ASF_CondEquation ASF_setCondEquationConditions(ASF_CondEquation arg, ASF_Conditions Conditions)
{
  if (ASF_isCondEquationImplies(arg)) {
    return (ASF_CondEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Conditions, 2), 1);
  }
  else if (ASF_isCondEquationWhen(arg)) {
    return (ASF_CondEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Conditions, 6), 1);
  }

  ATabort("CondEquation has no Conditions: %t\n", arg);
  return (ASF_CondEquation)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasCondEquationWsAfterConditions(ASF_CondEquation arg) */

ATbool ASF_hasCondEquationWsAfterConditions(ASF_CondEquation arg)
{
  if (ASF_isCondEquationImplies(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Layout ASF_getCondEquationWsAfterConditions(ASF_CondEquation arg) */

ASF_Layout ASF_getCondEquationWsAfterConditions(ASF_CondEquation arg)
{
  
    return (ASF_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  ASF_CondEquation ASF_setCondEquationWsAfterConditions(ASF_CondEquation arg, ASF_Layout wsAfterConditions) */

ASF_CondEquation ASF_setCondEquationWsAfterConditions(ASF_CondEquation arg, ASF_Layout wsAfterConditions)
{
  if (ASF_isCondEquationImplies(arg)) {
    return (ASF_CondEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterConditions, 3), 1);
  }

  ATabort("CondEquation has no WsAfterConditions: %t\n", arg);
  return (ASF_CondEquation)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasCondEquationImplies(ASF_CondEquation arg) */

ATbool ASF_hasCondEquationImplies(ASF_CondEquation arg)
{
  if (ASF_isCondEquationImplies(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Implies ASF_getCondEquationImplies(ASF_CondEquation arg) */

ASF_Implies ASF_getCondEquationImplies(ASF_CondEquation arg)
{
  
    return (ASF_Implies)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  ASF_CondEquation ASF_setCondEquationImplies(ASF_CondEquation arg, ASF_Implies Implies) */

ASF_CondEquation ASF_setCondEquationImplies(ASF_CondEquation arg, ASF_Implies Implies)
{
  if (ASF_isCondEquationImplies(arg)) {
    return (ASF_CondEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Implies, 4), 1);
  }

  ATabort("CondEquation has no Implies: %t\n", arg);
  return (ASF_CondEquation)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasCondEquationWsAfterImplies(ASF_CondEquation arg) */

ATbool ASF_hasCondEquationWsAfterImplies(ASF_CondEquation arg)
{
  if (ASF_isCondEquationImplies(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Layout ASF_getCondEquationWsAfterImplies(ASF_CondEquation arg) */

ASF_Layout ASF_getCondEquationWsAfterImplies(ASF_CondEquation arg)
{
  
    return (ASF_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  ASF_CondEquation ASF_setCondEquationWsAfterImplies(ASF_CondEquation arg, ASF_Layout wsAfterImplies) */

ASF_CondEquation ASF_setCondEquationWsAfterImplies(ASF_CondEquation arg, ASF_Layout wsAfterImplies)
{
  if (ASF_isCondEquationImplies(arg)) {
    return (ASF_CondEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterImplies, 5), 1);
  }

  ATabort("CondEquation has no WsAfterImplies: %t\n", arg);
  return (ASF_CondEquation)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasCondEquationWsAfterEquation(ASF_CondEquation arg) */

ATbool ASF_hasCondEquationWsAfterEquation(ASF_CondEquation arg)
{
  if (ASF_isCondEquationWhen(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Layout ASF_getCondEquationWsAfterEquation(ASF_CondEquation arg) */

ASF_Layout ASF_getCondEquationWsAfterEquation(ASF_CondEquation arg)
{
  
    return (ASF_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  ASF_CondEquation ASF_setCondEquationWsAfterEquation(ASF_CondEquation arg, ASF_Layout wsAfterEquation) */

ASF_CondEquation ASF_setCondEquationWsAfterEquation(ASF_CondEquation arg, ASF_Layout wsAfterEquation)
{
  if (ASF_isCondEquationWhen(arg)) {
    return (ASF_CondEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterEquation, 3), 1);
  }

  ATabort("CondEquation has no WsAfterEquation: %t\n", arg);
  return (ASF_CondEquation)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasCondEquationWsAfterWhen(ASF_CondEquation arg) */

ATbool ASF_hasCondEquationWsAfterWhen(ASF_CondEquation arg)
{
  if (ASF_isCondEquationWhen(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Layout ASF_getCondEquationWsAfterWhen(ASF_CondEquation arg) */

ASF_Layout ASF_getCondEquationWsAfterWhen(ASF_CondEquation arg)
{
  
    return (ASF_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  ASF_CondEquation ASF_setCondEquationWsAfterWhen(ASF_CondEquation arg, ASF_Layout wsAfterWhen) */

ASF_CondEquation ASF_setCondEquationWsAfterWhen(ASF_CondEquation arg, ASF_Layout wsAfterWhen)
{
  if (ASF_isCondEquationWhen(arg)) {
    return (ASF_CondEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterWhen, 5), 1);
  }

  ATabort("CondEquation has no WsAfterWhen: %t\n", arg);
  return (ASF_CondEquation)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_Tag accessors */

/*{{{  ATbool ASF_isValidTag(ASF_Tag arg) */

ATbool ASF_isValidTag(ASF_Tag arg)
{
  if (ASF_isTagEmpty(arg)) {
    return ATtrue;
  }
  else if (ASF_isTagNotEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isTagEmpty(ASF_Tag arg) */

inline ATbool ASF_isTagEmpty(ASF_Tag arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternTagEmpty, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isTagNotEmpty(ASF_Tag arg) */

inline ATbool ASF_isTagNotEmpty(ASF_Tag arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternTagNotEmpty, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ASF_hasTagWsAfterBracketOpen(ASF_Tag arg) */

ATbool ASF_hasTagWsAfterBracketOpen(ASF_Tag arg)
{
  if (ASF_isTagEmpty(arg)) {
    return ATtrue;
  }
  else if (ASF_isTagNotEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Layout ASF_getTagWsAfterBracketOpen(ASF_Tag arg) */

ASF_Layout ASF_getTagWsAfterBracketOpen(ASF_Tag arg)
{
  if (ASF_isTagEmpty(arg)) {
    return (ASF_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else 
    return (ASF_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  ASF_Tag ASF_setTagWsAfterBracketOpen(ASF_Tag arg, ASF_Layout wsAfterBracketOpen) */

ASF_Tag ASF_setTagWsAfterBracketOpen(ASF_Tag arg, ASF_Layout wsAfterBracketOpen)
{
  if (ASF_isTagEmpty(arg)) {
    return (ASF_Tag)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterBracketOpen, 1), 1);
  }
  else if (ASF_isTagNotEmpty(arg)) {
    return (ASF_Tag)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterBracketOpen, 1), 1);
  }

  ATabort("Tag has no WsAfterBracketOpen: %t\n", arg);
  return (ASF_Tag)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasTagTagId(ASF_Tag arg) */

ATbool ASF_hasTagTagId(ASF_Tag arg)
{
  if (ASF_isTagNotEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_TagId ASF_getTagTagId(ASF_Tag arg) */

ASF_TagId ASF_getTagTagId(ASF_Tag arg)
{
  
    return (ASF_TagId)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  ASF_Tag ASF_setTagTagId(ASF_Tag arg, ASF_TagId TagId) */

ASF_Tag ASF_setTagTagId(ASF_Tag arg, ASF_TagId TagId)
{
  if (ASF_isTagNotEmpty(arg)) {
    return (ASF_Tag)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)TagId, 2), 1);
  }

  ATabort("Tag has no TagId: %t\n", arg);
  return (ASF_Tag)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasTagWsAfterTagId(ASF_Tag arg) */

ATbool ASF_hasTagWsAfterTagId(ASF_Tag arg)
{
  if (ASF_isTagNotEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Layout ASF_getTagWsAfterTagId(ASF_Tag arg) */

ASF_Layout ASF_getTagWsAfterTagId(ASF_Tag arg)
{
  
    return (ASF_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  ASF_Tag ASF_setTagWsAfterTagId(ASF_Tag arg, ASF_Layout wsAfterTagId) */

ASF_Tag ASF_setTagWsAfterTagId(ASF_Tag arg, ASF_Layout wsAfterTagId)
{
  if (ASF_isTagNotEmpty(arg)) {
    return (ASF_Tag)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterTagId, 3), 1);
  }

  ATabort("Tag has no WsAfterTagId: %t\n", arg);
  return (ASF_Tag)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_Tree accessors */

/*{{{  ATbool ASF_isValidTree(ASF_Tree arg) */

ATbool ASF_isValidTree(ASF_Tree arg)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return ATtrue;
  }
  else if (ASF_isTreeAmbConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isTreeLexicalConstructor(ASF_Tree arg) */

inline ATbool ASF_isTreeLexicalConstructor(ASF_Tree arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternTreeLexicalConstructor, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isTreeAmbConstructor(ASF_Tree arg) */

inline ATbool ASF_isTreeAmbConstructor(ASF_Tree arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternTreeAmbConstructor, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ASF_hasTreeFormalName(ASF_Tree arg) */

ATbool ASF_hasTreeFormalName(ASF_Tree arg)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * ASF_getTreeFormalName(ASF_Tree arg) */

char * ASF_getTreeFormalName(ASF_Tree arg)
{
  
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0)), 0)));
}

/*}}}  */
/*{{{  ASF_Tree ASF_setTreeFormalName(ASF_Tree arg, char * formalName) */

ASF_Tree ASF_setTreeFormalName(ASF_Tree arg, char * formalName)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return (ASF_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0)), (ATerm)ATmakeAppl0(ATmakeAFun(formalName, 0, ATtrue)), 0), 0), 0), 0);
  }

  ATabort("Tree has no FormalName: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasTreeSymbol(ASF_Tree arg) */

ATbool ASF_hasTreeSymbol(ASF_Tree arg)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return ATtrue;
  }
  else if (ASF_isTreeAmbConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Symbol ASF_getTreeSymbol(ASF_Tree arg) */

ASF_Symbol ASF_getTreeSymbol(ASF_Tree arg)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return (ASF_Symbol)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1);
  }
  else 
    return (ASF_Symbol)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 0);
}

/*}}}  */
/*{{{  ASF_Tree ASF_setTreeSymbol(ASF_Tree arg, ASF_Symbol symbol) */

ASF_Tree ASF_setTreeSymbol(ASF_Tree arg, ASF_Symbol symbol)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return (ASF_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)symbol, 1), 0);
  }
  else if (ASF_isTreeAmbConstructor(arg)) {
    return (ASF_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)symbol, 0), 1), 0);
  }

  ATabort("Tree has no Symbol: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasTreeName(ASF_Tree arg) */

ATbool ASF_hasTreeName(ASF_Tree arg)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Tree ASF_getTreeName(ASF_Tree arg) */

ASF_Tree ASF_getTreeName(ASF_Tree arg)
{
  
    return (ASF_Tree)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  ASF_Tree ASF_setTreeName(ASF_Tree arg, ASF_Tree name) */

ASF_Tree ASF_setTreeName(ASF_Tree arg, ASF_Tree name)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return (ASF_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)name, 0), 1);
  }

  ATabort("Tree has no Name: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasTreeWsAfterName(ASF_Tree arg) */

ATbool ASF_hasTreeWsAfterName(ASF_Tree arg)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Layout ASF_getTreeWsAfterName(ASF_Tree arg) */

ASF_Layout ASF_getTreeWsAfterName(ASF_Tree arg)
{
  
    return (ASF_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  ASF_Tree ASF_setTreeWsAfterName(ASF_Tree arg, ASF_Layout wsAfterName) */

ASF_Tree ASF_setTreeWsAfterName(ASF_Tree arg, ASF_Layout wsAfterName)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return (ASF_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterName, 1), 1);
  }

  ATabort("Tree has no WsAfterName: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasTreeWsAfterParenOpen(ASF_Tree arg) */

ATbool ASF_hasTreeWsAfterParenOpen(ASF_Tree arg)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return ATtrue;
  }
  else if (ASF_isTreeAmbConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Layout ASF_getTreeWsAfterParenOpen(ASF_Tree arg) */

ASF_Layout ASF_getTreeWsAfterParenOpen(ASF_Tree arg)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return (ASF_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (ASF_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  ASF_Tree ASF_setTreeWsAfterParenOpen(ASF_Tree arg, ASF_Layout wsAfterParenOpen) */

ASF_Tree ASF_setTreeWsAfterParenOpen(ASF_Tree arg, ASF_Layout wsAfterParenOpen)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return (ASF_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenOpen, 3), 1);
  }
  else if (ASF_isTreeAmbConstructor(arg)) {
    return (ASF_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenOpen, 3), 1);
  }

  ATabort("Tree has no WsAfterParenOpen: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasTreeList(ASF_Tree arg) */

ATbool ASF_hasTreeList(ASF_Tree arg)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_CHARList ASF_getTreeList(ASF_Tree arg) */

ASF_CHARList ASF_getTreeList(ASF_Tree arg)
{
  
    return (ASF_CHARList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), 1);
}

/*}}}  */
/*{{{  ASF_Tree ASF_setTreeList(ASF_Tree arg, ASF_CHARList list) */

ASF_Tree ASF_setTreeList(ASF_Tree arg, ASF_CHARList list)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return (ASF_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), (ATerm)list, 1), 4), 1);
  }

  ATabort("Tree has no List: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasTreeWsAfterList(ASF_Tree arg) */

ATbool ASF_hasTreeWsAfterList(ASF_Tree arg)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Layout ASF_getTreeWsAfterList(ASF_Tree arg) */

ASF_Layout ASF_getTreeWsAfterList(ASF_Tree arg)
{
  
    return (ASF_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  ASF_Tree ASF_setTreeWsAfterList(ASF_Tree arg, ASF_Layout wsAfterList) */

ASF_Tree ASF_setTreeWsAfterList(ASF_Tree arg, ASF_Layout wsAfterList)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return (ASF_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterList, 5), 1);
  }

  ATabort("Tree has no WsAfterList: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasTreeAmb(ASF_Tree arg) */

ATbool ASF_hasTreeAmb(ASF_Tree arg)
{
  if (ASF_isTreeAmbConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Symbol ASF_getTreeAmb(ASF_Tree arg) */

ASF_Symbol ASF_getTreeAmb(ASF_Tree arg)
{
  
    return (ASF_Symbol)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), 4), 0), 0);
}

/*}}}  */
/*{{{  ASF_Tree ASF_setTreeAmb(ASF_Tree arg, ASF_Symbol amb) */

ASF_Tree ASF_setTreeAmb(ASF_Tree arg, ASF_Symbol amb)
{
  if (ASF_isTreeAmbConstructor(arg)) {
    return (ASF_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), 4), (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), 4), 0), (ATerm)amb, 0), 0), 4), 0), 0);
  }

  ATabort("Tree has no Amb: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasTreeWsAfterAmb(ASF_Tree arg) */

ATbool ASF_hasTreeWsAfterAmb(ASF_Tree arg)
{
  if (ASF_isTreeAmbConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Layout ASF_getTreeWsAfterAmb(ASF_Tree arg) */

ASF_Layout ASF_getTreeWsAfterAmb(ASF_Tree arg)
{
  
    return (ASF_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  ASF_Tree ASF_setTreeWsAfterAmb(ASF_Tree arg, ASF_Layout wsAfterAmb) */

ASF_Tree ASF_setTreeWsAfterAmb(ASF_Tree arg, ASF_Layout wsAfterAmb)
{
  if (ASF_isTreeAmbConstructor(arg)) {
    return (ASF_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterAmb, 1), 1);
  }

  ATabort("Tree has no WsAfterAmb: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasTreeListSymbol(ASF_Tree arg) */

ATbool ASF_hasTreeListSymbol(ASF_Tree arg)
{
  if (ASF_isTreeAmbConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Symbol ASF_getTreeListSymbol(ASF_Tree arg) */

ASF_Symbol ASF_getTreeListSymbol(ASF_Tree arg)
{
  
    return (ASF_Symbol)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), 0), 0), 0), 0);
}

/*}}}  */
/*{{{  ASF_Tree ASF_setTreeListSymbol(ASF_Tree arg, ASF_Symbol listSymbol) */

ASF_Tree ASF_setTreeListSymbol(ASF_Tree arg, ASF_Symbol listSymbol)
{
  if (ASF_isTreeAmbConstructor(arg)) {
    return (ASF_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), 0), (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), 0), 0), (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), 0), 0), 0), (ATerm)listSymbol, 0), 0), 0), 0), 4), 1);
  }

  ATabort("Tree has no ListSymbol: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasTreeAmbs(ASF_Tree arg) */

ATbool ASF_hasTreeAmbs(ASF_Tree arg)
{
  if (ASF_isTreeAmbConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_TreeAmbs ASF_getTreeAmbs(ASF_Tree arg) */

ASF_TreeAmbs ASF_getTreeAmbs(ASF_Tree arg)
{
  
    return (ASF_TreeAmbs)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), 1);
}

/*}}}  */
/*{{{  ASF_Tree ASF_setTreeAmbs(ASF_Tree arg, ASF_TreeAmbs ambs) */

ASF_Tree ASF_setTreeAmbs(ASF_Tree arg, ASF_TreeAmbs ambs)
{
  if (ASF_isTreeAmbConstructor(arg)) {
    return (ASF_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), (ATerm)ambs, 1), 4), 1);
  }

  ATabort("Tree has no Ambs: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasTreeWsAfterAmbs(ASF_Tree arg) */

ATbool ASF_hasTreeWsAfterAmbs(ASF_Tree arg)
{
  if (ASF_isTreeAmbConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Layout ASF_getTreeWsAfterAmbs(ASF_Tree arg) */

ASF_Layout ASF_getTreeWsAfterAmbs(ASF_Tree arg)
{
  
    return (ASF_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  ASF_Tree ASF_setTreeWsAfterAmbs(ASF_Tree arg, ASF_Layout wsAfterAmbs) */

ASF_Tree ASF_setTreeWsAfterAmbs(ASF_Tree arg, ASF_Layout wsAfterAmbs)
{
  if (ASF_isTreeAmbConstructor(arg)) {
    return (ASF_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterAmbs, 5), 1);
  }

  ATabort("Tree has no WsAfterAmbs: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_CHARList accessors */

/*{{{  ATbool ASF_isValidCHARList(ASF_CHARList arg) */

ATbool ASF_isValidCHARList(ASF_CHARList arg)
{
  if (ASF_isCHARListEmpty(arg)) {
    return ATtrue;
  }
  else if (ASF_isCHARListSingle(arg)) {
    return ATtrue;
  }
  else if (ASF_isCHARListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isCHARListEmpty(ASF_CHARList arg) */

inline ATbool ASF_isCHARListEmpty(ASF_CHARList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ASF_patternCHARListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool ASF_isCHARListSingle(ASF_CHARList arg) */

inline ATbool ASF_isCHARListSingle(ASF_CHARList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternCHARListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isCHARListMany(ASF_CHARList arg) */

inline ATbool ASF_isCHARListMany(ASF_CHARList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternCHARListMany, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ASF_hasCHARListHead(ASF_CHARList arg) */

ATbool ASF_hasCHARListHead(ASF_CHARList arg)
{
  if (ASF_isCHARListSingle(arg)) {
    return ATtrue;
  }
  else if (ASF_isCHARListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_CHAR ASF_getCHARListHead(ASF_CHARList arg) */

ASF_CHAR ASF_getCHARListHead(ASF_CHARList arg)
{
  if (ASF_isCHARListSingle(arg)) {
    return (ASF_CHAR)ATgetFirst((ATermList)arg);
  }
  else 
    return (ASF_CHAR)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  ASF_CHARList ASF_setCHARListHead(ASF_CHARList arg, ASF_CHAR head) */

ASF_CHARList ASF_setCHARListHead(ASF_CHARList arg, ASF_CHAR head)
{
  if (ASF_isCHARListSingle(arg)) {
    return (ASF_CHARList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (ASF_isCHARListMany(arg)) {
    return (ASF_CHARList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("CHARList has no Head: %t\n", arg);
  return (ASF_CHARList)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasCHARListWsAfterFirst(ASF_CHARList arg) */

ATbool ASF_hasCHARListWsAfterFirst(ASF_CHARList arg)
{
  if (ASF_isCHARListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Layout ASF_getCHARListWsAfterFirst(ASF_CHARList arg) */

ASF_Layout ASF_getCHARListWsAfterFirst(ASF_CHARList arg)
{
  
    return (ASF_Layout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  ASF_CHARList ASF_setCHARListWsAfterFirst(ASF_CHARList arg, ASF_Layout wsAfterFirst) */

ASF_CHARList ASF_setCHARListWsAfterFirst(ASF_CHARList arg, ASF_Layout wsAfterFirst)
{
  if (ASF_isCHARListMany(arg)) {
    return (ASF_CHARList)ATreplace((ATermList)arg, (ATerm)wsAfterFirst, 1);
  }

  ATabort("CHARList has no WsAfterFirst: %t\n", arg);
  return (ASF_CHARList)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasCHARListTail(ASF_CHARList arg) */

ATbool ASF_hasCHARListTail(ASF_CHARList arg)
{
  if (ASF_isCHARListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_CHARList ASF_getCHARListTail(ASF_CHARList arg) */

ASF_CHARList ASF_getCHARListTail(ASF_CHARList arg)
{
  
    return (ASF_CHARList)ATgetTail((ATermList)arg, 2);
}

/*}}}  */
/*{{{  ASF_CHARList ASF_setCHARListTail(ASF_CHARList arg, ASF_CHARList tail) */

ASF_CHARList ASF_setCHARListTail(ASF_CHARList arg, ASF_CHARList tail)
{
  if (ASF_isCHARListMany(arg)) {
    return (ASF_CHARList)ATreplaceTail((ATermList)arg, (ATermList)tail, 2);
  }

  ATabort("CHARList has no Tail: %t\n", arg);
  return (ASF_CHARList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_Equation accessors */

/*{{{  ATbool ASF_isValidEquation(ASF_Equation arg) */

ATbool ASF_isValidEquation(ASF_Equation arg)
{
  if (ASF_isEquationDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isEquationDefault(ASF_Equation arg) */

inline ATbool ASF_isEquationDefault(ASF_Equation arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ASF_patternEquationDefault, NULL, NULL, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool ASF_hasEquationLhsSymbol(ASF_Equation arg) */

ATbool ASF_hasEquationLhsSymbol(ASF_Equation arg)
{
  if (ASF_isEquationDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Symbol ASF_getEquationLhsSymbol(ASF_Equation arg) */

ASF_Symbol ASF_getEquationLhsSymbol(ASF_Equation arg)
{
  
    return (ASF_Symbol)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0));
}

/*}}}  */
/*{{{  ASF_Equation ASF_setEquationLhsSymbol(ASF_Equation arg, ASF_Symbol lhsSymbol) */

ASF_Equation ASF_setEquationLhsSymbol(ASF_Equation arg, ASF_Symbol lhsSymbol)
{
  if (ASF_isEquationDefault(arg)) {
    return (ASF_Equation)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)lhsSymbol, 0), 0), 0);
  }

  ATabort("Equation has no LhsSymbol: %t\n", arg);
  return (ASF_Equation)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasEquationRhsSymbol(ASF_Equation arg) */

ATbool ASF_hasEquationRhsSymbol(ASF_Equation arg)
{
  if (ASF_isEquationDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Symbol ASF_getEquationRhsSymbol(ASF_Equation arg) */

ASF_Symbol ASF_getEquationRhsSymbol(ASF_Equation arg)
{
  
    return (ASF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), 4);
}

/*}}}  */
/*{{{  ASF_Equation ASF_setEquationRhsSymbol(ASF_Equation arg, ASF_Symbol rhsSymbol) */

ASF_Equation ASF_setEquationRhsSymbol(ASF_Equation arg, ASF_Symbol rhsSymbol)
{
  if (ASF_isEquationDefault(arg)) {
    return (ASF_Equation)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)rhsSymbol, 4), 0), 0);
  }

  ATabort("Equation has no RhsSymbol: %t\n", arg);
  return (ASF_Equation)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasEquationLhs(ASF_Equation arg) */

ATbool ASF_hasEquationLhs(ASF_Equation arg)
{
  if (ASF_isEquationDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Tree ASF_getEquationLhs(ASF_Equation arg) */

ASF_Tree ASF_getEquationLhs(ASF_Equation arg)
{
  
    return (ASF_Tree)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  ASF_Equation ASF_setEquationLhs(ASF_Equation arg, ASF_Tree lhs) */

ASF_Equation ASF_setEquationLhs(ASF_Equation arg, ASF_Tree lhs)
{
  if (ASF_isEquationDefault(arg)) {
    return (ASF_Equation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)lhs, 0), 1);
  }

  ATabort("Equation has no Lhs: %t\n", arg);
  return (ASF_Equation)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasEquationWsAfterLhs(ASF_Equation arg) */

ATbool ASF_hasEquationWsAfterLhs(ASF_Equation arg)
{
  if (ASF_isEquationDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Layout ASF_getEquationWsAfterLhs(ASF_Equation arg) */

ASF_Layout ASF_getEquationWsAfterLhs(ASF_Equation arg)
{
  
    return (ASF_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  ASF_Equation ASF_setEquationWsAfterLhs(ASF_Equation arg, ASF_Layout wsAfterLhs) */

ASF_Equation ASF_setEquationWsAfterLhs(ASF_Equation arg, ASF_Layout wsAfterLhs)
{
  if (ASF_isEquationDefault(arg)) {
    return (ASF_Equation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLhs, 1), 1);
  }

  ATabort("Equation has no WsAfterLhs: %t\n", arg);
  return (ASF_Equation)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasEquationWsAfterEquals(ASF_Equation arg) */

ATbool ASF_hasEquationWsAfterEquals(ASF_Equation arg)
{
  if (ASF_isEquationDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Layout ASF_getEquationWsAfterEquals(ASF_Equation arg) */

ASF_Layout ASF_getEquationWsAfterEquals(ASF_Equation arg)
{
  
    return (ASF_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  ASF_Equation ASF_setEquationWsAfterEquals(ASF_Equation arg, ASF_Layout wsAfterEquals) */

ASF_Equation ASF_setEquationWsAfterEquals(ASF_Equation arg, ASF_Layout wsAfterEquals)
{
  if (ASF_isEquationDefault(arg)) {
    return (ASF_Equation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterEquals, 3), 1);
  }

  ATabort("Equation has no WsAfterEquals: %t\n", arg);
  return (ASF_Equation)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasEquationRhs(ASF_Equation arg) */

ATbool ASF_hasEquationRhs(ASF_Equation arg)
{
  if (ASF_isEquationDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Tree ASF_getEquationRhs(ASF_Equation arg) */

ASF_Tree ASF_getEquationRhs(ASF_Equation arg)
{
  
    return (ASF_Tree)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  ASF_Equation ASF_setEquationRhs(ASF_Equation arg, ASF_Tree rhs) */

ASF_Equation ASF_setEquationRhs(ASF_Equation arg, ASF_Tree rhs)
{
  if (ASF_isEquationDefault(arg)) {
    return (ASF_Equation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)rhs, 4), 1);
  }

  ATabort("Equation has no Rhs: %t\n", arg);
  return (ASF_Equation)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_Condition accessors */

/*{{{  ATbool ASF_isValidCondition(ASF_Condition arg) */

ATbool ASF_isValidCondition(ASF_Condition arg)
{
  if (ASF_isConditionPositive(arg)) {
    return ATtrue;
  }
  else if (ASF_isConditionNegative(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isConditionPositive(ASF_Condition arg) */

inline ATbool ASF_isConditionPositive(ASF_Condition arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternConditionPositive, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isConditionNegative(ASF_Condition arg) */

inline ATbool ASF_isConditionNegative(ASF_Condition arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternConditionNegative, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ASF_hasConditionLhsSymbol(ASF_Condition arg) */

ATbool ASF_hasConditionLhsSymbol(ASF_Condition arg)
{
  if (ASF_isConditionPositive(arg)) {
    return ATtrue;
  }
  else if (ASF_isConditionNegative(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Symbol ASF_getConditionLhsSymbol(ASF_Condition arg) */

ASF_Symbol ASF_getConditionLhsSymbol(ASF_Condition arg)
{
  if (ASF_isConditionPositive(arg)) {
    return (ASF_Symbol)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0));
  }
  else 
    return (ASF_Symbol)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0));
}

/*}}}  */
/*{{{  ASF_Condition ASF_setConditionLhsSymbol(ASF_Condition arg, ASF_Symbol lhsSymbol) */

ASF_Condition ASF_setConditionLhsSymbol(ASF_Condition arg, ASF_Symbol lhsSymbol)
{
  if (ASF_isConditionPositive(arg)) {
    return (ASF_Condition)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)lhsSymbol, 0), 0), 0);
  }
  else if (ASF_isConditionNegative(arg)) {
    return (ASF_Condition)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)lhsSymbol, 0), 0), 0);
  }

  ATabort("Condition has no LhsSymbol: %t\n", arg);
  return (ASF_Condition)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasConditionRhsSymbol(ASF_Condition arg) */

ATbool ASF_hasConditionRhsSymbol(ASF_Condition arg)
{
  if (ASF_isConditionPositive(arg)) {
    return ATtrue;
  }
  else if (ASF_isConditionNegative(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Symbol ASF_getConditionRhsSymbol(ASF_Condition arg) */

ASF_Symbol ASF_getConditionRhsSymbol(ASF_Condition arg)
{
  if (ASF_isConditionPositive(arg)) {
    return (ASF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), 4);
  }
  else 
    return (ASF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), 4);
}

/*}}}  */
/*{{{  ASF_Condition ASF_setConditionRhsSymbol(ASF_Condition arg, ASF_Symbol rhsSymbol) */

ASF_Condition ASF_setConditionRhsSymbol(ASF_Condition arg, ASF_Symbol rhsSymbol)
{
  if (ASF_isConditionPositive(arg)) {
    return (ASF_Condition)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)rhsSymbol, 4), 0), 0);
  }
  else if (ASF_isConditionNegative(arg)) {
    return (ASF_Condition)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)rhsSymbol, 4), 0), 0);
  }

  ATabort("Condition has no RhsSymbol: %t\n", arg);
  return (ASF_Condition)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasConditionLhs(ASF_Condition arg) */

ATbool ASF_hasConditionLhs(ASF_Condition arg)
{
  if (ASF_isConditionPositive(arg)) {
    return ATtrue;
  }
  else if (ASF_isConditionNegative(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Tree ASF_getConditionLhs(ASF_Condition arg) */

ASF_Tree ASF_getConditionLhs(ASF_Condition arg)
{
  if (ASF_isConditionPositive(arg)) {
    return (ASF_Tree)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (ASF_Tree)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  ASF_Condition ASF_setConditionLhs(ASF_Condition arg, ASF_Tree lhs) */

ASF_Condition ASF_setConditionLhs(ASF_Condition arg, ASF_Tree lhs)
{
  if (ASF_isConditionPositive(arg)) {
    return (ASF_Condition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)lhs, 0), 1);
  }
  else if (ASF_isConditionNegative(arg)) {
    return (ASF_Condition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)lhs, 0), 1);
  }

  ATabort("Condition has no Lhs: %t\n", arg);
  return (ASF_Condition)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasConditionWsAfterLhs(ASF_Condition arg) */

ATbool ASF_hasConditionWsAfterLhs(ASF_Condition arg)
{
  if (ASF_isConditionPositive(arg)) {
    return ATtrue;
  }
  else if (ASF_isConditionNegative(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Layout ASF_getConditionWsAfterLhs(ASF_Condition arg) */

ASF_Layout ASF_getConditionWsAfterLhs(ASF_Condition arg)
{
  if (ASF_isConditionPositive(arg)) {
    return (ASF_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else 
    return (ASF_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  ASF_Condition ASF_setConditionWsAfterLhs(ASF_Condition arg, ASF_Layout wsAfterLhs) */

ASF_Condition ASF_setConditionWsAfterLhs(ASF_Condition arg, ASF_Layout wsAfterLhs)
{
  if (ASF_isConditionPositive(arg)) {
    return (ASF_Condition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLhs, 1), 1);
  }
  else if (ASF_isConditionNegative(arg)) {
    return (ASF_Condition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLhs, 1), 1);
  }

  ATabort("Condition has no WsAfterLhs: %t\n", arg);
  return (ASF_Condition)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasConditionWsAfterEquals(ASF_Condition arg) */

ATbool ASF_hasConditionWsAfterEquals(ASF_Condition arg)
{
  if (ASF_isConditionPositive(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Layout ASF_getConditionWsAfterEquals(ASF_Condition arg) */

ASF_Layout ASF_getConditionWsAfterEquals(ASF_Condition arg)
{
  
    return (ASF_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  ASF_Condition ASF_setConditionWsAfterEquals(ASF_Condition arg, ASF_Layout wsAfterEquals) */

ASF_Condition ASF_setConditionWsAfterEquals(ASF_Condition arg, ASF_Layout wsAfterEquals)
{
  if (ASF_isConditionPositive(arg)) {
    return (ASF_Condition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterEquals, 3), 1);
  }

  ATabort("Condition has no WsAfterEquals: %t\n", arg);
  return (ASF_Condition)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasConditionRhs(ASF_Condition arg) */

ATbool ASF_hasConditionRhs(ASF_Condition arg)
{
  if (ASF_isConditionPositive(arg)) {
    return ATtrue;
  }
  else if (ASF_isConditionNegative(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Tree ASF_getConditionRhs(ASF_Condition arg) */

ASF_Tree ASF_getConditionRhs(ASF_Condition arg)
{
  if (ASF_isConditionPositive(arg)) {
    return (ASF_Tree)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (ASF_Tree)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  ASF_Condition ASF_setConditionRhs(ASF_Condition arg, ASF_Tree rhs) */

ASF_Condition ASF_setConditionRhs(ASF_Condition arg, ASF_Tree rhs)
{
  if (ASF_isConditionPositive(arg)) {
    return (ASF_Condition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)rhs, 4), 1);
  }
  else if (ASF_isConditionNegative(arg)) {
    return (ASF_Condition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)rhs, 4), 1);
  }

  ATabort("Condition has no Rhs: %t\n", arg);
  return (ASF_Condition)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasConditionWsAfterUnequal(ASF_Condition arg) */

ATbool ASF_hasConditionWsAfterUnequal(ASF_Condition arg)
{
  if (ASF_isConditionNegative(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Layout ASF_getConditionWsAfterUnequal(ASF_Condition arg) */

ASF_Layout ASF_getConditionWsAfterUnequal(ASF_Condition arg)
{
  
    return (ASF_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  ASF_Condition ASF_setConditionWsAfterUnequal(ASF_Condition arg, ASF_Layout wsAfterUnequal) */

ASF_Condition ASF_setConditionWsAfterUnequal(ASF_Condition arg, ASF_Layout wsAfterUnequal)
{
  if (ASF_isConditionNegative(arg)) {
    return (ASF_Condition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterUnequal, 3), 1);
  }

  ATabort("Condition has no WsAfterUnequal: %t\n", arg);
  return (ASF_Condition)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_TreeAmbs accessors */

/*{{{  ATbool ASF_isValidTreeAmbs(ASF_TreeAmbs arg) */

ATbool ASF_isValidTreeAmbs(ASF_TreeAmbs arg)
{
  if (ASF_isTreeAmbsEmpty(arg)) {
    return ATtrue;
  }
  else if (ASF_isTreeAmbsSingle(arg)) {
    return ATtrue;
  }
  else if (ASF_isTreeAmbsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isTreeAmbsEmpty(ASF_TreeAmbs arg) */

inline ATbool ASF_isTreeAmbsEmpty(ASF_TreeAmbs arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ASF_patternTreeAmbsEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool ASF_isTreeAmbsSingle(ASF_TreeAmbs arg) */

inline ATbool ASF_isTreeAmbsSingle(ASF_TreeAmbs arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternTreeAmbsSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isTreeAmbsMany(ASF_TreeAmbs arg) */

inline ATbool ASF_isTreeAmbsMany(ASF_TreeAmbs arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternTreeAmbsMany, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ASF_hasTreeAmbsHead(ASF_TreeAmbs arg) */

ATbool ASF_hasTreeAmbsHead(ASF_TreeAmbs arg)
{
  if (ASF_isTreeAmbsSingle(arg)) {
    return ATtrue;
  }
  else if (ASF_isTreeAmbsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Tree ASF_getTreeAmbsHead(ASF_TreeAmbs arg) */

ASF_Tree ASF_getTreeAmbsHead(ASF_TreeAmbs arg)
{
  if (ASF_isTreeAmbsSingle(arg)) {
    return (ASF_Tree)ATgetFirst((ATermList)arg);
  }
  else 
    return (ASF_Tree)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  ASF_TreeAmbs ASF_setTreeAmbsHead(ASF_TreeAmbs arg, ASF_Tree head) */

ASF_TreeAmbs ASF_setTreeAmbsHead(ASF_TreeAmbs arg, ASF_Tree head)
{
  if (ASF_isTreeAmbsSingle(arg)) {
    return (ASF_TreeAmbs)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (ASF_isTreeAmbsMany(arg)) {
    return (ASF_TreeAmbs)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("TreeAmbs has no Head: %t\n", arg);
  return (ASF_TreeAmbs)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasTreeAmbsWsAfterFirst(ASF_TreeAmbs arg) */

ATbool ASF_hasTreeAmbsWsAfterFirst(ASF_TreeAmbs arg)
{
  if (ASF_isTreeAmbsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Layout ASF_getTreeAmbsWsAfterFirst(ASF_TreeAmbs arg) */

ASF_Layout ASF_getTreeAmbsWsAfterFirst(ASF_TreeAmbs arg)
{
  
    return (ASF_Layout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  ASF_TreeAmbs ASF_setTreeAmbsWsAfterFirst(ASF_TreeAmbs arg, ASF_Layout wsAfterFirst) */

ASF_TreeAmbs ASF_setTreeAmbsWsAfterFirst(ASF_TreeAmbs arg, ASF_Layout wsAfterFirst)
{
  if (ASF_isTreeAmbsMany(arg)) {
    return (ASF_TreeAmbs)ATreplace((ATermList)arg, (ATerm)wsAfterFirst, 1);
  }

  ATabort("TreeAmbs has no WsAfterFirst: %t\n", arg);
  return (ASF_TreeAmbs)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasTreeAmbsSep(ASF_TreeAmbs arg) */

ATbool ASF_hasTreeAmbsSep(ASF_TreeAmbs arg)
{
  if (ASF_isTreeAmbsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * ASF_getTreeAmbsSep(ASF_TreeAmbs arg) */

char * ASF_getTreeAmbsSep(ASF_TreeAmbs arg)
{
  
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), 0)));
}

/*}}}  */
/*{{{  ASF_TreeAmbs ASF_setTreeAmbsSep(ASF_TreeAmbs arg, char * sep) */

ASF_TreeAmbs ASF_setTreeAmbsSep(ASF_TreeAmbs arg, char * sep)
{
  if (ASF_isTreeAmbsMany(arg)) {
    return (ASF_TreeAmbs)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)), 0), 2);
  }

  ATabort("TreeAmbs has no Sep: %t\n", arg);
  return (ASF_TreeAmbs)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasTreeAmbsWsAfterSep(ASF_TreeAmbs arg) */

ATbool ASF_hasTreeAmbsWsAfterSep(ASF_TreeAmbs arg)
{
  if (ASF_isTreeAmbsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Layout ASF_getTreeAmbsWsAfterSep(ASF_TreeAmbs arg) */

ASF_Layout ASF_getTreeAmbsWsAfterSep(ASF_TreeAmbs arg)
{
  
    return (ASF_Layout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  ASF_TreeAmbs ASF_setTreeAmbsWsAfterSep(ASF_TreeAmbs arg, ASF_Layout wsAfterSep) */

ASF_TreeAmbs ASF_setTreeAmbsWsAfterSep(ASF_TreeAmbs arg, ASF_Layout wsAfterSep)
{
  if (ASF_isTreeAmbsMany(arg)) {
    return (ASF_TreeAmbs)ATreplace((ATermList)arg, (ATerm)wsAfterSep, 3);
  }

  ATabort("TreeAmbs has no WsAfterSep: %t\n", arg);
  return (ASF_TreeAmbs)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasTreeAmbsTail(ASF_TreeAmbs arg) */

ATbool ASF_hasTreeAmbsTail(ASF_TreeAmbs arg)
{
  if (ASF_isTreeAmbsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_TreeAmbs ASF_getTreeAmbsTail(ASF_TreeAmbs arg) */

ASF_TreeAmbs ASF_getTreeAmbsTail(ASF_TreeAmbs arg)
{
  
    return (ASF_TreeAmbs)ATgetTail((ATermList)arg, 4);
}

/*}}}  */
/*{{{  ASF_TreeAmbs ASF_setTreeAmbsTail(ASF_TreeAmbs arg, ASF_TreeAmbs tail) */

ASF_TreeAmbs ASF_setTreeAmbsTail(ASF_TreeAmbs arg, ASF_TreeAmbs tail)
{
  if (ASF_isTreeAmbsMany(arg)) {
    return (ASF_TreeAmbs)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("TreeAmbs has no Tail: %t\n", arg);
  return (ASF_TreeAmbs)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_CHAR accessors */

/*{{{  ATbool ASF_isValidCHAR(ASF_CHAR arg) */

ATbool ASF_isValidCHAR(ASF_CHAR arg)
{
  if (ASF_isCHARLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isCHARLexToCf(ASF_CHAR arg) */

inline ATbool ASF_isCHARLexToCf(ASF_CHAR arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ASF_patternCHARLexToCf, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool ASF_hasCHARLex(ASF_CHAR arg) */

ATbool ASF_hasCHARLex(ASF_CHAR arg)
{
  if (ASF_isCHARLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Lexical ASF_getCHARLex(ASF_CHAR arg) */

ASF_Lexical ASF_getCHARLex(ASF_CHAR arg)
{
  
    return (ASF_Lexical)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  ASF_CHAR ASF_setCHARLex(ASF_CHAR arg, ASF_Lexical lex) */

ASF_CHAR ASF_setCHARLex(ASF_CHAR arg, ASF_Lexical lex)
{
  if (ASF_isCHARLexToCf(arg)) {
    return (ASF_CHAR)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)lex, 0), 1);
  }

  ATabort("CHAR has no Lex: %t\n", arg);
  return (ASF_CHAR)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  ASF_Production ASF_visitProduction(ASF_Production arg, char * (*acceptFormalName)(char *), ASF_Symbol (*acceptSymbol)(ASF_Symbol)) */

ASF_Production ASF_visitProduction(ASF_Production arg, char * (*acceptFormalName)(char *), ASF_Symbol (*acceptSymbol)(ASF_Symbol))
{
  if (ASF_isProductionLexicalConstructor(arg)) {
    return ASF_makeProductionLexicalConstructor(
        acceptFormalName ? acceptFormalName(ASF_getProductionFormalName(arg)) : ASF_getProductionFormalName(arg),
        acceptSymbol ? acceptSymbol(ASF_getProductionSymbol(arg)) : ASF_getProductionSymbol(arg));
  }
  ATabort("not a Production: %t\n", arg);
  return (ASF_Production)NULL;
}

/*}}}  */
/*{{{  ASF_Implies ASF_visitImplies(ASF_Implies arg, ASF_Lexical (*acceptLex)(ASF_Lexical)) */

ASF_Implies ASF_visitImplies(ASF_Implies arg, ASF_Lexical (*acceptLex)(ASF_Lexical))
{
  if (ASF_isImpliesLexToCf(arg)) {
    return ASF_makeImpliesLexToCf(
        acceptLex ? acceptLex(ASF_getImpliesLex(arg)) : ASF_getImpliesLex(arg));
  }
  ATabort("not a Implies: %t\n", arg);
  return (ASF_Implies)NULL;
}

/*}}}  */
/*{{{  ASF_TagId ASF_visitTagId(ASF_TagId arg, ASF_Lexical (*acceptLex)(ASF_Lexical)) */

ASF_TagId ASF_visitTagId(ASF_TagId arg, ASF_Lexical (*acceptLex)(ASF_Lexical))
{
  if (ASF_isTagIdLexToCf(arg)) {
    return ASF_makeTagIdLexToCf(
        acceptLex ? acceptLex(ASF_getTagIdLex(arg)) : ASF_getTagIdLex(arg));
  }
  ATabort("not a TagId: %t\n", arg);
  return (ASF_TagId)NULL;
}

/*}}}  */
/*{{{  ASF_Conditions ASF_visitConditions(ASF_Conditions arg, ASF_ConditionList (*acceptList)(ASF_ConditionList)) */

ASF_Conditions ASF_visitConditions(ASF_Conditions arg, ASF_ConditionList (*acceptList)(ASF_ConditionList))
{
  if (ASF_isConditionsDefault(arg)) {
    return ASF_makeConditionsDefault(
        acceptList ? acceptList(ASF_getConditionsList(arg)) : ASF_getConditionsList(arg));
  }
  ATabort("not a Conditions: %t\n", arg);
  return (ASF_Conditions)NULL;
}

/*}}}  */
/*{{{  ASF_ConditionList ASF_visitConditionList(ASF_ConditionList arg, ASF_Condition (*acceptHead)(ASF_Condition), ASF_Layout (*acceptWsAfterFirst)(ASF_Layout), char * (*acceptSep)(char *), ASF_Layout (*acceptWsAfterSep)(ASF_Layout)) */

ASF_ConditionList ASF_visitConditionList(ASF_ConditionList arg, ASF_Condition (*acceptHead)(ASF_Condition), ASF_Layout (*acceptWsAfterFirst)(ASF_Layout), char * (*acceptSep)(char *), ASF_Layout (*acceptWsAfterSep)(ASF_Layout))
{
  if (ASF_isConditionListSingle(arg)) {
    return ASF_makeConditionListSingle(
        acceptHead ? acceptHead(ASF_getConditionListHead(arg)) : ASF_getConditionListHead(arg));
  }
  if (ASF_isConditionListMany(arg)) {
    return ASF_makeConditionListMany(
        acceptHead ? acceptHead(ASF_getConditionListHead(arg)) : ASF_getConditionListHead(arg),
        acceptWsAfterFirst ? acceptWsAfterFirst(ASF_getConditionListWsAfterFirst(arg)) : ASF_getConditionListWsAfterFirst(arg),
        acceptSep ? acceptSep(ASF_getConditionListSep(arg)) : ASF_getConditionListSep(arg),
        acceptWsAfterSep ? acceptWsAfterSep(ASF_getConditionListWsAfterSep(arg)) : ASF_getConditionListWsAfterSep(arg),
        ASF_visitConditionList(ASF_getConditionListTail(arg), acceptHead, acceptWsAfterFirst, acceptSep, acceptWsAfterSep));
  }
  ATabort("not a ConditionList: %t\n", arg);
  return (ASF_ConditionList)NULL;
}

/*}}}  */
/*{{{  ASF_Equations ASF_visitEquations(ASF_Equations arg, ASF_Layout (*acceptWsAfterEquations)(ASF_Layout), ASF_CondEquationList (*acceptList)(ASF_CondEquationList)) */

ASF_Equations ASF_visitEquations(ASF_Equations arg, ASF_Layout (*acceptWsAfterEquations)(ASF_Layout), ASF_CondEquationList (*acceptList)(ASF_CondEquationList))
{
  if (ASF_isEquationsAbsent(arg)) {
    return ASF_makeEquationsAbsent();
  }
  if (ASF_isEquationsPresent(arg)) {
    return ASF_makeEquationsPresent(
        acceptWsAfterEquations ? acceptWsAfterEquations(ASF_getEquationsWsAfterEquations(arg)) : ASF_getEquationsWsAfterEquations(arg),
        acceptList ? acceptList(ASF_getEquationsList(arg)) : ASF_getEquationsList(arg));
  }
  ATabort("not a Equations: %t\n", arg);
  return (ASF_Equations)NULL;
}

/*}}}  */
/*{{{  ASF_CondEquationList ASF_visitCondEquationList(ASF_CondEquationList arg, ASF_CondEquation (*acceptHead)(ASF_CondEquation), ASF_Layout (*acceptWsAfterFirst)(ASF_Layout)) */

ASF_CondEquationList ASF_visitCondEquationList(ASF_CondEquationList arg, ASF_CondEquation (*acceptHead)(ASF_CondEquation), ASF_Layout (*acceptWsAfterFirst)(ASF_Layout))
{
  if (ASF_isCondEquationListEmpty(arg)) {
    return ASF_makeCondEquationListEmpty();
  }
  if (ASF_isCondEquationListSingle(arg)) {
    return ASF_makeCondEquationListSingle(
        acceptHead ? acceptHead(ASF_getCondEquationListHead(arg)) : ASF_getCondEquationListHead(arg));
  }
  if (ASF_isCondEquationListMany(arg)) {
    return ASF_makeCondEquationListMany(
        acceptHead ? acceptHead(ASF_getCondEquationListHead(arg)) : ASF_getCondEquationListHead(arg),
        acceptWsAfterFirst ? acceptWsAfterFirst(ASF_getCondEquationListWsAfterFirst(arg)) : ASF_getCondEquationListWsAfterFirst(arg),
        ASF_visitCondEquationList(ASF_getCondEquationListTail(arg), acceptHead, acceptWsAfterFirst));
  }
  ATabort("not a CondEquationList: %t\n", arg);
  return (ASF_CondEquationList)NULL;
}

/*}}}  */
/*{{{  ASF_CondEquation ASF_visitCondEquation(ASF_CondEquation arg, ASF_Tag (*acceptTag)(ASF_Tag), ASF_Layout (*acceptWsAfterTag)(ASF_Layout), ASF_Equation (*acceptEquation)(ASF_Equation), ASF_Conditions (*acceptConditions)(ASF_Conditions), ASF_Layout (*acceptWsAfterConditions)(ASF_Layout), ASF_Implies (*acceptImplies)(ASF_Implies), ASF_Layout (*acceptWsAfterImplies)(ASF_Layout), ASF_Layout (*acceptWsAfterEquation)(ASF_Layout), ASF_Layout (*acceptWsAfterWhen)(ASF_Layout)) */

ASF_CondEquation ASF_visitCondEquation(ASF_CondEquation arg, ASF_Tag (*acceptTag)(ASF_Tag), ASF_Layout (*acceptWsAfterTag)(ASF_Layout), ASF_Equation (*acceptEquation)(ASF_Equation), ASF_Conditions (*acceptConditions)(ASF_Conditions), ASF_Layout (*acceptWsAfterConditions)(ASF_Layout), ASF_Implies (*acceptImplies)(ASF_Implies), ASF_Layout (*acceptWsAfterImplies)(ASF_Layout), ASF_Layout (*acceptWsAfterEquation)(ASF_Layout), ASF_Layout (*acceptWsAfterWhen)(ASF_Layout))
{
  if (ASF_isCondEquationSimple(arg)) {
    return ASF_makeCondEquationSimple(
        acceptTag ? acceptTag(ASF_getCondEquationTag(arg)) : ASF_getCondEquationTag(arg),
        acceptWsAfterTag ? acceptWsAfterTag(ASF_getCondEquationWsAfterTag(arg)) : ASF_getCondEquationWsAfterTag(arg),
        acceptEquation ? acceptEquation(ASF_getCondEquationEquation(arg)) : ASF_getCondEquationEquation(arg));
  }
  if (ASF_isCondEquationImplies(arg)) {
    return ASF_makeCondEquationImplies(
        acceptTag ? acceptTag(ASF_getCondEquationTag(arg)) : ASF_getCondEquationTag(arg),
        acceptWsAfterTag ? acceptWsAfterTag(ASF_getCondEquationWsAfterTag(arg)) : ASF_getCondEquationWsAfterTag(arg),
        acceptConditions ? acceptConditions(ASF_getCondEquationConditions(arg)) : ASF_getCondEquationConditions(arg),
        acceptWsAfterConditions ? acceptWsAfterConditions(ASF_getCondEquationWsAfterConditions(arg)) : ASF_getCondEquationWsAfterConditions(arg),
        acceptImplies ? acceptImplies(ASF_getCondEquationImplies(arg)) : ASF_getCondEquationImplies(arg),
        acceptWsAfterImplies ? acceptWsAfterImplies(ASF_getCondEquationWsAfterImplies(arg)) : ASF_getCondEquationWsAfterImplies(arg),
        acceptEquation ? acceptEquation(ASF_getCondEquationEquation(arg)) : ASF_getCondEquationEquation(arg));
  }
  if (ASF_isCondEquationWhen(arg)) {
    return ASF_makeCondEquationWhen(
        acceptTag ? acceptTag(ASF_getCondEquationTag(arg)) : ASF_getCondEquationTag(arg),
        acceptWsAfterTag ? acceptWsAfterTag(ASF_getCondEquationWsAfterTag(arg)) : ASF_getCondEquationWsAfterTag(arg),
        acceptEquation ? acceptEquation(ASF_getCondEquationEquation(arg)) : ASF_getCondEquationEquation(arg),
        acceptWsAfterEquation ? acceptWsAfterEquation(ASF_getCondEquationWsAfterEquation(arg)) : ASF_getCondEquationWsAfterEquation(arg),
        acceptWsAfterWhen ? acceptWsAfterWhen(ASF_getCondEquationWsAfterWhen(arg)) : ASF_getCondEquationWsAfterWhen(arg),
        acceptConditions ? acceptConditions(ASF_getCondEquationConditions(arg)) : ASF_getCondEquationConditions(arg));
  }
  ATabort("not a CondEquation: %t\n", arg);
  return (ASF_CondEquation)NULL;
}

/*}}}  */
/*{{{  ASF_Tag ASF_visitTag(ASF_Tag arg, ASF_Layout (*acceptWsAfterBracketOpen)(ASF_Layout), ASF_TagId (*acceptTagId)(ASF_TagId), ASF_Layout (*acceptWsAfterTagId)(ASF_Layout)) */

ASF_Tag ASF_visitTag(ASF_Tag arg, ASF_Layout (*acceptWsAfterBracketOpen)(ASF_Layout), ASF_TagId (*acceptTagId)(ASF_TagId), ASF_Layout (*acceptWsAfterTagId)(ASF_Layout))
{
  if (ASF_isTagEmpty(arg)) {
    return ASF_makeTagEmpty(
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(ASF_getTagWsAfterBracketOpen(arg)) : ASF_getTagWsAfterBracketOpen(arg));
  }
  if (ASF_isTagNotEmpty(arg)) {
    return ASF_makeTagNotEmpty(
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(ASF_getTagWsAfterBracketOpen(arg)) : ASF_getTagWsAfterBracketOpen(arg),
        acceptTagId ? acceptTagId(ASF_getTagTagId(arg)) : ASF_getTagTagId(arg),
        acceptWsAfterTagId ? acceptWsAfterTagId(ASF_getTagWsAfterTagId(arg)) : ASF_getTagWsAfterTagId(arg));
  }
  ATabort("not a Tag: %t\n", arg);
  return (ASF_Tag)NULL;
}

/*}}}  */
/*{{{  ASF_Tree ASF_visitTree(ASF_Tree arg, char * (*acceptFormalName)(char *), ASF_Symbol (*acceptSymbol)(ASF_Symbol), ASF_Layout (*acceptWsAfterName)(ASF_Layout), ASF_Layout (*acceptWsAfterParenOpen)(ASF_Layout), ASF_CHARList (*acceptList)(ASF_CHARList), ASF_Layout (*acceptWsAfterList)(ASF_Layout), ASF_Symbol (*acceptAmb)(ASF_Symbol), ASF_Layout (*acceptWsAfterAmb)(ASF_Layout), ASF_Symbol (*acceptListSymbol)(ASF_Symbol), ASF_TreeAmbs (*acceptAmbs)(ASF_TreeAmbs), ASF_Layout (*acceptWsAfterAmbs)(ASF_Layout)) */

ASF_Tree ASF_visitTree(ASF_Tree arg, char * (*acceptFormalName)(char *), ASF_Symbol (*acceptSymbol)(ASF_Symbol), ASF_Layout (*acceptWsAfterName)(ASF_Layout), ASF_Layout (*acceptWsAfterParenOpen)(ASF_Layout), ASF_CHARList (*acceptList)(ASF_CHARList), ASF_Layout (*acceptWsAfterList)(ASF_Layout), ASF_Symbol (*acceptAmb)(ASF_Symbol), ASF_Layout (*acceptWsAfterAmb)(ASF_Layout), ASF_Symbol (*acceptListSymbol)(ASF_Symbol), ASF_TreeAmbs (*acceptAmbs)(ASF_TreeAmbs), ASF_Layout (*acceptWsAfterAmbs)(ASF_Layout))
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return ASF_makeTreeLexicalConstructor(
        acceptFormalName ? acceptFormalName(ASF_getTreeFormalName(arg)) : ASF_getTreeFormalName(arg),
        acceptSymbol ? acceptSymbol(ASF_getTreeSymbol(arg)) : ASF_getTreeSymbol(arg),
        ASF_visitTree(ASF_getTreeName(arg), acceptFormalName, acceptSymbol, acceptWsAfterName, acceptWsAfterParenOpen, acceptList, acceptWsAfterList, acceptAmb, acceptWsAfterAmb, acceptListSymbol, acceptAmbs, acceptWsAfterAmbs),
        acceptWsAfterName ? acceptWsAfterName(ASF_getTreeWsAfterName(arg)) : ASF_getTreeWsAfterName(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(ASF_getTreeWsAfterParenOpen(arg)) : ASF_getTreeWsAfterParenOpen(arg),
        acceptList ? acceptList(ASF_getTreeList(arg)) : ASF_getTreeList(arg),
        acceptWsAfterList ? acceptWsAfterList(ASF_getTreeWsAfterList(arg)) : ASF_getTreeWsAfterList(arg));
  }
  if (ASF_isTreeAmbConstructor(arg)) {
    return ASF_makeTreeAmbConstructor(
        acceptAmb ? acceptAmb(ASF_getTreeAmb(arg)) : ASF_getTreeAmb(arg),
        acceptSymbol ? acceptSymbol(ASF_getTreeSymbol(arg)) : ASF_getTreeSymbol(arg),
        acceptWsAfterAmb ? acceptWsAfterAmb(ASF_getTreeWsAfterAmb(arg)) : ASF_getTreeWsAfterAmb(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(ASF_getTreeWsAfterParenOpen(arg)) : ASF_getTreeWsAfterParenOpen(arg),
        acceptListSymbol ? acceptListSymbol(ASF_getTreeListSymbol(arg)) : ASF_getTreeListSymbol(arg),
        acceptAmbs ? acceptAmbs(ASF_getTreeAmbs(arg)) : ASF_getTreeAmbs(arg),
        acceptWsAfterAmbs ? acceptWsAfterAmbs(ASF_getTreeWsAfterAmbs(arg)) : ASF_getTreeWsAfterAmbs(arg));
  }
  ATabort("not a Tree: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ASF_CHARList ASF_visitCHARList(ASF_CHARList arg, ASF_CHAR (*acceptHead)(ASF_CHAR), ASF_Layout (*acceptWsAfterFirst)(ASF_Layout)) */

ASF_CHARList ASF_visitCHARList(ASF_CHARList arg, ASF_CHAR (*acceptHead)(ASF_CHAR), ASF_Layout (*acceptWsAfterFirst)(ASF_Layout))
{
  if (ASF_isCHARListEmpty(arg)) {
    return ASF_makeCHARListEmpty();
  }
  if (ASF_isCHARListSingle(arg)) {
    return ASF_makeCHARListSingle(
        acceptHead ? acceptHead(ASF_getCHARListHead(arg)) : ASF_getCHARListHead(arg));
  }
  if (ASF_isCHARListMany(arg)) {
    return ASF_makeCHARListMany(
        acceptHead ? acceptHead(ASF_getCHARListHead(arg)) : ASF_getCHARListHead(arg),
        acceptWsAfterFirst ? acceptWsAfterFirst(ASF_getCHARListWsAfterFirst(arg)) : ASF_getCHARListWsAfterFirst(arg),
        ASF_visitCHARList(ASF_getCHARListTail(arg), acceptHead, acceptWsAfterFirst));
  }
  ATabort("not a CHARList: %t\n", arg);
  return (ASF_CHARList)NULL;
}

/*}}}  */
/*{{{  ASF_Equation ASF_visitEquation(ASF_Equation arg, ASF_Symbol (*acceptLhsSymbol)(ASF_Symbol), ASF_Symbol (*acceptRhsSymbol)(ASF_Symbol), ASF_Tree (*acceptLhs)(ASF_Tree), ASF_Layout (*acceptWsAfterLhs)(ASF_Layout), ASF_Layout (*acceptWsAfterEquals)(ASF_Layout), ASF_Tree (*acceptRhs)(ASF_Tree)) */

ASF_Equation ASF_visitEquation(ASF_Equation arg, ASF_Symbol (*acceptLhsSymbol)(ASF_Symbol), ASF_Symbol (*acceptRhsSymbol)(ASF_Symbol), ASF_Tree (*acceptLhs)(ASF_Tree), ASF_Layout (*acceptWsAfterLhs)(ASF_Layout), ASF_Layout (*acceptWsAfterEquals)(ASF_Layout), ASF_Tree (*acceptRhs)(ASF_Tree))
{
  if (ASF_isEquationDefault(arg)) {
    return ASF_makeEquationDefault(
        acceptLhsSymbol ? acceptLhsSymbol(ASF_getEquationLhsSymbol(arg)) : ASF_getEquationLhsSymbol(arg),
        acceptRhsSymbol ? acceptRhsSymbol(ASF_getEquationRhsSymbol(arg)) : ASF_getEquationRhsSymbol(arg),
        acceptLhs ? acceptLhs(ASF_getEquationLhs(arg)) : ASF_getEquationLhs(arg),
        acceptWsAfterLhs ? acceptWsAfterLhs(ASF_getEquationWsAfterLhs(arg)) : ASF_getEquationWsAfterLhs(arg),
        acceptWsAfterEquals ? acceptWsAfterEquals(ASF_getEquationWsAfterEquals(arg)) : ASF_getEquationWsAfterEquals(arg),
        acceptRhs ? acceptRhs(ASF_getEquationRhs(arg)) : ASF_getEquationRhs(arg));
  }
  ATabort("not a Equation: %t\n", arg);
  return (ASF_Equation)NULL;
}

/*}}}  */
/*{{{  ASF_Condition ASF_visitCondition(ASF_Condition arg, ASF_Symbol (*acceptLhsSymbol)(ASF_Symbol), ASF_Symbol (*acceptRhsSymbol)(ASF_Symbol), ASF_Tree (*acceptLhs)(ASF_Tree), ASF_Layout (*acceptWsAfterLhs)(ASF_Layout), ASF_Layout (*acceptWsAfterEquals)(ASF_Layout), ASF_Tree (*acceptRhs)(ASF_Tree), ASF_Layout (*acceptWsAfterUnequal)(ASF_Layout)) */

ASF_Condition ASF_visitCondition(ASF_Condition arg, ASF_Symbol (*acceptLhsSymbol)(ASF_Symbol), ASF_Symbol (*acceptRhsSymbol)(ASF_Symbol), ASF_Tree (*acceptLhs)(ASF_Tree), ASF_Layout (*acceptWsAfterLhs)(ASF_Layout), ASF_Layout (*acceptWsAfterEquals)(ASF_Layout), ASF_Tree (*acceptRhs)(ASF_Tree), ASF_Layout (*acceptWsAfterUnequal)(ASF_Layout))
{
  if (ASF_isConditionPositive(arg)) {
    return ASF_makeConditionPositive(
        acceptLhsSymbol ? acceptLhsSymbol(ASF_getConditionLhsSymbol(arg)) : ASF_getConditionLhsSymbol(arg),
        acceptRhsSymbol ? acceptRhsSymbol(ASF_getConditionRhsSymbol(arg)) : ASF_getConditionRhsSymbol(arg),
        acceptLhs ? acceptLhs(ASF_getConditionLhs(arg)) : ASF_getConditionLhs(arg),
        acceptWsAfterLhs ? acceptWsAfterLhs(ASF_getConditionWsAfterLhs(arg)) : ASF_getConditionWsAfterLhs(arg),
        acceptWsAfterEquals ? acceptWsAfterEquals(ASF_getConditionWsAfterEquals(arg)) : ASF_getConditionWsAfterEquals(arg),
        acceptRhs ? acceptRhs(ASF_getConditionRhs(arg)) : ASF_getConditionRhs(arg));
  }
  if (ASF_isConditionNegative(arg)) {
    return ASF_makeConditionNegative(
        acceptLhsSymbol ? acceptLhsSymbol(ASF_getConditionLhsSymbol(arg)) : ASF_getConditionLhsSymbol(arg),
        acceptRhsSymbol ? acceptRhsSymbol(ASF_getConditionRhsSymbol(arg)) : ASF_getConditionRhsSymbol(arg),
        acceptLhs ? acceptLhs(ASF_getConditionLhs(arg)) : ASF_getConditionLhs(arg),
        acceptWsAfterLhs ? acceptWsAfterLhs(ASF_getConditionWsAfterLhs(arg)) : ASF_getConditionWsAfterLhs(arg),
        acceptWsAfterUnequal ? acceptWsAfterUnequal(ASF_getConditionWsAfterUnequal(arg)) : ASF_getConditionWsAfterUnequal(arg),
        acceptRhs ? acceptRhs(ASF_getConditionRhs(arg)) : ASF_getConditionRhs(arg));
  }
  ATabort("not a Condition: %t\n", arg);
  return (ASF_Condition)NULL;
}

/*}}}  */
/*{{{  ASF_TreeAmbs ASF_visitTreeAmbs(ASF_TreeAmbs arg, ASF_Tree (*acceptHead)(ASF_Tree), ASF_Layout (*acceptWsAfterFirst)(ASF_Layout), char * (*acceptSep)(char *), ASF_Layout (*acceptWsAfterSep)(ASF_Layout)) */

ASF_TreeAmbs ASF_visitTreeAmbs(ASF_TreeAmbs arg, ASF_Tree (*acceptHead)(ASF_Tree), ASF_Layout (*acceptWsAfterFirst)(ASF_Layout), char * (*acceptSep)(char *), ASF_Layout (*acceptWsAfterSep)(ASF_Layout))
{
  if (ASF_isTreeAmbsEmpty(arg)) {
    return ASF_makeTreeAmbsEmpty();
  }
  if (ASF_isTreeAmbsSingle(arg)) {
    return ASF_makeTreeAmbsSingle(
        acceptHead ? acceptHead(ASF_getTreeAmbsHead(arg)) : ASF_getTreeAmbsHead(arg));
  }
  if (ASF_isTreeAmbsMany(arg)) {
    return ASF_makeTreeAmbsMany(
        acceptHead ? acceptHead(ASF_getTreeAmbsHead(arg)) : ASF_getTreeAmbsHead(arg),
        acceptWsAfterFirst ? acceptWsAfterFirst(ASF_getTreeAmbsWsAfterFirst(arg)) : ASF_getTreeAmbsWsAfterFirst(arg),
        acceptSep ? acceptSep(ASF_getTreeAmbsSep(arg)) : ASF_getTreeAmbsSep(arg),
        acceptWsAfterSep ? acceptWsAfterSep(ASF_getTreeAmbsWsAfterSep(arg)) : ASF_getTreeAmbsWsAfterSep(arg),
        ASF_visitTreeAmbs(ASF_getTreeAmbsTail(arg), acceptHead, acceptWsAfterFirst, acceptSep, acceptWsAfterSep));
  }
  ATabort("not a TreeAmbs: %t\n", arg);
  return (ASF_TreeAmbs)NULL;
}

/*}}}  */
/*{{{  ASF_CHAR ASF_visitCHAR(ASF_CHAR arg, ASF_Lexical (*acceptLex)(ASF_Lexical)) */

ASF_CHAR ASF_visitCHAR(ASF_CHAR arg, ASF_Lexical (*acceptLex)(ASF_Lexical))
{
  if (ASF_isCHARLexToCf(arg)) {
    return ASF_makeCHARLexToCf(
        acceptLex ? acceptLex(ASF_getCHARLex(arg)) : ASF_getCHARLex(arg));
  }
  ATabort("not a CHAR: %t\n", arg);
  return (ASF_CHAR)NULL;
}

/*}}}  */

/*}}}  */
