#ifndef _SLICING_H
#define _SLICING_H

/*{{{  includes */

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "Slicing_dict.h"

/*}}}  */

/*{{{  prologue */


#include <Location.h>

typedef LOC_Area S_Area;


/*}}}  */
/*{{{  typedefs */

typedef struct _S_CategoryName *S_CategoryName;
typedef struct _S_Category *S_Category;
typedef struct _S_Attributes *S_Attributes;
typedef struct _S_Attribute *S_Attribute;
typedef struct _S_Color *S_Color;
typedef struct _S_Style *S_Style;
typedef struct _S_Slice *S_Slice;
typedef struct _S_Areas *S_Areas;
typedef struct _S_Slices *S_Slices;

/*}}}  */

void S_initSlicingApi(void);

/*{{{  protect functions */

void S_protectCategoryName(S_CategoryName *arg);
void S_protectCategory(S_Category *arg);
void S_protectAttributes(S_Attributes *arg);
void S_protectAttribute(S_Attribute *arg);
void S_protectColor(S_Color *arg);
void S_protectStyle(S_Style *arg);
void S_protectSlice(S_Slice *arg);
void S_protectAreas(S_Areas *arg);
void S_protectSlices(S_Slices *arg);

/*}}}  */
/*{{{  term conversion functions */

S_CategoryName S_CategoryNameFromTerm(ATerm t);
ATerm S_CategoryNameToTerm(S_CategoryName arg);
S_Category S_CategoryFromTerm(ATerm t);
ATerm S_CategoryToTerm(S_Category arg);
S_Attributes S_AttributesFromTerm(ATerm t);
ATerm S_AttributesToTerm(S_Attributes arg);
S_Attribute S_AttributeFromTerm(ATerm t);
ATerm S_AttributeToTerm(S_Attribute arg);
S_Color S_ColorFromTerm(ATerm t);
ATerm S_ColorToTerm(S_Color arg);
S_Style S_StyleFromTerm(ATerm t);
ATerm S_StyleToTerm(S_Style arg);
S_Slice S_SliceFromTerm(ATerm t);
ATerm S_SliceToTerm(S_Slice arg);
S_Areas S_AreasFromTerm(ATerm t);
ATerm S_AreasToTerm(S_Areas arg);
S_Slices S_SlicesFromTerm(ATerm t);
ATerm S_SlicesToTerm(S_Slices arg);

/*}}}  */
/*{{{  list functions */

