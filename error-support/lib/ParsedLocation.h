#ifndef _PARSEDLOCATION_H
#define _PARSEDLOCATION_H

/*{{{  includes */

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "ParsedLocation_dict.h"

/*}}}  */

/*{{{  typedefs */

typedef struct _PLOC_Normal *PLOC_Normal;
typedef struct _PLOC_Escaped *PLOC_Escaped;
typedef struct _PLOC_StrCon *PLOC_StrCon;
typedef struct _PLOC_NatCon *PLOC_NatCon;
typedef struct _PLOC_Location *PLOC_Location;
typedef struct _PLOC_Area *PLOC_Area;
typedef struct _PLOC_Slice *PLOC_Slice;
typedef struct _PLOC_AreaAreas *PLOC_AreaAreas;
typedef struct _PLOC_Start *PLOC_Start;
typedef struct _PLOC_OptLayout *PLOC_OptLayout;

/*}}}  */

void PLOC_initParsedLocationApi(void);

/*{{{  protect functions */

void PLOC_protectNormal(PLOC_Normal * arg);
void PLOC_protectEscaped(PLOC_Escaped * arg);
void PLOC_protectStrCon(PLOC_StrCon * arg);
void PLOC_protectNatCon(PLOC_NatCon * arg);
void PLOC_protectLocation(PLOC_Location * arg);
void PLOC_protectArea(PLOC_Area * arg);
void PLOC_protectSlice(PLOC_Slice * arg);
void PLOC_protectAreaAreas(PLOC_AreaAreas * arg);
void PLOC_protectStart(PLOC_Start * arg);
void PLOC_protectOptLayout(PLOC_OptLayout * arg);

/*}}}  */
/*{{{  term conversion functions */

PLOC_Normal PLOC_NormalFromTerm(ATerm t);
ATerm PLOC_NormalToTerm(PLOC_Normal arg);
PLOC_Escaped PLOC_EscapedFromTerm(ATerm t);
ATerm PLOC_EscapedToTerm(PLOC_Escaped arg);
PLOC_StrCon PLOC_StrConFromTerm(ATerm t);
ATerm PLOC_StrConToTerm(PLOC_StrCon arg);
PLOC_NatCon PLOC_NatConFromTerm(ATerm t);
ATerm PLOC_NatConToTerm(PLOC_NatCon arg);
PLOC_Location PLOC_LocationFromTerm(ATerm t);
ATerm PLOC_LocationToTerm(PLOC_Location arg);
PLOC_Area PLOC_AreaFromTerm(ATerm t);
ATerm PLOC_AreaToTerm(PLOC_Area arg);
PLOC_Slice PLOC_SliceFromTerm(ATerm t);
ATerm PLOC_SliceToTerm(PLOC_Slice arg);
PLOC_AreaAreas PLOC_AreaAreasFromTerm(ATerm t);
ATerm PLOC_AreaAreasToTerm(PLOC_AreaAreas arg);
PLOC_Start PLOC_StartFromTerm(ATerm t);
ATerm PLOC_StartToTerm(PLOC_Start arg);
PLOC_OptLayout PLOC_OptLayoutFromTerm(ATerm t);
ATerm PLOC_OptLayoutToTerm(PLOC_OptLayout arg);

/*}}}  */
/*{{{  list functions */

int PLOC_getAreaAreasLength(PLOC_AreaAreas arg);
PLOC_AreaAreas PLOC_reverseAreaAreas(PLOC_AreaAreas arg);
PLOC_AreaAreas PLOC_appendAreaAreas(PLOC_AreaAreas arg0,
				    PLOC_OptLayout wsAfterHead,
				    PLOC_OptLayout wsAfterSep,
				    PLOC_Area arg1);
PLOC_AreaAreas PLOC_concatAreaAreas(PLOC_AreaAreas arg0,
				    PLOC_OptLayout wsAfterHead,
				    PLOC_OptLayout wsAfterSep,
				    PLOC_AreaAreas arg1);
PLOC_AreaAreas PLOC_sliceAreaAreas(PLOC_AreaAreas arg, int start, int end);
PLOC_Area PLOC_getAreaAreasAreaAt(PLOC_AreaAreas arg, int index);
PLOC_AreaAreas PLOC_replaceAreaAreasAreaAt(PLOC_AreaAreas arg, PLOC_Area elem,
					   int index);
PLOC_AreaAreas PLOC_makeAreaAreas2(PLOC_OptLayout wsAfterHead,
				   PLOC_OptLayout wsAfterSep, PLOC_Area elem1,
				   PLOC_Area elem2);
PLOC_AreaAreas PLOC_makeAreaAreas3(PLOC_OptLayout wsAfterHead,
				   PLOC_OptLayout wsAfterSep, PLOC_Area elem1,
				   PLOC_Area elem2, PLOC_Area elem3);
