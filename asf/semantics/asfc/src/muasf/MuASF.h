#ifndef _MUASF_H
#define _MUASF_H

/*{{{  includes */

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "MuASF_dict.h"

/*}}}  */

/*{{{  typedefs */

typedef struct _MA_OptLayout *MA_OptLayout;
typedef struct _MA_Layout *MA_Layout;
typedef struct _MA_LexLayoutList *MA_LexLayoutList;
typedef struct _MA_TraversalStrategy *MA_TraversalStrategy;
typedef struct _MA_TraversalType *MA_TraversalType;
typedef struct _MA_TraversalContinuation *MA_TraversalContinuation;
typedef struct _MA_FunId *MA_FunId;
typedef struct _MA_VarId *MA_VarId;
typedef struct _MA_ModId *MA_ModId;
typedef struct _MA_Term *MA_Term;
typedef struct _MA_TermList *MA_TermList;
typedef struct _MA_SigArg *MA_SigArg;
typedef struct _MA_FuncDef *MA_FuncDef;
typedef struct _MA_Annotations *MA_Annotations;
typedef struct _MA_SigArgList *MA_SigArgList;
typedef struct _MA_FuncDefList *MA_FuncDefList;
typedef struct _MA_Rule *MA_Rule;
typedef struct _MA_RuleList *MA_RuleList;
typedef struct _MA_CondList *MA_CondList;
typedef struct _MA_Cond *MA_Cond;
typedef struct _MA_SignatureOpt *MA_SignatureOpt;
typedef struct _MA_RulesOpt *MA_RulesOpt;
typedef struct _MA_Module *MA_Module;
typedef struct _MA_TermArgs *MA_TermArgs;
typedef struct _MA_TermElems *MA_TermElems;
typedef struct _MA_SigArgArgs *MA_SigArgArgs;
typedef struct _MA_TermAttrs *MA_TermAttrs;
typedef struct _MA_FuncDefDefs *MA_FuncDefDefs;
typedef struct _MA_RuleRules *MA_RuleRules;
typedef struct _MA_CondConds *MA_CondConds;
typedef struct _MA_LexLayout *MA_LexLayout;
typedef struct _MA_LexStrChar *MA_LexStrChar;
typedef struct _MA_StrChar *MA_StrChar;
typedef struct _MA_LexStrCon *MA_LexStrCon;
typedef struct _MA_StrCon *MA_StrCon;
typedef struct _MA_LexStrCharChars *MA_LexStrCharChars;
typedef struct _MA_LexNatCon *MA_LexNatCon;
typedef struct _MA_NatCon *MA_NatCon;
typedef struct _MA_LexIdCon *MA_LexIdCon;
typedef struct _MA_IdCon *MA_IdCon;

/*}}}  */

void MA_initMuASFApi(void);

/*{{{  protect functions */

void MA_protectOptLayout(MA_OptLayout *arg);
void MA_protectLayout(MA_Layout *arg);
void MA_protectLexLayoutList(MA_LexLayoutList *arg);
void MA_protectTraversalStrategy(MA_TraversalStrategy *arg);
void MA_protectTraversalType(MA_TraversalType *arg);
void MA_protectTraversalContinuation(MA_TraversalContinuation *arg);
void MA_protectFunId(MA_FunId *arg);
void MA_protectVarId(MA_VarId *arg);
void MA_protectModId(MA_ModId *arg);
void MA_protectTerm(MA_Term *arg);
void MA_protectTermList(MA_TermList *arg);
void MA_protectSigArg(MA_SigArg *arg);
void MA_protectFuncDef(MA_FuncDef *arg);
void MA_protectAnnotations(MA_Annotations *arg);
void MA_protectSigArgList(MA_SigArgList *arg);
void MA_protectFuncDefList(MA_FuncDefList *arg);
void MA_protectRule(MA_Rule *arg);
void MA_protectRuleList(MA_RuleList *arg);
void MA_protectCondList(MA_CondList *arg);
void MA_protectCond(MA_Cond *arg);
void MA_protectSignatureOpt(MA_SignatureOpt *arg);
void MA_protectRulesOpt(MA_RulesOpt *arg);
void MA_protectModule(MA_Module *arg);
void MA_protectTermArgs(MA_TermArgs *arg);
void MA_protectTermElems(MA_TermElems *arg);
void MA_protectSigArgArgs(MA_SigArgArgs *arg);
void MA_protectTermAttrs(MA_TermAttrs *arg);
void MA_protectFuncDefDefs(MA_FuncDefDefs *arg);
void MA_protectRuleRules(MA_RuleRules *arg);
void MA_protectCondConds(MA_CondConds *arg);
void MA_protectLexLayout(MA_LexLayout *arg);
void MA_protectLexStrChar(MA_LexStrChar *arg);
void MA_protectStrChar(MA_StrChar *arg);
void MA_protectLexStrCon(MA_LexStrCon *arg);
void MA_protectStrCon(MA_StrCon *arg);
void MA_protectLexStrCharChars(MA_LexStrCharChars *arg);
void MA_protectLexNatCon(MA_LexNatCon *arg);
void MA_protectNatCon(MA_NatCon *arg);
void MA_protectLexIdCon(MA_LexIdCon *arg);
void MA_protectIdCon(MA_IdCon *arg);

/*}}}  */
/*{{{  term conversion functions */

MA_OptLayout MA_OptLayoutFromTerm(ATerm t);
ATerm MA_OptLayoutToTerm(MA_OptLayout arg);
MA_Layout MA_LayoutFromTerm(ATerm t);
ATerm MA_LayoutToTerm(MA_Layout arg);
MA_LexLayoutList MA_LexLayoutListFromTerm(ATerm t);
ATerm MA_LexLayoutListToTerm(MA_LexLayoutList arg);
MA_TraversalStrategy MA_TraversalStrategyFromTerm(ATerm t);
ATerm MA_TraversalStrategyToTerm(MA_TraversalStrategy arg);
MA_TraversalType MA_TraversalTypeFromTerm(ATerm t);
ATerm MA_TraversalTypeToTerm(MA_TraversalType arg);
MA_TraversalContinuation MA_TraversalContinuationFromTerm(ATerm t);
ATerm MA_TraversalContinuationToTerm(MA_TraversalContinuation arg);
MA_FunId MA_FunIdFromTerm(ATerm t);
ATerm MA_FunIdToTerm(MA_FunId arg);
MA_VarId MA_VarIdFromTerm(ATerm t);
ATerm MA_VarIdToTerm(MA_VarId arg);
MA_ModId MA_ModIdFromTerm(ATerm t);
ATerm MA_ModIdToTerm(MA_ModId arg);
MA_Term MA_TermFromTerm(ATerm t);
ATerm MA_TermToTerm(MA_Term arg);
MA_TermList MA_TermListFromTerm(ATerm t);
ATerm MA_TermListToTerm(MA_TermList arg);
MA_SigArg MA_SigArgFromTerm(ATerm t);
ATerm MA_SigArgToTerm(MA_SigArg arg);
MA_FuncDef MA_FuncDefFromTerm(ATerm t);
ATerm MA_FuncDefToTerm(MA_FuncDef arg);
MA_Annotations MA_AnnotationsFromTerm(ATerm t);
ATerm MA_AnnotationsToTerm(MA_Annotations arg);
MA_SigArgList MA_SigArgListFromTerm(ATerm t);
ATerm MA_SigArgListToTerm(MA_SigArgList arg);
MA_FuncDefList MA_FuncDefListFromTerm(ATerm t);
ATerm MA_FuncDefListToTerm(MA_FuncDefList arg);
MA_Rule MA_RuleFromTerm(ATerm t);
ATerm MA_RuleToTerm(MA_Rule arg);
MA_RuleList MA_RuleListFromTerm(ATerm t);
ATerm MA_RuleListToTerm(MA_RuleList arg);
MA_CondList MA_CondListFromTerm(ATerm t);
ATerm MA_CondListToTerm(MA_CondList arg);
MA_Cond MA_CondFromTerm(ATerm t);
ATerm MA_CondToTerm(MA_Cond arg);
MA_SignatureOpt MA_SignatureOptFromTerm(ATerm t);
ATerm MA_SignatureOptToTerm(MA_SignatureOpt arg);
MA_RulesOpt MA_RulesOptFromTerm(ATerm t);
ATerm MA_RulesOptToTerm(MA_RulesOpt arg);
MA_Module MA_ModuleFromTerm(ATerm t);
ATerm MA_ModuleToTerm(MA_Module arg);
MA_TermArgs MA_TermArgsFromTerm(ATerm t);
ATerm MA_TermArgsToTerm(MA_TermArgs arg);
MA_TermElems MA_TermElemsFromTerm(ATerm t);
ATerm MA_TermElemsToTerm(MA_TermElems arg);
MA_SigArgArgs MA_SigArgArgsFromTerm(ATerm t);
ATerm MA_SigArgArgsToTerm(MA_SigArgArgs arg);
MA_TermAttrs MA_TermAttrsFromTerm(ATerm t);
ATerm MA_TermAttrsToTerm(MA_TermAttrs arg);
MA_FuncDefDefs MA_FuncDefDefsFromTerm(ATerm t);
ATerm MA_FuncDefDefsToTerm(MA_FuncDefDefs arg);
MA_RuleRules MA_RuleRulesFromTerm(ATerm t);
ATerm MA_RuleRulesToTerm(MA_RuleRules arg);
MA_CondConds MA_CondCondsFromTerm(ATerm t);
ATerm MA_CondCondsToTerm(MA_CondConds arg);
MA_LexLayout MA_LexLayoutFromTerm(ATerm t);
ATerm MA_LexLayoutToTerm(MA_LexLayout arg);
MA_LexStrChar MA_LexStrCharFromTerm(ATerm t);
ATerm MA_LexStrCharToTerm(MA_LexStrChar arg);
MA_StrChar MA_StrCharFromTerm(ATerm t);
ATerm MA_StrCharToTerm(MA_StrChar arg);
MA_LexStrCon MA_LexStrConFromTerm(ATerm t);
ATerm MA_LexStrConToTerm(MA_LexStrCon arg);
MA_StrCon MA_StrConFromTerm(ATerm t);
ATerm MA_StrConToTerm(MA_StrCon arg);
MA_LexStrCharChars MA_LexStrCharCharsFromTerm(ATerm t);
ATerm MA_LexStrCharCharsToTerm(MA_LexStrCharChars arg);
MA_LexNatCon MA_LexNatConFromTerm(ATerm t);
ATerm MA_LexNatConToTerm(MA_LexNatCon arg);
MA_NatCon MA_NatConFromTerm(ATerm t);
ATerm MA_NatConToTerm(MA_NatCon arg);
MA_LexIdCon MA_LexIdConFromTerm(ATerm t);
ATerm MA_LexIdConToTerm(MA_LexIdCon arg);
MA_IdCon MA_IdConFromTerm(ATerm t);
ATerm MA_IdConToTerm(MA_IdCon arg);

/*}}}  */
/*{{{  list functions */

