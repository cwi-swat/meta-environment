#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <assert.h>
#include <aterm2.h>

#include <MEPT-utils.h>
#include <ASFME-utils.h>
#include <SDFME-utils.h>
#include <MuASF.h>

#include "asfsdf2muasf.h"
#include "sdf2pt.h"
#include "chars.h"
#include "lex-cons.h"

typedef enum { WITH_LAYOUT, WITHOUT_LAYOUT } LayoutOption;

/* abbreviations for arbitrary layout (should be ATprotected) */
static MA_Layout sp  = NULL; /* space */
static MA_Layout nl  = NULL; /* newline */
static MA_Layout nl2 = NULL; /* 2 newlines */
static MA_Layout em  = NULL; /* empty */

/* local functions */
static MA_Term treeToTerm(PT_Tree tree, LayoutOption layout);
static MA_Lexical stringToLexical(const char* str);
static MA_Layout stringToLayout(const char *str);
static MA_FunId stringToFunId(const char *str);
static MA_FunId intToFunId(int ch);
static void initLayoutAbbreviations(void);
static char* prodToEscapedString(PT_Production prod);
static int getProdArity(PT_Production prod, LayoutOption layout);
static MA_Term attrToTerm(PT_Attr attr);
static MA_TermTerms attrsToTermList(PT_Attrs attrs);
static MA_TermArgs atArgsToTermArgs(ATermList args);
static MA_Term atermToTerm(ATerm aterm);
static MA_Annotations attributesToAnnotations(PT_Attributes attributes);
static MA_FunId prodToFunId(PT_Production prod);
static MA_SigArgElems makeSigArgElems(int arity);
static MA_FuncDef productionToFuncDef(SDF_Production prod, 
                                      SDF_ModuleName moduleName);
static MA_FuncDef prodToFuncDef(PT_Production prod);
static MA_SignatureOpt productionListToSignature(SDF_ProductionList list,
                                                 SDF_ModuleName moduleName);
static MA_TermArgs argsToTermArgs(PT_Args args);
static MA_Term treeToTerm(PT_Tree tree, LayoutOption layout);
static MA_Cond conditionToCond(ASF_Condition condition);
static MA_CondList conditionsToCondList(ASF_Conditions conditions);
static MA_Rule condEquationToRule(ASF_CondEquation condEquation);
static MA_RulesOpt  condEquationListToRulesOpt(ASF_CondEquationList list);
static MA_ModId moduleNameToModId(SDF_ModuleName sdfModuleName);



static MA_Lexical stringToLexical(const char* str)
{
  return (MA_Lexical) PT_makeTreeFlatLexicalFromString(str);
}

static MA_Layout stringToLayout(const char *str)
{
  if (strlen(str) == 0) {
    return (MA_Layout) PT_makeTreeLayoutEmpty();
  }

  return (MA_Layout) PT_makeTreeLayoutFromString(str);
}

static MA_FunId stringToFunId(const char *str)
{
  return MA_makeFunIdLexToCf(stringToLexical(str));
}

static MA_FunId intToFunId(int ch)
{
  char num[5] = "\\";

  if(ch < 0 || ch > 255) {
    ATerror("intToFunId: unable to process %d\n", ch);
    return NULL;
  }

  sprintf(num+1,"%03d", ch);

  return MA_makeFunIdLexToCf(stringToLexical(num));
}

static void initLayoutAbbreviations(void)
{
  ATprotect(&em);
  ATprotect(&sp);
  ATprotect(&nl);
  ATprotect(&nl2);

  em = stringToLayout("");
  sp = stringToLayout(" ");
  nl = stringToLayout("\n");
  nl2 = stringToLayout("\n\n");
}

static char* prodToEscapedString(PT_Production prod)
{
  char *strProd = ATwriteToString((ATerm) prod);
  return escape(strProd,"\"", QUOTED);
}

static int getProdArity(PT_Production prod, LayoutOption layout)
{
  PT_Symbols symbols = PT_getProductionLhs(prod);
  int arity = 0;

  for (; PT_hasSymbolsHead(symbols); symbols = PT_getSymbolsTail(symbols)) {
    PT_Symbol symbol = PT_getSymbolsHead(symbols);

    if (!PT_isSymbolLit(symbol) &&
        (layout == WITH_LAYOUT || !PT_isSymbolLayout(symbol))) {
      arity++;
    }
  }
  return arity;  
}

