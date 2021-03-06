#include "Graph_dict.h"

AFun afun16;
AFun afun15;
AFun afun14;
AFun afun13;
AFun afun39;
AFun afun38;
AFun afun19;
AFun afun37;
AFun afun18;
AFun afun36;
AFun afun17;
AFun afun35;
AFun afun22;
AFun afun40;
AFun afun23;
AFun afun41;
AFun afun20;
AFun afun21;
AFun afun4;
AFun afun5;
AFun afun2;
AFun afun3;
AFun afun0;
AFun afun1;
AFun afun29;
AFun afun28;
AFun afun8;
AFun afun25;
AFun afun24;
AFun afun9;
AFun afun6;
AFun afun27;
AFun afun7;
AFun afun26;
AFun afun31;
AFun afun32;
AFun afun33;
AFun afun34;
AFun afun10;
AFun afun11;
AFun afun12;
AFun afun30;


/*
 * afun16 = file(x)
 * afun15 = level(x)
 * afun14 = style(x)
 * afun13 = size(x,x)
 * afun39 = none
 * afun38 = both
 * afun19 = dashed
 * afun37 = back
 * afun18 = bold
 * afun36 = forward
 * afun17 = rgb(x,x,x)
 * afun35 = triangle
 * afun22 = invisible
 * afun40 = edge(x,x,x)
 * afun23 = solid
 * afun41 = point(x,x)
 * afun20 = dotted
 * afun21 = filled
 * afun4 = color(x)
 * afun5 = curve-points(x)
 * afun2 = subgraph(x,x,x,x)
 * afun3 = bounding-box(x,x)
 * afun0 = graph(x,x,x)
 * afun1 = node(x,x)
 * afun29 = hexagon
 * afun28 = ellipse
 * afun8 = info(x,x)
 * afun25 = circle
 * afun24 = box
 * afun9 = label(x)
 * afun6 = direction(x)
 * afun27 = egg
 * afun7 = fill-color(x)
 * afun26 = diamond
 * afun31 = octagon
 * afun32 = parallelogram
 * afun33 = plaintext
 * afun34 = trapezium
 * afun10 = tooltip(x)
 * afun11 = location(x,x)
 * afun12 = shape(x)
 * afun30 = house
 *
 *
 */

static ATerm _Graph_dict = NULL;

#define _Graph_dict_LEN 654

