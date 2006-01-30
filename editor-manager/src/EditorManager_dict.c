#include "EditorManager_dict.h"

AFun EM_afun0;
AFun EM_afun2;
AFun EM_afun3;
AFun EM_afun1;

ATerm EM_patternEditorTypeListMany = NULL;
ATerm EM_patternEditorTypeListSingle = NULL;
ATerm EM_patternEditorTypeListEmpty = NULL;
ATerm EM_patternSessionDefault = NULL;
ATerm EM_patternSessionStatusZombie = NULL;
ATerm EM_patternSessionStatusRunning = NULL;
ATerm EM_patternModuleIdDefault = NULL;
ATerm EM_patternEditorTypeDefault = NULL;
ATerm EM_patternSidDefault = NULL;

/*
 * EM_afun0 = Default(x)
 * EM_afun2 = zombie
 * EM_afun3 = Default(x,x,x,x,x)
 * EM_afun1 = running
 *
 * EM_patternEditorTypeListMany = [<term>,<list>]
 * EM_patternEditorTypeListSingle = [<term>]
 * EM_patternEditorTypeListEmpty = []
 * EM_patternSessionDefault = Default(<term>,<str>,<term>,<int>,<term>)
 * EM_patternSessionStatusZombie = zombie
 * EM_patternSessionStatusRunning = running
 * EM_patternModuleIdDefault = Default(<int>)
 * EM_patternEditorTypeDefault = Default(<str>)
 * EM_patternSidDefault = Default(<int>)
 *
 */

static ATerm _EditorManager_dict = NULL;

#define _EditorManager_dict_LEN 174

static char _EditorManager_dict_baf[_EditorManager_dict_LEN] = {
0x00,0x8B,0xAF,0x83,0x00,0x0C,0x23,0x03,0x3C,0x5F,0x3E,0x01,0x00,0x04,0x04,0x03,
0x04,0x05,0x06,0x05,0x5B,0x5F,0x2C,0x5F,0x5D,0x02,0x00,0x12,0x07,0x01,0x02,0x00,
0x08,0x09,0x0A,0x0B,0x02,0x01,0x02,0x02,0x5B,0x5D,0x00,0x00,0x01,0x03,0x69,0x6E,
0x74,0x00,0x00,0x01,0x03,0x73,0x74,0x72,0x00,0x00,0x01,0x04,0x6C,0x69,0x73,0x74,
0x00,0x00,0x01,0x04,0x74,0x65,0x72,0x6D,0x00,0x00,0x01,0x01,0x78,0x00,0x00,0x01,
0x07,0x44,0x65,0x66,0x61,0x75,0x6C,0x74,0x01,0x00,0x03,0x02,0x00,0x07,0x06,0x7A,
0x6F,0x6D,0x62,0x69,0x65,0x00,0x00,0x01,0x07,0x44,0x65,0x66,0x61,0x75,0x6C,0x74,
0x05,0x00,0x02,0x02,0x00,0x07,0x02,0x00,0x07,0x02,0x00,0x07,0x02,0x00,0x07,0x02,
0x00,0x07,0x07,0x72,0x75,0x6E,0x6E,0x69,0x6E,0x67,0x00,0x00,0x01,0x01,0x18,0xC4,
0x20,0x90,0xA5,0x54,0x01,0xC0,0x47,0x85,0x10,0xC1,0x14,0x50,0xE0,0xC4,0x22,0xD0,
0x35,0x80,0x28,0x03,0x00,0x1A,0x22,0x99,0x2D,0x18,0x16,0x44,0x73,0x54
};

void init_EditorManager_dict()
{
  ATermList afuns, terms;

  _EditorManager_dict = ATreadFromBinaryString(_EditorManager_dict_baf, _EditorManager_dict_LEN);

  ATprotect(&_EditorManager_dict);

  afuns = (ATermList)ATelementAt((ATermList)_EditorManager_dict, 0);

  EM_afun0 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  EM_afun2 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  EM_afun3 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  EM_afun1 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);

  terms = (ATermList)ATelementAt((ATermList)_EditorManager_dict, 1);

  EM_patternEditorTypeListMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  EM_patternEditorTypeListSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  EM_patternEditorTypeListEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  EM_patternSessionDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  EM_patternSessionStatusZombie = ATgetFirst(terms);
  terms = ATgetNext(terms);
  EM_patternSessionStatusRunning = ATgetFirst(terms);
  terms = ATgetNext(terms);
  EM_patternModuleIdDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  EM_patternEditorTypeDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  EM_patternSidDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
}
