#include "Slicing_dict.h"

AFun S_afun8;
AFun S_afun0;
AFun S_afun11;
AFun S_afun5;
AFun S_afun3;
AFun S_afun9;
AFun S_afun10;
AFun S_afun4;
AFun S_afun13;
AFun S_afun14;
AFun S_afun2;
AFun S_afun7;
AFun S_afun12;
AFun S_afun6;
AFun S_afun1;

ATerm S_patternSlicesMany = NULL;
ATerm S_patternSlicesSingle = NULL;
ATerm S_patternSlicesEmpty = NULL;
ATerm S_patternAreasMany = NULL;
ATerm S_patternAreasSingle = NULL;
ATerm S_patternAreasEmpty = NULL;
ATerm S_patternSliceDefault = NULL;
ATerm S_patternStyleUnderlined = NULL;
ATerm S_patternStyleItalics = NULL;
ATerm S_patternStyleBold = NULL;
ATerm S_patternColorRgb = NULL;
ATerm S_patternAttributeSize = NULL;
ATerm S_patternAttributeFont = NULL;
ATerm S_patternAttributeStyle = NULL;
ATerm S_patternAttributeBackgroundColor = NULL;
ATerm S_patternAttributeForegroundColor = NULL;
ATerm S_patternAttributesMany = NULL;
ATerm S_patternAttributesSingle = NULL;
ATerm S_patternAttributesEmpty = NULL;
ATerm S_patternCategoryDefault = NULL;
ATerm S_patternCategoryNameExtern = NULL;
ATerm S_patternCategoryNameNormal = NULL;
ATerm S_patternCategoryNameSelection = NULL;
ATerm S_patternCategoryNameFocus = NULL;

/*
 * S_afun8 = font(x)
 * S_afun0 = focus
 * S_afun11 = bold
 * S_afun5 = foreground-color(x)
 * S_afun3 = extern(x)
 * S_afun9 = size(x)
 * S_afun10 = rgb(x,x,x)
 * S_afun4 = category(x,x)
 * S_afun13 = underlined
 * S_afun14 = slice(x,x)
 * S_afun2 = normal
 * S_afun7 = style(x)
 * S_afun12 = italics
 * S_afun6 = background-color(x)
 * S_afun1 = selection
 *
 * S_patternSlicesMany = [<term>,<list>]
 * S_patternSlicesSingle = [<term>]
 * S_patternSlicesEmpty = []
 * S_patternAreasMany = [<term>,<list>]
 * S_patternAreasSingle = [<term>]
 * S_patternAreasEmpty = []
 * S_patternSliceDefault = slice(<term>,<term>)
 * S_patternStyleUnderlined = underlined
 * S_patternStyleItalics = italics
 * S_patternStyleBold = bold
 * S_patternColorRgb = rgb(<int>,<int>,<int>)
 * S_patternAttributeSize = size(<int>)
 * S_patternAttributeFont = font(<str>)
 * S_patternAttributeStyle = style(<term>)
 * S_patternAttributeBackgroundColor = background-color(<term>)
 * S_patternAttributeForegroundColor = foreground-color(<term>)
 * S_patternAttributesMany = [<term>,<list>]
 * S_patternAttributesSingle = [<term>]
 * S_patternAttributesEmpty = []
 * S_patternCategoryDefault = category(<term>,<term>)
 * S_patternCategoryNameExtern = extern(<str>)
 * S_patternCategoryNameNormal = normal
 * S_patternCategoryNameSelection = selection
 * S_patternCategoryNameFocus = focus
 *
 */

static ATerm _Slicing_dict = NULL;

#define _Slicing_dict_LEN 392