static unsigned char _Graph_dict_baf[_Graph_dict_LEN] = {
0x00,0x8B,0xAF,0x83,0x00,0x2D,0x58,0x05,0x5B,0x5F,0x2C,0x5F,0x5D,0x02,0x00,0x2C,
0x2C,0x00,0x01,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,
0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,
0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2A,0x2B,0x2C,0x02,0x00,0x01,
0x02,0x5B,0x5D,0x00,0x00,0x01,0x01,0x78,0x00,0x00,0x01,0x04,0x66,0x69,0x6C,0x65,
0x01,0x00,0x01,0x01,0x02,0x05,0x6C,0x65,0x76,0x65,0x6C,0x01,0x00,0x01,0x01,0x02,
0x05,0x73,0x74,0x79,0x6C,0x65,0x01,0x00,0x01,0x01,0x02,0x04,0x73,0x69,0x7A,0x65,
0x02,0x00,0x01,0x01,0x02,0x01,0x02,0x04,0x6E,0x6F,0x6E,0x65,0x00,0x00,0x01,0x04,
0x62,0x6F,0x74,0x68,0x00,0x00,0x01,0x06,0x64,0x61,0x73,0x68,0x65,0x64,0x00,0x00,
0x01,0x04,0x62,0x61,0x63,0x6B,0x00,0x00,0x01,0x04,0x62,0x6F,0x6C,0x64,0x00,0x00,
0x01,0x07,0x66,0x6F,0x72,0x77,0x61,0x72,0x64,0x00,0x00,0x01,0x03,0x72,0x67,0x62,
0x03,0x00,0x01,0x01,0x02,0x01,0x02,0x01,0x02,0x08,0x74,0x72,0x69,0x61,0x6E,0x67,
0x6C,0x65,0x00,0x00,0x01,0x09,0x69,0x6E,0x76,0x69,0x73,0x69,0x62,0x6C,0x65,0x00,
0x00,0x01,0x04,0x65,0x64,0x67,0x65,0x03,0x00,0x01,0x01,0x02,0x01,0x02,0x01,0x02,
0x05,0x73,0x6F,0x6C,0x69,0x64,0x00,0x00,0x01,0x05,0x70,0x6F,0x69,0x6E,0x74,0x02,
0x00,0x01,0x01,0x02,0x01,0x02,0x06,0x64,0x6F,0x74,0x74,0x65,0x64,0x00,0x00,0x01,
0x06,0x66,0x69,0x6C,0x6C,0x65,0x64,0x00,0x00,0x01,0x05,0x63,0x6F,0x6C,0x6F,0x72,
0x01,0x00,0x01,0x01,0x02,0x0C,0x63,0x75,0x72,0x76,0x65,0x2D,0x70,0x6F,0x69,0x6E,
0x74,0x73,0x01,0x00,0x01,0x01,0x02,0x08,0x73,0x75,0x62,0x67,0x72,0x61,0x70,0x68,
0x04,0x00,0x01,0x01,0x02,0x01,0x02,0x01,0x02,0x01,0x02,0x0C,0x62,0x6F,0x75,0x6E,
0x64,0x69,0x6E,0x67,0x2D,0x62,0x6F,0x78,0x02,0x00,0x01,0x01,0x02,0x01,0x02,0x05,
0x67,0x72,0x61,0x70,0x68,0x03,0x00,0x01,0x01,0x02,0x01,0x02,0x01,0x02,0x04,0x6E,
0x6F,0x64,0x65,0x02,0x00,0x01,0x01,0x02,0x01,0x02,0x07,0x68,0x65,0x78,0x61,0x67,
0x6F,0x6E,0x00,0x00,0x01,0x07,0x65,0x6C,0x6C,0x69,0x70,0x73,0x65,0x00,0x00,0x01,
0x04,0x69,0x6E,0x66,0x6F,0x02,0x00,0x01,0x01,0x02,0x01,0x02,0x06,0x63,0x69,0x72,
0x63,0x6C,0x65,0x00,0x00,0x01,0x03,0x62,0x6F,0x78,0x00,0x00,0x01,0x05,0x6C,0x61,
0x62,0x65,0x6C,0x01,0x00,0x01,0x01,0x02,0x09,0x64,0x69,0x72,0x65,0x63,0x74,0x69,
0x6F,0x6E,0x01,0x00,0x01,0x01,0x02,0x03,0x65,0x67,0x67,0x00,0x00,0x01,0x0A,0x66,
0x69,0x6C,0x6C,0x2D,0x63,0x6F,0x6C,0x6F,0x72,0x01,0x00,0x01,0x01,0x02,0x07,0x64,
0x69,0x61,0x6D,0x6F,0x6E,0x64,0x00,0x00,0x01,0x07,0x6F,0x63,0x74,0x61,0x67,0x6F,
0x6E,0x00,0x00,0x01,0x0D,0x70,0x61,0x72,0x61,0x6C,0x6C,0x65,0x6C,0x6F,0x67,0x72,
0x61,0x6D,0x00,0x00,0x01,0x09,0x70,0x6C,0x61,0x69,0x6E,0x74,0x65,0x78,0x74,0x00,
0x00,0x01,0x09,0x74,0x72,0x61,0x70,0x65,0x7A,0x69,0x75,0x6D,0x00,0x00,0x01,0x07,
0x74,0x6F,0x6F,0x6C,0x74,0x69,0x70,0x01,0x00,0x01,0x01,0x02,0x08,0x6C,0x6F,0x63,
0x61,0x74,0x69,0x6F,0x6E,0x02,0x00,0x01,0x01,0x02,0x01,0x02,0x05,0x73,0x68,0x61,
0x70,0x65,0x01,0x00,0x01,0x01,0x02,0x05,0x68,0x6F,0x75,0x73,0x65,0x00,0x00,0x01,
0x00,0x02,0x54,0x01,0x70,0x39,0x20,0x66,0x82,0x96,0x02,0x78,0x31,0x10,0x46,0x42,
0x15,0x00,0x74,0x3E,0x30,0x7A,0xC2,0xE7,0x03,0xBC,0x36,0x08,0x5A,0x22,0x64,0x81,
0xB2,0x3A,0x28,0x6A,0xA2,0xA6,0x82,0xBA,0x32,0x18,0x4A,0x62,0x25,0x80,0xB6,0x3C,
0x38,0x72,0xE2,0xC7,0x83,0x3E,0x34,0x04,0x52,0x12,0x44,0x41,0x31,0x38,0x24,0x62,
0x92,0x86,0x42,0x39,0x30,0x14,0x42,0x52,0x05,0x40,0x35,0x85,0x60,0x80
};

