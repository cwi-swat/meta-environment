#include "reshuffle.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static PT_Symbol     flattenSdfSymbol(SDF_Symbol sdfSymbol);
static PT_Symbols    flattenSdfSymbols(SDF_Symbols sdfSymbols);
static PT_Attributes flattenSdfAttributes(SDF_Attributes sdfAttributes);
static PT_Attr flattenSdfAttribute(SDF_Attribute sdfAttribute);


PT_Production
makeLexicalConstructorProd(SDF_Symbol symbol)
{
  char *sortName;
  char *name;
  int i;
  ASF_Symbol sortSymbol;
  ASF_Production lexConsProd;

  sortName = SDF_getSortLex(SDF_getSymbolSort(symbol));

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
  PT_Symbol layout = PT_makeSymbolEmptyLayout();
  PT_Symbol comma  = PT_makeSymbolQuotedLiteral(",");
  PT_Symbol open   = PT_makeSymbolQuotedLiteral("(");
  PT_Symbol close  = PT_makeSymbolQuotedLiteral(")");

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
  char *modname = SDF_getModuleIdLex(SDF_getModuleNameModuleId(sdfModuleName));
  SDF_Symbol  sdfResult  = SDF_getProductionResult(sdfProduction);
  SDF_Attributes sdfAttributes = SDF_getProductionAttributes(sdfProduction);

  PT_Symbols ptSymbols;
  PT_Symbol  ptResult  = flattenSdfSymbol(sdfResult);
  PT_Attributes ptAttributes = flattenSdfAttributes(sdfAttributes);

  if (SDF_isProductionProd(sdfProduction)) {
    SDF_Symbols sdfSymbols = SDF_getProductionSymbols(sdfProduction);
    ptSymbols = flattenSdfSymbols(sdfSymbols);
  }
  else if (SDF_isProductionProdFun(sdfProduction)) {
     SDF_Literal sdfLiteral = SDF_getProductionFunctionSymbol(sdfProduction);
     SDF_SymbolArguments sdfArgs = SDF_getProductionArguments(sdfProduction);

     ptSymbols = flattenSdfProductionProdFun(sdfLiteral, sdfArgs);
  } else {
    ATerror("flattenSdfProduction: illegal production %t\n", sdfProduction);
    return NULL;
  }
  return PT_makeProductionDefault(modname, ptSymbols, ptResult, ptAttributes);
}

static PT_Symbols    flattenSdfSymbols(SDF_Symbols sdfSymbols)
{
  SDF_SymbolList sdfSymbolList = SDF_getSymbolsList(sdfSymbols);
  PT_Symbols ptSymbols = PT_makeSymbolsEmpty();
  PT_Symbol layout = PT_makeSymbolEmptyLayout();

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

static char *unquotedStrDup(char *str)
{
  char *new;
  int len;

  if (strlen(str) > 0) {
    new = strdup(str+1);
    if (new == NULL) {
      ATerror("Could not allocate memory to copy string\n");
      return NULL;
    }

    len = strlen(new);
    if (len > 0) {
      new[len - 1] = '\0';
    }
    return new;
  }
  else {
    return str;
  }
}

static PT_Symbol     flattenSdfSymbol(SDF_Symbol sdfSymbol)
{
  PT_Symbol result = NULL;

  if (SDF_isSymbolSort(sdfSymbol)) {
    char *str = SDF_getSortLex(SDF_getSymbolSort(sdfSymbol));
    result = PT_makeSymbolSort(str); 
  }
  else if (SDF_isSymbolLit(sdfSymbol)) {
    SDF_Literal sdfLit = SDF_getSymbolLiteral(sdfSymbol);
 
    if (SDF_isLiteralQuoted(sdfLit)) {
      char *str = SDF_getLiteralLex(sdfLit);
      char *newStr = unquotedStrDup(str);

      result = PT_makeSymbolQuotedLiteral(newStr);
      free(newStr);
    }
    else {
      char *str = SDF_getUQLiteralLex(SDF_getLiteralUQLiteral(sdfLit));
      result = PT_makeSymbolQuotedLiteral(str);
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
    char *sep = SDF_getLiteralLex(SDF_getSymbolLiteral(sdfIterSep));
    char *newSep = unquotedStrDup(sep);
    result = PT_makeSymbolIterPlusSep(ptIterSymbol, newSep);
    free(newSep);
  }
  else if (SDF_isSymbolIterStarSep(sdfSymbol)) {
    SDF_Symbol sdfIterSymbol = SDF_getSymbolSymbol(sdfSymbol);
    SDF_Symbol sdfIterSep = SDF_getSymbolSep(sdfSymbol);
    PT_Symbol ptIterSymbol = flattenSdfSymbol(sdfIterSymbol);
    char *sep = SDF_getLiteralLex(SDF_getSymbolLiteral(sdfIterSep));
    char *newSep = unquotedStrDup(sep);
    result = PT_makeSymbolIterStarSep(ptIterSymbol, newSep);
    free(newSep);
  } 
 
  /* the following symbols need to be added for asfix2: 
  SDF_isSymbolCf(sdfSymbol)) {
  SDF_isSymbolLex(sdfSymbol)) {
  SDF_isSymbolVarsym(sdfSymbol)) {
  SDF_isSymbolLayout(sdfSymbol)) {
  SDF_isSymbolEmpty(sdfSymbol)) {
  SDF_isSymbolSeq(sdfSymbol)) {
  SDF_isSymbolOpt(sdfSymbol)) {
  SDF_isSymbolIterN(sdfSymbol)) {
  SDF_isSymbolIterSepN(sdfSymbol)) {
  SDF_isSymbolSet(sdfSymbol)) {
  SDF_isSymbolPair(sdfSymbol)) {
  SDF_isSymbolFunc(sdfSymbol)) {
  SDF_isSymbolAlt(sdfSymbol)) {
  SDF_isSymbolPerm(sdfSymbol)) {
  SDF_isSymbolCharClass(sdfSymbol)) {
  SDF_isSymbolLabel(sdfSymbol)) {
  SDF_isSymbolBracket(sdfSymbol)) { */    

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
    char *str = SDF_getModuleIdLex(sdfModuleId);
    ptAttr = PT_makeAttrId(str);         
  }
  else if (SDF_isAttributeCons(sdfAttribute)) {
    SDF_ATerm sdfATerm = SDF_getAttributeTerm(sdfAttribute);
    if (SDF_isATermFun(sdfATerm)) {
      SDF_AFun fun = SDF_getATermFun(sdfATerm);
      char *str = SDF_getLiteralLex(SDF_getAFunLiteral(fun));
      ptAttr = PT_makeAttrCons(str);         
    }
    else {
      ATerror("flattenSdfAttribute: cannot flatten %t\n", (ATerm) sdfAttribute);
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
  return ptAttr;
}
