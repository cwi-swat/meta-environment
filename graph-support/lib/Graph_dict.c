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
ATerm patternAttributeTooltip = NULL;
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
 * afun16 = rgb(x,x,x)
 * afun15 = file(x)
 * afun14 = level(x)
 * afun13 = style(x)
 * afun39 = edge(x,x,x)
 * afun38 = none
 * afun19 = dotted
 * afun37 = both
 * afun18 = dashed
 * afun36 = back
 * afun17 = bold
 * afun35 = forward
 * afun22 = solid
 * afun40 = point(x,x)
 * afun23 = box
 * afun20 = filled
 * afun21 = invisible
 * afun4 = curve-points(x)
 * afun5 = direction(x)
 * afun2 = bounding-box(x,x)
 * afun3 = color(x)
 * afun0 = graph(x,x,x)
 * afun1 = node(x,x)
 * afun29 = house
 * afun28 = hexagon
 * afun8 = label(x)
 * afun25 = diamond
 * afun24 = circle
 * afun9 = tooltip(x)
 * afun6 = fill-color(x)
 * afun27 = ellipse
 * afun7 = info(x,x)
 * afun26 = egg
 * afun31 = parallelogram
 * afun32 = plaintext
 * afun33 = trapezium
 * afun34 = triangle
 * afun10 = location(x,x)
 * afun11 = shape(x)
 * afun12 = size(x,x)
 * afun30 = octagon
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
 * patternAttributeTooltip = tooltip(<str>)
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

#define _Graph_dict_LEN 865

