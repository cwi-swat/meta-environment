#ifndef _BOX_H
#define _BOX_H

/*{{{  includes */

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "Box_dict.h"

/*}}}  */

/*{{{  typedefs */

typedef struct _BOX_OptLayout *BOX_OptLayout;
typedef struct _BOX_Layout *BOX_Layout;
typedef struct _BOX_LexLayoutList *BOX_LexLayoutList;
typedef struct _BOX_LexFontId *BOX_LexFontId;
typedef struct _BOX_FontId *BOX_FontId;
typedef struct _BOX_FontValue *BOX_FontValue;
typedef struct _BOX_FontOption *BOX_FontOption;
typedef struct _BOX_FontOperator *BOX_FontOperator;
typedef struct _BOX_Box *BOX_Box;
typedef struct _BOX_FontParam *BOX_FontParam;
typedef struct _BOX_FontOptionList *BOX_FontOptionList;
typedef struct _BOX_BoxList *BOX_BoxList;
typedef struct _BOX_LexNatCon *BOX_LexNatCon;
typedef struct _BOX_NatCon *BOX_NatCon;
typedef struct _BOX_LexStrChar *BOX_LexStrChar;
typedef struct _BOX_StrChar *BOX_StrChar;
typedef struct _BOX_LexStrCon *BOX_LexStrCon;
typedef struct _BOX_StrCon *BOX_StrCon;
typedef struct _BOX_LexStrCharChars *BOX_LexStrCharChars;
typedef struct _BOX_LexLayout *BOX_LexLayout;
typedef struct _BOX_SpaceSymbol *BOX_SpaceSymbol;
typedef struct _BOX_SpaceOption *BOX_SpaceOption;
typedef struct _BOX_SpaceOptionOptions *BOX_SpaceOptionOptions;
typedef struct _BOX_AlignmentOption *BOX_AlignmentOption;
typedef struct _BOX_AlignmentOptions *BOX_AlignmentOptions;
typedef struct _BOX_AlignmentOptionList *BOX_AlignmentOptionList;
typedef struct _BOX_Start *BOX_Start;

/*}}}  */

void BOX_initBoxApi(void);

/*{{{  protect functions */

void BOX_protectOptLayout(BOX_OptLayout *arg);
void BOX_protectLayout(BOX_Layout *arg);
void BOX_protectLexLayoutList(BOX_LexLayoutList *arg);
void BOX_protectLexFontId(BOX_LexFontId *arg);
void BOX_protectFontId(BOX_FontId *arg);
void BOX_protectFontValue(BOX_FontValue *arg);
void BOX_protectFontOption(BOX_FontOption *arg);
void BOX_protectFontOperator(BOX_FontOperator *arg);
void BOX_protectBox(BOX_Box *arg);
void BOX_protectFontParam(BOX_FontParam *arg);
void BOX_protectFontOptionList(BOX_FontOptionList *arg);
void BOX_protectBoxList(BOX_BoxList *arg);
void BOX_protectLexNatCon(BOX_LexNatCon *arg);
void BOX_protectNatCon(BOX_NatCon *arg);
void BOX_protectLexStrChar(BOX_LexStrChar *arg);
void BOX_protectStrChar(BOX_StrChar *arg);
void BOX_protectLexStrCon(BOX_LexStrCon *arg);
void BOX_protectStrCon(BOX_StrCon *arg);
void BOX_protectLexStrCharChars(BOX_LexStrCharChars *arg);
void BOX_protectLexLayout(BOX_LexLayout *arg);
void BOX_protectSpaceSymbol(BOX_SpaceSymbol *arg);
void BOX_protectSpaceOption(BOX_SpaceOption *arg);
void BOX_protectSpaceOptionOptions(BOX_SpaceOptionOptions *arg);
void BOX_protectAlignmentOption(BOX_AlignmentOption *arg);
void BOX_protectAlignmentOptions(BOX_AlignmentOptions *arg);
void BOX_protectAlignmentOptionList(BOX_AlignmentOptionList *arg);
void BOX_protectStart(BOX_Start *arg);

/*}}}  */
/*{{{  term conversion functions */

BOX_OptLayout BOX_OptLayoutFromTerm(ATerm t);
ATerm BOX_OptLayoutToTerm(BOX_OptLayout arg);
BOX_Layout BOX_LayoutFromTerm(ATerm t);
ATerm BOX_LayoutToTerm(BOX_Layout arg);
BOX_LexLayoutList BOX_LexLayoutListFromTerm(ATerm t);
ATerm BOX_LexLayoutListToTerm(BOX_LexLayoutList arg);
BOX_LexFontId BOX_LexFontIdFromTerm(ATerm t);
ATerm BOX_LexFontIdToTerm(BOX_LexFontId arg);
BOX_FontId BOX_FontIdFromTerm(ATerm t);
ATerm BOX_FontIdToTerm(BOX_FontId arg);
BOX_FontValue BOX_FontValueFromTerm(ATerm t);
ATerm BOX_FontValueToTerm(BOX_FontValue arg);
BOX_FontOption BOX_FontOptionFromTerm(ATerm t);
ATerm BOX_FontOptionToTerm(BOX_FontOption arg);
BOX_FontOperator BOX_FontOperatorFromTerm(ATerm t);
ATerm BOX_FontOperatorToTerm(BOX_FontOperator arg);
BOX_Box BOX_BoxFromTerm(ATerm t);
ATerm BOX_BoxToTerm(BOX_Box arg);
BOX_FontParam BOX_FontParamFromTerm(ATerm t);
ATerm BOX_FontParamToTerm(BOX_FontParam arg);
BOX_FontOptionList BOX_FontOptionListFromTerm(ATerm t);
ATerm BOX_FontOptionListToTerm(BOX_FontOptionList arg);
BOX_BoxList BOX_BoxListFromTerm(ATerm t);
ATerm BOX_BoxListToTerm(BOX_BoxList arg);
BOX_LexNatCon BOX_LexNatConFromTerm(ATerm t);
ATerm BOX_LexNatConToTerm(BOX_LexNatCon arg);
BOX_NatCon BOX_NatConFromTerm(ATerm t);
ATerm BOX_NatConToTerm(BOX_NatCon arg);
BOX_LexStrChar BOX_LexStrCharFromTerm(ATerm t);
ATerm BOX_LexStrCharToTerm(BOX_LexStrChar arg);
BOX_StrChar BOX_StrCharFromTerm(ATerm t);
ATerm BOX_StrCharToTerm(BOX_StrChar arg);
BOX_LexStrCon BOX_LexStrConFromTerm(ATerm t);
ATerm BOX_LexStrConToTerm(BOX_LexStrCon arg);
BOX_StrCon BOX_StrConFromTerm(ATerm t);
ATerm BOX_StrConToTerm(BOX_StrCon arg);
BOX_LexStrCharChars BOX_LexStrCharCharsFromTerm(ATerm t);
ATerm BOX_LexStrCharCharsToTerm(BOX_LexStrCharChars arg);
BOX_LexLayout BOX_LexLayoutFromTerm(ATerm t);
ATerm BOX_LexLayoutToTerm(BOX_LexLayout arg);
BOX_SpaceSymbol BOX_SpaceSymbolFromTerm(ATerm t);
ATerm BOX_SpaceSymbolToTerm(BOX_SpaceSymbol arg);
BOX_SpaceOption BOX_SpaceOptionFromTerm(ATerm t);
ATerm BOX_SpaceOptionToTerm(BOX_SpaceOption arg);
BOX_SpaceOptionOptions BOX_SpaceOptionOptionsFromTerm(ATerm t);
ATerm BOX_SpaceOptionOptionsToTerm(BOX_SpaceOptionOptions arg);
BOX_AlignmentOption BOX_AlignmentOptionFromTerm(ATerm t);
ATerm BOX_AlignmentOptionToTerm(BOX_AlignmentOption arg);
BOX_AlignmentOptions BOX_AlignmentOptionsFromTerm(ATerm t);
ATerm BOX_AlignmentOptionsToTerm(BOX_AlignmentOptions arg);
BOX_AlignmentOptionList BOX_AlignmentOptionListFromTerm(ATerm t);
ATerm BOX_AlignmentOptionListToTerm(BOX_AlignmentOptionList arg);
BOX_Start BOX_StartFromTerm(ATerm t);
ATerm BOX_StartToTerm(BOX_Start arg);

