#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "MuASF.h"

/*{{{  conversion functions */

ATerm MA_stringToChars(const char *str)
{
  int len = strlen(str);
  int i;
  ATermList result = ATempty;

  for (i = len - 1; i >= 0; i--) {
    result = ATinsert(result, (ATerm) ATmakeInt(str[i]));
  }

  return (ATerm) result;
}

ATerm MA_byteToChar(char ch)
{
    return (ATerm) ATmakeInt(ch);
}

char *MA_charsToString(ATerm arg)
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

char MA_charToByte(ATerm arg)
{
    return (char) ATgetInt((ATermInt) arg);
}


/*}}}  */

/*{{{  typedefs */

typedef struct ATerm _MA_OptLayout;
typedef struct ATerm _MA_Layout;
typedef struct ATerm _MA_LexLayoutList;
typedef struct ATerm _MA_TraversalStrategy;
typedef struct ATerm _MA_TraversalType;
typedef struct ATerm _MA_TraversalContinuation;
typedef struct ATerm _MA_FunId;
typedef struct ATerm _MA_VarId;
typedef struct ATerm _MA_ModId;
typedef struct ATerm _MA_Term;
typedef struct ATerm _MA_TermList;
typedef struct ATerm _MA_SigArg;
typedef struct ATerm _MA_FuncDef;
typedef struct ATerm _MA_Annotations;
typedef struct ATerm _MA_SigArgList;
typedef struct ATerm _MA_FuncDefList;
typedef struct ATerm _MA_Rule;
typedef struct ATerm _MA_RuleList;
typedef struct ATerm _MA_CondList;
typedef struct ATerm _MA_Cond;
typedef struct ATerm _MA_SignatureOpt;
typedef struct ATerm _MA_RulesOpt;
typedef struct ATerm _MA_Module;
typedef struct ATerm _MA_TermArgs;
typedef struct ATerm _MA_TermElems;
typedef struct ATerm _MA_SigArgArgs;
typedef struct ATerm _MA_TermAttrs;
typedef struct ATerm _MA_FuncDefDefs;
typedef struct ATerm _MA_RuleRules;
typedef struct ATerm _MA_CondConds;
typedef struct ATerm _MA_LexLayout;
typedef struct ATerm _MA_LexStrChar;
typedef struct ATerm _MA_StrChar;
typedef struct ATerm _MA_LexStrCon;
typedef struct ATerm _MA_StrCon;
typedef struct ATerm _MA_LexStrCharChars;
typedef struct ATerm _MA_LexNatCon;
typedef struct ATerm _MA_NatCon;
typedef struct ATerm _MA_LexIdCon;
typedef struct ATerm _MA_IdCon;

/*}}}  */

/*{{{  void MA_initMuASFApi(void) */

void MA_initMuASFApi(void)
{
  init_MuASF_dict();
}

/*}}}  */

/*{{{  protect functions */

void MA_protectOptLayout(MA_OptLayout *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MA_protectLayout(MA_Layout *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MA_protectLexLayoutList(MA_LexLayoutList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MA_protectTraversalStrategy(MA_TraversalStrategy *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MA_protectTraversalType(MA_TraversalType *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MA_protectTraversalContinuation(MA_TraversalContinuation *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MA_protectFunId(MA_FunId *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MA_protectVarId(MA_VarId *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MA_protectModId(MA_ModId *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MA_protectTerm(MA_Term *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MA_protectTermList(MA_TermList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MA_protectSigArg(MA_SigArg *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MA_protectFuncDef(MA_FuncDef *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MA_protectAnnotations(MA_Annotations *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MA_protectSigArgList(MA_SigArgList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MA_protectFuncDefList(MA_FuncDefList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MA_protectRule(MA_Rule *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MA_protectRuleList(MA_RuleList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MA_protectCondList(MA_CondList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MA_protectCond(MA_Cond *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MA_protectSignatureOpt(MA_SignatureOpt *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MA_protectRulesOpt(MA_RulesOpt *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MA_protectModule(MA_Module *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MA_protectTermArgs(MA_TermArgs *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MA_protectTermElems(MA_TermElems *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MA_protectSigArgArgs(MA_SigArgArgs *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MA_protectTermAttrs(MA_TermAttrs *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MA_protectFuncDefDefs(MA_FuncDefDefs *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MA_protectRuleRules(MA_RuleRules *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MA_protectCondConds(MA_CondConds *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MA_protectLexLayout(MA_LexLayout *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MA_protectLexStrChar(MA_LexStrChar *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MA_protectStrChar(MA_StrChar *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MA_protectLexStrCon(MA_LexStrCon *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MA_protectStrCon(MA_StrCon *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MA_protectLexStrCharChars(MA_LexStrCharChars *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MA_protectLexNatCon(MA_LexNatCon *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MA_protectNatCon(MA_NatCon *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MA_protectLexIdCon(MA_LexIdCon *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void MA_protectIdCon(MA_IdCon *arg)
{
  ATprotect((ATerm*)((void*) arg));
}


/*}}}  */
/*{{{  term conversion functions */

/*{{{  MA_OptLayout MA_OptLayoutFromTerm(ATerm t) */

MA_OptLayout MA_OptLayoutFromTerm(ATerm t)
{
  return (MA_OptLayout)t;
}

/*}}}  */
/*{{{  ATerm MA_OptLayoutToTerm(MA_OptLayout arg) */

ATerm MA_OptLayoutToTerm(MA_OptLayout arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_Layout MA_LayoutFromTerm(ATerm t) */

MA_Layout MA_LayoutFromTerm(ATerm t)
{
  return (MA_Layout)t;
}

/*}}}  */
/*{{{  ATerm MA_LayoutToTerm(MA_Layout arg) */

ATerm MA_LayoutToTerm(MA_Layout arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_LexLayoutList MA_LexLayoutListFromTerm(ATerm t) */

MA_LexLayoutList MA_LexLayoutListFromTerm(ATerm t)
{
  return (MA_LexLayoutList)t;
}

/*}}}  */
/*{{{  ATerm MA_LexLayoutListToTerm(MA_LexLayoutList arg) */

ATerm MA_LexLayoutListToTerm(MA_LexLayoutList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_TraversalStrategy MA_TraversalStrategyFromTerm(ATerm t) */

MA_TraversalStrategy MA_TraversalStrategyFromTerm(ATerm t)
{
  return (MA_TraversalStrategy)t;
}

/*}}}  */
/*{{{  ATerm MA_TraversalStrategyToTerm(MA_TraversalStrategy arg) */

ATerm MA_TraversalStrategyToTerm(MA_TraversalStrategy arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_TraversalType MA_TraversalTypeFromTerm(ATerm t) */

MA_TraversalType MA_TraversalTypeFromTerm(ATerm t)
{
  return (MA_TraversalType)t;
}

/*}}}  */
/*{{{  ATerm MA_TraversalTypeToTerm(MA_TraversalType arg) */

ATerm MA_TraversalTypeToTerm(MA_TraversalType arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_TraversalContinuation MA_TraversalContinuationFromTerm(ATerm t) */

MA_TraversalContinuation MA_TraversalContinuationFromTerm(ATerm t)
{
  return (MA_TraversalContinuation)t;
}

/*}}}  */
/*{{{  ATerm MA_TraversalContinuationToTerm(MA_TraversalContinuation arg) */

ATerm MA_TraversalContinuationToTerm(MA_TraversalContinuation arg)
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
/*{{{  MA_SigArgArgs MA_SigArgArgsFromTerm(ATerm t) */

MA_SigArgArgs MA_SigArgArgsFromTerm(ATerm t)
{
  return (MA_SigArgArgs)t;
}

/*}}}  */
/*{{{  ATerm MA_SigArgArgsToTerm(MA_SigArgArgs arg) */

ATerm MA_SigArgArgsToTerm(MA_SigArgArgs arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_TermAttrs MA_TermAttrsFromTerm(ATerm t) */

MA_TermAttrs MA_TermAttrsFromTerm(ATerm t)
{
  return (MA_TermAttrs)t;
}

/*}}}  */
/*{{{  ATerm MA_TermAttrsToTerm(MA_TermAttrs arg) */

ATerm MA_TermAttrsToTerm(MA_TermAttrs arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_FuncDefDefs MA_FuncDefDefsFromTerm(ATerm t) */

MA_FuncDefDefs MA_FuncDefDefsFromTerm(ATerm t)
{
  return (MA_FuncDefDefs)t;
}

/*}}}  */
/*{{{  ATerm MA_FuncDefDefsToTerm(MA_FuncDefDefs arg) */

ATerm MA_FuncDefDefsToTerm(MA_FuncDefDefs arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_RuleRules MA_RuleRulesFromTerm(ATerm t) */

MA_RuleRules MA_RuleRulesFromTerm(ATerm t)
{
  return (MA_RuleRules)t;
}

/*}}}  */
/*{{{  ATerm MA_RuleRulesToTerm(MA_RuleRules arg) */

ATerm MA_RuleRulesToTerm(MA_RuleRules arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_CondConds MA_CondCondsFromTerm(ATerm t) */

MA_CondConds MA_CondCondsFromTerm(ATerm t)
{
  return (MA_CondConds)t;
}

/*}}}  */
/*{{{  ATerm MA_CondCondsToTerm(MA_CondConds arg) */

ATerm MA_CondCondsToTerm(MA_CondConds arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_LexLayout MA_LexLayoutFromTerm(ATerm t) */

MA_LexLayout MA_LexLayoutFromTerm(ATerm t)
{
  return (MA_LexLayout)t;
}

/*}}}  */
/*{{{  ATerm MA_LexLayoutToTerm(MA_LexLayout arg) */

ATerm MA_LexLayoutToTerm(MA_LexLayout arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_LexStrChar MA_LexStrCharFromTerm(ATerm t) */

MA_LexStrChar MA_LexStrCharFromTerm(ATerm t)
{
  return (MA_LexStrChar)t;
}

/*}}}  */
/*{{{  ATerm MA_LexStrCharToTerm(MA_LexStrChar arg) */

ATerm MA_LexStrCharToTerm(MA_LexStrChar arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_StrChar MA_StrCharFromTerm(ATerm t) */

MA_StrChar MA_StrCharFromTerm(ATerm t)
{
  return (MA_StrChar)t;
}

/*}}}  */
/*{{{  ATerm MA_StrCharToTerm(MA_StrChar arg) */

ATerm MA_StrCharToTerm(MA_StrChar arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_LexStrCon MA_LexStrConFromTerm(ATerm t) */

MA_LexStrCon MA_LexStrConFromTerm(ATerm t)
{
  return (MA_LexStrCon)t;
}

/*}}}  */
/*{{{  ATerm MA_LexStrConToTerm(MA_LexStrCon arg) */

ATerm MA_LexStrConToTerm(MA_LexStrCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_StrCon MA_StrConFromTerm(ATerm t) */

MA_StrCon MA_StrConFromTerm(ATerm t)
{
  return (MA_StrCon)t;
}

/*}}}  */
/*{{{  ATerm MA_StrConToTerm(MA_StrCon arg) */

ATerm MA_StrConToTerm(MA_StrCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_LexStrCharChars MA_LexStrCharCharsFromTerm(ATerm t) */

MA_LexStrCharChars MA_LexStrCharCharsFromTerm(ATerm t)
{
  return (MA_LexStrCharChars)t;
}

/*}}}  */
/*{{{  ATerm MA_LexStrCharCharsToTerm(MA_LexStrCharChars arg) */

ATerm MA_LexStrCharCharsToTerm(MA_LexStrCharChars arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_LexNatCon MA_LexNatConFromTerm(ATerm t) */

MA_LexNatCon MA_LexNatConFromTerm(ATerm t)
{
  return (MA_LexNatCon)t;
}

/*}}}  */
/*{{{  ATerm MA_LexNatConToTerm(MA_LexNatCon arg) */

ATerm MA_LexNatConToTerm(MA_LexNatCon arg)
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
/*{{{  MA_LexIdCon MA_LexIdConFromTerm(ATerm t) */

MA_LexIdCon MA_LexIdConFromTerm(ATerm t)
{
  return (MA_LexIdCon)t;
}

/*}}}  */
/*{{{  ATerm MA_LexIdConToTerm(MA_LexIdCon arg) */

ATerm MA_LexIdConToTerm(MA_LexIdCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  MA_IdCon MA_IdConFromTerm(ATerm t) */

MA_IdCon MA_IdConFromTerm(ATerm t)
{
  return (MA_IdCon)t;
}

/*}}}  */
/*{{{  ATerm MA_IdConToTerm(MA_IdCon arg) */

ATerm MA_IdConToTerm(MA_IdCon arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*}}}  */
/*{{{  list functions */

int MA_getLexLayoutListLength (MA_LexLayoutList arg) {
  return ATgetLength((ATermList) arg);
}
MA_LexLayoutList MA_reverseLexLayoutList(MA_LexLayoutList arg) {
  return (MA_LexLayoutList) ATreverse((ATermList) arg);
}
MA_LexLayoutList MA_appendLexLayoutList(MA_LexLayoutList arg, MA_LexLayout elem) {
  return (MA_LexLayoutList) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}
MA_LexLayoutList MA_concatLexLayoutList(MA_LexLayoutList arg0, MA_LexLayoutList arg1) {
  return (MA_LexLayoutList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
MA_LexLayoutList MA_sliceLexLayoutList(MA_LexLayoutList arg, int start, int end) {
  return (MA_LexLayoutList) ATgetSlice((ATermList) arg, start, end);
}
MA_LexLayout MA_getLexLayoutListLexLayoutAt(MA_LexLayoutList arg, int index) {
 return (MA_LexLayout)ATelementAt((ATermList) arg,index);
}
MA_LexLayoutList MA_replaceLexLayoutListLexLayoutAt(MA_LexLayoutList arg, MA_LexLayout elem, int index) {
 return (MA_LexLayoutList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}
MA_LexLayoutList MA_makeLexLayoutList2(MA_LexLayout elem1, MA_LexLayout elem2) {
  return (MA_LexLayoutList) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}
MA_LexLayoutList MA_makeLexLayoutList3(MA_LexLayout elem1, MA_LexLayout elem2, MA_LexLayout elem3) {
  return (MA_LexLayoutList) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}
MA_LexLayoutList MA_makeLexLayoutList4(MA_LexLayout elem1, MA_LexLayout elem2, MA_LexLayout elem3, MA_LexLayout elem4) {
  return (MA_LexLayoutList) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}
MA_LexLayoutList MA_makeLexLayoutList5(MA_LexLayout elem1, MA_LexLayout elem2, MA_LexLayout elem3, MA_LexLayout elem4, MA_LexLayout elem5) {
  return (MA_LexLayoutList) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}
MA_LexLayoutList MA_makeLexLayoutList6(MA_LexLayout elem1, MA_LexLayout elem2, MA_LexLayout elem3, MA_LexLayout elem4, MA_LexLayout elem5, MA_LexLayout elem6) {
  return (MA_LexLayoutList) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}
int MA_getTermArgsLength (MA_TermArgs arg) {
  if (ATisEmpty((ATermList) arg)) {
    return 0;
  }
  return (ATgetLength((ATermList) arg) / 4) + 1;
}
MA_TermArgs MA_reverseTermArgs(MA_TermArgs arg) {
  ATermList list = (ATermList) arg;
  ATerm head;
  ATerm sep0;
  ATerm sep1;
  ATerm sep2;
  ATermList result;

 if (ATisEmpty(list) || ATgetLength(list) == 1) {
    return arg;
  }

  result = ATmakeList1(ATgetFirst(list));
      list = ATgetNext(list);
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);

  while (!ATisEmpty(list)) {
    result = ATinsert(result, sep2);
    result = ATinsert(result, sep1);
    result = ATinsert(result, sep0);

   head = ATgetFirst(list);
   result = ATinsert(result, head);
    list = ATgetNext(list);

   if (!ATisEmpty(list)) {
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);
   }
  }

  return (MA_TermArgs) result;
}
MA_TermArgs MA_appendTermArgs(MA_TermArgs arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term arg1) {
  return MA_concatTermArgs(arg0, wsAfterHead, wsAfterSep, MA_makeTermArgsSingle(arg1));
}
MA_TermArgs MA_concatTermArgs(MA_TermArgs arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_TermArgs arg1) {
  if (ATisEmpty((ATermList) arg0)) {
    return arg1;
  }
  arg1 = MA_makeTermArgsMany((MA_Term)ATgetFirst((ATermList) arg0), wsAfterHead, wsAfterSep,  arg1);
  arg1 = (MA_TermArgs) ATgetNext((ATermList) arg1);
  return (MA_TermArgs) ATconcat((ATermList) arg0, (ATermList) arg1);
}
MA_TermArgs MA_sliceTermArgs(MA_TermArgs arg, int start, int end) {
  return (MA_TermArgs) ATgetSlice((ATermList) arg, start * 4, end * 4);
}
MA_Term MA_getTermArgsTermAt(MA_TermArgs arg, int index) {
 return (MA_Term)ATelementAt((ATermList) arg,index * 4);
}
MA_TermArgs MA_replaceTermArgsTermAt(MA_TermArgs arg, MA_Term elem, int index) {
 return (MA_TermArgs) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index * 4);
}
MA_TermArgs MA_makeTermArgs2(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2) {
  return MA_makeTermArgsMany(elem1, wsAfterHead, wsAfterSep, MA_makeTermArgsSingle(elem2));
}
MA_TermArgs MA_makeTermArgs3(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2, MA_Term elem3) {
  return MA_makeTermArgsMany(elem1, wsAfterHead, wsAfterSep, MA_makeTermArgs2(wsAfterHead, wsAfterSep, elem2, elem3));
}
MA_TermArgs MA_makeTermArgs4(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2, MA_Term elem3, MA_Term elem4) {
  return MA_makeTermArgsMany(elem1, wsAfterHead, wsAfterSep, MA_makeTermArgs3(wsAfterHead, wsAfterSep, elem2, elem3, elem4));
}
MA_TermArgs MA_makeTermArgs5(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2, MA_Term elem3, MA_Term elem4, MA_Term elem5) {
  return MA_makeTermArgsMany(elem1, wsAfterHead, wsAfterSep, MA_makeTermArgs4(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5));
}
MA_TermArgs MA_makeTermArgs6(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2, MA_Term elem3, MA_Term elem4, MA_Term elem5, MA_Term elem6) {
  return MA_makeTermArgsMany(elem1, wsAfterHead, wsAfterSep, MA_makeTermArgs5(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5, elem6));
}
int MA_getTermElemsLength (MA_TermElems arg) {
  if (ATisEmpty((ATermList) arg)) {
    return 0;
  }
  return (ATgetLength((ATermList) arg) / 4) + 1;
}
MA_TermElems MA_reverseTermElems(MA_TermElems arg) {
  ATermList list = (ATermList) arg;
  ATerm head;
  ATerm sep0;
  ATerm sep1;
  ATerm sep2;
  ATermList result;

 if (ATisEmpty(list) || ATgetLength(list) == 1) {
    return arg;
  }

  result = ATmakeList1(ATgetFirst(list));
      list = ATgetNext(list);
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);

  while (!ATisEmpty(list)) {
    result = ATinsert(result, sep2);
    result = ATinsert(result, sep1);
    result = ATinsert(result, sep0);

   head = ATgetFirst(list);
   result = ATinsert(result, head);
    list = ATgetNext(list);

   if (!ATisEmpty(list)) {
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);
   }
  }

  return (MA_TermElems) result;
}
MA_TermElems MA_appendTermElems(MA_TermElems arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term arg1) {
  return MA_concatTermElems(arg0, wsAfterHead, wsAfterSep, MA_makeTermElemsSingle(arg1));
}
MA_TermElems MA_concatTermElems(MA_TermElems arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_TermElems arg1) {
  if (ATisEmpty((ATermList) arg0)) {
    return arg1;
  }
  arg1 = MA_makeTermElemsMany((MA_Term)ATgetFirst((ATermList) arg0), wsAfterHead, wsAfterSep,  arg1);
  arg1 = (MA_TermElems) ATgetNext((ATermList) arg1);
  return (MA_TermElems) ATconcat((ATermList) arg0, (ATermList) arg1);
}
MA_TermElems MA_sliceTermElems(MA_TermElems arg, int start, int end) {
  return (MA_TermElems) ATgetSlice((ATermList) arg, start * 4, end * 4);
}
MA_Term MA_getTermElemsTermAt(MA_TermElems arg, int index) {
 return (MA_Term)ATelementAt((ATermList) arg,index * 4);
}
MA_TermElems MA_replaceTermElemsTermAt(MA_TermElems arg, MA_Term elem, int index) {
 return (MA_TermElems) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index * 4);
}
MA_TermElems MA_makeTermElems2(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2) {
  return MA_makeTermElemsMany(elem1, wsAfterHead, wsAfterSep, MA_makeTermElemsSingle(elem2));
}
MA_TermElems MA_makeTermElems3(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2, MA_Term elem3) {
  return MA_makeTermElemsMany(elem1, wsAfterHead, wsAfterSep, MA_makeTermElems2(wsAfterHead, wsAfterSep, elem2, elem3));
}
MA_TermElems MA_makeTermElems4(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2, MA_Term elem3, MA_Term elem4) {
  return MA_makeTermElemsMany(elem1, wsAfterHead, wsAfterSep, MA_makeTermElems3(wsAfterHead, wsAfterSep, elem2, elem3, elem4));
}
MA_TermElems MA_makeTermElems5(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2, MA_Term elem3, MA_Term elem4, MA_Term elem5) {
  return MA_makeTermElemsMany(elem1, wsAfterHead, wsAfterSep, MA_makeTermElems4(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5));
}
MA_TermElems MA_makeTermElems6(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2, MA_Term elem3, MA_Term elem4, MA_Term elem5, MA_Term elem6) {
  return MA_makeTermElemsMany(elem1, wsAfterHead, wsAfterSep, MA_makeTermElems5(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5, elem6));
}
int MA_getSigArgArgsLength (MA_SigArgArgs arg) {
  if (ATisEmpty((ATermList) arg)) {
    return 0;
  }
  return (ATgetLength((ATermList) arg) / 4) + 1;
}
MA_SigArgArgs MA_reverseSigArgArgs(MA_SigArgArgs arg) {
  ATermList list = (ATermList) arg;
  ATerm head;
  ATerm sep0;
  ATerm sep1;
  ATerm sep2;
  ATermList result;

 if (ATisEmpty(list) || ATgetLength(list) == 1) {
    return arg;
  }

  result = ATmakeList1(ATgetFirst(list));
      list = ATgetNext(list);
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);

  while (!ATisEmpty(list)) {
    result = ATinsert(result, sep2);
    result = ATinsert(result, sep1);
    result = ATinsert(result, sep0);

   head = ATgetFirst(list);
   result = ATinsert(result, head);
    list = ATgetNext(list);

   if (!ATisEmpty(list)) {
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);
   }
  }

  return (MA_SigArgArgs) result;
}
MA_SigArgArgs MA_appendSigArgArgs(MA_SigArgArgs arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_SigArg arg1) {
  return MA_concatSigArgArgs(arg0, wsAfterHead, wsAfterSep, MA_makeSigArgArgsSingle(arg1));
}
MA_SigArgArgs MA_concatSigArgArgs(MA_SigArgArgs arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_SigArgArgs arg1) {
  if (ATisEmpty((ATermList) arg0)) {
    return arg1;
  }
  arg1 = MA_makeSigArgArgsMany((MA_SigArg)ATgetFirst((ATermList) arg0), wsAfterHead, wsAfterSep,  arg1);
  arg1 = (MA_SigArgArgs) ATgetNext((ATermList) arg1);
  return (MA_SigArgArgs) ATconcat((ATermList) arg0, (ATermList) arg1);
}
MA_SigArgArgs MA_sliceSigArgArgs(MA_SigArgArgs arg, int start, int end) {
  return (MA_SigArgArgs) ATgetSlice((ATermList) arg, start * 4, end * 4);
}
MA_SigArg MA_getSigArgArgsSigArgAt(MA_SigArgArgs arg, int index) {
 return (MA_SigArg)ATelementAt((ATermList) arg,index * 4);
}
MA_SigArgArgs MA_replaceSigArgArgsSigArgAt(MA_SigArgArgs arg, MA_SigArg elem, int index) {
 return (MA_SigArgArgs) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index * 4);
}
MA_SigArgArgs MA_makeSigArgArgs2(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_SigArg elem1, MA_SigArg elem2) {
  return MA_makeSigArgArgsMany(elem1, wsAfterHead, wsAfterSep, MA_makeSigArgArgsSingle(elem2));
}
MA_SigArgArgs MA_makeSigArgArgs3(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_SigArg elem1, MA_SigArg elem2, MA_SigArg elem3) {
  return MA_makeSigArgArgsMany(elem1, wsAfterHead, wsAfterSep, MA_makeSigArgArgs2(wsAfterHead, wsAfterSep, elem2, elem3));
}
MA_SigArgArgs MA_makeSigArgArgs4(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_SigArg elem1, MA_SigArg elem2, MA_SigArg elem3, MA_SigArg elem4) {
  return MA_makeSigArgArgsMany(elem1, wsAfterHead, wsAfterSep, MA_makeSigArgArgs3(wsAfterHead, wsAfterSep, elem2, elem3, elem4));
}
MA_SigArgArgs MA_makeSigArgArgs5(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_SigArg elem1, MA_SigArg elem2, MA_SigArg elem3, MA_SigArg elem4, MA_SigArg elem5) {
  return MA_makeSigArgArgsMany(elem1, wsAfterHead, wsAfterSep, MA_makeSigArgArgs4(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5));
}
MA_SigArgArgs MA_makeSigArgArgs6(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_SigArg elem1, MA_SigArg elem2, MA_SigArg elem3, MA_SigArg elem4, MA_SigArg elem5, MA_SigArg elem6) {
  return MA_makeSigArgArgsMany(elem1, wsAfterHead, wsAfterSep, MA_makeSigArgArgs5(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5, elem6));
}
int MA_getTermAttrsLength (MA_TermAttrs arg) {
  if (ATisEmpty((ATermList) arg)) {
    return 0;
  }
  return (ATgetLength((ATermList) arg) / 4) + 1;
}
MA_TermAttrs MA_reverseTermAttrs(MA_TermAttrs arg) {
  ATermList list = (ATermList) arg;
  ATerm head;
  ATerm sep0;
  ATerm sep1;
  ATerm sep2;
  ATermList result;

 if (ATisEmpty(list) || ATgetLength(list) == 1) {
    return arg;
  }

  result = ATmakeList1(ATgetFirst(list));
      list = ATgetNext(list);
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);

  while (!ATisEmpty(list)) {
    result = ATinsert(result, sep2);
    result = ATinsert(result, sep1);
    result = ATinsert(result, sep0);

   head = ATgetFirst(list);
   result = ATinsert(result, head);
    list = ATgetNext(list);

   if (!ATisEmpty(list)) {
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);
   }
  }

  return (MA_TermAttrs) result;
}
MA_TermAttrs MA_appendTermAttrs(MA_TermAttrs arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term arg1) {
  return MA_concatTermAttrs(arg0, wsAfterHead, wsAfterSep, MA_makeTermAttrsSingle(arg1));
}
MA_TermAttrs MA_concatTermAttrs(MA_TermAttrs arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_TermAttrs arg1) {
  if (ATisEmpty((ATermList) arg0)) {
    return arg1;
  }
  arg1 = MA_makeTermAttrsMany((MA_Term)ATgetFirst((ATermList) arg0), wsAfterHead, wsAfterSep,  arg1);
  arg1 = (MA_TermAttrs) ATgetNext((ATermList) arg1);
  return (MA_TermAttrs) ATconcat((ATermList) arg0, (ATermList) arg1);
}
MA_TermAttrs MA_sliceTermAttrs(MA_TermAttrs arg, int start, int end) {
  return (MA_TermAttrs) ATgetSlice((ATermList) arg, start * 4, end * 4);
}
MA_Term MA_getTermAttrsTermAt(MA_TermAttrs arg, int index) {
 return (MA_Term)ATelementAt((ATermList) arg,index * 4);
}
MA_TermAttrs MA_replaceTermAttrsTermAt(MA_TermAttrs arg, MA_Term elem, int index) {
 return (MA_TermAttrs) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index * 4);
}
MA_TermAttrs MA_makeTermAttrs2(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2) {
  return MA_makeTermAttrsMany(elem1, wsAfterHead, wsAfterSep, MA_makeTermAttrsSingle(elem2));
}
MA_TermAttrs MA_makeTermAttrs3(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2, MA_Term elem3) {
  return MA_makeTermAttrsMany(elem1, wsAfterHead, wsAfterSep, MA_makeTermAttrs2(wsAfterHead, wsAfterSep, elem2, elem3));
}
MA_TermAttrs MA_makeTermAttrs4(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2, MA_Term elem3, MA_Term elem4) {
  return MA_makeTermAttrsMany(elem1, wsAfterHead, wsAfterSep, MA_makeTermAttrs3(wsAfterHead, wsAfterSep, elem2, elem3, elem4));
}
MA_TermAttrs MA_makeTermAttrs5(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2, MA_Term elem3, MA_Term elem4, MA_Term elem5) {
  return MA_makeTermAttrsMany(elem1, wsAfterHead, wsAfterSep, MA_makeTermAttrs4(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5));
}
MA_TermAttrs MA_makeTermAttrs6(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Term elem1, MA_Term elem2, MA_Term elem3, MA_Term elem4, MA_Term elem5, MA_Term elem6) {
  return MA_makeTermAttrsMany(elem1, wsAfterHead, wsAfterSep, MA_makeTermAttrs5(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5, elem6));
}
int MA_getFuncDefDefsLength (MA_FuncDefDefs arg) {
  if (ATisEmpty((ATermList) arg)) {
    return 0;
  }
  return (ATgetLength((ATermList) arg) / 4) + 1;
}
MA_FuncDefDefs MA_reverseFuncDefDefs(MA_FuncDefDefs arg) {
  ATermList list = (ATermList) arg;
  ATerm head;
  ATerm sep0;
  ATerm sep1;
  ATerm sep2;
  ATermList result;

 if (ATisEmpty(list) || ATgetLength(list) == 1) {
    return arg;
  }

  result = ATmakeList1(ATgetFirst(list));
      list = ATgetNext(list);
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);

  while (!ATisEmpty(list)) {
    result = ATinsert(result, sep2);
    result = ATinsert(result, sep1);
    result = ATinsert(result, sep0);

   head = ATgetFirst(list);
   result = ATinsert(result, head);
    list = ATgetNext(list);

   if (!ATisEmpty(list)) {
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);
   }
  }

  return (MA_FuncDefDefs) result;
}
MA_FuncDefDefs MA_appendFuncDefDefs(MA_FuncDefDefs arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_FuncDef arg1) {
  return MA_concatFuncDefDefs(arg0, wsAfterHead, wsAfterSep, MA_makeFuncDefDefsSingle(arg1));
}
MA_FuncDefDefs MA_concatFuncDefDefs(MA_FuncDefDefs arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_FuncDefDefs arg1) {
  if (ATisEmpty((ATermList) arg0)) {
    return arg1;
  }
  arg1 = MA_makeFuncDefDefsMany((MA_FuncDef)ATgetFirst((ATermList) arg0), wsAfterHead, wsAfterSep,  arg1);
  arg1 = (MA_FuncDefDefs) ATgetNext((ATermList) arg1);
  return (MA_FuncDefDefs) ATconcat((ATermList) arg0, (ATermList) arg1);
}
MA_FuncDefDefs MA_sliceFuncDefDefs(MA_FuncDefDefs arg, int start, int end) {
  return (MA_FuncDefDefs) ATgetSlice((ATermList) arg, start * 4, end * 4);
}
MA_FuncDef MA_getFuncDefDefsFuncDefAt(MA_FuncDefDefs arg, int index) {
 return (MA_FuncDef)ATelementAt((ATermList) arg,index * 4);
}
MA_FuncDefDefs MA_replaceFuncDefDefsFuncDefAt(MA_FuncDefDefs arg, MA_FuncDef elem, int index) {
 return (MA_FuncDefDefs) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index * 4);
}
MA_FuncDefDefs MA_makeFuncDefDefs2(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_FuncDef elem1, MA_FuncDef elem2) {
  return MA_makeFuncDefDefsMany(elem1, wsAfterHead, wsAfterSep, MA_makeFuncDefDefsSingle(elem2));
}
MA_FuncDefDefs MA_makeFuncDefDefs3(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_FuncDef elem1, MA_FuncDef elem2, MA_FuncDef elem3) {
  return MA_makeFuncDefDefsMany(elem1, wsAfterHead, wsAfterSep, MA_makeFuncDefDefs2(wsAfterHead, wsAfterSep, elem2, elem3));
}
MA_FuncDefDefs MA_makeFuncDefDefs4(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_FuncDef elem1, MA_FuncDef elem2, MA_FuncDef elem3, MA_FuncDef elem4) {
  return MA_makeFuncDefDefsMany(elem1, wsAfterHead, wsAfterSep, MA_makeFuncDefDefs3(wsAfterHead, wsAfterSep, elem2, elem3, elem4));
}
MA_FuncDefDefs MA_makeFuncDefDefs5(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_FuncDef elem1, MA_FuncDef elem2, MA_FuncDef elem3, MA_FuncDef elem4, MA_FuncDef elem5) {
  return MA_makeFuncDefDefsMany(elem1, wsAfterHead, wsAfterSep, MA_makeFuncDefDefs4(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5));
}
MA_FuncDefDefs MA_makeFuncDefDefs6(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_FuncDef elem1, MA_FuncDef elem2, MA_FuncDef elem3, MA_FuncDef elem4, MA_FuncDef elem5, MA_FuncDef elem6) {
  return MA_makeFuncDefDefsMany(elem1, wsAfterHead, wsAfterSep, MA_makeFuncDefDefs5(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5, elem6));
}
int MA_getRuleRulesLength (MA_RuleRules arg) {
  if (ATisEmpty((ATermList) arg)) {
    return 0;
  }
  return (ATgetLength((ATermList) arg) / 4) + 1;
}
MA_RuleRules MA_reverseRuleRules(MA_RuleRules arg) {
  ATermList list = (ATermList) arg;
  ATerm head;
  ATerm sep0;
  ATerm sep1;
  ATerm sep2;
  ATermList result;

 if (ATisEmpty(list) || ATgetLength(list) == 1) {
    return arg;
  }

  result = ATmakeList1(ATgetFirst(list));
      list = ATgetNext(list);
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);

  while (!ATisEmpty(list)) {
    result = ATinsert(result, sep2);
    result = ATinsert(result, sep1);
    result = ATinsert(result, sep0);

   head = ATgetFirst(list);
   result = ATinsert(result, head);
    list = ATgetNext(list);

   if (!ATisEmpty(list)) {
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);
   }
  }

  return (MA_RuleRules) result;
}
MA_RuleRules MA_appendRuleRules(MA_RuleRules arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Rule arg1) {
  return MA_concatRuleRules(arg0, wsAfterHead, wsAfterSep, MA_makeRuleRulesSingle(arg1));
}
MA_RuleRules MA_concatRuleRules(MA_RuleRules arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_RuleRules arg1) {
  if (ATisEmpty((ATermList) arg0)) {
    return arg1;
  }
  arg1 = MA_makeRuleRulesMany((MA_Rule)ATgetFirst((ATermList) arg0), wsAfterHead, wsAfterSep,  arg1);
  arg1 = (MA_RuleRules) ATgetNext((ATermList) arg1);
  return (MA_RuleRules) ATconcat((ATermList) arg0, (ATermList) arg1);
}
MA_RuleRules MA_sliceRuleRules(MA_RuleRules arg, int start, int end) {
  return (MA_RuleRules) ATgetSlice((ATermList) arg, start * 4, end * 4);
}
MA_Rule MA_getRuleRulesRuleAt(MA_RuleRules arg, int index) {
 return (MA_Rule)ATelementAt((ATermList) arg,index * 4);
}
MA_RuleRules MA_replaceRuleRulesRuleAt(MA_RuleRules arg, MA_Rule elem, int index) {
 return (MA_RuleRules) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index * 4);
}
MA_RuleRules MA_makeRuleRules2(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Rule elem1, MA_Rule elem2) {
  return MA_makeRuleRulesMany(elem1, wsAfterHead, wsAfterSep, MA_makeRuleRulesSingle(elem2));
}
MA_RuleRules MA_makeRuleRules3(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Rule elem1, MA_Rule elem2, MA_Rule elem3) {
  return MA_makeRuleRulesMany(elem1, wsAfterHead, wsAfterSep, MA_makeRuleRules2(wsAfterHead, wsAfterSep, elem2, elem3));
}
MA_RuleRules MA_makeRuleRules4(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Rule elem1, MA_Rule elem2, MA_Rule elem3, MA_Rule elem4) {
  return MA_makeRuleRulesMany(elem1, wsAfterHead, wsAfterSep, MA_makeRuleRules3(wsAfterHead, wsAfterSep, elem2, elem3, elem4));
}
MA_RuleRules MA_makeRuleRules5(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Rule elem1, MA_Rule elem2, MA_Rule elem3, MA_Rule elem4, MA_Rule elem5) {
  return MA_makeRuleRulesMany(elem1, wsAfterHead, wsAfterSep, MA_makeRuleRules4(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5));
}
MA_RuleRules MA_makeRuleRules6(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Rule elem1, MA_Rule elem2, MA_Rule elem3, MA_Rule elem4, MA_Rule elem5, MA_Rule elem6) {
  return MA_makeRuleRulesMany(elem1, wsAfterHead, wsAfterSep, MA_makeRuleRules5(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5, elem6));
}
int MA_getCondCondsLength (MA_CondConds arg) {
  if (ATisEmpty((ATermList) arg)) {
    return 0;
  }
  return (ATgetLength((ATermList) arg) / 4) + 1;
}
MA_CondConds MA_reverseCondConds(MA_CondConds arg) {
  ATermList list = (ATermList) arg;
  ATerm head;
  ATerm sep0;
  ATerm sep1;
  ATerm sep2;
  ATermList result;

 if (ATisEmpty(list) || ATgetLength(list) == 1) {
    return arg;
  }

  result = ATmakeList1(ATgetFirst(list));
      list = ATgetNext(list);
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);

  while (!ATisEmpty(list)) {
    result = ATinsert(result, sep2);
    result = ATinsert(result, sep1);
    result = ATinsert(result, sep0);

   head = ATgetFirst(list);
   result = ATinsert(result, head);
    list = ATgetNext(list);

   if (!ATisEmpty(list)) {
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);
   }
  }

  return (MA_CondConds) result;
}
MA_CondConds MA_appendCondConds(MA_CondConds arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Cond arg1) {
  return MA_concatCondConds(arg0, wsAfterHead, wsAfterSep, MA_makeCondCondsSingle(arg1));
}
MA_CondConds MA_concatCondConds(MA_CondConds arg0, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_CondConds arg1) {
  if (ATisEmpty((ATermList) arg0)) {
    return arg1;
  }
  arg1 = MA_makeCondCondsMany((MA_Cond)ATgetFirst((ATermList) arg0), wsAfterHead, wsAfterSep,  arg1);
  arg1 = (MA_CondConds) ATgetNext((ATermList) arg1);
  return (MA_CondConds) ATconcat((ATermList) arg0, (ATermList) arg1);
}
MA_CondConds MA_sliceCondConds(MA_CondConds arg, int start, int end) {
  return (MA_CondConds) ATgetSlice((ATermList) arg, start * 4, end * 4);
}
MA_Cond MA_getCondCondsCondAt(MA_CondConds arg, int index) {
 return (MA_Cond)ATelementAt((ATermList) arg,index * 4);
}
MA_CondConds MA_replaceCondCondsCondAt(MA_CondConds arg, MA_Cond elem, int index) {
 return (MA_CondConds) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index * 4);
}
MA_CondConds MA_makeCondConds2(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Cond elem1, MA_Cond elem2) {
  return MA_makeCondCondsMany(elem1, wsAfterHead, wsAfterSep, MA_makeCondCondsSingle(elem2));
}
MA_CondConds MA_makeCondConds3(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Cond elem1, MA_Cond elem2, MA_Cond elem3) {
  return MA_makeCondCondsMany(elem1, wsAfterHead, wsAfterSep, MA_makeCondConds2(wsAfterHead, wsAfterSep, elem2, elem3));
}
MA_CondConds MA_makeCondConds4(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Cond elem1, MA_Cond elem2, MA_Cond elem3, MA_Cond elem4) {
  return MA_makeCondCondsMany(elem1, wsAfterHead, wsAfterSep, MA_makeCondConds3(wsAfterHead, wsAfterSep, elem2, elem3, elem4));
}
MA_CondConds MA_makeCondConds5(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Cond elem1, MA_Cond elem2, MA_Cond elem3, MA_Cond elem4, MA_Cond elem5) {
  return MA_makeCondCondsMany(elem1, wsAfterHead, wsAfterSep, MA_makeCondConds4(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5));
}
MA_CondConds MA_makeCondConds6(MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_Cond elem1, MA_Cond elem2, MA_Cond elem3, MA_Cond elem4, MA_Cond elem5, MA_Cond elem6) {
  return MA_makeCondCondsMany(elem1, wsAfterHead, wsAfterSep, MA_makeCondConds5(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5, elem6));
}
int MA_getLexStrCharCharsLength (MA_LexStrCharChars arg) {
  return ATgetLength((ATermList) arg);
}
MA_LexStrCharChars MA_reverseLexStrCharChars(MA_LexStrCharChars arg) {
  return (MA_LexStrCharChars) ATreverse((ATermList) arg);
}
MA_LexStrCharChars MA_appendLexStrCharChars(MA_LexStrCharChars arg, MA_LexStrChar elem) {
  return (MA_LexStrCharChars) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}
MA_LexStrCharChars MA_concatLexStrCharChars(MA_LexStrCharChars arg0, MA_LexStrCharChars arg1) {
  return (MA_LexStrCharChars) ATconcat((ATermList) arg0, (ATermList) arg1);
}
MA_LexStrCharChars MA_sliceLexStrCharChars(MA_LexStrCharChars arg, int start, int end) {
  return (MA_LexStrCharChars) ATgetSlice((ATermList) arg, start, end);
}
MA_LexStrChar MA_getLexStrCharCharsLexStrCharAt(MA_LexStrCharChars arg, int index) {
 return (MA_LexStrChar)ATelementAt((ATermList) arg,index);
}
MA_LexStrCharChars MA_replaceLexStrCharCharsLexStrCharAt(MA_LexStrCharChars arg, MA_LexStrChar elem, int index) {
 return (MA_LexStrCharChars) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}
MA_LexStrCharChars MA_makeLexStrCharChars2(MA_LexStrChar elem1, MA_LexStrChar elem2) {
  return (MA_LexStrCharChars) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}
MA_LexStrCharChars MA_makeLexStrCharChars3(MA_LexStrChar elem1, MA_LexStrChar elem2, MA_LexStrChar elem3) {
  return (MA_LexStrCharChars) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}
MA_LexStrCharChars MA_makeLexStrCharChars4(MA_LexStrChar elem1, MA_LexStrChar elem2, MA_LexStrChar elem3, MA_LexStrChar elem4) {
  return (MA_LexStrCharChars) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}
MA_LexStrCharChars MA_makeLexStrCharChars5(MA_LexStrChar elem1, MA_LexStrChar elem2, MA_LexStrChar elem3, MA_LexStrChar elem4, MA_LexStrChar elem5) {
  return (MA_LexStrCharChars) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}
MA_LexStrCharChars MA_makeLexStrCharChars6(MA_LexStrChar elem1, MA_LexStrChar elem2, MA_LexStrChar elem3, MA_LexStrChar elem4, MA_LexStrChar elem5, MA_LexStrChar elem6) {
  return (MA_LexStrCharChars) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}

/*}}}  */
/*{{{  constructors */

/*{{{  MA_OptLayout MA_makeOptLayoutAbsent(void) */

MA_OptLayout MA_makeOptLayoutAbsent(void)
{
  return (MA_OptLayout)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATempty, (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4))), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATempty);
}

/*}}}  */
/*{{{  MA_OptLayout MA_makeOptLayoutPresent(MA_Layout layout) */

MA_OptLayout MA_makeOptLayoutPresent(MA_Layout layout)
{
  return (MA_OptLayout)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl0(MA_afun4))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4))), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm) layout));
}

/*}}}  */
/*{{{  MA_Layout MA_makeLayoutLexToCf(MA_LexLayoutList list) */

MA_Layout MA_makeLayoutLexToCf(MA_LexLayoutList list)
{
  return (MA_Layout)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl0(MA_afun4)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl1(MA_afun8, (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm) list)));
}

/*}}}  */
/*{{{  MA_LexLayoutList MA_makeLexLayoutListEmpty(void) */

MA_LexLayoutList MA_makeLexLayoutListEmpty(void)
{
  return (MA_LexLayoutList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  MA_LexLayoutList MA_makeLexLayoutListSingle(MA_LexLayout head) */

MA_LexLayoutList MA_makeLexLayoutListSingle(MA_LexLayout head)
{
  return (MA_LexLayoutList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  MA_LexLayoutList MA_makeLexLayoutListMany(MA_LexLayout head, MA_LexLayoutList tail) */

MA_LexLayoutList MA_makeLexLayoutListMany(MA_LexLayout head, MA_LexLayoutList tail)
{
  return (MA_LexLayoutList)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/*}}}  */
/*{{{  MA_TraversalStrategy MA_makeTraversalStrategyBottomUp(void) */

MA_TraversalStrategy MA_makeTraversalStrategyBottomUp(void)
{
  return (MA_TraversalStrategy)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun12))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun10)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(112)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(117)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(45)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(109)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(98)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun10)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(112)), (ATerm)ATmakeInt(117)), (ATerm)ATmakeInt(45)), (ATerm)ATmakeInt(109)), (ATerm)ATmakeInt(111)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(111)), (ATerm)ATmakeInt(98)))));
}

/*}}}  */
/*{{{  MA_TraversalStrategy MA_makeTraversalStrategyTopDown(void) */

MA_TraversalStrategy MA_makeTraversalStrategyTopDown(void)
{
  return (MA_TraversalStrategy)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun17))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun12))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun17)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(110)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(119)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(100)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(45)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(112)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun17)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(110)), (ATerm)ATmakeInt(119)), (ATerm)ATmakeInt(111)), (ATerm)ATmakeInt(100)), (ATerm)ATmakeInt(45)), (ATerm)ATmakeInt(112)), (ATerm)ATmakeInt(111)), (ATerm)ATmakeInt(116)))));
}