int MA_getLexLayoutListLength (MA_LexLayoutList arg);
MA_LexLayoutList MA_reverseLexLayoutList(MA_LexLayoutList arg);
MA_LexLayoutList MA_appendLexLayoutList(MA_LexLayoutList arg, MA_LexLayout elem);
MA_LexLayoutList MA_concatLexLayoutList(MA_LexLayoutList arg0, MA_LexLayoutList arg1);
MA_LexLayoutList MA_sliceLexLayoutList(MA_LexLayoutList arg, int start, int end);
MA_LexLayout MA_getLexLayoutListLexLayoutAt(MA_LexLayoutList arg, int index);
MA_LexLayoutList MA_replaceLexLayoutListLexLayoutAt(MA_LexLayoutList arg, MA_LexLayout elem, int index);
MA_LexLayoutList MA_makeLexLayoutList2(MA_LexLayout elem1, MA_LexLayout elem2);
MA_LexLayoutList MA_makeLexLayoutList3(MA_LexLayout elem1, MA_LexLayout elem2, MA_LexLayout elem3);
MA_LexLayoutList MA_makeLexLayoutList4(MA_LexLayout elem1, MA_LexLayout elem2, MA_LexLayout elem3, MA_LexLayout elem4);
MA_LexLayoutList MA_makeLexLayoutList5(MA_LexLayout elem1, MA_LexLayout elem2, MA_LexLayout elem3, MA_LexLayout elem4, MA_LexLayout elem5);
MA_LexLayoutList MA_makeLexLayoutList6(MA_LexLayout elem1, MA_LexLayout elem2, MA_LexLayout elem3, MA_LexLayout elem4, MA_LexLayout elem5, MA_LexLayout elem6);
int MA_getTermArgsLength (MA_TermArgs arg);
MA_TermArgs MA_reverseTermArgs(MA_TermArgs arg);
MA_TermArgs MA_appendTermArgs(MA_TermArgs arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term arg1);
MA_TermArgs MA_concatTermArgs(MA_TermArgs arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_TermArgs arg1);
MA_TermArgs MA_sliceTermArgs(MA_TermArgs arg, int start, int end);
MA_Term MA_getTermArgsTermAt(MA_TermArgs arg, int index);
MA_TermArgs MA_replaceTermArgsTermAt(MA_TermArgs arg, MA_Term elem, int index);
MA_TermArgs MA_makeTermArgs2(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2);
MA_TermArgs MA_makeTermArgs3(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2, MA_Term elem3);
MA_TermArgs MA_makeTermArgs4(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2, MA_Term elem3, MA_Term elem4);
MA_TermArgs MA_makeTermArgs5(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2, MA_Term elem3, MA_Term elem4, MA_Term elem5);
MA_TermArgs MA_makeTermArgs6(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2, MA_Term elem3, MA_Term elem4, MA_Term elem5, MA_Term elem6);
int MA_getTermElemsLength (MA_TermElems arg);
MA_TermElems MA_reverseTermElems(MA_TermElems arg);
MA_TermElems MA_appendTermElems(MA_TermElems arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term arg1);
MA_TermElems MA_concatTermElems(MA_TermElems arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_TermElems arg1);
MA_TermElems MA_sliceTermElems(MA_TermElems arg, int start, int end);
MA_Term MA_getTermElemsTermAt(MA_TermElems arg, int index);
MA_TermElems MA_replaceTermElemsTermAt(MA_TermElems arg, MA_Term elem, int index);
MA_TermElems MA_makeTermElems2(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2);
MA_TermElems MA_makeTermElems3(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2, MA_Term elem3);
MA_TermElems MA_makeTermElems4(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2, MA_Term elem3, MA_Term elem4);
MA_TermElems MA_makeTermElems5(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2, MA_Term elem3, MA_Term elem4, MA_Term elem5);
MA_TermElems MA_makeTermElems6(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2, MA_Term elem3, MA_Term elem4, MA_Term elem5, MA_Term elem6);
int MA_getSigArgArgsLength (MA_SigArgArgs arg);
MA_SigArgArgs MA_reverseSigArgArgs(MA_SigArgArgs arg);
MA_SigArgArgs MA_appendSigArgArgs(MA_SigArgArgs arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_SigArg arg1);
MA_SigArgArgs MA_concatSigArgArgs(MA_SigArgArgs arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_SigArgArgs arg1);
MA_SigArgArgs MA_sliceSigArgArgs(MA_SigArgArgs arg, int start, int end);
MA_SigArg MA_getSigArgArgsSigArgAt(MA_SigArgArgs arg, int index);
MA_SigArgArgs MA_replaceSigArgArgsSigArgAt(MA_SigArgArgs arg, MA_SigArg elem, int index);
MA_SigArgArgs MA_makeSigArgArgs2(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_SigArg elem1, MA_SigArg elem2);
MA_SigArgArgs MA_makeSigArgArgs3(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_SigArg elem1, MA_SigArg elem2, MA_SigArg elem3);
MA_SigArgArgs MA_makeSigArgArgs4(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_SigArg elem1, MA_SigArg elem2, MA_SigArg elem3, MA_SigArg elem4);
MA_SigArgArgs MA_makeSigArgArgs5(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_SigArg elem1, MA_SigArg elem2, MA_SigArg elem3, MA_SigArg elem4, MA_SigArg elem5);
MA_SigArgArgs MA_makeSigArgArgs6(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_SigArg elem1, MA_SigArg elem2, MA_SigArg elem3, MA_SigArg elem4, MA_SigArg elem5, MA_SigArg elem6);
int MA_getTermAttrsLength (MA_TermAttrs arg);
MA_TermAttrs MA_reverseTermAttrs(MA_TermAttrs arg);
MA_TermAttrs MA_appendTermAttrs(MA_TermAttrs arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term arg1);
MA_TermAttrs MA_concatTermAttrs(MA_TermAttrs arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_TermAttrs arg1);
MA_TermAttrs MA_sliceTermAttrs(MA_TermAttrs arg, int start, int end);
MA_Term MA_getTermAttrsTermAt(MA_TermAttrs arg, int index);
MA_TermAttrs MA_replaceTermAttrsTermAt(MA_TermAttrs arg, MA_Term elem, int index);
MA_TermAttrs MA_makeTermAttrs2(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2);
MA_TermAttrs MA_makeTermAttrs3(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2, MA_Term elem3);
MA_TermAttrs MA_makeTermAttrs4(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2, MA_Term elem3, MA_Term elem4);
MA_TermAttrs MA_makeTermAttrs5(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2, MA_Term elem3, MA_Term elem4, MA_Term elem5);
MA_TermAttrs MA_makeTermAttrs6(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2, MA_Term elem3, MA_Term elem4, MA_Term elem5, MA_Term elem6);
int MA_getFuncDefDefsLength (MA_FuncDefDefs arg);
MA_FuncDefDefs MA_reverseFuncDefDefs(MA_FuncDefDefs arg);
MA_FuncDefDefs MA_appendFuncDefDefs(MA_FuncDefDefs arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_FuncDef arg1);
MA_FuncDefDefs MA_concatFuncDefDefs(MA_FuncDefDefs arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_FuncDefDefs arg1);
MA_FuncDefDefs MA_sliceFuncDefDefs(MA_FuncDefDefs arg, int start, int end);
MA_FuncDef MA_getFuncDefDefsFuncDefAt(MA_FuncDefDefs arg, int index);
MA_FuncDefDefs MA_replaceFuncDefDefsFuncDefAt(MA_FuncDefDefs arg, MA_FuncDef elem, int index);
MA_FuncDefDefs MA_makeFuncDefDefs2(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_FuncDef elem1, MA_FuncDef elem2);
MA_FuncDefDefs MA_makeFuncDefDefs3(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_FuncDef elem1, MA_FuncDef elem2, MA_FuncDef elem3);
MA_FuncDefDefs MA_makeFuncDefDefs4(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_FuncDef elem1, MA_FuncDef elem2, MA_FuncDef elem3, MA_FuncDef elem4);
MA_FuncDefDefs MA_makeFuncDefDefs5(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_FuncDef elem1, MA_FuncDef elem2, MA_FuncDef elem3, MA_FuncDef elem4, MA_FuncDef elem5);
MA_FuncDefDefs MA_makeFuncDefDefs6(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_FuncDef elem1, MA_FuncDef elem2, MA_FuncDef elem3, MA_FuncDef elem4, MA_FuncDef elem5, MA_FuncDef elem6);
int MA_getRuleRulesLength (MA_RuleRules arg);
MA_RuleRules MA_reverseRuleRules(MA_RuleRules arg);
MA_RuleRules MA_appendRuleRules(MA_RuleRules arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Rule arg1);
MA_RuleRules MA_concatRuleRules(MA_RuleRules arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_RuleRules arg1);
MA_RuleRules MA_sliceRuleRules(MA_RuleRules arg, int start, int end);
MA_Rule MA_getRuleRulesRuleAt(MA_RuleRules arg, int index);
MA_RuleRules MA_replaceRuleRulesRuleAt(MA_RuleRules arg, MA_Rule elem, int index);
MA_RuleRules MA_makeRuleRules2(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Rule elem1, MA_Rule elem2);
MA_RuleRules MA_makeRuleRules3(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Rule elem1, MA_Rule elem2, MA_Rule elem3);
MA_RuleRules MA_makeRuleRules4(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Rule elem1, MA_Rule elem2, MA_Rule elem3, MA_Rule elem4);
MA_RuleRules MA_makeRuleRules5(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Rule elem1, MA_Rule elem2, MA_Rule elem3, MA_Rule elem4, MA_Rule elem5);
MA_RuleRules MA_makeRuleRules6(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Rule elem1, MA_Rule elem2, MA_Rule elem3, MA_Rule elem4, MA_Rule elem5, MA_Rule elem6);
int MA_getCondCondsLength (MA_CondConds arg);
MA_CondConds MA_reverseCondConds(MA_CondConds arg);
MA_CondConds MA_appendCondConds(MA_CondConds arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Cond arg1);
MA_CondConds MA_concatCondConds(MA_CondConds arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_CondConds arg1);
MA_CondConds MA_sliceCondConds(MA_CondConds arg, int start, int end);
MA_Cond MA_getCondCondsCondAt(MA_CondConds arg, int index);
MA_CondConds MA_replaceCondCondsCondAt(MA_CondConds arg, MA_Cond elem, int index);
MA_CondConds MA_makeCondConds2(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Cond elem1, MA_Cond elem2);
MA_CondConds MA_makeCondConds3(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Cond elem1, MA_Cond elem2, MA_Cond elem3);
MA_CondConds MA_makeCondConds4(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Cond elem1, MA_Cond elem2, MA_Cond elem3, MA_Cond elem4);
MA_CondConds MA_makeCondConds5(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Cond elem1, MA_Cond elem2, MA_Cond elem3, MA_Cond elem4, MA_Cond elem5);
MA_CondConds MA_makeCondConds6(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Cond elem1, MA_Cond elem2, MA_Cond elem3, MA_Cond elem4, MA_Cond elem5, MA_Cond elem6);
int MA_getLexStrCharCharsLength (MA_LexStrCharChars arg);
MA_LexStrCharChars MA_reverseLexStrCharChars(MA_LexStrCharChars arg);
MA_LexStrCharChars MA_appendLexStrCharChars(MA_LexStrCharChars arg, MA_LexStrChar elem);
MA_LexStrCharChars MA_concatLexStrCharChars(MA_LexStrCharChars arg0, MA_LexStrCharChars arg1);
MA_LexStrCharChars MA_sliceLexStrCharChars(MA_LexStrCharChars arg, int start, int end);
MA_LexStrChar MA_getLexStrCharCharsLexStrCharAt(MA_LexStrCharChars arg, int index);
MA_LexStrCharChars MA_replaceLexStrCharCharsLexStrCharAt(MA_LexStrCharChars arg, MA_LexStrChar elem, int index);
MA_LexStrCharChars MA_makeLexStrCharChars2(MA_LexStrChar elem1, MA_LexStrChar elem2);
MA_LexStrCharChars MA_makeLexStrCharChars3(MA_LexStrChar elem1, MA_LexStrChar elem2, MA_LexStrChar elem3);
MA_LexStrCharChars MA_makeLexStrCharChars4(MA_LexStrChar elem1, MA_LexStrChar elem2, MA_LexStrChar elem3, MA_LexStrChar elem4);
MA_LexStrCharChars MA_makeLexStrCharChars5(MA_LexStrChar elem1, MA_LexStrChar elem2, MA_LexStrChar elem3, MA_LexStrChar elem4, MA_LexStrChar elem5);
MA_LexStrCharChars MA_makeLexStrCharChars6(MA_LexStrChar elem1, MA_LexStrChar elem2, MA_LexStrChar elem3, MA_LexStrChar elem4, MA_LexStrChar elem5, MA_LexStrChar elem6);

/*}}}  */
/*{{{  constructors */