PLOC_AreaAreas PLOC_makeAreaAreas4(PLOC_OptLayout wsAfterHead,
				   PLOC_OptLayout wsAfterSep, PLOC_Area elem1,
				   PLOC_Area elem2, PLOC_Area elem3,
				   PLOC_Area elem4);
PLOC_AreaAreas PLOC_makeAreaAreas5(PLOC_OptLayout wsAfterHead,
				   PLOC_OptLayout wsAfterSep, PLOC_Area elem1,
				   PLOC_Area elem2, PLOC_Area elem3,
				   PLOC_Area elem4, PLOC_Area elem5);
PLOC_AreaAreas PLOC_makeAreaAreas6(PLOC_OptLayout wsAfterHead,
				   PLOC_OptLayout wsAfterSep, PLOC_Area elem1,
				   PLOC_Area elem2, PLOC_Area elem3,
				   PLOC_Area elem4, PLOC_Area elem5,
				   PLOC_Area elem6);

/*}}}  */
/*{{{  constructors */

PLOC_Normal PLOC_makeNormalDefault(const char *string);
PLOC_Escaped PLOC_makeEscapedSpecialCharacter(const char *string);
PLOC_Escaped PLOC_makeEscapedOctal(const char *string);
PLOC_StrCon PLOC_makeStrConDefault(const char *string);
PLOC_NatCon PLOC_makeNatConDefault(const char *string);
PLOC_Location PLOC_makeLocationFile(PLOC_OptLayout wsAfterFile,
				    PLOC_OptLayout wsAfterParenOpen,
				    PLOC_StrCon filename,
				    PLOC_OptLayout wsAfterFilename);
PLOC_Location PLOC_makeLocationArea(PLOC_OptLayout wsAfterA,
				    PLOC_OptLayout wsAfterParenOpen,
				    PLOC_Area Area,
				    PLOC_OptLayout wsAfterArea);
PLOC_Location PLOC_makeLocationAreaInFile(PLOC_OptLayout wsAfterAreaInFile,
					  PLOC_OptLayout wsAfterParenOpen,
					  PLOC_StrCon filename,
					  PLOC_OptLayout wsAfterFilename,
					  PLOC_OptLayout wsAfterComma,
					  PLOC_Area Area,
					  PLOC_OptLayout wsAfterArea);
PLOC_Area PLOC_makeAreaArea(PLOC_OptLayout wsAfterArea,
			    PLOC_OptLayout wsAfterParenOpen,
			    PLOC_NatCon beginLine,
			    PLOC_OptLayout wsAfterBeginLine,
			    PLOC_OptLayout wsAfterComma,
			    PLOC_NatCon beginColumn,
			    PLOC_OptLayout wsAfterBeginColumn,
			    PLOC_OptLayout wsAfterComma1, PLOC_NatCon endLine,
			    PLOC_OptLayout wsAfterEndLine,
			    PLOC_OptLayout wsAfterComma2,
			    PLOC_NatCon endColumn,
			    PLOC_OptLayout wsAfterEndColumn,
			    PLOC_OptLayout wsAfterComma3, PLOC_NatCon offset,
			    PLOC_OptLayout wsAfterOffset,
			    PLOC_OptLayout wsAfterComma4, PLOC_NatCon length,
			    PLOC_OptLayout wsAfterLength);
PLOC_Slice PLOC_makeSliceSlice(PLOC_OptLayout wsAfterSlice,
			       PLOC_OptLayout wsAfterParenOpen,
			       PLOC_StrCon id, PLOC_OptLayout wsAfterId,
			       PLOC_OptLayout wsAfterComma,
			       PLOC_OptLayout wsAfterBracketOpen,
			       PLOC_AreaAreas areas,
			       PLOC_OptLayout wsAfterAreas,
			       PLOC_OptLayout wsAfterBracketClose);
PLOC_AreaAreas PLOC_makeAreaAreasEmpty(void);
PLOC_AreaAreas PLOC_makeAreaAreasSingle(PLOC_Area head);
PLOC_AreaAreas PLOC_makeAreaAreasMany(PLOC_Area head,
				      PLOC_OptLayout wsAfterHead,
				      PLOC_OptLayout wsAfterSep,
				      PLOC_AreaAreas tail);
PLOC_Start PLOC_makeStartSlice(PLOC_OptLayout wsBefore, PLOC_Slice topSlice,
			       PLOC_OptLayout wsAfter, int ambCnt);
PLOC_Start PLOC_makeStartArea(PLOC_OptLayout wsBefore, PLOC_Area topArea,
			      PLOC_OptLayout wsAfter, int ambCnt);
