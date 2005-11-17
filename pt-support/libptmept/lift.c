#include "PTMEPT-utils.h"
#include "PTMEPT.h"
#include <MEPT-utils.h>
#include <assert.h>
#include <ctype.h>

static PTPT_OptLayout e = NULL;
static ATermTable liftCache = NULL;
static ATermTable lowerCache = NULL;

/*{{{  static void initGlobals()  */

static void initGlobals(ATermTable myLowerCache) 
{
  lowerCache = myLowerCache;

  if (e == NULL) {
    PTPT_protectOptLayout(&e);
    e = PTPT_makeOptLayoutAbsent();
    liftCache = ATtableCreate(1024, 75);
  }
}

/*}}}  */
/*{{{  static void storeTree(PT_Tree tree, PTPT_Tree lifted)  */

static void storeTree(PT_Tree tree, PTPT_Tree lifted) 
{
  ATtablePut(liftCache, PT_TreeToTerm(tree), PTPT_TreeToTerm(lifted));

  if (lowerCache) {
    ATtablePut(lowerCache, PTPT_TreeToTerm(lifted), PT_TreeToTerm(tree));
  }
}

/*}}}  */
/*{{{  static PTPT_Tree lookupTree(PT_Tree tree) */

static PTPT_Tree lookupTree(PT_Tree tree)
{
  return PTPT_TreeFromTerm(ATtableGet(liftCache, PT_TreeToTerm(tree)));
}

/*}}}  */
/*{{{  static void storeSymbol(PT_Symbol symbol, PTPT_Symbol lifted)  */

static void storeSymbol(PT_Symbol symbol, PTPT_Symbol lifted) 
{
  ATtablePut(liftCache, PT_SymbolToTerm(symbol), PTPT_SymbolToTerm(lifted));

  if (lowerCache) {
    ATtablePut(lowerCache, PTPT_SymbolToTerm(lifted), PT_SymbolToTerm(symbol));
  }
}

/*}}}  */
/*{{{  static PTPT_Symbol lookupSymbol(PT_Symbol symbol) */

static PTPT_Symbol lookupSymbol(PT_Symbol symbol)
{
  return PTPT_SymbolFromTerm(ATtableGet(liftCache, PT_SymbolToTerm(symbol)));
}

/*}}}  */
/*{{{  static void storeATerm(PT_ATerm symbol, PTPT_ATerm lifted)  */

static void storeATerm(ATerm trm, PTPT_ATerm lifted) 
{
  ATtablePut(liftCache, trm, PTPT_ATermToTerm(lifted));

  if (lowerCache) {
    ATtablePut(lowerCache, PTPT_ATermToTerm(lifted), trm);
  }

}

/*}}}  */
/*{{{  static PTPT_ATerm lookupATerm(PT_ATerm symbol) */

static PTPT_ATerm lookupATerm(ATerm trm)
{
  return PTPT_ATermFromTerm(ATtableGet(liftCache, trm));
}

/*}}}  */

/*{{{  PTPT_LexStrCon PTPT_makeLexStrCon(const char* str) */

PTPT_LexStrCon PTPT_makeLexStrCon(const char* str)
{
  int len = strlen(str);
  int i;
  PTPT_LexStrCharChars list = PTPT_makeLexStrCharCharsEmpty();

  for (i = len - 1; i >= 0; i--) {
    PTPT_LexStrChar ch;

    switch(str[i]) {
      case '\n':
	ch = PTPT_makeLexStrCharNewline();
	break;
      case '\t':
	ch = PTPT_makeLexStrCharTab();
	break;
      case '"':
	ch = PTPT_makeLexStrCharQuote();
	break;
      case '\\':
	ch = PTPT_makeLexStrCharBackslash();
	break;
      default:
	if (isprint((int) str[i])) {
	  ch = PTPT_makeLexStrCharNormal(str[i]);
	}
	else {
	  int value = str[i];
	  int a, b, c;

	  c = value % 10;
	  value /= 10;
	  b = value % 10;
	  value /= 10;
	  a = value;

	  ch = PTPT_makeLexStrCharDecimal(a,b,c);
	}
    }

    list = PTPT_makeLexStrCharCharsMany(ch, list);
  }


  return PTPT_makeLexStrConDefault(list);
}