/*}}}  */
/*{{{  list functions */

int BOX_getLexLayoutListLength (BOX_LexLayoutList arg);
BOX_LexLayoutList BOX_reverseLexLayoutList(BOX_LexLayoutList arg);
BOX_LexLayoutList BOX_appendLexLayoutList(BOX_LexLayoutList arg, BOX_LexLayout elem);
BOX_LexLayoutList BOX_concatLexLayoutList(BOX_LexLayoutList arg0, BOX_LexLayoutList arg1);
BOX_LexLayoutList BOX_sliceLexLayoutList(BOX_LexLayoutList arg, int start, int end);
BOX_LexLayout BOX_getLexLayoutListLexLayoutAt(BOX_LexLayoutList arg, int index);
BOX_LexLayoutList BOX_replaceLexLayoutListLexLayoutAt(BOX_LexLayoutList arg, BOX_LexLayout elem, int index);
BOX_LexLayoutList BOX_makeLexLayoutList2(BOX_LexLayout elem1, BOX_LexLayout elem2);
BOX_LexLayoutList BOX_makeLexLayoutList3(BOX_LexLayout elem1, BOX_LexLayout elem2, BOX_LexLayout elem3);
BOX_LexLayoutList BOX_makeLexLayoutList4(BOX_LexLayout elem1, BOX_LexLayout elem2, BOX_LexLayout elem3, BOX_LexLayout elem4);
BOX_LexLayoutList BOX_makeLexLayoutList5(BOX_LexLayout elem1, BOX_LexLayout elem2, BOX_LexLayout elem3, BOX_LexLayout elem4, BOX_LexLayout elem5);
BOX_LexLayoutList BOX_makeLexLayoutList6(BOX_LexLayout elem1, BOX_LexLayout elem2, BOX_LexLayout elem3, BOX_LexLayout elem4, BOX_LexLayout elem5, BOX_LexLayout elem6);
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
int BOX_getLexStrCharCharsLength (BOX_LexStrCharChars arg);
BOX_LexStrCharChars BOX_reverseLexStrCharChars(BOX_LexStrCharChars arg);
BOX_LexStrCharChars BOX_appendLexStrCharChars(BOX_LexStrCharChars arg, BOX_LexStrChar elem);
BOX_LexStrCharChars BOX_concatLexStrCharChars(BOX_LexStrCharChars arg0, BOX_LexStrCharChars arg1);
BOX_LexStrCharChars BOX_sliceLexStrCharChars(BOX_LexStrCharChars arg, int start, int end);
BOX_LexStrChar BOX_getLexStrCharCharsLexStrCharAt(BOX_LexStrCharChars arg, int index);
BOX_LexStrCharChars BOX_replaceLexStrCharCharsLexStrCharAt(BOX_LexStrCharChars arg, BOX_LexStrChar elem, int index);
BOX_LexStrCharChars BOX_makeLexStrCharChars2(BOX_LexStrChar elem1, BOX_LexStrChar elem2);
BOX_LexStrCharChars BOX_makeLexStrCharChars3(BOX_LexStrChar elem1, BOX_LexStrChar elem2, BOX_LexStrChar elem3);
BOX_LexStrCharChars BOX_makeLexStrCharChars4(BOX_LexStrChar elem1, BOX_LexStrChar elem2, BOX_LexStrChar elem3, BOX_LexStrChar elem4);
BOX_LexStrCharChars BOX_makeLexStrCharChars5(BOX_LexStrChar elem1, BOX_LexStrChar elem2, BOX_LexStrChar elem3, BOX_LexStrChar elem4, BOX_LexStrChar elem5);
BOX_LexStrCharChars BOX_makeLexStrCharChars6(BOX_LexStrChar elem1, BOX_LexStrChar elem2, BOX_LexStrChar elem3, BOX_LexStrChar elem4, BOX_LexStrChar elem5, BOX_LexStrChar elem6);
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
int BOX_getAlignmentOptionListLength (BOX_AlignmentOptionList arg);
BOX_AlignmentOptionList BOX_reverseAlignmentOptionList(BOX_AlignmentOptionList arg);
BOX_AlignmentOptionList BOX_appendAlignmentOptionList(BOX_AlignmentOptionList arg0, BOX_OptLayout wsAfterHead, BOX_OptLayout wsAfterSep, BOX_AlignmentOption arg1);
BOX_AlignmentOptionList BOX_concatAlignmentOptionList(BOX_AlignmentOptionList arg0, BOX_OptLayout wsAfterHead, BOX_OptLayout wsAfterSep, BOX_AlignmentOptionList arg1);
BOX_AlignmentOptionList BOX_sliceAlignmentOptionList(BOX_AlignmentOptionList arg, int start, int end);
BOX_AlignmentOption BOX_getAlignmentOptionListAlignmentOptionAt(BOX_AlignmentOptionList arg, int index);
BOX_AlignmentOptionList BOX_replaceAlignmentOptionListAlignmentOptionAt(BOX_AlignmentOptionList arg, BOX_AlignmentOption elem, int index);
BOX_AlignmentOptionList BOX_makeAlignmentOptionList2(BOX_OptLayout wsAfterHead, BOX_OptLayout wsAfterSep, BOX_AlignmentOption elem1, BOX_AlignmentOption elem2);
BOX_AlignmentOptionList BOX_makeAlignmentOptionList3(BOX_OptLayout wsAfterHead, BOX_OptLayout wsAfterSep, BOX_AlignmentOption elem1, BOX_AlignmentOption elem2, BOX_AlignmentOption elem3);
BOX_AlignmentOptionList BOX_makeAlignmentOptionList4(BOX_OptLayout wsAfterHead, BOX_OptLayout wsAfterSep, BOX_AlignmentOption elem1, BOX_AlignmentOption elem2, BOX_AlignmentOption elem3, BOX_AlignmentOption elem4);
BOX_AlignmentOptionList BOX_makeAlignmentOptionList5(BOX_OptLayout wsAfterHead, BOX_OptLayout wsAfterSep, BOX_AlignmentOption elem1, BOX_AlignmentOption elem2, BOX_AlignmentOption elem3, BOX_AlignmentOption elem4, BOX_AlignmentOption elem5);
BOX_AlignmentOptionList BOX_makeAlignmentOptionList6(BOX_OptLayout wsAfterHead, BOX_OptLayout wsAfterSep, BOX_AlignmentOption elem1, BOX_AlignmentOption elem2, BOX_AlignmentOption elem3, BOX_AlignmentOption elem4, BOX_AlignmentOption elem5, BOX_AlignmentOption elem6);

/*}}}  */
/*{{{  constructors */

