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
typedef struct _BOX_SpaceOption *BOX_SpaceOption;
typedef struct _BOX_Box *BOX_Box;
typedef struct _BOX_SpaceOptionOptions *BOX_SpaceOptionOptions;
typedef struct _BOX_BoxList *BOX_BoxList;
typedef struct _BOX_FontId *BOX_FontId;
typedef struct _BOX_FontValue *BOX_FontValue;
typedef struct _BOX_FontOption *BOX_FontOption;
typedef struct _BOX_FontOperator *BOX_FontOperator;
typedef struct _BOX_FontOptionList *BOX_FontOptionList;
typedef struct _BOX_FontParam *BOX_FontParam;
typedef struct _BOX_OptLayout *BOX_OptLayout;
typedef struct _BOX_Start *BOX_Start;

/*}}}  */

/*{{{  definition of bottom types */


/*}}}  */

void BOX_initBoxApi(void);

/*{{{  protect functions */

void BOX_protectNatCon(BOX_NatCon *arg);
void BOX_protectNormal(BOX_Normal *arg);
void BOX_protectEscaped(BOX_Escaped *arg);
void BOX_protectStrCon(BOX_StrCon *arg);
void BOX_protectSpaceSymbol(BOX_SpaceSymbol *arg);
void BOX_protectSpaceOption(BOX_SpaceOption *arg);
void BOX_protectBox(BOX_Box *arg);
void BOX_protectSpaceOptionOptions(BOX_SpaceOptionOptions *arg);
void BOX_protectBoxList(BOX_BoxList *arg);
void BOX_protectFontId(BOX_FontId *arg);
void BOX_protectFontValue(BOX_FontValue *arg);
void BOX_protectFontOption(BOX_FontOption *arg);
void BOX_protectFontOperator(BOX_FontOperator *arg);
void BOX_protectFontOptionList(BOX_FontOptionList *arg);
void BOX_protectFontParam(BOX_FontParam *arg);
void BOX_protectOptLayout(BOX_OptLayout *arg);
void BOX_protectStart(BOX_Start *arg);

/*}}}  */
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
BOX_SpaceOption BOX_SpaceOptionFromTerm(ATerm t);
ATerm BOX_SpaceOptionToTerm(BOX_SpaceOption arg);
BOX_Box BOX_BoxFromTerm(ATerm t);
ATerm BOX_BoxToTerm(BOX_Box arg);
BOX_SpaceOptionOptions BOX_SpaceOptionOptionsFromTerm(ATerm t);
ATerm BOX_SpaceOptionOptionsToTerm(BOX_SpaceOptionOptions arg);
BOX_BoxList BOX_BoxListFromTerm(ATerm t);
ATerm BOX_BoxListToTerm(BOX_BoxList arg);
BOX_FontId BOX_FontIdFromTerm(ATerm t);
ATerm BOX_FontIdToTerm(BOX_FontId arg);
BOX_FontValue BOX_FontValueFromTerm(ATerm t);
ATerm BOX_FontValueToTerm(BOX_FontValue arg);
BOX_FontOption BOX_FontOptionFromTerm(ATerm t);
ATerm BOX_FontOptionToTerm(BOX_FontOption arg);
BOX_FontOperator BOX_FontOperatorFromTerm(ATerm t);
ATerm BOX_FontOperatorToTerm(BOX_FontOperator arg);
BOX_FontOptionList BOX_FontOptionListFromTerm(ATerm t);
ATerm BOX_FontOptionListToTerm(BOX_FontOptionList arg);
BOX_FontParam BOX_FontParamFromTerm(ATerm t);
ATerm BOX_FontParamToTerm(BOX_FontParam arg);
BOX_OptLayout BOX_OptLayoutFromTerm(ATerm t);
ATerm BOX_OptLayoutToTerm(BOX_OptLayout arg);
BOX_Start BOX_StartFromTerm(ATerm t);
ATerm BOX_StartToTerm(BOX_Start arg);

/*}}}  */
/*{{{  list functions */

