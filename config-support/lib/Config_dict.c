#include "Config_dict.h"

AFun CFG_afun17;
AFun CFG_afun22;
AFun CFG_afun3;
AFun CFG_afun9;
AFun CFG_afun34;
AFun CFG_afun19;
AFun CFG_afun26;
AFun CFG_afun2;
AFun CFG_afun12;
AFun CFG_afun15;
AFun CFG_afun25;
AFun CFG_afun18;
AFun CFG_afun20;
AFun CFG_afun31;
AFun CFG_afun8;
AFun CFG_afun28;
AFun CFG_afun21;
AFun CFG_afun32;
AFun CFG_afun0;
AFun CFG_afun11;
AFun CFG_afun5;
AFun CFG_afun27;
AFun CFG_afun33;
AFun CFG_afun16;
AFun CFG_afun10;
AFun CFG_afun13;
AFun CFG_afun4;
AFun CFG_afun14;
AFun CFG_afun23;
AFun CFG_afun30;
AFun CFG_afun7;
AFun CFG_afun24;
AFun CFG_afun29;
AFun CFG_afun1;
AFun CFG_afun6;

ATerm CFG_patternColorRgb = NULL;
ATerm CFG_patternTextStyleUnderlined = NULL;
ATerm CFG_patternTextStyleItalics = NULL;
ATerm CFG_patternTextStyleBold = NULL;
ATerm CFG_patternTextAttributeSize = NULL;
ATerm CFG_patternTextAttributeFont = NULL;
ATerm CFG_patternTextAttributeStyle = NULL;
ATerm CFG_patternTextAttributeBackgroundColor = NULL;
ATerm CFG_patternTextAttributeForegroundColor = NULL;
ATerm CFG_patternTextAttributesMany = NULL;
ATerm CFG_patternTextAttributesSingle = NULL;
ATerm CFG_patternTextAttributesEmpty = NULL;
ATerm CFG_patternTextCategoryNameExtern = NULL;
ATerm CFG_patternTextCategoryNameNormal = NULL;
ATerm CFG_patternTextCategoryNameSelection = NULL;
ATerm CFG_patternTextCategoryNameFocus = NULL;
ATerm CFG_patternModuleNameWildcard = NULL;
ATerm CFG_patternItemsMany = NULL;
ATerm CFG_patternItemsSingle = NULL;
ATerm CFG_patternItemsEmpty = NULL;
ATerm CFG_patternEventShortcut = NULL;
ATerm CFG_patternEventDefault = NULL;
ATerm CFG_patternEventIcon = NULL;
ATerm CFG_patternEventClick = NULL;
ATerm CFG_patternActionTypeWildcard = NULL;
ATerm CFG_patternActionTypeStudioToolbar = NULL;
ATerm CFG_patternActionTypeStudioMenubar = NULL;
ATerm CFG_patternActionTypeNewModulePopup = NULL;
ATerm CFG_patternActionTypeModulePopup = NULL;
ATerm CFG_patternActionTypeTreePanel = NULL;
ATerm CFG_patternActionTypeFeedbackList = NULL;
ATerm CFG_patternActionTypeSyntaxEditor = NULL;
ATerm CFG_patternActionTypeEquationsEditor = NULL;
ATerm CFG_patternActionTypeTermEditorForModule = NULL;
ATerm CFG_patternActionTypeTermEditor = NULL;
ATerm CFG_patternActionDescriptionListMany = NULL;
ATerm CFG_patternActionDescriptionListSingle = NULL;
ATerm CFG_patternActionDescriptionListEmpty = NULL;
ATerm CFG_patternActionDescriptionDefault = NULL;
ATerm CFG_patternPropertyTextCategory = NULL;
ATerm CFG_patternPropertyModulePath = NULL;
ATerm CFG_patternPropertyLibraryPath = NULL;
ATerm CFG_patternPropertyExtension = NULL;
ATerm CFG_patternPropertyAction = NULL;
ATerm CFG_patternPropertiesMany = NULL;
ATerm CFG_patternPropertiesSingle = NULL;
ATerm CFG_patternPropertiesEmpty = NULL;
ATerm CFG_patternConfigurationList = NULL;