void init_Graph_dict()
{
  ATermList afuns, terms;

  _Graph_dict = ATreadFromBinaryString(_Graph_dict_baf, _Graph_dict_LEN);

  ATprotect(&_Graph_dict);

  afuns = (ATermList)ATelementAt((ATermList)_Graph_dict, 0);

  afun16 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun16);
  afuns = ATgetNext(afuns);
  afun15 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun15);
  afuns = ATgetNext(afuns);
  afun14 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun14);
  afuns = ATgetNext(afuns);
  afun13 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun13);
  afuns = ATgetNext(afuns);
  afun39 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun39);
  afuns = ATgetNext(afuns);
  afun38 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun38);
  afuns = ATgetNext(afuns);
  afun19 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun19);
  afuns = ATgetNext(afuns);
  afun37 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun37);
  afuns = ATgetNext(afuns);
  afun18 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun18);
  afuns = ATgetNext(afuns);
  afun36 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun36);
  afuns = ATgetNext(afuns);
  afun17 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun17);
  afuns = ATgetNext(afuns);
  afun35 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun35);
  afuns = ATgetNext(afuns);
  afun22 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun22);
  afuns = ATgetNext(afuns);
  afun40 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun40);
  afuns = ATgetNext(afuns);
  afun23 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun23);
  afuns = ATgetNext(afuns);
  afun41 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun41);
  afuns = ATgetNext(afuns);
  afun20 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun20);
  afuns = ATgetNext(afuns);
  afun21 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun21);
  afuns = ATgetNext(afuns);
  afun4 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun4);
  afuns = ATgetNext(afuns);
  afun5 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun5);
  afuns = ATgetNext(afuns);
  afun2 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun2);
  afuns = ATgetNext(afuns);
  afun3 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun3);
  afuns = ATgetNext(afuns);
  afun0 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun0);
  afuns = ATgetNext(afuns);
  afun1 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun1);
  afuns = ATgetNext(afuns);
  afun29 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun29);
  afuns = ATgetNext(afuns);
  afun28 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun28);
  afuns = ATgetNext(afuns);
  afun8 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun8);
  afuns = ATgetNext(afuns);
  afun25 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun25);
  afuns = ATgetNext(afuns);
  afun24 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun24);
  afuns = ATgetNext(afuns);
  afun9 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun9);
  afuns = ATgetNext(afuns);
  afun6 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun6);
  afuns = ATgetNext(afuns);
  afun27 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun27);
  afuns = ATgetNext(afuns);
  afun7 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun7);
  afuns = ATgetNext(afuns);
  afun26 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun26);
  afuns = ATgetNext(afuns);
  afun31 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun31);
  afuns = ATgetNext(afuns);
  afun32 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun32);
  afuns = ATgetNext(afuns);
  afun33 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun33);
  afuns = ATgetNext(afuns);
  afun34 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun34);
  afuns = ATgetNext(afuns);
  afun10 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun10);
  afuns = ATgetNext(afuns);
  afun11 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun11);
  afuns = ATgetNext(afuns);
  afun12 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun12);
  afuns = ATgetNext(afuns);
  afun30 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  ATprotectAFun(afun30);
  afuns = ATgetNext(afuns);

  terms = (ATermList)ATelementAt((ATermList)_Graph_dict, 1);

}
