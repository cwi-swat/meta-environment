#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "Box.h"

/*{{{  conversion functions */

ATerm BOX_stringToChars(const char *str)
{
  int len = strlen(str);
  int i;
  ATermList result = ATempty;

  for (i = len - 1; i >= 0; i--) {
    result = ATinsert(result, (ATerm) ATmakeInt(str[i]));
  }

  return (ATerm) result;
}

ATerm BOX_byteToChar(char ch)
{
    return (ATerm) ATmakeInt(ch);
}

char *BOX_charsToString(ATerm arg)
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

char BOX_charToByte(ATerm arg)
{
    return (char) ATgetInt((ATermInt) arg);
}


/*}}}  */

/*{{{  typedefs */

typedef struct ATerm _BOX_OptLayout;
typedef struct ATerm _BOX_Layout;
typedef struct ATerm _BOX_LexLayoutList;
typedef struct ATerm _BOX_LexFontId;
typedef struct ATerm _BOX_FontId;
typedef struct ATerm _BOX_FontValue;
typedef struct ATerm _BOX_FontOption;
typedef struct ATerm _BOX_FontOperator;
typedef struct ATerm _BOX_Box;
typedef struct ATerm _BOX_FontParam;
typedef struct ATerm _BOX_FontOptionList;
typedef struct ATerm _BOX_BoxList;
typedef struct ATerm _BOX_LexNatCon;
typedef struct ATerm _BOX_NatCon;
typedef struct ATerm _BOX_LexStrChar;
typedef struct ATerm _BOX_StrChar;
typedef struct ATerm _BOX_LexStrCon;
typedef struct ATerm _BOX_StrCon;
typedef struct ATerm _BOX_LexStrCharChars;
typedef struct ATerm _BOX_LexLayout;
typedef struct ATerm _BOX_SpaceSymbol;
typedef struct ATerm _BOX_SpaceOption;
typedef struct ATerm _BOX_SpaceOptionOptions;
typedef struct ATerm _BOX_AlignmentOption;
typedef struct ATerm _BOX_AlignmentOptions;
typedef struct ATerm _BOX_AlignmentOptionList;
typedef struct ATerm _BOX_Start;

/*}}}  */

/*{{{  void BOX_initBoxApi(void) */

void BOX_initBoxApi(void)
{
  init_Box_dict();
}

/*}}}  */

/*{{{  protect functions */

void BOX_protectOptLayout(BOX_OptLayout *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void BOX_protectLayout(BOX_Layout *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void BOX_protectLexLayoutList(BOX_LexLayoutList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void BOX_protectLexFontId(BOX_LexFontId *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void BOX_protectFontId(BOX_FontId *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void BOX_protectFontValue(BOX_FontValue *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void BOX_protectFontOption(BOX_FontOption *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void BOX_protectFontOperator(BOX_FontOperator *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void BOX_protectBox(BOX_Box *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void BOX_protectFontParam(BOX_FontParam *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void BOX_protectFontOptionList(BOX_FontOptionList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void BOX_protectBoxList(BOX_BoxList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void BOX_protectLexNatCon(BOX_LexNatCon *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void BOX_protectNatCon(BOX_NatCon *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void BOX_protectLexStrChar(BOX_LexStrChar *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void BOX_protectStrChar(BOX_StrChar *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void BOX_protectLexStrCon(BOX_LexStrCon *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void BOX_protectStrCon(BOX_StrCon *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void BOX_protectLexStrCharChars(BOX_LexStrCharChars *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void BOX_protectLexLayout(BOX_LexLayout *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void BOX_protectSpaceSymbol(BOX_SpaceSymbol *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void BOX_protectSpaceOption(BOX_SpaceOption *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void BOX_protectSpaceOptionOptions(BOX_SpaceOptionOptions *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void BOX_protectAlignmentOption(BOX_AlignmentOption *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void BOX_protectAlignmentOptions(BOX_AlignmentOptions *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void BOX_protectAlignmentOptionList(BOX_AlignmentOptionList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void BOX_protectStart(BOX_Start *arg)
{
  ATprotect((ATerm*)((void*) arg));
}


/*}}}  */
/*{{{  term conversion functions */

/*{{{  BOX_OptLayout BOX_OptLayoutFromTerm(ATerm t) */

BOX_OptLayout BOX_OptLayoutFromTerm(ATerm t)
{
  return (BOX_OptLayout)t;
}

/*}}}  */
/*{{{  ATerm BOX_OptLayoutToTerm(BOX_OptLayout arg) */

ATerm BOX_OptLayoutToTerm(BOX_OptLayout arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  BOX_Layout BOX_LayoutFromTerm(ATerm t) */

BOX_Layout BOX_LayoutFromTerm(ATerm t)
{
  return (BOX_Layout)t;
}

/*}}}  */
/*{{{  ATerm BOX_LayoutToTerm(BOX_Layout arg) */

ATerm BOX_LayoutToTerm(BOX_Layout arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  BOX_LexLayoutList BOX_LexLayoutListFromTerm(ATerm t) */

BOX_LexLayoutList BOX_LexLayoutListFromTerm(ATerm t)
{
  return (BOX_LexLayoutList)t;
}

/*}}}  */
/*{{{  ATerm BOX_LexLayoutListToTerm(BOX_LexLayoutList arg) */

ATerm BOX_LexLayoutListToTerm(BOX_LexLayoutList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  BOX_LexFontId BOX_LexFontIdFromTerm(ATerm t) */

BOX_LexFontId BOX_LexFontIdFromTerm(ATerm t)
{
  return (BOX_LexFontId)t;
}

/*}}}  */
/*{{{  ATerm BOX_LexFontIdToTerm(BOX_LexFontId arg) */

ATerm BOX_LexFontIdToTerm(BOX_LexFontId arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  BOX_FontId BOX_FontIdFromTerm(ATerm t) */

BOX_FontId BOX_FontIdFromTerm(ATerm t)
{
  return (BOX_FontId)t;
}

/*}}}  */
/*{{{  ATerm BOX_FontIdToTerm(BOX_FontId arg) */

ATerm BOX_FontIdToTerm(BOX_FontId arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  BOX_FontValue BOX_FontValueFromTerm(ATerm t) */

BOX_FontValue BOX_FontValueFromTerm(ATerm t)
{
  return (BOX_FontValue)t;
}

/*}}}  */
/*{{{  ATerm BOX_FontValueToTerm(BOX_FontValue arg) */

ATerm BOX_FontValueToTerm(BOX_FontValue arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  BOX_FontOption BOX_FontOptionFromTerm(ATerm t) */

BOX_FontOption BOX_FontOptionFromTerm(ATerm t)
{
  return (BOX_FontOption)t;
}

/*}}}  */
/*{{{  ATerm BOX_FontOptionToTerm(BOX_FontOption arg) */

ATerm BOX_FontOptionToTerm(BOX_FontOption arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  BOX_FontOperator BOX_FontOperatorFromTerm(ATerm t) */

BOX_FontOperator BOX_FontOperatorFromTerm(ATerm t)
{
  return (BOX_FontOperator)t;
}

/*}}}  */
/*{{{  ATerm BOX_FontOperatorToTerm(BOX_FontOperator arg) */

ATerm BOX_FontOperatorToTerm(BOX_FontOperator arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  BOX_Box BOX_BoxFromTerm(ATerm t) */

BOX_Box BOX_BoxFromTerm(ATerm t)
{
  return (BOX_Box)t;
}

/*}}}  */
/*{{{  ATerm BOX_BoxToTerm(BOX_Box arg) */

ATerm BOX_BoxToTerm(BOX_Box arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  BOX_FontParam BOX_FontParamFromTerm(ATerm t) */

BOX_FontParam BOX_FontParamFromTerm(ATerm t)
{
  return (BOX_FontParam)t;
}

/*}}}  */
/*{{{  ATerm BOX_FontParamToTerm(BOX_FontParam arg) */

ATerm BOX_FontParamToTerm(BOX_FontParam arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  BOX_FontOptionList BOX_FontOptionListFromTerm(ATerm t) */

BOX_FontOptionList BOX_FontOptionListFromTerm(ATerm t)
{
  return (BOX_FontOptionList)t;
}

/*}}}  */
/*{{{  ATerm BOX_FontOptionListToTerm(BOX_FontOptionList arg) */

ATerm BOX_FontOptionListToTerm(BOX_FontOptionList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  BOX_BoxList BOX_BoxListFromTerm(ATerm t) */

BOX_BoxList BOX_BoxListFromTerm(ATerm t)
{
  return (BOX_BoxList)t;
}

/*}}}  */
/*{{{  ATerm BOX_BoxListToTerm(BOX_BoxList arg) */

ATerm BOX_BoxListToTerm(BOX_BoxList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  BOX_LexNatCon BOX_LexNatConFromTerm(ATerm t) */

BOX_LexNatCon BOX_LexNatConFromTerm(ATerm t)
{
  return (BOX_LexNatCon)t;
}

/*}}}  */
/*{{{  ATerm BOX_LexNatConToTerm(BOX_LexNatCon arg) */

ATerm BOX_LexNatConToTerm(BOX_LexNatCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  BOX_NatCon BOX_NatConFromTerm(ATerm t) */

BOX_NatCon BOX_NatConFromTerm(ATerm t)
{
  return (BOX_NatCon)t;
}

/*}}}  */
/*{{{  ATerm BOX_NatConToTerm(BOX_NatCon arg) */

ATerm BOX_NatConToTerm(BOX_NatCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  BOX_LexStrChar BOX_LexStrCharFromTerm(ATerm t) */

BOX_LexStrChar BOX_LexStrCharFromTerm(ATerm t)
{
  return (BOX_LexStrChar)t;
}

/*}}}  */
/*{{{  ATerm BOX_LexStrCharToTerm(BOX_LexStrChar arg) */

ATerm BOX_LexStrCharToTerm(BOX_LexStrChar arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  BOX_StrChar BOX_StrCharFromTerm(ATerm t) */

BOX_StrChar BOX_StrCharFromTerm(ATerm t)
{
  return (BOX_StrChar)t;
}

/*}}}  */
/*{{{  ATerm BOX_StrCharToTerm(BOX_StrChar arg) */

ATerm BOX_StrCharToTerm(BOX_StrChar arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  BOX_LexStrCon BOX_LexStrConFromTerm(ATerm t) */

BOX_LexStrCon BOX_LexStrConFromTerm(ATerm t)
{
  return (BOX_LexStrCon)t;
}

/*}}}  */
/*{{{  ATerm BOX_LexStrConToTerm(BOX_LexStrCon arg) */

ATerm BOX_LexStrConToTerm(BOX_LexStrCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  BOX_StrCon BOX_StrConFromTerm(ATerm t) */

BOX_StrCon BOX_StrConFromTerm(ATerm t)
{
  return (BOX_StrCon)t;
}

/*}}}  */
/*{{{  ATerm BOX_StrConToTerm(BOX_StrCon arg) */

ATerm BOX_StrConToTerm(BOX_StrCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  BOX_LexStrCharChars BOX_LexStrCharCharsFromTerm(ATerm t) */

BOX_LexStrCharChars BOX_LexStrCharCharsFromTerm(ATerm t)
{
  return (BOX_LexStrCharChars)t;
}

/*}}}  */
/*{{{  ATerm BOX_LexStrCharCharsToTerm(BOX_LexStrCharChars arg) */

ATerm BOX_LexStrCharCharsToTerm(BOX_LexStrCharChars arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  BOX_LexLayout BOX_LexLayoutFromTerm(ATerm t) */

BOX_LexLayout BOX_LexLayoutFromTerm(ATerm t)
{
  return (BOX_LexLayout)t;
}

/*}}}  */
/*{{{  ATerm BOX_LexLayoutToTerm(BOX_LexLayout arg) */

ATerm BOX_LexLayoutToTerm(BOX_LexLayout arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  BOX_SpaceSymbol BOX_SpaceSymbolFromTerm(ATerm t) */

BOX_SpaceSymbol BOX_SpaceSymbolFromTerm(ATerm t)
{
  return (BOX_SpaceSymbol)t;
}

/*}}}  */
/*{{{  ATerm BOX_SpaceSymbolToTerm(BOX_SpaceSymbol arg) */

ATerm BOX_SpaceSymbolToTerm(BOX_SpaceSymbol arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  BOX_SpaceOption BOX_SpaceOptionFromTerm(ATerm t) */

BOX_SpaceOption BOX_SpaceOptionFromTerm(ATerm t)
{
  return (BOX_SpaceOption)t;
}

/*}}}  */
/*{{{  ATerm BOX_SpaceOptionToTerm(BOX_SpaceOption arg) */

ATerm BOX_SpaceOptionToTerm(BOX_SpaceOption arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  BOX_SpaceOptionOptions BOX_SpaceOptionOptionsFromTerm(ATerm t) */

BOX_SpaceOptionOptions BOX_SpaceOptionOptionsFromTerm(ATerm t)
{
  return (BOX_SpaceOptionOptions)t;
}

/*}}}  */
/*{{{  ATerm BOX_SpaceOptionOptionsToTerm(BOX_SpaceOptionOptions arg) */

ATerm BOX_SpaceOptionOptionsToTerm(BOX_SpaceOptionOptions arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  BOX_AlignmentOption BOX_AlignmentOptionFromTerm(ATerm t) */

BOX_AlignmentOption BOX_AlignmentOptionFromTerm(ATerm t)
{
  return (BOX_AlignmentOption)t;
}

/*}}}  */
/*{{{  ATerm BOX_AlignmentOptionToTerm(BOX_AlignmentOption arg) */

ATerm BOX_AlignmentOptionToTerm(BOX_AlignmentOption arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  BOX_AlignmentOptions BOX_AlignmentOptionsFromTerm(ATerm t) */

BOX_AlignmentOptions BOX_AlignmentOptionsFromTerm(ATerm t)
{
  return (BOX_AlignmentOptions)t;
}

/*}}}  */
/*{{{  ATerm BOX_AlignmentOptionsToTerm(BOX_AlignmentOptions arg) */

ATerm BOX_AlignmentOptionsToTerm(BOX_AlignmentOptions arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  BOX_AlignmentOptionList BOX_AlignmentOptionListFromTerm(ATerm t) */

BOX_AlignmentOptionList BOX_AlignmentOptionListFromTerm(ATerm t)
{
  return (BOX_AlignmentOptionList)t;
}

/*}}}  */
/*{{{  ATerm BOX_AlignmentOptionListToTerm(BOX_AlignmentOptionList arg) */

ATerm BOX_AlignmentOptionListToTerm(BOX_AlignmentOptionList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  BOX_Start BOX_StartFromTerm(ATerm t) */

BOX_Start BOX_StartFromTerm(ATerm t)
{
  return (BOX_Start)t;
}

/*}}}  */
/*{{{  ATerm BOX_StartToTerm(BOX_Start arg) */

ATerm BOX_StartToTerm(BOX_Start arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*}}}  */
/*{{{  list functions */

int BOX_getLexLayoutListLength (BOX_LexLayoutList arg) {
  return ATgetLength((ATermList) arg);
}
BOX_LexLayoutList BOX_reverseLexLayoutList(BOX_LexLayoutList arg) {
  return (BOX_LexLayoutList) ATreverse((ATermList) arg);
}
BOX_LexLayoutList BOX_appendLexLayoutList(BOX_LexLayoutList arg, BOX_LexLayout elem) {
  return (BOX_LexLayoutList) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}
BOX_LexLayoutList BOX_concatLexLayoutList(BOX_LexLayoutList arg0, BOX_LexLayoutList arg1) {
  return (BOX_LexLayoutList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
BOX_LexLayoutList BOX_sliceLexLayoutList(BOX_LexLayoutList arg, int start, int end) {
  return (BOX_LexLayoutList) ATgetSlice((ATermList) arg, start, end);
}
BOX_LexLayout BOX_getLexLayoutListLexLayoutAt(BOX_LexLayoutList arg, int index) {
 return (BOX_LexLayout)ATelementAt((ATermList) arg,index);
}
BOX_LexLayoutList BOX_replaceLexLayoutListLexLayoutAt(BOX_LexLayoutList arg, BOX_LexLayout elem, int index) {
 return (BOX_LexLayoutList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}
BOX_LexLayoutList BOX_makeLexLayoutList2(BOX_LexLayout elem1, BOX_LexLayout elem2) {
  return (BOX_LexLayoutList) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}
BOX_LexLayoutList BOX_makeLexLayoutList3(BOX_LexLayout elem1, BOX_LexLayout elem2, BOX_LexLayout elem3) {
  return (BOX_LexLayoutList) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}
BOX_LexLayoutList BOX_makeLexLayoutList4(BOX_LexLayout elem1, BOX_LexLayout elem2, BOX_LexLayout elem3, BOX_LexLayout elem4) {
  return (BOX_LexLayoutList) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}
BOX_LexLayoutList BOX_makeLexLayoutList5(BOX_LexLayout elem1, BOX_LexLayout elem2, BOX_LexLayout elem3, BOX_LexLayout elem4, BOX_LexLayout elem5) {
  return (BOX_LexLayoutList) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}
BOX_LexLayoutList BOX_makeLexLayoutList6(BOX_LexLayout elem1, BOX_LexLayout elem2, BOX_LexLayout elem3, BOX_LexLayout elem4, BOX_LexLayout elem5, BOX_LexLayout elem6) {
  return (BOX_LexLayoutList) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}
int BOX_getFontOptionListLength (BOX_FontOptionList arg) {
  if (ATisEmpty((ATermList) arg)) {
    return 0;
  }
  return (ATgetLength((ATermList) arg) / 2) + 1;
}
BOX_FontOptionList BOX_reverseFontOptionList(BOX_FontOptionList arg) {
  ATermList list = (ATermList) arg;
  ATerm head;
  ATerm sep0;
  ATermList result;

 if (ATisEmpty(list) || ATgetLength(list) == 1) {
    return arg;
  }

  result = ATmakeList1(ATgetFirst(list));
      list = ATgetNext(list);
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);

  while (!ATisEmpty(list)) {
    result = ATinsert(result, sep0);

   head = ATgetFirst(list);
   result = ATinsert(result, head);
    list = ATgetNext(list);

   if (!ATisEmpty(list)) {
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
   }
  }

  return (BOX_FontOptionList) result;
}
BOX_FontOptionList BOX_appendFontOptionList(BOX_FontOptionList arg0, BOX_OptLayout wsAfterHead, BOX_FontOption arg1) {
  return BOX_concatFontOptionList(arg0, wsAfterHead, BOX_makeFontOptionListSingle(arg1));
}
BOX_FontOptionList BOX_concatFontOptionList(BOX_FontOptionList arg0, BOX_OptLayout wsAfterHead, BOX_FontOptionList arg1) {
  if (ATisEmpty((ATermList) arg0)) {
    return arg1;
  }
  arg1 = BOX_makeFontOptionListMany((BOX_FontOption)ATgetFirst((ATermList) arg0), wsAfterHead,  arg1);
  arg1 = (BOX_FontOptionList) ATgetNext((ATermList) arg1);
  return (BOX_FontOptionList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
BOX_FontOptionList BOX_sliceFontOptionList(BOX_FontOptionList arg, int start, int end) {
  return (BOX_FontOptionList) ATgetSlice((ATermList) arg, start * 2, end * 2);
}
BOX_FontOption BOX_getFontOptionListFontOptionAt(BOX_FontOptionList arg, int index) {
 return (BOX_FontOption)ATelementAt((ATermList) arg,index * 2);
}
BOX_FontOptionList BOX_replaceFontOptionListFontOptionAt(BOX_FontOptionList arg, BOX_FontOption elem, int index) {
 return (BOX_FontOptionList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index * 2);
}
BOX_FontOptionList BOX_makeFontOptionList2(BOX_OptLayout wsAfterHead, BOX_FontOption elem1, BOX_FontOption elem2) {
  return BOX_makeFontOptionListMany(elem1, wsAfterHead, BOX_makeFontOptionListSingle(elem2));
}
BOX_FontOptionList BOX_makeFontOptionList3(BOX_OptLayout wsAfterHead, BOX_FontOption elem1, BOX_FontOption elem2, BOX_FontOption elem3) {
  return BOX_makeFontOptionListMany(elem1, wsAfterHead, BOX_makeFontOptionList2(wsAfterHead, elem2, elem3));
}
BOX_FontOptionList BOX_makeFontOptionList4(BOX_OptLayout wsAfterHead, BOX_FontOption elem1, BOX_FontOption elem2, BOX_FontOption elem3, BOX_FontOption elem4) {
  return BOX_makeFontOptionListMany(elem1, wsAfterHead, BOX_makeFontOptionList3(wsAfterHead, elem2, elem3, elem4));
}
BOX_FontOptionList BOX_makeFontOptionList5(BOX_OptLayout wsAfterHead, BOX_FontOption elem1, BOX_FontOption elem2, BOX_FontOption elem3, BOX_FontOption elem4, BOX_FontOption elem5) {
  return BOX_makeFontOptionListMany(elem1, wsAfterHead, BOX_makeFontOptionList4(wsAfterHead, elem2, elem3, elem4, elem5));
}
BOX_FontOptionList BOX_makeFontOptionList6(BOX_OptLayout wsAfterHead, BOX_FontOption elem1, BOX_FontOption elem2, BOX_FontOption elem3, BOX_FontOption elem4, BOX_FontOption elem5, BOX_FontOption elem6) {
  return BOX_makeFontOptionListMany(elem1, wsAfterHead, BOX_makeFontOptionList5(wsAfterHead, elem2, elem3, elem4, elem5, elem6));
}
int BOX_getBoxListLength (BOX_BoxList arg) {
  if (ATisEmpty((ATermList) arg)) {
    return 0;
  }
  return (ATgetLength((ATermList) arg) / 2) + 1;
}
BOX_BoxList BOX_reverseBoxList(BOX_BoxList arg) {
  ATermList list = (ATermList) arg;
  ATerm head;
  ATerm sep0;
  ATermList result;

 if (ATisEmpty(list) || ATgetLength(list) == 1) {
    return arg;
  }

  result = ATmakeList1(ATgetFirst(list));
      list = ATgetNext(list);
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);

  while (!ATisEmpty(list)) {
    result = ATinsert(result, sep0);

   head = ATgetFirst(list);
   result = ATinsert(result, head);
    list = ATgetNext(list);

   if (!ATisEmpty(list)) {
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
   }
  }

  return (BOX_BoxList) result;
}
BOX_BoxList BOX_appendBoxList(BOX_BoxList arg0, BOX_OptLayout wsAfterHead, BOX_Box arg1) {
  return BOX_concatBoxList(arg0, wsAfterHead, BOX_makeBoxListSingle(arg1));
}
BOX_BoxList BOX_concatBoxList(BOX_BoxList arg0, BOX_OptLayout wsAfterHead, BOX_BoxList arg1) {
  if (ATisEmpty((ATermList) arg0)) {
    return arg1;
  }
  arg1 = BOX_makeBoxListMany((BOX_Box)ATgetFirst((ATermList) arg0), wsAfterHead,  arg1);
  arg1 = (BOX_BoxList) ATgetNext((ATermList) arg1);
  return (BOX_BoxList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
BOX_BoxList BOX_sliceBoxList(BOX_BoxList arg, int start, int end) {
  return (BOX_BoxList) ATgetSlice((ATermList) arg, start * 2, end * 2);
}
BOX_Box BOX_getBoxListBoxAt(BOX_BoxList arg, int index) {
 return (BOX_Box)ATelementAt((ATermList) arg,index * 2);
}
BOX_BoxList BOX_replaceBoxListBoxAt(BOX_BoxList arg, BOX_Box elem, int index) {
 return (BOX_BoxList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index * 2);
}
BOX_BoxList BOX_makeBoxList2(BOX_OptLayout wsAfterHead, BOX_Box elem1, BOX_Box elem2) {
  return BOX_makeBoxListMany(elem1, wsAfterHead, BOX_makeBoxListSingle(elem2));
}
BOX_BoxList BOX_makeBoxList3(BOX_OptLayout wsAfterHead, BOX_Box elem1, BOX_Box elem2, BOX_Box elem3) {
  return BOX_makeBoxListMany(elem1, wsAfterHead, BOX_makeBoxList2(wsAfterHead, elem2, elem3));
}
BOX_BoxList BOX_makeBoxList4(BOX_OptLayout wsAfterHead, BOX_Box elem1, BOX_Box elem2, BOX_Box elem3, BOX_Box elem4) {
  return BOX_makeBoxListMany(elem1, wsAfterHead, BOX_makeBoxList3(wsAfterHead, elem2, elem3, elem4));
}
BOX_BoxList BOX_makeBoxList5(BOX_OptLayout wsAfterHead, BOX_Box elem1, BOX_Box elem2, BOX_Box elem3, BOX_Box elem4, BOX_Box elem5) {
  return BOX_makeBoxListMany(elem1, wsAfterHead, BOX_makeBoxList4(wsAfterHead, elem2, elem3, elem4, elem5));
}
BOX_BoxList BOX_makeBoxList6(BOX_OptLayout wsAfterHead, BOX_Box elem1, BOX_Box elem2, BOX_Box elem3, BOX_Box elem4, BOX_Box elem5, BOX_Box elem6) {
  return BOX_makeBoxListMany(elem1, wsAfterHead, BOX_makeBoxList5(wsAfterHead, elem2, elem3, elem4, elem5, elem6));
}
int BOX_getLexStrCharCharsLength (BOX_LexStrCharChars arg) {
  return ATgetLength((ATermList) arg);
}
BOX_LexStrCharChars BOX_reverseLexStrCharChars(BOX_LexStrCharChars arg) {
  return (BOX_LexStrCharChars) ATreverse((ATermList) arg);
}
BOX_LexStrCharChars BOX_appendLexStrCharChars(BOX_LexStrCharChars arg, BOX_LexStrChar elem) {
  return (BOX_LexStrCharChars) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}
BOX_LexStrCharChars BOX_concatLexStrCharChars(BOX_LexStrCharChars arg0, BOX_LexStrCharChars arg1) {
  return (BOX_LexStrCharChars) ATconcat((ATermList) arg0, (ATermList) arg1);
}
BOX_LexStrCharChars BOX_sliceLexStrCharChars(BOX_LexStrCharChars arg, int start, int end) {
  return (BOX_LexStrCharChars) ATgetSlice((ATermList) arg, start, end);
}
BOX_LexStrChar BOX_getLexStrCharCharsLexStrCharAt(BOX_LexStrCharChars arg, int index) {
 return (BOX_LexStrChar)ATelementAt((ATermList) arg,index);
}
BOX_LexStrCharChars BOX_replaceLexStrCharCharsLexStrCharAt(BOX_LexStrCharChars arg, BOX_LexStrChar elem, int index) {
 return (BOX_LexStrCharChars) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}
BOX_LexStrCharChars BOX_makeLexStrCharChars2(BOX_LexStrChar elem1, BOX_LexStrChar elem2) {
  return (BOX_LexStrCharChars) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}
BOX_LexStrCharChars BOX_makeLexStrCharChars3(BOX_LexStrChar elem1, BOX_LexStrChar elem2, BOX_LexStrChar elem3) {
  return (BOX_LexStrCharChars) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}
BOX_LexStrCharChars BOX_makeLexStrCharChars4(BOX_LexStrChar elem1, BOX_LexStrChar elem2, BOX_LexStrChar elem3, BOX_LexStrChar elem4) {
  return (BOX_LexStrCharChars) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}
BOX_LexStrCharChars BOX_makeLexStrCharChars5(BOX_LexStrChar elem1, BOX_LexStrChar elem2, BOX_LexStrChar elem3, BOX_LexStrChar elem4, BOX_LexStrChar elem5) {
  return (BOX_LexStrCharChars) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}
BOX_LexStrCharChars BOX_makeLexStrCharChars6(BOX_LexStrChar elem1, BOX_LexStrChar elem2, BOX_LexStrChar elem3, BOX_LexStrChar elem4, BOX_LexStrChar elem5, BOX_LexStrChar elem6) {
  return (BOX_LexStrCharChars) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}
int BOX_getSpaceOptionOptionsLength (BOX_SpaceOptionOptions arg) {
  if (ATisEmpty((ATermList) arg)) {
    return 0;
  }
  return (ATgetLength((ATermList) arg) / 2) + 1;
}
BOX_SpaceOptionOptions BOX_reverseSpaceOptionOptions(BOX_SpaceOptionOptions arg) {
  ATermList list = (ATermList) arg;
  ATerm head;
  ATerm sep0;
  ATermList result;

 if (ATisEmpty(list) || ATgetLength(list) == 1) {
    return arg;
  }

  result = ATmakeList1(ATgetFirst(list));
      list = ATgetNext(list);
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);

  while (!ATisEmpty(list)) {
    result = ATinsert(result, sep0);

   head = ATgetFirst(list);
   result = ATinsert(result, head);
    list = ATgetNext(list);

   if (!ATisEmpty(list)) {
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
   }
  }

  return (BOX_SpaceOptionOptions) result;
}
BOX_SpaceOptionOptions BOX_appendSpaceOptionOptions(BOX_SpaceOptionOptions arg0, BOX_OptLayout wsAfterHead, BOX_SpaceOption arg1) {
  return BOX_concatSpaceOptionOptions(arg0, wsAfterHead, BOX_makeSpaceOptionOptionsSingle(arg1));
}
BOX_SpaceOptionOptions BOX_concatSpaceOptionOptions(BOX_SpaceOptionOptions arg0, BOX_OptLayout wsAfterHead, BOX_SpaceOptionOptions arg1) {
  if (ATisEmpty((ATermList) arg0)) {
    return arg1;
  }
  arg1 = BOX_makeSpaceOptionOptionsMany((BOX_SpaceOption)ATgetFirst((ATermList) arg0), wsAfterHead,  arg1);
  arg1 = (BOX_SpaceOptionOptions) ATgetNext((ATermList) arg1);
  return (BOX_SpaceOptionOptions) ATconcat((ATermList) arg0, (ATermList) arg1);
}
BOX_SpaceOptionOptions BOX_sliceSpaceOptionOptions(BOX_SpaceOptionOptions arg, int start, int end) {
  return (BOX_SpaceOptionOptions) ATgetSlice((ATermList) arg, start * 2, end * 2);
}
BOX_SpaceOption BOX_getSpaceOptionOptionsSpaceOptionAt(BOX_SpaceOptionOptions arg, int index) {
 return (BOX_SpaceOption)ATelementAt((ATermList) arg,index * 2);
}
BOX_SpaceOptionOptions BOX_replaceSpaceOptionOptionsSpaceOptionAt(BOX_SpaceOptionOptions arg, BOX_SpaceOption elem, int index) {
 return (BOX_SpaceOptionOptions) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index * 2);
}
BOX_SpaceOptionOptions BOX_makeSpaceOptionOptions2(BOX_OptLayout wsAfterHead, BOX_SpaceOption elem1, BOX_SpaceOption elem2) {
  return BOX_makeSpaceOptionOptionsMany(elem1, wsAfterHead, BOX_makeSpaceOptionOptionsSingle(elem2));
}
BOX_SpaceOptionOptions BOX_makeSpaceOptionOptions3(BOX_OptLayout wsAfterHead, BOX_SpaceOption elem1, BOX_SpaceOption elem2, BOX_SpaceOption elem3) {
  return BOX_makeSpaceOptionOptionsMany(elem1, wsAfterHead, BOX_makeSpaceOptionOptions2(wsAfterHead, elem2, elem3));
}
BOX_SpaceOptionOptions BOX_makeSpaceOptionOptions4(BOX_OptLayout wsAfterHead, BOX_SpaceOption elem1, BOX_SpaceOption elem2, BOX_SpaceOption elem3, BOX_SpaceOption elem4) {
  return BOX_makeSpaceOptionOptionsMany(elem1, wsAfterHead, BOX_makeSpaceOptionOptions3(wsAfterHead, elem2, elem3, elem4));
}
BOX_SpaceOptionOptions BOX_makeSpaceOptionOptions5(BOX_OptLayout wsAfterHead, BOX_SpaceOption elem1, BOX_SpaceOption elem2, BOX_SpaceOption elem3, BOX_SpaceOption elem4, BOX_SpaceOption elem5) {
  return BOX_makeSpaceOptionOptionsMany(elem1, wsAfterHead, BOX_makeSpaceOptionOptions4(wsAfterHead, elem2, elem3, elem4, elem5));
}
BOX_SpaceOptionOptions BOX_makeSpaceOptionOptions6(BOX_OptLayout wsAfterHead, BOX_SpaceOption elem1, BOX_SpaceOption elem2, BOX_SpaceOption elem3, BOX_SpaceOption elem4, BOX_SpaceOption elem5, BOX_SpaceOption elem6) {
  return BOX_makeSpaceOptionOptionsMany(elem1, wsAfterHead, BOX_makeSpaceOptionOptions5(wsAfterHead, elem2, elem3, elem4, elem5, elem6));
}
int BOX_getAlignmentOptionListLength (BOX_AlignmentOptionList arg) {
  if (ATisEmpty((ATermList) arg)) {
    return 0;
  }
  return (ATgetLength((ATermList) arg) / 4) + 1;
}
BOX_AlignmentOptionList BOX_reverseAlignmentOptionList(BOX_AlignmentOptionList arg) {
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

  return (BOX_AlignmentOptionList) result;
}
BOX_AlignmentOptionList BOX_appendAlignmentOptionList(BOX_AlignmentOptionList arg0, BOX_OptLayout wsAfterHead, BOX_OptLayout wsAfterSep, BOX_AlignmentOption arg1) {
  return BOX_concatAlignmentOptionList(arg0, wsAfterHead, wsAfterSep, BOX_makeAlignmentOptionListSingle(arg1));
}
BOX_AlignmentOptionList BOX_concatAlignmentOptionList(BOX_AlignmentOptionList arg0, BOX_OptLayout wsAfterHead, BOX_OptLayout wsAfterSep, BOX_AlignmentOptionList arg1) {
  if (ATisEmpty((ATermList) arg0)) {
    return arg1;
  }
  arg1 = BOX_makeAlignmentOptionListMany((BOX_AlignmentOption)ATgetFirst((ATermList) arg0), wsAfterHead, wsAfterSep,  arg1);
  arg1 = (BOX_AlignmentOptionList) ATgetNext((ATermList) arg1);
  return (BOX_AlignmentOptionList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
BOX_AlignmentOptionList BOX_sliceAlignmentOptionList(BOX_AlignmentOptionList arg, int start, int end) {
  return (BOX_AlignmentOptionList) ATgetSlice((ATermList) arg, start * 4, end * 4);
}
BOX_AlignmentOption BOX_getAlignmentOptionListAlignmentOptionAt(BOX_AlignmentOptionList arg, int index) {
 return (BOX_AlignmentOption)ATelementAt((ATermList) arg,index * 4);
}
BOX_AlignmentOptionList BOX_replaceAlignmentOptionListAlignmentOptionAt(BOX_AlignmentOptionList arg, BOX_AlignmentOption elem, int index) {
 return (BOX_AlignmentOptionList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index * 4);
}
BOX_AlignmentOptionList BOX_makeAlignmentOptionList2(BOX_OptLayout wsAfterHead, BOX_OptLayout wsAfterSep, BOX_AlignmentOption elem1, BOX_AlignmentOption elem2) {
  return BOX_makeAlignmentOptionListMany(elem1, wsAfterHead, wsAfterSep, BOX_makeAlignmentOptionListSingle(elem2));
}
BOX_AlignmentOptionList BOX_makeAlignmentOptionList3(BOX_OptLayout wsAfterHead, BOX_OptLayout wsAfterSep, BOX_AlignmentOption elem1, BOX_AlignmentOption elem2, BOX_AlignmentOption elem3) {
  return BOX_makeAlignmentOptionListMany(elem1, wsAfterHead, wsAfterSep, BOX_makeAlignmentOptionList2(wsAfterHead, wsAfterSep, elem2, elem3));
}
BOX_AlignmentOptionList BOX_makeAlignmentOptionList4(BOX_OptLayout wsAfterHead, BOX_OptLayout wsAfterSep, BOX_AlignmentOption elem1, BOX_AlignmentOption elem2, BOX_AlignmentOption elem3, BOX_AlignmentOption elem4) {
  return BOX_makeAlignmentOptionListMany(elem1, wsAfterHead, wsAfterSep, BOX_makeAlignmentOptionList3(wsAfterHead, wsAfterSep, elem2, elem3, elem4));
}
BOX_AlignmentOptionList BOX_makeAlignmentOptionList5(BOX_OptLayout wsAfterHead, BOX_OptLayout wsAfterSep, BOX_AlignmentOption elem1, BOX_AlignmentOption elem2, BOX_AlignmentOption elem3, BOX_AlignmentOption elem4, BOX_AlignmentOption elem5) {
  return BOX_makeAlignmentOptionListMany(elem1, wsAfterHead, wsAfterSep, BOX_makeAlignmentOptionList4(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5));
}
BOX_AlignmentOptionList BOX_makeAlignmentOptionList6(BOX_OptLayout wsAfterHead, BOX_OptLayout wsAfterSep, BOX_AlignmentOption elem1, BOX_AlignmentOption elem2, BOX_AlignmentOption elem3, BOX_AlignmentOption elem4, BOX_AlignmentOption elem5, BOX_AlignmentOption elem6) {
  return BOX_makeAlignmentOptionListMany(elem1, wsAfterHead, wsAfterSep, BOX_makeAlignmentOptionList5(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5, elem6));
}

/*}}}  */
/*{{{  constructors */

/*{{{  BOX_OptLayout BOX_makeOptLayoutAbsent(void) */

BOX_OptLayout BOX_makeOptLayoutAbsent(void)
{
  return (BOX_OptLayout)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATempty, (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4))), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATempty);
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_makeOptLayoutPresent(BOX_Layout layout) */

BOX_OptLayout BOX_makeOptLayoutPresent(BOX_Layout layout)
{
  return (BOX_OptLayout)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl0(BOX_afun4))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4))), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm) layout));
}

/*}}}  */
/*{{{  BOX_Layout BOX_makeLayoutLexToCf(BOX_LexLayoutList list) */

BOX_Layout BOX_makeLayoutLexToCf(BOX_LexLayoutList list)
{
  return (BOX_Layout)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun6, (ATerm)ATmakeAppl1(BOX_afun7, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl0(BOX_afun4)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun6, (ATerm)ATmakeAppl1(BOX_afun7, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm) list)));
}

/*}}}  */
/*{{{  BOX_LexLayoutList BOX_makeLexLayoutListEmpty(void) */

BOX_LexLayoutList BOX_makeLexLayoutListEmpty(void)
{
  return (BOX_LexLayoutList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  BOX_LexLayoutList BOX_makeLexLayoutListSingle(BOX_LexLayout head) */

BOX_LexLayoutList BOX_makeLexLayoutListSingle(BOX_LexLayout head)
{
  return (BOX_LexLayoutList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  BOX_LexLayoutList BOX_makeLexLayoutListMany(BOX_LexLayout head, BOX_LexLayoutList tail) */

BOX_LexLayoutList BOX_makeLexLayoutListMany(BOX_LexLayout head, BOX_LexLayoutList tail)
{
  return (BOX_LexLayoutList)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/*}}}  */
/*{{{  BOX_LexFontId BOX_makeLexFontIdDefault(const char* list) */

BOX_LexFontId BOX_makeLexFontIdDefault(const char* list)
{
  return (BOX_LexFontId)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun6, (ATerm)ATmakeAppl1(BOX_afun7, (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl2(BOX_afun10, (ATerm)ATmakeInt(97), (ATerm)ATmakeInt(122))), (ATerm)ATmakeAppl2(BOX_afun10, (ATerm)ATmakeInt(65), (ATerm)ATmakeInt(90))))))), (ATerm)ATmakeAppl1(BOX_afun6, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun12))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun16)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun6, (ATerm)ATmakeAppl1(BOX_afun7, (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl2(BOX_afun10, (ATerm)ATmakeInt(97), (ATerm)ATmakeInt(122))), (ATerm)ATmakeAppl2(BOX_afun10, (ATerm)ATmakeInt(65), (ATerm)ATmakeInt(90))))))), (ATerm) ((ATerm) BOX_stringToChars(list)))));
}

/*}}}  */
/*{{{  BOX_FontId BOX_makeFontIdLexToCf(BOX_LexFontId FontId) */

BOX_FontId BOX_makeFontIdLexToCf(BOX_LexFontId FontId)
{
  return (BOX_FontId)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun6, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun12)))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun12))), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm) FontId));
}

/*}}}  */
/*{{{  BOX_FontValue BOX_makeFontValueNatural(BOX_NatCon NatCon) */

BOX_FontValue BOX_makeFontValueNatural(BOX_NatCon NatCon)
{
  return (BOX_FontValue)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun17)))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun18))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun19)))))), (ATerm)ATmakeList1((ATerm) NatCon));
}

/*}}}  */
/*{{{  BOX_FontValue BOX_makeFontValueFontId(BOX_FontId FontId) */

BOX_FontValue BOX_makeFontValueFontId(BOX_FontId FontId)
{
  return (BOX_FontValue)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun12)))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun18))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun20)))))), (ATerm)ATmakeList1((ATerm) FontId));
}

/*}}}  */
/*{{{  BOX_FontOption BOX_makeFontOptionDefault(BOX_FontParam FontParam, BOX_OptLayout wsAfterFontParam, BOX_OptLayout wsAfterEquals, BOX_FontValue FontValue) */

BOX_FontOption BOX_makeFontOptionDefault(BOX_FontParam FontParam, BOX_OptLayout wsAfterFontParam, BOX_OptLayout wsAfterEquals, BOX_FontValue FontValue)
{
  return (BOX_FontOption)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun18)))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun22))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun24))), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) FontValue), (ATerm) wsAfterEquals), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(61)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun22)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(61)))), (ATerm) wsAfterFontParam), (ATerm) FontParam));
}

