/*{{{  standard includes */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


/*}}}  */
/*{{{  meta includes */

#include <aterm2.h>
#include <MEPT-utils.h>
#include <ASFME-utils.h>
#include <asc-support-me.h>
#include <asc-traversals.h>
#include <MuASF.h>


/*}}}  */
/*{{{  local includes */

#include "asf2muasf.h"
#include "chars.h"
#include "lex-cons.h"

/*}}}  */

/*{{{  local typedefs */

typedef enum { WITH_LAYOUT, WITHOUT_LAYOUT } LayoutOption;

/*}}}  */

/*{{{  macros */

#define RETURNS_LIST "LIST"

/*}}}  */

/*{{{  abbreviations for arbitrary layout  */

static MA_Layout sp  = NULL; /* space */
static MA_Layout nl  = NULL; /* newline */
static MA_Layout nl2 = NULL; /* 2 newlines */
static MA_Layout em  = NULL; /* empty */


/*}}}  */

/*{{{  static function decls */

static MA_Lexical stringToLexical(const char* str);
static MA_Layout stringToLayout(const char *str);
static MA_FunId stringToFunId(const char *str);
static MA_FunId intToFunId(int ch);
static void initLayoutAbbreviations(void);
static int getProdArity(PT_Production prod, LayoutOption layout);
static MA_Term attrToTerm(PT_Attr attr);
static MA_TermTerms attrsToTermList(PT_Attrs attrs);
static MA_TermArgs atArgsToTermArgs(ATermList args);
static MA_Term atermToTerm(ATerm aterm);
static MA_Annotations attributesToAnnotations(PT_Attributes attributes);
static MA_FunId prodToFunId(PT_Production prod, ATbool returnsList);
static MA_SigArgElems makeSigArgElems(int arity);
static MA_FuncDef prodToFuncDef(PT_Production prod);
static MA_TermArgs argsToTermArgs(PT_Args args, ATermIndexedSet funcdefs);
static MA_Term treeToTerm(PT_Tree tree, ATermIndexedSet funcdefs, 
			  LayoutOption layout);
static MA_Cond conditionToCond(ASF_Condition condition, 
			       ATermIndexedSet funcdefs);
static MA_CondList conditionsToCondList(ASF_Conditions conditions, 
					ATermIndexedSet funcdefs);

static MA_Rule condEquationToRule(ASF_CondEquation condEquation, 
				  ATermIndexedSet funcdefs);
static MA_RulesOpt  condEquationListToRulesOpt(ASF_CondEquationList list,
					       ATermIndexedSet funcdefs);
static MA_ModId makeModId(const char *str);
static ATbool checkListProductionCompatibility(PT_Production ptProd);

/*}}}  */

/*{{{  static ATbool returnsList(PT_Production prod) */

static ATbool prodReturnsList(PT_Production prod)
{
  if (PT_isProductionDefault(prod)) {
    PT_Symbol rhs;

    rhs = PT_getProductionRhs(prod);

    if (PT_isSymbolCf(rhs) || PT_isSymbolLex(rhs)) {
      rhs = PT_getSymbolSymbol(rhs);
    }

    if (PT_isSymbolIterPlus(rhs) ||
	PT_isSymbolIterStar(rhs) ||
	PT_isSymbolIterPlusSep(rhs) ||
	PT_isSymbolIterStarSep(rhs)) {
       return ATtrue;
    }
  }

  return ATfalse;
}

/*}}}  */

/*{{{  static MA_Lexical stringToLexical(const char* str) */

static MA_Lexical stringToLexical(const char* str)
{
  return (MA_Lexical) PT_makeTreeFlatLexicalFromString(str);
}

/*}}}  */
/*{{{  static MA_Layout stringToLayout(const char *str) */

static MA_Layout stringToLayout(const char *str)
{
  if (strlen(str) == 0) {
    return (MA_Layout) PT_makeTreeLayoutEmpty();
  }

  return (MA_Layout) PT_makeTreeLayoutFromString(str);
}

/*}}}  */
/*{{{  static MA_FunId stringToFunId(const char *str) */

static MA_FunId stringToFunId(const char *str)
{
  return MA_makeFunIdLexToCf(stringToLexical(str));
}

/*}}}  */
/*{{{  static MA_VarId stringToVarId(const char *str) */

