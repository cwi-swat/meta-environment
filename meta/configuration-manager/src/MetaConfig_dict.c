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
AFun MC_afun19;
AFun MC_afun2;
AFun MC_afun7;
AFun MC_afun12;
AFun MC_afun15;
AFun MC_afun18;
AFun MC_afun6;
AFun MC_afun1;

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
ATerm MC_patternPropertyModulePath = NULL;
ATerm MC_patternPropertyExtension = NULL;
ATerm MC_patternPropertyAction = NULL;
ATerm MC_patternPropertiesMany = NULL;
ATerm MC_patternPropertiesSingle = NULL;
ATerm MC_patternPropertiesEmpty = NULL;
ATerm MC_patternConfigurationList = NULL;

/*
 * MC_afun8 = syntax-editor
 * MC_afun17 = icon(x,x)
 * MC_afun0 = configuration(x)
 * MC_afun11 = module-popup(x)
 * MC_afun5 = term-editor
 * MC_afun3 = module-path(x)
 * MC_afun9 = feedback-list
 * MC_afun16 = click
 * MC_afun10 = tree-panel
 * MC_afun4 = description(x,x)
 * MC_afun13 = studio-menubar
 * MC_afun14 = studio-toolbar
 * MC_afun19 = menu(x,x)
 * MC_afun2 = extension(x,x)
 * MC_afun7 = equations-editor
 * MC_afun12 = new-module-popup
 * MC_afun15 = "*"
 * MC_afun18 = menu(x)
 * MC_afun6 = term-editor(x)
 * MC_afun1 = action(x,x)
 *
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
 * MC_patternPropertyModulePath = module-path(<str>)
 * MC_patternPropertyExtension = extension(<str>,<str>)
 * MC_patternPropertyAction = action(<term>,<term>)
 * MC_patternPropertiesMany = [<term>,<list>]
 * MC_patternPropertiesSingle = [<term>]
 * MC_patternPropertiesEmpty = []
 * MC_patternConfigurationList = configuration(<term>)
 *
 */

static ATerm _MetaConfig_dict = NULL;

#define _MetaConfig_dict_LEN 525

