#ifndef _MUASF_H
#define _MUASF_H

/*{{{  includes */

#include <aterm1.h>
#include "MuASF_dict.h"

/*}}}  */

/*{{{  prologue */

typedef struct _MA_CHARLIST *MA_CHARLIST;

ATbool MA_isValidCHARLIST(MA_CHARLIST arg);
ATbool MA_isCHARLISTString(MA_CHARLIST arg);
char*  MA_getCHARLISTString(MA_CHARLIST arg);
MA_CHARLIST  MA_setCHARLISTString(MA_CHARLIST arg, char *str);
ATerm  MA_CHARLISTToTerm(MA_CHARLIST arg);
MA_CHARLIST MA_CHARLISTFromTerm(ATerm trm);
MA_CHARLIST MA_makeCHARLISTString(char *str);

/*}}}  */
/*{{{  typedefs */

typedef struct _MA_Int *MA_Int;
typedef struct _MA_IntCon *MA_IntCon;
typedef struct _MA_NatCon *MA_NatCon;
typedef struct _MA_Var *MA_Var;
typedef struct _MA_Term *MA_Term;
typedef struct _MA_TermArgs *MA_TermArgs;
typedef struct _MA_TermList *MA_TermList;
typedef struct _MA_TermElems *MA_TermElems;
typedef struct _MA_SigArg *MA_SigArg;
typedef struct _MA_FuncDef *MA_FuncDef;
typedef struct _MA_SigArgElems *MA_SigArgElems;
typedef struct _MA_Annotations *MA_Annotations;
typedef struct _MA_TermTerms *MA_TermTerms;
typedef struct _MA_SigArgList *MA_SigArgList;
typedef struct _MA_FuncDefList *MA_FuncDefList;
typedef struct _MA_FuncDefElems *MA_FuncDefElems;
typedef struct _MA_Rule *MA_Rule;
typedef struct _MA_RuleList *MA_RuleList;
typedef struct _MA_RuleElems *MA_RuleElems;
typedef struct _MA_CondList *MA_CondList;
typedef struct _MA_CondElems *MA_CondElems;
typedef struct _MA_Cond *MA_Cond;
typedef struct _MA_SignatureOpt *MA_SignatureOpt;
typedef struct _MA_RulesOpt *MA_RulesOpt;
typedef struct _MA_Module *MA_Module;
typedef struct _MA_EscChar *MA_EscChar;
typedef struct _MA_QChar *MA_QChar;
typedef struct _MA_FunId *MA_FunId;
typedef struct _MA_VarId *MA_VarId;
typedef struct _MA_ModId *MA_ModId;
typedef struct _MA_PropId *MA_PropId;
typedef struct _MA_Start *MA_Start;
typedef struct _MA_OptLayout *MA_OptLayout;

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
MA_TermArgs MA_TermArgsFromTerm(ATerm t);
ATerm MA_TermArgsToTerm(MA_TermArgs arg);
MA_TermList MA_TermListFromTerm(ATerm t);
ATerm MA_TermListToTerm(MA_TermList arg);
MA_TermElems MA_TermElemsFromTerm(ATerm t);
ATerm MA_TermElemsToTerm(MA_TermElems arg);
MA_SigArg MA_SigArgFromTerm(ATerm t);
ATerm MA_SigArgToTerm(MA_SigArg arg);
MA_FuncDef MA_FuncDefFromTerm(ATerm t);
ATerm MA_FuncDefToTerm(MA_FuncDef arg);
MA_SigArgElems MA_SigArgElemsFromTerm(ATerm t);
ATerm MA_SigArgElemsToTerm(MA_SigArgElems arg);
MA_Annotations MA_AnnotationsFromTerm(ATerm t);
ATerm MA_AnnotationsToTerm(MA_Annotations arg);
MA_TermTerms MA_TermTermsFromTerm(ATerm t);
ATerm MA_TermTermsToTerm(MA_TermTerms arg);
MA_SigArgList MA_SigArgListFromTerm(ATerm t);
ATerm MA_SigArgListToTerm(MA_SigArgList arg);
MA_FuncDefList MA_FuncDefListFromTerm(ATerm t);
ATerm MA_FuncDefListToTerm(MA_FuncDefList arg);
MA_FuncDefElems MA_FuncDefElemsFromTerm(ATerm t);
ATerm MA_FuncDefElemsToTerm(MA_FuncDefElems arg);
MA_Rule MA_RuleFromTerm(ATerm t);
ATerm MA_RuleToTerm(MA_Rule arg);
MA_RuleList MA_RuleListFromTerm(ATerm t);
ATerm MA_RuleListToTerm(MA_RuleList arg);
MA_RuleElems MA_RuleElemsFromTerm(ATerm t);
ATerm MA_RuleElemsToTerm(MA_RuleElems arg);
MA_CondList MA_CondListFromTerm(ATerm t);
ATerm MA_CondListToTerm(MA_CondList arg);
MA_CondElems MA_CondElemsFromTerm(ATerm t);
ATerm MA_CondElemsToTerm(MA_CondElems arg);
MA_Cond MA_CondFromTerm(ATerm t);
ATerm MA_CondToTerm(MA_Cond arg);
MA_SignatureOpt MA_SignatureOptFromTerm(ATerm t);
ATerm MA_SignatureOptToTerm(MA_SignatureOpt arg);
MA_RulesOpt MA_RulesOptFromTerm(ATerm t);
ATerm MA_RulesOptToTerm(MA_RulesOpt arg);
MA_Module MA_ModuleFromTerm(ATerm t);
ATerm MA_ModuleToTerm(MA_Module arg);
MA_EscChar MA_EscCharFromTerm(ATerm t);
ATerm MA_EscCharToTerm(MA_EscChar arg);
MA_QChar MA_QCharFromTerm(ATerm t);
ATerm MA_QCharToTerm(MA_QChar arg);
MA_FunId MA_FunIdFromTerm(ATerm t);
ATerm MA_FunIdToTerm(MA_FunId arg);
MA_VarId MA_VarIdFromTerm(ATerm t);
ATerm MA_VarIdToTerm(MA_VarId arg);
MA_ModId MA_ModIdFromTerm(ATerm t);
ATerm MA_ModIdToTerm(MA_ModId arg);
MA_PropId MA_PropIdFromTerm(ATerm t);
ATerm MA_PropIdToTerm(MA_PropId arg);
MA_Start MA_StartFromTerm(ATerm t);
ATerm MA_StartToTerm(MA_Start arg);
MA_OptLayout MA_OptLayoutFromTerm(ATerm t);
ATerm MA_OptLayoutToTerm(MA_OptLayout arg);

/*}}}  */
/*{{{  constructors */

