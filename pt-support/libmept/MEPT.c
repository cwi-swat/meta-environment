#include <aterm2.h>
#include <deprecated.h>
#include "MEPT.h"

/*{{{  typedefs */

typedef struct ATerm _PT_ParseTree;
typedef struct ATerm _PT_Tree;
typedef struct ATerm _PT_Production;
typedef struct ATerm _PT_Attributes;
typedef struct ATerm _PT_Attrs;
typedef struct ATerm _PT_Attr;
typedef struct ATerm _PT_ATerm;
typedef struct ATerm _PT_Args;
typedef struct ATerm _PT_Symbol;
typedef struct ATerm _PT_Symbols;
typedef struct ATerm _PT_CharRange;
typedef struct ATerm _PT_CharRanges;

/*}}}  */

/*{{{  void PT_initMEPTApi(void) */

void PT_initMEPTApi(void)
{
  init_MEPT_dict();
}

/*}}}  */

/*{{{  term conversion functions */

/*{{{  PT_ParseTree PT_makeParseTreeFromTerm(ATerm t) */

PT_ParseTree PT_makeParseTreeFromTerm(ATerm t)
{
  return (PT_ParseTree)t;
}

/*}}}  */
/*{{{  ATerm PT_makeTermFromParseTree(PT_ParseTree arg) */

