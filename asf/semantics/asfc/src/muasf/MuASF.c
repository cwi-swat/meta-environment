#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "MuASF.h"

/*{{{  typedefs */

typedef struct ATerm _MA_Int;
typedef struct ATerm _MA_IntCon;
typedef struct ATerm _MA_NatCon;
typedef struct ATerm _MA_Var;
typedef struct ATerm _MA_Term;
typedef struct ATerm _MA_TermArgs;
typedef struct ATerm _MA_TermList;
typedef struct ATerm _MA_TermElems;
typedef struct ATerm _MA_SigArg;
typedef struct ATerm _MA_FuncDef;
typedef struct ATerm _MA_SigArgElems;
typedef struct ATerm _MA_Annotations;
typedef struct ATerm _MA_TermTerms;
typedef struct ATerm _MA_SigArgList;
typedef struct ATerm _MA_FuncDefList;
typedef struct ATerm _MA_FuncDefElems;
typedef struct ATerm _MA_Rule;
typedef struct ATerm _MA_RuleList;
typedef struct ATerm _MA_RuleElems;
typedef struct ATerm _MA_CondList;
typedef struct ATerm _MA_CondElems;
typedef struct ATerm _MA_Cond;
typedef struct ATerm _MA_SignatureOpt;
typedef struct ATerm _MA_RulesOpt;
typedef struct ATerm _MA_Module;
typedef struct ATerm _MA_EscChar;
typedef struct ATerm _MA_QChar;
typedef struct ATerm _MA_FunId;
typedef struct ATerm _MA_VarId;
typedef struct ATerm _MA_ModId;
typedef struct ATerm _MA_PropId;

/*}}}  */

/*{{{  void MA_initMuASFApi(void) */

void MA_initMuASFApi(void)
{
  init_MuASF_dict();
}

/*}}}  */

/*{{{  term conversion functions */

/*{{{  MA_Int MA_IntFromTerm(ATerm t) */

MA_Int MA_IntFromTerm(ATerm t)
{
  return (MA_Int)t;
}

/*}}}  */
/*{{{  ATerm MA_IntToTerm(MA_Int arg) */

ATerm MA_IntToTerm(MA_Int arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_IntCon MA_IntConFromTerm(ATerm t) */

MA_IntCon MA_IntConFromTerm(ATerm t)
{
  return (MA_IntCon)t;
}

/*}}}  */
/*{{{  ATerm MA_IntConToTerm(MA_IntCon arg) */

ATerm MA_IntConToTerm(MA_IntCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_NatCon MA_NatConFromTerm(ATerm t) */

MA_NatCon MA_NatConFromTerm(ATerm t)
{
  return (MA_NatCon)t;
}

/*}}}  */
/*{{{  ATerm MA_NatConToTerm(MA_NatCon arg) */

ATerm MA_NatConToTerm(MA_NatCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_Var MA_VarFromTerm(ATerm t) */

MA_Var MA_VarFromTerm(ATerm t)
{
  return (MA_Var)t;
}

/*}}}  */
/*{{{  ATerm MA_VarToTerm(MA_Var arg) */

ATerm MA_VarToTerm(MA_Var arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_Term MA_TermFromTerm(ATerm t) */

MA_Term MA_TermFromTerm(ATerm t)
{
  return (MA_Term)t;
}

/*}}}  */
/*{{{  ATerm MA_TermToTerm(MA_Term arg) */

ATerm MA_TermToTerm(MA_Term arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_TermArgs MA_TermArgsFromTerm(ATerm t) */

MA_TermArgs MA_TermArgsFromTerm(ATerm t)
{
  return (MA_TermArgs)t;
}

/*}}}  */
/*{{{  ATerm MA_TermArgsToTerm(MA_TermArgs arg) */

ATerm MA_TermArgsToTerm(MA_TermArgs arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_TermList MA_TermListFromTerm(ATerm t) */

MA_TermList MA_TermListFromTerm(ATerm t)
{
  return (MA_TermList)t;
}

/*}}}  */
/*{{{  ATerm MA_TermListToTerm(MA_TermList arg) */

ATerm MA_TermListToTerm(MA_TermList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_TermElems MA_TermElemsFromTerm(ATerm t) */

MA_TermElems MA_TermElemsFromTerm(ATerm t)
{
  return (MA_TermElems)t;
}

/*}}}  */
/*{{{  ATerm MA_TermElemsToTerm(MA_TermElems arg) */

ATerm MA_TermElemsToTerm(MA_TermElems arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_SigArg MA_SigArgFromTerm(ATerm t) */

MA_SigArg MA_SigArgFromTerm(ATerm t)
{
  return (MA_SigArg)t;
}

/*}}}  */
/*{{{  ATerm MA_SigArgToTerm(MA_SigArg arg) */

ATerm MA_SigArgToTerm(MA_SigArg arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_FuncDef MA_FuncDefFromTerm(ATerm t) */

MA_FuncDef MA_FuncDefFromTerm(ATerm t)
{
  return (MA_FuncDef)t;
}

/*}}}  */
/*{{{  ATerm MA_FuncDefToTerm(MA_FuncDef arg) */

ATerm MA_FuncDefToTerm(MA_FuncDef arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_SigArgElems MA_SigArgElemsFromTerm(ATerm t) */

MA_SigArgElems MA_SigArgElemsFromTerm(ATerm t)
{
  return (MA_SigArgElems)t;
}

/*}}}  */
/*{{{  ATerm MA_SigArgElemsToTerm(MA_SigArgElems arg) */

ATerm MA_SigArgElemsToTerm(MA_SigArgElems arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_Annotations MA_AnnotationsFromTerm(ATerm t) */

MA_Annotations MA_AnnotationsFromTerm(ATerm t)
{
  return (MA_Annotations)t;
}

/*}}}  */
/*{{{  ATerm MA_AnnotationsToTerm(MA_Annotations arg) */

ATerm MA_AnnotationsToTerm(MA_Annotations arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_TermTerms MA_TermTermsFromTerm(ATerm t) */

MA_TermTerms MA_TermTermsFromTerm(ATerm t)
{
  return (MA_TermTerms)t;
}

/*}}}  */
/*{{{  ATerm MA_TermTermsToTerm(MA_TermTerms arg) */

ATerm MA_TermTermsToTerm(MA_TermTerms arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_SigArgList MA_SigArgListFromTerm(ATerm t) */

MA_SigArgList MA_SigArgListFromTerm(ATerm t)
{
  return (MA_SigArgList)t;
}

/*}}}  */
/*{{{  ATerm MA_SigArgListToTerm(MA_SigArgList arg) */

ATerm MA_SigArgListToTerm(MA_SigArgList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_FuncDefList MA_FuncDefListFromTerm(ATerm t) */

MA_FuncDefList MA_FuncDefListFromTerm(ATerm t)
{
  return (MA_FuncDefList)t;
}

/*}}}  */
/*{{{  ATerm MA_FuncDefListToTerm(MA_FuncDefList arg) */

ATerm MA_FuncDefListToTerm(MA_FuncDefList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_FuncDefElems MA_FuncDefElemsFromTerm(ATerm t) */

MA_FuncDefElems MA_FuncDefElemsFromTerm(ATerm t)
{
  return (MA_FuncDefElems)t;
}

/*}}}  */
/*{{{  ATerm MA_FuncDefElemsToTerm(MA_FuncDefElems arg) */

ATerm MA_FuncDefElemsToTerm(MA_FuncDefElems arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_Rule MA_RuleFromTerm(ATerm t) */

MA_Rule MA_RuleFromTerm(ATerm t)
{
  return (MA_Rule)t;
}

/*}}}  */
/*{{{  ATerm MA_RuleToTerm(MA_Rule arg) */

ATerm MA_RuleToTerm(MA_Rule arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_RuleList MA_RuleListFromTerm(ATerm t) */

MA_RuleList MA_RuleListFromTerm(ATerm t)
{
  return (MA_RuleList)t;
}

/*}}}  */
/*{{{  ATerm MA_RuleListToTerm(MA_RuleList arg) */

ATerm MA_RuleListToTerm(MA_RuleList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_RuleElems MA_RuleElemsFromTerm(ATerm t) */

MA_RuleElems MA_RuleElemsFromTerm(ATerm t)
{
  return (MA_RuleElems)t;
}

/*}}}  */
/*{{{  ATerm MA_RuleElemsToTerm(MA_RuleElems arg) */

ATerm MA_RuleElemsToTerm(MA_RuleElems arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_CondList MA_CondListFromTerm(ATerm t) */

MA_CondList MA_CondListFromTerm(ATerm t)
{
  return (MA_CondList)t;
}

/*}}}  */
/*{{{  ATerm MA_CondListToTerm(MA_CondList arg) */

ATerm MA_CondListToTerm(MA_CondList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_CondElems MA_CondElemsFromTerm(ATerm t) */

MA_CondElems MA_CondElemsFromTerm(ATerm t)
{
  return (MA_CondElems)t;
}

/*}}}  */
/*{{{  ATerm MA_CondElemsToTerm(MA_CondElems arg) */

ATerm MA_CondElemsToTerm(MA_CondElems arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_Cond MA_CondFromTerm(ATerm t) */

MA_Cond MA_CondFromTerm(ATerm t)
{
  return (MA_Cond)t;
}

/*}}}  */
/*{{{  ATerm MA_CondToTerm(MA_Cond arg) */

ATerm MA_CondToTerm(MA_Cond arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_SignatureOpt MA_SignatureOptFromTerm(ATerm t) */

MA_SignatureOpt MA_SignatureOptFromTerm(ATerm t)
{
  return (MA_SignatureOpt)t;
}

/*}}}  */
/*{{{  ATerm MA_SignatureOptToTerm(MA_SignatureOpt arg) */

ATerm MA_SignatureOptToTerm(MA_SignatureOpt arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_RulesOpt MA_RulesOptFromTerm(ATerm t) */

MA_RulesOpt MA_RulesOptFromTerm(ATerm t)
{
  return (MA_RulesOpt)t;
}

/*}}}  */
/*{{{  ATerm MA_RulesOptToTerm(MA_RulesOpt arg) */

ATerm MA_RulesOptToTerm(MA_RulesOpt arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_Module MA_ModuleFromTerm(ATerm t) */

MA_Module MA_ModuleFromTerm(ATerm t)
{
  return (MA_Module)t;
}

/*}}}  */
/*{{{  ATerm MA_ModuleToTerm(MA_Module arg) */

ATerm MA_ModuleToTerm(MA_Module arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_EscChar MA_EscCharFromTerm(ATerm t) */

MA_EscChar MA_EscCharFromTerm(ATerm t)
{
  return (MA_EscChar)t;
}

/*}}}  */
/*{{{  ATerm MA_EscCharToTerm(MA_EscChar arg) */

ATerm MA_EscCharToTerm(MA_EscChar arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_QChar MA_QCharFromTerm(ATerm t) */

MA_QChar MA_QCharFromTerm(ATerm t)
{
  return (MA_QChar)t;
}

/*}}}  */
/*{{{  ATerm MA_QCharToTerm(MA_QChar arg) */

ATerm MA_QCharToTerm(MA_QChar arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_FunId MA_FunIdFromTerm(ATerm t) */

MA_FunId MA_FunIdFromTerm(ATerm t)
{
  return (MA_FunId)t;
}

/*}}}  */
/*{{{  ATerm MA_FunIdToTerm(MA_FunId arg) */

ATerm MA_FunIdToTerm(MA_FunId arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_VarId MA_VarIdFromTerm(ATerm t) */

MA_VarId MA_VarIdFromTerm(ATerm t)
{
  return (MA_VarId)t;
}

/*}}}  */
/*{{{  ATerm MA_VarIdToTerm(MA_VarId arg) */

ATerm MA_VarIdToTerm(MA_VarId arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_ModId MA_ModIdFromTerm(ATerm t) */

MA_ModId MA_ModIdFromTerm(ATerm t)
{
  return (MA_ModId)t;
}

/*}}}  */
/*{{{  ATerm MA_ModIdToTerm(MA_ModId arg) */

ATerm MA_ModIdToTerm(MA_ModId arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_PropId MA_PropIdFromTerm(ATerm t) */

MA_PropId MA_PropIdFromTerm(ATerm t)
{
  return (MA_PropId)t;
}

/*}}}  */
/*{{{  ATerm MA_PropIdToTerm(MA_PropId arg) */

ATerm MA_PropIdToTerm(MA_PropId arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*}}}  */
/*{{{  constructors */

/*{{{  MA_Int MA_makeIntCon(MA_IntCon IntCon) */

MA_Int MA_makeIntCon(MA_IntCon IntCon)
{
  return (MA_Int)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun5))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun8))))), (ATerm)ATmakeList1((ATerm)IntCon));
}

/*}}}  */
/*{{{  MA_Int MA_makeIntPlus(MA_Int lhs, MA_Layout wsAfterLhs, MA_Layout wsAfterPlus, MA_Int rhs) */

MA_Int MA_makeIntPlus(MA_Int lhs, MA_Layout wsAfterLhs, MA_Layout wsAfterPlus, MA_Int rhs)
{
  return (MA_Int)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun5)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun12))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun5)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun5))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun8))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeAppl0(MA_afun14))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)rhs), (ATerm)wsAfterPlus), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun12))), (ATerm)wsAfterLhs), (ATerm)lhs));
}

/*}}}  */
/*{{{  MA_IntCon MA_makeIntConCon(MA_Layout wsAfterCon, MA_Layout wsAfterParenOpen, MA_Int intArg, MA_Layout wsAfterIntArg) */

MA_IntCon MA_makeIntConCon(MA_Layout wsAfterCon, MA_Layout wsAfterParenOpen, MA_Int intArg, MA_Layout wsAfterIntArg)
{
  return (MA_IntCon)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun15))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun5)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun16))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun17))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun8))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun15))), (ATerm)wsAfterIntArg), (ATerm)intArg), (ATerm)wsAfterParenOpen), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun16))), (ATerm)wsAfterCon), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun17))));
}

/*}}}  */
/*{{{  MA_IntCon MA_makeIntConNat(MA_NatCon NatCon) */

MA_IntCon MA_makeIntConNat(MA_NatCon NatCon)
{
  return (MA_IntCon)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun18)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun4))))), (ATerm)ATmakeList1((ATerm)NatCon));
}

/*}}}  */
/*{{{  MA_IntCon MA_makeIntConPos(MA_Layout wsAfterPlus, MA_NatCon natArg) */

MA_IntCon MA_makeIntConPos(MA_Layout wsAfterPlus, MA_NatCon natArg)
{
  return (MA_IntCon)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun18)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun12))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun4))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)natArg), (ATerm)wsAfterPlus), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun12))));
}

/*}}}  */
/*{{{  MA_IntCon MA_makeIntConNeg(MA_Layout wsAfter, MA_NatCon natArg) */

MA_IntCon MA_makeIntConNeg(MA_Layout wsAfter, MA_NatCon natArg)
{
  return (MA_IntCon)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun18)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun19))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun4))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)natArg), (ATerm)wsAfter), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun19))));
}

/*}}}  */
/*{{{  MA_NatCon MA_makeNatConAbs(MA_Layout wsAfterAbs, MA_Layout wsAfterParenOpen, MA_Int intArg, MA_Layout wsAfterIntArg) */

MA_NatCon MA_makeNatConAbs(MA_Layout wsAfterAbs, MA_Layout wsAfterParenOpen, MA_Int intArg, MA_Layout wsAfterIntArg)
{
  return (MA_NatCon)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun15))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun5)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun16))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun20))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun18))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun8))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun15))), (ATerm)wsAfterIntArg), (ATerm)intArg), (ATerm)wsAfterParenOpen), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun16))), (ATerm)wsAfterAbs), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun20))));
}

/*}}}  */
/*{{{  MA_Var MA_makeVarNormal(MA_VarId VarId) */

MA_Var MA_makeVarNormal(MA_VarId VarId)
{
  return (MA_Var)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun21)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun22))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATmakeList1((ATerm)VarId));
}

/*}}}  */
/*{{{  MA_Var MA_makeVarStar(MA_Layout wsAfterStar, MA_VarId VarId) */

MA_Var MA_makeVarStar(MA_Layout wsAfterStar, MA_VarId VarId)
{
  return (MA_Var)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun21)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun24))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun22))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)VarId), (ATerm)wsAfterStar), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun24))));
}

/*}}}  */
/*{{{  MA_Var MA_makeVarPlus(MA_Layout wsAfterPlus, MA_VarId VarId) */

MA_Var MA_makeVarPlus(MA_Layout wsAfterPlus, MA_VarId VarId)
{
  return (MA_Var)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun21)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun12))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun22))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)VarId), (ATerm)wsAfterPlus), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun12))));
}

/*}}}  */
/*{{{  MA_Term MA_makeTermVar(MA_Var Var) */

MA_Term MA_makeTermVar(MA_Var Var)
{
  return (MA_Term)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun22)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATmakeList1((ATerm)Var));
}

/*}}}  */
/*{{{  MA_Term MA_makeTermConstant(MA_FunId FunId) */

MA_Term MA_makeTermConstant(MA_FunId FunId)
{
  return (MA_Term)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun26)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATmakeList1((ATerm)FunId));
}

/*}}}  */
/*{{{  MA_Term MA_makeTermInt(MA_Int Int) */

MA_Term MA_makeTermInt(MA_Int Int)
{
  return (MA_Term)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun5)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATmakeList1((ATerm)Int));
}

/*}}}  */
/*{{{  MA_Term MA_makeTermFunc(MA_FunId FunId, MA_Layout wsAfterFunId, MA_Layout wsAfterParenOpen, MA_TermArgs args, MA_Layout wsAfterArgs) */

MA_Term MA_makeTermFunc(MA_FunId FunId, MA_Layout wsAfterFunId, MA_Layout wsAfterParenOpen, MA_TermArgs args, MA_Layout wsAfterArgs)
{
  return (MA_Term)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun15))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun27, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun16))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun26)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun15))), (ATerm)wsAfterArgs), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl1(MA_afun29, (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun27, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))))), (ATerm)args)), (ATerm)wsAfterParenOpen), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun16))), (ATerm)wsAfterFunId), (ATerm)FunId));
}

/*}}}  */
/*{{{  MA_TermArgs MA_makeTermArgsSingle(MA_Term head) */

MA_TermArgs MA_makeTermArgsSingle(MA_Term head)
{
  return (MA_TermArgs)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  MA_TermArgs MA_makeTermArgsMany(MA_Term head, MA_Layout wsAfterFirst, char * sep, MA_Layout wsAfterSep, MA_TermArgs tail) */

MA_TermArgs MA_makeTermArgsMany(MA_Term head, MA_Layout wsAfterFirst, char * sep, MA_Layout wsAfterSep, MA_TermArgs tail)
{
  return (MA_TermArgs)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm)wsAfterSep), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)))), (ATerm)wsAfterFirst), (ATerm)head);
}

/*}}}  */
/*{{{  MA_TermList MA_makeTermListDefault(MA_TermElems elems) */

MA_TermList MA_makeTermListDefault(MA_TermElems elems)
{
  return (MA_TermList)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun30, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun31))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl1(MA_afun29, (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun30, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))))), (ATerm)elems)));
}

/*}}}  */
/*{{{  MA_TermElems MA_makeTermElemsEmpty() */

MA_TermElems MA_makeTermElemsEmpty()
{
  return (MA_TermElems)(ATerm)ATempty;
}

/*}}}  */
/*{{{  MA_TermElems MA_makeTermElemsSingle(MA_Term head) */

MA_TermElems MA_makeTermElemsSingle(MA_Term head)
{
  return (MA_TermElems)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  MA_TermElems MA_makeTermElemsMany(MA_Term head, MA_Layout wsAfterFirst, char * sep, MA_Layout wsAfterSep, MA_TermElems tail) */

MA_TermElems MA_makeTermElemsMany(MA_Term head, MA_Layout wsAfterFirst, char * sep, MA_Layout wsAfterSep, MA_TermElems tail)
{
  return (MA_TermElems)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm)wsAfterSep), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)))), (ATerm)wsAfterFirst), (ATerm)head);
}

/*}}}  */
/*{{{  MA_SigArg MA_makeSigArgNormal() */

MA_SigArg MA_makeSigArgNormal()
{
  return (MA_SigArg)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun32))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun33))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun32))));
}

/*}}}  */
/*{{{  MA_SigArg MA_makeSigArgStar(MA_Layout wsAfterUnderscore) */

MA_SigArg MA_makeSigArgStar(MA_Layout wsAfterUnderscore)
{
  return (MA_SigArg)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun24))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun32))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun33))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun24))), (ATerm)wsAfterUnderscore), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun32))));
}

/*}}}  */
/*{{{  MA_SigArg MA_makeSigArgPlus(MA_Layout wsAfterUnderscore) */

MA_SigArg MA_makeSigArgPlus(MA_Layout wsAfterUnderscore)
{
  return (MA_SigArg)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun12))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun32))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun33))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun12))), (ATerm)wsAfterUnderscore), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun32))));
}

/*}}}  */
/*{{{  MA_FuncDef MA_makeFuncDefConstantNoAnnos(MA_FunId FunId) */

MA_FuncDef MA_makeFuncDefConstantNoAnnos(MA_FunId FunId)
{
  return (MA_FuncDef)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun26)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun34))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATmakeList1((ATerm)FunId));
}

/*}}}  */
/*{{{  MA_FuncDef MA_makeFuncDefConstantWithAnnos(MA_FunId FunId, MA_Layout wsAfterFunId, MA_Annotations annos) */

MA_FuncDef MA_makeFuncDefConstantWithAnnos(MA_FunId FunId, MA_Layout wsAfterFunId, MA_Annotations annos)
{
  return (MA_FuncDef)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun35)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun26)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun34))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)annos), (ATerm)wsAfterFunId), (ATerm)FunId));
}

/*}}}  */
/*{{{  MA_FuncDef MA_makeFuncDefFuncNoAnnos(MA_FunId FunId, MA_Layout wsAfterFunId, MA_Layout wsAfterParenOpen, MA_SigArgElems elems, MA_Layout wsAfterElems) */

MA_FuncDef MA_makeFuncDefFuncNoAnnos(MA_FunId FunId, MA_Layout wsAfterFunId, MA_Layout wsAfterParenOpen, MA_SigArgElems elems, MA_Layout wsAfterElems)
{
  return (MA_FuncDef)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun15))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun27, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun33)), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun16))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun26)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun34))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun15))), (ATerm)wsAfterElems), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl1(MA_afun29, (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun27, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun33)), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))))), (ATerm)elems)), (ATerm)wsAfterParenOpen), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun16))), (ATerm)wsAfterFunId), (ATerm)FunId));
}

/*}}}  */
/*{{{  MA_FuncDef MA_makeFuncDefFuncWithAnnos(MA_FunId FunId, MA_Layout wsAfterFunId, MA_Layout wsAfterParenOpen, MA_SigArgElems elems, MA_Layout wsAfterElems, MA_Layout wsAfterParenClose, MA_Annotations annos) */

MA_FuncDef MA_makeFuncDefFuncWithAnnos(MA_FunId FunId, MA_Layout wsAfterFunId, MA_Layout wsAfterParenOpen, MA_SigArgElems elems, MA_Layout wsAfterElems, MA_Layout wsAfterParenClose, MA_Annotations annos)
{
  return (MA_FuncDef)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun35)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun15))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun27, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun33)), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun16))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun26)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun34))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)annos), (ATerm)wsAfterParenClose), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun15))), (ATerm)wsAfterElems), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl1(MA_afun29, (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun27, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun33)), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))))), (ATerm)elems)), (ATerm)wsAfterParenOpen), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun16))), (ATerm)wsAfterFunId), (ATerm)FunId));
}

/*}}}  */
/*{{{  MA_SigArgElems MA_makeSigArgElemsSingle(MA_SigArg head) */

MA_SigArgElems MA_makeSigArgElemsSingle(MA_SigArg head)
{
  return (MA_SigArgElems)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  MA_SigArgElems MA_makeSigArgElemsMany(MA_SigArg head, MA_Layout wsAfterFirst, char * sep, MA_Layout wsAfterSep, MA_SigArgElems tail) */

MA_SigArgElems MA_makeSigArgElemsMany(MA_SigArg head, MA_Layout wsAfterFirst, char * sep, MA_Layout wsAfterSep, MA_SigArgElems tail)
{
  return (MA_SigArgElems)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm)wsAfterSep), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)))), (ATerm)wsAfterFirst), (ATerm)head);
}

/*}}}  */
/*{{{  MA_Annotations MA_makeAnnotationsDefault(MA_Layout wsAfterBraceOpen, MA_TermTerms terms, MA_Layout wsAfterTerms) */

MA_Annotations MA_makeAnnotationsDefault(MA_Layout wsAfterBraceOpen, MA_TermTerms terms, MA_Layout wsAfterTerms)
{
  return (MA_Annotations)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun36))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun27, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun37))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun35))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun36))), (ATerm)wsAfterTerms), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl1(MA_afun29, (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun27, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))))), (ATerm)terms)), (ATerm)wsAfterBraceOpen), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun37))));
}