/*}}}  */
/*{{{  MA_TraversalType MA_makeTraversalTypeTrafo(void) */

MA_TraversalType MA_makeTraversalTypeTrafo(void)
{
  return (MA_TraversalType)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun18))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun19))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun18)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(102)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun18)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(111)), (ATerm)ATmakeInt(102)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(116)))));
}

/*}}}  */
/*{{{  MA_TraversalType MA_makeTraversalTypeAccu(void) */

MA_TraversalType MA_makeTraversalTypeAccu(void)
{
  return (MA_TraversalType)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun20))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun19))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun20)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(117)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(99)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(99)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun20)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(117)), (ATerm)ATmakeInt(99)), (ATerm)ATmakeInt(99)), (ATerm)ATmakeInt(97)))));
}

/*}}}  */
/*{{{  MA_TraversalType MA_makeTraversalTypeAccutrafo(void) */

MA_TraversalType MA_makeTraversalTypeAccutrafo(void)
{
  return (MA_TraversalType)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun21))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun19))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun21)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(102)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(117)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(99)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(99)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun21)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(111)), (ATerm)ATmakeInt(102)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(117)), (ATerm)ATmakeInt(99)), (ATerm)ATmakeInt(99)), (ATerm)ATmakeInt(97)))));
}

/*}}}  */
/*{{{  MA_TraversalContinuation MA_makeTraversalContinuationBreak(void) */

MA_TraversalContinuation MA_makeTraversalContinuationBreak(void)
{
  return (MA_TraversalContinuation)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun22))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun23))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun22)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(107)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(98)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun22)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(107)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(98)))));
}

/*}}}  */
/*{{{  MA_TraversalContinuation MA_makeTraversalContinuationContinue(void) */

MA_TraversalContinuation MA_makeTraversalContinuationContinue(void)
{
  return (MA_TraversalContinuation)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun24))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun23))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun24)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(117)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(110)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(110)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(99)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun24)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(117)), (ATerm)ATmakeInt(110)), (ATerm)ATmakeInt(105)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(110)), (ATerm)ATmakeInt(111)), (ATerm)ATmakeInt(99)))));
}

/*}}}  */
/*{{{  MA_FunId MA_makeFunIdCharacter(MA_NatCon NatCon) */

MA_FunId MA_makeFunIdCharacter(MA_NatCon NatCon)
{
  return (MA_FunId)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun25)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun26))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun27)))))), (ATerm)ATmakeList1((ATerm) NatCon));
}

/*}}}  */
/*{{{  MA_FunId MA_makeFunIdUnquoted(MA_IdCon IdCon) */

MA_FunId MA_makeFunIdUnquoted(MA_IdCon IdCon)
{
  return (MA_FunId)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun26))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl0(MA_afun29)), (ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun30)))))), (ATerm)ATmakeList1((ATerm) IdCon));
}

/*}}}  */
/*{{{  MA_FunId MA_makeFunIdQuoted(MA_StrCon StrCon) */

MA_FunId MA_makeFunIdQuoted(MA_StrCon StrCon)
{
  return (MA_FunId)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun31)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun26))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun32)))))), (ATerm)ATmakeList1((ATerm) StrCon));
}

/*}}}  */
/*{{{  MA_FunId MA_makeFunIdReturnsList(MA_OptLayout wsAfterBracketOpen, MA_FunId FunId, MA_OptLayout wsAfterFunId) */

MA_FunId MA_makeFunIdReturnsList(MA_OptLayout wsAfterBracketOpen, MA_FunId FunId, MA_OptLayout wsAfterFunId)
{
  return (MA_FunId)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun33))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun26)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun34))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun26))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun35)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun33)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterFunId), (ATerm) FunId), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun34)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))));
}

/*}}}  */
/*{{{  MA_FunId MA_makeFunIdList(MA_OptLayout wsAfterBraceOpen, MA_FunId FunId, MA_OptLayout wsAfterFunId) */

MA_FunId MA_makeFunIdList(MA_OptLayout wsAfterBraceOpen, MA_FunId FunId, MA_OptLayout wsAfterFunId)
{
  return (MA_FunId)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun36))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun26)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun37))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun26))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun38)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(125)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun36)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(125)))), (ATerm) wsAfterFunId), (ATerm) FunId), (ATerm) wsAfterBraceOpen), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(123)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun37)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(123)))));
}

/*}}}  */
/*{{{  MA_FunId MA_makeFunIdIgnored(MA_OptLayout wsAfterIGNORE, MA_OptLayout wsAfterBracketOpen, MA_FunId FunId, MA_OptLayout wsAfterFunId) */

MA_FunId MA_makeFunIdIgnored(MA_OptLayout wsAfterIGNORE, MA_OptLayout wsAfterBracketOpen, MA_FunId FunId, MA_OptLayout wsAfterFunId)
{
  return (MA_FunId)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun33))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun26)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun34))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun39))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun26))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun40)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun33)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterFunId), (ATerm) FunId), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun34)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm) wsAfterIGNORE), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(69)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(82)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(79)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(78)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(71)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(73)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun39)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(69)), (ATerm)ATmakeInt(82)), (ATerm)ATmakeInt(79)), (ATerm)ATmakeInt(78)), (ATerm)ATmakeInt(71)), (ATerm)ATmakeInt(73)))));
}

/*}}}  */
/*{{{  MA_FunId MA_makeFunIdTranslate(MA_OptLayout wsAfterTRANSLATE, MA_OptLayout wsAfterBracketOpen, MA_FunId FunId, MA_OptLayout wsAfterFunId) */

MA_FunId MA_makeFunIdTranslate(MA_OptLayout wsAfterTRANSLATE, MA_OptLayout wsAfterBracketOpen, MA_FunId FunId, MA_OptLayout wsAfterFunId)
{
  return (MA_FunId)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun33))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun26)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun34))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun41))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun26))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun42)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun33)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterFunId), (ATerm) FunId), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun34)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm) wsAfterTRANSLATE), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(69)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(84)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(65)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(76)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(83)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(78)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(65)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(82)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(84)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun41)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(69)), (ATerm)ATmakeInt(84)), (ATerm)ATmakeInt(65)), (ATerm)ATmakeInt(76)), (ATerm)ATmakeInt(83)), (ATerm)ATmakeInt(78)), (ATerm)ATmakeInt(65)), (ATerm)ATmakeInt(82)), (ATerm)ATmakeInt(84)))));
}

/*}}}  */
/*{{{  MA_FunId MA_makeFunIdTraversal(MA_OptLayout wsAfterBar, MA_FunId FunId, MA_OptLayout wsAfterFunId, MA_TraversalType TraversalType, MA_OptLayout wsAfterTraversalType, MA_TraversalStrategy TraversalStrategy, MA_OptLayout wsAfterTraversalStrategy, MA_TraversalContinuation TraversalContinuation, MA_OptLayout wsAfterTraversalContinuation) */

MA_FunId MA_makeFunIdTraversal(MA_OptLayout wsAfterBar, MA_FunId FunId, MA_OptLayout wsAfterFunId, MA_TraversalType TraversalType, MA_OptLayout wsAfterTraversalType, MA_TraversalStrategy TraversalStrategy, MA_OptLayout wsAfterTraversalStrategy, MA_TraversalContinuation TraversalContinuation, MA_OptLayout wsAfterTraversalContinuation)
{
  return (MA_FunId)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun43))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun23)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun12)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun19)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun26)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun43))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun26))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun44)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(124)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun43)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(124)))), (ATerm) wsAfterTraversalContinuation), (ATerm) TraversalContinuation), (ATerm) wsAfterTraversalStrategy), (ATerm) TraversalStrategy), (ATerm) wsAfterTraversalType), (ATerm) TraversalType), (ATerm) wsAfterFunId), (ATerm) FunId), (ATerm) wsAfterBar), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(124)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun43)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(124)))));
}

/*}}}  */
/*{{{  MA_FunId MA_makeFunIdConcat(MA_FunId lhs, MA_OptLayout wsAfterLhs, MA_OptLayout wsAfterPlusPlus, MA_FunId rhs) */

MA_FunId MA_makeFunIdConcat(MA_FunId lhs, MA_OptLayout wsAfterLhs, MA_OptLayout wsAfterPlusPlus, MA_FunId rhs)
{
  return (MA_FunId)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun26)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun45))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun26)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun26))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun46)))), (ATerm)ATmakeAppl1(MA_afun47, (ATerm)ATmakeAppl0(MA_afun48))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) rhs), (ATerm) wsAfterPlusPlus), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(43)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(43)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun45)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(43)), (ATerm)ATmakeInt(43)))), (ATerm) wsAfterLhs), (ATerm) lhs));
}

/*}}}  */
/*{{{  MA_VarId MA_makeVarIdNormal(MA_OptLayout wsAfterDollar, MA_FunId FunId) */

MA_VarId MA_makeVarIdNormal(MA_OptLayout wsAfterDollar, MA_FunId FunId)
{
  return (MA_VarId)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun26)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun49))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun50))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun51)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) FunId), (ATerm) wsAfterDollar), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(36)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun49)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(36)))));
}

/*}}}  */
/*{{{  MA_VarId MA_makeVarIdPlus(MA_OptLayout wsAfterDollarPlus, MA_FunId FunId) */

MA_VarId MA_makeVarIdPlus(MA_OptLayout wsAfterDollarPlus, MA_FunId FunId)
{
  return (MA_VarId)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun26)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun52))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun50))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun53)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) FunId), (ATerm) wsAfterDollarPlus), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(43)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(36)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun52)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(43)), (ATerm)ATmakeInt(36)))));
}

/*}}}  */
/*{{{  MA_VarId MA_makeVarIdStar(MA_OptLayout wsAfterDollarStar, MA_FunId FunId) */

MA_VarId MA_makeVarIdStar(MA_OptLayout wsAfterDollarStar, MA_FunId FunId)
{
  return (MA_VarId)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun26)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun54))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun50))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun55)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) FunId), (ATerm) wsAfterDollarStar), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(42)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(36)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun54)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(42)), (ATerm)ATmakeInt(36)))));
}

/*}}}  */
/*{{{  MA_ModId MA_makeModIdDefault(MA_IdCon IdCon) */

MA_ModId MA_makeModIdDefault(MA_IdCon IdCon)
{
  return (MA_ModId)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun56))), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm) IdCon));
}

/*}}}  */
/*{{{  MA_Term MA_makeTermVar(MA_VarId VarId) */

MA_Term MA_makeTermVar(MA_VarId VarId)
{
  return (MA_Term)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun50)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun57))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun58)))))), (ATerm)ATmakeList1((ATerm) VarId));
}

/*}}}  */
/*{{{  MA_Term MA_makeTermConstant(MA_FunId FunId) */

MA_Term MA_makeTermConstant(MA_FunId FunId)
{
  return (MA_Term)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun26)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun57))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun59)))))), (ATerm)ATmakeList1((ATerm) FunId));
}

/*}}}  */
/*{{{  MA_Term MA_makeTermFunc(MA_FunId FunId, MA_OptLayout wsAfterFunId, MA_OptLayout wsAfterParenOpen, MA_TermArgs args, MA_OptLayout wsAfterArgs) */

MA_Term MA_makeTermFunc(MA_FunId FunId, MA_OptLayout wsAfterFunId, MA_OptLayout wsAfterParenOpen, MA_TermArgs args, MA_OptLayout wsAfterArgs)
{
  return (MA_Term)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun60))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun61, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun57)), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun62))))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun63))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun26)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun57))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun64)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun60)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterArgs), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl1(MA_afun8, (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun61, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun57)), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun62))))), (ATerm) args)), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun63)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterFunId), (ATerm) FunId));
}

/*}}}  */
/*{{{  MA_Term MA_makeTermList(MA_OptLayout wsAfterBracketOpen, MA_TermList TermList, MA_OptLayout wsAfterTermList) */

MA_Term MA_makeTermList(MA_OptLayout wsAfterBracketOpen, MA_TermList TermList, MA_OptLayout wsAfterTermList)
{
  return (MA_Term)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun33))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun65)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun34))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun57))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun38)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun33)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterTermList), (ATerm) TermList), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun34)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))));
}

/*}}}  */
/*{{{  MA_Term MA_makeTermTyped(MA_Term Term, MA_OptLayout wsAfterTerm, MA_OptLayout wsAfterColon, MA_Term type) */

MA_Term MA_makeTermTyped(MA_Term Term, MA_OptLayout wsAfterTerm, MA_OptLayout wsAfterColon, MA_Term type)
{
  return (MA_Term)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun57)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun66))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun57)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun57))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun67)))), (ATerm)ATmakeAppl1(MA_afun47, (ATerm)ATmakeAppl0(MA_afun68))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) type), (ATerm) wsAfterColon), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(58)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun66)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(58)))), (ATerm) wsAfterTerm), (ATerm) Term));
}

/*}}}  */
/*{{{  MA_TermList MA_makeTermListDefault(MA_TermElems elems) */

MA_TermList MA_makeTermListDefault(MA_TermElems elems)
{
  return (MA_TermList)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun69, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun57)), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun62))))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun65))), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl1(MA_afun8, (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun69, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun57)), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun62))))), (ATerm) elems)));
}

/*}}}  */
/*{{{  MA_SigArg MA_makeSigArgNormal(void) */

MA_SigArg MA_makeSigArgNormal(void)
{
  return (MA_SigArg)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun70))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun71))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun51)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(95)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun70)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(95)))));
}

/*}}}  */
/*{{{  MA_SigArg MA_makeSigArgStar(MA_OptLayout wsAfterUnderscore) */

MA_SigArg MA_makeSigArgStar(MA_OptLayout wsAfterUnderscore)
{
  return (MA_SigArg)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun72))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun70))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun71))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun55)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(42)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun72)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(42)))), (ATerm) wsAfterUnderscore), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(95)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun70)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(95)))));
}

/*}}}  */
/*{{{  MA_SigArg MA_makeSigArgPlus(MA_OptLayout wsAfterUnderscore) */

MA_SigArg MA_makeSigArgPlus(MA_OptLayout wsAfterUnderscore)
{
  return (MA_SigArg)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun73))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun70))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun71))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun53)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(43)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun73)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(43)))), (ATerm) wsAfterUnderscore), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(95)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun70)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(95)))));
}

/*}}}  */
/*{{{  MA_FuncDef MA_makeFuncDefConstantNoAnnos(MA_FunId FunId) */

MA_FuncDef MA_makeFuncDefConstantNoAnnos(MA_FunId FunId)
{
  return (MA_FuncDef)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun26)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun74))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun75)))))), (ATerm)ATmakeList1((ATerm) FunId));
}

/*}}}  */
/*{{{  MA_FuncDef MA_makeFuncDefConstantWithAnnos(MA_FunId FunId, MA_OptLayout wsAfterFunId, MA_Annotations Annotations) */

MA_FuncDef MA_makeFuncDefConstantWithAnnos(MA_FunId FunId, MA_OptLayout wsAfterFunId, MA_Annotations Annotations)
{
  return (MA_FuncDef)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun76)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun26)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun74))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun77)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) Annotations), (ATerm) wsAfterFunId), (ATerm) FunId));
}

/*}}}  */
/*{{{  MA_FuncDef MA_makeFuncDefFuncNoAnnos(MA_FunId FunId, MA_OptLayout wsAfterFunId, MA_OptLayout wsAfterParenOpen, MA_SigArgArgs args, MA_OptLayout wsAfterArgs) */

MA_FuncDef MA_makeFuncDefFuncNoAnnos(MA_FunId FunId, MA_OptLayout wsAfterFunId, MA_OptLayout wsAfterParenOpen, MA_SigArgArgs args, MA_OptLayout wsAfterArgs)
{
  return (MA_FuncDef)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun60))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun61, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun71)), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun62))))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun63))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun26)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun74))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun78)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun60)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterArgs), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl1(MA_afun8, (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun61, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun71)), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun62))))), (ATerm) args)), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun63)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterFunId), (ATerm) FunId));
}

/*}}}  */
/*{{{  MA_FuncDef MA_makeFuncDefFuncWithAnnos(MA_FunId FunId, MA_OptLayout wsAfterFunId, MA_OptLayout wsAfterParenOpen, MA_SigArgArgs args, MA_OptLayout wsAfterArgs, MA_OptLayout wsAfterParenClose, MA_Annotations Annotations) */

MA_FuncDef MA_makeFuncDefFuncWithAnnos(MA_FunId FunId, MA_OptLayout wsAfterFunId, MA_OptLayout wsAfterParenOpen, MA_SigArgArgs args, MA_OptLayout wsAfterArgs, MA_OptLayout wsAfterParenClose, MA_Annotations Annotations)
{
  return (MA_FuncDef)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun76)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun60))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun61, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun71)), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun62))))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun63))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun26)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun74))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun79)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) Annotations), (ATerm) wsAfterParenClose), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun60)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterArgs), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl1(MA_afun8, (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun61, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun71)), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun62))))), (ATerm) args)), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun63)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterFunId), (ATerm) FunId));
}

/*}}}  */
/*{{{  MA_Annotations MA_makeAnnotationsDefault(MA_OptLayout wsAfterBraceOpen, MA_TermAttrs attrs, MA_OptLayout wsAfterAttrs) */

MA_Annotations MA_makeAnnotationsDefault(MA_OptLayout wsAfterBraceOpen, MA_TermAttrs attrs, MA_OptLayout wsAfterAttrs)
{
  return (MA_Annotations)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun36))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun61, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun57)), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun62))))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun37))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun76))), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(125)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun36)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(125)))), (ATerm) wsAfterAttrs), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl1(MA_afun8, (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun61, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun57)), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun62))))), (ATerm) attrs)), (ATerm) wsAfterBraceOpen), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(123)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun37)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(123)))));
}

/*}}}  */
/*{{{  MA_SigArgList MA_makeSigArgListDefault(MA_SigArgArgs args) */

MA_SigArgList MA_makeSigArgListDefault(MA_SigArgArgs args)
{
  return (MA_SigArgList)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun61, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun71)), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun62))))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun80))), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl1(MA_afun8, (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun61, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun71)), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun62))))), (ATerm) args)));
}

/*}}}  */
/*{{{  MA_FuncDefList MA_makeFuncDefListDefault(MA_FuncDefDefs defs) */

MA_FuncDefList MA_makeFuncDefListDefault(MA_FuncDefDefs defs)
{
  return (MA_FuncDefList)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun69, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun74)), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun81))))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun82))), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl1(MA_afun8, (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun69, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun74)), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun81))))), (ATerm) defs)));
}

/*}}}  */
/*{{{  MA_Rule MA_makeRuleNoConds(MA_Term lhs, MA_OptLayout wsAfterLhs, MA_OptLayout wsAfterIs, MA_Term rhs) */

MA_Rule MA_makeRuleNoConds(MA_Term lhs, MA_OptLayout wsAfterLhs, MA_OptLayout wsAfterIs, MA_Term rhs)
{
  return (MA_Rule)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun57)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun83))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun57)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun84))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun85)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) rhs), (ATerm) wsAfterIs), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(61)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun83)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(61)))), (ATerm) wsAfterLhs), (ATerm) lhs));
}

/*}}}  */
/*{{{  MA_Rule MA_makeRuleDefaultNoConds(MA_OptLayout wsAfterDefaultColon, MA_Term lhs, MA_OptLayout wsAfterLhs, MA_OptLayout wsAfterIs, MA_Term rhs) */

MA_Rule MA_makeRuleDefaultNoConds(MA_OptLayout wsAfterDefaultColon, MA_Term lhs, MA_OptLayout wsAfterLhs, MA_OptLayout wsAfterIs, MA_Term rhs)
{
  return (MA_Rule)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun57)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun83))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun57)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun86))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun84))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun87)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) rhs), (ATerm) wsAfterIs), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(61)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun83)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(61)))), (ATerm) wsAfterLhs), (ATerm) lhs), (ATerm) wsAfterDefaultColon), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(58)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(117)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(102)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(100)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun86)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(58)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(108)), (ATerm)ATmakeInt(117)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(102)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(100)))));
}

/*}}}  */
/*{{{  MA_Rule MA_makeRuleWithConds(MA_CondList conds, MA_OptLayout wsAfterConds, MA_OptLayout wsAfterEqualsEqualsGreaterThan, MA_Term lhs, MA_OptLayout wsAfterLhs, MA_OptLayout wsAfterIs, MA_Term rhs) */

MA_Rule MA_makeRuleWithConds(MA_CondList conds, MA_OptLayout wsAfterConds, MA_OptLayout wsAfterEqualsEqualsGreaterThan, MA_Term lhs, MA_OptLayout wsAfterLhs, MA_OptLayout wsAfterIs, MA_Term rhs)
{
  return (MA_Rule)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun57)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun83))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun57)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun88))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun89)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun84))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun90)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) rhs), (ATerm) wsAfterIs), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(61)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun83)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(61)))), (ATerm) wsAfterLhs), (ATerm) lhs), (ATerm) wsAfterEqualsEqualsGreaterThan), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(62)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(61)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(61)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun88)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(62)), (ATerm)ATmakeInt(61)), (ATerm)ATmakeInt(61)))), (ATerm) wsAfterConds), (ATerm) conds));
}

/*}}}  */
/*{{{  MA_Rule MA_makeRuleDefaultWithConds(MA_OptLayout wsAfterDefaultColon, MA_CondList conds, MA_OptLayout wsAfterConds, MA_OptLayout wsAfterEqualsEqualsGreaterThan, MA_Term lhs, MA_OptLayout wsAfterLhs, MA_OptLayout wsAfterIs, MA_Term rhs) */

MA_Rule MA_makeRuleDefaultWithConds(MA_OptLayout wsAfterDefaultColon, MA_CondList conds, MA_OptLayout wsAfterConds, MA_OptLayout wsAfterEqualsEqualsGreaterThan, MA_Term lhs, MA_OptLayout wsAfterLhs, MA_OptLayout wsAfterIs, MA_Term rhs)
{
  return (MA_Rule)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun57)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun83))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun57)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun88))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun89)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun86))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun84))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun91)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) rhs), (ATerm) wsAfterIs), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(61)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun83)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(61)))), (ATerm) wsAfterLhs), (ATerm) lhs), (ATerm) wsAfterEqualsEqualsGreaterThan), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(62)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(61)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(61)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun88)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(62)), (ATerm)ATmakeInt(61)), (ATerm)ATmakeInt(61)))), (ATerm) wsAfterConds), (ATerm) conds), (ATerm) wsAfterDefaultColon), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(58)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(117)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(102)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(100)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun86)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(58)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(108)), (ATerm)ATmakeInt(117)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(102)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(100)))));
}

/*}}}  */
/*{{{  MA_RuleList MA_makeRuleListDefault(MA_RuleRules rules) */

MA_RuleList MA_makeRuleListDefault(MA_RuleRules rules)
{
  return (MA_RuleList)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun69, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun84)), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun81))))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun92))), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl1(MA_afun8, (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun69, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun84)), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun81))))), (ATerm) rules)));
}

/*}}}  */
/*{{{  MA_CondList MA_makeCondListDefault(MA_CondConds conds) */

MA_CondList MA_makeCondListDefault(MA_CondConds conds)
{
  return (MA_CondList)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun69, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun93)), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun94))))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun89))), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl1(MA_afun8, (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl2(MA_afun69, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun93)), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun94))))), (ATerm) conds)));
}

/*}}}  */
/*{{{  MA_Cond MA_makeCondAssign(MA_Term lhs, MA_OptLayout wsAfterLhs, MA_OptLayout wsAfterBecomes, MA_Term rhs) */

MA_Cond MA_makeCondAssign(MA_Term lhs, MA_OptLayout wsAfterLhs, MA_OptLayout wsAfterBecomes, MA_Term rhs)
{
  return (MA_Cond)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun57)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun95))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun57)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun93))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun96)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) rhs), (ATerm) wsAfterBecomes), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(58)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(61)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun95)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(58)), (ATerm)ATmakeInt(61)))), (ATerm) wsAfterLhs), (ATerm) lhs));
}

/*}}}  */
/*{{{  MA_Cond MA_makeCondNoAssign(MA_Term lhs, MA_OptLayout wsAfterLhs, MA_OptLayout wsAfterNotBecomes, MA_Term rhs) */

MA_Cond MA_makeCondNoAssign(MA_Term lhs, MA_OptLayout wsAfterLhs, MA_OptLayout wsAfterNotBecomes, MA_Term rhs)
{
  return (MA_Cond)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun57)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun97))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun57)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun93))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun98)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) rhs), (ATerm) wsAfterNotBecomes), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(33)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(58)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(61)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun97)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(33)), (ATerm)ATmakeInt(58)), (ATerm)ATmakeInt(61)))), (ATerm) wsAfterLhs), (ATerm) lhs));
}

/*}}}  */
/*{{{  MA_Cond MA_makeCondEqual(MA_Term lhs, MA_OptLayout wsAfterLhs, MA_OptLayout wsAfterEquals, MA_Term rhs) */

MA_Cond MA_makeCondEqual(MA_Term lhs, MA_OptLayout wsAfterLhs, MA_OptLayout wsAfterEquals, MA_Term rhs)
{
  return (MA_Cond)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun57)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun99))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun57)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun93))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun100)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) rhs), (ATerm) wsAfterEquals), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(61)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(61)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun99)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(61)), (ATerm)ATmakeInt(61)))), (ATerm) wsAfterLhs), (ATerm) lhs));
}

/*}}}  */
/*{{{  MA_Cond MA_makeCondUnequal(MA_Term lhs, MA_OptLayout wsAfterLhs, MA_OptLayout wsAfterNotEquals, MA_Term rhs) */

MA_Cond MA_makeCondUnequal(MA_Term lhs, MA_OptLayout wsAfterLhs, MA_OptLayout wsAfterNotEquals, MA_Term rhs)
{
  return (MA_Cond)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun57)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun101))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun57)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun93))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun102)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) rhs), (ATerm) wsAfterNotEquals), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(61)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(33)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun101)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(61)), (ATerm)ATmakeInt(33)))), (ATerm) wsAfterLhs), (ATerm) lhs));
}

/*}}}  */
/*{{{  MA_SignatureOpt MA_makeSignatureOptAbsent(void) */

MA_SignatureOpt MA_makeSignatureOptAbsent(void)
{
  return (MA_SignatureOpt)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATempty, (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun103))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun104)))))), (ATerm)ATempty);
}

/*}}}  */
/*{{{  MA_SignatureOpt MA_makeSignatureOptPresent(MA_OptLayout wsAfterSignature, MA_FuncDefList FuncDefList) */

MA_SignatureOpt MA_makeSignatureOptPresent(MA_OptLayout wsAfterSignature, MA_FuncDefList FuncDefList)
{
  return (MA_SignatureOpt)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun82)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun105))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun103))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun106)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) FuncDefList), (ATerm) wsAfterSignature), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(117)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(110)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(103)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun105)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(117)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(110)), (ATerm)ATmakeInt(103)), (ATerm)ATmakeInt(105)), (ATerm)ATmakeInt(115)))));
}

