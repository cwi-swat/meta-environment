#include "MetaConfig_dict.h"

AFun MC_afun8;
AFun MC_afun17;
AFun MC_afun0;
AFun MC_afun11;
AFun MC_afun5;
AFun MC_afun3;
AFun MC_afun9;
AFun MC_afun16;
AFun MC_afun10;
AFun MC_afun4;
AFun MC_afun13;
AFun MC_afun14;
AFun MC_afun2;
AFun MC_afun7;
AFun MC_afun12;
AFun MC_afun15;
AFun MC_afun6;
AFun MC_afun1;

ATerm MC_patternModuleNameWildcard = NULL;
ATerm MC_patternItemsMany = NULL;
ATerm MC_patternItemsSingle = NULL;
ATerm MC_patternItemsEmpty = NULL;
ATerm MC_patternActionListMany = NULL;
ATerm MC_patternActionListSingle = NULL;
ATerm MC_patternActionListEmpty = NULL;
ATerm MC_patternMenuShortcut = NULL;
ATerm MC_patternMenuDefault = NULL;
ATerm MC_patternButtonArgsIcon = NULL;
ATerm MC_patternButtonArgsClick = NULL;
ATerm MC_patternButtonTypeWildcard = NULL;
ATerm MC_patternButtonTypeStudioToolbar = NULL;
ATerm MC_patternButtonTypeStudioMenubar = NULL;
ATerm MC_patternButtonTypeNewModulePopup = NULL;
ATerm MC_patternButtonTypeModulePopup = NULL;
ATerm MC_patternButtonTypeTreePanel = NULL;
ATerm MC_patternButtonTypeFeedbackList = NULL;
ATerm MC_patternButtonTypeSyntaxEditor = NULL;
ATerm MC_patternButtonTypeEquationsEditor = NULL;
ATerm MC_patternButtonTypeTermEditor = NULL;
ATerm MC_patternButtonDescriptionDefault = NULL;
ATerm MC_patternButtonDescriptionListMany = NULL;
ATerm MC_patternButtonDescriptionListSingle = NULL;
ATerm MC_patternButtonDescriptionListEmpty = NULL;
ATerm MC_patternPropertyExtension = NULL;
ATerm MC_patternPropertyButton = NULL;
ATerm MC_patternPropertiesMany = NULL;
ATerm MC_patternPropertiesSingle = NULL;
ATerm MC_patternPropertiesEmpty = NULL;
ATerm MC_patternConfigurationList = NULL;

/*
 * MC_afun8 = tree-panel
 * MC_afun17 = menu-entry(x,x)
 * MC_afun0 = configuration(x)
 * MC_afun11 = studio-menubar
 * MC_afun5 = equations-editor
 * MC_afun3 = description(x,x)
 * MC_afun9 = module-popup
 * MC_afun16 = menu-entry(x)
 * MC_afun10 = new-module-popup
 * MC_afun4 = term-editor
 * MC_afun13 = "*"
 * MC_afun14 = click
 * MC_afun2 = extension(x,x)
 * MC_afun7 = feedback-list
 * MC_afun12 = studio-toolbar
 * MC_afun15 = icon(x,x)
 * MC_afun6 = syntax-editor
 * MC_afun1 = button(x,x,x)
 *
 * MC_patternModuleNameWildcard = "*"
 * MC_patternItemsMany = [<str>,<list>]
 * MC_patternItemsSingle = [<str>]
 * MC_patternItemsEmpty = []
 * MC_patternActionListMany = [<term>,<list>]
 * MC_patternActionListSingle = [<term>]
 * MC_patternActionListEmpty = []
 * MC_patternMenuShortcut = menu-entry(<term>,<str>)
 * MC_patternMenuDefault = menu-entry(<term>)
 * MC_patternButtonArgsIcon = icon(<str>,<str>)
 * MC_patternButtonArgsClick = click
 * MC_patternButtonTypeWildcard = "*"
 * MC_patternButtonTypeStudioToolbar = studio-toolbar
 * MC_patternButtonTypeStudioMenubar = studio-menubar
 * MC_patternButtonTypeNewModulePopup = new-module-popup
 * MC_patternButtonTypeModulePopup = module-popup
 * MC_patternButtonTypeTreePanel = tree-panel
 * MC_patternButtonTypeFeedbackList = feedback-list
 * MC_patternButtonTypeSyntaxEditor = syntax-editor
 * MC_patternButtonTypeEquationsEditor = equations-editor
 * MC_patternButtonTypeTermEditor = term-editor
 * MC_patternButtonDescriptionDefault = description(<term>,<term>)
 * MC_patternButtonDescriptionListMany = [<term>,<list>]
 * MC_patternButtonDescriptionListSingle = [<term>]
 * MC_patternButtonDescriptionListEmpty = []
 * MC_patternPropertyExtension = extension(<str>,<str>)
 * MC_patternPropertyButton = button(<str>,<term>,<term>)
 * MC_patternPropertiesMany = [<term>,<list>]
 * MC_patternPropertiesSingle = [<term>]
 * MC_patternPropertiesEmpty = []
 * MC_patternConfigurationList = configuration(<term>)
 *
 */