int BOX_getSpaceOptionOptionsLength (BOX_SpaceOptionOptions arg);
BOX_SpaceOptionOptions BOX_reverseSpaceOptionOptions(BOX_SpaceOptionOptions arg);
BOX_SpaceOptionOptions BOX_appendSpaceOptionOptions(BOX_SpaceOptionOptions arg0, BOX_OptLayout wsAfterHead, BOX_SpaceOption arg1);
BOX_SpaceOptionOptions BOX_concatSpaceOptionOptions(BOX_SpaceOptionOptions arg0, BOX_OptLayout wsAfterHead, BOX_SpaceOptionOptions arg1);
BOX_SpaceOptionOptions BOX_sliceSpaceOptionOptions(BOX_SpaceOptionOptions arg, int start, int end);
BOX_SpaceOption BOX_getSpaceOptionOptionsSpaceOptionAt(BOX_SpaceOptionOptions arg, int index);
BOX_SpaceOptionOptions BOX_replaceSpaceOptionOptionsSpaceOptionAt(BOX_SpaceOptionOptions arg, BOX_SpaceOption elem, int index);
BOX_SpaceOptionOptions BOX_makeSpaceOptionOptions2(BOX_OptLayout wsAfterHead, BOX_SpaceOption elem1, BOX_SpaceOption elem2);
BOX_SpaceOptionOptions BOX_makeSpaceOptionOptions3(BOX_OptLayout wsAfterHead, BOX_SpaceOption elem1, BOX_SpaceOption elem2, BOX_SpaceOption elem3);
BOX_SpaceOptionOptions BOX_makeSpaceOptionOptions4(BOX_OptLayout wsAfterHead, BOX_SpaceOption elem1, BOX_SpaceOption elem2, BOX_SpaceOption elem3, BOX_SpaceOption elem4);
BOX_SpaceOptionOptions BOX_makeSpaceOptionOptions5(BOX_OptLayout wsAfterHead, BOX_SpaceOption elem1, BOX_SpaceOption elem2, BOX_SpaceOption elem3, BOX_SpaceOption elem4, BOX_SpaceOption elem5);
BOX_SpaceOptionOptions BOX_makeSpaceOptionOptions6(BOX_OptLayout wsAfterHead, BOX_SpaceOption elem1, BOX_SpaceOption elem2, BOX_SpaceOption elem3, BOX_SpaceOption elem4, BOX_SpaceOption elem5, BOX_SpaceOption elem6);
int BOX_getBoxListLength (BOX_BoxList arg);
BOX_BoxList BOX_reverseBoxList(BOX_BoxList arg);
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
int BOX_getFontOptionListLength (BOX_FontOptionList arg);
BOX_FontOptionList BOX_reverseFontOptionList(BOX_FontOptionList arg);
BOX_FontOptionList BOX_appendFontOptionList(BOX_FontOptionList arg0, BOX_OptLayout wsAfterHead, BOX_FontOption arg1);
BOX_FontOptionList BOX_concatFontOptionList(BOX_FontOptionList arg0, BOX_OptLayout wsAfterHead, BOX_FontOptionList arg1);
BOX_FontOptionList BOX_sliceFontOptionList(BOX_FontOptionList arg, int start, int end);
BOX_FontOption BOX_getFontOptionListFontOptionAt(BOX_FontOptionList arg, int index);
BOX_FontOptionList BOX_replaceFontOptionListFontOptionAt(BOX_FontOptionList arg, BOX_FontOption elem, int index);
BOX_FontOptionList BOX_makeFontOptionList2(BOX_OptLayout wsAfterHead, BOX_FontOption elem1, BOX_FontOption elem2);
BOX_FontOptionList BOX_makeFontOptionList3(BOX_OptLayout wsAfterHead, BOX_FontOption elem1, BOX_FontOption elem2, BOX_FontOption elem3);
BOX_FontOptionList BOX_makeFontOptionList4(BOX_OptLayout wsAfterHead, BOX_FontOption elem1, BOX_FontOption elem2, BOX_FontOption elem3, BOX_FontOption elem4);
BOX_FontOptionList BOX_makeFontOptionList5(BOX_OptLayout wsAfterHead, BOX_FontOption elem1, BOX_FontOption elem2, BOX_FontOption elem3, BOX_FontOption elem4, BOX_FontOption elem5);
BOX_FontOptionList BOX_makeFontOptionList6(BOX_OptLayout wsAfterHead, BOX_FontOption elem1, BOX_FontOption elem2, BOX_FontOption elem3, BOX_FontOption elem4, BOX_FontOption elem5, BOX_FontOption elem6);

/*}}}  */
/*{{{  constructors */