PLOC_Start PLOC_makeStartLocation(PLOC_OptLayout wsBefore,
				  PLOC_Location topLocation,
				  PLOC_OptLayout wsAfter, int ambCnt);
PLOC_Start PLOC_makeStartNatCon(PLOC_OptLayout wsBefore,
				PLOC_NatCon topNatCon, PLOC_OptLayout wsAfter,
				int ambCnt);
PLOC_Start PLOC_makeStartEscaped(PLOC_OptLayout wsBefore,
				 PLOC_Escaped topEscaped,
				 PLOC_OptLayout wsAfter, int ambCnt);
PLOC_Start PLOC_makeStartNormal(PLOC_OptLayout wsBefore,
				PLOC_Normal topNormal, PLOC_OptLayout wsAfter,
				int ambCnt);
PLOC_Start PLOC_makeStartStrCon(PLOC_OptLayout wsBefore,
				PLOC_StrCon topStrCon, PLOC_OptLayout wsAfter,
				int ambCnt);
PLOC_OptLayout PLOC_makeOptLayoutAbsent(void);
PLOC_OptLayout PLOC_makeOptLayoutPresent(const char *string);

/*}}}  */
/*{{{  equality functions */

ATbool PLOC_isEqualNormal(PLOC_Normal arg0, PLOC_Normal arg1);
ATbool PLOC_isEqualEscaped(PLOC_Escaped arg0, PLOC_Escaped arg1);
ATbool PLOC_isEqualStrCon(PLOC_StrCon arg0, PLOC_StrCon arg1);
ATbool PLOC_isEqualNatCon(PLOC_NatCon arg0, PLOC_NatCon arg1);
ATbool PLOC_isEqualLocation(PLOC_Location arg0, PLOC_Location arg1);
ATbool PLOC_isEqualArea(PLOC_Area arg0, PLOC_Area arg1);
ATbool PLOC_isEqualSlice(PLOC_Slice arg0, PLOC_Slice arg1);
ATbool PLOC_isEqualAreaAreas(PLOC_AreaAreas arg0, PLOC_AreaAreas arg1);
ATbool PLOC_isEqualStart(PLOC_Start arg0, PLOC_Start arg1);
ATbool PLOC_isEqualOptLayout(PLOC_OptLayout arg0, PLOC_OptLayout arg1);

/*}}}  */
/*{{{  PLOC_Normal accessors */

ATbool PLOC_isValidNormal(PLOC_Normal arg);
inline ATbool PLOC_isNormalDefault(PLOC_Normal arg);
ATbool PLOC_hasNormalString(PLOC_Normal arg);
char *PLOC_getNormalString(PLOC_Normal arg);
PLOC_Normal PLOC_setNormalString(PLOC_Normal arg, const char *string);

/*}}}  */
/*{{{  PLOC_Escaped accessors */

ATbool PLOC_isValidEscaped(PLOC_Escaped arg);
inline ATbool PLOC_isEscapedSpecialCharacter(PLOC_Escaped arg);
inline ATbool PLOC_isEscapedOctal(PLOC_Escaped arg);
ATbool PLOC_hasEscapedString(PLOC_Escaped arg);
char *PLOC_getEscapedString(PLOC_Escaped arg);
PLOC_Escaped PLOC_setEscapedString(PLOC_Escaped arg, const char *string);

/*}}}  */
/*{{{  PLOC_StrCon accessors */

ATbool PLOC_isValidStrCon(PLOC_StrCon arg);
inline ATbool PLOC_isStrConDefault(PLOC_StrCon arg);
ATbool PLOC_hasStrConString(PLOC_StrCon arg);
char *PLOC_getStrConString(PLOC_StrCon arg);
PLOC_StrCon PLOC_setStrConString(PLOC_StrCon arg, const char *string);

/*}}}  */
/*{{{  PLOC_NatCon accessors */

ATbool PLOC_isValidNatCon(PLOC_NatCon arg);
inline ATbool PLOC_isNatConDefault(PLOC_NatCon arg);
ATbool PLOC_hasNatConString(PLOC_NatCon arg);
char *PLOC_getNatConString(PLOC_NatCon arg);
PLOC_NatCon PLOC_setNatConString(PLOC_NatCon arg, const char *string);

/*}}}  */
/*{{{  PLOC_Location accessors */

