#include "chars.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include <MEPT-utils.h>
#include <SDFME-utils.h>
#include <ASFME-utils.h>

static PT_Symbol     flattenSdfSymbol(SDF_Symbol sdfSymbol);
static PT_Symbols    flattenSdfSymbols(SDF_Symbols sdfSymbols);
static PT_Attributes flattenSdfAttributes(SDF_Attributes sdfAttributes);
static PT_Attr       flattenSdfAttribute(SDF_Attribute sdfAttribute);
static PT_CharRanges flattenSdfCharClass(SDF_CharClass sdfCharClass);
static PT_CharRanges flattenSdfCharRanges(SDF_CharRanges sdfCharRanges);
static PT_CharRange  flattenSdfCharRange(SDF_CharRange sdfCharRange);
static int           flattenSdfCharacter(SDF_Character sdfCharacter);

PT_Production
makeLexicalConstructorProd(SDF_Symbol symbol)
{
  char *sortName;
  char *name;
  int i;
  ASF_Symbol sortSymbol;
  ASF_Production lexConsProd;

  sortName = PT_yieldTree((PT_Tree) SDF_getSymbolSort(symbol));

  name = strdup(sortName);
  if (!name) {
    ATerror("makeLexicalConstructorProd: not enough memory\n");
  }
  for (i=0; name[i]; i++) {
    name[i] = tolower(name[i]);
  }

  sortSymbol = (ASF_Symbol)PT_makeSymbolSort(sortName);

  lexConsProd = ASF_makeProductionLexicalConstructor(name,
                                                     sortSymbol);

  free(name);
  return PT_makeProductionFromTerm(ASF_makeTermFromProduction(lexConsProd));
}

PT_Symbols flattenSdfProductionProdFun(SDF_Literal sdfPrefixFunc,
				       SDF_SymbolArguments sdfPrefixArgs)
{
  PT_Symbols ptPrefixArgs;
  PT_Symbol  ptPrefixArg;
  PT_Symbol ptPrefixFunc = flattenSdfSymbol(SDF_makeSymbolLit(sdfPrefixFunc));
  PT_Symbol layout = PT_makeSymbolLayout();
  PT_Symbol comma  = PT_makeSymbolLit(",");
  PT_Symbol open   = PT_makeSymbolLit("(");
  PT_Symbol close  = PT_makeSymbolLit(")");

  ptPrefixArgs = PT_makeSymbolsList(ptPrefixFunc, PT_makeSymbolsEmpty());
  ptPrefixArgs = PT_appendSymbols(ptPrefixArgs, layout);
  ptPrefixArgs = PT_appendSymbols(ptPrefixArgs, open);
  ptPrefixArgs = PT_appendSymbols(ptPrefixArgs, layout);

  while (SDF_hasSymbolArgumentsHead(sdfPrefixArgs)) {
    ptPrefixArg  = flattenSdfSymbol(SDF_getSymbolArgumentsHead(sdfPrefixArgs));
    ptPrefixArgs = PT_appendSymbols(ptPrefixArgs, ptPrefixArg);

    if (SDF_hasSymbolArgumentsTail(sdfPrefixArgs)) {
      ptPrefixArgs = PT_appendSymbols(ptPrefixArgs, layout);
      ptPrefixArgs = PT_appendSymbols(ptPrefixArgs, comma);
      ptPrefixArgs = PT_appendSymbols(ptPrefixArgs, layout);
    }
    else {
      break;
    }

    sdfPrefixArgs = SDF_getSymbolArgumentsTail(sdfPrefixArgs);
  }
  ptPrefixArgs = PT_appendSymbols(ptPrefixArgs, layout);
  ptPrefixArgs = PT_appendSymbols(ptPrefixArgs, close);

  return ptPrefixArgs;
}

