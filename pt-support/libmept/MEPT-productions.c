#include <MEPT-productions.h>
#include <MEPT-symbols.h>
#include <MEPT-visitors.h>

/*@{ predicates */

ATbool PT_isGeneratedKernelProduction(PT_Production arg) {
  PT_Symbol rhs = PT_getProductionRhs(arg);

  if (PT_isSymbolCf(rhs) || PT_isSymbolLex(rhs)) {
    rhs = PT_getSymbolSymbol(rhs);
  }

  /* We assume that all generated productions have more complex
   * sort names, and all non generated productions have simple
   * sort names.
   */
  if (PT_isSymbolSort(rhs)) {
    return ATfalse;
  }
  else {
    return ATtrue;
  }
}

ATbool PT_prodHasLitAsRhs(PT_Production prod)
{
  /* This implements: "prod([<list>],lit(<str>),no-attrs)" */
  if (PT_isProductionDefault(prod)) {
    PT_Symbol rhs = PT_getProductionRhs(prod);

    return PT_isSymbolLit(rhs);
  }

  return ATfalse;
}


ATbool PT_isLexicalProd(PT_Production prod)
{
  /* This implements: "prod([<list>],lex(sort(<term>)),<term>)" */
  if (PT_isProductionDefault(prod)) {
    PT_Symbol rhs = PT_getProductionRhs(prod);

    if (PT_isSymbolLex(rhs)) {
      PT_Symbol symbol = PT_getSymbolSymbol(rhs);
      return PT_isSymbolSort(symbol);
    }
    return ATfalse;
  }

  return ATfalse;
}


ATbool PT_isProductionInjection(PT_Production prod)
{
  PT_Symbols lhs = PT_getProductionLhs(prod);

  if (PT_getSymbolsLength(lhs) == 1) {
    PT_Symbol symbol = PT_getSymbolsHead(lhs);

    if (!PT_isSymbolLit(symbol)) {
      return ATtrue;
    }
  }

  return ATfalse;
}


ATbool PT_prodHasLexLayoutAsRhs(PT_Production  prod)
{
  /* This implements: "prod([<list>],lex(layout),<term>)" */
  if (PT_isProductionDefault(prod)) {
    PT_Symbol rhs = PT_getProductionRhs(prod);

    if (PT_isSymbolLex(rhs)) {
      PT_Symbol symbol = PT_getSymbolSymbol(rhs);
      return PT_isSymbolLayout(symbol);
    }
    return ATfalse;
  }

  return ATfalse;
}


ATbool PT_prodHasCfLayoutAsRhs(PT_Production prod)
{
  /* This implements: "prod([<list>],cf(layout),<term>)" */
  if (PT_isProductionDefault(prod)) {
    PT_Symbol rhs = PT_getProductionRhs(prod);

    if (PT_isSymbolCf(rhs)) {
      PT_Symbol symbol = PT_getSymbolSymbol(rhs);
      return PT_isSymbolLayout(symbol);
    }
    return ATfalse;
  }

  return ATfalse;
}


ATbool PT_isOptLayoutProd(PT_Production  prod)
{
  /* This implements: "prod([<list>],cf(opt(layout)),<term>)" */
  if (PT_isProductionDefault(prod)) {
    PT_Symbol rhs = PT_getProductionRhs(prod);
    return PT_isOptLayoutSymbol(rhs);
  }

  return ATfalse;
}


ATbool PT_prodHasVarSymAsRhs(PT_Production prod)
{
  /* This implements: "prod([<list>],varsym(<str>),no-attrs)" */
  if (PT_isProductionDefault(prod)) {
    PT_Symbol rhs = PT_getProductionRhs(prod);
    return PT_isSymbolVarSym(rhs);
  }

  return ATfalse;
}


ATbool PT_isProductionVariable(PT_Production prod)
{
  /* This implements: "prod([varsym(<term>)],<term>,<term>)" */

  if (PT_isProductionDefault(prod)) {
    PT_Symbols lhs = PT_getProductionLhs(prod);

    if (PT_hasSymbolsHead(lhs)) {
      PT_Symbol lhssym = PT_getSymbolsHead(lhs);
      PT_Symbols tail = PT_getSymbolsTail(lhs);

      if (PT_isSymbolsEmpty(tail)) {
	if (PT_isSymbolCf(lhssym) || PT_isSymbolLex(lhssym)) {
	  lhssym = PT_getSymbolSymbol(lhssym);
	}

	return PT_isSymbolVarSym(lhssym);
      }
    }
  }

  return ATfalse;
}


ATbool PT_isLexicalInjectionProd(PT_Production prod)
{
  /* This implements: "prod([lex(<term>)],cf(<term>),<term>)" */
  if (PT_isProductionDefault(prod)) {
    PT_Symbols lhs = PT_getProductionLhs(prod);
    PT_Symbol rhs = PT_getProductionRhs(prod);

    if (PT_isSymbolCf(rhs) && PT_hasSymbolsHead(lhs)) {
      PT_Symbol rhsNestedSymbol = PT_getSymbolSymbol(rhs);
      PT_Symbol lhssym = PT_getSymbolsHead(lhs);
      PT_Symbols tail = PT_getSymbolsTail(lhs);
      if (PT_isSymbolsEmpty(tail) && PT_isSymbolLex(lhssym)) {
        PT_Symbol lhsNestedSymbol = PT_getSymbolSymbol(lhssym);
        return PT_isEqualSymbol(rhsNestedSymbol, lhsNestedSymbol);
      }
    }
    return ATfalse;
  }

  return ATfalse;
}


