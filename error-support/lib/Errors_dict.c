#include "Errors_dict.h"



/*
 *
 *
 */

static ATerm _Errors_dict = NULL;

#define _Errors_dict_LEN 29

static char _Errors_dict_baf[_Errors_dict_LEN] = {
0x00,0x8B,0xAF,0x83,0x00,0x02,0x03,0x05,0x5B,0x5F,0x2C,0x5F,0x5D,0x02,0x00,0x02,
0x01,0x01,0x02,0x00,0x01,0x02,0x5B,0x5D,0x00,0x00,0x01,0x00,0x08
};

void init_Errors_dict()
{
  ATermList afuns, terms;

  _Errors_dict = ATreadFromBinaryString(_Errors_dict_baf, _Errors_dict_LEN);

  ATprotect(&_Errors_dict);

  afuns = (ATermList)ATelementAt((ATermList)_Errors_dict, 0);


  terms = (ATermList)ATelementAt((ATermList)_Errors_dict, 1);

}