PT_Production flattenSdfProduction(SDF_Production sdfProduction,                                                   SDF_ModuleName sdfModuleName)
{
  SDF_Symbol  sdfResult;
  SDF_Attributes sdfAttributes;
  PT_Symbols ptSymbols;
  PT_Symbol  ptResult;
  PT_Attributes ptAttributes;
  
  sdfResult  = SDF_getProductionResult(sdfProduction);
  sdfAttributes = SDF_getProductionAttributes(sdfProduction);
  ptResult  = flattenSdfSymbol(sdfResult);
  ptAttributes = flattenSdfAttributes(sdfAttributes);

  if (SDF_isProductionProd(sdfProduction)) {
    SDF_Symbols sdfSymbols = SDF_getProductionSymbols(sdfProduction);
    ptSymbols = flattenSdfSymbols(sdfSymbols);
  }
  else if (SDF_isProductionProdFun(sdfProduction)) {
     SDF_Literal sdfLiteral = SDF_getProductionFunctionSymbol(sdfProduction);
     SDF_SymbolArguments sdfArgs = SDF_getProductionArguments(sdfProduction);

     ptSymbols = flattenSdfProductionProdFun(sdfLiteral, sdfArgs);
  } else {
    ATerror("flattenSdfProduction: unable to flatten %s\n", 
	    PT_yieldTree((PT_Tree) sdfProduction));
    return NULL;
  }

  return PT_makeProductionDefault(ptSymbols, ptResult, ptAttributes);
}

static PT_Symbols flattenSdfSymbols(SDF_Symbols sdfSymbols)
{
  SDF_SymbolList sdfSymbolList = SDF_getSymbolsList(sdfSymbols);
  PT_Symbols ptSymbols = PT_makeSymbolsEmpty();
  PT_Symbol layout = PT_makeSymbolLayout();

  while (SDF_hasSymbolListHead(sdfSymbolList)) {
    SDF_Symbol sdfSymbol = SDF_getSymbolListHead(sdfSymbolList);
    PT_Symbol ptSymbol = flattenSdfSymbol(sdfSymbol);

    if (!PT_isSymbolsEmpty(ptSymbols)) {
      ptSymbols = PT_appendSymbols(ptSymbols, layout);      
    }

    ptSymbols = PT_appendSymbols(ptSymbols, ptSymbol);

    if (SDF_isSymbolListSingle(sdfSymbolList)) {
      break;
    }
    sdfSymbolList = SDF_getSymbolListTail(sdfSymbolList);
  }

  return ptSymbols;
}