BOX_OptLayout BOX_makeOptLayoutAbsent(void);
BOX_OptLayout BOX_makeOptLayoutPresent(BOX_Layout layout);
BOX_Layout BOX_makeLayoutLexToCf(BOX_LexLayoutList list);
BOX_LexLayoutList BOX_makeLexLayoutListEmpty(void);
BOX_LexLayoutList BOX_makeLexLayoutListSingle(BOX_LexLayout head);
BOX_LexLayoutList BOX_makeLexLayoutListMany(BOX_LexLayout head, BOX_LexLayoutList tail);
BOX_LexFontId BOX_makeLexFontIdDefault(const char* list);
BOX_FontId BOX_makeFontIdLexToCf(BOX_LexFontId FontId);
BOX_FontValue BOX_makeFontValueNatural(BOX_NatCon NatCon);
BOX_FontValue BOX_makeFontValueFontId(BOX_FontId FontId);
BOX_FontOption BOX_makeFontOptionDefault(BOX_FontParam FontParam, BOX_OptLayout wsAfterFontParam, BOX_OptLayout wsAfterEquals, BOX_FontValue FontValue);
BOX_FontOperator BOX_makeFontOperatorDefault(BOX_OptLayout wsAfterF, BOX_FontOptionList list);
BOX_FontOperator BOX_makeFontOperatorKeyword(void);
BOX_FontOperator BOX_makeFontOperatorVariable(void);
BOX_FontOperator BOX_makeFontOperatorNumber(void);
BOX_FontOperator BOX_makeFontOperatorMath(void);
BOX_FontOperator BOX_makeFontOperatorEscape(void);
BOX_FontOperator BOX_makeFontOperatorComment(void);
BOX_FontOperator BOX_makeFontOperatorString(void);
BOX_Box BOX_makeBoxFontOperator(BOX_FontOperator FontOperator, BOX_OptLayout wsAfterFontOperator, BOX_OptLayout wsAfterBracketOpen, BOX_Box Box, BOX_OptLayout wsAfterBox);
BOX_Box BOX_makeBoxDefault(BOX_OptLayout wsAfterCOMM, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList list, BOX_OptLayout wsAfterList);
BOX_Box BOX_makeBoxString(BOX_StrCon StrCon);
BOX_Box BOX_makeBoxH(BOX_OptLayout wsAfterH, BOX_SpaceOptionOptions options, BOX_OptLayout wsAfterOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList list, BOX_OptLayout wsAfterList);
BOX_Box BOX_makeBoxV(BOX_OptLayout wsAfterV, BOX_SpaceOptionOptions options, BOX_OptLayout wsAfterOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList list, BOX_OptLayout wsAfterList);
BOX_Box BOX_makeBoxHv(BOX_OptLayout wsAfterHV, BOX_SpaceOptionOptions options, BOX_OptLayout wsAfterOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList list, BOX_OptLayout wsAfterList);
BOX_Box BOX_makeBoxHov(BOX_OptLayout wsAfterHOV, BOX_SpaceOptionOptions options, BOX_OptLayout wsAfterOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList list, BOX_OptLayout wsAfterList);
BOX_Box BOX_makeBoxI(BOX_OptLayout wsAfterI, BOX_SpaceOptionOptions options, BOX_OptLayout wsAfterOptions, BOX_OptLayout wsAfterBracketOpen, BOX_Box Box, BOX_OptLayout wsAfterBox);
BOX_Box BOX_makeBoxWd(BOX_OptLayout wsAfterWD, BOX_OptLayout wsAfterBracketOpen, BOX_Box Box, BOX_OptLayout wsAfterBox);
BOX_Box BOX_makeBoxAlignment(BOX_OptLayout wsAfterA, BOX_AlignmentOptions alignments, BOX_OptLayout wsAfterAlignments, BOX_SpaceOptionOptions options, BOX_OptLayout wsAfterOptions, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList list, BOX_OptLayout wsAfterList);
BOX_Box BOX_makeBoxRow(BOX_OptLayout wsAfterR, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList list, BOX_OptLayout wsAfterList);
BOX_FontParam BOX_makeFontParamName(void);
BOX_FontParam BOX_makeFontParamFamily(void);
BOX_FontParam BOX_makeFontParamSeries(void);
BOX_FontParam BOX_makeFontParamShape(void);
BOX_FontParam BOX_makeFontParamSize(void);
BOX_FontParam BOX_makeFontParamColor(void);
BOX_FontOptionList BOX_makeFontOptionListEmpty(void);
BOX_FontOptionList BOX_makeFontOptionListSingle(BOX_FontOption head);
BOX_FontOptionList BOX_makeFontOptionListMany(BOX_FontOption head, BOX_OptLayout wsAfterHead, BOX_FontOptionList tail);
BOX_BoxList BOX_makeBoxListEmpty(void);
BOX_BoxList BOX_makeBoxListSingle(BOX_Box head);
BOX_BoxList BOX_makeBoxListMany(BOX_Box head, BOX_OptLayout wsAfterHead, BOX_BoxList tail);
BOX_LexNatCon BOX_makeLexNatConDigits(const char* list);
BOX_NatCon BOX_makeNatConLexToCf(BOX_LexNatCon NatCon);
BOX_LexStrChar BOX_makeLexStrCharNewline(void);
BOX_LexStrChar BOX_makeLexStrCharTab(void);
BOX_LexStrChar BOX_makeLexStrCharQuote(void);
BOX_LexStrChar BOX_makeLexStrCharBackslash(void);
BOX_LexStrChar BOX_makeLexStrCharDecimal(char a, char b, char c);
BOX_LexStrChar BOX_makeLexStrCharNormal(char ch);
BOX_StrChar BOX_makeStrCharLexToCf(BOX_LexStrChar StrChar);
BOX_LexStrCon BOX_makeLexStrConDefault(BOX_LexStrCharChars chars);
BOX_StrCon BOX_makeStrConLexToCf(BOX_LexStrCon StrCon);
BOX_LexStrCharChars BOX_makeLexStrCharCharsEmpty(void);
BOX_LexStrCharChars BOX_makeLexStrCharCharsSingle(BOX_LexStrChar head);
BOX_LexStrCharChars BOX_makeLexStrCharCharsMany(BOX_LexStrChar head, BOX_LexStrCharChars tail);
BOX_LexLayout BOX_makeLexLayoutWhitespace(char ch);
BOX_LexLayout BOX_makeLexLayoutLine(const char* line);
BOX_LexLayout BOX_makeLexLayoutNested(const char* content);
BOX_SpaceSymbol BOX_makeSpaceSymbolHorizontal(void);
BOX_SpaceSymbol BOX_makeSpaceSymbolVertical(void);
BOX_SpaceSymbol BOX_makeSpaceSymbolIndentation(void);
BOX_SpaceSymbol BOX_makeSpaceSymbolTabstop(void);
BOX_SpaceOption BOX_makeSpaceOptionDefault(BOX_SpaceSymbol SpaceSymbol, BOX_OptLayout wsAfterSpaceSymbol, BOX_OptLayout wsAfterEquals, BOX_NatCon NatCon);
BOX_SpaceOptionOptions BOX_makeSpaceOptionOptionsEmpty(void);
BOX_SpaceOptionOptions BOX_makeSpaceOptionOptionsSingle(BOX_SpaceOption head);
BOX_SpaceOptionOptions BOX_makeSpaceOptionOptionsMany(BOX_SpaceOption head, BOX_OptLayout wsAfterHead, BOX_SpaceOptionOptions tail);
BOX_AlignmentOption BOX_makeAlignmentOptionLeft(BOX_OptLayout wsAfterL, BOX_SpaceOptionOptions options);
BOX_AlignmentOption BOX_makeAlignmentOptionCentre(BOX_OptLayout wsAfterC, BOX_SpaceOptionOptions options);
BOX_AlignmentOption BOX_makeAlignmentOptionRight(BOX_OptLayout wsAfterR, BOX_SpaceOptionOptions options);
BOX_AlignmentOptions BOX_makeAlignmentOptionsDefault(BOX_OptLayout wsAfterParenOpen, BOX_AlignmentOptionList list, BOX_OptLayout wsAfterList);
BOX_AlignmentOptionList BOX_makeAlignmentOptionListEmpty(void);
BOX_AlignmentOptionList BOX_makeAlignmentOptionListSingle(BOX_AlignmentOption head);
BOX_AlignmentOptionList BOX_makeAlignmentOptionListMany(BOX_AlignmentOption head, BOX_OptLayout wsAfterHead, BOX_OptLayout wsAfterSep, BOX_AlignmentOptionList tail);
BOX_Start BOX_makeStartBox(BOX_OptLayout wsBefore, BOX_Box topBox, BOX_OptLayout wsAfter, int ambCnt);

/*}}}  */
/*{{{  equality functions */

