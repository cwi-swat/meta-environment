/*{{{  standard includes */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

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

/*}}}  */


typedef enum { WITH_LAYOUT, WITHOUT_LAYOUT } LayoutOption;

static LayoutOption layout = WITHOUT_LAYOUT;
static ATermIndexedSet funcdefs;

static MA_OptLayout sp  = NULL; /* space */
static MA_OptLayout nl  = NULL; /* newline */
static MA_OptLayout nl2 = NULL; /* 2 newlines */
static MA_OptLayout em  = NULL; /* empty */

/*{{{  static function decls */

static MA_OptLayout stringToLayout(const char *str);
static void initLayoutAbbreviations(void);
static int getProdArity(PT_Production prod, LayoutOption layout);
static MA_Term attrToTerm(PT_Attr attr);
static MA_TermElems attrsToTermList(PT_Attrs attrs);
static MA_TermArgs atArgsToTermArgs(ATermList args);
static MA_Term atermToTerm(ATerm aterm);
static MA_FunId prodToFunId(PT_Production prod, ATbool returnsList);
static MA_SigArgArgs makeSigArgElems(int arity);
static MA_FuncDef prodToFuncDef(PT_Production prod, MA_Term type);
static MA_TermArgs argsToTermArgs(PT_Args args);
static MA_Term treeToTerm(PT_Tree tree);
static MA_Cond conditionToCond(ASF_ASFCondition condition); 
static MA_CondList conditionsToCondList(ASF_ASFConditions conditions); 

static MA_Rule condEquationToRule(ASF_ASFConditionalEquation condEquation);
static MA_RulesOpt  condEquationListToRulesOpt(ASF_ASFConditionalEquationList list);
static MA_ModId makeModId(const char *str);
static ATbool checkListProductionCompatibility(PT_Production ptProd);
MA_RuleRules literalsToRules(ATermTable literals);

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


/*{{{  MA_StrCon MA_makeStrCon(const char* str) */

MA_StrCon MA_makeStrCon(const char* str)
{
  int len = strlen(str);
  int i;
  MA_LexStrCharChars list = MA_makeLexStrCharCharsEmpty();

  for (i = len - 1; i >= 0; i--) {
    MA_LexStrChar ch;

    switch(str[i]) {
      case '\n':
        ch = MA_makeLexStrCharNewline();
        break;
      case '\t':
        ch = MA_makeLexStrCharTab();
        break;
      case '"':
        ch = MA_makeLexStrCharQuote();
        break;
      case '\\':
        ch = MA_makeLexStrCharBackslash();
        break;
      default:
        if (isprint(str[i])) {
          ch = MA_makeLexStrCharNormal(str[i]);
        }
        else {
          int value = str[i];
          int a, b, c;

          c = value % 10;
          value /= 10;
          b = value % 10;
          value /= 10;
          a = value;

          ch = MA_makeLexStrCharDecimal(a,b,c);
        }
    }

    list = MA_makeLexStrCharCharsMany(ch, list);
  }


  return MA_makeStrConLexToCf(MA_makeLexStrConDefault(list));
}

/*}}}  */
/*{{{  MA_IdCon MA_makeIdCon(const char *str) */

MA_IdCon MA_makeIdCon(const char *str)
{
  assert(strlen(str) >= 1);
  return MA_makeIdConLexToCf(MA_makeLexIdConDefault(str[0], str+1));
}

/*}}}  */

/*{{{  static MA_Layout stringToLayout(const char *str) */

static MA_OptLayout stringToLayout(const char *str)
{
  if (strlen(str) == 0) {
    return (MA_OptLayout) PT_makeTreeLayoutEmpty();
  }

  return (MA_OptLayout) PT_makeTreeLayoutFromString(str);
}

/*}}}  */
/*{{{  static MA_Term intToTerm(int ch) */

static MA_Term intToTerm(int ch)
{
  char digits[100];

  sprintf(digits, "%d", ch);

  return MA_makeTermConstant(MA_makeFunIdCharacter(MA_makeNatConLexToCf(MA_makeLexNatConDigits(digits))));
}

/*}}}  */
/*{{{  static void initLayoutAbbreviations(void) */