/*
 * CFG_afun17 = "*"
 * CFG_afun22 = focus
 * CFG_afun3 = library-path(x)
 * CFG_afun9 = equations-editor
 * CFG_afun34 = rgb(x,x,x)
 * CFG_afun19 = icon(x,x)
 * CFG_afun26 = foreground-color(x)
 * CFG_afun2 = extension(x,x)
 * CFG_afun12 = tree-panel
 * CFG_afun15 = studio-menubar
 * CFG_afun25 = extern(x)
 * CFG_afun18 = click
 * CFG_afun20 = menu(x)
 * CFG_afun31 = bold
 * CFG_afun8 = term-editor(x)
 * CFG_afun28 = style(x)
 * CFG_afun21 = menu(x,x)
 * CFG_afun32 = italics
 * CFG_afun0 = configuration(x)
 * CFG_afun11 = feedback-list
 * CFG_afun5 = text-category(x,x)
 * CFG_afun27 = background-color(x)
 * CFG_afun33 = underlined
 * CFG_afun16 = studio-toolbar
 * CFG_afun10 = syntax-editor
 * CFG_afun13 = module-popup(x)
 * CFG_afun4 = module-path(x)
 * CFG_afun14 = new-module-popup
 * CFG_afun23 = selection
 * CFG_afun30 = size(x)
 * CFG_afun7 = term-editor
 * CFG_afun24 = normal
 * CFG_afun29 = font(x)
 * CFG_afun1 = action(x,x)
 * CFG_afun6 = description(x,x)
 *
 * CFG_patternColorRgb = rgb(<int>,<int>,<int>)
 * CFG_patternTextStyleUnderlined = underlined
 * CFG_patternTextStyleItalics = italics
 * CFG_patternTextStyleBold = bold
 * CFG_patternTextAttributeSize = size(<int>)
 * CFG_patternTextAttributeFont = font(<str>)
 * CFG_patternTextAttributeStyle = style(<term>)
 * CFG_patternTextAttributeBackgroundColor = background-color(<term>)
 * CFG_patternTextAttributeForegroundColor = foreground-color(<term>)
 * CFG_patternTextAttributesMany = [<term>,<list>]
 * CFG_patternTextAttributesSingle = [<term>]
 * CFG_patternTextAttributesEmpty = []
 * CFG_patternTextCategoryNameExtern = extern(<str>)
 * CFG_patternTextCategoryNameNormal = normal
 * CFG_patternTextCategoryNameSelection = selection
 * CFG_patternTextCategoryNameFocus = focus
 * CFG_patternModuleNameWildcard = "*"
 * CFG_patternItemsMany = [<str>,<list>]
 * CFG_patternItemsSingle = [<str>]
 * CFG_patternItemsEmpty = []
 * CFG_patternEventShortcut = menu(<term>,<str>)
 * CFG_patternEventDefault = menu(<term>)
 * CFG_patternEventIcon = icon(<str>,<str>)
 * CFG_patternEventClick = click
 * CFG_patternActionTypeWildcard = "*"
 * CFG_patternActionTypeStudioToolbar = studio-toolbar
 * CFG_patternActionTypeStudioMenubar = studio-menubar
 * CFG_patternActionTypeNewModulePopup = new-module-popup
 * CFG_patternActionTypeModulePopup = module-popup(<str>)
 * CFG_patternActionTypeTreePanel = tree-panel
 * CFG_patternActionTypeFeedbackList = feedback-list
 * CFG_patternActionTypeSyntaxEditor = syntax-editor
 * CFG_patternActionTypeEquationsEditor = equations-editor
 * CFG_patternActionTypeTermEditorForModule = term-editor(<str>)
 * CFG_patternActionTypeTermEditor = term-editor
 * CFG_patternActionDescriptionListMany = [<term>,<list>]
 * CFG_patternActionDescriptionListSingle = [<term>]
 * CFG_patternActionDescriptionListEmpty = []
 * CFG_patternActionDescriptionDefault = description(<term>,<term>)
 * CFG_patternPropertyTextCategory = text-category(<term>,<term>)
 * CFG_patternPropertyModulePath = module-path(<str>)
 * CFG_patternPropertyLibraryPath = library-path(<str>)
 * CFG_patternPropertyExtension = extension(<str>,<str>)
 * CFG_patternPropertyAction = action(<term>,<str>)
 * CFG_patternPropertiesMany = [<term>,<list>]
 * CFG_patternPropertiesSingle = [<term>]
 * CFG_patternPropertiesEmpty = []
 * CFG_patternConfigurationList = configuration(<term>)
 *
 */

