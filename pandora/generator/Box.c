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


/*}}}  */

/*{{{  typedefs */

typedef struct ATerm _BOX_NatCon;
typedef struct ATerm _BOX_Normal;
typedef struct ATerm _BOX_Escaped;
typedef struct ATerm _BOX_StrCon;
typedef struct ATerm _BOX_SpaceSymbol;
typedef struct ATerm _BOX_SpaceOption;
typedef struct ATerm _BOX_Box;
typedef struct ATerm _BOX_SpaceOptionOptions;
typedef struct ATerm _BOX_BoxList;
typedef struct ATerm _BOX_FontId;
typedef struct ATerm _BOX_FontValue;
typedef struct ATerm _BOX_FontOption;
typedef struct ATerm _BOX_FontOperator;
typedef struct ATerm _BOX_FontOptionList;
typedef struct ATerm _BOX_FontParam;
typedef struct ATerm _BOX_OptLayout;
typedef struct ATerm _BOX_Start;

/*}}}  */

/*{{{  void BOX_initBoxApi(void) */

void BOX_initBoxApi(void)
{
  init_Box_dict();
}

/*}}}  */

/*{{{  protect functions */

void BOX_protectNatCon(BOX_NatCon *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void BOX_protectNormal(BOX_Normal *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void BOX_protectEscaped(BOX_Escaped *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void BOX_protectStrCon(BOX_StrCon *arg)
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

void BOX_protectBox(BOX_Box *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void BOX_protectSpaceOptionOptions(BOX_SpaceOptionOptions *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void BOX_protectBoxList(BOX_BoxList *arg)
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

void BOX_protectFontOptionList(BOX_FontOptionList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void BOX_protectFontParam(BOX_FontParam *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void BOX_protectOptLayout(BOX_OptLayout *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void BOX_protectStart(BOX_Start *arg)
{
  ATprotect((ATerm*)((void*) arg));
}


/*}}}  */
/*{{{  term conversion functions */

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
/*{{{  BOX_Normal BOX_NormalFromTerm(ATerm t) */

BOX_Normal BOX_NormalFromTerm(ATerm t)
{
  return (BOX_Normal)t;
}

/*}}}  */
/*{{{  ATerm BOX_NormalToTerm(BOX_Normal arg) */

ATerm BOX_NormalToTerm(BOX_Normal arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  BOX_Escaped BOX_EscapedFromTerm(ATerm t) */

BOX_Escaped BOX_EscapedFromTerm(ATerm t)
{
  return (BOX_Escaped)t;
}

/*}}}  */
/*{{{  ATerm BOX_EscapedToTerm(BOX_Escaped arg) */

ATerm BOX_EscapedToTerm(BOX_Escaped arg)
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

/*}}}  */
/*{{{  constructors */

/*{{{  BOX_NatCon BOX_makeNatConDefault(char* string) */

BOX_NatCon BOX_makeNatConDefault(char* string)
{
  return (BOX_NatCon)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4))), (ATerm)ATmakeAppl0(BOX_afun6)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun7, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun10, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255)))))), (ATerm) ((ATerm) BOX_stringToChars(string)))));
}

/*}}}  */
/*{{{  BOX_Normal BOX_makeNormalDefault(char* string) */

BOX_Normal BOX_makeNormalDefault(char* string)
{
  return (BOX_Normal)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun11)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun11))), (ATerm)ATmakeAppl0(BOX_afun6)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun7, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun10, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255)))))), (ATerm) ((ATerm) BOX_stringToChars(string)))));
}

/*}}}  */
/*{{{  BOX_Escaped BOX_makeEscapedSpecialCharacter(char* string) */

BOX_Escaped BOX_makeEscapedSpecialCharacter(char* string)
{
  return (BOX_Escaped)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun12)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun12))), (ATerm)ATmakeAppl0(BOX_afun6)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun7, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun10, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255)))))), (ATerm) ((ATerm) BOX_stringToChars(string)))));
}

/*}}}  */
/*{{{  BOX_Escaped BOX_makeEscapedOctal(char* string) */

BOX_Escaped BOX_makeEscapedOctal(char* string)
{
  return (BOX_Escaped)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun12)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun12))), (ATerm)ATmakeAppl0(BOX_afun6)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun7, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun10, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255)))))), (ATerm) ((ATerm) BOX_stringToChars(string)))));
}

/*}}}  */
/*{{{  BOX_StrCon BOX_makeStrConDefault(char* string) */

BOX_StrCon BOX_makeStrConDefault(char* string)
{
  return (BOX_StrCon)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun13)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun13))), (ATerm)ATmakeAppl0(BOX_afun6)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun7, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun10, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255)))))), (ATerm) ((ATerm) BOX_stringToChars(string)))));
}

/*}}}  */
/*{{{  BOX_SpaceSymbol BOX_makeSpaceSymbolHorizontal() */

BOX_SpaceSymbol BOX_makeSpaceSymbolHorizontal()
{
  return (BOX_SpaceSymbol)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun15))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun16))), (ATerm)ATmakeAppl1(BOX_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun18, (ATerm)ATmakeAppl1(BOX_afun19, (ATerm)ATmakeAppl0(BOX_afun20)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun15))));
}

/*}}}  */
/*{{{  BOX_SpaceSymbol BOX_makeSpaceSymbolVertical() */

BOX_SpaceSymbol BOX_makeSpaceSymbolVertical()
{
  return (BOX_SpaceSymbol)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun21))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun16))), (ATerm)ATmakeAppl1(BOX_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun18, (ATerm)ATmakeAppl1(BOX_afun19, (ATerm)ATmakeAppl0(BOX_afun22)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun21))));
}

/*}}}  */
/*{{{  BOX_SpaceSymbol BOX_makeSpaceSymbolIndentation() */

BOX_SpaceSymbol BOX_makeSpaceSymbolIndentation()
{
  return (BOX_SpaceSymbol)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun23))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun16))), (ATerm)ATmakeAppl1(BOX_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun18, (ATerm)ATmakeAppl1(BOX_afun19, (ATerm)ATmakeAppl0(BOX_afun24)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun23))));
}

/*}}}  */
/*{{{  BOX_SpaceOption BOX_makeSpaceOptionDefault(BOX_SpaceSymbol SpaceSymbol, BOX_OptLayout wsAfterSpaceSymbol, BOX_OptLayout wsAfterEquals, BOX_NatCon NatCon) */

BOX_SpaceOption BOX_makeSpaceOptionDefault(BOX_SpaceSymbol SpaceSymbol, BOX_OptLayout wsAfterSpaceSymbol, BOX_OptLayout wsAfterEquals, BOX_NatCon NatCon)
{
  return (BOX_SpaceOption)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun27))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun16)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun28))), (ATerm)ATmakeAppl0(BOX_afun6)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) NatCon), (ATerm) wsAfterEquals), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun27))), (ATerm) wsAfterSpaceSymbol), (ATerm) SpaceSymbol));
}

/*}}}  */
/*{{{  BOX_Box BOX_makeBoxString(BOX_StrCon StrCon) */

BOX_Box BOX_makeBoxString(BOX_StrCon StrCon)
{
  return (BOX_Box)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun13)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun29))), (ATerm)ATmakeAppl1(BOX_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun18, (ATerm)ATmakeAppl1(BOX_afun19, (ATerm)ATmakeAppl0(BOX_afun30)))))), (ATerm)ATmakeList1((ATerm) StrCon));
}

/*}}}  */
/*{{{  BOX_Box BOX_makeBoxH(BOX_OptLayout wsAfterH, BOX_SpaceOptionOptions options, BOX_OptLayout wsAfterOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList list, BOX_OptLayout wsAfterList) */

BOX_Box BOX_makeBoxH(BOX_OptLayout wsAfterH, BOX_SpaceOptionOptions options, BOX_OptLayout wsAfterOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList list, BOX_OptLayout wsAfterList)
{
  return (BOX_Box)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun31))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun29))))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun32))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun28))))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun33))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun29))), (ATerm)ATmakeAppl1(BOX_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun18, (ATerm)ATmakeAppl1(BOX_afun19, (ATerm)ATmakeAppl0(BOX_afun34)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun31))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun7, (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun29))))), (ATerm) list)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun32))), (ATerm) wsAfterOptions), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun7, (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun28))))), (ATerm) options)), (ATerm) wsAfterH), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun33))));
}

/*}}}  */
/*{{{  BOX_Box BOX_makeBoxV(BOX_OptLayout wsAfterV, BOX_SpaceOptionOptions options, BOX_OptLayout wsAfterOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList list, BOX_OptLayout wsAfterList) */

BOX_Box BOX_makeBoxV(BOX_OptLayout wsAfterV, BOX_SpaceOptionOptions options, BOX_OptLayout wsAfterOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList list, BOX_OptLayout wsAfterList)
{
  return (BOX_Box)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun31))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun29))))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun32))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun28))))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun35))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun29))), (ATerm)ATmakeAppl1(BOX_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun18, (ATerm)ATmakeAppl1(BOX_afun19, (ATerm)ATmakeAppl0(BOX_afun36)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun31))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun7, (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun29))))), (ATerm) list)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun32))), (ATerm) wsAfterOptions), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun7, (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun28))))), (ATerm) options)), (ATerm) wsAfterV), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun35))));
}

/*}}}  */
/*{{{  BOX_Box BOX_makeBoxHv(BOX_OptLayout wsAfterHV, BOX_SpaceOptionOptions options, BOX_OptLayout wsAfterOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList list, BOX_OptLayout wsAfterList) */

BOX_Box BOX_makeBoxHv(BOX_OptLayout wsAfterHV, BOX_SpaceOptionOptions options, BOX_OptLayout wsAfterOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList list, BOX_OptLayout wsAfterList)
{
  return (BOX_Box)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun31))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun29))))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun32))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun28))))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun37))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun29))), (ATerm)ATmakeAppl1(BOX_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun18, (ATerm)ATmakeAppl1(BOX_afun19, (ATerm)ATmakeAppl0(BOX_afun38)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun31))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun7, (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun29))))), (ATerm) list)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun32))), (ATerm) wsAfterOptions), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun7, (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun28))))), (ATerm) options)), (ATerm) wsAfterHV), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun37))));
}

/*}}}  */
/*{{{  BOX_Box BOX_makeBoxHov(BOX_OptLayout wsAfterHOV, BOX_SpaceOptionOptions options, BOX_OptLayout wsAfterOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList list, BOX_OptLayout wsAfterList) */

BOX_Box BOX_makeBoxHov(BOX_OptLayout wsAfterHOV, BOX_SpaceOptionOptions options, BOX_OptLayout wsAfterOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList list, BOX_OptLayout wsAfterList)
{
  return (BOX_Box)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun31))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun29))))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun32))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun28))))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun39))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun29))), (ATerm)ATmakeAppl1(BOX_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun18, (ATerm)ATmakeAppl1(BOX_afun19, (ATerm)ATmakeAppl0(BOX_afun40)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun31))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun7, (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun29))))), (ATerm) list)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun32))), (ATerm) wsAfterOptions), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun7, (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun28))))), (ATerm) options)), (ATerm) wsAfterHOV), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun39))));
}