/*}}}  */
/*{{{  MA_TermTerms MA_makeTermTermsSingle(MA_Term head) */

MA_TermTerms MA_makeTermTermsSingle(MA_Term head)
{
  return (MA_TermTerms)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  MA_TermTerms MA_makeTermTermsMany(MA_Term head, MA_Layout wsAfterFirst, char * sep, MA_Layout wsAfterSep, MA_TermTerms tail) */

MA_TermTerms MA_makeTermTermsMany(MA_Term head, MA_Layout wsAfterFirst, char * sep, MA_Layout wsAfterSep, MA_TermTerms tail)
{
  return (MA_TermTerms)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm)wsAfterSep), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)))), (ATerm)wsAfterFirst), (ATerm)head);
}

/*}}}  */
/*{{{  MA_SigArgList MA_makeSigArgListDefault(MA_SigArgElems elems) */

MA_SigArgList MA_makeSigArgListDefault(MA_SigArgElems elems)
{
  return (MA_SigArgList)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun27, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun33)), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun38))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl1(MA_afun29, (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun27, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun33)), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))))), (ATerm)elems)));
}

/*}}}  */
/*{{{  MA_FuncDefList MA_makeFuncDefListDefault(MA_FuncDefElems elems) */

MA_FuncDefList MA_makeFuncDefListDefault(MA_FuncDefElems elems)
{
  return (MA_FuncDefList)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun30, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun34)), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun39))))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun40))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl1(MA_afun29, (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun30, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun34)), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun39))))), (ATerm)elems)));
}

/*}}}  */
/*{{{  MA_FuncDefElems MA_makeFuncDefElemsEmpty() */

MA_FuncDefElems MA_makeFuncDefElemsEmpty()
{
  return (MA_FuncDefElems)(ATerm)ATempty;
}

/*}}}  */
/*{{{  MA_FuncDefElems MA_makeFuncDefElemsSingle(MA_FuncDef head) */

MA_FuncDefElems MA_makeFuncDefElemsSingle(MA_FuncDef head)
{
  return (MA_FuncDefElems)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  MA_FuncDefElems MA_makeFuncDefElemsMany(MA_FuncDef head, MA_Layout wsAfterFirst, char * sep, MA_Layout wsAfterSep, MA_FuncDefElems tail) */

MA_FuncDefElems MA_makeFuncDefElemsMany(MA_FuncDef head, MA_Layout wsAfterFirst, char * sep, MA_Layout wsAfterSep, MA_FuncDefElems tail)
{
  return (MA_FuncDefElems)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm)wsAfterSep), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)))), (ATerm)wsAfterFirst), (ATerm)head);
}

/*}}}  */
/*{{{  MA_Rule MA_makeRuleNoConds(MA_Term lhs, MA_Layout wsAfterLhs, MA_Layout wsAfterEquals, MA_Term rhs) */

MA_Rule MA_makeRuleNoConds(MA_Term lhs, MA_Layout wsAfterLhs, MA_Layout wsAfterEquals, MA_Term rhs)
{
  return (MA_Rule)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun41))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun42))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)rhs), (ATerm)wsAfterEquals), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun41))), (ATerm)wsAfterLhs), (ATerm)lhs));
}

/*}}}  */
/*{{{  MA_Rule MA_makeRuleDefaultNoConds(MA_Layout wsAfterDefaultColon, MA_Term lhs, MA_Layout wsAfterLhs, MA_Layout wsAfterEquals, MA_Term rhs) */

MA_Rule MA_makeRuleDefaultNoConds(MA_Layout wsAfterDefaultColon, MA_Term lhs, MA_Layout wsAfterLhs, MA_Layout wsAfterEquals, MA_Term rhs)
{
  return (MA_Rule)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun41))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun43))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun42))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)rhs), (ATerm)wsAfterEquals), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun41))), (ATerm)wsAfterLhs), (ATerm)lhs), (ATerm)wsAfterDefaultColon), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun43))));
}

/*}}}  */
/*{{{  MA_Rule MA_makeRuleDefaultWithConds(MA_Layout wsAfterDefaultColon, MA_CondList conds, MA_Layout wsAfterConds, MA_Layout wsAfterImplies, MA_Term lhs, MA_Layout wsAfterLhs, MA_Layout wsAfterEquals, MA_Term rhs) */

MA_Rule MA_makeRuleDefaultWithConds(MA_Layout wsAfterDefaultColon, MA_CondList conds, MA_Layout wsAfterConds, MA_Layout wsAfterImplies, MA_Term lhs, MA_Layout wsAfterLhs, MA_Layout wsAfterEquals, MA_Term rhs)
{
  return (MA_Rule)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun41))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun44))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun45)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun43))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun42))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)rhs), (ATerm)wsAfterEquals), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun41))), (ATerm)wsAfterLhs), (ATerm)lhs), (ATerm)wsAfterImplies), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun44))), (ATerm)wsAfterConds), (ATerm)conds), (ATerm)wsAfterDefaultColon), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun43))));
}

/*}}}  */
/*{{{  MA_Rule MA_makeRuleWithConds(MA_CondList conds, MA_Layout wsAfterConds, MA_Layout wsAfterImplies, MA_Term lhs, MA_Layout wsAfterLhs, MA_Layout wsAfterEquals, MA_Term rhs) */

MA_Rule MA_makeRuleWithConds(MA_CondList conds, MA_Layout wsAfterConds, MA_Layout wsAfterImplies, MA_Term lhs, MA_Layout wsAfterLhs, MA_Layout wsAfterEquals, MA_Term rhs)
{
  return (MA_Rule)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun41))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun44))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun45)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun42))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)rhs), (ATerm)wsAfterEquals), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun41))), (ATerm)wsAfterLhs), (ATerm)lhs), (ATerm)wsAfterImplies), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun44))), (ATerm)wsAfterConds), (ATerm)conds));
}

/*}}}  */
/*{{{  MA_RuleList MA_makeRuleListDefault(MA_RuleElems elems) */

MA_RuleList MA_makeRuleListDefault(MA_RuleElems elems)
{
  return (MA_RuleList)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun30, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun42)), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun39))))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun46))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl1(MA_afun29, (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun30, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun42)), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun39))))), (ATerm)elems)));
}

/*}}}  */
/*{{{  MA_RuleElems MA_makeRuleElemsEmpty() */

MA_RuleElems MA_makeRuleElemsEmpty()
{
  return (MA_RuleElems)(ATerm)ATempty;
}

/*}}}  */
/*{{{  MA_RuleElems MA_makeRuleElemsSingle(MA_Rule head) */

MA_RuleElems MA_makeRuleElemsSingle(MA_Rule head)
{
  return (MA_RuleElems)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  MA_RuleElems MA_makeRuleElemsMany(MA_Rule head, MA_Layout wsAfterFirst, char * sep, MA_Layout wsAfterSep, MA_RuleElems tail) */

MA_RuleElems MA_makeRuleElemsMany(MA_Rule head, MA_Layout wsAfterFirst, char * sep, MA_Layout wsAfterSep, MA_RuleElems tail)
{
  return (MA_RuleElems)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm)wsAfterSep), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)))), (ATerm)wsAfterFirst), (ATerm)head);
}

/*}}}  */
/*{{{  MA_CondList MA_makeCondListDefault(MA_CondElems elems) */

MA_CondList MA_makeCondListDefault(MA_CondElems elems)
{
  return (MA_CondList)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun30, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun47)), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun48))))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun45))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl1(MA_afun29, (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun30, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun47)), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun48))))), (ATerm)elems)));
}

/*}}}  */
/*{{{  MA_CondElems MA_makeCondElemsEmpty() */

MA_CondElems MA_makeCondElemsEmpty()
{
  return (MA_CondElems)(ATerm)ATempty;
}

/*}}}  */
/*{{{  MA_CondElems MA_makeCondElemsSingle(MA_Cond head) */

MA_CondElems MA_makeCondElemsSingle(MA_Cond head)
{
  return (MA_CondElems)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  MA_CondElems MA_makeCondElemsMany(MA_Cond head, MA_Layout wsAfterFirst, char * sep, MA_Layout wsAfterSep, MA_CondElems tail) */

MA_CondElems MA_makeCondElemsMany(MA_Cond head, MA_Layout wsAfterFirst, char * sep, MA_Layout wsAfterSep, MA_CondElems tail)
{
  return (MA_CondElems)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm)wsAfterSep), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)))), (ATerm)wsAfterFirst), (ATerm)head);
}

/*}}}  */
/*{{{  MA_Cond MA_makeCondAssign(MA_Term lhs, MA_Layout wsAfterLhs, MA_Layout wsAfterAssign, MA_Term rhs) */

MA_Cond MA_makeCondAssign(MA_Term lhs, MA_Layout wsAfterLhs, MA_Layout wsAfterAssign, MA_Term rhs)
{
  return (MA_Cond)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun49))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun47))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)rhs), (ATerm)wsAfterAssign), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun49))), (ATerm)wsAfterLhs), (ATerm)lhs));
}

/*}}}  */
/*{{{  MA_Cond MA_makeCondEqual(MA_Term lhs, MA_Layout wsAfterLhs, MA_Layout wsAfterEqual, MA_Term rhs) */

MA_Cond MA_makeCondEqual(MA_Term lhs, MA_Layout wsAfterLhs, MA_Layout wsAfterEqual, MA_Term rhs)
{
  return (MA_Cond)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun50))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun47))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)rhs), (ATerm)wsAfterEqual), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun50))), (ATerm)wsAfterLhs), (ATerm)lhs));
}

/*}}}  */
/*{{{  MA_Cond MA_makeCondUnequal(MA_Term lhs, MA_Layout wsAfterLhs, MA_Layout wsAfterUnequal, MA_Term rhs) */

MA_Cond MA_makeCondUnequal(MA_Term lhs, MA_Layout wsAfterLhs, MA_Layout wsAfterUnequal, MA_Term rhs)
{
  return (MA_Cond)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun51))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun47))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)rhs), (ATerm)wsAfterUnequal), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun51))), (ATerm)wsAfterLhs), (ATerm)lhs));
}

/*}}}  */
/*{{{  MA_SignatureOpt MA_makeSignatureOptAbsent() */

MA_SignatureOpt MA_makeSignatureOptAbsent()
{
  return (MA_SignatureOpt)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATempty, (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun52))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATempty);
}

/*}}}  */
/*{{{  MA_SignatureOpt MA_makeSignatureOptPresent(MA_Layout wsAfterSignature, MA_FuncDefList funcdefs) */

MA_SignatureOpt MA_makeSignatureOptPresent(MA_Layout wsAfterSignature, MA_FuncDefList funcdefs)
{
  return (MA_SignatureOpt)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun40)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun53))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun52))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)funcdefs), (ATerm)wsAfterSignature), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun53))));
}

/*}}}  */
/*{{{  MA_RulesOpt MA_makeRulesOptAbsent() */

MA_RulesOpt MA_makeRulesOptAbsent()
{
  return (MA_RulesOpt)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATempty, (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun54))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATempty);
}

/*}}}  */
/*{{{  MA_RulesOpt MA_makeRulesOptPresent(MA_Layout wsAfterRules, MA_RuleList rules) */

MA_RulesOpt MA_makeRulesOptPresent(MA_Layout wsAfterRules, MA_RuleList rules)
{
  return (MA_RulesOpt)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun46)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun55))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun54))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)rules), (ATerm)wsAfterRules), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun55))));
}

/*}}}  */
/*{{{  MA_Module MA_makeModuleModule(MA_Layout wsAfterModule, MA_ModId id, MA_Layout wsAfterId, MA_SignatureOpt signature, MA_Layout wsAfterSignature, MA_RulesOpt rules) */

MA_Module MA_makeModuleModule(MA_Layout wsAfterModule, MA_ModId id, MA_Layout wsAfterId, MA_SignatureOpt signature, MA_Layout wsAfterSignature, MA_RulesOpt rules)
{
  return (MA_Module)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun54)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun52)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun56)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun57))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun58))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)rules), (ATerm)wsAfterSignature), (ATerm)signature), (ATerm)wsAfterId), (ATerm)id), (ATerm)wsAfterModule), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun57))));
}

/*}}}  */
/*{{{  MA_EscChar MA_makeEscCharLexToCf(MA_Lexical lex) */

MA_EscChar MA_makeEscCharLexToCf(MA_Lexical lex)
{
  return (MA_EscChar)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun59, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun60)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun60))), (ATerm)ATmakeAppl0(MA_afun61)), (ATerm)ATmakeList1((ATerm)lex));
}

/*}}}  */
/*{{{  MA_QChar MA_makeQCharLexToCf(MA_Lexical lex) */

MA_QChar MA_makeQCharLexToCf(MA_Lexical lex)
{
  return (MA_QChar)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun59, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun62)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun62))), (ATerm)ATmakeAppl0(MA_afun61)), (ATerm)ATmakeList1((ATerm)lex));
}

/*}}}  */
/*{{{  MA_FunId MA_makeFunIdLexToCf(MA_Lexical lex) */

MA_FunId MA_makeFunIdLexToCf(MA_Lexical lex)
{
  return (MA_FunId)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun59, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun26)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun26))), (ATerm)ATmakeAppl0(MA_afun61)), (ATerm)ATmakeList1((ATerm)lex));
}

/*}}}  */
/*{{{  MA_VarId MA_makeVarIdLexToCf(MA_Lexical lex) */

MA_VarId MA_makeVarIdLexToCf(MA_Lexical lex)
{
  return (MA_VarId)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun59, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun21)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun21))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeAppl0(MA_afun63))))), (ATerm)ATmakeList1((ATerm)lex));
}

/*}}}  */
/*{{{  MA_ModId MA_makeModIdLexToCf(MA_Lexical lex) */

MA_ModId MA_makeModIdLexToCf(MA_Lexical lex)
{
  return (MA_ModId)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun59, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun56)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun56))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeAppl0(MA_afun63))))), (ATerm)ATmakeList1((ATerm)lex));
}

/*}}}  */
/*{{{  MA_PropId MA_makePropIdLexToCf(MA_Lexical lex) */

