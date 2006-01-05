#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include <MEPT-utils.h>
#include "SDFME-utils.h"
#include "SDF2PT.h"

static const char*   SDFStrConToString(SDF_StrCon str);
static PT_Symbols    SDFSymbolsToPtSymbols(SDF_Symbols sdfSymbols);
static PT_Attributes SDFAttributesToPtAttributes(SDF_Attributes sdfAttributes);
static PT_Attr       SDFAttributeToPtAttr(SDF_Attribute sdfAttribute);
static PT_CharRanges SDFCharClassToPtCharRanges(SDF_CharClass sdfCharClass);
static PT_CharRanges SDFCharRangesToPtCharRanges(SDF_CharRanges sdfCharRanges);
static PT_CharRange  SDFCharRangeToPtCharRange(SDF_CharRange sdfCharRange);
static int           SDFCharacterToInt(SDF_Character sdfCharacter);

static const char *SDFStrCharsToString(SDF_LexStrCharChars list)
{
  int len = SDF_getLexStrCharCharsLength(list);
  int i;
  static char result[BUFSIZ];

  if (len >= BUFSIZ - 2) {
    ATwarning("SDFStrConToString: insufficient memory to allocate string\n");
    return NULL;
  }

  for (i = 0;
       !SDF_isLexStrCharCharsEmpty(list);
       list = SDF_getLexStrCharCharsTail(list),
       i++) {

    SDF_LexStrChar ch = SDF_getLexStrCharCharsHead(list);


    if (SDF_isLexStrCharNewline(ch)) {
      result[i] = '\n';
    }
    else if (SDF_isLexStrCharTab(ch)) {
      result[i] = '\t';
    }
    else if (SDF_isLexStrCharQuote(ch)) {
      result[i] = '\"';
    }
    else if (SDF_isLexStrCharBackslash(ch)) {
      result[i] = '\\';
    }
    else if (SDF_isLexStrCharNormal(ch)) {
      result[i] = SDF_getLexStrCharCh(ch);
    }
    else if (SDF_isLexStrCharDecimal(ch)) {
      int a = SDF_getLexStrCharA(ch);
      int b = SDF_getLexStrCharB(ch);
      int c = SDF_getLexStrCharC(ch);
      result[i] = (char) 100*a + 10*b + c;
    }
  }

  result[len] = '\0'; 
  return result;
}

static const char *SDFStrConToString(SDF_StrCon pStr) {
  SDF_LexStrCon strcon = SDF_getStrConStrCon(pStr);
  SDF_LexStrCharChars list = SDF_getLexStrConChars(strcon);
  return SDFStrCharsToString(list);
}

static const char *SDFSingleQuotedStrCharsToString(SDF_LexSingleQuotedStrCharChars list)
{
  int len = SDF_getLexSingleQuotedStrCharCharsLength(list);
  int i;
  static char result[BUFSIZ];

  if (len >= BUFSIZ - 2) {
    ATwarning("SDFStrConToString: insufficient memory to allocate string\n");
    return NULL;
  }

  for (i = 0;
       !SDF_isLexSingleQuotedStrCharCharsEmpty(list);
       list = SDF_getLexSingleQuotedStrCharCharsTail(list),
       i++) {

    SDF_LexSingleQuotedStrChar ch = SDF_getLexSingleQuotedStrCharCharsHead(list);


    if (SDF_isLexSingleQuotedStrCharNewline(ch)) {
      result[i] = '\n';
    }
    else if (SDF_isLexSingleQuotedStrCharTab(ch)) {
      result[i] = '\t';
    }
    else if (SDF_isLexSingleQuotedStrCharQuote(ch)) {
      result[i] = '\'';
    }
    else if (SDF_isLexSingleQuotedStrCharBackslash(ch)) {
      result[i] = '\\';
    }
    else if (SDF_isLexSingleQuotedStrCharNormal(ch)) {
      result[i] = SDF_getLexSingleQuotedStrCharCh(ch);
    }
    else if (SDF_isLexSingleQuotedStrCharDecimal(ch)) {
      int a = SDF_getLexSingleQuotedStrCharA(ch);
      int b = SDF_getLexSingleQuotedStrCharB(ch);
      int c = SDF_getLexSingleQuotedStrCharC(ch);
      result[i] = (char) 100*a + 10*b + c;
    }
  }

  result[len] = '\0'; 
  return result;
}