/*}}}  */
/*{{{  BOX_Box BOX_makeBoxI(BOX_OptLayout wsAfterI, BOX_SpaceOptionOptions options, BOX_OptLayout wsAfterOptions, BOX_OptLayout wsAfterBracketOpen, BOX_Box Box, BOX_OptLayout wsAfterBox) */

BOX_Box BOX_makeBoxI(BOX_OptLayout wsAfterI, BOX_SpaceOptionOptions options, BOX_OptLayout wsAfterOptions, BOX_OptLayout wsAfterBracketOpen, BOX_Box Box, BOX_OptLayout wsAfterBox)
{
  return (BOX_Box)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun31))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun29)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun32))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun28))))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun41))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun29))), (ATerm)ATmakeAppl1(BOX_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun18, (ATerm)ATmakeAppl1(BOX_afun19, (ATerm)ATmakeAppl0(BOX_afun42)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun31))), (ATerm) wsAfterBox), (ATerm) Box), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun32))), (ATerm) wsAfterOptions), (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun7, (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun28))))), (ATerm) options)), (ATerm) wsAfterI), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun41))));
}

/*}}}  */
/*{{{  BOX_Box BOX_makeBoxWd(BOX_OptLayout wsAfterWD, BOX_OptLayout wsAfterBracketOpen, BOX_Box Box, BOX_OptLayout wsAfterBox) */

BOX_Box BOX_makeBoxWd(BOX_OptLayout wsAfterWD, BOX_OptLayout wsAfterBracketOpen, BOX_Box Box, BOX_OptLayout wsAfterBox)
{
  return (BOX_Box)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun31))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun29)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun32))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun43))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun29))), (ATerm)ATmakeAppl1(BOX_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun18, (ATerm)ATmakeAppl1(BOX_afun19, (ATerm)ATmakeAppl0(BOX_afun44)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun31))), (ATerm) wsAfterBox), (ATerm) Box), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun32))), (ATerm) wsAfterWD), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun43))));
}

/*}}}  */
/*{{{  BOX_Box BOX_makeBoxFontOperator(BOX_FontOperator FontOperator, BOX_OptLayout wsAfterFontOperator, BOX_OptLayout wsAfterBracketOpen, BOX_Box Box, BOX_OptLayout wsAfterBox) */

BOX_Box BOX_makeBoxFontOperator(BOX_FontOperator FontOperator, BOX_OptLayout wsAfterFontOperator, BOX_OptLayout wsAfterBracketOpen, BOX_Box Box, BOX_OptLayout wsAfterBox)
{
  return (BOX_Box)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun31))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun29)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun32))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun45)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun29))), (ATerm)ATmakeAppl1(BOX_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun18, (ATerm)ATmakeAppl1(BOX_afun19, (ATerm)ATmakeAppl0(BOX_afun46)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun31))), (ATerm) wsAfterBox), (ATerm) Box), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun32))), (ATerm) wsAfterFontOperator), (ATerm) FontOperator));
}

/*}}}  */
/*{{{  BOX_SpaceOptionOptions BOX_makeSpaceOptionOptionsEmpty() */

BOX_SpaceOptionOptions BOX_makeSpaceOptionOptionsEmpty()
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
/*{{{  BOX_BoxList BOX_makeBoxListEmpty() */

BOX_BoxList BOX_makeBoxListEmpty()
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
/*{{{  BOX_FontId BOX_makeFontIdDefault(char* string) */

BOX_FontId BOX_makeFontIdDefault(char* string)
{
  return (BOX_FontId)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun2, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun47)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun47))), (ATerm)ATmakeAppl0(BOX_afun6)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun7, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun9, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun10, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255)))))), (ATerm) ((ATerm) BOX_stringToChars(string)))));
}

/*}}}  */
/*{{{  BOX_FontValue BOX_makeFontValueNatural(BOX_NatCon NatCon) */

BOX_FontValue BOX_makeFontValueNatural(BOX_NatCon NatCon)
{
  return (BOX_FontValue)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun48))), (ATerm)ATmakeAppl1(BOX_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun18, (ATerm)ATmakeAppl1(BOX_afun19, (ATerm)ATmakeAppl0(BOX_afun49)))))), (ATerm)ATmakeList1((ATerm) NatCon));
}

/*}}}  */
/*{{{  BOX_FontValue BOX_makeFontValueFontId(BOX_FontId FontId) */

BOX_FontValue BOX_makeFontValueFontId(BOX_FontId FontId)
{
  return (BOX_FontValue)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun47)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun48))), (ATerm)ATmakeAppl1(BOX_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun18, (ATerm)ATmakeAppl1(BOX_afun19, (ATerm)ATmakeAppl0(BOX_afun50)))))), (ATerm)ATmakeList1((ATerm) FontId));
}

/*}}}  */
/*{{{  BOX_FontOption BOX_makeFontOptionDefault(BOX_FontParam FontParam, BOX_OptLayout wsAfterFontParam, BOX_OptLayout wsAfterEquals, BOX_FontValue FontValue) */

BOX_FontOption BOX_makeFontOptionDefault(BOX_FontParam FontParam, BOX_OptLayout wsAfterFontParam, BOX_OptLayout wsAfterEquals, BOX_FontValue FontValue)
{
  return (BOX_FontOption)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun48)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun27))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun51)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun52))), (ATerm)ATmakeAppl0(BOX_afun6)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) FontValue), (ATerm) wsAfterEquals), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun27))), (ATerm) wsAfterFontParam), (ATerm) FontParam));
}

/*}}}  */
/*{{{  BOX_FontOperator BOX_makeFontOperatorDefault(BOX_OptLayout wsAfterF, BOX_FontOptionList list) */

BOX_FontOperator BOX_makeFontOperatorDefault(BOX_OptLayout wsAfterF, BOX_FontOptionList list)
{
  return (BOX_FontOperator)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun52))))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun53))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun45))), (ATerm)ATmakeAppl0(BOX_afun6)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun7, (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun52))))), (ATerm) list)), (ATerm) wsAfterF), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun53))));
}

/*}}}  */
/*{{{  BOX_FontOperator BOX_makeFontOperatorKeyword() */

BOX_FontOperator BOX_makeFontOperatorKeyword()
{
  return (BOX_FontOperator)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun54))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun45))), (ATerm)ATmakeAppl1(BOX_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun18, (ATerm)ATmakeAppl1(BOX_afun19, (ATerm)ATmakeAppl0(BOX_afun55)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun54))));
}

/*}}}  */
/*{{{  BOX_FontOperator BOX_makeFontOperatorVariable() */

BOX_FontOperator BOX_makeFontOperatorVariable()
{
  return (BOX_FontOperator)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun56))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun45))), (ATerm)ATmakeAppl1(BOX_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun18, (ATerm)ATmakeAppl1(BOX_afun19, (ATerm)ATmakeAppl0(BOX_afun57)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun56))));
}

/*}}}  */
/*{{{  BOX_FontOperator BOX_makeFontOperatorNumber() */

BOX_FontOperator BOX_makeFontOperatorNumber()
{
  return (BOX_FontOperator)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun58))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun45))), (ATerm)ATmakeAppl1(BOX_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun18, (ATerm)ATmakeAppl1(BOX_afun19, (ATerm)ATmakeAppl0(BOX_afun59)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun58))));
}

/*}}}  */
/*{{{  BOX_FontOperator BOX_makeFontOperatorMath() */

BOX_FontOperator BOX_makeFontOperatorMath()
{
  return (BOX_FontOperator)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun60))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun45))), (ATerm)ATmakeAppl1(BOX_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun18, (ATerm)ATmakeAppl1(BOX_afun19, (ATerm)ATmakeAppl0(BOX_afun61)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun60))));
}

/*}}}  */
/*{{{  BOX_FontOperator BOX_makeFontOperatorEscape() */

BOX_FontOperator BOX_makeFontOperatorEscape()
{
  return (BOX_FontOperator)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun62))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun45))), (ATerm)ATmakeAppl1(BOX_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun18, (ATerm)ATmakeAppl1(BOX_afun19, (ATerm)ATmakeAppl0(BOX_afun63)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun62))));
}

/*}}}  */
/*{{{  BOX_FontOperator BOX_makeFontOperatorComment() */

BOX_FontOperator BOX_makeFontOperatorComment()
{
  return (BOX_FontOperator)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun64))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun45))), (ATerm)ATmakeAppl1(BOX_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun18, (ATerm)ATmakeAppl1(BOX_afun19, (ATerm)ATmakeAppl0(BOX_afun65)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun64))));
}

/*}}}  */
/*{{{  BOX_FontOperator BOX_makeFontOperatorString() */

BOX_FontOperator BOX_makeFontOperatorString()
{
  return (BOX_FontOperator)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun66))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun45))), (ATerm)ATmakeAppl1(BOX_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun18, (ATerm)ATmakeAppl1(BOX_afun19, (ATerm)ATmakeAppl0(BOX_afun30)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun66))));
}

/*}}}  */
/*{{{  BOX_FontOptionList BOX_makeFontOptionListEmpty() */

BOX_FontOptionList BOX_makeFontOptionListEmpty()
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
/*{{{  BOX_FontParam BOX_makeFontParamName() */

BOX_FontParam BOX_makeFontParamName()
{
  return (BOX_FontParam)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun67))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun51))), (ATerm)ATmakeAppl1(BOX_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun18, (ATerm)ATmakeAppl1(BOX_afun19, (ATerm)ATmakeAppl0(BOX_afun68)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun67))));
}

/*}}}  */
/*{{{  BOX_FontParam BOX_makeFontParamFamily() */

BOX_FontParam BOX_makeFontParamFamily()
{
  return (BOX_FontParam)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun69))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun51))), (ATerm)ATmakeAppl1(BOX_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun18, (ATerm)ATmakeAppl1(BOX_afun19, (ATerm)ATmakeAppl0(BOX_afun70)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun69))));
}

/*}}}  */
/*{{{  BOX_FontParam BOX_makeFontParamSeries() */

BOX_FontParam BOX_makeFontParamSeries()
{
  return (BOX_FontParam)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun71))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun51))), (ATerm)ATmakeAppl1(BOX_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun18, (ATerm)ATmakeAppl1(BOX_afun19, (ATerm)ATmakeAppl0(BOX_afun72)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun71))));
}

/*}}}  */
/*{{{  BOX_FontParam BOX_makeFontParamShape() */

BOX_FontParam BOX_makeFontParamShape()
{
  return (BOX_FontParam)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun73))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun51))), (ATerm)ATmakeAppl1(BOX_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun18, (ATerm)ATmakeAppl1(BOX_afun19, (ATerm)ATmakeAppl0(BOX_afun74)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun73))));
}

/*}}}  */
/*{{{  BOX_FontParam BOX_makeFontParamSize() */