BOX_NatCon BOX_makeNatConDefault(char* string);
BOX_Normal BOX_makeNormalDefault(char* string);
BOX_Escaped BOX_makeEscapedSpecialCharacter(char* string);
BOX_Escaped BOX_makeEscapedOctal(char* string);
BOX_StrCon BOX_makeStrConDefault(char* string);
BOX_SpaceSymbol BOX_makeSpaceSymbolHorizontal();
BOX_SpaceSymbol BOX_makeSpaceSymbolVertical();
BOX_SpaceSymbol BOX_makeSpaceSymbolIndentation();
BOX_SpaceOption BOX_makeSpaceOptionDefault(BOX_SpaceSymbol SpaceSymbol, BOX_OptLayout wsAfterSpaceSymbol, BOX_OptLayout wsAfterEquals, BOX_NatCon NatCon);
BOX_Box BOX_makeBoxString(BOX_StrCon StrCon);
BOX_Box BOX_makeBoxH(BOX_OptLayout wsAfterH, BOX_SpaceOptionOptions options, BOX_OptLayout wsAfterOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList list, BOX_OptLayout wsAfterList);
BOX_Box BOX_makeBoxV(BOX_OptLayout wsAfterV, BOX_SpaceOptionOptions options, BOX_OptLayout wsAfterOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList list, BOX_OptLayout wsAfterList);
BOX_Box BOX_makeBoxHv(BOX_OptLayout wsAfterHV, BOX_SpaceOptionOptions options, BOX_OptLayout wsAfterOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList list, BOX_OptLayout wsAfterList);
BOX_Box BOX_makeBoxHov(BOX_OptLayout wsAfterHOV, BOX_SpaceOptionOptions options, BOX_OptLayout wsAfterOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList list, BOX_OptLayout wsAfterList);
BOX_Box BOX_makeBoxI(BOX_OptLayout wsAfterI, BOX_SpaceOptionOptions options, BOX_OptLayout wsAfterOptions, BOX_OptLayout wsAfterBracketOpen, BOX_Box Box, BOX_OptLayout wsAfterBox);
BOX_Box BOX_makeBoxWd(BOX_OptLayout wsAfterWD, BOX_OptLayout wsAfterBracketOpen, BOX_Box Box, BOX_OptLayout wsAfterBox);
BOX_Box BOX_makeBoxFontOperator(BOX_FontOperator FontOperator, BOX_OptLayout wsAfterFontOperator, BOX_OptLayout wsAfterBracketOpen, BOX_Box Box, BOX_OptLayout wsAfterBox);
BOX_SpaceOptionOptions BOX_makeSpaceOptionOptionsEmpty();
BOX_SpaceOptionOptions BOX_makeSpaceOptionOptionsSingle(BOX_SpaceOption head);
BOX_SpaceOptionOptions BOX_makeSpaceOptionOptionsMany(BOX_SpaceOption head, BOX_OptLayout wsAfterHead, BOX_SpaceOptionOptions tail);
BOX_BoxList BOX_makeBoxListEmpty();
BOX_BoxList BOX_makeBoxListSingle(BOX_Box head);
BOX_BoxList BOX_makeBoxListMany(BOX_Box head, BOX_OptLayout wsAfterHead, BOX_BoxList tail);
BOX_FontId BOX_makeFontIdDefault(char* string);
BOX_FontValue BOX_makeFontValueNatural(BOX_NatCon NatCon);
BOX_FontValue BOX_makeFontValueFontId(BOX_FontId FontId);
BOX_FontOption BOX_makeFontOptionDefault(BOX_FontParam FontParam, BOX_OptLayout wsAfterFontParam, BOX_OptLayout wsAfterEquals, BOX_FontValue FontValue);
BOX_FontOperator BOX_makeFontOperatorDefault(BOX_OptLayout wsAfterF, BOX_FontOptionList list);
BOX_FontOperator BOX_makeFontOperatorKeyword();
BOX_FontOperator BOX_makeFontOperatorVariable();
BOX_FontOperator BOX_makeFontOperatorNumber();
BOX_FontOperator BOX_makeFontOperatorMath();
BOX_FontOperator BOX_makeFontOperatorEscape();
BOX_FontOperator BOX_makeFontOperatorComment();
BOX_FontOperator BOX_makeFontOperatorString();
BOX_FontOptionList BOX_makeFontOptionListEmpty();
BOX_FontOptionList BOX_makeFontOptionListSingle(BOX_FontOption head);
BOX_FontOptionList BOX_makeFontOptionListMany(BOX_FontOption head, BOX_OptLayout wsAfterHead, BOX_FontOptionList tail);
BOX_FontParam BOX_makeFontParamName();
BOX_FontParam BOX_makeFontParamFamily();
BOX_FontParam BOX_makeFontParamSeries();
BOX_FontParam BOX_makeFontParamShape();
BOX_FontParam BOX_makeFontParamSize();
BOX_FontParam BOX_makeFontParamColor();
BOX_OptLayout BOX_makeOptLayoutAbsent();
BOX_OptLayout BOX_makeOptLayoutPresent(char* string);
BOX_Start BOX_makeStartFontId(BOX_OptLayout wsBefore, BOX_FontId topFontId, BOX_OptLayout wsAfter, int ambCnt);
BOX_Start BOX_makeStartFontOperator(BOX_OptLayout wsBefore, BOX_FontOperator topFontOperator, BOX_OptLayout wsAfter, int ambCnt);
BOX_Start BOX_makeStartFontValue(BOX_OptLayout wsBefore, BOX_FontValue topFontValue, BOX_OptLayout wsAfter, int ambCnt);
BOX_Start BOX_makeStartFontOption(BOX_OptLayout wsBefore, BOX_FontOption topFontOption, BOX_OptLayout wsAfter, int ambCnt);
BOX_Start BOX_makeStartFontParam(BOX_OptLayout wsBefore, BOX_FontParam topFontParam, BOX_OptLayout wsAfter, int ambCnt);
BOX_Start BOX_makeStartSpaceOption(BOX_OptLayout wsBefore, BOX_SpaceOption topSpaceOption, BOX_OptLayout wsAfter, int ambCnt);
BOX_Start BOX_makeStartSpaceSymbol(BOX_OptLayout wsBefore, BOX_SpaceSymbol topSpaceSymbol, BOX_OptLayout wsAfter, int ambCnt);
BOX_Start BOX_makeStartBox(BOX_OptLayout wsBefore, BOX_Box topBox, BOX_OptLayout wsAfter, int ambCnt);
BOX_Start BOX_makeStartEscaped(BOX_OptLayout wsBefore, BOX_Escaped topEscaped, BOX_OptLayout wsAfter, int ambCnt);
BOX_Start BOX_makeStartNormal(BOX_OptLayout wsBefore, BOX_Normal topNormal, BOX_OptLayout wsAfter, int ambCnt);
BOX_Start BOX_makeStartStrCon(BOX_OptLayout wsBefore, BOX_StrCon topStrCon, BOX_OptLayout wsAfter, int ambCnt);
BOX_Start BOX_makeStartNatCon(BOX_OptLayout wsBefore, BOX_NatCon topNatCon, BOX_OptLayout wsAfter, int ambCnt);

