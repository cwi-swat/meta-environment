#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "Slicing.h"

/*{{{  conversion functions */

ATerm S_stringToChars(const char *str)
{
  int len = strlen(str);
  int i;
  ATermList result = ATempty;

  for (i = len - 1; i >= 0; i--) {
    result = ATinsert(result, (ATerm) ATmakeInt(str[i]));
  }

  return (ATerm) result;
}

char *S_charsToString(ATerm arg)
{
  ATermList list = (ATermList) arg;
  int len = ATgetLength(list);
  int i;
  char *str;

  str = (char *) malloc(len+1);
  if (str == NULL) {
      return NULL;
  }

  for (i = 0; !ATisEmpty(list); list = ATgetNext(list), i++) {
    str[i] = (char) ATgetInt((ATermInt) ATgetFirst(list));
  }
  str[i] = '\0';

  return str;
}


/*}}}  */

/*{{{  typedefs */

typedef struct ATerm _S_CategoryName;
typedef struct ATerm _S_Category;
typedef struct ATerm _S_Attributes;
typedef struct ATerm _S_Attribute;
typedef struct ATerm _S_Color;
typedef struct ATerm _S_Style;
typedef struct ATerm _S_Slice;
typedef struct ATerm _S_Areas;
typedef struct ATerm _S_Slices;

/*}}}  */

/*{{{  void S_initSlicingApi(void) */

void S_initSlicingApi(void)
{
  init_Slicing_dict();
}

/*}}}  */

/*{{{  protect functions */

