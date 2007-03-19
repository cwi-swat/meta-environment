#include "MEPT_dict.h"

AFun PT_afun39;
AFun PT_afun17;
AFun PT_afun22;
AFun PT_afun3;
AFun PT_afun9;
AFun PT_afun34;
AFun PT_afun19;
AFun PT_afun26;
AFun PT_afun37;
AFun PT_afun2;
AFun PT_afun41;
AFun PT_afun12;
AFun PT_afun15;
AFun PT_afun25;
AFun PT_afun18;
AFun PT_afun20;
AFun PT_afun31;
AFun PT_afun8;
AFun PT_afun28;
AFun PT_afun21;
AFun PT_afun32;
AFun PT_afun0;
AFun PT_afun11;
AFun PT_afun5;
AFun PT_afun27;
AFun PT_afun33;
AFun PT_afun38;
AFun PT_afun16;
AFun PT_afun10;
AFun PT_afun13;
AFun PT_afun4;
AFun PT_afun14;
AFun PT_afun40;
AFun PT_afun23;
AFun PT_afun30;
AFun PT_afun7;
AFun PT_afun36;
AFun PT_afun24;
AFun PT_afun35;
AFun PT_afun29;
AFun PT_afun1;
AFun PT_afun6;


/*
 * PT_afun39 = layout
 * PT_afun17 = assoc
 * PT_afun22 = lex(x)
 * PT_afun3 = amb(x)
 * PT_afun9 = term(x)
 * PT_afun34 = iter-sep-n(x,x,x)
 * PT_afun19 = lit(x)
 * PT_afun26 = alt(x,x)
 * PT_afun37 = strategy(x,x)
 * PT_afun2 = cycle(x,x)
 * PT_afun41 = range(x,x)
 * PT_afun12 = reject
 * PT_afun15 = left
 * PT_afun25 = opt(x)
 * PT_afun18 = non-assoc
 * PT_afun20 = cilit(x)
 * PT_afun31 = iter-sep(x,x)
 * PT_afun8 = assoc(x)
 * PT_afun28 = sort(x)
 * PT_afun21 = cf(x)
 * PT_afun32 = iter-star-sep(x,x)
 * PT_afun0 = parsetree(x,x)
 * PT_afun11 = bracket
 * PT_afun5 = list(x)
 * PT_afun27 = tuple(x,x)
 * PT_afun33 = iter-n(x,x)
 * PT_afun38 = varsym(x)
 * PT_afun16 = right
 * PT_afun10 = id(x)
 * PT_afun13 = prefer
 * PT_afun4 = prod(x,x,x)
 * PT_afun14 = avoid
 * PT_afun40 = char-class(x)
 * PT_afun23 = empty
 * PT_afun30 = iter-star(x)
 * PT_afun7 = attrs(x)
 * PT_afun36 = parameterized-sort(x,x)
 * PT_afun24 = seq(x)
 * PT_afun35 = func(x,x)
 * PT_afun29 = iter(x)
 * PT_afun1 = appl(x,x)
 * PT_afun6 = no-attrs
 *
 *
 */

static ATerm _MEPT_dict = NULL;

#define _MEPT_dict_LEN 658

