#include "Graph_dict.h"

AFun afun39;
AFun afun17;
AFun afun22;
AFun afun3;
AFun afun9;
AFun afun34;
AFun afun19;
AFun afun26;
AFun afun37;
AFun afun2;
AFun afun12;
AFun afun15;
AFun afun25;
AFun afun18;
AFun afun20;
AFun afun31;
AFun afun8;
AFun afun28;
AFun afun21;
AFun afun32;
AFun afun0;
AFun afun11;
AFun afun5;
AFun afun27;
AFun afun33;
AFun afun38;
AFun afun16;
AFun afun10;
AFun afun13;
AFun afun4;
AFun afun14;
AFun afun23;
AFun afun30;
AFun afun7;
AFun afun36;
AFun afun24;
AFun afun35;
AFun afun29;
AFun afun1;
AFun afun6;

ATerm patternPointDefault = NULL;
ATerm patternPolygonMany = NULL;
ATerm patternPolygonSingle = NULL;
ATerm patternPolygonEmpty = NULL;
ATerm patternEdgeDefault = NULL;
ATerm patternEdgeListMany = NULL;
ATerm patternEdgeListSingle = NULL;
ATerm patternEdgeListEmpty = NULL;
ATerm patternDirectionNone = NULL;
ATerm patternDirectionBoth = NULL;
ATerm patternDirectionBack = NULL;
ATerm patternDirectionForward = NULL;
ATerm patternShapeTriangle = NULL;
ATerm patternShapeTrapezium = NULL;
ATerm patternShapePlaintext = NULL;
ATerm patternShapeParallelogram = NULL;
ATerm patternShapeOctagon = NULL;
ATerm patternShapeHouse = NULL;
ATerm patternShapeHexagon = NULL;
ATerm patternShapeEllipse = NULL;
ATerm patternShapeEgg = NULL;
ATerm patternShapeDiamond = NULL;
ATerm patternShapeCircle = NULL;
ATerm patternShapeBox = NULL;
ATerm patternStyleSolid = NULL;
ATerm patternStyleInvisible = NULL;
ATerm patternStyleFilled = NULL;
ATerm patternStyleDotted = NULL;
ATerm patternStyleDashed = NULL;
ATerm patternStyleBold = NULL;
ATerm patternColorRgb = NULL;
ATerm patternFileExternal = NULL;
ATerm patternAttributeFile = NULL;
ATerm patternAttributeLevel = NULL;
ATerm patternAttributeStyle = NULL;
ATerm patternAttributeSize = NULL;
ATerm patternAttributeShape = NULL;
ATerm patternAttributeLocation = NULL;
ATerm patternAttributeLabel = NULL;
ATerm patternAttributeInfo = NULL;
ATerm patternAttributeFillColor = NULL;
ATerm patternAttributeDirection = NULL;
ATerm patternAttributeCurvePoints = NULL;
ATerm patternAttributeColor = NULL;
ATerm patternAttributeBoundingBox = NULL;
ATerm patternAttributeListMany = NULL;
ATerm patternAttributeListSingle = NULL;
ATerm patternAttributeListEmpty = NULL;
ATerm patternNodeIdDefault = NULL;
ATerm patternNodeDefault = NULL;
ATerm patternNodeListMany = NULL;
ATerm patternNodeListSingle = NULL;
ATerm patternNodeListEmpty = NULL;
ATerm patternGraphDefault = NULL;

