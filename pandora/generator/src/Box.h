#ifndef _BOX_H
#define _BOX_H

/*{{{  includes */

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "Box_dict.h"

/*}}}  */

/*{{{  typedefs */

typedef struct _BOX_NatCon *BOX_NatCon;
typedef struct _BOX_Normal *BOX_Normal;
typedef struct _BOX_Escaped *BOX_Escaped;
typedef struct _BOX_StrCon *BOX_StrCon;
typedef struct _BOX_SpaceSymbol *BOX_SpaceSymbol;
typedef struct _BOX_SOption *BOX_SOption;
typedef struct _BOX_SOptions *BOX_SOptions;
typedef struct _BOX_SOptionList *BOX_SOptionList;
typedef struct _BOX_BoxList *BOX_BoxList;
typedef struct _BOX_BoxList *BOX_BoxList;
typedef struct _BOX_Box *BOX_Box;
typedef struct _BOX_Start *BOX_Start;
typedef struct _BOX_OptLayout *BOX_OptLayout;

/*}}}  */

/*{{{  definition of bottom types */


/*}}}  */

/*{{{  protect macros */

#define BOX_protectNatCon(arg) (ATprotect((ATerm*)((void*) arg)))
#define BOX_protectNormal(arg) (ATprotect((ATerm*)((void*) arg)))
#define BOX_protectEscaped(arg) (ATprotect((ATerm*)((void*) arg)))
#define BOX_protectStrCon(arg) (ATprotect((ATerm*)((void*) arg)))
#define BOX_protectSpaceSymbol(arg) (ATprotect((ATerm*)((void*) arg)))
#define BOX_protectSOption(arg) (ATprotect((ATerm*)((void*) arg)))
#define BOX_protectSOptions(arg) (ATprotect((ATerm*)((void*) arg)))
#define BOX_protectSOptionList(arg) (ATprotect((ATerm*)((void*) arg)))
#define BOX_protectBoxList(arg) (ATprotect((ATerm*)((void*) arg)))
#define BOX_protectBoxList(arg) (ATprotect((ATerm*)((void*) arg)))
#define BOX_protectBox(arg) (ATprotect((ATerm*)((void*) arg)))
#define BOX_protectStart(arg) (ATprotect((ATerm*)((void*) arg)))
#define BOX_protectOptLayout(arg) (ATprotect((ATerm*)((void*) arg)))

/*}}}  */
void BOX_initBoxApi(void);

/*{{{  term conversion functions */

BOX_NatCon BOX_NatConFromTerm(ATerm t);
ATerm BOX_NatConToTerm(BOX_NatCon arg);
BOX_Normal BOX_NormalFromTerm(ATerm t);
ATerm BOX_NormalToTerm(BOX_Normal arg);
BOX_Escaped BOX_EscapedFromTerm(ATerm t);
ATerm BOX_EscapedToTerm(BOX_Escaped arg);
BOX_StrCon BOX_StrConFromTerm(ATerm t);
ATerm BOX_StrConToTerm(BOX_StrCon arg);
BOX_SpaceSymbol BOX_SpaceSymbolFromTerm(ATerm t);
ATerm BOX_SpaceSymbolToTerm(BOX_SpaceSymbol arg);
BOX_SOption BOX_SOptionFromTerm(ATerm t);
ATerm BOX_SOptionToTerm(BOX_SOption arg);
BOX_SOptions BOX_SOptionsFromTerm(ATerm t);
ATerm BOX_SOptionsToTerm(BOX_SOptions arg);
BOX_SOptionList BOX_SOptionListFromTerm(ATerm t);
ATerm BOX_SOptionListToTerm(BOX_SOptionList arg);
BOX_BoxList BOX_BoxListFromTerm(ATerm t);
ATerm BOX_BoxListToTerm(BOX_BoxList arg);
BOX_BoxList BOX_BoxListFromTerm(ATerm t);
ATerm BOX_BoxListToTerm(BOX_BoxList arg);
BOX_Box BOX_BoxFromTerm(ATerm t);
ATerm BOX_BoxToTerm(BOX_Box arg);
BOX_Start BOX_StartFromTerm(ATerm t);
ATerm BOX_StartToTerm(BOX_Start arg);
BOX_OptLayout BOX_OptLayoutFromTerm(ATerm t);
ATerm BOX_OptLayoutToTerm(BOX_OptLayout arg);

/*}}}  */
/*{{{  list functions */

