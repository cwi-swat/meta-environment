#include "PTMEPT-utils.h"
#include "PTMEPT.h"
#include <MEPT-utils.h>
#include <assert.h>

static PTPT_OptLayout e = NULL;

/*{{{  static void initEmptyLayout()  */

static void initEmptyLayout() 
{
  if (e == NULL) {
    e = PTPT_makeOptLayoutAbsent();
    ATprotect((ATerm*) &e);
  }
}

/*}}}  */

/*{{{  static PTPT_NatCon   PTPT_explodeNatCon(int val) */

static PTPT_NatCon   PTPT_explodeNatCon(int val)
{
  static char string[1024];
  sprintf(string, "%d", val);
  return PTPT_makeNatConDefault(PTPT_makeCHARLISTString(string));
}

/*}}}  */
/*{{{  static PTPT_IntCon   PTPT_explodeIntCon(int val) */

static PTPT_IntCon   PTPT_explodeIntCon(int val)
{
  if (val >= 0) {
    return PTPT_makeIntConNat(PTPT_explodeNatCon(val));
  }
  else {
    return PTPT_makeIntConMinus(e,PTPT_explodeNatCon(-val));
  }
}

/*}}}  */
/*{{{  static PTPT_IntCon   PTPT_explodeIntCon(int val) */

static PTPT_IntCon   PTPT_explodeRealCon(double val)
{
  ATerror("explode: reals not implemented!\n");
  return NULL;
}

/*}}}  */
/*{{{  static PTPT_Literal PTPT_explodeLiteral(char *string) */

static PTPT_Literal PTPT_explodeLiteral(char *string, ATbool quoted)
{
  if (quoted) {
    char quoted[1024];
    sprintf(quoted, "\"%s\"", string);
    return PTPT_makeLiteralQuoted(PTPT_makeCHARLISTString(quoted));
  }

  return PTPT_makeLiteralUnquoted(PTPT_makeUQLiteralMany(
			       PTPT_makeCHARLISTString(string)));
}

/*}}}  */

/*{{{  static PTPT_ATermList PTPT_explodeATermList(ATermList elems) */

static PTPT_ATermList PTPT_explodeATermList(ATermList elems)
{
  PTPT_ATermElems list = PTPT_makeATermElemsEmpty();

  for(;!ATisEmpty(elems); elems = ATgetNext(elems)) 
  {
    PTPT_ATerm head = PTPT_explodeATerm(ATgetFirst(elems));

    if (!PTPT_isATermElemsEmpty(list)) {
      list = PTPT_makeATermElemsMany(head,e,",",e,list);
    }
    else {
      list = PTPT_makeATermElemsSingle(head);
    }
  }

  return  PTPT_makeATermListList(e,PTPT_reverseATermElems(list),e);
}

/*}}}  */
/*{{{  static PTPT_Ann PTPT_explodeAnnotations(ATermList annos) */

static PTPT_Ann PTPT_explodeAnnotations(ATermList annos)
{
  PTPT_ATermList ptlist = PTPT_explodeATermList(annos);
  PTPT_ATermElems elems = PTPT_getATermListElems(ptlist);
  
  return PTPT_makeAnnList(e,elems,e);
}

/*}}}  */
/*{{{  static PTPT_ATerm PTPT_explodeATermAppl(ATermAppl appl) */

static PTPT_ATerm PTPT_explodeATermAppl(ATermAppl appl)
{
  ATerm annos = AT_getAnnotations((ATerm) appl);
  AFun fun = ATgetAFun(appl);
  char *name = ATgetName(fun);
  int arity = ATgetArity(fun);
  ATermList args = ATgetArguments(appl);
  PTPT_ATerm result = NULL;
  PTPT_AFun pfun = PTPT_makeAFunLit(PTPT_explodeLiteral(name, ATisQuoted(fun)));
  PTPT_Ann ann = NULL;

  if (annos != NULL) {
    ann = PTPT_explodeAnnotations((ATermList) annos);
  }

  if (arity == 0) {
    if (ann != NULL) {
      result = PTPT_makeATermAnnotatedConstant(pfun, e, ann);
    }
    else {
      result = PTPT_makeATermConstant(pfun);
    }
  }
  else {
    /* hack alert, PTPT_ATermArgs is the same as an ATermList by coincidence */
    PTPT_ATermArgs pargs  = 
      (PTPT_ATermArgs) PTPT_getATermListElems(PTPT_explodeATermList(args));

    if (ann != NULL) {
      result = PTPT_makeATermAnnotatedAppl(pfun,e,e,pargs,e,e,ann);
    }
    else {
      result = PTPT_makeATermAppl(pfun,e,e,pargs,e);
    }
  }

  return result;
}

