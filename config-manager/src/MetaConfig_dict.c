#include "MetaConfig_dict.h"

AFun MC_afun17;
AFun MC_afun22;
AFun MC_afun3;
AFun MC_afun9;
AFun MC_afun34;
AFun MC_afun19;
AFun MC_afun26;
AFun MC_afun2;
AFun MC_afun12;
AFun MC_afun15;
AFun MC_afun25;
AFun MC_afun18;
AFun MC_afun20;
AFun MC_afun31;
AFun MC_afun8;
AFun MC_afun28;
AFun MC_afun21;
AFun MC_afun32;
AFun MC_afun0;
AFun MC_afun11;
AFun MC_afun5;
AFun MC_afun27;
AFun MC_afun33;
AFun MC_afun16;
AFun MC_afun10;
AFun MC_afun13;
AFun MC_afun4;
AFun MC_afun14;
AFun MC_afun23;
AFun MC_afun30;
AFun MC_afun7;
AFun MC_afun24;
AFun MC_afun29;
AFun MC_afun1;
AFun MC_afun6;

ATerm MC_patternColorRgb = NULL;
ATerm MC_patternTextStyleUnderlined = NULL;
ATerm MC_patternTextStyleItalics = NULL;
ATerm MC_patternTextStyleBold = NULL;
ATerm MC_patternTextAttributeSize = NULL;
ATerm MC_patternTextAttributeFont = NULL;
ATerm MC_patternTextAttributeStyle = NULL;
ATerm MC_patternTextAttributeBackgroundColor = NULL;
ATerm MC_patternTextAttributeForegroundColor = NULL;
ATerm MC_patternTextAttributesMany = NULL;
ATerm MC_patternTextAttributesSingle = NULL;
ATerm MC_patternTextAttributesEmpty = NULL;
ATerm MC_patternTextCategoryNameExtern = NULL;
ATerm MC_patternTextCategoryNameNormal = NULL;
ATerm MC_patternTextCategoryNameSelection = NULL;
ATerm MC_patternTextCategoryNameFocus = NULL;
ATerm MC_patternModuleNameWildcard = NULL;
ATerm MC_patternItemsMany = NULL;
ATerm MC_patternItemsSingle = NULL;
ATerm MC_patternItemsEmpty = NULL;
ATerm MC_patternEventShortcut = NULL;
ATerm MC_patternEventDefault = NULL;
ATerm MC_patternEventIcon = NULL;
ATerm MC_patternEventClick = NULL;
ATerm MC_patternActionTypeWildcard = NULL;
ATerm MC_patternActionTypeStudioToolbar = NULL;
ATerm MC_patternActionTypeStudioMenubar = NULL;
ATerm MC_patternActionTypeNewModulePopup = NULL;
ATerm MC_patternActionTypeModulePopup = NULL;
ATerm MC_patternActionTypeTreePanel = NULL;
ATerm MC_patternActionTypeFeedbackList = NULL;
ATerm MC_patternActionTypeSyntaxEditor = NULL;
ATerm MC_patternActionTypeEquationsEditor = NULL;
ATerm MC_patternActionTypeTermEditorForModule = NULL;
ATerm MC_patternActionTypeTermEditor = NULL;
ATerm MC_patternActionDescriptionListMany = NULL;
ATerm MC_patternActionDescriptionListSingle = NULL;
ATerm MC_patternActionDescriptionListEmpty = NULL;
ATerm MC_patternActionDescriptionDefault = NULL;
ATerm MC_patternPropertyTextCategory = NULL;
ATerm MC_patternPropertyModulePath = NULL;
ATerm MC_patternPropertyLibraryPath = NULL;
ATerm MC_patternPropertyExtension = NULL;
ATerm MC_patternPropertyAction = NULL;
ATerm MC_patternPropertiesMany = NULL;
ATerm MC_patternPropertiesSingle = NULL;
ATerm MC_patternPropertiesEmpty = NULL;
ATerm MC_patternConfigurationList = NULL;