BOX_FontParam BOX_makeFontParamSize()
{
  return (BOX_FontParam)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun75))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun51))), (ATerm)ATmakeAppl1(BOX_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun18, (ATerm)ATmakeAppl1(BOX_afun19, (ATerm)ATmakeAppl0(BOX_afun76)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun75))));
}

/*}}}  */
/*{{{  BOX_FontParam BOX_makeFontParamColor() */

BOX_FontParam BOX_makeFontParamColor()
{
  return (BOX_FontParam)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun77))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun51))), (ATerm)ATmakeAppl1(BOX_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun18, (ATerm)ATmakeAppl1(BOX_afun19, (ATerm)ATmakeAppl0(BOX_afun78)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun77))));
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_makeOptLayoutAbsent() */

BOX_OptLayout BOX_makeOptLayoutAbsent()
{
  return (BOX_OptLayout)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATempty, (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26))), (ATerm)ATmakeAppl0(BOX_afun6)), (ATerm)ATempty);
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_makeOptLayoutPresent(char* string) */

BOX_OptLayout BOX_makeOptLayoutPresent(char* string)
{
  return (BOX_OptLayout)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl0(BOX_afun26))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26))), (ATerm)ATmakeAppl0(BOX_afun6)), (ATerm) ((ATerm) BOX_stringToChars(string)));
}

/*}}}  */
/*{{{  BOX_Start BOX_makeStartFontId(BOX_OptLayout wsBefore, BOX_FontId topFontId, BOX_OptLayout wsAfter, int ambCnt) */

BOX_Start BOX_makeStartFontId(BOX_OptLayout wsBefore, BOX_FontId topFontId, BOX_OptLayout wsAfter, int ambCnt)
{
  return (BOX_Start)(ATerm)ATmakeAppl2(BOX_afun79, (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun47)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun80)), (ATerm)ATmakeAppl0(BOX_afun6)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topFontId), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  BOX_Start BOX_makeStartFontOperator(BOX_OptLayout wsBefore, BOX_FontOperator topFontOperator, BOX_OptLayout wsAfter, int ambCnt) */

BOX_Start BOX_makeStartFontOperator(BOX_OptLayout wsBefore, BOX_FontOperator topFontOperator, BOX_OptLayout wsAfter, int ambCnt)
{
  return (BOX_Start)(ATerm)ATmakeAppl2(BOX_afun79, (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun45)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun80)), (ATerm)ATmakeAppl0(BOX_afun6)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topFontOperator), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  BOX_Start BOX_makeStartFontValue(BOX_OptLayout wsBefore, BOX_FontValue topFontValue, BOX_OptLayout wsAfter, int ambCnt) */

BOX_Start BOX_makeStartFontValue(BOX_OptLayout wsBefore, BOX_FontValue topFontValue, BOX_OptLayout wsAfter, int ambCnt)
{
  return (BOX_Start)(ATerm)ATmakeAppl2(BOX_afun79, (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun48)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun80)), (ATerm)ATmakeAppl0(BOX_afun6)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topFontValue), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  BOX_Start BOX_makeStartFontOption(BOX_OptLayout wsBefore, BOX_FontOption topFontOption, BOX_OptLayout wsAfter, int ambCnt) */

BOX_Start BOX_makeStartFontOption(BOX_OptLayout wsBefore, BOX_FontOption topFontOption, BOX_OptLayout wsAfter, int ambCnt)
{
  return (BOX_Start)(ATerm)ATmakeAppl2(BOX_afun79, (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun52)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun80)), (ATerm)ATmakeAppl0(BOX_afun6)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topFontOption), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  BOX_Start BOX_makeStartFontParam(BOX_OptLayout wsBefore, BOX_FontParam topFontParam, BOX_OptLayout wsAfter, int ambCnt) */

BOX_Start BOX_makeStartFontParam(BOX_OptLayout wsBefore, BOX_FontParam topFontParam, BOX_OptLayout wsAfter, int ambCnt)
{
  return (BOX_Start)(ATerm)ATmakeAppl2(BOX_afun79, (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun51)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun80)), (ATerm)ATmakeAppl0(BOX_afun6)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topFontParam), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  BOX_Start BOX_makeStartSpaceOption(BOX_OptLayout wsBefore, BOX_SpaceOption topSpaceOption, BOX_OptLayout wsAfter, int ambCnt) */

BOX_Start BOX_makeStartSpaceOption(BOX_OptLayout wsBefore, BOX_SpaceOption topSpaceOption, BOX_OptLayout wsAfter, int ambCnt)
{
  return (BOX_Start)(ATerm)ATmakeAppl2(BOX_afun79, (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun28)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun80)), (ATerm)ATmakeAppl0(BOX_afun6)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topSpaceOption), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  BOX_Start BOX_makeStartSpaceSymbol(BOX_OptLayout wsBefore, BOX_SpaceSymbol topSpaceSymbol, BOX_OptLayout wsAfter, int ambCnt) */

BOX_Start BOX_makeStartSpaceSymbol(BOX_OptLayout wsBefore, BOX_SpaceSymbol topSpaceSymbol, BOX_OptLayout wsAfter, int ambCnt)
{
  return (BOX_Start)(ATerm)ATmakeAppl2(BOX_afun79, (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun16)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun80)), (ATerm)ATmakeAppl0(BOX_afun6)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topSpaceSymbol), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  BOX_Start BOX_makeStartBox(BOX_OptLayout wsBefore, BOX_Box topBox, BOX_OptLayout wsAfter, int ambCnt) */

BOX_Start BOX_makeStartBox(BOX_OptLayout wsBefore, BOX_Box topBox, BOX_OptLayout wsAfter, int ambCnt)
{
  return (BOX_Start)(ATerm)ATmakeAppl2(BOX_afun79, (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun29)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun80)), (ATerm)ATmakeAppl0(BOX_afun6)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topBox), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  BOX_Start BOX_makeStartEscaped(BOX_OptLayout wsBefore, BOX_Escaped topEscaped, BOX_OptLayout wsAfter, int ambCnt) */

BOX_Start BOX_makeStartEscaped(BOX_OptLayout wsBefore, BOX_Escaped topEscaped, BOX_OptLayout wsAfter, int ambCnt)
{
  return (BOX_Start)(ATerm)ATmakeAppl2(BOX_afun79, (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun12)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun80)), (ATerm)ATmakeAppl0(BOX_afun6)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topEscaped), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  BOX_Start BOX_makeStartNormal(BOX_OptLayout wsBefore, BOX_Normal topNormal, BOX_OptLayout wsAfter, int ambCnt) */

BOX_Start BOX_makeStartNormal(BOX_OptLayout wsBefore, BOX_Normal topNormal, BOX_OptLayout wsAfter, int ambCnt)
{
  return (BOX_Start)(ATerm)ATmakeAppl2(BOX_afun79, (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun11)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun80)), (ATerm)ATmakeAppl0(BOX_afun6)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topNormal), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  BOX_Start BOX_makeStartStrCon(BOX_OptLayout wsBefore, BOX_StrCon topStrCon, BOX_OptLayout wsAfter, int ambCnt) */

BOX_Start BOX_makeStartStrCon(BOX_OptLayout wsBefore, BOX_StrCon topStrCon, BOX_OptLayout wsAfter, int ambCnt)
{
  return (BOX_Start)(ATerm)ATmakeAppl2(BOX_afun79, (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun13)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun80)), (ATerm)ATmakeAppl0(BOX_afun6)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topStrCon), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  BOX_Start BOX_makeStartNatCon(BOX_OptLayout wsBefore, BOX_NatCon topNatCon, BOX_OptLayout wsAfter, int ambCnt) */

