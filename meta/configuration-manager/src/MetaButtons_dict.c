/*
 * Generated at Mon Jul  7 16:56:05 2003
 */

#include "MetaButtons_dict.h"

AFun MB_afun8;
AFun MB_afun0;
AFun MB_afun11;
AFun MB_afun5;
AFun MB_afun3;
AFun MB_afun9;
AFun MB_afun10;
AFun MB_afun4;
AFun MB_afun13;
AFun MB_afun2;
AFun MB_afun7;
AFun MB_afun12;
AFun MB_afun6;
AFun MB_afun1;

ATerm MB_patternModuleNameWildcard = NULL;
ATerm MB_patternMenuTitlesMany = NULL;
ATerm MB_patternMenuTitlesEmpty = NULL;
ATerm MB_patternButtonArgsIcon = NULL;
ATerm MB_patternButtonArgsMenu = NULL;
ATerm MB_patternButtonTypeWildcard = NULL;
ATerm MB_patternButtonTypeStudioToolbar = NULL;
ATerm MB_patternButtonTypeStudioMenubar = NULL;
ATerm MB_patternButtonTypeNewModulePopup = NULL;
ATerm MB_patternButtonTypeModulePopup = NULL;
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
 * MB_afun8 = new-module-popup
 * MB_afun0 = buttons(x)
 * MB_afun11 = "*"
 * MB_afun5 = syntax-editor
 * MB_afun3 = term-editor
 * MB_afun9 = studio-menubar
 * MB_afun10 = studio-toolbar
 * MB_afun4 = equations-editor
 * MB_afun13 = icon(x,x)
 * MB_afun2 = button-desc(x,x)
 * MB_afun7 = module-popup
 * MB_afun12 = menu(x)
 * MB_afun6 = message-list
 * MB_afun1 = button(x,x,x)
 *
 * MB_patternModuleNameWildcard = "*"
 * MB_patternMenuTitlesMany = [<str>,<list>]
 * MB_patternMenuTitlesEmpty = []
 * MB_patternButtonArgsIcon = icon(<str>,<str>)
 * MB_patternButtonArgsMenu = menu(<term>)
 * MB_patternButtonTypeWildcard = "*"
 * MB_patternButtonTypeStudioToolbar = studio-toolbar
 * MB_patternButtonTypeStudioMenubar = studio-menubar
 * MB_patternButtonTypeNewModulePopup = new-module-popup
 * MB_patternButtonTypeModulePopup = module-popup
 * MB_patternButtonTypeMessageList = message-list
 * MB_patternButtonTypeSyntax = syntax-editor
 * MB_patternButtonTypeEquations = equations-editor
 * MB_patternButtonTypeTerm = term-editor
 * MB_patternButtonDescriptionDefault = button-desc(<term>,<term>)
 * MB_patternButtonDescriptionListMany = [<term>,<list>]
 * MB_patternButtonDescriptionListEmpty = []
 * MB_patternButtonDefault = button(<str>,<term>,<term>)
 * MB_patternButtonListMany = [<term>,<list>]
 * MB_patternButtonListEmpty = []
 * MB_patternButtonsList = buttons(<term>)
 *
 */

static ATermList _MetaButtons_dict = NULL;

#define _MetaButtons_dict_LEN 384