MA_OptLayout MA_makeOptLayoutAbsent(void);
MA_OptLayout MA_makeOptLayoutPresent(MA_Layout layout);
MA_Layout MA_makeLayoutLexToCf(MA_LexLayoutList list);
MA_LexLayoutList MA_makeLexLayoutListEmpty(void);
MA_LexLayoutList MA_makeLexLayoutListSingle(MA_LexLayout head);
MA_LexLayoutList MA_makeLexLayoutListMany(MA_LexLayout head, MA_LexLayoutList tail);
MA_TraversalStrategy MA_makeTraversalStrategyBottomUp(void);
MA_TraversalStrategy MA_makeTraversalStrategyTopDown(void);
MA_TraversalType MA_makeTraversalTypeTrafo(void);
MA_TraversalType MA_makeTraversalTypeAccu(void);
MA_TraversalType MA_makeTraversalTypeAccutrafo(void);
MA_TraversalContinuation MA_makeTraversalContinuationBreak(void);
MA_TraversalContinuation MA_makeTraversalContinuationContinue(void);
MA_FunId MA_makeFunIdCharacter(MA_NatCon NatCon);
MA_FunId MA_makeFunIdUnquoted(MA_IdCon IdCon);
MA_FunId MA_makeFunIdQuoted(MA_StrCon StrCon);
MA_FunId MA_makeFunIdReturnsList(MA_OptLayout wsAfterBracketOpen, MA_FunId FunId, MA_OptLayout wsAfterFunId);
MA_FunId MA_makeFunIdList(MA_OptLayout wsAfterBraceOpen, MA_FunId FunId, MA_OptLayout wsAfterFunId);
MA_FunId MA_makeFunIdIgnored(MA_OptLayout wsAfterIGNORE, MA_OptLayout wsAfterBracketOpen, MA_FunId FunId, MA_OptLayout wsAfterFunId);
MA_FunId MA_makeFunIdTranslate(MA_OptLayout wsAfterTRANSLATE, MA_OptLayout wsAfterBracketOpen, MA_FunId FunId, MA_OptLayout wsAfterFunId);
MA_FunId MA_makeFunIdTraversal(MA_OptLayout wsAfterBar, MA_FunId FunId, MA_OptLayout wsAfterFunId, MA_TraversalType TraversalType, MA_OptLayout wsAfterTraversalType, MA_TraversalStrategy TraversalStrategy, MA_OptLayout wsAfterTraversalStrategy, MA_TraversalContinuation TraversalContinuation, MA_OptLayout wsAfterTraversalContinuation);
MA_FunId MA_makeFunIdConcat(MA_FunId lhs, MA_OptLayout wsAfterLhs, MA_OptLayout wsAfterPlusPlus, MA_FunId rhs);
MA_VarId MA_makeVarIdNormal(MA_OptLayout wsAfterDollar, MA_FunId FunId);
MA_VarId MA_makeVarIdPlus(MA_OptLayout wsAfterDollarPlus, MA_FunId FunId);
MA_VarId MA_makeVarIdStar(MA_OptLayout wsAfterDollarStar, MA_FunId FunId);
MA_ModId MA_makeModIdDefault(MA_IdCon IdCon);
MA_Term MA_makeTermVar(MA_VarId VarId);
MA_Term MA_makeTermConstant(MA_FunId FunId);
MA_Term MA_makeTermFunc(MA_FunId FunId, MA_OptLayout wsAfterFunId, MA_OptLayout wsAfterParenOpen, MA_TermArgs args, MA_OptLayout wsAfterArgs);
MA_Term MA_makeTermList(MA_OptLayout wsAfterBracketOpen, MA_TermList TermList, MA_OptLayout wsAfterTermList);
MA_Term MA_makeTermTyped(MA_Term Term, MA_OptLayout wsAfterTerm, MA_OptLayout wsAfterColon, MA_Term type);
MA_TermList MA_makeTermListDefault(MA_TermElems elems);
MA_SigArg MA_makeSigArgNormal(void);
MA_SigArg MA_makeSigArgStar(MA_OptLayout wsAfterUnderscore);
MA_SigArg MA_makeSigArgPlus(MA_OptLayout wsAfterUnderscore);
MA_FuncDef MA_makeFuncDefConstantNoAnnos(MA_FunId FunId);
MA_FuncDef MA_makeFuncDefConstantWithAnnos(MA_FunId FunId, MA_OptLayout wsAfterFunId, MA_Annotations Annotations);
MA_FuncDef MA_makeFuncDefFuncNoAnnos(MA_FunId FunId, MA_OptLayout wsAfterFunId, MA_OptLayout wsAfterParenOpen, MA_SigArgArgs args, MA_OptLayout wsAfterArgs);
MA_FuncDef MA_makeFuncDefFuncWithAnnos(MA_FunId FunId, MA_OptLayout wsAfterFunId, MA_OptLayout wsAfterParenOpen, MA_SigArgArgs args, MA_OptLayout wsAfterArgs, MA_OptLayout wsAfterParenClose, MA_Annotations Annotations);
MA_Annotations MA_makeAnnotationsDefault(MA_OptLayout wsAfterBraceOpen, MA_TermAttrs attrs, MA_OptLayout wsAfterAttrs);
MA_SigArgList MA_makeSigArgListDefault(MA_SigArgArgs args);
MA_FuncDefList MA_makeFuncDefListDefault(MA_FuncDefDefs defs);
MA_Rule MA_makeRuleNoConds(MA_Term lhs, MA_OptLayout wsAfterLhs, MA_OptLayout wsAfterIs, MA_Term rhs);
MA_Rule MA_makeRuleDefaultNoConds(MA_OptLayout wsAfterDefaultColon, MA_Term lhs, MA_OptLayout wsAfterLhs, MA_OptLayout wsAfterIs, MA_Term rhs);
MA_Rule MA_makeRuleWithConds(MA_CondList conds, MA_OptLayout wsAfterConds, MA_OptLayout wsAfterEqualsEqualsGreaterThan, MA_Term lhs, MA_OptLayout wsAfterLhs, MA_OptLayout wsAfterIs, MA_Term rhs);
MA_Rule MA_makeRuleDefaultWithConds(MA_OptLayout wsAfterDefaultColon, MA_CondList conds, MA_OptLayout wsAfterConds, MA_OptLayout wsAfterEqualsEqualsGreaterThan, MA_Term lhs, MA_OptLayout wsAfterLhs, MA_OptLayout wsAfterIs, MA_Term rhs);
MA_RuleList MA_makeRuleListDefault(MA_RuleRules rules);
MA_CondList MA_makeCondListDefault(MA_CondConds conds);
MA_Cond MA_makeCondAssign(MA_Term lhs, MA_OptLayout wsAfterLhs, MA_OptLayout wsAfterBecomes, MA_Term rhs);
MA_Cond MA_makeCondNoAssign(MA_Term lhs, MA_OptLayout wsAfterLhs, MA_OptLayout wsAfterNotBecomes, MA_Term rhs);
MA_Cond MA_makeCondEqual(MA_Term lhs, MA_OptLayout wsAfterLhs, MA_OptLayout wsAfterEquals, MA_Term rhs);
MA_Cond MA_makeCondUnequal(MA_Term lhs, MA_OptLayout wsAfterLhs, MA_OptLayout wsAfterNotEquals, MA_Term rhs);
MA_SignatureOpt MA_makeSignatureOptAbsent(void);
MA_SignatureOpt MA_makeSignatureOptPresent(MA_OptLayout wsAfterSignature, MA_FuncDefList FuncDefList);
MA_RulesOpt MA_makeRulesOptAbsent(void);
MA_RulesOpt MA_makeRulesOptPresent(MA_OptLayout wsAfterRules, MA_RuleList RuleList);
MA_Module MA_makeModuleModule(MA_OptLayout wsAfterModule, MA_ModId ModId, MA_OptLayout wsAfterModId, MA_SignatureOpt SignatureOpt, MA_OptLayout wsAfterSignatureOpt, MA_RulesOpt RulesOpt);
MA_TermArgs MA_makeTermArgsEmpty(void);
MA_TermArgs MA_makeTermArgsSingle(MA_Term head);
MA_TermArgs MA_makeTermArgsMany(MA_Term head, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_TermArgs tail);
MA_TermElems MA_makeTermElemsEmpty(void);
MA_TermElems MA_makeTermElemsSingle(MA_Term head);
MA_TermElems MA_makeTermElemsMany(MA_Term head, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_TermElems tail);
MA_SigArgArgs MA_makeSigArgArgsEmpty(void);
MA_SigArgArgs MA_makeSigArgArgsSingle(MA_SigArg head);
MA_SigArgArgs MA_makeSigArgArgsMany(MA_SigArg head, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_SigArgArgs tail);
MA_TermAttrs MA_makeTermAttrsEmpty(void);
MA_TermAttrs MA_makeTermAttrsSingle(MA_Term head);
MA_TermAttrs MA_makeTermAttrsMany(MA_Term head, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_TermAttrs tail);
MA_FuncDefDefs MA_makeFuncDefDefsEmpty(void);
MA_FuncDefDefs MA_makeFuncDefDefsSingle(MA_FuncDef head);
MA_FuncDefDefs MA_makeFuncDefDefsMany(MA_FuncDef head, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_FuncDefDefs tail);
MA_RuleRules MA_makeRuleRulesEmpty(void);
MA_RuleRules MA_makeRuleRulesSingle(MA_Rule head);
MA_RuleRules MA_makeRuleRulesMany(MA_Rule head, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_RuleRules tail);
MA_CondConds MA_makeCondCondsEmpty(void);
MA_CondConds MA_makeCondCondsSingle(MA_Cond head);
MA_CondConds MA_makeCondCondsMany(MA_Cond head, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_CondConds tail);
MA_LexLayout MA_makeLexLayoutWhitespace(char ch);
MA_LexStrChar MA_makeLexStrCharNewline(void);
MA_LexStrChar MA_makeLexStrCharTab(void);
MA_LexStrChar MA_makeLexStrCharQuote(void);
MA_LexStrChar MA_makeLexStrCharBackslash(void);
MA_LexStrChar MA_makeLexStrCharDecimal(char a, char b, char c);
MA_LexStrChar MA_makeLexStrCharNormal(char ch);
MA_StrChar MA_makeStrCharLexToCf(MA_LexStrChar StrChar);
MA_LexStrCon MA_makeLexStrConDefault(MA_LexStrCharChars chars);
MA_StrCon MA_makeStrConLexToCf(MA_LexStrCon StrCon);
MA_LexStrCharChars MA_makeLexStrCharCharsEmpty(void);
MA_LexStrCharChars MA_makeLexStrCharCharsSingle(MA_LexStrChar head);
MA_LexStrCharChars MA_makeLexStrCharCharsMany(MA_LexStrChar head, MA_LexStrCharChars tail);
MA_LexNatCon MA_makeLexNatConDigits(const char* list);
MA_NatCon MA_makeNatConLexToCf(MA_LexNatCon NatCon);
MA_LexIdCon MA_makeLexIdConDefault(char head, const char* tail);
MA_IdCon MA_makeIdConLexToCf(MA_LexIdCon IdCon);

/*}}}  */
/*{{{  equality functions */

