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
typedef struct ATerm _BOX_SOption;
typedef struct ATerm _BOX_SOptions;
typedef struct ATerm _BOX_SOptionList;
typedef struct ATerm _BOX_BoxList;
typedef struct ATerm _BOX_BoxList;
typedef struct ATerm _BOX_Box;
typedef struct ATerm _BOX_Start;
typedef struct ATerm _BOX_OptLayout;

/*}}}  */

/*{{{  void BOX_initBoxApi(void) */

void BOX_initBoxApi(void)
{
  init_Box_dict();
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
/*{{{  BOX_SOption BOX_SOptionFromTerm(ATerm t) */

BOX_SOption BOX_SOptionFromTerm(ATerm t)
{
  return (BOX_SOption)t;
}

/*}}}  */
/*{{{  ATerm BOX_SOptionToTerm(BOX_SOption arg) */

ATerm BOX_SOptionToTerm(BOX_SOption arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  BOX_SOptions BOX_SOptionsFromTerm(ATerm t) */

BOX_SOptions BOX_SOptionsFromTerm(ATerm t)
{
  return (BOX_SOptions)t;
}

/*}}}  */
/*{{{  ATerm BOX_SOptionsToTerm(BOX_SOptions arg) */

ATerm BOX_SOptionsToTerm(BOX_SOptions arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  BOX_SOptionList BOX_SOptionListFromTerm(ATerm t) */

BOX_SOptionList BOX_SOptionListFromTerm(ATerm t)
{
  return (BOX_SOptionList)t;
}

/*}}}  */
/*{{{  ATerm BOX_SOptionListToTerm(BOX_SOptionList arg) */

ATerm BOX_SOptionListToTerm(BOX_SOptionList arg)
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

/*}}}  */
/*{{{  list functions */

int BOX_getSOptionListLength (BOX_SOptionList arg) {
  if (ATisEmpty((ATermList) arg)) {
    return 0;
  }
  return (ATgetLength((ATermList) arg) / 2) + 1;
}
BOX_SOptionList reverseSOptionList(BOX_SOptionList arg) {
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

  return (BOX_SOptionList) result;
}
BOX_SOptionList BOX_appendSOptionList(BOX_SOptionList arg0, BOX_OptLayout wsAfterHead, BOX_SOption arg1) {
  return BOX_concatSOptionList(arg0, wsAfterHead, BOX_makeSOptionListSingle(arg1));
}
BOX_SOptionList BOX_concatSOptionList(BOX_SOptionList arg0, BOX_OptLayout wsAfterHead, BOX_SOptionList arg1) {
  if (ATisEmpty((ATermList) arg0)) {
    return arg1;
  }
  arg1 = BOX_makeSOptionListMany((BOX_SOption)ATgetFirst((ATermList) arg0), wsAfterHead,  arg1);
  arg1 = (BOX_SOptionList) ATgetNext((ATermList) arg1);
  return (BOX_SOptionList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
BOX_SOptionList BOX_sliceSOptionList(BOX_SOptionList arg, int start, int end) {
  return (BOX_SOptionList) ATgetSlice((ATermList) arg, start * 2, end * 2);
}
BOX_SOption BOX_getSOptionListSOptionAt(BOX_SOptionList arg, int index) {
 return (BOX_SOption)ATelementAt((ATermList) arg,index * 2);
}
BOX_SOptionList BOX_replaceSOptionListSOptionAt(BOX_SOptionList arg, BOX_SOption elem, int index) {
 return (BOX_SOptionList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index * 2);
}
BOX_SOptionList BOX_makeSOptionList2(BOX_OptLayout wsAfterHead, BOX_SOption elem1, BOX_SOption elem2) {
  return BOX_makeSOptionListMany(elem1, wsAfterHead, BOX_makeSOptionListSingle(elem2));
}
BOX_SOptionList BOX_makeSOptionList3(BOX_OptLayout wsAfterHead, BOX_SOption elem1, BOX_SOption elem2, BOX_SOption elem3) {
  return BOX_makeSOptionListMany(elem1, wsAfterHead, BOX_makeSOptionList2(wsAfterHead, elem2, elem3));
}
BOX_SOptionList BOX_makeSOptionList4(BOX_OptLayout wsAfterHead, BOX_SOption elem1, BOX_SOption elem2, BOX_SOption elem3, BOX_SOption elem4) {
  return BOX_makeSOptionListMany(elem1, wsAfterHead, BOX_makeSOptionList3(wsAfterHead, elem2, elem3, elem4));
}
BOX_SOptionList BOX_makeSOptionList5(BOX_OptLayout wsAfterHead, BOX_SOption elem1, BOX_SOption elem2, BOX_SOption elem3, BOX_SOption elem4, BOX_SOption elem5) {
  return BOX_makeSOptionListMany(elem1, wsAfterHead, BOX_makeSOptionList4(wsAfterHead, elem2, elem3, elem4, elem5));
}
BOX_SOptionList BOX_makeSOptionList6(BOX_OptLayout wsAfterHead, BOX_SOption elem1, BOX_SOption elem2, BOX_SOption elem3, BOX_SOption elem4, BOX_SOption elem5, BOX_SOption elem6) {
  return BOX_makeSOptionListMany(elem1, wsAfterHead, BOX_makeSOptionList5(wsAfterHead, elem2, elem3, elem4, elem5, elem6));
}
int BOX_getBoxListLength (BOX_BoxList arg) {
  if (ATisEmpty((ATermList) arg)) {
    return 0;
  }
  return (ATgetLength((ATermList) arg) / 2) + 1;
}
BOX_BoxList reverseBoxList(BOX_BoxList arg) {
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
/*{{{  BOX_SpaceSymbol BOX_makeSpaceSymbolHs() */

BOX_SpaceSymbol BOX_makeSpaceSymbolHs()
{
  return (BOX_SpaceSymbol)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun15))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun16))), (ATerm)ATmakeAppl1(BOX_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun18, (ATerm)ATmakeAppl1(BOX_afun19, (ATerm)ATmakeAppl0(BOX_afun15)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun15))));
}

/*}}}  */
/*{{{  BOX_SpaceSymbol BOX_makeSpaceSymbolVs() */

BOX_SpaceSymbol BOX_makeSpaceSymbolVs()
{
  return (BOX_SpaceSymbol)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun20))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun16))), (ATerm)ATmakeAppl1(BOX_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun18, (ATerm)ATmakeAppl1(BOX_afun19, (ATerm)ATmakeAppl0(BOX_afun20)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun20))));
}

/*}}}  */
/*{{{  BOX_SpaceSymbol BOX_makeSpaceSymbolIs() */

BOX_SpaceSymbol BOX_makeSpaceSymbolIs()
{
  return (BOX_SpaceSymbol)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun21))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun16))), (ATerm)ATmakeAppl1(BOX_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun18, (ATerm)ATmakeAppl1(BOX_afun19, (ATerm)ATmakeAppl0(BOX_afun21)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun21))));
}

/*}}}  */
/*{{{  BOX_SOption BOX_makeSOptionDefault(BOX_SpaceSymbol SpaceSymbol, BOX_OptLayout wsAfterSpaceSymbol, BOX_OptLayout wsAfterEquals, BOX_NatCon NatCon) */

BOX_SOption BOX_makeSOptionDefault(BOX_SpaceSymbol SpaceSymbol, BOX_OptLayout wsAfterSpaceSymbol, BOX_OptLayout wsAfterEquals, BOX_NatCon NatCon)
{
  return (BOX_SOption)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun24))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun16)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun25))), (ATerm)ATmakeAppl0(BOX_afun6)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) NatCon), (ATerm) wsAfterEquals), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun24))), (ATerm) wsAfterSpaceSymbol), (ATerm) SpaceSymbol));
}

/*}}}  */
/*{{{  BOX_SOptions BOX_makeSOptionsDefault(BOX_SOptionList list) */

BOX_SOptions BOX_makeSOptionsDefault(BOX_SOptionList list)
{
  return (BOX_SOptions)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun25))))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun26))), (ATerm)ATmakeAppl0(BOX_afun6)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun7, (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun25))))), (ATerm) list)));
}

/*}}}  */
/*{{{  BOX_SOptionList BOX_makeSOptionListEmpty() */

BOX_SOptionList BOX_makeSOptionListEmpty()
{
  return (BOX_SOptionList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  BOX_SOptionList BOX_makeSOptionListSingle(BOX_SOption head) */

BOX_SOptionList BOX_makeSOptionListSingle(BOX_SOption head)
{
  return (BOX_SOptionList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  BOX_SOptionList BOX_makeSOptionListMany(BOX_SOption head, BOX_OptLayout wsAfterHead, BOX_SOptionList tail) */

BOX_SOptionList BOX_makeSOptionListMany(BOX_SOption head, BOX_OptLayout wsAfterHead, BOX_SOptionList tail)
{
  if (BOX_isSOptionListEmpty(tail)) {
    return BOX_makeSOptionListSingle(head);
  }
  return (BOX_SOptionList)(ATerm)ATinsert(ATinsert((ATermList)tail, (ATerm) wsAfterHead), (ATerm) head);
}

/*}}}  */
/*{{{  BOX_BoxList BOX_makeBoxListDefault(BOX_BoxList list) */

BOX_BoxList BOX_makeBoxListDefault(BOX_BoxList list)
{
  return (BOX_BoxList)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun27))))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun28))), (ATerm)ATmakeAppl0(BOX_afun6)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl1(BOX_afun7, (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun8, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun27))))), (ATerm) list)));
}