ATbool PLOC_isValidLocation(PLOC_Location arg);
inline ATbool PLOC_isLocationFile(PLOC_Location arg);
inline ATbool PLOC_isLocationArea(PLOC_Location arg);
inline ATbool PLOC_isLocationAreaInFile(PLOC_Location arg);
ATbool PLOC_hasLocationWsAfterFile(PLOC_Location arg);
ATbool PLOC_hasLocationWsAfterParenOpen(PLOC_Location arg);
ATbool PLOC_hasLocationFilename(PLOC_Location arg);
ATbool PLOC_hasLocationWsAfterFilename(PLOC_Location arg);
ATbool PLOC_hasLocationWsAfterA(PLOC_Location arg);
ATbool PLOC_hasLocationArea(PLOC_Location arg);
ATbool PLOC_hasLocationWsAfterArea(PLOC_Location arg);
ATbool PLOC_hasLocationWsAfterAreaInFile(PLOC_Location arg);
ATbool PLOC_hasLocationWsAfterComma(PLOC_Location arg);
PLOC_OptLayout PLOC_getLocationWsAfterFile(PLOC_Location arg);
PLOC_OptLayout PLOC_getLocationWsAfterParenOpen(PLOC_Location arg);
PLOC_StrCon PLOC_getLocationFilename(PLOC_Location arg);
PLOC_OptLayout PLOC_getLocationWsAfterFilename(PLOC_Location arg);
PLOC_OptLayout PLOC_getLocationWsAfterA(PLOC_Location arg);
PLOC_Area PLOC_getLocationArea(PLOC_Location arg);
PLOC_OptLayout PLOC_getLocationWsAfterArea(PLOC_Location arg);
PLOC_OptLayout PLOC_getLocationWsAfterAreaInFile(PLOC_Location arg);
PLOC_OptLayout PLOC_getLocationWsAfterComma(PLOC_Location arg);
PLOC_Location PLOC_setLocationWsAfterFile(PLOC_Location arg,
					  PLOC_OptLayout wsAfterFile);
PLOC_Location PLOC_setLocationWsAfterParenOpen(PLOC_Location arg,
					       PLOC_OptLayout
					       wsAfterParenOpen);
PLOC_Location PLOC_setLocationFilename(PLOC_Location arg,
				       PLOC_StrCon filename);
PLOC_Location PLOC_setLocationWsAfterFilename(PLOC_Location arg,
					      PLOC_OptLayout wsAfterFilename);
PLOC_Location PLOC_setLocationWsAfterA(PLOC_Location arg,
				       PLOC_OptLayout wsAfterA);
PLOC_Location PLOC_setLocationArea(PLOC_Location arg, PLOC_Area Area);
PLOC_Location PLOC_setLocationWsAfterArea(PLOC_Location arg,
					  PLOC_OptLayout wsAfterArea);
PLOC_Location PLOC_setLocationWsAfterAreaInFile(PLOC_Location arg,
						PLOC_OptLayout
						wsAfterAreaInFile);
PLOC_Location PLOC_setLocationWsAfterComma(PLOC_Location arg,
					   PLOC_OptLayout wsAfterComma);

/*}}}  */
/*{{{  PLOC_Area accessors */

ATbool PLOC_isValidArea(PLOC_Area arg);
inline ATbool PLOC_isAreaArea(PLOC_Area arg);
ATbool PLOC_hasAreaWsAfterArea(PLOC_Area arg);
ATbool PLOC_hasAreaWsAfterParenOpen(PLOC_Area arg);
ATbool PLOC_hasAreaBeginLine(PLOC_Area arg);
ATbool PLOC_hasAreaWsAfterBeginLine(PLOC_Area arg);
ATbool PLOC_hasAreaWsAfterComma(PLOC_Area arg);
ATbool PLOC_hasAreaBeginColumn(PLOC_Area arg);
ATbool PLOC_hasAreaWsAfterBeginColumn(PLOC_Area arg);
ATbool PLOC_hasAreaWsAfterComma1(PLOC_Area arg);
ATbool PLOC_hasAreaEndLine(PLOC_Area arg);
ATbool PLOC_hasAreaWsAfterEndLine(PLOC_Area arg);
ATbool PLOC_hasAreaWsAfterComma2(PLOC_Area arg);
ATbool PLOC_hasAreaEndColumn(PLOC_Area arg);
ATbool PLOC_hasAreaWsAfterEndColumn(PLOC_Area arg);
ATbool PLOC_hasAreaWsAfterComma3(PLOC_Area arg);
ATbool PLOC_hasAreaOffset(PLOC_Area arg);
ATbool PLOC_hasAreaWsAfterOffset(PLOC_Area arg);
ATbool PLOC_hasAreaWsAfterComma4(PLOC_Area arg);
ATbool PLOC_hasAreaLength(PLOC_Area arg);
ATbool PLOC_hasAreaWsAfterLength(PLOC_Area arg);
PLOC_OptLayout PLOC_getAreaWsAfterArea(PLOC_Area arg);
PLOC_OptLayout PLOC_getAreaWsAfterParenOpen(PLOC_Area arg);
PLOC_NatCon PLOC_getAreaBeginLine(PLOC_Area arg);
PLOC_OptLayout PLOC_getAreaWsAfterBeginLine(PLOC_Area arg);
PLOC_OptLayout PLOC_getAreaWsAfterComma(PLOC_Area arg);
PLOC_NatCon PLOC_getAreaBeginColumn(PLOC_Area arg);
PLOC_OptLayout PLOC_getAreaWsAfterBeginColumn(PLOC_Area arg);
PLOC_OptLayout PLOC_getAreaWsAfterComma1(PLOC_Area arg);
PLOC_NatCon PLOC_getAreaEndLine(PLOC_Area arg);
PLOC_OptLayout PLOC_getAreaWsAfterEndLine(PLOC_Area arg);
PLOC_OptLayout PLOC_getAreaWsAfterComma2(PLOC_Area arg);
PLOC_NatCon PLOC_getAreaEndColumn(PLOC_Area arg);
PLOC_OptLayout PLOC_getAreaWsAfterEndColumn(PLOC_Area arg);
PLOC_OptLayout PLOC_getAreaWsAfterComma3(PLOC_Area arg);
PLOC_NatCon PLOC_getAreaOffset(PLOC_Area arg);
PLOC_OptLayout PLOC_getAreaWsAfterOffset(PLOC_Area arg);
PLOC_OptLayout PLOC_getAreaWsAfterComma4(PLOC_Area arg);
PLOC_NatCon PLOC_getAreaLength(PLOC_Area arg);
PLOC_OptLayout PLOC_getAreaWsAfterLength(PLOC_Area arg);
PLOC_Area PLOC_setAreaWsAfterArea(PLOC_Area arg, PLOC_OptLayout wsAfterArea);
PLOC_Area PLOC_setAreaWsAfterParenOpen(PLOC_Area arg,
				       PLOC_OptLayout wsAfterParenOpen);