int BOX_getSOptionListLength (BOX_SOptionList arg);
BOX_SOptionList reverseSOptionList(BOX_SOptionList arg);
BOX_SOptionList BOX_appendSOptionList(BOX_SOptionList arg0, BOX_OptLayout wsAfterHead, BOX_SOption arg1);
BOX_SOptionList BOX_concatSOptionList(BOX_SOptionList arg0, BOX_OptLayout wsAfterHead, BOX_SOptionList arg1);
BOX_SOptionList BOX_sliceSOptionList(BOX_SOptionList arg, int start, int end);
BOX_SOption BOX_getSOptionListSOptionAt(BOX_SOptionList arg, int index);
BOX_SOptionList BOX_replaceSOptionListSOptionAt(BOX_SOptionList arg, BOX_SOption elem, int index);
BOX_SOptionList BOX_makeSOptionList2(BOX_OptLayout wsAfterHead, BOX_SOption elem1, BOX_SOption elem2);
BOX_SOptionList BOX_makeSOptionList3(BOX_OptLayout wsAfterHead, BOX_SOption elem1, BOX_SOption elem2, BOX_SOption elem3);
BOX_SOptionList BOX_makeSOptionList4(BOX_OptLayout wsAfterHead, BOX_SOption elem1, BOX_SOption elem2, BOX_SOption elem3, BOX_SOption elem4);
BOX_SOptionList BOX_makeSOptionList5(BOX_OptLayout wsAfterHead, BOX_SOption elem1, BOX_SOption elem2, BOX_SOption elem3, BOX_SOption elem4, BOX_SOption elem5);
BOX_SOptionList BOX_makeSOptionList6(BOX_OptLayout wsAfterHead, BOX_SOption elem1, BOX_SOption elem2, BOX_SOption elem3, BOX_SOption elem4, BOX_SOption elem5, BOX_SOption elem6);
int BOX_getBoxListLength (BOX_BoxList arg);
BOX_BoxList reverseBoxList(BOX_BoxList arg);
BOX_BoxList BOX_appendBoxList(BOX_BoxList arg0, BOX_OptLayout wsAfterHead, BOX_Box arg1);
BOX_BoxList BOX_concatBoxList(BOX_BoxList arg0, BOX_OptLayout wsAfterHead, BOX_BoxList arg1);
BOX_BoxList BOX_sliceBoxList(BOX_BoxList arg, int start, int end);
BOX_Box BOX_getBoxListBoxAt(BOX_BoxList arg, int index);
BOX_BoxList BOX_replaceBoxListBoxAt(BOX_BoxList arg, BOX_Box elem, int index);
BOX_BoxList BOX_makeBoxList2(BOX_OptLayout wsAfterHead, BOX_Box elem1, BOX_Box elem2);
BOX_BoxList BOX_makeBoxList3(BOX_OptLayout wsAfterHead, BOX_Box elem1, BOX_Box elem2, BOX_Box elem3);
BOX_BoxList BOX_makeBoxList4(BOX_OptLayout wsAfterHead, BOX_Box elem1, BOX_Box elem2, BOX_Box elem3, BOX_Box elem4);
BOX_BoxList BOX_makeBoxList5(BOX_OptLayout wsAfterHead, BOX_Box elem1, BOX_Box elem2, BOX_Box elem3, BOX_Box elem4, BOX_Box elem5);
BOX_BoxList BOX_makeBoxList6(BOX_OptLayout wsAfterHead, BOX_Box elem1, BOX_Box elem2, BOX_Box elem3, BOX_Box elem4, BOX_Box elem5, BOX_Box elem6);

/*}}}  */
/*{{{  constructors */

