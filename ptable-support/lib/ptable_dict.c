/*
 * Generated at Sun Jul  7 20:14:07 2002
 */

#include "ptable_dict.h"

AFun PTA_afun0;
AFun PTA_afun1;
AFun PTA_afun2;
AFun PTA_afun3;
AFun PTA_afun4;
AFun PTA_afun5;
AFun PTA_afun6;
AFun PTA_afun7;
AFun PTA_afun8;
AFun PTA_afun9;
AFun PTA_afun10;
AFun PTA_afun11;
AFun PTA_afun12;
AFun PTA_afun13;
AFun PTA_afun14;
AFun PTA_afun15;
AFun PTA_afun16;

ATerm PTA_patternPriorityGreater = NULL;
ATerm PTA_patternPriorityNonAssoc = NULL;
ATerm PTA_patternPriorityRight = NULL;
ATerm PTA_patternPriorityLeft = NULL;
ATerm PTA_patternPrioritiesList = NULL;
ATerm PTA_patternPrioritiesEmpty = NULL;
ATerm PTA_patternLookAheadsList = NULL;
ATerm PTA_patternLookAheadsEmpty = NULL;
ATerm PTA_patternCharClassDefault = NULL;
ATerm PTA_patternLookAheadDefault = NULL;
ATerm PTA_patternSpecialAttrAvoid = NULL;
ATerm PTA_patternSpecialAttrPrefer = NULL;
ATerm PTA_patternSpecialAttrReject = NULL;
ATerm PTA_patternSpecialAttrNone = NULL;
ATerm PTA_patternChoiceAccept = NULL;
ATerm PTA_patternChoiceShift = NULL;
ATerm PTA_patternChoiceLookaheadReduce = NULL;
ATerm PTA_patternChoiceReduce = NULL;
ATerm PTA_patternChoicesList = NULL;
ATerm PTA_patternChoicesEmpty = NULL;
ATerm PTA_patternActionDefault = NULL;
ATerm PTA_patternActionsList = NULL;
ATerm PTA_patternActionsEmpty = NULL;
ATerm PTA_patternGotoDefault = NULL;
ATerm PTA_patternGotosList = NULL;
ATerm PTA_patternGotosEmpty = NULL;
ATerm PTA_patternStateDefault = NULL;
ATerm PTA_patternStatesList = NULL;
ATerm PTA_patternStatesEmpty = NULL;
ATerm PTA_patternLabelDefault = NULL;
ATerm PTA_patternLabelsList = NULL;
ATerm PTA_patternLabelsEmpty = NULL;
ATerm PTA_patternParseTableParseTable = NULL;
ATerm PTA_patternVersionDefault = NULL;

/*
 * PTA_afun0 = parse-table(x,x,x,x,x)
 * PTA_afun1 = states(x)
 * PTA_afun2 = priorities(x)
 * PTA_afun3 = label(x,x)
 * PTA_afun4 = state-rec(x,x,x)
 * PTA_afun5 = goto(x,x)
 * PTA_afun6 = action(x,x)
 * PTA_afun7 = reduce(x,x,x)
 * PTA_afun8 = reduce(x,x,x,x)
 * PTA_afun9 = shift(x)
 * PTA_afun10 = accept
 * PTA_afun11 = look(x,x)
 * PTA_afun12 = char-class(x)
 * PTA_afun13 = left-prio(x,x)
 * PTA_afun14 = right-prio(x,x)
 * PTA_afun15 = non-assoc(x,x)
 * PTA_afun16 = gtr-prio(x,x)
 *
 * PTA_patternPriorityGreater = gtr-prio(<int>,<int>)
 * PTA_patternPriorityNonAssoc = non-assoc(<int>,<int>)
 * PTA_patternPriorityRight = right-prio(<int>,<int>)
 * PTA_patternPriorityLeft = left-prio(<int>,<int>)
 * PTA_patternPrioritiesList = [<term>,<list>]
 * PTA_patternPrioritiesEmpty = []
 * PTA_patternLookAheadsList = [<term>,<list>]
 * PTA_patternLookAheadsEmpty = []
 * PTA_patternCharClassDefault = char-class(<term>)
 * PTA_patternLookAheadDefault = look(<term>,<term>)
 * PTA_patternSpecialAttrAvoid = 4
 * PTA_patternSpecialAttrPrefer = 2
 * PTA_patternSpecialAttrReject = 1
 * PTA_patternSpecialAttrNone = 0
 * PTA_patternChoiceAccept = accept
 * PTA_patternChoiceShift = shift(<int>)
 * PTA_patternChoiceLookaheadReduce = reduce(<int>,<int>,<term>,<term>)
 * PTA_patternChoiceReduce = reduce(<int>,<int>,<term>)
 * PTA_patternChoicesList = [<term>,<list>]
 * PTA_patternChoicesEmpty = []
 * PTA_patternActionDefault = action(<term>,<term>)
 * PTA_patternActionsList = [<term>,<list>]
 * PTA_patternActionsEmpty = []
 * PTA_patternGotoDefault = goto(<term>,<int>)
 * PTA_patternGotosList = [<term>,<list>]
 * PTA_patternGotosEmpty = []
 * PTA_patternStateDefault = state-rec(<int>,<term>,<term>)
 * PTA_patternStatesList = [<term>,<list>]
 * PTA_patternStatesEmpty = []
 * PTA_patternLabelDefault = label(<term>,<int>)
 * PTA_patternLabelsList = [<term>,<list>]
 * PTA_patternLabelsEmpty = []
 * PTA_patternParseTableParseTable = parse-table(<term>,<int>,<term>,states(<term>),priorities(<term>))
 * PTA_patternVersionDefault = 4
 *
 */

