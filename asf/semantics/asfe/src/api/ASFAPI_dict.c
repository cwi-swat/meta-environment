/*
 * Generated at Wed Dec 19 17:37:31 2001
 */

#include "ASFAPI_dict.h"

AFun AA_afun0;
AFun AA_afun1;
AFun AA_afun2;
AFun AA_afun3;
AFun AA_afun4;
AFun AA_afun5;
AFun AA_afun6;
AFun AA_afun7;
AFun AA_afun8;
AFun AA_afun9;
AFun AA_afun10;
AFun AA_afun11;

ATerm AA_patternResultFalse = NULL;
ATerm AA_patternResultTrue = NULL;
ATerm AA_patternCallsList = NULL;
ATerm AA_patternCallsEmpty = NULL;
ATerm AA_patternCallSetter = NULL;
ATerm AA_patternCallGetter = NULL;
ATerm AA_patternCallPredicate = NULL;
ATerm AA_patternCallConstructor = NULL;

/*
 * AA_afun0 = asf-constructor(x)
 * AA_afun1 = asf-predicate(x)
 * AA_afun2 = asf-getter(x,x)
 * AA_afun3 = asf-setter(x,x)
 * AA_afun4 = appl(x,x)
 * AA_afun5 = prod(x,x,x)
 * AA_afun6 = lit(x)
 * AA_afun7 = "true"
 * AA_afun8 = cf(x)
 * AA_afun9 = alt(x,x)
 * AA_afun10 = "false"
 * AA_afun11 = no-attrs
 *
 * AA_patternResultFalse = appl(prod([lit("true")],cf(alt(lit("true"),lit("false"))),no-attrs),[lit("false")])
 * AA_patternResultTrue = appl(prod([lit("true")],cf(alt(lit("true"),lit("false"))),no-attrs),[lit("true")])
 * AA_patternCallsList = [<term>,<list>]
 * AA_patternCallsEmpty = []
 * AA_patternCallSetter = asf-setter(<term>,<int>)
 * AA_patternCallGetter = asf-getter(<term>,<int>)
 * AA_patternCallPredicate = asf-predicate(<term>)
 * AA_patternCallConstructor = asf-constructor(<term>)
 *
 */

static ATermList _ASFAPI_dict = NULL;

#define _ASFAPI_dict_LEN 309

static char _ASFAPI_dict_baf[_ASFAPI_dict_LEN] = {
0x00,0x8B,0xAF,0x83,0x00,0x13,0x39,0x03,0x3C,0x5F,0x3E,0x01,0x00,0x03,0x03,0x03,
0x04,0x05,0x05,0x5B,0x5F,0x2C,0x5F,0x5D,0x02,0x00,0x1A,0x0F,0x01,0x02,0x00,0x07,
0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x02,0x01,0x02,0x02,0x5B,
0x5D,0x00,0x00,0x01,0x03,0x69,0x6E,0x74,0x00,0x00,0x01,0x04,0x6C,0x69,0x73,0x74,
0x00,0x00,0x01,0x04,0x74,0x65,0x72,0x6D,0x00,0x00,0x01,0x01,0x78,0x00,0x00,0x01,
0x0F,0x61,0x73,0x66,0x2D,0x63,0x6F,0x6E,0x73,0x74,0x72,0x75,0x63,0x74,0x6F,0x72,
0x01,0x00,0x02,0x02,0x00,0x06,0x0D,0x61,0x73,0x66,0x2D,0x70,0x72,0x65,0x64,0x69,
0x63,0x61,0x74,0x65,0x01,0x00,0x02,0x02,0x00,0x06,0x0A,0x61,0x73,0x66,0x2D,0x67,
0x65,0x74,0x74,0x65,0x72,0x02,0x00,0x02,0x02,0x00,0x06,0x02,0x00,0x06,0x0A,0x61,
0x73,0x66,0x2D,0x73,0x65,0x74,0x74,0x65,0x72,0x02,0x00,0x02,0x02,0x00,0x06,0x02,
0x00,0x06,0x04,0x61,0x70,0x70,0x6C,0x02,0x00,0x03,0x02,0x0C,0x06,0x02,0x01,0x06,
0x04,0x70,0x72,0x6F,0x64,0x03,0x00,0x02,0x02,0x01,0x06,0x02,0x0F,0x06,0x02,0x12,
0x06,0x03,0x6C,0x69,0x74,0x01,0x00,0x03,0x03,0x11,0x0E,0x06,0x04,0x74,0x72,0x75,
0x65,0x00,0x01,0x01,0x02,0x63,0x66,0x01,0x00,0x02,0x02,0x10,0x06,0x03,0x61,0x6C,
0x74,0x02,0x00,0x02,0x02,0x0D,0x06,0x02,0x0D,0x06,0x05,0x66,0x61,0x6C,0x73,0x65,
0x00,0x01,0x01,0x08,0x6E,0x6F,0x2D,0x61,0x74,0x74,0x72,0x73,0x00,0x00,0x01,0x01,
0x0D,0x61,0x0A,0x22,0x25,0x45,0x02,0x62,0x8E,0x71,0x43,0x04,0xA8,0xA4,0x88,0x45,
0x31,0xA4,0x20,0xCA,0x21,0x60,0x1E,0x06,0x1D,0xE8,0x83,0x4D,0x44,0x44,0x20,0x5A,
0x58,0x6F,0x24,0x18,0xA8,0x79,0x04,0x72,0x54,0x16,0x0C,0xB4,0x02,0x09,0xA8,0x04,
0x89,0x40,0x07,0x20,0xA0
};

void init_ASFAPI_dict()
{
  ATermList afuns, terms;

  _ASFAPI_dict = (ATermList)ATreadFromBinaryString(_ASFAPI_dict_baf, _ASFAPI_dict_LEN);

  ATprotect((ATerm *)&_ASFAPI_dict);

  afuns = (ATermList)ATelementAt(_ASFAPI_dict, 0);

  AA_afun0 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  AA_afun1 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  AA_afun2 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  AA_afun3 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  AA_afun4 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  AA_afun5 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  AA_afun6 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  AA_afun7 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  AA_afun8 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  AA_afun9 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  AA_afun10 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  AA_afun11 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);

  terms = (ATermList)ATelementAt(_ASFAPI_dict, 1);

  AA_patternResultFalse = ATgetFirst(terms);
  terms = ATgetNext(terms);
  AA_patternResultTrue = ATgetFirst(terms);
  terms = ATgetNext(terms);
  AA_patternCallsList = ATgetFirst(terms);
  terms = ATgetNext(terms);
  AA_patternCallsEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  AA_patternCallSetter = ATgetFirst(terms);
  terms = ATgetNext(terms);
  AA_patternCallGetter = ATgetFirst(terms);
  terms = ATgetNext(terms);
  AA_patternCallPredicate = ATgetFirst(terms);
  terms = ATgetNext(terms);
  AA_patternCallConstructor = ATgetFirst(terms);
  terms = ATgetNext(terms);
}