/*
 * afun39 = point(x,x)
 * afun17 = dashed
 * afun22 = box
 * afun3 = color(x)
 * afun9 = location(x,x)
 * afun34 = forward
 * afun19 = filled
 * afun26 = ellipse
 * afun37 = none
 * afun2 = bounding-box(x,x)
 * afun12 = style(x)
 * afun15 = rgb(x,x,x)
 * afun25 = egg
 * afun18 = dotted
 * afun20 = invisible
 * afun31 = plaintext
 * afun8 = label(x)
 * afun28 = house
 * afun21 = solid
 * afun32 = trapezium
 * afun0 = graph(x,x,x)
 * afun11 = size(x,x)
 * afun5 = direction(x)
 * afun27 = hexagon
 * afun33 = triangle
 * afun38 = edge(x,x,x)
 * afun16 = bold
 * afun10 = shape(x)
 * afun13 = level(x)
 * afun4 = curve-points(x)
 * afun14 = file(x)
 * afun23 = circle
 * afun30 = parallelogram
 * afun7 = info(x,x)
 * afun36 = both
 * afun24 = diamond
 * afun35 = back
 * afun29 = octagon
 * afun1 = node(x,x)
 * afun6 = fill-color(x)
 *
 * patternPointDefault = point(<int>,<int>)
 * patternPolygonMany = [<term>,<list>]
 * patternPolygonSingle = [<term>]
 * patternPolygonEmpty = []
 * patternEdgeDefault = edge(<term>,<term>,<term>)
 * patternEdgeListMany = [<term>,<list>]
 * patternEdgeListSingle = [<term>]
 * patternEdgeListEmpty = []
 * patternDirectionNone = none
 * patternDirectionBoth = both
 * patternDirectionBack = back
 * patternDirectionForward = forward
 * patternShapeTriangle = triangle
 * patternShapeTrapezium = trapezium
 * patternShapePlaintext = plaintext
 * patternShapeParallelogram = parallelogram
 * patternShapeOctagon = octagon
 * patternShapeHouse = house
 * patternShapeHexagon = hexagon
 * patternShapeEllipse = ellipse
 * patternShapeEgg = egg
 * patternShapeDiamond = diamond
 * patternShapeCircle = circle
 * patternShapeBox = box
 * patternStyleSolid = solid
 * patternStyleInvisible = invisible
 * patternStyleFilled = filled
 * patternStyleDotted = dotted
 * patternStyleDashed = dashed
 * patternStyleBold = bold
 * patternColorRgb = rgb(<int>,<int>,<int>)
 * patternFileExternal = <term>
 * patternAttributeFile = file(<term>)
 * patternAttributeLevel = level(<str>)
 * patternAttributeStyle = style(<term>)
 * patternAttributeSize = size(<int>,<int>)
 * patternAttributeShape = shape(<term>)
 * patternAttributeLocation = location(<int>,<int>)
 * patternAttributeLabel = label(<str>)
 * patternAttributeInfo = info(<str>,<term>)
 * patternAttributeFillColor = fill-color(<term>)
 * patternAttributeDirection = direction(<term>)
 * patternAttributeCurvePoints = curve-points(<term>)
 * patternAttributeColor = color(<term>)
 * patternAttributeBoundingBox = bounding-box(<term>,<term>)
 * patternAttributeListMany = [<term>,<list>]
 * patternAttributeListSingle = [<term>]
 * patternAttributeListEmpty = []
 * patternNodeIdDefault = <term>
 * patternNodeDefault = node(<term>,<term>)
 * patternNodeListMany = [<term>,<list>]
 * patternNodeListSingle = [<term>]
 * patternNodeListEmpty = []
 * patternGraphDefault = graph(<term>,<term>,<term>)
 *
 */

static ATerm _Graph_dict = NULL;

#define _Graph_dict_LEN 845