BOX_NatCon BOX_makeNatConDefault(char* string);
BOX_Normal BOX_makeNormalDefault(char* string);
BOX_Escaped BOX_makeEscapedSpecialCharacter(char* string);
BOX_Escaped BOX_makeEscapedOctal(char* string);
BOX_StrCon BOX_makeStrConDefault(char* string);
BOX_SpaceSymbol BOX_makeSpaceSymbolHs();
BOX_SpaceSymbol BOX_makeSpaceSymbolVs();
BOX_SpaceSymbol BOX_makeSpaceSymbolIs();
BOX_SOption BOX_makeSOptionDefault(BOX_SpaceSymbol SpaceSymbol, BOX_OptLayout wsAfterSpaceSymbol, BOX_OptLayout wsAfterEquals, BOX_NatCon NatCon);
BOX_SOptions BOX_makeSOptionsDefault(BOX_SOptionList list);
BOX_SOptionList BOX_makeSOptionListEmpty();
BOX_SOptionList BOX_makeSOptionListSingle(BOX_SOption head);
BOX_SOptionList BOX_makeSOptionListMany(BOX_SOption head, BOX_OptLayout wsAfterHead, BOX_SOptionList tail);
BOX_BoxList BOX_makeBoxListDefault(BOX_BoxList list);
BOX_BoxList BOX_makeBoxListIstar(BOX_OptLayout wsAfterIStar, BOX_SOptions SOptions, BOX_OptLayout wsAfterSOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList BoxList, BOX_OptLayout wsAfterBoxList);
BOX_BoxList BOX_makeBoxListEmpty();
BOX_BoxList BOX_makeBoxListSingle(BOX_Box head);
BOX_BoxList BOX_makeBoxListMany(BOX_Box head, BOX_OptLayout wsAfterHead, BOX_BoxList tail);
BOX_Box BOX_makeBoxString(BOX_StrCon StrCon);
BOX_Box BOX_makeBoxH(BOX_OptLayout wsAfterH, BOX_SOptions SOptions, BOX_OptLayout wsAfterSOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList BoxList, BOX_OptLayout wsAfterBoxList);
BOX_Box BOX_makeBoxV(BOX_OptLayout wsAfterV, BOX_SOptions SOptions, BOX_OptLayout wsAfterSOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList BoxList, BOX_OptLayout wsAfterBoxList);
BOX_Box BOX_makeBoxHV(BOX_OptLayout wsAfterHV, BOX_SOptions SOptions, BOX_OptLayout wsAfterSOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList BoxList, BOX_OptLayout wsAfterBoxList);
BOX_Box BOX_makeBoxHOV(BOX_OptLayout wsAfterHOV, BOX_SOptions SOptions, BOX_OptLayout wsAfterSOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList BoxList, BOX_OptLayout wsAfterBoxList);
BOX_Box BOX_makeBoxI(BOX_OptLayout wsAfterI, BOX_SOptions SOptions, BOX_OptLayout wsAfterSOptions, BOX_OptLayout wsAfterBracketOpen, BOX_Box Box, BOX_OptLayout wsAfterBox);
BOX_Box BOX_makeBoxWD(BOX_OptLayout wsAfterWD, BOX_OptLayout wsAfterBracketOpen, BOX_Box Box, BOX_OptLayout wsAfterBox);
BOX_Box BOX_makeBoxLST(BOX_OptLayout wsAfterLST, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList BoxList, BOX_OptLayout wsAfterBoxList);
BOX_Start BOX_makeStartSOptions(BOX_OptLayout wsBefore, BOX_SOptions topSOptions, BOX_OptLayout wsAfter, int ambCnt);
BOX_Start BOX_makeStartSOption(BOX_OptLayout wsBefore, BOX_SOption topSOption, BOX_OptLayout wsAfter, int ambCnt);
BOX_Start BOX_makeStartSpaceSymbol(BOX_OptLayout wsBefore, BOX_SpaceSymbol topSpaceSymbol, BOX_OptLayout wsAfter, int ambCnt);
BOX_Start BOX_makeStartBoxList(BOX_OptLayout wsBefore, BOX_BoxList topBoxList, BOX_OptLayout wsAfter, int ambCnt);
BOX_Start BOX_makeStartBox(BOX_OptLayout wsBefore, BOX_Box topBox, BOX_OptLayout wsAfter, int ambCnt);
BOX_Start BOX_makeStartEscaped(BOX_OptLayout wsBefore, BOX_Escaped topEscaped, BOX_OptLayout wsAfter, int ambCnt);
BOX_Start BOX_makeStartNormal(BOX_OptLayout wsBefore, BOX_Normal topNormal, BOX_OptLayout wsAfter, int ambCnt);
BOX_Start BOX_makeStartStrCon(BOX_OptLayout wsBefore, BOX_StrCon topStrCon, BOX_OptLayout wsAfter, int ambCnt);
BOX_Start BOX_makeStartNatCon(BOX_OptLayout wsBefore, BOX_NatCon topNatCon, BOX_OptLayout wsAfter, int ambCnt);
BOX_OptLayout BOX_makeOptLayoutAbsent();
BOX_OptLayout BOX_makeOptLayoutPresent(char* string);

/*}}}  */
/*{{{  equality functions */