static MA_TermArgs atArgsToTermArgs(ATermList args)
{
  MA_TermArgs list = NULL;

  for(;!ATisEmpty(args); args = ATgetNext(args)) {
    if (list == NULL) {
      list = MA_makeTermArgsSingle(atermToTerm(ATgetFirst(args)));
    }
    else {
      list = MA_makeTermArgsMany(atermToTerm(ATgetFirst(args)),em,",",sp,list);
    }
  }

  return (MA_TermArgs) ATreverse((ATermList) list);
}

static MA_Term atermToTerm(ATerm aterm)
{
  char *str = NULL;
  ATermList args;
  MA_Term result;
  MA_TermArgs list;

  if (ATgetType(aterm) == AT_APPL) {
    str = ATgetName(ATgetAFun((ATermAppl) aterm));
    args = ATgetArguments((ATermAppl) aterm);
    if (!ATisEmpty(args)) { 
      list = atArgsToTermArgs(args);
      result = MA_makeTermFunc(stringToFunId(str),em,em,list,em);
    } 
    else {
      result = MA_makeTermConstant(stringToFunId(str));
    }
  }
  else {
    ATerror("atermToTerm: ATerm type %s is not supported.\n", ATgetType(aterm));
    result = NULL;
  }

  return result;
}

static MA_Term attrToTerm(PT_Attr attr)
{
  char *str = NULL;
  MA_Term arg;
  MA_Term result = NULL;

  if (PT_isAttrCons(attr)) {
    str = PT_getAttrString(attr);
    arg = MA_makeTermConstant(stringToFunId(str));
    result =  MA_makeTermFunc(stringToFunId("cons"),em,em, 
                           MA_makeTermArgsSingle(arg), em);
  }
  else if (PT_isAttrId(attr)) {
    str = PT_getAttrString(attr);
    arg = MA_makeTermConstant(stringToFunId(str));
    result =  MA_makeTermFunc(stringToFunId("id"),em,em, 
			   MA_makeTermArgsSingle(arg), em);
  }
  else if (PT_isAttrAterm(attr)) {
    ATerm term = (ATerm) PT_getAttrTerm(attr);
    result =  atermToTerm(term);
  }

  free(str);

  return result;
}

static MA_TermTerms attrsToTermList(PT_Attrs attrs)
{
  MA_TermTerms terms;

  if (!PT_hasAttrsHead(attrs)) {
    return NULL;
  }
  
  terms = MA_makeTermTermsSingle(attrToTerm(PT_getAttrsHead(attrs)));
  attrs = PT_getAttrsTail(attrs);    

  for(;PT_hasAttrsHead(attrs); attrs = PT_getAttrsTail(attrs)) {
    PT_Attr attr = PT_getAttrsHead(attrs);
    terms = MA_makeTermTermsMany(attrToTerm(attr),em,",",sp,terms); 
  }

  return terms;
}

static MA_Annotations attributesToAnnotations(PT_Attributes attributes)
{
  if (PT_isAttributesNoAttrs(attributes)) {
    return (MA_Annotations) NULL;
  }

  return MA_makeAnnotationsDefault(em,
	   attrsToTermList(PT_getAttributesAttrs(attributes)),em);
}

static MA_FunId prodToFunId(PT_Production prod)
{
  char *strProd = prodToEscapedString(prod);
  MA_FunId result = stringToFunId(strProd);
  free(strProd);
  
  return result;
}

static MA_SigArgElems makeSigArgElems(int arity)
{
  MA_SigArg arg = MA_makeSigArgNormal();
  MA_SigArgElems list = MA_makeSigArgElemsSingle(arg);

  assert(arity > 0);
  
  for(--arity;arity > 0; arity--) {
    list = MA_makeSigArgElemsMany(arg,em,",",em,list);
  }

  return list;
}

static MA_FuncDef productionToFuncDef(SDF_Production prod,
				      SDF_ModuleName moduleName)
{
  PT_Production ptProd = flattenSdfProduction(prod,moduleName);

  return prodToFuncDef(ptProd);
}

static MA_FuncDef prodToFuncDef(PT_Production ptProd) 
{
  MA_FunId maFunId = prodToFunId(ptProd);
  PT_Attributes ptAttributes = PT_getProductionAttributes(ptProd);
  int arity = getProdArity(ptProd, WITHOUT_LAYOUT);
  MA_SigArgElems maSigArgElems;
  MA_FuncDef maFuncdef;

  
  if (PT_isAttributesAttrs(ptAttributes)) {
    MA_Annotations maAnnos = attributesToAnnotations(ptAttributes);
 
    if (arity > 0) {
      maSigArgElems = makeSigArgElems(arity);
      maFuncdef = MA_makeFuncDefFuncWithAnnos(maFunId,em,em,
					      maSigArgElems,em,em,maAnnos);
    }
    else {
      maFuncdef = MA_makeFuncDefConstantWithAnnos(maFunId,em,maAnnos);
    }
  }
  else { /* no attributes */
    if (arity > 0) {
      maSigArgElems = makeSigArgElems(arity);
      maFuncdef = MA_makeFuncDefFuncNoAnnos(maFunId,em,em,
					      maSigArgElems,em);
    }
    else {
      maFuncdef = MA_makeFuncDefConstantNoAnnos(maFunId);
    }
  }

  return maFuncdef;
	 
}

