/*
 * Generated at Mon Mar 31 18:45:05 2003
 */

#include "Graph_dict.h"

AFun afun24;
AFun afun25;
AFun afun10;
AFun afun11;
AFun afun12;
AFun afun13;
AFun afun14;
AFun afun15;
AFun afun16;
AFun afun17;
AFun afun18;
AFun afun19;
AFun afun0;
AFun afun1;
AFun afun2;
AFun afun3;
AFun afun4;
AFun afun5;
AFun afun6;
AFun afun7;
AFun afun8;
AFun afun9;
AFun afun20;
AFun afun21;
AFun afun22;
AFun afun23;

ATerm patternPointDefault = NULL;
ATerm patternPolygonMulti = NULL;
ATerm patternPolygonEmpty = NULL;
ATerm patternEdgeDefault = NULL;
ATerm patternEdgeListMulti = NULL;
ATerm patternEdgeListEmpty = NULL;
ATerm patternDirectionNone = NULL;
ATerm patternDirectionBoth = NULL;
ATerm patternDirectionBack = NULL;
ATerm patternDirectionForward = NULL;
ATerm patternShapeOctagon = NULL;
ATerm patternShapeHexagon = NULL;
ATerm patternShapeHouse = NULL;
ATerm patternShapeParallelogram = NULL;
ATerm patternShapeTrapezium = NULL;
ATerm patternShapeDiamond = NULL;
ATerm patternShapeBox = NULL;
ATerm patternShapeTriangle = NULL;
ATerm patternShapeEgg = NULL;
ATerm patternShapeCircle = NULL;
ATerm patternShapeEllipse = NULL;
ATerm patternShapePlaintext = NULL;
ATerm patternAttributeDirection = NULL;
ATerm patternAttributeCurvePoints = NULL;
ATerm patternAttributeSize = NULL;
ATerm patternAttributeLocation = NULL;
ATerm patternAttributeShape = NULL;
ATerm patternAttributeLabel = NULL;
ATerm patternAttributeListMulti = NULL;
ATerm patternAttributeListEmpty = NULL;
ATerm patternNodeIdDefault = NULL;
ATerm patternNodeDefault = NULL;
ATerm patternNodeListMulti = NULL;
ATerm patternNodeListEmpty = NULL;
ATerm patternGraphDefault = NULL;

/*
 * afun24 = edge(x,x,x)
 * afun25 = point(x,x)
 * afun10 = circle
 * afun11 = egg
 * afun12 = triangle
 * afun13 = box
 * afun14 = diamond
 * afun15 = trapezium
 * afun16 = parallelogram
 * afun17 = house
 * afun18 = hexagon
 * afun19 = octagon
 * afun0 = graph(x,x)
 * afun1 = node(x,x)
 * afun2 = label(x)
 * afun3 = shape(x)
 * afun4 = location(x,x)
 * afun5 = size(x,x)
 * afun6 = curve-points(x)
 * afun7 = direction(x)
 * afun8 = plaintext
 * afun9 = ellipse
 * afun20 = forward
 * afun21 = back
 * afun22 = both
 * afun23 = none
 *
 * patternPointDefault = point(<int>,<int>)
 * patternPolygonMulti = [<term>,<list>]
 * patternPolygonEmpty = []
 * patternEdgeDefault = edge(<term>,<term>,<term>)
 * patternEdgeListMulti = [<term>,<list>]
 * patternEdgeListEmpty = []
 * patternDirectionNone = none
 * patternDirectionBoth = both
 * patternDirectionBack = back
 * patternDirectionForward = forward
 * patternShapeOctagon = octagon
 * patternShapeHexagon = hexagon
 * patternShapeHouse = house
 * patternShapeParallelogram = parallelogram
 * patternShapeTrapezium = trapezium
 * patternShapeDiamond = diamond
 * patternShapeBox = box
 * patternShapeTriangle = triangle
 * patternShapeEgg = egg
 * patternShapeCircle = circle
 * patternShapeEllipse = ellipse
 * patternShapePlaintext = plaintext
 * patternAttributeDirection = direction(<term>)
 * patternAttributeCurvePoints = curve-points(<term>)
 * patternAttributeSize = size(<int>,<int>)
 * patternAttributeLocation = location(<int>,<int>)
 * patternAttributeShape = shape(<term>)
 * patternAttributeLabel = label(<str>)
 * patternAttributeListMulti = [<term>,<list>]
 * patternAttributeListEmpty = []
 * patternNodeIdDefault = <str>
 * patternNodeDefault = node(<term>,<term>)
 * patternNodeListMulti = [<term>,<list>]
 * patternNodeListEmpty = []
 * patternGraphDefault = graph(<term>,<term>)
 *
 */