ATbool BOX_isEqualNatCon(BOX_NatCon arg0, BOX_NatCon arg1);
ATbool BOX_isEqualNormal(BOX_Normal arg0, BOX_Normal arg1);
ATbool BOX_isEqualEscaped(BOX_Escaped arg0, BOX_Escaped arg1);
ATbool BOX_isEqualStrCon(BOX_StrCon arg0, BOX_StrCon arg1);
ATbool BOX_isEqualSpaceSymbol(BOX_SpaceSymbol arg0, BOX_SpaceSymbol arg1);
ATbool BOX_isEqualSOption(BOX_SOption arg0, BOX_SOption arg1);
ATbool BOX_isEqualSOptions(BOX_SOptions arg0, BOX_SOptions arg1);
ATbool BOX_isEqualSOptionList(BOX_SOptionList arg0, BOX_SOptionList arg1);
ATbool BOX_isEqualBoxList(BOX_BoxList arg0, BOX_BoxList arg1);
ATbool BOX_isEqualBoxList(BOX_BoxList arg0, BOX_BoxList arg1);
ATbool BOX_isEqualBox(BOX_Box arg0, BOX_Box arg1);
ATbool BOX_isEqualStart(BOX_Start arg0, BOX_Start arg1);
ATbool BOX_isEqualOptLayout(BOX_OptLayout arg0, BOX_OptLayout arg1);

/*}}}  */
/*{{{  BOX_NatCon accessors */

ATbool BOX_isValidNatCon(BOX_NatCon arg);
inline ATbool BOX_isNatConDefault(BOX_NatCon arg);
ATbool BOX_hasNatConString(BOX_NatCon arg);
char* BOX_getNatConString(BOX_NatCon arg);
BOX_NatCon BOX_setNatConString(BOX_NatCon arg, char* string);

/*}}}  */
/*{{{  BOX_Normal accessors */

ATbool BOX_isValidNormal(BOX_Normal arg);
inline ATbool BOX_isNormalDefault(BOX_Normal arg);
ATbool BOX_hasNormalString(BOX_Normal arg);
char* BOX_getNormalString(BOX_Normal arg);
BOX_Normal BOX_setNormalString(BOX_Normal arg, char* string);

/*}}}  */
/*{{{  BOX_Escaped accessors */

ATbool BOX_isValidEscaped(BOX_Escaped arg);
inline ATbool BOX_isEscapedSpecialCharacter(BOX_Escaped arg);
inline ATbool BOX_isEscapedOctal(BOX_Escaped arg);
ATbool BOX_hasEscapedString(BOX_Escaped arg);
char* BOX_getEscapedString(BOX_Escaped arg);
BOX_Escaped BOX_setEscapedString(BOX_Escaped arg, char* string);

/*}}}  */
/*{{{  BOX_StrCon accessors */

ATbool BOX_isValidStrCon(BOX_StrCon arg);
inline ATbool BOX_isStrConDefault(BOX_StrCon arg);
ATbool BOX_hasStrConString(BOX_StrCon arg);
char* BOX_getStrConString(BOX_StrCon arg);
BOX_StrCon BOX_setStrConString(BOX_StrCon arg, char* string);

/*}}}  */
/*{{{  BOX_SpaceSymbol accessors */

ATbool BOX_isValidSpaceSymbol(BOX_SpaceSymbol arg);
inline ATbool BOX_isSpaceSymbolHs(BOX_SpaceSymbol arg);
inline ATbool BOX_isSpaceSymbolVs(BOX_SpaceSymbol arg);
inline ATbool BOX_isSpaceSymbolIs(BOX_SpaceSymbol arg);

/*}}}  */
/*{{{  BOX_SOption accessors */

ATbool BOX_isValidSOption(BOX_SOption arg);
inline ATbool BOX_isSOptionDefault(BOX_SOption arg);
ATbool BOX_hasSOptionSpaceSymbol(BOX_SOption arg);
BOX_SpaceSymbol BOX_getSOptionSpaceSymbol(BOX_SOption arg);
BOX_SOption BOX_setSOptionSpaceSymbol(BOX_SOption arg, BOX_SpaceSymbol SpaceSymbol);
ATbool BOX_hasSOptionWsAfterSpaceSymbol(BOX_SOption arg);
BOX_OptLayout BOX_getSOptionWsAfterSpaceSymbol(BOX_SOption arg);
BOX_SOption BOX_setSOptionWsAfterSpaceSymbol(BOX_SOption arg, BOX_OptLayout wsAfterSpaceSymbol);
ATbool BOX_hasSOptionWsAfterEquals(BOX_SOption arg);
BOX_OptLayout BOX_getSOptionWsAfterEquals(BOX_SOption arg);
BOX_SOption BOX_setSOptionWsAfterEquals(BOX_SOption arg, BOX_OptLayout wsAfterEquals);
ATbool BOX_hasSOptionNatCon(BOX_SOption arg);
BOX_NatCon BOX_getSOptionNatCon(BOX_SOption arg);
BOX_SOption BOX_setSOptionNatCon(BOX_SOption arg, BOX_NatCon NatCon);

/*}}}  */
/*{{{  BOX_SOptions accessors */