static ATerm _MetaConfig_dict = NULL;

#define _MetaConfig_dict_LEN 496

static char _MetaConfig_dict_baf[_MetaConfig_dict_LEN] = {
0x00,0x8B,0xAF,0x83,0x00,0x19,0x59,0x03,0x3C,0x5F,0x3E,0x01,0x00,0x03,0x03,0x05,
0x04,0x03,0x05,0x5B,0x5F,0x2C,0x5F,0x5D,0x02,0x00,0x38,0x15,0x01,0x02,0x00,0x06,
0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,
0x18,0x02,0x01,0x02,0x02,0x5B,0x5D,0x00,0x00,0x01,0x03,0x73,0x74,0x72,0x00,0x00,
0x01,0x04,0x6C,0x69,0x73,0x74,0x00,0x00,0x01,0x04,0x74,0x65,0x72,0x6D,0x00,0x00,
0x01,0x0A,0x74,0x72,0x65,0x65,0x2D,0x70,0x61,0x6E,0x65,0x6C,0x00,0x00,0x01,0x01,
0x78,0x00,0x00,0x01,0x0A,0x6D,0x65,0x6E,0x75,0x2D,0x65,0x6E,0x74,0x72,0x79,0x02,
0x00,0x02,0x02,0x00,0x07,0x02,0x00,0x07,0x0D,0x63,0x6F,0x6E,0x66,0x69,0x67,0x75,
0x72,0x61,0x74,0x69,0x6F,0x6E,0x01,0x00,0x02,0x02,0x00,0x07,0x0E,0x73,0x74,0x75,
0x64,0x69,0x6F,0x2D,0x6D,0x65,0x6E,0x75,0x62,0x61,0x72,0x00,0x00,0x01,0x10,0x65,
0x71,0x75,0x61,0x74,0x69,0x6F,0x6E,0x73,0x2D,0x65,0x64,0x69,0x74,0x6F,0x72,0x00,
0x00,0x01,0x0B,0x64,0x65,0x73,0x63,0x72,0x69,0x70,0x74,0x69,0x6F,0x6E,0x02,0x00,
0x02,0x02,0x00,0x07,0x02,0x00,0x07,0x0C,0x6D,0x6F,0x64,0x75,0x6C,0x65,0x2D,0x70,
0x6F,0x70,0x75,0x70,0x00,0x00,0x01,0x0A,0x6D,0x65,0x6E,0x75,0x2D,0x65,0x6E,0x74,
0x72,0x79,0x01,0x00,0x02,0x02,0x00,0x07,0x10,0x6E,0x65,0x77,0x2D,0x6D,0x6F,0x64,
0x75,0x6C,0x65,0x2D,0x70,0x6F,0x70,0x75,0x70,0x00,0x00,0x01,0x0B,0x74,0x65,0x72,
0x6D,0x2D,0x65,0x64,0x69,0x74,0x6F,0x72,0x00,0x00,0x01,0x01,0x2A,0x00,0x01,0x01,
0x05,0x63,0x6C,0x69,0x63,0x6B,0x00,0x00,0x01,0x09,0x65,0x78,0x74,0x65,0x6E,0x73,
0x69,0x6F,0x6E,0x02,0x00,0x02,0x02,0x00,0x07,0x02,0x00,0x07,0x0D,0x66,0x65,0x65,
0x64,0x62,0x61,0x63,0x6B,0x2D,0x6C,0x69,0x73,0x74,0x00,0x00,0x01,0x0E,0x73,0x74,
0x75,0x64,0x69,0x6F,0x2D,0x74,0x6F,0x6F,0x6C,0x62,0x61,0x72,0x00,0x00,0x01,0x04,
0x69,0x63,0x6F,0x6E,0x02,0x00,0x02,0x02,0x00,0x07,0x02,0x00,0x07,0x0D,0x73,0x79,
0x6E,0x74,0x61,0x78,0x2D,0x65,0x64,0x69,0x74,0x6F,0x72,0x00,0x00,0x01,0x06,0x62,
0x75,0x74,0x74,0x6F,0x6E,0x03,0x00,0x02,0x02,0x00,0x07,0x02,0x00,0x07,0x02,0x00,
0x07,0x01,0x04,0x58,0x02,0x21,0x47,0x94,0x21,0xC6,0x16,0x70,0x30,0x45,0x1A,0x48,
0x51,0x44,0x49,0xA0,0x43,0x1C,0x58,0x61,0xC5,0x1E,0x28,0x20,0x26,0x11,0x10,0x49,
0x44,0x19,0x00,0x29,0x54,0x36,0x0A,0xEC,0x16,0x0C,0x90,0x22,0x48,0xA8,0xCC,0x05,
0x20,0x84,0xE0,0x46,0x0A,0x90,0x82,0x40,0x60,0x69,0x0C,0x7B,0x01,0xD2,0x42,0x05,
0xAA,0x84,0x35,0x30,0x01,0xAB,0x85,0x6C,0x4B,0x10,0x56,0x1C,0xE8,0x66,0x45,0x38,
0x09,0x09,0x8E,0x44,0x78,0x42,0x60,0x11,0x42,0x27,0xC0,0xA8,0x78,0x0D,0x17,0x40,
0x3B,0xD0,0x01,0xB1,0x60,0x11,0x16,0x05,0x44,0xC0,0x68,0x1A,0x07,0x54,0x86,0x80
};