/*}}}  */

/*{{{  PTPT_ATerm PTPT_explodeATerm(ATerm term) */

PTPT_ATerm PTPT_explodeATerm(ATerm term)
{
  PTPT_ATerm result = NULL;
  ATerm annos = AT_getAnnotations(term);
  PTPT_Ann ann = NULL;

  if (annos != NULL) {
    ann = PTPT_explodeAnnotations((ATermList) annos);
  }

  initEmptyLayout();

  if (ATgetType(term) == AT_LIST) {
    PTPT_ATermList list = PTPT_explodeATermList((ATermList) term);

    if (ann != NULL) {
      result = PTPT_makeATermAnnotatedList(list,e,ann);
    }
    else {
      result = PTPT_makeATermList(list);
    }
  }
  else if (ATgetType(term) == AT_APPL) {
    result = PTPT_explodeATermAppl((ATermAppl) term);
  }
  else if (ATgetType(term) == AT_PLACEHOLDER) {
    PTPT_ATerm type = 
      PTPT_explodeATerm(ATgetPlaceholder((ATermPlaceholder) term));
    result = PTPT_makeATermPlaceholder(e,type,e);
  }
  else if (ATgetType(term) == AT_INT) {
    int nat = ATgetInt((ATermInt) term);
    PTPT_ACon con = PTPT_makeAConInt(PTPT_explodeIntCon(nat));

    if (ann != NULL) {
      result = PTPT_makeATermAnnotatedAconstant(con,e,ann);
    }
    else {
      result = PTPT_makeATermAconstant(con);
    }
  }
  else if (ATgetType(term) == AT_REAL) {
    double real = ATgetInt((ATermInt) term);
    PTPT_ACon con = PTPT_makeAConInt(PTPT_explodeRealCon(real));
    
    if (ann != NULL) {
      result = PTPT_makeATermAnnotatedAconstant(con,e,ann);
    }
    else {
      result = PTPT_makeATermAconstant(con);
    }
  }
  else {
    ATwarning("explode: unsupported ATerm %t\n", term);
  }

  return result;
}

/*}}}  */

/*{{{  static PTPT_CharRanges PTPT_explodeCharRanges(PT_CharRanges symbols) */

static PTPT_CharRange PTPT_explodeCharRange(PT_CharRange symbol);
static PTPT_CharRanges PTPT_explodeCharRanges(PT_CharRanges symbols)
{
  PTPT_CharRangeList list = PTPT_makeCharRangeListEmpty();

  for(;!PT_isCharRangesEmpty(symbols); symbols = PT_getCharRangesTail(symbols)) 
  {
    PTPT_CharRange head = PTPT_explodeCharRange(PT_getCharRangesHead(symbols));
    if (!PTPT_isCharRangeListEmpty(list)) {
      list = PTPT_makeCharRangeListMany(head,e,",",e,list);
    }
    else {
      list = PTPT_makeCharRangeListSingle(head);
    }
  }

  return PTPT_makeCharRangesList(e,PTPT_reverseCharRangeList(list),e);
}

/*}}}  */
/*{{{  static PTPT_Symbols PTPT_explodeSymbols(PT_Symbols symbols) */

static PTPT_Symbol PTPT_explodeSymbol(PT_Symbol symbol);
static PTPT_Symbols PTPT_explodeSymbols(PT_Symbols symbols)
{
  PTPT_SymbolList list = PTPT_makeSymbolListEmpty();

  for(;!PT_isSymbolsEmpty(symbols); symbols = PT_getSymbolsTail(symbols)) {
    PTPT_Symbol head = PTPT_explodeSymbol(PT_getSymbolsHead(symbols));
    if (!PTPT_isSymbolListEmpty(list)) {
      list = PTPT_makeSymbolListMany(head,e,",",e,list);
    }
    else {
      list = PTPT_makeSymbolListSingle(head);
    }
  }

  return PTPT_makeSymbolsList(e,PTPT_reverseSymbolList(list),e);
}