static char _Graph_dict_baf[_Graph_dict_LEN] = {
0x00,0x8B,0xAF,0x83,0x00,0x31,0x80,0xAB,0x03,0x3C,0x5F,0x3E,0x01,0x00,0x04,0x04,
0x04,0x05,0x06,0x03,0x05,0x5B,0x5F,0x2C,0x5F,0x5D,0x02,0x00,0x65,0x2C,0x01,0x02,
0x00,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x16,
0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,0x20,0x21,0x22,0x23,0x24,0x25,0x26,
0x27,0x28,0x29,0x2A,0x2B,0x2C,0x2D,0x2E,0x2F,0x30,0x02,0x01,0x02,0x02,0x5B,0x5D,
0x00,0x00,0x01,0x03,0x69,0x6E,0x74,0x00,0x00,0x01,0x03,0x73,0x74,0x72,0x00,0x00,
0x01,0x04,0x6C,0x69,0x73,0x74,0x00,0x00,0x01,0x04,0x74,0x65,0x72,0x6D,0x00,0x00,
0x01,0x01,0x78,0x00,0x00,0x01,0x03,0x72,0x67,0x62,0x03,0x00,0x02,0x02,0x00,0x07,
0x02,0x00,0x07,0x02,0x00,0x07,0x04,0x66,0x69,0x6C,0x65,0x01,0x00,0x02,0x02,0x00,
0x07,0x05,0x6C,0x65,0x76,0x65,0x6C,0x01,0x00,0x02,0x02,0x00,0x07,0x05,0x73,0x74,
0x79,0x6C,0x65,0x01,0x00,0x02,0x02,0x00,0x07,0x04,0x65,0x64,0x67,0x65,0x03,0x00,
0x02,0x02,0x00,0x07,0x02,0x00,0x07,0x02,0x00,0x07,0x04,0x6E,0x6F,0x6E,0x65,0x00,
0x00,0x01,0x06,0x64,0x6F,0x74,0x74,0x65,0x64,0x00,0x00,0x01,0x04,0x62,0x6F,0x74,
0x68,0x00,0x00,0x01,0x06,0x64,0x61,0x73,0x68,0x65,0x64,0x00,0x00,0x01,0x04,0x62,
0x61,0x63,0x6B,0x00,0x00,0x01,0x04,0x62,0x6F,0x6C,0x64,0x00,0x00,0x01,0x07,0x66,
0x6F,0x72,0x77,0x61,0x72,0x64,0x00,0x00,0x01,0x05,0x73,0x6F,0x6C,0x69,0x64,0x00,
0x00,0x01,0x05,0x70,0x6F,0x69,0x6E,0x74,0x02,0x00,0x02,0x02,0x00,0x07,0x02,0x00,
0x07,0x03,0x62,0x6F,0x78,0x00,0x00,0x01,0x06,0x66,0x69,0x6C,0x6C,0x65,0x64,0x00,
0x00,0x01,0x09,0x69,0x6E,0x76,0x69,0x73,0x69,0x62,0x6C,0x65,0x00,0x00,0x01,0x0C,
0x63,0x75,0x72,0x76,0x65,0x2D,0x70,0x6F,0x69,0x6E,0x74,0x73,0x01,0x00,0x02,0x02,
0x00,0x07,0x09,0x64,0x69,0x72,0x65,0x63,0x74,0x69,0x6F,0x6E,0x01,0x00,0x02,0x02,
0x00,0x07,0x0C,0x62,0x6F,0x75,0x6E,0x64,0x69,0x6E,0x67,0x2D,0x62,0x6F,0x78,0x02,
0x00,0x02,0x02,0x00,0x07,0x02,0x00,0x07,0x05,0x63,0x6F,0x6C,0x6F,0x72,0x01,0x00,
0x02,0x02,0x00,0x07,0x05,0x67,0x72,0x61,0x70,0x68,0x03,0x00,0x02,0x02,0x00,0x07,
0x02,0x00,0x07,0x02,0x00,0x07,0x04,0x6E,0x6F,0x64,0x65,0x02,0x00,0x02,0x02,0x00,
0x07,0x02,0x00,0x07,0x05,0x68,0x6F,0x75,0x73,0x65,0x00,0x00,0x01,0x07,0x68,0x65,
0x78,0x61,0x67,0x6F,0x6E,0x00,0x00,0x01,0x05,0x6C,0x61,0x62,0x65,0x6C,0x01,0x00,
0x02,0x02,0x00,0x07,0x07,0x64,0x69,0x61,0x6D,0x6F,0x6E,0x64,0x00,0x00,0x01,0x06,
0x63,0x69,0x72,0x63,0x6C,0x65,0x00,0x00,0x01,0x07,0x74,0x6F,0x6F,0x6C,0x74,0x69,
0x70,0x01,0x00,0x02,0x02,0x00,0x07,0x0A,0x66,0x69,0x6C,0x6C,0x2D,0x63,0x6F,0x6C,
0x6F,0x72,0x01,0x00,0x02,0x02,0x00,0x07,0x07,0x65,0x6C,0x6C,0x69,0x70,0x73,0x65,
0x00,0x00,0x01,0x04,0x69,0x6E,0x66,0x6F,0x02,0x00,0x02,0x02,0x00,0x07,0x02,0x00,
0x07,0x03,0x65,0x67,0x67,0x00,0x00,0x01,0x0D,0x70,0x61,0x72,0x61,0x6C,0x6C,0x65,
0x6C,0x6F,0x67,0x72,0x61,0x6D,0x00,0x00,0x01,0x09,0x70,0x6C,0x61,0x69,0x6E,0x74,
0x65,0x78,0x74,0x00,0x00,0x01,0x09,0x74,0x72,0x61,0x70,0x65,0x7A,0x69,0x75,0x6D,
0x00,0x00,0x01,0x08,0x74,0x72,0x69,0x61,0x6E,0x67,0x6C,0x65,0x00,0x00,0x01,0x08,
0x6C,0x6F,0x63,0x61,0x74,0x69,0x6F,0x6E,0x02,0x00,0x02,0x02,0x00,0x07,0x02,0x00,
0x07,0x05,0x73,0x68,0x61,0x70,0x65,0x01,0x00,0x02,0x02,0x00,0x07,0x04,0x73,0x69,
0x7A,0x65,0x02,0x00,0x02,0x02,0x00,0x07,0x02,0x00,0x07,0x07,0x6F,0x63,0x74,0x61,
0x67,0x6F,0x6E,0x00,0x00,0x01,0x01,0x00,0x56,0x05,0x47,0x22,0x08,0x65,0x41,0x14,
0x98,0x20,0x97,0x05,0x46,0x21,0x04,0x52,0x10,0x94,0x01,0x68,0x7C,0x30,0x79,0x61,
0x71,0xC0,0xE7,0x86,0xC0,0x8A,0x16,0x44,0x4C,0x48,0x19,0x91,0xD0,0xA2,0x1A,0x54,
0x45,0x46,0x8A,0x0A,0x74,0x46,0x41,0x8A,0x84,0x93,0x14,0x44,0x58,0x09,0xB1,0xE0,
0xE2,0x1C,0x5C,0x58,0x78,0x31,0xF1,0x1A,0x01,0x21,0x44,0x24,0x84,0x4A,0x04,0x62,
0x70,0x24,0x61,0x49,0x41,0x90,0x87,0x26,0x01,0x4A,0x10,0x4A,0x44,0x05,0x4A,0x00,
0x6B,0x18,0xC0,0x46,0x14,0x0C,0x02,0x18,0x0A,0x90,0x88,0x94,0x82,0x90,0x0C,0x0D,
0x48,0x48,0xFB,0x00,0xF7,0x88,0x84,0x21,0x74,0x05,0x41,0xD0,0x35,0x1B,0x60,0x16,
0x88,0x4D,0x50,0x1A,0x61,0xD5,0xC1,0xAF,0x25,0x56,0x42,0xB4,0x99,0x49,0x12,0xEA,
0x45,0x58,0x0B,0xB1,0xE6,0x11,0xCE,0x25,0x9B,0x83,0x2F,0x1A,0x62,0x14,0xF8,0x49,
0xC8,0x12,0x91,0xC6,0x41,0x8E,0x85,0x1B,0x02,0x38,0x40,0x00,0x0C,0x28,0x41,0x09,
0x11,0x08,0x34,0x46,0x00,0x16,0x22,0x1F,0x95,0x80,0x01,0xF4,0xB1,0x0B,0xC2,0xC0,
0x00,0x7B,0xE8,0xC6,0xE3,0xA3,0x0B,0x91,0x8C,0x42,0x70,0x31,0x01,0xD5,0x44,0x3B,
0x15,0x10,0x6D,0xD4,0x42,0xB3,0x51,0x08,0x16,0x01,0x51,0x98,0x0D,0x42,0x68,0x08,
0xC8,0x40,0x34,0xD1,0x08,0x7A,0x01,0x50,0xE8,0x0D,0x45,0xA8,0x03,0x43,0x44,0x21,
0x28
};

void init_Graph_dict()
{
  ATermList afuns, terms;

  _Graph_dict = ATreadFromBinaryString(_Graph_dict_baf, _Graph_dict_LEN);

  ATprotect(&_Graph_dict);

  afuns = (ATermList)ATelementAt((ATermList)_Graph_dict, 0);

  afun16 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun15 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun14 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun13 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun39 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun38 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun19 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun37 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun18 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun36 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun17 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun35 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun22 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun40 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun23 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun20 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun21 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun4 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun5 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun2 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun3 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun0 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun1 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun29 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun28 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun8 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun25 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun24 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun9 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun6 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun27 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun7 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun26 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun31 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun32 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun33 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun34 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun10 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun11 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun12 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  afun30 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
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
  patternAttributeTooltip = ATgetFirst(terms);
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