static MA_VarId stringToVarId(const char *str)
{
  char* alfanum = toalfanum(str);
  char* varid = malloc(strlen(alfanum) + 3);
  MA_VarId result;

  if (varid == NULL) {
    ATerror("Not enought memory to prefix: %s\n", str);
    return NULL;
  }

  strcpy(varid, "V_");
  strcat(varid, alfanum);

  result = MA_makeVarIdLexToCf(stringToLexical(varid));

  free(alfanum);
  free(varid);

  return result;
}

/*}}}  */
/*{{{  static MA_FunId intToFunId(int ch) */

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

/*}}}  */
/*{{{  static void initLayoutAbbreviations(void) */

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

/*}}}  */
/*{{{  static int getProdArity(PT_Production prod, LayoutOption layout) */

static int getProdArity(PT_Production prod, LayoutOption layout)
{
  PT_Symbols symbols;
  int arity = 0;

  if (PT_isProductionDefault(prod)) {
    symbols = PT_getProductionLhs(prod);

    for (; PT_hasSymbolsHead(symbols); symbols = PT_getSymbolsTail(symbols)) {
      PT_Symbol symbol = PT_getSymbolsHead(symbols);

      if (!PT_isSymbolLit(symbol)  &&
	  (layout == WITH_LAYOUT || !PT_isOptLayoutSymbol(symbol))) {
	arity++;
      }
    }
  }
  else {
    arity = 1; /* a list production */
  }

  return arity;  
}

/*}}}  */
/*{{{  static MA_TermArgs atArgsToTermArgs(ATermList args) */

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

/*}}}  */
/*{{{  static MA_Term atermToTerm(ATerm aterm) */

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
    ATerror("atermToTerm: ATerm %t is not supported.\n", aterm);
    result = NULL;
  }

  return result;
}

/*}}}  */
/*{{{  static MA_Term attrToTerm(PT_Attr attr) */

static MA_Term attrToTerm(PT_Attr attr)
{
  char *str = NULL;
  MA_Term arg;
  MA_Term result = NULL;

  if (PT_isAttrId(attr)) {
    str = PT_getAttrModuleName(attr);
    arg = MA_makeTermConstant(stringToFunId(str));
    result =  MA_makeTermFunc(stringToFunId("id"),em,em, 
			   MA_makeTermArgsSingle(arg), em);
  }
  else if (PT_isAttrTerm(attr)) {
    ATerm term = (ATerm) PT_getAttrTerm(attr);
    
    result =  atermToTerm(term);
  }
  else if (PT_isAttrAssoc(attr)) {
    ATerm term = (ATerm) PT_getAttrAssoc(attr);
    result = atermToTerm(term);
  }
  else {
    ATerm term = PT_AttrToTerm(attr);
    result = atermToTerm(term);
  }

  return result;
}

/*}}}  */
/*{{{  static MA_TermTerms attrsToTermList(PT_Attrs attrs) */

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

/*}}}  */
/*{{{  static MA_Annotations attributesToAnnotations(PT_Attributes attributes) */

static MA_Annotations attributesToAnnotations(PT_Attributes attributes)
{
  if (PT_isAttributesNoAttrs(attributes)) {
    return (MA_Annotations) NULL;
  }

  return MA_makeAnnotationsDefault(em,
	   attrsToTermList(PT_getAttributesAttrs(attributes)),em);
}

/*}}}  */
/*{{{  static MA_FunId prodToFunId(PT_Production prod) */

static MA_FunId prodToFunId(PT_Production prod, ATbool returnsList)
{
  char *strProd;
  char *str;
  char *escaped;
  MA_FunId result;

  strProd = strdup(ATwriteToString((ATerm) prod));

  if (strProd == NULL) {
    ATerror("Unable to allocate memory for string.\n"); 
    return NULL;
  }

  str = (char*) malloc(strlen(strProd) + 
		       (returnsList ? strlen(RETURNS_LIST) : 0) + 1);

  if (str == NULL) {
    ATerror("Unable to allocate memory for string.\n");
    return NULL;
  } 
  else {
    str[0] = '\0';
  }

  if (returnsList) {
    strcat(str,RETURNS_LIST);
  }

  strcat(str,strProd);

  escaped = escape(str,"\"\\", QUOTED);

  result = stringToFunId(escaped);

  free(strProd);
  free(str);
  free(escaped);

  return result;
}

/*}}}  */
/*{{{  static MA_SigArgElems makeSigArgElems(int arity) */

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

/*}}}  */
/*{{{  static ATbool checkListProductionCompatibility(PT_Production ptProd) */