/*}}}  */
/*{{{  static PTPT_Attrs PTPT_explodeAttrs(PT_Attrs symbols) */

static PTPT_Attr PTPT_explodeAttr(PT_Attr attr);
static PTPT_Attrs PTPT_explodeAttrs(PT_Attrs attrs)
{
  PTPT_AttrList list = NULL;

  for(;PT_hasAttrsHead(attrs); attrs = PT_getAttrsTail(attrs)) {
    PTPT_Attr head = PTPT_explodeAttr(PT_getAttrsHead(attrs));
    if (list != NULL) {
      list = PTPT_makeAttrListMany(head,e,",",e,list);
    }
    else {
      list = PTPT_makeAttrListSingle(head);
    }

    if (!PT_hasAttrsTail(attrs)) {
      break;
    }
  }

  return PTPT_makeAttrsMany(e,PTPT_reverseAttrList(list),e);
}

/*}}}  */
/*{{{  static PTPT_Symbol PTPT_explodeSymbol(PT_Symbol symbol) */

static PTPT_Symbol PTPT_explodeSymbol(PT_Symbol symbol)
{
  PTPT_Symbol result = NULL;

  initEmptyLayout();

  if (PT_isSymbolLit(symbol)) {
    PTPT_Literal lit = PTPT_explodeLiteral(PT_getSymbolString(symbol), ATtrue);
    result = PTPT_makeSymbolLit(e,e,lit,e);
  }
  else if (PT_isSymbolCf(symbol)) {
    PTPT_Symbol new = PTPT_explodeSymbol(PT_getSymbolSymbol(symbol));
    result = PTPT_makeSymbolCf(e,e,new,e);
  }
  else if (PT_isSymbolLex(symbol)) {
    PTPT_Symbol new = PTPT_explodeSymbol(PT_getSymbolSymbol(symbol));
    result = PTPT_makeSymbolLex(e,e,new,e);
  }
  else if (PT_isSymbolEmpty(symbol)) {
    result = PTPT_makeSymbolEmpty();
  }
  else if (PT_isSymbolSeq(symbol)) {
    PTPT_Symbol lhs = PTPT_explodeSymbol(PT_getSymbolLhs(symbol));
    PTPT_Symbol rhs = PTPT_explodeSymbol(PT_getSymbolRhs(symbol));
    result = PTPT_makeSymbolSeq(e,e,lhs,e,e,rhs,e);
  }
  else if (PT_isSymbolOpt(symbol)) {
    PTPT_Symbol new = PTPT_explodeSymbol(PT_getSymbolSymbol(symbol));
    result = PTPT_makeSymbolOpt(e,e,new,e);
  }
  else if (PT_isSymbolAlt(symbol)) {
    PTPT_Symbol lhs = PTPT_explodeSymbol(PT_getSymbolLhs(symbol));
    PTPT_Symbol rhs = PTPT_explodeSymbol(PT_getSymbolRhs(symbol));
    result = PTPT_makeSymbolAlt(e,e,lhs,e,e,rhs,e);
  }
  else if (PT_isSymbolPair(symbol)) {
    PTPT_Symbol lhs = PTPT_explodeSymbol(PT_getSymbolLhs(symbol));
    PTPT_Symbol rhs = PTPT_explodeSymbol(PT_getSymbolRhs(symbol));
    result = PTPT_makeSymbolPair(e,e,lhs,e,e,rhs,e);
  }
  else if (PT_isSymbolSort(symbol)) {
    PTPT_Literal lit = PTPT_explodeLiteral(PT_getSymbolString(symbol), ATtrue);
    result = PTPT_makeSymbolSort(e,e,lit,e);
  }
  else if (PT_isSymbolIterPlus(symbol)) {
    PTPT_Symbol new = PTPT_explodeSymbol(PT_getSymbolSymbol(symbol));
    result = PTPT_makeSymbolIter(e,e,new,e);
  }
  else if (PT_isSymbolIterStar(symbol)) {
    PTPT_Symbol new = PTPT_explodeSymbol(PT_getSymbolSymbol(symbol));
    result = PTPT_makeSymbolIterStar(e,e,new,e);
  }
  else if (PT_isSymbolIterPlusSep(symbol)) {
    PTPT_Symbol sym = PTPT_explodeSymbol(PT_getSymbolSymbol(symbol));
    PTPT_Symbol sep = PTPT_explodeSymbol(PT_getSymbolSeparator(symbol));
    result = PTPT_makeSymbolIterSep(e,e,sym,e,e,sep,e);
  }
  else if (PT_isSymbolIterStarSep(symbol)) {
    PTPT_Symbol sym = PTPT_explodeSymbol(PT_getSymbolSymbol(symbol));
    PTPT_Symbol sep = PTPT_explodeSymbol(PT_getSymbolSeparator(symbol));
    result = PTPT_makeSymbolIterStarSep(e,e,sym,e,e,sep,e);
  }
  else if (PT_isSymbolIterN(symbol)) {
    PTPT_Symbol sym = PTPT_explodeSymbol(PT_getSymbolSymbol(symbol));
    PTPT_NatCon num = PTPT_explodeNatCon(PT_getSymbolNumber(symbol));
    result = PTPT_makeSymbolIterN(e,e,sym,e,e,num,e);
  }
  else if (PT_isSymbolIterSepN(symbol)) {
    PTPT_Symbol sym = PTPT_explodeSymbol(PT_getSymbolSymbol(symbol));
    PTPT_Symbol sep = PTPT_explodeSymbol(PT_getSymbolSeparator(symbol));
    PTPT_NatCon num = PTPT_explodeNatCon(PT_getSymbolNumber(symbol));
    result = PTPT_makeSymbolIterSepN(e,e,sym,e,e,sep,e,e,num,e);
  }
  else if (PT_isSymbolPerm(symbol)) {
    PTPT_Symbols syms = PTPT_explodeSymbols(PT_getSymbolSymbols(symbol));
    result = PTPT_makeSymbolPerm(e,e,syms,e);
  }
  else if (PT_isSymbolSet(symbol)) {
    PTPT_Symbol sym = PTPT_explodeSymbol(PT_getSymbolSymbol(symbol));
    result = PTPT_makeSymbolSet(e,e,sym,e);
  }
  else if (PT_isSymbolFunc(symbol)) {
    PTPT_Symbols syms = PTPT_explodeSymbols(PT_getSymbolSymbols(symbol));
    PTPT_Symbol sym = PTPT_explodeSymbol(PT_getSymbolSymbol(symbol));
    result = PTPT_makeSymbolFunc(e,e,syms,e,e,sym,e);
  }
  else if (PT_isSymbolParameterizedSort(symbol)) {
    PTPT_Literal lit = PTPT_explodeLiteral(PT_getSymbolSort(symbol), ATtrue);
    PTPT_Symbols syms = PTPT_explodeSymbols(PT_getSymbolParameters(symbol));
    result = PTPT_makeSymbolParametrizedSort(e,e,lit,e,e,syms,e);
  }
  else if (PT_isSymbolStrategy(symbol)) {
    PTPT_Symbol lhs = PTPT_explodeSymbol(PT_getSymbolLhs(symbol));
    PTPT_Symbol rhs = PTPT_explodeSymbol(PT_getSymbolRhs(symbol));
    result = PTPT_makeSymbolStrategy(e,e,lhs,e,e,rhs,e);
  }
  else if (PT_isSymbolVarSym(symbol)) {
    PTPT_Symbol new = PTPT_explodeSymbol(PT_getSymbolSymbol(symbol));
    result = PTPT_makeSymbolVarsym(e,e,new,e);
  }
  else if (PT_isSymbolLayout(symbol)) {
    result = PTPT_makeSymbolLayout();
  }
  else if (PT_isSymbolCharClass(symbol)) {
    PTPT_CharRanges ranges = PTPT_explodeCharRanges(PT_getSymbolRanges(symbol));
    result = PTPT_makeSymbolCharClass(e,e,ranges,e);
  }
  else {
    ATwarning("explode: unknown symbol %t\n", symbol);
  }
 
  return result;
}