PLOC_Area PLOC_setAreaBeginLine(PLOC_Area arg, PLOC_NatCon beginLine);
PLOC_Area PLOC_setAreaWsAfterBeginLine(PLOC_Area arg,
				       PLOC_OptLayout wsAfterBeginLine);
PLOC_Area PLOC_setAreaWsAfterComma(PLOC_Area arg,
				   PLOC_OptLayout wsAfterComma);
PLOC_Area PLOC_setAreaBeginColumn(PLOC_Area arg, PLOC_NatCon beginColumn);
PLOC_Area PLOC_setAreaWsAfterBeginColumn(PLOC_Area arg,
					 PLOC_OptLayout wsAfterBeginColumn);
PLOC_Area PLOC_setAreaWsAfterComma1(PLOC_Area arg,
				    PLOC_OptLayout wsAfterComma1);
PLOC_Area PLOC_setAreaEndLine(PLOC_Area arg, PLOC_NatCon endLine);
PLOC_Area PLOC_setAreaWsAfterEndLine(PLOC_Area arg,
				     PLOC_OptLayout wsAfterEndLine);
PLOC_Area PLOC_setAreaWsAfterComma2(PLOC_Area arg,
				    PLOC_OptLayout wsAfterComma2);
PLOC_Area PLOC_setAreaEndColumn(PLOC_Area arg, PLOC_NatCon endColumn);
PLOC_Area PLOC_setAreaWsAfterEndColumn(PLOC_Area arg,
				       PLOC_OptLayout wsAfterEndColumn);
PLOC_Area PLOC_setAreaWsAfterComma3(PLOC_Area arg,
				    PLOC_OptLayout wsAfterComma3);
PLOC_Area PLOC_setAreaOffset(PLOC_Area arg, PLOC_NatCon offset);
PLOC_Area PLOC_setAreaWsAfterOffset(PLOC_Area arg,
				    PLOC_OptLayout wsAfterOffset);
PLOC_Area PLOC_setAreaWsAfterComma4(PLOC_Area arg,
				    PLOC_OptLayout wsAfterComma4);
PLOC_Area PLOC_setAreaLength(PLOC_Area arg, PLOC_NatCon length);
PLOC_Area PLOC_setAreaWsAfterLength(PLOC_Area arg,
				    PLOC_OptLayout wsAfterLength);

/*}}}  */
/*{{{  PLOC_Slice accessors */