int S_getAttributesLength (S_Attributes arg);
S_Attributes S_reverseAttributes(S_Attributes arg);
S_Attributes S_appendAttributes(S_Attributes arg, S_Attribute elem);
S_Attributes S_concatAttributes(S_Attributes arg0, S_Attributes arg1);
S_Attributes S_sliceAttributes(S_Attributes arg, int start, int end);
S_Attribute S_getAttributesAttributeAt(S_Attributes arg, int index);
S_Attributes S_replaceAttributesAttributeAt(S_Attributes arg, S_Attribute elem, int index);
S_Attributes S_makeAttributes2(S_Attribute elem1, S_Attribute elem2);
S_Attributes S_makeAttributes3(S_Attribute elem1, S_Attribute elem2, S_Attribute elem3);
S_Attributes S_makeAttributes4(S_Attribute elem1, S_Attribute elem2, S_Attribute elem3, S_Attribute elem4);
S_Attributes S_makeAttributes5(S_Attribute elem1, S_Attribute elem2, S_Attribute elem3, S_Attribute elem4, S_Attribute elem5);
S_Attributes S_makeAttributes6(S_Attribute elem1, S_Attribute elem2, S_Attribute elem3, S_Attribute elem4, S_Attribute elem5, S_Attribute elem6);
int S_getAreasLength (S_Areas arg);
S_Areas S_reverseAreas(S_Areas arg);
S_Areas S_appendAreas(S_Areas arg, S_Area elem);
S_Areas S_concatAreas(S_Areas arg0, S_Areas arg1);
S_Areas S_sliceAreas(S_Areas arg, int start, int end);
S_Area S_getAreasAreaAt(S_Areas arg, int index);
S_Areas S_replaceAreasAreaAt(S_Areas arg, S_Area elem, int index);
S_Areas S_makeAreas2(S_Area elem1, S_Area elem2);
S_Areas S_makeAreas3(S_Area elem1, S_Area elem2, S_Area elem3);
S_Areas S_makeAreas4(S_Area elem1, S_Area elem2, S_Area elem3, S_Area elem4);
S_Areas S_makeAreas5(S_Area elem1, S_Area elem2, S_Area elem3, S_Area elem4, S_Area elem5);
S_Areas S_makeAreas6(S_Area elem1, S_Area elem2, S_Area elem3, S_Area elem4, S_Area elem5, S_Area elem6);
int S_getSlicesLength (S_Slices arg);
S_Slices S_reverseSlices(S_Slices arg);
S_Slices S_appendSlices(S_Slices arg, S_Slice elem);
S_Slices S_concatSlices(S_Slices arg0, S_Slices arg1);
S_Slices S_sliceSlices(S_Slices arg, int start, int end);
S_Slice S_getSlicesSliceAt(S_Slices arg, int index);
S_Slices S_replaceSlicesSliceAt(S_Slices arg, S_Slice elem, int index);
S_Slices S_makeSlices2(S_Slice elem1, S_Slice elem2);
S_Slices S_makeSlices3(S_Slice elem1, S_Slice elem2, S_Slice elem3);
S_Slices S_makeSlices4(S_Slice elem1, S_Slice elem2, S_Slice elem3, S_Slice elem4);
S_Slices S_makeSlices5(S_Slice elem1, S_Slice elem2, S_Slice elem3, S_Slice elem4, S_Slice elem5);
S_Slices S_makeSlices6(S_Slice elem1, S_Slice elem2, S_Slice elem3, S_Slice elem4, S_Slice elem5, S_Slice elem6);

/*}}}  */
/*{{{  constructors */

S_CategoryName S_makeCategoryNameFocus(void);
S_CategoryName S_makeCategoryNameSelection(void);
S_CategoryName S_makeCategoryNameNormal(void);
S_CategoryName S_makeCategoryNameExtern(const char* name);
S_Category S_makeCategoryDefault(S_CategoryName name, S_Attributes attributes);
S_Attributes S_makeAttributesEmpty(void);
S_Attributes S_makeAttributesSingle(S_Attribute head);
S_Attributes S_makeAttributesMany(S_Attribute head, S_Attributes tail);
S_Attribute S_makeAttributeForegroundColor(S_Color color);
S_Attribute S_makeAttributeBackgroundColor(S_Color color);
S_Attribute S_makeAttributeStyle(S_Style style);
S_Attribute S_makeAttributeFont(const char* name);
S_Attribute S_makeAttributeSize(int points);
S_Color S_makeColorRgb(int red, int green, int blue);
S_Style S_makeStyleBold(void);
S_Style S_makeStyleItalics(void);
S_Style S_makeStyleUnderlined(void);
S_Slice S_makeSliceDefault(S_CategoryName category, S_Areas areas);
S_Areas S_makeAreasEmpty(void);
S_Areas S_makeAreasSingle(S_Area head);
S_Areas S_makeAreasMany(S_Area head, S_Areas tail);
S_Slices S_makeSlicesEmpty(void);
S_Slices S_makeSlicesSingle(S_Slice head);
S_Slices S_makeSlicesMany(S_Slice head, S_Slices tail);

/*}}}  */
/*{{{  equality functions */

