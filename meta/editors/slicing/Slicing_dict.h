#ifndef __Slicing_dict_H
#define __Slicing_dict_H

#include <aterm2.h>

extern AFun S_afun8;
extern AFun S_afun0;
extern AFun S_afun11;
extern AFun S_afun5;
extern AFun S_afun3;
extern AFun S_afun9;
extern AFun S_afun10;
extern AFun S_afun4;
extern AFun S_afun13;
extern AFun S_afun14;
extern AFun S_afun2;
extern AFun S_afun7;
extern AFun S_afun12;
extern AFun S_afun6;
extern AFun S_afun1;

extern ATerm S_patternSlicesMany;
extern ATerm S_patternSlicesSingle;
extern ATerm S_patternSlicesEmpty;
extern ATerm S_patternAreasMany;
extern ATerm S_patternAreasSingle;
extern ATerm S_patternAreasEmpty;
extern ATerm S_patternSliceDefault;
extern ATerm S_patternStyleUnderlined;
extern ATerm S_patternStyleItalics;
extern ATerm S_patternStyleBold;
extern ATerm S_patternColorRgb;
extern ATerm S_patternAttributeSize;
extern ATerm S_patternAttributeFont;
extern ATerm S_patternAttributeStyle;
extern ATerm S_patternAttributeBackgroundColor;
extern ATerm S_patternAttributeForegroundColor;
extern ATerm S_patternAttributesMany;
extern ATerm S_patternAttributesSingle;
extern ATerm S_patternAttributesEmpty;
extern ATerm S_patternCategoryDefault;
extern ATerm S_patternCategoryNameExtern;
extern ATerm S_patternCategoryNameNormal;
extern ATerm S_patternCategoryNameSelection;
extern ATerm S_patternCategoryNameFocus;

extern void init_Slicing_dict();

#endif /* __Slicing_dict_H */