ATbool BOX_isEqualOptLayout(BOX_OptLayout arg0, BOX_OptLayout arg1);
ATbool BOX_isEqualLayout(BOX_Layout arg0, BOX_Layout arg1);
ATbool BOX_isEqualLexLayoutList(BOX_LexLayoutList arg0, BOX_LexLayoutList arg1);
ATbool BOX_isEqualLexFontId(BOX_LexFontId arg0, BOX_LexFontId arg1);
ATbool BOX_isEqualFontId(BOX_FontId arg0, BOX_FontId arg1);
ATbool BOX_isEqualFontValue(BOX_FontValue arg0, BOX_FontValue arg1);
ATbool BOX_isEqualFontOption(BOX_FontOption arg0, BOX_FontOption arg1);
ATbool BOX_isEqualFontOperator(BOX_FontOperator arg0, BOX_FontOperator arg1);
ATbool BOX_isEqualBox(BOX_Box arg0, BOX_Box arg1);
ATbool BOX_isEqualFontParam(BOX_FontParam arg0, BOX_FontParam arg1);
ATbool BOX_isEqualFontOptionList(BOX_FontOptionList arg0, BOX_FontOptionList arg1);
ATbool BOX_isEqualBoxList(BOX_BoxList arg0, BOX_BoxList arg1);
ATbool BOX_isEqualLexNatCon(BOX_LexNatCon arg0, BOX_LexNatCon arg1);
ATbool BOX_isEqualNatCon(BOX_NatCon arg0, BOX_NatCon arg1);
ATbool BOX_isEqualLexStrChar(BOX_LexStrChar arg0, BOX_LexStrChar arg1);
ATbool BOX_isEqualStrChar(BOX_StrChar arg0, BOX_StrChar arg1);
ATbool BOX_isEqualLexStrCon(BOX_LexStrCon arg0, BOX_LexStrCon arg1);
ATbool BOX_isEqualStrCon(BOX_StrCon arg0, BOX_StrCon arg1);
ATbool BOX_isEqualLexStrCharChars(BOX_LexStrCharChars arg0, BOX_LexStrCharChars arg1);
ATbool BOX_isEqualLexLayout(BOX_LexLayout arg0, BOX_LexLayout arg1);
ATbool BOX_isEqualSpaceSymbol(BOX_SpaceSymbol arg0, BOX_SpaceSymbol arg1);
ATbool BOX_isEqualSpaceOption(BOX_SpaceOption arg0, BOX_SpaceOption arg1);
ATbool BOX_isEqualSpaceOptionOptions(BOX_SpaceOptionOptions arg0, BOX_SpaceOptionOptions arg1);
ATbool BOX_isEqualAlignmentOption(BOX_AlignmentOption arg0, BOX_AlignmentOption arg1);
ATbool BOX_isEqualAlignmentOptions(BOX_AlignmentOptions arg0, BOX_AlignmentOptions arg1);
ATbool BOX_isEqualAlignmentOptionList(BOX_AlignmentOptionList arg0, BOX_AlignmentOptionList arg1);
ATbool BOX_isEqualStart(BOX_Start arg0, BOX_Start arg1);

/*}}}  */
/*{{{  BOX_OptLayout accessors */

ATbool BOX_isValidOptLayout(BOX_OptLayout arg);
inline ATbool BOX_isOptLayoutAbsent(BOX_OptLayout arg);
inline ATbool BOX_isOptLayoutPresent(BOX_OptLayout arg);
ATbool BOX_hasOptLayoutLayout(BOX_OptLayout arg);
BOX_Layout BOX_getOptLayoutLayout(BOX_OptLayout arg);
BOX_OptLayout BOX_setOptLayoutLayout(BOX_OptLayout arg, BOX_Layout layout);

/*}}}  */
/*{{{  BOX_Layout accessors */

ATbool BOX_isValidLayout(BOX_Layout arg);
inline ATbool BOX_isLayoutLexToCf(BOX_Layout arg);
ATbool BOX_hasLayoutList(BOX_Layout arg);
BOX_LexLayoutList BOX_getLayoutList(BOX_Layout arg);
BOX_Layout BOX_setLayoutList(BOX_Layout arg, BOX_LexLayoutList list);

/*}}}  */
/*{{{  BOX_LexLayoutList accessors */

ATbool BOX_isValidLexLayoutList(BOX_LexLayoutList arg);
inline ATbool BOX_isLexLayoutListEmpty(BOX_LexLayoutList arg);
inline ATbool BOX_isLexLayoutListSingle(BOX_LexLayoutList arg);
inline ATbool BOX_isLexLayoutListMany(BOX_LexLayoutList arg);
ATbool BOX_hasLexLayoutListHead(BOX_LexLayoutList arg);
ATbool BOX_hasLexLayoutListTail(BOX_LexLayoutList arg);
BOX_LexLayout BOX_getLexLayoutListHead(BOX_LexLayoutList arg);
BOX_LexLayoutList BOX_getLexLayoutListTail(BOX_LexLayoutList arg);
BOX_LexLayoutList BOX_setLexLayoutListHead(BOX_LexLayoutList arg, BOX_LexLayout head);
BOX_LexLayoutList BOX_setLexLayoutListTail(BOX_LexLayoutList arg, BOX_LexLayoutList tail);

/*}}}  */
/*{{{  BOX_LexFontId accessors */

ATbool BOX_isValidLexFontId(BOX_LexFontId arg);
inline ATbool BOX_isLexFontIdDefault(BOX_LexFontId arg);
ATbool BOX_hasLexFontIdList(BOX_LexFontId arg);
char* BOX_getLexFontIdList(BOX_LexFontId arg);
BOX_LexFontId BOX_setLexFontIdList(BOX_LexFontId arg, const char* list);

/*}}}  */
/*{{{  BOX_FontId accessors */

ATbool BOX_isValidFontId(BOX_FontId arg);
inline ATbool BOX_isFontIdLexToCf(BOX_FontId arg);
ATbool BOX_hasFontIdFontId(BOX_FontId arg);
BOX_LexFontId BOX_getFontIdFontId(BOX_FontId arg);
BOX_FontId BOX_setFontIdFontId(BOX_FontId arg, BOX_LexFontId FontId);

/*}}}  */
/*{{{  BOX_FontValue accessors */

ATbool BOX_isValidFontValue(BOX_FontValue arg);
inline ATbool BOX_isFontValueNatural(BOX_FontValue arg);
inline ATbool BOX_isFontValueFontId(BOX_FontValue arg);
ATbool BOX_hasFontValueNatCon(BOX_FontValue arg);
ATbool BOX_hasFontValueFontId(BOX_FontValue arg);
BOX_NatCon BOX_getFontValueNatCon(BOX_FontValue arg);
BOX_FontId BOX_getFontValueFontId(BOX_FontValue arg);
BOX_FontValue BOX_setFontValueNatCon(BOX_FontValue arg, BOX_NatCon NatCon);
BOX_FontValue BOX_setFontValueFontId(BOX_FontValue arg, BOX_FontId FontId);

/*}}}  */
/*{{{  BOX_FontOption accessors */

ATbool BOX_isValidFontOption(BOX_FontOption arg);
inline ATbool BOX_isFontOptionDefault(BOX_FontOption arg);
ATbool BOX_hasFontOptionFontParam(BOX_FontOption arg);
ATbool BOX_hasFontOptionWsAfterFontParam(BOX_FontOption arg);
ATbool BOX_hasFontOptionWsAfterEquals(BOX_FontOption arg);
ATbool BOX_hasFontOptionFontValue(BOX_FontOption arg);
BOX_FontParam BOX_getFontOptionFontParam(BOX_FontOption arg);
BOX_OptLayout BOX_getFontOptionWsAfterFontParam(BOX_FontOption arg);
BOX_OptLayout BOX_getFontOptionWsAfterEquals(BOX_FontOption arg);
BOX_FontValue BOX_getFontOptionFontValue(BOX_FontOption arg);
BOX_FontOption BOX_setFontOptionFontParam(BOX_FontOption arg, BOX_FontParam FontParam);
BOX_FontOption BOX_setFontOptionWsAfterFontParam(BOX_FontOption arg, BOX_OptLayout wsAfterFontParam);
BOX_FontOption BOX_setFontOptionWsAfterEquals(BOX_FontOption arg, BOX_OptLayout wsAfterEquals);
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
ATbool BOX_hasFontOperatorList(BOX_FontOperator arg);
BOX_OptLayout BOX_getFontOperatorWsAfterF(BOX_FontOperator arg);
BOX_FontOptionList BOX_getFontOperatorList(BOX_FontOperator arg);
BOX_FontOperator BOX_setFontOperatorWsAfterF(BOX_FontOperator arg, BOX_OptLayout wsAfterF);
BOX_FontOperator BOX_setFontOperatorList(BOX_FontOperator arg, BOX_FontOptionList list);

/*}}}  */
/*{{{  BOX_Box accessors */

