#ifndef _MUASF_H
#define _MUASF_H

/*{{{  includes */

#include <aterm1.h>
#include "MuASF_dict.h"

/*}}}  */

/*{{{  prologue */


typedef ATerm MA_Layout;
typedef ATerm MA_Literal;
typedef ATerm MA_VarId;
typedef ATerm MA_FunId;
typedef ATerm MA_ModId;

/*}}}  */
/*{{{  typedefs */

typedef struct _MA_Int *MA_Int;
typedef struct _MA_IntCon *MA_IntCon;
typedef struct _MA_NatCon *MA_NatCon;
typedef struct _MA_Var *MA_Var;
typedef struct _MA_Term *MA_Term;
typedef struct _MA_TermMinusArgs *MA_TermMinusArgs;
typedef struct _MA_TermList *MA_TermList;
typedef struct _MA_TermMinusTerms *MA_TermMinusTerms;
typedef struct _MA_SigArg *MA_SigArg;
typedef struct _MA_FuncDef *MA_FuncDef;
typedef struct _MA_SigArgMinusArgs *MA_SigArgMinusArgs;
typedef struct _MA_Annotations *MA_Annotations;
typedef struct _MA_SigArgList *MA_SigArgList;
typedef struct _MA_SigArgMinusSigargs *MA_SigArgMinusSigargs;
typedef struct _MA_FuncDefList *MA_FuncDefList;
typedef struct _MA_FuncDefMinusFuncdefs *MA_FuncDefMinusFuncdefs;
typedef struct _MA_Rule *MA_Rule;
typedef struct _MA_RuleList *MA_RuleList;
typedef struct _MA_RuleMinusRules *MA_RuleMinusRules;
typedef struct _MA_CondList *MA_CondList;
typedef struct _MA_CondMinusConds *MA_CondMinusConds;
typedef struct _MA_Cond *MA_Cond;
typedef struct _MA_SignatureOpt *MA_SignatureOpt;
typedef struct _MA_RulesOpt *MA_RulesOpt;
typedef struct _MA_Module *MA_Module;
typedef struct _MA_NamePair *MA_NamePair;
typedef struct _MA_TermMinusAttributes *MA_TermMinusAttributes;
typedef struct _MA_NameTable *MA_NameTable;
typedef struct _MA_NamePairMinusTable *MA_NamePairMinusTable;
typedef struct _MA_MNMinusStruct *MA_MNMinusStruct;

/*}}}  */

void MA_initMuASFApi(void);

/*{{{  term conversion functions */

MA_Int MA_IntFromTerm(ATerm t);
ATerm MA_IntToTerm(MA_Int arg);
MA_IntCon MA_IntConFromTerm(ATerm t);
ATerm MA_IntConToTerm(MA_IntCon arg);
MA_NatCon MA_NatConFromTerm(ATerm t);
ATerm MA_NatConToTerm(MA_NatCon arg);
MA_Var MA_VarFromTerm(ATerm t);
ATerm MA_VarToTerm(MA_Var arg);
MA_Term MA_TermFromTerm(ATerm t);
ATerm MA_TermToTerm(MA_Term arg);
MA_TermMinusArgs MA_TermMinusArgsFromTerm(ATerm t);
ATerm MA_TermMinusArgsToTerm(MA_TermMinusArgs arg);
MA_TermList MA_TermListFromTerm(ATerm t);
ATerm MA_TermListToTerm(MA_TermList arg);
MA_TermMinusTerms MA_TermMinusTermsFromTerm(ATerm t);
ATerm MA_TermMinusTermsToTerm(MA_TermMinusTerms arg);
MA_SigArg MA_SigArgFromTerm(ATerm t);
ATerm MA_SigArgToTerm(MA_SigArg arg);
MA_FuncDef MA_FuncDefFromTerm(ATerm t);
ATerm MA_FuncDefToTerm(MA_FuncDef arg);
MA_SigArgMinusArgs MA_SigArgMinusArgsFromTerm(ATerm t);
ATerm MA_SigArgMinusArgsToTerm(MA_SigArgMinusArgs arg);
MA_Annotations MA_AnnotationsFromTerm(ATerm t);
ATerm MA_AnnotationsToTerm(MA_Annotations arg);
MA_SigArgList MA_SigArgListFromTerm(ATerm t);
ATerm MA_SigArgListToTerm(MA_SigArgList arg);
MA_SigArgMinusSigargs MA_SigArgMinusSigargsFromTerm(ATerm t);
ATerm MA_SigArgMinusSigargsToTerm(MA_SigArgMinusSigargs arg);
MA_FuncDefList MA_FuncDefListFromTerm(ATerm t);
ATerm MA_FuncDefListToTerm(MA_FuncDefList arg);
MA_FuncDefMinusFuncdefs MA_FuncDefMinusFuncdefsFromTerm(ATerm t);
ATerm MA_FuncDefMinusFuncdefsToTerm(MA_FuncDefMinusFuncdefs arg);
MA_Rule MA_RuleFromTerm(ATerm t);
ATerm MA_RuleToTerm(MA_Rule arg);
MA_RuleList MA_RuleListFromTerm(ATerm t);
ATerm MA_RuleListToTerm(MA_RuleList arg);
MA_RuleMinusRules MA_RuleMinusRulesFromTerm(ATerm t);
ATerm MA_RuleMinusRulesToTerm(MA_RuleMinusRules arg);
MA_CondList MA_CondListFromTerm(ATerm t);
ATerm MA_CondListToTerm(MA_CondList arg);
MA_CondMinusConds MA_CondMinusCondsFromTerm(ATerm t);
ATerm MA_CondMinusCondsToTerm(MA_CondMinusConds arg);
MA_Cond MA_CondFromTerm(ATerm t);
ATerm MA_CondToTerm(MA_Cond arg);
MA_SignatureOpt MA_SignatureOptFromTerm(ATerm t);
ATerm MA_SignatureOptToTerm(MA_SignatureOpt arg);
MA_RulesOpt MA_RulesOptFromTerm(ATerm t);
ATerm MA_RulesOptToTerm(MA_RulesOpt arg);
MA_Module MA_ModuleFromTerm(ATerm t);
ATerm MA_ModuleToTerm(MA_Module arg);
MA_NamePair MA_NamePairFromTerm(ATerm t);
ATerm MA_NamePairToTerm(MA_NamePair arg);
MA_TermMinusAttributes MA_TermMinusAttributesFromTerm(ATerm t);
ATerm MA_TermMinusAttributesToTerm(MA_TermMinusAttributes arg);
MA_NameTable MA_NameTableFromTerm(ATerm t);
ATerm MA_NameTableToTerm(MA_NameTable arg);
MA_NamePairMinusTable MA_NamePairMinusTableFromTerm(ATerm t);
ATerm MA_NamePairMinusTableToTerm(MA_NamePairMinusTable arg);
MA_MNMinusStruct MA_MNMinusStructFromTerm(ATerm t);
ATerm MA_MNMinusStructToTerm(MA_MNMinusStruct arg);

/*}}}  */
/*{{{  constructors */