static char _MetaButtons_dict_baf[_MetaButtons_dict_LEN] = {
0x00,0x8B,0xAF,0x83,0x00,0x15,0x43,0x03,0x3C,0x5F,0x3E,0x01,0x00,0x03,0x03,0x05,
0x04,0x03,0x05,0x5B,0x5F,0x2C,0x5F,0x5D,0x02,0x00,0x28,0x11,0x01,0x02,0x00,0x06,
0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x02,0x01,0x02,
0x02,0x5B,0x5D,0x00,0x00,0x01,0x03,0x73,0x74,0x72,0x00,0x00,0x01,0x04,0x6C,0x69,
0x73,0x74,0x00,0x00,0x01,0x04,0x74,0x65,0x72,0x6D,0x00,0x00,0x01,0x10,0x6E,0x65,
0x77,0x2D,0x6D,0x6F,0x64,0x75,0x6C,0x65,0x2D,0x70,0x6F,0x70,0x75,0x70,0x00,0x00,
0x01,0x01,0x78,0x00,0x00,0x01,0x07,0x62,0x75,0x74,0x74,0x6F,0x6E,0x73,0x01,0x00,
0x02,0x02,0x00,0x07,0x01,0x2A,0x00,0x01,0x01,0x0D,0x73,0x79,0x6E,0x74,0x61,0x78,
0x2D,0x65,0x64,0x69,0x74,0x6F,0x72,0x00,0x00,0x01,0x0B,0x74,0x65,0x72,0x6D,0x2D,
0x65,0x64,0x69,0x74,0x6F,0x72,0x00,0x00,0x01,0x0E,0x73,0x74,0x75,0x64,0x69,0x6F,
0x2D,0x6D,0x65,0x6E,0x75,0x62,0x61,0x72,0x00,0x00,0x01,0x0E,0x73,0x74,0x75,0x64,
0x69,0x6F,0x2D,0x74,0x6F,0x6F,0x6C,0x62,0x61,0x72,0x00,0x00,0x01,0x10,0x65,0x71,
0x75,0x61,0x74,0x69,0x6F,0x6E,0x73,0x2D,0x65,0x64,0x69,0x74,0x6F,0x72,0x00,0x00,
0x01,0x04,0x69,0x63,0x6F,0x6E,0x02,0x00,0x02,0x02,0x00,0x07,0x02,0x00,0x07,0x0B,
0x62,0x75,0x74,0x74,0x6F,0x6E,0x2D,0x64,0x65,0x73,0x63,0x02,0x00,0x02,0x02,0x00,
0x07,0x02,0x00,0x07,0x0C,0x6D,0x6F,0x64,0x75,0x6C,0x65,0x2D,0x70,0x6F,0x70,0x75,
0x70,0x00,0x00,0x01,0x04,0x6D,0x65,0x6E,0x75,0x01,0x00,0x02,0x02,0x00,0x07,0x0C,
0x6D,0x65,0x73,0x73,0x61,0x67,0x65,0x2D,0x6C,0x69,0x73,0x74,0x00,0x00,0x01,0x06,
0x62,0x75,0x74,0x74,0x6F,0x6E,0x03,0x00,0x02,0x02,0x00,0x07,0x02,0x00,0x07,0x02,
0x00,0x07,0x01,0x05,0x98,0x0C,0x21,0x1A,0x50,0x51,0x84,0x9C,0x04,0x11,0xC4,0x86,
0x14,0x51,0xA2,0x82,0x0C,0x51,0x85,0x84,0x1C,0x44,0x1E,0x00,0x09,0x54,0x32,0x0A,
0x68,0x12,0x0F,0x10,0x23,0x88,0xA8,0xC6,0x02,0x3A,0x80,0x08,0x5D,0x08,0x03,0x43,
0xE9,0x0F,0x08,0xBB,0x01,0xD6,0x36,0xF0,0xB3,0x09,0x94,0x0D,0xC3,0xA3,0x42,0x23,
0x40,0x09,0x08,0xE1,0x54,0x02,0x83,0x00,0x89,0x90,0x02,0x12,0x81,0x11,0x21,0xA0
};

void init_MetaButtons_dict()
{
  ATermList afuns, terms;

  _MetaButtons_dict = (ATermList)ATreadFromBinaryString(_MetaButtons_dict_baf, _MetaButtons_dict_LEN);

  ATprotect((ATerm *)&_MetaButtons_dict);

  afuns = (ATermList)ATelementAt(_MetaButtons_dict, 0);

  MB_afun8 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MB_afun0 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MB_afun11 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MB_afun5 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MB_afun3 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MB_afun9 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MB_afun10 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MB_afun4 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MB_afun13 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MB_afun2 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MB_afun7 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MB_afun12 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MB_afun6 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  MB_afun1 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
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
