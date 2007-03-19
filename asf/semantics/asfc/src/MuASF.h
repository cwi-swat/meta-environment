#ifndef _MUASF_H
#define _MUASF_H

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "MuASF_dict.h"

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

#ifdef FAST_API
#define MA_initMuASFApi() (init_MuASF_dict())
#else
void _MA_initMuASFApi(void);
#define MA_initMuASFApi() (_MA_initMuASFApi())
#endif

#ifdef FAST_API
#define MA_protectOptLayout(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _MA_protectOptLayout(MA_OptLayout *arg);
#define MA_protectOptLayout(arg) (_MA_protectOptLayout(arg))
#endif
#ifdef FAST_API
#define MA_unprotectOptLayout(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _MA_unprotectOptLayout(MA_OptLayout *arg);
#define MA_unprotectOptLayout(arg) (_MA_unprotectOptLayout(arg))
#endif
#ifdef FAST_API
#define MA_protectLayout(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _MA_protectLayout(MA_Layout *arg);
#define MA_protectLayout(arg) (_MA_protectLayout(arg))
#endif
#ifdef FAST_API
#define MA_unprotectLayout(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _MA_unprotectLayout(MA_Layout *arg);
#define MA_unprotectLayout(arg) (_MA_unprotectLayout(arg))
#endif
#ifdef FAST_API
#define MA_protectLexLayoutList(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _MA_protectLexLayoutList(MA_LexLayoutList *arg);
#define MA_protectLexLayoutList(arg) (_MA_protectLexLayoutList(arg))
#endif
#ifdef FAST_API
#define MA_unprotectLexLayoutList(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _MA_unprotectLexLayoutList(MA_LexLayoutList *arg);
#define MA_unprotectLexLayoutList(arg) (_MA_unprotectLexLayoutList(arg))
#endif
#ifdef FAST_API
#define MA_protectTraversalStrategy(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _MA_protectTraversalStrategy(MA_TraversalStrategy *arg);
#define MA_protectTraversalStrategy(arg) (_MA_protectTraversalStrategy(arg))
#endif
#ifdef FAST_API
#define MA_unprotectTraversalStrategy(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _MA_unprotectTraversalStrategy(MA_TraversalStrategy *arg);
#define MA_unprotectTraversalStrategy(arg) (_MA_unprotectTraversalStrategy(arg))
#endif
#ifdef FAST_API
#define MA_protectTraversalType(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _MA_protectTraversalType(MA_TraversalType *arg);
#define MA_protectTraversalType(arg) (_MA_protectTraversalType(arg))
#endif
#ifdef FAST_API
#define MA_unprotectTraversalType(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _MA_unprotectTraversalType(MA_TraversalType *arg);
#define MA_unprotectTraversalType(arg) (_MA_unprotectTraversalType(arg))
#endif
#ifdef FAST_API
#define MA_protectTraversalContinuation(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _MA_protectTraversalContinuation(MA_TraversalContinuation *arg);
#define MA_protectTraversalContinuation(arg) (_MA_protectTraversalContinuation(arg))
#endif
#ifdef FAST_API
#define MA_unprotectTraversalContinuation(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _MA_unprotectTraversalContinuation(MA_TraversalContinuation *arg);
#define MA_unprotectTraversalContinuation(arg) (_MA_unprotectTraversalContinuation(arg))
#endif
#ifdef FAST_API
#define MA_protectFunId(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _MA_protectFunId(MA_FunId *arg);
#define MA_protectFunId(arg) (_MA_protectFunId(arg))
#endif
#ifdef FAST_API
#define MA_unprotectFunId(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _MA_unprotectFunId(MA_FunId *arg);
#define MA_unprotectFunId(arg) (_MA_unprotectFunId(arg))
#endif
#ifdef FAST_API
#define MA_protectVarId(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _MA_protectVarId(MA_VarId *arg);
#define MA_protectVarId(arg) (_MA_protectVarId(arg))
#endif
#ifdef FAST_API
#define MA_unprotectVarId(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _MA_unprotectVarId(MA_VarId *arg);
#define MA_unprotectVarId(arg) (_MA_unprotectVarId(arg))
#endif
#ifdef FAST_API
#define MA_protectModId(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _MA_protectModId(MA_ModId *arg);
#define MA_protectModId(arg) (_MA_protectModId(arg))
#endif
#ifdef FAST_API
#define MA_unprotectModId(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _MA_unprotectModId(MA_ModId *arg);
#define MA_unprotectModId(arg) (_MA_unprotectModId(arg))
#endif
#ifdef FAST_API
#define MA_protectTerm(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _MA_protectTerm(MA_Term *arg);
#define MA_protectTerm(arg) (_MA_protectTerm(arg))
#endif
#ifdef FAST_API
#define MA_unprotectTerm(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _MA_unprotectTerm(MA_Term *arg);
#define MA_unprotectTerm(arg) (_MA_unprotectTerm(arg))
#endif
#ifdef FAST_API
#define MA_protectTermList(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _MA_protectTermList(MA_TermList *arg);
#define MA_protectTermList(arg) (_MA_protectTermList(arg))
#endif
#ifdef FAST_API
#define MA_unprotectTermList(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _MA_unprotectTermList(MA_TermList *arg);
#define MA_unprotectTermList(arg) (_MA_unprotectTermList(arg))
#endif
#ifdef FAST_API
#define MA_protectSigArg(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _MA_protectSigArg(MA_SigArg *arg);
#define MA_protectSigArg(arg) (_MA_protectSigArg(arg))
#endif
#ifdef FAST_API
#define MA_unprotectSigArg(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _MA_unprotectSigArg(MA_SigArg *arg);
#define MA_unprotectSigArg(arg) (_MA_unprotectSigArg(arg))
#endif
#ifdef FAST_API
#define MA_protectFuncDef(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _MA_protectFuncDef(MA_FuncDef *arg);
#define MA_protectFuncDef(arg) (_MA_protectFuncDef(arg))
#endif
#ifdef FAST_API
#define MA_unprotectFuncDef(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _MA_unprotectFuncDef(MA_FuncDef *arg);
#define MA_unprotectFuncDef(arg) (_MA_unprotectFuncDef(arg))
#endif
#ifdef FAST_API
#define MA_protectAnnotations(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _MA_protectAnnotations(MA_Annotations *arg);
#define MA_protectAnnotations(arg) (_MA_protectAnnotations(arg))
#endif
#ifdef FAST_API
#define MA_unprotectAnnotations(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _MA_unprotectAnnotations(MA_Annotations *arg);
#define MA_unprotectAnnotations(arg) (_MA_unprotectAnnotations(arg))
#endif
#ifdef FAST_API
#define MA_protectSigArgList(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _MA_protectSigArgList(MA_SigArgList *arg);
#define MA_protectSigArgList(arg) (_MA_protectSigArgList(arg))
#endif
#ifdef FAST_API
#define MA_unprotectSigArgList(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _MA_unprotectSigArgList(MA_SigArgList *arg);
#define MA_unprotectSigArgList(arg) (_MA_unprotectSigArgList(arg))
#endif
#ifdef FAST_API
#define MA_protectFuncDefList(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _MA_protectFuncDefList(MA_FuncDefList *arg);
#define MA_protectFuncDefList(arg) (_MA_protectFuncDefList(arg))
#endif
#ifdef FAST_API
#define MA_unprotectFuncDefList(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _MA_unprotectFuncDefList(MA_FuncDefList *arg);
#define MA_unprotectFuncDefList(arg) (_MA_unprotectFuncDefList(arg))
#endif
#ifdef FAST_API
#define MA_protectRule(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _MA_protectRule(MA_Rule *arg);
#define MA_protectRule(arg) (_MA_protectRule(arg))
#endif
#ifdef FAST_API
#define MA_unprotectRule(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _MA_unprotectRule(MA_Rule *arg);
#define MA_unprotectRule(arg) (_MA_unprotectRule(arg))
#endif
#ifdef FAST_API
#define MA_protectRuleList(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _MA_protectRuleList(MA_RuleList *arg);
#define MA_protectRuleList(arg) (_MA_protectRuleList(arg))
#endif
#ifdef FAST_API
#define MA_unprotectRuleList(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _MA_unprotectRuleList(MA_RuleList *arg);
#define MA_unprotectRuleList(arg) (_MA_unprotectRuleList(arg))
#endif
#ifdef FAST_API
#define MA_protectCondList(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _MA_protectCondList(MA_CondList *arg);
#define MA_protectCondList(arg) (_MA_protectCondList(arg))
#endif
#ifdef FAST_API
#define MA_unprotectCondList(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _MA_unprotectCondList(MA_CondList *arg);
#define MA_unprotectCondList(arg) (_MA_unprotectCondList(arg))
#endif
#ifdef FAST_API
#define MA_protectCond(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _MA_protectCond(MA_Cond *arg);
#define MA_protectCond(arg) (_MA_protectCond(arg))
#endif
#ifdef FAST_API
#define MA_unprotectCond(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _MA_unprotectCond(MA_Cond *arg);
#define MA_unprotectCond(arg) (_MA_unprotectCond(arg))
#endif
#ifdef FAST_API
#define MA_protectSignatureOpt(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _MA_protectSignatureOpt(MA_SignatureOpt *arg);
#define MA_protectSignatureOpt(arg) (_MA_protectSignatureOpt(arg))
#endif
#ifdef FAST_API
#define MA_unprotectSignatureOpt(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _MA_unprotectSignatureOpt(MA_SignatureOpt *arg);
#define MA_unprotectSignatureOpt(arg) (_MA_unprotectSignatureOpt(arg))
#endif
#ifdef FAST_API
#define MA_protectRulesOpt(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _MA_protectRulesOpt(MA_RulesOpt *arg);
#define MA_protectRulesOpt(arg) (_MA_protectRulesOpt(arg))
#endif
#ifdef FAST_API
#define MA_unprotectRulesOpt(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _MA_unprotectRulesOpt(MA_RulesOpt *arg);
#define MA_unprotectRulesOpt(arg) (_MA_unprotectRulesOpt(arg))
#endif
#ifdef FAST_API
#define MA_protectModule(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _MA_protectModule(MA_Module *arg);
#define MA_protectModule(arg) (_MA_protectModule(arg))
#endif
#ifdef FAST_API
#define MA_unprotectModule(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _MA_unprotectModule(MA_Module *arg);
#define MA_unprotectModule(arg) (_MA_unprotectModule(arg))
#endif
#ifdef FAST_API
#define MA_protectTermArgs(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _MA_protectTermArgs(MA_TermArgs *arg);
#define MA_protectTermArgs(arg) (_MA_protectTermArgs(arg))
#endif
#ifdef FAST_API
#define MA_unprotectTermArgs(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _MA_unprotectTermArgs(MA_TermArgs *arg);
#define MA_unprotectTermArgs(arg) (_MA_unprotectTermArgs(arg))
#endif
#ifdef FAST_API
#define MA_protectTermElems(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _MA_protectTermElems(MA_TermElems *arg);
#define MA_protectTermElems(arg) (_MA_protectTermElems(arg))
#endif
#ifdef FAST_API
#define MA_unprotectTermElems(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _MA_unprotectTermElems(MA_TermElems *arg);
#define MA_unprotectTermElems(arg) (_MA_unprotectTermElems(arg))
#endif
#ifdef FAST_API
#define MA_protectSigArgArgs(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _MA_protectSigArgArgs(MA_SigArgArgs *arg);
#define MA_protectSigArgArgs(arg) (_MA_protectSigArgArgs(arg))
#endif
#ifdef FAST_API
#define MA_unprotectSigArgArgs(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _MA_unprotectSigArgArgs(MA_SigArgArgs *arg);
#define MA_unprotectSigArgArgs(arg) (_MA_unprotectSigArgArgs(arg))
#endif
#ifdef FAST_API
#define MA_protectTermAttrs(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _MA_protectTermAttrs(MA_TermAttrs *arg);
#define MA_protectTermAttrs(arg) (_MA_protectTermAttrs(arg))
#endif
#ifdef FAST_API
#define MA_unprotectTermAttrs(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _MA_unprotectTermAttrs(MA_TermAttrs *arg);
#define MA_unprotectTermAttrs(arg) (_MA_unprotectTermAttrs(arg))
#endif
#ifdef FAST_API
#define MA_protectFuncDefDefs(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _MA_protectFuncDefDefs(MA_FuncDefDefs *arg);
#define MA_protectFuncDefDefs(arg) (_MA_protectFuncDefDefs(arg))
#endif
#ifdef FAST_API
#define MA_unprotectFuncDefDefs(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _MA_unprotectFuncDefDefs(MA_FuncDefDefs *arg);
#define MA_unprotectFuncDefDefs(arg) (_MA_unprotectFuncDefDefs(arg))
#endif
#ifdef FAST_API
#define MA_protectRuleRules(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _MA_protectRuleRules(MA_RuleRules *arg);
#define MA_protectRuleRules(arg) (_MA_protectRuleRules(arg))
#endif
#ifdef FAST_API
#define MA_unprotectRuleRules(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _MA_unprotectRuleRules(MA_RuleRules *arg);
#define MA_unprotectRuleRules(arg) (_MA_unprotectRuleRules(arg))
#endif
#ifdef FAST_API
#define MA_protectCondConds(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _MA_protectCondConds(MA_CondConds *arg);
#define MA_protectCondConds(arg) (_MA_protectCondConds(arg))
#endif
#ifdef FAST_API
#define MA_unprotectCondConds(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _MA_unprotectCondConds(MA_CondConds *arg);
#define MA_unprotectCondConds(arg) (_MA_unprotectCondConds(arg))
#endif
#ifdef FAST_API
#define MA_protectLexLayout(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _MA_protectLexLayout(MA_LexLayout *arg);
#define MA_protectLexLayout(arg) (_MA_protectLexLayout(arg))
#endif
#ifdef FAST_API
#define MA_unprotectLexLayout(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _MA_unprotectLexLayout(MA_LexLayout *arg);
#define MA_unprotectLexLayout(arg) (_MA_unprotectLexLayout(arg))
#endif
#ifdef FAST_API
#define MA_protectLexStrChar(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _MA_protectLexStrChar(MA_LexStrChar *arg);
#define MA_protectLexStrChar(arg) (_MA_protectLexStrChar(arg))
#endif
#ifdef FAST_API
#define MA_unprotectLexStrChar(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _MA_unprotectLexStrChar(MA_LexStrChar *arg);
#define MA_unprotectLexStrChar(arg) (_MA_unprotectLexStrChar(arg))
#endif
#ifdef FAST_API
#define MA_protectStrChar(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _MA_protectStrChar(MA_StrChar *arg);
#define MA_protectStrChar(arg) (_MA_protectStrChar(arg))
#endif
#ifdef FAST_API
#define MA_unprotectStrChar(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _MA_unprotectStrChar(MA_StrChar *arg);
#define MA_unprotectStrChar(arg) (_MA_unprotectStrChar(arg))
#endif
#ifdef FAST_API
#define MA_protectLexStrCon(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _MA_protectLexStrCon(MA_LexStrCon *arg);
#define MA_protectLexStrCon(arg) (_MA_protectLexStrCon(arg))
#endif
#ifdef FAST_API
#define MA_unprotectLexStrCon(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _MA_unprotectLexStrCon(MA_LexStrCon *arg);
#define MA_unprotectLexStrCon(arg) (_MA_unprotectLexStrCon(arg))
#endif
#ifdef FAST_API
#define MA_protectStrCon(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _MA_protectStrCon(MA_StrCon *arg);
#define MA_protectStrCon(arg) (_MA_protectStrCon(arg))
#endif
#ifdef FAST_API
#define MA_unprotectStrCon(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _MA_unprotectStrCon(MA_StrCon *arg);
#define MA_unprotectStrCon(arg) (_MA_unprotectStrCon(arg))
#endif
#ifdef FAST_API
#define MA_protectLexStrCharChars(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _MA_protectLexStrCharChars(MA_LexStrCharChars *arg);
#define MA_protectLexStrCharChars(arg) (_MA_protectLexStrCharChars(arg))
#endif
#ifdef FAST_API
#define MA_unprotectLexStrCharChars(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _MA_unprotectLexStrCharChars(MA_LexStrCharChars *arg);
#define MA_unprotectLexStrCharChars(arg) (_MA_unprotectLexStrCharChars(arg))
#endif
#ifdef FAST_API
#define MA_protectLexNatCon(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _MA_protectLexNatCon(MA_LexNatCon *arg);
#define MA_protectLexNatCon(arg) (_MA_protectLexNatCon(arg))
#endif
#ifdef FAST_API
#define MA_unprotectLexNatCon(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _MA_unprotectLexNatCon(MA_LexNatCon *arg);
#define MA_unprotectLexNatCon(arg) (_MA_unprotectLexNatCon(arg))
#endif
#ifdef FAST_API
#define MA_protectNatCon(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _MA_protectNatCon(MA_NatCon *arg);
#define MA_protectNatCon(arg) (_MA_protectNatCon(arg))
#endif
#ifdef FAST_API
#define MA_unprotectNatCon(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _MA_unprotectNatCon(MA_NatCon *arg);
#define MA_unprotectNatCon(arg) (_MA_unprotectNatCon(arg))
#endif
#ifdef FAST_API
#define MA_protectLexIdCon(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _MA_protectLexIdCon(MA_LexIdCon *arg);
#define MA_protectLexIdCon(arg) (_MA_protectLexIdCon(arg))
#endif
#ifdef FAST_API
#define MA_unprotectLexIdCon(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _MA_unprotectLexIdCon(MA_LexIdCon *arg);
#define MA_unprotectLexIdCon(arg) (_MA_unprotectLexIdCon(arg))
#endif
#ifdef FAST_API
#define MA_protectIdCon(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _MA_protectIdCon(MA_IdCon *arg);
#define MA_protectIdCon(arg) (_MA_protectIdCon(arg))
#endif
#ifdef FAST_API
#define MA_unprotectIdCon(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _MA_unprotectIdCon(MA_IdCon *arg);
#define MA_unprotectIdCon(arg) (_MA_unprotectIdCon(arg))
#endif
#ifdef FAST_API
#define MA_OptLayoutFromTerm(t) ((MA_OptLayout)(t))
#else
MA_OptLayout _MA_OptLayoutFromTerm(ATerm t);
#define MA_OptLayoutFromTerm(t) (_MA_OptLayoutFromTerm(t))
#endif
#ifdef FAST_API
#define MA_OptLayoutToTerm(arg) ((ATerm)(arg))
#else
ATerm _MA_OptLayoutToTerm(MA_OptLayout arg);
#define MA_OptLayoutToTerm(arg) (_MA_OptLayoutToTerm(arg))
#endif
#ifdef FAST_API
#define MA_LayoutFromTerm(t) ((MA_Layout)(t))
#else
MA_Layout _MA_LayoutFromTerm(ATerm t);
#define MA_LayoutFromTerm(t) (_MA_LayoutFromTerm(t))
#endif
#ifdef FAST_API
#define MA_LayoutToTerm(arg) ((ATerm)(arg))
#else
ATerm _MA_LayoutToTerm(MA_Layout arg);
#define MA_LayoutToTerm(arg) (_MA_LayoutToTerm(arg))
#endif
#ifdef FAST_API
#define MA_LexLayoutListFromTerm(t) ((MA_LexLayoutList)(t))
#else
MA_LexLayoutList _MA_LexLayoutListFromTerm(ATerm t);
#define MA_LexLayoutListFromTerm(t) (_MA_LexLayoutListFromTerm(t))
#endif
#ifdef FAST_API
#define MA_LexLayoutListToTerm(arg) ((ATerm)(arg))
#else
ATerm _MA_LexLayoutListToTerm(MA_LexLayoutList arg);
#define MA_LexLayoutListToTerm(arg) (_MA_LexLayoutListToTerm(arg))
#endif
#ifdef FAST_API
#define MA_TraversalStrategyFromTerm(t) ((MA_TraversalStrategy)(t))
#else
MA_TraversalStrategy _MA_TraversalStrategyFromTerm(ATerm t);
#define MA_TraversalStrategyFromTerm(t) (_MA_TraversalStrategyFromTerm(t))
#endif
#ifdef FAST_API
#define MA_TraversalStrategyToTerm(arg) ((ATerm)(arg))
#else
ATerm _MA_TraversalStrategyToTerm(MA_TraversalStrategy arg);
#define MA_TraversalStrategyToTerm(arg) (_MA_TraversalStrategyToTerm(arg))
#endif
#ifdef FAST_API
#define MA_TraversalTypeFromTerm(t) ((MA_TraversalType)(t))
#else
MA_TraversalType _MA_TraversalTypeFromTerm(ATerm t);
#define MA_TraversalTypeFromTerm(t) (_MA_TraversalTypeFromTerm(t))
#endif
#ifdef FAST_API
#define MA_TraversalTypeToTerm(arg) ((ATerm)(arg))
#else
ATerm _MA_TraversalTypeToTerm(MA_TraversalType arg);
#define MA_TraversalTypeToTerm(arg) (_MA_TraversalTypeToTerm(arg))
#endif
#ifdef FAST_API
#define MA_TraversalContinuationFromTerm(t) ((MA_TraversalContinuation)(t))
#else
MA_TraversalContinuation _MA_TraversalContinuationFromTerm(ATerm t);
#define MA_TraversalContinuationFromTerm(t) (_MA_TraversalContinuationFromTerm(t))
#endif
#ifdef FAST_API
#define MA_TraversalContinuationToTerm(arg) ((ATerm)(arg))
#else
ATerm _MA_TraversalContinuationToTerm(MA_TraversalContinuation arg);
#define MA_TraversalContinuationToTerm(arg) (_MA_TraversalContinuationToTerm(arg))
#endif
#ifdef FAST_API
#define MA_FunIdFromTerm(t) ((MA_FunId)(t))
#else
MA_FunId _MA_FunIdFromTerm(ATerm t);
#define MA_FunIdFromTerm(t) (_MA_FunIdFromTerm(t))
#endif
#ifdef FAST_API
#define MA_FunIdToTerm(arg) ((ATerm)(arg))
#else
ATerm _MA_FunIdToTerm(MA_FunId arg);
#define MA_FunIdToTerm(arg) (_MA_FunIdToTerm(arg))
#endif
#ifdef FAST_API
#define MA_VarIdFromTerm(t) ((MA_VarId)(t))
#else
MA_VarId _MA_VarIdFromTerm(ATerm t);
#define MA_VarIdFromTerm(t) (_MA_VarIdFromTerm(t))
#endif
#ifdef FAST_API
#define MA_VarIdToTerm(arg) ((ATerm)(arg))
#else
ATerm _MA_VarIdToTerm(MA_VarId arg);
#define MA_VarIdToTerm(arg) (_MA_VarIdToTerm(arg))
#endif
#ifdef FAST_API
#define MA_ModIdFromTerm(t) ((MA_ModId)(t))
#else
MA_ModId _MA_ModIdFromTerm(ATerm t);
#define MA_ModIdFromTerm(t) (_MA_ModIdFromTerm(t))
#endif
#ifdef FAST_API
#define MA_ModIdToTerm(arg) ((ATerm)(arg))
#else
ATerm _MA_ModIdToTerm(MA_ModId arg);
#define MA_ModIdToTerm(arg) (_MA_ModIdToTerm(arg))
#endif
#ifdef FAST_API
#define MA_TermFromTerm(t) ((MA_Term)(t))
#else
MA_Term _MA_TermFromTerm(ATerm t);
#define MA_TermFromTerm(t) (_MA_TermFromTerm(t))
#endif
#ifdef FAST_API
#define MA_TermToTerm(arg) ((ATerm)(arg))
#else
ATerm _MA_TermToTerm(MA_Term arg);
#define MA_TermToTerm(arg) (_MA_TermToTerm(arg))
#endif
#ifdef FAST_API
#define MA_TermListFromTerm(t) ((MA_TermList)(t))
#else
MA_TermList _MA_TermListFromTerm(ATerm t);
#define MA_TermListFromTerm(t) (_MA_TermListFromTerm(t))
#endif
#ifdef FAST_API
#define MA_TermListToTerm(arg) ((ATerm)(arg))
#else
ATerm _MA_TermListToTerm(MA_TermList arg);
#define MA_TermListToTerm(arg) (_MA_TermListToTerm(arg))
#endif
#ifdef FAST_API
#define MA_SigArgFromTerm(t) ((MA_SigArg)(t))
#else
MA_SigArg _MA_SigArgFromTerm(ATerm t);
#define MA_SigArgFromTerm(t) (_MA_SigArgFromTerm(t))
#endif
#ifdef FAST_API
#define MA_SigArgToTerm(arg) ((ATerm)(arg))
#else
ATerm _MA_SigArgToTerm(MA_SigArg arg);
#define MA_SigArgToTerm(arg) (_MA_SigArgToTerm(arg))
#endif
#ifdef FAST_API
#define MA_FuncDefFromTerm(t) ((MA_FuncDef)(t))
#else
MA_FuncDef _MA_FuncDefFromTerm(ATerm t);
#define MA_FuncDefFromTerm(t) (_MA_FuncDefFromTerm(t))
#endif
#ifdef FAST_API
#define MA_FuncDefToTerm(arg) ((ATerm)(arg))
#else
ATerm _MA_FuncDefToTerm(MA_FuncDef arg);
#define MA_FuncDefToTerm(arg) (_MA_FuncDefToTerm(arg))
#endif
#ifdef FAST_API
#define MA_AnnotationsFromTerm(t) ((MA_Annotations)(t))
#else
MA_Annotations _MA_AnnotationsFromTerm(ATerm t);
#define MA_AnnotationsFromTerm(t) (_MA_AnnotationsFromTerm(t))
#endif
#ifdef FAST_API
#define MA_AnnotationsToTerm(arg) ((ATerm)(arg))
#else
ATerm _MA_AnnotationsToTerm(MA_Annotations arg);
#define MA_AnnotationsToTerm(arg) (_MA_AnnotationsToTerm(arg))
#endif
#ifdef FAST_API
#define MA_SigArgListFromTerm(t) ((MA_SigArgList)(t))
#else
MA_SigArgList _MA_SigArgListFromTerm(ATerm t);
#define MA_SigArgListFromTerm(t) (_MA_SigArgListFromTerm(t))
#endif
#ifdef FAST_API
#define MA_SigArgListToTerm(arg) ((ATerm)(arg))
#else
ATerm _MA_SigArgListToTerm(MA_SigArgList arg);
#define MA_SigArgListToTerm(arg) (_MA_SigArgListToTerm(arg))
#endif
#ifdef FAST_API
#define MA_FuncDefListFromTerm(t) ((MA_FuncDefList)(t))
#else
MA_FuncDefList _MA_FuncDefListFromTerm(ATerm t);
#define MA_FuncDefListFromTerm(t) (_MA_FuncDefListFromTerm(t))
#endif
#ifdef FAST_API
#define MA_FuncDefListToTerm(arg) ((ATerm)(arg))
#else
ATerm _MA_FuncDefListToTerm(MA_FuncDefList arg);
#define MA_FuncDefListToTerm(arg) (_MA_FuncDefListToTerm(arg))
#endif
#ifdef FAST_API
#define MA_RuleFromTerm(t) ((MA_Rule)(t))
#else
MA_Rule _MA_RuleFromTerm(ATerm t);
#define MA_RuleFromTerm(t) (_MA_RuleFromTerm(t))
#endif
#ifdef FAST_API
#define MA_RuleToTerm(arg) ((ATerm)(arg))
#else
ATerm _MA_RuleToTerm(MA_Rule arg);
#define MA_RuleToTerm(arg) (_MA_RuleToTerm(arg))
#endif
#ifdef FAST_API
#define MA_RuleListFromTerm(t) ((MA_RuleList)(t))
#else
MA_RuleList _MA_RuleListFromTerm(ATerm t);
#define MA_RuleListFromTerm(t) (_MA_RuleListFromTerm(t))
#endif
#ifdef FAST_API
#define MA_RuleListToTerm(arg) ((ATerm)(arg))
#else
ATerm _MA_RuleListToTerm(MA_RuleList arg);
#define MA_RuleListToTerm(arg) (_MA_RuleListToTerm(arg))
#endif
#ifdef FAST_API
#define MA_CondListFromTerm(t) ((MA_CondList)(t))
#else
MA_CondList _MA_CondListFromTerm(ATerm t);
#define MA_CondListFromTerm(t) (_MA_CondListFromTerm(t))
#endif
#ifdef FAST_API
#define MA_CondListToTerm(arg) ((ATerm)(arg))
#else
ATerm _MA_CondListToTerm(MA_CondList arg);
#define MA_CondListToTerm(arg) (_MA_CondListToTerm(arg))
#endif
#ifdef FAST_API
#define MA_CondFromTerm(t) ((MA_Cond)(t))
#else
MA_Cond _MA_CondFromTerm(ATerm t);
#define MA_CondFromTerm(t) (_MA_CondFromTerm(t))
#endif
#ifdef FAST_API
#define MA_CondToTerm(arg) ((ATerm)(arg))
#else
ATerm _MA_CondToTerm(MA_Cond arg);
#define MA_CondToTerm(arg) (_MA_CondToTerm(arg))
#endif
#ifdef FAST_API
#define MA_SignatureOptFromTerm(t) ((MA_SignatureOpt)(t))
#else
MA_SignatureOpt _MA_SignatureOptFromTerm(ATerm t);
#define MA_SignatureOptFromTerm(t) (_MA_SignatureOptFromTerm(t))
#endif
#ifdef FAST_API
#define MA_SignatureOptToTerm(arg) ((ATerm)(arg))
#else
ATerm _MA_SignatureOptToTerm(MA_SignatureOpt arg);
#define MA_SignatureOptToTerm(arg) (_MA_SignatureOptToTerm(arg))
#endif
#ifdef FAST_API
#define MA_RulesOptFromTerm(t) ((MA_RulesOpt)(t))
#else
MA_RulesOpt _MA_RulesOptFromTerm(ATerm t);
#define MA_RulesOptFromTerm(t) (_MA_RulesOptFromTerm(t))
#endif
#ifdef FAST_API
#define MA_RulesOptToTerm(arg) ((ATerm)(arg))
#else
ATerm _MA_RulesOptToTerm(MA_RulesOpt arg);
#define MA_RulesOptToTerm(arg) (_MA_RulesOptToTerm(arg))
#endif
#ifdef FAST_API
#define MA_ModuleFromTerm(t) ((MA_Module)(t))
#else
MA_Module _MA_ModuleFromTerm(ATerm t);
#define MA_ModuleFromTerm(t) (_MA_ModuleFromTerm(t))
#endif
#ifdef FAST_API
#define MA_ModuleToTerm(arg) ((ATerm)(arg))
#else
ATerm _MA_ModuleToTerm(MA_Module arg);
#define MA_ModuleToTerm(arg) (_MA_ModuleToTerm(arg))
#endif
#ifdef FAST_API
#define MA_TermArgsFromTerm(t) ((MA_TermArgs)(t))
#else
MA_TermArgs _MA_TermArgsFromTerm(ATerm t);
#define MA_TermArgsFromTerm(t) (_MA_TermArgsFromTerm(t))
#endif
#ifdef FAST_API
#define MA_TermArgsToTerm(arg) ((ATerm)(arg))
#else
ATerm _MA_TermArgsToTerm(MA_TermArgs arg);
#define MA_TermArgsToTerm(arg) (_MA_TermArgsToTerm(arg))
#endif
#ifdef FAST_API
#define MA_TermElemsFromTerm(t) ((MA_TermElems)(t))
#else
MA_TermElems _MA_TermElemsFromTerm(ATerm t);
#define MA_TermElemsFromTerm(t) (_MA_TermElemsFromTerm(t))
#endif
#ifdef FAST_API
#define MA_TermElemsToTerm(arg) ((ATerm)(arg))
#else
ATerm _MA_TermElemsToTerm(MA_TermElems arg);
#define MA_TermElemsToTerm(arg) (_MA_TermElemsToTerm(arg))
#endif
#ifdef FAST_API
#define MA_SigArgArgsFromTerm(t) ((MA_SigArgArgs)(t))
#else
MA_SigArgArgs _MA_SigArgArgsFromTerm(ATerm t);
#define MA_SigArgArgsFromTerm(t) (_MA_SigArgArgsFromTerm(t))
#endif
#ifdef FAST_API
#define MA_SigArgArgsToTerm(arg) ((ATerm)(arg))
#else
ATerm _MA_SigArgArgsToTerm(MA_SigArgArgs arg);
#define MA_SigArgArgsToTerm(arg) (_MA_SigArgArgsToTerm(arg))
#endif
#ifdef FAST_API
#define MA_TermAttrsFromTerm(t) ((MA_TermAttrs)(t))
#else
MA_TermAttrs _MA_TermAttrsFromTerm(ATerm t);
#define MA_TermAttrsFromTerm(t) (_MA_TermAttrsFromTerm(t))
#endif
#ifdef FAST_API
#define MA_TermAttrsToTerm(arg) ((ATerm)(arg))
#else
ATerm _MA_TermAttrsToTerm(MA_TermAttrs arg);
#define MA_TermAttrsToTerm(arg) (_MA_TermAttrsToTerm(arg))
#endif
#ifdef FAST_API
#define MA_FuncDefDefsFromTerm(t) ((MA_FuncDefDefs)(t))
#else
MA_FuncDefDefs _MA_FuncDefDefsFromTerm(ATerm t);
#define MA_FuncDefDefsFromTerm(t) (_MA_FuncDefDefsFromTerm(t))
#endif
#ifdef FAST_API
#define MA_FuncDefDefsToTerm(arg) ((ATerm)(arg))
#else
ATerm _MA_FuncDefDefsToTerm(MA_FuncDefDefs arg);
#define MA_FuncDefDefsToTerm(arg) (_MA_FuncDefDefsToTerm(arg))
#endif
#ifdef FAST_API
#define MA_RuleRulesFromTerm(t) ((MA_RuleRules)(t))
#else
MA_RuleRules _MA_RuleRulesFromTerm(ATerm t);
#define MA_RuleRulesFromTerm(t) (_MA_RuleRulesFromTerm(t))
#endif
#ifdef FAST_API
#define MA_RuleRulesToTerm(arg) ((ATerm)(arg))
#else
ATerm _MA_RuleRulesToTerm(MA_RuleRules arg);
#define MA_RuleRulesToTerm(arg) (_MA_RuleRulesToTerm(arg))
#endif
#ifdef FAST_API
#define MA_CondCondsFromTerm(t) ((MA_CondConds)(t))
#else
MA_CondConds _MA_CondCondsFromTerm(ATerm t);
#define MA_CondCondsFromTerm(t) (_MA_CondCondsFromTerm(t))
#endif
#ifdef FAST_API
#define MA_CondCondsToTerm(arg) ((ATerm)(arg))
#else
ATerm _MA_CondCondsToTerm(MA_CondConds arg);
#define MA_CondCondsToTerm(arg) (_MA_CondCondsToTerm(arg))
#endif
#ifdef FAST_API
#define MA_LexLayoutFromTerm(t) ((MA_LexLayout)(t))
#else
MA_LexLayout _MA_LexLayoutFromTerm(ATerm t);
#define MA_LexLayoutFromTerm(t) (_MA_LexLayoutFromTerm(t))
#endif
#ifdef FAST_API
#define MA_LexLayoutToTerm(arg) ((ATerm)(arg))
#else
ATerm _MA_LexLayoutToTerm(MA_LexLayout arg);
#define MA_LexLayoutToTerm(arg) (_MA_LexLayoutToTerm(arg))
#endif
#ifdef FAST_API
#define MA_LexStrCharFromTerm(t) ((MA_LexStrChar)(t))
#else
MA_LexStrChar _MA_LexStrCharFromTerm(ATerm t);
#define MA_LexStrCharFromTerm(t) (_MA_LexStrCharFromTerm(t))
#endif
#ifdef FAST_API
#define MA_LexStrCharToTerm(arg) ((ATerm)(arg))
#else
ATerm _MA_LexStrCharToTerm(MA_LexStrChar arg);
#define MA_LexStrCharToTerm(arg) (_MA_LexStrCharToTerm(arg))
#endif
#ifdef FAST_API
#define MA_StrCharFromTerm(t) ((MA_StrChar)(t))
#else
MA_StrChar _MA_StrCharFromTerm(ATerm t);
#define MA_StrCharFromTerm(t) (_MA_StrCharFromTerm(t))
#endif
#ifdef FAST_API
#define MA_StrCharToTerm(arg) ((ATerm)(arg))
#else
ATerm _MA_StrCharToTerm(MA_StrChar arg);
#define MA_StrCharToTerm(arg) (_MA_StrCharToTerm(arg))
#endif
#ifdef FAST_API
#define MA_LexStrConFromTerm(t) ((MA_LexStrCon)(t))
#else
MA_LexStrCon _MA_LexStrConFromTerm(ATerm t);
#define MA_LexStrConFromTerm(t) (_MA_LexStrConFromTerm(t))
#endif
#ifdef FAST_API
#define MA_LexStrConToTerm(arg) ((ATerm)(arg))
#else
ATerm _MA_LexStrConToTerm(MA_LexStrCon arg);
#define MA_LexStrConToTerm(arg) (_MA_LexStrConToTerm(arg))
#endif
#ifdef FAST_API
#define MA_StrConFromTerm(t) ((MA_StrCon)(t))
#else
MA_StrCon _MA_StrConFromTerm(ATerm t);
#define MA_StrConFromTerm(t) (_MA_StrConFromTerm(t))
#endif
#ifdef FAST_API
#define MA_StrConToTerm(arg) ((ATerm)(arg))
#else
ATerm _MA_StrConToTerm(MA_StrCon arg);
#define MA_StrConToTerm(arg) (_MA_StrConToTerm(arg))
#endif
#ifdef FAST_API
#define MA_LexStrCharCharsFromTerm(t) ((MA_LexStrCharChars)(t))
#else
MA_LexStrCharChars _MA_LexStrCharCharsFromTerm(ATerm t);
#define MA_LexStrCharCharsFromTerm(t) (_MA_LexStrCharCharsFromTerm(t))
#endif
#ifdef FAST_API
#define MA_LexStrCharCharsToTerm(arg) ((ATerm)(arg))
#else
ATerm _MA_LexStrCharCharsToTerm(MA_LexStrCharChars arg);
#define MA_LexStrCharCharsToTerm(arg) (_MA_LexStrCharCharsToTerm(arg))
#endif
#ifdef FAST_API
#define MA_LexNatConFromTerm(t) ((MA_LexNatCon)(t))
#else
MA_LexNatCon _MA_LexNatConFromTerm(ATerm t);
#define MA_LexNatConFromTerm(t) (_MA_LexNatConFromTerm(t))
#endif
#ifdef FAST_API
#define MA_LexNatConToTerm(arg) ((ATerm)(arg))
#else
ATerm _MA_LexNatConToTerm(MA_LexNatCon arg);
#define MA_LexNatConToTerm(arg) (_MA_LexNatConToTerm(arg))
#endif
#ifdef FAST_API
#define MA_NatConFromTerm(t) ((MA_NatCon)(t))
#else
MA_NatCon _MA_NatConFromTerm(ATerm t);
#define MA_NatConFromTerm(t) (_MA_NatConFromTerm(t))
#endif
#ifdef FAST_API
#define MA_NatConToTerm(arg) ((ATerm)(arg))
#else
ATerm _MA_NatConToTerm(MA_NatCon arg);
#define MA_NatConToTerm(arg) (_MA_NatConToTerm(arg))
#endif
#ifdef FAST_API
#define MA_LexIdConFromTerm(t) ((MA_LexIdCon)(t))
#else
MA_LexIdCon _MA_LexIdConFromTerm(ATerm t);
#define MA_LexIdConFromTerm(t) (_MA_LexIdConFromTerm(t))
#endif
#ifdef FAST_API
#define MA_LexIdConToTerm(arg) ((ATerm)(arg))
#else
ATerm _MA_LexIdConToTerm(MA_LexIdCon arg);
#define MA_LexIdConToTerm(arg) (_MA_LexIdConToTerm(arg))
#endif
#ifdef FAST_API
#define MA_IdConFromTerm(t) ((MA_IdCon)(t))
#else
MA_IdCon _MA_IdConFromTerm(ATerm t);
#define MA_IdConFromTerm(t) (_MA_IdConFromTerm(t))
#endif
#ifdef FAST_API
#define MA_IdConToTerm(arg) ((ATerm)(arg))
#else
ATerm _MA_IdConToTerm(MA_IdCon arg);
#define MA_IdConToTerm(arg) (_MA_IdConToTerm(arg))
#endif
#ifdef FAST_API
#define MA_getLexLayoutListLength(arg) (ATgetLength((ATermList) (arg)))
#else
int _MA_getLexLayoutListLength(MA_LexLayoutList arg);
#define MA_getLexLayoutListLength(arg) (_MA_getLexLayoutListLength(arg))
#endif
#ifdef FAST_API
#define MA_reverseLexLayoutList(arg) ((MA_LexLayoutList) ATreverse((ATermList) (arg)))
#else
MA_LexLayoutList _MA_reverseLexLayoutList(MA_LexLayoutList arg);
#define MA_reverseLexLayoutList(arg) (_MA_reverseLexLayoutList(arg))
#endif
#ifdef FAST_API
#define MA_appendLexLayoutList(arg, elem) ((MA_LexLayoutList) ATappend((ATermList) (arg), (ATerm) (((ATerm) elem))))
#else
MA_LexLayoutList _MA_appendLexLayoutList(MA_LexLayoutList arg, MA_LexLayout elem);
#define MA_appendLexLayoutList(arg, elem) (_MA_appendLexLayoutList(arg, elem))
#endif
#ifdef FAST_API
#define MA_concatLexLayoutList(arg0, arg1) ((MA_LexLayoutList) ATconcat((ATermList) (arg0), (ATermList) (arg1)))
#else
MA_LexLayoutList _MA_concatLexLayoutList(MA_LexLayoutList arg0, MA_LexLayoutList arg1);
#define MA_concatLexLayoutList(arg0, arg1) (_MA_concatLexLayoutList(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_sliceLexLayoutList(arg, start, end) ((MA_LexLayoutList) ATgetSlice((ATermList) (arg), (start), (end)))
#else
MA_LexLayoutList _MA_sliceLexLayoutList(MA_LexLayoutList arg, int start, int end);
#define MA_sliceLexLayoutList(arg, start, end) (_MA_sliceLexLayoutList(arg, start, end))
#endif
#ifdef FAST_API
#define MA_getLexLayoutListLexLayoutAt(arg, index) ((MA_LexLayout) (ATelementAt((ATermList) arg,index)))
#else
MA_LexLayout _MA_getLexLayoutListLexLayoutAt(MA_LexLayoutList arg, int index);
#define MA_getLexLayoutListLexLayoutAt(arg, index) (_MA_getLexLayoutListLexLayoutAt(arg, index))
#endif
#ifdef FAST_API
#define MA_replaceLexLayoutListLexLayoutAt(arg, elem, index) ((MA_LexLayoutList) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index)))
#else
MA_LexLayoutList _MA_replaceLexLayoutListLexLayoutAt(MA_LexLayoutList arg, MA_LexLayout elem, int index);
#define MA_replaceLexLayoutListLexLayoutAt(arg, elem, index) (_MA_replaceLexLayoutListLexLayoutAt(arg, elem, index))
#endif
#ifdef FAST_API
#define MA_makeLexLayoutList2(elem1,  elem2) ((MA_LexLayoutList) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) (((ATerm) elem2))))
#else
MA_LexLayoutList _MA_makeLexLayoutList2(MA_LexLayout elem1, MA_LexLayout elem2);
#define MA_makeLexLayoutList2(elem1,  elem2) (_MA_makeLexLayoutList2(elem1,  elem2))
#endif
#ifdef FAST_API
#define MA_makeLexLayoutList3(elem1, elem2,  elem3) ((MA_LexLayoutList) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) (((ATerm) elem3))))
#else
MA_LexLayoutList _MA_makeLexLayoutList3(MA_LexLayout elem1, MA_LexLayout elem2, MA_LexLayout elem3);
#define MA_makeLexLayoutList3(elem1, elem2,  elem3) (_MA_makeLexLayoutList3(elem1, elem2,  elem3))
#endif
#ifdef FAST_API
#define MA_makeLexLayoutList4(elem1, elem2, elem3,  elem4) ((MA_LexLayoutList) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) (((ATerm) elem4))))
#else
MA_LexLayoutList _MA_makeLexLayoutList4(MA_LexLayout elem1, MA_LexLayout elem2, MA_LexLayout elem3, MA_LexLayout elem4);
#define MA_makeLexLayoutList4(elem1, elem2, elem3,  elem4) (_MA_makeLexLayoutList4(elem1, elem2, elem3,  elem4))
#endif
#ifdef FAST_API
#define MA_makeLexLayoutList5(elem1, elem2, elem3, elem4,  elem5) ((MA_LexLayoutList) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) (((ATerm) elem5))))
#else
MA_LexLayoutList _MA_makeLexLayoutList5(MA_LexLayout elem1, MA_LexLayout elem2, MA_LexLayout elem3, MA_LexLayout elem4, MA_LexLayout elem5);
#define MA_makeLexLayoutList5(elem1, elem2, elem3, elem4,  elem5) (_MA_makeLexLayoutList5(elem1, elem2, elem3, elem4,  elem5))
#endif
#ifdef FAST_API
#define MA_makeLexLayoutList6(elem1, elem2, elem3, elem4, elem5,  elem6) ((MA_LexLayoutList) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) (((ATerm) elem6))))
#else
MA_LexLayoutList _MA_makeLexLayoutList6(MA_LexLayout elem1, MA_LexLayout elem2, MA_LexLayout elem3, MA_LexLayout elem4, MA_LexLayout elem5, MA_LexLayout elem6);
#define MA_makeLexLayoutList6(elem1, elem2, elem3, elem4, elem5,  elem6) (_MA_makeLexLayoutList6(elem1, elem2, elem3, elem4, elem5,  elem6))
#endif
#ifdef FAST_API
#define MA_getTermArgsLength(arg) ((ATisEmpty((ATermList) (arg)) ? 0 : (ATgetLength((ATermList) (arg)) / 4) + 1))
#else
int _MA_getTermArgsLength(MA_TermArgs arg);
#define MA_getTermArgsLength(arg) (_MA_getTermArgsLength(arg))
#endif
MA_TermArgs MA_reverseTermArgs(MA_TermArgs arg);
MA_TermArgs MA_appendTermArgs(MA_TermArgs arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term arg1);
MA_TermArgs MA_concatTermArgs(MA_TermArgs arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_TermArgs arg1);
#ifdef FAST_API
#define MA_sliceTermArgs(arg, start, end) ((MA_TermArgs) ATgetSlice((ATermList) (arg), (start * 4), (end * 4)))
#else
MA_TermArgs _MA_sliceTermArgs(MA_TermArgs arg, int start, int end);
#define MA_sliceTermArgs(arg, start, end) (_MA_sliceTermArgs(arg, start, end))
#endif
#ifdef FAST_API
#define MA_getTermArgsTermAt(arg, index) ((MA_Term) (ATelementAt((ATermList) arg,index * 4)))
#else
MA_Term _MA_getTermArgsTermAt(MA_TermArgs arg, int index);
#define MA_getTermArgsTermAt(arg, index) (_MA_getTermArgsTermAt(arg, index))
#endif
#ifdef FAST_API
#define MA_replaceTermArgsTermAt(arg, elem, index) ((MA_TermArgs) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index * 4)))
#else
MA_TermArgs _MA_replaceTermArgsTermAt(MA_TermArgs arg, MA_Term elem, int index);
#define MA_replaceTermArgsTermAt(arg, elem, index) (_MA_replaceTermArgsTermAt(arg, elem, index))
#endif
MA_TermArgs MA_makeTermArgs2(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2);
MA_TermArgs MA_makeTermArgs3(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2, MA_Term elem3);
MA_TermArgs MA_makeTermArgs4(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2, MA_Term elem3, MA_Term elem4);
MA_TermArgs MA_makeTermArgs5(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2, MA_Term elem3, MA_Term elem4, MA_Term elem5);
MA_TermArgs MA_makeTermArgs6(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2, MA_Term elem3, MA_Term elem4, MA_Term elem5, MA_Term elem6);
#ifdef FAST_API
#define MA_getTermElemsLength(arg) ((ATisEmpty((ATermList) (arg)) ? 0 : (ATgetLength((ATermList) (arg)) / 4) + 1))
#else
int _MA_getTermElemsLength(MA_TermElems arg);
#define MA_getTermElemsLength(arg) (_MA_getTermElemsLength(arg))
#endif
MA_TermElems MA_reverseTermElems(MA_TermElems arg);
MA_TermElems MA_appendTermElems(MA_TermElems arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term arg1);
MA_TermElems MA_concatTermElems(MA_TermElems arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_TermElems arg1);
#ifdef FAST_API
#define MA_sliceTermElems(arg, start, end) ((MA_TermElems) ATgetSlice((ATermList) (arg), (start * 4), (end * 4)))
#else
MA_TermElems _MA_sliceTermElems(MA_TermElems arg, int start, int end);
#define MA_sliceTermElems(arg, start, end) (_MA_sliceTermElems(arg, start, end))
#endif
#ifdef FAST_API
#define MA_getTermElemsTermAt(arg, index) ((MA_Term) (ATelementAt((ATermList) arg,index * 4)))
#else
MA_Term _MA_getTermElemsTermAt(MA_TermElems arg, int index);
#define MA_getTermElemsTermAt(arg, index) (_MA_getTermElemsTermAt(arg, index))
#endif
#ifdef FAST_API
#define MA_replaceTermElemsTermAt(arg, elem, index) ((MA_TermElems) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index * 4)))
#else
MA_TermElems _MA_replaceTermElemsTermAt(MA_TermElems arg, MA_Term elem, int index);
#define MA_replaceTermElemsTermAt(arg, elem, index) (_MA_replaceTermElemsTermAt(arg, elem, index))
#endif
MA_TermElems MA_makeTermElems2(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2);
MA_TermElems MA_makeTermElems3(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2, MA_Term elem3);
MA_TermElems MA_makeTermElems4(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2, MA_Term elem3, MA_Term elem4);
MA_TermElems MA_makeTermElems5(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2, MA_Term elem3, MA_Term elem4, MA_Term elem5);
MA_TermElems MA_makeTermElems6(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2, MA_Term elem3, MA_Term elem4, MA_Term elem5, MA_Term elem6);
#ifdef FAST_API
#define MA_getSigArgArgsLength(arg) ((ATisEmpty((ATermList) (arg)) ? 0 : (ATgetLength((ATermList) (arg)) / 4) + 1))
#else
int _MA_getSigArgArgsLength(MA_SigArgArgs arg);
#define MA_getSigArgArgsLength(arg) (_MA_getSigArgArgsLength(arg))
#endif
MA_SigArgArgs MA_reverseSigArgArgs(MA_SigArgArgs arg);
MA_SigArgArgs MA_appendSigArgArgs(MA_SigArgArgs arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_SigArg arg1);
MA_SigArgArgs MA_concatSigArgArgs(MA_SigArgArgs arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_SigArgArgs arg1);
#ifdef FAST_API
#define MA_sliceSigArgArgs(arg, start, end) ((MA_SigArgArgs) ATgetSlice((ATermList) (arg), (start * 4), (end * 4)))
#else
MA_SigArgArgs _MA_sliceSigArgArgs(MA_SigArgArgs arg, int start, int end);
#define MA_sliceSigArgArgs(arg, start, end) (_MA_sliceSigArgArgs(arg, start, end))
#endif
#ifdef FAST_API
#define MA_getSigArgArgsSigArgAt(arg, index) ((MA_SigArg) (ATelementAt((ATermList) arg,index * 4)))
#else
MA_SigArg _MA_getSigArgArgsSigArgAt(MA_SigArgArgs arg, int index);
#define MA_getSigArgArgsSigArgAt(arg, index) (_MA_getSigArgArgsSigArgAt(arg, index))
#endif
#ifdef FAST_API
#define MA_replaceSigArgArgsSigArgAt(arg, elem, index) ((MA_SigArgArgs) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index * 4)))
#else
MA_SigArgArgs _MA_replaceSigArgArgsSigArgAt(MA_SigArgArgs arg, MA_SigArg elem, int index);
#define MA_replaceSigArgArgsSigArgAt(arg, elem, index) (_MA_replaceSigArgArgsSigArgAt(arg, elem, index))
#endif
MA_SigArgArgs MA_makeSigArgArgs2(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_SigArg elem1, MA_SigArg elem2);
MA_SigArgArgs MA_makeSigArgArgs3(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_SigArg elem1, MA_SigArg elem2, MA_SigArg elem3);
MA_SigArgArgs MA_makeSigArgArgs4(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_SigArg elem1, MA_SigArg elem2, MA_SigArg elem3, MA_SigArg elem4);
MA_SigArgArgs MA_makeSigArgArgs5(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_SigArg elem1, MA_SigArg elem2, MA_SigArg elem3, MA_SigArg elem4, MA_SigArg elem5);
MA_SigArgArgs MA_makeSigArgArgs6(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_SigArg elem1, MA_SigArg elem2, MA_SigArg elem3, MA_SigArg elem4, MA_SigArg elem5, MA_SigArg elem6);
#ifdef FAST_API
#define MA_getTermAttrsLength(arg) ((ATisEmpty((ATermList) (arg)) ? 0 : (ATgetLength((ATermList) (arg)) / 4) + 1))
#else
int _MA_getTermAttrsLength(MA_TermAttrs arg);
#define MA_getTermAttrsLength(arg) (_MA_getTermAttrsLength(arg))
#endif
MA_TermAttrs MA_reverseTermAttrs(MA_TermAttrs arg);
MA_TermAttrs MA_appendTermAttrs(MA_TermAttrs arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term arg1);
MA_TermAttrs MA_concatTermAttrs(MA_TermAttrs arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_TermAttrs arg1);
#ifdef FAST_API
#define MA_sliceTermAttrs(arg, start, end) ((MA_TermAttrs) ATgetSlice((ATermList) (arg), (start * 4), (end * 4)))
#else
MA_TermAttrs _MA_sliceTermAttrs(MA_TermAttrs arg, int start, int end);
#define MA_sliceTermAttrs(arg, start, end) (_MA_sliceTermAttrs(arg, start, end))
#endif
#ifdef FAST_API
#define MA_getTermAttrsTermAt(arg, index) ((MA_Term) (ATelementAt((ATermList) arg,index * 4)))
#else
MA_Term _MA_getTermAttrsTermAt(MA_TermAttrs arg, int index);
#define MA_getTermAttrsTermAt(arg, index) (_MA_getTermAttrsTermAt(arg, index))
#endif
#ifdef FAST_API
#define MA_replaceTermAttrsTermAt(arg, elem, index) ((MA_TermAttrs) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index * 4)))
#else
MA_TermAttrs _MA_replaceTermAttrsTermAt(MA_TermAttrs arg, MA_Term elem, int index);
#define MA_replaceTermAttrsTermAt(arg, elem, index) (_MA_replaceTermAttrsTermAt(arg, elem, index))
#endif
MA_TermAttrs MA_makeTermAttrs2(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2);
MA_TermAttrs MA_makeTermAttrs3(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2, MA_Term elem3);
MA_TermAttrs MA_makeTermAttrs4(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2, MA_Term elem3, MA_Term elem4);
MA_TermAttrs MA_makeTermAttrs5(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2, MA_Term elem3, MA_Term elem4, MA_Term elem5);
MA_TermAttrs MA_makeTermAttrs6(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2, MA_Term elem3, MA_Term elem4, MA_Term elem5, MA_Term elem6);
#ifdef FAST_API
#define MA_getFuncDefDefsLength(arg) ((ATisEmpty((ATermList) (arg)) ? 0 : (ATgetLength((ATermList) (arg)) / 4) + 1))
#else
int _MA_getFuncDefDefsLength(MA_FuncDefDefs arg);
#define MA_getFuncDefDefsLength(arg) (_MA_getFuncDefDefsLength(arg))
#endif
MA_FuncDefDefs MA_reverseFuncDefDefs(MA_FuncDefDefs arg);
MA_FuncDefDefs MA_appendFuncDefDefs(MA_FuncDefDefs arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_FuncDef arg1);
MA_FuncDefDefs MA_concatFuncDefDefs(MA_FuncDefDefs arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_FuncDefDefs arg1);
#ifdef FAST_API
#define MA_sliceFuncDefDefs(arg, start, end) ((MA_FuncDefDefs) ATgetSlice((ATermList) (arg), (start * 4), (end * 4)))
#else
MA_FuncDefDefs _MA_sliceFuncDefDefs(MA_FuncDefDefs arg, int start, int end);
#define MA_sliceFuncDefDefs(arg, start, end) (_MA_sliceFuncDefDefs(arg, start, end))
#endif
#ifdef FAST_API
#define MA_getFuncDefDefsFuncDefAt(arg, index) ((MA_FuncDef) (ATelementAt((ATermList) arg,index * 4)))
#else
MA_FuncDef _MA_getFuncDefDefsFuncDefAt(MA_FuncDefDefs arg, int index);
#define MA_getFuncDefDefsFuncDefAt(arg, index) (_MA_getFuncDefDefsFuncDefAt(arg, index))
#endif
#ifdef FAST_API
#define MA_replaceFuncDefDefsFuncDefAt(arg, elem, index) ((MA_FuncDefDefs) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index * 4)))
#else
MA_FuncDefDefs _MA_replaceFuncDefDefsFuncDefAt(MA_FuncDefDefs arg, MA_FuncDef elem, int index);
#define MA_replaceFuncDefDefsFuncDefAt(arg, elem, index) (_MA_replaceFuncDefDefsFuncDefAt(arg, elem, index))
#endif
MA_FuncDefDefs MA_makeFuncDefDefs2(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_FuncDef elem1, MA_FuncDef elem2);
MA_FuncDefDefs MA_makeFuncDefDefs3(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_FuncDef elem1, MA_FuncDef elem2, MA_FuncDef elem3);
MA_FuncDefDefs MA_makeFuncDefDefs4(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_FuncDef elem1, MA_FuncDef elem2, MA_FuncDef elem3, MA_FuncDef elem4);
MA_FuncDefDefs MA_makeFuncDefDefs5(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_FuncDef elem1, MA_FuncDef elem2, MA_FuncDef elem3, MA_FuncDef elem4, MA_FuncDef elem5);
MA_FuncDefDefs MA_makeFuncDefDefs6(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_FuncDef elem1, MA_FuncDef elem2, MA_FuncDef elem3, MA_FuncDef elem4, MA_FuncDef elem5, MA_FuncDef elem6);
#ifdef FAST_API
#define MA_getRuleRulesLength(arg) ((ATisEmpty((ATermList) (arg)) ? 0 : (ATgetLength((ATermList) (arg)) / 4) + 1))
#else
int _MA_getRuleRulesLength(MA_RuleRules arg);
#define MA_getRuleRulesLength(arg) (_MA_getRuleRulesLength(arg))
#endif
MA_RuleRules MA_reverseRuleRules(MA_RuleRules arg);
MA_RuleRules MA_appendRuleRules(MA_RuleRules arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Rule arg1);
MA_RuleRules MA_concatRuleRules(MA_RuleRules arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_RuleRules arg1);
#ifdef FAST_API
#define MA_sliceRuleRules(arg, start, end) ((MA_RuleRules) ATgetSlice((ATermList) (arg), (start * 4), (end * 4)))
#else
MA_RuleRules _MA_sliceRuleRules(MA_RuleRules arg, int start, int end);
#define MA_sliceRuleRules(arg, start, end) (_MA_sliceRuleRules(arg, start, end))
#endif
#ifdef FAST_API
#define MA_getRuleRulesRuleAt(arg, index) ((MA_Rule) (ATelementAt((ATermList) arg,index * 4)))
#else
MA_Rule _MA_getRuleRulesRuleAt(MA_RuleRules arg, int index);
#define MA_getRuleRulesRuleAt(arg, index) (_MA_getRuleRulesRuleAt(arg, index))
#endif
#ifdef FAST_API
#define MA_replaceRuleRulesRuleAt(arg, elem, index) ((MA_RuleRules) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index * 4)))
#else
MA_RuleRules _MA_replaceRuleRulesRuleAt(MA_RuleRules arg, MA_Rule elem, int index);
#define MA_replaceRuleRulesRuleAt(arg, elem, index) (_MA_replaceRuleRulesRuleAt(arg, elem, index))
#endif
MA_RuleRules MA_makeRuleRules2(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Rule elem1, MA_Rule elem2);
MA_RuleRules MA_makeRuleRules3(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Rule elem1, MA_Rule elem2, MA_Rule elem3);
MA_RuleRules MA_makeRuleRules4(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Rule elem1, MA_Rule elem2, MA_Rule elem3, MA_Rule elem4);
MA_RuleRules MA_makeRuleRules5(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Rule elem1, MA_Rule elem2, MA_Rule elem3, MA_Rule elem4, MA_Rule elem5);
MA_RuleRules MA_makeRuleRules6(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Rule elem1, MA_Rule elem2, MA_Rule elem3, MA_Rule elem4, MA_Rule elem5, MA_Rule elem6);
#ifdef FAST_API
#define MA_getCondCondsLength(arg) ((ATisEmpty((ATermList) (arg)) ? 0 : (ATgetLength((ATermList) (arg)) / 4) + 1))
#else
int _MA_getCondCondsLength(MA_CondConds arg);
#define MA_getCondCondsLength(arg) (_MA_getCondCondsLength(arg))
#endif
MA_CondConds MA_reverseCondConds(MA_CondConds arg);
MA_CondConds MA_appendCondConds(MA_CondConds arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Cond arg1);
MA_CondConds MA_concatCondConds(MA_CondConds arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_CondConds arg1);
#ifdef FAST_API
#define MA_sliceCondConds(arg, start, end) ((MA_CondConds) ATgetSlice((ATermList) (arg), (start * 4), (end * 4)))
#else
MA_CondConds _MA_sliceCondConds(MA_CondConds arg, int start, int end);
#define MA_sliceCondConds(arg, start, end) (_MA_sliceCondConds(arg, start, end))
#endif
#ifdef FAST_API
#define MA_getCondCondsCondAt(arg, index) ((MA_Cond) (ATelementAt((ATermList) arg,index * 4)))
#else
MA_Cond _MA_getCondCondsCondAt(MA_CondConds arg, int index);
#define MA_getCondCondsCondAt(arg, index) (_MA_getCondCondsCondAt(arg, index))
#endif
#ifdef FAST_API
#define MA_replaceCondCondsCondAt(arg, elem, index) ((MA_CondConds) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index * 4)))
#else
MA_CondConds _MA_replaceCondCondsCondAt(MA_CondConds arg, MA_Cond elem, int index);
#define MA_replaceCondCondsCondAt(arg, elem, index) (_MA_replaceCondCondsCondAt(arg, elem, index))
#endif
MA_CondConds MA_makeCondConds2(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Cond elem1, MA_Cond elem2);
MA_CondConds MA_makeCondConds3(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Cond elem1, MA_Cond elem2, MA_Cond elem3);
MA_CondConds MA_makeCondConds4(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Cond elem1, MA_Cond elem2, MA_Cond elem3, MA_Cond elem4);
MA_CondConds MA_makeCondConds5(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Cond elem1, MA_Cond elem2, MA_Cond elem3, MA_Cond elem4, MA_Cond elem5);
MA_CondConds MA_makeCondConds6(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Cond elem1, MA_Cond elem2, MA_Cond elem3, MA_Cond elem4, MA_Cond elem5, MA_Cond elem6);
#ifdef FAST_API
#define MA_getLexStrCharCharsLength(arg) (ATgetLength((ATermList) (arg)))
#else
int _MA_getLexStrCharCharsLength(MA_LexStrCharChars arg);
#define MA_getLexStrCharCharsLength(arg) (_MA_getLexStrCharCharsLength(arg))
#endif
#ifdef FAST_API
#define MA_reverseLexStrCharChars(arg) ((MA_LexStrCharChars) ATreverse((ATermList) (arg)))
#else
MA_LexStrCharChars _MA_reverseLexStrCharChars(MA_LexStrCharChars arg);
#define MA_reverseLexStrCharChars(arg) (_MA_reverseLexStrCharChars(arg))
#endif
#ifdef FAST_API
#define MA_appendLexStrCharChars(arg, elem) ((MA_LexStrCharChars) ATappend((ATermList) (arg), (ATerm) (((ATerm) elem))))
#else
MA_LexStrCharChars _MA_appendLexStrCharChars(MA_LexStrCharChars arg, MA_LexStrChar elem);
#define MA_appendLexStrCharChars(arg, elem) (_MA_appendLexStrCharChars(arg, elem))
#endif
#ifdef FAST_API
#define MA_concatLexStrCharChars(arg0, arg1) ((MA_LexStrCharChars) ATconcat((ATermList) (arg0), (ATermList) (arg1)))
#else
MA_LexStrCharChars _MA_concatLexStrCharChars(MA_LexStrCharChars arg0, MA_LexStrCharChars arg1);
#define MA_concatLexStrCharChars(arg0, arg1) (_MA_concatLexStrCharChars(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_sliceLexStrCharChars(arg, start, end) ((MA_LexStrCharChars) ATgetSlice((ATermList) (arg), (start), (end)))
#else
MA_LexStrCharChars _MA_sliceLexStrCharChars(MA_LexStrCharChars arg, int start, int end);
#define MA_sliceLexStrCharChars(arg, start, end) (_MA_sliceLexStrCharChars(arg, start, end))
#endif
#ifdef FAST_API
#define MA_getLexStrCharCharsLexStrCharAt(arg, index) ((MA_LexStrChar) (ATelementAt((ATermList) arg,index)))
#else
MA_LexStrChar _MA_getLexStrCharCharsLexStrCharAt(MA_LexStrCharChars arg, int index);
#define MA_getLexStrCharCharsLexStrCharAt(arg, index) (_MA_getLexStrCharCharsLexStrCharAt(arg, index))
#endif
#ifdef FAST_API
#define MA_replaceLexStrCharCharsLexStrCharAt(arg, elem, index) ((MA_LexStrCharChars) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index)))
#else
MA_LexStrCharChars _MA_replaceLexStrCharCharsLexStrCharAt(MA_LexStrCharChars arg, MA_LexStrChar elem, int index);
#define MA_replaceLexStrCharCharsLexStrCharAt(arg, elem, index) (_MA_replaceLexStrCharCharsLexStrCharAt(arg, elem, index))
#endif
#ifdef FAST_API
#define MA_makeLexStrCharChars2(elem1,  elem2) ((MA_LexStrCharChars) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) (((ATerm) elem2))))
#else
MA_LexStrCharChars _MA_makeLexStrCharChars2(MA_LexStrChar elem1, MA_LexStrChar elem2);
#define MA_makeLexStrCharChars2(elem1,  elem2) (_MA_makeLexStrCharChars2(elem1,  elem2))
#endif
#ifdef FAST_API
#define MA_makeLexStrCharChars3(elem1, elem2,  elem3) ((MA_LexStrCharChars) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) (((ATerm) elem3))))
#else
MA_LexStrCharChars _MA_makeLexStrCharChars3(MA_LexStrChar elem1, MA_LexStrChar elem2, MA_LexStrChar elem3);
#define MA_makeLexStrCharChars3(elem1, elem2,  elem3) (_MA_makeLexStrCharChars3(elem1, elem2,  elem3))
#endif
#ifdef FAST_API
#define MA_makeLexStrCharChars4(elem1, elem2, elem3,  elem4) ((MA_LexStrCharChars) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) (((ATerm) elem4))))
#else
MA_LexStrCharChars _MA_makeLexStrCharChars4(MA_LexStrChar elem1, MA_LexStrChar elem2, MA_LexStrChar elem3, MA_LexStrChar elem4);
#define MA_makeLexStrCharChars4(elem1, elem2, elem3,  elem4) (_MA_makeLexStrCharChars4(elem1, elem2, elem3,  elem4))
#endif
#ifdef FAST_API
#define MA_makeLexStrCharChars5(elem1, elem2, elem3, elem4,  elem5) ((MA_LexStrCharChars) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) (((ATerm) elem5))))
#else
MA_LexStrCharChars _MA_makeLexStrCharChars5(MA_LexStrChar elem1, MA_LexStrChar elem2, MA_LexStrChar elem3, MA_LexStrChar elem4, MA_LexStrChar elem5);
#define MA_makeLexStrCharChars5(elem1, elem2, elem3, elem4,  elem5) (_MA_makeLexStrCharChars5(elem1, elem2, elem3, elem4,  elem5))
#endif
#ifdef FAST_API
#define MA_makeLexStrCharChars6(elem1, elem2, elem3, elem4, elem5,  elem6) ((MA_LexStrCharChars) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) (((ATerm) elem6))))
#else
MA_LexStrCharChars _MA_makeLexStrCharChars6(MA_LexStrChar elem1, MA_LexStrChar elem2, MA_LexStrChar elem3, MA_LexStrChar elem4, MA_LexStrChar elem5, MA_LexStrChar elem6);
#define MA_makeLexStrCharChars6(elem1, elem2, elem3, elem4, elem5,  elem6) (_MA_makeLexStrCharChars6(elem1, elem2, elem3, elem4, elem5,  elem6))
#endif
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
#ifdef FAST_API
#define MA_isEqualOptLayout(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _MA_isEqualOptLayout(MA_OptLayout arg0, MA_OptLayout arg1);
#define MA_isEqualOptLayout(arg0, arg1) (_MA_isEqualOptLayout(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_isEqualLayout(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _MA_isEqualLayout(MA_Layout arg0, MA_Layout arg1);
#define MA_isEqualLayout(arg0, arg1) (_MA_isEqualLayout(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_isEqualLexLayoutList(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _MA_isEqualLexLayoutList(MA_LexLayoutList arg0, MA_LexLayoutList arg1);
#define MA_isEqualLexLayoutList(arg0, arg1) (_MA_isEqualLexLayoutList(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_isEqualTraversalStrategy(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _MA_isEqualTraversalStrategy(MA_TraversalStrategy arg0, MA_TraversalStrategy arg1);
#define MA_isEqualTraversalStrategy(arg0, arg1) (_MA_isEqualTraversalStrategy(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_isEqualTraversalType(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _MA_isEqualTraversalType(MA_TraversalType arg0, MA_TraversalType arg1);
#define MA_isEqualTraversalType(arg0, arg1) (_MA_isEqualTraversalType(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_isEqualTraversalContinuation(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _MA_isEqualTraversalContinuation(MA_TraversalContinuation arg0, MA_TraversalContinuation arg1);
#define MA_isEqualTraversalContinuation(arg0, arg1) (_MA_isEqualTraversalContinuation(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_isEqualFunId(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _MA_isEqualFunId(MA_FunId arg0, MA_FunId arg1);
#define MA_isEqualFunId(arg0, arg1) (_MA_isEqualFunId(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_isEqualVarId(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _MA_isEqualVarId(MA_VarId arg0, MA_VarId arg1);
#define MA_isEqualVarId(arg0, arg1) (_MA_isEqualVarId(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_isEqualModId(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _MA_isEqualModId(MA_ModId arg0, MA_ModId arg1);
#define MA_isEqualModId(arg0, arg1) (_MA_isEqualModId(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_isEqualTerm(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _MA_isEqualTerm(MA_Term arg0, MA_Term arg1);
#define MA_isEqualTerm(arg0, arg1) (_MA_isEqualTerm(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_isEqualTermList(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _MA_isEqualTermList(MA_TermList arg0, MA_TermList arg1);
#define MA_isEqualTermList(arg0, arg1) (_MA_isEqualTermList(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_isEqualSigArg(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _MA_isEqualSigArg(MA_SigArg arg0, MA_SigArg arg1);
#define MA_isEqualSigArg(arg0, arg1) (_MA_isEqualSigArg(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_isEqualFuncDef(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _MA_isEqualFuncDef(MA_FuncDef arg0, MA_FuncDef arg1);
#define MA_isEqualFuncDef(arg0, arg1) (_MA_isEqualFuncDef(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_isEqualAnnotations(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _MA_isEqualAnnotations(MA_Annotations arg0, MA_Annotations arg1);
#define MA_isEqualAnnotations(arg0, arg1) (_MA_isEqualAnnotations(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_isEqualSigArgList(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _MA_isEqualSigArgList(MA_SigArgList arg0, MA_SigArgList arg1);
#define MA_isEqualSigArgList(arg0, arg1) (_MA_isEqualSigArgList(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_isEqualFuncDefList(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _MA_isEqualFuncDefList(MA_FuncDefList arg0, MA_FuncDefList arg1);
#define MA_isEqualFuncDefList(arg0, arg1) (_MA_isEqualFuncDefList(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_isEqualRule(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _MA_isEqualRule(MA_Rule arg0, MA_Rule arg1);
#define MA_isEqualRule(arg0, arg1) (_MA_isEqualRule(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_isEqualRuleList(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _MA_isEqualRuleList(MA_RuleList arg0, MA_RuleList arg1);
#define MA_isEqualRuleList(arg0, arg1) (_MA_isEqualRuleList(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_isEqualCondList(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _MA_isEqualCondList(MA_CondList arg0, MA_CondList arg1);
#define MA_isEqualCondList(arg0, arg1) (_MA_isEqualCondList(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_isEqualCond(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _MA_isEqualCond(MA_Cond arg0, MA_Cond arg1);
#define MA_isEqualCond(arg0, arg1) (_MA_isEqualCond(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_isEqualSignatureOpt(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _MA_isEqualSignatureOpt(MA_SignatureOpt arg0, MA_SignatureOpt arg1);
#define MA_isEqualSignatureOpt(arg0, arg1) (_MA_isEqualSignatureOpt(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_isEqualRulesOpt(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _MA_isEqualRulesOpt(MA_RulesOpt arg0, MA_RulesOpt arg1);
#define MA_isEqualRulesOpt(arg0, arg1) (_MA_isEqualRulesOpt(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_isEqualModule(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _MA_isEqualModule(MA_Module arg0, MA_Module arg1);
#define MA_isEqualModule(arg0, arg1) (_MA_isEqualModule(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_isEqualTermArgs(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _MA_isEqualTermArgs(MA_TermArgs arg0, MA_TermArgs arg1);
#define MA_isEqualTermArgs(arg0, arg1) (_MA_isEqualTermArgs(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_isEqualTermElems(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _MA_isEqualTermElems(MA_TermElems arg0, MA_TermElems arg1);
#define MA_isEqualTermElems(arg0, arg1) (_MA_isEqualTermElems(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_isEqualSigArgArgs(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _MA_isEqualSigArgArgs(MA_SigArgArgs arg0, MA_SigArgArgs arg1);
#define MA_isEqualSigArgArgs(arg0, arg1) (_MA_isEqualSigArgArgs(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_isEqualTermAttrs(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _MA_isEqualTermAttrs(MA_TermAttrs arg0, MA_TermAttrs arg1);
#define MA_isEqualTermAttrs(arg0, arg1) (_MA_isEqualTermAttrs(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_isEqualFuncDefDefs(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _MA_isEqualFuncDefDefs(MA_FuncDefDefs arg0, MA_FuncDefDefs arg1);
#define MA_isEqualFuncDefDefs(arg0, arg1) (_MA_isEqualFuncDefDefs(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_isEqualRuleRules(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _MA_isEqualRuleRules(MA_RuleRules arg0, MA_RuleRules arg1);
#define MA_isEqualRuleRules(arg0, arg1) (_MA_isEqualRuleRules(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_isEqualCondConds(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _MA_isEqualCondConds(MA_CondConds arg0, MA_CondConds arg1);
#define MA_isEqualCondConds(arg0, arg1) (_MA_isEqualCondConds(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_isEqualLexLayout(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _MA_isEqualLexLayout(MA_LexLayout arg0, MA_LexLayout arg1);
#define MA_isEqualLexLayout(arg0, arg1) (_MA_isEqualLexLayout(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_isEqualLexStrChar(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _MA_isEqualLexStrChar(MA_LexStrChar arg0, MA_LexStrChar arg1);
#define MA_isEqualLexStrChar(arg0, arg1) (_MA_isEqualLexStrChar(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_isEqualStrChar(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _MA_isEqualStrChar(MA_StrChar arg0, MA_StrChar arg1);
#define MA_isEqualStrChar(arg0, arg1) (_MA_isEqualStrChar(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_isEqualLexStrCon(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _MA_isEqualLexStrCon(MA_LexStrCon arg0, MA_LexStrCon arg1);
#define MA_isEqualLexStrCon(arg0, arg1) (_MA_isEqualLexStrCon(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_isEqualStrCon(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _MA_isEqualStrCon(MA_StrCon arg0, MA_StrCon arg1);
#define MA_isEqualStrCon(arg0, arg1) (_MA_isEqualStrCon(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_isEqualLexStrCharChars(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _MA_isEqualLexStrCharChars(MA_LexStrCharChars arg0, MA_LexStrCharChars arg1);
#define MA_isEqualLexStrCharChars(arg0, arg1) (_MA_isEqualLexStrCharChars(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_isEqualLexNatCon(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _MA_isEqualLexNatCon(MA_LexNatCon arg0, MA_LexNatCon arg1);
#define MA_isEqualLexNatCon(arg0, arg1) (_MA_isEqualLexNatCon(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_isEqualNatCon(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _MA_isEqualNatCon(MA_NatCon arg0, MA_NatCon arg1);
#define MA_isEqualNatCon(arg0, arg1) (_MA_isEqualNatCon(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_isEqualLexIdCon(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _MA_isEqualLexIdCon(MA_LexIdCon arg0, MA_LexIdCon arg1);
#define MA_isEqualLexIdCon(arg0, arg1) (_MA_isEqualLexIdCon(arg0, arg1))
#endif
#ifdef FAST_API
#define MA_isEqualIdCon(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _MA_isEqualIdCon(MA_IdCon arg0, MA_IdCon arg1);
#define MA_isEqualIdCon(arg0, arg1) (_MA_isEqualIdCon(arg0, arg1))
#endif
ATbool MA_isValidOptLayout(MA_OptLayout arg);
inline ATbool MA_isOptLayoutAbsent(MA_OptLayout arg);
inline ATbool MA_isOptLayoutPresent(MA_OptLayout arg);
ATbool MA_hasOptLayoutLayout(MA_OptLayout arg);
MA_Layout MA_getOptLayoutLayout(MA_OptLayout arg);
MA_OptLayout MA_setOptLayoutLayout(MA_OptLayout arg, MA_Layout layout);
ATbool MA_isValidLayout(MA_Layout arg);
inline ATbool MA_isLayoutLexToCf(MA_Layout arg);
ATbool MA_hasLayoutList(MA_Layout arg);
MA_LexLayoutList MA_getLayoutList(MA_Layout arg);
MA_Layout MA_setLayoutList(MA_Layout arg, MA_LexLayoutList list);
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
ATbool MA_isValidTraversalStrategy(MA_TraversalStrategy arg);
inline ATbool MA_isTraversalStrategyBottomUp(MA_TraversalStrategy arg);
inline ATbool MA_isTraversalStrategyTopDown(MA_TraversalStrategy arg);
ATbool MA_isValidTraversalType(MA_TraversalType arg);
inline ATbool MA_isTraversalTypeTrafo(MA_TraversalType arg);
inline ATbool MA_isTraversalTypeAccu(MA_TraversalType arg);
inline ATbool MA_isTraversalTypeAccutrafo(MA_TraversalType arg);
ATbool MA_isValidTraversalContinuation(MA_TraversalContinuation arg);
inline ATbool MA_isTraversalContinuationBreak(MA_TraversalContinuation arg);
inline ATbool MA_isTraversalContinuationContinue(MA_TraversalContinuation arg);
ATbool MA_isValidFunId(MA_FunId arg);
inline ATbool MA_isFunIdCharacter(MA_FunId arg);
inline ATbool MA_isFunIdUnquoted(MA_FunId arg);
inline ATbool MA_isFunIdQuoted(MA_FunId arg);
inline ATbool MA_isFunIdReturnsList(MA_FunId arg);
inline ATbool MA_isFunIdList(MA_FunId arg);
inline ATbool MA_isFunIdIgnored(MA_FunId arg);
inline ATbool MA_isFunIdTranslate(MA_FunId arg);
inline ATbool MA_isFunIdTraversal(MA_FunId arg);
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
ATbool MA_isValidModId(MA_ModId arg);
inline ATbool MA_isModIdDefault(MA_ModId arg);
ATbool MA_hasModIdIdCon(MA_ModId arg);
MA_IdCon MA_getModIdIdCon(MA_ModId arg);
MA_ModId MA_setModIdIdCon(MA_ModId arg, MA_IdCon IdCon);
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
ATbool MA_isValidTermList(MA_TermList arg);
inline ATbool MA_isTermListDefault(MA_TermList arg);
ATbool MA_hasTermListElems(MA_TermList arg);
MA_TermElems MA_getTermListElems(MA_TermList arg);
MA_TermList MA_setTermListElems(MA_TermList arg, MA_TermElems elems);
ATbool MA_isValidSigArg(MA_SigArg arg);
inline ATbool MA_isSigArgNormal(MA_SigArg arg);
inline ATbool MA_isSigArgStar(MA_SigArg arg);
inline ATbool MA_isSigArgPlus(MA_SigArg arg);
ATbool MA_hasSigArgWsAfterUnderscore(MA_SigArg arg);
MA_OptLayout MA_getSigArgWsAfterUnderscore(MA_SigArg arg);
MA_SigArg MA_setSigArgWsAfterUnderscore(MA_SigArg arg, MA_OptLayout wsAfterUnderscore);
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
ATbool MA_isValidSigArgList(MA_SigArgList arg);
inline ATbool MA_isSigArgListDefault(MA_SigArgList arg);
ATbool MA_hasSigArgListArgs(MA_SigArgList arg);
MA_SigArgArgs MA_getSigArgListArgs(MA_SigArgList arg);
MA_SigArgList MA_setSigArgListArgs(MA_SigArgList arg, MA_SigArgArgs args);
ATbool MA_isValidFuncDefList(MA_FuncDefList arg);
inline ATbool MA_isFuncDefListDefault(MA_FuncDefList arg);
ATbool MA_hasFuncDefListDefs(MA_FuncDefList arg);
MA_FuncDefDefs MA_getFuncDefListDefs(MA_FuncDefList arg);
MA_FuncDefList MA_setFuncDefListDefs(MA_FuncDefList arg, MA_FuncDefDefs defs);
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
ATbool MA_isValidRuleList(MA_RuleList arg);
inline ATbool MA_isRuleListDefault(MA_RuleList arg);
ATbool MA_hasRuleListRules(MA_RuleList arg);
MA_RuleRules MA_getRuleListRules(MA_RuleList arg);
MA_RuleList MA_setRuleListRules(MA_RuleList arg, MA_RuleRules rules);
ATbool MA_isValidCondList(MA_CondList arg);
inline ATbool MA_isCondListDefault(MA_CondList arg);
ATbool MA_hasCondListConds(MA_CondList arg);
MA_CondConds MA_getCondListConds(MA_CondList arg);
MA_CondList MA_setCondListConds(MA_CondList arg, MA_CondConds conds);
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
ATbool MA_isValidSignatureOpt(MA_SignatureOpt arg);
inline ATbool MA_isSignatureOptAbsent(MA_SignatureOpt arg);
inline ATbool MA_isSignatureOptPresent(MA_SignatureOpt arg);
ATbool MA_hasSignatureOptWsAfterSignature(MA_SignatureOpt arg);
ATbool MA_hasSignatureOptFuncDefList(MA_SignatureOpt arg);
MA_OptLayout MA_getSignatureOptWsAfterSignature(MA_SignatureOpt arg);
MA_FuncDefList MA_getSignatureOptFuncDefList(MA_SignatureOpt arg);
MA_SignatureOpt MA_setSignatureOptWsAfterSignature(MA_SignatureOpt arg, MA_OptLayout wsAfterSignature);
MA_SignatureOpt MA_setSignatureOptFuncDefList(MA_SignatureOpt arg, MA_FuncDefList FuncDefList);
ATbool MA_isValidRulesOpt(MA_RulesOpt arg);
inline ATbool MA_isRulesOptAbsent(MA_RulesOpt arg);
inline ATbool MA_isRulesOptPresent(MA_RulesOpt arg);
ATbool MA_hasRulesOptWsAfterRules(MA_RulesOpt arg);
ATbool MA_hasRulesOptRuleList(MA_RulesOpt arg);
MA_OptLayout MA_getRulesOptWsAfterRules(MA_RulesOpt arg);
MA_RuleList MA_getRulesOptRuleList(MA_RulesOpt arg);
MA_RulesOpt MA_setRulesOptWsAfterRules(MA_RulesOpt arg, MA_OptLayout wsAfterRules);
MA_RulesOpt MA_setRulesOptRuleList(MA_RulesOpt arg, MA_RuleList RuleList);
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
ATbool MA_isValidLexLayout(MA_LexLayout arg);
inline ATbool MA_isLexLayoutWhitespace(MA_LexLayout arg);
ATbool MA_hasLexLayoutCh(MA_LexLayout arg);
char MA_getLexLayoutCh(MA_LexLayout arg);
MA_LexLayout MA_setLexLayoutCh(MA_LexLayout arg, char ch);
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
ATbool MA_isValidStrChar(MA_StrChar arg);
inline ATbool MA_isStrCharLexToCf(MA_StrChar arg);
ATbool MA_hasStrCharStrChar(MA_StrChar arg);
MA_LexStrChar MA_getStrCharStrChar(MA_StrChar arg);
MA_StrChar MA_setStrCharStrChar(MA_StrChar arg, MA_LexStrChar StrChar);
ATbool MA_isValidLexStrCon(MA_LexStrCon arg);
inline ATbool MA_isLexStrConDefault(MA_LexStrCon arg);
ATbool MA_hasLexStrConChars(MA_LexStrCon arg);
MA_LexStrCharChars MA_getLexStrConChars(MA_LexStrCon arg);
MA_LexStrCon MA_setLexStrConChars(MA_LexStrCon arg, MA_LexStrCharChars chars);
ATbool MA_isValidStrCon(MA_StrCon arg);
inline ATbool MA_isStrConLexToCf(MA_StrCon arg);
ATbool MA_hasStrConStrCon(MA_StrCon arg);
MA_LexStrCon MA_getStrConStrCon(MA_StrCon arg);
MA_StrCon MA_setStrConStrCon(MA_StrCon arg, MA_LexStrCon StrCon);
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
ATbool MA_isValidLexNatCon(MA_LexNatCon arg);
inline ATbool MA_isLexNatConDigits(MA_LexNatCon arg);
ATbool MA_hasLexNatConList(MA_LexNatCon arg);
char* MA_getLexNatConList(MA_LexNatCon arg);
MA_LexNatCon MA_setLexNatConList(MA_LexNatCon arg, const char* list);
ATbool MA_isValidNatCon(MA_NatCon arg);
inline ATbool MA_isNatConLexToCf(MA_NatCon arg);
ATbool MA_hasNatConNatCon(MA_NatCon arg);
MA_LexNatCon MA_getNatConNatCon(MA_NatCon arg);
MA_NatCon MA_setNatConNatCon(MA_NatCon arg, MA_LexNatCon NatCon);
ATbool MA_isValidLexIdCon(MA_LexIdCon arg);
inline ATbool MA_isLexIdConDefault(MA_LexIdCon arg);
ATbool MA_hasLexIdConHead(MA_LexIdCon arg);
ATbool MA_hasLexIdConTail(MA_LexIdCon arg);
char MA_getLexIdConHead(MA_LexIdCon arg);
char* MA_getLexIdConTail(MA_LexIdCon arg);
MA_LexIdCon MA_setLexIdConHead(MA_LexIdCon arg, char head);
MA_LexIdCon MA_setLexIdConTail(MA_LexIdCon arg, const char* tail);
ATbool MA_isValidIdCon(MA_IdCon arg);
inline ATbool MA_isIdConLexToCf(MA_IdCon arg);
ATbool MA_hasIdConIdCon(MA_IdCon arg);
MA_LexIdCon MA_getIdConIdCon(MA_IdCon arg);
MA_IdCon MA_setIdConIdCon(MA_IdCon arg, MA_LexIdCon IdCon);
MA_OptLayout MA_visitOptLayout(MA_OptLayout arg, MA_Layout (*acceptLayout)(MA_Layout));
MA_Layout MA_visitLayout(MA_Layout arg, MA_LexLayoutList (*acceptList)(MA_LexLayoutList));
MA_LexLayoutList MA_visitLexLayoutList(MA_LexLayoutList arg, MA_LexLayout (*acceptHead)(MA_LexLayout));
MA_TraversalStrategy MA_visitTraversalStrategy(MA_TraversalStrategy arg);
MA_TraversalType MA_visitTraversalType(MA_TraversalType arg);
MA_TraversalContinuation MA_visitTraversalContinuation(MA_TraversalContinuation arg);
MA_FunId MA_visitFunId(MA_FunId arg, MA_NatCon (*acceptNatCon)(MA_NatCon), MA_IdCon (*acceptIdCon)(MA_IdCon), MA_StrCon (*acceptStrCon)(MA_StrCon), MA_OptLayout (*acceptWsAfterBracketOpen)(MA_OptLayout), MA_OptLayout (*acceptWsAfterFunId)(MA_OptLayout), MA_OptLayout (*acceptWsAfterBraceOpen)(MA_OptLayout), MA_OptLayout (*acceptWsAfterIGNORE)(MA_OptLayout), MA_OptLayout (*acceptWsAfterTRANSLATE)(MA_OptLayout), MA_OptLayout (*acceptWsAfterBar)(MA_OptLayout), MA_TraversalType (*acceptTraversalType)(MA_TraversalType), MA_OptLayout (*acceptWsAfterTraversalType)(MA_OptLayout), MA_TraversalStrategy (*acceptTraversalStrategy)(MA_TraversalStrategy), MA_OptLayout (*acceptWsAfterTraversalStrategy)(MA_OptLayout), MA_TraversalContinuation (*acceptTraversalContinuation)(MA_TraversalContinuation), MA_OptLayout (*acceptWsAfterTraversalContinuation)(MA_OptLayout));
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

#endif /* _MUASF_H */