static ATermList _ptable_dict = NULL;

#define _ptable_dict_LEN 539

static char _ptable_dict_baf[_ptable_dict_LEN] = {
0x00,0x8B,0xAF,0x83,0x00,0x19,0x64,0x05,0x3C,0x69,0x6E,0x74,0x3E,0x00,0x00,0x04,
0x03,0x3C,0x5F,0x3E,0x01,0x00,0x03,0x03,0x05,0x06,0x04,0x05,0x5B,0x5F,0x2C,0x5F,
0x5D,0x02,0x00,0x37,0x15,0x02,0x03,0x00,0x01,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,
0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x02,0x02,0x03,0x02,0x5B,0x5D,
0x00,0x00,0x01,0x03,0x69,0x6E,0x74,0x00,0x00,0x01,0x04,0x6C,0x69,0x73,0x74,0x00,
0x00,0x01,0x04,0x74,0x65,0x72,0x6D,0x00,0x00,0x01,0x01,0x78,0x00,0x00,0x01,0x0B,
0x70,0x61,0x72,0x73,0x65,0x2D,0x74,0x61,0x62,0x6C,0x65,0x05,0x00,0x02,0x02,0x01,
0x07,0x02,0x01,0x07,0x02,0x01,0x07,0x02,0x09,0x07,0x02,0x0A,0x07,0x06,0x73,0x74,
0x61,0x74,0x65,0x73,0x01,0x00,0x02,0x02,0x01,0x07,0x0A,0x70,0x72,0x69,0x6F,0x72,
0x69,0x74,0x69,0x65,0x73,0x01,0x00,0x02,0x02,0x01,0x07,0x05,0x6C,0x61,0x62,0x65,
0x6C,0x02,0x00,0x02,0x02,0x01,0x07,0x02,0x01,0x07,0x09,0x73,0x74,0x61,0x74,0x65,
0x2D,0x72,0x65,0x63,0x03,0x00,0x02,0x02,0x01,0x07,0x02,0x01,0x07,0x02,0x01,0x07,
0x04,0x67,0x6F,0x74,0x6F,0x02,0x00,0x02,0x02,0x01,0x07,0x02,0x01,0x07,0x06,0x61,
0x63,0x74,0x69,0x6F,0x6E,0x02,0x00,0x02,0x02,0x01,0x07,0x02,0x01,0x07,0x06,0x72,
0x65,0x64,0x75,0x63,0x65,0x03,0x00,0x02,0x02,0x01,0x07,0x02,0x01,0x07,0x02,0x01,
0x07,0x06,0x72,0x65,0x64,0x75,0x63,0x65,0x04,0x00,0x02,0x02,0x01,0x07,0x02,0x01,
0x07,0x02,0x01,0x07,0x02,0x01,0x07,0x05,0x73,0x68,0x69,0x66,0x74,0x01,0x00,0x02,
0x02,0x01,0x07,0x06,0x61,0x63,0x63,0x65,0x70,0x74,0x00,0x00,0x01,0x04,0x6C,0x6F,
0x6F,0x6B,0x02,0x00,0x02,0x02,0x01,0x07,0x02,0x01,0x07,0x0A,0x63,0x68,0x61,0x72,
0x2D,0x63,0x6C,0x61,0x73,0x73,0x01,0x00,0x02,0x02,0x01,0x07,0x09,0x6C,0x65,0x66,
0x74,0x2D,0x70,0x72,0x69,0x6F,0x02,0x00,0x02,0x02,0x01,0x07,0x02,0x01,0x07,0x0A,
0x72,0x69,0x67,0x68,0x74,0x2D,0x70,0x72,0x69,0x6F,0x02,0x00,0x02,0x02,0x01,0x07,
0x02,0x01,0x07,0x09,0x6E,0x6F,0x6E,0x2D,0x61,0x73,0x73,0x6F,0x63,0x02,0x00,0x02,
0x02,0x01,0x07,0x02,0x01,0x07,0x08,0x67,0x74,0x72,0x2D,0x70,0x72,0x69,0x6F,0x02,
0x00,0x02,0x02,0x01,0x07,0x02,0x01,0x07,0x02,0x00,0x44,0x2A,0xA3,0xCA,0x10,0xE3,
0x08,0xB3,0x85,0x06,0x08,0xA8,0xD2,0x45,0x0A,0x28,0xA2,0x4D,0x15,0x02,0x18,0xAA,
0x38,0xB1,0x0C,0x38,0xA3,0xC5,0x04,0x04,0x8C,0x22,0x50,0x82,0x4A,0x20,0xC9,0x40,
0x05,0x2A,0x2B,0x01,0x65,0x81,0x03,0x3C,0xC0,0x02,0x69,0x80,0x08,0xE3,0x00,0x01,
0x81,0x2C,0x51,0x16,0x12,0x3D,0x80,0xE8,0x12,0x2D,0x80,0x68,0x62,0x35,0xF4,0x44,
0x2A,0x80,0x40,0x00,0x00,0x00,0x4A,0x88,0x80,0x00,0x00,0x00,0x0A,0x85,0x00,0x00,
0x00,0x00,0x72,0x8C,0x00,0x00,0x00,0x00,0x32,0xE2,0x9B,0x40,0x12,0x68,0x00,0x88,
0xC7,0x50,0x01,0x08,0x81,0x22,0x18,0x00,0xAA,0x22,0x3E,0x02,0x43,0xD0,0x2E,0x94,
0x40,0x1C,0x04,0x8D,0xA0,0x2C,0x28,0x08,0x89,0x80,0x90,0x34,0x0E,0xB9,0x10,0x0D,
0x01,0x22,0xA8,0x05,0x12,0x20,0x22,0x22,0x23,0x24,0x0A
};