static PT_Symbol     flattenSdfSymbol(SDF_Symbol sdfSymbol)
{
  PT_Symbol result = NULL;

  if (SDF_isSymbolSort(sdfSymbol)) {
    char *str = PT_yieldTree((PT_Tree) SDF_getSymbolSort(sdfSymbol));
    result = PT_makeSymbolSort(str); 
  }
  else if (SDF_isSymbolLit(sdfSymbol)) {
    SDF_Literal sdfLit = SDF_getSymbolLiteral(sdfSymbol);
    char *str = PT_yieldTree((PT_Tree) sdfLit);
    if (str[0] == '\"') { /* quoted */
       char* uqstr = rmquotes(str);
       result = PT_makeSymbolLit(uqstr);
       free(uqstr);
    }
    else { /* not quoted */
       result = PT_makeSymbolLit(str);
    }
  }
  else if (SDF_isSymbolIter(sdfSymbol)) {
    SDF_Symbol sdfIterSymbol = SDF_getSymbolSymbol(sdfSymbol);
    PT_Symbol ptIterSymbol = flattenSdfSymbol(sdfIterSymbol);
    result = PT_makeSymbolIterPlus(ptIterSymbol);
  }
  else if (SDF_isSymbolIterStar(sdfSymbol)) {
    SDF_Symbol sdfIterSymbol = SDF_getSymbolSymbol(sdfSymbol);
    PT_Symbol ptIterSymbol = flattenSdfSymbol(sdfIterSymbol);
    result = PT_makeSymbolIterStar(ptIterSymbol);
  }
  else if (SDF_isSymbolIterSep(sdfSymbol)) {
    SDF_Symbol sdfIterSymbol = SDF_getSymbolSymbol(sdfSymbol);
    SDF_Symbol sdfIterSep = SDF_getSymbolSep(sdfSymbol);
    PT_Symbol ptIterSymbol = flattenSdfSymbol(sdfIterSymbol);
    PT_Symbol ptSepSymbol = flattenSdfSymbol(sdfIterSep);
    result = PT_makeSymbolIterPlusSep(ptIterSymbol, ptSepSymbol);
  }
  else if (SDF_isSymbolIterStarSep(sdfSymbol)) {
    SDF_Symbol sdfIterSymbol = SDF_getSymbolSymbol(sdfSymbol);
    SDF_Symbol sdfIterSep = SDF_getSymbolSep(sdfSymbol);
    PT_Symbol ptIterSymbol = flattenSdfSymbol(sdfIterSymbol);
    PT_Symbol ptSepSymbol = flattenSdfSymbol(sdfIterSep);
    result = PT_makeSymbolIterStarSep(ptIterSymbol, ptSepSymbol);
  } 
  else if (SDF_isSymbolIterN(sdfSymbol)) {
    SDF_Symbol sdfIterSymbol = SDF_getSymbolSymbol(sdfSymbol);
    SDF_NatCon sdfN = SDF_getSymbolN(sdfSymbol);
    PT_Symbol ptIterSymbol = flattenSdfSymbol(sdfIterSymbol);
    int ptN = atoi(PT_yieldTree((PT_Tree) sdfN));
    result = PT_makeSymbolIterN(ptIterSymbol,ptN);
  }
  else if (SDF_isSymbolIterSepN(sdfSymbol)) {
    SDF_Symbol sdfIterSymbol = SDF_getSymbolSymbol(sdfSymbol);
    SDF_Symbol sdfIterSep = SDF_getSymbolSep(sdfSymbol);
    SDF_NatCon sdfN = SDF_getSymbolN(sdfSymbol);
    PT_Symbol ptIterSymbol = flattenSdfSymbol(sdfIterSymbol);
    PT_Symbol ptSepSymbol = flattenSdfSymbol(sdfIterSep);
    int ptN = atoi(PT_yieldTree((PT_Tree) sdfN));
    result = PT_makeSymbolIterSepN(ptIterSymbol,ptSepSymbol,ptN);
  }
  else if (SDF_isSymbolCf(sdfSymbol)) {
    SDF_Symbol sdfSym = SDF_getSymbolSymbol(sdfSymbol);
    PT_Symbol ptSym = flattenSdfSymbol(sdfSym);
    result = PT_makeSymbolCf(ptSym);
  }
  else if (SDF_isSymbolLex(sdfSymbol)) {
    SDF_Symbol sdfSym = SDF_getSymbolSymbol(sdfSymbol);
    PT_Symbol ptSym = flattenSdfSymbol(sdfSym);
    result = PT_makeSymbolLex(ptSym);
  }
  else if (SDF_isSymbolVarsym(sdfSymbol)) {
    SDF_Symbol sdfSym = SDF_getSymbolSymbol(sdfSymbol);
    PT_Symbol ptSym = flattenSdfSymbol(sdfSym);
    result = PT_makeSymbolVarSym(ptSym);
  }
  else if (SDF_isSymbolLayout(sdfSymbol)) {
    result = PT_makeSymbolLayout();
  }
  else if (SDF_isSymbolEmpty(sdfSymbol)) {
    result = PT_makeSymbolEmpty();
  }
  else if (SDF_isSymbolSeq(sdfSymbol)) {
    SDF_Symbol sdfHead = SDF_getSymbolHead(sdfSymbol);
    /* tricky casting of SymbolTail to SymbolList */
    SDF_SymbolList sdfTail = (SDF_SymbolList) SDF_getSymbolTail(sdfSymbol);
    SDF_Symbols sdfSymbols = SDF_makeSymbolsDefault(sdfTail);
    PT_Symbol ptHead = flattenSdfSymbol(sdfHead);
    PT_Symbols ptTail = flattenSdfSymbols(sdfSymbols);
    result = PT_makeSymbolSeq(PT_makeSymbolsList(ptHead, ptTail));
  }
  else if (SDF_isSymbolOpt(sdfSymbol)) {
    SDF_Symbol sdfSym = SDF_getSymbolSymbol(sdfSymbol);
    PT_Symbol ptSym = flattenSdfSymbol(sdfSym);
    result = PT_makeSymbolOpt(ptSym);
  }
  else if (SDF_isSymbolSet(sdfSymbol)) {
    SDF_Symbol sdfSym = SDF_getSymbolSymbol(sdfSymbol);
    PT_Symbol ptSym = flattenSdfSymbol(sdfSym);
    result = PT_makeSymbolSet(ptSym);
  }
  else if (SDF_isSymbolPair(sdfSymbol)) {
    SDF_Symbol sdfLeft = SDF_getSymbolLeft(sdfSymbol);
    SDF_Symbol sdfRight = SDF_getSymbolRight(sdfSymbol);
    PT_Symbol ptLeft = flattenSdfSymbol(sdfLeft);
    PT_Symbol ptRight = flattenSdfSymbol(sdfRight);
    result = PT_makeSymbolPair(ptLeft, ptRight);
  }
  else if (SDF_isSymbolFunc(sdfSymbol)) {
    SDF_Symbols sdfArguments = SDF_getSymbolArguments(sdfSymbol);
    SDF_Symbol sdfResult = SDF_getSymbolResults(sdfSymbol);
    PT_Symbols ptArguments = flattenSdfSymbols(sdfArguments);
    PT_Symbol ptResult = flattenSdfSymbol(sdfResult);
    result = PT_makeSymbolFunc(ptArguments,ptResult);
  }
  else if (SDF_isSymbolAlt(sdfSymbol)) {
    SDF_Symbol sdfLeft = SDF_getSymbolLeft(sdfSymbol);
    SDF_Symbol sdfRight = SDF_getSymbolRight(sdfSymbol);
    PT_Symbol ptLeft = flattenSdfSymbol(sdfLeft);
    PT_Symbol ptRight = flattenSdfSymbol(sdfRight);
    result = PT_makeSymbolPair(ptLeft, ptRight);
  }
  else if (SDF_isSymbolPerm(sdfSymbol)) {
    SDF_Symbols sdfSyms = SDF_getSymbolSymbols(sdfSymbol);
    PT_Symbols ptSyms = flattenSdfSymbols(sdfSyms);
    result = PT_makeSymbolPerm(ptSyms);
  }
  else if (SDF_isSymbolCharClass(sdfSymbol)) {
    SDF_CharClass sdfCC = SDF_getSymbolCharClass(sdfSymbol);
    PT_CharRanges ptCR = flattenSdfCharClass(sdfCC);
    result = PT_makeSymbolCharClass(ptCR);
  }
  else {
    ATerror("flattenSdfSymbol: unable to flatten symbol: %s\n", 
	    PT_yieldTree((PT_Tree) sdfSymbol));
    result = NULL;
  }
	    

  return result;
}

