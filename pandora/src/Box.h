#ifndef _BOX_H
#define _BOX_H

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "Box_dict.h"

typedef struct _BOX_OptLayout *BOX_OptLayout;
typedef struct _BOX_Layout *BOX_Layout;
typedef struct _BOX_LexLayoutList *BOX_LexLayoutList;
typedef struct _BOX_Start *BOX_Start;
typedef struct _BOX_GroupOption *BOX_GroupOption;
typedef struct _BOX_BoxOperator *BOX_BoxOperator;
typedef struct _BOX_GroupOptionGroupOptions *BOX_GroupOptionGroupOptions;
typedef struct _BOX_LexNatCon *BOX_LexNatCon;
typedef struct _BOX_NatCon *BOX_NatCon;
typedef struct _BOX_AlignmentOption *BOX_AlignmentOption;
typedef struct _BOX_AlignmentOptions *BOX_AlignmentOptions;
typedef struct _BOX_SpaceOptionOptions *BOX_SpaceOptionOptions;
typedef struct _BOX_AlignmentOptionList *BOX_AlignmentOptionList;
typedef struct _BOX_SpaceSymbol *BOX_SpaceSymbol;
typedef struct _BOX_SpaceOption *BOX_SpaceOption;
typedef struct _BOX_Box *BOX_Box;
typedef struct _BOX_BoxList *BOX_BoxList;
typedef struct _BOX_LexLayout *BOX_LexLayout;
typedef struct _BOX_LexFontId *BOX_LexFontId;
typedef struct _BOX_FontId *BOX_FontId;
typedef struct _BOX_FontValue *BOX_FontValue;
typedef struct _BOX_FontOption *BOX_FontOption;
typedef struct _BOX_FontParam *BOX_FontParam;
typedef struct _BOX_FontOperator *BOX_FontOperator;
typedef struct _BOX_FontOptionList *BOX_FontOptionList;
typedef struct _BOX_LexStrChar *BOX_LexStrChar;
typedef struct _BOX_StrChar *BOX_StrChar;
typedef struct _BOX_LexStrCon *BOX_LexStrCon;
typedef struct _BOX_StrCon *BOX_StrCon;
typedef struct _BOX_LexStrCharChars *BOX_LexStrCharChars;

#ifdef FAST_API
#define BOX_initBoxApi() (init_Box_dict())
#else
void _BOX_initBoxApi(void);
#define BOX_initBoxApi() (_BOX_initBoxApi())
#endif

