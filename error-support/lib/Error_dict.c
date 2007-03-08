#include "Error_dict.h"

AFun ERR_afun8;
AFun ERR_afun4;
AFun ERR_afun0;
AFun ERR_afun2;
AFun ERR_afun11;
AFun ERR_afun7;
AFun ERR_afun5;
AFun ERR_afun3;
AFun ERR_afun9;
AFun ERR_afun10;
AFun ERR_afun1;
AFun ERR_afun6;


/*
 * ERR_afun8 = area(x)
 * ERR_afun4 = error(x,x)
 * ERR_afun0 = subject(x)
 * ERR_afun2 = info(x,x)
 * ERR_afun11 = slice(x,x)
 * ERR_afun7 = file(x)
 * ERR_afun5 = fatal(x,x)
 * ERR_afun3 = warning(x,x)
 * ERR_afun9 = area-in-file(x,x)
 * ERR_afun10 = area(x,x,x,x,x,x)
 * ERR_afun1 = localized(x,x)
 * ERR_afun6 = summary(x,x,x)
 *
 *
 */

static ATerm _Error_dict = NULL;

#define _Error_dict_LEN 236

static char _Error_dict_baf[_Error_dict_LEN] = {
0x00,0x8B,0xAF,0x83,0x00,0x0F,0x1C,0x05,0x5B,0x5F,0x2C,0x5F,0x5D,0x02,0x00,0x0E,
0x0E,0x00,0x01,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x02,
0x00,0x01,0x02,0x5B,0x5D,0x00,0x00,0x01,0x01,0x78,0x00,0x00,0x01,0x04,0x61,0x72,
0x65,0x61,0x01,0x00,0x01,0x01,0x02,0x05,0x65,0x72,0x72,0x6F,0x72,0x02,0x00,0x01,
0x01,0x02,0x01,0x02,0x07,0x73,0x75,0x62,0x6A,0x65,0x63,0x74,0x01,0x00,0x01,0x01,
0x02,0x04,0x69,0x6E,0x66,0x6F,0x02,0x00,0x01,0x01,0x02,0x01,0x02,0x05,0x73,0x6C,
0x69,0x63,0x65,0x02,0x00,0x01,0x01,0x02,0x01,0x02,0x04,0x66,0x69,0x6C,0x65,0x01,
0x00,0x01,0x01,0x02,0x05,0x66,0x61,0x74,0x61,0x6C,0x02,0x00,0x01,0x01,0x02,0x01,
0x02,0x07,0x77,0x61,0x72,0x6E,0x69,0x6E,0x67,0x02,0x00,0x01,0x01,0x02,0x01,0x02,
0x0C,0x61,0x72,0x65,0x61,0x2D,0x69,0x6E,0x2D,0x66,0x69,0x6C,0x65,0x02,0x00,0x01,
0x01,0x02,0x01,0x02,0x04,0x61,0x72,0x65,0x61,0x06,0x00,0x01,0x01,0x02,0x01,0x02,
0x01,0x02,0x01,0x02,0x01,0x02,0x01,0x02,0x09,0x6C,0x6F,0x63,0x61,0x6C,0x69,0x7A,
0x65,0x64,0x02,0x00,0x01,0x01,0x02,0x01,0x02,0x07,0x73,0x75,0x6D,0x6D,0x61,0x72,
0x79,0x03,0x00,0x01,0x01,0x02,0x01,0x02,0x01,0x02,0x00,0x0D,0x41,0x70,0x92,0x06,
0x8E,0x61,0xB8,0xA1,0x0A,0x4C,0x51,0x34,0x83,0x02,0xE0,0xE2
};

void init_Error_dict()
{
  ATermList afuns, terms;

  _Error_dict = ATreadFromBinaryString(_Error_dict_baf, _Error_dict_LEN);

  ATprotect(&_Error_dict);

  afuns = (ATermList)ATelementAt((ATermList)_Error_dict, 0);

  ERR_afun8 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ERR_afun4 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ERR_afun0 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ERR_afun2 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ERR_afun11 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ERR_afun7 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ERR_afun5 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ERR_afun3 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ERR_afun9 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ERR_afun10 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ERR_afun1 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  ERR_afun6 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);

  terms = (ATermList)ATelementAt((ATermList)_Error_dict, 1);

}