/*}}}  */
/*{{{  BOX_BoxList BOX_makeBoxListIstar(BOX_OptLayout wsAfterIStar, BOX_SOptions SOptions, BOX_OptLayout wsAfterSOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList BoxList, BOX_OptLayout wsAfterBoxList) */

BOX_BoxList BOX_makeBoxListIstar(BOX_OptLayout wsAfterIStar, BOX_SOptions SOptions, BOX_OptLayout wsAfterSOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList BoxList, BOX_OptLayout wsAfterBoxList)
{
  return (BOX_BoxList)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun29))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun28)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun30))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun31))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun28))), (ATerm)ATmakeAppl1(BOX_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun18, (ATerm)ATmakeAppl1(BOX_afun19, (ATerm)ATmakeAppl0(BOX_afun32)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun29))), (ATerm) wsAfterBoxList), (ATerm) BoxList), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun30))), (ATerm) wsAfterSOptions), (ATerm) SOptions), (ATerm) wsAfterIStar), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun31))));
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
/*{{{  BOX_Box BOX_makeBoxString(BOX_StrCon StrCon) */

BOX_Box BOX_makeBoxString(BOX_StrCon StrCon)
{
  return (BOX_Box)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun13)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun27))), (ATerm)ATmakeAppl1(BOX_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun18, (ATerm)ATmakeAppl1(BOX_afun19, (ATerm)ATmakeAppl0(BOX_afun33)))))), (ATerm)ATmakeList1((ATerm) StrCon));
}

/*}}}  */
/*{{{  BOX_Box BOX_makeBoxH(BOX_OptLayout wsAfterH, BOX_SOptions SOptions, BOX_OptLayout wsAfterSOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList BoxList, BOX_OptLayout wsAfterBoxList) */

BOX_Box BOX_makeBoxH(BOX_OptLayout wsAfterH, BOX_SOptions SOptions, BOX_OptLayout wsAfterSOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList BoxList, BOX_OptLayout wsAfterBoxList)
{
  return (BOX_Box)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun29))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun28)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun30))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun34))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun27))), (ATerm)ATmakeAppl1(BOX_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun18, (ATerm)ATmakeAppl1(BOX_afun19, (ATerm)ATmakeAppl0(BOX_afun34)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun29))), (ATerm) wsAfterBoxList), (ATerm) BoxList), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun30))), (ATerm) wsAfterSOptions), (ATerm) SOptions), (ATerm) wsAfterH), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun34))));
}

/*}}}  */
/*{{{  BOX_Box BOX_makeBoxV(BOX_OptLayout wsAfterV, BOX_SOptions SOptions, BOX_OptLayout wsAfterSOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList BoxList, BOX_OptLayout wsAfterBoxList) */

BOX_Box BOX_makeBoxV(BOX_OptLayout wsAfterV, BOX_SOptions SOptions, BOX_OptLayout wsAfterSOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList BoxList, BOX_OptLayout wsAfterBoxList)
{
  return (BOX_Box)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun29))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun28)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun30))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun35))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun27))), (ATerm)ATmakeAppl1(BOX_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun18, (ATerm)ATmakeAppl1(BOX_afun19, (ATerm)ATmakeAppl0(BOX_afun35)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun29))), (ATerm) wsAfterBoxList), (ATerm) BoxList), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun30))), (ATerm) wsAfterSOptions), (ATerm) SOptions), (ATerm) wsAfterV), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun35))));
}

/*}}}  */
/*{{{  BOX_Box BOX_makeBoxHV(BOX_OptLayout wsAfterHV, BOX_SOptions SOptions, BOX_OptLayout wsAfterSOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList BoxList, BOX_OptLayout wsAfterBoxList) */

BOX_Box BOX_makeBoxHV(BOX_OptLayout wsAfterHV, BOX_SOptions SOptions, BOX_OptLayout wsAfterSOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList BoxList, BOX_OptLayout wsAfterBoxList)
{
  return (BOX_Box)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun29))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun28)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun30))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun36))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun27))), (ATerm)ATmakeAppl1(BOX_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun18, (ATerm)ATmakeAppl1(BOX_afun19, (ATerm)ATmakeAppl0(BOX_afun36)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun29))), (ATerm) wsAfterBoxList), (ATerm) BoxList), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun30))), (ATerm) wsAfterSOptions), (ATerm) SOptions), (ATerm) wsAfterHV), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun36))));
}

/*}}}  */
/*{{{  BOX_Box BOX_makeBoxHOV(BOX_OptLayout wsAfterHOV, BOX_SOptions SOptions, BOX_OptLayout wsAfterSOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList BoxList, BOX_OptLayout wsAfterBoxList) */

BOX_Box BOX_makeBoxHOV(BOX_OptLayout wsAfterHOV, BOX_SOptions SOptions, BOX_OptLayout wsAfterSOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList BoxList, BOX_OptLayout wsAfterBoxList)
{
  return (BOX_Box)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun29))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun28)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun30))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun37))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun27))), (ATerm)ATmakeAppl1(BOX_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun18, (ATerm)ATmakeAppl1(BOX_afun19, (ATerm)ATmakeAppl0(BOX_afun37)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun29))), (ATerm) wsAfterBoxList), (ATerm) BoxList), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun30))), (ATerm) wsAfterSOptions), (ATerm) SOptions), (ATerm) wsAfterHOV), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun37))));
}

/*}}}  */
/*{{{  BOX_Box BOX_makeBoxI(BOX_OptLayout wsAfterI, BOX_SOptions SOptions, BOX_OptLayout wsAfterSOptions, BOX_OptLayout wsAfterBracketOpen, BOX_Box Box, BOX_OptLayout wsAfterBox) */

BOX_Box BOX_makeBoxI(BOX_OptLayout wsAfterI, BOX_SOptions SOptions, BOX_OptLayout wsAfterSOptions, BOX_OptLayout wsAfterBracketOpen, BOX_Box Box, BOX_OptLayout wsAfterBox)
{
  return (BOX_Box)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun29))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun27)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun30))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun38))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun27))), (ATerm)ATmakeAppl1(BOX_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun18, (ATerm)ATmakeAppl1(BOX_afun19, (ATerm)ATmakeAppl0(BOX_afun38)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun29))), (ATerm) wsAfterBox), (ATerm) Box), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun30))), (ATerm) wsAfterSOptions), (ATerm) SOptions), (ATerm) wsAfterI), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun38))));
}

/*}}}  */
/*{{{  BOX_Box BOX_makeBoxWD(BOX_OptLayout wsAfterWD, BOX_OptLayout wsAfterBracketOpen, BOX_Box Box, BOX_OptLayout wsAfterBox) */

BOX_Box BOX_makeBoxWD(BOX_OptLayout wsAfterWD, BOX_OptLayout wsAfterBracketOpen, BOX_Box Box, BOX_OptLayout wsAfterBox)
{
  return (BOX_Box)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun29))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun27)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun30))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun39))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun27))), (ATerm)ATmakeAppl1(BOX_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun18, (ATerm)ATmakeAppl1(BOX_afun19, (ATerm)ATmakeAppl0(BOX_afun39)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun29))), (ATerm) wsAfterBox), (ATerm) Box), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun30))), (ATerm) wsAfterWD), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun39))));
}

/*}}}  */
/*{{{  BOX_Box BOX_makeBoxLST(BOX_OptLayout wsAfterLST, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList BoxList, BOX_OptLayout wsAfterBoxList) */

BOX_Box BOX_makeBoxLST(BOX_OptLayout wsAfterLST, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList BoxList, BOX_OptLayout wsAfterBoxList)
{
  return (BOX_Box)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun29))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun28)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun30))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun40))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun27))), (ATerm)ATmakeAppl1(BOX_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun18, (ATerm)ATmakeAppl1(BOX_afun19, (ATerm)ATmakeAppl0(BOX_afun40)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun29))), (ATerm) wsAfterBoxList), (ATerm) BoxList), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun30))), (ATerm) wsAfterLST), (ATerm)ATmakeAppl1(BOX_afun14, (ATerm)ATmakeAppl0(BOX_afun40))));
}

/*}}}  */
/*{{{  BOX_Start BOX_makeStartSOptions(BOX_OptLayout wsBefore, BOX_SOptions topSOptions, BOX_OptLayout wsAfter, int ambCnt) */

BOX_Start BOX_makeStartSOptions(BOX_OptLayout wsBefore, BOX_SOptions topSOptions, BOX_OptLayout wsAfter, int ambCnt)
{
  return (BOX_Start)(ATerm)ATmakeAppl2(BOX_afun41, (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun26)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun42)), (ATerm)ATmakeAppl0(BOX_afun6)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topSOptions), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  BOX_Start BOX_makeStartSOption(BOX_OptLayout wsBefore, BOX_SOption topSOption, BOX_OptLayout wsAfter, int ambCnt) */