/*}}}  */
/*{{{  BOX_FontOperator BOX_makeFontOperatorDefault(BOX_OptLayout wsAfterF, BOX_FontOptionList list) */

BOX_FontOperator BOX_makeFontOperatorDefault(BOX_OptLayout wsAfterF, BOX_FontOptionList list)
{
  return (BOX_FontOperator)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun24))))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun26))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun27))), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun24))))), (ATerm) list)), (ATerm) wsAfterF), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(70)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun26)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(70)))));
}

/*}}}  */
/*{{{  BOX_FontOperator BOX_makeFontOperatorKeyword(void) */

BOX_FontOperator BOX_makeFontOperatorKeyword(void)
{
  return (BOX_FontOperator)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun28))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun27))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun29)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(87)))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(75)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun28)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(87)), (ATerm)ATmakeInt(75)))));
}

/*}}}  */
/*{{{  BOX_FontOperator BOX_makeFontOperatorVariable(void) */

BOX_FontOperator BOX_makeFontOperatorVariable(void)
{
  return (BOX_FontOperator)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun30))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun27))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun31)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(82)))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(65)))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(86)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun30)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(82)), (ATerm)ATmakeInt(65)), (ATerm)ATmakeInt(86)))));
}

/*}}}  */
/*{{{  BOX_FontOperator BOX_makeFontOperatorNumber(void) */

BOX_FontOperator BOX_makeFontOperatorNumber(void)
{
  return (BOX_FontOperator)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun32))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun27))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun33)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(77)))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(85)))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(78)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun32)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(77)), (ATerm)ATmakeInt(85)), (ATerm)ATmakeInt(78)))));
}

/*}}}  */
/*{{{  BOX_FontOperator BOX_makeFontOperatorMath(void) */

BOX_FontOperator BOX_makeFontOperatorMath(void)
{
  return (BOX_FontOperator)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun34))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun27))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun35)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(72)))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(84)))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(65)))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(77)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun34)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(72)), (ATerm)ATmakeInt(84)), (ATerm)ATmakeInt(65)), (ATerm)ATmakeInt(77)))));
}

/*}}}  */
/*{{{  BOX_FontOperator BOX_makeFontOperatorEscape(void) */

BOX_FontOperator BOX_makeFontOperatorEscape(void)
{
  return (BOX_FontOperator)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun36))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun27))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun37)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(67)))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(83)))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(69)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun36)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(67)), (ATerm)ATmakeInt(83)), (ATerm)ATmakeInt(69)))));
}

/*}}}  */
/*{{{  BOX_FontOperator BOX_makeFontOperatorComment(void) */

BOX_FontOperator BOX_makeFontOperatorComment(void)
{
  return (BOX_FontOperator)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun38))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun27))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun39)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(77)))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(77)))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(79)))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(67)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun38)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(77)), (ATerm)ATmakeInt(77)), (ATerm)ATmakeInt(79)), (ATerm)ATmakeInt(67)))));
}

/*}}}  */
/*{{{  BOX_FontOperator BOX_makeFontOperatorString(void) */

BOX_FontOperator BOX_makeFontOperatorString(void)
{
  return (BOX_FontOperator)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun40))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun27))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun41)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(71)))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(78)))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(73)))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(82)))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(84)))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(83)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun40)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(71)), (ATerm)ATmakeInt(78)), (ATerm)ATmakeInt(73)), (ATerm)ATmakeInt(82)), (ATerm)ATmakeInt(84)), (ATerm)ATmakeInt(83)))));
}

/*}}}  */
/*{{{  BOX_Box BOX_makeBoxFontOperator(BOX_FontOperator FontOperator, BOX_OptLayout wsAfterFontOperator, BOX_OptLayout wsAfterBracketOpen, BOX_Box Box, BOX_OptLayout wsAfterBox) */

BOX_Box BOX_makeBoxFontOperator(BOX_FontOperator FontOperator, BOX_OptLayout wsAfterFontOperator, BOX_OptLayout wsAfterBracketOpen, BOX_Box Box, BOX_OptLayout wsAfterBox)
{
  return (BOX_Box)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun42))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun43)))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun44))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun27)))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun43))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun45)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun42)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterBox), (ATerm) Box), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun44)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm) wsAfterFontOperator), (ATerm) FontOperator));
}

/*}}}  */
/*{{{  BOX_Box BOX_makeBoxDefault(BOX_OptLayout wsAfterCOMM, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList list, BOX_OptLayout wsAfterList) */

BOX_Box BOX_makeBoxDefault(BOX_OptLayout wsAfterCOMM, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList list, BOX_OptLayout wsAfterList)
{
  return (BOX_Box)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun42))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun43))))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun44))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun38))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun43))), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun42)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun43))))), (ATerm) list)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun44)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm) wsAfterCOMM), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(77)))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(77)))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(79)))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(67)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun38)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(77)), (ATerm)ATmakeInt(77)), (ATerm)ATmakeInt(79)), (ATerm)ATmakeInt(67)))));
}

/*}}}  */
/*{{{  BOX_Box BOX_makeBoxString(BOX_StrCon StrCon) */

BOX_Box BOX_makeBoxString(BOX_StrCon StrCon)
{
  return (BOX_Box)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun46)))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun43))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun41)))))), (ATerm)ATmakeList1((ATerm) StrCon));
}

/*}}}  */
/*{{{  BOX_Box BOX_makeBoxH(BOX_OptLayout wsAfterH, BOX_SpaceOptionOptions options, BOX_OptLayout wsAfterOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList list, BOX_OptLayout wsAfterList) */

BOX_Box BOX_makeBoxH(BOX_OptLayout wsAfterH, BOX_SpaceOptionOptions options, BOX_OptLayout wsAfterOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList list, BOX_OptLayout wsAfterList)
{
  return (BOX_Box)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun42))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun43))))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun44))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun47))))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun48))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun43))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun49)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun42)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun43))))), (ATerm) list)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun44)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm) wsAfterOptions), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun47))))), (ATerm) options)), (ATerm) wsAfterH), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(72)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun48)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(72)))));
}

/*}}}  */
/*{{{  BOX_Box BOX_makeBoxV(BOX_OptLayout wsAfterV, BOX_SpaceOptionOptions options, BOX_OptLayout wsAfterOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList list, BOX_OptLayout wsAfterList) */

BOX_Box BOX_makeBoxV(BOX_OptLayout wsAfterV, BOX_SpaceOptionOptions options, BOX_OptLayout wsAfterOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList list, BOX_OptLayout wsAfterList)
{
  return (BOX_Box)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun42))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun43))))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun44))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun47))))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun50))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun43))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun51)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun42)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun43))))), (ATerm) list)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun44)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm) wsAfterOptions), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun47))))), (ATerm) options)), (ATerm) wsAfterV), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(86)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun50)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(86)))));
}

/*}}}  */
/*{{{  BOX_Box BOX_makeBoxHv(BOX_OptLayout wsAfterHV, BOX_SpaceOptionOptions options, BOX_OptLayout wsAfterOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList list, BOX_OptLayout wsAfterList) */

BOX_Box BOX_makeBoxHv(BOX_OptLayout wsAfterHV, BOX_SpaceOptionOptions options, BOX_OptLayout wsAfterOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList list, BOX_OptLayout wsAfterList)
{
  return (BOX_Box)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun42))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun43))))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun44))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun47))))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun52))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun43))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun53)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun42)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun43))))), (ATerm) list)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun44)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm) wsAfterOptions), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun47))))), (ATerm) options)), (ATerm) wsAfterHV), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(86)))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(72)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun52)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(86)), (ATerm)ATmakeInt(72)))));
}

/*}}}  */
/*{{{  BOX_Box BOX_makeBoxHov(BOX_OptLayout wsAfterHOV, BOX_SpaceOptionOptions options, BOX_OptLayout wsAfterOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList list, BOX_OptLayout wsAfterList) */

BOX_Box BOX_makeBoxHov(BOX_OptLayout wsAfterHOV, BOX_SpaceOptionOptions options, BOX_OptLayout wsAfterOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList list, BOX_OptLayout wsAfterList)
{
  return (BOX_Box)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun42))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun43))))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun44))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun47))))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun54))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun43))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun55)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun42)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun43))))), (ATerm) list)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun44)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm) wsAfterOptions), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun47))))), (ATerm) options)), (ATerm) wsAfterHOV), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(86)))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(79)))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(72)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun54)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(86)), (ATerm)ATmakeInt(79)), (ATerm)ATmakeInt(72)))));
}

/*}}}  */
/*{{{  BOX_Box BOX_makeBoxI(BOX_OptLayout wsAfterI, BOX_SpaceOptionOptions options, BOX_OptLayout wsAfterOptions, BOX_OptLayout wsAfterBracketOpen, BOX_Box Box, BOX_OptLayout wsAfterBox) */

BOX_Box BOX_makeBoxI(BOX_OptLayout wsAfterI, BOX_SpaceOptionOptions options, BOX_OptLayout wsAfterOptions, BOX_OptLayout wsAfterBracketOpen, BOX_Box Box, BOX_OptLayout wsAfterBox)
{
  return (BOX_Box)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun42))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun43)))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun44))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun47))))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun56))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun43))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun57)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun42)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterBox), (ATerm) Box), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun44)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm) wsAfterOptions), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun47))))), (ATerm) options)), (ATerm) wsAfterI), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(73)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun56)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(73)))));
}

/*}}}  */
/*{{{  BOX_Box BOX_makeBoxWd(BOX_OptLayout wsAfterWD, BOX_OptLayout wsAfterBracketOpen, BOX_Box Box, BOX_OptLayout wsAfterBox) */

BOX_Box BOX_makeBoxWd(BOX_OptLayout wsAfterWD, BOX_OptLayout wsAfterBracketOpen, BOX_Box Box, BOX_OptLayout wsAfterBox)
{
  return (BOX_Box)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun42))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun43)))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun44))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun58))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun43))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun59)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun42)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterBox), (ATerm) Box), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun44)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm) wsAfterWD), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(68)))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(87)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun58)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(68)), (ATerm)ATmakeInt(87)))));
}

/*}}}  */
/*{{{  BOX_Box BOX_makeBoxAlignment(BOX_OptLayout wsAfterA, BOX_AlignmentOptions alignments, BOX_OptLayout wsAfterAlignments, BOX_SpaceOptionOptions options, BOX_OptLayout wsAfterOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList list, BOX_OptLayout wsAfterList) */

BOX_Box BOX_makeBoxAlignment(BOX_OptLayout wsAfterA, BOX_AlignmentOptions alignments, BOX_OptLayout wsAfterAlignments, BOX_SpaceOptionOptions options, BOX_OptLayout wsAfterOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList list, BOX_OptLayout wsAfterList)
{
  return (BOX_Box)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun42))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun43))))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun44))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun47))))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun60)))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun61))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun43))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun62)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun42)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun43))))), (ATerm) list)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun44)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm) wsAfterOptions), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun47))))), (ATerm) options)), (ATerm) wsAfterAlignments), (ATerm) alignments), (ATerm) wsAfterA), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(65)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun61)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(65)))));
}

/*}}}  */
/*{{{  BOX_Box BOX_makeBoxRow(BOX_OptLayout wsAfterR, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList list, BOX_OptLayout wsAfterList) */

BOX_Box BOX_makeBoxRow(BOX_OptLayout wsAfterR, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList list, BOX_OptLayout wsAfterList)
{
  return (BOX_Box)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun42))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun43))))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun44))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun63))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun43))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun64)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun42)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun43))))), (ATerm) list)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun44)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm) wsAfterR), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(82)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun63)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(82)))));
}

/*}}}  */
/*{{{  BOX_FontParam BOX_makeFontParamName(void) */

BOX_FontParam BOX_makeFontParamName(void)
{
  return (BOX_FontParam)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun65))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun23))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun66)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(110)))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(102)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun65)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(110)), (ATerm)ATmakeInt(102)))));
}

/*}}}  */
/*{{{  BOX_FontParam BOX_makeFontParamFamily(void) */

BOX_FontParam BOX_makeFontParamFamily(void)
{
  return (BOX_FontParam)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun67))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun23))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun68)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(109)))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(102)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun67)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(109)), (ATerm)ATmakeInt(102)))));
}

/*}}}  */
/*{{{  BOX_FontParam BOX_makeFontParamSeries(void) */

BOX_FontParam BOX_makeFontParamSeries(void)
{
  return (BOX_FontParam)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun69))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun23))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun70)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun69)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(115)))));
}

/*}}}  */
/*{{{  BOX_FontParam BOX_makeFontParamShape(void) */

BOX_FontParam BOX_makeFontParamShape(void)
{
  return (BOX_FontParam)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun71))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun23))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun72)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(104)))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun71)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(104)), (ATerm)ATmakeInt(115)))));
}

/*}}}  */
/*{{{  BOX_FontParam BOX_makeFontParamSize(void) */

BOX_FontParam BOX_makeFontParamSize(void)
{
  return (BOX_FontParam)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun73))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun23))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun74)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(122)))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun73)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(122)), (ATerm)ATmakeInt(115)))));
}

/*}}}  */
/*{{{  BOX_FontParam BOX_makeFontParamColor(void) */

BOX_FontParam BOX_makeFontParamColor(void)
{
  return (BOX_FontParam)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun75))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun23))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun76)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(99)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun75)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(108)), (ATerm)ATmakeInt(99)))));
}

/*}}}  */
/*{{{  BOX_FontOptionList BOX_makeFontOptionListEmpty(void) */