MA_Int MA_makeIntCon(MA_IntCon IntCon);
MA_Int MA_makeIntPlus(MA_Int lhs, MA_OptLayout wsAfterLhs, MA_OptLayout wsAfterPlus, MA_Int rhs);
MA_IntCon MA_makeIntConCon(MA_OptLayout wsAfterCon, MA_OptLayout wsAfterParenOpen, MA_Int intArg, MA_OptLayout wsAfterIntArg);
MA_IntCon MA_makeIntConNat(MA_NatCon NatCon);
MA_IntCon MA_makeIntConPos(MA_OptLayout wsAfterPlus, MA_NatCon natArg);
MA_IntCon MA_makeIntConNeg(MA_OptLayout wsAfter, MA_NatCon natArg);
MA_NatCon MA_makeNatConAbs(MA_OptLayout wsAfterAbs, MA_OptLayout wsAfterParenOpen, MA_Int intArg, MA_OptLayout wsAfterIntArg);
MA_Var MA_makeVarNormal(MA_VarId VarId);
MA_Var MA_makeVarStar(MA_OptLayout wsAfterStar, MA_VarId VarId);
MA_Var MA_makeVarPlus(MA_OptLayout wsAfterPlus, MA_VarId VarId);
MA_Term MA_makeTermVar(MA_Var Var);
MA_Term MA_makeTermConstant(MA_FunId FunId);
MA_Term MA_makeTermInt(MA_Int Int);
MA_Term MA_makeTermFunc(MA_FunId FunId, MA_OptLayout wsAfterFunId, MA_OptLayout wsAfterParenOpen, MA_TermArgs args, MA_OptLayout wsAfterArgs);
MA_Term MA_makeTermList(MA_OptLayout wsAfterBracketOpen, MA_TermList TermList, MA_OptLayout wsAfterTermList);
MA_Term MA_makeTermTyped(MA_Term term, MA_OptLayout wsAfterTerm, MA_OptLayout wsAfterColon, MA_Term type);
MA_TermArgs MA_makeTermArgsSingle(MA_Term head);
MA_TermArgs MA_makeTermArgsMany(MA_Term head, MA_OptLayout wsAfterFirst, char* sep, MA_OptLayout wsAfterSep, MA_TermArgs tail);
MA_TermList MA_makeTermListDefault(MA_TermElems elems);
MA_TermElems MA_makeTermElemsEmpty();
MA_TermElems MA_makeTermElemsSingle(MA_Term head);
MA_TermElems MA_makeTermElemsMany(MA_Term head, MA_OptLayout wsAfterFirst, char* sep, MA_OptLayout wsAfterSep, MA_TermElems tail);
MA_SigArg MA_makeSigArgNormal();
MA_SigArg MA_makeSigArgStar(MA_OptLayout wsAfterUnderscore);
MA_SigArg MA_makeSigArgPlus(MA_OptLayout wsAfterUnderscore);
MA_FuncDef MA_makeFuncDefConstantNoAnnos(MA_FunId FunId);
MA_FuncDef MA_makeFuncDefConstantWithAnnos(MA_FunId FunId, MA_OptLayout wsAfterFunId, MA_Annotations annos);
MA_FuncDef MA_makeFuncDefFuncNoAnnos(MA_FunId FunId, MA_OptLayout wsAfterFunId, MA_OptLayout wsAfterParenOpen, MA_SigArgElems elems, MA_OptLayout wsAfterElems);
MA_FuncDef MA_makeFuncDefFuncWithAnnos(MA_FunId FunId, MA_OptLayout wsAfterFunId, MA_OptLayout wsAfterParenOpen, MA_SigArgElems elems, MA_OptLayout wsAfterElems, MA_OptLayout wsAfterParenClose, MA_Annotations annos);
MA_SigArgElems MA_makeSigArgElemsSingle(MA_SigArg head);
MA_SigArgElems MA_makeSigArgElemsMany(MA_SigArg head, MA_OptLayout wsAfterFirst, char* sep, MA_OptLayout wsAfterSep, MA_SigArgElems tail);
MA_Annotations MA_makeAnnotationsDefault(MA_OptLayout wsAfterBraceOpen, MA_TermTerms terms, MA_OptLayout wsAfterTerms);
MA_TermTerms MA_makeTermTermsSingle(MA_Term head);
MA_TermTerms MA_makeTermTermsMany(MA_Term head, MA_OptLayout wsAfterFirst, char* sep, MA_OptLayout wsAfterSep, MA_TermTerms tail);
MA_SigArgList MA_makeSigArgListDefault(MA_SigArgElems elems);
MA_FuncDefList MA_makeFuncDefListDefault(MA_FuncDefElems elems);
MA_FuncDefElems MA_makeFuncDefElemsEmpty();
MA_FuncDefElems MA_makeFuncDefElemsSingle(MA_FuncDef head);
MA_FuncDefElems MA_makeFuncDefElemsMany(MA_FuncDef head, MA_OptLayout wsAfterFirst, char* sep, MA_OptLayout wsAfterSep, MA_FuncDefElems tail);
MA_Rule MA_makeRuleNoConds(MA_Term lhs, MA_OptLayout wsAfterLhs, MA_OptLayout wsAfterEquals, MA_Term rhs);
MA_Rule MA_makeRuleDefaultNoConds(MA_OptLayout wsAfterDefaultColon, MA_Term lhs, MA_OptLayout wsAfterLhs, MA_OptLayout wsAfterEquals, MA_Term rhs);
MA_Rule MA_makeRuleDefaultWithConds(MA_OptLayout wsAfterDefaultColon, MA_CondList conds, MA_OptLayout wsAfterConds, MA_OptLayout wsAfterImplies, MA_Term lhs, MA_OptLayout wsAfterLhs, MA_OptLayout wsAfterEquals, MA_Term rhs);
MA_Rule MA_makeRuleWithConds(MA_CondList conds, MA_OptLayout wsAfterConds, MA_OptLayout wsAfterImplies, MA_Term lhs, MA_OptLayout wsAfterLhs, MA_OptLayout wsAfterEquals, MA_Term rhs);
MA_RuleList MA_makeRuleListDefault(MA_RuleElems elems);
MA_RuleElems MA_makeRuleElemsEmpty();
MA_RuleElems MA_makeRuleElemsSingle(MA_Rule head);
MA_RuleElems MA_makeRuleElemsMany(MA_Rule head, MA_OptLayout wsAfterFirst, char* sep, MA_OptLayout wsAfterSep, MA_RuleElems tail);
MA_CondList MA_makeCondListDefault(MA_CondElems elems);
MA_CondElems MA_makeCondElemsEmpty();
MA_CondElems MA_makeCondElemsSingle(MA_Cond head);
MA_CondElems MA_makeCondElemsMany(MA_Cond head, MA_OptLayout wsAfterFirst, char* sep, MA_OptLayout wsAfterSep, MA_CondElems tail);
MA_Cond MA_makeCondAssign(MA_Term lhs, MA_OptLayout wsAfterLhs, MA_OptLayout wsAfterAssign, MA_Term rhs);
MA_Cond MA_makeCondEqual(MA_Term lhs, MA_OptLayout wsAfterLhs, MA_OptLayout wsAfterEqual, MA_Term rhs);
MA_Cond MA_makeCondUnequal(MA_Term lhs, MA_OptLayout wsAfterLhs, MA_OptLayout wsAfterUnequal, MA_Term rhs);
MA_SignatureOpt MA_makeSignatureOptAbsent();
MA_SignatureOpt MA_makeSignatureOptPresent(MA_OptLayout wsAfterSignature, MA_FuncDefList funcdefs);
MA_RulesOpt MA_makeRulesOptAbsent();
MA_RulesOpt MA_makeRulesOptPresent(MA_OptLayout wsAfterRules, MA_RuleList rules);
MA_Module MA_makeModuleModule(MA_OptLayout wsAfterModule, MA_ModId id, MA_OptLayout wsAfterId, MA_SignatureOpt signature, MA_OptLayout wsAfterSignature, MA_RulesOpt rules);
MA_EscChar MA_makeEscCharDefault(MA_CHARLIST chars);
MA_EscChar MA_makeEscCharOct0Underscore177(MA_CHARLIST chars);
MA_QChar MA_makeQCharPrintable(MA_CHARLIST chars);
MA_QChar MA_makeQCharEscaped(MA_CHARLIST chars);
MA_FunId MA_makeFunIdUnquoted(MA_CHARLIST chars);
MA_FunId MA_makeFunIdQuoted(MA_CHARLIST chars);
MA_FunId MA_makeFunIdSingleQuote(MA_CHARLIST chars);
MA_FunId MA_makeFunIdDecimal(MA_CHARLIST chars);
MA_VarId MA_makeVarIdDefault(MA_CHARLIST chars);
MA_ModId MA_makeModIdDefault(MA_CHARLIST chars);
MA_PropId MA_makePropIdDefault(MA_CHARLIST chars);
MA_Start MA_makeStartPropId(MA_OptLayout wsBefore, MA_PropId topPropId, MA_OptLayout wsAfter, int ambCnt);
MA_Start MA_makeStartVarId(MA_OptLayout wsBefore, MA_VarId topVarId, MA_OptLayout wsAfter, int ambCnt);
MA_Start MA_makeStartModId(MA_OptLayout wsBefore, MA_ModId topModId, MA_OptLayout wsAfter, int ambCnt);
MA_Start MA_makeStartFunId(MA_OptLayout wsBefore, MA_FunId topFunId, MA_OptLayout wsAfter, int ambCnt);
MA_Start MA_makeStartTermList(MA_OptLayout wsBefore, MA_TermList topTermList, MA_OptLayout wsAfter, int ambCnt);
MA_Start MA_makeStartTerm(MA_OptLayout wsBefore, MA_Term topTerm, MA_OptLayout wsAfter, int ambCnt);
MA_Start MA_makeStartVar(MA_OptLayout wsBefore, MA_Var topVar, MA_OptLayout wsAfter, int ambCnt);
MA_Start MA_makeStartSigArgList(MA_OptLayout wsBefore, MA_SigArgList topSigArgList, MA_OptLayout wsAfter, int ambCnt);
MA_Start MA_makeStartSigArg(MA_OptLayout wsBefore, MA_SigArg topSigArg, MA_OptLayout wsAfter, int ambCnt);
MA_Start MA_makeStartFuncDefList(MA_OptLayout wsBefore, MA_FuncDefList topFuncDefList, MA_OptLayout wsAfter, int ambCnt);
MA_Start MA_makeStartFuncDef(MA_OptLayout wsBefore, MA_FuncDef topFuncDef, MA_OptLayout wsAfter, int ambCnt);
MA_Start MA_makeStartAnnotations(MA_OptLayout wsBefore, MA_Annotations topAnnotations, MA_OptLayout wsAfter, int ambCnt);
MA_Start MA_makeStartCondList(MA_OptLayout wsBefore, MA_CondList topCondList, MA_OptLayout wsAfter, int ambCnt);
MA_Start MA_makeStartCond(MA_OptLayout wsBefore, MA_Cond topCond, MA_OptLayout wsAfter, int ambCnt);
MA_Start MA_makeStartRuleList(MA_OptLayout wsBefore, MA_RuleList topRuleList, MA_OptLayout wsAfter, int ambCnt);
MA_Start MA_makeStartRule(MA_OptLayout wsBefore, MA_Rule topRule, MA_OptLayout wsAfter, int ambCnt);
MA_Start MA_makeStartSignatureOpt(MA_OptLayout wsBefore, MA_SignatureOpt topSignatureOpt, MA_OptLayout wsAfter, int ambCnt);
MA_Start MA_makeStartRulesOpt(MA_OptLayout wsBefore, MA_RulesOpt topRulesOpt, MA_OptLayout wsAfter, int ambCnt);
MA_Start MA_makeStartModule(MA_OptLayout wsBefore, MA_Module topModule, MA_OptLayout wsAfter, int ambCnt);
MA_Start MA_makeStartIntCon(MA_OptLayout wsBefore, MA_IntCon topIntCon, MA_OptLayout wsAfter, int ambCnt);
MA_Start MA_makeStartNatCon(MA_OptLayout wsBefore, MA_NatCon topNatCon, MA_OptLayout wsAfter, int ambCnt);
MA_Start MA_makeStartInt(MA_OptLayout wsBefore, MA_Int topInt, MA_OptLayout wsAfter, int ambCnt);
MA_OptLayout MA_makeOptLayoutAbsent();
MA_OptLayout MA_makeOptLayoutPresent(MA_CHARLIST chars);

/*}}}  */
/*{{{  equality functions */