void init_ptable_dict()
{
  ATermList afuns, terms;

  _ptable_dict = (ATermList)ATreadFromBinaryString(_ptable_dict_baf, _ptable_dict_LEN);

  ATprotect((ATerm *)&_ptable_dict);

  afuns = (ATermList)ATelementAt(_ptable_dict, 0);

  PTA_afun0 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PTA_afun1 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PTA_afun2 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PTA_afun3 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PTA_afun4 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PTA_afun5 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PTA_afun6 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PTA_afun7 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PTA_afun8 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PTA_afun9 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PTA_afun10 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PTA_afun11 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PTA_afun12 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PTA_afun13 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PTA_afun14 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PTA_afun15 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PTA_afun16 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);

  terms = (ATermList)ATelementAt(_ptable_dict, 1);

  PTA_patternPriorityGreater = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTA_patternPriorityNonAssoc = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTA_patternPriorityRight = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTA_patternPriorityLeft = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTA_patternPrioritiesList = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTA_patternPrioritiesEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTA_patternLookAheadsList = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTA_patternLookAheadsEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTA_patternCharClassDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTA_patternLookAheadDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTA_patternSpecialAttrAvoid = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTA_patternSpecialAttrPrefer = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTA_patternSpecialAttrReject = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTA_patternSpecialAttrNone = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTA_patternChoiceAccept = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTA_patternChoiceShift = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTA_patternChoiceLookaheadReduce = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTA_patternChoiceReduce = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTA_patternChoicesList = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTA_patternChoicesEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTA_patternActionDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTA_patternActionsList = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTA_patternActionsEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTA_patternGotoDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTA_patternGotosList = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTA_patternGotosEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTA_patternStateDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTA_patternStatesList = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTA_patternStatesEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTA_patternLabelDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTA_patternLabelsList = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTA_patternLabelsEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTA_patternParseTableParseTable = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTA_patternVersionDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
}