static char _MEPT_dict_baf[_MEPT_dict_LEN] = {
0x00,0x8B,0xAF,0x83,0x00,0x2D,0x58,0x05,0x5B,0x5F,0x2C,0x5F,0x5D,0x02,0x00,0x2C,
0x2C,0x00,0x01,0x02,0x03,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,
0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,
0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2A,0x2B,0x2C,0x02,0x00,0x01,
0x02,0x5B,0x5D,0x00,0x00,0x01,0x06,0x6C,0x61,0x79,0x6F,0x75,0x74,0x00,0x00,0x01,
0x05,0x61,0x73,0x73,0x6F,0x63,0x00,0x00,0x01,0x01,0x78,0x00,0x00,0x01,0x03,0x6C,
0x65,0x78,0x01,0x00,0x01,0x01,0x04,0x03,0x61,0x6D,0x62,0x01,0x00,0x01,0x01,0x04,
0x04,0x74,0x65,0x72,0x6D,0x01,0x00,0x01,0x01,0x04,0x0A,0x69,0x74,0x65,0x72,0x2D,
0x73,0x65,0x70,0x2D,0x6E,0x03,0x00,0x01,0x01,0x04,0x01,0x04,0x01,0x04,0x03,0x6C,
0x69,0x74,0x01,0x00,0x01,0x01,0x04,0x03,0x61,0x6C,0x74,0x02,0x00,0x01,0x01,0x04,
0x01,0x04,0x08,0x73,0x74,0x72,0x61,0x74,0x65,0x67,0x79,0x02,0x00,0x01,0x01,0x04,
0x01,0x04,0x05,0x63,0x79,0x63,0x6C,0x65,0x02,0x00,0x01,0x01,0x04,0x01,0x04,0x05,
0x72,0x61,0x6E,0x67,0x65,0x02,0x00,0x01,0x01,0x04,0x01,0x04,0x06,0x72,0x65,0x6A,
0x65,0x63,0x74,0x00,0x00,0x01,0x04,0x6C,0x65,0x66,0x74,0x00,0x00,0x01,0x03,0x6F,
0x70,0x74,0x01,0x00,0x01,0x01,0x04,0x09,0x6E,0x6F,0x6E,0x2D,0x61,0x73,0x73,0x6F,
0x63,0x00,0x00,0x01,0x05,0x63,0x69,0x6C,0x69,0x74,0x01,0x00,0x01,0x01,0x04,0x08,
0x69,0x74,0x65,0x72,0x2D,0x73,0x65,0x70,0x02,0x00,0x01,0x01,0x04,0x01,0x04,0x05,
0x61,0x73,0x73,0x6F,0x63,0x01,0x00,0x01,0x01,0x04,0x04,0x73,0x6F,0x72,0x74,0x01,
0x00,0x01,0x01,0x04,0x02,0x63,0x66,0x01,0x00,0x01,0x01,0x04,0x0D,0x69,0x74,0x65,
0x72,0x2D,0x73,0x74,0x61,0x72,0x2D,0x73,0x65,0x70,0x02,0x00,0x01,0x01,0x04,0x01,
0x04,0x09,0x70,0x61,0x72,0x73,0x65,0x74,0x72,0x65,0x65,0x02,0x00,0x01,0x01,0x04,
0x01,0x04,0x07,0x62,0x72,0x61,0x63,0x6B,0x65,0x74,0x00,0x00,0x01,0x04,0x6C,0x69,
0x73,0x74,0x01,0x00,0x01,0x01,0x04,0x05,0x74,0x75,0x70,0x6C,0x65,0x02,0x00,0x01,
0x01,0x04,0x01,0x04,0x06,0x69,0x74,0x65,0x72,0x2D,0x6E,0x02,0x00,0x01,0x01,0x04,
0x01,0x04,0x06,0x76,0x61,0x72,0x73,0x79,0x6D,0x01,0x00,0x01,0x01,0x04,0x05,0x72,
0x69,0x67,0x68,0x74,0x00,0x00,0x01,0x02,0x69,0x64,0x01,0x00,0x01,0x01,0x04,0x06,
0x70,0x72,0x65,0x66,0x65,0x72,0x00,0x00,0x01,0x04,0x70,0x72,0x6F,0x64,0x03,0x00,
0x01,0x01,0x04,0x01,0x04,0x01,0x04,0x05,0x61,0x76,0x6F,0x69,0x64,0x00,0x00,0x01,
0x0A,0x63,0x68,0x61,0x72,0x2D,0x63,0x6C,0x61,0x73,0x73,0x01,0x00,0x01,0x01,0x04,
0x05,0x65,0x6D,0x70,0x74,0x79,0x00,0x00,0x01,0x09,0x69,0x74,0x65,0x72,0x2D,0x73,
0x74,0x61,0x72,0x01,0x00,0x01,0x01,0x04,0x05,0x61,0x74,0x74,0x72,0x73,0x01,0x00,
0x01,0x01,0x04,0x12,0x70,0x61,0x72,0x61,0x6D,0x65,0x74,0x65,0x72,0x69,0x7A,0x65,
0x64,0x2D,0x73,0x6F,0x72,0x74,0x02,0x00,0x01,0x01,0x04,0x01,0x04,0x03,0x73,0x65,
0x71,0x01,0x00,0x01,0x01,0x04,0x04,0x66,0x75,0x6E,0x63,0x02,0x00,0x01,0x01,0x04,
0x01,0x04,0x04,0x69,0x74,0x65,0x72,0x01,0x00,0x01,0x01,0x04,0x04,0x61,0x70,0x70,
0x6C,0x02,0x00,0x01,0x01,0x04,0x01,0x04,0x08,0x6E,0x6F,0x2D,0x61,0x74,0x74,0x72,
0x73,0x00,0x00,0x01,0x00,0x02,0x54,0x01,0x70,0x39,0x20,0x66,0x82,0x96,0x02,0x78,
0x31,0x10,0x46,0x42,0x15,0x00,0x74,0x3E,0x30,0x7A,0xC2,0xE7,0x03,0xBC,0x36,0x08,
0x5A,0x22,0x64,0x81,0xB2,0x3A,0x28,0x6A,0xA2,0xA6,0x82,0xBA,0x32,0x18,0x4A,0x62,
0x25,0x80,0xB6,0x3C,0x38,0x72,0xE2,0xC7,0x83,0x3E,0x34,0x04,0x52,0x12,0x44,0x41,
0x31,0x38,0x24,0x62,0x92,0x86,0x42,0x39,0x30,0x14,0x42,0x52,0x05,0x40,0x35,0x85,
0x60,0x80
};