BOX_Start BOX_makeStartNatCon(BOX_OptLayout wsBefore, BOX_NatCon topNatCon, BOX_OptLayout wsAfter, int ambCnt)
{
  return (BOX_Start)(ATerm)ATmakeAppl2(BOX_afun79, (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun25, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun80)), (ATerm)ATmakeAppl0(BOX_afun6)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topNatCon), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool BOX_isEqualNatCon(BOX_NatCon arg0, BOX_NatCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualNormal(BOX_Normal arg0, BOX_Normal arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualEscaped(BOX_Escaped arg0, BOX_Escaped arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualStrCon(BOX_StrCon arg0, BOX_StrCon arg1)
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

ATbool BOX_isEqualBox(BOX_Box arg0, BOX_Box arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualSpaceOptionOptions(BOX_SpaceOptionOptions arg0, BOX_SpaceOptionOptions arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualBoxList(BOX_BoxList arg0, BOX_BoxList arg1)
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

ATbool BOX_isEqualFontOptionList(BOX_FontOptionList arg0, BOX_FontOptionList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualFontParam(BOX_FontParam arg0, BOX_FontParam arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualOptLayout(BOX_OptLayout arg0, BOX_OptLayout arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualStart(BOX_Start arg0, BOX_Start arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  BOX_NatCon accessors */

/*{{{  ATbool BOX_isValidNatCon(BOX_NatCon arg) */

ATbool BOX_isValidNatCon(BOX_NatCon arg)
{
  if (BOX_isNatConDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool BOX_isNatConDefault(BOX_NatCon arg) */

inline ATbool BOX_isNatConDefault(BOX_NatCon arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, BOX_patternNatConDefault, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool BOX_hasNatConString(BOX_NatCon arg) */

ATbool BOX_hasNatConString(BOX_NatCon arg)
{
  if (BOX_isNatConDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* BOX_getNatConString(BOX_NatCon arg) */

char* BOX_getNatConString(BOX_NatCon arg)
{
  
    return (char*)BOX_charsToString((ATerm)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1));
}

/*}}}  */
/*{{{  BOX_NatCon BOX_setNatConString(BOX_NatCon arg, char* string) */

BOX_NatCon BOX_setNatConString(BOX_NatCon arg, char* string)
{
  if (BOX_isNatConDefault(arg)) {
    return (BOX_NatCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) ((ATerm) BOX_stringToChars(string))), 1), 0), 1);
  }

  ATabort("NatCon has no String: %t\n", arg);
  return (BOX_NatCon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  BOX_Normal accessors */

/*{{{  ATbool BOX_isValidNormal(BOX_Normal arg) */

ATbool BOX_isValidNormal(BOX_Normal arg)
{
  if (BOX_isNormalDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool BOX_isNormalDefault(BOX_Normal arg) */

inline ATbool BOX_isNormalDefault(BOX_Normal arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, BOX_patternNormalDefault, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool BOX_hasNormalString(BOX_Normal arg) */

ATbool BOX_hasNormalString(BOX_Normal arg)
{
  if (BOX_isNormalDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* BOX_getNormalString(BOX_Normal arg) */

char* BOX_getNormalString(BOX_Normal arg)
{
  
    return (char*)BOX_charsToString((ATerm)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1));
}

/*}}}  */
/*{{{  BOX_Normal BOX_setNormalString(BOX_Normal arg, char* string) */

BOX_Normal BOX_setNormalString(BOX_Normal arg, char* string)
{
  if (BOX_isNormalDefault(arg)) {
    return (BOX_Normal)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) ((ATerm) BOX_stringToChars(string))), 1), 0), 1);
  }

  ATabort("Normal has no String: %t\n", arg);
  return (BOX_Normal)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  BOX_Escaped accessors */

/*{{{  ATbool BOX_isValidEscaped(BOX_Escaped arg) */

ATbool BOX_isValidEscaped(BOX_Escaped arg)
{
  if (BOX_isEscapedSpecialCharacter(arg)) {
    return ATtrue;
  }
  else if (BOX_isEscapedOctal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool BOX_isEscapedSpecialCharacter(BOX_Escaped arg) */

inline ATbool BOX_isEscapedSpecialCharacter(BOX_Escaped arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternEscapedSpecialCharacter, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isEscapedOctal(BOX_Escaped arg) */

inline ATbool BOX_isEscapedOctal(BOX_Escaped arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternEscapedOctal, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool BOX_hasEscapedString(BOX_Escaped arg) */

ATbool BOX_hasEscapedString(BOX_Escaped arg)
{
  if (BOX_isEscapedSpecialCharacter(arg)) {
    return ATtrue;
  }
  else if (BOX_isEscapedOctal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* BOX_getEscapedString(BOX_Escaped arg) */

char* BOX_getEscapedString(BOX_Escaped arg)
{
  if (BOX_isEscapedSpecialCharacter(arg)) {
    return (char*)BOX_charsToString((ATerm)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1));
  }
  else 
    return (char*)BOX_charsToString((ATerm)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1));
}

/*}}}  */
/*{{{  BOX_Escaped BOX_setEscapedString(BOX_Escaped arg, char* string) */

BOX_Escaped BOX_setEscapedString(BOX_Escaped arg, char* string)
{
  if (BOX_isEscapedSpecialCharacter(arg)) {
    return (BOX_Escaped)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) ((ATerm) BOX_stringToChars(string))), 1), 0), 1);
  }
  else if (BOX_isEscapedOctal(arg)) {
    return (BOX_Escaped)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) ((ATerm) BOX_stringToChars(string))), 1), 0), 1);
  }

  ATabort("Escaped has no String: %t\n", arg);
  return (BOX_Escaped)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  BOX_StrCon accessors */

/*{{{  ATbool BOX_isValidStrCon(BOX_StrCon arg) */

ATbool BOX_isValidStrCon(BOX_StrCon arg)
{
  if (BOX_isStrConDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool BOX_isStrConDefault(BOX_StrCon arg) */

inline ATbool BOX_isStrConDefault(BOX_StrCon arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, BOX_patternStrConDefault, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool BOX_hasStrConString(BOX_StrCon arg) */

ATbool BOX_hasStrConString(BOX_StrCon arg)
{
  if (BOX_isStrConDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* BOX_getStrConString(BOX_StrCon arg) */

char* BOX_getStrConString(BOX_StrCon arg)
{
  
    return (char*)BOX_charsToString((ATerm)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1));
}

/*}}}  */
/*{{{  BOX_StrCon BOX_setStrConString(BOX_StrCon arg, char* string) */

BOX_StrCon BOX_setStrConString(BOX_StrCon arg, char* string)
{
  if (BOX_isStrConDefault(arg)) {
    return (BOX_StrCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) ((ATerm) BOX_stringToChars(string))), 1), 0), 1);
  }

  ATabort("StrCon has no String: %t\n", arg);
  return (BOX_StrCon)NULL;
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
/*{{{  BOX_SpaceSymbol BOX_getSpaceOptionSpaceSymbol(BOX_SpaceOption arg) */

BOX_SpaceSymbol BOX_getSpaceOptionSpaceSymbol(BOX_SpaceOption arg)
{
  
    return (BOX_SpaceSymbol)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
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
/*{{{  ATbool BOX_hasSpaceOptionWsAfterSpaceSymbol(BOX_SpaceOption arg) */

ATbool BOX_hasSpaceOptionWsAfterSpaceSymbol(BOX_SpaceOption arg)
{
  if (BOX_isSpaceOptionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getSpaceOptionWsAfterSpaceSymbol(BOX_SpaceOption arg) */

BOX_OptLayout BOX_getSpaceOptionWsAfterSpaceSymbol(BOX_SpaceOption arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
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
/*{{{  ATbool BOX_hasSpaceOptionWsAfterEquals(BOX_SpaceOption arg) */

ATbool BOX_hasSpaceOptionWsAfterEquals(BOX_SpaceOption arg)
{
  if (BOX_isSpaceOptionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getSpaceOptionWsAfterEquals(BOX_SpaceOption arg) */

BOX_OptLayout BOX_getSpaceOptionWsAfterEquals(BOX_SpaceOption arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
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
/*{{{  ATbool BOX_hasSpaceOptionNatCon(BOX_SpaceOption arg) */

ATbool BOX_hasSpaceOptionNatCon(BOX_SpaceOption arg)
{
  if (BOX_isSpaceOptionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_NatCon BOX_getSpaceOptionNatCon(BOX_SpaceOption arg) */

BOX_NatCon BOX_getSpaceOptionNatCon(BOX_SpaceOption arg)
{
  
    return (BOX_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
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
/*{{{  BOX_Box accessors */

/*{{{  ATbool BOX_isValidBox(BOX_Box arg) */

ATbool BOX_isValidBox(BOX_Box arg)
{
  if (BOX_isBoxString(arg)) {
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
  else if (BOX_isBoxFontOperator(arg)) {
    return ATtrue;
  }
  return ATfalse;
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
/*{{{  ATbool BOX_hasBoxStrCon(BOX_Box arg) */

ATbool BOX_hasBoxStrCon(BOX_Box arg)
{
  if (BOX_isBoxString(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_StrCon BOX_getBoxStrCon(BOX_Box arg) */

BOX_StrCon BOX_getBoxStrCon(BOX_Box arg)
{
  
    return (BOX_StrCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
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
/*{{{  ATbool BOX_hasBoxWsAfterH(BOX_Box arg) */

ATbool BOX_hasBoxWsAfterH(BOX_Box arg)
{
  if (BOX_isBoxH(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getBoxWsAfterH(BOX_Box arg) */

BOX_OptLayout BOX_getBoxWsAfterH(BOX_Box arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
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
  return ATfalse;
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
  else 
    return (BOX_SpaceOptionOptions)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), 1);
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

  ATabort("Box has no Options: %t\n", arg);
  return (BOX_Box)NULL;
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
  return ATfalse;
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
  else 
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
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

  ATabort("Box has no WsAfterOptions: %t\n", arg);
  return (BOX_Box)NULL;
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxWsAfterBracketOpen(BOX_Box arg) */

ATbool BOX_hasBoxWsAfterBracketOpen(BOX_Box arg)
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
  else if (BOX_isBoxWd(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxFontOperator(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getBoxWsAfterBracketOpen(BOX_Box arg) */

BOX_OptLayout BOX_getBoxWsAfterBracketOpen(BOX_Box arg)
{
  if (BOX_isBoxH(arg)) {
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
  else 
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  BOX_Box BOX_setBoxWsAfterBracketOpen(BOX_Box arg, BOX_OptLayout wsAfterBracketOpen) */

BOX_Box BOX_setBoxWsAfterBracketOpen(BOX_Box arg, BOX_OptLayout wsAfterBracketOpen)
{
  if (BOX_isBoxH(arg)) {
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
  else if (BOX_isBoxFontOperator(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 3), 1);
  }

  ATabort("Box has no WsAfterBracketOpen: %t\n", arg);
  return (BOX_Box)NULL;
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxList(BOX_Box arg) */

ATbool BOX_hasBoxList(BOX_Box arg)
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
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_BoxList BOX_getBoxList(BOX_Box arg) */

BOX_BoxList BOX_getBoxList(BOX_Box arg)
{
  if (BOX_isBoxH(arg)) {
    return (BOX_BoxList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6), 1);
  }
  else if (BOX_isBoxV(arg)) {
    return (BOX_BoxList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6), 1);
  }
  else if (BOX_isBoxHv(arg)) {
    return (BOX_BoxList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6), 1);
  }
  else 
    return (BOX_BoxList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6), 1);
}

/*}}}  */
/*{{{  BOX_Box BOX_setBoxList(BOX_Box arg, BOX_BoxList list) */

BOX_Box BOX_setBoxList(BOX_Box arg, BOX_BoxList list)
{
  if (BOX_isBoxH(arg)) {
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

  ATabort("Box has no List: %t\n", arg);
  return (BOX_Box)NULL;
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxWsAfterList(BOX_Box arg) */

ATbool BOX_hasBoxWsAfterList(BOX_Box arg)
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
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getBoxWsAfterList(BOX_Box arg) */

BOX_OptLayout BOX_getBoxWsAfterList(BOX_Box arg)
{
  if (BOX_isBoxH(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else if (BOX_isBoxV(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else if (BOX_isBoxHv(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else 
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  BOX_Box BOX_setBoxWsAfterList(BOX_Box arg, BOX_OptLayout wsAfterList) */

BOX_Box BOX_setBoxWsAfterList(BOX_Box arg, BOX_OptLayout wsAfterList)
{
  if (BOX_isBoxH(arg)) {
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

  ATabort("Box has no WsAfterList: %t\n", arg);
  return (BOX_Box)NULL;
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
/*{{{  BOX_OptLayout BOX_getBoxWsAfterV(BOX_Box arg) */

BOX_OptLayout BOX_getBoxWsAfterV(BOX_Box arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
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
/*{{{  ATbool BOX_hasBoxWsAfterHV(BOX_Box arg) */

ATbool BOX_hasBoxWsAfterHV(BOX_Box arg)
{
  if (BOX_isBoxHv(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getBoxWsAfterHV(BOX_Box arg) */

BOX_OptLayout BOX_getBoxWsAfterHV(BOX_Box arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
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
/*{{{  ATbool BOX_hasBoxWsAfterHOV(BOX_Box arg) */

ATbool BOX_hasBoxWsAfterHOV(BOX_Box arg)
{
  if (BOX_isBoxHov(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getBoxWsAfterHOV(BOX_Box arg) */

BOX_OptLayout BOX_getBoxWsAfterHOV(BOX_Box arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
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
/*{{{  ATbool BOX_hasBoxWsAfterI(BOX_Box arg) */

ATbool BOX_hasBoxWsAfterI(BOX_Box arg)
{
  if (BOX_isBoxI(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getBoxWsAfterI(BOX_Box arg) */

BOX_OptLayout BOX_getBoxWsAfterI(BOX_Box arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
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
/*{{{  ATbool BOX_hasBoxBox(BOX_Box arg) */

ATbool BOX_hasBoxBox(BOX_Box arg)
{
  if (BOX_isBoxI(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxWd(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxFontOperator(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_Box BOX_getBoxBox(BOX_Box arg) */

BOX_Box BOX_getBoxBox(BOX_Box arg)
{
  if (BOX_isBoxI(arg)) {
    return (BOX_Box)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6);
  }
  else if (BOX_isBoxWd(arg)) {
    return (BOX_Box)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (BOX_Box)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  BOX_Box BOX_setBoxBox(BOX_Box arg, BOX_Box Box) */

BOX_Box BOX_setBoxBox(BOX_Box arg, BOX_Box Box)
{
  if (BOX_isBoxI(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Box), 6), 1);
  }
  else if (BOX_isBoxWd(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Box), 4), 1);
  }
  else if (BOX_isBoxFontOperator(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Box), 4), 1);
  }

  ATabort("Box has no Box: %t\n", arg);
  return (BOX_Box)NULL;
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxWsAfterBox(BOX_Box arg) */

ATbool BOX_hasBoxWsAfterBox(BOX_Box arg)
{
  if (BOX_isBoxI(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxWd(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxFontOperator(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getBoxWsAfterBox(BOX_Box arg) */

BOX_OptLayout BOX_getBoxWsAfterBox(BOX_Box arg)
{
  if (BOX_isBoxI(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else if (BOX_isBoxWd(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else 
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  BOX_Box BOX_setBoxWsAfterBox(BOX_Box arg, BOX_OptLayout wsAfterBox) */

BOX_Box BOX_setBoxWsAfterBox(BOX_Box arg, BOX_OptLayout wsAfterBox)
{
  if (BOX_isBoxI(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBox), 7), 1);
  }
  else if (BOX_isBoxWd(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBox), 5), 1);
  }
  else if (BOX_isBoxFontOperator(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBox), 5), 1);
  }

  ATabort("Box has no WsAfterBox: %t\n", arg);
  return (BOX_Box)NULL;
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
/*{{{  BOX_OptLayout BOX_getBoxWsAfterWD(BOX_Box arg) */

BOX_OptLayout BOX_getBoxWsAfterWD(BOX_Box arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
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
/*{{{  ATbool BOX_hasBoxFontOperator(BOX_Box arg) */

ATbool BOX_hasBoxFontOperator(BOX_Box arg)
{
  if (BOX_isBoxFontOperator(arg)) {
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
/*{{{  ATbool BOX_hasBoxWsAfterFontOperator(BOX_Box arg) */

ATbool BOX_hasBoxWsAfterFontOperator(BOX_Box arg)
{
  if (BOX_isBoxFontOperator(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getBoxWsAfterFontOperator(BOX_Box arg) */

BOX_OptLayout BOX_getBoxWsAfterFontOperator(BOX_Box arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
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
/*{{{  ATbool BOX_hasSpaceOptionOptionsWsAfterHead(BOX_SpaceOptionOptions arg) */

ATbool BOX_hasSpaceOptionOptionsWsAfterHead(BOX_SpaceOptionOptions arg)
{
  if (BOX_isSpaceOptionOptionsMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getSpaceOptionOptionsWsAfterHead(BOX_SpaceOptionOptions arg) */

BOX_OptLayout BOX_getSpaceOptionOptionsWsAfterHead(BOX_SpaceOptionOptions arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)arg, 1);
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
  
    return (BOX_SpaceOptionOptions)ATgetTail((ATermList)arg, 2);
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
/*{{{  ATbool BOX_hasBoxListWsAfterHead(BOX_BoxList arg) */

ATbool BOX_hasBoxListWsAfterHead(BOX_BoxList arg)
{
  if (BOX_isBoxListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getBoxListWsAfterHead(BOX_BoxList arg) */

BOX_OptLayout BOX_getBoxListWsAfterHead(BOX_BoxList arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)arg, 1);
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
  
    return (BOX_BoxList)ATgetTail((ATermList)arg, 2);
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
/*{{{  BOX_FontId accessors */

/*{{{  ATbool BOX_isValidFontId(BOX_FontId arg) */

ATbool BOX_isValidFontId(BOX_FontId arg)
{
  if (BOX_isFontIdDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool BOX_isFontIdDefault(BOX_FontId arg) */

inline ATbool BOX_isFontIdDefault(BOX_FontId arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, BOX_patternFontIdDefault, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool BOX_hasFontIdString(BOX_FontId arg) */

ATbool BOX_hasFontIdString(BOX_FontId arg)
{
  if (BOX_isFontIdDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* BOX_getFontIdString(BOX_FontId arg) */

char* BOX_getFontIdString(BOX_FontId arg)
{
  
    return (char*)BOX_charsToString((ATerm)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1));
}

/*}}}  */
/*{{{  BOX_FontId BOX_setFontIdString(BOX_FontId arg, char* string) */

BOX_FontId BOX_setFontIdString(BOX_FontId arg, char* string)
{
  if (BOX_isFontIdDefault(arg)) {
    return (BOX_FontId)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) ((ATerm) BOX_stringToChars(string))), 1), 0), 1);
  }

  ATabort("FontId has no String: %t\n", arg);
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
/*{{{  BOX_NatCon BOX_getFontValueNatCon(BOX_FontValue arg) */

BOX_NatCon BOX_getFontValueNatCon(BOX_FontValue arg)
{
  
    return (BOX_NatCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
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
/*{{{  ATbool BOX_hasFontValueFontId(BOX_FontValue arg) */

ATbool BOX_hasFontValueFontId(BOX_FontValue arg)
{
  if (BOX_isFontValueFontId(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_FontId BOX_getFontValueFontId(BOX_FontValue arg) */

BOX_FontId BOX_getFontValueFontId(BOX_FontValue arg)
{
  
    return (BOX_FontId)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
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
/*{{{  BOX_FontParam BOX_getFontOptionFontParam(BOX_FontOption arg) */

BOX_FontParam BOX_getFontOptionFontParam(BOX_FontOption arg)
{
  
    return (BOX_FontParam)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
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
/*{{{  ATbool BOX_hasFontOptionWsAfterFontParam(BOX_FontOption arg) */

ATbool BOX_hasFontOptionWsAfterFontParam(BOX_FontOption arg)
{
  if (BOX_isFontOptionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getFontOptionWsAfterFontParam(BOX_FontOption arg) */

BOX_OptLayout BOX_getFontOptionWsAfterFontParam(BOX_FontOption arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
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
/*{{{  ATbool BOX_hasFontOptionWsAfterEquals(BOX_FontOption arg) */

ATbool BOX_hasFontOptionWsAfterEquals(BOX_FontOption arg)
{
  if (BOX_isFontOptionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getFontOptionWsAfterEquals(BOX_FontOption arg) */

BOX_OptLayout BOX_getFontOptionWsAfterEquals(BOX_FontOption arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
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
/*{{{  ATbool BOX_hasFontOptionFontValue(BOX_FontOption arg) */

ATbool BOX_hasFontOptionFontValue(BOX_FontOption arg)
{
  if (BOX_isFontOptionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_FontValue BOX_getFontOptionFontValue(BOX_FontOption arg) */

BOX_FontValue BOX_getFontOptionFontValue(BOX_FontOption arg)
{
  
    return (BOX_FontValue)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
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
/*{{{  BOX_OptLayout BOX_getFontOperatorWsAfterF(BOX_FontOperator arg) */

BOX_OptLayout BOX_getFontOperatorWsAfterF(BOX_FontOperator arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
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
/*{{{  ATbool BOX_hasFontOperatorList(BOX_FontOperator arg) */

ATbool BOX_hasFontOperatorList(BOX_FontOperator arg)
{
  if (BOX_isFontOperatorDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_FontOptionList BOX_getFontOperatorList(BOX_FontOperator arg) */

BOX_FontOptionList BOX_getFontOperatorList(BOX_FontOperator arg)
{
  
    return (BOX_FontOptionList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), 1);
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
/*{{{  ATbool BOX_hasFontOptionListWsAfterHead(BOX_FontOptionList arg) */

ATbool BOX_hasFontOptionListWsAfterHead(BOX_FontOptionList arg)
{
  if (BOX_isFontOptionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getFontOptionListWsAfterHead(BOX_FontOptionList arg) */

BOX_OptLayout BOX_getFontOptionListWsAfterHead(BOX_FontOptionList arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)arg, 1);
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
  
    return (BOX_FontOptionList)ATgetTail((ATermList)arg, 2);
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
/*{{{  ATbool BOX_hasOptLayoutString(BOX_OptLayout arg) */

ATbool BOX_hasOptLayoutString(BOX_OptLayout arg)
{
  if (BOX_isOptLayoutPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* BOX_getOptLayoutString(BOX_OptLayout arg) */

char* BOX_getOptLayoutString(BOX_OptLayout arg)
{
  
    return (char*)BOX_charsToString((ATerm)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_setOptLayoutString(BOX_OptLayout arg, char* string) */

BOX_OptLayout BOX_setOptLayoutString(BOX_OptLayout arg, char* string)
{
  if (BOX_isOptLayoutPresent(arg)) {
    return (BOX_OptLayout)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) ((ATerm) BOX_stringToChars(string))), 1);
  }

  ATabort("OptLayout has no String: %t\n", arg);
  return (BOX_OptLayout)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  BOX_Start accessors */

/*{{{  ATbool BOX_isValidStart(BOX_Start arg) */

ATbool BOX_isValidStart(BOX_Start arg)
{
  if (BOX_isStartFontId(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartFontOperator(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartFontValue(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartFontOption(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartFontParam(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartSpaceOption(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartSpaceSymbol(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartBox(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartEscaped(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartNormal(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartStrCon(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartNatCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool BOX_isStartFontId(BOX_Start arg) */

inline ATbool BOX_isStartFontId(BOX_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternStartFontId, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isStartFontOperator(BOX_Start arg) */

inline ATbool BOX_isStartFontOperator(BOX_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternStartFontOperator, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isStartFontValue(BOX_Start arg) */

inline ATbool BOX_isStartFontValue(BOX_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternStartFontValue, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isStartFontOption(BOX_Start arg) */

inline ATbool BOX_isStartFontOption(BOX_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternStartFontOption, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isStartFontParam(BOX_Start arg) */

inline ATbool BOX_isStartFontParam(BOX_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternStartFontParam, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isStartSpaceOption(BOX_Start arg) */

inline ATbool BOX_isStartSpaceOption(BOX_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternStartSpaceOption, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isStartSpaceSymbol(BOX_Start arg) */

inline ATbool BOX_isStartSpaceSymbol(BOX_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternStartSpaceSymbol, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isStartBox(BOX_Start arg) */

inline ATbool BOX_isStartBox(BOX_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternStartBox, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isStartEscaped(BOX_Start arg) */

inline ATbool BOX_isStartEscaped(BOX_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternStartEscaped, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isStartNormal(BOX_Start arg) */

inline ATbool BOX_isStartNormal(BOX_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternStartNormal, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isStartStrCon(BOX_Start arg) */

inline ATbool BOX_isStartStrCon(BOX_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternStartStrCon, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isStartNatCon(BOX_Start arg) */

inline ATbool BOX_isStartNatCon(BOX_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternStartNatCon, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool BOX_hasStartWsBefore(BOX_Start arg) */

ATbool BOX_hasStartWsBefore(BOX_Start arg)
{
  if (BOX_isStartFontId(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartFontOperator(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartFontValue(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartFontOption(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartFontParam(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartSpaceOption(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartSpaceSymbol(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartBox(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartEscaped(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartNormal(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartStrCon(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartNatCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getStartWsBefore(BOX_Start arg) */

BOX_OptLayout BOX_getStartWsBefore(BOX_Start arg)
{
  if (BOX_isStartFontId(arg)) {
    return (BOX_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (BOX_isStartFontOperator(arg)) {
    return (BOX_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (BOX_isStartFontValue(arg)) {
    return (BOX_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (BOX_isStartFontOption(arg)) {
    return (BOX_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (BOX_isStartFontParam(arg)) {
    return (BOX_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (BOX_isStartSpaceOption(arg)) {
    return (BOX_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (BOX_isStartSpaceSymbol(arg)) {
    return (BOX_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (BOX_isStartBox(arg)) {
    return (BOX_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (BOX_isStartEscaped(arg)) {
    return (BOX_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (BOX_isStartNormal(arg)) {
    return (BOX_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (BOX_isStartStrCon(arg)) {
    return (BOX_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else 
    return (BOX_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
}

/*}}}  */
/*{{{  BOX_Start BOX_setStartWsBefore(BOX_Start arg, BOX_OptLayout wsBefore) */

BOX_Start BOX_setStartWsBefore(BOX_Start arg, BOX_OptLayout wsBefore)
{
  if (BOX_isStartFontId(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (BOX_isStartFontOperator(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (BOX_isStartFontValue(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (BOX_isStartFontOption(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (BOX_isStartFontParam(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (BOX_isStartSpaceOption(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (BOX_isStartSpaceSymbol(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (BOX_isStartBox(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (BOX_isStartEscaped(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (BOX_isStartNormal(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (BOX_isStartStrCon(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (BOX_isStartNatCon(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }

  ATabort("Start has no WsBefore: %t\n", arg);
  return (BOX_Start)NULL;
}

/*}}}  */
/*{{{  ATbool BOX_hasStartTopFontId(BOX_Start arg) */

ATbool BOX_hasStartTopFontId(BOX_Start arg)
{
  if (BOX_isStartFontId(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_FontId BOX_getStartTopFontId(BOX_Start arg) */

BOX_FontId BOX_getStartTopFontId(BOX_Start arg)
{
  
    return (BOX_FontId)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  BOX_Start BOX_setStartTopFontId(BOX_Start arg, BOX_FontId topFontId) */

BOX_Start BOX_setStartTopFontId(BOX_Start arg, BOX_FontId topFontId)
{
  if (BOX_isStartFontId(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topFontId), 1), 1), 0);
  }

  ATabort("Start has no TopFontId: %t\n", arg);
  return (BOX_Start)NULL;
}

/*}}}  */
/*{{{  ATbool BOX_hasStartWsAfter(BOX_Start arg) */

ATbool BOX_hasStartWsAfter(BOX_Start arg)
{
  if (BOX_isStartFontId(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartFontOperator(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartFontValue(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartFontOption(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartFontParam(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartSpaceOption(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartSpaceSymbol(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartBox(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartEscaped(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartNormal(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartStrCon(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartNatCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getStartWsAfter(BOX_Start arg) */

BOX_OptLayout BOX_getStartWsAfter(BOX_Start arg)
{
  if (BOX_isStartFontId(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (BOX_isStartFontOperator(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (BOX_isStartFontValue(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (BOX_isStartFontOption(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (BOX_isStartFontParam(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (BOX_isStartSpaceOption(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (BOX_isStartSpaceSymbol(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (BOX_isStartBox(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (BOX_isStartEscaped(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (BOX_isStartNormal(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (BOX_isStartStrCon(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else 
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
}

/*}}}  */
/*{{{  BOX_Start BOX_setStartWsAfter(BOX_Start arg, BOX_OptLayout wsAfter) */

BOX_Start BOX_setStartWsAfter(BOX_Start arg, BOX_OptLayout wsAfter)
{
  if (BOX_isStartFontId(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (BOX_isStartFontOperator(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (BOX_isStartFontValue(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (BOX_isStartFontOption(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (BOX_isStartFontParam(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (BOX_isStartSpaceOption(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (BOX_isStartSpaceSymbol(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (BOX_isStartBox(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (BOX_isStartEscaped(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (BOX_isStartNormal(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (BOX_isStartStrCon(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (BOX_isStartNatCon(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }

  ATabort("Start has no WsAfter: %t\n", arg);
  return (BOX_Start)NULL;
}

/*}}}  */
/*{{{  ATbool BOX_hasStartAmbCnt(BOX_Start arg) */

ATbool BOX_hasStartAmbCnt(BOX_Start arg)
{
  if (BOX_isStartFontId(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartFontOperator(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartFontValue(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartFontOption(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartFontParam(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartSpaceOption(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartSpaceSymbol(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartBox(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartEscaped(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartNormal(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartStrCon(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartNatCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int BOX_getStartAmbCnt(BOX_Start arg) */

int BOX_getStartAmbCnt(BOX_Start arg)
{
  if (BOX_isStartFontId(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else if (BOX_isStartFontOperator(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else if (BOX_isStartFontValue(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else if (BOX_isStartFontOption(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else if (BOX_isStartFontParam(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else if (BOX_isStartSpaceOption(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else if (BOX_isStartSpaceSymbol(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else if (BOX_isStartBox(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else if (BOX_isStartEscaped(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else if (BOX_isStartNormal(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else if (BOX_isStartStrCon(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  BOX_Start BOX_setStartAmbCnt(BOX_Start arg, int ambCnt) */

BOX_Start BOX_setStartAmbCnt(BOX_Start arg, int ambCnt)
{
  if (BOX_isStartFontId(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (BOX_isStartFontOperator(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (BOX_isStartFontValue(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (BOX_isStartFontOption(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (BOX_isStartFontParam(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (BOX_isStartSpaceOption(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (BOX_isStartSpaceSymbol(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (BOX_isStartBox(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (BOX_isStartEscaped(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (BOX_isStartNormal(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (BOX_isStartStrCon(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (BOX_isStartNatCon(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }

  ATabort("Start has no AmbCnt: %t\n", arg);
  return (BOX_Start)NULL;
}

/*}}}  */
/*{{{  ATbool BOX_hasStartTopFontOperator(BOX_Start arg) */

ATbool BOX_hasStartTopFontOperator(BOX_Start arg)
{
  if (BOX_isStartFontOperator(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_FontOperator BOX_getStartTopFontOperator(BOX_Start arg) */

BOX_FontOperator BOX_getStartTopFontOperator(BOX_Start arg)
{
  
    return (BOX_FontOperator)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  BOX_Start BOX_setStartTopFontOperator(BOX_Start arg, BOX_FontOperator topFontOperator) */

BOX_Start BOX_setStartTopFontOperator(BOX_Start arg, BOX_FontOperator topFontOperator)
{
  if (BOX_isStartFontOperator(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topFontOperator), 1), 1), 0);
  }

  ATabort("Start has no TopFontOperator: %t\n", arg);
  return (BOX_Start)NULL;
}

/*}}}  */
/*{{{  ATbool BOX_hasStartTopFontValue(BOX_Start arg) */

ATbool BOX_hasStartTopFontValue(BOX_Start arg)
{
  if (BOX_isStartFontValue(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_FontValue BOX_getStartTopFontValue(BOX_Start arg) */

BOX_FontValue BOX_getStartTopFontValue(BOX_Start arg)
{
  
    return (BOX_FontValue)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  BOX_Start BOX_setStartTopFontValue(BOX_Start arg, BOX_FontValue topFontValue) */

BOX_Start BOX_setStartTopFontValue(BOX_Start arg, BOX_FontValue topFontValue)
{
  if (BOX_isStartFontValue(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topFontValue), 1), 1), 0);
  }

  ATabort("Start has no TopFontValue: %t\n", arg);
  return (BOX_Start)NULL;
}

/*}}}  */
/*{{{  ATbool BOX_hasStartTopFontOption(BOX_Start arg) */

ATbool BOX_hasStartTopFontOption(BOX_Start arg)
{
  if (BOX_isStartFontOption(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_FontOption BOX_getStartTopFontOption(BOX_Start arg) */

BOX_FontOption BOX_getStartTopFontOption(BOX_Start arg)
{
  
    return (BOX_FontOption)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  BOX_Start BOX_setStartTopFontOption(BOX_Start arg, BOX_FontOption topFontOption) */

BOX_Start BOX_setStartTopFontOption(BOX_Start arg, BOX_FontOption topFontOption)
{
  if (BOX_isStartFontOption(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topFontOption), 1), 1), 0);
  }

  ATabort("Start has no TopFontOption: %t\n", arg);
  return (BOX_Start)NULL;
}

/*}}}  */
/*{{{  ATbool BOX_hasStartTopFontParam(BOX_Start arg) */

ATbool BOX_hasStartTopFontParam(BOX_Start arg)
{
  if (BOX_isStartFontParam(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_FontParam BOX_getStartTopFontParam(BOX_Start arg) */

BOX_FontParam BOX_getStartTopFontParam(BOX_Start arg)
{
  
    return (BOX_FontParam)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  BOX_Start BOX_setStartTopFontParam(BOX_Start arg, BOX_FontParam topFontParam) */

BOX_Start BOX_setStartTopFontParam(BOX_Start arg, BOX_FontParam topFontParam)
{
  if (BOX_isStartFontParam(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topFontParam), 1), 1), 0);
  }

  ATabort("Start has no TopFontParam: %t\n", arg);
  return (BOX_Start)NULL;
}

/*}}}  */
/*{{{  ATbool BOX_hasStartTopSpaceOption(BOX_Start arg) */

ATbool BOX_hasStartTopSpaceOption(BOX_Start arg)
{
  if (BOX_isStartSpaceOption(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_SpaceOption BOX_getStartTopSpaceOption(BOX_Start arg) */

BOX_SpaceOption BOX_getStartTopSpaceOption(BOX_Start arg)
{
  
    return (BOX_SpaceOption)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  BOX_Start BOX_setStartTopSpaceOption(BOX_Start arg, BOX_SpaceOption topSpaceOption) */

BOX_Start BOX_setStartTopSpaceOption(BOX_Start arg, BOX_SpaceOption topSpaceOption)
{
  if (BOX_isStartSpaceOption(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topSpaceOption), 1), 1), 0);
  }

  ATabort("Start has no TopSpaceOption: %t\n", arg);
  return (BOX_Start)NULL;
}

/*}}}  */
/*{{{  ATbool BOX_hasStartTopSpaceSymbol(BOX_Start arg) */

ATbool BOX_hasStartTopSpaceSymbol(BOX_Start arg)
{
  if (BOX_isStartSpaceSymbol(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_SpaceSymbol BOX_getStartTopSpaceSymbol(BOX_Start arg) */

BOX_SpaceSymbol BOX_getStartTopSpaceSymbol(BOX_Start arg)
{
  
    return (BOX_SpaceSymbol)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  BOX_Start BOX_setStartTopSpaceSymbol(BOX_Start arg, BOX_SpaceSymbol topSpaceSymbol) */

BOX_Start BOX_setStartTopSpaceSymbol(BOX_Start arg, BOX_SpaceSymbol topSpaceSymbol)
{
  if (BOX_isStartSpaceSymbol(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topSpaceSymbol), 1), 1), 0);
  }

  ATabort("Start has no TopSpaceSymbol: %t\n", arg);
  return (BOX_Start)NULL;
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
/*{{{  BOX_Box BOX_getStartTopBox(BOX_Start arg) */

BOX_Box BOX_getStartTopBox(BOX_Start arg)
{
  
    return (BOX_Box)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
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
/*{{{  ATbool BOX_hasStartTopEscaped(BOX_Start arg) */

ATbool BOX_hasStartTopEscaped(BOX_Start arg)
{
  if (BOX_isStartEscaped(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_Escaped BOX_getStartTopEscaped(BOX_Start arg) */

BOX_Escaped BOX_getStartTopEscaped(BOX_Start arg)
{
  
    return (BOX_Escaped)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  BOX_Start BOX_setStartTopEscaped(BOX_Start arg, BOX_Escaped topEscaped) */

BOX_Start BOX_setStartTopEscaped(BOX_Start arg, BOX_Escaped topEscaped)
{
  if (BOX_isStartEscaped(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topEscaped), 1), 1), 0);
  }

  ATabort("Start has no TopEscaped: %t\n", arg);
  return (BOX_Start)NULL;
}

/*}}}  */
/*{{{  ATbool BOX_hasStartTopNormal(BOX_Start arg) */

ATbool BOX_hasStartTopNormal(BOX_Start arg)
{
  if (BOX_isStartNormal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_Normal BOX_getStartTopNormal(BOX_Start arg) */

BOX_Normal BOX_getStartTopNormal(BOX_Start arg)
{
  
    return (BOX_Normal)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  BOX_Start BOX_setStartTopNormal(BOX_Start arg, BOX_Normal topNormal) */

BOX_Start BOX_setStartTopNormal(BOX_Start arg, BOX_Normal topNormal)
{
  if (BOX_isStartNormal(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topNormal), 1), 1), 0);
  }

  ATabort("Start has no TopNormal: %t\n", arg);
  return (BOX_Start)NULL;
}

/*}}}  */
/*{{{  ATbool BOX_hasStartTopStrCon(BOX_Start arg) */

ATbool BOX_hasStartTopStrCon(BOX_Start arg)
{
  if (BOX_isStartStrCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_StrCon BOX_getStartTopStrCon(BOX_Start arg) */

BOX_StrCon BOX_getStartTopStrCon(BOX_Start arg)
{
  
    return (BOX_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  BOX_Start BOX_setStartTopStrCon(BOX_Start arg, BOX_StrCon topStrCon) */

BOX_Start BOX_setStartTopStrCon(BOX_Start arg, BOX_StrCon topStrCon)
{
  if (BOX_isStartStrCon(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topStrCon), 1), 1), 0);
  }

  ATabort("Start has no TopStrCon: %t\n", arg);
  return (BOX_Start)NULL;
}

/*}}}  */
/*{{{  ATbool BOX_hasStartTopNatCon(BOX_Start arg) */

ATbool BOX_hasStartTopNatCon(BOX_Start arg)
{
  if (BOX_isStartNatCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_NatCon BOX_getStartTopNatCon(BOX_Start arg) */

BOX_NatCon BOX_getStartTopNatCon(BOX_Start arg)
{
  
    return (BOX_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  BOX_Start BOX_setStartTopNatCon(BOX_Start arg, BOX_NatCon topNatCon) */

BOX_Start BOX_setStartTopNatCon(BOX_Start arg, BOX_NatCon topNatCon)
{
  if (BOX_isStartNatCon(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topNatCon), 1), 1), 0);
  }

  ATabort("Start has no TopNatCon: %t\n", arg);
  return (BOX_Start)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  BOX_NatCon BOX_visitNatCon(BOX_NatCon arg, char* (*acceptString)(char*)) */

BOX_NatCon BOX_visitNatCon(BOX_NatCon arg, char* (*acceptString)(char*))
{
  if (BOX_isNatConDefault(arg)) {
    return BOX_makeNatConDefault(
        acceptString ? acceptString(BOX_getNatConString(arg)) : BOX_getNatConString(arg));
  }
  ATabort("not a NatCon: %t\n", arg);
  return (BOX_NatCon)NULL;
}

/*}}}  */
/*{{{  BOX_Normal BOX_visitNormal(BOX_Normal arg, char* (*acceptString)(char*)) */

BOX_Normal BOX_visitNormal(BOX_Normal arg, char* (*acceptString)(char*))
{
  if (BOX_isNormalDefault(arg)) {
    return BOX_makeNormalDefault(
        acceptString ? acceptString(BOX_getNormalString(arg)) : BOX_getNormalString(arg));
  }
  ATabort("not a Normal: %t\n", arg);
  return (BOX_Normal)NULL;
}

/*}}}  */
/*{{{  BOX_Escaped BOX_visitEscaped(BOX_Escaped arg, char* (*acceptString)(char*)) */

BOX_Escaped BOX_visitEscaped(BOX_Escaped arg, char* (*acceptString)(char*))
{
  if (BOX_isEscapedSpecialCharacter(arg)) {
    return BOX_makeEscapedSpecialCharacter(
        acceptString ? acceptString(BOX_getEscapedString(arg)) : BOX_getEscapedString(arg));
  }
  if (BOX_isEscapedOctal(arg)) {
    return BOX_makeEscapedOctal(
        acceptString ? acceptString(BOX_getEscapedString(arg)) : BOX_getEscapedString(arg));
  }
  ATabort("not a Escaped: %t\n", arg);
  return (BOX_Escaped)NULL;
}

/*}}}  */
/*{{{  BOX_StrCon BOX_visitStrCon(BOX_StrCon arg, char* (*acceptString)(char*)) */

BOX_StrCon BOX_visitStrCon(BOX_StrCon arg, char* (*acceptString)(char*))
{
  if (BOX_isStrConDefault(arg)) {
    return BOX_makeStrConDefault(
        acceptString ? acceptString(BOX_getStrConString(arg)) : BOX_getStrConString(arg));
  }
  ATabort("not a StrCon: %t\n", arg);
  return (BOX_StrCon)NULL;
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
/*{{{  BOX_Box BOX_visitBox(BOX_Box arg, BOX_StrCon (*acceptStrCon)(BOX_StrCon), BOX_OptLayout (*acceptWsAfterH)(BOX_OptLayout), BOX_SpaceOptionOptions (*acceptOptions)(BOX_SpaceOptionOptions), BOX_OptLayout (*acceptWsAfterOptions)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterBracketOpen)(BOX_OptLayout), BOX_BoxList (*acceptList)(BOX_BoxList), BOX_OptLayout (*acceptWsAfterList)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterV)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterHV)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterHOV)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterI)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterBox)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterWD)(BOX_OptLayout), BOX_FontOperator (*acceptFontOperator)(BOX_FontOperator), BOX_OptLayout (*acceptWsAfterFontOperator)(BOX_OptLayout)) */

BOX_Box BOX_visitBox(BOX_Box arg, BOX_StrCon (*acceptStrCon)(BOX_StrCon), BOX_OptLayout (*acceptWsAfterH)(BOX_OptLayout), BOX_SpaceOptionOptions (*acceptOptions)(BOX_SpaceOptionOptions), BOX_OptLayout (*acceptWsAfterOptions)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterBracketOpen)(BOX_OptLayout), BOX_BoxList (*acceptList)(BOX_BoxList), BOX_OptLayout (*acceptWsAfterList)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterV)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterHV)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterHOV)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterI)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterBox)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterWD)(BOX_OptLayout), BOX_FontOperator (*acceptFontOperator)(BOX_FontOperator), BOX_OptLayout (*acceptWsAfterFontOperator)(BOX_OptLayout))
{
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
        BOX_visitBox(BOX_getBoxBox(arg), acceptStrCon, acceptWsAfterH, acceptOptions, acceptWsAfterOptions, acceptWsAfterBracketOpen, acceptList, acceptWsAfterList, acceptWsAfterV, acceptWsAfterHV, acceptWsAfterHOV, acceptWsAfterI, acceptWsAfterBox, acceptWsAfterWD, acceptFontOperator, acceptWsAfterFontOperator),
        acceptWsAfterBox ? acceptWsAfterBox(BOX_getBoxWsAfterBox(arg)) : BOX_getBoxWsAfterBox(arg));
  }
  if (BOX_isBoxWd(arg)) {
    return BOX_makeBoxWd(
        acceptWsAfterWD ? acceptWsAfterWD(BOX_getBoxWsAfterWD(arg)) : BOX_getBoxWsAfterWD(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(BOX_getBoxWsAfterBracketOpen(arg)) : BOX_getBoxWsAfterBracketOpen(arg),
        BOX_visitBox(BOX_getBoxBox(arg), acceptStrCon, acceptWsAfterH, acceptOptions, acceptWsAfterOptions, acceptWsAfterBracketOpen, acceptList, acceptWsAfterList, acceptWsAfterV, acceptWsAfterHV, acceptWsAfterHOV, acceptWsAfterI, acceptWsAfterBox, acceptWsAfterWD, acceptFontOperator, acceptWsAfterFontOperator),
        acceptWsAfterBox ? acceptWsAfterBox(BOX_getBoxWsAfterBox(arg)) : BOX_getBoxWsAfterBox(arg));
  }
  if (BOX_isBoxFontOperator(arg)) {
    return BOX_makeBoxFontOperator(
        acceptFontOperator ? acceptFontOperator(BOX_getBoxFontOperator(arg)) : BOX_getBoxFontOperator(arg),
        acceptWsAfterFontOperator ? acceptWsAfterFontOperator(BOX_getBoxWsAfterFontOperator(arg)) : BOX_getBoxWsAfterFontOperator(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(BOX_getBoxWsAfterBracketOpen(arg)) : BOX_getBoxWsAfterBracketOpen(arg),
        BOX_visitBox(BOX_getBoxBox(arg), acceptStrCon, acceptWsAfterH, acceptOptions, acceptWsAfterOptions, acceptWsAfterBracketOpen, acceptList, acceptWsAfterList, acceptWsAfterV, acceptWsAfterHV, acceptWsAfterHOV, acceptWsAfterI, acceptWsAfterBox, acceptWsAfterWD, acceptFontOperator, acceptWsAfterFontOperator),
        acceptWsAfterBox ? acceptWsAfterBox(BOX_getBoxWsAfterBox(arg)) : BOX_getBoxWsAfterBox(arg));
  }
  ATabort("not a Box: %t\n", arg);
  return (BOX_Box)NULL;
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
/*{{{  BOX_FontId BOX_visitFontId(BOX_FontId arg, char* (*acceptString)(char*)) */

BOX_FontId BOX_visitFontId(BOX_FontId arg, char* (*acceptString)(char*))
{
  if (BOX_isFontIdDefault(arg)) {
    return BOX_makeFontIdDefault(
        acceptString ? acceptString(BOX_getFontIdString(arg)) : BOX_getFontIdString(arg));
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
/*{{{  BOX_OptLayout BOX_visitOptLayout(BOX_OptLayout arg, char* (*acceptString)(char*)) */

BOX_OptLayout BOX_visitOptLayout(BOX_OptLayout arg, char* (*acceptString)(char*))
{
  if (BOX_isOptLayoutAbsent(arg)) {
    return BOX_makeOptLayoutAbsent();
  }
  if (BOX_isOptLayoutPresent(arg)) {
    return BOX_makeOptLayoutPresent(
        acceptString ? acceptString(BOX_getOptLayoutString(arg)) : BOX_getOptLayoutString(arg));
  }
  ATabort("not a OptLayout: %t\n", arg);
  return (BOX_OptLayout)NULL;
}

/*}}}  */
/*{{{  BOX_Start BOX_visitStart(BOX_Start arg, BOX_OptLayout (*acceptWsBefore)(BOX_OptLayout), BOX_FontId (*acceptTopFontId)(BOX_FontId), BOX_OptLayout (*acceptWsAfter)(BOX_OptLayout), int (*acceptAmbCnt)(int), BOX_FontOperator (*acceptTopFontOperator)(BOX_FontOperator), BOX_FontValue (*acceptTopFontValue)(BOX_FontValue), BOX_FontOption (*acceptTopFontOption)(BOX_FontOption), BOX_FontParam (*acceptTopFontParam)(BOX_FontParam), BOX_SpaceOption (*acceptTopSpaceOption)(BOX_SpaceOption), BOX_SpaceSymbol (*acceptTopSpaceSymbol)(BOX_SpaceSymbol), BOX_Box (*acceptTopBox)(BOX_Box), BOX_Escaped (*acceptTopEscaped)(BOX_Escaped), BOX_Normal (*acceptTopNormal)(BOX_Normal), BOX_StrCon (*acceptTopStrCon)(BOX_StrCon), BOX_NatCon (*acceptTopNatCon)(BOX_NatCon)) */

BOX_Start BOX_visitStart(BOX_Start arg, BOX_OptLayout (*acceptWsBefore)(BOX_OptLayout), BOX_FontId (*acceptTopFontId)(BOX_FontId), BOX_OptLayout (*acceptWsAfter)(BOX_OptLayout), int (*acceptAmbCnt)(int), BOX_FontOperator (*acceptTopFontOperator)(BOX_FontOperator), BOX_FontValue (*acceptTopFontValue)(BOX_FontValue), BOX_FontOption (*acceptTopFontOption)(BOX_FontOption), BOX_FontParam (*acceptTopFontParam)(BOX_FontParam), BOX_SpaceOption (*acceptTopSpaceOption)(BOX_SpaceOption), BOX_SpaceSymbol (*acceptTopSpaceSymbol)(BOX_SpaceSymbol), BOX_Box (*acceptTopBox)(BOX_Box), BOX_Escaped (*acceptTopEscaped)(BOX_Escaped), BOX_Normal (*acceptTopNormal)(BOX_Normal), BOX_StrCon (*acceptTopStrCon)(BOX_StrCon), BOX_NatCon (*acceptTopNatCon)(BOX_NatCon))
{
  if (BOX_isStartFontId(arg)) {
    return BOX_makeStartFontId(
        acceptWsBefore ? acceptWsBefore(BOX_getStartWsBefore(arg)) : BOX_getStartWsBefore(arg),
        acceptTopFontId ? acceptTopFontId(BOX_getStartTopFontId(arg)) : BOX_getStartTopFontId(arg),
        acceptWsAfter ? acceptWsAfter(BOX_getStartWsAfter(arg)) : BOX_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(BOX_getStartAmbCnt(arg)) : BOX_getStartAmbCnt(arg));
  }
  if (BOX_isStartFontOperator(arg)) {
    return BOX_makeStartFontOperator(
        acceptWsBefore ? acceptWsBefore(BOX_getStartWsBefore(arg)) : BOX_getStartWsBefore(arg),
        acceptTopFontOperator ? acceptTopFontOperator(BOX_getStartTopFontOperator(arg)) : BOX_getStartTopFontOperator(arg),
        acceptWsAfter ? acceptWsAfter(BOX_getStartWsAfter(arg)) : BOX_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(BOX_getStartAmbCnt(arg)) : BOX_getStartAmbCnt(arg));
  }
  if (BOX_isStartFontValue(arg)) {
    return BOX_makeStartFontValue(
        acceptWsBefore ? acceptWsBefore(BOX_getStartWsBefore(arg)) : BOX_getStartWsBefore(arg),
        acceptTopFontValue ? acceptTopFontValue(BOX_getStartTopFontValue(arg)) : BOX_getStartTopFontValue(arg),
        acceptWsAfter ? acceptWsAfter(BOX_getStartWsAfter(arg)) : BOX_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(BOX_getStartAmbCnt(arg)) : BOX_getStartAmbCnt(arg));
  }
  if (BOX_isStartFontOption(arg)) {
    return BOX_makeStartFontOption(
        acceptWsBefore ? acceptWsBefore(BOX_getStartWsBefore(arg)) : BOX_getStartWsBefore(arg),
        acceptTopFontOption ? acceptTopFontOption(BOX_getStartTopFontOption(arg)) : BOX_getStartTopFontOption(arg),
        acceptWsAfter ? acceptWsAfter(BOX_getStartWsAfter(arg)) : BOX_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(BOX_getStartAmbCnt(arg)) : BOX_getStartAmbCnt(arg));
  }
  if (BOX_isStartFontParam(arg)) {
    return BOX_makeStartFontParam(
        acceptWsBefore ? acceptWsBefore(BOX_getStartWsBefore(arg)) : BOX_getStartWsBefore(arg),
        acceptTopFontParam ? acceptTopFontParam(BOX_getStartTopFontParam(arg)) : BOX_getStartTopFontParam(arg),
        acceptWsAfter ? acceptWsAfter(BOX_getStartWsAfter(arg)) : BOX_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(BOX_getStartAmbCnt(arg)) : BOX_getStartAmbCnt(arg));
  }
  if (BOX_isStartSpaceOption(arg)) {
    return BOX_makeStartSpaceOption(
        acceptWsBefore ? acceptWsBefore(BOX_getStartWsBefore(arg)) : BOX_getStartWsBefore(arg),
        acceptTopSpaceOption ? acceptTopSpaceOption(BOX_getStartTopSpaceOption(arg)) : BOX_getStartTopSpaceOption(arg),
        acceptWsAfter ? acceptWsAfter(BOX_getStartWsAfter(arg)) : BOX_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(BOX_getStartAmbCnt(arg)) : BOX_getStartAmbCnt(arg));
  }
  if (BOX_isStartSpaceSymbol(arg)) {
    return BOX_makeStartSpaceSymbol(
        acceptWsBefore ? acceptWsBefore(BOX_getStartWsBefore(arg)) : BOX_getStartWsBefore(arg),
        acceptTopSpaceSymbol ? acceptTopSpaceSymbol(BOX_getStartTopSpaceSymbol(arg)) : BOX_getStartTopSpaceSymbol(arg),
        acceptWsAfter ? acceptWsAfter(BOX_getStartWsAfter(arg)) : BOX_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(BOX_getStartAmbCnt(arg)) : BOX_getStartAmbCnt(arg));
  }
  if (BOX_isStartBox(arg)) {
    return BOX_makeStartBox(
        acceptWsBefore ? acceptWsBefore(BOX_getStartWsBefore(arg)) : BOX_getStartWsBefore(arg),
        acceptTopBox ? acceptTopBox(BOX_getStartTopBox(arg)) : BOX_getStartTopBox(arg),
        acceptWsAfter ? acceptWsAfter(BOX_getStartWsAfter(arg)) : BOX_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(BOX_getStartAmbCnt(arg)) : BOX_getStartAmbCnt(arg));
  }
  if (BOX_isStartEscaped(arg)) {
    return BOX_makeStartEscaped(
        acceptWsBefore ? acceptWsBefore(BOX_getStartWsBefore(arg)) : BOX_getStartWsBefore(arg),
        acceptTopEscaped ? acceptTopEscaped(BOX_getStartTopEscaped(arg)) : BOX_getStartTopEscaped(arg),
        acceptWsAfter ? acceptWsAfter(BOX_getStartWsAfter(arg)) : BOX_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(BOX_getStartAmbCnt(arg)) : BOX_getStartAmbCnt(arg));
  }
  if (BOX_isStartNormal(arg)) {
    return BOX_makeStartNormal(
        acceptWsBefore ? acceptWsBefore(BOX_getStartWsBefore(arg)) : BOX_getStartWsBefore(arg),
        acceptTopNormal ? acceptTopNormal(BOX_getStartTopNormal(arg)) : BOX_getStartTopNormal(arg),
        acceptWsAfter ? acceptWsAfter(BOX_getStartWsAfter(arg)) : BOX_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(BOX_getStartAmbCnt(arg)) : BOX_getStartAmbCnt(arg));
  }
  if (BOX_isStartStrCon(arg)) {
    return BOX_makeStartStrCon(
        acceptWsBefore ? acceptWsBefore(BOX_getStartWsBefore(arg)) : BOX_getStartWsBefore(arg),
        acceptTopStrCon ? acceptTopStrCon(BOX_getStartTopStrCon(arg)) : BOX_getStartTopStrCon(arg),
        acceptWsAfter ? acceptWsAfter(BOX_getStartWsAfter(arg)) : BOX_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(BOX_getStartAmbCnt(arg)) : BOX_getStartAmbCnt(arg));
  }
  if (BOX_isStartNatCon(arg)) {
    return BOX_makeStartNatCon(
        acceptWsBefore ? acceptWsBefore(BOX_getStartWsBefore(arg)) : BOX_getStartWsBefore(arg),
        acceptTopNatCon ? acceptTopNatCon(BOX_getStartTopNatCon(arg)) : BOX_getStartTopNatCon(arg),
        acceptWsAfter ? acceptWsAfter(BOX_getStartWsAfter(arg)) : BOX_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(BOX_getStartAmbCnt(arg)) : BOX_getStartAmbCnt(arg));
  }
  ATabort("not a Start: %t\n", arg);
  return (BOX_Start)NULL;
}

/*}}}  */

/*}}}  */
