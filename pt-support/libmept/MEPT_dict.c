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

ATerm PT_patternCharRangesMany = NULL;
ATerm PT_patternCharRangesSingle = NULL;
ATerm PT_patternCharRangesEmpty = NULL;
ATerm PT_patternCharRangeRange = NULL;
ATerm PT_patternCharRangeCharacter = NULL;
ATerm PT_patternSymbolsMany = NULL;
ATerm PT_patternSymbolsSingle = NULL;
ATerm PT_patternSymbolsEmpty = NULL;
ATerm PT_patternSymbolCharClass = NULL;
ATerm PT_patternSymbolLayout = NULL;
ATerm PT_patternSymbolVarSym = NULL;
ATerm PT_patternSymbolStrategy = NULL;
ATerm PT_patternSymbolParameterizedSort = NULL;
ATerm PT_patternSymbolFunc = NULL;
ATerm PT_patternSymbolIterSepN = NULL;
ATerm PT_patternSymbolIterN = NULL;
ATerm PT_patternSymbolIterStarSep = NULL;
ATerm PT_patternSymbolIterPlusSep = NULL;
ATerm PT_patternSymbolIterStar = NULL;
ATerm PT_patternSymbolIterPlus = NULL;
ATerm PT_patternSymbolSort = NULL;
ATerm PT_patternSymbolTuple = NULL;
ATerm PT_patternSymbolAlt = NULL;
ATerm PT_patternSymbolOpt = NULL;
ATerm PT_patternSymbolSeq = NULL;
ATerm PT_patternSymbolEmpty = NULL;
ATerm PT_patternSymbolLex = NULL;
ATerm PT_patternSymbolCf = NULL;
ATerm PT_patternSymbolLit = NULL;
ATerm PT_patternAssociativityNonAssoc = NULL;
ATerm PT_patternAssociativityAssoc = NULL;
ATerm PT_patternAssociativityRight = NULL;
ATerm PT_patternAssociativityLeft = NULL;
ATerm PT_patternAttrAvoid = NULL;
ATerm PT_patternAttrPrefer = NULL;
ATerm PT_patternAttrReject = NULL;
ATerm PT_patternAttrBracket = NULL;
ATerm PT_patternAttrId = NULL;
ATerm PT_patternAttrTerm = NULL;
ATerm PT_patternAttrAssoc = NULL;
ATerm PT_patternAttrsMany = NULL;
ATerm PT_patternAttrsSingle = NULL;
ATerm PT_patternAttrsEmpty = NULL;
ATerm PT_patternAttributesAttrs = NULL;
ATerm PT_patternAttributesNoAttrs = NULL;
ATerm PT_patternProductionList = NULL;
ATerm PT_patternProductionDefault = NULL;
ATerm PT_patternArgsMany = NULL;
ATerm PT_patternArgsSingle = NULL;
ATerm PT_patternArgsEmpty = NULL;
ATerm PT_patternTreeChar = NULL;
ATerm PT_patternTreeAmb = NULL;
ATerm PT_patternTreeCycle = NULL;
ATerm PT_patternTreeAppl = NULL;
ATerm PT_patternParseTreeTop = NULL;

