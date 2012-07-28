/*{{{  includes */

#include "PTMEPT-utils.h"
#include "PTMEPT.h"
#include <MEPT-utils.h>
#include <assert.h>
#include <stdlib.h>
#include <aterm2.h>
#include <string.h>

/*}}}  */

static ATermTable lowerCache = NULL;

/*{{{  static PTPT_Tree lookupTree(PT_Tree tree) */

static PT_Tree lookupTree(PTPT_Tree tree)
{
  if (lowerCache) {
    return PT_TreeFromTerm(ATtableGet(lowerCache, PTPT_TreeToTerm(tree)));
  }
  return NULL;
}

/*}}}  */
/*{{{  static PTPT_Symbol lookupSymbol(PT_Symbol symbol) */

static PT_Symbol lookupSymbol(PTPT_Symbol symbol)
{
  if (lowerCache) {
    return PT_SymbolFromTerm(ATtableGet(lowerCache, PTPT_SymbolToTerm(symbol)));
  }
  return NULL;
}

/*}}}  */
/*{{{  static PTPT_ATerm lookupATerm(PT_ATerm symbol) */

static ATerm lookupATerm(PTPT_ATerm trm)
{
  if (lowerCache) {
    return ATtableGet(lowerCache, PTPT_ATermToTerm(trm));
  }
  return NULL;
}

/*}}}  */

/*{{{  static int PTPT_lowerNatCon(PTPT_NatCon val) */

static int PTPT_lowerNatCon(PTPT_NatCon val)
{
  char *valStr = PT_yieldTree((PT_Tree) val);
  int result = atoi(valStr);

  return result;
}

/*}}}  */
/*{{{  static int PTPT_lowerIntCon(PTPT_IntCon val) */

static int PTPT_lowerIntCon(PTPT_IntCon val)
{
  int result = PTPT_lowerNatCon(PTPT_getIntConNatCon(val));

  return PTPT_isIntConNegative(val) ? -result : result;
}

/*}}}  */
/*{{{  static double PTPT_lowerRealCon(PTPT_RealCon val) */

static double PTPT_lowerRealCon(PTPT_RealCon val)
{
  ATerror("lower: reals not implemented!\n");
  return 0.0;
}

/*}}}  */
/*{{{  static AFun PTPT_lowerStrCon(PTPT_StrCon string) */

static AFun PTPT_lowerStrCon(PTPT_StrCon string)
{
  char *str = PT_yieldTree((PT_Tree) string);
  ATerm appl;
  AFun fun;

  appl = ATparse(str);
  fun = ATgetAFun((ATermAppl) appl);

  return fun;
}

/*}}}  */
/*{{{  static AFun PTPT_lowerIdCon(PTPT_IdCon string) */

static AFun PTPT_lowerIdCon(PTPT_IdCon string)
{
  ATerm appl = ATparse(PT_yieldTree((PT_Tree) string));

  return ATgetAFun((ATermAppl) appl);
}

/*}}}  */
/*{{{  static AFun PTPT_lowerAFun(PTPT_AFun fun, int arity) */

static AFun PTPT_lowerAFun(PTPT_AFun fun, int arity)
{
  AFun result = 0;

  if (PTPT_isAFunQuoted(fun)) {
    result = PTPT_lowerStrCon(PTPT_getAFunStrCon(fun));
  }
  else if (PTPT_isAFunUnquoted(fun)) {
    result = PTPT_lowerIdCon(PTPT_getAFunIdCon(fun));
  }

  /* put the proper arity in the result */
  result = ATmakeAFun(ATgetName(result), arity, ATisQuoted(result));

  return result;
}

/*}}}  */

ATerm PTPT_lowerATerm(PTPT_ATerm term);

/*{{{  static ATermList PTPT_lowerATermList(PTPT_ATerm listelems) */

static ATermList PTPT_lowerATermList(PTPT_ATerm listelems)
{
  ATermList list = ATempty;
  PTPT_ATermElems elems = PTPT_getATermElems(listelems);

  for (; !PTPT_isATermElemsEmpty(elems);
       elems = PTPT_getATermElemsTail(elems)) {
    ATerm head = PTPT_lowerATerm(PTPT_getATermElemsHead(elems));

    list = ATinsert(list, head);

    if (!PTPT_hasATermElemsTail(elems)) {
      break;
    }
  }

  return ATreverse(list);
}

