/*
 * Generated at Thu Jun  5 09:22:20 2003
 */

#include "MetaButtons_dict.h"

AFun MB_afun0;
AFun MB_afun1;
AFun MB_afun2;
AFun MB_afun3;
AFun MB_afun4;
AFun MB_afun5;
AFun MB_afun6;

ATerm MB_patternModuleNameAll = NULL;
ATerm MB_patternEditorTypeAll = NULL;
ATerm MB_patternEditorTypeMessageList = NULL;
ATerm MB_patternEditorTypeSyntax = NULL;
ATerm MB_patternEditorTypeEquations = NULL;
ATerm MB_patternEditorTypeTerm = NULL;
ATerm MB_patternEditorTypesMany = NULL;
ATerm MB_patternEditorTypesEmpty = NULL;
ATerm MB_patternButtonEditor = NULL;
ATerm MB_patternButtonListMany = NULL;
ATerm MB_patternButtonListEmpty = NULL;
ATerm MB_patternButtonsList = NULL;

/*
 * MB_afun0 = buttons(x)
 * MB_afun1 = button(x,x,x,x)
 * MB_afun2 = "term"
 * MB_afun3 = "equations"
 * MB_afun4 = "syntax"
 * MB_afun5 = "message-list"
 * MB_afun6 = "*"
 *
 * MB_patternModuleNameAll = "*"
 * MB_patternEditorTypeAll = "*"
 * MB_patternEditorTypeMessageList = "message-list"
 * MB_patternEditorTypeSyntax = "syntax"
 * MB_patternEditorTypeEquations = "equations"
 * MB_patternEditorTypeTerm = "term"
 * MB_patternEditorTypesMany = [<term>,<list>]
 * MB_patternEditorTypesEmpty = []
 * MB_patternButtonEditor = button(<str>,<term>,<term>,<term>)
 * MB_patternButtonListMany = [<term>,<list>]
 * MB_patternButtonListEmpty = []
 * MB_patternButtonsList = buttons(<term>)
 *
 */

static ATermList _MetaButtons_dict = NULL;

#define _MetaButtons_dict_LEN 202

static char _MetaButtons_dict_baf[_MetaButtons_dict_LEN] = {
0x00,0x8B,0xAF,0x83,0x00,0x0E,0x28,0x03,0x3C,0x5F,0x3E,0x01,0x00,0x03,0x03,0x03,
0x04,0x05,0x05,0x5B,0x5F,0x2C,0x5F,0x5D,0x02,0x00,0x17,0x0A,0x01,0x02,0x00,0x07,
0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x02,0x01,0x02,0x02,0x5B,0x5D,0x00,0x00,0x01,0x03,
0x73,0x74,0x72,0x00,0x00,0x01,0x04,0x6C,0x69,0x73,0x74,0x00,0x00,0x01,0x04,0x74,
0x65,0x72,0x6D,0x00,0x00,0x01,0x01,0x78,0x00,0x00,0x01,0x07,0x62,0x75,0x74,0x74,
0x6F,0x6E,0x73,0x01,0x00,0x02,0x02,0x00,0x06,0x06,0x62,0x75,0x74,0x74,0x6F,0x6E,
0x04,0x00,0x02,0x02,0x00,0x06,0x02,0x00,0x06,0x02,0x00,0x06,0x02,0x00,0x06,0x04,
0x74,0x65,0x72,0x6D,0x00,0x01,0x01,0x09,0x65,0x71,0x75,0x61,0x74,0x69,0x6F,0x6E,
0x73,0x00,0x01,0x01,0x06,0x73,0x79,0x6E,0x74,0x61,0x78,0x00,0x01,0x01,0x0C,0x6D,
0x65,0x73,0x73,0x61,0x67,0x65,0x2D,0x6C,0x69,0x73,0x74,0x00,0x01,0x01,0x01,0x2A,
0x00,0x01,0x01,0x01,0x06,0x61,0x14,0x22,0xA8,0x25,0x18,0x61,0x1C,0x40,0x40,0x4C,
0x54,0x0B,0x26,0x64,0x48,0x91,0xE0,0x2C,0x7A,0x87,0x00,0x90,0x4E,0x25,0x45,0xA0,
0x31,0x42,0x00,0x01,0xA0,0x10,0xA8,0x25,0x90,0x50
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

  terms = (ATermList)ATelementAt(_MetaButtons_dict, 1);

  MB_patternModuleNameAll = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MB_patternEditorTypeAll = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MB_patternEditorTypeMessageList = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MB_patternEditorTypeSyntax = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MB_patternEditorTypeEquations = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MB_patternEditorTypeTerm = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MB_patternEditorTypesMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MB_patternEditorTypesEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MB_patternButtonEditor = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MB_patternButtonListMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MB_patternButtonListEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  MB_patternButtonsList = ATgetFirst(terms);
  terms = ATgetNext(terms);
}