ATbool MA_isEqualInt(MA_Int arg0, MA_Int arg1);
ATbool MA_isEqualIntCon(MA_IntCon arg0, MA_IntCon arg1);
ATbool MA_isEqualNatCon(MA_NatCon arg0, MA_NatCon arg1);
ATbool MA_isEqualVar(MA_Var arg0, MA_Var arg1);
ATbool MA_isEqualTerm(MA_Term arg0, MA_Term arg1);
ATbool MA_isEqualTermArgs(MA_TermArgs arg0, MA_TermArgs arg1);
ATbool MA_isEqualTermList(MA_TermList arg0, MA_TermList arg1);
ATbool MA_isEqualTermElems(MA_TermElems arg0, MA_TermElems arg1);
ATbool MA_isEqualSigArg(MA_SigArg arg0, MA_SigArg arg1);
ATbool MA_isEqualFuncDef(MA_FuncDef arg0, MA_FuncDef arg1);
ATbool MA_isEqualSigArgElems(MA_SigArgElems arg0, MA_SigArgElems arg1);
ATbool MA_isEqualAnnotations(MA_Annotations arg0, MA_Annotations arg1);
ATbool MA_isEqualTermTerms(MA_TermTerms arg0, MA_TermTerms arg1);
ATbool MA_isEqualSigArgList(MA_SigArgList arg0, MA_SigArgList arg1);
ATbool MA_isEqualFuncDefList(MA_FuncDefList arg0, MA_FuncDefList arg1);
ATbool MA_isEqualFuncDefElems(MA_FuncDefElems arg0, MA_FuncDefElems arg1);
ATbool MA_isEqualRule(MA_Rule arg0, MA_Rule arg1);
ATbool MA_isEqualRuleList(MA_RuleList arg0, MA_RuleList arg1);
ATbool MA_isEqualRuleElems(MA_RuleElems arg0, MA_RuleElems arg1);
ATbool MA_isEqualCondList(MA_CondList arg0, MA_CondList arg1);
ATbool MA_isEqualCondElems(MA_CondElems arg0, MA_CondElems arg1);
ATbool MA_isEqualCond(MA_Cond arg0, MA_Cond arg1);
ATbool MA_isEqualSignatureOpt(MA_SignatureOpt arg0, MA_SignatureOpt arg1);
ATbool MA_isEqualRulesOpt(MA_RulesOpt arg0, MA_RulesOpt arg1);
ATbool MA_isEqualModule(MA_Module arg0, MA_Module arg1);
ATbool MA_isEqualEscChar(MA_EscChar arg0, MA_EscChar arg1);
ATbool MA_isEqualQChar(MA_QChar arg0, MA_QChar arg1);
ATbool MA_isEqualFunId(MA_FunId arg0, MA_FunId arg1);
ATbool MA_isEqualVarId(MA_VarId arg0, MA_VarId arg1);
ATbool MA_isEqualModId(MA_ModId arg0, MA_ModId arg1);
ATbool MA_isEqualPropId(MA_PropId arg0, MA_PropId arg1);
ATbool MA_isEqualStart(MA_Start arg0, MA_Start arg1);
ATbool MA_isEqualOptLayout(MA_OptLayout arg0, MA_OptLayout arg1);

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
ATbool MA_hasIntWsAfterLhs(MA_Int arg);
MA_OptLayout MA_getIntWsAfterLhs(MA_Int arg);
MA_Int MA_setIntWsAfterLhs(MA_Int arg, MA_OptLayout wsAfterLhs);
ATbool MA_hasIntWsAfterPlus(MA_Int arg);
MA_OptLayout MA_getIntWsAfterPlus(MA_Int arg);
MA_Int MA_setIntWsAfterPlus(MA_Int arg, MA_OptLayout wsAfterPlus);
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
ATbool MA_hasIntConWsAfterCon(MA_IntCon arg);
MA_OptLayout MA_getIntConWsAfterCon(MA_IntCon arg);
MA_IntCon MA_setIntConWsAfterCon(MA_IntCon arg, MA_OptLayout wsAfterCon);
ATbool MA_hasIntConWsAfterParenOpen(MA_IntCon arg);
MA_OptLayout MA_getIntConWsAfterParenOpen(MA_IntCon arg);
MA_IntCon MA_setIntConWsAfterParenOpen(MA_IntCon arg, MA_OptLayout wsAfterParenOpen);
ATbool MA_hasIntConIntArg(MA_IntCon arg);
MA_Int MA_getIntConIntArg(MA_IntCon arg);
MA_IntCon MA_setIntConIntArg(MA_IntCon arg, MA_Int intArg);
ATbool MA_hasIntConWsAfterIntArg(MA_IntCon arg);
MA_OptLayout MA_getIntConWsAfterIntArg(MA_IntCon arg);
MA_IntCon MA_setIntConWsAfterIntArg(MA_IntCon arg, MA_OptLayout wsAfterIntArg);
ATbool MA_hasIntConNatCon(MA_IntCon arg);
MA_NatCon MA_getIntConNatCon(MA_IntCon arg);
MA_IntCon MA_setIntConNatCon(MA_IntCon arg, MA_NatCon NatCon);
ATbool MA_hasIntConWsAfterPlus(MA_IntCon arg);
MA_OptLayout MA_getIntConWsAfterPlus(MA_IntCon arg);
MA_IntCon MA_setIntConWsAfterPlus(MA_IntCon arg, MA_OptLayout wsAfterPlus);
ATbool MA_hasIntConNatArg(MA_IntCon arg);
MA_NatCon MA_getIntConNatArg(MA_IntCon arg);
MA_IntCon MA_setIntConNatArg(MA_IntCon arg, MA_NatCon natArg);
ATbool MA_hasIntConWsAfter(MA_IntCon arg);
MA_OptLayout MA_getIntConWsAfter(MA_IntCon arg);
MA_IntCon MA_setIntConWsAfter(MA_IntCon arg, MA_OptLayout wsAfter);

/*}}}  */
/*{{{  MA_NatCon accessors */

ATbool MA_isValidNatCon(MA_NatCon arg);
inline ATbool MA_isNatConAbs(MA_NatCon arg);
ATbool MA_hasNatConWsAfterAbs(MA_NatCon arg);
MA_OptLayout MA_getNatConWsAfterAbs(MA_NatCon arg);
MA_NatCon MA_setNatConWsAfterAbs(MA_NatCon arg, MA_OptLayout wsAfterAbs);
ATbool MA_hasNatConWsAfterParenOpen(MA_NatCon arg);
MA_OptLayout MA_getNatConWsAfterParenOpen(MA_NatCon arg);
MA_NatCon MA_setNatConWsAfterParenOpen(MA_NatCon arg, MA_OptLayout wsAfterParenOpen);
ATbool MA_hasNatConIntArg(MA_NatCon arg);
MA_Int MA_getNatConIntArg(MA_NatCon arg);
MA_NatCon MA_setNatConIntArg(MA_NatCon arg, MA_Int intArg);
ATbool MA_hasNatConWsAfterIntArg(MA_NatCon arg);
MA_OptLayout MA_getNatConWsAfterIntArg(MA_NatCon arg);
MA_NatCon MA_setNatConWsAfterIntArg(MA_NatCon arg, MA_OptLayout wsAfterIntArg);

/*}}}  */
/*{{{  MA_Var accessors */

ATbool MA_isValidVar(MA_Var arg);
inline ATbool MA_isVarNormal(MA_Var arg);
inline ATbool MA_isVarStar(MA_Var arg);
inline ATbool MA_isVarPlus(MA_Var arg);
ATbool MA_hasVarVarId(MA_Var arg);
MA_VarId MA_getVarVarId(MA_Var arg);
MA_Var MA_setVarVarId(MA_Var arg, MA_VarId VarId);
ATbool MA_hasVarWsAfterStar(MA_Var arg);
MA_OptLayout MA_getVarWsAfterStar(MA_Var arg);
MA_Var MA_setVarWsAfterStar(MA_Var arg, MA_OptLayout wsAfterStar);
ATbool MA_hasVarWsAfterPlus(MA_Var arg);
MA_OptLayout MA_getVarWsAfterPlus(MA_Var arg);
MA_Var MA_setVarWsAfterPlus(MA_Var arg, MA_OptLayout wsAfterPlus);

/*}}}  */
/*{{{  MA_Term accessors */

ATbool MA_isValidTerm(MA_Term arg);
inline ATbool MA_isTermVar(MA_Term arg);
inline ATbool MA_isTermConstant(MA_Term arg);
inline ATbool MA_isTermInt(MA_Term arg);
inline ATbool MA_isTermFunc(MA_Term arg);
inline ATbool MA_isTermList(MA_Term arg);
inline ATbool MA_isTermTyped(MA_Term arg);
ATbool MA_hasTermVar(MA_Term arg);
MA_Var MA_getTermVar(MA_Term arg);
MA_Term MA_setTermVar(MA_Term arg, MA_Var Var);
ATbool MA_hasTermFunId(MA_Term arg);
MA_FunId MA_getTermFunId(MA_Term arg);
MA_Term MA_setTermFunId(MA_Term arg, MA_FunId FunId);
ATbool MA_hasTermInt(MA_Term arg);
MA_Int MA_getTermInt(MA_Term arg);
MA_Term MA_setTermInt(MA_Term arg, MA_Int Int);
ATbool MA_hasTermWsAfterFunId(MA_Term arg);
MA_OptLayout MA_getTermWsAfterFunId(MA_Term arg);
MA_Term MA_setTermWsAfterFunId(MA_Term arg, MA_OptLayout wsAfterFunId);
ATbool MA_hasTermWsAfterParenOpen(MA_Term arg);
MA_OptLayout MA_getTermWsAfterParenOpen(MA_Term arg);
MA_Term MA_setTermWsAfterParenOpen(MA_Term arg, MA_OptLayout wsAfterParenOpen);
ATbool MA_hasTermArgs(MA_Term arg);
MA_TermArgs MA_getTermArgs(MA_Term arg);
MA_Term MA_setTermArgs(MA_Term arg, MA_TermArgs args);
ATbool MA_hasTermWsAfterArgs(MA_Term arg);
MA_OptLayout MA_getTermWsAfterArgs(MA_Term arg);
MA_Term MA_setTermWsAfterArgs(MA_Term arg, MA_OptLayout wsAfterArgs);
ATbool MA_hasTermWsAfterBracketOpen(MA_Term arg);
MA_OptLayout MA_getTermWsAfterBracketOpen(MA_Term arg);
MA_Term MA_setTermWsAfterBracketOpen(MA_Term arg, MA_OptLayout wsAfterBracketOpen);
ATbool MA_hasTermTermList(MA_Term arg);
MA_TermList MA_getTermTermList(MA_Term arg);
MA_Term MA_setTermTermList(MA_Term arg, MA_TermList TermList);
ATbool MA_hasTermWsAfterTermList(MA_Term arg);
MA_OptLayout MA_getTermWsAfterTermList(MA_Term arg);
MA_Term MA_setTermWsAfterTermList(MA_Term arg, MA_OptLayout wsAfterTermList);
ATbool MA_hasTermTerm(MA_Term arg);
MA_Term MA_getTermTerm(MA_Term arg);
MA_Term MA_setTermTerm(MA_Term arg, MA_Term term);
ATbool MA_hasTermWsAfterTerm(MA_Term arg);
MA_OptLayout MA_getTermWsAfterTerm(MA_Term arg);
MA_Term MA_setTermWsAfterTerm(MA_Term arg, MA_OptLayout wsAfterTerm);
ATbool MA_hasTermWsAfterColon(MA_Term arg);
MA_OptLayout MA_getTermWsAfterColon(MA_Term arg);
MA_Term MA_setTermWsAfterColon(MA_Term arg, MA_OptLayout wsAfterColon);
ATbool MA_hasTermType(MA_Term arg);
MA_Term MA_getTermType(MA_Term arg);
MA_Term MA_setTermType(MA_Term arg, MA_Term type);