void S_protectCategoryName(S_CategoryName *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void S_protectCategory(S_Category *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void S_protectAttributes(S_Attributes *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void S_protectAttribute(S_Attribute *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void S_protectColor(S_Color *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void S_protectStyle(S_Style *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void S_protectSlice(S_Slice *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void S_protectAreas(S_Areas *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void S_protectSlices(S_Slices *arg)
{
  ATprotect((ATerm*)((void*) arg));
}


/*}}}  */
/*{{{  term conversion functions */

/*{{{  S_CategoryName S_CategoryNameFromTerm(ATerm t) */

S_CategoryName S_CategoryNameFromTerm(ATerm t)
{
  return (S_CategoryName)t;
}

/*}}}  */
/*{{{  ATerm S_CategoryNameToTerm(S_CategoryName arg) */

ATerm S_CategoryNameToTerm(S_CategoryName arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  S_Category S_CategoryFromTerm(ATerm t) */

S_Category S_CategoryFromTerm(ATerm t)
{
  return (S_Category)t;
}

/*}}}  */
/*{{{  ATerm S_CategoryToTerm(S_Category arg) */

ATerm S_CategoryToTerm(S_Category arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  S_Attributes S_AttributesFromTerm(ATerm t) */

S_Attributes S_AttributesFromTerm(ATerm t)
{
  return (S_Attributes)t;
}

/*}}}  */
/*{{{  ATerm S_AttributesToTerm(S_Attributes arg) */

ATerm S_AttributesToTerm(S_Attributes arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  S_Attribute S_AttributeFromTerm(ATerm t) */

S_Attribute S_AttributeFromTerm(ATerm t)
{
  return (S_Attribute)t;
}

/*}}}  */
/*{{{  ATerm S_AttributeToTerm(S_Attribute arg) */

ATerm S_AttributeToTerm(S_Attribute arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  S_Color S_ColorFromTerm(ATerm t) */

S_Color S_ColorFromTerm(ATerm t)
{
  return (S_Color)t;
}

/*}}}  */
/*{{{  ATerm S_ColorToTerm(S_Color arg) */

ATerm S_ColorToTerm(S_Color arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  S_Style S_StyleFromTerm(ATerm t) */

S_Style S_StyleFromTerm(ATerm t)
{
  return (S_Style)t;
}

/*}}}  */
/*{{{  ATerm S_StyleToTerm(S_Style arg) */

ATerm S_StyleToTerm(S_Style arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  S_Slice S_SliceFromTerm(ATerm t) */

S_Slice S_SliceFromTerm(ATerm t)
{
  return (S_Slice)t;
}

/*}}}  */
/*{{{  ATerm S_SliceToTerm(S_Slice arg) */

ATerm S_SliceToTerm(S_Slice arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  S_Areas S_AreasFromTerm(ATerm t) */

S_Areas S_AreasFromTerm(ATerm t)
{
  return (S_Areas)t;
}

/*}}}  */
/*{{{  ATerm S_AreasToTerm(S_Areas arg) */

ATerm S_AreasToTerm(S_Areas arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  S_Slices S_SlicesFromTerm(ATerm t) */

S_Slices S_SlicesFromTerm(ATerm t)
{
  return (S_Slices)t;
}

/*}}}  */
/*{{{  ATerm S_SlicesToTerm(S_Slices arg) */

ATerm S_SlicesToTerm(S_Slices arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*}}}  */
/*{{{  list functions */

int S_getAttributesLength (S_Attributes arg) {
  return ATgetLength((ATermList) arg);
}
S_Attributes S_reverseAttributes(S_Attributes arg) {
  return (S_Attributes) ATreverse((ATermList) arg);
}
S_Attributes S_appendAttributes(S_Attributes arg, S_Attribute elem) {
  return (S_Attributes) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}
S_Attributes S_concatAttributes(S_Attributes arg0, S_Attributes arg1) {
  return (S_Attributes) ATconcat((ATermList) arg0, (ATermList) arg1);
}
S_Attributes S_sliceAttributes(S_Attributes arg, int start, int end) {
  return (S_Attributes) ATgetSlice((ATermList) arg, start, end);
}
S_Attribute S_getAttributesAttributeAt(S_Attributes arg, int index) {
 return (S_Attribute)ATelementAt((ATermList) arg,index);
}
S_Attributes S_replaceAttributesAttributeAt(S_Attributes arg, S_Attribute elem, int index) {
 return (S_Attributes) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}
S_Attributes S_makeAttributes2(S_Attribute elem1, S_Attribute elem2) {
  return (S_Attributes) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}
S_Attributes S_makeAttributes3(S_Attribute elem1, S_Attribute elem2, S_Attribute elem3) {
  return (S_Attributes) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}
S_Attributes S_makeAttributes4(S_Attribute elem1, S_Attribute elem2, S_Attribute elem3, S_Attribute elem4) {
  return (S_Attributes) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}
S_Attributes S_makeAttributes5(S_Attribute elem1, S_Attribute elem2, S_Attribute elem3, S_Attribute elem4, S_Attribute elem5) {
  return (S_Attributes) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}
S_Attributes S_makeAttributes6(S_Attribute elem1, S_Attribute elem2, S_Attribute elem3, S_Attribute elem4, S_Attribute elem5, S_Attribute elem6) {
  return (S_Attributes) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}
int S_getAreasLength (S_Areas arg) {
  return ATgetLength((ATermList) arg);
}
S_Areas S_reverseAreas(S_Areas arg) {
  return (S_Areas) ATreverse((ATermList) arg);
}
S_Areas S_appendAreas(S_Areas arg, S_Area elem) {
  return (S_Areas) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}
S_Areas S_concatAreas(S_Areas arg0, S_Areas arg1) {
  return (S_Areas) ATconcat((ATermList) arg0, (ATermList) arg1);
}
S_Areas S_sliceAreas(S_Areas arg, int start, int end) {
  return (S_Areas) ATgetSlice((ATermList) arg, start, end);
}
S_Area S_getAreasAreaAt(S_Areas arg, int index) {
 return (S_Area)ATelementAt((ATermList) arg,index);
}
S_Areas S_replaceAreasAreaAt(S_Areas arg, S_Area elem, int index) {
 return (S_Areas) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}
S_Areas S_makeAreas2(S_Area elem1, S_Area elem2) {
  return (S_Areas) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}
S_Areas S_makeAreas3(S_Area elem1, S_Area elem2, S_Area elem3) {
  return (S_Areas) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}
S_Areas S_makeAreas4(S_Area elem1, S_Area elem2, S_Area elem3, S_Area elem4) {
  return (S_Areas) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}
S_Areas S_makeAreas5(S_Area elem1, S_Area elem2, S_Area elem3, S_Area elem4, S_Area elem5) {
  return (S_Areas) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}
S_Areas S_makeAreas6(S_Area elem1, S_Area elem2, S_Area elem3, S_Area elem4, S_Area elem5, S_Area elem6) {
  return (S_Areas) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}
int S_getSlicesLength (S_Slices arg) {
  return ATgetLength((ATermList) arg);
}
S_Slices S_reverseSlices(S_Slices arg) {
  return (S_Slices) ATreverse((ATermList) arg);
}
S_Slices S_appendSlices(S_Slices arg, S_Slice elem) {
  return (S_Slices) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}
S_Slices S_concatSlices(S_Slices arg0, S_Slices arg1) {
  return (S_Slices) ATconcat((ATermList) arg0, (ATermList) arg1);
}
S_Slices S_sliceSlices(S_Slices arg, int start, int end) {
  return (S_Slices) ATgetSlice((ATermList) arg, start, end);
}
S_Slice S_getSlicesSliceAt(S_Slices arg, int index) {
 return (S_Slice)ATelementAt((ATermList) arg,index);
}
S_Slices S_replaceSlicesSliceAt(S_Slices arg, S_Slice elem, int index) {
 return (S_Slices) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}
S_Slices S_makeSlices2(S_Slice elem1, S_Slice elem2) {
  return (S_Slices) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}
S_Slices S_makeSlices3(S_Slice elem1, S_Slice elem2, S_Slice elem3) {
  return (S_Slices) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}
S_Slices S_makeSlices4(S_Slice elem1, S_Slice elem2, S_Slice elem3, S_Slice elem4) {
  return (S_Slices) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}
S_Slices S_makeSlices5(S_Slice elem1, S_Slice elem2, S_Slice elem3, S_Slice elem4, S_Slice elem5) {
  return (S_Slices) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}
S_Slices S_makeSlices6(S_Slice elem1, S_Slice elem2, S_Slice elem3, S_Slice elem4, S_Slice elem5, S_Slice elem6) {
  return (S_Slices) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}

/*}}}  */
/*{{{  constructors */

/*{{{  S_CategoryName S_makeCategoryNameFocus(void) */

S_CategoryName S_makeCategoryNameFocus(void)
{
  return (S_CategoryName)(ATerm)ATmakeAppl0(S_afun0);
}

/*}}}  */
/*{{{  S_CategoryName S_makeCategoryNameSelection(void) */

S_CategoryName S_makeCategoryNameSelection(void)
{
  return (S_CategoryName)(ATerm)ATmakeAppl0(S_afun1);
}

/*}}}  */
/*{{{  S_CategoryName S_makeCategoryNameNormal(void) */

S_CategoryName S_makeCategoryNameNormal(void)
{
  return (S_CategoryName)(ATerm)ATmakeAppl0(S_afun2);
}

/*}}}  */
/*{{{  S_CategoryName S_makeCategoryNameExtern(const char* name) */

S_CategoryName S_makeCategoryNameExtern(const char* name)
{
  return (S_CategoryName)(ATerm)ATmakeAppl1(S_afun3, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(name, 0, ATtrue)));
}

/*}}}  */
/*{{{  S_Category S_makeCategoryDefault(S_CategoryName name, S_Attributes attributes) */

S_Category S_makeCategoryDefault(S_CategoryName name, S_Attributes attributes)
{
  return (S_Category)(ATerm)ATmakeAppl2(S_afun4, (ATerm) name, (ATerm) attributes);
}

/*}}}  */
/*{{{  S_Attributes S_makeAttributesEmpty(void) */

S_Attributes S_makeAttributesEmpty(void)
{
  return (S_Attributes)(ATerm)ATempty;
}

/*}}}  */
/*{{{  S_Attributes S_makeAttributesSingle(S_Attribute head) */

S_Attributes S_makeAttributesSingle(S_Attribute head)
{
  return (S_Attributes)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  S_Attributes S_makeAttributesMany(S_Attribute head, S_Attributes tail) */

S_Attributes S_makeAttributesMany(S_Attribute head, S_Attributes tail)
{
  return (S_Attributes)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/*}}}  */
/*{{{  S_Attribute S_makeAttributeForegroundColor(S_Color color) */

S_Attribute S_makeAttributeForegroundColor(S_Color color)
{
  return (S_Attribute)(ATerm)ATmakeAppl1(S_afun5, (ATerm) color);
}

/*}}}  */
/*{{{  S_Attribute S_makeAttributeBackgroundColor(S_Color color) */

S_Attribute S_makeAttributeBackgroundColor(S_Color color)
{
  return (S_Attribute)(ATerm)ATmakeAppl1(S_afun6, (ATerm) color);
}

/*}}}  */
/*{{{  S_Attribute S_makeAttributeStyle(S_Style style) */

S_Attribute S_makeAttributeStyle(S_Style style)
{
  return (S_Attribute)(ATerm)ATmakeAppl1(S_afun7, (ATerm) style);
}

/*}}}  */
/*{{{  S_Attribute S_makeAttributeFont(const char* name) */

S_Attribute S_makeAttributeFont(const char* name)
{
  return (S_Attribute)(ATerm)ATmakeAppl1(S_afun8, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(name, 0, ATtrue)));
}

/*}}}  */
/*{{{  S_Attribute S_makeAttributeSize(int points) */

S_Attribute S_makeAttributeSize(int points)
{
  return (S_Attribute)(ATerm)ATmakeAppl1(S_afun9, (ATerm) (ATerm) ATmakeInt(points));
}

/*}}}  */
/*{{{  S_Color S_makeColorRgb(int red, int green, int blue) */

S_Color S_makeColorRgb(int red, int green, int blue)
{
  return (S_Color)(ATerm)ATmakeAppl3(S_afun10, (ATerm) (ATerm) ATmakeInt(red), (ATerm) (ATerm) ATmakeInt(green), (ATerm) (ATerm) ATmakeInt(blue));
}

/*}}}  */
/*{{{  S_Style S_makeStyleBold(void) */

S_Style S_makeStyleBold(void)
{
  return (S_Style)(ATerm)ATmakeAppl0(S_afun11);
}

/*}}}  */
/*{{{  S_Style S_makeStyleItalics(void) */

S_Style S_makeStyleItalics(void)
{
  return (S_Style)(ATerm)ATmakeAppl0(S_afun12);
}

/*}}}  */
/*{{{  S_Style S_makeStyleUnderlined(void) */

S_Style S_makeStyleUnderlined(void)
{
  return (S_Style)(ATerm)ATmakeAppl0(S_afun13);
}

/*}}}  */
/*{{{  S_Slice S_makeSliceDefault(S_CategoryName category, S_Areas areas) */

S_Slice S_makeSliceDefault(S_CategoryName category, S_Areas areas)
{
  return (S_Slice)(ATerm)ATmakeAppl2(S_afun14, (ATerm) category, (ATerm) areas);
}

/*}}}  */
/*{{{  S_Areas S_makeAreasEmpty(void) */

S_Areas S_makeAreasEmpty(void)
{
  return (S_Areas)(ATerm)ATempty;
}

/*}}}  */
/*{{{  S_Areas S_makeAreasSingle(S_Area head) */

S_Areas S_makeAreasSingle(S_Area head)
{
  return (S_Areas)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  S_Areas S_makeAreasMany(S_Area head, S_Areas tail) */

S_Areas S_makeAreasMany(S_Area head, S_Areas tail)
{
  return (S_Areas)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/*}}}  */
/*{{{  S_Slices S_makeSlicesEmpty(void) */

S_Slices S_makeSlicesEmpty(void)
{
  return (S_Slices)(ATerm)ATempty;
}

/*}}}  */
/*{{{  S_Slices S_makeSlicesSingle(S_Slice head) */

S_Slices S_makeSlicesSingle(S_Slice head)
{
  return (S_Slices)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  S_Slices S_makeSlicesMany(S_Slice head, S_Slices tail) */

S_Slices S_makeSlicesMany(S_Slice head, S_Slices tail)
{
  return (S_Slices)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool S_isEqualCategoryName(S_CategoryName arg0, S_CategoryName arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool S_isEqualCategory(S_Category arg0, S_Category arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool S_isEqualAttributes(S_Attributes arg0, S_Attributes arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool S_isEqualAttribute(S_Attribute arg0, S_Attribute arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool S_isEqualColor(S_Color arg0, S_Color arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool S_isEqualStyle(S_Style arg0, S_Style arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool S_isEqualSlice(S_Slice arg0, S_Slice arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool S_isEqualAreas(S_Areas arg0, S_Areas arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool S_isEqualSlices(S_Slices arg0, S_Slices arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  S_CategoryName accessors */

/*{{{  ATbool S_isValidCategoryName(S_CategoryName arg) */

ATbool S_isValidCategoryName(S_CategoryName arg)
{
  if (S_isCategoryNameFocus(arg)) {
    return ATtrue;
  }
  else if (S_isCategoryNameSelection(arg)) {
    return ATtrue;
  }
  else if (S_isCategoryNameNormal(arg)) {
    return ATtrue;
  }
  else if (S_isCategoryNameExtern(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool S_isCategoryNameFocus(S_CategoryName arg) */

inline ATbool S_isCategoryNameFocus(S_CategoryName arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, S_patternCategoryNameFocus);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool S_isCategoryNameSelection(S_CategoryName arg) */

inline ATbool S_isCategoryNameSelection(S_CategoryName arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, S_patternCategoryNameSelection);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool S_isCategoryNameNormal(S_CategoryName arg) */

inline ATbool S_isCategoryNameNormal(S_CategoryName arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, S_patternCategoryNameNormal);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool S_isCategoryNameExtern(S_CategoryName arg) */

inline ATbool S_isCategoryNameExtern(S_CategoryName arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, S_patternCategoryNameExtern, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool S_hasCategoryNameName(S_CategoryName arg) */

ATbool S_hasCategoryNameName(S_CategoryName arg)
{
  if (S_isCategoryNameExtern(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* S_getCategoryNameName(S_CategoryName arg) */

char* S_getCategoryNameName(S_CategoryName arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  S_CategoryName S_setCategoryNameName(S_CategoryName arg, const char* name) */

S_CategoryName S_setCategoryNameName(S_CategoryName arg, const char* name)
{
  if (S_isCategoryNameExtern(arg)) {
    return (S_CategoryName)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(name, 0, ATtrue))), 0);
  }

  ATabort("CategoryName has no Name: %t\n", arg);
  return (S_CategoryName)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  S_Category accessors */

/*{{{  ATbool S_isValidCategory(S_Category arg) */

ATbool S_isValidCategory(S_Category arg)
{
  if (S_isCategoryDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool S_isCategoryDefault(S_Category arg) */

inline ATbool S_isCategoryDefault(S_Category arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, S_patternCategoryDefault, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool S_hasCategoryName(S_Category arg) */

ATbool S_hasCategoryName(S_Category arg)
{
  if (S_isCategoryDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool S_hasCategoryAttributes(S_Category arg) */

ATbool S_hasCategoryAttributes(S_Category arg)
{
  if (S_isCategoryDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  S_CategoryName S_getCategoryName(S_Category arg) */

S_CategoryName S_getCategoryName(S_Category arg)
{
  
    return (S_CategoryName)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  S_Attributes S_getCategoryAttributes(S_Category arg) */

S_Attributes S_getCategoryAttributes(S_Category arg)
{
  
    return (S_Attributes)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  S_Category S_setCategoryName(S_Category arg, S_CategoryName name) */

S_Category S_setCategoryName(S_Category arg, S_CategoryName name)
{
  if (S_isCategoryDefault(arg)) {
    return (S_Category)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) name), 0);
  }

  ATabort("Category has no Name: %t\n", arg);
  return (S_Category)NULL;
}

/*}}}  */
/*{{{  S_Category S_setCategoryAttributes(S_Category arg, S_Attributes attributes) */

S_Category S_setCategoryAttributes(S_Category arg, S_Attributes attributes)
{
  if (S_isCategoryDefault(arg)) {
    return (S_Category)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) attributes), 1);
  }

  ATabort("Category has no Attributes: %t\n", arg);
  return (S_Category)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  S_Attributes accessors */

/*{{{  ATbool S_isValidAttributes(S_Attributes arg) */

ATbool S_isValidAttributes(S_Attributes arg)
{
  if (S_isAttributesEmpty(arg)) {
    return ATtrue;
  }
  else if (S_isAttributesSingle(arg)) {
    return ATtrue;
  }
  else if (S_isAttributesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool S_isAttributesEmpty(S_Attributes arg) */

inline ATbool S_isAttributesEmpty(S_Attributes arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, S_patternAttributesEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool S_isAttributesSingle(S_Attributes arg) */

inline ATbool S_isAttributesSingle(S_Attributes arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, S_patternAttributesSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool S_isAttributesMany(S_Attributes arg) */

inline ATbool S_isAttributesMany(S_Attributes arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, S_patternAttributesMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool S_hasAttributesHead(S_Attributes arg) */

ATbool S_hasAttributesHead(S_Attributes arg)
{
  if (S_isAttributesSingle(arg)) {
    return ATtrue;
  }
  else if (S_isAttributesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool S_hasAttributesTail(S_Attributes arg) */

ATbool S_hasAttributesTail(S_Attributes arg)
{
  if (S_isAttributesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  S_Attribute S_getAttributesHead(S_Attributes arg) */

S_Attribute S_getAttributesHead(S_Attributes arg)
{
  if (S_isAttributesSingle(arg)) {
    return (S_Attribute)ATgetFirst((ATermList)arg);
  }
  else 
    return (S_Attribute)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  S_Attributes S_getAttributesTail(S_Attributes arg) */

S_Attributes S_getAttributesTail(S_Attributes arg)
{
  
    return (S_Attributes)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  S_Attributes S_setAttributesHead(S_Attributes arg, S_Attribute head) */

S_Attributes S_setAttributesHead(S_Attributes arg, S_Attribute head)
{
  if (S_isAttributesSingle(arg)) {
    return (S_Attributes)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (S_isAttributesMany(arg)) {
    return (S_Attributes)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("Attributes has no Head: %t\n", arg);
  return (S_Attributes)NULL;
}

/*}}}  */
/*{{{  S_Attributes S_setAttributesTail(S_Attributes arg, S_Attributes tail) */

S_Attributes S_setAttributesTail(S_Attributes arg, S_Attributes tail)
{
  if (S_isAttributesMany(arg)) {
    return (S_Attributes)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("Attributes has no Tail: %t\n", arg);
  return (S_Attributes)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  S_Attribute accessors */

/*{{{  ATbool S_isValidAttribute(S_Attribute arg) */

ATbool S_isValidAttribute(S_Attribute arg)
{
  if (S_isAttributeForegroundColor(arg)) {
    return ATtrue;
  }
  else if (S_isAttributeBackgroundColor(arg)) {
    return ATtrue;
  }
  else if (S_isAttributeStyle(arg)) {
    return ATtrue;
  }
  else if (S_isAttributeFont(arg)) {
    return ATtrue;
  }
  else if (S_isAttributeSize(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool S_isAttributeForegroundColor(S_Attribute arg) */

inline ATbool S_isAttributeForegroundColor(S_Attribute arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, S_patternAttributeForegroundColor, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool S_isAttributeBackgroundColor(S_Attribute arg) */

inline ATbool S_isAttributeBackgroundColor(S_Attribute arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, S_patternAttributeBackgroundColor, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool S_isAttributeStyle(S_Attribute arg) */

inline ATbool S_isAttributeStyle(S_Attribute arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, S_patternAttributeStyle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool S_isAttributeFont(S_Attribute arg) */

inline ATbool S_isAttributeFont(S_Attribute arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, S_patternAttributeFont, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool S_isAttributeSize(S_Attribute arg) */

inline ATbool S_isAttributeSize(S_Attribute arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, S_patternAttributeSize, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool S_hasAttributeColor(S_Attribute arg) */

ATbool S_hasAttributeColor(S_Attribute arg)
{
  if (S_isAttributeForegroundColor(arg)) {
    return ATtrue;
  }
  else if (S_isAttributeBackgroundColor(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool S_hasAttributeStyle(S_Attribute arg) */

ATbool S_hasAttributeStyle(S_Attribute arg)
{
  if (S_isAttributeStyle(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool S_hasAttributeName(S_Attribute arg) */

ATbool S_hasAttributeName(S_Attribute arg)
{
  if (S_isAttributeFont(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool S_hasAttributePoints(S_Attribute arg) */

ATbool S_hasAttributePoints(S_Attribute arg)
{
  if (S_isAttributeSize(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  S_Color S_getAttributeColor(S_Attribute arg) */

S_Color S_getAttributeColor(S_Attribute arg)
{
  if (S_isAttributeForegroundColor(arg)) {
    return (S_Color)ATgetArgument((ATermAppl)arg, 0);
  }
  else 
    return (S_Color)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  S_Style S_getAttributeStyle(S_Attribute arg) */

S_Style S_getAttributeStyle(S_Attribute arg)
{
  
    return (S_Style)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  char* S_getAttributeName(S_Attribute arg) */

char* S_getAttributeName(S_Attribute arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  int S_getAttributePoints(S_Attribute arg) */

int S_getAttributePoints(S_Attribute arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

/*}}}  */
/*{{{  S_Attribute S_setAttributeColor(S_Attribute arg, S_Color color) */

S_Attribute S_setAttributeColor(S_Attribute arg, S_Color color)
{
  if (S_isAttributeForegroundColor(arg)) {
    return (S_Attribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) color), 0);
  }
  else if (S_isAttributeBackgroundColor(arg)) {
    return (S_Attribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) color), 0);
  }

  ATabort("Attribute has no Color: %t\n", arg);
  return (S_Attribute)NULL;
}

/*}}}  */
/*{{{  S_Attribute S_setAttributeStyle(S_Attribute arg, S_Style style) */

S_Attribute S_setAttributeStyle(S_Attribute arg, S_Style style)
{
  if (S_isAttributeStyle(arg)) {
    return (S_Attribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) style), 0);
  }

  ATabort("Attribute has no Style: %t\n", arg);
  return (S_Attribute)NULL;
}

/*}}}  */
/*{{{  S_Attribute S_setAttributeName(S_Attribute arg, const char* name) */

S_Attribute S_setAttributeName(S_Attribute arg, const char* name)
{
  if (S_isAttributeFont(arg)) {
    return (S_Attribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(name, 0, ATtrue))), 0);
  }

  ATabort("Attribute has no Name: %t\n", arg);
  return (S_Attribute)NULL;
}

/*}}}  */
/*{{{  S_Attribute S_setAttributePoints(S_Attribute arg, int points) */

S_Attribute S_setAttributePoints(S_Attribute arg, int points)
{
  if (S_isAttributeSize(arg)) {
    return (S_Attribute)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(points)), 0);
  }

  ATabort("Attribute has no Points: %t\n", arg);
  return (S_Attribute)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  S_Color accessors */

/*{{{  ATbool S_isValidColor(S_Color arg) */

ATbool S_isValidColor(S_Color arg)
{
  if (S_isColorRgb(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool S_isColorRgb(S_Color arg) */

inline ATbool S_isColorRgb(S_Color arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, S_patternColorRgb, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool S_hasColorRed(S_Color arg) */

ATbool S_hasColorRed(S_Color arg)
{
  if (S_isColorRgb(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool S_hasColorGreen(S_Color arg) */

ATbool S_hasColorGreen(S_Color arg)
{
  if (S_isColorRgb(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool S_hasColorBlue(S_Color arg) */

ATbool S_hasColorBlue(S_Color arg)
{
  if (S_isColorRgb(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int S_getColorRed(S_Color arg) */

int S_getColorRed(S_Color arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

/*}}}  */
/*{{{  int S_getColorGreen(S_Color arg) */

int S_getColorGreen(S_Color arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  int S_getColorBlue(S_Color arg) */

int S_getColorBlue(S_Color arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 2));
}

/*}}}  */
/*{{{  S_Color S_setColorRed(S_Color arg, int red) */

S_Color S_setColorRed(S_Color arg, int red)
{
  if (S_isColorRgb(arg)) {
    return (S_Color)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(red)), 0);
  }

  ATabort("Color has no Red: %t\n", arg);
  return (S_Color)NULL;
}

/*}}}  */
/*{{{  S_Color S_setColorGreen(S_Color arg, int green) */

S_Color S_setColorGreen(S_Color arg, int green)
{
  if (S_isColorRgb(arg)) {
    return (S_Color)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(green)), 1);
  }

  ATabort("Color has no Green: %t\n", arg);
  return (S_Color)NULL;
}

/*}}}  */
/*{{{  S_Color S_setColorBlue(S_Color arg, int blue) */

S_Color S_setColorBlue(S_Color arg, int blue)
{
  if (S_isColorRgb(arg)) {
    return (S_Color)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(blue)), 2);
  }

  ATabort("Color has no Blue: %t\n", arg);
  return (S_Color)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  S_Style accessors */

/*{{{  ATbool S_isValidStyle(S_Style arg) */

ATbool S_isValidStyle(S_Style arg)
{
  if (S_isStyleBold(arg)) {
    return ATtrue;
  }
  else if (S_isStyleItalics(arg)) {
    return ATtrue;
  }
  else if (S_isStyleUnderlined(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool S_isStyleBold(S_Style arg) */

inline ATbool S_isStyleBold(S_Style arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, S_patternStyleBold);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool S_isStyleItalics(S_Style arg) */

inline ATbool S_isStyleItalics(S_Style arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, S_patternStyleItalics);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool S_isStyleUnderlined(S_Style arg) */

inline ATbool S_isStyleUnderlined(S_Style arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, S_patternStyleUnderlined);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */

/*}}}  */
/*{{{  S_Slice accessors */

/*{{{  ATbool S_isValidSlice(S_Slice arg) */

ATbool S_isValidSlice(S_Slice arg)
{
  if (S_isSliceDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool S_isSliceDefault(S_Slice arg) */

inline ATbool S_isSliceDefault(S_Slice arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, S_patternSliceDefault, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool S_hasSliceCategory(S_Slice arg) */

ATbool S_hasSliceCategory(S_Slice arg)
{
  if (S_isSliceDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool S_hasSliceAreas(S_Slice arg) */

ATbool S_hasSliceAreas(S_Slice arg)
{
  if (S_isSliceDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  S_CategoryName S_getSliceCategory(S_Slice arg) */

S_CategoryName S_getSliceCategory(S_Slice arg)
{
  
    return (S_CategoryName)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  S_Areas S_getSliceAreas(S_Slice arg) */

S_Areas S_getSliceAreas(S_Slice arg)
{
  
    return (S_Areas)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  S_Slice S_setSliceCategory(S_Slice arg, S_CategoryName category) */

S_Slice S_setSliceCategory(S_Slice arg, S_CategoryName category)
{
  if (S_isSliceDefault(arg)) {
    return (S_Slice)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) category), 0);
  }

  ATabort("Slice has no Category: %t\n", arg);
  return (S_Slice)NULL;
}

/*}}}  */
/*{{{  S_Slice S_setSliceAreas(S_Slice arg, S_Areas areas) */

S_Slice S_setSliceAreas(S_Slice arg, S_Areas areas)
{
  if (S_isSliceDefault(arg)) {
    return (S_Slice)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) areas), 1);
  }

  ATabort("Slice has no Areas: %t\n", arg);
  return (S_Slice)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  S_Areas accessors */

/*{{{  ATbool S_isValidAreas(S_Areas arg) */

ATbool S_isValidAreas(S_Areas arg)
{
  if (S_isAreasEmpty(arg)) {
    return ATtrue;
  }
  else if (S_isAreasSingle(arg)) {
    return ATtrue;
  }
  else if (S_isAreasMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool S_isAreasEmpty(S_Areas arg) */

inline ATbool S_isAreasEmpty(S_Areas arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, S_patternAreasEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool S_isAreasSingle(S_Areas arg) */

inline ATbool S_isAreasSingle(S_Areas arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, S_patternAreasSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool S_isAreasMany(S_Areas arg) */

inline ATbool S_isAreasMany(S_Areas arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, S_patternAreasMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool S_hasAreasHead(S_Areas arg) */

ATbool S_hasAreasHead(S_Areas arg)
{
  if (S_isAreasSingle(arg)) {
    return ATtrue;
  }
  else if (S_isAreasMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool S_hasAreasTail(S_Areas arg) */

ATbool S_hasAreasTail(S_Areas arg)
{
  if (S_isAreasMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  S_Area S_getAreasHead(S_Areas arg) */

S_Area S_getAreasHead(S_Areas arg)
{
  if (S_isAreasSingle(arg)) {
    return (S_Area)ATgetFirst((ATermList)arg);
  }
  else 
    return (S_Area)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  S_Areas S_getAreasTail(S_Areas arg) */

S_Areas S_getAreasTail(S_Areas arg)
{
  
    return (S_Areas)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  S_Areas S_setAreasHead(S_Areas arg, S_Area head) */

S_Areas S_setAreasHead(S_Areas arg, S_Area head)
{
  if (S_isAreasSingle(arg)) {
    return (S_Areas)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (S_isAreasMany(arg)) {
    return (S_Areas)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("Areas has no Head: %t\n", arg);
  return (S_Areas)NULL;
}

/*}}}  */
/*{{{  S_Areas S_setAreasTail(S_Areas arg, S_Areas tail) */

S_Areas S_setAreasTail(S_Areas arg, S_Areas tail)
{
  if (S_isAreasMany(arg)) {
    return (S_Areas)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("Areas has no Tail: %t\n", arg);
  return (S_Areas)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  S_Slices accessors */

/*{{{  ATbool S_isValidSlices(S_Slices arg) */

ATbool S_isValidSlices(S_Slices arg)
{
  if (S_isSlicesEmpty(arg)) {
    return ATtrue;
  }
  else if (S_isSlicesSingle(arg)) {
    return ATtrue;
  }
  else if (S_isSlicesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool S_isSlicesEmpty(S_Slices arg) */

inline ATbool S_isSlicesEmpty(S_Slices arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, S_patternSlicesEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool S_isSlicesSingle(S_Slices arg) */

inline ATbool S_isSlicesSingle(S_Slices arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, S_patternSlicesSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool S_isSlicesMany(S_Slices arg) */

inline ATbool S_isSlicesMany(S_Slices arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, S_patternSlicesMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool S_hasSlicesHead(S_Slices arg) */

ATbool S_hasSlicesHead(S_Slices arg)
{
  if (S_isSlicesSingle(arg)) {
    return ATtrue;
  }
  else if (S_isSlicesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool S_hasSlicesTail(S_Slices arg) */

ATbool S_hasSlicesTail(S_Slices arg)
{
  if (S_isSlicesMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  S_Slice S_getSlicesHead(S_Slices arg) */

S_Slice S_getSlicesHead(S_Slices arg)
{
  if (S_isSlicesSingle(arg)) {
    return (S_Slice)ATgetFirst((ATermList)arg);
  }
  else 
    return (S_Slice)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  S_Slices S_getSlicesTail(S_Slices arg) */

S_Slices S_getSlicesTail(S_Slices arg)
{
  
    return (S_Slices)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  S_Slices S_setSlicesHead(S_Slices arg, S_Slice head) */

S_Slices S_setSlicesHead(S_Slices arg, S_Slice head)
{
  if (S_isSlicesSingle(arg)) {
    return (S_Slices)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (S_isSlicesMany(arg)) {
    return (S_Slices)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("Slices has no Head: %t\n", arg);
  return (S_Slices)NULL;
}

/*}}}  */
/*{{{  S_Slices S_setSlicesTail(S_Slices arg, S_Slices tail) */

S_Slices S_setSlicesTail(S_Slices arg, S_Slices tail)
{
  if (S_isSlicesMany(arg)) {
    return (S_Slices)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("Slices has no Tail: %t\n", arg);
  return (S_Slices)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  S_CategoryName S_visitCategoryName(S_CategoryName arg, char* (*acceptName)(char*)) */

S_CategoryName S_visitCategoryName(S_CategoryName arg, char* (*acceptName)(char*))
{
  if (S_isCategoryNameFocus(arg)) {
    return S_makeCategoryNameFocus();
  }
  if (S_isCategoryNameSelection(arg)) {
    return S_makeCategoryNameSelection();
  }
  if (S_isCategoryNameNormal(arg)) {
    return S_makeCategoryNameNormal();
  }
  if (S_isCategoryNameExtern(arg)) {
    return S_makeCategoryNameExtern(
        acceptName ? acceptName(S_getCategoryNameName(arg)) : S_getCategoryNameName(arg));
  }
  ATabort("not a CategoryName: %t\n", arg);
  return (S_CategoryName)NULL;
}

/*}}}  */
/*{{{  S_Category S_visitCategory(S_Category arg, S_CategoryName (*acceptName)(S_CategoryName), S_Attributes (*acceptAttributes)(S_Attributes)) */

S_Category S_visitCategory(S_Category arg, S_CategoryName (*acceptName)(S_CategoryName), S_Attributes (*acceptAttributes)(S_Attributes))
{
  if (S_isCategoryDefault(arg)) {
    return S_makeCategoryDefault(
        acceptName ? acceptName(S_getCategoryName(arg)) : S_getCategoryName(arg),
        acceptAttributes ? acceptAttributes(S_getCategoryAttributes(arg)) : S_getCategoryAttributes(arg));
  }
  ATabort("not a Category: %t\n", arg);
  return (S_Category)NULL;
}

/*}}}  */
/*{{{  S_Attributes S_visitAttributes(S_Attributes arg, S_Attribute (*acceptHead)(S_Attribute)) */

S_Attributes S_visitAttributes(S_Attributes arg, S_Attribute (*acceptHead)(S_Attribute))
{
  if (S_isAttributesEmpty(arg)) {
    return S_makeAttributesEmpty();
  }
  if (S_isAttributesSingle(arg)) {
    return S_makeAttributesSingle(
        acceptHead ? acceptHead(S_getAttributesHead(arg)) : S_getAttributesHead(arg));
  }
  if (S_isAttributesMany(arg)) {
    return S_makeAttributesMany(
        acceptHead ? acceptHead(S_getAttributesHead(arg)) : S_getAttributesHead(arg),
        S_visitAttributes(S_getAttributesTail(arg), acceptHead));
  }
  ATabort("not a Attributes: %t\n", arg);
  return (S_Attributes)NULL;
}

/*}}}  */
/*{{{  S_Attribute S_visitAttribute(S_Attribute arg, S_Color (*acceptColor)(S_Color), S_Style (*acceptStyle)(S_Style), char* (*acceptName)(char*), int (*acceptPoints)(int)) */

S_Attribute S_visitAttribute(S_Attribute arg, S_Color (*acceptColor)(S_Color), S_Style (*acceptStyle)(S_Style), char* (*acceptName)(char*), int (*acceptPoints)(int))
{
  if (S_isAttributeForegroundColor(arg)) {
    return S_makeAttributeForegroundColor(
        acceptColor ? acceptColor(S_getAttributeColor(arg)) : S_getAttributeColor(arg));
  }
  if (S_isAttributeBackgroundColor(arg)) {
    return S_makeAttributeBackgroundColor(
        acceptColor ? acceptColor(S_getAttributeColor(arg)) : S_getAttributeColor(arg));
  }
  if (S_isAttributeStyle(arg)) {
    return S_makeAttributeStyle(
        acceptStyle ? acceptStyle(S_getAttributeStyle(arg)) : S_getAttributeStyle(arg));
  }
  if (S_isAttributeFont(arg)) {
    return S_makeAttributeFont(
        acceptName ? acceptName(S_getAttributeName(arg)) : S_getAttributeName(arg));
  }
  if (S_isAttributeSize(arg)) {
    return S_makeAttributeSize(
        acceptPoints ? acceptPoints(S_getAttributePoints(arg)) : S_getAttributePoints(arg));
  }
  ATabort("not a Attribute: %t\n", arg);
  return (S_Attribute)NULL;
}

/*}}}  */
/*{{{  S_Color S_visitColor(S_Color arg, int (*acceptRed)(int), int (*acceptGreen)(int), int (*acceptBlue)(int)) */

S_Color S_visitColor(S_Color arg, int (*acceptRed)(int), int (*acceptGreen)(int), int (*acceptBlue)(int))
{
  if (S_isColorRgb(arg)) {
    return S_makeColorRgb(
        acceptRed ? acceptRed(S_getColorRed(arg)) : S_getColorRed(arg),
        acceptGreen ? acceptGreen(S_getColorGreen(arg)) : S_getColorGreen(arg),
        acceptBlue ? acceptBlue(S_getColorBlue(arg)) : S_getColorBlue(arg));
  }
  ATabort("not a Color: %t\n", arg);
  return (S_Color)NULL;
}

/*}}}  */
/*{{{  S_Style S_visitStyle(S_Style arg) */

S_Style S_visitStyle(S_Style arg)
{
  if (S_isStyleBold(arg)) {
    return S_makeStyleBold();
  }
  if (S_isStyleItalics(arg)) {
    return S_makeStyleItalics();
  }
  if (S_isStyleUnderlined(arg)) {
    return S_makeStyleUnderlined();
  }
  ATabort("not a Style: %t\n", arg);
  return (S_Style)NULL;
}

/*}}}  */
/*{{{  S_Slice S_visitSlice(S_Slice arg, S_CategoryName (*acceptCategory)(S_CategoryName), S_Areas (*acceptAreas)(S_Areas)) */

S_Slice S_visitSlice(S_Slice arg, S_CategoryName (*acceptCategory)(S_CategoryName), S_Areas (*acceptAreas)(S_Areas))
{
  if (S_isSliceDefault(arg)) {
    return S_makeSliceDefault(
        acceptCategory ? acceptCategory(S_getSliceCategory(arg)) : S_getSliceCategory(arg),
        acceptAreas ? acceptAreas(S_getSliceAreas(arg)) : S_getSliceAreas(arg));
  }
  ATabort("not a Slice: %t\n", arg);
  return (S_Slice)NULL;
}

/*}}}  */
/*{{{  S_Areas S_visitAreas(S_Areas arg, S_Area (*acceptHead)(S_Area)) */

S_Areas S_visitAreas(S_Areas arg, S_Area (*acceptHead)(S_Area))
{
  if (S_isAreasEmpty(arg)) {
    return S_makeAreasEmpty();
  }
  if (S_isAreasSingle(arg)) {
    return S_makeAreasSingle(
        acceptHead ? acceptHead(S_getAreasHead(arg)) : S_getAreasHead(arg));
  }
  if (S_isAreasMany(arg)) {
    return S_makeAreasMany(
        acceptHead ? acceptHead(S_getAreasHead(arg)) : S_getAreasHead(arg),
        S_visitAreas(S_getAreasTail(arg), acceptHead));
  }
  ATabort("not a Areas: %t\n", arg);
  return (S_Areas)NULL;
}

/*}}}  */
/*{{{  S_Slices S_visitSlices(S_Slices arg, S_Slice (*acceptHead)(S_Slice)) */

S_Slices S_visitSlices(S_Slices arg, S_Slice (*acceptHead)(S_Slice))
{
  if (S_isSlicesEmpty(arg)) {
    return S_makeSlicesEmpty();
  }
  if (S_isSlicesSingle(arg)) {
    return S_makeSlicesSingle(
        acceptHead ? acceptHead(S_getSlicesHead(arg)) : S_getSlicesHead(arg));
  }
  if (S_isSlicesMany(arg)) {
    return S_makeSlicesMany(
        acceptHead ? acceptHead(S_getSlicesHead(arg)) : S_getSlicesHead(arg),
        S_visitSlices(S_getSlicesTail(arg), acceptHead));
  }
  ATabort("not a Slices: %t\n", arg);
  return (S_Slices)NULL;
}

/*}}}  */

/*}}}  */