MA_Int MA_makeIntCon(MA_IntCon IntCon);
MA_Int MA_makeIntPlus(MA_Int lhs, MA_Layout wsMinusAfterMinusLhs, MA_Layout wsMinusAfterMinusPlus, MA_Int rhs);
MA_IntCon MA_makeIntConCon(MA_Layout wsMinusAfterMinusCon, MA_Layout wsMinusAfterMinusParenOpen, MA_Int intMinusArg, MA_Layout wsMinusAfterMinusIntMinusArg);
MA_IntCon MA_makeIntConNat(MA_NatCon NatCon);
MA_IntCon MA_makeIntConPos(MA_Layout wsMinusAfterMinusPlus, MA_NatCon natMinusArg);
MA_IntCon MA_makeIntConNeg(MA_Layout wsMinusAfterMinusMinus, MA_NatCon natMinusArg);
MA_NatCon MA_makeNatConAbs(MA_Layout wsMinusAfterMinusAbs, MA_Layout wsMinusAfterMinusParenOpen, MA_Int intMinusArg, MA_Layout wsMinusAfterMinusIntMinusArg);
MA_Var MA_makeVarNormal(MA_VarId VarId);
MA_Var MA_makeVarStar(MA_Layout wsMinusAfterMinusStar, MA_VarId VarId);
MA_Var MA_makeVarPlus(MA_Layout wsMinusAfterMinusPlus, MA_VarId VarId);
MA_Term MA_makeTermVar(MA_Var Var);
MA_Term MA_makeTermConstant(MA_FunId FunId);
MA_Term MA_makeTermInt(MA_Int Int);
MA_Term MA_makeTermFunc(MA_FunId FunId, MA_Layout wsMinusAfterMinusFunId, MA_Layout wsMinusAfterMinusParenOpen, MA_TermMinusArgs args, MA_Layout wsMinusAfterMinusArgs);
MA_TermMinusArgs MA_makeTermMinusArgsSingle(MA_Term head);
MA_TermMinusArgs MA_makeTermMinusArgsMany(MA_Term head, MA_Layout wsMinusAfterMinusFirst, char * sep, MA_Layout wsMinusAfterMinusSep, MA_TermMinusArgs tail);
MA_TermList MA_makeTermListDefault(MA_TermMinusTerms terms);
MA_TermMinusTerms MA_makeTermMinusTermsEmpty();
MA_TermMinusTerms MA_makeTermMinusTermsSingle(MA_Term head);
MA_TermMinusTerms MA_makeTermMinusTermsMany(MA_Term head, MA_Layout wsMinusAfterMinusFirst, char * sep, MA_Layout wsMinusAfterMinusSep, MA_TermMinusTerms tail);
MA_SigArg MA_makeSigArgNormal();
MA_SigArg MA_makeSigArgStar(MA_Layout wsMinusAfterMinusUnderscore);
MA_SigArg MA_makeSigArgPlus(MA_Layout wsMinusAfterMinusUnderscore);
MA_FuncDef MA_makeFuncDefConstantMinusNoMinusAnnos(MA_FunId FunId);
MA_FuncDef MA_makeFuncDefConstantMinusWithMinusAnnos(MA_FunId FunId, MA_Layout wsMinusAfterMinusFunId, MA_Annotations annos);
MA_FuncDef MA_makeFuncDefFuncMinusNoMinusAnnos(MA_FunId FunId, MA_Layout wsMinusAfterMinusFunId, MA_Layout wsMinusAfterMinusParenOpen, MA_SigArgMinusArgs args, MA_Layout wsMinusAfterMinusArgs);
MA_FuncDef MA_makeFuncDefFuncMinusWithMinusAnnos(MA_FunId FunId, MA_Layout wsMinusAfterMinusFunId, MA_Layout wsMinusAfterMinusParenOpen, MA_SigArgMinusArgs args, MA_Layout wsMinusAfterMinusArgs, MA_Layout wsMinusAfterMinusParenClose, MA_Annotations annos);
MA_SigArgMinusArgs MA_makeSigArgMinusArgsSingle(MA_SigArg head);
MA_SigArgMinusArgs MA_makeSigArgMinusArgsMany(MA_SigArg head, MA_Layout wsMinusAfterMinusFirst, char * sep, MA_Layout wsMinusAfterMinusSep, MA_SigArgMinusArgs tail);
MA_Annotations MA_makeAnnotationsDefault(MA_Layout wsMinusAfterMinusBraceOpen, MA_TermMinusTerms terms, MA_Layout wsMinusAfterMinusTerms);
MA_SigArgList MA_makeSigArgListDefault(MA_SigArgMinusSigargs sigargs);
MA_SigArgMinusSigargs MA_makeSigArgMinusSigargsSingle(MA_SigArg head);
MA_SigArgMinusSigargs MA_makeSigArgMinusSigargsMany(MA_SigArg head, MA_Layout wsMinusAfterMinusFirst, char * sep, MA_Layout wsMinusAfterMinusSep, MA_SigArgMinusSigargs tail);
MA_FuncDefList MA_makeFuncDefListDefault(MA_FuncDefMinusFuncdefs funcdefs);
MA_FuncDefMinusFuncdefs MA_makeFuncDefMinusFuncdefsEmpty();
MA_FuncDefMinusFuncdefs MA_makeFuncDefMinusFuncdefsSingle(MA_FuncDef head);
MA_FuncDefMinusFuncdefs MA_makeFuncDefMinusFuncdefsMany(MA_FuncDef head, MA_Layout wsMinusAfterMinusFirst, char * sep, MA_Layout wsMinusAfterMinusSep, MA_FuncDefMinusFuncdefs tail);
MA_Rule MA_makeRuleNoMinusConds(MA_Term lhs, MA_Layout wsMinusAfterMinusLhs, MA_Layout wsMinusAfterMinusEquals, MA_Term rhs);
MA_Rule MA_makeRuleDefaultMinusNoMinusConds(MA_Layout wsMinusAfterMinusDefaultColon, MA_Term lhs, MA_Layout wsMinusAfterMinusLhs, MA_Layout wsMinusAfterMinusEquals, MA_Term rhs);
MA_Rule MA_makeRuleDefaultMinusWithMinusConds(MA_Layout wsMinusAfterMinusDefaultColon, MA_CondList conds, MA_Layout wsMinusAfterMinusConds, MA_Layout wsMinusAfterMinusImplies, MA_Term lhs, MA_Layout wsMinusAfterMinusLhs, MA_Layout wsMinusAfterMinusEquals, MA_Term rhs);
MA_Rule MA_makeRuleWithMinusConds(MA_CondList conds, MA_Layout wsMinusAfterMinusConds, MA_Layout wsMinusAfterMinusImplies, MA_Term lhs, MA_Layout wsMinusAfterMinusLhs, MA_Layout wsMinusAfterMinusEquals, MA_Term rhs);
MA_RuleList MA_makeRuleListDefault(MA_RuleMinusRules rules);
MA_RuleMinusRules MA_makeRuleMinusRulesEmpty();
MA_RuleMinusRules MA_makeRuleMinusRulesSingle(MA_Rule head);
MA_RuleMinusRules MA_makeRuleMinusRulesMany(MA_Rule head, MA_Layout wsMinusAfterMinusFirst, char * sep, MA_Layout wsMinusAfterMinusSep, MA_RuleMinusRules tail);
MA_CondList MA_makeCondListDefault(MA_CondMinusConds conds);
MA_CondMinusConds MA_makeCondMinusCondsEmpty();
MA_CondMinusConds MA_makeCondMinusCondsSingle(MA_Cond head);
MA_CondMinusConds MA_makeCondMinusCondsMany(MA_Cond head, MA_Layout wsMinusAfterMinusFirst, char * sep, MA_Layout wsMinusAfterMinusSep, MA_CondMinusConds tail);
MA_Cond MA_makeCondAssign(MA_Term lhs, MA_Layout wsMinusAfterMinusLhs, MA_Layout wsMinusAfterMinusAssign, MA_Term rhs);
MA_Cond MA_makeCondEqual(MA_Term lhs, MA_Layout wsMinusAfterMinusLhs, MA_Layout wsMinusAfterMinusEqual, MA_Term rhs);
MA_Cond MA_makeCondUnequal(MA_Term lhs, MA_Layout wsMinusAfterMinusLhs, MA_Layout wsMinusAfterMinusUnequal, MA_Term rhs);
MA_SignatureOpt MA_makeSignatureOptAbsent();
MA_SignatureOpt MA_makeSignatureOptPresent(MA_Layout wsMinusAfterMinusSignature, MA_FuncDefList funcdefs);
MA_RulesOpt MA_makeRulesOptAbsent();
MA_RulesOpt MA_makeRulesOptPresent(MA_Layout wsMinusAfterMinusRules, MA_RuleList rules);
MA_Module MA_makeModuleModule(MA_Layout wsMinusAfterMinusModule, MA_ModId id, MA_Layout wsMinusAfterMinusId, MA_SignatureOpt signature, MA_Layout wsMinusAfterMinusSignature, MA_RulesOpt rules);
MA_NamePair MA_makeNamePairDefault(MA_Layout wsMinusAfterMinusParenOpen, MA_FunId prod, MA_Layout wsMinusAfterMinusProd, MA_Layout wsMinusAfterMinusComma, MA_FunId func, MA_Layout wsMinusAfterMinusFunc, MA_TermMinusAttributes attributes, MA_Layout wsMinusAfterMinusAttributes);
MA_TermMinusAttributes MA_makeTermMinusAttributesEmpty();
MA_TermMinusAttributes MA_makeTermMinusAttributesSingle(MA_Term head);
MA_TermMinusAttributes MA_makeTermMinusAttributesMany(MA_Term head, MA_Layout wsMinusAfterMinusFirst, char * sep, MA_Layout wsMinusAfterMinusSep, MA_TermMinusAttributes tail);
MA_NameTable MA_makeNameTableDefault(MA_Layout wsMinusAfterMinusParenOpen, MA_NamePairMinusTable table, MA_Layout wsMinusAfterMinusTable, MA_Layout wsMinusAfterMinusComma, MA_FunId id, MA_Layout wsMinusAfterMinusId, MA_IntCon last, MA_Layout wsMinusAfterMinusLast, MA_IntCon prev, MA_Layout wsMinusAfterMinusPrev);
MA_NamePairMinusTable MA_makeNamePairMinusTableEmpty();
MA_NamePairMinusTable MA_makeNamePairMinusTableSingle(MA_NamePair head);
MA_NamePairMinusTable MA_makeNamePairMinusTableMany(MA_NamePair head, MA_Layout wsMinusAfterMinusFirst, char * sep, MA_Layout wsMinusAfterMinusSep, MA_NamePairMinusTable tail);
MA_MNMinusStruct MA_makeMNMinusStructDefault(MA_Layout wsMinusAfterMinusParenOpen, MA_Module mod, MA_Layout wsMinusAfterMinusMod, MA_Layout wsMinusAfterMinusComma, MA_NameTable nametable, MA_Layout wsMinusAfterMinusNametable);

/*}}}  */
/*{{{  equality functions */

ATbool MA_isEqualInt(MA_Int arg0, MA_Int arg1);
ATbool MA_isEqualIntCon(MA_IntCon arg0, MA_IntCon arg1);
ATbool MA_isEqualNatCon(MA_NatCon arg0, MA_NatCon arg1);
ATbool MA_isEqualVar(MA_Var arg0, MA_Var arg1);
ATbool MA_isEqualTerm(MA_Term arg0, MA_Term arg1);
ATbool MA_isEqualTermMinusArgs(MA_TermMinusArgs arg0, MA_TermMinusArgs arg1);
ATbool MA_isEqualTermList(MA_TermList arg0, MA_TermList arg1);
ATbool MA_isEqualTermMinusTerms(MA_TermMinusTerms arg0, MA_TermMinusTerms arg1);
ATbool MA_isEqualSigArg(MA_SigArg arg0, MA_SigArg arg1);
ATbool MA_isEqualFuncDef(MA_FuncDef arg0, MA_FuncDef arg1);
ATbool MA_isEqualSigArgMinusArgs(MA_SigArgMinusArgs arg0, MA_SigArgMinusArgs arg1);
ATbool MA_isEqualAnnotations(MA_Annotations arg0, MA_Annotations arg1);
ATbool MA_isEqualSigArgList(MA_SigArgList arg0, MA_SigArgList arg1);
ATbool MA_isEqualSigArgMinusSigargs(MA_SigArgMinusSigargs arg0, MA_SigArgMinusSigargs arg1);
ATbool MA_isEqualFuncDefList(MA_FuncDefList arg0, MA_FuncDefList arg1);
ATbool MA_isEqualFuncDefMinusFuncdefs(MA_FuncDefMinusFuncdefs arg0, MA_FuncDefMinusFuncdefs arg1);
ATbool MA_isEqualRule(MA_Rule arg0, MA_Rule arg1);
ATbool MA_isEqualRuleList(MA_RuleList arg0, MA_RuleList arg1);
ATbool MA_isEqualRuleMinusRules(MA_RuleMinusRules arg0, MA_RuleMinusRules arg1);
ATbool MA_isEqualCondList(MA_CondList arg0, MA_CondList arg1);
ATbool MA_isEqualCondMinusConds(MA_CondMinusConds arg0, MA_CondMinusConds arg1);
ATbool MA_isEqualCond(MA_Cond arg0, MA_Cond arg1);
ATbool MA_isEqualSignatureOpt(MA_SignatureOpt arg0, MA_SignatureOpt arg1);
ATbool MA_isEqualRulesOpt(MA_RulesOpt arg0, MA_RulesOpt arg1);
ATbool MA_isEqualModule(MA_Module arg0, MA_Module arg1);
ATbool MA_isEqualNamePair(MA_NamePair arg0, MA_NamePair arg1);
ATbool MA_isEqualTermMinusAttributes(MA_TermMinusAttributes arg0, MA_TermMinusAttributes arg1);
ATbool MA_isEqualNameTable(MA_NameTable arg0, MA_NameTable arg1);
ATbool MA_isEqualNamePairMinusTable(MA_NamePairMinusTable arg0, MA_NamePairMinusTable arg1);
ATbool MA_isEqualMNMinusStruct(MA_MNMinusStruct arg0, MA_MNMinusStruct arg1);

/*}}}  */
/*{{{  MA_Int accessors */