/*}}}  */
/*{{{  MA_TermArgs accessors */

ATbool MA_isValidTermArgs(MA_TermArgs arg);
inline ATbool MA_isTermArgsSingle(MA_TermArgs arg);
inline ATbool MA_isTermArgsMany(MA_TermArgs arg);
ATbool MA_hasTermArgsHead(MA_TermArgs arg);
MA_Term MA_getTermArgsHead(MA_TermArgs arg);
MA_TermArgs MA_setTermArgsHead(MA_TermArgs arg, MA_Term head);
ATbool MA_hasTermArgsWsAfterFirst(MA_TermArgs arg);
MA_OptLayout MA_getTermArgsWsAfterFirst(MA_TermArgs arg);
MA_TermArgs MA_setTermArgsWsAfterFirst(MA_TermArgs arg, MA_OptLayout wsAfterFirst);
ATbool MA_hasTermArgsSep(MA_TermArgs arg);
char* MA_getTermArgsSep(MA_TermArgs arg);
MA_TermArgs MA_setTermArgsSep(MA_TermArgs arg, char* sep);
ATbool MA_hasTermArgsWsAfterSep(MA_TermArgs arg);
MA_OptLayout MA_getTermArgsWsAfterSep(MA_TermArgs arg);
MA_TermArgs MA_setTermArgsWsAfterSep(MA_TermArgs arg, MA_OptLayout wsAfterSep);
ATbool MA_hasTermArgsTail(MA_TermArgs arg);
MA_TermArgs MA_getTermArgsTail(MA_TermArgs arg);
MA_TermArgs MA_setTermArgsTail(MA_TermArgs arg, MA_TermArgs tail);

/*}}}  */
/*{{{  MA_TermList accessors */

ATbool MA_isValidTermList(MA_TermList arg);
inline ATbool MA_isTermListDefault(MA_TermList arg);
ATbool MA_hasTermListElems(MA_TermList arg);
MA_TermElems MA_getTermListElems(MA_TermList arg);
MA_TermList MA_setTermListElems(MA_TermList arg, MA_TermElems elems);

/*}}}  */
/*{{{  MA_TermElems accessors */

ATbool MA_isValidTermElems(MA_TermElems arg);
inline ATbool MA_isTermElemsEmpty(MA_TermElems arg);
inline ATbool MA_isTermElemsSingle(MA_TermElems arg);
inline ATbool MA_isTermElemsMany(MA_TermElems arg);
ATbool MA_hasTermElemsHead(MA_TermElems arg);
MA_Term MA_getTermElemsHead(MA_TermElems arg);
MA_TermElems MA_setTermElemsHead(MA_TermElems arg, MA_Term head);
ATbool MA_hasTermElemsWsAfterFirst(MA_TermElems arg);
MA_OptLayout MA_getTermElemsWsAfterFirst(MA_TermElems arg);
MA_TermElems MA_setTermElemsWsAfterFirst(MA_TermElems arg, MA_OptLayout wsAfterFirst);
ATbool MA_hasTermElemsSep(MA_TermElems arg);
char* MA_getTermElemsSep(MA_TermElems arg);
MA_TermElems MA_setTermElemsSep(MA_TermElems arg, char* sep);
ATbool MA_hasTermElemsWsAfterSep(MA_TermElems arg);
MA_OptLayout MA_getTermElemsWsAfterSep(MA_TermElems arg);
MA_TermElems MA_setTermElemsWsAfterSep(MA_TermElems arg, MA_OptLayout wsAfterSep);
ATbool MA_hasTermElemsTail(MA_TermElems arg);
MA_TermElems MA_getTermElemsTail(MA_TermElems arg);
MA_TermElems MA_setTermElemsTail(MA_TermElems arg, MA_TermElems tail);

/*}}}  */
/*{{{  MA_SigArg accessors */

ATbool MA_isValidSigArg(MA_SigArg arg);
inline ATbool MA_isSigArgNormal(MA_SigArg arg);
inline ATbool MA_isSigArgStar(MA_SigArg arg);
inline ATbool MA_isSigArgPlus(MA_SigArg arg);
ATbool MA_hasSigArgWsAfterUnderscore(MA_SigArg arg);
MA_OptLayout MA_getSigArgWsAfterUnderscore(MA_SigArg arg);
MA_SigArg MA_setSigArgWsAfterUnderscore(MA_SigArg arg, MA_OptLayout wsAfterUnderscore);

/*}}}  */
/*{{{  MA_FuncDef accessors */

ATbool MA_isValidFuncDef(MA_FuncDef arg);
inline ATbool MA_isFuncDefConstantNoAnnos(MA_FuncDef arg);
inline ATbool MA_isFuncDefConstantWithAnnos(MA_FuncDef arg);
inline ATbool MA_isFuncDefFuncNoAnnos(MA_FuncDef arg);
inline ATbool MA_isFuncDefFuncWithAnnos(MA_FuncDef arg);
ATbool MA_hasFuncDefFunId(MA_FuncDef arg);
MA_FunId MA_getFuncDefFunId(MA_FuncDef arg);
MA_FuncDef MA_setFuncDefFunId(MA_FuncDef arg, MA_FunId FunId);
ATbool MA_hasFuncDefWsAfterFunId(MA_FuncDef arg);
MA_OptLayout MA_getFuncDefWsAfterFunId(MA_FuncDef arg);
MA_FuncDef MA_setFuncDefWsAfterFunId(MA_FuncDef arg, MA_OptLayout wsAfterFunId);
ATbool MA_hasFuncDefAnnos(MA_FuncDef arg);
MA_Annotations MA_getFuncDefAnnos(MA_FuncDef arg);
MA_FuncDef MA_setFuncDefAnnos(MA_FuncDef arg, MA_Annotations annos);
ATbool MA_hasFuncDefWsAfterParenOpen(MA_FuncDef arg);
MA_OptLayout MA_getFuncDefWsAfterParenOpen(MA_FuncDef arg);
MA_FuncDef MA_setFuncDefWsAfterParenOpen(MA_FuncDef arg, MA_OptLayout wsAfterParenOpen);
ATbool MA_hasFuncDefElems(MA_FuncDef arg);
MA_SigArgElems MA_getFuncDefElems(MA_FuncDef arg);
MA_FuncDef MA_setFuncDefElems(MA_FuncDef arg, MA_SigArgElems elems);
ATbool MA_hasFuncDefWsAfterElems(MA_FuncDef arg);
MA_OptLayout MA_getFuncDefWsAfterElems(MA_FuncDef arg);
MA_FuncDef MA_setFuncDefWsAfterElems(MA_FuncDef arg, MA_OptLayout wsAfterElems);
ATbool MA_hasFuncDefWsAfterParenClose(MA_FuncDef arg);
MA_OptLayout MA_getFuncDefWsAfterParenClose(MA_FuncDef arg);
MA_FuncDef MA_setFuncDefWsAfterParenClose(MA_FuncDef arg, MA_OptLayout wsAfterParenClose);

/*}}}  */
/*{{{  MA_SigArgElems accessors */

ATbool MA_isValidSigArgElems(MA_SigArgElems arg);
inline ATbool MA_isSigArgElemsSingle(MA_SigArgElems arg);
inline ATbool MA_isSigArgElemsMany(MA_SigArgElems arg);
ATbool MA_hasSigArgElemsHead(MA_SigArgElems arg);
MA_SigArg MA_getSigArgElemsHead(MA_SigArgElems arg);
MA_SigArgElems MA_setSigArgElemsHead(MA_SigArgElems arg, MA_SigArg head);
ATbool MA_hasSigArgElemsWsAfterFirst(MA_SigArgElems arg);
MA_OptLayout MA_getSigArgElemsWsAfterFirst(MA_SigArgElems arg);
MA_SigArgElems MA_setSigArgElemsWsAfterFirst(MA_SigArgElems arg, MA_OptLayout wsAfterFirst);
ATbool MA_hasSigArgElemsSep(MA_SigArgElems arg);
char* MA_getSigArgElemsSep(MA_SigArgElems arg);
MA_SigArgElems MA_setSigArgElemsSep(MA_SigArgElems arg, char* sep);
ATbool MA_hasSigArgElemsWsAfterSep(MA_SigArgElems arg);
MA_OptLayout MA_getSigArgElemsWsAfterSep(MA_SigArgElems arg);
MA_SigArgElems MA_setSigArgElemsWsAfterSep(MA_SigArgElems arg, MA_OptLayout wsAfterSep);
ATbool MA_hasSigArgElemsTail(MA_SigArgElems arg);
MA_SigArgElems MA_getSigArgElemsTail(MA_SigArgElems arg);
MA_SigArgElems MA_setSigArgElemsTail(MA_SigArgElems arg, MA_SigArgElems tail);

