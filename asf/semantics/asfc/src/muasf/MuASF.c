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
typedef struct ATerm _MA_TermMinusArgs;
typedef struct ATerm _MA_TermList;
typedef struct ATerm _MA_TermMinusTerms;
typedef struct ATerm _MA_SigArg;
typedef struct ATerm _MA_FuncDef;
typedef struct ATerm _MA_SigArgMinusArgs;
typedef struct ATerm _MA_Annotations;
typedef struct ATerm _MA_SigArgList;
typedef struct ATerm _MA_SigArgMinusSigargs;
typedef struct ATerm _MA_FuncDefList;
typedef struct ATerm _MA_FuncDefMinusFuncdefs;
typedef struct ATerm _MA_Rule;
typedef struct ATerm _MA_RuleList;
typedef struct ATerm _MA_RuleMinusRules;
typedef struct ATerm _MA_CondList;
typedef struct ATerm _MA_CondMinusConds;
typedef struct ATerm _MA_Cond;
typedef struct ATerm _MA_SignatureOpt;
typedef struct ATerm _MA_RulesOpt;
typedef struct ATerm _MA_Module;
typedef struct ATerm _MA_NamePair;
typedef struct ATerm _MA_TermMinusAttributes;
typedef struct ATerm _MA_NameTable;
typedef struct ATerm _MA_NamePairMinusTable;
typedef struct ATerm _MA_MNMinusStruct;

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
/*{{{  MA_TermMinusArgs MA_TermMinusArgsFromTerm(ATerm t) */

MA_TermMinusArgs MA_TermMinusArgsFromTerm(ATerm t)
{
  return (MA_TermMinusArgs)t;
}

/*}}}  */
/*{{{  ATerm MA_TermMinusArgsToTerm(MA_TermMinusArgs arg) */

ATerm MA_TermMinusArgsToTerm(MA_TermMinusArgs arg)
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
/*{{{  MA_TermMinusTerms MA_TermMinusTermsFromTerm(ATerm t) */

MA_TermMinusTerms MA_TermMinusTermsFromTerm(ATerm t)
{
  return (MA_TermMinusTerms)t;
}

/*}}}  */
/*{{{  ATerm MA_TermMinusTermsToTerm(MA_TermMinusTerms arg) */

ATerm MA_TermMinusTermsToTerm(MA_TermMinusTerms arg)
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
/*{{{  MA_SigArgMinusArgs MA_SigArgMinusArgsFromTerm(ATerm t) */

MA_SigArgMinusArgs MA_SigArgMinusArgsFromTerm(ATerm t)
{
  return (MA_SigArgMinusArgs)t;
}

/*}}}  */
/*{{{  ATerm MA_SigArgMinusArgsToTerm(MA_SigArgMinusArgs arg) */

ATerm MA_SigArgMinusArgsToTerm(MA_SigArgMinusArgs arg)
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
/*{{{  MA_SigArgMinusSigargs MA_SigArgMinusSigargsFromTerm(ATerm t) */

MA_SigArgMinusSigargs MA_SigArgMinusSigargsFromTerm(ATerm t)
{
  return (MA_SigArgMinusSigargs)t;
}

/*}}}  */
/*{{{  ATerm MA_SigArgMinusSigargsToTerm(MA_SigArgMinusSigargs arg) */

ATerm MA_SigArgMinusSigargsToTerm(MA_SigArgMinusSigargs arg)
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
/*{{{  MA_FuncDefMinusFuncdefs MA_FuncDefMinusFuncdefsFromTerm(ATerm t) */

MA_FuncDefMinusFuncdefs MA_FuncDefMinusFuncdefsFromTerm(ATerm t)
{
  return (MA_FuncDefMinusFuncdefs)t;
}

/*}}}  */
/*{{{  ATerm MA_FuncDefMinusFuncdefsToTerm(MA_FuncDefMinusFuncdefs arg) */

ATerm MA_FuncDefMinusFuncdefsToTerm(MA_FuncDefMinusFuncdefs arg)
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
/*{{{  MA_RuleMinusRules MA_RuleMinusRulesFromTerm(ATerm t) */

MA_RuleMinusRules MA_RuleMinusRulesFromTerm(ATerm t)
{
  return (MA_RuleMinusRules)t;
}

/*}}}  */
/*{{{  ATerm MA_RuleMinusRulesToTerm(MA_RuleMinusRules arg) */

ATerm MA_RuleMinusRulesToTerm(MA_RuleMinusRules arg)
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
/*{{{  MA_CondMinusConds MA_CondMinusCondsFromTerm(ATerm t) */

MA_CondMinusConds MA_CondMinusCondsFromTerm(ATerm t)
{
  return (MA_CondMinusConds)t;
}

/*}}}  */
/*{{{  ATerm MA_CondMinusCondsToTerm(MA_CondMinusConds arg) */

ATerm MA_CondMinusCondsToTerm(MA_CondMinusConds arg)
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
/*{{{  MA_NamePair MA_NamePairFromTerm(ATerm t) */

MA_NamePair MA_NamePairFromTerm(ATerm t)
{
  return (MA_NamePair)t;
}

/*}}}  */
/*{{{  ATerm MA_NamePairToTerm(MA_NamePair arg) */

ATerm MA_NamePairToTerm(MA_NamePair arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_TermMinusAttributes MA_TermMinusAttributesFromTerm(ATerm t) */

MA_TermMinusAttributes MA_TermMinusAttributesFromTerm(ATerm t)
{
  return (MA_TermMinusAttributes)t;
}

/*}}}  */
/*{{{  ATerm MA_TermMinusAttributesToTerm(MA_TermMinusAttributes arg) */

ATerm MA_TermMinusAttributesToTerm(MA_TermMinusAttributes arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_NameTable MA_NameTableFromTerm(ATerm t) */

MA_NameTable MA_NameTableFromTerm(ATerm t)
{
  return (MA_NameTable)t;
}

/*}}}  */
/*{{{  ATerm MA_NameTableToTerm(MA_NameTable arg) */

ATerm MA_NameTableToTerm(MA_NameTable arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_NamePairMinusTable MA_NamePairMinusTableFromTerm(ATerm t) */

MA_NamePairMinusTable MA_NamePairMinusTableFromTerm(ATerm t)
{
  return (MA_NamePairMinusTable)t;
}

/*}}}  */
/*{{{  ATerm MA_NamePairMinusTableToTerm(MA_NamePairMinusTable arg) */

ATerm MA_NamePairMinusTableToTerm(MA_NamePairMinusTable arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_MNMinusStruct MA_MNMinusStructFromTerm(ATerm t) */

MA_MNMinusStruct MA_MNMinusStructFromTerm(ATerm t)
{
  return (MA_MNMinusStruct)t;
}

/*}}}  */
/*{{{  ATerm MA_MNMinusStructToTerm(MA_MNMinusStruct arg) */

ATerm MA_MNMinusStructToTerm(MA_MNMinusStruct arg)
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
/*{{{  MA_Int MA_makeIntPlus(MA_Int lhs, MA_Layout wsMinusAfterMinusLhs, MA_Layout wsMinusAfterMinusPlus, MA_Int rhs) */

MA_Int MA_makeIntPlus(MA_Int lhs, MA_Layout wsMinusAfterMinusLhs, MA_Layout wsMinusAfterMinusPlus, MA_Int rhs)
{
  return (MA_Int)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun5)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun12))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun5)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun5))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun8))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeAppl0(MA_afun14))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)rhs), (ATerm)wsMinusAfterMinusPlus), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun12))), (ATerm)wsMinusAfterMinusLhs), (ATerm)lhs));
}

/*}}}  */
/*{{{  MA_IntCon MA_makeIntConCon(MA_Layout wsMinusAfterMinusCon, MA_Layout wsMinusAfterMinusParenOpen, MA_Int intMinusArg, MA_Layout wsMinusAfterMinusIntMinusArg) */

MA_IntCon MA_makeIntConCon(MA_Layout wsMinusAfterMinusCon, MA_Layout wsMinusAfterMinusParenOpen, MA_Int intMinusArg, MA_Layout wsMinusAfterMinusIntMinusArg)
{
  return (MA_IntCon)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun15))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun5)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun16))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun17))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun8))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun15))), (ATerm)wsMinusAfterMinusIntMinusArg), (ATerm)intMinusArg), (ATerm)wsMinusAfterMinusParenOpen), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun16))), (ATerm)wsMinusAfterMinusCon), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun17))));
}

/*}}}  */
/*{{{  MA_IntCon MA_makeIntConNat(MA_NatCon NatCon) */

MA_IntCon MA_makeIntConNat(MA_NatCon NatCon)
{
  return (MA_IntCon)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun18)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun4))))), (ATerm)ATmakeList1((ATerm)NatCon));
}

/*}}}  */
/*{{{  MA_IntCon MA_makeIntConPos(MA_Layout wsMinusAfterMinusPlus, MA_NatCon natMinusArg) */

MA_IntCon MA_makeIntConPos(MA_Layout wsMinusAfterMinusPlus, MA_NatCon natMinusArg)
{
  return (MA_IntCon)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun18)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun12))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun4))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)natMinusArg), (ATerm)wsMinusAfterMinusPlus), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun12))));
}

/*}}}  */
/*{{{  MA_IntCon MA_makeIntConNeg(MA_Layout wsMinusAfterMinusMinus, MA_NatCon natMinusArg) */

MA_IntCon MA_makeIntConNeg(MA_Layout wsMinusAfterMinusMinus, MA_NatCon natMinusArg)
{
  return (MA_IntCon)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun18)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun19))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun4))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)natMinusArg), (ATerm)wsMinusAfterMinusMinus), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun19))));
}

/*}}}  */
/*{{{  MA_NatCon MA_makeNatConAbs(MA_Layout wsMinusAfterMinusAbs, MA_Layout wsMinusAfterMinusParenOpen, MA_Int intMinusArg, MA_Layout wsMinusAfterMinusIntMinusArg) */

MA_NatCon MA_makeNatConAbs(MA_Layout wsMinusAfterMinusAbs, MA_Layout wsMinusAfterMinusParenOpen, MA_Int intMinusArg, MA_Layout wsMinusAfterMinusIntMinusArg)
{
  return (MA_NatCon)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun15))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun5)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun16))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun20))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun18))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun8))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun15))), (ATerm)wsMinusAfterMinusIntMinusArg), (ATerm)intMinusArg), (ATerm)wsMinusAfterMinusParenOpen), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun16))), (ATerm)wsMinusAfterMinusAbs), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun20))));
}

/*}}}  */
/*{{{  MA_Var MA_makeVarNormal(MA_VarId VarId) */

MA_Var MA_makeVarNormal(MA_VarId VarId)
{
  return (MA_Var)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun21)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun22))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATmakeList1((ATerm)VarId));
}

/*}}}  */
/*{{{  MA_Var MA_makeVarStar(MA_Layout wsMinusAfterMinusStar, MA_VarId VarId) */

MA_Var MA_makeVarStar(MA_Layout wsMinusAfterMinusStar, MA_VarId VarId)
{
  return (MA_Var)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun21)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun24))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun22))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)VarId), (ATerm)wsMinusAfterMinusStar), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun24))));
}

/*}}}  */
/*{{{  MA_Var MA_makeVarPlus(MA_Layout wsMinusAfterMinusPlus, MA_VarId VarId) */

MA_Var MA_makeVarPlus(MA_Layout wsMinusAfterMinusPlus, MA_VarId VarId)
{
  return (MA_Var)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun21)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun12))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun22))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)VarId), (ATerm)wsMinusAfterMinusPlus), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun12))));
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
/*{{{  MA_Term MA_makeTermFunc(MA_FunId FunId, MA_Layout wsMinusAfterMinusFunId, MA_Layout wsMinusAfterMinusParenOpen, MA_TermMinusArgs args, MA_Layout wsMinusAfterMinusArgs) */

MA_Term MA_makeTermFunc(MA_FunId FunId, MA_Layout wsMinusAfterMinusFunId, MA_Layout wsMinusAfterMinusParenOpen, MA_TermMinusArgs args, MA_Layout wsMinusAfterMinusArgs)
{
  return (MA_Term)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun15))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun27, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun16))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun26)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun15))), (ATerm)wsMinusAfterMinusArgs), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl1(MA_afun29, (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun27, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))))), (ATerm)args)), (ATerm)wsMinusAfterMinusParenOpen), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun16))), (ATerm)wsMinusAfterMinusFunId), (ATerm)FunId));
}

/*}}}  */
/*{{{  MA_TermMinusArgs MA_makeTermMinusArgsSingle(MA_Term head) */

MA_TermMinusArgs MA_makeTermMinusArgsSingle(MA_Term head)
{
  return (MA_TermMinusArgs)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  MA_TermMinusArgs MA_makeTermMinusArgsMany(MA_Term head, MA_Layout wsMinusAfterMinusFirst, char * sep, MA_Layout wsMinusAfterMinusSep, MA_TermMinusArgs tail) */

MA_TermMinusArgs MA_makeTermMinusArgsMany(MA_Term head, MA_Layout wsMinusAfterMinusFirst, char * sep, MA_Layout wsMinusAfterMinusSep, MA_TermMinusArgs tail)
{
  return (MA_TermMinusArgs)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm)wsMinusAfterMinusSep), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)))), (ATerm)wsMinusAfterMinusFirst), (ATerm)head);
}

/*}}}  */
/*{{{  MA_TermList MA_makeTermListDefault(MA_TermMinusTerms terms) */

MA_TermList MA_makeTermListDefault(MA_TermMinusTerms terms)
{
  return (MA_TermList)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun30, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun31))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl1(MA_afun29, (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun30, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))))), (ATerm)terms)));
}

/*}}}  */
/*{{{  MA_TermMinusTerms MA_makeTermMinusTermsEmpty() */

MA_TermMinusTerms MA_makeTermMinusTermsEmpty()
{
  return (MA_TermMinusTerms)(ATerm)ATempty;
}

/*}}}  */
/*{{{  MA_TermMinusTerms MA_makeTermMinusTermsSingle(MA_Term head) */

MA_TermMinusTerms MA_makeTermMinusTermsSingle(MA_Term head)
{
  return (MA_TermMinusTerms)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  MA_TermMinusTerms MA_makeTermMinusTermsMany(MA_Term head, MA_Layout wsMinusAfterMinusFirst, char * sep, MA_Layout wsMinusAfterMinusSep, MA_TermMinusTerms tail) */

MA_TermMinusTerms MA_makeTermMinusTermsMany(MA_Term head, MA_Layout wsMinusAfterMinusFirst, char * sep, MA_Layout wsMinusAfterMinusSep, MA_TermMinusTerms tail)
{
  return (MA_TermMinusTerms)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm)wsMinusAfterMinusSep), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)))), (ATerm)wsMinusAfterMinusFirst), (ATerm)head);
}

/*}}}  */
/*{{{  MA_SigArg MA_makeSigArgNormal() */

MA_SigArg MA_makeSigArgNormal()
{
  return (MA_SigArg)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun32))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun33))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun32))));
}

/*}}}  */
/*{{{  MA_SigArg MA_makeSigArgStar(MA_Layout wsMinusAfterMinusUnderscore) */

MA_SigArg MA_makeSigArgStar(MA_Layout wsMinusAfterMinusUnderscore)
{
  return (MA_SigArg)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun24))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun32))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun33))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun24))), (ATerm)wsMinusAfterMinusUnderscore), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun32))));
}

/*}}}  */
/*{{{  MA_SigArg MA_makeSigArgPlus(MA_Layout wsMinusAfterMinusUnderscore) */

MA_SigArg MA_makeSigArgPlus(MA_Layout wsMinusAfterMinusUnderscore)
{
  return (MA_SigArg)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun12))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun32))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun33))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun12))), (ATerm)wsMinusAfterMinusUnderscore), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun32))));
}

/*}}}  */
/*{{{  MA_FuncDef MA_makeFuncDefConstantMinusNoMinusAnnos(MA_FunId FunId) */

MA_FuncDef MA_makeFuncDefConstantMinusNoMinusAnnos(MA_FunId FunId)
{
  return (MA_FuncDef)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun26)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun34))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATmakeList1((ATerm)FunId));
}

/*}}}  */
/*{{{  MA_FuncDef MA_makeFuncDefConstantMinusWithMinusAnnos(MA_FunId FunId, MA_Layout wsMinusAfterMinusFunId, MA_Annotations annos) */

MA_FuncDef MA_makeFuncDefConstantMinusWithMinusAnnos(MA_FunId FunId, MA_Layout wsMinusAfterMinusFunId, MA_Annotations annos)
{
  return (MA_FuncDef)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun35)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun26)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun34))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)annos), (ATerm)wsMinusAfterMinusFunId), (ATerm)FunId));
}

/*}}}  */
/*{{{  MA_FuncDef MA_makeFuncDefFuncMinusNoMinusAnnos(MA_FunId FunId, MA_Layout wsMinusAfterMinusFunId, MA_Layout wsMinusAfterMinusParenOpen, MA_SigArgMinusArgs args, MA_Layout wsMinusAfterMinusArgs) */

MA_FuncDef MA_makeFuncDefFuncMinusNoMinusAnnos(MA_FunId FunId, MA_Layout wsMinusAfterMinusFunId, MA_Layout wsMinusAfterMinusParenOpen, MA_SigArgMinusArgs args, MA_Layout wsMinusAfterMinusArgs)
{
  return (MA_FuncDef)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun15))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun27, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun33)), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun16))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun26)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun34))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun15))), (ATerm)wsMinusAfterMinusArgs), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl1(MA_afun29, (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun27, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun33)), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))))), (ATerm)args)), (ATerm)wsMinusAfterMinusParenOpen), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun16))), (ATerm)wsMinusAfterMinusFunId), (ATerm)FunId));
}

/*}}}  */
/*{{{  MA_FuncDef MA_makeFuncDefFuncMinusWithMinusAnnos(MA_FunId FunId, MA_Layout wsMinusAfterMinusFunId, MA_Layout wsMinusAfterMinusParenOpen, MA_SigArgMinusArgs args, MA_Layout wsMinusAfterMinusArgs, MA_Layout wsMinusAfterMinusParenClose, MA_Annotations annos) */

MA_FuncDef MA_makeFuncDefFuncMinusWithMinusAnnos(MA_FunId FunId, MA_Layout wsMinusAfterMinusFunId, MA_Layout wsMinusAfterMinusParenOpen, MA_SigArgMinusArgs args, MA_Layout wsMinusAfterMinusArgs, MA_Layout wsMinusAfterMinusParenClose, MA_Annotations annos)
{
  return (MA_FuncDef)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun35)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun15))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun27, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun33)), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun16))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun26)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun34))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)annos), (ATerm)wsMinusAfterMinusParenClose), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun15))), (ATerm)wsMinusAfterMinusArgs), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl1(MA_afun29, (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun27, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun33)), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))))), (ATerm)args)), (ATerm)wsMinusAfterMinusParenOpen), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun16))), (ATerm)wsMinusAfterMinusFunId), (ATerm)FunId));
}

/*}}}  */
/*{{{  MA_SigArgMinusArgs MA_makeSigArgMinusArgsSingle(MA_SigArg head) */

MA_SigArgMinusArgs MA_makeSigArgMinusArgsSingle(MA_SigArg head)
{
  return (MA_SigArgMinusArgs)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  MA_SigArgMinusArgs MA_makeSigArgMinusArgsMany(MA_SigArg head, MA_Layout wsMinusAfterMinusFirst, char * sep, MA_Layout wsMinusAfterMinusSep, MA_SigArgMinusArgs tail) */

MA_SigArgMinusArgs MA_makeSigArgMinusArgsMany(MA_SigArg head, MA_Layout wsMinusAfterMinusFirst, char * sep, MA_Layout wsMinusAfterMinusSep, MA_SigArgMinusArgs tail)
{
  return (MA_SigArgMinusArgs)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm)wsMinusAfterMinusSep), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)))), (ATerm)wsMinusAfterMinusFirst), (ATerm)head);
}

/*}}}  */
/*{{{  MA_Annotations MA_makeAnnotationsDefault(MA_Layout wsMinusAfterMinusBraceOpen, MA_TermMinusTerms terms, MA_Layout wsMinusAfterMinusTerms) */

MA_Annotations MA_makeAnnotationsDefault(MA_Layout wsMinusAfterMinusBraceOpen, MA_TermMinusTerms terms, MA_Layout wsMinusAfterMinusTerms)
{
  return (MA_Annotations)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun36))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun27, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun37))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun35))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun36))), (ATerm)wsMinusAfterMinusTerms), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl1(MA_afun29, (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun27, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))))), (ATerm)terms)), (ATerm)wsMinusAfterMinusBraceOpen), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun37))));
}

/*}}}  */
/*{{{  MA_SigArgList MA_makeSigArgListDefault(MA_SigArgMinusSigargs sigargs) */

MA_SigArgList MA_makeSigArgListDefault(MA_SigArgMinusSigargs sigargs)
{
  return (MA_SigArgList)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun27, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun33)), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun38))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl1(MA_afun29, (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun27, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun33)), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))))), (ATerm)sigargs)));
}

/*}}}  */
/*{{{  MA_SigArgMinusSigargs MA_makeSigArgMinusSigargsSingle(MA_SigArg head) */

MA_SigArgMinusSigargs MA_makeSigArgMinusSigargsSingle(MA_SigArg head)
{
  return (MA_SigArgMinusSigargs)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  MA_SigArgMinusSigargs MA_makeSigArgMinusSigargsMany(MA_SigArg head, MA_Layout wsMinusAfterMinusFirst, char * sep, MA_Layout wsMinusAfterMinusSep, MA_SigArgMinusSigargs tail) */

MA_SigArgMinusSigargs MA_makeSigArgMinusSigargsMany(MA_SigArg head, MA_Layout wsMinusAfterMinusFirst, char * sep, MA_Layout wsMinusAfterMinusSep, MA_SigArgMinusSigargs tail)
{
  return (MA_SigArgMinusSigargs)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm)wsMinusAfterMinusSep), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)))), (ATerm)wsMinusAfterMinusFirst), (ATerm)head);
}

/*}}}  */
/*{{{  MA_FuncDefList MA_makeFuncDefListDefault(MA_FuncDefMinusFuncdefs funcdefs) */

MA_FuncDefList MA_makeFuncDefListDefault(MA_FuncDefMinusFuncdefs funcdefs)
{
  return (MA_FuncDefList)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun30, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun34)), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun39))))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun40))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl1(MA_afun29, (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun30, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun34)), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun39))))), (ATerm)funcdefs)));
}

/*}}}  */
/*{{{  MA_FuncDefMinusFuncdefs MA_makeFuncDefMinusFuncdefsEmpty() */

MA_FuncDefMinusFuncdefs MA_makeFuncDefMinusFuncdefsEmpty()
{
  return (MA_FuncDefMinusFuncdefs)(ATerm)ATempty;
}

/*}}}  */
/*{{{  MA_FuncDefMinusFuncdefs MA_makeFuncDefMinusFuncdefsSingle(MA_FuncDef head) */

MA_FuncDefMinusFuncdefs MA_makeFuncDefMinusFuncdefsSingle(MA_FuncDef head)
{
  return (MA_FuncDefMinusFuncdefs)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  MA_FuncDefMinusFuncdefs MA_makeFuncDefMinusFuncdefsMany(MA_FuncDef head, MA_Layout wsMinusAfterMinusFirst, char * sep, MA_Layout wsMinusAfterMinusSep, MA_FuncDefMinusFuncdefs tail) */

MA_FuncDefMinusFuncdefs MA_makeFuncDefMinusFuncdefsMany(MA_FuncDef head, MA_Layout wsMinusAfterMinusFirst, char * sep, MA_Layout wsMinusAfterMinusSep, MA_FuncDefMinusFuncdefs tail)
{
  return (MA_FuncDefMinusFuncdefs)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm)wsMinusAfterMinusSep), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)))), (ATerm)wsMinusAfterMinusFirst), (ATerm)head);
}

/*}}}  */
/*{{{  MA_Rule MA_makeRuleNoMinusConds(MA_Term lhs, MA_Layout wsMinusAfterMinusLhs, MA_Layout wsMinusAfterMinusEquals, MA_Term rhs) */

MA_Rule MA_makeRuleNoMinusConds(MA_Term lhs, MA_Layout wsMinusAfterMinusLhs, MA_Layout wsMinusAfterMinusEquals, MA_Term rhs)
{
  return (MA_Rule)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun41))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun42))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)rhs), (ATerm)wsMinusAfterMinusEquals), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun41))), (ATerm)wsMinusAfterMinusLhs), (ATerm)lhs));
}

/*}}}  */
/*{{{  MA_Rule MA_makeRuleDefaultMinusNoMinusConds(MA_Layout wsMinusAfterMinusDefaultColon, MA_Term lhs, MA_Layout wsMinusAfterMinusLhs, MA_Layout wsMinusAfterMinusEquals, MA_Term rhs) */

MA_Rule MA_makeRuleDefaultMinusNoMinusConds(MA_Layout wsMinusAfterMinusDefaultColon, MA_Term lhs, MA_Layout wsMinusAfterMinusLhs, MA_Layout wsMinusAfterMinusEquals, MA_Term rhs)
{
  return (MA_Rule)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun41))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun43))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun42))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)rhs), (ATerm)wsMinusAfterMinusEquals), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun41))), (ATerm)wsMinusAfterMinusLhs), (ATerm)lhs), (ATerm)wsMinusAfterMinusDefaultColon), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun43))));
}

/*}}}  */
/*{{{  MA_Rule MA_makeRuleDefaultMinusWithMinusConds(MA_Layout wsMinusAfterMinusDefaultColon, MA_CondList conds, MA_Layout wsMinusAfterMinusConds, MA_Layout wsMinusAfterMinusImplies, MA_Term lhs, MA_Layout wsMinusAfterMinusLhs, MA_Layout wsMinusAfterMinusEquals, MA_Term rhs) */

MA_Rule MA_makeRuleDefaultMinusWithMinusConds(MA_Layout wsMinusAfterMinusDefaultColon, MA_CondList conds, MA_Layout wsMinusAfterMinusConds, MA_Layout wsMinusAfterMinusImplies, MA_Term lhs, MA_Layout wsMinusAfterMinusLhs, MA_Layout wsMinusAfterMinusEquals, MA_Term rhs)
{
  return (MA_Rule)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun41))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun44))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun45)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun43))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun42))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)rhs), (ATerm)wsMinusAfterMinusEquals), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun41))), (ATerm)wsMinusAfterMinusLhs), (ATerm)lhs), (ATerm)wsMinusAfterMinusImplies), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun44))), (ATerm)wsMinusAfterMinusConds), (ATerm)conds), (ATerm)wsMinusAfterMinusDefaultColon), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun43))));
}

/*}}}  */
/*{{{  MA_Rule MA_makeRuleWithMinusConds(MA_CondList conds, MA_Layout wsMinusAfterMinusConds, MA_Layout wsMinusAfterMinusImplies, MA_Term lhs, MA_Layout wsMinusAfterMinusLhs, MA_Layout wsMinusAfterMinusEquals, MA_Term rhs) */

MA_Rule MA_makeRuleWithMinusConds(MA_CondList conds, MA_Layout wsMinusAfterMinusConds, MA_Layout wsMinusAfterMinusImplies, MA_Term lhs, MA_Layout wsMinusAfterMinusLhs, MA_Layout wsMinusAfterMinusEquals, MA_Term rhs)
{
  return (MA_Rule)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun41))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun44))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun45)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun42))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)rhs), (ATerm)wsMinusAfterMinusEquals), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun41))), (ATerm)wsMinusAfterMinusLhs), (ATerm)lhs), (ATerm)wsMinusAfterMinusImplies), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun44))), (ATerm)wsMinusAfterMinusConds), (ATerm)conds));
}

/*}}}  */
/*{{{  MA_RuleList MA_makeRuleListDefault(MA_RuleMinusRules rules) */

MA_RuleList MA_makeRuleListDefault(MA_RuleMinusRules rules)
{
  return (MA_RuleList)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun30, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun42)), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun39))))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun46))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl1(MA_afun29, (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun30, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun42)), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun39))))), (ATerm)rules)));
}

/*}}}  */
/*{{{  MA_RuleMinusRules MA_makeRuleMinusRulesEmpty() */

MA_RuleMinusRules MA_makeRuleMinusRulesEmpty()
{
  return (MA_RuleMinusRules)(ATerm)ATempty;
}

/*}}}  */
/*{{{  MA_RuleMinusRules MA_makeRuleMinusRulesSingle(MA_Rule head) */

MA_RuleMinusRules MA_makeRuleMinusRulesSingle(MA_Rule head)
{
  return (MA_RuleMinusRules)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  MA_RuleMinusRules MA_makeRuleMinusRulesMany(MA_Rule head, MA_Layout wsMinusAfterMinusFirst, char * sep, MA_Layout wsMinusAfterMinusSep, MA_RuleMinusRules tail) */

MA_RuleMinusRules MA_makeRuleMinusRulesMany(MA_Rule head, MA_Layout wsMinusAfterMinusFirst, char * sep, MA_Layout wsMinusAfterMinusSep, MA_RuleMinusRules tail)
{
  return (MA_RuleMinusRules)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm)wsMinusAfterMinusSep), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)))), (ATerm)wsMinusAfterMinusFirst), (ATerm)head);
}

/*}}}  */
/*{{{  MA_CondList MA_makeCondListDefault(MA_CondMinusConds conds) */

MA_CondList MA_makeCondListDefault(MA_CondMinusConds conds)
{
  return (MA_CondList)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun30, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun47)), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun48))))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun45))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl1(MA_afun29, (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun30, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun47)), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun48))))), (ATerm)conds)));
}

/*}}}  */
/*{{{  MA_CondMinusConds MA_makeCondMinusCondsEmpty() */

MA_CondMinusConds MA_makeCondMinusCondsEmpty()
{
  return (MA_CondMinusConds)(ATerm)ATempty;
}

/*}}}  */
/*{{{  MA_CondMinusConds MA_makeCondMinusCondsSingle(MA_Cond head) */

MA_CondMinusConds MA_makeCondMinusCondsSingle(MA_Cond head)
{
  return (MA_CondMinusConds)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  MA_CondMinusConds MA_makeCondMinusCondsMany(MA_Cond head, MA_Layout wsMinusAfterMinusFirst, char * sep, MA_Layout wsMinusAfterMinusSep, MA_CondMinusConds tail) */

MA_CondMinusConds MA_makeCondMinusCondsMany(MA_Cond head, MA_Layout wsMinusAfterMinusFirst, char * sep, MA_Layout wsMinusAfterMinusSep, MA_CondMinusConds tail)
{
  return (MA_CondMinusConds)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm)wsMinusAfterMinusSep), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)))), (ATerm)wsMinusAfterMinusFirst), (ATerm)head);
}

/*}}}  */
/*{{{  MA_Cond MA_makeCondAssign(MA_Term lhs, MA_Layout wsMinusAfterMinusLhs, MA_Layout wsMinusAfterMinusAssign, MA_Term rhs) */