ATbool MA_isValidInt(MA_Int arg);
inline ATbool MA_isIntCon(MA_Int arg);
inline ATbool MA_isIntPlus(MA_Int arg);
ATbool MA_hasIntIntCon(MA_Int arg);
MA_IntCon MA_getIntIntCon(MA_Int arg);
MA_Int MA_setIntIntCon(MA_Int arg, MA_IntCon IntCon);
ATbool MA_hasIntLhs(MA_Int arg);
MA_Int MA_getIntLhs(MA_Int arg);
MA_Int MA_setIntLhs(MA_Int arg, MA_Int lhs);
ATbool MA_hasIntWsMinusAfterMinusLhs(MA_Int arg);
MA_Layout MA_getIntWsMinusAfterMinusLhs(MA_Int arg);
MA_Int MA_setIntWsMinusAfterMinusLhs(MA_Int arg, MA_Layout wsMinusAfterMinusLhs);
ATbool MA_hasIntWsMinusAfterMinusPlus(MA_Int arg);
MA_Layout MA_getIntWsMinusAfterMinusPlus(MA_Int arg);
MA_Int MA_setIntWsMinusAfterMinusPlus(MA_Int arg, MA_Layout wsMinusAfterMinusPlus);
ATbool MA_hasIntRhs(MA_Int arg);
MA_Int MA_getIntRhs(MA_Int arg);
MA_Int MA_setIntRhs(MA_Int arg, MA_Int rhs);

/*}}}  */
/*{{{  MA_IntCon accessors */

ATbool MA_isValidIntCon(MA_IntCon arg);
inline ATbool MA_isIntConCon(MA_IntCon arg);
inline ATbool MA_isIntConNat(MA_IntCon arg);
inline ATbool MA_isIntConPos(MA_IntCon arg);
inline ATbool MA_isIntConNeg(MA_IntCon arg);
ATbool MA_hasIntConWsMinusAfterMinusCon(MA_IntCon arg);
MA_Layout MA_getIntConWsMinusAfterMinusCon(MA_IntCon arg);
MA_IntCon MA_setIntConWsMinusAfterMinusCon(MA_IntCon arg, MA_Layout wsMinusAfterMinusCon);
ATbool MA_hasIntConWsMinusAfterMinusParenOpen(MA_IntCon arg);
MA_Layout MA_getIntConWsMinusAfterMinusParenOpen(MA_IntCon arg);
MA_IntCon MA_setIntConWsMinusAfterMinusParenOpen(MA_IntCon arg, MA_Layout wsMinusAfterMinusParenOpen);
ATbool MA_hasIntConIntMinusArg(MA_IntCon arg);
MA_Int MA_getIntConIntMinusArg(MA_IntCon arg);
MA_IntCon MA_setIntConIntMinusArg(MA_IntCon arg, MA_Int intMinusArg);
ATbool MA_hasIntConWsMinusAfterMinusIntMinusArg(MA_IntCon arg);
MA_Layout MA_getIntConWsMinusAfterMinusIntMinusArg(MA_IntCon arg);
MA_IntCon MA_setIntConWsMinusAfterMinusIntMinusArg(MA_IntCon arg, MA_Layout wsMinusAfterMinusIntMinusArg);
ATbool MA_hasIntConNatCon(MA_IntCon arg);
MA_NatCon MA_getIntConNatCon(MA_IntCon arg);
MA_IntCon MA_setIntConNatCon(MA_IntCon arg, MA_NatCon NatCon);
ATbool MA_hasIntConWsMinusAfterMinusPlus(MA_IntCon arg);
MA_Layout MA_getIntConWsMinusAfterMinusPlus(MA_IntCon arg);
MA_IntCon MA_setIntConWsMinusAfterMinusPlus(MA_IntCon arg, MA_Layout wsMinusAfterMinusPlus);
ATbool MA_hasIntConNatMinusArg(MA_IntCon arg);
MA_NatCon MA_getIntConNatMinusArg(MA_IntCon arg);
MA_IntCon MA_setIntConNatMinusArg(MA_IntCon arg, MA_NatCon natMinusArg);
ATbool MA_hasIntConWsMinusAfterMinusMinus(MA_IntCon arg);
MA_Layout MA_getIntConWsMinusAfterMinusMinus(MA_IntCon arg);
MA_IntCon MA_setIntConWsMinusAfterMinusMinus(MA_IntCon arg, MA_Layout wsMinusAfterMinusMinus);

/*}}}  */
/*{{{  MA_NatCon accessors */

ATbool MA_isValidNatCon(MA_NatCon arg);
inline ATbool MA_isNatConAbs(MA_NatCon arg);
ATbool MA_hasNatConWsMinusAfterMinusAbs(MA_NatCon arg);
MA_Layout MA_getNatConWsMinusAfterMinusAbs(MA_NatCon arg);
MA_NatCon MA_setNatConWsMinusAfterMinusAbs(MA_NatCon arg, MA_Layout wsMinusAfterMinusAbs);
ATbool MA_hasNatConWsMinusAfterMinusParenOpen(MA_NatCon arg);
MA_Layout MA_getNatConWsMinusAfterMinusParenOpen(MA_NatCon arg);
MA_NatCon MA_setNatConWsMinusAfterMinusParenOpen(MA_NatCon arg, MA_Layout wsMinusAfterMinusParenOpen);
ATbool MA_hasNatConIntMinusArg(MA_NatCon arg);
MA_Int MA_getNatConIntMinusArg(MA_NatCon arg);
MA_NatCon MA_setNatConIntMinusArg(MA_NatCon arg, MA_Int intMinusArg);
ATbool MA_hasNatConWsMinusAfterMinusIntMinusArg(MA_NatCon arg);
MA_Layout MA_getNatConWsMinusAfterMinusIntMinusArg(MA_NatCon arg);
MA_NatCon MA_setNatConWsMinusAfterMinusIntMinusArg(MA_NatCon arg, MA_Layout wsMinusAfterMinusIntMinusArg);

/*}}}  */
/*{{{  MA_Var accessors */

ATbool MA_isValidVar(MA_Var arg);
inline ATbool MA_isVarNormal(MA_Var arg);
inline ATbool MA_isVarStar(MA_Var arg);
inline ATbool MA_isVarPlus(MA_Var arg);
ATbool MA_hasVarVarId(MA_Var arg);
MA_VarId MA_getVarVarId(MA_Var arg);
MA_Var MA_setVarVarId(MA_Var arg, MA_VarId VarId);
ATbool MA_hasVarWsMinusAfterMinusStar(MA_Var arg);
MA_Layout MA_getVarWsMinusAfterMinusStar(MA_Var arg);
MA_Var MA_setVarWsMinusAfterMinusStar(MA_Var arg, MA_Layout wsMinusAfterMinusStar);
ATbool MA_hasVarWsMinusAfterMinusPlus(MA_Var arg);
MA_Layout MA_getVarWsMinusAfterMinusPlus(MA_Var arg);
MA_Var MA_setVarWsMinusAfterMinusPlus(MA_Var arg, MA_Layout wsMinusAfterMinusPlus);

/*}}}  */
/*{{{  MA_Term accessors */

ATbool MA_isValidTerm(MA_Term arg);
inline ATbool MA_isTermVar(MA_Term arg);
inline ATbool MA_isTermConstant(MA_Term arg);
inline ATbool MA_isTermInt(MA_Term arg);
inline ATbool MA_isTermFunc(MA_Term arg);
ATbool MA_hasTermVar(MA_Term arg);
MA_Var MA_getTermVar(MA_Term arg);
MA_Term MA_setTermVar(MA_Term arg, MA_Var Var);
ATbool MA_hasTermFunId(MA_Term arg);
MA_FunId MA_getTermFunId(MA_Term arg);
MA_Term MA_setTermFunId(MA_Term arg, MA_FunId FunId);
ATbool MA_hasTermInt(MA_Term arg);
MA_Int MA_getTermInt(MA_Term arg);
MA_Term MA_setTermInt(MA_Term arg, MA_Int Int);
ATbool MA_hasTermWsMinusAfterMinusFunId(MA_Term arg);
MA_Layout MA_getTermWsMinusAfterMinusFunId(MA_Term arg);
MA_Term MA_setTermWsMinusAfterMinusFunId(MA_Term arg, MA_Layout wsMinusAfterMinusFunId);
ATbool MA_hasTermWsMinusAfterMinusParenOpen(MA_Term arg);
MA_Layout MA_getTermWsMinusAfterMinusParenOpen(MA_Term arg);
MA_Term MA_setTermWsMinusAfterMinusParenOpen(MA_Term arg, MA_Layout wsMinusAfterMinusParenOpen);
ATbool MA_hasTermArgs(MA_Term arg);
MA_TermMinusArgs MA_getTermArgs(MA_Term arg);
MA_Term MA_setTermArgs(MA_Term arg, MA_TermMinusArgs args);
ATbool MA_hasTermWsMinusAfterMinusArgs(MA_Term arg);
MA_Layout MA_getTermWsMinusAfterMinusArgs(MA_Term arg);
MA_Term MA_setTermWsMinusAfterMinusArgs(MA_Term arg, MA_Layout wsMinusAfterMinusArgs);

/*}}}  */
/*{{{  MA_TermMinusArgs accessors */

ATbool MA_isValidTermMinusArgs(MA_TermMinusArgs arg);
inline ATbool MA_isTermMinusArgsSingle(MA_TermMinusArgs arg);
inline ATbool MA_isTermMinusArgsMany(MA_TermMinusArgs arg);
ATbool MA_hasTermMinusArgsHead(MA_TermMinusArgs arg);
MA_Term MA_getTermMinusArgsHead(MA_TermMinusArgs arg);
MA_TermMinusArgs MA_setTermMinusArgsHead(MA_TermMinusArgs arg, MA_Term head);
ATbool MA_hasTermMinusArgsWsMinusAfterMinusFirst(MA_TermMinusArgs arg);
MA_Layout MA_getTermMinusArgsWsMinusAfterMinusFirst(MA_TermMinusArgs arg);
MA_TermMinusArgs MA_setTermMinusArgsWsMinusAfterMinusFirst(MA_TermMinusArgs arg, MA_Layout wsMinusAfterMinusFirst);
ATbool MA_hasTermMinusArgsSep(MA_TermMinusArgs arg);
char * MA_getTermMinusArgsSep(MA_TermMinusArgs arg);
MA_TermMinusArgs MA_setTermMinusArgsSep(MA_TermMinusArgs arg, char * sep);
ATbool MA_hasTermMinusArgsWsMinusAfterMinusSep(MA_TermMinusArgs arg);
MA_Layout MA_getTermMinusArgsWsMinusAfterMinusSep(MA_TermMinusArgs arg);
MA_TermMinusArgs MA_setTermMinusArgsWsMinusAfterMinusSep(MA_TermMinusArgs arg, MA_Layout wsMinusAfterMinusSep);
ATbool MA_hasTermMinusArgsTail(MA_TermMinusArgs arg);
MA_TermMinusArgs MA_getTermMinusArgsTail(MA_TermMinusArgs arg);
MA_TermMinusArgs MA_setTermMinusArgsTail(MA_TermMinusArgs arg, MA_TermMinusArgs tail);