ATbool BOX_isValidSOptions(BOX_SOptions arg);
inline ATbool BOX_isSOptionsDefault(BOX_SOptions arg);
ATbool BOX_hasSOptionsList(BOX_SOptions arg);
BOX_SOptionList BOX_getSOptionsList(BOX_SOptions arg);
BOX_SOptions BOX_setSOptionsList(BOX_SOptions arg, BOX_SOptionList list);

/*}}}  */
/*{{{  BOX_SOptionList accessors */

ATbool BOX_isValidSOptionList(BOX_SOptionList arg);
inline ATbool BOX_isSOptionListEmpty(BOX_SOptionList arg);
inline ATbool BOX_isSOptionListSingle(BOX_SOptionList arg);
inline ATbool BOX_isSOptionListMany(BOX_SOptionList arg);
ATbool BOX_hasSOptionListHead(BOX_SOptionList arg);
BOX_SOption BOX_getSOptionListHead(BOX_SOptionList arg);
BOX_SOptionList BOX_setSOptionListHead(BOX_SOptionList arg, BOX_SOption head);
ATbool BOX_hasSOptionListWsAfterHead(BOX_SOptionList arg);
BOX_OptLayout BOX_getSOptionListWsAfterHead(BOX_SOptionList arg);
BOX_SOptionList BOX_setSOptionListWsAfterHead(BOX_SOptionList arg, BOX_OptLayout wsAfterHead);
ATbool BOX_hasSOptionListTail(BOX_SOptionList arg);
BOX_SOptionList BOX_getSOptionListTail(BOX_SOptionList arg);
BOX_SOptionList BOX_setSOptionListTail(BOX_SOptionList arg, BOX_SOptionList tail);

/*}}}  */
/*{{{  BOX_BoxList accessors */

ATbool BOX_isValidBoxList(BOX_BoxList arg);
inline ATbool BOX_isBoxListDefault(BOX_BoxList arg);
inline ATbool BOX_isBoxListIstar(BOX_BoxList arg);
ATbool BOX_hasBoxListList(BOX_BoxList arg);
BOX_BoxList BOX_getBoxListList(BOX_BoxList arg);
BOX_BoxList BOX_setBoxListList(BOX_BoxList arg, BOX_BoxList list);
ATbool BOX_hasBoxListWsAfterIStar(BOX_BoxList arg);
BOX_OptLayout BOX_getBoxListWsAfterIStar(BOX_BoxList arg);
BOX_BoxList BOX_setBoxListWsAfterIStar(BOX_BoxList arg, BOX_OptLayout wsAfterIStar);
ATbool BOX_hasBoxListSOptions(BOX_BoxList arg);
BOX_SOptions BOX_getBoxListSOptions(BOX_BoxList arg);
BOX_BoxList BOX_setBoxListSOptions(BOX_BoxList arg, BOX_SOptions SOptions);
ATbool BOX_hasBoxListWsAfterSOptions(BOX_BoxList arg);
BOX_OptLayout BOX_getBoxListWsAfterSOptions(BOX_BoxList arg);
BOX_BoxList BOX_setBoxListWsAfterSOptions(BOX_BoxList arg, BOX_OptLayout wsAfterSOptions);
ATbool BOX_hasBoxListWsAfterBracketOpen(BOX_BoxList arg);
BOX_OptLayout BOX_getBoxListWsAfterBracketOpen(BOX_BoxList arg);
BOX_BoxList BOX_setBoxListWsAfterBracketOpen(BOX_BoxList arg, BOX_OptLayout wsAfterBracketOpen);
ATbool BOX_hasBoxListBoxList(BOX_BoxList arg);
BOX_BoxList BOX_getBoxListBoxList(BOX_BoxList arg);
BOX_BoxList BOX_setBoxListBoxList(BOX_BoxList arg, BOX_BoxList BoxList);
ATbool BOX_hasBoxListWsAfterBoxList(BOX_BoxList arg);
BOX_OptLayout BOX_getBoxListWsAfterBoxList(BOX_BoxList arg);
BOX_BoxList BOX_setBoxListWsAfterBoxList(BOX_BoxList arg, BOX_OptLayout wsAfterBoxList);

/*}}}  */
/*{{{  BOX_BoxList accessors */