/*}}}  */
/*{{{  equality functions */

ATbool BOX_isEqualNatCon(BOX_NatCon arg0, BOX_NatCon arg1);
ATbool BOX_isEqualNormal(BOX_Normal arg0, BOX_Normal arg1);
ATbool BOX_isEqualEscaped(BOX_Escaped arg0, BOX_Escaped arg1);
ATbool BOX_isEqualStrCon(BOX_StrCon arg0, BOX_StrCon arg1);
ATbool BOX_isEqualSpaceSymbol(BOX_SpaceSymbol arg0, BOX_SpaceSymbol arg1);
ATbool BOX_isEqualSpaceOption(BOX_SpaceOption arg0, BOX_SpaceOption arg1);
ATbool BOX_isEqualBox(BOX_Box arg0, BOX_Box arg1);
ATbool BOX_isEqualSpaceOptionOptions(BOX_SpaceOptionOptions arg0, BOX_SpaceOptionOptions arg1);
ATbool BOX_isEqualBoxList(BOX_BoxList arg0, BOX_BoxList arg1);
ATbool BOX_isEqualFontId(BOX_FontId arg0, BOX_FontId arg1);
ATbool BOX_isEqualFontValue(BOX_FontValue arg0, BOX_FontValue arg1);
ATbool BOX_isEqualFontOption(BOX_FontOption arg0, BOX_FontOption arg1);
ATbool BOX_isEqualFontOperator(BOX_FontOperator arg0, BOX_FontOperator arg1);
ATbool BOX_isEqualFontOptionList(BOX_FontOptionList arg0, BOX_FontOptionList arg1);
ATbool BOX_isEqualFontParam(BOX_FontParam arg0, BOX_FontParam arg1);
ATbool BOX_isEqualOptLayout(BOX_OptLayout arg0, BOX_OptLayout arg1);
ATbool BOX_isEqualStart(BOX_Start arg0, BOX_Start arg1);

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
inline ATbool BOX_isSpaceSymbolHorizontal(BOX_SpaceSymbol arg);
inline ATbool BOX_isSpaceSymbolVertical(BOX_SpaceSymbol arg);
inline ATbool BOX_isSpaceSymbolIndentation(BOX_SpaceSymbol arg);

/*}}}  */
/*{{{  BOX_SpaceOption accessors */

ATbool BOX_isValidSpaceOption(BOX_SpaceOption arg);
inline ATbool BOX_isSpaceOptionDefault(BOX_SpaceOption arg);
ATbool BOX_hasSpaceOptionSpaceSymbol(BOX_SpaceOption arg);
BOX_SpaceSymbol BOX_getSpaceOptionSpaceSymbol(BOX_SpaceOption arg);
BOX_SpaceOption BOX_setSpaceOptionSpaceSymbol(BOX_SpaceOption arg, BOX_SpaceSymbol SpaceSymbol);
ATbool BOX_hasSpaceOptionWsAfterSpaceSymbol(BOX_SpaceOption arg);
BOX_OptLayout BOX_getSpaceOptionWsAfterSpaceSymbol(BOX_SpaceOption arg);
BOX_SpaceOption BOX_setSpaceOptionWsAfterSpaceSymbol(BOX_SpaceOption arg, BOX_OptLayout wsAfterSpaceSymbol);
ATbool BOX_hasSpaceOptionWsAfterEquals(BOX_SpaceOption arg);
BOX_OptLayout BOX_getSpaceOptionWsAfterEquals(BOX_SpaceOption arg);
BOX_SpaceOption BOX_setSpaceOptionWsAfterEquals(BOX_SpaceOption arg, BOX_OptLayout wsAfterEquals);
ATbool BOX_hasSpaceOptionNatCon(BOX_SpaceOption arg);
BOX_NatCon BOX_getSpaceOptionNatCon(BOX_SpaceOption arg);
BOX_SpaceOption BOX_setSpaceOptionNatCon(BOX_SpaceOption arg, BOX_NatCon NatCon);

/*}}}  */
/*{{{  BOX_Box accessors */