static PT_Attributes flattenSdfAttributes(SDF_Attributes sdfAttributes) 
{
  PT_Attributes ptAttributes;

  if (SDF_isAttributesNoAttrs(sdfAttributes)) {
    ptAttributes = PT_makeAttributesNoAttrs();
  }
  else {
    SDF_AttributeList sdfAttrList = SDF_getAttributesList(sdfAttributes);
    PT_Attrs ptAttrList = NULL;
 
    if (SDF_isAttributeListEmpty(sdfAttrList)) {
      ptAttributes = PT_makeAttributesNoAttrs();
    }
    else {
      while (SDF_hasAttributeListHead(sdfAttrList)) {
        SDF_Attribute sdfAttr = SDF_getAttributeListHead(sdfAttrList);
        PT_Attr ptAttr = flattenSdfAttribute(sdfAttr);
        
        if (ptAttrList == NULL) {
          ptAttrList = PT_makeAttrsSingle(ptAttr);
        } 
        else {
          ptAttrList = PT_makeAttrsMany(ptAttr, ptAttrList);
        }
  
        if (SDF_isAttributeListSingle(sdfAttrList)) {
          break;
        }
        sdfAttrList = SDF_getAttributeListTail(sdfAttrList);
      }
    }

    ptAttributes = PT_makeAttributesAttrs(
                     PT_reverseAttrs(ptAttrList));
  }

  return ptAttributes;
}
                     