void init_MEPT_dict()
{
  ATermList afuns, terms;

  _MEPT_dict = ATreadFromBinaryString(_MEPT_dict_baf, _MEPT_dict_LEN);

  ATprotect(&_MEPT_dict);

  afuns = (ATermList)ATelementAt((ATermList)_MEPT_dict, 0);

  PT_afun39 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun39);
  afuns = ATgetNext(afuns);
  PT_afun17 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun17);
  afuns = ATgetNext(afuns);
  PT_afun22 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun22);
  afuns = ATgetNext(afuns);
  PT_afun3 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun3);
  afuns = ATgetNext(afuns);
  PT_afun9 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun9);
  afuns = ATgetNext(afuns);
  PT_afun34 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun34);
  afuns = ATgetNext(afuns);
  PT_afun19 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun19);
  afuns = ATgetNext(afuns);
  PT_afun26 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun26);
  afuns = ATgetNext(afuns);
  PT_afun37 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun37);
  afuns = ATgetNext(afuns);
  PT_afun2 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun2);
  afuns = ATgetNext(afuns);
  PT_afun41 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun41);
  afuns = ATgetNext(afuns);
  PT_afun12 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun12);
  afuns = ATgetNext(afuns);
  PT_afun15 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun15);
  afuns = ATgetNext(afuns);
  PT_afun25 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun25);
  afuns = ATgetNext(afuns);
  PT_afun18 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun18);
  afuns = ATgetNext(afuns);
  PT_afun20 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun20);
  afuns = ATgetNext(afuns);
  PT_afun31 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun31);
  afuns = ATgetNext(afuns);
  PT_afun8 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun8);
  afuns = ATgetNext(afuns);
  PT_afun28 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun28);
  afuns = ATgetNext(afuns);
  PT_afun21 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun21);
  afuns = ATgetNext(afuns);
  PT_afun32 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun32);
  afuns = ATgetNext(afuns);
  PT_afun0 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun0);
  afuns = ATgetNext(afuns);
  PT_afun11 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun11);
  afuns = ATgetNext(afuns);
  PT_afun5 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun5);
  afuns = ATgetNext(afuns);
  PT_afun27 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun27);
  afuns = ATgetNext(afuns);
  PT_afun33 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun33);
  afuns = ATgetNext(afuns);
  PT_afun38 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun38);
  afuns = ATgetNext(afuns);
  PT_afun16 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun16);
  afuns = ATgetNext(afuns);
  PT_afun10 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun10);
  afuns = ATgetNext(afuns);
  PT_afun13 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun13);
  afuns = ATgetNext(afuns);
  PT_afun4 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun4);
  afuns = ATgetNext(afuns);
  PT_afun14 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun14);
  afuns = ATgetNext(afuns);
  PT_afun40 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun40);
  afuns = ATgetNext(afuns);
  PT_afun23 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun23);
  afuns = ATgetNext(afuns);
  PT_afun30 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun30);
  afuns = ATgetNext(afuns);
  PT_afun7 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun7);
  afuns = ATgetNext(afuns);
  PT_afun36 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun36);
  afuns = ATgetNext(afuns);
  PT_afun24 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun24);
  afuns = ATgetNext(afuns);
  PT_afun35 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun35);
  afuns = ATgetNext(afuns);
  PT_afun29 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun29);
  afuns = ATgetNext(afuns);
  PT_afun1 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun1);
  afuns = ATgetNext(afuns);
  PT_afun6 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(PT_afun6);
  afuns = ATgetNext(afuns);

  terms = (ATermList)ATelementAt((ATermList)_MEPT_dict, 1);

}
