#include "Slicing_dict.h"

AFun S_afun0;

ATerm S_patternAreasMany = NULL;
ATerm S_patternAreasSingle = NULL;
ATerm S_patternAreasEmpty = NULL;
ATerm S_patternSlicesMany = NULL;
ATerm S_patternSlicesSingle = NULL;
ATerm S_patternSlicesEmpty = NULL;
ATerm S_patternSliceDefault = NULL;

/*
 * S_afun0 = slice(x,x)
 *
 * S_patternAreasMany = [<term>,<list>]
 * S_patternAreasSingle = [<term>]
 * S_patternAreasEmpty = []
 * S_patternSlicesMany = [<term>,<list>]
 * S_patternSlicesSingle = [<term>]
 * S_patternSlicesEmpty = []
 * S_patternSliceDefault = slice(<str>,<term>)
 *
 */

static ATerm _Slicing_dict = NULL;

#define _Slicing_dict_LEN 104

static char _Slicing_dict_baf[_Slicing_dict_LEN] = {
0x00,0x8B,0xAF,0x83,0x00,0x08,0x17,0x03,0x3C,0x5F,0x3E,0x01,0x00,0x03,0x03,0x03,
0x04,0x05,0x05,0x5B,0x5F,0x2C,0x5F,0x5D,0x02,0x00,0x0D,0x04,0x01,0x02,0x00,0x07,
0x02,0x01,0x02,0x02,0x5B,0x5D,0x00,0x00,0x01,0x03,0x73,0x74,0x72,0x00,0x00,0x01,
0x04,0x6C,0x69,0x73,0x74,0x00,0x00,0x01,0x04,0x74,0x65,0x72,0x6D,0x00,0x00,0x01,
0x01,0x78,0x00,0x00,0x01,0x05,0x73,0x6C,0x69,0x63,0x65,0x02,0x00,0x02,0x02,0x00,
0x06,0x02,0x00,0x06,0x01,0x01,0x8A,0x8D,0x0A,0x11,0x09,0x0A,0xA2,0x46,0x22,0x06,
0x1C,0x10,0x61,0x85,0x40,0xB4,0x20,0x50
};

void init_Slicing_dict()
{
  ATermList afuns, terms;

  _Slicing_dict = ATreadFromBinaryString(_Slicing_dict_baf, _Slicing_dict_LEN);

  ATprotect(&_Slicing_dict);

  afuns = (ATermList)ATelementAt((ATermList)_Slicing_dict, 0);

  S_afun0 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);

  terms = (ATermList)ATelementAt((ATermList)_Slicing_dict, 1);

  S_patternAreasMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  S_patternAreasSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  S_patternAreasEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  S_patternSlicesMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  S_patternSlicesSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  S_patternSlicesEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  S_patternSliceDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
}