ATbool MA_isEqualOptLayout(MA_OptLayout arg0, MA_OptLayout arg1);
ATbool MA_isEqualLayout(MA_Layout arg0, MA_Layout arg1);
ATbool MA_isEqualLexLayoutList(MA_LexLayoutList arg0, MA_LexLayoutList arg1);
ATbool MA_isEqualTraversalStrategy(MA_TraversalStrategy arg0, MA_TraversalStrategy arg1);
ATbool MA_isEqualTraversalType(MA_TraversalType arg0, MA_TraversalType arg1);
ATbool MA_isEqualTraversalContinuation(MA_TraversalContinuation arg0, MA_TraversalContinuation arg1);
ATbool MA_isEqualFunId(MA_FunId arg0, MA_FunId arg1);
ATbool MA_isEqualVarId(MA_VarId arg0, MA_VarId arg1);
ATbool MA_isEqualModId(MA_ModId arg0, MA_ModId arg1);
ATbool MA_isEqualTerm(MA_Term arg0, MA_Term arg1);
ATbool MA_isEqualTermList(MA_TermList arg0, MA_TermList arg1);
ATbool MA_isEqualSigArg(MA_SigArg arg0, MA_SigArg arg1);
ATbool MA_isEqualFuncDef(MA_FuncDef arg0, MA_FuncDef arg1);
ATbool MA_isEqualAnnotations(MA_Annotations arg0, MA_Annotations arg1);
ATbool MA_isEqualSigArgList(MA_SigArgList arg0, MA_SigArgList arg1);
ATbool MA_isEqualFuncDefList(MA_FuncDefList arg0, MA_FuncDefList arg1);
ATbool MA_isEqualRule(MA_Rule arg0, MA_Rule arg1);
ATbool MA_isEqualRuleList(MA_RuleList arg0, MA_RuleList arg1);
ATbool MA_isEqualCondList(MA_CondList arg0, MA_CondList arg1);
ATbool MA_isEqualCond(MA_Cond arg0, MA_Cond arg1);
ATbool MA_isEqualSignatureOpt(MA_SignatureOpt arg0, MA_SignatureOpt arg1);
ATbool MA_isEqualRulesOpt(MA_RulesOpt arg0, MA_RulesOpt arg1);
ATbool MA_isEqualModule(MA_Module arg0, MA_Module arg1);
ATbool MA_isEqualTermArgs(MA_TermArgs arg0, MA_TermArgs arg1);
ATbool MA_isEqualTermElems(MA_TermElems arg0, MA_TermElems arg1);
ATbool MA_isEqualSigArgArgs(MA_SigArgArgs arg0, MA_SigArgArgs arg1);
ATbool MA_isEqualTermAttrs(MA_TermAttrs arg0, MA_TermAttrs arg1);
ATbool MA_isEqualFuncDefDefs(MA_FuncDefDefs arg0, MA_FuncDefDefs arg1);
ATbool MA_isEqualRuleRules(MA_RuleRules arg0, MA_RuleRules arg1);
ATbool MA_isEqualCondConds(MA_CondConds arg0, MA_CondConds arg1);
ATbool MA_isEqualLexLayout(MA_LexLayout arg0, MA_LexLayout arg1);
ATbool MA_isEqualLexStrChar(MA_LexStrChar arg0, MA_LexStrChar arg1);
ATbool MA_isEqualStrChar(MA_StrChar arg0, MA_StrChar arg1);
ATbool MA_isEqualLexStrCon(MA_LexStrCon arg0, MA_LexStrCon arg1);
ATbool MA_isEqualStrCon(MA_StrCon arg0, MA_StrCon arg1);
ATbool MA_isEqualLexStrCharChars(MA_LexStrCharChars arg0, MA_LexStrCharChars arg1);
ATbool MA_isEqualLexNatCon(MA_LexNatCon arg0, MA_LexNatCon arg1);
ATbool MA_isEqualNatCon(MA_NatCon arg0, MA_NatCon arg1);
ATbool MA_isEqualLexIdCon(MA_LexIdCon arg0, MA_LexIdCon arg1);
ATbool MA_isEqualIdCon(MA_IdCon arg0, MA_IdCon arg1);

/*}}}  */
/*{{{  MA_OptLayout accessors */

ATbool MA_isValidOptLayout(MA_OptLayout arg);
inline ATbool MA_isOptLayoutAbsent(MA_OptLayout arg);
inline ATbool MA_isOptLayoutPresent(MA_OptLayout arg);
ATbool MA_hasOptLayoutLayout(MA_OptLayout arg);
MA_Layout MA_getOptLayoutLayout(MA_OptLayout arg);
MA_OptLayout MA_setOptLayoutLayout(MA_OptLayout arg, MA_Layout layout);

/*}}}  */
/*{{{  MA_Layout accessors */

ATbool MA_isValidLayout(MA_Layout arg);
inline ATbool MA_isLayoutLexToCf(MA_Layout arg);
ATbool MA_hasLayoutList(MA_Layout arg);
MA_LexLayoutList MA_getLayoutList(MA_Layout arg);
MA_Layout MA_setLayoutList(MA_Layout arg, MA_LexLayoutList list);

/*}}}  */
/*{{{  MA_LexLayoutList accessors */

ATbool MA_isValidLexLayoutList(MA_LexLayoutList arg);
inline ATbool MA_isLexLayoutListEmpty(MA_LexLayoutList arg);
inline ATbool MA_isLexLayoutListSingle(MA_LexLayoutList arg);
inline ATbool MA_isLexLayoutListMany(MA_LexLayoutList arg);
ATbool MA_hasLexLayoutListHead(MA_LexLayoutList arg);
ATbool MA_hasLexLayoutListTail(MA_LexLayoutList arg);
MA_LexLayout MA_getLexLayoutListHead(MA_LexLayoutList arg);
MA_LexLayoutList MA_getLexLayoutListTail(MA_LexLayoutList arg);
MA_LexLayoutList MA_setLexLayoutListHead(MA_LexLayoutList arg, MA_LexLayout head);
MA_LexLayoutList MA_setLexLayoutListTail(MA_LexLayoutList arg, MA_LexLayoutList tail);

/*}}}  */
/*{{{  MA_TraversalStrategy accessors */

ATbool MA_isValidTraversalStrategy(MA_TraversalStrategy arg);
inline ATbool MA_isTraversalStrategyBottomUp(MA_TraversalStrategy arg);
inline ATbool MA_isTraversalStrategyTopDown(MA_TraversalStrategy arg);

/*}}}  */
/*{{{  MA_TraversalType accessors */

ATbool MA_isValidTraversalType(MA_TraversalType arg);
inline ATbool MA_isTraversalTypeTrafo(MA_TraversalType arg);
inline ATbool MA_isTraversalTypeAccu(MA_TraversalType arg);
inline ATbool MA_isTraversalTypeAccutrafo(MA_TraversalType arg);

/*}}}  */
/*{{{  MA_TraversalContinuation accessors */

ATbool MA_isValidTraversalContinuation(MA_TraversalContinuation arg);
inline ATbool MA_isTraversalContinuationBreak(MA_TraversalContinuation arg);
inline ATbool MA_isTraversalContinuationContinue(MA_TraversalContinuation arg);

/*}}}  */
/*{{{  MA_FunId accessors */

ATbool MA_isValidFunId(MA_FunId arg);
inline ATbool MA_isFunIdCharacter(MA_FunId arg);
inline ATbool MA_isFunIdUnquoted(MA_FunId arg);
inline ATbool MA_isFunIdQuoted(MA_FunId arg);
inline ATbool MA_isFunIdReturnsList(MA_FunId arg);
inline ATbool MA_isFunIdList(MA_FunId arg);
inline ATbool MA_isFunIdIgnored(MA_FunId arg);
inline ATbool MA_isFunIdTranslate(MA_FunId arg);
inline ATbool MA_isFunIdTraversal(MA_FunId arg);
inline ATbool MA_isFunIdConcat(MA_FunId arg);
ATbool MA_hasFunIdNatCon(MA_FunId arg);
ATbool MA_hasFunIdIdCon(MA_FunId arg);
ATbool MA_hasFunIdStrCon(MA_FunId arg);
ATbool MA_hasFunIdWsAfterBracketOpen(MA_FunId arg);
ATbool MA_hasFunIdFunId(MA_FunId arg);
ATbool MA_hasFunIdWsAfterFunId(MA_FunId arg);
ATbool MA_hasFunIdWsAfterBraceOpen(MA_FunId arg);
ATbool MA_hasFunIdWsAfterIGNORE(MA_FunId arg);
ATbool MA_hasFunIdWsAfterTRANSLATE(MA_FunId arg);
ATbool MA_hasFunIdWsAfterBar(MA_FunId arg);
ATbool MA_hasFunIdTraversalType(MA_FunId arg);
ATbool MA_hasFunIdWsAfterTraversalType(MA_FunId arg);
ATbool MA_hasFunIdTraversalStrategy(MA_FunId arg);
ATbool MA_hasFunIdWsAfterTraversalStrategy(MA_FunId arg);
ATbool MA_hasFunIdTraversalContinuation(MA_FunId arg);
ATbool MA_hasFunIdWsAfterTraversalContinuation(MA_FunId arg);
ATbool MA_hasFunIdLhs(MA_FunId arg);
ATbool MA_hasFunIdWsAfterLhs(MA_FunId arg);
ATbool MA_hasFunIdWsAfterPlusPlus(MA_FunId arg);
ATbool MA_hasFunIdRhs(MA_FunId arg);
MA_NatCon MA_getFunIdNatCon(MA_FunId arg);
MA_IdCon MA_getFunIdIdCon(MA_FunId arg);
MA_StrCon MA_getFunIdStrCon(MA_FunId arg);
MA_OptLayout MA_getFunIdWsAfterBracketOpen(MA_FunId arg);
MA_FunId MA_getFunIdFunId(MA_FunId arg);
MA_OptLayout MA_getFunIdWsAfterFunId(MA_FunId arg);
MA_OptLayout MA_getFunIdWsAfterBraceOpen(MA_FunId arg);
MA_OptLayout MA_getFunIdWsAfterIGNORE(MA_FunId arg);
MA_OptLayout MA_getFunIdWsAfterTRANSLATE(MA_FunId arg);
MA_OptLayout MA_getFunIdWsAfterBar(MA_FunId arg);
MA_TraversalType MA_getFunIdTraversalType(MA_FunId arg);
MA_OptLayout MA_getFunIdWsAfterTraversalType(MA_FunId arg);
MA_TraversalStrategy MA_getFunIdTraversalStrategy(MA_FunId arg);
MA_OptLayout MA_getFunIdWsAfterTraversalStrategy(MA_FunId arg);
MA_TraversalContinuation MA_getFunIdTraversalContinuation(MA_FunId arg);
MA_OptLayout MA_getFunIdWsAfterTraversalContinuation(MA_FunId arg);
MA_FunId MA_getFunIdLhs(MA_FunId arg);
MA_OptLayout MA_getFunIdWsAfterLhs(MA_FunId arg);
MA_OptLayout MA_getFunIdWsAfterPlusPlus(MA_FunId arg);
MA_FunId MA_getFunIdRhs(MA_FunId arg);
MA_FunId MA_setFunIdNatCon(MA_FunId arg, MA_NatCon NatCon);
MA_FunId MA_setFunIdIdCon(MA_FunId arg, MA_IdCon IdCon);
MA_FunId MA_setFunIdStrCon(MA_FunId arg, MA_StrCon StrCon);
MA_FunId MA_setFunIdWsAfterBracketOpen(MA_FunId arg, MA_OptLayout wsAfterBracketOpen);
MA_FunId MA_setFunIdFunId(MA_FunId arg, MA_FunId FunId);
MA_FunId MA_setFunIdWsAfterFunId(MA_FunId arg, MA_OptLayout wsAfterFunId);
MA_FunId MA_setFunIdWsAfterBraceOpen(MA_FunId arg, MA_OptLayout wsAfterBraceOpen);
MA_FunId MA_setFunIdWsAfterIGNORE(MA_FunId arg, MA_OptLayout wsAfterIGNORE);
MA_FunId MA_setFunIdWsAfterTRANSLATE(MA_FunId arg, MA_OptLayout wsAfterTRANSLATE);
MA_FunId MA_setFunIdWsAfterBar(MA_FunId arg, MA_OptLayout wsAfterBar);
MA_FunId MA_setFunIdTraversalType(MA_FunId arg, MA_TraversalType TraversalType);
MA_FunId MA_setFunIdWsAfterTraversalType(MA_FunId arg, MA_OptLayout wsAfterTraversalType);
MA_FunId MA_setFunIdTraversalStrategy(MA_FunId arg, MA_TraversalStrategy TraversalStrategy);
MA_FunId MA_setFunIdWsAfterTraversalStrategy(MA_FunId arg, MA_OptLayout wsAfterTraversalStrategy);
MA_FunId MA_setFunIdTraversalContinuation(MA_FunId arg, MA_TraversalContinuation TraversalContinuation);
MA_FunId MA_setFunIdWsAfterTraversalContinuation(MA_FunId arg, MA_OptLayout wsAfterTraversalContinuation);
MA_FunId MA_setFunIdLhs(MA_FunId arg, MA_FunId lhs);
MA_FunId MA_setFunIdWsAfterLhs(MA_FunId arg, MA_OptLayout wsAfterLhs);
MA_FunId MA_setFunIdWsAfterPlusPlus(MA_FunId arg, MA_OptLayout wsAfterPlusPlus);
MA_FunId MA_setFunIdRhs(MA_FunId arg, MA_FunId rhs);