static void initLayoutAbbreviations(void)
{
  MA_protectOptLayout(&em);
  em = stringToLayout("");

  MA_protectOptLayout(&sp);
  sp = stringToLayout(" ");

  MA_protectOptLayout(&nl);
  nl = stringToLayout("\n");

  MA_protectOptLayout(&nl2);
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

      if (!PT_isSymbolLit(symbol) 
	  && (layout == WITH_LAYOUT || !PT_isOptLayoutSymbol(symbol))) {
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
      list = MA_makeTermArgsMany(atermToTerm(ATgetFirst(args)),em,sp,list);
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
  MA_TermList termList;
  MA_FunId fun;
  AFun afun;

  if (ATgetType(aterm) == AT_APPL) {
    afun = ATgetAFun((ATermAppl) aterm);
    str = ATgetName(afun);

    if (ATisQuoted(afun)) {
      fun = MA_makeFunIdQuoted(MA_makeStrCon(str));
    }
    else {
      fun = MA_makeFunIdUnquoted(MA_makeIdCon(str));
    }

    args = ATgetArguments((ATermAppl) aterm);
    if (!ATisEmpty(args)) { 
      list = atArgsToTermArgs(args);
      result = MA_makeTermFunc(fun,em,em,list,em);
    } 
    else {
      result = MA_makeTermConstant(fun);
    }
  }
  else if (ATgetType(aterm) == AT_LIST) {
    list = atArgsToTermArgs((ATermList) aterm);
    termList = MA_makeTermListDefault((MA_TermElems) list);
    result = MA_makeTermList(em,termList,em);
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
    arg = MA_makeTermConstant(MA_makeFunIdQuoted(MA_makeStrCon(str)));
    result =  MA_makeTermFunc(MA_makeFunIdUnquoted(MA_makeIdCon("id")),
			      em,em, 
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
/*{{{  static MA_TermElems attrsToTermList(PT_Attrs attrs) */

static MA_TermElems attrsToTermList(PT_Attrs attrs)
{
  MA_TermElems terms;

  if (!PT_hasAttrsHead(attrs)) {
    return NULL;
  }
  
  terms = MA_makeTermElemsSingle(attrToTerm(PT_getAttrsHead(attrs)));
  attrs = PT_getAttrsTail(attrs);    

  for(;PT_hasAttrsHead(attrs); attrs = PT_getAttrsTail(attrs)) {
    PT_Attr attr = PT_getAttrsHead(attrs);
    terms = MA_makeTermElemsMany(attrToTerm(attr),em,sp,terms); 
  }

  return terms;
}

/*}}}  */
/*{{{  static MA_FunId prodToFunId(PT_Production prod) */

static MA_FunId prodToFunId(PT_Production prod, ATbool returnsList)
{
  char *strProd;
  MA_FunId result;

  strProd = strdup(ATwriteToString((ATerm) prod));

  if (strProd == NULL) {
    ATerror("Unable to allocate memory for string.\n"); 
    return NULL;
  }

  result = MA_makeFunIdQuoted(MA_makeStrCon(strProd));

  if (PT_isProductionList(prod)) {
    result = MA_makeFunIdList(em, result, em);
  }
  else if (returnsList) {
    result = MA_makeFunIdReturnsList(em,result,em);
  }

  free(strProd);

  return result;
}

/*}}}  */
/*{{{  static MA_SigArgElems makeSigArgElems(int arity) */

static MA_SigArgArgs makeSigArgElems(int arity)
{
  MA_SigArg arg = MA_makeSigArgNormal();
  MA_SigArgArgs list = MA_makeSigArgArgsSingle(arg);

  assert(arity > 0);
  
  for(--arity;arity > 0; arity--) {
    list = MA_makeSigArgArgsMany(arg,em,em,list);
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

    MA_FunId funid = MA_makeFunIdQuoted(MA_makeStrCon(str));
 
    if (str == NULL) {
      ATerror("Unable to allocate memory for string.\n");
      return NULL; 
    }

    result = MA_makeTermConstant(funid);
    free(str);
  }

  return result;
}

/*}}}  */
/*{{{  static MA_FuncDef prodToFuncDef(PT_Production ptProd)  */

static MA_FuncDef prodToFuncDef(PT_Production ptProd, MA_Term type) 
{
  MA_FunId maFunId = prodToFunId(ptProd, prodReturnsList(ptProd));
  PT_Attributes ptAttributes;
  int arity ;
  MA_SigArgArgs maSigArgElems;
  MA_FuncDef maFuncdef;

  arity = getProdArity(ptProd, WITHOUT_LAYOUT);

  if (PT_isProductionDefault(ptProd)) {
    MA_TermElems maAnnos = NULL;
    MA_Annotations wrappedAnnos;

    ptAttributes = PT_getProductionAttributes(ptProd);

    if (PT_isAttributesAttrs(ptAttributes)) {
      maAnnos = attrsToTermList(PT_getAttributesAttrs(ptAttributes));
    }

    maAnnos = maAnnos ? 
      MA_makeTermElemsMany(type, em, em, maAnnos) : 
      MA_makeTermElemsSingle(type);

    wrappedAnnos = MA_makeAnnotationsDefault(em, (MA_TermAttrs) maAnnos, em);
    
    if (arity > 0) {
      maSigArgElems = makeSigArgElems(arity);
      maFuncdef = MA_makeFuncDefFuncWithAnnos(maFunId,em,em,
					      maSigArgElems,em,em,wrappedAnnos);
    }
    else {
      maFuncdef = MA_makeFuncDefConstantWithAnnos(maFunId,em,wrappedAnnos);
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
/*{{{  static MA_TermArgs argsToTermArgs(PT_Args args) */

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
      term = treeToTerm(arg);
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
    term = treeToTerm(arg);
    if (term != NULL) { /* not ignored */
      termArgs = MA_makeTermArgsMany(term,sp,em,termArgs);
    }
  } 

  return (MA_TermArgs) ATreverse((ATermList) termArgs);
}

/*}}}  */
/*{{{  static MA_Term variableToTerm(PT_Tree var) */

static MA_Term variableToTerm(PT_Tree var)
{
  char *str = strdup(PT_yieldTreeToString(var, ATfalse));
  MA_FunId varid = MA_makeFunIdQuoted(MA_makeStrCon(str));
  MA_VarId maVar = NULL;
  MA_Term type = NULL;
  MA_Term result = NULL;

  assert(PT_isTreeVar(var));

  if (PT_isTreeVarListStar(var)) {
    maVar = MA_makeVarIdStar(em, varid);
  }
  else if (PT_isTreeVarListPlus(var)) {
    maVar = MA_makeVarIdPlus(em, varid);
  }
  else {
    maVar = MA_makeVarIdNormal(em, varid);
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
/*{{{  static MA_Term applTreeToTerm(PT_Tree tree, ATbool returnsList) */

static MA_Term applTreeToTerm(PT_Tree tree, ATbool returnsList)
{
  MA_Term result = NULL;
  PT_Production prod = PT_getTreeProd(tree);
  MA_Term type = MA_makeTermFunc(MA_makeFunIdUnquoted(MA_makeIdCon("type")),
				 em,em,
				MA_makeTermArgsSingle(treeToType(tree)),
			       em);	
  MA_FuncDef funcdef = prodToFuncDef(prod, type);
  PT_Args args = PT_getTreeArgs(tree);
  MA_FunId funid = prodToFunId(prod, returnsList);
  MA_TermArgs terms = argsToTermArgs(args);
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
/*{{{  static MA_Term treeToTerm(PT_Tree tree) */

static MA_Term treeToTerm(PT_Tree tree)
{
  MA_Term result = NULL;
  if (layout == WITHOUT_LAYOUT && PT_isTreeLayout(tree)) {
    result = NULL; /* ignore layout */
  }
  else if (ASF_isTreeTraversalFunction((ASF_Tree) tree)) {
    PT_Tree converted;
    MA_Term type = treeToType(tree);
    ATbool returnsList = prodReturnsList(PT_getTreeProd(tree));
    converted = ASC_transformTraversalFunction(tree);
    result = MA_makeTermTyped(applTreeToTerm(converted, returnsList),
			      em,em,type);
  }
  else if (PT_isTreeVar(tree)) {
    result = variableToTerm(tree);
  }
  else if (PT_isTreeBracket(tree)) {
    result = treeToTerm(PT_getTreeBracketTree(tree));
  } 
  else if (PT_isTreeLit(tree)) {
    result = NULL; 
  }
  else if (PT_isTreeAppl(tree)) {
    ATbool returnsList = prodReturnsList(PT_getTreeProd(tree));
    result = applTreeToTerm(tree, returnsList);
  }
  else if (PT_isTreeChar(tree)) {
    int ch = PT_getTreeCharacter(tree);

    result = intToTerm(ch);
  }
  else if (PT_isTreeAmb(tree)) {
    ATwarning("asfc: ambiguities are not allowed by the compiler.\n");
    result = NULL;
  }
  else {
    ATerror("treeToTerm: unable to process %t\n", tree);
    result = NULL;
  }

  return result;
}

/*}}}  */
/*{{{  static MA_Cond conditionToCond(ASF_ASFCondition condition) */

static MA_Cond conditionToCond(ASF_ASFCondition condition)
{
  ASF_Tree asfLhs = ASF_getASFConditionLhs(condition);
  ASF_Tree asfRhs = ASF_getASFConditionRhs(condition);
  MA_Term maLhs = treeToTerm((PT_Tree) asfLhs);
  MA_Term maRhs = treeToTerm((PT_Tree) asfRhs);
  MA_Cond result = NULL;

  assert(maLhs != NULL && maRhs != NULL);

  if (ASF_isASFConditionEquality(condition) ||
      ASF_isASFConditionMatch(condition)) {
    result = MA_makeCondEqual(maLhs,sp,sp,maRhs);
  }
  else if (ASF_isASFConditionNegative(condition)) {
    result = MA_makeCondUnequal(maLhs,sp,sp,maRhs);
  }
  else if (ASF_isASFConditionNoMatch(condition)) {
    /* assignment is directed the other way in muASF, why?? */
    result = MA_makeCondNoAssign(maRhs,sp,sp,maLhs);
  }
  else {
    ATerror("conditionToCond: unable to process %t\n",
	    ((PT_Tree) condition));
    result = NULL;
  }

  return result;
}

/*}}}  */
/*{{{  static MA_CondList conditionsToCondList(ASF_ASFConditions conditions) */

static MA_CondList conditionsToCondList(ASF_ASFConditions conditions)
{
  ASF_ASFConditionList list = ASF_getASFConditionsList(conditions);
  MA_CondConds elems = MA_makeCondCondsEmpty();

  for(;ASF_hasASFConditionListHead(list); list = ASF_getASFConditionListTail(list)) {
    ASF_ASFCondition condition = ASF_getASFConditionListHead(list);
    MA_Cond cond = conditionToCond(condition);

    if (MA_isCondCondsEmpty(elems)) {
      elems = MA_makeCondCondsSingle(cond);
    }
    else {
      elems = MA_makeCondCondsMany(cond,em,sp,elems);
    }

    if (!ASF_hasASFConditionListTail(list)) {
      break;
    }
  }

  elems = MA_reverseCondConds(elems);
  return MA_makeCondListDefault(elems);
}

/*}}}  */
/*{{{  static MA_Rule condEquationToRule(ASF_ASFConditionalEquation condEquation, */

static MA_Rule condEquationToRule(ASF_ASFConditionalEquation condEquation)
{
  ASF_ASFEquation asfEq = ASF_getASFConditionalEquationASFEquation(condEquation);
  ASF_Tree asfLhs = ASF_getASFEquationLhs(asfEq);
  ASF_Tree asfRhs = ASF_getASFEquationRhs(asfEq);
  ASF_ASFTag tag = ASF_getASFConditionalEquationASFTag(condEquation);
  MA_Term lhs = treeToTerm((PT_Tree) asfLhs);
  MA_Term rhs = treeToTerm((PT_Tree) asfRhs);
  MA_CondList conds = NULL;
  MA_Rule result = NULL;


  if (lhs == NULL || rhs == NULL) {
    return NULL;
  }

  /* TODO: fix this in a better way */
  /* If a left-hand side is a function returning a list, it will
   * alway be wrapped with a list production. We remove this wrapper,
   * such that the function can be matched to a term that contains
   * the function without the wrapper.
   */
  if (PT_hasTreeProd((PT_Tree) asfLhs)) {
    PT_Production prod = PT_getTreeProd((PT_Tree) asfLhs);

    if (PT_isProductionList(prod)) {
      PT_Args args = PT_getTreeArgs((PT_Tree) asfLhs);

      if (PT_getArgsLength(args) == 1) {
	PT_Tree arg = PT_getArgsHead(args);

	if (PT_hasTreeProd(arg)) {
	  PT_Production prod = PT_getTreeProd(arg);

	  if (!PT_isTreeVar(arg)
	      && (PT_prodHasIterAsRhs(prod) 
		  || PT_prodHasIterSepAsRhs(prod))) {
	    lhs = MA_getTermArgsHead(MA_getTermArgs(lhs));
	  }
	}
      }
    }
  }

  if (ASF_hasASFConditionalEquationASFConditions(condEquation)) {
    conds = conditionsToCondList(ASF_getASFConditionalEquationASFConditions(condEquation));
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
/*{{{  static MA_RulesOpt  condEquationListToRulesOpt(ASF_ASFConditionalEquationList list) */

static MA_RulesOpt  condEquationListToRulesOpt(ASF_ASFConditionalEquationList list)
{
  MA_RuleRules rules = MA_makeRuleRulesEmpty();

  for(;ASF_hasASFConditionalEquationListHead(list);
       list = ASF_getASFConditionalEquationListTail(list)) {
    ASF_ASFConditionalEquation eq = ASF_getASFConditionalEquationListHead(list);
    MA_Rule rule = condEquationToRule(eq);

    if (rule == NULL) {
      return NULL;
    }

    if (!MA_isRuleRulesEmpty(rules)) {
      rules = MA_makeRuleRulesMany(rule,em,nl2,rules);
    }
    else {
      rules = MA_makeRuleRulesSingle(rule);
    }

    if (ASF_isASFConditionalEquationListSingle(list)) {
      break;
    }
  }

  /* We want to compile the rules in order given by the user for
   * predictability.
   */
  rules = MA_reverseRuleRules(rules);

  return MA_makeRulesOptPresent(nl,MA_makeRuleListDefault(rules));
}

/*}}}  */
/*{{{  static MA_ModId makeModId(const char *str) */
static MA_ModId makeModId(const char *str)
{
  MA_IdCon id = MA_makeIdCon(str);
  return MA_makeModIdDefault(id);
}

/*}}}  */

/*{{{  MA_SignatureOpt indexedSetToSignatureOpt(ATermIndexedSet funcdefs) */

static MA_SignatureOpt indexedSetToSignatureOpt(ATermIndexedSet funcdefs)
{
  ATermList list = ATindexedSetElements(funcdefs);
  MA_FuncDefDefs elems = NULL;

  if (ATisEmpty(list)) {
    return MA_makeSignatureOptAbsent();
  }

  for(;!ATisEmpty(list); list = ATgetNext(list)) {
    MA_FuncDef def = MA_FuncDefFromTerm(ATgetFirst(list));

    if (elems == NULL) {
      elems = MA_makeFuncDefDefsSingle(def);
    }
    else {
      elems = MA_makeFuncDefDefsMany(def, em,nl,elems);
    }
  }

  return MA_makeSignatureOptPresent(nl,
           MA_makeFuncDefListDefault(elems));
}

/*}}}  */

/*{{{  MA_Module asfToMuASF(char *name, ASF_ASFConditionalEquationList equations) */

MA_Module asfToMuASF(char *name, ASF_ASFConditionalEquationList equations)
{
  MA_SignatureOpt maSignature;
  MA_RulesOpt maRules;
  MA_ModId maName;

  initLayoutAbbreviations();

  /* globals */
  layout = WITHOUT_LAYOUT;
  funcdefs = ATindexedSetCreate(1024, 70);

  if (ASF_isASFConditionalEquationListEmpty(equations)) {
    maRules = MA_makeRulesOptAbsent();
  } 
  else {
    maRules = condEquationListToRulesOpt(equations);
    if (maRules == NULL) {
      return NULL;
    }
  }

  maSignature = indexedSetToSignatureOpt(funcdefs);
  maName = makeModId(name);

  ATindexedSetDestroy(funcdefs);

  return MA_makeModuleModule(sp,maName,nl,maSignature,nl,maRules);
}

/*}}}  */