static ATbool checkListProductionCompatibility(PT_Production ptProd)
{
  ATbool result = ATtrue;
  PT_Symbol rhs;

  assert(PT_isProductionList(ptProd));

  rhs = PT_getProductionRhs(ptProd);

  if (PT_isSymbolIterPlus(rhs)
      || PT_isSymbolIterStar(rhs)) {
    PT_Symbol nested = PT_getSymbolSymbol(rhs);

    if (PT_isSymbolIterStar(nested) ||
	PT_isSymbolIterPlus(nested) ||
	PT_isSymbolIterStarSep(nested) ||
	PT_isSymbolIterStarSep(nested)) {
      result = ATfalse;
    }
    
    result = ATtrue;
  }
  else if (PT_isSymbolIterPlusSep(rhs)
	   || PT_isSymbolIterStarSep(rhs)) {
    PT_Symbol sep = PT_getSymbolSeparator(rhs);

    if (PT_isSymbolLit(sep)) {
      result = ATtrue; /* only allow literal separators */
    }
    else {
      result = ATfalse;
    }
  }

  return result;
}

/*}}}  */

/*{{{  static MA_Term treeToType(PT_Tree tree) */

static MA_Term treeToType(PT_Tree tree)
{
  MA_Term result = NULL;

  if (PT_hasTreeProd(tree)) {
    PT_Production prod = PT_getTreeProd(tree);
    PT_Symbol sym = PT_getProductionRhs(prod);
    char *str = strdup(ATwriteToString((ATerm) sym));
    char *escaped =  escape(str,"\"\\", QUOTED);

    MA_FunId funid = stringToFunId(escaped);
 
    if (str == NULL) {
      ATerror("Unable to allocate memory for string.\n");
      return NULL; 
    }

    result = MA_makeTermConstant(funid);
    free(str);
    free(escaped);
  }

  return result;
}

/*}}}  */
/*{{{  static MA_FuncDef prodToFuncDef(PT_Production ptProd)  */

static MA_FuncDef prodToFuncDef(PT_Production ptProd) 
{
  MA_FunId maFunId = prodToFunId(ptProd, prodReturnsList(ptProd));
  PT_Attributes ptAttributes;
  int arity ;
  MA_SigArgElems maSigArgElems;
  MA_FuncDef maFuncdef;

  arity = getProdArity(ptProd, WITHOUT_LAYOUT);

  if (PT_isProductionDefault(ptProd)) {
    ptAttributes = PT_getProductionAttributes(ptProd);

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
  }
  else { /* list production */
    if (checkListProductionCompatibility(ptProd)) {
      maSigArgElems = makeSigArgElems(1);
      maFuncdef = MA_makeFuncDefFuncNoAnnos(maFunId,em,em,maSigArgElems,em);
    }
    else {
      ATerror("This list type is not supported yet: %t\n", ptProd);
      return NULL;
    } 
  }

  return maFuncdef;
	 
}

/*}}}  */
/*{{{  static MA_TermArgs argsToTermArgs(PT_Args args, ATindexedSet funcdefs) */

static MA_TermArgs argsToTermArgs(PT_Args args, ATermIndexedSet funcdefs)
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
      term = treeToTerm(arg,funcdefs, WITHOUT_LAYOUT); 
    } 
    
    if (term != NULL) {
      termArgs = MA_makeTermArgsSingle(term);
    }
    else {
      /* no real arguments */
      return NULL;
    }
  }

  /* then do the rest */
  for(;PT_hasArgsHead(args); args = PT_getArgsTail(args)) {
    arg = PT_getArgsHead(args);
    term = treeToTerm(arg, funcdefs, WITHOUT_LAYOUT);
    if (term != NULL) { /* not ignored */
      termArgs = MA_makeTermArgsMany(term,sp,",",em,termArgs);
    }
  } 

  return (MA_TermArgs) ATreverse((ATermList) termArgs);
}

/*}}}  */
/*{{{  static MA_Term variableToTerm(PT_Tree var) */

static MA_Term variableToTerm(PT_Tree var)
{
  char *str = strdup(PT_yieldTree(var));
  MA_VarId varid = stringToVarId(str);
  MA_Var maVar = NULL;
  MA_Term type = NULL;
  MA_Term result = NULL;

  assert(PT_isTreeVar(var));

  if (PT_isTreeVarListStar(var)) {
    maVar = MA_makeVarStar(em, varid);
  }
  else if (PT_isTreeVarListPlus(var)) {
    maVar = MA_makeVarPlus(em, varid);
  }
  else {
    maVar = MA_makeVarNormal(varid);
  }

  free(str);
  result = MA_makeTermVar(maVar);

  type = treeToType(var);

  if (type) {
    result = MA_makeTermTyped(result,em,em,type);
  }

  return result;
}

