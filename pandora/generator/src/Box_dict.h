#ifndef __Box_dict_H
#define __Box_dict_H

#include <aterm2.h>

extern AFun BOX_afun17;
extern AFun BOX_afun22;
extern AFun BOX_afun3;
extern AFun BOX_afun9;
extern AFun BOX_afun34;
extern AFun BOX_afun19;
extern AFun BOX_afun26;
extern AFun BOX_afun37;
extern AFun BOX_afun2;
extern AFun BOX_afun12;
extern AFun BOX_afun15;
extern AFun BOX_afun25;
extern AFun BOX_afun18;
extern AFun BOX_afun20;
extern AFun BOX_afun31;
extern AFun BOX_afun8;
extern AFun BOX_afun28;
extern AFun BOX_afun21;
extern AFun BOX_afun32;
extern AFun BOX_afun0;
extern AFun BOX_afun11;
extern AFun BOX_afun5;
extern AFun BOX_afun27;
extern AFun BOX_afun33;
extern AFun BOX_afun38;
extern AFun BOX_afun16;
extern AFun BOX_afun10;
extern AFun BOX_afun4;
extern AFun BOX_afun13;
extern AFun BOX_afun14;
extern AFun BOX_afun23;
extern AFun BOX_afun30;
extern AFun BOX_afun7;
extern AFun BOX_afun36;
extern AFun BOX_afun24;
extern AFun BOX_afun35;
extern AFun BOX_afun29;
extern AFun BOX_afun1;
extern AFun BOX_afun6;

extern ATerm BOX_patternOptLayoutPresent;
extern ATerm BOX_patternOptLayoutAbsent;
extern ATerm BOX_patternStartNatCon;
extern ATerm BOX_patternStartStrCon;
extern ATerm BOX_patternStartNormal;
extern ATerm BOX_patternStartEscaped;
extern ATerm BOX_patternStartBox;
extern ATerm BOX_patternStartSpaceSymbol;
extern ATerm BOX_patternStartSOption;
extern ATerm BOX_patternStartSOptions;
extern ATerm BOX_patternBoxListMany;
extern ATerm BOX_patternBoxListSingle;
extern ATerm BOX_patternBoxListEmpty;
extern ATerm BOX_patternBoxWD;
extern ATerm BOX_patternBoxI;
extern ATerm BOX_patternBoxHOV;
extern ATerm BOX_patternBoxHV;
extern ATerm BOX_patternBoxV;
extern ATerm BOX_patternBoxH;
extern ATerm BOX_patternBoxString;
extern ATerm BOX_patternSOptionListMany;
extern ATerm BOX_patternSOptionListSingle;
extern ATerm BOX_patternSOptionListEmpty;
extern ATerm BOX_patternSOptionsDefault;
extern ATerm BOX_patternSOptionDefault;
extern ATerm BOX_patternSpaceSymbolIs;
extern ATerm BOX_patternSpaceSymbolVs;
extern ATerm BOX_patternSpaceSymbolHs;
extern ATerm BOX_patternStrConDefault;
extern ATerm BOX_patternEscapedOctal;
extern ATerm BOX_patternEscapedSpecialCharacter;
extern ATerm BOX_patternNormalDefault;
extern ATerm BOX_patternNatConDefault;

extern void init_Box_dict();

#endif /* __Box_dict_H */