/*}}}  */
/*{{{  static ATermList PTPT_lowerAnnotations(PTPT_ATermAnnos annos) */

static ATermList PTPT_lowerAnnotations(PTPT_ATermAnnos annos)
{
  PTPT_OptLayout e = PTPT_makeOptLayoutAbsent();
  PTPT_ATerm list = PTPT_makeATermList(e, (PTPT_ATermElems) annos, e);

  return PTPT_lowerATermList(list);
}

/*}}}  */
/*{{{  static ATermList PTPT_lowerAnn(PTPT_Ann ann) */

static ATermList PTPT_lowerAnn(PTPT_Annotation ann)
{
  return PTPT_lowerAnnotations(PTPT_getAnnotationAnnos(ann));
}

/*}}}  */
/*{{{  static PT_ATerm PTPT_lowerATermAppl(ATermAppl appl) */

static ATerm PTPT_lowerATermAppl(PTPT_ATerm appl)
{
  ATermList args;
  AFun fun;
  PTPT_OptLayout e = PTPT_makeOptLayoutAbsent();

  /* hack alert, PT_ATermArgs is the same as an ATermList by coincidence */
  PTPT_ATerm list = PTPT_makeATermList(e, (PTPT_ATermElems)
				       PTPT_getATermArgs(appl),
				       e);

  args = (ATermList) PTPT_lowerATermList(list);
  fun = PTPT_lowerAFun(PTPT_getATermFun(appl), ATgetLength(args));


  return (ATerm) ATmakeApplList(fun, args);
}

/*}}}  */

/*{{{  PT_ATerm PTPT_lowerATerm(ATerm term) */

ATerm PTPT_lowerATerm(PTPT_ATerm term)
{
  ATerm result = lookupATerm(term);
  ATermList ann = NULL;

  if (result != NULL) {
    return result;
  }

  if (PTPT_hasATermAnnotation(term)) {
    ann = PTPT_lowerAnn(PTPT_getATermAnnotation(term));
  }

  if (PTPT_isATermList(term)) {
    result = (ATerm) PTPT_lowerATermList(term);
  }
  else if (PTPT_isATermAppl(term)) {
    result = PTPT_lowerATermAppl(term);
  }
  else if (PTPT_isATermFun(term)) {
    {
    AFun afun = PTPT_lowerAFun(PTPT_getATermFun(term), 0);

    result = (ATerm) ATmakeAppl0(afun);

    }
  }
  else if (PTPT_isATermInt(term)) {
      PTPT_IntCon intc = PTPT_getATermIntCon(term);

      result = (ATerm) ATmakeInt(PTPT_lowerIntCon(intc));
  }
  else if (PTPT_isATermReal(term)) {
    PTPT_RealCon real = PTPT_getATermRealCon(term);

    result = (ATerm) ATmakeReal(PTPT_lowerRealCon(real));
  }
  else if (PTPT_isATermPlaceholder(term)) {
    ATerm type = PTPT_lowerATerm(PTPT_getATermType(term));
    result = (ATerm) ATmakePlaceholder(type);
  }
  else {
    ATwarning("lower: unsupported ATerm %t\n", term);
    assert(ATfalse);
  }

  return result;
}

/*}}}  */

/*{{{  static PT_CharRanges PTPT_lowerCharRanges(PTPT_CharRanges symbols) */

static PT_CharRange PTPT_lowerCharRange(PTPT_CharRange symbol);

static PT_CharRanges PTPT_lowerCharRanges(PTPT_CharRanges symbols)
{
  PTPT_CharRangeList ranges = PTPT_getCharRangesList(symbols);
  PT_CharRanges list = PT_makeCharRangesEmpty();

  for (; !PTPT_isCharRangeListEmpty(ranges);
       ranges = PTPT_getCharRangeListTail(ranges)) {
    PT_CharRange head =
      PTPT_lowerCharRange(PTPT_getCharRangeListHead(ranges));
    list = PT_makeCharRangesMany(head, list);

    if (!PTPT_hasCharRangeListTail(ranges)) {
      break;
    }
  }

  return (PT_CharRanges) ATreverse((ATermList) list);
}