/*}}}  */
/*{{{  MA_RulesOpt MA_makeRulesOptAbsent(void) */

MA_RulesOpt MA_makeRulesOptAbsent(void)
{
  return (MA_RulesOpt)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATempty, (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun107))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun104)))))), (ATerm)ATempty);
}

/*}}}  */
/*{{{  MA_RulesOpt MA_makeRulesOptPresent(MA_OptLayout wsAfterRules, MA_RuleList RuleList) */

MA_RulesOpt MA_makeRulesOptPresent(MA_OptLayout wsAfterRules, MA_RuleList RuleList)
{
  return (MA_RulesOpt)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun92)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun108))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun107))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun106)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) RuleList), (ATerm) wsAfterRules), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(117)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun108)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(115)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(108)), (ATerm)ATmakeInt(117)), (ATerm)ATmakeInt(114)))));
}

/*}}}  */
/*{{{  MA_Module MA_makeModuleModule(MA_OptLayout wsAfterModule, MA_ModId ModId, MA_OptLayout wsAfterModId, MA_SignatureOpt SignatureOpt, MA_OptLayout wsAfterSignatureOpt, MA_RulesOpt RulesOpt) */

MA_Module MA_makeModuleModule(MA_OptLayout wsAfterModule, MA_ModId ModId, MA_OptLayout wsAfterModId, MA_SignatureOpt SignatureOpt, MA_OptLayout wsAfterSignatureOpt, MA_RulesOpt RulesOpt)
{
  return (MA_Module)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun107)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun103)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun56)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun3, (ATerm)ATmakeAppl0(MA_afun4)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun109))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun110))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun109)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) RulesOpt), (ATerm) wsAfterSignatureOpt), (ATerm) SignatureOpt), (ATerm) wsAfterModId), (ATerm) ModId), (ATerm) wsAfterModule), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(117)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(100)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(109)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun109)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(108)), (ATerm)ATmakeInt(117)), (ATerm)ATmakeInt(100)), (ATerm)ATmakeInt(111)), (ATerm)ATmakeInt(109)))));
}

/*}}}  */
/*{{{  MA_TermArgs MA_makeTermArgsEmpty(void) */

MA_TermArgs MA_makeTermArgsEmpty(void)
{
  return (MA_TermArgs)(ATerm)ATempty;
}

/*}}}  */
/*{{{  MA_TermArgs MA_makeTermArgsSingle(MA_Term head) */

MA_TermArgs MA_makeTermArgsSingle(MA_Term head)
{
  return (MA_TermArgs)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  MA_TermArgs MA_makeTermArgsMany(MA_Term head, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_TermArgs tail) */

MA_TermArgs MA_makeTermArgsMany(MA_Term head, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_TermArgs tail)
{
  if (MA_isTermArgsEmpty(tail)) {
    return MA_makeTermArgsSingle(head);
  }
  return (MA_TermArgs)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm) wsAfterSep), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun62)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterHead), (ATerm) head);
}

/*}}}  */
/*{{{  MA_TermElems MA_makeTermElemsEmpty(void) */

MA_TermElems MA_makeTermElemsEmpty(void)
{
  return (MA_TermElems)(ATerm)ATempty;
}

/*}}}  */
/*{{{  MA_TermElems MA_makeTermElemsSingle(MA_Term head) */

MA_TermElems MA_makeTermElemsSingle(MA_Term head)
{
  return (MA_TermElems)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  MA_TermElems MA_makeTermElemsMany(MA_Term head, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_TermElems tail) */

MA_TermElems MA_makeTermElemsMany(MA_Term head, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_TermElems tail)
{
  if (MA_isTermElemsEmpty(tail)) {
    return MA_makeTermElemsSingle(head);
  }
  return (MA_TermElems)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm) wsAfterSep), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun62)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterHead), (ATerm) head);
}

/*}}}  */
/*{{{  MA_SigArgArgs MA_makeSigArgArgsEmpty(void) */

MA_SigArgArgs MA_makeSigArgArgsEmpty(void)
{
  return (MA_SigArgArgs)(ATerm)ATempty;
}

/*}}}  */
/*{{{  MA_SigArgArgs MA_makeSigArgArgsSingle(MA_SigArg head) */

MA_SigArgArgs MA_makeSigArgArgsSingle(MA_SigArg head)
{
  return (MA_SigArgArgs)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  MA_SigArgArgs MA_makeSigArgArgsMany(MA_SigArg head, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_SigArgArgs tail) */

MA_SigArgArgs MA_makeSigArgArgsMany(MA_SigArg head, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_SigArgArgs tail)
{
  if (MA_isSigArgArgsEmpty(tail)) {
    return MA_makeSigArgArgsSingle(head);
  }
  return (MA_SigArgArgs)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm) wsAfterSep), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun62)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterHead), (ATerm) head);
}

/*}}}  */
/*{{{  MA_TermAttrs MA_makeTermAttrsEmpty(void) */

MA_TermAttrs MA_makeTermAttrsEmpty(void)
{
  return (MA_TermAttrs)(ATerm)ATempty;
}

/*}}}  */
/*{{{  MA_TermAttrs MA_makeTermAttrsSingle(MA_Term head) */

MA_TermAttrs MA_makeTermAttrsSingle(MA_Term head)
{
  return (MA_TermAttrs)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  MA_TermAttrs MA_makeTermAttrsMany(MA_Term head, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_TermAttrs tail) */

MA_TermAttrs MA_makeTermAttrsMany(MA_Term head, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_TermAttrs tail)
{
  if (MA_isTermAttrsEmpty(tail)) {
    return MA_makeTermAttrsSingle(head);
  }
  return (MA_TermAttrs)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm) wsAfterSep), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun62)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterHead), (ATerm) head);
}

/*}}}  */
/*{{{  MA_FuncDefDefs MA_makeFuncDefDefsEmpty(void) */

MA_FuncDefDefs MA_makeFuncDefDefsEmpty(void)
{
  return (MA_FuncDefDefs)(ATerm)ATempty;
}

/*}}}  */
/*{{{  MA_FuncDefDefs MA_makeFuncDefDefsSingle(MA_FuncDef head) */

MA_FuncDefDefs MA_makeFuncDefDefsSingle(MA_FuncDef head)
{
  return (MA_FuncDefDefs)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  MA_FuncDefDefs MA_makeFuncDefDefsMany(MA_FuncDef head, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_FuncDefDefs tail) */

MA_FuncDefDefs MA_makeFuncDefDefsMany(MA_FuncDef head, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_FuncDefDefs tail)
{
  if (MA_isFuncDefDefsEmpty(tail)) {
    return MA_makeFuncDefDefsSingle(head);
  }
  return (MA_FuncDefDefs)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm) wsAfterSep), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(59)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun81)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(59)))), (ATerm) wsAfterHead), (ATerm) head);
}

/*}}}  */
/*{{{  MA_RuleRules MA_makeRuleRulesEmpty(void) */

MA_RuleRules MA_makeRuleRulesEmpty(void)
{
  return (MA_RuleRules)(ATerm)ATempty;
}

/*}}}  */
/*{{{  MA_RuleRules MA_makeRuleRulesSingle(MA_Rule head) */

MA_RuleRules MA_makeRuleRulesSingle(MA_Rule head)
{
  return (MA_RuleRules)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  MA_RuleRules MA_makeRuleRulesMany(MA_Rule head, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_RuleRules tail) */

MA_RuleRules MA_makeRuleRulesMany(MA_Rule head, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_RuleRules tail)
{
  if (MA_isRuleRulesEmpty(tail)) {
    return MA_makeRuleRulesSingle(head);
  }
  return (MA_RuleRules)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm) wsAfterSep), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(59)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun81)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(59)))), (ATerm) wsAfterHead), (ATerm) head);
}

/*}}}  */
/*{{{  MA_CondConds MA_makeCondCondsEmpty(void) */

MA_CondConds MA_makeCondCondsEmpty(void)
{
  return (MA_CondConds)(ATerm)ATempty;
}

/*}}}  */
/*{{{  MA_CondConds MA_makeCondCondsSingle(MA_Cond head) */

MA_CondConds MA_makeCondCondsSingle(MA_Cond head)
{
  return (MA_CondConds)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  MA_CondConds MA_makeCondCondsMany(MA_Cond head, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_CondConds tail) */

MA_CondConds MA_makeCondCondsMany(MA_Cond head, MA_OptLayout wsAfterHead, MA_OptLayout wsAfterSep, MA_CondConds tail)
{
  if (MA_isCondCondsEmpty(tail)) {
    return MA_makeCondCondsSingle(head);
  }
  return (MA_CondConds)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm) wsAfterSep), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(38)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun94)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(38)))), (ATerm) wsAfterHead), (ATerm) head);
}

/*}}}  */
/*{{{  MA_LexLayout MA_makeLexLayoutWhitespace(char ch) */

MA_LexLayout MA_makeLexLayoutWhitespace(char ch)
{
  return (MA_LexLayout)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(32)), (ATerm)ATmakeInt(13)), (ATerm)ATmakeAppl2(MA_afun111, (ATerm)ATmakeInt(9), (ATerm)ATmakeInt(10))))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeAppl0(MA_afun4)), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun112)))))), (ATerm)ATmakeList1((ATerm) ((ATerm) MA_byteToChar(ch))));
}

/*}}}  */
/*{{{  MA_LexStrChar MA_makeLexStrCharNewline(void) */

MA_LexStrChar MA_makeLexStrCharNewline(void)
{
  return (MA_LexStrChar)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun113))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun114))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun115)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(110)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun113)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(110)), (ATerm)ATmakeInt(92)))));
}

/*}}}  */
/*{{{  MA_LexStrChar MA_makeLexStrCharTab(void) */

MA_LexStrChar MA_makeLexStrCharTab(void)
{
  return (MA_LexStrChar)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun116))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun114))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun117)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun116)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(92)))));
}

/*}}}  */
/*{{{  MA_LexStrChar MA_makeLexStrCharQuote(void) */

MA_LexStrChar MA_makeLexStrCharQuote(void)
{
  return (MA_LexStrChar)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun118))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun114))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun119)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(34)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun118)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(34)), (ATerm)ATmakeInt(92)))));
}

/*}}}  */
/*{{{  MA_LexStrChar MA_makeLexStrCharBackslash(void) */

MA_LexStrChar MA_makeLexStrCharBackslash(void)
{
  return (MA_LexStrChar)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun120))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun114))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun121)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun120)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(92)), (ATerm)ATmakeInt(92)))));
}

/*}}}  */
/*{{{  MA_LexStrChar MA_makeLexStrCharDecimal(char a, char b, char c) */

MA_LexStrChar MA_makeLexStrCharDecimal(char a, char b, char c)
{
  return (MA_LexStrChar)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(MA_afun111, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(MA_afun111, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(MA_afun111, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun122))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun114))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun123)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) ((ATerm) MA_byteToChar(c))), (ATerm) ((ATerm) MA_byteToChar(b))), (ATerm) ((ATerm) MA_byteToChar(a))), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(MA_afun9, (ATerm)ATmakeAppl0(MA_afun122)), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))));
}

/*}}}  */
/*{{{  MA_LexStrChar MA_makeLexStrCharNormal(char ch) */

MA_LexStrChar MA_makeLexStrCharNormal(char ch)
{
  return (MA_LexStrChar)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(MA_afun111, (ATerm)ATmakeInt(93), (ATerm)ATmakeInt(255))), (ATerm)ATmakeAppl2(MA_afun111, (ATerm)ATmakeInt(35), (ATerm)ATmakeInt(91))), (ATerm)ATmakeAppl2(MA_afun111, (ATerm)ATmakeInt(32), (ATerm)ATmakeInt(33))))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun114))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun51)))))), (ATerm)ATmakeList1((ATerm) ((ATerm) MA_byteToChar(ch))));
}

/*}}}  */
/*{{{  MA_StrChar MA_makeStrCharLexToCf(MA_LexStrChar StrChar) */

MA_StrChar MA_makeStrCharLexToCf(MA_LexStrChar StrChar)
{
  return (MA_StrChar)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun114)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun114))), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm) StrChar));
}

/*}}}  */
/*{{{  MA_LexStrCon MA_makeLexStrConDefault(MA_LexStrCharChars chars) */

MA_LexStrCon MA_makeLexStrConDefault(MA_LexStrCharChars chars)
{
  return (MA_LexStrCon)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(34)))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeAppl1(MA_afun124, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun114))))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeInt(34)))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun31))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun125)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(34)), (ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl1(MA_afun8, (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeAppl1(MA_afun124, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun114))))), (ATerm) chars)), (ATerm)ATmakeInt(34)));
}

/*}}}  */
/*{{{  MA_StrCon MA_makeStrConLexToCf(MA_LexStrCon StrCon) */

MA_StrCon MA_makeStrConLexToCf(MA_LexStrCon StrCon)
{
  return (MA_StrCon)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun31)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun31))), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm) StrCon));
}

/*}}}  */
/*{{{  MA_LexStrCharChars MA_makeLexStrCharCharsEmpty(void) */

MA_LexStrCharChars MA_makeLexStrCharCharsEmpty(void)
{
  return (MA_LexStrCharChars)(ATerm)ATempty;
}

/*}}}  */
/*{{{  MA_LexStrCharChars MA_makeLexStrCharCharsSingle(MA_LexStrChar head) */

MA_LexStrCharChars MA_makeLexStrCharCharsSingle(MA_LexStrChar head)
{
  return (MA_LexStrCharChars)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  MA_LexStrCharChars MA_makeLexStrCharCharsMany(MA_LexStrChar head, MA_LexStrCharChars tail) */

MA_LexStrCharChars MA_makeLexStrCharCharsMany(MA_LexStrChar head, MA_LexStrCharChars tail)
{
  return (MA_LexStrCharChars)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/*}}}  */
/*{{{  MA_LexNatCon MA_makeLexNatConDigits(const char* list) */

MA_LexNatCon MA_makeLexNatConDigits(const char* list)
{
  return (MA_LexNatCon)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(MA_afun111, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))))))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun25))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun126)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl1(MA_afun8, (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeAppl1(MA_afun7, (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(MA_afun111, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))))))), (ATerm) ((ATerm) MA_stringToChars(list)))));
}

/*}}}  */
/*{{{  MA_NatCon MA_makeNatConLexToCf(MA_LexNatCon NatCon) */

MA_NatCon MA_makeNatConLexToCf(MA_LexNatCon NatCon)
{
  return (MA_NatCon)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun25)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun25))), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm) NatCon));
}

/*}}}  */
/*{{{  MA_LexIdCon MA_makeLexIdConDefault(char head, const char* tail) */

MA_LexIdCon MA_makeLexIdConDefault(char head, const char* tail)
{
  return (MA_LexIdCon)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeAppl1(MA_afun124, (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(MA_afun111, (ATerm)ATmakeInt(97), (ATerm)ATmakeInt(122))), (ATerm)ATmakeAppl2(MA_afun111, (ATerm)ATmakeInt(65), (ATerm)ATmakeInt(90))), (ATerm)ATmakeAppl2(MA_afun111, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))), (ATerm)ATmakeInt(45)))))), (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl2(MA_afun111, (ATerm)ATmakeInt(97), (ATerm)ATmakeInt(122))), (ATerm)ATmakeAppl2(MA_afun111, (ATerm)ATmakeInt(65), (ATerm)ATmakeInt(90))))), (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))), (ATerm)ATmakeAppl1(MA_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun14, (ATerm)ATmakeAppl1(MA_afun15, (ATerm)ATmakeAppl0(MA_afun125)))))), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl1(MA_afun8, (ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeAppl1(MA_afun124, (ATerm)ATmakeAppl1(MA_afun16, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(MA_afun111, (ATerm)ATmakeInt(97), (ATerm)ATmakeInt(122))), (ATerm)ATmakeAppl2(MA_afun111, (ATerm)ATmakeInt(65), (ATerm)ATmakeInt(90))), (ATerm)ATmakeAppl2(MA_afun111, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))), (ATerm)ATmakeInt(45)))))), (ATerm) ((ATerm) MA_stringToChars(tail)))), (ATerm) ((ATerm) MA_byteToChar(head))));
}

/*}}}  */
/*{{{  MA_IdCon MA_makeIdConLexToCf(MA_LexIdCon IdCon) */