MA_Cond MA_makeCondAssign(MA_Term lhs, MA_Layout wsMinusAfterMinusLhs, MA_Layout wsMinusAfterMinusAssign, MA_Term rhs)
{
  return (MA_Cond)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun49))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun47))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)rhs), (ATerm)wsMinusAfterMinusAssign), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun49))), (ATerm)wsMinusAfterMinusLhs), (ATerm)lhs));
}

/*}}}  */
/*{{{  MA_Cond MA_makeCondEqual(MA_Term lhs, MA_Layout wsMinusAfterMinusLhs, MA_Layout wsMinusAfterMinusEqual, MA_Term rhs) */

MA_Cond MA_makeCondEqual(MA_Term lhs, MA_Layout wsMinusAfterMinusLhs, MA_Layout wsMinusAfterMinusEqual, MA_Term rhs)
{
  return (MA_Cond)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun50))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun47))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)rhs), (ATerm)wsMinusAfterMinusEqual), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun50))), (ATerm)wsMinusAfterMinusLhs), (ATerm)lhs));
}

/*}}}  */
/*{{{  MA_Cond MA_makeCondUnequal(MA_Term lhs, MA_Layout wsMinusAfterMinusLhs, MA_Layout wsMinusAfterMinusUnequal, MA_Term rhs) */

MA_Cond MA_makeCondUnequal(MA_Term lhs, MA_Layout wsMinusAfterMinusLhs, MA_Layout wsMinusAfterMinusUnequal, MA_Term rhs)
{
  return (MA_Cond)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun51))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun47))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)rhs), (ATerm)wsMinusAfterMinusUnequal), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun51))), (ATerm)wsMinusAfterMinusLhs), (ATerm)lhs));
}

/*}}}  */
/*{{{  MA_SignatureOpt MA_makeSignatureOptAbsent() */

MA_SignatureOpt MA_makeSignatureOptAbsent()
{
  return (MA_SignatureOpt)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATempty, (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun52))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATempty);
}

/*}}}  */
/*{{{  MA_SignatureOpt MA_makeSignatureOptPresent(MA_Layout wsMinusAfterMinusSignature, MA_FuncDefList funcdefs) */

MA_SignatureOpt MA_makeSignatureOptPresent(MA_Layout wsMinusAfterMinusSignature, MA_FuncDefList funcdefs)
{
  return (MA_SignatureOpt)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun40)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun53))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun52))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)funcdefs), (ATerm)wsMinusAfterMinusSignature), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun53))));
}

/*}}}  */
/*{{{  MA_RulesOpt MA_makeRulesOptAbsent() */

MA_RulesOpt MA_makeRulesOptAbsent()
{
  return (MA_RulesOpt)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATempty, (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun54))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATempty);
}

/*}}}  */
/*{{{  MA_RulesOpt MA_makeRulesOptPresent(MA_Layout wsMinusAfterMinusRules, MA_RuleList rules) */

MA_RulesOpt MA_makeRulesOptPresent(MA_Layout wsMinusAfterMinusRules, MA_RuleList rules)
{
  return (MA_RulesOpt)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun46)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun55))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun54))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)rules), (ATerm)wsMinusAfterMinusRules), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun55))));
}

/*}}}  */
/*{{{  MA_Module MA_makeModuleModule(MA_Layout wsMinusAfterMinusModule, MA_ModId id, MA_Layout wsMinusAfterMinusId, MA_SignatureOpt signature, MA_Layout wsMinusAfterMinusSignature, MA_RulesOpt rules) */

MA_Module MA_makeModuleModule(MA_Layout wsMinusAfterMinusModule, MA_ModId id, MA_Layout wsMinusAfterMinusId, MA_SignatureOpt signature, MA_Layout wsMinusAfterMinusSignature, MA_RulesOpt rules)
{
  return (MA_Module)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun54)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun52)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun56)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun57))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun58))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun23))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)rules), (ATerm)wsMinusAfterMinusSignature), (ATerm)signature), (ATerm)wsMinusAfterMinusId), (ATerm)id), (ATerm)wsMinusAfterMinusModule), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun57))));
}

/*}}}  */
/*{{{  MA_NamePair MA_makeNamePairDefault(MA_Layout wsMinusAfterMinusParenOpen, MA_FunId prod, MA_Layout wsMinusAfterMinusProd, MA_Layout wsMinusAfterMinusComma, MA_FunId func, MA_Layout wsMinusAfterMinusFunc, MA_TermMinusAttributes attributes, MA_Layout wsMinusAfterMinusAttributes) */

MA_NamePair MA_makeNamePairDefault(MA_Layout wsMinusAfterMinusParenOpen, MA_FunId prod, MA_Layout wsMinusAfterMinusProd, MA_Layout wsMinusAfterMinusComma, MA_FunId func, MA_Layout wsMinusAfterMinusFunc, MA_TermMinusAttributes attributes, MA_Layout wsMinusAfterMinusAttributes)
{
  return (MA_NamePair)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun15))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun30, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun26)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun26)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun16))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun59))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun60))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun15))), (ATerm)wsMinusAfterMinusAttributes), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl1(MA_afun29, (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun30, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun25)), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))))), (ATerm)attributes)), (ATerm)wsMinusAfterMinusComma), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))), (ATerm)wsMinusAfterMinusFunc), (ATerm)func), (ATerm)wsMinusAfterMinusComma), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))), (ATerm)wsMinusAfterMinusProd), (ATerm)prod), (ATerm)wsMinusAfterMinusParenOpen), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun16))));
}

/*}}}  */
/*{{{  MA_TermMinusAttributes MA_makeTermMinusAttributesEmpty() */

MA_TermMinusAttributes MA_makeTermMinusAttributesEmpty()
{
  return (MA_TermMinusAttributes)(ATerm)ATempty;
}

/*}}}  */
/*{{{  MA_TermMinusAttributes MA_makeTermMinusAttributesSingle(MA_Term head) */

MA_TermMinusAttributes MA_makeTermMinusAttributesSingle(MA_Term head)
{
  return (MA_TermMinusAttributes)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  MA_TermMinusAttributes MA_makeTermMinusAttributesMany(MA_Term head, MA_Layout wsMinusAfterMinusFirst, char * sep, MA_Layout wsMinusAfterMinusSep, MA_TermMinusAttributes tail) */

MA_TermMinusAttributes MA_makeTermMinusAttributesMany(MA_Term head, MA_Layout wsMinusAfterMinusFirst, char * sep, MA_Layout wsMinusAfterMinusSep, MA_TermMinusAttributes tail)
{
  return (MA_TermMinusAttributes)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm)wsMinusAfterMinusSep), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)))), (ATerm)wsMinusAfterMinusFirst), (ATerm)head);
}

/*}}}  */
/*{{{  MA_NameTable MA_makeNameTableDefault(MA_Layout wsMinusAfterMinusParenOpen, MA_NamePairMinusTable table, MA_Layout wsMinusAfterMinusTable, MA_Layout wsMinusAfterMinusComma, MA_FunId id, MA_Layout wsMinusAfterMinusId, MA_IntCon last, MA_Layout wsMinusAfterMinusLast, MA_IntCon prev, MA_Layout wsMinusAfterMinusPrev) */

MA_NameTable MA_makeNameTableDefault(MA_Layout wsMinusAfterMinusParenOpen, MA_NamePairMinusTable table, MA_Layout wsMinusAfterMinusTable, MA_Layout wsMinusAfterMinusComma, MA_FunId id, MA_Layout wsMinusAfterMinusId, MA_IntCon last, MA_Layout wsMinusAfterMinusLast, MA_IntCon prev, MA_Layout wsMinusAfterMinusPrev)
{
  return (MA_NameTable)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun15))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun26)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun30, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun59)), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun16))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun60))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun60))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun15))), (ATerm)wsMinusAfterMinusPrev), (ATerm)prev), (ATerm)wsMinusAfterMinusComma), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))), (ATerm)wsMinusAfterMinusLast), (ATerm)last), (ATerm)wsMinusAfterMinusComma), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))), (ATerm)wsMinusAfterMinusId), (ATerm)id), (ATerm)wsMinusAfterMinusComma), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))), (ATerm)wsMinusAfterMinusTable), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl1(MA_afun29, (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun30, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun59)), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))))), (ATerm)table)), (ATerm)wsMinusAfterMinusParenOpen), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun16))));
}

/*}}}  */
/*{{{  MA_NamePairMinusTable MA_makeNamePairMinusTableEmpty() */

MA_NamePairMinusTable MA_makeNamePairMinusTableEmpty()
{
  return (MA_NamePairMinusTable)(ATerm)ATempty;
}

/*}}}  */
/*{{{  MA_NamePairMinusTable MA_makeNamePairMinusTableSingle(MA_NamePair head) */

MA_NamePairMinusTable MA_makeNamePairMinusTableSingle(MA_NamePair head)
{
  return (MA_NamePairMinusTable)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  MA_NamePairMinusTable MA_makeNamePairMinusTableMany(MA_NamePair head, MA_Layout wsMinusAfterMinusFirst, char * sep, MA_Layout wsMinusAfterMinusSep, MA_NamePairMinusTable tail) */

MA_NamePairMinusTable MA_makeNamePairMinusTableMany(MA_NamePair head, MA_Layout wsMinusAfterMinusFirst, char * sep, MA_Layout wsMinusAfterMinusSep, MA_NamePairMinusTable tail)
{
  return (MA_NamePairMinusTable)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm)wsMinusAfterMinusSep), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)))), (ATerm)wsMinusAfterMinusFirst), (ATerm)head);
}

/*}}}  */
/*{{{  MA_MNMinusStruct MA_makeMNMinusStructDefault(MA_Layout wsMinusAfterMinusParenOpen, MA_Module mod, MA_Layout wsMinusAfterMinusMod, MA_Layout wsMinusAfterMinusComma, MA_NameTable nametable, MA_Layout wsMinusAfterMinusNametable) */

MA_MNMinusStruct MA_makeMNMinusStructDefault(MA_Layout wsMinusAfterMinusParenOpen, MA_Module mod, MA_Layout wsMinusAfterMinusMod, MA_Layout wsMinusAfterMinusComma, MA_NameTable nametable, MA_Layout wsMinusAfterMinusNametable)
{
  return (MA_MNMinusStruct)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun15))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun60)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun58)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)))), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun16))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun61))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun60))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun15))), (ATerm)wsMinusAfterMinusNametable), (ATerm)nametable), (ATerm)wsMinusAfterMinusComma), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))), (ATerm)wsMinusAfterMinusMod), (ATerm)mod), (ATerm)wsMinusAfterMinusParenOpen), (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun16))));
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

