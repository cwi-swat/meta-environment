#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "ASFME.h"

/*{{{  typedefs */

typedef struct ATerm _ASF_Production;
typedef struct ATerm _ASF_ASFImplies;
typedef struct ATerm _ASF_ASFTagId;
typedef struct ATerm _ASF_ASFConditions;
typedef struct ATerm _ASF_ASFConditionList;
typedef struct ATerm _ASF_ASFEquations;
typedef struct ATerm _ASF_ASFConditionalEquationList;
typedef struct ATerm _ASF_ASFConditionalEquation;
typedef struct ATerm _ASF_ASFTag;
typedef struct ATerm _ASF_Tree;
typedef struct ATerm _ASF_CHARList;
typedef struct ATerm _ASF_ASFEquation;
typedef struct ATerm _ASF_ASFCondition;
typedef struct ATerm _ASF_TreeAmbs;
typedef struct ATerm _ASF_CHAR;
typedef struct ATerm _ASF_OptLayout;
typedef struct ATerm _ASF_Start;

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
/*{{{  ASF_ASFImplies ASF_ASFImpliesFromTerm(ATerm t) */

ASF_ASFImplies ASF_ASFImpliesFromTerm(ATerm t)
{
  return (ASF_ASFImplies)t;
}

/*}}}  */
/*{{{  ATerm ASF_ASFImpliesToTerm(ASF_ASFImplies arg) */

ATerm ASF_ASFImpliesToTerm(ASF_ASFImplies arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_ASFTagId ASF_ASFTagIdFromTerm(ATerm t) */

ASF_ASFTagId ASF_ASFTagIdFromTerm(ATerm t)
{
  return (ASF_ASFTagId)t;
}

/*}}}  */
/*{{{  ATerm ASF_ASFTagIdToTerm(ASF_ASFTagId arg) */

ATerm ASF_ASFTagIdToTerm(ASF_ASFTagId arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_ASFConditions ASF_ASFConditionsFromTerm(ATerm t) */

ASF_ASFConditions ASF_ASFConditionsFromTerm(ATerm t)
{
  return (ASF_ASFConditions)t;
}

/*}}}  */
/*{{{  ATerm ASF_ASFConditionsToTerm(ASF_ASFConditions arg) */

ATerm ASF_ASFConditionsToTerm(ASF_ASFConditions arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_ASFConditionList ASF_ASFConditionListFromTerm(ATerm t) */

ASF_ASFConditionList ASF_ASFConditionListFromTerm(ATerm t)
{
  return (ASF_ASFConditionList)t;
}

/*}}}  */
/*{{{  ATerm ASF_ASFConditionListToTerm(ASF_ASFConditionList arg) */

ATerm ASF_ASFConditionListToTerm(ASF_ASFConditionList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_ASFEquations ASF_ASFEquationsFromTerm(ATerm t) */

ASF_ASFEquations ASF_ASFEquationsFromTerm(ATerm t)
{
  return (ASF_ASFEquations)t;
}

/*}}}  */
/*{{{  ATerm ASF_ASFEquationsToTerm(ASF_ASFEquations arg) */

ATerm ASF_ASFEquationsToTerm(ASF_ASFEquations arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquationList ASF_ASFConditionalEquationListFromTerm(ATerm t) */

ASF_ASFConditionalEquationList ASF_ASFConditionalEquationListFromTerm(ATerm t)
{
  return (ASF_ASFConditionalEquationList)t;
}

/*}}}  */
/*{{{  ATerm ASF_ASFConditionalEquationListToTerm(ASF_ASFConditionalEquationList arg) */

ATerm ASF_ASFConditionalEquationListToTerm(ASF_ASFConditionalEquationList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquation ASF_ASFConditionalEquationFromTerm(ATerm t) */

ASF_ASFConditionalEquation ASF_ASFConditionalEquationFromTerm(ATerm t)
{
  return (ASF_ASFConditionalEquation)t;
}

/*}}}  */
/*{{{  ATerm ASF_ASFConditionalEquationToTerm(ASF_ASFConditionalEquation arg) */

ATerm ASF_ASFConditionalEquationToTerm(ASF_ASFConditionalEquation arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_ASFTag ASF_ASFTagFromTerm(ATerm t) */

ASF_ASFTag ASF_ASFTagFromTerm(ATerm t)
{
  return (ASF_ASFTag)t;
}

/*}}}  */
/*{{{  ATerm ASF_ASFTagToTerm(ASF_ASFTag arg) */

ATerm ASF_ASFTagToTerm(ASF_ASFTag arg)
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
/*{{{  ASF_ASFEquation ASF_ASFEquationFromTerm(ATerm t) */

ASF_ASFEquation ASF_ASFEquationFromTerm(ATerm t)
{
  return (ASF_ASFEquation)t;
}

/*}}}  */
/*{{{  ATerm ASF_ASFEquationToTerm(ASF_ASFEquation arg) */

ATerm ASF_ASFEquationToTerm(ASF_ASFEquation arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_ASFCondition ASF_ASFConditionFromTerm(ATerm t) */

ASF_ASFCondition ASF_ASFConditionFromTerm(ATerm t)
{
  return (ASF_ASFCondition)t;
}

/*}}}  */
/*{{{  ATerm ASF_ASFConditionToTerm(ASF_ASFCondition arg) */

ATerm ASF_ASFConditionToTerm(ASF_ASFCondition arg)
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
/*{{{  ASF_OptLayout ASF_OptLayoutFromTerm(ATerm t) */

ASF_OptLayout ASF_OptLayoutFromTerm(ATerm t)
{
  return (ASF_OptLayout)t;
}

/*}}}  */
/*{{{  ATerm ASF_OptLayoutToTerm(ASF_OptLayout arg) */

ATerm ASF_OptLayoutToTerm(ASF_OptLayout arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ASF_Start ASF_StartFromTerm(ATerm t) */

ASF_Start ASF_StartFromTerm(ATerm t)
{
  return (ASF_Start)t;
}

/*}}}  */
/*{{{  ATerm ASF_StartToTerm(ASF_Start arg) */

ATerm ASF_StartToTerm(ASF_Start arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*}}}  */
/*{{{  constructors */

/*{{{  ASF_Production ASF_makeProductionLexicalConstructor(char * formalName, ASF_Symbol symbol) */

ASF_Production ASF_makeProductionLexicalConstructor(char * formalName, ASF_Symbol symbol)
{
  return (ASF_Production)(ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun2))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun8))))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun9))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ATmakeAFun(formalName, 0, ATtrue)))), (ATerm)symbol, (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl1(ASF_afun12, (ATerm)ATmakeAppl0(ASF_afun13))))));
}

/*}}}  */
/*{{{  ASF_ASFImplies ASF_makeASFImpliesDefault(ASF_CHARLIST chars) */

ASF_ASFImplies ASF_makeASFImpliesDefault(ASF_CHARLIST chars)
{
  return (ASF_ASFImplies)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun15, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun16)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun16))), (ATerm)ATmakeAppl0(ASF_afun17)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun18, (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun19, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(ASF_afun20, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255)))))), (ATerm)chars)));
}

/*}}}  */
/*{{{  ASF_ASFTagId ASF_makeASFTagIdOneChar(ASF_CHARLIST chars) */

ASF_ASFTagId ASF_makeASFTagIdOneChar(ASF_CHARLIST chars)
{
  return (ASF_ASFTagId)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun15, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun21)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun21))), (ATerm)ATmakeAppl0(ASF_afun17)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun18, (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun19, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(ASF_afun20, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255)))))), (ATerm)chars)));
}

/*}}}  */
/*{{{  ASF_ASFTagId ASF_makeASFTagIdManyChars(ASF_CHARLIST chars) */

ASF_ASFTagId ASF_makeASFTagIdManyChars(ASF_CHARLIST chars)
{
  return (ASF_ASFTagId)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun15, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun21)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun21))), (ATerm)ATmakeAppl0(ASF_afun17)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun18, (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun19, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(ASF_afun20, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255)))))), (ATerm)chars)));
}

/*}}}  */
/*{{{  ASF_ASFConditions ASF_makeASFConditionsDefault(ASF_ASFConditionList list) */

ASF_ASFConditions ASF_makeASFConditionsDefault(ASF_ASFConditionList list)
{
  return (ASF_ASFConditions)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl2(ASF_afun22, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun23)), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun24))))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun25))), (ATerm)ATmakeAppl0(ASF_afun17)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun18, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl2(ASF_afun22, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun23)), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun24))))), (ATerm)list)));
}

/*}}}  */
/*{{{  ASF_ASFConditionList ASF_makeASFConditionListSingle(ASF_ASFCondition head) */

ASF_ASFConditionList ASF_makeASFConditionListSingle(ASF_ASFCondition head)
{
  return (ASF_ASFConditionList)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  ASF_ASFConditionList ASF_makeASFConditionListMany(ASF_ASFCondition head, ASF_OptLayout wsAfterFirst, char * sep, ASF_OptLayout wsAfterSep, ASF_ASFConditionList tail) */

ASF_ASFConditionList ASF_makeASFConditionListMany(ASF_ASFCondition head, ASF_OptLayout wsAfterFirst, char * sep, ASF_OptLayout wsAfterSep, ASF_ASFConditionList tail)
{
  return (ASF_ASFConditionList)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm)wsAfterSep), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)))), (ATerm)wsAfterFirst), (ATerm)head);
}

/*}}}  */
/*{{{  ASF_ASFEquations ASF_makeASFEquationsAbsent() */

ASF_ASFEquations ASF_makeASFEquationsAbsent()
{
  return (ASF_ASFEquations)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATempty, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun26))), (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl1(ASF_afun12, (ATerm)ATmakeAppl0(ASF_afun27)))))), (ATerm)ATempty);
}

/*}}}  */
/*{{{  ASF_ASFEquations ASF_makeASFEquationsPresent(ASF_OptLayout wsAfterEquations, ASF_ASFConditionalEquationList list) */

ASF_ASFEquations ASF_makeASFEquationsPresent(ASF_OptLayout wsAfterEquations, ASF_ASFConditionalEquationList list)
{
  return (ASF_ASFEquations)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun28))))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun29))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun26))), (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl1(ASF_afun12, (ATerm)ATmakeAppl0(ASF_afun30)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun18, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun28))))), (ATerm)list)), (ATerm)wsAfterEquations), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun29))));
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquationList ASF_makeASFConditionalEquationListEmpty() */

ASF_ASFConditionalEquationList ASF_makeASFConditionalEquationListEmpty()
{
  return (ASF_ASFConditionalEquationList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquationList ASF_makeASFConditionalEquationListSingle(ASF_ASFConditionalEquation head) */

ASF_ASFConditionalEquationList ASF_makeASFConditionalEquationListSingle(ASF_ASFConditionalEquation head)
{
  return (ASF_ASFConditionalEquationList)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquationList ASF_makeASFConditionalEquationListMany(ASF_ASFConditionalEquation head, ASF_OptLayout wsAfterFirst, ASF_ASFConditionalEquationList tail) */

ASF_ASFConditionalEquationList ASF_makeASFConditionalEquationListMany(ASF_ASFConditionalEquation head, ASF_OptLayout wsAfterFirst, ASF_ASFConditionalEquationList tail)
{
  return (ASF_ASFConditionalEquationList)(ATerm)ATinsert(ATinsert((ATermList)tail, (ATerm)wsAfterFirst), (ATerm)head);
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquation ASF_makeASFConditionalEquationSimple(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFEquation ASFEquation) */

ASF_ASFConditionalEquation ASF_makeASFConditionalEquationSimple(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFEquation ASFEquation)
{
  return (ASF_ASFConditionalEquation)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun31)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun32)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun28))), (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl1(ASF_afun12, (ATerm)ATmakeAppl0(ASF_afun33)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ASFEquation), (ATerm)wsAfterASFTag), (ATerm)ASFTag));
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquation ASF_makeASFConditionalEquationImplies(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFConditions ASFConditions, ASF_OptLayout wsAfterASFConditions, ASF_ASFImplies ASFImplies, ASF_OptLayout wsAfterASFImplies, ASF_ASFEquation ASFEquation) */

ASF_ASFConditionalEquation ASF_makeASFConditionalEquationImplies(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFConditions ASFConditions, ASF_OptLayout wsAfterASFConditions, ASF_ASFImplies ASFImplies, ASF_OptLayout wsAfterASFImplies, ASF_ASFEquation ASFEquation)
{
  return (ASF_ASFConditionalEquation)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun31)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun16)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun25)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun32)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun28))), (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl1(ASF_afun12, (ATerm)ATmakeAppl0(ASF_afun34)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ASFEquation), (ATerm)wsAfterASFImplies), (ATerm)ASFImplies), (ATerm)wsAfterASFConditions), (ATerm)ASFConditions), (ATerm)wsAfterASFTag), (ATerm)ASFTag));
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquation ASF_makeASFConditionalEquationWhen(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFEquation ASFEquation, ASF_OptLayout wsAfterASFEquation, ASF_OptLayout wsAfterWhen, ASF_ASFConditions ASFConditions) */

ASF_ASFConditionalEquation ASF_makeASFConditionalEquationWhen(ASF_ASFTag ASFTag, ASF_OptLayout wsAfterASFTag, ASF_ASFEquation ASFEquation, ASF_OptLayout wsAfterASFEquation, ASF_OptLayout wsAfterWhen, ASF_ASFConditions ASFConditions)
{
  return (ASF_ASFConditionalEquation)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun25)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun35))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun31)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun32)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun28))), (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl1(ASF_afun12, (ATerm)ATmakeAppl0(ASF_afun35)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ASFConditions), (ATerm)wsAfterWhen), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun35))), (ATerm)wsAfterASFEquation), (ATerm)ASFEquation), (ATerm)wsAfterASFTag), (ATerm)ASFTag));
}