/*
 * PT_afun39 = char-class(x)
 * PT_afun17 = assoc
 * PT_afun22 = empty
 * PT_afun3 = amb(x)
 * PT_afun9 = term(x)
 * PT_afun34 = func(x,x)
 * PT_afun19 = lit(x)
 * PT_afun26 = tuple(x,x)
 * PT_afun37 = varsym(x)
 * PT_afun2 = cycle(x,x)
 * PT_afun12 = reject
 * PT_afun15 = left
 * PT_afun25 = alt(x,x)
 * PT_afun18 = non-assoc
 * PT_afun20 = cf(x)
 * PT_afun31 = iter-star-sep(x,x)
 * PT_afun8 = assoc(x)
 * PT_afun28 = iter(x)
 * PT_afun21 = lex(x)
 * PT_afun32 = iter-n(x,x)
 * PT_afun0 = parsetree(x,x)
 * PT_afun11 = bracket
 * PT_afun5 = list(x)
 * PT_afun27 = sort(x)
 * PT_afun33 = iter-sep-n(x,x,x)
 * PT_afun38 = layout
 * PT_afun16 = right
 * PT_afun10 = id(x)
 * PT_afun13 = prefer
 * PT_afun4 = prod(x,x,x)
 * PT_afun14 = avoid
 * PT_afun40 = range(x,x)
 * PT_afun23 = seq(x)
 * PT_afun30 = iter-sep(x,x)
 * PT_afun7 = attrs(x)
 * PT_afun36 = strategy(x,x)
 * PT_afun24 = opt(x)
 * PT_afun35 = parameterized-sort(x,x)
 * PT_afun29 = iter-star(x)
 * PT_afun1 = appl(x,x)
 * PT_afun6 = no-attrs
 *
 * PT_patternCharRangesMany = [<term>,<list>]
 * PT_patternCharRangesSingle = [<term>]
 * PT_patternCharRangesEmpty = []
 * PT_patternCharRangeRange = range(<int>,<int>)
 * PT_patternCharRangeCharacter = <int>
 * PT_patternSymbolsMany = [<term>,<list>]
 * PT_patternSymbolsSingle = [<term>]
 * PT_patternSymbolsEmpty = []
 * PT_patternSymbolCharClass = char-class(<term>)
 * PT_patternSymbolLayout = layout
 * PT_patternSymbolVarSym = varsym(<term>)
 * PT_patternSymbolStrategy = strategy(<term>,<term>)
 * PT_patternSymbolParameterizedSort = parameterized-sort(<str>,<term>)
 * PT_patternSymbolFunc = func(<term>,<term>)
 * PT_patternSymbolIterSepN = iter-sep-n(<term>,<term>,<int>)
 * PT_patternSymbolIterN = iter-n(<term>,<int>)
 * PT_patternSymbolIterStarSep = iter-star-sep(<term>,<term>)
 * PT_patternSymbolIterPlusSep = iter-sep(<term>,<term>)
 * PT_patternSymbolIterStar = iter-star(<term>)
 * PT_patternSymbolIterPlus = iter(<term>)
 * PT_patternSymbolSort = sort(<str>)
 * PT_patternSymbolTuple = tuple(<term>,<term>)
 * PT_patternSymbolAlt = alt(<term>,<term>)
 * PT_patternSymbolOpt = opt(<term>)
 * PT_patternSymbolSeq = seq(<term>)
 * PT_patternSymbolEmpty = empty
 * PT_patternSymbolLex = lex(<term>)
 * PT_patternSymbolCf = cf(<term>)
 * PT_patternSymbolLit = lit(<str>)
 * PT_patternAssociativityNonAssoc = non-assoc
 * PT_patternAssociativityAssoc = assoc
 * PT_patternAssociativityRight = right
 * PT_patternAssociativityLeft = left
 * PT_patternAttrAvoid = avoid
 * PT_patternAttrPrefer = prefer
 * PT_patternAttrReject = reject
 * PT_patternAttrBracket = bracket
 * PT_patternAttrId = id(<str>)
 * PT_patternAttrTerm = term(<term>)
 * PT_patternAttrAssoc = assoc(<term>)
 * PT_patternAttrsMany = [<term>,<list>]
 * PT_patternAttrsSingle = [<term>]
 * PT_patternAttrsEmpty = []
 * PT_patternAttributesAttrs = attrs(<term>)
 * PT_patternAttributesNoAttrs = no-attrs
 * PT_patternProductionList = list(<term>)
 * PT_patternProductionDefault = prod(<term>,<term>,<term>)
 * PT_patternArgsMany = [<term>,<list>]
 * PT_patternArgsSingle = [<term>]
 * PT_patternArgsEmpty = []
 * PT_patternTreeChar = <int>
 * PT_patternTreeAmb = amb(<term>)
 * PT_patternTreeCycle = cycle(<term>,<int>)
 * PT_patternTreeAppl = appl(<term>,<term>)
 * PT_patternParseTreeTop = parsetree(<term>,<int>)
 *
 */

static ATerm _MEPT_dict = NULL;

#define _MEPT_dict_LEN 912