ATbool S_isEqualCategoryName(S_CategoryName arg0, S_CategoryName arg1);
ATbool S_isEqualCategory(S_Category arg0, S_Category arg1);
ATbool S_isEqualAttributes(S_Attributes arg0, S_Attributes arg1);
ATbool S_isEqualAttribute(S_Attribute arg0, S_Attribute arg1);
ATbool S_isEqualColor(S_Color arg0, S_Color arg1);
ATbool S_isEqualStyle(S_Style arg0, S_Style arg1);
ATbool S_isEqualSlice(S_Slice arg0, S_Slice arg1);
ATbool S_isEqualAreas(S_Areas arg0, S_Areas arg1);
ATbool S_isEqualSlices(S_Slices arg0, S_Slices arg1);

/*}}}  */
/*{{{  S_CategoryName accessors */

ATbool S_isValidCategoryName(S_CategoryName arg);
inline ATbool S_isCategoryNameFocus(S_CategoryName arg);
inline ATbool S_isCategoryNameSelection(S_CategoryName arg);
inline ATbool S_isCategoryNameNormal(S_CategoryName arg);
inline ATbool S_isCategoryNameExtern(S_CategoryName arg);
ATbool S_hasCategoryNameName(S_CategoryName arg);
char* S_getCategoryNameName(S_CategoryName arg);
S_CategoryName S_setCategoryNameName(S_CategoryName arg, const char* name);

/*}}}  */
/*{{{  S_Category accessors */

ATbool S_isValidCategory(S_Category arg);
inline ATbool S_isCategoryDefault(S_Category arg);
ATbool S_hasCategoryName(S_Category arg);
ATbool S_hasCategoryAttributes(S_Category arg);
S_CategoryName S_getCategoryName(S_Category arg);
S_Attributes S_getCategoryAttributes(S_Category arg);
S_Category S_setCategoryName(S_Category arg, S_CategoryName name);
S_Category S_setCategoryAttributes(S_Category arg, S_Attributes attributes);

/*}}}  */
/*{{{  S_Attributes accessors */

ATbool S_isValidAttributes(S_Attributes arg);
inline ATbool S_isAttributesEmpty(S_Attributes arg);
inline ATbool S_isAttributesSingle(S_Attributes arg);
inline ATbool S_isAttributesMany(S_Attributes arg);
ATbool S_hasAttributesHead(S_Attributes arg);
ATbool S_hasAttributesTail(S_Attributes arg);
S_Attribute S_getAttributesHead(S_Attributes arg);
S_Attributes S_getAttributesTail(S_Attributes arg);
S_Attributes S_setAttributesHead(S_Attributes arg, S_Attribute head);
S_Attributes S_setAttributesTail(S_Attributes arg, S_Attributes tail);

/*}}}  */
/*{{{  S_Attribute accessors */

ATbool S_isValidAttribute(S_Attribute arg);
inline ATbool S_isAttributeForegroundColor(S_Attribute arg);
inline ATbool S_isAttributeBackgroundColor(S_Attribute arg);
inline ATbool S_isAttributeStyle(S_Attribute arg);
inline ATbool S_isAttributeFont(S_Attribute arg);
inline ATbool S_isAttributeSize(S_Attribute arg);
ATbool S_hasAttributeColor(S_Attribute arg);
ATbool S_hasAttributeStyle(S_Attribute arg);
ATbool S_hasAttributeName(S_Attribute arg);
ATbool S_hasAttributePoints(S_Attribute arg);
S_Color S_getAttributeColor(S_Attribute arg);
S_Style S_getAttributeStyle(S_Attribute arg);
char* S_getAttributeName(S_Attribute arg);
int S_getAttributePoints(S_Attribute arg);
S_Attribute S_setAttributeColor(S_Attribute arg, S_Color color);
S_Attribute S_setAttributeStyle(S_Attribute arg, S_Style style);
S_Attribute S_setAttributeName(S_Attribute arg, const char* name);
S_Attribute S_setAttributePoints(S_Attribute arg, int points);

/*}}}  */
/*{{{  S_Color accessors */