static PT_Attr flattenSdfAttribute(SDF_Attribute sdfAttribute)
{
  PT_Attr ptAttr = NULL;

  if (SDF_isAttributeBracket(sdfAttribute)) {
    ptAttr = PT_makeAttrBracket();         
  }
  else if (SDF_isAttributeMemo(sdfAttribute)) {
    ptAttr = PT_makeAttrMemo();         
  }
  else if (SDF_isAttributeReject(sdfAttribute)) {
    ptAttr = PT_makeAttrReject();         
  }
  else if (SDF_isAttributePrefer(sdfAttribute)) {
    ptAttr = PT_makeAttrPrefer();         
  }
  else if (SDF_isAttributeAvoid(sdfAttribute)) {
    ptAttr = PT_makeAttrAvoid();         
  }
  else if (SDF_isAttributeConstructor(sdfAttribute)) {
    ptAttr = PT_makeAttrConstructor();         
  }
  else if (SDF_isAttributeId(sdfAttribute)) {
    SDF_ModuleName sdfModuleName = SDF_getAttributeModuleName(sdfAttribute);
    SDF_ModuleId  sdfModuleId = SDF_getModuleNameModuleId(sdfModuleName);
    char *str = PT_yieldTree((PT_Tree) sdfModuleId);
    ptAttr = PT_makeAttrId(str);         
  }
  else if (SDF_isAttributeCons(sdfAttribute)) {
    SDF_ATerm sdfATerm = SDF_getAttributeTerm(sdfAttribute);
    if (SDF_isATermFun(sdfATerm)) {
      SDF_AFun fun = SDF_getATermFun(sdfATerm);
      char *str = PT_yieldTree((PT_Tree) SDF_getAFunLiteral(fun));
      ptAttr = PT_makeAttrCons(str);         
    }
    else {
      ATerror("flattenSdfAttribute: unable to flatten %s\n", 
	      PT_yieldTree((PT_Tree) sdfAttribute));
      ptAttr = NULL;
    }
  }
  else if (SDF_isAttributeAtr(sdfAttribute)) {
    SDF_Associativity sdfAssoc = SDF_getAttributeAssociativity(sdfAttribute);
    
    if (SDF_isAssociativityLeft(sdfAssoc)) {
      ptAttr = PT_makeAttrLeft();
    }
    else if (SDF_isAssociativityRight(sdfAssoc)) {
      ptAttr = PT_makeAttrRight();
    }
    else if (SDF_isAssociativityNonAssoc(sdfAssoc)) {
      ptAttr = PT_makeAttrNonAssoc();
    }
    else if (SDF_isAssociativityAssoc(sdfAssoc)) { 
      ptAttr = PT_makeAttrAssoc();
    }
  } 
  else {
     ATerror("flattenSdfAttribute: unable to flatten %s\n", 
	     PT_yieldTree((PT_Tree) sdfAttribute));
     ptAttr = NULL;
  }

  return ptAttr;
}