ATbool BOX_isValidBoxList(BOX_BoxList arg);
inline ATbool BOX_isBoxListEmpty(BOX_BoxList arg);
inline ATbool BOX_isBoxListSingle(BOX_BoxList arg);
inline ATbool BOX_isBoxListMany(BOX_BoxList arg);
ATbool BOX_hasBoxListHead(BOX_BoxList arg);
BOX_Box BOX_getBoxListHead(BOX_BoxList arg);
BOX_BoxList BOX_setBoxListHead(BOX_BoxList arg, BOX_Box head);
ATbool BOX_hasBoxListWsAfterHead(BOX_BoxList arg);
BOX_OptLayout BOX_getBoxListWsAfterHead(BOX_BoxList arg);
BOX_BoxList BOX_setBoxListWsAfterHead(BOX_BoxList arg, BOX_OptLayout wsAfterHead);
ATbool BOX_hasBoxListTail(BOX_BoxList arg);
BOX_BoxList BOX_getBoxListTail(BOX_BoxList arg);
BOX_BoxList BOX_setBoxListTail(BOX_BoxList arg, BOX_BoxList tail);

/*}}}  */
/*{{{  BOX_Box accessors */

ATbool BOX_isValidBox(BOX_Box arg);
inline ATbool BOX_isBoxString(BOX_Box arg);
inline ATbool BOX_isBoxH(BOX_Box arg);
inline ATbool BOX_isBoxV(BOX_Box arg);
inline ATbool BOX_isBoxHV(BOX_Box arg);
inline ATbool BOX_isBoxHOV(BOX_Box arg);
inline ATbool BOX_isBoxI(BOX_Box arg);
inline ATbool BOX_isBoxWD(BOX_Box arg);
inline ATbool BOX_isBoxLST(BOX_Box arg);
ATbool BOX_hasBoxStrCon(BOX_Box arg);
BOX_StrCon BOX_getBoxStrCon(BOX_Box arg);
BOX_Box BOX_setBoxStrCon(BOX_Box arg, BOX_StrCon StrCon);
ATbool BOX_hasBoxWsAfterH(BOX_Box arg);
BOX_OptLayout BOX_getBoxWsAfterH(BOX_Box arg);
BOX_Box BOX_setBoxWsAfterH(BOX_Box arg, BOX_OptLayout wsAfterH);
ATbool BOX_hasBoxSOptions(BOX_Box arg);
BOX_SOptions BOX_getBoxSOptions(BOX_Box arg);
BOX_Box BOX_setBoxSOptions(BOX_Box arg, BOX_SOptions SOptions);
ATbool BOX_hasBoxWsAfterSOptions(BOX_Box arg);
BOX_OptLayout BOX_getBoxWsAfterSOptions(BOX_Box arg);
BOX_Box BOX_setBoxWsAfterSOptions(BOX_Box arg, BOX_OptLayout wsAfterSOptions);
ATbool BOX_hasBoxWsAfterBracketOpen(BOX_Box arg);
BOX_OptLayout BOX_getBoxWsAfterBracketOpen(BOX_Box arg);
BOX_Box BOX_setBoxWsAfterBracketOpen(BOX_Box arg, BOX_OptLayout wsAfterBracketOpen);
ATbool BOX_hasBoxBoxList(BOX_Box arg);
BOX_BoxList BOX_getBoxBoxList(BOX_Box arg);
BOX_Box BOX_setBoxBoxList(BOX_Box arg, BOX_BoxList BoxList);
ATbool BOX_hasBoxWsAfterBoxList(BOX_Box arg);
BOX_OptLayout BOX_getBoxWsAfterBoxList(BOX_Box arg);
BOX_Box BOX_setBoxWsAfterBoxList(BOX_Box arg, BOX_OptLayout wsAfterBoxList);
ATbool BOX_hasBoxWsAfterV(BOX_Box arg);
BOX_OptLayout BOX_getBoxWsAfterV(BOX_Box arg);
BOX_Box BOX_setBoxWsAfterV(BOX_Box arg, BOX_OptLayout wsAfterV);
ATbool BOX_hasBoxWsAfterHV(BOX_Box arg);
BOX_OptLayout BOX_getBoxWsAfterHV(BOX_Box arg);
BOX_Box BOX_setBoxWsAfterHV(BOX_Box arg, BOX_OptLayout wsAfterHV);
ATbool BOX_hasBoxWsAfterHOV(BOX_Box arg);
BOX_OptLayout BOX_getBoxWsAfterHOV(BOX_Box arg);
BOX_Box BOX_setBoxWsAfterHOV(BOX_Box arg, BOX_OptLayout wsAfterHOV);
ATbool BOX_hasBoxWsAfterI(BOX_Box arg);
BOX_OptLayout BOX_getBoxWsAfterI(BOX_Box arg);
BOX_Box BOX_setBoxWsAfterI(BOX_Box arg, BOX_OptLayout wsAfterI);
ATbool BOX_hasBoxBox(BOX_Box arg);
BOX_Box BOX_getBoxBox(BOX_Box arg);
BOX_Box BOX_setBoxBox(BOX_Box arg, BOX_Box Box);
ATbool BOX_hasBoxWsAfterBox(BOX_Box arg);
BOX_OptLayout BOX_getBoxWsAfterBox(BOX_Box arg);
BOX_Box BOX_setBoxWsAfterBox(BOX_Box arg, BOX_OptLayout wsAfterBox);
ATbool BOX_hasBoxWsAfterWD(BOX_Box arg);
BOX_OptLayout BOX_getBoxWsAfterWD(BOX_Box arg);
BOX_Box BOX_setBoxWsAfterWD(BOX_Box arg, BOX_OptLayout wsAfterWD);
ATbool BOX_hasBoxWsAfterLST(BOX_Box arg);
BOX_OptLayout BOX_getBoxWsAfterLST(BOX_Box arg);
BOX_Box BOX_setBoxWsAfterLST(BOX_Box arg, BOX_OptLayout wsAfterLST);