static MA_SignatureOpt productionListToSignature(SDF_ProductionList list,
						 SDF_ModuleName moduleName)
{
  SDF_Production sdfProd;
  MA_FuncDefElems maFuncDefElems = MA_makeFuncDefElemsEmpty();
  MA_FuncDef maFuncDef;

  for (;SDF_hasProductionListHead(list);
      list = SDF_getProductionListTail(list)) {
    sdfProd = SDF_getProductionListHead(list);
    maFuncDef = productionToFuncDef(sdfProd, moduleName);
    if (!MA_isFuncDefElemsEmpty(maFuncDefElems)) {
      maFuncDefElems = MA_makeFuncDefElemsMany(maFuncDef,em,";",nl,
					       maFuncDefElems);
    }
    else {
      maFuncDefElems = MA_makeFuncDefElemsSingle(maFuncDef);
    }
    if (!SDF_hasProductionListTail(list)) {
      break;
    }
  }

  return MA_makeSignatureOptPresent(nl,
				    MA_makeFuncDefListDefault(maFuncDefElems));
}

static MA_TermArgs argsToTermArgs(PT_Args args)
{
  MA_TermArgs termArgs = NULL;
  PT_Tree arg = NULL;
  MA_Term term = NULL;

  if (PT_isArgsEmpty(args)) {
    return NULL;
  } else {
    /* first find the first argument */
    for(;term == NULL && PT_hasArgsHead(args); args = PT_getArgsTail(args)) {
      arg = PT_getArgsHead(args);
      term = treeToTerm(arg, WITHOUT_LAYOUT); 
    } 
    
    if (term != NULL) {
      termArgs = MA_makeTermArgsSingle(term);
    
      if (PT_hasArgsTail(args)) {
        args = PT_getArgsTail(args);
      }
    }
    else {
      /* no real arguments */
      return NULL;
    }
  }

  /* then do the rest */
  for(;PT_hasArgsHead(args); args = PT_getArgsTail(args)) {
    arg = PT_getArgsHead(args);
    term = treeToTerm(arg, WITHOUT_LAYOUT);
    if (term != NULL) { /* not ignored */
      termArgs = MA_makeTermArgsMany(term,sp,",",em,termArgs);
    }
  } 

  return (MA_TermArgs) ATreverse((ATermList) termArgs);
}

static MA_Term treeToTerm(PT_Tree tree, LayoutOption layout)
{
  MA_Term result = NULL;

  if (layout == WITHOUT_LAYOUT && PT_isTreeLayout(tree)) {
    result = NULL; /* ignore layout */
  }
  else if (ASF_isTreeLexicalConstructorFunction((ASF_Tree) tree)) {
    return treeToTerm(constructorTreeToLexicalTree(tree), layout);
  }
  else if (PT_isTreeAppl(tree)) {
    PT_Production prod = PT_getTreeProd(tree);
    PT_Args args = PT_getTreeArgs(tree);
    MA_FunId funid = prodToFunId(prod);
    MA_TermArgs terms = argsToTermArgs(args);

    if (terms != NULL) {
      result = MA_makeTermFunc(funid,em,em,terms,em);
    }
    else {
      result = MA_makeTermConstant(funid);
    }
  }
  else if (PT_isTreeChar(tree)) {
    int ch = PT_getTreeCharacter(tree);
    MA_FunId funid = intToFunId(ch);

    result = MA_makeTermConstant(funid);
  }
  else if (PT_isTreeLit(tree)) {
    result = NULL; /* ignore literals */
  }
  else {
    ATerror("treeToTerm: unable to process %t\n", tree);
    result = NULL;
  }

  return result;
}

static MA_Cond conditionToCond(ASF_Condition condition)
{
  ASF_Tree asfLhs = ASF_getConditionLhs(condition);
  ASF_Tree asfRhs = ASF_getConditionRhs(condition);
  MA_Term maLhs = treeToTerm((PT_Tree) asfLhs, WITHOUT_LAYOUT);
  MA_Term maRhs = treeToTerm((PT_Tree) asfRhs, WITHOUT_LAYOUT);
  MA_Cond result = NULL;

  assert(maLhs != NULL && maRhs != NULL);

  if (ASF_isConditionPositive(condition)) {
    result = MA_makeCondEqual(maLhs,sp,sp,maRhs);
  }
  else if (ASF_isConditionNegative(condition)) {
    result = MA_makeCondUnequal(maLhs,sp,sp,maRhs);
  }
  else {
    ATerror("conditionToCond: unable to process %s\n",
	    PT_yieldTree((PT_Tree) condition));
    result = NULL;
  }

  return result;
}