MA_IdCon MA_makeIdConLexToCf(MA_LexIdCon IdCon)
{
  return (MA_IdCon)(ATerm)ATmakeAppl2(MA_afun0, (ATerm)ATmakeAppl3(MA_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(MA_afun6, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28)))), (ATerm)ATmakeAppl1(MA_afun2, (ATerm)ATmakeAppl1(MA_afun11, (ATerm)ATmakeAppl0(MA_afun28))), (ATerm)ATmakeAppl0(MA_afun5)), (ATerm)ATmakeList1((ATerm) IdCon));
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool MA_isEqualOptLayout(MA_OptLayout arg0, MA_OptLayout arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualLayout(MA_Layout arg0, MA_Layout arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualLexLayoutList(MA_LexLayoutList arg0, MA_LexLayoutList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualTraversalStrategy(MA_TraversalStrategy arg0, MA_TraversalStrategy arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualTraversalType(MA_TraversalType arg0, MA_TraversalType arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualTraversalContinuation(MA_TraversalContinuation arg0, MA_TraversalContinuation arg1)
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

ATbool MA_isEqualTerm(MA_Term arg0, MA_Term arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualTermList(MA_TermList arg0, MA_TermList arg1)
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

ATbool MA_isEqualAnnotations(MA_Annotations arg0, MA_Annotations arg1)
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

ATbool MA_isEqualRule(MA_Rule arg0, MA_Rule arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualRuleList(MA_RuleList arg0, MA_RuleList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualCondList(MA_CondList arg0, MA_CondList arg1)
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

ATbool MA_isEqualTermArgs(MA_TermArgs arg0, MA_TermArgs arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualTermElems(MA_TermElems arg0, MA_TermElems arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualSigArgArgs(MA_SigArgArgs arg0, MA_SigArgArgs arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualTermAttrs(MA_TermAttrs arg0, MA_TermAttrs arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualFuncDefDefs(MA_FuncDefDefs arg0, MA_FuncDefDefs arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualRuleRules(MA_RuleRules arg0, MA_RuleRules arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualCondConds(MA_CondConds arg0, MA_CondConds arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualLexLayout(MA_LexLayout arg0, MA_LexLayout arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualLexStrChar(MA_LexStrChar arg0, MA_LexStrChar arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualStrChar(MA_StrChar arg0, MA_StrChar arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualLexStrCon(MA_LexStrCon arg0, MA_LexStrCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualStrCon(MA_StrCon arg0, MA_StrCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualLexStrCharChars(MA_LexStrCharChars arg0, MA_LexStrCharChars arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualLexNatCon(MA_LexNatCon arg0, MA_LexNatCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualNatCon(MA_NatCon arg0, MA_NatCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualLexIdCon(MA_LexIdCon arg0, MA_LexIdCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool MA_isEqualIdCon(MA_IdCon arg0, MA_IdCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  MA_OptLayout accessors */

/*{{{  ATbool MA_isValidOptLayout(MA_OptLayout arg) */

ATbool MA_isValidOptLayout(MA_OptLayout arg)
{
  if (MA_isOptLayoutAbsent(arg)) {
    return ATtrue;
  }
  else if (MA_isOptLayoutPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isOptLayoutAbsent(MA_OptLayout arg) */

inline ATbool MA_isOptLayoutAbsent(MA_OptLayout arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternOptLayoutAbsent);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isOptLayoutPresent(MA_OptLayout arg) */

inline ATbool MA_isOptLayoutPresent(MA_OptLayout arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternOptLayoutPresent, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MA_hasOptLayoutLayout(MA_OptLayout arg) */

ATbool MA_hasOptLayoutLayout(MA_OptLayout arg)
{
  if (MA_isOptLayoutPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_Layout MA_getOptLayoutLayout(MA_OptLayout arg) */

MA_Layout MA_getOptLayoutLayout(MA_OptLayout arg)
{
  
    return (MA_Layout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  MA_OptLayout MA_setOptLayoutLayout(MA_OptLayout arg, MA_Layout layout) */

MA_OptLayout MA_setOptLayoutLayout(MA_OptLayout arg, MA_Layout layout)
{
  if (MA_isOptLayoutPresent(arg)) {
    return (MA_OptLayout)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) layout), 0), 1);
  }

  ATabort("OptLayout has no Layout: %t\n", arg);
  return (MA_OptLayout)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_Layout accessors */

/*{{{  ATbool MA_isValidLayout(MA_Layout arg) */

ATbool MA_isValidLayout(MA_Layout arg)
{
  if (MA_isLayoutLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isLayoutLexToCf(MA_Layout arg) */

inline ATbool MA_isLayoutLexToCf(MA_Layout arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MA_patternLayoutLexToCf, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool MA_hasLayoutList(MA_Layout arg) */

ATbool MA_hasLayoutList(MA_Layout arg)
{
  if (MA_isLayoutLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_LexLayoutList MA_getLayoutList(MA_Layout arg) */

MA_LexLayoutList MA_getLayoutList(MA_Layout arg)
{
  
    return (MA_LexLayoutList)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  MA_Layout MA_setLayoutList(MA_Layout arg, MA_LexLayoutList list) */

MA_Layout MA_setLayoutList(MA_Layout arg, MA_LexLayoutList list)
{
  if (MA_isLayoutLexToCf(arg)) {
    return (MA_Layout)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) list), 1), 0), 1);
  }

  ATabort("Layout has no List: %t\n", arg);
  return (MA_Layout)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_LexLayoutList accessors */

/*{{{  ATbool MA_isValidLexLayoutList(MA_LexLayoutList arg) */

ATbool MA_isValidLexLayoutList(MA_LexLayoutList arg)
{
  if (MA_isLexLayoutListEmpty(arg)) {
    return ATtrue;
  }
  else if (MA_isLexLayoutListSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isLexLayoutListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isLexLayoutListEmpty(MA_LexLayoutList arg) */

inline ATbool MA_isLexLayoutListEmpty(MA_LexLayoutList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MA_patternLexLayoutListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool MA_isLexLayoutListSingle(MA_LexLayoutList arg) */

inline ATbool MA_isLexLayoutListSingle(MA_LexLayoutList arg)
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
      last_result = ATmatchTerm((ATerm)arg, MA_patternLexLayoutListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isLexLayoutListMany(MA_LexLayoutList arg) */

inline ATbool MA_isLexLayoutListMany(MA_LexLayoutList arg)
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
      last_result = ATmatchTerm((ATerm)arg, MA_patternLexLayoutListMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MA_hasLexLayoutListHead(MA_LexLayoutList arg) */

ATbool MA_hasLexLayoutListHead(MA_LexLayoutList arg)
{
  if (MA_isLexLayoutListSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isLexLayoutListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasLexLayoutListTail(MA_LexLayoutList arg) */

ATbool MA_hasLexLayoutListTail(MA_LexLayoutList arg)
{
  if (MA_isLexLayoutListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_LexLayout MA_getLexLayoutListHead(MA_LexLayoutList arg) */

MA_LexLayout MA_getLexLayoutListHead(MA_LexLayoutList arg)
{
  if (MA_isLexLayoutListSingle(arg)) {
    return (MA_LexLayout)ATgetFirst((ATermList)arg);
  }
  else 
    return (MA_LexLayout)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  MA_LexLayoutList MA_getLexLayoutListTail(MA_LexLayoutList arg) */

MA_LexLayoutList MA_getLexLayoutListTail(MA_LexLayoutList arg)
{
  
    return (MA_LexLayoutList)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  MA_LexLayoutList MA_setLexLayoutListHead(MA_LexLayoutList arg, MA_LexLayout head) */

MA_LexLayoutList MA_setLexLayoutListHead(MA_LexLayoutList arg, MA_LexLayout head)
{
  if (MA_isLexLayoutListSingle(arg)) {
    return (MA_LexLayoutList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (MA_isLexLayoutListMany(arg)) {
    return (MA_LexLayoutList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("LexLayoutList has no Head: %t\n", arg);
  return (MA_LexLayoutList)NULL;
}

/*}}}  */
/*{{{  MA_LexLayoutList MA_setLexLayoutListTail(MA_LexLayoutList arg, MA_LexLayoutList tail) */

MA_LexLayoutList MA_setLexLayoutListTail(MA_LexLayoutList arg, MA_LexLayoutList tail)
{
  if (MA_isLexLayoutListMany(arg)) {
    return (MA_LexLayoutList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("LexLayoutList has no Tail: %t\n", arg);
  return (MA_LexLayoutList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_TraversalStrategy accessors */

/*{{{  ATbool MA_isValidTraversalStrategy(MA_TraversalStrategy arg) */

ATbool MA_isValidTraversalStrategy(MA_TraversalStrategy arg)
{
  if (MA_isTraversalStrategyBottomUp(arg)) {
    return ATtrue;
  }
  else if (MA_isTraversalStrategyTopDown(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isTraversalStrategyBottomUp(MA_TraversalStrategy arg) */

inline ATbool MA_isTraversalStrategyBottomUp(MA_TraversalStrategy arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternTraversalStrategyBottomUp);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isTraversalStrategyTopDown(MA_TraversalStrategy arg) */

inline ATbool MA_isTraversalStrategyTopDown(MA_TraversalStrategy arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternTraversalStrategyTopDown);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */

/*}}}  */
/*{{{  MA_TraversalType accessors */

/*{{{  ATbool MA_isValidTraversalType(MA_TraversalType arg) */

ATbool MA_isValidTraversalType(MA_TraversalType arg)
{
  if (MA_isTraversalTypeTrafo(arg)) {
    return ATtrue;
  }
  else if (MA_isTraversalTypeAccu(arg)) {
    return ATtrue;
  }
  else if (MA_isTraversalTypeAccutrafo(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isTraversalTypeTrafo(MA_TraversalType arg) */

inline ATbool MA_isTraversalTypeTrafo(MA_TraversalType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternTraversalTypeTrafo);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isTraversalTypeAccu(MA_TraversalType arg) */

inline ATbool MA_isTraversalTypeAccu(MA_TraversalType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternTraversalTypeAccu);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isTraversalTypeAccutrafo(MA_TraversalType arg) */

inline ATbool MA_isTraversalTypeAccutrafo(MA_TraversalType arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternTraversalTypeAccutrafo);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */

/*}}}  */
/*{{{  MA_TraversalContinuation accessors */

/*{{{  ATbool MA_isValidTraversalContinuation(MA_TraversalContinuation arg) */

ATbool MA_isValidTraversalContinuation(MA_TraversalContinuation arg)
{
  if (MA_isTraversalContinuationBreak(arg)) {
    return ATtrue;
  }
  else if (MA_isTraversalContinuationContinue(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isTraversalContinuationBreak(MA_TraversalContinuation arg) */

inline ATbool MA_isTraversalContinuationBreak(MA_TraversalContinuation arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternTraversalContinuationBreak);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isTraversalContinuationContinue(MA_TraversalContinuation arg) */

inline ATbool MA_isTraversalContinuationContinue(MA_TraversalContinuation arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternTraversalContinuationContinue);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */

/*}}}  */
/*{{{  MA_FunId accessors */

/*{{{  ATbool MA_isValidFunId(MA_FunId arg) */

ATbool MA_isValidFunId(MA_FunId arg)
{
  if (MA_isFunIdCharacter(arg)) {
    return ATtrue;
  }
  else if (MA_isFunIdUnquoted(arg)) {
    return ATtrue;
  }
  else if (MA_isFunIdQuoted(arg)) {
    return ATtrue;
  }
  else if (MA_isFunIdReturnsList(arg)) {
    return ATtrue;
  }
  else if (MA_isFunIdList(arg)) {
    return ATtrue;
  }
  else if (MA_isFunIdIgnored(arg)) {
    return ATtrue;
  }
  else if (MA_isFunIdTranslate(arg)) {
    return ATtrue;
  }
  else if (MA_isFunIdTraversal(arg)) {
    return ATtrue;
  }
  else if (MA_isFunIdConcat(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isFunIdCharacter(MA_FunId arg) */

inline ATbool MA_isFunIdCharacter(MA_FunId arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternFunIdCharacter, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isFunIdUnquoted(MA_FunId arg) */

inline ATbool MA_isFunIdUnquoted(MA_FunId arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternFunIdUnquoted, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isFunIdQuoted(MA_FunId arg) */

inline ATbool MA_isFunIdQuoted(MA_FunId arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternFunIdQuoted, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isFunIdReturnsList(MA_FunId arg) */

inline ATbool MA_isFunIdReturnsList(MA_FunId arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternFunIdReturnsList, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isFunIdList(MA_FunId arg) */

inline ATbool MA_isFunIdList(MA_FunId arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternFunIdList, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isFunIdIgnored(MA_FunId arg) */

inline ATbool MA_isFunIdIgnored(MA_FunId arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternFunIdIgnored, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isFunIdTranslate(MA_FunId arg) */

inline ATbool MA_isFunIdTranslate(MA_FunId arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternFunIdTranslate, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isFunIdTraversal(MA_FunId arg) */

inline ATbool MA_isFunIdTraversal(MA_FunId arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternFunIdTraversal, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isFunIdConcat(MA_FunId arg) */

inline ATbool MA_isFunIdConcat(MA_FunId arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternFunIdConcat, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MA_hasFunIdNatCon(MA_FunId arg) */

ATbool MA_hasFunIdNatCon(MA_FunId arg)
{
  if (MA_isFunIdCharacter(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasFunIdIdCon(MA_FunId arg) */

ATbool MA_hasFunIdIdCon(MA_FunId arg)
{
  if (MA_isFunIdUnquoted(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasFunIdStrCon(MA_FunId arg) */

ATbool MA_hasFunIdStrCon(MA_FunId arg)
{
  if (MA_isFunIdQuoted(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasFunIdWsAfterBracketOpen(MA_FunId arg) */

ATbool MA_hasFunIdWsAfterBracketOpen(MA_FunId arg)
{
  if (MA_isFunIdReturnsList(arg)) {
    return ATtrue;
  }
  else if (MA_isFunIdIgnored(arg)) {
    return ATtrue;
  }
  else if (MA_isFunIdTranslate(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasFunIdFunId(MA_FunId arg) */

ATbool MA_hasFunIdFunId(MA_FunId arg)
{
  if (MA_isFunIdReturnsList(arg)) {
    return ATtrue;
  }
  else if (MA_isFunIdList(arg)) {
    return ATtrue;
  }
  else if (MA_isFunIdIgnored(arg)) {
    return ATtrue;
  }
  else if (MA_isFunIdTranslate(arg)) {
    return ATtrue;
  }
  else if (MA_isFunIdTraversal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasFunIdWsAfterFunId(MA_FunId arg) */

ATbool MA_hasFunIdWsAfterFunId(MA_FunId arg)
{
  if (MA_isFunIdReturnsList(arg)) {
    return ATtrue;
  }
  else if (MA_isFunIdList(arg)) {
    return ATtrue;
  }
  else if (MA_isFunIdIgnored(arg)) {
    return ATtrue;
  }
  else if (MA_isFunIdTranslate(arg)) {
    return ATtrue;
  }
  else if (MA_isFunIdTraversal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasFunIdWsAfterBraceOpen(MA_FunId arg) */

ATbool MA_hasFunIdWsAfterBraceOpen(MA_FunId arg)
{
  if (MA_isFunIdList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasFunIdWsAfterIGNORE(MA_FunId arg) */

ATbool MA_hasFunIdWsAfterIGNORE(MA_FunId arg)
{
  if (MA_isFunIdIgnored(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasFunIdWsAfterTRANSLATE(MA_FunId arg) */

ATbool MA_hasFunIdWsAfterTRANSLATE(MA_FunId arg)
{
  if (MA_isFunIdTranslate(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasFunIdWsAfterBar(MA_FunId arg) */

ATbool MA_hasFunIdWsAfterBar(MA_FunId arg)
{
  if (MA_isFunIdTraversal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasFunIdTraversalType(MA_FunId arg) */

ATbool MA_hasFunIdTraversalType(MA_FunId arg)
{
  if (MA_isFunIdTraversal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasFunIdWsAfterTraversalType(MA_FunId arg) */

ATbool MA_hasFunIdWsAfterTraversalType(MA_FunId arg)
{
  if (MA_isFunIdTraversal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasFunIdTraversalStrategy(MA_FunId arg) */

ATbool MA_hasFunIdTraversalStrategy(MA_FunId arg)
{
  if (MA_isFunIdTraversal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasFunIdWsAfterTraversalStrategy(MA_FunId arg) */

ATbool MA_hasFunIdWsAfterTraversalStrategy(MA_FunId arg)
{
  if (MA_isFunIdTraversal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasFunIdTraversalContinuation(MA_FunId arg) */

ATbool MA_hasFunIdTraversalContinuation(MA_FunId arg)
{
  if (MA_isFunIdTraversal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasFunIdWsAfterTraversalContinuation(MA_FunId arg) */

ATbool MA_hasFunIdWsAfterTraversalContinuation(MA_FunId arg)
{
  if (MA_isFunIdTraversal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasFunIdLhs(MA_FunId arg) */

ATbool MA_hasFunIdLhs(MA_FunId arg)
{
  if (MA_isFunIdConcat(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasFunIdWsAfterLhs(MA_FunId arg) */

ATbool MA_hasFunIdWsAfterLhs(MA_FunId arg)
{
  if (MA_isFunIdConcat(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasFunIdWsAfterPlusPlus(MA_FunId arg) */

ATbool MA_hasFunIdWsAfterPlusPlus(MA_FunId arg)
{
  if (MA_isFunIdConcat(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasFunIdRhs(MA_FunId arg) */

ATbool MA_hasFunIdRhs(MA_FunId arg)
{
  if (MA_isFunIdConcat(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_NatCon MA_getFunIdNatCon(MA_FunId arg) */

MA_NatCon MA_getFunIdNatCon(MA_FunId arg)
{
  
    return (MA_NatCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  MA_IdCon MA_getFunIdIdCon(MA_FunId arg) */

MA_IdCon MA_getFunIdIdCon(MA_FunId arg)
{
  
    return (MA_IdCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  MA_StrCon MA_getFunIdStrCon(MA_FunId arg) */

MA_StrCon MA_getFunIdStrCon(MA_FunId arg)
{
  
    return (MA_StrCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  MA_OptLayout MA_getFunIdWsAfterBracketOpen(MA_FunId arg) */

MA_OptLayout MA_getFunIdWsAfterBracketOpen(MA_FunId arg)
{
  if (MA_isFunIdReturnsList(arg)) {
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else if (MA_isFunIdIgnored(arg)) {
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  MA_FunId MA_getFunIdFunId(MA_FunId arg) */

MA_FunId MA_getFunIdFunId(MA_FunId arg)
{
  if (MA_isFunIdReturnsList(arg)) {
    return (MA_FunId)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else if (MA_isFunIdList(arg)) {
    return (MA_FunId)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else if (MA_isFunIdIgnored(arg)) {
    return (MA_FunId)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else if (MA_isFunIdTranslate(arg)) {
    return (MA_FunId)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (MA_FunId)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getFunIdWsAfterFunId(MA_FunId arg) */

MA_OptLayout MA_getFunIdWsAfterFunId(MA_FunId arg)
{
  if (MA_isFunIdReturnsList(arg)) {
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (MA_isFunIdList(arg)) {
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (MA_isFunIdIgnored(arg)) {
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else if (MA_isFunIdTranslate(arg)) {
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else 
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getFunIdWsAfterBraceOpen(MA_FunId arg) */

MA_OptLayout MA_getFunIdWsAfterBraceOpen(MA_FunId arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getFunIdWsAfterIGNORE(MA_FunId arg) */

MA_OptLayout MA_getFunIdWsAfterIGNORE(MA_FunId arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getFunIdWsAfterTRANSLATE(MA_FunId arg) */

MA_OptLayout MA_getFunIdWsAfterTRANSLATE(MA_FunId arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getFunIdWsAfterBar(MA_FunId arg) */

MA_OptLayout MA_getFunIdWsAfterBar(MA_FunId arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_TraversalType MA_getFunIdTraversalType(MA_FunId arg) */

MA_TraversalType MA_getFunIdTraversalType(MA_FunId arg)
{
  
    return (MA_TraversalType)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getFunIdWsAfterTraversalType(MA_FunId arg) */

MA_OptLayout MA_getFunIdWsAfterTraversalType(MA_FunId arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  MA_TraversalStrategy MA_getFunIdTraversalStrategy(MA_FunId arg) */

MA_TraversalStrategy MA_getFunIdTraversalStrategy(MA_FunId arg)
{
  
    return (MA_TraversalStrategy)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getFunIdWsAfterTraversalStrategy(MA_FunId arg) */

MA_OptLayout MA_getFunIdWsAfterTraversalStrategy(MA_FunId arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  MA_TraversalContinuation MA_getFunIdTraversalContinuation(MA_FunId arg) */

MA_TraversalContinuation MA_getFunIdTraversalContinuation(MA_FunId arg)
{
  
    return (MA_TraversalContinuation)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getFunIdWsAfterTraversalContinuation(MA_FunId arg) */

MA_OptLayout MA_getFunIdWsAfterTraversalContinuation(MA_FunId arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/*}}}  */
/*{{{  MA_FunId MA_getFunIdLhs(MA_FunId arg) */

MA_FunId MA_getFunIdLhs(MA_FunId arg)
{
  
    return (MA_FunId)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  MA_OptLayout MA_getFunIdWsAfterLhs(MA_FunId arg) */

MA_OptLayout MA_getFunIdWsAfterLhs(MA_FunId arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getFunIdWsAfterPlusPlus(MA_FunId arg) */

MA_OptLayout MA_getFunIdWsAfterPlusPlus(MA_FunId arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  MA_FunId MA_getFunIdRhs(MA_FunId arg) */

MA_FunId MA_getFunIdRhs(MA_FunId arg)
{
  
    return (MA_FunId)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  MA_FunId MA_setFunIdNatCon(MA_FunId arg, MA_NatCon NatCon) */

MA_FunId MA_setFunIdNatCon(MA_FunId arg, MA_NatCon NatCon)
{
  if (MA_isFunIdCharacter(arg)) {
    return (MA_FunId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) NatCon), 0), 1);
  }

  ATabort("FunId has no NatCon: %t\n", arg);
  return (MA_FunId)NULL;
}

/*}}}  */
/*{{{  MA_FunId MA_setFunIdIdCon(MA_FunId arg, MA_IdCon IdCon) */

MA_FunId MA_setFunIdIdCon(MA_FunId arg, MA_IdCon IdCon)
{
  if (MA_isFunIdUnquoted(arg)) {
    return (MA_FunId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) IdCon), 0), 1);
  }

  ATabort("FunId has no IdCon: %t\n", arg);
  return (MA_FunId)NULL;
}

/*}}}  */
/*{{{  MA_FunId MA_setFunIdStrCon(MA_FunId arg, MA_StrCon StrCon) */

MA_FunId MA_setFunIdStrCon(MA_FunId arg, MA_StrCon StrCon)
{
  if (MA_isFunIdQuoted(arg)) {
    return (MA_FunId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) StrCon), 0), 1);
  }

  ATabort("FunId has no StrCon: %t\n", arg);
  return (MA_FunId)NULL;
}

/*}}}  */
/*{{{  MA_FunId MA_setFunIdWsAfterBracketOpen(MA_FunId arg, MA_OptLayout wsAfterBracketOpen) */

MA_FunId MA_setFunIdWsAfterBracketOpen(MA_FunId arg, MA_OptLayout wsAfterBracketOpen)
{
  if (MA_isFunIdReturnsList(arg)) {
    return (MA_FunId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 1), 1);
  }
  else if (MA_isFunIdIgnored(arg)) {
    return (MA_FunId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 3), 1);
  }
  else if (MA_isFunIdTranslate(arg)) {
    return (MA_FunId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 3), 1);
  }

  ATabort("FunId has no WsAfterBracketOpen: %t\n", arg);
  return (MA_FunId)NULL;
}

/*}}}  */
/*{{{  MA_FunId MA_setFunIdFunId(MA_FunId arg, MA_FunId FunId) */

MA_FunId MA_setFunIdFunId(MA_FunId arg, MA_FunId FunId)
{
  if (MA_isFunIdReturnsList(arg)) {
    return (MA_FunId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) FunId), 2), 1);
  }
  else if (MA_isFunIdList(arg)) {
    return (MA_FunId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) FunId), 2), 1);
  }
  else if (MA_isFunIdIgnored(arg)) {
    return (MA_FunId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) FunId), 4), 1);
  }
  else if (MA_isFunIdTranslate(arg)) {
    return (MA_FunId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) FunId), 4), 1);
  }
  else if (MA_isFunIdTraversal(arg)) {
    return (MA_FunId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) FunId), 2), 1);
  }

  ATabort("FunId has no FunId: %t\n", arg);
  return (MA_FunId)NULL;
}

/*}}}  */
/*{{{  MA_FunId MA_setFunIdWsAfterFunId(MA_FunId arg, MA_OptLayout wsAfterFunId) */

MA_FunId MA_setFunIdWsAfterFunId(MA_FunId arg, MA_OptLayout wsAfterFunId)
{
  if (MA_isFunIdReturnsList(arg)) {
    return (MA_FunId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterFunId), 3), 1);
  }
  else if (MA_isFunIdList(arg)) {
    return (MA_FunId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterFunId), 3), 1);
  }
  else if (MA_isFunIdIgnored(arg)) {
    return (MA_FunId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterFunId), 5), 1);
  }
  else if (MA_isFunIdTranslate(arg)) {
    return (MA_FunId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterFunId), 5), 1);
  }
  else if (MA_isFunIdTraversal(arg)) {
    return (MA_FunId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterFunId), 3), 1);
  }

  ATabort("FunId has no WsAfterFunId: %t\n", arg);
  return (MA_FunId)NULL;
}

/*}}}  */
/*{{{  MA_FunId MA_setFunIdWsAfterBraceOpen(MA_FunId arg, MA_OptLayout wsAfterBraceOpen) */

MA_FunId MA_setFunIdWsAfterBraceOpen(MA_FunId arg, MA_OptLayout wsAfterBraceOpen)
{
  if (MA_isFunIdList(arg)) {
    return (MA_FunId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBraceOpen), 1), 1);
  }

  ATabort("FunId has no WsAfterBraceOpen: %t\n", arg);
  return (MA_FunId)NULL;
}

/*}}}  */
/*{{{  MA_FunId MA_setFunIdWsAfterIGNORE(MA_FunId arg, MA_OptLayout wsAfterIGNORE) */

MA_FunId MA_setFunIdWsAfterIGNORE(MA_FunId arg, MA_OptLayout wsAfterIGNORE)
{
  if (MA_isFunIdIgnored(arg)) {
    return (MA_FunId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterIGNORE), 1), 1);
  }

  ATabort("FunId has no WsAfterIGNORE: %t\n", arg);
  return (MA_FunId)NULL;
}

/*}}}  */
/*{{{  MA_FunId MA_setFunIdWsAfterTRANSLATE(MA_FunId arg, MA_OptLayout wsAfterTRANSLATE) */

MA_FunId MA_setFunIdWsAfterTRANSLATE(MA_FunId arg, MA_OptLayout wsAfterTRANSLATE)
{
  if (MA_isFunIdTranslate(arg)) {
    return (MA_FunId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterTRANSLATE), 1), 1);
  }

  ATabort("FunId has no WsAfterTRANSLATE: %t\n", arg);
  return (MA_FunId)NULL;
}

/*}}}  */
/*{{{  MA_FunId MA_setFunIdWsAfterBar(MA_FunId arg, MA_OptLayout wsAfterBar) */

MA_FunId MA_setFunIdWsAfterBar(MA_FunId arg, MA_OptLayout wsAfterBar)
{
  if (MA_isFunIdTraversal(arg)) {
    return (MA_FunId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBar), 1), 1);
  }

  ATabort("FunId has no WsAfterBar: %t\n", arg);
  return (MA_FunId)NULL;
}

/*}}}  */
/*{{{  MA_FunId MA_setFunIdTraversalType(MA_FunId arg, MA_TraversalType TraversalType) */

MA_FunId MA_setFunIdTraversalType(MA_FunId arg, MA_TraversalType TraversalType)
{
  if (MA_isFunIdTraversal(arg)) {
    return (MA_FunId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) TraversalType), 4), 1);
  }

  ATabort("FunId has no TraversalType: %t\n", arg);
  return (MA_FunId)NULL;
}

/*}}}  */
/*{{{  MA_FunId MA_setFunIdWsAfterTraversalType(MA_FunId arg, MA_OptLayout wsAfterTraversalType) */

MA_FunId MA_setFunIdWsAfterTraversalType(MA_FunId arg, MA_OptLayout wsAfterTraversalType)
{
  if (MA_isFunIdTraversal(arg)) {
    return (MA_FunId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterTraversalType), 5), 1);
  }

  ATabort("FunId has no WsAfterTraversalType: %t\n", arg);
  return (MA_FunId)NULL;
}

/*}}}  */
/*{{{  MA_FunId MA_setFunIdTraversalStrategy(MA_FunId arg, MA_TraversalStrategy TraversalStrategy) */

MA_FunId MA_setFunIdTraversalStrategy(MA_FunId arg, MA_TraversalStrategy TraversalStrategy)
{
  if (MA_isFunIdTraversal(arg)) {
    return (MA_FunId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) TraversalStrategy), 6), 1);
  }

  ATabort("FunId has no TraversalStrategy: %t\n", arg);
  return (MA_FunId)NULL;
}

/*}}}  */
/*{{{  MA_FunId MA_setFunIdWsAfterTraversalStrategy(MA_FunId arg, MA_OptLayout wsAfterTraversalStrategy) */

MA_FunId MA_setFunIdWsAfterTraversalStrategy(MA_FunId arg, MA_OptLayout wsAfterTraversalStrategy)
{
  if (MA_isFunIdTraversal(arg)) {
    return (MA_FunId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterTraversalStrategy), 7), 1);
  }

  ATabort("FunId has no WsAfterTraversalStrategy: %t\n", arg);
  return (MA_FunId)NULL;
}

/*}}}  */
/*{{{  MA_FunId MA_setFunIdTraversalContinuation(MA_FunId arg, MA_TraversalContinuation TraversalContinuation) */

MA_FunId MA_setFunIdTraversalContinuation(MA_FunId arg, MA_TraversalContinuation TraversalContinuation)
{
  if (MA_isFunIdTraversal(arg)) {
    return (MA_FunId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) TraversalContinuation), 8), 1);
  }

  ATabort("FunId has no TraversalContinuation: %t\n", arg);
  return (MA_FunId)NULL;
}

/*}}}  */
/*{{{  MA_FunId MA_setFunIdWsAfterTraversalContinuation(MA_FunId arg, MA_OptLayout wsAfterTraversalContinuation) */

MA_FunId MA_setFunIdWsAfterTraversalContinuation(MA_FunId arg, MA_OptLayout wsAfterTraversalContinuation)
{
  if (MA_isFunIdTraversal(arg)) {
    return (MA_FunId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterTraversalContinuation), 9), 1);
  }

  ATabort("FunId has no WsAfterTraversalContinuation: %t\n", arg);
  return (MA_FunId)NULL;
}

/*}}}  */
/*{{{  MA_FunId MA_setFunIdLhs(MA_FunId arg, MA_FunId lhs) */

MA_FunId MA_setFunIdLhs(MA_FunId arg, MA_FunId lhs)
{
  if (MA_isFunIdConcat(arg)) {
    return (MA_FunId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) lhs), 0), 1);
  }

  ATabort("FunId has no Lhs: %t\n", arg);
  return (MA_FunId)NULL;
}

/*}}}  */
/*{{{  MA_FunId MA_setFunIdWsAfterLhs(MA_FunId arg, MA_OptLayout wsAfterLhs) */

MA_FunId MA_setFunIdWsAfterLhs(MA_FunId arg, MA_OptLayout wsAfterLhs)
{
  if (MA_isFunIdConcat(arg)) {
    return (MA_FunId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLhs), 1), 1);
  }

  ATabort("FunId has no WsAfterLhs: %t\n", arg);
  return (MA_FunId)NULL;
}

/*}}}  */
/*{{{  MA_FunId MA_setFunIdWsAfterPlusPlus(MA_FunId arg, MA_OptLayout wsAfterPlusPlus) */

MA_FunId MA_setFunIdWsAfterPlusPlus(MA_FunId arg, MA_OptLayout wsAfterPlusPlus)
{
  if (MA_isFunIdConcat(arg)) {
    return (MA_FunId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterPlusPlus), 3), 1);
  }

  ATabort("FunId has no WsAfterPlusPlus: %t\n", arg);
  return (MA_FunId)NULL;
}

/*}}}  */
/*{{{  MA_FunId MA_setFunIdRhs(MA_FunId arg, MA_FunId rhs) */

MA_FunId MA_setFunIdRhs(MA_FunId arg, MA_FunId rhs)
{
  if (MA_isFunIdConcat(arg)) {
    return (MA_FunId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) rhs), 4), 1);
  }

  ATabort("FunId has no Rhs: %t\n", arg);
  return (MA_FunId)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_VarId accessors */

/*{{{  ATbool MA_isValidVarId(MA_VarId arg) */

ATbool MA_isValidVarId(MA_VarId arg)
{
  if (MA_isVarIdNormal(arg)) {
    return ATtrue;
  }
  else if (MA_isVarIdPlus(arg)) {
    return ATtrue;
  }
  else if (MA_isVarIdStar(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isVarIdNormal(MA_VarId arg) */

inline ATbool MA_isVarIdNormal(MA_VarId arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternVarIdNormal, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isVarIdPlus(MA_VarId arg) */

inline ATbool MA_isVarIdPlus(MA_VarId arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternVarIdPlus, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isVarIdStar(MA_VarId arg) */

inline ATbool MA_isVarIdStar(MA_VarId arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternVarIdStar, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MA_hasVarIdWsAfterDollar(MA_VarId arg) */

ATbool MA_hasVarIdWsAfterDollar(MA_VarId arg)
{
  if (MA_isVarIdNormal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasVarIdFunId(MA_VarId arg) */

ATbool MA_hasVarIdFunId(MA_VarId arg)
{
  if (MA_isVarIdNormal(arg)) {
    return ATtrue;
  }
  else if (MA_isVarIdPlus(arg)) {
    return ATtrue;
  }
  else if (MA_isVarIdStar(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasVarIdWsAfterDollarPlus(MA_VarId arg) */

ATbool MA_hasVarIdWsAfterDollarPlus(MA_VarId arg)
{
  if (MA_isVarIdPlus(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasVarIdWsAfterDollarStar(MA_VarId arg) */

ATbool MA_hasVarIdWsAfterDollarStar(MA_VarId arg)
{
  if (MA_isVarIdStar(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_OptLayout MA_getVarIdWsAfterDollar(MA_VarId arg) */

MA_OptLayout MA_getVarIdWsAfterDollar(MA_VarId arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_FunId MA_getVarIdFunId(MA_VarId arg) */

MA_FunId MA_getVarIdFunId(MA_VarId arg)
{
  if (MA_isVarIdNormal(arg)) {
    return (MA_FunId)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else if (MA_isVarIdPlus(arg)) {
    return (MA_FunId)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else 
    return (MA_FunId)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getVarIdWsAfterDollarPlus(MA_VarId arg) */

MA_OptLayout MA_getVarIdWsAfterDollarPlus(MA_VarId arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getVarIdWsAfterDollarStar(MA_VarId arg) */

MA_OptLayout MA_getVarIdWsAfterDollarStar(MA_VarId arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_VarId MA_setVarIdWsAfterDollar(MA_VarId arg, MA_OptLayout wsAfterDollar) */

MA_VarId MA_setVarIdWsAfterDollar(MA_VarId arg, MA_OptLayout wsAfterDollar)
{
  if (MA_isVarIdNormal(arg)) {
    return (MA_VarId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterDollar), 1), 1);
  }

  ATabort("VarId has no WsAfterDollar: %t\n", arg);
  return (MA_VarId)NULL;
}

/*}}}  */
/*{{{  MA_VarId MA_setVarIdFunId(MA_VarId arg, MA_FunId FunId) */

MA_VarId MA_setVarIdFunId(MA_VarId arg, MA_FunId FunId)
{
  if (MA_isVarIdNormal(arg)) {
    return (MA_VarId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) FunId), 2), 1);
  }
  else if (MA_isVarIdPlus(arg)) {
    return (MA_VarId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) FunId), 2), 1);
  }
  else if (MA_isVarIdStar(arg)) {
    return (MA_VarId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) FunId), 2), 1);
  }

  ATabort("VarId has no FunId: %t\n", arg);
  return (MA_VarId)NULL;
}

/*}}}  */
/*{{{  MA_VarId MA_setVarIdWsAfterDollarPlus(MA_VarId arg, MA_OptLayout wsAfterDollarPlus) */

MA_VarId MA_setVarIdWsAfterDollarPlus(MA_VarId arg, MA_OptLayout wsAfterDollarPlus)
{
  if (MA_isVarIdPlus(arg)) {
    return (MA_VarId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterDollarPlus), 1), 1);
  }

  ATabort("VarId has no WsAfterDollarPlus: %t\n", arg);
  return (MA_VarId)NULL;
}

/*}}}  */
/*{{{  MA_VarId MA_setVarIdWsAfterDollarStar(MA_VarId arg, MA_OptLayout wsAfterDollarStar) */

MA_VarId MA_setVarIdWsAfterDollarStar(MA_VarId arg, MA_OptLayout wsAfterDollarStar)
{
  if (MA_isVarIdStar(arg)) {
    return (MA_VarId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterDollarStar), 1), 1);
  }

  ATabort("VarId has no WsAfterDollarStar: %t\n", arg);
  return (MA_VarId)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_ModId accessors */

/*{{{  ATbool MA_isValidModId(MA_ModId arg) */

ATbool MA_isValidModId(MA_ModId arg)
{
  if (MA_isModIdDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isModIdDefault(MA_ModId arg) */

inline ATbool MA_isModIdDefault(MA_ModId arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MA_patternModIdDefault, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool MA_hasModIdIdCon(MA_ModId arg) */

ATbool MA_hasModIdIdCon(MA_ModId arg)
{
  if (MA_isModIdDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_IdCon MA_getModIdIdCon(MA_ModId arg) */

MA_IdCon MA_getModIdIdCon(MA_ModId arg)
{
  
    return (MA_IdCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  MA_ModId MA_setModIdIdCon(MA_ModId arg, MA_IdCon IdCon) */

MA_ModId MA_setModIdIdCon(MA_ModId arg, MA_IdCon IdCon)
{
  if (MA_isModIdDefault(arg)) {
    return (MA_ModId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) IdCon), 0), 1);
  }

  ATabort("ModId has no IdCon: %t\n", arg);
  return (MA_ModId)NULL;
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
  else if (MA_isTermFunc(arg)) {
    return ATtrue;
  }
  else if (MA_isTermList(arg)) {
    return ATtrue;
  }
  else if (MA_isTermTyped(arg)) {
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
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternTermVar, NULL);
      last_gc = ATgetGCCount();
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
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternTermConstant, NULL);
      last_gc = ATgetGCCount();
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
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternTermFunc, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isTermList(MA_Term arg) */

inline ATbool MA_isTermList(MA_Term arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternTermList, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isTermTyped(MA_Term arg) */

inline ATbool MA_isTermTyped(MA_Term arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternTermTyped, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MA_hasTermVarId(MA_Term arg) */

ATbool MA_hasTermVarId(MA_Term arg)
{
  if (MA_isTermVar(arg)) {
    return ATtrue;
  }
  return ATfalse;
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
/*{{{  ATbool MA_hasTermWsAfterFunId(MA_Term arg) */

ATbool MA_hasTermWsAfterFunId(MA_Term arg)
{
  if (MA_isTermFunc(arg)) {
    return ATtrue;
  }
  return ATfalse;
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
/*{{{  ATbool MA_hasTermArgs(MA_Term arg) */

ATbool MA_hasTermArgs(MA_Term arg)
{
  if (MA_isTermFunc(arg)) {
    return ATtrue;
  }
  return ATfalse;
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
/*{{{  ATbool MA_hasTermWsAfterBracketOpen(MA_Term arg) */

ATbool MA_hasTermWsAfterBracketOpen(MA_Term arg)
{
  if (MA_isTermList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasTermTermList(MA_Term arg) */

ATbool MA_hasTermTermList(MA_Term arg)
{
  if (MA_isTermList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasTermWsAfterTermList(MA_Term arg) */

ATbool MA_hasTermWsAfterTermList(MA_Term arg)
{
  if (MA_isTermList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasTermTerm(MA_Term arg) */

ATbool MA_hasTermTerm(MA_Term arg)
{
  if (MA_isTermTyped(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasTermWsAfterTerm(MA_Term arg) */

ATbool MA_hasTermWsAfterTerm(MA_Term arg)
{
  if (MA_isTermTyped(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasTermWsAfterColon(MA_Term arg) */

ATbool MA_hasTermWsAfterColon(MA_Term arg)
{
  if (MA_isTermTyped(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasTermType(MA_Term arg) */

ATbool MA_hasTermType(MA_Term arg)
{
  if (MA_isTermTyped(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_VarId MA_getTermVarId(MA_Term arg) */

MA_VarId MA_getTermVarId(MA_Term arg)
{
  
    return (MA_VarId)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
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
/*{{{  MA_OptLayout MA_getTermWsAfterFunId(MA_Term arg) */

MA_OptLayout MA_getTermWsAfterFunId(MA_Term arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getTermWsAfterParenOpen(MA_Term arg) */

MA_OptLayout MA_getTermWsAfterParenOpen(MA_Term arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  MA_TermArgs MA_getTermArgs(MA_Term arg) */

MA_TermArgs MA_getTermArgs(MA_Term arg)
{
  
    return (MA_TermArgs)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), 1);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getTermWsAfterArgs(MA_Term arg) */

MA_OptLayout MA_getTermWsAfterArgs(MA_Term arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getTermWsAfterBracketOpen(MA_Term arg) */

MA_OptLayout MA_getTermWsAfterBracketOpen(MA_Term arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_TermList MA_getTermTermList(MA_Term arg) */

MA_TermList MA_getTermTermList(MA_Term arg)
{
  
    return (MA_TermList)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getTermWsAfterTermList(MA_Term arg) */

MA_OptLayout MA_getTermWsAfterTermList(MA_Term arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  MA_Term MA_getTermTerm(MA_Term arg) */

MA_Term MA_getTermTerm(MA_Term arg)
{
  
    return (MA_Term)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  MA_OptLayout MA_getTermWsAfterTerm(MA_Term arg) */

MA_OptLayout MA_getTermWsAfterTerm(MA_Term arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getTermWsAfterColon(MA_Term arg) */

MA_OptLayout MA_getTermWsAfterColon(MA_Term arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  MA_Term MA_getTermType(MA_Term arg) */

MA_Term MA_getTermType(MA_Term arg)
{
  
    return (MA_Term)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  MA_Term MA_setTermVarId(MA_Term arg, MA_VarId VarId) */

MA_Term MA_setTermVarId(MA_Term arg, MA_VarId VarId)
{
  if (MA_isTermVar(arg)) {
    return (MA_Term)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) VarId), 0), 1);
  }

  ATabort("Term has no VarId: %t\n", arg);
  return (MA_Term)NULL;
}

/*}}}  */
/*{{{  MA_Term MA_setTermFunId(MA_Term arg, MA_FunId FunId) */

MA_Term MA_setTermFunId(MA_Term arg, MA_FunId FunId)
{
  if (MA_isTermConstant(arg)) {
    return (MA_Term)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) FunId), 0), 1);
  }
  else if (MA_isTermFunc(arg)) {
    return (MA_Term)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) FunId), 0), 1);
  }

  ATabort("Term has no FunId: %t\n", arg);
  return (MA_Term)NULL;
}

/*}}}  */
/*{{{  MA_Term MA_setTermWsAfterFunId(MA_Term arg, MA_OptLayout wsAfterFunId) */

MA_Term MA_setTermWsAfterFunId(MA_Term arg, MA_OptLayout wsAfterFunId)
{
  if (MA_isTermFunc(arg)) {
    return (MA_Term)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterFunId), 1), 1);
  }

  ATabort("Term has no WsAfterFunId: %t\n", arg);
  return (MA_Term)NULL;
}

/*}}}  */
/*{{{  MA_Term MA_setTermWsAfterParenOpen(MA_Term arg, MA_OptLayout wsAfterParenOpen) */

MA_Term MA_setTermWsAfterParenOpen(MA_Term arg, MA_OptLayout wsAfterParenOpen)
{
  if (MA_isTermFunc(arg)) {
    return (MA_Term)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("Term has no WsAfterParenOpen: %t\n", arg);
  return (MA_Term)NULL;
}

/*}}}  */
/*{{{  MA_Term MA_setTermArgs(MA_Term arg, MA_TermArgs args) */

MA_Term MA_setTermArgs(MA_Term arg, MA_TermArgs args)
{
  if (MA_isTermFunc(arg)) {
    return (MA_Term)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), (ATerm)((ATerm) args), 1), 4), 1);
  }

  ATabort("Term has no Args: %t\n", arg);
  return (MA_Term)NULL;
}

/*}}}  */
/*{{{  MA_Term MA_setTermWsAfterArgs(MA_Term arg, MA_OptLayout wsAfterArgs) */

MA_Term MA_setTermWsAfterArgs(MA_Term arg, MA_OptLayout wsAfterArgs)
{
  if (MA_isTermFunc(arg)) {
    return (MA_Term)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterArgs), 5), 1);
  }

  ATabort("Term has no WsAfterArgs: %t\n", arg);
  return (MA_Term)NULL;
}

/*}}}  */
/*{{{  MA_Term MA_setTermWsAfterBracketOpen(MA_Term arg, MA_OptLayout wsAfterBracketOpen) */

MA_Term MA_setTermWsAfterBracketOpen(MA_Term arg, MA_OptLayout wsAfterBracketOpen)
{
  if (MA_isTermList(arg)) {
    return (MA_Term)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 1), 1);
  }

  ATabort("Term has no WsAfterBracketOpen: %t\n", arg);
  return (MA_Term)NULL;
}

/*}}}  */
/*{{{  MA_Term MA_setTermTermList(MA_Term arg, MA_TermList TermList) */

MA_Term MA_setTermTermList(MA_Term arg, MA_TermList TermList)
{
  if (MA_isTermList(arg)) {
    return (MA_Term)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) TermList), 2), 1);
  }

  ATabort("Term has no TermList: %t\n", arg);
  return (MA_Term)NULL;
}

/*}}}  */
/*{{{  MA_Term MA_setTermWsAfterTermList(MA_Term arg, MA_OptLayout wsAfterTermList) */

MA_Term MA_setTermWsAfterTermList(MA_Term arg, MA_OptLayout wsAfterTermList)
{
  if (MA_isTermList(arg)) {
    return (MA_Term)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterTermList), 3), 1);
  }

  ATabort("Term has no WsAfterTermList: %t\n", arg);
  return (MA_Term)NULL;
}

/*}}}  */
/*{{{  MA_Term MA_setTermTerm(MA_Term arg, MA_Term Term) */

MA_Term MA_setTermTerm(MA_Term arg, MA_Term Term)
{
  if (MA_isTermTyped(arg)) {
    return (MA_Term)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Term), 0), 1);
  }

  ATabort("Term has no Term: %t\n", arg);
  return (MA_Term)NULL;
}

/*}}}  */
/*{{{  MA_Term MA_setTermWsAfterTerm(MA_Term arg, MA_OptLayout wsAfterTerm) */

MA_Term MA_setTermWsAfterTerm(MA_Term arg, MA_OptLayout wsAfterTerm)
{
  if (MA_isTermTyped(arg)) {
    return (MA_Term)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterTerm), 1), 1);
  }

  ATabort("Term has no WsAfterTerm: %t\n", arg);
  return (MA_Term)NULL;
}

/*}}}  */
/*{{{  MA_Term MA_setTermWsAfterColon(MA_Term arg, MA_OptLayout wsAfterColon) */

MA_Term MA_setTermWsAfterColon(MA_Term arg, MA_OptLayout wsAfterColon)
{
  if (MA_isTermTyped(arg)) {
    return (MA_Term)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterColon), 3), 1);
  }

  ATabort("Term has no WsAfterColon: %t\n", arg);
  return (MA_Term)NULL;
}

/*}}}  */
/*{{{  MA_Term MA_setTermType(MA_Term arg, MA_Term type) */

MA_Term MA_setTermType(MA_Term arg, MA_Term type)
{
  if (MA_isTermTyped(arg)) {
    return (MA_Term)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) type), 4), 1);
  }

  ATabort("Term has no Type: %t\n", arg);
  return (MA_Term)NULL;
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
    return (MA_TermList)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) elems), 1), 0), 1);
  }

  ATabort("TermList has no Elems: %t\n", arg);
  return (MA_TermList)NULL;
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
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternSigArgNormal);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isSigArgStar(MA_SigArg arg) */

inline ATbool MA_isSigArgStar(MA_SigArg arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternSigArgStar, NULL);
      last_gc = ATgetGCCount();
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
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternSigArgPlus, NULL);
      last_gc = ATgetGCCount();
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
/*{{{  MA_OptLayout MA_getSigArgWsAfterUnderscore(MA_SigArg arg) */

MA_OptLayout MA_getSigArgWsAfterUnderscore(MA_SigArg arg)
{
  if (MA_isSigArgStar(arg)) {
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else 
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_SigArg MA_setSigArgWsAfterUnderscore(MA_SigArg arg, MA_OptLayout wsAfterUnderscore) */

MA_SigArg MA_setSigArgWsAfterUnderscore(MA_SigArg arg, MA_OptLayout wsAfterUnderscore)
{
  if (MA_isSigArgStar(arg)) {
    return (MA_SigArg)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterUnderscore), 1), 1);
  }
  else if (MA_isSigArgPlus(arg)) {
    return (MA_SigArg)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterUnderscore), 1), 1);
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
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternFuncDefConstantNoAnnos, NULL);
      last_gc = ATgetGCCount();
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
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternFuncDefConstantWithAnnos, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
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
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternFuncDefFuncNoAnnos, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
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
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternFuncDefFuncWithAnnos, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
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
/*{{{  ATbool MA_hasFuncDefAnnotations(MA_FuncDef arg) */

ATbool MA_hasFuncDefAnnotations(MA_FuncDef arg)
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
/*{{{  ATbool MA_hasFuncDefArgs(MA_FuncDef arg) */

ATbool MA_hasFuncDefArgs(MA_FuncDef arg)
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
/*{{{  ATbool MA_hasFuncDefWsAfterArgs(MA_FuncDef arg) */

ATbool MA_hasFuncDefWsAfterArgs(MA_FuncDef arg)
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
/*{{{  ATbool MA_hasFuncDefWsAfterParenClose(MA_FuncDef arg) */

ATbool MA_hasFuncDefWsAfterParenClose(MA_FuncDef arg)
{
  if (MA_isFuncDefFuncWithAnnos(arg)) {
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
/*{{{  MA_OptLayout MA_getFuncDefWsAfterFunId(MA_FuncDef arg) */

MA_OptLayout MA_getFuncDefWsAfterFunId(MA_FuncDef arg)
{
  if (MA_isFuncDefConstantWithAnnos(arg)) {
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else if (MA_isFuncDefFuncNoAnnos(arg)) {
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else 
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_Annotations MA_getFuncDefAnnotations(MA_FuncDef arg) */

MA_Annotations MA_getFuncDefAnnotations(MA_FuncDef arg)
{
  if (MA_isFuncDefConstantWithAnnos(arg)) {
    return (MA_Annotations)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else 
    return (MA_Annotations)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getFuncDefWsAfterParenOpen(MA_FuncDef arg) */

MA_OptLayout MA_getFuncDefWsAfterParenOpen(MA_FuncDef arg)
{
  if (MA_isFuncDefFuncNoAnnos(arg)) {
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  MA_SigArgArgs MA_getFuncDefArgs(MA_FuncDef arg) */

MA_SigArgArgs MA_getFuncDefArgs(MA_FuncDef arg)
{
  if (MA_isFuncDefFuncNoAnnos(arg)) {
    return (MA_SigArgArgs)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), 1);
  }
  else 
    return (MA_SigArgArgs)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), 1);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getFuncDefWsAfterArgs(MA_FuncDef arg) */

MA_OptLayout MA_getFuncDefWsAfterArgs(MA_FuncDef arg)
{
  if (MA_isFuncDefFuncNoAnnos(arg)) {
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else 
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getFuncDefWsAfterParenClose(MA_FuncDef arg) */

MA_OptLayout MA_getFuncDefWsAfterParenClose(MA_FuncDef arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  MA_FuncDef MA_setFuncDefFunId(MA_FuncDef arg, MA_FunId FunId) */

MA_FuncDef MA_setFuncDefFunId(MA_FuncDef arg, MA_FunId FunId)
{
  if (MA_isFuncDefConstantNoAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) FunId), 0), 1);
  }
  else if (MA_isFuncDefConstantWithAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) FunId), 0), 1);
  }
  else if (MA_isFuncDefFuncNoAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) FunId), 0), 1);
  }
  else if (MA_isFuncDefFuncWithAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) FunId), 0), 1);
  }

  ATabort("FuncDef has no FunId: %t\n", arg);
  return (MA_FuncDef)NULL;
}

/*}}}  */
/*{{{  MA_FuncDef MA_setFuncDefWsAfterFunId(MA_FuncDef arg, MA_OptLayout wsAfterFunId) */

MA_FuncDef MA_setFuncDefWsAfterFunId(MA_FuncDef arg, MA_OptLayout wsAfterFunId)
{
  if (MA_isFuncDefConstantWithAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterFunId), 1), 1);
  }
  else if (MA_isFuncDefFuncNoAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterFunId), 1), 1);
  }
  else if (MA_isFuncDefFuncWithAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterFunId), 1), 1);
  }

  ATabort("FuncDef has no WsAfterFunId: %t\n", arg);
  return (MA_FuncDef)NULL;
}

/*}}}  */
/*{{{  MA_FuncDef MA_setFuncDefAnnotations(MA_FuncDef arg, MA_Annotations Annotations) */

MA_FuncDef MA_setFuncDefAnnotations(MA_FuncDef arg, MA_Annotations Annotations)
{
  if (MA_isFuncDefConstantWithAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Annotations), 2), 1);
  }
  else if (MA_isFuncDefFuncWithAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Annotations), 8), 1);
  }

  ATabort("FuncDef has no Annotations: %t\n", arg);
  return (MA_FuncDef)NULL;
}

/*}}}  */
/*{{{  MA_FuncDef MA_setFuncDefWsAfterParenOpen(MA_FuncDef arg, MA_OptLayout wsAfterParenOpen) */

MA_FuncDef MA_setFuncDefWsAfterParenOpen(MA_FuncDef arg, MA_OptLayout wsAfterParenOpen)
{
  if (MA_isFuncDefFuncNoAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (MA_isFuncDefFuncWithAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("FuncDef has no WsAfterParenOpen: %t\n", arg);
  return (MA_FuncDef)NULL;
}

/*}}}  */
/*{{{  MA_FuncDef MA_setFuncDefArgs(MA_FuncDef arg, MA_SigArgArgs args) */

MA_FuncDef MA_setFuncDefArgs(MA_FuncDef arg, MA_SigArgArgs args)
{
  if (MA_isFuncDefFuncNoAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), (ATerm)((ATerm) args), 1), 4), 1);
  }
  else if (MA_isFuncDefFuncWithAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), (ATerm)((ATerm) args), 1), 4), 1);
  }

  ATabort("FuncDef has no Args: %t\n", arg);
  return (MA_FuncDef)NULL;
}

/*}}}  */
/*{{{  MA_FuncDef MA_setFuncDefWsAfterArgs(MA_FuncDef arg, MA_OptLayout wsAfterArgs) */

MA_FuncDef MA_setFuncDefWsAfterArgs(MA_FuncDef arg, MA_OptLayout wsAfterArgs)
{
  if (MA_isFuncDefFuncNoAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterArgs), 5), 1);
  }
  else if (MA_isFuncDefFuncWithAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterArgs), 5), 1);
  }

  ATabort("FuncDef has no WsAfterArgs: %t\n", arg);
  return (MA_FuncDef)NULL;
}

/*}}}  */
/*{{{  MA_FuncDef MA_setFuncDefWsAfterParenClose(MA_FuncDef arg, MA_OptLayout wsAfterParenClose) */

MA_FuncDef MA_setFuncDefWsAfterParenClose(MA_FuncDef arg, MA_OptLayout wsAfterParenClose)
{
  if (MA_isFuncDefFuncWithAnnos(arg)) {
    return (MA_FuncDef)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenClose), 7), 1);
  }

  ATabort("FuncDef has no WsAfterParenClose: %t\n", arg);
  return (MA_FuncDef)NULL;
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
/*{{{  ATbool MA_hasAnnotationsAttrs(MA_Annotations arg) */

ATbool MA_hasAnnotationsAttrs(MA_Annotations arg)
{
  if (MA_isAnnotationsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasAnnotationsWsAfterAttrs(MA_Annotations arg) */

ATbool MA_hasAnnotationsWsAfterAttrs(MA_Annotations arg)
{
  if (MA_isAnnotationsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_OptLayout MA_getAnnotationsWsAfterBraceOpen(MA_Annotations arg) */

MA_OptLayout MA_getAnnotationsWsAfterBraceOpen(MA_Annotations arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_TermAttrs MA_getAnnotationsAttrs(MA_Annotations arg) */

MA_TermAttrs MA_getAnnotationsAttrs(MA_Annotations arg)
{
  
    return (MA_TermAttrs)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), 1);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getAnnotationsWsAfterAttrs(MA_Annotations arg) */

MA_OptLayout MA_getAnnotationsWsAfterAttrs(MA_Annotations arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  MA_Annotations MA_setAnnotationsWsAfterBraceOpen(MA_Annotations arg, MA_OptLayout wsAfterBraceOpen) */

MA_Annotations MA_setAnnotationsWsAfterBraceOpen(MA_Annotations arg, MA_OptLayout wsAfterBraceOpen)
{
  if (MA_isAnnotationsDefault(arg)) {
    return (MA_Annotations)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBraceOpen), 1), 1);
  }

  ATabort("Annotations has no WsAfterBraceOpen: %t\n", arg);
  return (MA_Annotations)NULL;
}

/*}}}  */
/*{{{  MA_Annotations MA_setAnnotationsAttrs(MA_Annotations arg, MA_TermAttrs attrs) */

MA_Annotations MA_setAnnotationsAttrs(MA_Annotations arg, MA_TermAttrs attrs)
{
  if (MA_isAnnotationsDefault(arg)) {
    return (MA_Annotations)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), (ATerm)((ATerm) attrs), 1), 2), 1);
  }

  ATabort("Annotations has no Attrs: %t\n", arg);
  return (MA_Annotations)NULL;
}

/*}}}  */
/*{{{  MA_Annotations MA_setAnnotationsWsAfterAttrs(MA_Annotations arg, MA_OptLayout wsAfterAttrs) */

MA_Annotations MA_setAnnotationsWsAfterAttrs(MA_Annotations arg, MA_OptLayout wsAfterAttrs)
{
  if (MA_isAnnotationsDefault(arg)) {
    return (MA_Annotations)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterAttrs), 3), 1);
  }

  ATabort("Annotations has no WsAfterAttrs: %t\n", arg);
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
/*{{{  ATbool MA_hasSigArgListArgs(MA_SigArgList arg) */

ATbool MA_hasSigArgListArgs(MA_SigArgList arg)
{
  if (MA_isSigArgListDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_SigArgArgs MA_getSigArgListArgs(MA_SigArgList arg) */

MA_SigArgArgs MA_getSigArgListArgs(MA_SigArgList arg)
{
  
    return (MA_SigArgArgs)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  MA_SigArgList MA_setSigArgListArgs(MA_SigArgList arg, MA_SigArgArgs args) */

MA_SigArgList MA_setSigArgListArgs(MA_SigArgList arg, MA_SigArgArgs args)
{
  if (MA_isSigArgListDefault(arg)) {
    return (MA_SigArgList)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) args), 1), 0), 1);
  }

  ATabort("SigArgList has no Args: %t\n", arg);
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
/*{{{  ATbool MA_hasFuncDefListDefs(MA_FuncDefList arg) */

ATbool MA_hasFuncDefListDefs(MA_FuncDefList arg)
{
  if (MA_isFuncDefListDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_FuncDefDefs MA_getFuncDefListDefs(MA_FuncDefList arg) */

MA_FuncDefDefs MA_getFuncDefListDefs(MA_FuncDefList arg)
{
  
    return (MA_FuncDefDefs)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  MA_FuncDefList MA_setFuncDefListDefs(MA_FuncDefList arg, MA_FuncDefDefs defs) */

MA_FuncDefList MA_setFuncDefListDefs(MA_FuncDefList arg, MA_FuncDefDefs defs)
{
  if (MA_isFuncDefListDefault(arg)) {
    return (MA_FuncDefList)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) defs), 1), 0), 1);
  }

  ATabort("FuncDefList has no Defs: %t\n", arg);
  return (MA_FuncDefList)NULL;
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
  else if (MA_isRuleWithConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleDefaultWithConds(arg)) {
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
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternRuleNoConds, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
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
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternRuleDefaultNoConds, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
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
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternRuleWithConds, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
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
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternRuleDefaultWithConds, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
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
  else if (MA_isRuleWithConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleDefaultWithConds(arg)) {
    return ATtrue;
  }
  return ATfalse;
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
  else if (MA_isRuleWithConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleDefaultWithConds(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasRuleWsAfterIs(MA_Rule arg) */

ATbool MA_hasRuleWsAfterIs(MA_Rule arg)
{
  if (MA_isRuleNoConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleDefaultNoConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleWithConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleDefaultWithConds(arg)) {
    return ATtrue;
  }
  return ATfalse;
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
  else if (MA_isRuleWithConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleDefaultWithConds(arg)) {
    return ATtrue;
  }
  return ATfalse;
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
/*{{{  ATbool MA_hasRuleConds(MA_Rule arg) */

ATbool MA_hasRuleConds(MA_Rule arg)
{
  if (MA_isRuleWithConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleDefaultWithConds(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasRuleWsAfterConds(MA_Rule arg) */

ATbool MA_hasRuleWsAfterConds(MA_Rule arg)
{
  if (MA_isRuleWithConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleDefaultWithConds(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasRuleWsAfterEqualsEqualsGreaterThan(MA_Rule arg) */

ATbool MA_hasRuleWsAfterEqualsEqualsGreaterThan(MA_Rule arg)
{
  if (MA_isRuleWithConds(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleDefaultWithConds(arg)) {
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
  else if (MA_isRuleWithConds(arg)) {
    return (MA_Term)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (MA_Term)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getRuleWsAfterLhs(MA_Rule arg) */

MA_OptLayout MA_getRuleWsAfterLhs(MA_Rule arg)
{
  if (MA_isRuleNoConds(arg)) {
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else if (MA_isRuleDefaultNoConds(arg)) {
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (MA_isRuleWithConds(arg)) {
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else 
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getRuleWsAfterIs(MA_Rule arg) */

MA_OptLayout MA_getRuleWsAfterIs(MA_Rule arg)
{
  if (MA_isRuleNoConds(arg)) {
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (MA_isRuleDefaultNoConds(arg)) {
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else if (MA_isRuleWithConds(arg)) {
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else 
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
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
  else if (MA_isRuleWithConds(arg)) {
    return (MA_Term)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
  }
  else 
    return (MA_Term)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 10);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getRuleWsAfterDefaultColon(MA_Rule arg) */

MA_OptLayout MA_getRuleWsAfterDefaultColon(MA_Rule arg)
{
  if (MA_isRuleDefaultNoConds(arg)) {
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else 
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_CondList MA_getRuleConds(MA_Rule arg) */

MA_CondList MA_getRuleConds(MA_Rule arg)
{
  if (MA_isRuleWithConds(arg)) {
    return (MA_CondList)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (MA_CondList)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getRuleWsAfterConds(MA_Rule arg) */

MA_OptLayout MA_getRuleWsAfterConds(MA_Rule arg)
{
  if (MA_isRuleWithConds(arg)) {
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else 
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getRuleWsAfterEqualsEqualsGreaterThan(MA_Rule arg) */

MA_OptLayout MA_getRuleWsAfterEqualsEqualsGreaterThan(MA_Rule arg)
{
  if (MA_isRuleWithConds(arg)) {
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  MA_Rule MA_setRuleLhs(MA_Rule arg, MA_Term lhs) */

MA_Rule MA_setRuleLhs(MA_Rule arg, MA_Term lhs)
{
  if (MA_isRuleNoConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) lhs), 0), 1);
  }
  else if (MA_isRuleDefaultNoConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) lhs), 2), 1);
  }
  else if (MA_isRuleWithConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) lhs), 4), 1);
  }
  else if (MA_isRuleDefaultWithConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) lhs), 6), 1);
  }

  ATabort("Rule has no Lhs: %t\n", arg);
  return (MA_Rule)NULL;
}

/*}}}  */
/*{{{  MA_Rule MA_setRuleWsAfterLhs(MA_Rule arg, MA_OptLayout wsAfterLhs) */

MA_Rule MA_setRuleWsAfterLhs(MA_Rule arg, MA_OptLayout wsAfterLhs)
{
  if (MA_isRuleNoConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLhs), 1), 1);
  }
  else if (MA_isRuleDefaultNoConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLhs), 3), 1);
  }
  else if (MA_isRuleWithConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLhs), 5), 1);
  }
  else if (MA_isRuleDefaultWithConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLhs), 7), 1);
  }

  ATabort("Rule has no WsAfterLhs: %t\n", arg);
  return (MA_Rule)NULL;
}

/*}}}  */
/*{{{  MA_Rule MA_setRuleWsAfterIs(MA_Rule arg, MA_OptLayout wsAfterIs) */

MA_Rule MA_setRuleWsAfterIs(MA_Rule arg, MA_OptLayout wsAfterIs)
{
  if (MA_isRuleNoConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterIs), 3), 1);
  }
  else if (MA_isRuleDefaultNoConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterIs), 5), 1);
  }
  else if (MA_isRuleWithConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterIs), 7), 1);
  }
  else if (MA_isRuleDefaultWithConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterIs), 9), 1);
  }

  ATabort("Rule has no WsAfterIs: %t\n", arg);
  return (MA_Rule)NULL;
}

/*}}}  */
/*{{{  MA_Rule MA_setRuleRhs(MA_Rule arg, MA_Term rhs) */

MA_Rule MA_setRuleRhs(MA_Rule arg, MA_Term rhs)
{
  if (MA_isRuleNoConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) rhs), 4), 1);
  }
  else if (MA_isRuleDefaultNoConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) rhs), 6), 1);
  }
  else if (MA_isRuleWithConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) rhs), 8), 1);
  }
  else if (MA_isRuleDefaultWithConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) rhs), 10), 1);
  }

  ATabort("Rule has no Rhs: %t\n", arg);
  return (MA_Rule)NULL;
}

/*}}}  */
/*{{{  MA_Rule MA_setRuleWsAfterDefaultColon(MA_Rule arg, MA_OptLayout wsAfterDefaultColon) */

MA_Rule MA_setRuleWsAfterDefaultColon(MA_Rule arg, MA_OptLayout wsAfterDefaultColon)
{
  if (MA_isRuleDefaultNoConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterDefaultColon), 1), 1);
  }
  else if (MA_isRuleDefaultWithConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterDefaultColon), 1), 1);
  }

  ATabort("Rule has no WsAfterDefaultColon: %t\n", arg);
  return (MA_Rule)NULL;
}

/*}}}  */
/*{{{  MA_Rule MA_setRuleConds(MA_Rule arg, MA_CondList conds) */

MA_Rule MA_setRuleConds(MA_Rule arg, MA_CondList conds)
{
  if (MA_isRuleWithConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) conds), 0), 1);
  }
  else if (MA_isRuleDefaultWithConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) conds), 2), 1);
  }

  ATabort("Rule has no Conds: %t\n", arg);
  return (MA_Rule)NULL;
}