/*}}}  */
/*{{{  static PT_Symbols PTPT_lowerSymbols(PTPT_Symbols symbols) */

static PT_Symbol PTPT_lowerSymbol(PTPT_Symbol symbol);

static PT_Symbols PTPT_lowerSymbols(PTPT_Symbols symbols)
{
  PTPT_SymbolList elems = PTPT_getSymbolsList(symbols);
  PT_Symbols list = PT_makeSymbolsEmpty();

  for (; !PTPT_isSymbolListEmpty(elems);
       elems = PTPT_getSymbolListTail(elems)) {
    PT_Symbol head = PTPT_lowerSymbol(PTPT_getSymbolListHead(elems));

    list = PT_makeSymbolsMany(head, list);

    if (!PTPT_hasSymbolListTail(elems)) {
      break;
    }
  }

  return PT_reverseSymbols(list);
}

/*}}}  */
/*{{{  static PT_Attrs PTPT_lowerAttrs(PTPT_Attrs symbols) */

static PT_Attr PTPT_lowerAttr(PTPT_Attr attr);

static PT_Attrs PTPT_lowerAttrs(PTPT_Attrs attrs)
{
  PTPT_AttrList list = PTPT_getAttrsList(attrs);
  PT_Attrs result = NULL;

  for (; PTPT_hasAttrListHead(list); list = PTPT_getAttrListTail(list)) {
    PT_Attr head = PTPT_lowerAttr(PTPT_getAttrListHead(list));

    if (result == NULL) {
      result = PT_makeAttrsSingle(head);
    }
    else {
      result = PT_makeAttrsMany(head, result);
    }

    if (!PTPT_hasAttrListTail(list)) {
      break;
    }
  }

  return PT_reverseAttrs(result);
}

/*}}}  */
/*{{{  static PT_Symbol PTPT_lowerSymbol(PTPT_Symbol symbol) */

