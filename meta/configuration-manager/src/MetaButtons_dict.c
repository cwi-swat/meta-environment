/*
 * Generated at Thu Jul 10 17:59:30 2003
 */

#include "MetaButtons_dict.h"

AFun MB_afun0;
AFun MB_afun1;
AFun MB_afun2;
AFun MB_afun3;
AFun MB_afun4;
AFun MB_afun5;
AFun MB_afun6;
AFun MB_afun7;
AFun MB_afun8;
AFun MB_afun9;
AFun MB_afun10;
AFun MB_afun11;
AFun MB_afun12;
AFun MB_afun13;
AFun MB_afun14;
AFun MB_afun15;

ATerm MB_patternModuleNameWildcard = NULL;
ATerm MB_patternMenuTitlesMany = NULL;
ATerm MB_patternMenuTitlesEmpty = NULL;
ATerm MB_patternButtonArgsIcon = NULL;
ATerm MB_patternButtonArgsMenu = NULL;
ATerm MB_patternButtonArgsClick = NULL;
ATerm MB_patternButtonTypeWildcard = NULL;
ATerm MB_patternButtonTypeStudioToolbar = NULL;
ATerm MB_patternButtonTypeStudioMenubar = NULL;
ATerm MB_patternButtonTypeNewModulePopup = NULL;
ATerm MB_patternButtonTypeModulePopup = NULL;
ATerm MB_patternButtonTypeTreePanel = NULL;
ATerm MB_patternButtonTypeMessageList = NULL;
ATerm MB_patternButtonTypeSyntax = NULL;
ATerm MB_patternButtonTypeEquations = NULL;
ATerm MB_patternButtonTypeTerm = NULL;
ATerm MB_patternButtonDescriptionDefault = NULL;
ATerm MB_patternButtonDescriptionListMany = NULL;
ATerm MB_patternButtonDescriptionListEmpty = NULL;
ATerm MB_patternButtonDefault = NULL;
ATerm MB_patternButtonListMany = NULL;
ATerm MB_patternButtonListEmpty = NULL;
ATerm MB_patternButtonsList = NULL;

/*
 * MB_afun0 = buttons(x)
 * MB_afun1 = button(x,x,x)
 * MB_afun2 = description(x,x)
 * MB_afun3 = term-editor
 * MB_afun4 = equations-editor
 * MB_afun5 = syntax-editor
 * MB_afun6 = message-list
 * MB_afun7 = tree-panel
 * MB_afun8 = module-popup
 * MB_afun9 = new-module-popup
 * MB_afun10 = studio-menubar
 * MB_afun11 = studio-toolbar
 * MB_afun12 = "*"
 * MB_afun13 = click
 * MB_afun14 = menu(x)
 * MB_afun15 = icon(x,x)
 *
 * MB_patternModuleNameWildcard = "*"
 * MB_patternMenuTitlesMany = [<str>,<list>]
 * MB_patternMenuTitlesEmpty = []
 * MB_patternButtonArgsIcon = icon(<str>,<str>)
 * MB_patternButtonArgsMenu = menu(<term>)
 * MB_patternButtonArgsClick = click
 * MB_patternButtonTypeWildcard = "*"
 * MB_patternButtonTypeStudioToolbar = studio-toolbar
 * MB_patternButtonTypeStudioMenubar = studio-menubar
 * MB_patternButtonTypeNewModulePopup = new-module-popup
 * MB_patternButtonTypeModulePopup = module-popup
 * MB_patternButtonTypeTreePanel = tree-panel
 * MB_patternButtonTypeMessageList = message-list
 * MB_patternButtonTypeSyntax = syntax-editor
 * MB_patternButtonTypeEquations = equations-editor
 * MB_patternButtonTypeTerm = term-editor
 * MB_patternButtonDescriptionDefault = description(<term>,<term>)
 * MB_patternButtonDescriptionListMany = [<term>,<list>]
 * MB_patternButtonDescriptionListEmpty = []
 * MB_patternButtonDefault = button(<str>,<term>,<term>)
 * MB_patternButtonListMany = [<term>,<list>]
 * MB_patternButtonListEmpty = []
 * MB_patternButtonsList = buttons(<term>)
 *
 */

static ATermList _MetaButtons_dict = NULL;

#define _MetaButtons_dict_LEN 415