/*}}}  */
/*{{{  static MA_Term applTreeToTerm(PT_Tree tree, ATermIndexedSet funcdefs, */

static MA_Term applTreeToTerm(PT_Tree tree, ATermIndexedSet funcdefs,
			      LayoutOption layout, ATbool returnsList)
{
  MA_Term result = NULL;
  PT_Production prod = PT_getTreeProd(tree);
  MA_FuncDef funcdef = prodToFuncDef(prod);
  PT_Args args = PT_getTreeArgs(tree);
  MA_FunId funid = prodToFunId(prod, returnsList);
  MA_TermArgs terms = argsToTermArgs(args, funcdefs);
  ATindexedSetPut(funcdefs, (ATerm) funcdef, NULL);

  if (terms != NULL) {
    result = MA_makeTermFunc(funid,em,em,terms,em);
  }
  else {
    result = MA_makeTermConstant(funid);
  }

  return result;
}

/*}}}  */
/*{{{  static MA_Term treeToTerm(PT_Tree tree, ATindexedSet funcdefs,  */

static MA_Term treeToTerm(PT_Tree tree, ATermIndexedSet funcdefs, 
			  LayoutOption layout)
{
  MA_Term result = NULL;
  if (layout == WITHOUT_LAYOUT && PT_isTreeLayout(tree)) {
    result = NULL; /* ignore layout */
  }
  else if (ASF_isTreeLexicalConstructorFunction((ASF_Tree) tree)) {
    PT_Tree converted = constructorTreeToLexicalTree(tree);
    result = treeToTerm(converted, funcdefs, layout);
  }
  else if (ASF_isTreeTraversalFunction((ASF_Tree) tree)) {
    PT_Tree converted;
    MA_Term type = treeToType(tree);
    ATbool returnsList = prodReturnsList(PT_getTreeProd(tree));
    converted = ASC_transformTraversalFunction(tree);
    result = MA_makeTermTyped(applTreeToTerm(converted, funcdefs, layout, 
					     returnsList),
			      em,em,type);
  }
  else if (PT_isTreeVar(tree)) {
    result = variableToTerm(tree);
  }
  else if (PT_isTreeBracket(tree)) {
    result = treeToTerm(PT_getTreeBracketTree(tree), funcdefs, layout);
  } 
  else if (PT_isTreeAppl(tree)) {
    ATbool returnsList = prodReturnsList(PT_getTreeProd(tree));
    result = applTreeToTerm(tree, funcdefs, layout, returnsList);
  }
  else if (PT_isTreeChar(tree)) {
    int ch = PT_getTreeCharacter(tree);
    MA_FunId funid;

    funid = intToFunId(ch);
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

/*}}}  */
/*{{{  static MA_Cond conditionToCond(ASF_Condition condition, */

static MA_Cond conditionToCond(ASF_Condition condition,
			       ATermIndexedSet funcdefs)
{
  ASF_Tree asfLhs = ASF_getConditionLhs(condition);
  ASF_Tree asfRhs = ASF_getConditionRhs(condition);
  MA_Term maLhs = treeToTerm((PT_Tree) asfLhs, funcdefs, WITHOUT_LAYOUT);
  MA_Term maRhs = treeToTerm((PT_Tree) asfRhs, funcdefs, WITHOUT_LAYOUT);
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

/*}}}  */
/*{{{  static MA_CondList conditionsToCondList(ASF_Conditions conditions, */

static MA_CondList conditionsToCondList(ASF_Conditions conditions,
					ATermIndexedSet funcdefs)
{
  ASF_ConditionList list = ASF_getConditionsList(conditions);
  MA_CondElems elems = MA_makeCondElemsEmpty();

  for(;ASF_hasConditionListHead(list); list = ASF_getConditionListTail(list)) {
    ASF_Condition condition = ASF_getConditionListHead(list);
    MA_Cond cond = conditionToCond(condition, funcdefs);

    if (MA_isCondElemsEmpty(elems)) {
      elems = MA_makeCondElemsSingle(cond);
    }
    else {
      elems = MA_makeCondElemsMany(cond,em,"&",sp,elems);
    }

    if (!ASF_hasConditionListTail(list)) {
      break;
    }
  }

  elems = (MA_CondElems) ATreverse((ATermList) elems);
  return MA_makeCondListDefault(elems);
}

/*}}}  */
/*{{{  static MA_Rule condEquationToRule(ASF_CondEquation condEquation, */

static MA_Rule condEquationToRule(ASF_CondEquation condEquation,
				  ATermIndexedSet funcdefs)
{
  ASF_Equation asfEq = ASF_getCondEquationEquation(condEquation);
  ASF_Tree asfLhs = ASF_getEquationLhs(asfEq);
  ASF_Tree asfRhs = ASF_getEquationRhs(asfEq);
  ASF_Tag tag = ASF_getCondEquationTag(condEquation);
  MA_Term lhs = treeToTerm((PT_Tree) asfLhs, funcdefs, WITHOUT_LAYOUT);
  MA_Term rhs = treeToTerm((PT_Tree) asfRhs, funcdefs, WITHOUT_LAYOUT);
  MA_CondList conds = NULL;
  MA_Rule result = NULL;

  assert(lhs != NULL && rhs != NULL);

  if (ASF_hasCondEquationConditions(condEquation)) {
    conds = conditionsToCondList(ASF_getCondEquationConditions(condEquation),
				 funcdefs);
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

/*}}}  */
/*{{{  static MA_RulesOpt  condEquationListToRulesOpt(ASF_CondEquationList list, */

static MA_RulesOpt  condEquationListToRulesOpt(ASF_CondEquationList list,
					       ATermIndexedSet funcdefs)
{
  MA_RuleElems rules = MA_makeRuleElemsEmpty();

  for(;ASF_hasCondEquationListHead(list);
       list = ASF_getCondEquationListTail(list)) {
    ASF_CondEquation eq = ASF_getCondEquationListHead(list);

    if (!MA_isRuleElemsEmpty(rules)) {
      rules = MA_makeRuleElemsMany(condEquationToRule(eq,funcdefs),
				   em,";",nl2,rules);
    }
    else {
      rules = MA_makeRuleElemsSingle(condEquationToRule(eq,funcdefs));
    }

    if (ASF_isCondEquationListSingle(list)) {
      break;
    }
  }

  /* We want to compile the rules in order given by the user for
   * predictability.
   */
  rules = (MA_RuleElems) ATreverse((ATermList) rules);

  return MA_makeRulesOptPresent(nl,MA_makeRuleListDefault(rules));
}

/*}}}  */
/*{{{  static MA_ModId makeModId(const char *str) */

static MA_ModId makeModId(const char *str)
{
  MA_ModId result = MA_makeModIdLexToCf(stringToLexical(str));
  return result;
}

/*}}}  */

/*{{{  MA_SignatureOpt indexedSetToSignatureOpt(ATermIndexedSet funcdefs) */

MA_SignatureOpt indexedSetToSignatureOpt(ATermIndexedSet funcdefs)
{
  ATermList list = ATindexedSetElements(funcdefs);
  MA_FuncDefElems elems = NULL;

  if (ATisEmpty(list)) {
    return MA_makeSignatureOptAbsent();
  }

  for(;!ATisEmpty(list); list = ATgetNext(list)) {
    MA_FuncDef def = MA_FuncDefFromTerm(ATgetFirst(list));

    if (elems == NULL) {
      elems = MA_makeFuncDefElemsSingle(def);
    }
    else {
      elems = MA_makeFuncDefElemsMany(def, em,";",nl,elems);
    }
  }

  return MA_makeSignatureOptPresent(nl,
           MA_makeFuncDefListDefault(elems));
}

/*}}}  */

/*{{{  MA_Module asfToMuASF(char *name, ASF_CondEquationList equations) */

MA_Module asfToMuASF(char *name, ASF_CondEquationList equations)
{
  MA_SignatureOpt maSignature;
  ATermIndexedSet funcdefs = ATindexedSetCreate(1024, 70);
  MA_RulesOpt maRules;
  MA_ModId maName;

  initLayoutAbbreviations();

  if (ASF_isCondEquationListEmpty(equations)) {
    maRules = MA_makeRulesOptAbsent();
  } 
  else {
    maRules = condEquationListToRulesOpt(equations, funcdefs); 
  }

  maSignature = indexedSetToSignatureOpt(funcdefs);
  maName = makeModId(name);

  ATindexedSetDestroy(funcdefs);

  return MA_makeModuleModule(sp,maName,nl,maSignature,nl,maRules);
}

/*}}}  */
