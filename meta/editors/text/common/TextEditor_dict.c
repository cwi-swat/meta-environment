#include "TextEditor_dict.h"

AFun TE_afun8;
AFun TE_afun17;
AFun TE_afun0;
AFun TE_afun11;
AFun TE_afun5;
AFun TE_afun3;
AFun TE_afun9;
AFun TE_afun16;
AFun TE_afun10;
AFun TE_afun4;
AFun TE_afun13;
AFun TE_afun14;
AFun TE_afun2;
AFun TE_afun7;
AFun TE_afun12;
AFun TE_afun15;
AFun TE_afun18;
AFun TE_afun6;
AFun TE_afun1;

ATerm TE_patternPipeDefault = NULL;
ATerm TE_patternProcessDefault = NULL;
ATerm TE_patternEventModified = NULL;
ATerm TE_patternEventContents = NULL;
ATerm TE_patternEventMouse = NULL;
ATerm TE_patternEventMenu = NULL;
ATerm TE_patternMenuShortcut = NULL;
ATerm TE_patternMenuDefault = NULL;
ATerm TE_patternActionListMulti = NULL;
ATerm TE_patternActionListEmpty = NULL;
ATerm TE_patternActionSetActions = NULL;
ATerm TE_patternActionGetContents = NULL;
ATerm TE_patternActionSetFocus = NULL;
ATerm TE_patternActionClearFocus = NULL;
ATerm TE_patternActionSetFocusAtLocation = NULL;
ATerm TE_patternActionSetCursorAtOffset = NULL;
ATerm TE_patternActionDisplayMessage = NULL;
ATerm TE_patternActionRereadContents = NULL;
ATerm TE_patternActionWriteContents = NULL;
ATerm TE_patternActionToFront = NULL;

/*
 * TE_afun8 = set-focus(x)
 * TE_afun17 = process(x,x)
 * TE_afun0 = action(x)
 * TE_afun11 = menu(x)
 * TE_afun5 = set-cursor-at-offset(x)
 * TE_afun3 = reread-contents
 * TE_afun9 = get-contents(x)
 * TE_afun16 = modified
 * TE_afun10 = set-actions(x)
 * TE_afun4 = display-message(x)
 * TE_afun13 = menu-event(x)
 * TE_afun14 = mouse-event(x)
 * TE_afun2 = write-contents
 * TE_afun7 = clear-focus
 * TE_afun12 = menuwithshortcut(x,x)
 * TE_afun15 = contents(x)
 * TE_afun18 = pipe(x,x)
 * TE_afun6 = set-focus-at-location(x)
 * TE_afun1 = to-front
 *
 * TE_patternPipeDefault = pipe(<int>,<int>)
 * TE_patternProcessDefault = process(<term>,<term>)
 * TE_patternEventModified = modified
 * TE_patternEventContents = contents(<str>)
 * TE_patternEventMouse = mouse-event(<int>)
 * TE_patternEventMenu = menu-event(<term>)
 * TE_patternMenuShortcut = menuwithshortcut([<str>,<str>],<str>)
 * TE_patternMenuDefault = menu([<str>,<str>])
 * TE_patternActionListMulti = [<term>,<list>]
 * TE_patternActionListEmpty = []
 * TE_patternActionSetActions = action(set-actions(<term>))
 * TE_patternActionGetContents = action(get-contents(<term>))
 * TE_patternActionSetFocus = action(set-focus(<term>))
 * TE_patternActionClearFocus = action(clear-focus)
 * TE_patternActionSetFocusAtLocation = action(set-focus-at-location(<term>))
 * TE_patternActionSetCursorAtOffset = action(set-cursor-at-offset(<int>))
 * TE_patternActionDisplayMessage = action(display-message(<str>))
 * TE_patternActionRereadContents = action(reread-contents)
 * TE_patternActionWriteContents = action(write-contents)
 * TE_patternActionToFront = action(to-front)
 *
 */

static ATerm _TextEditor_dict = NULL;

#define _TextEditor_dict_LEN 549