static PT_Symbol PTPT_lowerSymbol(PTPT_Symbol symbol)
{
  PT_Symbol result =  lookupSymbol(symbol);

  if (result != NULL) {
    return result;
  }

  if (PTPT_isSymbolLit(symbol)) {
    AFun lit = PTPT_lowerStrCon(PTPT_getSymbolString(symbol));

    result = PT_makeSymbolLit(ATgetName(lit));
  }
  else if (PTPT_isSymbolCilit(symbol)) {
    AFun lit = PTPT_lowerStrCon(PTPT_getSymbolString(symbol));

    result = PT_makeSymbolCilit(ATgetName(lit));
  }
  else if (PTPT_isSymbolCf(symbol)) {
    PT_Symbol new = PTPT_lowerSymbol(PTPT_getSymbolSymbol(symbol));

    result = PT_makeSymbolCf(new);
  }
  else if (PTPT_isSymbolLex(symbol)) {
    PT_Symbol new = PTPT_lowerSymbol(PTPT_getSymbolSymbol(symbol));

    result = PT_makeSymbolLex(new);
  }
  else if (PTPT_isSymbolEmpty(symbol)) {
    result = PT_makeSymbolEmpty();
  }
  else if (PTPT_isSymbolSeq(symbol)) {
    PT_Symbols syms = PTPT_lowerSymbols(PTPT_getSymbolSymbols(symbol));

    result
      = PT_makeSymbolSeq(syms);

  }
  else if (PTPT_isSymbolOpt(symbol)) {
    PT_Symbol new = PTPT_lowerSymbol(PTPT_getSymbolSymbol(symbol));

    result = PT_makeSymbolOpt(new);
  }
  else if (PTPT_isSymbolAlt(symbol)) {
    PT_Symbol lhs = PTPT_lowerSymbol(PTPT_getSymbolLhs(symbol));
    PT_Symbol rhs = PTPT_lowerSymbol(PTPT_getSymbolRhs(symbol));

    result = PT_makeSymbolAlt(lhs, rhs);
  }
  else if (PTPT_isSymbolTuple(symbol)) {
    PT_Symbol head = PTPT_lowerSymbol(PTPT_getSymbolHead(symbol));
    PT_Symbols rest = PTPT_lowerSymbols(PTPT_getSymbolRest(symbol));

    result = PT_makeSymbolTuple(head, rest);
  }
  else if (PTPT_isSymbolSort(symbol)) {
    AFun lit = PTPT_lowerStrCon(PTPT_getSymbolString(symbol));

    result = PT_makeSymbolSort(ATgetName(lit));
  }
  else if (PTPT_isSymbolIter(symbol)) {
    PT_Symbol new = PTPT_lowerSymbol(PTPT_getSymbolSymbol(symbol));

    result = PT_makeSymbolIterPlus(new);
  }
  else if (PTPT_isSymbolIterStar(symbol)) {
    PT_Symbol new = PTPT_lowerSymbol(PTPT_getSymbolSymbol(symbol));

    result = PT_makeSymbolIterStar(new);
  }
  else if (PTPT_isSymbolIterSep(symbol)) {
    PT_Symbol sym = PTPT_lowerSymbol(PTPT_getSymbolSymbol(symbol));
    PT_Symbol sep = PTPT_lowerSymbol(PTPT_getSymbolSeparator(symbol));

    result = PT_makeSymbolIterPlusSep(sym, sep);
  }
  else if (PTPT_isSymbolIterStarSep(symbol)) {
    PT_Symbol sym = PTPT_lowerSymbol(PTPT_getSymbolSymbol(symbol));
    PT_Symbol sep = PTPT_lowerSymbol(PTPT_getSymbolSeparator(symbol));

    result = PT_makeSymbolIterStarSep(sym, sep);
  }
  else if (PTPT_isSymbolIterN(symbol)) {
    PT_Symbol sym = PTPT_lowerSymbol(PTPT_getSymbolSymbol(symbol));
    int num = PTPT_lowerNatCon(PTPT_getSymbolNumber(symbol));

    result = PT_makeSymbolIterN(sym, num);
  }
  else if (PTPT_isSymbolIterSepN(symbol)) {
    PT_Symbol sym = PTPT_lowerSymbol(PTPT_getSymbolSymbol(symbol));
    PT_Symbol sep = PTPT_lowerSymbol(PTPT_getSymbolSeparator(symbol));
    int num = PTPT_lowerNatCon(PTPT_getSymbolNumber(symbol));

    result = PT_makeSymbolIterSepN(sym, sep, num);
  }
  else if (PTPT_isSymbolFunc(symbol)) {
    PT_Symbols syms = PTPT_lowerSymbols(PTPT_getSymbolSymbols(symbol));
    PT_Symbol sym = PTPT_lowerSymbol(PTPT_getSymbolSymbol(symbol));

    result = PT_makeSymbolFunc(syms, sym);
  }
  else if (PTPT_isSymbolParameterizedSort(symbol)) {
    AFun lit = PTPT_lowerStrCon(PTPT_getSymbolSort(symbol));
    PT_Symbols syms = PTPT_lowerSymbols(PTPT_getSymbolParameters(symbol));

    result = PT_makeSymbolParameterizedSort(ATgetName(lit), syms);
  }
  else if (PTPT_isSymbolVarsym(symbol)) {
    PT_Symbol new = PTPT_lowerSymbol(PTPT_getSymbolSymbol(symbol));

    result = PT_makeSymbolVarSym(new);
  }
  else if (PTPT_isSymbolLayout(symbol)) {
    result = PT_makeSymbolLayout();
  }
  else if (PTPT_isSymbolCharClass(symbol)) {
    PT_CharRanges ranges =
      PTPT_lowerCharRanges(PTPT_getSymbolCharRanges(symbol));
    result = PT_makeSymbolCharClass(ranges);
  }
  else {
    ATwarning("lower: unknown symbol %t\n", symbol);
    assert(ATfalse);
  }

  return result;
}

/*}}}  */
/*{{{  static PT_CharRange PTPT_lowerCharRange(PTPT_CharRange range) */