static char _Graph_dict_baf[_Graph_dict_LEN] = {
0x00,0x8B,0xAF,0x83,0x00,0x30,0x80,0xA7,0x03,0x3C,0x5F,0x3E,0x01,0x00,0x04,0x04,
0x04,0x05,0x06,0x03,0x05,0x5B,0x5F,0x2C,0x5F,0x5D,0x02,0x00,0x63,0x2B,0x01,0x02,
0x00,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x16,
0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,0x20,0x21,0x22,0x23,0x24,0x25,0x26,
0x27,0x28,0x29,0x2A,0x2B,0x2C,0x2D,0x2E,0x2F,0x02,0x01,0x02,0x02,0x5B,0x5D,0x00,
0x00,0x01,0x03,0x69,0x6E,0x74,0x00,0x00,0x01,0x03,0x73,0x74,0x72,0x00,0x00,0x01,
0x04,0x6C,0x69,0x73,0x74,0x00,0x00,0x01,0x04,0x74,0x65,0x72,0x6D,0x00,0x00,0x01,
0x01,0x78,0x00,0x00,0x01,0x05,0x70,0x6F,0x69,0x6E,0x74,0x02,0x00,0x02,0x02,0x00,
0x07,0x02,0x00,0x07,0x06,0x64,0x61,0x73,0x68,0x65,0x64,0x00,0x00,0x01,0x03,0x62,
0x6F,0x78,0x00,0x00,0x01,0x05,0x63,0x6F,0x6C,0x6F,0x72,0x01,0x00,0x02,0x02,0x00,
0x07,0x08,0x6C,0x6F,0x63,0x61,0x74,0x69,0x6F,0x6E,0x02,0x00,0x02,0x02,0x00,0x07,
0x02,0x00,0x07,0x07,0x66,0x6F,0x72,0x77,0x61,0x72,0x64,0x00,0x00,0x01,0x06,0x66,
0x69,0x6C,0x6C,0x65,0x64,0x00,0x00,0x01,0x07,0x65,0x6C,0x6C,0x69,0x70,0x73,0x65,
0x00,0x00,0x01,0x04,0x6E,0x6F,0x6E,0x65,0x00,0x00,0x01,0x0C,0x62,0x6F,0x75,0x6E,
0x64,0x69,0x6E,0x67,0x2D,0x62,0x6F,0x78,0x02,0x00,0x02,0x02,0x00,0x07,0x02,0x00,
0x07,0x05,0x73,0x74,0x79,0x6C,0x65,0x01,0x00,0x02,0x02,0x00,0x07,0x03,0x72,0x67,
0x62,0x03,0x00,0x02,0x02,0x00,0x07,0x02,0x00,0x07,0x02,0x00,0x07,0x03,0x65,0x67,
0x67,0x00,0x00,0x01,0x06,0x64,0x6F,0x74,0x74,0x65,0x64,0x00,0x00,0x01,0x09,0x69,
0x6E,0x76,0x69,0x73,0x69,0x62,0x6C,0x65,0x00,0x00,0x01,0x09,0x70,0x6C,0x61,0x69,
0x6E,0x74,0x65,0x78,0x74,0x00,0x00,0x01,0x05,0x6C,0x61,0x62,0x65,0x6C,0x01,0x00,
0x02,0x02,0x00,0x07,0x05,0x68,0x6F,0x75,0x73,0x65,0x00,0x00,0x01,0x05,0x73,0x6F,
0x6C,0x69,0x64,0x00,0x00,0x01,0x09,0x74,0x72,0x61,0x70,0x65,0x7A,0x69,0x75,0x6D,
0x00,0x00,0x01,0x05,0x67,0x72,0x61,0x70,0x68,0x03,0x00,0x02,0x02,0x00,0x07,0x02,
0x00,0x07,0x02,0x00,0x07,0x04,0x73,0x69,0x7A,0x65,0x02,0x00,0x02,0x02,0x00,0x07,
0x02,0x00,0x07,0x09,0x64,0x69,0x72,0x65,0x63,0x74,0x69,0x6F,0x6E,0x01,0x00,0x02,
0x02,0x00,0x07,0x07,0x68,0x65,0x78,0x61,0x67,0x6F,0x6E,0x00,0x00,0x01,0x08,0x74,
0x72,0x69,0x61,0x6E,0x67,0x6C,0x65,0x00,0x00,0x01,0x04,0x65,0x64,0x67,0x65,0x03,
0x00,0x02,0x02,0x00,0x07,0x02,0x00,0x07,0x02,0x00,0x07,0x04,0x62,0x6F,0x6C,0x64,
0x00,0x00,0x01,0x05,0x73,0x68,0x61,0x70,0x65,0x01,0x00,0x02,0x02,0x00,0x07,0x05,
0x6C,0x65,0x76,0x65,0x6C,0x01,0x00,0x02,0x02,0x00,0x07,0x0C,0x63,0x75,0x72,0x76,
0x65,0x2D,0x70,0x6F,0x69,0x6E,0x74,0x73,0x01,0x00,0x02,0x02,0x00,0x07,0x04,0x66,
0x69,0x6C,0x65,0x01,0x00,0x02,0x02,0x00,0x07,0x06,0x63,0x69,0x72,0x63,0x6C,0x65,
0x00,0x00,0x01,0x0D,0x70,0x61,0x72,0x61,0x6C,0x6C,0x65,0x6C,0x6F,0x67,0x72,0x61,
0x6D,0x00,0x00,0x01,0x04,0x69,0x6E,0x66,0x6F,0x02,0x00,0x02,0x02,0x00,0x07,0x02,
0x00,0x07,0x04,0x62,0x6F,0x74,0x68,0x00,0x00,0x01,0x07,0x64,0x69,0x61,0x6D,0x6F,
0x6E,0x64,0x00,0x00,0x01,0x04,0x62,0x61,0x63,0x6B,0x00,0x00,0x01,0x07,0x6F,0x63,
0x74,0x61,0x67,0x6F,0x6E,0x00,0x00,0x01,0x04,0x6E,0x6F,0x64,0x65,0x02,0x00,0x02,
0x02,0x00,0x07,0x02,0x00,0x07,0x0A,0x66,0x69,0x6C,0x6C,0x2D,0x63,0x6F,0x6C,0x6F,
0x72,0x01,0x00,0x02,0x02,0x00,0x07,0x01,0x03,0x96,0x05,0x0C,0x88,0x29,0x50,0x12,
0x60,0x8C,0x5C,0x14,0x22,0x10,0x85,0x20,0x09,0x43,0xE6,0x83,0xC3,0x0A,0x2E,0x58,
0x41,0xC7,0x0A,0x8D,0x9E,0x0B,0x02,0x26,0x44,0x0C,0x48,0xE9,0x91,0x0D,0x0A,0x2A,
0x54,0x14,0x68,0xC9,0xD1,0x50,0x90,0x62,0x88,0x93,0x10,0x11,0x63,0xC6,0xC3,0x83,
0x8A,0x8B,0x17,0x06,0x1E,0x23,0x47,0xC4,0x28,0x04,0x89,0x10,0x90,0x21,0x13,0x86,
0x23,0x02,0x4A,0x28,0x52,0x10,0x64,0xC1,0xC8,0x80,0x52,0x04,0xA5,0x00,0x15,0x28,
0x86,0x00,0x3C,0x20,0x60,0x1F,0x40,0x94,0x84,0x40,0xA4,0x14,0x87,0xA0,0x2A,0x42,
0x45,0xD8,0x03,0xA7,0x44,0x21,0x0D,0xA0,0x4A,0x16,0x80,0xA8,0x9B,0x00,0x37,0x43,
0xAD,0x23,0x5E,0x4A,0xA2,0x05,0x76,0x32,0xB4,0x25,0x48,0x8B,0x88,0x14,0x53,0xC9,
0x43,0x95,0x8B,0x2A,0x06,0x7C,0x34,0xB2,0x29,0x44,0x93,0x40,0x26,0xA3,0x8C,0x43,
0x19,0x0A,0x21,0x04,0x48,0x30,0xDC,0x21,0x72,0x00,0x00,0x41,0x42,0x00,0x61,0x88,
0x7E,0xFA,0x30,0x1F,0x59,0x10,0xBC,0x34,0x00,0x07,0x9E,0x88,0x6E,0xE2,0x00,0x05,
0xD9,0x46,0x27,0x13,0x18,0x80,0xE5,0x62,0x1D,0xA6,0x88,0x36,0x06,0x21,0x59,0x88,
0x81,0x63,0x22,0x10,0xCC,0x04,0xA1,0x30,0x0A,0x88,0xD0,0x01,0x90,0x87,0xA9,0x62,
0x10,0x74,0x04,0xA2,0xD0,0x0A,0x83,0x50,0x1A,0xBA,0x88,0x42,0x50
};