BOX_FontOptionList BOX_makeFontOptionListEmpty(void)
{
  return (BOX_FontOptionList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  BOX_FontOptionList BOX_makeFontOptionListSingle(BOX_FontOption head) */

BOX_FontOptionList BOX_makeFontOptionListSingle(BOX_FontOption head)
{
  return (BOX_FontOptionList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  BOX_FontOptionList BOX_makeFontOptionListMany(BOX_FontOption head, BOX_OptLayout wsAfterHead, BOX_FontOptionList tail) */

BOX_FontOptionList BOX_makeFontOptionListMany(BOX_FontOption head, BOX_OptLayout wsAfterHead, BOX_FontOptionList tail)
{
  if (BOX_isFontOptionListEmpty(tail)) {
    return BOX_makeFontOptionListSingle(head);
  }
  return (BOX_FontOptionList)(ATerm)ATinsert(ATinsert((ATermList)tail, (ATerm) wsAfterHead), (ATerm) head);
}

/*}}}  */
/*{{{  BOX_BoxList BOX_makeBoxListEmpty(void) */

BOX_BoxList BOX_makeBoxListEmpty(void)
{
  return (BOX_BoxList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  BOX_BoxList BOX_makeBoxListSingle(BOX_Box head) */

BOX_BoxList BOX_makeBoxListSingle(BOX_Box head)
{
  return (BOX_BoxList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  BOX_BoxList BOX_makeBoxListMany(BOX_Box head, BOX_OptLayout wsAfterHead, BOX_BoxList tail) */

BOX_BoxList BOX_makeBoxListMany(BOX_Box head, BOX_OptLayout wsAfterHead, BOX_BoxList tail)
{
  if (BOX_isBoxListEmpty(tail)) {
    return BOX_makeBoxListSingle(head);
  }
  return (BOX_BoxList)(ATerm)ATinsert(ATinsert((ATermList)tail, (ATerm) wsAfterHead), (ATerm) head);
}

/*}}}  */
/*{{{  BOX_LexNatCon BOX_makeLexNatConDigits(const char* list) */

BOX_LexNatCon BOX_makeLexNatConDigits(const char* list)
{
  return (BOX_LexNatCon)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun6, (ATerm)ATmakeAppl1(BOX_afun7, (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun10, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))))))), (ATerm)ATmakeAppl1(BOX_afun6, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun17))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun77)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun6, (ATerm)ATmakeAppl1(BOX_afun7, (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun10, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))))))), (ATerm) ((ATerm) BOX_stringToChars(list)))));
}

/*}}}  */
/*{{{  BOX_NatCon BOX_makeNatConLexToCf(BOX_LexNatCon NatCon) */

BOX_NatCon BOX_makeNatConLexToCf(BOX_LexNatCon NatCon)
{
  return (BOX_NatCon)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun6, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun17)))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun17))), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm) NatCon));
}

/*}}}  */
/*{{{  BOX_LexStrChar BOX_makeLexStrCharNewline(void) */

BOX_LexStrChar BOX_makeLexStrCharNewline(void)
{
  return (BOX_LexStrChar)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun78))), (ATerm)ATmakeAppl1(BOX_afun6, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun79))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun80)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(110)))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun78)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(110)), (ATerm)ATmakeInt(92)))));
}

/*}}}  */
/*{{{  BOX_LexStrChar BOX_makeLexStrCharTab(void) */

BOX_LexStrChar BOX_makeLexStrCharTab(void)
{
  return (BOX_LexStrChar)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun81))), (ATerm)ATmakeAppl1(BOX_afun6, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun79))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun82)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun81)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(92)))));
}

/*}}}  */
/*{{{  BOX_LexStrChar BOX_makeLexStrCharQuote(void) */

BOX_LexStrChar BOX_makeLexStrCharQuote(void)
{
  return (BOX_LexStrChar)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun83))), (ATerm)ATmakeAppl1(BOX_afun6, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun79))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun84)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(34)))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun83)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(34)), (ATerm)ATmakeInt(92)))));
}

/*}}}  */
/*{{{  BOX_LexStrChar BOX_makeLexStrCharBackslash(void) */

BOX_LexStrChar BOX_makeLexStrCharBackslash(void)
{
  return (BOX_LexStrChar)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun85))), (ATerm)ATmakeAppl1(BOX_afun6, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun79))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun86)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun85)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(92)), (ATerm)ATmakeInt(92)))));
}

/*}}}  */
/*{{{  BOX_LexStrChar BOX_makeLexStrCharDecimal(char a, char b, char c) */

BOX_LexStrChar BOX_makeLexStrCharDecimal(char a, char b, char c)
{
  return (BOX_LexStrChar)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun10, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun10, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun10, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun87))), (ATerm)ATmakeAppl1(BOX_afun6, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun79))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun88)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) ((ATerm) BOX_byteToChar(c))), (ATerm) ((ATerm) BOX_byteToChar(b))), (ATerm) ((ATerm) BOX_byteToChar(a))), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun87)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))));
}

/*}}}  */
/*{{{  BOX_LexStrChar BOX_makeLexStrCharNormal(char ch) */

BOX_LexStrChar BOX_makeLexStrCharNormal(char ch)
{
  return (BOX_LexStrChar)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(BOX_afun10, (ATerm)ATmakeInt(93), (ATerm)ATmakeInt(255))), (ATerm)ATmakeAppl2(BOX_afun10, (ATerm)ATmakeInt(35), (ATerm)ATmakeInt(91))), (ATerm)ATmakeAppl2(BOX_afun10, (ATerm)ATmakeInt(32), (ATerm)ATmakeInt(33))))), (ATerm)ATmakeAppl1(BOX_afun6, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun79))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun89)))))), (ATerm)ATmakeList1((ATerm) ((ATerm) BOX_byteToChar(ch))));
}

/*}}}  */
/*{{{  BOX_StrChar BOX_makeStrCharLexToCf(BOX_LexStrChar StrChar) */

BOX_StrChar BOX_makeStrCharLexToCf(BOX_LexStrChar StrChar)
{
  return (BOX_StrChar)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun6, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun79)))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun79))), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm) StrChar));
}

/*}}}  */
/*{{{  BOX_LexStrCon BOX_makeLexStrConDefault(BOX_LexStrCharChars chars) */

BOX_LexStrCon BOX_makeLexStrConDefault(BOX_LexStrCharChars chars)
{
  return (BOX_LexStrCon)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(34)))), (ATerm)ATmakeAppl1(BOX_afun6, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun79))))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(34)))), (ATerm)ATmakeAppl1(BOX_afun6, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun46))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun16)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(34)), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun6, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun79))))), (ATerm) chars)), (ATerm)ATmakeInt(34)));
}

/*}}}  */
/*{{{  BOX_StrCon BOX_makeStrConLexToCf(BOX_LexStrCon StrCon) */

BOX_StrCon BOX_makeStrConLexToCf(BOX_LexStrCon StrCon)
{
  return (BOX_StrCon)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun6, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun46)))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun46))), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm) StrCon));
}

/*}}}  */
/*{{{  BOX_LexStrCharChars BOX_makeLexStrCharCharsEmpty(void) */

BOX_LexStrCharChars BOX_makeLexStrCharCharsEmpty(void)
{
  return (BOX_LexStrCharChars)(ATerm)ATempty;
}

/*}}}  */
/*{{{  BOX_LexStrCharChars BOX_makeLexStrCharCharsSingle(BOX_LexStrChar head) */

BOX_LexStrCharChars BOX_makeLexStrCharCharsSingle(BOX_LexStrChar head)
{
  return (BOX_LexStrCharChars)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  BOX_LexStrCharChars BOX_makeLexStrCharCharsMany(BOX_LexStrChar head, BOX_LexStrCharChars tail) */

BOX_LexStrCharChars BOX_makeLexStrCharCharsMany(BOX_LexStrChar head, BOX_LexStrCharChars tail)
{
  return (BOX_LexStrCharChars)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/*}}}  */
/*{{{  BOX_LexLayout BOX_makeLexLayoutWhitespace(char ch) */

BOX_LexLayout BOX_makeLexLayoutWhitespace(char ch)
{
  return (BOX_LexLayout)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(32)), (ATerm)ATmakeInt(13)), (ATerm)ATmakeAppl2(BOX_afun10, (ATerm)ATmakeInt(9), (ATerm)ATmakeInt(10))))), (ATerm)ATmakeAppl1(BOX_afun6, (ATerm)ATmakeAppl0(BOX_afun4)), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun90)))))), (ATerm)ATmakeList1((ATerm) ((ATerm) BOX_byteToChar(ch))));
}

/*}}}  */
/*{{{  BOX_LexLayout BOX_makeLexLayoutLine(const char* line) */

BOX_LexLayout BOX_makeLexLayoutLine(const char* line)
{
  return (BOX_LexLayout)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun91))), (ATerm)ATmakeAppl1(BOX_afun6, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl2(BOX_afun10, (ATerm)ATmakeInt(11), (ATerm)ATmakeInt(255))), (ATerm)ATmakeAppl2(BOX_afun10, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(9))))))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun92))), (ATerm)ATmakeAppl1(BOX_afun6, (ATerm)ATmakeAppl0(BOX_afun4)), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun93)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(10)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun91)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(10)))), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun6, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl2(BOX_afun10, (ATerm)ATmakeInt(11), (ATerm)ATmakeInt(255))), (ATerm)ATmakeAppl2(BOX_afun10, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(9))))))), (ATerm) ((ATerm) BOX_stringToChars(line)))), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(37)))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(37)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun92)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(37)), (ATerm)ATmakeInt(37)))));
}

/*}}}  */
/*{{{  BOX_LexLayout BOX_makeLexLayoutNested(const char* content) */

BOX_LexLayout BOX_makeLexLayoutNested(const char* content)
{
  return (BOX_LexLayout)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun94))), (ATerm)ATmakeAppl1(BOX_afun6, (ATerm)ATmakeAppl1(BOX_afun7, (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(BOX_afun10, (ATerm)ATmakeInt(38), (ATerm)ATmakeInt(255))), (ATerm)ATmakeAppl2(BOX_afun10, (ATerm)ATmakeInt(11), (ATerm)ATmakeInt(36))), (ATerm)ATmakeAppl2(BOX_afun10, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(9))))))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun94))), (ATerm)ATmakeAppl1(BOX_afun6, (ATerm)ATmakeAppl0(BOX_afun4)), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun95)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(37)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun94)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(37)))), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun6, (ATerm)ATmakeAppl1(BOX_afun7, (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(BOX_afun10, (ATerm)ATmakeInt(38), (ATerm)ATmakeInt(255))), (ATerm)ATmakeAppl2(BOX_afun10, (ATerm)ATmakeInt(11), (ATerm)ATmakeInt(36))), (ATerm)ATmakeAppl2(BOX_afun10, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(9))))))), (ATerm) ((ATerm) BOX_stringToChars(content)))), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(37)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun94)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(37)))));
}

/*}}}  */
/*{{{  BOX_SpaceSymbol BOX_makeSpaceSymbolHorizontal(void) */

BOX_SpaceSymbol BOX_makeSpaceSymbolHorizontal(void)
{
  return (BOX_SpaceSymbol)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun96))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun97))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun98)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(104)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun96)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(115)), (ATerm)ATmakeInt(104)))));
}

/*}}}  */
/*{{{  BOX_SpaceSymbol BOX_makeSpaceSymbolVertical(void) */

BOX_SpaceSymbol BOX_makeSpaceSymbolVertical(void)
{
  return (BOX_SpaceSymbol)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun99))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun97))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun100)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(118)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun99)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(115)), (ATerm)ATmakeInt(118)))));
}

/*}}}  */
/*{{{  BOX_SpaceSymbol BOX_makeSpaceSymbolIndentation(void) */

BOX_SpaceSymbol BOX_makeSpaceSymbolIndentation(void)
{
  return (BOX_SpaceSymbol)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun101))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun97))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun102)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun101)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(115)), (ATerm)ATmakeInt(105)))));
}

/*}}}  */
/*{{{  BOX_SpaceSymbol BOX_makeSpaceSymbolTabstop(void) */

BOX_SpaceSymbol BOX_makeSpaceSymbolTabstop(void)
{
  return (BOX_SpaceSymbol)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun103))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun97))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun104)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun103)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(115)), (ATerm)ATmakeInt(116)))));
}

/*}}}  */
/*{{{  BOX_SpaceOption BOX_makeSpaceOptionDefault(BOX_SpaceSymbol SpaceSymbol, BOX_OptLayout wsAfterSpaceSymbol, BOX_OptLayout wsAfterEquals, BOX_NatCon NatCon) */

BOX_SpaceOption BOX_makeSpaceOptionDefault(BOX_SpaceSymbol SpaceSymbol, BOX_OptLayout wsAfterSpaceSymbol, BOX_OptLayout wsAfterEquals, BOX_NatCon NatCon)
{
  return (BOX_SpaceOption)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun17)))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun22))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun97)))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun47))), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) NatCon), (ATerm) wsAfterEquals), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(61)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun22)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(61)))), (ATerm) wsAfterSpaceSymbol), (ATerm) SpaceSymbol));
}

/*}}}  */
/*{{{  BOX_SpaceOptionOptions BOX_makeSpaceOptionOptionsEmpty(void) */

BOX_SpaceOptionOptions BOX_makeSpaceOptionOptionsEmpty(void)
{
  return (BOX_SpaceOptionOptions)(ATerm)ATempty;
}

/*}}}  */
/*{{{  BOX_SpaceOptionOptions BOX_makeSpaceOptionOptionsSingle(BOX_SpaceOption head) */

BOX_SpaceOptionOptions BOX_makeSpaceOptionOptionsSingle(BOX_SpaceOption head)
{
  return (BOX_SpaceOptionOptions)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  BOX_SpaceOptionOptions BOX_makeSpaceOptionOptionsMany(BOX_SpaceOption head, BOX_OptLayout wsAfterHead, BOX_SpaceOptionOptions tail) */

BOX_SpaceOptionOptions BOX_makeSpaceOptionOptionsMany(BOX_SpaceOption head, BOX_OptLayout wsAfterHead, BOX_SpaceOptionOptions tail)
{
  if (BOX_isSpaceOptionOptionsEmpty(tail)) {
    return BOX_makeSpaceOptionOptionsSingle(head);
  }
  return (BOX_SpaceOptionOptions)(ATerm)ATinsert(ATinsert((ATermList)tail, (ATerm) wsAfterHead), (ATerm) head);
}

/*}}}  */
/*{{{  BOX_AlignmentOption BOX_makeAlignmentOptionLeft(BOX_OptLayout wsAfterL, BOX_SpaceOptionOptions options) */

BOX_AlignmentOption BOX_makeAlignmentOptionLeft(BOX_OptLayout wsAfterL, BOX_SpaceOptionOptions options)
{
  return (BOX_AlignmentOption)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun47))))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun105))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun106))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun107)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun47))))), (ATerm) options)), (ATerm) wsAfterL), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun105)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))));
}

/*}}}  */
/*{{{  BOX_AlignmentOption BOX_makeAlignmentOptionCentre(BOX_OptLayout wsAfterC, BOX_SpaceOptionOptions options) */

BOX_AlignmentOption BOX_makeAlignmentOptionCentre(BOX_OptLayout wsAfterC, BOX_SpaceOptionOptions options)
{
  return (BOX_AlignmentOption)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun47))))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun108))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun106))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun109)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun47))))), (ATerm) options)), (ATerm) wsAfterC), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(99)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun108)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(99)))));
}

/*}}}  */
/*{{{  BOX_AlignmentOption BOX_makeAlignmentOptionRight(BOX_OptLayout wsAfterR, BOX_SpaceOptionOptions options) */

BOX_AlignmentOption BOX_makeAlignmentOptionRight(BOX_OptLayout wsAfterR, BOX_SpaceOptionOptions options)
{
  return (BOX_AlignmentOption)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun47))))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun110))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun106))), (ATerm)ATmakeAppl1(BOX_afun13, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl1(BOX_afun15, (ATerm)ATmakeAppl0(BOX_afun111)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun47))))), (ATerm) options)), (ATerm) wsAfterR), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun110)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))));
}

/*}}}  */
/*{{{  BOX_AlignmentOptions BOX_makeAlignmentOptionsDefault(BOX_OptLayout wsAfterParenOpen, BOX_AlignmentOptionList list, BOX_OptLayout wsAfterList) */

BOX_AlignmentOptions BOX_makeAlignmentOptionsDefault(BOX_OptLayout wsAfterParenOpen, BOX_AlignmentOptionList list, BOX_OptLayout wsAfterList)
{
  return (BOX_AlignmentOptions)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun112))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl2(BOX_afun113, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun106)), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun114))))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun115))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun60))), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun112)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl2(BOX_afun113, (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun106)), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun114))))), (ATerm) list)), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun115)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))));
}

/*}}}  */
/*{{{  BOX_AlignmentOptionList BOX_makeAlignmentOptionListEmpty(void) */

