/*
 * Generated at Fri Jun 15 16:02:59 2001
 */

#include "TA_dict.h"

AFun TA_afun0;
AFun TA_afun1;
AFun TA_afun2;
AFun TA_afun3;
AFun TA_afun4;
AFun TA_afun5;
AFun TA_afun6;

ATerm TA_patternPortStarted = NULL;
ATerm TA_patternPortStopped = NULL;
ATerm TA_patternPortStep = NULL;
ATerm TA_patternLocationUnknown = NULL;
ATerm TA_patternLocationLineCol = NULL;
ATerm TA_patternLocationArea = NULL;
ATerm TA_patternLocationLine = NULL;

/*
 * TA_afun0 = line(x,x)
 * TA_afun1 = area(x,x,x,x,x)
 * TA_afun2 = lc(x,x,x)
 * TA_afun3 = unknown
 * TA_afun4 = step
 * TA_afun5 = stopped
 * TA_afun6 = started
 *
 * TA_patternPortStarted = started
 * TA_patternPortStopped = stopped
 * TA_patternPortStep = step
 * TA_patternLocationUnknown = unknown
 * TA_patternLocationLineCol = lc(<str>,<int>,<int>)
 * TA_patternLocationArea = area(<str>,<int>,<int>,<int>,<int>)
 * TA_patternLocationLine = line(<str>,<int>)
 *
 */

static ATermList _TA_dict = NULL;

#define _TA_dict_LEN 188

static char _TA_dict_baf[_TA_dict_LEN] = {
0x00,0x8B,0xAF,0x83,0x00,0x0D,0x20,0x03,0x3C,0x5F,0x3E,0x01,0x00,0x02,0x02,0x03,
0x04,0x05,0x5B,0x5F,0x2C,0x5F,0x5D,0x02,0x00,0x10,0x08,0x01,0x06,0x07,0x08,0x09,
0x0A,0x0B,0x0C,0x02,0x01,0x02,0x02,0x5B,0x5D,0x00,0x00,0x01,0x03,0x69,0x6E,0x74,
0x00,0x00,0x01,0x03,0x73,0x74,0x72,0x00,0x00,0x01,0x01,0x78,0x00,0x00,0x01,0x04,
0x6C,0x69,0x6E,0x65,0x02,0x00,0x02,0x02,0x00,0x05,0x02,0x00,0x05,0x04,0x61,0x72,
0x65,0x61,0x05,0x00,0x02,0x02,0x00,0x05,0x02,0x00,0x05,0x02,0x00,0x05,0x02,0x00,
0x05,0x02,0x00,0x05,0x02,0x6C,0x63,0x03,0x00,0x02,0x02,0x00,0x05,0x02,0x00,0x05,
0x02,0x00,0x05,0x07,0x75,0x6E,0x6B,0x6E,0x6F,0x77,0x6E,0x00,0x00,0x01,0x04,0x73,
0x74,0x65,0x70,0x00,0x00,0x01,0x07,0x73,0x74,0x6F,0x70,0x70,0x65,0x64,0x00,0x00,
0x01,0x07,0x73,0x74,0x61,0x72,0x74,0x65,0x64,0x00,0x00,0x01,0x01,0x06,0x41,0x45,
0x10,0xAA,0x82,0x61,0x51,0x82,0x11,0x44,0x18,0x07,0x43,0x82,0xDC,0x19,0x8D,0x50,
0xA2,0x25,0x90,0x44,0x10,0x24,0x80,0x88,0x88,0xE4,0x40,0x54
};

void init_TA_dict()
{
  ATermList afuns, terms;

  _TA_dict = (ATermList)ATreadFromBinaryString(_TA_dict_baf, _TA_dict_LEN);

  ATprotect((ATerm *)&_TA_dict);

  afuns = (ATermList)ATelementAt(_TA_dict, 0);

  TA_afun0 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  TA_afun1 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  TA_afun2 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  TA_afun3 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  TA_afun4 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  TA_afun5 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  TA_afun6 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);

  terms = (ATermList)ATelementAt(_TA_dict, 1);

  TA_patternPortStarted = ATgetFirst(terms);
  terms = ATgetNext(terms);
  TA_patternPortStopped = ATgetFirst(terms);
  terms = ATgetNext(terms);
  TA_patternPortStep = ATgetFirst(terms);
  terms = ATgetNext(terms);
  TA_patternLocationUnknown = ATgetFirst(terms);
  terms = ATgetNext(terms);
  TA_patternLocationLineCol = ATgetFirst(terms);
  terms = ATgetNext(terms);
  TA_patternLocationArea = ATgetFirst(terms);
  terms = ATgetNext(terms);
  TA_patternLocationLine = ATgetFirst(terms);
  terms = ATgetNext(terms);
}