/*}}}  */
/*{{{  MA_TermList accessors */

ATbool MA_isValidTermList(MA_TermList arg);
inline ATbool MA_isTermListDefault(MA_TermList arg);
ATbool MA_hasTermListTerms(MA_TermList arg);
MA_TermMinusTerms MA_getTermListTerms(MA_TermList arg);
MA_TermList MA_setTermListTerms(MA_TermList arg, MA_TermMinusTerms terms);

/*}}}  */
/*{{{  MA_TermMinusTerms accessors */

ATbool MA_isValidTermMinusTerms(MA_TermMinusTerms arg);
inline ATbool MA_isTermMinusTermsEmpty(MA_TermMinusTerms arg);
inline ATbool MA_isTermMinusTermsSingle(MA_TermMinusTerms arg);
inline ATbool MA_isTermMinusTermsMany(MA_TermMinusTerms arg);
ATbool MA_hasTermMinusTermsHead(MA_TermMinusTerms arg);
MA_Term MA_getTermMinusTermsHead(MA_TermMinusTerms arg);
MA_TermMinusTerms MA_setTermMinusTermsHead(MA_TermMinusTerms arg, MA_Term head);
ATbool MA_hasTermMinusTermsWsMinusAfterMinusFirst(MA_TermMinusTerms arg);
MA_Layout MA_getTermMinusTermsWsMinusAfterMinusFirst(MA_TermMinusTerms arg);
MA_TermMinusTerms MA_setTermMinusTermsWsMinusAfterMinusFirst(MA_TermMinusTerms arg, MA_Layout wsMinusAfterMinusFirst);
ATbool MA_hasTermMinusTermsSep(MA_TermMinusTerms arg);
char * MA_getTermMinusTermsSep(MA_TermMinusTerms arg);
MA_TermMinusTerms MA_setTermMinusTermsSep(MA_TermMinusTerms arg, char * sep);
ATbool MA_hasTermMinusTermsWsMinusAfterMinusSep(MA_TermMinusTerms arg);
MA_Layout MA_getTermMinusTermsWsMinusAfterMinusSep(MA_TermMinusTerms arg);
MA_TermMinusTerms MA_setTermMinusTermsWsMinusAfterMinusSep(MA_TermMinusTerms arg, MA_Layout wsMinusAfterMinusSep);
ATbool MA_hasTermMinusTermsTail(MA_TermMinusTerms arg);
MA_TermMinusTerms MA_getTermMinusTermsTail(MA_TermMinusTerms arg);
MA_TermMinusTerms MA_setTermMinusTermsTail(MA_TermMinusTerms arg, MA_TermMinusTerms tail);

/*}}}  */
/*{{{  MA_SigArg accessors */

ATbool MA_isValidSigArg(MA_SigArg arg);
inline ATbool MA_isSigArgNormal(MA_SigArg arg);
inline ATbool MA_isSigArgStar(MA_SigArg arg);
inline ATbool MA_isSigArgPlus(MA_SigArg arg);
ATbool MA_hasSigArgWsMinusAfterMinusUnderscore(MA_SigArg arg);
MA_Layout MA_getSigArgWsMinusAfterMinusUnderscore(MA_SigArg arg);
MA_SigArg MA_setSigArgWsMinusAfterMinusUnderscore(MA_SigArg arg, MA_Layout wsMinusAfterMinusUnderscore);

/*}}}  */
/*{{{  MA_FuncDef accessors */

ATbool MA_isValidFuncDef(MA_FuncDef arg);
inline ATbool MA_isFuncDefConstantMinusNoMinusAnnos(MA_FuncDef arg);
inline ATbool MA_isFuncDefConstantMinusWithMinusAnnos(MA_FuncDef arg);
inline ATbool MA_isFuncDefFuncMinusNoMinusAnnos(MA_FuncDef arg);
inline ATbool MA_isFuncDefFuncMinusWithMinusAnnos(MA_FuncDef arg);
ATbool MA_hasFuncDefFunId(MA_FuncDef arg);
MA_FunId MA_getFuncDefFunId(MA_FuncDef arg);
MA_FuncDef MA_setFuncDefFunId(MA_FuncDef arg, MA_FunId FunId);
ATbool MA_hasFuncDefWsMinusAfterMinusFunId(MA_FuncDef arg);
MA_Layout MA_getFuncDefWsMinusAfterMinusFunId(MA_FuncDef arg);
MA_FuncDef MA_setFuncDefWsMinusAfterMinusFunId(MA_FuncDef arg, MA_Layout wsMinusAfterMinusFunId);
ATbool MA_hasFuncDefAnnos(MA_FuncDef arg);
MA_Annotations MA_getFuncDefAnnos(MA_FuncDef arg);
MA_FuncDef MA_setFuncDefAnnos(MA_FuncDef arg, MA_Annotations annos);
ATbool MA_hasFuncDefWsMinusAfterMinusParenOpen(MA_FuncDef arg);
MA_Layout MA_getFuncDefWsMinusAfterMinusParenOpen(MA_FuncDef arg);
MA_FuncDef MA_setFuncDefWsMinusAfterMinusParenOpen(MA_FuncDef arg, MA_Layout wsMinusAfterMinusParenOpen);
ATbool MA_hasFuncDefArgs(MA_FuncDef arg);
MA_SigArgMinusArgs MA_getFuncDefArgs(MA_FuncDef arg);
MA_FuncDef MA_setFuncDefArgs(MA_FuncDef arg, MA_SigArgMinusArgs args);
ATbool MA_hasFuncDefWsMinusAfterMinusArgs(MA_FuncDef arg);
MA_Layout MA_getFuncDefWsMinusAfterMinusArgs(MA_FuncDef arg);
MA_FuncDef MA_setFuncDefWsMinusAfterMinusArgs(MA_FuncDef arg, MA_Layout wsMinusAfterMinusArgs);
ATbool MA_hasFuncDefWsMinusAfterMinusParenClose(MA_FuncDef arg);
MA_Layout MA_getFuncDefWsMinusAfterMinusParenClose(MA_FuncDef arg);
MA_FuncDef MA_setFuncDefWsMinusAfterMinusParenClose(MA_FuncDef arg, MA_Layout wsMinusAfterMinusParenClose);

/*}}}  */
/*{{{  MA_SigArgMinusArgs accessors */

ATbool MA_isValidSigArgMinusArgs(MA_SigArgMinusArgs arg);
inline ATbool MA_isSigArgMinusArgsSingle(MA_SigArgMinusArgs arg);
inline ATbool MA_isSigArgMinusArgsMany(MA_SigArgMinusArgs arg);
ATbool MA_hasSigArgMinusArgsHead(MA_SigArgMinusArgs arg);
MA_SigArg MA_getSigArgMinusArgsHead(MA_SigArgMinusArgs arg);
MA_SigArgMinusArgs MA_setSigArgMinusArgsHead(MA_SigArgMinusArgs arg, MA_SigArg head);
ATbool MA_hasSigArgMinusArgsWsMinusAfterMinusFirst(MA_SigArgMinusArgs arg);
MA_Layout MA_getSigArgMinusArgsWsMinusAfterMinusFirst(MA_SigArgMinusArgs arg);
MA_SigArgMinusArgs MA_setSigArgMinusArgsWsMinusAfterMinusFirst(MA_SigArgMinusArgs arg, MA_Layout wsMinusAfterMinusFirst);
ATbool MA_hasSigArgMinusArgsSep(MA_SigArgMinusArgs arg);
char * MA_getSigArgMinusArgsSep(MA_SigArgMinusArgs arg);
MA_SigArgMinusArgs MA_setSigArgMinusArgsSep(MA_SigArgMinusArgs arg, char * sep);
ATbool MA_hasSigArgMinusArgsWsMinusAfterMinusSep(MA_SigArgMinusArgs arg);
MA_Layout MA_getSigArgMinusArgsWsMinusAfterMinusSep(MA_SigArgMinusArgs arg);
MA_SigArgMinusArgs MA_setSigArgMinusArgsWsMinusAfterMinusSep(MA_SigArgMinusArgs arg, MA_Layout wsMinusAfterMinusSep);
ATbool MA_hasSigArgMinusArgsTail(MA_SigArgMinusArgs arg);
MA_SigArgMinusArgs MA_getSigArgMinusArgsTail(MA_SigArgMinusArgs arg);
MA_SigArgMinusArgs MA_setSigArgMinusArgsTail(MA_SigArgMinusArgs arg, MA_SigArgMinusArgs tail);

/*}}}  */
/*{{{  MA_Annotations accessors */

ATbool MA_isValidAnnotations(MA_Annotations arg);
inline ATbool MA_isAnnotationsDefault(MA_Annotations arg);
ATbool MA_hasAnnotationsWsMinusAfterMinusBraceOpen(MA_Annotations arg);
MA_Layout MA_getAnnotationsWsMinusAfterMinusBraceOpen(MA_Annotations arg);
MA_Annotations MA_setAnnotationsWsMinusAfterMinusBraceOpen(MA_Annotations arg, MA_Layout wsMinusAfterMinusBraceOpen);
ATbool MA_hasAnnotationsTerms(MA_Annotations arg);
MA_TermMinusTerms MA_getAnnotationsTerms(MA_Annotations arg);
MA_Annotations MA_setAnnotationsTerms(MA_Annotations arg, MA_TermMinusTerms terms);
ATbool MA_hasAnnotationsWsMinusAfterMinusTerms(MA_Annotations arg);
MA_Layout MA_getAnnotationsWsMinusAfterMinusTerms(MA_Annotations arg);
MA_Annotations MA_setAnnotationsWsMinusAfterMinusTerms(MA_Annotations arg, MA_Layout wsMinusAfterMinusTerms);

/*}}}  */
/*{{{  MA_SigArgList accessors */

ATbool MA_isValidSigArgList(MA_SigArgList arg);
inline ATbool MA_isSigArgListDefault(MA_SigArgList arg);
ATbool MA_hasSigArgListSigargs(MA_SigArgList arg);
MA_SigArgMinusSigargs MA_getSigArgListSigargs(MA_SigArgList arg);
MA_SigArgList MA_setSigArgListSigargs(MA_SigArgList arg, MA_SigArgMinusSigargs sigargs);

/*}}}  */
/*{{{  MA_SigArgMinusSigargs accessors */