static MA_CondList conditionsToCondList(ASF_Conditions conditions)
{
  ASF_ConditionList list = ASF_getConditionsList(conditions);
  MA_CondElems elems = MA_makeCondElemsEmpty();

  for(;ASF_hasConditionListHead(list); list = ASF_getConditionListTail(list)) {
    ASF_Condition condition = ASF_getConditionListHead(list);
    MA_Cond cond = conditionToCond(condition);

    elems = MA_makeCondElemsMany(cond,em,"&",sp,elems);

    if (!ASF_hasConditionListTail(list)) {
      break;
    }
  }

  elems = (MA_CondElems) ATreverse((ATermList) elems);
  return MA_makeCondListDefault(elems);
}

static MA_Rule condEquationToRule(ASF_CondEquation condEquation)
{
  ASF_Equation asfEq = ASF_getCondEquationEquation(condEquation);
  ASF_Tree asfLhs = ASF_getEquationLhs(asfEq);
  ASF_Tree asfRhs = ASF_getEquationRhs(asfEq);
  ASF_Tag tag = ASF_getCondEquationTag(condEquation);
  MA_Term lhs = treeToTerm((PT_Tree) asfLhs, WITHOUT_LAYOUT);
  MA_Term rhs = treeToTerm((PT_Tree) asfRhs, WITHOUT_LAYOUT);
  MA_CondList conds = NULL;
  MA_Rule result = NULL;

  assert(lhs != NULL && rhs != NULL);

  if (ASF_hasCondEquationConditions(condEquation)) {
    conds = conditionsToCondList(ASF_getCondEquationConditions(condEquation));
  }

  if (ASF_isTagDefault(tag)) {
    if (conds != NULL) {
      result = MA_makeRuleDefaultWithConds(nl,conds,nl,nl,lhs,sp,nl,rhs);      
    }
    else {
      result = MA_makeRuleDefaultNoConds(nl,lhs,sp,nl,rhs);
    }
  }
  else {
    if (conds != NULL) {
      result = MA_makeRuleWithConds(conds,nl,nl,lhs,sp,nl,rhs);
    }
    else {
      result = MA_makeRuleNoConds(lhs,sp,nl,rhs);
    }
  }

  return result;
}

static MA_RulesOpt  condEquationListToRulesOpt(ASF_CondEquationList list)
{
  MA_RuleElems rules = MA_makeRuleElemsEmpty();

  for(;ASF_hasCondEquationListHead(list);
       list = ASF_getCondEquationListTail(list)) {
    ASF_CondEquation eq = ASF_getCondEquationListHead(list);

    if (!MA_isRuleElemsEmpty(rules)) {
      rules = MA_makeRuleElemsMany(condEquationToRule(eq),em,";",nl2,rules);
    }
    else {
      rules = MA_makeRuleElemsSingle(condEquationToRule(eq));
    }

    if (ASF_isCondEquationListSingle(list)) {
      break;
    }
  }

  return MA_makeRulesOptPresent(nl,MA_makeRuleListDefault(rules));
}

static MA_ModId moduleNameToModId(SDF_ModuleName sdfModuleName)
{
  MA_ModId result;

  if (SDF_isModuleNameUnparameterized(sdfModuleName)) {
    char *str = strdup(PT_yieldTree((PT_Tree) sdfModuleName));
    result = MA_makeModIdLexToCf(stringToLexical(str));
    free(str);
  }
  else {
    ATerror("moduleNameToModId: unable to interpret module name: %s\n",
	    PT_yieldTree((PT_Tree) sdfModuleName));
    result = NULL;
  }

  return result;
}

MA_Module 
asfSdfToMuASF(SDF_ModuleName name, SDF_ProductionList signature, 
	    ASF_CondEquationList equations)
{
  MA_SignatureOpt maSignature;
  MA_RulesOpt maRules;
  MA_ModId maName;

  initLayoutAbbreviations();

  maSignature = productionListToSignature(signature, name);
  maRules = condEquationListToRulesOpt(equations); 
  maName = moduleNameToModId(name);

  return MA_makeModuleModule(sp,maName,nl,maSignature,nl,maRules);
}