/*}}}  */
/*{{{  static PTPT_CharRange PTPT_explodeCharRange(PT_CharRange range) */

static PTPT_CharRange PTPT_explodeCharRange(PT_CharRange range)
{
  PTPT_CharRange result = NULL;

  if (PT_isCharRangeCharacter(range)) {
    PTPT_NatCon nat = PTPT_explodeNatCon(PT_getCharRangeInteger(range));
    result = PTPT_makeCharRangeCharacter(nat);
  }
  else if (PT_isCharRangeRange(range)) {
    PTPT_NatCon start = PTPT_explodeNatCon(PT_getCharRangeStart(range));
    PTPT_NatCon end = PTPT_explodeNatCon(PT_getCharRangeEnd(range));
    result = PTPT_makeCharRangeRange(e,e,start,e,e,end,e);
  }
  else {
    ATwarning("explode: unknown charrange %t\n", range);
  }

  return result;
}

/*}}}  */
/*{{{  static PTPT_Associativity PTPT_explodeAssociativity(PT_Associativity assoc) */

static PTPT_Associativity PTPT_explodeAssociativity(PT_Associativity assoc)
{
  PTPT_Associativity result = NULL;

  if (PT_isAssociativityLeft(assoc)) {
    result = PTPT_makeAssociativityLeft();
  }
  else if (PT_isAssociativityRight(assoc)) {
    result = PTPT_makeAssociativityRight();
  }
  else if (PT_isAssociativityAssoc(assoc)) {
    result = PTPT_makeAssociativityAssoc();
  }
  else if (PT_isAssociativityNonAssoc(assoc)) {
    result = PTPT_makeAssociativityNonAssoc();
  }
  else {
    ATwarning("explode: unknown associativity %t\n", assoc);
  }

  return result;
}