/*}}}  */
/*{{{  BOX_Start accessors */

ATbool BOX_isValidStart(BOX_Start arg);
inline ATbool BOX_isStartSOptions(BOX_Start arg);
inline ATbool BOX_isStartSOption(BOX_Start arg);
inline ATbool BOX_isStartSpaceSymbol(BOX_Start arg);
inline ATbool BOX_isStartBoxList(BOX_Start arg);
inline ATbool BOX_isStartBox(BOX_Start arg);
inline ATbool BOX_isStartEscaped(BOX_Start arg);
inline ATbool BOX_isStartNormal(BOX_Start arg);
inline ATbool BOX_isStartStrCon(BOX_Start arg);
inline ATbool BOX_isStartNatCon(BOX_Start arg);
ATbool BOX_hasStartWsBefore(BOX_Start arg);
BOX_OptLayout BOX_getStartWsBefore(BOX_Start arg);
BOX_Start BOX_setStartWsBefore(BOX_Start arg, BOX_OptLayout wsBefore);
ATbool BOX_hasStartTopSOptions(BOX_Start arg);
BOX_SOptions BOX_getStartTopSOptions(BOX_Start arg);
BOX_Start BOX_setStartTopSOptions(BOX_Start arg, BOX_SOptions topSOptions);
ATbool BOX_hasStartWsAfter(BOX_Start arg);
BOX_OptLayout BOX_getStartWsAfter(BOX_Start arg);
BOX_Start BOX_setStartWsAfter(BOX_Start arg, BOX_OptLayout wsAfter);
ATbool BOX_hasStartAmbCnt(BOX_Start arg);
int BOX_getStartAmbCnt(BOX_Start arg);
BOX_Start BOX_setStartAmbCnt(BOX_Start arg, int ambCnt);
ATbool BOX_hasStartTopSOption(BOX_Start arg);
BOX_SOption BOX_getStartTopSOption(BOX_Start arg);
BOX_Start BOX_setStartTopSOption(BOX_Start arg, BOX_SOption topSOption);
ATbool BOX_hasStartTopSpaceSymbol(BOX_Start arg);
BOX_SpaceSymbol BOX_getStartTopSpaceSymbol(BOX_Start arg);
BOX_Start BOX_setStartTopSpaceSymbol(BOX_Start arg, BOX_SpaceSymbol topSpaceSymbol);
ATbool BOX_hasStartTopBoxList(BOX_Start arg);
BOX_BoxList BOX_getStartTopBoxList(BOX_Start arg);
BOX_Start BOX_setStartTopBoxList(BOX_Start arg, BOX_BoxList topBoxList);
ATbool BOX_hasStartTopBox(BOX_Start arg);
BOX_Box BOX_getStartTopBox(BOX_Start arg);
BOX_Start BOX_setStartTopBox(BOX_Start arg, BOX_Box topBox);
ATbool BOX_hasStartTopEscaped(BOX_Start arg);
BOX_Escaped BOX_getStartTopEscaped(BOX_Start arg);
BOX_Start BOX_setStartTopEscaped(BOX_Start arg, BOX_Escaped topEscaped);
ATbool BOX_hasStartTopNormal(BOX_Start arg);
BOX_Normal BOX_getStartTopNormal(BOX_Start arg);
BOX_Start BOX_setStartTopNormal(BOX_Start arg, BOX_Normal topNormal);
ATbool BOX_hasStartTopStrCon(BOX_Start arg);
BOX_StrCon BOX_getStartTopStrCon(BOX_Start arg);
BOX_Start BOX_setStartTopStrCon(BOX_Start arg, BOX_StrCon topStrCon);
ATbool BOX_hasStartTopNatCon(BOX_Start arg);
BOX_NatCon BOX_getStartTopNatCon(BOX_Start arg);
BOX_Start BOX_setStartTopNatCon(BOX_Start arg, BOX_NatCon topNatCon);