static char _Slicing_dict_baf[_Slicing_dict_LEN] = {
0x00,0x8B,0xAF,0x83,0x00,0x17,0x4E,0x03,0x3C,0x5F,0x3E,0x01,0x00,0x04,0x04,0x04,
0x03,0x05,0x06,0x05,0x5B,0x5F,0x2C,0x5F,0x5D,0x02,0x00,0x2C,0x12,0x01,0x02,0x00,
0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x02,
0x01,0x02,0x02,0x5B,0x5D,0x00,0x00,0x01,0x03,0x69,0x6E,0x74,0x00,0x00,0x01,0x03,
0x73,0x74,0x72,0x00,0x00,0x01,0x04,0x6C,0x69,0x73,0x74,0x00,0x00,0x01,0x04,0x74,
0x65,0x72,0x6D,0x00,0x00,0x01,0x01,0x78,0x00,0x00,0x01,0x04,0x66,0x6F,0x6E,0x74,
0x01,0x00,0x02,0x02,0x00,0x07,0x05,0x66,0x6F,0x63,0x75,0x73,0x00,0x00,0x01,0x04,
0x62,0x6F,0x6C,0x64,0x00,0x00,0x01,0x10,0x66,0x6F,0x72,0x65,0x67,0x72,0x6F,0x75,
0x6E,0x64,0x2D,0x63,0x6F,0x6C,0x6F,0x72,0x01,0x00,0x02,0x02,0x00,0x07,0x06,0x65,
0x78,0x74,0x65,0x72,0x6E,0x01,0x00,0x02,0x02,0x00,0x07,0x04,0x73,0x69,0x7A,0x65,
0x01,0x00,0x02,0x02,0x00,0x07,0x03,0x72,0x67,0x62,0x03,0x00,0x02,0x02,0x00,0x07,
0x02,0x00,0x07,0x02,0x00,0x07,0x08,0x63,0x61,0x74,0x65,0x67,0x6F,0x72,0x79,0x02,
0x00,0x02,0x02,0x00,0x07,0x02,0x00,0x07,0x0A,0x75,0x6E,0x64,0x65,0x72,0x6C,0x69,
0x6E,0x65,0x64,0x00,0x00,0x01,0x05,0x73,0x6C,0x69,0x63,0x65,0x02,0x00,0x02,0x02,
0x00,0x07,0x02,0x00,0x07,0x06,0x6E,0x6F,0x72,0x6D,0x61,0x6C,0x00,0x00,0x01,0x05,
0x73,0x74,0x79,0x6C,0x65,0x01,0x00,0x02,0x02,0x00,0x07,0x07,0x69,0x74,0x61,0x6C,
0x69,0x63,0x73,0x00,0x00,0x01,0x10,0x62,0x61,0x63,0x6B,0x67,0x72,0x6F,0x75,0x6E,
0x64,0x2D,0x63,0x6F,0x6C,0x6F,0x72,0x01,0x00,0x02,0x02,0x00,0x07,0x09,0x73,0x65,
0x6C,0x65,0x63,0x74,0x69,0x6F,0x6E,0x00,0x00,0x01,0x01,0x03,0x98,0x22,0xC2,0x06,
0x50,0xD1,0x84,0x29,0xC2,0x24,0x11,0x02,0x48,0xA8,0xE1,0x45,0x0C,0x68,0xA0,0xC5,
0x04,0x58,0xC1,0xC4,0x21,0xE2,0x00,0x90,0x04,0x61,0x50,0x4A,0x00,0x90,0x31,0xE2,
0x22,0x81,0x41,0x12,0x04,0x73,0x01,0x90,0x04,0x52,0x08,0x82,0x60,0x62,0x68,0x00,
0x11,0xD1,0x0F,0x80,0x68,0x7D,0x28,0x50,0x42,0x1E,0x14,0x22,0xEC,0x46,0x01,0xCE,
0x80,0x6C,0x18,0x02,0xCC,0x80,0x4C,0x00,0x81,0x81,0x11,0xD4,0x06,0x95,0x00,0x05,
0x5C,0x8C,0x15,0x63,0x28,0x89,0x12,0x80
};

void init_Slicing_dict()
{
  ATermList afuns, terms;

  _Slicing_dict = ATreadFromBinaryString(_Slicing_dict_baf, _Slicing_dict_LEN);

  ATprotect(&_Slicing_dict);

  afuns = (ATermList)ATelementAt((ATermList)_Slicing_dict, 0);

  S_afun8 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  S_afun0 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  S_afun11 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  S_afun5 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  S_afun3 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  S_afun9 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  S_afun10 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  S_afun4 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  S_afun13 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  S_afun14 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  S_afun2 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  S_afun7 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  S_afun12 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  S_afun6 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  S_afun1 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);

  terms = (ATermList)ATelementAt((ATermList)_Slicing_dict, 1);

  S_patternSlicesMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  S_patternSlicesSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  S_patternSlicesEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  S_patternAreasMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  S_patternAreasSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  S_patternAreasEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  S_patternSliceDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  S_patternStyleUnderlined = ATgetFirst(terms);
  terms = ATgetNext(terms);
  S_patternStyleItalics = ATgetFirst(terms);
  terms = ATgetNext(terms);
  S_patternStyleBold = ATgetFirst(terms);
  terms = ATgetNext(terms);
  S_patternColorRgb = ATgetFirst(terms);
  terms = ATgetNext(terms);
  S_patternAttributeSize = ATgetFirst(terms);
  terms = ATgetNext(terms);
  S_patternAttributeFont = ATgetFirst(terms);
  terms = ATgetNext(terms);
  S_patternAttributeStyle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  S_patternAttributeBackgroundColor = ATgetFirst(terms);
  terms = ATgetNext(terms);
  S_patternAttributeForegroundColor = ATgetFirst(terms);
  terms = ATgetNext(terms);
  S_patternAttributesMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  S_patternAttributesSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  S_patternAttributesEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  S_patternCategoryDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  S_patternCategoryNameExtern = ATgetFirst(terms);
  terms = ATgetNext(terms);
  S_patternCategoryNameNormal = ATgetFirst(terms);
  terms = ATgetNext(terms);
  S_patternCategoryNameSelection = ATgetFirst(terms);
  terms = ATgetNext(terms);
  S_patternCategoryNameFocus = ATgetFirst(terms);
  terms = ATgetNext(terms);
}