/*
 * MC_afun17 = "*"
 * MC_afun22 = focus
 * MC_afun3 = library-path(x)
 * MC_afun9 = equations-editor
 * MC_afun34 = rgb(x,x,x)
 * MC_afun19 = icon(x,x)
 * MC_afun26 = foreground-color(x)
 * MC_afun2 = extension(x,x)
 * MC_afun12 = tree-panel
 * MC_afun15 = studio-menubar
 * MC_afun25 = extern(x)
 * MC_afun18 = click
 * MC_afun20 = menu(x)
 * MC_afun31 = bold
 * MC_afun8 = term-editor(x)
 * MC_afun28 = style(x)
 * MC_afun21 = menu(x,x)
 * MC_afun32 = italics
 * MC_afun0 = configuration(x)
 * MC_afun11 = feedback-list
 * MC_afun5 = text-category(x,x)
 * MC_afun27 = background-color(x)
 * MC_afun33 = underlined
 * MC_afun16 = studio-toolbar
 * MC_afun10 = syntax-editor
 * MC_afun13 = module-popup(x)
 * MC_afun4 = module-path(x)
 * MC_afun14 = new-module-popup
 * MC_afun23 = selection
 * MC_afun30 = size(x)
 * MC_afun7 = term-editor
 * MC_afun24 = normal
 * MC_afun29 = font(x)
 * MC_afun1 = action(x,x)
 * MC_afun6 = description(x,x)
 *
 * MC_patternColorRgb = rgb(<int>,<int>,<int>)
 * MC_patternTextStyleUnderlined = underlined
 * MC_patternTextStyleItalics = italics
 * MC_patternTextStyleBold = bold
 * MC_patternTextAttributeSize = size(<int>)
 * MC_patternTextAttributeFont = font(<str>)
 * MC_patternTextAttributeStyle = style(<term>)
 * MC_patternTextAttributeBackgroundColor = background-color(<term>)
 * MC_patternTextAttributeForegroundColor = foreground-color(<term>)
 * MC_patternTextAttributesMany = [<term>,<list>]
 * MC_patternTextAttributesSingle = [<term>]
 * MC_patternTextAttributesEmpty = []
 * MC_patternTextCategoryNameExtern = extern(<str>)
 * MC_patternTextCategoryNameNormal = normal
 * MC_patternTextCategoryNameSelection = selection
 * MC_patternTextCategoryNameFocus = focus
 * MC_patternModuleNameWildcard = "*"
 * MC_patternItemsMany = [<str>,<list>]
 * MC_patternItemsSingle = [<str>]
 * MC_patternItemsEmpty = []
 * MC_patternEventShortcut = menu(<term>,<str>)
 * MC_patternEventDefault = menu(<term>)
 * MC_patternEventIcon = icon(<str>,<str>)
 * MC_patternEventClick = click
 * MC_patternActionTypeWildcard = "*"
 * MC_patternActionTypeStudioToolbar = studio-toolbar
 * MC_patternActionTypeStudioMenubar = studio-menubar
 * MC_patternActionTypeNewModulePopup = new-module-popup
 * MC_patternActionTypeModulePopup = module-popup(<str>)
 * MC_patternActionTypeTreePanel = tree-panel
 * MC_patternActionTypeFeedbackList = feedback-list
 * MC_patternActionTypeSyntaxEditor = syntax-editor
 * MC_patternActionTypeEquationsEditor = equations-editor
 * MC_patternActionTypeTermEditorForModule = term-editor(<str>)
 * MC_patternActionTypeTermEditor = term-editor
 * MC_patternActionDescriptionListMany = [<term>,<list>]
 * MC_patternActionDescriptionListSingle = [<term>]
 * MC_patternActionDescriptionListEmpty = []
 * MC_patternActionDescriptionDefault = description(<term>,<term>)
 * MC_patternPropertyTextCategory = text-category(<term>,<term>)
 * MC_patternPropertyModulePath = module-path(<str>)
 * MC_patternPropertyLibraryPath = library-path(<str>)
 * MC_patternPropertyExtension = extension(<str>,<str>)
 * MC_patternPropertyAction = action(<term>,<str>)
 * MC_patternPropertiesMany = [<term>,<list>]
 * MC_patternPropertiesSingle = [<term>]
 * MC_patternPropertiesEmpty = []
 * MC_patternConfigurationList = configuration(<term>)
 *
 */