static char _TextEditor_dict_baf[_TextEditor_dict_LEN] = {
0x00,0x8B,0xAF,0x83,0x00,0x1B,0x61,0x03,0x3C,0x5F,0x3E,0x01,0x00,0x04,0x04,0x05,
0x04,0x06,0x03,0x05,0x5B,0x5F,0x2C,0x5F,0x5D,0x02,0x00,0x2D,0x16,0x01,0x02,0x00,
0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,
0x18,0x19,0x1A,0x02,0x01,0x02,0x02,0x5B,0x5D,0x00,0x00,0x01,0x03,0x69,0x6E,0x74,
0x00,0x00,0x01,0x03,0x73,0x74,0x72,0x00,0x00,0x01,0x04,0x6C,0x69,0x73,0x74,0x00,
0x00,0x01,0x04,0x74,0x65,0x72,0x6D,0x00,0x00,0x01,0x01,0x78,0x00,0x00,0x01,0x09,
0x73,0x65,0x74,0x2D,0x66,0x6F,0x63,0x75,0x73,0x01,0x00,0x02,0x02,0x00,0x07,0x07,
0x70,0x72,0x6F,0x63,0x65,0x73,0x73,0x02,0x00,0x02,0x02,0x00,0x07,0x02,0x00,0x07,
0x06,0x61,0x63,0x74,0x69,0x6F,0x6E,0x01,0x00,0x0B,0x0B,0x1A,0x14,0x0D,0x11,0x0C,
0x19,0x15,0x08,0x0E,0x10,0x07,0x04,0x6D,0x65,0x6E,0x75,0x01,0x00,0x02,0x02,0x01,
0x07,0x14,0x73,0x65,0x74,0x2D,0x63,0x75,0x72,0x73,0x6F,0x72,0x2D,0x61,0x74,0x2D,
0x6F,0x66,0x66,0x73,0x65,0x74,0x01,0x00,0x02,0x02,0x00,0x07,0x0F,0x72,0x65,0x72,
0x65,0x61,0x64,0x2D,0x63,0x6F,0x6E,0x74,0x65,0x6E,0x74,0x73,0x00,0x00,0x01,0x0C,
0x67,0x65,0x74,0x2D,0x63,0x6F,0x6E,0x74,0x65,0x6E,0x74,0x73,0x01,0x00,0x02,0x02,
0x00,0x07,0x08,0x6D,0x6F,0x64,0x69,0x66,0x69,0x65,0x64,0x00,0x00,0x01,0x0B,0x73,
0x65,0x74,0x2D,0x61,0x63,0x74,0x69,0x6F,0x6E,0x73,0x01,0x00,0x02,0x02,0x00,0x07,
0x0F,0x64,0x69,0x73,0x70,0x6C,0x61,0x79,0x2D,0x6D,0x65,0x73,0x73,0x61,0x67,0x65,
0x01,0x00,0x02,0x02,0x00,0x07,0x0A,0x6D,0x65,0x6E,0x75,0x2D,0x65,0x76,0x65,0x6E,
0x74,0x01,0x00,0x02,0x02,0x00,0x07,0x0B,0x6D,0x6F,0x75,0x73,0x65,0x2D,0x65,0x76,
0x65,0x6E,0x74,0x01,0x00,0x02,0x02,0x00,0x07,0x0E,0x77,0x72,0x69,0x74,0x65,0x2D,
0x63,0x6F,0x6E,0x74,0x65,0x6E,0x74,0x73,0x00,0x00,0x01,0x0B,0x63,0x6C,0x65,0x61,
0x72,0x2D,0x66,0x6F,0x63,0x75,0x73,0x00,0x00,0x01,0x10,0x6D,0x65,0x6E,0x75,0x77,
0x69,0x74,0x68,0x73,0x68,0x6F,0x72,0x74,0x63,0x75,0x74,0x02,0x00,0x02,0x02,0x01,
0x07,0x02,0x00,0x07,0x08,0x63,0x6F,0x6E,0x74,0x65,0x6E,0x74,0x73,0x01,0x00,0x02,
0x02,0x00,0x07,0x04,0x70,0x69,0x70,0x65,0x02,0x00,0x02,0x02,0x00,0x07,0x02,0x00,
0x07,0x15,0x73,0x65,0x74,0x2D,0x66,0x6F,0x63,0x75,0x73,0x2D,0x61,0x74,0x2D,0x6C,
0x6F,0x63,0x61,0x74,0x69,0x6F,0x6E,0x01,0x00,0x02,0x02,0x00,0x07,0x08,0x74,0x6F,
0x2D,0x66,0x72,0x6F,0x6E,0x74,0x00,0x00,0x01,0x01,0x02,0x58,0x22,0x22,0x14,0x05,
0x40,0x53,0xC6,0x10,0xE7,0x08,0xB0,0x41,0x92,0x23,0x45,0x0A,0x68,0x89,0x0C,0x40,
0x96,0x23,0x87,0x10,0xC7,0x8A,0x02,0x11,0x12,0x8C,0x12,0x42,0x19,0x28,0x80,0xA4,
0x01,0x58,0xD4,0x0A,0xE6,0x06,0x01,0x29,0x22,0x22,0x02,0xA8,0xE5,0x30,0xA0,0xCB,
0xA0,0x14,0xDA,0x20,0x4C,0x60,0xA4,0x23,0x24,0x28,0x46,0x2C,0x82,0x84,0x40,0xD2,
0x21,0x52,0x30,0x88,0x60,0x03,0x48,0x98,0x87,0xD4,0x41,0x88,0x3D,0x4C,0xE8,0x85,
0xD4,0x26,0x0E,0xA5,0x54,0x43,0x6A,0x31,0x40,0x16,0xA7,0x64,0x22,0x6A,0x0A,0x03,
0x52,0x60,0xEA,0x8A,0x14
};