/*}}}  */
/*{{{  PTPT_QLiteral PTPT_makeQLiteral(const char *str)  */

PTPT_StrCon PTPT_makeStrCon(const char *str) 
{
  return PTPT_makeStrConLexToCf(PTPT_makeLexStrCon(str));
}

/*}}}  */

static PTPT_Tree PTPT_liftTreeRec(PT_Tree tree);

/*{{{  PTPT_NatCon   PTPT_liftNatCon(int val) */

PTPT_NatCon   PTPT_liftNatCon(int val)
{
  static char string[1024];
  sprintf(string, "%d", val);
  return PTPT_makeNatConLexToCf(PTPT_makeLexNatConDigits(string));
}

/*}}}  */
/*{{{  static PTPT_IntCon   PTPT_liftIntCon(int val) */

static PTPT_IntCon   PTPT_liftIntCon(int val)
{
  if (val >= 0) {
    return PTPT_makeIntConNatural(PTPT_liftNatCon(val));
  }
  else {
    return PTPT_makeIntConNegative(e,PTPT_liftNatCon(-val));
  }
}

/*}}}  */
/*{{{  static PTPT_IntCon   PTPT_liftIntCon(int val) */

static PTPT_RealCon   PTPT_liftRealCon(double val)
{
  ATerror("lift: reals not implemented!\n");
  return NULL;
}

/*}}}  */
/*{{{  static PTPT_QLiteral PTPT_liftQLiteral(char *string) */

static PTPT_StrCon PTPT_liftStrCon(char *string)
{
  return PTPT_makeStrCon(string);
}

/*}}}  */
/*{{{  static PTPT_UQLiteral PTPT_liftUQLiteral(const char *string) */

static PTPT_IdCon PTPT_liftIdCon(const char *string)
{
  PTPT_LexIdCon lit;

  if (strlen(string) > 1) {
    lit = PTPT_makeLexIdConDefault(string[0], string+1);
  }
  else {
    lit = PTPT_makeLexIdConDefault(string[0], "");
  }

  return PTPT_makeIdConLexToCf(lit);
}

/*}}}  */

/*{{{  static PTPT_ATermList PTPT_liftATermList(ATermList elems) */

static PTPT_ATerm PTPT_liftATermList(ATermList elems)
{
  PTPT_ATermElems list = PTPT_makeATermElemsEmpty();

  for(;!ATisEmpty(elems); elems = ATgetNext(elems)) 
  {
    PTPT_ATerm head = PTPT_liftATerm(ATgetFirst(elems));

    if (!PTPT_isATermElemsEmpty(list)) {
      list = PTPT_makeATermElemsMany(head, e, e, list);
    }
    else {
      list = PTPT_makeATermElemsSingle(head);
    }
  }

  return  PTPT_makeATermList(e,PTPT_reverseATermElems(list),e);
}

/*}}}  */
/*{{{  static PTPT_Ann PTPT_liftAnnotations(ATermList annos) */

static PTPT_Annotation PTPT_liftAnnotations(ATermList annos)
{
  PTPT_ATerm ptlist = PTPT_liftATermList(annos);
  PTPT_ATermAnnos elems = (PTPT_ATermAnnos)PTPT_getATermElems(ptlist);
  
  return PTPT_makeAnnotationDefault(e,elems,e);
}

/*}}}  */
/*{{{  static PTPT_ATerm PTPT_liftATermAppl(ATermAppl appl) */