ATbool MA_isEqualTermMinusArgs(MA_TermMinusArgs arg0, MA_TermMinusArgs arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualTermList(MA_TermList arg0, MA_TermList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualTermMinusTerms(MA_TermMinusTerms arg0, MA_TermMinusTerms arg1)
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

ATbool MA_isEqualSigArgMinusArgs(MA_SigArgMinusArgs arg0, MA_SigArgMinusArgs arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualAnnotations(MA_Annotations arg0, MA_Annotations arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualSigArgList(MA_SigArgList arg0, MA_SigArgList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualSigArgMinusSigargs(MA_SigArgMinusSigargs arg0, MA_SigArgMinusSigargs arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualFuncDefList(MA_FuncDefList arg0, MA_FuncDefList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualFuncDefMinusFuncdefs(MA_FuncDefMinusFuncdefs arg0, MA_FuncDefMinusFuncdefs arg1)
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

ATbool MA_isEqualRuleMinusRules(MA_RuleMinusRules arg0, MA_RuleMinusRules arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualCondList(MA_CondList arg0, MA_CondList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualCondMinusConds(MA_CondMinusConds arg0, MA_CondMinusConds arg1)
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

ATbool MA_isEqualNamePair(MA_NamePair arg0, MA_NamePair arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualTermMinusAttributes(MA_TermMinusAttributes arg0, MA_TermMinusAttributes arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualNameTable(MA_NameTable arg0, MA_NameTable arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualNamePairMinusTable(MA_NamePairMinusTable arg0, MA_NamePairMinusTable arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualMNMinusStruct(MA_MNMinusStruct arg0, MA_MNMinusStruct arg1)
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
/*{{{  ATbool MA_hasIntWsMinusAfterMinusLhs(MA_Int arg) */

ATbool MA_hasIntWsMinusAfterMinusLhs(MA_Int arg)
{
  if (MA_isIntPlus(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getIntWsMinusAfterMinusLhs(MA_Int arg) */

MA_Layout MA_getIntWsMinusAfterMinusLhs(MA_Int arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_Int MA_setIntWsMinusAfterMinusLhs(MA_Int arg, MA_Layout wsMinusAfterMinusLhs) */

MA_Int MA_setIntWsMinusAfterMinusLhs(MA_Int arg, MA_Layout wsMinusAfterMinusLhs)
{
  if (MA_isIntPlus(arg)) {
    return (MA_Int)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusLhs, 1), 1);
  }

  ATabort("Int has no WsMinusAfterMinusLhs: %t\n", arg);
  return (MA_Int)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasIntWsMinusAfterMinusPlus(MA_Int arg) */

ATbool MA_hasIntWsMinusAfterMinusPlus(MA_Int arg)
{
  if (MA_isIntPlus(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getIntWsMinusAfterMinusPlus(MA_Int arg) */

MA_Layout MA_getIntWsMinusAfterMinusPlus(MA_Int arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  MA_Int MA_setIntWsMinusAfterMinusPlus(MA_Int arg, MA_Layout wsMinusAfterMinusPlus) */

MA_Int MA_setIntWsMinusAfterMinusPlus(MA_Int arg, MA_Layout wsMinusAfterMinusPlus)
{
  if (MA_isIntPlus(arg)) {
    return (MA_Int)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusPlus, 3), 1);
  }

  ATabort("Int has no WsMinusAfterMinusPlus: %t\n", arg);
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
/*{{{  ATbool MA_hasIntConWsMinusAfterMinusCon(MA_IntCon arg) */

ATbool MA_hasIntConWsMinusAfterMinusCon(MA_IntCon arg)
{
  if (MA_isIntConCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getIntConWsMinusAfterMinusCon(MA_IntCon arg) */

MA_Layout MA_getIntConWsMinusAfterMinusCon(MA_IntCon arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_IntCon MA_setIntConWsMinusAfterMinusCon(MA_IntCon arg, MA_Layout wsMinusAfterMinusCon) */

MA_IntCon MA_setIntConWsMinusAfterMinusCon(MA_IntCon arg, MA_Layout wsMinusAfterMinusCon)
{
  if (MA_isIntConCon(arg)) {
    return (MA_IntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusCon, 1), 1);
  }

  ATabort("IntCon has no WsMinusAfterMinusCon: %t\n", arg);
  return (MA_IntCon)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasIntConWsMinusAfterMinusParenOpen(MA_IntCon arg) */

ATbool MA_hasIntConWsMinusAfterMinusParenOpen(MA_IntCon arg)
{
  if (MA_isIntConCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getIntConWsMinusAfterMinusParenOpen(MA_IntCon arg) */

MA_Layout MA_getIntConWsMinusAfterMinusParenOpen(MA_IntCon arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  MA_IntCon MA_setIntConWsMinusAfterMinusParenOpen(MA_IntCon arg, MA_Layout wsMinusAfterMinusParenOpen) */

MA_IntCon MA_setIntConWsMinusAfterMinusParenOpen(MA_IntCon arg, MA_Layout wsMinusAfterMinusParenOpen)
{
  if (MA_isIntConCon(arg)) {
    return (MA_IntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusParenOpen, 3), 1);
  }

  ATabort("IntCon has no WsMinusAfterMinusParenOpen: %t\n", arg);
  return (MA_IntCon)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasIntConIntMinusArg(MA_IntCon arg) */

ATbool MA_hasIntConIntMinusArg(MA_IntCon arg)
{
  if (MA_isIntConCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Int MA_getIntConIntMinusArg(MA_IntCon arg) */

MA_Int MA_getIntConIntMinusArg(MA_IntCon arg)
{
  
    return (MA_Int)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  MA_IntCon MA_setIntConIntMinusArg(MA_IntCon arg, MA_Int intMinusArg) */

MA_IntCon MA_setIntConIntMinusArg(MA_IntCon arg, MA_Int intMinusArg)
{
  if (MA_isIntConCon(arg)) {
    return (MA_IntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)intMinusArg, 4), 1);
  }

  ATabort("IntCon has no IntMinusArg: %t\n", arg);
  return (MA_IntCon)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasIntConWsMinusAfterMinusIntMinusArg(MA_IntCon arg) */

ATbool MA_hasIntConWsMinusAfterMinusIntMinusArg(MA_IntCon arg)
{
  if (MA_isIntConCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getIntConWsMinusAfterMinusIntMinusArg(MA_IntCon arg) */

MA_Layout MA_getIntConWsMinusAfterMinusIntMinusArg(MA_IntCon arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  MA_IntCon MA_setIntConWsMinusAfterMinusIntMinusArg(MA_IntCon arg, MA_Layout wsMinusAfterMinusIntMinusArg) */

MA_IntCon MA_setIntConWsMinusAfterMinusIntMinusArg(MA_IntCon arg, MA_Layout wsMinusAfterMinusIntMinusArg)
{
  if (MA_isIntConCon(arg)) {
    return (MA_IntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusIntMinusArg, 5), 1);
  }

  ATabort("IntCon has no WsMinusAfterMinusIntMinusArg: %t\n", arg);
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
/*{{{  ATbool MA_hasIntConWsMinusAfterMinusPlus(MA_IntCon arg) */

ATbool MA_hasIntConWsMinusAfterMinusPlus(MA_IntCon arg)
{
  if (MA_isIntConPos(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getIntConWsMinusAfterMinusPlus(MA_IntCon arg) */

MA_Layout MA_getIntConWsMinusAfterMinusPlus(MA_IntCon arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_IntCon MA_setIntConWsMinusAfterMinusPlus(MA_IntCon arg, MA_Layout wsMinusAfterMinusPlus) */

MA_IntCon MA_setIntConWsMinusAfterMinusPlus(MA_IntCon arg, MA_Layout wsMinusAfterMinusPlus)
{
  if (MA_isIntConPos(arg)) {
    return (MA_IntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusPlus, 1), 1);
  }

  ATabort("IntCon has no WsMinusAfterMinusPlus: %t\n", arg);
  return (MA_IntCon)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasIntConNatMinusArg(MA_IntCon arg) */

ATbool MA_hasIntConNatMinusArg(MA_IntCon arg)
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
/*{{{  MA_NatCon MA_getIntConNatMinusArg(MA_IntCon arg) */

MA_NatCon MA_getIntConNatMinusArg(MA_IntCon arg)
{
  if (MA_isIntConPos(arg)) {
    return (MA_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else 
    return (MA_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  MA_IntCon MA_setIntConNatMinusArg(MA_IntCon arg, MA_NatCon natMinusArg) */

MA_IntCon MA_setIntConNatMinusArg(MA_IntCon arg, MA_NatCon natMinusArg)
{
  if (MA_isIntConPos(arg)) {
    return (MA_IntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)natMinusArg, 2), 1);
  }
  else if (MA_isIntConNeg(arg)) {
    return (MA_IntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)natMinusArg, 2), 1);
  }

  ATabort("IntCon has no NatMinusArg: %t\n", arg);
  return (MA_IntCon)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasIntConWsMinusAfterMinusMinus(MA_IntCon arg) */

ATbool MA_hasIntConWsMinusAfterMinusMinus(MA_IntCon arg)
{
  if (MA_isIntConNeg(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getIntConWsMinusAfterMinusMinus(MA_IntCon arg) */

MA_Layout MA_getIntConWsMinusAfterMinusMinus(MA_IntCon arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_IntCon MA_setIntConWsMinusAfterMinusMinus(MA_IntCon arg, MA_Layout wsMinusAfterMinusMinus) */

MA_IntCon MA_setIntConWsMinusAfterMinusMinus(MA_IntCon arg, MA_Layout wsMinusAfterMinusMinus)
{
  if (MA_isIntConNeg(arg)) {
    return (MA_IntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusMinus, 1), 1);
  }

  ATabort("IntCon has no WsMinusAfterMinusMinus: %t\n", arg);
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
/*{{{  ATbool MA_hasNatConWsMinusAfterMinusAbs(MA_NatCon arg) */

ATbool MA_hasNatConWsMinusAfterMinusAbs(MA_NatCon arg)
{
  if (MA_isNatConAbs(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getNatConWsMinusAfterMinusAbs(MA_NatCon arg) */

MA_Layout MA_getNatConWsMinusAfterMinusAbs(MA_NatCon arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_NatCon MA_setNatConWsMinusAfterMinusAbs(MA_NatCon arg, MA_Layout wsMinusAfterMinusAbs) */

MA_NatCon MA_setNatConWsMinusAfterMinusAbs(MA_NatCon arg, MA_Layout wsMinusAfterMinusAbs)
{
  if (MA_isNatConAbs(arg)) {
    return (MA_NatCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusAbs, 1), 1);
  }

  ATabort("NatCon has no WsMinusAfterMinusAbs: %t\n", arg);
  return (MA_NatCon)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasNatConWsMinusAfterMinusParenOpen(MA_NatCon arg) */

ATbool MA_hasNatConWsMinusAfterMinusParenOpen(MA_NatCon arg)
{
  if (MA_isNatConAbs(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getNatConWsMinusAfterMinusParenOpen(MA_NatCon arg) */

MA_Layout MA_getNatConWsMinusAfterMinusParenOpen(MA_NatCon arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  MA_NatCon MA_setNatConWsMinusAfterMinusParenOpen(MA_NatCon arg, MA_Layout wsMinusAfterMinusParenOpen) */

MA_NatCon MA_setNatConWsMinusAfterMinusParenOpen(MA_NatCon arg, MA_Layout wsMinusAfterMinusParenOpen)
{
  if (MA_isNatConAbs(arg)) {
    return (MA_NatCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusParenOpen, 3), 1);
  }

  ATabort("NatCon has no WsMinusAfterMinusParenOpen: %t\n", arg);
  return (MA_NatCon)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasNatConIntMinusArg(MA_NatCon arg) */

ATbool MA_hasNatConIntMinusArg(MA_NatCon arg)
{
  if (MA_isNatConAbs(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Int MA_getNatConIntMinusArg(MA_NatCon arg) */

MA_Int MA_getNatConIntMinusArg(MA_NatCon arg)
{
  
    return (MA_Int)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  MA_NatCon MA_setNatConIntMinusArg(MA_NatCon arg, MA_Int intMinusArg) */

MA_NatCon MA_setNatConIntMinusArg(MA_NatCon arg, MA_Int intMinusArg)
{
  if (MA_isNatConAbs(arg)) {
    return (MA_NatCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)intMinusArg, 4), 1);
  }

  ATabort("NatCon has no IntMinusArg: %t\n", arg);
  return (MA_NatCon)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasNatConWsMinusAfterMinusIntMinusArg(MA_NatCon arg) */

ATbool MA_hasNatConWsMinusAfterMinusIntMinusArg(MA_NatCon arg)
{
  if (MA_isNatConAbs(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getNatConWsMinusAfterMinusIntMinusArg(MA_NatCon arg) */

MA_Layout MA_getNatConWsMinusAfterMinusIntMinusArg(MA_NatCon arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  MA_NatCon MA_setNatConWsMinusAfterMinusIntMinusArg(MA_NatCon arg, MA_Layout wsMinusAfterMinusIntMinusArg) */

MA_NatCon MA_setNatConWsMinusAfterMinusIntMinusArg(MA_NatCon arg, MA_Layout wsMinusAfterMinusIntMinusArg)
{
  if (MA_isNatConAbs(arg)) {
    return (MA_NatCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusIntMinusArg, 5), 1);
  }

  ATabort("NatCon has no WsMinusAfterMinusIntMinusArg: %t\n", arg);
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
/*{{{  ATbool MA_hasVarWsMinusAfterMinusStar(MA_Var arg) */

ATbool MA_hasVarWsMinusAfterMinusStar(MA_Var arg)
{
  if (MA_isVarStar(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getVarWsMinusAfterMinusStar(MA_Var arg) */

MA_Layout MA_getVarWsMinusAfterMinusStar(MA_Var arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_Var MA_setVarWsMinusAfterMinusStar(MA_Var arg, MA_Layout wsMinusAfterMinusStar) */

MA_Var MA_setVarWsMinusAfterMinusStar(MA_Var arg, MA_Layout wsMinusAfterMinusStar)
{
  if (MA_isVarStar(arg)) {
    return (MA_Var)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusStar, 1), 1);
  }

  ATabort("Var has no WsMinusAfterMinusStar: %t\n", arg);
  return (MA_Var)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasVarWsMinusAfterMinusPlus(MA_Var arg) */

ATbool MA_hasVarWsMinusAfterMinusPlus(MA_Var arg)
{
  if (MA_isVarPlus(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getVarWsMinusAfterMinusPlus(MA_Var arg) */

MA_Layout MA_getVarWsMinusAfterMinusPlus(MA_Var arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_Var MA_setVarWsMinusAfterMinusPlus(MA_Var arg, MA_Layout wsMinusAfterMinusPlus) */

MA_Var MA_setVarWsMinusAfterMinusPlus(MA_Var arg, MA_Layout wsMinusAfterMinusPlus)
{
  if (MA_isVarPlus(arg)) {
    return (MA_Var)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusPlus, 1), 1);
  }

  ATabort("Var has no WsMinusAfterMinusPlus: %t\n", arg);
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
/*{{{  ATbool MA_hasTermWsMinusAfterMinusFunId(MA_Term arg) */

ATbool MA_hasTermWsMinusAfterMinusFunId(MA_Term arg)
{
  if (MA_isTermFunc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getTermWsMinusAfterMinusFunId(MA_Term arg) */

MA_Layout MA_getTermWsMinusAfterMinusFunId(MA_Term arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_Term MA_setTermWsMinusAfterMinusFunId(MA_Term arg, MA_Layout wsMinusAfterMinusFunId) */

MA_Term MA_setTermWsMinusAfterMinusFunId(MA_Term arg, MA_Layout wsMinusAfterMinusFunId)
{
  if (MA_isTermFunc(arg)) {
    return (MA_Term)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusFunId, 1), 1);
  }

  ATabort("Term has no WsMinusAfterMinusFunId: %t\n", arg);
  return (MA_Term)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasTermWsMinusAfterMinusParenOpen(MA_Term arg) */

ATbool MA_hasTermWsMinusAfterMinusParenOpen(MA_Term arg)
{
  if (MA_isTermFunc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getTermWsMinusAfterMinusParenOpen(MA_Term arg) */

MA_Layout MA_getTermWsMinusAfterMinusParenOpen(MA_Term arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  MA_Term MA_setTermWsMinusAfterMinusParenOpen(MA_Term arg, MA_Layout wsMinusAfterMinusParenOpen) */

MA_Term MA_setTermWsMinusAfterMinusParenOpen(MA_Term arg, MA_Layout wsMinusAfterMinusParenOpen)
{
  if (MA_isTermFunc(arg)) {
    return (MA_Term)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusParenOpen, 3), 1);
  }

  ATabort("Term has no WsMinusAfterMinusParenOpen: %t\n", arg);
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
/*{{{  MA_TermMinusArgs MA_getTermArgs(MA_Term arg) */

MA_TermMinusArgs MA_getTermArgs(MA_Term arg)
{
  
    return (MA_TermMinusArgs)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), 1);
}

/*}}}  */
/*{{{  MA_Term MA_setTermArgs(MA_Term arg, MA_TermMinusArgs args) */

MA_Term MA_setTermArgs(MA_Term arg, MA_TermMinusArgs args)
{
  if (MA_isTermFunc(arg)) {
    return (MA_Term)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), (ATerm)args, 1), 4), 1);
  }

  ATabort("Term has no Args: %t\n", arg);
  return (MA_Term)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasTermWsMinusAfterMinusArgs(MA_Term arg) */

ATbool MA_hasTermWsMinusAfterMinusArgs(MA_Term arg)
{
  if (MA_isTermFunc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getTermWsMinusAfterMinusArgs(MA_Term arg) */

MA_Layout MA_getTermWsMinusAfterMinusArgs(MA_Term arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  MA_Term MA_setTermWsMinusAfterMinusArgs(MA_Term arg, MA_Layout wsMinusAfterMinusArgs) */

MA_Term MA_setTermWsMinusAfterMinusArgs(MA_Term arg, MA_Layout wsMinusAfterMinusArgs)
{
  if (MA_isTermFunc(arg)) {
    return (MA_Term)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusArgs, 5), 1);
  }

  ATabort("Term has no WsMinusAfterMinusArgs: %t\n", arg);
  return (MA_Term)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_TermMinusArgs accessors */

/*{{{  ATbool MA_isValidTermMinusArgs(MA_TermMinusArgs arg) */

ATbool MA_isValidTermMinusArgs(MA_TermMinusArgs arg)
{
  if (MA_isTermMinusArgsSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isTermMinusArgsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isTermMinusArgsSingle(MA_TermMinusArgs arg) */

inline ATbool MA_isTermMinusArgsSingle(MA_TermMinusArgs arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternTermMinusArgsSingle, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isTermMinusArgsMany(MA_TermMinusArgs arg) */

inline ATbool MA_isTermMinusArgsMany(MA_TermMinusArgs arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternTermMinusArgsMany, NULL, NULL, NULL, NULL, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MA_hasTermMinusArgsHead(MA_TermMinusArgs arg) */

ATbool MA_hasTermMinusArgsHead(MA_TermMinusArgs arg)
{
  if (MA_isTermMinusArgsSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isTermMinusArgsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Term MA_getTermMinusArgsHead(MA_TermMinusArgs arg) */

MA_Term MA_getTermMinusArgsHead(MA_TermMinusArgs arg)
{
  if (MA_isTermMinusArgsSingle(arg)) {
    return (MA_Term)ATgetFirst((ATermList)arg);
  }
  else 
    return (MA_Term)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  MA_TermMinusArgs MA_setTermMinusArgsHead(MA_TermMinusArgs arg, MA_Term head) */

MA_TermMinusArgs MA_setTermMinusArgsHead(MA_TermMinusArgs arg, MA_Term head)
{
  if (MA_isTermMinusArgsSingle(arg)) {
    return (MA_TermMinusArgs)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (MA_isTermMinusArgsMany(arg)) {
    return (MA_TermMinusArgs)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("TermMinusArgs has no Head: %t\n", arg);
  return (MA_TermMinusArgs)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasTermMinusArgsWsMinusAfterMinusFirst(MA_TermMinusArgs arg) */

ATbool MA_hasTermMinusArgsWsMinusAfterMinusFirst(MA_TermMinusArgs arg)
{
  if (MA_isTermMinusArgsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getTermMinusArgsWsMinusAfterMinusFirst(MA_TermMinusArgs arg) */

MA_Layout MA_getTermMinusArgsWsMinusAfterMinusFirst(MA_TermMinusArgs arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  MA_TermMinusArgs MA_setTermMinusArgsWsMinusAfterMinusFirst(MA_TermMinusArgs arg, MA_Layout wsMinusAfterMinusFirst) */

MA_TermMinusArgs MA_setTermMinusArgsWsMinusAfterMinusFirst(MA_TermMinusArgs arg, MA_Layout wsMinusAfterMinusFirst)
{
  if (MA_isTermMinusArgsMany(arg)) {
    return (MA_TermMinusArgs)ATreplace((ATermList)arg, (ATerm)wsMinusAfterMinusFirst, 1);
  }

  ATabort("TermMinusArgs has no WsMinusAfterMinusFirst: %t\n", arg);
  return (MA_TermMinusArgs)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasTermMinusArgsSep(MA_TermMinusArgs arg) */

ATbool MA_hasTermMinusArgsSep(MA_TermMinusArgs arg)
{
  if (MA_isTermMinusArgsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * MA_getTermMinusArgsSep(MA_TermMinusArgs arg) */

char * MA_getTermMinusArgsSep(MA_TermMinusArgs arg)
{
  
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), 0)));
}

/*}}}  */
/*{{{  MA_TermMinusArgs MA_setTermMinusArgsSep(MA_TermMinusArgs arg, char * sep) */

MA_TermMinusArgs MA_setTermMinusArgsSep(MA_TermMinusArgs arg, char * sep)
{
  if (MA_isTermMinusArgsMany(arg)) {
    return (MA_TermMinusArgs)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)), 0), 2);
  }

  ATabort("TermMinusArgs has no Sep: %t\n", arg);
  return (MA_TermMinusArgs)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasTermMinusArgsWsMinusAfterMinusSep(MA_TermMinusArgs arg) */

ATbool MA_hasTermMinusArgsWsMinusAfterMinusSep(MA_TermMinusArgs arg)
{
  if (MA_isTermMinusArgsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getTermMinusArgsWsMinusAfterMinusSep(MA_TermMinusArgs arg) */

MA_Layout MA_getTermMinusArgsWsMinusAfterMinusSep(MA_TermMinusArgs arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  MA_TermMinusArgs MA_setTermMinusArgsWsMinusAfterMinusSep(MA_TermMinusArgs arg, MA_Layout wsMinusAfterMinusSep) */

MA_TermMinusArgs MA_setTermMinusArgsWsMinusAfterMinusSep(MA_TermMinusArgs arg, MA_Layout wsMinusAfterMinusSep)
{
  if (MA_isTermMinusArgsMany(arg)) {
    return (MA_TermMinusArgs)ATreplace((ATermList)arg, (ATerm)wsMinusAfterMinusSep, 3);
  }

  ATabort("TermMinusArgs has no WsMinusAfterMinusSep: %t\n", arg);
  return (MA_TermMinusArgs)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasTermMinusArgsTail(MA_TermMinusArgs arg) */

ATbool MA_hasTermMinusArgsTail(MA_TermMinusArgs arg)
{
  if (MA_isTermMinusArgsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_TermMinusArgs MA_getTermMinusArgsTail(MA_TermMinusArgs arg) */

MA_TermMinusArgs MA_getTermMinusArgsTail(MA_TermMinusArgs arg)
{
  
    return (MA_TermMinusArgs)ATgetTail((ATermList)arg, 4);
}

/*}}}  */
/*{{{  MA_TermMinusArgs MA_setTermMinusArgsTail(MA_TermMinusArgs arg, MA_TermMinusArgs tail) */

MA_TermMinusArgs MA_setTermMinusArgsTail(MA_TermMinusArgs arg, MA_TermMinusArgs tail)
{
  if (MA_isTermMinusArgsMany(arg)) {
    return (MA_TermMinusArgs)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("TermMinusArgs has no Tail: %t\n", arg);
  return (MA_TermMinusArgs)NULL;
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
/*{{{  ATbool MA_hasTermListTerms(MA_TermList arg) */

ATbool MA_hasTermListTerms(MA_TermList arg)
{
  if (MA_isTermListDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_TermMinusTerms MA_getTermListTerms(MA_TermList arg) */

MA_TermMinusTerms MA_getTermListTerms(MA_TermList arg)
{
  
    return (MA_TermMinusTerms)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  MA_TermList MA_setTermListTerms(MA_TermList arg, MA_TermMinusTerms terms) */

MA_TermList MA_setTermListTerms(MA_TermList arg, MA_TermMinusTerms terms)
{
  if (MA_isTermListDefault(arg)) {
    return (MA_TermList)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)terms, 1), 0), 1);
  }

  ATabort("TermList has no Terms: %t\n", arg);
  return (MA_TermList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_TermMinusTerms accessors */

/*{{{  ATbool MA_isValidTermMinusTerms(MA_TermMinusTerms arg) */

ATbool MA_isValidTermMinusTerms(MA_TermMinusTerms arg)
{
  if (MA_isTermMinusTermsEmpty(arg)) {
    return ATtrue;
  }
  else if (MA_isTermMinusTermsSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isTermMinusTermsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isTermMinusTermsEmpty(MA_TermMinusTerms arg) */

inline ATbool MA_isTermMinusTermsEmpty(MA_TermMinusTerms arg)
{
  return ATmatchTerm((ATerm)arg, MA_patternTermMinusTermsEmpty);
}

/*}}}  */
/*{{{  inline ATbool MA_isTermMinusTermsSingle(MA_TermMinusTerms arg) */

inline ATbool MA_isTermMinusTermsSingle(MA_TermMinusTerms arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternTermMinusTermsSingle, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isTermMinusTermsMany(MA_TermMinusTerms arg) */

inline ATbool MA_isTermMinusTermsMany(MA_TermMinusTerms arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternTermMinusTermsMany, NULL, NULL, NULL, NULL, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MA_hasTermMinusTermsHead(MA_TermMinusTerms arg) */

ATbool MA_hasTermMinusTermsHead(MA_TermMinusTerms arg)
{
  if (MA_isTermMinusTermsSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isTermMinusTermsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Term MA_getTermMinusTermsHead(MA_TermMinusTerms arg) */

MA_Term MA_getTermMinusTermsHead(MA_TermMinusTerms arg)
{
  if (MA_isTermMinusTermsSingle(arg)) {
    return (MA_Term)ATgetFirst((ATermList)arg);
  }
  else 
    return (MA_Term)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  MA_TermMinusTerms MA_setTermMinusTermsHead(MA_TermMinusTerms arg, MA_Term head) */

MA_TermMinusTerms MA_setTermMinusTermsHead(MA_TermMinusTerms arg, MA_Term head)
{
  if (MA_isTermMinusTermsSingle(arg)) {
    return (MA_TermMinusTerms)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (MA_isTermMinusTermsMany(arg)) {
    return (MA_TermMinusTerms)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("TermMinusTerms has no Head: %t\n", arg);
  return (MA_TermMinusTerms)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasTermMinusTermsWsMinusAfterMinusFirst(MA_TermMinusTerms arg) */

ATbool MA_hasTermMinusTermsWsMinusAfterMinusFirst(MA_TermMinusTerms arg)
{
  if (MA_isTermMinusTermsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getTermMinusTermsWsMinusAfterMinusFirst(MA_TermMinusTerms arg) */

MA_Layout MA_getTermMinusTermsWsMinusAfterMinusFirst(MA_TermMinusTerms arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  MA_TermMinusTerms MA_setTermMinusTermsWsMinusAfterMinusFirst(MA_TermMinusTerms arg, MA_Layout wsMinusAfterMinusFirst) */

MA_TermMinusTerms MA_setTermMinusTermsWsMinusAfterMinusFirst(MA_TermMinusTerms arg, MA_Layout wsMinusAfterMinusFirst)
{
  if (MA_isTermMinusTermsMany(arg)) {
    return (MA_TermMinusTerms)ATreplace((ATermList)arg, (ATerm)wsMinusAfterMinusFirst, 1);
  }

  ATabort("TermMinusTerms has no WsMinusAfterMinusFirst: %t\n", arg);
  return (MA_TermMinusTerms)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasTermMinusTermsSep(MA_TermMinusTerms arg) */

ATbool MA_hasTermMinusTermsSep(MA_TermMinusTerms arg)
{
  if (MA_isTermMinusTermsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * MA_getTermMinusTermsSep(MA_TermMinusTerms arg) */

char * MA_getTermMinusTermsSep(MA_TermMinusTerms arg)
{
  
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), 0)));
}

/*}}}  */
/*{{{  MA_TermMinusTerms MA_setTermMinusTermsSep(MA_TermMinusTerms arg, char * sep) */

MA_TermMinusTerms MA_setTermMinusTermsSep(MA_TermMinusTerms arg, char * sep)
{
  if (MA_isTermMinusTermsMany(arg)) {
    return (MA_TermMinusTerms)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)), 0), 2);
  }

  ATabort("TermMinusTerms has no Sep: %t\n", arg);
  return (MA_TermMinusTerms)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasTermMinusTermsWsMinusAfterMinusSep(MA_TermMinusTerms arg) */

ATbool MA_hasTermMinusTermsWsMinusAfterMinusSep(MA_TermMinusTerms arg)
{
  if (MA_isTermMinusTermsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getTermMinusTermsWsMinusAfterMinusSep(MA_TermMinusTerms arg) */

MA_Layout MA_getTermMinusTermsWsMinusAfterMinusSep(MA_TermMinusTerms arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  MA_TermMinusTerms MA_setTermMinusTermsWsMinusAfterMinusSep(MA_TermMinusTerms arg, MA_Layout wsMinusAfterMinusSep) */

MA_TermMinusTerms MA_setTermMinusTermsWsMinusAfterMinusSep(MA_TermMinusTerms arg, MA_Layout wsMinusAfterMinusSep)
{
  if (MA_isTermMinusTermsMany(arg)) {
    return (MA_TermMinusTerms)ATreplace((ATermList)arg, (ATerm)wsMinusAfterMinusSep, 3);
  }

  ATabort("TermMinusTerms has no WsMinusAfterMinusSep: %t\n", arg);
  return (MA_TermMinusTerms)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasTermMinusTermsTail(MA_TermMinusTerms arg) */

ATbool MA_hasTermMinusTermsTail(MA_TermMinusTerms arg)
{
  if (MA_isTermMinusTermsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_TermMinusTerms MA_getTermMinusTermsTail(MA_TermMinusTerms arg) */

MA_TermMinusTerms MA_getTermMinusTermsTail(MA_TermMinusTerms arg)
{
  
    return (MA_TermMinusTerms)ATgetTail((ATermList)arg, 4);
}

/*}}}  */
/*{{{  MA_TermMinusTerms MA_setTermMinusTermsTail(MA_TermMinusTerms arg, MA_TermMinusTerms tail) */

MA_TermMinusTerms MA_setTermMinusTermsTail(MA_TermMinusTerms arg, MA_TermMinusTerms tail)
{
  if (MA_isTermMinusTermsMany(arg)) {
    return (MA_TermMinusTerms)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("TermMinusTerms has no Tail: %t\n", arg);
  return (MA_TermMinusTerms)NULL;
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
/*{{{  ATbool MA_hasSigArgWsMinusAfterMinusUnderscore(MA_SigArg arg) */

ATbool MA_hasSigArgWsMinusAfterMinusUnderscore(MA_SigArg arg)
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
/*{{{  MA_Layout MA_getSigArgWsMinusAfterMinusUnderscore(MA_SigArg arg) */

MA_Layout MA_getSigArgWsMinusAfterMinusUnderscore(MA_SigArg arg)
{
  if (MA_isSigArgStar(arg)) {
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else 
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_SigArg MA_setSigArgWsMinusAfterMinusUnderscore(MA_SigArg arg, MA_Layout wsMinusAfterMinusUnderscore) */

MA_SigArg MA_setSigArgWsMinusAfterMinusUnderscore(MA_SigArg arg, MA_Layout wsMinusAfterMinusUnderscore)
{
  if (MA_isSigArgStar(arg)) {
    return (MA_SigArg)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusUnderscore, 1), 1);
  }
  else if (MA_isSigArgPlus(arg)) {
    return (MA_SigArg)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusUnderscore, 1), 1);
  }

  ATabort("SigArg has no WsMinusAfterMinusUnderscore: %t\n", arg);
  return (MA_SigArg)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_FuncDef accessors */

/*{{{  ATbool MA_isValidFuncDef(MA_FuncDef arg) */

ATbool MA_isValidFuncDef(MA_FuncDef arg)
{
  if (MA_isFuncDefConstantMinusNoMinusAnnos(arg)) {
    return ATtrue;
  }
  else if (MA_isFuncDefConstantMinusWithMinusAnnos(arg)) {
    return ATtrue;
  }
  else if (MA_isFuncDefFuncMinusNoMinusAnnos(arg)) {
    return ATtrue;
  }
  else if (MA_isFuncDefFuncMinusWithMinusAnnos(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isFuncDefConstantMinusNoMinusAnnos(MA_FuncDef arg) */

inline ATbool MA_isFuncDefConstantMinusNoMinusAnnos(MA_FuncDef arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternFuncDefConstantMinusNoMinusAnnos, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isFuncDefConstantMinusWithMinusAnnos(MA_FuncDef arg) */

inline ATbool MA_isFuncDefConstantMinusWithMinusAnnos(MA_FuncDef arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternFuncDefConstantMinusWithMinusAnnos, NULL, NULL, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isFuncDefFuncMinusNoMinusAnnos(MA_FuncDef arg) */

inline ATbool MA_isFuncDefFuncMinusNoMinusAnnos(MA_FuncDef arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternFuncDefFuncMinusNoMinusAnnos, NULL, NULL, NULL, NULL, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isFuncDefFuncMinusWithMinusAnnos(MA_FuncDef arg) */

inline ATbool MA_isFuncDefFuncMinusWithMinusAnnos(MA_FuncDef arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternFuncDefFuncMinusWithMinusAnnos, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MA_hasFuncDefFunId(MA_FuncDef arg) */

ATbool MA_hasFuncDefFunId(MA_FuncDef arg)
{
  if (MA_isFuncDefConstantMinusNoMinusAnnos(arg)) {
    return ATtrue;
  }
  else if (MA_isFuncDefConstantMinusWithMinusAnnos(arg)) {
    return ATtrue;
  }
  else if (MA_isFuncDefFuncMinusNoMinusAnnos(arg)) {
    return ATtrue;
  }
  else if (MA_isFuncDefFuncMinusWithMinusAnnos(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_FunId MA_getFuncDefFunId(MA_FuncDef arg) */

MA_FunId MA_getFuncDefFunId(MA_FuncDef arg)
{
  if (MA_isFuncDefConstantMinusNoMinusAnnos(arg)) {
    return (MA_FunId)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (MA_isFuncDefConstantMinusWithMinusAnnos(arg)) {
    return (MA_FunId)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (MA_isFuncDefFuncMinusNoMinusAnnos(arg)) {
    return (MA_FunId)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (MA_FunId)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  MA_FuncDef MA_setFuncDefFunId(MA_FuncDef arg, MA_FunId FunId) */

MA_FuncDef MA_setFuncDefFunId(MA_FuncDef arg, MA_FunId FunId)
{
  if (MA_isFuncDefConstantMinusNoMinusAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)FunId, 0), 1);
  }
  else if (MA_isFuncDefConstantMinusWithMinusAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)FunId, 0), 1);
  }
  else if (MA_isFuncDefFuncMinusNoMinusAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)FunId, 0), 1);
  }
  else if (MA_isFuncDefFuncMinusWithMinusAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)FunId, 0), 1);
  }

  ATabort("FuncDef has no FunId: %t\n", arg);
  return (MA_FuncDef)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasFuncDefWsMinusAfterMinusFunId(MA_FuncDef arg) */

ATbool MA_hasFuncDefWsMinusAfterMinusFunId(MA_FuncDef arg)
{
  if (MA_isFuncDefConstantMinusWithMinusAnnos(arg)) {
    return ATtrue;
  }
  else if (MA_isFuncDefFuncMinusNoMinusAnnos(arg)) {
    return ATtrue;
  }
  else if (MA_isFuncDefFuncMinusWithMinusAnnos(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getFuncDefWsMinusAfterMinusFunId(MA_FuncDef arg) */

MA_Layout MA_getFuncDefWsMinusAfterMinusFunId(MA_FuncDef arg)
{
  if (MA_isFuncDefConstantMinusWithMinusAnnos(arg)) {
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else if (MA_isFuncDefFuncMinusNoMinusAnnos(arg)) {
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else 
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_FuncDef MA_setFuncDefWsMinusAfterMinusFunId(MA_FuncDef arg, MA_Layout wsMinusAfterMinusFunId) */

MA_FuncDef MA_setFuncDefWsMinusAfterMinusFunId(MA_FuncDef arg, MA_Layout wsMinusAfterMinusFunId)
{
  if (MA_isFuncDefConstantMinusWithMinusAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusFunId, 1), 1);
  }
  else if (MA_isFuncDefFuncMinusNoMinusAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusFunId, 1), 1);
  }
  else if (MA_isFuncDefFuncMinusWithMinusAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusFunId, 1), 1);
  }

  ATabort("FuncDef has no WsMinusAfterMinusFunId: %t\n", arg);
  return (MA_FuncDef)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasFuncDefAnnos(MA_FuncDef arg) */

ATbool MA_hasFuncDefAnnos(MA_FuncDef arg)
{
  if (MA_isFuncDefConstantMinusWithMinusAnnos(arg)) {
    return ATtrue;
  }
  else if (MA_isFuncDefFuncMinusWithMinusAnnos(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Annotations MA_getFuncDefAnnos(MA_FuncDef arg) */

MA_Annotations MA_getFuncDefAnnos(MA_FuncDef arg)
{
  if (MA_isFuncDefConstantMinusWithMinusAnnos(arg)) {
    return (MA_Annotations)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else 
    return (MA_Annotations)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/*}}}  */
/*{{{  MA_FuncDef MA_setFuncDefAnnos(MA_FuncDef arg, MA_Annotations annos) */

MA_FuncDef MA_setFuncDefAnnos(MA_FuncDef arg, MA_Annotations annos)
{
  if (MA_isFuncDefConstantMinusWithMinusAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)annos, 2), 1);
  }
  else if (MA_isFuncDefFuncMinusWithMinusAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)annos, 8), 1);
  }

  ATabort("FuncDef has no Annos: %t\n", arg);
  return (MA_FuncDef)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasFuncDefWsMinusAfterMinusParenOpen(MA_FuncDef arg) */

ATbool MA_hasFuncDefWsMinusAfterMinusParenOpen(MA_FuncDef arg)
{
  if (MA_isFuncDefFuncMinusNoMinusAnnos(arg)) {
    return ATtrue;
  }
  else if (MA_isFuncDefFuncMinusWithMinusAnnos(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getFuncDefWsMinusAfterMinusParenOpen(MA_FuncDef arg) */

MA_Layout MA_getFuncDefWsMinusAfterMinusParenOpen(MA_FuncDef arg)
{
  if (MA_isFuncDefFuncMinusNoMinusAnnos(arg)) {
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  MA_FuncDef MA_setFuncDefWsMinusAfterMinusParenOpen(MA_FuncDef arg, MA_Layout wsMinusAfterMinusParenOpen) */

MA_FuncDef MA_setFuncDefWsMinusAfterMinusParenOpen(MA_FuncDef arg, MA_Layout wsMinusAfterMinusParenOpen)
{
  if (MA_isFuncDefFuncMinusNoMinusAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusParenOpen, 3), 1);
  }
  else if (MA_isFuncDefFuncMinusWithMinusAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusParenOpen, 3), 1);
  }

  ATabort("FuncDef has no WsMinusAfterMinusParenOpen: %t\n", arg);
  return (MA_FuncDef)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasFuncDefArgs(MA_FuncDef arg) */

ATbool MA_hasFuncDefArgs(MA_FuncDef arg)
{
  if (MA_isFuncDefFuncMinusNoMinusAnnos(arg)) {
    return ATtrue;
  }
  else if (MA_isFuncDefFuncMinusWithMinusAnnos(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_SigArgMinusArgs MA_getFuncDefArgs(MA_FuncDef arg) */

MA_SigArgMinusArgs MA_getFuncDefArgs(MA_FuncDef arg)
{
  if (MA_isFuncDefFuncMinusNoMinusAnnos(arg)) {
    return (MA_SigArgMinusArgs)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), 1);
  }
  else 
    return (MA_SigArgMinusArgs)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), 1);
}

/*}}}  */
/*{{{  MA_FuncDef MA_setFuncDefArgs(MA_FuncDef arg, MA_SigArgMinusArgs args) */

MA_FuncDef MA_setFuncDefArgs(MA_FuncDef arg, MA_SigArgMinusArgs args)
{
  if (MA_isFuncDefFuncMinusNoMinusAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), (ATerm)args, 1), 4), 1);
  }
  else if (MA_isFuncDefFuncMinusWithMinusAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), (ATerm)args, 1), 4), 1);
  }

  ATabort("FuncDef has no Args: %t\n", arg);
  return (MA_FuncDef)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasFuncDefWsMinusAfterMinusArgs(MA_FuncDef arg) */

ATbool MA_hasFuncDefWsMinusAfterMinusArgs(MA_FuncDef arg)
{
  if (MA_isFuncDefFuncMinusNoMinusAnnos(arg)) {
    return ATtrue;
  }
  else if (MA_isFuncDefFuncMinusWithMinusAnnos(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getFuncDefWsMinusAfterMinusArgs(MA_FuncDef arg) */

MA_Layout MA_getFuncDefWsMinusAfterMinusArgs(MA_FuncDef arg)
{
  if (MA_isFuncDefFuncMinusNoMinusAnnos(arg)) {
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else 
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  MA_FuncDef MA_setFuncDefWsMinusAfterMinusArgs(MA_FuncDef arg, MA_Layout wsMinusAfterMinusArgs) */

MA_FuncDef MA_setFuncDefWsMinusAfterMinusArgs(MA_FuncDef arg, MA_Layout wsMinusAfterMinusArgs)
{
  if (MA_isFuncDefFuncMinusNoMinusAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusArgs, 5), 1);
  }
  else if (MA_isFuncDefFuncMinusWithMinusAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusArgs, 5), 1);
  }

  ATabort("FuncDef has no WsMinusAfterMinusArgs: %t\n", arg);
  return (MA_FuncDef)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasFuncDefWsMinusAfterMinusParenClose(MA_FuncDef arg) */

ATbool MA_hasFuncDefWsMinusAfterMinusParenClose(MA_FuncDef arg)
{
  if (MA_isFuncDefFuncMinusWithMinusAnnos(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getFuncDefWsMinusAfterMinusParenClose(MA_FuncDef arg) */

MA_Layout MA_getFuncDefWsMinusAfterMinusParenClose(MA_FuncDef arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  MA_FuncDef MA_setFuncDefWsMinusAfterMinusParenClose(MA_FuncDef arg, MA_Layout wsMinusAfterMinusParenClose) */

MA_FuncDef MA_setFuncDefWsMinusAfterMinusParenClose(MA_FuncDef arg, MA_Layout wsMinusAfterMinusParenClose)
{
  if (MA_isFuncDefFuncMinusWithMinusAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusParenClose, 7), 1);
  }

  ATabort("FuncDef has no WsMinusAfterMinusParenClose: %t\n", arg);
  return (MA_FuncDef)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_SigArgMinusArgs accessors */

/*{{{  ATbool MA_isValidSigArgMinusArgs(MA_SigArgMinusArgs arg) */

ATbool MA_isValidSigArgMinusArgs(MA_SigArgMinusArgs arg)
{
  if (MA_isSigArgMinusArgsSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isSigArgMinusArgsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isSigArgMinusArgsSingle(MA_SigArgMinusArgs arg) */

inline ATbool MA_isSigArgMinusArgsSingle(MA_SigArgMinusArgs arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternSigArgMinusArgsSingle, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isSigArgMinusArgsMany(MA_SigArgMinusArgs arg) */

inline ATbool MA_isSigArgMinusArgsMany(MA_SigArgMinusArgs arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternSigArgMinusArgsMany, NULL, NULL, NULL, NULL, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MA_hasSigArgMinusArgsHead(MA_SigArgMinusArgs arg) */

ATbool MA_hasSigArgMinusArgsHead(MA_SigArgMinusArgs arg)
{
  if (MA_isSigArgMinusArgsSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isSigArgMinusArgsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_SigArg MA_getSigArgMinusArgsHead(MA_SigArgMinusArgs arg) */

MA_SigArg MA_getSigArgMinusArgsHead(MA_SigArgMinusArgs arg)
{
  if (MA_isSigArgMinusArgsSingle(arg)) {
    return (MA_SigArg)ATgetFirst((ATermList)arg);
  }
  else 
    return (MA_SigArg)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  MA_SigArgMinusArgs MA_setSigArgMinusArgsHead(MA_SigArgMinusArgs arg, MA_SigArg head) */

MA_SigArgMinusArgs MA_setSigArgMinusArgsHead(MA_SigArgMinusArgs arg, MA_SigArg head)
{
  if (MA_isSigArgMinusArgsSingle(arg)) {
    return (MA_SigArgMinusArgs)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (MA_isSigArgMinusArgsMany(arg)) {
    return (MA_SigArgMinusArgs)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("SigArgMinusArgs has no Head: %t\n", arg);
  return (MA_SigArgMinusArgs)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasSigArgMinusArgsWsMinusAfterMinusFirst(MA_SigArgMinusArgs arg) */

ATbool MA_hasSigArgMinusArgsWsMinusAfterMinusFirst(MA_SigArgMinusArgs arg)
{
  if (MA_isSigArgMinusArgsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getSigArgMinusArgsWsMinusAfterMinusFirst(MA_SigArgMinusArgs arg) */

MA_Layout MA_getSigArgMinusArgsWsMinusAfterMinusFirst(MA_SigArgMinusArgs arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  MA_SigArgMinusArgs MA_setSigArgMinusArgsWsMinusAfterMinusFirst(MA_SigArgMinusArgs arg, MA_Layout wsMinusAfterMinusFirst) */

MA_SigArgMinusArgs MA_setSigArgMinusArgsWsMinusAfterMinusFirst(MA_SigArgMinusArgs arg, MA_Layout wsMinusAfterMinusFirst)
{
  if (MA_isSigArgMinusArgsMany(arg)) {
    return (MA_SigArgMinusArgs)ATreplace((ATermList)arg, (ATerm)wsMinusAfterMinusFirst, 1);
  }

  ATabort("SigArgMinusArgs has no WsMinusAfterMinusFirst: %t\n", arg);
  return (MA_SigArgMinusArgs)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasSigArgMinusArgsSep(MA_SigArgMinusArgs arg) */

ATbool MA_hasSigArgMinusArgsSep(MA_SigArgMinusArgs arg)
{
  if (MA_isSigArgMinusArgsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * MA_getSigArgMinusArgsSep(MA_SigArgMinusArgs arg) */

char * MA_getSigArgMinusArgsSep(MA_SigArgMinusArgs arg)
{
  
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), 0)));
}

/*}}}  */
/*{{{  MA_SigArgMinusArgs MA_setSigArgMinusArgsSep(MA_SigArgMinusArgs arg, char * sep) */

MA_SigArgMinusArgs MA_setSigArgMinusArgsSep(MA_SigArgMinusArgs arg, char * sep)
{
  if (MA_isSigArgMinusArgsMany(arg)) {
    return (MA_SigArgMinusArgs)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)), 0), 2);
  }

  ATabort("SigArgMinusArgs has no Sep: %t\n", arg);
  return (MA_SigArgMinusArgs)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasSigArgMinusArgsWsMinusAfterMinusSep(MA_SigArgMinusArgs arg) */

ATbool MA_hasSigArgMinusArgsWsMinusAfterMinusSep(MA_SigArgMinusArgs arg)
{
  if (MA_isSigArgMinusArgsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getSigArgMinusArgsWsMinusAfterMinusSep(MA_SigArgMinusArgs arg) */

MA_Layout MA_getSigArgMinusArgsWsMinusAfterMinusSep(MA_SigArgMinusArgs arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  MA_SigArgMinusArgs MA_setSigArgMinusArgsWsMinusAfterMinusSep(MA_SigArgMinusArgs arg, MA_Layout wsMinusAfterMinusSep) */

MA_SigArgMinusArgs MA_setSigArgMinusArgsWsMinusAfterMinusSep(MA_SigArgMinusArgs arg, MA_Layout wsMinusAfterMinusSep)
{
  if (MA_isSigArgMinusArgsMany(arg)) {
    return (MA_SigArgMinusArgs)ATreplace((ATermList)arg, (ATerm)wsMinusAfterMinusSep, 3);
  }

  ATabort("SigArgMinusArgs has no WsMinusAfterMinusSep: %t\n", arg);
  return (MA_SigArgMinusArgs)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasSigArgMinusArgsTail(MA_SigArgMinusArgs arg) */

ATbool MA_hasSigArgMinusArgsTail(MA_SigArgMinusArgs arg)
{
  if (MA_isSigArgMinusArgsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_SigArgMinusArgs MA_getSigArgMinusArgsTail(MA_SigArgMinusArgs arg) */

MA_SigArgMinusArgs MA_getSigArgMinusArgsTail(MA_SigArgMinusArgs arg)
{
  
    return (MA_SigArgMinusArgs)ATgetTail((ATermList)arg, 4);
}

/*}}}  */
/*{{{  MA_SigArgMinusArgs MA_setSigArgMinusArgsTail(MA_SigArgMinusArgs arg, MA_SigArgMinusArgs tail) */

MA_SigArgMinusArgs MA_setSigArgMinusArgsTail(MA_SigArgMinusArgs arg, MA_SigArgMinusArgs tail)
{
  if (MA_isSigArgMinusArgsMany(arg)) {
    return (MA_SigArgMinusArgs)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("SigArgMinusArgs has no Tail: %t\n", arg);
  return (MA_SigArgMinusArgs)NULL;
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
/*{{{  ATbool MA_hasAnnotationsWsMinusAfterMinusBraceOpen(MA_Annotations arg) */

ATbool MA_hasAnnotationsWsMinusAfterMinusBraceOpen(MA_Annotations arg)
{
  if (MA_isAnnotationsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getAnnotationsWsMinusAfterMinusBraceOpen(MA_Annotations arg) */

MA_Layout MA_getAnnotationsWsMinusAfterMinusBraceOpen(MA_Annotations arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_Annotations MA_setAnnotationsWsMinusAfterMinusBraceOpen(MA_Annotations arg, MA_Layout wsMinusAfterMinusBraceOpen) */

MA_Annotations MA_setAnnotationsWsMinusAfterMinusBraceOpen(MA_Annotations arg, MA_Layout wsMinusAfterMinusBraceOpen)
{
  if (MA_isAnnotationsDefault(arg)) {
    return (MA_Annotations)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusBraceOpen, 1), 1);
  }

  ATabort("Annotations has no WsMinusAfterMinusBraceOpen: %t\n", arg);
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
/*{{{  MA_TermMinusTerms MA_getAnnotationsTerms(MA_Annotations arg) */

MA_TermMinusTerms MA_getAnnotationsTerms(MA_Annotations arg)
{
  
    return (MA_TermMinusTerms)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), 1);
}

/*}}}  */
/*{{{  MA_Annotations MA_setAnnotationsTerms(MA_Annotations arg, MA_TermMinusTerms terms) */

MA_Annotations MA_setAnnotationsTerms(MA_Annotations arg, MA_TermMinusTerms terms)
{
  if (MA_isAnnotationsDefault(arg)) {
    return (MA_Annotations)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), (ATerm)terms, 1), 2), 1);
  }

  ATabort("Annotations has no Terms: %t\n", arg);
  return (MA_Annotations)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasAnnotationsWsMinusAfterMinusTerms(MA_Annotations arg) */

ATbool MA_hasAnnotationsWsMinusAfterMinusTerms(MA_Annotations arg)
{
  if (MA_isAnnotationsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getAnnotationsWsMinusAfterMinusTerms(MA_Annotations arg) */

MA_Layout MA_getAnnotationsWsMinusAfterMinusTerms(MA_Annotations arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  MA_Annotations MA_setAnnotationsWsMinusAfterMinusTerms(MA_Annotations arg, MA_Layout wsMinusAfterMinusTerms) */

MA_Annotations MA_setAnnotationsWsMinusAfterMinusTerms(MA_Annotations arg, MA_Layout wsMinusAfterMinusTerms)
{
  if (MA_isAnnotationsDefault(arg)) {
    return (MA_Annotations)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusTerms, 3), 1);
  }

  ATabort("Annotations has no WsMinusAfterMinusTerms: %t\n", arg);
  return (MA_Annotations)NULL;
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
/*{{{  ATbool MA_hasSigArgListSigargs(MA_SigArgList arg) */

ATbool MA_hasSigArgListSigargs(MA_SigArgList arg)
{
  if (MA_isSigArgListDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_SigArgMinusSigargs MA_getSigArgListSigargs(MA_SigArgList arg) */

MA_SigArgMinusSigargs MA_getSigArgListSigargs(MA_SigArgList arg)
{
  
    return (MA_SigArgMinusSigargs)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  MA_SigArgList MA_setSigArgListSigargs(MA_SigArgList arg, MA_SigArgMinusSigargs sigargs) */

MA_SigArgList MA_setSigArgListSigargs(MA_SigArgList arg, MA_SigArgMinusSigargs sigargs)
{
  if (MA_isSigArgListDefault(arg)) {
    return (MA_SigArgList)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)sigargs, 1), 0), 1);
  }

  ATabort("SigArgList has no Sigargs: %t\n", arg);
  return (MA_SigArgList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_SigArgMinusSigargs accessors */

/*{{{  ATbool MA_isValidSigArgMinusSigargs(MA_SigArgMinusSigargs arg) */

ATbool MA_isValidSigArgMinusSigargs(MA_SigArgMinusSigargs arg)
{
  if (MA_isSigArgMinusSigargsSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isSigArgMinusSigargsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isSigArgMinusSigargsSingle(MA_SigArgMinusSigargs arg) */

inline ATbool MA_isSigArgMinusSigargsSingle(MA_SigArgMinusSigargs arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternSigArgMinusSigargsSingle, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isSigArgMinusSigargsMany(MA_SigArgMinusSigargs arg) */

inline ATbool MA_isSigArgMinusSigargsMany(MA_SigArgMinusSigargs arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternSigArgMinusSigargsMany, NULL, NULL, NULL, NULL, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MA_hasSigArgMinusSigargsHead(MA_SigArgMinusSigargs arg) */

ATbool MA_hasSigArgMinusSigargsHead(MA_SigArgMinusSigargs arg)
{
  if (MA_isSigArgMinusSigargsSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isSigArgMinusSigargsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_SigArg MA_getSigArgMinusSigargsHead(MA_SigArgMinusSigargs arg) */

MA_SigArg MA_getSigArgMinusSigargsHead(MA_SigArgMinusSigargs arg)
{
  if (MA_isSigArgMinusSigargsSingle(arg)) {
    return (MA_SigArg)ATgetFirst((ATermList)arg);
  }
  else 
    return (MA_SigArg)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  MA_SigArgMinusSigargs MA_setSigArgMinusSigargsHead(MA_SigArgMinusSigargs arg, MA_SigArg head) */

MA_SigArgMinusSigargs MA_setSigArgMinusSigargsHead(MA_SigArgMinusSigargs arg, MA_SigArg head)
{
  if (MA_isSigArgMinusSigargsSingle(arg)) {
    return (MA_SigArgMinusSigargs)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (MA_isSigArgMinusSigargsMany(arg)) {
    return (MA_SigArgMinusSigargs)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("SigArgMinusSigargs has no Head: %t\n", arg);
  return (MA_SigArgMinusSigargs)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasSigArgMinusSigargsWsMinusAfterMinusFirst(MA_SigArgMinusSigargs arg) */

ATbool MA_hasSigArgMinusSigargsWsMinusAfterMinusFirst(MA_SigArgMinusSigargs arg)
{
  if (MA_isSigArgMinusSigargsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getSigArgMinusSigargsWsMinusAfterMinusFirst(MA_SigArgMinusSigargs arg) */

MA_Layout MA_getSigArgMinusSigargsWsMinusAfterMinusFirst(MA_SigArgMinusSigargs arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  MA_SigArgMinusSigargs MA_setSigArgMinusSigargsWsMinusAfterMinusFirst(MA_SigArgMinusSigargs arg, MA_Layout wsMinusAfterMinusFirst) */

MA_SigArgMinusSigargs MA_setSigArgMinusSigargsWsMinusAfterMinusFirst(MA_SigArgMinusSigargs arg, MA_Layout wsMinusAfterMinusFirst)
{
  if (MA_isSigArgMinusSigargsMany(arg)) {
    return (MA_SigArgMinusSigargs)ATreplace((ATermList)arg, (ATerm)wsMinusAfterMinusFirst, 1);
  }

  ATabort("SigArgMinusSigargs has no WsMinusAfterMinusFirst: %t\n", arg);
  return (MA_SigArgMinusSigargs)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasSigArgMinusSigargsSep(MA_SigArgMinusSigargs arg) */

ATbool MA_hasSigArgMinusSigargsSep(MA_SigArgMinusSigargs arg)
{
  if (MA_isSigArgMinusSigargsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * MA_getSigArgMinusSigargsSep(MA_SigArgMinusSigargs arg) */

char * MA_getSigArgMinusSigargsSep(MA_SigArgMinusSigargs arg)
{
  
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), 0)));
}

/*}}}  */
/*{{{  MA_SigArgMinusSigargs MA_setSigArgMinusSigargsSep(MA_SigArgMinusSigargs arg, char * sep) */

MA_SigArgMinusSigargs MA_setSigArgMinusSigargsSep(MA_SigArgMinusSigargs arg, char * sep)
{
  if (MA_isSigArgMinusSigargsMany(arg)) {
    return (MA_SigArgMinusSigargs)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)), 0), 2);
  }

  ATabort("SigArgMinusSigargs has no Sep: %t\n", arg);
  return (MA_SigArgMinusSigargs)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasSigArgMinusSigargsWsMinusAfterMinusSep(MA_SigArgMinusSigargs arg) */

ATbool MA_hasSigArgMinusSigargsWsMinusAfterMinusSep(MA_SigArgMinusSigargs arg)
{
  if (MA_isSigArgMinusSigargsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getSigArgMinusSigargsWsMinusAfterMinusSep(MA_SigArgMinusSigargs arg) */

MA_Layout MA_getSigArgMinusSigargsWsMinusAfterMinusSep(MA_SigArgMinusSigargs arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  MA_SigArgMinusSigargs MA_setSigArgMinusSigargsWsMinusAfterMinusSep(MA_SigArgMinusSigargs arg, MA_Layout wsMinusAfterMinusSep) */

MA_SigArgMinusSigargs MA_setSigArgMinusSigargsWsMinusAfterMinusSep(MA_SigArgMinusSigargs arg, MA_Layout wsMinusAfterMinusSep)
{
  if (MA_isSigArgMinusSigargsMany(arg)) {
    return (MA_SigArgMinusSigargs)ATreplace((ATermList)arg, (ATerm)wsMinusAfterMinusSep, 3);
  }

  ATabort("SigArgMinusSigargs has no WsMinusAfterMinusSep: %t\n", arg);
  return (MA_SigArgMinusSigargs)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasSigArgMinusSigargsTail(MA_SigArgMinusSigargs arg) */

ATbool MA_hasSigArgMinusSigargsTail(MA_SigArgMinusSigargs arg)
{
  if (MA_isSigArgMinusSigargsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_SigArgMinusSigargs MA_getSigArgMinusSigargsTail(MA_SigArgMinusSigargs arg) */

MA_SigArgMinusSigargs MA_getSigArgMinusSigargsTail(MA_SigArgMinusSigargs arg)
{
  
    return (MA_SigArgMinusSigargs)ATgetTail((ATermList)arg, 4);
}

/*}}}  */
/*{{{  MA_SigArgMinusSigargs MA_setSigArgMinusSigargsTail(MA_SigArgMinusSigargs arg, MA_SigArgMinusSigargs tail) */

MA_SigArgMinusSigargs MA_setSigArgMinusSigargsTail(MA_SigArgMinusSigargs arg, MA_SigArgMinusSigargs tail)
{
  if (MA_isSigArgMinusSigargsMany(arg)) {
    return (MA_SigArgMinusSigargs)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("SigArgMinusSigargs has no Tail: %t\n", arg);
  return (MA_SigArgMinusSigargs)NULL;
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
/*{{{  ATbool MA_hasFuncDefListFuncdefs(MA_FuncDefList arg) */

ATbool MA_hasFuncDefListFuncdefs(MA_FuncDefList arg)
{
  if (MA_isFuncDefListDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_FuncDefMinusFuncdefs MA_getFuncDefListFuncdefs(MA_FuncDefList arg) */

MA_FuncDefMinusFuncdefs MA_getFuncDefListFuncdefs(MA_FuncDefList arg)
{
  
    return (MA_FuncDefMinusFuncdefs)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  MA_FuncDefList MA_setFuncDefListFuncdefs(MA_FuncDefList arg, MA_FuncDefMinusFuncdefs funcdefs) */

MA_FuncDefList MA_setFuncDefListFuncdefs(MA_FuncDefList arg, MA_FuncDefMinusFuncdefs funcdefs)
{
  if (MA_isFuncDefListDefault(arg)) {
    return (MA_FuncDefList)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)funcdefs, 1), 0), 1);
  }

  ATabort("FuncDefList has no Funcdefs: %t\n", arg);
  return (MA_FuncDefList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_FuncDefMinusFuncdefs accessors */

/*{{{  ATbool MA_isValidFuncDefMinusFuncdefs(MA_FuncDefMinusFuncdefs arg) */

ATbool MA_isValidFuncDefMinusFuncdefs(MA_FuncDefMinusFuncdefs arg)
{
  if (MA_isFuncDefMinusFuncdefsEmpty(arg)) {
    return ATtrue;
  }
  else if (MA_isFuncDefMinusFuncdefsSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isFuncDefMinusFuncdefsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isFuncDefMinusFuncdefsEmpty(MA_FuncDefMinusFuncdefs arg) */

inline ATbool MA_isFuncDefMinusFuncdefsEmpty(MA_FuncDefMinusFuncdefs arg)
{
  return ATmatchTerm((ATerm)arg, MA_patternFuncDefMinusFuncdefsEmpty);
}

/*}}}  */
/*{{{  inline ATbool MA_isFuncDefMinusFuncdefsSingle(MA_FuncDefMinusFuncdefs arg) */

inline ATbool MA_isFuncDefMinusFuncdefsSingle(MA_FuncDefMinusFuncdefs arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternFuncDefMinusFuncdefsSingle, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isFuncDefMinusFuncdefsMany(MA_FuncDefMinusFuncdefs arg) */

inline ATbool MA_isFuncDefMinusFuncdefsMany(MA_FuncDefMinusFuncdefs arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternFuncDefMinusFuncdefsMany, NULL, NULL, NULL, NULL, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MA_hasFuncDefMinusFuncdefsHead(MA_FuncDefMinusFuncdefs arg) */

ATbool MA_hasFuncDefMinusFuncdefsHead(MA_FuncDefMinusFuncdefs arg)
{
  if (MA_isFuncDefMinusFuncdefsSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isFuncDefMinusFuncdefsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_FuncDef MA_getFuncDefMinusFuncdefsHead(MA_FuncDefMinusFuncdefs arg) */

MA_FuncDef MA_getFuncDefMinusFuncdefsHead(MA_FuncDefMinusFuncdefs arg)
{
  if (MA_isFuncDefMinusFuncdefsSingle(arg)) {
    return (MA_FuncDef)ATgetFirst((ATermList)arg);
  }
  else 
    return (MA_FuncDef)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  MA_FuncDefMinusFuncdefs MA_setFuncDefMinusFuncdefsHead(MA_FuncDefMinusFuncdefs arg, MA_FuncDef head) */

MA_FuncDefMinusFuncdefs MA_setFuncDefMinusFuncdefsHead(MA_FuncDefMinusFuncdefs arg, MA_FuncDef head)
{
  if (MA_isFuncDefMinusFuncdefsSingle(arg)) {
    return (MA_FuncDefMinusFuncdefs)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (MA_isFuncDefMinusFuncdefsMany(arg)) {
    return (MA_FuncDefMinusFuncdefs)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("FuncDefMinusFuncdefs has no Head: %t\n", arg);
  return (MA_FuncDefMinusFuncdefs)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasFuncDefMinusFuncdefsWsMinusAfterMinusFirst(MA_FuncDefMinusFuncdefs arg) */

ATbool MA_hasFuncDefMinusFuncdefsWsMinusAfterMinusFirst(MA_FuncDefMinusFuncdefs arg)
{
  if (MA_isFuncDefMinusFuncdefsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getFuncDefMinusFuncdefsWsMinusAfterMinusFirst(MA_FuncDefMinusFuncdefs arg) */

MA_Layout MA_getFuncDefMinusFuncdefsWsMinusAfterMinusFirst(MA_FuncDefMinusFuncdefs arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  MA_FuncDefMinusFuncdefs MA_setFuncDefMinusFuncdefsWsMinusAfterMinusFirst(MA_FuncDefMinusFuncdefs arg, MA_Layout wsMinusAfterMinusFirst) */

MA_FuncDefMinusFuncdefs MA_setFuncDefMinusFuncdefsWsMinusAfterMinusFirst(MA_FuncDefMinusFuncdefs arg, MA_Layout wsMinusAfterMinusFirst)
{
  if (MA_isFuncDefMinusFuncdefsMany(arg)) {
    return (MA_FuncDefMinusFuncdefs)ATreplace((ATermList)arg, (ATerm)wsMinusAfterMinusFirst, 1);
  }

  ATabort("FuncDefMinusFuncdefs has no WsMinusAfterMinusFirst: %t\n", arg);
  return (MA_FuncDefMinusFuncdefs)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasFuncDefMinusFuncdefsSep(MA_FuncDefMinusFuncdefs arg) */

ATbool MA_hasFuncDefMinusFuncdefsSep(MA_FuncDefMinusFuncdefs arg)
{
  if (MA_isFuncDefMinusFuncdefsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * MA_getFuncDefMinusFuncdefsSep(MA_FuncDefMinusFuncdefs arg) */

char * MA_getFuncDefMinusFuncdefsSep(MA_FuncDefMinusFuncdefs arg)
{
  
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), 0)));
}

/*}}}  */
/*{{{  MA_FuncDefMinusFuncdefs MA_setFuncDefMinusFuncdefsSep(MA_FuncDefMinusFuncdefs arg, char * sep) */

MA_FuncDefMinusFuncdefs MA_setFuncDefMinusFuncdefsSep(MA_FuncDefMinusFuncdefs arg, char * sep)
{
  if (MA_isFuncDefMinusFuncdefsMany(arg)) {
    return (MA_FuncDefMinusFuncdefs)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)), 0), 2);
  }

  ATabort("FuncDefMinusFuncdefs has no Sep: %t\n", arg);
  return (MA_FuncDefMinusFuncdefs)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasFuncDefMinusFuncdefsWsMinusAfterMinusSep(MA_FuncDefMinusFuncdefs arg) */

ATbool MA_hasFuncDefMinusFuncdefsWsMinusAfterMinusSep(MA_FuncDefMinusFuncdefs arg)
{
  if (MA_isFuncDefMinusFuncdefsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getFuncDefMinusFuncdefsWsMinusAfterMinusSep(MA_FuncDefMinusFuncdefs arg) */

MA_Layout MA_getFuncDefMinusFuncdefsWsMinusAfterMinusSep(MA_FuncDefMinusFuncdefs arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  MA_FuncDefMinusFuncdefs MA_setFuncDefMinusFuncdefsWsMinusAfterMinusSep(MA_FuncDefMinusFuncdefs arg, MA_Layout wsMinusAfterMinusSep) */

MA_FuncDefMinusFuncdefs MA_setFuncDefMinusFuncdefsWsMinusAfterMinusSep(MA_FuncDefMinusFuncdefs arg, MA_Layout wsMinusAfterMinusSep)
{
  if (MA_isFuncDefMinusFuncdefsMany(arg)) {
    return (MA_FuncDefMinusFuncdefs)ATreplace((ATermList)arg, (ATerm)wsMinusAfterMinusSep, 3);
  }

  ATabort("FuncDefMinusFuncdefs has no WsMinusAfterMinusSep: %t\n", arg);
  return (MA_FuncDefMinusFuncdefs)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasFuncDefMinusFuncdefsTail(MA_FuncDefMinusFuncdefs arg) */

ATbool MA_hasFuncDefMinusFuncdefsTail(MA_FuncDefMinusFuncdefs arg)
{
  if (MA_isFuncDefMinusFuncdefsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_FuncDefMinusFuncdefs MA_getFuncDefMinusFuncdefsTail(MA_FuncDefMinusFuncdefs arg) */

MA_FuncDefMinusFuncdefs MA_getFuncDefMinusFuncdefsTail(MA_FuncDefMinusFuncdefs arg)
{
  
    return (MA_FuncDefMinusFuncdefs)ATgetTail((ATermList)arg, 4);
}

/*}}}  */
/*{{{  MA_FuncDefMinusFuncdefs MA_setFuncDefMinusFuncdefsTail(MA_FuncDefMinusFuncdefs arg, MA_FuncDefMinusFuncdefs tail) */

MA_FuncDefMinusFuncdefs MA_setFuncDefMinusFuncdefsTail(MA_FuncDefMinusFuncdefs arg, MA_FuncDefMinusFuncdefs tail)
{
  if (MA_isFuncDefMinusFuncdefsMany(arg)) {
    return (MA_FuncDefMinusFuncdefs)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("FuncDefMinusFuncdefs has no Tail: %t\n", arg);
  return (MA_FuncDefMinusFuncdefs)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_Rule accessors */

/*{{{  ATbool MA_isValidRule(MA_Rule arg) */

ATbool MA_isValidRule(MA_Rule arg)
{
  if (MA_isRuleNoMinusConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleDefaultMinusNoMinusConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleDefaultMinusWithMinusConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleWithMinusConds(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isRuleNoMinusConds(MA_Rule arg) */

inline ATbool MA_isRuleNoMinusConds(MA_Rule arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternRuleNoMinusConds, NULL, NULL, NULL, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isRuleDefaultMinusNoMinusConds(MA_Rule arg) */

inline ATbool MA_isRuleDefaultMinusNoMinusConds(MA_Rule arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternRuleDefaultMinusNoMinusConds, NULL, NULL, NULL, NULL, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isRuleDefaultMinusWithMinusConds(MA_Rule arg) */

inline ATbool MA_isRuleDefaultMinusWithMinusConds(MA_Rule arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternRuleDefaultMinusWithMinusConds, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isRuleWithMinusConds(MA_Rule arg) */

inline ATbool MA_isRuleWithMinusConds(MA_Rule arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternRuleWithMinusConds, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MA_hasRuleLhs(MA_Rule arg) */

ATbool MA_hasRuleLhs(MA_Rule arg)
{
  if (MA_isRuleNoMinusConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleDefaultMinusNoMinusConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleDefaultMinusWithMinusConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleWithMinusConds(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Term MA_getRuleLhs(MA_Rule arg) */

MA_Term MA_getRuleLhs(MA_Rule arg)
{
  if (MA_isRuleNoMinusConds(arg)) {
    return (MA_Term)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (MA_isRuleDefaultMinusNoMinusConds(arg)) {
    return (MA_Term)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else if (MA_isRuleDefaultMinusWithMinusConds(arg)) {
    return (MA_Term)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6);
  }
  else 
    return (MA_Term)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  MA_Rule MA_setRuleLhs(MA_Rule arg, MA_Term lhs) */

MA_Rule MA_setRuleLhs(MA_Rule arg, MA_Term lhs)
{
  if (MA_isRuleNoMinusConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)lhs, 0), 1);
  }
  else if (MA_isRuleDefaultMinusNoMinusConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)lhs, 2), 1);
  }
  else if (MA_isRuleDefaultMinusWithMinusConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)lhs, 6), 1);
  }
  else if (MA_isRuleWithMinusConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)lhs, 4), 1);
  }

  ATabort("Rule has no Lhs: %t\n", arg);
  return (MA_Rule)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasRuleWsMinusAfterMinusLhs(MA_Rule arg) */

ATbool MA_hasRuleWsMinusAfterMinusLhs(MA_Rule arg)
{
  if (MA_isRuleNoMinusConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleDefaultMinusNoMinusConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleDefaultMinusWithMinusConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleWithMinusConds(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getRuleWsMinusAfterMinusLhs(MA_Rule arg) */

MA_Layout MA_getRuleWsMinusAfterMinusLhs(MA_Rule arg)
{
  if (MA_isRuleNoMinusConds(arg)) {
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else if (MA_isRuleDefaultMinusNoMinusConds(arg)) {
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (MA_isRuleDefaultMinusWithMinusConds(arg)) {
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else 
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  MA_Rule MA_setRuleWsMinusAfterMinusLhs(MA_Rule arg, MA_Layout wsMinusAfterMinusLhs) */

MA_Rule MA_setRuleWsMinusAfterMinusLhs(MA_Rule arg, MA_Layout wsMinusAfterMinusLhs)
{
  if (MA_isRuleNoMinusConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusLhs, 1), 1);
  }
  else if (MA_isRuleDefaultMinusNoMinusConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusLhs, 3), 1);
  }
  else if (MA_isRuleDefaultMinusWithMinusConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusLhs, 7), 1);
  }
  else if (MA_isRuleWithMinusConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusLhs, 5), 1);
  }

  ATabort("Rule has no WsMinusAfterMinusLhs: %t\n", arg);
  return (MA_Rule)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasRuleWsMinusAfterMinusEquals(MA_Rule arg) */

ATbool MA_hasRuleWsMinusAfterMinusEquals(MA_Rule arg)
{
  if (MA_isRuleNoMinusConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleDefaultMinusNoMinusConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleDefaultMinusWithMinusConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleWithMinusConds(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getRuleWsMinusAfterMinusEquals(MA_Rule arg) */

MA_Layout MA_getRuleWsMinusAfterMinusEquals(MA_Rule arg)
{
  if (MA_isRuleNoMinusConds(arg)) {
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (MA_isRuleDefaultMinusNoMinusConds(arg)) {
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else if (MA_isRuleDefaultMinusWithMinusConds(arg)) {
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
  }
  else 
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  MA_Rule MA_setRuleWsMinusAfterMinusEquals(MA_Rule arg, MA_Layout wsMinusAfterMinusEquals) */

MA_Rule MA_setRuleWsMinusAfterMinusEquals(MA_Rule arg, MA_Layout wsMinusAfterMinusEquals)
{
  if (MA_isRuleNoMinusConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusEquals, 3), 1);
  }
  else if (MA_isRuleDefaultMinusNoMinusConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusEquals, 5), 1);
  }
  else if (MA_isRuleDefaultMinusWithMinusConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusEquals, 9), 1);
  }
  else if (MA_isRuleWithMinusConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusEquals, 7), 1);
  }

  ATabort("Rule has no WsMinusAfterMinusEquals: %t\n", arg);
  return (MA_Rule)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasRuleRhs(MA_Rule arg) */

ATbool MA_hasRuleRhs(MA_Rule arg)
{
  if (MA_isRuleNoMinusConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleDefaultMinusNoMinusConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleDefaultMinusWithMinusConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleWithMinusConds(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Term MA_getRuleRhs(MA_Rule arg) */

MA_Term MA_getRuleRhs(MA_Rule arg)
{
  if (MA_isRuleNoMinusConds(arg)) {
    return (MA_Term)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else if (MA_isRuleDefaultMinusNoMinusConds(arg)) {
    return (MA_Term)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6);
  }
  else if (MA_isRuleDefaultMinusWithMinusConds(arg)) {
    return (MA_Term)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 10);
  }
  else 
    return (MA_Term)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/*}}}  */
/*{{{  MA_Rule MA_setRuleRhs(MA_Rule arg, MA_Term rhs) */

MA_Rule MA_setRuleRhs(MA_Rule arg, MA_Term rhs)
{
  if (MA_isRuleNoMinusConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)rhs, 4), 1);
  }
  else if (MA_isRuleDefaultMinusNoMinusConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)rhs, 6), 1);
  }
  else if (MA_isRuleDefaultMinusWithMinusConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)rhs, 10), 1);
  }
  else if (MA_isRuleWithMinusConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)rhs, 8), 1);
  }

  ATabort("Rule has no Rhs: %t\n", arg);
  return (MA_Rule)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasRuleWsMinusAfterMinusDefaultColon(MA_Rule arg) */

ATbool MA_hasRuleWsMinusAfterMinusDefaultColon(MA_Rule arg)
{
  if (MA_isRuleDefaultMinusNoMinusConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleDefaultMinusWithMinusConds(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getRuleWsMinusAfterMinusDefaultColon(MA_Rule arg) */

MA_Layout MA_getRuleWsMinusAfterMinusDefaultColon(MA_Rule arg)
{
  if (MA_isRuleDefaultMinusNoMinusConds(arg)) {
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else 
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_Rule MA_setRuleWsMinusAfterMinusDefaultColon(MA_Rule arg, MA_Layout wsMinusAfterMinusDefaultColon) */

MA_Rule MA_setRuleWsMinusAfterMinusDefaultColon(MA_Rule arg, MA_Layout wsMinusAfterMinusDefaultColon)
{
  if (MA_isRuleDefaultMinusNoMinusConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusDefaultColon, 1), 1);
  }
  else if (MA_isRuleDefaultMinusWithMinusConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusDefaultColon, 1), 1);
  }

  ATabort("Rule has no WsMinusAfterMinusDefaultColon: %t\n", arg);
  return (MA_Rule)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasRuleConds(MA_Rule arg) */

ATbool MA_hasRuleConds(MA_Rule arg)
{
  if (MA_isRuleDefaultMinusWithMinusConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleWithMinusConds(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_CondList MA_getRuleConds(MA_Rule arg) */

MA_CondList MA_getRuleConds(MA_Rule arg)
{
  if (MA_isRuleDefaultMinusWithMinusConds(arg)) {
    return (MA_CondList)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else 
    return (MA_CondList)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  MA_Rule MA_setRuleConds(MA_Rule arg, MA_CondList conds) */

MA_Rule MA_setRuleConds(MA_Rule arg, MA_CondList conds)
{
  if (MA_isRuleDefaultMinusWithMinusConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)conds, 2), 1);
  }
  else if (MA_isRuleWithMinusConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)conds, 0), 1);
  }

  ATabort("Rule has no Conds: %t\n", arg);
  return (MA_Rule)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasRuleWsMinusAfterMinusConds(MA_Rule arg) */

ATbool MA_hasRuleWsMinusAfterMinusConds(MA_Rule arg)
{
  if (MA_isRuleDefaultMinusWithMinusConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleWithMinusConds(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getRuleWsMinusAfterMinusConds(MA_Rule arg) */

MA_Layout MA_getRuleWsMinusAfterMinusConds(MA_Rule arg)
{
  if (MA_isRuleDefaultMinusWithMinusConds(arg)) {
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_Rule MA_setRuleWsMinusAfterMinusConds(MA_Rule arg, MA_Layout wsMinusAfterMinusConds) */

MA_Rule MA_setRuleWsMinusAfterMinusConds(MA_Rule arg, MA_Layout wsMinusAfterMinusConds)
{
  if (MA_isRuleDefaultMinusWithMinusConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusConds, 3), 1);
  }
  else if (MA_isRuleWithMinusConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusConds, 1), 1);
  }

  ATabort("Rule has no WsMinusAfterMinusConds: %t\n", arg);
  return (MA_Rule)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasRuleWsMinusAfterMinusImplies(MA_Rule arg) */

ATbool MA_hasRuleWsMinusAfterMinusImplies(MA_Rule arg)
{
  if (MA_isRuleDefaultMinusWithMinusConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleWithMinusConds(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getRuleWsMinusAfterMinusImplies(MA_Rule arg) */

MA_Layout MA_getRuleWsMinusAfterMinusImplies(MA_Rule arg)
{
  if (MA_isRuleDefaultMinusWithMinusConds(arg)) {
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else 
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  MA_Rule MA_setRuleWsMinusAfterMinusImplies(MA_Rule arg, MA_Layout wsMinusAfterMinusImplies) */

MA_Rule MA_setRuleWsMinusAfterMinusImplies(MA_Rule arg, MA_Layout wsMinusAfterMinusImplies)
{
  if (MA_isRuleDefaultMinusWithMinusConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusImplies, 5), 1);
  }
  else if (MA_isRuleWithMinusConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusImplies, 3), 1);
  }

  ATabort("Rule has no WsMinusAfterMinusImplies: %t\n", arg);
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
/*{{{  ATbool MA_hasRuleListRules(MA_RuleList arg) */

ATbool MA_hasRuleListRules(MA_RuleList arg)
{
  if (MA_isRuleListDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_RuleMinusRules MA_getRuleListRules(MA_RuleList arg) */

MA_RuleMinusRules MA_getRuleListRules(MA_RuleList arg)
{
  
    return (MA_RuleMinusRules)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  MA_RuleList MA_setRuleListRules(MA_RuleList arg, MA_RuleMinusRules rules) */

MA_RuleList MA_setRuleListRules(MA_RuleList arg, MA_RuleMinusRules rules)
{
  if (MA_isRuleListDefault(arg)) {
    return (MA_RuleList)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)rules, 1), 0), 1);
  }

  ATabort("RuleList has no Rules: %t\n", arg);
  return (MA_RuleList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_RuleMinusRules accessors */

/*{{{  ATbool MA_isValidRuleMinusRules(MA_RuleMinusRules arg) */

ATbool MA_isValidRuleMinusRules(MA_RuleMinusRules arg)
{
  if (MA_isRuleMinusRulesEmpty(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleMinusRulesSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleMinusRulesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isRuleMinusRulesEmpty(MA_RuleMinusRules arg) */

inline ATbool MA_isRuleMinusRulesEmpty(MA_RuleMinusRules arg)
{
  return ATmatchTerm((ATerm)arg, MA_patternRuleMinusRulesEmpty);
}

/*}}}  */
/*{{{  inline ATbool MA_isRuleMinusRulesSingle(MA_RuleMinusRules arg) */

inline ATbool MA_isRuleMinusRulesSingle(MA_RuleMinusRules arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternRuleMinusRulesSingle, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isRuleMinusRulesMany(MA_RuleMinusRules arg) */

inline ATbool MA_isRuleMinusRulesMany(MA_RuleMinusRules arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternRuleMinusRulesMany, NULL, NULL, NULL, NULL, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MA_hasRuleMinusRulesHead(MA_RuleMinusRules arg) */

ATbool MA_hasRuleMinusRulesHead(MA_RuleMinusRules arg)
{
  if (MA_isRuleMinusRulesSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleMinusRulesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Rule MA_getRuleMinusRulesHead(MA_RuleMinusRules arg) */

MA_Rule MA_getRuleMinusRulesHead(MA_RuleMinusRules arg)
{
  if (MA_isRuleMinusRulesSingle(arg)) {
    return (MA_Rule)ATgetFirst((ATermList)arg);
  }
  else 
    return (MA_Rule)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  MA_RuleMinusRules MA_setRuleMinusRulesHead(MA_RuleMinusRules arg, MA_Rule head) */

MA_RuleMinusRules MA_setRuleMinusRulesHead(MA_RuleMinusRules arg, MA_Rule head)
{
  if (MA_isRuleMinusRulesSingle(arg)) {
    return (MA_RuleMinusRules)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (MA_isRuleMinusRulesMany(arg)) {
    return (MA_RuleMinusRules)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("RuleMinusRules has no Head: %t\n", arg);
  return (MA_RuleMinusRules)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasRuleMinusRulesWsMinusAfterMinusFirst(MA_RuleMinusRules arg) */

ATbool MA_hasRuleMinusRulesWsMinusAfterMinusFirst(MA_RuleMinusRules arg)
{
  if (MA_isRuleMinusRulesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getRuleMinusRulesWsMinusAfterMinusFirst(MA_RuleMinusRules arg) */

MA_Layout MA_getRuleMinusRulesWsMinusAfterMinusFirst(MA_RuleMinusRules arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  MA_RuleMinusRules MA_setRuleMinusRulesWsMinusAfterMinusFirst(MA_RuleMinusRules arg, MA_Layout wsMinusAfterMinusFirst) */

MA_RuleMinusRules MA_setRuleMinusRulesWsMinusAfterMinusFirst(MA_RuleMinusRules arg, MA_Layout wsMinusAfterMinusFirst)
{
  if (MA_isRuleMinusRulesMany(arg)) {
    return (MA_RuleMinusRules)ATreplace((ATermList)arg, (ATerm)wsMinusAfterMinusFirst, 1);
  }

  ATabort("RuleMinusRules has no WsMinusAfterMinusFirst: %t\n", arg);
  return (MA_RuleMinusRules)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasRuleMinusRulesSep(MA_RuleMinusRules arg) */

ATbool MA_hasRuleMinusRulesSep(MA_RuleMinusRules arg)
{
  if (MA_isRuleMinusRulesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * MA_getRuleMinusRulesSep(MA_RuleMinusRules arg) */

char * MA_getRuleMinusRulesSep(MA_RuleMinusRules arg)
{
  
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), 0)));
}

/*}}}  */
/*{{{  MA_RuleMinusRules MA_setRuleMinusRulesSep(MA_RuleMinusRules arg, char * sep) */

MA_RuleMinusRules MA_setRuleMinusRulesSep(MA_RuleMinusRules arg, char * sep)
{
  if (MA_isRuleMinusRulesMany(arg)) {
    return (MA_RuleMinusRules)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)), 0), 2);
  }

  ATabort("RuleMinusRules has no Sep: %t\n", arg);
  return (MA_RuleMinusRules)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasRuleMinusRulesWsMinusAfterMinusSep(MA_RuleMinusRules arg) */

ATbool MA_hasRuleMinusRulesWsMinusAfterMinusSep(MA_RuleMinusRules arg)
{
  if (MA_isRuleMinusRulesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getRuleMinusRulesWsMinusAfterMinusSep(MA_RuleMinusRules arg) */

MA_Layout MA_getRuleMinusRulesWsMinusAfterMinusSep(MA_RuleMinusRules arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  MA_RuleMinusRules MA_setRuleMinusRulesWsMinusAfterMinusSep(MA_RuleMinusRules arg, MA_Layout wsMinusAfterMinusSep) */

MA_RuleMinusRules MA_setRuleMinusRulesWsMinusAfterMinusSep(MA_RuleMinusRules arg, MA_Layout wsMinusAfterMinusSep)
{
  if (MA_isRuleMinusRulesMany(arg)) {
    return (MA_RuleMinusRules)ATreplace((ATermList)arg, (ATerm)wsMinusAfterMinusSep, 3);
  }

  ATabort("RuleMinusRules has no WsMinusAfterMinusSep: %t\n", arg);
  return (MA_RuleMinusRules)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasRuleMinusRulesTail(MA_RuleMinusRules arg) */

ATbool MA_hasRuleMinusRulesTail(MA_RuleMinusRules arg)
{
  if (MA_isRuleMinusRulesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_RuleMinusRules MA_getRuleMinusRulesTail(MA_RuleMinusRules arg) */

MA_RuleMinusRules MA_getRuleMinusRulesTail(MA_RuleMinusRules arg)
{
  
    return (MA_RuleMinusRules)ATgetTail((ATermList)arg, 4);
}

/*}}}  */
/*{{{  MA_RuleMinusRules MA_setRuleMinusRulesTail(MA_RuleMinusRules arg, MA_RuleMinusRules tail) */

MA_RuleMinusRules MA_setRuleMinusRulesTail(MA_RuleMinusRules arg, MA_RuleMinusRules tail)
{
  if (MA_isRuleMinusRulesMany(arg)) {
    return (MA_RuleMinusRules)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("RuleMinusRules has no Tail: %t\n", arg);
  return (MA_RuleMinusRules)NULL;
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
/*{{{  ATbool MA_hasCondListConds(MA_CondList arg) */

ATbool MA_hasCondListConds(MA_CondList arg)
{
  if (MA_isCondListDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_CondMinusConds MA_getCondListConds(MA_CondList arg) */

MA_CondMinusConds MA_getCondListConds(MA_CondList arg)
{
  
    return (MA_CondMinusConds)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  MA_CondList MA_setCondListConds(MA_CondList arg, MA_CondMinusConds conds) */

MA_CondList MA_setCondListConds(MA_CondList arg, MA_CondMinusConds conds)
{
  if (MA_isCondListDefault(arg)) {
    return (MA_CondList)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)conds, 1), 0), 1);
  }

  ATabort("CondList has no Conds: %t\n", arg);
  return (MA_CondList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_CondMinusConds accessors */

/*{{{  ATbool MA_isValidCondMinusConds(MA_CondMinusConds arg) */

ATbool MA_isValidCondMinusConds(MA_CondMinusConds arg)
{
  if (MA_isCondMinusCondsEmpty(arg)) {
    return ATtrue;
  }
  else if (MA_isCondMinusCondsSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isCondMinusCondsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isCondMinusCondsEmpty(MA_CondMinusConds arg) */

inline ATbool MA_isCondMinusCondsEmpty(MA_CondMinusConds arg)
{
  return ATmatchTerm((ATerm)arg, MA_patternCondMinusCondsEmpty);
}

/*}}}  */
/*{{{  inline ATbool MA_isCondMinusCondsSingle(MA_CondMinusConds arg) */

inline ATbool MA_isCondMinusCondsSingle(MA_CondMinusConds arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternCondMinusCondsSingle, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isCondMinusCondsMany(MA_CondMinusConds arg) */

inline ATbool MA_isCondMinusCondsMany(MA_CondMinusConds arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternCondMinusCondsMany, NULL, NULL, NULL, NULL, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MA_hasCondMinusCondsHead(MA_CondMinusConds arg) */

ATbool MA_hasCondMinusCondsHead(MA_CondMinusConds arg)
{
  if (MA_isCondMinusCondsSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isCondMinusCondsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Cond MA_getCondMinusCondsHead(MA_CondMinusConds arg) */

MA_Cond MA_getCondMinusCondsHead(MA_CondMinusConds arg)
{
  if (MA_isCondMinusCondsSingle(arg)) {
    return (MA_Cond)ATgetFirst((ATermList)arg);
  }
  else 
    return (MA_Cond)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  MA_CondMinusConds MA_setCondMinusCondsHead(MA_CondMinusConds arg, MA_Cond head) */

MA_CondMinusConds MA_setCondMinusCondsHead(MA_CondMinusConds arg, MA_Cond head)
{
  if (MA_isCondMinusCondsSingle(arg)) {
    return (MA_CondMinusConds)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (MA_isCondMinusCondsMany(arg)) {
    return (MA_CondMinusConds)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("CondMinusConds has no Head: %t\n", arg);
  return (MA_CondMinusConds)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasCondMinusCondsWsMinusAfterMinusFirst(MA_CondMinusConds arg) */

ATbool MA_hasCondMinusCondsWsMinusAfterMinusFirst(MA_CondMinusConds arg)
{
  if (MA_isCondMinusCondsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getCondMinusCondsWsMinusAfterMinusFirst(MA_CondMinusConds arg) */

MA_Layout MA_getCondMinusCondsWsMinusAfterMinusFirst(MA_CondMinusConds arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  MA_CondMinusConds MA_setCondMinusCondsWsMinusAfterMinusFirst(MA_CondMinusConds arg, MA_Layout wsMinusAfterMinusFirst) */

MA_CondMinusConds MA_setCondMinusCondsWsMinusAfterMinusFirst(MA_CondMinusConds arg, MA_Layout wsMinusAfterMinusFirst)
{
  if (MA_isCondMinusCondsMany(arg)) {
    return (MA_CondMinusConds)ATreplace((ATermList)arg, (ATerm)wsMinusAfterMinusFirst, 1);
  }

  ATabort("CondMinusConds has no WsMinusAfterMinusFirst: %t\n", arg);
  return (MA_CondMinusConds)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasCondMinusCondsSep(MA_CondMinusConds arg) */

ATbool MA_hasCondMinusCondsSep(MA_CondMinusConds arg)
{
  if (MA_isCondMinusCondsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * MA_getCondMinusCondsSep(MA_CondMinusConds arg) */

char * MA_getCondMinusCondsSep(MA_CondMinusConds arg)
{
  
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), 0)));
}

/*}}}  */
/*{{{  MA_CondMinusConds MA_setCondMinusCondsSep(MA_CondMinusConds arg, char * sep) */

MA_CondMinusConds MA_setCondMinusCondsSep(MA_CondMinusConds arg, char * sep)
{
  if (MA_isCondMinusCondsMany(arg)) {
    return (MA_CondMinusConds)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)), 0), 2);
  }

  ATabort("CondMinusConds has no Sep: %t\n", arg);
  return (MA_CondMinusConds)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasCondMinusCondsWsMinusAfterMinusSep(MA_CondMinusConds arg) */

ATbool MA_hasCondMinusCondsWsMinusAfterMinusSep(MA_CondMinusConds arg)
{
  if (MA_isCondMinusCondsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getCondMinusCondsWsMinusAfterMinusSep(MA_CondMinusConds arg) */

MA_Layout MA_getCondMinusCondsWsMinusAfterMinusSep(MA_CondMinusConds arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  MA_CondMinusConds MA_setCondMinusCondsWsMinusAfterMinusSep(MA_CondMinusConds arg, MA_Layout wsMinusAfterMinusSep) */

MA_CondMinusConds MA_setCondMinusCondsWsMinusAfterMinusSep(MA_CondMinusConds arg, MA_Layout wsMinusAfterMinusSep)
{
  if (MA_isCondMinusCondsMany(arg)) {
    return (MA_CondMinusConds)ATreplace((ATermList)arg, (ATerm)wsMinusAfterMinusSep, 3);
  }

  ATabort("CondMinusConds has no WsMinusAfterMinusSep: %t\n", arg);
  return (MA_CondMinusConds)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasCondMinusCondsTail(MA_CondMinusConds arg) */

ATbool MA_hasCondMinusCondsTail(MA_CondMinusConds arg)
{
  if (MA_isCondMinusCondsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_CondMinusConds MA_getCondMinusCondsTail(MA_CondMinusConds arg) */

MA_CondMinusConds MA_getCondMinusCondsTail(MA_CondMinusConds arg)
{
  
    return (MA_CondMinusConds)ATgetTail((ATermList)arg, 4);
}

/*}}}  */
/*{{{  MA_CondMinusConds MA_setCondMinusCondsTail(MA_CondMinusConds arg, MA_CondMinusConds tail) */

MA_CondMinusConds MA_setCondMinusCondsTail(MA_CondMinusConds arg, MA_CondMinusConds tail)
{
  if (MA_isCondMinusCondsMany(arg)) {
    return (MA_CondMinusConds)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("CondMinusConds has no Tail: %t\n", arg);
  return (MA_CondMinusConds)NULL;
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
/*{{{  ATbool MA_hasCondWsMinusAfterMinusLhs(MA_Cond arg) */

ATbool MA_hasCondWsMinusAfterMinusLhs(MA_Cond arg)
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
/*{{{  MA_Layout MA_getCondWsMinusAfterMinusLhs(MA_Cond arg) */

MA_Layout MA_getCondWsMinusAfterMinusLhs(MA_Cond arg)
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
/*{{{  MA_Cond MA_setCondWsMinusAfterMinusLhs(MA_Cond arg, MA_Layout wsMinusAfterMinusLhs) */

MA_Cond MA_setCondWsMinusAfterMinusLhs(MA_Cond arg, MA_Layout wsMinusAfterMinusLhs)
{
  if (MA_isCondAssign(arg)) {
    return (MA_Cond)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusLhs, 1), 1);
  }
  else if (MA_isCondEqual(arg)) {
    return (MA_Cond)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusLhs, 1), 1);
  }
  else if (MA_isCondUnequal(arg)) {
    return (MA_Cond)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusLhs, 1), 1);
  }

  ATabort("Cond has no WsMinusAfterMinusLhs: %t\n", arg);
  return (MA_Cond)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasCondWsMinusAfterMinusAssign(MA_Cond arg) */

ATbool MA_hasCondWsMinusAfterMinusAssign(MA_Cond arg)
{
  if (MA_isCondAssign(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getCondWsMinusAfterMinusAssign(MA_Cond arg) */

MA_Layout MA_getCondWsMinusAfterMinusAssign(MA_Cond arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  MA_Cond MA_setCondWsMinusAfterMinusAssign(MA_Cond arg, MA_Layout wsMinusAfterMinusAssign) */

MA_Cond MA_setCondWsMinusAfterMinusAssign(MA_Cond arg, MA_Layout wsMinusAfterMinusAssign)
{
  if (MA_isCondAssign(arg)) {
    return (MA_Cond)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusAssign, 3), 1);
  }

  ATabort("Cond has no WsMinusAfterMinusAssign: %t\n", arg);
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
/*{{{  ATbool MA_hasCondWsMinusAfterMinusEqual(MA_Cond arg) */

ATbool MA_hasCondWsMinusAfterMinusEqual(MA_Cond arg)
{
  if (MA_isCondEqual(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getCondWsMinusAfterMinusEqual(MA_Cond arg) */

MA_Layout MA_getCondWsMinusAfterMinusEqual(MA_Cond arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  MA_Cond MA_setCondWsMinusAfterMinusEqual(MA_Cond arg, MA_Layout wsMinusAfterMinusEqual) */

MA_Cond MA_setCondWsMinusAfterMinusEqual(MA_Cond arg, MA_Layout wsMinusAfterMinusEqual)
{
  if (MA_isCondEqual(arg)) {
    return (MA_Cond)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusEqual, 3), 1);
  }

  ATabort("Cond has no WsMinusAfterMinusEqual: %t\n", arg);
  return (MA_Cond)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasCondWsMinusAfterMinusUnequal(MA_Cond arg) */

ATbool MA_hasCondWsMinusAfterMinusUnequal(MA_Cond arg)
{
  if (MA_isCondUnequal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getCondWsMinusAfterMinusUnequal(MA_Cond arg) */

MA_Layout MA_getCondWsMinusAfterMinusUnequal(MA_Cond arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  MA_Cond MA_setCondWsMinusAfterMinusUnequal(MA_Cond arg, MA_Layout wsMinusAfterMinusUnequal) */

MA_Cond MA_setCondWsMinusAfterMinusUnequal(MA_Cond arg, MA_Layout wsMinusAfterMinusUnequal)
{
  if (MA_isCondUnequal(arg)) {
    return (MA_Cond)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusUnequal, 3), 1);
  }

  ATabort("Cond has no WsMinusAfterMinusUnequal: %t\n", arg);
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
/*{{{  ATbool MA_hasSignatureOptWsMinusAfterMinusSignature(MA_SignatureOpt arg) */

ATbool MA_hasSignatureOptWsMinusAfterMinusSignature(MA_SignatureOpt arg)
{
  if (MA_isSignatureOptPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getSignatureOptWsMinusAfterMinusSignature(MA_SignatureOpt arg) */

MA_Layout MA_getSignatureOptWsMinusAfterMinusSignature(MA_SignatureOpt arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_SignatureOpt MA_setSignatureOptWsMinusAfterMinusSignature(MA_SignatureOpt arg, MA_Layout wsMinusAfterMinusSignature) */

MA_SignatureOpt MA_setSignatureOptWsMinusAfterMinusSignature(MA_SignatureOpt arg, MA_Layout wsMinusAfterMinusSignature)
{
  if (MA_isSignatureOptPresent(arg)) {
    return (MA_SignatureOpt)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusSignature, 1), 1);
  }

  ATabort("SignatureOpt has no WsMinusAfterMinusSignature: %t\n", arg);
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
/*{{{  ATbool MA_hasRulesOptWsMinusAfterMinusRules(MA_RulesOpt arg) */

ATbool MA_hasRulesOptWsMinusAfterMinusRules(MA_RulesOpt arg)
{
  if (MA_isRulesOptPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getRulesOptWsMinusAfterMinusRules(MA_RulesOpt arg) */

MA_Layout MA_getRulesOptWsMinusAfterMinusRules(MA_RulesOpt arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_RulesOpt MA_setRulesOptWsMinusAfterMinusRules(MA_RulesOpt arg, MA_Layout wsMinusAfterMinusRules) */

MA_RulesOpt MA_setRulesOptWsMinusAfterMinusRules(MA_RulesOpt arg, MA_Layout wsMinusAfterMinusRules)
{
  if (MA_isRulesOptPresent(arg)) {
    return (MA_RulesOpt)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusRules, 1), 1);
  }

  ATabort("RulesOpt has no WsMinusAfterMinusRules: %t\n", arg);
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
/*{{{  ATbool MA_hasModuleWsMinusAfterMinusModule(MA_Module arg) */

ATbool MA_hasModuleWsMinusAfterMinusModule(MA_Module arg)
{
  if (MA_isModuleModule(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getModuleWsMinusAfterMinusModule(MA_Module arg) */

MA_Layout MA_getModuleWsMinusAfterMinusModule(MA_Module arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_Module MA_setModuleWsMinusAfterMinusModule(MA_Module arg, MA_Layout wsMinusAfterMinusModule) */

MA_Module MA_setModuleWsMinusAfterMinusModule(MA_Module arg, MA_Layout wsMinusAfterMinusModule)
{
  if (MA_isModuleModule(arg)) {
    return (MA_Module)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusModule, 1), 1);
  }

  ATabort("Module has no WsMinusAfterMinusModule: %t\n", arg);
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
/*{{{  ATbool MA_hasModuleWsMinusAfterMinusId(MA_Module arg) */

ATbool MA_hasModuleWsMinusAfterMinusId(MA_Module arg)
{
  if (MA_isModuleModule(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getModuleWsMinusAfterMinusId(MA_Module arg) */

MA_Layout MA_getModuleWsMinusAfterMinusId(MA_Module arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  MA_Module MA_setModuleWsMinusAfterMinusId(MA_Module arg, MA_Layout wsMinusAfterMinusId) */

MA_Module MA_setModuleWsMinusAfterMinusId(MA_Module arg, MA_Layout wsMinusAfterMinusId)
{
  if (MA_isModuleModule(arg)) {
    return (MA_Module)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusId, 3), 1);
  }

  ATabort("Module has no WsMinusAfterMinusId: %t\n", arg);
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
/*{{{  ATbool MA_hasModuleWsMinusAfterMinusSignature(MA_Module arg) */

ATbool MA_hasModuleWsMinusAfterMinusSignature(MA_Module arg)
{
  if (MA_isModuleModule(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getModuleWsMinusAfterMinusSignature(MA_Module arg) */

MA_Layout MA_getModuleWsMinusAfterMinusSignature(MA_Module arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  MA_Module MA_setModuleWsMinusAfterMinusSignature(MA_Module arg, MA_Layout wsMinusAfterMinusSignature) */

MA_Module MA_setModuleWsMinusAfterMinusSignature(MA_Module arg, MA_Layout wsMinusAfterMinusSignature)
{
  if (MA_isModuleModule(arg)) {
    return (MA_Module)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusSignature, 5), 1);
  }

  ATabort("Module has no WsMinusAfterMinusSignature: %t\n", arg);
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
/*{{{  MA_NamePair accessors */

/*{{{  ATbool MA_isValidNamePair(MA_NamePair arg) */

ATbool MA_isValidNamePair(MA_NamePair arg)
{
  if (MA_isNamePairDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isNamePairDefault(MA_NamePair arg) */

inline ATbool MA_isNamePairDefault(MA_NamePair arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MA_patternNamePairDefault, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool MA_hasNamePairWsMinusAfterMinusParenOpen(MA_NamePair arg) */

ATbool MA_hasNamePairWsMinusAfterMinusParenOpen(MA_NamePair arg)
{
  if (MA_isNamePairDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getNamePairWsMinusAfterMinusParenOpen(MA_NamePair arg) */

MA_Layout MA_getNamePairWsMinusAfterMinusParenOpen(MA_NamePair arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_NamePair MA_setNamePairWsMinusAfterMinusParenOpen(MA_NamePair arg, MA_Layout wsMinusAfterMinusParenOpen) */

MA_NamePair MA_setNamePairWsMinusAfterMinusParenOpen(MA_NamePair arg, MA_Layout wsMinusAfterMinusParenOpen)
{
  if (MA_isNamePairDefault(arg)) {
    return (MA_NamePair)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusParenOpen, 1), 1);
  }

  ATabort("NamePair has no WsMinusAfterMinusParenOpen: %t\n", arg);
  return (MA_NamePair)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasNamePairProd(MA_NamePair arg) */

ATbool MA_hasNamePairProd(MA_NamePair arg)
{
  if (MA_isNamePairDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_FunId MA_getNamePairProd(MA_NamePair arg) */

MA_FunId MA_getNamePairProd(MA_NamePair arg)
{
  
    return (MA_FunId)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  MA_NamePair MA_setNamePairProd(MA_NamePair arg, MA_FunId prod) */

MA_NamePair MA_setNamePairProd(MA_NamePair arg, MA_FunId prod)
{
  if (MA_isNamePairDefault(arg)) {
    return (MA_NamePair)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)prod, 2), 1);
  }

  ATabort("NamePair has no Prod: %t\n", arg);
  return (MA_NamePair)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasNamePairWsMinusAfterMinusProd(MA_NamePair arg) */

ATbool MA_hasNamePairWsMinusAfterMinusProd(MA_NamePair arg)
{
  if (MA_isNamePairDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getNamePairWsMinusAfterMinusProd(MA_NamePair arg) */

MA_Layout MA_getNamePairWsMinusAfterMinusProd(MA_NamePair arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  MA_NamePair MA_setNamePairWsMinusAfterMinusProd(MA_NamePair arg, MA_Layout wsMinusAfterMinusProd) */

MA_NamePair MA_setNamePairWsMinusAfterMinusProd(MA_NamePair arg, MA_Layout wsMinusAfterMinusProd)
{
  if (MA_isNamePairDefault(arg)) {
    return (MA_NamePair)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusProd, 3), 1);
  }

  ATabort("NamePair has no WsMinusAfterMinusProd: %t\n", arg);
  return (MA_NamePair)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasNamePairWsMinusAfterMinusComma(MA_NamePair arg) */

ATbool MA_hasNamePairWsMinusAfterMinusComma(MA_NamePair arg)
{
  if (MA_isNamePairDefault(arg)) {
    return ATtrue;
  }
  else if (MA_isNamePairDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getNamePairWsMinusAfterMinusComma(MA_NamePair arg) */

MA_Layout MA_getNamePairWsMinusAfterMinusComma(MA_NamePair arg)
{
  if (MA_isNamePairDefault(arg)) {
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else 
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/*}}}  */
/*{{{  MA_NamePair MA_setNamePairWsMinusAfterMinusComma(MA_NamePair arg, MA_Layout wsMinusAfterMinusComma) */

MA_NamePair MA_setNamePairWsMinusAfterMinusComma(MA_NamePair arg, MA_Layout wsMinusAfterMinusComma)
{
  if (MA_isNamePairDefault(arg)) {
    return (MA_NamePair)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusComma, 5), 1);
  }
  else if (MA_isNamePairDefault(arg)) {
    return (MA_NamePair)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusComma, 9), 1);
  }

  ATabort("NamePair has no WsMinusAfterMinusComma: %t\n", arg);
  return (MA_NamePair)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasNamePairFunc(MA_NamePair arg) */

ATbool MA_hasNamePairFunc(MA_NamePair arg)
{
  if (MA_isNamePairDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_FunId MA_getNamePairFunc(MA_NamePair arg) */

MA_FunId MA_getNamePairFunc(MA_NamePair arg)
{
  
    return (MA_FunId)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6);
}

/*}}}  */
/*{{{  MA_NamePair MA_setNamePairFunc(MA_NamePair arg, MA_FunId func) */

MA_NamePair MA_setNamePairFunc(MA_NamePair arg, MA_FunId func)
{
  if (MA_isNamePairDefault(arg)) {
    return (MA_NamePair)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)func, 6), 1);
  }

  ATabort("NamePair has no Func: %t\n", arg);
  return (MA_NamePair)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasNamePairWsMinusAfterMinusFunc(MA_NamePair arg) */

ATbool MA_hasNamePairWsMinusAfterMinusFunc(MA_NamePair arg)
{
  if (MA_isNamePairDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getNamePairWsMinusAfterMinusFunc(MA_NamePair arg) */

MA_Layout MA_getNamePairWsMinusAfterMinusFunc(MA_NamePair arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  MA_NamePair MA_setNamePairWsMinusAfterMinusFunc(MA_NamePair arg, MA_Layout wsMinusAfterMinusFunc) */

MA_NamePair MA_setNamePairWsMinusAfterMinusFunc(MA_NamePair arg, MA_Layout wsMinusAfterMinusFunc)
{
  if (MA_isNamePairDefault(arg)) {
    return (MA_NamePair)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusFunc, 7), 1);
  }

  ATabort("NamePair has no WsMinusAfterMinusFunc: %t\n", arg);
  return (MA_NamePair)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasNamePairAttributes(MA_NamePair arg) */

ATbool MA_hasNamePairAttributes(MA_NamePair arg)
{
  if (MA_isNamePairDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_TermMinusAttributes MA_getNamePairAttributes(MA_NamePair arg) */

MA_TermMinusAttributes MA_getNamePairAttributes(MA_NamePair arg)
{
  
    return (MA_TermMinusAttributes)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 10), 1);
}

/*}}}  */
/*{{{  MA_NamePair MA_setNamePairAttributes(MA_NamePair arg, MA_TermMinusAttributes attributes) */

MA_NamePair MA_setNamePairAttributes(MA_NamePair arg, MA_TermMinusAttributes attributes)
{
  if (MA_isNamePairDefault(arg)) {
    return (MA_NamePair)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 10), (ATerm)attributes, 1), 10), 1);
  }

  ATabort("NamePair has no Attributes: %t\n", arg);
  return (MA_NamePair)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasNamePairWsMinusAfterMinusAttributes(MA_NamePair arg) */

ATbool MA_hasNamePairWsMinusAfterMinusAttributes(MA_NamePair arg)
{
  if (MA_isNamePairDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getNamePairWsMinusAfterMinusAttributes(MA_NamePair arg) */

MA_Layout MA_getNamePairWsMinusAfterMinusAttributes(MA_NamePair arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 11);
}

/*}}}  */
/*{{{  MA_NamePair MA_setNamePairWsMinusAfterMinusAttributes(MA_NamePair arg, MA_Layout wsMinusAfterMinusAttributes) */

MA_NamePair MA_setNamePairWsMinusAfterMinusAttributes(MA_NamePair arg, MA_Layout wsMinusAfterMinusAttributes)
{
  if (MA_isNamePairDefault(arg)) {
    return (MA_NamePair)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusAttributes, 11), 1);
  }

  ATabort("NamePair has no WsMinusAfterMinusAttributes: %t\n", arg);
  return (MA_NamePair)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_TermMinusAttributes accessors */

/*{{{  ATbool MA_isValidTermMinusAttributes(MA_TermMinusAttributes arg) */

ATbool MA_isValidTermMinusAttributes(MA_TermMinusAttributes arg)
{
  if (MA_isTermMinusAttributesEmpty(arg)) {
    return ATtrue;
  }
  else if (MA_isTermMinusAttributesSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isTermMinusAttributesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isTermMinusAttributesEmpty(MA_TermMinusAttributes arg) */

inline ATbool MA_isTermMinusAttributesEmpty(MA_TermMinusAttributes arg)
{
  return ATmatchTerm((ATerm)arg, MA_patternTermMinusAttributesEmpty);
}

/*}}}  */
/*{{{  inline ATbool MA_isTermMinusAttributesSingle(MA_TermMinusAttributes arg) */

inline ATbool MA_isTermMinusAttributesSingle(MA_TermMinusAttributes arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternTermMinusAttributesSingle, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isTermMinusAttributesMany(MA_TermMinusAttributes arg) */

inline ATbool MA_isTermMinusAttributesMany(MA_TermMinusAttributes arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternTermMinusAttributesMany, NULL, NULL, NULL, NULL, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MA_hasTermMinusAttributesHead(MA_TermMinusAttributes arg) */

ATbool MA_hasTermMinusAttributesHead(MA_TermMinusAttributes arg)
{
  if (MA_isTermMinusAttributesSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isTermMinusAttributesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Term MA_getTermMinusAttributesHead(MA_TermMinusAttributes arg) */

MA_Term MA_getTermMinusAttributesHead(MA_TermMinusAttributes arg)
{
  if (MA_isTermMinusAttributesSingle(arg)) {
    return (MA_Term)ATgetFirst((ATermList)arg);
  }
  else 
    return (MA_Term)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  MA_TermMinusAttributes MA_setTermMinusAttributesHead(MA_TermMinusAttributes arg, MA_Term head) */

MA_TermMinusAttributes MA_setTermMinusAttributesHead(MA_TermMinusAttributes arg, MA_Term head)
{
  if (MA_isTermMinusAttributesSingle(arg)) {
    return (MA_TermMinusAttributes)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (MA_isTermMinusAttributesMany(arg)) {
    return (MA_TermMinusAttributes)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("TermMinusAttributes has no Head: %t\n", arg);
  return (MA_TermMinusAttributes)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasTermMinusAttributesWsMinusAfterMinusFirst(MA_TermMinusAttributes arg) */

ATbool MA_hasTermMinusAttributesWsMinusAfterMinusFirst(MA_TermMinusAttributes arg)
{
  if (MA_isTermMinusAttributesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getTermMinusAttributesWsMinusAfterMinusFirst(MA_TermMinusAttributes arg) */

MA_Layout MA_getTermMinusAttributesWsMinusAfterMinusFirst(MA_TermMinusAttributes arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  MA_TermMinusAttributes MA_setTermMinusAttributesWsMinusAfterMinusFirst(MA_TermMinusAttributes arg, MA_Layout wsMinusAfterMinusFirst) */

MA_TermMinusAttributes MA_setTermMinusAttributesWsMinusAfterMinusFirst(MA_TermMinusAttributes arg, MA_Layout wsMinusAfterMinusFirst)
{
  if (MA_isTermMinusAttributesMany(arg)) {
    return (MA_TermMinusAttributes)ATreplace((ATermList)arg, (ATerm)wsMinusAfterMinusFirst, 1);
  }

  ATabort("TermMinusAttributes has no WsMinusAfterMinusFirst: %t\n", arg);
  return (MA_TermMinusAttributes)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasTermMinusAttributesSep(MA_TermMinusAttributes arg) */

ATbool MA_hasTermMinusAttributesSep(MA_TermMinusAttributes arg)
{
  if (MA_isTermMinusAttributesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * MA_getTermMinusAttributesSep(MA_TermMinusAttributes arg) */

char * MA_getTermMinusAttributesSep(MA_TermMinusAttributes arg)
{
  
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), 0)));
}

/*}}}  */
/*{{{  MA_TermMinusAttributes MA_setTermMinusAttributesSep(MA_TermMinusAttributes arg, char * sep) */

MA_TermMinusAttributes MA_setTermMinusAttributesSep(MA_TermMinusAttributes arg, char * sep)
{
  if (MA_isTermMinusAttributesMany(arg)) {
    return (MA_TermMinusAttributes)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)), 0), 2);
  }

  ATabort("TermMinusAttributes has no Sep: %t\n", arg);
  return (MA_TermMinusAttributes)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasTermMinusAttributesWsMinusAfterMinusSep(MA_TermMinusAttributes arg) */

ATbool MA_hasTermMinusAttributesWsMinusAfterMinusSep(MA_TermMinusAttributes arg)
{
  if (MA_isTermMinusAttributesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getTermMinusAttributesWsMinusAfterMinusSep(MA_TermMinusAttributes arg) */

MA_Layout MA_getTermMinusAttributesWsMinusAfterMinusSep(MA_TermMinusAttributes arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  MA_TermMinusAttributes MA_setTermMinusAttributesWsMinusAfterMinusSep(MA_TermMinusAttributes arg, MA_Layout wsMinusAfterMinusSep) */

MA_TermMinusAttributes MA_setTermMinusAttributesWsMinusAfterMinusSep(MA_TermMinusAttributes arg, MA_Layout wsMinusAfterMinusSep)
{
  if (MA_isTermMinusAttributesMany(arg)) {
    return (MA_TermMinusAttributes)ATreplace((ATermList)arg, (ATerm)wsMinusAfterMinusSep, 3);
  }

  ATabort("TermMinusAttributes has no WsMinusAfterMinusSep: %t\n", arg);
  return (MA_TermMinusAttributes)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasTermMinusAttributesTail(MA_TermMinusAttributes arg) */

ATbool MA_hasTermMinusAttributesTail(MA_TermMinusAttributes arg)
{
  if (MA_isTermMinusAttributesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_TermMinusAttributes MA_getTermMinusAttributesTail(MA_TermMinusAttributes arg) */

MA_TermMinusAttributes MA_getTermMinusAttributesTail(MA_TermMinusAttributes arg)
{
  
    return (MA_TermMinusAttributes)ATgetTail((ATermList)arg, 4);
}

/*}}}  */
/*{{{  MA_TermMinusAttributes MA_setTermMinusAttributesTail(MA_TermMinusAttributes arg, MA_TermMinusAttributes tail) */

MA_TermMinusAttributes MA_setTermMinusAttributesTail(MA_TermMinusAttributes arg, MA_TermMinusAttributes tail)
{
  if (MA_isTermMinusAttributesMany(arg)) {
    return (MA_TermMinusAttributes)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("TermMinusAttributes has no Tail: %t\n", arg);
  return (MA_TermMinusAttributes)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_NameTable accessors */

/*{{{  ATbool MA_isValidNameTable(MA_NameTable arg) */

ATbool MA_isValidNameTable(MA_NameTable arg)
{
  if (MA_isNameTableDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isNameTableDefault(MA_NameTable arg) */

inline ATbool MA_isNameTableDefault(MA_NameTable arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MA_patternNameTableDefault, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool MA_hasNameTableWsMinusAfterMinusParenOpen(MA_NameTable arg) */

ATbool MA_hasNameTableWsMinusAfterMinusParenOpen(MA_NameTable arg)
{
  if (MA_isNameTableDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getNameTableWsMinusAfterMinusParenOpen(MA_NameTable arg) */

MA_Layout MA_getNameTableWsMinusAfterMinusParenOpen(MA_NameTable arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_NameTable MA_setNameTableWsMinusAfterMinusParenOpen(MA_NameTable arg, MA_Layout wsMinusAfterMinusParenOpen) */

MA_NameTable MA_setNameTableWsMinusAfterMinusParenOpen(MA_NameTable arg, MA_Layout wsMinusAfterMinusParenOpen)
{
  if (MA_isNameTableDefault(arg)) {
    return (MA_NameTable)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusParenOpen, 1), 1);
  }

  ATabort("NameTable has no WsMinusAfterMinusParenOpen: %t\n", arg);
  return (MA_NameTable)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasNameTableTable(MA_NameTable arg) */

ATbool MA_hasNameTableTable(MA_NameTable arg)
{
  if (MA_isNameTableDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_NamePairMinusTable MA_getNameTableTable(MA_NameTable arg) */

MA_NamePairMinusTable MA_getNameTableTable(MA_NameTable arg)
{
  
    return (MA_NamePairMinusTable)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), 1);
}

/*}}}  */
/*{{{  MA_NameTable MA_setNameTableTable(MA_NameTable arg, MA_NamePairMinusTable table) */

MA_NameTable MA_setNameTableTable(MA_NameTable arg, MA_NamePairMinusTable table)
{
  if (MA_isNameTableDefault(arg)) {
    return (MA_NameTable)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), (ATerm)table, 1), 2), 1);
  }

  ATabort("NameTable has no Table: %t\n", arg);
  return (MA_NameTable)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasNameTableWsMinusAfterMinusTable(MA_NameTable arg) */

ATbool MA_hasNameTableWsMinusAfterMinusTable(MA_NameTable arg)
{
  if (MA_isNameTableDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getNameTableWsMinusAfterMinusTable(MA_NameTable arg) */

MA_Layout MA_getNameTableWsMinusAfterMinusTable(MA_NameTable arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  MA_NameTable MA_setNameTableWsMinusAfterMinusTable(MA_NameTable arg, MA_Layout wsMinusAfterMinusTable) */

MA_NameTable MA_setNameTableWsMinusAfterMinusTable(MA_NameTable arg, MA_Layout wsMinusAfterMinusTable)
{
  if (MA_isNameTableDefault(arg)) {
    return (MA_NameTable)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusTable, 3), 1);
  }

  ATabort("NameTable has no WsMinusAfterMinusTable: %t\n", arg);
  return (MA_NameTable)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasNameTableWsMinusAfterMinusComma(MA_NameTable arg) */

ATbool MA_hasNameTableWsMinusAfterMinusComma(MA_NameTable arg)
{
  if (MA_isNameTableDefault(arg)) {
    return ATtrue;
  }
  else if (MA_isNameTableDefault(arg)) {
    return ATtrue;
  }
  else if (MA_isNameTableDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getNameTableWsMinusAfterMinusComma(MA_NameTable arg) */

MA_Layout MA_getNameTableWsMinusAfterMinusComma(MA_NameTable arg)
{
  if (MA_isNameTableDefault(arg)) {
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else if (MA_isNameTableDefault(arg)) {
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
  }
  else 
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 13);
}

/*}}}  */
/*{{{  MA_NameTable MA_setNameTableWsMinusAfterMinusComma(MA_NameTable arg, MA_Layout wsMinusAfterMinusComma) */

MA_NameTable MA_setNameTableWsMinusAfterMinusComma(MA_NameTable arg, MA_Layout wsMinusAfterMinusComma)
{
  if (MA_isNameTableDefault(arg)) {
    return (MA_NameTable)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusComma, 5), 1);
  }
  else if (MA_isNameTableDefault(arg)) {
    return (MA_NameTable)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusComma, 9), 1);
  }
  else if (MA_isNameTableDefault(arg)) {
    return (MA_NameTable)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusComma, 13), 1);
  }

  ATabort("NameTable has no WsMinusAfterMinusComma: %t\n", arg);
  return (MA_NameTable)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasNameTableId(MA_NameTable arg) */

ATbool MA_hasNameTableId(MA_NameTable arg)
{
  if (MA_isNameTableDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_FunId MA_getNameTableId(MA_NameTable arg) */

MA_FunId MA_getNameTableId(MA_NameTable arg)
{
  
    return (MA_FunId)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6);
}

/*}}}  */
/*{{{  MA_NameTable MA_setNameTableId(MA_NameTable arg, MA_FunId id) */

MA_NameTable MA_setNameTableId(MA_NameTable arg, MA_FunId id)
{
  if (MA_isNameTableDefault(arg)) {
    return (MA_NameTable)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)id, 6), 1);
  }

  ATabort("NameTable has no Id: %t\n", arg);
  return (MA_NameTable)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasNameTableWsMinusAfterMinusId(MA_NameTable arg) */

ATbool MA_hasNameTableWsMinusAfterMinusId(MA_NameTable arg)
{
  if (MA_isNameTableDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getNameTableWsMinusAfterMinusId(MA_NameTable arg) */

MA_Layout MA_getNameTableWsMinusAfterMinusId(MA_NameTable arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  MA_NameTable MA_setNameTableWsMinusAfterMinusId(MA_NameTable arg, MA_Layout wsMinusAfterMinusId) */

MA_NameTable MA_setNameTableWsMinusAfterMinusId(MA_NameTable arg, MA_Layout wsMinusAfterMinusId)
{
  if (MA_isNameTableDefault(arg)) {
    return (MA_NameTable)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusId, 7), 1);
  }

  ATabort("NameTable has no WsMinusAfterMinusId: %t\n", arg);
  return (MA_NameTable)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasNameTableLast(MA_NameTable arg) */

ATbool MA_hasNameTableLast(MA_NameTable arg)
{
  if (MA_isNameTableDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_IntCon MA_getNameTableLast(MA_NameTable arg) */

MA_IntCon MA_getNameTableLast(MA_NameTable arg)
{
  
    return (MA_IntCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 10);
}

/*}}}  */
/*{{{  MA_NameTable MA_setNameTableLast(MA_NameTable arg, MA_IntCon last) */

MA_NameTable MA_setNameTableLast(MA_NameTable arg, MA_IntCon last)
{
  if (MA_isNameTableDefault(arg)) {
    return (MA_NameTable)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)last, 10), 1);
  }

  ATabort("NameTable has no Last: %t\n", arg);
  return (MA_NameTable)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasNameTableWsMinusAfterMinusLast(MA_NameTable arg) */

ATbool MA_hasNameTableWsMinusAfterMinusLast(MA_NameTable arg)
{
  if (MA_isNameTableDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getNameTableWsMinusAfterMinusLast(MA_NameTable arg) */

MA_Layout MA_getNameTableWsMinusAfterMinusLast(MA_NameTable arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 11);
}

/*}}}  */
/*{{{  MA_NameTable MA_setNameTableWsMinusAfterMinusLast(MA_NameTable arg, MA_Layout wsMinusAfterMinusLast) */

MA_NameTable MA_setNameTableWsMinusAfterMinusLast(MA_NameTable arg, MA_Layout wsMinusAfterMinusLast)
{
  if (MA_isNameTableDefault(arg)) {
    return (MA_NameTable)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusLast, 11), 1);
  }

  ATabort("NameTable has no WsMinusAfterMinusLast: %t\n", arg);
  return (MA_NameTable)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasNameTablePrev(MA_NameTable arg) */

ATbool MA_hasNameTablePrev(MA_NameTable arg)
{
  if (MA_isNameTableDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_IntCon MA_getNameTablePrev(MA_NameTable arg) */

MA_IntCon MA_getNameTablePrev(MA_NameTable arg)
{
  
    return (MA_IntCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 14);
}

/*}}}  */
/*{{{  MA_NameTable MA_setNameTablePrev(MA_NameTable arg, MA_IntCon prev) */

MA_NameTable MA_setNameTablePrev(MA_NameTable arg, MA_IntCon prev)
{
  if (MA_isNameTableDefault(arg)) {
    return (MA_NameTable)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)prev, 14), 1);
  }

  ATabort("NameTable has no Prev: %t\n", arg);
  return (MA_NameTable)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasNameTableWsMinusAfterMinusPrev(MA_NameTable arg) */

ATbool MA_hasNameTableWsMinusAfterMinusPrev(MA_NameTable arg)
{
  if (MA_isNameTableDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getNameTableWsMinusAfterMinusPrev(MA_NameTable arg) */

MA_Layout MA_getNameTableWsMinusAfterMinusPrev(MA_NameTable arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 15);
}

/*}}}  */
/*{{{  MA_NameTable MA_setNameTableWsMinusAfterMinusPrev(MA_NameTable arg, MA_Layout wsMinusAfterMinusPrev) */

MA_NameTable MA_setNameTableWsMinusAfterMinusPrev(MA_NameTable arg, MA_Layout wsMinusAfterMinusPrev)
{
  if (MA_isNameTableDefault(arg)) {
    return (MA_NameTable)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusPrev, 15), 1);
  }

  ATabort("NameTable has no WsMinusAfterMinusPrev: %t\n", arg);
  return (MA_NameTable)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_NamePairMinusTable accessors */

/*{{{  ATbool MA_isValidNamePairMinusTable(MA_NamePairMinusTable arg) */

ATbool MA_isValidNamePairMinusTable(MA_NamePairMinusTable arg)
{
  if (MA_isNamePairMinusTableEmpty(arg)) {
    return ATtrue;
  }
  else if (MA_isNamePairMinusTableSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isNamePairMinusTableMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isNamePairMinusTableEmpty(MA_NamePairMinusTable arg) */

inline ATbool MA_isNamePairMinusTableEmpty(MA_NamePairMinusTable arg)
{
  return ATmatchTerm((ATerm)arg, MA_patternNamePairMinusTableEmpty);
}

/*}}}  */
/*{{{  inline ATbool MA_isNamePairMinusTableSingle(MA_NamePairMinusTable arg) */

inline ATbool MA_isNamePairMinusTableSingle(MA_NamePairMinusTable arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternNamePairMinusTableSingle, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isNamePairMinusTableMany(MA_NamePairMinusTable arg) */

inline ATbool MA_isNamePairMinusTableMany(MA_NamePairMinusTable arg)
{
  {
    static ATerm last_arg = NULL;
    static ATbool last_result;

    assert(arg != NULL);

    if ((ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternNamePairMinusTableMany, NULL, NULL, NULL, NULL, NULL);
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MA_hasNamePairMinusTableHead(MA_NamePairMinusTable arg) */

ATbool MA_hasNamePairMinusTableHead(MA_NamePairMinusTable arg)
{
  if (MA_isNamePairMinusTableSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isNamePairMinusTableMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_NamePair MA_getNamePairMinusTableHead(MA_NamePairMinusTable arg) */

MA_NamePair MA_getNamePairMinusTableHead(MA_NamePairMinusTable arg)
{
  if (MA_isNamePairMinusTableSingle(arg)) {
    return (MA_NamePair)ATgetFirst((ATermList)arg);
  }
  else 
    return (MA_NamePair)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  MA_NamePairMinusTable MA_setNamePairMinusTableHead(MA_NamePairMinusTable arg, MA_NamePair head) */

MA_NamePairMinusTable MA_setNamePairMinusTableHead(MA_NamePairMinusTable arg, MA_NamePair head)
{
  if (MA_isNamePairMinusTableSingle(arg)) {
    return (MA_NamePairMinusTable)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (MA_isNamePairMinusTableMany(arg)) {
    return (MA_NamePairMinusTable)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("NamePairMinusTable has no Head: %t\n", arg);
  return (MA_NamePairMinusTable)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasNamePairMinusTableWsMinusAfterMinusFirst(MA_NamePairMinusTable arg) */

ATbool MA_hasNamePairMinusTableWsMinusAfterMinusFirst(MA_NamePairMinusTable arg)
{
  if (MA_isNamePairMinusTableMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getNamePairMinusTableWsMinusAfterMinusFirst(MA_NamePairMinusTable arg) */

MA_Layout MA_getNamePairMinusTableWsMinusAfterMinusFirst(MA_NamePairMinusTable arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  MA_NamePairMinusTable MA_setNamePairMinusTableWsMinusAfterMinusFirst(MA_NamePairMinusTable arg, MA_Layout wsMinusAfterMinusFirst) */

MA_NamePairMinusTable MA_setNamePairMinusTableWsMinusAfterMinusFirst(MA_NamePairMinusTable arg, MA_Layout wsMinusAfterMinusFirst)
{
  if (MA_isNamePairMinusTableMany(arg)) {
    return (MA_NamePairMinusTable)ATreplace((ATermList)arg, (ATerm)wsMinusAfterMinusFirst, 1);
  }

  ATabort("NamePairMinusTable has no WsMinusAfterMinusFirst: %t\n", arg);
  return (MA_NamePairMinusTable)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasNamePairMinusTableSep(MA_NamePairMinusTable arg) */

ATbool MA_hasNamePairMinusTableSep(MA_NamePairMinusTable arg)
{
  if (MA_isNamePairMinusTableMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * MA_getNamePairMinusTableSep(MA_NamePairMinusTable arg) */

char * MA_getNamePairMinusTableSep(MA_NamePairMinusTable arg)
{
  
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), 0)));
}

/*}}}  */
/*{{{  MA_NamePairMinusTable MA_setNamePairMinusTableSep(MA_NamePairMinusTable arg, char * sep) */

MA_NamePairMinusTable MA_setNamePairMinusTableSep(MA_NamePairMinusTable arg, char * sep)
{
  if (MA_isNamePairMinusTableMany(arg)) {
    return (MA_NamePairMinusTable)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)), 0), 2);
  }

  ATabort("NamePairMinusTable has no Sep: %t\n", arg);
  return (MA_NamePairMinusTable)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasNamePairMinusTableWsMinusAfterMinusSep(MA_NamePairMinusTable arg) */

ATbool MA_hasNamePairMinusTableWsMinusAfterMinusSep(MA_NamePairMinusTable arg)
{
  if (MA_isNamePairMinusTableMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getNamePairMinusTableWsMinusAfterMinusSep(MA_NamePairMinusTable arg) */

MA_Layout MA_getNamePairMinusTableWsMinusAfterMinusSep(MA_NamePairMinusTable arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  MA_NamePairMinusTable MA_setNamePairMinusTableWsMinusAfterMinusSep(MA_NamePairMinusTable arg, MA_Layout wsMinusAfterMinusSep) */

MA_NamePairMinusTable MA_setNamePairMinusTableWsMinusAfterMinusSep(MA_NamePairMinusTable arg, MA_Layout wsMinusAfterMinusSep)
{
  if (MA_isNamePairMinusTableMany(arg)) {
    return (MA_NamePairMinusTable)ATreplace((ATermList)arg, (ATerm)wsMinusAfterMinusSep, 3);
  }

  ATabort("NamePairMinusTable has no WsMinusAfterMinusSep: %t\n", arg);
  return (MA_NamePairMinusTable)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasNamePairMinusTableTail(MA_NamePairMinusTable arg) */

ATbool MA_hasNamePairMinusTableTail(MA_NamePairMinusTable arg)
{
  if (MA_isNamePairMinusTableMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_NamePairMinusTable MA_getNamePairMinusTableTail(MA_NamePairMinusTable arg) */

MA_NamePairMinusTable MA_getNamePairMinusTableTail(MA_NamePairMinusTable arg)
{
  
    return (MA_NamePairMinusTable)ATgetTail((ATermList)arg, 4);
}

/*}}}  */
/*{{{  MA_NamePairMinusTable MA_setNamePairMinusTableTail(MA_NamePairMinusTable arg, MA_NamePairMinusTable tail) */

MA_NamePairMinusTable MA_setNamePairMinusTableTail(MA_NamePairMinusTable arg, MA_NamePairMinusTable tail)
{
  if (MA_isNamePairMinusTableMany(arg)) {
    return (MA_NamePairMinusTable)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
  }

  ATabort("NamePairMinusTable has no Tail: %t\n", arg);
  return (MA_NamePairMinusTable)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_MNMinusStruct accessors */

/*{{{  ATbool MA_isValidMNMinusStruct(MA_MNMinusStruct arg) */

ATbool MA_isValidMNMinusStruct(MA_MNMinusStruct arg)
{
  if (MA_isMNMinusStructDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isMNMinusStructDefault(MA_MNMinusStruct arg) */

inline ATbool MA_isMNMinusStructDefault(MA_MNMinusStruct arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MA_patternMNMinusStructDefault, NULL, NULL, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool MA_hasMNMinusStructWsMinusAfterMinusParenOpen(MA_MNMinusStruct arg) */

ATbool MA_hasMNMinusStructWsMinusAfterMinusParenOpen(MA_MNMinusStruct arg)
{
  if (MA_isMNMinusStructDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getMNMinusStructWsMinusAfterMinusParenOpen(MA_MNMinusStruct arg) */

MA_Layout MA_getMNMinusStructWsMinusAfterMinusParenOpen(MA_MNMinusStruct arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_MNMinusStruct MA_setMNMinusStructWsMinusAfterMinusParenOpen(MA_MNMinusStruct arg, MA_Layout wsMinusAfterMinusParenOpen) */

MA_MNMinusStruct MA_setMNMinusStructWsMinusAfterMinusParenOpen(MA_MNMinusStruct arg, MA_Layout wsMinusAfterMinusParenOpen)
{
  if (MA_isMNMinusStructDefault(arg)) {
    return (MA_MNMinusStruct)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusParenOpen, 1), 1);
  }

  ATabort("MNMinusStruct has no WsMinusAfterMinusParenOpen: %t\n", arg);
  return (MA_MNMinusStruct)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasMNMinusStructMod(MA_MNMinusStruct arg) */

ATbool MA_hasMNMinusStructMod(MA_MNMinusStruct arg)
{
  if (MA_isMNMinusStructDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Module MA_getMNMinusStructMod(MA_MNMinusStruct arg) */

MA_Module MA_getMNMinusStructMod(MA_MNMinusStruct arg)
{
  
    return (MA_Module)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  MA_MNMinusStruct MA_setMNMinusStructMod(MA_MNMinusStruct arg, MA_Module mod) */

MA_MNMinusStruct MA_setMNMinusStructMod(MA_MNMinusStruct arg, MA_Module mod)
{
  if (MA_isMNMinusStructDefault(arg)) {
    return (MA_MNMinusStruct)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)mod, 2), 1);
  }

  ATabort("MNMinusStruct has no Mod: %t\n", arg);
  return (MA_MNMinusStruct)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasMNMinusStructWsMinusAfterMinusMod(MA_MNMinusStruct arg) */

ATbool MA_hasMNMinusStructWsMinusAfterMinusMod(MA_MNMinusStruct arg)
{
  if (MA_isMNMinusStructDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getMNMinusStructWsMinusAfterMinusMod(MA_MNMinusStruct arg) */

MA_Layout MA_getMNMinusStructWsMinusAfterMinusMod(MA_MNMinusStruct arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  MA_MNMinusStruct MA_setMNMinusStructWsMinusAfterMinusMod(MA_MNMinusStruct arg, MA_Layout wsMinusAfterMinusMod) */

MA_MNMinusStruct MA_setMNMinusStructWsMinusAfterMinusMod(MA_MNMinusStruct arg, MA_Layout wsMinusAfterMinusMod)
{
  if (MA_isMNMinusStructDefault(arg)) {
    return (MA_MNMinusStruct)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusMod, 3), 1);
  }

  ATabort("MNMinusStruct has no WsMinusAfterMinusMod: %t\n", arg);
  return (MA_MNMinusStruct)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasMNMinusStructWsMinusAfterMinusComma(MA_MNMinusStruct arg) */

ATbool MA_hasMNMinusStructWsMinusAfterMinusComma(MA_MNMinusStruct arg)
{
  if (MA_isMNMinusStructDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getMNMinusStructWsMinusAfterMinusComma(MA_MNMinusStruct arg) */

MA_Layout MA_getMNMinusStructWsMinusAfterMinusComma(MA_MNMinusStruct arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  MA_MNMinusStruct MA_setMNMinusStructWsMinusAfterMinusComma(MA_MNMinusStruct arg, MA_Layout wsMinusAfterMinusComma) */

MA_MNMinusStruct MA_setMNMinusStructWsMinusAfterMinusComma(MA_MNMinusStruct arg, MA_Layout wsMinusAfterMinusComma)
{
  if (MA_isMNMinusStructDefault(arg)) {
    return (MA_MNMinusStruct)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusComma, 5), 1);
  }

  ATabort("MNMinusStruct has no WsMinusAfterMinusComma: %t\n", arg);
  return (MA_MNMinusStruct)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasMNMinusStructNametable(MA_MNMinusStruct arg) */

ATbool MA_hasMNMinusStructNametable(MA_MNMinusStruct arg)
{
  if (MA_isMNMinusStructDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_NameTable MA_getMNMinusStructNametable(MA_MNMinusStruct arg) */

MA_NameTable MA_getMNMinusStructNametable(MA_MNMinusStruct arg)
{
  
    return (MA_NameTable)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6);
}

/*}}}  */
/*{{{  MA_MNMinusStruct MA_setMNMinusStructNametable(MA_MNMinusStruct arg, MA_NameTable nametable) */

MA_MNMinusStruct MA_setMNMinusStructNametable(MA_MNMinusStruct arg, MA_NameTable nametable)
{
  if (MA_isMNMinusStructDefault(arg)) {
    return (MA_MNMinusStruct)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)nametable, 6), 1);
  }

  ATabort("MNMinusStruct has no Nametable: %t\n", arg);
  return (MA_MNMinusStruct)NULL;
}

/*}}}  */
/*{{{  ATbool MA_hasMNMinusStructWsMinusAfterMinusNametable(MA_MNMinusStruct arg) */

ATbool MA_hasMNMinusStructWsMinusAfterMinusNametable(MA_MNMinusStruct arg)
{
  if (MA_isMNMinusStructDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getMNMinusStructWsMinusAfterMinusNametable(MA_MNMinusStruct arg) */

MA_Layout MA_getMNMinusStructWsMinusAfterMinusNametable(MA_MNMinusStruct arg)
{
  
    return (MA_Layout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  MA_MNMinusStruct MA_setMNMinusStructWsMinusAfterMinusNametable(MA_MNMinusStruct arg, MA_Layout wsMinusAfterMinusNametable) */

MA_MNMinusStruct MA_setMNMinusStructWsMinusAfterMinusNametable(MA_MNMinusStruct arg, MA_Layout wsMinusAfterMinusNametable)
{
  if (MA_isMNMinusStructDefault(arg)) {
    return (MA_MNMinusStruct)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsMinusAfterMinusNametable, 7), 1);
  }

  ATabort("MNMinusStruct has no WsMinusAfterMinusNametable: %t\n", arg);
  return (MA_MNMinusStruct)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  MA_Int MA_visitInt(MA_Int arg, MA_IntCon (*acceptIntCon)(MA_IntCon), MA_Layout (*acceptWsMinusAfterMinusLhs)(MA_Layout), MA_Layout (*acceptWsMinusAfterMinusPlus)(MA_Layout)) */

MA_Int MA_visitInt(MA_Int arg, MA_IntCon (*acceptIntCon)(MA_IntCon), MA_Layout (*acceptWsMinusAfterMinusLhs)(MA_Layout), MA_Layout (*acceptWsMinusAfterMinusPlus)(MA_Layout))
{
  if (MA_isIntCon(arg)) {
    return MA_makeIntCon(
        acceptIntCon ? acceptIntCon(MA_getIntIntCon(arg)) : MA_getIntIntCon(arg));
  }
  if (MA_isIntPlus(arg)) {
    return MA_makeIntPlus(
        MA_visitInt(MA_getIntLhs(arg), acceptIntCon, acceptWsMinusAfterMinusLhs, acceptWsMinusAfterMinusPlus),
        acceptWsMinusAfterMinusLhs ? acceptWsMinusAfterMinusLhs(MA_getIntWsMinusAfterMinusLhs(arg)) : MA_getIntWsMinusAfterMinusLhs(arg),
        acceptWsMinusAfterMinusPlus ? acceptWsMinusAfterMinusPlus(MA_getIntWsMinusAfterMinusPlus(arg)) : MA_getIntWsMinusAfterMinusPlus(arg),
        MA_visitInt(MA_getIntRhs(arg), acceptIntCon, acceptWsMinusAfterMinusLhs, acceptWsMinusAfterMinusPlus));
  }
  ATabort("not a Int: %t\n", arg);
  return (MA_Int)NULL;
}

/*}}}  */
/*{{{  MA_IntCon MA_visitIntCon(MA_IntCon arg, MA_Layout (*acceptWsMinusAfterMinusCon)(MA_Layout), MA_Layout (*acceptWsMinusAfterMinusParenOpen)(MA_Layout), MA_Int (*acceptIntMinusArg)(MA_Int), MA_Layout (*acceptWsMinusAfterMinusIntMinusArg)(MA_Layout), MA_NatCon (*acceptNatCon)(MA_NatCon), MA_Layout (*acceptWsMinusAfterMinusPlus)(MA_Layout), MA_NatCon (*acceptNatMinusArg)(MA_NatCon), MA_Layout (*acceptWsMinusAfterMinusMinus)(MA_Layout)) */

MA_IntCon MA_visitIntCon(MA_IntCon arg, MA_Layout (*acceptWsMinusAfterMinusCon)(MA_Layout), MA_Layout (*acceptWsMinusAfterMinusParenOpen)(MA_Layout), MA_Int (*acceptIntMinusArg)(MA_Int), MA_Layout (*acceptWsMinusAfterMinusIntMinusArg)(MA_Layout), MA_NatCon (*acceptNatCon)(MA_NatCon), MA_Layout (*acceptWsMinusAfterMinusPlus)(MA_Layout), MA_NatCon (*acceptNatMinusArg)(MA_NatCon), MA_Layout (*acceptWsMinusAfterMinusMinus)(MA_Layout))
{
  if (MA_isIntConCon(arg)) {
    return MA_makeIntConCon(
        acceptWsMinusAfterMinusCon ? acceptWsMinusAfterMinusCon(MA_getIntConWsMinusAfterMinusCon(arg)) : MA_getIntConWsMinusAfterMinusCon(arg),
        acceptWsMinusAfterMinusParenOpen ? acceptWsMinusAfterMinusParenOpen(MA_getIntConWsMinusAfterMinusParenOpen(arg)) : MA_getIntConWsMinusAfterMinusParenOpen(arg),
        acceptIntMinusArg ? acceptIntMinusArg(MA_getIntConIntMinusArg(arg)) : MA_getIntConIntMinusArg(arg),
        acceptWsMinusAfterMinusIntMinusArg ? acceptWsMinusAfterMinusIntMinusArg(MA_getIntConWsMinusAfterMinusIntMinusArg(arg)) : MA_getIntConWsMinusAfterMinusIntMinusArg(arg));
  }
  if (MA_isIntConNat(arg)) {
    return MA_makeIntConNat(
        acceptNatCon ? acceptNatCon(MA_getIntConNatCon(arg)) : MA_getIntConNatCon(arg));
  }
  if (MA_isIntConPos(arg)) {
    return MA_makeIntConPos(
        acceptWsMinusAfterMinusPlus ? acceptWsMinusAfterMinusPlus(MA_getIntConWsMinusAfterMinusPlus(arg)) : MA_getIntConWsMinusAfterMinusPlus(arg),
        acceptNatMinusArg ? acceptNatMinusArg(MA_getIntConNatMinusArg(arg)) : MA_getIntConNatMinusArg(arg));
  }
  if (MA_isIntConNeg(arg)) {
    return MA_makeIntConNeg(
        acceptWsMinusAfterMinusMinus ? acceptWsMinusAfterMinusMinus(MA_getIntConWsMinusAfterMinusMinus(arg)) : MA_getIntConWsMinusAfterMinusMinus(arg),
        acceptNatMinusArg ? acceptNatMinusArg(MA_getIntConNatMinusArg(arg)) : MA_getIntConNatMinusArg(arg));
  }
  ATabort("not a IntCon: %t\n", arg);
  return (MA_IntCon)NULL;
}

/*}}}  */
/*{{{  MA_NatCon MA_visitNatCon(MA_NatCon arg, MA_Layout (*acceptWsMinusAfterMinusAbs)(MA_Layout), MA_Layout (*acceptWsMinusAfterMinusParenOpen)(MA_Layout), MA_Int (*acceptIntMinusArg)(MA_Int), MA_Layout (*acceptWsMinusAfterMinusIntMinusArg)(MA_Layout)) */

MA_NatCon MA_visitNatCon(MA_NatCon arg, MA_Layout (*acceptWsMinusAfterMinusAbs)(MA_Layout), MA_Layout (*acceptWsMinusAfterMinusParenOpen)(MA_Layout), MA_Int (*acceptIntMinusArg)(MA_Int), MA_Layout (*acceptWsMinusAfterMinusIntMinusArg)(MA_Layout))
{
  if (MA_isNatConAbs(arg)) {
    return MA_makeNatConAbs(
        acceptWsMinusAfterMinusAbs ? acceptWsMinusAfterMinusAbs(MA_getNatConWsMinusAfterMinusAbs(arg)) : MA_getNatConWsMinusAfterMinusAbs(arg),
        acceptWsMinusAfterMinusParenOpen ? acceptWsMinusAfterMinusParenOpen(MA_getNatConWsMinusAfterMinusParenOpen(arg)) : MA_getNatConWsMinusAfterMinusParenOpen(arg),
        acceptIntMinusArg ? acceptIntMinusArg(MA_getNatConIntMinusArg(arg)) : MA_getNatConIntMinusArg(arg),
        acceptWsMinusAfterMinusIntMinusArg ? acceptWsMinusAfterMinusIntMinusArg(MA_getNatConWsMinusAfterMinusIntMinusArg(arg)) : MA_getNatConWsMinusAfterMinusIntMinusArg(arg));
  }
  ATabort("not a NatCon: %t\n", arg);
  return (MA_NatCon)NULL;
}

/*}}}  */
/*{{{  MA_Var MA_visitVar(MA_Var arg, MA_VarId (*acceptVarId)(MA_VarId), MA_Layout (*acceptWsMinusAfterMinusStar)(MA_Layout), MA_Layout (*acceptWsMinusAfterMinusPlus)(MA_Layout)) */

MA_Var MA_visitVar(MA_Var arg, MA_VarId (*acceptVarId)(MA_VarId), MA_Layout (*acceptWsMinusAfterMinusStar)(MA_Layout), MA_Layout (*acceptWsMinusAfterMinusPlus)(MA_Layout))
{
  if (MA_isVarNormal(arg)) {
    return MA_makeVarNormal(
        acceptVarId ? acceptVarId(MA_getVarVarId(arg)) : MA_getVarVarId(arg));
  }
  if (MA_isVarStar(arg)) {
    return MA_makeVarStar(
        acceptWsMinusAfterMinusStar ? acceptWsMinusAfterMinusStar(MA_getVarWsMinusAfterMinusStar(arg)) : MA_getVarWsMinusAfterMinusStar(arg),
        acceptVarId ? acceptVarId(MA_getVarVarId(arg)) : MA_getVarVarId(arg));
  }
  if (MA_isVarPlus(arg)) {
    return MA_makeVarPlus(
        acceptWsMinusAfterMinusPlus ? acceptWsMinusAfterMinusPlus(MA_getVarWsMinusAfterMinusPlus(arg)) : MA_getVarWsMinusAfterMinusPlus(arg),
        acceptVarId ? acceptVarId(MA_getVarVarId(arg)) : MA_getVarVarId(arg));
  }
  ATabort("not a Var: %t\n", arg);
  return (MA_Var)NULL;
}

/*}}}  */
/*{{{  MA_Term MA_visitTerm(MA_Term arg, MA_Var (*acceptVar)(MA_Var), MA_FunId (*acceptFunId)(MA_FunId), MA_Int (*acceptInt)(MA_Int), MA_Layout (*acceptWsMinusAfterMinusFunId)(MA_Layout), MA_Layout (*acceptWsMinusAfterMinusParenOpen)(MA_Layout), MA_TermMinusArgs (*acceptArgs)(MA_TermMinusArgs), MA_Layout (*acceptWsMinusAfterMinusArgs)(MA_Layout)) */

MA_Term MA_visitTerm(MA_Term arg, MA_Var (*acceptVar)(MA_Var), MA_FunId (*acceptFunId)(MA_FunId), MA_Int (*acceptInt)(MA_Int), MA_Layout (*acceptWsMinusAfterMinusFunId)(MA_Layout), MA_Layout (*acceptWsMinusAfterMinusParenOpen)(MA_Layout), MA_TermMinusArgs (*acceptArgs)(MA_TermMinusArgs), MA_Layout (*acceptWsMinusAfterMinusArgs)(MA_Layout))
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
        acceptWsMinusAfterMinusFunId ? acceptWsMinusAfterMinusFunId(MA_getTermWsMinusAfterMinusFunId(arg)) : MA_getTermWsMinusAfterMinusFunId(arg),
        acceptWsMinusAfterMinusParenOpen ? acceptWsMinusAfterMinusParenOpen(MA_getTermWsMinusAfterMinusParenOpen(arg)) : MA_getTermWsMinusAfterMinusParenOpen(arg),
        acceptArgs ? acceptArgs(MA_getTermArgs(arg)) : MA_getTermArgs(arg),
        acceptWsMinusAfterMinusArgs ? acceptWsMinusAfterMinusArgs(MA_getTermWsMinusAfterMinusArgs(arg)) : MA_getTermWsMinusAfterMinusArgs(arg));
  }
  ATabort("not a Term: %t\n", arg);
  return (MA_Term)NULL;
}

/*}}}  */
/*{{{  MA_TermMinusArgs MA_visitTermMinusArgs(MA_TermMinusArgs arg, MA_Term (*acceptHead)(MA_Term), MA_Layout (*acceptWsMinusAfterMinusFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsMinusAfterMinusSep)(MA_Layout)) */

MA_TermMinusArgs MA_visitTermMinusArgs(MA_TermMinusArgs arg, MA_Term (*acceptHead)(MA_Term), MA_Layout (*acceptWsMinusAfterMinusFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsMinusAfterMinusSep)(MA_Layout))
{
  if (MA_isTermMinusArgsSingle(arg)) {
    return MA_makeTermMinusArgsSingle(
        acceptHead ? acceptHead(MA_getTermMinusArgsHead(arg)) : MA_getTermMinusArgsHead(arg));
  }
  if (MA_isTermMinusArgsMany(arg)) {
    return MA_makeTermMinusArgsMany(
        acceptHead ? acceptHead(MA_getTermMinusArgsHead(arg)) : MA_getTermMinusArgsHead(arg),
        acceptWsMinusAfterMinusFirst ? acceptWsMinusAfterMinusFirst(MA_getTermMinusArgsWsMinusAfterMinusFirst(arg)) : MA_getTermMinusArgsWsMinusAfterMinusFirst(arg),
        acceptSep ? acceptSep(MA_getTermMinusArgsSep(arg)) : MA_getTermMinusArgsSep(arg),
        acceptWsMinusAfterMinusSep ? acceptWsMinusAfterMinusSep(MA_getTermMinusArgsWsMinusAfterMinusSep(arg)) : MA_getTermMinusArgsWsMinusAfterMinusSep(arg),
        MA_visitTermMinusArgs(MA_getTermMinusArgsTail(arg), acceptHead, acceptWsMinusAfterMinusFirst, acceptSep, acceptWsMinusAfterMinusSep));
  }
  ATabort("not a TermMinusArgs: %t\n", arg);
  return (MA_TermMinusArgs)NULL;
}

/*}}}  */
/*{{{  MA_TermList MA_visitTermList(MA_TermList arg, MA_TermMinusTerms (*acceptTerms)(MA_TermMinusTerms)) */

MA_TermList MA_visitTermList(MA_TermList arg, MA_TermMinusTerms (*acceptTerms)(MA_TermMinusTerms))
{
  if (MA_isTermListDefault(arg)) {
    return MA_makeTermListDefault(
        acceptTerms ? acceptTerms(MA_getTermListTerms(arg)) : MA_getTermListTerms(arg));
  }
  ATabort("not a TermList: %t\n", arg);
  return (MA_TermList)NULL;
}

/*}}}  */
/*{{{  MA_TermMinusTerms MA_visitTermMinusTerms(MA_TermMinusTerms arg, MA_Term (*acceptHead)(MA_Term), MA_Layout (*acceptWsMinusAfterMinusFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsMinusAfterMinusSep)(MA_Layout)) */

MA_TermMinusTerms MA_visitTermMinusTerms(MA_TermMinusTerms arg, MA_Term (*acceptHead)(MA_Term), MA_Layout (*acceptWsMinusAfterMinusFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsMinusAfterMinusSep)(MA_Layout))
{
  if (MA_isTermMinusTermsEmpty(arg)) {
    return MA_makeTermMinusTermsEmpty();
  }
  if (MA_isTermMinusTermsSingle(arg)) {
    return MA_makeTermMinusTermsSingle(
        acceptHead ? acceptHead(MA_getTermMinusTermsHead(arg)) : MA_getTermMinusTermsHead(arg));
  }
  if (MA_isTermMinusTermsMany(arg)) {
    return MA_makeTermMinusTermsMany(
        acceptHead ? acceptHead(MA_getTermMinusTermsHead(arg)) : MA_getTermMinusTermsHead(arg),
        acceptWsMinusAfterMinusFirst ? acceptWsMinusAfterMinusFirst(MA_getTermMinusTermsWsMinusAfterMinusFirst(arg)) : MA_getTermMinusTermsWsMinusAfterMinusFirst(arg),
        acceptSep ? acceptSep(MA_getTermMinusTermsSep(arg)) : MA_getTermMinusTermsSep(arg),
        acceptWsMinusAfterMinusSep ? acceptWsMinusAfterMinusSep(MA_getTermMinusTermsWsMinusAfterMinusSep(arg)) : MA_getTermMinusTermsWsMinusAfterMinusSep(arg),
        MA_visitTermMinusTerms(MA_getTermMinusTermsTail(arg), acceptHead, acceptWsMinusAfterMinusFirst, acceptSep, acceptWsMinusAfterMinusSep));
  }
  ATabort("not a TermMinusTerms: %t\n", arg);
  return (MA_TermMinusTerms)NULL;
}

/*}}}  */
/*{{{  MA_SigArg MA_visitSigArg(MA_SigArg arg, MA_Layout (*acceptWsMinusAfterMinusUnderscore)(MA_Layout)) */

MA_SigArg MA_visitSigArg(MA_SigArg arg, MA_Layout (*acceptWsMinusAfterMinusUnderscore)(MA_Layout))
{
  if (MA_isSigArgNormal(arg)) {
    return MA_makeSigArgNormal();
  }
  if (MA_isSigArgStar(arg)) {
    return MA_makeSigArgStar(
        acceptWsMinusAfterMinusUnderscore ? acceptWsMinusAfterMinusUnderscore(MA_getSigArgWsMinusAfterMinusUnderscore(arg)) : MA_getSigArgWsMinusAfterMinusUnderscore(arg));
  }
  if (MA_isSigArgPlus(arg)) {
    return MA_makeSigArgPlus(
        acceptWsMinusAfterMinusUnderscore ? acceptWsMinusAfterMinusUnderscore(MA_getSigArgWsMinusAfterMinusUnderscore(arg)) : MA_getSigArgWsMinusAfterMinusUnderscore(arg));
  }
  ATabort("not a SigArg: %t\n", arg);
  return (MA_SigArg)NULL;
}

/*}}}  */
/*{{{  MA_FuncDef MA_visitFuncDef(MA_FuncDef arg, MA_FunId (*acceptFunId)(MA_FunId), MA_Layout (*acceptWsMinusAfterMinusFunId)(MA_Layout), MA_Annotations (*acceptAnnos)(MA_Annotations), MA_Layout (*acceptWsMinusAfterMinusParenOpen)(MA_Layout), MA_SigArgMinusArgs (*acceptArgs)(MA_SigArgMinusArgs), MA_Layout (*acceptWsMinusAfterMinusArgs)(MA_Layout), MA_Layout (*acceptWsMinusAfterMinusParenClose)(MA_Layout)) */

MA_FuncDef MA_visitFuncDef(MA_FuncDef arg, MA_FunId (*acceptFunId)(MA_FunId), MA_Layout (*acceptWsMinusAfterMinusFunId)(MA_Layout), MA_Annotations (*acceptAnnos)(MA_Annotations), MA_Layout (*acceptWsMinusAfterMinusParenOpen)(MA_Layout), MA_SigArgMinusArgs (*acceptArgs)(MA_SigArgMinusArgs), MA_Layout (*acceptWsMinusAfterMinusArgs)(MA_Layout), MA_Layout (*acceptWsMinusAfterMinusParenClose)(MA_Layout))
{
  if (MA_isFuncDefConstantMinusNoMinusAnnos(arg)) {
    return MA_makeFuncDefConstantMinusNoMinusAnnos(
        acceptFunId ? acceptFunId(MA_getFuncDefFunId(arg)) : MA_getFuncDefFunId(arg));
  }
  if (MA_isFuncDefConstantMinusWithMinusAnnos(arg)) {
    return MA_makeFuncDefConstantMinusWithMinusAnnos(
        acceptFunId ? acceptFunId(MA_getFuncDefFunId(arg)) : MA_getFuncDefFunId(arg),
        acceptWsMinusAfterMinusFunId ? acceptWsMinusAfterMinusFunId(MA_getFuncDefWsMinusAfterMinusFunId(arg)) : MA_getFuncDefWsMinusAfterMinusFunId(arg),
        acceptAnnos ? acceptAnnos(MA_getFuncDefAnnos(arg)) : MA_getFuncDefAnnos(arg));
  }
  if (MA_isFuncDefFuncMinusNoMinusAnnos(arg)) {
    return MA_makeFuncDefFuncMinusNoMinusAnnos(
        acceptFunId ? acceptFunId(MA_getFuncDefFunId(arg)) : MA_getFuncDefFunId(arg),
        acceptWsMinusAfterMinusFunId ? acceptWsMinusAfterMinusFunId(MA_getFuncDefWsMinusAfterMinusFunId(arg)) : MA_getFuncDefWsMinusAfterMinusFunId(arg),
        acceptWsMinusAfterMinusParenOpen ? acceptWsMinusAfterMinusParenOpen(MA_getFuncDefWsMinusAfterMinusParenOpen(arg)) : MA_getFuncDefWsMinusAfterMinusParenOpen(arg),
        acceptArgs ? acceptArgs(MA_getFuncDefArgs(arg)) : MA_getFuncDefArgs(arg),
        acceptWsMinusAfterMinusArgs ? acceptWsMinusAfterMinusArgs(MA_getFuncDefWsMinusAfterMinusArgs(arg)) : MA_getFuncDefWsMinusAfterMinusArgs(arg));
  }
  if (MA_isFuncDefFuncMinusWithMinusAnnos(arg)) {
    return MA_makeFuncDefFuncMinusWithMinusAnnos(
        acceptFunId ? acceptFunId(MA_getFuncDefFunId(arg)) : MA_getFuncDefFunId(arg),
        acceptWsMinusAfterMinusFunId ? acceptWsMinusAfterMinusFunId(MA_getFuncDefWsMinusAfterMinusFunId(arg)) : MA_getFuncDefWsMinusAfterMinusFunId(arg),
        acceptWsMinusAfterMinusParenOpen ? acceptWsMinusAfterMinusParenOpen(MA_getFuncDefWsMinusAfterMinusParenOpen(arg)) : MA_getFuncDefWsMinusAfterMinusParenOpen(arg),
        acceptArgs ? acceptArgs(MA_getFuncDefArgs(arg)) : MA_getFuncDefArgs(arg),
        acceptWsMinusAfterMinusArgs ? acceptWsMinusAfterMinusArgs(MA_getFuncDefWsMinusAfterMinusArgs(arg)) : MA_getFuncDefWsMinusAfterMinusArgs(arg),
        acceptWsMinusAfterMinusParenClose ? acceptWsMinusAfterMinusParenClose(MA_getFuncDefWsMinusAfterMinusParenClose(arg)) : MA_getFuncDefWsMinusAfterMinusParenClose(arg),
        acceptAnnos ? acceptAnnos(MA_getFuncDefAnnos(arg)) : MA_getFuncDefAnnos(arg));
  }
  ATabort("not a FuncDef: %t\n", arg);
  return (MA_FuncDef)NULL;
}

/*}}}  */
/*{{{  MA_SigArgMinusArgs MA_visitSigArgMinusArgs(MA_SigArgMinusArgs arg, MA_SigArg (*acceptHead)(MA_SigArg), MA_Layout (*acceptWsMinusAfterMinusFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsMinusAfterMinusSep)(MA_Layout)) */

MA_SigArgMinusArgs MA_visitSigArgMinusArgs(MA_SigArgMinusArgs arg, MA_SigArg (*acceptHead)(MA_SigArg), MA_Layout (*acceptWsMinusAfterMinusFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsMinusAfterMinusSep)(MA_Layout))
{
  if (MA_isSigArgMinusArgsSingle(arg)) {
    return MA_makeSigArgMinusArgsSingle(
        acceptHead ? acceptHead(MA_getSigArgMinusArgsHead(arg)) : MA_getSigArgMinusArgsHead(arg));
  }
  if (MA_isSigArgMinusArgsMany(arg)) {
    return MA_makeSigArgMinusArgsMany(
        acceptHead ? acceptHead(MA_getSigArgMinusArgsHead(arg)) : MA_getSigArgMinusArgsHead(arg),
        acceptWsMinusAfterMinusFirst ? acceptWsMinusAfterMinusFirst(MA_getSigArgMinusArgsWsMinusAfterMinusFirst(arg)) : MA_getSigArgMinusArgsWsMinusAfterMinusFirst(arg),
        acceptSep ? acceptSep(MA_getSigArgMinusArgsSep(arg)) : MA_getSigArgMinusArgsSep(arg),
        acceptWsMinusAfterMinusSep ? acceptWsMinusAfterMinusSep(MA_getSigArgMinusArgsWsMinusAfterMinusSep(arg)) : MA_getSigArgMinusArgsWsMinusAfterMinusSep(arg),
        MA_visitSigArgMinusArgs(MA_getSigArgMinusArgsTail(arg), acceptHead, acceptWsMinusAfterMinusFirst, acceptSep, acceptWsMinusAfterMinusSep));
  }
  ATabort("not a SigArgMinusArgs: %t\n", arg);
  return (MA_SigArgMinusArgs)NULL;
}

/*}}}  */
/*{{{  MA_Annotations MA_visitAnnotations(MA_Annotations arg, MA_Layout (*acceptWsMinusAfterMinusBraceOpen)(MA_Layout), MA_TermMinusTerms (*acceptTerms)(MA_TermMinusTerms), MA_Layout (*acceptWsMinusAfterMinusTerms)(MA_Layout)) */

MA_Annotations MA_visitAnnotations(MA_Annotations arg, MA_Layout (*acceptWsMinusAfterMinusBraceOpen)(MA_Layout), MA_TermMinusTerms (*acceptTerms)(MA_TermMinusTerms), MA_Layout (*acceptWsMinusAfterMinusTerms)(MA_Layout))
{
  if (MA_isAnnotationsDefault(arg)) {
    return MA_makeAnnotationsDefault(
        acceptWsMinusAfterMinusBraceOpen ? acceptWsMinusAfterMinusBraceOpen(MA_getAnnotationsWsMinusAfterMinusBraceOpen(arg)) : MA_getAnnotationsWsMinusAfterMinusBraceOpen(arg),
        acceptTerms ? acceptTerms(MA_getAnnotationsTerms(arg)) : MA_getAnnotationsTerms(arg),
        acceptWsMinusAfterMinusTerms ? acceptWsMinusAfterMinusTerms(MA_getAnnotationsWsMinusAfterMinusTerms(arg)) : MA_getAnnotationsWsMinusAfterMinusTerms(arg));
  }
  ATabort("not a Annotations: %t\n", arg);
  return (MA_Annotations)NULL;
}

/*}}}  */
/*{{{  MA_SigArgList MA_visitSigArgList(MA_SigArgList arg, MA_SigArgMinusSigargs (*acceptSigargs)(MA_SigArgMinusSigargs)) */

MA_SigArgList MA_visitSigArgList(MA_SigArgList arg, MA_SigArgMinusSigargs (*acceptSigargs)(MA_SigArgMinusSigargs))
{
  if (MA_isSigArgListDefault(arg)) {
    return MA_makeSigArgListDefault(
        acceptSigargs ? acceptSigargs(MA_getSigArgListSigargs(arg)) : MA_getSigArgListSigargs(arg));
  }
  ATabort("not a SigArgList: %t\n", arg);
  return (MA_SigArgList)NULL;
}

/*}}}  */
/*{{{  MA_SigArgMinusSigargs MA_visitSigArgMinusSigargs(MA_SigArgMinusSigargs arg, MA_SigArg (*acceptHead)(MA_SigArg), MA_Layout (*acceptWsMinusAfterMinusFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsMinusAfterMinusSep)(MA_Layout)) */

MA_SigArgMinusSigargs MA_visitSigArgMinusSigargs(MA_SigArgMinusSigargs arg, MA_SigArg (*acceptHead)(MA_SigArg), MA_Layout (*acceptWsMinusAfterMinusFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsMinusAfterMinusSep)(MA_Layout))
{
  if (MA_isSigArgMinusSigargsSingle(arg)) {
    return MA_makeSigArgMinusSigargsSingle(
        acceptHead ? acceptHead(MA_getSigArgMinusSigargsHead(arg)) : MA_getSigArgMinusSigargsHead(arg));
  }
  if (MA_isSigArgMinusSigargsMany(arg)) {
    return MA_makeSigArgMinusSigargsMany(
        acceptHead ? acceptHead(MA_getSigArgMinusSigargsHead(arg)) : MA_getSigArgMinusSigargsHead(arg),
        acceptWsMinusAfterMinusFirst ? acceptWsMinusAfterMinusFirst(MA_getSigArgMinusSigargsWsMinusAfterMinusFirst(arg)) : MA_getSigArgMinusSigargsWsMinusAfterMinusFirst(arg),
        acceptSep ? acceptSep(MA_getSigArgMinusSigargsSep(arg)) : MA_getSigArgMinusSigargsSep(arg),
        acceptWsMinusAfterMinusSep ? acceptWsMinusAfterMinusSep(MA_getSigArgMinusSigargsWsMinusAfterMinusSep(arg)) : MA_getSigArgMinusSigargsWsMinusAfterMinusSep(arg),
        MA_visitSigArgMinusSigargs(MA_getSigArgMinusSigargsTail(arg), acceptHead, acceptWsMinusAfterMinusFirst, acceptSep, acceptWsMinusAfterMinusSep));
  }
  ATabort("not a SigArgMinusSigargs: %t\n", arg);
  return (MA_SigArgMinusSigargs)NULL;
}

/*}}}  */
/*{{{  MA_FuncDefList MA_visitFuncDefList(MA_FuncDefList arg, MA_FuncDefMinusFuncdefs (*acceptFuncdefs)(MA_FuncDefMinusFuncdefs)) */

MA_FuncDefList MA_visitFuncDefList(MA_FuncDefList arg, MA_FuncDefMinusFuncdefs (*acceptFuncdefs)(MA_FuncDefMinusFuncdefs))
{
  if (MA_isFuncDefListDefault(arg)) {
    return MA_makeFuncDefListDefault(
        acceptFuncdefs ? acceptFuncdefs(MA_getFuncDefListFuncdefs(arg)) : MA_getFuncDefListFuncdefs(arg));
  }
  ATabort("not a FuncDefList: %t\n", arg);
  return (MA_FuncDefList)NULL;
}

/*}}}  */
/*{{{  MA_FuncDefMinusFuncdefs MA_visitFuncDefMinusFuncdefs(MA_FuncDefMinusFuncdefs arg, MA_FuncDef (*acceptHead)(MA_FuncDef), MA_Layout (*acceptWsMinusAfterMinusFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsMinusAfterMinusSep)(MA_Layout)) */

MA_FuncDefMinusFuncdefs MA_visitFuncDefMinusFuncdefs(MA_FuncDefMinusFuncdefs arg, MA_FuncDef (*acceptHead)(MA_FuncDef), MA_Layout (*acceptWsMinusAfterMinusFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsMinusAfterMinusSep)(MA_Layout))
{
  if (MA_isFuncDefMinusFuncdefsEmpty(arg)) {
    return MA_makeFuncDefMinusFuncdefsEmpty();
  }
  if (MA_isFuncDefMinusFuncdefsSingle(arg)) {
    return MA_makeFuncDefMinusFuncdefsSingle(
        acceptHead ? acceptHead(MA_getFuncDefMinusFuncdefsHead(arg)) : MA_getFuncDefMinusFuncdefsHead(arg));
  }
  if (MA_isFuncDefMinusFuncdefsMany(arg)) {
    return MA_makeFuncDefMinusFuncdefsMany(
        acceptHead ? acceptHead(MA_getFuncDefMinusFuncdefsHead(arg)) : MA_getFuncDefMinusFuncdefsHead(arg),
        acceptWsMinusAfterMinusFirst ? acceptWsMinusAfterMinusFirst(MA_getFuncDefMinusFuncdefsWsMinusAfterMinusFirst(arg)) : MA_getFuncDefMinusFuncdefsWsMinusAfterMinusFirst(arg),
        acceptSep ? acceptSep(MA_getFuncDefMinusFuncdefsSep(arg)) : MA_getFuncDefMinusFuncdefsSep(arg),
        acceptWsMinusAfterMinusSep ? acceptWsMinusAfterMinusSep(MA_getFuncDefMinusFuncdefsWsMinusAfterMinusSep(arg)) : MA_getFuncDefMinusFuncdefsWsMinusAfterMinusSep(arg),
        MA_visitFuncDefMinusFuncdefs(MA_getFuncDefMinusFuncdefsTail(arg), acceptHead, acceptWsMinusAfterMinusFirst, acceptSep, acceptWsMinusAfterMinusSep));
  }
  ATabort("not a FuncDefMinusFuncdefs: %t\n", arg);
  return (MA_FuncDefMinusFuncdefs)NULL;
}

/*}}}  */
/*{{{  MA_Rule MA_visitRule(MA_Rule arg, MA_Term (*acceptLhs)(MA_Term), MA_Layout (*acceptWsMinusAfterMinusLhs)(MA_Layout), MA_Layout (*acceptWsMinusAfterMinusEquals)(MA_Layout), MA_Term (*acceptRhs)(MA_Term), MA_Layout (*acceptWsMinusAfterMinusDefaultColon)(MA_Layout), MA_CondList (*acceptConds)(MA_CondList), MA_Layout (*acceptWsMinusAfterMinusConds)(MA_Layout), MA_Layout (*acceptWsMinusAfterMinusImplies)(MA_Layout)) */

MA_Rule MA_visitRule(MA_Rule arg, MA_Term (*acceptLhs)(MA_Term), MA_Layout (*acceptWsMinusAfterMinusLhs)(MA_Layout), MA_Layout (*acceptWsMinusAfterMinusEquals)(MA_Layout), MA_Term (*acceptRhs)(MA_Term), MA_Layout (*acceptWsMinusAfterMinusDefaultColon)(MA_Layout), MA_CondList (*acceptConds)(MA_CondList), MA_Layout (*acceptWsMinusAfterMinusConds)(MA_Layout), MA_Layout (*acceptWsMinusAfterMinusImplies)(MA_Layout))
{
  if (MA_isRuleNoMinusConds(arg)) {
    return MA_makeRuleNoMinusConds(
        acceptLhs ? acceptLhs(MA_getRuleLhs(arg)) : MA_getRuleLhs(arg),
        acceptWsMinusAfterMinusLhs ? acceptWsMinusAfterMinusLhs(MA_getRuleWsMinusAfterMinusLhs(arg)) : MA_getRuleWsMinusAfterMinusLhs(arg),
        acceptWsMinusAfterMinusEquals ? acceptWsMinusAfterMinusEquals(MA_getRuleWsMinusAfterMinusEquals(arg)) : MA_getRuleWsMinusAfterMinusEquals(arg),
        acceptRhs ? acceptRhs(MA_getRuleRhs(arg)) : MA_getRuleRhs(arg));
  }
  if (MA_isRuleDefaultMinusNoMinusConds(arg)) {
    return MA_makeRuleDefaultMinusNoMinusConds(
        acceptWsMinusAfterMinusDefaultColon ? acceptWsMinusAfterMinusDefaultColon(MA_getRuleWsMinusAfterMinusDefaultColon(arg)) : MA_getRuleWsMinusAfterMinusDefaultColon(arg),
        acceptLhs ? acceptLhs(MA_getRuleLhs(arg)) : MA_getRuleLhs(arg),
        acceptWsMinusAfterMinusLhs ? acceptWsMinusAfterMinusLhs(MA_getRuleWsMinusAfterMinusLhs(arg)) : MA_getRuleWsMinusAfterMinusLhs(arg),
        acceptWsMinusAfterMinusEquals ? acceptWsMinusAfterMinusEquals(MA_getRuleWsMinusAfterMinusEquals(arg)) : MA_getRuleWsMinusAfterMinusEquals(arg),
        acceptRhs ? acceptRhs(MA_getRuleRhs(arg)) : MA_getRuleRhs(arg));
  }
  if (MA_isRuleDefaultMinusWithMinusConds(arg)) {
    return MA_makeRuleDefaultMinusWithMinusConds(
        acceptWsMinusAfterMinusDefaultColon ? acceptWsMinusAfterMinusDefaultColon(MA_getRuleWsMinusAfterMinusDefaultColon(arg)) : MA_getRuleWsMinusAfterMinusDefaultColon(arg),
        acceptConds ? acceptConds(MA_getRuleConds(arg)) : MA_getRuleConds(arg),
        acceptWsMinusAfterMinusConds ? acceptWsMinusAfterMinusConds(MA_getRuleWsMinusAfterMinusConds(arg)) : MA_getRuleWsMinusAfterMinusConds(arg),
        acceptWsMinusAfterMinusImplies ? acceptWsMinusAfterMinusImplies(MA_getRuleWsMinusAfterMinusImplies(arg)) : MA_getRuleWsMinusAfterMinusImplies(arg),
        acceptLhs ? acceptLhs(MA_getRuleLhs(arg)) : MA_getRuleLhs(arg),
        acceptWsMinusAfterMinusLhs ? acceptWsMinusAfterMinusLhs(MA_getRuleWsMinusAfterMinusLhs(arg)) : MA_getRuleWsMinusAfterMinusLhs(arg),
        acceptWsMinusAfterMinusEquals ? acceptWsMinusAfterMinusEquals(MA_getRuleWsMinusAfterMinusEquals(arg)) : MA_getRuleWsMinusAfterMinusEquals(arg),
        acceptRhs ? acceptRhs(MA_getRuleRhs(arg)) : MA_getRuleRhs(arg));
  }
  if (MA_isRuleWithMinusConds(arg)) {
    return MA_makeRuleWithMinusConds(
        acceptConds ? acceptConds(MA_getRuleConds(arg)) : MA_getRuleConds(arg),
        acceptWsMinusAfterMinusConds ? acceptWsMinusAfterMinusConds(MA_getRuleWsMinusAfterMinusConds(arg)) : MA_getRuleWsMinusAfterMinusConds(arg),
        acceptWsMinusAfterMinusImplies ? acceptWsMinusAfterMinusImplies(MA_getRuleWsMinusAfterMinusImplies(arg)) : MA_getRuleWsMinusAfterMinusImplies(arg),
        acceptLhs ? acceptLhs(MA_getRuleLhs(arg)) : MA_getRuleLhs(arg),
        acceptWsMinusAfterMinusLhs ? acceptWsMinusAfterMinusLhs(MA_getRuleWsMinusAfterMinusLhs(arg)) : MA_getRuleWsMinusAfterMinusLhs(arg),
        acceptWsMinusAfterMinusEquals ? acceptWsMinusAfterMinusEquals(MA_getRuleWsMinusAfterMinusEquals(arg)) : MA_getRuleWsMinusAfterMinusEquals(arg),
        acceptRhs ? acceptRhs(MA_getRuleRhs(arg)) : MA_getRuleRhs(arg));
  }
  ATabort("not a Rule: %t\n", arg);
  return (MA_Rule)NULL;
}

/*}}}  */
/*{{{  MA_RuleList MA_visitRuleList(MA_RuleList arg, MA_RuleMinusRules (*acceptRules)(MA_RuleMinusRules)) */

MA_RuleList MA_visitRuleList(MA_RuleList arg, MA_RuleMinusRules (*acceptRules)(MA_RuleMinusRules))
{
  if (MA_isRuleListDefault(arg)) {
    return MA_makeRuleListDefault(
        acceptRules ? acceptRules(MA_getRuleListRules(arg)) : MA_getRuleListRules(arg));
  }
  ATabort("not a RuleList: %t\n", arg);
  return (MA_RuleList)NULL;
}

/*}}}  */
/*{{{  MA_RuleMinusRules MA_visitRuleMinusRules(MA_RuleMinusRules arg, MA_Rule (*acceptHead)(MA_Rule), MA_Layout (*acceptWsMinusAfterMinusFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsMinusAfterMinusSep)(MA_Layout)) */

MA_RuleMinusRules MA_visitRuleMinusRules(MA_RuleMinusRules arg, MA_Rule (*acceptHead)(MA_Rule), MA_Layout (*acceptWsMinusAfterMinusFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsMinusAfterMinusSep)(MA_Layout))
{
  if (MA_isRuleMinusRulesEmpty(arg)) {
    return MA_makeRuleMinusRulesEmpty();
  }
  if (MA_isRuleMinusRulesSingle(arg)) {
    return MA_makeRuleMinusRulesSingle(
        acceptHead ? acceptHead(MA_getRuleMinusRulesHead(arg)) : MA_getRuleMinusRulesHead(arg));
  }
  if (MA_isRuleMinusRulesMany(arg)) {
    return MA_makeRuleMinusRulesMany(
        acceptHead ? acceptHead(MA_getRuleMinusRulesHead(arg)) : MA_getRuleMinusRulesHead(arg),
        acceptWsMinusAfterMinusFirst ? acceptWsMinusAfterMinusFirst(MA_getRuleMinusRulesWsMinusAfterMinusFirst(arg)) : MA_getRuleMinusRulesWsMinusAfterMinusFirst(arg),
        acceptSep ? acceptSep(MA_getRuleMinusRulesSep(arg)) : MA_getRuleMinusRulesSep(arg),
        acceptWsMinusAfterMinusSep ? acceptWsMinusAfterMinusSep(MA_getRuleMinusRulesWsMinusAfterMinusSep(arg)) : MA_getRuleMinusRulesWsMinusAfterMinusSep(arg),
        MA_visitRuleMinusRules(MA_getRuleMinusRulesTail(arg), acceptHead, acceptWsMinusAfterMinusFirst, acceptSep, acceptWsMinusAfterMinusSep));
  }
  ATabort("not a RuleMinusRules: %t\n", arg);
  return (MA_RuleMinusRules)NULL;
}

/*}}}  */
/*{{{  MA_CondList MA_visitCondList(MA_CondList arg, MA_CondMinusConds (*acceptConds)(MA_CondMinusConds)) */

MA_CondList MA_visitCondList(MA_CondList arg, MA_CondMinusConds (*acceptConds)(MA_CondMinusConds))
{
  if (MA_isCondListDefault(arg)) {
    return MA_makeCondListDefault(
        acceptConds ? acceptConds(MA_getCondListConds(arg)) : MA_getCondListConds(arg));
  }
  ATabort("not a CondList: %t\n", arg);
  return (MA_CondList)NULL;
}

/*}}}  */
/*{{{  MA_CondMinusConds MA_visitCondMinusConds(MA_CondMinusConds arg, MA_Cond (*acceptHead)(MA_Cond), MA_Layout (*acceptWsMinusAfterMinusFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsMinusAfterMinusSep)(MA_Layout)) */

MA_CondMinusConds MA_visitCondMinusConds(MA_CondMinusConds arg, MA_Cond (*acceptHead)(MA_Cond), MA_Layout (*acceptWsMinusAfterMinusFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsMinusAfterMinusSep)(MA_Layout))
{
  if (MA_isCondMinusCondsEmpty(arg)) {
    return MA_makeCondMinusCondsEmpty();
  }
  if (MA_isCondMinusCondsSingle(arg)) {
    return MA_makeCondMinusCondsSingle(
        acceptHead ? acceptHead(MA_getCondMinusCondsHead(arg)) : MA_getCondMinusCondsHead(arg));
  }
  if (MA_isCondMinusCondsMany(arg)) {
    return MA_makeCondMinusCondsMany(
        acceptHead ? acceptHead(MA_getCondMinusCondsHead(arg)) : MA_getCondMinusCondsHead(arg),
        acceptWsMinusAfterMinusFirst ? acceptWsMinusAfterMinusFirst(MA_getCondMinusCondsWsMinusAfterMinusFirst(arg)) : MA_getCondMinusCondsWsMinusAfterMinusFirst(arg),
        acceptSep ? acceptSep(MA_getCondMinusCondsSep(arg)) : MA_getCondMinusCondsSep(arg),
        acceptWsMinusAfterMinusSep ? acceptWsMinusAfterMinusSep(MA_getCondMinusCondsWsMinusAfterMinusSep(arg)) : MA_getCondMinusCondsWsMinusAfterMinusSep(arg),
        MA_visitCondMinusConds(MA_getCondMinusCondsTail(arg), acceptHead, acceptWsMinusAfterMinusFirst, acceptSep, acceptWsMinusAfterMinusSep));
  }
  ATabort("not a CondMinusConds: %t\n", arg);
  return (MA_CondMinusConds)NULL;
}

/*}}}  */
/*{{{  MA_Cond MA_visitCond(MA_Cond arg, MA_Term (*acceptLhs)(MA_Term), MA_Layout (*acceptWsMinusAfterMinusLhs)(MA_Layout), MA_Layout (*acceptWsMinusAfterMinusAssign)(MA_Layout), MA_Term (*acceptRhs)(MA_Term), MA_Layout (*acceptWsMinusAfterMinusEqual)(MA_Layout), MA_Layout (*acceptWsMinusAfterMinusUnequal)(MA_Layout)) */

MA_Cond MA_visitCond(MA_Cond arg, MA_Term (*acceptLhs)(MA_Term), MA_Layout (*acceptWsMinusAfterMinusLhs)(MA_Layout), MA_Layout (*acceptWsMinusAfterMinusAssign)(MA_Layout), MA_Term (*acceptRhs)(MA_Term), MA_Layout (*acceptWsMinusAfterMinusEqual)(MA_Layout), MA_Layout (*acceptWsMinusAfterMinusUnequal)(MA_Layout))
{
  if (MA_isCondAssign(arg)) {
    return MA_makeCondAssign(
        acceptLhs ? acceptLhs(MA_getCondLhs(arg)) : MA_getCondLhs(arg),
        acceptWsMinusAfterMinusLhs ? acceptWsMinusAfterMinusLhs(MA_getCondWsMinusAfterMinusLhs(arg)) : MA_getCondWsMinusAfterMinusLhs(arg),
        acceptWsMinusAfterMinusAssign ? acceptWsMinusAfterMinusAssign(MA_getCondWsMinusAfterMinusAssign(arg)) : MA_getCondWsMinusAfterMinusAssign(arg),
        acceptRhs ? acceptRhs(MA_getCondRhs(arg)) : MA_getCondRhs(arg));
  }
  if (MA_isCondEqual(arg)) {
    return MA_makeCondEqual(
        acceptLhs ? acceptLhs(MA_getCondLhs(arg)) : MA_getCondLhs(arg),
        acceptWsMinusAfterMinusLhs ? acceptWsMinusAfterMinusLhs(MA_getCondWsMinusAfterMinusLhs(arg)) : MA_getCondWsMinusAfterMinusLhs(arg),
        acceptWsMinusAfterMinusEqual ? acceptWsMinusAfterMinusEqual(MA_getCondWsMinusAfterMinusEqual(arg)) : MA_getCondWsMinusAfterMinusEqual(arg),
        acceptRhs ? acceptRhs(MA_getCondRhs(arg)) : MA_getCondRhs(arg));
  }
  if (MA_isCondUnequal(arg)) {
    return MA_makeCondUnequal(
        acceptLhs ? acceptLhs(MA_getCondLhs(arg)) : MA_getCondLhs(arg),
        acceptWsMinusAfterMinusLhs ? acceptWsMinusAfterMinusLhs(MA_getCondWsMinusAfterMinusLhs(arg)) : MA_getCondWsMinusAfterMinusLhs(arg),
        acceptWsMinusAfterMinusUnequal ? acceptWsMinusAfterMinusUnequal(MA_getCondWsMinusAfterMinusUnequal(arg)) : MA_getCondWsMinusAfterMinusUnequal(arg),
        acceptRhs ? acceptRhs(MA_getCondRhs(arg)) : MA_getCondRhs(arg));
  }
  ATabort("not a Cond: %t\n", arg);
  return (MA_Cond)NULL;
}

/*}}}  */
/*{{{  MA_SignatureOpt MA_visitSignatureOpt(MA_SignatureOpt arg, MA_Layout (*acceptWsMinusAfterMinusSignature)(MA_Layout), MA_FuncDefList (*acceptFuncdefs)(MA_FuncDefList)) */

MA_SignatureOpt MA_visitSignatureOpt(MA_SignatureOpt arg, MA_Layout (*acceptWsMinusAfterMinusSignature)(MA_Layout), MA_FuncDefList (*acceptFuncdefs)(MA_FuncDefList))
{
  if (MA_isSignatureOptAbsent(arg)) {
    return MA_makeSignatureOptAbsent();
  }
  if (MA_isSignatureOptPresent(arg)) {
    return MA_makeSignatureOptPresent(
        acceptWsMinusAfterMinusSignature ? acceptWsMinusAfterMinusSignature(MA_getSignatureOptWsMinusAfterMinusSignature(arg)) : MA_getSignatureOptWsMinusAfterMinusSignature(arg),
        acceptFuncdefs ? acceptFuncdefs(MA_getSignatureOptFuncdefs(arg)) : MA_getSignatureOptFuncdefs(arg));
  }
  ATabort("not a SignatureOpt: %t\n", arg);
  return (MA_SignatureOpt)NULL;
}

/*}}}  */
/*{{{  MA_RulesOpt MA_visitRulesOpt(MA_RulesOpt arg, MA_Layout (*acceptWsMinusAfterMinusRules)(MA_Layout), MA_RuleList (*acceptRules)(MA_RuleList)) */

MA_RulesOpt MA_visitRulesOpt(MA_RulesOpt arg, MA_Layout (*acceptWsMinusAfterMinusRules)(MA_Layout), MA_RuleList (*acceptRules)(MA_RuleList))
{
  if (MA_isRulesOptAbsent(arg)) {
    return MA_makeRulesOptAbsent();
  }
  if (MA_isRulesOptPresent(arg)) {
    return MA_makeRulesOptPresent(
        acceptWsMinusAfterMinusRules ? acceptWsMinusAfterMinusRules(MA_getRulesOptWsMinusAfterMinusRules(arg)) : MA_getRulesOptWsMinusAfterMinusRules(arg),
        acceptRules ? acceptRules(MA_getRulesOptRules(arg)) : MA_getRulesOptRules(arg));
  }
  ATabort("not a RulesOpt: %t\n", arg);
  return (MA_RulesOpt)NULL;
}

/*}}}  */
/*{{{  MA_Module MA_visitModule(MA_Module arg, MA_Layout (*acceptWsMinusAfterMinusModule)(MA_Layout), MA_ModId (*acceptId)(MA_ModId), MA_Layout (*acceptWsMinusAfterMinusId)(MA_Layout), MA_SignatureOpt (*acceptSignature)(MA_SignatureOpt), MA_Layout (*acceptWsMinusAfterMinusSignature)(MA_Layout), MA_RulesOpt (*acceptRules)(MA_RulesOpt)) */

MA_Module MA_visitModule(MA_Module arg, MA_Layout (*acceptWsMinusAfterMinusModule)(MA_Layout), MA_ModId (*acceptId)(MA_ModId), MA_Layout (*acceptWsMinusAfterMinusId)(MA_Layout), MA_SignatureOpt (*acceptSignature)(MA_SignatureOpt), MA_Layout (*acceptWsMinusAfterMinusSignature)(MA_Layout), MA_RulesOpt (*acceptRules)(MA_RulesOpt))
{
  if (MA_isModuleModule(arg)) {
    return MA_makeModuleModule(
        acceptWsMinusAfterMinusModule ? acceptWsMinusAfterMinusModule(MA_getModuleWsMinusAfterMinusModule(arg)) : MA_getModuleWsMinusAfterMinusModule(arg),
        acceptId ? acceptId(MA_getModuleId(arg)) : MA_getModuleId(arg),
        acceptWsMinusAfterMinusId ? acceptWsMinusAfterMinusId(MA_getModuleWsMinusAfterMinusId(arg)) : MA_getModuleWsMinusAfterMinusId(arg),
        acceptSignature ? acceptSignature(MA_getModuleSignature(arg)) : MA_getModuleSignature(arg),
        acceptWsMinusAfterMinusSignature ? acceptWsMinusAfterMinusSignature(MA_getModuleWsMinusAfterMinusSignature(arg)) : MA_getModuleWsMinusAfterMinusSignature(arg),
        acceptRules ? acceptRules(MA_getModuleRules(arg)) : MA_getModuleRules(arg));
  }
  ATabort("not a Module: %t\n", arg);
  return (MA_Module)NULL;
}

/*}}}  */
/*{{{  MA_NamePair MA_visitNamePair(MA_NamePair arg, MA_Layout (*acceptWsMinusAfterMinusParenOpen)(MA_Layout), MA_FunId (*acceptProd)(MA_FunId), MA_Layout (*acceptWsMinusAfterMinusProd)(MA_Layout), MA_Layout (*acceptWsMinusAfterMinusComma)(MA_Layout), MA_FunId (*acceptFunc)(MA_FunId), MA_Layout (*acceptWsMinusAfterMinusFunc)(MA_Layout), MA_TermMinusAttributes (*acceptAttributes)(MA_TermMinusAttributes), MA_Layout (*acceptWsMinusAfterMinusAttributes)(MA_Layout)) */

MA_NamePair MA_visitNamePair(MA_NamePair arg, MA_Layout (*acceptWsMinusAfterMinusParenOpen)(MA_Layout), MA_FunId (*acceptProd)(MA_FunId), MA_Layout (*acceptWsMinusAfterMinusProd)(MA_Layout), MA_Layout (*acceptWsMinusAfterMinusComma)(MA_Layout), MA_FunId (*acceptFunc)(MA_FunId), MA_Layout (*acceptWsMinusAfterMinusFunc)(MA_Layout), MA_TermMinusAttributes (*acceptAttributes)(MA_TermMinusAttributes), MA_Layout (*acceptWsMinusAfterMinusAttributes)(MA_Layout))
{
  if (MA_isNamePairDefault(arg)) {
    return MA_makeNamePairDefault(
        acceptWsMinusAfterMinusParenOpen ? acceptWsMinusAfterMinusParenOpen(MA_getNamePairWsMinusAfterMinusParenOpen(arg)) : MA_getNamePairWsMinusAfterMinusParenOpen(arg),
        acceptProd ? acceptProd(MA_getNamePairProd(arg)) : MA_getNamePairProd(arg),
        acceptWsMinusAfterMinusProd ? acceptWsMinusAfterMinusProd(MA_getNamePairWsMinusAfterMinusProd(arg)) : MA_getNamePairWsMinusAfterMinusProd(arg),
        acceptWsMinusAfterMinusComma ? acceptWsMinusAfterMinusComma(MA_getNamePairWsMinusAfterMinusComma(arg)) : MA_getNamePairWsMinusAfterMinusComma(arg),
        acceptFunc ? acceptFunc(MA_getNamePairFunc(arg)) : MA_getNamePairFunc(arg),
        acceptWsMinusAfterMinusFunc ? acceptWsMinusAfterMinusFunc(MA_getNamePairWsMinusAfterMinusFunc(arg)) : MA_getNamePairWsMinusAfterMinusFunc(arg),
        acceptAttributes ? acceptAttributes(MA_getNamePairAttributes(arg)) : MA_getNamePairAttributes(arg),
        acceptWsMinusAfterMinusAttributes ? acceptWsMinusAfterMinusAttributes(MA_getNamePairWsMinusAfterMinusAttributes(arg)) : MA_getNamePairWsMinusAfterMinusAttributes(arg));
  }
  ATabort("not a NamePair: %t\n", arg);
  return (MA_NamePair)NULL;
}

/*}}}  */
/*{{{  MA_TermMinusAttributes MA_visitTermMinusAttributes(MA_TermMinusAttributes arg, MA_Term (*acceptHead)(MA_Term), MA_Layout (*acceptWsMinusAfterMinusFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsMinusAfterMinusSep)(MA_Layout)) */

MA_TermMinusAttributes MA_visitTermMinusAttributes(MA_TermMinusAttributes arg, MA_Term (*acceptHead)(MA_Term), MA_Layout (*acceptWsMinusAfterMinusFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsMinusAfterMinusSep)(MA_Layout))
{
  if (MA_isTermMinusAttributesEmpty(arg)) {
    return MA_makeTermMinusAttributesEmpty();
  }
  if (MA_isTermMinusAttributesSingle(arg)) {
    return MA_makeTermMinusAttributesSingle(
        acceptHead ? acceptHead(MA_getTermMinusAttributesHead(arg)) : MA_getTermMinusAttributesHead(arg));
  }
  if (MA_isTermMinusAttributesMany(arg)) {
    return MA_makeTermMinusAttributesMany(
        acceptHead ? acceptHead(MA_getTermMinusAttributesHead(arg)) : MA_getTermMinusAttributesHead(arg),
        acceptWsMinusAfterMinusFirst ? acceptWsMinusAfterMinusFirst(MA_getTermMinusAttributesWsMinusAfterMinusFirst(arg)) : MA_getTermMinusAttributesWsMinusAfterMinusFirst(arg),
        acceptSep ? acceptSep(MA_getTermMinusAttributesSep(arg)) : MA_getTermMinusAttributesSep(arg),
        acceptWsMinusAfterMinusSep ? acceptWsMinusAfterMinusSep(MA_getTermMinusAttributesWsMinusAfterMinusSep(arg)) : MA_getTermMinusAttributesWsMinusAfterMinusSep(arg),
        MA_visitTermMinusAttributes(MA_getTermMinusAttributesTail(arg), acceptHead, acceptWsMinusAfterMinusFirst, acceptSep, acceptWsMinusAfterMinusSep));
  }
  ATabort("not a TermMinusAttributes: %t\n", arg);
  return (MA_TermMinusAttributes)NULL;
}

/*}}}  */
/*{{{  MA_NameTable MA_visitNameTable(MA_NameTable arg, MA_Layout (*acceptWsMinusAfterMinusParenOpen)(MA_Layout), MA_NamePairMinusTable (*acceptTable)(MA_NamePairMinusTable), MA_Layout (*acceptWsMinusAfterMinusTable)(MA_Layout), MA_Layout (*acceptWsMinusAfterMinusComma)(MA_Layout), MA_FunId (*acceptId)(MA_FunId), MA_Layout (*acceptWsMinusAfterMinusId)(MA_Layout), MA_IntCon (*acceptLast)(MA_IntCon), MA_Layout (*acceptWsMinusAfterMinusLast)(MA_Layout), MA_IntCon (*acceptPrev)(MA_IntCon), MA_Layout (*acceptWsMinusAfterMinusPrev)(MA_Layout)) */

MA_NameTable MA_visitNameTable(MA_NameTable arg, MA_Layout (*acceptWsMinusAfterMinusParenOpen)(MA_Layout), MA_NamePairMinusTable (*acceptTable)(MA_NamePairMinusTable), MA_Layout (*acceptWsMinusAfterMinusTable)(MA_Layout), MA_Layout (*acceptWsMinusAfterMinusComma)(MA_Layout), MA_FunId (*acceptId)(MA_FunId), MA_Layout (*acceptWsMinusAfterMinusId)(MA_Layout), MA_IntCon (*acceptLast)(MA_IntCon), MA_Layout (*acceptWsMinusAfterMinusLast)(MA_Layout), MA_IntCon (*acceptPrev)(MA_IntCon), MA_Layout (*acceptWsMinusAfterMinusPrev)(MA_Layout))
{
  if (MA_isNameTableDefault(arg)) {
    return MA_makeNameTableDefault(
        acceptWsMinusAfterMinusParenOpen ? acceptWsMinusAfterMinusParenOpen(MA_getNameTableWsMinusAfterMinusParenOpen(arg)) : MA_getNameTableWsMinusAfterMinusParenOpen(arg),
        acceptTable ? acceptTable(MA_getNameTableTable(arg)) : MA_getNameTableTable(arg),
        acceptWsMinusAfterMinusTable ? acceptWsMinusAfterMinusTable(MA_getNameTableWsMinusAfterMinusTable(arg)) : MA_getNameTableWsMinusAfterMinusTable(arg),
        acceptWsMinusAfterMinusComma ? acceptWsMinusAfterMinusComma(MA_getNameTableWsMinusAfterMinusComma(arg)) : MA_getNameTableWsMinusAfterMinusComma(arg),
        acceptId ? acceptId(MA_getNameTableId(arg)) : MA_getNameTableId(arg),
        acceptWsMinusAfterMinusId ? acceptWsMinusAfterMinusId(MA_getNameTableWsMinusAfterMinusId(arg)) : MA_getNameTableWsMinusAfterMinusId(arg),
        acceptLast ? acceptLast(MA_getNameTableLast(arg)) : MA_getNameTableLast(arg),
        acceptWsMinusAfterMinusLast ? acceptWsMinusAfterMinusLast(MA_getNameTableWsMinusAfterMinusLast(arg)) : MA_getNameTableWsMinusAfterMinusLast(arg),
        acceptPrev ? acceptPrev(MA_getNameTablePrev(arg)) : MA_getNameTablePrev(arg),
        acceptWsMinusAfterMinusPrev ? acceptWsMinusAfterMinusPrev(MA_getNameTableWsMinusAfterMinusPrev(arg)) : MA_getNameTableWsMinusAfterMinusPrev(arg));
  }
  ATabort("not a NameTable: %t\n", arg);
  return (MA_NameTable)NULL;
}

/*}}}  */
/*{{{  MA_NamePairMinusTable MA_visitNamePairMinusTable(MA_NamePairMinusTable arg, MA_NamePair (*acceptHead)(MA_NamePair), MA_Layout (*acceptWsMinusAfterMinusFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsMinusAfterMinusSep)(MA_Layout)) */

MA_NamePairMinusTable MA_visitNamePairMinusTable(MA_NamePairMinusTable arg, MA_NamePair (*acceptHead)(MA_NamePair), MA_Layout (*acceptWsMinusAfterMinusFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsMinusAfterMinusSep)(MA_Layout))
{
  if (MA_isNamePairMinusTableEmpty(arg)) {
    return MA_makeNamePairMinusTableEmpty();
  }
  if (MA_isNamePairMinusTableSingle(arg)) {
    return MA_makeNamePairMinusTableSingle(
        acceptHead ? acceptHead(MA_getNamePairMinusTableHead(arg)) : MA_getNamePairMinusTableHead(arg));
  }
  if (MA_isNamePairMinusTableMany(arg)) {
    return MA_makeNamePairMinusTableMany(
        acceptHead ? acceptHead(MA_getNamePairMinusTableHead(arg)) : MA_getNamePairMinusTableHead(arg),
        acceptWsMinusAfterMinusFirst ? acceptWsMinusAfterMinusFirst(MA_getNamePairMinusTableWsMinusAfterMinusFirst(arg)) : MA_getNamePairMinusTableWsMinusAfterMinusFirst(arg),
        acceptSep ? acceptSep(MA_getNamePairMinusTableSep(arg)) : MA_getNamePairMinusTableSep(arg),
        acceptWsMinusAfterMinusSep ? acceptWsMinusAfterMinusSep(MA_getNamePairMinusTableWsMinusAfterMinusSep(arg)) : MA_getNamePairMinusTableWsMinusAfterMinusSep(arg),
        MA_visitNamePairMinusTable(MA_getNamePairMinusTableTail(arg), acceptHead, acceptWsMinusAfterMinusFirst, acceptSep, acceptWsMinusAfterMinusSep));
  }
  ATabort("not a NamePairMinusTable: %t\n", arg);
  return (MA_NamePairMinusTable)NULL;
}

/*}}}  */
/*{{{  MA_MNMinusStruct MA_visitMNMinusStruct(MA_MNMinusStruct arg, MA_Layout (*acceptWsMinusAfterMinusParenOpen)(MA_Layout), MA_Module (*acceptMod)(MA_Module), MA_Layout (*acceptWsMinusAfterMinusMod)(MA_Layout), MA_Layout (*acceptWsMinusAfterMinusComma)(MA_Layout), MA_NameTable (*acceptNametable)(MA_NameTable), MA_Layout (*acceptWsMinusAfterMinusNametable)(MA_Layout)) */

MA_MNMinusStruct MA_visitMNMinusStruct(MA_MNMinusStruct arg, MA_Layout (*acceptWsMinusAfterMinusParenOpen)(MA_Layout), MA_Module (*acceptMod)(MA_Module), MA_Layout (*acceptWsMinusAfterMinusMod)(MA_Layout), MA_Layout (*acceptWsMinusAfterMinusComma)(MA_Layout), MA_NameTable (*acceptNametable)(MA_NameTable), MA_Layout (*acceptWsMinusAfterMinusNametable)(MA_Layout))
{
  if (MA_isMNMinusStructDefault(arg)) {
    return MA_makeMNMinusStructDefault(
        acceptWsMinusAfterMinusParenOpen ? acceptWsMinusAfterMinusParenOpen(MA_getMNMinusStructWsMinusAfterMinusParenOpen(arg)) : MA_getMNMinusStructWsMinusAfterMinusParenOpen(arg),
        acceptMod ? acceptMod(MA_getMNMinusStructMod(arg)) : MA_getMNMinusStructMod(arg),
        acceptWsMinusAfterMinusMod ? acceptWsMinusAfterMinusMod(MA_getMNMinusStructWsMinusAfterMinusMod(arg)) : MA_getMNMinusStructWsMinusAfterMinusMod(arg),
        acceptWsMinusAfterMinusComma ? acceptWsMinusAfterMinusComma(MA_getMNMinusStructWsMinusAfterMinusComma(arg)) : MA_getMNMinusStructWsMinusAfterMinusComma(arg),
        acceptNametable ? acceptNametable(MA_getMNMinusStructNametable(arg)) : MA_getMNMinusStructNametable(arg),
        acceptWsMinusAfterMinusNametable ? acceptWsMinusAfterMinusNametable(MA_getMNMinusStructWsMinusAfterMinusNametable(arg)) : MA_getMNMinusStructWsMinusAfterMinusNametable(arg));
  }
  ATabort("not a MNMinusStruct: %t\n", arg);
  return (MA_MNMinusStruct)NULL;
}

/*}}}  */

/*}}}  */