ATbool PLOC_isValidSlice(PLOC_Slice arg);
inline ATbool PLOC_isSliceSlice(PLOC_Slice arg);
ATbool PLOC_hasSliceWsAfterSlice(PLOC_Slice arg);
ATbool PLOC_hasSliceWsAfterParenOpen(PLOC_Slice arg);
ATbool PLOC_hasSliceId(PLOC_Slice arg);
ATbool PLOC_hasSliceWsAfterId(PLOC_Slice arg);
ATbool PLOC_hasSliceWsAfterComma(PLOC_Slice arg);
ATbool PLOC_hasSliceWsAfterBracketOpen(PLOC_Slice arg);
ATbool PLOC_hasSliceAreas(PLOC_Slice arg);
ATbool PLOC_hasSliceWsAfterAreas(PLOC_Slice arg);
ATbool PLOC_hasSliceWsAfterBracketClose(PLOC_Slice arg);
PLOC_OptLayout PLOC_getSliceWsAfterSlice(PLOC_Slice arg);
PLOC_OptLayout PLOC_getSliceWsAfterParenOpen(PLOC_Slice arg);
PLOC_StrCon PLOC_getSliceId(PLOC_Slice arg);
PLOC_OptLayout PLOC_getSliceWsAfterId(PLOC_Slice arg);
PLOC_OptLayout PLOC_getSliceWsAfterComma(PLOC_Slice arg);
PLOC_OptLayout PLOC_getSliceWsAfterBracketOpen(PLOC_Slice arg);
PLOC_AreaAreas PLOC_getSliceAreas(PLOC_Slice arg);
PLOC_OptLayout PLOC_getSliceWsAfterAreas(PLOC_Slice arg);
PLOC_OptLayout PLOC_getSliceWsAfterBracketClose(PLOC_Slice arg);
PLOC_Slice PLOC_setSliceWsAfterSlice(PLOC_Slice arg,
				     PLOC_OptLayout wsAfterSlice);
PLOC_Slice PLOC_setSliceWsAfterParenOpen(PLOC_Slice arg,
					 PLOC_OptLayout wsAfterParenOpen);
PLOC_Slice PLOC_setSliceId(PLOC_Slice arg, PLOC_StrCon id);
PLOC_Slice PLOC_setSliceWsAfterId(PLOC_Slice arg, PLOC_OptLayout wsAfterId);
PLOC_Slice PLOC_setSliceWsAfterComma(PLOC_Slice arg,
				     PLOC_OptLayout wsAfterComma);
PLOC_Slice PLOC_setSliceWsAfterBracketOpen(PLOC_Slice arg,
					   PLOC_OptLayout wsAfterBracketOpen);
PLOC_Slice PLOC_setSliceAreas(PLOC_Slice arg, PLOC_AreaAreas areas);
PLOC_Slice PLOC_setSliceWsAfterAreas(PLOC_Slice arg,
				     PLOC_OptLayout wsAfterAreas);
PLOC_Slice PLOC_setSliceWsAfterBracketClose(PLOC_Slice arg,
					    PLOC_OptLayout
					    wsAfterBracketClose);

/*}}}  */
/*{{{  PLOC_AreaAreas accessors */

ATbool PLOC_isValidAreaAreas(PLOC_AreaAreas arg);
inline ATbool PLOC_isAreaAreasEmpty(PLOC_AreaAreas arg);
inline ATbool PLOC_isAreaAreasSingle(PLOC_AreaAreas arg);
inline ATbool PLOC_isAreaAreasMany(PLOC_AreaAreas arg);
ATbool PLOC_hasAreaAreasHead(PLOC_AreaAreas arg);
ATbool PLOC_hasAreaAreasWsAfterHead(PLOC_AreaAreas arg);
ATbool PLOC_hasAreaAreasWsAfterSep(PLOC_AreaAreas arg);
ATbool PLOC_hasAreaAreasTail(PLOC_AreaAreas arg);
PLOC_AreaAreas PLOC_getAreaAreasTail(PLOC_AreaAreas arg);
PLOC_Area PLOC_getAreaAreasHead(PLOC_AreaAreas arg);
PLOC_OptLayout PLOC_getAreaAreasWsAfterHead(PLOC_AreaAreas arg);
PLOC_OptLayout PLOC_getAreaAreasWsAfterSep(PLOC_AreaAreas arg);
PLOC_AreaAreas PLOC_setAreaAreasHead(PLOC_AreaAreas arg, PLOC_Area head);
PLOC_AreaAreas PLOC_setAreaAreasWsAfterHead(PLOC_AreaAreas arg,
					    PLOC_OptLayout wsAfterHead);
PLOC_AreaAreas PLOC_setAreaAreasWsAfterSep(PLOC_AreaAreas arg,
					   PLOC_OptLayout wsAfterSep);
PLOC_AreaAreas PLOC_setAreaAreasTail(PLOC_AreaAreas arg, PLOC_AreaAreas tail);

/*}}}  */
/*{{{  PLOC_Start accessors */