static PTPT_ATerm PTPT_liftATermAppl(ATermAppl appl)
{
  AFun fun = ATgetAFun(appl);
  char *name = ATgetName(fun);
  int arity = ATgetArity(fun);
  ATermList args = ATgetArguments(appl);
  PTPT_ATerm result = NULL;
  PTPT_AFun pfun;

  if (ATisQuoted(fun)) {
    pfun = PTPT_makeAFunQuoted(PTPT_liftStrCon(name));
  }
  else {
    pfun = PTPT_makeAFunUnquoted(PTPT_liftIdCon(name));
  }

  if (arity == 0) {
    result = PTPT_makeATermFun(pfun);
  }
  else {
    /* hack alert, PTPT_ATermArgs is the same as an ATermList by coincidence */
    PTPT_ATermArgs pargs  = 
      (PTPT_ATermArgs) PTPT_getATermElems(PTPT_liftATermList(args));

    result = PTPT_makeATermAppl(pfun,e,e,pargs,e);
  }

  return result;
}

/*}}}  */

/*{{{  PTPT_ATerm PTPT_liftATerm(ATerm term) */

PTPT_ATerm PTPT_liftATerm(ATerm term)
{
  PTPT_ATerm result = NULL;
  ATerm annos = AT_getAnnotations(term);
  PTPT_Annotation ann = NULL;

  initGlobals(NULL);

  if (ATgetType(term) != AT_INT) {
    result = lookupATerm(term);
    if (result) {
      return result;
    }
  }

  if (annos != NULL) {
    ann = PTPT_liftAnnotations((ATermList) annos);
  }

  if (ATgetType(term) == AT_LIST) {
    result = PTPT_liftATermList((ATermList) term);
  }
  else if (ATgetType(term) == AT_APPL) {
    result = PTPT_liftATermAppl((ATermAppl) term);
  }
  else if (ATgetType(term) == AT_INT) {
    int nat = ATgetInt((ATermInt) term);
    result = PTPT_makeATermInt(PTPT_liftIntCon(nat));
  }
  else if (ATgetType(term) == AT_REAL) {
    double real = ATgetInt((ATermInt) term);
    result = PTPT_makeATermReal(PTPT_liftRealCon(real));
  }
  else if (ATgetType(term) == AT_PLACEHOLDER) {
    PTPT_ATerm ph = PTPT_liftATerm(ATgetPlaceholder((ATermPlaceholder) term));
    result = PTPT_makeATermPlaceholder(e, ph, e);
  }
  else {
    ATwarning("lift: unsupported ATerm %t\n", term);
    assert(ATfalse);
  }

  if (ann != NULL) {
    result = PTPT_makeATermAnnotated(result, e, ann);
  }

  /* otherwise we map AsFix characters onto ATerm ints and vice versa */
  if (ATgetType(term) != AT_INT) {
    storeATerm(term, result);
  }

  return result;
}

/*}}}  */

/*{{{  static PTPT_CharRanges PTPT_liftCharRanges(PT_CharRanges symbols) */

static PTPT_CharRange PTPT_liftCharRange(PT_CharRange symbol);
static PTPT_CharRanges PTPT_liftCharRanges(PT_CharRanges symbols)
{
  PTPT_CharRangeList list = PTPT_makeCharRangeListEmpty();

  for(;!PT_isCharRangesEmpty(symbols); symbols = PT_getCharRangesTail(symbols)) 
  {
    PTPT_CharRange head = PTPT_liftCharRange(PT_getCharRangesHead(symbols));
    if (!PTPT_isCharRangeListEmpty(list)) {
      list = PTPT_makeCharRangeListMany(head, e, e, list);
    }
    else {
      list = PTPT_makeCharRangeListSingle(head);
    }
  }

  return PTPT_makeCharRangesList(e,PTPT_reverseCharRangeList(list),e);
}

/*}}}  */
/*{{{  static PTPT_Symbols PTPT_liftSymbols(PT_Symbols symbols) */