BOX_Start BOX_makeStartSOption(BOX_OptLayout wsBefore, BOX_SOption topSOption, BOX_OptLayout wsAfter, int ambCnt)
{
  return (BOX_Start)(ATerm)ATmakeAppl2(BOX_afun41, (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun25)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun42)), (ATerm)ATmakeAppl0(BOX_afun6)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topSOption), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  BOX_Start BOX_makeStartSpaceSymbol(BOX_OptLayout wsBefore, BOX_SpaceSymbol topSpaceSymbol, BOX_OptLayout wsAfter, int ambCnt) */

BOX_Start BOX_makeStartSpaceSymbol(BOX_OptLayout wsBefore, BOX_SpaceSymbol topSpaceSymbol, BOX_OptLayout wsAfter, int ambCnt)
{
  return (BOX_Start)(ATerm)ATmakeAppl2(BOX_afun41, (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun16)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun42)), (ATerm)ATmakeAppl0(BOX_afun6)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topSpaceSymbol), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  BOX_Start BOX_makeStartBoxList(BOX_OptLayout wsBefore, BOX_BoxList topBoxList, BOX_OptLayout wsAfter, int ambCnt) */

BOX_Start BOX_makeStartBoxList(BOX_OptLayout wsBefore, BOX_BoxList topBoxList, BOX_OptLayout wsAfter, int ambCnt)
{
  return (BOX_Start)(ATerm)ATmakeAppl2(BOX_afun41, (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun28)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun42)), (ATerm)ATmakeAppl0(BOX_afun6)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topBoxList), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  BOX_Start BOX_makeStartBox(BOX_OptLayout wsBefore, BOX_Box topBox, BOX_OptLayout wsAfter, int ambCnt) */

BOX_Start BOX_makeStartBox(BOX_OptLayout wsBefore, BOX_Box topBox, BOX_OptLayout wsAfter, int ambCnt)
{
  return (BOX_Start)(ATerm)ATmakeAppl2(BOX_afun41, (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun27)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun42)), (ATerm)ATmakeAppl0(BOX_afun6)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topBox), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  BOX_Start BOX_makeStartEscaped(BOX_OptLayout wsBefore, BOX_Escaped topEscaped, BOX_OptLayout wsAfter, int ambCnt) */

BOX_Start BOX_makeStartEscaped(BOX_OptLayout wsBefore, BOX_Escaped topEscaped, BOX_OptLayout wsAfter, int ambCnt)
{
  return (BOX_Start)(ATerm)ATmakeAppl2(BOX_afun41, (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun12)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun42)), (ATerm)ATmakeAppl0(BOX_afun6)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topEscaped), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  BOX_Start BOX_makeStartNormal(BOX_OptLayout wsBefore, BOX_Normal topNormal, BOX_OptLayout wsAfter, int ambCnt) */

BOX_Start BOX_makeStartNormal(BOX_OptLayout wsBefore, BOX_Normal topNormal, BOX_OptLayout wsAfter, int ambCnt)
{
  return (BOX_Start)(ATerm)ATmakeAppl2(BOX_afun41, (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun11)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun42)), (ATerm)ATmakeAppl0(BOX_afun6)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topNormal), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  BOX_Start BOX_makeStartStrCon(BOX_OptLayout wsBefore, BOX_StrCon topStrCon, BOX_OptLayout wsAfter, int ambCnt) */

BOX_Start BOX_makeStartStrCon(BOX_OptLayout wsBefore, BOX_StrCon topStrCon, BOX_OptLayout wsAfter, int ambCnt)
{
  return (BOX_Start)(ATerm)ATmakeAppl2(BOX_afun41, (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun13)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun42)), (ATerm)ATmakeAppl0(BOX_afun6)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topStrCon), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  BOX_Start BOX_makeStartNatCon(BOX_OptLayout wsBefore, BOX_NatCon topNatCon, BOX_OptLayout wsAfter, int ambCnt) */

BOX_Start BOX_makeStartNatCon(BOX_OptLayout wsBefore, BOX_NatCon topNatCon, BOX_OptLayout wsAfter, int ambCnt)
{
  return (BOX_Start)(ATerm)ATmakeAppl2(BOX_afun41, (ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun4)))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23)))), (ATerm)ATmakeAppl1(BOX_afun3, (ATerm)ATmakeAppl0(BOX_afun42)), (ATerm)ATmakeAppl0(BOX_afun6)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topNatCon), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_makeOptLayoutAbsent() */

BOX_OptLayout BOX_makeOptLayoutAbsent()
{
  return (BOX_OptLayout)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATempty, (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23))), (ATerm)ATmakeAppl0(BOX_afun6)), (ATerm)ATempty);
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_makeOptLayoutPresent(char* string) */

BOX_OptLayout BOX_makeOptLayoutPresent(char* string)
{
  return (BOX_OptLayout)(ATerm)ATmakeAppl2(BOX_afun0, (ATerm)ATmakeAppl3(BOX_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl0(BOX_afun23))), (ATerm)ATmakeAppl1(BOX_afun5, (ATerm)ATmakeAppl1(BOX_afun22, (ATerm)ATmakeAppl0(BOX_afun23))), (ATerm)ATmakeAppl0(BOX_afun6)), (ATerm) ((ATerm) BOX_stringToChars(string)));
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

