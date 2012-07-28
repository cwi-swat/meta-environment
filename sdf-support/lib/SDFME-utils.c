#include "SDFME-utils.h"
#include "MEPT-utils.h"
#include <assert.h>
#include <ctype.h>

/*{{{  ATerm SDF_getModuleNamePlain(SDF_ModuleName moduleName) */

ATerm SDF_getModuleNamePlain(SDF_ModuleName moduleName)
{
  SDF_ModuleId modid = SDF_getModuleNameModuleId(moduleName);
  ATerm result = ATmake("<str>", PT_yieldTree((PT_Tree) modid));

  return result;
}

/*}}}  */

/*{{{  SDF_Production SDF_removeAttributes(SDF_Production prod) */

SDF_Production SDF_removeAttributes(SDF_Production prod)
{
  SDF_Attributes emptyAttrs = SDF_makeAttributesNoAttrs();
  return SDF_setProductionAttributes(prod, emptyAttrs);
}

/*}}}  */
/*{{{  ATbool SDF_hasRejectAttribute(SDF_Production prod) */

ATbool SDF_hasRejectAttribute(SDF_Production prod)
{
  ATbool found = ATfalse;
  SDF_Attributes attrs = SDF_getProductionAttributes(prod);

  if (!SDF_isAttributesNoAttrs(attrs)) {
    SDF_AttributeList attrList = SDF_getAttributesList(attrs);
    
    while (SDF_hasAttributeListHead(attrList) && !found) {
      SDF_Attribute attr = SDF_getAttributeListHead(attrList);

      if (SDF_isAttributeReject(attr)) {
        found = ATtrue;
      }

      if (SDF_isAttributeListSingle(attrList)) {
        break;
      }
      attrList = SDF_getAttributeListTail(attrList);
    }
  }
  return found;
}

/*}}}  */
/*{{{  ATbool SDF_hasPreferAttribute(SDF_Production prod) */

ATbool SDF_hasPreferAttribute(SDF_Production prod)
{
  ATbool found = ATfalse;
  SDF_Attributes attrs = SDF_getProductionAttributes(prod);

  if (!SDF_isAttributesNoAttrs(attrs)) {
    SDF_AttributeList attrList = SDF_getAttributesList(attrs);
    
    while (SDF_hasAttributeListHead(attrList) && !found) {
      SDF_Attribute attr = SDF_getAttributeListHead(attrList);

      if (SDF_isAttributePrefer(attr)) {
        found = ATtrue;
      }

      if (SDF_isAttributeListSingle(attrList)) {
        break;
      }
      attrList = SDF_getAttributeListTail(attrList);
    }
  }
  return found;
}

/*}}}  */
/*{{{  ATbool SDF_hasAvoidAttribute(SDF_Production prod) */

ATbool SDF_hasAvoidAttribute(SDF_Production prod)
{
  ATbool found = ATfalse;
  SDF_Attributes attrs = SDF_getProductionAttributes(prod);

  if (!SDF_isAttributesNoAttrs(attrs)) {
    SDF_AttributeList attrList = SDF_getAttributesList(attrs);
    
    while (SDF_hasAttributeListHead(attrList) && !found) {
      SDF_Attribute attr = SDF_getAttributeListHead(attrList);

      if (SDF_isAttributeAvoid(attr)) {
        found = ATtrue;
      }

      if (SDF_isAttributeListSingle(attrList)) {
        break;
      }
      attrList = SDF_getAttributeListTail(attrList);
    }
  }
  return found;
}

/*}}}  */

/*{{{  SDF_OptLayout SDF_makeLayoutEmpty() */

