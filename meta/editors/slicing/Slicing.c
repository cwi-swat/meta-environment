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

typedef struct ATerm _S_Slice;
typedef struct ATerm _S_Slices;
typedef struct ATerm _S_Areas;

/*}}}  */

/*{{{  void S_initSlicingApi(void) */

void S_initSlicingApi(void)
{
  init_Slicing_dict();
}

/*}}}  */

/*{{{  protect functions */

void S_protectSlice(S_Slice *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void S_protectSlices(S_Slices *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void S_protectAreas(S_Areas *arg)
{
  ATprotect((ATerm*)((void*) arg));
}


/*}}}  */
/*{{{  term conversion functions */

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

/*}}}  */
/*{{{  list functions */

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

/*}}}  */
/*{{{  constructors */

/*{{{  S_Slice S_makeSliceDefault(const char* category, S_Areas areas) */

S_Slice S_makeSliceDefault(const char* category, S_Areas areas)
{
  return (S_Slice)(ATerm)ATmakeAppl2(S_afun0, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(category, 0, ATtrue)), (ATerm) areas);
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

/*}}}  */
/*{{{  equality functions */

ATbool S_isEqualSlice(S_Slice arg0, S_Slice arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool S_isEqualSlices(S_Slices arg0, S_Slices arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool S_isEqualAreas(S_Areas arg0, S_Areas arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

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
/*{{{  char* S_getSliceCategory(S_Slice arg) */

char* S_getSliceCategory(S_Slice arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  S_Areas S_getSliceAreas(S_Slice arg) */

S_Areas S_getSliceAreas(S_Slice arg)
{
  
    return (S_Areas)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  S_Slice S_setSliceCategory(S_Slice arg, const char* category) */

S_Slice S_setSliceCategory(S_Slice arg, const char* category)
{
  if (S_isSliceDefault(arg)) {
    return (S_Slice)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(category, 0, ATtrue))), 0);
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
/*{{{  sort visitors */

/*{{{  S_Slice S_visitSlice(S_Slice arg, char* (*acceptCategory)(char*), S_Areas (*acceptAreas)(S_Areas)) */

S_Slice S_visitSlice(S_Slice arg, char* (*acceptCategory)(char*), S_Areas (*acceptAreas)(S_Areas))
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

/*}}}  */