ATbool BOX_isValidBox(BOX_Box arg);
inline ATbool BOX_isBoxFontOperator(BOX_Box arg);
inline ATbool BOX_isBoxDefault(BOX_Box arg);
inline ATbool BOX_isBoxString(BOX_Box arg);
inline ATbool BOX_isBoxH(BOX_Box arg);
inline ATbool BOX_isBoxV(BOX_Box arg);
inline ATbool BOX_isBoxHv(BOX_Box arg);
inline ATbool BOX_isBoxHov(BOX_Box arg);
inline ATbool BOX_isBoxI(BOX_Box arg);
inline ATbool BOX_isBoxWd(BOX_Box arg);
inline ATbool BOX_isBoxAlignment(BOX_Box arg);
inline ATbool BOX_isBoxRow(BOX_Box arg);
ATbool BOX_hasBoxFontOperator(BOX_Box arg);
ATbool BOX_hasBoxWsAfterFontOperator(BOX_Box arg);
ATbool BOX_hasBoxWsAfterBracketOpen(BOX_Box arg);
ATbool BOX_hasBoxBox(BOX_Box arg);
ATbool BOX_hasBoxWsAfterBox(BOX_Box arg);
ATbool BOX_hasBoxWsAfterCOMM(BOX_Box arg);
ATbool BOX_hasBoxList(BOX_Box arg);
ATbool BOX_hasBoxWsAfterList(BOX_Box arg);
ATbool BOX_hasBoxStrCon(BOX_Box arg);
ATbool BOX_hasBoxWsAfterH(BOX_Box arg);
ATbool BOX_hasBoxOptions(BOX_Box arg);
ATbool BOX_hasBoxWsAfterOptions(BOX_Box arg);
ATbool BOX_hasBoxWsAfterV(BOX_Box arg);
ATbool BOX_hasBoxWsAfterHV(BOX_Box arg);
ATbool BOX_hasBoxWsAfterHOV(BOX_Box arg);
ATbool BOX_hasBoxWsAfterI(BOX_Box arg);
ATbool BOX_hasBoxWsAfterWD(BOX_Box arg);
ATbool BOX_hasBoxWsAfterA(BOX_Box arg);
ATbool BOX_hasBoxAlignments(BOX_Box arg);
ATbool BOX_hasBoxWsAfterAlignments(BOX_Box arg);
ATbool BOX_hasBoxWsAfterR(BOX_Box arg);
BOX_FontOperator BOX_getBoxFontOperator(BOX_Box arg);
BOX_OptLayout BOX_getBoxWsAfterFontOperator(BOX_Box arg);
BOX_OptLayout BOX_getBoxWsAfterBracketOpen(BOX_Box arg);
BOX_Box BOX_getBoxBox(BOX_Box arg);
BOX_OptLayout BOX_getBoxWsAfterBox(BOX_Box arg);
BOX_OptLayout BOX_getBoxWsAfterCOMM(BOX_Box arg);
BOX_BoxList BOX_getBoxList(BOX_Box arg);
BOX_OptLayout BOX_getBoxWsAfterList(BOX_Box arg);
BOX_StrCon BOX_getBoxStrCon(BOX_Box arg);
BOX_OptLayout BOX_getBoxWsAfterH(BOX_Box arg);
BOX_SpaceOptionOptions BOX_getBoxOptions(BOX_Box arg);
BOX_OptLayout BOX_getBoxWsAfterOptions(BOX_Box arg);
BOX_OptLayout BOX_getBoxWsAfterV(BOX_Box arg);
BOX_OptLayout BOX_getBoxWsAfterHV(BOX_Box arg);
BOX_OptLayout BOX_getBoxWsAfterHOV(BOX_Box arg);
BOX_OptLayout BOX_getBoxWsAfterI(BOX_Box arg);
BOX_OptLayout BOX_getBoxWsAfterWD(BOX_Box arg);
BOX_OptLayout BOX_getBoxWsAfterA(BOX_Box arg);
BOX_AlignmentOptions BOX_getBoxAlignments(BOX_Box arg);
BOX_OptLayout BOX_getBoxWsAfterAlignments(BOX_Box arg);
BOX_OptLayout BOX_getBoxWsAfterR(BOX_Box arg);
BOX_Box BOX_setBoxFontOperator(BOX_Box arg, BOX_FontOperator FontOperator);
BOX_Box BOX_setBoxWsAfterFontOperator(BOX_Box arg, BOX_OptLayout wsAfterFontOperator);
BOX_Box BOX_setBoxWsAfterBracketOpen(BOX_Box arg, BOX_OptLayout wsAfterBracketOpen);
BOX_Box BOX_setBoxBox(BOX_Box arg, BOX_Box Box);
BOX_Box BOX_setBoxWsAfterBox(BOX_Box arg, BOX_OptLayout wsAfterBox);
BOX_Box BOX_setBoxWsAfterCOMM(BOX_Box arg, BOX_OptLayout wsAfterCOMM);
BOX_Box BOX_setBoxList(BOX_Box arg, BOX_BoxList list);
BOX_Box BOX_setBoxWsAfterList(BOX_Box arg, BOX_OptLayout wsAfterList);
BOX_Box BOX_setBoxStrCon(BOX_Box arg, BOX_StrCon StrCon);
BOX_Box BOX_setBoxWsAfterH(BOX_Box arg, BOX_OptLayout wsAfterH);
BOX_Box BOX_setBoxOptions(BOX_Box arg, BOX_SpaceOptionOptions options);
BOX_Box BOX_setBoxWsAfterOptions(BOX_Box arg, BOX_OptLayout wsAfterOptions);
BOX_Box BOX_setBoxWsAfterV(BOX_Box arg, BOX_OptLayout wsAfterV);
BOX_Box BOX_setBoxWsAfterHV(BOX_Box arg, BOX_OptLayout wsAfterHV);
BOX_Box BOX_setBoxWsAfterHOV(BOX_Box arg, BOX_OptLayout wsAfterHOV);
BOX_Box BOX_setBoxWsAfterI(BOX_Box arg, BOX_OptLayout wsAfterI);
BOX_Box BOX_setBoxWsAfterWD(BOX_Box arg, BOX_OptLayout wsAfterWD);
BOX_Box BOX_setBoxWsAfterA(BOX_Box arg, BOX_OptLayout wsAfterA);
BOX_Box BOX_setBoxAlignments(BOX_Box arg, BOX_AlignmentOptions alignments);
BOX_Box BOX_setBoxWsAfterAlignments(BOX_Box arg, BOX_OptLayout wsAfterAlignments);
BOX_Box BOX_setBoxWsAfterR(BOX_Box arg, BOX_OptLayout wsAfterR);

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
/*{{{  BOX_FontOptionList accessors */

ATbool BOX_isValidFontOptionList(BOX_FontOptionList arg);
inline ATbool BOX_isFontOptionListEmpty(BOX_FontOptionList arg);
inline ATbool BOX_isFontOptionListSingle(BOX_FontOptionList arg);
inline ATbool BOX_isFontOptionListMany(BOX_FontOptionList arg);
ATbool BOX_hasFontOptionListHead(BOX_FontOptionList arg);
ATbool BOX_hasFontOptionListWsAfterHead(BOX_FontOptionList arg);
ATbool BOX_hasFontOptionListTail(BOX_FontOptionList arg);
BOX_FontOptionList BOX_getFontOptionListTail(BOX_FontOptionList arg);
BOX_FontOption BOX_getFontOptionListHead(BOX_FontOptionList arg);
BOX_OptLayout BOX_getFontOptionListWsAfterHead(BOX_FontOptionList arg);
BOX_FontOptionList BOX_setFontOptionListHead(BOX_FontOptionList arg, BOX_FontOption head);
BOX_FontOptionList BOX_setFontOptionListWsAfterHead(BOX_FontOptionList arg, BOX_OptLayout wsAfterHead);
BOX_FontOptionList BOX_setFontOptionListTail(BOX_FontOptionList arg, BOX_FontOptionList tail);

/*}}}  */
/*{{{  BOX_BoxList accessors */