static ATerm _MetaConfig_dict = NULL;

#define _MetaConfig_dict_LEN 861

static char _MetaConfig_dict_baf[_MetaConfig_dict_LEN] = {
0x00,0x8B,0xAF,0x83,0x00,0x2B,0x80,0x9A,0x03,0x3C,0x5F,0x3E,0x01,0x00,0x04,0x04,
0x05,0x06,0x04,0x03,0x05,0x5B,0x5F,0x2C,0x5F,0x5D,0x02,0x00,0x5A,0x26,0x01,0x02,
0x00,0x07,0x08,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x16,
0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,0x20,0x21,0x22,0x23,0x24,0x25,0x26,
0x27,0x28,0x29,0x2A,0x02,0x01,0x02,0x02,0x5B,0x5D,0x00,0x00,0x01,0x03,0x69,0x6E,
0x74,0x00,0x00,0x01,0x03,0x73,0x74,0x72,0x00,0x00,0x01,0x04,0x6C,0x69,0x73,0x74,
0x00,0x00,0x01,0x04,0x74,0x65,0x72,0x6D,0x00,0x00,0x01,0x01,0x2A,0x00,0x01,0x01,
0x05,0x66,0x6F,0x63,0x75,0x73,0x00,0x00,0x01,0x01,0x78,0x00,0x00,0x01,0x0C,0x6C,
0x69,0x62,0x72,0x61,0x72,0x79,0x2D,0x70,0x61,0x74,0x68,0x01,0x00,0x02,0x02,0x00,
0x09,0x10,0x65,0x71,0x75,0x61,0x74,0x69,0x6F,0x6E,0x73,0x2D,0x65,0x64,0x69,0x74,
0x6F,0x72,0x00,0x00,0x01,0x03,0x72,0x67,0x62,0x03,0x00,0x02,0x02,0x00,0x09,0x02,
0x00,0x09,0x02,0x00,0x09,0x04,0x69,0x63,0x6F,0x6E,0x02,0x00,0x02,0x02,0x00,0x09,
0x02,0x00,0x09,0x10,0x66,0x6F,0x72,0x65,0x67,0x72,0x6F,0x75,0x6E,0x64,0x2D,0x63,
0x6F,0x6C,0x6F,0x72,0x01,0x00,0x02,0x02,0x00,0x09,0x09,0x65,0x78,0x74,0x65,0x6E,
0x73,0x69,0x6F,0x6E,0x02,0x00,0x02,0x02,0x00,0x09,0x02,0x00,0x09,0x0A,0x74,0x72,
0x65,0x65,0x2D,0x70,0x61,0x6E,0x65,0x6C,0x00,0x00,0x01,0x0E,0x73,0x74,0x75,0x64,
0x69,0x6F,0x2D,0x6D,0x65,0x6E,0x75,0x62,0x61,0x72,0x00,0x00,0x01,0x06,0x65,0x78,
0x74,0x65,0x72,0x6E,0x01,0x00,0x02,0x02,0x00,0x09,0x05,0x63,0x6C,0x69,0x63,0x6B,
0x00,0x00,0x01,0x04,0x6D,0x65,0x6E,0x75,0x01,0x00,0x02,0x02,0x00,0x09,0x04,0x62,
0x6F,0x6C,0x64,0x00,0x00,0x01,0x0B,0x74,0x65,0x72,0x6D,0x2D,0x65,0x64,0x69,0x74,
0x6F,0x72,0x01,0x00,0x02,0x02,0x00,0x09,0x05,0x73,0x74,0x79,0x6C,0x65,0x01,0x00,
0x02,0x02,0x00,0x09,0x04,0x6D,0x65,0x6E,0x75,0x02,0x00,0x02,0x02,0x00,0x09,0x02,
0x00,0x09,0x07,0x69,0x74,0x61,0x6C,0x69,0x63,0x73,0x00,0x00,0x01,0x0D,0x63,0x6F,
0x6E,0x66,0x69,0x67,0x75,0x72,0x61,0x74,0x69,0x6F,0x6E,0x01,0x00,0x02,0x02,0x00,
0x09,0x0D,0x66,0x65,0x65,0x64,0x62,0x61,0x63,0x6B,0x2D,0x6C,0x69,0x73,0x74,0x00,
0x00,0x01,0x0D,0x74,0x65,0x78,0x74,0x2D,0x63,0x61,0x74,0x65,0x67,0x6F,0x72,0x79,
0x02,0x00,0x02,0x02,0x00,0x09,0x02,0x00,0x09,0x10,0x62,0x61,0x63,0x6B,0x67,0x72,
0x6F,0x75,0x6E,0x64,0x2D,0x63,0x6F,0x6C,0x6F,0x72,0x01,0x00,0x02,0x02,0x00,0x09,
0x0A,0x75,0x6E,0x64,0x65,0x72,0x6C,0x69,0x6E,0x65,0x64,0x00,0x00,0x01,0x0E,0x73,
0x74,0x75,0x64,0x69,0x6F,0x2D,0x74,0x6F,0x6F,0x6C,0x62,0x61,0x72,0x00,0x00,0x01,
0x0D,0x73,0x79,0x6E,0x74,0x61,0x78,0x2D,0x65,0x64,0x69,0x74,0x6F,0x72,0x00,0x00,
0x01,0x0C,0x6D,0x6F,0x64,0x75,0x6C,0x65,0x2D,0x70,0x6F,0x70,0x75,0x70,0x01,0x00,
0x02,0x02,0x00,0x09,0x0B,0x6D,0x6F,0x64,0x75,0x6C,0x65,0x2D,0x70,0x61,0x74,0x68,
0x01,0x00,0x02,0x02,0x00,0x09,0x10,0x6E,0x65,0x77,0x2D,0x6D,0x6F,0x64,0x75,0x6C,
0x65,0x2D,0x70,0x6F,0x70,0x75,0x70,0x00,0x00,0x01,0x09,0x73,0x65,0x6C,0x65,0x63,
0x74,0x69,0x6F,0x6E,0x00,0x00,0x01,0x04,0x73,0x69,0x7A,0x65,0x01,0x00,0x02,0x02,
0x00,0x09,0x0B,0x74,0x65,0x72,0x6D,0x2D,0x65,0x64,0x69,0x74,0x6F,0x72,0x00,0x00,
0x01,0x06,0x6E,0x6F,0x72,0x6D,0x61,0x6C,0x00,0x00,0x01,0x04,0x66,0x6F,0x6E,0x74,
0x01,0x00,0x02,0x02,0x00,0x09,0x06,0x61,0x63,0x74,0x69,0x6F,0x6E,0x02,0x00,0x02,
0x02,0x00,0x09,0x02,0x00,0x09,0x0B,0x64,0x65,0x73,0x63,0x72,0x69,0x70,0x74,0x69,
0x6F,0x6E,0x02,0x00,0x02,0x02,0x00,0x09,0x02,0x00,0x09,0x01,0x01,0x16,0x04,0x22,
0x00,0x54,0x11,0xF1,0x81,0xE7,0x05,0x45,0xC1,0x0A,0x0E,0x48,0x46,0xC5,0x0A,0x16,
0x68,0x4C,0x30,0x19,0x61,0x1D,0x1C,0x1A,0x78,0x45,0x40,0x82,0x91,0x11,0x91,0x22,
0x12,0x64,0x51,0x10,0xA0,0x25,0x44,0x78,0x68,0x71,0xD1,0x45,0x81,0x88,0x31,0x31,
0xA1,0x61,0x46,0xC4,0x83,0x88,0x11,0x71,0x1C,0x1E,0x18,0x7C,0x50,0x04,0x82,0x10,
0x98,0x11,0x10,0x62,0x44,0x02,0x4A,0x00,0x52,0x54,0x0D,0x03,0xAF,0x10,0x30,0x00,
0x35,0x98,0xAA,0x50,0x54,0x23,0x28,0x30,0x04,0xB8,0xC4,0x44,0x54,0xA1,0x40,0x28,
0xD0,0x8F,0x32,0x42,0x1C,0x80,0x49,0x04,0x62,0x43,0x08,0xB2,0x05,0x24,0x14,0x19,
0x80,0xD3,0x64,0x41,0x4A,0x24,0x9F,0x81,0x24,0x1C,0x70,0x18,0x80,0xC9,0x08,0x62,
0x28,0x81,0xC9,0x09,0x04,0x60,0x30,0xE5,0x08,0x82,0x1F,0x21,0x10,0x44,0x88,0x40,
0x0B,0x87,0xEC,0x07,0xCB,0x17,0x8C,0x0F,0x3C,0x6E,0x3A,0x20,0xBB,0x42,0x73,0x40,
0xED,0x8E,0xCC,0x0D,0xA2,0x88,0x56,0x84,0x2C,0x01,0x23,0x30,0x14,0x84,0xD0,0x11,
0xA9,0x84,0x20,0x37,0x50,0x84,0x7A,0xBA,0x20,0xEA,0x88,0x85,0xA5,0x22,0x10,0x34,
0x4C,0x22,0x1A,0x80,0x24,0x2A,0x02,0x91,0x2A,0x00,0x55,0x50,0xA8
};