/*}}}  */
/*{{{  ASF_ASFTag ASF_makeASFTagEmpty(ASF_OptLayout wsAfterBracketOpen) */

ASF_ASFTag ASF_makeASFTagEmpty(ASF_OptLayout wsAfterBracketOpen)
{
  return (ASF_ASFTag)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun36))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun37))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun32))), (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl1(ASF_afun12, (ATerm)ATmakeAppl0(ASF_afun38)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun36))), (ATerm)wsAfterBracketOpen), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun37))));
}

/*}}}  */
/*{{{  ASF_ASFTag ASF_makeASFTagNotEmpty(ASF_OptLayout wsAfterBracketOpen, ASF_ASFTagId ASFTagId, ASF_OptLayout wsAfterASFTagId) */

ASF_ASFTag ASF_makeASFTagNotEmpty(ASF_OptLayout wsAfterBracketOpen, ASF_ASFTagId ASFTagId, ASF_OptLayout wsAfterASFTagId)
{
  return (ASF_ASFTag)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun36))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun21)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun37))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun32))), (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl1(ASF_afun12, (ATerm)ATmakeAppl0(ASF_afun39)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun36))), (ATerm)wsAfterASFTagId), (ATerm)ASFTagId), (ATerm)wsAfterBracketOpen), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun37))));
}

/*}}}  */
/*{{{  ASF_Tree ASF_makeTreeLexicalConstructor(char * formalName, ASF_Symbol symbol, ASF_Tree name, ASF_OptLayout wsAfterName, ASF_OptLayout wsAfterParenOpen, ASF_CHARList list, ASF_OptLayout wsAfterList) */

ASF_Tree ASF_makeTreeLexicalConstructor(char * formalName, ASF_Symbol symbol, ASF_Tree name, ASF_OptLayout wsAfterName, ASF_OptLayout wsAfterParenOpen, ASF_CHARList list, ASF_OptLayout wsAfterList)
{
  return (ASF_Tree)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun2))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun8))))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun9))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ATmakeAFun(formalName, 0, ATtrue)))), (ATerm)symbol, (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl1(ASF_afun12, (ATerm)ATmakeAppl0(ASF_afun13)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun2))), (ATerm)wsAfterList), (ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun18, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun8))))), (ATerm)list)), (ATerm)wsAfterParenOpen), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun9))), (ATerm)wsAfterName), (ATerm)name));
}

/*}}}  */
/*{{{  ASF_Tree ASF_makeTreeAmbiguityConstructor(ASF_Symbol amb, ASF_Symbol symbol, ASF_OptLayout wsAfterAmb, ASF_OptLayout wsAfterParenOpen, ASF_Symbol listSymbol, ASF_TreeAmbs ambs, ASF_OptLayout wsAfterAmbs) */

ASF_Tree ASF_makeTreeAmbiguityConstructor(ASF_Symbol amb, ASF_Symbol symbol, ASF_OptLayout wsAfterAmb, ASF_OptLayout wsAfterParenOpen, ASF_Symbol listSymbol, ASF_TreeAmbs ambs, ASF_OptLayout wsAfterAmbs)
{
  return (ASF_Tree)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun2))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl2(ASF_afun40, (ATerm)amb, (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun24))))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun9))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun41))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)symbol), (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl1(ASF_afun12, (ATerm)ATmakeAppl0(ASF_afun42)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun2))), (ATerm)wsAfterAmbs), (ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun18, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl2(ASF_afun40, (ATerm)listSymbol, (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun24))))), (ATerm)ambs)), (ATerm)wsAfterParenOpen), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun9))), (ATerm)wsAfterAmb), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun41))));
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
/*{{{  ASF_CHARList ASF_makeCHARListMany(ASF_CHAR head, ASF_OptLayout wsAfterFirst, ASF_CHARList tail) */

ASF_CHARList ASF_makeCHARListMany(ASF_CHAR head, ASF_OptLayout wsAfterFirst, ASF_CHARList tail)
{
  return (ASF_CHARList)(ATerm)ATinsert(ATinsert((ATermList)tail, (ATerm)wsAfterFirst), (ATerm)head);
}

/*}}}  */
/*{{{  ASF_ASFEquation ASF_makeASFEquationDefault(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterEquals, ASF_Tree rhs) */

ASF_ASFEquation ASF_makeASFEquationDefault(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterEquals, ASF_Tree rhs)
{
  return (ASF_ASFEquation)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)rhsSymbol), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun43))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)lhsSymbol), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun31))), (ATerm)ATmakeAppl0(ASF_afun17)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)rhs), (ATerm)wsAfterEquals), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun43))), (ATerm)wsAfterLhs), (ATerm)lhs));
}

/*}}}  */
/*{{{  ASF_ASFCondition ASF_makeASFConditionPositive(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterEquals, ASF_Tree rhs) */

ASF_ASFCondition ASF_makeASFConditionPositive(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterEquals, ASF_Tree rhs)
{
  return (ASF_ASFCondition)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)rhsSymbol), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun43))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)lhsSymbol), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun23))), (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl1(ASF_afun12, (ATerm)ATmakeAppl0(ASF_afun44)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)rhs), (ATerm)wsAfterEquals), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun43))), (ATerm)wsAfterLhs), (ATerm)lhs));
}

/*}}}  */
/*{{{  ASF_ASFCondition ASF_makeASFConditionNegative(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterUnequal, ASF_Tree rhs) */

ASF_ASFCondition ASF_makeASFConditionNegative(ASF_Symbol lhsSymbol, ASF_Symbol rhsSymbol, ASF_Tree lhs, ASF_OptLayout wsAfterLhs, ASF_OptLayout wsAfterUnequal, ASF_Tree rhs)
{
  return (ASF_ASFCondition)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)rhsSymbol), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun45))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)lhsSymbol), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun23))), (ATerm)ATmakeAppl1(ASF_afun10, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun11, (ATerm)ATmakeAppl1(ASF_afun12, (ATerm)ATmakeAppl0(ASF_afun46)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)rhs), (ATerm)wsAfterUnequal), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ASF_afun45))), (ATerm)wsAfterLhs), (ATerm)lhs));
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
/*{{{  ASF_TreeAmbs ASF_makeTreeAmbsMany(ASF_Tree head, ASF_OptLayout wsAfterFirst, char * sep, ASF_OptLayout wsAfterSep, ASF_TreeAmbs tail) */

ASF_TreeAmbs ASF_makeTreeAmbsMany(ASF_Tree head, ASF_OptLayout wsAfterFirst, char * sep, ASF_OptLayout wsAfterSep, ASF_TreeAmbs tail)
{
  return (ASF_TreeAmbs)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm)wsAfterSep), (ATerm)ATmakeAppl1(ASF_afun1, (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)))), (ATerm)wsAfterFirst), (ATerm)head);
}

/*}}}  */
/*{{{  ASF_CHAR ASF_makeCHARDefault(ASF_CHARLIST chars) */

ASF_CHAR ASF_makeCHARDefault(ASF_CHARLIST chars)
{
  return (ASF_CHAR)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun15, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun8)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun8))), (ATerm)ATmakeAppl0(ASF_afun17)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl1(ASF_afun18, (ATerm)ATmakeAppl1(ASF_afun6, (ATerm)ATmakeAppl1(ASF_afun19, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(ASF_afun20, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255)))))), (ATerm)chars)));
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_makeOptLayoutAbsent() */

ASF_OptLayout ASF_makeOptLayoutAbsent()
{
  return (ASF_OptLayout)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATempty, (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5))), (ATerm)ATmakeAppl0(ASF_afun17)), (ATerm)ATempty);
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_makeOptLayoutPresent(ASF_CHARLIST chars) */

ASF_OptLayout ASF_makeOptLayoutPresent(ASF_CHARLIST chars)
{
  return (ASF_OptLayout)(ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl0(ASF_afun5))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5))), (ATerm)ATmakeAppl0(ASF_afun17)), (ATerm)chars);
}

/*}}}  */
/*{{{  ASF_Start ASF_makeStartASFEquations(ASF_OptLayout wsBefore, ASF_ASFEquations topASFEquations, ASF_OptLayout wsAfter, int ambCnt) */