/*}}}  */
/*{{{  MA_Annotations accessors */

ATbool MA_isValidAnnotations(MA_Annotations arg);
inline ATbool MA_isAnnotationsDefault(MA_Annotations arg);
ATbool MA_hasAnnotationsWsAfterBraceOpen(MA_Annotations arg);
MA_OptLayout MA_getAnnotationsWsAfterBraceOpen(MA_Annotations arg);
MA_Annotations MA_setAnnotationsWsAfterBraceOpen(MA_Annotations arg, MA_OptLayout wsAfterBraceOpen);
ATbool MA_hasAnnotationsTerms(MA_Annotations arg);
MA_TermTerms MA_getAnnotationsTerms(MA_Annotations arg);
MA_Annotations MA_setAnnotationsTerms(MA_Annotations arg, MA_TermTerms terms);
ATbool MA_hasAnnotationsWsAfterTerms(MA_Annotations arg);
MA_OptLayout MA_getAnnotationsWsAfterTerms(MA_Annotations arg);
MA_Annotations MA_setAnnotationsWsAfterTerms(MA_Annotations arg, MA_OptLayout wsAfterTerms);

/*}}}  */
/*{{{  MA_TermTerms accessors */

ATbool MA_isValidTermTerms(MA_TermTerms arg);
inline ATbool MA_isTermTermsSingle(MA_TermTerms arg);
inline ATbool MA_isTermTermsMany(MA_TermTerms arg);
ATbool MA_hasTermTermsHead(MA_TermTerms arg);
MA_Term MA_getTermTermsHead(MA_TermTerms arg);
MA_TermTerms MA_setTermTermsHead(MA_TermTerms arg, MA_Term head);
ATbool MA_hasTermTermsWsAfterFirst(MA_TermTerms arg);
MA_OptLayout MA_getTermTermsWsAfterFirst(MA_TermTerms arg);
MA_TermTerms MA_setTermTermsWsAfterFirst(MA_TermTerms arg, MA_OptLayout wsAfterFirst);
ATbool MA_hasTermTermsSep(MA_TermTerms arg);
char* MA_getTermTermsSep(MA_TermTerms arg);
MA_TermTerms MA_setTermTermsSep(MA_TermTerms arg, char* sep);
ATbool MA_hasTermTermsWsAfterSep(MA_TermTerms arg);
MA_OptLayout MA_getTermTermsWsAfterSep(MA_TermTerms arg);
MA_TermTerms MA_setTermTermsWsAfterSep(MA_TermTerms arg, MA_OptLayout wsAfterSep);
ATbool MA_hasTermTermsTail(MA_TermTerms arg);
MA_TermTerms MA_getTermTermsTail(MA_TermTerms arg);
MA_TermTerms MA_setTermTermsTail(MA_TermTerms arg, MA_TermTerms tail);

/*}}}  */
/*{{{  MA_SigArgList accessors */

ATbool MA_isValidSigArgList(MA_SigArgList arg);
inline ATbool MA_isSigArgListDefault(MA_SigArgList arg);
ATbool MA_hasSigArgListElems(MA_SigArgList arg);
MA_SigArgElems MA_getSigArgListElems(MA_SigArgList arg);
MA_SigArgList MA_setSigArgListElems(MA_SigArgList arg, MA_SigArgElems elems);

/*}}}  */
/*{{{  MA_FuncDefList accessors */

ATbool MA_isValidFuncDefList(MA_FuncDefList arg);
inline ATbool MA_isFuncDefListDefault(MA_FuncDefList arg);
ATbool MA_hasFuncDefListElems(MA_FuncDefList arg);
MA_FuncDefElems MA_getFuncDefListElems(MA_FuncDefList arg);
MA_FuncDefList MA_setFuncDefListElems(MA_FuncDefList arg, MA_FuncDefElems elems);

/*}}}  */
/*{{{  MA_FuncDefElems accessors */

ATbool MA_isValidFuncDefElems(MA_FuncDefElems arg);
inline ATbool MA_isFuncDefElemsEmpty(MA_FuncDefElems arg);
inline ATbool MA_isFuncDefElemsSingle(MA_FuncDefElems arg);
inline ATbool MA_isFuncDefElemsMany(MA_FuncDefElems arg);
ATbool MA_hasFuncDefElemsHead(MA_FuncDefElems arg);
MA_FuncDef MA_getFuncDefElemsHead(MA_FuncDefElems arg);
MA_FuncDefElems MA_setFuncDefElemsHead(MA_FuncDefElems arg, MA_FuncDef head);
ATbool MA_hasFuncDefElemsWsAfterFirst(MA_FuncDefElems arg);
MA_OptLayout MA_getFuncDefElemsWsAfterFirst(MA_FuncDefElems arg);
MA_FuncDefElems MA_setFuncDefElemsWsAfterFirst(MA_FuncDefElems arg, MA_OptLayout wsAfterFirst);
ATbool MA_hasFuncDefElemsSep(MA_FuncDefElems arg);
char* MA_getFuncDefElemsSep(MA_FuncDefElems arg);
MA_FuncDefElems MA_setFuncDefElemsSep(MA_FuncDefElems arg, char* sep);
ATbool MA_hasFuncDefElemsWsAfterSep(MA_FuncDefElems arg);
MA_OptLayout MA_getFuncDefElemsWsAfterSep(MA_FuncDefElems arg);
MA_FuncDefElems MA_setFuncDefElemsWsAfterSep(MA_FuncDefElems arg, MA_OptLayout wsAfterSep);
ATbool MA_hasFuncDefElemsTail(MA_FuncDefElems arg);
MA_FuncDefElems MA_getFuncDefElemsTail(MA_FuncDefElems arg);
MA_FuncDefElems MA_setFuncDefElemsTail(MA_FuncDefElems arg, MA_FuncDefElems tail);

/*}}}  */
/*{{{  MA_Rule accessors */

ATbool MA_isValidRule(MA_Rule arg);
inline ATbool MA_isRuleNoConds(MA_Rule arg);
inline ATbool MA_isRuleDefaultNoConds(MA_Rule arg);
inline ATbool MA_isRuleDefaultWithConds(MA_Rule arg);
inline ATbool MA_isRuleWithConds(MA_Rule arg);
ATbool MA_hasRuleLhs(MA_Rule arg);
MA_Term MA_getRuleLhs(MA_Rule arg);
MA_Rule MA_setRuleLhs(MA_Rule arg, MA_Term lhs);
ATbool MA_hasRuleWsAfterLhs(MA_Rule arg);
MA_OptLayout MA_getRuleWsAfterLhs(MA_Rule arg);
MA_Rule MA_setRuleWsAfterLhs(MA_Rule arg, MA_OptLayout wsAfterLhs);
ATbool MA_hasRuleWsAfterEquals(MA_Rule arg);
MA_OptLayout MA_getRuleWsAfterEquals(MA_Rule arg);
MA_Rule MA_setRuleWsAfterEquals(MA_Rule arg, MA_OptLayout wsAfterEquals);
ATbool MA_hasRuleRhs(MA_Rule arg);
MA_Term MA_getRuleRhs(MA_Rule arg);
MA_Rule MA_setRuleRhs(MA_Rule arg, MA_Term rhs);
ATbool MA_hasRuleWsAfterDefaultColon(MA_Rule arg);
MA_OptLayout MA_getRuleWsAfterDefaultColon(MA_Rule arg);
MA_Rule MA_setRuleWsAfterDefaultColon(MA_Rule arg, MA_OptLayout wsAfterDefaultColon);
ATbool MA_hasRuleConds(MA_Rule arg);
MA_CondList MA_getRuleConds(MA_Rule arg);
MA_Rule MA_setRuleConds(MA_Rule arg, MA_CondList conds);
ATbool MA_hasRuleWsAfterConds(MA_Rule arg);
MA_OptLayout MA_getRuleWsAfterConds(MA_Rule arg);
MA_Rule MA_setRuleWsAfterConds(MA_Rule arg, MA_OptLayout wsAfterConds);
ATbool MA_hasRuleWsAfterImplies(MA_Rule arg);
MA_OptLayout MA_getRuleWsAfterImplies(MA_Rule arg);
MA_Rule MA_setRuleWsAfterImplies(MA_Rule arg, MA_OptLayout wsAfterImplies);

/*}}}  */
/*{{{  MA_RuleList accessors */

ATbool MA_isValidRuleList(MA_RuleList arg);
inline ATbool MA_isRuleListDefault(MA_RuleList arg);
ATbool MA_hasRuleListElems(MA_RuleList arg);
MA_RuleElems MA_getRuleListElems(MA_RuleList arg);
MA_RuleList MA_setRuleListElems(MA_RuleList arg, MA_RuleElems elems);

/*}}}  */
/*{{{  MA_RuleElems accessors */

ATbool MA_isValidRuleElems(MA_RuleElems arg);
inline ATbool MA_isRuleElemsEmpty(MA_RuleElems arg);
inline ATbool MA_isRuleElemsSingle(MA_RuleElems arg);
inline ATbool MA_isRuleElemsMany(MA_RuleElems arg);
ATbool MA_hasRuleElemsHead(MA_RuleElems arg);
MA_Rule MA_getRuleElemsHead(MA_RuleElems arg);
MA_RuleElems MA_setRuleElemsHead(MA_RuleElems arg, MA_Rule head);
ATbool MA_hasRuleElemsWsAfterFirst(MA_RuleElems arg);
MA_OptLayout MA_getRuleElemsWsAfterFirst(MA_RuleElems arg);
MA_RuleElems MA_setRuleElemsWsAfterFirst(MA_RuleElems arg, MA_OptLayout wsAfterFirst);
ATbool MA_hasRuleElemsSep(MA_RuleElems arg);
char* MA_getRuleElemsSep(MA_RuleElems arg);
MA_RuleElems MA_setRuleElemsSep(MA_RuleElems arg, char* sep);
ATbool MA_hasRuleElemsWsAfterSep(MA_RuleElems arg);
MA_OptLayout MA_getRuleElemsWsAfterSep(MA_RuleElems arg);
MA_RuleElems MA_setRuleElemsWsAfterSep(MA_RuleElems arg, MA_OptLayout wsAfterSep);
ATbool MA_hasRuleElemsTail(MA_RuleElems arg);
MA_RuleElems MA_getRuleElemsTail(MA_RuleElems arg);
MA_RuleElems MA_setRuleElemsTail(MA_RuleElems arg, MA_RuleElems tail);