ATbool BOX_isValidBoxList(BOX_BoxList arg);
inline ATbool BOX_isBoxListEmpty(BOX_BoxList arg);
inline ATbool BOX_isBoxListSingle(BOX_BoxList arg);
inline ATbool BOX_isBoxListMany(BOX_BoxList arg);
ATbool BOX_hasBoxListHead(BOX_BoxList arg);
ATbool BOX_hasBoxListWsAfterHead(BOX_BoxList arg);
ATbool BOX_hasBoxListTail(BOX_BoxList arg);
BOX_BoxList BOX_getBoxListTail(BOX_BoxList arg);
BOX_Box BOX_getBoxListHead(BOX_BoxList arg);
BOX_OptLayout BOX_getBoxListWsAfterHead(BOX_BoxList arg);
BOX_BoxList BOX_setBoxListHead(BOX_BoxList arg, BOX_Box head);
BOX_BoxList BOX_setBoxListWsAfterHead(BOX_BoxList arg, BOX_OptLayout wsAfterHead);
BOX_BoxList BOX_setBoxListTail(BOX_BoxList arg, BOX_BoxList tail);

/*}}}  */
/*{{{  BOX_LexNatCon accessors */

ATbool BOX_isValidLexNatCon(BOX_LexNatCon arg);
inline ATbool BOX_isLexNatConDigits(BOX_LexNatCon arg);
ATbool BOX_hasLexNatConList(BOX_LexNatCon arg);
char* BOX_getLexNatConList(BOX_LexNatCon arg);
BOX_LexNatCon BOX_setLexNatConList(BOX_LexNatCon arg, const char* list);

/*}}}  */
/*{{{  BOX_NatCon accessors */

ATbool BOX_isValidNatCon(BOX_NatCon arg);
inline ATbool BOX_isNatConLexToCf(BOX_NatCon arg);
ATbool BOX_hasNatConNatCon(BOX_NatCon arg);
BOX_LexNatCon BOX_getNatConNatCon(BOX_NatCon arg);
BOX_NatCon BOX_setNatConNatCon(BOX_NatCon arg, BOX_LexNatCon NatCon);

/*}}}  */
/*{{{  BOX_LexStrChar accessors */

ATbool BOX_isValidLexStrChar(BOX_LexStrChar arg);
inline ATbool BOX_isLexStrCharNewline(BOX_LexStrChar arg);
inline ATbool BOX_isLexStrCharTab(BOX_LexStrChar arg);
inline ATbool BOX_isLexStrCharQuote(BOX_LexStrChar arg);
inline ATbool BOX_isLexStrCharBackslash(BOX_LexStrChar arg);
inline ATbool BOX_isLexStrCharDecimal(BOX_LexStrChar arg);
inline ATbool BOX_isLexStrCharNormal(BOX_LexStrChar arg);
ATbool BOX_hasLexStrCharA(BOX_LexStrChar arg);
ATbool BOX_hasLexStrCharB(BOX_LexStrChar arg);
ATbool BOX_hasLexStrCharC(BOX_LexStrChar arg);
ATbool BOX_hasLexStrCharCh(BOX_LexStrChar arg);
char BOX_getLexStrCharA(BOX_LexStrChar arg);
char BOX_getLexStrCharB(BOX_LexStrChar arg);
char BOX_getLexStrCharC(BOX_LexStrChar arg);
char BOX_getLexStrCharCh(BOX_LexStrChar arg);
BOX_LexStrChar BOX_setLexStrCharA(BOX_LexStrChar arg, char a);
BOX_LexStrChar BOX_setLexStrCharB(BOX_LexStrChar arg, char b);
BOX_LexStrChar BOX_setLexStrCharC(BOX_LexStrChar arg, char c);
BOX_LexStrChar BOX_setLexStrCharCh(BOX_LexStrChar arg, char ch);

/*}}}  */
/*{{{  BOX_StrChar accessors */

ATbool BOX_isValidStrChar(BOX_StrChar arg);
inline ATbool BOX_isStrCharLexToCf(BOX_StrChar arg);
ATbool BOX_hasStrCharStrChar(BOX_StrChar arg);
BOX_LexStrChar BOX_getStrCharStrChar(BOX_StrChar arg);
BOX_StrChar BOX_setStrCharStrChar(BOX_StrChar arg, BOX_LexStrChar StrChar);

/*}}}  */
/*{{{  BOX_LexStrCon accessors */

ATbool BOX_isValidLexStrCon(BOX_LexStrCon arg);
inline ATbool BOX_isLexStrConDefault(BOX_LexStrCon arg);
ATbool BOX_hasLexStrConChars(BOX_LexStrCon arg);
BOX_LexStrCharChars BOX_getLexStrConChars(BOX_LexStrCon arg);
BOX_LexStrCon BOX_setLexStrConChars(BOX_LexStrCon arg, BOX_LexStrCharChars chars);

/*}}}  */
/*{{{  BOX_StrCon accessors */

ATbool BOX_isValidStrCon(BOX_StrCon arg);
inline ATbool BOX_isStrConLexToCf(BOX_StrCon arg);
ATbool BOX_hasStrConStrCon(BOX_StrCon arg);
BOX_LexStrCon BOX_getStrConStrCon(BOX_StrCon arg);
BOX_StrCon BOX_setStrConStrCon(BOX_StrCon arg, BOX_LexStrCon StrCon);

/*}}}  */
/*{{{  BOX_LexStrCharChars accessors */

ATbool BOX_isValidLexStrCharChars(BOX_LexStrCharChars arg);
inline ATbool BOX_isLexStrCharCharsEmpty(BOX_LexStrCharChars arg);
inline ATbool BOX_isLexStrCharCharsSingle(BOX_LexStrCharChars arg);
inline ATbool BOX_isLexStrCharCharsMany(BOX_LexStrCharChars arg);
ATbool BOX_hasLexStrCharCharsHead(BOX_LexStrCharChars arg);
ATbool BOX_hasLexStrCharCharsTail(BOX_LexStrCharChars arg);
BOX_LexStrChar BOX_getLexStrCharCharsHead(BOX_LexStrCharChars arg);
BOX_LexStrCharChars BOX_getLexStrCharCharsTail(BOX_LexStrCharChars arg);
BOX_LexStrCharChars BOX_setLexStrCharCharsHead(BOX_LexStrCharChars arg, BOX_LexStrChar head);
BOX_LexStrCharChars BOX_setLexStrCharCharsTail(BOX_LexStrCharChars arg, BOX_LexStrCharChars tail);

/*}}}  */
/*{{{  BOX_LexLayout accessors */

ATbool BOX_isValidLexLayout(BOX_LexLayout arg);
inline ATbool BOX_isLexLayoutWhitespace(BOX_LexLayout arg);
inline ATbool BOX_isLexLayoutLine(BOX_LexLayout arg);
inline ATbool BOX_isLexLayoutNested(BOX_LexLayout arg);
ATbool BOX_hasLexLayoutCh(BOX_LexLayout arg);
ATbool BOX_hasLexLayoutLine(BOX_LexLayout arg);
ATbool BOX_hasLexLayoutContent(BOX_LexLayout arg);
char BOX_getLexLayoutCh(BOX_LexLayout arg);
char* BOX_getLexLayoutLine(BOX_LexLayout arg);
char* BOX_getLexLayoutContent(BOX_LexLayout arg);
BOX_LexLayout BOX_setLexLayoutCh(BOX_LexLayout arg, char ch);
BOX_LexLayout BOX_setLexLayoutLine(BOX_LexLayout arg, const char* line);
BOX_LexLayout BOX_setLexLayoutContent(BOX_LexLayout arg, const char* content);

/*}}}  */
/*{{{  BOX_SpaceSymbol accessors */

ATbool BOX_isValidSpaceSymbol(BOX_SpaceSymbol arg);
inline ATbool BOX_isSpaceSymbolHorizontal(BOX_SpaceSymbol arg);
inline ATbool BOX_isSpaceSymbolVertical(BOX_SpaceSymbol arg);
inline ATbool BOX_isSpaceSymbolIndentation(BOX_SpaceSymbol arg);
inline ATbool BOX_isSpaceSymbolTabstop(BOX_SpaceSymbol arg);

/*}}}  */
/*{{{  BOX_SpaceOption accessors */