void init_Graph_dict()
{
  ATermList afuns, terms;

  _Graph_dict = ATreadFromBinaryString(_Graph_dict_baf, _Graph_dict_LEN);

  ATprotect(&_Graph_dict);

  afuns = (ATermList)ATelementAt((ATermList)_Graph_dict, 0);

  afun39 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun17 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun22 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun3 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun9 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun34 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun19 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun26 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun37 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun2 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun12 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun15 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun25 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun18 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun20 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun31 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun8 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun28 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun21 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun32 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun0 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun11 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun5 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun27 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun33 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun38 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun16 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun10 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun13 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun4 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun14 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun23 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun30 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun7 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun36 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun24 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun35 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun29 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun1 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun6 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);

  terms = (ATermList)ATelementAt((ATermList)_Graph_dict, 1);

  patternPointDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternPolygonMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternPolygonSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternPolygonEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternEdgeDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternEdgeListMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternEdgeListSingle = ATgetFirst(terms);
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
  patternShapeTriangle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternShapeTrapezium = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternShapePlaintext = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternShapeParallelogram = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternShapeOctagon = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternShapeHouse = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternShapeHexagon = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternShapeEllipse = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternShapeEgg = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternShapeDiamond = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternShapeCircle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternShapeBox = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternStyleSolid = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternStyleInvisible = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternStyleFilled = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternStyleDotted = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternStyleDashed = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternStyleBold = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternColorRgb = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternFileExternal = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternAttributeFile = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternAttributeLevel = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternAttributeStyle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternAttributeSize = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternAttributeShape = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternAttributeLocation = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternAttributeLabel = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternAttributeInfo = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternAttributeFillColor = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternAttributeDirection = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternAttributeCurvePoints = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternAttributeColor = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternAttributeBoundingBox = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternAttributeListMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternAttributeListSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternAttributeListEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternNodeIdDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternNodeDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternNodeListMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternNodeListSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternNodeListEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  patternGraphDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
}