/*}}}  */
/*{{{  MA_CondList accessors */

ATbool MA_isValidCondList(MA_CondList arg);
inline ATbool MA_isCondListDefault(MA_CondList arg);
ATbool MA_hasCondListElems(MA_CondList arg);
MA_CondElems MA_getCondListElems(MA_CondList arg);
MA_CondList MA_setCondListElems(MA_CondList arg, MA_CondElems elems);

/*}}}  */
/*{{{  MA_CondElems accessors */

ATbool MA_isValidCondElems(MA_CondElems arg);
inline ATbool MA_isCondElemsEmpty(MA_CondElems arg);
inline ATbool MA_isCondElemsSingle(MA_CondElems arg);
inline ATbool MA_isCondElemsMany(MA_CondElems arg);
ATbool MA_hasCondElemsHead(MA_CondElems arg);
MA_Cond MA_getCondElemsHead(MA_CondElems arg);
MA_CondElems MA_setCondElemsHead(MA_CondElems arg, MA_Cond head);
ATbool MA_hasCondElemsWsAfterFirst(MA_CondElems arg);
MA_OptLayout MA_getCondElemsWsAfterFirst(MA_CondElems arg);
MA_CondElems MA_setCondElemsWsAfterFirst(MA_CondElems arg, MA_OptLayout wsAfterFirst);
ATbool MA_hasCondElemsSep(MA_CondElems arg);
char* MA_getCondElemsSep(MA_CondElems arg);
MA_CondElems MA_setCondElemsSep(MA_CondElems arg, char* sep);
ATbool MA_hasCondElemsWsAfterSep(MA_CondElems arg);
MA_OptLayout MA_getCondElemsWsAfterSep(MA_CondElems arg);
MA_CondElems MA_setCondElemsWsAfterSep(MA_CondElems arg, MA_OptLayout wsAfterSep);
ATbool MA_hasCondElemsTail(MA_CondElems arg);
MA_CondElems MA_getCondElemsTail(MA_CondElems arg);
MA_CondElems MA_setCondElemsTail(MA_CondElems arg, MA_CondElems tail);

/*}}}  */
/*{{{  MA_Cond accessors */

ATbool MA_isValidCond(MA_Cond arg);
inline ATbool MA_isCondAssign(MA_Cond arg);
inline ATbool MA_isCondEqual(MA_Cond arg);
inline ATbool MA_isCondUnequal(MA_Cond arg);
ATbool MA_hasCondLhs(MA_Cond arg);
MA_Term MA_getCondLhs(MA_Cond arg);
MA_Cond MA_setCondLhs(MA_Cond arg, MA_Term lhs);
ATbool MA_hasCondWsAfterLhs(MA_Cond arg);
MA_OptLayout MA_getCondWsAfterLhs(MA_Cond arg);
MA_Cond MA_setCondWsAfterLhs(MA_Cond arg, MA_OptLayout wsAfterLhs);
ATbool MA_hasCondWsAfterAssign(MA_Cond arg);
MA_OptLayout MA_getCondWsAfterAssign(MA_Cond arg);
MA_Cond MA_setCondWsAfterAssign(MA_Cond arg, MA_OptLayout wsAfterAssign);
ATbool MA_hasCondRhs(MA_Cond arg);
MA_Term MA_getCondRhs(MA_Cond arg);
MA_Cond MA_setCondRhs(MA_Cond arg, MA_Term rhs);
ATbool MA_hasCondWsAfterEqual(MA_Cond arg);
MA_OptLayout MA_getCondWsAfterEqual(MA_Cond arg);
MA_Cond MA_setCondWsAfterEqual(MA_Cond arg, MA_OptLayout wsAfterEqual);
ATbool MA_hasCondWsAfterUnequal(MA_Cond arg);
MA_OptLayout MA_getCondWsAfterUnequal(MA_Cond arg);
MA_Cond MA_setCondWsAfterUnequal(MA_Cond arg, MA_OptLayout wsAfterUnequal);

/*}}}  */
/*{{{  MA_SignatureOpt accessors */

ATbool MA_isValidSignatureOpt(MA_SignatureOpt arg);
inline ATbool MA_isSignatureOptAbsent(MA_SignatureOpt arg);
inline ATbool MA_isSignatureOptPresent(MA_SignatureOpt arg);
ATbool MA_hasSignatureOptWsAfterSignature(MA_SignatureOpt arg);
MA_OptLayout MA_getSignatureOptWsAfterSignature(MA_SignatureOpt arg);
MA_SignatureOpt MA_setSignatureOptWsAfterSignature(MA_SignatureOpt arg, MA_OptLayout wsAfterSignature);
ATbool MA_hasSignatureOptFuncdefs(MA_SignatureOpt arg);
MA_FuncDefList MA_getSignatureOptFuncdefs(MA_SignatureOpt arg);
MA_SignatureOpt MA_setSignatureOptFuncdefs(MA_SignatureOpt arg, MA_FuncDefList funcdefs);

/*}}}  */
/*{{{  MA_RulesOpt accessors */

ATbool MA_isValidRulesOpt(MA_RulesOpt arg);
inline ATbool MA_isRulesOptAbsent(MA_RulesOpt arg);
inline ATbool MA_isRulesOptPresent(MA_RulesOpt arg);
ATbool MA_hasRulesOptWsAfterRules(MA_RulesOpt arg);
MA_OptLayout MA_getRulesOptWsAfterRules(MA_RulesOpt arg);
MA_RulesOpt MA_setRulesOptWsAfterRules(MA_RulesOpt arg, MA_OptLayout wsAfterRules);
ATbool MA_hasRulesOptRules(MA_RulesOpt arg);
MA_RuleList MA_getRulesOptRules(MA_RulesOpt arg);
MA_RulesOpt MA_setRulesOptRules(MA_RulesOpt arg, MA_RuleList rules);

/*}}}  */
/*{{{  MA_Module accessors */

ATbool MA_isValidModule(MA_Module arg);
inline ATbool MA_isModuleModule(MA_Module arg);
ATbool MA_hasModuleWsAfterModule(MA_Module arg);
MA_OptLayout MA_getModuleWsAfterModule(MA_Module arg);
MA_Module MA_setModuleWsAfterModule(MA_Module arg, MA_OptLayout wsAfterModule);
ATbool MA_hasModuleId(MA_Module arg);
MA_ModId MA_getModuleId(MA_Module arg);
MA_Module MA_setModuleId(MA_Module arg, MA_ModId id);
ATbool MA_hasModuleWsAfterId(MA_Module arg);
MA_OptLayout MA_getModuleWsAfterId(MA_Module arg);
MA_Module MA_setModuleWsAfterId(MA_Module arg, MA_OptLayout wsAfterId);
ATbool MA_hasModuleSignature(MA_Module arg);
MA_SignatureOpt MA_getModuleSignature(MA_Module arg);
MA_Module MA_setModuleSignature(MA_Module arg, MA_SignatureOpt signature);
ATbool MA_hasModuleWsAfterSignature(MA_Module arg);
MA_OptLayout MA_getModuleWsAfterSignature(MA_Module arg);
MA_Module MA_setModuleWsAfterSignature(MA_Module arg, MA_OptLayout wsAfterSignature);
ATbool MA_hasModuleRules(MA_Module arg);
MA_RulesOpt MA_getModuleRules(MA_Module arg);
MA_Module MA_setModuleRules(MA_Module arg, MA_RulesOpt rules);

/*}}}  */
/*{{{  MA_EscChar accessors */

ATbool MA_isValidEscChar(MA_EscChar arg);
inline ATbool MA_isEscCharDefault(MA_EscChar arg);
inline ATbool MA_isEscCharOct0Underscore177(MA_EscChar arg);
ATbool MA_hasEscCharChars(MA_EscChar arg);
MA_CHARLIST MA_getEscCharChars(MA_EscChar arg);
MA_EscChar MA_setEscCharChars(MA_EscChar arg, MA_CHARLIST chars);

/*}}}  */
/*{{{  MA_QChar accessors */

ATbool MA_isValidQChar(MA_QChar arg);
inline ATbool MA_isQCharPrintable(MA_QChar arg);
inline ATbool MA_isQCharEscaped(MA_QChar arg);
ATbool MA_hasQCharChars(MA_QChar arg);
MA_CHARLIST MA_getQCharChars(MA_QChar arg);
MA_QChar MA_setQCharChars(MA_QChar arg, MA_CHARLIST chars);

/*}}}  */
/*{{{  MA_FunId accessors */

ATbool MA_isValidFunId(MA_FunId arg);
inline ATbool MA_isFunIdUnquoted(MA_FunId arg);
inline ATbool MA_isFunIdQuoted(MA_FunId arg);
inline ATbool MA_isFunIdSingleQuote(MA_FunId arg);
inline ATbool MA_isFunIdDecimal(MA_FunId arg);
ATbool MA_hasFunIdChars(MA_FunId arg);
MA_CHARLIST MA_getFunIdChars(MA_FunId arg);
MA_FunId MA_setFunIdChars(MA_FunId arg, MA_CHARLIST chars);

/*}}}  */
/*{{{  MA_VarId accessors */

ATbool MA_isValidVarId(MA_VarId arg);
inline ATbool MA_isVarIdDefault(MA_VarId arg);
ATbool MA_hasVarIdChars(MA_VarId arg);
MA_CHARLIST MA_getVarIdChars(MA_VarId arg);
MA_VarId MA_setVarIdChars(MA_VarId arg, MA_CHARLIST chars);