static char _MEPT_dict_baf[_MEPT_dict_LEN] = {
0x00,0x8B,0xAF,0x83,0x00,0x31,0x80,0xB6,0x03,0x3C,0x5F,0x3E,0x01,0x00,0x04,0x04,
0x04,0x03,0x05,0x06,0x05,0x5B,0x5F,0x2C,0x5F,0x5D,0x02,0x00,0x65,0x2C,0x01,0x02,
0x00,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x16,
0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,0x20,0x21,0x22,0x23,0x24,0x25,0x26,
0x27,0x28,0x29,0x2A,0x2B,0x2C,0x2D,0x2E,0x2F,0x30,0x02,0x01,0x02,0x02,0x5B,0x5D,
0x00,0x00,0x01,0x03,0x69,0x6E,0x74,0x00,0x00,0x01,0x03,0x73,0x74,0x72,0x00,0x00,
0x01,0x04,0x6C,0x69,0x73,0x74,0x00,0x00,0x01,0x04,0x74,0x65,0x72,0x6D,0x00,0x00,
0x01,0x01,0x78,0x00,0x00,0x01,0x0A,0x63,0x68,0x61,0x72,0x2D,0x63,0x6C,0x61,0x73,
0x73,0x01,0x00,0x02,0x02,0x00,0x07,0x05,0x61,0x73,0x73,0x6F,0x63,0x00,0x00,0x01,
0x05,0x65,0x6D,0x70,0x74,0x79,0x00,0x00,0x01,0x03,0x61,0x6D,0x62,0x01,0x00,0x02,
0x02,0x00,0x07,0x04,0x74,0x65,0x72,0x6D,0x01,0x00,0x02,0x02,0x00,0x07,0x04,0x66,
0x75,0x6E,0x63,0x02,0x00,0x02,0x02,0x00,0x07,0x02,0x00,0x07,0x03,0x6C,0x69,0x74,
0x01,0x00,0x02,0x02,0x00,0x07,0x05,0x74,0x75,0x70,0x6C,0x65,0x02,0x00,0x02,0x02,
0x00,0x07,0x02,0x00,0x07,0x06,0x76,0x61,0x72,0x73,0x79,0x6D,0x01,0x00,0x02,0x02,
0x00,0x07,0x05,0x63,0x79,0x63,0x6C,0x65,0x02,0x00,0x02,0x02,0x00,0x07,0x02,0x00,
0x07,0x06,0x72,0x65,0x6A,0x65,0x63,0x74,0x00,0x00,0x01,0x04,0x6C,0x65,0x66,0x74,
0x00,0x00,0x01,0x03,0x61,0x6C,0x74,0x02,0x00,0x02,0x02,0x00,0x07,0x02,0x00,0x07,
0x09,0x6E,0x6F,0x6E,0x2D,0x61,0x73,0x73,0x6F,0x63,0x00,0x00,0x01,0x02,0x63,0x66,
0x01,0x00,0x02,0x02,0x00,0x07,0x0D,0x69,0x74,0x65,0x72,0x2D,0x73,0x74,0x61,0x72,
0x2D,0x73,0x65,0x70,0x02,0x00,0x02,0x02,0x00,0x07,0x02,0x00,0x07,0x05,0x61,0x73,
0x73,0x6F,0x63,0x01,0x00,0x02,0x02,0x00,0x07,0x04,0x69,0x74,0x65,0x72,0x01,0x00,
0x02,0x02,0x00,0x07,0x03,0x6C,0x65,0x78,0x01,0x00,0x02,0x02,0x00,0x07,0x06,0x69,
0x74,0x65,0x72,0x2D,0x6E,0x02,0x00,0x02,0x02,0x00,0x07,0x02,0x00,0x07,0x09,0x70,
0x61,0x72,0x73,0x65,0x74,0x72,0x65,0x65,0x02,0x00,0x02,0x02,0x00,0x07,0x02,0x00,
0x07,0x07,0x62,0x72,0x61,0x63,0x6B,0x65,0x74,0x00,0x00,0x01,0x04,0x6C,0x69,0x73,
0x74,0x01,0x00,0x02,0x02,0x00,0x07,0x04,0x73,0x6F,0x72,0x74,0x01,0x00,0x02,0x02,
0x00,0x07,0x0A,0x69,0x74,0x65,0x72,0x2D,0x73,0x65,0x70,0x2D,0x6E,0x03,0x00,0x02,
0x02,0x00,0x07,0x02,0x00,0x07,0x02,0x00,0x07,0x06,0x6C,0x61,0x79,0x6F,0x75,0x74,
0x00,0x00,0x01,0x05,0x72,0x69,0x67,0x68,0x74,0x00,0x00,0x01,0x02,0x69,0x64,0x01,
0x00,0x02,0x02,0x00,0x07,0x06,0x70,0x72,0x65,0x66,0x65,0x72,0x00,0x00,0x01,0x04,
0x70,0x72,0x6F,0x64,0x03,0x00,0x02,0x02,0x00,0x07,0x02,0x00,0x07,0x02,0x00,0x07,
0x05,0x61,0x76,0x6F,0x69,0x64,0x00,0x00,0x01,0x05,0x72,0x61,0x6E,0x67,0x65,0x02,
0x00,0x02,0x02,0x00,0x07,0x02,0x00,0x07,0x03,0x73,0x65,0x71,0x01,0x00,0x02,0x02,
0x00,0x07,0x08,0x69,0x74,0x65,0x72,0x2D,0x73,0x65,0x70,0x02,0x00,0x02,0x02,0x00,
0x07,0x02,0x00,0x07,0x05,0x61,0x74,0x74,0x72,0x73,0x01,0x00,0x02,0x02,0x00,0x07,
0x08,0x73,0x74,0x72,0x61,0x74,0x65,0x67,0x79,0x02,0x00,0x02,0x02,0x00,0x07,0x02,
0x00,0x07,0x03,0x6F,0x70,0x74,0x01,0x00,0x02,0x02,0x00,0x07,0x12,0x70,0x61,0x72,
0x61,0x6D,0x65,0x74,0x65,0x72,0x69,0x7A,0x65,0x64,0x2D,0x73,0x6F,0x72,0x74,0x02,
0x00,0x02,0x02,0x00,0x07,0x02,0x00,0x07,0x09,0x69,0x74,0x65,0x72,0x2D,0x73,0x74,
0x61,0x72,0x01,0x00,0x02,0x02,0x00,0x07,0x04,0x61,0x70,0x70,0x6C,0x02,0x00,0x02,
0x02,0x00,0x07,0x02,0x00,0x07,0x08,0x6E,0x6F,0x2D,0x61,0x74,0x74,0x72,0x73,0x00,
0x00,0x01,0x01,0x00,0x56,0x04,0x72,0x20,0x65,0x41,0x49,0x82,0x09,0x70,0x46,0x21,
0x0A,0x11,0x48,0x44,0x25,0x0A,0x01,0x68,0x47,0xC3,0x0A,0x1E,0x58,0x5C,0x70,0x39,
0xE1,0x46,0xC0,0x85,0x91,0x11,0x31,0x22,0x81,0x99,0x11,0xD0,0xA2,0x1A,0x54,0x45,
0x46,0x8A,0x0A,0x74,0x51,0x90,0x61,0x24,0xC4,0x44,0x58,0x80,0x9B,0x15,0x1E,0x0E,
0x1C,0x5C,0x58,0x78,0x83,0x1F,0x1A,0x01,0x2A,0x14,0x42,0x48,0x44,0xA0,0x46,0x24,
0x70,0x24,0xA1,0x85,0x24,0x50,0x64,0xA0,0x87,0x24,0x60,0x14,0xA1,0x04,0xA4,0x40,
0x54,0xA0,0x06,0xB1,0x8C,0x04,0x60,0x2A,0x40,0x62,0x52,0x11,0x44,0x30,0x35,0x20,
0x20,0x1C,0x07,0xD4,0x61,0x41,0x0F,0x50,0x45,0xD0,0x15,0x07,0x40,0xD4,0x6D,0x80,
0x5B,0x84,0x02,0x69,0xC0,0xDD,0x20,0x1D,0x59,0x80,0x01,0xA8,0xB1,0x80,0x0A,0xA2,
0x40,0x00,0x57,0x68,0x00,0x11,0x95,0xA8,0x02,0x12,0xA5,0x00,0x04,0x52,0x60,0x00,
0x0B,0x2C,0x03,0xC9,0x50,0x07,0x2B,0x46,0x2C,0xA9,0x00,0x01,0x9F,0x20,0x00,0xD3,
0xCC,0x01,0x4E,0x30,0x09,0x34,0x02,0x6A,0x80,0x71,0x8A,0x00,0xC6,0x48,0xC5,0x10,
0x82,0x24,0x18,0x6E,0x10,0xB8,0x41,0x84,0x03,0xF1,0xFA,0xC1,0xF0,0xC5,0xE7,0xA3,
0x07,0xB8,0x80,0x6E,0xCA,0x00,0xB8,0x05,0x44,0xE0,0x35,0x03,0xA0,0x3B,0x53,0x00,
0x6D,0xA9,0x5A,0x68,0x01,0x60,0x60,0x00,0x06,0x60,0x15,0x09,0x80,0xD4,0x46,0x80,
0x0C,0x82,0x3D,0x31,0x00,0x74,0x64,0x01,0x16,0x95,0x80,0x00,0xD7,0x50,0x05,0x40
};