ATbool S_isValidColor(S_Color arg);
inline ATbool S_isColorRgb(S_Color arg);
ATbool S_hasColorRed(S_Color arg);
ATbool S_hasColorGreen(S_Color arg);
ATbool S_hasColorBlue(S_Color arg);
int S_getColorRed(S_Color arg);
int S_getColorGreen(S_Color arg);
int S_getColorBlue(S_Color arg);
S_Color S_setColorRed(S_Color arg, int red);
S_Color S_setColorGreen(S_Color arg, int green);
S_Color S_setColorBlue(S_Color arg, int blue);

/*}}}  */
/*{{{  S_Style accessors */

ATbool S_isValidStyle(S_Style arg);
inline ATbool S_isStyleBold(S_Style arg);
inline ATbool S_isStyleItalics(S_Style arg);
inline ATbool S_isStyleUnderlined(S_Style arg);

/*}}}  */
/*{{{  S_Slice accessors */

ATbool S_isValidSlice(S_Slice arg);
inline ATbool S_isSliceDefault(S_Slice arg);
ATbool S_hasSliceCategory(S_Slice arg);
ATbool S_hasSliceAreas(S_Slice arg);
S_CategoryName S_getSliceCategory(S_Slice arg);
S_Areas S_getSliceAreas(S_Slice arg);
S_Slice S_setSliceCategory(S_Slice arg, S_CategoryName category);
S_Slice S_setSliceAreas(S_Slice arg, S_Areas areas);

/*}}}  */
/*{{{  S_Areas accessors */

ATbool S_isValidAreas(S_Areas arg);
inline ATbool S_isAreasEmpty(S_Areas arg);
inline ATbool S_isAreasSingle(S_Areas arg);
inline ATbool S_isAreasMany(S_Areas arg);
ATbool S_hasAreasHead(S_Areas arg);
ATbool S_hasAreasTail(S_Areas arg);
S_Area S_getAreasHead(S_Areas arg);
S_Areas S_getAreasTail(S_Areas arg);
S_Areas S_setAreasHead(S_Areas arg, S_Area head);
S_Areas S_setAreasTail(S_Areas arg, S_Areas tail);

/*}}}  */
/*{{{  S_Slices accessors */

ATbool S_isValidSlices(S_Slices arg);
inline ATbool S_isSlicesEmpty(S_Slices arg);
inline ATbool S_isSlicesSingle(S_Slices arg);
inline ATbool S_isSlicesMany(S_Slices arg);
ATbool S_hasSlicesHead(S_Slices arg);
ATbool S_hasSlicesTail(S_Slices arg);
S_Slice S_getSlicesHead(S_Slices arg);
S_Slices S_getSlicesTail(S_Slices arg);
S_Slices S_setSlicesHead(S_Slices arg, S_Slice head);
S_Slices S_setSlicesTail(S_Slices arg, S_Slices tail);

/*}}}  */
/*{{{  sort visitors */

S_CategoryName S_visitCategoryName(S_CategoryName arg, char* (*acceptName)(char*));
S_Category S_visitCategory(S_Category arg, S_CategoryName (*acceptName)(S_CategoryName), S_Attributes (*acceptAttributes)(S_Attributes));
S_Attributes S_visitAttributes(S_Attributes arg, S_Attribute (*acceptHead)(S_Attribute));
S_Attribute S_visitAttribute(S_Attribute arg, S_Color (*acceptColor)(S_Color), S_Style (*acceptStyle)(S_Style), char* (*acceptName)(char*), int (*acceptPoints)(int));
S_Color S_visitColor(S_Color arg, int (*acceptRed)(int), int (*acceptGreen)(int), int (*acceptBlue)(int));
S_Style S_visitStyle(S_Style arg);
S_Slice S_visitSlice(S_Slice arg, S_CategoryName (*acceptCategory)(S_CategoryName), S_Areas (*acceptAreas)(S_Areas));
S_Areas S_visitAreas(S_Areas arg, S_Area (*acceptHead)(S_Area));
S_Slices S_visitSlices(S_Slices arg, S_Slice (*acceptHead)(S_Slice));

/*}}}  */

#endif /* _SLICING_H */