ATbool BOX_isValidBox(BOX_Box arg);
inline ATbool BOX_isBoxString(BOX_Box arg);
inline ATbool BOX_isBoxH(BOX_Box arg);
inline ATbool BOX_isBoxV(BOX_Box arg);
inline ATbool BOX_isBoxHv(BOX_Box arg);
inline ATbool BOX_isBoxHov(BOX_Box arg);
inline ATbool BOX_isBoxI(BOX_Box arg);
inline ATbool BOX_isBoxWd(BOX_Box arg);
inline ATbool BOX_isBoxFontOperator(BOX_Box arg);
ATbool BOX_hasBoxStrCon(BOX_Box arg);
BOX_StrCon BOX_getBoxStrCon(BOX_Box arg);
BOX_Box BOX_setBoxStrCon(BOX_Box arg, BOX_StrCon StrCon);
ATbool BOX_hasBoxWsAfterH(BOX_Box arg);
BOX_OptLayout BOX_getBoxWsAfterH(BOX_Box arg);
BOX_Box BOX_setBoxWsAfterH(BOX_Box arg, BOX_OptLayout wsAfterH);
ATbool BOX_hasBoxOptions(BOX_Box arg);
BOX_SpaceOptionOptions BOX_getBoxOptions(BOX_Box arg);
BOX_Box BOX_setBoxOptions(BOX_Box arg, BOX_SpaceOptionOptions options);
ATbool BOX_hasBoxWsAfterOptions(BOX_Box arg);
BOX_OptLayout BOX_getBoxWsAfterOptions(BOX_Box arg);
BOX_Box BOX_setBoxWsAfterOptions(BOX_Box arg, BOX_OptLayout wsAfterOptions);
ATbool BOX_hasBoxWsAfterBracketOpen(BOX_Box arg);
BOX_OptLayout BOX_getBoxWsAfterBracketOpen(BOX_Box arg);
BOX_Box BOX_setBoxWsAfterBracketOpen(BOX_Box arg, BOX_OptLayout wsAfterBracketOpen);
ATbool BOX_hasBoxList(BOX_Box arg);
BOX_BoxList BOX_getBoxList(BOX_Box arg);
BOX_Box BOX_setBoxList(BOX_Box arg, BOX_BoxList list);
ATbool BOX_hasBoxWsAfterList(BOX_Box arg);
BOX_OptLayout BOX_getBoxWsAfterList(BOX_Box arg);
BOX_Box BOX_setBoxWsAfterList(BOX_Box arg, BOX_OptLayout wsAfterList);
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
ATbool BOX_hasBoxFontOperator(BOX_Box arg);
BOX_FontOperator BOX_getBoxFontOperator(BOX_Box arg);
BOX_Box BOX_setBoxFontOperator(BOX_Box arg, BOX_FontOperator FontOperator);
ATbool BOX_hasBoxWsAfterFontOperator(BOX_Box arg);
BOX_OptLayout BOX_getBoxWsAfterFontOperator(BOX_Box arg);
BOX_Box BOX_setBoxWsAfterFontOperator(BOX_Box arg, BOX_OptLayout wsAfterFontOperator);

/*}}}  */
/*{{{  BOX_SpaceOptionOptions accessors */

ATbool BOX_isValidSpaceOptionOptions(BOX_SpaceOptionOptions arg);
inline ATbool BOX_isSpaceOptionOptionsEmpty(BOX_SpaceOptionOptions arg);
inline ATbool BOX_isSpaceOptionOptionsSingle(BOX_SpaceOptionOptions arg);
inline ATbool BOX_isSpaceOptionOptionsMany(BOX_SpaceOptionOptions arg);
ATbool BOX_hasSpaceOptionOptionsHead(BOX_SpaceOptionOptions arg);
BOX_SpaceOption BOX_getSpaceOptionOptionsHead(BOX_SpaceOptionOptions arg);
BOX_SpaceOptionOptions BOX_setSpaceOptionOptionsHead(BOX_SpaceOptionOptions arg, BOX_SpaceOption head);
ATbool BOX_hasSpaceOptionOptionsWsAfterHead(BOX_SpaceOptionOptions arg);
BOX_OptLayout BOX_getSpaceOptionOptionsWsAfterHead(BOX_SpaceOptionOptions arg);
BOX_SpaceOptionOptions BOX_setSpaceOptionOptionsWsAfterHead(BOX_SpaceOptionOptions arg, BOX_OptLayout wsAfterHead);
ATbool BOX_hasSpaceOptionOptionsTail(BOX_SpaceOptionOptions arg);
BOX_SpaceOptionOptions BOX_getSpaceOptionOptionsTail(BOX_SpaceOptionOptions arg);
BOX_SpaceOptionOptions BOX_setSpaceOptionOptionsTail(BOX_SpaceOptionOptions arg, BOX_SpaceOptionOptions tail);

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
/*{{{  BOX_FontId accessors */