/*}}}  */
/*{{{  MA_VarId accessors */

ATbool MA_isValidVarId(MA_VarId arg);
inline ATbool MA_isVarIdNormal(MA_VarId arg);
inline ATbool MA_isVarIdPlus(MA_VarId arg);
inline ATbool MA_isVarIdStar(MA_VarId arg);
ATbool MA_hasVarIdWsAfterDollar(MA_VarId arg);
ATbool MA_hasVarIdFunId(MA_VarId arg);
ATbool MA_hasVarIdWsAfterDollarPlus(MA_VarId arg);
ATbool MA_hasVarIdWsAfterDollarStar(MA_VarId arg);
MA_OptLayout MA_getVarIdWsAfterDollar(MA_VarId arg);
MA_FunId MA_getVarIdFunId(MA_VarId arg);
MA_OptLayout MA_getVarIdWsAfterDollarPlus(MA_VarId arg);
MA_OptLayout MA_getVarIdWsAfterDollarStar(MA_VarId arg);
MA_VarId MA_setVarIdWsAfterDollar(MA_VarId arg, MA_OptLayout wsAfterDollar);
MA_VarId MA_setVarIdFunId(MA_VarId arg, MA_FunId FunId);
MA_VarId MA_setVarIdWsAfterDollarPlus(MA_VarId arg, MA_OptLayout wsAfterDollarPlus);
MA_VarId MA_setVarIdWsAfterDollarStar(MA_VarId arg, MA_OptLayout wsAfterDollarStar);

/*}}}  */
/*{{{  MA_ModId accessors */

ATbool MA_isValidModId(MA_ModId arg);
inline ATbool MA_isModIdDefault(MA_ModId arg);
ATbool MA_hasModIdIdCon(MA_ModId arg);
MA_IdCon MA_getModIdIdCon(MA_ModId arg);
MA_ModId MA_setModIdIdCon(MA_ModId arg, MA_IdCon IdCon);

/*}}}  */
/*{{{  MA_Term accessors */

ATbool MA_isValidTerm(MA_Term arg);
inline ATbool MA_isTermVar(MA_Term arg);
inline ATbool MA_isTermConstant(MA_Term arg);
inline ATbool MA_isTermFunc(MA_Term arg);
inline ATbool MA_isTermList(MA_Term arg);
inline ATbool MA_isTermTyped(MA_Term arg);
ATbool MA_hasTermVarId(MA_Term arg);
ATbool MA_hasTermFunId(MA_Term arg);
ATbool MA_hasTermWsAfterFunId(MA_Term arg);
ATbool MA_hasTermWsAfterParenOpen(MA_Term arg);
ATbool MA_hasTermArgs(MA_Term arg);
ATbool MA_hasTermWsAfterArgs(MA_Term arg);
ATbool MA_hasTermWsAfterBracketOpen(MA_Term arg);
ATbool MA_hasTermTermList(MA_Term arg);
ATbool MA_hasTermWsAfterTermList(MA_Term arg);
ATbool MA_hasTermTerm(MA_Term arg);
ATbool MA_hasTermWsAfterTerm(MA_Term arg);
ATbool MA_hasTermWsAfterColon(MA_Term arg);
ATbool MA_hasTermType(MA_Term arg);
MA_VarId MA_getTermVarId(MA_Term arg);
MA_FunId MA_getTermFunId(MA_Term arg);
MA_OptLayout MA_getTermWsAfterFunId(MA_Term arg);
MA_OptLayout MA_getTermWsAfterParenOpen(MA_Term arg);
MA_TermArgs MA_getTermArgs(MA_Term arg);
MA_OptLayout MA_getTermWsAfterArgs(MA_Term arg);
MA_OptLayout MA_getTermWsAfterBracketOpen(MA_Term arg);
MA_TermList MA_getTermTermList(MA_Term arg);
MA_OptLayout MA_getTermWsAfterTermList(MA_Term arg);
MA_Term MA_getTermTerm(MA_Term arg);
MA_OptLayout MA_getTermWsAfterTerm(MA_Term arg);
MA_OptLayout MA_getTermWsAfterColon(MA_Term arg);
MA_Term MA_getTermType(MA_Term arg);
MA_Term MA_setTermVarId(MA_Term arg, MA_VarId VarId);
MA_Term MA_setTermFunId(MA_Term arg, MA_FunId FunId);
MA_Term MA_setTermWsAfterFunId(MA_Term arg, MA_OptLayout wsAfterFunId);
MA_Term MA_setTermWsAfterParenOpen(MA_Term arg, MA_OptLayout wsAfterParenOpen);
MA_Term MA_setTermArgs(MA_Term arg, MA_TermArgs args);
MA_Term MA_setTermWsAfterArgs(MA_Term arg, MA_OptLayout wsAfterArgs);
MA_Term MA_setTermWsAfterBracketOpen(MA_Term arg, MA_OptLayout wsAfterBracketOpen);
MA_Term MA_setTermTermList(MA_Term arg, MA_TermList TermList);
MA_Term MA_setTermWsAfterTermList(MA_Term arg, MA_OptLayout wsAfterTermList);
MA_Term MA_setTermTerm(MA_Term arg, MA_Term Term);
MA_Term MA_setTermWsAfterTerm(MA_Term arg, MA_OptLayout wsAfterTerm);
MA_Term MA_setTermWsAfterColon(MA_Term arg, MA_OptLayout wsAfterColon);
MA_Term MA_setTermType(MA_Term arg, MA_Term type);

/*}}}  */
/*{{{  MA_TermList accessors */

ATbool MA_isValidTermList(MA_TermList arg);
inline ATbool MA_isTermListDefault(MA_TermList arg);
ATbool MA_hasTermListElems(MA_TermList arg);
MA_TermElems MA_getTermListElems(MA_TermList arg);
MA_TermList MA_setTermListElems(MA_TermList arg, MA_TermElems elems);

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
ATbool MA_hasFuncDefWsAfterFunId(MA_FuncDef arg);
ATbool MA_hasFuncDefAnnotations(MA_FuncDef arg);
ATbool MA_hasFuncDefWsAfterParenOpen(MA_FuncDef arg);
ATbool MA_hasFuncDefArgs(MA_FuncDef arg);
ATbool MA_hasFuncDefWsAfterArgs(MA_FuncDef arg);
ATbool MA_hasFuncDefWsAfterParenClose(MA_FuncDef arg);
MA_FunId MA_getFuncDefFunId(MA_FuncDef arg);
MA_OptLayout MA_getFuncDefWsAfterFunId(MA_FuncDef arg);
MA_Annotations MA_getFuncDefAnnotations(MA_FuncDef arg);
MA_OptLayout MA_getFuncDefWsAfterParenOpen(MA_FuncDef arg);
MA_SigArgArgs MA_getFuncDefArgs(MA_FuncDef arg);
MA_OptLayout MA_getFuncDefWsAfterArgs(MA_FuncDef arg);
MA_OptLayout MA_getFuncDefWsAfterParenClose(MA_FuncDef arg);
MA_FuncDef MA_setFuncDefFunId(MA_FuncDef arg, MA_FunId FunId);
MA_FuncDef MA_setFuncDefWsAfterFunId(MA_FuncDef arg, MA_OptLayout wsAfterFunId);
MA_FuncDef MA_setFuncDefAnnotations(MA_FuncDef arg, MA_Annotations Annotations);
MA_FuncDef MA_setFuncDefWsAfterParenOpen(MA_FuncDef arg, MA_OptLayout wsAfterParenOpen);
MA_FuncDef MA_setFuncDefArgs(MA_FuncDef arg, MA_SigArgArgs args);
MA_FuncDef MA_setFuncDefWsAfterArgs(MA_FuncDef arg, MA_OptLayout wsAfterArgs);
MA_FuncDef MA_setFuncDefWsAfterParenClose(MA_FuncDef arg, MA_OptLayout wsAfterParenClose);

/*}}}  */
/*{{{  MA_Annotations accessors */

ATbool MA_isValidAnnotations(MA_Annotations arg);
inline ATbool MA_isAnnotationsDefault(MA_Annotations arg);
ATbool MA_hasAnnotationsWsAfterBraceOpen(MA_Annotations arg);
ATbool MA_hasAnnotationsAttrs(MA_Annotations arg);
ATbool MA_hasAnnotationsWsAfterAttrs(MA_Annotations arg);
MA_OptLayout MA_getAnnotationsWsAfterBraceOpen(MA_Annotations arg);
MA_TermAttrs MA_getAnnotationsAttrs(MA_Annotations arg);
MA_OptLayout MA_getAnnotationsWsAfterAttrs(MA_Annotations arg);
MA_Annotations MA_setAnnotationsWsAfterBraceOpen(MA_Annotations arg, MA_OptLayout wsAfterBraceOpen);
MA_Annotations MA_setAnnotationsAttrs(MA_Annotations arg, MA_TermAttrs attrs);
MA_Annotations MA_setAnnotationsWsAfterAttrs(MA_Annotations arg, MA_OptLayout wsAfterAttrs);

/*}}}  */
/*{{{  MA_SigArgList accessors */

ATbool MA_isValidSigArgList(MA_SigArgList arg);
inline ATbool MA_isSigArgListDefault(MA_SigArgList arg);
ATbool MA_hasSigArgListArgs(MA_SigArgList arg);
MA_SigArgArgs MA_getSigArgListArgs(MA_SigArgList arg);
MA_SigArgList MA_setSigArgListArgs(MA_SigArgList arg, MA_SigArgArgs args);

/*}}}  */
/*{{{  MA_FuncDefList accessors */

ATbool MA_isValidFuncDefList(MA_FuncDefList arg);
inline ATbool MA_isFuncDefListDefault(MA_FuncDefList arg);
ATbool MA_hasFuncDefListDefs(MA_FuncDefList arg);
MA_FuncDefDefs MA_getFuncDefListDefs(MA_FuncDefList arg);
MA_FuncDefList MA_setFuncDefListDefs(MA_FuncDefList arg, MA_FuncDefDefs defs);

/*}}}  */
/*{{{  MA_Rule accessors */

ATbool MA_isValidRule(MA_Rule arg);
inline ATbool MA_isRuleNoConds(MA_Rule arg);
inline ATbool MA_isRuleDefaultNoConds(MA_Rule arg);
inline ATbool MA_isRuleWithConds(MA_Rule arg);
inline ATbool MA_isRuleDefaultWithConds(MA_Rule arg);
ATbool MA_hasRuleLhs(MA_Rule arg);
ATbool MA_hasRuleWsAfterLhs(MA_Rule arg);
ATbool MA_hasRuleWsAfterIs(MA_Rule arg);
ATbool MA_hasRuleRhs(MA_Rule arg);
ATbool MA_hasRuleWsAfterDefaultColon(MA_Rule arg);
ATbool MA_hasRuleConds(MA_Rule arg);
ATbool MA_hasRuleWsAfterConds(MA_Rule arg);
ATbool MA_hasRuleWsAfterEqualsEqualsGreaterThan(MA_Rule arg);
MA_Term MA_getRuleLhs(MA_Rule arg);
MA_OptLayout MA_getRuleWsAfterLhs(MA_Rule arg);
MA_OptLayout MA_getRuleWsAfterIs(MA_Rule arg);
MA_Term MA_getRuleRhs(MA_Rule arg);
MA_OptLayout MA_getRuleWsAfterDefaultColon(MA_Rule arg);
MA_CondList MA_getRuleConds(MA_Rule arg);
MA_OptLayout MA_getRuleWsAfterConds(MA_Rule arg);
MA_OptLayout MA_getRuleWsAfterEqualsEqualsGreaterThan(MA_Rule arg);
MA_Rule MA_setRuleLhs(MA_Rule arg, MA_Term lhs);
MA_Rule MA_setRuleWsAfterLhs(MA_Rule arg, MA_OptLayout wsAfterLhs);
MA_Rule MA_setRuleWsAfterIs(MA_Rule arg, MA_OptLayout wsAfterIs);
MA_Rule MA_setRuleRhs(MA_Rule arg, MA_Term rhs);
MA_Rule MA_setRuleWsAfterDefaultColon(MA_Rule arg, MA_OptLayout wsAfterDefaultColon);
MA_Rule MA_setRuleConds(MA_Rule arg, MA_CondList conds);
MA_Rule MA_setRuleWsAfterConds(MA_Rule arg, MA_OptLayout wsAfterConds);
MA_Rule MA_setRuleWsAfterEqualsEqualsGreaterThan(MA_Rule arg, MA_OptLayout wsAfterEqualsEqualsGreaterThan);

