#include "Actions_dict.h"

AFun AC_afun8;
AFun AC_afun0;
AFun AC_afun11;
AFun AC_afun5;
AFun AC_afun3;
AFun AC_afun9;
AFun AC_afun10;
AFun AC_afun4;
AFun AC_afun13;
AFun AC_afun2;
AFun AC_afun7;
AFun AC_afun12;
AFun AC_afun6;
AFun AC_afun1;

ATerm AC_patternItemString = NULL;
ATerm AC_patternStackMany = NULL;
ATerm AC_patternStackSingle = NULL;
ATerm AC_patternStackEmpty = NULL;
ATerm AC_patternMessageEditTerm = NULL;
ATerm AC_patternMessagePromptForFile = NULL;
ATerm AC_patternArgTree = NULL;
ATerm AC_patternArgString = NULL;
ATerm AC_patternArgsMany = NULL;
ATerm AC_patternArgsSingle = NULL;
ATerm AC_patternArgsEmpty = NULL;
ATerm AC_patternDescriptionAction = NULL;
ATerm AC_patternDescriptionsMany = NULL;
ATerm AC_patternDescriptionsSingle = NULL;
ATerm AC_patternDescriptionsEmpty = NULL;
ATerm AC_patternSignatureList = NULL;
ATerm AC_patternActionGeneric = NULL;
ATerm AC_patternActionCondition = NULL;
ATerm AC_patternActionPushModulename = NULL;
ATerm AC_patternActionPushFilename = NULL;
ATerm AC_patternActionPushTerm = NULL;
ATerm AC_patternActionApply = NULL;
ATerm AC_patternActionPushString = NULL;
ATerm AC_patternActionPop = NULL;
ATerm AC_patternActionDup = NULL;
ATerm AC_patternActionsMany = NULL;
ATerm AC_patternActionsSingle = NULL;
ATerm AC_patternActionsEmpty = NULL;
ATerm AC_patternScriptList = NULL;

/*
 * AC_afun8 = action(x,x)
 * AC_afun0 = dup
 * AC_afun11 = new-prompt-for-file(x,x,x)
 * AC_afun5 = push-filename(x)
 * AC_afun3 = apply(x,x,x)
 * AC_afun9 = string
 * AC_afun10 = tree
 * AC_afun4 = push-term(x)
 * AC_afun13 = str(x)
 * AC_afun2 = push-string(x)
 * AC_afun7 = if-equal(x,x)
 * AC_afun12 = new-edit-term(x,x)
 * AC_afun6 = push-modulename(x)
 * AC_afun1 = pop
 *
 * AC_patternItemString = str(<str>)
 * AC_patternStackMany = [<term>,<list>]
 * AC_patternStackSingle = [<term>]
 * AC_patternStackEmpty = []
 * AC_patternMessageEditTerm = new-edit-term(<str>,<str>)
 * AC_patternMessagePromptForFile = new-prompt-for-file(<str>,<str>,<str>)
 * AC_patternArgTree = tree
 * AC_patternArgString = string
 * AC_patternArgsMany = [<term>,<list>]
 * AC_patternArgsSingle = [<term>]
 * AC_patternArgsEmpty = []
 * AC_patternDescriptionAction = action(<term>,<term>)
 * AC_patternDescriptionsMany = [<term>,<list>]
 * AC_patternDescriptionsSingle = [<term>]
 * AC_patternDescriptionsEmpty = []
 * AC_patternSignatureList = <term>
 * AC_patternActionGeneric = <term>
 * AC_patternActionCondition = if-equal(<term>,<term>)
 * AC_patternActionPushModulename = push-modulename(<str>)
 * AC_patternActionPushFilename = push-filename(<str>)
 * AC_patternActionPushTerm = push-term(<term>)
 * AC_patternActionApply = apply(<str>,<str>,<int>)
 * AC_patternActionPushString = push-string(<str>)
 * AC_patternActionPop = pop
 * AC_patternActionDup = dup
 * AC_patternActionsMany = [<term>,<list>]
 * AC_patternActionsSingle = [<term>]
 * AC_patternActionsEmpty = []
 * AC_patternScriptList = <term>
 *
 */

static ATerm _Actions_dict = NULL;

#define _Actions_dict_LEN 421