void init_MetaConfig_dict()
{
  ATermList afuns, terms;

  _MetaConfig_dict = ATreadFromBinaryString(_MetaConfig_dict_baf, _MetaConfig_dict_LEN);

  ATprotect(&_MetaConfig_dict);

  afuns = (ATermList)ATelementAt((ATermList)_MetaConfig_dict, 0);

  MC_afun8 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun17 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun0 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun11 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun5 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun3 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun9 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun16 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun10 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun4 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun13 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun14 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun2 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun7 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun12 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun15 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun6 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun1 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);

  terms = (ATermList)ATelementAt((ATermList)_MetaConfig_dict, 1);

  MC_patternModuleNameWildcard = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternItemsMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternItemsSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternItemsEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternActionListMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternActionListSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternActionListEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternMenuShortcut = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternMenuDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternButtonArgsIcon = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternButtonArgsClick = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternButtonTypeWildcard = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternButtonTypeStudioToolbar = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternButtonTypeStudioMenubar = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternButtonTypeNewModulePopup = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternButtonTypeModulePopup = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternButtonTypeTreePanel = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternButtonTypeFeedbackList = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternButtonTypeSyntaxEditor = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternButtonTypeEquationsEditor = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternButtonTypeTermEditor = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternButtonDescriptionDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternButtonDescriptionListMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternButtonDescriptionListSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternButtonDescriptionListEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternPropertyExtension = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MC_patternPropertyButton = ATgetFirst(terms);
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