ATbool BOX_isValidSpaceOption(BOX_SpaceOption arg);
inline ATbool BOX_isSpaceOptionDefault(BOX_SpaceOption arg);
ATbool BOX_hasSpaceOptionSpaceSymbol(BOX_SpaceOption arg);
ATbool BOX_hasSpaceOptionWsAfterSpaceSymbol(BOX_SpaceOption arg);
ATbool BOX_hasSpaceOptionWsAfterEquals(BOX_SpaceOption arg);
ATbool BOX_hasSpaceOptionNatCon(BOX_SpaceOption arg);
BOX_SpaceSymbol BOX_getSpaceOptionSpaceSymbol(BOX_SpaceOption arg);
BOX_OptLayout BOX_getSpaceOptionWsAfterSpaceSymbol(BOX_SpaceOption arg);
BOX_OptLayout BOX_getSpaceOptionWsAfterEquals(BOX_SpaceOption arg);
BOX_NatCon BOX_getSpaceOptionNatCon(BOX_SpaceOption arg);
BOX_SpaceOption BOX_setSpaceOptionSpaceSymbol(BOX_SpaceOption arg, BOX_SpaceSymbol SpaceSymbol);
BOX_SpaceOption BOX_setSpaceOptionWsAfterSpaceSymbol(BOX_SpaceOption arg, BOX_OptLayout wsAfterSpaceSymbol);
BOX_SpaceOption BOX_setSpaceOptionWsAfterEquals(BOX_SpaceOption arg, BOX_OptLayout wsAfterEquals);
BOX_SpaceOption BOX_setSpaceOptionNatCon(BOX_SpaceOption arg, BOX_NatCon NatCon);

/*}}}  */
/*{{{  BOX_SpaceOptionOptions accessors */

ATbool BOX_isValidSpaceOptionOptions(BOX_SpaceOptionOptions arg);
inline ATbool BOX_isSpaceOptionOptionsEmpty(BOX_SpaceOptionOptions arg);
inline ATbool BOX_isSpaceOptionOptionsSingle(BOX_SpaceOptionOptions arg);
inline ATbool BOX_isSpaceOptionOptionsMany(BOX_SpaceOptionOptions arg);
ATbool BOX_hasSpaceOptionOptionsHead(BOX_SpaceOptionOptions arg);
ATbool BOX_hasSpaceOptionOptionsWsAfterHead(BOX_SpaceOptionOptions arg);
ATbool BOX_hasSpaceOptionOptionsTail(BOX_SpaceOptionOptions arg);
BOX_SpaceOptionOptions BOX_getSpaceOptionOptionsTail(BOX_SpaceOptionOptions arg);
BOX_SpaceOption BOX_getSpaceOptionOptionsHead(BOX_SpaceOptionOptions arg);
BOX_OptLayout BOX_getSpaceOptionOptionsWsAfterHead(BOX_SpaceOptionOptions arg);
BOX_SpaceOptionOptions BOX_setSpaceOptionOptionsHead(BOX_SpaceOptionOptions arg, BOX_SpaceOption head);
BOX_SpaceOptionOptions BOX_setSpaceOptionOptionsWsAfterHead(BOX_SpaceOptionOptions arg, BOX_OptLayout wsAfterHead);
BOX_SpaceOptionOptions BOX_setSpaceOptionOptionsTail(BOX_SpaceOptionOptions arg, BOX_SpaceOptionOptions tail);

/*}}}  */
/*{{{  BOX_AlignmentOption accessors */

ATbool BOX_isValidAlignmentOption(BOX_AlignmentOption arg);
inline ATbool BOX_isAlignmentOptionLeft(BOX_AlignmentOption arg);
inline ATbool BOX_isAlignmentOptionCentre(BOX_AlignmentOption arg);
inline ATbool BOX_isAlignmentOptionRight(BOX_AlignmentOption arg);
ATbool BOX_hasAlignmentOptionWsAfterL(BOX_AlignmentOption arg);
ATbool BOX_hasAlignmentOptionOptions(BOX_AlignmentOption arg);
ATbool BOX_hasAlignmentOptionWsAfterC(BOX_AlignmentOption arg);
ATbool BOX_hasAlignmentOptionWsAfterR(BOX_AlignmentOption arg);
BOX_OptLayout BOX_getAlignmentOptionWsAfterL(BOX_AlignmentOption arg);
BOX_SpaceOptionOptions BOX_getAlignmentOptionOptions(BOX_AlignmentOption arg);
BOX_OptLayout BOX_getAlignmentOptionWsAfterC(BOX_AlignmentOption arg);
BOX_OptLayout BOX_getAlignmentOptionWsAfterR(BOX_AlignmentOption arg);
BOX_AlignmentOption BOX_setAlignmentOptionWsAfterL(BOX_AlignmentOption arg, BOX_OptLayout wsAfterL);
BOX_AlignmentOption BOX_setAlignmentOptionOptions(BOX_AlignmentOption arg, BOX_SpaceOptionOptions options);
BOX_AlignmentOption BOX_setAlignmentOptionWsAfterC(BOX_AlignmentOption arg, BOX_OptLayout wsAfterC);
BOX_AlignmentOption BOX_setAlignmentOptionWsAfterR(BOX_AlignmentOption arg, BOX_OptLayout wsAfterR);

/*}}}  */
/*{{{  BOX_AlignmentOptions accessors */

ATbool BOX_isValidAlignmentOptions(BOX_AlignmentOptions arg);
inline ATbool BOX_isAlignmentOptionsDefault(BOX_AlignmentOptions arg);
ATbool BOX_hasAlignmentOptionsWsAfterParenOpen(BOX_AlignmentOptions arg);
ATbool BOX_hasAlignmentOptionsList(BOX_AlignmentOptions arg);
ATbool BOX_hasAlignmentOptionsWsAfterList(BOX_AlignmentOptions arg);
BOX_OptLayout BOX_getAlignmentOptionsWsAfterParenOpen(BOX_AlignmentOptions arg);
BOX_AlignmentOptionList BOX_getAlignmentOptionsList(BOX_AlignmentOptions arg);
BOX_OptLayout BOX_getAlignmentOptionsWsAfterList(BOX_AlignmentOptions arg);
BOX_AlignmentOptions BOX_setAlignmentOptionsWsAfterParenOpen(BOX_AlignmentOptions arg, BOX_OptLayout wsAfterParenOpen);
BOX_AlignmentOptions BOX_setAlignmentOptionsList(BOX_AlignmentOptions arg, BOX_AlignmentOptionList list);
BOX_AlignmentOptions BOX_setAlignmentOptionsWsAfterList(BOX_AlignmentOptions arg, BOX_OptLayout wsAfterList);

/*}}}  */
/*{{{  BOX_AlignmentOptionList accessors */

ATbool BOX_isValidAlignmentOptionList(BOX_AlignmentOptionList arg);
inline ATbool BOX_isAlignmentOptionListEmpty(BOX_AlignmentOptionList arg);
inline ATbool BOX_isAlignmentOptionListSingle(BOX_AlignmentOptionList arg);
inline ATbool BOX_isAlignmentOptionListMany(BOX_AlignmentOptionList arg);
ATbool BOX_hasAlignmentOptionListHead(BOX_AlignmentOptionList arg);
ATbool BOX_hasAlignmentOptionListWsAfterHead(BOX_AlignmentOptionList arg);
ATbool BOX_hasAlignmentOptionListWsAfterSep(BOX_AlignmentOptionList arg);
ATbool BOX_hasAlignmentOptionListTail(BOX_AlignmentOptionList arg);
BOX_AlignmentOptionList BOX_getAlignmentOptionListTail(BOX_AlignmentOptionList arg);
BOX_AlignmentOption BOX_getAlignmentOptionListHead(BOX_AlignmentOptionList arg);
BOX_OptLayout BOX_getAlignmentOptionListWsAfterHead(BOX_AlignmentOptionList arg);
BOX_OptLayout BOX_getAlignmentOptionListWsAfterSep(BOX_AlignmentOptionList arg);
BOX_AlignmentOptionList BOX_setAlignmentOptionListHead(BOX_AlignmentOptionList arg, BOX_AlignmentOption head);
BOX_AlignmentOptionList BOX_setAlignmentOptionListWsAfterHead(BOX_AlignmentOptionList arg, BOX_OptLayout wsAfterHead);
BOX_AlignmentOptionList BOX_setAlignmentOptionListWsAfterSep(BOX_AlignmentOptionList arg, BOX_OptLayout wsAfterSep);
BOX_AlignmentOptionList BOX_setAlignmentOptionListTail(BOX_AlignmentOptionList arg, BOX_AlignmentOptionList tail);