/*}}}  */
/*{{{  MA_Rule MA_setRuleWsAfterConds(MA_Rule arg, MA_OptLayout wsAfterConds) */

MA_Rule MA_setRuleWsAfterConds(MA_Rule arg, MA_OptLayout wsAfterConds)
{
  if (MA_isRuleWithConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterConds), 1), 1);
  }
  else if (MA_isRuleDefaultWithConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterConds), 3), 1);
  }

  ATabort("Rule has no WsAfterConds: %t\n", arg);
  return (MA_Rule)NULL;
}

/*}}}  */
/*{{{  MA_Rule MA_setRuleWsAfterEqualsEqualsGreaterThan(MA_Rule arg, MA_OptLayout wsAfterEqualsEqualsGreaterThan) */

MA_Rule MA_setRuleWsAfterEqualsEqualsGreaterThan(MA_Rule arg, MA_OptLayout wsAfterEqualsEqualsGreaterThan)
{
  if (MA_isRuleWithConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterEqualsEqualsGreaterThan), 3), 1);
  }
  else if (MA_isRuleDefaultWithConds(arg)) {
    return (MA_Rule)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterEqualsEqualsGreaterThan), 5), 1);
  }

  ATabort("Rule has no WsAfterEqualsEqualsGreaterThan: %t\n", arg);
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
/*{{{  MA_RuleRules MA_getRuleListRules(MA_RuleList arg) */

MA_RuleRules MA_getRuleListRules(MA_RuleList arg)
{
  
    return (MA_RuleRules)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  MA_RuleList MA_setRuleListRules(MA_RuleList arg, MA_RuleRules rules) */

MA_RuleList MA_setRuleListRules(MA_RuleList arg, MA_RuleRules rules)
{
  if (MA_isRuleListDefault(arg)) {
    return (MA_RuleList)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) rules), 1), 0), 1);
  }

  ATabort("RuleList has no Rules: %t\n", arg);
  return (MA_RuleList)NULL;
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
/*{{{  MA_CondConds MA_getCondListConds(MA_CondList arg) */

MA_CondConds MA_getCondListConds(MA_CondList arg)
{
  
    return (MA_CondConds)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  MA_CondList MA_setCondListConds(MA_CondList arg, MA_CondConds conds) */

MA_CondList MA_setCondListConds(MA_CondList arg, MA_CondConds conds)
{
  if (MA_isCondListDefault(arg)) {
    return (MA_CondList)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) conds), 1), 0), 1);
  }

  ATabort("CondList has no Conds: %t\n", arg);
  return (MA_CondList)NULL;
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
  else if (MA_isCondNoAssign(arg)) {
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
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternCondAssign, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isCondNoAssign(MA_Cond arg) */

inline ATbool MA_isCondNoAssign(MA_Cond arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternCondNoAssign, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
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
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternCondEqual, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
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
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternCondUnequal, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
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
  else if (MA_isCondNoAssign(arg)) {
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
/*{{{  ATbool MA_hasCondWsAfterLhs(MA_Cond arg) */

ATbool MA_hasCondWsAfterLhs(MA_Cond arg)
{
  if (MA_isCondAssign(arg)) {
    return ATtrue;
  }
  else if (MA_isCondNoAssign(arg)) {
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
/*{{{  ATbool MA_hasCondWsAfterBecomes(MA_Cond arg) */

ATbool MA_hasCondWsAfterBecomes(MA_Cond arg)
{
  if (MA_isCondAssign(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasCondRhs(MA_Cond arg) */

ATbool MA_hasCondRhs(MA_Cond arg)
{
  if (MA_isCondAssign(arg)) {
    return ATtrue;
  }
  else if (MA_isCondNoAssign(arg)) {
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
/*{{{  ATbool MA_hasCondWsAfterNotBecomes(MA_Cond arg) */

ATbool MA_hasCondWsAfterNotBecomes(MA_Cond arg)
{
  if (MA_isCondNoAssign(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasCondWsAfterEquals(MA_Cond arg) */

ATbool MA_hasCondWsAfterEquals(MA_Cond arg)
{
  if (MA_isCondEqual(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasCondWsAfterNotEquals(MA_Cond arg) */

ATbool MA_hasCondWsAfterNotEquals(MA_Cond arg)
{
  if (MA_isCondUnequal(arg)) {
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
  else if (MA_isCondNoAssign(arg)) {
    return (MA_Term)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (MA_isCondEqual(arg)) {
    return (MA_Term)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (MA_Term)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  MA_OptLayout MA_getCondWsAfterLhs(MA_Cond arg) */

MA_OptLayout MA_getCondWsAfterLhs(MA_Cond arg)
{
  if (MA_isCondAssign(arg)) {
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else if (MA_isCondNoAssign(arg)) {
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else if (MA_isCondEqual(arg)) {
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else 
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getCondWsAfterBecomes(MA_Cond arg) */

MA_OptLayout MA_getCondWsAfterBecomes(MA_Cond arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  MA_Term MA_getCondRhs(MA_Cond arg) */

MA_Term MA_getCondRhs(MA_Cond arg)
{
  if (MA_isCondAssign(arg)) {
    return (MA_Term)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else if (MA_isCondNoAssign(arg)) {
    return (MA_Term)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else if (MA_isCondEqual(arg)) {
    return (MA_Term)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (MA_Term)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getCondWsAfterNotBecomes(MA_Cond arg) */

MA_OptLayout MA_getCondWsAfterNotBecomes(MA_Cond arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getCondWsAfterEquals(MA_Cond arg) */

MA_OptLayout MA_getCondWsAfterEquals(MA_Cond arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getCondWsAfterNotEquals(MA_Cond arg) */

MA_OptLayout MA_getCondWsAfterNotEquals(MA_Cond arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  MA_Cond MA_setCondLhs(MA_Cond arg, MA_Term lhs) */

MA_Cond MA_setCondLhs(MA_Cond arg, MA_Term lhs)
{
  if (MA_isCondAssign(arg)) {
    return (MA_Cond)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) lhs), 0), 1);
  }
  else if (MA_isCondNoAssign(arg)) {
    return (MA_Cond)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) lhs), 0), 1);
  }
  else if (MA_isCondEqual(arg)) {
    return (MA_Cond)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) lhs), 0), 1);
  }
  else if (MA_isCondUnequal(arg)) {
    return (MA_Cond)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) lhs), 0), 1);
  }

  ATabort("Cond has no Lhs: %t\n", arg);
  return (MA_Cond)NULL;
}

/*}}}  */
/*{{{  MA_Cond MA_setCondWsAfterLhs(MA_Cond arg, MA_OptLayout wsAfterLhs) */

MA_Cond MA_setCondWsAfterLhs(MA_Cond arg, MA_OptLayout wsAfterLhs)
{
  if (MA_isCondAssign(arg)) {
    return (MA_Cond)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLhs), 1), 1);
  }
  else if (MA_isCondNoAssign(arg)) {
    return (MA_Cond)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLhs), 1), 1);
  }
  else if (MA_isCondEqual(arg)) {
    return (MA_Cond)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLhs), 1), 1);
  }
  else if (MA_isCondUnequal(arg)) {
    return (MA_Cond)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLhs), 1), 1);
  }

  ATabort("Cond has no WsAfterLhs: %t\n", arg);
  return (MA_Cond)NULL;
}

/*}}}  */
/*{{{  MA_Cond MA_setCondWsAfterBecomes(MA_Cond arg, MA_OptLayout wsAfterBecomes) */

MA_Cond MA_setCondWsAfterBecomes(MA_Cond arg, MA_OptLayout wsAfterBecomes)
{
  if (MA_isCondAssign(arg)) {
    return (MA_Cond)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBecomes), 3), 1);
  }

  ATabort("Cond has no WsAfterBecomes: %t\n", arg);
  return (MA_Cond)NULL;
}

/*}}}  */
/*{{{  MA_Cond MA_setCondRhs(MA_Cond arg, MA_Term rhs) */

MA_Cond MA_setCondRhs(MA_Cond arg, MA_Term rhs)
{
  if (MA_isCondAssign(arg)) {
    return (MA_Cond)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) rhs), 4), 1);
  }
  else if (MA_isCondNoAssign(arg)) {
    return (MA_Cond)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) rhs), 4), 1);
  }
  else if (MA_isCondEqual(arg)) {
    return (MA_Cond)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) rhs), 4), 1);
  }
  else if (MA_isCondUnequal(arg)) {
    return (MA_Cond)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) rhs), 4), 1);
  }

  ATabort("Cond has no Rhs: %t\n", arg);
  return (MA_Cond)NULL;
}

/*}}}  */
/*{{{  MA_Cond MA_setCondWsAfterNotBecomes(MA_Cond arg, MA_OptLayout wsAfterNotBecomes) */

MA_Cond MA_setCondWsAfterNotBecomes(MA_Cond arg, MA_OptLayout wsAfterNotBecomes)
{
  if (MA_isCondNoAssign(arg)) {
    return (MA_Cond)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterNotBecomes), 3), 1);
  }

  ATabort("Cond has no WsAfterNotBecomes: %t\n", arg);
  return (MA_Cond)NULL;
}

/*}}}  */
/*{{{  MA_Cond MA_setCondWsAfterEquals(MA_Cond arg, MA_OptLayout wsAfterEquals) */

MA_Cond MA_setCondWsAfterEquals(MA_Cond arg, MA_OptLayout wsAfterEquals)
{
  if (MA_isCondEqual(arg)) {
    return (MA_Cond)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterEquals), 3), 1);
  }

  ATabort("Cond has no WsAfterEquals: %t\n", arg);
  return (MA_Cond)NULL;
}

/*}}}  */
/*{{{  MA_Cond MA_setCondWsAfterNotEquals(MA_Cond arg, MA_OptLayout wsAfterNotEquals) */

MA_Cond MA_setCondWsAfterNotEquals(MA_Cond arg, MA_OptLayout wsAfterNotEquals)
{
  if (MA_isCondUnequal(arg)) {
    return (MA_Cond)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterNotEquals), 3), 1);
  }

  ATabort("Cond has no WsAfterNotEquals: %t\n", arg);
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
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternSignatureOptAbsent);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isSignatureOptPresent(MA_SignatureOpt arg) */

inline ATbool MA_isSignatureOptPresent(MA_SignatureOpt arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternSignatureOptPresent, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
/*{{{  ATbool MA_hasSignatureOptFuncDefList(MA_SignatureOpt arg) */

ATbool MA_hasSignatureOptFuncDefList(MA_SignatureOpt arg)
{
  if (MA_isSignatureOptPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_OptLayout MA_getSignatureOptWsAfterSignature(MA_SignatureOpt arg) */

MA_OptLayout MA_getSignatureOptWsAfterSignature(MA_SignatureOpt arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_FuncDefList MA_getSignatureOptFuncDefList(MA_SignatureOpt arg) */

MA_FuncDefList MA_getSignatureOptFuncDefList(MA_SignatureOpt arg)
{
  
    return (MA_FuncDefList)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  MA_SignatureOpt MA_setSignatureOptWsAfterSignature(MA_SignatureOpt arg, MA_OptLayout wsAfterSignature) */

MA_SignatureOpt MA_setSignatureOptWsAfterSignature(MA_SignatureOpt arg, MA_OptLayout wsAfterSignature)
{
  if (MA_isSignatureOptPresent(arg)) {
    return (MA_SignatureOpt)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSignature), 1), 1);
  }

  ATabort("SignatureOpt has no WsAfterSignature: %t\n", arg);
  return (MA_SignatureOpt)NULL;
}

/*}}}  */
/*{{{  MA_SignatureOpt MA_setSignatureOptFuncDefList(MA_SignatureOpt arg, MA_FuncDefList FuncDefList) */

MA_SignatureOpt MA_setSignatureOptFuncDefList(MA_SignatureOpt arg, MA_FuncDefList FuncDefList)
{
  if (MA_isSignatureOptPresent(arg)) {
    return (MA_SignatureOpt)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) FuncDefList), 2), 1);
  }

  ATabort("SignatureOpt has no FuncDefList: %t\n", arg);
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
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternRulesOptAbsent);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isRulesOptPresent(MA_RulesOpt arg) */

inline ATbool MA_isRulesOptPresent(MA_RulesOpt arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternRulesOptPresent, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
/*{{{  ATbool MA_hasRulesOptRuleList(MA_RulesOpt arg) */

ATbool MA_hasRulesOptRuleList(MA_RulesOpt arg)
{
  if (MA_isRulesOptPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_OptLayout MA_getRulesOptWsAfterRules(MA_RulesOpt arg) */

MA_OptLayout MA_getRulesOptWsAfterRules(MA_RulesOpt arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_RuleList MA_getRulesOptRuleList(MA_RulesOpt arg) */

MA_RuleList MA_getRulesOptRuleList(MA_RulesOpt arg)
{
  
    return (MA_RuleList)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  MA_RulesOpt MA_setRulesOptWsAfterRules(MA_RulesOpt arg, MA_OptLayout wsAfterRules) */

MA_RulesOpt MA_setRulesOptWsAfterRules(MA_RulesOpt arg, MA_OptLayout wsAfterRules)
{
  if (MA_isRulesOptPresent(arg)) {
    return (MA_RulesOpt)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterRules), 1), 1);
  }

  ATabort("RulesOpt has no WsAfterRules: %t\n", arg);
  return (MA_RulesOpt)NULL;
}

/*}}}  */
/*{{{  MA_RulesOpt MA_setRulesOptRuleList(MA_RulesOpt arg, MA_RuleList RuleList) */

MA_RulesOpt MA_setRulesOptRuleList(MA_RulesOpt arg, MA_RuleList RuleList)
{
  if (MA_isRulesOptPresent(arg)) {
    return (MA_RulesOpt)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) RuleList), 2), 1);
  }

  ATabort("RulesOpt has no RuleList: %t\n", arg);
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
/*{{{  ATbool MA_hasModuleModId(MA_Module arg) */

ATbool MA_hasModuleModId(MA_Module arg)
{
  if (MA_isModuleModule(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasModuleWsAfterModId(MA_Module arg) */

ATbool MA_hasModuleWsAfterModId(MA_Module arg)
{
  if (MA_isModuleModule(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasModuleSignatureOpt(MA_Module arg) */

ATbool MA_hasModuleSignatureOpt(MA_Module arg)
{
  if (MA_isModuleModule(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasModuleWsAfterSignatureOpt(MA_Module arg) */

ATbool MA_hasModuleWsAfterSignatureOpt(MA_Module arg)
{
  if (MA_isModuleModule(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasModuleRulesOpt(MA_Module arg) */

ATbool MA_hasModuleRulesOpt(MA_Module arg)
{
  if (MA_isModuleModule(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_OptLayout MA_getModuleWsAfterModule(MA_Module arg) */

MA_OptLayout MA_getModuleWsAfterModule(MA_Module arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  MA_ModId MA_getModuleModId(MA_Module arg) */

MA_ModId MA_getModuleModId(MA_Module arg)
{
  
    return (MA_ModId)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getModuleWsAfterModId(MA_Module arg) */

MA_OptLayout MA_getModuleWsAfterModId(MA_Module arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  MA_SignatureOpt MA_getModuleSignatureOpt(MA_Module arg) */

MA_SignatureOpt MA_getModuleSignatureOpt(MA_Module arg)
{
  
    return (MA_SignatureOpt)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getModuleWsAfterSignatureOpt(MA_Module arg) */

MA_OptLayout MA_getModuleWsAfterSignatureOpt(MA_Module arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  MA_RulesOpt MA_getModuleRulesOpt(MA_Module arg) */

MA_RulesOpt MA_getModuleRulesOpt(MA_Module arg)
{
  
    return (MA_RulesOpt)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6);
}

/*}}}  */
/*{{{  MA_Module MA_setModuleWsAfterModule(MA_Module arg, MA_OptLayout wsAfterModule) */

MA_Module MA_setModuleWsAfterModule(MA_Module arg, MA_OptLayout wsAfterModule)
{
  if (MA_isModuleModule(arg)) {
    return (MA_Module)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterModule), 1), 1);
  }

  ATabort("Module has no WsAfterModule: %t\n", arg);
  return (MA_Module)NULL;
}

/*}}}  */
/*{{{  MA_Module MA_setModuleModId(MA_Module arg, MA_ModId ModId) */

MA_Module MA_setModuleModId(MA_Module arg, MA_ModId ModId)
{
  if (MA_isModuleModule(arg)) {
    return (MA_Module)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ModId), 2), 1);
  }

  ATabort("Module has no ModId: %t\n", arg);
  return (MA_Module)NULL;
}

/*}}}  */
/*{{{  MA_Module MA_setModuleWsAfterModId(MA_Module arg, MA_OptLayout wsAfterModId) */

MA_Module MA_setModuleWsAfterModId(MA_Module arg, MA_OptLayout wsAfterModId)
{
  if (MA_isModuleModule(arg)) {
    return (MA_Module)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterModId), 3), 1);
  }

  ATabort("Module has no WsAfterModId: %t\n", arg);
  return (MA_Module)NULL;
}

/*}}}  */
/*{{{  MA_Module MA_setModuleSignatureOpt(MA_Module arg, MA_SignatureOpt SignatureOpt) */

MA_Module MA_setModuleSignatureOpt(MA_Module arg, MA_SignatureOpt SignatureOpt)
{
  if (MA_isModuleModule(arg)) {
    return (MA_Module)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) SignatureOpt), 4), 1);
  }

  ATabort("Module has no SignatureOpt: %t\n", arg);
  return (MA_Module)NULL;
}

/*}}}  */
/*{{{  MA_Module MA_setModuleWsAfterSignatureOpt(MA_Module arg, MA_OptLayout wsAfterSignatureOpt) */

MA_Module MA_setModuleWsAfterSignatureOpt(MA_Module arg, MA_OptLayout wsAfterSignatureOpt)
{
  if (MA_isModuleModule(arg)) {
    return (MA_Module)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSignatureOpt), 5), 1);
  }

  ATabort("Module has no WsAfterSignatureOpt: %t\n", arg);
  return (MA_Module)NULL;
}

/*}}}  */
/*{{{  MA_Module MA_setModuleRulesOpt(MA_Module arg, MA_RulesOpt RulesOpt) */

MA_Module MA_setModuleRulesOpt(MA_Module arg, MA_RulesOpt RulesOpt)
{
  if (MA_isModuleModule(arg)) {
    return (MA_Module)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) RulesOpt), 6), 1);
  }

  ATabort("Module has no RulesOpt: %t\n", arg);
  return (MA_Module)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_TermArgs accessors */

/*{{{  ATbool MA_isValidTermArgs(MA_TermArgs arg) */