ATerm PT_makeTermFromParseTree(PT_ParseTree arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PT_Tree PT_makeTreeFromTerm(ATerm t) */

PT_Tree PT_makeTreeFromTerm(ATerm t)
{
  return (PT_Tree)t;
}

/*}}}  */
/*{{{  ATerm PT_makeTermFromTree(PT_Tree arg) */

ATerm PT_makeTermFromTree(PT_Tree arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PT_Production PT_makeProductionFromTerm(ATerm t) */

PT_Production PT_makeProductionFromTerm(ATerm t)
{
  return (PT_Production)t;
}

/*}}}  */
/*{{{  ATerm PT_makeTermFromProduction(PT_Production arg) */

ATerm PT_makeTermFromProduction(PT_Production arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PT_Attributes PT_makeAttributesFromTerm(ATerm t) */

PT_Attributes PT_makeAttributesFromTerm(ATerm t)
{
  return (PT_Attributes)t;
}

/*}}}  */
/*{{{  ATerm PT_makeTermFromAttributes(PT_Attributes arg) */

ATerm PT_makeTermFromAttributes(PT_Attributes arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PT_Attrs PT_makeAttrsFromTerm(ATerm t) */

PT_Attrs PT_makeAttrsFromTerm(ATerm t)
{
  return (PT_Attrs)t;
}

/*}}}  */
/*{{{  ATerm PT_makeTermFromAttrs(PT_Attrs arg) */

ATerm PT_makeTermFromAttrs(PT_Attrs arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PT_Attr PT_makeAttrFromTerm(ATerm t) */

PT_Attr PT_makeAttrFromTerm(ATerm t)
{
  return (PT_Attr)t;
}

/*}}}  */
/*{{{  ATerm PT_makeTermFromAttr(PT_Attr arg) */

ATerm PT_makeTermFromAttr(PT_Attr arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PT_ATerm PT_makeATermFromTerm(ATerm t) */

PT_ATerm PT_makeATermFromTerm(ATerm t)
{
  return (PT_ATerm)t;
}

/*}}}  */
/*{{{  ATerm PT_makeTermFromATerm(PT_ATerm arg) */

ATerm PT_makeTermFromATerm(PT_ATerm arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PT_Args PT_makeArgsFromTerm(ATerm t) */

PT_Args PT_makeArgsFromTerm(ATerm t)
{
  return (PT_Args)t;
}

/*}}}  */
/*{{{  ATerm PT_makeTermFromArgs(PT_Args arg) */

ATerm PT_makeTermFromArgs(PT_Args arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PT_Symbol PT_makeSymbolFromTerm(ATerm t) */

PT_Symbol PT_makeSymbolFromTerm(ATerm t)
{
  return (PT_Symbol)t;
}

/*}}}  */
/*{{{  ATerm PT_makeTermFromSymbol(PT_Symbol arg) */

ATerm PT_makeTermFromSymbol(PT_Symbol arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PT_Symbols PT_makeSymbolsFromTerm(ATerm t) */

PT_Symbols PT_makeSymbolsFromTerm(ATerm t)
{
  return (PT_Symbols)t;
}

/*}}}  */
/*{{{  ATerm PT_makeTermFromSymbols(PT_Symbols arg) */

ATerm PT_makeTermFromSymbols(PT_Symbols arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PT_CharRange PT_makeCharRangeFromTerm(ATerm t) */

PT_CharRange PT_makeCharRangeFromTerm(ATerm t)
{
  return (PT_CharRange)t;
}

/*}}}  */
/*{{{  ATerm PT_makeTermFromCharRange(PT_CharRange arg) */

ATerm PT_makeTermFromCharRange(PT_CharRange arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PT_CharRanges PT_makeCharRangesFromTerm(ATerm t) */

PT_CharRanges PT_makeCharRangesFromTerm(ATerm t)
{
  return (PT_CharRanges)t;
}

/*}}}  */
/*{{{  ATerm PT_makeTermFromCharRanges(PT_CharRanges arg) */

ATerm PT_makeTermFromCharRanges(PT_CharRanges arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*}}}  */
/*{{{  constructors */

/*{{{  PT_ParseTree PT_makeParseTreeTree(PT_Symbols lhs, PT_Tree layoutBeforeTree, PT_Tree tree, PT_Tree layoutAfterTree, int ambCnt) */

PT_ParseTree PT_makeParseTreeTree(PT_Symbols lhs, PT_Tree layoutBeforeTree, PT_Tree tree, PT_Tree layoutAfterTree, int ambCnt)
{
  return (PT_ParseTree)ATmakeTerm(PT_patternParseTreeTree, lhs, layoutBeforeTree, tree, layoutAfterTree, ambCnt);
}

/*}}}  */
/*{{{  PT_Tree PT_makeTreeAppl(PT_Production prod, PT_Args args) */

PT_Tree PT_makeTreeAppl(PT_Production prod, PT_Args args)
{
  return (PT_Tree)ATmakeTerm(PT_patternTreeAppl, prod, args);
}

/*}}}  */
/*{{{  PT_Tree PT_makeTreeChar(int character) */

PT_Tree PT_makeTreeChar(int character)
{
  return (PT_Tree)ATmakeTerm(PT_patternTreeChar, character);
}

/*}}}  */
/*{{{  PT_Tree PT_makeTreeLit(char * string) */

PT_Tree PT_makeTreeLit(char * string)
{
  return (PT_Tree)ATmakeTerm(PT_patternTreeLit, string);
}

/*}}}  */
/*{{{  PT_Tree PT_makeTreeFlatLayout(char * string) */

PT_Tree PT_makeTreeFlatLayout(char * string)
{
  return (PT_Tree)ATmakeTerm(PT_patternTreeFlatLayout, string);
}

/*}}}  */
/*{{{  PT_Tree PT_makeTreeAmb(PT_Args args) */

PT_Tree PT_makeTreeAmb(PT_Args args)
{
  return (PT_Tree)ATmakeTerm(PT_patternTreeAmb, args);
}

/*}}}  */
/*{{{  PT_Production PT_makeProductionDefault(PT_Symbols lhs, PT_Symbol rhs, PT_Attributes attributes) */

PT_Production PT_makeProductionDefault(PT_Symbols lhs, PT_Symbol rhs, PT_Attributes attributes)
{
  return (PT_Production)ATmakeTerm(PT_patternProductionDefault, lhs, rhs, attributes);
}

/*}}}  */
/*{{{  PT_Production PT_makeProductionList(PT_Symbol rhs) */

PT_Production PT_makeProductionList(PT_Symbol rhs)
{
  return (PT_Production)ATmakeTerm(PT_patternProductionList, rhs);
}

/*}}}  */
/*{{{  PT_Attributes PT_makeAttributesNoAttrs() */

PT_Attributes PT_makeAttributesNoAttrs()
{
  return (PT_Attributes)ATmakeTerm(PT_patternAttributesNoAttrs);
}

/*}}}  */
/*{{{  PT_Attributes PT_makeAttributesAttrs(PT_Attrs attrs) */

PT_Attributes PT_makeAttributesAttrs(PT_Attrs attrs)
{
  return (PT_Attributes)ATmakeTerm(PT_patternAttributesAttrs, attrs);
}

/*}}}  */
/*{{{  PT_Attrs PT_makeAttrsMany(PT_Attr head, PT_Attrs tail) */

PT_Attrs PT_makeAttrsMany(PT_Attr head, PT_Attrs tail)
{
  return (PT_Attrs)ATmakeTerm(PT_patternAttrsMany, head, tail);
}

/*}}}  */
/*{{{  PT_Attrs PT_makeAttrsSingle(PT_Attr head) */

PT_Attrs PT_makeAttrsSingle(PT_Attr head)
{
  return (PT_Attrs)ATmakeTerm(PT_patternAttrsSingle, head);
}

/*}}}  */
/*{{{  PT_Attr PT_makeAttrCons(char * string) */

PT_Attr PT_makeAttrCons(char * string)
{
  return (PT_Attr)ATmakeTerm(PT_patternAttrCons, string);
}

/*}}}  */
/*{{{  PT_Attr PT_makeAttrId(char * moduleName) */

PT_Attr PT_makeAttrId(char * moduleName)
{
  return (PT_Attr)ATmakeTerm(PT_patternAttrId, moduleName);
}

/*}}}  */
/*{{{  PT_Attr PT_makeAttrAterm(PT_ATerm term) */

PT_Attr PT_makeAttrAterm(PT_ATerm term)
{
  return (PT_Attr)ATmakeTerm(PT_patternAttrAterm, term);
}

/*}}}  */
/*{{{  PT_ATerm PT_makeATermBracket() */

PT_ATerm PT_makeATermBracket()
{
  return (PT_ATerm)ATmakeTerm(PT_patternATermBracket);
}

/*}}}  */
/*{{{  PT_ATerm PT_makeATermLeft() */

PT_ATerm PT_makeATermLeft()
{
  return (PT_ATerm)ATmakeTerm(PT_patternATermLeft);
}

/*}}}  */
/*{{{  PT_ATerm PT_makeATermRight() */

PT_ATerm PT_makeATermRight()
{
  return (PT_ATerm)ATmakeTerm(PT_patternATermRight);
}

/*}}}  */
/*{{{  PT_ATerm PT_makeATermAssoc() */

PT_ATerm PT_makeATermAssoc()
{
  return (PT_ATerm)ATmakeTerm(PT_patternATermAssoc);
}

/*}}}  */
/*{{{  PT_ATerm PT_makeATermNonAssoc() */

PT_ATerm PT_makeATermNonAssoc()
{
  return (PT_ATerm)ATmakeTerm(PT_patternATermNonAssoc);
}

/*}}}  */
/*{{{  PT_ATerm PT_makeATermMemo() */

PT_ATerm PT_makeATermMemo()
{
  return (PT_ATerm)ATmakeTerm(PT_patternATermMemo);
}

/*}}}  */
/*{{{  PT_ATerm PT_makeATermReject() */

PT_ATerm PT_makeATermReject()
{
  return (PT_ATerm)ATmakeTerm(PT_patternATermReject);
}

/*}}}  */
/*{{{  PT_ATerm PT_makeATermPrefer() */

PT_ATerm PT_makeATermPrefer()
{
  return (PT_ATerm)ATmakeTerm(PT_patternATermPrefer);
}

/*}}}  */
/*{{{  PT_ATerm PT_makeATermAvoid() */

PT_ATerm PT_makeATermAvoid()
{
  return (PT_ATerm)ATmakeTerm(PT_patternATermAvoid);
}

/*}}}  */
/*{{{  PT_ATerm PT_makeATermConstructor() */

PT_ATerm PT_makeATermConstructor()
{
  return (PT_ATerm)ATmakeTerm(PT_patternATermConstructor);
}

/*}}}  */
/*{{{  PT_ATerm PT_makeATermTraverse() */

PT_ATerm PT_makeATermTraverse()
{
  return (PT_ATerm)ATmakeTerm(PT_patternATermTraverse);
}

/*}}}  */
/*{{{  PT_Args PT_makeArgsList(PT_Tree head, PT_Args tail) */

PT_Args PT_makeArgsList(PT_Tree head, PT_Args tail)
{
  return (PT_Args)ATmakeTerm(PT_patternArgsList, head, tail);
}

/*}}}  */
/*{{{  PT_Args PT_makeArgsEmpty() */

PT_Args PT_makeArgsEmpty()
{
  return (PT_Args)ATmakeTerm(PT_patternArgsEmpty);
}

/*}}}  */
/*{{{  PT_Symbol PT_makeSymbolLit(char * string) */

PT_Symbol PT_makeSymbolLit(char * string)
{
  return (PT_Symbol)ATmakeTerm(PT_patternSymbolLit, string);
}

/*}}}  */
/*{{{  PT_Symbol PT_makeSymbolCf(PT_Symbol symbol) */

PT_Symbol PT_makeSymbolCf(PT_Symbol symbol)
{
  return (PT_Symbol)ATmakeTerm(PT_patternSymbolCf, symbol);
}

/*}}}  */
/*{{{  PT_Symbol PT_makeSymbolLex(PT_Symbol symbol) */

PT_Symbol PT_makeSymbolLex(PT_Symbol symbol)
{
  return (PT_Symbol)ATmakeTerm(PT_patternSymbolLex, symbol);
}

/*}}}  */
/*{{{  PT_Symbol PT_makeSymbolEmpty() */

PT_Symbol PT_makeSymbolEmpty()
{
  return (PT_Symbol)ATmakeTerm(PT_patternSymbolEmpty);
}

/*}}}  */
/*{{{  PT_Symbol PT_makeSymbolSeq(PT_Symbols symbols) */

PT_Symbol PT_makeSymbolSeq(PT_Symbols symbols)
{
  return (PT_Symbol)ATmakeTerm(PT_patternSymbolSeq, symbols);
}

/*}}}  */
/*{{{  PT_Symbol PT_makeSymbolOpt(PT_Symbol symbol) */

PT_Symbol PT_makeSymbolOpt(PT_Symbol symbol)
{
  return (PT_Symbol)ATmakeTerm(PT_patternSymbolOpt, symbol);
}

/*}}}  */
/*{{{  PT_Symbol PT_makeSymbolAlt(PT_Symbol lhs, PT_Symbol rhs) */

PT_Symbol PT_makeSymbolAlt(PT_Symbol lhs, PT_Symbol rhs)
{
  return (PT_Symbol)ATmakeTerm(PT_patternSymbolAlt, lhs, rhs);
}

/*}}}  */
/*{{{  PT_Symbol PT_makeSymbolPair(PT_Symbol lhs, PT_Symbol rhs) */

PT_Symbol PT_makeSymbolPair(PT_Symbol lhs, PT_Symbol rhs)
{
  return (PT_Symbol)ATmakeTerm(PT_patternSymbolPair, lhs, rhs);
}

/*}}}  */
/*{{{  PT_Symbol PT_makeSymbolSort(char * string) */

PT_Symbol PT_makeSymbolSort(char * string)
{
  return (PT_Symbol)ATmakeTerm(PT_patternSymbolSort, string);
}

/*}}}  */
/*{{{  PT_Symbol PT_makeSymbolIterPlus(PT_Symbol symbol) */

PT_Symbol PT_makeSymbolIterPlus(PT_Symbol symbol)
{
  return (PT_Symbol)ATmakeTerm(PT_patternSymbolIterPlus, symbol);
}

/*}}}  */
/*{{{  PT_Symbol PT_makeSymbolIterStar(PT_Symbol symbol) */

PT_Symbol PT_makeSymbolIterStar(PT_Symbol symbol)
{
  return (PT_Symbol)ATmakeTerm(PT_patternSymbolIterStar, symbol);
}

/*}}}  */
/*{{{  PT_Symbol PT_makeSymbolIterPlusSep(PT_Symbol symbol, PT_Symbol separator) */

PT_Symbol PT_makeSymbolIterPlusSep(PT_Symbol symbol, PT_Symbol separator)
{
  return (PT_Symbol)ATmakeTerm(PT_patternSymbolIterPlusSep, symbol, separator);
}

/*}}}  */
/*{{{  PT_Symbol PT_makeSymbolIterStarSep(PT_Symbol symbol, PT_Symbol separator) */

PT_Symbol PT_makeSymbolIterStarSep(PT_Symbol symbol, PT_Symbol separator)
{
  return (PT_Symbol)ATmakeTerm(PT_patternSymbolIterStarSep, symbol, separator);
}

/*}}}  */
/*{{{  PT_Symbol PT_makeSymbolIterN(PT_Symbol symbol, int number) */

PT_Symbol PT_makeSymbolIterN(PT_Symbol symbol, int number)
{
  return (PT_Symbol)ATmakeTerm(PT_patternSymbolIterN, symbol, number);
}

/*}}}  */
/*{{{  PT_Symbol PT_makeSymbolIterSepN(PT_Symbol symbol, PT_Symbol separator, int number) */

PT_Symbol PT_makeSymbolIterSepN(PT_Symbol symbol, PT_Symbol separator, int number)
{
  return (PT_Symbol)ATmakeTerm(PT_patternSymbolIterSepN, symbol, separator, number);
}

/*}}}  */
/*{{{  PT_Symbol PT_makeSymbolPerm(PT_Symbols symbols) */

PT_Symbol PT_makeSymbolPerm(PT_Symbols symbols)
{
  return (PT_Symbol)ATmakeTerm(PT_patternSymbolPerm, symbols);
}

/*}}}  */
/*{{{  PT_Symbol PT_makeSymbolSet(PT_Symbol symbol) */

PT_Symbol PT_makeSymbolSet(PT_Symbol symbol)
{
  return (PT_Symbol)ATmakeTerm(PT_patternSymbolSet, symbol);
}

/*}}}  */
/*{{{  PT_Symbol PT_makeSymbolFunc(PT_Symbols symbols, PT_Symbol symbol) */

PT_Symbol PT_makeSymbolFunc(PT_Symbols symbols, PT_Symbol symbol)
{
  return (PT_Symbol)ATmakeTerm(PT_patternSymbolFunc, symbols, symbol);
}

/*}}}  */
/*{{{  PT_Symbol PT_makeSymbolVarSym(PT_Symbol symbol) */

PT_Symbol PT_makeSymbolVarSym(PT_Symbol symbol)
{
  return (PT_Symbol)ATmakeTerm(PT_patternSymbolVarSym, symbol);
}

/*}}}  */
/*{{{  PT_Symbol PT_makeSymbolLayout() */

PT_Symbol PT_makeSymbolLayout()
{
  return (PT_Symbol)ATmakeTerm(PT_patternSymbolLayout);
}

/*}}}  */
/*{{{  PT_Symbol PT_makeSymbolCharClass(PT_CharRanges ranges) */

PT_Symbol PT_makeSymbolCharClass(PT_CharRanges ranges)
{
  return (PT_Symbol)ATmakeTerm(PT_patternSymbolCharClass, ranges);
}

/*}}}  */
/*{{{  PT_Symbols PT_makeSymbolsList(PT_Symbol head, PT_Symbols tail) */

PT_Symbols PT_makeSymbolsList(PT_Symbol head, PT_Symbols tail)
{
  return (PT_Symbols)ATmakeTerm(PT_patternSymbolsList, head, tail);
}

/*}}}  */
/*{{{  PT_Symbols PT_makeSymbolsEmpty() */

PT_Symbols PT_makeSymbolsEmpty()
{
  return (PT_Symbols)ATmakeTerm(PT_patternSymbolsEmpty);
}

/*}}}  */
/*{{{  PT_CharRange PT_makeCharRangeCharacter(int integer) */

PT_CharRange PT_makeCharRangeCharacter(int integer)
{
  return (PT_CharRange)ATmakeTerm(PT_patternCharRangeCharacter, integer);
}

/*}}}  */
/*{{{  PT_CharRange PT_makeCharRangeRange(int start, int end) */

PT_CharRange PT_makeCharRangeRange(int start, int end)
{
  return (PT_CharRange)ATmakeTerm(PT_patternCharRangeRange, start, end);
}

/*}}}  */
/*{{{  PT_CharRanges PT_makeCharRangesList(PT_CharRange head, PT_CharRanges tail) */

PT_CharRanges PT_makeCharRangesList(PT_CharRange head, PT_CharRanges tail)
{
  return (PT_CharRanges)ATmakeTerm(PT_patternCharRangesList, head, tail);
}

/*}}}  */
/*{{{  PT_CharRanges PT_makeCharRangesEmpty() */

PT_CharRanges PT_makeCharRangesEmpty()
{
  return (PT_CharRanges)ATmakeTerm(PT_patternCharRangesEmpty);
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool PT_isEqualParseTree(PT_ParseTree arg0, PT_ParseTree arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PT_isEqualTree(PT_Tree arg0, PT_Tree arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PT_isEqualProduction(PT_Production arg0, PT_Production arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PT_isEqualAttributes(PT_Attributes arg0, PT_Attributes arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PT_isEqualAttrs(PT_Attrs arg0, PT_Attrs arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PT_isEqualAttr(PT_Attr arg0, PT_Attr arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PT_isEqualATerm(PT_ATerm arg0, PT_ATerm arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PT_isEqualArgs(PT_Args arg0, PT_Args arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PT_isEqualSymbol(PT_Symbol arg0, PT_Symbol arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PT_isEqualSymbols(PT_Symbols arg0, PT_Symbols arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PT_isEqualCharRange(PT_CharRange arg0, PT_CharRange arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PT_isEqualCharRanges(PT_CharRanges arg0, PT_CharRanges arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  PT_ParseTree accessors */

/*{{{  ATbool PT_isValidParseTree(PT_ParseTree arg) */

ATbool PT_isValidParseTree(PT_ParseTree arg)
{
  if (PT_isParseTreeTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isParseTreeTree(PT_ParseTree arg) */

ATbool PT_isParseTreeTree(PT_ParseTree arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternParseTreeTree, NULL, NULL, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool PT_hasParseTreeLhs(PT_ParseTree arg) */

ATbool PT_hasParseTreeLhs(PT_ParseTree arg)
{
  if (PT_isParseTreeTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Symbols PT_getParseTreeLhs(PT_ParseTree arg) */

PT_Symbols PT_getParseTreeLhs(PT_ParseTree arg)
{
  if (PT_isParseTreeTree(arg)) {
    return (PT_Symbols)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), 0);
  }

  ATabort("ParseTree has no Lhs: %t\n", arg);
  return (PT_Symbols)NULL;
}

/*}}}  */
/*{{{  PT_ParseTree PT_setParseTreeLhs(PT_ParseTree arg, PT_Symbols lhs) */

PT_ParseTree PT_setParseTreeLhs(PT_ParseTree arg, PT_Symbols lhs)
{
  if (PT_isParseTreeTree(arg)) {
    return (PT_ParseTree)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)lhs, 0), 0), 0);
  }

  ATabort("ParseTree has no Lhs: %t\n", arg);
  return (PT_ParseTree)NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasParseTreeLayoutBeforeTree(PT_ParseTree arg) */

ATbool PT_hasParseTreeLayoutBeforeTree(PT_ParseTree arg)
{
  if (PT_isParseTreeTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Tree PT_getParseTreeLayoutBeforeTree(PT_ParseTree arg) */

PT_Tree PT_getParseTreeLayoutBeforeTree(PT_ParseTree arg)
{
  if (PT_isParseTreeTree(arg)) {
    return (PT_Tree)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 0);
  }

  ATabort("ParseTree has no LayoutBeforeTree: %t\n", arg);
  return (PT_Tree)NULL;
}

/*}}}  */
/*{{{  PT_ParseTree PT_setParseTreeLayoutBeforeTree(PT_ParseTree arg, PT_Tree layoutBeforeTree) */

PT_ParseTree PT_setParseTreeLayoutBeforeTree(PT_ParseTree arg, PT_Tree layoutBeforeTree)
{
  if (PT_isParseTreeTree(arg)) {
    return (PT_ParseTree)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)layoutBeforeTree, 0), 1), 0);
  }

  ATabort("ParseTree has no LayoutBeforeTree: %t\n", arg);
  return (PT_ParseTree)NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasParseTreeTree(PT_ParseTree arg) */

ATbool PT_hasParseTreeTree(PT_ParseTree arg)
{
  if (PT_isParseTreeTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Tree PT_getParseTreeTree(PT_ParseTree arg) */

PT_Tree PT_getParseTreeTree(PT_ParseTree arg)
{
  if (PT_isParseTreeTree(arg)) {
    return (PT_Tree)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
  }

  ATabort("ParseTree has no Tree: %t\n", arg);
  return (PT_Tree)NULL;
}

/*}}}  */
/*{{{  PT_ParseTree PT_setParseTreeTree(PT_ParseTree arg, PT_Tree tree) */

PT_ParseTree PT_setParseTreeTree(PT_ParseTree arg, PT_Tree tree)
{
  if (PT_isParseTreeTree(arg)) {
    return (PT_ParseTree)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)tree, 1), 1), 0);
  }

  ATabort("ParseTree has no Tree: %t\n", arg);
  return (PT_ParseTree)NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasParseTreeLayoutAfterTree(PT_ParseTree arg) */

ATbool PT_hasParseTreeLayoutAfterTree(PT_ParseTree arg)
{
  if (PT_isParseTreeTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Tree PT_getParseTreeLayoutAfterTree(PT_ParseTree arg) */

PT_Tree PT_getParseTreeLayoutAfterTree(PT_ParseTree arg)
{
  if (PT_isParseTreeTree(arg)) {
    return (PT_Tree)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }

  ATabort("ParseTree has no LayoutAfterTree: %t\n", arg);
  return (PT_Tree)NULL;
}

/*}}}  */
/*{{{  PT_ParseTree PT_setParseTreeLayoutAfterTree(PT_ParseTree arg, PT_Tree layoutAfterTree) */

PT_ParseTree PT_setParseTreeLayoutAfterTree(PT_ParseTree arg, PT_Tree layoutAfterTree)
{
  if (PT_isParseTreeTree(arg)) {
    return (PT_ParseTree)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)layoutAfterTree, 2), 1), 0);
  }

  ATabort("ParseTree has no LayoutAfterTree: %t\n", arg);
  return (PT_ParseTree)NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasParseTreeAmbCnt(PT_ParseTree arg) */

ATbool PT_hasParseTreeAmbCnt(PT_ParseTree arg)
{
  if (PT_isParseTreeTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int PT_getParseTreeAmbCnt(PT_ParseTree arg) */

int PT_getParseTreeAmbCnt(PT_ParseTree arg)
{
  if (PT_isParseTreeTree(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }

  ATabort("ParseTree has no AmbCnt: %t\n", arg);
  return (int)NULL;
}

/*}}}  */
/*{{{  PT_ParseTree PT_setParseTreeAmbCnt(PT_ParseTree arg, int ambCnt) */

PT_ParseTree PT_setParseTreeAmbCnt(PT_ParseTree arg, int ambCnt)
{
  if (PT_isParseTreeTree(arg)) {
    return (PT_ParseTree)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }

  ATabort("ParseTree has no AmbCnt: %t\n", arg);
  return (PT_ParseTree)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PT_Tree accessors */

/*{{{  ATbool PT_isValidTree(PT_Tree arg) */

ATbool PT_isValidTree(PT_Tree arg)
{
  if (PT_isTreeAppl(arg)) {
    return ATtrue;
  }
  else if (PT_isTreeChar(arg)) {
    return ATtrue;
  }
  else if (PT_isTreeLit(arg)) {
    return ATtrue;
  }
  else if (PT_isTreeFlatLayout(arg)) {
    return ATtrue;
  }
  else if (PT_isTreeAmb(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isTreeAppl(PT_Tree arg) */

ATbool PT_isTreeAppl(PT_Tree arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternTreeAppl, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isTreeChar(PT_Tree arg) */

ATbool PT_isTreeChar(PT_Tree arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternTreeChar, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isTreeLit(PT_Tree arg) */

ATbool PT_isTreeLit(PT_Tree arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternTreeLit, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isTreeFlatLayout(PT_Tree arg) */

ATbool PT_isTreeFlatLayout(PT_Tree arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternTreeFlatLayout, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isTreeAmb(PT_Tree arg) */

ATbool PT_isTreeAmb(PT_Tree arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternTreeAmb, NULL);
}

/*}}}  */
/*{{{  ATbool PT_hasTreeProd(PT_Tree arg) */

ATbool PT_hasTreeProd(PT_Tree arg)
{
  if (PT_isTreeAppl(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Production PT_getTreeProd(PT_Tree arg) */

PT_Production PT_getTreeProd(PT_Tree arg)
{
  if (PT_isTreeAppl(arg)) {
    return (PT_Production)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("Tree has no Prod: %t\n", arg);
  return (PT_Production)NULL;
}

/*}}}  */
/*{{{  PT_Tree PT_setTreeProd(PT_Tree arg, PT_Production prod) */

PT_Tree PT_setTreeProd(PT_Tree arg, PT_Production prod)
{
  if (PT_isTreeAppl(arg)) {
    return (PT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)prod, 0);
  }

  ATabort("Tree has no Prod: %t\n", arg);
  return (PT_Tree)NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasTreeArgs(PT_Tree arg) */

ATbool PT_hasTreeArgs(PT_Tree arg)
{
  if (PT_isTreeAppl(arg)) {
    return ATtrue;
  }
  else if (PT_isTreeAmb(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Args PT_getTreeArgs(PT_Tree arg) */

PT_Args PT_getTreeArgs(PT_Tree arg)
{
  if (PT_isTreeAppl(arg)) {
    return (PT_Args)ATgetArgument((ATermAppl)arg, 1);
  }
  else if (PT_isTreeAmb(arg)) {
    return (PT_Args)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("Tree has no Args: %t\n", arg);
  return (PT_Args)NULL;
}

/*}}}  */
/*{{{  PT_Tree PT_setTreeArgs(PT_Tree arg, PT_Args args) */

PT_Tree PT_setTreeArgs(PT_Tree arg, PT_Args args)
{
  if (PT_isTreeAppl(arg)) {
    return (PT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)args, 1);
  }
  else if (PT_isTreeAmb(arg)) {
    return (PT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)args, 0);
  }

  ATabort("Tree has no Args: %t\n", arg);
  return (PT_Tree)NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasTreeCharacter(PT_Tree arg) */

ATbool PT_hasTreeCharacter(PT_Tree arg)
{
  if (PT_isTreeChar(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int PT_getTreeCharacter(PT_Tree arg) */

int PT_getTreeCharacter(PT_Tree arg)
{
  if (PT_isTreeChar(arg)) {
    return (int)ATgetInt((ATermInt)arg);
  }

  ATabort("Tree has no Character: %t\n", arg);
  return (int)NULL;
}

/*}}}  */
/*{{{  PT_Tree PT_setTreeCharacter(PT_Tree arg, int character) */

PT_Tree PT_setTreeCharacter(PT_Tree arg, int character)
{
  if (PT_isTreeChar(arg)) {
    return (PT_Tree)ATmakeInt(character);
  }

  ATabort("Tree has no Character: %t\n", arg);
  return (PT_Tree)NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasTreeString(PT_Tree arg) */

ATbool PT_hasTreeString(PT_Tree arg)
{
  if (PT_isTreeLit(arg)) {
    return ATtrue;
  }
  else if (PT_isTreeFlatLayout(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * PT_getTreeString(PT_Tree arg) */

char * PT_getTreeString(PT_Tree arg)
{
  if (PT_isTreeLit(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }
  else if (PT_isTreeFlatLayout(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }

  ATabort("Tree has no String: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  PT_Tree PT_setTreeString(PT_Tree arg, char * string) */

PT_Tree PT_setTreeString(PT_Tree arg, char * string)
{
  if (PT_isTreeLit(arg)) {
    return (PT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(string, 0, ATtrue)), 0);
  }
  else if (PT_isTreeFlatLayout(arg)) {
    return (PT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(string, 0, ATtrue)), 0);
  }

  ATabort("Tree has no String: %t\n", arg);
  return (PT_Tree)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PT_Production accessors */

/*{{{  ATbool PT_isValidProduction(PT_Production arg) */

ATbool PT_isValidProduction(PT_Production arg)
{
  if (PT_isProductionDefault(arg)) {
    return ATtrue;
  }
  else if (PT_isProductionList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isProductionDefault(PT_Production arg) */

ATbool PT_isProductionDefault(PT_Production arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternProductionDefault, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isProductionList(PT_Production arg) */

ATbool PT_isProductionList(PT_Production arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternProductionList, NULL);
}

/*}}}  */
/*{{{  ATbool PT_hasProductionLhs(PT_Production arg) */

ATbool PT_hasProductionLhs(PT_Production arg)
{
  if (PT_isProductionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Symbols PT_getProductionLhs(PT_Production arg) */

PT_Symbols PT_getProductionLhs(PT_Production arg)
{
  if (PT_isProductionDefault(arg)) {
    return (PT_Symbols)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("Production has no Lhs: %t\n", arg);
  return (PT_Symbols)NULL;
}

/*}}}  */
/*{{{  PT_Production PT_setProductionLhs(PT_Production arg, PT_Symbols lhs) */

PT_Production PT_setProductionLhs(PT_Production arg, PT_Symbols lhs)
{
  if (PT_isProductionDefault(arg)) {
    return (PT_Production)ATsetArgument((ATermAppl)arg, (ATerm)lhs, 0);
  }

  ATabort("Production has no Lhs: %t\n", arg);
  return (PT_Production)NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasProductionRhs(PT_Production arg) */

ATbool PT_hasProductionRhs(PT_Production arg)
{
  if (PT_isProductionDefault(arg)) {
    return ATtrue;
  }
  else if (PT_isProductionList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Symbol PT_getProductionRhs(PT_Production arg) */

PT_Symbol PT_getProductionRhs(PT_Production arg)
{
  if (PT_isProductionDefault(arg)) {
    return (PT_Symbol)ATgetArgument((ATermAppl)arg, 1);
  }
  else if (PT_isProductionList(arg)) {
    return (PT_Symbol)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("Production has no Rhs: %t\n", arg);
  return (PT_Symbol)NULL;
}

/*}}}  */
/*{{{  PT_Production PT_setProductionRhs(PT_Production arg, PT_Symbol rhs) */

PT_Production PT_setProductionRhs(PT_Production arg, PT_Symbol rhs)
{
  if (PT_isProductionDefault(arg)) {
    return (PT_Production)ATsetArgument((ATermAppl)arg, (ATerm)rhs, 1);
  }
  else if (PT_isProductionList(arg)) {
    return (PT_Production)ATsetArgument((ATermAppl)arg, (ATerm)rhs, 0);
  }

  ATabort("Production has no Rhs: %t\n", arg);
  return (PT_Production)NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasProductionAttributes(PT_Production arg) */

ATbool PT_hasProductionAttributes(PT_Production arg)
{
  if (PT_isProductionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Attributes PT_getProductionAttributes(PT_Production arg) */

PT_Attributes PT_getProductionAttributes(PT_Production arg)
{
  if (PT_isProductionDefault(arg)) {
    return (PT_Attributes)ATgetArgument((ATermAppl)arg, 2);
  }

  ATabort("Production has no Attributes: %t\n", arg);
  return (PT_Attributes)NULL;
}

/*}}}  */
/*{{{  PT_Production PT_setProductionAttributes(PT_Production arg, PT_Attributes attributes) */

PT_Production PT_setProductionAttributes(PT_Production arg, PT_Attributes attributes)
{
  if (PT_isProductionDefault(arg)) {
    return (PT_Production)ATsetArgument((ATermAppl)arg, (ATerm)attributes, 2);
  }

  ATabort("Production has no Attributes: %t\n", arg);
  return (PT_Production)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PT_Attributes accessors */

/*{{{  ATbool PT_isValidAttributes(PT_Attributes arg) */

ATbool PT_isValidAttributes(PT_Attributes arg)
{
  if (PT_isAttributesNoAttrs(arg)) {
    return ATtrue;
  }
  else if (PT_isAttributesAttrs(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isAttributesNoAttrs(PT_Attributes arg) */

ATbool PT_isAttributesNoAttrs(PT_Attributes arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternAttributesNoAttrs);
}

/*}}}  */
/*{{{  ATbool PT_isAttributesAttrs(PT_Attributes arg) */

ATbool PT_isAttributesAttrs(PT_Attributes arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternAttributesAttrs, NULL);
}

/*}}}  */
/*{{{  ATbool PT_hasAttributesAttrs(PT_Attributes arg) */

ATbool PT_hasAttributesAttrs(PT_Attributes arg)
{
  if (PT_isAttributesAttrs(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Attrs PT_getAttributesAttrs(PT_Attributes arg) */

PT_Attrs PT_getAttributesAttrs(PT_Attributes arg)
{
  if (PT_isAttributesAttrs(arg)) {
    return (PT_Attrs)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("Attributes has no Attrs: %t\n", arg);
  return (PT_Attrs)NULL;
}

/*}}}  */
/*{{{  PT_Attributes PT_setAttributesAttrs(PT_Attributes arg, PT_Attrs attrs) */

PT_Attributes PT_setAttributesAttrs(PT_Attributes arg, PT_Attrs attrs)
{
  if (PT_isAttributesAttrs(arg)) {
    return (PT_Attributes)ATsetArgument((ATermAppl)arg, (ATerm)attrs, 0);
  }

  ATabort("Attributes has no Attrs: %t\n", arg);
  return (PT_Attributes)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PT_Attrs accessors */

/*{{{  ATbool PT_isValidAttrs(PT_Attrs arg) */

ATbool PT_isValidAttrs(PT_Attrs arg)
{
  if (PT_isAttrsMany(arg)) {
    return ATtrue;
  }
  else if (PT_isAttrsSingle(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isAttrsMany(PT_Attrs arg) */

ATbool PT_isAttrsMany(PT_Attrs arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternAttrsMany, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isAttrsSingle(PT_Attrs arg) */

ATbool PT_isAttrsSingle(PT_Attrs arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternAttrsSingle, NULL);
}

/*}}}  */
/*{{{  ATbool PT_hasAttrsHead(PT_Attrs arg) */

ATbool PT_hasAttrsHead(PT_Attrs arg)
{
  if (PT_isAttrsMany(arg)) {
    return ATtrue;
  }
  else if (PT_isAttrsSingle(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Attr PT_getAttrsHead(PT_Attrs arg) */

PT_Attr PT_getAttrsHead(PT_Attrs arg)
{
  if (PT_isAttrsMany(arg)) {
    return (PT_Attr)ATelementAt((ATermList)arg, 0);
  }
  else if (PT_isAttrsSingle(arg)) {
    return (PT_Attr)ATelementAt((ATermList)arg, 0);
  }

  ATabort("Attrs has no Head: %t\n", arg);
  return (PT_Attr)NULL;
}

/*}}}  */
/*{{{  PT_Attrs PT_setAttrsHead(PT_Attrs arg, PT_Attr head) */

PT_Attrs PT_setAttrsHead(PT_Attrs arg, PT_Attr head)
{
  if (PT_isAttrsMany(arg)) {
    return (PT_Attrs)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (PT_isAttrsSingle(arg)) {
    return (PT_Attrs)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("Attrs has no Head: %t\n", arg);
  return (PT_Attrs)NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasAttrsTail(PT_Attrs arg) */

ATbool PT_hasAttrsTail(PT_Attrs arg)
{
  if (PT_isAttrsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Attrs PT_getAttrsTail(PT_Attrs arg) */

PT_Attrs PT_getAttrsTail(PT_Attrs arg)
{
  if (PT_isAttrsMany(arg)) {
    return (PT_Attrs)ATgetTail((ATermList)arg, 1);
  }

  ATabort("Attrs has no Tail: %t\n", arg);
  return (PT_Attrs)NULL;
}

/*}}}  */
/*{{{  PT_Attrs PT_setAttrsTail(PT_Attrs arg, PT_Attrs tail) */

PT_Attrs PT_setAttrsTail(PT_Attrs arg, PT_Attrs tail)
{
  if (PT_isAttrsMany(arg)) {
    return (PT_Attrs)ATreplaceTail((ATermList)arg, (ATermList)tail, 1);
  }

  ATabort("Attrs has no Tail: %t\n", arg);
  return (PT_Attrs)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PT_Attr accessors */

/*{{{  ATbool PT_isValidAttr(PT_Attr arg) */

ATbool PT_isValidAttr(PT_Attr arg)
{
  if (PT_isAttrCons(arg)) {
    return ATtrue;
  }
  else if (PT_isAttrId(arg)) {
    return ATtrue;
  }
  else if (PT_isAttrAterm(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isAttrCons(PT_Attr arg) */

ATbool PT_isAttrCons(PT_Attr arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternAttrCons, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isAttrId(PT_Attr arg) */

ATbool PT_isAttrId(PT_Attr arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternAttrId, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isAttrAterm(PT_Attr arg) */

ATbool PT_isAttrAterm(PT_Attr arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternAttrAterm, NULL);
}

/*}}}  */
/*{{{  ATbool PT_hasAttrString(PT_Attr arg) */

ATbool PT_hasAttrString(PT_Attr arg)
{
  if (PT_isAttrCons(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * PT_getAttrString(PT_Attr arg) */

char * PT_getAttrString(PT_Attr arg)
{
  if (PT_isAttrCons(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }

  ATabort("Attr has no String: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  PT_Attr PT_setAttrString(PT_Attr arg, char * string) */

PT_Attr PT_setAttrString(PT_Attr arg, char * string)
{
  if (PT_isAttrCons(arg)) {
    return (PT_Attr)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(string, 0, ATtrue)), 0);
  }

  ATabort("Attr has no String: %t\n", arg);
  return (PT_Attr)NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasAttrModuleName(PT_Attr arg) */

ATbool PT_hasAttrModuleName(PT_Attr arg)
{
  if (PT_isAttrId(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * PT_getAttrModuleName(PT_Attr arg) */

char * PT_getAttrModuleName(PT_Attr arg)
{
  if (PT_isAttrId(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }

  ATabort("Attr has no ModuleName: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  PT_Attr PT_setAttrModuleName(PT_Attr arg, char * moduleName) */

PT_Attr PT_setAttrModuleName(PT_Attr arg, char * moduleName)
{
  if (PT_isAttrId(arg)) {
    return (PT_Attr)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(moduleName, 0, ATtrue)), 0);
  }

  ATabort("Attr has no ModuleName: %t\n", arg);
  return (PT_Attr)NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasAttrTerm(PT_Attr arg) */

ATbool PT_hasAttrTerm(PT_Attr arg)
{
  if (PT_isAttrAterm(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_ATerm PT_getAttrTerm(PT_Attr arg) */

PT_ATerm PT_getAttrTerm(PT_Attr arg)
{
  if (PT_isAttrAterm(arg)) {
    return (PT_ATerm)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("Attr has no Term: %t\n", arg);
  return (PT_ATerm)NULL;
}

/*}}}  */
/*{{{  PT_Attr PT_setAttrTerm(PT_Attr arg, PT_ATerm term) */

PT_Attr PT_setAttrTerm(PT_Attr arg, PT_ATerm term)
{
  if (PT_isAttrAterm(arg)) {
    return (PT_Attr)ATsetArgument((ATermAppl)arg, (ATerm)term, 0);
  }

  ATabort("Attr has no Term: %t\n", arg);
  return (PT_Attr)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PT_ATerm accessors */

/*{{{  ATbool PT_isValidATerm(PT_ATerm arg) */

ATbool PT_isValidATerm(PT_ATerm arg)
{
  if (PT_isATermBracket(arg)) {
    return ATtrue;
  }
  else if (PT_isATermLeft(arg)) {
    return ATtrue;
  }
  else if (PT_isATermRight(arg)) {
    return ATtrue;
  }
  else if (PT_isATermAssoc(arg)) {
    return ATtrue;
  }
  else if (PT_isATermNonAssoc(arg)) {
    return ATtrue;
  }
  else if (PT_isATermMemo(arg)) {
    return ATtrue;
  }
  else if (PT_isATermReject(arg)) {
    return ATtrue;
  }
  else if (PT_isATermPrefer(arg)) {
    return ATtrue;
  }
  else if (PT_isATermAvoid(arg)) {
    return ATtrue;
  }
  else if (PT_isATermConstructor(arg)) {
    return ATtrue;
  }
  else if (PT_isATermTraverse(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isATermBracket(PT_ATerm arg) */

ATbool PT_isATermBracket(PT_ATerm arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternATermBracket);
}

/*}}}  */
/*{{{  ATbool PT_isATermLeft(PT_ATerm arg) */

ATbool PT_isATermLeft(PT_ATerm arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternATermLeft);
}

/*}}}  */
/*{{{  ATbool PT_isATermRight(PT_ATerm arg) */

ATbool PT_isATermRight(PT_ATerm arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternATermRight);
}

/*}}}  */
/*{{{  ATbool PT_isATermAssoc(PT_ATerm arg) */

ATbool PT_isATermAssoc(PT_ATerm arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternATermAssoc);
}

/*}}}  */
/*{{{  ATbool PT_isATermNonAssoc(PT_ATerm arg) */

ATbool PT_isATermNonAssoc(PT_ATerm arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternATermNonAssoc);
}

/*}}}  */
/*{{{  ATbool PT_isATermMemo(PT_ATerm arg) */

ATbool PT_isATermMemo(PT_ATerm arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternATermMemo);
}

/*}}}  */
/*{{{  ATbool PT_isATermReject(PT_ATerm arg) */

ATbool PT_isATermReject(PT_ATerm arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternATermReject);
}

/*}}}  */
/*{{{  ATbool PT_isATermPrefer(PT_ATerm arg) */

ATbool PT_isATermPrefer(PT_ATerm arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternATermPrefer);
}

/*}}}  */
/*{{{  ATbool PT_isATermAvoid(PT_ATerm arg) */

ATbool PT_isATermAvoid(PT_ATerm arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternATermAvoid);
}

/*}}}  */
/*{{{  ATbool PT_isATermConstructor(PT_ATerm arg) */

ATbool PT_isATermConstructor(PT_ATerm arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternATermConstructor);
}

/*}}}  */
/*{{{  ATbool PT_isATermTraverse(PT_ATerm arg) */

ATbool PT_isATermTraverse(PT_ATerm arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternATermTraverse);
}

/*}}}  */

/*}}}  */
/*{{{  PT_Args accessors */

/*{{{  ATbool PT_isValidArgs(PT_Args arg) */

ATbool PT_isValidArgs(PT_Args arg)
{
  if (PT_isArgsList(arg)) {
    return ATtrue;
  }
  else if (PT_isArgsEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isArgsList(PT_Args arg) */

ATbool PT_isArgsList(PT_Args arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternArgsList, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isArgsEmpty(PT_Args arg) */

ATbool PT_isArgsEmpty(PT_Args arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternArgsEmpty);
}

/*}}}  */
/*{{{  ATbool PT_hasArgsHead(PT_Args arg) */

ATbool PT_hasArgsHead(PT_Args arg)
{
  if (PT_isArgsList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Tree PT_getArgsHead(PT_Args arg) */

PT_Tree PT_getArgsHead(PT_Args arg)
{
  if (PT_isArgsList(arg)) {
    return (PT_Tree)ATelementAt((ATermList)arg, 0);
  }

  ATabort("Args has no Head: %t\n", arg);
  return (PT_Tree)NULL;
}

/*}}}  */
/*{{{  PT_Args PT_setArgsHead(PT_Args arg, PT_Tree head) */

PT_Args PT_setArgsHead(PT_Args arg, PT_Tree head)
{
  if (PT_isArgsList(arg)) {
    return (PT_Args)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("Args has no Head: %t\n", arg);
  return (PT_Args)NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasArgsTail(PT_Args arg) */

ATbool PT_hasArgsTail(PT_Args arg)
{
  if (PT_isArgsList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Args PT_getArgsTail(PT_Args arg) */

PT_Args PT_getArgsTail(PT_Args arg)
{
  if (PT_isArgsList(arg)) {
    return (PT_Args)ATgetTail((ATermList)arg, 1);
  }

  ATabort("Args has no Tail: %t\n", arg);
  return (PT_Args)NULL;
}

/*}}}  */
/*{{{  PT_Args PT_setArgsTail(PT_Args arg, PT_Args tail) */

PT_Args PT_setArgsTail(PT_Args arg, PT_Args tail)
{
  if (PT_isArgsList(arg)) {
    return (PT_Args)ATreplaceTail((ATermList)arg, (ATermList)tail, 1);
  }

  ATabort("Args has no Tail: %t\n", arg);
  return (PT_Args)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PT_Symbol accessors */

/*{{{  ATbool PT_isValidSymbol(PT_Symbol arg) */

ATbool PT_isValidSymbol(PT_Symbol arg)
{
  if (PT_isSymbolLit(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolCf(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolLex(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolEmpty(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolSeq(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolOpt(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolAlt(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolPair(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolSort(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolIterPlus(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolIterStar(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolIterPlusSep(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolIterStarSep(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolIterN(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolIterSepN(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolPerm(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolSet(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolFunc(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolVarSym(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolLayout(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolCharClass(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isSymbolLit(PT_Symbol arg) */

ATbool PT_isSymbolLit(PT_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternSymbolLit, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isSymbolCf(PT_Symbol arg) */

ATbool PT_isSymbolCf(PT_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternSymbolCf, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isSymbolLex(PT_Symbol arg) */

ATbool PT_isSymbolLex(PT_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternSymbolLex, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isSymbolEmpty(PT_Symbol arg) */

ATbool PT_isSymbolEmpty(PT_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternSymbolEmpty);
}

/*}}}  */
/*{{{  ATbool PT_isSymbolSeq(PT_Symbol arg) */

ATbool PT_isSymbolSeq(PT_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternSymbolSeq, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isSymbolOpt(PT_Symbol arg) */

ATbool PT_isSymbolOpt(PT_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternSymbolOpt, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isSymbolAlt(PT_Symbol arg) */

ATbool PT_isSymbolAlt(PT_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternSymbolAlt, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isSymbolPair(PT_Symbol arg) */

ATbool PT_isSymbolPair(PT_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternSymbolPair, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isSymbolSort(PT_Symbol arg) */

ATbool PT_isSymbolSort(PT_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternSymbolSort, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isSymbolIterPlus(PT_Symbol arg) */

ATbool PT_isSymbolIterPlus(PT_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternSymbolIterPlus, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isSymbolIterStar(PT_Symbol arg) */

ATbool PT_isSymbolIterStar(PT_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternSymbolIterStar, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isSymbolIterPlusSep(PT_Symbol arg) */

ATbool PT_isSymbolIterPlusSep(PT_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternSymbolIterPlusSep, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isSymbolIterStarSep(PT_Symbol arg) */

ATbool PT_isSymbolIterStarSep(PT_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternSymbolIterStarSep, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isSymbolIterN(PT_Symbol arg) */

ATbool PT_isSymbolIterN(PT_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternSymbolIterN, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isSymbolIterSepN(PT_Symbol arg) */

ATbool PT_isSymbolIterSepN(PT_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternSymbolIterSepN, NULL, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isSymbolPerm(PT_Symbol arg) */

ATbool PT_isSymbolPerm(PT_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternSymbolPerm, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isSymbolSet(PT_Symbol arg) */

ATbool PT_isSymbolSet(PT_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternSymbolSet, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isSymbolFunc(PT_Symbol arg) */

ATbool PT_isSymbolFunc(PT_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternSymbolFunc, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isSymbolVarSym(PT_Symbol arg) */

ATbool PT_isSymbolVarSym(PT_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternSymbolVarSym, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isSymbolLayout(PT_Symbol arg) */

ATbool PT_isSymbolLayout(PT_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternSymbolLayout);
}

/*}}}  */
/*{{{  ATbool PT_isSymbolCharClass(PT_Symbol arg) */

ATbool PT_isSymbolCharClass(PT_Symbol arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternSymbolCharClass, NULL);
}

/*}}}  */
/*{{{  ATbool PT_hasSymbolString(PT_Symbol arg) */

ATbool PT_hasSymbolString(PT_Symbol arg)
{
  if (PT_isSymbolLit(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolSort(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char * PT_getSymbolString(PT_Symbol arg) */

char * PT_getSymbolString(PT_Symbol arg)
{
  if (PT_isSymbolLit(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }
  else if (PT_isSymbolSort(arg)) {
    return (char *)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }

  ATabort("Symbol has no String: %t\n", arg);
  return (char *)NULL;
}

/*}}}  */
/*{{{  PT_Symbol PT_setSymbolString(PT_Symbol arg, char * string) */

PT_Symbol PT_setSymbolString(PT_Symbol arg, char * string)
{
  if (PT_isSymbolLit(arg)) {
    return (PT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(string, 0, ATtrue)), 0);
  }
  else if (PT_isSymbolSort(arg)) {
    return (PT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(string, 0, ATtrue)), 0);
  }

  ATabort("Symbol has no String: %t\n", arg);
  return (PT_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasSymbolSymbol(PT_Symbol arg) */

ATbool PT_hasSymbolSymbol(PT_Symbol arg)
{
  if (PT_isSymbolCf(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolLex(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolOpt(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolIterPlus(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolIterStar(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolIterPlusSep(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolIterStarSep(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolIterN(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolIterSepN(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolSet(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolFunc(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolVarSym(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Symbol PT_getSymbolSymbol(PT_Symbol arg) */

PT_Symbol PT_getSymbolSymbol(PT_Symbol arg)
{
  if (PT_isSymbolCf(arg)) {
    return (PT_Symbol)ATgetArgument((ATermAppl)arg, 0);
  }
  else if (PT_isSymbolLex(arg)) {
    return (PT_Symbol)ATgetArgument((ATermAppl)arg, 0);
  }
  else if (PT_isSymbolOpt(arg)) {
    return (PT_Symbol)ATgetArgument((ATermAppl)arg, 0);
  }
  else if (PT_isSymbolIterPlus(arg)) {
    return (PT_Symbol)ATgetArgument((ATermAppl)arg, 0);
  }
  else if (PT_isSymbolIterStar(arg)) {
    return (PT_Symbol)ATgetArgument((ATermAppl)arg, 0);
  }
  else if (PT_isSymbolIterPlusSep(arg)) {
    return (PT_Symbol)ATgetArgument((ATermAppl)arg, 0);
  }
  else if (PT_isSymbolIterStarSep(arg)) {
    return (PT_Symbol)ATgetArgument((ATermAppl)arg, 0);
  }
  else if (PT_isSymbolIterN(arg)) {
    return (PT_Symbol)ATgetArgument((ATermAppl)arg, 0);
  }
  else if (PT_isSymbolIterSepN(arg)) {
    return (PT_Symbol)ATgetArgument((ATermAppl)arg, 0);
  }
  else if (PT_isSymbolSet(arg)) {
    return (PT_Symbol)ATgetArgument((ATermAppl)arg, 0);
  }
  else if (PT_isSymbolFunc(arg)) {
    return (PT_Symbol)ATgetArgument((ATermAppl)arg, 1);
  }
  else if (PT_isSymbolVarSym(arg)) {
    return (PT_Symbol)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("Symbol has no Symbol: %t\n", arg);
  return (PT_Symbol)NULL;
}

/*}}}  */
/*{{{  PT_Symbol PT_setSymbolSymbol(PT_Symbol arg, PT_Symbol symbol) */

PT_Symbol PT_setSymbolSymbol(PT_Symbol arg, PT_Symbol symbol)
{
  if (PT_isSymbolCf(arg)) {
    return (PT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)symbol, 0);
  }
  else if (PT_isSymbolLex(arg)) {
    return (PT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)symbol, 0);
  }
  else if (PT_isSymbolOpt(arg)) {
    return (PT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)symbol, 0);
  }
  else if (PT_isSymbolIterPlus(arg)) {
    return (PT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)symbol, 0);
  }
  else if (PT_isSymbolIterStar(arg)) {
    return (PT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)symbol, 0);
  }
  else if (PT_isSymbolIterPlusSep(arg)) {
    return (PT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)symbol, 0);
  }
  else if (PT_isSymbolIterStarSep(arg)) {
    return (PT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)symbol, 0);
  }
  else if (PT_isSymbolIterN(arg)) {
    return (PT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)symbol, 0);
  }
  else if (PT_isSymbolIterSepN(arg)) {
    return (PT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)symbol, 0);
  }
  else if (PT_isSymbolSet(arg)) {
    return (PT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)symbol, 0);
  }
  else if (PT_isSymbolFunc(arg)) {
    return (PT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)symbol, 1);
  }
  else if (PT_isSymbolVarSym(arg)) {
    return (PT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)symbol, 0);
  }

  ATabort("Symbol has no Symbol: %t\n", arg);
  return (PT_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasSymbolSymbols(PT_Symbol arg) */

ATbool PT_hasSymbolSymbols(PT_Symbol arg)
{
  if (PT_isSymbolSeq(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolPerm(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolFunc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Symbols PT_getSymbolSymbols(PT_Symbol arg) */

PT_Symbols PT_getSymbolSymbols(PT_Symbol arg)
{
  if (PT_isSymbolSeq(arg)) {
    return (PT_Symbols)ATgetArgument((ATermAppl)arg, 0);
  }
  else if (PT_isSymbolPerm(arg)) {
    return (PT_Symbols)ATgetArgument((ATermAppl)arg, 0);
  }
  else if (PT_isSymbolFunc(arg)) {
    return (PT_Symbols)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("Symbol has no Symbols: %t\n", arg);
  return (PT_Symbols)NULL;
}

/*}}}  */
/*{{{  PT_Symbol PT_setSymbolSymbols(PT_Symbol arg, PT_Symbols symbols) */

PT_Symbol PT_setSymbolSymbols(PT_Symbol arg, PT_Symbols symbols)
{
  if (PT_isSymbolSeq(arg)) {
    return (PT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)symbols, 0);
  }
  else if (PT_isSymbolPerm(arg)) {
    return (PT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)symbols, 0);
  }
  else if (PT_isSymbolFunc(arg)) {
    return (PT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)symbols, 0);
  }

  ATabort("Symbol has no Symbols: %t\n", arg);
  return (PT_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasSymbolLhs(PT_Symbol arg) */

ATbool PT_hasSymbolLhs(PT_Symbol arg)
{
  if (PT_isSymbolAlt(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolPair(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Symbol PT_getSymbolLhs(PT_Symbol arg) */

PT_Symbol PT_getSymbolLhs(PT_Symbol arg)
{
  if (PT_isSymbolAlt(arg)) {
    return (PT_Symbol)ATgetArgument((ATermAppl)arg, 0);
  }
  else if (PT_isSymbolPair(arg)) {
    return (PT_Symbol)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("Symbol has no Lhs: %t\n", arg);
  return (PT_Symbol)NULL;
}

/*}}}  */
/*{{{  PT_Symbol PT_setSymbolLhs(PT_Symbol arg, PT_Symbol lhs) */

PT_Symbol PT_setSymbolLhs(PT_Symbol arg, PT_Symbol lhs)
{
  if (PT_isSymbolAlt(arg)) {
    return (PT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)lhs, 0);
  }
  else if (PT_isSymbolPair(arg)) {
    return (PT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)lhs, 0);
  }

  ATabort("Symbol has no Lhs: %t\n", arg);
  return (PT_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasSymbolRhs(PT_Symbol arg) */

ATbool PT_hasSymbolRhs(PT_Symbol arg)
{
  if (PT_isSymbolAlt(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolPair(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Symbol PT_getSymbolRhs(PT_Symbol arg) */

PT_Symbol PT_getSymbolRhs(PT_Symbol arg)
{
  if (PT_isSymbolAlt(arg)) {
    return (PT_Symbol)ATgetArgument((ATermAppl)arg, 1);
  }
  else if (PT_isSymbolPair(arg)) {
    return (PT_Symbol)ATgetArgument((ATermAppl)arg, 1);
  }

  ATabort("Symbol has no Rhs: %t\n", arg);
  return (PT_Symbol)NULL;
}

/*}}}  */
/*{{{  PT_Symbol PT_setSymbolRhs(PT_Symbol arg, PT_Symbol rhs) */

PT_Symbol PT_setSymbolRhs(PT_Symbol arg, PT_Symbol rhs)
{
  if (PT_isSymbolAlt(arg)) {
    return (PT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)rhs, 1);
  }
  else if (PT_isSymbolPair(arg)) {
    return (PT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)rhs, 1);
  }

  ATabort("Symbol has no Rhs: %t\n", arg);
  return (PT_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasSymbolSeparator(PT_Symbol arg) */

ATbool PT_hasSymbolSeparator(PT_Symbol arg)
{
  if (PT_isSymbolIterPlusSep(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolIterStarSep(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolIterSepN(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Symbol PT_getSymbolSeparator(PT_Symbol arg) */

PT_Symbol PT_getSymbolSeparator(PT_Symbol arg)
{
  if (PT_isSymbolIterPlusSep(arg)) {
    return (PT_Symbol)ATgetArgument((ATermAppl)arg, 1);
  }
  else if (PT_isSymbolIterStarSep(arg)) {
    return (PT_Symbol)ATgetArgument((ATermAppl)arg, 1);
  }
  else if (PT_isSymbolIterSepN(arg)) {
    return (PT_Symbol)ATgetArgument((ATermAppl)arg, 1);
  }

  ATabort("Symbol has no Separator: %t\n", arg);
  return (PT_Symbol)NULL;
}

/*}}}  */
/*{{{  PT_Symbol PT_setSymbolSeparator(PT_Symbol arg, PT_Symbol separator) */

PT_Symbol PT_setSymbolSeparator(PT_Symbol arg, PT_Symbol separator)
{
  if (PT_isSymbolIterPlusSep(arg)) {
    return (PT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)separator, 1);
  }
  else if (PT_isSymbolIterStarSep(arg)) {
    return (PT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)separator, 1);
  }
  else if (PT_isSymbolIterSepN(arg)) {
    return (PT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)separator, 1);
  }

  ATabort("Symbol has no Separator: %t\n", arg);
  return (PT_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasSymbolNumber(PT_Symbol arg) */

ATbool PT_hasSymbolNumber(PT_Symbol arg)
{
  if (PT_isSymbolIterN(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolIterSepN(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int PT_getSymbolNumber(PT_Symbol arg) */

int PT_getSymbolNumber(PT_Symbol arg)
{
  if (PT_isSymbolIterN(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (PT_isSymbolIterSepN(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 2));
  }

  ATabort("Symbol has no Number: %t\n", arg);
  return (int)NULL;
}

/*}}}  */
/*{{{  PT_Symbol PT_setSymbolNumber(PT_Symbol arg, int number) */

PT_Symbol PT_setSymbolNumber(PT_Symbol arg, int number)
{
  if (PT_isSymbolIterN(arg)) {
    return (PT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(number), 1);
  }
  else if (PT_isSymbolIterSepN(arg)) {
    return (PT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(number), 2);
  }

  ATabort("Symbol has no Number: %t\n", arg);
  return (PT_Symbol)NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasSymbolRanges(PT_Symbol arg) */

ATbool PT_hasSymbolRanges(PT_Symbol arg)
{
  if (PT_isSymbolCharClass(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_CharRanges PT_getSymbolRanges(PT_Symbol arg) */

PT_CharRanges PT_getSymbolRanges(PT_Symbol arg)
{
  if (PT_isSymbolCharClass(arg)) {
    return (PT_CharRanges)ATgetArgument((ATermAppl)arg, 0);
  }

  ATabort("Symbol has no Ranges: %t\n", arg);
  return (PT_CharRanges)NULL;
}

/*}}}  */
/*{{{  PT_Symbol PT_setSymbolRanges(PT_Symbol arg, PT_CharRanges ranges) */

PT_Symbol PT_setSymbolRanges(PT_Symbol arg, PT_CharRanges ranges)
{
  if (PT_isSymbolCharClass(arg)) {
    return (PT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ranges, 0);
  }

  ATabort("Symbol has no Ranges: %t\n", arg);
  return (PT_Symbol)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PT_Symbols accessors */

/*{{{  ATbool PT_isValidSymbols(PT_Symbols arg) */

ATbool PT_isValidSymbols(PT_Symbols arg)
{
  if (PT_isSymbolsList(arg)) {
    return ATtrue;
  }
  else if (PT_isSymbolsEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isSymbolsList(PT_Symbols arg) */

ATbool PT_isSymbolsList(PT_Symbols arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternSymbolsList, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isSymbolsEmpty(PT_Symbols arg) */

ATbool PT_isSymbolsEmpty(PT_Symbols arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternSymbolsEmpty);
}

/*}}}  */
/*{{{  ATbool PT_hasSymbolsHead(PT_Symbols arg) */

ATbool PT_hasSymbolsHead(PT_Symbols arg)
{
  if (PT_isSymbolsList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Symbol PT_getSymbolsHead(PT_Symbols arg) */

PT_Symbol PT_getSymbolsHead(PT_Symbols arg)
{
  if (PT_isSymbolsList(arg)) {
    return (PT_Symbol)ATelementAt((ATermList)arg, 0);
  }

  ATabort("Symbols has no Head: %t\n", arg);
  return (PT_Symbol)NULL;
}

/*}}}  */
/*{{{  PT_Symbols PT_setSymbolsHead(PT_Symbols arg, PT_Symbol head) */

PT_Symbols PT_setSymbolsHead(PT_Symbols arg, PT_Symbol head)
{
  if (PT_isSymbolsList(arg)) {
    return (PT_Symbols)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("Symbols has no Head: %t\n", arg);
  return (PT_Symbols)NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasSymbolsTail(PT_Symbols arg) */

ATbool PT_hasSymbolsTail(PT_Symbols arg)
{
  if (PT_isSymbolsList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_Symbols PT_getSymbolsTail(PT_Symbols arg) */

PT_Symbols PT_getSymbolsTail(PT_Symbols arg)
{
  if (PT_isSymbolsList(arg)) {
    return (PT_Symbols)ATgetTail((ATermList)arg, 1);
  }

  ATabort("Symbols has no Tail: %t\n", arg);
  return (PT_Symbols)NULL;
}

/*}}}  */
/*{{{  PT_Symbols PT_setSymbolsTail(PT_Symbols arg, PT_Symbols tail) */

PT_Symbols PT_setSymbolsTail(PT_Symbols arg, PT_Symbols tail)
{
  if (PT_isSymbolsList(arg)) {
    return (PT_Symbols)ATreplaceTail((ATermList)arg, (ATermList)tail, 1);
  }

  ATabort("Symbols has no Tail: %t\n", arg);
  return (PT_Symbols)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PT_CharRange accessors */

/*{{{  ATbool PT_isValidCharRange(PT_CharRange arg) */

ATbool PT_isValidCharRange(PT_CharRange arg)
{
  if (PT_isCharRangeCharacter(arg)) {
    return ATtrue;
  }
  else if (PT_isCharRangeRange(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isCharRangeCharacter(PT_CharRange arg) */

ATbool PT_isCharRangeCharacter(PT_CharRange arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternCharRangeCharacter, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isCharRangeRange(PT_CharRange arg) */

ATbool PT_isCharRangeRange(PT_CharRange arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternCharRangeRange, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool PT_hasCharRangeInteger(PT_CharRange arg) */

ATbool PT_hasCharRangeInteger(PT_CharRange arg)
{
  if (PT_isCharRangeCharacter(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int PT_getCharRangeInteger(PT_CharRange arg) */

int PT_getCharRangeInteger(PT_CharRange arg)
{
  if (PT_isCharRangeCharacter(arg)) {
    return (int)ATgetInt((ATermInt)arg);
  }

  ATabort("CharRange has no Integer: %t\n", arg);
  return (int)NULL;
}

/*}}}  */
/*{{{  PT_CharRange PT_setCharRangeInteger(PT_CharRange arg, int integer) */

PT_CharRange PT_setCharRangeInteger(PT_CharRange arg, int integer)
{
  if (PT_isCharRangeCharacter(arg)) {
    return (PT_CharRange)ATmakeInt(integer);
  }

  ATabort("CharRange has no Integer: %t\n", arg);
  return (PT_CharRange)NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasCharRangeStart(PT_CharRange arg) */

ATbool PT_hasCharRangeStart(PT_CharRange arg)
{
  if (PT_isCharRangeRange(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int PT_getCharRangeStart(PT_CharRange arg) */

int PT_getCharRangeStart(PT_CharRange arg)
{
  if (PT_isCharRangeRange(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 0));
  }

  ATabort("CharRange has no Start: %t\n", arg);
  return (int)NULL;
}

/*}}}  */
/*{{{  PT_CharRange PT_setCharRangeStart(PT_CharRange arg, int start) */

PT_CharRange PT_setCharRangeStart(PT_CharRange arg, int start)
{
  if (PT_isCharRangeRange(arg)) {
    return (PT_CharRange)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(start), 0);
  }

  ATabort("CharRange has no Start: %t\n", arg);
  return (PT_CharRange)NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasCharRangeEnd(PT_CharRange arg) */

ATbool PT_hasCharRangeEnd(PT_CharRange arg)
{
  if (PT_isCharRangeRange(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int PT_getCharRangeEnd(PT_CharRange arg) */

int PT_getCharRangeEnd(PT_CharRange arg)
{
  if (PT_isCharRangeRange(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }

  ATabort("CharRange has no End: %t\n", arg);
  return (int)NULL;
}

/*}}}  */
/*{{{  PT_CharRange PT_setCharRangeEnd(PT_CharRange arg, int end) */

PT_CharRange PT_setCharRangeEnd(PT_CharRange arg, int end)
{
  if (PT_isCharRangeRange(arg)) {
    return (PT_CharRange)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(end), 1);
  }

  ATabort("CharRange has no End: %t\n", arg);
  return (PT_CharRange)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PT_CharRanges accessors */

/*{{{  ATbool PT_isValidCharRanges(PT_CharRanges arg) */

ATbool PT_isValidCharRanges(PT_CharRanges arg)
{
  if (PT_isCharRangesList(arg)) {
    return ATtrue;
  }
  else if (PT_isCharRangesEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PT_isCharRangesList(PT_CharRanges arg) */

ATbool PT_isCharRangesList(PT_CharRanges arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternCharRangesList, NULL, NULL);
}

/*}}}  */
/*{{{  ATbool PT_isCharRangesEmpty(PT_CharRanges arg) */

ATbool PT_isCharRangesEmpty(PT_CharRanges arg)
{
  return ATmatchTerm((ATerm)arg, PT_patternCharRangesEmpty);
}

/*}}}  */
/*{{{  ATbool PT_hasCharRangesHead(PT_CharRanges arg) */

ATbool PT_hasCharRangesHead(PT_CharRanges arg)
{
  if (PT_isCharRangesList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_CharRange PT_getCharRangesHead(PT_CharRanges arg) */

PT_CharRange PT_getCharRangesHead(PT_CharRanges arg)
{
  if (PT_isCharRangesList(arg)) {
    return (PT_CharRange)ATelementAt((ATermList)arg, 0);
  }

  ATabort("CharRanges has no Head: %t\n", arg);
  return (PT_CharRange)NULL;
}

/*}}}  */
/*{{{  PT_CharRanges PT_setCharRangesHead(PT_CharRanges arg, PT_CharRange head) */

PT_CharRanges PT_setCharRangesHead(PT_CharRanges arg, PT_CharRange head)
{
  if (PT_isCharRangesList(arg)) {
    return (PT_CharRanges)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("CharRanges has no Head: %t\n", arg);
  return (PT_CharRanges)NULL;
}

/*}}}  */
/*{{{  ATbool PT_hasCharRangesTail(PT_CharRanges arg) */

ATbool PT_hasCharRangesTail(PT_CharRanges arg)
{
  if (PT_isCharRangesList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PT_CharRanges PT_getCharRangesTail(PT_CharRanges arg) */

PT_CharRanges PT_getCharRangesTail(PT_CharRanges arg)
{
  if (PT_isCharRangesList(arg)) {
    return (PT_CharRanges)ATgetTail((ATermList)arg, 1);
  }

  ATabort("CharRanges has no Tail: %t\n", arg);
  return (PT_CharRanges)NULL;
}

/*}}}  */
/*{{{  PT_CharRanges PT_setCharRangesTail(PT_CharRanges arg, PT_CharRanges tail) */

PT_CharRanges PT_setCharRangesTail(PT_CharRanges arg, PT_CharRanges tail)
{
  if (PT_isCharRangesList(arg)) {
    return (PT_CharRanges)ATreplaceTail((ATermList)arg, (ATermList)tail, 1);
  }

  ATabort("CharRanges has no Tail: %t\n", arg);
  return (PT_CharRanges)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  PT_ParseTree PT_visitParseTree(PT_ParseTree arg, PT_Symbols (*acceptLhs)(PT_Symbols), PT_Tree (*acceptLayoutBeforeTree)(PT_Tree), PT_Tree (*acceptTree)(PT_Tree), PT_Tree (*acceptLayoutAfterTree)(PT_Tree), int (*acceptAmbCnt)(int)) */

PT_ParseTree PT_visitParseTree(PT_ParseTree arg, PT_Symbols (*acceptLhs)(PT_Symbols), PT_Tree (*acceptLayoutBeforeTree)(PT_Tree), PT_Tree (*acceptTree)(PT_Tree), PT_Tree (*acceptLayoutAfterTree)(PT_Tree), int (*acceptAmbCnt)(int))
{
  if (PT_isParseTreeTree(arg)) {
    return PT_makeParseTreeTree(
        acceptLhs ? acceptLhs(PT_getParseTreeLhs(arg)) : PT_getParseTreeLhs(arg),
        acceptLayoutBeforeTree ? acceptLayoutBeforeTree(PT_getParseTreeLayoutBeforeTree(arg)) : PT_getParseTreeLayoutBeforeTree(arg),
        acceptTree ? acceptTree(PT_getParseTreeTree(arg)) : PT_getParseTreeTree(arg),
        acceptLayoutAfterTree ? acceptLayoutAfterTree(PT_getParseTreeLayoutAfterTree(arg)) : PT_getParseTreeLayoutAfterTree(arg),
        acceptAmbCnt ? acceptAmbCnt(PT_getParseTreeAmbCnt(arg)) : PT_getParseTreeAmbCnt(arg));
  }
  ATabort("not a ParseTree: %t\n", arg);
  return (PT_ParseTree)NULL;
}

/*}}}  */
/*{{{  PT_Tree PT_visitTree(PT_Tree arg, PT_Production (*acceptProd)(PT_Production), PT_Args (*acceptArgs)(PT_Args), int (*acceptCharacter)(int), char * (*acceptString)(char *)) */

PT_Tree PT_visitTree(PT_Tree arg, PT_Production (*acceptProd)(PT_Production), PT_Args (*acceptArgs)(PT_Args), int (*acceptCharacter)(int), char * (*acceptString)(char *))
{
  if (PT_isTreeAppl(arg)) {
    return PT_makeTreeAppl(
        acceptProd ? acceptProd(PT_getTreeProd(arg)) : PT_getTreeProd(arg),
        acceptArgs ? acceptArgs(PT_getTreeArgs(arg)) : PT_getTreeArgs(arg));
  }
  if (PT_isTreeChar(arg)) {
    return PT_makeTreeChar(
        acceptCharacter ? acceptCharacter(PT_getTreeCharacter(arg)) : PT_getTreeCharacter(arg));
  }
  if (PT_isTreeLit(arg)) {
    return PT_makeTreeLit(
        acceptString ? acceptString(PT_getTreeString(arg)) : PT_getTreeString(arg));
  }
  if (PT_isTreeFlatLayout(arg)) {
    return PT_makeTreeFlatLayout(
        acceptString ? acceptString(PT_getTreeString(arg)) : PT_getTreeString(arg));
  }
  if (PT_isTreeAmb(arg)) {
    return PT_makeTreeAmb(
        acceptArgs ? acceptArgs(PT_getTreeArgs(arg)) : PT_getTreeArgs(arg));
  }
  ATabort("not a Tree: %t\n", arg);
  return (PT_Tree)NULL;
}

/*}}}  */
/*{{{  PT_Production PT_visitProduction(PT_Production arg, PT_Symbols (*acceptLhs)(PT_Symbols), PT_Symbol (*acceptRhs)(PT_Symbol), PT_Attributes (*acceptAttributes)(PT_Attributes)) */

PT_Production PT_visitProduction(PT_Production arg, PT_Symbols (*acceptLhs)(PT_Symbols), PT_Symbol (*acceptRhs)(PT_Symbol), PT_Attributes (*acceptAttributes)(PT_Attributes))
{
  if (PT_isProductionDefault(arg)) {
    return PT_makeProductionDefault(
        acceptLhs ? acceptLhs(PT_getProductionLhs(arg)) : PT_getProductionLhs(arg),
        acceptRhs ? acceptRhs(PT_getProductionRhs(arg)) : PT_getProductionRhs(arg),
        acceptAttributes ? acceptAttributes(PT_getProductionAttributes(arg)) : PT_getProductionAttributes(arg));
  }
  if (PT_isProductionList(arg)) {
    return PT_makeProductionList(
        acceptRhs ? acceptRhs(PT_getProductionRhs(arg)) : PT_getProductionRhs(arg));
  }
  ATabort("not a Production: %t\n", arg);
  return (PT_Production)NULL;
}

/*}}}  */
/*{{{  PT_Attributes PT_visitAttributes(PT_Attributes arg, PT_Attrs (*acceptAttrs)(PT_Attrs)) */

PT_Attributes PT_visitAttributes(PT_Attributes arg, PT_Attrs (*acceptAttrs)(PT_Attrs))
{
  if (PT_isAttributesNoAttrs(arg)) {
    return PT_makeAttributesNoAttrs();
  }
  if (PT_isAttributesAttrs(arg)) {
    return PT_makeAttributesAttrs(
        acceptAttrs ? acceptAttrs(PT_getAttributesAttrs(arg)) : PT_getAttributesAttrs(arg));
  }
  ATabort("not a Attributes: %t\n", arg);
  return (PT_Attributes)NULL;
}

/*}}}  */
/*{{{  PT_Attrs PT_visitAttrs(PT_Attrs arg, PT_Attr (*acceptHead)(PT_Attr)) */

PT_Attrs PT_visitAttrs(PT_Attrs arg, PT_Attr (*acceptHead)(PT_Attr))
{
  if (PT_isAttrsMany(arg)) {
    return PT_makeAttrsMany(
        acceptHead ? acceptHead(PT_getAttrsHead(arg)) : PT_getAttrsHead(arg),
        PT_visitAttrs(PT_getAttrsTail(arg), acceptHead));
  }
  if (PT_isAttrsSingle(arg)) {
    return PT_makeAttrsSingle(
        acceptHead ? acceptHead(PT_getAttrsHead(arg)) : PT_getAttrsHead(arg));
  }
  ATabort("not a Attrs: %t\n", arg);
  return (PT_Attrs)NULL;
}

/*}}}  */
/*{{{  PT_Attr PT_visitAttr(PT_Attr arg, char * (*acceptString)(char *), char * (*acceptModuleName)(char *), PT_ATerm (*acceptTerm)(PT_ATerm)) */

PT_Attr PT_visitAttr(PT_Attr arg, char * (*acceptString)(char *), char * (*acceptModuleName)(char *), PT_ATerm (*acceptTerm)(PT_ATerm))
{
  if (PT_isAttrCons(arg)) {
    return PT_makeAttrCons(
        acceptString ? acceptString(PT_getAttrString(arg)) : PT_getAttrString(arg));
  }
  if (PT_isAttrId(arg)) {
    return PT_makeAttrId(
        acceptModuleName ? acceptModuleName(PT_getAttrModuleName(arg)) : PT_getAttrModuleName(arg));
  }
  if (PT_isAttrAterm(arg)) {
    return PT_makeAttrAterm(
        acceptTerm ? acceptTerm(PT_getAttrTerm(arg)) : PT_getAttrTerm(arg));
  }
  ATabort("not a Attr: %t\n", arg);
  return (PT_Attr)NULL;
}

/*}}}  */
/*{{{  PT_ATerm PT_visitATerm(PT_ATerm arg) */

PT_ATerm PT_visitATerm(PT_ATerm arg)
{
  if (PT_isATermBracket(arg)) {
    return PT_makeATermBracket();
  }
  if (PT_isATermLeft(arg)) {
    return PT_makeATermLeft();
  }
  if (PT_isATermRight(arg)) {
    return PT_makeATermRight();
  }
  if (PT_isATermAssoc(arg)) {
    return PT_makeATermAssoc();
  }
  if (PT_isATermNonAssoc(arg)) {
    return PT_makeATermNonAssoc();
  }
  if (PT_isATermMemo(arg)) {
    return PT_makeATermMemo();
  }
  if (PT_isATermReject(arg)) {
    return PT_makeATermReject();
  }
  if (PT_isATermPrefer(arg)) {
    return PT_makeATermPrefer();
  }
  if (PT_isATermAvoid(arg)) {
    return PT_makeATermAvoid();
  }
  if (PT_isATermConstructor(arg)) {
    return PT_makeATermConstructor();
  }
  if (PT_isATermTraverse(arg)) {
    return PT_makeATermTraverse();
  }
  ATabort("not a ATerm: %t\n", arg);
  return (PT_ATerm)NULL;
}

/*}}}  */
/*{{{  PT_Args PT_visitArgs(PT_Args arg, PT_Tree (*acceptHead)(PT_Tree)) */

PT_Args PT_visitArgs(PT_Args arg, PT_Tree (*acceptHead)(PT_Tree))
{
  if (PT_isArgsList(arg)) {
    return PT_makeArgsList(
        acceptHead ? acceptHead(PT_getArgsHead(arg)) : PT_getArgsHead(arg),
        PT_visitArgs(PT_getArgsTail(arg), acceptHead));
  }
  if (PT_isArgsEmpty(arg)) {
    return PT_makeArgsEmpty();
  }
  ATabort("not a Args: %t\n", arg);
  return (PT_Args)NULL;
}

/*}}}  */
/*{{{  PT_Symbol PT_visitSymbol(PT_Symbol arg, char * (*acceptString)(char *), PT_Symbols (*acceptSymbols)(PT_Symbols), int (*acceptNumber)(int), PT_CharRanges (*acceptRanges)(PT_CharRanges)) */

PT_Symbol PT_visitSymbol(PT_Symbol arg, char * (*acceptString)(char *), PT_Symbols (*acceptSymbols)(PT_Symbols), int (*acceptNumber)(int), PT_CharRanges (*acceptRanges)(PT_CharRanges))
{
  if (PT_isSymbolLit(arg)) {
    return PT_makeSymbolLit(
        acceptString ? acceptString(PT_getSymbolString(arg)) : PT_getSymbolString(arg));
  }
  if (PT_isSymbolCf(arg)) {
    return PT_makeSymbolCf(
        PT_visitSymbol(PT_getSymbolSymbol(arg), acceptString, acceptSymbols, acceptNumber, acceptRanges));
  }
  if (PT_isSymbolLex(arg)) {
    return PT_makeSymbolLex(
        PT_visitSymbol(PT_getSymbolSymbol(arg), acceptString, acceptSymbols, acceptNumber, acceptRanges));
  }
  if (PT_isSymbolEmpty(arg)) {
    return PT_makeSymbolEmpty();
  }
  if (PT_isSymbolSeq(arg)) {
    return PT_makeSymbolSeq(
        acceptSymbols ? acceptSymbols(PT_getSymbolSymbols(arg)) : PT_getSymbolSymbols(arg));
  }
  if (PT_isSymbolOpt(arg)) {
    return PT_makeSymbolOpt(
        PT_visitSymbol(PT_getSymbolSymbol(arg), acceptString, acceptSymbols, acceptNumber, acceptRanges));
  }
  if (PT_isSymbolAlt(arg)) {
    return PT_makeSymbolAlt(
        PT_visitSymbol(PT_getSymbolLhs(arg), acceptString, acceptSymbols, acceptNumber, acceptRanges),
        PT_visitSymbol(PT_getSymbolRhs(arg), acceptString, acceptSymbols, acceptNumber, acceptRanges));
  }
  if (PT_isSymbolPair(arg)) {
    return PT_makeSymbolPair(
        PT_visitSymbol(PT_getSymbolLhs(arg), acceptString, acceptSymbols, acceptNumber, acceptRanges),
        PT_visitSymbol(PT_getSymbolRhs(arg), acceptString, acceptSymbols, acceptNumber, acceptRanges));
  }
  if (PT_isSymbolSort(arg)) {
    return PT_makeSymbolSort(
        acceptString ? acceptString(PT_getSymbolString(arg)) : PT_getSymbolString(arg));
  }
  if (PT_isSymbolIterPlus(arg)) {
    return PT_makeSymbolIterPlus(
        PT_visitSymbol(PT_getSymbolSymbol(arg), acceptString, acceptSymbols, acceptNumber, acceptRanges));
  }
  if (PT_isSymbolIterStar(arg)) {
    return PT_makeSymbolIterStar(
        PT_visitSymbol(PT_getSymbolSymbol(arg), acceptString, acceptSymbols, acceptNumber, acceptRanges));
  }
  if (PT_isSymbolIterPlusSep(arg)) {
    return PT_makeSymbolIterPlusSep(
        PT_visitSymbol(PT_getSymbolSymbol(arg), acceptString, acceptSymbols, acceptNumber, acceptRanges),
        PT_visitSymbol(PT_getSymbolSeparator(arg), acceptString, acceptSymbols, acceptNumber, acceptRanges));
  }
  if (PT_isSymbolIterStarSep(arg)) {
    return PT_makeSymbolIterStarSep(
        PT_visitSymbol(PT_getSymbolSymbol(arg), acceptString, acceptSymbols, acceptNumber, acceptRanges),
        PT_visitSymbol(PT_getSymbolSeparator(arg), acceptString, acceptSymbols, acceptNumber, acceptRanges));
  }
  if (PT_isSymbolIterN(arg)) {
    return PT_makeSymbolIterN(
        PT_visitSymbol(PT_getSymbolSymbol(arg), acceptString, acceptSymbols, acceptNumber, acceptRanges),
        acceptNumber ? acceptNumber(PT_getSymbolNumber(arg)) : PT_getSymbolNumber(arg));
  }
  if (PT_isSymbolIterSepN(arg)) {
    return PT_makeSymbolIterSepN(
        PT_visitSymbol(PT_getSymbolSymbol(arg), acceptString, acceptSymbols, acceptNumber, acceptRanges),
        PT_visitSymbol(PT_getSymbolSeparator(arg), acceptString, acceptSymbols, acceptNumber, acceptRanges),
        acceptNumber ? acceptNumber(PT_getSymbolNumber(arg)) : PT_getSymbolNumber(arg));
  }
  if (PT_isSymbolPerm(arg)) {
    return PT_makeSymbolPerm(
        acceptSymbols ? acceptSymbols(PT_getSymbolSymbols(arg)) : PT_getSymbolSymbols(arg));
  }
  if (PT_isSymbolSet(arg)) {
    return PT_makeSymbolSet(
        PT_visitSymbol(PT_getSymbolSymbol(arg), acceptString, acceptSymbols, acceptNumber, acceptRanges));
  }
  if (PT_isSymbolFunc(arg)) {
    return PT_makeSymbolFunc(
        acceptSymbols ? acceptSymbols(PT_getSymbolSymbols(arg)) : PT_getSymbolSymbols(arg),
        PT_visitSymbol(PT_getSymbolSymbol(arg), acceptString, acceptSymbols, acceptNumber, acceptRanges));
  }
  if (PT_isSymbolVarSym(arg)) {
    return PT_makeSymbolVarSym(
        PT_visitSymbol(PT_getSymbolSymbol(arg), acceptString, acceptSymbols, acceptNumber, acceptRanges));
  }
  if (PT_isSymbolLayout(arg)) {
    return PT_makeSymbolLayout();
  }
  if (PT_isSymbolCharClass(arg)) {
    return PT_makeSymbolCharClass(
        acceptRanges ? acceptRanges(PT_getSymbolRanges(arg)) : PT_getSymbolRanges(arg));
  }
  ATabort("not a Symbol: %t\n", arg);
  return (PT_Symbol)NULL;
}

/*}}}  */
/*{{{  PT_Symbols PT_visitSymbols(PT_Symbols arg, PT_Symbol (*acceptHead)(PT_Symbol)) */

PT_Symbols PT_visitSymbols(PT_Symbols arg, PT_Symbol (*acceptHead)(PT_Symbol))
{
  if (PT_isSymbolsList(arg)) {
    return PT_makeSymbolsList(
        acceptHead ? acceptHead(PT_getSymbolsHead(arg)) : PT_getSymbolsHead(arg),
        PT_visitSymbols(PT_getSymbolsTail(arg), acceptHead));
  }
  if (PT_isSymbolsEmpty(arg)) {
    return PT_makeSymbolsEmpty();
  }
  ATabort("not a Symbols: %t\n", arg);
  return (PT_Symbols)NULL;
}

/*}}}  */
/*{{{  PT_CharRange PT_visitCharRange(PT_CharRange arg, int (*acceptInteger)(int), int (*acceptStart)(int), int (*acceptEnd)(int)) */

PT_CharRange PT_visitCharRange(PT_CharRange arg, int (*acceptInteger)(int), int (*acceptStart)(int), int (*acceptEnd)(int))
{
  if (PT_isCharRangeCharacter(arg)) {
    return PT_makeCharRangeCharacter(
        acceptInteger ? acceptInteger(PT_getCharRangeInteger(arg)) : PT_getCharRangeInteger(arg));
  }
  if (PT_isCharRangeRange(arg)) {
    return PT_makeCharRangeRange(
        acceptStart ? acceptStart(PT_getCharRangeStart(arg)) : PT_getCharRangeStart(arg),
        acceptEnd ? acceptEnd(PT_getCharRangeEnd(arg)) : PT_getCharRangeEnd(arg));
  }
  ATabort("not a CharRange: %t\n", arg);
  return (PT_CharRange)NULL;
}

/*}}}  */
/*{{{  PT_CharRanges PT_visitCharRanges(PT_CharRanges arg, PT_CharRange (*acceptHead)(PT_CharRange)) */

PT_CharRanges PT_visitCharRanges(PT_CharRanges arg, PT_CharRange (*acceptHead)(PT_CharRange))
{
  if (PT_isCharRangesList(arg)) {
    return PT_makeCharRangesList(
        acceptHead ? acceptHead(PT_getCharRangesHead(arg)) : PT_getCharRangesHead(arg),
        PT_visitCharRanges(PT_getCharRangesTail(arg), acceptHead));
  }
  if (PT_isCharRangesEmpty(arg)) {
    return PT_makeCharRangesEmpty();
  }
  ATabort("not a CharRanges: %t\n", arg);
  return (PT_CharRanges)NULL;
}

/*}}}  */

/*}}}  */