/*}}}  */
/*{{{  static PTPT_Attr PTPT_explodeAttr(PT_Attr attr) */

static PTPT_Attr PTPT_explodeAttr(PT_Attr attr)
{
  PTPT_Attr result = NULL;

  if (PT_isAttrAssoc(attr)) {
    PTPT_Associativity assoc = PTPT_explodeAssociativity(PT_getAttrAssoc(attr));
    result = PTPT_makeAttrAssoc(e,e,assoc,e);
  }
  else if (PT_isAttrTerm(attr)) {
    PTPT_ATerm term = PTPT_explodeATerm(PT_getAttrTerm(attr));
    result = PTPT_makeAttrTerm(e,e,term,e);
  }
  else if (PT_isAttrId(attr)) {
    PTPT_Literal id = PTPT_explodeLiteral(PT_getAttrModuleName(attr), ATtrue);
    result = PTPT_makeAttrId(e,e,id,e);
  }
  else if (PT_isAttrBracket(attr)) {
    result = PTPT_makeAttrBracket();
  }
  else if (PT_isAttrReject(attr)) {
    result = PTPT_makeAttrReject();
  }
  else if (PT_isAttrPrefer(attr)) {
    result = PTPT_makeAttrPrefer();
  }
  else if (PT_isAttrAvoid(attr)) {
    result = PTPT_makeAttrAvoid();
  }
  else {
    ATwarning("explode: unknown attr %t\n", attr);
  }

  return result;
}

/*}}}  */

/*{{{  static PTPT_Attributes PTPT_explodeAttributes(PT_Attributes attributes) */

static PTPT_Attributes PTPT_explodeAttributes(PT_Attributes attributes)
{
  PTPT_Attributes result = NULL;

  if (PT_isAttributesNoAttrs(attributes)) {
    result = PTPT_makeAttributesNoAttrs();
  }
  else if (PT_isAttributesAttrs(attributes)) {
    PTPT_Attrs attrs = PTPT_explodeAttrs(PT_getAttributesAttrs(attributes));
    result = PTPT_makeAttributesAttrs(e,e,attrs,e);
  }
  else {
    ATwarning("explode: unknown attributes: %t\n", attributes);
  }

  return result;
}