ATbool PLOC_isValidStart(PLOC_Start arg);
inline ATbool PLOC_isStartSlice(PLOC_Start arg);
inline ATbool PLOC_isStartArea(PLOC_Start arg);
inline ATbool PLOC_isStartLocation(PLOC_Start arg);
inline ATbool PLOC_isStartNatCon(PLOC_Start arg);
inline ATbool PLOC_isStartEscaped(PLOC_Start arg);
inline ATbool PLOC_isStartNormal(PLOC_Start arg);
inline ATbool PLOC_isStartStrCon(PLOC_Start arg);
ATbool PLOC_hasStartWsBefore(PLOC_Start arg);
ATbool PLOC_hasStartTopSlice(PLOC_Start arg);
ATbool PLOC_hasStartWsAfter(PLOC_Start arg);
ATbool PLOC_hasStartAmbCnt(PLOC_Start arg);
ATbool PLOC_hasStartTopArea(PLOC_Start arg);
ATbool PLOC_hasStartTopLocation(PLOC_Start arg);
ATbool PLOC_hasStartTopNatCon(PLOC_Start arg);
ATbool PLOC_hasStartTopEscaped(PLOC_Start arg);
ATbool PLOC_hasStartTopNormal(PLOC_Start arg);
ATbool PLOC_hasStartTopStrCon(PLOC_Start arg);
PLOC_OptLayout PLOC_getStartWsBefore(PLOC_Start arg);
PLOC_Slice PLOC_getStartTopSlice(PLOC_Start arg);
PLOC_OptLayout PLOC_getStartWsAfter(PLOC_Start arg);
int PLOC_getStartAmbCnt(PLOC_Start arg);
PLOC_Area PLOC_getStartTopArea(PLOC_Start arg);
PLOC_Location PLOC_getStartTopLocation(PLOC_Start arg);
PLOC_NatCon PLOC_getStartTopNatCon(PLOC_Start arg);
PLOC_Escaped PLOC_getStartTopEscaped(PLOC_Start arg);
PLOC_Normal PLOC_getStartTopNormal(PLOC_Start arg);
PLOC_StrCon PLOC_getStartTopStrCon(PLOC_Start arg);
PLOC_Start PLOC_setStartWsBefore(PLOC_Start arg, PLOC_OptLayout wsBefore);
PLOC_Start PLOC_setStartTopSlice(PLOC_Start arg, PLOC_Slice topSlice);
PLOC_Start PLOC_setStartWsAfter(PLOC_Start arg, PLOC_OptLayout wsAfter);
PLOC_Start PLOC_setStartAmbCnt(PLOC_Start arg, int ambCnt);
PLOC_Start PLOC_setStartTopArea(PLOC_Start arg, PLOC_Area topArea);
PLOC_Start PLOC_setStartTopLocation(PLOC_Start arg,
				    PLOC_Location topLocation);
PLOC_Start PLOC_setStartTopNatCon(PLOC_Start arg, PLOC_NatCon topNatCon);
PLOC_Start PLOC_setStartTopEscaped(PLOC_Start arg, PLOC_Escaped topEscaped);
PLOC_Start PLOC_setStartTopNormal(PLOC_Start arg, PLOC_Normal topNormal);
PLOC_Start PLOC_setStartTopStrCon(PLOC_Start arg, PLOC_StrCon topStrCon);

/*}}}  */
/*{{{  PLOC_OptLayout accessors */

ATbool PLOC_isValidOptLayout(PLOC_OptLayout arg);
inline ATbool PLOC_isOptLayoutAbsent(PLOC_OptLayout arg);
inline ATbool PLOC_isOptLayoutPresent(PLOC_OptLayout arg);
ATbool PLOC_hasOptLayoutString(PLOC_OptLayout arg);
char *PLOC_getOptLayoutString(PLOC_OptLayout arg);
PLOC_OptLayout PLOC_setOptLayoutString(PLOC_OptLayout arg,
				       const char *string);

/*}}}  */
/*{{{  sort visitors */

PLOC_Normal PLOC_visitNormal(PLOC_Normal arg, char *(*acceptString) (char *));
PLOC_Escaped PLOC_visitEscaped(PLOC_Escaped arg,
			       char *(*acceptString) (char *));
PLOC_StrCon PLOC_visitStrCon(PLOC_StrCon arg, char *(*acceptString) (char *));
PLOC_NatCon PLOC_visitNatCon(PLOC_NatCon arg, char *(*acceptString) (char *));
PLOC_Location PLOC_visitLocation(PLOC_Location arg,
				 PLOC_OptLayout(*acceptWsAfterFile)
				 (PLOC_OptLayout),
				 PLOC_OptLayout(*acceptWsAfterParenOpen)
				 (PLOC_OptLayout),
				 PLOC_StrCon(*acceptFilename) (PLOC_StrCon),
				 PLOC_OptLayout(*acceptWsAfterFilename)
				 (PLOC_OptLayout),
				 PLOC_OptLayout(*acceptWsAfterA)
				 (PLOC_OptLayout),
				 PLOC_Area(*acceptArea) (PLOC_Area),
				 PLOC_OptLayout(*acceptWsAfterArea)
				 (PLOC_OptLayout),
				 PLOC_OptLayout(*acceptWsAfterAreaInFile)
				 (PLOC_OptLayout),
				 PLOC_OptLayout(*acceptWsAfterComma)
				 (PLOC_OptLayout));