static PTPT_Symbol PTPT_liftSymbol(PT_Symbol symbol);
static PTPT_Symbols PTPT_liftSymbols(PT_Symbols symbols)
{
  PTPT_SymbolList list = PTPT_makeSymbolListEmpty();

  for(;!PT_isSymbolsEmpty(symbols); symbols = PT_getSymbolsTail(symbols)) {
    PTPT_Symbol head = PTPT_liftSymbol(PT_getSymbolsHead(symbols));
    if (!PTPT_isSymbolListEmpty(list)) {
      list = PTPT_makeSymbolListMany(head, e, e, list);
    }
    else {
      list = PTPT_makeSymbolListSingle(head);
    }
  }

  return PTPT_makeSymbolsList(e, PTPT_reverseSymbolList(list), e);
}

/*}}}  */
/*{{{  static PTPT_Attrs PTPT_liftAttrs(PT_Attrs symbols) */

static PTPT_Attr PTPT_liftAttr(PT_Attr attr);
static PTPT_Attrs PTPT_liftAttrs(PT_Attrs attrs)
{
  PTPT_AttrList list = NULL;

  for(;PT_hasAttrsHead(attrs); attrs = PT_getAttrsTail(attrs)) {
    PTPT_Attr head = PTPT_liftAttr(PT_getAttrsHead(attrs));
    if (list != NULL) {
      list = PTPT_makeAttrListMany(head,e,e,list);
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
/*{{{  static PTPT_Symbol PTPT_liftSymbol(PT_Symbol symbol) */

static PTPT_Symbol PTPT_liftSymbol(PT_Symbol symbol)
{
  PTPT_Symbol result = NULL;

  result = lookupSymbol(symbol);
  if (result != NULL) {
    return result;
  }

  if (PT_isSymbolLit(symbol)) {
    PTPT_StrCon lit = PTPT_liftStrCon(PT_getSymbolString(symbol));
    result = PTPT_makeSymbolLit(e,e,lit,e);
  }
  else if (PT_isSymbolCilit(symbol)) {
    PTPT_StrCon lit = PTPT_liftStrCon(PT_getSymbolString(symbol));
    result = PTPT_makeSymbolCilit(e,e,lit,e);
  }
  else if (PT_isSymbolCf(symbol)) {
    PTPT_Symbol new = PTPT_liftSymbol(PT_getSymbolSymbol(symbol));
    result = PTPT_makeSymbolCf(e,e,new,e);
  }
  else if (PT_isSymbolLex(symbol)) {
    PTPT_Symbol new = PTPT_liftSymbol(PT_getSymbolSymbol(symbol));
    result = PTPT_makeSymbolLex(e,e,new,e);
  }
  else if (PT_isSymbolEmpty(symbol)) {
    result = PTPT_makeSymbolEmpty();
  }
  else if (PT_isSymbolSeq(symbol)) {
    PTPT_Symbols syms = PTPT_liftSymbols(PT_getSymbolSymbols(symbol));
    result = PTPT_makeSymbolSeq(e,e,syms,e);
  }
  else if (PT_isSymbolOpt(symbol)) {
    PTPT_Symbol new = PTPT_liftSymbol(PT_getSymbolSymbol(symbol));
    result = PTPT_makeSymbolOpt(e,e,new,e);
  }
  else if (PT_isSymbolAlt(symbol)) {
    PTPT_Symbol lhs = PTPT_liftSymbol(PT_getSymbolLhs(symbol));
    PTPT_Symbol rhs = PTPT_liftSymbol(PT_getSymbolRhs(symbol));
    result = PTPT_makeSymbolAlt(e,e,lhs,e,e,rhs,e);
  }
  else if (PT_isSymbolTuple(symbol)) {
    PTPT_Symbol head = PTPT_liftSymbol(PT_getSymbolHead(symbol));
    PTPT_Symbols rest = PTPT_liftSymbols(PT_getSymbolRest(symbol));
    result = PTPT_makeSymbolTuple(e,e,head,e,e,rest,e);
  }
  else if (PT_isSymbolSort(symbol)) {
    PTPT_StrCon lit = PTPT_liftStrCon(PT_getSymbolString(symbol));
    result = PTPT_makeSymbolSort(e,e,lit,e);
  }
  else if (PT_isSymbolIterPlus(symbol)) {
    PTPT_Symbol new = PTPT_liftSymbol(PT_getSymbolSymbol(symbol));
    result = PTPT_makeSymbolIter(e,e,new,e);
  }
  else if (PT_isSymbolIterStar(symbol)) {
    PTPT_Symbol new = PTPT_liftSymbol(PT_getSymbolSymbol(symbol));
    result = PTPT_makeSymbolIterStar(e,e,new,e);
  }
  else if (PT_isSymbolIterPlusSep(symbol)) {
    PTPT_Symbol sym = PTPT_liftSymbol(PT_getSymbolSymbol(symbol));
    PTPT_Symbol sep = PTPT_liftSymbol(PT_getSymbolSeparator(symbol));
    result = PTPT_makeSymbolIterSep(e,e,sym,e,e,sep,e);
  }
  else if (PT_isSymbolIterStarSep(symbol)) {
    PTPT_Symbol sym = PTPT_liftSymbol(PT_getSymbolSymbol(symbol));
    PTPT_Symbol sep = PTPT_liftSymbol(PT_getSymbolSeparator(symbol));
    result = PTPT_makeSymbolIterStarSep(e,e,sym,e,e,sep,e);
  }
  else if (PT_isSymbolIterN(symbol)) {
    PTPT_Symbol sym = PTPT_liftSymbol(PT_getSymbolSymbol(symbol));
    PTPT_NatCon num = PTPT_liftNatCon(PT_getSymbolNumber(symbol));
    result = PTPT_makeSymbolIterN(e,e,sym,e,e,num,e);
  }
  else if (PT_isSymbolIterSepN(symbol)) {
    PTPT_Symbol sym = PTPT_liftSymbol(PT_getSymbolSymbol(symbol));
    PTPT_Symbol sep = PTPT_liftSymbol(PT_getSymbolSeparator(symbol));
    PTPT_NatCon num = PTPT_liftNatCon(PT_getSymbolNumber(symbol));
    result = PTPT_makeSymbolIterSepN(e,e,sym,e,e,sep,e,e,num,e);
  }
  else if (PT_isSymbolFunc(symbol)) {
    PTPT_Symbols syms = PTPT_liftSymbols(PT_getSymbolSymbols(symbol));
    PTPT_Symbol sym = PTPT_liftSymbol(PT_getSymbolSymbol(symbol));
    result = PTPT_makeSymbolFunc(e,e,syms,e,e,sym,e);
  }
  else if (PT_isSymbolParameterizedSort(symbol)) {
    PTPT_StrCon lit = PTPT_liftStrCon(PT_getSymbolSort(symbol));
    PTPT_Symbols syms = PTPT_liftSymbols(PT_getSymbolParameters(symbol));
    result = PTPT_makeSymbolParameterizedSort(e,e,lit,e,e,syms,e);
  }
  else if (PT_isSymbolVarSym(symbol)) {
    PTPT_Symbol new = PTPT_liftSymbol(PT_getSymbolSymbol(symbol));
    result = PTPT_makeSymbolVarsym(e,e,new,e);
  }
  else if (PT_isSymbolLayout(symbol)) {
    result = PTPT_makeSymbolLayout();
  }
  else if (PT_isSymbolCharClass(symbol)) {
    PTPT_CharRanges ranges = PTPT_liftCharRanges(PT_getSymbolRanges(symbol));
    result = PTPT_makeSymbolCharClass(e,e,ranges,e);
  }
  else {
    ATwarning("lift: unknown symbol %t\n", symbol);
    assert(ATfalse);
  }

  storeSymbol(symbol, result); 
  return result;
}

/*}}}  */
/*{{{  static PTPT_CharRange PTPT_liftCharRange(PT_CharRange range) */

static PTPT_CharRange PTPT_liftCharRange(PT_CharRange range)
{
  PTPT_CharRange result = NULL;

  if (PT_isCharRangeCharacter(range)) {
    PTPT_NatCon nat = PTPT_liftNatCon(PT_getCharRangeStart(range));
    result = PTPT_makeCharRangeCharacter(nat);
  }
  else if (PT_isCharRangeRange(range)) {
    PTPT_NatCon start = PTPT_liftNatCon(PT_getCharRangeStart(range));
    PTPT_NatCon end = PTPT_liftNatCon(PT_getCharRangeEnd(range));
    result = PTPT_makeCharRangeRange(e,e,start,e,e,end,e);
  }
  else {
    ATwarning("lift: unknown charrange %t\n", range);
    assert(ATfalse);
  }

  return result;
}

/*}}}  */
/*{{{  static PTPT_Associativity PTPT_liftAssociativity(PT_Associativity assoc) */

static PTPT_Associativity PTPT_liftAssociativity(PT_Associativity assoc)
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
    ATwarning("lift: unknown associativity %t\n", assoc);
    assert(ATfalse);
  }

  return result;
}

/*}}}  */
/*{{{  static PTPT_Attr PTPT_liftAttr(PT_Attr attr) */

static PTPT_Attr PTPT_liftAttr(PT_Attr attr)
{
  PTPT_Attr result = NULL;

  if (PT_isAttrAssoc(attr)) {
    PTPT_Associativity assoc = PTPT_liftAssociativity(PT_getAttrAssoc(attr));
    result = PTPT_makeAttrAssoc(e,e,assoc,e);
  }
  else if (PT_isAttrTerm(attr)) {
    PTPT_ATerm term = PTPT_liftATerm(PT_getAttrTerm(attr));
    result = PTPT_makeAttrTerm(e,e,term,e);
  }
  else if (PT_isAttrId(attr)) {
    PTPT_StrCon id = PTPT_liftStrCon(PT_getAttrModuleName(attr));
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
    ATwarning("lift: unknown attr %t\n", attr);
    assert(ATfalse);
  }

  return result;
}

/*}}}  */

/*{{{  static PTPT_Attributes PTPT_liftAttributes(PT_Attributes attributes) */

static PTPT_Attributes PTPT_liftAttributes(PT_Attributes attributes)
{
  PTPT_Attributes result = NULL;

  if (PT_isAttributesNoAttrs(attributes)) {
    result = PTPT_makeAttributesNoAttrs();
  }
  else if (PT_isAttributesAttrs(attributes)) {
    PTPT_Attrs attrs = PTPT_liftAttrs(PT_getAttributesAttrs(attributes));
    result = PTPT_makeAttributesAttrs(e,e,attrs,e);
  }
  else {
    ATwarning("lift: unknown attributes: %t\n", attributes);
  }

  return result;
}

/*}}}  */

/*{{{  static PTPT_Production PTPT_liftProd(PT_Production prod) */

static PTPT_Production PTPT_liftProd(PT_Production prod)
{
  PTPT_Production result = NULL;

  if (PT_isProductionDefault(prod)) {
    PTPT_Symbols lhs;
    PTPT_Symbol  rhs;
    PTPT_Attributes attrs;

    lhs = PTPT_liftSymbols(PT_getProductionLhs(prod));
    rhs  = PTPT_liftSymbol(PT_getProductionRhs(prod));
    attrs = PTPT_liftAttributes(PT_getProductionAttributes(prod));
    result = PTPT_makeProductionDefault(e,e,lhs,e,e,rhs,e,e,attrs,e);
  }
  else if (PT_isProductionList(prod)) {
    PTPT_Symbol  rhs  = PTPT_liftSymbol(PT_getProductionRhs(prod));

    result = PTPT_makeProductionList(e,e,rhs,e);
  }
  else {
    ATwarning("lift: unknown production %t\n", prod);
    assert(ATfalse);
  }

  return result;
}

/*}}}  */
/*{{{  static PTPT_Args PTPT_liftArgs(PT_Args args)  */

static PTPT_Args PTPT_liftArgs(PT_Args args) 
{
  PTPT_TreeList list = PTPT_makeTreeListEmpty();

  for(;!PT_isArgsEmpty(args); args = PT_getArgsTail(args)) {
    PTPT_Tree head = PTPT_liftTreeRec(PT_getArgsHead(args));
    if (!PTPT_isTreeListEmpty(list)) {
      list = PTPT_makeTreeListMany(head,e,e,list);
    }
    else {
      list = PTPT_makeTreeListSingle(head);
    }
  }

  return PTPT_makeArgsList(e,PTPT_reverseTreeList(list),e);
}

/*}}}  */

/*{{{  PTPT_Tree PTPT_liftTreeCache(PT_Tree pt, ATermTable myLowerCache) */

PTPT_Tree PTPT_liftTreeCache(PT_Tree pt, ATermTable myLowerCache)
{
  PTPT_Tree result;

  initGlobals(myLowerCache);

  result = PTPT_liftTreeRec(pt);

  lowerCache = NULL;

  return result;
}

/*}}}  */
/*{{{  PTPT_Tree PTPT_liftTree(PT_Tree pt); */

PTPT_Tree PTPT_liftTree(PT_Tree pt)
{
  PTPT_Tree result;

  initGlobals(NULL);

  result = PTPT_liftTreeRec(pt);

  return result;
}

/*}}}  */

/*{{{  PT_Tree PTPT_liftTreeRec(PT_Tree pt) */

static PTPT_Tree PTPT_liftTreeRec(PT_Tree pt)
{
  PTPT_Tree result = NULL;
  ATerm annos = NULL;

  result = lookupTree(pt);
  if (result != NULL) {
    return result;
  }

  if (PT_isTreeAmb(pt)) {
    PT_Args args = PT_getTreeArgs(pt);

    result = PTPT_makeTreeAmb(e,e, PTPT_liftArgs(args),e);
  }
  else if (PT_isTreeAppl(pt)) {
    PTPT_Production prod;
    PTPT_Args args;

    prod = PTPT_liftProd(PT_getTreeProd(pt));
    args = PTPT_liftArgs(PT_getTreeArgs(pt));

    result = PTPT_makeTreeAppl(e,e,prod,e,e,args,e);
  }
  else if (PT_isTreeChar(pt)) {
    int val = PT_getTreeCharacter(pt);
    result = PTPT_makeTreeChar(PTPT_liftNatCon(val));
  }
  else if (PT_isTreeCycle(pt)) {
    PTPT_Symbol symbol = PTPT_liftSymbol(PT_getTreeSymbol(pt));
    PTPT_NatCon length = PTPT_liftNatCon(PT_getTreeCycleLength(pt));
    result = PTPT_makeTreeCycle(e,e,symbol,e,e,length,e);
  }
  else {
    ATwarning("lift: unknown term %t\n", pt);
    assert(ATfalse);
  }

  if ((annos = PT_getTreeAnnotations(pt)) != NULL) {
    PTPT_Annotation ann = PTPT_liftAnnotations((ATermList) annos);

    result = PTPT_makeTreeAnnotated(result,e,ann);
  }

  storeTree(pt, result);

  return result;
}

/*}}}  */
/*{{{  PT_ParseTree PTPT_liftParseTree(PT_ParseTree pt)  */

PTPT_ParseTree PTPT_liftParseTree(PT_ParseTree pt) 
{
  PT_Tree tree = PT_getParseTreeTop(pt);
  PTPT_ParseTree result;
  int ambCnt = PT_getParseTreeAmbCnt(pt);

  initGlobals(NULL);

  result = PTPT_makeParseTreeTop(e,e,
				 (PTPT_Tree) PTPT_liftTreeRec(tree),
				 e,e,
				 PTPT_liftNatCon(ambCnt),
				 e);

  ATtableDestroy(liftCache);
  liftCache = NULL;

  return result;

}

/*}}}  */