static ATerm _Config_dict = NULL;

#define _Config_dict_LEN 861

static char _Config_dict_baf[_Config_dict_LEN] = {
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

void init_Config_dict()
{
  ATermList afuns, terms;

  _Config_dict = ATreadFromBinaryString(_Config_dict_baf, _Config_dict_LEN);

  ATprotect(&_Config_dict);

  afuns = (ATermList)ATelementAt((ATermList)_Config_dict, 0);

  CFG_afun17 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  CFG_afun22 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  CFG_afun3 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  CFG_afun9 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  CFG_afun34 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  CFG_afun19 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  CFG_afun26 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  CFG_afun2 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  CFG_afun12 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  CFG_afun15 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  CFG_afun25 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  CFG_afun18 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  CFG_afun20 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  CFG_afun31 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  CFG_afun8 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  CFG_afun28 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  CFG_afun21 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  CFG_afun32 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  CFG_afun0 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  CFG_afun11 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  CFG_afun5 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  CFG_afun27 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  CFG_afun33 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  CFG_afun16 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  CFG_afun10 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  CFG_afun13 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  CFG_afun4 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  CFG_afun14 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  CFG_afun23 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  CFG_afun30 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  CFG_afun7 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  CFG_afun24 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  CFG_afun29 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  CFG_afun1 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  CFG_afun6 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);

  terms = (ATermList)ATelementAt((ATermList)_Config_dict, 1);

  CFG_patternColorRgb = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternTextStyleUnderlined = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternTextStyleItalics = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternTextStyleBold = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternTextAttributeSize = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternTextAttributeFont = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternTextAttributeStyle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternTextAttributeBackgroundColor = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternTextAttributeForegroundColor = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternTextAttributesMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternTextAttributesSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternTextAttributesEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternTextCategoryNameExtern = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternTextCategoryNameNormal = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternTextCategoryNameSelection = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternTextCategoryNameFocus = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternModuleNameWildcard = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternItemsMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternItemsSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternItemsEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternEventShortcut = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternEventDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternEventIcon = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternEventClick = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternActionTypeWildcard = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternActionTypeStudioToolbar = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternActionTypeStudioMenubar = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternActionTypeNewModulePopup = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternActionTypeModulePopup = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternActionTypeTreePanel = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternActionTypeFeedbackList = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternActionTypeSyntaxEditor = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternActionTypeEquationsEditor = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternActionTypeTermEditorForModule = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternActionTypeTermEditor = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternActionDescriptionListMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternActionDescriptionListSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternActionDescriptionListEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternActionDescriptionDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternPropertyTextCategory = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternPropertyModulePath = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternPropertyLibraryPath = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternPropertyExtension = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternPropertyAction = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternPropertiesMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternPropertiesSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternPropertiesEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  CFG_patternConfigurationList = ATgetFirst(terms);
  terms = ATgetNext(terms);
}