PLOC_Area PLOC_visitArea(PLOC_Area arg,
			 PLOC_OptLayout(*acceptWsAfterArea) (PLOC_OptLayout),
			 PLOC_OptLayout(*acceptWsAfterParenOpen)
			 (PLOC_OptLayout),
			 PLOC_NatCon(*acceptBeginLine) (PLOC_NatCon),
			 PLOC_OptLayout(*acceptWsAfterBeginLine)
			 (PLOC_OptLayout),
			 PLOC_OptLayout(*acceptWsAfterComma) (PLOC_OptLayout),
			 PLOC_NatCon(*acceptBeginColumn) (PLOC_NatCon),
			 PLOC_OptLayout(*acceptWsAfterBeginColumn)
			 (PLOC_OptLayout),
			 PLOC_OptLayout(*acceptWsAfterComma1)
			 (PLOC_OptLayout),
			 PLOC_NatCon(*acceptEndLine) (PLOC_NatCon),
			 PLOC_OptLayout(*acceptWsAfterEndLine)
			 (PLOC_OptLayout),
			 PLOC_OptLayout(*acceptWsAfterComma2)
			 (PLOC_OptLayout),
			 PLOC_NatCon(*acceptEndColumn) (PLOC_NatCon),
			 PLOC_OptLayout(*acceptWsAfterEndColumn)
			 (PLOC_OptLayout),
			 PLOC_OptLayout(*acceptWsAfterComma3)
			 (PLOC_OptLayout),
			 PLOC_NatCon(*acceptOffset) (PLOC_NatCon),
			 PLOC_OptLayout(*acceptWsAfterOffset)
			 (PLOC_OptLayout),
			 PLOC_OptLayout(*acceptWsAfterComma4)
			 (PLOC_OptLayout),
			 PLOC_NatCon(*acceptLength) (PLOC_NatCon),
			 PLOC_OptLayout(*acceptWsAfterLength)
			 (PLOC_OptLayout));
PLOC_Slice PLOC_visitSlice(PLOC_Slice arg,
			   PLOC_OptLayout(*acceptWsAfterSlice)
			   (PLOC_OptLayout),
			   PLOC_OptLayout(*acceptWsAfterParenOpen)
			   (PLOC_OptLayout),
			   PLOC_StrCon(*acceptId) (PLOC_StrCon),
			   PLOC_OptLayout(*acceptWsAfterId) (PLOC_OptLayout),
			   PLOC_OptLayout(*acceptWsAfterComma)
			   (PLOC_OptLayout),
			   PLOC_OptLayout(*acceptWsAfterBracketOpen)
			   (PLOC_OptLayout),
			   PLOC_AreaAreas(*acceptAreas) (PLOC_AreaAreas),
			   PLOC_OptLayout(*acceptWsAfterAreas)
			   (PLOC_OptLayout),
			   PLOC_OptLayout(*acceptWsAfterBracketClose)
			   (PLOC_OptLayout));
PLOC_AreaAreas PLOC_visitAreaAreas(PLOC_AreaAreas arg,
				   PLOC_Area(*acceptHead) (PLOC_Area),
				   PLOC_OptLayout(*acceptWsAfterHead)
				   (PLOC_OptLayout),
				   PLOC_OptLayout(*acceptWsAfterSep)
				   (PLOC_OptLayout));
PLOC_Start PLOC_visitStart(PLOC_Start arg,
			   PLOC_OptLayout(*acceptWsBefore) (PLOC_OptLayout),
			   PLOC_Slice(*acceptTopSlice) (PLOC_Slice),
			   PLOC_OptLayout(*acceptWsAfter) (PLOC_OptLayout),
			   int (*acceptAmbCnt) (int),
			   PLOC_Area(*acceptTopArea) (PLOC_Area),
			   PLOC_Location(*acceptTopLocation) (PLOC_Location),
			   PLOC_NatCon(*acceptTopNatCon) (PLOC_NatCon),
			   PLOC_Escaped(*acceptTopEscaped) (PLOC_Escaped),
			   PLOC_Normal(*acceptTopNormal) (PLOC_Normal),
			   PLOC_StrCon(*acceptTopStrCon) (PLOC_StrCon));
PLOC_OptLayout PLOC_visitOptLayout(PLOC_OptLayout arg,
				   char *(*acceptString) (char *));

/*}}}  */

#endif /* _PARSEDLOCATION_H */
