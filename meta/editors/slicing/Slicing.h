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

typedef struct _S_Slice *S_Slice;
typedef struct _S_Slices *S_Slices;
typedef struct _S_Areas *S_Areas;

/*}}}  */

void S_initSlicingApi(void);

/*{{{  protect functions */

void S_protectSlice(S_Slice *arg);
void S_protectSlices(S_Slices *arg);
void S_protectAreas(S_Areas *arg);

/*}}}  */
/*{{{  term conversion functions */

S_Slice S_SliceFromTerm(ATerm t);
ATerm S_SliceToTerm(S_Slice arg);
S_Slices S_SlicesFromTerm(ATerm t);
ATerm S_SlicesToTerm(S_Slices arg);
S_Areas S_AreasFromTerm(ATerm t);
ATerm S_AreasToTerm(S_Areas arg);

/*}}}  */
/*{{{  list functions */

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

/*}}}  */
/*{{{  constructors */

S_Slice S_makeSliceDefault(const char* category, S_Areas areas);
S_Slices S_makeSlicesEmpty(void);
S_Slices S_makeSlicesSingle(S_Slice head);
S_Slices S_makeSlicesMany(S_Slice head, S_Slices tail);
S_Areas S_makeAreasEmpty(void);
S_Areas S_makeAreasSingle(S_Area head);
S_Areas S_makeAreasMany(S_Area head, S_Areas tail);

/*}}}  */
/*{{{  equality functions */

ATbool S_isEqualSlice(S_Slice arg0, S_Slice arg1);
ATbool S_isEqualSlices(S_Slices arg0, S_Slices arg1);
ATbool S_isEqualAreas(S_Areas arg0, S_Areas arg1);

/*}}}  */
/*{{{  S_Slice accessors */

ATbool S_isValidSlice(S_Slice arg);
inline ATbool S_isSliceDefault(S_Slice arg);
ATbool S_hasSliceCategory(S_Slice arg);
ATbool S_hasSliceAreas(S_Slice arg);
char* S_getSliceCategory(S_Slice arg);
S_Areas S_getSliceAreas(S_Slice arg);
S_Slice S_setSliceCategory(S_Slice arg, const char* category);
S_Slice S_setSliceAreas(S_Slice arg, S_Areas areas);

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
/*{{{  sort visitors */

S_Slice S_visitSlice(S_Slice arg, char* (*acceptCategory)(char*), S_Areas (*acceptAreas)(S_Areas));
S_Slices S_visitSlices(S_Slices arg, S_Slice (*acceptHead)(S_Slice));
S_Areas S_visitAreas(S_Areas arg, S_Area (*acceptHead)(S_Area));

/*}}}  */

#endif /* _SLICING_H */