/*}}}  */
/*{{{  BOX_Start accessors */

ATbool BOX_isValidStart(BOX_Start arg);
inline ATbool BOX_isStartBox(BOX_Start arg);
ATbool BOX_hasStartWsBefore(BOX_Start arg);
ATbool BOX_hasStartTopBox(BOX_Start arg);
ATbool BOX_hasStartWsAfter(BOX_Start arg);
ATbool BOX_hasStartAmbCnt(BOX_Start arg);
BOX_OptLayout BOX_getStartWsBefore(BOX_Start arg);
BOX_Box BOX_getStartTopBox(BOX_Start arg);
BOX_OptLayout BOX_getStartWsAfter(BOX_Start arg);
int BOX_getStartAmbCnt(BOX_Start arg);
BOX_Start BOX_setStartWsBefore(BOX_Start arg, BOX_OptLayout wsBefore);
BOX_Start BOX_setStartTopBox(BOX_Start arg, BOX_Box topBox);
BOX_Start BOX_setStartWsAfter(BOX_Start arg, BOX_OptLayout wsAfter);
BOX_Start BOX_setStartAmbCnt(BOX_Start arg, int ambCnt);

/*}}}  */
/*{{{  sort visitors */

BOX_OptLayout BOX_visitOptLayout(BOX_OptLayout arg, BOX_Layout (*acceptLayout)(BOX_Layout));
BOX_Layout BOX_visitLayout(BOX_Layout arg, BOX_LexLayoutList (*acceptList)(BOX_LexLayoutList));
BOX_LexLayoutList BOX_visitLexLayoutList(BOX_LexLayoutList arg, BOX_LexLayout (*acceptHead)(BOX_LexLayout));
BOX_LexFontId BOX_visitLexFontId(BOX_LexFontId arg, char* (*acceptList)(char*));
BOX_FontId BOX_visitFontId(BOX_FontId arg, BOX_LexFontId (*acceptFontId)(BOX_LexFontId));
BOX_FontValue BOX_visitFontValue(BOX_FontValue arg, BOX_NatCon (*acceptNatCon)(BOX_NatCon), BOX_FontId (*acceptFontId)(BOX_FontId));
BOX_FontOption BOX_visitFontOption(BOX_FontOption arg, BOX_FontParam (*acceptFontParam)(BOX_FontParam), BOX_OptLayout (*acceptWsAfterFontParam)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterEquals)(BOX_OptLayout), BOX_FontValue (*acceptFontValue)(BOX_FontValue));
BOX_FontOperator BOX_visitFontOperator(BOX_FontOperator arg, BOX_OptLayout (*acceptWsAfterF)(BOX_OptLayout), BOX_FontOptionList (*acceptList)(BOX_FontOptionList));
BOX_Box BOX_visitBox(BOX_Box arg, BOX_FontOperator (*acceptFontOperator)(BOX_FontOperator), BOX_OptLayout (*acceptWsAfterFontOperator)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterBracketOpen)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterBox)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterCOMM)(BOX_OptLayout), BOX_BoxList (*acceptList)(BOX_BoxList), BOX_OptLayout (*acceptWsAfterList)(BOX_OptLayout), BOX_StrCon (*acceptStrCon)(BOX_StrCon), BOX_OptLayout (*acceptWsAfterH)(BOX_OptLayout), BOX_SpaceOptionOptions (*acceptOptions)(BOX_SpaceOptionOptions), BOX_OptLayout (*acceptWsAfterOptions)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterV)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterHV)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterHOV)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterI)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterWD)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterA)(BOX_OptLayout), BOX_AlignmentOptions (*acceptAlignments)(BOX_AlignmentOptions), BOX_OptLayout (*acceptWsAfterAlignments)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterR)(BOX_OptLayout));
BOX_FontParam BOX_visitFontParam(BOX_FontParam arg);
BOX_FontOptionList BOX_visitFontOptionList(BOX_FontOptionList arg, BOX_FontOption (*acceptHead)(BOX_FontOption), BOX_OptLayout (*acceptWsAfterHead)(BOX_OptLayout));
BOX_BoxList BOX_visitBoxList(BOX_BoxList arg, BOX_Box (*acceptHead)(BOX_Box), BOX_OptLayout (*acceptWsAfterHead)(BOX_OptLayout));
BOX_LexNatCon BOX_visitLexNatCon(BOX_LexNatCon arg, char* (*acceptList)(char*));
BOX_NatCon BOX_visitNatCon(BOX_NatCon arg, BOX_LexNatCon (*acceptNatCon)(BOX_LexNatCon));
BOX_LexStrChar BOX_visitLexStrChar(BOX_LexStrChar arg, char (*acceptA)(char), char (*acceptB)(char), char (*acceptC)(char), char (*acceptCh)(char));
BOX_StrChar BOX_visitStrChar(BOX_StrChar arg, BOX_LexStrChar (*acceptStrChar)(BOX_LexStrChar));
BOX_LexStrCon BOX_visitLexStrCon(BOX_LexStrCon arg, BOX_LexStrCharChars (*acceptChars)(BOX_LexStrCharChars));
BOX_StrCon BOX_visitStrCon(BOX_StrCon arg, BOX_LexStrCon (*acceptStrCon)(BOX_LexStrCon));
BOX_LexStrCharChars BOX_visitLexStrCharChars(BOX_LexStrCharChars arg, BOX_LexStrChar (*acceptHead)(BOX_LexStrChar));
BOX_LexLayout BOX_visitLexLayout(BOX_LexLayout arg, char (*acceptCh)(char), char* (*acceptLine)(char*), char* (*acceptContent)(char*));
BOX_SpaceSymbol BOX_visitSpaceSymbol(BOX_SpaceSymbol arg);
BOX_SpaceOption BOX_visitSpaceOption(BOX_SpaceOption arg, BOX_SpaceSymbol (*acceptSpaceSymbol)(BOX_SpaceSymbol), BOX_OptLayout (*acceptWsAfterSpaceSymbol)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterEquals)(BOX_OptLayout), BOX_NatCon (*acceptNatCon)(BOX_NatCon));
BOX_SpaceOptionOptions BOX_visitSpaceOptionOptions(BOX_SpaceOptionOptions arg, BOX_SpaceOption (*acceptHead)(BOX_SpaceOption), BOX_OptLayout (*acceptWsAfterHead)(BOX_OptLayout));
BOX_AlignmentOption BOX_visitAlignmentOption(BOX_AlignmentOption arg, BOX_OptLayout (*acceptWsAfterL)(BOX_OptLayout), BOX_SpaceOptionOptions (*acceptOptions)(BOX_SpaceOptionOptions), BOX_OptLayout (*acceptWsAfterC)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterR)(BOX_OptLayout));
BOX_AlignmentOptions BOX_visitAlignmentOptions(BOX_AlignmentOptions arg, BOX_OptLayout (*acceptWsAfterParenOpen)(BOX_OptLayout), BOX_AlignmentOptionList (*acceptList)(BOX_AlignmentOptionList), BOX_OptLayout (*acceptWsAfterList)(BOX_OptLayout));
BOX_AlignmentOptionList BOX_visitAlignmentOptionList(BOX_AlignmentOptionList arg, BOX_AlignmentOption (*acceptHead)(BOX_AlignmentOption), BOX_OptLayout (*acceptWsAfterHead)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterSep)(BOX_OptLayout));
BOX_Start BOX_visitStart(BOX_Start arg, BOX_OptLayout (*acceptWsBefore)(BOX_OptLayout), BOX_Box (*acceptTopBox)(BOX_Box), BOX_OptLayout (*acceptWsAfter)(BOX_OptLayout), int (*acceptAmbCnt)(int));

/*}}}  */

#endif /* _BOX_H */