ATbool MA_isValidSigArgMinusSigargs(MA_SigArgMinusSigargs arg);
inline ATbool MA_isSigArgMinusSigargsSingle(MA_SigArgMinusSigargs arg);
inline ATbool MA_isSigArgMinusSigargsMany(MA_SigArgMinusSigargs arg);
ATbool MA_hasSigArgMinusSigargsHead(MA_SigArgMinusSigargs arg);
MA_SigArg MA_getSigArgMinusSigargsHead(MA_SigArgMinusSigargs arg);
MA_SigArgMinusSigargs MA_setSigArgMinusSigargsHead(MA_SigArgMinusSigargs arg, MA_SigArg head);
ATbool MA_hasSigArgMinusSigargsWsMinusAfterMinusFirst(MA_SigArgMinusSigargs arg);
MA_Layout MA_getSigArgMinusSigargsWsMinusAfterMinusFirst(MA_SigArgMinusSigargs arg);
MA_SigArgMinusSigargs MA_setSigArgMinusSigargsWsMinusAfterMinusFirst(MA_SigArgMinusSigargs arg, MA_Layout wsMinusAfterMinusFirst);
ATbool MA_hasSigArgMinusSigargsSep(MA_SigArgMinusSigargs arg);
char * MA_getSigArgMinusSigargsSep(MA_SigArgMinusSigargs arg);
MA_SigArgMinusSigargs MA_setSigArgMinusSigargsSep(MA_SigArgMinusSigargs arg, char * sep);
ATbool MA_hasSigArgMinusSigargsWsMinusAfterMinusSep(MA_SigArgMinusSigargs arg);
MA_Layout MA_getSigArgMinusSigargsWsMinusAfterMinusSep(MA_SigArgMinusSigargs arg);
MA_SigArgMinusSigargs MA_setSigArgMinusSigargsWsMinusAfterMinusSep(MA_SigArgMinusSigargs arg, MA_Layout wsMinusAfterMinusSep);
ATbool MA_hasSigArgMinusSigargsTail(MA_SigArgMinusSigargs arg);
MA_SigArgMinusSigargs MA_getSigArgMinusSigargsTail(MA_SigArgMinusSigargs arg);
MA_SigArgMinusSigargs MA_setSigArgMinusSigargsTail(MA_SigArgMinusSigargs arg, MA_SigArgMinusSigargs tail);

/*}}}  */
/*{{{  MA_FuncDefList accessors */

ATbool MA_isValidFuncDefList(MA_FuncDefList arg);
inline ATbool MA_isFuncDefListDefault(MA_FuncDefList arg);
ATbool MA_hasFuncDefListFuncdefs(MA_FuncDefList arg);
MA_FuncDefMinusFuncdefs MA_getFuncDefListFuncdefs(MA_FuncDefList arg);
MA_FuncDefList MA_setFuncDefListFuncdefs(MA_FuncDefList arg, MA_FuncDefMinusFuncdefs funcdefs);

/*}}}  */
/*{{{  MA_FuncDefMinusFuncdefs accessors */

ATbool MA_isValidFuncDefMinusFuncdefs(MA_FuncDefMinusFuncdefs arg);
inline ATbool MA_isFuncDefMinusFuncdefsEmpty(MA_FuncDefMinusFuncdefs arg);
inline ATbool MA_isFuncDefMinusFuncdefsSingle(MA_FuncDefMinusFuncdefs arg);
inline ATbool MA_isFuncDefMinusFuncdefsMany(MA_FuncDefMinusFuncdefs arg);
ATbool MA_hasFuncDefMinusFuncdefsHead(MA_FuncDefMinusFuncdefs arg);
MA_FuncDef MA_getFuncDefMinusFuncdefsHead(MA_FuncDefMinusFuncdefs arg);
MA_FuncDefMinusFuncdefs MA_setFuncDefMinusFuncdefsHead(MA_FuncDefMinusFuncdefs arg, MA_FuncDef head);
ATbool MA_hasFuncDefMinusFuncdefsWsMinusAfterMinusFirst(MA_FuncDefMinusFuncdefs arg);
MA_Layout MA_getFuncDefMinusFuncdefsWsMinusAfterMinusFirst(MA_FuncDefMinusFuncdefs arg);
MA_FuncDefMinusFuncdefs MA_setFuncDefMinusFuncdefsWsMinusAfterMinusFirst(MA_FuncDefMinusFuncdefs arg, MA_Layout wsMinusAfterMinusFirst);
ATbool MA_hasFuncDefMinusFuncdefsSep(MA_FuncDefMinusFuncdefs arg);
char * MA_getFuncDefMinusFuncdefsSep(MA_FuncDefMinusFuncdefs arg);
MA_FuncDefMinusFuncdefs MA_setFuncDefMinusFuncdefsSep(MA_FuncDefMinusFuncdefs arg, char * sep);
ATbool MA_hasFuncDefMinusFuncdefsWsMinusAfterMinusSep(MA_FuncDefMinusFuncdefs arg);
MA_Layout MA_getFuncDefMinusFuncdefsWsMinusAfterMinusSep(MA_FuncDefMinusFuncdefs arg);
MA_FuncDefMinusFuncdefs MA_setFuncDefMinusFuncdefsWsMinusAfterMinusSep(MA_FuncDefMinusFuncdefs arg, MA_Layout wsMinusAfterMinusSep);
ATbool MA_hasFuncDefMinusFuncdefsTail(MA_FuncDefMinusFuncdefs arg);
MA_FuncDefMinusFuncdefs MA_getFuncDefMinusFuncdefsTail(MA_FuncDefMinusFuncdefs arg);
MA_FuncDefMinusFuncdefs MA_setFuncDefMinusFuncdefsTail(MA_FuncDefMinusFuncdefs arg, MA_FuncDefMinusFuncdefs tail);

/*}}}  */
/*{{{  MA_Rule accessors */

ATbool MA_isValidRule(MA_Rule arg);
inline ATbool MA_isRuleNoMinusConds(MA_Rule arg);
inline ATbool MA_isRuleDefaultMinusNoMinusConds(MA_Rule arg);
inline ATbool MA_isRuleDefaultMinusWithMinusConds(MA_Rule arg);
inline ATbool MA_isRuleWithMinusConds(MA_Rule arg);
ATbool MA_hasRuleLhs(MA_Rule arg);
MA_Term MA_getRuleLhs(MA_Rule arg);
MA_Rule MA_setRuleLhs(MA_Rule arg, MA_Term lhs);
ATbool MA_hasRuleWsMinusAfterMinusLhs(MA_Rule arg);
MA_Layout MA_getRuleWsMinusAfterMinusLhs(MA_Rule arg);
MA_Rule MA_setRuleWsMinusAfterMinusLhs(MA_Rule arg, MA_Layout wsMinusAfterMinusLhs);
ATbool MA_hasRuleWsMinusAfterMinusEquals(MA_Rule arg);
MA_Layout MA_getRuleWsMinusAfterMinusEquals(MA_Rule arg);
MA_Rule MA_setRuleWsMinusAfterMinusEquals(MA_Rule arg, MA_Layout wsMinusAfterMinusEquals);
ATbool MA_hasRuleRhs(MA_Rule arg);
MA_Term MA_getRuleRhs(MA_Rule arg);
MA_Rule MA_setRuleRhs(MA_Rule arg, MA_Term rhs);
ATbool MA_hasRuleWsMinusAfterMinusDefaultColon(MA_Rule arg);
MA_Layout MA_getRuleWsMinusAfterMinusDefaultColon(MA_Rule arg);
MA_Rule MA_setRuleWsMinusAfterMinusDefaultColon(MA_Rule arg, MA_Layout wsMinusAfterMinusDefaultColon);
ATbool MA_hasRuleConds(MA_Rule arg);
MA_CondList MA_getRuleConds(MA_Rule arg);
MA_Rule MA_setRuleConds(MA_Rule arg, MA_CondList conds);
ATbool MA_hasRuleWsMinusAfterMinusConds(MA_Rule arg);
MA_Layout MA_getRuleWsMinusAfterMinusConds(MA_Rule arg);
MA_Rule MA_setRuleWsMinusAfterMinusConds(MA_Rule arg, MA_Layout wsMinusAfterMinusConds);
ATbool MA_hasRuleWsMinusAfterMinusImplies(MA_Rule arg);
MA_Layout MA_getRuleWsMinusAfterMinusImplies(MA_Rule arg);
MA_Rule MA_setRuleWsMinusAfterMinusImplies(MA_Rule arg, MA_Layout wsMinusAfterMinusImplies);

/*}}}  */
/*{{{  MA_RuleList accessors */

ATbool MA_isValidRuleList(MA_RuleList arg);
inline ATbool MA_isRuleListDefault(MA_RuleList arg);
ATbool MA_hasRuleListRules(MA_RuleList arg);
MA_RuleMinusRules MA_getRuleListRules(MA_RuleList arg);
MA_RuleList MA_setRuleListRules(MA_RuleList arg, MA_RuleMinusRules rules);

/*}}}  */
/*{{{  MA_RuleMinusRules accessors */

ATbool MA_isValidRuleMinusRules(MA_RuleMinusRules arg);
inline ATbool MA_isRuleMinusRulesEmpty(MA_RuleMinusRules arg);
inline ATbool MA_isRuleMinusRulesSingle(MA_RuleMinusRules arg);
inline ATbool MA_isRuleMinusRulesMany(MA_RuleMinusRules arg);
ATbool MA_hasRuleMinusRulesHead(MA_RuleMinusRules arg);
MA_Rule MA_getRuleMinusRulesHead(MA_RuleMinusRules arg);
MA_RuleMinusRules MA_setRuleMinusRulesHead(MA_RuleMinusRules arg, MA_Rule head);
ATbool MA_hasRuleMinusRulesWsMinusAfterMinusFirst(MA_RuleMinusRules arg);
MA_Layout MA_getRuleMinusRulesWsMinusAfterMinusFirst(MA_RuleMinusRules arg);
MA_RuleMinusRules MA_setRuleMinusRulesWsMinusAfterMinusFirst(MA_RuleMinusRules arg, MA_Layout wsMinusAfterMinusFirst);
ATbool MA_hasRuleMinusRulesSep(MA_RuleMinusRules arg);
char * MA_getRuleMinusRulesSep(MA_RuleMinusRules arg);
MA_RuleMinusRules MA_setRuleMinusRulesSep(MA_RuleMinusRules arg, char * sep);
ATbool MA_hasRuleMinusRulesWsMinusAfterMinusSep(MA_RuleMinusRules arg);
MA_Layout MA_getRuleMinusRulesWsMinusAfterMinusSep(MA_RuleMinusRules arg);
MA_RuleMinusRules MA_setRuleMinusRulesWsMinusAfterMinusSep(MA_RuleMinusRules arg, MA_Layout wsMinusAfterMinusSep);
ATbool MA_hasRuleMinusRulesTail(MA_RuleMinusRules arg);
MA_RuleMinusRules MA_getRuleMinusRulesTail(MA_RuleMinusRules arg);
MA_RuleMinusRules MA_setRuleMinusRulesTail(MA_RuleMinusRules arg, MA_RuleMinusRules tail);