static PT_CharRange PTPT_lowerCharRange(PTPT_CharRange range)
{
  PT_CharRange result = NULL;

  if (PTPT_isCharRangeCharacter(range)) {
    int nat = PTPT_lowerNatCon(PTPT_getCharRangeInteger(range));

    result = PT_makeCharRangeCharacter(nat);
  }
  else if (PTPT_isCharRangeRange(range)) {
    int start = PTPT_lowerNatCon(PTPT_getCharRangeStart(range));
    int end = PTPT_lowerNatCon(PTPT_getCharRangeEnd(range));

    result = PT_makeCharRangeRange(start, end);
  }
  else {
    ATwarning("lower: unknown charrange %t\n", range);
    assert(ATfalse);
  }

  return result;
}

/*}}}  */
/*{{{  static PT_Associativity PTPT_lowerAssociativity(PTPT_Associativity assoc) */

static PT_Associativity PTPT_lowerAssociativity(PTPT_Associativity assoc)
{
  PT_Associativity result = NULL;

  if (PTPT_isAssociativityLeft(assoc)) {
    result = PT_makeAssociativityLeft();
  }
  else if (PTPT_isAssociativityRight(assoc)) {
    result = PT_makeAssociativityRight();
  }
  else if (PTPT_isAssociativityAssoc(assoc)) {
    result = PT_makeAssociativityAssoc();
  }
  else if (PTPT_isAssociativityNonAssoc(assoc)) {
    result = PT_makeAssociativityNonAssoc();
  }
  else {
    ATwarning("lower: unknown associativity %t\n", assoc);
    assert(ATfalse);
  }

  return result;
}

/*}}}  */
/*{{{  static PT_Attr PTPT_lowerAttr(PTPT_Attr attr) */

static PT_Attr PTPT_lowerAttr(PTPT_Attr attr)
{
  PT_Attr result = NULL;

  if (PTPT_isAttrAssoc(attr)) {
    PT_Associativity assoc =
      PTPT_lowerAssociativity(PTPT_getAttrAssociativity(attr));
    result = PT_makeAttrAssoc(assoc);
  }
  else if (PTPT_isAttrTerm(attr)) {
    ATerm term = PTPT_lowerATerm(PTPT_getAttrAterm(attr));

    result = PT_makeAttrTerm(term);
  }
  else if (PTPT_isAttrId(attr)) {
    AFun id = PTPT_lowerStrCon(PTPT_getAttrModuleName(attr));

    result = PT_makeAttrId(ATgetName(id));
  }
  else if (PTPT_isAttrBracket(attr)) {
    result = PT_makeAttrBracket();
  }
  else if (PTPT_isAttrReject(attr)) {
    result = PT_makeAttrReject();
  }
  else if (PTPT_isAttrPrefer(attr)) {
    result = PT_makeAttrPrefer();
  }
  else if (PTPT_isAttrAvoid(attr)) {
    result = PT_makeAttrAvoid();
  }
  else {
    ATwarning("lower: unknown attr %t\n", attr);
    assert(ATfalse);
  }

  return result;
}

/*}}}  */

/*{{{  static PT_Attributes PTPT_lowerAttributes(PTPT_Attributes attributes) */

static PT_Attributes PTPT_lowerAttributes(PTPT_Attributes attributes)
{
  PT_Attributes result = NULL;

  if (PTPT_isAttributesNoAttrs(attributes)) {
    result = PT_makeAttributesNoAttrs();
  }
  else if (PTPT_isAttributesAttrs(attributes)) {
    PT_Attrs attrs =
      PTPT_lowerAttrs(PTPT_getAttributesAttributes(attributes));
    result = PT_makeAttributesAttrs(attrs);
  }
  else {
    ATwarning("lower: unknown attributes: %t\n", attributes);
    assert(ATfalse);
  }

  return result;
}

/*}}}  */

/*{{{  static PT_Production PTPT_lowerProd(PTPT_Production prod) */

static PT_Production PTPT_lowerProd(PTPT_Production prod)
{
  PT_Production result = NULL;

  if (PTPT_isProductionDefault(prod)) {
    PT_Symbols lhs;
    PT_Symbol rhs;
    PT_Attributes attrs;

    lhs = PTPT_lowerSymbols(PTPT_getProductionLhs(prod));
    rhs = PTPT_lowerSymbol(PTPT_getProductionRhs(prod));
    attrs = PTPT_lowerAttributes(PTPT_getProductionAttributes(prod));
    result = PT_makeProductionDefault(lhs, rhs, attrs);
  }
  else if (PTPT_isProductionList(prod)) {
    PT_Symbol rhs = PTPT_lowerSymbol(PTPT_getProductionRhs(prod));

    result = PT_makeProductionList(rhs);
  }
  else {
    ATwarning("lower: unknown production %t\n", prod);
    assert(ATfalse);
  }

  return result;
}