static const char *SDFCiStrConToString(SDF_SingleQuotedStrCon pStr) {
  SDF_LexSingleQuotedStrCon strcon = 
    SDF_getSingleQuotedStrConSingleQuotedStrCon(pStr);
  SDF_LexSingleQuotedStrCharChars list = SDF_getLexSingleQuotedStrConChars(strcon);
  return SDFSingleQuotedStrCharsToString(list);
}


PT_Production SDFProductionToPtProduction(SDF_Production sdfProduction)
{
  SDF_Symbol  sdfResult;
  SDF_Attributes sdfAttributes;
  PT_Symbols ptSymbols;
  PT_Symbol  ptResult;
  PT_Attributes ptAttributes;

  sdfResult  = SDF_getProductionResult(sdfProduction);
  sdfAttributes = SDF_getProductionAttributes(sdfProduction);
  ptResult  = SDFSymbolToPtSymbol(sdfResult);
  ptAttributes = SDFAttributesToPtAttributes(sdfAttributes);

  if (SDF_isProductionProd(sdfProduction)) {
    SDF_Symbols sdfSymbols = SDF_getProductionSymbols(sdfProduction);
    ptSymbols = SDFSymbolsToPtSymbols(sdfSymbols);
  }
  else {
    ATwarning("SDFProductionToPtProduction: unable to convert %s\n", 
	      PT_yieldTreeToString((PT_Tree) sdfProduction, ATfalse));
    return NULL;
  }

  return PT_makeProductionDefault(ptSymbols, ptResult, ptAttributes);
}

static PT_Symbols SDFSymbolsToPtSymbols(SDF_Symbols sdfSymbols)
{
  SDF_SymbolList sdfSymbolList = SDF_getSymbolsList(sdfSymbols);
  PT_Symbols ptSymbols = PT_makeSymbolsEmpty();

  while (SDF_hasSymbolListHead(sdfSymbolList)) {
    SDF_Symbol sdfSymbol = SDF_getSymbolListHead(sdfSymbolList);
    PT_Symbol ptSymbol = SDFSymbolToPtSymbol(sdfSymbol);

    ptSymbols = PT_appendSymbols(ptSymbols, ptSymbol);


    if (SDF_isSymbolListSingle(sdfSymbolList)) {
      break;
    }
    sdfSymbolList = SDF_getSymbolListTail(sdfSymbolList);
  }

  return ptSymbols;
}

static PT_Symbols SDFSymbolParametersToPtSymbols(SDF_SymbolParameters sdfSymbols)
{
  PT_Symbols ptSymbols = PT_makeSymbolsEmpty();

  while (SDF_hasSymbolParametersHead(sdfSymbols)) {
    SDF_Symbol sdfSymbol = SDF_getSymbolParametersHead(sdfSymbols);
    PT_Symbol ptSymbol = SDFSymbolToPtSymbol(sdfSymbol);

    ptSymbols = PT_appendSymbols(ptSymbols, ptSymbol);


    if (SDF_isSymbolParametersSingle(sdfSymbols)) {
      break;
    }
    sdfSymbols = SDF_getSymbolParametersTail(sdfSymbols);
  }

  return ptSymbols;
}

static PT_Symbols SDFSymbolRestToPtSymbols(SDF_SymbolRest sdfSymbols)
{
  PT_Symbols ptSymbols = PT_makeSymbolsEmpty();

  while (SDF_hasSymbolRestHead(sdfSymbols)) {
    SDF_Symbol sdfSymbol = SDF_getSymbolRestHead(sdfSymbols);
    PT_Symbol ptSymbol = SDFSymbolToPtSymbol(sdfSymbol);

    ptSymbols = PT_appendSymbols(ptSymbols, ptSymbol);


    if (SDF_isSymbolRestSingle(sdfSymbols)) {
      break;
    }
    sdfSymbols = SDF_getSymbolRestTail(sdfSymbols);
  }

  return ptSymbols;
}

