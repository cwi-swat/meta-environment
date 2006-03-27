#ifndef __ptable_dict_H
#define __ptable_dict_H

#include <aterm2.h>

extern AFun PTBL_afun8;
extern AFun PTBL_afun0;
extern AFun PTBL_afun11;
extern AFun PTBL_afun5;
extern AFun PTBL_afun3;
extern AFun PTBL_afun9;
extern AFun PTBL_afun10;
extern AFun PTBL_afun4;
extern AFun PTBL_afun13;
extern AFun PTBL_afun2;
extern AFun PTBL_afun7;
extern AFun PTBL_afun12;
extern AFun PTBL_afun6;
extern AFun PTBL_afun1;

extern ATerm PTBL_patternPriorityArgGreater;
extern ATerm PTBL_patternPriorityGreater;
extern ATerm PTBL_patternPrioritiesMany;
extern ATerm PTBL_patternPrioritiesSingle;
extern ATerm PTBL_patternPrioritiesEmpty;
extern ATerm PTBL_patternCharClassesMany;
extern ATerm PTBL_patternCharClassesSingle;
extern ATerm PTBL_patternCharClassesEmpty;
extern ATerm PTBL_patternRestrictionFollow;
extern ATerm PTBL_patternRestrictionsMany;
extern ATerm PTBL_patternRestrictionsSingle;
extern ATerm PTBL_patternRestrictionsEmpty;
extern ATerm PTBL_patternSpecialAttrAvoid;
extern ATerm PTBL_patternSpecialAttrPrefer;
extern ATerm PTBL_patternSpecialAttrReject;
extern ATerm PTBL_patternSpecialAttrNone;
extern ATerm PTBL_patternActionAccept;
extern ATerm PTBL_patternActionShift;
extern ATerm PTBL_patternActionLookaheadReduce;
extern ATerm PTBL_patternActionReduce;
extern ATerm PTBL_patternActionsMany;
extern ATerm PTBL_patternActionsSingle;
extern ATerm PTBL_patternActionsEmpty;
extern ATerm PTBL_patternChoiceDefault;
extern ATerm PTBL_patternChoicesMany;
extern ATerm PTBL_patternChoicesSingle;
extern ATerm PTBL_patternChoicesEmpty;
extern ATerm PTBL_patternGotoDefault;
extern ATerm PTBL_patternGotosMany;
extern ATerm PTBL_patternGotosSingle;
extern ATerm PTBL_patternGotosEmpty;
extern ATerm PTBL_patternStateDefault;
extern ATerm PTBL_patternStatesMany;
extern ATerm PTBL_patternStatesSingle;
extern ATerm PTBL_patternStatesEmpty;
extern ATerm PTBL_patternLabelDefault;
extern ATerm PTBL_patternLabelsMany;
extern ATerm PTBL_patternLabelsSingle;
extern ATerm PTBL_patternLabelsEmpty;
extern ATerm PTBL_patternParseTableParseTable;
extern ATerm PTBL_patternVersionDefault;
extern ATerm PTBL_patternCharRangesExternal;
extern ATerm PTBL_patternCharClassExternal;
extern ATerm PTBL_patternProductionExternal;

extern void init_ptable_dict();

#endif /* __ptable_dict_H */