ATbool MA_isValidTermArgs(MA_TermArgs arg)
{
  if (MA_isTermArgsEmpty(arg)) {
    return ATtrue;
  }
  else if (MA_isTermArgsSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isTermArgsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isTermArgsEmpty(MA_TermArgs arg) */

inline ATbool MA_isTermArgsEmpty(MA_TermArgs arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MA_patternTermArgsEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool MA_isTermArgsSingle(MA_TermArgs arg) */

inline ATbool MA_isTermArgsSingle(MA_TermArgs arg)
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
      last_result = ATmatchTerm((ATerm)arg, MA_patternTermArgsSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isTermArgsMany(MA_TermArgs arg) */

inline ATbool MA_isTermArgsMany(MA_TermArgs arg)
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
      last_result = ATmatchTerm((ATerm)arg, MA_patternTermArgsMany, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
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
/*{{{  ATbool MA_hasTermArgsWsAfterHead(MA_TermArgs arg) */

ATbool MA_hasTermArgsWsAfterHead(MA_TermArgs arg)
{
  if (MA_isTermArgsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
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
  assert(!MA_isTermArgsEmpty(arg) && "getTail on an empty list");
  if (MA_isTermArgsSingle(arg)) {
    return (MA_TermArgs) MA_makeTermArgsEmpty();
  }
  else {
  
    return (MA_TermArgs)ATgetTail((ATermList)arg, 4);
  }
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
/*{{{  MA_OptLayout MA_getTermArgsWsAfterHead(MA_TermArgs arg) */

MA_OptLayout MA_getTermArgsWsAfterHead(MA_TermArgs arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getTermArgsWsAfterSep(MA_TermArgs arg) */

MA_OptLayout MA_getTermArgsWsAfterSep(MA_TermArgs arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  MA_TermArgs MA_setTermArgsHead(MA_TermArgs arg, MA_Term head) */

MA_TermArgs MA_setTermArgsHead(MA_TermArgs arg, MA_Term head)
{
  if (MA_isTermArgsSingle(arg)) {
    return (MA_TermArgs)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (MA_isTermArgsMany(arg)) {
    return (MA_TermArgs)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("TermArgs has no Head: %t\n", arg);
  return (MA_TermArgs)NULL;
}

/*}}}  */
/*{{{  MA_TermArgs MA_setTermArgsWsAfterHead(MA_TermArgs arg, MA_OptLayout wsAfterHead) */

MA_TermArgs MA_setTermArgsWsAfterHead(MA_TermArgs arg, MA_OptLayout wsAfterHead)
{
  if (MA_isTermArgsMany(arg)) {
    return (MA_TermArgs)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterHead), 1);
  }

  ATabort("TermArgs has no WsAfterHead: %t\n", arg);
  return (MA_TermArgs)NULL;
}

/*}}}  */
/*{{{  MA_TermArgs MA_setTermArgsWsAfterSep(MA_TermArgs arg, MA_OptLayout wsAfterSep) */

MA_TermArgs MA_setTermArgsWsAfterSep(MA_TermArgs arg, MA_OptLayout wsAfterSep)
{
  if (MA_isTermArgsMany(arg)) {
    return (MA_TermArgs)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterSep), 3);
  }

  ATabort("TermArgs has no WsAfterSep: %t\n", arg);
  return (MA_TermArgs)NULL;
}

/*}}}  */
/*{{{  MA_TermArgs MA_setTermArgsTail(MA_TermArgs arg, MA_TermArgs tail) */

MA_TermArgs MA_setTermArgsTail(MA_TermArgs arg, MA_TermArgs tail)
{
  if (MA_isTermArgsMany(arg)) {
    return (MA_TermArgs)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 4);
  }

  ATabort("TermArgs has no Tail: %t\n", arg);
  return (MA_TermArgs)NULL;
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
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MA_patternTermElemsEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool MA_isTermElemsSingle(MA_TermElems arg) */

inline ATbool MA_isTermElemsSingle(MA_TermElems arg)
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
      last_result = ATmatchTerm((ATerm)arg, MA_patternTermElemsSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isTermElemsMany(MA_TermElems arg) */

inline ATbool MA_isTermElemsMany(MA_TermElems arg)
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
      last_result = ATmatchTerm((ATerm)arg, MA_patternTermElemsMany, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
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
/*{{{  ATbool MA_hasTermElemsWsAfterHead(MA_TermElems arg) */

ATbool MA_hasTermElemsWsAfterHead(MA_TermElems arg)
{
  if (MA_isTermElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
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
  assert(!MA_isTermElemsEmpty(arg) && "getTail on an empty list");
  if (MA_isTermElemsSingle(arg)) {
    return (MA_TermElems) MA_makeTermElemsEmpty();
  }
  else {
  
    return (MA_TermElems)ATgetTail((ATermList)arg, 4);
  }
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
/*{{{  MA_OptLayout MA_getTermElemsWsAfterHead(MA_TermElems arg) */

MA_OptLayout MA_getTermElemsWsAfterHead(MA_TermElems arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getTermElemsWsAfterSep(MA_TermElems arg) */

MA_OptLayout MA_getTermElemsWsAfterSep(MA_TermElems arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  MA_TermElems MA_setTermElemsHead(MA_TermElems arg, MA_Term head) */

MA_TermElems MA_setTermElemsHead(MA_TermElems arg, MA_Term head)
{
  if (MA_isTermElemsSingle(arg)) {
    return (MA_TermElems)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (MA_isTermElemsMany(arg)) {
    return (MA_TermElems)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("TermElems has no Head: %t\n", arg);
  return (MA_TermElems)NULL;
}

/*}}}  */
/*{{{  MA_TermElems MA_setTermElemsWsAfterHead(MA_TermElems arg, MA_OptLayout wsAfterHead) */

MA_TermElems MA_setTermElemsWsAfterHead(MA_TermElems arg, MA_OptLayout wsAfterHead)
{
  if (MA_isTermElemsMany(arg)) {
    return (MA_TermElems)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterHead), 1);
  }

  ATabort("TermElems has no WsAfterHead: %t\n", arg);
  return (MA_TermElems)NULL;
}

/*}}}  */
/*{{{  MA_TermElems MA_setTermElemsWsAfterSep(MA_TermElems arg, MA_OptLayout wsAfterSep) */

MA_TermElems MA_setTermElemsWsAfterSep(MA_TermElems arg, MA_OptLayout wsAfterSep)
{
  if (MA_isTermElemsMany(arg)) {
    return (MA_TermElems)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterSep), 3);
  }

  ATabort("TermElems has no WsAfterSep: %t\n", arg);
  return (MA_TermElems)NULL;
}

/*}}}  */
/*{{{  MA_TermElems MA_setTermElemsTail(MA_TermElems arg, MA_TermElems tail) */

MA_TermElems MA_setTermElemsTail(MA_TermElems arg, MA_TermElems tail)
{
  if (MA_isTermElemsMany(arg)) {
    return (MA_TermElems)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 4);
  }

  ATabort("TermElems has no Tail: %t\n", arg);
  return (MA_TermElems)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_SigArgArgs accessors */

/*{{{  ATbool MA_isValidSigArgArgs(MA_SigArgArgs arg) */

ATbool MA_isValidSigArgArgs(MA_SigArgArgs arg)
{
  if (MA_isSigArgArgsEmpty(arg)) {
    return ATtrue;
  }
  else if (MA_isSigArgArgsSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isSigArgArgsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isSigArgArgsEmpty(MA_SigArgArgs arg) */

inline ATbool MA_isSigArgArgsEmpty(MA_SigArgArgs arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MA_patternSigArgArgsEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool MA_isSigArgArgsSingle(MA_SigArgArgs arg) */

inline ATbool MA_isSigArgArgsSingle(MA_SigArgArgs arg)
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
      last_result = ATmatchTerm((ATerm)arg, MA_patternSigArgArgsSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isSigArgArgsMany(MA_SigArgArgs arg) */

inline ATbool MA_isSigArgArgsMany(MA_SigArgArgs arg)
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
      last_result = ATmatchTerm((ATerm)arg, MA_patternSigArgArgsMany, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MA_hasSigArgArgsHead(MA_SigArgArgs arg) */

ATbool MA_hasSigArgArgsHead(MA_SigArgArgs arg)
{
  if (MA_isSigArgArgsSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isSigArgArgsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasSigArgArgsWsAfterHead(MA_SigArgArgs arg) */

ATbool MA_hasSigArgArgsWsAfterHead(MA_SigArgArgs arg)
{
  if (MA_isSigArgArgsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasSigArgArgsWsAfterSep(MA_SigArgArgs arg) */

ATbool MA_hasSigArgArgsWsAfterSep(MA_SigArgArgs arg)
{
  if (MA_isSigArgArgsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasSigArgArgsTail(MA_SigArgArgs arg) */

ATbool MA_hasSigArgArgsTail(MA_SigArgArgs arg)
{
  if (MA_isSigArgArgsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_SigArgArgs MA_getSigArgArgsTail(MA_SigArgArgs arg) */

MA_SigArgArgs MA_getSigArgArgsTail(MA_SigArgArgs arg)
{
  assert(!MA_isSigArgArgsEmpty(arg) && "getTail on an empty list");
  if (MA_isSigArgArgsSingle(arg)) {
    return (MA_SigArgArgs) MA_makeSigArgArgsEmpty();
  }
  else {
  
    return (MA_SigArgArgs)ATgetTail((ATermList)arg, 4);
  }
}

/*}}}  */
/*{{{  MA_SigArg MA_getSigArgArgsHead(MA_SigArgArgs arg) */

MA_SigArg MA_getSigArgArgsHead(MA_SigArgArgs arg)
{
  if (MA_isSigArgArgsSingle(arg)) {
    return (MA_SigArg)ATgetFirst((ATermList)arg);
  }
  else 
    return (MA_SigArg)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getSigArgArgsWsAfterHead(MA_SigArgArgs arg) */

MA_OptLayout MA_getSigArgArgsWsAfterHead(MA_SigArgArgs arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getSigArgArgsWsAfterSep(MA_SigArgArgs arg) */

MA_OptLayout MA_getSigArgArgsWsAfterSep(MA_SigArgArgs arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  MA_SigArgArgs MA_setSigArgArgsHead(MA_SigArgArgs arg, MA_SigArg head) */

MA_SigArgArgs MA_setSigArgArgsHead(MA_SigArgArgs arg, MA_SigArg head)
{
  if (MA_isSigArgArgsSingle(arg)) {
    return (MA_SigArgArgs)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (MA_isSigArgArgsMany(arg)) {
    return (MA_SigArgArgs)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("SigArgArgs has no Head: %t\n", arg);
  return (MA_SigArgArgs)NULL;
}

/*}}}  */
/*{{{  MA_SigArgArgs MA_setSigArgArgsWsAfterHead(MA_SigArgArgs arg, MA_OptLayout wsAfterHead) */

MA_SigArgArgs MA_setSigArgArgsWsAfterHead(MA_SigArgArgs arg, MA_OptLayout wsAfterHead)
{
  if (MA_isSigArgArgsMany(arg)) {
    return (MA_SigArgArgs)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterHead), 1);
  }

  ATabort("SigArgArgs has no WsAfterHead: %t\n", arg);
  return (MA_SigArgArgs)NULL;
}

/*}}}  */
/*{{{  MA_SigArgArgs MA_setSigArgArgsWsAfterSep(MA_SigArgArgs arg, MA_OptLayout wsAfterSep) */

MA_SigArgArgs MA_setSigArgArgsWsAfterSep(MA_SigArgArgs arg, MA_OptLayout wsAfterSep)
{
  if (MA_isSigArgArgsMany(arg)) {
    return (MA_SigArgArgs)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterSep), 3);
  }

  ATabort("SigArgArgs has no WsAfterSep: %t\n", arg);
  return (MA_SigArgArgs)NULL;
}

/*}}}  */
/*{{{  MA_SigArgArgs MA_setSigArgArgsTail(MA_SigArgArgs arg, MA_SigArgArgs tail) */

MA_SigArgArgs MA_setSigArgArgsTail(MA_SigArgArgs arg, MA_SigArgArgs tail)
{
  if (MA_isSigArgArgsMany(arg)) {
    return (MA_SigArgArgs)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 4);
  }

  ATabort("SigArgArgs has no Tail: %t\n", arg);
  return (MA_SigArgArgs)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_TermAttrs accessors */

/*{{{  ATbool MA_isValidTermAttrs(MA_TermAttrs arg) */

ATbool MA_isValidTermAttrs(MA_TermAttrs arg)
{
  if (MA_isTermAttrsEmpty(arg)) {
    return ATtrue;
  }
  else if (MA_isTermAttrsSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isTermAttrsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isTermAttrsEmpty(MA_TermAttrs arg) */

inline ATbool MA_isTermAttrsEmpty(MA_TermAttrs arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MA_patternTermAttrsEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool MA_isTermAttrsSingle(MA_TermAttrs arg) */

inline ATbool MA_isTermAttrsSingle(MA_TermAttrs arg)
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
      last_result = ATmatchTerm((ATerm)arg, MA_patternTermAttrsSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isTermAttrsMany(MA_TermAttrs arg) */

inline ATbool MA_isTermAttrsMany(MA_TermAttrs arg)
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
      last_result = ATmatchTerm((ATerm)arg, MA_patternTermAttrsMany, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MA_hasTermAttrsHead(MA_TermAttrs arg) */

ATbool MA_hasTermAttrsHead(MA_TermAttrs arg)
{
  if (MA_isTermAttrsSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isTermAttrsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasTermAttrsWsAfterHead(MA_TermAttrs arg) */

ATbool MA_hasTermAttrsWsAfterHead(MA_TermAttrs arg)
{
  if (MA_isTermAttrsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasTermAttrsWsAfterSep(MA_TermAttrs arg) */

ATbool MA_hasTermAttrsWsAfterSep(MA_TermAttrs arg)
{
  if (MA_isTermAttrsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasTermAttrsTail(MA_TermAttrs arg) */

ATbool MA_hasTermAttrsTail(MA_TermAttrs arg)
{
  if (MA_isTermAttrsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_TermAttrs MA_getTermAttrsTail(MA_TermAttrs arg) */

MA_TermAttrs MA_getTermAttrsTail(MA_TermAttrs arg)
{
  assert(!MA_isTermAttrsEmpty(arg) && "getTail on an empty list");
  if (MA_isTermAttrsSingle(arg)) {
    return (MA_TermAttrs) MA_makeTermAttrsEmpty();
  }
  else {
  
    return (MA_TermAttrs)ATgetTail((ATermList)arg, 4);
  }
}

/*}}}  */
/*{{{  MA_Term MA_getTermAttrsHead(MA_TermAttrs arg) */

MA_Term MA_getTermAttrsHead(MA_TermAttrs arg)
{
  if (MA_isTermAttrsSingle(arg)) {
    return (MA_Term)ATgetFirst((ATermList)arg);
  }
  else 
    return (MA_Term)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getTermAttrsWsAfterHead(MA_TermAttrs arg) */

MA_OptLayout MA_getTermAttrsWsAfterHead(MA_TermAttrs arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getTermAttrsWsAfterSep(MA_TermAttrs arg) */

MA_OptLayout MA_getTermAttrsWsAfterSep(MA_TermAttrs arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  MA_TermAttrs MA_setTermAttrsHead(MA_TermAttrs arg, MA_Term head) */

MA_TermAttrs MA_setTermAttrsHead(MA_TermAttrs arg, MA_Term head)
{
  if (MA_isTermAttrsSingle(arg)) {
    return (MA_TermAttrs)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (MA_isTermAttrsMany(arg)) {
    return (MA_TermAttrs)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("TermAttrs has no Head: %t\n", arg);
  return (MA_TermAttrs)NULL;
}

/*}}}  */
/*{{{  MA_TermAttrs MA_setTermAttrsWsAfterHead(MA_TermAttrs arg, MA_OptLayout wsAfterHead) */

MA_TermAttrs MA_setTermAttrsWsAfterHead(MA_TermAttrs arg, MA_OptLayout wsAfterHead)
{
  if (MA_isTermAttrsMany(arg)) {
    return (MA_TermAttrs)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterHead), 1);
  }

  ATabort("TermAttrs has no WsAfterHead: %t\n", arg);
  return (MA_TermAttrs)NULL;
}

/*}}}  */
/*{{{  MA_TermAttrs MA_setTermAttrsWsAfterSep(MA_TermAttrs arg, MA_OptLayout wsAfterSep) */

MA_TermAttrs MA_setTermAttrsWsAfterSep(MA_TermAttrs arg, MA_OptLayout wsAfterSep)
{
  if (MA_isTermAttrsMany(arg)) {
    return (MA_TermAttrs)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterSep), 3);
  }

  ATabort("TermAttrs has no WsAfterSep: %t\n", arg);
  return (MA_TermAttrs)NULL;
}

/*}}}  */
/*{{{  MA_TermAttrs MA_setTermAttrsTail(MA_TermAttrs arg, MA_TermAttrs tail) */

MA_TermAttrs MA_setTermAttrsTail(MA_TermAttrs arg, MA_TermAttrs tail)
{
  if (MA_isTermAttrsMany(arg)) {
    return (MA_TermAttrs)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 4);
  }

  ATabort("TermAttrs has no Tail: %t\n", arg);
  return (MA_TermAttrs)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_FuncDefDefs accessors */

/*{{{  ATbool MA_isValidFuncDefDefs(MA_FuncDefDefs arg) */

ATbool MA_isValidFuncDefDefs(MA_FuncDefDefs arg)
{
  if (MA_isFuncDefDefsEmpty(arg)) {
    return ATtrue;
  }
  else if (MA_isFuncDefDefsSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isFuncDefDefsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isFuncDefDefsEmpty(MA_FuncDefDefs arg) */

inline ATbool MA_isFuncDefDefsEmpty(MA_FuncDefDefs arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MA_patternFuncDefDefsEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool MA_isFuncDefDefsSingle(MA_FuncDefDefs arg) */

inline ATbool MA_isFuncDefDefsSingle(MA_FuncDefDefs arg)
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
      last_result = ATmatchTerm((ATerm)arg, MA_patternFuncDefDefsSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isFuncDefDefsMany(MA_FuncDefDefs arg) */

inline ATbool MA_isFuncDefDefsMany(MA_FuncDefDefs arg)
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
      last_result = ATmatchTerm((ATerm)arg, MA_patternFuncDefDefsMany, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MA_hasFuncDefDefsHead(MA_FuncDefDefs arg) */

ATbool MA_hasFuncDefDefsHead(MA_FuncDefDefs arg)
{
  if (MA_isFuncDefDefsSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isFuncDefDefsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasFuncDefDefsWsAfterHead(MA_FuncDefDefs arg) */

ATbool MA_hasFuncDefDefsWsAfterHead(MA_FuncDefDefs arg)
{
  if (MA_isFuncDefDefsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasFuncDefDefsWsAfterSep(MA_FuncDefDefs arg) */

ATbool MA_hasFuncDefDefsWsAfterSep(MA_FuncDefDefs arg)
{
  if (MA_isFuncDefDefsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasFuncDefDefsTail(MA_FuncDefDefs arg) */

ATbool MA_hasFuncDefDefsTail(MA_FuncDefDefs arg)
{
  if (MA_isFuncDefDefsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_FuncDefDefs MA_getFuncDefDefsTail(MA_FuncDefDefs arg) */

MA_FuncDefDefs MA_getFuncDefDefsTail(MA_FuncDefDefs arg)
{
  assert(!MA_isFuncDefDefsEmpty(arg) && "getTail on an empty list");
  if (MA_isFuncDefDefsSingle(arg)) {
    return (MA_FuncDefDefs) MA_makeFuncDefDefsEmpty();
  }
  else {
  
    return (MA_FuncDefDefs)ATgetTail((ATermList)arg, 4);
  }
}

/*}}}  */
/*{{{  MA_FuncDef MA_getFuncDefDefsHead(MA_FuncDefDefs arg) */

MA_FuncDef MA_getFuncDefDefsHead(MA_FuncDefDefs arg)
{
  if (MA_isFuncDefDefsSingle(arg)) {
    return (MA_FuncDef)ATgetFirst((ATermList)arg);
  }
  else 
    return (MA_FuncDef)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getFuncDefDefsWsAfterHead(MA_FuncDefDefs arg) */

MA_OptLayout MA_getFuncDefDefsWsAfterHead(MA_FuncDefDefs arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getFuncDefDefsWsAfterSep(MA_FuncDefDefs arg) */

MA_OptLayout MA_getFuncDefDefsWsAfterSep(MA_FuncDefDefs arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  MA_FuncDefDefs MA_setFuncDefDefsHead(MA_FuncDefDefs arg, MA_FuncDef head) */

MA_FuncDefDefs MA_setFuncDefDefsHead(MA_FuncDefDefs arg, MA_FuncDef head)
{
  if (MA_isFuncDefDefsSingle(arg)) {
    return (MA_FuncDefDefs)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (MA_isFuncDefDefsMany(arg)) {
    return (MA_FuncDefDefs)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("FuncDefDefs has no Head: %t\n", arg);
  return (MA_FuncDefDefs)NULL;
}

/*}}}  */
/*{{{  MA_FuncDefDefs MA_setFuncDefDefsWsAfterHead(MA_FuncDefDefs arg, MA_OptLayout wsAfterHead) */

MA_FuncDefDefs MA_setFuncDefDefsWsAfterHead(MA_FuncDefDefs arg, MA_OptLayout wsAfterHead)
{
  if (MA_isFuncDefDefsMany(arg)) {
    return (MA_FuncDefDefs)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterHead), 1);
  }

  ATabort("FuncDefDefs has no WsAfterHead: %t\n", arg);
  return (MA_FuncDefDefs)NULL;
}

/*}}}  */
/*{{{  MA_FuncDefDefs MA_setFuncDefDefsWsAfterSep(MA_FuncDefDefs arg, MA_OptLayout wsAfterSep) */

MA_FuncDefDefs MA_setFuncDefDefsWsAfterSep(MA_FuncDefDefs arg, MA_OptLayout wsAfterSep)
{
  if (MA_isFuncDefDefsMany(arg)) {
    return (MA_FuncDefDefs)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterSep), 3);
  }

  ATabort("FuncDefDefs has no WsAfterSep: %t\n", arg);
  return (MA_FuncDefDefs)NULL;
}

/*}}}  */
/*{{{  MA_FuncDefDefs MA_setFuncDefDefsTail(MA_FuncDefDefs arg, MA_FuncDefDefs tail) */

MA_FuncDefDefs MA_setFuncDefDefsTail(MA_FuncDefDefs arg, MA_FuncDefDefs tail)
{
  if (MA_isFuncDefDefsMany(arg)) {
    return (MA_FuncDefDefs)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 4);
  }

  ATabort("FuncDefDefs has no Tail: %t\n", arg);
  return (MA_FuncDefDefs)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_RuleRules accessors */

/*{{{  ATbool MA_isValidRuleRules(MA_RuleRules arg) */

ATbool MA_isValidRuleRules(MA_RuleRules arg)
{
  if (MA_isRuleRulesEmpty(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleRulesSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleRulesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isRuleRulesEmpty(MA_RuleRules arg) */

inline ATbool MA_isRuleRulesEmpty(MA_RuleRules arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MA_patternRuleRulesEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool MA_isRuleRulesSingle(MA_RuleRules arg) */

inline ATbool MA_isRuleRulesSingle(MA_RuleRules arg)
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
      last_result = ATmatchTerm((ATerm)arg, MA_patternRuleRulesSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isRuleRulesMany(MA_RuleRules arg) */

inline ATbool MA_isRuleRulesMany(MA_RuleRules arg)
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
      last_result = ATmatchTerm((ATerm)arg, MA_patternRuleRulesMany, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MA_hasRuleRulesHead(MA_RuleRules arg) */

ATbool MA_hasRuleRulesHead(MA_RuleRules arg)
{
  if (MA_isRuleRulesSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isRuleRulesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasRuleRulesWsAfterHead(MA_RuleRules arg) */

ATbool MA_hasRuleRulesWsAfterHead(MA_RuleRules arg)
{
  if (MA_isRuleRulesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasRuleRulesWsAfterSep(MA_RuleRules arg) */

ATbool MA_hasRuleRulesWsAfterSep(MA_RuleRules arg)
{
  if (MA_isRuleRulesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasRuleRulesTail(MA_RuleRules arg) */

ATbool MA_hasRuleRulesTail(MA_RuleRules arg)
{
  if (MA_isRuleRulesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_RuleRules MA_getRuleRulesTail(MA_RuleRules arg) */

MA_RuleRules MA_getRuleRulesTail(MA_RuleRules arg)
{
  assert(!MA_isRuleRulesEmpty(arg) && "getTail on an empty list");
  if (MA_isRuleRulesSingle(arg)) {
    return (MA_RuleRules) MA_makeRuleRulesEmpty();
  }
  else {
  
    return (MA_RuleRules)ATgetTail((ATermList)arg, 4);
  }
}

/*}}}  */
/*{{{  MA_Rule MA_getRuleRulesHead(MA_RuleRules arg) */

MA_Rule MA_getRuleRulesHead(MA_RuleRules arg)
{
  if (MA_isRuleRulesSingle(arg)) {
    return (MA_Rule)ATgetFirst((ATermList)arg);
  }
  else 
    return (MA_Rule)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getRuleRulesWsAfterHead(MA_RuleRules arg) */

MA_OptLayout MA_getRuleRulesWsAfterHead(MA_RuleRules arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getRuleRulesWsAfterSep(MA_RuleRules arg) */

MA_OptLayout MA_getRuleRulesWsAfterSep(MA_RuleRules arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  MA_RuleRules MA_setRuleRulesHead(MA_RuleRules arg, MA_Rule head) */

MA_RuleRules MA_setRuleRulesHead(MA_RuleRules arg, MA_Rule head)
{
  if (MA_isRuleRulesSingle(arg)) {
    return (MA_RuleRules)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (MA_isRuleRulesMany(arg)) {
    return (MA_RuleRules)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("RuleRules has no Head: %t\n", arg);
  return (MA_RuleRules)NULL;
}

/*}}}  */
/*{{{  MA_RuleRules MA_setRuleRulesWsAfterHead(MA_RuleRules arg, MA_OptLayout wsAfterHead) */

MA_RuleRules MA_setRuleRulesWsAfterHead(MA_RuleRules arg, MA_OptLayout wsAfterHead)
{
  if (MA_isRuleRulesMany(arg)) {
    return (MA_RuleRules)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterHead), 1);
  }

  ATabort("RuleRules has no WsAfterHead: %t\n", arg);
  return (MA_RuleRules)NULL;
}

/*}}}  */
/*{{{  MA_RuleRules MA_setRuleRulesWsAfterSep(MA_RuleRules arg, MA_OptLayout wsAfterSep) */

MA_RuleRules MA_setRuleRulesWsAfterSep(MA_RuleRules arg, MA_OptLayout wsAfterSep)
{
  if (MA_isRuleRulesMany(arg)) {
    return (MA_RuleRules)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterSep), 3);
  }

  ATabort("RuleRules has no WsAfterSep: %t\n", arg);
  return (MA_RuleRules)NULL;
}

/*}}}  */
/*{{{  MA_RuleRules MA_setRuleRulesTail(MA_RuleRules arg, MA_RuleRules tail) */

MA_RuleRules MA_setRuleRulesTail(MA_RuleRules arg, MA_RuleRules tail)
{
  if (MA_isRuleRulesMany(arg)) {
    return (MA_RuleRules)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 4);
  }

  ATabort("RuleRules has no Tail: %t\n", arg);
  return (MA_RuleRules)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_CondConds accessors */

/*{{{  ATbool MA_isValidCondConds(MA_CondConds arg) */

ATbool MA_isValidCondConds(MA_CondConds arg)
{
  if (MA_isCondCondsEmpty(arg)) {
    return ATtrue;
  }
  else if (MA_isCondCondsSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isCondCondsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isCondCondsEmpty(MA_CondConds arg) */

inline ATbool MA_isCondCondsEmpty(MA_CondConds arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MA_patternCondCondsEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool MA_isCondCondsSingle(MA_CondConds arg) */

inline ATbool MA_isCondCondsSingle(MA_CondConds arg)
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
      last_result = ATmatchTerm((ATerm)arg, MA_patternCondCondsSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isCondCondsMany(MA_CondConds arg) */

inline ATbool MA_isCondCondsMany(MA_CondConds arg)
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
      last_result = ATmatchTerm((ATerm)arg, MA_patternCondCondsMany, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MA_hasCondCondsHead(MA_CondConds arg) */

ATbool MA_hasCondCondsHead(MA_CondConds arg)
{
  if (MA_isCondCondsSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isCondCondsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasCondCondsWsAfterHead(MA_CondConds arg) */

ATbool MA_hasCondCondsWsAfterHead(MA_CondConds arg)
{
  if (MA_isCondCondsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasCondCondsWsAfterSep(MA_CondConds arg) */

ATbool MA_hasCondCondsWsAfterSep(MA_CondConds arg)
{
  if (MA_isCondCondsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasCondCondsTail(MA_CondConds arg) */

ATbool MA_hasCondCondsTail(MA_CondConds arg)
{
  if (MA_isCondCondsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_CondConds MA_getCondCondsTail(MA_CondConds arg) */

MA_CondConds MA_getCondCondsTail(MA_CondConds arg)
{
  assert(!MA_isCondCondsEmpty(arg) && "getTail on an empty list");
  if (MA_isCondCondsSingle(arg)) {
    return (MA_CondConds) MA_makeCondCondsEmpty();
  }
  else {
  
    return (MA_CondConds)ATgetTail((ATermList)arg, 4);
  }
}

/*}}}  */
/*{{{  MA_Cond MA_getCondCondsHead(MA_CondConds arg) */

MA_Cond MA_getCondCondsHead(MA_CondConds arg)
{
  if (MA_isCondCondsSingle(arg)) {
    return (MA_Cond)ATgetFirst((ATermList)arg);
  }
  else 
    return (MA_Cond)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getCondCondsWsAfterHead(MA_CondConds arg) */

MA_OptLayout MA_getCondCondsWsAfterHead(MA_CondConds arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  MA_OptLayout MA_getCondCondsWsAfterSep(MA_CondConds arg) */

MA_OptLayout MA_getCondCondsWsAfterSep(MA_CondConds arg)
{
  
    return (MA_OptLayout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  MA_CondConds MA_setCondCondsHead(MA_CondConds arg, MA_Cond head) */

MA_CondConds MA_setCondCondsHead(MA_CondConds arg, MA_Cond head)
{
  if (MA_isCondCondsSingle(arg)) {
    return (MA_CondConds)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (MA_isCondCondsMany(arg)) {
    return (MA_CondConds)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("CondConds has no Head: %t\n", arg);
  return (MA_CondConds)NULL;
}

/*}}}  */
/*{{{  MA_CondConds MA_setCondCondsWsAfterHead(MA_CondConds arg, MA_OptLayout wsAfterHead) */

MA_CondConds MA_setCondCondsWsAfterHead(MA_CondConds arg, MA_OptLayout wsAfterHead)
{
  if (MA_isCondCondsMany(arg)) {
    return (MA_CondConds)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterHead), 1);
  }

  ATabort("CondConds has no WsAfterHead: %t\n", arg);
  return (MA_CondConds)NULL;
}

/*}}}  */
/*{{{  MA_CondConds MA_setCondCondsWsAfterSep(MA_CondConds arg, MA_OptLayout wsAfterSep) */

MA_CondConds MA_setCondCondsWsAfterSep(MA_CondConds arg, MA_OptLayout wsAfterSep)
{
  if (MA_isCondCondsMany(arg)) {
    return (MA_CondConds)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterSep), 3);
  }

  ATabort("CondConds has no WsAfterSep: %t\n", arg);
  return (MA_CondConds)NULL;
}

/*}}}  */
/*{{{  MA_CondConds MA_setCondCondsTail(MA_CondConds arg, MA_CondConds tail) */

MA_CondConds MA_setCondCondsTail(MA_CondConds arg, MA_CondConds tail)
{
  if (MA_isCondCondsMany(arg)) {
    return (MA_CondConds)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 4);
  }

  ATabort("CondConds has no Tail: %t\n", arg);
  return (MA_CondConds)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_LexLayout accessors */

/*{{{  ATbool MA_isValidLexLayout(MA_LexLayout arg) */

ATbool MA_isValidLexLayout(MA_LexLayout arg)
{
  if (MA_isLexLayoutWhitespace(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isLexLayoutWhitespace(MA_LexLayout arg) */

inline ATbool MA_isLexLayoutWhitespace(MA_LexLayout arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MA_patternLexLayoutWhitespace, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool MA_hasLexLayoutCh(MA_LexLayout arg) */

ATbool MA_hasLexLayoutCh(MA_LexLayout arg)
{
  if (MA_isLexLayoutWhitespace(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char MA_getLexLayoutCh(MA_LexLayout arg) */

char MA_getLexLayoutCh(MA_LexLayout arg)
{
  
    return (char)MA_charToByte((ATerm)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  MA_LexLayout MA_setLexLayoutCh(MA_LexLayout arg, char ch) */

MA_LexLayout MA_setLexLayoutCh(MA_LexLayout arg, char ch)
{
  if (MA_isLexLayoutWhitespace(arg)) {
    return (MA_LexLayout)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) MA_byteToChar(ch))), 0), 1);
  }

  ATabort("LexLayout has no Ch: %t\n", arg);
  return (MA_LexLayout)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_LexStrChar accessors */

/*{{{  ATbool MA_isValidLexStrChar(MA_LexStrChar arg) */

ATbool MA_isValidLexStrChar(MA_LexStrChar arg)
{
  if (MA_isLexStrCharNewline(arg)) {
    return ATtrue;
  }
  else if (MA_isLexStrCharTab(arg)) {
    return ATtrue;
  }
  else if (MA_isLexStrCharQuote(arg)) {
    return ATtrue;
  }
  else if (MA_isLexStrCharBackslash(arg)) {
    return ATtrue;
  }
  else if (MA_isLexStrCharDecimal(arg)) {
    return ATtrue;
  }
  else if (MA_isLexStrCharNormal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isLexStrCharNewline(MA_LexStrChar arg) */

inline ATbool MA_isLexStrCharNewline(MA_LexStrChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternLexStrCharNewline);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isLexStrCharTab(MA_LexStrChar arg) */

inline ATbool MA_isLexStrCharTab(MA_LexStrChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternLexStrCharTab);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isLexStrCharQuote(MA_LexStrChar arg) */

inline ATbool MA_isLexStrCharQuote(MA_LexStrChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternLexStrCharQuote);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isLexStrCharBackslash(MA_LexStrChar arg) */

inline ATbool MA_isLexStrCharBackslash(MA_LexStrChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternLexStrCharBackslash);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isLexStrCharDecimal(MA_LexStrChar arg) */

inline ATbool MA_isLexStrCharDecimal(MA_LexStrChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternLexStrCharDecimal, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isLexStrCharNormal(MA_LexStrChar arg) */

inline ATbool MA_isLexStrCharNormal(MA_LexStrChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, MA_patternLexStrCharNormal, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MA_hasLexStrCharA(MA_LexStrChar arg) */

ATbool MA_hasLexStrCharA(MA_LexStrChar arg)
{
  if (MA_isLexStrCharDecimal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasLexStrCharB(MA_LexStrChar arg) */

ATbool MA_hasLexStrCharB(MA_LexStrChar arg)
{
  if (MA_isLexStrCharDecimal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasLexStrCharC(MA_LexStrChar arg) */

ATbool MA_hasLexStrCharC(MA_LexStrChar arg)
{
  if (MA_isLexStrCharDecimal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasLexStrCharCh(MA_LexStrChar arg) */

ATbool MA_hasLexStrCharCh(MA_LexStrChar arg)
{
  if (MA_isLexStrCharNormal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char MA_getLexStrCharA(MA_LexStrChar arg) */

char MA_getLexStrCharA(MA_LexStrChar arg)
{
  
    return (char)MA_charToByte((ATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1));
}

/*}}}  */
/*{{{  char MA_getLexStrCharB(MA_LexStrChar arg) */

char MA_getLexStrCharB(MA_LexStrChar arg)
{
  
    return (char)MA_charToByte((ATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2));
}

/*}}}  */
/*{{{  char MA_getLexStrCharC(MA_LexStrChar arg) */

char MA_getLexStrCharC(MA_LexStrChar arg)
{
  
    return (char)MA_charToByte((ATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3));
}

/*}}}  */
/*{{{  char MA_getLexStrCharCh(MA_LexStrChar arg) */

char MA_getLexStrCharCh(MA_LexStrChar arg)
{
  
    return (char)MA_charToByte((ATerm)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  MA_LexStrChar MA_setLexStrCharA(MA_LexStrChar arg, char a) */

MA_LexStrChar MA_setLexStrCharA(MA_LexStrChar arg, char a)
{
  if (MA_isLexStrCharDecimal(arg)) {
    return (MA_LexStrChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) MA_byteToChar(a))), 1), 1);
  }

  ATabort("LexStrChar has no A: %t\n", arg);
  return (MA_LexStrChar)NULL;
}

/*}}}  */
/*{{{  MA_LexStrChar MA_setLexStrCharB(MA_LexStrChar arg, char b) */

MA_LexStrChar MA_setLexStrCharB(MA_LexStrChar arg, char b)
{
  if (MA_isLexStrCharDecimal(arg)) {
    return (MA_LexStrChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) MA_byteToChar(b))), 2), 1);
  }

  ATabort("LexStrChar has no B: %t\n", arg);
  return (MA_LexStrChar)NULL;
}

/*}}}  */
/*{{{  MA_LexStrChar MA_setLexStrCharC(MA_LexStrChar arg, char c) */

MA_LexStrChar MA_setLexStrCharC(MA_LexStrChar arg, char c)
{
  if (MA_isLexStrCharDecimal(arg)) {
    return (MA_LexStrChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) MA_byteToChar(c))), 3), 1);
  }

  ATabort("LexStrChar has no C: %t\n", arg);
  return (MA_LexStrChar)NULL;
}

/*}}}  */
/*{{{  MA_LexStrChar MA_setLexStrCharCh(MA_LexStrChar arg, char ch) */

MA_LexStrChar MA_setLexStrCharCh(MA_LexStrChar arg, char ch)
{
  if (MA_isLexStrCharNormal(arg)) {
    return (MA_LexStrChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) MA_byteToChar(ch))), 0), 1);
  }

  ATabort("LexStrChar has no Ch: %t\n", arg);
  return (MA_LexStrChar)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_StrChar accessors */

/*{{{  ATbool MA_isValidStrChar(MA_StrChar arg) */

ATbool MA_isValidStrChar(MA_StrChar arg)
{
  if (MA_isStrCharLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isStrCharLexToCf(MA_StrChar arg) */

inline ATbool MA_isStrCharLexToCf(MA_StrChar arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MA_patternStrCharLexToCf, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool MA_hasStrCharStrChar(MA_StrChar arg) */

ATbool MA_hasStrCharStrChar(MA_StrChar arg)
{
  if (MA_isStrCharLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_LexStrChar MA_getStrCharStrChar(MA_StrChar arg) */

MA_LexStrChar MA_getStrCharStrChar(MA_StrChar arg)
{
  
    return (MA_LexStrChar)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  MA_StrChar MA_setStrCharStrChar(MA_StrChar arg, MA_LexStrChar StrChar) */

MA_StrChar MA_setStrCharStrChar(MA_StrChar arg, MA_LexStrChar StrChar)
{
  if (MA_isStrCharLexToCf(arg)) {
    return (MA_StrChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) StrChar), 0), 1);
  }

  ATabort("StrChar has no StrChar: %t\n", arg);
  return (MA_StrChar)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_LexStrCon accessors */

/*{{{  ATbool MA_isValidLexStrCon(MA_LexStrCon arg) */

ATbool MA_isValidLexStrCon(MA_LexStrCon arg)
{
  if (MA_isLexStrConDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isLexStrConDefault(MA_LexStrCon arg) */

inline ATbool MA_isLexStrConDefault(MA_LexStrCon arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MA_patternLexStrConDefault, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool MA_hasLexStrConChars(MA_LexStrCon arg) */

ATbool MA_hasLexStrConChars(MA_LexStrCon arg)
{
  if (MA_isLexStrConDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_LexStrCharChars MA_getLexStrConChars(MA_LexStrCon arg) */

MA_LexStrCharChars MA_getLexStrConChars(MA_LexStrCon arg)
{
  
    return (MA_LexStrCharChars)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1), 1);
}

/*}}}  */
/*{{{  MA_LexStrCon MA_setLexStrConChars(MA_LexStrCon arg, MA_LexStrCharChars chars) */

MA_LexStrCon MA_setLexStrConChars(MA_LexStrCon arg, MA_LexStrCharChars chars)
{
  if (MA_isLexStrConDefault(arg)) {
    return (MA_LexStrCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1), (ATerm)((ATerm) chars), 1), 1), 1);
  }

  ATabort("LexStrCon has no Chars: %t\n", arg);
  return (MA_LexStrCon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_StrCon accessors */

/*{{{  ATbool MA_isValidStrCon(MA_StrCon arg) */

ATbool MA_isValidStrCon(MA_StrCon arg)
{
  if (MA_isStrConLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isStrConLexToCf(MA_StrCon arg) */

inline ATbool MA_isStrConLexToCf(MA_StrCon arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MA_patternStrConLexToCf, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool MA_hasStrConStrCon(MA_StrCon arg) */

ATbool MA_hasStrConStrCon(MA_StrCon arg)
{
  if (MA_isStrConLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_LexStrCon MA_getStrConStrCon(MA_StrCon arg) */

MA_LexStrCon MA_getStrConStrCon(MA_StrCon arg)
{
  
    return (MA_LexStrCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  MA_StrCon MA_setStrConStrCon(MA_StrCon arg, MA_LexStrCon StrCon) */

MA_StrCon MA_setStrConStrCon(MA_StrCon arg, MA_LexStrCon StrCon)
{
  if (MA_isStrConLexToCf(arg)) {
    return (MA_StrCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) StrCon), 0), 1);
  }

  ATabort("StrCon has no StrCon: %t\n", arg);
  return (MA_StrCon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_LexStrCharChars accessors */

/*{{{  ATbool MA_isValidLexStrCharChars(MA_LexStrCharChars arg) */

ATbool MA_isValidLexStrCharChars(MA_LexStrCharChars arg)
{
  if (MA_isLexStrCharCharsEmpty(arg)) {
    return ATtrue;
  }
  else if (MA_isLexStrCharCharsSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isLexStrCharCharsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isLexStrCharCharsEmpty(MA_LexStrCharChars arg) */

inline ATbool MA_isLexStrCharCharsEmpty(MA_LexStrCharChars arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MA_patternLexStrCharCharsEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool MA_isLexStrCharCharsSingle(MA_LexStrCharChars arg) */

inline ATbool MA_isLexStrCharCharsSingle(MA_LexStrCharChars arg)
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
      last_result = ATmatchTerm((ATerm)arg, MA_patternLexStrCharCharsSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool MA_isLexStrCharCharsMany(MA_LexStrCharChars arg) */

inline ATbool MA_isLexStrCharCharsMany(MA_LexStrCharChars arg)
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
      last_result = ATmatchTerm((ATerm)arg, MA_patternLexStrCharCharsMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool MA_hasLexStrCharCharsHead(MA_LexStrCharChars arg) */

ATbool MA_hasLexStrCharCharsHead(MA_LexStrCharChars arg)
{
  if (MA_isLexStrCharCharsSingle(arg)) {
    return ATtrue;
  }
  else if (MA_isLexStrCharCharsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasLexStrCharCharsTail(MA_LexStrCharChars arg) */

ATbool MA_hasLexStrCharCharsTail(MA_LexStrCharChars arg)
{
  if (MA_isLexStrCharCharsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_LexStrChar MA_getLexStrCharCharsHead(MA_LexStrCharChars arg) */

MA_LexStrChar MA_getLexStrCharCharsHead(MA_LexStrCharChars arg)
{
  if (MA_isLexStrCharCharsSingle(arg)) {
    return (MA_LexStrChar)ATgetFirst((ATermList)arg);
  }
  else 
    return (MA_LexStrChar)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  MA_LexStrCharChars MA_getLexStrCharCharsTail(MA_LexStrCharChars arg) */

MA_LexStrCharChars MA_getLexStrCharCharsTail(MA_LexStrCharChars arg)
{
  
    return (MA_LexStrCharChars)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  MA_LexStrCharChars MA_setLexStrCharCharsHead(MA_LexStrCharChars arg, MA_LexStrChar head) */

MA_LexStrCharChars MA_setLexStrCharCharsHead(MA_LexStrCharChars arg, MA_LexStrChar head)
{
  if (MA_isLexStrCharCharsSingle(arg)) {
    return (MA_LexStrCharChars)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (MA_isLexStrCharCharsMany(arg)) {
    return (MA_LexStrCharChars)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("LexStrCharChars has no Head: %t\n", arg);
  return (MA_LexStrCharChars)NULL;
}

/*}}}  */
/*{{{  MA_LexStrCharChars MA_setLexStrCharCharsTail(MA_LexStrCharChars arg, MA_LexStrCharChars tail) */

MA_LexStrCharChars MA_setLexStrCharCharsTail(MA_LexStrCharChars arg, MA_LexStrCharChars tail)
{
  if (MA_isLexStrCharCharsMany(arg)) {
    return (MA_LexStrCharChars)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("LexStrCharChars has no Tail: %t\n", arg);
  return (MA_LexStrCharChars)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_LexNatCon accessors */

/*{{{  ATbool MA_isValidLexNatCon(MA_LexNatCon arg) */

ATbool MA_isValidLexNatCon(MA_LexNatCon arg)
{
  if (MA_isLexNatConDigits(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isLexNatConDigits(MA_LexNatCon arg) */

inline ATbool MA_isLexNatConDigits(MA_LexNatCon arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MA_patternLexNatConDigits, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool MA_hasLexNatConList(MA_LexNatCon arg) */

ATbool MA_hasLexNatConList(MA_LexNatCon arg)
{
  if (MA_isLexNatConDigits(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* MA_getLexNatConList(MA_LexNatCon arg) */

char* MA_getLexNatConList(MA_LexNatCon arg)
{
  
    return (char*)MA_charsToString((ATerm)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1));
}

/*}}}  */
/*{{{  MA_LexNatCon MA_setLexNatConList(MA_LexNatCon arg, const char* list) */

MA_LexNatCon MA_setLexNatConList(MA_LexNatCon arg, const char* list)
{
  if (MA_isLexNatConDigits(arg)) {
    return (MA_LexNatCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) ((ATerm) MA_stringToChars(list))), 1), 0), 1);
  }

  ATabort("LexNatCon has no List: %t\n", arg);
  return (MA_LexNatCon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_NatCon accessors */

/*{{{  ATbool MA_isValidNatCon(MA_NatCon arg) */

ATbool MA_isValidNatCon(MA_NatCon arg)
{
  if (MA_isNatConLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isNatConLexToCf(MA_NatCon arg) */

inline ATbool MA_isNatConLexToCf(MA_NatCon arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MA_patternNatConLexToCf, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool MA_hasNatConNatCon(MA_NatCon arg) */

ATbool MA_hasNatConNatCon(MA_NatCon arg)
{
  if (MA_isNatConLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_LexNatCon MA_getNatConNatCon(MA_NatCon arg) */

MA_LexNatCon MA_getNatConNatCon(MA_NatCon arg)
{
  
    return (MA_LexNatCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  MA_NatCon MA_setNatConNatCon(MA_NatCon arg, MA_LexNatCon NatCon) */

MA_NatCon MA_setNatConNatCon(MA_NatCon arg, MA_LexNatCon NatCon)
{
  if (MA_isNatConLexToCf(arg)) {
    return (MA_NatCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) NatCon), 0), 1);
  }

  ATabort("NatCon has no NatCon: %t\n", arg);
  return (MA_NatCon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_LexIdCon accessors */

/*{{{  ATbool MA_isValidLexIdCon(MA_LexIdCon arg) */

ATbool MA_isValidLexIdCon(MA_LexIdCon arg)
{
  if (MA_isLexIdConDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isLexIdConDefault(MA_LexIdCon arg) */

inline ATbool MA_isLexIdConDefault(MA_LexIdCon arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MA_patternLexIdConDefault, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool MA_hasLexIdConHead(MA_LexIdCon arg) */

ATbool MA_hasLexIdConHead(MA_LexIdCon arg)
{
  if (MA_isLexIdConDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool MA_hasLexIdConTail(MA_LexIdCon arg) */

ATbool MA_hasLexIdConTail(MA_LexIdCon arg)
{
  if (MA_isLexIdConDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char MA_getLexIdConHead(MA_LexIdCon arg) */

char MA_getLexIdConHead(MA_LexIdCon arg)
{
  
    return (char)MA_charToByte((ATerm)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  char* MA_getLexIdConTail(MA_LexIdCon arg) */

char* MA_getLexIdConTail(MA_LexIdCon arg)
{
  
    return (char*)MA_charsToString((ATerm)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1), 1));
}

/*}}}  */
/*{{{  MA_LexIdCon MA_setLexIdConHead(MA_LexIdCon arg, char head) */

MA_LexIdCon MA_setLexIdConHead(MA_LexIdCon arg, char head)
{
  if (MA_isLexIdConDefault(arg)) {
    return (MA_LexIdCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) MA_byteToChar(head))), 0), 1);
  }

  ATabort("LexIdCon has no Head: %t\n", arg);
  return (MA_LexIdCon)NULL;
}

/*}}}  */
/*{{{  MA_LexIdCon MA_setLexIdConTail(MA_LexIdCon arg, const char* tail) */

MA_LexIdCon MA_setLexIdConTail(MA_LexIdCon arg, const char* tail)
{
  if (MA_isLexIdConDefault(arg)) {
    return (MA_LexIdCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1), (ATerm)((ATerm) ((ATerm) MA_stringToChars(tail))), 1), 1), 1);
  }

  ATabort("LexIdCon has no Tail: %t\n", arg);
  return (MA_LexIdCon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  MA_IdCon accessors */

/*{{{  ATbool MA_isValidIdCon(MA_IdCon arg) */

ATbool MA_isValidIdCon(MA_IdCon arg)
{
  if (MA_isIdConLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool MA_isIdConLexToCf(MA_IdCon arg) */

inline ATbool MA_isIdConLexToCf(MA_IdCon arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, MA_patternIdConLexToCf, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool MA_hasIdConIdCon(MA_IdCon arg) */

ATbool MA_hasIdConIdCon(MA_IdCon arg)
{
  if (MA_isIdConLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  MA_LexIdCon MA_getIdConIdCon(MA_IdCon arg) */

MA_LexIdCon MA_getIdConIdCon(MA_IdCon arg)
{
  
    return (MA_LexIdCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  MA_IdCon MA_setIdConIdCon(MA_IdCon arg, MA_LexIdCon IdCon) */

MA_IdCon MA_setIdConIdCon(MA_IdCon arg, MA_LexIdCon IdCon)
{
  if (MA_isIdConLexToCf(arg)) {
    return (MA_IdCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) IdCon), 0), 1);
  }

  ATabort("IdCon has no IdCon: %t\n", arg);
  return (MA_IdCon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  MA_OptLayout MA_visitOptLayout(MA_OptLayout arg, MA_Layout (*acceptLayout)(MA_Layout)) */

MA_OptLayout MA_visitOptLayout(MA_OptLayout arg, MA_Layout (*acceptLayout)(MA_Layout))
{
  if (MA_isOptLayoutAbsent(arg)) {
    return MA_makeOptLayoutAbsent();
  }
  if (MA_isOptLayoutPresent(arg)) {
    return MA_makeOptLayoutPresent(
        acceptLayout ? acceptLayout(MA_getOptLayoutLayout(arg)) : MA_getOptLayoutLayout(arg));
  }
  ATabort("not a OptLayout: %t\n", arg);
  return (MA_OptLayout)NULL;
}

/*}}}  */
/*{{{  MA_Layout MA_visitLayout(MA_Layout arg, MA_LexLayoutList (*acceptList)(MA_LexLayoutList)) */

MA_Layout MA_visitLayout(MA_Layout arg, MA_LexLayoutList (*acceptList)(MA_LexLayoutList))
{
  if (MA_isLayoutLexToCf(arg)) {
    return MA_makeLayoutLexToCf(
        acceptList ? acceptList(MA_getLayoutList(arg)) : MA_getLayoutList(arg));
  }
  ATabort("not a Layout: %t\n", arg);
  return (MA_Layout)NULL;
}

/*}}}  */
/*{{{  MA_LexLayoutList MA_visitLexLayoutList(MA_LexLayoutList arg, MA_LexLayout (*acceptHead)(MA_LexLayout)) */

MA_LexLayoutList MA_visitLexLayoutList(MA_LexLayoutList arg, MA_LexLayout (*acceptHead)(MA_LexLayout))
{
  if (MA_isLexLayoutListEmpty(arg)) {
    return MA_makeLexLayoutListEmpty();
  }
  if (MA_isLexLayoutListSingle(arg)) {
    return MA_makeLexLayoutListSingle(
        acceptHead ? acceptHead(MA_getLexLayoutListHead(arg)) : MA_getLexLayoutListHead(arg));
  }
  if (MA_isLexLayoutListMany(arg)) {
    return MA_makeLexLayoutListMany(
        acceptHead ? acceptHead(MA_getLexLayoutListHead(arg)) : MA_getLexLayoutListHead(arg),
        MA_visitLexLayoutList(MA_getLexLayoutListTail(arg), acceptHead));
  }
  ATabort("not a LexLayoutList: %t\n", arg);
  return (MA_LexLayoutList)NULL;
}

/*}}}  */
/*{{{  MA_TraversalStrategy MA_visitTraversalStrategy(MA_TraversalStrategy arg) */

MA_TraversalStrategy MA_visitTraversalStrategy(MA_TraversalStrategy arg)
{
  if (MA_isTraversalStrategyBottomUp(arg)) {
    return MA_makeTraversalStrategyBottomUp();
  }
  if (MA_isTraversalStrategyTopDown(arg)) {
    return MA_makeTraversalStrategyTopDown();
  }
  ATabort("not a TraversalStrategy: %t\n", arg);
  return (MA_TraversalStrategy)NULL;
}

/*}}}  */
/*{{{  MA_TraversalType MA_visitTraversalType(MA_TraversalType arg) */

MA_TraversalType MA_visitTraversalType(MA_TraversalType arg)
{
  if (MA_isTraversalTypeTrafo(arg)) {
    return MA_makeTraversalTypeTrafo();
  }
  if (MA_isTraversalTypeAccu(arg)) {
    return MA_makeTraversalTypeAccu();
  }
  if (MA_isTraversalTypeAccutrafo(arg)) {
    return MA_makeTraversalTypeAccutrafo();
  }
  ATabort("not a TraversalType: %t\n", arg);
  return (MA_TraversalType)NULL;
}

/*}}}  */
/*{{{  MA_TraversalContinuation MA_visitTraversalContinuation(MA_TraversalContinuation arg) */

MA_TraversalContinuation MA_visitTraversalContinuation(MA_TraversalContinuation arg)
{
  if (MA_isTraversalContinuationBreak(arg)) {
    return MA_makeTraversalContinuationBreak();
  }
  if (MA_isTraversalContinuationContinue(arg)) {
    return MA_makeTraversalContinuationContinue();
  }
  ATabort("not a TraversalContinuation: %t\n", arg);
  return (MA_TraversalContinuation)NULL;
}

/*}}}  */
/*{{{  MA_FunId MA_visitFunId(MA_FunId arg, MA_NatCon (*acceptNatCon)(MA_NatCon), MA_IdCon (*acceptIdCon)(MA_IdCon), MA_StrCon (*acceptStrCon)(MA_StrCon), MA_OptLayout (*acceptWsAfterBracketOpen)(MA_OptLayout), MA_OptLayout (*acceptWsAfterFunId)(MA_OptLayout), MA_OptLayout (*acceptWsAfterBraceOpen)(MA_OptLayout), MA_OptLayout (*acceptWsAfterIGNORE)(MA_OptLayout), MA_OptLayout (*acceptWsAfterTRANSLATE)(MA_OptLayout), MA_OptLayout (*acceptWsAfterBar)(MA_OptLayout), MA_TraversalType (*acceptTraversalType)(MA_TraversalType), MA_OptLayout (*acceptWsAfterTraversalType)(MA_OptLayout), MA_TraversalStrategy (*acceptTraversalStrategy)(MA_TraversalStrategy), MA_OptLayout (*acceptWsAfterTraversalStrategy)(MA_OptLayout), MA_TraversalContinuation (*acceptTraversalContinuation)(MA_TraversalContinuation), MA_OptLayout (*acceptWsAfterTraversalContinuation)(MA_OptLayout), MA_OptLayout (*acceptWsAfterLhs)(MA_OptLayout), MA_OptLayout (*acceptWsAfterPlusPlus)(MA_OptLayout)) */

MA_FunId MA_visitFunId(MA_FunId arg, MA_NatCon (*acceptNatCon)(MA_NatCon), MA_IdCon (*acceptIdCon)(MA_IdCon), MA_StrCon (*acceptStrCon)(MA_StrCon), MA_OptLayout (*acceptWsAfterBracketOpen)(MA_OptLayout), MA_OptLayout (*acceptWsAfterFunId)(MA_OptLayout), MA_OptLayout (*acceptWsAfterBraceOpen)(MA_OptLayout), MA_OptLayout (*acceptWsAfterIGNORE)(MA_OptLayout), MA_OptLayout (*acceptWsAfterTRANSLATE)(MA_OptLayout), MA_OptLayout (*acceptWsAfterBar)(MA_OptLayout), MA_TraversalType (*acceptTraversalType)(MA_TraversalType), MA_OptLayout (*acceptWsAfterTraversalType)(MA_OptLayout), MA_TraversalStrategy (*acceptTraversalStrategy)(MA_TraversalStrategy), MA_OptLayout (*acceptWsAfterTraversalStrategy)(MA_OptLayout), MA_TraversalContinuation (*acceptTraversalContinuation)(MA_TraversalContinuation), MA_OptLayout (*acceptWsAfterTraversalContinuation)(MA_OptLayout), MA_OptLayout (*acceptWsAfterLhs)(MA_OptLayout), MA_OptLayout (*acceptWsAfterPlusPlus)(MA_OptLayout))
{
  if (MA_isFunIdCharacter(arg)) {
    return MA_makeFunIdCharacter(
        acceptNatCon ? acceptNatCon(MA_getFunIdNatCon(arg)) : MA_getFunIdNatCon(arg));
  }
  if (MA_isFunIdUnquoted(arg)) {
    return MA_makeFunIdUnquoted(
        acceptIdCon ? acceptIdCon(MA_getFunIdIdCon(arg)) : MA_getFunIdIdCon(arg));
  }
  if (MA_isFunIdQuoted(arg)) {
    return MA_makeFunIdQuoted(
        acceptStrCon ? acceptStrCon(MA_getFunIdStrCon(arg)) : MA_getFunIdStrCon(arg));
  }
  if (MA_isFunIdReturnsList(arg)) {
    return MA_makeFunIdReturnsList(
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(MA_getFunIdWsAfterBracketOpen(arg)) : MA_getFunIdWsAfterBracketOpen(arg),
        MA_visitFunId(MA_getFunIdFunId(arg), acceptNatCon, acceptIdCon, acceptStrCon, acceptWsAfterBracketOpen, acceptWsAfterFunId, acceptWsAfterBraceOpen, acceptWsAfterIGNORE, acceptWsAfterTRANSLATE, acceptWsAfterBar, acceptTraversalType, acceptWsAfterTraversalType, acceptTraversalStrategy, acceptWsAfterTraversalStrategy, acceptTraversalContinuation, acceptWsAfterTraversalContinuation, acceptWsAfterLhs, acceptWsAfterPlusPlus),
        acceptWsAfterFunId ? acceptWsAfterFunId(MA_getFunIdWsAfterFunId(arg)) : MA_getFunIdWsAfterFunId(arg));
  }
  if (MA_isFunIdList(arg)) {
    return MA_makeFunIdList(
        acceptWsAfterBraceOpen ? acceptWsAfterBraceOpen(MA_getFunIdWsAfterBraceOpen(arg)) : MA_getFunIdWsAfterBraceOpen(arg),
        MA_visitFunId(MA_getFunIdFunId(arg), acceptNatCon, acceptIdCon, acceptStrCon, acceptWsAfterBracketOpen, acceptWsAfterFunId, acceptWsAfterBraceOpen, acceptWsAfterIGNORE, acceptWsAfterTRANSLATE, acceptWsAfterBar, acceptTraversalType, acceptWsAfterTraversalType, acceptTraversalStrategy, acceptWsAfterTraversalStrategy, acceptTraversalContinuation, acceptWsAfterTraversalContinuation, acceptWsAfterLhs, acceptWsAfterPlusPlus),
        acceptWsAfterFunId ? acceptWsAfterFunId(MA_getFunIdWsAfterFunId(arg)) : MA_getFunIdWsAfterFunId(arg));
  }
  if (MA_isFunIdIgnored(arg)) {
    return MA_makeFunIdIgnored(
        acceptWsAfterIGNORE ? acceptWsAfterIGNORE(MA_getFunIdWsAfterIGNORE(arg)) : MA_getFunIdWsAfterIGNORE(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(MA_getFunIdWsAfterBracketOpen(arg)) : MA_getFunIdWsAfterBracketOpen(arg),
        MA_visitFunId(MA_getFunIdFunId(arg), acceptNatCon, acceptIdCon, acceptStrCon, acceptWsAfterBracketOpen, acceptWsAfterFunId, acceptWsAfterBraceOpen, acceptWsAfterIGNORE, acceptWsAfterTRANSLATE, acceptWsAfterBar, acceptTraversalType, acceptWsAfterTraversalType, acceptTraversalStrategy, acceptWsAfterTraversalStrategy, acceptTraversalContinuation, acceptWsAfterTraversalContinuation, acceptWsAfterLhs, acceptWsAfterPlusPlus),
        acceptWsAfterFunId ? acceptWsAfterFunId(MA_getFunIdWsAfterFunId(arg)) : MA_getFunIdWsAfterFunId(arg));
  }
  if (MA_isFunIdTranslate(arg)) {
    return MA_makeFunIdTranslate(
        acceptWsAfterTRANSLATE ? acceptWsAfterTRANSLATE(MA_getFunIdWsAfterTRANSLATE(arg)) : MA_getFunIdWsAfterTRANSLATE(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(MA_getFunIdWsAfterBracketOpen(arg)) : MA_getFunIdWsAfterBracketOpen(arg),
        MA_visitFunId(MA_getFunIdFunId(arg), acceptNatCon, acceptIdCon, acceptStrCon, acceptWsAfterBracketOpen, acceptWsAfterFunId, acceptWsAfterBraceOpen, acceptWsAfterIGNORE, acceptWsAfterTRANSLATE, acceptWsAfterBar, acceptTraversalType, acceptWsAfterTraversalType, acceptTraversalStrategy, acceptWsAfterTraversalStrategy, acceptTraversalContinuation, acceptWsAfterTraversalContinuation, acceptWsAfterLhs, acceptWsAfterPlusPlus),
        acceptWsAfterFunId ? acceptWsAfterFunId(MA_getFunIdWsAfterFunId(arg)) : MA_getFunIdWsAfterFunId(arg));
  }
  if (MA_isFunIdTraversal(arg)) {
    return MA_makeFunIdTraversal(
        acceptWsAfterBar ? acceptWsAfterBar(MA_getFunIdWsAfterBar(arg)) : MA_getFunIdWsAfterBar(arg),
        MA_visitFunId(MA_getFunIdFunId(arg), acceptNatCon, acceptIdCon, acceptStrCon, acceptWsAfterBracketOpen, acceptWsAfterFunId, acceptWsAfterBraceOpen, acceptWsAfterIGNORE, acceptWsAfterTRANSLATE, acceptWsAfterBar, acceptTraversalType, acceptWsAfterTraversalType, acceptTraversalStrategy, acceptWsAfterTraversalStrategy, acceptTraversalContinuation, acceptWsAfterTraversalContinuation, acceptWsAfterLhs, acceptWsAfterPlusPlus),
        acceptWsAfterFunId ? acceptWsAfterFunId(MA_getFunIdWsAfterFunId(arg)) : MA_getFunIdWsAfterFunId(arg),
        acceptTraversalType ? acceptTraversalType(MA_getFunIdTraversalType(arg)) : MA_getFunIdTraversalType(arg),
        acceptWsAfterTraversalType ? acceptWsAfterTraversalType(MA_getFunIdWsAfterTraversalType(arg)) : MA_getFunIdWsAfterTraversalType(arg),
        acceptTraversalStrategy ? acceptTraversalStrategy(MA_getFunIdTraversalStrategy(arg)) : MA_getFunIdTraversalStrategy(arg),
        acceptWsAfterTraversalStrategy ? acceptWsAfterTraversalStrategy(MA_getFunIdWsAfterTraversalStrategy(arg)) : MA_getFunIdWsAfterTraversalStrategy(arg),
        acceptTraversalContinuation ? acceptTraversalContinuation(MA_getFunIdTraversalContinuation(arg)) : MA_getFunIdTraversalContinuation(arg),
        acceptWsAfterTraversalContinuation ? acceptWsAfterTraversalContinuation(MA_getFunIdWsAfterTraversalContinuation(arg)) : MA_getFunIdWsAfterTraversalContinuation(arg));
  }
  if (MA_isFunIdConcat(arg)) {
    return MA_makeFunIdConcat(
        MA_visitFunId(MA_getFunIdLhs(arg), acceptNatCon, acceptIdCon, acceptStrCon, acceptWsAfterBracketOpen, acceptWsAfterFunId, acceptWsAfterBraceOpen, acceptWsAfterIGNORE, acceptWsAfterTRANSLATE, acceptWsAfterBar, acceptTraversalType, acceptWsAfterTraversalType, acceptTraversalStrategy, acceptWsAfterTraversalStrategy, acceptTraversalContinuation, acceptWsAfterTraversalContinuation, acceptWsAfterLhs, acceptWsAfterPlusPlus),
        acceptWsAfterLhs ? acceptWsAfterLhs(MA_getFunIdWsAfterLhs(arg)) : MA_getFunIdWsAfterLhs(arg),
        acceptWsAfterPlusPlus ? acceptWsAfterPlusPlus(MA_getFunIdWsAfterPlusPlus(arg)) : MA_getFunIdWsAfterPlusPlus(arg),
        MA_visitFunId(MA_getFunIdRhs(arg), acceptNatCon, acceptIdCon, acceptStrCon, acceptWsAfterBracketOpen, acceptWsAfterFunId, acceptWsAfterBraceOpen, acceptWsAfterIGNORE, acceptWsAfterTRANSLATE, acceptWsAfterBar, acceptTraversalType, acceptWsAfterTraversalType, acceptTraversalStrategy, acceptWsAfterTraversalStrategy, acceptTraversalContinuation, acceptWsAfterTraversalContinuation, acceptWsAfterLhs, acceptWsAfterPlusPlus));
  }
  ATabort("not a FunId: %t\n", arg);
  return (MA_FunId)NULL;
}

/*}}}  */
/*{{{  MA_VarId MA_visitVarId(MA_VarId arg, MA_OptLayout (*acceptWsAfterDollar)(MA_OptLayout), MA_FunId (*acceptFunId)(MA_FunId), MA_OptLayout (*acceptWsAfterDollarPlus)(MA_OptLayout), MA_OptLayout (*acceptWsAfterDollarStar)(MA_OptLayout)) */

MA_VarId MA_visitVarId(MA_VarId arg, MA_OptLayout (*acceptWsAfterDollar)(MA_OptLayout), MA_FunId (*acceptFunId)(MA_FunId), MA_OptLayout (*acceptWsAfterDollarPlus)(MA_OptLayout), MA_OptLayout (*acceptWsAfterDollarStar)(MA_OptLayout))
{
  if (MA_isVarIdNormal(arg)) {
    return MA_makeVarIdNormal(
        acceptWsAfterDollar ? acceptWsAfterDollar(MA_getVarIdWsAfterDollar(arg)) : MA_getVarIdWsAfterDollar(arg),
        acceptFunId ? acceptFunId(MA_getVarIdFunId(arg)) : MA_getVarIdFunId(arg));
  }
  if (MA_isVarIdPlus(arg)) {
    return MA_makeVarIdPlus(
        acceptWsAfterDollarPlus ? acceptWsAfterDollarPlus(MA_getVarIdWsAfterDollarPlus(arg)) : MA_getVarIdWsAfterDollarPlus(arg),
        acceptFunId ? acceptFunId(MA_getVarIdFunId(arg)) : MA_getVarIdFunId(arg));
  }
  if (MA_isVarIdStar(arg)) {
    return MA_makeVarIdStar(
        acceptWsAfterDollarStar ? acceptWsAfterDollarStar(MA_getVarIdWsAfterDollarStar(arg)) : MA_getVarIdWsAfterDollarStar(arg),
        acceptFunId ? acceptFunId(MA_getVarIdFunId(arg)) : MA_getVarIdFunId(arg));
  }
  ATabort("not a VarId: %t\n", arg);
  return (MA_VarId)NULL;
}

/*}}}  */
/*{{{  MA_ModId MA_visitModId(MA_ModId arg, MA_IdCon (*acceptIdCon)(MA_IdCon)) */

MA_ModId MA_visitModId(MA_ModId arg, MA_IdCon (*acceptIdCon)(MA_IdCon))
{
  if (MA_isModIdDefault(arg)) {
    return MA_makeModIdDefault(
        acceptIdCon ? acceptIdCon(MA_getModIdIdCon(arg)) : MA_getModIdIdCon(arg));
  }
  ATabort("not a ModId: %t\n", arg);
  return (MA_ModId)NULL;
}

/*}}}  */
/*{{{  MA_Term MA_visitTerm(MA_Term arg, MA_VarId (*acceptVarId)(MA_VarId), MA_FunId (*acceptFunId)(MA_FunId), MA_OptLayout (*acceptWsAfterFunId)(MA_OptLayout), MA_OptLayout (*acceptWsAfterParenOpen)(MA_OptLayout), MA_TermArgs (*acceptArgs)(MA_TermArgs), MA_OptLayout (*acceptWsAfterArgs)(MA_OptLayout), MA_OptLayout (*acceptWsAfterBracketOpen)(MA_OptLayout), MA_TermList (*acceptTermList)(MA_TermList), MA_OptLayout (*acceptWsAfterTermList)(MA_OptLayout), MA_OptLayout (*acceptWsAfterTerm)(MA_OptLayout), MA_OptLayout (*acceptWsAfterColon)(MA_OptLayout)) */

MA_Term MA_visitTerm(MA_Term arg, MA_VarId (*acceptVarId)(MA_VarId), MA_FunId (*acceptFunId)(MA_FunId), MA_OptLayout (*acceptWsAfterFunId)(MA_OptLayout), MA_OptLayout (*acceptWsAfterParenOpen)(MA_OptLayout), MA_TermArgs (*acceptArgs)(MA_TermArgs), MA_OptLayout (*acceptWsAfterArgs)(MA_OptLayout), MA_OptLayout (*acceptWsAfterBracketOpen)(MA_OptLayout), MA_TermList (*acceptTermList)(MA_TermList), MA_OptLayout (*acceptWsAfterTermList)(MA_OptLayout), MA_OptLayout (*acceptWsAfterTerm)(MA_OptLayout), MA_OptLayout (*acceptWsAfterColon)(MA_OptLayout))
{
  if (MA_isTermVar(arg)) {
    return MA_makeTermVar(
        acceptVarId ? acceptVarId(MA_getTermVarId(arg)) : MA_getTermVarId(arg));
  }
  if (MA_isTermConstant(arg)) {
    return MA_makeTermConstant(
        acceptFunId ? acceptFunId(MA_getTermFunId(arg)) : MA_getTermFunId(arg));
  }
  if (MA_isTermFunc(arg)) {
    return MA_makeTermFunc(
        acceptFunId ? acceptFunId(MA_getTermFunId(arg)) : MA_getTermFunId(arg),
        acceptWsAfterFunId ? acceptWsAfterFunId(MA_getTermWsAfterFunId(arg)) : MA_getTermWsAfterFunId(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(MA_getTermWsAfterParenOpen(arg)) : MA_getTermWsAfterParenOpen(arg),
        acceptArgs ? acceptArgs(MA_getTermArgs(arg)) : MA_getTermArgs(arg),
        acceptWsAfterArgs ? acceptWsAfterArgs(MA_getTermWsAfterArgs(arg)) : MA_getTermWsAfterArgs(arg));
  }
  if (MA_isTermList(arg)) {
    return MA_makeTermList(
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(MA_getTermWsAfterBracketOpen(arg)) : MA_getTermWsAfterBracketOpen(arg),
        acceptTermList ? acceptTermList(MA_getTermTermList(arg)) : MA_getTermTermList(arg),
        acceptWsAfterTermList ? acceptWsAfterTermList(MA_getTermWsAfterTermList(arg)) : MA_getTermWsAfterTermList(arg));
  }
  if (MA_isTermTyped(arg)) {
    return MA_makeTermTyped(
        MA_visitTerm(MA_getTermTerm(arg), acceptVarId, acceptFunId, acceptWsAfterFunId, acceptWsAfterParenOpen, acceptArgs, acceptWsAfterArgs, acceptWsAfterBracketOpen, acceptTermList, acceptWsAfterTermList, acceptWsAfterTerm, acceptWsAfterColon),
        acceptWsAfterTerm ? acceptWsAfterTerm(MA_getTermWsAfterTerm(arg)) : MA_getTermWsAfterTerm(arg),
        acceptWsAfterColon ? acceptWsAfterColon(MA_getTermWsAfterColon(arg)) : MA_getTermWsAfterColon(arg),
        MA_visitTerm(MA_getTermType(arg), acceptVarId, acceptFunId, acceptWsAfterFunId, acceptWsAfterParenOpen, acceptArgs, acceptWsAfterArgs, acceptWsAfterBracketOpen, acceptTermList, acceptWsAfterTermList, acceptWsAfterTerm, acceptWsAfterColon));
  }
  ATabort("not a Term: %t\n", arg);
  return (MA_Term)NULL;
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
/*{{{  MA_SigArg MA_visitSigArg(MA_SigArg arg, MA_OptLayout (*acceptWsAfterUnderscore)(MA_OptLayout)) */

MA_SigArg MA_visitSigArg(MA_SigArg arg, MA_OptLayout (*acceptWsAfterUnderscore)(MA_OptLayout))
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
/*{{{  MA_FuncDef MA_visitFuncDef(MA_FuncDef arg, MA_FunId (*acceptFunId)(MA_FunId), MA_OptLayout (*acceptWsAfterFunId)(MA_OptLayout), MA_Annotations (*acceptAnnotations)(MA_Annotations), MA_OptLayout (*acceptWsAfterParenOpen)(MA_OptLayout), MA_SigArgArgs (*acceptArgs)(MA_SigArgArgs), MA_OptLayout (*acceptWsAfterArgs)(MA_OptLayout), MA_OptLayout (*acceptWsAfterParenClose)(MA_OptLayout)) */

MA_FuncDef MA_visitFuncDef(MA_FuncDef arg, MA_FunId (*acceptFunId)(MA_FunId), MA_OptLayout (*acceptWsAfterFunId)(MA_OptLayout), MA_Annotations (*acceptAnnotations)(MA_Annotations), MA_OptLayout (*acceptWsAfterParenOpen)(MA_OptLayout), MA_SigArgArgs (*acceptArgs)(MA_SigArgArgs), MA_OptLayout (*acceptWsAfterArgs)(MA_OptLayout), MA_OptLayout (*acceptWsAfterParenClose)(MA_OptLayout))
{
  if (MA_isFuncDefConstantNoAnnos(arg)) {
    return MA_makeFuncDefConstantNoAnnos(
        acceptFunId ? acceptFunId(MA_getFuncDefFunId(arg)) : MA_getFuncDefFunId(arg));
  }
  if (MA_isFuncDefConstantWithAnnos(arg)) {
    return MA_makeFuncDefConstantWithAnnos(
        acceptFunId ? acceptFunId(MA_getFuncDefFunId(arg)) : MA_getFuncDefFunId(arg),
        acceptWsAfterFunId ? acceptWsAfterFunId(MA_getFuncDefWsAfterFunId(arg)) : MA_getFuncDefWsAfterFunId(arg),
        acceptAnnotations ? acceptAnnotations(MA_getFuncDefAnnotations(arg)) : MA_getFuncDefAnnotations(arg));
  }
  if (MA_isFuncDefFuncNoAnnos(arg)) {
    return MA_makeFuncDefFuncNoAnnos(
        acceptFunId ? acceptFunId(MA_getFuncDefFunId(arg)) : MA_getFuncDefFunId(arg),
        acceptWsAfterFunId ? acceptWsAfterFunId(MA_getFuncDefWsAfterFunId(arg)) : MA_getFuncDefWsAfterFunId(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(MA_getFuncDefWsAfterParenOpen(arg)) : MA_getFuncDefWsAfterParenOpen(arg),
        acceptArgs ? acceptArgs(MA_getFuncDefArgs(arg)) : MA_getFuncDefArgs(arg),
        acceptWsAfterArgs ? acceptWsAfterArgs(MA_getFuncDefWsAfterArgs(arg)) : MA_getFuncDefWsAfterArgs(arg));
  }
  if (MA_isFuncDefFuncWithAnnos(arg)) {
    return MA_makeFuncDefFuncWithAnnos(
        acceptFunId ? acceptFunId(MA_getFuncDefFunId(arg)) : MA_getFuncDefFunId(arg),
        acceptWsAfterFunId ? acceptWsAfterFunId(MA_getFuncDefWsAfterFunId(arg)) : MA_getFuncDefWsAfterFunId(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(MA_getFuncDefWsAfterParenOpen(arg)) : MA_getFuncDefWsAfterParenOpen(arg),
        acceptArgs ? acceptArgs(MA_getFuncDefArgs(arg)) : MA_getFuncDefArgs(arg),
        acceptWsAfterArgs ? acceptWsAfterArgs(MA_getFuncDefWsAfterArgs(arg)) : MA_getFuncDefWsAfterArgs(arg),
        acceptWsAfterParenClose ? acceptWsAfterParenClose(MA_getFuncDefWsAfterParenClose(arg)) : MA_getFuncDefWsAfterParenClose(arg),
        acceptAnnotations ? acceptAnnotations(MA_getFuncDefAnnotations(arg)) : MA_getFuncDefAnnotations(arg));
  }
  ATabort("not a FuncDef: %t\n", arg);
  return (MA_FuncDef)NULL;
}

/*}}}  */
/*{{{  MA_Annotations MA_visitAnnotations(MA_Annotations arg, MA_OptLayout (*acceptWsAfterBraceOpen)(MA_OptLayout), MA_TermAttrs (*acceptAttrs)(MA_TermAttrs), MA_OptLayout (*acceptWsAfterAttrs)(MA_OptLayout)) */

MA_Annotations MA_visitAnnotations(MA_Annotations arg, MA_OptLayout (*acceptWsAfterBraceOpen)(MA_OptLayout), MA_TermAttrs (*acceptAttrs)(MA_TermAttrs), MA_OptLayout (*acceptWsAfterAttrs)(MA_OptLayout))
{
  if (MA_isAnnotationsDefault(arg)) {
    return MA_makeAnnotationsDefault(
        acceptWsAfterBraceOpen ? acceptWsAfterBraceOpen(MA_getAnnotationsWsAfterBraceOpen(arg)) : MA_getAnnotationsWsAfterBraceOpen(arg),
        acceptAttrs ? acceptAttrs(MA_getAnnotationsAttrs(arg)) : MA_getAnnotationsAttrs(arg),
        acceptWsAfterAttrs ? acceptWsAfterAttrs(MA_getAnnotationsWsAfterAttrs(arg)) : MA_getAnnotationsWsAfterAttrs(arg));
  }
  ATabort("not a Annotations: %t\n", arg);
  return (MA_Annotations)NULL;
}

/*}}}  */
/*{{{  MA_SigArgList MA_visitSigArgList(MA_SigArgList arg, MA_SigArgArgs (*acceptArgs)(MA_SigArgArgs)) */

MA_SigArgList MA_visitSigArgList(MA_SigArgList arg, MA_SigArgArgs (*acceptArgs)(MA_SigArgArgs))
{
  if (MA_isSigArgListDefault(arg)) {
    return MA_makeSigArgListDefault(
        acceptArgs ? acceptArgs(MA_getSigArgListArgs(arg)) : MA_getSigArgListArgs(arg));
  }
  ATabort("not a SigArgList: %t\n", arg);
  return (MA_SigArgList)NULL;
}

/*}}}  */
/*{{{  MA_FuncDefList MA_visitFuncDefList(MA_FuncDefList arg, MA_FuncDefDefs (*acceptDefs)(MA_FuncDefDefs)) */

MA_FuncDefList MA_visitFuncDefList(MA_FuncDefList arg, MA_FuncDefDefs (*acceptDefs)(MA_FuncDefDefs))
{
  if (MA_isFuncDefListDefault(arg)) {
    return MA_makeFuncDefListDefault(
        acceptDefs ? acceptDefs(MA_getFuncDefListDefs(arg)) : MA_getFuncDefListDefs(arg));
  }
  ATabort("not a FuncDefList: %t\n", arg);
  return (MA_FuncDefList)NULL;
}

/*}}}  */
/*{{{  MA_Rule MA_visitRule(MA_Rule arg, MA_Term (*acceptLhs)(MA_Term), MA_OptLayout (*acceptWsAfterLhs)(MA_OptLayout), MA_OptLayout (*acceptWsAfterIs)(MA_OptLayout), MA_Term (*acceptRhs)(MA_Term), MA_OptLayout (*acceptWsAfterDefaultColon)(MA_OptLayout), MA_CondList (*acceptConds)(MA_CondList), MA_OptLayout (*acceptWsAfterConds)(MA_OptLayout), MA_OptLayout (*acceptWsAfterEqualsEqualsGreaterThan)(MA_OptLayout)) */

MA_Rule MA_visitRule(MA_Rule arg, MA_Term (*acceptLhs)(MA_Term), MA_OptLayout (*acceptWsAfterLhs)(MA_OptLayout), MA_OptLayout (*acceptWsAfterIs)(MA_OptLayout), MA_Term (*acceptRhs)(MA_Term), MA_OptLayout (*acceptWsAfterDefaultColon)(MA_OptLayout), MA_CondList (*acceptConds)(MA_CondList), MA_OptLayout (*acceptWsAfterConds)(MA_OptLayout), MA_OptLayout (*acceptWsAfterEqualsEqualsGreaterThan)(MA_OptLayout))
{
  if (MA_isRuleNoConds(arg)) {
    return MA_makeRuleNoConds(
        acceptLhs ? acceptLhs(MA_getRuleLhs(arg)) : MA_getRuleLhs(arg),
        acceptWsAfterLhs ? acceptWsAfterLhs(MA_getRuleWsAfterLhs(arg)) : MA_getRuleWsAfterLhs(arg),
        acceptWsAfterIs ? acceptWsAfterIs(MA_getRuleWsAfterIs(arg)) : MA_getRuleWsAfterIs(arg),
        acceptRhs ? acceptRhs(MA_getRuleRhs(arg)) : MA_getRuleRhs(arg));
  }
  if (MA_isRuleDefaultNoConds(arg)) {
    return MA_makeRuleDefaultNoConds(
        acceptWsAfterDefaultColon ? acceptWsAfterDefaultColon(MA_getRuleWsAfterDefaultColon(arg)) : MA_getRuleWsAfterDefaultColon(arg),
        acceptLhs ? acceptLhs(MA_getRuleLhs(arg)) : MA_getRuleLhs(arg),
        acceptWsAfterLhs ? acceptWsAfterLhs(MA_getRuleWsAfterLhs(arg)) : MA_getRuleWsAfterLhs(arg),
        acceptWsAfterIs ? acceptWsAfterIs(MA_getRuleWsAfterIs(arg)) : MA_getRuleWsAfterIs(arg),
        acceptRhs ? acceptRhs(MA_getRuleRhs(arg)) : MA_getRuleRhs(arg));
  }
  if (MA_isRuleWithConds(arg)) {
    return MA_makeRuleWithConds(
        acceptConds ? acceptConds(MA_getRuleConds(arg)) : MA_getRuleConds(arg),
        acceptWsAfterConds ? acceptWsAfterConds(MA_getRuleWsAfterConds(arg)) : MA_getRuleWsAfterConds(arg),
        acceptWsAfterEqualsEqualsGreaterThan ? acceptWsAfterEqualsEqualsGreaterThan(MA_getRuleWsAfterEqualsEqualsGreaterThan(arg)) : MA_getRuleWsAfterEqualsEqualsGreaterThan(arg),
        acceptLhs ? acceptLhs(MA_getRuleLhs(arg)) : MA_getRuleLhs(arg),
        acceptWsAfterLhs ? acceptWsAfterLhs(MA_getRuleWsAfterLhs(arg)) : MA_getRuleWsAfterLhs(arg),
        acceptWsAfterIs ? acceptWsAfterIs(MA_getRuleWsAfterIs(arg)) : MA_getRuleWsAfterIs(arg),
        acceptRhs ? acceptRhs(MA_getRuleRhs(arg)) : MA_getRuleRhs(arg));
  }
  if (MA_isRuleDefaultWithConds(arg)) {
    return MA_makeRuleDefaultWithConds(
        acceptWsAfterDefaultColon ? acceptWsAfterDefaultColon(MA_getRuleWsAfterDefaultColon(arg)) : MA_getRuleWsAfterDefaultColon(arg),
        acceptConds ? acceptConds(MA_getRuleConds(arg)) : MA_getRuleConds(arg),
        acceptWsAfterConds ? acceptWsAfterConds(MA_getRuleWsAfterConds(arg)) : MA_getRuleWsAfterConds(arg),
        acceptWsAfterEqualsEqualsGreaterThan ? acceptWsAfterEqualsEqualsGreaterThan(MA_getRuleWsAfterEqualsEqualsGreaterThan(arg)) : MA_getRuleWsAfterEqualsEqualsGreaterThan(arg),
        acceptLhs ? acceptLhs(MA_getRuleLhs(arg)) : MA_getRuleLhs(arg),
        acceptWsAfterLhs ? acceptWsAfterLhs(MA_getRuleWsAfterLhs(arg)) : MA_getRuleWsAfterLhs(arg),
        acceptWsAfterIs ? acceptWsAfterIs(MA_getRuleWsAfterIs(arg)) : MA_getRuleWsAfterIs(arg),
        acceptRhs ? acceptRhs(MA_getRuleRhs(arg)) : MA_getRuleRhs(arg));
  }
  ATabort("not a Rule: %t\n", arg);
  return (MA_Rule)NULL;
}

/*}}}  */
/*{{{  MA_RuleList MA_visitRuleList(MA_RuleList arg, MA_RuleRules (*acceptRules)(MA_RuleRules)) */

MA_RuleList MA_visitRuleList(MA_RuleList arg, MA_RuleRules (*acceptRules)(MA_RuleRules))
{
  if (MA_isRuleListDefault(arg)) {
    return MA_makeRuleListDefault(
        acceptRules ? acceptRules(MA_getRuleListRules(arg)) : MA_getRuleListRules(arg));
  }
  ATabort("not a RuleList: %t\n", arg);
  return (MA_RuleList)NULL;
}

/*}}}  */
/*{{{  MA_CondList MA_visitCondList(MA_CondList arg, MA_CondConds (*acceptConds)(MA_CondConds)) */

MA_CondList MA_visitCondList(MA_CondList arg, MA_CondConds (*acceptConds)(MA_CondConds))
{
  if (MA_isCondListDefault(arg)) {
    return MA_makeCondListDefault(
        acceptConds ? acceptConds(MA_getCondListConds(arg)) : MA_getCondListConds(arg));
  }
  ATabort("not a CondList: %t\n", arg);
  return (MA_CondList)NULL;
}

/*}}}  */
/*{{{  MA_Cond MA_visitCond(MA_Cond arg, MA_Term (*acceptLhs)(MA_Term), MA_OptLayout (*acceptWsAfterLhs)(MA_OptLayout), MA_OptLayout (*acceptWsAfterBecomes)(MA_OptLayout), MA_Term (*acceptRhs)(MA_Term), MA_OptLayout (*acceptWsAfterNotBecomes)(MA_OptLayout), MA_OptLayout (*acceptWsAfterEquals)(MA_OptLayout), MA_OptLayout (*acceptWsAfterNotEquals)(MA_OptLayout)) */

MA_Cond MA_visitCond(MA_Cond arg, MA_Term (*acceptLhs)(MA_Term), MA_OptLayout (*acceptWsAfterLhs)(MA_OptLayout), MA_OptLayout (*acceptWsAfterBecomes)(MA_OptLayout), MA_Term (*acceptRhs)(MA_Term), MA_OptLayout (*acceptWsAfterNotBecomes)(MA_OptLayout), MA_OptLayout (*acceptWsAfterEquals)(MA_OptLayout), MA_OptLayout (*acceptWsAfterNotEquals)(MA_OptLayout))
{
  if (MA_isCondAssign(arg)) {
    return MA_makeCondAssign(
        acceptLhs ? acceptLhs(MA_getCondLhs(arg)) : MA_getCondLhs(arg),
        acceptWsAfterLhs ? acceptWsAfterLhs(MA_getCondWsAfterLhs(arg)) : MA_getCondWsAfterLhs(arg),
        acceptWsAfterBecomes ? acceptWsAfterBecomes(MA_getCondWsAfterBecomes(arg)) : MA_getCondWsAfterBecomes(arg),
        acceptRhs ? acceptRhs(MA_getCondRhs(arg)) : MA_getCondRhs(arg));
  }
  if (MA_isCondNoAssign(arg)) {
    return MA_makeCondNoAssign(
        acceptLhs ? acceptLhs(MA_getCondLhs(arg)) : MA_getCondLhs(arg),
        acceptWsAfterLhs ? acceptWsAfterLhs(MA_getCondWsAfterLhs(arg)) : MA_getCondWsAfterLhs(arg),
        acceptWsAfterNotBecomes ? acceptWsAfterNotBecomes(MA_getCondWsAfterNotBecomes(arg)) : MA_getCondWsAfterNotBecomes(arg),
        acceptRhs ? acceptRhs(MA_getCondRhs(arg)) : MA_getCondRhs(arg));
  }
  if (MA_isCondEqual(arg)) {
    return MA_makeCondEqual(
        acceptLhs ? acceptLhs(MA_getCondLhs(arg)) : MA_getCondLhs(arg),
        acceptWsAfterLhs ? acceptWsAfterLhs(MA_getCondWsAfterLhs(arg)) : MA_getCondWsAfterLhs(arg),
        acceptWsAfterEquals ? acceptWsAfterEquals(MA_getCondWsAfterEquals(arg)) : MA_getCondWsAfterEquals(arg),
        acceptRhs ? acceptRhs(MA_getCondRhs(arg)) : MA_getCondRhs(arg));
  }
  if (MA_isCondUnequal(arg)) {
    return MA_makeCondUnequal(
        acceptLhs ? acceptLhs(MA_getCondLhs(arg)) : MA_getCondLhs(arg),
        acceptWsAfterLhs ? acceptWsAfterLhs(MA_getCondWsAfterLhs(arg)) : MA_getCondWsAfterLhs(arg),
        acceptWsAfterNotEquals ? acceptWsAfterNotEquals(MA_getCondWsAfterNotEquals(arg)) : MA_getCondWsAfterNotEquals(arg),
        acceptRhs ? acceptRhs(MA_getCondRhs(arg)) : MA_getCondRhs(arg));
  }
  ATabort("not a Cond: %t\n", arg);
  return (MA_Cond)NULL;
}

/*}}}  */
/*{{{  MA_SignatureOpt MA_visitSignatureOpt(MA_SignatureOpt arg, MA_OptLayout (*acceptWsAfterSignature)(MA_OptLayout), MA_FuncDefList (*acceptFuncDefList)(MA_FuncDefList)) */

MA_SignatureOpt MA_visitSignatureOpt(MA_SignatureOpt arg, MA_OptLayout (*acceptWsAfterSignature)(MA_OptLayout), MA_FuncDefList (*acceptFuncDefList)(MA_FuncDefList))
{
  if (MA_isSignatureOptAbsent(arg)) {
    return MA_makeSignatureOptAbsent();
  }
  if (MA_isSignatureOptPresent(arg)) {
    return MA_makeSignatureOptPresent(
        acceptWsAfterSignature ? acceptWsAfterSignature(MA_getSignatureOptWsAfterSignature(arg)) : MA_getSignatureOptWsAfterSignature(arg),
        acceptFuncDefList ? acceptFuncDefList(MA_getSignatureOptFuncDefList(arg)) : MA_getSignatureOptFuncDefList(arg));
  }
  ATabort("not a SignatureOpt: %t\n", arg);
  return (MA_SignatureOpt)NULL;
}

/*}}}  */
/*{{{  MA_RulesOpt MA_visitRulesOpt(MA_RulesOpt arg, MA_OptLayout (*acceptWsAfterRules)(MA_OptLayout), MA_RuleList (*acceptRuleList)(MA_RuleList)) */

MA_RulesOpt MA_visitRulesOpt(MA_RulesOpt arg, MA_OptLayout (*acceptWsAfterRules)(MA_OptLayout), MA_RuleList (*acceptRuleList)(MA_RuleList))
{
  if (MA_isRulesOptAbsent(arg)) {
    return MA_makeRulesOptAbsent();
  }
  if (MA_isRulesOptPresent(arg)) {
    return MA_makeRulesOptPresent(
        acceptWsAfterRules ? acceptWsAfterRules(MA_getRulesOptWsAfterRules(arg)) : MA_getRulesOptWsAfterRules(arg),
        acceptRuleList ? acceptRuleList(MA_getRulesOptRuleList(arg)) : MA_getRulesOptRuleList(arg));
  }
  ATabort("not a RulesOpt: %t\n", arg);
  return (MA_RulesOpt)NULL;
}

/*}}}  */
/*{{{  MA_Module MA_visitModule(MA_Module arg, MA_OptLayout (*acceptWsAfterModule)(MA_OptLayout), MA_ModId (*acceptModId)(MA_ModId), MA_OptLayout (*acceptWsAfterModId)(MA_OptLayout), MA_SignatureOpt (*acceptSignatureOpt)(MA_SignatureOpt), MA_OptLayout (*acceptWsAfterSignatureOpt)(MA_OptLayout), MA_RulesOpt (*acceptRulesOpt)(MA_RulesOpt)) */

MA_Module MA_visitModule(MA_Module arg, MA_OptLayout (*acceptWsAfterModule)(MA_OptLayout), MA_ModId (*acceptModId)(MA_ModId), MA_OptLayout (*acceptWsAfterModId)(MA_OptLayout), MA_SignatureOpt (*acceptSignatureOpt)(MA_SignatureOpt), MA_OptLayout (*acceptWsAfterSignatureOpt)(MA_OptLayout), MA_RulesOpt (*acceptRulesOpt)(MA_RulesOpt))
{
  if (MA_isModuleModule(arg)) {
    return MA_makeModuleModule(
        acceptWsAfterModule ? acceptWsAfterModule(MA_getModuleWsAfterModule(arg)) : MA_getModuleWsAfterModule(arg),
        acceptModId ? acceptModId(MA_getModuleModId(arg)) : MA_getModuleModId(arg),
        acceptWsAfterModId ? acceptWsAfterModId(MA_getModuleWsAfterModId(arg)) : MA_getModuleWsAfterModId(arg),
        acceptSignatureOpt ? acceptSignatureOpt(MA_getModuleSignatureOpt(arg)) : MA_getModuleSignatureOpt(arg),
        acceptWsAfterSignatureOpt ? acceptWsAfterSignatureOpt(MA_getModuleWsAfterSignatureOpt(arg)) : MA_getModuleWsAfterSignatureOpt(arg),
        acceptRulesOpt ? acceptRulesOpt(MA_getModuleRulesOpt(arg)) : MA_getModuleRulesOpt(arg));
  }
  ATabort("not a Module: %t\n", arg);
  return (MA_Module)NULL;
}

/*}}}  */
/*{{{  MA_TermArgs MA_visitTermArgs(MA_TermArgs arg, MA_Term (*acceptHead)(MA_Term), MA_OptLayout (*acceptWsAfterHead)(MA_OptLayout), MA_OptLayout (*acceptWsAfterSep)(MA_OptLayout)) */

MA_TermArgs MA_visitTermArgs(MA_TermArgs arg, MA_Term (*acceptHead)(MA_Term), MA_OptLayout (*acceptWsAfterHead)(MA_OptLayout), MA_OptLayout (*acceptWsAfterSep)(MA_OptLayout))
{
  if (MA_isTermArgsEmpty(arg)) {
    return MA_makeTermArgsEmpty();
  }
  if (MA_isTermArgsSingle(arg)) {
    return MA_makeTermArgsSingle(
        acceptHead ? acceptHead(MA_getTermArgsHead(arg)) : MA_getTermArgsHead(arg));
  }
  if (MA_isTermArgsMany(arg)) {
    return MA_makeTermArgsMany(
        acceptHead ? acceptHead(MA_getTermArgsHead(arg)) : MA_getTermArgsHead(arg),
        acceptWsAfterHead ? acceptWsAfterHead(MA_getTermArgsWsAfterHead(arg)) : MA_getTermArgsWsAfterHead(arg),
        acceptWsAfterSep ? acceptWsAfterSep(MA_getTermArgsWsAfterSep(arg)) : MA_getTermArgsWsAfterSep(arg),
        MA_visitTermArgs(MA_getTermArgsTail(arg), acceptHead, acceptWsAfterHead, acceptWsAfterSep));
  }
  ATabort("not a TermArgs: %t\n", arg);
  return (MA_TermArgs)NULL;
}

/*}}}  */
/*{{{  MA_TermElems MA_visitTermElems(MA_TermElems arg, MA_Term (*acceptHead)(MA_Term), MA_OptLayout (*acceptWsAfterHead)(MA_OptLayout), MA_OptLayout (*acceptWsAfterSep)(MA_OptLayout)) */

MA_TermElems MA_visitTermElems(MA_TermElems arg, MA_Term (*acceptHead)(MA_Term), MA_OptLayout (*acceptWsAfterHead)(MA_OptLayout), MA_OptLayout (*acceptWsAfterSep)(MA_OptLayout))
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
        acceptWsAfterHead ? acceptWsAfterHead(MA_getTermElemsWsAfterHead(arg)) : MA_getTermElemsWsAfterHead(arg),
        acceptWsAfterSep ? acceptWsAfterSep(MA_getTermElemsWsAfterSep(arg)) : MA_getTermElemsWsAfterSep(arg),
        MA_visitTermElems(MA_getTermElemsTail(arg), acceptHead, acceptWsAfterHead, acceptWsAfterSep));
  }
  ATabort("not a TermElems: %t\n", arg);
  return (MA_TermElems)NULL;
}

/*}}}  */
/*{{{  MA_SigArgArgs MA_visitSigArgArgs(MA_SigArgArgs arg, MA_SigArg (*acceptHead)(MA_SigArg), MA_OptLayout (*acceptWsAfterHead)(MA_OptLayout), MA_OptLayout (*acceptWsAfterSep)(MA_OptLayout)) */

MA_SigArgArgs MA_visitSigArgArgs(MA_SigArgArgs arg, MA_SigArg (*acceptHead)(MA_SigArg), MA_OptLayout (*acceptWsAfterHead)(MA_OptLayout), MA_OptLayout (*acceptWsAfterSep)(MA_OptLayout))
{
  if (MA_isSigArgArgsEmpty(arg)) {
    return MA_makeSigArgArgsEmpty();
  }
  if (MA_isSigArgArgsSingle(arg)) {
    return MA_makeSigArgArgsSingle(
        acceptHead ? acceptHead(MA_getSigArgArgsHead(arg)) : MA_getSigArgArgsHead(arg));
  }
  if (MA_isSigArgArgsMany(arg)) {
    return MA_makeSigArgArgsMany(
        acceptHead ? acceptHead(MA_getSigArgArgsHead(arg)) : MA_getSigArgArgsHead(arg),
        acceptWsAfterHead ? acceptWsAfterHead(MA_getSigArgArgsWsAfterHead(arg)) : MA_getSigArgArgsWsAfterHead(arg),
        acceptWsAfterSep ? acceptWsAfterSep(MA_getSigArgArgsWsAfterSep(arg)) : MA_getSigArgArgsWsAfterSep(arg),
        MA_visitSigArgArgs(MA_getSigArgArgsTail(arg), acceptHead, acceptWsAfterHead, acceptWsAfterSep));
  }
  ATabort("not a SigArgArgs: %t\n", arg);
  return (MA_SigArgArgs)NULL;
}

/*}}}  */
/*{{{  MA_TermAttrs MA_visitTermAttrs(MA_TermAttrs arg, MA_Term (*acceptHead)(MA_Term), MA_OptLayout (*acceptWsAfterHead)(MA_OptLayout), MA_OptLayout (*acceptWsAfterSep)(MA_OptLayout)) */

MA_TermAttrs MA_visitTermAttrs(MA_TermAttrs arg, MA_Term (*acceptHead)(MA_Term), MA_OptLayout (*acceptWsAfterHead)(MA_OptLayout), MA_OptLayout (*acceptWsAfterSep)(MA_OptLayout))
{
  if (MA_isTermAttrsEmpty(arg)) {
    return MA_makeTermAttrsEmpty();
  }
  if (MA_isTermAttrsSingle(arg)) {
    return MA_makeTermAttrsSingle(
        acceptHead ? acceptHead(MA_getTermAttrsHead(arg)) : MA_getTermAttrsHead(arg));
  }
  if (MA_isTermAttrsMany(arg)) {
    return MA_makeTermAttrsMany(
        acceptHead ? acceptHead(MA_getTermAttrsHead(arg)) : MA_getTermAttrsHead(arg),
        acceptWsAfterHead ? acceptWsAfterHead(MA_getTermAttrsWsAfterHead(arg)) : MA_getTermAttrsWsAfterHead(arg),
        acceptWsAfterSep ? acceptWsAfterSep(MA_getTermAttrsWsAfterSep(arg)) : MA_getTermAttrsWsAfterSep(arg),
        MA_visitTermAttrs(MA_getTermAttrsTail(arg), acceptHead, acceptWsAfterHead, acceptWsAfterSep));
  }
  ATabort("not a TermAttrs: %t\n", arg);
  return (MA_TermAttrs)NULL;
}

/*}}}  */
/*{{{  MA_FuncDefDefs MA_visitFuncDefDefs(MA_FuncDefDefs arg, MA_FuncDef (*acceptHead)(MA_FuncDef), MA_OptLayout (*acceptWsAfterHead)(MA_OptLayout), MA_OptLayout (*acceptWsAfterSep)(MA_OptLayout)) */

MA_FuncDefDefs MA_visitFuncDefDefs(MA_FuncDefDefs arg, MA_FuncDef (*acceptHead)(MA_FuncDef), MA_OptLayout (*acceptWsAfterHead)(MA_OptLayout), MA_OptLayout (*acceptWsAfterSep)(MA_OptLayout))
{
  if (MA_isFuncDefDefsEmpty(arg)) {
    return MA_makeFuncDefDefsEmpty();
  }
  if (MA_isFuncDefDefsSingle(arg)) {
    return MA_makeFuncDefDefsSingle(
        acceptHead ? acceptHead(MA_getFuncDefDefsHead(arg)) : MA_getFuncDefDefsHead(arg));
  }
  if (MA_isFuncDefDefsMany(arg)) {
    return MA_makeFuncDefDefsMany(
        acceptHead ? acceptHead(MA_getFuncDefDefsHead(arg)) : MA_getFuncDefDefsHead(arg),
        acceptWsAfterHead ? acceptWsAfterHead(MA_getFuncDefDefsWsAfterHead(arg)) : MA_getFuncDefDefsWsAfterHead(arg),
        acceptWsAfterSep ? acceptWsAfterSep(MA_getFuncDefDefsWsAfterSep(arg)) : MA_getFuncDefDefsWsAfterSep(arg),
        MA_visitFuncDefDefs(MA_getFuncDefDefsTail(arg), acceptHead, acceptWsAfterHead, acceptWsAfterSep));
  }
  ATabort("not a FuncDefDefs: %t\n", arg);
  return (MA_FuncDefDefs)NULL;
}

/*}}}  */
/*{{{  MA_RuleRules MA_visitRuleRules(MA_RuleRules arg, MA_Rule (*acceptHead)(MA_Rule), MA_OptLayout (*acceptWsAfterHead)(MA_OptLayout), MA_OptLayout (*acceptWsAfterSep)(MA_OptLayout)) */

MA_RuleRules MA_visitRuleRules(MA_RuleRules arg, MA_Rule (*acceptHead)(MA_Rule), MA_OptLayout (*acceptWsAfterHead)(MA_OptLayout), MA_OptLayout (*acceptWsAfterSep)(MA_OptLayout))
{
  if (MA_isRuleRulesEmpty(arg)) {
    return MA_makeRuleRulesEmpty();
  }
  if (MA_isRuleRulesSingle(arg)) {
    return MA_makeRuleRulesSingle(
        acceptHead ? acceptHead(MA_getRuleRulesHead(arg)) : MA_getRuleRulesHead(arg));
  }
  if (MA_isRuleRulesMany(arg)) {
    return MA_makeRuleRulesMany(
        acceptHead ? acceptHead(MA_getRuleRulesHead(arg)) : MA_getRuleRulesHead(arg),
        acceptWsAfterHead ? acceptWsAfterHead(MA_getRuleRulesWsAfterHead(arg)) : MA_getRuleRulesWsAfterHead(arg),
        acceptWsAfterSep ? acceptWsAfterSep(MA_getRuleRulesWsAfterSep(arg)) : MA_getRuleRulesWsAfterSep(arg),
        MA_visitRuleRules(MA_getRuleRulesTail(arg), acceptHead, acceptWsAfterHead, acceptWsAfterSep));
  }
  ATabort("not a RuleRules: %t\n", arg);
  return (MA_RuleRules)NULL;
}

/*}}}  */
/*{{{  MA_CondConds MA_visitCondConds(MA_CondConds arg, MA_Cond (*acceptHead)(MA_Cond), MA_OptLayout (*acceptWsAfterHead)(MA_OptLayout), MA_OptLayout (*acceptWsAfterSep)(MA_OptLayout)) */

MA_CondConds MA_visitCondConds(MA_CondConds arg, MA_Cond (*acceptHead)(MA_Cond), MA_OptLayout (*acceptWsAfterHead)(MA_OptLayout), MA_OptLayout (*acceptWsAfterSep)(MA_OptLayout))
{
  if (MA_isCondCondsEmpty(arg)) {
    return MA_makeCondCondsEmpty();
  }
  if (MA_isCondCondsSingle(arg)) {
    return MA_makeCondCondsSingle(
        acceptHead ? acceptHead(MA_getCondCondsHead(arg)) : MA_getCondCondsHead(arg));
  }
  if (MA_isCondCondsMany(arg)) {
    return MA_makeCondCondsMany(
        acceptHead ? acceptHead(MA_getCondCondsHead(arg)) : MA_getCondCondsHead(arg),
        acceptWsAfterHead ? acceptWsAfterHead(MA_getCondCondsWsAfterHead(arg)) : MA_getCondCondsWsAfterHead(arg),
        acceptWsAfterSep ? acceptWsAfterSep(MA_getCondCondsWsAfterSep(arg)) : MA_getCondCondsWsAfterSep(arg),
        MA_visitCondConds(MA_getCondCondsTail(arg), acceptHead, acceptWsAfterHead, acceptWsAfterSep));
  }
  ATabort("not a CondConds: %t\n", arg);
  return (MA_CondConds)NULL;
}

/*}}}  */
/*{{{  MA_LexLayout MA_visitLexLayout(MA_LexLayout arg, char (*acceptCh)(char)) */

MA_LexLayout MA_visitLexLayout(MA_LexLayout arg, char (*acceptCh)(char))
{
  if (MA_isLexLayoutWhitespace(arg)) {
    return MA_makeLexLayoutWhitespace(
        acceptCh ? acceptCh(MA_getLexLayoutCh(arg)) : MA_getLexLayoutCh(arg));
  }
  ATabort("not a LexLayout: %t\n", arg);
  return (MA_LexLayout)NULL;
}

/*}}}  */
/*{{{  MA_LexStrChar MA_visitLexStrChar(MA_LexStrChar arg, char (*acceptA)(char), char (*acceptB)(char), char (*acceptC)(char), char (*acceptCh)(char)) */

MA_LexStrChar MA_visitLexStrChar(MA_LexStrChar arg, char (*acceptA)(char), char (*acceptB)(char), char (*acceptC)(char), char (*acceptCh)(char))
{
  if (MA_isLexStrCharNewline(arg)) {
    return MA_makeLexStrCharNewline();
  }
  if (MA_isLexStrCharTab(arg)) {
    return MA_makeLexStrCharTab();
  }
  if (MA_isLexStrCharQuote(arg)) {
    return MA_makeLexStrCharQuote();
  }
  if (MA_isLexStrCharBackslash(arg)) {
    return MA_makeLexStrCharBackslash();
  }
  if (MA_isLexStrCharDecimal(arg)) {
    return MA_makeLexStrCharDecimal(
        acceptA ? acceptA(MA_getLexStrCharA(arg)) : MA_getLexStrCharA(arg),
        acceptB ? acceptB(MA_getLexStrCharB(arg)) : MA_getLexStrCharB(arg),
        acceptC ? acceptC(MA_getLexStrCharC(arg)) : MA_getLexStrCharC(arg));
  }
  if (MA_isLexStrCharNormal(arg)) {
    return MA_makeLexStrCharNormal(
        acceptCh ? acceptCh(MA_getLexStrCharCh(arg)) : MA_getLexStrCharCh(arg));
  }
  ATabort("not a LexStrChar: %t\n", arg);
  return (MA_LexStrChar)NULL;
}

/*}}}  */
/*{{{  MA_StrChar MA_visitStrChar(MA_StrChar arg, MA_LexStrChar (*acceptStrChar)(MA_LexStrChar)) */

MA_StrChar MA_visitStrChar(MA_StrChar arg, MA_LexStrChar (*acceptStrChar)(MA_LexStrChar))
{
  if (MA_isStrCharLexToCf(arg)) {
    return MA_makeStrCharLexToCf(
        acceptStrChar ? acceptStrChar(MA_getStrCharStrChar(arg)) : MA_getStrCharStrChar(arg));
  }
  ATabort("not a StrChar: %t\n", arg);
  return (MA_StrChar)NULL;
}

/*}}}  */
/*{{{  MA_LexStrCon MA_visitLexStrCon(MA_LexStrCon arg, MA_LexStrCharChars (*acceptChars)(MA_LexStrCharChars)) */

MA_LexStrCon MA_visitLexStrCon(MA_LexStrCon arg, MA_LexStrCharChars (*acceptChars)(MA_LexStrCharChars))
{
  if (MA_isLexStrConDefault(arg)) {
    return MA_makeLexStrConDefault(
        acceptChars ? acceptChars(MA_getLexStrConChars(arg)) : MA_getLexStrConChars(arg));
  }
  ATabort("not a LexStrCon: %t\n", arg);
  return (MA_LexStrCon)NULL;
}

/*}}}  */
/*{{{  MA_StrCon MA_visitStrCon(MA_StrCon arg, MA_LexStrCon (*acceptStrCon)(MA_LexStrCon)) */

MA_StrCon MA_visitStrCon(MA_StrCon arg, MA_LexStrCon (*acceptStrCon)(MA_LexStrCon))
{
  if (MA_isStrConLexToCf(arg)) {
    return MA_makeStrConLexToCf(
        acceptStrCon ? acceptStrCon(MA_getStrConStrCon(arg)) : MA_getStrConStrCon(arg));
  }
  ATabort("not a StrCon: %t\n", arg);
  return (MA_StrCon)NULL;
}

/*}}}  */
/*{{{  MA_LexStrCharChars MA_visitLexStrCharChars(MA_LexStrCharChars arg, MA_LexStrChar (*acceptHead)(MA_LexStrChar)) */

MA_LexStrCharChars MA_visitLexStrCharChars(MA_LexStrCharChars arg, MA_LexStrChar (*acceptHead)(MA_LexStrChar))
{
  if (MA_isLexStrCharCharsEmpty(arg)) {
    return MA_makeLexStrCharCharsEmpty();
  }
  if (MA_isLexStrCharCharsSingle(arg)) {
    return MA_makeLexStrCharCharsSingle(
        acceptHead ? acceptHead(MA_getLexStrCharCharsHead(arg)) : MA_getLexStrCharCharsHead(arg));
  }
  if (MA_isLexStrCharCharsMany(arg)) {
    return MA_makeLexStrCharCharsMany(
        acceptHead ? acceptHead(MA_getLexStrCharCharsHead(arg)) : MA_getLexStrCharCharsHead(arg),
        MA_visitLexStrCharChars(MA_getLexStrCharCharsTail(arg), acceptHead));
  }
  ATabort("not a LexStrCharChars: %t\n", arg);
  return (MA_LexStrCharChars)NULL;
}

/*}}}  */
/*{{{  MA_LexNatCon MA_visitLexNatCon(MA_LexNatCon arg, char* (*acceptList)(char*)) */

MA_LexNatCon MA_visitLexNatCon(MA_LexNatCon arg, char* (*acceptList)(char*))
{
  if (MA_isLexNatConDigits(arg)) {
    return MA_makeLexNatConDigits(
        acceptList ? acceptList(MA_getLexNatConList(arg)) : MA_getLexNatConList(arg));
  }
  ATabort("not a LexNatCon: %t\n", arg);
  return (MA_LexNatCon)NULL;
}

/*}}}  */
/*{{{  MA_NatCon MA_visitNatCon(MA_NatCon arg, MA_LexNatCon (*acceptNatCon)(MA_LexNatCon)) */

MA_NatCon MA_visitNatCon(MA_NatCon arg, MA_LexNatCon (*acceptNatCon)(MA_LexNatCon))
{
  if (MA_isNatConLexToCf(arg)) {
    return MA_makeNatConLexToCf(
        acceptNatCon ? acceptNatCon(MA_getNatConNatCon(arg)) : MA_getNatConNatCon(arg));
  }
  ATabort("not a NatCon: %t\n", arg);
  return (MA_NatCon)NULL;
}

/*}}}  */
/*{{{  MA_LexIdCon MA_visitLexIdCon(MA_LexIdCon arg, char (*acceptHead)(char), char* (*acceptTail)(char*)) */

MA_LexIdCon MA_visitLexIdCon(MA_LexIdCon arg, char (*acceptHead)(char), char* (*acceptTail)(char*))
{
  if (MA_isLexIdConDefault(arg)) {
    return MA_makeLexIdConDefault(
        acceptHead ? acceptHead(MA_getLexIdConHead(arg)) : MA_getLexIdConHead(arg),
        acceptTail ? acceptTail(MA_getLexIdConTail(arg)) : MA_getLexIdConTail(arg));
  }
  ATabort("not a LexIdCon: %t\n", arg);
  return (MA_LexIdCon)NULL;
}

/*}}}  */
/*{{{  MA_IdCon MA_visitIdCon(MA_IdCon arg, MA_LexIdCon (*acceptIdCon)(MA_LexIdCon)) */

MA_IdCon MA_visitIdCon(MA_IdCon arg, MA_LexIdCon (*acceptIdCon)(MA_LexIdCon))
{
  if (MA_isIdConLexToCf(arg)) {
    return MA_makeIdConLexToCf(
        acceptIdCon ? acceptIdCon(MA_getIdConIdCon(arg)) : MA_getIdConIdCon(arg));
  }
  ATabort("not a IdCon: %t\n", arg);
  return (MA_IdCon)NULL;
}

/*}}}  */

/*}}}  */