/*}}}  */
/*{{{  MA_CondList accessors */

ATbool MA_isValidCondList(MA_CondList arg);
inline ATbool MA_isCondListDefault(MA_CondList arg);
ATbool MA_hasCondListConds(MA_CondList arg);
MA_CondMinusConds MA_getCondListConds(MA_CondList arg);
MA_CondList MA_setCondListConds(MA_CondList arg, MA_CondMinusConds conds);

/*}}}  */
/*{{{  MA_CondMinusConds accessors */

ATbool MA_isValidCondMinusConds(MA_CondMinusConds arg);
inline ATbool MA_isCondMinusCondsEmpty(MA_CondMinusConds arg);
inline ATbool MA_isCondMinusCondsSingle(MA_CondMinusConds arg);
inline ATbool MA_isCondMinusCondsMany(MA_CondMinusConds arg);
ATbool MA_hasCondMinusCondsHead(MA_CondMinusConds arg);
MA_Cond MA_getCondMinusCondsHead(MA_CondMinusConds arg);
MA_CondMinusConds MA_setCondMinusCondsHead(MA_CondMinusConds arg, MA_Cond head);
ATbool MA_hasCondMinusCondsWsMinusAfterMinusFirst(MA_CondMinusConds arg);
MA_Layout MA_getCondMinusCondsWsMinusAfterMinusFirst(MA_CondMinusConds arg);
MA_CondMinusConds MA_setCondMinusCondsWsMinusAfterMinusFirst(MA_CondMinusConds arg, MA_Layout wsMinusAfterMinusFirst);
ATbool MA_hasCondMinusCondsSep(MA_CondMinusConds arg);
char * MA_getCondMinusCondsSep(MA_CondMinusConds arg);
MA_CondMinusConds MA_setCondMinusCondsSep(MA_CondMinusConds arg, char * sep);
ATbool MA_hasCondMinusCondsWsMinusAfterMinusSep(MA_CondMinusConds arg);
MA_Layout MA_getCondMinusCondsWsMinusAfterMinusSep(MA_CondMinusConds arg);
MA_CondMinusConds MA_setCondMinusCondsWsMinusAfterMinusSep(MA_CondMinusConds arg, MA_Layout wsMinusAfterMinusSep);
ATbool MA_hasCondMinusCondsTail(MA_CondMinusConds arg);
MA_CondMinusConds MA_getCondMinusCondsTail(MA_CondMinusConds arg);
MA_CondMinusConds MA_setCondMinusCondsTail(MA_CondMinusConds arg, MA_CondMinusConds tail);

/*}}}  */
/*{{{  MA_Cond accessors */

ATbool MA_isValidCond(MA_Cond arg);
inline ATbool MA_isCondAssign(MA_Cond arg);
inline ATbool MA_isCondEqual(MA_Cond arg);
inline ATbool MA_isCondUnequal(MA_Cond arg);
ATbool MA_hasCondLhs(MA_Cond arg);
MA_Term MA_getCondLhs(MA_Cond arg);
MA_Cond MA_setCondLhs(MA_Cond arg, MA_Term lhs);
ATbool MA_hasCondWsMinusAfterMinusLhs(MA_Cond arg);
MA_Layout MA_getCondWsMinusAfterMinusLhs(MA_Cond arg);
MA_Cond MA_setCondWsMinusAfterMinusLhs(MA_Cond arg, MA_Layout wsMinusAfterMinusLhs);
ATbool MA_hasCondWsMinusAfterMinusAssign(MA_Cond arg);
MA_Layout MA_getCondWsMinusAfterMinusAssign(MA_Cond arg);
MA_Cond MA_setCondWsMinusAfterMinusAssign(MA_Cond arg, MA_Layout wsMinusAfterMinusAssign);
ATbool MA_hasCondRhs(MA_Cond arg);
MA_Term MA_getCondRhs(MA_Cond arg);
MA_Cond MA_setCondRhs(MA_Cond arg, MA_Term rhs);
ATbool MA_hasCondWsMinusAfterMinusEqual(MA_Cond arg);
MA_Layout MA_getCondWsMinusAfterMinusEqual(MA_Cond arg);
MA_Cond MA_setCondWsMinusAfterMinusEqual(MA_Cond arg, MA_Layout wsMinusAfterMinusEqual);
ATbool MA_hasCondWsMinusAfterMinusUnequal(MA_Cond arg);
MA_Layout MA_getCondWsMinusAfterMinusUnequal(MA_Cond arg);
MA_Cond MA_setCondWsMinusAfterMinusUnequal(MA_Cond arg, MA_Layout wsMinusAfterMinusUnequal);

/*}}}  */
/*{{{  MA_SignatureOpt accessors */

ATbool MA_isValidSignatureOpt(MA_SignatureOpt arg);
inline ATbool MA_isSignatureOptAbsent(MA_SignatureOpt arg);
inline ATbool MA_isSignatureOptPresent(MA_SignatureOpt arg);
ATbool MA_hasSignatureOptWsMinusAfterMinusSignature(MA_SignatureOpt arg);
MA_Layout MA_getSignatureOptWsMinusAfterMinusSignature(MA_SignatureOpt arg);
MA_SignatureOpt MA_setSignatureOptWsMinusAfterMinusSignature(MA_SignatureOpt arg, MA_Layout wsMinusAfterMinusSignature);
ATbool MA_hasSignatureOptFuncdefs(MA_SignatureOpt arg);
MA_FuncDefList MA_getSignatureOptFuncdefs(MA_SignatureOpt arg);
MA_SignatureOpt MA_setSignatureOptFuncdefs(MA_SignatureOpt arg, MA_FuncDefList funcdefs);

/*}}}  */
/*{{{  MA_RulesOpt accessors */

ATbool MA_isValidRulesOpt(MA_RulesOpt arg);
inline ATbool MA_isRulesOptAbsent(MA_RulesOpt arg);
inline ATbool MA_isRulesOptPresent(MA_RulesOpt arg);
ATbool MA_hasRulesOptWsMinusAfterMinusRules(MA_RulesOpt arg);
MA_Layout MA_getRulesOptWsMinusAfterMinusRules(MA_RulesOpt arg);
MA_RulesOpt MA_setRulesOptWsMinusAfterMinusRules(MA_RulesOpt arg, MA_Layout wsMinusAfterMinusRules);
ATbool MA_hasRulesOptRules(MA_RulesOpt arg);
MA_RuleList MA_getRulesOptRules(MA_RulesOpt arg);
MA_RulesOpt MA_setRulesOptRules(MA_RulesOpt arg, MA_RuleList rules);

/*}}}  */
/*{{{  MA_Module accessors */

ATbool MA_isValidModule(MA_Module arg);
inline ATbool MA_isModuleModule(MA_Module arg);
ATbool MA_hasModuleWsMinusAfterMinusModule(MA_Module arg);
MA_Layout MA_getModuleWsMinusAfterMinusModule(MA_Module arg);
MA_Module MA_setModuleWsMinusAfterMinusModule(MA_Module arg, MA_Layout wsMinusAfterMinusModule);
ATbool MA_hasModuleId(MA_Module arg);
MA_ModId MA_getModuleId(MA_Module arg);
MA_Module MA_setModuleId(MA_Module arg, MA_ModId id);
ATbool MA_hasModuleWsMinusAfterMinusId(MA_Module arg);
MA_Layout MA_getModuleWsMinusAfterMinusId(MA_Module arg);
MA_Module MA_setModuleWsMinusAfterMinusId(MA_Module arg, MA_Layout wsMinusAfterMinusId);
ATbool MA_hasModuleSignature(MA_Module arg);
MA_SignatureOpt MA_getModuleSignature(MA_Module arg);
MA_Module MA_setModuleSignature(MA_Module arg, MA_SignatureOpt signature);
ATbool MA_hasModuleWsMinusAfterMinusSignature(MA_Module arg);
MA_Layout MA_getModuleWsMinusAfterMinusSignature(MA_Module arg);
MA_Module MA_setModuleWsMinusAfterMinusSignature(MA_Module arg, MA_Layout wsMinusAfterMinusSignature);
ATbool MA_hasModuleRules(MA_Module arg);
MA_RulesOpt MA_getModuleRules(MA_Module arg);
MA_Module MA_setModuleRules(MA_Module arg, MA_RulesOpt rules);

/*}}}  */
/*{{{  MA_NamePair accessors */

ATbool MA_isValidNamePair(MA_NamePair arg);
inline ATbool MA_isNamePairDefault(MA_NamePair arg);
ATbool MA_hasNamePairWsMinusAfterMinusParenOpen(MA_NamePair arg);
MA_Layout MA_getNamePairWsMinusAfterMinusParenOpen(MA_NamePair arg);
MA_NamePair MA_setNamePairWsMinusAfterMinusParenOpen(MA_NamePair arg, MA_Layout wsMinusAfterMinusParenOpen);
ATbool MA_hasNamePairProd(MA_NamePair arg);
MA_FunId MA_getNamePairProd(MA_NamePair arg);
MA_NamePair MA_setNamePairProd(MA_NamePair arg, MA_FunId prod);
ATbool MA_hasNamePairWsMinusAfterMinusProd(MA_NamePair arg);
MA_Layout MA_getNamePairWsMinusAfterMinusProd(MA_NamePair arg);
MA_NamePair MA_setNamePairWsMinusAfterMinusProd(MA_NamePair arg, MA_Layout wsMinusAfterMinusProd);
ATbool MA_hasNamePairWsMinusAfterMinusComma(MA_NamePair arg);
MA_Layout MA_getNamePairWsMinusAfterMinusComma(MA_NamePair arg);
MA_NamePair MA_setNamePairWsMinusAfterMinusComma(MA_NamePair arg, MA_Layout wsMinusAfterMinusComma);
ATbool MA_hasNamePairFunc(MA_NamePair arg);
MA_FunId MA_getNamePairFunc(MA_NamePair arg);
MA_NamePair MA_setNamePairFunc(MA_NamePair arg, MA_FunId func);
ATbool MA_hasNamePairWsMinusAfterMinusFunc(MA_NamePair arg);
MA_Layout MA_getNamePairWsMinusAfterMinusFunc(MA_NamePair arg);
MA_NamePair MA_setNamePairWsMinusAfterMinusFunc(MA_NamePair arg, MA_Layout wsMinusAfterMinusFunc);
ATbool MA_hasNamePairAttributes(MA_NamePair arg);
MA_TermMinusAttributes MA_getNamePairAttributes(MA_NamePair arg);
MA_NamePair MA_setNamePairAttributes(MA_NamePair arg, MA_TermMinusAttributes attributes);
ATbool MA_hasNamePairWsMinusAfterMinusAttributes(MA_NamePair arg);
MA_Layout MA_getNamePairWsMinusAfterMinusAttributes(MA_NamePair arg);
MA_NamePair MA_setNamePairWsMinusAfterMinusAttributes(MA_NamePair arg, MA_Layout wsMinusAfterMinusAttributes);