static char _Actions_dict_baf[_Actions_dict_LEN] = {
0x00,0x8B,0xAF,0x83,0x00,0x16,0x51,0x03,0x3C,0x5F,0x3E,0x01,0x00,0x04,0x04,0x03,
0x05,0x06,0x04,0x05,0x5B,0x5F,0x2C,0x5F,0x5D,0x02,0x00,0x2F,0x11,0x01,0x02,0x00,
0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x02,0x01,
0x02,0x02,0x5B,0x5D,0x00,0x00,0x01,0x03,0x69,0x6E,0x74,0x00,0x00,0x01,0x03,0x73,
0x74,0x72,0x00,0x00,0x01,0x04,0x6C,0x69,0x73,0x74,0x00,0x00,0x01,0x04,0x74,0x65,
0x72,0x6D,0x00,0x00,0x01,0x01,0x78,0x00,0x00,0x01,0x06,0x61,0x63,0x74,0x69,0x6F,
0x6E,0x02,0x00,0x02,0x02,0x00,0x07,0x02,0x00,0x07,0x03,0x64,0x75,0x70,0x00,0x00,
0x01,0x13,0x6E,0x65,0x77,0x2D,0x70,0x72,0x6F,0x6D,0x70,0x74,0x2D,0x66,0x6F,0x72,
0x2D,0x66,0x69,0x6C,0x65,0x03,0x00,0x02,0x02,0x00,0x07,0x02,0x00,0x07,0x02,0x00,
0x07,0x0D,0x70,0x75,0x73,0x68,0x2D,0x66,0x69,0x6C,0x65,0x6E,0x61,0x6D,0x65,0x01,
0x00,0x02,0x02,0x00,0x07,0x05,0x61,0x70,0x70,0x6C,0x79,0x03,0x00,0x02,0x02,0x00,
0x07,0x02,0x00,0x07,0x02,0x00,0x07,0x06,0x73,0x74,0x72,0x69,0x6E,0x67,0x00,0x00,
0x01,0x04,0x74,0x72,0x65,0x65,0x00,0x00,0x01,0x09,0x70,0x75,0x73,0x68,0x2D,0x74,
0x65,0x72,0x6D,0x01,0x00,0x02,0x02,0x00,0x07,0x03,0x73,0x74,0x72,0x01,0x00,0x02,
0x02,0x00,0x07,0x0B,0x70,0x75,0x73,0x68,0x2D,0x73,0x74,0x72,0x69,0x6E,0x67,0x01,
0x00,0x02,0x02,0x00,0x07,0x08,0x69,0x66,0x2D,0x65,0x71,0x75,0x61,0x6C,0x02,0x00,
0x02,0x02,0x00,0x07,0x02,0x00,0x07,0x0D,0x6E,0x65,0x77,0x2D,0x65,0x64,0x69,0x74,
0x2D,0x74,0x65,0x72,0x6D,0x02,0x00,0x02,0x02,0x00,0x07,0x02,0x00,0x07,0x0F,0x70,
0x75,0x73,0x68,0x2D,0x6D,0x6F,0x64,0x75,0x6C,0x65,0x6E,0x61,0x6D,0x65,0x01,0x00,
0x02,0x02,0x00,0x07,0x03,0x70,0x6F,0x70,0x00,0x00,0x01,0x01,0x05,0x98,0x28,0x30,
0x86,0x94,0x2A,0x14,0x61,0x12,0x70,0xA8,0x10,0x47,0x12,0x18,0x51,0x14,0x68,0x82,
0x0C,0x46,0x16,0x28,0x41,0xC5,0x10,0x78,0x80,0x03,0x16,0x80,0xDD,0x40,0xC6,0xA0,
0xF1,0x11,0x0E,0x21,0x48,0x54,0x01,0x22,0x44,0xB0,0x05,0x74,0x00,0x1C,0xD2,0x00,
0x00,0x33,0x22,0x91,0x04,0x83,0xC3,0x10,0x04,0x23,0x02,0x1C,0x44,0x20,0x08,0x3C,
0x3E,0x00,0x43,0xD0,0x2E,0x44,0x0E,0x44,0x36,0xB4,0x42,0x0B,0x7A,0x01,0x33,0x20,
0x03,0x2A,0x21,0xD7,0x20,0x00,0xC0,0x68,0xD0,0x0A,0x82,0x14,0x43,0x20,0x78,0x24,
0x00,0x88,0xA0,0x05,0x00
};

void init_Actions_dict()
{
  ATermList afuns, terms;

  _Actions_dict = ATreadFromBinaryString(_Actions_dict_baf, _Actions_dict_LEN);

  ATprotect(&_Actions_dict);

  afuns = (ATermList)ATelementAt((ATermList)_Actions_dict, 0);

  AC_afun8 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  AC_afun0 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  AC_afun11 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  AC_afun5 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  AC_afun3 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  AC_afun9 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  AC_afun10 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  AC_afun4 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  AC_afun13 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  AC_afun2 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  AC_afun7 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  AC_afun12 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  AC_afun6 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  AC_afun1 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);

  terms = (ATermList)ATelementAt((ATermList)_Actions_dict, 1);

  AC_patternItemString = ATgetFirst(terms);
  terms = ATgetNext(terms);
  AC_patternStackMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  AC_patternStackSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  AC_patternStackEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  AC_patternMessageEditTerm = ATgetFirst(terms);
  terms = ATgetNext(terms);
  AC_patternMessagePromptForFile = ATgetFirst(terms);
  terms = ATgetNext(terms);
  AC_patternArgTree = ATgetFirst(terms);
  terms = ATgetNext(terms);
  AC_patternArgString = ATgetFirst(terms);
  terms = ATgetNext(terms);
  AC_patternArgsMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  AC_patternArgsSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  AC_patternArgsEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  AC_patternDescriptionAction = ATgetFirst(terms);
  terms = ATgetNext(terms);
  AC_patternDescriptionsMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  AC_patternDescriptionsSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  AC_patternDescriptionsEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  AC_patternSignatureList = ATgetFirst(terms);
  terms = ATgetNext(terms);
  AC_patternActionGeneric = ATgetFirst(terms);
  terms = ATgetNext(terms);
  AC_patternActionCondition = ATgetFirst(terms);
  terms = ATgetNext(terms);
  AC_patternActionPushModulename = ATgetFirst(terms);
  terms = ATgetNext(terms);
  AC_patternActionPushFilename = ATgetFirst(terms);
  terms = ATgetNext(terms);
  AC_patternActionPushTerm = ATgetFirst(terms);
  terms = ATgetNext(terms);
  AC_patternActionApply = ATgetFirst(terms);
  terms = ATgetNext(terms);
  AC_patternActionPushString = ATgetFirst(terms);
  terms = ATgetNext(terms);
  AC_patternActionPop = ATgetFirst(terms);
  terms = ATgetNext(terms);
  AC_patternActionDup = ATgetFirst(terms);
  terms = ATgetNext(terms);
  AC_patternActionsMany = ATgetFirst(terms);
  terms = ATgetNext(terms);
  AC_patternActionsSingle = ATgetFirst(terms);
  terms = ATgetNext(terms);
  AC_patternActionsEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  AC_patternScriptList = ATgetFirst(terms);
  terms = ATgetNext(terms);
}