ATbool BOX_isEqualSOption(BOX_SOption arg0, BOX_SOption arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualSOptions(BOX_SOptions arg0, BOX_SOptions arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualSOptionList(BOX_SOptionList arg0, BOX_SOptionList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualBoxList(BOX_BoxList arg0, BOX_BoxList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualBoxList(BOX_BoxList arg0, BOX_BoxList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualBox(BOX_Box arg0, BOX_Box arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualStart(BOX_Start arg0, BOX_Start arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool BOX_isEqualOptLayout(BOX_OptLayout arg0, BOX_OptLayout arg1)
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
  if (BOX_isSpaceSymbolHs(arg)) {
    return ATtrue;
  }
  else if (BOX_isSpaceSymbolVs(arg)) {
    return ATtrue;
  }
  else if (BOX_isSpaceSymbolIs(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool BOX_isSpaceSymbolHs(BOX_SpaceSymbol arg) */

inline ATbool BOX_isSpaceSymbolHs(BOX_SpaceSymbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternSpaceSymbolHs);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isSpaceSymbolVs(BOX_SpaceSymbol arg) */

inline ATbool BOX_isSpaceSymbolVs(BOX_SpaceSymbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternSpaceSymbolVs);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isSpaceSymbolIs(BOX_SpaceSymbol arg) */

inline ATbool BOX_isSpaceSymbolIs(BOX_SpaceSymbol arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternSpaceSymbolIs);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */

/*}}}  */
/*{{{  BOX_SOption accessors */

/*{{{  ATbool BOX_isValidSOption(BOX_SOption arg) */

ATbool BOX_isValidSOption(BOX_SOption arg)
{
  if (BOX_isSOptionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool BOX_isSOptionDefault(BOX_SOption arg) */

inline ATbool BOX_isSOptionDefault(BOX_SOption arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, BOX_patternSOptionDefault, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool BOX_hasSOptionSpaceSymbol(BOX_SOption arg) */

ATbool BOX_hasSOptionSpaceSymbol(BOX_SOption arg)
{
  if (BOX_isSOptionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_SpaceSymbol BOX_getSOptionSpaceSymbol(BOX_SOption arg) */

BOX_SpaceSymbol BOX_getSOptionSpaceSymbol(BOX_SOption arg)
{
  
    return (BOX_SpaceSymbol)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  BOX_SOption BOX_setSOptionSpaceSymbol(BOX_SOption arg, BOX_SpaceSymbol SpaceSymbol) */

BOX_SOption BOX_setSOptionSpaceSymbol(BOX_SOption arg, BOX_SpaceSymbol SpaceSymbol)
{
  if (BOX_isSOptionDefault(arg)) {
    return (BOX_SOption)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) SpaceSymbol), 0), 1);
  }

  ATabort("SOption has no SpaceSymbol: %t\n", arg);
  return (BOX_SOption)NULL;
}

/*}}}  */
/*{{{  ATbool BOX_hasSOptionWsAfterSpaceSymbol(BOX_SOption arg) */

ATbool BOX_hasSOptionWsAfterSpaceSymbol(BOX_SOption arg)
{
  if (BOX_isSOptionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getSOptionWsAfterSpaceSymbol(BOX_SOption arg) */

BOX_OptLayout BOX_getSOptionWsAfterSpaceSymbol(BOX_SOption arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  BOX_SOption BOX_setSOptionWsAfterSpaceSymbol(BOX_SOption arg, BOX_OptLayout wsAfterSpaceSymbol) */

BOX_SOption BOX_setSOptionWsAfterSpaceSymbol(BOX_SOption arg, BOX_OptLayout wsAfterSpaceSymbol)
{
  if (BOX_isSOptionDefault(arg)) {
    return (BOX_SOption)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSpaceSymbol), 1), 1);
  }

  ATabort("SOption has no WsAfterSpaceSymbol: %t\n", arg);
  return (BOX_SOption)NULL;
}

/*}}}  */
/*{{{  ATbool BOX_hasSOptionWsAfterEquals(BOX_SOption arg) */

ATbool BOX_hasSOptionWsAfterEquals(BOX_SOption arg)
{
  if (BOX_isSOptionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getSOptionWsAfterEquals(BOX_SOption arg) */

BOX_OptLayout BOX_getSOptionWsAfterEquals(BOX_SOption arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  BOX_SOption BOX_setSOptionWsAfterEquals(BOX_SOption arg, BOX_OptLayout wsAfterEquals) */

BOX_SOption BOX_setSOptionWsAfterEquals(BOX_SOption arg, BOX_OptLayout wsAfterEquals)
{
  if (BOX_isSOptionDefault(arg)) {
    return (BOX_SOption)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterEquals), 3), 1);
  }

  ATabort("SOption has no WsAfterEquals: %t\n", arg);
  return (BOX_SOption)NULL;
}

/*}}}  */
/*{{{  ATbool BOX_hasSOptionNatCon(BOX_SOption arg) */

ATbool BOX_hasSOptionNatCon(BOX_SOption arg)
{
  if (BOX_isSOptionDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_NatCon BOX_getSOptionNatCon(BOX_SOption arg) */

BOX_NatCon BOX_getSOptionNatCon(BOX_SOption arg)
{
  
    return (BOX_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  BOX_SOption BOX_setSOptionNatCon(BOX_SOption arg, BOX_NatCon NatCon) */

BOX_SOption BOX_setSOptionNatCon(BOX_SOption arg, BOX_NatCon NatCon)
{
  if (BOX_isSOptionDefault(arg)) {
    return (BOX_SOption)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) NatCon), 4), 1);
  }

  ATabort("SOption has no NatCon: %t\n", arg);
  return (BOX_SOption)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  BOX_SOptions accessors */

/*{{{  ATbool BOX_isValidSOptions(BOX_SOptions arg) */

ATbool BOX_isValidSOptions(BOX_SOptions arg)
{
  if (BOX_isSOptionsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool BOX_isSOptionsDefault(BOX_SOptions arg) */

inline ATbool BOX_isSOptionsDefault(BOX_SOptions arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, BOX_patternSOptionsDefault, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool BOX_hasSOptionsList(BOX_SOptions arg) */

ATbool BOX_hasSOptionsList(BOX_SOptions arg)
{
  if (BOX_isSOptionsDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_SOptionList BOX_getSOptionsList(BOX_SOptions arg) */

BOX_SOptionList BOX_getSOptionsList(BOX_SOptions arg)
{
  
    return (BOX_SOptionList)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  BOX_SOptions BOX_setSOptionsList(BOX_SOptions arg, BOX_SOptionList list) */

BOX_SOptions BOX_setSOptionsList(BOX_SOptions arg, BOX_SOptionList list)
{
  if (BOX_isSOptionsDefault(arg)) {
    return (BOX_SOptions)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) list), 1), 0), 1);
  }

  ATabort("SOptions has no List: %t\n", arg);
  return (BOX_SOptions)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  BOX_SOptionList accessors */

/*{{{  ATbool BOX_isValidSOptionList(BOX_SOptionList arg) */

ATbool BOX_isValidSOptionList(BOX_SOptionList arg)
{
  if (BOX_isSOptionListEmpty(arg)) {
    return ATtrue;
  }
  else if (BOX_isSOptionListSingle(arg)) {
    return ATtrue;
  }
  else if (BOX_isSOptionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool BOX_isSOptionListEmpty(BOX_SOptionList arg) */

inline ATbool BOX_isSOptionListEmpty(BOX_SOptionList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, BOX_patternSOptionListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool BOX_isSOptionListSingle(BOX_SOptionList arg) */

inline ATbool BOX_isSOptionListSingle(BOX_SOptionList arg)
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
      last_result = ATmatchTerm((ATerm)arg, BOX_patternSOptionListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isSOptionListMany(BOX_SOptionList arg) */

inline ATbool BOX_isSOptionListMany(BOX_SOptionList arg)
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
      last_result = ATmatchTerm((ATerm)arg, BOX_patternSOptionListMany, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool BOX_hasSOptionListHead(BOX_SOptionList arg) */

ATbool BOX_hasSOptionListHead(BOX_SOptionList arg)
{
  if (BOX_isSOptionListSingle(arg)) {
    return ATtrue;
  }
  else if (BOX_isSOptionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_SOption BOX_getSOptionListHead(BOX_SOptionList arg) */

BOX_SOption BOX_getSOptionListHead(BOX_SOptionList arg)
{
  if (BOX_isSOptionListSingle(arg)) {
    return (BOX_SOption)ATgetFirst((ATermList)arg);
  }
  else 
    return (BOX_SOption)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  BOX_SOptionList BOX_setSOptionListHead(BOX_SOptionList arg, BOX_SOption head) */

BOX_SOptionList BOX_setSOptionListHead(BOX_SOptionList arg, BOX_SOption head)
{
  if (BOX_isSOptionListSingle(arg)) {
    return (BOX_SOptionList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (BOX_isSOptionListMany(arg)) {
    return (BOX_SOptionList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("SOptionList has no Head: %t\n", arg);
  return (BOX_SOptionList)NULL;
}

/*}}}  */
/*{{{  ATbool BOX_hasSOptionListWsAfterHead(BOX_SOptionList arg) */

ATbool BOX_hasSOptionListWsAfterHead(BOX_SOptionList arg)
{
  if (BOX_isSOptionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getSOptionListWsAfterHead(BOX_SOptionList arg) */

BOX_OptLayout BOX_getSOptionListWsAfterHead(BOX_SOptionList arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  BOX_SOptionList BOX_setSOptionListWsAfterHead(BOX_SOptionList arg, BOX_OptLayout wsAfterHead) */

BOX_SOptionList BOX_setSOptionListWsAfterHead(BOX_SOptionList arg, BOX_OptLayout wsAfterHead)
{
  if (BOX_isSOptionListMany(arg)) {
    return (BOX_SOptionList)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterHead), 1);
  }

  ATabort("SOptionList has no WsAfterHead: %t\n", arg);
  return (BOX_SOptionList)NULL;
}

/*}}}  */
/*{{{  ATbool BOX_hasSOptionListTail(BOX_SOptionList arg) */

ATbool BOX_hasSOptionListTail(BOX_SOptionList arg)
{
  if (BOX_isSOptionListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_SOptionList BOX_getSOptionListTail(BOX_SOptionList arg) */

BOX_SOptionList BOX_getSOptionListTail(BOX_SOptionList arg)
{
  
    return (BOX_SOptionList)ATgetTail((ATermList)arg, 2);
}

/*}}}  */
/*{{{  BOX_SOptionList BOX_setSOptionListTail(BOX_SOptionList arg, BOX_SOptionList tail) */

BOX_SOptionList BOX_setSOptionListTail(BOX_SOptionList arg, BOX_SOptionList tail)
{
  if (BOX_isSOptionListMany(arg)) {
    return (BOX_SOptionList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 2);
  }

  ATabort("SOptionList has no Tail: %t\n", arg);
  return (BOX_SOptionList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  BOX_BoxList accessors */

/*{{{  ATbool BOX_isValidBoxList(BOX_BoxList arg) */

ATbool BOX_isValidBoxList(BOX_BoxList arg)
{
  if (BOX_isBoxListDefault(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxListIstar(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool BOX_isBoxListDefault(BOX_BoxList arg) */

inline ATbool BOX_isBoxListDefault(BOX_BoxList arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternBoxListDefault, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isBoxListIstar(BOX_BoxList arg) */

inline ATbool BOX_isBoxListIstar(BOX_BoxList arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternBoxListIstar, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxListList(BOX_BoxList arg) */

ATbool BOX_hasBoxListList(BOX_BoxList arg)
{
  if (BOX_isBoxListDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_BoxList BOX_getBoxListList(BOX_BoxList arg) */

BOX_BoxList BOX_getBoxListList(BOX_BoxList arg)
{
  
    return (BOX_BoxList)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  BOX_BoxList BOX_setBoxListList(BOX_BoxList arg, BOX_BoxList list) */

BOX_BoxList BOX_setBoxListList(BOX_BoxList arg, BOX_BoxList list)
{
  if (BOX_isBoxListDefault(arg)) {
    return (BOX_BoxList)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) list), 1), 0), 1);
  }

  ATabort("BoxList has no List: %t\n", arg);
  return (BOX_BoxList)NULL;
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxListWsAfterIStar(BOX_BoxList arg) */

ATbool BOX_hasBoxListWsAfterIStar(BOX_BoxList arg)
{
  if (BOX_isBoxListIstar(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getBoxListWsAfterIStar(BOX_BoxList arg) */

BOX_OptLayout BOX_getBoxListWsAfterIStar(BOX_BoxList arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  BOX_BoxList BOX_setBoxListWsAfterIStar(BOX_BoxList arg, BOX_OptLayout wsAfterIStar) */

BOX_BoxList BOX_setBoxListWsAfterIStar(BOX_BoxList arg, BOX_OptLayout wsAfterIStar)
{
  if (BOX_isBoxListIstar(arg)) {
    return (BOX_BoxList)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterIStar), 1), 1);
  }

  ATabort("BoxList has no WsAfterIStar: %t\n", arg);
  return (BOX_BoxList)NULL;
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxListSOptions(BOX_BoxList arg) */

ATbool BOX_hasBoxListSOptions(BOX_BoxList arg)
{
  if (BOX_isBoxListIstar(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_SOptions BOX_getBoxListSOptions(BOX_BoxList arg) */

BOX_SOptions BOX_getBoxListSOptions(BOX_BoxList arg)
{
  
    return (BOX_SOptions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  BOX_BoxList BOX_setBoxListSOptions(BOX_BoxList arg, BOX_SOptions SOptions) */

BOX_BoxList BOX_setBoxListSOptions(BOX_BoxList arg, BOX_SOptions SOptions)
{
  if (BOX_isBoxListIstar(arg)) {
    return (BOX_BoxList)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) SOptions), 2), 1);
  }

  ATabort("BoxList has no SOptions: %t\n", arg);
  return (BOX_BoxList)NULL;
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxListWsAfterSOptions(BOX_BoxList arg) */

ATbool BOX_hasBoxListWsAfterSOptions(BOX_BoxList arg)
{
  if (BOX_isBoxListIstar(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getBoxListWsAfterSOptions(BOX_BoxList arg) */

BOX_OptLayout BOX_getBoxListWsAfterSOptions(BOX_BoxList arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  BOX_BoxList BOX_setBoxListWsAfterSOptions(BOX_BoxList arg, BOX_OptLayout wsAfterSOptions) */

BOX_BoxList BOX_setBoxListWsAfterSOptions(BOX_BoxList arg, BOX_OptLayout wsAfterSOptions)
{
  if (BOX_isBoxListIstar(arg)) {
    return (BOX_BoxList)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSOptions), 3), 1);
  }

  ATabort("BoxList has no WsAfterSOptions: %t\n", arg);
  return (BOX_BoxList)NULL;
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxListWsAfterBracketOpen(BOX_BoxList arg) */

ATbool BOX_hasBoxListWsAfterBracketOpen(BOX_BoxList arg)
{
  if (BOX_isBoxListIstar(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getBoxListWsAfterBracketOpen(BOX_BoxList arg) */

BOX_OptLayout BOX_getBoxListWsAfterBracketOpen(BOX_BoxList arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  BOX_BoxList BOX_setBoxListWsAfterBracketOpen(BOX_BoxList arg, BOX_OptLayout wsAfterBracketOpen) */

BOX_BoxList BOX_setBoxListWsAfterBracketOpen(BOX_BoxList arg, BOX_OptLayout wsAfterBracketOpen)
{
  if (BOX_isBoxListIstar(arg)) {
    return (BOX_BoxList)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 5), 1);
  }

  ATabort("BoxList has no WsAfterBracketOpen: %t\n", arg);
  return (BOX_BoxList)NULL;
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxListBoxList(BOX_BoxList arg) */

ATbool BOX_hasBoxListBoxList(BOX_BoxList arg)
{
  if (BOX_isBoxListIstar(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_BoxList BOX_getBoxListBoxList(BOX_BoxList arg) */

BOX_BoxList BOX_getBoxListBoxList(BOX_BoxList arg)
{
  
    return (BOX_BoxList)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6);
}

/*}}}  */
/*{{{  BOX_BoxList BOX_setBoxListBoxList(BOX_BoxList arg, BOX_BoxList BoxList) */

BOX_BoxList BOX_setBoxListBoxList(BOX_BoxList arg, BOX_BoxList BoxList)
{
  if (BOX_isBoxListIstar(arg)) {
    return (BOX_BoxList)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) BoxList), 6), 1);
  }

  ATabort("BoxList has no BoxList: %t\n", arg);
  return (BOX_BoxList)NULL;
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxListWsAfterBoxList(BOX_BoxList arg) */

ATbool BOX_hasBoxListWsAfterBoxList(BOX_BoxList arg)
{
  if (BOX_isBoxListIstar(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getBoxListWsAfterBoxList(BOX_BoxList arg) */

BOX_OptLayout BOX_getBoxListWsAfterBoxList(BOX_BoxList arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  BOX_BoxList BOX_setBoxListWsAfterBoxList(BOX_BoxList arg, BOX_OptLayout wsAfterBoxList) */

BOX_BoxList BOX_setBoxListWsAfterBoxList(BOX_BoxList arg, BOX_OptLayout wsAfterBoxList)
{
  if (BOX_isBoxListIstar(arg)) {
    return (BOX_BoxList)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBoxList), 7), 1);
  }

  ATabort("BoxList has no WsAfterBoxList: %t\n", arg);
  return (BOX_BoxList)NULL;
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
  else if (BOX_isBoxHV(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxHOV(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxI(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxWD(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxLST(arg)) {
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
/*{{{  inline ATbool BOX_isBoxHV(BOX_Box arg) */

inline ATbool BOX_isBoxHV(BOX_Box arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternBoxHV, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isBoxHOV(BOX_Box arg) */

inline ATbool BOX_isBoxHOV(BOX_Box arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternBoxHOV, NULL, NULL, NULL, NULL, NULL, NULL);
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
/*{{{  inline ATbool BOX_isBoxWD(BOX_Box arg) */

inline ATbool BOX_isBoxWD(BOX_Box arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternBoxWD, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isBoxLST(BOX_Box arg) */

inline ATbool BOX_isBoxLST(BOX_Box arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternBoxLST, NULL, NULL, NULL, NULL);
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
/*{{{  ATbool BOX_hasBoxSOptions(BOX_Box arg) */

ATbool BOX_hasBoxSOptions(BOX_Box arg)
{
  if (BOX_isBoxH(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxV(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxHV(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxHOV(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxI(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_SOptions BOX_getBoxSOptions(BOX_Box arg) */

BOX_SOptions BOX_getBoxSOptions(BOX_Box arg)
{
  if (BOX_isBoxH(arg)) {
    return (BOX_SOptions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else if (BOX_isBoxV(arg)) {
    return (BOX_SOptions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else if (BOX_isBoxHV(arg)) {
    return (BOX_SOptions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else if (BOX_isBoxHOV(arg)) {
    return (BOX_SOptions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
  }
  else 
    return (BOX_SOptions)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  BOX_Box BOX_setBoxSOptions(BOX_Box arg, BOX_SOptions SOptions) */

BOX_Box BOX_setBoxSOptions(BOX_Box arg, BOX_SOptions SOptions)
{
  if (BOX_isBoxH(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) SOptions), 2), 1);
  }
  else if (BOX_isBoxV(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) SOptions), 2), 1);
  }
  else if (BOX_isBoxHV(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) SOptions), 2), 1);
  }
  else if (BOX_isBoxHOV(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) SOptions), 2), 1);
  }
  else if (BOX_isBoxI(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) SOptions), 2), 1);
  }

  ATabort("Box has no SOptions: %t\n", arg);
  return (BOX_Box)NULL;
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxWsAfterSOptions(BOX_Box arg) */

ATbool BOX_hasBoxWsAfterSOptions(BOX_Box arg)
{
  if (BOX_isBoxH(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxV(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxHV(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxHOV(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxI(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getBoxWsAfterSOptions(BOX_Box arg) */

BOX_OptLayout BOX_getBoxWsAfterSOptions(BOX_Box arg)
{
  if (BOX_isBoxH(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (BOX_isBoxV(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (BOX_isBoxHV(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (BOX_isBoxHOV(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  BOX_Box BOX_setBoxWsAfterSOptions(BOX_Box arg, BOX_OptLayout wsAfterSOptions) */

BOX_Box BOX_setBoxWsAfterSOptions(BOX_Box arg, BOX_OptLayout wsAfterSOptions)
{
  if (BOX_isBoxH(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSOptions), 3), 1);
  }
  else if (BOX_isBoxV(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSOptions), 3), 1);
  }
  else if (BOX_isBoxHV(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSOptions), 3), 1);
  }
  else if (BOX_isBoxHOV(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSOptions), 3), 1);
  }
  else if (BOX_isBoxI(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSOptions), 3), 1);
  }

  ATabort("Box has no WsAfterSOptions: %t\n", arg);
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
  else if (BOX_isBoxHV(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxHOV(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxI(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxWD(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxLST(arg)) {
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
  else if (BOX_isBoxHV(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else if (BOX_isBoxHOV(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else if (BOX_isBoxI(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else if (BOX_isBoxWD(arg)) {
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
  else if (BOX_isBoxHV(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 5), 1);
  }
  else if (BOX_isBoxHOV(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 5), 1);
  }
  else if (BOX_isBoxI(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 5), 1);
  }
  else if (BOX_isBoxWD(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 3), 1);
  }
  else if (BOX_isBoxLST(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 3), 1);
  }

  ATabort("Box has no WsAfterBracketOpen: %t\n", arg);
  return (BOX_Box)NULL;
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxBoxList(BOX_Box arg) */

ATbool BOX_hasBoxBoxList(BOX_Box arg)
{
  if (BOX_isBoxH(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxV(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxHV(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxHOV(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxLST(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_BoxList BOX_getBoxBoxList(BOX_Box arg) */

BOX_BoxList BOX_getBoxBoxList(BOX_Box arg)
{
  if (BOX_isBoxH(arg)) {
    return (BOX_BoxList)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6);
  }
  else if (BOX_isBoxV(arg)) {
    return (BOX_BoxList)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6);
  }
  else if (BOX_isBoxHV(arg)) {
    return (BOX_BoxList)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6);
  }
  else if (BOX_isBoxHOV(arg)) {
    return (BOX_BoxList)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 6);
  }
  else 
    return (BOX_BoxList)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  BOX_Box BOX_setBoxBoxList(BOX_Box arg, BOX_BoxList BoxList) */

BOX_Box BOX_setBoxBoxList(BOX_Box arg, BOX_BoxList BoxList)
{
  if (BOX_isBoxH(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) BoxList), 6), 1);
  }
  else if (BOX_isBoxV(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) BoxList), 6), 1);
  }
  else if (BOX_isBoxHV(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) BoxList), 6), 1);
  }
  else if (BOX_isBoxHOV(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) BoxList), 6), 1);
  }
  else if (BOX_isBoxLST(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) BoxList), 4), 1);
  }

  ATabort("Box has no BoxList: %t\n", arg);
  return (BOX_Box)NULL;
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxWsAfterBoxList(BOX_Box arg) */

ATbool BOX_hasBoxWsAfterBoxList(BOX_Box arg)
{
  if (BOX_isBoxH(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxV(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxHV(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxHOV(arg)) {
    return ATtrue;
  }
  else if (BOX_isBoxLST(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getBoxWsAfterBoxList(BOX_Box arg) */

BOX_OptLayout BOX_getBoxWsAfterBoxList(BOX_Box arg)
{
  if (BOX_isBoxH(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else if (BOX_isBoxV(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else if (BOX_isBoxHV(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else if (BOX_isBoxHOV(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else 
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  BOX_Box BOX_setBoxWsAfterBoxList(BOX_Box arg, BOX_OptLayout wsAfterBoxList) */

BOX_Box BOX_setBoxWsAfterBoxList(BOX_Box arg, BOX_OptLayout wsAfterBoxList)
{
  if (BOX_isBoxH(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBoxList), 7), 1);
  }
  else if (BOX_isBoxV(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBoxList), 7), 1);
  }
  else if (BOX_isBoxHV(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBoxList), 7), 1);
  }
  else if (BOX_isBoxHOV(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBoxList), 7), 1);
  }
  else if (BOX_isBoxLST(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBoxList), 5), 1);
  }

  ATabort("Box has no WsAfterBoxList: %t\n", arg);
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
  if (BOX_isBoxHV(arg)) {
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
  if (BOX_isBoxHV(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterHV), 1), 1);
  }

  ATabort("Box has no WsAfterHV: %t\n", arg);
  return (BOX_Box)NULL;
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxWsAfterHOV(BOX_Box arg) */

ATbool BOX_hasBoxWsAfterHOV(BOX_Box arg)
{
  if (BOX_isBoxHOV(arg)) {
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
  if (BOX_isBoxHOV(arg)) {
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
  else if (BOX_isBoxWD(arg)) {
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
  else if (BOX_isBoxWD(arg)) {
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
  else if (BOX_isBoxWD(arg)) {
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
  else if (BOX_isBoxWD(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBox), 5), 1);
  }

  ATabort("Box has no WsAfterBox: %t\n", arg);
  return (BOX_Box)NULL;
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxWsAfterWD(BOX_Box arg) */

ATbool BOX_hasBoxWsAfterWD(BOX_Box arg)
{
  if (BOX_isBoxWD(arg)) {
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
  if (BOX_isBoxWD(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterWD), 1), 1);
  }

  ATabort("Box has no WsAfterWD: %t\n", arg);
  return (BOX_Box)NULL;
}

/*}}}  */
/*{{{  ATbool BOX_hasBoxWsAfterLST(BOX_Box arg) */

ATbool BOX_hasBoxWsAfterLST(BOX_Box arg)
{
  if (BOX_isBoxLST(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_OptLayout BOX_getBoxWsAfterLST(BOX_Box arg) */

BOX_OptLayout BOX_getBoxWsAfterLST(BOX_Box arg)
{
  
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  BOX_Box BOX_setBoxWsAfterLST(BOX_Box arg, BOX_OptLayout wsAfterLST) */

BOX_Box BOX_setBoxWsAfterLST(BOX_Box arg, BOX_OptLayout wsAfterLST)
{
  if (BOX_isBoxLST(arg)) {
    return (BOX_Box)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLST), 1), 1);
  }

  ATabort("Box has no WsAfterLST: %t\n", arg);
  return (BOX_Box)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  BOX_Start accessors */

/*{{{  ATbool BOX_isValidStart(BOX_Start arg) */

ATbool BOX_isValidStart(BOX_Start arg)
{
  if (BOX_isStartSOptions(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartSOption(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartSpaceSymbol(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartBoxList(arg)) {
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
/*{{{  inline ATbool BOX_isStartSOptions(BOX_Start arg) */

inline ATbool BOX_isStartSOptions(BOX_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternStartSOptions, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool BOX_isStartSOption(BOX_Start arg) */

inline ATbool BOX_isStartSOption(BOX_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternStartSOption, NULL, NULL, NULL, NULL);
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
/*{{{  inline ATbool BOX_isStartBoxList(BOX_Start arg) */

inline ATbool BOX_isStartBoxList(BOX_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, BOX_patternStartBoxList, NULL, NULL, NULL, NULL);
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
  if (BOX_isStartSOptions(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartSOption(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartSpaceSymbol(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartBoxList(arg)) {
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
  if (BOX_isStartSOptions(arg)) {
    return (BOX_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (BOX_isStartSOption(arg)) {
    return (BOX_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (BOX_isStartSpaceSymbol(arg)) {
    return (BOX_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (BOX_isStartBoxList(arg)) {
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
  if (BOX_isStartSOptions(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (BOX_isStartSOption(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (BOX_isStartSpaceSymbol(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (BOX_isStartBoxList(arg)) {
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
/*{{{  ATbool BOX_hasStartTopSOptions(BOX_Start arg) */

ATbool BOX_hasStartTopSOptions(BOX_Start arg)
{
  if (BOX_isStartSOptions(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_SOptions BOX_getStartTopSOptions(BOX_Start arg) */

BOX_SOptions BOX_getStartTopSOptions(BOX_Start arg)
{
  
    return (BOX_SOptions)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  BOX_Start BOX_setStartTopSOptions(BOX_Start arg, BOX_SOptions topSOptions) */

BOX_Start BOX_setStartTopSOptions(BOX_Start arg, BOX_SOptions topSOptions)
{
  if (BOX_isStartSOptions(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topSOptions), 1), 1), 0);
  }

  ATabort("Start has no TopSOptions: %t\n", arg);
  return (BOX_Start)NULL;
}

/*}}}  */
/*{{{  ATbool BOX_hasStartWsAfter(BOX_Start arg) */

ATbool BOX_hasStartWsAfter(BOX_Start arg)
{
  if (BOX_isStartSOptions(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartSOption(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartSpaceSymbol(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartBoxList(arg)) {
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
  if (BOX_isStartSOptions(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (BOX_isStartSOption(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (BOX_isStartSpaceSymbol(arg)) {
    return (BOX_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (BOX_isStartBoxList(arg)) {
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
  if (BOX_isStartSOptions(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (BOX_isStartSOption(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (BOX_isStartSpaceSymbol(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (BOX_isStartBoxList(arg)) {
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
  if (BOX_isStartSOptions(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartSOption(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartSpaceSymbol(arg)) {
    return ATtrue;
  }
  else if (BOX_isStartBoxList(arg)) {
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
  if (BOX_isStartSOptions(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else if (BOX_isStartSOption(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else if (BOX_isStartSpaceSymbol(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else if (BOX_isStartBoxList(arg)) {
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
  if (BOX_isStartSOptions(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (BOX_isStartSOption(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (BOX_isStartSpaceSymbol(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (BOX_isStartBoxList(arg)) {
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
/*{{{  ATbool BOX_hasStartTopSOption(BOX_Start arg) */

ATbool BOX_hasStartTopSOption(BOX_Start arg)
{
  if (BOX_isStartSOption(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_SOption BOX_getStartTopSOption(BOX_Start arg) */

BOX_SOption BOX_getStartTopSOption(BOX_Start arg)
{
  
    return (BOX_SOption)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  BOX_Start BOX_setStartTopSOption(BOX_Start arg, BOX_SOption topSOption) */

BOX_Start BOX_setStartTopSOption(BOX_Start arg, BOX_SOption topSOption)
{
  if (BOX_isStartSOption(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topSOption), 1), 1), 0);
  }

  ATabort("Start has no TopSOption: %t\n", arg);
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
/*{{{  ATbool BOX_hasStartTopBoxList(BOX_Start arg) */

ATbool BOX_hasStartTopBoxList(BOX_Start arg)
{
  if (BOX_isStartBoxList(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  BOX_BoxList BOX_getStartTopBoxList(BOX_Start arg) */

BOX_BoxList BOX_getStartTopBoxList(BOX_Start arg)
{
  
    return (BOX_BoxList)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  BOX_Start BOX_setStartTopBoxList(BOX_Start arg, BOX_BoxList topBoxList) */

BOX_Start BOX_setStartTopBoxList(BOX_Start arg, BOX_BoxList topBoxList)
{
  if (BOX_isStartBoxList(arg)) {
    return (BOX_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topBoxList), 1), 1), 0);
  }

  ATabort("Start has no TopBoxList: %t\n", arg);
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
  if (BOX_isSpaceSymbolHs(arg)) {
    return BOX_makeSpaceSymbolHs();
  }
  if (BOX_isSpaceSymbolVs(arg)) {
    return BOX_makeSpaceSymbolVs();
  }
  if (BOX_isSpaceSymbolIs(arg)) {
    return BOX_makeSpaceSymbolIs();
  }
  ATabort("not a SpaceSymbol: %t\n", arg);
  return (BOX_SpaceSymbol)NULL;
}

/*}}}  */
/*{{{  BOX_SOption BOX_visitSOption(BOX_SOption arg, BOX_SpaceSymbol (*acceptSpaceSymbol)(BOX_SpaceSymbol), BOX_OptLayout (*acceptWsAfterSpaceSymbol)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterEquals)(BOX_OptLayout), BOX_NatCon (*acceptNatCon)(BOX_NatCon)) */

BOX_SOption BOX_visitSOption(BOX_SOption arg, BOX_SpaceSymbol (*acceptSpaceSymbol)(BOX_SpaceSymbol), BOX_OptLayout (*acceptWsAfterSpaceSymbol)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterEquals)(BOX_OptLayout), BOX_NatCon (*acceptNatCon)(BOX_NatCon))
{
  if (BOX_isSOptionDefault(arg)) {
    return BOX_makeSOptionDefault(
        acceptSpaceSymbol ? acceptSpaceSymbol(BOX_getSOptionSpaceSymbol(arg)) : BOX_getSOptionSpaceSymbol(arg),
        acceptWsAfterSpaceSymbol ? acceptWsAfterSpaceSymbol(BOX_getSOptionWsAfterSpaceSymbol(arg)) : BOX_getSOptionWsAfterSpaceSymbol(arg),
        acceptWsAfterEquals ? acceptWsAfterEquals(BOX_getSOptionWsAfterEquals(arg)) : BOX_getSOptionWsAfterEquals(arg),
        acceptNatCon ? acceptNatCon(BOX_getSOptionNatCon(arg)) : BOX_getSOptionNatCon(arg));
  }
  ATabort("not a SOption: %t\n", arg);
  return (BOX_SOption)NULL;
}

/*}}}  */
/*{{{  BOX_SOptions BOX_visitSOptions(BOX_SOptions arg, BOX_SOptionList (*acceptList)(BOX_SOptionList)) */

BOX_SOptions BOX_visitSOptions(BOX_SOptions arg, BOX_SOptionList (*acceptList)(BOX_SOptionList))
{
  if (BOX_isSOptionsDefault(arg)) {
    return BOX_makeSOptionsDefault(
        acceptList ? acceptList(BOX_getSOptionsList(arg)) : BOX_getSOptionsList(arg));
  }
  ATabort("not a SOptions: %t\n", arg);
  return (BOX_SOptions)NULL;
}

/*}}}  */
/*{{{  BOX_SOptionList BOX_visitSOptionList(BOX_SOptionList arg, BOX_SOption (*acceptHead)(BOX_SOption), BOX_OptLayout (*acceptWsAfterHead)(BOX_OptLayout)) */

BOX_SOptionList BOX_visitSOptionList(BOX_SOptionList arg, BOX_SOption (*acceptHead)(BOX_SOption), BOX_OptLayout (*acceptWsAfterHead)(BOX_OptLayout))
{
  if (BOX_isSOptionListEmpty(arg)) {
    return BOX_makeSOptionListEmpty();
  }
  if (BOX_isSOptionListSingle(arg)) {
    return BOX_makeSOptionListSingle(
        acceptHead ? acceptHead(BOX_getSOptionListHead(arg)) : BOX_getSOptionListHead(arg));
  }
  if (BOX_isSOptionListMany(arg)) {
    return BOX_makeSOptionListMany(
        acceptHead ? acceptHead(BOX_getSOptionListHead(arg)) : BOX_getSOptionListHead(arg),
        acceptWsAfterHead ? acceptWsAfterHead(BOX_getSOptionListWsAfterHead(arg)) : BOX_getSOptionListWsAfterHead(arg),
        BOX_visitSOptionList(BOX_getSOptionListTail(arg), acceptHead, acceptWsAfterHead));
  }
  ATabort("not a SOptionList: %t\n", arg);
  return (BOX_SOptionList)NULL;
}

/*}}}  */
/*{{{  BOX_BoxList BOX_visitBoxList(BOX_BoxList arg, BOX_BoxList (*acceptList)(BOX_BoxList), BOX_OptLayout (*acceptWsAfterIStar)(BOX_OptLayout), BOX_SOptions (*acceptSOptions)(BOX_SOptions), BOX_OptLayout (*acceptWsAfterSOptions)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterBracketOpen)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterBoxList)(BOX_OptLayout)) */

BOX_BoxList BOX_visitBoxList(BOX_BoxList arg, BOX_BoxList (*acceptList)(BOX_BoxList), BOX_OptLayout (*acceptWsAfterIStar)(BOX_OptLayout), BOX_SOptions (*acceptSOptions)(BOX_SOptions), BOX_OptLayout (*acceptWsAfterSOptions)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterBracketOpen)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterBoxList)(BOX_OptLayout))
{
  if (BOX_isBoxListDefault(arg)) {
    return BOX_makeBoxListDefault(
        acceptList ? acceptList(BOX_getBoxListList(arg)) : BOX_getBoxListList(arg));
  }
  if (BOX_isBoxListIstar(arg)) {
    return BOX_makeBoxListIstar(
        acceptWsAfterIStar ? acceptWsAfterIStar(BOX_getBoxListWsAfterIStar(arg)) : BOX_getBoxListWsAfterIStar(arg),
        acceptSOptions ? acceptSOptions(BOX_getBoxListSOptions(arg)) : BOX_getBoxListSOptions(arg),
        acceptWsAfterSOptions ? acceptWsAfterSOptions(BOX_getBoxListWsAfterSOptions(arg)) : BOX_getBoxListWsAfterSOptions(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(BOX_getBoxListWsAfterBracketOpen(arg)) : BOX_getBoxListWsAfterBracketOpen(arg),
        BOX_visitBoxList(BOX_getBoxListBoxList(arg), acceptList, acceptWsAfterIStar, acceptSOptions, acceptWsAfterSOptions, acceptWsAfterBracketOpen, acceptWsAfterBoxList),
        acceptWsAfterBoxList ? acceptWsAfterBoxList(BOX_getBoxListWsAfterBoxList(arg)) : BOX_getBoxListWsAfterBoxList(arg));
  }
  ATabort("not a BoxList: %t\n", arg);
  return (BOX_BoxList)NULL;
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
/*{{{  BOX_Box BOX_visitBox(BOX_Box arg, BOX_StrCon (*acceptStrCon)(BOX_StrCon), BOX_OptLayout (*acceptWsAfterH)(BOX_OptLayout), BOX_SOptions (*acceptSOptions)(BOX_SOptions), BOX_OptLayout (*acceptWsAfterSOptions)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterBracketOpen)(BOX_OptLayout), BOX_BoxList (*acceptBoxList)(BOX_BoxList), BOX_OptLayout (*acceptWsAfterBoxList)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterV)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterHV)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterHOV)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterI)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterBox)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterWD)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterLST)(BOX_OptLayout)) */

BOX_Box BOX_visitBox(BOX_Box arg, BOX_StrCon (*acceptStrCon)(BOX_StrCon), BOX_OptLayout (*acceptWsAfterH)(BOX_OptLayout), BOX_SOptions (*acceptSOptions)(BOX_SOptions), BOX_OptLayout (*acceptWsAfterSOptions)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterBracketOpen)(BOX_OptLayout), BOX_BoxList (*acceptBoxList)(BOX_BoxList), BOX_OptLayout (*acceptWsAfterBoxList)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterV)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterHV)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterHOV)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterI)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterBox)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterWD)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterLST)(BOX_OptLayout))
{
  if (BOX_isBoxString(arg)) {
    return BOX_makeBoxString(
        acceptStrCon ? acceptStrCon(BOX_getBoxStrCon(arg)) : BOX_getBoxStrCon(arg));
  }
  if (BOX_isBoxH(arg)) {
    return BOX_makeBoxH(
        acceptWsAfterH ? acceptWsAfterH(BOX_getBoxWsAfterH(arg)) : BOX_getBoxWsAfterH(arg),
        acceptSOptions ? acceptSOptions(BOX_getBoxSOptions(arg)) : BOX_getBoxSOptions(arg),
        acceptWsAfterSOptions ? acceptWsAfterSOptions(BOX_getBoxWsAfterSOptions(arg)) : BOX_getBoxWsAfterSOptions(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(BOX_getBoxWsAfterBracketOpen(arg)) : BOX_getBoxWsAfterBracketOpen(arg),
        acceptBoxList ? acceptBoxList(BOX_getBoxBoxList(arg)) : BOX_getBoxBoxList(arg),
        acceptWsAfterBoxList ? acceptWsAfterBoxList(BOX_getBoxWsAfterBoxList(arg)) : BOX_getBoxWsAfterBoxList(arg));
  }
  if (BOX_isBoxV(arg)) {
    return BOX_makeBoxV(
        acceptWsAfterV ? acceptWsAfterV(BOX_getBoxWsAfterV(arg)) : BOX_getBoxWsAfterV(arg),
        acceptSOptions ? acceptSOptions(BOX_getBoxSOptions(arg)) : BOX_getBoxSOptions(arg),
        acceptWsAfterSOptions ? acceptWsAfterSOptions(BOX_getBoxWsAfterSOptions(arg)) : BOX_getBoxWsAfterSOptions(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(BOX_getBoxWsAfterBracketOpen(arg)) : BOX_getBoxWsAfterBracketOpen(arg),
        acceptBoxList ? acceptBoxList(BOX_getBoxBoxList(arg)) : BOX_getBoxBoxList(arg),
        acceptWsAfterBoxList ? acceptWsAfterBoxList(BOX_getBoxWsAfterBoxList(arg)) : BOX_getBoxWsAfterBoxList(arg));
  }
  if (BOX_isBoxHV(arg)) {
    return BOX_makeBoxHV(
        acceptWsAfterHV ? acceptWsAfterHV(BOX_getBoxWsAfterHV(arg)) : BOX_getBoxWsAfterHV(arg),
        acceptSOptions ? acceptSOptions(BOX_getBoxSOptions(arg)) : BOX_getBoxSOptions(arg),
        acceptWsAfterSOptions ? acceptWsAfterSOptions(BOX_getBoxWsAfterSOptions(arg)) : BOX_getBoxWsAfterSOptions(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(BOX_getBoxWsAfterBracketOpen(arg)) : BOX_getBoxWsAfterBracketOpen(arg),
        acceptBoxList ? acceptBoxList(BOX_getBoxBoxList(arg)) : BOX_getBoxBoxList(arg),
        acceptWsAfterBoxList ? acceptWsAfterBoxList(BOX_getBoxWsAfterBoxList(arg)) : BOX_getBoxWsAfterBoxList(arg));
  }
  if (BOX_isBoxHOV(arg)) {
    return BOX_makeBoxHOV(
        acceptWsAfterHOV ? acceptWsAfterHOV(BOX_getBoxWsAfterHOV(arg)) : BOX_getBoxWsAfterHOV(arg),
        acceptSOptions ? acceptSOptions(BOX_getBoxSOptions(arg)) : BOX_getBoxSOptions(arg),
        acceptWsAfterSOptions ? acceptWsAfterSOptions(BOX_getBoxWsAfterSOptions(arg)) : BOX_getBoxWsAfterSOptions(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(BOX_getBoxWsAfterBracketOpen(arg)) : BOX_getBoxWsAfterBracketOpen(arg),
        acceptBoxList ? acceptBoxList(BOX_getBoxBoxList(arg)) : BOX_getBoxBoxList(arg),
        acceptWsAfterBoxList ? acceptWsAfterBoxList(BOX_getBoxWsAfterBoxList(arg)) : BOX_getBoxWsAfterBoxList(arg));
  }
  if (BOX_isBoxI(arg)) {
    return BOX_makeBoxI(
        acceptWsAfterI ? acceptWsAfterI(BOX_getBoxWsAfterI(arg)) : BOX_getBoxWsAfterI(arg),
        acceptSOptions ? acceptSOptions(BOX_getBoxSOptions(arg)) : BOX_getBoxSOptions(arg),
        acceptWsAfterSOptions ? acceptWsAfterSOptions(BOX_getBoxWsAfterSOptions(arg)) : BOX_getBoxWsAfterSOptions(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(BOX_getBoxWsAfterBracketOpen(arg)) : BOX_getBoxWsAfterBracketOpen(arg),
        BOX_visitBox(BOX_getBoxBox(arg), acceptStrCon, acceptWsAfterH, acceptSOptions, acceptWsAfterSOptions, acceptWsAfterBracketOpen, acceptBoxList, acceptWsAfterBoxList, acceptWsAfterV, acceptWsAfterHV, acceptWsAfterHOV, acceptWsAfterI, acceptWsAfterBox, acceptWsAfterWD, acceptWsAfterLST),
        acceptWsAfterBox ? acceptWsAfterBox(BOX_getBoxWsAfterBox(arg)) : BOX_getBoxWsAfterBox(arg));
  }
  if (BOX_isBoxWD(arg)) {
    return BOX_makeBoxWD(
        acceptWsAfterWD ? acceptWsAfterWD(BOX_getBoxWsAfterWD(arg)) : BOX_getBoxWsAfterWD(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(BOX_getBoxWsAfterBracketOpen(arg)) : BOX_getBoxWsAfterBracketOpen(arg),
        BOX_visitBox(BOX_getBoxBox(arg), acceptStrCon, acceptWsAfterH, acceptSOptions, acceptWsAfterSOptions, acceptWsAfterBracketOpen, acceptBoxList, acceptWsAfterBoxList, acceptWsAfterV, acceptWsAfterHV, acceptWsAfterHOV, acceptWsAfterI, acceptWsAfterBox, acceptWsAfterWD, acceptWsAfterLST),
        acceptWsAfterBox ? acceptWsAfterBox(BOX_getBoxWsAfterBox(arg)) : BOX_getBoxWsAfterBox(arg));
  }
  if (BOX_isBoxLST(arg)) {
    return BOX_makeBoxLST(
        acceptWsAfterLST ? acceptWsAfterLST(BOX_getBoxWsAfterLST(arg)) : BOX_getBoxWsAfterLST(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(BOX_getBoxWsAfterBracketOpen(arg)) : BOX_getBoxWsAfterBracketOpen(arg),
        acceptBoxList ? acceptBoxList(BOX_getBoxBoxList(arg)) : BOX_getBoxBoxList(arg),
        acceptWsAfterBoxList ? acceptWsAfterBoxList(BOX_getBoxWsAfterBoxList(arg)) : BOX_getBoxWsAfterBoxList(arg));
  }
  ATabort("not a Box: %t\n", arg);
  return (BOX_Box)NULL;
}

/*}}}  */
/*{{{  BOX_Start BOX_visitStart(BOX_Start arg, BOX_OptLayout (*acceptWsBefore)(BOX_OptLayout), BOX_SOptions (*acceptTopSOptions)(BOX_SOptions), BOX_OptLayout (*acceptWsAfter)(BOX_OptLayout), int (*acceptAmbCnt)(int), BOX_SOption (*acceptTopSOption)(BOX_SOption), BOX_SpaceSymbol (*acceptTopSpaceSymbol)(BOX_SpaceSymbol), BOX_BoxList (*acceptTopBoxList)(BOX_BoxList), BOX_Box (*acceptTopBox)(BOX_Box), BOX_Escaped (*acceptTopEscaped)(BOX_Escaped), BOX_Normal (*acceptTopNormal)(BOX_Normal), BOX_StrCon (*acceptTopStrCon)(BOX_StrCon), BOX_NatCon (*acceptTopNatCon)(BOX_NatCon)) */

BOX_Start BOX_visitStart(BOX_Start arg, BOX_OptLayout (*acceptWsBefore)(BOX_OptLayout), BOX_SOptions (*acceptTopSOptions)(BOX_SOptions), BOX_OptLayout (*acceptWsAfter)(BOX_OptLayout), int (*acceptAmbCnt)(int), BOX_SOption (*acceptTopSOption)(BOX_SOption), BOX_SpaceSymbol (*acceptTopSpaceSymbol)(BOX_SpaceSymbol), BOX_BoxList (*acceptTopBoxList)(BOX_BoxList), BOX_Box (*acceptTopBox)(BOX_Box), BOX_Escaped (*acceptTopEscaped)(BOX_Escaped), BOX_Normal (*acceptTopNormal)(BOX_Normal), BOX_StrCon (*acceptTopStrCon)(BOX_StrCon), BOX_NatCon (*acceptTopNatCon)(BOX_NatCon))
{
  if (BOX_isStartSOptions(arg)) {
    return BOX_makeStartSOptions(
        acceptWsBefore ? acceptWsBefore(BOX_getStartWsBefore(arg)) : BOX_getStartWsBefore(arg),
        acceptTopSOptions ? acceptTopSOptions(BOX_getStartTopSOptions(arg)) : BOX_getStartTopSOptions(arg),
        acceptWsAfter ? acceptWsAfter(BOX_getStartWsAfter(arg)) : BOX_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(BOX_getStartAmbCnt(arg)) : BOX_getStartAmbCnt(arg));
  }
  if (BOX_isStartSOption(arg)) {
    return BOX_makeStartSOption(
        acceptWsBefore ? acceptWsBefore(BOX_getStartWsBefore(arg)) : BOX_getStartWsBefore(arg),
        acceptTopSOption ? acceptTopSOption(BOX_getStartTopSOption(arg)) : BOX_getStartTopSOption(arg),
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
  if (BOX_isStartBoxList(arg)) {
    return BOX_makeStartBoxList(
        acceptWsBefore ? acceptWsBefore(BOX_getStartWsBefore(arg)) : BOX_getStartWsBefore(arg),
        acceptTopBoxList ? acceptTopBoxList(BOX_getStartTopBoxList(arg)) : BOX_getStartTopBoxList(arg),
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

/*}}}  */