/*}}}  */
/*{{{  BOX_OptLayout accessors */

ATbool BOX_isValidOptLayout(BOX_OptLayout arg);
inline ATbool BOX_isOptLayoutAbsent(BOX_OptLayout arg);
inline ATbool BOX_isOptLayoutPresent(BOX_OptLayout arg);
ATbool BOX_hasOptLayoutString(BOX_OptLayout arg);
char* BOX_getOptLayoutString(BOX_OptLayout arg);
BOX_OptLayout BOX_setOptLayoutString(BOX_OptLayout arg, char* string);

/*}}}  */
/*{{{  sort visitors */

BOX_NatCon BOX_visitNatCon(BOX_NatCon arg, char* (*acceptString)(char*));
BOX_Normal BOX_visitNormal(BOX_Normal arg, char* (*acceptString)(char*));
BOX_Escaped BOX_visitEscaped(BOX_Escaped arg, char* (*acceptString)(char*));
BOX_StrCon BOX_visitStrCon(BOX_StrCon arg, char* (*acceptString)(char*));
BOX_SpaceSymbol BOX_visitSpaceSymbol(BOX_SpaceSymbol arg);
BOX_SOption BOX_visitSOption(BOX_SOption arg, BOX_SpaceSymbol (*acceptSpaceSymbol)(BOX_SpaceSymbol), BOX_OptLayout (*acceptWsAfterSpaceSymbol)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterEquals)(BOX_OptLayout), BOX_NatCon (*acceptNatCon)(BOX_NatCon));
BOX_SOptions BOX_visitSOptions(BOX_SOptions arg, BOX_SOptionList (*acceptList)(BOX_SOptionList));
BOX_SOptionList BOX_visitSOptionList(BOX_SOptionList arg, BOX_SOption (*acceptHead)(BOX_SOption), BOX_OptLayout (*acceptWsAfterHead)(BOX_OptLayout));
BOX_BoxList BOX_visitBoxList(BOX_BoxList arg, BOX_BoxList (*acceptList)(BOX_BoxList), BOX_OptLayout (*acceptWsAfterIStar)(BOX_OptLayout), BOX_SOptions (*acceptSOptions)(BOX_SOptions), BOX_OptLayout (*acceptWsAfterSOptions)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterBracketOpen)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterBoxList)(BOX_OptLayout));
BOX_BoxList BOX_visitBoxList(BOX_BoxList arg, BOX_Box (*acceptHead)(BOX_Box), BOX_OptLayout (*acceptWsAfterHead)(BOX_OptLayout));
BOX_Box BOX_visitBox(BOX_Box arg, BOX_StrCon (*acceptStrCon)(BOX_StrCon), BOX_OptLayout (*acceptWsAfterH)(BOX_OptLayout), BOX_SOptions (*acceptSOptions)(BOX_SOptions), BOX_OptLayout (*acceptWsAfterSOptions)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterBracketOpen)(BOX_OptLayout), BOX_BoxList (*acceptBoxList)(BOX_BoxList), BOX_OptLayout (*acceptWsAfterBoxList)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterV)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterHV)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterHOV)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterI)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterBox)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterWD)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterLST)(BOX_OptLayout));
BOX_Start BOX_visitStart(BOX_Start arg, BOX_OptLayout (*acceptWsBefore)(BOX_OptLayout), BOX_SOptions (*acceptTopSOptions)(BOX_SOptions), BOX_OptLayout (*acceptWsAfter)(BOX_OptLayout), int (*acceptAmbCnt)(int), BOX_SOption (*acceptTopSOption)(BOX_SOption), BOX_SpaceSymbol (*acceptTopSpaceSymbol)(BOX_SpaceSymbol), BOX_BoxList (*acceptTopBoxList)(BOX_BoxList), BOX_Box (*acceptTopBox)(BOX_Box), BOX_Escaped (*acceptTopEscaped)(BOX_Escaped), BOX_Normal (*acceptTopNormal)(BOX_Normal), BOX_StrCon (*acceptTopStrCon)(BOX_StrCon), BOX_NatCon (*acceptTopNatCon)(BOX_NatCon));
BOX_OptLayout BOX_visitOptLayout(BOX_OptLayout arg, char* (*acceptString)(char*));

/*}}}  */

#endif /* _BOX_H */