/*}}}  */
/*{{{  MA_RuleList accessors */

ATbool MA_isValidRuleList(MA_RuleList arg);
inline ATbool MA_isRuleListDefault(MA_RuleList arg);
ATbool MA_hasRuleListRules(MA_RuleList arg);
MA_RuleRules MA_getRuleListRules(MA_RuleList arg);
MA_RuleList MA_setRuleListRules(MA_RuleList arg, MA_RuleRules rules);

/*}}}  */
/*{{{  MA_CondList accessors */

ATbool MA_isValidCondList(MA_CondList arg);
inline ATbool MA_isCondListDefault(MA_CondList arg);
ATbool MA_hasCondListConds(MA_CondList arg);
MA_CondConds MA_getCondListConds(MA_CondList arg);
MA_CondList MA_setCondListConds(MA_CondList arg, MA_CondConds conds);

/*}}}  */
/*{{{  MA_Cond accessors */

ATbool MA_isValidCond(MA_Cond arg);
inline ATbool MA_isCondAssign(MA_Cond arg);
inline ATbool MA_isCondNoAssign(MA_Cond arg);
inline ATbool MA_isCondEqual(MA_Cond arg);
inline ATbool MA_isCondUnequal(MA_Cond arg);
ATbool MA_hasCondLhs(MA_Cond arg);
ATbool MA_hasCondWsAfterLhs(MA_Cond arg);
ATbool MA_hasCondWsAfterBecomes(MA_Cond arg);
ATbool MA_hasCondRhs(MA_Cond arg);
ATbool MA_hasCondWsAfterNotBecomes(MA_Cond arg);
ATbool MA_hasCondWsAfterEquals(MA_Cond arg);
ATbool MA_hasCondWsAfterNotEquals(MA_Cond arg);
MA_Term MA_getCondLhs(MA_Cond arg);
MA_OptLayout MA_getCondWsAfterLhs(MA_Cond arg);
MA_OptLayout MA_getCondWsAfterBecomes(MA_Cond arg);
MA_Term MA_getCondRhs(MA_Cond arg);
MA_OptLayout MA_getCondWsAfterNotBecomes(MA_Cond arg);
MA_OptLayout MA_getCondWsAfterEquals(MA_Cond arg);
MA_OptLayout MA_getCondWsAfterNotEquals(MA_Cond arg);
MA_Cond MA_setCondLhs(MA_Cond arg, MA_Term lhs);
MA_Cond MA_setCondWsAfterLhs(MA_Cond arg, MA_OptLayout wsAfterLhs);
MA_Cond MA_setCondWsAfterBecomes(MA_Cond arg, MA_OptLayout wsAfterBecomes);
MA_Cond MA_setCondRhs(MA_Cond arg, MA_Term rhs);
MA_Cond MA_setCondWsAfterNotBecomes(MA_Cond arg, MA_OptLayout wsAfterNotBecomes);
MA_Cond MA_setCondWsAfterEquals(MA_Cond arg, MA_OptLayout wsAfterEquals);
MA_Cond MA_setCondWsAfterNotEquals(MA_Cond arg, MA_OptLayout wsAfterNotEquals);

/*}}}  */
/*{{{  MA_SignatureOpt accessors */

ATbool MA_isValidSignatureOpt(MA_SignatureOpt arg);
inline ATbool MA_isSignatureOptAbsent(MA_SignatureOpt arg);
inline ATbool MA_isSignatureOptPresent(MA_SignatureOpt arg);
ATbool MA_hasSignatureOptWsAfterSignature(MA_SignatureOpt arg);
ATbool MA_hasSignatureOptFuncDefList(MA_SignatureOpt arg);
MA_OptLayout MA_getSignatureOptWsAfterSignature(MA_SignatureOpt arg);
MA_FuncDefList MA_getSignatureOptFuncDefList(MA_SignatureOpt arg);
MA_SignatureOpt MA_setSignatureOptWsAfterSignature(MA_SignatureOpt arg, MA_OptLayout wsAfterSignature);
MA_SignatureOpt MA_setSignatureOptFuncDefList(MA_SignatureOpt arg, MA_FuncDefList FuncDefList);

/*}}}  */
/*{{{  MA_RulesOpt accessors */

ATbool MA_isValidRulesOpt(MA_RulesOpt arg);
inline ATbool MA_isRulesOptAbsent(MA_RulesOpt arg);
inline ATbool MA_isRulesOptPresent(MA_RulesOpt arg);
ATbool MA_hasRulesOptWsAfterRules(MA_RulesOpt arg);
ATbool MA_hasRulesOptRuleList(MA_RulesOpt arg);
MA_OptLayout MA_getRulesOptWsAfterRules(MA_RulesOpt arg);
MA_RuleList MA_getRulesOptRuleList(MA_RulesOpt arg);
MA_RulesOpt MA_setRulesOptWsAfterRules(MA_RulesOpt arg, MA_OptLayout wsAfterRules);
MA_RulesOpt MA_setRulesOptRuleList(MA_RulesOpt arg, MA_RuleList RuleList);

/*}}}  */
/*{{{  MA_Module accessors */

ATbool MA_isValidModule(MA_Module arg);
inline ATbool MA_isModuleModule(MA_Module arg);
ATbool MA_hasModuleWsAfterModule(MA_Module arg);
ATbool MA_hasModuleModId(MA_Module arg);
ATbool MA_hasModuleWsAfterModId(MA_Module arg);
ATbool MA_hasModuleSignatureOpt(MA_Module arg);
ATbool MA_hasModuleWsAfterSignatureOpt(MA_Module arg);
ATbool MA_hasModuleRulesOpt(MA_Module arg);
MA_OptLayout MA_getModuleWsAfterModule(MA_Module arg);
MA_ModId MA_getModuleModId(MA_Module arg);
MA_OptLayout MA_getModuleWsAfterModId(MA_Module arg);
MA_SignatureOpt MA_getModuleSignatureOpt(MA_Module arg);
MA_OptLayout MA_getModuleWsAfterSignatureOpt(MA_Module arg);
MA_RulesOpt MA_getModuleRulesOpt(MA_Module arg);
MA_Module MA_setModuleWsAfterModule(MA_Module arg, MA_OptLayout wsAfterModule);
MA_Module MA_setModuleModId(MA_Module arg, MA_ModId ModId);
MA_Module MA_setModuleWsAfterModId(MA_Module arg, MA_OptLayout wsAfterModId);
MA_Module MA_setModuleSignatureOpt(MA_Module arg, MA_SignatureOpt SignatureOpt);
MA_Module MA_setModuleWsAfterSignatureOpt(MA_Module arg, MA_OptLayout wsAfterSignatureOpt);
MA_Module MA_setModuleRulesOpt(MA_Module arg, MA_RulesOpt RulesOpt);

/*}}}  */
/*{{{  MA_TermArgs accessors */

ATbool MA_isValidTermArgs(MA_TermArgs arg);
inline ATbool MA_isTermArgsEmpty(MA_TermArgs arg);
inline ATbool MA_isTermArgsSingle(MA_TermArgs arg);
inline ATbool MA_isTermArgsMany(MA_TermArgs arg);
ATbool MA_hasTermArgsHead(MA_TermArgs arg);
ATbool MA_hasTermArgsWsAfterHead(MA_TermArgs arg);
ATbool MA_hasTermArgsWsAfterSep(MA_TermArgs arg);
ATbool MA_hasTermArgsTail(MA_TermArgs arg);
MA_TermArgs MA_getTermArgsTail(MA_TermArgs arg);
MA_Term MA_getTermArgsHead(MA_TermArgs arg);
MA_OptLayout MA_getTermArgsWsAfterHead(MA_TermArgs arg);
MA_OptLayout MA_getTermArgsWsAfterSep(MA_TermArgs arg);
MA_TermArgs MA_setTermArgsHead(MA_TermArgs arg, MA_Term head);
MA_TermArgs MA_setTermArgsWsAfterHead(MA_TermArgs arg, MA_OptLayout wsAfterHead);
MA_TermArgs MA_setTermArgsWsAfterSep(MA_TermArgs arg, MA_OptLayout wsAfterSep);
MA_TermArgs MA_setTermArgsTail(MA_TermArgs arg, MA_TermArgs tail);

/*}}}  */
/*{{{  MA_TermElems accessors */

ATbool MA_isValidTermElems(MA_TermElems arg);
inline ATbool MA_isTermElemsEmpty(MA_TermElems arg);
inline ATbool MA_isTermElemsSingle(MA_TermElems arg);
inline ATbool MA_isTermElemsMany(MA_TermElems arg);
ATbool MA_hasTermElemsHead(MA_TermElems arg);
ATbool MA_hasTermElemsWsAfterHead(MA_TermElems arg);
ATbool MA_hasTermElemsWsAfterSep(MA_TermElems arg);
ATbool MA_hasTermElemsTail(MA_TermElems arg);
MA_TermElems MA_getTermElemsTail(MA_TermElems arg);
MA_Term MA_getTermElemsHead(MA_TermElems arg);
MA_OptLayout MA_getTermElemsWsAfterHead(MA_TermElems arg);
MA_OptLayout MA_getTermElemsWsAfterSep(MA_TermElems arg);
MA_TermElems MA_setTermElemsHead(MA_TermElems arg, MA_Term head);
MA_TermElems MA_setTermElemsWsAfterHead(MA_TermElems arg, MA_OptLayout wsAfterHead);
MA_TermElems MA_setTermElemsWsAfterSep(MA_TermElems arg, MA_OptLayout wsAfterSep);
MA_TermElems MA_setTermElemsTail(MA_TermElems arg, MA_TermElems tail);

/*}}}  */
/*{{{  MA_SigArgArgs accessors */

ATbool MA_isValidSigArgArgs(MA_SigArgArgs arg);
inline ATbool MA_isSigArgArgsEmpty(MA_SigArgArgs arg);
inline ATbool MA_isSigArgArgsSingle(MA_SigArgArgs arg);
inline ATbool MA_isSigArgArgsMany(MA_SigArgArgs arg);
ATbool MA_hasSigArgArgsHead(MA_SigArgArgs arg);
ATbool MA_hasSigArgArgsWsAfterHead(MA_SigArgArgs arg);
ATbool MA_hasSigArgArgsWsAfterSep(MA_SigArgArgs arg);
ATbool MA_hasSigArgArgsTail(MA_SigArgArgs arg);
MA_SigArgArgs MA_getSigArgArgsTail(MA_SigArgArgs arg);
MA_SigArg MA_getSigArgArgsHead(MA_SigArgArgs arg);
MA_OptLayout MA_getSigArgArgsWsAfterHead(MA_SigArgArgs arg);
MA_OptLayout MA_getSigArgArgsWsAfterSep(MA_SigArgArgs arg);
MA_SigArgArgs MA_setSigArgArgsHead(MA_SigArgArgs arg, MA_SigArg head);
MA_SigArgArgs MA_setSigArgArgsWsAfterHead(MA_SigArgArgs arg, MA_OptLayout wsAfterHead);
MA_SigArgArgs MA_setSigArgArgsWsAfterSep(MA_SigArgArgs arg, MA_OptLayout wsAfterSep);
MA_SigArgArgs MA_setSigArgArgsTail(MA_SigArgArgs arg, MA_SigArgArgs tail);