/*}}}  */
/*{{{  MA_TermMinusAttributes accessors */

ATbool MA_isValidTermMinusAttributes(MA_TermMinusAttributes arg);
inline ATbool MA_isTermMinusAttributesEmpty(MA_TermMinusAttributes arg);
inline ATbool MA_isTermMinusAttributesSingle(MA_TermMinusAttributes arg);
inline ATbool MA_isTermMinusAttributesMany(MA_TermMinusAttributes arg);
ATbool MA_hasTermMinusAttributesHead(MA_TermMinusAttributes arg);
MA_Term MA_getTermMinusAttributesHead(MA_TermMinusAttributes arg);
MA_TermMinusAttributes MA_setTermMinusAttributesHead(MA_TermMinusAttributes arg, MA_Term head);
ATbool MA_hasTermMinusAttributesWsMinusAfterMinusFirst(MA_TermMinusAttributes arg);
MA_Layout MA_getTermMinusAttributesWsMinusAfterMinusFirst(MA_TermMinusAttributes arg);
MA_TermMinusAttributes MA_setTermMinusAttributesWsMinusAfterMinusFirst(MA_TermMinusAttributes arg, MA_Layout wsMinusAfterMinusFirst);
ATbool MA_hasTermMinusAttributesSep(MA_TermMinusAttributes arg);
char * MA_getTermMinusAttributesSep(MA_TermMinusAttributes arg);
MA_TermMinusAttributes MA_setTermMinusAttributesSep(MA_TermMinusAttributes arg, char * sep);
ATbool MA_hasTermMinusAttributesWsMinusAfterMinusSep(MA_TermMinusAttributes arg);
MA_Layout MA_getTermMinusAttributesWsMinusAfterMinusSep(MA_TermMinusAttributes arg);
MA_TermMinusAttributes MA_setTermMinusAttributesWsMinusAfterMinusSep(MA_TermMinusAttributes arg, MA_Layout wsMinusAfterMinusSep);
ATbool MA_hasTermMinusAttributesTail(MA_TermMinusAttributes arg);
MA_TermMinusAttributes MA_getTermMinusAttributesTail(MA_TermMinusAttributes arg);
MA_TermMinusAttributes MA_setTermMinusAttributesTail(MA_TermMinusAttributes arg, MA_TermMinusAttributes tail);

/*}}}  */
/*{{{  MA_NameTable accessors */

ATbool MA_isValidNameTable(MA_NameTable arg);
inline ATbool MA_isNameTableDefault(MA_NameTable arg);
ATbool MA_hasNameTableWsMinusAfterMinusParenOpen(MA_NameTable arg);
MA_Layout MA_getNameTableWsMinusAfterMinusParenOpen(MA_NameTable arg);
MA_NameTable MA_setNameTableWsMinusAfterMinusParenOpen(MA_NameTable arg, MA_Layout wsMinusAfterMinusParenOpen);
ATbool MA_hasNameTableTable(MA_NameTable arg);
MA_NamePairMinusTable MA_getNameTableTable(MA_NameTable arg);
MA_NameTable MA_setNameTableTable(MA_NameTable arg, MA_NamePairMinusTable table);
ATbool MA_hasNameTableWsMinusAfterMinusTable(MA_NameTable arg);
MA_Layout MA_getNameTableWsMinusAfterMinusTable(MA_NameTable arg);
MA_NameTable MA_setNameTableWsMinusAfterMinusTable(MA_NameTable arg, MA_Layout wsMinusAfterMinusTable);
ATbool MA_hasNameTableWsMinusAfterMinusComma(MA_NameTable arg);
MA_Layout MA_getNameTableWsMinusAfterMinusComma(MA_NameTable arg);
MA_NameTable MA_setNameTableWsMinusAfterMinusComma(MA_NameTable arg, MA_Layout wsMinusAfterMinusComma);
ATbool MA_hasNameTableId(MA_NameTable arg);
MA_FunId MA_getNameTableId(MA_NameTable arg);
MA_NameTable MA_setNameTableId(MA_NameTable arg, MA_FunId id);
ATbool MA_hasNameTableWsMinusAfterMinusId(MA_NameTable arg);
MA_Layout MA_getNameTableWsMinusAfterMinusId(MA_NameTable arg);
MA_NameTable MA_setNameTableWsMinusAfterMinusId(MA_NameTable arg, MA_Layout wsMinusAfterMinusId);
ATbool MA_hasNameTableLast(MA_NameTable arg);
MA_IntCon MA_getNameTableLast(MA_NameTable arg);
MA_NameTable MA_setNameTableLast(MA_NameTable arg, MA_IntCon last);
ATbool MA_hasNameTableWsMinusAfterMinusLast(MA_NameTable arg);
MA_Layout MA_getNameTableWsMinusAfterMinusLast(MA_NameTable arg);
MA_NameTable MA_setNameTableWsMinusAfterMinusLast(MA_NameTable arg, MA_Layout wsMinusAfterMinusLast);
ATbool MA_hasNameTablePrev(MA_NameTable arg);
MA_IntCon MA_getNameTablePrev(MA_NameTable arg);
MA_NameTable MA_setNameTablePrev(MA_NameTable arg, MA_IntCon prev);
ATbool MA_hasNameTableWsMinusAfterMinusPrev(MA_NameTable arg);
MA_Layout MA_getNameTableWsMinusAfterMinusPrev(MA_NameTable arg);
MA_NameTable MA_setNameTableWsMinusAfterMinusPrev(MA_NameTable arg, MA_Layout wsMinusAfterMinusPrev);

/*}}}  */
/*{{{  MA_NamePairMinusTable accessors */

ATbool MA_isValidNamePairMinusTable(MA_NamePairMinusTable arg);
inline ATbool MA_isNamePairMinusTableEmpty(MA_NamePairMinusTable arg);
inline ATbool MA_isNamePairMinusTableSingle(MA_NamePairMinusTable arg);
inline ATbool MA_isNamePairMinusTableMany(MA_NamePairMinusTable arg);
ATbool MA_hasNamePairMinusTableHead(MA_NamePairMinusTable arg);
MA_NamePair MA_getNamePairMinusTableHead(MA_NamePairMinusTable arg);
MA_NamePairMinusTable MA_setNamePairMinusTableHead(MA_NamePairMinusTable arg, MA_NamePair head);
ATbool MA_hasNamePairMinusTableWsMinusAfterMinusFirst(MA_NamePairMinusTable arg);
MA_Layout MA_getNamePairMinusTableWsMinusAfterMinusFirst(MA_NamePairMinusTable arg);
MA_NamePairMinusTable MA_setNamePairMinusTableWsMinusAfterMinusFirst(MA_NamePairMinusTable arg, MA_Layout wsMinusAfterMinusFirst);
ATbool MA_hasNamePairMinusTableSep(MA_NamePairMinusTable arg);
char * MA_getNamePairMinusTableSep(MA_NamePairMinusTable arg);
MA_NamePairMinusTable MA_setNamePairMinusTableSep(MA_NamePairMinusTable arg, char * sep);
ATbool MA_hasNamePairMinusTableWsMinusAfterMinusSep(MA_NamePairMinusTable arg);
MA_Layout MA_getNamePairMinusTableWsMinusAfterMinusSep(MA_NamePairMinusTable arg);
MA_NamePairMinusTable MA_setNamePairMinusTableWsMinusAfterMinusSep(MA_NamePairMinusTable arg, MA_Layout wsMinusAfterMinusSep);
ATbool MA_hasNamePairMinusTableTail(MA_NamePairMinusTable arg);
MA_NamePairMinusTable MA_getNamePairMinusTableTail(MA_NamePairMinusTable arg);
MA_NamePairMinusTable MA_setNamePairMinusTableTail(MA_NamePairMinusTable arg, MA_NamePairMinusTable tail);

/*}}}  */
/*{{{  MA_MNMinusStruct accessors */

ATbool MA_isValidMNMinusStruct(MA_MNMinusStruct arg);
inline ATbool MA_isMNMinusStructDefault(MA_MNMinusStruct arg);
ATbool MA_hasMNMinusStructWsMinusAfterMinusParenOpen(MA_MNMinusStruct arg);
MA_Layout MA_getMNMinusStructWsMinusAfterMinusParenOpen(MA_MNMinusStruct arg);
MA_MNMinusStruct MA_setMNMinusStructWsMinusAfterMinusParenOpen(MA_MNMinusStruct arg, MA_Layout wsMinusAfterMinusParenOpen);
ATbool MA_hasMNMinusStructMod(MA_MNMinusStruct arg);
MA_Module MA_getMNMinusStructMod(MA_MNMinusStruct arg);
MA_MNMinusStruct MA_setMNMinusStructMod(MA_MNMinusStruct arg, MA_Module mod);
ATbool MA_hasMNMinusStructWsMinusAfterMinusMod(MA_MNMinusStruct arg);
MA_Layout MA_getMNMinusStructWsMinusAfterMinusMod(MA_MNMinusStruct arg);
MA_MNMinusStruct MA_setMNMinusStructWsMinusAfterMinusMod(MA_MNMinusStruct arg, MA_Layout wsMinusAfterMinusMod);
ATbool MA_hasMNMinusStructWsMinusAfterMinusComma(MA_MNMinusStruct arg);
MA_Layout MA_getMNMinusStructWsMinusAfterMinusComma(MA_MNMinusStruct arg);
MA_MNMinusStruct MA_setMNMinusStructWsMinusAfterMinusComma(MA_MNMinusStruct arg, MA_Layout wsMinusAfterMinusComma);
ATbool MA_hasMNMinusStructNametable(MA_MNMinusStruct arg);
MA_NameTable MA_getMNMinusStructNametable(MA_MNMinusStruct arg);
MA_MNMinusStruct MA_setMNMinusStructNametable(MA_MNMinusStruct arg, MA_NameTable nametable);
ATbool MA_hasMNMinusStructWsMinusAfterMinusNametable(MA_MNMinusStruct arg);
MA_Layout MA_getMNMinusStructWsMinusAfterMinusNametable(MA_MNMinusStruct arg);
MA_MNMinusStruct MA_setMNMinusStructWsMinusAfterMinusNametable(MA_MNMinusStruct arg, MA_Layout wsMinusAfterMinusNametable);

/*}}}  */
/*{{{  sort visitors */