void init_MetaConfig_dict()
{
  ATermList afuns, terms;

  _MetaConfig_dict = ATreadFromBinaryString(_MetaConfig_dict_baf, _MetaConfig_dict_LEN);

  ATprotect(&_MetaConfig_dict);

  afuns = (ATermList)ATelementAt((ATermList)_MetaConfig_dict, 0);

  MC_afun17 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun22 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun3 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun9 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun34 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun19 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun26 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun2 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun12 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun15 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun25 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun18 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun20 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun31 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun8 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun28 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun21 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun32 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun0 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun11 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun5 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun27 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun33 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun16 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun10 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun13 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun4 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun14 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun23 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun30 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun7 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun24 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun29 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun1 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun6 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);

  terms = (ATermList)ATelementAt((ATermList)_MetaConfig_dict, 1);

  MC_patternColorRgb = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternTextStyleUnderlined = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternTextStyleItalics = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternTextStyleBold = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternTextAttributeSize = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternTextAttributeFont = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternTextAttributeStyle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternTextAttributeBackgroundColor = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternTextAttributeForegroundColor = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternTextAttributesMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternTextAttributesSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternTextAttributesEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternTextCategoryNameExtern = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternTextCategoryNameNormal = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternTextCategoryNameSelection = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternTextCategoryNameFocus = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternModuleNameWildcard = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternItemsMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternItemsSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternItemsEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternEventShortcut = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternEventDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternEventIcon = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternEventClick = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternActionTypeWildcard = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternActionTypeStudioToolbar = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternActionTypeStudioMenubar = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternActionTypeNewModulePopup = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternActionTypeModulePopup = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternActionTypeTreePanel = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternActionTypeFeedbackList = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternActionTypeSyntaxEditor = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternActionTypeEquationsEditor = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternActionTypeTermEditorForModule = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternActionTypeTermEditor = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternActionDescriptionListMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternActionDescriptionListSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternActionDescriptionListEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternActionDescriptionDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternPropertyTextCategory = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternPropertyModulePath = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternPropertyLibraryPath = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternPropertyExtension = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternPropertyAction = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternPropertiesMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternPropertiesSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternPropertiesEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternConfigurationList = ATgetFirst(terms);
  terms = ATgetNext(terms);
}