static char _MetaButtons_dict_baf[_MetaButtons_dict_LEN] = {
0x00,0x8B,0xAF,0x83,0x00,0x17,0x49,0x03,0x3C,0x5F,0x3E,0x01,0x00,0x03,0x03,0x05,
0x04,0x03,0x05,0x5B,0x5F,0x2C,0x5F,0x5D,0x02,0x00,0x2C,0x13,0x01,0x02,0x00,0x07,
0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x02,
0x01,0x02,0x02,0x5B,0x5D,0x00,0x00,0x01,0x03,0x73,0x74,0x72,0x00,0x00,0x01,0x04,
0x6C,0x69,0x73,0x74,0x00,0x00,0x01,0x04,0x74,0x65,0x72,0x6D,0x00,0x00,0x01,0x01,
0x78,0x00,0x00,0x01,0x07,0x62,0x75,0x74,0x74,0x6F,0x6E,0x73,0x01,0x00,0x02,0x02,
0x00,0x06,0x06,0x62,0x75,0x74,0x74,0x6F,0x6E,0x03,0x00,0x02,0x02,0x00,0x06,0x02,
0x00,0x06,0x02,0x00,0x06,0x0B,0x64,0x65,0x73,0x63,0x72,0x69,0x70,0x74,0x69,0x6F,
0x6E,0x02,0x00,0x02,0x02,0x00,0x06,0x02,0x00,0x06,0x0B,0x74,0x65,0x72,0x6D,0x2D,
0x65,0x64,0x69,0x74,0x6F,0x72,0x00,0x00,0x01,0x10,0x65,0x71,0x75,0x61,0x74,0x69,
0x6F,0x6E,0x73,0x2D,0x65,0x64,0x69,0x74,0x6F,0x72,0x00,0x00,0x01,0x0D,0x73,0x79,
0x6E,0x74,0x61,0x78,0x2D,0x65,0x64,0x69,0x74,0x6F,0x72,0x00,0x00,0x01,0x0C,0x6D,
0x65,0x73,0x73,0x61,0x67,0x65,0x2D,0x6C,0x69,0x73,0x74,0x00,0x00,0x01,0x0A,0x74,
0x72,0x65,0x65,0x2D,0x70,0x61,0x6E,0x65,0x6C,0x00,0x00,0x01,0x0C,0x6D,0x6F,0x64,
0x75,0x6C,0x65,0x2D,0x70,0x6F,0x70,0x75,0x70,0x00,0x00,0x01,0x10,0x6E,0x65,0x77,
0x2D,0x6D,0x6F,0x64,0x75,0x6C,0x65,0x2D,0x70,0x6F,0x70,0x75,0x70,0x00,0x00,0x01,
0x0E,0x73,0x74,0x75,0x64,0x69,0x6F,0x2D,0x6D,0x65,0x6E,0x75,0x62,0x61,0x72,0x00,
0x00,0x01,0x0E,0x73,0x74,0x75,0x64,0x69,0x6F,0x2D,0x74,0x6F,0x6F,0x6C,0x62,0x61,
0x72,0x00,0x00,0x01,0x01,0x2A,0x00,0x01,0x01,0x05,0x63,0x6C,0x69,0x63,0x6B,0x00,
0x00,0x01,0x04,0x6D,0x65,0x6E,0x75,0x01,0x00,0x02,0x02,0x00,0x06,0x04,0x69,0x63,
0x6F,0x6E,0x02,0x00,0x02,0x02,0x00,0x06,0x02,0x00,0x06,0x01,0x07,0x98,0x21,0xC2,
0x15,0x16,0x50,0xA0,0xC6,0x1A,0x70,0x50,0x44,0x92,0x04,0x51,0xC6,0x86,0x0C,0x51,
0x60,0x87,0x18,0x78,0x40,0x24,0x11,0x20,0x04,0x95,0x0A,0x82,0x5F,0x02,0x82,0x24,
0x08,0x12,0x2A,0x39,0x80,0xCA,0x60,0x02,0x98,0xC2,0x04,0x84,0xC7,0xC2,0x2E,0x21,
0xB0,0x09,0x8F,0xB4,0x3C,0xA2,0xE9,0x07,0x08,0xDB,0x82,0xCC,0x26,0xA4,0x22,0x0C,
0x04,0x90,0x81,0x1D,0x40,0x68,0x90,0x08,0x95,0x01,0x20,0xA8,0x19,0x62,0x1A
};

void init_MetaButtons_dict()
{
  ATermList afuns, terms;

  _MetaButtons_dict = (ATermList)ATreadFromBinaryString(_MetaButtons_dict_baf, _MetaButtons_dict_LEN);

  ATprotect((ATerm *)&_MetaButtons_dict);

  afuns = (ATermList)ATelementAt(_MetaButtons_dict, 0);

  MB_afun0 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MB_afun1 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MB_afun2 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MB_afun3 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MB_afun4 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MB_afun5 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MB_afun6 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MB_afun7 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MB_afun8 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MB_afun9 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MB_afun10 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MB_afun11 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MB_afun12 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MB_afun13 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MB_afun14 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MB_afun15 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);

  terms = (ATermList)ATelementAt(_MetaButtons_dict, 1);

  MB_patternModuleNameWildcard = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MB_patternMenuTitlesMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MB_patternMenuTitlesEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MB_patternButtonArgsIcon = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MB_patternButtonArgsMenu = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MB_patternButtonArgsClick = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MB_patternButtonTypeWildcard = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MB_patternButtonTypeStudioToolbar = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MB_patternButtonTypeStudioMenubar = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MB_patternButtonTypeNewModulePopup = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MB_patternButtonTypeModulePopup = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MB_patternButtonTypeTreePanel = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MB_patternButtonTypeMessageList = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MB_patternButtonTypeSyntax = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MB_patternButtonTypeEquations = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MB_patternButtonTypeTerm = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MB_patternButtonDescriptionDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MB_patternButtonDescriptionListMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MB_patternButtonDescriptionListEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MB_patternButtonDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MB_patternButtonListMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MB_patternButtonListEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MB_patternButtonsList = ATgetFirst(terms);
  terms = ATgetNext(terms);
}
