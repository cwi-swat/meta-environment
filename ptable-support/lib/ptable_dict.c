#include "ptable_dict.h"

AFun PTBL_afun8;
AFun PTBL_afun0;
AFun PTBL_afun11;
AFun PTBL_afun5;
AFun PTBL_afun3;
AFun PTBL_afun9;
AFun PTBL_afun10;
AFun PTBL_afun4;
AFun PTBL_afun13;
AFun PTBL_afun2;
AFun PTBL_afun7;
AFun PTBL_afun12;
AFun PTBL_afun6;
AFun PTBL_afun1;

ATerm PTBL_patternPriorityArgGreater = NULL;
ATerm PTBL_patternPriorityGreater = NULL;
ATerm PTBL_patternPrioritiesMany = NULL;
ATerm PTBL_patternPrioritiesSingle = NULL;
ATerm PTBL_patternPrioritiesEmpty = NULL;
ATerm PTBL_patternCharClassesMany = NULL;
ATerm PTBL_patternCharClassesSingle = NULL;
ATerm PTBL_patternCharClassesEmpty = NULL;
ATerm PTBL_patternRestrictionFollow = NULL;
ATerm PTBL_patternRestrictionsMany = NULL;
ATerm PTBL_patternRestrictionsSingle = NULL;
ATerm PTBL_patternRestrictionsEmpty = NULL;
ATerm PTBL_patternSpecialAttrAvoid = NULL;
ATerm PTBL_patternSpecialAttrPrefer = NULL;
ATerm PTBL_patternSpecialAttrReject = NULL;
ATerm PTBL_patternSpecialAttrNone = NULL;
ATerm PTBL_patternActionAccept = NULL;
ATerm PTBL_patternActionShift = NULL;
ATerm PTBL_patternActionLookaheadReduce = NULL;
ATerm PTBL_patternActionReduce = NULL;
ATerm PTBL_patternActionsMany = NULL;
ATerm PTBL_patternActionsSingle = NULL;
ATerm PTBL_patternActionsEmpty = NULL;
ATerm PTBL_patternChoiceDefault = NULL;
ATerm PTBL_patternChoicesMany = NULL;
ATerm PTBL_patternChoicesSingle = NULL;
ATerm PTBL_patternChoicesEmpty = NULL;
ATerm PTBL_patternGotoDefault = NULL;
ATerm PTBL_patternGotosMany = NULL;
ATerm PTBL_patternGotosSingle = NULL;
ATerm PTBL_patternGotosEmpty = NULL;
ATerm PTBL_patternStateDefault = NULL;
ATerm PTBL_patternStatesMany = NULL;
ATerm PTBL_patternStatesSingle = NULL;
ATerm PTBL_patternStatesEmpty = NULL;
ATerm PTBL_patternLabelDefault = NULL;
ATerm PTBL_patternLabelsMany = NULL;
ATerm PTBL_patternLabelsSingle = NULL;
ATerm PTBL_patternLabelsEmpty = NULL;
ATerm PTBL_patternParseTableParseTable = NULL;
ATerm PTBL_patternVersionDefault = NULL;
ATerm PTBL_patternCharRangesExternal = NULL;
ATerm PTBL_patternCharClassExternal = NULL;
ATerm PTBL_patternProductionExternal = NULL;

