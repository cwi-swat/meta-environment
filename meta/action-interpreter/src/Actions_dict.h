#ifndef __Actions_dict_H
#define __Actions_dict_H

#include <aterm2.h>

extern AFun AC_afun8;
extern AFun AC_afun0;
extern AFun AC_afun11;
extern AFun AC_afun5;
extern AFun AC_afun3;
extern AFun AC_afun9;
extern AFun AC_afun10;
extern AFun AC_afun4;
extern AFun AC_afun13;
extern AFun AC_afun2;
extern AFun AC_afun7;
extern AFun AC_afun12;
extern AFun AC_afun6;
extern AFun AC_afun1;

extern ATerm AC_patternItemString;
extern ATerm AC_patternStackMany;
extern ATerm AC_patternStackSingle;
extern ATerm AC_patternStackEmpty;
extern ATerm AC_patternMessageEditTerm;
extern ATerm AC_patternMessagePromptForFile;
extern ATerm AC_patternArgTree;
extern ATerm AC_patternArgString;
extern ATerm AC_patternArgsMany;
extern ATerm AC_patternArgsSingle;
extern ATerm AC_patternArgsEmpty;
extern ATerm AC_patternDescriptionAction;
extern ATerm AC_patternDescriptionsMany;
extern ATerm AC_patternDescriptionsSingle;
extern ATerm AC_patternDescriptionsEmpty;
extern ATerm AC_patternSignatureList;
extern ATerm AC_patternActionGeneric;
extern ATerm AC_patternActionCondition;
extern ATerm AC_patternActionPushModulename;
extern ATerm AC_patternActionPushFilename;
extern ATerm AC_patternActionPushTerm;
extern ATerm AC_patternActionApply;
extern ATerm AC_patternActionPushString;
extern ATerm AC_patternActionPop;
extern ATerm AC_patternActionDup;
extern ATerm AC_patternActionsMany;
extern ATerm AC_patternActionsSingle;
extern ATerm AC_patternActionsEmpty;
extern ATerm AC_patternScriptList;

extern void init_Actions_dict();

#endif /* __Actions_dict_H */
