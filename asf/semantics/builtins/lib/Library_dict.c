/*
 * Generated at Mon Sep 22 10:03:17 2003
 */

#include "Library_dict.h"



/*
 *
 *
 */

static ATermList _Library_dict = NULL;

#define _Library_dict_LEN 29

static char _Library_dict_baf[_Library_dict_LEN] = {
0x00,0x8B,0xAF,0x83,0x00,0x02,0x03,0x05,0x5B,0x5F,0x2C,0x5F,0x5D,0x02,0x00,0x02,
0x01,0x01,0x02,0x00,0x01,0x02,0x5B,0x5D,0x00,0x00,0x01,0x00,0x08
};

void init_Library_dict()
{
  ATermList afuns, terms;

  _Library_dict = (ATermList)ATreadFromBinaryString(_Library_dict_baf, _Library_dict_LEN);

  ATprotect((ATerm *)&_Library_dict);

  afuns = (ATermList)ATelementAt(_Library_dict, 0);


  terms = (ATermList)ATelementAt(_Library_dict, 1);

}