MA_PropId MA_makePropIdLexToCf(MA_Lexical lex)
{
  return (MA_PropId)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun59, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun64)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun64))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeAppl0(MA_afun63))))), (ATerm)ATmakeList1((ATerm)lex));
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool MA_isEqualInt(MA_Int arg0, MA_Int arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualIntCon(MA_IntCon arg0, MA_IntCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualNatCon(MA_NatCon arg0, MA_NatCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualVar(MA_Var arg0, MA_Var arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualTerm(MA_Term arg0, MA_Term arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualTermArgs(MA_TermArgs arg0, MA_TermArgs arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualTermList(MA_TermList arg0, MA_TermList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualTermElems(MA_TermElems arg0, MA_TermElems arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualSigArg(MA_SigArg arg0, MA_SigArg arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualFuncDef(MA_FuncDef arg0, MA_FuncDef arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualSigArgElems(MA_SigArgElems arg0, MA_SigArgElems arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualAnnotations(MA_Annotations arg0, MA_Annotations arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualTermTerms(MA_TermTerms arg0, MA_TermTerms arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualSigArgList(MA_SigArgList arg0, MA_SigArgList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualFuncDefList(MA_FuncDefList arg0, MA_FuncDefList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualFuncDefElems(MA_FuncDefElems arg0, MA_FuncDefElems arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualRule(MA_Rule arg0, MA_Rule arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualRuleList(MA_RuleList arg0, MA_RuleList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualRuleElems(MA_RuleElems arg0, MA_RuleElems arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualCondList(MA_CondList arg0, MA_CondList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualCondElems(MA_CondElems arg0, MA_CondElems arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualCond(MA_Cond arg0, MA_Cond arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualSignatureOpt(MA_SignatureOpt arg0, MA_SignatureOpt arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualRulesOpt(MA_RulesOpt arg0, MA_RulesOpt arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualModule(MA_Module arg0, MA_Module arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualEscChar(MA_EscChar arg0, MA_EscChar arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualQChar(MA_QChar arg0, MA_QChar arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualFunId(MA_FunId arg0, MA_FunId arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualVarId(MA_VarId arg0, MA_VarId arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualModId(MA_ModId arg0, MA_ModId arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualPropId(MA_PropId arg0, MA_PropId arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  MA_Int accessors */

/*{{{  ATbool MA_isValidInt(MA_Int arg) */

ATbool MA_isValidInt(MA_Int arg)
{
  if (MA_isIntCon(arg)) {
    return ATtrue;
  }
  else if (MA_isIntPlus(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isIntCon(MA_Int arg) */

inline ATbool MA_isIntCon(MA_Int arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternIntCon, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isIntPlus(MA_Int arg) */

inline ATbool MA_isIntPlus(MA_Int arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternIntPlus, NULL, NULL, NULL, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MA_hasIntIntCon(MA_Int arg) */

ATbool MA_hasIntIntCon(MA_Int arg)
{
  if (MA_isIntCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_IntCon MA_getIntIntCon(MA_Int arg) */

MA_IntCon MA_getIntIntCon(MA_Int arg)
{
  
    return (MA_IntCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  MA_Int MA_setIntIntCon(MA_Int arg, MA_IntCon IntCon) */

MA_Int MA_setIntIntCon(MA_Int arg, MA_IntCon IntCon)
{
  if (MA_isIntCon(arg)) {
    return (MA_Int)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)IntCon, 0), 1);
  }

  ATabort("Int has no IntCon: %t\n", arg);
  return (MA_Int)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasIntLhs(MA_Int arg) */

ATbool MA_hasIntLhs(MA_Int arg)
{
  if (MA_isIntPlus(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Int MA_getIntLhs(MA_Int arg) */

MA_Int MA_getIntLhs(MA_Int arg)
{
  
    return (MA_Int)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  MA_Int MA_setIntLhs(MA_Int arg, MA_Int lhs) */

MA_Int MA_setIntLhs(MA_Int arg, MA_Int lhs)
{
  if (MA_isIntPlus(arg)) {
    return (MA_Int)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)lhs, 0), 1);
  }

  ATabort("Int has no Lhs: %t\n", arg);
  return (MA_Int)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasIntWsAfterLhs(MA_Int arg) */

ATbool MA_hasIntWsAfterLhs(MA_Int arg)
{
  if (MA_isIntPlus(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getIntWsAfterLhs(MA_Int arg) */

MA_Layout MA_getIntWsAfterLhs(MA_Int arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_Int MA_setIntWsAfterLhs(MA_Int arg, MA_Layout wsAfterLhs) */

MA_Int MA_setIntWsAfterLhs(MA_Int arg, MA_Layout wsAfterLhs)
{
  if (MA_isIntPlus(arg)) {
    return (MA_Int)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLhs, 1), 1);
  }

  ATabort("Int has no WsAfterLhs: %t\n", arg);
  return (MA_Int)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasIntWsAfterPlus(MA_Int arg) */

ATbool MA_hasIntWsAfterPlus(MA_Int arg)
{
  if (MA_isIntPlus(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getIntWsAfterPlus(MA_Int arg) */

MA_Layout MA_getIntWsAfterPlus(MA_Int arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  MA_Int MA_setIntWsAfterPlus(MA_Int arg, MA_Layout wsAfterPlus) */

MA_Int MA_setIntWsAfterPlus(MA_Int arg, MA_Layout wsAfterPlus)
{
  if (MA_isIntPlus(arg)) {
    return (MA_Int)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterPlus, 3), 1);
  }

  ATabort("Int has no WsAfterPlus: %t\n", arg);
  return (MA_Int)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasIntRhs(MA_Int arg) */

ATbool MA_hasIntRhs(MA_Int arg)
{
  if (MA_isIntPlus(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Int MA_getIntRhs(MA_Int arg) */

MA_Int MA_getIntRhs(MA_Int arg)
{
  
    return (MA_Int)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  MA_Int MA_setIntRhs(MA_Int arg, MA_Int rhs) */

MA_Int MA_setIntRhs(MA_Int arg, MA_Int rhs)
{
  if (MA_isIntPlus(arg)) {
    return (MA_Int)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)rhs, 4), 1);
  }

  ATabort("Int has no Rhs: %t\n", arg);
  return (MA_Int)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_IntCon accessors */

/*{{{  ATbool MA_isValidIntCon(MA_IntCon arg) */

ATbool MA_isValidIntCon(MA_IntCon arg)
{
  if (MA_isIntConCon(arg)) {
    return ATtrue;
  }
  else if (MA_isIntConNat(arg)) {
    return ATtrue;
  }
  else if (MA_isIntConPos(arg)) {
    return ATtrue;
  }
  else if (MA_isIntConNeg(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isIntConCon(MA_IntCon arg) */

inline ATbool MA_isIntConCon(MA_IntCon arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternIntConCon, NULL, NULL, NULL, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isIntConNat(MA_IntCon arg) */

inline ATbool MA_isIntConNat(MA_IntCon arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternIntConNat, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isIntConPos(MA_IntCon arg) */

inline ATbool MA_isIntConPos(MA_IntCon arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternIntConPos, NULL, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isIntConNeg(MA_IntCon arg) */

inline ATbool MA_isIntConNeg(MA_IntCon arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternIntConNeg, NULL, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MA_hasIntConWsAfterCon(MA_IntCon arg) */

ATbool MA_hasIntConWsAfterCon(MA_IntCon arg)
{
  if (MA_isIntConCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getIntConWsAfterCon(MA_IntCon arg) */

MA_Layout MA_getIntConWsAfterCon(MA_IntCon arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_IntCon MA_setIntConWsAfterCon(MA_IntCon arg, MA_Layout wsAfterCon) */

MA_IntCon MA_setIntConWsAfterCon(MA_IntCon arg, MA_Layout wsAfterCon)
{
  if (MA_isIntConCon(arg)) {
    return (MA_IntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterCon, 1), 1);
  }

  ATabort("IntCon has no WsAfterCon: %t\n", arg);
  return (MA_IntCon)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasIntConWsAfterParenOpen(MA_IntCon arg) */

ATbool MA_hasIntConWsAfterParenOpen(MA_IntCon arg)
{
  if (MA_isIntConCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getIntConWsAfterParenOpen(MA_IntCon arg) */

MA_Layout MA_getIntConWsAfterParenOpen(MA_IntCon arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  MA_IntCon MA_setIntConWsAfterParenOpen(MA_IntCon arg, MA_Layout wsAfterParenOpen) */

MA_IntCon MA_setIntConWsAfterParenOpen(MA_IntCon arg, MA_Layout wsAfterParenOpen)
{
  if (MA_isIntConCon(arg)) {
    return (MA_IntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenOpen, 3), 1);
  }

  ATabort("IntCon has no WsAfterParenOpen: %t\n", arg);
  return (MA_IntCon)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasIntConIntArg(MA_IntCon arg) */

ATbool MA_hasIntConIntArg(MA_IntCon arg)
{
  if (MA_isIntConCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Int MA_getIntConIntArg(MA_IntCon arg) */

MA_Int MA_getIntConIntArg(MA_IntCon arg)
{
  
    return (MA_Int)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  MA_IntCon MA_setIntConIntArg(MA_IntCon arg, MA_Int intArg) */

MA_IntCon MA_setIntConIntArg(MA_IntCon arg, MA_Int intArg)
{
  if (MA_isIntConCon(arg)) {
    return (MA_IntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)intArg, 4), 1);
  }

  ATabort("IntCon has no IntArg: %t\n", arg);
  return (MA_IntCon)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasIntConWsAfterIntArg(MA_IntCon arg) */

ATbool MA_hasIntConWsAfterIntArg(MA_IntCon arg)
{
  if (MA_isIntConCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getIntConWsAfterIntArg(MA_IntCon arg) */

MA_Layout MA_getIntConWsAfterIntArg(MA_IntCon arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  MA_IntCon MA_setIntConWsAfterIntArg(MA_IntCon arg, MA_Layout wsAfterIntArg) */

MA_IntCon MA_setIntConWsAfterIntArg(MA_IntCon arg, MA_Layout wsAfterIntArg)
{
  if (MA_isIntConCon(arg)) {
    return (MA_IntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterIntArg, 5), 1);
  }

  ATabort("IntCon has no WsAfterIntArg: %t\n", arg);
  return (MA_IntCon)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasIntConNatCon(MA_IntCon arg) */

ATbool MA_hasIntConNatCon(MA_IntCon arg)
{
  if (MA_isIntConNat(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_NatCon MA_getIntConNatCon(MA_IntCon arg) */

MA_NatCon MA_getIntConNatCon(MA_IntCon arg)
{
  
    return (MA_NatCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  MA_IntCon MA_setIntConNatCon(MA_IntCon arg, MA_NatCon NatCon) */

MA_IntCon MA_setIntConNatCon(MA_IntCon arg, MA_NatCon NatCon)
{
  if (MA_isIntConNat(arg)) {
    return (MA_IntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)NatCon, 0), 1);
  }

  ATabort("IntCon has no NatCon: %t\n", arg);
  return (MA_IntCon)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasIntConWsAfterPlus(MA_IntCon arg) */

ATbool MA_hasIntConWsAfterPlus(MA_IntCon arg)
{
  if (MA_isIntConPos(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getIntConWsAfterPlus(MA_IntCon arg) */

MA_Layout MA_getIntConWsAfterPlus(MA_IntCon arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_IntCon MA_setIntConWsAfterPlus(MA_IntCon arg, MA_Layout wsAfterPlus) */

MA_IntCon MA_setIntConWsAfterPlus(MA_IntCon arg, MA_Layout wsAfterPlus)
{
  if (MA_isIntConPos(arg)) {
    return (MA_IntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterPlus, 1), 1);
  }

  ATabort("IntCon has no WsAfterPlus: %t\n", arg);
  return (MA_IntCon)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasIntConNatArg(MA_IntCon arg) */

ATbool MA_hasIntConNatArg(MA_IntCon arg)
{
  if (MA_isIntConPos(arg)) {
    return ATtrue;
  }
  else if (MA_isIntConNeg(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_NatCon MA_getIntConNatArg(MA_IntCon arg) */

MA_NatCon MA_getIntConNatArg(MA_IntCon arg)
{
  if (MA_isIntConPos(arg)) {
    return (MA_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else 
    return (MA_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  MA_IntCon MA_setIntConNatArg(MA_IntCon arg, MA_NatCon natArg) */

MA_IntCon MA_setIntConNatArg(MA_IntCon arg, MA_NatCon natArg)
{
  if (MA_isIntConPos(arg)) {
    return (MA_IntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)natArg, 2), 1);
  }
  else if (MA_isIntConNeg(arg)) {
    return (MA_IntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)natArg, 2), 1);
  }

  ATabort("IntCon has no NatArg: %t\n", arg);
  return (MA_IntCon)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasIntConWsAfter(MA_IntCon arg) */

ATbool MA_hasIntConWsAfter(MA_IntCon arg)
{
  if (MA_isIntConNeg(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getIntConWsAfter(MA_IntCon arg) */

MA_Layout MA_getIntConWsAfter(MA_IntCon arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_IntCon MA_setIntConWsAfter(MA_IntCon arg, MA_Layout wsAfter) */

MA_IntCon MA_setIntConWsAfter(MA_IntCon arg, MA_Layout wsAfter)
{
  if (MA_isIntConNeg(arg)) {
    return (MA_IntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfter, 1), 1);
  }

  ATabort("IntCon has no WsAfter: %t\n", arg);
  return (MA_IntCon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_NatCon accessors */

/*{{{  ATbool MA_isValidNatCon(MA_NatCon arg) */

ATbool MA_isValidNatCon(MA_NatCon arg)
{
  if (MA_isNatConAbs(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isNatConAbs(MA_NatCon arg) */

inline ATbool MA_isNatConAbs(MA_NatCon arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MA_patternNatConAbs, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool MA_hasNatConWsAfterAbs(MA_NatCon arg) */

ATbool MA_hasNatConWsAfterAbs(MA_NatCon arg)
{
  if (MA_isNatConAbs(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getNatConWsAfterAbs(MA_NatCon arg) */

MA_Layout MA_getNatConWsAfterAbs(MA_NatCon arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_NatCon MA_setNatConWsAfterAbs(MA_NatCon arg, MA_Layout wsAfterAbs) */

MA_NatCon MA_setNatConWsAfterAbs(MA_NatCon arg, MA_Layout wsAfterAbs)
{
  if (MA_isNatConAbs(arg)) {
    return (MA_NatCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterAbs, 1), 1);
  }

  ATabort("NatCon has no WsAfterAbs: %t\n", arg);
  return (MA_NatCon)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasNatConWsAfterParenOpen(MA_NatCon arg) */

ATbool MA_hasNatConWsAfterParenOpen(MA_NatCon arg)
{
  if (MA_isNatConAbs(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getNatConWsAfterParenOpen(MA_NatCon arg) */

MA_Layout MA_getNatConWsAfterParenOpen(MA_NatCon arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  MA_NatCon MA_setNatConWsAfterParenOpen(MA_NatCon arg, MA_Layout wsAfterParenOpen) */

MA_NatCon MA_setNatConWsAfterParenOpen(MA_NatCon arg, MA_Layout wsAfterParenOpen)
{
  if (MA_isNatConAbs(arg)) {
    return (MA_NatCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenOpen, 3), 1);
  }

  ATabort("NatCon has no WsAfterParenOpen: %t\n", arg);
  return (MA_NatCon)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasNatConIntArg(MA_NatCon arg) */

ATbool MA_hasNatConIntArg(MA_NatCon arg)
{
  if (MA_isNatConAbs(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Int MA_getNatConIntArg(MA_NatCon arg) */

MA_Int MA_getNatConIntArg(MA_NatCon arg)
{
  
    return (MA_Int)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  MA_NatCon MA_setNatConIntArg(MA_NatCon arg, MA_Int intArg) */

MA_NatCon MA_setNatConIntArg(MA_NatCon arg, MA_Int intArg)
{
  if (MA_isNatConAbs(arg)) {
    return (MA_NatCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)intArg, 4), 1);
  }

  ATabort("NatCon has no IntArg: %t\n", arg);
  return (MA_NatCon)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasNatConWsAfterIntArg(MA_NatCon arg) */

ATbool MA_hasNatConWsAfterIntArg(MA_NatCon arg)
{
  if (MA_isNatConAbs(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getNatConWsAfterIntArg(MA_NatCon arg) */

MA_Layout MA_getNatConWsAfterIntArg(MA_NatCon arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  MA_NatCon MA_setNatConWsAfterIntArg(MA_NatCon arg, MA_Layout wsAfterIntArg) */

MA_NatCon MA_setNatConWsAfterIntArg(MA_NatCon arg, MA_Layout wsAfterIntArg)
{
  if (MA_isNatConAbs(arg)) {
    return (MA_NatCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterIntArg, 5), 1);
  }

  ATabort("NatCon has no WsAfterIntArg: %t\n", arg);
  return (MA_NatCon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_Var accessors */

/*{{{  ATbool MA_isValidVar(MA_Var arg) */

ATbool MA_isValidVar(MA_Var arg)
{
  if (MA_isVarNormal(arg)) {
    return ATtrue;
  }
  else if (MA_isVarStar(arg)) {
    return ATtrue;
  }
  else if (MA_isVarPlus(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isVarNormal(MA_Var arg) */

inline ATbool MA_isVarNormal(MA_Var arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternVarNormal, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isVarStar(MA_Var arg) */

inline ATbool MA_isVarStar(MA_Var arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternVarStar, NULL, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isVarPlus(MA_Var arg) */

inline ATbool MA_isVarPlus(MA_Var arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternVarPlus, NULL, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MA_hasVarVarId(MA_Var arg) */

ATbool MA_hasVarVarId(MA_Var arg)
{
  if (MA_isVarNormal(arg)) {
    return ATtrue;
  }
  else if (MA_isVarStar(arg)) {
    return ATtrue;
  }
  else if (MA_isVarPlus(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_VarId MA_getVarVarId(MA_Var arg) */

MA_VarId MA_getVarVarId(MA_Var arg)
{
  if (MA_isVarNormal(arg)) {
    return (MA_VarId)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (MA_isVarStar(arg)) {
    return (MA_VarId)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else 
    return (MA_VarId)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  MA_Var MA_setVarVarId(MA_Var arg, MA_VarId VarId) */

MA_Var MA_setVarVarId(MA_Var arg, MA_VarId VarId)
{
  if (MA_isVarNormal(arg)) {
    return (MA_Var)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)VarId, 0), 1);
  }
  else if (MA_isVarStar(arg)) {
    return (MA_Var)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)VarId, 2), 1);
  }
  else if (MA_isVarPlus(arg)) {
    return (MA_Var)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)VarId, 2), 1);
  }

  ATabort("Var has no VarId: %t\n", arg);
  return (MA_Var)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasVarWsAfterStar(MA_Var arg) */

ATbool MA_hasVarWsAfterStar(MA_Var arg)
{
  if (MA_isVarStar(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getVarWsAfterStar(MA_Var arg) */

MA_Layout MA_getVarWsAfterStar(MA_Var arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_Var MA_setVarWsAfterStar(MA_Var arg, MA_Layout wsAfterStar) */

MA_Var MA_setVarWsAfterStar(MA_Var arg, MA_Layout wsAfterStar)
{
  if (MA_isVarStar(arg)) {
    return (MA_Var)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterStar, 1), 1);
  }

  ATabort("Var has no WsAfterStar: %t\n", arg);
  return (MA_Var)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasVarWsAfterPlus(MA_Var arg) */

ATbool MA_hasVarWsAfterPlus(MA_Var arg)
{
  if (MA_isVarPlus(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getVarWsAfterPlus(MA_Var arg) */

MA_Layout MA_getVarWsAfterPlus(MA_Var arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_Var MA_setVarWsAfterPlus(MA_Var arg, MA_Layout wsAfterPlus) */

MA_Var MA_setVarWsAfterPlus(MA_Var arg, MA_Layout wsAfterPlus)
{
  if (MA_isVarPlus(arg)) {
    return (MA_Var)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterPlus, 1), 1);
  }

  ATabort("Var has no WsAfterPlus: %t\n", arg);
  return (MA_Var)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_Term accessors */

/*{{{  ATbool MA_isValidTerm(MA_Term arg) */

ATbool MA_isValidTerm(MA_Term arg)
{
  if (MA_isTermVar(arg)) {
    return ATtrue;
  }
  else if (MA_isTermConstant(arg)) {
    return ATtrue;
  }
  else if (MA_isTermInt(arg)) {
    return ATtrue;
  }
  else if (MA_isTermFunc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isTermVar(MA_Term arg) */

inline ATbool MA_isTermVar(MA_Term arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternTermVar, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isTermConstant(MA_Term arg) */

inline ATbool MA_isTermConstant(MA_Term arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternTermConstant, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isTermInt(MA_Term arg) */

inline ATbool MA_isTermInt(MA_Term arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternTermInt, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isTermFunc(MA_Term arg) */

inline ATbool MA_isTermFunc(MA_Term arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternTermFunc, NULL, NULL, NULL, NULL, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MA_hasTermVar(MA_Term arg) */

ATbool MA_hasTermVar(MA_Term arg)
{
  if (MA_isTermVar(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Var MA_getTermVar(MA_Term arg) */

MA_Var MA_getTermVar(MA_Term arg)
{
  
    return (MA_Var)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  MA_Term MA_setTermVar(MA_Term arg, MA_Var Var) */

MA_Term MA_setTermVar(MA_Term arg, MA_Var Var)
{
  if (MA_isTermVar(arg)) {
    return (MA_Term)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Var, 0), 1);
  }

  ATabort("Term has no Var: %t\n", arg);
  return (MA_Term)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasTermFunId(MA_Term arg) */

ATbool MA_hasTermFunId(MA_Term arg)
{
  if (MA_isTermConstant(arg)) {
    return ATtrue;
  }
  else if (MA_isTermFunc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_FunId MA_getTermFunId(MA_Term arg) */

MA_FunId MA_getTermFunId(MA_Term arg)
{
  if (MA_isTermConstant(arg)) {
    return (MA_FunId)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (MA_FunId)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  MA_Term MA_setTermFunId(MA_Term arg, MA_FunId FunId) */

MA_Term MA_setTermFunId(MA_Term arg, MA_FunId FunId)
{
  if (MA_isTermConstant(arg)) {
    return (MA_Term)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)FunId, 0), 1);
  }
  else if (MA_isTermFunc(arg)) {
    return (MA_Term)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)FunId, 0), 1);
  }

  ATabort("Term has no FunId: %t\n", arg);
  return (MA_Term)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasTermInt(MA_Term arg) */

ATbool MA_hasTermInt(MA_Term arg)
{
  if (MA_isTermInt(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Int MA_getTermInt(MA_Term arg) */

MA_Int MA_getTermInt(MA_Term arg)
{
  
    return (MA_Int)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  MA_Term MA_setTermInt(MA_Term arg, MA_Int Int) */

MA_Term MA_setTermInt(MA_Term arg, MA_Int Int)
{
  if (MA_isTermInt(arg)) {
    return (MA_Term)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Int, 0), 1);
  }

  ATabort("Term has no Int: %t\n", arg);
  return (MA_Term)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasTermWsAfterFunId(MA_Term arg) */

ATbool MA_hasTermWsAfterFunId(MA_Term arg)
{
  if (MA_isTermFunc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getTermWsAfterFunId(MA_Term arg) */

MA_Layout MA_getTermWsAfterFunId(MA_Term arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_Term MA_setTermWsAfterFunId(MA_Term arg, MA_Layout wsAfterFunId) */

MA_Term MA_setTermWsAfterFunId(MA_Term arg, MA_Layout wsAfterFunId)
{
  if (MA_isTermFunc(arg)) {
    return (MA_Term)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterFunId, 1), 1);
  }

  ATabort("Term has no WsAfterFunId: %t\n", arg);
  return (MA_Term)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasTermWsAfterParenOpen(MA_Term arg) */

ATbool MA_hasTermWsAfterParenOpen(MA_Term arg)
{
  if (MA_isTermFunc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getTermWsAfterParenOpen(MA_Term arg) */

MA_Layout MA_getTermWsAfterParenOpen(MA_Term arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  MA_Term MA_setTermWsAfterParenOpen(MA_Term arg, MA_Layout wsAfterParenOpen) */

MA_Term MA_setTermWsAfterParenOpen(MA_Term arg, MA_Layout wsAfterParenOpen)
{
  if (MA_isTermFunc(arg)) {
    return (MA_Term)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenOpen, 3), 1);
  }

  ATabort("Term has no WsAfterParenOpen: %t\n", arg);
  return (MA_Term)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasTermArgs(MA_Term arg) */

ATbool MA_hasTermArgs(MA_Term arg)
{
  if (MA_isTermFunc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_TermArgs MA_getTermArgs(MA_Term arg) */

MA_TermArgs MA_getTermArgs(MA_Term arg)
{
  
    return (MA_TermArgs)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), 1);
}

/*}}}  */
/*{{{  MA_Term MA_setTermArgs(MA_Term arg, MA_TermArgs args) */

MA_Term MA_setTermArgs(MA_Term arg, MA_TermArgs args)
{
  if (MA_isTermFunc(arg)) {
    return (MA_Term)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), (ATerm)args, 1), 4), 1);
  }

  ATabort("Term has no Args: %t\n", arg);
  return (MA_Term)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasTermWsAfterArgs(MA_Term arg) */

ATbool MA_hasTermWsAfterArgs(MA_Term arg)
{
  if (MA_isTermFunc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getTermWsAfterArgs(MA_Term arg) */

MA_Layout MA_getTermWsAfterArgs(MA_Term arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  MA_Term MA_setTermWsAfterArgs(MA_Term arg, MA_Layout wsAfterArgs) */

MA_Term MA_setTermWsAfterArgs(MA_Term arg, MA_Layout wsAfterArgs)
{
  if (MA_isTermFunc(arg)) {
    return (MA_Term)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterArgs, 5), 1);
  }

  ATabort("Term has no WsAfterArgs: %t\n", arg);
  return (MA_Term)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_TermArgs accessors */

/*{{{  ATbool MA_isValidTermArgs(MA_TermArgs arg) */

ATbool MA_isValidTermArgs(MA_TermArgs arg)
{
  if (MA_isTermArgsSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isTermArgsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isTermArgsSingle(MA_TermArgs arg) */

inline ATbool MA_isTermArgsSingle(MA_TermArgs arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternTermArgsSingle, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isTermArgsMany(MA_TermArgs arg) */

inline ATbool MA_isTermArgsMany(MA_TermArgs arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternTermArgsMany, NULL, NULL, NULL, NULL, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MA_hasTermArgsHead(MA_TermArgs arg) */

ATbool MA_hasTermArgsHead(MA_TermArgs arg)
{
  if (MA_isTermArgsSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isTermArgsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Term MA_getTermArgsHead(MA_TermArgs arg) */

MA_Term MA_getTermArgsHead(MA_TermArgs arg)
{
  if (MA_isTermArgsSingle(arg)) {
    return (MA_Term)ATgetFirst((ATermList)arg);
  }
  else 
    return (MA_Term)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  MA_TermArgs MA_setTermArgsHead(MA_TermArgs arg, MA_Term head) */

MA_TermArgs MA_setTermArgsHead(MA_TermArgs arg, MA_Term head)
{
  if (MA_isTermArgsSingle(arg)) {
    return (MA_TermArgs)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (MA_isTermArgsMany(arg)) {
    return (MA_TermArgs)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("TermArgs has no Head: %t\n", arg);
  return (MA_TermArgs)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasTermArgsWsAfterFirst(MA_TermArgs arg) */

ATbool MA_hasTermArgsWsAfterFirst(MA_TermArgs arg)
{
  if (MA_isTermArgsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getTermArgsWsAfterFirst(MA_TermArgs arg) */

MA_Layout MA_getTermArgsWsAfterFirst(MA_TermArgs arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  MA_TermArgs MA_setTermArgsWsAfterFirst(MA_TermArgs arg, MA_Layout wsAfterFirst) */

MA_TermArgs MA_setTermArgsWsAfterFirst(MA_TermArgs arg, MA_Layout wsAfterFirst)
{
  if (MA_isTermArgsMany(arg)) {
    return (MA_TermArgs)ATreplace((ATermList)arg, (ATerm)wsAfterFirst, 1);
  }

  ATabort("TermArgs has no WsAfterFirst: %t\n", arg);
  return (MA_TermArgs)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasTermArgsSep(MA_TermArgs arg) */

ATbool MA_hasTermArgsSep(MA_TermArgs arg)
{
  if (MA_isTermArgsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * MA_getTermArgsSep(MA_TermArgs arg) */

char * MA_getTermArgsSep(MA_TermArgs arg)
{
  
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), 0)));
}

/*}}}  */
/*{{{  MA_TermArgs MA_setTermArgsSep(MA_TermArgs arg, char * sep) */

MA_TermArgs MA_setTermArgsSep(MA_TermArgs arg, char * sep)
{
  if (MA_isTermArgsMany(arg)) {
    return (MA_TermArgs)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)), 0), 2);
  }

  ATabort("TermArgs has no Sep: %t\n", arg);
  return (MA_TermArgs)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasTermArgsWsAfterSep(MA_TermArgs arg) */

ATbool MA_hasTermArgsWsAfterSep(MA_TermArgs arg)
{
  if (MA_isTermArgsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getTermArgsWsAfterSep(MA_TermArgs arg) */

MA_Layout MA_getTermArgsWsAfterSep(MA_TermArgs arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  MA_TermArgs MA_setTermArgsWsAfterSep(MA_TermArgs arg, MA_Layout wsAfterSep) */

MA_TermArgs MA_setTermArgsWsAfterSep(MA_TermArgs arg, MA_Layout wsAfterSep)
{
  if (MA_isTermArgsMany(arg)) {
    return (MA_TermArgs)ATreplace((ATermList)arg, (ATerm)wsAfterSep, 3);
  }

  ATabort("TermArgs has no WsAfterSep: %t\n", arg);
  return (MA_TermArgs)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasTermArgsTail(MA_TermArgs arg) */

ATbool MA_hasTermArgsTail(MA_TermArgs arg)
{
  if (MA_isTermArgsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_TermArgs MA_getTermArgsTail(MA_TermArgs arg) */

MA_TermArgs MA_getTermArgsTail(MA_TermArgs arg)
{
  
    return (MA_TermArgs)ATgetTail((ATermList)arg, 4);
}

/*}}}  */
/*{{{  MA_TermArgs MA_setTermArgsTail(MA_TermArgs arg, MA_TermArgs tail) */

MA_TermArgs MA_setTermArgsTail(MA_TermArgs arg, MA_TermArgs tail)
{
  if (MA_isTermArgsMany(arg)) {
    return (MA_TermArgs)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("TermArgs has no Tail: %t\n", arg);
  return (MA_TermArgs)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_TermList accessors */

/*{{{  ATbool MA_isValidTermList(MA_TermList arg) */

ATbool MA_isValidTermList(MA_TermList arg)
{
  if (MA_isTermListDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isTermListDefault(MA_TermList arg) */

inline ATbool MA_isTermListDefault(MA_TermList arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MA_patternTermListDefault, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool MA_hasTermListElems(MA_TermList arg) */

ATbool MA_hasTermListElems(MA_TermList arg)
{
  if (MA_isTermListDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_TermElems MA_getTermListElems(MA_TermList arg) */

MA_TermElems MA_getTermListElems(MA_TermList arg)
{
  
    return (MA_TermElems)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  MA_TermList MA_setTermListElems(MA_TermList arg, MA_TermElems elems) */

MA_TermList MA_setTermListElems(MA_TermList arg, MA_TermElems elems)
{
  if (MA_isTermListDefault(arg)) {
    return (MA_TermList)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)elems, 1), 0), 1);
  }

  ATabort("TermList has no Elems: %t\n", arg);
  return (MA_TermList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_TermElems accessors */

/*{{{  ATbool MA_isValidTermElems(MA_TermElems arg) */

ATbool MA_isValidTermElems(MA_TermElems arg)
{
  if (MA_isTermElemsEmpty(arg)) {
    return ATtrue;
  }
  else if (MA_isTermElemsSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isTermElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isTermElemsEmpty(MA_TermElems arg) */

inline ATbool MA_isTermElemsEmpty(MA_TermElems arg)
{
  return ATmatchTerm((ATerm)arg, MA_patternTermElemsEmpty);
}

/*}}}  */
/*{{{  inline ATbool MA_isTermElemsSingle(MA_TermElems arg) */

inline ATbool MA_isTermElemsSingle(MA_TermElems arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternTermElemsSingle, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isTermElemsMany(MA_TermElems arg) */

inline ATbool MA_isTermElemsMany(MA_TermElems arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternTermElemsMany, NULL, NULL, NULL, NULL, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MA_hasTermElemsHead(MA_TermElems arg) */

ATbool MA_hasTermElemsHead(MA_TermElems arg)
{
  if (MA_isTermElemsSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isTermElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Term MA_getTermElemsHead(MA_TermElems arg) */

MA_Term MA_getTermElemsHead(MA_TermElems arg)
{
  if (MA_isTermElemsSingle(arg)) {
    return (MA_Term)ATgetFirst((ATermList)arg);
  }
  else 
    return (MA_Term)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  MA_TermElems MA_setTermElemsHead(MA_TermElems arg, MA_Term head) */

MA_TermElems MA_setTermElemsHead(MA_TermElems arg, MA_Term head)
{
  if (MA_isTermElemsSingle(arg)) {
    return (MA_TermElems)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (MA_isTermElemsMany(arg)) {
    return (MA_TermElems)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("TermElems has no Head: %t\n", arg);
  return (MA_TermElems)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasTermElemsWsAfterFirst(MA_TermElems arg) */

ATbool MA_hasTermElemsWsAfterFirst(MA_TermElems arg)
{
  if (MA_isTermElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getTermElemsWsAfterFirst(MA_TermElems arg) */

MA_Layout MA_getTermElemsWsAfterFirst(MA_TermElems arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  MA_TermElems MA_setTermElemsWsAfterFirst(MA_TermElems arg, MA_Layout wsAfterFirst) */

MA_TermElems MA_setTermElemsWsAfterFirst(MA_TermElems arg, MA_Layout wsAfterFirst)
{
  if (MA_isTermElemsMany(arg)) {
    return (MA_TermElems)ATreplace((ATermList)arg, (ATerm)wsAfterFirst, 1);
  }

  ATabort("TermElems has no WsAfterFirst: %t\n", arg);
  return (MA_TermElems)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasTermElemsSep(MA_TermElems arg) */

ATbool MA_hasTermElemsSep(MA_TermElems arg)
{
  if (MA_isTermElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * MA_getTermElemsSep(MA_TermElems arg) */

char * MA_getTermElemsSep(MA_TermElems arg)
{
  
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), 0)));
}

/*}}}  */
/*{{{  MA_TermElems MA_setTermElemsSep(MA_TermElems arg, char * sep) */

MA_TermElems MA_setTermElemsSep(MA_TermElems arg, char * sep)
{
  if (MA_isTermElemsMany(arg)) {
    return (MA_TermElems)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)), 0), 2);
  }

  ATabort("TermElems has no Sep: %t\n", arg);
  return (MA_TermElems)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasTermElemsWsAfterSep(MA_TermElems arg) */

ATbool MA_hasTermElemsWsAfterSep(MA_TermElems arg)
{
  if (MA_isTermElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getTermElemsWsAfterSep(MA_TermElems arg) */

MA_Layout MA_getTermElemsWsAfterSep(MA_TermElems arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  MA_TermElems MA_setTermElemsWsAfterSep(MA_TermElems arg, MA_Layout wsAfterSep) */

MA_TermElems MA_setTermElemsWsAfterSep(MA_TermElems arg, MA_Layout wsAfterSep)
{
  if (MA_isTermElemsMany(arg)) {
    return (MA_TermElems)ATreplace((ATermList)arg, (ATerm)wsAfterSep, 3);
  }

  ATabort("TermElems has no WsAfterSep: %t\n", arg);
  return (MA_TermElems)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasTermElemsTail(MA_TermElems arg) */

ATbool MA_hasTermElemsTail(MA_TermElems arg)
{
  if (MA_isTermElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_TermElems MA_getTermElemsTail(MA_TermElems arg) */

MA_TermElems MA_getTermElemsTail(MA_TermElems arg)
{
  
    return (MA_TermElems)ATgetTail((ATermList)arg, 4);
}

/*}}}  */
/*{{{  MA_TermElems MA_setTermElemsTail(MA_TermElems arg, MA_TermElems tail) */

MA_TermElems MA_setTermElemsTail(MA_TermElems arg, MA_TermElems tail)
{
  if (MA_isTermElemsMany(arg)) {
    return (MA_TermElems)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("TermElems has no Tail: %t\n", arg);
  return (MA_TermElems)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_SigArg accessors */

/*{{{  ATbool MA_isValidSigArg(MA_SigArg arg) */

ATbool MA_isValidSigArg(MA_SigArg arg)
{
  if (MA_isSigArgNormal(arg)) {
    return ATtrue;
  }
  else if (MA_isSigArgStar(arg)) {
    return ATtrue;
  }
  else if (MA_isSigArgPlus(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isSigArgNormal(MA_SigArg arg) */

inline ATbool MA_isSigArgNormal(MA_SigArg arg)
{
  return ATmatchTerm((ATerm)arg, MA_patternSigArgNormal);
}

/*}}}  */
/*{{{  inline ATbool MA_isSigArgStar(MA_SigArg arg) */

inline ATbool MA_isSigArgStar(MA_SigArg arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternSigArgStar, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isSigArgPlus(MA_SigArg arg) */

inline ATbool MA_isSigArgPlus(MA_SigArg arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternSigArgPlus, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MA_hasSigArgWsAfterUnderscore(MA_SigArg arg) */

ATbool MA_hasSigArgWsAfterUnderscore(MA_SigArg arg)
{
  if (MA_isSigArgStar(arg)) {
    return ATtrue;
  }
  else if (MA_isSigArgPlus(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getSigArgWsAfterUnderscore(MA_SigArg arg) */

MA_Layout MA_getSigArgWsAfterUnderscore(MA_SigArg arg)
{
  if (MA_isSigArgStar(arg)) {
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else 
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_SigArg MA_setSigArgWsAfterUnderscore(MA_SigArg arg, MA_Layout wsAfterUnderscore) */

MA_SigArg MA_setSigArgWsAfterUnderscore(MA_SigArg arg, MA_Layout wsAfterUnderscore)
{
  if (MA_isSigArgStar(arg)) {
    return (MA_SigArg)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterUnderscore, 1), 1);
  }
  else if (MA_isSigArgPlus(arg)) {
    return (MA_SigArg)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterUnderscore, 1), 1);
  }

  ATabort("SigArg has no WsAfterUnderscore: %t\n", arg);
  return (MA_SigArg)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_FuncDef accessors */

/*{{{  ATbool MA_isValidFuncDef(MA_FuncDef arg) */

ATbool MA_isValidFuncDef(MA_FuncDef arg)
{
  if (MA_isFuncDefConstantNoAnnos(arg)) {
    return ATtrue;
  }
  else if (MA_isFuncDefConstantWithAnnos(arg)) {
    return ATtrue;
  }
  else if (MA_isFuncDefFuncNoAnnos(arg)) {
    return ATtrue;
  }
  else if (MA_isFuncDefFuncWithAnnos(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isFuncDefConstantNoAnnos(MA_FuncDef arg) */

inline ATbool MA_isFuncDefConstantNoAnnos(MA_FuncDef arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternFuncDefConstantNoAnnos, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isFuncDefConstantWithAnnos(MA_FuncDef arg) */

inline ATbool MA_isFuncDefConstantWithAnnos(MA_FuncDef arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternFuncDefConstantWithAnnos, NULL, NULL, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isFuncDefFuncNoAnnos(MA_FuncDef arg) */

inline ATbool MA_isFuncDefFuncNoAnnos(MA_FuncDef arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternFuncDefFuncNoAnnos, NULL, NULL, NULL, NULL, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isFuncDefFuncWithAnnos(MA_FuncDef arg) */

inline ATbool MA_isFuncDefFuncWithAnnos(MA_FuncDef arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternFuncDefFuncWithAnnos, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MA_hasFuncDefFunId(MA_FuncDef arg) */

ATbool MA_hasFuncDefFunId(MA_FuncDef arg)
{
  if (MA_isFuncDefConstantNoAnnos(arg)) {
    return ATtrue;
  }
  else if (MA_isFuncDefConstantWithAnnos(arg)) {
    return ATtrue;
  }
  else if (MA_isFuncDefFuncNoAnnos(arg)) {
    return ATtrue;
  }
  else if (MA_isFuncDefFuncWithAnnos(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_FunId MA_getFuncDefFunId(MA_FuncDef arg) */

MA_FunId MA_getFuncDefFunId(MA_FuncDef arg)
{
  if (MA_isFuncDefConstantNoAnnos(arg)) {
    return (MA_FunId)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (MA_isFuncDefConstantWithAnnos(arg)) {
    return (MA_FunId)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (MA_isFuncDefFuncNoAnnos(arg)) {
    return (MA_FunId)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (MA_FunId)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  MA_FuncDef MA_setFuncDefFunId(MA_FuncDef arg, MA_FunId FunId) */

MA_FuncDef MA_setFuncDefFunId(MA_FuncDef arg, MA_FunId FunId)
{
  if (MA_isFuncDefConstantNoAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)FunId, 0), 1);
  }
  else if (MA_isFuncDefConstantWithAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)FunId, 0), 1);
  }
  else if (MA_isFuncDefFuncNoAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)FunId, 0), 1);
  }
  else if (MA_isFuncDefFuncWithAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)FunId, 0), 1);
  }

  ATabort("FuncDef has no FunId: %t\n", arg);
  return (MA_FuncDef)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasFuncDefWsAfterFunId(MA_FuncDef arg) */

ATbool MA_hasFuncDefWsAfterFunId(MA_FuncDef arg)
{
  if (MA_isFuncDefConstantWithAnnos(arg)) {
    return ATtrue;
  }
  else if (MA_isFuncDefFuncNoAnnos(arg)) {
    return ATtrue;
  }
  else if (MA_isFuncDefFuncWithAnnos(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getFuncDefWsAfterFunId(MA_FuncDef arg) */

MA_Layout MA_getFuncDefWsAfterFunId(MA_FuncDef arg)
{
  if (MA_isFuncDefConstantWithAnnos(arg)) {
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else if (MA_isFuncDefFuncNoAnnos(arg)) {
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else 
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_FuncDef MA_setFuncDefWsAfterFunId(MA_FuncDef arg, MA_Layout wsAfterFunId) */

MA_FuncDef MA_setFuncDefWsAfterFunId(MA_FuncDef arg, MA_Layout wsAfterFunId)
{
  if (MA_isFuncDefConstantWithAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterFunId, 1), 1);
  }
  else if (MA_isFuncDefFuncNoAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterFunId, 1), 1);
  }
  else if (MA_isFuncDefFuncWithAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterFunId, 1), 1);
  }

  ATabort("FuncDef has no WsAfterFunId: %t\n", arg);
  return (MA_FuncDef)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasFuncDefAnnos(MA_FuncDef arg) */

ATbool MA_hasFuncDefAnnos(MA_FuncDef arg)
{
  if (MA_isFuncDefConstantWithAnnos(arg)) {
    return ATtrue;
  }
  else if (MA_isFuncDefFuncWithAnnos(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Annotations MA_getFuncDefAnnos(MA_FuncDef arg) */

MA_Annotations MA_getFuncDefAnnos(MA_FuncDef arg)
{
  if (MA_isFuncDefConstantWithAnnos(arg)) {
    return (MA_Annotations)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else 
    return (MA_Annotations)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/*}}}  */
/*{{{  MA_FuncDef MA_setFuncDefAnnos(MA_FuncDef arg, MA_Annotations annos) */

MA_FuncDef MA_setFuncDefAnnos(MA_FuncDef arg, MA_Annotations annos)
{
  if (MA_isFuncDefConstantWithAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)annos, 2), 1);
  }
  else if (MA_isFuncDefFuncWithAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)annos, 8), 1);
  }

  ATabort("FuncDef has no Annos: %t\n", arg);
  return (MA_FuncDef)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasFuncDefWsAfterParenOpen(MA_FuncDef arg) */

ATbool MA_hasFuncDefWsAfterParenOpen(MA_FuncDef arg)
{
  if (MA_isFuncDefFuncNoAnnos(arg)) {
    return ATtrue;
  }
  else if (MA_isFuncDefFuncWithAnnos(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getFuncDefWsAfterParenOpen(MA_FuncDef arg) */

MA_Layout MA_getFuncDefWsAfterParenOpen(MA_FuncDef arg)
{
  if (MA_isFuncDefFuncNoAnnos(arg)) {
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  MA_FuncDef MA_setFuncDefWsAfterParenOpen(MA_FuncDef arg, MA_Layout wsAfterParenOpen) */

MA_FuncDef MA_setFuncDefWsAfterParenOpen(MA_FuncDef arg, MA_Layout wsAfterParenOpen)
{
  if (MA_isFuncDefFuncNoAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenOpen, 3), 1);
  }
  else if (MA_isFuncDefFuncWithAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenOpen, 3), 1);
  }

  ATabort("FuncDef has no WsAfterParenOpen: %t\n", arg);
  return (MA_FuncDef)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasFuncDefElems(MA_FuncDef arg) */

ATbool MA_hasFuncDefElems(MA_FuncDef arg)
{
  if (MA_isFuncDefFuncNoAnnos(arg)) {
    return ATtrue;
  }
  else if (MA_isFuncDefFuncWithAnnos(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_SigArgElems MA_getFuncDefElems(MA_FuncDef arg) */

MA_SigArgElems MA_getFuncDefElems(MA_FuncDef arg)
{
  if (MA_isFuncDefFuncNoAnnos(arg)) {
    return (MA_SigArgElems)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), 1);
  }
  else 
    return (MA_SigArgElems)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), 1);
}

/*}}}  */
/*{{{  MA_FuncDef MA_setFuncDefElems(MA_FuncDef arg, MA_SigArgElems elems) */

MA_FuncDef MA_setFuncDefElems(MA_FuncDef arg, MA_SigArgElems elems)
{
  if (MA_isFuncDefFuncNoAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), (ATerm)elems, 1), 4), 1);
  }
  else if (MA_isFuncDefFuncWithAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), (ATerm)elems, 1), 4), 1);
  }

  ATabort("FuncDef has no Elems: %t\n", arg);
  return (MA_FuncDef)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasFuncDefWsAfterElems(MA_FuncDef arg) */

ATbool MA_hasFuncDefWsAfterElems(MA_FuncDef arg)
{
  if (MA_isFuncDefFuncNoAnnos(arg)) {
    return ATtrue;
  }
  else if (MA_isFuncDefFuncWithAnnos(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getFuncDefWsAfterElems(MA_FuncDef arg) */

MA_Layout MA_getFuncDefWsAfterElems(MA_FuncDef arg)
{
  if (MA_isFuncDefFuncNoAnnos(arg)) {
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else 
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  MA_FuncDef MA_setFuncDefWsAfterElems(MA_FuncDef arg, MA_Layout wsAfterElems) */

MA_FuncDef MA_setFuncDefWsAfterElems(MA_FuncDef arg, MA_Layout wsAfterElems)
{
  if (MA_isFuncDefFuncNoAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterElems, 5), 1);
  }
  else if (MA_isFuncDefFuncWithAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterElems, 5), 1);
  }

  ATabort("FuncDef has no WsAfterElems: %t\n", arg);
  return (MA_FuncDef)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasFuncDefWsAfterParenClose(MA_FuncDef arg) */

ATbool MA_hasFuncDefWsAfterParenClose(MA_FuncDef arg)
{
  if (MA_isFuncDefFuncWithAnnos(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getFuncDefWsAfterParenClose(MA_FuncDef arg) */

MA_Layout MA_getFuncDefWsAfterParenClose(MA_FuncDef arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  MA_FuncDef MA_setFuncDefWsAfterParenClose(MA_FuncDef arg, MA_Layout wsAfterParenClose) */

MA_FuncDef MA_setFuncDefWsAfterParenClose(MA_FuncDef arg, MA_Layout wsAfterParenClose)
{
  if (MA_isFuncDefFuncWithAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenClose, 7), 1);
  }

  ATabort("FuncDef has no WsAfterParenClose: %t\n", arg);
  return (MA_FuncDef)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_SigArgElems accessors */

/*{{{  ATbool MA_isValidSigArgElems(MA_SigArgElems arg) */

ATbool MA_isValidSigArgElems(MA_SigArgElems arg)
{
  if (MA_isSigArgElemsSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isSigArgElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isSigArgElemsSingle(MA_SigArgElems arg) */

inline ATbool MA_isSigArgElemsSingle(MA_SigArgElems arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternSigArgElemsSingle, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isSigArgElemsMany(MA_SigArgElems arg) */

inline ATbool MA_isSigArgElemsMany(MA_SigArgElems arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternSigArgElemsMany, NULL, NULL, NULL, NULL, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MA_hasSigArgElemsHead(MA_SigArgElems arg) */

ATbool MA_hasSigArgElemsHead(MA_SigArgElems arg)
{
  if (MA_isSigArgElemsSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isSigArgElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_SigArg MA_getSigArgElemsHead(MA_SigArgElems arg) */

MA_SigArg MA_getSigArgElemsHead(MA_SigArgElems arg)
{
  if (MA_isSigArgElemsSingle(arg)) {
    return (MA_SigArg)ATgetFirst((ATermList)arg);
  }
  else 
    return (MA_SigArg)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  MA_SigArgElems MA_setSigArgElemsHead(MA_SigArgElems arg, MA_SigArg head) */

MA_SigArgElems MA_setSigArgElemsHead(MA_SigArgElems arg, MA_SigArg head)
{
  if (MA_isSigArgElemsSingle(arg)) {
    return (MA_SigArgElems)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (MA_isSigArgElemsMany(arg)) {
    return (MA_SigArgElems)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("SigArgElems has no Head: %t\n", arg);
  return (MA_SigArgElems)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasSigArgElemsWsAfterFirst(MA_SigArgElems arg) */

ATbool MA_hasSigArgElemsWsAfterFirst(MA_SigArgElems arg)
{
  if (MA_isSigArgElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getSigArgElemsWsAfterFirst(MA_SigArgElems arg) */

MA_Layout MA_getSigArgElemsWsAfterFirst(MA_SigArgElems arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  MA_SigArgElems MA_setSigArgElemsWsAfterFirst(MA_SigArgElems arg, MA_Layout wsAfterFirst) */

MA_SigArgElems MA_setSigArgElemsWsAfterFirst(MA_SigArgElems arg, MA_Layout wsAfterFirst)
{
  if (MA_isSigArgElemsMany(arg)) {
    return (MA_SigArgElems)ATreplace((ATermList)arg, (ATerm)wsAfterFirst, 1);
  }

  ATabort("SigArgElems has no WsAfterFirst: %t\n", arg);
  return (MA_SigArgElems)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasSigArgElemsSep(MA_SigArgElems arg) */

ATbool MA_hasSigArgElemsSep(MA_SigArgElems arg)
{
  if (MA_isSigArgElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * MA_getSigArgElemsSep(MA_SigArgElems arg) */

char * MA_getSigArgElemsSep(MA_SigArgElems arg)
{
  
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), 0)));
}

/*}}}  */
/*{{{  MA_SigArgElems MA_setSigArgElemsSep(MA_SigArgElems arg, char * sep) */

MA_SigArgElems MA_setSigArgElemsSep(MA_SigArgElems arg, char * sep)
{
  if (MA_isSigArgElemsMany(arg)) {
    return (MA_SigArgElems)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)), 0), 2);
  }

  ATabort("SigArgElems has no Sep: %t\n", arg);
  return (MA_SigArgElems)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasSigArgElemsWsAfterSep(MA_SigArgElems arg) */

ATbool MA_hasSigArgElemsWsAfterSep(MA_SigArgElems arg)
{
  if (MA_isSigArgElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getSigArgElemsWsAfterSep(MA_SigArgElems arg) */

MA_Layout MA_getSigArgElemsWsAfterSep(MA_SigArgElems arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  MA_SigArgElems MA_setSigArgElemsWsAfterSep(MA_SigArgElems arg, MA_Layout wsAfterSep) */

MA_SigArgElems MA_setSigArgElemsWsAfterSep(MA_SigArgElems arg, MA_Layout wsAfterSep)
{
  if (MA_isSigArgElemsMany(arg)) {
    return (MA_SigArgElems)ATreplace((ATermList)arg, (ATerm)wsAfterSep, 3);
  }

  ATabort("SigArgElems has no WsAfterSep: %t\n", arg);
  return (MA_SigArgElems)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasSigArgElemsTail(MA_SigArgElems arg) */

ATbool MA_hasSigArgElemsTail(MA_SigArgElems arg)
{
  if (MA_isSigArgElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_SigArgElems MA_getSigArgElemsTail(MA_SigArgElems arg) */

MA_SigArgElems MA_getSigArgElemsTail(MA_SigArgElems arg)
{
  
    return (MA_SigArgElems)ATgetTail((ATermList)arg, 4);
}

/*}}}  */
/*{{{  MA_SigArgElems MA_setSigArgElemsTail(MA_SigArgElems arg, MA_SigArgElems tail) */

MA_SigArgElems MA_setSigArgElemsTail(MA_SigArgElems arg, MA_SigArgElems tail)
{
  if (MA_isSigArgElemsMany(arg)) {
    return (MA_SigArgElems)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("SigArgElems has no Tail: %t\n", arg);
  return (MA_SigArgElems)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_Annotations accessors */

/*{{{  ATbool MA_isValidAnnotations(MA_Annotations arg) */

ATbool MA_isValidAnnotations(MA_Annotations arg)
{
  if (MA_isAnnotationsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isAnnotationsDefault(MA_Annotations arg) */

inline ATbool MA_isAnnotationsDefault(MA_Annotations arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MA_patternAnnotationsDefault, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool MA_hasAnnotationsWsAfterBraceOpen(MA_Annotations arg) */

ATbool MA_hasAnnotationsWsAfterBraceOpen(MA_Annotations arg)
{
  if (MA_isAnnotationsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getAnnotationsWsAfterBraceOpen(MA_Annotations arg) */

MA_Layout MA_getAnnotationsWsAfterBraceOpen(MA_Annotations arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_Annotations MA_setAnnotationsWsAfterBraceOpen(MA_Annotations arg, MA_Layout wsAfterBraceOpen) */

MA_Annotations MA_setAnnotationsWsAfterBraceOpen(MA_Annotations arg, MA_Layout wsAfterBraceOpen)
{
  if (MA_isAnnotationsDefault(arg)) {
    return (MA_Annotations)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterBraceOpen, 1), 1);
  }

  ATabort("Annotations has no WsAfterBraceOpen: %t\n", arg);
  return (MA_Annotations)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasAnnotationsTerms(MA_Annotations arg) */

ATbool MA_hasAnnotationsTerms(MA_Annotations arg)
{
  if (MA_isAnnotationsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_TermTerms MA_getAnnotationsTerms(MA_Annotations arg) */

MA_TermTerms MA_getAnnotationsTerms(MA_Annotations arg)
{
  
    return (MA_TermTerms)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), 1);
}

/*}}}  */
/*{{{  MA_Annotations MA_setAnnotationsTerms(MA_Annotations arg, MA_TermTerms terms) */

MA_Annotations MA_setAnnotationsTerms(MA_Annotations arg, MA_TermTerms terms)
{
  if (MA_isAnnotationsDefault(arg)) {
    return (MA_Annotations)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), (ATerm)terms, 1), 2), 1);
  }

  ATabort("Annotations has no Terms: %t\n", arg);
  return (MA_Annotations)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasAnnotationsWsAfterTerms(MA_Annotations arg) */

ATbool MA_hasAnnotationsWsAfterTerms(MA_Annotations arg)
{
  if (MA_isAnnotationsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getAnnotationsWsAfterTerms(MA_Annotations arg) */

MA_Layout MA_getAnnotationsWsAfterTerms(MA_Annotations arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  MA_Annotations MA_setAnnotationsWsAfterTerms(MA_Annotations arg, MA_Layout wsAfterTerms) */

MA_Annotations MA_setAnnotationsWsAfterTerms(MA_Annotations arg, MA_Layout wsAfterTerms)
{
  if (MA_isAnnotationsDefault(arg)) {
    return (MA_Annotations)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterTerms, 3), 1);
  }

  ATabort("Annotations has no WsAfterTerms: %t\n", arg);
  return (MA_Annotations)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_TermTerms accessors */

/*{{{  ATbool MA_isValidTermTerms(MA_TermTerms arg) */

ATbool MA_isValidTermTerms(MA_TermTerms arg)
{
  if (MA_isTermTermsSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isTermTermsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isTermTermsSingle(MA_TermTerms arg) */

inline ATbool MA_isTermTermsSingle(MA_TermTerms arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternTermTermsSingle, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isTermTermsMany(MA_TermTerms arg) */

inline ATbool MA_isTermTermsMany(MA_TermTerms arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternTermTermsMany, NULL, NULL, NULL, NULL, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MA_hasTermTermsHead(MA_TermTerms arg) */

ATbool MA_hasTermTermsHead(MA_TermTerms arg)
{
  if (MA_isTermTermsSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isTermTermsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Term MA_getTermTermsHead(MA_TermTerms arg) */

MA_Term MA_getTermTermsHead(MA_TermTerms arg)
{
  if (MA_isTermTermsSingle(arg)) {
    return (MA_Term)ATgetFirst((ATermList)arg);
  }
  else 
    return (MA_Term)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  MA_TermTerms MA_setTermTermsHead(MA_TermTerms arg, MA_Term head) */

MA_TermTerms MA_setTermTermsHead(MA_TermTerms arg, MA_Term head)
{
  if (MA_isTermTermsSingle(arg)) {
    return (MA_TermTerms)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (MA_isTermTermsMany(arg)) {
    return (MA_TermTerms)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("TermTerms has no Head: %t\n", arg);
  return (MA_TermTerms)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasTermTermsWsAfterFirst(MA_TermTerms arg) */

ATbool MA_hasTermTermsWsAfterFirst(MA_TermTerms arg)
{
  if (MA_isTermTermsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getTermTermsWsAfterFirst(MA_TermTerms arg) */

MA_Layout MA_getTermTermsWsAfterFirst(MA_TermTerms arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  MA_TermTerms MA_setTermTermsWsAfterFirst(MA_TermTerms arg, MA_Layout wsAfterFirst) */

MA_TermTerms MA_setTermTermsWsAfterFirst(MA_TermTerms arg, MA_Layout wsAfterFirst)
{
  if (MA_isTermTermsMany(arg)) {
    return (MA_TermTerms)ATreplace((ATermList)arg, (ATerm)wsAfterFirst, 1);
  }

  ATabort("TermTerms has no WsAfterFirst: %t\n", arg);
  return (MA_TermTerms)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasTermTermsSep(MA_TermTerms arg) */

ATbool MA_hasTermTermsSep(MA_TermTerms arg)
{
  if (MA_isTermTermsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * MA_getTermTermsSep(MA_TermTerms arg) */

char * MA_getTermTermsSep(MA_TermTerms arg)
{
  
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), 0)));
}

/*}}}  */
/*{{{  MA_TermTerms MA_setTermTermsSep(MA_TermTerms arg, char * sep) */

MA_TermTerms MA_setTermTermsSep(MA_TermTerms arg, char * sep)
{
  if (MA_isTermTermsMany(arg)) {
    return (MA_TermTerms)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)), 0), 2);
  }

  ATabort("TermTerms has no Sep: %t\n", arg);
  return (MA_TermTerms)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasTermTermsWsAfterSep(MA_TermTerms arg) */

ATbool MA_hasTermTermsWsAfterSep(MA_TermTerms arg)
{
  if (MA_isTermTermsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getTermTermsWsAfterSep(MA_TermTerms arg) */

MA_Layout MA_getTermTermsWsAfterSep(MA_TermTerms arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  MA_TermTerms MA_setTermTermsWsAfterSep(MA_TermTerms arg, MA_Layout wsAfterSep) */

MA_TermTerms MA_setTermTermsWsAfterSep(MA_TermTerms arg, MA_Layout wsAfterSep)
{
  if (MA_isTermTermsMany(arg)) {
    return (MA_TermTerms)ATreplace((ATermList)arg, (ATerm)wsAfterSep, 3);
  }

  ATabort("TermTerms has no WsAfterSep: %t\n", arg);
  return (MA_TermTerms)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasTermTermsTail(MA_TermTerms arg) */

ATbool MA_hasTermTermsTail(MA_TermTerms arg)
{
  if (MA_isTermTermsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_TermTerms MA_getTermTermsTail(MA_TermTerms arg) */

MA_TermTerms MA_getTermTermsTail(MA_TermTerms arg)
{
  
    return (MA_TermTerms)ATgetTail((ATermList)arg, 4);
}

/*}}}  */
/*{{{  MA_TermTerms MA_setTermTermsTail(MA_TermTerms arg, MA_TermTerms tail) */

MA_TermTerms MA_setTermTermsTail(MA_TermTerms arg, MA_TermTerms tail)
{
  if (MA_isTermTermsMany(arg)) {
    return (MA_TermTerms)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("TermTerms has no Tail: %t\n", arg);
  return (MA_TermTerms)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_SigArgList accessors */

/*{{{  ATbool MA_isValidSigArgList(MA_SigArgList arg) */

ATbool MA_isValidSigArgList(MA_SigArgList arg)
{
  if (MA_isSigArgListDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isSigArgListDefault(MA_SigArgList arg) */

inline ATbool MA_isSigArgListDefault(MA_SigArgList arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MA_patternSigArgListDefault, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool MA_hasSigArgListElems(MA_SigArgList arg) */

ATbool MA_hasSigArgListElems(MA_SigArgList arg)
{
  if (MA_isSigArgListDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_SigArgElems MA_getSigArgListElems(MA_SigArgList arg) */

MA_SigArgElems MA_getSigArgListElems(MA_SigArgList arg)
{
  
    return (MA_SigArgElems)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  MA_SigArgList MA_setSigArgListElems(MA_SigArgList arg, MA_SigArgElems elems) */

MA_SigArgList MA_setSigArgListElems(MA_SigArgList arg, MA_SigArgElems elems)
{
  if (MA_isSigArgListDefault(arg)) {
    return (MA_SigArgList)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)elems, 1), 0), 1);
  }

  ATabort("SigArgList has no Elems: %t\n", arg);
  return (MA_SigArgList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_FuncDefList accessors */

/*{{{  ATbool MA_isValidFuncDefList(MA_FuncDefList arg) */

ATbool MA_isValidFuncDefList(MA_FuncDefList arg)
{
  if (MA_isFuncDefListDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isFuncDefListDefault(MA_FuncDefList arg) */

inline ATbool MA_isFuncDefListDefault(MA_FuncDefList arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MA_patternFuncDefListDefault, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool MA_hasFuncDefListElems(MA_FuncDefList arg) */

ATbool MA_hasFuncDefListElems(MA_FuncDefList arg)
{
  if (MA_isFuncDefListDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_FuncDefElems MA_getFuncDefListElems(MA_FuncDefList arg) */

MA_FuncDefElems MA_getFuncDefListElems(MA_FuncDefList arg)
{
  
    return (MA_FuncDefElems)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  MA_FuncDefList MA_setFuncDefListElems(MA_FuncDefList arg, MA_FuncDefElems elems) */

MA_FuncDefList MA_setFuncDefListElems(MA_FuncDefList arg, MA_FuncDefElems elems)
{
  if (MA_isFuncDefListDefault(arg)) {
    return (MA_FuncDefList)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)elems, 1), 0), 1);
  }

  ATabort("FuncDefList has no Elems: %t\n", arg);
  return (MA_FuncDefList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_FuncDefElems accessors */

/*{{{  ATbool MA_isValidFuncDefElems(MA_FuncDefElems arg) */

ATbool MA_isValidFuncDefElems(MA_FuncDefElems arg)
{
  if (MA_isFuncDefElemsEmpty(arg)) {
    return ATtrue;
  }
  else if (MA_isFuncDefElemsSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isFuncDefElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isFuncDefElemsEmpty(MA_FuncDefElems arg) */

inline ATbool MA_isFuncDefElemsEmpty(MA_FuncDefElems arg)
{
  return ATmatchTerm((ATerm)arg, MA_patternFuncDefElemsEmpty);
}

/*}}}  */
/*{{{  inline ATbool MA_isFuncDefElemsSingle(MA_FuncDefElems arg) */

inline ATbool MA_isFuncDefElemsSingle(MA_FuncDefElems arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternFuncDefElemsSingle, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isFuncDefElemsMany(MA_FuncDefElems arg) */

inline ATbool MA_isFuncDefElemsMany(MA_FuncDefElems arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternFuncDefElemsMany, NULL, NULL, NULL, NULL, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MA_hasFuncDefElemsHead(MA_FuncDefElems arg) */

ATbool MA_hasFuncDefElemsHead(MA_FuncDefElems arg)
{
  if (MA_isFuncDefElemsSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isFuncDefElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_FuncDef MA_getFuncDefElemsHead(MA_FuncDefElems arg) */

MA_FuncDef MA_getFuncDefElemsHead(MA_FuncDefElems arg)
{
  if (MA_isFuncDefElemsSingle(arg)) {
    return (MA_FuncDef)ATgetFirst((ATermList)arg);
  }
  else 
    return (MA_FuncDef)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  MA_FuncDefElems MA_setFuncDefElemsHead(MA_FuncDefElems arg, MA_FuncDef head) */

MA_FuncDefElems MA_setFuncDefElemsHead(MA_FuncDefElems arg, MA_FuncDef head)
{
  if (MA_isFuncDefElemsSingle(arg)) {
    return (MA_FuncDefElems)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (MA_isFuncDefElemsMany(arg)) {
    return (MA_FuncDefElems)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("FuncDefElems has no Head: %t\n", arg);
  return (MA_FuncDefElems)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasFuncDefElemsWsAfterFirst(MA_FuncDefElems arg) */

ATbool MA_hasFuncDefElemsWsAfterFirst(MA_FuncDefElems arg)
{
  if (MA_isFuncDefElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getFuncDefElemsWsAfterFirst(MA_FuncDefElems arg) */

MA_Layout MA_getFuncDefElemsWsAfterFirst(MA_FuncDefElems arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  MA_FuncDefElems MA_setFuncDefElemsWsAfterFirst(MA_FuncDefElems arg, MA_Layout wsAfterFirst) */

MA_FuncDefElems MA_setFuncDefElemsWsAfterFirst(MA_FuncDefElems arg, MA_Layout wsAfterFirst)
{
  if (MA_isFuncDefElemsMany(arg)) {
    return (MA_FuncDefElems)ATreplace((ATermList)arg, (ATerm)wsAfterFirst, 1);
  }

  ATabort("FuncDefElems has no WsAfterFirst: %t\n", arg);
  return (MA_FuncDefElems)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasFuncDefElemsSep(MA_FuncDefElems arg) */

ATbool MA_hasFuncDefElemsSep(MA_FuncDefElems arg)
{
  if (MA_isFuncDefElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * MA_getFuncDefElemsSep(MA_FuncDefElems arg) */

char * MA_getFuncDefElemsSep(MA_FuncDefElems arg)
{
  
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), 0)));
}

/*}}}  */
/*{{{  MA_FuncDefElems MA_setFuncDefElemsSep(MA_FuncDefElems arg, char * sep) */

MA_FuncDefElems MA_setFuncDefElemsSep(MA_FuncDefElems arg, char * sep)
{
  if (MA_isFuncDefElemsMany(arg)) {
    return (MA_FuncDefElems)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)), 0), 2);
  }

  ATabort("FuncDefElems has no Sep: %t\n", arg);
  return (MA_FuncDefElems)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasFuncDefElemsWsAfterSep(MA_FuncDefElems arg) */

ATbool MA_hasFuncDefElemsWsAfterSep(MA_FuncDefElems arg)
{
  if (MA_isFuncDefElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getFuncDefElemsWsAfterSep(MA_FuncDefElems arg) */

MA_Layout MA_getFuncDefElemsWsAfterSep(MA_FuncDefElems arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  MA_FuncDefElems MA_setFuncDefElemsWsAfterSep(MA_FuncDefElems arg, MA_Layout wsAfterSep) */

MA_FuncDefElems MA_setFuncDefElemsWsAfterSep(MA_FuncDefElems arg, MA_Layout wsAfterSep)
{
  if (MA_isFuncDefElemsMany(arg)) {
    return (MA_FuncDefElems)ATreplace((ATermList)arg, (ATerm)wsAfterSep, 3);
  }

  ATabort("FuncDefElems has no WsAfterSep: %t\n", arg);
  return (MA_FuncDefElems)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasFuncDefElemsTail(MA_FuncDefElems arg) */

ATbool MA_hasFuncDefElemsTail(MA_FuncDefElems arg)
{
  if (MA_isFuncDefElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_FuncDefElems MA_getFuncDefElemsTail(MA_FuncDefElems arg) */

MA_FuncDefElems MA_getFuncDefElemsTail(MA_FuncDefElems arg)
{
  
    return (MA_FuncDefElems)ATgetTail((ATermList)arg, 4);
}

/*}}}  */
/*{{{  MA_FuncDefElems MA_setFuncDefElemsTail(MA_FuncDefElems arg, MA_FuncDefElems tail) */

MA_FuncDefElems MA_setFuncDefElemsTail(MA_FuncDefElems arg, MA_FuncDefElems tail)
{
  if (MA_isFuncDefElemsMany(arg)) {
    return (MA_FuncDefElems)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("FuncDefElems has no Tail: %t\n", arg);
  return (MA_FuncDefElems)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_Rule accessors */

/*{{{  ATbool MA_isValidRule(MA_Rule arg) */

ATbool MA_isValidRule(MA_Rule arg)
{
  if (MA_isRuleNoConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleDefaultNoConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleDefaultWithConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleWithConds(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isRuleNoConds(MA_Rule arg) */

inline ATbool MA_isRuleNoConds(MA_Rule arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternRuleNoConds, NULL, NULL, NULL, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isRuleDefaultNoConds(MA_Rule arg) */

inline ATbool MA_isRuleDefaultNoConds(MA_Rule arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternRuleDefaultNoConds, NULL, NULL, NULL, NULL, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isRuleDefaultWithConds(MA_Rule arg) */

inline ATbool MA_isRuleDefaultWithConds(MA_Rule arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternRuleDefaultWithConds, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isRuleWithConds(MA_Rule arg) */

inline ATbool MA_isRuleWithConds(MA_Rule arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternRuleWithConds, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MA_hasRuleLhs(MA_Rule arg) */

ATbool MA_hasRuleLhs(MA_Rule arg)
{
  if (MA_isRuleNoConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleDefaultNoConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleDefaultWithConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleWithConds(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Term MA_getRuleLhs(MA_Rule arg) */

MA_Term MA_getRuleLhs(MA_Rule arg)
{
  if (MA_isRuleNoConds(arg)) {
    return (MA_Term)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (MA_isRuleDefaultNoConds(arg)) {
    return (MA_Term)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else if (MA_isRuleDefaultWithConds(arg)) {
    return (MA_Term)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6);
  }
  else 
    return (MA_Term)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  MA_Rule MA_setRuleLhs(MA_Rule arg, MA_Term lhs) */

MA_Rule MA_setRuleLhs(MA_Rule arg, MA_Term lhs)
{
  if (MA_isRuleNoConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)lhs, 0), 1);
  }
  else if (MA_isRuleDefaultNoConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)lhs, 2), 1);
  }
  else if (MA_isRuleDefaultWithConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)lhs, 6), 1);
  }
  else if (MA_isRuleWithConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)lhs, 4), 1);
  }

  ATabort("Rule has no Lhs: %t\n", arg);
  return (MA_Rule)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasRuleWsAfterLhs(MA_Rule arg) */

ATbool MA_hasRuleWsAfterLhs(MA_Rule arg)
{
  if (MA_isRuleNoConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleDefaultNoConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleDefaultWithConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleWithConds(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getRuleWsAfterLhs(MA_Rule arg) */

MA_Layout MA_getRuleWsAfterLhs(MA_Rule arg)
{
  if (MA_isRuleNoConds(arg)) {
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else if (MA_isRuleDefaultNoConds(arg)) {
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (MA_isRuleDefaultWithConds(arg)) {
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else 
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  MA_Rule MA_setRuleWsAfterLhs(MA_Rule arg, MA_Layout wsAfterLhs) */

MA_Rule MA_setRuleWsAfterLhs(MA_Rule arg, MA_Layout wsAfterLhs)
{
  if (MA_isRuleNoConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLhs, 1), 1);
  }
  else if (MA_isRuleDefaultNoConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLhs, 3), 1);
  }
  else if (MA_isRuleDefaultWithConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLhs, 7), 1);
  }
  else if (MA_isRuleWithConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLhs, 5), 1);
  }

  ATabort("Rule has no WsAfterLhs: %t\n", arg);
  return (MA_Rule)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasRuleWsAfterEquals(MA_Rule arg) */

ATbool MA_hasRuleWsAfterEquals(MA_Rule arg)
{
  if (MA_isRuleNoConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleDefaultNoConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleDefaultWithConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleWithConds(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getRuleWsAfterEquals(MA_Rule arg) */

MA_Layout MA_getRuleWsAfterEquals(MA_Rule arg)
{
  if (MA_isRuleNoConds(arg)) {
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (MA_isRuleDefaultNoConds(arg)) {
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else if (MA_isRuleDefaultWithConds(arg)) {
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
  }
  else 
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  MA_Rule MA_setRuleWsAfterEquals(MA_Rule arg, MA_Layout wsAfterEquals) */

MA_Rule MA_setRuleWsAfterEquals(MA_Rule arg, MA_Layout wsAfterEquals)
{
  if (MA_isRuleNoConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterEquals, 3), 1);
  }
  else if (MA_isRuleDefaultNoConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterEquals, 5), 1);
  }
  else if (MA_isRuleDefaultWithConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterEquals, 9), 1);
  }
  else if (MA_isRuleWithConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterEquals, 7), 1);
  }

  ATabort("Rule has no WsAfterEquals: %t\n", arg);
  return (MA_Rule)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasRuleRhs(MA_Rule arg) */

ATbool MA_hasRuleRhs(MA_Rule arg)
{
  if (MA_isRuleNoConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleDefaultNoConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleDefaultWithConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleWithConds(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Term MA_getRuleRhs(MA_Rule arg) */

MA_Term MA_getRuleRhs(MA_Rule arg)
{
  if (MA_isRuleNoConds(arg)) {
    return (MA_Term)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else if (MA_isRuleDefaultNoConds(arg)) {
    return (MA_Term)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6);
  }
  else if (MA_isRuleDefaultWithConds(arg)) {
    return (MA_Term)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 10);
  }
  else 
    return (MA_Term)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/*}}}  */
/*{{{  MA_Rule MA_setRuleRhs(MA_Rule arg, MA_Term rhs) */

MA_Rule MA_setRuleRhs(MA_Rule arg, MA_Term rhs)
{
  if (MA_isRuleNoConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)rhs, 4), 1);
  }
  else if (MA_isRuleDefaultNoConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)rhs, 6), 1);
  }
  else if (MA_isRuleDefaultWithConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)rhs, 10), 1);
  }
  else if (MA_isRuleWithConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)rhs, 8), 1);
  }

  ATabort("Rule has no Rhs: %t\n", arg);
  return (MA_Rule)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasRuleWsAfterDefaultColon(MA_Rule arg) */

ATbool MA_hasRuleWsAfterDefaultColon(MA_Rule arg)
{
  if (MA_isRuleDefaultNoConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleDefaultWithConds(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getRuleWsAfterDefaultColon(MA_Rule arg) */

MA_Layout MA_getRuleWsAfterDefaultColon(MA_Rule arg)
{
  if (MA_isRuleDefaultNoConds(arg)) {
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else 
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_Rule MA_setRuleWsAfterDefaultColon(MA_Rule arg, MA_Layout wsAfterDefaultColon) */

MA_Rule MA_setRuleWsAfterDefaultColon(MA_Rule arg, MA_Layout wsAfterDefaultColon)
{
  if (MA_isRuleDefaultNoConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterDefaultColon, 1), 1);
  }
  else if (MA_isRuleDefaultWithConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterDefaultColon, 1), 1);
  }

  ATabort("Rule has no WsAfterDefaultColon: %t\n", arg);
  return (MA_Rule)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasRuleConds(MA_Rule arg) */

ATbool MA_hasRuleConds(MA_Rule arg)
{
  if (MA_isRuleDefaultWithConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleWithConds(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_CondList MA_getRuleConds(MA_Rule arg) */

MA_CondList MA_getRuleConds(MA_Rule arg)
{
  if (MA_isRuleDefaultWithConds(arg)) {
    return (MA_CondList)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else 
    return (MA_CondList)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  MA_Rule MA_setRuleConds(MA_Rule arg, MA_CondList conds) */

MA_Rule MA_setRuleConds(MA_Rule arg, MA_CondList conds)
{
  if (MA_isRuleDefaultWithConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)conds, 2), 1);
  }
  else if (MA_isRuleWithConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)conds, 0), 1);
  }

  ATabort("Rule has no Conds: %t\n", arg);
  return (MA_Rule)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasRuleWsAfterConds(MA_Rule arg) */

ATbool MA_hasRuleWsAfterConds(MA_Rule arg)
{
  if (MA_isRuleDefaultWithConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleWithConds(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getRuleWsAfterConds(MA_Rule arg) */

MA_Layout MA_getRuleWsAfterConds(MA_Rule arg)
{
  if (MA_isRuleDefaultWithConds(arg)) {
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_Rule MA_setRuleWsAfterConds(MA_Rule arg, MA_Layout wsAfterConds) */

MA_Rule MA_setRuleWsAfterConds(MA_Rule arg, MA_Layout wsAfterConds)
{
  if (MA_isRuleDefaultWithConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterConds, 3), 1);
  }
  else if (MA_isRuleWithConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterConds, 1), 1);
  }

  ATabort("Rule has no WsAfterConds: %t\n", arg);
  return (MA_Rule)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasRuleWsAfterImplies(MA_Rule arg) */

ATbool MA_hasRuleWsAfterImplies(MA_Rule arg)
{
  if (MA_isRuleDefaultWithConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleWithConds(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getRuleWsAfterImplies(MA_Rule arg) */

MA_Layout MA_getRuleWsAfterImplies(MA_Rule arg)
{
  if (MA_isRuleDefaultWithConds(arg)) {
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else 
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  MA_Rule MA_setRuleWsAfterImplies(MA_Rule arg, MA_Layout wsAfterImplies) */

MA_Rule MA_setRuleWsAfterImplies(MA_Rule arg, MA_Layout wsAfterImplies)
{
  if (MA_isRuleDefaultWithConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterImplies, 5), 1);
  }
  else if (MA_isRuleWithConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterImplies, 3), 1);
  }

  ATabort("Rule has no WsAfterImplies: %t\n", arg);
  return (MA_Rule)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_RuleList accessors */

/*{{{  ATbool MA_isValidRuleList(MA_RuleList arg) */

ATbool MA_isValidRuleList(MA_RuleList arg)
{
  if (MA_isRuleListDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isRuleListDefault(MA_RuleList arg) */

inline ATbool MA_isRuleListDefault(MA_RuleList arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MA_patternRuleListDefault, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool MA_hasRuleListElems(MA_RuleList arg) */

ATbool MA_hasRuleListElems(MA_RuleList arg)
{
  if (MA_isRuleListDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_RuleElems MA_getRuleListElems(MA_RuleList arg) */

MA_RuleElems MA_getRuleListElems(MA_RuleList arg)
{
  
    return (MA_RuleElems)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  MA_RuleList MA_setRuleListElems(MA_RuleList arg, MA_RuleElems elems) */

MA_RuleList MA_setRuleListElems(MA_RuleList arg, MA_RuleElems elems)
{
  if (MA_isRuleListDefault(arg)) {
    return (MA_RuleList)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)elems, 1), 0), 1);
  }

  ATabort("RuleList has no Elems: %t\n", arg);
  return (MA_RuleList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_RuleElems accessors */

/*{{{  ATbool MA_isValidRuleElems(MA_RuleElems arg) */

ATbool MA_isValidRuleElems(MA_RuleElems arg)
{
  if (MA_isRuleElemsEmpty(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleElemsSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isRuleElemsEmpty(MA_RuleElems arg) */

inline ATbool MA_isRuleElemsEmpty(MA_RuleElems arg)
{
  return ATmatchTerm((ATerm)arg, MA_patternRuleElemsEmpty);
}

/*}}}  */
/*{{{  inline ATbool MA_isRuleElemsSingle(MA_RuleElems arg) */

inline ATbool MA_isRuleElemsSingle(MA_RuleElems arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternRuleElemsSingle, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isRuleElemsMany(MA_RuleElems arg) */

inline ATbool MA_isRuleElemsMany(MA_RuleElems arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternRuleElemsMany, NULL, NULL, NULL, NULL, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MA_hasRuleElemsHead(MA_RuleElems arg) */

ATbool MA_hasRuleElemsHead(MA_RuleElems arg)
{
  if (MA_isRuleElemsSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Rule MA_getRuleElemsHead(MA_RuleElems arg) */

MA_Rule MA_getRuleElemsHead(MA_RuleElems arg)
{
  if (MA_isRuleElemsSingle(arg)) {
    return (MA_Rule)ATgetFirst((ATermList)arg);
  }
  else 
    return (MA_Rule)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  MA_RuleElems MA_setRuleElemsHead(MA_RuleElems arg, MA_Rule head) */

MA_RuleElems MA_setRuleElemsHead(MA_RuleElems arg, MA_Rule head)
{
  if (MA_isRuleElemsSingle(arg)) {
    return (MA_RuleElems)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (MA_isRuleElemsMany(arg)) {
    return (MA_RuleElems)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("RuleElems has no Head: %t\n", arg);
  return (MA_RuleElems)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasRuleElemsWsAfterFirst(MA_RuleElems arg) */

ATbool MA_hasRuleElemsWsAfterFirst(MA_RuleElems arg)
{
  if (MA_isRuleElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getRuleElemsWsAfterFirst(MA_RuleElems arg) */

MA_Layout MA_getRuleElemsWsAfterFirst(MA_RuleElems arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  MA_RuleElems MA_setRuleElemsWsAfterFirst(MA_RuleElems arg, MA_Layout wsAfterFirst) */

MA_RuleElems MA_setRuleElemsWsAfterFirst(MA_RuleElems arg, MA_Layout wsAfterFirst)
{
  if (MA_isRuleElemsMany(arg)) {
    return (MA_RuleElems)ATreplace((ATermList)arg, (ATerm)wsAfterFirst, 1);
  }

  ATabort("RuleElems has no WsAfterFirst: %t\n", arg);
  return (MA_RuleElems)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasRuleElemsSep(MA_RuleElems arg) */

ATbool MA_hasRuleElemsSep(MA_RuleElems arg)
{
  if (MA_isRuleElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * MA_getRuleElemsSep(MA_RuleElems arg) */

char * MA_getRuleElemsSep(MA_RuleElems arg)
{
  
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), 0)));
}

/*}}}  */
/*{{{  MA_RuleElems MA_setRuleElemsSep(MA_RuleElems arg, char * sep) */

MA_RuleElems MA_setRuleElemsSep(MA_RuleElems arg, char * sep)
{
  if (MA_isRuleElemsMany(arg)) {
    return (MA_RuleElems)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)), 0), 2);
  }

  ATabort("RuleElems has no Sep: %t\n", arg);
  return (MA_RuleElems)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasRuleElemsWsAfterSep(MA_RuleElems arg) */

ATbool MA_hasRuleElemsWsAfterSep(MA_RuleElems arg)
{
  if (MA_isRuleElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getRuleElemsWsAfterSep(MA_RuleElems arg) */

MA_Layout MA_getRuleElemsWsAfterSep(MA_RuleElems arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  MA_RuleElems MA_setRuleElemsWsAfterSep(MA_RuleElems arg, MA_Layout wsAfterSep) */

MA_RuleElems MA_setRuleElemsWsAfterSep(MA_RuleElems arg, MA_Layout wsAfterSep)
{
  if (MA_isRuleElemsMany(arg)) {
    return (MA_RuleElems)ATreplace((ATermList)arg, (ATerm)wsAfterSep, 3);
  }

  ATabort("RuleElems has no WsAfterSep: %t\n", arg);
  return (MA_RuleElems)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasRuleElemsTail(MA_RuleElems arg) */

ATbool MA_hasRuleElemsTail(MA_RuleElems arg)
{
  if (MA_isRuleElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_RuleElems MA_getRuleElemsTail(MA_RuleElems arg) */

MA_RuleElems MA_getRuleElemsTail(MA_RuleElems arg)
{
  
    return (MA_RuleElems)ATgetTail((ATermList)arg, 4);
}

/*}}}  */
/*{{{  MA_RuleElems MA_setRuleElemsTail(MA_RuleElems arg, MA_RuleElems tail) */

MA_RuleElems MA_setRuleElemsTail(MA_RuleElems arg, MA_RuleElems tail)
{
  if (MA_isRuleElemsMany(arg)) {
    return (MA_RuleElems)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("RuleElems has no Tail: %t\n", arg);
  return (MA_RuleElems)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_CondList accessors */

/*{{{  ATbool MA_isValidCondList(MA_CondList arg) */

ATbool MA_isValidCondList(MA_CondList arg)
{
  if (MA_isCondListDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isCondListDefault(MA_CondList arg) */

inline ATbool MA_isCondListDefault(MA_CondList arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MA_patternCondListDefault, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool MA_hasCondListElems(MA_CondList arg) */

ATbool MA_hasCondListElems(MA_CondList arg)
{
  if (MA_isCondListDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_CondElems MA_getCondListElems(MA_CondList arg) */

MA_CondElems MA_getCondListElems(MA_CondList arg)
{
  
    return (MA_CondElems)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  MA_CondList MA_setCondListElems(MA_CondList arg, MA_CondElems elems) */

MA_CondList MA_setCondListElems(MA_CondList arg, MA_CondElems elems)
{
  if (MA_isCondListDefault(arg)) {
    return (MA_CondList)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)elems, 1), 0), 1);
  }

  ATabort("CondList has no Elems: %t\n", arg);
  return (MA_CondList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_CondElems accessors */

/*{{{  ATbool MA_isValidCondElems(MA_CondElems arg) */

ATbool MA_isValidCondElems(MA_CondElems arg)
{
  if (MA_isCondElemsEmpty(arg)) {
    return ATtrue;
  }
  else if (MA_isCondElemsSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isCondElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isCondElemsEmpty(MA_CondElems arg) */

inline ATbool MA_isCondElemsEmpty(MA_CondElems arg)
{
  return ATmatchTerm((ATerm)arg, MA_patternCondElemsEmpty);
}

/*}}}  */
/*{{{  inline ATbool MA_isCondElemsSingle(MA_CondElems arg) */

inline ATbool MA_isCondElemsSingle(MA_CondElems arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternCondElemsSingle, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isCondElemsMany(MA_CondElems arg) */

inline ATbool MA_isCondElemsMany(MA_CondElems arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternCondElemsMany, NULL, NULL, NULL, NULL, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MA_hasCondElemsHead(MA_CondElems arg) */

ATbool MA_hasCondElemsHead(MA_CondElems arg)
{
  if (MA_isCondElemsSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isCondElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Cond MA_getCondElemsHead(MA_CondElems arg) */

MA_Cond MA_getCondElemsHead(MA_CondElems arg)
{
  if (MA_isCondElemsSingle(arg)) {
    return (MA_Cond)ATgetFirst((ATermList)arg);
  }
  else 
    return (MA_Cond)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  MA_CondElems MA_setCondElemsHead(MA_CondElems arg, MA_Cond head) */

MA_CondElems MA_setCondElemsHead(MA_CondElems arg, MA_Cond head)
{
  if (MA_isCondElemsSingle(arg)) {
    return (MA_CondElems)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (MA_isCondElemsMany(arg)) {
    return (MA_CondElems)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("CondElems has no Head: %t\n", arg);
  return (MA_CondElems)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasCondElemsWsAfterFirst(MA_CondElems arg) */

ATbool MA_hasCondElemsWsAfterFirst(MA_CondElems arg)
{
  if (MA_isCondElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getCondElemsWsAfterFirst(MA_CondElems arg) */

MA_Layout MA_getCondElemsWsAfterFirst(MA_CondElems arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  MA_CondElems MA_setCondElemsWsAfterFirst(MA_CondElems arg, MA_Layout wsAfterFirst) */

MA_CondElems MA_setCondElemsWsAfterFirst(MA_CondElems arg, MA_Layout wsAfterFirst)
{
  if (MA_isCondElemsMany(arg)) {
    return (MA_CondElems)ATreplace((ATermList)arg, (ATerm)wsAfterFirst, 1);
  }

  ATabort("CondElems has no WsAfterFirst: %t\n", arg);
  return (MA_CondElems)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasCondElemsSep(MA_CondElems arg) */

ATbool MA_hasCondElemsSep(MA_CondElems arg)
{
  if (MA_isCondElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * MA_getCondElemsSep(MA_CondElems arg) */

char * MA_getCondElemsSep(MA_CondElems arg)
{
  
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), 0)));
}

/*}}}  */
/*{{{  MA_CondElems MA_setCondElemsSep(MA_CondElems arg, char * sep) */

MA_CondElems MA_setCondElemsSep(MA_CondElems arg, char * sep)
{
  if (MA_isCondElemsMany(arg)) {
    return (MA_CondElems)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)), 0), 2);
  }

  ATabort("CondElems has no Sep: %t\n", arg);
  return (MA_CondElems)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasCondElemsWsAfterSep(MA_CondElems arg) */

ATbool MA_hasCondElemsWsAfterSep(MA_CondElems arg)
{
  if (MA_isCondElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getCondElemsWsAfterSep(MA_CondElems arg) */

MA_Layout MA_getCondElemsWsAfterSep(MA_CondElems arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  MA_CondElems MA_setCondElemsWsAfterSep(MA_CondElems arg, MA_Layout wsAfterSep) */

MA_CondElems MA_setCondElemsWsAfterSep(MA_CondElems arg, MA_Layout wsAfterSep)
{
  if (MA_isCondElemsMany(arg)) {
    return (MA_CondElems)ATreplace((ATermList)arg, (ATerm)wsAfterSep, 3);
  }

  ATabort("CondElems has no WsAfterSep: %t\n", arg);
  return (MA_CondElems)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasCondElemsTail(MA_CondElems arg) */

ATbool MA_hasCondElemsTail(MA_CondElems arg)
{
  if (MA_isCondElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_CondElems MA_getCondElemsTail(MA_CondElems arg) */

MA_CondElems MA_getCondElemsTail(MA_CondElems arg)
{
  
    return (MA_CondElems)ATgetTail((ATermList)arg, 4);
}

/*}}}  */
/*{{{  MA_CondElems MA_setCondElemsTail(MA_CondElems arg, MA_CondElems tail) */

MA_CondElems MA_setCondElemsTail(MA_CondElems arg, MA_CondElems tail)
{
  if (MA_isCondElemsMany(arg)) {
    return (MA_CondElems)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("CondElems has no Tail: %t\n", arg);
  return (MA_CondElems)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_Cond accessors */

/*{{{  ATbool MA_isValidCond(MA_Cond arg) */

ATbool MA_isValidCond(MA_Cond arg)
{
  if (MA_isCondAssign(arg)) {
    return ATtrue;
  }
  else if (MA_isCondEqual(arg)) {
    return ATtrue;
  }
  else if (MA_isCondUnequal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isCondAssign(MA_Cond arg) */

inline ATbool MA_isCondAssign(MA_Cond arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternCondAssign, NULL, NULL, NULL, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isCondEqual(MA_Cond arg) */

inline ATbool MA_isCondEqual(MA_Cond arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternCondEqual, NULL, NULL, NULL, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isCondUnequal(MA_Cond arg) */

inline ATbool MA_isCondUnequal(MA_Cond arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternCondUnequal, NULL, NULL, NULL, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MA_hasCondLhs(MA_Cond arg) */

ATbool MA_hasCondLhs(MA_Cond arg)
{
  if (MA_isCondAssign(arg)) {
    return ATtrue;
  }
  else if (MA_isCondEqual(arg)) {
    return ATtrue;
  }
  else if (MA_isCondUnequal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Term MA_getCondLhs(MA_Cond arg) */

MA_Term MA_getCondLhs(MA_Cond arg)
{
  if (MA_isCondAssign(arg)) {
    return (MA_Term)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (MA_isCondEqual(arg)) {
    return (MA_Term)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (MA_Term)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  MA_Cond MA_setCondLhs(MA_Cond arg, MA_Term lhs) */

MA_Cond MA_setCondLhs(MA_Cond arg, MA_Term lhs)
{
  if (MA_isCondAssign(arg)) {
    return (MA_Cond)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)lhs, 0), 1);
  }
  else if (MA_isCondEqual(arg)) {
    return (MA_Cond)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)lhs, 0), 1);
  }
  else if (MA_isCondUnequal(arg)) {
    return (MA_Cond)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)lhs, 0), 1);
  }

  ATabort("Cond has no Lhs: %t\n", arg);
  return (MA_Cond)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasCondWsAfterLhs(MA_Cond arg) */

ATbool MA_hasCondWsAfterLhs(MA_Cond arg)
{
  if (MA_isCondAssign(arg)) {
    return ATtrue;
  }
  else if (MA_isCondEqual(arg)) {
    return ATtrue;
  }
  else if (MA_isCondUnequal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getCondWsAfterLhs(MA_Cond arg) */

MA_Layout MA_getCondWsAfterLhs(MA_Cond arg)
{
  if (MA_isCondAssign(arg)) {
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else if (MA_isCondEqual(arg)) {
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else 
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_Cond MA_setCondWsAfterLhs(MA_Cond arg, MA_Layout wsAfterLhs) */

MA_Cond MA_setCondWsAfterLhs(MA_Cond arg, MA_Layout wsAfterLhs)
{
  if (MA_isCondAssign(arg)) {
    return (MA_Cond)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLhs, 1), 1);
  }
  else if (MA_isCondEqual(arg)) {
    return (MA_Cond)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLhs, 1), 1);
  }
  else if (MA_isCondUnequal(arg)) {
    return (MA_Cond)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLhs, 1), 1);
  }

  ATabort("Cond has no WsAfterLhs: %t\n", arg);
  return (MA_Cond)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasCondWsAfterAssign(MA_Cond arg) */

ATbool MA_hasCondWsAfterAssign(MA_Cond arg)
{
  if (MA_isCondAssign(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getCondWsAfterAssign(MA_Cond arg) */

MA_Layout MA_getCondWsAfterAssign(MA_Cond arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  MA_Cond MA_setCondWsAfterAssign(MA_Cond arg, MA_Layout wsAfterAssign) */

MA_Cond MA_setCondWsAfterAssign(MA_Cond arg, MA_Layout wsAfterAssign)
{
  if (MA_isCondAssign(arg)) {
    return (MA_Cond)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterAssign, 3), 1);
  }

  ATabort("Cond has no WsAfterAssign: %t\n", arg);
  return (MA_Cond)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasCondRhs(MA_Cond arg) */

ATbool MA_hasCondRhs(MA_Cond arg)
{
  if (MA_isCondAssign(arg)) {
    return ATtrue;
  }
  else if (MA_isCondEqual(arg)) {
    return ATtrue;
  }
  else if (MA_isCondUnequal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Term MA_getCondRhs(MA_Cond arg) */

MA_Term MA_getCondRhs(MA_Cond arg)
{
  if (MA_isCondAssign(arg)) {
    return (MA_Term)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else if (MA_isCondEqual(arg)) {
    return (MA_Term)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (MA_Term)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  MA_Cond MA_setCondRhs(MA_Cond arg, MA_Term rhs) */

MA_Cond MA_setCondRhs(MA_Cond arg, MA_Term rhs)
{
  if (MA_isCondAssign(arg)) {
    return (MA_Cond)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)rhs, 4), 1);
  }
  else if (MA_isCondEqual(arg)) {
    return (MA_Cond)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)rhs, 4), 1);
  }
  else if (MA_isCondUnequal(arg)) {
    return (MA_Cond)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)rhs, 4), 1);
  }

  ATabort("Cond has no Rhs: %t\n", arg);
  return (MA_Cond)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasCondWsAfterEqual(MA_Cond arg) */

ATbool MA_hasCondWsAfterEqual(MA_Cond arg)
{
  if (MA_isCondEqual(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getCondWsAfterEqual(MA_Cond arg) */

MA_Layout MA_getCondWsAfterEqual(MA_Cond arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  MA_Cond MA_setCondWsAfterEqual(MA_Cond arg, MA_Layout wsAfterEqual) */

MA_Cond MA_setCondWsAfterEqual(MA_Cond arg, MA_Layout wsAfterEqual)
{
  if (MA_isCondEqual(arg)) {
    return (MA_Cond)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterEqual, 3), 1);
  }

  ATabort("Cond has no WsAfterEqual: %t\n", arg);
  return (MA_Cond)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasCondWsAfterUnequal(MA_Cond arg) */

ATbool MA_hasCondWsAfterUnequal(MA_Cond arg)
{
  if (MA_isCondUnequal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getCondWsAfterUnequal(MA_Cond arg) */

MA_Layout MA_getCondWsAfterUnequal(MA_Cond arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  MA_Cond MA_setCondWsAfterUnequal(MA_Cond arg, MA_Layout wsAfterUnequal) */

MA_Cond MA_setCondWsAfterUnequal(MA_Cond arg, MA_Layout wsAfterUnequal)
{
  if (MA_isCondUnequal(arg)) {
    return (MA_Cond)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterUnequal, 3), 1);
  }

  ATabort("Cond has no WsAfterUnequal: %t\n", arg);
  return (MA_Cond)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_SignatureOpt accessors */

/*{{{  ATbool MA_isValidSignatureOpt(MA_SignatureOpt arg) */

ATbool MA_isValidSignatureOpt(MA_SignatureOpt arg)
{
  if (MA_isSignatureOptAbsent(arg)) {
    return ATtrue;
  }
  else if (MA_isSignatureOptPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isSignatureOptAbsent(MA_SignatureOpt arg) */

inline ATbool MA_isSignatureOptAbsent(MA_SignatureOpt arg)
{
  return ATmatchTerm((ATerm)arg, MA_patternSignatureOptAbsent);
}

/*}}}  */
/*{{{  inline ATbool MA_isSignatureOptPresent(MA_SignatureOpt arg) */

inline ATbool MA_isSignatureOptPresent(MA_SignatureOpt arg)
{
  return !(ATmatchTerm((ATerm)arg, MA_patternSignatureOptAbsent));
}

/*}}}  */
/*{{{  ATbool MA_hasSignatureOptWsAfterSignature(MA_SignatureOpt arg) */

ATbool MA_hasSignatureOptWsAfterSignature(MA_SignatureOpt arg)
{
  if (MA_isSignatureOptPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getSignatureOptWsAfterSignature(MA_SignatureOpt arg) */

MA_Layout MA_getSignatureOptWsAfterSignature(MA_SignatureOpt arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_SignatureOpt MA_setSignatureOptWsAfterSignature(MA_SignatureOpt arg, MA_Layout wsAfterSignature) */

MA_SignatureOpt MA_setSignatureOptWsAfterSignature(MA_SignatureOpt arg, MA_Layout wsAfterSignature)
{
  if (MA_isSignatureOptPresent(arg)) {
    return (MA_SignatureOpt)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterSignature, 1), 1);
  }

  ATabort("SignatureOpt has no WsAfterSignature: %t\n", arg);
  return (MA_SignatureOpt)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasSignatureOptFuncdefs(MA_SignatureOpt arg) */

ATbool MA_hasSignatureOptFuncdefs(MA_SignatureOpt arg)
{
  if (MA_isSignatureOptPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_FuncDefList MA_getSignatureOptFuncdefs(MA_SignatureOpt arg) */

MA_FuncDefList MA_getSignatureOptFuncdefs(MA_SignatureOpt arg)
{
  
    return (MA_FuncDefList)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  MA_SignatureOpt MA_setSignatureOptFuncdefs(MA_SignatureOpt arg, MA_FuncDefList funcdefs) */

MA_SignatureOpt MA_setSignatureOptFuncdefs(MA_SignatureOpt arg, MA_FuncDefList funcdefs)
{
  if (MA_isSignatureOptPresent(arg)) {
    return (MA_SignatureOpt)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)funcdefs, 2), 1);
  }

  ATabort("SignatureOpt has no Funcdefs: %t\n", arg);
  return (MA_SignatureOpt)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_RulesOpt accessors */

/*{{{  ATbool MA_isValidRulesOpt(MA_RulesOpt arg) */

ATbool MA_isValidRulesOpt(MA_RulesOpt arg)
{
  if (MA_isRulesOptAbsent(arg)) {
    return ATtrue;
  }
  else if (MA_isRulesOptPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isRulesOptAbsent(MA_RulesOpt arg) */

inline ATbool MA_isRulesOptAbsent(MA_RulesOpt arg)
{
  return ATmatchTerm((ATerm)arg, MA_patternRulesOptAbsent);
}

/*}}}  */
/*{{{  inline ATbool MA_isRulesOptPresent(MA_RulesOpt arg) */

inline ATbool MA_isRulesOptPresent(MA_RulesOpt arg)
{
  return !(ATmatchTerm((ATerm)arg, MA_patternRulesOptAbsent));
}

/*}}}  */
/*{{{  ATbool MA_hasRulesOptWsAfterRules(MA_RulesOpt arg) */

ATbool MA_hasRulesOptWsAfterRules(MA_RulesOpt arg)
{
  if (MA_isRulesOptPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getRulesOptWsAfterRules(MA_RulesOpt arg) */

MA_Layout MA_getRulesOptWsAfterRules(MA_RulesOpt arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_RulesOpt MA_setRulesOptWsAfterRules(MA_RulesOpt arg, MA_Layout wsAfterRules) */

MA_RulesOpt MA_setRulesOptWsAfterRules(MA_RulesOpt arg, MA_Layout wsAfterRules)
{
  if (MA_isRulesOptPresent(arg)) {
    return (MA_RulesOpt)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterRules, 1), 1);
  }

  ATabort("RulesOpt has no WsAfterRules: %t\n", arg);
  return (MA_RulesOpt)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasRulesOptRules(MA_RulesOpt arg) */

ATbool MA_hasRulesOptRules(MA_RulesOpt arg)
{
  if (MA_isRulesOptPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_RuleList MA_getRulesOptRules(MA_RulesOpt arg) */

MA_RuleList MA_getRulesOptRules(MA_RulesOpt arg)
{
  
    return (MA_RuleList)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  MA_RulesOpt MA_setRulesOptRules(MA_RulesOpt arg, MA_RuleList rules) */

MA_RulesOpt MA_setRulesOptRules(MA_RulesOpt arg, MA_RuleList rules)
{
  if (MA_isRulesOptPresent(arg)) {
    return (MA_RulesOpt)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)rules, 2), 1);
  }

  ATabort("RulesOpt has no Rules: %t\n", arg);
  return (MA_RulesOpt)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_Module accessors */

/*{{{  ATbool MA_isValidModule(MA_Module arg) */

ATbool MA_isValidModule(MA_Module arg)
{
  if (MA_isModuleModule(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isModuleModule(MA_Module arg) */

inline ATbool MA_isModuleModule(MA_Module arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MA_patternModuleModule, NULL, NULL, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool MA_hasModuleWsAfterModule(MA_Module arg) */

ATbool MA_hasModuleWsAfterModule(MA_Module arg)
{
  if (MA_isModuleModule(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getModuleWsAfterModule(MA_Module arg) */

MA_Layout MA_getModuleWsAfterModule(MA_Module arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_Module MA_setModuleWsAfterModule(MA_Module arg, MA_Layout wsAfterModule) */

MA_Module MA_setModuleWsAfterModule(MA_Module arg, MA_Layout wsAfterModule)
{
  if (MA_isModuleModule(arg)) {
    return (MA_Module)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterModule, 1), 1);
  }

  ATabort("Module has no WsAfterModule: %t\n", arg);
  return (MA_Module)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasModuleId(MA_Module arg) */

ATbool MA_hasModuleId(MA_Module arg)
{
  if (MA_isModuleModule(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_ModId MA_getModuleId(MA_Module arg) */

MA_ModId MA_getModuleId(MA_Module arg)
{
  
    return (MA_ModId)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  MA_Module MA_setModuleId(MA_Module arg, MA_ModId id) */

MA_Module MA_setModuleId(MA_Module arg, MA_ModId id)
{
  if (MA_isModuleModule(arg)) {
    return (MA_Module)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)id, 2), 1);
  }

  ATabort("Module has no Id: %t\n", arg);
  return (MA_Module)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasModuleWsAfterId(MA_Module arg) */

ATbool MA_hasModuleWsAfterId(MA_Module arg)
{
  if (MA_isModuleModule(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getModuleWsAfterId(MA_Module arg) */

MA_Layout MA_getModuleWsAfterId(MA_Module arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  MA_Module MA_setModuleWsAfterId(MA_Module arg, MA_Layout wsAfterId) */

MA_Module MA_setModuleWsAfterId(MA_Module arg, MA_Layout wsAfterId)
{
  if (MA_isModuleModule(arg)) {
    return (MA_Module)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterId, 3), 1);
  }

  ATabort("Module has no WsAfterId: %t\n", arg);
  return (MA_Module)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasModuleSignature(MA_Module arg) */

ATbool MA_hasModuleSignature(MA_Module arg)
{
  if (MA_isModuleModule(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_SignatureOpt MA_getModuleSignature(MA_Module arg) */

MA_SignatureOpt MA_getModuleSignature(MA_Module arg)
{
  
    return (MA_SignatureOpt)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  MA_Module MA_setModuleSignature(MA_Module arg, MA_SignatureOpt signature) */

MA_Module MA_setModuleSignature(MA_Module arg, MA_SignatureOpt signature)
{
  if (MA_isModuleModule(arg)) {
    return (MA_Module)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)signature, 4), 1);
  }

  ATabort("Module has no Signature: %t\n", arg);
  return (MA_Module)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasModuleWsAfterSignature(MA_Module arg) */

ATbool MA_hasModuleWsAfterSignature(MA_Module arg)
{
  if (MA_isModuleModule(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getModuleWsAfterSignature(MA_Module arg) */

MA_Layout MA_getModuleWsAfterSignature(MA_Module arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  MA_Module MA_setModuleWsAfterSignature(MA_Module arg, MA_Layout wsAfterSignature) */

MA_Module MA_setModuleWsAfterSignature(MA_Module arg, MA_Layout wsAfterSignature)
{
  if (MA_isModuleModule(arg)) {
    return (MA_Module)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterSignature, 5), 1);
  }

  ATabort("Module has no WsAfterSignature: %t\n", arg);
  return (MA_Module)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasModuleRules(MA_Module arg) */

ATbool MA_hasModuleRules(MA_Module arg)
{
  if (MA_isModuleModule(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_RulesOpt MA_getModuleRules(MA_Module arg) */

MA_RulesOpt MA_getModuleRules(MA_Module arg)
{
  
    return (MA_RulesOpt)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6);
}

/*}}}  */
/*{{{  MA_Module MA_setModuleRules(MA_Module arg, MA_RulesOpt rules) */

MA_Module MA_setModuleRules(MA_Module arg, MA_RulesOpt rules)
{
  if (MA_isModuleModule(arg)) {
    return (MA_Module)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)rules, 6), 1);
  }

  ATabort("Module has no Rules: %t\n", arg);
  return (MA_Module)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_EscChar accessors */

/*{{{  ATbool MA_isValidEscChar(MA_EscChar arg) */

ATbool MA_isValidEscChar(MA_EscChar arg)
{
  if (MA_isEscCharLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isEscCharLexToCf(MA_EscChar arg) */

inline ATbool MA_isEscCharLexToCf(MA_EscChar arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MA_patternEscCharLexToCf, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool MA_hasEscCharLex(MA_EscChar arg) */

ATbool MA_hasEscCharLex(MA_EscChar arg)
{
  if (MA_isEscCharLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Lexical MA_getEscCharLex(MA_EscChar arg) */

MA_Lexical MA_getEscCharLex(MA_EscChar arg)
{
  
    return (MA_Lexical)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  MA_EscChar MA_setEscCharLex(MA_EscChar arg, MA_Lexical lex) */

MA_EscChar MA_setEscCharLex(MA_EscChar arg, MA_Lexical lex)
{
  if (MA_isEscCharLexToCf(arg)) {
    return (MA_EscChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)lex, 0), 1);
  }

  ATabort("EscChar has no Lex: %t\n", arg);
  return (MA_EscChar)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_QChar accessors */

/*{{{  ATbool MA_isValidQChar(MA_QChar arg) */

ATbool MA_isValidQChar(MA_QChar arg)
{
  if (MA_isQCharLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isQCharLexToCf(MA_QChar arg) */

inline ATbool MA_isQCharLexToCf(MA_QChar arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MA_patternQCharLexToCf, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool MA_hasQCharLex(MA_QChar arg) */

ATbool MA_hasQCharLex(MA_QChar arg)
{
  if (MA_isQCharLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Lexical MA_getQCharLex(MA_QChar arg) */

MA_Lexical MA_getQCharLex(MA_QChar arg)
{
  
    return (MA_Lexical)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  MA_QChar MA_setQCharLex(MA_QChar arg, MA_Lexical lex) */

MA_QChar MA_setQCharLex(MA_QChar arg, MA_Lexical lex)
{
  if (MA_isQCharLexToCf(arg)) {
    return (MA_QChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)lex, 0), 1);
  }

  ATabort("QChar has no Lex: %t\n", arg);
  return (MA_QChar)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_FunId accessors */

/*{{{  ATbool MA_isValidFunId(MA_FunId arg) */

ATbool MA_isValidFunId(MA_FunId arg)
{
  if (MA_isFunIdLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isFunIdLexToCf(MA_FunId arg) */

inline ATbool MA_isFunIdLexToCf(MA_FunId arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MA_patternFunIdLexToCf, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool MA_hasFunIdLex(MA_FunId arg) */

ATbool MA_hasFunIdLex(MA_FunId arg)
{
  if (MA_isFunIdLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Lexical MA_getFunIdLex(MA_FunId arg) */

MA_Lexical MA_getFunIdLex(MA_FunId arg)
{
  
    return (MA_Lexical)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  MA_FunId MA_setFunIdLex(MA_FunId arg, MA_Lexical lex) */

MA_FunId MA_setFunIdLex(MA_FunId arg, MA_Lexical lex)
{
  if (MA_isFunIdLexToCf(arg)) {
    return (MA_FunId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)lex, 0), 1);
  }

  ATabort("FunId has no Lex: %t\n", arg);
  return (MA_FunId)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_VarId accessors */

/*{{{  ATbool MA_isValidVarId(MA_VarId arg) */

ATbool MA_isValidVarId(MA_VarId arg)
{
  if (MA_isVarIdLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isVarIdLexToCf(MA_VarId arg) */

inline ATbool MA_isVarIdLexToCf(MA_VarId arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MA_patternVarIdLexToCf, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool MA_hasVarIdLex(MA_VarId arg) */

ATbool MA_hasVarIdLex(MA_VarId arg)
{
  if (MA_isVarIdLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Lexical MA_getVarIdLex(MA_VarId arg) */

MA_Lexical MA_getVarIdLex(MA_VarId arg)
{
  
    return (MA_Lexical)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  MA_VarId MA_setVarIdLex(MA_VarId arg, MA_Lexical lex) */

MA_VarId MA_setVarIdLex(MA_VarId arg, MA_Lexical lex)
{
  if (MA_isVarIdLexToCf(arg)) {
    return (MA_VarId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)lex, 0), 1);
  }

  ATabort("VarId has no Lex: %t\n", arg);
  return (MA_VarId)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_ModId accessors */

/*{{{  ATbool MA_isValidModId(MA_ModId arg) */

ATbool MA_isValidModId(MA_ModId arg)
{
  if (MA_isModIdLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isModIdLexToCf(MA_ModId arg) */

inline ATbool MA_isModIdLexToCf(MA_ModId arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MA_patternModIdLexToCf, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool MA_hasModIdLex(MA_ModId arg) */

ATbool MA_hasModIdLex(MA_ModId arg)
{
  if (MA_isModIdLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Lexical MA_getModIdLex(MA_ModId arg) */

MA_Lexical MA_getModIdLex(MA_ModId arg)
{
  
    return (MA_Lexical)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  MA_ModId MA_setModIdLex(MA_ModId arg, MA_Lexical lex) */

MA_ModId MA_setModIdLex(MA_ModId arg, MA_Lexical lex)
{
  if (MA_isModIdLexToCf(arg)) {
    return (MA_ModId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)lex, 0), 1);
  }

  ATabort("ModId has no Lex: %t\n", arg);
  return (MA_ModId)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_PropId accessors */

/*{{{  ATbool MA_isValidPropId(MA_PropId arg) */

ATbool MA_isValidPropId(MA_PropId arg)
{
  if (MA_isPropIdLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isPropIdLexToCf(MA_PropId arg) */

inline ATbool MA_isPropIdLexToCf(MA_PropId arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MA_patternPropIdLexToCf, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool MA_hasPropIdLex(MA_PropId arg) */

ATbool MA_hasPropIdLex(MA_PropId arg)
{
  if (MA_isPropIdLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Lexical MA_getPropIdLex(MA_PropId arg) */

MA_Lexical MA_getPropIdLex(MA_PropId arg)
{
  
    return (MA_Lexical)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  MA_PropId MA_setPropIdLex(MA_PropId arg, MA_Lexical lex) */

MA_PropId MA_setPropIdLex(MA_PropId arg, MA_Lexical lex)
{
  if (MA_isPropIdLexToCf(arg)) {
    return (MA_PropId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)lex, 0), 1);
  }

  ATabort("PropId has no Lex: %t\n", arg);
  return (MA_PropId)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  MA_Int MA_visitInt(MA_Int arg, MA_IntCon (*acceptIntCon)(MA_IntCon), MA_Layout (*acceptWsAfterLhs)(MA_Layout), MA_Layout (*acceptWsAfterPlus)(MA_Layout)) */

MA_Int MA_visitInt(MA_Int arg, MA_IntCon (*acceptIntCon)(MA_IntCon), MA_Layout (*acceptWsAfterLhs)(MA_Layout), MA_Layout (*acceptWsAfterPlus)(MA_Layout))
{
  if (MA_isIntCon(arg)) {
    return MA_makeIntCon(
        acceptIntCon ? acceptIntCon(MA_getIntIntCon(arg)) : MA_getIntIntCon(arg));
  }
  if (MA_isIntPlus(arg)) {
    return MA_makeIntPlus(
        MA_visitInt(MA_getIntLhs(arg), acceptIntCon, acceptWsAfterLhs, acceptWsAfterPlus),
        acceptWsAfterLhs ? acceptWsAfterLhs(MA_getIntWsAfterLhs(arg)) : MA_getIntWsAfterLhs(arg),
        acceptWsAfterPlus ? acceptWsAfterPlus(MA_getIntWsAfterPlus(arg)) : MA_getIntWsAfterPlus(arg),
        MA_visitInt(MA_getIntRhs(arg), acceptIntCon, acceptWsAfterLhs, acceptWsAfterPlus));
  }
  ATabort("not a Int: %t\n", arg);
  return (MA_Int)NULL;
}

/*}}}  */
/*{{{  MA_IntCon MA_visitIntCon(MA_IntCon arg, MA_Layout (*acceptWsAfterCon)(MA_Layout), MA_Layout (*acceptWsAfterParenOpen)(MA_Layout), MA_Int (*acceptIntArg)(MA_Int), MA_Layout (*acceptWsAfterIntArg)(MA_Layout), MA_NatCon (*acceptNatCon)(MA_NatCon), MA_Layout (*acceptWsAfterPlus)(MA_Layout), MA_NatCon (*acceptNatArg)(MA_NatCon), MA_Layout (*acceptWsAfter)(MA_Layout)) */

MA_IntCon MA_visitIntCon(MA_IntCon arg, MA_Layout (*acceptWsAfterCon)(MA_Layout), MA_Layout (*acceptWsAfterParenOpen)(MA_Layout), MA_Int (*acceptIntArg)(MA_Int), MA_Layout (*acceptWsAfterIntArg)(MA_Layout), MA_NatCon (*acceptNatCon)(MA_NatCon), MA_Layout (*acceptWsAfterPlus)(MA_Layout), MA_NatCon (*acceptNatArg)(MA_NatCon), MA_Layout (*acceptWsAfter)(MA_Layout))
{
  if (MA_isIntConCon(arg)) {
    return MA_makeIntConCon(
        acceptWsAfterCon ? acceptWsAfterCon(MA_getIntConWsAfterCon(arg)) : MA_getIntConWsAfterCon(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(MA_getIntConWsAfterParenOpen(arg)) : MA_getIntConWsAfterParenOpen(arg),
        acceptIntArg ? acceptIntArg(MA_getIntConIntArg(arg)) : MA_getIntConIntArg(arg),
        acceptWsAfterIntArg ? acceptWsAfterIntArg(MA_getIntConWsAfterIntArg(arg)) : MA_getIntConWsAfterIntArg(arg));
  }
  if (MA_isIntConNat(arg)) {
    return MA_makeIntConNat(
        acceptNatCon ? acceptNatCon(MA_getIntConNatCon(arg)) : MA_getIntConNatCon(arg));
  }
  if (MA_isIntConPos(arg)) {
    return MA_makeIntConPos(
        acceptWsAfterPlus ? acceptWsAfterPlus(MA_getIntConWsAfterPlus(arg)) : MA_getIntConWsAfterPlus(arg),
        acceptNatArg ? acceptNatArg(MA_getIntConNatArg(arg)) : MA_getIntConNatArg(arg));
  }
  if (MA_isIntConNeg(arg)) {
    return MA_makeIntConNeg(
        acceptWsAfter ? acceptWsAfter(MA_getIntConWsAfter(arg)) : MA_getIntConWsAfter(arg),
        acceptNatArg ? acceptNatArg(MA_getIntConNatArg(arg)) : MA_getIntConNatArg(arg));
  }
  ATabort("not a IntCon: %t\n", arg);
  return (MA_IntCon)NULL;
}

/*}}}  */
/*{{{  MA_NatCon MA_visitNatCon(MA_NatCon arg, MA_Layout (*acceptWsAfterAbs)(MA_Layout), MA_Layout (*acceptWsAfterParenOpen)(MA_Layout), MA_Int (*acceptIntArg)(MA_Int), MA_Layout (*acceptWsAfterIntArg)(MA_Layout)) */

MA_NatCon MA_visitNatCon(MA_NatCon arg, MA_Layout (*acceptWsAfterAbs)(MA_Layout), MA_Layout (*acceptWsAfterParenOpen)(MA_Layout), MA_Int (*acceptIntArg)(MA_Int), MA_Layout (*acceptWsAfterIntArg)(MA_Layout))
{
  if (MA_isNatConAbs(arg)) {
    return MA_makeNatConAbs(
        acceptWsAfterAbs ? acceptWsAfterAbs(MA_getNatConWsAfterAbs(arg)) : MA_getNatConWsAfterAbs(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(MA_getNatConWsAfterParenOpen(arg)) : MA_getNatConWsAfterParenOpen(arg),
        acceptIntArg ? acceptIntArg(MA_getNatConIntArg(arg)) : MA_getNatConIntArg(arg),
        acceptWsAfterIntArg ? acceptWsAfterIntArg(MA_getNatConWsAfterIntArg(arg)) : MA_getNatConWsAfterIntArg(arg));
  }
  ATabort("not a NatCon: %t\n", arg);
  return (MA_NatCon)NULL;
}

/*}}}  */
/*{{{  MA_Var MA_visitVar(MA_Var arg, MA_VarId (*acceptVarId)(MA_VarId), MA_Layout (*acceptWsAfterStar)(MA_Layout), MA_Layout (*acceptWsAfterPlus)(MA_Layout)) */

MA_Var MA_visitVar(MA_Var arg, MA_VarId (*acceptVarId)(MA_VarId), MA_Layout (*acceptWsAfterStar)(MA_Layout), MA_Layout (*acceptWsAfterPlus)(MA_Layout))
{
  if (MA_isVarNormal(arg)) {
    return MA_makeVarNormal(
        acceptVarId ? acceptVarId(MA_getVarVarId(arg)) : MA_getVarVarId(arg));
  }
  if (MA_isVarStar(arg)) {
    return MA_makeVarStar(
        acceptWsAfterStar ? acceptWsAfterStar(MA_getVarWsAfterStar(arg)) : MA_getVarWsAfterStar(arg),
        acceptVarId ? acceptVarId(MA_getVarVarId(arg)) : MA_getVarVarId(arg));
  }
  if (MA_isVarPlus(arg)) {
    return MA_makeVarPlus(
        acceptWsAfterPlus ? acceptWsAfterPlus(MA_getVarWsAfterPlus(arg)) : MA_getVarWsAfterPlus(arg),
        acceptVarId ? acceptVarId(MA_getVarVarId(arg)) : MA_getVarVarId(arg));
  }
  ATabort("not a Var: %t\n", arg);
  return (MA_Var)NULL;
}

/*}}}  */
/*{{{  MA_Term MA_visitTerm(MA_Term arg, MA_Var (*acceptVar)(MA_Var), MA_FunId (*acceptFunId)(MA_FunId), MA_Int (*acceptInt)(MA_Int), MA_Layout (*acceptWsAfterFunId)(MA_Layout), MA_Layout (*acceptWsAfterParenOpen)(MA_Layout), MA_TermArgs (*acceptArgs)(MA_TermArgs), MA_Layout (*acceptWsAfterArgs)(MA_Layout)) */

MA_Term MA_visitTerm(MA_Term arg, MA_Var (*acceptVar)(MA_Var), MA_FunId (*acceptFunId)(MA_FunId), MA_Int (*acceptInt)(MA_Int), MA_Layout (*acceptWsAfterFunId)(MA_Layout), MA_Layout (*acceptWsAfterParenOpen)(MA_Layout), MA_TermArgs (*acceptArgs)(MA_TermArgs), MA_Layout (*acceptWsAfterArgs)(MA_Layout))
{
  if (MA_isTermVar(arg)) {
    return MA_makeTermVar(
        acceptVar ? acceptVar(MA_getTermVar(arg)) : MA_getTermVar(arg));
  }
  if (MA_isTermConstant(arg)) {
    return MA_makeTermConstant(
        acceptFunId ? acceptFunId(MA_getTermFunId(arg)) : MA_getTermFunId(arg));
  }
  if (MA_isTermInt(arg)) {
    return MA_makeTermInt(
        acceptInt ? acceptInt(MA_getTermInt(arg)) : MA_getTermInt(arg));
  }
  if (MA_isTermFunc(arg)) {
    return MA_makeTermFunc(
        acceptFunId ? acceptFunId(MA_getTermFunId(arg)) : MA_getTermFunId(arg),
        acceptWsAfterFunId ? acceptWsAfterFunId(MA_getTermWsAfterFunId(arg)) : MA_getTermWsAfterFunId(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(MA_getTermWsAfterParenOpen(arg)) : MA_getTermWsAfterParenOpen(arg),
        acceptArgs ? acceptArgs(MA_getTermArgs(arg)) : MA_getTermArgs(arg),
        acceptWsAfterArgs ? acceptWsAfterArgs(MA_getTermWsAfterArgs(arg)) : MA_getTermWsAfterArgs(arg));
  }
  ATabort("not a Term: %t\n", arg);
  return (MA_Term)NULL;
}

/*}}}  */
/*{{{  MA_TermArgs MA_visitTermArgs(MA_TermArgs arg, MA_Term (*acceptHead)(MA_Term), MA_Layout (*acceptWsAfterFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsAfterSep)(MA_Layout)) */

MA_TermArgs MA_visitTermArgs(MA_TermArgs arg, MA_Term (*acceptHead)(MA_Term), MA_Layout (*acceptWsAfterFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsAfterSep)(MA_Layout))
{
  if (MA_isTermArgsSingle(arg)) {
    return MA_makeTermArgsSingle(
        acceptHead ? acceptHead(MA_getTermArgsHead(arg)) : MA_getTermArgsHead(arg));
  }
  if (MA_isTermArgsMany(arg)) {
    return MA_makeTermArgsMany(
        acceptHead ? acceptHead(MA_getTermArgsHead(arg)) : MA_getTermArgsHead(arg),
        acceptWsAfterFirst ? acceptWsAfterFirst(MA_getTermArgsWsAfterFirst(arg)) : MA_getTermArgsWsAfterFirst(arg),
        acceptSep ? acceptSep(MA_getTermArgsSep(arg)) : MA_getTermArgsSep(arg),
        acceptWsAfterSep ? acceptWsAfterSep(MA_getTermArgsWsAfterSep(arg)) : MA_getTermArgsWsAfterSep(arg),
        MA_visitTermArgs(MA_getTermArgsTail(arg), acceptHead, acceptWsAfterFirst, acceptSep, acceptWsAfterSep));
  }
  ATabort("not a TermArgs: %t\n", arg);
  return (MA_TermArgs)NULL;
}

/*}}}  */
/*{{{  MA_TermList MA_visitTermList(MA_TermList arg, MA_TermElems (*acceptElems)(MA_TermElems)) */

MA_TermList MA_visitTermList(MA_TermList arg, MA_TermElems (*acceptElems)(MA_TermElems))
{
  if (MA_isTermListDefault(arg)) {
    return MA_makeTermListDefault(
        acceptElems ? acceptElems(MA_getTermListElems(arg)) : MA_getTermListElems(arg));
  }
  ATabort("not a TermList: %t\n", arg);
  return (MA_TermList)NULL;
}

/*}}}  */
/*{{{  MA_TermElems MA_visitTermElems(MA_TermElems arg, MA_Term (*acceptHead)(MA_Term), MA_Layout (*acceptWsAfterFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsAfterSep)(MA_Layout)) */

MA_TermElems MA_visitTermElems(MA_TermElems arg, MA_Term (*acceptHead)(MA_Term), MA_Layout (*acceptWsAfterFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsAfterSep)(MA_Layout))
{
  if (MA_isTermElemsEmpty(arg)) {
    return MA_makeTermElemsEmpty();
  }
  if (MA_isTermElemsSingle(arg)) {
    return MA_makeTermElemsSingle(
        acceptHead ? acceptHead(MA_getTermElemsHead(arg)) : MA_getTermElemsHead(arg));
  }
  if (MA_isTermElemsMany(arg)) {
    return MA_makeTermElemsMany(
        acceptHead ? acceptHead(MA_getTermElemsHead(arg)) : MA_getTermElemsHead(arg),
        acceptWsAfterFirst ? acceptWsAfterFirst(MA_getTermElemsWsAfterFirst(arg)) : MA_getTermElemsWsAfterFirst(arg),
        acceptSep ? acceptSep(MA_getTermElemsSep(arg)) : MA_getTermElemsSep(arg),
        acceptWsAfterSep ? acceptWsAfterSep(MA_getTermElemsWsAfterSep(arg)) : MA_getTermElemsWsAfterSep(arg),
        MA_visitTermElems(MA_getTermElemsTail(arg), acceptHead, acceptWsAfterFirst, acceptSep, acceptWsAfterSep));
  }
  ATabort("not a TermElems: %t\n", arg);
  return (MA_TermElems)NULL;
}

/*}}}  */
/*{{{  MA_SigArg MA_visitSigArg(MA_SigArg arg, MA_Layout (*acceptWsAfterUnderscore)(MA_Layout)) */

MA_SigArg MA_visitSigArg(MA_SigArg arg, MA_Layout (*acceptWsAfterUnderscore)(MA_Layout))
{
  if (MA_isSigArgNormal(arg)) {
    return MA_makeSigArgNormal();
  }
  if (MA_isSigArgStar(arg)) {
    return MA_makeSigArgStar(
        acceptWsAfterUnderscore ? acceptWsAfterUnderscore(MA_getSigArgWsAfterUnderscore(arg)) : MA_getSigArgWsAfterUnderscore(arg));
  }
  if (MA_isSigArgPlus(arg)) {
    return MA_makeSigArgPlus(
        acceptWsAfterUnderscore ? acceptWsAfterUnderscore(MA_getSigArgWsAfterUnderscore(arg)) : MA_getSigArgWsAfterUnderscore(arg));
  }
  ATabort("not a SigArg: %t\n", arg);
  return (MA_SigArg)NULL;
}

/*}}}  */
/*{{{  MA_FuncDef MA_visitFuncDef(MA_FuncDef arg, MA_FunId (*acceptFunId)(MA_FunId), MA_Layout (*acceptWsAfterFunId)(MA_Layout), MA_Annotations (*acceptAnnos)(MA_Annotations), MA_Layout (*acceptWsAfterParenOpen)(MA_Layout), MA_SigArgElems (*acceptElems)(MA_SigArgElems), MA_Layout (*acceptWsAfterElems)(MA_Layout), MA_Layout (*acceptWsAfterParenClose)(MA_Layout)) */

MA_FuncDef MA_visitFuncDef(MA_FuncDef arg, MA_FunId (*acceptFunId)(MA_FunId), MA_Layout (*acceptWsAfterFunId)(MA_Layout), MA_Annotations (*acceptAnnos)(MA_Annotations), MA_Layout (*acceptWsAfterParenOpen)(MA_Layout), MA_SigArgElems (*acceptElems)(MA_SigArgElems), MA_Layout (*acceptWsAfterElems)(MA_Layout), MA_Layout (*acceptWsAfterParenClose)(MA_Layout))
{
  if (MA_isFuncDefConstantNoAnnos(arg)) {
    return MA_makeFuncDefConstantNoAnnos(
        acceptFunId ? acceptFunId(MA_getFuncDefFunId(arg)) : MA_getFuncDefFunId(arg));
  }
  if (MA_isFuncDefConstantWithAnnos(arg)) {
    return MA_makeFuncDefConstantWithAnnos(
        acceptFunId ? acceptFunId(MA_getFuncDefFunId(arg)) : MA_getFuncDefFunId(arg),
        acceptWsAfterFunId ? acceptWsAfterFunId(MA_getFuncDefWsAfterFunId(arg)) : MA_getFuncDefWsAfterFunId(arg),
        acceptAnnos ? acceptAnnos(MA_getFuncDefAnnos(arg)) : MA_getFuncDefAnnos(arg));
  }
  if (MA_isFuncDefFuncNoAnnos(arg)) {
    return MA_makeFuncDefFuncNoAnnos(
        acceptFunId ? acceptFunId(MA_getFuncDefFunId(arg)) : MA_getFuncDefFunId(arg),
        acceptWsAfterFunId ? acceptWsAfterFunId(MA_getFuncDefWsAfterFunId(arg)) : MA_getFuncDefWsAfterFunId(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(MA_getFuncDefWsAfterParenOpen(arg)) : MA_getFuncDefWsAfterParenOpen(arg),
        acceptElems ? acceptElems(MA_getFuncDefElems(arg)) : MA_getFuncDefElems(arg),
        acceptWsAfterElems ? acceptWsAfterElems(MA_getFuncDefWsAfterElems(arg)) : MA_getFuncDefWsAfterElems(arg));
  }
  if (MA_isFuncDefFuncWithAnnos(arg)) {
    return MA_makeFuncDefFuncWithAnnos(
        acceptFunId ? acceptFunId(MA_getFuncDefFunId(arg)) : MA_getFuncDefFunId(arg),
        acceptWsAfterFunId ? acceptWsAfterFunId(MA_getFuncDefWsAfterFunId(arg)) : MA_getFuncDefWsAfterFunId(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(MA_getFuncDefWsAfterParenOpen(arg)) : MA_getFuncDefWsAfterParenOpen(arg),
        acceptElems ? acceptElems(MA_getFuncDefElems(arg)) : MA_getFuncDefElems(arg),
        acceptWsAfterElems ? acceptWsAfterElems(MA_getFuncDefWsAfterElems(arg)) : MA_getFuncDefWsAfterElems(arg),
        acceptWsAfterParenClose ? acceptWsAfterParenClose(MA_getFuncDefWsAfterParenClose(arg)) : MA_getFuncDefWsAfterParenClose(arg),
        acceptAnnos ? acceptAnnos(MA_getFuncDefAnnos(arg)) : MA_getFuncDefAnnos(arg));
  }
  ATabort("not a FuncDef: %t\n", arg);
  return (MA_FuncDef)NULL;
}

/*}}}  */
/*{{{  MA_SigArgElems MA_visitSigArgElems(MA_SigArgElems arg, MA_SigArg (*acceptHead)(MA_SigArg), MA_Layout (*acceptWsAfterFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsAfterSep)(MA_Layout)) */

MA_SigArgElems MA_visitSigArgElems(MA_SigArgElems arg, MA_SigArg (*acceptHead)(MA_SigArg), MA_Layout (*acceptWsAfterFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsAfterSep)(MA_Layout))
{
  if (MA_isSigArgElemsSingle(arg)) {
    return MA_makeSigArgElemsSingle(
        acceptHead ? acceptHead(MA_getSigArgElemsHead(arg)) : MA_getSigArgElemsHead(arg));
  }
  if (MA_isSigArgElemsMany(arg)) {
    return MA_makeSigArgElemsMany(
        acceptHead ? acceptHead(MA_getSigArgElemsHead(arg)) : MA_getSigArgElemsHead(arg),
        acceptWsAfterFirst ? acceptWsAfterFirst(MA_getSigArgElemsWsAfterFirst(arg)) : MA_getSigArgElemsWsAfterFirst(arg),
        acceptSep ? acceptSep(MA_getSigArgElemsSep(arg)) : MA_getSigArgElemsSep(arg),
        acceptWsAfterSep ? acceptWsAfterSep(MA_getSigArgElemsWsAfterSep(arg)) : MA_getSigArgElemsWsAfterSep(arg),
        MA_visitSigArgElems(MA_getSigArgElemsTail(arg), acceptHead, acceptWsAfterFirst, acceptSep, acceptWsAfterSep));
  }
  ATabort("not a SigArgElems: %t\n", arg);
  return (MA_SigArgElems)NULL;
}

/*}}}  */
/*{{{  MA_Annotations MA_visitAnnotations(MA_Annotations arg, MA_Layout (*acceptWsAfterBraceOpen)(MA_Layout), MA_TermTerms (*acceptTerms)(MA_TermTerms), MA_Layout (*acceptWsAfterTerms)(MA_Layout)) */

MA_Annotations MA_visitAnnotations(MA_Annotations arg, MA_Layout (*acceptWsAfterBraceOpen)(MA_Layout), MA_TermTerms (*acceptTerms)(MA_TermTerms), MA_Layout (*acceptWsAfterTerms)(MA_Layout))
{
  if (MA_isAnnotationsDefault(arg)) {
    return MA_makeAnnotationsDefault(
        acceptWsAfterBraceOpen ? acceptWsAfterBraceOpen(MA_getAnnotationsWsAfterBraceOpen(arg)) : MA_getAnnotationsWsAfterBraceOpen(arg),
        acceptTerms ? acceptTerms(MA_getAnnotationsTerms(arg)) : MA_getAnnotationsTerms(arg),
        acceptWsAfterTerms ? acceptWsAfterTerms(MA_getAnnotationsWsAfterTerms(arg)) : MA_getAnnotationsWsAfterTerms(arg));
  }
  ATabort("not a Annotations: %t\n", arg);
  return (MA_Annotations)NULL;
}

/*}}}  */
/*{{{  MA_TermTerms MA_visitTermTerms(MA_TermTerms arg, MA_Term (*acceptHead)(MA_Term), MA_Layout (*acceptWsAfterFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsAfterSep)(MA_Layout)) */

MA_TermTerms MA_visitTermTerms(MA_TermTerms arg, MA_Term (*acceptHead)(MA_Term), MA_Layout (*acceptWsAfterFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsAfterSep)(MA_Layout))
{
  if (MA_isTermTermsSingle(arg)) {
    return MA_makeTermTermsSingle(
        acceptHead ? acceptHead(MA_getTermTermsHead(arg)) : MA_getTermTermsHead(arg));
  }
  if (MA_isTermTermsMany(arg)) {
    return MA_makeTermTermsMany(
        acceptHead ? acceptHead(MA_getTermTermsHead(arg)) : MA_getTermTermsHead(arg),
        acceptWsAfterFirst ? acceptWsAfterFirst(MA_getTermTermsWsAfterFirst(arg)) : MA_getTermTermsWsAfterFirst(arg),
        acceptSep ? acceptSep(MA_getTermTermsSep(arg)) : MA_getTermTermsSep(arg),
        acceptWsAfterSep ? acceptWsAfterSep(MA_getTermTermsWsAfterSep(arg)) : MA_getTermTermsWsAfterSep(arg),
        MA_visitTermTerms(MA_getTermTermsTail(arg), acceptHead, acceptWsAfterFirst, acceptSep, acceptWsAfterSep));
  }
  ATabort("not a TermTerms: %t\n", arg);
  return (MA_TermTerms)NULL;
}

/*}}}  */
/*{{{  MA_SigArgList MA_visitSigArgList(MA_SigArgList arg, MA_SigArgElems (*acceptElems)(MA_SigArgElems)) */

MA_SigArgList MA_visitSigArgList(MA_SigArgList arg, MA_SigArgElems (*acceptElems)(MA_SigArgElems))
{
  if (MA_isSigArgListDefault(arg)) {
    return MA_makeSigArgListDefault(
        acceptElems ? acceptElems(MA_getSigArgListElems(arg)) : MA_getSigArgListElems(arg));
  }
  ATabort("not a SigArgList: %t\n", arg);
  return (MA_SigArgList)NULL;
}

/*}}}  */
/*{{{  MA_FuncDefList MA_visitFuncDefList(MA_FuncDefList arg, MA_FuncDefElems (*acceptElems)(MA_FuncDefElems)) */

MA_FuncDefList MA_visitFuncDefList(MA_FuncDefList arg, MA_FuncDefElems (*acceptElems)(MA_FuncDefElems))
{
  if (MA_isFuncDefListDefault(arg)) {
    return MA_makeFuncDefListDefault(
        acceptElems ? acceptElems(MA_getFuncDefListElems(arg)) : MA_getFuncDefListElems(arg));
  }
  ATabort("not a FuncDefList: %t\n", arg);
  return (MA_FuncDefList)NULL;
}

/*}}}  */
/*{{{  MA_FuncDefElems MA_visitFuncDefElems(MA_FuncDefElems arg, MA_FuncDef (*acceptHead)(MA_FuncDef), MA_Layout (*acceptWsAfterFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsAfterSep)(MA_Layout)) */

MA_FuncDefElems MA_visitFuncDefElems(MA_FuncDefElems arg, MA_FuncDef (*acceptHead)(MA_FuncDef), MA_Layout (*acceptWsAfterFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsAfterSep)(MA_Layout))
{
  if (MA_isFuncDefElemsEmpty(arg)) {
    return MA_makeFuncDefElemsEmpty();
  }
  if (MA_isFuncDefElemsSingle(arg)) {
    return MA_makeFuncDefElemsSingle(
        acceptHead ? acceptHead(MA_getFuncDefElemsHead(arg)) : MA_getFuncDefElemsHead(arg));
  }
  if (MA_isFuncDefElemsMany(arg)) {
    return MA_makeFuncDefElemsMany(
        acceptHead ? acceptHead(MA_getFuncDefElemsHead(arg)) : MA_getFuncDefElemsHead(arg),
        acceptWsAfterFirst ? acceptWsAfterFirst(MA_getFuncDefElemsWsAfterFirst(arg)) : MA_getFuncDefElemsWsAfterFirst(arg),
        acceptSep ? acceptSep(MA_getFuncDefElemsSep(arg)) : MA_getFuncDefElemsSep(arg),
        acceptWsAfterSep ? acceptWsAfterSep(MA_getFuncDefElemsWsAfterSep(arg)) : MA_getFuncDefElemsWsAfterSep(arg),
        MA_visitFuncDefElems(MA_getFuncDefElemsTail(arg), acceptHead, acceptWsAfterFirst, acceptSep, acceptWsAfterSep));
  }
  ATabort("not a FuncDefElems: %t\n", arg);
  return (MA_FuncDefElems)NULL;
}

/*}}}  */
/*{{{  MA_Rule MA_visitRule(MA_Rule arg, MA_Term (*acceptLhs)(MA_Term), MA_Layout (*acceptWsAfterLhs)(MA_Layout), MA_Layout (*acceptWsAfterEquals)(MA_Layout), MA_Term (*acceptRhs)(MA_Term), MA_Layout (*acceptWsAfterDefaultColon)(MA_Layout), MA_CondList (*acceptConds)(MA_CondList), MA_Layout (*acceptWsAfterConds)(MA_Layout), MA_Layout (*acceptWsAfterImplies)(MA_Layout)) */

MA_Rule MA_visitRule(MA_Rule arg, MA_Term (*acceptLhs)(MA_Term), MA_Layout (*acceptWsAfterLhs)(MA_Layout), MA_Layout (*acceptWsAfterEquals)(MA_Layout), MA_Term (*acceptRhs)(MA_Term), MA_Layout (*acceptWsAfterDefaultColon)(MA_Layout), MA_CondList (*acceptConds)(MA_CondList), MA_Layout (*acceptWsAfterConds)(MA_Layout), MA_Layout (*acceptWsAfterImplies)(MA_Layout))
{
  if (MA_isRuleNoConds(arg)) {
    return MA_makeRuleNoConds(
        acceptLhs ? acceptLhs(MA_getRuleLhs(arg)) : MA_getRuleLhs(arg),
        acceptWsAfterLhs ? acceptWsAfterLhs(MA_getRuleWsAfterLhs(arg)) : MA_getRuleWsAfterLhs(arg),
        acceptWsAfterEquals ? acceptWsAfterEquals(MA_getRuleWsAfterEquals(arg)) : MA_getRuleWsAfterEquals(arg),
        acceptRhs ? acceptRhs(MA_getRuleRhs(arg)) : MA_getRuleRhs(arg));
  }
  if (MA_isRuleDefaultNoConds(arg)) {
    return MA_makeRuleDefaultNoConds(
        acceptWsAfterDefaultColon ? acceptWsAfterDefaultColon(MA_getRuleWsAfterDefaultColon(arg)) : MA_getRuleWsAfterDefaultColon(arg),
        acceptLhs ? acceptLhs(MA_getRuleLhs(arg)) : MA_getRuleLhs(arg),
        acceptWsAfterLhs ? acceptWsAfterLhs(MA_getRuleWsAfterLhs(arg)) : MA_getRuleWsAfterLhs(arg),
        acceptWsAfterEquals ? acceptWsAfterEquals(MA_getRuleWsAfterEquals(arg)) : MA_getRuleWsAfterEquals(arg),
        acceptRhs ? acceptRhs(MA_getRuleRhs(arg)) : MA_getRuleRhs(arg));
  }
  if (MA_isRuleDefaultWithConds(arg)) {
    return MA_makeRuleDefaultWithConds(
        acceptWsAfterDefaultColon ? acceptWsAfterDefaultColon(MA_getRuleWsAfterDefaultColon(arg)) : MA_getRuleWsAfterDefaultColon(arg),
        acceptConds ? acceptConds(MA_getRuleConds(arg)) : MA_getRuleConds(arg),
        acceptWsAfterConds ? acceptWsAfterConds(MA_getRuleWsAfterConds(arg)) : MA_getRuleWsAfterConds(arg),
        acceptWsAfterImplies ? acceptWsAfterImplies(MA_getRuleWsAfterImplies(arg)) : MA_getRuleWsAfterImplies(arg),
        acceptLhs ? acceptLhs(MA_getRuleLhs(arg)) : MA_getRuleLhs(arg),
        acceptWsAfterLhs ? acceptWsAfterLhs(MA_getRuleWsAfterLhs(arg)) : MA_getRuleWsAfterLhs(arg),
        acceptWsAfterEquals ? acceptWsAfterEquals(MA_getRuleWsAfterEquals(arg)) : MA_getRuleWsAfterEquals(arg),
        acceptRhs ? acceptRhs(MA_getRuleRhs(arg)) : MA_getRuleRhs(arg));
  }
  if (MA_isRuleWithConds(arg)) {
    return MA_makeRuleWithConds(
        acceptConds ? acceptConds(MA_getRuleConds(arg)) : MA_getRuleConds(arg),
        acceptWsAfterConds ? acceptWsAfterConds(MA_getRuleWsAfterConds(arg)) : MA_getRuleWsAfterConds(arg),
        acceptWsAfterImplies ? acceptWsAfterImplies(MA_getRuleWsAfterImplies(arg)) : MA_getRuleWsAfterImplies(arg),
        acceptLhs ? acceptLhs(MA_getRuleLhs(arg)) : MA_getRuleLhs(arg),
        acceptWsAfterLhs ? acceptWsAfterLhs(MA_getRuleWsAfterLhs(arg)) : MA_getRuleWsAfterLhs(arg),
        acceptWsAfterEquals ? acceptWsAfterEquals(MA_getRuleWsAfterEquals(arg)) : MA_getRuleWsAfterEquals(arg),
        acceptRhs ? acceptRhs(MA_getRuleRhs(arg)) : MA_getRuleRhs(arg));
  }
  ATabort("not a Rule: %t\n", arg);
  return (MA_Rule)NULL;
}

/*}}}  */
/*{{{  MA_RuleList MA_visitRuleList(MA_RuleList arg, MA_RuleElems (*acceptElems)(MA_RuleElems)) */

MA_RuleList MA_visitRuleList(MA_RuleList arg, MA_RuleElems (*acceptElems)(MA_RuleElems))
{
  if (MA_isRuleListDefault(arg)) {
    return MA_makeRuleListDefault(
        acceptElems ? acceptElems(MA_getRuleListElems(arg)) : MA_getRuleListElems(arg));
  }
  ATabort("not a RuleList: %t\n", arg);
  return (MA_RuleList)NULL;
}

/*}}}  */
/*{{{  MA_RuleElems MA_visitRuleElems(MA_RuleElems arg, MA_Rule (*acceptHead)(MA_Rule), MA_Layout (*acceptWsAfterFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsAfterSep)(MA_Layout)) */

MA_RuleElems MA_visitRuleElems(MA_RuleElems arg, MA_Rule (*acceptHead)(MA_Rule), MA_Layout (*acceptWsAfterFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsAfterSep)(MA_Layout))
{
  if (MA_isRuleElemsEmpty(arg)) {
    return MA_makeRuleElemsEmpty();
  }
  if (MA_isRuleElemsSingle(arg)) {
    return MA_makeRuleElemsSingle(
        acceptHead ? acceptHead(MA_getRuleElemsHead(arg)) : MA_getRuleElemsHead(arg));
  }
  if (MA_isRuleElemsMany(arg)) {
    return MA_makeRuleElemsMany(
        acceptHead ? acceptHead(MA_getRuleElemsHead(arg)) : MA_getRuleElemsHead(arg),
        acceptWsAfterFirst ? acceptWsAfterFirst(MA_getRuleElemsWsAfterFirst(arg)) : MA_getRuleElemsWsAfterFirst(arg),
        acceptSep ? acceptSep(MA_getRuleElemsSep(arg)) : MA_getRuleElemsSep(arg),
        acceptWsAfterSep ? acceptWsAfterSep(MA_getRuleElemsWsAfterSep(arg)) : MA_getRuleElemsWsAfterSep(arg),
        MA_visitRuleElems(MA_getRuleElemsTail(arg), acceptHead, acceptWsAfterFirst, acceptSep, acceptWsAfterSep));
  }
  ATabort("not a RuleElems: %t\n", arg);
  return (MA_RuleElems)NULL;
}

/*}}}  */
/*{{{  MA_CondList MA_visitCondList(MA_CondList arg, MA_CondElems (*acceptElems)(MA_CondElems)) */

MA_CondList MA_visitCondList(MA_CondList arg, MA_CondElems (*acceptElems)(MA_CondElems))
{
  if (MA_isCondListDefault(arg)) {
    return MA_makeCondListDefault(
        acceptElems ? acceptElems(MA_getCondListElems(arg)) : MA_getCondListElems(arg));
  }
  ATabort("not a CondList: %t\n", arg);
  return (MA_CondList)NULL;
}

/*}}}  */
/*{{{  MA_CondElems MA_visitCondElems(MA_CondElems arg, MA_Cond (*acceptHead)(MA_Cond), MA_Layout (*acceptWsAfterFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsAfterSep)(MA_Layout)) */

MA_CondElems MA_visitCondElems(MA_CondElems arg, MA_Cond (*acceptHead)(MA_Cond), MA_Layout (*acceptWsAfterFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsAfterSep)(MA_Layout))
{
  if (MA_isCondElemsEmpty(arg)) {
    return MA_makeCondElemsEmpty();
  }
  if (MA_isCondElemsSingle(arg)) {
    return MA_makeCondElemsSingle(
        acceptHead ? acceptHead(MA_getCondElemsHead(arg)) : MA_getCondElemsHead(arg));
  }
  if (MA_isCondElemsMany(arg)) {
    return MA_makeCondElemsMany(
        acceptHead ? acceptHead(MA_getCondElemsHead(arg)) : MA_getCondElemsHead(arg),
        acceptWsAfterFirst ? acceptWsAfterFirst(MA_getCondElemsWsAfterFirst(arg)) : MA_getCondElemsWsAfterFirst(arg),
        acceptSep ? acceptSep(MA_getCondElemsSep(arg)) : MA_getCondElemsSep(arg),
        acceptWsAfterSep ? acceptWsAfterSep(MA_getCondElemsWsAfterSep(arg)) : MA_getCondElemsWsAfterSep(arg),
        MA_visitCondElems(MA_getCondElemsTail(arg), acceptHead, acceptWsAfterFirst, acceptSep, acceptWsAfterSep));
  }
  ATabort("not a CondElems: %t\n", arg);
  return (MA_CondElems)NULL;
}

/*}}}  */
/*{{{  MA_Cond MA_visitCond(MA_Cond arg, MA_Term (*acceptLhs)(MA_Term), MA_Layout (*acceptWsAfterLhs)(MA_Layout), MA_Layout (*acceptWsAfterAssign)(MA_Layout), MA_Term (*acceptRhs)(MA_Term), MA_Layout (*acceptWsAfterEqual)(MA_Layout), MA_Layout (*acceptWsAfterUnequal)(MA_Layout)) */

MA_Cond MA_visitCond(MA_Cond arg, MA_Term (*acceptLhs)(MA_Term), MA_Layout (*acceptWsAfterLhs)(MA_Layout), MA_Layout (*acceptWsAfterAssign)(MA_Layout), MA_Term (*acceptRhs)(MA_Term), MA_Layout (*acceptWsAfterEqual)(MA_Layout), MA_Layout (*acceptWsAfterUnequal)(MA_Layout))
{
  if (MA_isCondAssign(arg)) {
    return MA_makeCondAssign(
        acceptLhs ? acceptLhs(MA_getCondLhs(arg)) : MA_getCondLhs(arg),
        acceptWsAfterLhs ? acceptWsAfterLhs(MA_getCondWsAfterLhs(arg)) : MA_getCondWsAfterLhs(arg),
        acceptWsAfterAssign ? acceptWsAfterAssign(MA_getCondWsAfterAssign(arg)) : MA_getCondWsAfterAssign(arg),
        acceptRhs ? acceptRhs(MA_getCondRhs(arg)) : MA_getCondRhs(arg));
  }
  if (MA_isCondEqual(arg)) {
    return MA_makeCondEqual(
        acceptLhs ? acceptLhs(MA_getCondLhs(arg)) : MA_getCondLhs(arg),
        acceptWsAfterLhs ? acceptWsAfterLhs(MA_getCondWsAfterLhs(arg)) : MA_getCondWsAfterLhs(arg),
        acceptWsAfterEqual ? acceptWsAfterEqual(MA_getCondWsAfterEqual(arg)) : MA_getCondWsAfterEqual(arg),
        acceptRhs ? acceptRhs(MA_getCondRhs(arg)) : MA_getCondRhs(arg));
  }
  if (MA_isCondUnequal(arg)) {
    return MA_makeCondUnequal(
        acceptLhs ? acceptLhs(MA_getCondLhs(arg)) : MA_getCondLhs(arg),
        acceptWsAfterLhs ? acceptWsAfterLhs(MA_getCondWsAfterLhs(arg)) : MA_getCondWsAfterLhs(arg),
        acceptWsAfterUnequal ? acceptWsAfterUnequal(MA_getCondWsAfterUnequal(arg)) : MA_getCondWsAfterUnequal(arg),
        acceptRhs ? acceptRhs(MA_getCondRhs(arg)) : MA_getCondRhs(arg));
  }
  ATabort("not a Cond: %t\n", arg);
  return (MA_Cond)NULL;
}

/*}}}  */
/*{{{  MA_SignatureOpt MA_visitSignatureOpt(MA_SignatureOpt arg, MA_Layout (*acceptWsAfterSignature)(MA_Layout), MA_FuncDefList (*acceptFuncdefs)(MA_FuncDefList)) */

MA_SignatureOpt MA_visitSignatureOpt(MA_SignatureOpt arg, MA_Layout (*acceptWsAfterSignature)(MA_Layout), MA_FuncDefList (*acceptFuncdefs)(MA_FuncDefList))
{
  if (MA_isSignatureOptAbsent(arg)) {
    return MA_makeSignatureOptAbsent();
  }
  if (MA_isSignatureOptPresent(arg)) {
    return MA_makeSignatureOptPresent(
        acceptWsAfterSignature ? acceptWsAfterSignature(MA_getSignatureOptWsAfterSignature(arg)) : MA_getSignatureOptWsAfterSignature(arg),
        acceptFuncdefs ? acceptFuncdefs(MA_getSignatureOptFuncdefs(arg)) : MA_getSignatureOptFuncdefs(arg));
  }
  ATabort("not a SignatureOpt: %t\n", arg);
  return (MA_SignatureOpt)NULL;
}

/*}}}  */
/*{{{  MA_RulesOpt MA_visitRulesOpt(MA_RulesOpt arg, MA_Layout (*acceptWsAfterRules)(MA_Layout), MA_RuleList (*acceptRules)(MA_RuleList)) */

MA_RulesOpt MA_visitRulesOpt(MA_RulesOpt arg, MA_Layout (*acceptWsAfterRules)(MA_Layout), MA_RuleList (*acceptRules)(MA_RuleList))
{
  if (MA_isRulesOptAbsent(arg)) {
    return MA_makeRulesOptAbsent();
  }
  if (MA_isRulesOptPresent(arg)) {
    return MA_makeRulesOptPresent(
        acceptWsAfterRules ? acceptWsAfterRules(MA_getRulesOptWsAfterRules(arg)) : MA_getRulesOptWsAfterRules(arg),
        acceptRules ? acceptRules(MA_getRulesOptRules(arg)) : MA_getRulesOptRules(arg));
  }
  ATabort("not a RulesOpt: %t\n", arg);
  return (MA_RulesOpt)NULL;
}

/*}}}  */
/*{{{  MA_Module MA_visitModule(MA_Module arg, MA_Layout (*acceptWsAfterModule)(MA_Layout), MA_ModId (*acceptId)(MA_ModId), MA_Layout (*acceptWsAfterId)(MA_Layout), MA_SignatureOpt (*acceptSignature)(MA_SignatureOpt), MA_Layout (*acceptWsAfterSignature)(MA_Layout), MA_RulesOpt (*acceptRules)(MA_RulesOpt)) */

MA_Module MA_visitModule(MA_Module arg, MA_Layout (*acceptWsAfterModule)(MA_Layout), MA_ModId (*acceptId)(MA_ModId), MA_Layout (*acceptWsAfterId)(MA_Layout), MA_SignatureOpt (*acceptSignature)(MA_SignatureOpt), MA_Layout (*acceptWsAfterSignature)(MA_Layout), MA_RulesOpt (*acceptRules)(MA_RulesOpt))
{
  if (MA_isModuleModule(arg)) {
    return MA_makeModuleModule(
        acceptWsAfterModule ? acceptWsAfterModule(MA_getModuleWsAfterModule(arg)) : MA_getModuleWsAfterModule(arg),
        acceptId ? acceptId(MA_getModuleId(arg)) : MA_getModuleId(arg),
        acceptWsAfterId ? acceptWsAfterId(MA_getModuleWsAfterId(arg)) : MA_getModuleWsAfterId(arg),
        acceptSignature ? acceptSignature(MA_getModuleSignature(arg)) : MA_getModuleSignature(arg),
        acceptWsAfterSignature ? acceptWsAfterSignature(MA_getModuleWsAfterSignature(arg)) : MA_getModuleWsAfterSignature(arg),
        acceptRules ? acceptRules(MA_getModuleRules(arg)) : MA_getModuleRules(arg));
  }
  ATabort("not a Module: %t\n", arg);
  return (MA_Module)NULL;
}

/*}}}  */
/*{{{  MA_EscChar MA_visitEscChar(MA_EscChar arg, MA_Lexical (*acceptLex)(MA_Lexical)) */

MA_EscChar MA_visitEscChar(MA_EscChar arg, MA_Lexical (*acceptLex)(MA_Lexical))
{
  if (MA_isEscCharLexToCf(arg)) {
    return MA_makeEscCharLexToCf(
        acceptLex ? acceptLex(MA_getEscCharLex(arg)) : MA_getEscCharLex(arg));
  }
  ATabort("not a EscChar: %t\n", arg);
  return (MA_EscChar)NULL;
}

/*}}}  */
/*{{{  MA_QChar MA_visitQChar(MA_QChar arg, MA_Lexical (*acceptLex)(MA_Lexical)) */

MA_QChar MA_visitQChar(MA_QChar arg, MA_Lexical (*acceptLex)(MA_Lexical))
{
  if (MA_isQCharLexToCf(arg)) {
    return MA_makeQCharLexToCf(
        acceptLex ? acceptLex(MA_getQCharLex(arg)) : MA_getQCharLex(arg));
  }
  ATabort("not a QChar: %t\n", arg);
  return (MA_QChar)NULL;
}

/*}}}  */
/*{{{  MA_FunId MA_visitFunId(MA_FunId arg, MA_Lexical (*acceptLex)(MA_Lexical)) */

MA_FunId MA_visitFunId(MA_FunId arg, MA_Lexical (*acceptLex)(MA_Lexical))
{
  if (MA_isFunIdLexToCf(arg)) {
    return MA_makeFunIdLexToCf(
        acceptLex ? acceptLex(MA_getFunIdLex(arg)) : MA_getFunIdLex(arg));
  }
  ATabort("not a FunId: %t\n", arg);
  return (MA_FunId)NULL;
}

/*}}}  */
/*{{{  MA_VarId MA_visitVarId(MA_VarId arg, MA_Lexical (*acceptLex)(MA_Lexical)) */

MA_VarId MA_visitVarId(MA_VarId arg, MA_Lexical (*acceptLex)(MA_Lexical))
{
  if (MA_isVarIdLexToCf(arg)) {
    return MA_makeVarIdLexToCf(
        acceptLex ? acceptLex(MA_getVarIdLex(arg)) : MA_getVarIdLex(arg));
  }
  ATabort("not a VarId: %t\n", arg);
  return (MA_VarId)NULL;
}

/*}}}  */
/*{{{  MA_ModId MA_visitModId(MA_ModId arg, MA_Lexical (*acceptLex)(MA_Lexical)) */

MA_ModId MA_visitModId(MA_ModId arg, MA_Lexical (*acceptLex)(MA_Lexical))
{
  if (MA_isModIdLexToCf(arg)) {
    return MA_makeModIdLexToCf(
        acceptLex ? acceptLex(MA_getModIdLex(arg)) : MA_getModIdLex(arg));
  }
  ATabort("not a ModId: %t\n", arg);
  return (MA_ModId)NULL;
}

/*}}}  */
/*{{{  MA_PropId MA_visitPropId(MA_PropId arg, MA_Lexical (*acceptLex)(MA_Lexical)) */

MA_PropId MA_visitPropId(MA_PropId arg, MA_Lexical (*acceptLex)(MA_Lexical))
{
  if (MA_isPropIdLexToCf(arg)) {
    return MA_makePropIdLexToCf(
        acceptLex ? acceptLex(MA_getPropIdLex(arg)) : MA_getPropIdLex(arg));
  }
  ATabort("not a PropId: %t\n", arg);
  return (MA_PropId)NULL;
}

/*}}}  */

/*}}}  */