void init_MEPT_dict()
{
  ATermList afuns, terms;

  _MEPT_dict = ATreadFromBinaryString(_MEPT_dict_baf, _MEPT_dict_LEN);

  ATprotect(&_MEPT_dict);

  afuns = (ATermList)ATelementAt((ATermList)_MEPT_dict, 0);

  PT_afun39 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PT_afun17 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PT_afun22 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PT_afun3 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PT_afun9 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PT_afun34 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PT_afun19 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PT_afun26 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PT_afun37 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PT_afun2 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PT_afun12 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PT_afun15 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PT_afun25 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PT_afun18 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PT_afun20 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PT_afun31 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PT_afun8 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PT_afun28 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PT_afun21 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PT_afun32 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PT_afun0 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PT_afun11 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PT_afun5 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PT_afun27 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PT_afun33 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PT_afun38 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PT_afun16 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PT_afun10 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PT_afun13 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PT_afun4 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PT_afun14 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PT_afun40 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PT_afun23 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PT_afun30 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PT_afun7 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PT_afun36 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PT_afun24 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PT_afun35 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PT_afun29 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PT_afun1 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PT_afun6 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);

  terms = (ATermList)ATelementAt((ATermList)_MEPT_dict, 1);

  PT_patternCharRangesMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternCharRangesSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternCharRangesEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternCharRangeRange = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternCharRangeCharacter = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternSymbolsMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternSymbolsSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternSymbolsEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternSymbolCharClass = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternSymbolLayout = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternSymbolVarSym = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternSymbolStrategy = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternSymbolParameterizedSort = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternSymbolFunc = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternSymbolIterSepN = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternSymbolIterN = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternSymbolIterStarSep = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternSymbolIterPlusSep = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternSymbolIterStar = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternSymbolIterPlus = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternSymbolSort = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternSymbolTuple = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternSymbolAlt = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternSymbolOpt = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternSymbolSeq = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternSymbolEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternSymbolLex = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternSymbolCf = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternSymbolLit = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternAssociativityNonAssoc = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternAssociativityAssoc = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternAssociativityRight = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternAssociativityLeft = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternAttrAvoid = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternAttrPrefer = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternAttrReject = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternAttrBracket = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternAttrId = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternAttrTerm = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternAttrAssoc = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternAttrsMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternAttrsSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternAttrsEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternAttributesAttrs = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternAttributesNoAttrs = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternProductionList = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternProductionDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternArgsMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternArgsSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternArgsEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternTreeChar = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternTreeAmb = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternTreeCycle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternTreeAppl = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PT_patternParseTreeTop = ATgetFirst(terms);
  terms = ATgetNext(terms);
}