ASF_Start ASF_makeStartASFEquations(ASF_OptLayout wsBefore, ASF_ASFEquations topASFEquations, ASF_OptLayout wsAfter, int ambCnt)
{
  return (ASF_Start)(ATerm)ATmakeAppl2(ASF_afun47, (ATerm)ATmakeAppl2(ASF_afun14, (ATerm)ATmakeAppl3(ASF_afun0, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun26)))), (ATerm)ATmakeAppl1(ASF_afun3, (ATerm)ATmakeAppl1(ASF_afun4, (ATerm)ATmakeAppl0(ASF_afun5)))), (ATerm)ATmakeAppl1(ASF_afun7, (ATerm)ATmakeAppl0(ASF_afun48)), (ATerm)ATmakeAppl0(ASF_afun17)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topASFEquations), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool ASF_isEqualProduction(ASF_Production arg0, ASF_Production arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualASFImplies(ASF_ASFImplies arg0, ASF_ASFImplies arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualASFTagId(ASF_ASFTagId arg0, ASF_ASFTagId arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualASFConditions(ASF_ASFConditions arg0, ASF_ASFConditions arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualASFConditionList(ASF_ASFConditionList arg0, ASF_ASFConditionList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualASFEquations(ASF_ASFEquations arg0, ASF_ASFEquations arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualASFConditionalEquationList(ASF_ASFConditionalEquationList arg0, ASF_ASFConditionalEquationList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualASFConditionalEquation(ASF_ASFConditionalEquation arg0, ASF_ASFConditionalEquation arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualASFTag(ASF_ASFTag arg0, ASF_ASFTag arg1)
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

ATbool ASF_isEqualASFEquation(ASF_ASFEquation arg0, ASF_ASFEquation arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualASFCondition(ASF_ASFCondition arg0, ASF_ASFCondition arg1)
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

ATbool ASF_isEqualOptLayout(ASF_OptLayout arg0, ASF_OptLayout arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ASF_isEqualStart(ASF_Start arg0, ASF_Start arg1)
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
/*{{{  ASF_ASFImplies accessors */

/*{{{  ATbool ASF_isValidASFImplies(ASF_ASFImplies arg) */

ATbool ASF_isValidASFImplies(ASF_ASFImplies arg)
{
  if (ASF_isASFImpliesDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFImpliesDefault(ASF_ASFImplies arg) */

inline ATbool ASF_isASFImpliesDefault(ASF_ASFImplies arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ASF_patternASFImpliesDefault, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFImpliesChars(ASF_ASFImplies arg) */

ATbool ASF_hasASFImpliesChars(ASF_ASFImplies arg)
{
  if (ASF_isASFImpliesDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_CHARLIST ASF_getASFImpliesChars(ASF_ASFImplies arg) */

ASF_CHARLIST ASF_getASFImpliesChars(ASF_ASFImplies arg)
{
  
    return (ASF_CHARLIST)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  ASF_ASFImplies ASF_setASFImpliesChars(ASF_ASFImplies arg, ASF_CHARLIST chars) */

ASF_ASFImplies ASF_setASFImpliesChars(ASF_ASFImplies arg, ASF_CHARLIST chars)
{
  if (ASF_isASFImpliesDefault(arg)) {
    return (ASF_ASFImplies)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)chars, 1), 0), 1);
  }

  ATabort("ASFImplies has no Chars: %t\n", arg);
  return (ASF_ASFImplies)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_ASFTagId accessors */

/*{{{  ATbool ASF_isValidASFTagId(ASF_ASFTagId arg) */

ATbool ASF_isValidASFTagId(ASF_ASFTagId arg)
{
  if (ASF_isASFTagIdOneChar(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFTagIdManyChars(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFTagIdOneChar(ASF_ASFTagId arg) */

inline ATbool ASF_isASFTagIdOneChar(ASF_ASFTagId arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternASFTagIdOneChar, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFTagIdManyChars(ASF_ASFTagId arg) */

inline ATbool ASF_isASFTagIdManyChars(ASF_ASFTagId arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternASFTagIdManyChars, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ASF_hasASFTagIdChars(ASF_ASFTagId arg) */

ATbool ASF_hasASFTagIdChars(ASF_ASFTagId arg)
{
  if (ASF_isASFTagIdOneChar(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFTagIdManyChars(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_CHARLIST ASF_getASFTagIdChars(ASF_ASFTagId arg) */

ASF_CHARLIST ASF_getASFTagIdChars(ASF_ASFTagId arg)
{
  if (ASF_isASFTagIdOneChar(arg)) {
    return (ASF_CHARLIST)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
  }
  else 
    return (ASF_CHARLIST)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  ASF_ASFTagId ASF_setASFTagIdChars(ASF_ASFTagId arg, ASF_CHARLIST chars) */

ASF_ASFTagId ASF_setASFTagIdChars(ASF_ASFTagId arg, ASF_CHARLIST chars)
{
  if (ASF_isASFTagIdOneChar(arg)) {
    return (ASF_ASFTagId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)chars, 1), 0), 1);
  }
  else if (ASF_isASFTagIdManyChars(arg)) {
    return (ASF_ASFTagId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)chars, 1), 0), 1);
  }

  ATabort("ASFTagId has no Chars: %t\n", arg);
  return (ASF_ASFTagId)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_ASFConditions accessors */

/*{{{  ATbool ASF_isValidASFConditions(ASF_ASFConditions arg) */

ATbool ASF_isValidASFConditions(ASF_ASFConditions arg)
{
  if (ASF_isASFConditionsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFConditionsDefault(ASF_ASFConditions arg) */

inline ATbool ASF_isASFConditionsDefault(ASF_ASFConditions arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ASF_patternASFConditionsDefault, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionsList(ASF_ASFConditions arg) */

ATbool ASF_hasASFConditionsList(ASF_ASFConditions arg)
{
  if (ASF_isASFConditionsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_ASFConditionList ASF_getASFConditionsList(ASF_ASFConditions arg) */

ASF_ASFConditionList ASF_getASFConditionsList(ASF_ASFConditions arg)
{
  
    return (ASF_ASFConditionList)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  ASF_ASFConditions ASF_setASFConditionsList(ASF_ASFConditions arg, ASF_ASFConditionList list) */

ASF_ASFConditions ASF_setASFConditionsList(ASF_ASFConditions arg, ASF_ASFConditionList list)
{
  if (ASF_isASFConditionsDefault(arg)) {
    return (ASF_ASFConditions)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)list, 1), 0), 1);
  }

  ATabort("ASFConditions has no List: %t\n", arg);
  return (ASF_ASFConditions)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_ASFConditionList accessors */

/*{{{  ATbool ASF_isValidASFConditionList(ASF_ASFConditionList arg) */

ATbool ASF_isValidASFConditionList(ASF_ASFConditionList arg)
{
  if (ASF_isASFConditionListSingle(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFConditionListSingle(ASF_ASFConditionList arg) */

inline ATbool ASF_isASFConditionListSingle(ASF_ASFConditionList arg)
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
      last_result = ATmatchTerm((ATerm)arg, ASF_patternASFConditionListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFConditionListMany(ASF_ASFConditionList arg) */

inline ATbool ASF_isASFConditionListMany(ASF_ASFConditionList arg)
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
      last_result = ATmatchTerm((ATerm)arg, ASF_patternASFConditionListMany, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionListHead(ASF_ASFConditionList arg) */

ATbool ASF_hasASFConditionListHead(ASF_ASFConditionList arg)
{
  if (ASF_isASFConditionListSingle(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_ASFCondition ASF_getASFConditionListHead(ASF_ASFConditionList arg) */

ASF_ASFCondition ASF_getASFConditionListHead(ASF_ASFConditionList arg)
{
  if (ASF_isASFConditionListSingle(arg)) {
    return (ASF_ASFCondition)ATgetFirst((ATermList)arg);
  }
  else 
    return (ASF_ASFCondition)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  ASF_ASFConditionList ASF_setASFConditionListHead(ASF_ASFConditionList arg, ASF_ASFCondition head) */

ASF_ASFConditionList ASF_setASFConditionListHead(ASF_ASFConditionList arg, ASF_ASFCondition head)
{
  if (ASF_isASFConditionListSingle(arg)) {
    return (ASF_ASFConditionList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (ASF_isASFConditionListMany(arg)) {
    return (ASF_ASFConditionList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("ASFConditionList has no Head: %t\n", arg);
  return (ASF_ASFConditionList)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionListWsAfterFirst(ASF_ASFConditionList arg) */

ATbool ASF_hasASFConditionListWsAfterFirst(ASF_ASFConditionList arg)
{
  if (ASF_isASFConditionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFConditionListWsAfterFirst(ASF_ASFConditionList arg) */

ASF_OptLayout ASF_getASFConditionListWsAfterFirst(ASF_ASFConditionList arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  ASF_ASFConditionList ASF_setASFConditionListWsAfterFirst(ASF_ASFConditionList arg, ASF_OptLayout wsAfterFirst) */

ASF_ASFConditionList ASF_setASFConditionListWsAfterFirst(ASF_ASFConditionList arg, ASF_OptLayout wsAfterFirst)
{
  if (ASF_isASFConditionListMany(arg)) {
    return (ASF_ASFConditionList)ATreplace((ATermList)arg, (ATerm)wsAfterFirst, 1);
  }

  ATabort("ASFConditionList has no WsAfterFirst: %t\n", arg);
  return (ASF_ASFConditionList)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionListSep(ASF_ASFConditionList arg) */

ATbool ASF_hasASFConditionListSep(ASF_ASFConditionList arg)
{
  if (ASF_isASFConditionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * ASF_getASFConditionListSep(ASF_ASFConditionList arg) */

char * ASF_getASFConditionListSep(ASF_ASFConditionList arg)
{
  
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), 0)));
}

/*}}}  */
/*{{{  ASF_ASFConditionList ASF_setASFConditionListSep(ASF_ASFConditionList arg, char * sep) */

ASF_ASFConditionList ASF_setASFConditionListSep(ASF_ASFConditionList arg, char * sep)
{
  if (ASF_isASFConditionListMany(arg)) {
    return (ASF_ASFConditionList)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)), 0), 2);
  }

  ATabort("ASFConditionList has no Sep: %t\n", arg);
  return (ASF_ASFConditionList)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionListWsAfterSep(ASF_ASFConditionList arg) */

ATbool ASF_hasASFConditionListWsAfterSep(ASF_ASFConditionList arg)
{
  if (ASF_isASFConditionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFConditionListWsAfterSep(ASF_ASFConditionList arg) */

ASF_OptLayout ASF_getASFConditionListWsAfterSep(ASF_ASFConditionList arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  ASF_ASFConditionList ASF_setASFConditionListWsAfterSep(ASF_ASFConditionList arg, ASF_OptLayout wsAfterSep) */

ASF_ASFConditionList ASF_setASFConditionListWsAfterSep(ASF_ASFConditionList arg, ASF_OptLayout wsAfterSep)
{
  if (ASF_isASFConditionListMany(arg)) {
    return (ASF_ASFConditionList)ATreplace((ATermList)arg, (ATerm)wsAfterSep, 3);
  }

  ATabort("ASFConditionList has no WsAfterSep: %t\n", arg);
  return (ASF_ASFConditionList)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionListTail(ASF_ASFConditionList arg) */

ATbool ASF_hasASFConditionListTail(ASF_ASFConditionList arg)
{
  if (ASF_isASFConditionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_ASFConditionList ASF_getASFConditionListTail(ASF_ASFConditionList arg) */

ASF_ASFConditionList ASF_getASFConditionListTail(ASF_ASFConditionList arg)
{
  
    return (ASF_ASFConditionList)ATgetTail((ATermList)arg, 4);
}

/*}}}  */
/*{{{  ASF_ASFConditionList ASF_setASFConditionListTail(ASF_ASFConditionList arg, ASF_ASFConditionList tail) */

ASF_ASFConditionList ASF_setASFConditionListTail(ASF_ASFConditionList arg, ASF_ASFConditionList tail)
{
  if (ASF_isASFConditionListMany(arg)) {
    return (ASF_ASFConditionList)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("ASFConditionList has no Tail: %t\n", arg);
  return (ASF_ASFConditionList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_ASFEquations accessors */

/*{{{  ATbool ASF_isValidASFEquations(ASF_ASFEquations arg) */

ATbool ASF_isValidASFEquations(ASF_ASFEquations arg)
{
  if (ASF_isASFEquationsAbsent(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFEquationsPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFEquationsAbsent(ASF_ASFEquations arg) */

inline ATbool ASF_isASFEquationsAbsent(ASF_ASFEquations arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternASFEquationsAbsent);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFEquationsPresent(ASF_ASFEquations arg) */

inline ATbool ASF_isASFEquationsPresent(ASF_ASFEquations arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternASFEquationsPresent, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ASF_hasASFEquationsWsAfterEquations(ASF_ASFEquations arg) */

ATbool ASF_hasASFEquationsWsAfterEquations(ASF_ASFEquations arg)
{
  if (ASF_isASFEquationsPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFEquationsWsAfterEquations(ASF_ASFEquations arg) */

ASF_OptLayout ASF_getASFEquationsWsAfterEquations(ASF_ASFEquations arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  ASF_ASFEquations ASF_setASFEquationsWsAfterEquations(ASF_ASFEquations arg, ASF_OptLayout wsAfterEquations) */

ASF_ASFEquations ASF_setASFEquationsWsAfterEquations(ASF_ASFEquations arg, ASF_OptLayout wsAfterEquations)
{
  if (ASF_isASFEquationsPresent(arg)) {
    return (ASF_ASFEquations)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterEquations, 1), 1);
  }

  ATabort("ASFEquations has no WsAfterEquations: %t\n", arg);
  return (ASF_ASFEquations)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFEquationsList(ASF_ASFEquations arg) */

ATbool ASF_hasASFEquationsList(ASF_ASFEquations arg)
{
  if (ASF_isASFEquationsPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquationList ASF_getASFEquationsList(ASF_ASFEquations arg) */

ASF_ASFConditionalEquationList ASF_getASFEquationsList(ASF_ASFEquations arg)
{
  
    return (ASF_ASFConditionalEquationList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), 1);
}

/*}}}  */
/*{{{  ASF_ASFEquations ASF_setASFEquationsList(ASF_ASFEquations arg, ASF_ASFConditionalEquationList list) */

ASF_ASFEquations ASF_setASFEquationsList(ASF_ASFEquations arg, ASF_ASFConditionalEquationList list)
{
  if (ASF_isASFEquationsPresent(arg)) {
    return (ASF_ASFEquations)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), (ATerm)list, 1), 2), 1);
  }

  ATabort("ASFEquations has no List: %t\n", arg);
  return (ASF_ASFEquations)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_ASFConditionalEquationList accessors */

/*{{{  ATbool ASF_isValidASFConditionalEquationList(ASF_ASFConditionalEquationList arg) */

ATbool ASF_isValidASFConditionalEquationList(ASF_ASFConditionalEquationList arg)
{
  if (ASF_isASFConditionalEquationListEmpty(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionalEquationListSingle(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionalEquationListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFConditionalEquationListEmpty(ASF_ASFConditionalEquationList arg) */

inline ATbool ASF_isASFConditionalEquationListEmpty(ASF_ASFConditionalEquationList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ASF_patternASFConditionalEquationListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFConditionalEquationListSingle(ASF_ASFConditionalEquationList arg) */

inline ATbool ASF_isASFConditionalEquationListSingle(ASF_ASFConditionalEquationList arg)
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
      last_result = ATmatchTerm((ATerm)arg, ASF_patternASFConditionalEquationListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFConditionalEquationListMany(ASF_ASFConditionalEquationList arg) */

inline ATbool ASF_isASFConditionalEquationListMany(ASF_ASFConditionalEquationList arg)
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
      last_result = ATmatchTerm((ATerm)arg, ASF_patternASFConditionalEquationListMany, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionalEquationListHead(ASF_ASFConditionalEquationList arg) */

ATbool ASF_hasASFConditionalEquationListHead(ASF_ASFConditionalEquationList arg)
{
  if (ASF_isASFConditionalEquationListSingle(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionalEquationListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquation ASF_getASFConditionalEquationListHead(ASF_ASFConditionalEquationList arg) */

ASF_ASFConditionalEquation ASF_getASFConditionalEquationListHead(ASF_ASFConditionalEquationList arg)
{
  if (ASF_isASFConditionalEquationListSingle(arg)) {
    return (ASF_ASFConditionalEquation)ATgetFirst((ATermList)arg);
  }
  else 
    return (ASF_ASFConditionalEquation)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquationList ASF_setASFConditionalEquationListHead(ASF_ASFConditionalEquationList arg, ASF_ASFConditionalEquation head) */

ASF_ASFConditionalEquationList ASF_setASFConditionalEquationListHead(ASF_ASFConditionalEquationList arg, ASF_ASFConditionalEquation head)
{
  if (ASF_isASFConditionalEquationListSingle(arg)) {
    return (ASF_ASFConditionalEquationList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (ASF_isASFConditionalEquationListMany(arg)) {
    return (ASF_ASFConditionalEquationList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("ASFConditionalEquationList has no Head: %t\n", arg);
  return (ASF_ASFConditionalEquationList)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionalEquationListWsAfterFirst(ASF_ASFConditionalEquationList arg) */

ATbool ASF_hasASFConditionalEquationListWsAfterFirst(ASF_ASFConditionalEquationList arg)
{
  if (ASF_isASFConditionalEquationListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFConditionalEquationListWsAfterFirst(ASF_ASFConditionalEquationList arg) */

ASF_OptLayout ASF_getASFConditionalEquationListWsAfterFirst(ASF_ASFConditionalEquationList arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquationList ASF_setASFConditionalEquationListWsAfterFirst(ASF_ASFConditionalEquationList arg, ASF_OptLayout wsAfterFirst) */

ASF_ASFConditionalEquationList ASF_setASFConditionalEquationListWsAfterFirst(ASF_ASFConditionalEquationList arg, ASF_OptLayout wsAfterFirst)
{
  if (ASF_isASFConditionalEquationListMany(arg)) {
    return (ASF_ASFConditionalEquationList)ATreplace((ATermList)arg, (ATerm)wsAfterFirst, 1);
  }

  ATabort("ASFConditionalEquationList has no WsAfterFirst: %t\n", arg);
  return (ASF_ASFConditionalEquationList)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionalEquationListTail(ASF_ASFConditionalEquationList arg) */

ATbool ASF_hasASFConditionalEquationListTail(ASF_ASFConditionalEquationList arg)
{
  if (ASF_isASFConditionalEquationListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquationList ASF_getASFConditionalEquationListTail(ASF_ASFConditionalEquationList arg) */

ASF_ASFConditionalEquationList ASF_getASFConditionalEquationListTail(ASF_ASFConditionalEquationList arg)
{
  
    return (ASF_ASFConditionalEquationList)ATgetTail((ATermList)arg, 2);
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquationList ASF_setASFConditionalEquationListTail(ASF_ASFConditionalEquationList arg, ASF_ASFConditionalEquationList tail) */

ASF_ASFConditionalEquationList ASF_setASFConditionalEquationListTail(ASF_ASFConditionalEquationList arg, ASF_ASFConditionalEquationList tail)
{
  if (ASF_isASFConditionalEquationListMany(arg)) {
    return (ASF_ASFConditionalEquationList)ATreplaceTail((ATermList)arg, (ATermList)tail, 2);
  }

  ATabort("ASFConditionalEquationList has no Tail: %t\n", arg);
  return (ASF_ASFConditionalEquationList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_ASFConditionalEquation accessors */

/*{{{  ATbool ASF_isValidASFConditionalEquation(ASF_ASFConditionalEquation arg) */

ATbool ASF_isValidASFConditionalEquation(ASF_ASFConditionalEquation arg)
{
  if (ASF_isASFConditionalEquationSimple(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionalEquationImplies(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionalEquationWhen(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFConditionalEquationSimple(ASF_ASFConditionalEquation arg) */

inline ATbool ASF_isASFConditionalEquationSimple(ASF_ASFConditionalEquation arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternASFConditionalEquationSimple, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFConditionalEquationImplies(ASF_ASFConditionalEquation arg) */

inline ATbool ASF_isASFConditionalEquationImplies(ASF_ASFConditionalEquation arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternASFConditionalEquationImplies, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFConditionalEquationWhen(ASF_ASFConditionalEquation arg) */

inline ATbool ASF_isASFConditionalEquationWhen(ASF_ASFConditionalEquation arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternASFConditionalEquationWhen, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionalEquationASFTag(ASF_ASFConditionalEquation arg) */

ATbool ASF_hasASFConditionalEquationASFTag(ASF_ASFConditionalEquation arg)
{
  if (ASF_isASFConditionalEquationSimple(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionalEquationImplies(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionalEquationWhen(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_ASFTag ASF_getASFConditionalEquationASFTag(ASF_ASFConditionalEquation arg) */

ASF_ASFTag ASF_getASFConditionalEquationASFTag(ASF_ASFConditionalEquation arg)
{
  if (ASF_isASFConditionalEquationSimple(arg)) {
    return (ASF_ASFTag)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (ASF_isASFConditionalEquationImplies(arg)) {
    return (ASF_ASFTag)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (ASF_ASFTag)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquation ASF_setASFConditionalEquationASFTag(ASF_ASFConditionalEquation arg, ASF_ASFTag ASFTag) */

ASF_ASFConditionalEquation ASF_setASFConditionalEquationASFTag(ASF_ASFConditionalEquation arg, ASF_ASFTag ASFTag)
{
  if (ASF_isASFConditionalEquationSimple(arg)) {
    return (ASF_ASFConditionalEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ASFTag, 0), 1);
  }
  else if (ASF_isASFConditionalEquationImplies(arg)) {
    return (ASF_ASFConditionalEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ASFTag, 0), 1);
  }
  else if (ASF_isASFConditionalEquationWhen(arg)) {
    return (ASF_ASFConditionalEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ASFTag, 0), 1);
  }

  ATabort("ASFConditionalEquation has no ASFTag: %t\n", arg);
  return (ASF_ASFConditionalEquation)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionalEquationWsAfterASFTag(ASF_ASFConditionalEquation arg) */

ATbool ASF_hasASFConditionalEquationWsAfterASFTag(ASF_ASFConditionalEquation arg)
{
  if (ASF_isASFConditionalEquationSimple(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionalEquationImplies(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionalEquationWhen(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFConditionalEquationWsAfterASFTag(ASF_ASFConditionalEquation arg) */

ASF_OptLayout ASF_getASFConditionalEquationWsAfterASFTag(ASF_ASFConditionalEquation arg)
{
  if (ASF_isASFConditionalEquationSimple(arg)) {
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else if (ASF_isASFConditionalEquationImplies(arg)) {
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else 
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquation ASF_setASFConditionalEquationWsAfterASFTag(ASF_ASFConditionalEquation arg, ASF_OptLayout wsAfterASFTag) */

ASF_ASFConditionalEquation ASF_setASFConditionalEquationWsAfterASFTag(ASF_ASFConditionalEquation arg, ASF_OptLayout wsAfterASFTag)
{
  if (ASF_isASFConditionalEquationSimple(arg)) {
    return (ASF_ASFConditionalEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterASFTag, 1), 1);
  }
  else if (ASF_isASFConditionalEquationImplies(arg)) {
    return (ASF_ASFConditionalEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterASFTag, 1), 1);
  }
  else if (ASF_isASFConditionalEquationWhen(arg)) {
    return (ASF_ASFConditionalEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterASFTag, 1), 1);
  }

  ATabort("ASFConditionalEquation has no WsAfterASFTag: %t\n", arg);
  return (ASF_ASFConditionalEquation)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionalEquationASFEquation(ASF_ASFConditionalEquation arg) */

ATbool ASF_hasASFConditionalEquationASFEquation(ASF_ASFConditionalEquation arg)
{
  if (ASF_isASFConditionalEquationSimple(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionalEquationImplies(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionalEquationWhen(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_ASFEquation ASF_getASFConditionalEquationASFEquation(ASF_ASFConditionalEquation arg) */

ASF_ASFEquation ASF_getASFConditionalEquationASFEquation(ASF_ASFConditionalEquation arg)
{
  if (ASF_isASFConditionalEquationSimple(arg)) {
    return (ASF_ASFEquation)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else if (ASF_isASFConditionalEquationImplies(arg)) {
    return (ASF_ASFEquation)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6);
  }
  else 
    return (ASF_ASFEquation)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquation ASF_setASFConditionalEquationASFEquation(ASF_ASFConditionalEquation arg, ASF_ASFEquation ASFEquation) */

ASF_ASFConditionalEquation ASF_setASFConditionalEquationASFEquation(ASF_ASFConditionalEquation arg, ASF_ASFEquation ASFEquation)
{
  if (ASF_isASFConditionalEquationSimple(arg)) {
    return (ASF_ASFConditionalEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ASFEquation, 2), 1);
  }
  else if (ASF_isASFConditionalEquationImplies(arg)) {
    return (ASF_ASFConditionalEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ASFEquation, 6), 1);
  }
  else if (ASF_isASFConditionalEquationWhen(arg)) {
    return (ASF_ASFConditionalEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ASFEquation, 2), 1);
  }

  ATabort("ASFConditionalEquation has no ASFEquation: %t\n", arg);
  return (ASF_ASFConditionalEquation)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionalEquationASFConditions(ASF_ASFConditionalEquation arg) */

ATbool ASF_hasASFConditionalEquationASFConditions(ASF_ASFConditionalEquation arg)
{
  if (ASF_isASFConditionalEquationImplies(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionalEquationWhen(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_ASFConditions ASF_getASFConditionalEquationASFConditions(ASF_ASFConditionalEquation arg) */

ASF_ASFConditions ASF_getASFConditionalEquationASFConditions(ASF_ASFConditionalEquation arg)
{
  if (ASF_isASFConditionalEquationImplies(arg)) {
    return (ASF_ASFConditions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else 
    return (ASF_ASFConditions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6);
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquation ASF_setASFConditionalEquationASFConditions(ASF_ASFConditionalEquation arg, ASF_ASFConditions ASFConditions) */

ASF_ASFConditionalEquation ASF_setASFConditionalEquationASFConditions(ASF_ASFConditionalEquation arg, ASF_ASFConditions ASFConditions)
{
  if (ASF_isASFConditionalEquationImplies(arg)) {
    return (ASF_ASFConditionalEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ASFConditions, 2), 1);
  }
  else if (ASF_isASFConditionalEquationWhen(arg)) {
    return (ASF_ASFConditionalEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ASFConditions, 6), 1);
  }

  ATabort("ASFConditionalEquation has no ASFConditions: %t\n", arg);
  return (ASF_ASFConditionalEquation)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionalEquationWsAfterASFConditions(ASF_ASFConditionalEquation arg) */

ATbool ASF_hasASFConditionalEquationWsAfterASFConditions(ASF_ASFConditionalEquation arg)
{
  if (ASF_isASFConditionalEquationImplies(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFConditionalEquationWsAfterASFConditions(ASF_ASFConditionalEquation arg) */

ASF_OptLayout ASF_getASFConditionalEquationWsAfterASFConditions(ASF_ASFConditionalEquation arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquation ASF_setASFConditionalEquationWsAfterASFConditions(ASF_ASFConditionalEquation arg, ASF_OptLayout wsAfterASFConditions) */

ASF_ASFConditionalEquation ASF_setASFConditionalEquationWsAfterASFConditions(ASF_ASFConditionalEquation arg, ASF_OptLayout wsAfterASFConditions)
{
  if (ASF_isASFConditionalEquationImplies(arg)) {
    return (ASF_ASFConditionalEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterASFConditions, 3), 1);
  }

  ATabort("ASFConditionalEquation has no WsAfterASFConditions: %t\n", arg);
  return (ASF_ASFConditionalEquation)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionalEquationASFImplies(ASF_ASFConditionalEquation arg) */

ATbool ASF_hasASFConditionalEquationASFImplies(ASF_ASFConditionalEquation arg)
{
  if (ASF_isASFConditionalEquationImplies(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_ASFImplies ASF_getASFConditionalEquationASFImplies(ASF_ASFConditionalEquation arg) */

ASF_ASFImplies ASF_getASFConditionalEquationASFImplies(ASF_ASFConditionalEquation arg)
{
  
    return (ASF_ASFImplies)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquation ASF_setASFConditionalEquationASFImplies(ASF_ASFConditionalEquation arg, ASF_ASFImplies ASFImplies) */

ASF_ASFConditionalEquation ASF_setASFConditionalEquationASFImplies(ASF_ASFConditionalEquation arg, ASF_ASFImplies ASFImplies)
{
  if (ASF_isASFConditionalEquationImplies(arg)) {
    return (ASF_ASFConditionalEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ASFImplies, 4), 1);
  }

  ATabort("ASFConditionalEquation has no ASFImplies: %t\n", arg);
  return (ASF_ASFConditionalEquation)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionalEquationWsAfterASFImplies(ASF_ASFConditionalEquation arg) */

ATbool ASF_hasASFConditionalEquationWsAfterASFImplies(ASF_ASFConditionalEquation arg)
{
  if (ASF_isASFConditionalEquationImplies(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFConditionalEquationWsAfterASFImplies(ASF_ASFConditionalEquation arg) */

ASF_OptLayout ASF_getASFConditionalEquationWsAfterASFImplies(ASF_ASFConditionalEquation arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquation ASF_setASFConditionalEquationWsAfterASFImplies(ASF_ASFConditionalEquation arg, ASF_OptLayout wsAfterASFImplies) */

ASF_ASFConditionalEquation ASF_setASFConditionalEquationWsAfterASFImplies(ASF_ASFConditionalEquation arg, ASF_OptLayout wsAfterASFImplies)
{
  if (ASF_isASFConditionalEquationImplies(arg)) {
    return (ASF_ASFConditionalEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterASFImplies, 5), 1);
  }

  ATabort("ASFConditionalEquation has no WsAfterASFImplies: %t\n", arg);
  return (ASF_ASFConditionalEquation)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionalEquationWsAfterASFEquation(ASF_ASFConditionalEquation arg) */

ATbool ASF_hasASFConditionalEquationWsAfterASFEquation(ASF_ASFConditionalEquation arg)
{
  if (ASF_isASFConditionalEquationWhen(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFConditionalEquationWsAfterASFEquation(ASF_ASFConditionalEquation arg) */

ASF_OptLayout ASF_getASFConditionalEquationWsAfterASFEquation(ASF_ASFConditionalEquation arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquation ASF_setASFConditionalEquationWsAfterASFEquation(ASF_ASFConditionalEquation arg, ASF_OptLayout wsAfterASFEquation) */

ASF_ASFConditionalEquation ASF_setASFConditionalEquationWsAfterASFEquation(ASF_ASFConditionalEquation arg, ASF_OptLayout wsAfterASFEquation)
{
  if (ASF_isASFConditionalEquationWhen(arg)) {
    return (ASF_ASFConditionalEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterASFEquation, 3), 1);
  }

  ATabort("ASFConditionalEquation has no WsAfterASFEquation: %t\n", arg);
  return (ASF_ASFConditionalEquation)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionalEquationWsAfterWhen(ASF_ASFConditionalEquation arg) */

ATbool ASF_hasASFConditionalEquationWsAfterWhen(ASF_ASFConditionalEquation arg)
{
  if (ASF_isASFConditionalEquationWhen(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFConditionalEquationWsAfterWhen(ASF_ASFConditionalEquation arg) */

ASF_OptLayout ASF_getASFConditionalEquationWsAfterWhen(ASF_ASFConditionalEquation arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquation ASF_setASFConditionalEquationWsAfterWhen(ASF_ASFConditionalEquation arg, ASF_OptLayout wsAfterWhen) */

ASF_ASFConditionalEquation ASF_setASFConditionalEquationWsAfterWhen(ASF_ASFConditionalEquation arg, ASF_OptLayout wsAfterWhen)
{
  if (ASF_isASFConditionalEquationWhen(arg)) {
    return (ASF_ASFConditionalEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterWhen, 5), 1);
  }

  ATabort("ASFConditionalEquation has no WsAfterWhen: %t\n", arg);
  return (ASF_ASFConditionalEquation)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_ASFTag accessors */

/*{{{  ATbool ASF_isValidASFTag(ASF_ASFTag arg) */

ATbool ASF_isValidASFTag(ASF_ASFTag arg)
{
  if (ASF_isASFTagEmpty(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFTagNotEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFTagEmpty(ASF_ASFTag arg) */

inline ATbool ASF_isASFTagEmpty(ASF_ASFTag arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternASFTagEmpty, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFTagNotEmpty(ASF_ASFTag arg) */

inline ATbool ASF_isASFTagNotEmpty(ASF_ASFTag arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternASFTagNotEmpty, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ASF_hasASFTagWsAfterBracketOpen(ASF_ASFTag arg) */

ATbool ASF_hasASFTagWsAfterBracketOpen(ASF_ASFTag arg)
{
  if (ASF_isASFTagEmpty(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFTagNotEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFTagWsAfterBracketOpen(ASF_ASFTag arg) */

ASF_OptLayout ASF_getASFTagWsAfterBracketOpen(ASF_ASFTag arg)
{
  if (ASF_isASFTagEmpty(arg)) {
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else 
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  ASF_ASFTag ASF_setASFTagWsAfterBracketOpen(ASF_ASFTag arg, ASF_OptLayout wsAfterBracketOpen) */

ASF_ASFTag ASF_setASFTagWsAfterBracketOpen(ASF_ASFTag arg, ASF_OptLayout wsAfterBracketOpen)
{
  if (ASF_isASFTagEmpty(arg)) {
    return (ASF_ASFTag)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterBracketOpen, 1), 1);
  }
  else if (ASF_isASFTagNotEmpty(arg)) {
    return (ASF_ASFTag)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterBracketOpen, 1), 1);
  }

  ATabort("ASFTag has no WsAfterBracketOpen: %t\n", arg);
  return (ASF_ASFTag)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFTagASFTagId(ASF_ASFTag arg) */

ATbool ASF_hasASFTagASFTagId(ASF_ASFTag arg)
{
  if (ASF_isASFTagNotEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_ASFTagId ASF_getASFTagASFTagId(ASF_ASFTag arg) */

ASF_ASFTagId ASF_getASFTagASFTagId(ASF_ASFTag arg)
{
  
    return (ASF_ASFTagId)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  ASF_ASFTag ASF_setASFTagASFTagId(ASF_ASFTag arg, ASF_ASFTagId ASFTagId) */

ASF_ASFTag ASF_setASFTagASFTagId(ASF_ASFTag arg, ASF_ASFTagId ASFTagId)
{
  if (ASF_isASFTagNotEmpty(arg)) {
    return (ASF_ASFTag)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ASFTagId, 2), 1);
  }

  ATabort("ASFTag has no ASFTagId: %t\n", arg);
  return (ASF_ASFTag)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFTagWsAfterASFTagId(ASF_ASFTag arg) */

ATbool ASF_hasASFTagWsAfterASFTagId(ASF_ASFTag arg)
{
  if (ASF_isASFTagNotEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFTagWsAfterASFTagId(ASF_ASFTag arg) */

ASF_OptLayout ASF_getASFTagWsAfterASFTagId(ASF_ASFTag arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  ASF_ASFTag ASF_setASFTagWsAfterASFTagId(ASF_ASFTag arg, ASF_OptLayout wsAfterASFTagId) */

ASF_ASFTag ASF_setASFTagWsAfterASFTagId(ASF_ASFTag arg, ASF_OptLayout wsAfterASFTagId)
{
  if (ASF_isASFTagNotEmpty(arg)) {
    return (ASF_ASFTag)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterASFTagId, 3), 1);
  }

  ATabort("ASFTag has no WsAfterASFTagId: %t\n", arg);
  return (ASF_ASFTag)NULL;
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
  else if (ASF_isTreeAmbiguityConstructor(arg)) {
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
/*{{{  inline ATbool ASF_isTreeAmbiguityConstructor(ASF_Tree arg) */

inline ATbool ASF_isTreeAmbiguityConstructor(ASF_Tree arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternTreeAmbiguityConstructor, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
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
  else if (ASF_isTreeAmbiguityConstructor(arg)) {
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
  else if (ASF_isTreeAmbiguityConstructor(arg)) {
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
/*{{{  ASF_OptLayout ASF_getTreeWsAfterName(ASF_Tree arg) */

ASF_OptLayout ASF_getTreeWsAfterName(ASF_Tree arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  ASF_Tree ASF_setTreeWsAfterName(ASF_Tree arg, ASF_OptLayout wsAfterName) */

ASF_Tree ASF_setTreeWsAfterName(ASF_Tree arg, ASF_OptLayout wsAfterName)
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
  else if (ASF_isTreeAmbiguityConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getTreeWsAfterParenOpen(ASF_Tree arg) */

ASF_OptLayout ASF_getTreeWsAfterParenOpen(ASF_Tree arg)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  ASF_Tree ASF_setTreeWsAfterParenOpen(ASF_Tree arg, ASF_OptLayout wsAfterParenOpen) */

ASF_Tree ASF_setTreeWsAfterParenOpen(ASF_Tree arg, ASF_OptLayout wsAfterParenOpen)
{
  if (ASF_isTreeLexicalConstructor(arg)) {
    return (ASF_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenOpen, 3), 1);
  }
  else if (ASF_isTreeAmbiguityConstructor(arg)) {
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
/*{{{  ASF_OptLayout ASF_getTreeWsAfterList(ASF_Tree arg) */

ASF_OptLayout ASF_getTreeWsAfterList(ASF_Tree arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  ASF_Tree ASF_setTreeWsAfterList(ASF_Tree arg, ASF_OptLayout wsAfterList) */

ASF_Tree ASF_setTreeWsAfterList(ASF_Tree arg, ASF_OptLayout wsAfterList)
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
  if (ASF_isTreeAmbiguityConstructor(arg)) {
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
  if (ASF_isTreeAmbiguityConstructor(arg)) {
    return (ASF_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), 4), (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), 4), 0), (ATerm)amb, 0), 0), 4), 0), 0);
  }

  ATabort("Tree has no Amb: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasTreeWsAfterAmb(ASF_Tree arg) */

ATbool ASF_hasTreeWsAfterAmb(ASF_Tree arg)
{
  if (ASF_isTreeAmbiguityConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getTreeWsAfterAmb(ASF_Tree arg) */

ASF_OptLayout ASF_getTreeWsAfterAmb(ASF_Tree arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  ASF_Tree ASF_setTreeWsAfterAmb(ASF_Tree arg, ASF_OptLayout wsAfterAmb) */

ASF_Tree ASF_setTreeWsAfterAmb(ASF_Tree arg, ASF_OptLayout wsAfterAmb)
{
  if (ASF_isTreeAmbiguityConstructor(arg)) {
    return (ASF_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterAmb, 1), 1);
  }

  ATabort("Tree has no WsAfterAmb: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasTreeListSymbol(ASF_Tree arg) */

ATbool ASF_hasTreeListSymbol(ASF_Tree arg)
{
  if (ASF_isTreeAmbiguityConstructor(arg)) {
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
  if (ASF_isTreeAmbiguityConstructor(arg)) {
    return (ASF_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), 0), (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), 0), 0), (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), 0), 0), 0), (ATerm)listSymbol, 0), 0), 0), 0), 4), 1);
  }

  ATabort("Tree has no ListSymbol: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasTreeAmbs(ASF_Tree arg) */

ATbool ASF_hasTreeAmbs(ASF_Tree arg)
{
  if (ASF_isTreeAmbiguityConstructor(arg)) {
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
  if (ASF_isTreeAmbiguityConstructor(arg)) {
    return (ASF_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), (ATerm)ambs, 1), 4), 1);
  }

  ATabort("Tree has no Ambs: %t\n", arg);
  return (ASF_Tree)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasTreeWsAfterAmbs(ASF_Tree arg) */

ATbool ASF_hasTreeWsAfterAmbs(ASF_Tree arg)
{
  if (ASF_isTreeAmbiguityConstructor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getTreeWsAfterAmbs(ASF_Tree arg) */

ASF_OptLayout ASF_getTreeWsAfterAmbs(ASF_Tree arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  ASF_Tree ASF_setTreeWsAfterAmbs(ASF_Tree arg, ASF_OptLayout wsAfterAmbs) */

ASF_Tree ASF_setTreeWsAfterAmbs(ASF_Tree arg, ASF_OptLayout wsAfterAmbs)
{
  if (ASF_isTreeAmbiguityConstructor(arg)) {
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
/*{{{  ASF_OptLayout ASF_getCHARListWsAfterFirst(ASF_CHARList arg) */

ASF_OptLayout ASF_getCHARListWsAfterFirst(ASF_CHARList arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  ASF_CHARList ASF_setCHARListWsAfterFirst(ASF_CHARList arg, ASF_OptLayout wsAfterFirst) */

ASF_CHARList ASF_setCHARListWsAfterFirst(ASF_CHARList arg, ASF_OptLayout wsAfterFirst)
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
/*{{{  ASF_ASFEquation accessors */

/*{{{  ATbool ASF_isValidASFEquation(ASF_ASFEquation arg) */

ATbool ASF_isValidASFEquation(ASF_ASFEquation arg)
{
  if (ASF_isASFEquationDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFEquationDefault(ASF_ASFEquation arg) */

inline ATbool ASF_isASFEquationDefault(ASF_ASFEquation arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ASF_patternASFEquationDefault, NULL, NULL, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFEquationLhsSymbol(ASF_ASFEquation arg) */

ATbool ASF_hasASFEquationLhsSymbol(ASF_ASFEquation arg)
{
  if (ASF_isASFEquationDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Symbol ASF_getASFEquationLhsSymbol(ASF_ASFEquation arg) */

ASF_Symbol ASF_getASFEquationLhsSymbol(ASF_ASFEquation arg)
{
  
    return (ASF_Symbol)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0));
}

/*}}}  */
/*{{{  ASF_ASFEquation ASF_setASFEquationLhsSymbol(ASF_ASFEquation arg, ASF_Symbol lhsSymbol) */

ASF_ASFEquation ASF_setASFEquationLhsSymbol(ASF_ASFEquation arg, ASF_Symbol lhsSymbol)
{
  if (ASF_isASFEquationDefault(arg)) {
    return (ASF_ASFEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)lhsSymbol, 0), 0), 0);
  }

  ATabort("ASFEquation has no LhsSymbol: %t\n", arg);
  return (ASF_ASFEquation)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFEquationRhsSymbol(ASF_ASFEquation arg) */

ATbool ASF_hasASFEquationRhsSymbol(ASF_ASFEquation arg)
{
  if (ASF_isASFEquationDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Symbol ASF_getASFEquationRhsSymbol(ASF_ASFEquation arg) */

ASF_Symbol ASF_getASFEquationRhsSymbol(ASF_ASFEquation arg)
{
  
    return (ASF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), 4);
}

/*}}}  */
/*{{{  ASF_ASFEquation ASF_setASFEquationRhsSymbol(ASF_ASFEquation arg, ASF_Symbol rhsSymbol) */

ASF_ASFEquation ASF_setASFEquationRhsSymbol(ASF_ASFEquation arg, ASF_Symbol rhsSymbol)
{
  if (ASF_isASFEquationDefault(arg)) {
    return (ASF_ASFEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)rhsSymbol, 4), 0), 0);
  }

  ATabort("ASFEquation has no RhsSymbol: %t\n", arg);
  return (ASF_ASFEquation)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFEquationLhs(ASF_ASFEquation arg) */

ATbool ASF_hasASFEquationLhs(ASF_ASFEquation arg)
{
  if (ASF_isASFEquationDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Tree ASF_getASFEquationLhs(ASF_ASFEquation arg) */

ASF_Tree ASF_getASFEquationLhs(ASF_ASFEquation arg)
{
  
    return (ASF_Tree)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  ASF_ASFEquation ASF_setASFEquationLhs(ASF_ASFEquation arg, ASF_Tree lhs) */

ASF_ASFEquation ASF_setASFEquationLhs(ASF_ASFEquation arg, ASF_Tree lhs)
{
  if (ASF_isASFEquationDefault(arg)) {
    return (ASF_ASFEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)lhs, 0), 1);
  }

  ATabort("ASFEquation has no Lhs: %t\n", arg);
  return (ASF_ASFEquation)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFEquationWsAfterLhs(ASF_ASFEquation arg) */

ATbool ASF_hasASFEquationWsAfterLhs(ASF_ASFEquation arg)
{
  if (ASF_isASFEquationDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFEquationWsAfterLhs(ASF_ASFEquation arg) */

ASF_OptLayout ASF_getASFEquationWsAfterLhs(ASF_ASFEquation arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  ASF_ASFEquation ASF_setASFEquationWsAfterLhs(ASF_ASFEquation arg, ASF_OptLayout wsAfterLhs) */

ASF_ASFEquation ASF_setASFEquationWsAfterLhs(ASF_ASFEquation arg, ASF_OptLayout wsAfterLhs)
{
  if (ASF_isASFEquationDefault(arg)) {
    return (ASF_ASFEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLhs, 1), 1);
  }

  ATabort("ASFEquation has no WsAfterLhs: %t\n", arg);
  return (ASF_ASFEquation)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFEquationWsAfterEquals(ASF_ASFEquation arg) */

ATbool ASF_hasASFEquationWsAfterEquals(ASF_ASFEquation arg)
{
  if (ASF_isASFEquationDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFEquationWsAfterEquals(ASF_ASFEquation arg) */

ASF_OptLayout ASF_getASFEquationWsAfterEquals(ASF_ASFEquation arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  ASF_ASFEquation ASF_setASFEquationWsAfterEquals(ASF_ASFEquation arg, ASF_OptLayout wsAfterEquals) */

ASF_ASFEquation ASF_setASFEquationWsAfterEquals(ASF_ASFEquation arg, ASF_OptLayout wsAfterEquals)
{
  if (ASF_isASFEquationDefault(arg)) {
    return (ASF_ASFEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterEquals, 3), 1);
  }

  ATabort("ASFEquation has no WsAfterEquals: %t\n", arg);
  return (ASF_ASFEquation)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFEquationRhs(ASF_ASFEquation arg) */

ATbool ASF_hasASFEquationRhs(ASF_ASFEquation arg)
{
  if (ASF_isASFEquationDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Tree ASF_getASFEquationRhs(ASF_ASFEquation arg) */

ASF_Tree ASF_getASFEquationRhs(ASF_ASFEquation arg)
{
  
    return (ASF_Tree)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  ASF_ASFEquation ASF_setASFEquationRhs(ASF_ASFEquation arg, ASF_Tree rhs) */

ASF_ASFEquation ASF_setASFEquationRhs(ASF_ASFEquation arg, ASF_Tree rhs)
{
  if (ASF_isASFEquationDefault(arg)) {
    return (ASF_ASFEquation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)rhs, 4), 1);
  }

  ATabort("ASFEquation has no Rhs: %t\n", arg);
  return (ASF_ASFEquation)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_ASFCondition accessors */

/*{{{  ATbool ASF_isValidASFCondition(ASF_ASFCondition arg) */

ATbool ASF_isValidASFCondition(ASF_ASFCondition arg)
{
  if (ASF_isASFConditionPositive(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionNegative(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFConditionPositive(ASF_ASFCondition arg) */

inline ATbool ASF_isASFConditionPositive(ASF_ASFCondition arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternASFConditionPositive, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isASFConditionNegative(ASF_ASFCondition arg) */

inline ATbool ASF_isASFConditionNegative(ASF_ASFCondition arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternASFConditionNegative, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionLhsSymbol(ASF_ASFCondition arg) */

ATbool ASF_hasASFConditionLhsSymbol(ASF_ASFCondition arg)
{
  if (ASF_isASFConditionPositive(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionNegative(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Symbol ASF_getASFConditionLhsSymbol(ASF_ASFCondition arg) */

ASF_Symbol ASF_getASFConditionLhsSymbol(ASF_ASFCondition arg)
{
  if (ASF_isASFConditionPositive(arg)) {
    return (ASF_Symbol)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0));
  }
  else 
    return (ASF_Symbol)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0));
}

/*}}}  */
/*{{{  ASF_ASFCondition ASF_setASFConditionLhsSymbol(ASF_ASFCondition arg, ASF_Symbol lhsSymbol) */

ASF_ASFCondition ASF_setASFConditionLhsSymbol(ASF_ASFCondition arg, ASF_Symbol lhsSymbol)
{
  if (ASF_isASFConditionPositive(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)lhsSymbol, 0), 0), 0);
  }
  else if (ASF_isASFConditionNegative(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)lhsSymbol, 0), 0), 0);
  }

  ATabort("ASFCondition has no LhsSymbol: %t\n", arg);
  return (ASF_ASFCondition)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionRhsSymbol(ASF_ASFCondition arg) */

ATbool ASF_hasASFConditionRhsSymbol(ASF_ASFCondition arg)
{
  if (ASF_isASFConditionPositive(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionNegative(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Symbol ASF_getASFConditionRhsSymbol(ASF_ASFCondition arg) */

ASF_Symbol ASF_getASFConditionRhsSymbol(ASF_ASFCondition arg)
{
  if (ASF_isASFConditionPositive(arg)) {
    return (ASF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), 4);
  }
  else 
    return (ASF_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), 4);
}

/*}}}  */
/*{{{  ASF_ASFCondition ASF_setASFConditionRhsSymbol(ASF_ASFCondition arg, ASF_Symbol rhsSymbol) */

ASF_ASFCondition ASF_setASFConditionRhsSymbol(ASF_ASFCondition arg, ASF_Symbol rhsSymbol)
{
  if (ASF_isASFConditionPositive(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)rhsSymbol, 4), 0), 0);
  }
  else if (ASF_isASFConditionNegative(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)rhsSymbol, 4), 0), 0);
  }

  ATabort("ASFCondition has no RhsSymbol: %t\n", arg);
  return (ASF_ASFCondition)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionLhs(ASF_ASFCondition arg) */

ATbool ASF_hasASFConditionLhs(ASF_ASFCondition arg)
{
  if (ASF_isASFConditionPositive(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionNegative(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Tree ASF_getASFConditionLhs(ASF_ASFCondition arg) */

ASF_Tree ASF_getASFConditionLhs(ASF_ASFCondition arg)
{
  if (ASF_isASFConditionPositive(arg)) {
    return (ASF_Tree)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (ASF_Tree)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  ASF_ASFCondition ASF_setASFConditionLhs(ASF_ASFCondition arg, ASF_Tree lhs) */

ASF_ASFCondition ASF_setASFConditionLhs(ASF_ASFCondition arg, ASF_Tree lhs)
{
  if (ASF_isASFConditionPositive(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)lhs, 0), 1);
  }
  else if (ASF_isASFConditionNegative(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)lhs, 0), 1);
  }

  ATabort("ASFCondition has no Lhs: %t\n", arg);
  return (ASF_ASFCondition)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionWsAfterLhs(ASF_ASFCondition arg) */

ATbool ASF_hasASFConditionWsAfterLhs(ASF_ASFCondition arg)
{
  if (ASF_isASFConditionPositive(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionNegative(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFConditionWsAfterLhs(ASF_ASFCondition arg) */

ASF_OptLayout ASF_getASFConditionWsAfterLhs(ASF_ASFCondition arg)
{
  if (ASF_isASFConditionPositive(arg)) {
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else 
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  ASF_ASFCondition ASF_setASFConditionWsAfterLhs(ASF_ASFCondition arg, ASF_OptLayout wsAfterLhs) */

ASF_ASFCondition ASF_setASFConditionWsAfterLhs(ASF_ASFCondition arg, ASF_OptLayout wsAfterLhs)
{
  if (ASF_isASFConditionPositive(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLhs, 1), 1);
  }
  else if (ASF_isASFConditionNegative(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLhs, 1), 1);
  }

  ATabort("ASFCondition has no WsAfterLhs: %t\n", arg);
  return (ASF_ASFCondition)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionWsAfterEquals(ASF_ASFCondition arg) */

ATbool ASF_hasASFConditionWsAfterEquals(ASF_ASFCondition arg)
{
  if (ASF_isASFConditionPositive(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFConditionWsAfterEquals(ASF_ASFCondition arg) */

ASF_OptLayout ASF_getASFConditionWsAfterEquals(ASF_ASFCondition arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  ASF_ASFCondition ASF_setASFConditionWsAfterEquals(ASF_ASFCondition arg, ASF_OptLayout wsAfterEquals) */

ASF_ASFCondition ASF_setASFConditionWsAfterEquals(ASF_ASFCondition arg, ASF_OptLayout wsAfterEquals)
{
  if (ASF_isASFConditionPositive(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterEquals, 3), 1);
  }

  ATabort("ASFCondition has no WsAfterEquals: %t\n", arg);
  return (ASF_ASFCondition)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionRhs(ASF_ASFCondition arg) */

ATbool ASF_hasASFConditionRhs(ASF_ASFCondition arg)
{
  if (ASF_isASFConditionPositive(arg)) {
    return ATtrue;
  }
  else if (ASF_isASFConditionNegative(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_Tree ASF_getASFConditionRhs(ASF_ASFCondition arg) */

ASF_Tree ASF_getASFConditionRhs(ASF_ASFCondition arg)
{
  if (ASF_isASFConditionPositive(arg)) {
    return (ASF_Tree)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (ASF_Tree)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  ASF_ASFCondition ASF_setASFConditionRhs(ASF_ASFCondition arg, ASF_Tree rhs) */

ASF_ASFCondition ASF_setASFConditionRhs(ASF_ASFCondition arg, ASF_Tree rhs)
{
  if (ASF_isASFConditionPositive(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)rhs, 4), 1);
  }
  else if (ASF_isASFConditionNegative(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)rhs, 4), 1);
  }

  ATabort("ASFCondition has no Rhs: %t\n", arg);
  return (ASF_ASFCondition)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasASFConditionWsAfterUnequal(ASF_ASFCondition arg) */

ATbool ASF_hasASFConditionWsAfterUnequal(ASF_ASFCondition arg)
{
  if (ASF_isASFConditionNegative(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getASFConditionWsAfterUnequal(ASF_ASFCondition arg) */

ASF_OptLayout ASF_getASFConditionWsAfterUnequal(ASF_ASFCondition arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  ASF_ASFCondition ASF_setASFConditionWsAfterUnequal(ASF_ASFCondition arg, ASF_OptLayout wsAfterUnequal) */

ASF_ASFCondition ASF_setASFConditionWsAfterUnequal(ASF_ASFCondition arg, ASF_OptLayout wsAfterUnequal)
{
  if (ASF_isASFConditionNegative(arg)) {
    return (ASF_ASFCondition)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterUnequal, 3), 1);
  }

  ATabort("ASFCondition has no WsAfterUnequal: %t\n", arg);
  return (ASF_ASFCondition)NULL;
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
/*{{{  ASF_OptLayout ASF_getTreeAmbsWsAfterFirst(ASF_TreeAmbs arg) */

ASF_OptLayout ASF_getTreeAmbsWsAfterFirst(ASF_TreeAmbs arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  ASF_TreeAmbs ASF_setTreeAmbsWsAfterFirst(ASF_TreeAmbs arg, ASF_OptLayout wsAfterFirst) */

ASF_TreeAmbs ASF_setTreeAmbsWsAfterFirst(ASF_TreeAmbs arg, ASF_OptLayout wsAfterFirst)
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
/*{{{  ASF_OptLayout ASF_getTreeAmbsWsAfterSep(ASF_TreeAmbs arg) */

ASF_OptLayout ASF_getTreeAmbsWsAfterSep(ASF_TreeAmbs arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  ASF_TreeAmbs ASF_setTreeAmbsWsAfterSep(ASF_TreeAmbs arg, ASF_OptLayout wsAfterSep) */

ASF_TreeAmbs ASF_setTreeAmbsWsAfterSep(ASF_TreeAmbs arg, ASF_OptLayout wsAfterSep)
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
  if (ASF_isCHARDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isCHARDefault(ASF_CHAR arg) */

inline ATbool ASF_isCHARDefault(ASF_CHAR arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ASF_patternCHARDefault, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool ASF_hasCHARChars(ASF_CHAR arg) */

ATbool ASF_hasCHARChars(ASF_CHAR arg)
{
  if (ASF_isCHARDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_CHARLIST ASF_getCHARChars(ASF_CHAR arg) */

ASF_CHARLIST ASF_getCHARChars(ASF_CHAR arg)
{
  
    return (ASF_CHARLIST)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  ASF_CHAR ASF_setCHARChars(ASF_CHAR arg, ASF_CHARLIST chars) */

ASF_CHAR ASF_setCHARChars(ASF_CHAR arg, ASF_CHARLIST chars)
{
  if (ASF_isCHARDefault(arg)) {
    return (ASF_CHAR)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)chars, 1), 0), 1);
  }

  ATabort("CHAR has no Chars: %t\n", arg);
  return (ASF_CHAR)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_OptLayout accessors */

/*{{{  ATbool ASF_isValidOptLayout(ASF_OptLayout arg) */

ATbool ASF_isValidOptLayout(ASF_OptLayout arg)
{
  if (ASF_isOptLayoutAbsent(arg)) {
    return ATtrue;
  }
  else if (ASF_isOptLayoutPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isOptLayoutAbsent(ASF_OptLayout arg) */

inline ATbool ASF_isOptLayoutAbsent(ASF_OptLayout arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternOptLayoutAbsent);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ASF_isOptLayoutPresent(ASF_OptLayout arg) */

inline ATbool ASF_isOptLayoutPresent(ASF_OptLayout arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ASF_patternOptLayoutPresent, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ASF_hasOptLayoutChars(ASF_OptLayout arg) */

ATbool ASF_hasOptLayoutChars(ASF_OptLayout arg)
{
  if (ASF_isOptLayoutPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_CHARLIST ASF_getOptLayoutChars(ASF_OptLayout arg) */

ASF_CHARLIST ASF_getOptLayoutChars(ASF_OptLayout arg)
{
  
    return (ASF_CHARLIST)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_setOptLayoutChars(ASF_OptLayout arg, ASF_CHARLIST chars) */

ASF_OptLayout ASF_setOptLayoutChars(ASF_OptLayout arg, ASF_CHARLIST chars)
{
  if (ASF_isOptLayoutPresent(arg)) {
    return (ASF_OptLayout)ATsetArgument((ATermAppl)arg, (ATerm)chars, 1);
  }

  ATabort("OptLayout has no Chars: %t\n", arg);
  return (ASF_OptLayout)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ASF_Start accessors */

/*{{{  ATbool ASF_isValidStart(ASF_Start arg) */

ATbool ASF_isValidStart(ASF_Start arg)
{
  if (ASF_isStartASFEquations(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ASF_isStartASFEquations(ASF_Start arg) */

inline ATbool ASF_isStartASFEquations(ASF_Start arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ASF_patternStartASFEquations, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool ASF_hasStartWsBefore(ASF_Start arg) */

ATbool ASF_hasStartWsBefore(ASF_Start arg)
{
  if (ASF_isStartASFEquations(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getStartWsBefore(ASF_Start arg) */

ASF_OptLayout ASF_getStartWsBefore(ASF_Start arg)
{
  
    return (ASF_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
}

/*}}}  */
/*{{{  ASF_Start ASF_setStartWsBefore(ASF_Start arg, ASF_OptLayout wsBefore) */

ASF_Start ASF_setStartWsBefore(ASF_Start arg, ASF_OptLayout wsBefore)
{
  if (ASF_isStartASFEquations(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }

  ATabort("Start has no WsBefore: %t\n", arg);
  return (ASF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasStartTopASFEquations(ASF_Start arg) */

ATbool ASF_hasStartTopASFEquations(ASF_Start arg)
{
  if (ASF_isStartASFEquations(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_ASFEquations ASF_getStartTopASFEquations(ASF_Start arg) */

ASF_ASFEquations ASF_getStartTopASFEquations(ASF_Start arg)
{
  
    return (ASF_ASFEquations)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  ASF_Start ASF_setStartTopASFEquations(ASF_Start arg, ASF_ASFEquations topASFEquations) */

ASF_Start ASF_setStartTopASFEquations(ASF_Start arg, ASF_ASFEquations topASFEquations)
{
  if (ASF_isStartASFEquations(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topASFEquations, 1), 1), 0);
  }

  ATabort("Start has no TopASFEquations: %t\n", arg);
  return (ASF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasStartWsAfter(ASF_Start arg) */

ATbool ASF_hasStartWsAfter(ASF_Start arg)
{
  if (ASF_isStartASFEquations(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_getStartWsAfter(ASF_Start arg) */

ASF_OptLayout ASF_getStartWsAfter(ASF_Start arg)
{
  
    return (ASF_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
}

/*}}}  */
/*{{{  ASF_Start ASF_setStartWsAfter(ASF_Start arg, ASF_OptLayout wsAfter) */

ASF_Start ASF_setStartWsAfter(ASF_Start arg, ASF_OptLayout wsAfter)
{
  if (ASF_isStartASFEquations(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }

  ATabort("Start has no WsAfter: %t\n", arg);
  return (ASF_Start)NULL;
}

/*}}}  */
/*{{{  ATbool ASF_hasStartAmbCnt(ASF_Start arg) */

ATbool ASF_hasStartAmbCnt(ASF_Start arg)
{
  if (ASF_isStartASFEquations(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int ASF_getStartAmbCnt(ASF_Start arg) */

int ASF_getStartAmbCnt(ASF_Start arg)
{
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  ASF_Start ASF_setStartAmbCnt(ASF_Start arg, int ambCnt) */

ASF_Start ASF_setStartAmbCnt(ASF_Start arg, int ambCnt)
{
  if (ASF_isStartASFEquations(arg)) {
    return (ASF_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }

  ATabort("Start has no AmbCnt: %t\n", arg);
  return (ASF_Start)NULL;
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
/*{{{  ASF_ASFImplies ASF_visitASFImplies(ASF_ASFImplies arg, ASF_CHARLIST (*acceptChars)(ASF_CHARLIST)) */

ASF_ASFImplies ASF_visitASFImplies(ASF_ASFImplies arg, ASF_CHARLIST (*acceptChars)(ASF_CHARLIST))
{
  if (ASF_isASFImpliesDefault(arg)) {
    return ASF_makeASFImpliesDefault(
        acceptChars ? acceptChars(ASF_getASFImpliesChars(arg)) : ASF_getASFImpliesChars(arg));
  }
  ATabort("not a ASFImplies: %t\n", arg);
  return (ASF_ASFImplies)NULL;
}

/*}}}  */
/*{{{  ASF_ASFTagId ASF_visitASFTagId(ASF_ASFTagId arg, ASF_CHARLIST (*acceptChars)(ASF_CHARLIST)) */

ASF_ASFTagId ASF_visitASFTagId(ASF_ASFTagId arg, ASF_CHARLIST (*acceptChars)(ASF_CHARLIST))
{
  if (ASF_isASFTagIdOneChar(arg)) {
    return ASF_makeASFTagIdOneChar(
        acceptChars ? acceptChars(ASF_getASFTagIdChars(arg)) : ASF_getASFTagIdChars(arg));
  }
  if (ASF_isASFTagIdManyChars(arg)) {
    return ASF_makeASFTagIdManyChars(
        acceptChars ? acceptChars(ASF_getASFTagIdChars(arg)) : ASF_getASFTagIdChars(arg));
  }
  ATabort("not a ASFTagId: %t\n", arg);
  return (ASF_ASFTagId)NULL;
}

/*}}}  */
/*{{{  ASF_ASFConditions ASF_visitASFConditions(ASF_ASFConditions arg, ASF_ASFConditionList (*acceptList)(ASF_ASFConditionList)) */

ASF_ASFConditions ASF_visitASFConditions(ASF_ASFConditions arg, ASF_ASFConditionList (*acceptList)(ASF_ASFConditionList))
{
  if (ASF_isASFConditionsDefault(arg)) {
    return ASF_makeASFConditionsDefault(
        acceptList ? acceptList(ASF_getASFConditionsList(arg)) : ASF_getASFConditionsList(arg));
  }
  ATabort("not a ASFConditions: %t\n", arg);
  return (ASF_ASFConditions)NULL;
}

/*}}}  */
/*{{{  ASF_ASFConditionList ASF_visitASFConditionList(ASF_ASFConditionList arg, ASF_ASFCondition (*acceptHead)(ASF_ASFCondition), ASF_OptLayout (*acceptWsAfterFirst)(ASF_OptLayout), char * (*acceptSep)(char *), ASF_OptLayout (*acceptWsAfterSep)(ASF_OptLayout)) */

ASF_ASFConditionList ASF_visitASFConditionList(ASF_ASFConditionList arg, ASF_ASFCondition (*acceptHead)(ASF_ASFCondition), ASF_OptLayout (*acceptWsAfterFirst)(ASF_OptLayout), char * (*acceptSep)(char *), ASF_OptLayout (*acceptWsAfterSep)(ASF_OptLayout))
{
  if (ASF_isASFConditionListSingle(arg)) {
    return ASF_makeASFConditionListSingle(
        acceptHead ? acceptHead(ASF_getASFConditionListHead(arg)) : ASF_getASFConditionListHead(arg));
  }
  if (ASF_isASFConditionListMany(arg)) {
    return ASF_makeASFConditionListMany(
        acceptHead ? acceptHead(ASF_getASFConditionListHead(arg)) : ASF_getASFConditionListHead(arg),
        acceptWsAfterFirst ? acceptWsAfterFirst(ASF_getASFConditionListWsAfterFirst(arg)) : ASF_getASFConditionListWsAfterFirst(arg),
        acceptSep ? acceptSep(ASF_getASFConditionListSep(arg)) : ASF_getASFConditionListSep(arg),
        acceptWsAfterSep ? acceptWsAfterSep(ASF_getASFConditionListWsAfterSep(arg)) : ASF_getASFConditionListWsAfterSep(arg),
        ASF_visitASFConditionList(ASF_getASFConditionListTail(arg), acceptHead, acceptWsAfterFirst, acceptSep, acceptWsAfterSep));
  }
  ATabort("not a ASFConditionList: %t\n", arg);
  return (ASF_ASFConditionList)NULL;
}

/*}}}  */
/*{{{  ASF_ASFEquations ASF_visitASFEquations(ASF_ASFEquations arg, ASF_OptLayout (*acceptWsAfterEquations)(ASF_OptLayout), ASF_ASFConditionalEquationList (*acceptList)(ASF_ASFConditionalEquationList)) */

ASF_ASFEquations ASF_visitASFEquations(ASF_ASFEquations arg, ASF_OptLayout (*acceptWsAfterEquations)(ASF_OptLayout), ASF_ASFConditionalEquationList (*acceptList)(ASF_ASFConditionalEquationList))
{
  if (ASF_isASFEquationsAbsent(arg)) {
    return ASF_makeASFEquationsAbsent();
  }
  if (ASF_isASFEquationsPresent(arg)) {
    return ASF_makeASFEquationsPresent(
        acceptWsAfterEquations ? acceptWsAfterEquations(ASF_getASFEquationsWsAfterEquations(arg)) : ASF_getASFEquationsWsAfterEquations(arg),
        acceptList ? acceptList(ASF_getASFEquationsList(arg)) : ASF_getASFEquationsList(arg));
  }
  ATabort("not a ASFEquations: %t\n", arg);
  return (ASF_ASFEquations)NULL;
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquationList ASF_visitASFConditionalEquationList(ASF_ASFConditionalEquationList arg, ASF_ASFConditionalEquation (*acceptHead)(ASF_ASFConditionalEquation), ASF_OptLayout (*acceptWsAfterFirst)(ASF_OptLayout)) */

ASF_ASFConditionalEquationList ASF_visitASFConditionalEquationList(ASF_ASFConditionalEquationList arg, ASF_ASFConditionalEquation (*acceptHead)(ASF_ASFConditionalEquation), ASF_OptLayout (*acceptWsAfterFirst)(ASF_OptLayout))
{
  if (ASF_isASFConditionalEquationListEmpty(arg)) {
    return ASF_makeASFConditionalEquationListEmpty();
  }
  if (ASF_isASFConditionalEquationListSingle(arg)) {
    return ASF_makeASFConditionalEquationListSingle(
        acceptHead ? acceptHead(ASF_getASFConditionalEquationListHead(arg)) : ASF_getASFConditionalEquationListHead(arg));
  }
  if (ASF_isASFConditionalEquationListMany(arg)) {
    return ASF_makeASFConditionalEquationListMany(
        acceptHead ? acceptHead(ASF_getASFConditionalEquationListHead(arg)) : ASF_getASFConditionalEquationListHead(arg),
        acceptWsAfterFirst ? acceptWsAfterFirst(ASF_getASFConditionalEquationListWsAfterFirst(arg)) : ASF_getASFConditionalEquationListWsAfterFirst(arg),
        ASF_visitASFConditionalEquationList(ASF_getASFConditionalEquationListTail(arg), acceptHead, acceptWsAfterFirst));
  }
  ATabort("not a ASFConditionalEquationList: %t\n", arg);
  return (ASF_ASFConditionalEquationList)NULL;
}

/*}}}  */
/*{{{  ASF_ASFConditionalEquation ASF_visitASFConditionalEquation(ASF_ASFConditionalEquation arg, ASF_ASFTag (*acceptASFTag)(ASF_ASFTag), ASF_OptLayout (*acceptWsAfterASFTag)(ASF_OptLayout), ASF_ASFEquation (*acceptASFEquation)(ASF_ASFEquation), ASF_ASFConditions (*acceptASFConditions)(ASF_ASFConditions), ASF_OptLayout (*acceptWsAfterASFConditions)(ASF_OptLayout), ASF_ASFImplies (*acceptASFImplies)(ASF_ASFImplies), ASF_OptLayout (*acceptWsAfterASFImplies)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterASFEquation)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterWhen)(ASF_OptLayout)) */

ASF_ASFConditionalEquation ASF_visitASFConditionalEquation(ASF_ASFConditionalEquation arg, ASF_ASFTag (*acceptASFTag)(ASF_ASFTag), ASF_OptLayout (*acceptWsAfterASFTag)(ASF_OptLayout), ASF_ASFEquation (*acceptASFEquation)(ASF_ASFEquation), ASF_ASFConditions (*acceptASFConditions)(ASF_ASFConditions), ASF_OptLayout (*acceptWsAfterASFConditions)(ASF_OptLayout), ASF_ASFImplies (*acceptASFImplies)(ASF_ASFImplies), ASF_OptLayout (*acceptWsAfterASFImplies)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterASFEquation)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterWhen)(ASF_OptLayout))
{
  if (ASF_isASFConditionalEquationSimple(arg)) {
    return ASF_makeASFConditionalEquationSimple(
        acceptASFTag ? acceptASFTag(ASF_getASFConditionalEquationASFTag(arg)) : ASF_getASFConditionalEquationASFTag(arg),
        acceptWsAfterASFTag ? acceptWsAfterASFTag(ASF_getASFConditionalEquationWsAfterASFTag(arg)) : ASF_getASFConditionalEquationWsAfterASFTag(arg),
        acceptASFEquation ? acceptASFEquation(ASF_getASFConditionalEquationASFEquation(arg)) : ASF_getASFConditionalEquationASFEquation(arg));
  }
  if (ASF_isASFConditionalEquationImplies(arg)) {
    return ASF_makeASFConditionalEquationImplies(
        acceptASFTag ? acceptASFTag(ASF_getASFConditionalEquationASFTag(arg)) : ASF_getASFConditionalEquationASFTag(arg),
        acceptWsAfterASFTag ? acceptWsAfterASFTag(ASF_getASFConditionalEquationWsAfterASFTag(arg)) : ASF_getASFConditionalEquationWsAfterASFTag(arg),
        acceptASFConditions ? acceptASFConditions(ASF_getASFConditionalEquationASFConditions(arg)) : ASF_getASFConditionalEquationASFConditions(arg),
        acceptWsAfterASFConditions ? acceptWsAfterASFConditions(ASF_getASFConditionalEquationWsAfterASFConditions(arg)) : ASF_getASFConditionalEquationWsAfterASFConditions(arg),
        acceptASFImplies ? acceptASFImplies(ASF_getASFConditionalEquationASFImplies(arg)) : ASF_getASFConditionalEquationASFImplies(arg),
        acceptWsAfterASFImplies ? acceptWsAfterASFImplies(ASF_getASFConditionalEquationWsAfterASFImplies(arg)) : ASF_getASFConditionalEquationWsAfterASFImplies(arg),
        acceptASFEquation ? acceptASFEquation(ASF_getASFConditionalEquationASFEquation(arg)) : ASF_getASFConditionalEquationASFEquation(arg));
  }
  if (ASF_isASFConditionalEquationWhen(arg)) {
    return ASF_makeASFConditionalEquationWhen(
        acceptASFTag ? acceptASFTag(ASF_getASFConditionalEquationASFTag(arg)) : ASF_getASFConditionalEquationASFTag(arg),
        acceptWsAfterASFTag ? acceptWsAfterASFTag(ASF_getASFConditionalEquationWsAfterASFTag(arg)) : ASF_getASFConditionalEquationWsAfterASFTag(arg),
        acceptASFEquation ? acceptASFEquation(ASF_getASFConditionalEquationASFEquation(arg)) : ASF_getASFConditionalEquationASFEquation(arg),
        acceptWsAfterASFEquation ? acceptWsAfterASFEquation(ASF_getASFConditionalEquationWsAfterASFEquation(arg)) : ASF_getASFConditionalEquationWsAfterASFEquation(arg),
        acceptWsAfterWhen ? acceptWsAfterWhen(ASF_getASFConditionalEquationWsAfterWhen(arg)) : ASF_getASFConditionalEquationWsAfterWhen(arg),
        acceptASFConditions ? acceptASFConditions(ASF_getASFConditionalEquationASFConditions(arg)) : ASF_getASFConditionalEquationASFConditions(arg));
  }
  ATabort("not a ASFConditionalEquation: %t\n", arg);
  return (ASF_ASFConditionalEquation)NULL;
}

/*}}}  */
/*{{{  ASF_ASFTag ASF_visitASFTag(ASF_ASFTag arg, ASF_OptLayout (*acceptWsAfterBracketOpen)(ASF_OptLayout), ASF_ASFTagId (*acceptASFTagId)(ASF_ASFTagId), ASF_OptLayout (*acceptWsAfterASFTagId)(ASF_OptLayout)) */

ASF_ASFTag ASF_visitASFTag(ASF_ASFTag arg, ASF_OptLayout (*acceptWsAfterBracketOpen)(ASF_OptLayout), ASF_ASFTagId (*acceptASFTagId)(ASF_ASFTagId), ASF_OptLayout (*acceptWsAfterASFTagId)(ASF_OptLayout))
{
  if (ASF_isASFTagEmpty(arg)) {
    return ASF_makeASFTagEmpty(
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(ASF_getASFTagWsAfterBracketOpen(arg)) : ASF_getASFTagWsAfterBracketOpen(arg));
  }
  if (ASF_isASFTagNotEmpty(arg)) {
    return ASF_makeASFTagNotEmpty(
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(ASF_getASFTagWsAfterBracketOpen(arg)) : ASF_getASFTagWsAfterBracketOpen(arg),
        acceptASFTagId ? acceptASFTagId(ASF_getASFTagASFTagId(arg)) : ASF_getASFTagASFTagId(arg),
        acceptWsAfterASFTagId ? acceptWsAfterASFTagId(ASF_getASFTagWsAfterASFTagId(arg)) : ASF_getASFTagWsAfterASFTagId(arg));
  }
  ATabort("not a ASFTag: %t\n", arg);
  return (ASF_ASFTag)NULL;
}

/*}}}  */
/*{{{  ASF_Tree ASF_visitTree(ASF_Tree arg, char * (*acceptFormalName)(char *), ASF_Symbol (*acceptSymbol)(ASF_Symbol), ASF_OptLayout (*acceptWsAfterName)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterParenOpen)(ASF_OptLayout), ASF_CHARList (*acceptList)(ASF_CHARList), ASF_OptLayout (*acceptWsAfterList)(ASF_OptLayout), ASF_Symbol (*acceptAmb)(ASF_Symbol), ASF_OptLayout (*acceptWsAfterAmb)(ASF_OptLayout), ASF_Symbol (*acceptListSymbol)(ASF_Symbol), ASF_TreeAmbs (*acceptAmbs)(ASF_TreeAmbs), ASF_OptLayout (*acceptWsAfterAmbs)(ASF_OptLayout)) */

ASF_Tree ASF_visitTree(ASF_Tree arg, char * (*acceptFormalName)(char *), ASF_Symbol (*acceptSymbol)(ASF_Symbol), ASF_OptLayout (*acceptWsAfterName)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterParenOpen)(ASF_OptLayout), ASF_CHARList (*acceptList)(ASF_CHARList), ASF_OptLayout (*acceptWsAfterList)(ASF_OptLayout), ASF_Symbol (*acceptAmb)(ASF_Symbol), ASF_OptLayout (*acceptWsAfterAmb)(ASF_OptLayout), ASF_Symbol (*acceptListSymbol)(ASF_Symbol), ASF_TreeAmbs (*acceptAmbs)(ASF_TreeAmbs), ASF_OptLayout (*acceptWsAfterAmbs)(ASF_OptLayout))
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
  if (ASF_isTreeAmbiguityConstructor(arg)) {
    return ASF_makeTreeAmbiguityConstructor(
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
/*{{{  ASF_CHARList ASF_visitCHARList(ASF_CHARList arg, ASF_CHAR (*acceptHead)(ASF_CHAR), ASF_OptLayout (*acceptWsAfterFirst)(ASF_OptLayout)) */

ASF_CHARList ASF_visitCHARList(ASF_CHARList arg, ASF_CHAR (*acceptHead)(ASF_CHAR), ASF_OptLayout (*acceptWsAfterFirst)(ASF_OptLayout))
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
/*{{{  ASF_ASFEquation ASF_visitASFEquation(ASF_ASFEquation arg, ASF_Symbol (*acceptLhsSymbol)(ASF_Symbol), ASF_Symbol (*acceptRhsSymbol)(ASF_Symbol), ASF_Tree (*acceptLhs)(ASF_Tree), ASF_OptLayout (*acceptWsAfterLhs)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterEquals)(ASF_OptLayout), ASF_Tree (*acceptRhs)(ASF_Tree)) */

ASF_ASFEquation ASF_visitASFEquation(ASF_ASFEquation arg, ASF_Symbol (*acceptLhsSymbol)(ASF_Symbol), ASF_Symbol (*acceptRhsSymbol)(ASF_Symbol), ASF_Tree (*acceptLhs)(ASF_Tree), ASF_OptLayout (*acceptWsAfterLhs)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterEquals)(ASF_OptLayout), ASF_Tree (*acceptRhs)(ASF_Tree))
{
  if (ASF_isASFEquationDefault(arg)) {
    return ASF_makeASFEquationDefault(
        acceptLhsSymbol ? acceptLhsSymbol(ASF_getASFEquationLhsSymbol(arg)) : ASF_getASFEquationLhsSymbol(arg),
        acceptRhsSymbol ? acceptRhsSymbol(ASF_getASFEquationRhsSymbol(arg)) : ASF_getASFEquationRhsSymbol(arg),
        acceptLhs ? acceptLhs(ASF_getASFEquationLhs(arg)) : ASF_getASFEquationLhs(arg),
        acceptWsAfterLhs ? acceptWsAfterLhs(ASF_getASFEquationWsAfterLhs(arg)) : ASF_getASFEquationWsAfterLhs(arg),
        acceptWsAfterEquals ? acceptWsAfterEquals(ASF_getASFEquationWsAfterEquals(arg)) : ASF_getASFEquationWsAfterEquals(arg),
        acceptRhs ? acceptRhs(ASF_getASFEquationRhs(arg)) : ASF_getASFEquationRhs(arg));
  }
  ATabort("not a ASFEquation: %t\n", arg);
  return (ASF_ASFEquation)NULL;
}

/*}}}  */
/*{{{  ASF_ASFCondition ASF_visitASFCondition(ASF_ASFCondition arg, ASF_Symbol (*acceptLhsSymbol)(ASF_Symbol), ASF_Symbol (*acceptRhsSymbol)(ASF_Symbol), ASF_Tree (*acceptLhs)(ASF_Tree), ASF_OptLayout (*acceptWsAfterLhs)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterEquals)(ASF_OptLayout), ASF_Tree (*acceptRhs)(ASF_Tree), ASF_OptLayout (*acceptWsAfterUnequal)(ASF_OptLayout)) */

ASF_ASFCondition ASF_visitASFCondition(ASF_ASFCondition arg, ASF_Symbol (*acceptLhsSymbol)(ASF_Symbol), ASF_Symbol (*acceptRhsSymbol)(ASF_Symbol), ASF_Tree (*acceptLhs)(ASF_Tree), ASF_OptLayout (*acceptWsAfterLhs)(ASF_OptLayout), ASF_OptLayout (*acceptWsAfterEquals)(ASF_OptLayout), ASF_Tree (*acceptRhs)(ASF_Tree), ASF_OptLayout (*acceptWsAfterUnequal)(ASF_OptLayout))
{
  if (ASF_isASFConditionPositive(arg)) {
    return ASF_makeASFConditionPositive(
        acceptLhsSymbol ? acceptLhsSymbol(ASF_getASFConditionLhsSymbol(arg)) : ASF_getASFConditionLhsSymbol(arg),
        acceptRhsSymbol ? acceptRhsSymbol(ASF_getASFConditionRhsSymbol(arg)) : ASF_getASFConditionRhsSymbol(arg),
        acceptLhs ? acceptLhs(ASF_getASFConditionLhs(arg)) : ASF_getASFConditionLhs(arg),
        acceptWsAfterLhs ? acceptWsAfterLhs(ASF_getASFConditionWsAfterLhs(arg)) : ASF_getASFConditionWsAfterLhs(arg),
        acceptWsAfterEquals ? acceptWsAfterEquals(ASF_getASFConditionWsAfterEquals(arg)) : ASF_getASFConditionWsAfterEquals(arg),
        acceptRhs ? acceptRhs(ASF_getASFConditionRhs(arg)) : ASF_getASFConditionRhs(arg));
  }
  if (ASF_isASFConditionNegative(arg)) {
    return ASF_makeASFConditionNegative(
        acceptLhsSymbol ? acceptLhsSymbol(ASF_getASFConditionLhsSymbol(arg)) : ASF_getASFConditionLhsSymbol(arg),
        acceptRhsSymbol ? acceptRhsSymbol(ASF_getASFConditionRhsSymbol(arg)) : ASF_getASFConditionRhsSymbol(arg),
        acceptLhs ? acceptLhs(ASF_getASFConditionLhs(arg)) : ASF_getASFConditionLhs(arg),
        acceptWsAfterLhs ? acceptWsAfterLhs(ASF_getASFConditionWsAfterLhs(arg)) : ASF_getASFConditionWsAfterLhs(arg),
        acceptWsAfterUnequal ? acceptWsAfterUnequal(ASF_getASFConditionWsAfterUnequal(arg)) : ASF_getASFConditionWsAfterUnequal(arg),
        acceptRhs ? acceptRhs(ASF_getASFConditionRhs(arg)) : ASF_getASFConditionRhs(arg));
  }
  ATabort("not a ASFCondition: %t\n", arg);
  return (ASF_ASFCondition)NULL;
}

/*}}}  */
/*{{{  ASF_TreeAmbs ASF_visitTreeAmbs(ASF_TreeAmbs arg, ASF_Tree (*acceptHead)(ASF_Tree), ASF_OptLayout (*acceptWsAfterFirst)(ASF_OptLayout), char * (*acceptSep)(char *), ASF_OptLayout (*acceptWsAfterSep)(ASF_OptLayout)) */

ASF_TreeAmbs ASF_visitTreeAmbs(ASF_TreeAmbs arg, ASF_Tree (*acceptHead)(ASF_Tree), ASF_OptLayout (*acceptWsAfterFirst)(ASF_OptLayout), char * (*acceptSep)(char *), ASF_OptLayout (*acceptWsAfterSep)(ASF_OptLayout))
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
/*{{{  ASF_CHAR ASF_visitCHAR(ASF_CHAR arg, ASF_CHARLIST (*acceptChars)(ASF_CHARLIST)) */

ASF_CHAR ASF_visitCHAR(ASF_CHAR arg, ASF_CHARLIST (*acceptChars)(ASF_CHARLIST))
{
  if (ASF_isCHARDefault(arg)) {
    return ASF_makeCHARDefault(
        acceptChars ? acceptChars(ASF_getCHARChars(arg)) : ASF_getCHARChars(arg));
  }
  ATabort("not a CHAR: %t\n", arg);
  return (ASF_CHAR)NULL;
}

/*}}}  */
/*{{{  ASF_OptLayout ASF_visitOptLayout(ASF_OptLayout arg, ASF_CHARLIST (*acceptChars)(ASF_CHARLIST)) */

ASF_OptLayout ASF_visitOptLayout(ASF_OptLayout arg, ASF_CHARLIST (*acceptChars)(ASF_CHARLIST))
{
  if (ASF_isOptLayoutAbsent(arg)) {
    return ASF_makeOptLayoutAbsent();
  }
  if (ASF_isOptLayoutPresent(arg)) {
    return ASF_makeOptLayoutPresent(
        acceptChars ? acceptChars(ASF_getOptLayoutChars(arg)) : ASF_getOptLayoutChars(arg));
  }
  ATabort("not a OptLayout: %t\n", arg);
  return (ASF_OptLayout)NULL;
}

/*}}}  */
/*{{{  ASF_Start ASF_visitStart(ASF_Start arg, ASF_OptLayout (*acceptWsBefore)(ASF_OptLayout), ASF_ASFEquations (*acceptTopASFEquations)(ASF_ASFEquations), ASF_OptLayout (*acceptWsAfter)(ASF_OptLayout), int (*acceptAmbCnt)(int)) */

ASF_Start ASF_visitStart(ASF_Start arg, ASF_OptLayout (*acceptWsBefore)(ASF_OptLayout), ASF_ASFEquations (*acceptTopASFEquations)(ASF_ASFEquations), ASF_OptLayout (*acceptWsAfter)(ASF_OptLayout), int (*acceptAmbCnt)(int))
{
  if (ASF_isStartASFEquations(arg)) {
    return ASF_makeStartASFEquations(
        acceptWsBefore ? acceptWsBefore(ASF_getStartWsBefore(arg)) : ASF_getStartWsBefore(arg),
        acceptTopASFEquations ? acceptTopASFEquations(ASF_getStartTopASFEquations(arg)) : ASF_getStartTopASFEquations(arg),
        acceptWsAfter ? acceptWsAfter(ASF_getStartWsAfter(arg)) : ASF_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(ASF_getStartAmbCnt(arg)) : ASF_getStartAmbCnt(arg));
  }
  ATabort("not a Start: %t\n", arg);
  return (ASF_Start)NULL;
}

/*}}}  */

/*}}}  */