void init_TextEditor_dict()
{
  ATermList afuns, terms;

  _TextEditor_dict = ATreadFromBinaryString(_TextEditor_dict_baf, _TextEditor_dict_LEN);

  ATprotect(&_TextEditor_dict);

  afuns = (ATermList)ATelementAt((ATermList)_TextEditor_dict, 0);

  TE_afun8 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  TE_afun17 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  TE_afun0 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  TE_afun11 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  TE_afun5 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  TE_afun3 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  TE_afun9 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  TE_afun16 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  TE_afun10 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  TE_afun4 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  TE_afun13 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  TE_afun14 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  TE_afun2 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  TE_afun7 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  TE_afun12 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  TE_afun15 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  TE_afun18 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  TE_afun6 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);
  TE_afun1 = ATgetAFun((ATermAppl)ATgetFirst(afuns));
  afuns = ATgetNext(afuns);

  terms = (ATermList)ATelementAt((ATermList)_TextEditor_dict, 1);

  TE_patternPipeDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  TE_patternProcessDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  TE_patternEventModified = ATgetFirst(terms);
  terms = ATgetNext(terms);
  TE_patternEventContents = ATgetFirst(terms);
  terms = ATgetNext(terms);
  TE_patternEventMouse = ATgetFirst(terms);
  terms = ATgetNext(terms);
  TE_patternEventMenu = ATgetFirst(terms);
  terms = ATgetNext(terms);
  TE_patternMenuShortcut = ATgetFirst(terms);
  terms = ATgetNext(terms);
  TE_patternMenuDefault = ATgetFirst(terms);
  terms = ATgetNext(terms);
  TE_patternActionListMulti = ATgetFirst(terms);
  terms = ATgetNext(terms);
  TE_patternActionListEmpty = ATgetFirst(terms);
  terms = ATgetNext(terms);
  TE_patternActionSetActions = ATgetFirst(terms);
  terms = ATgetNext(terms);
  TE_patternActionGetContents = ATgetFirst(terms);
  terms = ATgetNext(terms);
  TE_patternActionSetFocus = ATgetFirst(terms);
  terms = ATgetNext(terms);
  TE_patternActionClearFocus = ATgetFirst(terms);
  terms = ATgetNext(terms);
  TE_patternActionSetFocusAtLocation = ATgetFirst(terms);
  terms = ATgetNext(terms);
  TE_patternActionSetCursorAtOffset = ATgetFirst(terms);
  terms = ATgetNext(terms);
  TE_patternActionDisplayMessage = ATgetFirst(terms);
  terms = ATgetNext(terms);
  TE_patternActionRereadContents = ATgetFirst(terms);
  terms = ATgetNext(terms);
  TE_patternActionWriteContents = ATgetFirst(terms);
  terms = ATgetNext(terms);
  TE_patternActionToFront = ATgetFirst(terms);
  terms = ATgetNext(terms);
}