static ATermList _Graph_dict = NULL;

#define _Graph_dict_LEN 560

static char _Graph_dict_baf[_Graph_dict_LEN] = {
0x00,0x8B,0xAF,0x83,0x00,0x22,0x6F,0x03,0x3C,0x5F,0x3E,0x01,0x00,0x04,0x04,0x04,
0x05,0x06,0x03,0x05,0x5B,0x5F,0x2C,0x5F,0x5D,0x02,0x00,0x41,0x1D,0x01,0x02,0x00,
0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,
0x18,0x19,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,0x20,0x21,0x02,0x01,0x02,0x02,0x5B,0x5D,
0x00,0x00,0x01,0x03,0x69,0x6E,0x74,0x00,0x00,0x01,0x03,0x73,0x74,0x72,0x00,0x00,
0x01,0x04,0x6C,0x69,0x73,0x74,0x00,0x00,0x01,0x04,0x74,0x65,0x72,0x6D,0x00,0x00,
0x01,0x01,0x78,0x00,0x00,0x01,0x04,0x65,0x64,0x67,0x65,0x03,0x00,0x02,0x02,0x00,
0x07,0x02,0x00,0x07,0x02,0x00,0x07,0x05,0x70,0x6F,0x69,0x6E,0x74,0x02,0x00,0x02,
0x02,0x00,0x07,0x02,0x00,0x07,0x06,0x63,0x69,0x72,0x63,0x6C,0x65,0x00,0x00,0x01,
0x03,0x65,0x67,0x67,0x00,0x00,0x01,0x08,0x74,0x72,0x69,0x61,0x6E,0x67,0x6C,0x65,
0x00,0x00,0x01,0x03,0x62,0x6F,0x78,0x00,0x00,0x01,0x07,0x64,0x69,0x61,0x6D,0x6F,
0x6E,0x64,0x00,0x00,0x01,0x09,0x74,0x72,0x61,0x70,0x65,0x7A,0x69,0x75,0x6D,0x00,
0x00,0x01,0x0D,0x70,0x61,0x72,0x61,0x6C,0x6C,0x65,0x6C,0x6F,0x67,0x72,0x61,0x6D,
0x00,0x00,0x01,0x05,0x68,0x6F,0x75,0x73,0x65,0x00,0x00,0x01,0x07,0x68,0x65,0x78,
0x61,0x67,0x6F,0x6E,0x00,0x00,0x01,0x07,0x6F,0x63,0x74,0x61,0x67,0x6F,0x6E,0x00,
0x00,0x01,0x05,0x67,0x72,0x61,0x70,0x68,0x02,0x00,0x02,0x02,0x00,0x07,0x02,0x00,
0x07,0x04,0x6E,0x6F,0x64,0x65,0x02,0x00,0x02,0x02,0x00,0x07,0x02,0x00,0x07,0x05,
0x6C,0x61,0x62,0x65,0x6C,0x01,0x00,0x02,0x02,0x00,0x07,0x05,0x73,0x68,0x61,0x70,
0x65,0x01,0x00,0x02,0x02,0x00,0x07,0x08,0x6C,0x6F,0x63,0x61,0x74,0x69,0x6F,0x6E,
0x02,0x00,0x02,0x02,0x00,0x07,0x02,0x00,0x07,0x04,0x73,0x69,0x7A,0x65,0x02,0x00,
0x02,0x02,0x00,0x07,0x02,0x00,0x07,0x0C,0x63,0x75,0x72,0x76,0x65,0x2D,0x70,0x6F,
0x69,0x6E,0x74,0x73,0x01,0x00,0x02,0x02,0x00,0x07,0x09,0x64,0x69,0x72,0x65,0x63,
0x74,0x69,0x6F,0x6E,0x01,0x00,0x02,0x02,0x00,0x07,0x09,0x70,0x6C,0x61,0x69,0x6E,
0x74,0x65,0x78,0x74,0x00,0x00,0x01,0x07,0x65,0x6C,0x6C,0x69,0x70,0x73,0x65,0x00,
0x00,0x01,0x07,0x66,0x6F,0x72,0x77,0x61,0x72,0x64,0x00,0x00,0x01,0x04,0x62,0x61,
0x63,0x6B,0x00,0x00,0x01,0x04,0x62,0x6F,0x74,0x68,0x00,0x00,0x01,0x04,0x6E,0x6F,
0x6E,0x65,0x00,0x00,0x01,0x01,0x04,0xCC,0x15,0x03,0x08,0x51,0xD2,0x83,0x46,0x15,
0x38,0x14,0x11,0x92,0x42,0x45,0x11,0x34,0x04,0x31,0xE2,0xC3,0x87,0x16,0x3C,0x50,
0x60,0x25,0x1A,0x22,0x42,0x84,0x91,0x23,0x25,0x02,0x0A,0x51,0xC2,0xA4,0x30,0x69,
0x14,0x3A,0x10,0x19,0x82,0x62,0x05,0x90,0x36,0x00,0x3C,0x7E,0x03,0xE2,0x40,0xC0,
0x2F,0x03,0x62,0x22,0x16,0x21,0x48,0x3D,0x03,0x76,0x22,0x10,0x82,0xE0,0x6C,0x27,
0x40,0x1C,0x73,0xB6,0xC6,0xCB,0x2B,0x4C,0x2C,0xE3,0x35,0x84,0xC6,0x23,0x68,0x0C,
0xA3,0xD4,0x87,0x42,0x2D,0x70,0x34,0xC3,0x55,0x05,0x43,0x25,0x74,0x14,0xD8,0x87,
0x2A,0xC4,0x19,0x16,0x00,0x0A,0x59,0x80,0x00,0x92,0x62,0x18,0xA3,0x18,0x08,0x81,
0xB0,0x85,0x00,0x12,0x31,0xF0,0x31,0x08,0x3C,0x06,0xC2,0xE4,0x03,0x9E,0x88,0x4A
};