ATbool BOX_isValidFontId(BOX_FontId arg);
inline ATbool BOX_isFontIdDefault(BOX_FontId arg);
ATbool BOX_hasFontIdString(BOX_FontId arg);
char* BOX_getFontIdString(BOX_FontId arg);
BOX_FontId BOX_setFontIdString(BOX_FontId arg, char* string);

/*}}}  */
/*{{{  BOX_FontValue accessors */

ATbool BOX_isValidFontValue(BOX_FontValue arg);
inline ATbool BOX_isFontValueNatural(BOX_FontValue arg);
inline ATbool BOX_isFontValueFontId(BOX_FontValue arg);
ATbool BOX_hasFontValueNatCon(BOX_FontValue arg);
BOX_NatCon BOX_getFontValueNatCon(BOX_FontValue arg);
BOX_FontValue BOX_setFontValueNatCon(BOX_FontValue arg, BOX_NatCon NatCon);
ATbool BOX_hasFontValueFontId(BOX_FontValue arg);
BOX_FontId BOX_getFontValueFontId(BOX_FontValue arg);
BOX_FontValue BOX_setFontValueFontId(BOX_FontValue arg, BOX_FontId FontId);

/*}}}  */
/*{{{  BOX_FontOption accessors */

ATbool BOX_isValidFontOption(BOX_FontOption arg);
inline ATbool BOX_isFontOptionDefault(BOX_FontOption arg);
ATbool BOX_hasFontOptionFontParam(BOX_FontOption arg);
BOX_FontParam BOX_getFontOptionFontParam(BOX_FontOption arg);
BOX_FontOption BOX_setFontOptionFontParam(BOX_FontOption arg, BOX_FontParam FontParam);
ATbool BOX_hasFontOptionWsAfterFontParam(BOX_FontOption arg);
BOX_OptLayout BOX_getFontOptionWsAfterFontParam(BOX_FontOption arg);
BOX_FontOption BOX_setFontOptionWsAfterFontParam(BOX_FontOption arg, BOX_OptLayout wsAfterFontParam);
ATbool BOX_hasFontOptionWsAfterEquals(BOX_FontOption arg);
BOX_OptLayout BOX_getFontOptionWsAfterEquals(BOX_FontOption arg);
BOX_FontOption BOX_setFontOptionWsAfterEquals(BOX_FontOption arg, BOX_OptLayout wsAfterEquals);
ATbool BOX_hasFontOptionFontValue(BOX_FontOption arg);
BOX_FontValue BOX_getFontOptionFontValue(BOX_FontOption arg);
BOX_FontOption BOX_setFontOptionFontValue(BOX_FontOption arg, BOX_FontValue FontValue);

/*}}}  */
/*{{{  BOX_FontOperator accessors */

ATbool BOX_isValidFontOperator(BOX_FontOperator arg);
inline ATbool BOX_isFontOperatorDefault(BOX_FontOperator arg);
inline ATbool BOX_isFontOperatorKeyword(BOX_FontOperator arg);
inline ATbool BOX_isFontOperatorVariable(BOX_FontOperator arg);
inline ATbool BOX_isFontOperatorNumber(BOX_FontOperator arg);
inline ATbool BOX_isFontOperatorMath(BOX_FontOperator arg);
inline ATbool BOX_isFontOperatorEscape(BOX_FontOperator arg);
inline ATbool BOX_isFontOperatorComment(BOX_FontOperator arg);
inline ATbool BOX_isFontOperatorString(BOX_FontOperator arg);
ATbool BOX_hasFontOperatorWsAfterF(BOX_FontOperator arg);
BOX_OptLayout BOX_getFontOperatorWsAfterF(BOX_FontOperator arg);
BOX_FontOperator BOX_setFontOperatorWsAfterF(BOX_FontOperator arg, BOX_OptLayout wsAfterF);
ATbool BOX_hasFontOperatorList(BOX_FontOperator arg);
BOX_FontOptionList BOX_getFontOperatorList(BOX_FontOperator arg);
BOX_FontOperator BOX_setFontOperatorList(BOX_FontOperator arg, BOX_FontOptionList list);

/*}}}  */
/*{{{  BOX_FontOptionList accessors */

ATbool BOX_isValidFontOptionList(BOX_FontOptionList arg);
inline ATbool BOX_isFontOptionListEmpty(BOX_FontOptionList arg);
inline ATbool BOX_isFontOptionListSingle(BOX_FontOptionList arg);
inline ATbool BOX_isFontOptionListMany(BOX_FontOptionList arg);
ATbool BOX_hasFontOptionListHead(BOX_FontOptionList arg);
BOX_FontOption BOX_getFontOptionListHead(BOX_FontOptionList arg);
BOX_FontOptionList BOX_setFontOptionListHead(BOX_FontOptionList arg, BOX_FontOption head);
ATbool BOX_hasFontOptionListWsAfterHead(BOX_FontOptionList arg);
BOX_OptLayout BOX_getFontOptionListWsAfterHead(BOX_FontOptionList arg);
BOX_FontOptionList BOX_setFontOptionListWsAfterHead(BOX_FontOptionList arg, BOX_OptLayout wsAfterHead);
ATbool BOX_hasFontOptionListTail(BOX_FontOptionList arg);
BOX_FontOptionList BOX_getFontOptionListTail(BOX_FontOptionList arg);
BOX_FontOptionList BOX_setFontOptionListTail(BOX_FontOptionList arg, BOX_FontOptionList tail);