/*
 * PTBL_afun8 = reduce(x,x,x,x)
 * PTBL_afun0 = parse-table(x,x,x,x,x)
 * PTBL_afun11 = follow-restriction(x)
 * PTBL_afun5 = goto(x,x)
 * PTBL_afun3 = label(x,x)
 * PTBL_afun9 = shift(x)
 * PTBL_afun10 = accept
 * PTBL_afun4 = state-rec(x,x,x)
 * PTBL_afun13 = arg-gtr-prio(x,x,x)
 * PTBL_afun2 = priorities(x)
 * PTBL_afun7 = reduce(x,x,x)
 * PTBL_afun12 = gtr-prio(x,x)
 * PTBL_afun6 = action(x,x)
 * PTBL_afun1 = states(x)
 *
 * PTBL_patternPriorityArgGreater = arg-gtr-prio(<int>,<int>,<int>)
 * PTBL_patternPriorityGreater = gtr-prio(<int>,<int>)
 * PTBL_patternPrioritiesMany = [<term>,<list>]
 * PTBL_patternPrioritiesSingle = [<term>]
 * PTBL_patternPrioritiesEmpty = []
 * PTBL_patternCharClassesMany = [<term>,<list>]
 * PTBL_patternCharClassesSingle = [<term>]
 * PTBL_patternCharClassesEmpty = []
 * PTBL_patternRestrictionFollow = follow-restriction(<term>)
 * PTBL_patternRestrictionsMany = [<term>,<list>]
 * PTBL_patternRestrictionsSingle = [<term>]
 * PTBL_patternRestrictionsEmpty = []
 * PTBL_patternSpecialAttrAvoid = 4
 * PTBL_patternSpecialAttrPrefer = 2
 * PTBL_patternSpecialAttrReject = 1
 * PTBL_patternSpecialAttrNone = 0
 * PTBL_patternActionAccept = accept
 * PTBL_patternActionShift = shift(<int>)
 * PTBL_patternActionLookaheadReduce = reduce(<int>,<int>,<term>,<term>)
 * PTBL_patternActionReduce = reduce(<int>,<int>,<term>)
 * PTBL_patternActionsMany = [<term>,<list>]
 * PTBL_patternActionsSingle = [<term>]
 * PTBL_patternActionsEmpty = []
 * PTBL_patternChoiceDefault = action(<term>,<term>)
 * PTBL_patternChoicesMany = [<term>,<list>]
 * PTBL_patternChoicesSingle = [<term>]
 * PTBL_patternChoicesEmpty = []
 * PTBL_patternGotoDefault = goto(<term>,<int>)
 * PTBL_patternGotosMany = [<term>,<list>]
 * PTBL_patternGotosSingle = [<term>]
 * PTBL_patternGotosEmpty = []
 * PTBL_patternStateDefault = state-rec(<int>,<term>,<term>)
 * PTBL_patternStatesMany = [<term>,<list>]
 * PTBL_patternStatesSingle = [<term>]
 * PTBL_patternStatesEmpty = []
 * PTBL_patternLabelDefault = label(<term>,<int>)
 * PTBL_patternLabelsMany = [<term>,<list>]
 * PTBL_patternLabelsSingle = [<term>]
 * PTBL_patternLabelsEmpty = []
 * PTBL_patternParseTableParseTable = parse-table(<term>,<int>,<term>,states(<term>),priorities(<term>))
 * PTBL_patternVersionDefault = 6
 * PTBL_patternCharRangesExternal = <term>
 * PTBL_patternCharClassExternal = <term>
 * PTBL_patternProductionExternal = <term>
 *
 */

static ATerm _ptable_dict = NULL;

#define _ptable_dict_LEN 515