/*}}}  */
/*{{{  MA_TermAttrs accessors */

ATbool MA_isValidTermAttrs(MA_TermAttrs arg);
inline ATbool MA_isTermAttrsEmpty(MA_TermAttrs arg);
inline ATbool MA_isTermAttrsSingle(MA_TermAttrs arg);
inline ATbool MA_isTermAttrsMany(MA_TermAttrs arg);
ATbool MA_hasTermAttrsHead(MA_TermAttrs arg);
ATbool MA_hasTermAttrsWsAfterHead(MA_TermAttrs arg);
ATbool MA_hasTermAttrsWsAfterSep(MA_TermAttrs arg);
ATbool MA_hasTermAttrsTail(MA_TermAttrs arg);
MA_TermAttrs MA_getTermAttrsTail(MA_TermAttrs arg);
MA_Term MA_getTermAttrsHead(MA_TermAttrs arg);
MA_OptLayout MA_getTermAttrsWsAfterHead(MA_TermAttrs arg);
MA_OptLayout MA_getTermAttrsWsAfterSep(MA_TermAttrs arg);
MA_TermAttrs MA_setTermAttrsHead(MA_TermAttrs arg, MA_Term head);
MA_TermAttrs MA_setTermAttrsWsAfterHead(MA_TermAttrs arg, MA_OptLayout wsAfterHead);
MA_TermAttrs MA_setTermAttrsWsAfterSep(MA_TermAttrs arg, MA_OptLayout wsAfterSep);
MA_TermAttrs MA_setTermAttrsTail(MA_TermAttrs arg, MA_TermAttrs tail);

/*}}}  */
/*{{{  MA_FuncDefDefs accessors */

ATbool MA_isValidFuncDefDefs(MA_FuncDefDefs arg);
inline ATbool MA_isFuncDefDefsEmpty(MA_FuncDefDefs arg);
inline ATbool MA_isFuncDefDefsSingle(MA_FuncDefDefs arg);
inline ATbool MA_isFuncDefDefsMany(MA_FuncDefDefs arg);
ATbool MA_hasFuncDefDefsHead(MA_FuncDefDefs arg);
ATbool MA_hasFuncDefDefsWsAfterHead(MA_FuncDefDefs arg);
ATbool MA_hasFuncDefDefsWsAfterSep(MA_FuncDefDefs arg);
ATbool MA_hasFuncDefDefsTail(MA_FuncDefDefs arg);
MA_FuncDefDefs MA_getFuncDefDefsTail(MA_FuncDefDefs arg);
MA_FuncDef MA_getFuncDefDefsHead(MA_FuncDefDefs arg);
MA_OptLayout MA_getFuncDefDefsWsAfterHead(MA_FuncDefDefs arg);
MA_OptLayout MA_getFuncDefDefsWsAfterSep(MA_FuncDefDefs arg);
MA_FuncDefDefs MA_setFuncDefDefsHead(MA_FuncDefDefs arg, MA_FuncDef head);
MA_FuncDefDefs MA_setFuncDefDefsWsAfterHead(MA_FuncDefDefs arg, MA_OptLayout wsAfterHead);
MA_FuncDefDefs MA_setFuncDefDefsWsAfterSep(MA_FuncDefDefs arg, MA_OptLayout wsAfterSep);
MA_FuncDefDefs MA_setFuncDefDefsTail(MA_FuncDefDefs arg, MA_FuncDefDefs tail);

/*}}}  */
/*{{{  MA_RuleRules accessors */

ATbool MA_isValidRuleRules(MA_RuleRules arg);
inline ATbool MA_isRuleRulesEmpty(MA_RuleRules arg);
inline ATbool MA_isRuleRulesSingle(MA_RuleRules arg);
inline ATbool MA_isRuleRulesMany(MA_RuleRules arg);
ATbool MA_hasRuleRulesHead(MA_RuleRules arg);
ATbool MA_hasRuleRulesWsAfterHead(MA_RuleRules arg);
ATbool MA_hasRuleRulesWsAfterSep(MA_RuleRules arg);
ATbool MA_hasRuleRulesTail(MA_RuleRules arg);
MA_RuleRules MA_getRuleRulesTail(MA_RuleRules arg);
MA_Rule MA_getRuleRulesHead(MA_RuleRules arg);
MA_OptLayout MA_getRuleRulesWsAfterHead(MA_RuleRules arg);
MA_OptLayout MA_getRuleRulesWsAfterSep(MA_RuleRules arg);
MA_RuleRules MA_setRuleRulesHead(MA_RuleRules arg, MA_Rule head);
MA_RuleRules MA_setRuleRulesWsAfterHead(MA_RuleRules arg, MA_OptLayout wsAfterHead);
MA_RuleRules MA_setRuleRulesWsAfterSep(MA_RuleRules arg, MA_OptLayout wsAfterSep);
MA_RuleRules MA_setRuleRulesTail(MA_RuleRules arg, MA_RuleRules tail);

/*}}}  */
/*{{{  MA_CondConds accessors */

ATbool MA_isValidCondConds(MA_CondConds arg);
inline ATbool MA_isCondCondsEmpty(MA_CondConds arg);
inline ATbool MA_isCondCondsSingle(MA_CondConds arg);
inline ATbool MA_isCondCondsMany(MA_CondConds arg);
ATbool MA_hasCondCondsHead(MA_CondConds arg);
ATbool MA_hasCondCondsWsAfterHead(MA_CondConds arg);
ATbool MA_hasCondCondsWsAfterSep(MA_CondConds arg);
ATbool MA_hasCondCondsTail(MA_CondConds arg);
MA_CondConds MA_getCondCondsTail(MA_CondConds arg);
MA_Cond MA_getCondCondsHead(MA_CondConds arg);
MA_OptLayout MA_getCondCondsWsAfterHead(MA_CondConds arg);
MA_OptLayout MA_getCondCondsWsAfterSep(MA_CondConds arg);
MA_CondConds MA_setCondCondsHead(MA_CondConds arg, MA_Cond head);
MA_CondConds MA_setCondCondsWsAfterHead(MA_CondConds arg, MA_OptLayout wsAfterHead);
MA_CondConds MA_setCondCondsWsAfterSep(MA_CondConds arg, MA_OptLayout wsAfterSep);
MA_CondConds MA_setCondCondsTail(MA_CondConds arg, MA_CondConds tail);

/*}}}  */
/*{{{  MA_LexLayout accessors */

ATbool MA_isValidLexLayout(MA_LexLayout arg);
inline ATbool MA_isLexLayoutWhitespace(MA_LexLayout arg);
ATbool MA_hasLexLayoutCh(MA_LexLayout arg);
char MA_getLexLayoutCh(MA_LexLayout arg);
MA_LexLayout MA_setLexLayoutCh(MA_LexLayout arg, char ch);

/*}}}  */
/*{{{  MA_LexStrChar accessors */

ATbool MA_isValidLexStrChar(MA_LexStrChar arg);
inline ATbool MA_isLexStrCharNewline(MA_LexStrChar arg);
inline ATbool MA_isLexStrCharTab(MA_LexStrChar arg);
inline ATbool MA_isLexStrCharQuote(MA_LexStrChar arg);
inline ATbool MA_isLexStrCharBackslash(MA_LexStrChar arg);
inline ATbool MA_isLexStrCharDecimal(MA_LexStrChar arg);
inline ATbool MA_isLexStrCharNormal(MA_LexStrChar arg);
ATbool MA_hasLexStrCharA(MA_LexStrChar arg);
ATbool MA_hasLexStrCharB(MA_LexStrChar arg);
ATbool MA_hasLexStrCharC(MA_LexStrChar arg);
ATbool MA_hasLexStrCharCh(MA_LexStrChar arg);
char MA_getLexStrCharA(MA_LexStrChar arg);
char MA_getLexStrCharB(MA_LexStrChar arg);
char MA_getLexStrCharC(MA_LexStrChar arg);
char MA_getLexStrCharCh(MA_LexStrChar arg);
MA_LexStrChar MA_setLexStrCharA(MA_LexStrChar arg, char a);
MA_LexStrChar MA_setLexStrCharB(MA_LexStrChar arg, char b);
MA_LexStrChar MA_setLexStrCharC(MA_LexStrChar arg, char c);
MA_LexStrChar MA_setLexStrCharCh(MA_LexStrChar arg, char ch);

/*}}}  */
/*{{{  MA_StrChar accessors */

ATbool MA_isValidStrChar(MA_StrChar arg);
inline ATbool MA_isStrCharLexToCf(MA_StrChar arg);
ATbool MA_hasStrCharStrChar(MA_StrChar arg);
MA_LexStrChar MA_getStrCharStrChar(MA_StrChar arg);
MA_StrChar MA_setStrCharStrChar(MA_StrChar arg, MA_LexStrChar StrChar);

/*}}}  */
/*{{{  MA_LexStrCon accessors */

ATbool MA_isValidLexStrCon(MA_LexStrCon arg);
inline ATbool MA_isLexStrConDefault(MA_LexStrCon arg);
ATbool MA_hasLexStrConChars(MA_LexStrCon arg);
MA_LexStrCharChars MA_getLexStrConChars(MA_LexStrCon arg);
MA_LexStrCon MA_setLexStrConChars(MA_LexStrCon arg, MA_LexStrCharChars chars);

/*}}}  */
/*{{{  MA_StrCon accessors */

ATbool MA_isValidStrCon(MA_StrCon arg);
inline ATbool MA_isStrConLexToCf(MA_StrCon arg);
ATbool MA_hasStrConStrCon(MA_StrCon arg);
MA_LexStrCon MA_getStrConStrCon(MA_StrCon arg);
MA_StrCon MA_setStrConStrCon(MA_StrCon arg, MA_LexStrCon StrCon);

/*}}}  */
/*{{{  MA_LexStrCharChars accessors */

ATbool MA_isValidLexStrCharChars(MA_LexStrCharChars arg);
inline ATbool MA_isLexStrCharCharsEmpty(MA_LexStrCharChars arg);
inline ATbool MA_isLexStrCharCharsSingle(MA_LexStrCharChars arg);
inline ATbool MA_isLexStrCharCharsMany(MA_LexStrCharChars arg);
ATbool MA_hasLexStrCharCharsHead(MA_LexStrCharChars arg);
ATbool MA_hasLexStrCharCharsTail(MA_LexStrCharChars arg);
MA_LexStrChar MA_getLexStrCharCharsHead(MA_LexStrCharChars arg);
MA_LexStrCharChars MA_getLexStrCharCharsTail(MA_LexStrCharChars arg);
MA_LexStrCharChars MA_setLexStrCharCharsHead(MA_LexStrCharChars arg, MA_LexStrChar head);
MA_LexStrCharChars MA_setLexStrCharCharsTail(MA_LexStrCharChars arg, MA_LexStrCharChars tail);

/*}}}  */
/*{{{  MA_LexNatCon accessors */

ATbool MA_isValidLexNatCon(MA_LexNatCon arg);
inline ATbool MA_isLexNatConDigits(MA_LexNatCon arg);
ATbool MA_hasLexNatConList(MA_LexNatCon arg);
char* MA_getLexNatConList(MA_LexNatCon arg);
MA_LexNatCon MA_setLexNatConList(MA_LexNatCon arg, const char* list);

/*}}}  */
/*{{{  MA_NatCon accessors */

ATbool MA_isValidNatCon(MA_NatCon arg);
inline ATbool MA_isNatConLexToCf(MA_NatCon arg);
ATbool MA_hasNatConNatCon(MA_NatCon arg);
MA_LexNatCon MA_getNatConNatCon(MA_NatCon arg);
MA_NatCon MA_setNatConNatCon(MA_NatCon arg, MA_LexNatCon NatCon);

/*}}}  */
/*{{{  MA_LexIdCon accessors */