SDF_OptLayout SDF_makeLayoutEmpty()
{
  return SDF_makeOptLayoutAbsent();
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_makeLayoutSpace() */

SDF_OptLayout SDF_makeLayoutSpace()
{
  return SDF_makeOptLayoutPresent(SDF_makeLayoutLexToCf(SDF_makeLexLayoutListSingle(SDF_makeLexLayoutWhitespace(' '))));
}

/*}}}  */
/*{{{  SDF_OptLayout SDF_makeLayoutNewline() */

SDF_OptLayout SDF_makeLayoutNewline()
{
  return SDF_makeOptLayoutPresent(SDF_makeLayoutLexToCf(SDF_makeLexLayoutListSingle(SDF_makeLexLayoutWhitespace('\n'))));
}

/*}}}  */

/*{{{  SDF_Symbol SDF_removeSymbolAnnotations(SDF_Symbol s) */

SDF_Symbol SDF_removeSymbolAnnotations(SDF_Symbol s)
{
  return SDF_SymbolFromTerm(ATremoveAllAnnotations(SDF_SymbolToTerm(s)));
}

/*}}}  */
/*{{{  SDF_ModuleId SDF_removeModuleIdAnnotations(SDF_ModuleId s) */

SDF_ModuleId SDF_removeModuleIdAnnotations(SDF_ModuleId s)
{
  return SDF_ModuleIdFromTerm(ATremoveAllAnnotations(SDF_ModuleIdToTerm(s)));
}

/*}}}  */
/*{{{  SDF_Import SDF_removeImportAnnotations(SDF_Import s) */

SDF_Import SDF_removeImportAnnotations(SDF_Import s)
{
  return SDF_ImportFromTerm(ATremoveAllAnnotations(SDF_ImportToTerm(s)));
}

/*}}}  */
/*{{{  SDF_ImportList SDF_removeImportListAnnotations(SDF_ImportList l) */

SDF_ImportList SDF_removeImportListAnnotations(SDF_ImportList l)
{
  return SDF_ImportListFromTerm(ATremoveAllAnnotations(SDF_ImportListToTerm(l)));
}

/*}}}  */

/*{{{  SDF_RenamingList SDF_insertRenaming(SDF_Renaming r, SDF_RenamingList l) */

SDF_RenamingList SDF_insertRenaming(SDF_Renaming r, SDF_RenamingList l)
{
  if (SDF_isRenamingListEmpty(l)) {
    return SDF_makeRenamingListSingle(r);
  }
  else {
    return SDF_makeRenamingListMany(r, SDF_makeLayoutSpace(), l);
  }
}

/*}}}  */

/*{{{  SDF_SymbolList SDF_insertSymbol(SDF_Symbol r, SDF_SymbolList l) */

SDF_SymbolList SDF_insertSymbol(SDF_Symbol r, SDF_SymbolList l)
{
  if (SDF_isSymbolListEmpty(l)) {
    return SDF_makeSymbolListSingle(r);
  }
  else {
    return SDF_makeSymbolListMany(r, SDF_makeLayoutSpace(), l);
  }
}

/*}}}  */


/*{{{  static SDF_LexStrCharChars SDF_makeLexStrChars(const char* str) */

static SDF_LexStrCharChars SDF_makeLexStrChars(const char* str)
{
  int len = strlen(str);
  int i;
  SDF_LexStrCharChars list = SDF_makeLexStrCharCharsEmpty();

  for (i = len - 1; i >= 0; i--) {
    SDF_LexStrChar ch;

    switch(str[i]) {
      case '\n':
	ch = SDF_makeLexStrCharNewline();
	break;
      case '\t':
	ch = SDF_makeLexStrCharTab();
	break;
      case '"':
	ch = SDF_makeLexStrCharQuote();
	break;
      case '\\':
	ch = SDF_makeLexStrCharBackslash();
	break;
      default:
	if (isprint((int) str[i])) {
	  ch = SDF_makeLexStrCharNormal(str[i]);
	}
	else {
	  int value = str[i];
	  int a, b, c;

	  c = value % 10;
	  value /= 10;
	  b = value % 10;
	  value /= 10;
	  a = value;

	  ch = SDF_makeLexStrCharDecimal(a,b,c);
	}
    }

    list = SDF_makeLexStrCharCharsMany(ch, list);
  }


  return list;
}

/*}}}  */

SDF_LexStrCon SDF_makeLexStrCon(const char* str) 
{
  return SDF_makeLexStrConDefault(SDF_makeLexStrChars(str));
}

/*{{{  static SDF_LexStrCharChars SDF_makeLexStrChars(const char* str) */

static SDF_LexSingleQuotedStrCharChars SDF_makeLexSingleQuotedStrChars(const char* str)
{
  int len = strlen(str);
  int i;
  SDF_LexSingleQuotedStrCharChars list = SDF_makeLexSingleQuotedStrCharCharsEmpty();

  for (i = len - 1; i >= 0; i--) {
    SDF_LexSingleQuotedStrChar ch;

    switch(str[i]) {
      case '\n':
	ch = SDF_makeLexSingleQuotedStrCharNewline();
	break;
      case '\t':
	ch = SDF_makeLexSingleQuotedStrCharTab();
	break;
      case '\'':
	ch = SDF_makeLexSingleQuotedStrCharQuote();
	break;
      case '\\':
	ch = SDF_makeLexSingleQuotedStrCharBackslash();
	break;
      default:
	if (isprint((int) str[i])) {
	  ch = SDF_makeLexSingleQuotedStrCharNormal(str[i]);
	}
	else {
	  int value = str[i];
	  int a, b, c;

	  c = value % 10;
	  value /= 10;
	  b = value % 10;
	  value /= 10;
	  a = value;

	  ch = SDF_makeLexSingleQuotedStrCharDecimal(a,b,c);
	}
    }

    list = SDF_makeLexSingleQuotedStrCharCharsMany(ch, list);
  }


  return list;
}

/*}}}  */

SDF_LexSingleQuotedStrCon SDF_makeLexSingleQuotedStrCon(const char* str)
{
  return SDF_makeLexSingleQuotedStrConDefault(SDF_makeLexSingleQuotedStrChars(str));
}

  
/*{{{  SDF_StrCon SDF_makeStrCon(const char *str)  */

SDF_StrCon SDF_makeStrCon(const char *str) 
{
  return SDF_makeStrConLexToCf(SDF_makeLexStrCon(str));
}

/*}}}  */
/*{{{  SDF_StrCon SDF_makeStrCon(const char *str)  */

SDF_SingleQuotedStrCon SDF_makeSingleQuotedStrCon(const char *str) 
{
  return SDF_makeSingleQuotedStrConLexToCf(SDF_makeLexSingleQuotedStrCon(str));
}

/*}}}  */

/*{{{  SDF_Sort SDF_makeSort(const char *str) */

SDF_Sort SDF_makeSort(const char *str)
{
  SDF_LexSort lex;

  if (strlen(str) == 1) {
    lex = SDF_makeLexSortOneChar(str[0]);
  }
  else if (strlen(str) > 1) {
    char *tmp = strdup(str);
    char head = str[0];
    char last = str[strlen(str) - 1];
    tmp[strlen(str) - 1] = '\0';

    lex = SDF_makeLexSortMoreChars(head, tmp+1, last);
  }
  else {
    assert("str has length 0");
    return NULL;
  }
 
  return SDF_makeSortLexToCf(lex); 
}

/*}}}  */

/*{{{  SDF_Sort SDF_makeSort(const char *str) */

int SDF_SDFNatConToInt(SDF_NatCon sdfNatCon) {
  char *valStr = PT_yieldTree((PT_Tree) sdfNatCon);
  int result = atoi(valStr);

  return result;
}

/*}}}  */