static char _MetaConfig_dict_baf[_MetaConfig_dict_LEN] = {
0x00,0x8B,0xAF,0x83,0x00,0x1B,0x5F,0x03,0x3C,0x5F,0x3E,0x01,0x00,0x03,0x03,0x05,
0x04,0x03,0x05,0x5B,0x5F,0x2C,0x5F,0x5D,0x02,0x00,0x39,0x17,0x01,0x02,0x00,0x06,
0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,
0x18,0x19,0x1A,0x02,0x01,0x02,0x02,0x5B,0x5D,0x00,0x00,0x01,0x03,0x73,0x74,0x72,
0x00,0x00,0x01,0x04,0x6C,0x69,0x73,0x74,0x00,0x00,0x01,0x04,0x74,0x65,0x72,0x6D,
0x00,0x00,0x01,0x0D,0x73,0x79,0x6E,0x74,0x61,0x78,0x2D,0x65,0x64,0x69,0x74,0x6F,
0x72,0x00,0x00,0x01,0x01,0x78,0x00,0x00,0x01,0x04,0x69,0x63,0x6F,0x6E,0x02,0x00,
0x02,0x02,0x00,0x07,0x02,0x00,0x07,0x0D,0x63,0x6F,0x6E,0x66,0x69,0x67,0x75,0x72,
0x61,0x74,0x69,0x6F,0x6E,0x01,0x00,0x02,0x02,0x00,0x07,0x0C,0x6D,0x6F,0x64,0x75,
0x6C,0x65,0x2D,0x70,0x6F,0x70,0x75,0x70,0x01,0x00,0x02,0x02,0x00,0x07,0x0B,0x74,
0x65,0x72,0x6D,0x2D,0x65,0x64,0x69,0x74,0x6F,0x72,0x00,0x00,0x01,0x0B,0x6D,0x6F,
0x64,0x75,0x6C,0x65,0x2D,0x70,0x61,0x74,0x68,0x01,0x00,0x02,0x02,0x00,0x07,0x0D,
0x66,0x65,0x65,0x64,0x62,0x61,0x63,0x6B,0x2D,0x6C,0x69,0x73,0x74,0x00,0x00,0x01,
0x05,0x63,0x6C,0x69,0x63,0x6B,0x00,0x00,0x01,0x0A,0x74,0x72,0x65,0x65,0x2D,0x70,
0x61,0x6E,0x65,0x6C,0x00,0x00,0x01,0x0B,0x64,0x65,0x73,0x63,0x72,0x69,0x70,0x74,
0x69,0x6F,0x6E,0x02,0x00,0x02,0x02,0x00,0x07,0x02,0x00,0x07,0x0E,0x73,0x74,0x75,
0x64,0x69,0x6F,0x2D,0x6D,0x65,0x6E,0x75,0x62,0x61,0x72,0x00,0x00,0x01,0x0E,0x73,
0x74,0x75,0x64,0x69,0x6F,0x2D,0x74,0x6F,0x6F,0x6C,0x62,0x61,0x72,0x00,0x00,0x01,
0x04,0x6D,0x65,0x6E,0x75,0x02,0x00,0x02,0x02,0x00,0x07,0x02,0x00,0x07,0x09,0x65,
0x78,0x74,0x65,0x6E,0x73,0x69,0x6F,0x6E,0x02,0x00,0x02,0x02,0x00,0x07,0x02,0x00,
0x07,0x10,0x65,0x71,0x75,0x61,0x74,0x69,0x6F,0x6E,0x73,0x2D,0x65,0x64,0x69,0x74,
0x6F,0x72,0x00,0x00,0x01,0x10,0x6E,0x65,0x77,0x2D,0x6D,0x6F,0x64,0x75,0x6C,0x65,
0x2D,0x70,0x6F,0x70,0x75,0x70,0x00,0x00,0x01,0x01,0x2A,0x00,0x01,0x01,0x04,0x6D,
0x65,0x6E,0x75,0x01,0x00,0x02,0x02,0x00,0x07,0x0B,0x74,0x65,0x72,0x6D,0x2D,0x65,
0x64,0x69,0x74,0x6F,0x72,0x01,0x00,0x02,0x02,0x00,0x07,0x06,0x61,0x63,0x74,0x69,
0x6F,0x6E,0x02,0x00,0x02,0x02,0x00,0x07,0x02,0x00,0x07,0x01,0x06,0x58,0x12,0x21,
0x44,0x54,0x20,0x26,0x11,0xE7,0x07,0x04,0x45,0x92,0x0C,0x51,0xA6,0x85,0x0C,0x51,
0x25,0x81,0x1C,0x71,0xE2,0x86,0x02,0x51,0x44,0x42,0x12,0x61,0x91,0x02,0x91,0x05,
0x48,0x01,0xA5,0x47,0x60,0x6F,0x25,0x60,0xA9,0x02,0x14,0x8A,0x82,0xC0,0xD2,0x08,
0xCE,0x02,0x7E,0x84,0x02,0x32,0xC2,0x06,0x48,0x00,0xF5,0x43,0xB9,0x2D,0x70,0x6D,
0x8D,0x52,0x2A,0xC8,0x09,0x74,0x0B,0x23,0x9C,0x0C,0xC4,0xA6,0xB0,0x04,0xF0,0xC4,
0x1D,0x21,0x0A,0x11,0x00,0xC8,0x62,0x18,0x00,0x9A,0x11,0x3E,0x14,0x03,0xC1,0x80,
0x0B,0x9B,0x08,0x87,0x03,0xA3,0x60,0x0C,0x2D,0x02,0x6A,0x43,0x40
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
  MC_afun19 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun2 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun7 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun12 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun15 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MC_afun18 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
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
  MC_patternPropertyModulePath = ATgetFirst(terms);
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