ATbool MA_isValidLexIdCon(MA_LexIdCon arg);
inline ATbool MA_isLexIdConDefault(MA_LexIdCon arg);
ATbool MA_hasLexIdConHead(MA_LexIdCon arg);
ATbool MA_hasLexIdConTail(MA_LexIdCon arg);
char MA_getLexIdConHead(MA_LexIdCon arg);
char* MA_getLexIdConTail(MA_LexIdCon arg);
MA_LexIdCon MA_setLexIdConHead(MA_LexIdCon arg, char head);
MA_LexIdCon MA_setLexIdConTail(MA_LexIdCon arg, const char* tail);

/*}}}  */
/*{{{  MA_IdCon accessors */

ATbool MA_isValidIdCon(MA_IdCon arg);
inline ATbool MA_isIdConLexToCf(MA_IdCon arg);
ATbool MA_hasIdConIdCon(MA_IdCon arg);
MA_LexIdCon MA_getIdConIdCon(MA_IdCon arg);
MA_IdCon MA_setIdConIdCon(MA_IdCon arg, MA_LexIdCon IdCon);

/*}}}  */
/*{{{  sort visitors */

MA_OptLayout MA_visitOptLayout(MA_OptLayout arg, MA_Layout (*acceptLayout)(MA_Layout));
MA_Layout MA_visitLayout(MA_Layout arg, MA_LexLayoutList (*acceptList)(MA_LexLayoutList));
MA_LexLayoutList MA_visitLexLayoutList(MA_LexLayoutList arg, MA_LexLayout (*acceptHead)(MA_LexLayout));
MA_TraversalStrategy MA_visitTraversalStrategy(MA_TraversalStrategy arg);
MA_TraversalType MA_visitTraversalType(MA_TraversalType arg);
MA_TraversalContinuation MA_visitTraversalContinuation(MA_TraversalContinuation arg);
MA_FunId MA_visitFunId(MA_FunId arg, MA_NatCon (*acceptNatCon)(MA_NatCon), MA_IdCon (*acceptIdCon)(MA_IdCon), MA_StrCon (*acceptStrCon)(MA_StrCon), MA_OptLayout (*acceptWsAfterBracketOpen)(MA_OptLayout), MA_OptLayout (*acceptWsAfterFunId)(MA_OptLayout), MA_OptLayout (*acceptWsAfterBraceOpen)(MA_OptLayout), MA_OptLayout (*acceptWsAfterIGNORE)(MA_OptLayout), MA_OptLayout (*acceptWsAfterTRANSLATE)(MA_OptLayout), MA_OptLayout (*acceptWsAfterBar)(MA_OptLayout), MA_TraversalType (*acceptTraversalType)(MA_TraversalType), MA_OptLayout (*acceptWsAfterTraversalType)(MA_OptLayout), MA_TraversalStrategy (*acceptTraversalStrategy)(MA_TraversalStrategy), MA_OptLayout (*acceptWsAfterTraversalStrategy)(MA_OptLayout), MA_TraversalContinuation (*acceptTraversalContinuation)(MA_TraversalContinuation), MA_OptLayout (*acceptWsAfterTraversalContinuation)(MA_OptLayout), MA_OptLayout (*acceptWsAfterLhs)(MA_OptLayout), MA_OptLayout (*acceptWsAfterPlusPlus)(MA_OptLayout));
MA_VarId MA_visitVarId(MA_VarId arg, MA_OptLayout (*acceptWsAfterDollar)(MA_OptLayout), MA_FunId (*acceptFunId)(MA_FunId), MA_OptLayout (*acceptWsAfterDollarPlus)(MA_OptLayout), MA_OptLayout (*acceptWsAfterDollarStar)(MA_OptLayout));
MA_ModId MA_visitModId(MA_ModId arg, MA_IdCon (*acceptIdCon)(MA_IdCon));
MA_Term MA_visitTerm(MA_Term arg, MA_VarId (*acceptVarId)(MA_VarId), MA_FunId (*acceptFunId)(MA_FunId), MA_OptLayout (*acceptWsAfterFunId)(MA_OptLayout), MA_OptLayout (*acceptWsAfterParenOpen)(MA_OptLayout), MA_TermArgs (*acceptArgs)(MA_TermArgs), MA_OptLayout (*acceptWsAfterArgs)(MA_OptLayout), MA_OptLayout (*acceptWsAfterBracketOpen)(MA_OptLayout), MA_TermList (*acceptTermList)(MA_TermList), MA_OptLayout (*acceptWsAfterTermList)(MA_OptLayout), MA_OptLayout (*acceptWsAfterTerm)(MA_OptLayout), MA_OptLayout (*acceptWsAfterColon)(MA_OptLayout));
MA_TermList MA_visitTermList(MA_TermList arg, MA_TermElems (*acceptElems)(MA_TermElems));
MA_SigArg MA_visitSigArg(MA_SigArg arg, MA_OptLayout (*acceptWsAfterUnderscore)(MA_OptLayout));
MA_FuncDef MA_visitFuncDef(MA_FuncDef arg, MA_FunId (*acceptFunId)(MA_FunId), MA_OptLayout (*acceptWsAfterFunId)(MA_OptLayout), MA_Annotations (*acceptAnnotations)(MA_Annotations), MA_OptLayout (*acceptWsAfterParenOpen)(MA_OptLayout), MA_SigArgArgs (*acceptArgs)(MA_SigArgArgs), MA_OptLayout (*acceptWsAfterArgs)(MA_OptLayout), MA_OptLayout (*acceptWsAfterParenClose)(MA_OptLayout));
MA_Annotations MA_visitAnnotations(MA_Annotations arg, MA_OptLayout (*acceptWsAfterBraceOpen)(MA_OptLayout), MA_TermAttrs (*acceptAttrs)(MA_TermAttrs), MA_OptLayout (*acceptWsAfterAttrs)(MA_OptLayout));
MA_SigArgList MA_visitSigArgList(MA_SigArgList arg, MA_SigArgArgs (*acceptArgs)(MA_SigArgArgs));
MA_FuncDefList MA_visitFuncDefList(MA_FuncDefList arg, MA_FuncDefDefs (*acceptDefs)(MA_FuncDefDefs));
MA_Rule MA_visitRule(MA_Rule arg, MA_Term (*acceptLhs)(MA_Term), MA_OptLayout (*acceptWsAfterLhs)(MA_OptLayout), MA_OptLayout (*acceptWsAfterIs)(MA_OptLayout), MA_Term (*acceptRhs)(MA_Term), MA_OptLayout (*acceptWsAfterDefaultColon)(MA_OptLayout), MA_CondList (*acceptConds)(MA_CondList), MA_OptLayout (*acceptWsAfterConds)(MA_OptLayout), MA_OptLayout (*acceptWsAfterEqualsEqualsGreaterThan)(MA_OptLayout));
MA_RuleList MA_visitRuleList(MA_RuleList arg, MA_RuleRules (*acceptRules)(MA_RuleRules));
MA_CondList MA_visitCondList(MA_CondList arg, MA_CondConds (*acceptConds)(MA_CondConds));
MA_Cond MA_visitCond(MA_Cond arg, MA_Term (*acceptLhs)(MA_Term), MA_OptLayout (*acceptWsAfterLhs)(MA_OptLayout), MA_OptLayout (*acceptWsAfterBecomes)(MA_OptLayout), MA_Term (*acceptRhs)(MA_Term), MA_OptLayout (*acceptWsAfterNotBecomes)(MA_OptLayout), MA_OptLayout (*acceptWsAfterEquals)(MA_OptLayout), MA_OptLayout (*acceptWsAfterNotEquals)(MA_OptLayout));
MA_SignatureOpt MA_visitSignatureOpt(MA_SignatureOpt arg, MA_OptLayout (*acceptWsAfterSignature)(MA_OptLayout), MA_FuncDefList (*acceptFuncDefList)(MA_FuncDefList));
MA_RulesOpt MA_visitRulesOpt(MA_RulesOpt arg, MA_OptLayout (*acceptWsAfterRules)(MA_OptLayout), MA_RuleList (*acceptRuleList)(MA_RuleList));
MA_Module MA_visitModule(MA_Module arg, MA_OptLayout (*acceptWsAfterModule)(MA_OptLayout), MA_ModId (*acceptModId)(MA_ModId), MA_OptLayout (*acceptWsAfterModId)(MA_OptLayout), MA_SignatureOpt (*acceptSignatureOpt)(MA_SignatureOpt), MA_OptLayout (*acceptWsAfterSignatureOpt)(MA_OptLayout), MA_RulesOpt (*acceptRulesOpt)(MA_RulesOpt));
MA_TermArgs MA_visitTermArgs(MA_TermArgs arg, MA_Term (*acceptHead)(MA_Term), MA_OptLayout (*acceptWsAfterHead)(MA_OptLayout), MA_OptLayout (*acceptWsAfterSep)(MA_OptLayout));
MA_TermElems MA_visitTermElems(MA_TermElems arg, MA_Term (*acceptHead)(MA_Term), MA_OptLayout (*acceptWsAfterHead)(MA_OptLayout), MA_OptLayout (*acceptWsAfterSep)(MA_OptLayout));
MA_SigArgArgs MA_visitSigArgArgs(MA_SigArgArgs arg, MA_SigArg (*acceptHead)(MA_SigArg), MA_OptLayout (*acceptWsAfterHead)(MA_OptLayout), MA_OptLayout (*acceptWsAfterSep)(MA_OptLayout));
MA_TermAttrs MA_visitTermAttrs(MA_TermAttrs arg, MA_Term (*acceptHead)(MA_Term), MA_OptLayout (*acceptWsAfterHead)(MA_OptLayout), MA_OptLayout (*acceptWsAfterSep)(MA_OptLayout));
MA_FuncDefDefs MA_visitFuncDefDefs(MA_FuncDefDefs arg, MA_FuncDef (*acceptHead)(MA_FuncDef), MA_OptLayout (*acceptWsAfterHead)(MA_OptLayout), MA_OptLayout (*acceptWsAfterSep)(MA_OptLayout));
MA_RuleRules MA_visitRuleRules(MA_RuleRules arg, MA_Rule (*acceptHead)(MA_Rule), MA_OptLayout (*acceptWsAfterHead)(MA_OptLayout), MA_OptLayout (*acceptWsAfterSep)(MA_OptLayout));
MA_CondConds MA_visitCondConds(MA_CondConds arg, MA_Cond (*acceptHead)(MA_Cond), MA_OptLayout (*acceptWsAfterHead)(MA_OptLayout), MA_OptLayout (*acceptWsAfterSep)(MA_OptLayout));
MA_LexLayout MA_visitLexLayout(MA_LexLayout arg, char (*acceptCh)(char));
MA_LexStrChar MA_visitLexStrChar(MA_LexStrChar arg, char (*acceptA)(char), char (*acceptB)(char), char (*acceptC)(char), char (*acceptCh)(char));
MA_StrChar MA_visitStrChar(MA_StrChar arg, MA_LexStrChar (*acceptStrChar)(MA_LexStrChar));
MA_LexStrCon MA_visitLexStrCon(MA_LexStrCon arg, MA_LexStrCharChars (*acceptChars)(MA_LexStrCharChars));
MA_StrCon MA_visitStrCon(MA_StrCon arg, MA_LexStrCon (*acceptStrCon)(MA_LexStrCon));
MA_LexStrCharChars MA_visitLexStrCharChars(MA_LexStrCharChars arg, MA_LexStrChar (*acceptHead)(MA_LexStrChar));
MA_LexNatCon MA_visitLexNatCon(MA_LexNatCon arg, char* (*acceptList)(char*));
MA_NatCon MA_visitNatCon(MA_NatCon arg, MA_LexNatCon (*acceptNatCon)(MA_LexNatCon));
MA_LexIdCon MA_visitLexIdCon(MA_LexIdCon arg, char (*acceptHead)(char), char* (*acceptTail)(char*));
MA_IdCon MA_visitIdCon(MA_IdCon arg, MA_LexIdCon (*acceptIdCon)(MA_LexIdCon));

/*}}}  */

#endif /* _MUASF_H */