BOX_AlignmentOptionList BOX_makeAlignmentOptionListEmpty(void)
{
  return (BOX_AlignmentOptionList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  BOX_AlignmentOptionList BOX_makeAlignmentOptionListSingle(BOX_AlignmentOption head) */

BOX_AlignmentOptionList BOX_makeAlignmentOptionListSingle(BOX_AlignmentOption head)
{
  return (BOX_AlignmentOptionList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  BOX_AlignmentOptionList BOX_makeAlignmentOptionListMany(BOX_AlignmentOption head, BOX_OptLayout wsAfterHead, BOX_OptLayout wsAfterSep, BOX_AlignmentOptionList tail) */

BOX_AlignmentOptionList BOX_makeAlignmentOptionListMany(BOX_AlignmentOption head, BOX_OptLayout wsAfterHead, BOX_OptLayout wsAfterSep, BOX_AlignmentOptionList tail)
{
  if (BOX_isAlignmentOptionListEmpty(tail)) {
    return BOX_makeAlignmentOptionListSingle(head);
  }
  return (BOX_AlignmentOptionList)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm) wsAfterSep), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(BOX_afun21, (ATerm)ATmakeAppl0(BOX_afun114)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterHead), (ATerm) head);
}

/*}}}  */
/*{{{  BOX_Start BOX_makeStartBox(BOX_OptLayout wsBefore, BOX_Box topBox, BOX_OptLayout wsAfter, int ambCnt) */

BOX_Start BOX_makeStartBox(BOX_OptLayout wsBefore, BOX_Box topBox, BOX_OptLayout wsAfter, int ambCnt)
{
  return (BOX_Start)(ATerm)ATmakeAppl2(BOX_afun116, (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun43))), (ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun11, (ATerm)ATmakeAppl0(BOX_afun117)), (ATerm)ATmakeAppl0(BOX_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topBox), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool BOX_isEqualOptLayout(BOX_OptLayout arg0, BOX_OptLayout arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualLayout(BOX_Layout arg0, BOX_Layout arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualLexLayoutList(BOX_LexLayoutList arg0, BOX_LexLayoutList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualLexFontId(BOX_LexFontId arg0, BOX_LexFontId arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualFontId(BOX_FontId arg0, BOX_FontId arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualFontValue(BOX_FontValue arg0, BOX_FontValue arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualFontOption(BOX_FontOption arg0, BOX_FontOption arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualFontOperator(BOX_FontOperator arg0, BOX_FontOperator arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualBox(BOX_Box arg0, BOX_Box arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualFontParam(BOX_FontParam arg0, BOX_FontParam arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualFontOptionList(BOX_FontOptionList arg0, BOX_FontOptionList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualBoxList(BOX_BoxList arg0, BOX_BoxList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualLexNatCon(BOX_LexNatCon arg0, BOX_LexNatCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualNatCon(BOX_NatCon arg0, BOX_NatCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualLexStrChar(BOX_LexStrChar arg0, BOX_LexStrChar arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualStrChar(BOX_StrChar arg0, BOX_StrChar arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualLexStrCon(BOX_LexStrCon arg0, BOX_LexStrCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualStrCon(BOX_StrCon arg0, BOX_StrCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualLexStrCharChars(BOX_LexStrCharChars arg0, BOX_LexStrCharChars arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualLexLayout(BOX_LexLayout arg0, BOX_LexLayout arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualSpaceSymbol(BOX_SpaceSymbol arg0, BOX_SpaceSymbol arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualSpaceOption(BOX_SpaceOption arg0, BOX_SpaceOption arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualSpaceOptionOptions(BOX_SpaceOptionOptions arg0, BOX_SpaceOptionOptions arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualAlignmentOption(BOX_AlignmentOption arg0, BOX_AlignmentOption arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualAlignmentOptions(BOX_AlignmentOptions arg0, BOX_AlignmentOptions arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualAlignmentOptionList(BOX_AlignmentOptionList arg0, BOX_AlignmentOptionList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualStart(BOX_Start arg0, BOX_Start arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  BOX_OptLayout accessors */

/*{{{  ATbool BOX_isValidOptLayout(BOX_OptLayout arg) */

ATbool BOX_isValidOptLayout(BOX_OptLayout arg)
{
  if (BOX_isOptLayoutAbsent(arg)) {
    return ATtrue;
  }
  else if (BOX_isOptLayoutPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool BOX_isOptLayoutAbsent(BOX_OptLayout arg) */

inline ATbool BOX_isOptLayoutAbsent(BOX_OptLayout arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternOptLayoutAbsent);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isOptLayoutPresent(BOX_OptLayout arg) */

inline ATbool BOX_isOptLayoutPresent(BOX_OptLayout arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternOptLayoutPresent, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool BOX_hasOptLayoutLayout(BOX_OptLayout arg) */

ATbool BOX_hasOptLayoutLayout(BOX_OptLayout arg)
{
  if (BOX_isOptLayoutPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_Layout BOX_getOptLayoutLayout(BOX_OptLayout arg) */

BOX_Layout BOX_getOptLayoutLayout(BOX_OptLayout arg)
{
  
    return (BOX_Layout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_setOptLayoutLayout(BOX_OptLayout arg, BOX_Layout layout) */

BOX_OptLayout BOX_setOptLayoutLayout(BOX_OptLayout arg, BOX_Layout layout)
{
  if (BOX_isOptLayoutPresent(arg)) {
    return (BOX_OptLayout)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) layout), 0), 1);
  }

  ATabort("OptLayout has no Layout: %t\n", arg);
  return (BOX_OptLayout)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  BOX_Layout accessors */

/*{{{  ATbool BOX_isValidLayout(BOX_Layout arg) */

ATbool BOX_isValidLayout(BOX_Layout arg)
{
  if (BOX_isLayoutLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool BOX_isLayoutLexToCf(BOX_Layout arg) */

inline ATbool BOX_isLayoutLexToCf(BOX_Layout arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, BOX_patternLayoutLexToCf, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool BOX_hasLayoutList(BOX_Layout arg) */

ATbool BOX_hasLayoutList(BOX_Layout arg)
{
  if (BOX_isLayoutLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_LexLayoutList BOX_getLayoutList(BOX_Layout arg) */

BOX_LexLayoutList BOX_getLayoutList(BOX_Layout arg)
{
  
    return (BOX_LexLayoutList)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  BOX_Layout BOX_setLayoutList(BOX_Layout arg, BOX_LexLayoutList list) */

BOX_Layout BOX_setLayoutList(BOX_Layout arg, BOX_LexLayoutList list)
{
  if (BOX_isLayoutLexToCf(arg)) {
    return (BOX_Layout)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) list), 1), 0), 1);
  }

  ATabort("Layout has no List: %t\n", arg);
  return (BOX_Layout)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  BOX_LexLayoutList accessors */

/*{{{  ATbool BOX_isValidLexLayoutList(BOX_LexLayoutList arg) */

ATbool BOX_isValidLexLayoutList(BOX_LexLayoutList arg)
{
  if (BOX_isLexLayoutListEmpty(arg)) {
    return ATtrue;
  }
  else if (BOX_isLexLayoutListSingle(arg)) {
    return ATtrue;
  }
  else if (BOX_isLexLayoutListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool BOX_isLexLayoutListEmpty(BOX_LexLayoutList arg) */

inline ATbool BOX_isLexLayoutListEmpty(BOX_LexLayoutList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, BOX_patternLexLayoutListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool BOX_isLexLayoutListSingle(BOX_LexLayoutList arg) */

inline ATbool BOX_isLexLayoutListSingle(BOX_LexLayoutList arg)
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
      last_result = ATmatchTerm((ATerm)arg, BOX_patternLexLayoutListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isLexLayoutListMany(BOX_LexLayoutList arg) */

inline ATbool BOX_isLexLayoutListMany(BOX_LexLayoutList arg)
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
      last_result = ATmatchTerm((ATerm)arg, BOX_patternLexLayoutListMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool BOX_hasLexLayoutListHead(BOX_LexLayoutList arg) */

ATbool BOX_hasLexLayoutListHead(BOX_LexLayoutList arg)
{
  if (BOX_isLexLayoutListSingle(arg)) {
    return ATtrue;
  }
  else if (BOX_isLexLayoutListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasLexLayoutListTail(BOX_LexLayoutList arg) */

ATbool BOX_hasLexLayoutListTail(BOX_LexLayoutList arg)
{
  if (BOX_isLexLayoutListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_LexLayout BOX_getLexLayoutListHead(BOX_LexLayoutList arg) */

BOX_LexLayout BOX_getLexLayoutListHead(BOX_LexLayoutList arg)
{
  if (BOX_isLexLayoutListSingle(arg)) {
    return (BOX_LexLayout)ATgetFirst((ATermList)arg);
  }
  else 
    return (BOX_LexLayout)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  BOX_LexLayoutList BOX_getLexLayoutListTail(BOX_LexLayoutList arg) */

BOX_LexLayoutList BOX_getLexLayoutListTail(BOX_LexLayoutList arg)
{
  
    return (BOX_LexLayoutList)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  BOX_LexLayoutList BOX_setLexLayoutListHead(BOX_LexLayoutList arg, BOX_LexLayout head) */

BOX_LexLayoutList BOX_setLexLayoutListHead(BOX_LexLayoutList arg, BOX_LexLayout head)
{
  if (BOX_isLexLayoutListSingle(arg)) {
    return (BOX_LexLayoutList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (BOX_isLexLayoutListMany(arg)) {
    return (BOX_LexLayoutList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("LexLayoutList has no Head: %t\n", arg);
  return (BOX_LexLayoutList)NULL;
}

/*}}}  */
/*{{{  BOX_LexLayoutList BOX_setLexLayoutListTail(BOX_LexLayoutList arg, BOX_LexLayoutList tail) */

BOX_LexLayoutList BOX_setLexLayoutListTail(BOX_LexLayoutList arg, BOX_LexLayoutList tail)
{
  if (BOX_isLexLayoutListMany(arg)) {
    return (BOX_LexLayoutList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("LexLayoutList has no Tail: %t\n", arg);
  return (BOX_LexLayoutList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  BOX_LexFontId accessors */

/*{{{  ATbool BOX_isValidLexFontId(BOX_LexFontId arg) */

ATbool BOX_isValidLexFontId(BOX_LexFontId arg)
{
  if (BOX_isLexFontIdDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool BOX_isLexFontIdDefault(BOX_LexFontId arg) */

inline ATbool BOX_isLexFontIdDefault(BOX_LexFontId arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, BOX_patternLexFontIdDefault, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool BOX_hasLexFontIdList(BOX_LexFontId arg) */

ATbool BOX_hasLexFontIdList(BOX_LexFontId arg)
{
  if (BOX_isLexFontIdDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* BOX_getLexFontIdList(BOX_LexFontId arg) */

char* BOX_getLexFontIdList(BOX_LexFontId arg)
{
  
    return (char*)BOX_charsToString((ATerm)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1));
}

/*}}}  */
/*{{{  BOX_LexFontId BOX_setLexFontIdList(BOX_LexFontId arg, const char* list) */

BOX_LexFontId BOX_setLexFontIdList(BOX_LexFontId arg, const char* list)
{
  if (BOX_isLexFontIdDefault(arg)) {
    return (BOX_LexFontId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) ((ATerm) BOX_stringToChars(list))), 1), 0), 1);
  }

  ATabort("LexFontId has no List: %t\n", arg);
  return (BOX_LexFontId)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  BOX_FontId accessors */

/*{{{  ATbool BOX_isValidFontId(BOX_FontId arg) */

ATbool BOX_isValidFontId(BOX_FontId arg)
{
  if (BOX_isFontIdLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool BOX_isFontIdLexToCf(BOX_FontId arg) */

inline ATbool BOX_isFontIdLexToCf(BOX_FontId arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, BOX_patternFontIdLexToCf, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool BOX_hasFontIdFontId(BOX_FontId arg) */

ATbool BOX_hasFontIdFontId(BOX_FontId arg)
{
  if (BOX_isFontIdLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_LexFontId BOX_getFontIdFontId(BOX_FontId arg) */

BOX_LexFontId BOX_getFontIdFontId(BOX_FontId arg)
{
  
    return (BOX_LexFontId)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  BOX_FontId BOX_setFontIdFontId(BOX_FontId arg, BOX_LexFontId FontId) */

BOX_FontId BOX_setFontIdFontId(BOX_FontId arg, BOX_LexFontId FontId)
{
  if (BOX_isFontIdLexToCf(arg)) {
    return (BOX_FontId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) FontId), 0), 1);
  }

  ATabort("FontId has no FontId: %t\n", arg);
  return (BOX_FontId)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  BOX_FontValue accessors */

/*{{{  ATbool BOX_isValidFontValue(BOX_FontValue arg) */

ATbool BOX_isValidFontValue(BOX_FontValue arg)
{
  if (BOX_isFontValueNatural(arg)) {
    return ATtrue;
  }
  else if (BOX_isFontValueFontId(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool BOX_isFontValueNatural(BOX_FontValue arg) */

inline ATbool BOX_isFontValueNatural(BOX_FontValue arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternFontValueNatural, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isFontValueFontId(BOX_FontValue arg) */

inline ATbool BOX_isFontValueFontId(BOX_FontValue arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternFontValueFontId, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool BOX_hasFontValueNatCon(BOX_FontValue arg) */

ATbool BOX_hasFontValueNatCon(BOX_FontValue arg)
{
  if (BOX_isFontValueNatural(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasFontValueFontId(BOX_FontValue arg) */

ATbool BOX_hasFontValueFontId(BOX_FontValue arg)
{
  if (BOX_isFontValueFontId(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_NatCon BOX_getFontValueNatCon(BOX_FontValue arg) */

BOX_NatCon BOX_getFontValueNatCon(BOX_FontValue arg)
{
  
    return (BOX_NatCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  BOX_FontId BOX_getFontValueFontId(BOX_FontValue arg) */

BOX_FontId BOX_getFontValueFontId(BOX_FontValue arg)
{
  
    return (BOX_FontId)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  BOX_FontValue BOX_setFontValueNatCon(BOX_FontValue arg, BOX_NatCon NatCon) */

BOX_FontValue BOX_setFontValueNatCon(BOX_FontValue arg, BOX_NatCon NatCon)
{
  if (BOX_isFontValueNatural(arg)) {
    return (BOX_FontValue)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) NatCon), 0), 1);
  }

  ATabort("FontValue has no NatCon: %t\n", arg);
  return (BOX_FontValue)NULL;
}

/*}}}  */
/*{{{  BOX_FontValue BOX_setFontValueFontId(BOX_FontValue arg, BOX_FontId FontId) */

BOX_FontValue BOX_setFontValueFontId(BOX_FontValue arg, BOX_FontId FontId)
{
  if (BOX_isFontValueFontId(arg)) {
    return (BOX_FontValue)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) FontId), 0), 1);
  }

  ATabort("FontValue has no FontId: %t\n", arg);
  return (BOX_FontValue)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  BOX_FontOption accessors */

/*{{{  ATbool BOX_isValidFontOption(BOX_FontOption arg) */

ATbool BOX_isValidFontOption(BOX_FontOption arg)
{
  if (BOX_isFontOptionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool BOX_isFontOptionDefault(BOX_FontOption arg) */

inline ATbool BOX_isFontOptionDefault(BOX_FontOption arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, BOX_patternFontOptionDefault, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool BOX_hasFontOptionFontParam(BOX_FontOption arg) */

ATbool BOX_hasFontOptionFontParam(BOX_FontOption arg)
{
  if (BOX_isFontOptionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasFontOptionWsAfterFontParam(BOX_FontOption arg) */

ATbool BOX_hasFontOptionWsAfterFontParam(BOX_FontOption arg)
{
  if (BOX_isFontOptionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasFontOptionWsAfterEquals(BOX_FontOption arg) */

ATbool BOX_hasFontOptionWsAfterEquals(BOX_FontOption arg)
{
  if (BOX_isFontOptionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasFontOptionFontValue(BOX_FontOption arg) */

ATbool BOX_hasFontOptionFontValue(BOX_FontOption arg)
{
  if (BOX_isFontOptionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_FontParam BOX_getFontOptionFontParam(BOX_FontOption arg) */

BOX_FontParam BOX_getFontOptionFontParam(BOX_FontOption arg)
{
  
    return (BOX_FontParam)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getFontOptionWsAfterFontParam(BOX_FontOption arg) */

BOX_OptLayout BOX_getFontOptionWsAfterFontParam(BOX_FontOption arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getFontOptionWsAfterEquals(BOX_FontOption arg) */

BOX_OptLayout BOX_getFontOptionWsAfterEquals(BOX_FontOption arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  BOX_FontValue BOX_getFontOptionFontValue(BOX_FontOption arg) */

BOX_FontValue BOX_getFontOptionFontValue(BOX_FontOption arg)
{
  
    return (BOX_FontValue)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  BOX_FontOption BOX_setFontOptionFontParam(BOX_FontOption arg, BOX_FontParam FontParam) */

BOX_FontOption BOX_setFontOptionFontParam(BOX_FontOption arg, BOX_FontParam FontParam)
{
  if (BOX_isFontOptionDefault(arg)) {
    return (BOX_FontOption)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) FontParam), 0), 1);
  }

  ATabort("FontOption has no FontParam: %t\n", arg);
  return (BOX_FontOption)NULL;
}

/*}}}  */
/*{{{  BOX_FontOption BOX_setFontOptionWsAfterFontParam(BOX_FontOption arg, BOX_OptLayout wsAfterFontParam) */

BOX_FontOption BOX_setFontOptionWsAfterFontParam(BOX_FontOption arg, BOX_OptLayout wsAfterFontParam)
{
  if (BOX_isFontOptionDefault(arg)) {
    return (BOX_FontOption)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterFontParam), 1), 1);
  }

  ATabort("FontOption has no WsAfterFontParam: %t\n", arg);
  return (BOX_FontOption)NULL;
}

/*}}}  */
/*{{{  BOX_FontOption BOX_setFontOptionWsAfterEquals(BOX_FontOption arg, BOX_OptLayout wsAfterEquals) */

BOX_FontOption BOX_setFontOptionWsAfterEquals(BOX_FontOption arg, BOX_OptLayout wsAfterEquals)
{
  if (BOX_isFontOptionDefault(arg)) {
    return (BOX_FontOption)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterEquals), 3), 1);
  }

  ATabort("FontOption has no WsAfterEquals: %t\n", arg);
  return (BOX_FontOption)NULL;
}

/*}}}  */
/*{{{  BOX_FontOption BOX_setFontOptionFontValue(BOX_FontOption arg, BOX_FontValue FontValue) */

BOX_FontOption BOX_setFontOptionFontValue(BOX_FontOption arg, BOX_FontValue FontValue)
{
  if (BOX_isFontOptionDefault(arg)) {
    return (BOX_FontOption)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) FontValue), 4), 1);
  }

  ATabort("FontOption has no FontValue: %t\n", arg);
  return (BOX_FontOption)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  BOX_FontOperator accessors */

/*{{{  ATbool BOX_isValidFontOperator(BOX_FontOperator arg) */

ATbool BOX_isValidFontOperator(BOX_FontOperator arg)
{
  if (BOX_isFontOperatorDefault(arg)) {
    return ATtrue;
  }
  else if (BOX_isFontOperatorKeyword(arg)) {
    return ATtrue;
  }
  else if (BOX_isFontOperatorVariable(arg)) {
    return ATtrue;
  }
  else if (BOX_isFontOperatorNumber(arg)) {
    return ATtrue;
  }
  else if (BOX_isFontOperatorMath(arg)) {
    return ATtrue;
  }
  else if (BOX_isFontOperatorEscape(arg)) {
    return ATtrue;
  }
  else if (BOX_isFontOperatorComment(arg)) {
    return ATtrue;
  }
  else if (BOX_isFontOperatorString(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool BOX_isFontOperatorDefault(BOX_FontOperator arg) */

inline ATbool BOX_isFontOperatorDefault(BOX_FontOperator arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternFontOperatorDefault, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isFontOperatorKeyword(BOX_FontOperator arg) */

inline ATbool BOX_isFontOperatorKeyword(BOX_FontOperator arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternFontOperatorKeyword);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isFontOperatorVariable(BOX_FontOperator arg) */

inline ATbool BOX_isFontOperatorVariable(BOX_FontOperator arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternFontOperatorVariable);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isFontOperatorNumber(BOX_FontOperator arg) */

inline ATbool BOX_isFontOperatorNumber(BOX_FontOperator arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternFontOperatorNumber);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isFontOperatorMath(BOX_FontOperator arg) */

inline ATbool BOX_isFontOperatorMath(BOX_FontOperator arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternFontOperatorMath);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isFontOperatorEscape(BOX_FontOperator arg) */

inline ATbool BOX_isFontOperatorEscape(BOX_FontOperator arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternFontOperatorEscape);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isFontOperatorComment(BOX_FontOperator arg) */

inline ATbool BOX_isFontOperatorComment(BOX_FontOperator arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternFontOperatorComment);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isFontOperatorString(BOX_FontOperator arg) */

inline ATbool BOX_isFontOperatorString(BOX_FontOperator arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternFontOperatorString);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool BOX_hasFontOperatorWsAfterF(BOX_FontOperator arg) */

ATbool BOX_hasFontOperatorWsAfterF(BOX_FontOperator arg)
{
  if (BOX_isFontOperatorDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasFontOperatorList(BOX_FontOperator arg) */

ATbool BOX_hasFontOperatorList(BOX_FontOperator arg)
{
  if (BOX_isFontOperatorDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getFontOperatorWsAfterF(BOX_FontOperator arg) */

BOX_OptLayout BOX_getFontOperatorWsAfterF(BOX_FontOperator arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  BOX_FontOptionList BOX_getFontOperatorList(BOX_FontOperator arg) */

BOX_FontOptionList BOX_getFontOperatorList(BOX_FontOperator arg)
{
  
    return (BOX_FontOptionList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), 1);
}

/*}}}  */
/*{{{  BOX_FontOperator BOX_setFontOperatorWsAfterF(BOX_FontOperator arg, BOX_OptLayout wsAfterF) */

BOX_FontOperator BOX_setFontOperatorWsAfterF(BOX_FontOperator arg, BOX_OptLayout wsAfterF)
{
  if (BOX_isFontOperatorDefault(arg)) {
    return (BOX_FontOperator)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterF), 1), 1);
  }

  ATabort("FontOperator has no WsAfterF: %t\n", arg);
  return (BOX_FontOperator)NULL;
}

/*}}}  */
/*{{{  BOX_FontOperator BOX_setFontOperatorList(BOX_FontOperator arg, BOX_FontOptionList list) */

BOX_FontOperator BOX_setFontOperatorList(BOX_FontOperator arg, BOX_FontOptionList list)
{
  if (BOX_isFontOperatorDefault(arg)) {
    return (BOX_FontOperator)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), (ATerm)((ATerm) list), 1), 2), 1);
  }

  ATabort("FontOperator has no List: %t\n", arg);
  return (BOX_FontOperator)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  BOX_Box accessors */

/*{{{  ATbool BOX_isValidBox(BOX_Box arg) */

ATbool BOX_isValidBox(BOX_Box arg)
{
  if (BOX_isBoxFontOperator(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxDefault(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxString(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxH(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxV(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxHv(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxHov(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxI(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxWd(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxAlignment(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxRow(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool BOX_isBoxFontOperator(BOX_Box arg) */

inline ATbool BOX_isBoxFontOperator(BOX_Box arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternBoxFontOperator, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isBoxDefault(BOX_Box arg) */

inline ATbool BOX_isBoxDefault(BOX_Box arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternBoxDefault, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isBoxString(BOX_Box arg) */

inline ATbool BOX_isBoxString(BOX_Box arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternBoxString, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isBoxH(BOX_Box arg) */

inline ATbool BOX_isBoxH(BOX_Box arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternBoxH, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isBoxV(BOX_Box arg) */

inline ATbool BOX_isBoxV(BOX_Box arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternBoxV, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isBoxHv(BOX_Box arg) */

inline ATbool BOX_isBoxHv(BOX_Box arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternBoxHv, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isBoxHov(BOX_Box arg) */

inline ATbool BOX_isBoxHov(BOX_Box arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternBoxHov, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isBoxI(BOX_Box arg) */

inline ATbool BOX_isBoxI(BOX_Box arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternBoxI, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isBoxWd(BOX_Box arg) */

inline ATbool BOX_isBoxWd(BOX_Box arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternBoxWd, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isBoxAlignment(BOX_Box arg) */

inline ATbool BOX_isBoxAlignment(BOX_Box arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternBoxAlignment, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isBoxRow(BOX_Box arg) */

inline ATbool BOX_isBoxRow(BOX_Box arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternBoxRow, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxFontOperator(BOX_Box arg) */

ATbool BOX_hasBoxFontOperator(BOX_Box arg)
{
  if (BOX_isBoxFontOperator(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxWsAfterFontOperator(BOX_Box arg) */

ATbool BOX_hasBoxWsAfterFontOperator(BOX_Box arg)
{
  if (BOX_isBoxFontOperator(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxWsAfterBracketOpen(BOX_Box arg) */

ATbool BOX_hasBoxWsAfterBracketOpen(BOX_Box arg)
{
  if (BOX_isBoxFontOperator(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxDefault(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxH(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxV(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxHv(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxHov(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxI(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxWd(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxAlignment(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxRow(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxBox(BOX_Box arg) */

ATbool BOX_hasBoxBox(BOX_Box arg)
{
  if (BOX_isBoxFontOperator(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxI(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxWd(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxWsAfterBox(BOX_Box arg) */

ATbool BOX_hasBoxWsAfterBox(BOX_Box arg)
{
  if (BOX_isBoxFontOperator(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxI(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxWd(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxWsAfterCOMM(BOX_Box arg) */

ATbool BOX_hasBoxWsAfterCOMM(BOX_Box arg)
{
  if (BOX_isBoxDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxList(BOX_Box arg) */

ATbool BOX_hasBoxList(BOX_Box arg)
{
  if (BOX_isBoxDefault(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxH(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxV(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxHv(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxHov(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxAlignment(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxRow(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxWsAfterList(BOX_Box arg) */

ATbool BOX_hasBoxWsAfterList(BOX_Box arg)
{
  if (BOX_isBoxDefault(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxH(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxV(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxHv(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxHov(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxAlignment(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxRow(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxStrCon(BOX_Box arg) */

ATbool BOX_hasBoxStrCon(BOX_Box arg)
{
  if (BOX_isBoxString(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxWsAfterH(BOX_Box arg) */

ATbool BOX_hasBoxWsAfterH(BOX_Box arg)
{
  if (BOX_isBoxH(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxOptions(BOX_Box arg) */

ATbool BOX_hasBoxOptions(BOX_Box arg)
{
  if (BOX_isBoxH(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxV(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxHv(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxHov(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxI(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxAlignment(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxWsAfterOptions(BOX_Box arg) */

ATbool BOX_hasBoxWsAfterOptions(BOX_Box arg)
{
  if (BOX_isBoxH(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxV(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxHv(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxHov(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxI(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxAlignment(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxWsAfterV(BOX_Box arg) */

ATbool BOX_hasBoxWsAfterV(BOX_Box arg)
{
  if (BOX_isBoxV(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxWsAfterHV(BOX_Box arg) */

ATbool BOX_hasBoxWsAfterHV(BOX_Box arg)
{
  if (BOX_isBoxHv(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxWsAfterHOV(BOX_Box arg) */

ATbool BOX_hasBoxWsAfterHOV(BOX_Box arg)
{
  if (BOX_isBoxHov(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxWsAfterI(BOX_Box arg) */

ATbool BOX_hasBoxWsAfterI(BOX_Box arg)
{
  if (BOX_isBoxI(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxWsAfterWD(BOX_Box arg) */

ATbool BOX_hasBoxWsAfterWD(BOX_Box arg)
{
  if (BOX_isBoxWd(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxWsAfterA(BOX_Box arg) */

ATbool BOX_hasBoxWsAfterA(BOX_Box arg)
{
  if (BOX_isBoxAlignment(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxAlignments(BOX_Box arg) */

ATbool BOX_hasBoxAlignments(BOX_Box arg)
{
  if (BOX_isBoxAlignment(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxWsAfterAlignments(BOX_Box arg) */

ATbool BOX_hasBoxWsAfterAlignments(BOX_Box arg)
{
  if (BOX_isBoxAlignment(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxWsAfterR(BOX_Box arg) */

ATbool BOX_hasBoxWsAfterR(BOX_Box arg)
{
  if (BOX_isBoxRow(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_FontOperator BOX_getBoxFontOperator(BOX_Box arg) */

BOX_FontOperator BOX_getBoxFontOperator(BOX_Box arg)
{
  
    return (BOX_FontOperator)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getBoxWsAfterFontOperator(BOX_Box arg) */

BOX_OptLayout BOX_getBoxWsAfterFontOperator(BOX_Box arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getBoxWsAfterBracketOpen(BOX_Box arg) */

BOX_OptLayout BOX_getBoxWsAfterBracketOpen(BOX_Box arg)
{
  if (BOX_isBoxFontOperator(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (BOX_isBoxDefault(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (BOX_isBoxH(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else if (BOX_isBoxV(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else if (BOX_isBoxHv(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else if (BOX_isBoxHov(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else if (BOX_isBoxI(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else if (BOX_isBoxWd(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (BOX_isBoxAlignment(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else 
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  BOX_Box BOX_getBoxBox(BOX_Box arg) */

BOX_Box BOX_getBoxBox(BOX_Box arg)
{
  if (BOX_isBoxFontOperator(arg)) {
    return (BOX_Box)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else if (BOX_isBoxI(arg)) {
    return (BOX_Box)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6);
  }
  else 
    return (BOX_Box)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getBoxWsAfterBox(BOX_Box arg) */

BOX_OptLayout BOX_getBoxWsAfterBox(BOX_Box arg)
{
  if (BOX_isBoxFontOperator(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else if (BOX_isBoxI(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else 
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getBoxWsAfterCOMM(BOX_Box arg) */

BOX_OptLayout BOX_getBoxWsAfterCOMM(BOX_Box arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  BOX_BoxList BOX_getBoxList(BOX_Box arg) */

BOX_BoxList BOX_getBoxList(BOX_Box arg)
{
  if (BOX_isBoxDefault(arg)) {
    return (BOX_BoxList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), 1);
  }
  else if (BOX_isBoxH(arg)) {
    return (BOX_BoxList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6), 1);
  }
  else if (BOX_isBoxV(arg)) {
    return (BOX_BoxList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6), 1);
  }
  else if (BOX_isBoxHv(arg)) {
    return (BOX_BoxList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6), 1);
  }
  else if (BOX_isBoxHov(arg)) {
    return (BOX_BoxList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6), 1);
  }
  else if (BOX_isBoxAlignment(arg)) {
    return (BOX_BoxList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8), 1);
  }
  else 
    return (BOX_BoxList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), 1);
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getBoxWsAfterList(BOX_Box arg) */

BOX_OptLayout BOX_getBoxWsAfterList(BOX_Box arg)
{
  if (BOX_isBoxDefault(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else if (BOX_isBoxH(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else if (BOX_isBoxV(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else if (BOX_isBoxHv(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else if (BOX_isBoxHov(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else if (BOX_isBoxAlignment(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
  }
  else 
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  BOX_StrCon BOX_getBoxStrCon(BOX_Box arg) */

BOX_StrCon BOX_getBoxStrCon(BOX_Box arg)
{
  
    return (BOX_StrCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getBoxWsAfterH(BOX_Box arg) */

BOX_OptLayout BOX_getBoxWsAfterH(BOX_Box arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  BOX_SpaceOptionOptions BOX_getBoxOptions(BOX_Box arg) */

BOX_SpaceOptionOptions BOX_getBoxOptions(BOX_Box arg)
{
  if (BOX_isBoxH(arg)) {
    return (BOX_SpaceOptionOptions)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), 1);
  }
  else if (BOX_isBoxV(arg)) {
    return (BOX_SpaceOptionOptions)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), 1);
  }
  else if (BOX_isBoxHv(arg)) {
    return (BOX_SpaceOptionOptions)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), 1);
  }
  else if (BOX_isBoxHov(arg)) {
    return (BOX_SpaceOptionOptions)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), 1);
  }
  else if (BOX_isBoxI(arg)) {
    return (BOX_SpaceOptionOptions)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), 1);
  }
  else 
    return (BOX_SpaceOptionOptions)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), 1);
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getBoxWsAfterOptions(BOX_Box arg) */

BOX_OptLayout BOX_getBoxWsAfterOptions(BOX_Box arg)
{
  if (BOX_isBoxH(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (BOX_isBoxV(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (BOX_isBoxHv(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (BOX_isBoxHov(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (BOX_isBoxI(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getBoxWsAfterV(BOX_Box arg) */

BOX_OptLayout BOX_getBoxWsAfterV(BOX_Box arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getBoxWsAfterHV(BOX_Box arg) */

BOX_OptLayout BOX_getBoxWsAfterHV(BOX_Box arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getBoxWsAfterHOV(BOX_Box arg) */

BOX_OptLayout BOX_getBoxWsAfterHOV(BOX_Box arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getBoxWsAfterI(BOX_Box arg) */

BOX_OptLayout BOX_getBoxWsAfterI(BOX_Box arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getBoxWsAfterWD(BOX_Box arg) */

BOX_OptLayout BOX_getBoxWsAfterWD(BOX_Box arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getBoxWsAfterA(BOX_Box arg) */

BOX_OptLayout BOX_getBoxWsAfterA(BOX_Box arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  BOX_AlignmentOptions BOX_getBoxAlignments(BOX_Box arg) */

BOX_AlignmentOptions BOX_getBoxAlignments(BOX_Box arg)
{
  
    return (BOX_AlignmentOptions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getBoxWsAfterAlignments(BOX_Box arg) */

BOX_OptLayout BOX_getBoxWsAfterAlignments(BOX_Box arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getBoxWsAfterR(BOX_Box arg) */

BOX_OptLayout BOX_getBoxWsAfterR(BOX_Box arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  BOX_Box BOX_setBoxFontOperator(BOX_Box arg, BOX_FontOperator FontOperator) */

BOX_Box BOX_setBoxFontOperator(BOX_Box arg, BOX_FontOperator FontOperator)
{
  if (BOX_isBoxFontOperator(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) FontOperator), 0), 1);
  }

  ATabort("Box has no FontOperator: %t\n", arg);
  return (BOX_Box)NULL;
}

/*}}}  */
/*{{{  BOX_Box BOX_setBoxWsAfterFontOperator(BOX_Box arg, BOX_OptLayout wsAfterFontOperator) */

BOX_Box BOX_setBoxWsAfterFontOperator(BOX_Box arg, BOX_OptLayout wsAfterFontOperator)
{
  if (BOX_isBoxFontOperator(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterFontOperator), 1), 1);
  }

  ATabort("Box has no WsAfterFontOperator: %t\n", arg);
  return (BOX_Box)NULL;
}

/*}}}  */
/*{{{  BOX_Box BOX_setBoxWsAfterBracketOpen(BOX_Box arg, BOX_OptLayout wsAfterBracketOpen) */

BOX_Box BOX_setBoxWsAfterBracketOpen(BOX_Box arg, BOX_OptLayout wsAfterBracketOpen)
{
  if (BOX_isBoxFontOperator(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 3), 1);
  }
  else if (BOX_isBoxDefault(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 3), 1);
  }
  else if (BOX_isBoxH(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 5), 1);
  }
  else if (BOX_isBoxV(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 5), 1);
  }
  else if (BOX_isBoxHv(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 5), 1);
  }
  else if (BOX_isBoxHov(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 5), 1);
  }
  else if (BOX_isBoxI(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 5), 1);
  }
  else if (BOX_isBoxWd(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 3), 1);
  }
  else if (BOX_isBoxAlignment(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 7), 1);
  }
  else if (BOX_isBoxRow(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 3), 1);
  }

  ATabort("Box has no WsAfterBracketOpen: %t\n", arg);
  return (BOX_Box)NULL;
}

/*}}}  */
/*{{{  BOX_Box BOX_setBoxBox(BOX_Box arg, BOX_Box Box) */

BOX_Box BOX_setBoxBox(BOX_Box arg, BOX_Box Box)
{
  if (BOX_isBoxFontOperator(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Box), 4), 1);
  }
  else if (BOX_isBoxI(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Box), 6), 1);
  }
  else if (BOX_isBoxWd(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Box), 4), 1);
  }

  ATabort("Box has no Box: %t\n", arg);
  return (BOX_Box)NULL;
}

/*}}}  */
/*{{{  BOX_Box BOX_setBoxWsAfterBox(BOX_Box arg, BOX_OptLayout wsAfterBox) */

BOX_Box BOX_setBoxWsAfterBox(BOX_Box arg, BOX_OptLayout wsAfterBox)
{
  if (BOX_isBoxFontOperator(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBox), 5), 1);
  }
  else if (BOX_isBoxI(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBox), 7), 1);
  }
  else if (BOX_isBoxWd(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBox), 5), 1);
  }

  ATabort("Box has no WsAfterBox: %t\n", arg);
  return (BOX_Box)NULL;
}

/*}}}  */
/*{{{  BOX_Box BOX_setBoxWsAfterCOMM(BOX_Box arg, BOX_OptLayout wsAfterCOMM) */

BOX_Box BOX_setBoxWsAfterCOMM(BOX_Box arg, BOX_OptLayout wsAfterCOMM)
{
  if (BOX_isBoxDefault(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterCOMM), 1), 1);
  }

  ATabort("Box has no WsAfterCOMM: %t\n", arg);
  return (BOX_Box)NULL;
}

/*}}}  */
/*{{{  BOX_Box BOX_setBoxList(BOX_Box arg, BOX_BoxList list) */

BOX_Box BOX_setBoxList(BOX_Box arg, BOX_BoxList list)
{
  if (BOX_isBoxDefault(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), (ATerm)((ATerm) list), 1), 4), 1);
  }
  else if (BOX_isBoxH(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6), (ATerm)((ATerm) list), 1), 6), 1);
  }
  else if (BOX_isBoxV(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6), (ATerm)((ATerm) list), 1), 6), 1);
  }
  else if (BOX_isBoxHv(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6), (ATerm)((ATerm) list), 1), 6), 1);
  }
  else if (BOX_isBoxHov(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6), (ATerm)((ATerm) list), 1), 6), 1);
  }
  else if (BOX_isBoxAlignment(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8), (ATerm)((ATerm) list), 1), 8), 1);
  }
  else if (BOX_isBoxRow(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), (ATerm)((ATerm) list), 1), 4), 1);
  }

  ATabort("Box has no List: %t\n", arg);
  return (BOX_Box)NULL;
}

/*}}}  */
/*{{{  BOX_Box BOX_setBoxWsAfterList(BOX_Box arg, BOX_OptLayout wsAfterList) */

BOX_Box BOX_setBoxWsAfterList(BOX_Box arg, BOX_OptLayout wsAfterList)
{
  if (BOX_isBoxDefault(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterList), 5), 1);
  }
  else if (BOX_isBoxH(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterList), 7), 1);
  }
  else if (BOX_isBoxV(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterList), 7), 1);
  }
  else if (BOX_isBoxHv(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterList), 7), 1);
  }
  else if (BOX_isBoxHov(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterList), 7), 1);
  }
  else if (BOX_isBoxAlignment(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterList), 9), 1);
  }
  else if (BOX_isBoxRow(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterList), 5), 1);
  }

  ATabort("Box has no WsAfterList: %t\n", arg);
  return (BOX_Box)NULL;
}

/*}}}  */
/*{{{  BOX_Box BOX_setBoxStrCon(BOX_Box arg, BOX_StrCon StrCon) */

BOX_Box BOX_setBoxStrCon(BOX_Box arg, BOX_StrCon StrCon)
{
  if (BOX_isBoxString(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) StrCon), 0), 1);
  }

  ATabort("Box has no StrCon: %t\n", arg);
  return (BOX_Box)NULL;
}

/*}}}  */
/*{{{  BOX_Box BOX_setBoxWsAfterH(BOX_Box arg, BOX_OptLayout wsAfterH) */

BOX_Box BOX_setBoxWsAfterH(BOX_Box arg, BOX_OptLayout wsAfterH)
{
  if (BOX_isBoxH(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterH), 1), 1);
  }

  ATabort("Box has no WsAfterH: %t\n", arg);
  return (BOX_Box)NULL;
}

/*}}}  */
/*{{{  BOX_Box BOX_setBoxOptions(BOX_Box arg, BOX_SpaceOptionOptions options) */

BOX_Box BOX_setBoxOptions(BOX_Box arg, BOX_SpaceOptionOptions options)
{
  if (BOX_isBoxH(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), (ATerm)((ATerm) options), 1), 2), 1);
  }
  else if (BOX_isBoxV(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), (ATerm)((ATerm) options), 1), 2), 1);
  }
  else if (BOX_isBoxHv(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), (ATerm)((ATerm) options), 1), 2), 1);
  }
  else if (BOX_isBoxHov(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), (ATerm)((ATerm) options), 1), 2), 1);
  }
  else if (BOX_isBoxI(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), (ATerm)((ATerm) options), 1), 2), 1);
  }
  else if (BOX_isBoxAlignment(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4), (ATerm)((ATerm) options), 1), 4), 1);
  }

  ATabort("Box has no Options: %t\n", arg);
  return (BOX_Box)NULL;
}

/*}}}  */
/*{{{  BOX_Box BOX_setBoxWsAfterOptions(BOX_Box arg, BOX_OptLayout wsAfterOptions) */

BOX_Box BOX_setBoxWsAfterOptions(BOX_Box arg, BOX_OptLayout wsAfterOptions)
{
  if (BOX_isBoxH(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterOptions), 3), 1);
  }
  else if (BOX_isBoxV(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterOptions), 3), 1);
  }
  else if (BOX_isBoxHv(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterOptions), 3), 1);
  }
  else if (BOX_isBoxHov(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterOptions), 3), 1);
  }
  else if (BOX_isBoxI(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterOptions), 3), 1);
  }
  else if (BOX_isBoxAlignment(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterOptions), 5), 1);
  }

  ATabort("Box has no WsAfterOptions: %t\n", arg);
  return (BOX_Box)NULL;
}

/*}}}  */
/*{{{  BOX_Box BOX_setBoxWsAfterV(BOX_Box arg, BOX_OptLayout wsAfterV) */

BOX_Box BOX_setBoxWsAfterV(BOX_Box arg, BOX_OptLayout wsAfterV)
{
  if (BOX_isBoxV(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterV), 1), 1);
  }

  ATabort("Box has no WsAfterV: %t\n", arg);
  return (BOX_Box)NULL;
}

/*}}}  */
/*{{{  BOX_Box BOX_setBoxWsAfterHV(BOX_Box arg, BOX_OptLayout wsAfterHV) */

BOX_Box BOX_setBoxWsAfterHV(BOX_Box arg, BOX_OptLayout wsAfterHV)
{
  if (BOX_isBoxHv(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterHV), 1), 1);
  }

  ATabort("Box has no WsAfterHV: %t\n", arg);
  return (BOX_Box)NULL;
}

/*}}}  */
/*{{{  BOX_Box BOX_setBoxWsAfterHOV(BOX_Box arg, BOX_OptLayout wsAfterHOV) */

BOX_Box BOX_setBoxWsAfterHOV(BOX_Box arg, BOX_OptLayout wsAfterHOV)
{
  if (BOX_isBoxHov(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterHOV), 1), 1);
  }

  ATabort("Box has no WsAfterHOV: %t\n", arg);
  return (BOX_Box)NULL;
}

/*}}}  */
/*{{{  BOX_Box BOX_setBoxWsAfterI(BOX_Box arg, BOX_OptLayout wsAfterI) */

BOX_Box BOX_setBoxWsAfterI(BOX_Box arg, BOX_OptLayout wsAfterI)
{
  if (BOX_isBoxI(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterI), 1), 1);
  }

  ATabort("Box has no WsAfterI: %t\n", arg);
  return (BOX_Box)NULL;
}

/*}}}  */
/*{{{  BOX_Box BOX_setBoxWsAfterWD(BOX_Box arg, BOX_OptLayout wsAfterWD) */

BOX_Box BOX_setBoxWsAfterWD(BOX_Box arg, BOX_OptLayout wsAfterWD)
{
  if (BOX_isBoxWd(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterWD), 1), 1);
  }

  ATabort("Box has no WsAfterWD: %t\n", arg);
  return (BOX_Box)NULL;
}

/*}}}  */
/*{{{  BOX_Box BOX_setBoxWsAfterA(BOX_Box arg, BOX_OptLayout wsAfterA) */

BOX_Box BOX_setBoxWsAfterA(BOX_Box arg, BOX_OptLayout wsAfterA)
{
  if (BOX_isBoxAlignment(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterA), 1), 1);
  }

  ATabort("Box has no WsAfterA: %t\n", arg);
  return (BOX_Box)NULL;
}

/*}}}  */
/*{{{  BOX_Box BOX_setBoxAlignments(BOX_Box arg, BOX_AlignmentOptions alignments) */

BOX_Box BOX_setBoxAlignments(BOX_Box arg, BOX_AlignmentOptions alignments)
{
  if (BOX_isBoxAlignment(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) alignments), 2), 1);
  }

  ATabort("Box has no Alignments: %t\n", arg);
  return (BOX_Box)NULL;
}

/*}}}  */
/*{{{  BOX_Box BOX_setBoxWsAfterAlignments(BOX_Box arg, BOX_OptLayout wsAfterAlignments) */

BOX_Box BOX_setBoxWsAfterAlignments(BOX_Box arg, BOX_OptLayout wsAfterAlignments)
{
  if (BOX_isBoxAlignment(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterAlignments), 3), 1);
  }

  ATabort("Box has no WsAfterAlignments: %t\n", arg);
  return (BOX_Box)NULL;
}

/*}}}  */
/*{{{  BOX_Box BOX_setBoxWsAfterR(BOX_Box arg, BOX_OptLayout wsAfterR) */

BOX_Box BOX_setBoxWsAfterR(BOX_Box arg, BOX_OptLayout wsAfterR)
{
  if (BOX_isBoxRow(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterR), 1), 1);
  }

  ATabort("Box has no WsAfterR: %t\n", arg);
  return (BOX_Box)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  BOX_FontParam accessors */

/*{{{  ATbool BOX_isValidFontParam(BOX_FontParam arg) */

ATbool BOX_isValidFontParam(BOX_FontParam arg)
{
  if (BOX_isFontParamName(arg)) {
    return ATtrue;
  }
  else if (BOX_isFontParamFamily(arg)) {
    return ATtrue;
  }
  else if (BOX_isFontParamSeries(arg)) {
    return ATtrue;
  }
  else if (BOX_isFontParamShape(arg)) {
    return ATtrue;
  }
  else if (BOX_isFontParamSize(arg)) {
    return ATtrue;
  }
  else if (BOX_isFontParamColor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool BOX_isFontParamName(BOX_FontParam arg) */

inline ATbool BOX_isFontParamName(BOX_FontParam arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternFontParamName);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isFontParamFamily(BOX_FontParam arg) */

inline ATbool BOX_isFontParamFamily(BOX_FontParam arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternFontParamFamily);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isFontParamSeries(BOX_FontParam arg) */

inline ATbool BOX_isFontParamSeries(BOX_FontParam arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternFontParamSeries);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isFontParamShape(BOX_FontParam arg) */

inline ATbool BOX_isFontParamShape(BOX_FontParam arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternFontParamShape);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isFontParamSize(BOX_FontParam arg) */

inline ATbool BOX_isFontParamSize(BOX_FontParam arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternFontParamSize);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isFontParamColor(BOX_FontParam arg) */

inline ATbool BOX_isFontParamColor(BOX_FontParam arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternFontParamColor);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */

/*}}}  */
/*{{{  BOX_FontOptionList accessors */

/*{{{  ATbool BOX_isValidFontOptionList(BOX_FontOptionList arg) */

ATbool BOX_isValidFontOptionList(BOX_FontOptionList arg)
{
  if (BOX_isFontOptionListEmpty(arg)) {
    return ATtrue;
  }
  else if (BOX_isFontOptionListSingle(arg)) {
    return ATtrue;
  }
  else if (BOX_isFontOptionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool BOX_isFontOptionListEmpty(BOX_FontOptionList arg) */

inline ATbool BOX_isFontOptionListEmpty(BOX_FontOptionList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, BOX_patternFontOptionListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool BOX_isFontOptionListSingle(BOX_FontOptionList arg) */

inline ATbool BOX_isFontOptionListSingle(BOX_FontOptionList arg)
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
      last_result = ATmatchTerm((ATerm)arg, BOX_patternFontOptionListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isFontOptionListMany(BOX_FontOptionList arg) */

inline ATbool BOX_isFontOptionListMany(BOX_FontOptionList arg)
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
      last_result = ATmatchTerm((ATerm)arg, BOX_patternFontOptionListMany, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool BOX_hasFontOptionListHead(BOX_FontOptionList arg) */

ATbool BOX_hasFontOptionListHead(BOX_FontOptionList arg)
{
  if (BOX_isFontOptionListSingle(arg)) {
    return ATtrue;
  }
  else if (BOX_isFontOptionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasFontOptionListWsAfterHead(BOX_FontOptionList arg) */

ATbool BOX_hasFontOptionListWsAfterHead(BOX_FontOptionList arg)
{
  if (BOX_isFontOptionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasFontOptionListTail(BOX_FontOptionList arg) */

ATbool BOX_hasFontOptionListTail(BOX_FontOptionList arg)
{
  if (BOX_isFontOptionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_FontOptionList BOX_getFontOptionListTail(BOX_FontOptionList arg) */

BOX_FontOptionList BOX_getFontOptionListTail(BOX_FontOptionList arg)
{
  assert(!BOX_isFontOptionListEmpty(arg) && "getTail on an empty list");
  if (BOX_isFontOptionListSingle(arg)) {
    return (BOX_FontOptionList) BOX_makeFontOptionListEmpty();
  }
  else {
  
    return (BOX_FontOptionList)ATgetTail((ATermList)arg, 2);
  }
}

/*}}}  */
/*{{{  BOX_FontOption BOX_getFontOptionListHead(BOX_FontOptionList arg) */

BOX_FontOption BOX_getFontOptionListHead(BOX_FontOptionList arg)
{
  if (BOX_isFontOptionListSingle(arg)) {
    return (BOX_FontOption)ATgetFirst((ATermList)arg);
  }
  else 
    return (BOX_FontOption)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getFontOptionListWsAfterHead(BOX_FontOptionList arg) */

BOX_OptLayout BOX_getFontOptionListWsAfterHead(BOX_FontOptionList arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  BOX_FontOptionList BOX_setFontOptionListHead(BOX_FontOptionList arg, BOX_FontOption head) */

BOX_FontOptionList BOX_setFontOptionListHead(BOX_FontOptionList arg, BOX_FontOption head)
{
  if (BOX_isFontOptionListSingle(arg)) {
    return (BOX_FontOptionList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (BOX_isFontOptionListMany(arg)) {
    return (BOX_FontOptionList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("FontOptionList has no Head: %t\n", arg);
  return (BOX_FontOptionList)NULL;
}

/*}}}  */
/*{{{  BOX_FontOptionList BOX_setFontOptionListWsAfterHead(BOX_FontOptionList arg, BOX_OptLayout wsAfterHead) */

BOX_FontOptionList BOX_setFontOptionListWsAfterHead(BOX_FontOptionList arg, BOX_OptLayout wsAfterHead)
{
  if (BOX_isFontOptionListMany(arg)) {
    return (BOX_FontOptionList)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterHead), 1);
  }

  ATabort("FontOptionList has no WsAfterHead: %t\n", arg);
  return (BOX_FontOptionList)NULL;
}

/*}}}  */
/*{{{  BOX_FontOptionList BOX_setFontOptionListTail(BOX_FontOptionList arg, BOX_FontOptionList tail) */

BOX_FontOptionList BOX_setFontOptionListTail(BOX_FontOptionList arg, BOX_FontOptionList tail)
{
  if (BOX_isFontOptionListMany(arg)) {
    return (BOX_FontOptionList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 2);
  }

  ATabort("FontOptionList has no Tail: %t\n", arg);
  return (BOX_FontOptionList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  BOX_BoxList accessors */

/*{{{  ATbool BOX_isValidBoxList(BOX_BoxList arg) */

ATbool BOX_isValidBoxList(BOX_BoxList arg)
{
  if (BOX_isBoxListEmpty(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxListSingle(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool BOX_isBoxListEmpty(BOX_BoxList arg) */

inline ATbool BOX_isBoxListEmpty(BOX_BoxList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, BOX_patternBoxListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool BOX_isBoxListSingle(BOX_BoxList arg) */

inline ATbool BOX_isBoxListSingle(BOX_BoxList arg)
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
      last_result = ATmatchTerm((ATerm)arg, BOX_patternBoxListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isBoxListMany(BOX_BoxList arg) */

inline ATbool BOX_isBoxListMany(BOX_BoxList arg)
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
      last_result = ATmatchTerm((ATerm)arg, BOX_patternBoxListMany, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxListHead(BOX_BoxList arg) */

ATbool BOX_hasBoxListHead(BOX_BoxList arg)
{
  if (BOX_isBoxListSingle(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxListWsAfterHead(BOX_BoxList arg) */

ATbool BOX_hasBoxListWsAfterHead(BOX_BoxList arg)
{
  if (BOX_isBoxListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxListTail(BOX_BoxList arg) */

ATbool BOX_hasBoxListTail(BOX_BoxList arg)
{
  if (BOX_isBoxListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_BoxList BOX_getBoxListTail(BOX_BoxList arg) */

BOX_BoxList BOX_getBoxListTail(BOX_BoxList arg)
{
  assert(!BOX_isBoxListEmpty(arg) && "getTail on an empty list");
  if (BOX_isBoxListSingle(arg)) {
    return (BOX_BoxList) BOX_makeBoxListEmpty();
  }
  else {
  
    return (BOX_BoxList)ATgetTail((ATermList)arg, 2);
  }
}

/*}}}  */
/*{{{  BOX_Box BOX_getBoxListHead(BOX_BoxList arg) */

BOX_Box BOX_getBoxListHead(BOX_BoxList arg)
{
  if (BOX_isBoxListSingle(arg)) {
    return (BOX_Box)ATgetFirst((ATermList)arg);
  }
  else 
    return (BOX_Box)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getBoxListWsAfterHead(BOX_BoxList arg) */

BOX_OptLayout BOX_getBoxListWsAfterHead(BOX_BoxList arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  BOX_BoxList BOX_setBoxListHead(BOX_BoxList arg, BOX_Box head) */

BOX_BoxList BOX_setBoxListHead(BOX_BoxList arg, BOX_Box head)
{
  if (BOX_isBoxListSingle(arg)) {
    return (BOX_BoxList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (BOX_isBoxListMany(arg)) {
    return (BOX_BoxList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("BoxList has no Head: %t\n", arg);
  return (BOX_BoxList)NULL;
}

/*}}}  */
/*{{{  BOX_BoxList BOX_setBoxListWsAfterHead(BOX_BoxList arg, BOX_OptLayout wsAfterHead) */

BOX_BoxList BOX_setBoxListWsAfterHead(BOX_BoxList arg, BOX_OptLayout wsAfterHead)
{
  if (BOX_isBoxListMany(arg)) {
    return (BOX_BoxList)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterHead), 1);
  }

  ATabort("BoxList has no WsAfterHead: %t\n", arg);
  return (BOX_BoxList)NULL;
}

/*}}}  */
/*{{{  BOX_BoxList BOX_setBoxListTail(BOX_BoxList arg, BOX_BoxList tail) */

BOX_BoxList BOX_setBoxListTail(BOX_BoxList arg, BOX_BoxList tail)
{
  if (BOX_isBoxListMany(arg)) {
    return (BOX_BoxList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 2);
  }

  ATabort("BoxList has no Tail: %t\n", arg);
  return (BOX_BoxList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  BOX_LexNatCon accessors */

/*{{{  ATbool BOX_isValidLexNatCon(BOX_LexNatCon arg) */

ATbool BOX_isValidLexNatCon(BOX_LexNatCon arg)
{
  if (BOX_isLexNatConDigits(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool BOX_isLexNatConDigits(BOX_LexNatCon arg) */

inline ATbool BOX_isLexNatConDigits(BOX_LexNatCon arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, BOX_patternLexNatConDigits, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool BOX_hasLexNatConList(BOX_LexNatCon arg) */

ATbool BOX_hasLexNatConList(BOX_LexNatCon arg)
{
  if (BOX_isLexNatConDigits(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* BOX_getLexNatConList(BOX_LexNatCon arg) */

char* BOX_getLexNatConList(BOX_LexNatCon arg)
{
  
    return (char*)BOX_charsToString((ATerm)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1));
}

/*}}}  */
/*{{{  BOX_LexNatCon BOX_setLexNatConList(BOX_LexNatCon arg, const char* list) */

BOX_LexNatCon BOX_setLexNatConList(BOX_LexNatCon arg, const char* list)
{
  if (BOX_isLexNatConDigits(arg)) {
    return (BOX_LexNatCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) ((ATerm) BOX_stringToChars(list))), 1), 0), 1);
  }

  ATabort("LexNatCon has no List: %t\n", arg);
  return (BOX_LexNatCon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  BOX_NatCon accessors */

/*{{{  ATbool BOX_isValidNatCon(BOX_NatCon arg) */

ATbool BOX_isValidNatCon(BOX_NatCon arg)
{
  if (BOX_isNatConLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool BOX_isNatConLexToCf(BOX_NatCon arg) */

inline ATbool BOX_isNatConLexToCf(BOX_NatCon arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, BOX_patternNatConLexToCf, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool BOX_hasNatConNatCon(BOX_NatCon arg) */

ATbool BOX_hasNatConNatCon(BOX_NatCon arg)
{
  if (BOX_isNatConLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_LexNatCon BOX_getNatConNatCon(BOX_NatCon arg) */

BOX_LexNatCon BOX_getNatConNatCon(BOX_NatCon arg)
{
  
    return (BOX_LexNatCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  BOX_NatCon BOX_setNatConNatCon(BOX_NatCon arg, BOX_LexNatCon NatCon) */

BOX_NatCon BOX_setNatConNatCon(BOX_NatCon arg, BOX_LexNatCon NatCon)
{
  if (BOX_isNatConLexToCf(arg)) {
    return (BOX_NatCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) NatCon), 0), 1);
  }

  ATabort("NatCon has no NatCon: %t\n", arg);
  return (BOX_NatCon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  BOX_LexStrChar accessors */

/*{{{  ATbool BOX_isValidLexStrChar(BOX_LexStrChar arg) */

ATbool BOX_isValidLexStrChar(BOX_LexStrChar arg)
{
  if (BOX_isLexStrCharNewline(arg)) {
    return ATtrue;
  }
  else if (BOX_isLexStrCharTab(arg)) {
    return ATtrue;
  }
  else if (BOX_isLexStrCharQuote(arg)) {
    return ATtrue;
  }
  else if (BOX_isLexStrCharBackslash(arg)) {
    return ATtrue;
  }
  else if (BOX_isLexStrCharDecimal(arg)) {
    return ATtrue;
  }
  else if (BOX_isLexStrCharNormal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool BOX_isLexStrCharNewline(BOX_LexStrChar arg) */

inline ATbool BOX_isLexStrCharNewline(BOX_LexStrChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternLexStrCharNewline);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isLexStrCharTab(BOX_LexStrChar arg) */

inline ATbool BOX_isLexStrCharTab(BOX_LexStrChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternLexStrCharTab);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isLexStrCharQuote(BOX_LexStrChar arg) */

inline ATbool BOX_isLexStrCharQuote(BOX_LexStrChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternLexStrCharQuote);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isLexStrCharBackslash(BOX_LexStrChar arg) */

inline ATbool BOX_isLexStrCharBackslash(BOX_LexStrChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternLexStrCharBackslash);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isLexStrCharDecimal(BOX_LexStrChar arg) */

inline ATbool BOX_isLexStrCharDecimal(BOX_LexStrChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternLexStrCharDecimal, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isLexStrCharNormal(BOX_LexStrChar arg) */

inline ATbool BOX_isLexStrCharNormal(BOX_LexStrChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternLexStrCharNormal, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool BOX_hasLexStrCharA(BOX_LexStrChar arg) */

ATbool BOX_hasLexStrCharA(BOX_LexStrChar arg)
{
  if (BOX_isLexStrCharDecimal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasLexStrCharB(BOX_LexStrChar arg) */

ATbool BOX_hasLexStrCharB(BOX_LexStrChar arg)
{
  if (BOX_isLexStrCharDecimal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasLexStrCharC(BOX_LexStrChar arg) */

ATbool BOX_hasLexStrCharC(BOX_LexStrChar arg)
{
  if (BOX_isLexStrCharDecimal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasLexStrCharCh(BOX_LexStrChar arg) */

ATbool BOX_hasLexStrCharCh(BOX_LexStrChar arg)
{
  if (BOX_isLexStrCharNormal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char BOX_getLexStrCharA(BOX_LexStrChar arg) */

char BOX_getLexStrCharA(BOX_LexStrChar arg)
{
  
    return (char)BOX_charToByte((ATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1));
}

/*}}}  */
/*{{{  char BOX_getLexStrCharB(BOX_LexStrChar arg) */

char BOX_getLexStrCharB(BOX_LexStrChar arg)
{
  
    return (char)BOX_charToByte((ATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2));
}

/*}}}  */
/*{{{  char BOX_getLexStrCharC(BOX_LexStrChar arg) */

char BOX_getLexStrCharC(BOX_LexStrChar arg)
{
  
    return (char)BOX_charToByte((ATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3));
}

/*}}}  */
/*{{{  char BOX_getLexStrCharCh(BOX_LexStrChar arg) */

char BOX_getLexStrCharCh(BOX_LexStrChar arg)
{
  
    return (char)BOX_charToByte((ATerm)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  BOX_LexStrChar BOX_setLexStrCharA(BOX_LexStrChar arg, char a) */

BOX_LexStrChar BOX_setLexStrCharA(BOX_LexStrChar arg, char a)
{
  if (BOX_isLexStrCharDecimal(arg)) {
    return (BOX_LexStrChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) BOX_byteToChar(a))), 1), 1);
  }

  ATabort("LexStrChar has no A: %t\n", arg);
  return (BOX_LexStrChar)NULL;
}

/*}}}  */
/*{{{  BOX_LexStrChar BOX_setLexStrCharB(BOX_LexStrChar arg, char b) */

BOX_LexStrChar BOX_setLexStrCharB(BOX_LexStrChar arg, char b)
{
  if (BOX_isLexStrCharDecimal(arg)) {
    return (BOX_LexStrChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) BOX_byteToChar(b))), 2), 1);
  }

  ATabort("LexStrChar has no B: %t\n", arg);
  return (BOX_LexStrChar)NULL;
}

/*}}}  */
/*{{{  BOX_LexStrChar BOX_setLexStrCharC(BOX_LexStrChar arg, char c) */

BOX_LexStrChar BOX_setLexStrCharC(BOX_LexStrChar arg, char c)
{
  if (BOX_isLexStrCharDecimal(arg)) {
    return (BOX_LexStrChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) BOX_byteToChar(c))), 3), 1);
  }

  ATabort("LexStrChar has no C: %t\n", arg);
  return (BOX_LexStrChar)NULL;
}

/*}}}  */
/*{{{  BOX_LexStrChar BOX_setLexStrCharCh(BOX_LexStrChar arg, char ch) */

BOX_LexStrChar BOX_setLexStrCharCh(BOX_LexStrChar arg, char ch)
{
  if (BOX_isLexStrCharNormal(arg)) {
    return (BOX_LexStrChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) BOX_byteToChar(ch))), 0), 1);
  }

  ATabort("LexStrChar has no Ch: %t\n", arg);
  return (BOX_LexStrChar)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  BOX_StrChar accessors */

/*{{{  ATbool BOX_isValidStrChar(BOX_StrChar arg) */

ATbool BOX_isValidStrChar(BOX_StrChar arg)
{
  if (BOX_isStrCharLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool BOX_isStrCharLexToCf(BOX_StrChar arg) */

inline ATbool BOX_isStrCharLexToCf(BOX_StrChar arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, BOX_patternStrCharLexToCf, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool BOX_hasStrCharStrChar(BOX_StrChar arg) */

ATbool BOX_hasStrCharStrChar(BOX_StrChar arg)
{
  if (BOX_isStrCharLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_LexStrChar BOX_getStrCharStrChar(BOX_StrChar arg) */

BOX_LexStrChar BOX_getStrCharStrChar(BOX_StrChar arg)
{
  
    return (BOX_LexStrChar)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  BOX_StrChar BOX_setStrCharStrChar(BOX_StrChar arg, BOX_LexStrChar StrChar) */

BOX_StrChar BOX_setStrCharStrChar(BOX_StrChar arg, BOX_LexStrChar StrChar)
{
  if (BOX_isStrCharLexToCf(arg)) {
    return (BOX_StrChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) StrChar), 0), 1);
  }

  ATabort("StrChar has no StrChar: %t\n", arg);
  return (BOX_StrChar)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  BOX_LexStrCon accessors */

/*{{{  ATbool BOX_isValidLexStrCon(BOX_LexStrCon arg) */

ATbool BOX_isValidLexStrCon(BOX_LexStrCon arg)
{
  if (BOX_isLexStrConDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool BOX_isLexStrConDefault(BOX_LexStrCon arg) */

inline ATbool BOX_isLexStrConDefault(BOX_LexStrCon arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, BOX_patternLexStrConDefault, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool BOX_hasLexStrConChars(BOX_LexStrCon arg) */

ATbool BOX_hasLexStrConChars(BOX_LexStrCon arg)
{
  if (BOX_isLexStrConDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_LexStrCharChars BOX_getLexStrConChars(BOX_LexStrCon arg) */

BOX_LexStrCharChars BOX_getLexStrConChars(BOX_LexStrCon arg)
{
  
    return (BOX_LexStrCharChars)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1), 1);
}

/*}}}  */
/*{{{  BOX_LexStrCon BOX_setLexStrConChars(BOX_LexStrCon arg, BOX_LexStrCharChars chars) */

BOX_LexStrCon BOX_setLexStrConChars(BOX_LexStrCon arg, BOX_LexStrCharChars chars)
{
  if (BOX_isLexStrConDefault(arg)) {
    return (BOX_LexStrCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1), (ATerm)((ATerm) chars), 1), 1), 1);
  }

  ATabort("LexStrCon has no Chars: %t\n", arg);
  return (BOX_LexStrCon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  BOX_StrCon accessors */

/*{{{  ATbool BOX_isValidStrCon(BOX_StrCon arg) */

ATbool BOX_isValidStrCon(BOX_StrCon arg)
{
  if (BOX_isStrConLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool BOX_isStrConLexToCf(BOX_StrCon arg) */

inline ATbool BOX_isStrConLexToCf(BOX_StrCon arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, BOX_patternStrConLexToCf, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool BOX_hasStrConStrCon(BOX_StrCon arg) */

ATbool BOX_hasStrConStrCon(BOX_StrCon arg)
{
  if (BOX_isStrConLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_LexStrCon BOX_getStrConStrCon(BOX_StrCon arg) */

BOX_LexStrCon BOX_getStrConStrCon(BOX_StrCon arg)
{
  
    return (BOX_LexStrCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  BOX_StrCon BOX_setStrConStrCon(BOX_StrCon arg, BOX_LexStrCon StrCon) */

BOX_StrCon BOX_setStrConStrCon(BOX_StrCon arg, BOX_LexStrCon StrCon)
{
  if (BOX_isStrConLexToCf(arg)) {
    return (BOX_StrCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) StrCon), 0), 1);
  }

  ATabort("StrCon has no StrCon: %t\n", arg);
  return (BOX_StrCon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  BOX_LexStrCharChars accessors */

/*{{{  ATbool BOX_isValidLexStrCharChars(BOX_LexStrCharChars arg) */

ATbool BOX_isValidLexStrCharChars(BOX_LexStrCharChars arg)
{
  if (BOX_isLexStrCharCharsEmpty(arg)) {
    return ATtrue;
  }
  else if (BOX_isLexStrCharCharsSingle(arg)) {
    return ATtrue;
  }
  else if (BOX_isLexStrCharCharsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool BOX_isLexStrCharCharsEmpty(BOX_LexStrCharChars arg) */

inline ATbool BOX_isLexStrCharCharsEmpty(BOX_LexStrCharChars arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, BOX_patternLexStrCharCharsEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool BOX_isLexStrCharCharsSingle(BOX_LexStrCharChars arg) */

inline ATbool BOX_isLexStrCharCharsSingle(BOX_LexStrCharChars arg)
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
      last_result = ATmatchTerm((ATerm)arg, BOX_patternLexStrCharCharsSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isLexStrCharCharsMany(BOX_LexStrCharChars arg) */

inline ATbool BOX_isLexStrCharCharsMany(BOX_LexStrCharChars arg)
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
      last_result = ATmatchTerm((ATerm)arg, BOX_patternLexStrCharCharsMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool BOX_hasLexStrCharCharsHead(BOX_LexStrCharChars arg) */

ATbool BOX_hasLexStrCharCharsHead(BOX_LexStrCharChars arg)
{
  if (BOX_isLexStrCharCharsSingle(arg)) {
    return ATtrue;
  }
  else if (BOX_isLexStrCharCharsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasLexStrCharCharsTail(BOX_LexStrCharChars arg) */

ATbool BOX_hasLexStrCharCharsTail(BOX_LexStrCharChars arg)
{
  if (BOX_isLexStrCharCharsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_LexStrChar BOX_getLexStrCharCharsHead(BOX_LexStrCharChars arg) */

BOX_LexStrChar BOX_getLexStrCharCharsHead(BOX_LexStrCharChars arg)
{
  if (BOX_isLexStrCharCharsSingle(arg)) {
    return (BOX_LexStrChar)ATgetFirst((ATermList)arg);
  }
  else 
    return (BOX_LexStrChar)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  BOX_LexStrCharChars BOX_getLexStrCharCharsTail(BOX_LexStrCharChars arg) */

BOX_LexStrCharChars BOX_getLexStrCharCharsTail(BOX_LexStrCharChars arg)
{
  
    return (BOX_LexStrCharChars)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  BOX_LexStrCharChars BOX_setLexStrCharCharsHead(BOX_LexStrCharChars arg, BOX_LexStrChar head) */

BOX_LexStrCharChars BOX_setLexStrCharCharsHead(BOX_LexStrCharChars arg, BOX_LexStrChar head)
{
  if (BOX_isLexStrCharCharsSingle(arg)) {
    return (BOX_LexStrCharChars)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (BOX_isLexStrCharCharsMany(arg)) {
    return (BOX_LexStrCharChars)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("LexStrCharChars has no Head: %t\n", arg);
  return (BOX_LexStrCharChars)NULL;
}

/*}}}  */
/*{{{  BOX_LexStrCharChars BOX_setLexStrCharCharsTail(BOX_LexStrCharChars arg, BOX_LexStrCharChars tail) */

BOX_LexStrCharChars BOX_setLexStrCharCharsTail(BOX_LexStrCharChars arg, BOX_LexStrCharChars tail)
{
  if (BOX_isLexStrCharCharsMany(arg)) {
    return (BOX_LexStrCharChars)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("LexStrCharChars has no Tail: %t\n", arg);
  return (BOX_LexStrCharChars)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  BOX_LexLayout accessors */

/*{{{  ATbool BOX_isValidLexLayout(BOX_LexLayout arg) */

ATbool BOX_isValidLexLayout(BOX_LexLayout arg)
{
  if (BOX_isLexLayoutWhitespace(arg)) {
    return ATtrue;
  }
  else if (BOX_isLexLayoutLine(arg)) {
    return ATtrue;
  }
  else if (BOX_isLexLayoutNested(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool BOX_isLexLayoutWhitespace(BOX_LexLayout arg) */

inline ATbool BOX_isLexLayoutWhitespace(BOX_LexLayout arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternLexLayoutWhitespace, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isLexLayoutLine(BOX_LexLayout arg) */

inline ATbool BOX_isLexLayoutLine(BOX_LexLayout arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternLexLayoutLine, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isLexLayoutNested(BOX_LexLayout arg) */

inline ATbool BOX_isLexLayoutNested(BOX_LexLayout arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternLexLayoutNested, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool BOX_hasLexLayoutCh(BOX_LexLayout arg) */

ATbool BOX_hasLexLayoutCh(BOX_LexLayout arg)
{
  if (BOX_isLexLayoutWhitespace(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasLexLayoutLine(BOX_LexLayout arg) */

ATbool BOX_hasLexLayoutLine(BOX_LexLayout arg)
{
  if (BOX_isLexLayoutLine(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasLexLayoutContent(BOX_LexLayout arg) */

ATbool BOX_hasLexLayoutContent(BOX_LexLayout arg)
{
  if (BOX_isLexLayoutNested(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char BOX_getLexLayoutCh(BOX_LexLayout arg) */

char BOX_getLexLayoutCh(BOX_LexLayout arg)
{
  
    return (char)BOX_charToByte((ATerm)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  char* BOX_getLexLayoutLine(BOX_LexLayout arg) */

char* BOX_getLexLayoutLine(BOX_LexLayout arg)
{
  
    return (char*)BOX_charsToString((ATerm)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1), 1));
}

/*}}}  */
/*{{{  char* BOX_getLexLayoutContent(BOX_LexLayout arg) */

char* BOX_getLexLayoutContent(BOX_LexLayout arg)
{
  
    return (char*)BOX_charsToString((ATerm)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1), 1));
}

/*}}}  */
/*{{{  BOX_LexLayout BOX_setLexLayoutCh(BOX_LexLayout arg, char ch) */

BOX_LexLayout BOX_setLexLayoutCh(BOX_LexLayout arg, char ch)
{
  if (BOX_isLexLayoutWhitespace(arg)) {
    return (BOX_LexLayout)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) BOX_byteToChar(ch))), 0), 1);
  }

  ATabort("LexLayout has no Ch: %t\n", arg);
  return (BOX_LexLayout)NULL;
}

/*}}}  */
/*{{{  BOX_LexLayout BOX_setLexLayoutLine(BOX_LexLayout arg, const char* line) */

BOX_LexLayout BOX_setLexLayoutLine(BOX_LexLayout arg, const char* line)
{
  if (BOX_isLexLayoutLine(arg)) {
    return (BOX_LexLayout)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1), (ATerm)((ATerm) ((ATerm) BOX_stringToChars(line))), 1), 1), 1);
  }

  ATabort("LexLayout has no Line: %t\n", arg);
  return (BOX_LexLayout)NULL;
}

/*}}}  */
/*{{{  BOX_LexLayout BOX_setLexLayoutContent(BOX_LexLayout arg, const char* content) */

BOX_LexLayout BOX_setLexLayoutContent(BOX_LexLayout arg, const char* content)
{
  if (BOX_isLexLayoutNested(arg)) {
    return (BOX_LexLayout)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1), (ATerm)((ATerm) ((ATerm) BOX_stringToChars(content))), 1), 1), 1);
  }

  ATabort("LexLayout has no Content: %t\n", arg);
  return (BOX_LexLayout)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  BOX_SpaceSymbol accessors */

/*{{{  ATbool BOX_isValidSpaceSymbol(BOX_SpaceSymbol arg) */

ATbool BOX_isValidSpaceSymbol(BOX_SpaceSymbol arg)
{
  if (BOX_isSpaceSymbolHorizontal(arg)) {
    return ATtrue;
  }
  else if (BOX_isSpaceSymbolVertical(arg)) {
    return ATtrue;
  }
  else if (BOX_isSpaceSymbolIndentation(arg)) {
    return ATtrue;
  }
  else if (BOX_isSpaceSymbolTabstop(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool BOX_isSpaceSymbolHorizontal(BOX_SpaceSymbol arg) */

inline ATbool BOX_isSpaceSymbolHorizontal(BOX_SpaceSymbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternSpaceSymbolHorizontal);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isSpaceSymbolVertical(BOX_SpaceSymbol arg) */

inline ATbool BOX_isSpaceSymbolVertical(BOX_SpaceSymbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternSpaceSymbolVertical);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isSpaceSymbolIndentation(BOX_SpaceSymbol arg) */

inline ATbool BOX_isSpaceSymbolIndentation(BOX_SpaceSymbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternSpaceSymbolIndentation);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isSpaceSymbolTabstop(BOX_SpaceSymbol arg) */

inline ATbool BOX_isSpaceSymbolTabstop(BOX_SpaceSymbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternSpaceSymbolTabstop);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */

/*}}}  */
/*{{{  BOX_SpaceOption accessors */

/*{{{  ATbool BOX_isValidSpaceOption(BOX_SpaceOption arg) */

ATbool BOX_isValidSpaceOption(BOX_SpaceOption arg)
{
  if (BOX_isSpaceOptionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool BOX_isSpaceOptionDefault(BOX_SpaceOption arg) */

inline ATbool BOX_isSpaceOptionDefault(BOX_SpaceOption arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, BOX_patternSpaceOptionDefault, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool BOX_hasSpaceOptionSpaceSymbol(BOX_SpaceOption arg) */

ATbool BOX_hasSpaceOptionSpaceSymbol(BOX_SpaceOption arg)
{
  if (BOX_isSpaceOptionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasSpaceOptionWsAfterSpaceSymbol(BOX_SpaceOption arg) */

ATbool BOX_hasSpaceOptionWsAfterSpaceSymbol(BOX_SpaceOption arg)
{
  if (BOX_isSpaceOptionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasSpaceOptionWsAfterEquals(BOX_SpaceOption arg) */

ATbool BOX_hasSpaceOptionWsAfterEquals(BOX_SpaceOption arg)
{
  if (BOX_isSpaceOptionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasSpaceOptionNatCon(BOX_SpaceOption arg) */

ATbool BOX_hasSpaceOptionNatCon(BOX_SpaceOption arg)
{
  if (BOX_isSpaceOptionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_SpaceSymbol BOX_getSpaceOptionSpaceSymbol(BOX_SpaceOption arg) */

BOX_SpaceSymbol BOX_getSpaceOptionSpaceSymbol(BOX_SpaceOption arg)
{
  
    return (BOX_SpaceSymbol)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getSpaceOptionWsAfterSpaceSymbol(BOX_SpaceOption arg) */

BOX_OptLayout BOX_getSpaceOptionWsAfterSpaceSymbol(BOX_SpaceOption arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getSpaceOptionWsAfterEquals(BOX_SpaceOption arg) */

BOX_OptLayout BOX_getSpaceOptionWsAfterEquals(BOX_SpaceOption arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  BOX_NatCon BOX_getSpaceOptionNatCon(BOX_SpaceOption arg) */

BOX_NatCon BOX_getSpaceOptionNatCon(BOX_SpaceOption arg)
{
  
    return (BOX_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  BOX_SpaceOption BOX_setSpaceOptionSpaceSymbol(BOX_SpaceOption arg, BOX_SpaceSymbol SpaceSymbol) */

BOX_SpaceOption BOX_setSpaceOptionSpaceSymbol(BOX_SpaceOption arg, BOX_SpaceSymbol SpaceSymbol)
{
  if (BOX_isSpaceOptionDefault(arg)) {
    return (BOX_SpaceOption)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) SpaceSymbol), 0), 1);
  }

  ATabort("SpaceOption has no SpaceSymbol: %t\n", arg);
  return (BOX_SpaceOption)NULL;
}

/*}}}  */
/*{{{  BOX_SpaceOption BOX_setSpaceOptionWsAfterSpaceSymbol(BOX_SpaceOption arg, BOX_OptLayout wsAfterSpaceSymbol) */

BOX_SpaceOption BOX_setSpaceOptionWsAfterSpaceSymbol(BOX_SpaceOption arg, BOX_OptLayout wsAfterSpaceSymbol)
{
  if (BOX_isSpaceOptionDefault(arg)) {
    return (BOX_SpaceOption)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSpaceSymbol), 1), 1);
  }

  ATabort("SpaceOption has no WsAfterSpaceSymbol: %t\n", arg);
  return (BOX_SpaceOption)NULL;
}

/*}}}  */
/*{{{  BOX_SpaceOption BOX_setSpaceOptionWsAfterEquals(BOX_SpaceOption arg, BOX_OptLayout wsAfterEquals) */

BOX_SpaceOption BOX_setSpaceOptionWsAfterEquals(BOX_SpaceOption arg, BOX_OptLayout wsAfterEquals)
{
  if (BOX_isSpaceOptionDefault(arg)) {
    return (BOX_SpaceOption)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterEquals), 3), 1);
  }

  ATabort("SpaceOption has no WsAfterEquals: %t\n", arg);
  return (BOX_SpaceOption)NULL;
}

/*}}}  */
/*{{{  BOX_SpaceOption BOX_setSpaceOptionNatCon(BOX_SpaceOption arg, BOX_NatCon NatCon) */

BOX_SpaceOption BOX_setSpaceOptionNatCon(BOX_SpaceOption arg, BOX_NatCon NatCon)
{
  if (BOX_isSpaceOptionDefault(arg)) {
    return (BOX_SpaceOption)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) NatCon), 4), 1);
  }

  ATabort("SpaceOption has no NatCon: %t\n", arg);
  return (BOX_SpaceOption)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  BOX_SpaceOptionOptions accessors */

/*{{{  ATbool BOX_isValidSpaceOptionOptions(BOX_SpaceOptionOptions arg) */

ATbool BOX_isValidSpaceOptionOptions(BOX_SpaceOptionOptions arg)
{
  if (BOX_isSpaceOptionOptionsEmpty(arg)) {
    return ATtrue;
  }
  else if (BOX_isSpaceOptionOptionsSingle(arg)) {
    return ATtrue;
  }
  else if (BOX_isSpaceOptionOptionsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool BOX_isSpaceOptionOptionsEmpty(BOX_SpaceOptionOptions arg) */

inline ATbool BOX_isSpaceOptionOptionsEmpty(BOX_SpaceOptionOptions arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, BOX_patternSpaceOptionOptionsEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool BOX_isSpaceOptionOptionsSingle(BOX_SpaceOptionOptions arg) */

inline ATbool BOX_isSpaceOptionOptionsSingle(BOX_SpaceOptionOptions arg)
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
      last_result = ATmatchTerm((ATerm)arg, BOX_patternSpaceOptionOptionsSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isSpaceOptionOptionsMany(BOX_SpaceOptionOptions arg) */

inline ATbool BOX_isSpaceOptionOptionsMany(BOX_SpaceOptionOptions arg)
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
      last_result = ATmatchTerm((ATerm)arg, BOX_patternSpaceOptionOptionsMany, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool BOX_hasSpaceOptionOptionsHead(BOX_SpaceOptionOptions arg) */

ATbool BOX_hasSpaceOptionOptionsHead(BOX_SpaceOptionOptions arg)
{
  if (BOX_isSpaceOptionOptionsSingle(arg)) {
    return ATtrue;
  }
  else if (BOX_isSpaceOptionOptionsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasSpaceOptionOptionsWsAfterHead(BOX_SpaceOptionOptions arg) */

ATbool BOX_hasSpaceOptionOptionsWsAfterHead(BOX_SpaceOptionOptions arg)
{
  if (BOX_isSpaceOptionOptionsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasSpaceOptionOptionsTail(BOX_SpaceOptionOptions arg) */

ATbool BOX_hasSpaceOptionOptionsTail(BOX_SpaceOptionOptions arg)
{
  if (BOX_isSpaceOptionOptionsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_SpaceOptionOptions BOX_getSpaceOptionOptionsTail(BOX_SpaceOptionOptions arg) */

BOX_SpaceOptionOptions BOX_getSpaceOptionOptionsTail(BOX_SpaceOptionOptions arg)
{
  assert(!BOX_isSpaceOptionOptionsEmpty(arg) && "getTail on an empty list");
  if (BOX_isSpaceOptionOptionsSingle(arg)) {
    return (BOX_SpaceOptionOptions) BOX_makeSpaceOptionOptionsEmpty();
  }
  else {
  
    return (BOX_SpaceOptionOptions)ATgetTail((ATermList)arg, 2);
  }
}

/*}}}  */
/*{{{  BOX_SpaceOption BOX_getSpaceOptionOptionsHead(BOX_SpaceOptionOptions arg) */

BOX_SpaceOption BOX_getSpaceOptionOptionsHead(BOX_SpaceOptionOptions arg)
{
  if (BOX_isSpaceOptionOptionsSingle(arg)) {
    return (BOX_SpaceOption)ATgetFirst((ATermList)arg);
  }
  else 
    return (BOX_SpaceOption)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getSpaceOptionOptionsWsAfterHead(BOX_SpaceOptionOptions arg) */

BOX_OptLayout BOX_getSpaceOptionOptionsWsAfterHead(BOX_SpaceOptionOptions arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  BOX_SpaceOptionOptions BOX_setSpaceOptionOptionsHead(BOX_SpaceOptionOptions arg, BOX_SpaceOption head) */

BOX_SpaceOptionOptions BOX_setSpaceOptionOptionsHead(BOX_SpaceOptionOptions arg, BOX_SpaceOption head)
{
  if (BOX_isSpaceOptionOptionsSingle(arg)) {
    return (BOX_SpaceOptionOptions)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (BOX_isSpaceOptionOptionsMany(arg)) {
    return (BOX_SpaceOptionOptions)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("SpaceOptionOptions has no Head: %t\n", arg);
  return (BOX_SpaceOptionOptions)NULL;
}

/*}}}  */
/*{{{  BOX_SpaceOptionOptions BOX_setSpaceOptionOptionsWsAfterHead(BOX_SpaceOptionOptions arg, BOX_OptLayout wsAfterHead) */

BOX_SpaceOptionOptions BOX_setSpaceOptionOptionsWsAfterHead(BOX_SpaceOptionOptions arg, BOX_OptLayout wsAfterHead)
{
  if (BOX_isSpaceOptionOptionsMany(arg)) {
    return (BOX_SpaceOptionOptions)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterHead), 1);
  }

  ATabort("SpaceOptionOptions has no WsAfterHead: %t\n", arg);
  return (BOX_SpaceOptionOptions)NULL;
}

/*}}}  */
/*{{{  BOX_SpaceOptionOptions BOX_setSpaceOptionOptionsTail(BOX_SpaceOptionOptions arg, BOX_SpaceOptionOptions tail) */

BOX_SpaceOptionOptions BOX_setSpaceOptionOptionsTail(BOX_SpaceOptionOptions arg, BOX_SpaceOptionOptions tail)
{
  if (BOX_isSpaceOptionOptionsMany(arg)) {
    return (BOX_SpaceOptionOptions)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 2);
  }

  ATabort("SpaceOptionOptions has no Tail: %t\n", arg);
  return (BOX_SpaceOptionOptions)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  BOX_AlignmentOption accessors */

/*{{{  ATbool BOX_isValidAlignmentOption(BOX_AlignmentOption arg) */

ATbool BOX_isValidAlignmentOption(BOX_AlignmentOption arg)
{
  if (BOX_isAlignmentOptionLeft(arg)) {
    return ATtrue;
  }
  else if (BOX_isAlignmentOptionCentre(arg)) {
    return ATtrue;
  }
  else if (BOX_isAlignmentOptionRight(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool BOX_isAlignmentOptionLeft(BOX_AlignmentOption arg) */

inline ATbool BOX_isAlignmentOptionLeft(BOX_AlignmentOption arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternAlignmentOptionLeft, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isAlignmentOptionCentre(BOX_AlignmentOption arg) */

inline ATbool BOX_isAlignmentOptionCentre(BOX_AlignmentOption arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternAlignmentOptionCentre, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isAlignmentOptionRight(BOX_AlignmentOption arg) */

inline ATbool BOX_isAlignmentOptionRight(BOX_AlignmentOption arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternAlignmentOptionRight, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool BOX_hasAlignmentOptionWsAfterL(BOX_AlignmentOption arg) */

ATbool BOX_hasAlignmentOptionWsAfterL(BOX_AlignmentOption arg)
{
  if (BOX_isAlignmentOptionLeft(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasAlignmentOptionOptions(BOX_AlignmentOption arg) */

ATbool BOX_hasAlignmentOptionOptions(BOX_AlignmentOption arg)
{
  if (BOX_isAlignmentOptionLeft(arg)) {
    return ATtrue;
  }
  else if (BOX_isAlignmentOptionCentre(arg)) {
    return ATtrue;
  }
  else if (BOX_isAlignmentOptionRight(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasAlignmentOptionWsAfterC(BOX_AlignmentOption arg) */

ATbool BOX_hasAlignmentOptionWsAfterC(BOX_AlignmentOption arg)
{
  if (BOX_isAlignmentOptionCentre(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasAlignmentOptionWsAfterR(BOX_AlignmentOption arg) */

ATbool BOX_hasAlignmentOptionWsAfterR(BOX_AlignmentOption arg)
{
  if (BOX_isAlignmentOptionRight(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getAlignmentOptionWsAfterL(BOX_AlignmentOption arg) */

BOX_OptLayout BOX_getAlignmentOptionWsAfterL(BOX_AlignmentOption arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  BOX_SpaceOptionOptions BOX_getAlignmentOptionOptions(BOX_AlignmentOption arg) */

BOX_SpaceOptionOptions BOX_getAlignmentOptionOptions(BOX_AlignmentOption arg)
{
  if (BOX_isAlignmentOptionLeft(arg)) {
    return (BOX_SpaceOptionOptions)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), 1);
  }
  else if (BOX_isAlignmentOptionCentre(arg)) {
    return (BOX_SpaceOptionOptions)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), 1);
  }
  else 
    return (BOX_SpaceOptionOptions)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), 1);
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getAlignmentOptionWsAfterC(BOX_AlignmentOption arg) */

BOX_OptLayout BOX_getAlignmentOptionWsAfterC(BOX_AlignmentOption arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getAlignmentOptionWsAfterR(BOX_AlignmentOption arg) */

BOX_OptLayout BOX_getAlignmentOptionWsAfterR(BOX_AlignmentOption arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  BOX_AlignmentOption BOX_setAlignmentOptionWsAfterL(BOX_AlignmentOption arg, BOX_OptLayout wsAfterL) */

BOX_AlignmentOption BOX_setAlignmentOptionWsAfterL(BOX_AlignmentOption arg, BOX_OptLayout wsAfterL)
{
  if (BOX_isAlignmentOptionLeft(arg)) {
    return (BOX_AlignmentOption)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterL), 1), 1);
  }

  ATabort("AlignmentOption has no WsAfterL: %t\n", arg);
  return (BOX_AlignmentOption)NULL;
}

/*}}}  */
/*{{{  BOX_AlignmentOption BOX_setAlignmentOptionOptions(BOX_AlignmentOption arg, BOX_SpaceOptionOptions options) */

BOX_AlignmentOption BOX_setAlignmentOptionOptions(BOX_AlignmentOption arg, BOX_SpaceOptionOptions options)
{
  if (BOX_isAlignmentOptionLeft(arg)) {
    return (BOX_AlignmentOption)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), (ATerm)((ATerm) options), 1), 2), 1);
  }
  else if (BOX_isAlignmentOptionCentre(arg)) {
    return (BOX_AlignmentOption)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), (ATerm)((ATerm) options), 1), 2), 1);
  }
  else if (BOX_isAlignmentOptionRight(arg)) {
    return (BOX_AlignmentOption)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), (ATerm)((ATerm) options), 1), 2), 1);
  }

  ATabort("AlignmentOption has no Options: %t\n", arg);
  return (BOX_AlignmentOption)NULL;
}

/*}}}  */
/*{{{  BOX_AlignmentOption BOX_setAlignmentOptionWsAfterC(BOX_AlignmentOption arg, BOX_OptLayout wsAfterC) */

BOX_AlignmentOption BOX_setAlignmentOptionWsAfterC(BOX_AlignmentOption arg, BOX_OptLayout wsAfterC)
{
  if (BOX_isAlignmentOptionCentre(arg)) {
    return (BOX_AlignmentOption)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterC), 1), 1);
  }

  ATabort("AlignmentOption has no WsAfterC: %t\n", arg);
  return (BOX_AlignmentOption)NULL;
}

/*}}}  */
/*{{{  BOX_AlignmentOption BOX_setAlignmentOptionWsAfterR(BOX_AlignmentOption arg, BOX_OptLayout wsAfterR) */

BOX_AlignmentOption BOX_setAlignmentOptionWsAfterR(BOX_AlignmentOption arg, BOX_OptLayout wsAfterR)
{
  if (BOX_isAlignmentOptionRight(arg)) {
    return (BOX_AlignmentOption)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterR), 1), 1);
  }

  ATabort("AlignmentOption has no WsAfterR: %t\n", arg);
  return (BOX_AlignmentOption)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  BOX_AlignmentOptions accessors */

/*{{{  ATbool BOX_isValidAlignmentOptions(BOX_AlignmentOptions arg) */

ATbool BOX_isValidAlignmentOptions(BOX_AlignmentOptions arg)
{
  if (BOX_isAlignmentOptionsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool BOX_isAlignmentOptionsDefault(BOX_AlignmentOptions arg) */

inline ATbool BOX_isAlignmentOptionsDefault(BOX_AlignmentOptions arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, BOX_patternAlignmentOptionsDefault, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool BOX_hasAlignmentOptionsWsAfterParenOpen(BOX_AlignmentOptions arg) */

ATbool BOX_hasAlignmentOptionsWsAfterParenOpen(BOX_AlignmentOptions arg)
{
  if (BOX_isAlignmentOptionsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasAlignmentOptionsList(BOX_AlignmentOptions arg) */

ATbool BOX_hasAlignmentOptionsList(BOX_AlignmentOptions arg)
{
  if (BOX_isAlignmentOptionsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasAlignmentOptionsWsAfterList(BOX_AlignmentOptions arg) */

ATbool BOX_hasAlignmentOptionsWsAfterList(BOX_AlignmentOptions arg)
{
  if (BOX_isAlignmentOptionsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getAlignmentOptionsWsAfterParenOpen(BOX_AlignmentOptions arg) */

BOX_OptLayout BOX_getAlignmentOptionsWsAfterParenOpen(BOX_AlignmentOptions arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  BOX_AlignmentOptionList BOX_getAlignmentOptionsList(BOX_AlignmentOptions arg) */

BOX_AlignmentOptionList BOX_getAlignmentOptionsList(BOX_AlignmentOptions arg)
{
  
    return (BOX_AlignmentOptionList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), 1);
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getAlignmentOptionsWsAfterList(BOX_AlignmentOptions arg) */

BOX_OptLayout BOX_getAlignmentOptionsWsAfterList(BOX_AlignmentOptions arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  BOX_AlignmentOptions BOX_setAlignmentOptionsWsAfterParenOpen(BOX_AlignmentOptions arg, BOX_OptLayout wsAfterParenOpen) */

BOX_AlignmentOptions BOX_setAlignmentOptionsWsAfterParenOpen(BOX_AlignmentOptions arg, BOX_OptLayout wsAfterParenOpen)
{
  if (BOX_isAlignmentOptionsDefault(arg)) {
    return (BOX_AlignmentOptions)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 1), 1);
  }

  ATabort("AlignmentOptions has no WsAfterParenOpen: %t\n", arg);
  return (BOX_AlignmentOptions)NULL;
}

/*}}}  */
/*{{{  BOX_AlignmentOptions BOX_setAlignmentOptionsList(BOX_AlignmentOptions arg, BOX_AlignmentOptionList list) */

BOX_AlignmentOptions BOX_setAlignmentOptionsList(BOX_AlignmentOptions arg, BOX_AlignmentOptionList list)
{
  if (BOX_isAlignmentOptionsDefault(arg)) {
    return (BOX_AlignmentOptions)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), (ATerm)((ATerm) list), 1), 2), 1);
  }

  ATabort("AlignmentOptions has no List: %t\n", arg);
  return (BOX_AlignmentOptions)NULL;
}

/*}}}  */
/*{{{  BOX_AlignmentOptions BOX_setAlignmentOptionsWsAfterList(BOX_AlignmentOptions arg, BOX_OptLayout wsAfterList) */

BOX_AlignmentOptions BOX_setAlignmentOptionsWsAfterList(BOX_AlignmentOptions arg, BOX_OptLayout wsAfterList)
{
  if (BOX_isAlignmentOptionsDefault(arg)) {
    return (BOX_AlignmentOptions)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterList), 3), 1);
  }

  ATabort("AlignmentOptions has no WsAfterList: %t\n", arg);
  return (BOX_AlignmentOptions)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  BOX_AlignmentOptionList accessors */

/*{{{  ATbool BOX_isValidAlignmentOptionList(BOX_AlignmentOptionList arg) */

ATbool BOX_isValidAlignmentOptionList(BOX_AlignmentOptionList arg)
{
  if (BOX_isAlignmentOptionListEmpty(arg)) {
    return ATtrue;
  }
  else if (BOX_isAlignmentOptionListSingle(arg)) {
    return ATtrue;
  }
  else if (BOX_isAlignmentOptionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool BOX_isAlignmentOptionListEmpty(BOX_AlignmentOptionList arg) */

inline ATbool BOX_isAlignmentOptionListEmpty(BOX_AlignmentOptionList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, BOX_patternAlignmentOptionListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool BOX_isAlignmentOptionListSingle(BOX_AlignmentOptionList arg) */

inline ATbool BOX_isAlignmentOptionListSingle(BOX_AlignmentOptionList arg)
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
      last_result = ATmatchTerm((ATerm)arg, BOX_patternAlignmentOptionListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isAlignmentOptionListMany(BOX_AlignmentOptionList arg) */

inline ATbool BOX_isAlignmentOptionListMany(BOX_AlignmentOptionList arg)
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
      last_result = ATmatchTerm((ATerm)arg, BOX_patternAlignmentOptionListMany, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool BOX_hasAlignmentOptionListHead(BOX_AlignmentOptionList arg) */

ATbool BOX_hasAlignmentOptionListHead(BOX_AlignmentOptionList arg)
{
  if (BOX_isAlignmentOptionListSingle(arg)) {
    return ATtrue;
  }
  else if (BOX_isAlignmentOptionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasAlignmentOptionListWsAfterHead(BOX_AlignmentOptionList arg) */

ATbool BOX_hasAlignmentOptionListWsAfterHead(BOX_AlignmentOptionList arg)
{
  if (BOX_isAlignmentOptionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasAlignmentOptionListWsAfterSep(BOX_AlignmentOptionList arg) */

ATbool BOX_hasAlignmentOptionListWsAfterSep(BOX_AlignmentOptionList arg)
{
  if (BOX_isAlignmentOptionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasAlignmentOptionListTail(BOX_AlignmentOptionList arg) */

ATbool BOX_hasAlignmentOptionListTail(BOX_AlignmentOptionList arg)
{
  if (BOX_isAlignmentOptionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_AlignmentOptionList BOX_getAlignmentOptionListTail(BOX_AlignmentOptionList arg) */

BOX_AlignmentOptionList BOX_getAlignmentOptionListTail(BOX_AlignmentOptionList arg)
{
  assert(!BOX_isAlignmentOptionListEmpty(arg) && "getTail on an empty list");
  if (BOX_isAlignmentOptionListSingle(arg)) {
    return (BOX_AlignmentOptionList) BOX_makeAlignmentOptionListEmpty();
  }
  else {
  
    return (BOX_AlignmentOptionList)ATgetTail((ATermList)arg, 4);
  }
}

/*}}}  */
/*{{{  BOX_AlignmentOption BOX_getAlignmentOptionListHead(BOX_AlignmentOptionList arg) */

BOX_AlignmentOption BOX_getAlignmentOptionListHead(BOX_AlignmentOptionList arg)
{
  if (BOX_isAlignmentOptionListSingle(arg)) {
    return (BOX_AlignmentOption)ATgetFirst((ATermList)arg);
  }
  else 
    return (BOX_AlignmentOption)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getAlignmentOptionListWsAfterHead(BOX_AlignmentOptionList arg) */

BOX_OptLayout BOX_getAlignmentOptionListWsAfterHead(BOX_AlignmentOptionList arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getAlignmentOptionListWsAfterSep(BOX_AlignmentOptionList arg) */

BOX_OptLayout BOX_getAlignmentOptionListWsAfterSep(BOX_AlignmentOptionList arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  BOX_AlignmentOptionList BOX_setAlignmentOptionListHead(BOX_AlignmentOptionList arg, BOX_AlignmentOption head) */

BOX_AlignmentOptionList BOX_setAlignmentOptionListHead(BOX_AlignmentOptionList arg, BOX_AlignmentOption head)
{
  if (BOX_isAlignmentOptionListSingle(arg)) {
    return (BOX_AlignmentOptionList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (BOX_isAlignmentOptionListMany(arg)) {
    return (BOX_AlignmentOptionList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("AlignmentOptionList has no Head: %t\n", arg);
  return (BOX_AlignmentOptionList)NULL;
}

/*}}}  */
/*{{{  BOX_AlignmentOptionList BOX_setAlignmentOptionListWsAfterHead(BOX_AlignmentOptionList arg, BOX_OptLayout wsAfterHead) */

BOX_AlignmentOptionList BOX_setAlignmentOptionListWsAfterHead(BOX_AlignmentOptionList arg, BOX_OptLayout wsAfterHead)
{
  if (BOX_isAlignmentOptionListMany(arg)) {
    return (BOX_AlignmentOptionList)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterHead), 1);
  }

  ATabort("AlignmentOptionList has no WsAfterHead: %t\n", arg);
  return (BOX_AlignmentOptionList)NULL;
}

/*}}}  */
/*{{{  BOX_AlignmentOptionList BOX_setAlignmentOptionListWsAfterSep(BOX_AlignmentOptionList arg, BOX_OptLayout wsAfterSep) */

BOX_AlignmentOptionList BOX_setAlignmentOptionListWsAfterSep(BOX_AlignmentOptionList arg, BOX_OptLayout wsAfterSep)
{
  if (BOX_isAlignmentOptionListMany(arg)) {
    return (BOX_AlignmentOptionList)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterSep), 3);
  }

  ATabort("AlignmentOptionList has no WsAfterSep: %t\n", arg);
  return (BOX_AlignmentOptionList)NULL;
}

/*}}}  */
/*{{{  BOX_AlignmentOptionList BOX_setAlignmentOptionListTail(BOX_AlignmentOptionList arg, BOX_AlignmentOptionList tail) */

BOX_AlignmentOptionList BOX_setAlignmentOptionListTail(BOX_AlignmentOptionList arg, BOX_AlignmentOptionList tail)
{
  if (BOX_isAlignmentOptionListMany(arg)) {
    return (BOX_AlignmentOptionList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 4);
  }

  ATabort("AlignmentOptionList has no Tail: %t\n", arg);
  return (BOX_AlignmentOptionList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  BOX_Start accessors */

/*{{{  ATbool BOX_isValidStart(BOX_Start arg) */

ATbool BOX_isValidStart(BOX_Start arg)
{
  if (BOX_isStartBox(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool BOX_isStartBox(BOX_Start arg) */

inline ATbool BOX_isStartBox(BOX_Start arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, BOX_patternStartBox, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool BOX_hasStartWsBefore(BOX_Start arg) */

ATbool BOX_hasStartWsBefore(BOX_Start arg)
{
  if (BOX_isStartBox(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasStartTopBox(BOX_Start arg) */

ATbool BOX_hasStartTopBox(BOX_Start arg)
{
  if (BOX_isStartBox(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasStartWsAfter(BOX_Start arg) */

ATbool BOX_hasStartWsAfter(BOX_Start arg)
{
  if (BOX_isStartBox(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool BOX_hasStartAmbCnt(BOX_Start arg) */

ATbool BOX_hasStartAmbCnt(BOX_Start arg)
{
  if (BOX_isStartBox(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getStartWsBefore(BOX_Start arg) */

BOX_OptLayout BOX_getStartWsBefore(BOX_Start arg)
{
  
    return (BOX_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
}

/*}}}  */
/*{{{  BOX_Box BOX_getStartTopBox(BOX_Start arg) */

BOX_Box BOX_getStartTopBox(BOX_Start arg)
{
  
    return (BOX_Box)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getStartWsAfter(BOX_Start arg) */

BOX_OptLayout BOX_getStartWsAfter(BOX_Start arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
}

/*}}}  */
/*{{{  int BOX_getStartAmbCnt(BOX_Start arg) */

int BOX_getStartAmbCnt(BOX_Start arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  BOX_Start BOX_setStartWsBefore(BOX_Start arg, BOX_OptLayout wsBefore) */

BOX_Start BOX_setStartWsBefore(BOX_Start arg, BOX_OptLayout wsBefore)
{
  if (BOX_isStartBox(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }

  ATabort("Start has no WsBefore: %t\n", arg);
  return (BOX_Start)NULL;
}

/*}}}  */
/*{{{  BOX_Start BOX_setStartTopBox(BOX_Start arg, BOX_Box topBox) */

BOX_Start BOX_setStartTopBox(BOX_Start arg, BOX_Box topBox)
{
  if (BOX_isStartBox(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topBox), 1), 1), 0);
  }

  ATabort("Start has no TopBox: %t\n", arg);
  return (BOX_Start)NULL;
}

/*}}}  */
/*{{{  BOX_Start BOX_setStartWsAfter(BOX_Start arg, BOX_OptLayout wsAfter) */

BOX_Start BOX_setStartWsAfter(BOX_Start arg, BOX_OptLayout wsAfter)
{
  if (BOX_isStartBox(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }

  ATabort("Start has no WsAfter: %t\n", arg);
  return (BOX_Start)NULL;
}

/*}}}  */
/*{{{  BOX_Start BOX_setStartAmbCnt(BOX_Start arg, int ambCnt) */

BOX_Start BOX_setStartAmbCnt(BOX_Start arg, int ambCnt)
{
  if (BOX_isStartBox(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }

  ATabort("Start has no AmbCnt: %t\n", arg);
  return (BOX_Start)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  BOX_OptLayout BOX_visitOptLayout(BOX_OptLayout arg, BOX_Layout (*acceptLayout)(BOX_Layout)) */

BOX_OptLayout BOX_visitOptLayout(BOX_OptLayout arg, BOX_Layout (*acceptLayout)(BOX_Layout))
{
  if (BOX_isOptLayoutAbsent(arg)) {
    return BOX_makeOptLayoutAbsent();
  }
  if (BOX_isOptLayoutPresent(arg)) {
    return BOX_makeOptLayoutPresent(
        acceptLayout ? acceptLayout(BOX_getOptLayoutLayout(arg)) : BOX_getOptLayoutLayout(arg));
  }
  ATabort("not a OptLayout: %t\n", arg);
  return (BOX_OptLayout)NULL;
}

/*}}}  */
/*{{{  BOX_Layout BOX_visitLayout(BOX_Layout arg, BOX_LexLayoutList (*acceptList)(BOX_LexLayoutList)) */

BOX_Layout BOX_visitLayout(BOX_Layout arg, BOX_LexLayoutList (*acceptList)(BOX_LexLayoutList))
{
  if (BOX_isLayoutLexToCf(arg)) {
    return BOX_makeLayoutLexToCf(
        acceptList ? acceptList(BOX_getLayoutList(arg)) : BOX_getLayoutList(arg));
  }
  ATabort("not a Layout: %t\n", arg);
  return (BOX_Layout)NULL;
}

/*}}}  */
/*{{{  BOX_LexLayoutList BOX_visitLexLayoutList(BOX_LexLayoutList arg, BOX_LexLayout (*acceptHead)(BOX_LexLayout)) */

BOX_LexLayoutList BOX_visitLexLayoutList(BOX_LexLayoutList arg, BOX_LexLayout (*acceptHead)(BOX_LexLayout))
{
  if (BOX_isLexLayoutListEmpty(arg)) {
    return BOX_makeLexLayoutListEmpty();
  }
  if (BOX_isLexLayoutListSingle(arg)) {
    return BOX_makeLexLayoutListSingle(
        acceptHead ? acceptHead(BOX_getLexLayoutListHead(arg)) : BOX_getLexLayoutListHead(arg));
  }
  if (BOX_isLexLayoutListMany(arg)) {
    return BOX_makeLexLayoutListMany(
        acceptHead ? acceptHead(BOX_getLexLayoutListHead(arg)) : BOX_getLexLayoutListHead(arg),
        BOX_visitLexLayoutList(BOX_getLexLayoutListTail(arg), acceptHead));
  }
  ATabort("not a LexLayoutList: %t\n", arg);
  return (BOX_LexLayoutList)NULL;
}

/*}}}  */
/*{{{  BOX_LexFontId BOX_visitLexFontId(BOX_LexFontId arg, char* (*acceptList)(char*)) */

BOX_LexFontId BOX_visitLexFontId(BOX_LexFontId arg, char* (*acceptList)(char*))
{
  if (BOX_isLexFontIdDefault(arg)) {
    return BOX_makeLexFontIdDefault(
        acceptList ? acceptList(BOX_getLexFontIdList(arg)) : BOX_getLexFontIdList(arg));
  }
  ATabort("not a LexFontId: %t\n", arg);
  return (BOX_LexFontId)NULL;
}

/*}}}  */
/*{{{  BOX_FontId BOX_visitFontId(BOX_FontId arg, BOX_LexFontId (*acceptFontId)(BOX_LexFontId)) */

BOX_FontId BOX_visitFontId(BOX_FontId arg, BOX_LexFontId (*acceptFontId)(BOX_LexFontId))
{
  if (BOX_isFontIdLexToCf(arg)) {
    return BOX_makeFontIdLexToCf(
        acceptFontId ? acceptFontId(BOX_getFontIdFontId(arg)) : BOX_getFontIdFontId(arg));
  }
  ATabort("not a FontId: %t\n", arg);
  return (BOX_FontId)NULL;
}

/*}}}  */
/*{{{  BOX_FontValue BOX_visitFontValue(BOX_FontValue arg, BOX_NatCon (*acceptNatCon)(BOX_NatCon), BOX_FontId (*acceptFontId)(BOX_FontId)) */

BOX_FontValue BOX_visitFontValue(BOX_FontValue arg, BOX_NatCon (*acceptNatCon)(BOX_NatCon), BOX_FontId (*acceptFontId)(BOX_FontId))
{
  if (BOX_isFontValueNatural(arg)) {
    return BOX_makeFontValueNatural(
        acceptNatCon ? acceptNatCon(BOX_getFontValueNatCon(arg)) : BOX_getFontValueNatCon(arg));
  }
  if (BOX_isFontValueFontId(arg)) {
    return BOX_makeFontValueFontId(
        acceptFontId ? acceptFontId(BOX_getFontValueFontId(arg)) : BOX_getFontValueFontId(arg));
  }
  ATabort("not a FontValue: %t\n", arg);
  return (BOX_FontValue)NULL;
}

/*}}}  */
/*{{{  BOX_FontOption BOX_visitFontOption(BOX_FontOption arg, BOX_FontParam (*acceptFontParam)(BOX_FontParam), BOX_OptLayout (*acceptWsAfterFontParam)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterEquals)(BOX_OptLayout), BOX_FontValue (*acceptFontValue)(BOX_FontValue)) */

BOX_FontOption BOX_visitFontOption(BOX_FontOption arg, BOX_FontParam (*acceptFontParam)(BOX_FontParam), BOX_OptLayout (*acceptWsAfterFontParam)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterEquals)(BOX_OptLayout), BOX_FontValue (*acceptFontValue)(BOX_FontValue))
{
  if (BOX_isFontOptionDefault(arg)) {
    return BOX_makeFontOptionDefault(
        acceptFontParam ? acceptFontParam(BOX_getFontOptionFontParam(arg)) : BOX_getFontOptionFontParam(arg),
        acceptWsAfterFontParam ? acceptWsAfterFontParam(BOX_getFontOptionWsAfterFontParam(arg)) : BOX_getFontOptionWsAfterFontParam(arg),
        acceptWsAfterEquals ? acceptWsAfterEquals(BOX_getFontOptionWsAfterEquals(arg)) : BOX_getFontOptionWsAfterEquals(arg),
        acceptFontValue ? acceptFontValue(BOX_getFontOptionFontValue(arg)) : BOX_getFontOptionFontValue(arg));
  }
  ATabort("not a FontOption: %t\n", arg);
  return (BOX_FontOption)NULL;
}

/*}}}  */
/*{{{  BOX_FontOperator BOX_visitFontOperator(BOX_FontOperator arg, BOX_OptLayout (*acceptWsAfterF)(BOX_OptLayout), BOX_FontOptionList (*acceptList)(BOX_FontOptionList)) */

BOX_FontOperator BOX_visitFontOperator(BOX_FontOperator arg, BOX_OptLayout (*acceptWsAfterF)(BOX_OptLayout), BOX_FontOptionList (*acceptList)(BOX_FontOptionList))
{
  if (BOX_isFontOperatorDefault(arg)) {
    return BOX_makeFontOperatorDefault(
        acceptWsAfterF ? acceptWsAfterF(BOX_getFontOperatorWsAfterF(arg)) : BOX_getFontOperatorWsAfterF(arg),
        acceptList ? acceptList(BOX_getFontOperatorList(arg)) : BOX_getFontOperatorList(arg));
  }
  if (BOX_isFontOperatorKeyword(arg)) {
    return BOX_makeFontOperatorKeyword();
  }
  if (BOX_isFontOperatorVariable(arg)) {
    return BOX_makeFontOperatorVariable();
  }
  if (BOX_isFontOperatorNumber(arg)) {
    return BOX_makeFontOperatorNumber();
  }
  if (BOX_isFontOperatorMath(arg)) {
    return BOX_makeFontOperatorMath();
  }
  if (BOX_isFontOperatorEscape(arg)) {
    return BOX_makeFontOperatorEscape();
  }
  if (BOX_isFontOperatorComment(arg)) {
    return BOX_makeFontOperatorComment();
  }
  if (BOX_isFontOperatorString(arg)) {
    return BOX_makeFontOperatorString();
  }
  ATabort("not a FontOperator: %t\n", arg);
  return (BOX_FontOperator)NULL;
}

/*}}}  */
/*{{{  BOX_Box BOX_visitBox(BOX_Box arg, BOX_FontOperator (*acceptFontOperator)(BOX_FontOperator), BOX_OptLayout (*acceptWsAfterFontOperator)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterBracketOpen)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterBox)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterCOMM)(BOX_OptLayout), BOX_BoxList (*acceptList)(BOX_BoxList), BOX_OptLayout (*acceptWsAfterList)(BOX_OptLayout), BOX_StrCon (*acceptStrCon)(BOX_StrCon), BOX_OptLayout (*acceptWsAfterH)(BOX_OptLayout), BOX_SpaceOptionOptions (*acceptOptions)(BOX_SpaceOptionOptions), BOX_OptLayout (*acceptWsAfterOptions)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterV)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterHV)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterHOV)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterI)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterWD)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterA)(BOX_OptLayout), BOX_AlignmentOptions (*acceptAlignments)(BOX_AlignmentOptions), BOX_OptLayout (*acceptWsAfterAlignments)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterR)(BOX_OptLayout)) */

BOX_Box BOX_visitBox(BOX_Box arg, BOX_FontOperator (*acceptFontOperator)(BOX_FontOperator), BOX_OptLayout (*acceptWsAfterFontOperator)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterBracketOpen)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterBox)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterCOMM)(BOX_OptLayout), BOX_BoxList (*acceptList)(BOX_BoxList), BOX_OptLayout (*acceptWsAfterList)(BOX_OptLayout), BOX_StrCon (*acceptStrCon)(BOX_StrCon), BOX_OptLayout (*acceptWsAfterH)(BOX_OptLayout), BOX_SpaceOptionOptions (*acceptOptions)(BOX_SpaceOptionOptions), BOX_OptLayout (*acceptWsAfterOptions)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterV)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterHV)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterHOV)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterI)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterWD)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterA)(BOX_OptLayout), BOX_AlignmentOptions (*acceptAlignments)(BOX_AlignmentOptions), BOX_OptLayout (*acceptWsAfterAlignments)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterR)(BOX_OptLayout))
{
  if (BOX_isBoxFontOperator(arg)) {
    return BOX_makeBoxFontOperator(
        acceptFontOperator ? acceptFontOperator(BOX_getBoxFontOperator(arg)) : BOX_getBoxFontOperator(arg),
        acceptWsAfterFontOperator ? acceptWsAfterFontOperator(BOX_getBoxWsAfterFontOperator(arg)) : BOX_getBoxWsAfterFontOperator(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(BOX_getBoxWsAfterBracketOpen(arg)) : BOX_getBoxWsAfterBracketOpen(arg),
        BOX_visitBox(BOX_getBoxBox(arg), acceptFontOperator, acceptWsAfterFontOperator, acceptWsAfterBracketOpen, acceptWsAfterBox, acceptWsAfterCOMM, acceptList, acceptWsAfterList, acceptStrCon, acceptWsAfterH, acceptOptions, acceptWsAfterOptions, acceptWsAfterV, acceptWsAfterHV, acceptWsAfterHOV, acceptWsAfterI, acceptWsAfterWD, acceptWsAfterA, acceptAlignments, acceptWsAfterAlignments, acceptWsAfterR),
        acceptWsAfterBox ? acceptWsAfterBox(BOX_getBoxWsAfterBox(arg)) : BOX_getBoxWsAfterBox(arg));
  }
  if (BOX_isBoxDefault(arg)) {
    return BOX_makeBoxDefault(
        acceptWsAfterCOMM ? acceptWsAfterCOMM(BOX_getBoxWsAfterCOMM(arg)) : BOX_getBoxWsAfterCOMM(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(BOX_getBoxWsAfterBracketOpen(arg)) : BOX_getBoxWsAfterBracketOpen(arg),
        acceptList ? acceptList(BOX_getBoxList(arg)) : BOX_getBoxList(arg),
        acceptWsAfterList ? acceptWsAfterList(BOX_getBoxWsAfterList(arg)) : BOX_getBoxWsAfterList(arg));
  }
  if (BOX_isBoxString(arg)) {
    return BOX_makeBoxString(
        acceptStrCon ? acceptStrCon(BOX_getBoxStrCon(arg)) : BOX_getBoxStrCon(arg));
  }
  if (BOX_isBoxH(arg)) {
    return BOX_makeBoxH(
        acceptWsAfterH ? acceptWsAfterH(BOX_getBoxWsAfterH(arg)) : BOX_getBoxWsAfterH(arg),
        acceptOptions ? acceptOptions(BOX_getBoxOptions(arg)) : BOX_getBoxOptions(arg),
        acceptWsAfterOptions ? acceptWsAfterOptions(BOX_getBoxWsAfterOptions(arg)) : BOX_getBoxWsAfterOptions(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(BOX_getBoxWsAfterBracketOpen(arg)) : BOX_getBoxWsAfterBracketOpen(arg),
        acceptList ? acceptList(BOX_getBoxList(arg)) : BOX_getBoxList(arg),
        acceptWsAfterList ? acceptWsAfterList(BOX_getBoxWsAfterList(arg)) : BOX_getBoxWsAfterList(arg));
  }
  if (BOX_isBoxV(arg)) {
    return BOX_makeBoxV(
        acceptWsAfterV ? acceptWsAfterV(BOX_getBoxWsAfterV(arg)) : BOX_getBoxWsAfterV(arg),
        acceptOptions ? acceptOptions(BOX_getBoxOptions(arg)) : BOX_getBoxOptions(arg),
        acceptWsAfterOptions ? acceptWsAfterOptions(BOX_getBoxWsAfterOptions(arg)) : BOX_getBoxWsAfterOptions(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(BOX_getBoxWsAfterBracketOpen(arg)) : BOX_getBoxWsAfterBracketOpen(arg),
        acceptList ? acceptList(BOX_getBoxList(arg)) : BOX_getBoxList(arg),
        acceptWsAfterList ? acceptWsAfterList(BOX_getBoxWsAfterList(arg)) : BOX_getBoxWsAfterList(arg));
  }
  if (BOX_isBoxHv(arg)) {
    return BOX_makeBoxHv(
        acceptWsAfterHV ? acceptWsAfterHV(BOX_getBoxWsAfterHV(arg)) : BOX_getBoxWsAfterHV(arg),
        acceptOptions ? acceptOptions(BOX_getBoxOptions(arg)) : BOX_getBoxOptions(arg),
        acceptWsAfterOptions ? acceptWsAfterOptions(BOX_getBoxWsAfterOptions(arg)) : BOX_getBoxWsAfterOptions(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(BOX_getBoxWsAfterBracketOpen(arg)) : BOX_getBoxWsAfterBracketOpen(arg),
        acceptList ? acceptList(BOX_getBoxList(arg)) : BOX_getBoxList(arg),
        acceptWsAfterList ? acceptWsAfterList(BOX_getBoxWsAfterList(arg)) : BOX_getBoxWsAfterList(arg));
  }
  if (BOX_isBoxHov(arg)) {
    return BOX_makeBoxHov(
        acceptWsAfterHOV ? acceptWsAfterHOV(BOX_getBoxWsAfterHOV(arg)) : BOX_getBoxWsAfterHOV(arg),
        acceptOptions ? acceptOptions(BOX_getBoxOptions(arg)) : BOX_getBoxOptions(arg),
        acceptWsAfterOptions ? acceptWsAfterOptions(BOX_getBoxWsAfterOptions(arg)) : BOX_getBoxWsAfterOptions(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(BOX_getBoxWsAfterBracketOpen(arg)) : BOX_getBoxWsAfterBracketOpen(arg),
        acceptList ? acceptList(BOX_getBoxList(arg)) : BOX_getBoxList(arg),
        acceptWsAfterList ? acceptWsAfterList(BOX_getBoxWsAfterList(arg)) : BOX_getBoxWsAfterList(arg));
  }
  if (BOX_isBoxI(arg)) {
    return BOX_makeBoxI(
        acceptWsAfterI ? acceptWsAfterI(BOX_getBoxWsAfterI(arg)) : BOX_getBoxWsAfterI(arg),
        acceptOptions ? acceptOptions(BOX_getBoxOptions(arg)) : BOX_getBoxOptions(arg),
        acceptWsAfterOptions ? acceptWsAfterOptions(BOX_getBoxWsAfterOptions(arg)) : BOX_getBoxWsAfterOptions(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(BOX_getBoxWsAfterBracketOpen(arg)) : BOX_getBoxWsAfterBracketOpen(arg),
        BOX_visitBox(BOX_getBoxBox(arg), acceptFontOperator, acceptWsAfterFontOperator, acceptWsAfterBracketOpen, acceptWsAfterBox, acceptWsAfterCOMM, acceptList, acceptWsAfterList, acceptStrCon, acceptWsAfterH, acceptOptions, acceptWsAfterOptions, acceptWsAfterV, acceptWsAfterHV, acceptWsAfterHOV, acceptWsAfterI, acceptWsAfterWD, acceptWsAfterA, acceptAlignments, acceptWsAfterAlignments, acceptWsAfterR),
        acceptWsAfterBox ? acceptWsAfterBox(BOX_getBoxWsAfterBox(arg)) : BOX_getBoxWsAfterBox(arg));
  }
  if (BOX_isBoxWd(arg)) {
    return BOX_makeBoxWd(
        acceptWsAfterWD ? acceptWsAfterWD(BOX_getBoxWsAfterWD(arg)) : BOX_getBoxWsAfterWD(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(BOX_getBoxWsAfterBracketOpen(arg)) : BOX_getBoxWsAfterBracketOpen(arg),
        BOX_visitBox(BOX_getBoxBox(arg), acceptFontOperator, acceptWsAfterFontOperator, acceptWsAfterBracketOpen, acceptWsAfterBox, acceptWsAfterCOMM, acceptList, acceptWsAfterList, acceptStrCon, acceptWsAfterH, acceptOptions, acceptWsAfterOptions, acceptWsAfterV, acceptWsAfterHV, acceptWsAfterHOV, acceptWsAfterI, acceptWsAfterWD, acceptWsAfterA, acceptAlignments, acceptWsAfterAlignments, acceptWsAfterR),
        acceptWsAfterBox ? acceptWsAfterBox(BOX_getBoxWsAfterBox(arg)) : BOX_getBoxWsAfterBox(arg));
  }
  if (BOX_isBoxAlignment(arg)) {
    return BOX_makeBoxAlignment(
        acceptWsAfterA ? acceptWsAfterA(BOX_getBoxWsAfterA(arg)) : BOX_getBoxWsAfterA(arg),
        acceptAlignments ? acceptAlignments(BOX_getBoxAlignments(arg)) : BOX_getBoxAlignments(arg),
        acceptWsAfterAlignments ? acceptWsAfterAlignments(BOX_getBoxWsAfterAlignments(arg)) : BOX_getBoxWsAfterAlignments(arg),
        acceptOptions ? acceptOptions(BOX_getBoxOptions(arg)) : BOX_getBoxOptions(arg),
        acceptWsAfterOptions ? acceptWsAfterOptions(BOX_getBoxWsAfterOptions(arg)) : BOX_getBoxWsAfterOptions(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(BOX_getBoxWsAfterBracketOpen(arg)) : BOX_getBoxWsAfterBracketOpen(arg),
        acceptList ? acceptList(BOX_getBoxList(arg)) : BOX_getBoxList(arg),
        acceptWsAfterList ? acceptWsAfterList(BOX_getBoxWsAfterList(arg)) : BOX_getBoxWsAfterList(arg));
  }
  if (BOX_isBoxRow(arg)) {
    return BOX_makeBoxRow(
        acceptWsAfterR ? acceptWsAfterR(BOX_getBoxWsAfterR(arg)) : BOX_getBoxWsAfterR(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(BOX_getBoxWsAfterBracketOpen(arg)) : BOX_getBoxWsAfterBracketOpen(arg),
        acceptList ? acceptList(BOX_getBoxList(arg)) : BOX_getBoxList(arg),
        acceptWsAfterList ? acceptWsAfterList(BOX_getBoxWsAfterList(arg)) : BOX_getBoxWsAfterList(arg));
  }
  ATabort("not a Box: %t\n", arg);
  return (BOX_Box)NULL;
}

/*}}}  */
/*{{{  BOX_FontParam BOX_visitFontParam(BOX_FontParam arg) */

BOX_FontParam BOX_visitFontParam(BOX_FontParam arg)
{
  if (BOX_isFontParamName(arg)) {
    return BOX_makeFontParamName();
  }
  if (BOX_isFontParamFamily(arg)) {
    return BOX_makeFontParamFamily();
  }
  if (BOX_isFontParamSeries(arg)) {
    return BOX_makeFontParamSeries();
  }
  if (BOX_isFontParamShape(arg)) {
    return BOX_makeFontParamShape();
  }
  if (BOX_isFontParamSize(arg)) {
    return BOX_makeFontParamSize();
  }
  if (BOX_isFontParamColor(arg)) {
    return BOX_makeFontParamColor();
  }
  ATabort("not a FontParam: %t\n", arg);
  return (BOX_FontParam)NULL;
}

/*}}}  */
/*{{{  BOX_FontOptionList BOX_visitFontOptionList(BOX_FontOptionList arg, BOX_FontOption (*acceptHead)(BOX_FontOption), BOX_OptLayout (*acceptWsAfterHead)(BOX_OptLayout)) */

BOX_FontOptionList BOX_visitFontOptionList(BOX_FontOptionList arg, BOX_FontOption (*acceptHead)(BOX_FontOption), BOX_OptLayout (*acceptWsAfterHead)(BOX_OptLayout))
{
  if (BOX_isFontOptionListEmpty(arg)) {
    return BOX_makeFontOptionListEmpty();
  }
  if (BOX_isFontOptionListSingle(arg)) {
    return BOX_makeFontOptionListSingle(
        acceptHead ? acceptHead(BOX_getFontOptionListHead(arg)) : BOX_getFontOptionListHead(arg));
  }
  if (BOX_isFontOptionListMany(arg)) {
    return BOX_makeFontOptionListMany(
        acceptHead ? acceptHead(BOX_getFontOptionListHead(arg)) : BOX_getFontOptionListHead(arg),
        acceptWsAfterHead ? acceptWsAfterHead(BOX_getFontOptionListWsAfterHead(arg)) : BOX_getFontOptionListWsAfterHead(arg),
        BOX_visitFontOptionList(BOX_getFontOptionListTail(arg), acceptHead, acceptWsAfterHead));
  }
  ATabort("not a FontOptionList: %t\n", arg);
  return (BOX_FontOptionList)NULL;
}

/*}}}  */
/*{{{  BOX_BoxList BOX_visitBoxList(BOX_BoxList arg, BOX_Box (*acceptHead)(BOX_Box), BOX_OptLayout (*acceptWsAfterHead)(BOX_OptLayout)) */

BOX_BoxList BOX_visitBoxList(BOX_BoxList arg, BOX_Box (*acceptHead)(BOX_Box), BOX_OptLayout (*acceptWsAfterHead)(BOX_OptLayout))
{
  if (BOX_isBoxListEmpty(arg)) {
    return BOX_makeBoxListEmpty();
  }
  if (BOX_isBoxListSingle(arg)) {
    return BOX_makeBoxListSingle(
        acceptHead ? acceptHead(BOX_getBoxListHead(arg)) : BOX_getBoxListHead(arg));
  }
  if (BOX_isBoxListMany(arg)) {
    return BOX_makeBoxListMany(
        acceptHead ? acceptHead(BOX_getBoxListHead(arg)) : BOX_getBoxListHead(arg),
        acceptWsAfterHead ? acceptWsAfterHead(BOX_getBoxListWsAfterHead(arg)) : BOX_getBoxListWsAfterHead(arg),
        BOX_visitBoxList(BOX_getBoxListTail(arg), acceptHead, acceptWsAfterHead));
  }
  ATabort("not a BoxList: %t\n", arg);
  return (BOX_BoxList)NULL;
}

/*}}}  */
/*{{{  BOX_LexNatCon BOX_visitLexNatCon(BOX_LexNatCon arg, char* (*acceptList)(char*)) */

BOX_LexNatCon BOX_visitLexNatCon(BOX_LexNatCon arg, char* (*acceptList)(char*))
{
  if (BOX_isLexNatConDigits(arg)) {
    return BOX_makeLexNatConDigits(
        acceptList ? acceptList(BOX_getLexNatConList(arg)) : BOX_getLexNatConList(arg));
  }
  ATabort("not a LexNatCon: %t\n", arg);
  return (BOX_LexNatCon)NULL;
}

/*}}}  */
/*{{{  BOX_NatCon BOX_visitNatCon(BOX_NatCon arg, BOX_LexNatCon (*acceptNatCon)(BOX_LexNatCon)) */

BOX_NatCon BOX_visitNatCon(BOX_NatCon arg, BOX_LexNatCon (*acceptNatCon)(BOX_LexNatCon))
{
  if (BOX_isNatConLexToCf(arg)) {
    return BOX_makeNatConLexToCf(
        acceptNatCon ? acceptNatCon(BOX_getNatConNatCon(arg)) : BOX_getNatConNatCon(arg));
  }
  ATabort("not a NatCon: %t\n", arg);
  return (BOX_NatCon)NULL;
}

/*}}}  */
/*{{{  BOX_LexStrChar BOX_visitLexStrChar(BOX_LexStrChar arg, char (*acceptA)(char), char (*acceptB)(char), char (*acceptC)(char), char (*acceptCh)(char)) */

BOX_LexStrChar BOX_visitLexStrChar(BOX_LexStrChar arg, char (*acceptA)(char), char (*acceptB)(char), char (*acceptC)(char), char (*acceptCh)(char))
{
  if (BOX_isLexStrCharNewline(arg)) {
    return BOX_makeLexStrCharNewline();
  }
  if (BOX_isLexStrCharTab(arg)) {
    return BOX_makeLexStrCharTab();
  }
  if (BOX_isLexStrCharQuote(arg)) {
    return BOX_makeLexStrCharQuote();
  }
  if (BOX_isLexStrCharBackslash(arg)) {
    return BOX_makeLexStrCharBackslash();
  }
  if (BOX_isLexStrCharDecimal(arg)) {
    return BOX_makeLexStrCharDecimal(
        acceptA ? acceptA(BOX_getLexStrCharA(arg)) : BOX_getLexStrCharA(arg),
        acceptB ? acceptB(BOX_getLexStrCharB(arg)) : BOX_getLexStrCharB(arg),
        acceptC ? acceptC(BOX_getLexStrCharC(arg)) : BOX_getLexStrCharC(arg));
  }
  if (BOX_isLexStrCharNormal(arg)) {
    return BOX_makeLexStrCharNormal(
        acceptCh ? acceptCh(BOX_getLexStrCharCh(arg)) : BOX_getLexStrCharCh(arg));
  }
  ATabort("not a LexStrChar: %t\n", arg);
  return (BOX_LexStrChar)NULL;
}

/*}}}  */
/*{{{  BOX_StrChar BOX_visitStrChar(BOX_StrChar arg, BOX_LexStrChar (*acceptStrChar)(BOX_LexStrChar)) */

BOX_StrChar BOX_visitStrChar(BOX_StrChar arg, BOX_LexStrChar (*acceptStrChar)(BOX_LexStrChar))
{
  if (BOX_isStrCharLexToCf(arg)) {
    return BOX_makeStrCharLexToCf(
        acceptStrChar ? acceptStrChar(BOX_getStrCharStrChar(arg)) : BOX_getStrCharStrChar(arg));
  }
  ATabort("not a StrChar: %t\n", arg);
  return (BOX_StrChar)NULL;
}

/*}}}  */
/*{{{  BOX_LexStrCon BOX_visitLexStrCon(BOX_LexStrCon arg, BOX_LexStrCharChars (*acceptChars)(BOX_LexStrCharChars)) */

BOX_LexStrCon BOX_visitLexStrCon(BOX_LexStrCon arg, BOX_LexStrCharChars (*acceptChars)(BOX_LexStrCharChars))
{
  if (BOX_isLexStrConDefault(arg)) {
    return BOX_makeLexStrConDefault(
        acceptChars ? acceptChars(BOX_getLexStrConChars(arg)) : BOX_getLexStrConChars(arg));
  }
  ATabort("not a LexStrCon: %t\n", arg);
  return (BOX_LexStrCon)NULL;
}

/*}}}  */
/*{{{  BOX_StrCon BOX_visitStrCon(BOX_StrCon arg, BOX_LexStrCon (*acceptStrCon)(BOX_LexStrCon)) */

BOX_StrCon BOX_visitStrCon(BOX_StrCon arg, BOX_LexStrCon (*acceptStrCon)(BOX_LexStrCon))
{
  if (BOX_isStrConLexToCf(arg)) {
    return BOX_makeStrConLexToCf(
        acceptStrCon ? acceptStrCon(BOX_getStrConStrCon(arg)) : BOX_getStrConStrCon(arg));
  }
  ATabort("not a StrCon: %t\n", arg);
  return (BOX_StrCon)NULL;
}

/*}}}  */
/*{{{  BOX_LexStrCharChars BOX_visitLexStrCharChars(BOX_LexStrCharChars arg, BOX_LexStrChar (*acceptHead)(BOX_LexStrChar)) */

BOX_LexStrCharChars BOX_visitLexStrCharChars(BOX_LexStrCharChars arg, BOX_LexStrChar (*acceptHead)(BOX_LexStrChar))
{
  if (BOX_isLexStrCharCharsEmpty(arg)) {
    return BOX_makeLexStrCharCharsEmpty();
  }
  if (BOX_isLexStrCharCharsSingle(arg)) {
    return BOX_makeLexStrCharCharsSingle(
        acceptHead ? acceptHead(BOX_getLexStrCharCharsHead(arg)) : BOX_getLexStrCharCharsHead(arg));
  }
  if (BOX_isLexStrCharCharsMany(arg)) {
    return BOX_makeLexStrCharCharsMany(
        acceptHead ? acceptHead(BOX_getLexStrCharCharsHead(arg)) : BOX_getLexStrCharCharsHead(arg),
        BOX_visitLexStrCharChars(BOX_getLexStrCharCharsTail(arg), acceptHead));
  }
  ATabort("not a LexStrCharChars: %t\n", arg);
  return (BOX_LexStrCharChars)NULL;
}

/*}}}  */
/*{{{  BOX_LexLayout BOX_visitLexLayout(BOX_LexLayout arg, char (*acceptCh)(char), char* (*acceptLine)(char*), char* (*acceptContent)(char*)) */

BOX_LexLayout BOX_visitLexLayout(BOX_LexLayout arg, char (*acceptCh)(char), char* (*acceptLine)(char*), char* (*acceptContent)(char*))
{
  if (BOX_isLexLayoutWhitespace(arg)) {
    return BOX_makeLexLayoutWhitespace(
        acceptCh ? acceptCh(BOX_getLexLayoutCh(arg)) : BOX_getLexLayoutCh(arg));
  }
  if (BOX_isLexLayoutLine(arg)) {
    return BOX_makeLexLayoutLine(
        acceptLine ? acceptLine(BOX_getLexLayoutLine(arg)) : BOX_getLexLayoutLine(arg));
  }
  if (BOX_isLexLayoutNested(arg)) {
    return BOX_makeLexLayoutNested(
        acceptContent ? acceptContent(BOX_getLexLayoutContent(arg)) : BOX_getLexLayoutContent(arg));
  }
  ATabort("not a LexLayout: %t\n", arg);
  return (BOX_LexLayout)NULL;
}

/*}}}  */
/*{{{  BOX_SpaceSymbol BOX_visitSpaceSymbol(BOX_SpaceSymbol arg) */

BOX_SpaceSymbol BOX_visitSpaceSymbol(BOX_SpaceSymbol arg)
{
  if (BOX_isSpaceSymbolHorizontal(arg)) {
    return BOX_makeSpaceSymbolHorizontal();
  }
  if (BOX_isSpaceSymbolVertical(arg)) {
    return BOX_makeSpaceSymbolVertical();
  }
  if (BOX_isSpaceSymbolIndentation(arg)) {
    return BOX_makeSpaceSymbolIndentation();
  }
  if (BOX_isSpaceSymbolTabstop(arg)) {
    return BOX_makeSpaceSymbolTabstop();
  }
  ATabort("not a SpaceSymbol: %t\n", arg);
  return (BOX_SpaceSymbol)NULL;
}

/*}}}  */
/*{{{  BOX_SpaceOption BOX_visitSpaceOption(BOX_SpaceOption arg, BOX_SpaceSymbol (*acceptSpaceSymbol)(BOX_SpaceSymbol), BOX_OptLayout (*acceptWsAfterSpaceSymbol)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterEquals)(BOX_OptLayout), BOX_NatCon (*acceptNatCon)(BOX_NatCon)) */

BOX_SpaceOption BOX_visitSpaceOption(BOX_SpaceOption arg, BOX_SpaceSymbol (*acceptSpaceSymbol)(BOX_SpaceSymbol), BOX_OptLayout (*acceptWsAfterSpaceSymbol)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterEquals)(BOX_OptLayout), BOX_NatCon (*acceptNatCon)(BOX_NatCon))
{
  if (BOX_isSpaceOptionDefault(arg)) {
    return BOX_makeSpaceOptionDefault(
        acceptSpaceSymbol ? acceptSpaceSymbol(BOX_getSpaceOptionSpaceSymbol(arg)) : BOX_getSpaceOptionSpaceSymbol(arg),
        acceptWsAfterSpaceSymbol ? acceptWsAfterSpaceSymbol(BOX_getSpaceOptionWsAfterSpaceSymbol(arg)) : BOX_getSpaceOptionWsAfterSpaceSymbol(arg),
        acceptWsAfterEquals ? acceptWsAfterEquals(BOX_getSpaceOptionWsAfterEquals(arg)) : BOX_getSpaceOptionWsAfterEquals(arg),
        acceptNatCon ? acceptNatCon(BOX_getSpaceOptionNatCon(arg)) : BOX_getSpaceOptionNatCon(arg));
  }
  ATabort("not a SpaceOption: %t\n", arg);
  return (BOX_SpaceOption)NULL;
}

/*}}}  */
/*{{{  BOX_SpaceOptionOptions BOX_visitSpaceOptionOptions(BOX_SpaceOptionOptions arg, BOX_SpaceOption (*acceptHead)(BOX_SpaceOption), BOX_OptLayout (*acceptWsAfterHead)(BOX_OptLayout)) */

BOX_SpaceOptionOptions BOX_visitSpaceOptionOptions(BOX_SpaceOptionOptions arg, BOX_SpaceOption (*acceptHead)(BOX_SpaceOption), BOX_OptLayout (*acceptWsAfterHead)(BOX_OptLayout))
{
  if (BOX_isSpaceOptionOptionsEmpty(arg)) {
    return BOX_makeSpaceOptionOptionsEmpty();
  }
  if (BOX_isSpaceOptionOptionsSingle(arg)) {
    return BOX_makeSpaceOptionOptionsSingle(
        acceptHead ? acceptHead(BOX_getSpaceOptionOptionsHead(arg)) : BOX_getSpaceOptionOptionsHead(arg));
  }
  if (BOX_isSpaceOptionOptionsMany(arg)) {
    return BOX_makeSpaceOptionOptionsMany(
        acceptHead ? acceptHead(BOX_getSpaceOptionOptionsHead(arg)) : BOX_getSpaceOptionOptionsHead(arg),
        acceptWsAfterHead ? acceptWsAfterHead(BOX_getSpaceOptionOptionsWsAfterHead(arg)) : BOX_getSpaceOptionOptionsWsAfterHead(arg),
        BOX_visitSpaceOptionOptions(BOX_getSpaceOptionOptionsTail(arg), acceptHead, acceptWsAfterHead));
  }
  ATabort("not a SpaceOptionOptions: %t\n", arg);
  return (BOX_SpaceOptionOptions)NULL;
}

/*}}}  */
/*{{{  BOX_AlignmentOption BOX_visitAlignmentOption(BOX_AlignmentOption arg, BOX_OptLayout (*acceptWsAfterL)(BOX_OptLayout), BOX_SpaceOptionOptions (*acceptOptions)(BOX_SpaceOptionOptions), BOX_OptLayout (*acceptWsAfterC)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterR)(BOX_OptLayout)) */

BOX_AlignmentOption BOX_visitAlignmentOption(BOX_AlignmentOption arg, BOX_OptLayout (*acceptWsAfterL)(BOX_OptLayout), BOX_SpaceOptionOptions (*acceptOptions)(BOX_SpaceOptionOptions), BOX_OptLayout (*acceptWsAfterC)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterR)(BOX_OptLayout))
{
  if (BOX_isAlignmentOptionLeft(arg)) {
    return BOX_makeAlignmentOptionLeft(
        acceptWsAfterL ? acceptWsAfterL(BOX_getAlignmentOptionWsAfterL(arg)) : BOX_getAlignmentOptionWsAfterL(arg),
        acceptOptions ? acceptOptions(BOX_getAlignmentOptionOptions(arg)) : BOX_getAlignmentOptionOptions(arg));
  }
  if (BOX_isAlignmentOptionCentre(arg)) {
    return BOX_makeAlignmentOptionCentre(
        acceptWsAfterC ? acceptWsAfterC(BOX_getAlignmentOptionWsAfterC(arg)) : BOX_getAlignmentOptionWsAfterC(arg),
        acceptOptions ? acceptOptions(BOX_getAlignmentOptionOptions(arg)) : BOX_getAlignmentOptionOptions(arg));
  }
  if (BOX_isAlignmentOptionRight(arg)) {
    return BOX_makeAlignmentOptionRight(
        acceptWsAfterR ? acceptWsAfterR(BOX_getAlignmentOptionWsAfterR(arg)) : BOX_getAlignmentOptionWsAfterR(arg),
        acceptOptions ? acceptOptions(BOX_getAlignmentOptionOptions(arg)) : BOX_getAlignmentOptionOptions(arg));
  }
  ATabort("not a AlignmentOption: %t\n", arg);
  return (BOX_AlignmentOption)NULL;
}

/*}}}  */
/*{{{  BOX_AlignmentOptions BOX_visitAlignmentOptions(BOX_AlignmentOptions arg, BOX_OptLayout (*acceptWsAfterParenOpen)(BOX_OptLayout), BOX_AlignmentOptionList (*acceptList)(BOX_AlignmentOptionList), BOX_OptLayout (*acceptWsAfterList)(BOX_OptLayout)) */

BOX_AlignmentOptions BOX_visitAlignmentOptions(BOX_AlignmentOptions arg, BOX_OptLayout (*acceptWsAfterParenOpen)(BOX_OptLayout), BOX_AlignmentOptionList (*acceptList)(BOX_AlignmentOptionList), BOX_OptLayout (*acceptWsAfterList)(BOX_OptLayout))
{
  if (BOX_isAlignmentOptionsDefault(arg)) {
    return BOX_makeAlignmentOptionsDefault(
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(BOX_getAlignmentOptionsWsAfterParenOpen(arg)) : BOX_getAlignmentOptionsWsAfterParenOpen(arg),
        acceptList ? acceptList(BOX_getAlignmentOptionsList(arg)) : BOX_getAlignmentOptionsList(arg),
        acceptWsAfterList ? acceptWsAfterList(BOX_getAlignmentOptionsWsAfterList(arg)) : BOX_getAlignmentOptionsWsAfterList(arg));
  }
  ATabort("not a AlignmentOptions: %t\n", arg);
  return (BOX_AlignmentOptions)NULL;
}

/*}}}  */
/*{{{  BOX_AlignmentOptionList BOX_visitAlignmentOptionList(BOX_AlignmentOptionList arg, BOX_AlignmentOption (*acceptHead)(BOX_AlignmentOption), BOX_OptLayout (*acceptWsAfterHead)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterSep)(BOX_OptLayout)) */

BOX_AlignmentOptionList BOX_visitAlignmentOptionList(BOX_AlignmentOptionList arg, BOX_AlignmentOption (*acceptHead)(BOX_AlignmentOption), BOX_OptLayout (*acceptWsAfterHead)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterSep)(BOX_OptLayout))
{
  if (BOX_isAlignmentOptionListEmpty(arg)) {
    return BOX_makeAlignmentOptionListEmpty();
  }
  if (BOX_isAlignmentOptionListSingle(arg)) {
    return BOX_makeAlignmentOptionListSingle(
        acceptHead ? acceptHead(BOX_getAlignmentOptionListHead(arg)) : BOX_getAlignmentOptionListHead(arg));
  }
  if (BOX_isAlignmentOptionListMany(arg)) {
    return BOX_makeAlignmentOptionListMany(
        acceptHead ? acceptHead(BOX_getAlignmentOptionListHead(arg)) : BOX_getAlignmentOptionListHead(arg),
        acceptWsAfterHead ? acceptWsAfterHead(BOX_getAlignmentOptionListWsAfterHead(arg)) : BOX_getAlignmentOptionListWsAfterHead(arg),
        acceptWsAfterSep ? acceptWsAfterSep(BOX_getAlignmentOptionListWsAfterSep(arg)) : BOX_getAlignmentOptionListWsAfterSep(arg),
        BOX_visitAlignmentOptionList(BOX_getAlignmentOptionListTail(arg), acceptHead, acceptWsAfterHead, acceptWsAfterSep));
  }
  ATabort("not a AlignmentOptionList: %t\n", arg);
  return (BOX_AlignmentOptionList)NULL;
}

/*}}}  */
/*{{{  BOX_Start BOX_visitStart(BOX_Start arg, BOX_OptLayout (*acceptWsBefore)(BOX_OptLayout), BOX_Box (*acceptTopBox)(BOX_Box), BOX_OptLayout (*acceptWsAfter)(BOX_OptLayout), int (*acceptAmbCnt)(int)) */

BOX_Start BOX_visitStart(BOX_Start arg, BOX_OptLayout (*acceptWsBefore)(BOX_OptLayout), BOX_Box (*acceptTopBox)(BOX_Box), BOX_OptLayout (*acceptWsAfter)(BOX_OptLayout), int (*acceptAmbCnt)(int))
{
  if (BOX_isStartBox(arg)) {
    return BOX_makeStartBox(
        acceptWsBefore ? acceptWsBefore(BOX_getStartWsBefore(arg)) : BOX_getStartWsBefore(arg),
        acceptTopBox ? acceptTopBox(BOX_getStartTopBox(arg)) : BOX_getStartTopBox(arg),
        acceptWsAfter ? acceptWsAfter(BOX_getStartWsAfter(arg)) : BOX_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(BOX_getStartAmbCnt(arg)) : BOX_getStartAmbCnt(arg));
  }
  ATabort("not a Start: %t\n", arg);
  return (BOX_Start)NULL;
}

/*}}}  */

/*}}}  */