#ifdef FAST_API
#define BOX_protectOptLayout(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _BOX_protectOptLayout(BOX_OptLayout *arg);
#define BOX_protectOptLayout(arg) (_BOX_protectOptLayout(arg))
#endif
#ifdef FAST_API
#define BOX_unprotectOptLayout(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _BOX_unprotectOptLayout(BOX_OptLayout *arg);
#define BOX_unprotectOptLayout(arg) (_BOX_unprotectOptLayout(arg))
#endif
#ifdef FAST_API
#define BOX_protectLayout(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _BOX_protectLayout(BOX_Layout *arg);
#define BOX_protectLayout(arg) (_BOX_protectLayout(arg))
#endif
#ifdef FAST_API
#define BOX_unprotectLayout(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _BOX_unprotectLayout(BOX_Layout *arg);
#define BOX_unprotectLayout(arg) (_BOX_unprotectLayout(arg))
#endif
#ifdef FAST_API
#define BOX_protectLexLayoutList(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _BOX_protectLexLayoutList(BOX_LexLayoutList *arg);
#define BOX_protectLexLayoutList(arg) (_BOX_protectLexLayoutList(arg))
#endif
#ifdef FAST_API
#define BOX_unprotectLexLayoutList(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _BOX_unprotectLexLayoutList(BOX_LexLayoutList *arg);
#define BOX_unprotectLexLayoutList(arg) (_BOX_unprotectLexLayoutList(arg))
#endif
#ifdef FAST_API
#define BOX_protectStart(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _BOX_protectStart(BOX_Start *arg);
#define BOX_protectStart(arg) (_BOX_protectStart(arg))
#endif
#ifdef FAST_API
#define BOX_unprotectStart(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _BOX_unprotectStart(BOX_Start *arg);
#define BOX_unprotectStart(arg) (_BOX_unprotectStart(arg))
#endif
#ifdef FAST_API
#define BOX_protectGroupOption(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _BOX_protectGroupOption(BOX_GroupOption *arg);
#define BOX_protectGroupOption(arg) (_BOX_protectGroupOption(arg))
#endif
#ifdef FAST_API
#define BOX_unprotectGroupOption(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _BOX_unprotectGroupOption(BOX_GroupOption *arg);
#define BOX_unprotectGroupOption(arg) (_BOX_unprotectGroupOption(arg))
#endif
#ifdef FAST_API
#define BOX_protectBoxOperator(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _BOX_protectBoxOperator(BOX_BoxOperator *arg);
#define BOX_protectBoxOperator(arg) (_BOX_protectBoxOperator(arg))
#endif
#ifdef FAST_API
#define BOX_unprotectBoxOperator(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _BOX_unprotectBoxOperator(BOX_BoxOperator *arg);
#define BOX_unprotectBoxOperator(arg) (_BOX_unprotectBoxOperator(arg))
#endif
#ifdef FAST_API
#define BOX_protectGroupOptionGroupOptions(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _BOX_protectGroupOptionGroupOptions(BOX_GroupOptionGroupOptions *arg);
#define BOX_protectGroupOptionGroupOptions(arg) (_BOX_protectGroupOptionGroupOptions(arg))
#endif
#ifdef FAST_API
#define BOX_unprotectGroupOptionGroupOptions(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _BOX_unprotectGroupOptionGroupOptions(BOX_GroupOptionGroupOptions *arg);
#define BOX_unprotectGroupOptionGroupOptions(arg) (_BOX_unprotectGroupOptionGroupOptions(arg))
#endif
#ifdef FAST_API
#define BOX_protectLexNatCon(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _BOX_protectLexNatCon(BOX_LexNatCon *arg);
#define BOX_protectLexNatCon(arg) (_BOX_protectLexNatCon(arg))
#endif
#ifdef FAST_API
#define BOX_unprotectLexNatCon(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _BOX_unprotectLexNatCon(BOX_LexNatCon *arg);
#define BOX_unprotectLexNatCon(arg) (_BOX_unprotectLexNatCon(arg))
#endif
#ifdef FAST_API
#define BOX_protectNatCon(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _BOX_protectNatCon(BOX_NatCon *arg);
#define BOX_protectNatCon(arg) (_BOX_protectNatCon(arg))
#endif
#ifdef FAST_API
#define BOX_unprotectNatCon(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _BOX_unprotectNatCon(BOX_NatCon *arg);
#define BOX_unprotectNatCon(arg) (_BOX_unprotectNatCon(arg))
#endif
#ifdef FAST_API
#define BOX_protectAlignmentOption(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _BOX_protectAlignmentOption(BOX_AlignmentOption *arg);
#define BOX_protectAlignmentOption(arg) (_BOX_protectAlignmentOption(arg))
#endif
#ifdef FAST_API
#define BOX_unprotectAlignmentOption(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _BOX_unprotectAlignmentOption(BOX_AlignmentOption *arg);
#define BOX_unprotectAlignmentOption(arg) (_BOX_unprotectAlignmentOption(arg))
#endif
#ifdef FAST_API
#define BOX_protectAlignmentOptions(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _BOX_protectAlignmentOptions(BOX_AlignmentOptions *arg);
#define BOX_protectAlignmentOptions(arg) (_BOX_protectAlignmentOptions(arg))
#endif
#ifdef FAST_API
#define BOX_unprotectAlignmentOptions(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _BOX_unprotectAlignmentOptions(BOX_AlignmentOptions *arg);
#define BOX_unprotectAlignmentOptions(arg) (_BOX_unprotectAlignmentOptions(arg))
#endif
#ifdef FAST_API
#define BOX_protectSpaceOptionOptions(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _BOX_protectSpaceOptionOptions(BOX_SpaceOptionOptions *arg);
#define BOX_protectSpaceOptionOptions(arg) (_BOX_protectSpaceOptionOptions(arg))
#endif
#ifdef FAST_API
#define BOX_unprotectSpaceOptionOptions(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _BOX_unprotectSpaceOptionOptions(BOX_SpaceOptionOptions *arg);
#define BOX_unprotectSpaceOptionOptions(arg) (_BOX_unprotectSpaceOptionOptions(arg))
#endif
#ifdef FAST_API
#define BOX_protectAlignmentOptionList(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _BOX_protectAlignmentOptionList(BOX_AlignmentOptionList *arg);
#define BOX_protectAlignmentOptionList(arg) (_BOX_protectAlignmentOptionList(arg))
#endif
#ifdef FAST_API
#define BOX_unprotectAlignmentOptionList(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _BOX_unprotectAlignmentOptionList(BOX_AlignmentOptionList *arg);
#define BOX_unprotectAlignmentOptionList(arg) (_BOX_unprotectAlignmentOptionList(arg))
#endif
#ifdef FAST_API
#define BOX_protectSpaceSymbol(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _BOX_protectSpaceSymbol(BOX_SpaceSymbol *arg);
#define BOX_protectSpaceSymbol(arg) (_BOX_protectSpaceSymbol(arg))
#endif
#ifdef FAST_API
#define BOX_unprotectSpaceSymbol(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _BOX_unprotectSpaceSymbol(BOX_SpaceSymbol *arg);
#define BOX_unprotectSpaceSymbol(arg) (_BOX_unprotectSpaceSymbol(arg))
#endif
#ifdef FAST_API
#define BOX_protectSpaceOption(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _BOX_protectSpaceOption(BOX_SpaceOption *arg);
#define BOX_protectSpaceOption(arg) (_BOX_protectSpaceOption(arg))
#endif
#ifdef FAST_API
#define BOX_unprotectSpaceOption(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _BOX_unprotectSpaceOption(BOX_SpaceOption *arg);
#define BOX_unprotectSpaceOption(arg) (_BOX_unprotectSpaceOption(arg))
#endif
#ifdef FAST_API
#define BOX_protectBox(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _BOX_protectBox(BOX_Box *arg);
#define BOX_protectBox(arg) (_BOX_protectBox(arg))
#endif
#ifdef FAST_API
#define BOX_unprotectBox(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _BOX_unprotectBox(BOX_Box *arg);
#define BOX_unprotectBox(arg) (_BOX_unprotectBox(arg))
#endif
#ifdef FAST_API
#define BOX_protectBoxList(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _BOX_protectBoxList(BOX_BoxList *arg);
#define BOX_protectBoxList(arg) (_BOX_protectBoxList(arg))
#endif
#ifdef FAST_API
#define BOX_unprotectBoxList(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _BOX_unprotectBoxList(BOX_BoxList *arg);
#define BOX_unprotectBoxList(arg) (_BOX_unprotectBoxList(arg))
#endif
#ifdef FAST_API
#define BOX_protectLexLayout(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _BOX_protectLexLayout(BOX_LexLayout *arg);
#define BOX_protectLexLayout(arg) (_BOX_protectLexLayout(arg))
#endif
#ifdef FAST_API
#define BOX_unprotectLexLayout(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _BOX_unprotectLexLayout(BOX_LexLayout *arg);
#define BOX_unprotectLexLayout(arg) (_BOX_unprotectLexLayout(arg))
#endif
#ifdef FAST_API
#define BOX_protectLexFontId(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _BOX_protectLexFontId(BOX_LexFontId *arg);
#define BOX_protectLexFontId(arg) (_BOX_protectLexFontId(arg))
#endif
#ifdef FAST_API
#define BOX_unprotectLexFontId(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _BOX_unprotectLexFontId(BOX_LexFontId *arg);
#define BOX_unprotectLexFontId(arg) (_BOX_unprotectLexFontId(arg))
#endif
#ifdef FAST_API
#define BOX_protectFontId(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _BOX_protectFontId(BOX_FontId *arg);
#define BOX_protectFontId(arg) (_BOX_protectFontId(arg))
#endif
#ifdef FAST_API
#define BOX_unprotectFontId(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _BOX_unprotectFontId(BOX_FontId *arg);
#define BOX_unprotectFontId(arg) (_BOX_unprotectFontId(arg))
#endif
#ifdef FAST_API
#define BOX_protectFontValue(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _BOX_protectFontValue(BOX_FontValue *arg);
#define BOX_protectFontValue(arg) (_BOX_protectFontValue(arg))
#endif
#ifdef FAST_API
#define BOX_unprotectFontValue(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _BOX_unprotectFontValue(BOX_FontValue *arg);
#define BOX_unprotectFontValue(arg) (_BOX_unprotectFontValue(arg))
#endif
#ifdef FAST_API
#define BOX_protectFontOption(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _BOX_protectFontOption(BOX_FontOption *arg);
#define BOX_protectFontOption(arg) (_BOX_protectFontOption(arg))
#endif
#ifdef FAST_API
#define BOX_unprotectFontOption(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _BOX_unprotectFontOption(BOX_FontOption *arg);
#define BOX_unprotectFontOption(arg) (_BOX_unprotectFontOption(arg))
#endif
#ifdef FAST_API
#define BOX_protectFontParam(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _BOX_protectFontParam(BOX_FontParam *arg);
#define BOX_protectFontParam(arg) (_BOX_protectFontParam(arg))
#endif
#ifdef FAST_API
#define BOX_unprotectFontParam(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _BOX_unprotectFontParam(BOX_FontParam *arg);
#define BOX_unprotectFontParam(arg) (_BOX_unprotectFontParam(arg))
#endif
#ifdef FAST_API
#define BOX_protectFontOperator(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _BOX_protectFontOperator(BOX_FontOperator *arg);
#define BOX_protectFontOperator(arg) (_BOX_protectFontOperator(arg))
#endif
#ifdef FAST_API
#define BOX_unprotectFontOperator(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _BOX_unprotectFontOperator(BOX_FontOperator *arg);
#define BOX_unprotectFontOperator(arg) (_BOX_unprotectFontOperator(arg))
#endif
#ifdef FAST_API
#define BOX_protectFontOptionList(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _BOX_protectFontOptionList(BOX_FontOptionList *arg);
#define BOX_protectFontOptionList(arg) (_BOX_protectFontOptionList(arg))
#endif
#ifdef FAST_API
#define BOX_unprotectFontOptionList(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _BOX_unprotectFontOptionList(BOX_FontOptionList *arg);
#define BOX_unprotectFontOptionList(arg) (_BOX_unprotectFontOptionList(arg))
#endif
#ifdef FAST_API
#define BOX_protectLexStrChar(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _BOX_protectLexStrChar(BOX_LexStrChar *arg);
#define BOX_protectLexStrChar(arg) (_BOX_protectLexStrChar(arg))
#endif
#ifdef FAST_API
#define BOX_unprotectLexStrChar(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _BOX_unprotectLexStrChar(BOX_LexStrChar *arg);
#define BOX_unprotectLexStrChar(arg) (_BOX_unprotectLexStrChar(arg))
#endif
#ifdef FAST_API
#define BOX_protectStrChar(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _BOX_protectStrChar(BOX_StrChar *arg);
#define BOX_protectStrChar(arg) (_BOX_protectStrChar(arg))
#endif
#ifdef FAST_API
#define BOX_unprotectStrChar(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _BOX_unprotectStrChar(BOX_StrChar *arg);
#define BOX_unprotectStrChar(arg) (_BOX_unprotectStrChar(arg))
#endif
#ifdef FAST_API
#define BOX_protectLexStrCon(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _BOX_protectLexStrCon(BOX_LexStrCon *arg);
#define BOX_protectLexStrCon(arg) (_BOX_protectLexStrCon(arg))
#endif
#ifdef FAST_API
#define BOX_unprotectLexStrCon(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _BOX_unprotectLexStrCon(BOX_LexStrCon *arg);
#define BOX_unprotectLexStrCon(arg) (_BOX_unprotectLexStrCon(arg))
#endif
#ifdef FAST_API
#define BOX_protectStrCon(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _BOX_protectStrCon(BOX_StrCon *arg);
#define BOX_protectStrCon(arg) (_BOX_protectStrCon(arg))
#endif
#ifdef FAST_API
#define BOX_unprotectStrCon(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _BOX_unprotectStrCon(BOX_StrCon *arg);
#define BOX_unprotectStrCon(arg) (_BOX_unprotectStrCon(arg))
#endif
#ifdef FAST_API
#define BOX_protectLexStrCharChars(arg) (ATprotect((ATerm*)((void*) (arg))))
#else
void _BOX_protectLexStrCharChars(BOX_LexStrCharChars *arg);
#define BOX_protectLexStrCharChars(arg) (_BOX_protectLexStrCharChars(arg))
#endif
#ifdef FAST_API
#define BOX_unprotectLexStrCharChars(arg) (ATunprotect((ATerm*)((void*) (arg))))
#else
void _BOX_unprotectLexStrCharChars(BOX_LexStrCharChars *arg);
#define BOX_unprotectLexStrCharChars(arg) (_BOX_unprotectLexStrCharChars(arg))
#endif
#ifdef FAST_API
#define BOX_OptLayoutFromTerm(t) ((BOX_OptLayout)(t))
#else
BOX_OptLayout _BOX_OptLayoutFromTerm(ATerm t);
#define BOX_OptLayoutFromTerm(t) (_BOX_OptLayoutFromTerm(t))
#endif
#ifdef FAST_API
#define BOX_OptLayoutToTerm(arg) ((ATerm)(arg))
#else
ATerm _BOX_OptLayoutToTerm(BOX_OptLayout arg);
#define BOX_OptLayoutToTerm(arg) (_BOX_OptLayoutToTerm(arg))
#endif
#ifdef FAST_API
#define BOX_LayoutFromTerm(t) ((BOX_Layout)(t))
#else
BOX_Layout _BOX_LayoutFromTerm(ATerm t);
#define BOX_LayoutFromTerm(t) (_BOX_LayoutFromTerm(t))
#endif
#ifdef FAST_API
#define BOX_LayoutToTerm(arg) ((ATerm)(arg))
#else
ATerm _BOX_LayoutToTerm(BOX_Layout arg);
#define BOX_LayoutToTerm(arg) (_BOX_LayoutToTerm(arg))
#endif
#ifdef FAST_API
#define BOX_LexLayoutListFromTerm(t) ((BOX_LexLayoutList)(t))
#else
BOX_LexLayoutList _BOX_LexLayoutListFromTerm(ATerm t);
#define BOX_LexLayoutListFromTerm(t) (_BOX_LexLayoutListFromTerm(t))
#endif
#ifdef FAST_API
#define BOX_LexLayoutListToTerm(arg) ((ATerm)(arg))
#else
ATerm _BOX_LexLayoutListToTerm(BOX_LexLayoutList arg);
#define BOX_LexLayoutListToTerm(arg) (_BOX_LexLayoutListToTerm(arg))
#endif
#ifdef FAST_API
#define BOX_StartFromTerm(t) ((BOX_Start)(t))
#else
BOX_Start _BOX_StartFromTerm(ATerm t);
#define BOX_StartFromTerm(t) (_BOX_StartFromTerm(t))
#endif
#ifdef FAST_API
#define BOX_StartToTerm(arg) ((ATerm)(arg))
#else
ATerm _BOX_StartToTerm(BOX_Start arg);
#define BOX_StartToTerm(arg) (_BOX_StartToTerm(arg))
#endif
#ifdef FAST_API
#define BOX_GroupOptionFromTerm(t) ((BOX_GroupOption)(t))
#else
BOX_GroupOption _BOX_GroupOptionFromTerm(ATerm t);
#define BOX_GroupOptionFromTerm(t) (_BOX_GroupOptionFromTerm(t))
#endif
#ifdef FAST_API
#define BOX_GroupOptionToTerm(arg) ((ATerm)(arg))
#else
ATerm _BOX_GroupOptionToTerm(BOX_GroupOption arg);
#define BOX_GroupOptionToTerm(arg) (_BOX_GroupOptionToTerm(arg))
#endif
#ifdef FAST_API
#define BOX_BoxOperatorFromTerm(t) ((BOX_BoxOperator)(t))
#else
BOX_BoxOperator _BOX_BoxOperatorFromTerm(ATerm t);
#define BOX_BoxOperatorFromTerm(t) (_BOX_BoxOperatorFromTerm(t))
#endif
#ifdef FAST_API
#define BOX_BoxOperatorToTerm(arg) ((ATerm)(arg))
#else
ATerm _BOX_BoxOperatorToTerm(BOX_BoxOperator arg);
#define BOX_BoxOperatorToTerm(arg) (_BOX_BoxOperatorToTerm(arg))
#endif
#ifdef FAST_API
#define BOX_GroupOptionGroupOptionsFromTerm(t) ((BOX_GroupOptionGroupOptions)(t))
#else
BOX_GroupOptionGroupOptions _BOX_GroupOptionGroupOptionsFromTerm(ATerm t);
#define BOX_GroupOptionGroupOptionsFromTerm(t) (_BOX_GroupOptionGroupOptionsFromTerm(t))
#endif
#ifdef FAST_API
#define BOX_GroupOptionGroupOptionsToTerm(arg) ((ATerm)(arg))
#else
ATerm _BOX_GroupOptionGroupOptionsToTerm(BOX_GroupOptionGroupOptions arg);
#define BOX_GroupOptionGroupOptionsToTerm(arg) (_BOX_GroupOptionGroupOptionsToTerm(arg))
#endif
#ifdef FAST_API
#define BOX_LexNatConFromTerm(t) ((BOX_LexNatCon)(t))
#else
BOX_LexNatCon _BOX_LexNatConFromTerm(ATerm t);
#define BOX_LexNatConFromTerm(t) (_BOX_LexNatConFromTerm(t))
#endif
#ifdef FAST_API
#define BOX_LexNatConToTerm(arg) ((ATerm)(arg))
#else
ATerm _BOX_LexNatConToTerm(BOX_LexNatCon arg);
#define BOX_LexNatConToTerm(arg) (_BOX_LexNatConToTerm(arg))
#endif
#ifdef FAST_API
#define BOX_NatConFromTerm(t) ((BOX_NatCon)(t))
#else
BOX_NatCon _BOX_NatConFromTerm(ATerm t);
#define BOX_NatConFromTerm(t) (_BOX_NatConFromTerm(t))
#endif
#ifdef FAST_API
#define BOX_NatConToTerm(arg) ((ATerm)(arg))
#else
ATerm _BOX_NatConToTerm(BOX_NatCon arg);
#define BOX_NatConToTerm(arg) (_BOX_NatConToTerm(arg))
#endif
#ifdef FAST_API
#define BOX_AlignmentOptionFromTerm(t) ((BOX_AlignmentOption)(t))
#else
BOX_AlignmentOption _BOX_AlignmentOptionFromTerm(ATerm t);
#define BOX_AlignmentOptionFromTerm(t) (_BOX_AlignmentOptionFromTerm(t))
#endif
#ifdef FAST_API
#define BOX_AlignmentOptionToTerm(arg) ((ATerm)(arg))
#else
ATerm _BOX_AlignmentOptionToTerm(BOX_AlignmentOption arg);
#define BOX_AlignmentOptionToTerm(arg) (_BOX_AlignmentOptionToTerm(arg))
#endif
#ifdef FAST_API
#define BOX_AlignmentOptionsFromTerm(t) ((BOX_AlignmentOptions)(t))
#else
BOX_AlignmentOptions _BOX_AlignmentOptionsFromTerm(ATerm t);
#define BOX_AlignmentOptionsFromTerm(t) (_BOX_AlignmentOptionsFromTerm(t))
#endif
#ifdef FAST_API
#define BOX_AlignmentOptionsToTerm(arg) ((ATerm)(arg))
#else
ATerm _BOX_AlignmentOptionsToTerm(BOX_AlignmentOptions arg);
#define BOX_AlignmentOptionsToTerm(arg) (_BOX_AlignmentOptionsToTerm(arg))
#endif
#ifdef FAST_API
#define BOX_SpaceOptionOptionsFromTerm(t) ((BOX_SpaceOptionOptions)(t))
#else
BOX_SpaceOptionOptions _BOX_SpaceOptionOptionsFromTerm(ATerm t);
#define BOX_SpaceOptionOptionsFromTerm(t) (_BOX_SpaceOptionOptionsFromTerm(t))
#endif
#ifdef FAST_API
#define BOX_SpaceOptionOptionsToTerm(arg) ((ATerm)(arg))
#else
ATerm _BOX_SpaceOptionOptionsToTerm(BOX_SpaceOptionOptions arg);
#define BOX_SpaceOptionOptionsToTerm(arg) (_BOX_SpaceOptionOptionsToTerm(arg))
#endif
#ifdef FAST_API
#define BOX_AlignmentOptionListFromTerm(t) ((BOX_AlignmentOptionList)(t))
#else
BOX_AlignmentOptionList _BOX_AlignmentOptionListFromTerm(ATerm t);
#define BOX_AlignmentOptionListFromTerm(t) (_BOX_AlignmentOptionListFromTerm(t))
#endif
#ifdef FAST_API
#define BOX_AlignmentOptionListToTerm(arg) ((ATerm)(arg))
#else
ATerm _BOX_AlignmentOptionListToTerm(BOX_AlignmentOptionList arg);
#define BOX_AlignmentOptionListToTerm(arg) (_BOX_AlignmentOptionListToTerm(arg))
#endif
#ifdef FAST_API
#define BOX_SpaceSymbolFromTerm(t) ((BOX_SpaceSymbol)(t))
#else
BOX_SpaceSymbol _BOX_SpaceSymbolFromTerm(ATerm t);
#define BOX_SpaceSymbolFromTerm(t) (_BOX_SpaceSymbolFromTerm(t))
#endif
#ifdef FAST_API
#define BOX_SpaceSymbolToTerm(arg) ((ATerm)(arg))
#else
ATerm _BOX_SpaceSymbolToTerm(BOX_SpaceSymbol arg);
#define BOX_SpaceSymbolToTerm(arg) (_BOX_SpaceSymbolToTerm(arg))
#endif
#ifdef FAST_API
#define BOX_SpaceOptionFromTerm(t) ((BOX_SpaceOption)(t))
#else
BOX_SpaceOption _BOX_SpaceOptionFromTerm(ATerm t);
#define BOX_SpaceOptionFromTerm(t) (_BOX_SpaceOptionFromTerm(t))
#endif
#ifdef FAST_API
#define BOX_SpaceOptionToTerm(arg) ((ATerm)(arg))
#else
ATerm _BOX_SpaceOptionToTerm(BOX_SpaceOption arg);
#define BOX_SpaceOptionToTerm(arg) (_BOX_SpaceOptionToTerm(arg))
#endif
#ifdef FAST_API
#define BOX_BoxFromTerm(t) ((BOX_Box)(t))
#else
BOX_Box _BOX_BoxFromTerm(ATerm t);
#define BOX_BoxFromTerm(t) (_BOX_BoxFromTerm(t))
#endif
#ifdef FAST_API
#define BOX_BoxToTerm(arg) ((ATerm)(arg))
#else
ATerm _BOX_BoxToTerm(BOX_Box arg);
#define BOX_BoxToTerm(arg) (_BOX_BoxToTerm(arg))
#endif
#ifdef FAST_API
#define BOX_BoxListFromTerm(t) ((BOX_BoxList)(t))
#else
BOX_BoxList _BOX_BoxListFromTerm(ATerm t);
#define BOX_BoxListFromTerm(t) (_BOX_BoxListFromTerm(t))
#endif
#ifdef FAST_API
#define BOX_BoxListToTerm(arg) ((ATerm)(arg))
#else
ATerm _BOX_BoxListToTerm(BOX_BoxList arg);
#define BOX_BoxListToTerm(arg) (_BOX_BoxListToTerm(arg))
#endif
#ifdef FAST_API
#define BOX_LexLayoutFromTerm(t) ((BOX_LexLayout)(t))
#else
BOX_LexLayout _BOX_LexLayoutFromTerm(ATerm t);
#define BOX_LexLayoutFromTerm(t) (_BOX_LexLayoutFromTerm(t))
#endif
#ifdef FAST_API
#define BOX_LexLayoutToTerm(arg) ((ATerm)(arg))
#else
ATerm _BOX_LexLayoutToTerm(BOX_LexLayout arg);
#define BOX_LexLayoutToTerm(arg) (_BOX_LexLayoutToTerm(arg))
#endif
#ifdef FAST_API
#define BOX_LexFontIdFromTerm(t) ((BOX_LexFontId)(t))
#else
BOX_LexFontId _BOX_LexFontIdFromTerm(ATerm t);
#define BOX_LexFontIdFromTerm(t) (_BOX_LexFontIdFromTerm(t))
#endif
#ifdef FAST_API
#define BOX_LexFontIdToTerm(arg) ((ATerm)(arg))
#else
ATerm _BOX_LexFontIdToTerm(BOX_LexFontId arg);
#define BOX_LexFontIdToTerm(arg) (_BOX_LexFontIdToTerm(arg))
#endif
#ifdef FAST_API
#define BOX_FontIdFromTerm(t) ((BOX_FontId)(t))
#else
BOX_FontId _BOX_FontIdFromTerm(ATerm t);
#define BOX_FontIdFromTerm(t) (_BOX_FontIdFromTerm(t))
#endif
#ifdef FAST_API
#define BOX_FontIdToTerm(arg) ((ATerm)(arg))
#else
ATerm _BOX_FontIdToTerm(BOX_FontId arg);
#define BOX_FontIdToTerm(arg) (_BOX_FontIdToTerm(arg))
#endif
#ifdef FAST_API
#define BOX_FontValueFromTerm(t) ((BOX_FontValue)(t))
#else
BOX_FontValue _BOX_FontValueFromTerm(ATerm t);
#define BOX_FontValueFromTerm(t) (_BOX_FontValueFromTerm(t))
#endif
#ifdef FAST_API
#define BOX_FontValueToTerm(arg) ((ATerm)(arg))
#else
ATerm _BOX_FontValueToTerm(BOX_FontValue arg);
#define BOX_FontValueToTerm(arg) (_BOX_FontValueToTerm(arg))
#endif
#ifdef FAST_API
#define BOX_FontOptionFromTerm(t) ((BOX_FontOption)(t))
#else
BOX_FontOption _BOX_FontOptionFromTerm(ATerm t);
#define BOX_FontOptionFromTerm(t) (_BOX_FontOptionFromTerm(t))
#endif
#ifdef FAST_API
#define BOX_FontOptionToTerm(arg) ((ATerm)(arg))
#else
ATerm _BOX_FontOptionToTerm(BOX_FontOption arg);
#define BOX_FontOptionToTerm(arg) (_BOX_FontOptionToTerm(arg))
#endif
#ifdef FAST_API
#define BOX_FontParamFromTerm(t) ((BOX_FontParam)(t))
#else
BOX_FontParam _BOX_FontParamFromTerm(ATerm t);
#define BOX_FontParamFromTerm(t) (_BOX_FontParamFromTerm(t))
#endif
#ifdef FAST_API
#define BOX_FontParamToTerm(arg) ((ATerm)(arg))
#else
ATerm _BOX_FontParamToTerm(BOX_FontParam arg);
#define BOX_FontParamToTerm(arg) (_BOX_FontParamToTerm(arg))
#endif
#ifdef FAST_API
#define BOX_FontOperatorFromTerm(t) ((BOX_FontOperator)(t))
#else
BOX_FontOperator _BOX_FontOperatorFromTerm(ATerm t);
#define BOX_FontOperatorFromTerm(t) (_BOX_FontOperatorFromTerm(t))
#endif
#ifdef FAST_API
#define BOX_FontOperatorToTerm(arg) ((ATerm)(arg))
#else
ATerm _BOX_FontOperatorToTerm(BOX_FontOperator arg);
#define BOX_FontOperatorToTerm(arg) (_BOX_FontOperatorToTerm(arg))
#endif
#ifdef FAST_API
#define BOX_FontOptionListFromTerm(t) ((BOX_FontOptionList)(t))
#else
BOX_FontOptionList _BOX_FontOptionListFromTerm(ATerm t);
#define BOX_FontOptionListFromTerm(t) (_BOX_FontOptionListFromTerm(t))
#endif
#ifdef FAST_API
#define BOX_FontOptionListToTerm(arg) ((ATerm)(arg))
#else
ATerm _BOX_FontOptionListToTerm(BOX_FontOptionList arg);
#define BOX_FontOptionListToTerm(arg) (_BOX_FontOptionListToTerm(arg))
#endif
#ifdef FAST_API
#define BOX_LexStrCharFromTerm(t) ((BOX_LexStrChar)(t))
#else
BOX_LexStrChar _BOX_LexStrCharFromTerm(ATerm t);
#define BOX_LexStrCharFromTerm(t) (_BOX_LexStrCharFromTerm(t))
#endif
#ifdef FAST_API
#define BOX_LexStrCharToTerm(arg) ((ATerm)(arg))
#else
ATerm _BOX_LexStrCharToTerm(BOX_LexStrChar arg);
#define BOX_LexStrCharToTerm(arg) (_BOX_LexStrCharToTerm(arg))
#endif
#ifdef FAST_API
#define BOX_StrCharFromTerm(t) ((BOX_StrChar)(t))
#else
BOX_StrChar _BOX_StrCharFromTerm(ATerm t);
#define BOX_StrCharFromTerm(t) (_BOX_StrCharFromTerm(t))
#endif
#ifdef FAST_API
#define BOX_StrCharToTerm(arg) ((ATerm)(arg))
#else
ATerm _BOX_StrCharToTerm(BOX_StrChar arg);
#define BOX_StrCharToTerm(arg) (_BOX_StrCharToTerm(arg))
#endif
#ifdef FAST_API
#define BOX_LexStrConFromTerm(t) ((BOX_LexStrCon)(t))
#else
BOX_LexStrCon _BOX_LexStrConFromTerm(ATerm t);
#define BOX_LexStrConFromTerm(t) (_BOX_LexStrConFromTerm(t))
#endif
#ifdef FAST_API
#define BOX_LexStrConToTerm(arg) ((ATerm)(arg))
#else
ATerm _BOX_LexStrConToTerm(BOX_LexStrCon arg);
#define BOX_LexStrConToTerm(arg) (_BOX_LexStrConToTerm(arg))
#endif
#ifdef FAST_API
#define BOX_StrConFromTerm(t) ((BOX_StrCon)(t))
#else
BOX_StrCon _BOX_StrConFromTerm(ATerm t);
#define BOX_StrConFromTerm(t) (_BOX_StrConFromTerm(t))
#endif
#ifdef FAST_API
#define BOX_StrConToTerm(arg) ((ATerm)(arg))
#else
ATerm _BOX_StrConToTerm(BOX_StrCon arg);
#define BOX_StrConToTerm(arg) (_BOX_StrConToTerm(arg))
#endif
#ifdef FAST_API
#define BOX_LexStrCharCharsFromTerm(t) ((BOX_LexStrCharChars)(t))
#else
BOX_LexStrCharChars _BOX_LexStrCharCharsFromTerm(ATerm t);
#define BOX_LexStrCharCharsFromTerm(t) (_BOX_LexStrCharCharsFromTerm(t))
#endif
#ifdef FAST_API
#define BOX_LexStrCharCharsToTerm(arg) ((ATerm)(arg))
#else
ATerm _BOX_LexStrCharCharsToTerm(BOX_LexStrCharChars arg);
#define BOX_LexStrCharCharsToTerm(arg) (_BOX_LexStrCharCharsToTerm(arg))
#endif
#ifdef FAST_API
#define BOX_getLexLayoutListLength(arg) (ATgetLength((ATermList) (arg)))
#else
int _BOX_getLexLayoutListLength(BOX_LexLayoutList arg);
#define BOX_getLexLayoutListLength(arg) (_BOX_getLexLayoutListLength(arg))
#endif
#ifdef FAST_API
#define BOX_reverseLexLayoutList(arg) ((BOX_LexLayoutList) ATreverse((ATermList) (arg)))
#else
BOX_LexLayoutList _BOX_reverseLexLayoutList(BOX_LexLayoutList arg);
#define BOX_reverseLexLayoutList(arg) (_BOX_reverseLexLayoutList(arg))
#endif
#ifdef FAST_API
#define BOX_appendLexLayoutList(arg, elem) ((BOX_LexLayoutList) ATappend((ATermList) (arg), (ATerm) (((ATerm) elem))))
#else
BOX_LexLayoutList _BOX_appendLexLayoutList(BOX_LexLayoutList arg, BOX_LexLayout elem);
#define BOX_appendLexLayoutList(arg, elem) (_BOX_appendLexLayoutList(arg, elem))
#endif
#ifdef FAST_API
#define BOX_concatLexLayoutList(arg0, arg1) ((BOX_LexLayoutList) ATconcat((ATermList) (arg0), (ATermList) (arg1)))
#else
BOX_LexLayoutList _BOX_concatLexLayoutList(BOX_LexLayoutList arg0, BOX_LexLayoutList arg1);
#define BOX_concatLexLayoutList(arg0, arg1) (_BOX_concatLexLayoutList(arg0, arg1))
#endif
#ifdef FAST_API
#define BOX_sliceLexLayoutList(arg, start, end) ((BOX_LexLayoutList) ATgetSlice((ATermList) (arg), (start), (end)))
#else
BOX_LexLayoutList _BOX_sliceLexLayoutList(BOX_LexLayoutList arg, int start, int end);
#define BOX_sliceLexLayoutList(arg, start, end) (_BOX_sliceLexLayoutList(arg, start, end))
#endif
#ifdef FAST_API
#define BOX_getLexLayoutListLexLayoutAt(arg, index) ((BOX_LexLayout) (ATelementAt((ATermList) arg,index)))
#else
BOX_LexLayout _BOX_getLexLayoutListLexLayoutAt(BOX_LexLayoutList arg, int index);
#define BOX_getLexLayoutListLexLayoutAt(arg, index) (_BOX_getLexLayoutListLexLayoutAt(arg, index))
#endif
#ifdef FAST_API
#define BOX_replaceLexLayoutListLexLayoutAt(arg, elem, index) ((BOX_LexLayoutList) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index)))
#else
BOX_LexLayoutList _BOX_replaceLexLayoutListLexLayoutAt(BOX_LexLayoutList arg, BOX_LexLayout elem, int index);
#define BOX_replaceLexLayoutListLexLayoutAt(arg, elem, index) (_BOX_replaceLexLayoutListLexLayoutAt(arg, elem, index))
#endif
#ifdef FAST_API
#define BOX_makeLexLayoutList2(elem1,  elem2) ((BOX_LexLayoutList) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) (((ATerm) elem2))))
#else
BOX_LexLayoutList _BOX_makeLexLayoutList2(BOX_LexLayout elem1, BOX_LexLayout elem2);
#define BOX_makeLexLayoutList2(elem1,  elem2) (_BOX_makeLexLayoutList2(elem1,  elem2))
#endif
#ifdef FAST_API
#define BOX_makeLexLayoutList3(elem1, elem2,  elem3) ((BOX_LexLayoutList) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) (((ATerm) elem3))))
#else
BOX_LexLayoutList _BOX_makeLexLayoutList3(BOX_LexLayout elem1, BOX_LexLayout elem2, BOX_LexLayout elem3);
#define BOX_makeLexLayoutList3(elem1, elem2,  elem3) (_BOX_makeLexLayoutList3(elem1, elem2,  elem3))
#endif
#ifdef FAST_API
#define BOX_makeLexLayoutList4(elem1, elem2, elem3,  elem4) ((BOX_LexLayoutList) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) (((ATerm) elem4))))
#else
BOX_LexLayoutList _BOX_makeLexLayoutList4(BOX_LexLayout elem1, BOX_LexLayout elem2, BOX_LexLayout elem3, BOX_LexLayout elem4);
#define BOX_makeLexLayoutList4(elem1, elem2, elem3,  elem4) (_BOX_makeLexLayoutList4(elem1, elem2, elem3,  elem4))
#endif
#ifdef FAST_API
#define BOX_makeLexLayoutList5(elem1, elem2, elem3, elem4,  elem5) ((BOX_LexLayoutList) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) (((ATerm) elem5))))
#else
BOX_LexLayoutList _BOX_makeLexLayoutList5(BOX_LexLayout elem1, BOX_LexLayout elem2, BOX_LexLayout elem3, BOX_LexLayout elem4, BOX_LexLayout elem5);
#define BOX_makeLexLayoutList5(elem1, elem2, elem3, elem4,  elem5) (_BOX_makeLexLayoutList5(elem1, elem2, elem3, elem4,  elem5))
#endif
#ifdef FAST_API
#define BOX_makeLexLayoutList6(elem1, elem2, elem3, elem4, elem5,  elem6) ((BOX_LexLayoutList) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) (((ATerm) elem6))))
#else
BOX_LexLayoutList _BOX_makeLexLayoutList6(BOX_LexLayout elem1, BOX_LexLayout elem2, BOX_LexLayout elem3, BOX_LexLayout elem4, BOX_LexLayout elem5, BOX_LexLayout elem6);
#define BOX_makeLexLayoutList6(elem1, elem2, elem3, elem4, elem5,  elem6) (_BOX_makeLexLayoutList6(elem1, elem2, elem3, elem4, elem5,  elem6))
#endif
#ifdef FAST_API
#define BOX_getGroupOptionGroupOptionsLength(arg) ((ATisEmpty((ATermList) (arg)) ? 0 : (ATgetLength((ATermList) (arg)) / 2) + 1))
#else
int _BOX_getGroupOptionGroupOptionsLength(BOX_GroupOptionGroupOptions arg);
#define BOX_getGroupOptionGroupOptionsLength(arg) (_BOX_getGroupOptionGroupOptionsLength(arg))
#endif
BOX_GroupOptionGroupOptions BOX_reverseGroupOptionGroupOptions(BOX_GroupOptionGroupOptions arg);
BOX_GroupOptionGroupOptions BOX_appendGroupOptionGroupOptions(BOX_GroupOptionGroupOptions arg0, BOX_OptLayout wsAfterHead, BOX_GroupOption arg1);
BOX_GroupOptionGroupOptions BOX_concatGroupOptionGroupOptions(BOX_GroupOptionGroupOptions arg0, BOX_OptLayout wsAfterHead, BOX_GroupOptionGroupOptions arg1);
#ifdef FAST_API
#define BOX_sliceGroupOptionGroupOptions(arg, start, end) ((BOX_GroupOptionGroupOptions) ATgetSlice((ATermList) (arg), (start * 2), (end * 2)))
#else
BOX_GroupOptionGroupOptions _BOX_sliceGroupOptionGroupOptions(BOX_GroupOptionGroupOptions arg, int start, int end);
#define BOX_sliceGroupOptionGroupOptions(arg, start, end) (_BOX_sliceGroupOptionGroupOptions(arg, start, end))
#endif
#ifdef FAST_API
#define BOX_getGroupOptionGroupOptionsGroupOptionAt(arg, index) ((BOX_GroupOption) (ATelementAt((ATermList) arg,index * 2)))
#else
BOX_GroupOption _BOX_getGroupOptionGroupOptionsGroupOptionAt(BOX_GroupOptionGroupOptions arg, int index);
#define BOX_getGroupOptionGroupOptionsGroupOptionAt(arg, index) (_BOX_getGroupOptionGroupOptionsGroupOptionAt(arg, index))
#endif
#ifdef FAST_API
#define BOX_replaceGroupOptionGroupOptionsGroupOptionAt(arg, elem, index) ((BOX_GroupOptionGroupOptions) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index * 2)))
#else
BOX_GroupOptionGroupOptions _BOX_replaceGroupOptionGroupOptionsGroupOptionAt(BOX_GroupOptionGroupOptions arg, BOX_GroupOption elem, int index);
#define BOX_replaceGroupOptionGroupOptionsGroupOptionAt(arg, elem, index) (_BOX_replaceGroupOptionGroupOptionsGroupOptionAt(arg, elem, index))
#endif
BOX_GroupOptionGroupOptions BOX_makeGroupOptionGroupOptions2(BOX_OptLayout wsAfterHead, BOX_GroupOption elem1, BOX_GroupOption elem2);
BOX_GroupOptionGroupOptions BOX_makeGroupOptionGroupOptions3(BOX_OptLayout wsAfterHead, BOX_GroupOption elem1, BOX_GroupOption elem2, BOX_GroupOption elem3);
BOX_GroupOptionGroupOptions BOX_makeGroupOptionGroupOptions4(BOX_OptLayout wsAfterHead, BOX_GroupOption elem1, BOX_GroupOption elem2, BOX_GroupOption elem3, BOX_GroupOption elem4);
BOX_GroupOptionGroupOptions BOX_makeGroupOptionGroupOptions5(BOX_OptLayout wsAfterHead, BOX_GroupOption elem1, BOX_GroupOption elem2, BOX_GroupOption elem3, BOX_GroupOption elem4, BOX_GroupOption elem5);
BOX_GroupOptionGroupOptions BOX_makeGroupOptionGroupOptions6(BOX_OptLayout wsAfterHead, BOX_GroupOption elem1, BOX_GroupOption elem2, BOX_GroupOption elem3, BOX_GroupOption elem4, BOX_GroupOption elem5, BOX_GroupOption elem6);
#ifdef FAST_API
#define BOX_getSpaceOptionOptionsLength(arg) ((ATisEmpty((ATermList) (arg)) ? 0 : (ATgetLength((ATermList) (arg)) / 2) + 1))
#else
int _BOX_getSpaceOptionOptionsLength(BOX_SpaceOptionOptions arg);
#define BOX_getSpaceOptionOptionsLength(arg) (_BOX_getSpaceOptionOptionsLength(arg))
#endif
BOX_SpaceOptionOptions BOX_reverseSpaceOptionOptions(BOX_SpaceOptionOptions arg);
BOX_SpaceOptionOptions BOX_appendSpaceOptionOptions(BOX_SpaceOptionOptions arg0, BOX_OptLayout wsAfterHead, BOX_SpaceOption arg1);
BOX_SpaceOptionOptions BOX_concatSpaceOptionOptions(BOX_SpaceOptionOptions arg0, BOX_OptLayout wsAfterHead, BOX_SpaceOptionOptions arg1);
#ifdef FAST_API
#define BOX_sliceSpaceOptionOptions(arg, start, end) ((BOX_SpaceOptionOptions) ATgetSlice((ATermList) (arg), (start * 2), (end * 2)))
#else
BOX_SpaceOptionOptions _BOX_sliceSpaceOptionOptions(BOX_SpaceOptionOptions arg, int start, int end);
#define BOX_sliceSpaceOptionOptions(arg, start, end) (_BOX_sliceSpaceOptionOptions(arg, start, end))
#endif
#ifdef FAST_API
#define BOX_getSpaceOptionOptionsSpaceOptionAt(arg, index) ((BOX_SpaceOption) (ATelementAt((ATermList) arg,index * 2)))
#else
BOX_SpaceOption _BOX_getSpaceOptionOptionsSpaceOptionAt(BOX_SpaceOptionOptions arg, int index);
#define BOX_getSpaceOptionOptionsSpaceOptionAt(arg, index) (_BOX_getSpaceOptionOptionsSpaceOptionAt(arg, index))
#endif
#ifdef FAST_API
#define BOX_replaceSpaceOptionOptionsSpaceOptionAt(arg, elem, index) ((BOX_SpaceOptionOptions) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index * 2)))
#else
BOX_SpaceOptionOptions _BOX_replaceSpaceOptionOptionsSpaceOptionAt(BOX_SpaceOptionOptions arg, BOX_SpaceOption elem, int index);
#define BOX_replaceSpaceOptionOptionsSpaceOptionAt(arg, elem, index) (_BOX_replaceSpaceOptionOptionsSpaceOptionAt(arg, elem, index))
#endif
BOX_SpaceOptionOptions BOX_makeSpaceOptionOptions2(BOX_OptLayout wsAfterHead, BOX_SpaceOption elem1, BOX_SpaceOption elem2);
BOX_SpaceOptionOptions BOX_makeSpaceOptionOptions3(BOX_OptLayout wsAfterHead, BOX_SpaceOption elem1, BOX_SpaceOption elem2, BOX_SpaceOption elem3);
BOX_SpaceOptionOptions BOX_makeSpaceOptionOptions4(BOX_OptLayout wsAfterHead, BOX_SpaceOption elem1, BOX_SpaceOption elem2, BOX_SpaceOption elem3, BOX_SpaceOption elem4);
BOX_SpaceOptionOptions BOX_makeSpaceOptionOptions5(BOX_OptLayout wsAfterHead, BOX_SpaceOption elem1, BOX_SpaceOption elem2, BOX_SpaceOption elem3, BOX_SpaceOption elem4, BOX_SpaceOption elem5);
BOX_SpaceOptionOptions BOX_makeSpaceOptionOptions6(BOX_OptLayout wsAfterHead, BOX_SpaceOption elem1, BOX_SpaceOption elem2, BOX_SpaceOption elem3, BOX_SpaceOption elem4, BOX_SpaceOption elem5, BOX_SpaceOption elem6);
#ifdef FAST_API
#define BOX_getAlignmentOptionListLength(arg) ((ATisEmpty((ATermList) (arg)) ? 0 : (ATgetLength((ATermList) (arg)) / 4) + 1))
#else
int _BOX_getAlignmentOptionListLength(BOX_AlignmentOptionList arg);
#define BOX_getAlignmentOptionListLength(arg) (_BOX_getAlignmentOptionListLength(arg))
#endif
BOX_AlignmentOptionList BOX_reverseAlignmentOptionList(BOX_AlignmentOptionList arg);
BOX_AlignmentOptionList BOX_appendAlignmentOptionList(BOX_AlignmentOptionList arg0, BOX_OptLayout wsAfterHead, BOX_OptLayout wsAfterSep, BOX_AlignmentOption arg1);
BOX_AlignmentOptionList BOX_concatAlignmentOptionList(BOX_AlignmentOptionList arg0, BOX_OptLayout wsAfterHead, BOX_OptLayout wsAfterSep, BOX_AlignmentOptionList arg1);
#ifdef FAST_API
#define BOX_sliceAlignmentOptionList(arg, start, end) ((BOX_AlignmentOptionList) ATgetSlice((ATermList) (arg), (start * 4), (end * 4)))
#else
BOX_AlignmentOptionList _BOX_sliceAlignmentOptionList(BOX_AlignmentOptionList arg, int start, int end);
#define BOX_sliceAlignmentOptionList(arg, start, end) (_BOX_sliceAlignmentOptionList(arg, start, end))
#endif
#ifdef FAST_API
#define BOX_getAlignmentOptionListAlignmentOptionAt(arg, index) ((BOX_AlignmentOption) (ATelementAt((ATermList) arg,index * 4)))
#else
BOX_AlignmentOption _BOX_getAlignmentOptionListAlignmentOptionAt(BOX_AlignmentOptionList arg, int index);
#define BOX_getAlignmentOptionListAlignmentOptionAt(arg, index) (_BOX_getAlignmentOptionListAlignmentOptionAt(arg, index))
#endif
#ifdef FAST_API
#define BOX_replaceAlignmentOptionListAlignmentOptionAt(arg, elem, index) ((BOX_AlignmentOptionList) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index * 4)))
#else
BOX_AlignmentOptionList _BOX_replaceAlignmentOptionListAlignmentOptionAt(BOX_AlignmentOptionList arg, BOX_AlignmentOption elem, int index);
#define BOX_replaceAlignmentOptionListAlignmentOptionAt(arg, elem, index) (_BOX_replaceAlignmentOptionListAlignmentOptionAt(arg, elem, index))
#endif
BOX_AlignmentOptionList BOX_makeAlignmentOptionList2(BOX_OptLayout wsAfterHead, BOX_OptLayout wsAfterSep, BOX_AlignmentOption elem1, BOX_AlignmentOption elem2);
BOX_AlignmentOptionList BOX_makeAlignmentOptionList3(BOX_OptLayout wsAfterHead, BOX_OptLayout wsAfterSep, BOX_AlignmentOption elem1, BOX_AlignmentOption elem2, BOX_AlignmentOption elem3);
BOX_AlignmentOptionList BOX_makeAlignmentOptionList4(BOX_OptLayout wsAfterHead, BOX_OptLayout wsAfterSep, BOX_AlignmentOption elem1, BOX_AlignmentOption elem2, BOX_AlignmentOption elem3, BOX_AlignmentOption elem4);
BOX_AlignmentOptionList BOX_makeAlignmentOptionList5(BOX_OptLayout wsAfterHead, BOX_OptLayout wsAfterSep, BOX_AlignmentOption elem1, BOX_AlignmentOption elem2, BOX_AlignmentOption elem3, BOX_AlignmentOption elem4, BOX_AlignmentOption elem5);
BOX_AlignmentOptionList BOX_makeAlignmentOptionList6(BOX_OptLayout wsAfterHead, BOX_OptLayout wsAfterSep, BOX_AlignmentOption elem1, BOX_AlignmentOption elem2, BOX_AlignmentOption elem3, BOX_AlignmentOption elem4, BOX_AlignmentOption elem5, BOX_AlignmentOption elem6);
#ifdef FAST_API
#define BOX_getBoxListLength(arg) ((ATisEmpty((ATermList) (arg)) ? 0 : (ATgetLength((ATermList) (arg)) / 2) + 1))
#else
int _BOX_getBoxListLength(BOX_BoxList arg);
#define BOX_getBoxListLength(arg) (_BOX_getBoxListLength(arg))
#endif
BOX_BoxList BOX_reverseBoxList(BOX_BoxList arg);
BOX_BoxList BOX_appendBoxList(BOX_BoxList arg0, BOX_OptLayout wsAfterHead, BOX_Box arg1);
BOX_BoxList BOX_concatBoxList(BOX_BoxList arg0, BOX_OptLayout wsAfterHead, BOX_BoxList arg1);
#ifdef FAST_API
#define BOX_sliceBoxList(arg, start, end) ((BOX_BoxList) ATgetSlice((ATermList) (arg), (start * 2), (end * 2)))
#else
BOX_BoxList _BOX_sliceBoxList(BOX_BoxList arg, int start, int end);
#define BOX_sliceBoxList(arg, start, end) (_BOX_sliceBoxList(arg, start, end))
#endif
#ifdef FAST_API
#define BOX_getBoxListBoxAt(arg, index) ((BOX_Box) (ATelementAt((ATermList) arg,index * 2)))
#else
BOX_Box _BOX_getBoxListBoxAt(BOX_BoxList arg, int index);
#define BOX_getBoxListBoxAt(arg, index) (_BOX_getBoxListBoxAt(arg, index))
#endif
#ifdef FAST_API
#define BOX_replaceBoxListBoxAt(arg, elem, index) ((BOX_BoxList) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index * 2)))
#else
BOX_BoxList _BOX_replaceBoxListBoxAt(BOX_BoxList arg, BOX_Box elem, int index);
#define BOX_replaceBoxListBoxAt(arg, elem, index) (_BOX_replaceBoxListBoxAt(arg, elem, index))
#endif
BOX_BoxList BOX_makeBoxList2(BOX_OptLayout wsAfterHead, BOX_Box elem1, BOX_Box elem2);
BOX_BoxList BOX_makeBoxList3(BOX_OptLayout wsAfterHead, BOX_Box elem1, BOX_Box elem2, BOX_Box elem3);
BOX_BoxList BOX_makeBoxList4(BOX_OptLayout wsAfterHead, BOX_Box elem1, BOX_Box elem2, BOX_Box elem3, BOX_Box elem4);
BOX_BoxList BOX_makeBoxList5(BOX_OptLayout wsAfterHead, BOX_Box elem1, BOX_Box elem2, BOX_Box elem3, BOX_Box elem4, BOX_Box elem5);
BOX_BoxList BOX_makeBoxList6(BOX_OptLayout wsAfterHead, BOX_Box elem1, BOX_Box elem2, BOX_Box elem3, BOX_Box elem4, BOX_Box elem5, BOX_Box elem6);
#ifdef FAST_API
#define BOX_getFontOptionListLength(arg) ((ATisEmpty((ATermList) (arg)) ? 0 : (ATgetLength((ATermList) (arg)) / 2) + 1))
#else
int _BOX_getFontOptionListLength(BOX_FontOptionList arg);
#define BOX_getFontOptionListLength(arg) (_BOX_getFontOptionListLength(arg))
#endif
BOX_FontOptionList BOX_reverseFontOptionList(BOX_FontOptionList arg);
BOX_FontOptionList BOX_appendFontOptionList(BOX_FontOptionList arg0, BOX_OptLayout wsAfterHead, BOX_FontOption arg1);
BOX_FontOptionList BOX_concatFontOptionList(BOX_FontOptionList arg0, BOX_OptLayout wsAfterHead, BOX_FontOptionList arg1);
#ifdef FAST_API
#define BOX_sliceFontOptionList(arg, start, end) ((BOX_FontOptionList) ATgetSlice((ATermList) (arg), (start * 2), (end * 2)))
#else
BOX_FontOptionList _BOX_sliceFontOptionList(BOX_FontOptionList arg, int start, int end);
#define BOX_sliceFontOptionList(arg, start, end) (_BOX_sliceFontOptionList(arg, start, end))
#endif
#ifdef FAST_API
#define BOX_getFontOptionListFontOptionAt(arg, index) ((BOX_FontOption) (ATelementAt((ATermList) arg,index * 2)))
#else
BOX_FontOption _BOX_getFontOptionListFontOptionAt(BOX_FontOptionList arg, int index);
#define BOX_getFontOptionListFontOptionAt(arg, index) (_BOX_getFontOptionListFontOptionAt(arg, index))
#endif
#ifdef FAST_API
#define BOX_replaceFontOptionListFontOptionAt(arg, elem, index) ((BOX_FontOptionList) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index * 2)))
#else
BOX_FontOptionList _BOX_replaceFontOptionListFontOptionAt(BOX_FontOptionList arg, BOX_FontOption elem, int index);
#define BOX_replaceFontOptionListFontOptionAt(arg, elem, index) (_BOX_replaceFontOptionListFontOptionAt(arg, elem, index))
#endif
BOX_FontOptionList BOX_makeFontOptionList2(BOX_OptLayout wsAfterHead, BOX_FontOption elem1, BOX_FontOption elem2);
BOX_FontOptionList BOX_makeFontOptionList3(BOX_OptLayout wsAfterHead, BOX_FontOption elem1, BOX_FontOption elem2, BOX_FontOption elem3);
BOX_FontOptionList BOX_makeFontOptionList4(BOX_OptLayout wsAfterHead, BOX_FontOption elem1, BOX_FontOption elem2, BOX_FontOption elem3, BOX_FontOption elem4);
BOX_FontOptionList BOX_makeFontOptionList5(BOX_OptLayout wsAfterHead, BOX_FontOption elem1, BOX_FontOption elem2, BOX_FontOption elem3, BOX_FontOption elem4, BOX_FontOption elem5);
BOX_FontOptionList BOX_makeFontOptionList6(BOX_OptLayout wsAfterHead, BOX_FontOption elem1, BOX_FontOption elem2, BOX_FontOption elem3, BOX_FontOption elem4, BOX_FontOption elem5, BOX_FontOption elem6);
#ifdef FAST_API
#define BOX_getLexStrCharCharsLength(arg) (ATgetLength((ATermList) (arg)))
#else
int _BOX_getLexStrCharCharsLength(BOX_LexStrCharChars arg);
#define BOX_getLexStrCharCharsLength(arg) (_BOX_getLexStrCharCharsLength(arg))
#endif
#ifdef FAST_API
#define BOX_reverseLexStrCharChars(arg) ((BOX_LexStrCharChars) ATreverse((ATermList) (arg)))
#else
BOX_LexStrCharChars _BOX_reverseLexStrCharChars(BOX_LexStrCharChars arg);
#define BOX_reverseLexStrCharChars(arg) (_BOX_reverseLexStrCharChars(arg))
#endif
#ifdef FAST_API
#define BOX_appendLexStrCharChars(arg, elem) ((BOX_LexStrCharChars) ATappend((ATermList) (arg), (ATerm) (((ATerm) elem))))
#else
BOX_LexStrCharChars _BOX_appendLexStrCharChars(BOX_LexStrCharChars arg, BOX_LexStrChar elem);
#define BOX_appendLexStrCharChars(arg, elem) (_BOX_appendLexStrCharChars(arg, elem))
#endif
#ifdef FAST_API
#define BOX_concatLexStrCharChars(arg0, arg1) ((BOX_LexStrCharChars) ATconcat((ATermList) (arg0), (ATermList) (arg1)))
#else
BOX_LexStrCharChars _BOX_concatLexStrCharChars(BOX_LexStrCharChars arg0, BOX_LexStrCharChars arg1);
#define BOX_concatLexStrCharChars(arg0, arg1) (_BOX_concatLexStrCharChars(arg0, arg1))
#endif
#ifdef FAST_API
#define BOX_sliceLexStrCharChars(arg, start, end) ((BOX_LexStrCharChars) ATgetSlice((ATermList) (arg), (start), (end)))
#else
BOX_LexStrCharChars _BOX_sliceLexStrCharChars(BOX_LexStrCharChars arg, int start, int end);
#define BOX_sliceLexStrCharChars(arg, start, end) (_BOX_sliceLexStrCharChars(arg, start, end))
#endif
#ifdef FAST_API
#define BOX_getLexStrCharCharsLexStrCharAt(arg, index) ((BOX_LexStrChar) (ATelementAt((ATermList) arg,index)))
#else
BOX_LexStrChar _BOX_getLexStrCharCharsLexStrCharAt(BOX_LexStrCharChars arg, int index);
#define BOX_getLexStrCharCharsLexStrCharAt(arg, index) (_BOX_getLexStrCharCharsLexStrCharAt(arg, index))
#endif
#ifdef FAST_API
#define BOX_replaceLexStrCharCharsLexStrCharAt(arg, elem, index) ((BOX_LexStrCharChars) ATreplace((ATermList) (arg), (ATerm) (((ATerm) elem)), (index)))
#else
BOX_LexStrCharChars _BOX_replaceLexStrCharCharsLexStrCharAt(BOX_LexStrCharChars arg, BOX_LexStrChar elem, int index);
#define BOX_replaceLexStrCharCharsLexStrCharAt(arg, elem, index) (_BOX_replaceLexStrCharCharsLexStrCharAt(arg, elem, index))
#endif
#ifdef FAST_API
#define BOX_makeLexStrCharChars2(elem1,  elem2) ((BOX_LexStrCharChars) ATmakeList2((ATerm) ((ATerm) elem1), (ATerm) (((ATerm) elem2))))
#else
BOX_LexStrCharChars _BOX_makeLexStrCharChars2(BOX_LexStrChar elem1, BOX_LexStrChar elem2);
#define BOX_makeLexStrCharChars2(elem1,  elem2) (_BOX_makeLexStrCharChars2(elem1,  elem2))
#endif
#ifdef FAST_API
#define BOX_makeLexStrCharChars3(elem1, elem2,  elem3) ((BOX_LexStrCharChars) ATmakeList3((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) (((ATerm) elem3))))
#else
BOX_LexStrCharChars _BOX_makeLexStrCharChars3(BOX_LexStrChar elem1, BOX_LexStrChar elem2, BOX_LexStrChar elem3);
#define BOX_makeLexStrCharChars3(elem1, elem2,  elem3) (_BOX_makeLexStrCharChars3(elem1, elem2,  elem3))
#endif
#ifdef FAST_API
#define BOX_makeLexStrCharChars4(elem1, elem2, elem3,  elem4) ((BOX_LexStrCharChars) ATmakeList4((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) (((ATerm) elem4))))
#else
BOX_LexStrCharChars _BOX_makeLexStrCharChars4(BOX_LexStrChar elem1, BOX_LexStrChar elem2, BOX_LexStrChar elem3, BOX_LexStrChar elem4);
#define BOX_makeLexStrCharChars4(elem1, elem2, elem3,  elem4) (_BOX_makeLexStrCharChars4(elem1, elem2, elem3,  elem4))
#endif
#ifdef FAST_API
#define BOX_makeLexStrCharChars5(elem1, elem2, elem3, elem4,  elem5) ((BOX_LexStrCharChars) ATmakeList5((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) (((ATerm) elem5))))
#else
BOX_LexStrCharChars _BOX_makeLexStrCharChars5(BOX_LexStrChar elem1, BOX_LexStrChar elem2, BOX_LexStrChar elem3, BOX_LexStrChar elem4, BOX_LexStrChar elem5);
#define BOX_makeLexStrCharChars5(elem1, elem2, elem3, elem4,  elem5) (_BOX_makeLexStrCharChars5(elem1, elem2, elem3, elem4,  elem5))
#endif
#ifdef FAST_API
#define BOX_makeLexStrCharChars6(elem1, elem2, elem3, elem4, elem5,  elem6) ((BOX_LexStrCharChars) ATmakeList6((ATerm) ((ATerm) elem1), (ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem5), (ATerm) (((ATerm) elem6))))
#else
BOX_LexStrCharChars _BOX_makeLexStrCharChars6(BOX_LexStrChar elem1, BOX_LexStrChar elem2, BOX_LexStrChar elem3, BOX_LexStrChar elem4, BOX_LexStrChar elem5, BOX_LexStrChar elem6);
#define BOX_makeLexStrCharChars6(elem1, elem2, elem3, elem4, elem5,  elem6) (_BOX_makeLexStrCharChars6(elem1, elem2, elem3, elem4, elem5,  elem6))
#endif
BOX_OptLayout BOX_makeOptLayoutAbsent(void);
BOX_OptLayout BOX_makeOptLayoutPresent(BOX_Layout layout);
BOX_Layout BOX_makeLayoutLexToCf(BOX_LexLayoutList list);
BOX_LexLayoutList BOX_makeLexLayoutListEmpty(void);
BOX_LexLayoutList BOX_makeLexLayoutListSingle(BOX_LexLayout head);
BOX_LexLayoutList BOX_makeLexLayoutListMany(BOX_LexLayout head, BOX_LexLayoutList tail);
BOX_Start BOX_makeStartBox(BOX_OptLayout wsBefore, BOX_Box topBox, BOX_OptLayout wsAfter, int ambCnt);
BOX_GroupOption BOX_makeGroupOptionSize(BOX_OptLayout wsAfterGs, BOX_OptLayout wsAfterEquals, BOX_NatCon NatCon);
BOX_GroupOption BOX_makeGroupOptionOperator(BOX_OptLayout wsAfterOp, BOX_OptLayout wsAfterEquals, BOX_BoxOperator BoxOperator);
BOX_BoxOperator BOX_makeBoxOperatorGrouping(BOX_OptLayout wsAfterG, BOX_GroupOptionGroupOptions groupOptions);
BOX_BoxOperator BOX_makeBoxOperatorSeparatedList(BOX_OptLayout wsAfterSL, BOX_GroupOptionGroupOptions groupOptions);
BOX_BoxOperator BOX_makeBoxOperatorComment(void);
BOX_BoxOperator BOX_makeBoxOperatorAlignment(BOX_OptLayout wsAfterA, BOX_AlignmentOptions alignments, BOX_OptLayout wsAfterAlignments, BOX_SpaceOptionOptions options);
BOX_BoxOperator BOX_makeBoxOperatorRow(void);
BOX_BoxOperator BOX_makeBoxOperatorH(BOX_OptLayout wsAfterH, BOX_SpaceOptionOptions options);
BOX_BoxOperator BOX_makeBoxOperatorV(BOX_OptLayout wsAfterV, BOX_SpaceOptionOptions options);
BOX_BoxOperator BOX_makeBoxOperatorHv(BOX_OptLayout wsAfterHV, BOX_SpaceOptionOptions options);
BOX_BoxOperator BOX_makeBoxOperatorHov(BOX_OptLayout wsAfterHOV, BOX_SpaceOptionOptions options);
BOX_BoxOperator BOX_makeBoxOperatorI(BOX_OptLayout wsAfterI, BOX_SpaceOptionOptions options);
BOX_BoxOperator BOX_makeBoxOperatorWd(void);
BOX_BoxOperator BOX_makeBoxOperatorFont(BOX_OptLayout wsAfterF, BOX_FontOptionList list);
BOX_GroupOptionGroupOptions BOX_makeGroupOptionGroupOptionsEmpty(void);
BOX_GroupOptionGroupOptions BOX_makeGroupOptionGroupOptionsSingle(BOX_GroupOption head);
BOX_GroupOptionGroupOptions BOX_makeGroupOptionGroupOptionsMany(BOX_GroupOption head, BOX_OptLayout wsAfterHead, BOX_GroupOptionGroupOptions tail);
BOX_LexNatCon BOX_makeLexNatConDigits(const char* list);
BOX_NatCon BOX_makeNatConLexToCf(BOX_LexNatCon NatCon);
BOX_AlignmentOption BOX_makeAlignmentOptionLeft(BOX_OptLayout wsAfterL, BOX_SpaceOptionOptions options);
BOX_AlignmentOption BOX_makeAlignmentOptionCentre(BOX_OptLayout wsAfterC, BOX_SpaceOptionOptions options);
BOX_AlignmentOption BOX_makeAlignmentOptionRight(BOX_OptLayout wsAfterR, BOX_SpaceOptionOptions options);
BOX_AlignmentOptions BOX_makeAlignmentOptionsDefault(BOX_OptLayout wsAfterParenOpen, BOX_AlignmentOptionList list, BOX_OptLayout wsAfterList);
BOX_SpaceOptionOptions BOX_makeSpaceOptionOptionsEmpty(void);
BOX_SpaceOptionOptions BOX_makeSpaceOptionOptionsSingle(BOX_SpaceOption head);
BOX_SpaceOptionOptions BOX_makeSpaceOptionOptionsMany(BOX_SpaceOption head, BOX_OptLayout wsAfterHead, BOX_SpaceOptionOptions tail);
BOX_AlignmentOptionList BOX_makeAlignmentOptionListEmpty(void);
BOX_AlignmentOptionList BOX_makeAlignmentOptionListSingle(BOX_AlignmentOption head);
BOX_AlignmentOptionList BOX_makeAlignmentOptionListMany(BOX_AlignmentOption head, BOX_OptLayout wsAfterHead, BOX_OptLayout wsAfterSep, BOX_AlignmentOptionList tail);
BOX_SpaceSymbol BOX_makeSpaceSymbolHorizontal(void);
BOX_SpaceSymbol BOX_makeSpaceSymbolVertical(void);
BOX_SpaceSymbol BOX_makeSpaceSymbolIndentation(void);
BOX_SpaceSymbol BOX_makeSpaceSymbolTabstop(void);
BOX_SpaceOption BOX_makeSpaceOptionDefault(BOX_SpaceSymbol SpaceSymbol, BOX_OptLayout wsAfterSpaceSymbol, BOX_OptLayout wsAfterEquals, BOX_NatCon NatCon);
BOX_Box BOX_makeBoxString(BOX_StrCon StrCon);
BOX_Box BOX_makeBoxAppl(BOX_BoxOperator operator, BOX_OptLayout wsAfterOperator, BOX_OptLayout wsAfterBracketOpen, BOX_BoxList list, BOX_OptLayout wsAfterList);
BOX_BoxList BOX_makeBoxListEmpty(void);
BOX_BoxList BOX_makeBoxListSingle(BOX_Box head);
BOX_BoxList BOX_makeBoxListMany(BOX_Box head, BOX_OptLayout wsAfterHead, BOX_BoxList tail);
BOX_LexLayout BOX_makeLexLayoutWhitespace(char ch);
BOX_LexLayout BOX_makeLexLayoutLine(const char* line);
BOX_LexLayout BOX_makeLexLayoutNested(const char* content);
BOX_LexFontId BOX_makeLexFontIdDefault(const char* list);
BOX_FontId BOX_makeFontIdLexToCf(BOX_LexFontId FontId);
BOX_FontValue BOX_makeFontValueNatural(BOX_NatCon NatCon);
BOX_FontValue BOX_makeFontValueFontId(BOX_FontId FontId);
BOX_FontOption BOX_makeFontOptionDefault(BOX_FontParam FontParam, BOX_OptLayout wsAfterFontParam, BOX_OptLayout wsAfterEquals, BOX_FontValue FontValue);
BOX_FontParam BOX_makeFontParamName(void);
BOX_FontParam BOX_makeFontParamFamily(void);
BOX_FontParam BOX_makeFontParamSeries(void);
BOX_FontParam BOX_makeFontParamShape(void);
BOX_FontParam BOX_makeFontParamSize(void);
BOX_FontParam BOX_makeFontParamColor(void);
BOX_FontOperator BOX_makeFontOperatorKeyword(void);
BOX_FontOperator BOX_makeFontOperatorVariable(void);
BOX_FontOperator BOX_makeFontOperatorNumber(void);
BOX_FontOperator BOX_makeFontOperatorMath(void);
BOX_FontOperator BOX_makeFontOperatorEscape(void);
BOX_FontOperator BOX_makeFontOperatorComment(void);
BOX_FontOperator BOX_makeFontOperatorString(void);
BOX_FontOptionList BOX_makeFontOptionListEmpty(void);
BOX_FontOptionList BOX_makeFontOptionListSingle(BOX_FontOption head);
BOX_FontOptionList BOX_makeFontOptionListMany(BOX_FontOption head, BOX_OptLayout wsAfterHead, BOX_FontOptionList tail);
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
#ifdef FAST_API
#define BOX_isEqualOptLayout(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _BOX_isEqualOptLayout(BOX_OptLayout arg0, BOX_OptLayout arg1);
#define BOX_isEqualOptLayout(arg0, arg1) (_BOX_isEqualOptLayout(arg0, arg1))
#endif
#ifdef FAST_API
#define BOX_isEqualLayout(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _BOX_isEqualLayout(BOX_Layout arg0, BOX_Layout arg1);
#define BOX_isEqualLayout(arg0, arg1) (_BOX_isEqualLayout(arg0, arg1))
#endif
#ifdef FAST_API
#define BOX_isEqualLexLayoutList(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _BOX_isEqualLexLayoutList(BOX_LexLayoutList arg0, BOX_LexLayoutList arg1);
#define BOX_isEqualLexLayoutList(arg0, arg1) (_BOX_isEqualLexLayoutList(arg0, arg1))
#endif
#ifdef FAST_API
#define BOX_isEqualStart(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _BOX_isEqualStart(BOX_Start arg0, BOX_Start arg1);
#define BOX_isEqualStart(arg0, arg1) (_BOX_isEqualStart(arg0, arg1))
#endif
#ifdef FAST_API
#define BOX_isEqualGroupOption(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _BOX_isEqualGroupOption(BOX_GroupOption arg0, BOX_GroupOption arg1);
#define BOX_isEqualGroupOption(arg0, arg1) (_BOX_isEqualGroupOption(arg0, arg1))
#endif
#ifdef FAST_API
#define BOX_isEqualBoxOperator(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _BOX_isEqualBoxOperator(BOX_BoxOperator arg0, BOX_BoxOperator arg1);
#define BOX_isEqualBoxOperator(arg0, arg1) (_BOX_isEqualBoxOperator(arg0, arg1))
#endif
#ifdef FAST_API
#define BOX_isEqualGroupOptionGroupOptions(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _BOX_isEqualGroupOptionGroupOptions(BOX_GroupOptionGroupOptions arg0, BOX_GroupOptionGroupOptions arg1);
#define BOX_isEqualGroupOptionGroupOptions(arg0, arg1) (_BOX_isEqualGroupOptionGroupOptions(arg0, arg1))
#endif
#ifdef FAST_API
#define BOX_isEqualLexNatCon(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _BOX_isEqualLexNatCon(BOX_LexNatCon arg0, BOX_LexNatCon arg1);
#define BOX_isEqualLexNatCon(arg0, arg1) (_BOX_isEqualLexNatCon(arg0, arg1))
#endif
#ifdef FAST_API
#define BOX_isEqualNatCon(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _BOX_isEqualNatCon(BOX_NatCon arg0, BOX_NatCon arg1);
#define BOX_isEqualNatCon(arg0, arg1) (_BOX_isEqualNatCon(arg0, arg1))
#endif
#ifdef FAST_API
#define BOX_isEqualAlignmentOption(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _BOX_isEqualAlignmentOption(BOX_AlignmentOption arg0, BOX_AlignmentOption arg1);
#define BOX_isEqualAlignmentOption(arg0, arg1) (_BOX_isEqualAlignmentOption(arg0, arg1))
#endif
#ifdef FAST_API
#define BOX_isEqualAlignmentOptions(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _BOX_isEqualAlignmentOptions(BOX_AlignmentOptions arg0, BOX_AlignmentOptions arg1);
#define BOX_isEqualAlignmentOptions(arg0, arg1) (_BOX_isEqualAlignmentOptions(arg0, arg1))
#endif
#ifdef FAST_API
#define BOX_isEqualSpaceOptionOptions(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _BOX_isEqualSpaceOptionOptions(BOX_SpaceOptionOptions arg0, BOX_SpaceOptionOptions arg1);
#define BOX_isEqualSpaceOptionOptions(arg0, arg1) (_BOX_isEqualSpaceOptionOptions(arg0, arg1))
#endif
#ifdef FAST_API
#define BOX_isEqualAlignmentOptionList(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _BOX_isEqualAlignmentOptionList(BOX_AlignmentOptionList arg0, BOX_AlignmentOptionList arg1);
#define BOX_isEqualAlignmentOptionList(arg0, arg1) (_BOX_isEqualAlignmentOptionList(arg0, arg1))
#endif
#ifdef FAST_API
#define BOX_isEqualSpaceSymbol(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _BOX_isEqualSpaceSymbol(BOX_SpaceSymbol arg0, BOX_SpaceSymbol arg1);
#define BOX_isEqualSpaceSymbol(arg0, arg1) (_BOX_isEqualSpaceSymbol(arg0, arg1))
#endif
#ifdef FAST_API
#define BOX_isEqualSpaceOption(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _BOX_isEqualSpaceOption(BOX_SpaceOption arg0, BOX_SpaceOption arg1);
#define BOX_isEqualSpaceOption(arg0, arg1) (_BOX_isEqualSpaceOption(arg0, arg1))
#endif
#ifdef FAST_API
#define BOX_isEqualBox(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _BOX_isEqualBox(BOX_Box arg0, BOX_Box arg1);
#define BOX_isEqualBox(arg0, arg1) (_BOX_isEqualBox(arg0, arg1))
#endif
#ifdef FAST_API
#define BOX_isEqualBoxList(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _BOX_isEqualBoxList(BOX_BoxList arg0, BOX_BoxList arg1);
#define BOX_isEqualBoxList(arg0, arg1) (_BOX_isEqualBoxList(arg0, arg1))
#endif
#ifdef FAST_API
#define BOX_isEqualLexLayout(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _BOX_isEqualLexLayout(BOX_LexLayout arg0, BOX_LexLayout arg1);
#define BOX_isEqualLexLayout(arg0, arg1) (_BOX_isEqualLexLayout(arg0, arg1))
#endif
#ifdef FAST_API
#define BOX_isEqualLexFontId(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _BOX_isEqualLexFontId(BOX_LexFontId arg0, BOX_LexFontId arg1);
#define BOX_isEqualLexFontId(arg0, arg1) (_BOX_isEqualLexFontId(arg0, arg1))
#endif
#ifdef FAST_API
#define BOX_isEqualFontId(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _BOX_isEqualFontId(BOX_FontId arg0, BOX_FontId arg1);
#define BOX_isEqualFontId(arg0, arg1) (_BOX_isEqualFontId(arg0, arg1))
#endif
#ifdef FAST_API
#define BOX_isEqualFontValue(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _BOX_isEqualFontValue(BOX_FontValue arg0, BOX_FontValue arg1);
#define BOX_isEqualFontValue(arg0, arg1) (_BOX_isEqualFontValue(arg0, arg1))
#endif
#ifdef FAST_API
#define BOX_isEqualFontOption(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _BOX_isEqualFontOption(BOX_FontOption arg0, BOX_FontOption arg1);
#define BOX_isEqualFontOption(arg0, arg1) (_BOX_isEqualFontOption(arg0, arg1))
#endif
#ifdef FAST_API
#define BOX_isEqualFontParam(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _BOX_isEqualFontParam(BOX_FontParam arg0, BOX_FontParam arg1);
#define BOX_isEqualFontParam(arg0, arg1) (_BOX_isEqualFontParam(arg0, arg1))
#endif
#ifdef FAST_API
#define BOX_isEqualFontOperator(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _BOX_isEqualFontOperator(BOX_FontOperator arg0, BOX_FontOperator arg1);
#define BOX_isEqualFontOperator(arg0, arg1) (_BOX_isEqualFontOperator(arg0, arg1))
#endif
#ifdef FAST_API
#define BOX_isEqualFontOptionList(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _BOX_isEqualFontOptionList(BOX_FontOptionList arg0, BOX_FontOptionList arg1);
#define BOX_isEqualFontOptionList(arg0, arg1) (_BOX_isEqualFontOptionList(arg0, arg1))
#endif
#ifdef FAST_API
#define BOX_isEqualLexStrChar(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _BOX_isEqualLexStrChar(BOX_LexStrChar arg0, BOX_LexStrChar arg1);
#define BOX_isEqualLexStrChar(arg0, arg1) (_BOX_isEqualLexStrChar(arg0, arg1))
#endif
#ifdef FAST_API
#define BOX_isEqualStrChar(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _BOX_isEqualStrChar(BOX_StrChar arg0, BOX_StrChar arg1);
#define BOX_isEqualStrChar(arg0, arg1) (_BOX_isEqualStrChar(arg0, arg1))
#endif
#ifdef FAST_API
#define BOX_isEqualLexStrCon(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _BOX_isEqualLexStrCon(BOX_LexStrCon arg0, BOX_LexStrCon arg1);
#define BOX_isEqualLexStrCon(arg0, arg1) (_BOX_isEqualLexStrCon(arg0, arg1))
#endif
#ifdef FAST_API
#define BOX_isEqualStrCon(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _BOX_isEqualStrCon(BOX_StrCon arg0, BOX_StrCon arg1);
#define BOX_isEqualStrCon(arg0, arg1) (_BOX_isEqualStrCon(arg0, arg1))
#endif
#ifdef FAST_API
#define BOX_isEqualLexStrCharChars(arg0, arg1) (ATisEqual((ATerm)(arg0), (ATerm)(arg1)))
#else
ATbool _BOX_isEqualLexStrCharChars(BOX_LexStrCharChars arg0, BOX_LexStrCharChars arg1);
#define BOX_isEqualLexStrCharChars(arg0, arg1) (_BOX_isEqualLexStrCharChars(arg0, arg1))
#endif
ATbool BOX_isValidOptLayout(BOX_OptLayout arg);
inline ATbool BOX_isOptLayoutAbsent(BOX_OptLayout arg);
inline ATbool BOX_isOptLayoutPresent(BOX_OptLayout arg);
ATbool BOX_hasOptLayoutLayout(BOX_OptLayout arg);
BOX_Layout BOX_getOptLayoutLayout(BOX_OptLayout arg);
BOX_OptLayout BOX_setOptLayoutLayout(BOX_OptLayout arg, BOX_Layout layout);
ATbool BOX_isValidLayout(BOX_Layout arg);
inline ATbool BOX_isLayoutLexToCf(BOX_Layout arg);
ATbool BOX_hasLayoutList(BOX_Layout arg);
BOX_LexLayoutList BOX_getLayoutList(BOX_Layout arg);
BOX_Layout BOX_setLayoutList(BOX_Layout arg, BOX_LexLayoutList list);
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
ATbool BOX_isValidGroupOption(BOX_GroupOption arg);
inline ATbool BOX_isGroupOptionSize(BOX_GroupOption arg);
inline ATbool BOX_isGroupOptionOperator(BOX_GroupOption arg);
ATbool BOX_hasGroupOptionWsAfterGs(BOX_GroupOption arg);
ATbool BOX_hasGroupOptionWsAfterEquals(BOX_GroupOption arg);
ATbool BOX_hasGroupOptionNatCon(BOX_GroupOption arg);
ATbool BOX_hasGroupOptionWsAfterOp(BOX_GroupOption arg);
ATbool BOX_hasGroupOptionBoxOperator(BOX_GroupOption arg);
BOX_OptLayout BOX_getGroupOptionWsAfterGs(BOX_GroupOption arg);
BOX_OptLayout BOX_getGroupOptionWsAfterEquals(BOX_GroupOption arg);
BOX_NatCon BOX_getGroupOptionNatCon(BOX_GroupOption arg);
BOX_OptLayout BOX_getGroupOptionWsAfterOp(BOX_GroupOption arg);
BOX_BoxOperator BOX_getGroupOptionBoxOperator(BOX_GroupOption arg);
BOX_GroupOption BOX_setGroupOptionWsAfterGs(BOX_GroupOption arg, BOX_OptLayout wsAfterGs);
BOX_GroupOption BOX_setGroupOptionWsAfterEquals(BOX_GroupOption arg, BOX_OptLayout wsAfterEquals);
BOX_GroupOption BOX_setGroupOptionNatCon(BOX_GroupOption arg, BOX_NatCon NatCon);
BOX_GroupOption BOX_setGroupOptionWsAfterOp(BOX_GroupOption arg, BOX_OptLayout wsAfterOp);
BOX_GroupOption BOX_setGroupOptionBoxOperator(BOX_GroupOption arg, BOX_BoxOperator BoxOperator);
ATbool BOX_isValidBoxOperator(BOX_BoxOperator arg);
inline ATbool BOX_isBoxOperatorGrouping(BOX_BoxOperator arg);
inline ATbool BOX_isBoxOperatorSeparatedList(BOX_BoxOperator arg);
inline ATbool BOX_isBoxOperatorComment(BOX_BoxOperator arg);
inline ATbool BOX_isBoxOperatorAlignment(BOX_BoxOperator arg);
inline ATbool BOX_isBoxOperatorRow(BOX_BoxOperator arg);
inline ATbool BOX_isBoxOperatorH(BOX_BoxOperator arg);
inline ATbool BOX_isBoxOperatorV(BOX_BoxOperator arg);
inline ATbool BOX_isBoxOperatorHv(BOX_BoxOperator arg);
inline ATbool BOX_isBoxOperatorHov(BOX_BoxOperator arg);
inline ATbool BOX_isBoxOperatorI(BOX_BoxOperator arg);
inline ATbool BOX_isBoxOperatorWd(BOX_BoxOperator arg);
inline ATbool BOX_isBoxOperatorFont(BOX_BoxOperator arg);
ATbool BOX_hasBoxOperatorWsAfterG(BOX_BoxOperator arg);
ATbool BOX_hasBoxOperatorGroupOptions(BOX_BoxOperator arg);
ATbool BOX_hasBoxOperatorWsAfterSL(BOX_BoxOperator arg);
ATbool BOX_hasBoxOperatorWsAfterA(BOX_BoxOperator arg);
ATbool BOX_hasBoxOperatorAlignments(BOX_BoxOperator arg);
ATbool BOX_hasBoxOperatorWsAfterAlignments(BOX_BoxOperator arg);
ATbool BOX_hasBoxOperatorOptions(BOX_BoxOperator arg);
ATbool BOX_hasBoxOperatorWsAfterH(BOX_BoxOperator arg);
ATbool BOX_hasBoxOperatorWsAfterV(BOX_BoxOperator arg);
ATbool BOX_hasBoxOperatorWsAfterHV(BOX_BoxOperator arg);
ATbool BOX_hasBoxOperatorWsAfterHOV(BOX_BoxOperator arg);
ATbool BOX_hasBoxOperatorWsAfterI(BOX_BoxOperator arg);
ATbool BOX_hasBoxOperatorWsAfterF(BOX_BoxOperator arg);
ATbool BOX_hasBoxOperatorList(BOX_BoxOperator arg);
BOX_OptLayout BOX_getBoxOperatorWsAfterG(BOX_BoxOperator arg);
BOX_GroupOptionGroupOptions BOX_getBoxOperatorGroupOptions(BOX_BoxOperator arg);
BOX_OptLayout BOX_getBoxOperatorWsAfterSL(BOX_BoxOperator arg);
BOX_OptLayout BOX_getBoxOperatorWsAfterA(BOX_BoxOperator arg);
BOX_AlignmentOptions BOX_getBoxOperatorAlignments(BOX_BoxOperator arg);
BOX_OptLayout BOX_getBoxOperatorWsAfterAlignments(BOX_BoxOperator arg);
BOX_SpaceOptionOptions BOX_getBoxOperatorOptions(BOX_BoxOperator arg);
BOX_OptLayout BOX_getBoxOperatorWsAfterH(BOX_BoxOperator arg);
BOX_OptLayout BOX_getBoxOperatorWsAfterV(BOX_BoxOperator arg);
BOX_OptLayout BOX_getBoxOperatorWsAfterHV(BOX_BoxOperator arg);
BOX_OptLayout BOX_getBoxOperatorWsAfterHOV(BOX_BoxOperator arg);
BOX_OptLayout BOX_getBoxOperatorWsAfterI(BOX_BoxOperator arg);
BOX_OptLayout BOX_getBoxOperatorWsAfterF(BOX_BoxOperator arg);
BOX_FontOptionList BOX_getBoxOperatorList(BOX_BoxOperator arg);
BOX_BoxOperator BOX_setBoxOperatorWsAfterG(BOX_BoxOperator arg, BOX_OptLayout wsAfterG);
BOX_BoxOperator BOX_setBoxOperatorGroupOptions(BOX_BoxOperator arg, BOX_GroupOptionGroupOptions groupOptions);
BOX_BoxOperator BOX_setBoxOperatorWsAfterSL(BOX_BoxOperator arg, BOX_OptLayout wsAfterSL);
BOX_BoxOperator BOX_setBoxOperatorWsAfterA(BOX_BoxOperator arg, BOX_OptLayout wsAfterA);
BOX_BoxOperator BOX_setBoxOperatorAlignments(BOX_BoxOperator arg, BOX_AlignmentOptions alignments);
BOX_BoxOperator BOX_setBoxOperatorWsAfterAlignments(BOX_BoxOperator arg, BOX_OptLayout wsAfterAlignments);
BOX_BoxOperator BOX_setBoxOperatorOptions(BOX_BoxOperator arg, BOX_SpaceOptionOptions options);
BOX_BoxOperator BOX_setBoxOperatorWsAfterH(BOX_BoxOperator arg, BOX_OptLayout wsAfterH);
BOX_BoxOperator BOX_setBoxOperatorWsAfterV(BOX_BoxOperator arg, BOX_OptLayout wsAfterV);
BOX_BoxOperator BOX_setBoxOperatorWsAfterHV(BOX_BoxOperator arg, BOX_OptLayout wsAfterHV);
BOX_BoxOperator BOX_setBoxOperatorWsAfterHOV(BOX_BoxOperator arg, BOX_OptLayout wsAfterHOV);
BOX_BoxOperator BOX_setBoxOperatorWsAfterI(BOX_BoxOperator arg, BOX_OptLayout wsAfterI);
BOX_BoxOperator BOX_setBoxOperatorWsAfterF(BOX_BoxOperator arg, BOX_OptLayout wsAfterF);
BOX_BoxOperator BOX_setBoxOperatorList(BOX_BoxOperator arg, BOX_FontOptionList list);
ATbool BOX_isValidGroupOptionGroupOptions(BOX_GroupOptionGroupOptions arg);
inline ATbool BOX_isGroupOptionGroupOptionsEmpty(BOX_GroupOptionGroupOptions arg);
inline ATbool BOX_isGroupOptionGroupOptionsSingle(BOX_GroupOptionGroupOptions arg);
inline ATbool BOX_isGroupOptionGroupOptionsMany(BOX_GroupOptionGroupOptions arg);
ATbool BOX_hasGroupOptionGroupOptionsHead(BOX_GroupOptionGroupOptions arg);
ATbool BOX_hasGroupOptionGroupOptionsWsAfterHead(BOX_GroupOptionGroupOptions arg);
ATbool BOX_hasGroupOptionGroupOptionsTail(BOX_GroupOptionGroupOptions arg);
BOX_GroupOptionGroupOptions BOX_getGroupOptionGroupOptionsTail(BOX_GroupOptionGroupOptions arg);
BOX_GroupOption BOX_getGroupOptionGroupOptionsHead(BOX_GroupOptionGroupOptions arg);
BOX_OptLayout BOX_getGroupOptionGroupOptionsWsAfterHead(BOX_GroupOptionGroupOptions arg);
BOX_GroupOptionGroupOptions BOX_setGroupOptionGroupOptionsHead(BOX_GroupOptionGroupOptions arg, BOX_GroupOption head);
BOX_GroupOptionGroupOptions BOX_setGroupOptionGroupOptionsWsAfterHead(BOX_GroupOptionGroupOptions arg, BOX_OptLayout wsAfterHead);
BOX_GroupOptionGroupOptions BOX_setGroupOptionGroupOptionsTail(BOX_GroupOptionGroupOptions arg, BOX_GroupOptionGroupOptions tail);
ATbool BOX_isValidLexNatCon(BOX_LexNatCon arg);
inline ATbool BOX_isLexNatConDigits(BOX_LexNatCon arg);
ATbool BOX_hasLexNatConList(BOX_LexNatCon arg);
char* BOX_getLexNatConList(BOX_LexNatCon arg);
BOX_LexNatCon BOX_setLexNatConList(BOX_LexNatCon arg, const char* list);
ATbool BOX_isValidNatCon(BOX_NatCon arg);
inline ATbool BOX_isNatConLexToCf(BOX_NatCon arg);
ATbool BOX_hasNatConNatCon(BOX_NatCon arg);
BOX_LexNatCon BOX_getNatConNatCon(BOX_NatCon arg);
BOX_NatCon BOX_setNatConNatCon(BOX_NatCon arg, BOX_LexNatCon NatCon);
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
ATbool BOX_isValidSpaceSymbol(BOX_SpaceSymbol arg);
inline ATbool BOX_isSpaceSymbolHorizontal(BOX_SpaceSymbol arg);
inline ATbool BOX_isSpaceSymbolVertical(BOX_SpaceSymbol arg);
inline ATbool BOX_isSpaceSymbolIndentation(BOX_SpaceSymbol arg);
inline ATbool BOX_isSpaceSymbolTabstop(BOX_SpaceSymbol arg);
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
ATbool BOX_isValidBox(BOX_Box arg);
inline ATbool BOX_isBoxString(BOX_Box arg);
inline ATbool BOX_isBoxAppl(BOX_Box arg);
ATbool BOX_hasBoxStrCon(BOX_Box arg);
ATbool BOX_hasBoxOperator(BOX_Box arg);
ATbool BOX_hasBoxWsAfterOperator(BOX_Box arg);
ATbool BOX_hasBoxWsAfterBracketOpen(BOX_Box arg);
ATbool BOX_hasBoxList(BOX_Box arg);
ATbool BOX_hasBoxWsAfterList(BOX_Box arg);
BOX_StrCon BOX_getBoxStrCon(BOX_Box arg);
BOX_BoxOperator BOX_getBoxOperator(BOX_Box arg);
BOX_OptLayout BOX_getBoxWsAfterOperator(BOX_Box arg);
BOX_OptLayout BOX_getBoxWsAfterBracketOpen(BOX_Box arg);
BOX_BoxList BOX_getBoxList(BOX_Box arg);
BOX_OptLayout BOX_getBoxWsAfterList(BOX_Box arg);
BOX_Box BOX_setBoxStrCon(BOX_Box arg, BOX_StrCon StrCon);
BOX_Box BOX_setBoxOperator(BOX_Box arg, BOX_BoxOperator operator);
BOX_Box BOX_setBoxWsAfterOperator(BOX_Box arg, BOX_OptLayout wsAfterOperator);
BOX_Box BOX_setBoxWsAfterBracketOpen(BOX_Box arg, BOX_OptLayout wsAfterBracketOpen);
BOX_Box BOX_setBoxList(BOX_Box arg, BOX_BoxList list);
BOX_Box BOX_setBoxWsAfterList(BOX_Box arg, BOX_OptLayout wsAfterList);
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
ATbool BOX_isValidLexFontId(BOX_LexFontId arg);
inline ATbool BOX_isLexFontIdDefault(BOX_LexFontId arg);
ATbool BOX_hasLexFontIdList(BOX_LexFontId arg);
char* BOX_getLexFontIdList(BOX_LexFontId arg);
BOX_LexFontId BOX_setLexFontIdList(BOX_LexFontId arg, const char* list);
ATbool BOX_isValidFontId(BOX_FontId arg);
inline ATbool BOX_isFontIdLexToCf(BOX_FontId arg);
ATbool BOX_hasFontIdFontId(BOX_FontId arg);
BOX_LexFontId BOX_getFontIdFontId(BOX_FontId arg);
BOX_FontId BOX_setFontIdFontId(BOX_FontId arg, BOX_LexFontId FontId);
ATbool BOX_isValidFontValue(BOX_FontValue arg);
inline ATbool BOX_isFontValueNatural(BOX_FontValue arg);
inline ATbool BOX_isFontValueFontId(BOX_FontValue arg);
ATbool BOX_hasFontValueNatCon(BOX_FontValue arg);
ATbool BOX_hasFontValueFontId(BOX_FontValue arg);
BOX_NatCon BOX_getFontValueNatCon(BOX_FontValue arg);
BOX_FontId BOX_getFontValueFontId(BOX_FontValue arg);
BOX_FontValue BOX_setFontValueNatCon(BOX_FontValue arg, BOX_NatCon NatCon);
BOX_FontValue BOX_setFontValueFontId(BOX_FontValue arg, BOX_FontId FontId);
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
ATbool BOX_isValidFontParam(BOX_FontParam arg);
inline ATbool BOX_isFontParamName(BOX_FontParam arg);
inline ATbool BOX_isFontParamFamily(BOX_FontParam arg);
inline ATbool BOX_isFontParamSeries(BOX_FontParam arg);
inline ATbool BOX_isFontParamShape(BOX_FontParam arg);
inline ATbool BOX_isFontParamSize(BOX_FontParam arg);
inline ATbool BOX_isFontParamColor(BOX_FontParam arg);
ATbool BOX_isValidFontOperator(BOX_FontOperator arg);
inline ATbool BOX_isFontOperatorKeyword(BOX_FontOperator arg);
inline ATbool BOX_isFontOperatorVariable(BOX_FontOperator arg);
inline ATbool BOX_isFontOperatorNumber(BOX_FontOperator arg);
inline ATbool BOX_isFontOperatorMath(BOX_FontOperator arg);
inline ATbool BOX_isFontOperatorEscape(BOX_FontOperator arg);
inline ATbool BOX_isFontOperatorComment(BOX_FontOperator arg);
inline ATbool BOX_isFontOperatorString(BOX_FontOperator arg);
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
ATbool BOX_isValidStrChar(BOX_StrChar arg);
inline ATbool BOX_isStrCharLexToCf(BOX_StrChar arg);
ATbool BOX_hasStrCharStrChar(BOX_StrChar arg);
BOX_LexStrChar BOX_getStrCharStrChar(BOX_StrChar arg);
BOX_StrChar BOX_setStrCharStrChar(BOX_StrChar arg, BOX_LexStrChar StrChar);
ATbool BOX_isValidLexStrCon(BOX_LexStrCon arg);
inline ATbool BOX_isLexStrConDefault(BOX_LexStrCon arg);
ATbool BOX_hasLexStrConChars(BOX_LexStrCon arg);
BOX_LexStrCharChars BOX_getLexStrConChars(BOX_LexStrCon arg);
BOX_LexStrCon BOX_setLexStrConChars(BOX_LexStrCon arg, BOX_LexStrCharChars chars);
ATbool BOX_isValidStrCon(BOX_StrCon arg);
inline ATbool BOX_isStrConLexToCf(BOX_StrCon arg);
ATbool BOX_hasStrConStrCon(BOX_StrCon arg);
BOX_LexStrCon BOX_getStrConStrCon(BOX_StrCon arg);
BOX_StrCon BOX_setStrConStrCon(BOX_StrCon arg, BOX_LexStrCon StrCon);
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
BOX_OptLayout BOX_visitOptLayout(BOX_OptLayout arg, BOX_Layout (*acceptLayout)(BOX_Layout));
BOX_Layout BOX_visitLayout(BOX_Layout arg, BOX_LexLayoutList (*acceptList)(BOX_LexLayoutList));
BOX_LexLayoutList BOX_visitLexLayoutList(BOX_LexLayoutList arg, BOX_LexLayout (*acceptHead)(BOX_LexLayout));
BOX_Start BOX_visitStart(BOX_Start arg, BOX_OptLayout (*acceptWsBefore)(BOX_OptLayout), BOX_Box (*acceptTopBox)(BOX_Box), BOX_OptLayout (*acceptWsAfter)(BOX_OptLayout), int (*acceptAmbCnt)(int));
BOX_GroupOption BOX_visitGroupOption(BOX_GroupOption arg, BOX_OptLayout (*acceptWsAfterGs)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterEquals)(BOX_OptLayout), BOX_NatCon (*acceptNatCon)(BOX_NatCon), BOX_OptLayout (*acceptWsAfterOp)(BOX_OptLayout), BOX_BoxOperator (*acceptBoxOperator)(BOX_BoxOperator));
BOX_BoxOperator BOX_visitBoxOperator(BOX_BoxOperator arg, BOX_OptLayout (*acceptWsAfterG)(BOX_OptLayout), BOX_GroupOptionGroupOptions (*acceptGroupOptions)(BOX_GroupOptionGroupOptions), BOX_OptLayout (*acceptWsAfterSL)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterA)(BOX_OptLayout), BOX_AlignmentOptions (*acceptAlignments)(BOX_AlignmentOptions), BOX_OptLayout (*acceptWsAfterAlignments)(BOX_OptLayout), BOX_SpaceOptionOptions (*acceptOptions)(BOX_SpaceOptionOptions), BOX_OptLayout (*acceptWsAfterH)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterV)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterHV)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterHOV)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterI)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterF)(BOX_OptLayout), BOX_FontOptionList (*acceptList)(BOX_FontOptionList));
BOX_GroupOptionGroupOptions BOX_visitGroupOptionGroupOptions(BOX_GroupOptionGroupOptions arg, BOX_GroupOption (*acceptHead)(BOX_GroupOption), BOX_OptLayout (*acceptWsAfterHead)(BOX_OptLayout));
BOX_LexNatCon BOX_visitLexNatCon(BOX_LexNatCon arg, char* (*acceptList)(char*));
BOX_NatCon BOX_visitNatCon(BOX_NatCon arg, BOX_LexNatCon (*acceptNatCon)(BOX_LexNatCon));
BOX_AlignmentOption BOX_visitAlignmentOption(BOX_AlignmentOption arg, BOX_OptLayout (*acceptWsAfterL)(BOX_OptLayout), BOX_SpaceOptionOptions (*acceptOptions)(BOX_SpaceOptionOptions), BOX_OptLayout (*acceptWsAfterC)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterR)(BOX_OptLayout));
BOX_AlignmentOptions BOX_visitAlignmentOptions(BOX_AlignmentOptions arg, BOX_OptLayout (*acceptWsAfterParenOpen)(BOX_OptLayout), BOX_AlignmentOptionList (*acceptList)(BOX_AlignmentOptionList), BOX_OptLayout (*acceptWsAfterList)(BOX_OptLayout));
BOX_SpaceOptionOptions BOX_visitSpaceOptionOptions(BOX_SpaceOptionOptions arg, BOX_SpaceOption (*acceptHead)(BOX_SpaceOption), BOX_OptLayout (*acceptWsAfterHead)(BOX_OptLayout));
BOX_AlignmentOptionList BOX_visitAlignmentOptionList(BOX_AlignmentOptionList arg, BOX_AlignmentOption (*acceptHead)(BOX_AlignmentOption), BOX_OptLayout (*acceptWsAfterHead)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterSep)(BOX_OptLayout));
BOX_SpaceSymbol BOX_visitSpaceSymbol(BOX_SpaceSymbol arg);
BOX_SpaceOption BOX_visitSpaceOption(BOX_SpaceOption arg, BOX_SpaceSymbol (*acceptSpaceSymbol)(BOX_SpaceSymbol), BOX_OptLayout (*acceptWsAfterSpaceSymbol)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterEquals)(BOX_OptLayout), BOX_NatCon (*acceptNatCon)(BOX_NatCon));
BOX_Box BOX_visitBox(BOX_Box arg, BOX_StrCon (*acceptStrCon)(BOX_StrCon), BOX_BoxOperator (*acceptOperator)(BOX_BoxOperator), BOX_OptLayout (*acceptWsAfterOperator)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterBracketOpen)(BOX_OptLayout), BOX_BoxList (*acceptList)(BOX_BoxList), BOX_OptLayout (*acceptWsAfterList)(BOX_OptLayout));
BOX_BoxList BOX_visitBoxList(BOX_BoxList arg, BOX_Box (*acceptHead)(BOX_Box), BOX_OptLayout (*acceptWsAfterHead)(BOX_OptLayout));
BOX_LexLayout BOX_visitLexLayout(BOX_LexLayout arg, char (*acceptCh)(char), char* (*acceptLine)(char*), char* (*acceptContent)(char*));
BOX_LexFontId BOX_visitLexFontId(BOX_LexFontId arg, char* (*acceptList)(char*));
BOX_FontId BOX_visitFontId(BOX_FontId arg, BOX_LexFontId (*acceptFontId)(BOX_LexFontId));
BOX_FontValue BOX_visitFontValue(BOX_FontValue arg, BOX_NatCon (*acceptNatCon)(BOX_NatCon), BOX_FontId (*acceptFontId)(BOX_FontId));
BOX_FontOption BOX_visitFontOption(BOX_FontOption arg, BOX_FontParam (*acceptFontParam)(BOX_FontParam), BOX_OptLayout (*acceptWsAfterFontParam)(BOX_OptLayout), BOX_OptLayout (*acceptWsAfterEquals)(BOX_OptLayout), BOX_FontValue (*acceptFontValue)(BOX_FontValue));
BOX_FontParam BOX_visitFontParam(BOX_FontParam arg);
BOX_FontOperator BOX_visitFontOperator(BOX_FontOperator arg);
BOX_FontOptionList BOX_visitFontOptionList(BOX_FontOptionList arg, BOX_FontOption (*acceptHead)(BOX_FontOption), BOX_OptLayout (*acceptWsAfterHead)(BOX_OptLayout));
BOX_LexStrChar BOX_visitLexStrChar(BOX_LexStrChar arg, char (*acceptA)(char), char (*acceptB)(char), char (*acceptC)(char), char (*acceptCh)(char));
BOX_StrChar BOX_visitStrChar(BOX_StrChar arg, BOX_LexStrChar (*acceptStrChar)(BOX_LexStrChar));
BOX_LexStrCon BOX_visitLexStrCon(BOX_LexStrCon arg, BOX_LexStrCharChars (*acceptChars)(BOX_LexStrCharChars));
BOX_StrCon BOX_visitStrCon(BOX_StrCon arg, BOX_LexStrCon (*acceptStrCon)(BOX_LexStrCon));
BOX_LexStrCharChars BOX_visitLexStrCharChars(BOX_LexStrCharChars arg, BOX_LexStrChar (*acceptHead)(BOX_LexStrChar));

#endif /* _BOX_H */