ATbool PT_prodHasIterSepAsRhs(PT_Production prod)
{
  /* This implements: 
   * "prod([<list>],cf(iter-star-sep(<term>,lit(<str>))),<term>)" and
   * "prod([<list>],cf(iter-sep(<term>,lit(<str>))),<term>)" 
   */
  if (PT_isProductionDefault(prod)) {
    PT_Symbol rhs = PT_getProductionRhs(prod);
    return PT_isIterSepSymbol(rhs);
  }

  return ATfalse;
}


ATbool PT_prodHasIterAsRhs(PT_Production prod)
{
  /* This implements: 
   * "prod([<list>],cf(iter-star(<term>,lit(<str>))),<term>)"
   * "prod([<list>],cf(iter(<term>,lit(<str>))),<term>)"
   */
  if (PT_isProductionDefault(prod)) {
    PT_Symbol rhs = PT_getProductionRhs(prod);
    return PT_isIterSymbol(rhs);
  }

  return ATfalse;
}


ATbool PT_prodHasSTARTAsRhs(PT_Production prod)
{
  /* This implements: 
   * "prod([<list>],sort(\"<START>\"),no-attrs)"
   */
  if (PT_isProductionDefault(prod)) {
    PT_Symbol rhs = PT_getProductionRhs(prod);
    if (PT_isSymbolSort(rhs)) {
      char *startsym = PT_getSymbolString(rhs);
      return strcmp(startsym,"<START>") == 0;
    }
  }

  return ATfalse;
}


/*@}*/

/*@{ attributes */

ATbool PT_hasProductionCertainAttr(PT_Production prod, PT_Attr attr)
{
  PT_Attributes attributes = PT_getProductionAttributes(prod);
  PT_Attrs attrs;

  if (PT_isProductionDefault(prod)) {
    if (PT_isAttributesNoAttrs(attributes)) {
      return ATfalse;
    }

    attrs = PT_getAttributesAttrs(attributes);

    for (; !PT_isAttrsEmpty(attrs); attrs = PT_getAttrsTail(attrs)) {
      PT_Attr head = PT_getAttrsHead(attrs);

      if (PT_isEqualAttr(head, attr)) {
	return ATtrue;
      }
    }
  }

  return ATfalse;
}


ATbool PT_hasProductionBracketAttr(PT_Production prod)
{
  static PT_Attr attr = NULL;

  if (attr == NULL) {
    attr = PT_makeAttrBracket();
    PT_protectAttr(&attr);
  }
  return PT_hasProductionCertainAttr(prod, attr);
}


ATbool PT_hasProductionMemoAttr(PT_Production prod)
{
  static PT_Attr attr = NULL;

  if (attr == NULL) {
    attr = PT_makeAttrTerm(ATparse("memo"));
    PT_protectAttr(&attr);
  }

  return PT_hasProductionCertainAttr(prod, attr);
}


ATbool PT_hasProductionTraversalAttribute(PT_Production prod)
{
  static PT_Attr attr = NULL;

  if (attr == NULL) {
    attr = PT_makeAttrTerm(ATparse("traversal"));
    PT_protectAttr(&attr);
  }
  return PT_hasProductionCertainAttr(prod, 
				     attr);
}


ATbool PT_hasProductionLexicalConstructorAttr(PT_Production prod)
{
  static PT_Attr attr = NULL;

  if (attr == NULL) {
    attr = PT_makeAttrTerm(ATparse("lexical-constructor"));
    PT_protectAttr(&attr);
  }
  return PT_hasProductionCertainAttr(prod, 
				     attr);
}


ATbool PT_hasProductionConstructorAttr(PT_Production prod)
{  
  static PT_Attr attr = NULL;

  if (attr == NULL) {
    attr = PT_makeAttrTerm(ATparse("constructor"));
    PT_protectAttr(&attr);
  }
  return PT_hasProductionCertainAttr(prod, 
				     attr);
}

ATbool PT_isProductionReject(PT_Production prod) {
  static PT_Attr attr = NULL;

  if (attr == NULL) {
    attr = PT_makeAttrReject();
    PT_protectAttr(&attr);
  }
    return PT_hasProductionCertainAttr(prod, attr);
}


ATbool PT_isProductionAvoid(PT_Production prod) {
  static PT_Attr attr = NULL;

  if (attr == NULL) {
    attr = PT_makeAttrAvoid();
    PT_protectAttr(&attr);
  }
    return PT_hasProductionCertainAttr(prod, attr);
}


ATbool PT_isProductionPrefer(PT_Production prod) {
  static PT_Attr attr = NULL;

  if (attr == NULL) {
    attr = PT_makeAttrPrefer();
    PT_protectAttr(&attr);
  }
  return PT_hasProductionCertainAttr(prod, attr);
}

/*@}*/