MA_Int MA_visitInt(MA_Int arg, MA_IntCon (*acceptIntCon)(MA_IntCon), MA_Layout (*acceptWsMinusAfterMinusLhs)(MA_Layout), MA_Layout (*acceptWsMinusAfterMinusPlus)(MA_Layout));
MA_IntCon MA_visitIntCon(MA_IntCon arg, MA_Layout (*acceptWsMinusAfterMinusCon)(MA_Layout), MA_Layout (*acceptWsMinusAfterMinusParenOpen)(MA_Layout), MA_Int (*acceptIntMinusArg)(MA_Int), MA_Layout (*acceptWsMinusAfterMinusIntMinusArg)(MA_Layout), MA_NatCon (*acceptNatCon)(MA_NatCon), MA_Layout (*acceptWsMinusAfterMinusPlus)(MA_Layout), MA_NatCon (*acceptNatMinusArg)(MA_NatCon), MA_Layout (*acceptWsMinusAfterMinusMinus)(MA_Layout));
MA_NatCon MA_visitNatCon(MA_NatCon arg, MA_Layout (*acceptWsMinusAfterMinusAbs)(MA_Layout), MA_Layout (*acceptWsMinusAfterMinusParenOpen)(MA_Layout), MA_Int (*acceptIntMinusArg)(MA_Int), MA_Layout (*acceptWsMinusAfterMinusIntMinusArg)(MA_Layout));
MA_Var MA_visitVar(MA_Var arg, MA_VarId (*acceptVarId)(MA_VarId), MA_Layout (*acceptWsMinusAfterMinusStar)(MA_Layout), MA_Layout (*acceptWsMinusAfterMinusPlus)(MA_Layout));
MA_Term MA_visitTerm(MA_Term arg, MA_Var (*acceptVar)(MA_Var), MA_FunId (*acceptFunId)(MA_FunId), MA_Int (*acceptInt)(MA_Int), MA_Layout (*acceptWsMinusAfterMinusFunId)(MA_Layout), MA_Layout (*acceptWsMinusAfterMinusParenOpen)(MA_Layout), MA_TermMinusArgs (*acceptArgs)(MA_TermMinusArgs), MA_Layout (*acceptWsMinusAfterMinusArgs)(MA_Layout));
MA_TermMinusArgs MA_visitTermMinusArgs(MA_TermMinusArgs arg, MA_Term (*acceptHead)(MA_Term), MA_Layout (*acceptWsMinusAfterMinusFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsMinusAfterMinusSep)(MA_Layout));
MA_TermList MA_visitTermList(MA_TermList arg, MA_TermMinusTerms (*acceptTerms)(MA_TermMinusTerms));
MA_TermMinusTerms MA_visitTermMinusTerms(MA_TermMinusTerms arg, MA_Term (*acceptHead)(MA_Term), MA_Layout (*acceptWsMinusAfterMinusFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsMinusAfterMinusSep)(MA_Layout));
MA_SigArg MA_visitSigArg(MA_SigArg arg, MA_Layout (*acceptWsMinusAfterMinusUnderscore)(MA_Layout));
MA_FuncDef MA_visitFuncDef(MA_FuncDef arg, MA_FunId (*acceptFunId)(MA_FunId), MA_Layout (*acceptWsMinusAfterMinusFunId)(MA_Layout), MA_Annotations (*acceptAnnos)(MA_Annotations), MA_Layout (*acceptWsMinusAfterMinusParenOpen)(MA_Layout), MA_SigArgMinusArgs (*acceptArgs)(MA_SigArgMinusArgs), MA_Layout (*acceptWsMinusAfterMinusArgs)(MA_Layout), MA_Layout (*acceptWsMinusAfterMinusParenClose)(MA_Layout));
MA_SigArgMinusArgs MA_visitSigArgMinusArgs(MA_SigArgMinusArgs arg, MA_SigArg (*acceptHead)(MA_SigArg), MA_Layout (*acceptWsMinusAfterMinusFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsMinusAfterMinusSep)(MA_Layout));
MA_Annotations MA_visitAnnotations(MA_Annotations arg, MA_Layout (*acceptWsMinusAfterMinusBraceOpen)(MA_Layout), MA_TermMinusTerms (*acceptTerms)(MA_TermMinusTerms), MA_Layout (*acceptWsMinusAfterMinusTerms)(MA_Layout));
MA_SigArgList MA_visitSigArgList(MA_SigArgList arg, MA_SigArgMinusSigargs (*acceptSigargs)(MA_SigArgMinusSigargs));
MA_SigArgMinusSigargs MA_visitSigArgMinusSigargs(MA_SigArgMinusSigargs arg, MA_SigArg (*acceptHead)(MA_SigArg), MA_Layout (*acceptWsMinusAfterMinusFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsMinusAfterMinusSep)(MA_Layout));
MA_FuncDefList MA_visitFuncDefList(MA_FuncDefList arg, MA_FuncDefMinusFuncdefs (*acceptFuncdefs)(MA_FuncDefMinusFuncdefs));
MA_FuncDefMinusFuncdefs MA_visitFuncDefMinusFuncdefs(MA_FuncDefMinusFuncdefs arg, MA_FuncDef (*acceptHead)(MA_FuncDef), MA_Layout (*acceptWsMinusAfterMinusFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsMinusAfterMinusSep)(MA_Layout));
MA_Rule MA_visitRule(MA_Rule arg, MA_Term (*acceptLhs)(MA_Term), MA_Layout (*acceptWsMinusAfterMinusLhs)(MA_Layout), MA_Layout (*acceptWsMinusAfterMinusEquals)(MA_Layout), MA_Term (*acceptRhs)(MA_Term), MA_Layout (*acceptWsMinusAfterMinusDefaultColon)(MA_Layout), MA_CondList (*acceptConds)(MA_CondList), MA_Layout (*acceptWsMinusAfterMinusConds)(MA_Layout), MA_Layout (*acceptWsMinusAfterMinusImplies)(MA_Layout));
MA_RuleList MA_visitRuleList(MA_RuleList arg, MA_RuleMinusRules (*acceptRules)(MA_RuleMinusRules));
MA_RuleMinusRules MA_visitRuleMinusRules(MA_RuleMinusRules arg, MA_Rule (*acceptHead)(MA_Rule), MA_Layout (*acceptWsMinusAfterMinusFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsMinusAfterMinusSep)(MA_Layout));
MA_CondList MA_visitCondList(MA_CondList arg, MA_CondMinusConds (*acceptConds)(MA_CondMinusConds));
MA_CondMinusConds MA_visitCondMinusConds(MA_CondMinusConds arg, MA_Cond (*acceptHead)(MA_Cond), MA_Layout (*acceptWsMinusAfterMinusFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsMinusAfterMinusSep)(MA_Layout));
MA_Cond MA_visitCond(MA_Cond arg, MA_Term (*acceptLhs)(MA_Term), MA_Layout (*acceptWsMinusAfterMinusLhs)(MA_Layout), MA_Layout (*acceptWsMinusAfterMinusAssign)(MA_Layout), MA_Term (*acceptRhs)(MA_Term), MA_Layout (*acceptWsMinusAfterMinusEqual)(MA_Layout), MA_Layout (*acceptWsMinusAfterMinusUnequal)(MA_Layout));
MA_SignatureOpt MA_visitSignatureOpt(MA_SignatureOpt arg, MA_Layout (*acceptWsMinusAfterMinusSignature)(MA_Layout), MA_FuncDefList (*acceptFuncdefs)(MA_FuncDefList));
MA_RulesOpt MA_visitRulesOpt(MA_RulesOpt arg, MA_Layout (*acceptWsMinusAfterMinusRules)(MA_Layout), MA_RuleList (*acceptRules)(MA_RuleList));
MA_Module MA_visitModule(MA_Module arg, MA_Layout (*acceptWsMinusAfterMinusModule)(MA_Layout), MA_ModId (*acceptId)(MA_ModId), MA_Layout (*acceptWsMinusAfterMinusId)(MA_Layout), MA_SignatureOpt (*acceptSignature)(MA_SignatureOpt), MA_Layout (*acceptWsMinusAfterMinusSignature)(MA_Layout), MA_RulesOpt (*acceptRules)(MA_RulesOpt));
MA_NamePair MA_visitNamePair(MA_NamePair arg, MA_Layout (*acceptWsMinusAfterMinusParenOpen)(MA_Layout), MA_FunId (*acceptProd)(MA_FunId), MA_Layout (*acceptWsMinusAfterMinusProd)(MA_Layout), MA_Layout (*acceptWsMinusAfterMinusComma)(MA_Layout), MA_FunId (*acceptFunc)(MA_FunId), MA_Layout (*acceptWsMinusAfterMinusFunc)(MA_Layout), MA_TermMinusAttributes (*acceptAttributes)(MA_TermMinusAttributes), MA_Layout (*acceptWsMinusAfterMinusAttributes)(MA_Layout));
MA_TermMinusAttributes MA_visitTermMinusAttributes(MA_TermMinusAttributes arg, MA_Term (*acceptHead)(MA_Term), MA_Layout (*acceptWsMinusAfterMinusFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsMinusAfterMinusSep)(MA_Layout));
MA_NameTable MA_visitNameTable(MA_NameTable arg, MA_Layout (*acceptWsMinusAfterMinusParenOpen)(MA_Layout), MA_NamePairMinusTable (*acceptTable)(MA_NamePairMinusTable), MA_Layout (*acceptWsMinusAfterMinusTable)(MA_Layout), MA_Layout (*acceptWsMinusAfterMinusComma)(MA_Layout), MA_FunId (*acceptId)(MA_FunId), MA_Layout (*acceptWsMinusAfterMinusId)(MA_Layout), MA_IntCon (*acceptLast)(MA_IntCon), MA_Layout (*acceptWsMinusAfterMinusLast)(MA_Layout), MA_IntCon (*acceptPrev)(MA_IntCon), MA_Layout (*acceptWsMinusAfterMinusPrev)(MA_Layout));
MA_NamePairMinusTable MA_visitNamePairMinusTable(MA_NamePairMinusTable arg, MA_NamePair (*acceptHead)(MA_NamePair), MA_Layout (*acceptWsMinusAfterMinusFirst)(MA_Layout), char * (*acceptSep)(char *), MA_Layout (*acceptWsMinusAfterMinusSep)(MA_Layout));
MA_MNMinusStruct MA_visitMNMinusStruct(MA_MNMinusStruct arg, MA_Layout (*acceptWsMinusAfterMinusParenOpen)(MA_Layout), MA_Module (*acceptMod)(MA_Module), MA_Layout (*acceptWsMinusAfterMinusMod)(MA_Layout), MA_Layout (*acceptWsMinusAfterMinusComma)(MA_Layout), MA_NameTable (*acceptNametable)(MA_NameTable), MA_Layout (*acceptWsMinusAfterMinusNametable)(MA_Layout));

/*}}}  */

#endif /* _MUASF_H */