static int flattenSdfCharacter(SDF_Character sdfCharacter)
{
  int result;

  if (SDF_isCharacterNumeric(sdfCharacter)) {
    SDF_NumChar sdfNumChar = SDF_getCharacterNumChar(sdfCharacter);
    char *numchar = PT_yieldTree((PT_Tree) sdfNumChar);
    result = atoi(numchar+1); /* remove leading backslash */ 
  }
  else if (SDF_isCharacterShort(sdfCharacter)) {
    SDF_ShortChar sdfShortChar = SDF_getCharacterShortChar(sdfCharacter);
    char *numchar = PT_yieldTree((PT_Tree) sdfShortChar);
    if (numchar[0] != '\\') {
      result = (int) numchar[0];
    } 
    else {
      result = (int) numchar[1]; /* skip backslash */
    }
  }
  else {
    ATerror("flattenSdfCharacter: unable to flatten %s\n",
	    PT_yieldTree((PT_Tree) sdfCharacter));
    result = -1;
  }

  return result;
}

static PT_CharRange flattenSdfCharRange(SDF_CharRange sdfCharRange)
{
  PT_CharRange result;

  if (SDF_isCharRangeDefault(sdfCharRange)) {
    SDF_Character sdfChar = SDF_getCharRangeCharacter(sdfCharRange);
    int ptChar = flattenSdfCharacter(sdfChar);
    result = PT_makeCharRangeCharacter(ptChar);
  }
  else if (SDF_isCharRangeRange(sdfCharRange)) {
    SDF_Character sdfStart = SDF_getCharRangeStart(sdfCharRange);
    SDF_Character sdfEnd = SDF_getCharRangeEnd(sdfCharRange);
    int ptStart = flattenSdfCharacter(sdfStart);
    int ptEnd = flattenSdfCharacter(sdfEnd);
    result = PT_makeCharRangeRange(ptStart,ptEnd);
  }
  else {
    ATerror("flattenSdfCharRange: unable to flatten %s\n",
	    PT_yieldTree((PT_Tree) sdfCharRange));
    result = NULL;
  } 
 
  return result;
}

static PT_CharRanges flattenSdfCharRanges(SDF_CharRanges sdfCharRanges)
{
  PT_CharRanges result = PT_makeCharRangesEmpty();

  if (SDF_isCharRangesDefault(sdfCharRanges)) {
    SDF_CharRange sdfCharRange = SDF_getCharRangesCharRange(sdfCharRanges);
    PT_CharRange ptCharRange = flattenSdfCharRange(sdfCharRange);
    result = PT_makeCharRangesList(ptCharRange, result);
  }
  else if (SDF_isCharRangesConc(sdfCharRanges)) {
    SDF_CharRanges sdfLeft = SDF_getCharRangesLeft(sdfCharRanges);
    SDF_CharRanges sdfRight = SDF_getCharRangesRight(sdfCharRanges);
    PT_CharRanges ptLeft = flattenSdfCharRanges(sdfLeft);
    PT_CharRanges ptRight = flattenSdfCharRanges(sdfRight);
    return PT_concatCharRanges(ptLeft, ptRight);
  }
  else {
    ATerror("flattenSdfCharRanges: unable to flatten %s\n",
	    PT_yieldTree((PT_Tree) sdfCharRanges));
    result = NULL;
  }

  return result;
}

static PT_CharRanges flattenSdfCharClass(SDF_CharClass sdfCharClass)
{
  PT_CharRanges result;

  if (SDF_isCharClassSimpleCharclass(sdfCharClass)) {
    SDF_OptCharRanges sdfOCR = SDF_getCharClassOptCharRanges(sdfCharClass);

    if (SDF_isOptCharRangesAbsent(sdfOCR)) {
      result = PT_makeCharRangesEmpty();
    }
    else {
      SDF_CharRanges sdfCharRanges = SDF_getOptCharRangesCharRanges(sdfOCR);
      result = flattenSdfCharRanges(sdfCharRanges);
    } 
  }
  else {
    ATerror("flattenSdfCharClass: unable to flatten characterclass: %s\n",
	    PT_yieldTree((PT_Tree) sdfCharClass));
    result = NULL;
  }
  
  return result;
}