/*}}}  */
/*{{{  BOX_FontParam accessors */

ATbool BOX_isValidFontParam(BOX_FontParam arg);
inline ATbool BOX_isFontParamName(BOX_FontParam arg);
inline ATbool BOX_isFontParamFamily(BOX_FontParam arg);
inline ATbool BOX_isFontParamSeries(BOX_FontParam arg);
inline ATbool BOX_isFontParamShape(BOX_FontParam arg);
inline ATbool BOX_isFontParamSize(BOX_FontParam arg);
inline ATbool BOX_isFontParamColor(BOX_FontParam arg);

/*}}}  */
/*{{{  BOX_OptLayout accessors */

ATbool BOX_isValidOptLayout(BOX_OptLayout arg);
inline ATbool BOX_isOptLayoutAbsent(BOX_OptLayout arg);
inline ATbool BOX_isOptLayoutPresent(BOX_OptLayout arg);
ATbool BOX_hasOptLayoutString(BOX_OptLayout arg);
char* BOX_getOptLayoutString(BOX_OptLayout arg);
BOX_OptLayout BOX_setOptLayoutString(BOX_OptLayout arg, char* string);

/*}}}  */
/*{{{  BOX_Start accessors */

ATbool BOX_isValidStart(BOX_Start arg);
inline ATbool BOX_isStartFontId(BOX_Start arg);
inline ATbool BOX_isStartFontOperator(BOX_Start arg);
inline ATbool BOX_isStartFontValue(BOX_Start arg);
inline ATbool BOX_isStartFontOption(BOX_Start arg);
inline ATbool BOX_isStartFontParam(BOX_Start arg);
inline ATbool BOX_isStartSpaceOption(BOX_Start arg);
inline ATbool BOX_isStartSpaceSymbol(BOX_Start arg);
inline ATbool BOX_isStartBox(BOX_Start arg);
inline ATbool BOX_isStartEscaped(BOX_Start arg);
inline ATbool BOX_isStartNormal(BOX_Start arg);
inline ATbool BOX_isStartStrCon(BOX_Start arg);
inline ATbool BOX_isStartNatCon(BOX_Start arg);
ATbool BOX_hasStartWsBefore(BOX_Start arg);
BOX_OptLayout BOX_getStartWsBefore(BOX_Start arg);
BOX_Start BOX_setStartWsBefore(BOX_Start arg, BOX_OptLayout wsBefore);
ATbool BOX_hasStartTopFontId(BOX_Start arg);
BOX_FontId BOX_getStartTopFontId(BOX_Start arg);
BOX_Start BOX_setStartTopFontId(BOX_Start arg, BOX_FontId topFontId);
ATbool BOX_hasStartWsAfter(BOX_Start arg);
BOX_OptLayout BOX_getStartWsAfter(BOX_Start arg);
BOX_Start BOX_setStartWsAfter(BOX_Start arg, BOX_OptLayout wsAfter);
ATbool BOX_hasStartAmbCnt(BOX_Start arg);
int BOX_getStartAmbCnt(BOX_Start arg);
BOX_Start BOX_setStartAmbCnt(BOX_Start arg, int ambCnt);
ATbool BOX_hasStartTopFontOperator(BOX_Start arg);
BOX_FontOperator BOX_getStartTopFontOperator(BOX_Start arg);
BOX_Start BOX_setStartTopFontOperator(BOX_Start arg, BOX_FontOperator topFontOperator);
ATbool BOX_hasStartTopFontValue(BOX_Start arg);
BOX_FontValue BOX_getStartTopFontValue(BOX_Start arg);
BOX_Start BOX_setStartTopFontValue(BOX_Start arg, BOX_FontValue topFontValue);
ATbool BOX_hasStartTopFontOption(BOX_Start arg);
BOX_FontOption BOX_getStartTopFontOption(BOX_Start arg);
BOX_Start BOX_setStartTopFontOption(BOX_Start arg, BOX_FontOption topFontOption);
ATbool BOX_hasStartTopFontParam(BOX_Start arg);
BOX_FontParam BOX_getStartTopFontParam(BOX_Start arg);
BOX_Start BOX_setStartTopFontParam(BOX_Start arg, BOX_FontParam topFontParam);
ATbool BOX_hasStartTopSpaceOption(BOX_Start arg);
BOX_SpaceOption BOX_getStartTopSpaceOption(BOX_Start arg);
BOX_Start BOX_setStartTopSpaceOption(BOX_Start arg, BOX_SpaceOption topSpaceOption);
ATbool BOX_hasStartTopSpaceSymbol(BOX_Start arg);
BOX_SpaceSymbol BOX_getStartTopSpaceSymbol(BOX_Start arg);
BOX_Start BOX_setStartTopSpaceSymbol(BOX_Start arg, BOX_SpaceSymbol topSpaceSymbol);
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
/*{{{  sort visitors */

