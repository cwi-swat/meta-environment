#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "PTMEPT.h"

/*{{{  conversion functions */

ATerm PTPT_stringToChars(const char *str)
{
  int len = strlen(str);
  int i;
  ATermList result = ATempty;

  for (i = len - 1; i >= 0; i--) {
    result = ATinsert(result, (ATerm) ATmakeInt(str[i]));
  }

  return (ATerm) result;
}

ATerm PTPT_byteToChar(char ch)
{
    return (ATerm) ATmakeInt(ch);
}

char *PTPT_charsToString(ATerm arg)
{
  ATermList list = (ATermList) arg;
  int len = ATgetLength(list);
  int i;
  char *str;

  str = (char *) malloc(len+1);
  if (str == NULL) {
      return NULL;
  }

  for (i = 0; !ATisEmpty(list); list = ATgetNext(list), i++) {
    str[i] = (char) ATgetInt((ATermInt) ATgetFirst(list));
  }
  str[i] = '\0';

  return str;
}

char PTPT_charToByte(ATerm arg)
{
    return (char) ATgetInt((ATermInt) arg);
}


/*}}}  */

/*{{{  typedefs */

typedef struct ATerm _PTPT_OptLayout;
typedef struct ATerm _PTPT_Layout;
typedef struct ATerm _PTPT_LexLayoutList;
typedef struct ATerm _PTPT_Tree;
typedef struct ATerm _PTPT_Attributes;
typedef struct ATerm _PTPT_Attrs;
typedef struct ATerm _PTPT_Attr;
typedef struct ATerm _PTPT_Associativity;
typedef struct ATerm _PTPT_AttrList;
typedef struct ATerm _PTPT_ParseTree;
typedef struct ATerm _PTPT_Symbol;
typedef struct ATerm _PTPT_Symbols;
typedef struct ATerm _PTPT_CharRanges;
typedef struct ATerm _PTPT_CharRange;
typedef struct ATerm _PTPT_Start;
typedef struct ATerm _PTPT_SymbolList;
typedef struct ATerm _PTPT_CharRangeList;
typedef struct ATerm _PTPT_Args;
typedef struct ATerm _PTPT_Production;
typedef struct ATerm _PTPT_TreeList;
typedef struct ATerm _PTPT_AFun;
typedef struct ATerm _PTPT_ATerm;
typedef struct ATerm _PTPT_Annotation;
typedef struct ATerm _PTPT_ATermArgs;
typedef struct ATerm _PTPT_ATermElems;
typedef struct ATerm _PTPT_ATermAnnos;
typedef struct ATerm _PTPT_IntCon;
typedef struct ATerm _PTPT_OptExp;
typedef struct ATerm _PTPT_RealCon;
typedef struct ATerm _PTPT_LexStrChar;
typedef struct ATerm _PTPT_StrChar;
typedef struct ATerm _PTPT_LexStrCon;
typedef struct ATerm _PTPT_StrCon;
typedef struct ATerm _PTPT_LexStrCharChars;
typedef struct ATerm _PTPT_LexNatCon;
typedef struct ATerm _PTPT_NatCon;
typedef struct ATerm _PTPT_LexIdCon;
typedef struct ATerm _PTPT_IdCon;
typedef struct ATerm _PTPT_LexLayout;

/*}}}  */

/*{{{  void PTPT_initPTMEPTApi(void) */

void PTPT_initPTMEPTApi(void)
{
  init_PTMEPT_dict();
}

/*}}}  */

/*{{{  protect functions */

void PTPT_protectOptLayout(PTPT_OptLayout *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PTPT_protectLayout(PTPT_Layout *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PTPT_protectLexLayoutList(PTPT_LexLayoutList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PTPT_protectTree(PTPT_Tree *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PTPT_protectAttributes(PTPT_Attributes *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PTPT_protectAttrs(PTPT_Attrs *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PTPT_protectAttr(PTPT_Attr *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PTPT_protectAssociativity(PTPT_Associativity *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PTPT_protectAttrList(PTPT_AttrList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PTPT_protectParseTree(PTPT_ParseTree *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PTPT_protectSymbol(PTPT_Symbol *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PTPT_protectSymbols(PTPT_Symbols *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PTPT_protectCharRanges(PTPT_CharRanges *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PTPT_protectCharRange(PTPT_CharRange *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PTPT_protectStart(PTPT_Start *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PTPT_protectSymbolList(PTPT_SymbolList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PTPT_protectCharRangeList(PTPT_CharRangeList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PTPT_protectArgs(PTPT_Args *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PTPT_protectProduction(PTPT_Production *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PTPT_protectTreeList(PTPT_TreeList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PTPT_protectAFun(PTPT_AFun *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PTPT_protectATerm(PTPT_ATerm *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PTPT_protectAnnotation(PTPT_Annotation *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PTPT_protectATermArgs(PTPT_ATermArgs *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PTPT_protectATermElems(PTPT_ATermElems *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PTPT_protectATermAnnos(PTPT_ATermAnnos *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PTPT_protectIntCon(PTPT_IntCon *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PTPT_protectOptExp(PTPT_OptExp *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PTPT_protectRealCon(PTPT_RealCon *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PTPT_protectLexStrChar(PTPT_LexStrChar *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PTPT_protectStrChar(PTPT_StrChar *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PTPT_protectLexStrCon(PTPT_LexStrCon *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PTPT_protectStrCon(PTPT_StrCon *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PTPT_protectLexStrCharChars(PTPT_LexStrCharChars *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PTPT_protectLexNatCon(PTPT_LexNatCon *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PTPT_protectNatCon(PTPT_NatCon *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PTPT_protectLexIdCon(PTPT_LexIdCon *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PTPT_protectIdCon(PTPT_IdCon *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void PTPT_protectLexLayout(PTPT_LexLayout *arg)
{
  ATprotect((ATerm*)((void*) arg));
}


/*}}}  */
/*{{{  term conversion functions */

/*{{{  PTPT_OptLayout PTPT_OptLayoutFromTerm(ATerm t) */

PTPT_OptLayout PTPT_OptLayoutFromTerm(ATerm t)
{
  return (PTPT_OptLayout)t;
}

/*}}}  */
/*{{{  ATerm PTPT_OptLayoutToTerm(PTPT_OptLayout arg) */

ATerm PTPT_OptLayoutToTerm(PTPT_OptLayout arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTPT_Layout PTPT_LayoutFromTerm(ATerm t) */

PTPT_Layout PTPT_LayoutFromTerm(ATerm t)
{
  return (PTPT_Layout)t;
}

/*}}}  */
/*{{{  ATerm PTPT_LayoutToTerm(PTPT_Layout arg) */

ATerm PTPT_LayoutToTerm(PTPT_Layout arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTPT_LexLayoutList PTPT_LexLayoutListFromTerm(ATerm t) */

PTPT_LexLayoutList PTPT_LexLayoutListFromTerm(ATerm t)
{
  return (PTPT_LexLayoutList)t;
}

/*}}}  */
/*{{{  ATerm PTPT_LexLayoutListToTerm(PTPT_LexLayoutList arg) */

ATerm PTPT_LexLayoutListToTerm(PTPT_LexLayoutList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTPT_Tree PTPT_TreeFromTerm(ATerm t) */

PTPT_Tree PTPT_TreeFromTerm(ATerm t)
{
  return (PTPT_Tree)t;
}

/*}}}  */
/*{{{  ATerm PTPT_TreeToTerm(PTPT_Tree arg) */

ATerm PTPT_TreeToTerm(PTPT_Tree arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTPT_Attributes PTPT_AttributesFromTerm(ATerm t) */

PTPT_Attributes PTPT_AttributesFromTerm(ATerm t)
{
  return (PTPT_Attributes)t;
}

/*}}}  */
/*{{{  ATerm PTPT_AttributesToTerm(PTPT_Attributes arg) */

ATerm PTPT_AttributesToTerm(PTPT_Attributes arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTPT_Attrs PTPT_AttrsFromTerm(ATerm t) */

PTPT_Attrs PTPT_AttrsFromTerm(ATerm t)
{
  return (PTPT_Attrs)t;
}

/*}}}  */
/*{{{  ATerm PTPT_AttrsToTerm(PTPT_Attrs arg) */

ATerm PTPT_AttrsToTerm(PTPT_Attrs arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTPT_Attr PTPT_AttrFromTerm(ATerm t) */

PTPT_Attr PTPT_AttrFromTerm(ATerm t)
{
  return (PTPT_Attr)t;
}

/*}}}  */
/*{{{  ATerm PTPT_AttrToTerm(PTPT_Attr arg) */

ATerm PTPT_AttrToTerm(PTPT_Attr arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTPT_Associativity PTPT_AssociativityFromTerm(ATerm t) */

PTPT_Associativity PTPT_AssociativityFromTerm(ATerm t)
{
  return (PTPT_Associativity)t;
}

/*}}}  */
/*{{{  ATerm PTPT_AssociativityToTerm(PTPT_Associativity arg) */

ATerm PTPT_AssociativityToTerm(PTPT_Associativity arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTPT_AttrList PTPT_AttrListFromTerm(ATerm t) */

PTPT_AttrList PTPT_AttrListFromTerm(ATerm t)
{
  return (PTPT_AttrList)t;
}

/*}}}  */
/*{{{  ATerm PTPT_AttrListToTerm(PTPT_AttrList arg) */

ATerm PTPT_AttrListToTerm(PTPT_AttrList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTPT_ParseTree PTPT_ParseTreeFromTerm(ATerm t) */

PTPT_ParseTree PTPT_ParseTreeFromTerm(ATerm t)
{
  return (PTPT_ParseTree)t;
}

/*}}}  */
/*{{{  ATerm PTPT_ParseTreeToTerm(PTPT_ParseTree arg) */

ATerm PTPT_ParseTreeToTerm(PTPT_ParseTree arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_SymbolFromTerm(ATerm t) */

PTPT_Symbol PTPT_SymbolFromTerm(ATerm t)
{
  return (PTPT_Symbol)t;
}

/*}}}  */
/*{{{  ATerm PTPT_SymbolToTerm(PTPT_Symbol arg) */

ATerm PTPT_SymbolToTerm(PTPT_Symbol arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTPT_Symbols PTPT_SymbolsFromTerm(ATerm t) */

PTPT_Symbols PTPT_SymbolsFromTerm(ATerm t)
{
  return (PTPT_Symbols)t;
}

/*}}}  */
/*{{{  ATerm PTPT_SymbolsToTerm(PTPT_Symbols arg) */

ATerm PTPT_SymbolsToTerm(PTPT_Symbols arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTPT_CharRanges PTPT_CharRangesFromTerm(ATerm t) */

PTPT_CharRanges PTPT_CharRangesFromTerm(ATerm t)
{
  return (PTPT_CharRanges)t;
}

/*}}}  */
/*{{{  ATerm PTPT_CharRangesToTerm(PTPT_CharRanges arg) */

ATerm PTPT_CharRangesToTerm(PTPT_CharRanges arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTPT_CharRange PTPT_CharRangeFromTerm(ATerm t) */

PTPT_CharRange PTPT_CharRangeFromTerm(ATerm t)
{
  return (PTPT_CharRange)t;
}

/*}}}  */
/*{{{  ATerm PTPT_CharRangeToTerm(PTPT_CharRange arg) */

ATerm PTPT_CharRangeToTerm(PTPT_CharRange arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTPT_Start PTPT_StartFromTerm(ATerm t) */

PTPT_Start PTPT_StartFromTerm(ATerm t)
{
  return (PTPT_Start)t;
}

/*}}}  */
/*{{{  ATerm PTPT_StartToTerm(PTPT_Start arg) */

ATerm PTPT_StartToTerm(PTPT_Start arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTPT_SymbolList PTPT_SymbolListFromTerm(ATerm t) */

PTPT_SymbolList PTPT_SymbolListFromTerm(ATerm t)
{
  return (PTPT_SymbolList)t;
}

/*}}}  */
/*{{{  ATerm PTPT_SymbolListToTerm(PTPT_SymbolList arg) */

ATerm PTPT_SymbolListToTerm(PTPT_SymbolList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTPT_CharRangeList PTPT_CharRangeListFromTerm(ATerm t) */

PTPT_CharRangeList PTPT_CharRangeListFromTerm(ATerm t)
{
  return (PTPT_CharRangeList)t;
}

/*}}}  */
/*{{{  ATerm PTPT_CharRangeListToTerm(PTPT_CharRangeList arg) */

ATerm PTPT_CharRangeListToTerm(PTPT_CharRangeList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTPT_Args PTPT_ArgsFromTerm(ATerm t) */

PTPT_Args PTPT_ArgsFromTerm(ATerm t)
{
  return (PTPT_Args)t;
}

/*}}}  */
/*{{{  ATerm PTPT_ArgsToTerm(PTPT_Args arg) */

ATerm PTPT_ArgsToTerm(PTPT_Args arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTPT_Production PTPT_ProductionFromTerm(ATerm t) */

PTPT_Production PTPT_ProductionFromTerm(ATerm t)
{
  return (PTPT_Production)t;
}

/*}}}  */
/*{{{  ATerm PTPT_ProductionToTerm(PTPT_Production arg) */

ATerm PTPT_ProductionToTerm(PTPT_Production arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTPT_TreeList PTPT_TreeListFromTerm(ATerm t) */

PTPT_TreeList PTPT_TreeListFromTerm(ATerm t)
{
  return (PTPT_TreeList)t;
}

/*}}}  */
/*{{{  ATerm PTPT_TreeListToTerm(PTPT_TreeList arg) */

ATerm PTPT_TreeListToTerm(PTPT_TreeList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTPT_AFun PTPT_AFunFromTerm(ATerm t) */

PTPT_AFun PTPT_AFunFromTerm(ATerm t)
{
  return (PTPT_AFun)t;
}

/*}}}  */
/*{{{  ATerm PTPT_AFunToTerm(PTPT_AFun arg) */

ATerm PTPT_AFunToTerm(PTPT_AFun arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTPT_ATerm PTPT_ATermFromTerm(ATerm t) */

PTPT_ATerm PTPT_ATermFromTerm(ATerm t)
{
  return (PTPT_ATerm)t;
}

/*}}}  */
/*{{{  ATerm PTPT_ATermToTerm(PTPT_ATerm arg) */

ATerm PTPT_ATermToTerm(PTPT_ATerm arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTPT_Annotation PTPT_AnnotationFromTerm(ATerm t) */

PTPT_Annotation PTPT_AnnotationFromTerm(ATerm t)
{
  return (PTPT_Annotation)t;
}

/*}}}  */
/*{{{  ATerm PTPT_AnnotationToTerm(PTPT_Annotation arg) */

ATerm PTPT_AnnotationToTerm(PTPT_Annotation arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTPT_ATermArgs PTPT_ATermArgsFromTerm(ATerm t) */

PTPT_ATermArgs PTPT_ATermArgsFromTerm(ATerm t)
{
  return (PTPT_ATermArgs)t;
}

/*}}}  */
/*{{{  ATerm PTPT_ATermArgsToTerm(PTPT_ATermArgs arg) */

ATerm PTPT_ATermArgsToTerm(PTPT_ATermArgs arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTPT_ATermElems PTPT_ATermElemsFromTerm(ATerm t) */

PTPT_ATermElems PTPT_ATermElemsFromTerm(ATerm t)
{
  return (PTPT_ATermElems)t;
}

/*}}}  */
/*{{{  ATerm PTPT_ATermElemsToTerm(PTPT_ATermElems arg) */

ATerm PTPT_ATermElemsToTerm(PTPT_ATermElems arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTPT_ATermAnnos PTPT_ATermAnnosFromTerm(ATerm t) */

PTPT_ATermAnnos PTPT_ATermAnnosFromTerm(ATerm t)
{
  return (PTPT_ATermAnnos)t;
}

/*}}}  */
/*{{{  ATerm PTPT_ATermAnnosToTerm(PTPT_ATermAnnos arg) */

ATerm PTPT_ATermAnnosToTerm(PTPT_ATermAnnos arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTPT_IntCon PTPT_IntConFromTerm(ATerm t) */

PTPT_IntCon PTPT_IntConFromTerm(ATerm t)
{
  return (PTPT_IntCon)t;
}

/*}}}  */
/*{{{  ATerm PTPT_IntConToTerm(PTPT_IntCon arg) */

ATerm PTPT_IntConToTerm(PTPT_IntCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTPT_OptExp PTPT_OptExpFromTerm(ATerm t) */

PTPT_OptExp PTPT_OptExpFromTerm(ATerm t)
{
  return (PTPT_OptExp)t;
}

/*}}}  */
/*{{{  ATerm PTPT_OptExpToTerm(PTPT_OptExp arg) */

ATerm PTPT_OptExpToTerm(PTPT_OptExp arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTPT_RealCon PTPT_RealConFromTerm(ATerm t) */

PTPT_RealCon PTPT_RealConFromTerm(ATerm t)
{
  return (PTPT_RealCon)t;
}

/*}}}  */
/*{{{  ATerm PTPT_RealConToTerm(PTPT_RealCon arg) */

ATerm PTPT_RealConToTerm(PTPT_RealCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTPT_LexStrChar PTPT_LexStrCharFromTerm(ATerm t) */

PTPT_LexStrChar PTPT_LexStrCharFromTerm(ATerm t)
{
  return (PTPT_LexStrChar)t;
}

/*}}}  */
/*{{{  ATerm PTPT_LexStrCharToTerm(PTPT_LexStrChar arg) */

ATerm PTPT_LexStrCharToTerm(PTPT_LexStrChar arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTPT_StrChar PTPT_StrCharFromTerm(ATerm t) */

PTPT_StrChar PTPT_StrCharFromTerm(ATerm t)
{
  return (PTPT_StrChar)t;
}

/*}}}  */
/*{{{  ATerm PTPT_StrCharToTerm(PTPT_StrChar arg) */

ATerm PTPT_StrCharToTerm(PTPT_StrChar arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTPT_LexStrCon PTPT_LexStrConFromTerm(ATerm t) */

PTPT_LexStrCon PTPT_LexStrConFromTerm(ATerm t)
{
  return (PTPT_LexStrCon)t;
}

/*}}}  */
/*{{{  ATerm PTPT_LexStrConToTerm(PTPT_LexStrCon arg) */

ATerm PTPT_LexStrConToTerm(PTPT_LexStrCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTPT_StrCon PTPT_StrConFromTerm(ATerm t) */

PTPT_StrCon PTPT_StrConFromTerm(ATerm t)
{
  return (PTPT_StrCon)t;
}

/*}}}  */
/*{{{  ATerm PTPT_StrConToTerm(PTPT_StrCon arg) */

ATerm PTPT_StrConToTerm(PTPT_StrCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTPT_LexStrCharChars PTPT_LexStrCharCharsFromTerm(ATerm t) */

PTPT_LexStrCharChars PTPT_LexStrCharCharsFromTerm(ATerm t)
{
  return (PTPT_LexStrCharChars)t;
}

/*}}}  */
/*{{{  ATerm PTPT_LexStrCharCharsToTerm(PTPT_LexStrCharChars arg) */

ATerm PTPT_LexStrCharCharsToTerm(PTPT_LexStrCharChars arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTPT_LexNatCon PTPT_LexNatConFromTerm(ATerm t) */

PTPT_LexNatCon PTPT_LexNatConFromTerm(ATerm t)
{
  return (PTPT_LexNatCon)t;
}

/*}}}  */
/*{{{  ATerm PTPT_LexNatConToTerm(PTPT_LexNatCon arg) */

ATerm PTPT_LexNatConToTerm(PTPT_LexNatCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTPT_NatCon PTPT_NatConFromTerm(ATerm t) */

PTPT_NatCon PTPT_NatConFromTerm(ATerm t)
{
  return (PTPT_NatCon)t;
}

/*}}}  */
/*{{{  ATerm PTPT_NatConToTerm(PTPT_NatCon arg) */

ATerm PTPT_NatConToTerm(PTPT_NatCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTPT_LexIdCon PTPT_LexIdConFromTerm(ATerm t) */

PTPT_LexIdCon PTPT_LexIdConFromTerm(ATerm t)
{
  return (PTPT_LexIdCon)t;
}

/*}}}  */
/*{{{  ATerm PTPT_LexIdConToTerm(PTPT_LexIdCon arg) */

ATerm PTPT_LexIdConToTerm(PTPT_LexIdCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTPT_IdCon PTPT_IdConFromTerm(ATerm t) */

PTPT_IdCon PTPT_IdConFromTerm(ATerm t)
{
  return (PTPT_IdCon)t;
}

/*}}}  */
/*{{{  ATerm PTPT_IdConToTerm(PTPT_IdCon arg) */

ATerm PTPT_IdConToTerm(PTPT_IdCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PTPT_LexLayout PTPT_LexLayoutFromTerm(ATerm t) */

PTPT_LexLayout PTPT_LexLayoutFromTerm(ATerm t)
{
  return (PTPT_LexLayout)t;
}

/*}}}  */
/*{{{  ATerm PTPT_LexLayoutToTerm(PTPT_LexLayout arg) */

ATerm PTPT_LexLayoutToTerm(PTPT_LexLayout arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*}}}  */
/*{{{  list functions */

int PTPT_getLexLayoutListLength (PTPT_LexLayoutList arg) {
  return ATgetLength((ATermList) arg);
}
PTPT_LexLayoutList PTPT_reverseLexLayoutList(PTPT_LexLayoutList arg) {
  return (PTPT_LexLayoutList) ATreverse((ATermList) arg);
}
PTPT_LexLayoutList PTPT_appendLexLayoutList(PTPT_LexLayoutList arg, PTPT_LexLayout elem) {
  return (PTPT_LexLayoutList) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}
PTPT_LexLayoutList PTPT_concatLexLayoutList(PTPT_LexLayoutList arg0, PTPT_LexLayoutList arg1) {
  return (PTPT_LexLayoutList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
PTPT_LexLayoutList PTPT_sliceLexLayoutList(PTPT_LexLayoutList arg, int start, int end) {
  return (PTPT_LexLayoutList) ATgetSlice((ATermList) arg, start, end);
}
PTPT_LexLayout PTPT_getLexLayoutListLexLayoutAt(PTPT_LexLayoutList arg, int index) {
 return (PTPT_LexLayout)ATelementAt((ATermList) arg,index);
}
PTPT_LexLayoutList PTPT_replaceLexLayoutListLexLayoutAt(PTPT_LexLayoutList arg, PTPT_LexLayout elem, int index) {
 return (PTPT_LexLayoutList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}
PTPT_LexLayoutList PTPT_makeLexLayoutList2(PTPT_LexLayout elem1, PTPT_LexLayout elem2) {
  return (PTPT_LexLayoutList) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}
PTPT_LexLayoutList PTPT_makeLexLayoutList3(PTPT_LexLayout elem1, PTPT_LexLayout elem2, PTPT_LexLayout elem3) {
  return (PTPT_LexLayoutList) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}
PTPT_LexLayoutList PTPT_makeLexLayoutList4(PTPT_LexLayout elem1, PTPT_LexLayout elem2, PTPT_LexLayout elem3, PTPT_LexLayout elem4) {
  return (PTPT_LexLayoutList) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}
PTPT_LexLayoutList PTPT_makeLexLayoutList5(PTPT_LexLayout elem1, PTPT_LexLayout elem2, PTPT_LexLayout elem3, PTPT_LexLayout elem4, PTPT_LexLayout elem5) {
  return (PTPT_LexLayoutList) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}
PTPT_LexLayoutList PTPT_makeLexLayoutList6(PTPT_LexLayout elem1, PTPT_LexLayout elem2, PTPT_LexLayout elem3, PTPT_LexLayout elem4, PTPT_LexLayout elem5, PTPT_LexLayout elem6) {
  return (PTPT_LexLayoutList) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}
int PTPT_getAttrListLength (PTPT_AttrList arg) {
  if (ATisEmpty((ATermList) arg)) {
    return 0;
  }
  return (ATgetLength((ATermList) arg) / 4) + 1;
}
PTPT_AttrList PTPT_reverseAttrList(PTPT_AttrList arg) {
  ATermList list = (ATermList) arg;
  ATerm head;
  ATerm sep0;
  ATerm sep1;
  ATerm sep2;
  ATermList result;

 if (ATisEmpty(list) || ATgetLength(list) == 1) {
    return arg;
  }

  result = ATmakeList1(ATgetFirst(list));
      list = ATgetNext(list);
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);

  while (!ATisEmpty(list)) {
    result = ATinsert(result, sep2);
    result = ATinsert(result, sep1);
    result = ATinsert(result, sep0);

   head = ATgetFirst(list);
   result = ATinsert(result, head);
    list = ATgetNext(list);

   if (!ATisEmpty(list)) {
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);
   }
  }

  return (PTPT_AttrList) result;
}
PTPT_AttrList PTPT_appendAttrList(PTPT_AttrList arg0, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_Attr arg1) {
  return PTPT_concatAttrList(arg0, wsAfterHead, wsAfterSep, PTPT_makeAttrListSingle(arg1));
}
PTPT_AttrList PTPT_concatAttrList(PTPT_AttrList arg0, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_AttrList arg1) {
  if (ATisEmpty((ATermList) arg0)) {
    return arg1;
  }
  arg1 = PTPT_makeAttrListMany((PTPT_Attr)ATgetFirst((ATermList) arg0), wsAfterHead, wsAfterSep,  arg1);
  arg1 = (PTPT_AttrList) ATgetNext((ATermList) arg1);
  return (PTPT_AttrList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
PTPT_AttrList PTPT_sliceAttrList(PTPT_AttrList arg, int start, int end) {
  return (PTPT_AttrList) ATgetSlice((ATermList) arg, start * 4, end * 4);
}
PTPT_Attr PTPT_getAttrListAttrAt(PTPT_AttrList arg, int index) {
 return (PTPT_Attr)ATelementAt((ATermList) arg,index * 4);
}
PTPT_AttrList PTPT_replaceAttrListAttrAt(PTPT_AttrList arg, PTPT_Attr elem, int index) {
 return (PTPT_AttrList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index * 4);
}
PTPT_AttrList PTPT_makeAttrList2(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_Attr elem1, PTPT_Attr elem2) {
  return PTPT_makeAttrListMany(elem1, wsAfterHead, wsAfterSep, PTPT_makeAttrListSingle(elem2));
}
PTPT_AttrList PTPT_makeAttrList3(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_Attr elem1, PTPT_Attr elem2, PTPT_Attr elem3) {
  return PTPT_makeAttrListMany(elem1, wsAfterHead, wsAfterSep, PTPT_makeAttrList2(wsAfterHead, wsAfterSep, elem2, elem3));
}
PTPT_AttrList PTPT_makeAttrList4(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_Attr elem1, PTPT_Attr elem2, PTPT_Attr elem3, PTPT_Attr elem4) {
  return PTPT_makeAttrListMany(elem1, wsAfterHead, wsAfterSep, PTPT_makeAttrList3(wsAfterHead, wsAfterSep, elem2, elem3, elem4));
}
PTPT_AttrList PTPT_makeAttrList5(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_Attr elem1, PTPT_Attr elem2, PTPT_Attr elem3, PTPT_Attr elem4, PTPT_Attr elem5) {
  return PTPT_makeAttrListMany(elem1, wsAfterHead, wsAfterSep, PTPT_makeAttrList4(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5));
}
PTPT_AttrList PTPT_makeAttrList6(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_Attr elem1, PTPT_Attr elem2, PTPT_Attr elem3, PTPT_Attr elem4, PTPT_Attr elem5, PTPT_Attr elem6) {
  return PTPT_makeAttrListMany(elem1, wsAfterHead, wsAfterSep, PTPT_makeAttrList5(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5, elem6));
}
int PTPT_getSymbolListLength (PTPT_SymbolList arg) {
  if (ATisEmpty((ATermList) arg)) {
    return 0;
  }
  return (ATgetLength((ATermList) arg) / 4) + 1;
}
PTPT_SymbolList PTPT_reverseSymbolList(PTPT_SymbolList arg) {
  ATermList list = (ATermList) arg;
  ATerm head;
  ATerm sep0;
  ATerm sep1;
  ATerm sep2;
  ATermList result;

 if (ATisEmpty(list) || ATgetLength(list) == 1) {
    return arg;
  }

  result = ATmakeList1(ATgetFirst(list));
      list = ATgetNext(list);
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);

  while (!ATisEmpty(list)) {
    result = ATinsert(result, sep2);
    result = ATinsert(result, sep1);
    result = ATinsert(result, sep0);

   head = ATgetFirst(list);
   result = ATinsert(result, head);
    list = ATgetNext(list);

   if (!ATisEmpty(list)) {
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);
   }
  }

  return (PTPT_SymbolList) result;
}
PTPT_SymbolList PTPT_appendSymbolList(PTPT_SymbolList arg0, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_Symbol arg1) {
  return PTPT_concatSymbolList(arg0, wsAfterHead, wsAfterSep, PTPT_makeSymbolListSingle(arg1));
}
PTPT_SymbolList PTPT_concatSymbolList(PTPT_SymbolList arg0, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_SymbolList arg1) {
  if (ATisEmpty((ATermList) arg0)) {
    return arg1;
  }
  arg1 = PTPT_makeSymbolListMany((PTPT_Symbol)ATgetFirst((ATermList) arg0), wsAfterHead, wsAfterSep,  arg1);
  arg1 = (PTPT_SymbolList) ATgetNext((ATermList) arg1);
  return (PTPT_SymbolList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
PTPT_SymbolList PTPT_sliceSymbolList(PTPT_SymbolList arg, int start, int end) {
  return (PTPT_SymbolList) ATgetSlice((ATermList) arg, start * 4, end * 4);
}
PTPT_Symbol PTPT_getSymbolListSymbolAt(PTPT_SymbolList arg, int index) {
 return (PTPT_Symbol)ATelementAt((ATermList) arg,index * 4);
}
PTPT_SymbolList PTPT_replaceSymbolListSymbolAt(PTPT_SymbolList arg, PTPT_Symbol elem, int index) {
 return (PTPT_SymbolList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index * 4);
}
PTPT_SymbolList PTPT_makeSymbolList2(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_Symbol elem1, PTPT_Symbol elem2) {
  return PTPT_makeSymbolListMany(elem1, wsAfterHead, wsAfterSep, PTPT_makeSymbolListSingle(elem2));
}
PTPT_SymbolList PTPT_makeSymbolList3(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_Symbol elem1, PTPT_Symbol elem2, PTPT_Symbol elem3) {
  return PTPT_makeSymbolListMany(elem1, wsAfterHead, wsAfterSep, PTPT_makeSymbolList2(wsAfterHead, wsAfterSep, elem2, elem3));
}
PTPT_SymbolList PTPT_makeSymbolList4(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_Symbol elem1, PTPT_Symbol elem2, PTPT_Symbol elem3, PTPT_Symbol elem4) {
  return PTPT_makeSymbolListMany(elem1, wsAfterHead, wsAfterSep, PTPT_makeSymbolList3(wsAfterHead, wsAfterSep, elem2, elem3, elem4));
}
PTPT_SymbolList PTPT_makeSymbolList5(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_Symbol elem1, PTPT_Symbol elem2, PTPT_Symbol elem3, PTPT_Symbol elem4, PTPT_Symbol elem5) {
  return PTPT_makeSymbolListMany(elem1, wsAfterHead, wsAfterSep, PTPT_makeSymbolList4(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5));
}
PTPT_SymbolList PTPT_makeSymbolList6(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_Symbol elem1, PTPT_Symbol elem2, PTPT_Symbol elem3, PTPT_Symbol elem4, PTPT_Symbol elem5, PTPT_Symbol elem6) {
  return PTPT_makeSymbolListMany(elem1, wsAfterHead, wsAfterSep, PTPT_makeSymbolList5(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5, elem6));
}
int PTPT_getCharRangeListLength (PTPT_CharRangeList arg) {
  if (ATisEmpty((ATermList) arg)) {
    return 0;
  }
  return (ATgetLength((ATermList) arg) / 4) + 1;
}
PTPT_CharRangeList PTPT_reverseCharRangeList(PTPT_CharRangeList arg) {
  ATermList list = (ATermList) arg;
  ATerm head;
  ATerm sep0;
  ATerm sep1;
  ATerm sep2;
  ATermList result;

 if (ATisEmpty(list) || ATgetLength(list) == 1) {
    return arg;
  }

  result = ATmakeList1(ATgetFirst(list));
      list = ATgetNext(list);
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);

  while (!ATisEmpty(list)) {
    result = ATinsert(result, sep2);
    result = ATinsert(result, sep1);
    result = ATinsert(result, sep0);

   head = ATgetFirst(list);
   result = ATinsert(result, head);
    list = ATgetNext(list);

   if (!ATisEmpty(list)) {
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);
   }
  }

  return (PTPT_CharRangeList) result;
}
PTPT_CharRangeList PTPT_appendCharRangeList(PTPT_CharRangeList arg0, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_CharRange arg1) {
  return PTPT_concatCharRangeList(arg0, wsAfterHead, wsAfterSep, PTPT_makeCharRangeListSingle(arg1));
}
PTPT_CharRangeList PTPT_concatCharRangeList(PTPT_CharRangeList arg0, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_CharRangeList arg1) {
  if (ATisEmpty((ATermList) arg0)) {
    return arg1;
  }
  arg1 = PTPT_makeCharRangeListMany((PTPT_CharRange)ATgetFirst((ATermList) arg0), wsAfterHead, wsAfterSep,  arg1);
  arg1 = (PTPT_CharRangeList) ATgetNext((ATermList) arg1);
  return (PTPT_CharRangeList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
PTPT_CharRangeList PTPT_sliceCharRangeList(PTPT_CharRangeList arg, int start, int end) {
  return (PTPT_CharRangeList) ATgetSlice((ATermList) arg, start * 4, end * 4);
}
PTPT_CharRange PTPT_getCharRangeListCharRangeAt(PTPT_CharRangeList arg, int index) {
 return (PTPT_CharRange)ATelementAt((ATermList) arg,index * 4);
}
PTPT_CharRangeList PTPT_replaceCharRangeListCharRangeAt(PTPT_CharRangeList arg, PTPT_CharRange elem, int index) {
 return (PTPT_CharRangeList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index * 4);
}
PTPT_CharRangeList PTPT_makeCharRangeList2(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_CharRange elem1, PTPT_CharRange elem2) {
  return PTPT_makeCharRangeListMany(elem1, wsAfterHead, wsAfterSep, PTPT_makeCharRangeListSingle(elem2));
}
PTPT_CharRangeList PTPT_makeCharRangeList3(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_CharRange elem1, PTPT_CharRange elem2, PTPT_CharRange elem3) {
  return PTPT_makeCharRangeListMany(elem1, wsAfterHead, wsAfterSep, PTPT_makeCharRangeList2(wsAfterHead, wsAfterSep, elem2, elem3));
}
PTPT_CharRangeList PTPT_makeCharRangeList4(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_CharRange elem1, PTPT_CharRange elem2, PTPT_CharRange elem3, PTPT_CharRange elem4) {
  return PTPT_makeCharRangeListMany(elem1, wsAfterHead, wsAfterSep, PTPT_makeCharRangeList3(wsAfterHead, wsAfterSep, elem2, elem3, elem4));
}
PTPT_CharRangeList PTPT_makeCharRangeList5(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_CharRange elem1, PTPT_CharRange elem2, PTPT_CharRange elem3, PTPT_CharRange elem4, PTPT_CharRange elem5) {
  return PTPT_makeCharRangeListMany(elem1, wsAfterHead, wsAfterSep, PTPT_makeCharRangeList4(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5));
}
PTPT_CharRangeList PTPT_makeCharRangeList6(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_CharRange elem1, PTPT_CharRange elem2, PTPT_CharRange elem3, PTPT_CharRange elem4, PTPT_CharRange elem5, PTPT_CharRange elem6) {
  return PTPT_makeCharRangeListMany(elem1, wsAfterHead, wsAfterSep, PTPT_makeCharRangeList5(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5, elem6));
}
int PTPT_getTreeListLength (PTPT_TreeList arg) {
  if (ATisEmpty((ATermList) arg)) {
    return 0;
  }
  return (ATgetLength((ATermList) arg) / 4) + 1;
}
PTPT_TreeList PTPT_reverseTreeList(PTPT_TreeList arg) {
  ATermList list = (ATermList) arg;
  ATerm head;
  ATerm sep0;
  ATerm sep1;
  ATerm sep2;
  ATermList result;

 if (ATisEmpty(list) || ATgetLength(list) == 1) {
    return arg;
  }

  result = ATmakeList1(ATgetFirst(list));
      list = ATgetNext(list);
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);

  while (!ATisEmpty(list)) {
    result = ATinsert(result, sep2);
    result = ATinsert(result, sep1);
    result = ATinsert(result, sep0);

   head = ATgetFirst(list);
   result = ATinsert(result, head);
    list = ATgetNext(list);

   if (!ATisEmpty(list)) {
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);
   }
  }

  return (PTPT_TreeList) result;
}
PTPT_TreeList PTPT_appendTreeList(PTPT_TreeList arg0, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_Tree arg1) {
  return PTPT_concatTreeList(arg0, wsAfterHead, wsAfterSep, PTPT_makeTreeListSingle(arg1));
}
PTPT_TreeList PTPT_concatTreeList(PTPT_TreeList arg0, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_TreeList arg1) {
  if (ATisEmpty((ATermList) arg0)) {
    return arg1;
  }
  arg1 = PTPT_makeTreeListMany((PTPT_Tree)ATgetFirst((ATermList) arg0), wsAfterHead, wsAfterSep,  arg1);
  arg1 = (PTPT_TreeList) ATgetNext((ATermList) arg1);
  return (PTPT_TreeList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
PTPT_TreeList PTPT_sliceTreeList(PTPT_TreeList arg, int start, int end) {
  return (PTPT_TreeList) ATgetSlice((ATermList) arg, start * 4, end * 4);
}
PTPT_Tree PTPT_getTreeListTreeAt(PTPT_TreeList arg, int index) {
 return (PTPT_Tree)ATelementAt((ATermList) arg,index * 4);
}
PTPT_TreeList PTPT_replaceTreeListTreeAt(PTPT_TreeList arg, PTPT_Tree elem, int index) {
 return (PTPT_TreeList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index * 4);
}
PTPT_TreeList PTPT_makeTreeList2(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_Tree elem1, PTPT_Tree elem2) {
  return PTPT_makeTreeListMany(elem1, wsAfterHead, wsAfterSep, PTPT_makeTreeListSingle(elem2));
}
PTPT_TreeList PTPT_makeTreeList3(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_Tree elem1, PTPT_Tree elem2, PTPT_Tree elem3) {
  return PTPT_makeTreeListMany(elem1, wsAfterHead, wsAfterSep, PTPT_makeTreeList2(wsAfterHead, wsAfterSep, elem2, elem3));
}
PTPT_TreeList PTPT_makeTreeList4(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_Tree elem1, PTPT_Tree elem2, PTPT_Tree elem3, PTPT_Tree elem4) {
  return PTPT_makeTreeListMany(elem1, wsAfterHead, wsAfterSep, PTPT_makeTreeList3(wsAfterHead, wsAfterSep, elem2, elem3, elem4));
}
PTPT_TreeList PTPT_makeTreeList5(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_Tree elem1, PTPT_Tree elem2, PTPT_Tree elem3, PTPT_Tree elem4, PTPT_Tree elem5) {
  return PTPT_makeTreeListMany(elem1, wsAfterHead, wsAfterSep, PTPT_makeTreeList4(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5));
}
PTPT_TreeList PTPT_makeTreeList6(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_Tree elem1, PTPT_Tree elem2, PTPT_Tree elem3, PTPT_Tree elem4, PTPT_Tree elem5, PTPT_Tree elem6) {
  return PTPT_makeTreeListMany(elem1, wsAfterHead, wsAfterSep, PTPT_makeTreeList5(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5, elem6));
}
int PTPT_getATermArgsLength (PTPT_ATermArgs arg) {
  if (ATisEmpty((ATermList) arg)) {
    return 0;
  }
  return (ATgetLength((ATermList) arg) / 4) + 1;
}
PTPT_ATermArgs PTPT_reverseATermArgs(PTPT_ATermArgs arg) {
  ATermList list = (ATermList) arg;
  ATerm head;
  ATerm sep0;
  ATerm sep1;
  ATerm sep2;
  ATermList result;

 if (ATisEmpty(list) || ATgetLength(list) == 1) {
    return arg;
  }

  result = ATmakeList1(ATgetFirst(list));
      list = ATgetNext(list);
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);

  while (!ATisEmpty(list)) {
    result = ATinsert(result, sep2);
    result = ATinsert(result, sep1);
    result = ATinsert(result, sep0);

   head = ATgetFirst(list);
   result = ATinsert(result, head);
    list = ATgetNext(list);

   if (!ATisEmpty(list)) {
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);
   }
  }

  return (PTPT_ATermArgs) result;
}
PTPT_ATermArgs PTPT_appendATermArgs(PTPT_ATermArgs arg0, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATerm arg1) {
  return PTPT_concatATermArgs(arg0, wsAfterHead, wsAfterSep, PTPT_makeATermArgsSingle(arg1));
}
PTPT_ATermArgs PTPT_concatATermArgs(PTPT_ATermArgs arg0, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATermArgs arg1) {
  if (ATisEmpty((ATermList) arg0)) {
    return arg1;
  }
  arg1 = PTPT_makeATermArgsMany((PTPT_ATerm)ATgetFirst((ATermList) arg0), wsAfterHead, wsAfterSep,  arg1);
  arg1 = (PTPT_ATermArgs) ATgetNext((ATermList) arg1);
  return (PTPT_ATermArgs) ATconcat((ATermList) arg0, (ATermList) arg1);
}
PTPT_ATermArgs PTPT_sliceATermArgs(PTPT_ATermArgs arg, int start, int end) {
  return (PTPT_ATermArgs) ATgetSlice((ATermList) arg, start * 4, end * 4);
}
PTPT_ATerm PTPT_getATermArgsATermAt(PTPT_ATermArgs arg, int index) {
 return (PTPT_ATerm)ATelementAt((ATermList) arg,index * 4);
}
PTPT_ATermArgs PTPT_replaceATermArgsATermAt(PTPT_ATermArgs arg, PTPT_ATerm elem, int index) {
 return (PTPT_ATermArgs) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index * 4);
}
PTPT_ATermArgs PTPT_makeATermArgs2(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATerm elem1, PTPT_ATerm elem2) {
  return PTPT_makeATermArgsMany(elem1, wsAfterHead, wsAfterSep, PTPT_makeATermArgsSingle(elem2));
}
PTPT_ATermArgs PTPT_makeATermArgs3(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATerm elem1, PTPT_ATerm elem2, PTPT_ATerm elem3) {
  return PTPT_makeATermArgsMany(elem1, wsAfterHead, wsAfterSep, PTPT_makeATermArgs2(wsAfterHead, wsAfterSep, elem2, elem3));
}
PTPT_ATermArgs PTPT_makeATermArgs4(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATerm elem1, PTPT_ATerm elem2, PTPT_ATerm elem3, PTPT_ATerm elem4) {
  return PTPT_makeATermArgsMany(elem1, wsAfterHead, wsAfterSep, PTPT_makeATermArgs3(wsAfterHead, wsAfterSep, elem2, elem3, elem4));
}
PTPT_ATermArgs PTPT_makeATermArgs5(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATerm elem1, PTPT_ATerm elem2, PTPT_ATerm elem3, PTPT_ATerm elem4, PTPT_ATerm elem5) {
  return PTPT_makeATermArgsMany(elem1, wsAfterHead, wsAfterSep, PTPT_makeATermArgs4(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5));
}
PTPT_ATermArgs PTPT_makeATermArgs6(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATerm elem1, PTPT_ATerm elem2, PTPT_ATerm elem3, PTPT_ATerm elem4, PTPT_ATerm elem5, PTPT_ATerm elem6) {
  return PTPT_makeATermArgsMany(elem1, wsAfterHead, wsAfterSep, PTPT_makeATermArgs5(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5, elem6));
}
int PTPT_getATermElemsLength (PTPT_ATermElems arg) {
  if (ATisEmpty((ATermList) arg)) {
    return 0;
  }
  return (ATgetLength((ATermList) arg) / 4) + 1;
}
PTPT_ATermElems PTPT_reverseATermElems(PTPT_ATermElems arg) {
  ATermList list = (ATermList) arg;
  ATerm head;
  ATerm sep0;
  ATerm sep1;
  ATerm sep2;
  ATermList result;

 if (ATisEmpty(list) || ATgetLength(list) == 1) {
    return arg;
  }

  result = ATmakeList1(ATgetFirst(list));
      list = ATgetNext(list);
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);

  while (!ATisEmpty(list)) {
    result = ATinsert(result, sep2);
    result = ATinsert(result, sep1);
    result = ATinsert(result, sep0);

   head = ATgetFirst(list);
   result = ATinsert(result, head);
    list = ATgetNext(list);

   if (!ATisEmpty(list)) {
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);
   }
  }

  return (PTPT_ATermElems) result;
}
PTPT_ATermElems PTPT_appendATermElems(PTPT_ATermElems arg0, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATerm arg1) {
  return PTPT_concatATermElems(arg0, wsAfterHead, wsAfterSep, PTPT_makeATermElemsSingle(arg1));
}
PTPT_ATermElems PTPT_concatATermElems(PTPT_ATermElems arg0, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATermElems arg1) {
  if (ATisEmpty((ATermList) arg0)) {
    return arg1;
  }
  arg1 = PTPT_makeATermElemsMany((PTPT_ATerm)ATgetFirst((ATermList) arg0), wsAfterHead, wsAfterSep,  arg1);
  arg1 = (PTPT_ATermElems) ATgetNext((ATermList) arg1);
  return (PTPT_ATermElems) ATconcat((ATermList) arg0, (ATermList) arg1);
}
PTPT_ATermElems PTPT_sliceATermElems(PTPT_ATermElems arg, int start, int end) {
  return (PTPT_ATermElems) ATgetSlice((ATermList) arg, start * 4, end * 4);
}
PTPT_ATerm PTPT_getATermElemsATermAt(PTPT_ATermElems arg, int index) {
 return (PTPT_ATerm)ATelementAt((ATermList) arg,index * 4);
}
PTPT_ATermElems PTPT_replaceATermElemsATermAt(PTPT_ATermElems arg, PTPT_ATerm elem, int index) {
 return (PTPT_ATermElems) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index * 4);
}
PTPT_ATermElems PTPT_makeATermElems2(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATerm elem1, PTPT_ATerm elem2) {
  return PTPT_makeATermElemsMany(elem1, wsAfterHead, wsAfterSep, PTPT_makeATermElemsSingle(elem2));
}
PTPT_ATermElems PTPT_makeATermElems3(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATerm elem1, PTPT_ATerm elem2, PTPT_ATerm elem3) {
  return PTPT_makeATermElemsMany(elem1, wsAfterHead, wsAfterSep, PTPT_makeATermElems2(wsAfterHead, wsAfterSep, elem2, elem3));
}
PTPT_ATermElems PTPT_makeATermElems4(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATerm elem1, PTPT_ATerm elem2, PTPT_ATerm elem3, PTPT_ATerm elem4) {
  return PTPT_makeATermElemsMany(elem1, wsAfterHead, wsAfterSep, PTPT_makeATermElems3(wsAfterHead, wsAfterSep, elem2, elem3, elem4));
}
PTPT_ATermElems PTPT_makeATermElems5(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATerm elem1, PTPT_ATerm elem2, PTPT_ATerm elem3, PTPT_ATerm elem4, PTPT_ATerm elem5) {
  return PTPT_makeATermElemsMany(elem1, wsAfterHead, wsAfterSep, PTPT_makeATermElems4(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5));
}
PTPT_ATermElems PTPT_makeATermElems6(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATerm elem1, PTPT_ATerm elem2, PTPT_ATerm elem3, PTPT_ATerm elem4, PTPT_ATerm elem5, PTPT_ATerm elem6) {
  return PTPT_makeATermElemsMany(elem1, wsAfterHead, wsAfterSep, PTPT_makeATermElems5(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5, elem6));
}
int PTPT_getATermAnnosLength (PTPT_ATermAnnos arg) {
  if (ATisEmpty((ATermList) arg)) {
    return 0;
  }
  return (ATgetLength((ATermList) arg) / 4) + 1;
}
PTPT_ATermAnnos PTPT_reverseATermAnnos(PTPT_ATermAnnos arg) {
  ATermList list = (ATermList) arg;
  ATerm head;
  ATerm sep0;
  ATerm sep1;
  ATerm sep2;
  ATermList result;

 if (ATisEmpty(list) || ATgetLength(list) == 1) {
    return arg;
  }

  result = ATmakeList1(ATgetFirst(list));
      list = ATgetNext(list);
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);

  while (!ATisEmpty(list)) {
    result = ATinsert(result, sep2);
    result = ATinsert(result, sep1);
    result = ATinsert(result, sep0);

   head = ATgetFirst(list);
   result = ATinsert(result, head);
    list = ATgetNext(list);

   if (!ATisEmpty(list)) {
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);
   }
  }

  return (PTPT_ATermAnnos) result;
}
PTPT_ATermAnnos PTPT_appendATermAnnos(PTPT_ATermAnnos arg0, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATerm arg1) {
  return PTPT_concatATermAnnos(arg0, wsAfterHead, wsAfterSep, PTPT_makeATermAnnosSingle(arg1));
}
PTPT_ATermAnnos PTPT_concatATermAnnos(PTPT_ATermAnnos arg0, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATermAnnos arg1) {
  if (ATisEmpty((ATermList) arg0)) {
    return arg1;
  }
  arg1 = PTPT_makeATermAnnosMany((PTPT_ATerm)ATgetFirst((ATermList) arg0), wsAfterHead, wsAfterSep,  arg1);
  arg1 = (PTPT_ATermAnnos) ATgetNext((ATermList) arg1);
  return (PTPT_ATermAnnos) ATconcat((ATermList) arg0, (ATermList) arg1);
}
PTPT_ATermAnnos PTPT_sliceATermAnnos(PTPT_ATermAnnos arg, int start, int end) {
  return (PTPT_ATermAnnos) ATgetSlice((ATermList) arg, start * 4, end * 4);
}
PTPT_ATerm PTPT_getATermAnnosATermAt(PTPT_ATermAnnos arg, int index) {
 return (PTPT_ATerm)ATelementAt((ATermList) arg,index * 4);
}
PTPT_ATermAnnos PTPT_replaceATermAnnosATermAt(PTPT_ATermAnnos arg, PTPT_ATerm elem, int index) {
 return (PTPT_ATermAnnos) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index * 4);
}
PTPT_ATermAnnos PTPT_makeATermAnnos2(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATerm elem1, PTPT_ATerm elem2) {
  return PTPT_makeATermAnnosMany(elem1, wsAfterHead, wsAfterSep, PTPT_makeATermAnnosSingle(elem2));
}
PTPT_ATermAnnos PTPT_makeATermAnnos3(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATerm elem1, PTPT_ATerm elem2, PTPT_ATerm elem3) {
  return PTPT_makeATermAnnosMany(elem1, wsAfterHead, wsAfterSep, PTPT_makeATermAnnos2(wsAfterHead, wsAfterSep, elem2, elem3));
}
PTPT_ATermAnnos PTPT_makeATermAnnos4(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATerm elem1, PTPT_ATerm elem2, PTPT_ATerm elem3, PTPT_ATerm elem4) {
  return PTPT_makeATermAnnosMany(elem1, wsAfterHead, wsAfterSep, PTPT_makeATermAnnos3(wsAfterHead, wsAfterSep, elem2, elem3, elem4));
}
PTPT_ATermAnnos PTPT_makeATermAnnos5(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATerm elem1, PTPT_ATerm elem2, PTPT_ATerm elem3, PTPT_ATerm elem4, PTPT_ATerm elem5) {
  return PTPT_makeATermAnnosMany(elem1, wsAfterHead, wsAfterSep, PTPT_makeATermAnnos4(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5));
}
PTPT_ATermAnnos PTPT_makeATermAnnos6(PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATerm elem1, PTPT_ATerm elem2, PTPT_ATerm elem3, PTPT_ATerm elem4, PTPT_ATerm elem5, PTPT_ATerm elem6) {
  return PTPT_makeATermAnnosMany(elem1, wsAfterHead, wsAfterSep, PTPT_makeATermAnnos5(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5, elem6));
}
int PTPT_getLexStrCharCharsLength (PTPT_LexStrCharChars arg) {
  return ATgetLength((ATermList) arg);
}
PTPT_LexStrCharChars PTPT_reverseLexStrCharChars(PTPT_LexStrCharChars arg) {
  return (PTPT_LexStrCharChars) ATreverse((ATermList) arg);
}
PTPT_LexStrCharChars PTPT_appendLexStrCharChars(PTPT_LexStrCharChars arg, PTPT_LexStrChar elem) {
  return (PTPT_LexStrCharChars) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}
PTPT_LexStrCharChars PTPT_concatLexStrCharChars(PTPT_LexStrCharChars arg0, PTPT_LexStrCharChars arg1) {
  return (PTPT_LexStrCharChars) ATconcat((ATermList) arg0, (ATermList) arg1);
}
PTPT_LexStrCharChars PTPT_sliceLexStrCharChars(PTPT_LexStrCharChars arg, int start, int end) {
  return (PTPT_LexStrCharChars) ATgetSlice((ATermList) arg, start, end);
}
PTPT_LexStrChar PTPT_getLexStrCharCharsLexStrCharAt(PTPT_LexStrCharChars arg, int index) {
 return (PTPT_LexStrChar)ATelementAt((ATermList) arg,index);
}
PTPT_LexStrCharChars PTPT_replaceLexStrCharCharsLexStrCharAt(PTPT_LexStrCharChars arg, PTPT_LexStrChar elem, int index) {
 return (PTPT_LexStrCharChars) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}
PTPT_LexStrCharChars PTPT_makeLexStrCharChars2(PTPT_LexStrChar elem1, PTPT_LexStrChar elem2) {
  return (PTPT_LexStrCharChars) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}
PTPT_LexStrCharChars PTPT_makeLexStrCharChars3(PTPT_LexStrChar elem1, PTPT_LexStrChar elem2, PTPT_LexStrChar elem3) {
  return (PTPT_LexStrCharChars) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}
PTPT_LexStrCharChars PTPT_makeLexStrCharChars4(PTPT_LexStrChar elem1, PTPT_LexStrChar elem2, PTPT_LexStrChar elem3, PTPT_LexStrChar elem4) {
  return (PTPT_LexStrCharChars) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}
PTPT_LexStrCharChars PTPT_makeLexStrCharChars5(PTPT_LexStrChar elem1, PTPT_LexStrChar elem2, PTPT_LexStrChar elem3, PTPT_LexStrChar elem4, PTPT_LexStrChar elem5) {
  return (PTPT_LexStrCharChars) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}
PTPT_LexStrCharChars PTPT_makeLexStrCharChars6(PTPT_LexStrChar elem1, PTPT_LexStrChar elem2, PTPT_LexStrChar elem3, PTPT_LexStrChar elem4, PTPT_LexStrChar elem5, PTPT_LexStrChar elem6) {
  return (PTPT_LexStrCharChars) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}

/*}}}  */
/*{{{  constructors */

/*{{{  PTPT_OptLayout PTPT_makeOptLayoutAbsent(void) */

PTPT_OptLayout PTPT_makeOptLayoutAbsent(void)
{
  return (PTPT_OptLayout)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATempty, (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4))), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATempty);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_makeOptLayoutPresent(PTPT_Layout layout) */

PTPT_OptLayout PTPT_makeOptLayoutPresent(PTPT_Layout layout)
{
  return (PTPT_OptLayout)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl0(PTPT_afun4))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4))), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm) layout));
}

/*}}}  */
/*{{{  PTPT_Layout PTPT_makeLayoutLexToCf(PTPT_LexLayoutList list) */

PTPT_Layout PTPT_makeLayoutLexToCf(PTPT_LexLayoutList list)
{
  return (PTPT_Layout)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun6, (ATerm)ATmakeAppl1(PTPT_afun7, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl0(PTPT_afun4)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl1(PTPT_afun8, (ATerm)ATmakeAppl1(PTPT_afun6, (ATerm)ATmakeAppl1(PTPT_afun7, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm) list)));
}

/*}}}  */
/*{{{  PTPT_LexLayoutList PTPT_makeLexLayoutListEmpty(void) */

PTPT_LexLayoutList PTPT_makeLexLayoutListEmpty(void)
{
  return (PTPT_LexLayoutList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  PTPT_LexLayoutList PTPT_makeLexLayoutListSingle(PTPT_LexLayout head) */

PTPT_LexLayoutList PTPT_makeLexLayoutListSingle(PTPT_LexLayout head)
{
  return (PTPT_LexLayoutList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  PTPT_LexLayoutList PTPT_makeLexLayoutListMany(PTPT_LexLayout head, PTPT_LexLayoutList tail) */

PTPT_LexLayoutList PTPT_makeLexLayoutListMany(PTPT_LexLayout head, PTPT_LexLayoutList tail)
{
  return (PTPT_LexLayoutList)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/*}}}  */
/*{{{  PTPT_Tree PTPT_makeTreeAnnotated(PTPT_Tree Tree, PTPT_OptLayout wsAfterTree, PTPT_Annotation Annotation) */

PTPT_Tree PTPT_makeTreeAnnotated(PTPT_Tree Tree, PTPT_OptLayout wsAfterTree, PTPT_Annotation Annotation)
{
  return (PTPT_Tree)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun10)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun11)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun11))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun15)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) Annotation), (ATerm) wsAfterTree), (ATerm) Tree));
}

/*}}}  */
/*{{{  PTPT_Tree PTPT_makeTreeAppl(PTPT_OptLayout wsAfterAppl, PTPT_OptLayout wsAfterParenOpen, PTPT_Production prod, PTPT_OptLayout wsAfterProd, PTPT_OptLayout wsAfterComma, PTPT_Args args, PTPT_OptLayout wsAfterArgs) */

PTPT_Tree PTPT_makeTreeAppl(PTPT_OptLayout wsAfterAppl, PTPT_OptLayout wsAfterParenOpen, PTPT_Production prod, PTPT_OptLayout wsAfterProd, PTPT_OptLayout wsAfterComma, PTPT_Args args, PTPT_OptLayout wsAfterArgs)
{
  return (PTPT_Tree)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun18)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun20)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun22))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun11))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun22)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterArgs), (ATerm) args), (ATerm) wsAfterComma), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterProd), (ATerm) prod), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterAppl), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(112)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(112)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun22)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(108)), (ATerm)ATmakeInt(112)), (ATerm)ATmakeInt(112)), (ATerm)ATmakeInt(97)))));
}

/*}}}  */
/*{{{  PTPT_Tree PTPT_makeTreeCycle(PTPT_OptLayout wsAfterCycle, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol, PTPT_OptLayout wsAfterComma, PTPT_NatCon cycleLength, PTPT_OptLayout wsAfterCycleLength) */

PTPT_Tree PTPT_makeTreeCycle(PTPT_OptLayout wsAfterCycle, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol, PTPT_OptLayout wsAfterComma, PTPT_NatCon cycleLength, PTPT_OptLayout wsAfterCycleLength)
{
  return (PTPT_Tree)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun24)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun26))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun11))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun26)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterCycleLength), (ATerm) cycleLength), (ATerm) wsAfterComma), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterSymbol), (ATerm) symbol), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterCycle), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(99)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(121)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(99)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun26)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(108)), (ATerm)ATmakeInt(99)), (ATerm)ATmakeInt(121)), (ATerm)ATmakeInt(99)))));
}

/*}}}  */
/*{{{  PTPT_Tree PTPT_makeTreeAmb(PTPT_OptLayout wsAfterAmb, PTPT_OptLayout wsAfterParenOpen, PTPT_Args args, PTPT_OptLayout wsAfterArgs) */

PTPT_Tree PTPT_makeTreeAmb(PTPT_OptLayout wsAfterAmb, PTPT_OptLayout wsAfterParenOpen, PTPT_Args args, PTPT_OptLayout wsAfterArgs)
{
  return (PTPT_Tree)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun18)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun27))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun11))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun27)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterArgs), (ATerm) args), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterAmb), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(98)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(109)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun27)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(98)), (ATerm)ATmakeInt(109)), (ATerm)ATmakeInt(97)))));
}

/*}}}  */
/*{{{  PTPT_Tree PTPT_makeTreeChar(PTPT_NatCon character) */

PTPT_Tree PTPT_makeTreeChar(PTPT_NatCon character)
{
  return (PTPT_Tree)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun24)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun11))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun28)))))), (ATerm)ATmakeList1((ATerm) character));
}

/*}}}  */
/*{{{  PTPT_Attributes PTPT_makeAttributesNoAttrs(void) */

PTPT_Attributes PTPT_makeAttributesNoAttrs(void)
{
  return (PTPT_Attributes)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun29))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun30))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun29)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(45)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(110)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun29)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(115)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(45)), (ATerm)ATmakeInt(111)), (ATerm)ATmakeInt(110)))));
}

/*}}}  */
/*{{{  PTPT_Attributes PTPT_makeAttributesAttrs(PTPT_OptLayout wsAfterAttrs, PTPT_OptLayout wsAfterParenOpen, PTPT_Attrs attributes, PTPT_OptLayout wsAfterAttributes) */

PTPT_Attributes PTPT_makeAttributesAttrs(PTPT_OptLayout wsAfterAttrs, PTPT_OptLayout wsAfterParenOpen, PTPT_Attrs attributes, PTPT_OptLayout wsAfterAttributes)
{
  return (PTPT_Attributes)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun31)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun32))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun30))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun32)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterAttributes), (ATerm) attributes), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterAttrs), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun32)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(115)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(97)))));
}

/*}}}  */
/*{{{  PTPT_Attrs PTPT_makeAttrsMany(PTPT_OptLayout wsAfterBracketOpen, PTPT_AttrList list, PTPT_OptLayout wsAfterList) */

PTPT_Attrs PTPT_makeAttrsMany(PTPT_OptLayout wsAfterBracketOpen, PTPT_AttrList list, PTPT_OptLayout wsAfterList)
{
  return (PTPT_Attrs)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun33))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl2(PTPT_afun34, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun35)), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19))))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun36))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun31))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun37)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun33)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl1(PTPT_afun8, (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl2(PTPT_afun34, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun35)), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19))))), (ATerm) list)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun36)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))));
}

/*}}}  */
/*{{{  PTPT_Attr PTPT_makeAttrAssoc(PTPT_OptLayout wsAfterAssoc, PTPT_OptLayout wsAfterParenOpen, PTPT_Associativity associativity, PTPT_OptLayout wsAfterAssociativity) */

PTPT_Attr PTPT_makeAttrAssoc(PTPT_OptLayout wsAfterAssoc, PTPT_OptLayout wsAfterParenOpen, PTPT_Associativity associativity, PTPT_OptLayout wsAfterAssociativity)
{
  return (PTPT_Attr)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun38)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun39))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun35))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun39)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterAssociativity), (ATerm) associativity), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterAssoc), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(99)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun39)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(99)), (ATerm)ATmakeInt(111)), (ATerm)ATmakeInt(115)), (ATerm)ATmakeInt(115)), (ATerm)ATmakeInt(97)))));
}

/*}}}  */
/*{{{  PTPT_Attr PTPT_makeAttrTerm(PTPT_OptLayout wsAfterTerm, PTPT_OptLayout wsAfterParenOpen, PTPT_ATerm aterm, PTPT_OptLayout wsAfterAterm) */

PTPT_Attr PTPT_makeAttrTerm(PTPT_OptLayout wsAfterTerm, PTPT_OptLayout wsAfterParenOpen, PTPT_ATerm aterm, PTPT_OptLayout wsAfterAterm)
{
  return (PTPT_Attr)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun40)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun41))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun35))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun41)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterAterm), (ATerm) aterm), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterTerm), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(109)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun41)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(109)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(116)))));
}

/*}}}  */
/*{{{  PTPT_Attr PTPT_makeAttrId(PTPT_OptLayout wsAfterId, PTPT_OptLayout wsAfterParenOpen, PTPT_StrCon moduleName, PTPT_OptLayout wsAfterModuleName) */

PTPT_Attr PTPT_makeAttrId(PTPT_OptLayout wsAfterId, PTPT_OptLayout wsAfterParenOpen, PTPT_StrCon moduleName, PTPT_OptLayout wsAfterModuleName)
{
  return (PTPT_Attr)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun42)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun43))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun35))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun43)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterModuleName), (ATerm) moduleName), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterId), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(100)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun43)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(100)), (ATerm)ATmakeInt(105)))));
}

/*}}}  */
/*{{{  PTPT_Attr PTPT_makeAttrBracket(void) */

PTPT_Attr PTPT_makeAttrBracket(void)
{
  return (PTPT_Attr)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun44))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun35))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun44)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(107)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(99)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(98)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun44)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(107)), (ATerm)ATmakeInt(99)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(98)))));
}

/*}}}  */
/*{{{  PTPT_Attr PTPT_makeAttrReject(void) */

PTPT_Attr PTPT_makeAttrReject(void)
{
  return (PTPT_Attr)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun45))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun35))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun45)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(99)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(106)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun45)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(99)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(106)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(114)))));
}

/*}}}  */
/*{{{  PTPT_Attr PTPT_makeAttrPrefer(void) */

PTPT_Attr PTPT_makeAttrPrefer(void)
{
  return (PTPT_Attr)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun46))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun35))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun46)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(102)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(112)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun46)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(102)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(112)))));
}

/*}}}  */
/*{{{  PTPT_Attr PTPT_makeAttrAvoid(void) */

PTPT_Attr PTPT_makeAttrAvoid(void)
{
  return (PTPT_Attr)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun47))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun35))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun47)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(100)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(118)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun47)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(100)), (ATerm)ATmakeInt(105)), (ATerm)ATmakeInt(111)), (ATerm)ATmakeInt(118)), (ATerm)ATmakeInt(97)))));
}

/*}}}  */
/*{{{  PTPT_Associativity PTPT_makeAssociativityLeft(void) */

PTPT_Associativity PTPT_makeAssociativityLeft(void)
{
  return (PTPT_Associativity)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun48))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun38))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun48)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(102)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun48)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(102)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(108)))));
}

/*}}}  */
/*{{{  PTPT_Associativity PTPT_makeAssociativityRight(void) */

PTPT_Associativity PTPT_makeAssociativityRight(void)
{
  return (PTPT_Associativity)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun49))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun38))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun49)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(104)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(103)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun49)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(104)), (ATerm)ATmakeInt(103)), (ATerm)ATmakeInt(105)), (ATerm)ATmakeInt(114)))));
}

/*}}}  */
/*{{{  PTPT_Associativity PTPT_makeAssociativityAssoc(void) */

PTPT_Associativity PTPT_makeAssociativityAssoc(void)
{
  return (PTPT_Associativity)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun39))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun38))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun39)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(99)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun39)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(99)), (ATerm)ATmakeInt(111)), (ATerm)ATmakeInt(115)), (ATerm)ATmakeInt(115)), (ATerm)ATmakeInt(97)))));
}

/*}}}  */
/*{{{  PTPT_Associativity PTPT_makeAssociativityNonAssoc(void) */

PTPT_Associativity PTPT_makeAssociativityNonAssoc(void)
{
  return (PTPT_Associativity)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun50))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun38))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun50)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(99)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(45)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(110)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(110)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun50)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(99)), (ATerm)ATmakeInt(111)), (ATerm)ATmakeInt(115)), (ATerm)ATmakeInt(115)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(45)), (ATerm)ATmakeInt(110)), (ATerm)ATmakeInt(111)), (ATerm)ATmakeInt(110)))));
}

/*}}}  */
/*{{{  PTPT_AttrList PTPT_makeAttrListEmpty(void) */

PTPT_AttrList PTPT_makeAttrListEmpty(void)
{
  return (PTPT_AttrList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  PTPT_AttrList PTPT_makeAttrListSingle(PTPT_Attr head) */

PTPT_AttrList PTPT_makeAttrListSingle(PTPT_Attr head)
{
  return (PTPT_AttrList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  PTPT_AttrList PTPT_makeAttrListMany(PTPT_Attr head, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_AttrList tail) */

PTPT_AttrList PTPT_makeAttrListMany(PTPT_Attr head, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_AttrList tail)
{
  if (PTPT_isAttrListEmpty(tail)) {
    return PTPT_makeAttrListSingle(head);
  }
  return (PTPT_AttrList)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm) wsAfterSep), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterHead), (ATerm) head);
}

/*}}}  */
/*{{{  PTPT_ParseTree PTPT_makeParseTreeTop(PTPT_OptLayout wsAfterParsetree, PTPT_OptLayout wsAfterParenOpen, PTPT_Tree top, PTPT_OptLayout wsAfterTop, PTPT_OptLayout wsAfterComma, PTPT_NatCon ambCnt, PTPT_OptLayout wsAfterAmbCnt) */

PTPT_ParseTree PTPT_makeParseTreeTop(PTPT_OptLayout wsAfterParsetree, PTPT_OptLayout wsAfterParenOpen, PTPT_Tree top, PTPT_OptLayout wsAfterTop, PTPT_OptLayout wsAfterComma, PTPT_NatCon ambCnt, PTPT_OptLayout wsAfterAmbCnt)
{
  return (PTPT_ParseTree)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun24)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun11)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun51))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun52))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun53)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterAmbCnt), (ATerm) ambCnt), (ATerm) wsAfterComma), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterTop), (ATerm) top), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterParsetree), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(112)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun51)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(115)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(112)))));
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_makeSymbolEmpty(void) */

PTPT_Symbol PTPT_makeSymbolEmpty(void)
{
  return (PTPT_Symbol)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun54))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun54)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(121)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(112)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(109)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun54)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(121)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(112)), (ATerm)ATmakeInt(109)), (ATerm)ATmakeInt(101)))));
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_makeSymbolLit(PTPT_OptLayout wsAfterLit, PTPT_OptLayout wsAfterParenOpen, PTPT_StrCon string, PTPT_OptLayout wsAfterString) */

PTPT_Symbol PTPT_makeSymbolLit(PTPT_OptLayout wsAfterLit, PTPT_OptLayout wsAfterParenOpen, PTPT_StrCon string, PTPT_OptLayout wsAfterString)
{
  return (PTPT_Symbol)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun42)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun55))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun55)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterString), (ATerm) string), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterLit), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun55)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(105)), (ATerm)ATmakeInt(108)))));
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_makeSymbolCilit(PTPT_OptLayout wsAfterCilit, PTPT_OptLayout wsAfterParenOpen, PTPT_StrCon string, PTPT_OptLayout wsAfterString) */

PTPT_Symbol PTPT_makeSymbolCilit(PTPT_OptLayout wsAfterCilit, PTPT_OptLayout wsAfterParenOpen, PTPT_StrCon string, PTPT_OptLayout wsAfterString)
{
  return (PTPT_Symbol)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun42)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun56))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun56)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterString), (ATerm) string), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterCilit), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(99)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun56)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(105)), (ATerm)ATmakeInt(108)), (ATerm)ATmakeInt(105)), (ATerm)ATmakeInt(99)))));
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_makeSymbolCf(PTPT_OptLayout wsAfterCf, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol) */

PTPT_Symbol PTPT_makeSymbolCf(PTPT_OptLayout wsAfterCf, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol)
{
  return (PTPT_Symbol)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun57))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun57)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterSymbol), (ATerm) symbol), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterCf), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(102)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(99)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun57)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(102)), (ATerm)ATmakeInt(99)))));
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_makeSymbolLex(PTPT_OptLayout wsAfterLex, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol) */

PTPT_Symbol PTPT_makeSymbolLex(PTPT_OptLayout wsAfterLex, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol)
{
  return (PTPT_Symbol)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun58))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun58)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterSymbol), (ATerm) symbol), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterLex), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(120)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun58)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(120)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(108)))));
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_makeSymbolOpt(PTPT_OptLayout wsAfterOpt, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol) */

PTPT_Symbol PTPT_makeSymbolOpt(PTPT_OptLayout wsAfterOpt, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol)
{
  return (PTPT_Symbol)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun59))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun59)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterSymbol), (ATerm) symbol), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterOpt), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(112)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun59)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(112)), (ATerm)ATmakeInt(111)))));
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_makeSymbolAlt(PTPT_OptLayout wsAfterAlt, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol lhs, PTPT_OptLayout wsAfterLhs, PTPT_OptLayout wsAfterComma, PTPT_Symbol rhs, PTPT_OptLayout wsAfterRhs) */

PTPT_Symbol PTPT_makeSymbolAlt(PTPT_OptLayout wsAfterAlt, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol lhs, PTPT_OptLayout wsAfterLhs, PTPT_OptLayout wsAfterComma, PTPT_Symbol rhs, PTPT_OptLayout wsAfterRhs)
{
  return (PTPT_Symbol)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun60))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun60)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterRhs), (ATerm) rhs), (ATerm) wsAfterComma), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterLhs), (ATerm) lhs), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterAlt), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun60)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(108)), (ATerm)ATmakeInt(97)))));
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_makeSymbolSeq(PTPT_OptLayout wsAfterSeq, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbols symbols, PTPT_OptLayout wsAfterSymbols) */

PTPT_Symbol PTPT_makeSymbolSeq(PTPT_OptLayout wsAfterSeq, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbols symbols, PTPT_OptLayout wsAfterSymbols)
{
  return (PTPT_Symbol)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun61)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun62))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun62)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterSymbols), (ATerm) symbols), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterSeq), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(113)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun62)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(113)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(115)))));
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_makeSymbolTuple(PTPT_OptLayout wsAfterTuple, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol head, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterComma, PTPT_Symbols rest, PTPT_OptLayout wsAfterRest) */

PTPT_Symbol PTPT_makeSymbolTuple(PTPT_OptLayout wsAfterTuple, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol head, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterComma, PTPT_Symbols rest, PTPT_OptLayout wsAfterRest)
{
  return (PTPT_Symbol)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun61)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun63))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun63)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterRest), (ATerm) rest), (ATerm) wsAfterComma), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterHead), (ATerm) head), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterTuple), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(112)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(117)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun63)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(108)), (ATerm)ATmakeInt(112)), (ATerm)ATmakeInt(117)), (ATerm)ATmakeInt(116)))));
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_makeSymbolSort(PTPT_OptLayout wsAfterSort, PTPT_OptLayout wsAfterParenOpen, PTPT_StrCon string, PTPT_OptLayout wsAfterString) */

PTPT_Symbol PTPT_makeSymbolSort(PTPT_OptLayout wsAfterSort, PTPT_OptLayout wsAfterParenOpen, PTPT_StrCon string, PTPT_OptLayout wsAfterString)
{
  return (PTPT_Symbol)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun42)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun64))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun64)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterString), (ATerm) string), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterSort), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun64)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(111)), (ATerm)ATmakeInt(115)))));
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_makeSymbolIter(PTPT_OptLayout wsAfterIter, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol) */

PTPT_Symbol PTPT_makeSymbolIter(PTPT_OptLayout wsAfterIter, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol)
{
  return (PTPT_Symbol)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun65))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun65)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterSymbol), (ATerm) symbol), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterIter), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun65)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(105)))));
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_makeSymbolIterStar(PTPT_OptLayout wsAfterIterStar, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol) */

PTPT_Symbol PTPT_makeSymbolIterStar(PTPT_OptLayout wsAfterIterStar, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol)
{
  return (PTPT_Symbol)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun66))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun66)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterSymbol), (ATerm) symbol), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterIterStar), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(45)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun66)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(115)), (ATerm)ATmakeInt(45)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(105)))));
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_makeSymbolIterSep(PTPT_OptLayout wsAfterIterSep, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol, PTPT_OptLayout wsAfterComma, PTPT_Symbol separator, PTPT_OptLayout wsAfterSeparator) */

PTPT_Symbol PTPT_makeSymbolIterSep(PTPT_OptLayout wsAfterIterSep, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol, PTPT_OptLayout wsAfterComma, PTPT_Symbol separator, PTPT_OptLayout wsAfterSeparator)
{
  return (PTPT_Symbol)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun67))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun67)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterSeparator), (ATerm) separator), (ATerm) wsAfterComma), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterSymbol), (ATerm) symbol), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterIterSep), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(112)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(45)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun67)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(112)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(115)), (ATerm)ATmakeInt(45)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(105)))));
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_makeSymbolIterStarSep(PTPT_OptLayout wsAfterIterStarSep, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol, PTPT_OptLayout wsAfterComma, PTPT_Symbol separator, PTPT_OptLayout wsAfterSeparator) */

PTPT_Symbol PTPT_makeSymbolIterStarSep(PTPT_OptLayout wsAfterIterStarSep, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol, PTPT_OptLayout wsAfterComma, PTPT_Symbol separator, PTPT_OptLayout wsAfterSeparator)
{
  return (PTPT_Symbol)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun68))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun68)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterSeparator), (ATerm) separator), (ATerm) wsAfterComma), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterSymbol), (ATerm) symbol), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterIterStarSep), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(112)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(45)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(45)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun68)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(112)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(115)), (ATerm)ATmakeInt(45)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(115)), (ATerm)ATmakeInt(45)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(105)))));
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_makeSymbolIterN(PTPT_OptLayout wsAfterIterN, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol, PTPT_OptLayout wsAfterComma, PTPT_NatCon number, PTPT_OptLayout wsAfterNumber) */

PTPT_Symbol PTPT_makeSymbolIterN(PTPT_OptLayout wsAfterIterN, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol, PTPT_OptLayout wsAfterComma, PTPT_NatCon number, PTPT_OptLayout wsAfterNumber)
{
  return (PTPT_Symbol)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun24)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun69))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun69)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterNumber), (ATerm) number), (ATerm) wsAfterComma), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterSymbol), (ATerm) symbol), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterIterN), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(110)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(45)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun69)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(110)), (ATerm)ATmakeInt(45)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(105)))));
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_makeSymbolIterSepN(PTPT_OptLayout wsAfterIterSepN, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol, PTPT_OptLayout wsAfterComma1, PTPT_Symbol separator, PTPT_OptLayout wsAfterSeparator, PTPT_OptLayout wsAfterComma2, PTPT_NatCon number, PTPT_OptLayout wsAfterNumber) */

PTPT_Symbol PTPT_makeSymbolIterSepN(PTPT_OptLayout wsAfterIterSepN, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol, PTPT_OptLayout wsAfterComma1, PTPT_Symbol separator, PTPT_OptLayout wsAfterSeparator, PTPT_OptLayout wsAfterComma2, PTPT_NatCon number, PTPT_OptLayout wsAfterNumber)
{
  return (PTPT_Symbol)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun24)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun70))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun70)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterNumber), (ATerm) number), (ATerm) wsAfterComma2), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterSeparator), (ATerm) separator), (ATerm) wsAfterComma1), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterSymbol), (ATerm) symbol), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterIterSepN), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(110)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(45)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(112)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(45)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun70)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(110)), (ATerm)ATmakeInt(45)), (ATerm)ATmakeInt(112)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(115)), (ATerm)ATmakeInt(45)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(105)))));
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_makeSymbolFunc(PTPT_OptLayout wsAfterFunc, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbols symbols, PTPT_OptLayout wsAfterSymbols, PTPT_OptLayout wsAfterComma, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol) */

PTPT_Symbol PTPT_makeSymbolFunc(PTPT_OptLayout wsAfterFunc, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbols symbols, PTPT_OptLayout wsAfterSymbols, PTPT_OptLayout wsAfterComma, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol)
{
  return (PTPT_Symbol)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun61)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun71))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun71)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterSymbol), (ATerm) symbol), (ATerm) wsAfterComma), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterSymbols), (ATerm) symbols), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterFunc), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(99)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(110)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(117)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(102)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun71)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(99)), (ATerm)ATmakeInt(110)), (ATerm)ATmakeInt(117)), (ATerm)ATmakeInt(102)))));
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_makeSymbolVarsym(PTPT_OptLayout wsAfterVarsym, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol) */

PTPT_Symbol PTPT_makeSymbolVarsym(PTPT_OptLayout wsAfterVarsym, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol symbol, PTPT_OptLayout wsAfterSymbol)
{
  return (PTPT_Symbol)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun72))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun72)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterSymbol), (ATerm) symbol), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterVarsym), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(109)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(121)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(118)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun72)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(109)), (ATerm)ATmakeInt(121)), (ATerm)ATmakeInt(115)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(118)))));
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_makeSymbolLayout(void) */

PTPT_Symbol PTPT_makeSymbolLayout(void)
{
  return (PTPT_Symbol)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun73))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun73)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(117)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(121)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun73)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(117)), (ATerm)ATmakeInt(111)), (ATerm)ATmakeInt(121)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(108)))));
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_makeSymbolCharClass(PTPT_OptLayout wsAfterCharClass, PTPT_OptLayout wsAfterParenOpen, PTPT_CharRanges CharRanges, PTPT_OptLayout wsAfterCharRanges) */

PTPT_Symbol PTPT_makeSymbolCharClass(PTPT_OptLayout wsAfterCharClass, PTPT_OptLayout wsAfterParenOpen, PTPT_CharRanges CharRanges, PTPT_OptLayout wsAfterCharRanges)
{
  return (PTPT_Symbol)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun74)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun75))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun75)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterCharRanges), (ATerm) CharRanges), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterCharClass), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(99)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(45)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(104)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(99)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun75)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(115)), (ATerm)ATmakeInt(115)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(108)), (ATerm)ATmakeInt(99)), (ATerm)ATmakeInt(45)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(104)), (ATerm)ATmakeInt(99)))));
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_makeSymbolStrategy(PTPT_OptLayout wsAfterStrategy, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol lhs, PTPT_OptLayout wsAfterLhs, PTPT_OptLayout wsAfterComma, PTPT_Symbol rhs, PTPT_OptLayout wsAfterRhs) */

PTPT_Symbol PTPT_makeSymbolStrategy(PTPT_OptLayout wsAfterStrategy, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol lhs, PTPT_OptLayout wsAfterLhs, PTPT_OptLayout wsAfterComma, PTPT_Symbol rhs, PTPT_OptLayout wsAfterRhs)
{
  return (PTPT_Symbol)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun76))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun76)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterRhs), (ATerm) rhs), (ATerm) wsAfterComma), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterLhs), (ATerm) lhs), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterStrategy), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(121)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(103)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun76)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(121)), (ATerm)ATmakeInt(103)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(115)))));
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_makeSymbolParameterizedSort(PTPT_OptLayout wsAfterParameterizedSort, PTPT_OptLayout wsAfterParenOpen, PTPT_StrCon sort, PTPT_OptLayout wsAfterSort, PTPT_OptLayout wsAfterComma, PTPT_Symbols parameters, PTPT_OptLayout wsAfterParameters) */

PTPT_Symbol PTPT_makeSymbolParameterizedSort(PTPT_OptLayout wsAfterParameterizedSort, PTPT_OptLayout wsAfterParenOpen, PTPT_StrCon sort, PTPT_OptLayout wsAfterSort, PTPT_OptLayout wsAfterComma, PTPT_Symbols parameters, PTPT_OptLayout wsAfterParameters)
{
  return (PTPT_Symbol)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun61)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun42)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun77))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun77)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterParameters), (ATerm) parameters), (ATerm) wsAfterComma), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterSort), (ATerm) sort), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterParameterizedSort), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(45)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(100)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(122)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(109)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(112)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun77)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(111)), (ATerm)ATmakeInt(115)), (ATerm)ATmakeInt(45)), (ATerm)ATmakeInt(100)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(122)), (ATerm)ATmakeInt(105)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(109)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(112)))));
}

/*}}}  */
/*{{{  PTPT_Symbols PTPT_makeSymbolsList(PTPT_OptLayout wsAfterBracketOpen, PTPT_SymbolList list, PTPT_OptLayout wsAfterList) */

PTPT_Symbols PTPT_makeSymbolsList(PTPT_OptLayout wsAfterBracketOpen, PTPT_SymbolList list, PTPT_OptLayout wsAfterList)
{
  return (PTPT_Symbols)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun33))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl2(PTPT_afun78, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25)), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19))))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun36))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun61))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun79)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun33)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl1(PTPT_afun8, (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl2(PTPT_afun78, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25)), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19))))), (ATerm) list)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun36)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))));
}

/*}}}  */
/*{{{  PTPT_CharRanges PTPT_makeCharRangesList(PTPT_OptLayout wsAfterBracketOpen, PTPT_CharRangeList list, PTPT_OptLayout wsAfterList) */

PTPT_CharRanges PTPT_makeCharRangesList(PTPT_OptLayout wsAfterBracketOpen, PTPT_CharRangeList list, PTPT_OptLayout wsAfterList)
{
  return (PTPT_CharRanges)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun33))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl2(PTPT_afun78, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun80)), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19))))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun36))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun74))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun79)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun33)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl1(PTPT_afun8, (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl2(PTPT_afun78, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun80)), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19))))), (ATerm) list)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun36)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))));
}

/*}}}  */
/*{{{  PTPT_CharRange PTPT_makeCharRangeCharacter(PTPT_NatCon integer) */

PTPT_CharRange PTPT_makeCharRangeCharacter(PTPT_NatCon integer)
{
  return (PTPT_CharRange)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun24)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun80))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun81)))))), (ATerm)ATmakeList1((ATerm) integer));
}

/*}}}  */
/*{{{  PTPT_CharRange PTPT_makeCharRangeRange(PTPT_OptLayout wsAfterRange, PTPT_OptLayout wsAfterParenOpen, PTPT_NatCon start, PTPT_OptLayout wsAfterStart, PTPT_OptLayout wsAfterComma, PTPT_NatCon end, PTPT_OptLayout wsAfterEnd) */

PTPT_CharRange PTPT_makeCharRangeRange(PTPT_OptLayout wsAfterRange, PTPT_OptLayout wsAfterParenOpen, PTPT_NatCon start, PTPT_OptLayout wsAfterStart, PTPT_OptLayout wsAfterComma, PTPT_NatCon end, PTPT_OptLayout wsAfterEnd)
{
  return (PTPT_CharRange)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun24)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun24)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun82))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun80))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun82)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterEnd), (ATerm) end), (ATerm) wsAfterComma), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterStart), (ATerm) start), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterRange), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(103)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(110)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun82)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(103)), (ATerm)ATmakeInt(110)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(114)))));
}

/*}}}  */
/*{{{  PTPT_Start PTPT_makeStartSymbol(PTPT_OptLayout wsBefore, PTPT_Symbol topSymbol, PTPT_OptLayout wsAfter, int ambCnt) */

PTPT_Start PTPT_makeStartSymbol(PTPT_OptLayout wsBefore, PTPT_Symbol topSymbol, PTPT_OptLayout wsAfter, int ambCnt)
{
  return (PTPT_Start)(ATerm)ATmakeAppl2(PTPT_afun83, (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun84)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topSymbol), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  PTPT_Start PTPT_makeStartTree(PTPT_OptLayout wsBefore, PTPT_Tree topTree, PTPT_OptLayout wsAfter, int ambCnt) */

PTPT_Start PTPT_makeStartTree(PTPT_OptLayout wsBefore, PTPT_Tree topTree, PTPT_OptLayout wsAfter, int ambCnt)
{
  return (PTPT_Start)(ATerm)ATmakeAppl2(PTPT_afun83, (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun11))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun84)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topTree), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  PTPT_Start PTPT_makeStartATerm(PTPT_OptLayout wsBefore, PTPT_ATerm topATerm, PTPT_OptLayout wsAfter, int ambCnt) */

PTPT_Start PTPT_makeStartATerm(PTPT_OptLayout wsBefore, PTPT_ATerm topATerm, PTPT_OptLayout wsAfter, int ambCnt)
{
  return (PTPT_Start)(ATerm)ATmakeAppl2(PTPT_afun83, (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun40))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun84)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topATerm), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  PTPT_Start PTPT_makeStartIntCon(PTPT_OptLayout wsBefore, PTPT_IntCon topIntCon, PTPT_OptLayout wsAfter, int ambCnt) */

PTPT_Start PTPT_makeStartIntCon(PTPT_OptLayout wsBefore, PTPT_IntCon topIntCon, PTPT_OptLayout wsAfter, int ambCnt)
{
  return (PTPT_Start)(ATerm)ATmakeAppl2(PTPT_afun83, (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun85))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun84)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topIntCon), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  PTPT_Start PTPT_makeStartRealCon(PTPT_OptLayout wsBefore, PTPT_RealCon topRealCon, PTPT_OptLayout wsAfter, int ambCnt) */

PTPT_Start PTPT_makeStartRealCon(PTPT_OptLayout wsBefore, PTPT_RealCon topRealCon, PTPT_OptLayout wsAfter, int ambCnt)
{
  return (PTPT_Start)(ATerm)ATmakeAppl2(PTPT_afun83, (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun86))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun84)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topRealCon), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  PTPT_SymbolList PTPT_makeSymbolListEmpty(void) */

PTPT_SymbolList PTPT_makeSymbolListEmpty(void)
{
  return (PTPT_SymbolList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  PTPT_SymbolList PTPT_makeSymbolListSingle(PTPT_Symbol head) */

PTPT_SymbolList PTPT_makeSymbolListSingle(PTPT_Symbol head)
{
  return (PTPT_SymbolList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  PTPT_SymbolList PTPT_makeSymbolListMany(PTPT_Symbol head, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_SymbolList tail) */

PTPT_SymbolList PTPT_makeSymbolListMany(PTPT_Symbol head, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_SymbolList tail)
{
  if (PTPT_isSymbolListEmpty(tail)) {
    return PTPT_makeSymbolListSingle(head);
  }
  return (PTPT_SymbolList)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm) wsAfterSep), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterHead), (ATerm) head);
}

/*}}}  */
/*{{{  PTPT_CharRangeList PTPT_makeCharRangeListEmpty(void) */

PTPT_CharRangeList PTPT_makeCharRangeListEmpty(void)
{
  return (PTPT_CharRangeList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  PTPT_CharRangeList PTPT_makeCharRangeListSingle(PTPT_CharRange head) */

PTPT_CharRangeList PTPT_makeCharRangeListSingle(PTPT_CharRange head)
{
  return (PTPT_CharRangeList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  PTPT_CharRangeList PTPT_makeCharRangeListMany(PTPT_CharRange head, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_CharRangeList tail) */

PTPT_CharRangeList PTPT_makeCharRangeListMany(PTPT_CharRange head, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_CharRangeList tail)
{
  if (PTPT_isCharRangeListEmpty(tail)) {
    return PTPT_makeCharRangeListSingle(head);
  }
  return (PTPT_CharRangeList)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm) wsAfterSep), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterHead), (ATerm) head);
}

/*}}}  */
/*{{{  PTPT_Args PTPT_makeArgsList(PTPT_OptLayout wsAfterBracketOpen, PTPT_TreeList list, PTPT_OptLayout wsAfterList) */

PTPT_Args PTPT_makeArgsList(PTPT_OptLayout wsAfterBracketOpen, PTPT_TreeList list, PTPT_OptLayout wsAfterList)
{
  return (PTPT_Args)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun33))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl2(PTPT_afun78, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun11)), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19))))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun36))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun18))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun79)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun33)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl1(PTPT_afun8, (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl2(PTPT_afun78, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun11)), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19))))), (ATerm) list)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun36)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))));
}

/*}}}  */
/*{{{  PTPT_Production PTPT_makeProductionDefault(PTPT_OptLayout wsAfterProd, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbols lhs, PTPT_OptLayout wsAfterLhs, PTPT_OptLayout wsAfterComma1, PTPT_Symbol rhs, PTPT_OptLayout wsAfterRhs, PTPT_OptLayout wsAfterComma2, PTPT_Attributes attributes, PTPT_OptLayout wsAfterAttributes) */

PTPT_Production PTPT_makeProductionDefault(PTPT_OptLayout wsAfterProd, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbols lhs, PTPT_OptLayout wsAfterLhs, PTPT_OptLayout wsAfterComma1, PTPT_Symbol rhs, PTPT_OptLayout wsAfterRhs, PTPT_OptLayout wsAfterComma2, PTPT_Attributes attributes, PTPT_OptLayout wsAfterAttributes)
{
  return (PTPT_Production)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun30)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun61)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun87))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun20))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun88)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterAttributes), (ATerm) attributes), (ATerm) wsAfterComma2), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterRhs), (ATerm) rhs), (ATerm) wsAfterComma1), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterLhs), (ATerm) lhs), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterProd), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(100)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(112)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun87)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(100)), (ATerm)ATmakeInt(111)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(112)))));
}

/*}}}  */
/*{{{  PTPT_Production PTPT_makeProductionList(PTPT_OptLayout wsAfterList, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol rhs, PTPT_OptLayout wsAfterRhs) */

PTPT_Production PTPT_makeProductionList(PTPT_OptLayout wsAfterList, PTPT_OptLayout wsAfterParenOpen, PTPT_Symbol rhs, PTPT_OptLayout wsAfterRhs)
{
  return (PTPT_Production)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun25)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun79))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun20))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun79)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterRhs), (ATerm) rhs), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun79)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(115)), (ATerm)ATmakeInt(105)), (ATerm)ATmakeInt(108)))));
}

/*}}}  */
/*{{{  PTPT_TreeList PTPT_makeTreeListEmpty(void) */

PTPT_TreeList PTPT_makeTreeListEmpty(void)
{
  return (PTPT_TreeList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  PTPT_TreeList PTPT_makeTreeListSingle(PTPT_Tree head) */

PTPT_TreeList PTPT_makeTreeListSingle(PTPT_Tree head)
{
  return (PTPT_TreeList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  PTPT_TreeList PTPT_makeTreeListMany(PTPT_Tree head, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_TreeList tail) */

PTPT_TreeList PTPT_makeTreeListMany(PTPT_Tree head, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_TreeList tail)
{
  if (PTPT_isTreeListEmpty(tail)) {
    return PTPT_makeTreeListSingle(head);
  }
  return (PTPT_TreeList)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm) wsAfterSep), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterHead), (ATerm) head);
}

/*}}}  */
/*{{{  PTPT_AFun PTPT_makeAFunQuoted(PTPT_StrCon StrCon) */

PTPT_AFun PTPT_makeAFunQuoted(PTPT_StrCon StrCon)
{
  return (PTPT_AFun)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun42)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun89))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun90)))))), (ATerm)ATmakeList1((ATerm) StrCon));
}

/*}}}  */
/*{{{  PTPT_AFun PTPT_makeAFunUnquoted(PTPT_IdCon IdCon) */

PTPT_AFun PTPT_makeAFunUnquoted(PTPT_IdCon IdCon)
{
  return (PTPT_AFun)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun91)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun89))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun92)))))), (ATerm)ATmakeList1((ATerm) IdCon));
}

/*}}}  */
/*{{{  PTPT_ATerm PTPT_makeATermInt(PTPT_IntCon IntCon) */

PTPT_ATerm PTPT_makeATermInt(PTPT_IntCon IntCon)
{
  return (PTPT_ATerm)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun85)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun40))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun93)))))), (ATerm)ATmakeList1((ATerm) IntCon));
}

/*}}}  */
/*{{{  PTPT_ATerm PTPT_makeATermReal(PTPT_RealCon RealCon) */

PTPT_ATerm PTPT_makeATermReal(PTPT_RealCon RealCon)
{
  return (PTPT_ATerm)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun86)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun40))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun94)))))), (ATerm)ATmakeList1((ATerm) RealCon));
}

/*}}}  */
/*{{{  PTPT_ATerm PTPT_makeATermFun(PTPT_AFun fun) */

PTPT_ATerm PTPT_makeATermFun(PTPT_AFun fun)
{
  return (PTPT_ATerm)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun89)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun40))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun95)))))), (ATerm)ATmakeList1((ATerm) fun));
}

/*}}}  */
/*{{{  PTPT_ATerm PTPT_makeATermAppl(PTPT_AFun fun, PTPT_OptLayout wsAfterFun, PTPT_OptLayout wsAfterParenOpen, PTPT_ATermArgs args, PTPT_OptLayout wsAfterArgs) */

PTPT_ATerm PTPT_makeATermAppl(PTPT_AFun fun, PTPT_OptLayout wsAfterFun, PTPT_OptLayout wsAfterParenOpen, PTPT_ATermArgs args, PTPT_OptLayout wsAfterArgs)
{
  return (PTPT_ATerm)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl2(PTPT_afun34, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun40)), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19))))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun89)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun40))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun22)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun17)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterArgs), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl1(PTPT_afun8, (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl2(PTPT_afun34, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun40)), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19))))), (ATerm) args)), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun21)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterFun), (ATerm) fun));
}

/*}}}  */
/*{{{  PTPT_ATerm PTPT_makeATermPlaceholder(PTPT_OptLayout wsAfterLessThan, PTPT_ATerm type, PTPT_OptLayout wsAfterType) */

PTPT_ATerm PTPT_makeATermPlaceholder(PTPT_OptLayout wsAfterLessThan, PTPT_ATerm type, PTPT_OptLayout wsAfterType)
{
  return (PTPT_ATerm)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun96))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun40)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun97))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun40))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun98)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(62)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun96)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(62)))), (ATerm) wsAfterType), (ATerm) type), (ATerm) wsAfterLessThan), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(60)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun97)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(60)))));
}

/*}}}  */
/*{{{  PTPT_ATerm PTPT_makeATermList(PTPT_OptLayout wsAfterBracketOpen, PTPT_ATermElems elems, PTPT_OptLayout wsAfterElems) */

PTPT_ATerm PTPT_makeATermList(PTPT_OptLayout wsAfterBracketOpen, PTPT_ATermElems elems, PTPT_OptLayout wsAfterElems)
{
  return (PTPT_ATerm)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun33))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl2(PTPT_afun78, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun40)), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19))))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun36))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun40))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun79)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun33)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterElems), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl1(PTPT_afun8, (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl2(PTPT_afun78, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun40)), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19))))), (ATerm) elems)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun36)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))));
}

/*}}}  */
/*{{{  PTPT_ATerm PTPT_makeATermAnnotated(PTPT_ATerm trm, PTPT_OptLayout wsAfterTrm, PTPT_Annotation Annotation) */

PTPT_ATerm PTPT_makeATermAnnotated(PTPT_ATerm trm, PTPT_OptLayout wsAfterTrm, PTPT_Annotation Annotation)
{
  return (PTPT_ATerm)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun10)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun40)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun40))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun15)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) Annotation), (ATerm) wsAfterTrm), (ATerm) trm));
}

/*}}}  */
/*{{{  PTPT_Annotation PTPT_makeAnnotationDefault(PTPT_OptLayout wsAfterBraceOpen, PTPT_ATermAnnos annos, PTPT_OptLayout wsAfterAnnos) */

PTPT_Annotation PTPT_makeAnnotationDefault(PTPT_OptLayout wsAfterBraceOpen, PTPT_ATermAnnos annos, PTPT_OptLayout wsAfterAnnos)
{
  return (PTPT_Annotation)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun99))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl2(PTPT_afun34, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun40)), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19))))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun100))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun10))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun88)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(125)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun99)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(125)))), (ATerm) wsAfterAnnos), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl1(PTPT_afun8, (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl2(PTPT_afun34, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun40)), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19))))), (ATerm) annos)), (ATerm) wsAfterBraceOpen), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(123)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun100)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(123)))));
}

/*}}}  */
/*{{{  PTPT_ATermArgs PTPT_makeATermArgsEmpty(void) */

PTPT_ATermArgs PTPT_makeATermArgsEmpty(void)
{
  return (PTPT_ATermArgs)(ATerm)ATempty;
}

/*}}}  */
/*{{{  PTPT_ATermArgs PTPT_makeATermArgsSingle(PTPT_ATerm head) */

PTPT_ATermArgs PTPT_makeATermArgsSingle(PTPT_ATerm head)
{
  return (PTPT_ATermArgs)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  PTPT_ATermArgs PTPT_makeATermArgsMany(PTPT_ATerm head, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATermArgs tail) */

PTPT_ATermArgs PTPT_makeATermArgsMany(PTPT_ATerm head, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATermArgs tail)
{
  if (PTPT_isATermArgsEmpty(tail)) {
    return PTPT_makeATermArgsSingle(head);
  }
  return (PTPT_ATermArgs)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm) wsAfterSep), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterHead), (ATerm) head);
}

/*}}}  */
/*{{{  PTPT_ATermElems PTPT_makeATermElemsEmpty(void) */

PTPT_ATermElems PTPT_makeATermElemsEmpty(void)
{
  return (PTPT_ATermElems)(ATerm)ATempty;
}

/*}}}  */
/*{{{  PTPT_ATermElems PTPT_makeATermElemsSingle(PTPT_ATerm head) */

PTPT_ATermElems PTPT_makeATermElemsSingle(PTPT_ATerm head)
{
  return (PTPT_ATermElems)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  PTPT_ATermElems PTPT_makeATermElemsMany(PTPT_ATerm head, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATermElems tail) */

PTPT_ATermElems PTPT_makeATermElemsMany(PTPT_ATerm head, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATermElems tail)
{
  if (PTPT_isATermElemsEmpty(tail)) {
    return PTPT_makeATermElemsSingle(head);
  }
  return (PTPT_ATermElems)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm) wsAfterSep), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterHead), (ATerm) head);
}

/*}}}  */
/*{{{  PTPT_ATermAnnos PTPT_makeATermAnnosEmpty(void) */

PTPT_ATermAnnos PTPT_makeATermAnnosEmpty(void)
{
  return (PTPT_ATermAnnos)(ATerm)ATempty;
}

/*}}}  */
/*{{{  PTPT_ATermAnnos PTPT_makeATermAnnosSingle(PTPT_ATerm head) */

PTPT_ATermAnnos PTPT_makeATermAnnosSingle(PTPT_ATerm head)
{
  return (PTPT_ATermAnnos)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  PTPT_ATermAnnos PTPT_makeATermAnnosMany(PTPT_ATerm head, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATermAnnos tail) */

PTPT_ATermAnnos PTPT_makeATermAnnosMany(PTPT_ATerm head, PTPT_OptLayout wsAfterHead, PTPT_OptLayout wsAfterSep, PTPT_ATermAnnos tail)
{
  if (PTPT_isATermAnnosEmpty(tail)) {
    return PTPT_makeATermAnnosSingle(head);
  }
  return (PTPT_ATermAnnos)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm) wsAfterSep), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun19)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterHead), (ATerm) head);
}

/*}}}  */
/*{{{  PTPT_IntCon PTPT_makeIntConNatural(PTPT_NatCon NatCon) */

PTPT_IntCon PTPT_makeIntConNatural(PTPT_NatCon NatCon)
{
  return (PTPT_IntCon)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun24)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun85))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun101)))))), (ATerm)ATmakeList1((ATerm) NatCon));
}

/*}}}  */
/*{{{  PTPT_IntCon PTPT_makeIntConPositive(PTPT_OptLayout wsAfterPos, PTPT_NatCon NatCon) */

PTPT_IntCon PTPT_makeIntConPositive(PTPT_OptLayout wsAfterPos, PTPT_NatCon NatCon)
{
  return (PTPT_IntCon)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun24)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun102))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun85))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun103)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) NatCon), (ATerm) wsAfterPos), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(43)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun102)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(43)))));
}

/*}}}  */
/*{{{  PTPT_IntCon PTPT_makeIntConNegative(PTPT_OptLayout wsAfterNeg, PTPT_NatCon NatCon) */

PTPT_IntCon PTPT_makeIntConNegative(PTPT_OptLayout wsAfterNeg, PTPT_NatCon NatCon)
{
  return (PTPT_IntCon)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun24)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun104))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun85))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun105)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) NatCon), (ATerm) wsAfterNeg), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(45)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun104)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(45)))));
}

/*}}}  */
/*{{{  PTPT_OptExp PTPT_makeOptExpPresent(PTPT_OptLayout wsAfterE, PTPT_IntCon IntCon) */

PTPT_OptExp PTPT_makeOptExpPresent(PTPT_OptLayout wsAfterE, PTPT_IntCon IntCon)
{
  return (PTPT_OptExp)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun85)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun106))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun107))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun108)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) IntCon), (ATerm) wsAfterE), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun106)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))));
}

/*}}}  */
/*{{{  PTPT_OptExp PTPT_makeOptExpAbsent(void) */

PTPT_OptExp PTPT_makeOptExpAbsent(void)
{
  return (PTPT_OptExp)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATempty, (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun107))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun109)))))), (ATerm)ATempty);
}

/*}}}  */
/*{{{  PTPT_RealCon PTPT_makeRealConRealCon(PTPT_IntCon base, PTPT_OptLayout wsAfterBase, PTPT_OptLayout wsAfterPeriod, PTPT_NatCon decimal, PTPT_OptLayout wsAfterDecimal, PTPT_OptExp exp) */

PTPT_RealCon PTPT_makeRealConRealCon(PTPT_IntCon base, PTPT_OptLayout wsAfterBase, PTPT_OptLayout wsAfterPeriod, PTPT_NatCon decimal, PTPT_OptLayout wsAfterDecimal, PTPT_OptExp exp)
{
  return (PTPT_RealCon)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun107)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun24)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun110))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun3, (ATerm)ATmakeAppl0(PTPT_afun4)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun85)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun86))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun111)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) exp), (ATerm) wsAfterDecimal), (ATerm) decimal), (ATerm) wsAfterPeriod), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(46)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun110)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(46)))), (ATerm) wsAfterBase), (ATerm) base));
}

/*}}}  */
/*{{{  PTPT_LexStrChar PTPT_makeLexStrCharNewline(void) */

PTPT_LexStrChar PTPT_makeLexStrCharNewline(void)
{
  return (PTPT_LexStrChar)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun112))), (ATerm)ATmakeAppl1(PTPT_afun6, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun113))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun114)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(110)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun112)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(110)), (ATerm)ATmakeInt(92)))));
}

/*}}}  */
/*{{{  PTPT_LexStrChar PTPT_makeLexStrCharTab(void) */

PTPT_LexStrChar PTPT_makeLexStrCharTab(void)
{
  return (PTPT_LexStrChar)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun115))), (ATerm)ATmakeAppl1(PTPT_afun6, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun113))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun116)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun115)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(92)))));
}

/*}}}  */
/*{{{  PTPT_LexStrChar PTPT_makeLexStrCharQuote(void) */

PTPT_LexStrChar PTPT_makeLexStrCharQuote(void)
{
  return (PTPT_LexStrChar)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun117))), (ATerm)ATmakeAppl1(PTPT_afun6, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun113))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun118)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(34)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun117)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(34)), (ATerm)ATmakeInt(92)))));
}

/*}}}  */
/*{{{  PTPT_LexStrChar PTPT_makeLexStrCharBackslash(void) */

PTPT_LexStrChar PTPT_makeLexStrCharBackslash(void)
{
  return (PTPT_LexStrChar)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun119))), (ATerm)ATmakeAppl1(PTPT_afun6, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun113))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun120)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun119)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(92)), (ATerm)ATmakeInt(92)))));
}

/*}}}  */
/*{{{  PTPT_LexStrChar PTPT_makeLexStrCharDecimal(char a, char b, char c) */

PTPT_LexStrChar PTPT_makeLexStrCharDecimal(char a, char b, char c)
{
  return (PTPT_LexStrChar)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun121, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun121, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun121, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun122))), (ATerm)ATmakeAppl1(PTPT_afun6, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun113))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun123)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) ((ATerm) PTPT_byteToChar(c))), (ATerm) ((ATerm) PTPT_byteToChar(b))), (ATerm) ((ATerm) PTPT_byteToChar(a))), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(PTPT_afun16, (ATerm)ATmakeAppl0(PTPT_afun122)), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))));
}

/*}}}  */
/*{{{  PTPT_LexStrChar PTPT_makeLexStrCharNormal(char ch) */

PTPT_LexStrChar PTPT_makeLexStrCharNormal(char ch)
{
  return (PTPT_LexStrChar)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun121, (ATerm)ATmakeInt(93), (ATerm)ATmakeInt(255))), (ATerm)ATmakeAppl2(PTPT_afun121, (ATerm)ATmakeInt(35), (ATerm)ATmakeInt(91))), (ATerm)ATmakeAppl2(PTPT_afun121, (ATerm)ATmakeInt(32), (ATerm)ATmakeInt(33))))), (ATerm)ATmakeAppl1(PTPT_afun6, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun113))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun124)))))), (ATerm)ATmakeList1((ATerm) ((ATerm) PTPT_byteToChar(ch))));
}

/*}}}  */
/*{{{  PTPT_StrChar PTPT_makeStrCharLexToCf(PTPT_LexStrChar StrChar) */

PTPT_StrChar PTPT_makeStrCharLexToCf(PTPT_LexStrChar StrChar)
{
  return (PTPT_StrChar)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun6, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun113)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun113))), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm) StrChar));
}

/*}}}  */
/*{{{  PTPT_LexStrCon PTPT_makeLexStrConDefault(PTPT_LexStrCharChars chars) */

PTPT_LexStrCon PTPT_makeLexStrConDefault(PTPT_LexStrCharChars chars)
{
  return (PTPT_LexStrCon)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(34)))), (ATerm)ATmakeAppl1(PTPT_afun6, (ATerm)ATmakeAppl1(PTPT_afun125, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun113))))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeInt(34)))), (ATerm)ATmakeAppl1(PTPT_afun6, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun42))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun88)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(34)), (ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl1(PTPT_afun8, (ATerm)ATmakeAppl1(PTPT_afun6, (ATerm)ATmakeAppl1(PTPT_afun125, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun113))))), (ATerm) chars)), (ATerm)ATmakeInt(34)));
}

/*}}}  */
/*{{{  PTPT_StrCon PTPT_makeStrConLexToCf(PTPT_LexStrCon StrCon) */

PTPT_StrCon PTPT_makeStrConLexToCf(PTPT_LexStrCon StrCon)
{
  return (PTPT_StrCon)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun6, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun42)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun42))), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm) StrCon));
}

/*}}}  */
/*{{{  PTPT_LexStrCharChars PTPT_makeLexStrCharCharsEmpty(void) */

PTPT_LexStrCharChars PTPT_makeLexStrCharCharsEmpty(void)
{
  return (PTPT_LexStrCharChars)(ATerm)ATempty;
}

/*}}}  */
/*{{{  PTPT_LexStrCharChars PTPT_makeLexStrCharCharsSingle(PTPT_LexStrChar head) */

PTPT_LexStrCharChars PTPT_makeLexStrCharCharsSingle(PTPT_LexStrChar head)
{
  return (PTPT_LexStrCharChars)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  PTPT_LexStrCharChars PTPT_makeLexStrCharCharsMany(PTPT_LexStrChar head, PTPT_LexStrCharChars tail) */

PTPT_LexStrCharChars PTPT_makeLexStrCharCharsMany(PTPT_LexStrChar head, PTPT_LexStrCharChars tail)
{
  return (PTPT_LexStrCharChars)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/*}}}  */
/*{{{  PTPT_LexNatCon PTPT_makeLexNatConDigits(const char* list) */

PTPT_LexNatCon PTPT_makeLexNatConDigits(const char* list)
{
  return (PTPT_LexNatCon)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun6, (ATerm)ATmakeAppl1(PTPT_afun7, (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun121, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))))))), (ATerm)ATmakeAppl1(PTPT_afun6, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun24))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun126)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl1(PTPT_afun8, (ATerm)ATmakeAppl1(PTPT_afun6, (ATerm)ATmakeAppl1(PTPT_afun7, (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun121, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))))))), (ATerm) ((ATerm) PTPT_stringToChars(list)))));
}

/*}}}  */
/*{{{  PTPT_NatCon PTPT_makeNatConLexToCf(PTPT_LexNatCon NatCon) */

PTPT_NatCon PTPT_makeNatConLexToCf(PTPT_LexNatCon NatCon)
{
  return (PTPT_NatCon)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun6, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun24)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun24))), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm) NatCon));
}

/*}}}  */
/*{{{  PTPT_LexIdCon PTPT_makeLexIdConDefault(char head, const char* tail) */

PTPT_LexIdCon PTPT_makeLexIdConDefault(char head, const char* tail)
{
  return (PTPT_LexIdCon)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun6, (ATerm)ATmakeAppl1(PTPT_afun125, (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun121, (ATerm)ATmakeInt(97), (ATerm)ATmakeInt(122))), (ATerm)ATmakeAppl2(PTPT_afun121, (ATerm)ATmakeInt(65), (ATerm)ATmakeInt(90))), (ATerm)ATmakeAppl2(PTPT_afun121, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))), (ATerm)ATmakeInt(45)))))), (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun121, (ATerm)ATmakeInt(97), (ATerm)ATmakeInt(122))), (ATerm)ATmakeAppl2(PTPT_afun121, (ATerm)ATmakeInt(65), (ATerm)ATmakeInt(90))))), (ATerm)ATmakeAppl1(PTPT_afun6, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun91))), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun88)))))), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl1(PTPT_afun8, (ATerm)ATmakeAppl1(PTPT_afun6, (ATerm)ATmakeAppl1(PTPT_afun125, (ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(PTPT_afun121, (ATerm)ATmakeInt(97), (ATerm)ATmakeInt(122))), (ATerm)ATmakeAppl2(PTPT_afun121, (ATerm)ATmakeInt(65), (ATerm)ATmakeInt(90))), (ATerm)ATmakeAppl2(PTPT_afun121, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))), (ATerm)ATmakeInt(45)))))), (ATerm) ((ATerm) PTPT_stringToChars(tail)))), (ATerm) ((ATerm) PTPT_byteToChar(head))));
}

/*}}}  */
/*{{{  PTPT_IdCon PTPT_makeIdConLexToCf(PTPT_LexIdCon IdCon) */

PTPT_IdCon PTPT_makeIdConLexToCf(PTPT_LexIdCon IdCon)
{
  return (PTPT_IdCon)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun6, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun91)))), (ATerm)ATmakeAppl1(PTPT_afun2, (ATerm)ATmakeAppl1(PTPT_afun9, (ATerm)ATmakeAppl0(PTPT_afun91))), (ATerm)ATmakeAppl0(PTPT_afun5)), (ATerm)ATmakeList1((ATerm) IdCon));
}

/*}}}  */
/*{{{  PTPT_LexLayout PTPT_makeLexLayoutWhitespace(char ch) */

PTPT_LexLayout PTPT_makeLexLayoutWhitespace(char ch)
{
  return (PTPT_LexLayout)(ATerm)ATmakeAppl2(PTPT_afun0, (ATerm)ATmakeAppl3(PTPT_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun23, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(32)), (ATerm)ATmakeInt(13)), (ATerm)ATmakeAppl2(PTPT_afun121, (ATerm)ATmakeInt(9), (ATerm)ATmakeInt(10))))), (ATerm)ATmakeAppl1(PTPT_afun6, (ATerm)ATmakeAppl0(PTPT_afun4)), (ATerm)ATmakeAppl1(PTPT_afun12, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PTPT_afun13, (ATerm)ATmakeAppl1(PTPT_afun14, (ATerm)ATmakeAppl0(PTPT_afun127)))))), (ATerm)ATmakeList1((ATerm) ((ATerm) PTPT_byteToChar(ch))));
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool PTPT_isEqualOptLayout(PTPT_OptLayout arg0, PTPT_OptLayout arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTPT_isEqualLayout(PTPT_Layout arg0, PTPT_Layout arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTPT_isEqualLexLayoutList(PTPT_LexLayoutList arg0, PTPT_LexLayoutList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTPT_isEqualTree(PTPT_Tree arg0, PTPT_Tree arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTPT_isEqualAttributes(PTPT_Attributes arg0, PTPT_Attributes arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTPT_isEqualAttrs(PTPT_Attrs arg0, PTPT_Attrs arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTPT_isEqualAttr(PTPT_Attr arg0, PTPT_Attr arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTPT_isEqualAssociativity(PTPT_Associativity arg0, PTPT_Associativity arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTPT_isEqualAttrList(PTPT_AttrList arg0, PTPT_AttrList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTPT_isEqualParseTree(PTPT_ParseTree arg0, PTPT_ParseTree arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTPT_isEqualSymbol(PTPT_Symbol arg0, PTPT_Symbol arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTPT_isEqualSymbols(PTPT_Symbols arg0, PTPT_Symbols arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTPT_isEqualCharRanges(PTPT_CharRanges arg0, PTPT_CharRanges arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTPT_isEqualCharRange(PTPT_CharRange arg0, PTPT_CharRange arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTPT_isEqualStart(PTPT_Start arg0, PTPT_Start arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTPT_isEqualSymbolList(PTPT_SymbolList arg0, PTPT_SymbolList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTPT_isEqualCharRangeList(PTPT_CharRangeList arg0, PTPT_CharRangeList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTPT_isEqualArgs(PTPT_Args arg0, PTPT_Args arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTPT_isEqualProduction(PTPT_Production arg0, PTPT_Production arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTPT_isEqualTreeList(PTPT_TreeList arg0, PTPT_TreeList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTPT_isEqualAFun(PTPT_AFun arg0, PTPT_AFun arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTPT_isEqualATerm(PTPT_ATerm arg0, PTPT_ATerm arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTPT_isEqualAnnotation(PTPT_Annotation arg0, PTPT_Annotation arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTPT_isEqualATermArgs(PTPT_ATermArgs arg0, PTPT_ATermArgs arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTPT_isEqualATermElems(PTPT_ATermElems arg0, PTPT_ATermElems arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTPT_isEqualATermAnnos(PTPT_ATermAnnos arg0, PTPT_ATermAnnos arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTPT_isEqualIntCon(PTPT_IntCon arg0, PTPT_IntCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTPT_isEqualOptExp(PTPT_OptExp arg0, PTPT_OptExp arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTPT_isEqualRealCon(PTPT_RealCon arg0, PTPT_RealCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTPT_isEqualLexStrChar(PTPT_LexStrChar arg0, PTPT_LexStrChar arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTPT_isEqualStrChar(PTPT_StrChar arg0, PTPT_StrChar arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTPT_isEqualLexStrCon(PTPT_LexStrCon arg0, PTPT_LexStrCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTPT_isEqualStrCon(PTPT_StrCon arg0, PTPT_StrCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTPT_isEqualLexStrCharChars(PTPT_LexStrCharChars arg0, PTPT_LexStrCharChars arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTPT_isEqualLexNatCon(PTPT_LexNatCon arg0, PTPT_LexNatCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTPT_isEqualNatCon(PTPT_NatCon arg0, PTPT_NatCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTPT_isEqualLexIdCon(PTPT_LexIdCon arg0, PTPT_LexIdCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTPT_isEqualIdCon(PTPT_IdCon arg0, PTPT_IdCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PTPT_isEqualLexLayout(PTPT_LexLayout arg0, PTPT_LexLayout arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  PTPT_OptLayout accessors */

/*{{{  ATbool PTPT_isValidOptLayout(PTPT_OptLayout arg) */

ATbool PTPT_isValidOptLayout(PTPT_OptLayout arg)
{
  if (PTPT_isOptLayoutAbsent(arg)) {
    return ATtrue;
  }
  else if (PTPT_isOptLayoutPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isOptLayoutAbsent(PTPT_OptLayout arg) */

inline ATbool PTPT_isOptLayoutAbsent(PTPT_OptLayout arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternOptLayoutAbsent);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isOptLayoutPresent(PTPT_OptLayout arg) */

inline ATbool PTPT_isOptLayoutPresent(PTPT_OptLayout arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternOptLayoutPresent, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PTPT_hasOptLayoutLayout(PTPT_OptLayout arg) */

ATbool PTPT_hasOptLayoutLayout(PTPT_OptLayout arg)
{
  if (PTPT_isOptLayoutPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTPT_Layout PTPT_getOptLayoutLayout(PTPT_OptLayout arg) */

PTPT_Layout PTPT_getOptLayoutLayout(PTPT_OptLayout arg)
{
  
    return (PTPT_Layout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_setOptLayoutLayout(PTPT_OptLayout arg, PTPT_Layout layout) */

PTPT_OptLayout PTPT_setOptLayoutLayout(PTPT_OptLayout arg, PTPT_Layout layout)
{
  if (PTPT_isOptLayoutPresent(arg)) {
    return (PTPT_OptLayout)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) layout), 0), 1);
  }

  ATabort("OptLayout has no Layout: %t\n", arg);
  return (PTPT_OptLayout)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTPT_Layout accessors */

/*{{{  ATbool PTPT_isValidLayout(PTPT_Layout arg) */

ATbool PTPT_isValidLayout(PTPT_Layout arg)
{
  if (PTPT_isLayoutLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isLayoutLexToCf(PTPT_Layout arg) */

inline ATbool PTPT_isLayoutLexToCf(PTPT_Layout arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTPT_patternLayoutLexToCf, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PTPT_hasLayoutList(PTPT_Layout arg) */

ATbool PTPT_hasLayoutList(PTPT_Layout arg)
{
  if (PTPT_isLayoutLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTPT_LexLayoutList PTPT_getLayoutList(PTPT_Layout arg) */

PTPT_LexLayoutList PTPT_getLayoutList(PTPT_Layout arg)
{
  
    return (PTPT_LexLayoutList)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  PTPT_Layout PTPT_setLayoutList(PTPT_Layout arg, PTPT_LexLayoutList list) */

PTPT_Layout PTPT_setLayoutList(PTPT_Layout arg, PTPT_LexLayoutList list)
{
  if (PTPT_isLayoutLexToCf(arg)) {
    return (PTPT_Layout)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) list), 1), 0), 1);
  }

  ATabort("Layout has no List: %t\n", arg);
  return (PTPT_Layout)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTPT_LexLayoutList accessors */

/*{{{  ATbool PTPT_isValidLexLayoutList(PTPT_LexLayoutList arg) */

ATbool PTPT_isValidLexLayoutList(PTPT_LexLayoutList arg)
{
  if (PTPT_isLexLayoutListEmpty(arg)) {
    return ATtrue;
  }
  else if (PTPT_isLexLayoutListSingle(arg)) {
    return ATtrue;
  }
  else if (PTPT_isLexLayoutListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isLexLayoutListEmpty(PTPT_LexLayoutList arg) */

inline ATbool PTPT_isLexLayoutListEmpty(PTPT_LexLayoutList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTPT_patternLexLayoutListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isLexLayoutListSingle(PTPT_LexLayoutList arg) */

inline ATbool PTPT_isLexLayoutListSingle(PTPT_LexLayoutList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternLexLayoutListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isLexLayoutListMany(PTPT_LexLayoutList arg) */

inline ATbool PTPT_isLexLayoutListMany(PTPT_LexLayoutList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternLexLayoutListMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PTPT_hasLexLayoutListHead(PTPT_LexLayoutList arg) */

ATbool PTPT_hasLexLayoutListHead(PTPT_LexLayoutList arg)
{
  if (PTPT_isLexLayoutListSingle(arg)) {
    return ATtrue;
  }
  else if (PTPT_isLexLayoutListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasLexLayoutListTail(PTPT_LexLayoutList arg) */

ATbool PTPT_hasLexLayoutListTail(PTPT_LexLayoutList arg)
{
  if (PTPT_isLexLayoutListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTPT_LexLayout PTPT_getLexLayoutListHead(PTPT_LexLayoutList arg) */

PTPT_LexLayout PTPT_getLexLayoutListHead(PTPT_LexLayoutList arg)
{
  if (PTPT_isLexLayoutListSingle(arg)) {
    return (PTPT_LexLayout)ATgetFirst((ATermList)arg);
  }
  else 
    return (PTPT_LexLayout)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  PTPT_LexLayoutList PTPT_getLexLayoutListTail(PTPT_LexLayoutList arg) */

PTPT_LexLayoutList PTPT_getLexLayoutListTail(PTPT_LexLayoutList arg)
{
  
    return (PTPT_LexLayoutList)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  PTPT_LexLayoutList PTPT_setLexLayoutListHead(PTPT_LexLayoutList arg, PTPT_LexLayout head) */

PTPT_LexLayoutList PTPT_setLexLayoutListHead(PTPT_LexLayoutList arg, PTPT_LexLayout head)
{
  if (PTPT_isLexLayoutListSingle(arg)) {
    return (PTPT_LexLayoutList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (PTPT_isLexLayoutListMany(arg)) {
    return (PTPT_LexLayoutList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("LexLayoutList has no Head: %t\n", arg);
  return (PTPT_LexLayoutList)NULL;
}

/*}}}  */
/*{{{  PTPT_LexLayoutList PTPT_setLexLayoutListTail(PTPT_LexLayoutList arg, PTPT_LexLayoutList tail) */

PTPT_LexLayoutList PTPT_setLexLayoutListTail(PTPT_LexLayoutList arg, PTPT_LexLayoutList tail)
{
  if (PTPT_isLexLayoutListMany(arg)) {
    return (PTPT_LexLayoutList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("LexLayoutList has no Tail: %t\n", arg);
  return (PTPT_LexLayoutList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTPT_Tree accessors */

/*{{{  ATbool PTPT_isValidTree(PTPT_Tree arg) */

ATbool PTPT_isValidTree(PTPT_Tree arg)
{
  if (PTPT_isTreeAnnotated(arg)) {
    return ATtrue;
  }
  else if (PTPT_isTreeAppl(arg)) {
    return ATtrue;
  }
  else if (PTPT_isTreeCycle(arg)) {
    return ATtrue;
  }
  else if (PTPT_isTreeAmb(arg)) {
    return ATtrue;
  }
  else if (PTPT_isTreeChar(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isTreeAnnotated(PTPT_Tree arg) */

inline ATbool PTPT_isTreeAnnotated(PTPT_Tree arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternTreeAnnotated, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isTreeAppl(PTPT_Tree arg) */

inline ATbool PTPT_isTreeAppl(PTPT_Tree arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternTreeAppl, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isTreeCycle(PTPT_Tree arg) */

inline ATbool PTPT_isTreeCycle(PTPT_Tree arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternTreeCycle, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isTreeAmb(PTPT_Tree arg) */

inline ATbool PTPT_isTreeAmb(PTPT_Tree arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternTreeAmb, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isTreeChar(PTPT_Tree arg) */

inline ATbool PTPT_isTreeChar(PTPT_Tree arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternTreeChar, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PTPT_hasTreeTree(PTPT_Tree arg) */

ATbool PTPT_hasTreeTree(PTPT_Tree arg)
{
  if (PTPT_isTreeAnnotated(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasTreeWsAfterTree(PTPT_Tree arg) */

ATbool PTPT_hasTreeWsAfterTree(PTPT_Tree arg)
{
  if (PTPT_isTreeAnnotated(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasTreeAnnotation(PTPT_Tree arg) */

ATbool PTPT_hasTreeAnnotation(PTPT_Tree arg)
{
  if (PTPT_isTreeAnnotated(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasTreeWsAfterAppl(PTPT_Tree arg) */

ATbool PTPT_hasTreeWsAfterAppl(PTPT_Tree arg)
{
  if (PTPT_isTreeAppl(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasTreeWsAfterParenOpen(PTPT_Tree arg) */

ATbool PTPT_hasTreeWsAfterParenOpen(PTPT_Tree arg)
{
  if (PTPT_isTreeAppl(arg)) {
    return ATtrue;
  }
  else if (PTPT_isTreeCycle(arg)) {
    return ATtrue;
  }
  else if (PTPT_isTreeAmb(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasTreeProd(PTPT_Tree arg) */

ATbool PTPT_hasTreeProd(PTPT_Tree arg)
{
  if (PTPT_isTreeAppl(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasTreeWsAfterProd(PTPT_Tree arg) */

ATbool PTPT_hasTreeWsAfterProd(PTPT_Tree arg)
{
  if (PTPT_isTreeAppl(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasTreeWsAfterComma(PTPT_Tree arg) */

ATbool PTPT_hasTreeWsAfterComma(PTPT_Tree arg)
{
  if (PTPT_isTreeAppl(arg)) {
    return ATtrue;
  }
  else if (PTPT_isTreeCycle(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasTreeArgs(PTPT_Tree arg) */

ATbool PTPT_hasTreeArgs(PTPT_Tree arg)
{
  if (PTPT_isTreeAppl(arg)) {
    return ATtrue;
  }
  else if (PTPT_isTreeAmb(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasTreeWsAfterArgs(PTPT_Tree arg) */

ATbool PTPT_hasTreeWsAfterArgs(PTPT_Tree arg)
{
  if (PTPT_isTreeAppl(arg)) {
    return ATtrue;
  }
  else if (PTPT_isTreeAmb(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasTreeWsAfterCycle(PTPT_Tree arg) */

ATbool PTPT_hasTreeWsAfterCycle(PTPT_Tree arg)
{
  if (PTPT_isTreeCycle(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasTreeSymbol(PTPT_Tree arg) */

ATbool PTPT_hasTreeSymbol(PTPT_Tree arg)
{
  if (PTPT_isTreeCycle(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasTreeWsAfterSymbol(PTPT_Tree arg) */

ATbool PTPT_hasTreeWsAfterSymbol(PTPT_Tree arg)
{
  if (PTPT_isTreeCycle(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasTreeCycleLength(PTPT_Tree arg) */

ATbool PTPT_hasTreeCycleLength(PTPT_Tree arg)
{
  if (PTPT_isTreeCycle(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasTreeWsAfterCycleLength(PTPT_Tree arg) */

ATbool PTPT_hasTreeWsAfterCycleLength(PTPT_Tree arg)
{
  if (PTPT_isTreeCycle(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasTreeWsAfterAmb(PTPT_Tree arg) */

ATbool PTPT_hasTreeWsAfterAmb(PTPT_Tree arg)
{
  if (PTPT_isTreeAmb(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasTreeCharacter(PTPT_Tree arg) */

ATbool PTPT_hasTreeCharacter(PTPT_Tree arg)
{
  if (PTPT_isTreeChar(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTPT_Tree PTPT_getTreeTree(PTPT_Tree arg) */

PTPT_Tree PTPT_getTreeTree(PTPT_Tree arg)
{
  
    return (PTPT_Tree)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getTreeWsAfterTree(PTPT_Tree arg) */

PTPT_OptLayout PTPT_getTreeWsAfterTree(PTPT_Tree arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_Annotation PTPT_getTreeAnnotation(PTPT_Tree arg) */

PTPT_Annotation PTPT_getTreeAnnotation(PTPT_Tree arg)
{
  
    return (PTPT_Annotation)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getTreeWsAfterAppl(PTPT_Tree arg) */

PTPT_OptLayout PTPT_getTreeWsAfterAppl(PTPT_Tree arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getTreeWsAfterParenOpen(PTPT_Tree arg) */

PTPT_OptLayout PTPT_getTreeWsAfterParenOpen(PTPT_Tree arg)
{
  if (PTPT_isTreeAppl(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (PTPT_isTreeCycle(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  PTPT_Production PTPT_getTreeProd(PTPT_Tree arg) */

PTPT_Production PTPT_getTreeProd(PTPT_Tree arg)
{
  
    return (PTPT_Production)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getTreeWsAfterProd(PTPT_Tree arg) */

PTPT_OptLayout PTPT_getTreeWsAfterProd(PTPT_Tree arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getTreeWsAfterComma(PTPT_Tree arg) */

PTPT_OptLayout PTPT_getTreeWsAfterComma(PTPT_Tree arg)
{
  if (PTPT_isTreeAppl(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else 
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  PTPT_Args PTPT_getTreeArgs(PTPT_Tree arg) */

PTPT_Args PTPT_getTreeArgs(PTPT_Tree arg)
{
  if (PTPT_isTreeAppl(arg)) {
    return (PTPT_Args)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
  }
  else 
    return (PTPT_Args)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getTreeWsAfterArgs(PTPT_Tree arg) */

PTPT_OptLayout PTPT_getTreeWsAfterArgs(PTPT_Tree arg)
{
  if (PTPT_isTreeAppl(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
  }
  else 
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getTreeWsAfterCycle(PTPT_Tree arg) */

PTPT_OptLayout PTPT_getTreeWsAfterCycle(PTPT_Tree arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_getTreeSymbol(PTPT_Tree arg) */

PTPT_Symbol PTPT_getTreeSymbol(PTPT_Tree arg)
{
  
    return (PTPT_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getTreeWsAfterSymbol(PTPT_Tree arg) */

PTPT_OptLayout PTPT_getTreeWsAfterSymbol(PTPT_Tree arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PTPT_NatCon PTPT_getTreeCycleLength(PTPT_Tree arg) */

PTPT_NatCon PTPT_getTreeCycleLength(PTPT_Tree arg)
{
  
    return (PTPT_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getTreeWsAfterCycleLength(PTPT_Tree arg) */

PTPT_OptLayout PTPT_getTreeWsAfterCycleLength(PTPT_Tree arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getTreeWsAfterAmb(PTPT_Tree arg) */

PTPT_OptLayout PTPT_getTreeWsAfterAmb(PTPT_Tree arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_NatCon PTPT_getTreeCharacter(PTPT_Tree arg) */

PTPT_NatCon PTPT_getTreeCharacter(PTPT_Tree arg)
{
  
    return (PTPT_NatCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  PTPT_Tree PTPT_setTreeTree(PTPT_Tree arg, PTPT_Tree Tree) */

PTPT_Tree PTPT_setTreeTree(PTPT_Tree arg, PTPT_Tree Tree)
{
  if (PTPT_isTreeAnnotated(arg)) {
    return (PTPT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Tree), 0), 1);
  }

  ATabort("Tree has no Tree: %t\n", arg);
  return (PTPT_Tree)NULL;
}

/*}}}  */
/*{{{  PTPT_Tree PTPT_setTreeWsAfterTree(PTPT_Tree arg, PTPT_OptLayout wsAfterTree) */

PTPT_Tree PTPT_setTreeWsAfterTree(PTPT_Tree arg, PTPT_OptLayout wsAfterTree)
{
  if (PTPT_isTreeAnnotated(arg)) {
    return (PTPT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterTree), 1), 1);
  }

  ATabort("Tree has no WsAfterTree: %t\n", arg);
  return (PTPT_Tree)NULL;
}

/*}}}  */
/*{{{  PTPT_Tree PTPT_setTreeAnnotation(PTPT_Tree arg, PTPT_Annotation Annotation) */

PTPT_Tree PTPT_setTreeAnnotation(PTPT_Tree arg, PTPT_Annotation Annotation)
{
  if (PTPT_isTreeAnnotated(arg)) {
    return (PTPT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Annotation), 2), 1);
  }

  ATabort("Tree has no Annotation: %t\n", arg);
  return (PTPT_Tree)NULL;
}

/*}}}  */
/*{{{  PTPT_Tree PTPT_setTreeWsAfterAppl(PTPT_Tree arg, PTPT_OptLayout wsAfterAppl) */

PTPT_Tree PTPT_setTreeWsAfterAppl(PTPT_Tree arg, PTPT_OptLayout wsAfterAppl)
{
  if (PTPT_isTreeAppl(arg)) {
    return (PTPT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterAppl), 1), 1);
  }

  ATabort("Tree has no WsAfterAppl: %t\n", arg);
  return (PTPT_Tree)NULL;
}

/*}}}  */
/*{{{  PTPT_Tree PTPT_setTreeWsAfterParenOpen(PTPT_Tree arg, PTPT_OptLayout wsAfterParenOpen) */

PTPT_Tree PTPT_setTreeWsAfterParenOpen(PTPT_Tree arg, PTPT_OptLayout wsAfterParenOpen)
{
  if (PTPT_isTreeAppl(arg)) {
    return (PTPT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PTPT_isTreeCycle(arg)) {
    return (PTPT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PTPT_isTreeAmb(arg)) {
    return (PTPT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("Tree has no WsAfterParenOpen: %t\n", arg);
  return (PTPT_Tree)NULL;
}

/*}}}  */
/*{{{  PTPT_Tree PTPT_setTreeProd(PTPT_Tree arg, PTPT_Production prod) */

PTPT_Tree PTPT_setTreeProd(PTPT_Tree arg, PTPT_Production prod)
{
  if (PTPT_isTreeAppl(arg)) {
    return (PTPT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) prod), 4), 1);
  }

  ATabort("Tree has no Prod: %t\n", arg);
  return (PTPT_Tree)NULL;
}

/*}}}  */
/*{{{  PTPT_Tree PTPT_setTreeWsAfterProd(PTPT_Tree arg, PTPT_OptLayout wsAfterProd) */

PTPT_Tree PTPT_setTreeWsAfterProd(PTPT_Tree arg, PTPT_OptLayout wsAfterProd)
{
  if (PTPT_isTreeAppl(arg)) {
    return (PTPT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterProd), 5), 1);
  }

  ATabort("Tree has no WsAfterProd: %t\n", arg);
  return (PTPT_Tree)NULL;
}

/*}}}  */
/*{{{  PTPT_Tree PTPT_setTreeWsAfterComma(PTPT_Tree arg, PTPT_OptLayout wsAfterComma) */

PTPT_Tree PTPT_setTreeWsAfterComma(PTPT_Tree arg, PTPT_OptLayout wsAfterComma)
{
  if (PTPT_isTreeAppl(arg)) {
    return (PTPT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }
  else if (PTPT_isTreeCycle(arg)) {
    return (PTPT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }

  ATabort("Tree has no WsAfterComma: %t\n", arg);
  return (PTPT_Tree)NULL;
}

/*}}}  */
/*{{{  PTPT_Tree PTPT_setTreeArgs(PTPT_Tree arg, PTPT_Args args) */

PTPT_Tree PTPT_setTreeArgs(PTPT_Tree arg, PTPT_Args args)
{
  if (PTPT_isTreeAppl(arg)) {
    return (PTPT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) args), 8), 1);
  }
  else if (PTPT_isTreeAmb(arg)) {
    return (PTPT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) args), 4), 1);
  }

  ATabort("Tree has no Args: %t\n", arg);
  return (PTPT_Tree)NULL;
}

/*}}}  */
/*{{{  PTPT_Tree PTPT_setTreeWsAfterArgs(PTPT_Tree arg, PTPT_OptLayout wsAfterArgs) */

PTPT_Tree PTPT_setTreeWsAfterArgs(PTPT_Tree arg, PTPT_OptLayout wsAfterArgs)
{
  if (PTPT_isTreeAppl(arg)) {
    return (PTPT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterArgs), 9), 1);
  }
  else if (PTPT_isTreeAmb(arg)) {
    return (PTPT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterArgs), 5), 1);
  }

  ATabort("Tree has no WsAfterArgs: %t\n", arg);
  return (PTPT_Tree)NULL;
}

/*}}}  */
/*{{{  PTPT_Tree PTPT_setTreeWsAfterCycle(PTPT_Tree arg, PTPT_OptLayout wsAfterCycle) */

PTPT_Tree PTPT_setTreeWsAfterCycle(PTPT_Tree arg, PTPT_OptLayout wsAfterCycle)
{
  if (PTPT_isTreeCycle(arg)) {
    return (PTPT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterCycle), 1), 1);
  }

  ATabort("Tree has no WsAfterCycle: %t\n", arg);
  return (PTPT_Tree)NULL;
}

/*}}}  */
/*{{{  PTPT_Tree PTPT_setTreeSymbol(PTPT_Tree arg, PTPT_Symbol symbol) */

PTPT_Tree PTPT_setTreeSymbol(PTPT_Tree arg, PTPT_Symbol symbol)
{
  if (PTPT_isTreeCycle(arg)) {
    return (PTPT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) symbol), 4), 1);
  }

  ATabort("Tree has no Symbol: %t\n", arg);
  return (PTPT_Tree)NULL;
}

/*}}}  */
/*{{{  PTPT_Tree PTPT_setTreeWsAfterSymbol(PTPT_Tree arg, PTPT_OptLayout wsAfterSymbol) */

PTPT_Tree PTPT_setTreeWsAfterSymbol(PTPT_Tree arg, PTPT_OptLayout wsAfterSymbol)
{
  if (PTPT_isTreeCycle(arg)) {
    return (PTPT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSymbol), 5), 1);
  }

  ATabort("Tree has no WsAfterSymbol: %t\n", arg);
  return (PTPT_Tree)NULL;
}

/*}}}  */
/*{{{  PTPT_Tree PTPT_setTreeCycleLength(PTPT_Tree arg, PTPT_NatCon cycleLength) */

PTPT_Tree PTPT_setTreeCycleLength(PTPT_Tree arg, PTPT_NatCon cycleLength)
{
  if (PTPT_isTreeCycle(arg)) {
    return (PTPT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) cycleLength), 8), 1);
  }

  ATabort("Tree has no CycleLength: %t\n", arg);
  return (PTPT_Tree)NULL;
}

/*}}}  */
/*{{{  PTPT_Tree PTPT_setTreeWsAfterCycleLength(PTPT_Tree arg, PTPT_OptLayout wsAfterCycleLength) */

PTPT_Tree PTPT_setTreeWsAfterCycleLength(PTPT_Tree arg, PTPT_OptLayout wsAfterCycleLength)
{
  if (PTPT_isTreeCycle(arg)) {
    return (PTPT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterCycleLength), 9), 1);
  }

  ATabort("Tree has no WsAfterCycleLength: %t\n", arg);
  return (PTPT_Tree)NULL;
}

/*}}}  */
/*{{{  PTPT_Tree PTPT_setTreeWsAfterAmb(PTPT_Tree arg, PTPT_OptLayout wsAfterAmb) */

PTPT_Tree PTPT_setTreeWsAfterAmb(PTPT_Tree arg, PTPT_OptLayout wsAfterAmb)
{
  if (PTPT_isTreeAmb(arg)) {
    return (PTPT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterAmb), 1), 1);
  }

  ATabort("Tree has no WsAfterAmb: %t\n", arg);
  return (PTPT_Tree)NULL;
}

/*}}}  */
/*{{{  PTPT_Tree PTPT_setTreeCharacter(PTPT_Tree arg, PTPT_NatCon character) */

PTPT_Tree PTPT_setTreeCharacter(PTPT_Tree arg, PTPT_NatCon character)
{
  if (PTPT_isTreeChar(arg)) {
    return (PTPT_Tree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) character), 0), 1);
  }

  ATabort("Tree has no Character: %t\n", arg);
  return (PTPT_Tree)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTPT_Attributes accessors */

/*{{{  ATbool PTPT_isValidAttributes(PTPT_Attributes arg) */

ATbool PTPT_isValidAttributes(PTPT_Attributes arg)
{
  if (PTPT_isAttributesNoAttrs(arg)) {
    return ATtrue;
  }
  else if (PTPT_isAttributesAttrs(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isAttributesNoAttrs(PTPT_Attributes arg) */

inline ATbool PTPT_isAttributesNoAttrs(PTPT_Attributes arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternAttributesNoAttrs);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isAttributesAttrs(PTPT_Attributes arg) */

inline ATbool PTPT_isAttributesAttrs(PTPT_Attributes arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternAttributesAttrs, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PTPT_hasAttributesWsAfterAttrs(PTPT_Attributes arg) */

ATbool PTPT_hasAttributesWsAfterAttrs(PTPT_Attributes arg)
{
  if (PTPT_isAttributesAttrs(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasAttributesWsAfterParenOpen(PTPT_Attributes arg) */

ATbool PTPT_hasAttributesWsAfterParenOpen(PTPT_Attributes arg)
{
  if (PTPT_isAttributesAttrs(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasAttributesAttributes(PTPT_Attributes arg) */

ATbool PTPT_hasAttributesAttributes(PTPT_Attributes arg)
{
  if (PTPT_isAttributesAttrs(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasAttributesWsAfterAttributes(PTPT_Attributes arg) */

ATbool PTPT_hasAttributesWsAfterAttributes(PTPT_Attributes arg)
{
  if (PTPT_isAttributesAttrs(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getAttributesWsAfterAttrs(PTPT_Attributes arg) */

PTPT_OptLayout PTPT_getAttributesWsAfterAttrs(PTPT_Attributes arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getAttributesWsAfterParenOpen(PTPT_Attributes arg) */

PTPT_OptLayout PTPT_getAttributesWsAfterParenOpen(PTPT_Attributes arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  PTPT_Attrs PTPT_getAttributesAttributes(PTPT_Attributes arg) */

PTPT_Attrs PTPT_getAttributesAttributes(PTPT_Attributes arg)
{
  
    return (PTPT_Attrs)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getAttributesWsAfterAttributes(PTPT_Attributes arg) */

PTPT_OptLayout PTPT_getAttributesWsAfterAttributes(PTPT_Attributes arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PTPT_Attributes PTPT_setAttributesWsAfterAttrs(PTPT_Attributes arg, PTPT_OptLayout wsAfterAttrs) */

PTPT_Attributes PTPT_setAttributesWsAfterAttrs(PTPT_Attributes arg, PTPT_OptLayout wsAfterAttrs)
{
  if (PTPT_isAttributesAttrs(arg)) {
    return (PTPT_Attributes)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterAttrs), 1), 1);
  }

  ATabort("Attributes has no WsAfterAttrs: %t\n", arg);
  return (PTPT_Attributes)NULL;
}

/*}}}  */
/*{{{  PTPT_Attributes PTPT_setAttributesWsAfterParenOpen(PTPT_Attributes arg, PTPT_OptLayout wsAfterParenOpen) */

PTPT_Attributes PTPT_setAttributesWsAfterParenOpen(PTPT_Attributes arg, PTPT_OptLayout wsAfterParenOpen)
{
  if (PTPT_isAttributesAttrs(arg)) {
    return (PTPT_Attributes)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("Attributes has no WsAfterParenOpen: %t\n", arg);
  return (PTPT_Attributes)NULL;
}

/*}}}  */
/*{{{  PTPT_Attributes PTPT_setAttributesAttributes(PTPT_Attributes arg, PTPT_Attrs attributes) */

PTPT_Attributes PTPT_setAttributesAttributes(PTPT_Attributes arg, PTPT_Attrs attributes)
{
  if (PTPT_isAttributesAttrs(arg)) {
    return (PTPT_Attributes)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) attributes), 4), 1);
  }

  ATabort("Attributes has no Attributes: %t\n", arg);
  return (PTPT_Attributes)NULL;
}

/*}}}  */
/*{{{  PTPT_Attributes PTPT_setAttributesWsAfterAttributes(PTPT_Attributes arg, PTPT_OptLayout wsAfterAttributes) */

PTPT_Attributes PTPT_setAttributesWsAfterAttributes(PTPT_Attributes arg, PTPT_OptLayout wsAfterAttributes)
{
  if (PTPT_isAttributesAttrs(arg)) {
    return (PTPT_Attributes)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterAttributes), 5), 1);
  }

  ATabort("Attributes has no WsAfterAttributes: %t\n", arg);
  return (PTPT_Attributes)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTPT_Attrs accessors */

/*{{{  ATbool PTPT_isValidAttrs(PTPT_Attrs arg) */

ATbool PTPT_isValidAttrs(PTPT_Attrs arg)
{
  if (PTPT_isAttrsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isAttrsMany(PTPT_Attrs arg) */

inline ATbool PTPT_isAttrsMany(PTPT_Attrs arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTPT_patternAttrsMany, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PTPT_hasAttrsWsAfterBracketOpen(PTPT_Attrs arg) */

ATbool PTPT_hasAttrsWsAfterBracketOpen(PTPT_Attrs arg)
{
  if (PTPT_isAttrsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasAttrsList(PTPT_Attrs arg) */

ATbool PTPT_hasAttrsList(PTPT_Attrs arg)
{
  if (PTPT_isAttrsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasAttrsWsAfterList(PTPT_Attrs arg) */

ATbool PTPT_hasAttrsWsAfterList(PTPT_Attrs arg)
{
  if (PTPT_isAttrsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getAttrsWsAfterBracketOpen(PTPT_Attrs arg) */

PTPT_OptLayout PTPT_getAttrsWsAfterBracketOpen(PTPT_Attrs arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_AttrList PTPT_getAttrsList(PTPT_Attrs arg) */

PTPT_AttrList PTPT_getAttrsList(PTPT_Attrs arg)
{
  
    return (PTPT_AttrList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), 1);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getAttrsWsAfterList(PTPT_Attrs arg) */

PTPT_OptLayout PTPT_getAttrsWsAfterList(PTPT_Attrs arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  PTPT_Attrs PTPT_setAttrsWsAfterBracketOpen(PTPT_Attrs arg, PTPT_OptLayout wsAfterBracketOpen) */

PTPT_Attrs PTPT_setAttrsWsAfterBracketOpen(PTPT_Attrs arg, PTPT_OptLayout wsAfterBracketOpen)
{
  if (PTPT_isAttrsMany(arg)) {
    return (PTPT_Attrs)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 1), 1);
  }

  ATabort("Attrs has no WsAfterBracketOpen: %t\n", arg);
  return (PTPT_Attrs)NULL;
}

/*}}}  */
/*{{{  PTPT_Attrs PTPT_setAttrsList(PTPT_Attrs arg, PTPT_AttrList list) */

PTPT_Attrs PTPT_setAttrsList(PTPT_Attrs arg, PTPT_AttrList list)
{
  if (PTPT_isAttrsMany(arg)) {
    return (PTPT_Attrs)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), (ATerm)((ATerm) list), 1), 2), 1);
  }

  ATabort("Attrs has no List: %t\n", arg);
  return (PTPT_Attrs)NULL;
}

/*}}}  */
/*{{{  PTPT_Attrs PTPT_setAttrsWsAfterList(PTPT_Attrs arg, PTPT_OptLayout wsAfterList) */

PTPT_Attrs PTPT_setAttrsWsAfterList(PTPT_Attrs arg, PTPT_OptLayout wsAfterList)
{
  if (PTPT_isAttrsMany(arg)) {
    return (PTPT_Attrs)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterList), 3), 1);
  }

  ATabort("Attrs has no WsAfterList: %t\n", arg);
  return (PTPT_Attrs)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTPT_Attr accessors */

/*{{{  ATbool PTPT_isValidAttr(PTPT_Attr arg) */

ATbool PTPT_isValidAttr(PTPT_Attr arg)
{
  if (PTPT_isAttrAssoc(arg)) {
    return ATtrue;
  }
  else if (PTPT_isAttrTerm(arg)) {
    return ATtrue;
  }
  else if (PTPT_isAttrId(arg)) {
    return ATtrue;
  }
  else if (PTPT_isAttrBracket(arg)) {
    return ATtrue;
  }
  else if (PTPT_isAttrReject(arg)) {
    return ATtrue;
  }
  else if (PTPT_isAttrPrefer(arg)) {
    return ATtrue;
  }
  else if (PTPT_isAttrAvoid(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isAttrAssoc(PTPT_Attr arg) */

inline ATbool PTPT_isAttrAssoc(PTPT_Attr arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternAttrAssoc, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isAttrTerm(PTPT_Attr arg) */

inline ATbool PTPT_isAttrTerm(PTPT_Attr arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternAttrTerm, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isAttrId(PTPT_Attr arg) */

inline ATbool PTPT_isAttrId(PTPT_Attr arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternAttrId, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isAttrBracket(PTPT_Attr arg) */

inline ATbool PTPT_isAttrBracket(PTPT_Attr arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternAttrBracket);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isAttrReject(PTPT_Attr arg) */

inline ATbool PTPT_isAttrReject(PTPT_Attr arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternAttrReject);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isAttrPrefer(PTPT_Attr arg) */

inline ATbool PTPT_isAttrPrefer(PTPT_Attr arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternAttrPrefer);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isAttrAvoid(PTPT_Attr arg) */

inline ATbool PTPT_isAttrAvoid(PTPT_Attr arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternAttrAvoid);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PTPT_hasAttrWsAfterAssoc(PTPT_Attr arg) */

ATbool PTPT_hasAttrWsAfterAssoc(PTPT_Attr arg)
{
  if (PTPT_isAttrAssoc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasAttrWsAfterParenOpen(PTPT_Attr arg) */

ATbool PTPT_hasAttrWsAfterParenOpen(PTPT_Attr arg)
{
  if (PTPT_isAttrAssoc(arg)) {
    return ATtrue;
  }
  else if (PTPT_isAttrTerm(arg)) {
    return ATtrue;
  }
  else if (PTPT_isAttrId(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasAttrAssociativity(PTPT_Attr arg) */

ATbool PTPT_hasAttrAssociativity(PTPT_Attr arg)
{
  if (PTPT_isAttrAssoc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasAttrWsAfterAssociativity(PTPT_Attr arg) */

ATbool PTPT_hasAttrWsAfterAssociativity(PTPT_Attr arg)
{
  if (PTPT_isAttrAssoc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasAttrWsAfterTerm(PTPT_Attr arg) */

ATbool PTPT_hasAttrWsAfterTerm(PTPT_Attr arg)
{
  if (PTPT_isAttrTerm(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasAttrAterm(PTPT_Attr arg) */

ATbool PTPT_hasAttrAterm(PTPT_Attr arg)
{
  if (PTPT_isAttrTerm(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasAttrWsAfterAterm(PTPT_Attr arg) */

ATbool PTPT_hasAttrWsAfterAterm(PTPT_Attr arg)
{
  if (PTPT_isAttrTerm(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasAttrWsAfterId(PTPT_Attr arg) */

ATbool PTPT_hasAttrWsAfterId(PTPT_Attr arg)
{
  if (PTPT_isAttrId(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasAttrModuleName(PTPT_Attr arg) */

ATbool PTPT_hasAttrModuleName(PTPT_Attr arg)
{
  if (PTPT_isAttrId(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasAttrWsAfterModuleName(PTPT_Attr arg) */

ATbool PTPT_hasAttrWsAfterModuleName(PTPT_Attr arg)
{
  if (PTPT_isAttrId(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getAttrWsAfterAssoc(PTPT_Attr arg) */

PTPT_OptLayout PTPT_getAttrWsAfterAssoc(PTPT_Attr arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getAttrWsAfterParenOpen(PTPT_Attr arg) */

PTPT_OptLayout PTPT_getAttrWsAfterParenOpen(PTPT_Attr arg)
{
  if (PTPT_isAttrAssoc(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (PTPT_isAttrTerm(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  PTPT_Associativity PTPT_getAttrAssociativity(PTPT_Attr arg) */

PTPT_Associativity PTPT_getAttrAssociativity(PTPT_Attr arg)
{
  
    return (PTPT_Associativity)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getAttrWsAfterAssociativity(PTPT_Attr arg) */

PTPT_OptLayout PTPT_getAttrWsAfterAssociativity(PTPT_Attr arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getAttrWsAfterTerm(PTPT_Attr arg) */

PTPT_OptLayout PTPT_getAttrWsAfterTerm(PTPT_Attr arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_ATerm PTPT_getAttrAterm(PTPT_Attr arg) */

PTPT_ATerm PTPT_getAttrAterm(PTPT_Attr arg)
{
  
    return (PTPT_ATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getAttrWsAfterAterm(PTPT_Attr arg) */

PTPT_OptLayout PTPT_getAttrWsAfterAterm(PTPT_Attr arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getAttrWsAfterId(PTPT_Attr arg) */

PTPT_OptLayout PTPT_getAttrWsAfterId(PTPT_Attr arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_StrCon PTPT_getAttrModuleName(PTPT_Attr arg) */

PTPT_StrCon PTPT_getAttrModuleName(PTPT_Attr arg)
{
  
    return (PTPT_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getAttrWsAfterModuleName(PTPT_Attr arg) */

PTPT_OptLayout PTPT_getAttrWsAfterModuleName(PTPT_Attr arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PTPT_Attr PTPT_setAttrWsAfterAssoc(PTPT_Attr arg, PTPT_OptLayout wsAfterAssoc) */

PTPT_Attr PTPT_setAttrWsAfterAssoc(PTPT_Attr arg, PTPT_OptLayout wsAfterAssoc)
{
  if (PTPT_isAttrAssoc(arg)) {
    return (PTPT_Attr)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterAssoc), 1), 1);
  }

  ATabort("Attr has no WsAfterAssoc: %t\n", arg);
  return (PTPT_Attr)NULL;
}

/*}}}  */
/*{{{  PTPT_Attr PTPT_setAttrWsAfterParenOpen(PTPT_Attr arg, PTPT_OptLayout wsAfterParenOpen) */

PTPT_Attr PTPT_setAttrWsAfterParenOpen(PTPT_Attr arg, PTPT_OptLayout wsAfterParenOpen)
{
  if (PTPT_isAttrAssoc(arg)) {
    return (PTPT_Attr)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PTPT_isAttrTerm(arg)) {
    return (PTPT_Attr)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PTPT_isAttrId(arg)) {
    return (PTPT_Attr)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("Attr has no WsAfterParenOpen: %t\n", arg);
  return (PTPT_Attr)NULL;
}

/*}}}  */
/*{{{  PTPT_Attr PTPT_setAttrAssociativity(PTPT_Attr arg, PTPT_Associativity associativity) */

PTPT_Attr PTPT_setAttrAssociativity(PTPT_Attr arg, PTPT_Associativity associativity)
{
  if (PTPT_isAttrAssoc(arg)) {
    return (PTPT_Attr)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) associativity), 4), 1);
  }

  ATabort("Attr has no Associativity: %t\n", arg);
  return (PTPT_Attr)NULL;
}

/*}}}  */
/*{{{  PTPT_Attr PTPT_setAttrWsAfterAssociativity(PTPT_Attr arg, PTPT_OptLayout wsAfterAssociativity) */

PTPT_Attr PTPT_setAttrWsAfterAssociativity(PTPT_Attr arg, PTPT_OptLayout wsAfterAssociativity)
{
  if (PTPT_isAttrAssoc(arg)) {
    return (PTPT_Attr)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterAssociativity), 5), 1);
  }

  ATabort("Attr has no WsAfterAssociativity: %t\n", arg);
  return (PTPT_Attr)NULL;
}

/*}}}  */
/*{{{  PTPT_Attr PTPT_setAttrWsAfterTerm(PTPT_Attr arg, PTPT_OptLayout wsAfterTerm) */

PTPT_Attr PTPT_setAttrWsAfterTerm(PTPT_Attr arg, PTPT_OptLayout wsAfterTerm)
{
  if (PTPT_isAttrTerm(arg)) {
    return (PTPT_Attr)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterTerm), 1), 1);
  }

  ATabort("Attr has no WsAfterTerm: %t\n", arg);
  return (PTPT_Attr)NULL;
}

/*}}}  */
/*{{{  PTPT_Attr PTPT_setAttrAterm(PTPT_Attr arg, PTPT_ATerm aterm) */

PTPT_Attr PTPT_setAttrAterm(PTPT_Attr arg, PTPT_ATerm aterm)
{
  if (PTPT_isAttrTerm(arg)) {
    return (PTPT_Attr)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) aterm), 4), 1);
  }

  ATabort("Attr has no Aterm: %t\n", arg);
  return (PTPT_Attr)NULL;
}

/*}}}  */
/*{{{  PTPT_Attr PTPT_setAttrWsAfterAterm(PTPT_Attr arg, PTPT_OptLayout wsAfterAterm) */

PTPT_Attr PTPT_setAttrWsAfterAterm(PTPT_Attr arg, PTPT_OptLayout wsAfterAterm)
{
  if (PTPT_isAttrTerm(arg)) {
    return (PTPT_Attr)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterAterm), 5), 1);
  }

  ATabort("Attr has no WsAfterAterm: %t\n", arg);
  return (PTPT_Attr)NULL;
}

/*}}}  */
/*{{{  PTPT_Attr PTPT_setAttrWsAfterId(PTPT_Attr arg, PTPT_OptLayout wsAfterId) */

PTPT_Attr PTPT_setAttrWsAfterId(PTPT_Attr arg, PTPT_OptLayout wsAfterId)
{
  if (PTPT_isAttrId(arg)) {
    return (PTPT_Attr)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterId), 1), 1);
  }

  ATabort("Attr has no WsAfterId: %t\n", arg);
  return (PTPT_Attr)NULL;
}

/*}}}  */
/*{{{  PTPT_Attr PTPT_setAttrModuleName(PTPT_Attr arg, PTPT_StrCon moduleName) */

PTPT_Attr PTPT_setAttrModuleName(PTPT_Attr arg, PTPT_StrCon moduleName)
{
  if (PTPT_isAttrId(arg)) {
    return (PTPT_Attr)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) moduleName), 4), 1);
  }

  ATabort("Attr has no ModuleName: %t\n", arg);
  return (PTPT_Attr)NULL;
}

/*}}}  */
/*{{{  PTPT_Attr PTPT_setAttrWsAfterModuleName(PTPT_Attr arg, PTPT_OptLayout wsAfterModuleName) */

PTPT_Attr PTPT_setAttrWsAfterModuleName(PTPT_Attr arg, PTPT_OptLayout wsAfterModuleName)
{
  if (PTPT_isAttrId(arg)) {
    return (PTPT_Attr)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterModuleName), 5), 1);
  }

  ATabort("Attr has no WsAfterModuleName: %t\n", arg);
  return (PTPT_Attr)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTPT_Associativity accessors */

/*{{{  ATbool PTPT_isValidAssociativity(PTPT_Associativity arg) */

ATbool PTPT_isValidAssociativity(PTPT_Associativity arg)
{
  if (PTPT_isAssociativityLeft(arg)) {
    return ATtrue;
  }
  else if (PTPT_isAssociativityRight(arg)) {
    return ATtrue;
  }
  else if (PTPT_isAssociativityAssoc(arg)) {
    return ATtrue;
  }
  else if (PTPT_isAssociativityNonAssoc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isAssociativityLeft(PTPT_Associativity arg) */

inline ATbool PTPT_isAssociativityLeft(PTPT_Associativity arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternAssociativityLeft);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isAssociativityRight(PTPT_Associativity arg) */

inline ATbool PTPT_isAssociativityRight(PTPT_Associativity arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternAssociativityRight);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isAssociativityAssoc(PTPT_Associativity arg) */

inline ATbool PTPT_isAssociativityAssoc(PTPT_Associativity arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternAssociativityAssoc);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isAssociativityNonAssoc(PTPT_Associativity arg) */

inline ATbool PTPT_isAssociativityNonAssoc(PTPT_Associativity arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternAssociativityNonAssoc);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */

/*}}}  */
/*{{{  PTPT_AttrList accessors */

/*{{{  ATbool PTPT_isValidAttrList(PTPT_AttrList arg) */

ATbool PTPT_isValidAttrList(PTPT_AttrList arg)
{
  if (PTPT_isAttrListEmpty(arg)) {
    return ATtrue;
  }
  else if (PTPT_isAttrListSingle(arg)) {
    return ATtrue;
  }
  else if (PTPT_isAttrListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isAttrListEmpty(PTPT_AttrList arg) */

inline ATbool PTPT_isAttrListEmpty(PTPT_AttrList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTPT_patternAttrListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isAttrListSingle(PTPT_AttrList arg) */

inline ATbool PTPT_isAttrListSingle(PTPT_AttrList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternAttrListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isAttrListMany(PTPT_AttrList arg) */

inline ATbool PTPT_isAttrListMany(PTPT_AttrList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternAttrListMany, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PTPT_hasAttrListHead(PTPT_AttrList arg) */

ATbool PTPT_hasAttrListHead(PTPT_AttrList arg)
{
  if (PTPT_isAttrListSingle(arg)) {
    return ATtrue;
  }
  else if (PTPT_isAttrListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasAttrListWsAfterHead(PTPT_AttrList arg) */

ATbool PTPT_hasAttrListWsAfterHead(PTPT_AttrList arg)
{
  if (PTPT_isAttrListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasAttrListWsAfterSep(PTPT_AttrList arg) */

ATbool PTPT_hasAttrListWsAfterSep(PTPT_AttrList arg)
{
  if (PTPT_isAttrListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasAttrListTail(PTPT_AttrList arg) */

ATbool PTPT_hasAttrListTail(PTPT_AttrList arg)
{
  if (PTPT_isAttrListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTPT_AttrList PTPT_getAttrListTail(PTPT_AttrList arg) */

PTPT_AttrList PTPT_getAttrListTail(PTPT_AttrList arg)
{
  assert(!PTPT_isAttrListEmpty(arg) && "getTail on an empty list");
  if (PTPT_isAttrListSingle(arg)) {
    return (PTPT_AttrList) PTPT_makeAttrListEmpty();
  }
  else {
  
    return (PTPT_AttrList)ATgetTail((ATermList)arg, 4);
  }
}

/*}}}  */
/*{{{  PTPT_Attr PTPT_getAttrListHead(PTPT_AttrList arg) */

PTPT_Attr PTPT_getAttrListHead(PTPT_AttrList arg)
{
  if (PTPT_isAttrListSingle(arg)) {
    return (PTPT_Attr)ATgetFirst((ATermList)arg);
  }
  else 
    return (PTPT_Attr)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getAttrListWsAfterHead(PTPT_AttrList arg) */

PTPT_OptLayout PTPT_getAttrListWsAfterHead(PTPT_AttrList arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getAttrListWsAfterSep(PTPT_AttrList arg) */

PTPT_OptLayout PTPT_getAttrListWsAfterSep(PTPT_AttrList arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  PTPT_AttrList PTPT_setAttrListHead(PTPT_AttrList arg, PTPT_Attr head) */

PTPT_AttrList PTPT_setAttrListHead(PTPT_AttrList arg, PTPT_Attr head)
{
  if (PTPT_isAttrListSingle(arg)) {
    return (PTPT_AttrList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (PTPT_isAttrListMany(arg)) {
    return (PTPT_AttrList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("AttrList has no Head: %t\n", arg);
  return (PTPT_AttrList)NULL;
}

/*}}}  */
/*{{{  PTPT_AttrList PTPT_setAttrListWsAfterHead(PTPT_AttrList arg, PTPT_OptLayout wsAfterHead) */

PTPT_AttrList PTPT_setAttrListWsAfterHead(PTPT_AttrList arg, PTPT_OptLayout wsAfterHead)
{
  if (PTPT_isAttrListMany(arg)) {
    return (PTPT_AttrList)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterHead), 1);
  }

  ATabort("AttrList has no WsAfterHead: %t\n", arg);
  return (PTPT_AttrList)NULL;
}

/*}}}  */
/*{{{  PTPT_AttrList PTPT_setAttrListWsAfterSep(PTPT_AttrList arg, PTPT_OptLayout wsAfterSep) */

PTPT_AttrList PTPT_setAttrListWsAfterSep(PTPT_AttrList arg, PTPT_OptLayout wsAfterSep)
{
  if (PTPT_isAttrListMany(arg)) {
    return (PTPT_AttrList)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterSep), 3);
  }

  ATabort("AttrList has no WsAfterSep: %t\n", arg);
  return (PTPT_AttrList)NULL;
}

/*}}}  */
/*{{{  PTPT_AttrList PTPT_setAttrListTail(PTPT_AttrList arg, PTPT_AttrList tail) */

PTPT_AttrList PTPT_setAttrListTail(PTPT_AttrList arg, PTPT_AttrList tail)
{
  if (PTPT_isAttrListMany(arg)) {
    return (PTPT_AttrList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 4);
  }

  ATabort("AttrList has no Tail: %t\n", arg);
  return (PTPT_AttrList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTPT_ParseTree accessors */

/*{{{  ATbool PTPT_isValidParseTree(PTPT_ParseTree arg) */

ATbool PTPT_isValidParseTree(PTPT_ParseTree arg)
{
  if (PTPT_isParseTreeTop(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isParseTreeTop(PTPT_ParseTree arg) */

inline ATbool PTPT_isParseTreeTop(PTPT_ParseTree arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTPT_patternParseTreeTop, NULL, NULL, NULL, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PTPT_hasParseTreeWsAfterParsetree(PTPT_ParseTree arg) */

ATbool PTPT_hasParseTreeWsAfterParsetree(PTPT_ParseTree arg)
{
  if (PTPT_isParseTreeTop(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasParseTreeWsAfterParenOpen(PTPT_ParseTree arg) */

ATbool PTPT_hasParseTreeWsAfterParenOpen(PTPT_ParseTree arg)
{
  if (PTPT_isParseTreeTop(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasParseTreeTop(PTPT_ParseTree arg) */

ATbool PTPT_hasParseTreeTop(PTPT_ParseTree arg)
{
  if (PTPT_isParseTreeTop(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasParseTreeWsAfterTop(PTPT_ParseTree arg) */

ATbool PTPT_hasParseTreeWsAfterTop(PTPT_ParseTree arg)
{
  if (PTPT_isParseTreeTop(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasParseTreeWsAfterComma(PTPT_ParseTree arg) */

ATbool PTPT_hasParseTreeWsAfterComma(PTPT_ParseTree arg)
{
  if (PTPT_isParseTreeTop(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasParseTreeAmbCnt(PTPT_ParseTree arg) */

ATbool PTPT_hasParseTreeAmbCnt(PTPT_ParseTree arg)
{
  if (PTPT_isParseTreeTop(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasParseTreeWsAfterAmbCnt(PTPT_ParseTree arg) */

ATbool PTPT_hasParseTreeWsAfterAmbCnt(PTPT_ParseTree arg)
{
  if (PTPT_isParseTreeTop(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getParseTreeWsAfterParsetree(PTPT_ParseTree arg) */

PTPT_OptLayout PTPT_getParseTreeWsAfterParsetree(PTPT_ParseTree arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getParseTreeWsAfterParenOpen(PTPT_ParseTree arg) */

PTPT_OptLayout PTPT_getParseTreeWsAfterParenOpen(PTPT_ParseTree arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  PTPT_Tree PTPT_getParseTreeTop(PTPT_ParseTree arg) */

PTPT_Tree PTPT_getParseTreeTop(PTPT_ParseTree arg)
{
  
    return (PTPT_Tree)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getParseTreeWsAfterTop(PTPT_ParseTree arg) */

PTPT_OptLayout PTPT_getParseTreeWsAfterTop(PTPT_ParseTree arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getParseTreeWsAfterComma(PTPT_ParseTree arg) */

PTPT_OptLayout PTPT_getParseTreeWsAfterComma(PTPT_ParseTree arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  PTPT_NatCon PTPT_getParseTreeAmbCnt(PTPT_ParseTree arg) */

PTPT_NatCon PTPT_getParseTreeAmbCnt(PTPT_ParseTree arg)
{
  
    return (PTPT_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getParseTreeWsAfterAmbCnt(PTPT_ParseTree arg) */

PTPT_OptLayout PTPT_getParseTreeWsAfterAmbCnt(PTPT_ParseTree arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/*}}}  */
/*{{{  PTPT_ParseTree PTPT_setParseTreeWsAfterParsetree(PTPT_ParseTree arg, PTPT_OptLayout wsAfterParsetree) */

PTPT_ParseTree PTPT_setParseTreeWsAfterParsetree(PTPT_ParseTree arg, PTPT_OptLayout wsAfterParsetree)
{
  if (PTPT_isParseTreeTop(arg)) {
    return (PTPT_ParseTree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParsetree), 1), 1);
  }

  ATabort("ParseTree has no WsAfterParsetree: %t\n", arg);
  return (PTPT_ParseTree)NULL;
}

/*}}}  */
/*{{{  PTPT_ParseTree PTPT_setParseTreeWsAfterParenOpen(PTPT_ParseTree arg, PTPT_OptLayout wsAfterParenOpen) */

PTPT_ParseTree PTPT_setParseTreeWsAfterParenOpen(PTPT_ParseTree arg, PTPT_OptLayout wsAfterParenOpen)
{
  if (PTPT_isParseTreeTop(arg)) {
    return (PTPT_ParseTree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("ParseTree has no WsAfterParenOpen: %t\n", arg);
  return (PTPT_ParseTree)NULL;
}

/*}}}  */
/*{{{  PTPT_ParseTree PTPT_setParseTreeTop(PTPT_ParseTree arg, PTPT_Tree top) */

PTPT_ParseTree PTPT_setParseTreeTop(PTPT_ParseTree arg, PTPT_Tree top)
{
  if (PTPT_isParseTreeTop(arg)) {
    return (PTPT_ParseTree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) top), 4), 1);
  }

  ATabort("ParseTree has no Top: %t\n", arg);
  return (PTPT_ParseTree)NULL;
}

/*}}}  */
/*{{{  PTPT_ParseTree PTPT_setParseTreeWsAfterTop(PTPT_ParseTree arg, PTPT_OptLayout wsAfterTop) */

PTPT_ParseTree PTPT_setParseTreeWsAfterTop(PTPT_ParseTree arg, PTPT_OptLayout wsAfterTop)
{
  if (PTPT_isParseTreeTop(arg)) {
    return (PTPT_ParseTree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterTop), 5), 1);
  }

  ATabort("ParseTree has no WsAfterTop: %t\n", arg);
  return (PTPT_ParseTree)NULL;
}

/*}}}  */
/*{{{  PTPT_ParseTree PTPT_setParseTreeWsAfterComma(PTPT_ParseTree arg, PTPT_OptLayout wsAfterComma) */

PTPT_ParseTree PTPT_setParseTreeWsAfterComma(PTPT_ParseTree arg, PTPT_OptLayout wsAfterComma)
{
  if (PTPT_isParseTreeTop(arg)) {
    return (PTPT_ParseTree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }

  ATabort("ParseTree has no WsAfterComma: %t\n", arg);
  return (PTPT_ParseTree)NULL;
}

/*}}}  */
/*{{{  PTPT_ParseTree PTPT_setParseTreeAmbCnt(PTPT_ParseTree arg, PTPT_NatCon ambCnt) */

PTPT_ParseTree PTPT_setParseTreeAmbCnt(PTPT_ParseTree arg, PTPT_NatCon ambCnt)
{
  if (PTPT_isParseTreeTop(arg)) {
    return (PTPT_ParseTree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ambCnt), 8), 1);
  }

  ATabort("ParseTree has no AmbCnt: %t\n", arg);
  return (PTPT_ParseTree)NULL;
}

/*}}}  */
/*{{{  PTPT_ParseTree PTPT_setParseTreeWsAfterAmbCnt(PTPT_ParseTree arg, PTPT_OptLayout wsAfterAmbCnt) */

PTPT_ParseTree PTPT_setParseTreeWsAfterAmbCnt(PTPT_ParseTree arg, PTPT_OptLayout wsAfterAmbCnt)
{
  if (PTPT_isParseTreeTop(arg)) {
    return (PTPT_ParseTree)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterAmbCnt), 9), 1);
  }

  ATabort("ParseTree has no WsAfterAmbCnt: %t\n", arg);
  return (PTPT_ParseTree)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTPT_Symbol accessors */

/*{{{  ATbool PTPT_isValidSymbol(PTPT_Symbol arg) */

ATbool PTPT_isValidSymbol(PTPT_Symbol arg)
{
  if (PTPT_isSymbolEmpty(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolLit(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolCilit(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolCf(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolLex(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolOpt(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolAlt(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolSeq(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolTuple(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolSort(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolIter(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolIterStar(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolIterSep(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolIterStarSep(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolIterN(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolIterSepN(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolFunc(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolVarsym(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolLayout(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolCharClass(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolStrategy(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolParameterizedSort(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isSymbolEmpty(PTPT_Symbol arg) */

inline ATbool PTPT_isSymbolEmpty(PTPT_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternSymbolEmpty);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isSymbolLit(PTPT_Symbol arg) */

inline ATbool PTPT_isSymbolLit(PTPT_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternSymbolLit, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isSymbolCilit(PTPT_Symbol arg) */

inline ATbool PTPT_isSymbolCilit(PTPT_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternSymbolCilit, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isSymbolCf(PTPT_Symbol arg) */

inline ATbool PTPT_isSymbolCf(PTPT_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternSymbolCf, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isSymbolLex(PTPT_Symbol arg) */

inline ATbool PTPT_isSymbolLex(PTPT_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternSymbolLex, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isSymbolOpt(PTPT_Symbol arg) */

inline ATbool PTPT_isSymbolOpt(PTPT_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternSymbolOpt, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isSymbolAlt(PTPT_Symbol arg) */

inline ATbool PTPT_isSymbolAlt(PTPT_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternSymbolAlt, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isSymbolSeq(PTPT_Symbol arg) */

inline ATbool PTPT_isSymbolSeq(PTPT_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternSymbolSeq, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isSymbolTuple(PTPT_Symbol arg) */

inline ATbool PTPT_isSymbolTuple(PTPT_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternSymbolTuple, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isSymbolSort(PTPT_Symbol arg) */

inline ATbool PTPT_isSymbolSort(PTPT_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternSymbolSort, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isSymbolIter(PTPT_Symbol arg) */

inline ATbool PTPT_isSymbolIter(PTPT_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternSymbolIter, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isSymbolIterStar(PTPT_Symbol arg) */

inline ATbool PTPT_isSymbolIterStar(PTPT_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternSymbolIterStar, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isSymbolIterSep(PTPT_Symbol arg) */

inline ATbool PTPT_isSymbolIterSep(PTPT_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternSymbolIterSep, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isSymbolIterStarSep(PTPT_Symbol arg) */

inline ATbool PTPT_isSymbolIterStarSep(PTPT_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternSymbolIterStarSep, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isSymbolIterN(PTPT_Symbol arg) */

inline ATbool PTPT_isSymbolIterN(PTPT_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternSymbolIterN, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isSymbolIterSepN(PTPT_Symbol arg) */

inline ATbool PTPT_isSymbolIterSepN(PTPT_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternSymbolIterSepN, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isSymbolFunc(PTPT_Symbol arg) */

inline ATbool PTPT_isSymbolFunc(PTPT_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternSymbolFunc, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isSymbolVarsym(PTPT_Symbol arg) */

inline ATbool PTPT_isSymbolVarsym(PTPT_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternSymbolVarsym, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isSymbolLayout(PTPT_Symbol arg) */

inline ATbool PTPT_isSymbolLayout(PTPT_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternSymbolLayout);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isSymbolCharClass(PTPT_Symbol arg) */

inline ATbool PTPT_isSymbolCharClass(PTPT_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternSymbolCharClass, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isSymbolStrategy(PTPT_Symbol arg) */

inline ATbool PTPT_isSymbolStrategy(PTPT_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternSymbolStrategy, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isSymbolParameterizedSort(PTPT_Symbol arg) */

inline ATbool PTPT_isSymbolParameterizedSort(PTPT_Symbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternSymbolParameterizedSort, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolWsAfterLit(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolWsAfterLit(PTPT_Symbol arg)
{
  if (PTPT_isSymbolLit(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolWsAfterParenOpen(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolWsAfterParenOpen(PTPT_Symbol arg)
{
  if (PTPT_isSymbolLit(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolCilit(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolCf(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolLex(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolOpt(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolAlt(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolSeq(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolTuple(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolSort(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolIter(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolIterStar(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolIterSep(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolIterStarSep(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolIterN(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolIterSepN(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolFunc(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolVarsym(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolCharClass(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolStrategy(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolParameterizedSort(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolString(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolString(PTPT_Symbol arg)
{
  if (PTPT_isSymbolLit(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolCilit(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolSort(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolWsAfterString(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolWsAfterString(PTPT_Symbol arg)
{
  if (PTPT_isSymbolLit(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolCilit(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolSort(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolWsAfterCilit(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolWsAfterCilit(PTPT_Symbol arg)
{
  if (PTPT_isSymbolCilit(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolWsAfterCf(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolWsAfterCf(PTPT_Symbol arg)
{
  if (PTPT_isSymbolCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolSymbol(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolSymbol(PTPT_Symbol arg)
{
  if (PTPT_isSymbolCf(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolLex(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolOpt(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolIter(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolIterStar(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolIterSep(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolIterStarSep(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolIterN(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolIterSepN(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolFunc(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolVarsym(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolWsAfterSymbol(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolWsAfterSymbol(PTPT_Symbol arg)
{
  if (PTPT_isSymbolCf(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolLex(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolOpt(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolIter(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolIterStar(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolIterSep(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolIterStarSep(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolIterN(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolIterSepN(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolFunc(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolVarsym(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolWsAfterLex(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolWsAfterLex(PTPT_Symbol arg)
{
  if (PTPT_isSymbolLex(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolWsAfterOpt(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolWsAfterOpt(PTPT_Symbol arg)
{
  if (PTPT_isSymbolOpt(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolWsAfterAlt(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolWsAfterAlt(PTPT_Symbol arg)
{
  if (PTPT_isSymbolAlt(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolLhs(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolLhs(PTPT_Symbol arg)
{
  if (PTPT_isSymbolAlt(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolStrategy(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolWsAfterLhs(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolWsAfterLhs(PTPT_Symbol arg)
{
  if (PTPT_isSymbolAlt(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolStrategy(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolWsAfterComma(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolWsAfterComma(PTPT_Symbol arg)
{
  if (PTPT_isSymbolAlt(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolTuple(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolIterSep(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolIterStarSep(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolIterN(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolFunc(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolStrategy(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolParameterizedSort(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolRhs(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolRhs(PTPT_Symbol arg)
{
  if (PTPT_isSymbolAlt(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolStrategy(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolWsAfterRhs(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolWsAfterRhs(PTPT_Symbol arg)
{
  if (PTPT_isSymbolAlt(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolStrategy(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolWsAfterSeq(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolWsAfterSeq(PTPT_Symbol arg)
{
  if (PTPT_isSymbolSeq(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolSymbols(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolSymbols(PTPT_Symbol arg)
{
  if (PTPT_isSymbolSeq(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolFunc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolWsAfterSymbols(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolWsAfterSymbols(PTPT_Symbol arg)
{
  if (PTPT_isSymbolSeq(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolFunc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolWsAfterTuple(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolWsAfterTuple(PTPT_Symbol arg)
{
  if (PTPT_isSymbolTuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolHead(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolHead(PTPT_Symbol arg)
{
  if (PTPT_isSymbolTuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolWsAfterHead(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolWsAfterHead(PTPT_Symbol arg)
{
  if (PTPT_isSymbolTuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolRest(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolRest(PTPT_Symbol arg)
{
  if (PTPT_isSymbolTuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolWsAfterRest(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolWsAfterRest(PTPT_Symbol arg)
{
  if (PTPT_isSymbolTuple(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolWsAfterSort(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolWsAfterSort(PTPT_Symbol arg)
{
  if (PTPT_isSymbolSort(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolParameterizedSort(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolWsAfterIter(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolWsAfterIter(PTPT_Symbol arg)
{
  if (PTPT_isSymbolIter(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolWsAfterIterStar(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolWsAfterIterStar(PTPT_Symbol arg)
{
  if (PTPT_isSymbolIterStar(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolWsAfterIterSep(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolWsAfterIterSep(PTPT_Symbol arg)
{
  if (PTPT_isSymbolIterSep(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolSeparator(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolSeparator(PTPT_Symbol arg)
{
  if (PTPT_isSymbolIterSep(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolIterStarSep(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolIterSepN(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolWsAfterSeparator(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolWsAfterSeparator(PTPT_Symbol arg)
{
  if (PTPT_isSymbolIterSep(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolIterStarSep(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolIterSepN(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolWsAfterIterStarSep(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolWsAfterIterStarSep(PTPT_Symbol arg)
{
  if (PTPT_isSymbolIterStarSep(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolWsAfterIterN(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolWsAfterIterN(PTPT_Symbol arg)
{
  if (PTPT_isSymbolIterN(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolNumber(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolNumber(PTPT_Symbol arg)
{
  if (PTPT_isSymbolIterN(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolIterSepN(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolWsAfterNumber(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolWsAfterNumber(PTPT_Symbol arg)
{
  if (PTPT_isSymbolIterN(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolIterSepN(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolWsAfterIterSepN(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolWsAfterIterSepN(PTPT_Symbol arg)
{
  if (PTPT_isSymbolIterSepN(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolWsAfterComma1(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolWsAfterComma1(PTPT_Symbol arg)
{
  if (PTPT_isSymbolIterSepN(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolWsAfterComma2(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolWsAfterComma2(PTPT_Symbol arg)
{
  if (PTPT_isSymbolIterSepN(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolWsAfterFunc(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolWsAfterFunc(PTPT_Symbol arg)
{
  if (PTPT_isSymbolFunc(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolWsAfterVarsym(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolWsAfterVarsym(PTPT_Symbol arg)
{
  if (PTPT_isSymbolVarsym(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolWsAfterCharClass(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolWsAfterCharClass(PTPT_Symbol arg)
{
  if (PTPT_isSymbolCharClass(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolCharRanges(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolCharRanges(PTPT_Symbol arg)
{
  if (PTPT_isSymbolCharClass(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolWsAfterCharRanges(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolWsAfterCharRanges(PTPT_Symbol arg)
{
  if (PTPT_isSymbolCharClass(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolWsAfterStrategy(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolWsAfterStrategy(PTPT_Symbol arg)
{
  if (PTPT_isSymbolStrategy(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolWsAfterParameterizedSort(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolWsAfterParameterizedSort(PTPT_Symbol arg)
{
  if (PTPT_isSymbolParameterizedSort(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolSort(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolSort(PTPT_Symbol arg)
{
  if (PTPT_isSymbolParameterizedSort(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolParameters(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolParameters(PTPT_Symbol arg)
{
  if (PTPT_isSymbolParameterizedSort(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolWsAfterParameters(PTPT_Symbol arg) */

ATbool PTPT_hasSymbolWsAfterParameters(PTPT_Symbol arg)
{
  if (PTPT_isSymbolParameterizedSort(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getSymbolWsAfterLit(PTPT_Symbol arg) */

PTPT_OptLayout PTPT_getSymbolWsAfterLit(PTPT_Symbol arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getSymbolWsAfterParenOpen(PTPT_Symbol arg) */

PTPT_OptLayout PTPT_getSymbolWsAfterParenOpen(PTPT_Symbol arg)
{
  if (PTPT_isSymbolLit(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (PTPT_isSymbolCilit(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (PTPT_isSymbolCf(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (PTPT_isSymbolLex(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (PTPT_isSymbolOpt(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (PTPT_isSymbolAlt(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (PTPT_isSymbolSeq(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (PTPT_isSymbolTuple(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (PTPT_isSymbolSort(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (PTPT_isSymbolIter(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (PTPT_isSymbolIterStar(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (PTPT_isSymbolIterSep(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (PTPT_isSymbolIterStarSep(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (PTPT_isSymbolIterN(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (PTPT_isSymbolIterSepN(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (PTPT_isSymbolFunc(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (PTPT_isSymbolVarsym(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (PTPT_isSymbolCharClass(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (PTPT_isSymbolStrategy(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  PTPT_StrCon PTPT_getSymbolString(PTPT_Symbol arg) */

PTPT_StrCon PTPT_getSymbolString(PTPT_Symbol arg)
{
  if (PTPT_isSymbolLit(arg)) {
    return (PTPT_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else if (PTPT_isSymbolCilit(arg)) {
    return (PTPT_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (PTPT_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getSymbolWsAfterString(PTPT_Symbol arg) */

PTPT_OptLayout PTPT_getSymbolWsAfterString(PTPT_Symbol arg)
{
  if (PTPT_isSymbolLit(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else if (PTPT_isSymbolCilit(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else 
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getSymbolWsAfterCilit(PTPT_Symbol arg) */

PTPT_OptLayout PTPT_getSymbolWsAfterCilit(PTPT_Symbol arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getSymbolWsAfterCf(PTPT_Symbol arg) */

PTPT_OptLayout PTPT_getSymbolWsAfterCf(PTPT_Symbol arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_getSymbolSymbol(PTPT_Symbol arg) */

PTPT_Symbol PTPT_getSymbolSymbol(PTPT_Symbol arg)
{
  if (PTPT_isSymbolCf(arg)) {
    return (PTPT_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else if (PTPT_isSymbolLex(arg)) {
    return (PTPT_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else if (PTPT_isSymbolOpt(arg)) {
    return (PTPT_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else if (PTPT_isSymbolIter(arg)) {
    return (PTPT_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else if (PTPT_isSymbolIterStar(arg)) {
    return (PTPT_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else if (PTPT_isSymbolIterSep(arg)) {
    return (PTPT_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else if (PTPT_isSymbolIterStarSep(arg)) {
    return (PTPT_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else if (PTPT_isSymbolIterN(arg)) {
    return (PTPT_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else if (PTPT_isSymbolIterSepN(arg)) {
    return (PTPT_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else if (PTPT_isSymbolFunc(arg)) {
    return (PTPT_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
  }
  else 
    return (PTPT_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getSymbolWsAfterSymbol(PTPT_Symbol arg) */

PTPT_OptLayout PTPT_getSymbolWsAfterSymbol(PTPT_Symbol arg)
{
  if (PTPT_isSymbolCf(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else if (PTPT_isSymbolLex(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else if (PTPT_isSymbolOpt(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else if (PTPT_isSymbolIter(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else if (PTPT_isSymbolIterStar(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else if (PTPT_isSymbolIterSep(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else if (PTPT_isSymbolIterStarSep(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else if (PTPT_isSymbolIterN(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else if (PTPT_isSymbolIterSepN(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else if (PTPT_isSymbolFunc(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
  }
  else 
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getSymbolWsAfterLex(PTPT_Symbol arg) */

PTPT_OptLayout PTPT_getSymbolWsAfterLex(PTPT_Symbol arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getSymbolWsAfterOpt(PTPT_Symbol arg) */

PTPT_OptLayout PTPT_getSymbolWsAfterOpt(PTPT_Symbol arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getSymbolWsAfterAlt(PTPT_Symbol arg) */

PTPT_OptLayout PTPT_getSymbolWsAfterAlt(PTPT_Symbol arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_getSymbolLhs(PTPT_Symbol arg) */

PTPT_Symbol PTPT_getSymbolLhs(PTPT_Symbol arg)
{
  if (PTPT_isSymbolAlt(arg)) {
    return (PTPT_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (PTPT_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getSymbolWsAfterLhs(PTPT_Symbol arg) */

PTPT_OptLayout PTPT_getSymbolWsAfterLhs(PTPT_Symbol arg)
{
  if (PTPT_isSymbolAlt(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else 
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getSymbolWsAfterComma(PTPT_Symbol arg) */

PTPT_OptLayout PTPT_getSymbolWsAfterComma(PTPT_Symbol arg)
{
  if (PTPT_isSymbolAlt(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else if (PTPT_isSymbolTuple(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else if (PTPT_isSymbolIterSep(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else if (PTPT_isSymbolIterStarSep(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else if (PTPT_isSymbolIterN(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else if (PTPT_isSymbolFunc(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else if (PTPT_isSymbolStrategy(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else 
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_getSymbolRhs(PTPT_Symbol arg) */

PTPT_Symbol PTPT_getSymbolRhs(PTPT_Symbol arg)
{
  if (PTPT_isSymbolAlt(arg)) {
    return (PTPT_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
  }
  else 
    return (PTPT_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getSymbolWsAfterRhs(PTPT_Symbol arg) */

PTPT_OptLayout PTPT_getSymbolWsAfterRhs(PTPT_Symbol arg)
{
  if (PTPT_isSymbolAlt(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
  }
  else 
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getSymbolWsAfterSeq(PTPT_Symbol arg) */

PTPT_OptLayout PTPT_getSymbolWsAfterSeq(PTPT_Symbol arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_Symbols PTPT_getSymbolSymbols(PTPT_Symbol arg) */

PTPT_Symbols PTPT_getSymbolSymbols(PTPT_Symbol arg)
{
  if (PTPT_isSymbolSeq(arg)) {
    return (PTPT_Symbols)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (PTPT_Symbols)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getSymbolWsAfterSymbols(PTPT_Symbol arg) */

PTPT_OptLayout PTPT_getSymbolWsAfterSymbols(PTPT_Symbol arg)
{
  if (PTPT_isSymbolSeq(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else 
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getSymbolWsAfterTuple(PTPT_Symbol arg) */

PTPT_OptLayout PTPT_getSymbolWsAfterTuple(PTPT_Symbol arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_getSymbolHead(PTPT_Symbol arg) */

PTPT_Symbol PTPT_getSymbolHead(PTPT_Symbol arg)
{
  
    return (PTPT_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getSymbolWsAfterHead(PTPT_Symbol arg) */

PTPT_OptLayout PTPT_getSymbolWsAfterHead(PTPT_Symbol arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PTPT_Symbols PTPT_getSymbolRest(PTPT_Symbol arg) */

PTPT_Symbols PTPT_getSymbolRest(PTPT_Symbol arg)
{
  
    return (PTPT_Symbols)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getSymbolWsAfterRest(PTPT_Symbol arg) */

PTPT_OptLayout PTPT_getSymbolWsAfterRest(PTPT_Symbol arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getSymbolWsAfterSort(PTPT_Symbol arg) */

PTPT_OptLayout PTPT_getSymbolWsAfterSort(PTPT_Symbol arg)
{
  if (PTPT_isSymbolSort(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else 
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getSymbolWsAfterIter(PTPT_Symbol arg) */

PTPT_OptLayout PTPT_getSymbolWsAfterIter(PTPT_Symbol arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getSymbolWsAfterIterStar(PTPT_Symbol arg) */

PTPT_OptLayout PTPT_getSymbolWsAfterIterStar(PTPT_Symbol arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getSymbolWsAfterIterSep(PTPT_Symbol arg) */

PTPT_OptLayout PTPT_getSymbolWsAfterIterSep(PTPT_Symbol arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_getSymbolSeparator(PTPT_Symbol arg) */

PTPT_Symbol PTPT_getSymbolSeparator(PTPT_Symbol arg)
{
  if (PTPT_isSymbolIterSep(arg)) {
    return (PTPT_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
  }
  else if (PTPT_isSymbolIterStarSep(arg)) {
    return (PTPT_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
  }
  else 
    return (PTPT_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getSymbolWsAfterSeparator(PTPT_Symbol arg) */

PTPT_OptLayout PTPT_getSymbolWsAfterSeparator(PTPT_Symbol arg)
{
  if (PTPT_isSymbolIterSep(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
  }
  else if (PTPT_isSymbolIterStarSep(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
  }
  else 
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getSymbolWsAfterIterStarSep(PTPT_Symbol arg) */

PTPT_OptLayout PTPT_getSymbolWsAfterIterStarSep(PTPT_Symbol arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getSymbolWsAfterIterN(PTPT_Symbol arg) */

PTPT_OptLayout PTPT_getSymbolWsAfterIterN(PTPT_Symbol arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_NatCon PTPT_getSymbolNumber(PTPT_Symbol arg) */

PTPT_NatCon PTPT_getSymbolNumber(PTPT_Symbol arg)
{
  if (PTPT_isSymbolIterN(arg)) {
    return (PTPT_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
  }
  else 
    return (PTPT_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 12);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getSymbolWsAfterNumber(PTPT_Symbol arg) */

PTPT_OptLayout PTPT_getSymbolWsAfterNumber(PTPT_Symbol arg)
{
  if (PTPT_isSymbolIterN(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
  }
  else 
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 13);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getSymbolWsAfterIterSepN(PTPT_Symbol arg) */

PTPT_OptLayout PTPT_getSymbolWsAfterIterSepN(PTPT_Symbol arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getSymbolWsAfterComma1(PTPT_Symbol arg) */

PTPT_OptLayout PTPT_getSymbolWsAfterComma1(PTPT_Symbol arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getSymbolWsAfterComma2(PTPT_Symbol arg) */

PTPT_OptLayout PTPT_getSymbolWsAfterComma2(PTPT_Symbol arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 11);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getSymbolWsAfterFunc(PTPT_Symbol arg) */

PTPT_OptLayout PTPT_getSymbolWsAfterFunc(PTPT_Symbol arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getSymbolWsAfterVarsym(PTPT_Symbol arg) */

PTPT_OptLayout PTPT_getSymbolWsAfterVarsym(PTPT_Symbol arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getSymbolWsAfterCharClass(PTPT_Symbol arg) */

PTPT_OptLayout PTPT_getSymbolWsAfterCharClass(PTPT_Symbol arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_CharRanges PTPT_getSymbolCharRanges(PTPT_Symbol arg) */

PTPT_CharRanges PTPT_getSymbolCharRanges(PTPT_Symbol arg)
{
  
    return (PTPT_CharRanges)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getSymbolWsAfterCharRanges(PTPT_Symbol arg) */

PTPT_OptLayout PTPT_getSymbolWsAfterCharRanges(PTPT_Symbol arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getSymbolWsAfterStrategy(PTPT_Symbol arg) */

PTPT_OptLayout PTPT_getSymbolWsAfterStrategy(PTPT_Symbol arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getSymbolWsAfterParameterizedSort(PTPT_Symbol arg) */

PTPT_OptLayout PTPT_getSymbolWsAfterParameterizedSort(PTPT_Symbol arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_StrCon PTPT_getSymbolSort(PTPT_Symbol arg) */

PTPT_StrCon PTPT_getSymbolSort(PTPT_Symbol arg)
{
  
    return (PTPT_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PTPT_Symbols PTPT_getSymbolParameters(PTPT_Symbol arg) */

PTPT_Symbols PTPT_getSymbolParameters(PTPT_Symbol arg)
{
  
    return (PTPT_Symbols)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getSymbolWsAfterParameters(PTPT_Symbol arg) */

PTPT_OptLayout PTPT_getSymbolWsAfterParameters(PTPT_Symbol arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolWsAfterLit(PTPT_Symbol arg, PTPT_OptLayout wsAfterLit) */

PTPT_Symbol PTPT_setSymbolWsAfterLit(PTPT_Symbol arg, PTPT_OptLayout wsAfterLit)
{
  if (PTPT_isSymbolLit(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLit), 1), 1);
  }

  ATabort("Symbol has no WsAfterLit: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolWsAfterParenOpen(PTPT_Symbol arg, PTPT_OptLayout wsAfterParenOpen) */

PTPT_Symbol PTPT_setSymbolWsAfterParenOpen(PTPT_Symbol arg, PTPT_OptLayout wsAfterParenOpen)
{
  if (PTPT_isSymbolLit(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PTPT_isSymbolCilit(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PTPT_isSymbolCf(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PTPT_isSymbolLex(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PTPT_isSymbolOpt(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PTPT_isSymbolAlt(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PTPT_isSymbolSeq(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PTPT_isSymbolTuple(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PTPT_isSymbolSort(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PTPT_isSymbolIter(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PTPT_isSymbolIterStar(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PTPT_isSymbolIterSep(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PTPT_isSymbolIterStarSep(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PTPT_isSymbolIterN(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PTPT_isSymbolIterSepN(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PTPT_isSymbolFunc(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PTPT_isSymbolVarsym(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PTPT_isSymbolCharClass(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PTPT_isSymbolStrategy(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PTPT_isSymbolParameterizedSort(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("Symbol has no WsAfterParenOpen: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolString(PTPT_Symbol arg, PTPT_StrCon string) */

PTPT_Symbol PTPT_setSymbolString(PTPT_Symbol arg, PTPT_StrCon string)
{
  if (PTPT_isSymbolLit(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) string), 4), 1);
  }
  else if (PTPT_isSymbolCilit(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) string), 4), 1);
  }
  else if (PTPT_isSymbolSort(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) string), 4), 1);
  }

  ATabort("Symbol has no String: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolWsAfterString(PTPT_Symbol arg, PTPT_OptLayout wsAfterString) */

PTPT_Symbol PTPT_setSymbolWsAfterString(PTPT_Symbol arg, PTPT_OptLayout wsAfterString)
{
  if (PTPT_isSymbolLit(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterString), 5), 1);
  }
  else if (PTPT_isSymbolCilit(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterString), 5), 1);
  }
  else if (PTPT_isSymbolSort(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterString), 5), 1);
  }

  ATabort("Symbol has no WsAfterString: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolWsAfterCilit(PTPT_Symbol arg, PTPT_OptLayout wsAfterCilit) */

PTPT_Symbol PTPT_setSymbolWsAfterCilit(PTPT_Symbol arg, PTPT_OptLayout wsAfterCilit)
{
  if (PTPT_isSymbolCilit(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterCilit), 1), 1);
  }

  ATabort("Symbol has no WsAfterCilit: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolWsAfterCf(PTPT_Symbol arg, PTPT_OptLayout wsAfterCf) */

PTPT_Symbol PTPT_setSymbolWsAfterCf(PTPT_Symbol arg, PTPT_OptLayout wsAfterCf)
{
  if (PTPT_isSymbolCf(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterCf), 1), 1);
  }

  ATabort("Symbol has no WsAfterCf: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolSymbol(PTPT_Symbol arg, PTPT_Symbol symbol) */

PTPT_Symbol PTPT_setSymbolSymbol(PTPT_Symbol arg, PTPT_Symbol symbol)
{
  if (PTPT_isSymbolCf(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) symbol), 4), 1);
  }
  else if (PTPT_isSymbolLex(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) symbol), 4), 1);
  }
  else if (PTPT_isSymbolOpt(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) symbol), 4), 1);
  }
  else if (PTPT_isSymbolIter(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) symbol), 4), 1);
  }
  else if (PTPT_isSymbolIterStar(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) symbol), 4), 1);
  }
  else if (PTPT_isSymbolIterSep(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) symbol), 4), 1);
  }
  else if (PTPT_isSymbolIterStarSep(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) symbol), 4), 1);
  }
  else if (PTPT_isSymbolIterN(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) symbol), 4), 1);
  }
  else if (PTPT_isSymbolIterSepN(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) symbol), 4), 1);
  }
  else if (PTPT_isSymbolFunc(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) symbol), 8), 1);
  }
  else if (PTPT_isSymbolVarsym(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) symbol), 4), 1);
  }

  ATabort("Symbol has no Symbol: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolWsAfterSymbol(PTPT_Symbol arg, PTPT_OptLayout wsAfterSymbol) */

PTPT_Symbol PTPT_setSymbolWsAfterSymbol(PTPT_Symbol arg, PTPT_OptLayout wsAfterSymbol)
{
  if (PTPT_isSymbolCf(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSymbol), 5), 1);
  }
  else if (PTPT_isSymbolLex(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSymbol), 5), 1);
  }
  else if (PTPT_isSymbolOpt(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSymbol), 5), 1);
  }
  else if (PTPT_isSymbolIter(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSymbol), 5), 1);
  }
  else if (PTPT_isSymbolIterStar(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSymbol), 5), 1);
  }
  else if (PTPT_isSymbolIterSep(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSymbol), 5), 1);
  }
  else if (PTPT_isSymbolIterStarSep(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSymbol), 5), 1);
  }
  else if (PTPT_isSymbolIterN(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSymbol), 5), 1);
  }
  else if (PTPT_isSymbolIterSepN(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSymbol), 5), 1);
  }
  else if (PTPT_isSymbolFunc(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSymbol), 9), 1);
  }
  else if (PTPT_isSymbolVarsym(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSymbol), 5), 1);
  }

  ATabort("Symbol has no WsAfterSymbol: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolWsAfterLex(PTPT_Symbol arg, PTPT_OptLayout wsAfterLex) */

PTPT_Symbol PTPT_setSymbolWsAfterLex(PTPT_Symbol arg, PTPT_OptLayout wsAfterLex)
{
  if (PTPT_isSymbolLex(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLex), 1), 1);
  }

  ATabort("Symbol has no WsAfterLex: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolWsAfterOpt(PTPT_Symbol arg, PTPT_OptLayout wsAfterOpt) */

PTPT_Symbol PTPT_setSymbolWsAfterOpt(PTPT_Symbol arg, PTPT_OptLayout wsAfterOpt)
{
  if (PTPT_isSymbolOpt(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterOpt), 1), 1);
  }

  ATabort("Symbol has no WsAfterOpt: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolWsAfterAlt(PTPT_Symbol arg, PTPT_OptLayout wsAfterAlt) */

PTPT_Symbol PTPT_setSymbolWsAfterAlt(PTPT_Symbol arg, PTPT_OptLayout wsAfterAlt)
{
  if (PTPT_isSymbolAlt(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterAlt), 1), 1);
  }

  ATabort("Symbol has no WsAfterAlt: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolLhs(PTPT_Symbol arg, PTPT_Symbol lhs) */

PTPT_Symbol PTPT_setSymbolLhs(PTPT_Symbol arg, PTPT_Symbol lhs)
{
  if (PTPT_isSymbolAlt(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) lhs), 4), 1);
  }
  else if (PTPT_isSymbolStrategy(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) lhs), 4), 1);
  }

  ATabort("Symbol has no Lhs: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolWsAfterLhs(PTPT_Symbol arg, PTPT_OptLayout wsAfterLhs) */

PTPT_Symbol PTPT_setSymbolWsAfterLhs(PTPT_Symbol arg, PTPT_OptLayout wsAfterLhs)
{
  if (PTPT_isSymbolAlt(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLhs), 5), 1);
  }
  else if (PTPT_isSymbolStrategy(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLhs), 5), 1);
  }

  ATabort("Symbol has no WsAfterLhs: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolWsAfterComma(PTPT_Symbol arg, PTPT_OptLayout wsAfterComma) */

PTPT_Symbol PTPT_setSymbolWsAfterComma(PTPT_Symbol arg, PTPT_OptLayout wsAfterComma)
{
  if (PTPT_isSymbolAlt(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }
  else if (PTPT_isSymbolTuple(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }
  else if (PTPT_isSymbolIterSep(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }
  else if (PTPT_isSymbolIterStarSep(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }
  else if (PTPT_isSymbolIterN(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }
  else if (PTPT_isSymbolFunc(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }
  else if (PTPT_isSymbolStrategy(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }
  else if (PTPT_isSymbolParameterizedSort(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }

  ATabort("Symbol has no WsAfterComma: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolRhs(PTPT_Symbol arg, PTPT_Symbol rhs) */

PTPT_Symbol PTPT_setSymbolRhs(PTPT_Symbol arg, PTPT_Symbol rhs)
{
  if (PTPT_isSymbolAlt(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) rhs), 8), 1);
  }
  else if (PTPT_isSymbolStrategy(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) rhs), 8), 1);
  }

  ATabort("Symbol has no Rhs: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolWsAfterRhs(PTPT_Symbol arg, PTPT_OptLayout wsAfterRhs) */

PTPT_Symbol PTPT_setSymbolWsAfterRhs(PTPT_Symbol arg, PTPT_OptLayout wsAfterRhs)
{
  if (PTPT_isSymbolAlt(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterRhs), 9), 1);
  }
  else if (PTPT_isSymbolStrategy(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterRhs), 9), 1);
  }

  ATabort("Symbol has no WsAfterRhs: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolWsAfterSeq(PTPT_Symbol arg, PTPT_OptLayout wsAfterSeq) */

PTPT_Symbol PTPT_setSymbolWsAfterSeq(PTPT_Symbol arg, PTPT_OptLayout wsAfterSeq)
{
  if (PTPT_isSymbolSeq(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSeq), 1), 1);
  }

  ATabort("Symbol has no WsAfterSeq: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolSymbols(PTPT_Symbol arg, PTPT_Symbols symbols) */

PTPT_Symbol PTPT_setSymbolSymbols(PTPT_Symbol arg, PTPT_Symbols symbols)
{
  if (PTPT_isSymbolSeq(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) symbols), 4), 1);
  }
  else if (PTPT_isSymbolFunc(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) symbols), 4), 1);
  }

  ATabort("Symbol has no Symbols: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolWsAfterSymbols(PTPT_Symbol arg, PTPT_OptLayout wsAfterSymbols) */

PTPT_Symbol PTPT_setSymbolWsAfterSymbols(PTPT_Symbol arg, PTPT_OptLayout wsAfterSymbols)
{
  if (PTPT_isSymbolSeq(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSymbols), 5), 1);
  }
  else if (PTPT_isSymbolFunc(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSymbols), 5), 1);
  }

  ATabort("Symbol has no WsAfterSymbols: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolWsAfterTuple(PTPT_Symbol arg, PTPT_OptLayout wsAfterTuple) */

PTPT_Symbol PTPT_setSymbolWsAfterTuple(PTPT_Symbol arg, PTPT_OptLayout wsAfterTuple)
{
  if (PTPT_isSymbolTuple(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterTuple), 1), 1);
  }

  ATabort("Symbol has no WsAfterTuple: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolHead(PTPT_Symbol arg, PTPT_Symbol head) */

PTPT_Symbol PTPT_setSymbolHead(PTPT_Symbol arg, PTPT_Symbol head)
{
  if (PTPT_isSymbolTuple(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) head), 4), 1);
  }

  ATabort("Symbol has no Head: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolWsAfterHead(PTPT_Symbol arg, PTPT_OptLayout wsAfterHead) */

PTPT_Symbol PTPT_setSymbolWsAfterHead(PTPT_Symbol arg, PTPT_OptLayout wsAfterHead)
{
  if (PTPT_isSymbolTuple(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterHead), 5), 1);
  }

  ATabort("Symbol has no WsAfterHead: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolRest(PTPT_Symbol arg, PTPT_Symbols rest) */

PTPT_Symbol PTPT_setSymbolRest(PTPT_Symbol arg, PTPT_Symbols rest)
{
  if (PTPT_isSymbolTuple(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) rest), 8), 1);
  }

  ATabort("Symbol has no Rest: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolWsAfterRest(PTPT_Symbol arg, PTPT_OptLayout wsAfterRest) */

PTPT_Symbol PTPT_setSymbolWsAfterRest(PTPT_Symbol arg, PTPT_OptLayout wsAfterRest)
{
  if (PTPT_isSymbolTuple(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterRest), 9), 1);
  }

  ATabort("Symbol has no WsAfterRest: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolWsAfterSort(PTPT_Symbol arg, PTPT_OptLayout wsAfterSort) */

PTPT_Symbol PTPT_setSymbolWsAfterSort(PTPT_Symbol arg, PTPT_OptLayout wsAfterSort)
{
  if (PTPT_isSymbolSort(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSort), 1), 1);
  }
  else if (PTPT_isSymbolParameterizedSort(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSort), 5), 1);
  }

  ATabort("Symbol has no WsAfterSort: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolWsAfterIter(PTPT_Symbol arg, PTPT_OptLayout wsAfterIter) */

PTPT_Symbol PTPT_setSymbolWsAfterIter(PTPT_Symbol arg, PTPT_OptLayout wsAfterIter)
{
  if (PTPT_isSymbolIter(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterIter), 1), 1);
  }

  ATabort("Symbol has no WsAfterIter: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolWsAfterIterStar(PTPT_Symbol arg, PTPT_OptLayout wsAfterIterStar) */

PTPT_Symbol PTPT_setSymbolWsAfterIterStar(PTPT_Symbol arg, PTPT_OptLayout wsAfterIterStar)
{
  if (PTPT_isSymbolIterStar(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterIterStar), 1), 1);
  }

  ATabort("Symbol has no WsAfterIterStar: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolWsAfterIterSep(PTPT_Symbol arg, PTPT_OptLayout wsAfterIterSep) */

PTPT_Symbol PTPT_setSymbolWsAfterIterSep(PTPT_Symbol arg, PTPT_OptLayout wsAfterIterSep)
{
  if (PTPT_isSymbolIterSep(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterIterSep), 1), 1);
  }

  ATabort("Symbol has no WsAfterIterSep: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolSeparator(PTPT_Symbol arg, PTPT_Symbol separator) */

PTPT_Symbol PTPT_setSymbolSeparator(PTPT_Symbol arg, PTPT_Symbol separator)
{
  if (PTPT_isSymbolIterSep(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) separator), 8), 1);
  }
  else if (PTPT_isSymbolIterStarSep(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) separator), 8), 1);
  }
  else if (PTPT_isSymbolIterSepN(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) separator), 8), 1);
  }

  ATabort("Symbol has no Separator: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolWsAfterSeparator(PTPT_Symbol arg, PTPT_OptLayout wsAfterSeparator) */

PTPT_Symbol PTPT_setSymbolWsAfterSeparator(PTPT_Symbol arg, PTPT_OptLayout wsAfterSeparator)
{
  if (PTPT_isSymbolIterSep(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSeparator), 9), 1);
  }
  else if (PTPT_isSymbolIterStarSep(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSeparator), 9), 1);
  }
  else if (PTPT_isSymbolIterSepN(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSeparator), 9), 1);
  }

  ATabort("Symbol has no WsAfterSeparator: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolWsAfterIterStarSep(PTPT_Symbol arg, PTPT_OptLayout wsAfterIterStarSep) */

PTPT_Symbol PTPT_setSymbolWsAfterIterStarSep(PTPT_Symbol arg, PTPT_OptLayout wsAfterIterStarSep)
{
  if (PTPT_isSymbolIterStarSep(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterIterStarSep), 1), 1);
  }

  ATabort("Symbol has no WsAfterIterStarSep: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolWsAfterIterN(PTPT_Symbol arg, PTPT_OptLayout wsAfterIterN) */

PTPT_Symbol PTPT_setSymbolWsAfterIterN(PTPT_Symbol arg, PTPT_OptLayout wsAfterIterN)
{
  if (PTPT_isSymbolIterN(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterIterN), 1), 1);
  }

  ATabort("Symbol has no WsAfterIterN: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolNumber(PTPT_Symbol arg, PTPT_NatCon number) */

PTPT_Symbol PTPT_setSymbolNumber(PTPT_Symbol arg, PTPT_NatCon number)
{
  if (PTPT_isSymbolIterN(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) number), 8), 1);
  }
  else if (PTPT_isSymbolIterSepN(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) number), 12), 1);
  }

  ATabort("Symbol has no Number: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolWsAfterNumber(PTPT_Symbol arg, PTPT_OptLayout wsAfterNumber) */

PTPT_Symbol PTPT_setSymbolWsAfterNumber(PTPT_Symbol arg, PTPT_OptLayout wsAfterNumber)
{
  if (PTPT_isSymbolIterN(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterNumber), 9), 1);
  }
  else if (PTPT_isSymbolIterSepN(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterNumber), 13), 1);
  }

  ATabort("Symbol has no WsAfterNumber: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolWsAfterIterSepN(PTPT_Symbol arg, PTPT_OptLayout wsAfterIterSepN) */

PTPT_Symbol PTPT_setSymbolWsAfterIterSepN(PTPT_Symbol arg, PTPT_OptLayout wsAfterIterSepN)
{
  if (PTPT_isSymbolIterSepN(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterIterSepN), 1), 1);
  }

  ATabort("Symbol has no WsAfterIterSepN: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolWsAfterComma1(PTPT_Symbol arg, PTPT_OptLayout wsAfterComma1) */

PTPT_Symbol PTPT_setSymbolWsAfterComma1(PTPT_Symbol arg, PTPT_OptLayout wsAfterComma1)
{
  if (PTPT_isSymbolIterSepN(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma1), 7), 1);
  }

  ATabort("Symbol has no WsAfterComma1: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolWsAfterComma2(PTPT_Symbol arg, PTPT_OptLayout wsAfterComma2) */

PTPT_Symbol PTPT_setSymbolWsAfterComma2(PTPT_Symbol arg, PTPT_OptLayout wsAfterComma2)
{
  if (PTPT_isSymbolIterSepN(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma2), 11), 1);
  }

  ATabort("Symbol has no WsAfterComma2: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolWsAfterFunc(PTPT_Symbol arg, PTPT_OptLayout wsAfterFunc) */

PTPT_Symbol PTPT_setSymbolWsAfterFunc(PTPT_Symbol arg, PTPT_OptLayout wsAfterFunc)
{
  if (PTPT_isSymbolFunc(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterFunc), 1), 1);
  }

  ATabort("Symbol has no WsAfterFunc: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolWsAfterVarsym(PTPT_Symbol arg, PTPT_OptLayout wsAfterVarsym) */

PTPT_Symbol PTPT_setSymbolWsAfterVarsym(PTPT_Symbol arg, PTPT_OptLayout wsAfterVarsym)
{
  if (PTPT_isSymbolVarsym(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterVarsym), 1), 1);
  }

  ATabort("Symbol has no WsAfterVarsym: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolWsAfterCharClass(PTPT_Symbol arg, PTPT_OptLayout wsAfterCharClass) */

PTPT_Symbol PTPT_setSymbolWsAfterCharClass(PTPT_Symbol arg, PTPT_OptLayout wsAfterCharClass)
{
  if (PTPT_isSymbolCharClass(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterCharClass), 1), 1);
  }

  ATabort("Symbol has no WsAfterCharClass: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolCharRanges(PTPT_Symbol arg, PTPT_CharRanges CharRanges) */

PTPT_Symbol PTPT_setSymbolCharRanges(PTPT_Symbol arg, PTPT_CharRanges CharRanges)
{
  if (PTPT_isSymbolCharClass(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) CharRanges), 4), 1);
  }

  ATabort("Symbol has no CharRanges: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolWsAfterCharRanges(PTPT_Symbol arg, PTPT_OptLayout wsAfterCharRanges) */

PTPT_Symbol PTPT_setSymbolWsAfterCharRanges(PTPT_Symbol arg, PTPT_OptLayout wsAfterCharRanges)
{
  if (PTPT_isSymbolCharClass(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterCharRanges), 5), 1);
  }

  ATabort("Symbol has no WsAfterCharRanges: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolWsAfterStrategy(PTPT_Symbol arg, PTPT_OptLayout wsAfterStrategy) */

PTPT_Symbol PTPT_setSymbolWsAfterStrategy(PTPT_Symbol arg, PTPT_OptLayout wsAfterStrategy)
{
  if (PTPT_isSymbolStrategy(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterStrategy), 1), 1);
  }

  ATabort("Symbol has no WsAfterStrategy: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolWsAfterParameterizedSort(PTPT_Symbol arg, PTPT_OptLayout wsAfterParameterizedSort) */

PTPT_Symbol PTPT_setSymbolWsAfterParameterizedSort(PTPT_Symbol arg, PTPT_OptLayout wsAfterParameterizedSort)
{
  if (PTPT_isSymbolParameterizedSort(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParameterizedSort), 1), 1);
  }

  ATabort("Symbol has no WsAfterParameterizedSort: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolSort(PTPT_Symbol arg, PTPT_StrCon sort) */

PTPT_Symbol PTPT_setSymbolSort(PTPT_Symbol arg, PTPT_StrCon sort)
{
  if (PTPT_isSymbolParameterizedSort(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) sort), 4), 1);
  }

  ATabort("Symbol has no Sort: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolParameters(PTPT_Symbol arg, PTPT_Symbols parameters) */

PTPT_Symbol PTPT_setSymbolParameters(PTPT_Symbol arg, PTPT_Symbols parameters)
{
  if (PTPT_isSymbolParameterizedSort(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) parameters), 8), 1);
  }

  ATabort("Symbol has no Parameters: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_setSymbolWsAfterParameters(PTPT_Symbol arg, PTPT_OptLayout wsAfterParameters) */

PTPT_Symbol PTPT_setSymbolWsAfterParameters(PTPT_Symbol arg, PTPT_OptLayout wsAfterParameters)
{
  if (PTPT_isSymbolParameterizedSort(arg)) {
    return (PTPT_Symbol)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParameters), 9), 1);
  }

  ATabort("Symbol has no WsAfterParameters: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTPT_Symbols accessors */

/*{{{  ATbool PTPT_isValidSymbols(PTPT_Symbols arg) */

ATbool PTPT_isValidSymbols(PTPT_Symbols arg)
{
  if (PTPT_isSymbolsList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isSymbolsList(PTPT_Symbols arg) */

inline ATbool PTPT_isSymbolsList(PTPT_Symbols arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTPT_patternSymbolsList, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolsWsAfterBracketOpen(PTPT_Symbols arg) */

ATbool PTPT_hasSymbolsWsAfterBracketOpen(PTPT_Symbols arg)
{
  if (PTPT_isSymbolsList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolsList(PTPT_Symbols arg) */

ATbool PTPT_hasSymbolsList(PTPT_Symbols arg)
{
  if (PTPT_isSymbolsList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolsWsAfterList(PTPT_Symbols arg) */

ATbool PTPT_hasSymbolsWsAfterList(PTPT_Symbols arg)
{
  if (PTPT_isSymbolsList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getSymbolsWsAfterBracketOpen(PTPT_Symbols arg) */

PTPT_OptLayout PTPT_getSymbolsWsAfterBracketOpen(PTPT_Symbols arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_SymbolList PTPT_getSymbolsList(PTPT_Symbols arg) */

PTPT_SymbolList PTPT_getSymbolsList(PTPT_Symbols arg)
{
  
    return (PTPT_SymbolList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), 1);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getSymbolsWsAfterList(PTPT_Symbols arg) */

PTPT_OptLayout PTPT_getSymbolsWsAfterList(PTPT_Symbols arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  PTPT_Symbols PTPT_setSymbolsWsAfterBracketOpen(PTPT_Symbols arg, PTPT_OptLayout wsAfterBracketOpen) */

PTPT_Symbols PTPT_setSymbolsWsAfterBracketOpen(PTPT_Symbols arg, PTPT_OptLayout wsAfterBracketOpen)
{
  if (PTPT_isSymbolsList(arg)) {
    return (PTPT_Symbols)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 1), 1);
  }

  ATabort("Symbols has no WsAfterBracketOpen: %t\n", arg);
  return (PTPT_Symbols)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbols PTPT_setSymbolsList(PTPT_Symbols arg, PTPT_SymbolList list) */

PTPT_Symbols PTPT_setSymbolsList(PTPT_Symbols arg, PTPT_SymbolList list)
{
  if (PTPT_isSymbolsList(arg)) {
    return (PTPT_Symbols)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), (ATerm)((ATerm) list), 1), 2), 1);
  }

  ATabort("Symbols has no List: %t\n", arg);
  return (PTPT_Symbols)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbols PTPT_setSymbolsWsAfterList(PTPT_Symbols arg, PTPT_OptLayout wsAfterList) */

PTPT_Symbols PTPT_setSymbolsWsAfterList(PTPT_Symbols arg, PTPT_OptLayout wsAfterList)
{
  if (PTPT_isSymbolsList(arg)) {
    return (PTPT_Symbols)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterList), 3), 1);
  }

  ATabort("Symbols has no WsAfterList: %t\n", arg);
  return (PTPT_Symbols)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTPT_CharRanges accessors */

/*{{{  ATbool PTPT_isValidCharRanges(PTPT_CharRanges arg) */

ATbool PTPT_isValidCharRanges(PTPT_CharRanges arg)
{
  if (PTPT_isCharRangesList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isCharRangesList(PTPT_CharRanges arg) */

inline ATbool PTPT_isCharRangesList(PTPT_CharRanges arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTPT_patternCharRangesList, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PTPT_hasCharRangesWsAfterBracketOpen(PTPT_CharRanges arg) */

ATbool PTPT_hasCharRangesWsAfterBracketOpen(PTPT_CharRanges arg)
{
  if (PTPT_isCharRangesList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasCharRangesList(PTPT_CharRanges arg) */

ATbool PTPT_hasCharRangesList(PTPT_CharRanges arg)
{
  if (PTPT_isCharRangesList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasCharRangesWsAfterList(PTPT_CharRanges arg) */

ATbool PTPT_hasCharRangesWsAfterList(PTPT_CharRanges arg)
{
  if (PTPT_isCharRangesList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getCharRangesWsAfterBracketOpen(PTPT_CharRanges arg) */

PTPT_OptLayout PTPT_getCharRangesWsAfterBracketOpen(PTPT_CharRanges arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_CharRangeList PTPT_getCharRangesList(PTPT_CharRanges arg) */

PTPT_CharRangeList PTPT_getCharRangesList(PTPT_CharRanges arg)
{
  
    return (PTPT_CharRangeList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), 1);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getCharRangesWsAfterList(PTPT_CharRanges arg) */

PTPT_OptLayout PTPT_getCharRangesWsAfterList(PTPT_CharRanges arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  PTPT_CharRanges PTPT_setCharRangesWsAfterBracketOpen(PTPT_CharRanges arg, PTPT_OptLayout wsAfterBracketOpen) */

PTPT_CharRanges PTPT_setCharRangesWsAfterBracketOpen(PTPT_CharRanges arg, PTPT_OptLayout wsAfterBracketOpen)
{
  if (PTPT_isCharRangesList(arg)) {
    return (PTPT_CharRanges)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 1), 1);
  }

  ATabort("CharRanges has no WsAfterBracketOpen: %t\n", arg);
  return (PTPT_CharRanges)NULL;
}

/*}}}  */
/*{{{  PTPT_CharRanges PTPT_setCharRangesList(PTPT_CharRanges arg, PTPT_CharRangeList list) */

PTPT_CharRanges PTPT_setCharRangesList(PTPT_CharRanges arg, PTPT_CharRangeList list)
{
  if (PTPT_isCharRangesList(arg)) {
    return (PTPT_CharRanges)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), (ATerm)((ATerm) list), 1), 2), 1);
  }

  ATabort("CharRanges has no List: %t\n", arg);
  return (PTPT_CharRanges)NULL;
}

/*}}}  */
/*{{{  PTPT_CharRanges PTPT_setCharRangesWsAfterList(PTPT_CharRanges arg, PTPT_OptLayout wsAfterList) */

PTPT_CharRanges PTPT_setCharRangesWsAfterList(PTPT_CharRanges arg, PTPT_OptLayout wsAfterList)
{
  if (PTPT_isCharRangesList(arg)) {
    return (PTPT_CharRanges)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterList), 3), 1);
  }

  ATabort("CharRanges has no WsAfterList: %t\n", arg);
  return (PTPT_CharRanges)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTPT_CharRange accessors */

/*{{{  ATbool PTPT_isValidCharRange(PTPT_CharRange arg) */

ATbool PTPT_isValidCharRange(PTPT_CharRange arg)
{
  if (PTPT_isCharRangeCharacter(arg)) {
    return ATtrue;
  }
  else if (PTPT_isCharRangeRange(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isCharRangeCharacter(PTPT_CharRange arg) */

inline ATbool PTPT_isCharRangeCharacter(PTPT_CharRange arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternCharRangeCharacter, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isCharRangeRange(PTPT_CharRange arg) */

inline ATbool PTPT_isCharRangeRange(PTPT_CharRange arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternCharRangeRange, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PTPT_hasCharRangeInteger(PTPT_CharRange arg) */

ATbool PTPT_hasCharRangeInteger(PTPT_CharRange arg)
{
  if (PTPT_isCharRangeCharacter(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasCharRangeWsAfterRange(PTPT_CharRange arg) */

ATbool PTPT_hasCharRangeWsAfterRange(PTPT_CharRange arg)
{
  if (PTPT_isCharRangeRange(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasCharRangeWsAfterParenOpen(PTPT_CharRange arg) */

ATbool PTPT_hasCharRangeWsAfterParenOpen(PTPT_CharRange arg)
{
  if (PTPT_isCharRangeRange(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasCharRangeStart(PTPT_CharRange arg) */

ATbool PTPT_hasCharRangeStart(PTPT_CharRange arg)
{
  if (PTPT_isCharRangeRange(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasCharRangeWsAfterStart(PTPT_CharRange arg) */

ATbool PTPT_hasCharRangeWsAfterStart(PTPT_CharRange arg)
{
  if (PTPT_isCharRangeRange(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasCharRangeWsAfterComma(PTPT_CharRange arg) */

ATbool PTPT_hasCharRangeWsAfterComma(PTPT_CharRange arg)
{
  if (PTPT_isCharRangeRange(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasCharRangeEnd(PTPT_CharRange arg) */

ATbool PTPT_hasCharRangeEnd(PTPT_CharRange arg)
{
  if (PTPT_isCharRangeRange(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasCharRangeWsAfterEnd(PTPT_CharRange arg) */

ATbool PTPT_hasCharRangeWsAfterEnd(PTPT_CharRange arg)
{
  if (PTPT_isCharRangeRange(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTPT_NatCon PTPT_getCharRangeInteger(PTPT_CharRange arg) */

PTPT_NatCon PTPT_getCharRangeInteger(PTPT_CharRange arg)
{
  
    return (PTPT_NatCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getCharRangeWsAfterRange(PTPT_CharRange arg) */

PTPT_OptLayout PTPT_getCharRangeWsAfterRange(PTPT_CharRange arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getCharRangeWsAfterParenOpen(PTPT_CharRange arg) */

PTPT_OptLayout PTPT_getCharRangeWsAfterParenOpen(PTPT_CharRange arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  PTPT_NatCon PTPT_getCharRangeStart(PTPT_CharRange arg) */

PTPT_NatCon PTPT_getCharRangeStart(PTPT_CharRange arg)
{
  
    return (PTPT_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getCharRangeWsAfterStart(PTPT_CharRange arg) */

PTPT_OptLayout PTPT_getCharRangeWsAfterStart(PTPT_CharRange arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getCharRangeWsAfterComma(PTPT_CharRange arg) */

PTPT_OptLayout PTPT_getCharRangeWsAfterComma(PTPT_CharRange arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  PTPT_NatCon PTPT_getCharRangeEnd(PTPT_CharRange arg) */

PTPT_NatCon PTPT_getCharRangeEnd(PTPT_CharRange arg)
{
  
    return (PTPT_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getCharRangeWsAfterEnd(PTPT_CharRange arg) */

PTPT_OptLayout PTPT_getCharRangeWsAfterEnd(PTPT_CharRange arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/*}}}  */
/*{{{  PTPT_CharRange PTPT_setCharRangeInteger(PTPT_CharRange arg, PTPT_NatCon integer) */

PTPT_CharRange PTPT_setCharRangeInteger(PTPT_CharRange arg, PTPT_NatCon integer)
{
  if (PTPT_isCharRangeCharacter(arg)) {
    return (PTPT_CharRange)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) integer), 0), 1);
  }

  ATabort("CharRange has no Integer: %t\n", arg);
  return (PTPT_CharRange)NULL;
}

/*}}}  */
/*{{{  PTPT_CharRange PTPT_setCharRangeWsAfterRange(PTPT_CharRange arg, PTPT_OptLayout wsAfterRange) */

PTPT_CharRange PTPT_setCharRangeWsAfterRange(PTPT_CharRange arg, PTPT_OptLayout wsAfterRange)
{
  if (PTPT_isCharRangeRange(arg)) {
    return (PTPT_CharRange)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterRange), 1), 1);
  }

  ATabort("CharRange has no WsAfterRange: %t\n", arg);
  return (PTPT_CharRange)NULL;
}

/*}}}  */
/*{{{  PTPT_CharRange PTPT_setCharRangeWsAfterParenOpen(PTPT_CharRange arg, PTPT_OptLayout wsAfterParenOpen) */

PTPT_CharRange PTPT_setCharRangeWsAfterParenOpen(PTPT_CharRange arg, PTPT_OptLayout wsAfterParenOpen)
{
  if (PTPT_isCharRangeRange(arg)) {
    return (PTPT_CharRange)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("CharRange has no WsAfterParenOpen: %t\n", arg);
  return (PTPT_CharRange)NULL;
}

/*}}}  */
/*{{{  PTPT_CharRange PTPT_setCharRangeStart(PTPT_CharRange arg, PTPT_NatCon start) */

PTPT_CharRange PTPT_setCharRangeStart(PTPT_CharRange arg, PTPT_NatCon start)
{
  if (PTPT_isCharRangeRange(arg)) {
    return (PTPT_CharRange)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) start), 4), 1);
  }

  ATabort("CharRange has no Start: %t\n", arg);
  return (PTPT_CharRange)NULL;
}

/*}}}  */
/*{{{  PTPT_CharRange PTPT_setCharRangeWsAfterStart(PTPT_CharRange arg, PTPT_OptLayout wsAfterStart) */

PTPT_CharRange PTPT_setCharRangeWsAfterStart(PTPT_CharRange arg, PTPT_OptLayout wsAfterStart)
{
  if (PTPT_isCharRangeRange(arg)) {
    return (PTPT_CharRange)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterStart), 5), 1);
  }

  ATabort("CharRange has no WsAfterStart: %t\n", arg);
  return (PTPT_CharRange)NULL;
}

/*}}}  */
/*{{{  PTPT_CharRange PTPT_setCharRangeWsAfterComma(PTPT_CharRange arg, PTPT_OptLayout wsAfterComma) */

PTPT_CharRange PTPT_setCharRangeWsAfterComma(PTPT_CharRange arg, PTPT_OptLayout wsAfterComma)
{
  if (PTPT_isCharRangeRange(arg)) {
    return (PTPT_CharRange)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }

  ATabort("CharRange has no WsAfterComma: %t\n", arg);
  return (PTPT_CharRange)NULL;
}

/*}}}  */
/*{{{  PTPT_CharRange PTPT_setCharRangeEnd(PTPT_CharRange arg, PTPT_NatCon end) */

PTPT_CharRange PTPT_setCharRangeEnd(PTPT_CharRange arg, PTPT_NatCon end)
{
  if (PTPT_isCharRangeRange(arg)) {
    return (PTPT_CharRange)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) end), 8), 1);
  }

  ATabort("CharRange has no End: %t\n", arg);
  return (PTPT_CharRange)NULL;
}

/*}}}  */
/*{{{  PTPT_CharRange PTPT_setCharRangeWsAfterEnd(PTPT_CharRange arg, PTPT_OptLayout wsAfterEnd) */

PTPT_CharRange PTPT_setCharRangeWsAfterEnd(PTPT_CharRange arg, PTPT_OptLayout wsAfterEnd)
{
  if (PTPT_isCharRangeRange(arg)) {
    return (PTPT_CharRange)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterEnd), 9), 1);
  }

  ATabort("CharRange has no WsAfterEnd: %t\n", arg);
  return (PTPT_CharRange)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTPT_Start accessors */

/*{{{  ATbool PTPT_isValidStart(PTPT_Start arg) */

ATbool PTPT_isValidStart(PTPT_Start arg)
{
  if (PTPT_isStartSymbol(arg)) {
    return ATtrue;
  }
  else if (PTPT_isStartTree(arg)) {
    return ATtrue;
  }
  else if (PTPT_isStartATerm(arg)) {
    return ATtrue;
  }
  else if (PTPT_isStartIntCon(arg)) {
    return ATtrue;
  }
  else if (PTPT_isStartRealCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isStartSymbol(PTPT_Start arg) */

inline ATbool PTPT_isStartSymbol(PTPT_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternStartSymbol, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isStartTree(PTPT_Start arg) */

inline ATbool PTPT_isStartTree(PTPT_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternStartTree, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isStartATerm(PTPT_Start arg) */

inline ATbool PTPT_isStartATerm(PTPT_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternStartATerm, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isStartIntCon(PTPT_Start arg) */

inline ATbool PTPT_isStartIntCon(PTPT_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternStartIntCon, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isStartRealCon(PTPT_Start arg) */

inline ATbool PTPT_isStartRealCon(PTPT_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternStartRealCon, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PTPT_hasStartWsBefore(PTPT_Start arg) */

ATbool PTPT_hasStartWsBefore(PTPT_Start arg)
{
  if (PTPT_isStartSymbol(arg)) {
    return ATtrue;
  }
  else if (PTPT_isStartTree(arg)) {
    return ATtrue;
  }
  else if (PTPT_isStartATerm(arg)) {
    return ATtrue;
  }
  else if (PTPT_isStartIntCon(arg)) {
    return ATtrue;
  }
  else if (PTPT_isStartRealCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasStartTopSymbol(PTPT_Start arg) */

ATbool PTPT_hasStartTopSymbol(PTPT_Start arg)
{
  if (PTPT_isStartSymbol(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasStartWsAfter(PTPT_Start arg) */

ATbool PTPT_hasStartWsAfter(PTPT_Start arg)
{
  if (PTPT_isStartSymbol(arg)) {
    return ATtrue;
  }
  else if (PTPT_isStartTree(arg)) {
    return ATtrue;
  }
  else if (PTPT_isStartATerm(arg)) {
    return ATtrue;
  }
  else if (PTPT_isStartIntCon(arg)) {
    return ATtrue;
  }
  else if (PTPT_isStartRealCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasStartAmbCnt(PTPT_Start arg) */

ATbool PTPT_hasStartAmbCnt(PTPT_Start arg)
{
  if (PTPT_isStartSymbol(arg)) {
    return ATtrue;
  }
  else if (PTPT_isStartTree(arg)) {
    return ATtrue;
  }
  else if (PTPT_isStartATerm(arg)) {
    return ATtrue;
  }
  else if (PTPT_isStartIntCon(arg)) {
    return ATtrue;
  }
  else if (PTPT_isStartRealCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasStartTopTree(PTPT_Start arg) */

ATbool PTPT_hasStartTopTree(PTPT_Start arg)
{
  if (PTPT_isStartTree(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasStartTopATerm(PTPT_Start arg) */

ATbool PTPT_hasStartTopATerm(PTPT_Start arg)
{
  if (PTPT_isStartATerm(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasStartTopIntCon(PTPT_Start arg) */

ATbool PTPT_hasStartTopIntCon(PTPT_Start arg)
{
  if (PTPT_isStartIntCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasStartTopRealCon(PTPT_Start arg) */

ATbool PTPT_hasStartTopRealCon(PTPT_Start arg)
{
  if (PTPT_isStartRealCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getStartWsBefore(PTPT_Start arg) */

PTPT_OptLayout PTPT_getStartWsBefore(PTPT_Start arg)
{
  if (PTPT_isStartSymbol(arg)) {
    return (PTPT_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (PTPT_isStartTree(arg)) {
    return (PTPT_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (PTPT_isStartATerm(arg)) {
    return (PTPT_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (PTPT_isStartIntCon(arg)) {
    return (PTPT_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else 
    return (PTPT_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_getStartTopSymbol(PTPT_Start arg) */

PTPT_Symbol PTPT_getStartTopSymbol(PTPT_Start arg)
{
  
    return (PTPT_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getStartWsAfter(PTPT_Start arg) */

PTPT_OptLayout PTPT_getStartWsAfter(PTPT_Start arg)
{
  if (PTPT_isStartSymbol(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (PTPT_isStartTree(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (PTPT_isStartATerm(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (PTPT_isStartIntCon(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else 
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
}

/*}}}  */
/*{{{  int PTPT_getStartAmbCnt(PTPT_Start arg) */

int PTPT_getStartAmbCnt(PTPT_Start arg)
{
  if (PTPT_isStartSymbol(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else if (PTPT_isStartTree(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else if (PTPT_isStartATerm(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else if (PTPT_isStartIntCon(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  PTPT_Tree PTPT_getStartTopTree(PTPT_Start arg) */

PTPT_Tree PTPT_getStartTopTree(PTPT_Start arg)
{
  
    return (PTPT_Tree)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  PTPT_ATerm PTPT_getStartTopATerm(PTPT_Start arg) */

PTPT_ATerm PTPT_getStartTopATerm(PTPT_Start arg)
{
  
    return (PTPT_ATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  PTPT_IntCon PTPT_getStartTopIntCon(PTPT_Start arg) */

PTPT_IntCon PTPT_getStartTopIntCon(PTPT_Start arg)
{
  
    return (PTPT_IntCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  PTPT_RealCon PTPT_getStartTopRealCon(PTPT_Start arg) */

PTPT_RealCon PTPT_getStartTopRealCon(PTPT_Start arg)
{
  
    return (PTPT_RealCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  PTPT_Start PTPT_setStartWsBefore(PTPT_Start arg, PTPT_OptLayout wsBefore) */

PTPT_Start PTPT_setStartWsBefore(PTPT_Start arg, PTPT_OptLayout wsBefore)
{
  if (PTPT_isStartSymbol(arg)) {
    return (PTPT_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (PTPT_isStartTree(arg)) {
    return (PTPT_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (PTPT_isStartATerm(arg)) {
    return (PTPT_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (PTPT_isStartIntCon(arg)) {
    return (PTPT_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (PTPT_isStartRealCon(arg)) {
    return (PTPT_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }

  ATabort("Start has no WsBefore: %t\n", arg);
  return (PTPT_Start)NULL;
}

/*}}}  */
/*{{{  PTPT_Start PTPT_setStartTopSymbol(PTPT_Start arg, PTPT_Symbol topSymbol) */

PTPT_Start PTPT_setStartTopSymbol(PTPT_Start arg, PTPT_Symbol topSymbol)
{
  if (PTPT_isStartSymbol(arg)) {
    return (PTPT_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topSymbol), 1), 1), 0);
  }

  ATabort("Start has no TopSymbol: %t\n", arg);
  return (PTPT_Start)NULL;
}

/*}}}  */
/*{{{  PTPT_Start PTPT_setStartWsAfter(PTPT_Start arg, PTPT_OptLayout wsAfter) */

PTPT_Start PTPT_setStartWsAfter(PTPT_Start arg, PTPT_OptLayout wsAfter)
{
  if (PTPT_isStartSymbol(arg)) {
    return (PTPT_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (PTPT_isStartTree(arg)) {
    return (PTPT_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (PTPT_isStartATerm(arg)) {
    return (PTPT_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (PTPT_isStartIntCon(arg)) {
    return (PTPT_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (PTPT_isStartRealCon(arg)) {
    return (PTPT_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }

  ATabort("Start has no WsAfter: %t\n", arg);
  return (PTPT_Start)NULL;
}

/*}}}  */
/*{{{  PTPT_Start PTPT_setStartAmbCnt(PTPT_Start arg, int ambCnt) */

PTPT_Start PTPT_setStartAmbCnt(PTPT_Start arg, int ambCnt)
{
  if (PTPT_isStartSymbol(arg)) {
    return (PTPT_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (PTPT_isStartTree(arg)) {
    return (PTPT_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (PTPT_isStartATerm(arg)) {
    return (PTPT_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (PTPT_isStartIntCon(arg)) {
    return (PTPT_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (PTPT_isStartRealCon(arg)) {
    return (PTPT_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }

  ATabort("Start has no AmbCnt: %t\n", arg);
  return (PTPT_Start)NULL;
}

/*}}}  */
/*{{{  PTPT_Start PTPT_setStartTopTree(PTPT_Start arg, PTPT_Tree topTree) */

PTPT_Start PTPT_setStartTopTree(PTPT_Start arg, PTPT_Tree topTree)
{
  if (PTPT_isStartTree(arg)) {
    return (PTPT_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topTree), 1), 1), 0);
  }

  ATabort("Start has no TopTree: %t\n", arg);
  return (PTPT_Start)NULL;
}

/*}}}  */
/*{{{  PTPT_Start PTPT_setStartTopATerm(PTPT_Start arg, PTPT_ATerm topATerm) */

PTPT_Start PTPT_setStartTopATerm(PTPT_Start arg, PTPT_ATerm topATerm)
{
  if (PTPT_isStartATerm(arg)) {
    return (PTPT_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topATerm), 1), 1), 0);
  }

  ATabort("Start has no TopATerm: %t\n", arg);
  return (PTPT_Start)NULL;
}

/*}}}  */
/*{{{  PTPT_Start PTPT_setStartTopIntCon(PTPT_Start arg, PTPT_IntCon topIntCon) */

PTPT_Start PTPT_setStartTopIntCon(PTPT_Start arg, PTPT_IntCon topIntCon)
{
  if (PTPT_isStartIntCon(arg)) {
    return (PTPT_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topIntCon), 1), 1), 0);
  }

  ATabort("Start has no TopIntCon: %t\n", arg);
  return (PTPT_Start)NULL;
}

/*}}}  */
/*{{{  PTPT_Start PTPT_setStartTopRealCon(PTPT_Start arg, PTPT_RealCon topRealCon) */

PTPT_Start PTPT_setStartTopRealCon(PTPT_Start arg, PTPT_RealCon topRealCon)
{
  if (PTPT_isStartRealCon(arg)) {
    return (PTPT_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topRealCon), 1), 1), 0);
  }

  ATabort("Start has no TopRealCon: %t\n", arg);
  return (PTPT_Start)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTPT_SymbolList accessors */

/*{{{  ATbool PTPT_isValidSymbolList(PTPT_SymbolList arg) */

ATbool PTPT_isValidSymbolList(PTPT_SymbolList arg)
{
  if (PTPT_isSymbolListEmpty(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolListSingle(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isSymbolListEmpty(PTPT_SymbolList arg) */

inline ATbool PTPT_isSymbolListEmpty(PTPT_SymbolList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTPT_patternSymbolListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isSymbolListSingle(PTPT_SymbolList arg) */

inline ATbool PTPT_isSymbolListSingle(PTPT_SymbolList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternSymbolListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isSymbolListMany(PTPT_SymbolList arg) */

inline ATbool PTPT_isSymbolListMany(PTPT_SymbolList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternSymbolListMany, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolListHead(PTPT_SymbolList arg) */

ATbool PTPT_hasSymbolListHead(PTPT_SymbolList arg)
{
  if (PTPT_isSymbolListSingle(arg)) {
    return ATtrue;
  }
  else if (PTPT_isSymbolListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolListWsAfterHead(PTPT_SymbolList arg) */

ATbool PTPT_hasSymbolListWsAfterHead(PTPT_SymbolList arg)
{
  if (PTPT_isSymbolListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolListWsAfterSep(PTPT_SymbolList arg) */

ATbool PTPT_hasSymbolListWsAfterSep(PTPT_SymbolList arg)
{
  if (PTPT_isSymbolListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasSymbolListTail(PTPT_SymbolList arg) */

ATbool PTPT_hasSymbolListTail(PTPT_SymbolList arg)
{
  if (PTPT_isSymbolListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTPT_SymbolList PTPT_getSymbolListTail(PTPT_SymbolList arg) */

PTPT_SymbolList PTPT_getSymbolListTail(PTPT_SymbolList arg)
{
  assert(!PTPT_isSymbolListEmpty(arg) && "getTail on an empty list");
  if (PTPT_isSymbolListSingle(arg)) {
    return (PTPT_SymbolList) PTPT_makeSymbolListEmpty();
  }
  else {
  
    return (PTPT_SymbolList)ATgetTail((ATermList)arg, 4);
  }
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_getSymbolListHead(PTPT_SymbolList arg) */

PTPT_Symbol PTPT_getSymbolListHead(PTPT_SymbolList arg)
{
  if (PTPT_isSymbolListSingle(arg)) {
    return (PTPT_Symbol)ATgetFirst((ATermList)arg);
  }
  else 
    return (PTPT_Symbol)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getSymbolListWsAfterHead(PTPT_SymbolList arg) */

PTPT_OptLayout PTPT_getSymbolListWsAfterHead(PTPT_SymbolList arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getSymbolListWsAfterSep(PTPT_SymbolList arg) */

PTPT_OptLayout PTPT_getSymbolListWsAfterSep(PTPT_SymbolList arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  PTPT_SymbolList PTPT_setSymbolListHead(PTPT_SymbolList arg, PTPT_Symbol head) */

PTPT_SymbolList PTPT_setSymbolListHead(PTPT_SymbolList arg, PTPT_Symbol head)
{
  if (PTPT_isSymbolListSingle(arg)) {
    return (PTPT_SymbolList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (PTPT_isSymbolListMany(arg)) {
    return (PTPT_SymbolList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("SymbolList has no Head: %t\n", arg);
  return (PTPT_SymbolList)NULL;
}

/*}}}  */
/*{{{  PTPT_SymbolList PTPT_setSymbolListWsAfterHead(PTPT_SymbolList arg, PTPT_OptLayout wsAfterHead) */

PTPT_SymbolList PTPT_setSymbolListWsAfterHead(PTPT_SymbolList arg, PTPT_OptLayout wsAfterHead)
{
  if (PTPT_isSymbolListMany(arg)) {
    return (PTPT_SymbolList)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterHead), 1);
  }

  ATabort("SymbolList has no WsAfterHead: %t\n", arg);
  return (PTPT_SymbolList)NULL;
}

/*}}}  */
/*{{{  PTPT_SymbolList PTPT_setSymbolListWsAfterSep(PTPT_SymbolList arg, PTPT_OptLayout wsAfterSep) */

PTPT_SymbolList PTPT_setSymbolListWsAfterSep(PTPT_SymbolList arg, PTPT_OptLayout wsAfterSep)
{
  if (PTPT_isSymbolListMany(arg)) {
    return (PTPT_SymbolList)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterSep), 3);
  }

  ATabort("SymbolList has no WsAfterSep: %t\n", arg);
  return (PTPT_SymbolList)NULL;
}

/*}}}  */
/*{{{  PTPT_SymbolList PTPT_setSymbolListTail(PTPT_SymbolList arg, PTPT_SymbolList tail) */

PTPT_SymbolList PTPT_setSymbolListTail(PTPT_SymbolList arg, PTPT_SymbolList tail)
{
  if (PTPT_isSymbolListMany(arg)) {
    return (PTPT_SymbolList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 4);
  }

  ATabort("SymbolList has no Tail: %t\n", arg);
  return (PTPT_SymbolList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTPT_CharRangeList accessors */

/*{{{  ATbool PTPT_isValidCharRangeList(PTPT_CharRangeList arg) */

ATbool PTPT_isValidCharRangeList(PTPT_CharRangeList arg)
{
  if (PTPT_isCharRangeListEmpty(arg)) {
    return ATtrue;
  }
  else if (PTPT_isCharRangeListSingle(arg)) {
    return ATtrue;
  }
  else if (PTPT_isCharRangeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isCharRangeListEmpty(PTPT_CharRangeList arg) */

inline ATbool PTPT_isCharRangeListEmpty(PTPT_CharRangeList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTPT_patternCharRangeListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isCharRangeListSingle(PTPT_CharRangeList arg) */

inline ATbool PTPT_isCharRangeListSingle(PTPT_CharRangeList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternCharRangeListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isCharRangeListMany(PTPT_CharRangeList arg) */

inline ATbool PTPT_isCharRangeListMany(PTPT_CharRangeList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternCharRangeListMany, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PTPT_hasCharRangeListHead(PTPT_CharRangeList arg) */

ATbool PTPT_hasCharRangeListHead(PTPT_CharRangeList arg)
{
  if (PTPT_isCharRangeListSingle(arg)) {
    return ATtrue;
  }
  else if (PTPT_isCharRangeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasCharRangeListWsAfterHead(PTPT_CharRangeList arg) */

ATbool PTPT_hasCharRangeListWsAfterHead(PTPT_CharRangeList arg)
{
  if (PTPT_isCharRangeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasCharRangeListWsAfterSep(PTPT_CharRangeList arg) */

ATbool PTPT_hasCharRangeListWsAfterSep(PTPT_CharRangeList arg)
{
  if (PTPT_isCharRangeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasCharRangeListTail(PTPT_CharRangeList arg) */

ATbool PTPT_hasCharRangeListTail(PTPT_CharRangeList arg)
{
  if (PTPT_isCharRangeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTPT_CharRangeList PTPT_getCharRangeListTail(PTPT_CharRangeList arg) */

PTPT_CharRangeList PTPT_getCharRangeListTail(PTPT_CharRangeList arg)
{
  assert(!PTPT_isCharRangeListEmpty(arg) && "getTail on an empty list");
  if (PTPT_isCharRangeListSingle(arg)) {
    return (PTPT_CharRangeList) PTPT_makeCharRangeListEmpty();
  }
  else {
  
    return (PTPT_CharRangeList)ATgetTail((ATermList)arg, 4);
  }
}

/*}}}  */
/*{{{  PTPT_CharRange PTPT_getCharRangeListHead(PTPT_CharRangeList arg) */

PTPT_CharRange PTPT_getCharRangeListHead(PTPT_CharRangeList arg)
{
  if (PTPT_isCharRangeListSingle(arg)) {
    return (PTPT_CharRange)ATgetFirst((ATermList)arg);
  }
  else 
    return (PTPT_CharRange)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getCharRangeListWsAfterHead(PTPT_CharRangeList arg) */

PTPT_OptLayout PTPT_getCharRangeListWsAfterHead(PTPT_CharRangeList arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getCharRangeListWsAfterSep(PTPT_CharRangeList arg) */

PTPT_OptLayout PTPT_getCharRangeListWsAfterSep(PTPT_CharRangeList arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  PTPT_CharRangeList PTPT_setCharRangeListHead(PTPT_CharRangeList arg, PTPT_CharRange head) */

PTPT_CharRangeList PTPT_setCharRangeListHead(PTPT_CharRangeList arg, PTPT_CharRange head)
{
  if (PTPT_isCharRangeListSingle(arg)) {
    return (PTPT_CharRangeList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (PTPT_isCharRangeListMany(arg)) {
    return (PTPT_CharRangeList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("CharRangeList has no Head: %t\n", arg);
  return (PTPT_CharRangeList)NULL;
}

/*}}}  */
/*{{{  PTPT_CharRangeList PTPT_setCharRangeListWsAfterHead(PTPT_CharRangeList arg, PTPT_OptLayout wsAfterHead) */

PTPT_CharRangeList PTPT_setCharRangeListWsAfterHead(PTPT_CharRangeList arg, PTPT_OptLayout wsAfterHead)
{
  if (PTPT_isCharRangeListMany(arg)) {
    return (PTPT_CharRangeList)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterHead), 1);
  }

  ATabort("CharRangeList has no WsAfterHead: %t\n", arg);
  return (PTPT_CharRangeList)NULL;
}

/*}}}  */
/*{{{  PTPT_CharRangeList PTPT_setCharRangeListWsAfterSep(PTPT_CharRangeList arg, PTPT_OptLayout wsAfterSep) */

PTPT_CharRangeList PTPT_setCharRangeListWsAfterSep(PTPT_CharRangeList arg, PTPT_OptLayout wsAfterSep)
{
  if (PTPT_isCharRangeListMany(arg)) {
    return (PTPT_CharRangeList)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterSep), 3);
  }

  ATabort("CharRangeList has no WsAfterSep: %t\n", arg);
  return (PTPT_CharRangeList)NULL;
}

/*}}}  */
/*{{{  PTPT_CharRangeList PTPT_setCharRangeListTail(PTPT_CharRangeList arg, PTPT_CharRangeList tail) */

PTPT_CharRangeList PTPT_setCharRangeListTail(PTPT_CharRangeList arg, PTPT_CharRangeList tail)
{
  if (PTPT_isCharRangeListMany(arg)) {
    return (PTPT_CharRangeList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 4);
  }

  ATabort("CharRangeList has no Tail: %t\n", arg);
  return (PTPT_CharRangeList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTPT_Args accessors */

/*{{{  ATbool PTPT_isValidArgs(PTPT_Args arg) */

ATbool PTPT_isValidArgs(PTPT_Args arg)
{
  if (PTPT_isArgsList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isArgsList(PTPT_Args arg) */

inline ATbool PTPT_isArgsList(PTPT_Args arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTPT_patternArgsList, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PTPT_hasArgsWsAfterBracketOpen(PTPT_Args arg) */

ATbool PTPT_hasArgsWsAfterBracketOpen(PTPT_Args arg)
{
  if (PTPT_isArgsList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasArgsList(PTPT_Args arg) */

ATbool PTPT_hasArgsList(PTPT_Args arg)
{
  if (PTPT_isArgsList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasArgsWsAfterList(PTPT_Args arg) */

ATbool PTPT_hasArgsWsAfterList(PTPT_Args arg)
{
  if (PTPT_isArgsList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getArgsWsAfterBracketOpen(PTPT_Args arg) */

PTPT_OptLayout PTPT_getArgsWsAfterBracketOpen(PTPT_Args arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_TreeList PTPT_getArgsList(PTPT_Args arg) */

PTPT_TreeList PTPT_getArgsList(PTPT_Args arg)
{
  
    return (PTPT_TreeList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), 1);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getArgsWsAfterList(PTPT_Args arg) */

PTPT_OptLayout PTPT_getArgsWsAfterList(PTPT_Args arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  PTPT_Args PTPT_setArgsWsAfterBracketOpen(PTPT_Args arg, PTPT_OptLayout wsAfterBracketOpen) */

PTPT_Args PTPT_setArgsWsAfterBracketOpen(PTPT_Args arg, PTPT_OptLayout wsAfterBracketOpen)
{
  if (PTPT_isArgsList(arg)) {
    return (PTPT_Args)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 1), 1);
  }

  ATabort("Args has no WsAfterBracketOpen: %t\n", arg);
  return (PTPT_Args)NULL;
}

/*}}}  */
/*{{{  PTPT_Args PTPT_setArgsList(PTPT_Args arg, PTPT_TreeList list) */

PTPT_Args PTPT_setArgsList(PTPT_Args arg, PTPT_TreeList list)
{
  if (PTPT_isArgsList(arg)) {
    return (PTPT_Args)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), (ATerm)((ATerm) list), 1), 2), 1);
  }

  ATabort("Args has no List: %t\n", arg);
  return (PTPT_Args)NULL;
}

/*}}}  */
/*{{{  PTPT_Args PTPT_setArgsWsAfterList(PTPT_Args arg, PTPT_OptLayout wsAfterList) */

PTPT_Args PTPT_setArgsWsAfterList(PTPT_Args arg, PTPT_OptLayout wsAfterList)
{
  if (PTPT_isArgsList(arg)) {
    return (PTPT_Args)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterList), 3), 1);
  }

  ATabort("Args has no WsAfterList: %t\n", arg);
  return (PTPT_Args)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTPT_Production accessors */

/*{{{  ATbool PTPT_isValidProduction(PTPT_Production arg) */

ATbool PTPT_isValidProduction(PTPT_Production arg)
{
  if (PTPT_isProductionDefault(arg)) {
    return ATtrue;
  }
  else if (PTPT_isProductionList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isProductionDefault(PTPT_Production arg) */

inline ATbool PTPT_isProductionDefault(PTPT_Production arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternProductionDefault, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isProductionList(PTPT_Production arg) */

inline ATbool PTPT_isProductionList(PTPT_Production arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternProductionList, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PTPT_hasProductionWsAfterProd(PTPT_Production arg) */

ATbool PTPT_hasProductionWsAfterProd(PTPT_Production arg)
{
  if (PTPT_isProductionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasProductionWsAfterParenOpen(PTPT_Production arg) */

ATbool PTPT_hasProductionWsAfterParenOpen(PTPT_Production arg)
{
  if (PTPT_isProductionDefault(arg)) {
    return ATtrue;
  }
  else if (PTPT_isProductionList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasProductionLhs(PTPT_Production arg) */

ATbool PTPT_hasProductionLhs(PTPT_Production arg)
{
  if (PTPT_isProductionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasProductionWsAfterLhs(PTPT_Production arg) */

ATbool PTPT_hasProductionWsAfterLhs(PTPT_Production arg)
{
  if (PTPT_isProductionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasProductionWsAfterComma1(PTPT_Production arg) */

ATbool PTPT_hasProductionWsAfterComma1(PTPT_Production arg)
{
  if (PTPT_isProductionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasProductionRhs(PTPT_Production arg) */

ATbool PTPT_hasProductionRhs(PTPT_Production arg)
{
  if (PTPT_isProductionDefault(arg)) {
    return ATtrue;
  }
  else if (PTPT_isProductionList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasProductionWsAfterRhs(PTPT_Production arg) */

ATbool PTPT_hasProductionWsAfterRhs(PTPT_Production arg)
{
  if (PTPT_isProductionDefault(arg)) {
    return ATtrue;
  }
  else if (PTPT_isProductionList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasProductionWsAfterComma2(PTPT_Production arg) */

ATbool PTPT_hasProductionWsAfterComma2(PTPT_Production arg)
{
  if (PTPT_isProductionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasProductionAttributes(PTPT_Production arg) */

ATbool PTPT_hasProductionAttributes(PTPT_Production arg)
{
  if (PTPT_isProductionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasProductionWsAfterAttributes(PTPT_Production arg) */

ATbool PTPT_hasProductionWsAfterAttributes(PTPT_Production arg)
{
  if (PTPT_isProductionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasProductionWsAfterList(PTPT_Production arg) */

ATbool PTPT_hasProductionWsAfterList(PTPT_Production arg)
{
  if (PTPT_isProductionList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getProductionWsAfterProd(PTPT_Production arg) */

PTPT_OptLayout PTPT_getProductionWsAfterProd(PTPT_Production arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getProductionWsAfterParenOpen(PTPT_Production arg) */

PTPT_OptLayout PTPT_getProductionWsAfterParenOpen(PTPT_Production arg)
{
  if (PTPT_isProductionDefault(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  PTPT_Symbols PTPT_getProductionLhs(PTPT_Production arg) */

PTPT_Symbols PTPT_getProductionLhs(PTPT_Production arg)
{
  
    return (PTPT_Symbols)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getProductionWsAfterLhs(PTPT_Production arg) */

PTPT_OptLayout PTPT_getProductionWsAfterLhs(PTPT_Production arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getProductionWsAfterComma1(PTPT_Production arg) */

PTPT_OptLayout PTPT_getProductionWsAfterComma1(PTPT_Production arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_getProductionRhs(PTPT_Production arg) */

PTPT_Symbol PTPT_getProductionRhs(PTPT_Production arg)
{
  if (PTPT_isProductionDefault(arg)) {
    return (PTPT_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
  }
  else 
    return (PTPT_Symbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getProductionWsAfterRhs(PTPT_Production arg) */

PTPT_OptLayout PTPT_getProductionWsAfterRhs(PTPT_Production arg)
{
  if (PTPT_isProductionDefault(arg)) {
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
  }
  else 
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getProductionWsAfterComma2(PTPT_Production arg) */

PTPT_OptLayout PTPT_getProductionWsAfterComma2(PTPT_Production arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 11);
}

/*}}}  */
/*{{{  PTPT_Attributes PTPT_getProductionAttributes(PTPT_Production arg) */

PTPT_Attributes PTPT_getProductionAttributes(PTPT_Production arg)
{
  
    return (PTPT_Attributes)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 12);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getProductionWsAfterAttributes(PTPT_Production arg) */

PTPT_OptLayout PTPT_getProductionWsAfterAttributes(PTPT_Production arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 13);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getProductionWsAfterList(PTPT_Production arg) */

PTPT_OptLayout PTPT_getProductionWsAfterList(PTPT_Production arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_Production PTPT_setProductionWsAfterProd(PTPT_Production arg, PTPT_OptLayout wsAfterProd) */

PTPT_Production PTPT_setProductionWsAfterProd(PTPT_Production arg, PTPT_OptLayout wsAfterProd)
{
  if (PTPT_isProductionDefault(arg)) {
    return (PTPT_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterProd), 1), 1);
  }

  ATabort("Production has no WsAfterProd: %t\n", arg);
  return (PTPT_Production)NULL;
}

/*}}}  */
/*{{{  PTPT_Production PTPT_setProductionWsAfterParenOpen(PTPT_Production arg, PTPT_OptLayout wsAfterParenOpen) */

PTPT_Production PTPT_setProductionWsAfterParenOpen(PTPT_Production arg, PTPT_OptLayout wsAfterParenOpen)
{
  if (PTPT_isProductionDefault(arg)) {
    return (PTPT_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PTPT_isProductionList(arg)) {
    return (PTPT_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("Production has no WsAfterParenOpen: %t\n", arg);
  return (PTPT_Production)NULL;
}

/*}}}  */
/*{{{  PTPT_Production PTPT_setProductionLhs(PTPT_Production arg, PTPT_Symbols lhs) */

PTPT_Production PTPT_setProductionLhs(PTPT_Production arg, PTPT_Symbols lhs)
{
  if (PTPT_isProductionDefault(arg)) {
    return (PTPT_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) lhs), 4), 1);
  }

  ATabort("Production has no Lhs: %t\n", arg);
  return (PTPT_Production)NULL;
}

/*}}}  */
/*{{{  PTPT_Production PTPT_setProductionWsAfterLhs(PTPT_Production arg, PTPT_OptLayout wsAfterLhs) */

PTPT_Production PTPT_setProductionWsAfterLhs(PTPT_Production arg, PTPT_OptLayout wsAfterLhs)
{
  if (PTPT_isProductionDefault(arg)) {
    return (PTPT_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLhs), 5), 1);
  }

  ATabort("Production has no WsAfterLhs: %t\n", arg);
  return (PTPT_Production)NULL;
}

/*}}}  */
/*{{{  PTPT_Production PTPT_setProductionWsAfterComma1(PTPT_Production arg, PTPT_OptLayout wsAfterComma1) */

PTPT_Production PTPT_setProductionWsAfterComma1(PTPT_Production arg, PTPT_OptLayout wsAfterComma1)
{
  if (PTPT_isProductionDefault(arg)) {
    return (PTPT_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma1), 7), 1);
  }

  ATabort("Production has no WsAfterComma1: %t\n", arg);
  return (PTPT_Production)NULL;
}

/*}}}  */
/*{{{  PTPT_Production PTPT_setProductionRhs(PTPT_Production arg, PTPT_Symbol rhs) */

PTPT_Production PTPT_setProductionRhs(PTPT_Production arg, PTPT_Symbol rhs)
{
  if (PTPT_isProductionDefault(arg)) {
    return (PTPT_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) rhs), 8), 1);
  }
  else if (PTPT_isProductionList(arg)) {
    return (PTPT_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) rhs), 4), 1);
  }

  ATabort("Production has no Rhs: %t\n", arg);
  return (PTPT_Production)NULL;
}

/*}}}  */
/*{{{  PTPT_Production PTPT_setProductionWsAfterRhs(PTPT_Production arg, PTPT_OptLayout wsAfterRhs) */

PTPT_Production PTPT_setProductionWsAfterRhs(PTPT_Production arg, PTPT_OptLayout wsAfterRhs)
{
  if (PTPT_isProductionDefault(arg)) {
    return (PTPT_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterRhs), 9), 1);
  }
  else if (PTPT_isProductionList(arg)) {
    return (PTPT_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterRhs), 5), 1);
  }

  ATabort("Production has no WsAfterRhs: %t\n", arg);
  return (PTPT_Production)NULL;
}

/*}}}  */
/*{{{  PTPT_Production PTPT_setProductionWsAfterComma2(PTPT_Production arg, PTPT_OptLayout wsAfterComma2) */

PTPT_Production PTPT_setProductionWsAfterComma2(PTPT_Production arg, PTPT_OptLayout wsAfterComma2)
{
  if (PTPT_isProductionDefault(arg)) {
    return (PTPT_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma2), 11), 1);
  }

  ATabort("Production has no WsAfterComma2: %t\n", arg);
  return (PTPT_Production)NULL;
}

/*}}}  */
/*{{{  PTPT_Production PTPT_setProductionAttributes(PTPT_Production arg, PTPT_Attributes attributes) */

PTPT_Production PTPT_setProductionAttributes(PTPT_Production arg, PTPT_Attributes attributes)
{
  if (PTPT_isProductionDefault(arg)) {
    return (PTPT_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) attributes), 12), 1);
  }

  ATabort("Production has no Attributes: %t\n", arg);
  return (PTPT_Production)NULL;
}

/*}}}  */
/*{{{  PTPT_Production PTPT_setProductionWsAfterAttributes(PTPT_Production arg, PTPT_OptLayout wsAfterAttributes) */

PTPT_Production PTPT_setProductionWsAfterAttributes(PTPT_Production arg, PTPT_OptLayout wsAfterAttributes)
{
  if (PTPT_isProductionDefault(arg)) {
    return (PTPT_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterAttributes), 13), 1);
  }

  ATabort("Production has no WsAfterAttributes: %t\n", arg);
  return (PTPT_Production)NULL;
}

/*}}}  */
/*{{{  PTPT_Production PTPT_setProductionWsAfterList(PTPT_Production arg, PTPT_OptLayout wsAfterList) */

PTPT_Production PTPT_setProductionWsAfterList(PTPT_Production arg, PTPT_OptLayout wsAfterList)
{
  if (PTPT_isProductionList(arg)) {
    return (PTPT_Production)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterList), 1), 1);
  }

  ATabort("Production has no WsAfterList: %t\n", arg);
  return (PTPT_Production)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTPT_TreeList accessors */

/*{{{  ATbool PTPT_isValidTreeList(PTPT_TreeList arg) */

ATbool PTPT_isValidTreeList(PTPT_TreeList arg)
{
  if (PTPT_isTreeListEmpty(arg)) {
    return ATtrue;
  }
  else if (PTPT_isTreeListSingle(arg)) {
    return ATtrue;
  }
  else if (PTPT_isTreeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isTreeListEmpty(PTPT_TreeList arg) */

inline ATbool PTPT_isTreeListEmpty(PTPT_TreeList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTPT_patternTreeListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isTreeListSingle(PTPT_TreeList arg) */

inline ATbool PTPT_isTreeListSingle(PTPT_TreeList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternTreeListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isTreeListMany(PTPT_TreeList arg) */

inline ATbool PTPT_isTreeListMany(PTPT_TreeList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternTreeListMany, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PTPT_hasTreeListHead(PTPT_TreeList arg) */

ATbool PTPT_hasTreeListHead(PTPT_TreeList arg)
{
  if (PTPT_isTreeListSingle(arg)) {
    return ATtrue;
  }
  else if (PTPT_isTreeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasTreeListWsAfterHead(PTPT_TreeList arg) */

ATbool PTPT_hasTreeListWsAfterHead(PTPT_TreeList arg)
{
  if (PTPT_isTreeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasTreeListWsAfterSep(PTPT_TreeList arg) */

ATbool PTPT_hasTreeListWsAfterSep(PTPT_TreeList arg)
{
  if (PTPT_isTreeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasTreeListTail(PTPT_TreeList arg) */

ATbool PTPT_hasTreeListTail(PTPT_TreeList arg)
{
  if (PTPT_isTreeListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTPT_TreeList PTPT_getTreeListTail(PTPT_TreeList arg) */

PTPT_TreeList PTPT_getTreeListTail(PTPT_TreeList arg)
{
  assert(!PTPT_isTreeListEmpty(arg) && "getTail on an empty list");
  if (PTPT_isTreeListSingle(arg)) {
    return (PTPT_TreeList) PTPT_makeTreeListEmpty();
  }
  else {
  
    return (PTPT_TreeList)ATgetTail((ATermList)arg, 4);
  }
}

/*}}}  */
/*{{{  PTPT_Tree PTPT_getTreeListHead(PTPT_TreeList arg) */

PTPT_Tree PTPT_getTreeListHead(PTPT_TreeList arg)
{
  if (PTPT_isTreeListSingle(arg)) {
    return (PTPT_Tree)ATgetFirst((ATermList)arg);
  }
  else 
    return (PTPT_Tree)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getTreeListWsAfterHead(PTPT_TreeList arg) */

PTPT_OptLayout PTPT_getTreeListWsAfterHead(PTPT_TreeList arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getTreeListWsAfterSep(PTPT_TreeList arg) */

PTPT_OptLayout PTPT_getTreeListWsAfterSep(PTPT_TreeList arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  PTPT_TreeList PTPT_setTreeListHead(PTPT_TreeList arg, PTPT_Tree head) */

PTPT_TreeList PTPT_setTreeListHead(PTPT_TreeList arg, PTPT_Tree head)
{
  if (PTPT_isTreeListSingle(arg)) {
    return (PTPT_TreeList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (PTPT_isTreeListMany(arg)) {
    return (PTPT_TreeList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("TreeList has no Head: %t\n", arg);
  return (PTPT_TreeList)NULL;
}

/*}}}  */
/*{{{  PTPT_TreeList PTPT_setTreeListWsAfterHead(PTPT_TreeList arg, PTPT_OptLayout wsAfterHead) */

PTPT_TreeList PTPT_setTreeListWsAfterHead(PTPT_TreeList arg, PTPT_OptLayout wsAfterHead)
{
  if (PTPT_isTreeListMany(arg)) {
    return (PTPT_TreeList)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterHead), 1);
  }

  ATabort("TreeList has no WsAfterHead: %t\n", arg);
  return (PTPT_TreeList)NULL;
}

/*}}}  */
/*{{{  PTPT_TreeList PTPT_setTreeListWsAfterSep(PTPT_TreeList arg, PTPT_OptLayout wsAfterSep) */

PTPT_TreeList PTPT_setTreeListWsAfterSep(PTPT_TreeList arg, PTPT_OptLayout wsAfterSep)
{
  if (PTPT_isTreeListMany(arg)) {
    return (PTPT_TreeList)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterSep), 3);
  }

  ATabort("TreeList has no WsAfterSep: %t\n", arg);
  return (PTPT_TreeList)NULL;
}

/*}}}  */
/*{{{  PTPT_TreeList PTPT_setTreeListTail(PTPT_TreeList arg, PTPT_TreeList tail) */

PTPT_TreeList PTPT_setTreeListTail(PTPT_TreeList arg, PTPT_TreeList tail)
{
  if (PTPT_isTreeListMany(arg)) {
    return (PTPT_TreeList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 4);
  }

  ATabort("TreeList has no Tail: %t\n", arg);
  return (PTPT_TreeList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTPT_AFun accessors */

/*{{{  ATbool PTPT_isValidAFun(PTPT_AFun arg) */

ATbool PTPT_isValidAFun(PTPT_AFun arg)
{
  if (PTPT_isAFunQuoted(arg)) {
    return ATtrue;
  }
  else if (PTPT_isAFunUnquoted(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isAFunQuoted(PTPT_AFun arg) */

inline ATbool PTPT_isAFunQuoted(PTPT_AFun arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternAFunQuoted, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isAFunUnquoted(PTPT_AFun arg) */

inline ATbool PTPT_isAFunUnquoted(PTPT_AFun arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternAFunUnquoted, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PTPT_hasAFunStrCon(PTPT_AFun arg) */

ATbool PTPT_hasAFunStrCon(PTPT_AFun arg)
{
  if (PTPT_isAFunQuoted(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasAFunIdCon(PTPT_AFun arg) */

ATbool PTPT_hasAFunIdCon(PTPT_AFun arg)
{
  if (PTPT_isAFunUnquoted(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTPT_StrCon PTPT_getAFunStrCon(PTPT_AFun arg) */

PTPT_StrCon PTPT_getAFunStrCon(PTPT_AFun arg)
{
  
    return (PTPT_StrCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  PTPT_IdCon PTPT_getAFunIdCon(PTPT_AFun arg) */

PTPT_IdCon PTPT_getAFunIdCon(PTPT_AFun arg)
{
  
    return (PTPT_IdCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  PTPT_AFun PTPT_setAFunStrCon(PTPT_AFun arg, PTPT_StrCon StrCon) */

PTPT_AFun PTPT_setAFunStrCon(PTPT_AFun arg, PTPT_StrCon StrCon)
{
  if (PTPT_isAFunQuoted(arg)) {
    return (PTPT_AFun)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) StrCon), 0), 1);
  }

  ATabort("AFun has no StrCon: %t\n", arg);
  return (PTPT_AFun)NULL;
}

/*}}}  */
/*{{{  PTPT_AFun PTPT_setAFunIdCon(PTPT_AFun arg, PTPT_IdCon IdCon) */

PTPT_AFun PTPT_setAFunIdCon(PTPT_AFun arg, PTPT_IdCon IdCon)
{
  if (PTPT_isAFunUnquoted(arg)) {
    return (PTPT_AFun)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) IdCon), 0), 1);
  }

  ATabort("AFun has no IdCon: %t\n", arg);
  return (PTPT_AFun)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTPT_ATerm accessors */

/*{{{  ATbool PTPT_isValidATerm(PTPT_ATerm arg) */

ATbool PTPT_isValidATerm(PTPT_ATerm arg)
{
  if (PTPT_isATermInt(arg)) {
    return ATtrue;
  }
  else if (PTPT_isATermReal(arg)) {
    return ATtrue;
  }
  else if (PTPT_isATermFun(arg)) {
    return ATtrue;
  }
  else if (PTPT_isATermAppl(arg)) {
    return ATtrue;
  }
  else if (PTPT_isATermPlaceholder(arg)) {
    return ATtrue;
  }
  else if (PTPT_isATermList(arg)) {
    return ATtrue;
  }
  else if (PTPT_isATermAnnotated(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isATermInt(PTPT_ATerm arg) */

inline ATbool PTPT_isATermInt(PTPT_ATerm arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternATermInt, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isATermReal(PTPT_ATerm arg) */

inline ATbool PTPT_isATermReal(PTPT_ATerm arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternATermReal, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isATermFun(PTPT_ATerm arg) */

inline ATbool PTPT_isATermFun(PTPT_ATerm arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternATermFun, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isATermAppl(PTPT_ATerm arg) */

inline ATbool PTPT_isATermAppl(PTPT_ATerm arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternATermAppl, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isATermPlaceholder(PTPT_ATerm arg) */

inline ATbool PTPT_isATermPlaceholder(PTPT_ATerm arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternATermPlaceholder, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isATermList(PTPT_ATerm arg) */

inline ATbool PTPT_isATermList(PTPT_ATerm arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternATermList, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isATermAnnotated(PTPT_ATerm arg) */

inline ATbool PTPT_isATermAnnotated(PTPT_ATerm arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternATermAnnotated, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PTPT_hasATermIntCon(PTPT_ATerm arg) */

ATbool PTPT_hasATermIntCon(PTPT_ATerm arg)
{
  if (PTPT_isATermInt(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasATermRealCon(PTPT_ATerm arg) */

ATbool PTPT_hasATermRealCon(PTPT_ATerm arg)
{
  if (PTPT_isATermReal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasATermFun(PTPT_ATerm arg) */

ATbool PTPT_hasATermFun(PTPT_ATerm arg)
{
  if (PTPT_isATermFun(arg)) {
    return ATtrue;
  }
  else if (PTPT_isATermAppl(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasATermWsAfterFun(PTPT_ATerm arg) */

ATbool PTPT_hasATermWsAfterFun(PTPT_ATerm arg)
{
  if (PTPT_isATermAppl(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasATermWsAfterParenOpen(PTPT_ATerm arg) */

ATbool PTPT_hasATermWsAfterParenOpen(PTPT_ATerm arg)
{
  if (PTPT_isATermAppl(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasATermArgs(PTPT_ATerm arg) */

ATbool PTPT_hasATermArgs(PTPT_ATerm arg)
{
  if (PTPT_isATermAppl(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasATermWsAfterArgs(PTPT_ATerm arg) */

ATbool PTPT_hasATermWsAfterArgs(PTPT_ATerm arg)
{
  if (PTPT_isATermAppl(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasATermWsAfterLessThan(PTPT_ATerm arg) */

ATbool PTPT_hasATermWsAfterLessThan(PTPT_ATerm arg)
{
  if (PTPT_isATermPlaceholder(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasATermType(PTPT_ATerm arg) */

ATbool PTPT_hasATermType(PTPT_ATerm arg)
{
  if (PTPT_isATermPlaceholder(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasATermWsAfterType(PTPT_ATerm arg) */

ATbool PTPT_hasATermWsAfterType(PTPT_ATerm arg)
{
  if (PTPT_isATermPlaceholder(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasATermWsAfterBracketOpen(PTPT_ATerm arg) */

ATbool PTPT_hasATermWsAfterBracketOpen(PTPT_ATerm arg)
{
  if (PTPT_isATermList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasATermElems(PTPT_ATerm arg) */

ATbool PTPT_hasATermElems(PTPT_ATerm arg)
{
  if (PTPT_isATermList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasATermWsAfterElems(PTPT_ATerm arg) */

ATbool PTPT_hasATermWsAfterElems(PTPT_ATerm arg)
{
  if (PTPT_isATermList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasATermTrm(PTPT_ATerm arg) */

ATbool PTPT_hasATermTrm(PTPT_ATerm arg)
{
  if (PTPT_isATermAnnotated(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasATermWsAfterTrm(PTPT_ATerm arg) */

ATbool PTPT_hasATermWsAfterTrm(PTPT_ATerm arg)
{
  if (PTPT_isATermAnnotated(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasATermAnnotation(PTPT_ATerm arg) */

ATbool PTPT_hasATermAnnotation(PTPT_ATerm arg)
{
  if (PTPT_isATermAnnotated(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTPT_IntCon PTPT_getATermIntCon(PTPT_ATerm arg) */

PTPT_IntCon PTPT_getATermIntCon(PTPT_ATerm arg)
{
  
    return (PTPT_IntCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  PTPT_RealCon PTPT_getATermRealCon(PTPT_ATerm arg) */

PTPT_RealCon PTPT_getATermRealCon(PTPT_ATerm arg)
{
  
    return (PTPT_RealCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  PTPT_AFun PTPT_getATermFun(PTPT_ATerm arg) */

PTPT_AFun PTPT_getATermFun(PTPT_ATerm arg)
{
  if (PTPT_isATermFun(arg)) {
    return (PTPT_AFun)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (PTPT_AFun)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getATermWsAfterFun(PTPT_ATerm arg) */

PTPT_OptLayout PTPT_getATermWsAfterFun(PTPT_ATerm arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getATermWsAfterParenOpen(PTPT_ATerm arg) */

PTPT_OptLayout PTPT_getATermWsAfterParenOpen(PTPT_ATerm arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  PTPT_ATermArgs PTPT_getATermArgs(PTPT_ATerm arg) */

PTPT_ATermArgs PTPT_getATermArgs(PTPT_ATerm arg)
{
  
    return (PTPT_ATermArgs)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), 1);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getATermWsAfterArgs(PTPT_ATerm arg) */

PTPT_OptLayout PTPT_getATermWsAfterArgs(PTPT_ATerm arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getATermWsAfterLessThan(PTPT_ATerm arg) */

PTPT_OptLayout PTPT_getATermWsAfterLessThan(PTPT_ATerm arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_ATerm PTPT_getATermType(PTPT_ATerm arg) */

PTPT_ATerm PTPT_getATermType(PTPT_ATerm arg)
{
  
    return (PTPT_ATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getATermWsAfterType(PTPT_ATerm arg) */

PTPT_OptLayout PTPT_getATermWsAfterType(PTPT_ATerm arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getATermWsAfterBracketOpen(PTPT_ATerm arg) */

PTPT_OptLayout PTPT_getATermWsAfterBracketOpen(PTPT_ATerm arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_ATermElems PTPT_getATermElems(PTPT_ATerm arg) */

PTPT_ATermElems PTPT_getATermElems(PTPT_ATerm arg)
{
  
    return (PTPT_ATermElems)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), 1);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getATermWsAfterElems(PTPT_ATerm arg) */

PTPT_OptLayout PTPT_getATermWsAfterElems(PTPT_ATerm arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  PTPT_ATerm PTPT_getATermTrm(PTPT_ATerm arg) */

PTPT_ATerm PTPT_getATermTrm(PTPT_ATerm arg)
{
  
    return (PTPT_ATerm)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getATermWsAfterTrm(PTPT_ATerm arg) */

PTPT_OptLayout PTPT_getATermWsAfterTrm(PTPT_ATerm arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_Annotation PTPT_getATermAnnotation(PTPT_ATerm arg) */

PTPT_Annotation PTPT_getATermAnnotation(PTPT_ATerm arg)
{
  
    return (PTPT_Annotation)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  PTPT_ATerm PTPT_setATermIntCon(PTPT_ATerm arg, PTPT_IntCon IntCon) */

PTPT_ATerm PTPT_setATermIntCon(PTPT_ATerm arg, PTPT_IntCon IntCon)
{
  if (PTPT_isATermInt(arg)) {
    return (PTPT_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) IntCon), 0), 1);
  }

  ATabort("ATerm has no IntCon: %t\n", arg);
  return (PTPT_ATerm)NULL;
}

/*}}}  */
/*{{{  PTPT_ATerm PTPT_setATermRealCon(PTPT_ATerm arg, PTPT_RealCon RealCon) */

PTPT_ATerm PTPT_setATermRealCon(PTPT_ATerm arg, PTPT_RealCon RealCon)
{
  if (PTPT_isATermReal(arg)) {
    return (PTPT_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) RealCon), 0), 1);
  }

  ATabort("ATerm has no RealCon: %t\n", arg);
  return (PTPT_ATerm)NULL;
}

/*}}}  */
/*{{{  PTPT_ATerm PTPT_setATermFun(PTPT_ATerm arg, PTPT_AFun fun) */

PTPT_ATerm PTPT_setATermFun(PTPT_ATerm arg, PTPT_AFun fun)
{
  if (PTPT_isATermFun(arg)) {
    return (PTPT_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) fun), 0), 1);
  }
  else if (PTPT_isATermAppl(arg)) {
    return (PTPT_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) fun), 0), 1);
  }

  ATabort("ATerm has no Fun: %t\n", arg);
  return (PTPT_ATerm)NULL;
}

/*}}}  */
/*{{{  PTPT_ATerm PTPT_setATermWsAfterFun(PTPT_ATerm arg, PTPT_OptLayout wsAfterFun) */

PTPT_ATerm PTPT_setATermWsAfterFun(PTPT_ATerm arg, PTPT_OptLayout wsAfterFun)
{
  if (PTPT_isATermAppl(arg)) {
    return (PTPT_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterFun), 1), 1);
  }

  ATabort("ATerm has no WsAfterFun: %t\n", arg);
  return (PTPT_ATerm)NULL;
}

/*}}}  */
/*{{{  PTPT_ATerm PTPT_setATermWsAfterParenOpen(PTPT_ATerm arg, PTPT_OptLayout wsAfterParenOpen) */

PTPT_ATerm PTPT_setATermWsAfterParenOpen(PTPT_ATerm arg, PTPT_OptLayout wsAfterParenOpen)
{
  if (PTPT_isATermAppl(arg)) {
    return (PTPT_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("ATerm has no WsAfterParenOpen: %t\n", arg);
  return (PTPT_ATerm)NULL;
}

/*}}}  */
/*{{{  PTPT_ATerm PTPT_setATermArgs(PTPT_ATerm arg, PTPT_ATermArgs args) */

PTPT_ATerm PTPT_setATermArgs(PTPT_ATerm arg, PTPT_ATermArgs args)
{
  if (PTPT_isATermAppl(arg)) {
    return (PTPT_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), (ATerm)((ATerm) args), 1), 4), 1);
  }

  ATabort("ATerm has no Args: %t\n", arg);
  return (PTPT_ATerm)NULL;
}

/*}}}  */
/*{{{  PTPT_ATerm PTPT_setATermWsAfterArgs(PTPT_ATerm arg, PTPT_OptLayout wsAfterArgs) */

PTPT_ATerm PTPT_setATermWsAfterArgs(PTPT_ATerm arg, PTPT_OptLayout wsAfterArgs)
{
  if (PTPT_isATermAppl(arg)) {
    return (PTPT_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterArgs), 5), 1);
  }

  ATabort("ATerm has no WsAfterArgs: %t\n", arg);
  return (PTPT_ATerm)NULL;
}

/*}}}  */
/*{{{  PTPT_ATerm PTPT_setATermWsAfterLessThan(PTPT_ATerm arg, PTPT_OptLayout wsAfterLessThan) */

PTPT_ATerm PTPT_setATermWsAfterLessThan(PTPT_ATerm arg, PTPT_OptLayout wsAfterLessThan)
{
  if (PTPT_isATermPlaceholder(arg)) {
    return (PTPT_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLessThan), 1), 1);
  }

  ATabort("ATerm has no WsAfterLessThan: %t\n", arg);
  return (PTPT_ATerm)NULL;
}

/*}}}  */
/*{{{  PTPT_ATerm PTPT_setATermType(PTPT_ATerm arg, PTPT_ATerm type) */

PTPT_ATerm PTPT_setATermType(PTPT_ATerm arg, PTPT_ATerm type)
{
  if (PTPT_isATermPlaceholder(arg)) {
    return (PTPT_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) type), 2), 1);
  }

  ATabort("ATerm has no Type: %t\n", arg);
  return (PTPT_ATerm)NULL;
}

/*}}}  */
/*{{{  PTPT_ATerm PTPT_setATermWsAfterType(PTPT_ATerm arg, PTPT_OptLayout wsAfterType) */

PTPT_ATerm PTPT_setATermWsAfterType(PTPT_ATerm arg, PTPT_OptLayout wsAfterType)
{
  if (PTPT_isATermPlaceholder(arg)) {
    return (PTPT_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterType), 3), 1);
  }

  ATabort("ATerm has no WsAfterType: %t\n", arg);
  return (PTPT_ATerm)NULL;
}

/*}}}  */
/*{{{  PTPT_ATerm PTPT_setATermWsAfterBracketOpen(PTPT_ATerm arg, PTPT_OptLayout wsAfterBracketOpen) */

PTPT_ATerm PTPT_setATermWsAfterBracketOpen(PTPT_ATerm arg, PTPT_OptLayout wsAfterBracketOpen)
{
  if (PTPT_isATermList(arg)) {
    return (PTPT_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 1), 1);
  }

  ATabort("ATerm has no WsAfterBracketOpen: %t\n", arg);
  return (PTPT_ATerm)NULL;
}

/*}}}  */
/*{{{  PTPT_ATerm PTPT_setATermElems(PTPT_ATerm arg, PTPT_ATermElems elems) */

PTPT_ATerm PTPT_setATermElems(PTPT_ATerm arg, PTPT_ATermElems elems)
{
  if (PTPT_isATermList(arg)) {
    return (PTPT_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), (ATerm)((ATerm) elems), 1), 2), 1);
  }

  ATabort("ATerm has no Elems: %t\n", arg);
  return (PTPT_ATerm)NULL;
}

/*}}}  */
/*{{{  PTPT_ATerm PTPT_setATermWsAfterElems(PTPT_ATerm arg, PTPT_OptLayout wsAfterElems) */

PTPT_ATerm PTPT_setATermWsAfterElems(PTPT_ATerm arg, PTPT_OptLayout wsAfterElems)
{
  if (PTPT_isATermList(arg)) {
    return (PTPT_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterElems), 3), 1);
  }

  ATabort("ATerm has no WsAfterElems: %t\n", arg);
  return (PTPT_ATerm)NULL;
}

/*}}}  */
/*{{{  PTPT_ATerm PTPT_setATermTrm(PTPT_ATerm arg, PTPT_ATerm trm) */

PTPT_ATerm PTPT_setATermTrm(PTPT_ATerm arg, PTPT_ATerm trm)
{
  if (PTPT_isATermAnnotated(arg)) {
    return (PTPT_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) trm), 0), 1);
  }

  ATabort("ATerm has no Trm: %t\n", arg);
  return (PTPT_ATerm)NULL;
}

/*}}}  */
/*{{{  PTPT_ATerm PTPT_setATermWsAfterTrm(PTPT_ATerm arg, PTPT_OptLayout wsAfterTrm) */

PTPT_ATerm PTPT_setATermWsAfterTrm(PTPT_ATerm arg, PTPT_OptLayout wsAfterTrm)
{
  if (PTPT_isATermAnnotated(arg)) {
    return (PTPT_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterTrm), 1), 1);
  }

  ATabort("ATerm has no WsAfterTrm: %t\n", arg);
  return (PTPT_ATerm)NULL;
}

/*}}}  */
/*{{{  PTPT_ATerm PTPT_setATermAnnotation(PTPT_ATerm arg, PTPT_Annotation Annotation) */

PTPT_ATerm PTPT_setATermAnnotation(PTPT_ATerm arg, PTPT_Annotation Annotation)
{
  if (PTPT_isATermAnnotated(arg)) {
    return (PTPT_ATerm)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Annotation), 2), 1);
  }

  ATabort("ATerm has no Annotation: %t\n", arg);
  return (PTPT_ATerm)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTPT_Annotation accessors */

/*{{{  ATbool PTPT_isValidAnnotation(PTPT_Annotation arg) */

ATbool PTPT_isValidAnnotation(PTPT_Annotation arg)
{
  if (PTPT_isAnnotationDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isAnnotationDefault(PTPT_Annotation arg) */

inline ATbool PTPT_isAnnotationDefault(PTPT_Annotation arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTPT_patternAnnotationDefault, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PTPT_hasAnnotationWsAfterBraceOpen(PTPT_Annotation arg) */

ATbool PTPT_hasAnnotationWsAfterBraceOpen(PTPT_Annotation arg)
{
  if (PTPT_isAnnotationDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasAnnotationAnnos(PTPT_Annotation arg) */

ATbool PTPT_hasAnnotationAnnos(PTPT_Annotation arg)
{
  if (PTPT_isAnnotationDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasAnnotationWsAfterAnnos(PTPT_Annotation arg) */

ATbool PTPT_hasAnnotationWsAfterAnnos(PTPT_Annotation arg)
{
  if (PTPT_isAnnotationDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getAnnotationWsAfterBraceOpen(PTPT_Annotation arg) */

PTPT_OptLayout PTPT_getAnnotationWsAfterBraceOpen(PTPT_Annotation arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_ATermAnnos PTPT_getAnnotationAnnos(PTPT_Annotation arg) */

PTPT_ATermAnnos PTPT_getAnnotationAnnos(PTPT_Annotation arg)
{
  
    return (PTPT_ATermAnnos)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), 1);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getAnnotationWsAfterAnnos(PTPT_Annotation arg) */

PTPT_OptLayout PTPT_getAnnotationWsAfterAnnos(PTPT_Annotation arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  PTPT_Annotation PTPT_setAnnotationWsAfterBraceOpen(PTPT_Annotation arg, PTPT_OptLayout wsAfterBraceOpen) */

PTPT_Annotation PTPT_setAnnotationWsAfterBraceOpen(PTPT_Annotation arg, PTPT_OptLayout wsAfterBraceOpen)
{
  if (PTPT_isAnnotationDefault(arg)) {
    return (PTPT_Annotation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBraceOpen), 1), 1);
  }

  ATabort("Annotation has no WsAfterBraceOpen: %t\n", arg);
  return (PTPT_Annotation)NULL;
}

/*}}}  */
/*{{{  PTPT_Annotation PTPT_setAnnotationAnnos(PTPT_Annotation arg, PTPT_ATermAnnos annos) */

PTPT_Annotation PTPT_setAnnotationAnnos(PTPT_Annotation arg, PTPT_ATermAnnos annos)
{
  if (PTPT_isAnnotationDefault(arg)) {
    return (PTPT_Annotation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), (ATerm)((ATerm) annos), 1), 2), 1);
  }

  ATabort("Annotation has no Annos: %t\n", arg);
  return (PTPT_Annotation)NULL;
}

/*}}}  */
/*{{{  PTPT_Annotation PTPT_setAnnotationWsAfterAnnos(PTPT_Annotation arg, PTPT_OptLayout wsAfterAnnos) */

PTPT_Annotation PTPT_setAnnotationWsAfterAnnos(PTPT_Annotation arg, PTPT_OptLayout wsAfterAnnos)
{
  if (PTPT_isAnnotationDefault(arg)) {
    return (PTPT_Annotation)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterAnnos), 3), 1);
  }

  ATabort("Annotation has no WsAfterAnnos: %t\n", arg);
  return (PTPT_Annotation)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTPT_ATermArgs accessors */

/*{{{  ATbool PTPT_isValidATermArgs(PTPT_ATermArgs arg) */

ATbool PTPT_isValidATermArgs(PTPT_ATermArgs arg)
{
  if (PTPT_isATermArgsEmpty(arg)) {
    return ATtrue;
  }
  else if (PTPT_isATermArgsSingle(arg)) {
    return ATtrue;
  }
  else if (PTPT_isATermArgsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isATermArgsEmpty(PTPT_ATermArgs arg) */

inline ATbool PTPT_isATermArgsEmpty(PTPT_ATermArgs arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTPT_patternATermArgsEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isATermArgsSingle(PTPT_ATermArgs arg) */

inline ATbool PTPT_isATermArgsSingle(PTPT_ATermArgs arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternATermArgsSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isATermArgsMany(PTPT_ATermArgs arg) */

inline ATbool PTPT_isATermArgsMany(PTPT_ATermArgs arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternATermArgsMany, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PTPT_hasATermArgsHead(PTPT_ATermArgs arg) */

ATbool PTPT_hasATermArgsHead(PTPT_ATermArgs arg)
{
  if (PTPT_isATermArgsSingle(arg)) {
    return ATtrue;
  }
  else if (PTPT_isATermArgsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasATermArgsWsAfterHead(PTPT_ATermArgs arg) */

ATbool PTPT_hasATermArgsWsAfterHead(PTPT_ATermArgs arg)
{
  if (PTPT_isATermArgsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasATermArgsWsAfterSep(PTPT_ATermArgs arg) */

ATbool PTPT_hasATermArgsWsAfterSep(PTPT_ATermArgs arg)
{
  if (PTPT_isATermArgsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasATermArgsTail(PTPT_ATermArgs arg) */

ATbool PTPT_hasATermArgsTail(PTPT_ATermArgs arg)
{
  if (PTPT_isATermArgsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTPT_ATermArgs PTPT_getATermArgsTail(PTPT_ATermArgs arg) */

PTPT_ATermArgs PTPT_getATermArgsTail(PTPT_ATermArgs arg)
{
  assert(!PTPT_isATermArgsEmpty(arg) && "getTail on an empty list");
  if (PTPT_isATermArgsSingle(arg)) {
    return (PTPT_ATermArgs) PTPT_makeATermArgsEmpty();
  }
  else {
  
    return (PTPT_ATermArgs)ATgetTail((ATermList)arg, 4);
  }
}

/*}}}  */
/*{{{  PTPT_ATerm PTPT_getATermArgsHead(PTPT_ATermArgs arg) */

PTPT_ATerm PTPT_getATermArgsHead(PTPT_ATermArgs arg)
{
  if (PTPT_isATermArgsSingle(arg)) {
    return (PTPT_ATerm)ATgetFirst((ATermList)arg);
  }
  else 
    return (PTPT_ATerm)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getATermArgsWsAfterHead(PTPT_ATermArgs arg) */

PTPT_OptLayout PTPT_getATermArgsWsAfterHead(PTPT_ATermArgs arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getATermArgsWsAfterSep(PTPT_ATermArgs arg) */

PTPT_OptLayout PTPT_getATermArgsWsAfterSep(PTPT_ATermArgs arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  PTPT_ATermArgs PTPT_setATermArgsHead(PTPT_ATermArgs arg, PTPT_ATerm head) */

PTPT_ATermArgs PTPT_setATermArgsHead(PTPT_ATermArgs arg, PTPT_ATerm head)
{
  if (PTPT_isATermArgsSingle(arg)) {
    return (PTPT_ATermArgs)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (PTPT_isATermArgsMany(arg)) {
    return (PTPT_ATermArgs)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("ATermArgs has no Head: %t\n", arg);
  return (PTPT_ATermArgs)NULL;
}

/*}}}  */
/*{{{  PTPT_ATermArgs PTPT_setATermArgsWsAfterHead(PTPT_ATermArgs arg, PTPT_OptLayout wsAfterHead) */

PTPT_ATermArgs PTPT_setATermArgsWsAfterHead(PTPT_ATermArgs arg, PTPT_OptLayout wsAfterHead)
{
  if (PTPT_isATermArgsMany(arg)) {
    return (PTPT_ATermArgs)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterHead), 1);
  }

  ATabort("ATermArgs has no WsAfterHead: %t\n", arg);
  return (PTPT_ATermArgs)NULL;
}

/*}}}  */
/*{{{  PTPT_ATermArgs PTPT_setATermArgsWsAfterSep(PTPT_ATermArgs arg, PTPT_OptLayout wsAfterSep) */

PTPT_ATermArgs PTPT_setATermArgsWsAfterSep(PTPT_ATermArgs arg, PTPT_OptLayout wsAfterSep)
{
  if (PTPT_isATermArgsMany(arg)) {
    return (PTPT_ATermArgs)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterSep), 3);
  }

  ATabort("ATermArgs has no WsAfterSep: %t\n", arg);
  return (PTPT_ATermArgs)NULL;
}

/*}}}  */
/*{{{  PTPT_ATermArgs PTPT_setATermArgsTail(PTPT_ATermArgs arg, PTPT_ATermArgs tail) */

PTPT_ATermArgs PTPT_setATermArgsTail(PTPT_ATermArgs arg, PTPT_ATermArgs tail)
{
  if (PTPT_isATermArgsMany(arg)) {
    return (PTPT_ATermArgs)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 4);
  }

  ATabort("ATermArgs has no Tail: %t\n", arg);
  return (PTPT_ATermArgs)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTPT_ATermElems accessors */

/*{{{  ATbool PTPT_isValidATermElems(PTPT_ATermElems arg) */

ATbool PTPT_isValidATermElems(PTPT_ATermElems arg)
{
  if (PTPT_isATermElemsEmpty(arg)) {
    return ATtrue;
  }
  else if (PTPT_isATermElemsSingle(arg)) {
    return ATtrue;
  }
  else if (PTPT_isATermElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isATermElemsEmpty(PTPT_ATermElems arg) */

inline ATbool PTPT_isATermElemsEmpty(PTPT_ATermElems arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTPT_patternATermElemsEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isATermElemsSingle(PTPT_ATermElems arg) */

inline ATbool PTPT_isATermElemsSingle(PTPT_ATermElems arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternATermElemsSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isATermElemsMany(PTPT_ATermElems arg) */

inline ATbool PTPT_isATermElemsMany(PTPT_ATermElems arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternATermElemsMany, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PTPT_hasATermElemsHead(PTPT_ATermElems arg) */

ATbool PTPT_hasATermElemsHead(PTPT_ATermElems arg)
{
  if (PTPT_isATermElemsSingle(arg)) {
    return ATtrue;
  }
  else if (PTPT_isATermElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasATermElemsWsAfterHead(PTPT_ATermElems arg) */

ATbool PTPT_hasATermElemsWsAfterHead(PTPT_ATermElems arg)
{
  if (PTPT_isATermElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasATermElemsWsAfterSep(PTPT_ATermElems arg) */

ATbool PTPT_hasATermElemsWsAfterSep(PTPT_ATermElems arg)
{
  if (PTPT_isATermElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasATermElemsTail(PTPT_ATermElems arg) */

ATbool PTPT_hasATermElemsTail(PTPT_ATermElems arg)
{
  if (PTPT_isATermElemsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTPT_ATermElems PTPT_getATermElemsTail(PTPT_ATermElems arg) */

PTPT_ATermElems PTPT_getATermElemsTail(PTPT_ATermElems arg)
{
  assert(!PTPT_isATermElemsEmpty(arg) && "getTail on an empty list");
  if (PTPT_isATermElemsSingle(arg)) {
    return (PTPT_ATermElems) PTPT_makeATermElemsEmpty();
  }
  else {
  
    return (PTPT_ATermElems)ATgetTail((ATermList)arg, 4);
  }
}

/*}}}  */
/*{{{  PTPT_ATerm PTPT_getATermElemsHead(PTPT_ATermElems arg) */

PTPT_ATerm PTPT_getATermElemsHead(PTPT_ATermElems arg)
{
  if (PTPT_isATermElemsSingle(arg)) {
    return (PTPT_ATerm)ATgetFirst((ATermList)arg);
  }
  else 
    return (PTPT_ATerm)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getATermElemsWsAfterHead(PTPT_ATermElems arg) */

PTPT_OptLayout PTPT_getATermElemsWsAfterHead(PTPT_ATermElems arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getATermElemsWsAfterSep(PTPT_ATermElems arg) */

PTPT_OptLayout PTPT_getATermElemsWsAfterSep(PTPT_ATermElems arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  PTPT_ATermElems PTPT_setATermElemsHead(PTPT_ATermElems arg, PTPT_ATerm head) */

PTPT_ATermElems PTPT_setATermElemsHead(PTPT_ATermElems arg, PTPT_ATerm head)
{
  if (PTPT_isATermElemsSingle(arg)) {
    return (PTPT_ATermElems)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (PTPT_isATermElemsMany(arg)) {
    return (PTPT_ATermElems)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("ATermElems has no Head: %t\n", arg);
  return (PTPT_ATermElems)NULL;
}

/*}}}  */
/*{{{  PTPT_ATermElems PTPT_setATermElemsWsAfterHead(PTPT_ATermElems arg, PTPT_OptLayout wsAfterHead) */

PTPT_ATermElems PTPT_setATermElemsWsAfterHead(PTPT_ATermElems arg, PTPT_OptLayout wsAfterHead)
{
  if (PTPT_isATermElemsMany(arg)) {
    return (PTPT_ATermElems)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterHead), 1);
  }

  ATabort("ATermElems has no WsAfterHead: %t\n", arg);
  return (PTPT_ATermElems)NULL;
}

/*}}}  */
/*{{{  PTPT_ATermElems PTPT_setATermElemsWsAfterSep(PTPT_ATermElems arg, PTPT_OptLayout wsAfterSep) */

PTPT_ATermElems PTPT_setATermElemsWsAfterSep(PTPT_ATermElems arg, PTPT_OptLayout wsAfterSep)
{
  if (PTPT_isATermElemsMany(arg)) {
    return (PTPT_ATermElems)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterSep), 3);
  }

  ATabort("ATermElems has no WsAfterSep: %t\n", arg);
  return (PTPT_ATermElems)NULL;
}

/*}}}  */
/*{{{  PTPT_ATermElems PTPT_setATermElemsTail(PTPT_ATermElems arg, PTPT_ATermElems tail) */

PTPT_ATermElems PTPT_setATermElemsTail(PTPT_ATermElems arg, PTPT_ATermElems tail)
{
  if (PTPT_isATermElemsMany(arg)) {
    return (PTPT_ATermElems)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 4);
  }

  ATabort("ATermElems has no Tail: %t\n", arg);
  return (PTPT_ATermElems)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTPT_ATermAnnos accessors */

/*{{{  ATbool PTPT_isValidATermAnnos(PTPT_ATermAnnos arg) */

ATbool PTPT_isValidATermAnnos(PTPT_ATermAnnos arg)
{
  if (PTPT_isATermAnnosEmpty(arg)) {
    return ATtrue;
  }
  else if (PTPT_isATermAnnosSingle(arg)) {
    return ATtrue;
  }
  else if (PTPT_isATermAnnosMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isATermAnnosEmpty(PTPT_ATermAnnos arg) */

inline ATbool PTPT_isATermAnnosEmpty(PTPT_ATermAnnos arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTPT_patternATermAnnosEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isATermAnnosSingle(PTPT_ATermAnnos arg) */

inline ATbool PTPT_isATermAnnosSingle(PTPT_ATermAnnos arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternATermAnnosSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isATermAnnosMany(PTPT_ATermAnnos arg) */

inline ATbool PTPT_isATermAnnosMany(PTPT_ATermAnnos arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternATermAnnosMany, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PTPT_hasATermAnnosHead(PTPT_ATermAnnos arg) */

ATbool PTPT_hasATermAnnosHead(PTPT_ATermAnnos arg)
{
  if (PTPT_isATermAnnosSingle(arg)) {
    return ATtrue;
  }
  else if (PTPT_isATermAnnosMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasATermAnnosWsAfterHead(PTPT_ATermAnnos arg) */

ATbool PTPT_hasATermAnnosWsAfterHead(PTPT_ATermAnnos arg)
{
  if (PTPT_isATermAnnosMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasATermAnnosWsAfterSep(PTPT_ATermAnnos arg) */

ATbool PTPT_hasATermAnnosWsAfterSep(PTPT_ATermAnnos arg)
{
  if (PTPT_isATermAnnosMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasATermAnnosTail(PTPT_ATermAnnos arg) */

ATbool PTPT_hasATermAnnosTail(PTPT_ATermAnnos arg)
{
  if (PTPT_isATermAnnosMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTPT_ATermAnnos PTPT_getATermAnnosTail(PTPT_ATermAnnos arg) */

PTPT_ATermAnnos PTPT_getATermAnnosTail(PTPT_ATermAnnos arg)
{
  assert(!PTPT_isATermAnnosEmpty(arg) && "getTail on an empty list");
  if (PTPT_isATermAnnosSingle(arg)) {
    return (PTPT_ATermAnnos) PTPT_makeATermAnnosEmpty();
  }
  else {
  
    return (PTPT_ATermAnnos)ATgetTail((ATermList)arg, 4);
  }
}

/*}}}  */
/*{{{  PTPT_ATerm PTPT_getATermAnnosHead(PTPT_ATermAnnos arg) */

PTPT_ATerm PTPT_getATermAnnosHead(PTPT_ATermAnnos arg)
{
  if (PTPT_isATermAnnosSingle(arg)) {
    return (PTPT_ATerm)ATgetFirst((ATermList)arg);
  }
  else 
    return (PTPT_ATerm)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getATermAnnosWsAfterHead(PTPT_ATermAnnos arg) */

PTPT_OptLayout PTPT_getATermAnnosWsAfterHead(PTPT_ATermAnnos arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getATermAnnosWsAfterSep(PTPT_ATermAnnos arg) */

PTPT_OptLayout PTPT_getATermAnnosWsAfterSep(PTPT_ATermAnnos arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  PTPT_ATermAnnos PTPT_setATermAnnosHead(PTPT_ATermAnnos arg, PTPT_ATerm head) */

PTPT_ATermAnnos PTPT_setATermAnnosHead(PTPT_ATermAnnos arg, PTPT_ATerm head)
{
  if (PTPT_isATermAnnosSingle(arg)) {
    return (PTPT_ATermAnnos)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (PTPT_isATermAnnosMany(arg)) {
    return (PTPT_ATermAnnos)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("ATermAnnos has no Head: %t\n", arg);
  return (PTPT_ATermAnnos)NULL;
}

/*}}}  */
/*{{{  PTPT_ATermAnnos PTPT_setATermAnnosWsAfterHead(PTPT_ATermAnnos arg, PTPT_OptLayout wsAfterHead) */

PTPT_ATermAnnos PTPT_setATermAnnosWsAfterHead(PTPT_ATermAnnos arg, PTPT_OptLayout wsAfterHead)
{
  if (PTPT_isATermAnnosMany(arg)) {
    return (PTPT_ATermAnnos)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterHead), 1);
  }

  ATabort("ATermAnnos has no WsAfterHead: %t\n", arg);
  return (PTPT_ATermAnnos)NULL;
}

/*}}}  */
/*{{{  PTPT_ATermAnnos PTPT_setATermAnnosWsAfterSep(PTPT_ATermAnnos arg, PTPT_OptLayout wsAfterSep) */

PTPT_ATermAnnos PTPT_setATermAnnosWsAfterSep(PTPT_ATermAnnos arg, PTPT_OptLayout wsAfterSep)
{
  if (PTPT_isATermAnnosMany(arg)) {
    return (PTPT_ATermAnnos)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterSep), 3);
  }

  ATabort("ATermAnnos has no WsAfterSep: %t\n", arg);
  return (PTPT_ATermAnnos)NULL;
}

/*}}}  */
/*{{{  PTPT_ATermAnnos PTPT_setATermAnnosTail(PTPT_ATermAnnos arg, PTPT_ATermAnnos tail) */

PTPT_ATermAnnos PTPT_setATermAnnosTail(PTPT_ATermAnnos arg, PTPT_ATermAnnos tail)
{
  if (PTPT_isATermAnnosMany(arg)) {
    return (PTPT_ATermAnnos)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 4);
  }

  ATabort("ATermAnnos has no Tail: %t\n", arg);
  return (PTPT_ATermAnnos)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTPT_IntCon accessors */

/*{{{  ATbool PTPT_isValidIntCon(PTPT_IntCon arg) */

ATbool PTPT_isValidIntCon(PTPT_IntCon arg)
{
  if (PTPT_isIntConNatural(arg)) {
    return ATtrue;
  }
  else if (PTPT_isIntConPositive(arg)) {
    return ATtrue;
  }
  else if (PTPT_isIntConNegative(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isIntConNatural(PTPT_IntCon arg) */

inline ATbool PTPT_isIntConNatural(PTPT_IntCon arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternIntConNatural, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isIntConPositive(PTPT_IntCon arg) */

inline ATbool PTPT_isIntConPositive(PTPT_IntCon arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternIntConPositive, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isIntConNegative(PTPT_IntCon arg) */

inline ATbool PTPT_isIntConNegative(PTPT_IntCon arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternIntConNegative, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PTPT_hasIntConNatCon(PTPT_IntCon arg) */

ATbool PTPT_hasIntConNatCon(PTPT_IntCon arg)
{
  if (PTPT_isIntConNatural(arg)) {
    return ATtrue;
  }
  else if (PTPT_isIntConPositive(arg)) {
    return ATtrue;
  }
  else if (PTPT_isIntConNegative(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasIntConWsAfterPos(PTPT_IntCon arg) */

ATbool PTPT_hasIntConWsAfterPos(PTPT_IntCon arg)
{
  if (PTPT_isIntConPositive(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasIntConWsAfterNeg(PTPT_IntCon arg) */

ATbool PTPT_hasIntConWsAfterNeg(PTPT_IntCon arg)
{
  if (PTPT_isIntConNegative(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTPT_NatCon PTPT_getIntConNatCon(PTPT_IntCon arg) */

PTPT_NatCon PTPT_getIntConNatCon(PTPT_IntCon arg)
{
  if (PTPT_isIntConNatural(arg)) {
    return (PTPT_NatCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (PTPT_isIntConPositive(arg)) {
    return (PTPT_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else 
    return (PTPT_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getIntConWsAfterPos(PTPT_IntCon arg) */

PTPT_OptLayout PTPT_getIntConWsAfterPos(PTPT_IntCon arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getIntConWsAfterNeg(PTPT_IntCon arg) */

PTPT_OptLayout PTPT_getIntConWsAfterNeg(PTPT_IntCon arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_IntCon PTPT_setIntConNatCon(PTPT_IntCon arg, PTPT_NatCon NatCon) */

PTPT_IntCon PTPT_setIntConNatCon(PTPT_IntCon arg, PTPT_NatCon NatCon)
{
  if (PTPT_isIntConNatural(arg)) {
    return (PTPT_IntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) NatCon), 0), 1);
  }
  else if (PTPT_isIntConPositive(arg)) {
    return (PTPT_IntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) NatCon), 2), 1);
  }
  else if (PTPT_isIntConNegative(arg)) {
    return (PTPT_IntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) NatCon), 2), 1);
  }

  ATabort("IntCon has no NatCon: %t\n", arg);
  return (PTPT_IntCon)NULL;
}

/*}}}  */
/*{{{  PTPT_IntCon PTPT_setIntConWsAfterPos(PTPT_IntCon arg, PTPT_OptLayout wsAfterPos) */

PTPT_IntCon PTPT_setIntConWsAfterPos(PTPT_IntCon arg, PTPT_OptLayout wsAfterPos)
{
  if (PTPT_isIntConPositive(arg)) {
    return (PTPT_IntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterPos), 1), 1);
  }

  ATabort("IntCon has no WsAfterPos: %t\n", arg);
  return (PTPT_IntCon)NULL;
}

/*}}}  */
/*{{{  PTPT_IntCon PTPT_setIntConWsAfterNeg(PTPT_IntCon arg, PTPT_OptLayout wsAfterNeg) */

PTPT_IntCon PTPT_setIntConWsAfterNeg(PTPT_IntCon arg, PTPT_OptLayout wsAfterNeg)
{
  if (PTPT_isIntConNegative(arg)) {
    return (PTPT_IntCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterNeg), 1), 1);
  }

  ATabort("IntCon has no WsAfterNeg: %t\n", arg);
  return (PTPT_IntCon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTPT_OptExp accessors */

/*{{{  ATbool PTPT_isValidOptExp(PTPT_OptExp arg) */

ATbool PTPT_isValidOptExp(PTPT_OptExp arg)
{
  if (PTPT_isOptExpPresent(arg)) {
    return ATtrue;
  }
  else if (PTPT_isOptExpAbsent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isOptExpPresent(PTPT_OptExp arg) */

inline ATbool PTPT_isOptExpPresent(PTPT_OptExp arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternOptExpPresent, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isOptExpAbsent(PTPT_OptExp arg) */

inline ATbool PTPT_isOptExpAbsent(PTPT_OptExp arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternOptExpAbsent);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PTPT_hasOptExpWsAfterE(PTPT_OptExp arg) */

ATbool PTPT_hasOptExpWsAfterE(PTPT_OptExp arg)
{
  if (PTPT_isOptExpPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasOptExpIntCon(PTPT_OptExp arg) */

ATbool PTPT_hasOptExpIntCon(PTPT_OptExp arg)
{
  if (PTPT_isOptExpPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getOptExpWsAfterE(PTPT_OptExp arg) */

PTPT_OptLayout PTPT_getOptExpWsAfterE(PTPT_OptExp arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_IntCon PTPT_getOptExpIntCon(PTPT_OptExp arg) */

PTPT_IntCon PTPT_getOptExpIntCon(PTPT_OptExp arg)
{
  
    return (PTPT_IntCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  PTPT_OptExp PTPT_setOptExpWsAfterE(PTPT_OptExp arg, PTPT_OptLayout wsAfterE) */

PTPT_OptExp PTPT_setOptExpWsAfterE(PTPT_OptExp arg, PTPT_OptLayout wsAfterE)
{
  if (PTPT_isOptExpPresent(arg)) {
    return (PTPT_OptExp)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterE), 1), 1);
  }

  ATabort("OptExp has no WsAfterE: %t\n", arg);
  return (PTPT_OptExp)NULL;
}

/*}}}  */
/*{{{  PTPT_OptExp PTPT_setOptExpIntCon(PTPT_OptExp arg, PTPT_IntCon IntCon) */

PTPT_OptExp PTPT_setOptExpIntCon(PTPT_OptExp arg, PTPT_IntCon IntCon)
{
  if (PTPT_isOptExpPresent(arg)) {
    return (PTPT_OptExp)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) IntCon), 2), 1);
  }

  ATabort("OptExp has no IntCon: %t\n", arg);
  return (PTPT_OptExp)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTPT_RealCon accessors */

/*{{{  ATbool PTPT_isValidRealCon(PTPT_RealCon arg) */

ATbool PTPT_isValidRealCon(PTPT_RealCon arg)
{
  if (PTPT_isRealConRealCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isRealConRealCon(PTPT_RealCon arg) */

inline ATbool PTPT_isRealConRealCon(PTPT_RealCon arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTPT_patternRealConRealCon, NULL, NULL, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PTPT_hasRealConBase(PTPT_RealCon arg) */

ATbool PTPT_hasRealConBase(PTPT_RealCon arg)
{
  if (PTPT_isRealConRealCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasRealConWsAfterBase(PTPT_RealCon arg) */

ATbool PTPT_hasRealConWsAfterBase(PTPT_RealCon arg)
{
  if (PTPT_isRealConRealCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasRealConWsAfterPeriod(PTPT_RealCon arg) */

ATbool PTPT_hasRealConWsAfterPeriod(PTPT_RealCon arg)
{
  if (PTPT_isRealConRealCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasRealConDecimal(PTPT_RealCon arg) */

ATbool PTPT_hasRealConDecimal(PTPT_RealCon arg)
{
  if (PTPT_isRealConRealCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasRealConWsAfterDecimal(PTPT_RealCon arg) */

ATbool PTPT_hasRealConWsAfterDecimal(PTPT_RealCon arg)
{
  if (PTPT_isRealConRealCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasRealConExp(PTPT_RealCon arg) */

ATbool PTPT_hasRealConExp(PTPT_RealCon arg)
{
  if (PTPT_isRealConRealCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTPT_IntCon PTPT_getRealConBase(PTPT_RealCon arg) */

PTPT_IntCon PTPT_getRealConBase(PTPT_RealCon arg)
{
  
    return (PTPT_IntCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getRealConWsAfterBase(PTPT_RealCon arg) */

PTPT_OptLayout PTPT_getRealConWsAfterBase(PTPT_RealCon arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getRealConWsAfterPeriod(PTPT_RealCon arg) */

PTPT_OptLayout PTPT_getRealConWsAfterPeriod(PTPT_RealCon arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  PTPT_NatCon PTPT_getRealConDecimal(PTPT_RealCon arg) */

PTPT_NatCon PTPT_getRealConDecimal(PTPT_RealCon arg)
{
  
    return (PTPT_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PTPT_OptLayout PTPT_getRealConWsAfterDecimal(PTPT_RealCon arg) */

PTPT_OptLayout PTPT_getRealConWsAfterDecimal(PTPT_RealCon arg)
{
  
    return (PTPT_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PTPT_OptExp PTPT_getRealConExp(PTPT_RealCon arg) */

PTPT_OptExp PTPT_getRealConExp(PTPT_RealCon arg)
{
  
    return (PTPT_OptExp)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6);
}

/*}}}  */
/*{{{  PTPT_RealCon PTPT_setRealConBase(PTPT_RealCon arg, PTPT_IntCon base) */

PTPT_RealCon PTPT_setRealConBase(PTPT_RealCon arg, PTPT_IntCon base)
{
  if (PTPT_isRealConRealCon(arg)) {
    return (PTPT_RealCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) base), 0), 1);
  }

  ATabort("RealCon has no Base: %t\n", arg);
  return (PTPT_RealCon)NULL;
}

/*}}}  */
/*{{{  PTPT_RealCon PTPT_setRealConWsAfterBase(PTPT_RealCon arg, PTPT_OptLayout wsAfterBase) */

PTPT_RealCon PTPT_setRealConWsAfterBase(PTPT_RealCon arg, PTPT_OptLayout wsAfterBase)
{
  if (PTPT_isRealConRealCon(arg)) {
    return (PTPT_RealCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBase), 1), 1);
  }

  ATabort("RealCon has no WsAfterBase: %t\n", arg);
  return (PTPT_RealCon)NULL;
}

/*}}}  */
/*{{{  PTPT_RealCon PTPT_setRealConWsAfterPeriod(PTPT_RealCon arg, PTPT_OptLayout wsAfterPeriod) */

PTPT_RealCon PTPT_setRealConWsAfterPeriod(PTPT_RealCon arg, PTPT_OptLayout wsAfterPeriod)
{
  if (PTPT_isRealConRealCon(arg)) {
    return (PTPT_RealCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterPeriod), 3), 1);
  }

  ATabort("RealCon has no WsAfterPeriod: %t\n", arg);
  return (PTPT_RealCon)NULL;
}

/*}}}  */
/*{{{  PTPT_RealCon PTPT_setRealConDecimal(PTPT_RealCon arg, PTPT_NatCon decimal) */

PTPT_RealCon PTPT_setRealConDecimal(PTPT_RealCon arg, PTPT_NatCon decimal)
{
  if (PTPT_isRealConRealCon(arg)) {
    return (PTPT_RealCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) decimal), 4), 1);
  }

  ATabort("RealCon has no Decimal: %t\n", arg);
  return (PTPT_RealCon)NULL;
}

/*}}}  */
/*{{{  PTPT_RealCon PTPT_setRealConWsAfterDecimal(PTPT_RealCon arg, PTPT_OptLayout wsAfterDecimal) */

PTPT_RealCon PTPT_setRealConWsAfterDecimal(PTPT_RealCon arg, PTPT_OptLayout wsAfterDecimal)
{
  if (PTPT_isRealConRealCon(arg)) {
    return (PTPT_RealCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterDecimal), 5), 1);
  }

  ATabort("RealCon has no WsAfterDecimal: %t\n", arg);
  return (PTPT_RealCon)NULL;
}

/*}}}  */
/*{{{  PTPT_RealCon PTPT_setRealConExp(PTPT_RealCon arg, PTPT_OptExp exp) */

PTPT_RealCon PTPT_setRealConExp(PTPT_RealCon arg, PTPT_OptExp exp)
{
  if (PTPT_isRealConRealCon(arg)) {
    return (PTPT_RealCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) exp), 6), 1);
  }

  ATabort("RealCon has no Exp: %t\n", arg);
  return (PTPT_RealCon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTPT_LexStrChar accessors */

/*{{{  ATbool PTPT_isValidLexStrChar(PTPT_LexStrChar arg) */

ATbool PTPT_isValidLexStrChar(PTPT_LexStrChar arg)
{
  if (PTPT_isLexStrCharNewline(arg)) {
    return ATtrue;
  }
  else if (PTPT_isLexStrCharTab(arg)) {
    return ATtrue;
  }
  else if (PTPT_isLexStrCharQuote(arg)) {
    return ATtrue;
  }
  else if (PTPT_isLexStrCharBackslash(arg)) {
    return ATtrue;
  }
  else if (PTPT_isLexStrCharDecimal(arg)) {
    return ATtrue;
  }
  else if (PTPT_isLexStrCharNormal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isLexStrCharNewline(PTPT_LexStrChar arg) */

inline ATbool PTPT_isLexStrCharNewline(PTPT_LexStrChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternLexStrCharNewline);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isLexStrCharTab(PTPT_LexStrChar arg) */

inline ATbool PTPT_isLexStrCharTab(PTPT_LexStrChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternLexStrCharTab);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isLexStrCharQuote(PTPT_LexStrChar arg) */

inline ATbool PTPT_isLexStrCharQuote(PTPT_LexStrChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternLexStrCharQuote);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isLexStrCharBackslash(PTPT_LexStrChar arg) */

inline ATbool PTPT_isLexStrCharBackslash(PTPT_LexStrChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternLexStrCharBackslash);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isLexStrCharDecimal(PTPT_LexStrChar arg) */

inline ATbool PTPT_isLexStrCharDecimal(PTPT_LexStrChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternLexStrCharDecimal, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isLexStrCharNormal(PTPT_LexStrChar arg) */

inline ATbool PTPT_isLexStrCharNormal(PTPT_LexStrChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternLexStrCharNormal, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PTPT_hasLexStrCharA(PTPT_LexStrChar arg) */

ATbool PTPT_hasLexStrCharA(PTPT_LexStrChar arg)
{
  if (PTPT_isLexStrCharDecimal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasLexStrCharB(PTPT_LexStrChar arg) */

ATbool PTPT_hasLexStrCharB(PTPT_LexStrChar arg)
{
  if (PTPT_isLexStrCharDecimal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasLexStrCharC(PTPT_LexStrChar arg) */

ATbool PTPT_hasLexStrCharC(PTPT_LexStrChar arg)
{
  if (PTPT_isLexStrCharDecimal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasLexStrCharCh(PTPT_LexStrChar arg) */

ATbool PTPT_hasLexStrCharCh(PTPT_LexStrChar arg)
{
  if (PTPT_isLexStrCharNormal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char PTPT_getLexStrCharA(PTPT_LexStrChar arg) */

char PTPT_getLexStrCharA(PTPT_LexStrChar arg)
{
  
    return (char)PTPT_charToByte((ATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1));
}

/*}}}  */
/*{{{  char PTPT_getLexStrCharB(PTPT_LexStrChar arg) */

char PTPT_getLexStrCharB(PTPT_LexStrChar arg)
{
  
    return (char)PTPT_charToByte((ATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2));
}

/*}}}  */
/*{{{  char PTPT_getLexStrCharC(PTPT_LexStrChar arg) */

char PTPT_getLexStrCharC(PTPT_LexStrChar arg)
{
  
    return (char)PTPT_charToByte((ATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3));
}

/*}}}  */
/*{{{  char PTPT_getLexStrCharCh(PTPT_LexStrChar arg) */

char PTPT_getLexStrCharCh(PTPT_LexStrChar arg)
{
  
    return (char)PTPT_charToByte((ATerm)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  PTPT_LexStrChar PTPT_setLexStrCharA(PTPT_LexStrChar arg, char a) */

PTPT_LexStrChar PTPT_setLexStrCharA(PTPT_LexStrChar arg, char a)
{
  if (PTPT_isLexStrCharDecimal(arg)) {
    return (PTPT_LexStrChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) PTPT_byteToChar(a))), 1), 1);
  }

  ATabort("LexStrChar has no A: %t\n", arg);
  return (PTPT_LexStrChar)NULL;
}

/*}}}  */
/*{{{  PTPT_LexStrChar PTPT_setLexStrCharB(PTPT_LexStrChar arg, char b) */

PTPT_LexStrChar PTPT_setLexStrCharB(PTPT_LexStrChar arg, char b)
{
  if (PTPT_isLexStrCharDecimal(arg)) {
    return (PTPT_LexStrChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) PTPT_byteToChar(b))), 2), 1);
  }

  ATabort("LexStrChar has no B: %t\n", arg);
  return (PTPT_LexStrChar)NULL;
}

/*}}}  */
/*{{{  PTPT_LexStrChar PTPT_setLexStrCharC(PTPT_LexStrChar arg, char c) */

PTPT_LexStrChar PTPT_setLexStrCharC(PTPT_LexStrChar arg, char c)
{
  if (PTPT_isLexStrCharDecimal(arg)) {
    return (PTPT_LexStrChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) PTPT_byteToChar(c))), 3), 1);
  }

  ATabort("LexStrChar has no C: %t\n", arg);
  return (PTPT_LexStrChar)NULL;
}

/*}}}  */
/*{{{  PTPT_LexStrChar PTPT_setLexStrCharCh(PTPT_LexStrChar arg, char ch) */

PTPT_LexStrChar PTPT_setLexStrCharCh(PTPT_LexStrChar arg, char ch)
{
  if (PTPT_isLexStrCharNormal(arg)) {
    return (PTPT_LexStrChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) PTPT_byteToChar(ch))), 0), 1);
  }

  ATabort("LexStrChar has no Ch: %t\n", arg);
  return (PTPT_LexStrChar)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTPT_StrChar accessors */

/*{{{  ATbool PTPT_isValidStrChar(PTPT_StrChar arg) */

ATbool PTPT_isValidStrChar(PTPT_StrChar arg)
{
  if (PTPT_isStrCharLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isStrCharLexToCf(PTPT_StrChar arg) */

inline ATbool PTPT_isStrCharLexToCf(PTPT_StrChar arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTPT_patternStrCharLexToCf, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PTPT_hasStrCharStrChar(PTPT_StrChar arg) */

ATbool PTPT_hasStrCharStrChar(PTPT_StrChar arg)
{
  if (PTPT_isStrCharLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTPT_LexStrChar PTPT_getStrCharStrChar(PTPT_StrChar arg) */

PTPT_LexStrChar PTPT_getStrCharStrChar(PTPT_StrChar arg)
{
  
    return (PTPT_LexStrChar)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  PTPT_StrChar PTPT_setStrCharStrChar(PTPT_StrChar arg, PTPT_LexStrChar StrChar) */

PTPT_StrChar PTPT_setStrCharStrChar(PTPT_StrChar arg, PTPT_LexStrChar StrChar)
{
  if (PTPT_isStrCharLexToCf(arg)) {
    return (PTPT_StrChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) StrChar), 0), 1);
  }

  ATabort("StrChar has no StrChar: %t\n", arg);
  return (PTPT_StrChar)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTPT_LexStrCon accessors */

/*{{{  ATbool PTPT_isValidLexStrCon(PTPT_LexStrCon arg) */

ATbool PTPT_isValidLexStrCon(PTPT_LexStrCon arg)
{
  if (PTPT_isLexStrConDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isLexStrConDefault(PTPT_LexStrCon arg) */

inline ATbool PTPT_isLexStrConDefault(PTPT_LexStrCon arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTPT_patternLexStrConDefault, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PTPT_hasLexStrConChars(PTPT_LexStrCon arg) */

ATbool PTPT_hasLexStrConChars(PTPT_LexStrCon arg)
{
  if (PTPT_isLexStrConDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTPT_LexStrCharChars PTPT_getLexStrConChars(PTPT_LexStrCon arg) */

PTPT_LexStrCharChars PTPT_getLexStrConChars(PTPT_LexStrCon arg)
{
  
    return (PTPT_LexStrCharChars)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1), 1);
}

/*}}}  */
/*{{{  PTPT_LexStrCon PTPT_setLexStrConChars(PTPT_LexStrCon arg, PTPT_LexStrCharChars chars) */

PTPT_LexStrCon PTPT_setLexStrConChars(PTPT_LexStrCon arg, PTPT_LexStrCharChars chars)
{
  if (PTPT_isLexStrConDefault(arg)) {
    return (PTPT_LexStrCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1), (ATerm)((ATerm) chars), 1), 1), 1);
  }

  ATabort("LexStrCon has no Chars: %t\n", arg);
  return (PTPT_LexStrCon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTPT_StrCon accessors */

/*{{{  ATbool PTPT_isValidStrCon(PTPT_StrCon arg) */

ATbool PTPT_isValidStrCon(PTPT_StrCon arg)
{
  if (PTPT_isStrConLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isStrConLexToCf(PTPT_StrCon arg) */

inline ATbool PTPT_isStrConLexToCf(PTPT_StrCon arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTPT_patternStrConLexToCf, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PTPT_hasStrConStrCon(PTPT_StrCon arg) */

ATbool PTPT_hasStrConStrCon(PTPT_StrCon arg)
{
  if (PTPT_isStrConLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTPT_LexStrCon PTPT_getStrConStrCon(PTPT_StrCon arg) */

PTPT_LexStrCon PTPT_getStrConStrCon(PTPT_StrCon arg)
{
  
    return (PTPT_LexStrCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  PTPT_StrCon PTPT_setStrConStrCon(PTPT_StrCon arg, PTPT_LexStrCon StrCon) */

PTPT_StrCon PTPT_setStrConStrCon(PTPT_StrCon arg, PTPT_LexStrCon StrCon)
{
  if (PTPT_isStrConLexToCf(arg)) {
    return (PTPT_StrCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) StrCon), 0), 1);
  }

  ATabort("StrCon has no StrCon: %t\n", arg);
  return (PTPT_StrCon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTPT_LexStrCharChars accessors */

/*{{{  ATbool PTPT_isValidLexStrCharChars(PTPT_LexStrCharChars arg) */

ATbool PTPT_isValidLexStrCharChars(PTPT_LexStrCharChars arg)
{
  if (PTPT_isLexStrCharCharsEmpty(arg)) {
    return ATtrue;
  }
  else if (PTPT_isLexStrCharCharsSingle(arg)) {
    return ATtrue;
  }
  else if (PTPT_isLexStrCharCharsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isLexStrCharCharsEmpty(PTPT_LexStrCharChars arg) */

inline ATbool PTPT_isLexStrCharCharsEmpty(PTPT_LexStrCharChars arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTPT_patternLexStrCharCharsEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isLexStrCharCharsSingle(PTPT_LexStrCharChars arg) */

inline ATbool PTPT_isLexStrCharCharsSingle(PTPT_LexStrCharChars arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternLexStrCharCharsSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PTPT_isLexStrCharCharsMany(PTPT_LexStrCharChars arg) */

inline ATbool PTPT_isLexStrCharCharsMany(PTPT_LexStrCharChars arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PTPT_patternLexStrCharCharsMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PTPT_hasLexStrCharCharsHead(PTPT_LexStrCharChars arg) */

ATbool PTPT_hasLexStrCharCharsHead(PTPT_LexStrCharChars arg)
{
  if (PTPT_isLexStrCharCharsSingle(arg)) {
    return ATtrue;
  }
  else if (PTPT_isLexStrCharCharsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasLexStrCharCharsTail(PTPT_LexStrCharChars arg) */

ATbool PTPT_hasLexStrCharCharsTail(PTPT_LexStrCharChars arg)
{
  if (PTPT_isLexStrCharCharsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTPT_LexStrChar PTPT_getLexStrCharCharsHead(PTPT_LexStrCharChars arg) */

PTPT_LexStrChar PTPT_getLexStrCharCharsHead(PTPT_LexStrCharChars arg)
{
  if (PTPT_isLexStrCharCharsSingle(arg)) {
    return (PTPT_LexStrChar)ATgetFirst((ATermList)arg);
  }
  else 
    return (PTPT_LexStrChar)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  PTPT_LexStrCharChars PTPT_getLexStrCharCharsTail(PTPT_LexStrCharChars arg) */

PTPT_LexStrCharChars PTPT_getLexStrCharCharsTail(PTPT_LexStrCharChars arg)
{
  
    return (PTPT_LexStrCharChars)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  PTPT_LexStrCharChars PTPT_setLexStrCharCharsHead(PTPT_LexStrCharChars arg, PTPT_LexStrChar head) */

PTPT_LexStrCharChars PTPT_setLexStrCharCharsHead(PTPT_LexStrCharChars arg, PTPT_LexStrChar head)
{
  if (PTPT_isLexStrCharCharsSingle(arg)) {
    return (PTPT_LexStrCharChars)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (PTPT_isLexStrCharCharsMany(arg)) {
    return (PTPT_LexStrCharChars)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("LexStrCharChars has no Head: %t\n", arg);
  return (PTPT_LexStrCharChars)NULL;
}

/*}}}  */
/*{{{  PTPT_LexStrCharChars PTPT_setLexStrCharCharsTail(PTPT_LexStrCharChars arg, PTPT_LexStrCharChars tail) */

PTPT_LexStrCharChars PTPT_setLexStrCharCharsTail(PTPT_LexStrCharChars arg, PTPT_LexStrCharChars tail)
{
  if (PTPT_isLexStrCharCharsMany(arg)) {
    return (PTPT_LexStrCharChars)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("LexStrCharChars has no Tail: %t\n", arg);
  return (PTPT_LexStrCharChars)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTPT_LexNatCon accessors */

/*{{{  ATbool PTPT_isValidLexNatCon(PTPT_LexNatCon arg) */

ATbool PTPT_isValidLexNatCon(PTPT_LexNatCon arg)
{
  if (PTPT_isLexNatConDigits(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isLexNatConDigits(PTPT_LexNatCon arg) */

inline ATbool PTPT_isLexNatConDigits(PTPT_LexNatCon arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTPT_patternLexNatConDigits, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PTPT_hasLexNatConList(PTPT_LexNatCon arg) */

ATbool PTPT_hasLexNatConList(PTPT_LexNatCon arg)
{
  if (PTPT_isLexNatConDigits(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* PTPT_getLexNatConList(PTPT_LexNatCon arg) */

char* PTPT_getLexNatConList(PTPT_LexNatCon arg)
{
  
    return (char*)PTPT_charsToString((ATerm)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1));
}

/*}}}  */
/*{{{  PTPT_LexNatCon PTPT_setLexNatConList(PTPT_LexNatCon arg, const char* list) */

PTPT_LexNatCon PTPT_setLexNatConList(PTPT_LexNatCon arg, const char* list)
{
  if (PTPT_isLexNatConDigits(arg)) {
    return (PTPT_LexNatCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) ((ATerm) PTPT_stringToChars(list))), 1), 0), 1);
  }

  ATabort("LexNatCon has no List: %t\n", arg);
  return (PTPT_LexNatCon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTPT_NatCon accessors */

/*{{{  ATbool PTPT_isValidNatCon(PTPT_NatCon arg) */

ATbool PTPT_isValidNatCon(PTPT_NatCon arg)
{
  if (PTPT_isNatConLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isNatConLexToCf(PTPT_NatCon arg) */

inline ATbool PTPT_isNatConLexToCf(PTPT_NatCon arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTPT_patternNatConLexToCf, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PTPT_hasNatConNatCon(PTPT_NatCon arg) */

ATbool PTPT_hasNatConNatCon(PTPT_NatCon arg)
{
  if (PTPT_isNatConLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTPT_LexNatCon PTPT_getNatConNatCon(PTPT_NatCon arg) */

PTPT_LexNatCon PTPT_getNatConNatCon(PTPT_NatCon arg)
{
  
    return (PTPT_LexNatCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  PTPT_NatCon PTPT_setNatConNatCon(PTPT_NatCon arg, PTPT_LexNatCon NatCon) */

PTPT_NatCon PTPT_setNatConNatCon(PTPT_NatCon arg, PTPT_LexNatCon NatCon)
{
  if (PTPT_isNatConLexToCf(arg)) {
    return (PTPT_NatCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) NatCon), 0), 1);
  }

  ATabort("NatCon has no NatCon: %t\n", arg);
  return (PTPT_NatCon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTPT_LexIdCon accessors */

/*{{{  ATbool PTPT_isValidLexIdCon(PTPT_LexIdCon arg) */

ATbool PTPT_isValidLexIdCon(PTPT_LexIdCon arg)
{
  if (PTPT_isLexIdConDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isLexIdConDefault(PTPT_LexIdCon arg) */

inline ATbool PTPT_isLexIdConDefault(PTPT_LexIdCon arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTPT_patternLexIdConDefault, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PTPT_hasLexIdConHead(PTPT_LexIdCon arg) */

ATbool PTPT_hasLexIdConHead(PTPT_LexIdCon arg)
{
  if (PTPT_isLexIdConDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool PTPT_hasLexIdConTail(PTPT_LexIdCon arg) */

ATbool PTPT_hasLexIdConTail(PTPT_LexIdCon arg)
{
  if (PTPT_isLexIdConDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char PTPT_getLexIdConHead(PTPT_LexIdCon arg) */

char PTPT_getLexIdConHead(PTPT_LexIdCon arg)
{
  
    return (char)PTPT_charToByte((ATerm)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  char* PTPT_getLexIdConTail(PTPT_LexIdCon arg) */

char* PTPT_getLexIdConTail(PTPT_LexIdCon arg)
{
  
    return (char*)PTPT_charsToString((ATerm)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1), 1));
}

/*}}}  */
/*{{{  PTPT_LexIdCon PTPT_setLexIdConHead(PTPT_LexIdCon arg, char head) */

PTPT_LexIdCon PTPT_setLexIdConHead(PTPT_LexIdCon arg, char head)
{
  if (PTPT_isLexIdConDefault(arg)) {
    return (PTPT_LexIdCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) PTPT_byteToChar(head))), 0), 1);
  }

  ATabort("LexIdCon has no Head: %t\n", arg);
  return (PTPT_LexIdCon)NULL;
}

/*}}}  */
/*{{{  PTPT_LexIdCon PTPT_setLexIdConTail(PTPT_LexIdCon arg, const char* tail) */

PTPT_LexIdCon PTPT_setLexIdConTail(PTPT_LexIdCon arg, const char* tail)
{
  if (PTPT_isLexIdConDefault(arg)) {
    return (PTPT_LexIdCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1), (ATerm)((ATerm) ((ATerm) PTPT_stringToChars(tail))), 1), 1), 1);
  }

  ATabort("LexIdCon has no Tail: %t\n", arg);
  return (PTPT_LexIdCon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTPT_IdCon accessors */

/*{{{  ATbool PTPT_isValidIdCon(PTPT_IdCon arg) */

ATbool PTPT_isValidIdCon(PTPT_IdCon arg)
{
  if (PTPT_isIdConLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isIdConLexToCf(PTPT_IdCon arg) */

inline ATbool PTPT_isIdConLexToCf(PTPT_IdCon arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTPT_patternIdConLexToCf, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PTPT_hasIdConIdCon(PTPT_IdCon arg) */

ATbool PTPT_hasIdConIdCon(PTPT_IdCon arg)
{
  if (PTPT_isIdConLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PTPT_LexIdCon PTPT_getIdConIdCon(PTPT_IdCon arg) */

PTPT_LexIdCon PTPT_getIdConIdCon(PTPT_IdCon arg)
{
  
    return (PTPT_LexIdCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  PTPT_IdCon PTPT_setIdConIdCon(PTPT_IdCon arg, PTPT_LexIdCon IdCon) */

PTPT_IdCon PTPT_setIdConIdCon(PTPT_IdCon arg, PTPT_LexIdCon IdCon)
{
  if (PTPT_isIdConLexToCf(arg)) {
    return (PTPT_IdCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) IdCon), 0), 1);
  }

  ATabort("IdCon has no IdCon: %t\n", arg);
  return (PTPT_IdCon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PTPT_LexLayout accessors */

/*{{{  ATbool PTPT_isValidLexLayout(PTPT_LexLayout arg) */

ATbool PTPT_isValidLexLayout(PTPT_LexLayout arg)
{
  if (PTPT_isLexLayoutWhitespace(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PTPT_isLexLayoutWhitespace(PTPT_LexLayout arg) */

inline ATbool PTPT_isLexLayoutWhitespace(PTPT_LexLayout arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PTPT_patternLexLayoutWhitespace, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PTPT_hasLexLayoutCh(PTPT_LexLayout arg) */

ATbool PTPT_hasLexLayoutCh(PTPT_LexLayout arg)
{
  if (PTPT_isLexLayoutWhitespace(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char PTPT_getLexLayoutCh(PTPT_LexLayout arg) */

char PTPT_getLexLayoutCh(PTPT_LexLayout arg)
{
  
    return (char)PTPT_charToByte((ATerm)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  PTPT_LexLayout PTPT_setLexLayoutCh(PTPT_LexLayout arg, char ch) */

PTPT_LexLayout PTPT_setLexLayoutCh(PTPT_LexLayout arg, char ch)
{
  if (PTPT_isLexLayoutWhitespace(arg)) {
    return (PTPT_LexLayout)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) PTPT_byteToChar(ch))), 0), 1);
  }

  ATabort("LexLayout has no Ch: %t\n", arg);
  return (PTPT_LexLayout)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  PTPT_OptLayout PTPT_visitOptLayout(PTPT_OptLayout arg, PTPT_Layout (*acceptLayout)(PTPT_Layout)) */

PTPT_OptLayout PTPT_visitOptLayout(PTPT_OptLayout arg, PTPT_Layout (*acceptLayout)(PTPT_Layout))
{
  if (PTPT_isOptLayoutAbsent(arg)) {
    return PTPT_makeOptLayoutAbsent();
  }
  if (PTPT_isOptLayoutPresent(arg)) {
    return PTPT_makeOptLayoutPresent(
        acceptLayout ? acceptLayout(PTPT_getOptLayoutLayout(arg)) : PTPT_getOptLayoutLayout(arg));
  }
  ATabort("not a OptLayout: %t\n", arg);
  return (PTPT_OptLayout)NULL;
}

/*}}}  */
/*{{{  PTPT_Layout PTPT_visitLayout(PTPT_Layout arg, PTPT_LexLayoutList (*acceptList)(PTPT_LexLayoutList)) */

PTPT_Layout PTPT_visitLayout(PTPT_Layout arg, PTPT_LexLayoutList (*acceptList)(PTPT_LexLayoutList))
{
  if (PTPT_isLayoutLexToCf(arg)) {
    return PTPT_makeLayoutLexToCf(
        acceptList ? acceptList(PTPT_getLayoutList(arg)) : PTPT_getLayoutList(arg));
  }
  ATabort("not a Layout: %t\n", arg);
  return (PTPT_Layout)NULL;
}

/*}}}  */
/*{{{  PTPT_LexLayoutList PTPT_visitLexLayoutList(PTPT_LexLayoutList arg, PTPT_LexLayout (*acceptHead)(PTPT_LexLayout)) */

PTPT_LexLayoutList PTPT_visitLexLayoutList(PTPT_LexLayoutList arg, PTPT_LexLayout (*acceptHead)(PTPT_LexLayout))
{
  if (PTPT_isLexLayoutListEmpty(arg)) {
    return PTPT_makeLexLayoutListEmpty();
  }
  if (PTPT_isLexLayoutListSingle(arg)) {
    return PTPT_makeLexLayoutListSingle(
        acceptHead ? acceptHead(PTPT_getLexLayoutListHead(arg)) : PTPT_getLexLayoutListHead(arg));
  }
  if (PTPT_isLexLayoutListMany(arg)) {
    return PTPT_makeLexLayoutListMany(
        acceptHead ? acceptHead(PTPT_getLexLayoutListHead(arg)) : PTPT_getLexLayoutListHead(arg),
        PTPT_visitLexLayoutList(PTPT_getLexLayoutListTail(arg), acceptHead));
  }
  ATabort("not a LexLayoutList: %t\n", arg);
  return (PTPT_LexLayoutList)NULL;
}

/*}}}  */
/*{{{  PTPT_Tree PTPT_visitTree(PTPT_Tree arg, PTPT_OptLayout (*acceptWsAfterTree)(PTPT_OptLayout), PTPT_Annotation (*acceptAnnotation)(PTPT_Annotation), PTPT_OptLayout (*acceptWsAfterAppl)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterParenOpen)(PTPT_OptLayout), PTPT_Production (*acceptProd)(PTPT_Production), PTPT_OptLayout (*acceptWsAfterProd)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterComma)(PTPT_OptLayout), PTPT_Args (*acceptArgs)(PTPT_Args), PTPT_OptLayout (*acceptWsAfterArgs)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterCycle)(PTPT_OptLayout), PTPT_Symbol (*acceptSymbol)(PTPT_Symbol), PTPT_OptLayout (*acceptWsAfterSymbol)(PTPT_OptLayout), PTPT_NatCon (*acceptCycleLength)(PTPT_NatCon), PTPT_OptLayout (*acceptWsAfterCycleLength)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterAmb)(PTPT_OptLayout), PTPT_NatCon (*acceptCharacter)(PTPT_NatCon)) */

PTPT_Tree PTPT_visitTree(PTPT_Tree arg, PTPT_OptLayout (*acceptWsAfterTree)(PTPT_OptLayout), PTPT_Annotation (*acceptAnnotation)(PTPT_Annotation), PTPT_OptLayout (*acceptWsAfterAppl)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterParenOpen)(PTPT_OptLayout), PTPT_Production (*acceptProd)(PTPT_Production), PTPT_OptLayout (*acceptWsAfterProd)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterComma)(PTPT_OptLayout), PTPT_Args (*acceptArgs)(PTPT_Args), PTPT_OptLayout (*acceptWsAfterArgs)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterCycle)(PTPT_OptLayout), PTPT_Symbol (*acceptSymbol)(PTPT_Symbol), PTPT_OptLayout (*acceptWsAfterSymbol)(PTPT_OptLayout), PTPT_NatCon (*acceptCycleLength)(PTPT_NatCon), PTPT_OptLayout (*acceptWsAfterCycleLength)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterAmb)(PTPT_OptLayout), PTPT_NatCon (*acceptCharacter)(PTPT_NatCon))
{
  if (PTPT_isTreeAnnotated(arg)) {
    return PTPT_makeTreeAnnotated(
        PTPT_visitTree(PTPT_getTreeTree(arg), acceptWsAfterTree, acceptAnnotation, acceptWsAfterAppl, acceptWsAfterParenOpen, acceptProd, acceptWsAfterProd, acceptWsAfterComma, acceptArgs, acceptWsAfterArgs, acceptWsAfterCycle, acceptSymbol, acceptWsAfterSymbol, acceptCycleLength, acceptWsAfterCycleLength, acceptWsAfterAmb, acceptCharacter),
        acceptWsAfterTree ? acceptWsAfterTree(PTPT_getTreeWsAfterTree(arg)) : PTPT_getTreeWsAfterTree(arg),
        acceptAnnotation ? acceptAnnotation(PTPT_getTreeAnnotation(arg)) : PTPT_getTreeAnnotation(arg));
  }
  if (PTPT_isTreeAppl(arg)) {
    return PTPT_makeTreeAppl(
        acceptWsAfterAppl ? acceptWsAfterAppl(PTPT_getTreeWsAfterAppl(arg)) : PTPT_getTreeWsAfterAppl(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PTPT_getTreeWsAfterParenOpen(arg)) : PTPT_getTreeWsAfterParenOpen(arg),
        acceptProd ? acceptProd(PTPT_getTreeProd(arg)) : PTPT_getTreeProd(arg),
        acceptWsAfterProd ? acceptWsAfterProd(PTPT_getTreeWsAfterProd(arg)) : PTPT_getTreeWsAfterProd(arg),
        acceptWsAfterComma ? acceptWsAfterComma(PTPT_getTreeWsAfterComma(arg)) : PTPT_getTreeWsAfterComma(arg),
        acceptArgs ? acceptArgs(PTPT_getTreeArgs(arg)) : PTPT_getTreeArgs(arg),
        acceptWsAfterArgs ? acceptWsAfterArgs(PTPT_getTreeWsAfterArgs(arg)) : PTPT_getTreeWsAfterArgs(arg));
  }
  if (PTPT_isTreeCycle(arg)) {
    return PTPT_makeTreeCycle(
        acceptWsAfterCycle ? acceptWsAfterCycle(PTPT_getTreeWsAfterCycle(arg)) : PTPT_getTreeWsAfterCycle(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PTPT_getTreeWsAfterParenOpen(arg)) : PTPT_getTreeWsAfterParenOpen(arg),
        acceptSymbol ? acceptSymbol(PTPT_getTreeSymbol(arg)) : PTPT_getTreeSymbol(arg),
        acceptWsAfterSymbol ? acceptWsAfterSymbol(PTPT_getTreeWsAfterSymbol(arg)) : PTPT_getTreeWsAfterSymbol(arg),
        acceptWsAfterComma ? acceptWsAfterComma(PTPT_getTreeWsAfterComma(arg)) : PTPT_getTreeWsAfterComma(arg),
        acceptCycleLength ? acceptCycleLength(PTPT_getTreeCycleLength(arg)) : PTPT_getTreeCycleLength(arg),
        acceptWsAfterCycleLength ? acceptWsAfterCycleLength(PTPT_getTreeWsAfterCycleLength(arg)) : PTPT_getTreeWsAfterCycleLength(arg));
  }
  if (PTPT_isTreeAmb(arg)) {
    return PTPT_makeTreeAmb(
        acceptWsAfterAmb ? acceptWsAfterAmb(PTPT_getTreeWsAfterAmb(arg)) : PTPT_getTreeWsAfterAmb(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PTPT_getTreeWsAfterParenOpen(arg)) : PTPT_getTreeWsAfterParenOpen(arg),
        acceptArgs ? acceptArgs(PTPT_getTreeArgs(arg)) : PTPT_getTreeArgs(arg),
        acceptWsAfterArgs ? acceptWsAfterArgs(PTPT_getTreeWsAfterArgs(arg)) : PTPT_getTreeWsAfterArgs(arg));
  }
  if (PTPT_isTreeChar(arg)) {
    return PTPT_makeTreeChar(
        acceptCharacter ? acceptCharacter(PTPT_getTreeCharacter(arg)) : PTPT_getTreeCharacter(arg));
  }
  ATabort("not a Tree: %t\n", arg);
  return (PTPT_Tree)NULL;
}

/*}}}  */
/*{{{  PTPT_Attributes PTPT_visitAttributes(PTPT_Attributes arg, PTPT_OptLayout (*acceptWsAfterAttrs)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterParenOpen)(PTPT_OptLayout), PTPT_Attrs (*acceptAttributes)(PTPT_Attrs), PTPT_OptLayout (*acceptWsAfterAttributes)(PTPT_OptLayout)) */

PTPT_Attributes PTPT_visitAttributes(PTPT_Attributes arg, PTPT_OptLayout (*acceptWsAfterAttrs)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterParenOpen)(PTPT_OptLayout), PTPT_Attrs (*acceptAttributes)(PTPT_Attrs), PTPT_OptLayout (*acceptWsAfterAttributes)(PTPT_OptLayout))
{
  if (PTPT_isAttributesNoAttrs(arg)) {
    return PTPT_makeAttributesNoAttrs();
  }
  if (PTPT_isAttributesAttrs(arg)) {
    return PTPT_makeAttributesAttrs(
        acceptWsAfterAttrs ? acceptWsAfterAttrs(PTPT_getAttributesWsAfterAttrs(arg)) : PTPT_getAttributesWsAfterAttrs(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PTPT_getAttributesWsAfterParenOpen(arg)) : PTPT_getAttributesWsAfterParenOpen(arg),
        acceptAttributes ? acceptAttributes(PTPT_getAttributesAttributes(arg)) : PTPT_getAttributesAttributes(arg),
        acceptWsAfterAttributes ? acceptWsAfterAttributes(PTPT_getAttributesWsAfterAttributes(arg)) : PTPT_getAttributesWsAfterAttributes(arg));
  }
  ATabort("not a Attributes: %t\n", arg);
  return (PTPT_Attributes)NULL;
}

/*}}}  */
/*{{{  PTPT_Attrs PTPT_visitAttrs(PTPT_Attrs arg, PTPT_OptLayout (*acceptWsAfterBracketOpen)(PTPT_OptLayout), PTPT_AttrList (*acceptList)(PTPT_AttrList), PTPT_OptLayout (*acceptWsAfterList)(PTPT_OptLayout)) */

PTPT_Attrs PTPT_visitAttrs(PTPT_Attrs arg, PTPT_OptLayout (*acceptWsAfterBracketOpen)(PTPT_OptLayout), PTPT_AttrList (*acceptList)(PTPT_AttrList), PTPT_OptLayout (*acceptWsAfterList)(PTPT_OptLayout))
{
  if (PTPT_isAttrsMany(arg)) {
    return PTPT_makeAttrsMany(
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(PTPT_getAttrsWsAfterBracketOpen(arg)) : PTPT_getAttrsWsAfterBracketOpen(arg),
        acceptList ? acceptList(PTPT_getAttrsList(arg)) : PTPT_getAttrsList(arg),
        acceptWsAfterList ? acceptWsAfterList(PTPT_getAttrsWsAfterList(arg)) : PTPT_getAttrsWsAfterList(arg));
  }
  ATabort("not a Attrs: %t\n", arg);
  return (PTPT_Attrs)NULL;
}

/*}}}  */
/*{{{  PTPT_Attr PTPT_visitAttr(PTPT_Attr arg, PTPT_OptLayout (*acceptWsAfterAssoc)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterParenOpen)(PTPT_OptLayout), PTPT_Associativity (*acceptAssociativity)(PTPT_Associativity), PTPT_OptLayout (*acceptWsAfterAssociativity)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterTerm)(PTPT_OptLayout), PTPT_ATerm (*acceptAterm)(PTPT_ATerm), PTPT_OptLayout (*acceptWsAfterAterm)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterId)(PTPT_OptLayout), PTPT_StrCon (*acceptModuleName)(PTPT_StrCon), PTPT_OptLayout (*acceptWsAfterModuleName)(PTPT_OptLayout)) */

PTPT_Attr PTPT_visitAttr(PTPT_Attr arg, PTPT_OptLayout (*acceptWsAfterAssoc)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterParenOpen)(PTPT_OptLayout), PTPT_Associativity (*acceptAssociativity)(PTPT_Associativity), PTPT_OptLayout (*acceptWsAfterAssociativity)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterTerm)(PTPT_OptLayout), PTPT_ATerm (*acceptAterm)(PTPT_ATerm), PTPT_OptLayout (*acceptWsAfterAterm)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterId)(PTPT_OptLayout), PTPT_StrCon (*acceptModuleName)(PTPT_StrCon), PTPT_OptLayout (*acceptWsAfterModuleName)(PTPT_OptLayout))
{
  if (PTPT_isAttrAssoc(arg)) {
    return PTPT_makeAttrAssoc(
        acceptWsAfterAssoc ? acceptWsAfterAssoc(PTPT_getAttrWsAfterAssoc(arg)) : PTPT_getAttrWsAfterAssoc(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PTPT_getAttrWsAfterParenOpen(arg)) : PTPT_getAttrWsAfterParenOpen(arg),
        acceptAssociativity ? acceptAssociativity(PTPT_getAttrAssociativity(arg)) : PTPT_getAttrAssociativity(arg),
        acceptWsAfterAssociativity ? acceptWsAfterAssociativity(PTPT_getAttrWsAfterAssociativity(arg)) : PTPT_getAttrWsAfterAssociativity(arg));
  }
  if (PTPT_isAttrTerm(arg)) {
    return PTPT_makeAttrTerm(
        acceptWsAfterTerm ? acceptWsAfterTerm(PTPT_getAttrWsAfterTerm(arg)) : PTPT_getAttrWsAfterTerm(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PTPT_getAttrWsAfterParenOpen(arg)) : PTPT_getAttrWsAfterParenOpen(arg),
        acceptAterm ? acceptAterm(PTPT_getAttrAterm(arg)) : PTPT_getAttrAterm(arg),
        acceptWsAfterAterm ? acceptWsAfterAterm(PTPT_getAttrWsAfterAterm(arg)) : PTPT_getAttrWsAfterAterm(arg));
  }
  if (PTPT_isAttrId(arg)) {
    return PTPT_makeAttrId(
        acceptWsAfterId ? acceptWsAfterId(PTPT_getAttrWsAfterId(arg)) : PTPT_getAttrWsAfterId(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PTPT_getAttrWsAfterParenOpen(arg)) : PTPT_getAttrWsAfterParenOpen(arg),
        acceptModuleName ? acceptModuleName(PTPT_getAttrModuleName(arg)) : PTPT_getAttrModuleName(arg),
        acceptWsAfterModuleName ? acceptWsAfterModuleName(PTPT_getAttrWsAfterModuleName(arg)) : PTPT_getAttrWsAfterModuleName(arg));
  }
  if (PTPT_isAttrBracket(arg)) {
    return PTPT_makeAttrBracket();
  }
  if (PTPT_isAttrReject(arg)) {
    return PTPT_makeAttrReject();
  }
  if (PTPT_isAttrPrefer(arg)) {
    return PTPT_makeAttrPrefer();
  }
  if (PTPT_isAttrAvoid(arg)) {
    return PTPT_makeAttrAvoid();
  }
  ATabort("not a Attr: %t\n", arg);
  return (PTPT_Attr)NULL;
}

/*}}}  */
/*{{{  PTPT_Associativity PTPT_visitAssociativity(PTPT_Associativity arg) */

PTPT_Associativity PTPT_visitAssociativity(PTPT_Associativity arg)
{
  if (PTPT_isAssociativityLeft(arg)) {
    return PTPT_makeAssociativityLeft();
  }
  if (PTPT_isAssociativityRight(arg)) {
    return PTPT_makeAssociativityRight();
  }
  if (PTPT_isAssociativityAssoc(arg)) {
    return PTPT_makeAssociativityAssoc();
  }
  if (PTPT_isAssociativityNonAssoc(arg)) {
    return PTPT_makeAssociativityNonAssoc();
  }
  ATabort("not a Associativity: %t\n", arg);
  return (PTPT_Associativity)NULL;
}

/*}}}  */
/*{{{  PTPT_AttrList PTPT_visitAttrList(PTPT_AttrList arg, PTPT_Attr (*acceptHead)(PTPT_Attr), PTPT_OptLayout (*acceptWsAfterHead)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterSep)(PTPT_OptLayout)) */

PTPT_AttrList PTPT_visitAttrList(PTPT_AttrList arg, PTPT_Attr (*acceptHead)(PTPT_Attr), PTPT_OptLayout (*acceptWsAfterHead)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterSep)(PTPT_OptLayout))
{
  if (PTPT_isAttrListEmpty(arg)) {
    return PTPT_makeAttrListEmpty();
  }
  if (PTPT_isAttrListSingle(arg)) {
    return PTPT_makeAttrListSingle(
        acceptHead ? acceptHead(PTPT_getAttrListHead(arg)) : PTPT_getAttrListHead(arg));
  }
  if (PTPT_isAttrListMany(arg)) {
    return PTPT_makeAttrListMany(
        acceptHead ? acceptHead(PTPT_getAttrListHead(arg)) : PTPT_getAttrListHead(arg),
        acceptWsAfterHead ? acceptWsAfterHead(PTPT_getAttrListWsAfterHead(arg)) : PTPT_getAttrListWsAfterHead(arg),
        acceptWsAfterSep ? acceptWsAfterSep(PTPT_getAttrListWsAfterSep(arg)) : PTPT_getAttrListWsAfterSep(arg),
        PTPT_visitAttrList(PTPT_getAttrListTail(arg), acceptHead, acceptWsAfterHead, acceptWsAfterSep));
  }
  ATabort("not a AttrList: %t\n", arg);
  return (PTPT_AttrList)NULL;
}

/*}}}  */
/*{{{  PTPT_ParseTree PTPT_visitParseTree(PTPT_ParseTree arg, PTPT_OptLayout (*acceptWsAfterParsetree)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterParenOpen)(PTPT_OptLayout), PTPT_Tree (*acceptTop)(PTPT_Tree), PTPT_OptLayout (*acceptWsAfterTop)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterComma)(PTPT_OptLayout), PTPT_NatCon (*acceptAmbCnt)(PTPT_NatCon), PTPT_OptLayout (*acceptWsAfterAmbCnt)(PTPT_OptLayout)) */

PTPT_ParseTree PTPT_visitParseTree(PTPT_ParseTree arg, PTPT_OptLayout (*acceptWsAfterParsetree)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterParenOpen)(PTPT_OptLayout), PTPT_Tree (*acceptTop)(PTPT_Tree), PTPT_OptLayout (*acceptWsAfterTop)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterComma)(PTPT_OptLayout), PTPT_NatCon (*acceptAmbCnt)(PTPT_NatCon), PTPT_OptLayout (*acceptWsAfterAmbCnt)(PTPT_OptLayout))
{
  if (PTPT_isParseTreeTop(arg)) {
    return PTPT_makeParseTreeTop(
        acceptWsAfterParsetree ? acceptWsAfterParsetree(PTPT_getParseTreeWsAfterParsetree(arg)) : PTPT_getParseTreeWsAfterParsetree(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PTPT_getParseTreeWsAfterParenOpen(arg)) : PTPT_getParseTreeWsAfterParenOpen(arg),
        acceptTop ? acceptTop(PTPT_getParseTreeTop(arg)) : PTPT_getParseTreeTop(arg),
        acceptWsAfterTop ? acceptWsAfterTop(PTPT_getParseTreeWsAfterTop(arg)) : PTPT_getParseTreeWsAfterTop(arg),
        acceptWsAfterComma ? acceptWsAfterComma(PTPT_getParseTreeWsAfterComma(arg)) : PTPT_getParseTreeWsAfterComma(arg),
        acceptAmbCnt ? acceptAmbCnt(PTPT_getParseTreeAmbCnt(arg)) : PTPT_getParseTreeAmbCnt(arg),
        acceptWsAfterAmbCnt ? acceptWsAfterAmbCnt(PTPT_getParseTreeWsAfterAmbCnt(arg)) : PTPT_getParseTreeWsAfterAmbCnt(arg));
  }
  ATabort("not a ParseTree: %t\n", arg);
  return (PTPT_ParseTree)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbol PTPT_visitSymbol(PTPT_Symbol arg, PTPT_OptLayout (*acceptWsAfterLit)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterParenOpen)(PTPT_OptLayout), PTPT_StrCon (*acceptString)(PTPT_StrCon), PTPT_OptLayout (*acceptWsAfterString)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterCilit)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterCf)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterSymbol)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterLex)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterOpt)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterAlt)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterLhs)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterComma)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterRhs)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterSeq)(PTPT_OptLayout), PTPT_Symbols (*acceptSymbols)(PTPT_Symbols), PTPT_OptLayout (*acceptWsAfterSymbols)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterTuple)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterHead)(PTPT_OptLayout), PTPT_Symbols (*acceptRest)(PTPT_Symbols), PTPT_OptLayout (*acceptWsAfterRest)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterSort)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterIter)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterIterStar)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterIterSep)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterSeparator)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterIterStarSep)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterIterN)(PTPT_OptLayout), PTPT_NatCon (*acceptNumber)(PTPT_NatCon), PTPT_OptLayout (*acceptWsAfterNumber)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterIterSepN)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterComma1)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterComma2)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterFunc)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterVarsym)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterCharClass)(PTPT_OptLayout), PTPT_CharRanges (*acceptCharRanges)(PTPT_CharRanges), PTPT_OptLayout (*acceptWsAfterCharRanges)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterStrategy)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterParameterizedSort)(PTPT_OptLayout), PTPT_StrCon (*acceptSort)(PTPT_StrCon), PTPT_Symbols (*acceptParameters)(PTPT_Symbols), PTPT_OptLayout (*acceptWsAfterParameters)(PTPT_OptLayout)) */

PTPT_Symbol PTPT_visitSymbol(PTPT_Symbol arg, PTPT_OptLayout (*acceptWsAfterLit)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterParenOpen)(PTPT_OptLayout), PTPT_StrCon (*acceptString)(PTPT_StrCon), PTPT_OptLayout (*acceptWsAfterString)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterCilit)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterCf)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterSymbol)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterLex)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterOpt)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterAlt)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterLhs)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterComma)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterRhs)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterSeq)(PTPT_OptLayout), PTPT_Symbols (*acceptSymbols)(PTPT_Symbols), PTPT_OptLayout (*acceptWsAfterSymbols)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterTuple)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterHead)(PTPT_OptLayout), PTPT_Symbols (*acceptRest)(PTPT_Symbols), PTPT_OptLayout (*acceptWsAfterRest)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterSort)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterIter)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterIterStar)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterIterSep)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterSeparator)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterIterStarSep)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterIterN)(PTPT_OptLayout), PTPT_NatCon (*acceptNumber)(PTPT_NatCon), PTPT_OptLayout (*acceptWsAfterNumber)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterIterSepN)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterComma1)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterComma2)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterFunc)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterVarsym)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterCharClass)(PTPT_OptLayout), PTPT_CharRanges (*acceptCharRanges)(PTPT_CharRanges), PTPT_OptLayout (*acceptWsAfterCharRanges)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterStrategy)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterParameterizedSort)(PTPT_OptLayout), PTPT_StrCon (*acceptSort)(PTPT_StrCon), PTPT_Symbols (*acceptParameters)(PTPT_Symbols), PTPT_OptLayout (*acceptWsAfterParameters)(PTPT_OptLayout))
{
  if (PTPT_isSymbolEmpty(arg)) {
    return PTPT_makeSymbolEmpty();
  }
  if (PTPT_isSymbolLit(arg)) {
    return PTPT_makeSymbolLit(
        acceptWsAfterLit ? acceptWsAfterLit(PTPT_getSymbolWsAfterLit(arg)) : PTPT_getSymbolWsAfterLit(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PTPT_getSymbolWsAfterParenOpen(arg)) : PTPT_getSymbolWsAfterParenOpen(arg),
        acceptString ? acceptString(PTPT_getSymbolString(arg)) : PTPT_getSymbolString(arg),
        acceptWsAfterString ? acceptWsAfterString(PTPT_getSymbolWsAfterString(arg)) : PTPT_getSymbolWsAfterString(arg));
  }
  if (PTPT_isSymbolCilit(arg)) {
    return PTPT_makeSymbolCilit(
        acceptWsAfterCilit ? acceptWsAfterCilit(PTPT_getSymbolWsAfterCilit(arg)) : PTPT_getSymbolWsAfterCilit(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PTPT_getSymbolWsAfterParenOpen(arg)) : PTPT_getSymbolWsAfterParenOpen(arg),
        acceptString ? acceptString(PTPT_getSymbolString(arg)) : PTPT_getSymbolString(arg),
        acceptWsAfterString ? acceptWsAfterString(PTPT_getSymbolWsAfterString(arg)) : PTPT_getSymbolWsAfterString(arg));
  }
  if (PTPT_isSymbolCf(arg)) {
    return PTPT_makeSymbolCf(
        acceptWsAfterCf ? acceptWsAfterCf(PTPT_getSymbolWsAfterCf(arg)) : PTPT_getSymbolWsAfterCf(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PTPT_getSymbolWsAfterParenOpen(arg)) : PTPT_getSymbolWsAfterParenOpen(arg),
        PTPT_visitSymbol(PTPT_getSymbolSymbol(arg), acceptWsAfterLit, acceptWsAfterParenOpen, acceptString, acceptWsAfterString, acceptWsAfterCilit, acceptWsAfterCf, acceptWsAfterSymbol, acceptWsAfterLex, acceptWsAfterOpt, acceptWsAfterAlt, acceptWsAfterLhs, acceptWsAfterComma, acceptWsAfterRhs, acceptWsAfterSeq, acceptSymbols, acceptWsAfterSymbols, acceptWsAfterTuple, acceptWsAfterHead, acceptRest, acceptWsAfterRest, acceptWsAfterSort, acceptWsAfterIter, acceptWsAfterIterStar, acceptWsAfterIterSep, acceptWsAfterSeparator, acceptWsAfterIterStarSep, acceptWsAfterIterN, acceptNumber, acceptWsAfterNumber, acceptWsAfterIterSepN, acceptWsAfterComma1, acceptWsAfterComma2, acceptWsAfterFunc, acceptWsAfterVarsym, acceptWsAfterCharClass, acceptCharRanges, acceptWsAfterCharRanges, acceptWsAfterStrategy, acceptWsAfterParameterizedSort, acceptSort, acceptParameters, acceptWsAfterParameters),
        acceptWsAfterSymbol ? acceptWsAfterSymbol(PTPT_getSymbolWsAfterSymbol(arg)) : PTPT_getSymbolWsAfterSymbol(arg));
  }
  if (PTPT_isSymbolLex(arg)) {
    return PTPT_makeSymbolLex(
        acceptWsAfterLex ? acceptWsAfterLex(PTPT_getSymbolWsAfterLex(arg)) : PTPT_getSymbolWsAfterLex(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PTPT_getSymbolWsAfterParenOpen(arg)) : PTPT_getSymbolWsAfterParenOpen(arg),
        PTPT_visitSymbol(PTPT_getSymbolSymbol(arg), acceptWsAfterLit, acceptWsAfterParenOpen, acceptString, acceptWsAfterString, acceptWsAfterCilit, acceptWsAfterCf, acceptWsAfterSymbol, acceptWsAfterLex, acceptWsAfterOpt, acceptWsAfterAlt, acceptWsAfterLhs, acceptWsAfterComma, acceptWsAfterRhs, acceptWsAfterSeq, acceptSymbols, acceptWsAfterSymbols, acceptWsAfterTuple, acceptWsAfterHead, acceptRest, acceptWsAfterRest, acceptWsAfterSort, acceptWsAfterIter, acceptWsAfterIterStar, acceptWsAfterIterSep, acceptWsAfterSeparator, acceptWsAfterIterStarSep, acceptWsAfterIterN, acceptNumber, acceptWsAfterNumber, acceptWsAfterIterSepN, acceptWsAfterComma1, acceptWsAfterComma2, acceptWsAfterFunc, acceptWsAfterVarsym, acceptWsAfterCharClass, acceptCharRanges, acceptWsAfterCharRanges, acceptWsAfterStrategy, acceptWsAfterParameterizedSort, acceptSort, acceptParameters, acceptWsAfterParameters),
        acceptWsAfterSymbol ? acceptWsAfterSymbol(PTPT_getSymbolWsAfterSymbol(arg)) : PTPT_getSymbolWsAfterSymbol(arg));
  }
  if (PTPT_isSymbolOpt(arg)) {
    return PTPT_makeSymbolOpt(
        acceptWsAfterOpt ? acceptWsAfterOpt(PTPT_getSymbolWsAfterOpt(arg)) : PTPT_getSymbolWsAfterOpt(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PTPT_getSymbolWsAfterParenOpen(arg)) : PTPT_getSymbolWsAfterParenOpen(arg),
        PTPT_visitSymbol(PTPT_getSymbolSymbol(arg), acceptWsAfterLit, acceptWsAfterParenOpen, acceptString, acceptWsAfterString, acceptWsAfterCilit, acceptWsAfterCf, acceptWsAfterSymbol, acceptWsAfterLex, acceptWsAfterOpt, acceptWsAfterAlt, acceptWsAfterLhs, acceptWsAfterComma, acceptWsAfterRhs, acceptWsAfterSeq, acceptSymbols, acceptWsAfterSymbols, acceptWsAfterTuple, acceptWsAfterHead, acceptRest, acceptWsAfterRest, acceptWsAfterSort, acceptWsAfterIter, acceptWsAfterIterStar, acceptWsAfterIterSep, acceptWsAfterSeparator, acceptWsAfterIterStarSep, acceptWsAfterIterN, acceptNumber, acceptWsAfterNumber, acceptWsAfterIterSepN, acceptWsAfterComma1, acceptWsAfterComma2, acceptWsAfterFunc, acceptWsAfterVarsym, acceptWsAfterCharClass, acceptCharRanges, acceptWsAfterCharRanges, acceptWsAfterStrategy, acceptWsAfterParameterizedSort, acceptSort, acceptParameters, acceptWsAfterParameters),
        acceptWsAfterSymbol ? acceptWsAfterSymbol(PTPT_getSymbolWsAfterSymbol(arg)) : PTPT_getSymbolWsAfterSymbol(arg));
  }
  if (PTPT_isSymbolAlt(arg)) {
    return PTPT_makeSymbolAlt(
        acceptWsAfterAlt ? acceptWsAfterAlt(PTPT_getSymbolWsAfterAlt(arg)) : PTPT_getSymbolWsAfterAlt(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PTPT_getSymbolWsAfterParenOpen(arg)) : PTPT_getSymbolWsAfterParenOpen(arg),
        PTPT_visitSymbol(PTPT_getSymbolLhs(arg), acceptWsAfterLit, acceptWsAfterParenOpen, acceptString, acceptWsAfterString, acceptWsAfterCilit, acceptWsAfterCf, acceptWsAfterSymbol, acceptWsAfterLex, acceptWsAfterOpt, acceptWsAfterAlt, acceptWsAfterLhs, acceptWsAfterComma, acceptWsAfterRhs, acceptWsAfterSeq, acceptSymbols, acceptWsAfterSymbols, acceptWsAfterTuple, acceptWsAfterHead, acceptRest, acceptWsAfterRest, acceptWsAfterSort, acceptWsAfterIter, acceptWsAfterIterStar, acceptWsAfterIterSep, acceptWsAfterSeparator, acceptWsAfterIterStarSep, acceptWsAfterIterN, acceptNumber, acceptWsAfterNumber, acceptWsAfterIterSepN, acceptWsAfterComma1, acceptWsAfterComma2, acceptWsAfterFunc, acceptWsAfterVarsym, acceptWsAfterCharClass, acceptCharRanges, acceptWsAfterCharRanges, acceptWsAfterStrategy, acceptWsAfterParameterizedSort, acceptSort, acceptParameters, acceptWsAfterParameters),
        acceptWsAfterLhs ? acceptWsAfterLhs(PTPT_getSymbolWsAfterLhs(arg)) : PTPT_getSymbolWsAfterLhs(arg),
        acceptWsAfterComma ? acceptWsAfterComma(PTPT_getSymbolWsAfterComma(arg)) : PTPT_getSymbolWsAfterComma(arg),
        PTPT_visitSymbol(PTPT_getSymbolRhs(arg), acceptWsAfterLit, acceptWsAfterParenOpen, acceptString, acceptWsAfterString, acceptWsAfterCilit, acceptWsAfterCf, acceptWsAfterSymbol, acceptWsAfterLex, acceptWsAfterOpt, acceptWsAfterAlt, acceptWsAfterLhs, acceptWsAfterComma, acceptWsAfterRhs, acceptWsAfterSeq, acceptSymbols, acceptWsAfterSymbols, acceptWsAfterTuple, acceptWsAfterHead, acceptRest, acceptWsAfterRest, acceptWsAfterSort, acceptWsAfterIter, acceptWsAfterIterStar, acceptWsAfterIterSep, acceptWsAfterSeparator, acceptWsAfterIterStarSep, acceptWsAfterIterN, acceptNumber, acceptWsAfterNumber, acceptWsAfterIterSepN, acceptWsAfterComma1, acceptWsAfterComma2, acceptWsAfterFunc, acceptWsAfterVarsym, acceptWsAfterCharClass, acceptCharRanges, acceptWsAfterCharRanges, acceptWsAfterStrategy, acceptWsAfterParameterizedSort, acceptSort, acceptParameters, acceptWsAfterParameters),
        acceptWsAfterRhs ? acceptWsAfterRhs(PTPT_getSymbolWsAfterRhs(arg)) : PTPT_getSymbolWsAfterRhs(arg));
  }
  if (PTPT_isSymbolSeq(arg)) {
    return PTPT_makeSymbolSeq(
        acceptWsAfterSeq ? acceptWsAfterSeq(PTPT_getSymbolWsAfterSeq(arg)) : PTPT_getSymbolWsAfterSeq(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PTPT_getSymbolWsAfterParenOpen(arg)) : PTPT_getSymbolWsAfterParenOpen(arg),
        acceptSymbols ? acceptSymbols(PTPT_getSymbolSymbols(arg)) : PTPT_getSymbolSymbols(arg),
        acceptWsAfterSymbols ? acceptWsAfterSymbols(PTPT_getSymbolWsAfterSymbols(arg)) : PTPT_getSymbolWsAfterSymbols(arg));
  }
  if (PTPT_isSymbolTuple(arg)) {
    return PTPT_makeSymbolTuple(
        acceptWsAfterTuple ? acceptWsAfterTuple(PTPT_getSymbolWsAfterTuple(arg)) : PTPT_getSymbolWsAfterTuple(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PTPT_getSymbolWsAfterParenOpen(arg)) : PTPT_getSymbolWsAfterParenOpen(arg),
        PTPT_visitSymbol(PTPT_getSymbolHead(arg), acceptWsAfterLit, acceptWsAfterParenOpen, acceptString, acceptWsAfterString, acceptWsAfterCilit, acceptWsAfterCf, acceptWsAfterSymbol, acceptWsAfterLex, acceptWsAfterOpt, acceptWsAfterAlt, acceptWsAfterLhs, acceptWsAfterComma, acceptWsAfterRhs, acceptWsAfterSeq, acceptSymbols, acceptWsAfterSymbols, acceptWsAfterTuple, acceptWsAfterHead, acceptRest, acceptWsAfterRest, acceptWsAfterSort, acceptWsAfterIter, acceptWsAfterIterStar, acceptWsAfterIterSep, acceptWsAfterSeparator, acceptWsAfterIterStarSep, acceptWsAfterIterN, acceptNumber, acceptWsAfterNumber, acceptWsAfterIterSepN, acceptWsAfterComma1, acceptWsAfterComma2, acceptWsAfterFunc, acceptWsAfterVarsym, acceptWsAfterCharClass, acceptCharRanges, acceptWsAfterCharRanges, acceptWsAfterStrategy, acceptWsAfterParameterizedSort, acceptSort, acceptParameters, acceptWsAfterParameters),
        acceptWsAfterHead ? acceptWsAfterHead(PTPT_getSymbolWsAfterHead(arg)) : PTPT_getSymbolWsAfterHead(arg),
        acceptWsAfterComma ? acceptWsAfterComma(PTPT_getSymbolWsAfterComma(arg)) : PTPT_getSymbolWsAfterComma(arg),
        acceptRest ? acceptRest(PTPT_getSymbolRest(arg)) : PTPT_getSymbolRest(arg),
        acceptWsAfterRest ? acceptWsAfterRest(PTPT_getSymbolWsAfterRest(arg)) : PTPT_getSymbolWsAfterRest(arg));
  }
  if (PTPT_isSymbolSort(arg)) {
    return PTPT_makeSymbolSort(
        acceptWsAfterSort ? acceptWsAfterSort(PTPT_getSymbolWsAfterSort(arg)) : PTPT_getSymbolWsAfterSort(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PTPT_getSymbolWsAfterParenOpen(arg)) : PTPT_getSymbolWsAfterParenOpen(arg),
        acceptString ? acceptString(PTPT_getSymbolString(arg)) : PTPT_getSymbolString(arg),
        acceptWsAfterString ? acceptWsAfterString(PTPT_getSymbolWsAfterString(arg)) : PTPT_getSymbolWsAfterString(arg));
  }
  if (PTPT_isSymbolIter(arg)) {
    return PTPT_makeSymbolIter(
        acceptWsAfterIter ? acceptWsAfterIter(PTPT_getSymbolWsAfterIter(arg)) : PTPT_getSymbolWsAfterIter(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PTPT_getSymbolWsAfterParenOpen(arg)) : PTPT_getSymbolWsAfterParenOpen(arg),
        PTPT_visitSymbol(PTPT_getSymbolSymbol(arg), acceptWsAfterLit, acceptWsAfterParenOpen, acceptString, acceptWsAfterString, acceptWsAfterCilit, acceptWsAfterCf, acceptWsAfterSymbol, acceptWsAfterLex, acceptWsAfterOpt, acceptWsAfterAlt, acceptWsAfterLhs, acceptWsAfterComma, acceptWsAfterRhs, acceptWsAfterSeq, acceptSymbols, acceptWsAfterSymbols, acceptWsAfterTuple, acceptWsAfterHead, acceptRest, acceptWsAfterRest, acceptWsAfterSort, acceptWsAfterIter, acceptWsAfterIterStar, acceptWsAfterIterSep, acceptWsAfterSeparator, acceptWsAfterIterStarSep, acceptWsAfterIterN, acceptNumber, acceptWsAfterNumber, acceptWsAfterIterSepN, acceptWsAfterComma1, acceptWsAfterComma2, acceptWsAfterFunc, acceptWsAfterVarsym, acceptWsAfterCharClass, acceptCharRanges, acceptWsAfterCharRanges, acceptWsAfterStrategy, acceptWsAfterParameterizedSort, acceptSort, acceptParameters, acceptWsAfterParameters),
        acceptWsAfterSymbol ? acceptWsAfterSymbol(PTPT_getSymbolWsAfterSymbol(arg)) : PTPT_getSymbolWsAfterSymbol(arg));
  }
  if (PTPT_isSymbolIterStar(arg)) {
    return PTPT_makeSymbolIterStar(
        acceptWsAfterIterStar ? acceptWsAfterIterStar(PTPT_getSymbolWsAfterIterStar(arg)) : PTPT_getSymbolWsAfterIterStar(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PTPT_getSymbolWsAfterParenOpen(arg)) : PTPT_getSymbolWsAfterParenOpen(arg),
        PTPT_visitSymbol(PTPT_getSymbolSymbol(arg), acceptWsAfterLit, acceptWsAfterParenOpen, acceptString, acceptWsAfterString, acceptWsAfterCilit, acceptWsAfterCf, acceptWsAfterSymbol, acceptWsAfterLex, acceptWsAfterOpt, acceptWsAfterAlt, acceptWsAfterLhs, acceptWsAfterComma, acceptWsAfterRhs, acceptWsAfterSeq, acceptSymbols, acceptWsAfterSymbols, acceptWsAfterTuple, acceptWsAfterHead, acceptRest, acceptWsAfterRest, acceptWsAfterSort, acceptWsAfterIter, acceptWsAfterIterStar, acceptWsAfterIterSep, acceptWsAfterSeparator, acceptWsAfterIterStarSep, acceptWsAfterIterN, acceptNumber, acceptWsAfterNumber, acceptWsAfterIterSepN, acceptWsAfterComma1, acceptWsAfterComma2, acceptWsAfterFunc, acceptWsAfterVarsym, acceptWsAfterCharClass, acceptCharRanges, acceptWsAfterCharRanges, acceptWsAfterStrategy, acceptWsAfterParameterizedSort, acceptSort, acceptParameters, acceptWsAfterParameters),
        acceptWsAfterSymbol ? acceptWsAfterSymbol(PTPT_getSymbolWsAfterSymbol(arg)) : PTPT_getSymbolWsAfterSymbol(arg));
  }
  if (PTPT_isSymbolIterSep(arg)) {
    return PTPT_makeSymbolIterSep(
        acceptWsAfterIterSep ? acceptWsAfterIterSep(PTPT_getSymbolWsAfterIterSep(arg)) : PTPT_getSymbolWsAfterIterSep(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PTPT_getSymbolWsAfterParenOpen(arg)) : PTPT_getSymbolWsAfterParenOpen(arg),
        PTPT_visitSymbol(PTPT_getSymbolSymbol(arg), acceptWsAfterLit, acceptWsAfterParenOpen, acceptString, acceptWsAfterString, acceptWsAfterCilit, acceptWsAfterCf, acceptWsAfterSymbol, acceptWsAfterLex, acceptWsAfterOpt, acceptWsAfterAlt, acceptWsAfterLhs, acceptWsAfterComma, acceptWsAfterRhs, acceptWsAfterSeq, acceptSymbols, acceptWsAfterSymbols, acceptWsAfterTuple, acceptWsAfterHead, acceptRest, acceptWsAfterRest, acceptWsAfterSort, acceptWsAfterIter, acceptWsAfterIterStar, acceptWsAfterIterSep, acceptWsAfterSeparator, acceptWsAfterIterStarSep, acceptWsAfterIterN, acceptNumber, acceptWsAfterNumber, acceptWsAfterIterSepN, acceptWsAfterComma1, acceptWsAfterComma2, acceptWsAfterFunc, acceptWsAfterVarsym, acceptWsAfterCharClass, acceptCharRanges, acceptWsAfterCharRanges, acceptWsAfterStrategy, acceptWsAfterParameterizedSort, acceptSort, acceptParameters, acceptWsAfterParameters),
        acceptWsAfterSymbol ? acceptWsAfterSymbol(PTPT_getSymbolWsAfterSymbol(arg)) : PTPT_getSymbolWsAfterSymbol(arg),
        acceptWsAfterComma ? acceptWsAfterComma(PTPT_getSymbolWsAfterComma(arg)) : PTPT_getSymbolWsAfterComma(arg),
        PTPT_visitSymbol(PTPT_getSymbolSeparator(arg), acceptWsAfterLit, acceptWsAfterParenOpen, acceptString, acceptWsAfterString, acceptWsAfterCilit, acceptWsAfterCf, acceptWsAfterSymbol, acceptWsAfterLex, acceptWsAfterOpt, acceptWsAfterAlt, acceptWsAfterLhs, acceptWsAfterComma, acceptWsAfterRhs, acceptWsAfterSeq, acceptSymbols, acceptWsAfterSymbols, acceptWsAfterTuple, acceptWsAfterHead, acceptRest, acceptWsAfterRest, acceptWsAfterSort, acceptWsAfterIter, acceptWsAfterIterStar, acceptWsAfterIterSep, acceptWsAfterSeparator, acceptWsAfterIterStarSep, acceptWsAfterIterN, acceptNumber, acceptWsAfterNumber, acceptWsAfterIterSepN, acceptWsAfterComma1, acceptWsAfterComma2, acceptWsAfterFunc, acceptWsAfterVarsym, acceptWsAfterCharClass, acceptCharRanges, acceptWsAfterCharRanges, acceptWsAfterStrategy, acceptWsAfterParameterizedSort, acceptSort, acceptParameters, acceptWsAfterParameters),
        acceptWsAfterSeparator ? acceptWsAfterSeparator(PTPT_getSymbolWsAfterSeparator(arg)) : PTPT_getSymbolWsAfterSeparator(arg));
  }
  if (PTPT_isSymbolIterStarSep(arg)) {
    return PTPT_makeSymbolIterStarSep(
        acceptWsAfterIterStarSep ? acceptWsAfterIterStarSep(PTPT_getSymbolWsAfterIterStarSep(arg)) : PTPT_getSymbolWsAfterIterStarSep(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PTPT_getSymbolWsAfterParenOpen(arg)) : PTPT_getSymbolWsAfterParenOpen(arg),
        PTPT_visitSymbol(PTPT_getSymbolSymbol(arg), acceptWsAfterLit, acceptWsAfterParenOpen, acceptString, acceptWsAfterString, acceptWsAfterCilit, acceptWsAfterCf, acceptWsAfterSymbol, acceptWsAfterLex, acceptWsAfterOpt, acceptWsAfterAlt, acceptWsAfterLhs, acceptWsAfterComma, acceptWsAfterRhs, acceptWsAfterSeq, acceptSymbols, acceptWsAfterSymbols, acceptWsAfterTuple, acceptWsAfterHead, acceptRest, acceptWsAfterRest, acceptWsAfterSort, acceptWsAfterIter, acceptWsAfterIterStar, acceptWsAfterIterSep, acceptWsAfterSeparator, acceptWsAfterIterStarSep, acceptWsAfterIterN, acceptNumber, acceptWsAfterNumber, acceptWsAfterIterSepN, acceptWsAfterComma1, acceptWsAfterComma2, acceptWsAfterFunc, acceptWsAfterVarsym, acceptWsAfterCharClass, acceptCharRanges, acceptWsAfterCharRanges, acceptWsAfterStrategy, acceptWsAfterParameterizedSort, acceptSort, acceptParameters, acceptWsAfterParameters),
        acceptWsAfterSymbol ? acceptWsAfterSymbol(PTPT_getSymbolWsAfterSymbol(arg)) : PTPT_getSymbolWsAfterSymbol(arg),
        acceptWsAfterComma ? acceptWsAfterComma(PTPT_getSymbolWsAfterComma(arg)) : PTPT_getSymbolWsAfterComma(arg),
        PTPT_visitSymbol(PTPT_getSymbolSeparator(arg), acceptWsAfterLit, acceptWsAfterParenOpen, acceptString, acceptWsAfterString, acceptWsAfterCilit, acceptWsAfterCf, acceptWsAfterSymbol, acceptWsAfterLex, acceptWsAfterOpt, acceptWsAfterAlt, acceptWsAfterLhs, acceptWsAfterComma, acceptWsAfterRhs, acceptWsAfterSeq, acceptSymbols, acceptWsAfterSymbols, acceptWsAfterTuple, acceptWsAfterHead, acceptRest, acceptWsAfterRest, acceptWsAfterSort, acceptWsAfterIter, acceptWsAfterIterStar, acceptWsAfterIterSep, acceptWsAfterSeparator, acceptWsAfterIterStarSep, acceptWsAfterIterN, acceptNumber, acceptWsAfterNumber, acceptWsAfterIterSepN, acceptWsAfterComma1, acceptWsAfterComma2, acceptWsAfterFunc, acceptWsAfterVarsym, acceptWsAfterCharClass, acceptCharRanges, acceptWsAfterCharRanges, acceptWsAfterStrategy, acceptWsAfterParameterizedSort, acceptSort, acceptParameters, acceptWsAfterParameters),
        acceptWsAfterSeparator ? acceptWsAfterSeparator(PTPT_getSymbolWsAfterSeparator(arg)) : PTPT_getSymbolWsAfterSeparator(arg));
  }
  if (PTPT_isSymbolIterN(arg)) {
    return PTPT_makeSymbolIterN(
        acceptWsAfterIterN ? acceptWsAfterIterN(PTPT_getSymbolWsAfterIterN(arg)) : PTPT_getSymbolWsAfterIterN(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PTPT_getSymbolWsAfterParenOpen(arg)) : PTPT_getSymbolWsAfterParenOpen(arg),
        PTPT_visitSymbol(PTPT_getSymbolSymbol(arg), acceptWsAfterLit, acceptWsAfterParenOpen, acceptString, acceptWsAfterString, acceptWsAfterCilit, acceptWsAfterCf, acceptWsAfterSymbol, acceptWsAfterLex, acceptWsAfterOpt, acceptWsAfterAlt, acceptWsAfterLhs, acceptWsAfterComma, acceptWsAfterRhs, acceptWsAfterSeq, acceptSymbols, acceptWsAfterSymbols, acceptWsAfterTuple, acceptWsAfterHead, acceptRest, acceptWsAfterRest, acceptWsAfterSort, acceptWsAfterIter, acceptWsAfterIterStar, acceptWsAfterIterSep, acceptWsAfterSeparator, acceptWsAfterIterStarSep, acceptWsAfterIterN, acceptNumber, acceptWsAfterNumber, acceptWsAfterIterSepN, acceptWsAfterComma1, acceptWsAfterComma2, acceptWsAfterFunc, acceptWsAfterVarsym, acceptWsAfterCharClass, acceptCharRanges, acceptWsAfterCharRanges, acceptWsAfterStrategy, acceptWsAfterParameterizedSort, acceptSort, acceptParameters, acceptWsAfterParameters),
        acceptWsAfterSymbol ? acceptWsAfterSymbol(PTPT_getSymbolWsAfterSymbol(arg)) : PTPT_getSymbolWsAfterSymbol(arg),
        acceptWsAfterComma ? acceptWsAfterComma(PTPT_getSymbolWsAfterComma(arg)) : PTPT_getSymbolWsAfterComma(arg),
        acceptNumber ? acceptNumber(PTPT_getSymbolNumber(arg)) : PTPT_getSymbolNumber(arg),
        acceptWsAfterNumber ? acceptWsAfterNumber(PTPT_getSymbolWsAfterNumber(arg)) : PTPT_getSymbolWsAfterNumber(arg));
  }
  if (PTPT_isSymbolIterSepN(arg)) {
    return PTPT_makeSymbolIterSepN(
        acceptWsAfterIterSepN ? acceptWsAfterIterSepN(PTPT_getSymbolWsAfterIterSepN(arg)) : PTPT_getSymbolWsAfterIterSepN(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PTPT_getSymbolWsAfterParenOpen(arg)) : PTPT_getSymbolWsAfterParenOpen(arg),
        PTPT_visitSymbol(PTPT_getSymbolSymbol(arg), acceptWsAfterLit, acceptWsAfterParenOpen, acceptString, acceptWsAfterString, acceptWsAfterCilit, acceptWsAfterCf, acceptWsAfterSymbol, acceptWsAfterLex, acceptWsAfterOpt, acceptWsAfterAlt, acceptWsAfterLhs, acceptWsAfterComma, acceptWsAfterRhs, acceptWsAfterSeq, acceptSymbols, acceptWsAfterSymbols, acceptWsAfterTuple, acceptWsAfterHead, acceptRest, acceptWsAfterRest, acceptWsAfterSort, acceptWsAfterIter, acceptWsAfterIterStar, acceptWsAfterIterSep, acceptWsAfterSeparator, acceptWsAfterIterStarSep, acceptWsAfterIterN, acceptNumber, acceptWsAfterNumber, acceptWsAfterIterSepN, acceptWsAfterComma1, acceptWsAfterComma2, acceptWsAfterFunc, acceptWsAfterVarsym, acceptWsAfterCharClass, acceptCharRanges, acceptWsAfterCharRanges, acceptWsAfterStrategy, acceptWsAfterParameterizedSort, acceptSort, acceptParameters, acceptWsAfterParameters),
        acceptWsAfterSymbol ? acceptWsAfterSymbol(PTPT_getSymbolWsAfterSymbol(arg)) : PTPT_getSymbolWsAfterSymbol(arg),
        acceptWsAfterComma1 ? acceptWsAfterComma1(PTPT_getSymbolWsAfterComma1(arg)) : PTPT_getSymbolWsAfterComma1(arg),
        PTPT_visitSymbol(PTPT_getSymbolSeparator(arg), acceptWsAfterLit, acceptWsAfterParenOpen, acceptString, acceptWsAfterString, acceptWsAfterCilit, acceptWsAfterCf, acceptWsAfterSymbol, acceptWsAfterLex, acceptWsAfterOpt, acceptWsAfterAlt, acceptWsAfterLhs, acceptWsAfterComma, acceptWsAfterRhs, acceptWsAfterSeq, acceptSymbols, acceptWsAfterSymbols, acceptWsAfterTuple, acceptWsAfterHead, acceptRest, acceptWsAfterRest, acceptWsAfterSort, acceptWsAfterIter, acceptWsAfterIterStar, acceptWsAfterIterSep, acceptWsAfterSeparator, acceptWsAfterIterStarSep, acceptWsAfterIterN, acceptNumber, acceptWsAfterNumber, acceptWsAfterIterSepN, acceptWsAfterComma1, acceptWsAfterComma2, acceptWsAfterFunc, acceptWsAfterVarsym, acceptWsAfterCharClass, acceptCharRanges, acceptWsAfterCharRanges, acceptWsAfterStrategy, acceptWsAfterParameterizedSort, acceptSort, acceptParameters, acceptWsAfterParameters),
        acceptWsAfterSeparator ? acceptWsAfterSeparator(PTPT_getSymbolWsAfterSeparator(arg)) : PTPT_getSymbolWsAfterSeparator(arg),
        acceptWsAfterComma2 ? acceptWsAfterComma2(PTPT_getSymbolWsAfterComma2(arg)) : PTPT_getSymbolWsAfterComma2(arg),
        acceptNumber ? acceptNumber(PTPT_getSymbolNumber(arg)) : PTPT_getSymbolNumber(arg),
        acceptWsAfterNumber ? acceptWsAfterNumber(PTPT_getSymbolWsAfterNumber(arg)) : PTPT_getSymbolWsAfterNumber(arg));
  }
  if (PTPT_isSymbolFunc(arg)) {
    return PTPT_makeSymbolFunc(
        acceptWsAfterFunc ? acceptWsAfterFunc(PTPT_getSymbolWsAfterFunc(arg)) : PTPT_getSymbolWsAfterFunc(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PTPT_getSymbolWsAfterParenOpen(arg)) : PTPT_getSymbolWsAfterParenOpen(arg),
        acceptSymbols ? acceptSymbols(PTPT_getSymbolSymbols(arg)) : PTPT_getSymbolSymbols(arg),
        acceptWsAfterSymbols ? acceptWsAfterSymbols(PTPT_getSymbolWsAfterSymbols(arg)) : PTPT_getSymbolWsAfterSymbols(arg),
        acceptWsAfterComma ? acceptWsAfterComma(PTPT_getSymbolWsAfterComma(arg)) : PTPT_getSymbolWsAfterComma(arg),
        PTPT_visitSymbol(PTPT_getSymbolSymbol(arg), acceptWsAfterLit, acceptWsAfterParenOpen, acceptString, acceptWsAfterString, acceptWsAfterCilit, acceptWsAfterCf, acceptWsAfterSymbol, acceptWsAfterLex, acceptWsAfterOpt, acceptWsAfterAlt, acceptWsAfterLhs, acceptWsAfterComma, acceptWsAfterRhs, acceptWsAfterSeq, acceptSymbols, acceptWsAfterSymbols, acceptWsAfterTuple, acceptWsAfterHead, acceptRest, acceptWsAfterRest, acceptWsAfterSort, acceptWsAfterIter, acceptWsAfterIterStar, acceptWsAfterIterSep, acceptWsAfterSeparator, acceptWsAfterIterStarSep, acceptWsAfterIterN, acceptNumber, acceptWsAfterNumber, acceptWsAfterIterSepN, acceptWsAfterComma1, acceptWsAfterComma2, acceptWsAfterFunc, acceptWsAfterVarsym, acceptWsAfterCharClass, acceptCharRanges, acceptWsAfterCharRanges, acceptWsAfterStrategy, acceptWsAfterParameterizedSort, acceptSort, acceptParameters, acceptWsAfterParameters),
        acceptWsAfterSymbol ? acceptWsAfterSymbol(PTPT_getSymbolWsAfterSymbol(arg)) : PTPT_getSymbolWsAfterSymbol(arg));
  }
  if (PTPT_isSymbolVarsym(arg)) {
    return PTPT_makeSymbolVarsym(
        acceptWsAfterVarsym ? acceptWsAfterVarsym(PTPT_getSymbolWsAfterVarsym(arg)) : PTPT_getSymbolWsAfterVarsym(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PTPT_getSymbolWsAfterParenOpen(arg)) : PTPT_getSymbolWsAfterParenOpen(arg),
        PTPT_visitSymbol(PTPT_getSymbolSymbol(arg), acceptWsAfterLit, acceptWsAfterParenOpen, acceptString, acceptWsAfterString, acceptWsAfterCilit, acceptWsAfterCf, acceptWsAfterSymbol, acceptWsAfterLex, acceptWsAfterOpt, acceptWsAfterAlt, acceptWsAfterLhs, acceptWsAfterComma, acceptWsAfterRhs, acceptWsAfterSeq, acceptSymbols, acceptWsAfterSymbols, acceptWsAfterTuple, acceptWsAfterHead, acceptRest, acceptWsAfterRest, acceptWsAfterSort, acceptWsAfterIter, acceptWsAfterIterStar, acceptWsAfterIterSep, acceptWsAfterSeparator, acceptWsAfterIterStarSep, acceptWsAfterIterN, acceptNumber, acceptWsAfterNumber, acceptWsAfterIterSepN, acceptWsAfterComma1, acceptWsAfterComma2, acceptWsAfterFunc, acceptWsAfterVarsym, acceptWsAfterCharClass, acceptCharRanges, acceptWsAfterCharRanges, acceptWsAfterStrategy, acceptWsAfterParameterizedSort, acceptSort, acceptParameters, acceptWsAfterParameters),
        acceptWsAfterSymbol ? acceptWsAfterSymbol(PTPT_getSymbolWsAfterSymbol(arg)) : PTPT_getSymbolWsAfterSymbol(arg));
  }
  if (PTPT_isSymbolLayout(arg)) {
    return PTPT_makeSymbolLayout();
  }
  if (PTPT_isSymbolCharClass(arg)) {
    return PTPT_makeSymbolCharClass(
        acceptWsAfterCharClass ? acceptWsAfterCharClass(PTPT_getSymbolWsAfterCharClass(arg)) : PTPT_getSymbolWsAfterCharClass(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PTPT_getSymbolWsAfterParenOpen(arg)) : PTPT_getSymbolWsAfterParenOpen(arg),
        acceptCharRanges ? acceptCharRanges(PTPT_getSymbolCharRanges(arg)) : PTPT_getSymbolCharRanges(arg),
        acceptWsAfterCharRanges ? acceptWsAfterCharRanges(PTPT_getSymbolWsAfterCharRanges(arg)) : PTPT_getSymbolWsAfterCharRanges(arg));
  }
  if (PTPT_isSymbolStrategy(arg)) {
    return PTPT_makeSymbolStrategy(
        acceptWsAfterStrategy ? acceptWsAfterStrategy(PTPT_getSymbolWsAfterStrategy(arg)) : PTPT_getSymbolWsAfterStrategy(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PTPT_getSymbolWsAfterParenOpen(arg)) : PTPT_getSymbolWsAfterParenOpen(arg),
        PTPT_visitSymbol(PTPT_getSymbolLhs(arg), acceptWsAfterLit, acceptWsAfterParenOpen, acceptString, acceptWsAfterString, acceptWsAfterCilit, acceptWsAfterCf, acceptWsAfterSymbol, acceptWsAfterLex, acceptWsAfterOpt, acceptWsAfterAlt, acceptWsAfterLhs, acceptWsAfterComma, acceptWsAfterRhs, acceptWsAfterSeq, acceptSymbols, acceptWsAfterSymbols, acceptWsAfterTuple, acceptWsAfterHead, acceptRest, acceptWsAfterRest, acceptWsAfterSort, acceptWsAfterIter, acceptWsAfterIterStar, acceptWsAfterIterSep, acceptWsAfterSeparator, acceptWsAfterIterStarSep, acceptWsAfterIterN, acceptNumber, acceptWsAfterNumber, acceptWsAfterIterSepN, acceptWsAfterComma1, acceptWsAfterComma2, acceptWsAfterFunc, acceptWsAfterVarsym, acceptWsAfterCharClass, acceptCharRanges, acceptWsAfterCharRanges, acceptWsAfterStrategy, acceptWsAfterParameterizedSort, acceptSort, acceptParameters, acceptWsAfterParameters),
        acceptWsAfterLhs ? acceptWsAfterLhs(PTPT_getSymbolWsAfterLhs(arg)) : PTPT_getSymbolWsAfterLhs(arg),
        acceptWsAfterComma ? acceptWsAfterComma(PTPT_getSymbolWsAfterComma(arg)) : PTPT_getSymbolWsAfterComma(arg),
        PTPT_visitSymbol(PTPT_getSymbolRhs(arg), acceptWsAfterLit, acceptWsAfterParenOpen, acceptString, acceptWsAfterString, acceptWsAfterCilit, acceptWsAfterCf, acceptWsAfterSymbol, acceptWsAfterLex, acceptWsAfterOpt, acceptWsAfterAlt, acceptWsAfterLhs, acceptWsAfterComma, acceptWsAfterRhs, acceptWsAfterSeq, acceptSymbols, acceptWsAfterSymbols, acceptWsAfterTuple, acceptWsAfterHead, acceptRest, acceptWsAfterRest, acceptWsAfterSort, acceptWsAfterIter, acceptWsAfterIterStar, acceptWsAfterIterSep, acceptWsAfterSeparator, acceptWsAfterIterStarSep, acceptWsAfterIterN, acceptNumber, acceptWsAfterNumber, acceptWsAfterIterSepN, acceptWsAfterComma1, acceptWsAfterComma2, acceptWsAfterFunc, acceptWsAfterVarsym, acceptWsAfterCharClass, acceptCharRanges, acceptWsAfterCharRanges, acceptWsAfterStrategy, acceptWsAfterParameterizedSort, acceptSort, acceptParameters, acceptWsAfterParameters),
        acceptWsAfterRhs ? acceptWsAfterRhs(PTPT_getSymbolWsAfterRhs(arg)) : PTPT_getSymbolWsAfterRhs(arg));
  }
  if (PTPT_isSymbolParameterizedSort(arg)) {
    return PTPT_makeSymbolParameterizedSort(
        acceptWsAfterParameterizedSort ? acceptWsAfterParameterizedSort(PTPT_getSymbolWsAfterParameterizedSort(arg)) : PTPT_getSymbolWsAfterParameterizedSort(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PTPT_getSymbolWsAfterParenOpen(arg)) : PTPT_getSymbolWsAfterParenOpen(arg),
        acceptSort ? acceptSort(PTPT_getSymbolSort(arg)) : PTPT_getSymbolSort(arg),
        acceptWsAfterSort ? acceptWsAfterSort(PTPT_getSymbolWsAfterSort(arg)) : PTPT_getSymbolWsAfterSort(arg),
        acceptWsAfterComma ? acceptWsAfterComma(PTPT_getSymbolWsAfterComma(arg)) : PTPT_getSymbolWsAfterComma(arg),
        acceptParameters ? acceptParameters(PTPT_getSymbolParameters(arg)) : PTPT_getSymbolParameters(arg),
        acceptWsAfterParameters ? acceptWsAfterParameters(PTPT_getSymbolWsAfterParameters(arg)) : PTPT_getSymbolWsAfterParameters(arg));
  }
  ATabort("not a Symbol: %t\n", arg);
  return (PTPT_Symbol)NULL;
}

/*}}}  */
/*{{{  PTPT_Symbols PTPT_visitSymbols(PTPT_Symbols arg, PTPT_OptLayout (*acceptWsAfterBracketOpen)(PTPT_OptLayout), PTPT_SymbolList (*acceptList)(PTPT_SymbolList), PTPT_OptLayout (*acceptWsAfterList)(PTPT_OptLayout)) */

PTPT_Symbols PTPT_visitSymbols(PTPT_Symbols arg, PTPT_OptLayout (*acceptWsAfterBracketOpen)(PTPT_OptLayout), PTPT_SymbolList (*acceptList)(PTPT_SymbolList), PTPT_OptLayout (*acceptWsAfterList)(PTPT_OptLayout))
{
  if (PTPT_isSymbolsList(arg)) {
    return PTPT_makeSymbolsList(
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(PTPT_getSymbolsWsAfterBracketOpen(arg)) : PTPT_getSymbolsWsAfterBracketOpen(arg),
        acceptList ? acceptList(PTPT_getSymbolsList(arg)) : PTPT_getSymbolsList(arg),
        acceptWsAfterList ? acceptWsAfterList(PTPT_getSymbolsWsAfterList(arg)) : PTPT_getSymbolsWsAfterList(arg));
  }
  ATabort("not a Symbols: %t\n", arg);
  return (PTPT_Symbols)NULL;
}

/*}}}  */
/*{{{  PTPT_CharRanges PTPT_visitCharRanges(PTPT_CharRanges arg, PTPT_OptLayout (*acceptWsAfterBracketOpen)(PTPT_OptLayout), PTPT_CharRangeList (*acceptList)(PTPT_CharRangeList), PTPT_OptLayout (*acceptWsAfterList)(PTPT_OptLayout)) */

PTPT_CharRanges PTPT_visitCharRanges(PTPT_CharRanges arg, PTPT_OptLayout (*acceptWsAfterBracketOpen)(PTPT_OptLayout), PTPT_CharRangeList (*acceptList)(PTPT_CharRangeList), PTPT_OptLayout (*acceptWsAfterList)(PTPT_OptLayout))
{
  if (PTPT_isCharRangesList(arg)) {
    return PTPT_makeCharRangesList(
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(PTPT_getCharRangesWsAfterBracketOpen(arg)) : PTPT_getCharRangesWsAfterBracketOpen(arg),
        acceptList ? acceptList(PTPT_getCharRangesList(arg)) : PTPT_getCharRangesList(arg),
        acceptWsAfterList ? acceptWsAfterList(PTPT_getCharRangesWsAfterList(arg)) : PTPT_getCharRangesWsAfterList(arg));
  }
  ATabort("not a CharRanges: %t\n", arg);
  return (PTPT_CharRanges)NULL;
}

/*}}}  */
/*{{{  PTPT_CharRange PTPT_visitCharRange(PTPT_CharRange arg, PTPT_NatCon (*acceptInteger)(PTPT_NatCon), PTPT_OptLayout (*acceptWsAfterRange)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterParenOpen)(PTPT_OptLayout), PTPT_NatCon (*acceptStart)(PTPT_NatCon), PTPT_OptLayout (*acceptWsAfterStart)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterComma)(PTPT_OptLayout), PTPT_NatCon (*acceptEnd)(PTPT_NatCon), PTPT_OptLayout (*acceptWsAfterEnd)(PTPT_OptLayout)) */

PTPT_CharRange PTPT_visitCharRange(PTPT_CharRange arg, PTPT_NatCon (*acceptInteger)(PTPT_NatCon), PTPT_OptLayout (*acceptWsAfterRange)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterParenOpen)(PTPT_OptLayout), PTPT_NatCon (*acceptStart)(PTPT_NatCon), PTPT_OptLayout (*acceptWsAfterStart)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterComma)(PTPT_OptLayout), PTPT_NatCon (*acceptEnd)(PTPT_NatCon), PTPT_OptLayout (*acceptWsAfterEnd)(PTPT_OptLayout))
{
  if (PTPT_isCharRangeCharacter(arg)) {
    return PTPT_makeCharRangeCharacter(
        acceptInteger ? acceptInteger(PTPT_getCharRangeInteger(arg)) : PTPT_getCharRangeInteger(arg));
  }
  if (PTPT_isCharRangeRange(arg)) {
    return PTPT_makeCharRangeRange(
        acceptWsAfterRange ? acceptWsAfterRange(PTPT_getCharRangeWsAfterRange(arg)) : PTPT_getCharRangeWsAfterRange(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PTPT_getCharRangeWsAfterParenOpen(arg)) : PTPT_getCharRangeWsAfterParenOpen(arg),
        acceptStart ? acceptStart(PTPT_getCharRangeStart(arg)) : PTPT_getCharRangeStart(arg),
        acceptWsAfterStart ? acceptWsAfterStart(PTPT_getCharRangeWsAfterStart(arg)) : PTPT_getCharRangeWsAfterStart(arg),
        acceptWsAfterComma ? acceptWsAfterComma(PTPT_getCharRangeWsAfterComma(arg)) : PTPT_getCharRangeWsAfterComma(arg),
        acceptEnd ? acceptEnd(PTPT_getCharRangeEnd(arg)) : PTPT_getCharRangeEnd(arg),
        acceptWsAfterEnd ? acceptWsAfterEnd(PTPT_getCharRangeWsAfterEnd(arg)) : PTPT_getCharRangeWsAfterEnd(arg));
  }
  ATabort("not a CharRange: %t\n", arg);
  return (PTPT_CharRange)NULL;
}

/*}}}  */
/*{{{  PTPT_Start PTPT_visitStart(PTPT_Start arg, PTPT_OptLayout (*acceptWsBefore)(PTPT_OptLayout), PTPT_Symbol (*acceptTopSymbol)(PTPT_Symbol), PTPT_OptLayout (*acceptWsAfter)(PTPT_OptLayout), int (*acceptAmbCnt)(int), PTPT_Tree (*acceptTopTree)(PTPT_Tree), PTPT_ATerm (*acceptTopATerm)(PTPT_ATerm), PTPT_IntCon (*acceptTopIntCon)(PTPT_IntCon), PTPT_RealCon (*acceptTopRealCon)(PTPT_RealCon)) */

PTPT_Start PTPT_visitStart(PTPT_Start arg, PTPT_OptLayout (*acceptWsBefore)(PTPT_OptLayout), PTPT_Symbol (*acceptTopSymbol)(PTPT_Symbol), PTPT_OptLayout (*acceptWsAfter)(PTPT_OptLayout), int (*acceptAmbCnt)(int), PTPT_Tree (*acceptTopTree)(PTPT_Tree), PTPT_ATerm (*acceptTopATerm)(PTPT_ATerm), PTPT_IntCon (*acceptTopIntCon)(PTPT_IntCon), PTPT_RealCon (*acceptTopRealCon)(PTPT_RealCon))
{
  if (PTPT_isStartSymbol(arg)) {
    return PTPT_makeStartSymbol(
        acceptWsBefore ? acceptWsBefore(PTPT_getStartWsBefore(arg)) : PTPT_getStartWsBefore(arg),
        acceptTopSymbol ? acceptTopSymbol(PTPT_getStartTopSymbol(arg)) : PTPT_getStartTopSymbol(arg),
        acceptWsAfter ? acceptWsAfter(PTPT_getStartWsAfter(arg)) : PTPT_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(PTPT_getStartAmbCnt(arg)) : PTPT_getStartAmbCnt(arg));
  }
  if (PTPT_isStartTree(arg)) {
    return PTPT_makeStartTree(
        acceptWsBefore ? acceptWsBefore(PTPT_getStartWsBefore(arg)) : PTPT_getStartWsBefore(arg),
        acceptTopTree ? acceptTopTree(PTPT_getStartTopTree(arg)) : PTPT_getStartTopTree(arg),
        acceptWsAfter ? acceptWsAfter(PTPT_getStartWsAfter(arg)) : PTPT_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(PTPT_getStartAmbCnt(arg)) : PTPT_getStartAmbCnt(arg));
  }
  if (PTPT_isStartATerm(arg)) {
    return PTPT_makeStartATerm(
        acceptWsBefore ? acceptWsBefore(PTPT_getStartWsBefore(arg)) : PTPT_getStartWsBefore(arg),
        acceptTopATerm ? acceptTopATerm(PTPT_getStartTopATerm(arg)) : PTPT_getStartTopATerm(arg),
        acceptWsAfter ? acceptWsAfter(PTPT_getStartWsAfter(arg)) : PTPT_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(PTPT_getStartAmbCnt(arg)) : PTPT_getStartAmbCnt(arg));
  }
  if (PTPT_isStartIntCon(arg)) {
    return PTPT_makeStartIntCon(
        acceptWsBefore ? acceptWsBefore(PTPT_getStartWsBefore(arg)) : PTPT_getStartWsBefore(arg),
        acceptTopIntCon ? acceptTopIntCon(PTPT_getStartTopIntCon(arg)) : PTPT_getStartTopIntCon(arg),
        acceptWsAfter ? acceptWsAfter(PTPT_getStartWsAfter(arg)) : PTPT_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(PTPT_getStartAmbCnt(arg)) : PTPT_getStartAmbCnt(arg));
  }
  if (PTPT_isStartRealCon(arg)) {
    return PTPT_makeStartRealCon(
        acceptWsBefore ? acceptWsBefore(PTPT_getStartWsBefore(arg)) : PTPT_getStartWsBefore(arg),
        acceptTopRealCon ? acceptTopRealCon(PTPT_getStartTopRealCon(arg)) : PTPT_getStartTopRealCon(arg),
        acceptWsAfter ? acceptWsAfter(PTPT_getStartWsAfter(arg)) : PTPT_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(PTPT_getStartAmbCnt(arg)) : PTPT_getStartAmbCnt(arg));
  }
  ATabort("not a Start: %t\n", arg);
  return (PTPT_Start)NULL;
}

/*}}}  */
/*{{{  PTPT_SymbolList PTPT_visitSymbolList(PTPT_SymbolList arg, PTPT_Symbol (*acceptHead)(PTPT_Symbol), PTPT_OptLayout (*acceptWsAfterHead)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterSep)(PTPT_OptLayout)) */

PTPT_SymbolList PTPT_visitSymbolList(PTPT_SymbolList arg, PTPT_Symbol (*acceptHead)(PTPT_Symbol), PTPT_OptLayout (*acceptWsAfterHead)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterSep)(PTPT_OptLayout))
{
  if (PTPT_isSymbolListEmpty(arg)) {
    return PTPT_makeSymbolListEmpty();
  }
  if (PTPT_isSymbolListSingle(arg)) {
    return PTPT_makeSymbolListSingle(
        acceptHead ? acceptHead(PTPT_getSymbolListHead(arg)) : PTPT_getSymbolListHead(arg));
  }
  if (PTPT_isSymbolListMany(arg)) {
    return PTPT_makeSymbolListMany(
        acceptHead ? acceptHead(PTPT_getSymbolListHead(arg)) : PTPT_getSymbolListHead(arg),
        acceptWsAfterHead ? acceptWsAfterHead(PTPT_getSymbolListWsAfterHead(arg)) : PTPT_getSymbolListWsAfterHead(arg),
        acceptWsAfterSep ? acceptWsAfterSep(PTPT_getSymbolListWsAfterSep(arg)) : PTPT_getSymbolListWsAfterSep(arg),
        PTPT_visitSymbolList(PTPT_getSymbolListTail(arg), acceptHead, acceptWsAfterHead, acceptWsAfterSep));
  }
  ATabort("not a SymbolList: %t\n", arg);
  return (PTPT_SymbolList)NULL;
}

/*}}}  */
/*{{{  PTPT_CharRangeList PTPT_visitCharRangeList(PTPT_CharRangeList arg, PTPT_CharRange (*acceptHead)(PTPT_CharRange), PTPT_OptLayout (*acceptWsAfterHead)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterSep)(PTPT_OptLayout)) */

PTPT_CharRangeList PTPT_visitCharRangeList(PTPT_CharRangeList arg, PTPT_CharRange (*acceptHead)(PTPT_CharRange), PTPT_OptLayout (*acceptWsAfterHead)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterSep)(PTPT_OptLayout))
{
  if (PTPT_isCharRangeListEmpty(arg)) {
    return PTPT_makeCharRangeListEmpty();
  }
  if (PTPT_isCharRangeListSingle(arg)) {
    return PTPT_makeCharRangeListSingle(
        acceptHead ? acceptHead(PTPT_getCharRangeListHead(arg)) : PTPT_getCharRangeListHead(arg));
  }
  if (PTPT_isCharRangeListMany(arg)) {
    return PTPT_makeCharRangeListMany(
        acceptHead ? acceptHead(PTPT_getCharRangeListHead(arg)) : PTPT_getCharRangeListHead(arg),
        acceptWsAfterHead ? acceptWsAfterHead(PTPT_getCharRangeListWsAfterHead(arg)) : PTPT_getCharRangeListWsAfterHead(arg),
        acceptWsAfterSep ? acceptWsAfterSep(PTPT_getCharRangeListWsAfterSep(arg)) : PTPT_getCharRangeListWsAfterSep(arg),
        PTPT_visitCharRangeList(PTPT_getCharRangeListTail(arg), acceptHead, acceptWsAfterHead, acceptWsAfterSep));
  }
  ATabort("not a CharRangeList: %t\n", arg);
  return (PTPT_CharRangeList)NULL;
}

/*}}}  */
/*{{{  PTPT_Args PTPT_visitArgs(PTPT_Args arg, PTPT_OptLayout (*acceptWsAfterBracketOpen)(PTPT_OptLayout), PTPT_TreeList (*acceptList)(PTPT_TreeList), PTPT_OptLayout (*acceptWsAfterList)(PTPT_OptLayout)) */

PTPT_Args PTPT_visitArgs(PTPT_Args arg, PTPT_OptLayout (*acceptWsAfterBracketOpen)(PTPT_OptLayout), PTPT_TreeList (*acceptList)(PTPT_TreeList), PTPT_OptLayout (*acceptWsAfterList)(PTPT_OptLayout))
{
  if (PTPT_isArgsList(arg)) {
    return PTPT_makeArgsList(
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(PTPT_getArgsWsAfterBracketOpen(arg)) : PTPT_getArgsWsAfterBracketOpen(arg),
        acceptList ? acceptList(PTPT_getArgsList(arg)) : PTPT_getArgsList(arg),
        acceptWsAfterList ? acceptWsAfterList(PTPT_getArgsWsAfterList(arg)) : PTPT_getArgsWsAfterList(arg));
  }
  ATabort("not a Args: %t\n", arg);
  return (PTPT_Args)NULL;
}

/*}}}  */
/*{{{  PTPT_Production PTPT_visitProduction(PTPT_Production arg, PTPT_OptLayout (*acceptWsAfterProd)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterParenOpen)(PTPT_OptLayout), PTPT_Symbols (*acceptLhs)(PTPT_Symbols), PTPT_OptLayout (*acceptWsAfterLhs)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterComma1)(PTPT_OptLayout), PTPT_Symbol (*acceptRhs)(PTPT_Symbol), PTPT_OptLayout (*acceptWsAfterRhs)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterComma2)(PTPT_OptLayout), PTPT_Attributes (*acceptAttributes)(PTPT_Attributes), PTPT_OptLayout (*acceptWsAfterAttributes)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterList)(PTPT_OptLayout)) */

PTPT_Production PTPT_visitProduction(PTPT_Production arg, PTPT_OptLayout (*acceptWsAfterProd)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterParenOpen)(PTPT_OptLayout), PTPT_Symbols (*acceptLhs)(PTPT_Symbols), PTPT_OptLayout (*acceptWsAfterLhs)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterComma1)(PTPT_OptLayout), PTPT_Symbol (*acceptRhs)(PTPT_Symbol), PTPT_OptLayout (*acceptWsAfterRhs)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterComma2)(PTPT_OptLayout), PTPT_Attributes (*acceptAttributes)(PTPT_Attributes), PTPT_OptLayout (*acceptWsAfterAttributes)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterList)(PTPT_OptLayout))
{
  if (PTPT_isProductionDefault(arg)) {
    return PTPT_makeProductionDefault(
        acceptWsAfterProd ? acceptWsAfterProd(PTPT_getProductionWsAfterProd(arg)) : PTPT_getProductionWsAfterProd(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PTPT_getProductionWsAfterParenOpen(arg)) : PTPT_getProductionWsAfterParenOpen(arg),
        acceptLhs ? acceptLhs(PTPT_getProductionLhs(arg)) : PTPT_getProductionLhs(arg),
        acceptWsAfterLhs ? acceptWsAfterLhs(PTPT_getProductionWsAfterLhs(arg)) : PTPT_getProductionWsAfterLhs(arg),
        acceptWsAfterComma1 ? acceptWsAfterComma1(PTPT_getProductionWsAfterComma1(arg)) : PTPT_getProductionWsAfterComma1(arg),
        acceptRhs ? acceptRhs(PTPT_getProductionRhs(arg)) : PTPT_getProductionRhs(arg),
        acceptWsAfterRhs ? acceptWsAfterRhs(PTPT_getProductionWsAfterRhs(arg)) : PTPT_getProductionWsAfterRhs(arg),
        acceptWsAfterComma2 ? acceptWsAfterComma2(PTPT_getProductionWsAfterComma2(arg)) : PTPT_getProductionWsAfterComma2(arg),
        acceptAttributes ? acceptAttributes(PTPT_getProductionAttributes(arg)) : PTPT_getProductionAttributes(arg),
        acceptWsAfterAttributes ? acceptWsAfterAttributes(PTPT_getProductionWsAfterAttributes(arg)) : PTPT_getProductionWsAfterAttributes(arg));
  }
  if (PTPT_isProductionList(arg)) {
    return PTPT_makeProductionList(
        acceptWsAfterList ? acceptWsAfterList(PTPT_getProductionWsAfterList(arg)) : PTPT_getProductionWsAfterList(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PTPT_getProductionWsAfterParenOpen(arg)) : PTPT_getProductionWsAfterParenOpen(arg),
        acceptRhs ? acceptRhs(PTPT_getProductionRhs(arg)) : PTPT_getProductionRhs(arg),
        acceptWsAfterRhs ? acceptWsAfterRhs(PTPT_getProductionWsAfterRhs(arg)) : PTPT_getProductionWsAfterRhs(arg));
  }
  ATabort("not a Production: %t\n", arg);
  return (PTPT_Production)NULL;
}

/*}}}  */
/*{{{  PTPT_TreeList PTPT_visitTreeList(PTPT_TreeList arg, PTPT_Tree (*acceptHead)(PTPT_Tree), PTPT_OptLayout (*acceptWsAfterHead)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterSep)(PTPT_OptLayout)) */

PTPT_TreeList PTPT_visitTreeList(PTPT_TreeList arg, PTPT_Tree (*acceptHead)(PTPT_Tree), PTPT_OptLayout (*acceptWsAfterHead)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterSep)(PTPT_OptLayout))
{
  if (PTPT_isTreeListEmpty(arg)) {
    return PTPT_makeTreeListEmpty();
  }
  if (PTPT_isTreeListSingle(arg)) {
    return PTPT_makeTreeListSingle(
        acceptHead ? acceptHead(PTPT_getTreeListHead(arg)) : PTPT_getTreeListHead(arg));
  }
  if (PTPT_isTreeListMany(arg)) {
    return PTPT_makeTreeListMany(
        acceptHead ? acceptHead(PTPT_getTreeListHead(arg)) : PTPT_getTreeListHead(arg),
        acceptWsAfterHead ? acceptWsAfterHead(PTPT_getTreeListWsAfterHead(arg)) : PTPT_getTreeListWsAfterHead(arg),
        acceptWsAfterSep ? acceptWsAfterSep(PTPT_getTreeListWsAfterSep(arg)) : PTPT_getTreeListWsAfterSep(arg),
        PTPT_visitTreeList(PTPT_getTreeListTail(arg), acceptHead, acceptWsAfterHead, acceptWsAfterSep));
  }
  ATabort("not a TreeList: %t\n", arg);
  return (PTPT_TreeList)NULL;
}

/*}}}  */
/*{{{  PTPT_AFun PTPT_visitAFun(PTPT_AFun arg, PTPT_StrCon (*acceptStrCon)(PTPT_StrCon), PTPT_IdCon (*acceptIdCon)(PTPT_IdCon)) */

PTPT_AFun PTPT_visitAFun(PTPT_AFun arg, PTPT_StrCon (*acceptStrCon)(PTPT_StrCon), PTPT_IdCon (*acceptIdCon)(PTPT_IdCon))
{
  if (PTPT_isAFunQuoted(arg)) {
    return PTPT_makeAFunQuoted(
        acceptStrCon ? acceptStrCon(PTPT_getAFunStrCon(arg)) : PTPT_getAFunStrCon(arg));
  }
  if (PTPT_isAFunUnquoted(arg)) {
    return PTPT_makeAFunUnquoted(
        acceptIdCon ? acceptIdCon(PTPT_getAFunIdCon(arg)) : PTPT_getAFunIdCon(arg));
  }
  ATabort("not a AFun: %t\n", arg);
  return (PTPT_AFun)NULL;
}

/*}}}  */
/*{{{  PTPT_ATerm PTPT_visitATerm(PTPT_ATerm arg, PTPT_IntCon (*acceptIntCon)(PTPT_IntCon), PTPT_RealCon (*acceptRealCon)(PTPT_RealCon), PTPT_AFun (*acceptFun)(PTPT_AFun), PTPT_OptLayout (*acceptWsAfterFun)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterParenOpen)(PTPT_OptLayout), PTPT_ATermArgs (*acceptArgs)(PTPT_ATermArgs), PTPT_OptLayout (*acceptWsAfterArgs)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterLessThan)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterType)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterBracketOpen)(PTPT_OptLayout), PTPT_ATermElems (*acceptElems)(PTPT_ATermElems), PTPT_OptLayout (*acceptWsAfterElems)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterTrm)(PTPT_OptLayout), PTPT_Annotation (*acceptAnnotation)(PTPT_Annotation)) */

PTPT_ATerm PTPT_visitATerm(PTPT_ATerm arg, PTPT_IntCon (*acceptIntCon)(PTPT_IntCon), PTPT_RealCon (*acceptRealCon)(PTPT_RealCon), PTPT_AFun (*acceptFun)(PTPT_AFun), PTPT_OptLayout (*acceptWsAfterFun)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterParenOpen)(PTPT_OptLayout), PTPT_ATermArgs (*acceptArgs)(PTPT_ATermArgs), PTPT_OptLayout (*acceptWsAfterArgs)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterLessThan)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterType)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterBracketOpen)(PTPT_OptLayout), PTPT_ATermElems (*acceptElems)(PTPT_ATermElems), PTPT_OptLayout (*acceptWsAfterElems)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterTrm)(PTPT_OptLayout), PTPT_Annotation (*acceptAnnotation)(PTPT_Annotation))
{
  if (PTPT_isATermInt(arg)) {
    return PTPT_makeATermInt(
        acceptIntCon ? acceptIntCon(PTPT_getATermIntCon(arg)) : PTPT_getATermIntCon(arg));
  }
  if (PTPT_isATermReal(arg)) {
    return PTPT_makeATermReal(
        acceptRealCon ? acceptRealCon(PTPT_getATermRealCon(arg)) : PTPT_getATermRealCon(arg));
  }
  if (PTPT_isATermFun(arg)) {
    return PTPT_makeATermFun(
        acceptFun ? acceptFun(PTPT_getATermFun(arg)) : PTPT_getATermFun(arg));
  }
  if (PTPT_isATermAppl(arg)) {
    return PTPT_makeATermAppl(
        acceptFun ? acceptFun(PTPT_getATermFun(arg)) : PTPT_getATermFun(arg),
        acceptWsAfterFun ? acceptWsAfterFun(PTPT_getATermWsAfterFun(arg)) : PTPT_getATermWsAfterFun(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PTPT_getATermWsAfterParenOpen(arg)) : PTPT_getATermWsAfterParenOpen(arg),
        acceptArgs ? acceptArgs(PTPT_getATermArgs(arg)) : PTPT_getATermArgs(arg),
        acceptWsAfterArgs ? acceptWsAfterArgs(PTPT_getATermWsAfterArgs(arg)) : PTPT_getATermWsAfterArgs(arg));
  }
  if (PTPT_isATermPlaceholder(arg)) {
    return PTPT_makeATermPlaceholder(
        acceptWsAfterLessThan ? acceptWsAfterLessThan(PTPT_getATermWsAfterLessThan(arg)) : PTPT_getATermWsAfterLessThan(arg),
        PTPT_visitATerm(PTPT_getATermType(arg), acceptIntCon, acceptRealCon, acceptFun, acceptWsAfterFun, acceptWsAfterParenOpen, acceptArgs, acceptWsAfterArgs, acceptWsAfterLessThan, acceptWsAfterType, acceptWsAfterBracketOpen, acceptElems, acceptWsAfterElems, acceptWsAfterTrm, acceptAnnotation),
        acceptWsAfterType ? acceptWsAfterType(PTPT_getATermWsAfterType(arg)) : PTPT_getATermWsAfterType(arg));
  }
  if (PTPT_isATermList(arg)) {
    return PTPT_makeATermList(
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(PTPT_getATermWsAfterBracketOpen(arg)) : PTPT_getATermWsAfterBracketOpen(arg),
        acceptElems ? acceptElems(PTPT_getATermElems(arg)) : PTPT_getATermElems(arg),
        acceptWsAfterElems ? acceptWsAfterElems(PTPT_getATermWsAfterElems(arg)) : PTPT_getATermWsAfterElems(arg));
  }
  if (PTPT_isATermAnnotated(arg)) {
    return PTPT_makeATermAnnotated(
        PTPT_visitATerm(PTPT_getATermTrm(arg), acceptIntCon, acceptRealCon, acceptFun, acceptWsAfterFun, acceptWsAfterParenOpen, acceptArgs, acceptWsAfterArgs, acceptWsAfterLessThan, acceptWsAfterType, acceptWsAfterBracketOpen, acceptElems, acceptWsAfterElems, acceptWsAfterTrm, acceptAnnotation),
        acceptWsAfterTrm ? acceptWsAfterTrm(PTPT_getATermWsAfterTrm(arg)) : PTPT_getATermWsAfterTrm(arg),
        acceptAnnotation ? acceptAnnotation(PTPT_getATermAnnotation(arg)) : PTPT_getATermAnnotation(arg));
  }
  ATabort("not a ATerm: %t\n", arg);
  return (PTPT_ATerm)NULL;
}

/*}}}  */
/*{{{  PTPT_Annotation PTPT_visitAnnotation(PTPT_Annotation arg, PTPT_OptLayout (*acceptWsAfterBraceOpen)(PTPT_OptLayout), PTPT_ATermAnnos (*acceptAnnos)(PTPT_ATermAnnos), PTPT_OptLayout (*acceptWsAfterAnnos)(PTPT_OptLayout)) */

PTPT_Annotation PTPT_visitAnnotation(PTPT_Annotation arg, PTPT_OptLayout (*acceptWsAfterBraceOpen)(PTPT_OptLayout), PTPT_ATermAnnos (*acceptAnnos)(PTPT_ATermAnnos), PTPT_OptLayout (*acceptWsAfterAnnos)(PTPT_OptLayout))
{
  if (PTPT_isAnnotationDefault(arg)) {
    return PTPT_makeAnnotationDefault(
        acceptWsAfterBraceOpen ? acceptWsAfterBraceOpen(PTPT_getAnnotationWsAfterBraceOpen(arg)) : PTPT_getAnnotationWsAfterBraceOpen(arg),
        acceptAnnos ? acceptAnnos(PTPT_getAnnotationAnnos(arg)) : PTPT_getAnnotationAnnos(arg),
        acceptWsAfterAnnos ? acceptWsAfterAnnos(PTPT_getAnnotationWsAfterAnnos(arg)) : PTPT_getAnnotationWsAfterAnnos(arg));
  }
  ATabort("not a Annotation: %t\n", arg);
  return (PTPT_Annotation)NULL;
}

/*}}}  */
/*{{{  PTPT_ATermArgs PTPT_visitATermArgs(PTPT_ATermArgs arg, PTPT_ATerm (*acceptHead)(PTPT_ATerm), PTPT_OptLayout (*acceptWsAfterHead)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterSep)(PTPT_OptLayout)) */

PTPT_ATermArgs PTPT_visitATermArgs(PTPT_ATermArgs arg, PTPT_ATerm (*acceptHead)(PTPT_ATerm), PTPT_OptLayout (*acceptWsAfterHead)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterSep)(PTPT_OptLayout))
{
  if (PTPT_isATermArgsEmpty(arg)) {
    return PTPT_makeATermArgsEmpty();
  }
  if (PTPT_isATermArgsSingle(arg)) {
    return PTPT_makeATermArgsSingle(
        acceptHead ? acceptHead(PTPT_getATermArgsHead(arg)) : PTPT_getATermArgsHead(arg));
  }
  if (PTPT_isATermArgsMany(arg)) {
    return PTPT_makeATermArgsMany(
        acceptHead ? acceptHead(PTPT_getATermArgsHead(arg)) : PTPT_getATermArgsHead(arg),
        acceptWsAfterHead ? acceptWsAfterHead(PTPT_getATermArgsWsAfterHead(arg)) : PTPT_getATermArgsWsAfterHead(arg),
        acceptWsAfterSep ? acceptWsAfterSep(PTPT_getATermArgsWsAfterSep(arg)) : PTPT_getATermArgsWsAfterSep(arg),
        PTPT_visitATermArgs(PTPT_getATermArgsTail(arg), acceptHead, acceptWsAfterHead, acceptWsAfterSep));
  }
  ATabort("not a ATermArgs: %t\n", arg);
  return (PTPT_ATermArgs)NULL;
}

/*}}}  */
/*{{{  PTPT_ATermElems PTPT_visitATermElems(PTPT_ATermElems arg, PTPT_ATerm (*acceptHead)(PTPT_ATerm), PTPT_OptLayout (*acceptWsAfterHead)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterSep)(PTPT_OptLayout)) */

PTPT_ATermElems PTPT_visitATermElems(PTPT_ATermElems arg, PTPT_ATerm (*acceptHead)(PTPT_ATerm), PTPT_OptLayout (*acceptWsAfterHead)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterSep)(PTPT_OptLayout))
{
  if (PTPT_isATermElemsEmpty(arg)) {
    return PTPT_makeATermElemsEmpty();
  }
  if (PTPT_isATermElemsSingle(arg)) {
    return PTPT_makeATermElemsSingle(
        acceptHead ? acceptHead(PTPT_getATermElemsHead(arg)) : PTPT_getATermElemsHead(arg));
  }
  if (PTPT_isATermElemsMany(arg)) {
    return PTPT_makeATermElemsMany(
        acceptHead ? acceptHead(PTPT_getATermElemsHead(arg)) : PTPT_getATermElemsHead(arg),
        acceptWsAfterHead ? acceptWsAfterHead(PTPT_getATermElemsWsAfterHead(arg)) : PTPT_getATermElemsWsAfterHead(arg),
        acceptWsAfterSep ? acceptWsAfterSep(PTPT_getATermElemsWsAfterSep(arg)) : PTPT_getATermElemsWsAfterSep(arg),
        PTPT_visitATermElems(PTPT_getATermElemsTail(arg), acceptHead, acceptWsAfterHead, acceptWsAfterSep));
  }
  ATabort("not a ATermElems: %t\n", arg);
  return (PTPT_ATermElems)NULL;
}

/*}}}  */
/*{{{  PTPT_ATermAnnos PTPT_visitATermAnnos(PTPT_ATermAnnos arg, PTPT_ATerm (*acceptHead)(PTPT_ATerm), PTPT_OptLayout (*acceptWsAfterHead)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterSep)(PTPT_OptLayout)) */

PTPT_ATermAnnos PTPT_visitATermAnnos(PTPT_ATermAnnos arg, PTPT_ATerm (*acceptHead)(PTPT_ATerm), PTPT_OptLayout (*acceptWsAfterHead)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterSep)(PTPT_OptLayout))
{
  if (PTPT_isATermAnnosEmpty(arg)) {
    return PTPT_makeATermAnnosEmpty();
  }
  if (PTPT_isATermAnnosSingle(arg)) {
    return PTPT_makeATermAnnosSingle(
        acceptHead ? acceptHead(PTPT_getATermAnnosHead(arg)) : PTPT_getATermAnnosHead(arg));
  }
  if (PTPT_isATermAnnosMany(arg)) {
    return PTPT_makeATermAnnosMany(
        acceptHead ? acceptHead(PTPT_getATermAnnosHead(arg)) : PTPT_getATermAnnosHead(arg),
        acceptWsAfterHead ? acceptWsAfterHead(PTPT_getATermAnnosWsAfterHead(arg)) : PTPT_getATermAnnosWsAfterHead(arg),
        acceptWsAfterSep ? acceptWsAfterSep(PTPT_getATermAnnosWsAfterSep(arg)) : PTPT_getATermAnnosWsAfterSep(arg),
        PTPT_visitATermAnnos(PTPT_getATermAnnosTail(arg), acceptHead, acceptWsAfterHead, acceptWsAfterSep));
  }
  ATabort("not a ATermAnnos: %t\n", arg);
  return (PTPT_ATermAnnos)NULL;
}

/*}}}  */
/*{{{  PTPT_IntCon PTPT_visitIntCon(PTPT_IntCon arg, PTPT_NatCon (*acceptNatCon)(PTPT_NatCon), PTPT_OptLayout (*acceptWsAfterPos)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterNeg)(PTPT_OptLayout)) */

PTPT_IntCon PTPT_visitIntCon(PTPT_IntCon arg, PTPT_NatCon (*acceptNatCon)(PTPT_NatCon), PTPT_OptLayout (*acceptWsAfterPos)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterNeg)(PTPT_OptLayout))
{
  if (PTPT_isIntConNatural(arg)) {
    return PTPT_makeIntConNatural(
        acceptNatCon ? acceptNatCon(PTPT_getIntConNatCon(arg)) : PTPT_getIntConNatCon(arg));
  }
  if (PTPT_isIntConPositive(arg)) {
    return PTPT_makeIntConPositive(
        acceptWsAfterPos ? acceptWsAfterPos(PTPT_getIntConWsAfterPos(arg)) : PTPT_getIntConWsAfterPos(arg),
        acceptNatCon ? acceptNatCon(PTPT_getIntConNatCon(arg)) : PTPT_getIntConNatCon(arg));
  }
  if (PTPT_isIntConNegative(arg)) {
    return PTPT_makeIntConNegative(
        acceptWsAfterNeg ? acceptWsAfterNeg(PTPT_getIntConWsAfterNeg(arg)) : PTPT_getIntConWsAfterNeg(arg),
        acceptNatCon ? acceptNatCon(PTPT_getIntConNatCon(arg)) : PTPT_getIntConNatCon(arg));
  }
  ATabort("not a IntCon: %t\n", arg);
  return (PTPT_IntCon)NULL;
}

/*}}}  */
/*{{{  PTPT_OptExp PTPT_visitOptExp(PTPT_OptExp arg, PTPT_OptLayout (*acceptWsAfterE)(PTPT_OptLayout), PTPT_IntCon (*acceptIntCon)(PTPT_IntCon)) */

PTPT_OptExp PTPT_visitOptExp(PTPT_OptExp arg, PTPT_OptLayout (*acceptWsAfterE)(PTPT_OptLayout), PTPT_IntCon (*acceptIntCon)(PTPT_IntCon))
{
  if (PTPT_isOptExpPresent(arg)) {
    return PTPT_makeOptExpPresent(
        acceptWsAfterE ? acceptWsAfterE(PTPT_getOptExpWsAfterE(arg)) : PTPT_getOptExpWsAfterE(arg),
        acceptIntCon ? acceptIntCon(PTPT_getOptExpIntCon(arg)) : PTPT_getOptExpIntCon(arg));
  }
  if (PTPT_isOptExpAbsent(arg)) {
    return PTPT_makeOptExpAbsent();
  }
  ATabort("not a OptExp: %t\n", arg);
  return (PTPT_OptExp)NULL;
}

/*}}}  */
/*{{{  PTPT_RealCon PTPT_visitRealCon(PTPT_RealCon arg, PTPT_IntCon (*acceptBase)(PTPT_IntCon), PTPT_OptLayout (*acceptWsAfterBase)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterPeriod)(PTPT_OptLayout), PTPT_NatCon (*acceptDecimal)(PTPT_NatCon), PTPT_OptLayout (*acceptWsAfterDecimal)(PTPT_OptLayout), PTPT_OptExp (*acceptExp)(PTPT_OptExp)) */

PTPT_RealCon PTPT_visitRealCon(PTPT_RealCon arg, PTPT_IntCon (*acceptBase)(PTPT_IntCon), PTPT_OptLayout (*acceptWsAfterBase)(PTPT_OptLayout), PTPT_OptLayout (*acceptWsAfterPeriod)(PTPT_OptLayout), PTPT_NatCon (*acceptDecimal)(PTPT_NatCon), PTPT_OptLayout (*acceptWsAfterDecimal)(PTPT_OptLayout), PTPT_OptExp (*acceptExp)(PTPT_OptExp))
{
  if (PTPT_isRealConRealCon(arg)) {
    return PTPT_makeRealConRealCon(
        acceptBase ? acceptBase(PTPT_getRealConBase(arg)) : PTPT_getRealConBase(arg),
        acceptWsAfterBase ? acceptWsAfterBase(PTPT_getRealConWsAfterBase(arg)) : PTPT_getRealConWsAfterBase(arg),
        acceptWsAfterPeriod ? acceptWsAfterPeriod(PTPT_getRealConWsAfterPeriod(arg)) : PTPT_getRealConWsAfterPeriod(arg),
        acceptDecimal ? acceptDecimal(PTPT_getRealConDecimal(arg)) : PTPT_getRealConDecimal(arg),
        acceptWsAfterDecimal ? acceptWsAfterDecimal(PTPT_getRealConWsAfterDecimal(arg)) : PTPT_getRealConWsAfterDecimal(arg),
        acceptExp ? acceptExp(PTPT_getRealConExp(arg)) : PTPT_getRealConExp(arg));
  }
  ATabort("not a RealCon: %t\n", arg);
  return (PTPT_RealCon)NULL;
}

/*}}}  */
/*{{{  PTPT_LexStrChar PTPT_visitLexStrChar(PTPT_LexStrChar arg, char (*acceptA)(char), char (*acceptB)(char), char (*acceptC)(char), char (*acceptCh)(char)) */

PTPT_LexStrChar PTPT_visitLexStrChar(PTPT_LexStrChar arg, char (*acceptA)(char), char (*acceptB)(char), char (*acceptC)(char), char (*acceptCh)(char))
{
  if (PTPT_isLexStrCharNewline(arg)) {
    return PTPT_makeLexStrCharNewline();
  }
  if (PTPT_isLexStrCharTab(arg)) {
    return PTPT_makeLexStrCharTab();
  }
  if (PTPT_isLexStrCharQuote(arg)) {
    return PTPT_makeLexStrCharQuote();
  }
  if (PTPT_isLexStrCharBackslash(arg)) {
    return PTPT_makeLexStrCharBackslash();
  }
  if (PTPT_isLexStrCharDecimal(arg)) {
    return PTPT_makeLexStrCharDecimal(
        acceptA ? acceptA(PTPT_getLexStrCharA(arg)) : PTPT_getLexStrCharA(arg),
        acceptB ? acceptB(PTPT_getLexStrCharB(arg)) : PTPT_getLexStrCharB(arg),
        acceptC ? acceptC(PTPT_getLexStrCharC(arg)) : PTPT_getLexStrCharC(arg));
  }
  if (PTPT_isLexStrCharNormal(arg)) {
    return PTPT_makeLexStrCharNormal(
        acceptCh ? acceptCh(PTPT_getLexStrCharCh(arg)) : PTPT_getLexStrCharCh(arg));
  }
  ATabort("not a LexStrChar: %t\n", arg);
  return (PTPT_LexStrChar)NULL;
}

/*}}}  */
/*{{{  PTPT_StrChar PTPT_visitStrChar(PTPT_StrChar arg, PTPT_LexStrChar (*acceptStrChar)(PTPT_LexStrChar)) */

PTPT_StrChar PTPT_visitStrChar(PTPT_StrChar arg, PTPT_LexStrChar (*acceptStrChar)(PTPT_LexStrChar))
{
  if (PTPT_isStrCharLexToCf(arg)) {
    return PTPT_makeStrCharLexToCf(
        acceptStrChar ? acceptStrChar(PTPT_getStrCharStrChar(arg)) : PTPT_getStrCharStrChar(arg));
  }
  ATabort("not a StrChar: %t\n", arg);
  return (PTPT_StrChar)NULL;
}

/*}}}  */
/*{{{  PTPT_LexStrCon PTPT_visitLexStrCon(PTPT_LexStrCon arg, PTPT_LexStrCharChars (*acceptChars)(PTPT_LexStrCharChars)) */

PTPT_LexStrCon PTPT_visitLexStrCon(PTPT_LexStrCon arg, PTPT_LexStrCharChars (*acceptChars)(PTPT_LexStrCharChars))
{
  if (PTPT_isLexStrConDefault(arg)) {
    return PTPT_makeLexStrConDefault(
        acceptChars ? acceptChars(PTPT_getLexStrConChars(arg)) : PTPT_getLexStrConChars(arg));
  }
  ATabort("not a LexStrCon: %t\n", arg);
  return (PTPT_LexStrCon)NULL;
}

/*}}}  */
/*{{{  PTPT_StrCon PTPT_visitStrCon(PTPT_StrCon arg, PTPT_LexStrCon (*acceptStrCon)(PTPT_LexStrCon)) */

PTPT_StrCon PTPT_visitStrCon(PTPT_StrCon arg, PTPT_LexStrCon (*acceptStrCon)(PTPT_LexStrCon))
{
  if (PTPT_isStrConLexToCf(arg)) {
    return PTPT_makeStrConLexToCf(
        acceptStrCon ? acceptStrCon(PTPT_getStrConStrCon(arg)) : PTPT_getStrConStrCon(arg));
  }
  ATabort("not a StrCon: %t\n", arg);
  return (PTPT_StrCon)NULL;
}

/*}}}  */
/*{{{  PTPT_LexStrCharChars PTPT_visitLexStrCharChars(PTPT_LexStrCharChars arg, PTPT_LexStrChar (*acceptHead)(PTPT_LexStrChar)) */

PTPT_LexStrCharChars PTPT_visitLexStrCharChars(PTPT_LexStrCharChars arg, PTPT_LexStrChar (*acceptHead)(PTPT_LexStrChar))
{
  if (PTPT_isLexStrCharCharsEmpty(arg)) {
    return PTPT_makeLexStrCharCharsEmpty();
  }
  if (PTPT_isLexStrCharCharsSingle(arg)) {
    return PTPT_makeLexStrCharCharsSingle(
        acceptHead ? acceptHead(PTPT_getLexStrCharCharsHead(arg)) : PTPT_getLexStrCharCharsHead(arg));
  }
  if (PTPT_isLexStrCharCharsMany(arg)) {
    return PTPT_makeLexStrCharCharsMany(
        acceptHead ? acceptHead(PTPT_getLexStrCharCharsHead(arg)) : PTPT_getLexStrCharCharsHead(arg),
        PTPT_visitLexStrCharChars(PTPT_getLexStrCharCharsTail(arg), acceptHead));
  }
  ATabort("not a LexStrCharChars: %t\n", arg);
  return (PTPT_LexStrCharChars)NULL;
}

/*}}}  */
/*{{{  PTPT_LexNatCon PTPT_visitLexNatCon(PTPT_LexNatCon arg, char* (*acceptList)(char*)) */

PTPT_LexNatCon PTPT_visitLexNatCon(PTPT_LexNatCon arg, char* (*acceptList)(char*))
{
  if (PTPT_isLexNatConDigits(arg)) {
    return PTPT_makeLexNatConDigits(
        acceptList ? acceptList(PTPT_getLexNatConList(arg)) : PTPT_getLexNatConList(arg));
  }
  ATabort("not a LexNatCon: %t\n", arg);
  return (PTPT_LexNatCon)NULL;
}

/*}}}  */
/*{{{  PTPT_NatCon PTPT_visitNatCon(PTPT_NatCon arg, PTPT_LexNatCon (*acceptNatCon)(PTPT_LexNatCon)) */

PTPT_NatCon PTPT_visitNatCon(PTPT_NatCon arg, PTPT_LexNatCon (*acceptNatCon)(PTPT_LexNatCon))
{
  if (PTPT_isNatConLexToCf(arg)) {
    return PTPT_makeNatConLexToCf(
        acceptNatCon ? acceptNatCon(PTPT_getNatConNatCon(arg)) : PTPT_getNatConNatCon(arg));
  }
  ATabort("not a NatCon: %t\n", arg);
  return (PTPT_NatCon)NULL;
}

/*}}}  */
/*{{{  PTPT_LexIdCon PTPT_visitLexIdCon(PTPT_LexIdCon arg, char (*acceptHead)(char), char* (*acceptTail)(char*)) */

PTPT_LexIdCon PTPT_visitLexIdCon(PTPT_LexIdCon arg, char (*acceptHead)(char), char* (*acceptTail)(char*))
{
  if (PTPT_isLexIdConDefault(arg)) {
    return PTPT_makeLexIdConDefault(
        acceptHead ? acceptHead(PTPT_getLexIdConHead(arg)) : PTPT_getLexIdConHead(arg),
        acceptTail ? acceptTail(PTPT_getLexIdConTail(arg)) : PTPT_getLexIdConTail(arg));
  }
  ATabort("not a LexIdCon: %t\n", arg);
  return (PTPT_LexIdCon)NULL;
}

/*}}}  */
/*{{{  PTPT_IdCon PTPT_visitIdCon(PTPT_IdCon arg, PTPT_LexIdCon (*acceptIdCon)(PTPT_LexIdCon)) */

PTPT_IdCon PTPT_visitIdCon(PTPT_IdCon arg, PTPT_LexIdCon (*acceptIdCon)(PTPT_LexIdCon))
{
  if (PTPT_isIdConLexToCf(arg)) {
    return PTPT_makeIdConLexToCf(
        acceptIdCon ? acceptIdCon(PTPT_getIdConIdCon(arg)) : PTPT_getIdConIdCon(arg));
  }
  ATabort("not a IdCon: %t\n", arg);
  return (PTPT_IdCon)NULL;
}

/*}}}  */
/*{{{  PTPT_LexLayout PTPT_visitLexLayout(PTPT_LexLayout arg, char (*acceptCh)(char)) */

PTPT_LexLayout PTPT_visitLexLayout(PTPT_LexLayout arg, char (*acceptCh)(char))
{
  if (PTPT_isLexLayoutWhitespace(arg)) {
    return PTPT_makeLexLayoutWhitespace(
        acceptCh ? acceptCh(PTPT_getLexLayoutCh(arg)) : PTPT_getLexLayoutCh(arg));
  }
  ATabort("not a LexLayout: %t\n", arg);
  return (PTPT_LexLayout)NULL;
}

/*}}}  */

/*}}}  */