/*}}}  */

/*{{{  static PTPT_Production PTPT_explodeProd(PT_Production prod) */

static PTPT_Production PTPT_explodeProd(PT_Production prod)
{
  PTPT_Production result = NULL;

  if (PT_isProductionDefault(prod)) {
    PTPT_Symbols lhs;
    PTPT_Symbol  rhs;
    PTPT_Attributes attrs;

    lhs = PTPT_explodeSymbols(PT_getProductionLhs(prod));
    rhs  = PTPT_explodeSymbol(PT_getProductionRhs(prod));
    attrs = PTPT_explodeAttributes(PT_getProductionAttributes(prod));
    result = PTPT_makeProductionDefault(e,e,lhs,e,e,rhs,e,e,attrs,e);
  }
  else if (PT_isProductionList(prod)) {
    PTPT_Symbol  rhs  = PTPT_explodeSymbol(PT_getProductionRhs(prod));

    result = PTPT_makeProductionList(e,e,rhs,e);
  }
  else {
    ATwarning("explode: unknown production %t\n", prod);
  }

  return result;
}

/*}}}  */
/*{{{  static PTPT_Args PTPT_explodeArgs(PT_Args args)  */

static PTPT_Args PTPT_explodeArgs(PT_Args args) 
{
  PTPT_TreeList list = PTPT_makeTreeListEmpty();

  for(;!PT_isArgsEmpty(args); args = PT_getArgsTail(args)) {
    PTPT_Tree head = PTPT_explodeTree(PT_getArgsHead(args));
    if (!PTPT_isTreeListEmpty(list)) {
      list = PTPT_makeTreeListMany(head,e,",",e,list);
    }
    else {
      list = PTPT_makeTreeListSingle(head);
    }
  }

  return PTPT_makeArgsList(e,PTPT_reverseTreeList(list),e);
}

/*}}}  */


/*{{{  PT_Tree PTPT_explodeTree(PT_Tree pt) */

PTPT_Tree PTPT_explodeTree(PT_Tree pt)
{
  PTPT_Tree result = NULL;
  ATerm annos = NULL;

  initEmptyLayout();

  if (PT_isTreeAmb(pt)) {
    PT_Args args = PT_getTreeArgs(pt);

    result = PTPT_makeTreeAmb(e,e, PTPT_explodeArgs(args),e);
  }
  else if (PT_isTreeAppl(pt)) {
    PTPT_Production prod;
    PTPT_Args args;

    prod = PTPT_explodeProd(PT_getTreeProd(pt));
    args = PTPT_explodeArgs(PT_getTreeArgs(pt));

    result = PTPT_makeTreeAppl(e,e,prod,e,e,args,e);
  }
  else if (PT_isTreeLit(pt)) {
    PTPT_Literal lit = PTPT_explodeLiteral(PT_getTreeString(pt), ATtrue);
    result = PTPT_makeTreeLit(e,e,lit,e);
  }
  else if (PT_isTreeChar(pt)) {
    int val = PT_getTreeCharacter(pt);
    result = PTPT_makeTreeChar(PTPT_explodeNatCon(val));
  }
  else {
    ATwarning("explode: unknown term %t\n", pt);
  }

  if ((annos = PT_getTreeAnnotations(pt)) != NULL) {
    PTPT_Ann ann = PTPT_explodeAnnotations((ATermList) annos);

    result = PTPT_makeTreeAnnotated(result,e,ann);
  }

  return result;
}

/*}}}  */
/*{{{  PT_ParseTree PTPT_explodeParseTree(PT_ParseTree pt)  */

PTPT_ParseTree PTPT_explodeParseTree(PT_ParseTree pt) 
{
  PT_Tree tree = PT_getParseTreeTop(pt);
  int ambCnt = PT_getParseTreeAmbCnt(pt);

  initEmptyLayout();

  return PTPT_makeParseTreeTop(e,e,
			       (PTPT_Tree) PTPT_explodeTree(tree),
			       e,e,
			       PTPT_explodeNatCon(ambCnt),
			       e);

}

/*}}}  */