PT_Symbol     SDFSymbolToPtSymbol(SDF_Symbol sdfSymbol)
{
  PT_Symbol result = NULL;

  if (SDF_isSymbolStart(sdfSymbol)) {
    result = PT_makeSymbolSort("<START>"); 
  }
  else if (SDF_isSymbolFileStart(sdfSymbol)) {
    result = PT_makeSymbolSort("<Start>"); 
  }
  else if (SDF_isSymbolSort(sdfSymbol)) {
    char *str = PT_yieldTreeToString((PT_Tree) SDF_getSymbolSort(sdfSymbol),
				     ATfalse);
    result = PT_makeSymbolSort(str); 
  }
  else if (SDF_isSymbolLit(sdfSymbol)) {
    SDF_StrCon sdfLit = SDF_getSymbolString(sdfSymbol);
    const char *str = SDFStrConToString(sdfLit);
    result = PT_makeSymbolLit(str);
  }
  else if (SDF_isSymbolCiLit(sdfSymbol)) {
    SDF_SingleQuotedStrCon sdfLit = SDF_getSymbolCiString(sdfSymbol);
    const char *str = SDFCiStrConToString(sdfLit);
    result = PT_makeSymbolCilit(str);
  }
  else if (SDF_isSymbolIter(sdfSymbol)) {
    SDF_Symbol sdfIterSymbol = SDF_getSymbolSymbol(sdfSymbol);
    PT_Symbol ptIterSymbol = SDFSymbolToPtSymbol(sdfIterSymbol);
    result = PT_makeSymbolIterPlus(ptIterSymbol);
  }
  else if (SDF_isSymbolIterStar(sdfSymbol)) {
    SDF_Symbol sdfIterSymbol = SDF_getSymbolSymbol(sdfSymbol);
    PT_Symbol ptIterSymbol = SDFSymbolToPtSymbol(sdfIterSymbol);
    result = PT_makeSymbolIterStar(ptIterSymbol);
  }
  else if (SDF_isSymbolIterSep(sdfSymbol)) {
    SDF_Symbol sdfIterSymbol = SDF_getSymbolSymbol(sdfSymbol);
    SDF_Symbol sdfIterSep = SDF_getSymbolSep(sdfSymbol);
    PT_Symbol ptIterSymbol = SDFSymbolToPtSymbol(sdfIterSymbol);
    PT_Symbol ptSepSymbol = SDFSymbolToPtSymbol(sdfIterSep);
    result = PT_makeSymbolIterPlusSep(ptIterSymbol, ptSepSymbol);
  }
  else if (SDF_isSymbolIterStarSep(sdfSymbol)) {
    SDF_Symbol sdfIterSymbol = SDF_getSymbolSymbol(sdfSymbol);
    SDF_Symbol sdfIterSep = SDF_getSymbolSep(sdfSymbol);
    PT_Symbol ptIterSymbol = SDFSymbolToPtSymbol(sdfIterSymbol);
    PT_Symbol ptSepSymbol = SDFSymbolToPtSymbol(sdfIterSep);
    result = PT_makeSymbolIterStarSep(ptIterSymbol, ptSepSymbol);
  } 
  else if (SDF_isSymbolCf(sdfSymbol)) {
    SDF_Symbol sdfSym = SDF_getSymbolSymbol(sdfSymbol);
    PT_Symbol ptSym = SDFSymbolToPtSymbol(sdfSym);
    result = PT_makeSymbolCf(ptSym);
  }
  else if (SDF_isSymbolLex(sdfSymbol)) {
    SDF_Symbol sdfSym = SDF_getSymbolSymbol(sdfSymbol);
    PT_Symbol ptSym = SDFSymbolToPtSymbol(sdfSym);
    result = PT_makeSymbolLex(ptSym);
  }
  else if (SDF_isSymbolVarsym(sdfSymbol)) {
    SDF_Symbol sdfSym = SDF_getSymbolSymbol(sdfSymbol);
    PT_Symbol ptSym = SDFSymbolToPtSymbol(sdfSym);
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
    PT_Symbol ptHead = SDFSymbolToPtSymbol(sdfHead);
    PT_Symbols ptTail = SDFSymbolsToPtSymbols(sdfSymbols);
    result = PT_makeSymbolSeq(PT_makeSymbolsMany(ptHead, ptTail));
  }
  else if (SDF_isSymbolOpt(sdfSymbol)) {
    SDF_Symbol sdfSym = SDF_getSymbolSymbol(sdfSymbol);
    PT_Symbol ptSym = SDFSymbolToPtSymbol(sdfSym);
    result = PT_makeSymbolOpt(ptSym);
  }
  else if (SDF_isSymbolTuple(sdfSymbol)) {
    SDF_Symbol sdfHead = SDF_getSymbolHead(sdfSymbol);
    SDF_SymbolRest sdfRest = SDF_getSymbolRest(sdfSymbol);
    PT_Symbol ptHead = SDFSymbolToPtSymbol(sdfHead);
    PT_Symbols ptRest = SDFSymbolRestToPtSymbols(sdfRest);
    result = PT_makeSymbolTuple(ptHead, ptRest);
  }
  else if (SDF_isSymbolFunc(sdfSymbol)) {
    SDF_Symbols sdfArguments = SDF_getSymbolArguments(sdfSymbol);
    SDF_Symbol sdfResult = SDF_getSymbolResults(sdfSymbol);
    PT_Symbols ptArguments = SDFSymbolsToPtSymbols(sdfArguments);
    PT_Symbol ptResult = SDFSymbolToPtSymbol(sdfResult);
    result = PT_makeSymbolFunc(ptArguments,ptResult);
  }
  else if (SDF_isSymbolParameterizedSort(sdfSymbol)) {
    SDF_Sort sdfSort = SDF_getSymbolSort(sdfSymbol);
    SDF_SymbolParameters sdfParameters = SDF_getSymbolParameters(sdfSymbol);
    PT_Symbols ptParameters = SDFSymbolParametersToPtSymbols(sdfParameters);
    char *ptSort = PT_yieldTreeToString((PT_Tree) sdfSort, ATfalse);
    result = PT_makeSymbolParameterizedSort(ptSort, ptParameters);
  }
  else if (SDF_isSymbolAlt(sdfSymbol)) {
    SDF_Symbol sdfLeft = SDF_getSymbolLeft(sdfSymbol);
    SDF_Symbol sdfRight = SDF_getSymbolRight(sdfSymbol);
    PT_Symbol ptLeft = SDFSymbolToPtSymbol(sdfLeft);
    PT_Symbol ptRight = SDFSymbolToPtSymbol(sdfRight);
    result = PT_makeSymbolAlt(ptLeft, ptRight);
  }
  else if (SDF_isSymbolCharClass(sdfSymbol)) {
    SDF_CharClass sdfCC = SDF_getSymbolCharClass(sdfSymbol);
    PT_CharRanges ptCR = SDFCharClassToPtCharRanges(sdfCC);
    result = PT_makeSymbolCharClass(ptCR);
  }
  else if (SDF_isSymbolLabel(sdfSymbol)) {
    SDF_Symbol arg = SDF_getSymbolSymbol(sdfSymbol);
    result = SDFSymbolToPtSymbol(arg);
  }
  else if (SDF_isSymbolStrategy(sdfSymbol)) {
    SDF_Symbol sdfLeft = SDF_getSymbolLeft(sdfSymbol);
    SDF_Symbol sdfRight = SDF_getSymbolRight(sdfSymbol);
    PT_Symbol ptLeft = SDFSymbolToPtSymbol(sdfLeft);
    PT_Symbol ptRight = SDFSymbolToPtSymbol(sdfRight);
    result = PT_makeSymbolStrategy(ptLeft, ptRight);
  }
  else if (SDF_isSymbolBracket(sdfSymbol)) {
    SDF_Symbol sym = SDF_getSymbolSymbol(sdfSymbol);
    result = SDFSymbolToPtSymbol(sym);
  }
  else {
    ATerror("SDFSymbolToPtSymbol: unable to convert symbol %t: %s\n", 
	    sdfSymbol, PT_yieldTreeToString((PT_Tree) sdfSymbol, ATfalse));
    result = NULL;
  }
	    
  return result;
}