static char _ptable_dict_baf[_ptable_dict_LEN] = {
0x00,0x8B,0xAF,0x83,0x00,0x16,0x66,0x05,0x3C,0x69,0x6E,0x74,0x3E,0x00,0x00,0x05,
0x03,0x3C,0x5F,0x3E,0x01,0x00,0x03,0x03,0x05,0x06,0x04,0x05,0x5B,0x5F,0x2C,0x5F,
0x5D,0x02,0x00,0x3E,0x12,0x02,0x03,0x00,0x01,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,
0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x02,0x02,0x03,0x02,0x5B,0x5D,0x00,0x00,0x01,
0x03,0x69,0x6E,0x74,0x00,0x00,0x01,0x04,0x6C,0x69,0x73,0x74,0x00,0x00,0x01,0x04,
0x74,0x65,0x72,0x6D,0x00,0x00,0x01,0x01,0x78,0x00,0x00,0x01,0x06,0x72,0x65,0x64,
0x75,0x63,0x65,0x04,0x00,0x02,0x02,0x01,0x07,0x02,0x01,0x07,0x02,0x01,0x07,0x02,
0x01,0x07,0x0B,0x70,0x61,0x72,0x73,0x65,0x2D,0x74,0x61,0x62,0x6C,0x65,0x05,0x00,
0x02,0x02,0x01,0x07,0x02,0x01,0x07,0x02,0x01,0x07,0x02,0x15,0x07,0x02,0x11,0x07,
0x12,0x66,0x6F,0x6C,0x6C,0x6F,0x77,0x2D,0x72,0x65,0x73,0x74,0x72,0x69,0x63,0x74,
0x69,0x6F,0x6E,0x01,0x00,0x02,0x02,0x01,0x07,0x04,0x67,0x6F,0x74,0x6F,0x02,0x00,
0x02,0x02,0x01,0x07,0x02,0x01,0x07,0x05,0x6C,0x61,0x62,0x65,0x6C,0x02,0x00,0x02,
0x02,0x01,0x07,0x02,0x01,0x07,0x05,0x73,0x68,0x69,0x66,0x74,0x01,0x00,0x02,0x02,
0x01,0x07,0x06,0x61,0x63,0x63,0x65,0x70,0x74,0x00,0x00,0x01,0x09,0x73,0x74,0x61,
0x74,0x65,0x2D,0x72,0x65,0x63,0x03,0x00,0x02,0x02,0x01,0x07,0x02,0x01,0x07,0x02,
0x01,0x07,0x0C,0x61,0x72,0x67,0x2D,0x67,0x74,0x72,0x2D,0x70,0x72,0x69,0x6F,0x03,
0x00,0x02,0x02,0x01,0x07,0x02,0x01,0x07,0x02,0x01,0x07,0x0A,0x70,0x72,0x69,0x6F,
0x72,0x69,0x74,0x69,0x65,0x73,0x01,0x00,0x02,0x02,0x01,0x07,0x06,0x72,0x65,0x64,
0x75,0x63,0x65,0x03,0x00,0x02,0x02,0x01,0x07,0x02,0x01,0x07,0x02,0x01,0x07,0x08,
0x67,0x74,0x72,0x2D,0x70,0x72,0x69,0x6F,0x02,0x00,0x02,0x02,0x01,0x07,0x02,0x01,
0x07,0x06,0x61,0x63,0x74,0x69,0x6F,0x6E,0x02,0x00,0x02,0x02,0x01,0x07,0x02,0x01,
0x07,0x06,0x73,0x74,0x61,0x74,0x65,0x73,0x01,0x00,0x02,0x02,0x01,0x07,0x02,0x05,
0x84,0x2A,0x83,0x28,0x55,0x46,0x8C,0x21,0x4E,0x14,0x48,0x22,0x81,0x24,0x47,0x0A,
0x18,0xD1,0x51,0x41,0x8A,0x82,0x2C,0x46,0x0E,0x2A,0x10,0xF1,0x44,0x01,0x28,0x02,
0x25,0x07,0x83,0x73,0x40,0x80,0x0B,0xFA,0x00,0x27,0x07,0x98,0xA1,0xCC,0x24,0x0E,
0x00,0xB1,0x47,0x70,0x1B,0x07,0x85,0x60,0x08,0x2E,0x06,0x6C,0x88,0x4C,0x1E,0x11,
0x80,0x20,0x38,0x1E,0xA0,0x10,0x00,0x00,0x00,0x0E,0xA2,0x20,0x00,0x00,0x00,0x16,
0xA1,0x40,0x00,0x00,0x00,0x06,0xA3,0x00,0x00,0x00,0x00,0x1A,0xA8,0x56,0x50,0x12,
0x92,0x00,0x22,0x05,0x74,0x00,0x47,0x20,0xF0,0x64,0x01,0x14,0xC0,0x24,0x31,0x11,
0x88,0x3C,0x11,0x00,0x44,0x30,0x01,0xE4,0x40,0x7C,0x0F,0x07,0x80,0x11,0x74,0x03,
0xB5,0x01,0x11,0xB0,0x3C,0x16,0x00,0x44,0xD0,0x06,0x14,0x40,0x74,0x0F,0x06,0x80,
0x11,0x54,0x02,0xA9,0x10,0x11,0x11,0x11,0x92,0x0B,0x00,0x00,0x00,0x00,0x96,0x22,
0x2C,0x40,0x50
};

void init_ptable_dict()
{
  ATermList afuns, terms;

  _ptable_dict = ATreadFromBinaryString(_ptable_dict_baf, _ptable_dict_LEN);

  ATprotect(&_ptable_dict);

  afuns = (ATermList)ATelementAt((ATermList)_ptable_dict, 0);

  PTBL_afun8 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PTBL_afun0 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PTBL_afun11 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PTBL_afun5 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PTBL_afun3 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PTBL_afun9 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PTBL_afun10 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PTBL_afun4 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PTBL_afun13 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PTBL_afun2 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PTBL_afun7 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PTBL_afun12 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PTBL_afun6 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  PTBL_afun1 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);

  terms = (ATermList)ATelementAt((ATermList)_ptable_dict, 1);

  PTBL_patternPriorityArgGreater = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternPriorityGreater = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternPrioritiesMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternPrioritiesSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternPrioritiesEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternCharClassesMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternCharClassesSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternCharClassesEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternRestrictionFollow = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternRestrictionsMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternRestrictionsSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternRestrictionsEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternSpecialAttrAvoid = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternSpecialAttrPrefer = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternSpecialAttrReject = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternSpecialAttrNone = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternActionAccept = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternActionShift = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternActionLookaheadReduce = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternActionReduce = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternActionsMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternActionsSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternActionsEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternChoiceDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternChoicesMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternChoicesSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternChoicesEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternGotoDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternGotosMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternGotosSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternGotosEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternStateDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternStatesMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternStatesSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternStatesEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternLabelDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternLabelsMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternLabelsSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternLabelsEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternParseTableParseTable = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternVersionDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternCharRangesExternal = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternCharClassExternal = ATgetFirst(terms);
  terms = ATgetNext(terms);
  PTBL_patternProductionExternal = ATgetFirst(terms);
  terms = ATgetNext(terms);
}