/*}}}  */
/*{{{  MA_ModId accessors */

ATbool MA_isValidModId(MA_ModId arg);
inline ATbool MA_isModIdDefault(MA_ModId arg);
ATbool MA_hasModIdChars(MA_ModId arg);
MA_CHARLIST MA_getModIdChars(MA_ModId arg);
MA_ModId MA_setModIdChars(MA_ModId arg, MA_CHARLIST chars);

/*}}}  */
/*{{{  MA_PropId accessors */

ATbool MA_isValidPropId(MA_PropId arg);
inline ATbool MA_isPropIdDefault(MA_PropId arg);
ATbool MA_hasPropIdChars(MA_PropId arg);
MA_CHARLIST MA_getPropIdChars(MA_PropId arg);
MA_PropId MA_setPropIdChars(MA_PropId arg, MA_CHARLIST chars);

/*}}}  */
/*{{{  MA_Start accessors */

ATbool MA_isValidStart(MA_Start arg);
inline ATbool MA_isStartPropId(MA_Start arg);
inline ATbool MA_isStartVarId(MA_Start arg);
inline ATbool MA_isStartModId(MA_Start arg);
inline ATbool MA_isStartFunId(MA_Start arg);
inline ATbool MA_isStartTermList(MA_Start arg);
inline ATbool MA_isStartTerm(MA_Start arg);
inline ATbool MA_isStartVar(MA_Start arg);
inline ATbool MA_isStartSigArgList(MA_Start arg);
inline ATbool MA_isStartSigArg(MA_Start arg);
inline ATbool MA_isStartFuncDefList(MA_Start arg);
inline ATbool MA_isStartFuncDef(MA_Start arg);
inline ATbool MA_isStartAnnotations(MA_Start arg);
inline ATbool MA_isStartCondList(MA_Start arg);
inline ATbool MA_isStartCond(MA_Start arg);
inline ATbool MA_isStartRuleList(MA_Start arg);
inline ATbool MA_isStartRule(MA_Start arg);
inline ATbool MA_isStartSignatureOpt(MA_Start arg);
inline ATbool MA_isStartRulesOpt(MA_Start arg);
inline ATbool MA_isStartModule(MA_Start arg);
inline ATbool MA_isStartIntCon(MA_Start arg);
inline ATbool MA_isStartNatCon(MA_Start arg);
inline ATbool MA_isStartInt(MA_Start arg);
ATbool MA_hasStartWsBefore(MA_Start arg);
MA_OptLayout MA_getStartWsBefore(MA_Start arg);
MA_Start MA_setStartWsBefore(MA_Start arg, MA_OptLayout wsBefore);
ATbool MA_hasStartTopPropId(MA_Start arg);
MA_PropId MA_getStartTopPropId(MA_Start arg);
MA_Start MA_setStartTopPropId(MA_Start arg, MA_PropId topPropId);
ATbool MA_hasStartWsAfter(MA_Start arg);
MA_OptLayout MA_getStartWsAfter(MA_Start arg);
MA_Start MA_setStartWsAfter(MA_Start arg, MA_OptLayout wsAfter);
ATbool MA_hasStartAmbCnt(MA_Start arg);
int MA_getStartAmbCnt(MA_Start arg);
MA_Start MA_setStartAmbCnt(MA_Start arg, int ambCnt);
ATbool MA_hasStartTopVarId(MA_Start arg);
MA_VarId MA_getStartTopVarId(MA_Start arg);
MA_Start MA_setStartTopVarId(MA_Start arg, MA_VarId topVarId);
ATbool MA_hasStartTopModId(MA_Start arg);
MA_ModId MA_getStartTopModId(MA_Start arg);
MA_Start MA_setStartTopModId(MA_Start arg, MA_ModId topModId);
ATbool MA_hasStartTopFunId(MA_Start arg);
MA_FunId MA_getStartTopFunId(MA_Start arg);
MA_Start MA_setStartTopFunId(MA_Start arg, MA_FunId topFunId);
ATbool MA_hasStartTopTermList(MA_Start arg);
MA_TermList MA_getStartTopTermList(MA_Start arg);
MA_Start MA_setStartTopTermList(MA_Start arg, MA_TermList topTermList);
ATbool MA_hasStartTopTerm(MA_Start arg);
MA_Term MA_getStartTopTerm(MA_Start arg);
MA_Start MA_setStartTopTerm(MA_Start arg, MA_Term topTerm);
ATbool MA_hasStartTopVar(MA_Start arg);
MA_Var MA_getStartTopVar(MA_Start arg);
MA_Start MA_setStartTopVar(MA_Start arg, MA_Var topVar);
ATbool MA_hasStartTopSigArgList(MA_Start arg);
MA_SigArgList MA_getStartTopSigArgList(MA_Start arg);
MA_Start MA_setStartTopSigArgList(MA_Start arg, MA_SigArgList topSigArgList);
ATbool MA_hasStartTopSigArg(MA_Start arg);
MA_SigArg MA_getStartTopSigArg(MA_Start arg);
MA_Start MA_setStartTopSigArg(MA_Start arg, MA_SigArg topSigArg);
ATbool MA_hasStartTopFuncDefList(MA_Start arg);
MA_FuncDefList MA_getStartTopFuncDefList(MA_Start arg);
MA_Start MA_setStartTopFuncDefList(MA_Start arg, MA_FuncDefList topFuncDefList);
ATbool MA_hasStartTopFuncDef(MA_Start arg);
MA_FuncDef MA_getStartTopFuncDef(MA_Start arg);
MA_Start MA_setStartTopFuncDef(MA_Start arg, MA_FuncDef topFuncDef);
ATbool MA_hasStartTopAnnotations(MA_Start arg);
MA_Annotations MA_getStartTopAnnotations(MA_Start arg);
MA_Start MA_setStartTopAnnotations(MA_Start arg, MA_Annotations topAnnotations);
ATbool MA_hasStartTopCondList(MA_Start arg);
MA_CondList MA_getStartTopCondList(MA_Start arg);
MA_Start MA_setStartTopCondList(MA_Start arg, MA_CondList topCondList);
ATbool MA_hasStartTopCond(MA_Start arg);
MA_Cond MA_getStartTopCond(MA_Start arg);
MA_Start MA_setStartTopCond(MA_Start arg, MA_Cond topCond);
ATbool MA_hasStartTopRuleList(MA_Start arg);
MA_RuleList MA_getStartTopRuleList(MA_Start arg);
MA_Start MA_setStartTopRuleList(MA_Start arg, MA_RuleList topRuleList);
ATbool MA_hasStartTopRule(MA_Start arg);
MA_Rule MA_getStartTopRule(MA_Start arg);
MA_Start MA_setStartTopRule(MA_Start arg, MA_Rule topRule);
ATbool MA_hasStartTopSignatureOpt(MA_Start arg);
MA_SignatureOpt MA_getStartTopSignatureOpt(MA_Start arg);
MA_Start MA_setStartTopSignatureOpt(MA_Start arg, MA_SignatureOpt topSignatureOpt);
ATbool MA_hasStartTopRulesOpt(MA_Start arg);
MA_RulesOpt MA_getStartTopRulesOpt(MA_Start arg);
MA_Start MA_setStartTopRulesOpt(MA_Start arg, MA_RulesOpt topRulesOpt);
ATbool MA_hasStartTopModule(MA_Start arg);
MA_Module MA_getStartTopModule(MA_Start arg);
MA_Start MA_setStartTopModule(MA_Start arg, MA_Module topModule);
ATbool MA_hasStartTopIntCon(MA_Start arg);
MA_IntCon MA_getStartTopIntCon(MA_Start arg);
MA_Start MA_setStartTopIntCon(MA_Start arg, MA_IntCon topIntCon);
ATbool MA_hasStartTopNatCon(MA_Start arg);
MA_NatCon MA_getStartTopNatCon(MA_Start arg);
MA_Start MA_setStartTopNatCon(MA_Start arg, MA_NatCon topNatCon);
ATbool MA_hasStartTopInt(MA_Start arg);
MA_Int MA_getStartTopInt(MA_Start arg);
MA_Start MA_setStartTopInt(MA_Start arg, MA_Int topInt);

/*}}}  */
/*{{{  MA_OptLayout accessors */

ATbool MA_isValidOptLayout(MA_OptLayout arg);
inline ATbool MA_isOptLayoutAbsent(MA_OptLayout arg);
inline ATbool MA_isOptLayoutPresent(MA_OptLayout arg);
ATbool MA_hasOptLayoutChars(MA_OptLayout arg);
MA_CHARLIST MA_getOptLayoutChars(MA_OptLayout arg);
MA_OptLayout MA_setOptLayoutChars(MA_OptLayout arg, MA_CHARLIST chars);

/*}}}  */
/*{{{  sort visitors */