BOX_NatCon BOX_visitNatCon(BOX_NatCon arg, char* (*acceptString)(char*));
BOX_Normal BOX_visitNormal(BOX_Normal arg, char* (*acceptString)(char*));
BOX_Escaped BOX_visitEscaped(BOX_Escaped arg, char* (*acceptString)(char*));
BOX_StrCon BOX_visitStrCon(BOX_StrCon arg, char* (*acceptString)(char*));
BOX_SpaceSymbol BOX_visitSpaceSymbol(BOX_SpaceSymbol arg);
BOX_SpaceOption BOX_visitSpaceOption(BOX_SpaceOption arg, BOX_SpaceSymbol (*acceptSpaceSymbol)(BOX_SpaceSymbol), BOX_OptLayout (*acceptWsAfterSpaceSymbol)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterEquals)(BOX_OptLayout), BOX_NatCon (*acceptNatCon)(BOX_NatCon));
BOX_Box BOX_visitBox(BOX_Box arg, BOX_StrCon (*acceptStrCon)(BOX_StrCon), BOX_OptLayout (*acceptWsAfterH)(BOX_OptLayout), BOX_SpaceOptionOptions (*acceptOptions)(BOX_SpaceOptionOptions), BOX_OptLayout (*acceptWsAfterOptions)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterBracketOpen)(BOX_OptLayout), BOX_BoxList (*acceptList)(BOX_BoxList), BOX_OptLayout (*acceptWsAfterList)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterV)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterHV)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterHOV)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterI)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterBox)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterWD)(BOX_OptLayout), BOX_FontOperator (*acceptFontOperator)(BOX_FontOperator), BOX_OptLayout (*acceptWsAfterFontOperator)(BOX_OptLayout));
BOX_SpaceOptionOptions BOX_visitSpaceOptionOptions(BOX_SpaceOptionOptions arg, BOX_SpaceOption (*acceptHead)(BOX_SpaceOption), BOX_OptLayout (*acceptWsAfterHead)(BOX_OptLayout));
BOX_BoxList BOX_visitBoxList(BOX_BoxList arg, BOX_Box (*acceptHead)(BOX_Box), BOX_OptLayout (*acceptWsAfterHead)(BOX_OptLayout));
BOX_FontId BOX_visitFontId(BOX_FontId arg, char* (*acceptString)(char*));
BOX_FontValue BOX_visitFontValue(BOX_FontValue arg, BOX_NatCon (*acceptNatCon)(BOX_NatCon), BOX_FontId (*acceptFontId)(BOX_FontId));
BOX_FontOption BOX_visitFontOption(BOX_FontOption arg, BOX_FontParam (*acceptFontParam)(BOX_FontParam), BOX_OptLayout (*acceptWsAfterFontParam)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterEquals)(BOX_OptLayout), BOX_FontValue (*acceptFontValue)(BOX_FontValue));
BOX_FontOperator BOX_visitFontOperator(BOX_FontOperator arg, BOX_OptLayout (*acceptWsAfterF)(BOX_OptLayout), BOX_FontOptionList (*acceptList)(BOX_FontOptionList));
BOX_FontOptionList BOX_visitFontOptionList(BOX_FontOptionList arg, BOX_FontOption (*acceptHead)(BOX_FontOption), BOX_OptLayout (*acceptWsAfterHead)(BOX_OptLayout));
BOX_FontParam BOX_visitFontParam(BOX_FontParam arg);
BOX_OptLayout BOX_visitOptLayout(BOX_OptLayout arg, char* (*acceptString)(char*));
BOX_Start BOX_visitStart(BOX_Start arg, BOX_OptLayout (*acceptWsBefore)(BOX_OptLayout), BOX_FontId (*acceptTopFontId)(BOX_FontId), BOX_OptLayout (*acceptWsAfter)(BOX_OptLayout), int (*acceptAmbCnt)(int), BOX_FontOperator (*acceptTopFontOperator)(BOX_FontOperator), BOX_FontValue (*acceptTopFontValue)(BOX_FontValue), BOX_FontOption (*acceptTopFontOption)(BOX_FontOption), BOX_FontParam (*acceptTopFontParam)(BOX_FontParam), BOX_SpaceOption (*acceptTopSpaceOption)(BOX_SpaceOption), BOX_SpaceSymbol (*acceptTopSpaceSymbol)(BOX_SpaceSymbol), BOX_Box (*acceptTopBox)(BOX_Box), BOX_Escaped (*acceptTopEscaped)(BOX_Escaped), BOX_Normal (*acceptTopNormal)(BOX_Normal), BOX_StrCon (*acceptTopStrCon)(BOX_StrCon), BOX_NatCon (*acceptTopNatCon)(BOX_NatCon));

/*}}}  */

#endif /* _BOX_H */