static PT_Attributes SDFAttributesToPtAttributes(SDF_Attributes sdfAttributes) 
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
        PT_Attr ptAttr = SDFAttributeToPtAttr(sdfAttr);
        
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

    if (ptAttrList == NULL) {
      ptAttributes = PT_makeAttributesNoAttrs();
    }
    else {
      ptAttributes = PT_makeAttributesAttrs(
                       PT_reverseAttrs(ptAttrList));
    }
  }

  return ptAttributes;
}
                     
static PT_Attr SDFAttributeToPtAttr(SDF_Attribute sdfAttribute)
{
  PT_Attr ptAttr = NULL;

  if (SDF_isAttributeBracket(sdfAttribute)) {
    ptAttr = PT_makeAttrBracket();         
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
  else if (SDF_isAttributeId(sdfAttribute)) {
    SDF_ModuleName sdfModuleName = SDF_getAttributeModuleName(sdfAttribute);
    SDF_ModuleId  sdfModuleId = SDF_getModuleNameModuleId(sdfModuleName);
    char *str = PT_yieldTree((PT_Tree) sdfModuleId);
    ptAttr = PT_makeAttrId(str);         
  }
  else if (SDF_isAttributeAssoc(sdfAttribute)) {
    SDF_Associativity sdfAssoc = SDF_getAttributeAssociativity(sdfAttribute);
    PT_Associativity ptAssoc = NULL;

    if (SDF_isAssociativityLeft(sdfAssoc)) {
      ptAssoc = PT_makeAssociativityLeft();
    }
    else if (SDF_isAssociativityRight(sdfAssoc)) {
      ptAssoc = PT_makeAssociativityRight();
    }
    else if (SDF_isAssociativityNonAssoc(sdfAssoc)) {
      ptAssoc = PT_makeAssociativityNonAssoc();
    }
    else if (SDF_isAssociativityAssoc(sdfAssoc)) { 
      ptAssoc = PT_makeAssociativityAssoc();
    }

    ptAttr = PT_makeAttrAssoc(ptAssoc);
  }
  else if (SDF_isAttributeId(sdfAttribute)) {
    char *moduleName = PT_yieldTreeToString((PT_Tree) sdfAttribute, ATfalse);
    ptAttr = PT_makeAttrId(moduleName);
  }
  else if (SDF_isAttributeTerm(sdfAttribute)) {
    ATerm term = ATmake(PT_yieldTreeToString((PT_Tree) sdfAttribute, ATfalse));
    if (term == NULL) {
      ATerror("SDFAttributeToPtAttr (term): unable to convert %s\n",
	      PT_yieldTreeToString((PT_Tree) sdfAttribute, ATfalse));
      ptAttr = NULL;
    }
    else {
      ptAttr = PT_makeAttrTerm(term);
    }
  }
  else {
     ATerror("SDFAttributeToPtAttr: unable to convert %s\n", 
	     PT_yieldTreeToString((PT_Tree) sdfAttribute, ATfalse));
     ptAttr = NULL;
  }

  return ptAttr;
}

static int SDFCharacterToInt(SDF_Character sdfCharacter)
{
  int result;

  if (SDF_isCharacterNumeric(sdfCharacter)) {
    SDF_NumChar sdfNumChar = SDF_getCharacterNumChar(sdfCharacter);
    char *numchar = PT_yieldTreeToString((PT_Tree) sdfNumChar, ATfalse);
    result = atoi(numchar+1); /* remove leading backslash */ 
  }
  else if (SDF_isCharacterShort(sdfCharacter)) {
    SDF_ShortChar sdfShortChar = SDF_getCharacterShortChar(sdfCharacter);
    char *numchar = PT_yieldTreeToString((PT_Tree) sdfShortChar, ATfalse);
    if (numchar[0] != '\\') {
      result = (int) numchar[0];
    } 
    else {
      result = (int) numchar[1]; /* skip backslash */
    }
  }
  else {
    ATerror("SDFCharacterToInt: unable to convert %s\n",
	    PT_yieldTreeToString((PT_Tree) sdfCharacter, ATfalse));
    result = -1;
  }

  return result;
}

static PT_CharRange SDFCharRangeToPtCharRange(SDF_CharRange sdfCharRange)
{
  PT_CharRange result;

  if (SDF_isCharRangeDefault(sdfCharRange)) {
    SDF_Character sdfChar = SDF_getCharRangeCharacter(sdfCharRange);
    int ptChar = SDFCharacterToInt(sdfChar);
    result = PT_makeCharRangeCharacter(ptChar);
  }
  else if (SDF_isCharRangeRange(sdfCharRange)) {
    SDF_Character sdfStart = SDF_getCharRangeStart(sdfCharRange);
    SDF_Character sdfEnd = SDF_getCharRangeEnd(sdfCharRange);
    int ptStart = SDFCharacterToInt(sdfStart);
    int ptEnd = SDFCharacterToInt(sdfEnd);
    result = PT_makeCharRangeRange(ptStart,ptEnd);
  }
  else {
    ATerror("SDFCharRangeToPtCharRange: unable to convert %s\n",
	    PT_yieldTreeToString((PT_Tree) sdfCharRange, ATfalse));
    result = NULL;
  } 
 
  return result;
}

static PT_CharRanges SDFCharRangesToPtCharRanges(SDF_CharRanges sdfCharRanges)
{
  PT_CharRanges result = PT_makeCharRangesEmpty();


  if (SDF_isCharRangesDefault(sdfCharRanges)) {
    SDF_CharRange sdfCharRange = SDF_getCharRangesCharRange(sdfCharRanges);
    PT_CharRange ptCharRange = SDFCharRangeToPtCharRange(sdfCharRange);
    result = PT_makeCharRangesMany(ptCharRange, result);
  }
  else if (SDF_isCharRangesConc(sdfCharRanges)) {
    SDF_CharRanges sdfLeft = SDF_getCharRangesLeft(sdfCharRanges);
    SDF_CharRanges sdfRight = SDF_getCharRangesRight(sdfCharRanges);
    PT_CharRanges ptLeft = SDFCharRangesToPtCharRanges(sdfLeft);
    PT_CharRanges ptRight = SDFCharRangesToPtCharRanges(sdfRight);
    return PT_concatCharRanges(ptLeft, ptRight);
  }
  else {
    ATerror("SDFCharRangesToPtCharRanges: unable to convert %s\n",
	    PT_yieldTreeToString((PT_Tree) sdfCharRanges, ATfalse));
    result = NULL;
  }

  return result;
}

static PT_CharRanges SDFCharClassToPtCharRanges(SDF_CharClass sdfCharClass)
{
  PT_CharRanges result;

  if (SDF_isCharClassSimpleCharclass(sdfCharClass)) {
    SDF_OptCharRanges sdfOCR = SDF_getCharClassOptCharRanges(sdfCharClass);

    if (SDF_isOptCharRangesAbsent(sdfOCR)) {
      result = PT_makeCharRangesEmpty();
    }
    else {
      SDF_CharRanges sdfCharRanges = SDF_getOptCharRangesCharRanges(sdfOCR);
      result = SDFCharRangesToPtCharRanges(sdfCharRanges);
    } 
  }
  else {
    ATerror("SDFCharClassToPtCharRanges: unable to convert characterclass: %s\n",
	    PT_yieldTreeToString((PT_Tree) sdfCharClass, ATfalse));
    result = NULL;
  }
  
  return result;
}

PT_Symbol SDFCharClassToPtSymbol(SDF_CharClass sdfCharClass)
{
  return PT_makeSymbolCharClass(
           SDFCharClassToPtCharRanges(sdfCharClass));
}
