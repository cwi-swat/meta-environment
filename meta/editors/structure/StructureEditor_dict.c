#include "StructureEditor_dict.h"

AFun SE_afun4;
AFun SE_afun0;
AFun SE_afun2;
AFun SE_afun5;
AFun SE_afun3;
AFun SE_afun1;

ATerm SE_patternStructureEditorUnedited = NULL;
ATerm SE_patternStructureEditorDefault = NULL;
ATerm SE_patternDirectionRight = NULL;
ATerm SE_patternDirectionDown = NULL;
ATerm SE_patternDirectionLeft = NULL;
ATerm SE_patternDirectionUp = NULL;

/*
 * SE_afun4 = default(x,x)
 * SE_afun0 = up
 * SE_afun2 = down
 * SE_afun5 = unedited(x)
 * SE_afun3 = right
 * SE_afun1 = left
 *
 * SE_patternStructureEditorUnedited = unedited(<term>)
 * SE_patternStructureEditorDefault = default(<term>,<int>)
 * SE_patternDirectionRight = right
 * SE_patternDirectionDown = down
 * SE_patternDirectionLeft = left
 * SE_patternDirectionUp = up
 *
 */

static ATerm _StructureEditor_dict = NULL;

#define _StructureEditor_dict_LEN 146

static char _StructureEditor_dict_baf[_StructureEditor_dict_LEN] = {
0x00,0x8B,0xAF,0x83,0x00,0x0C,0x1C,0x03,0x3C,0x5F,0x3E,0x01,0x00,0x02,0x02,0x03,
0x04,0x05,0x5B,0x5F,0x2C,0x5F,0x5D,0x02,0x00,0x0E,0x07,0x01,0x06,0x07,0x08,0x09,
0x0A,0x0B,0x02,0x01,0x02,0x02,0x5B,0x5D,0x00,0x00,0x01,0x03,0x69,0x6E,0x74,0x00,
0x00,0x01,0x04,0x74,0x65,0x72,0x6D,0x00,0x00,0x01,0x01,0x78,0x00,0x00,0x01,0x07,
0x64,0x65,0x66,0x61,0x75,0x6C,0x74,0x02,0x00,0x02,0x02,0x00,0x05,0x02,0x00,0x05,
0x02,0x75,0x70,0x00,0x00,0x01,0x04,0x64,0x6F,0x77,0x6E,0x00,0x00,0x01,0x08,0x75,
0x6E,0x65,0x64,0x69,0x74,0x65,0x64,0x01,0x00,0x02,0x02,0x00,0x05,0x05,0x72,0x69,
0x67,0x68,0x74,0x00,0x00,0x01,0x04,0x6C,0x65,0x66,0x74,0x00,0x00,0x01,0x01,0x15,
0x0A,0x09,0x19,0x84,0x24,0x45,0x01,0xC1,0x8D,0x30,0x42,0xC8,0x08,0x26,0x83,0x8E,
0x63,0x2A
};

void init_StructureEditor_dict()
{
  ATermList afuns, terms;

  _StructureEditor_dict = ATreadFromBinaryString(_StructureEditor_dict_baf, _StructureEditor_dict_LEN);

  ATprotect(&_StructureEditor_dict);

  afuns = (ATermList)ATelementAt((ATermList)_StructureEditor_dict, 0);

  SE_afun4 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  SE_afun0 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  SE_afun2 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  SE_afun5 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  SE_afun3 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  SE_afun1 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);

  terms = (ATermList)ATelementAt((ATermList)_StructureEditor_dict, 1);

  SE_patternStructureEditorUnedited = ATgetFirst(terms);
  terms = ATgetNext(terms);
  SE_patternStructureEditorDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  SE_patternDirectionRight = ATgetFirst(terms);
  terms = ATgetNext(terms);
  SE_patternDirectionDown = ATgetFirst(terms);
  terms = ATgetNext(terms);
  SE_patternDirectionLeft = ATgetFirst(terms);
  terms = ATgetNext(terms);
  SE_patternDirectionUp = ATgetFirst(terms);
  terms = ATgetNext(terms);
}