void init_Graph_dict()
{
  ATermList afuns, terms;

  _Graph_dict = (ATermList)ATreadFromBinaryString(_Graph_dict_baf, _Graph_dict_LEN);

  ATprotect((ATerm *)&_Graph_dict);

  afuns = (ATermList)ATelementAt(_Graph_dict, 0);

  afun24 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun25 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun10 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun11 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun12 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun13 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun14 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun15 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun16 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun17 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun18 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun19 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun0 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun1 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun2 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun3 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun4 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun5 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun6 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun7 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun8 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun9 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun20 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun21 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun22 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun23 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);

  terms = (ATermList)ATelementAt(_Graph_dict, 1);

  patternPointDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternPolygonMulti = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternPolygonEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternEdgeDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternEdgeListMulti = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternEdgeListEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternDirectionNone = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternDirectionBoth = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternDirectionBack = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternDirectionForward = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternShapeOctagon = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternShapeHexagon = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternShapeHouse = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternShapeParallelogram = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternShapeTrapezium = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternShapeDiamond = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternShapeBox = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternShapeTriangle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternShapeEgg = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternShapeCircle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternShapeEllipse = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternShapePlaintext = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternAttributeDirection = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternAttributeCurvePoints = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternAttributeSize = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternAttributeLocation = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternAttributeShape = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternAttributeLabel = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternAttributeListMulti = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternAttributeListEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternNodeIdDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternNodeDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternNodeListMulti = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternNodeListEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternGraphDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
}