/*}}}  */

PT_Tree PTPT_lowerTree(PTPT_Tree pt);

/*{{{  static PT_Args PTPT_lowerArgs(PTPT_Args args)  */

static PT_Args PTPT_lowerArgs(PTPT_Args args)
{
  PTPT_TreeList trees = PTPT_getArgsList(args);
  PT_Args list = PT_makeArgsEmpty();

  for (; !PTPT_isTreeListEmpty(trees); trees = PTPT_getTreeListTail(trees)) {
    PT_Tree head = PTPT_lowerTree(PTPT_getTreeListHead(trees));

    list = PT_makeArgsMany(head, list);

    if (!PTPT_hasTreeListTail(trees)) {
      break;
    }
  }

  return PT_reverseArgs(list);
}

/*}}}  */

/*{{{  PT_Tree PTPT_lowerTreeCache(PTPT_Tree pt, ATermTable myLowerCache) */

PT_Tree PTPT_lowerTreeCache(PTPT_Tree pt, ATermTable myLowerCache)
{
  PT_Tree result = NULL;
  lowerCache = myLowerCache;

  result = PTPT_lowerTree(pt);

  lowerCache = NULL;

  return result;
}

/*}}}  */

/*{{{  PT_Tree PTPT_lowerTree(PTPT_Tree pt) */

PT_Tree PTPT_lowerTree(PTPT_Tree pt)
{
  PT_Tree result = lookupTree(pt);
  PTPT_Annotation annos = NULL;

  if (result != NULL) {
    return result;
  }

  if (PTPT_isTreeAnnotated(pt)) {
    annos = PTPT_getTreeAnnotation(pt);
    pt = PTPT_getTreeTree(pt);
    assert(!PTPT_isTreeAnnotated(pt) 
	   && "encountered an illegal nested annotation");
  }

  if (PTPT_isTreeAmb(pt)) {
    PTPT_Args args = PTPT_getTreeArgs(pt);

    result = PT_makeTreeAmb(PTPT_lowerArgs(args));
  }
  else if (PTPT_isTreeAppl(pt)) {
    PT_Production prod;
    PT_Args args;

    prod = PTPT_lowerProd(PTPT_getTreeProd(pt));
    args = PTPT_lowerArgs(PTPT_getTreeArgs(pt));

    result = PT_makeTreeAppl(prod, args);
  }
  else if (PTPT_isTreeCycle(pt)) {
    PT_Symbol symbol;
    int length;

    symbol = PTPT_lowerSymbol(PTPT_getTreeSymbol(pt));
    length = PTPT_lowerNatCon(PTPT_getTreeLength(pt));

    result = PT_makeTreeCycle(symbol,length);
  }
  else if (PTPT_isTreeChar(pt)) {
    PTPT_NatCon val = PTPT_getTreeCharacter(pt);

    result = PT_makeTreeChar(PTPT_lowerNatCon(val));
  }
  else {
    ATwarning("lower: unknown term %t\n", pt);
    /* In this case we leave the term as-is, which is important
     * for bootstrapping purposes. When bootstrapping the ASF-Normalizer,
     * we try to lower meta-level variables, which should be left alone.
     */
    result = (PT_Tree) pt;
  }

  if (annos != NULL) {
    ATermList atannos = PTPT_lowerAnn(annos);

    result = PT_setTreeAnnotations(result, (ATerm) atannos);
  }

  return result;
}

/*}}}  */
/*{{{  PT_ParseTree PTPT_lowerParseTree(PTPT_ParseTree pt) */

PT_ParseTree PTPT_lowerParseTree(PTPT_ParseTree pt)
{
  PTPT_Tree tree = PTPT_getParseTreeTop(pt);
  PTPT_NatCon ambCnt = PTPT_getParseTreeAmbCnt(pt);

  return PT_makeParseTreeTop(PTPT_lowerTree(tree), PTPT_lowerNatCon(ambCnt));
}

/*}}}  */