MA_Int MA_visitInt(MA_Int arg, MA_IntCon (*acceptIntCon)(MA_IntCon), MA_OptLayout (*acceptWsAfterLhs)(MA_OptLayout), MA_OptLayout (*acceptWsAfterPlus)(MA_OptLayout));
MA_IntCon MA_visitIntCon(MA_IntCon arg, MA_OptLayout (*acceptWsAfterCon)(MA_OptLayout), MA_OptLayout (*acceptWsAfterParenOpen)(MA_OptLayout), MA_Int (*acceptIntArg)(MA_Int), MA_OptLayout (*acceptWsAfterIntArg)(MA_OptLayout), MA_NatCon (*acceptNatCon)(MA_NatCon), MA_OptLayout (*acceptWsAfterPlus)(MA_OptLayout), MA_NatCon (*acceptNatArg)(MA_NatCon), MA_OptLayout (*acceptWsAfter)(MA_OptLayout));
MA_NatCon MA_visitNatCon(MA_NatCon arg, MA_OptLayout (*acceptWsAfterAbs)(MA_OptLayout), MA_OptLayout (*acceptWsAfterParenOpen)(MA_OptLayout), MA_Int (*acceptIntArg)(MA_Int), MA_OptLayout (*acceptWsAfterIntArg)(MA_OptLayout));
MA_Var MA_visitVar(MA_Var arg, MA_VarId (*acceptVarId)(MA_VarId), MA_OptLayout (*acceptWsAfterStar)(MA_OptLayout), MA_OptLayout (*acceptWsAfterPlus)(MA_OptLayout));
MA_Term MA_visitTerm(MA_Term arg, MA_Var (*acceptVar)(MA_Var), MA_FunId (*acceptFunId)(MA_FunId), MA_Int (*acceptInt)(MA_Int), MA_OptLayout (*acceptWsAfterFunId)(MA_OptLayout), MA_OptLayout (*acceptWsAfterParenOpen)(MA_OptLayout), MA_TermArgs (*acceptArgs)(MA_TermArgs), MA_OptLayout (*acceptWsAfterArgs)(MA_OptLayout), MA_OptLayout (*acceptWsAfterBracketOpen)(MA_OptLayout), MA_TermList (*acceptTermList)(MA_TermList), MA_OptLayout (*acceptWsAfterTermList)(MA_OptLayout), MA_OptLayout (*acceptWsAfterTerm)(MA_OptLayout), MA_OptLayout (*acceptWsAfterColon)(MA_OptLayout));
MA_TermArgs MA_visitTermArgs(MA_TermArgs arg, MA_Term (*acceptHead)(MA_Term), MA_OptLayout (*acceptWsAfterFirst)(MA_OptLayout), char* (*acceptSep)(char*), MA_OptLayout (*acceptWsAfterSep)(MA_OptLayout));
MA_TermList MA_visitTermList(MA_TermList arg, MA_TermElems (*acceptElems)(MA_TermElems));
MA_TermElems MA_visitTermElems(MA_TermElems arg, MA_Term (*acceptHead)(MA_Term), MA_OptLayout (*acceptWsAfterFirst)(MA_OptLayout), char* (*acceptSep)(char*), MA_OptLayout (*acceptWsAfterSep)(MA_OptLayout));
MA_SigArg MA_visitSigArg(MA_SigArg arg, MA_OptLayout (*acceptWsAfterUnderscore)(MA_OptLayout));
MA_FuncDef MA_visitFuncDef(MA_FuncDef arg, MA_FunId (*acceptFunId)(MA_FunId), MA_OptLayout (*acceptWsAfterFunId)(MA_OptLayout), MA_Annotations (*acceptAnnos)(MA_Annotations), MA_OptLayout (*acceptWsAfterParenOpen)(MA_OptLayout), MA_SigArgElems (*acceptElems)(MA_SigArgElems), MA_OptLayout (*acceptWsAfterElems)(MA_OptLayout), MA_OptLayout (*acceptWsAfterParenClose)(MA_OptLayout));
MA_SigArgElems MA_visitSigArgElems(MA_SigArgElems arg, MA_SigArg (*acceptHead)(MA_SigArg), MA_OptLayout (*acceptWsAfterFirst)(MA_OptLayout), char* (*acceptSep)(char*), MA_OptLayout (*acceptWsAfterSep)(MA_OptLayout));
MA_Annotations MA_visitAnnotations(MA_Annotations arg, MA_OptLayout (*acceptWsAfterBraceOpen)(MA_OptLayout), MA_TermTerms (*acceptTerms)(MA_TermTerms), MA_OptLayout (*acceptWsAfterTerms)(MA_OptLayout));
MA_TermTerms MA_visitTermTerms(MA_TermTerms arg, MA_Term (*acceptHead)(MA_Term), MA_OptLayout (*acceptWsAfterFirst)(MA_OptLayout), char* (*acceptSep)(char*), MA_OptLayout (*acceptWsAfterSep)(MA_OptLayout));
MA_SigArgList MA_visitSigArgList(MA_SigArgList arg, MA_SigArgElems (*acceptElems)(MA_SigArgElems));
MA_FuncDefList MA_visitFuncDefList(MA_FuncDefList arg, MA_FuncDefElems (*acceptElems)(MA_FuncDefElems));
MA_FuncDefElems MA_visitFuncDefElems(MA_FuncDefElems arg, MA_FuncDef (*acceptHead)(MA_FuncDef), MA_OptLayout (*acceptWsAfterFirst)(MA_OptLayout), char* (*acceptSep)(char*), MA_OptLayout (*acceptWsAfterSep)(MA_OptLayout));
MA_Rule MA_visitRule(MA_Rule arg, MA_Term (*acceptLhs)(MA_Term), MA_OptLayout (*acceptWsAfterLhs)(MA_OptLayout), MA_OptLayout (*acceptWsAfterEquals)(MA_OptLayout), MA_Term (*acceptRhs)(MA_Term), MA_OptLayout (*acceptWsAfterDefaultColon)(MA_OptLayout), MA_CondList (*acceptConds)(MA_CondList), MA_OptLayout (*acceptWsAfterConds)(MA_OptLayout), MA_OptLayout (*acceptWsAfterImplies)(MA_OptLayout));
MA_RuleList MA_visitRuleList(MA_RuleList arg, MA_RuleElems (*acceptElems)(MA_RuleElems));
MA_RuleElems MA_visitRuleElems(MA_RuleElems arg, MA_Rule (*acceptHead)(MA_Rule), MA_OptLayout (*acceptWsAfterFirst)(MA_OptLayout), char* (*acceptSep)(char*), MA_OptLayout (*acceptWsAfterSep)(MA_OptLayout));
MA_CondList MA_visitCondList(MA_CondList arg, MA_CondElems (*acceptElems)(MA_CondElems));
MA_CondElems MA_visitCondElems(MA_CondElems arg, MA_Cond (*acceptHead)(MA_Cond), MA_OptLayout (*acceptWsAfterFirst)(MA_OptLayout), char* (*acceptSep)(char*), MA_OptLayout (*acceptWsAfterSep)(MA_OptLayout));
MA_Cond MA_visitCond(MA_Cond arg, MA_Term (*acceptLhs)(MA_Term), MA_OptLayout (*acceptWsAfterLhs)(MA_OptLayout), MA_OptLayout (*acceptWsAfterAssign)(MA_OptLayout), MA_Term (*acceptRhs)(MA_Term), MA_OptLayout (*acceptWsAfterEqual)(MA_OptLayout), MA_OptLayout (*acceptWsAfterUnequal)(MA_OptLayout));
MA_SignatureOpt MA_visitSignatureOpt(MA_SignatureOpt arg, MA_OptLayout (*acceptWsAfterSignature)(MA_OptLayout), MA_FuncDefList (*acceptFuncdefs)(MA_FuncDefList));
MA_RulesOpt MA_visitRulesOpt(MA_RulesOpt arg, MA_OptLayout (*acceptWsAfterRules)(MA_OptLayout), MA_RuleList (*acceptRules)(MA_RuleList));
MA_Module MA_visitModule(MA_Module arg, MA_OptLayout (*acceptWsAfterModule)(MA_OptLayout), MA_ModId (*acceptId)(MA_ModId), MA_OptLayout (*acceptWsAfterId)(MA_OptLayout), MA_SignatureOpt (*acceptSignature)(MA_SignatureOpt), MA_OptLayout (*acceptWsAfterSignature)(MA_OptLayout), MA_RulesOpt (*acceptRules)(MA_RulesOpt));
MA_EscChar MA_visitEscChar(MA_EscChar arg, MA_CHARLIST (*acceptChars)(MA_CHARLIST));
MA_QChar MA_visitQChar(MA_QChar arg, MA_CHARLIST (*acceptChars)(MA_CHARLIST));
MA_FunId MA_visitFunId(MA_FunId arg, MA_CHARLIST (*acceptChars)(MA_CHARLIST));
MA_VarId MA_visitVarId(MA_VarId arg, MA_CHARLIST (*acceptChars)(MA_CHARLIST));
MA_ModId MA_visitModId(MA_ModId arg, MA_CHARLIST (*acceptChars)(MA_CHARLIST));
MA_PropId MA_visitPropId(MA_PropId arg, MA_CHARLIST (*acceptChars)(MA_CHARLIST));
MA_Start MA_visitStart(MA_Start arg, MA_OptLayout (*acceptWsBefore)(MA_OptLayout), MA_PropId (*acceptTopPropId)(MA_PropId), MA_OptLayout (*acceptWsAfter)(MA_OptLayout), int (*acceptAmbCnt)(int), MA_VarId (*acceptTopVarId)(MA_VarId), MA_ModId (*acceptTopModId)(MA_ModId), MA_FunId (*acceptTopFunId)(MA_FunId), MA_TermList (*acceptTopTermList)(MA_TermList), MA_Term (*acceptTopTerm)(MA_Term), MA_Var (*acceptTopVar)(MA_Var), MA_SigArgList (*acceptTopSigArgList)(MA_SigArgList), MA_SigArg (*acceptTopSigArg)(MA_SigArg), MA_FuncDefList (*acceptTopFuncDefList)(MA_FuncDefList), MA_FuncDef (*acceptTopFuncDef)(MA_FuncDef), MA_Annotations (*acceptTopAnnotations)(MA_Annotations), MA_CondList (*acceptTopCondList)(MA_CondList), MA_Cond (*acceptTopCond)(MA_Cond), MA_RuleList (*acceptTopRuleList)(MA_RuleList), MA_Rule (*acceptTopRule)(MA_Rule), MA_SignatureOpt (*acceptTopSignatureOpt)(MA_SignatureOpt), MA_RulesOpt (*acceptTopRulesOpt)(MA_RulesOpt), MA_Module (*acceptTopModule)(MA_Module), MA_IntCon (*acceptTopIntCon)(MA_IntCon), MA_NatCon (*acceptTopNatCon)(MA_NatCon), MA_Int (*acceptTopInt)(MA_Int));
MA_OptLayout MA_visitOptLayout(MA_OptLayout arg, MA_CHARLIST (*acceptChars)(MA_CHARLIST));

/*}}}  */

#endif /* _MUASF_H */
