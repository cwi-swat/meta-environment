#ifndef _LIBRARY_H
#define _LIBRARY_H

/*{{{  includes */

#include <stdlib.h>
#include <string.h>
#include <aterm1.h>
#include "Library_dict.h"

/*}}}  */

/*{{{  typedefs */

typedef struct _CO_Boolean *CO_Boolean;
typedef struct _CO_Normal *CO_Normal;
typedef struct _CO_Escaped *CO_Escaped;
typedef struct _CO_StrCon *CO_StrCon;
typedef struct _CO_BoolCon *CO_BoolCon;
typedef struct _CO_NatCon *CO_NatCon;
typedef struct _CO_Byte *CO_Byte;
typedef struct _CO_Bytes *CO_Bytes;
typedef struct _CO_Subject *CO_Subject;
typedef struct _CO_Error *CO_Error;
typedef struct _CO_SubjectList *CO_SubjectList;
typedef struct _CO_Summary *CO_Summary;
typedef struct _CO_ErrorList *CO_ErrorList;
typedef struct _CO_Location *CO_Location;
typedef struct _CO_Area *CO_Area;
typedef struct _CO_Read *CO_Read;
typedef struct _CO_Write *CO_Write;
typedef struct _CO_Parsetree *CO_Parsetree;
typedef struct _CO_OptLayout *CO_OptLayout;
typedef struct _CO_Start *CO_Start;

/*}}}  */

void CO_initLibraryApi(void);

/*{{{  protect functions */

void CO_protectBoolean(CO_Boolean *arg);
void CO_protectNormal(CO_Normal *arg);
void CO_protectEscaped(CO_Escaped *arg);
void CO_protectStrCon(CO_StrCon *arg);
void CO_protectBoolCon(CO_BoolCon *arg);
void CO_protectNatCon(CO_NatCon *arg);
void CO_protectByte(CO_Byte *arg);
void CO_protectBytes(CO_Bytes *arg);
void CO_protectSubject(CO_Subject *arg);
void CO_protectError(CO_Error *arg);
void CO_protectSubjectList(CO_SubjectList *arg);
void CO_protectSummary(CO_Summary *arg);
void CO_protectErrorList(CO_ErrorList *arg);
void CO_protectLocation(CO_Location *arg);
void CO_protectArea(CO_Area *arg);
void CO_protectRead(CO_Read *arg);
void CO_protectWrite(CO_Write *arg);
void CO_protectParsetree(CO_Parsetree *arg);
void CO_protectOptLayout(CO_OptLayout *arg);
void CO_protectStart(CO_Start *arg);

/*}}}  */
/*{{{  term conversion functions */

CO_Boolean CO_BooleanFromTerm(ATerm t);
ATerm CO_BooleanToTerm(CO_Boolean arg);
CO_Normal CO_NormalFromTerm(ATerm t);
ATerm CO_NormalToTerm(CO_Normal arg);
CO_Escaped CO_EscapedFromTerm(ATerm t);
ATerm CO_EscapedToTerm(CO_Escaped arg);
CO_StrCon CO_StrConFromTerm(ATerm t);
ATerm CO_StrConToTerm(CO_StrCon arg);
CO_BoolCon CO_BoolConFromTerm(ATerm t);
ATerm CO_BoolConToTerm(CO_BoolCon arg);
CO_NatCon CO_NatConFromTerm(ATerm t);
ATerm CO_NatConToTerm(CO_NatCon arg);
CO_Byte CO_ByteFromTerm(ATerm t);
ATerm CO_ByteToTerm(CO_Byte arg);
CO_Bytes CO_BytesFromTerm(ATerm t);
ATerm CO_BytesToTerm(CO_Bytes arg);
CO_Subject CO_SubjectFromTerm(ATerm t);
ATerm CO_SubjectToTerm(CO_Subject arg);
CO_Error CO_ErrorFromTerm(ATerm t);
ATerm CO_ErrorToTerm(CO_Error arg);
CO_SubjectList CO_SubjectListFromTerm(ATerm t);
ATerm CO_SubjectListToTerm(CO_SubjectList arg);
CO_Summary CO_SummaryFromTerm(ATerm t);
ATerm CO_SummaryToTerm(CO_Summary arg);
CO_ErrorList CO_ErrorListFromTerm(ATerm t);
ATerm CO_ErrorListToTerm(CO_ErrorList arg);
CO_Location CO_LocationFromTerm(ATerm t);
ATerm CO_LocationToTerm(CO_Location arg);
CO_Area CO_AreaFromTerm(ATerm t);
ATerm CO_AreaToTerm(CO_Area arg);
CO_Read CO_ReadFromTerm(ATerm t);
ATerm CO_ReadToTerm(CO_Read arg);
CO_Write CO_WriteFromTerm(ATerm t);
ATerm CO_WriteToTerm(CO_Write arg);
CO_Parsetree CO_ParsetreeFromTerm(ATerm t);
ATerm CO_ParsetreeToTerm(CO_Parsetree arg);
CO_OptLayout CO_OptLayoutFromTerm(ATerm t);
ATerm CO_OptLayoutToTerm(CO_OptLayout arg);
CO_Start CO_StartFromTerm(ATerm t);
ATerm CO_StartToTerm(CO_Start arg);

/*}}}  */
/*{{{  list functions */

int CO_getSubjectListLength (CO_SubjectList arg);
CO_SubjectList CO_reverseSubjectList(CO_SubjectList arg);
CO_SubjectList CO_appendSubjectList(CO_SubjectList arg0, CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Subject arg1);
CO_SubjectList CO_concatSubjectList(CO_SubjectList arg0, CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_SubjectList arg1);
CO_SubjectList CO_sliceSubjectList(CO_SubjectList arg, int start, int end);
CO_Subject CO_getSubjectListSubjectAt(CO_SubjectList arg, int index);
CO_SubjectList CO_replaceSubjectListSubjectAt(CO_SubjectList arg, CO_Subject elem, int index);
CO_SubjectList CO_makeSubjectList2(CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Subject elem1, CO_Subject elem2);
CO_SubjectList CO_makeSubjectList3(CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Subject elem1, CO_Subject elem2, CO_Subject elem3);
CO_SubjectList CO_makeSubjectList4(CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Subject elem1, CO_Subject elem2, CO_Subject elem3, CO_Subject elem4);
CO_SubjectList CO_makeSubjectList5(CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Subject elem1, CO_Subject elem2, CO_Subject elem3, CO_Subject elem4, CO_Subject elem5);
CO_SubjectList CO_makeSubjectList6(CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Subject elem1, CO_Subject elem2, CO_Subject elem3, CO_Subject elem4, CO_Subject elem5, CO_Subject elem6);
int CO_getErrorListLength (CO_ErrorList arg);
CO_ErrorList CO_reverseErrorList(CO_ErrorList arg);
CO_ErrorList CO_appendErrorList(CO_ErrorList arg0, CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Error arg1);
CO_ErrorList CO_concatErrorList(CO_ErrorList arg0, CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_ErrorList arg1);
CO_ErrorList CO_sliceErrorList(CO_ErrorList arg, int start, int end);
CO_Error CO_getErrorListErrorAt(CO_ErrorList arg, int index);
CO_ErrorList CO_replaceErrorListErrorAt(CO_ErrorList arg, CO_Error elem, int index);
CO_ErrorList CO_makeErrorList2(CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Error elem1, CO_Error elem2);
CO_ErrorList CO_makeErrorList3(CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Error elem1, CO_Error elem2, CO_Error elem3);
CO_ErrorList CO_makeErrorList4(CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Error elem1, CO_Error elem2, CO_Error elem3, CO_Error elem4);
CO_ErrorList CO_makeErrorList5(CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Error elem1, CO_Error elem2, CO_Error elem3, CO_Error elem4, CO_Error elem5);
CO_ErrorList CO_makeErrorList6(CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Error elem1, CO_Error elem2, CO_Error elem3, CO_Error elem4, CO_Error elem5, CO_Error elem6);

/*}}}  */
/*{{{  constructors */

CO_Boolean CO_makeBooleanConstant(CO_BoolCon BoolCon);
CO_Boolean CO_makeBooleanOr(CO_Boolean lhs, CO_OptLayout wsAfterLhs, CO_OptLayout wsAfterBar, CO_Boolean rhs);
CO_Boolean CO_makeBooleanAnd(CO_Boolean lhs, CO_OptLayout wsAfterLhs, CO_OptLayout wsAfterAmp, CO_Boolean rhs);
CO_Boolean CO_makeBooleanNot(CO_OptLayout wsAfterNot, CO_OptLayout wsAfterParenOpen, CO_Boolean Boolean, CO_OptLayout wsAfterBoolean);
CO_Boolean CO_makeBooleanBracket(CO_OptLayout wsAfterParenOpen, CO_Boolean Boolean, CO_OptLayout wsAfterBoolean);
CO_Normal CO_makeNormalDefault(const char* string);
CO_Escaped CO_makeEscapedSpecialCharacter(const char* string);
CO_Escaped CO_makeEscapedOctal(const char* string);
CO_StrCon CO_makeStrConDefault(const char* string);
CO_BoolCon CO_makeBoolConTrue(void);
CO_BoolCon CO_makeBoolConFalse(void);
CO_NatCon CO_makeNatConDefault(const char* string);
CO_Byte CO_makeByteByte(const char* string);
CO_Bytes CO_makeBytesBytes(const char* string);
CO_Subject CO_makeSubjectSubject(CO_OptLayout wsAfterSubject, CO_OptLayout wsAfterParenOpen, CO_StrCon description, CO_OptLayout wsAfterDescription);
CO_Subject CO_makeSubjectLocalized(CO_OptLayout wsAfterLocalized, CO_OptLayout wsAfterParenOpen, CO_StrCon description, CO_OptLayout wsAfterDescription, CO_OptLayout wsAfterComma, CO_Location Location, CO_OptLayout wsAfterLocation);
CO_Error CO_makeErrorInfo(CO_OptLayout wsAfterInfo, CO_OptLayout wsAfterParenOpen, CO_StrCon description, CO_OptLayout wsAfterDescription, CO_OptLayout wsAfterComma, CO_OptLayout wsAfterBracketOpen, CO_SubjectList list, CO_OptLayout wsAfterList, CO_OptLayout wsAfterBracketClose);
CO_Error CO_makeErrorWarning(CO_OptLayout wsAfterWarning, CO_OptLayout wsAfterParenOpen, CO_StrCon description, CO_OptLayout wsAfterDescription, CO_OptLayout wsAfterComma, CO_OptLayout wsAfterBracketOpen, CO_SubjectList list, CO_OptLayout wsAfterList, CO_OptLayout wsAfterBracketClose);
CO_Error CO_makeErrorError(CO_OptLayout wsAfterError, CO_OptLayout wsAfterParenOpen, CO_StrCon description, CO_OptLayout wsAfterDescription, CO_OptLayout wsAfterComma, CO_OptLayout wsAfterBracketOpen, CO_SubjectList list, CO_OptLayout wsAfterList, CO_OptLayout wsAfterBracketClose);
CO_Error CO_makeErrorFatal(CO_OptLayout wsAfterFatal, CO_OptLayout wsAfterParenOpen, CO_StrCon description, CO_OptLayout wsAfterDescription, CO_OptLayout wsAfterComma, CO_OptLayout wsAfterBracketOpen, CO_SubjectList list, CO_OptLayout wsAfterList, CO_OptLayout wsAfterBracketClose);
CO_SubjectList CO_makeSubjectListEmpty(void);
CO_SubjectList CO_makeSubjectListSingle(CO_Subject head);
CO_SubjectList CO_makeSubjectListMany(CO_Subject head, CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_SubjectList tail);
CO_Summary CO_makeSummarySummary(CO_OptLayout wsAfterSummary, CO_OptLayout wsAfterParenOpen, CO_StrCon producer, CO_OptLayout wsAfterProducer, CO_OptLayout wsAfterComma, CO_StrCon id, CO_OptLayout wsAfterId, CO_OptLayout wsAfterComma1, CO_OptLayout wsAfterBracketOpen, CO_ErrorList list, CO_OptLayout wsAfterList, CO_OptLayout wsAfterBracketClose);
CO_ErrorList CO_makeErrorListEmpty(void);
CO_ErrorList CO_makeErrorListSingle(CO_Error head);
CO_ErrorList CO_makeErrorListMany(CO_Error head, CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_ErrorList tail);
CO_Location CO_makeLocationFile(CO_OptLayout wsAfterFile, CO_OptLayout wsAfterParenOpen, CO_StrCon filename, CO_OptLayout wsAfterFilename);
CO_Location CO_makeLocationAreaInFile(CO_OptLayout wsAfterAreaInFile, CO_OptLayout wsAfterParenOpen, CO_StrCon filename, CO_OptLayout wsAfterFilename, CO_OptLayout wsAfterComma, CO_Area Area, CO_OptLayout wsAfterArea);
CO_Area CO_makeAreaArea(CO_OptLayout wsAfterArea, CO_OptLayout wsAfterParenOpen, CO_NatCon beginLine, CO_OptLayout wsAfterBeginLine, CO_OptLayout wsAfterComma, CO_NatCon beginColumn, CO_OptLayout wsAfterBeginColumn, CO_OptLayout wsAfterComma1, CO_NatCon endLine, CO_OptLayout wsAfterEndLine, CO_OptLayout wsAfterComma2, CO_NatCon endColumn, CO_OptLayout wsAfterEndColumn, CO_OptLayout wsAfterComma3, CO_NatCon offset, CO_OptLayout wsAfterOffset, CO_OptLayout wsAfterComma4, CO_NatCon length, CO_OptLayout wsAfterLength);
CO_Read CO_makeReadSuccess(CO_OptLayout wsAfterRead, CO_OptLayout wsAfterParenOpen, CO_Bytes value, CO_OptLayout wsAfterValue);
CO_Read CO_makeReadFailure(CO_OptLayout wsAfterReadError, CO_OptLayout wsAfterParenOpen, CO_Summary Summary, CO_OptLayout wsAfterSummary);
CO_Write CO_makeWriteSuccess(void);
CO_Write CO_makeWriteFailure(CO_OptLayout wsAfterWriteError, CO_OptLayout wsAfterParenOpen, CO_Summary Summary, CO_OptLayout wsAfterSummary);
CO_Parsetree CO_makeParsetreeSuccess(const char* treeSort, const char* X, CO_OptLayout wsAfterParseTree, CO_OptLayout wsAfterParenOpen, CO_Bytes leftLayout, CO_OptLayout wsAfterLeftLayout, CO_OptLayout wsAfterComma, ATerm tree, CO_OptLayout wsAfterTree, CO_OptLayout wsAfterComma1, CO_Bytes rightLayout, CO_OptLayout wsAfterRightLayout, CO_OptLayout wsAfterComma2, CO_NatCon ambCnt, CO_OptLayout wsAfterAmbCnt);
CO_Parsetree CO_makeParsetreeFailure(const char* X, CO_OptLayout wsAfterParseError, CO_OptLayout wsAfterParenOpen, CO_Summary Summary, CO_OptLayout wsAfterSummary);
CO_OptLayout CO_makeOptLayoutAbsent(void);
CO_OptLayout CO_makeOptLayoutPresent(const char* string);
CO_Start CO_makeStartWrite(CO_OptLayout wsBefore, CO_Write topWrite, CO_OptLayout wsAfter, int ambCnt);
CO_Start CO_makeStartRead(CO_OptLayout wsBefore, CO_Read topRead, CO_OptLayout wsAfter, int ambCnt);
CO_Start CO_makeStartArea(CO_OptLayout wsBefore, CO_Area topArea, CO_OptLayout wsAfter, int ambCnt);
CO_Start CO_makeStartLocation(CO_OptLayout wsBefore, CO_Location topLocation, CO_OptLayout wsAfter, int ambCnt);
CO_Start CO_makeStartSubject(CO_OptLayout wsBefore, CO_Subject topSubject, CO_OptLayout wsAfter, int ambCnt);
CO_Start CO_makeStartError(CO_OptLayout wsBefore, CO_Error topError, CO_OptLayout wsAfter, int ambCnt);
CO_Start CO_makeStartSummary(CO_OptLayout wsBefore, CO_Summary topSummary, CO_OptLayout wsAfter, int ambCnt);
CO_Start CO_makeStartByte(CO_OptLayout wsBefore, CO_Byte topByte, CO_OptLayout wsAfter, int ambCnt);
CO_Start CO_makeStartBytes(CO_OptLayout wsBefore, CO_Bytes topBytes, CO_OptLayout wsAfter, int ambCnt);
CO_Start CO_makeStartNatCon(CO_OptLayout wsBefore, CO_NatCon topNatCon, CO_OptLayout wsAfter, int ambCnt);
CO_Start CO_makeStartBoolCon(CO_OptLayout wsBefore, CO_BoolCon topBoolCon, CO_OptLayout wsAfter, int ambCnt);
CO_Start CO_makeStartEscaped(CO_OptLayout wsBefore, CO_Escaped topEscaped, CO_OptLayout wsAfter, int ambCnt);
CO_Start CO_makeStartNormal(CO_OptLayout wsBefore, CO_Normal topNormal, CO_OptLayout wsAfter, int ambCnt);
CO_Start CO_makeStartStrCon(CO_OptLayout wsBefore, CO_StrCon topStrCon, CO_OptLayout wsAfter, int ambCnt);
CO_Start CO_makeStartBoolean(CO_OptLayout wsBefore, CO_Boolean topBoolean, CO_OptLayout wsAfter, int ambCnt);

/*}}}  */
/*{{{  equality functions */

ATbool CO_isEqualBoolean(CO_Boolean arg0, CO_Boolean arg1);
ATbool CO_isEqualNormal(CO_Normal arg0, CO_Normal arg1);
ATbool CO_isEqualEscaped(CO_Escaped arg0, CO_Escaped arg1);
ATbool CO_isEqualStrCon(CO_StrCon arg0, CO_StrCon arg1);
ATbool CO_isEqualBoolCon(CO_BoolCon arg0, CO_BoolCon arg1);
ATbool CO_isEqualNatCon(CO_NatCon arg0, CO_NatCon arg1);
ATbool CO_isEqualByte(CO_Byte arg0, CO_Byte arg1);
ATbool CO_isEqualBytes(CO_Bytes arg0, CO_Bytes arg1);
ATbool CO_isEqualSubject(CO_Subject arg0, CO_Subject arg1);
ATbool CO_isEqualError(CO_Error arg0, CO_Error arg1);
ATbool CO_isEqualSubjectList(CO_SubjectList arg0, CO_SubjectList arg1);
ATbool CO_isEqualSummary(CO_Summary arg0, CO_Summary arg1);
ATbool CO_isEqualErrorList(CO_ErrorList arg0, CO_ErrorList arg1);
ATbool CO_isEqualLocation(CO_Location arg0, CO_Location arg1);
ATbool CO_isEqualArea(CO_Area arg0, CO_Area arg1);
ATbool CO_isEqualRead(CO_Read arg0, CO_Read arg1);
ATbool CO_isEqualWrite(CO_Write arg0, CO_Write arg1);
ATbool CO_isEqualParsetree(CO_Parsetree arg0, CO_Parsetree arg1);
ATbool CO_isEqualOptLayout(CO_OptLayout arg0, CO_OptLayout arg1);
ATbool CO_isEqualStart(CO_Start arg0, CO_Start arg1);

/*}}}  */
/*{{{  CO_Boolean accessors */

ATbool CO_isValidBoolean(CO_Boolean arg);
inline ATbool CO_isBooleanConstant(CO_Boolean arg);
inline ATbool CO_isBooleanOr(CO_Boolean arg);
inline ATbool CO_isBooleanAnd(CO_Boolean arg);
inline ATbool CO_isBooleanNot(CO_Boolean arg);
inline ATbool CO_isBooleanBracket(CO_Boolean arg);
ATbool CO_hasBooleanBoolCon(CO_Boolean arg);
ATbool CO_hasBooleanLhs(CO_Boolean arg);
ATbool CO_hasBooleanWsAfterLhs(CO_Boolean arg);
ATbool CO_hasBooleanWsAfterBar(CO_Boolean arg);
ATbool CO_hasBooleanRhs(CO_Boolean arg);
ATbool CO_hasBooleanWsAfterAmp(CO_Boolean arg);
ATbool CO_hasBooleanWsAfterNot(CO_Boolean arg);
ATbool CO_hasBooleanWsAfterParenOpen(CO_Boolean arg);
ATbool CO_hasBooleanBoolean(CO_Boolean arg);
ATbool CO_hasBooleanWsAfterBoolean(CO_Boolean arg);
CO_BoolCon CO_getBooleanBoolCon(CO_Boolean arg);
CO_Boolean CO_getBooleanLhs(CO_Boolean arg);
CO_OptLayout CO_getBooleanWsAfterLhs(CO_Boolean arg);
CO_OptLayout CO_getBooleanWsAfterBar(CO_Boolean arg);
CO_Boolean CO_getBooleanRhs(CO_Boolean arg);
CO_OptLayout CO_getBooleanWsAfterAmp(CO_Boolean arg);
CO_OptLayout CO_getBooleanWsAfterNot(CO_Boolean arg);
CO_OptLayout CO_getBooleanWsAfterParenOpen(CO_Boolean arg);
CO_Boolean CO_getBooleanBoolean(CO_Boolean arg);
CO_OptLayout CO_getBooleanWsAfterBoolean(CO_Boolean arg);
CO_Boolean CO_setBooleanBoolCon(CO_Boolean arg, CO_BoolCon BoolCon);
CO_Boolean CO_setBooleanLhs(CO_Boolean arg, CO_Boolean lhs);
CO_Boolean CO_setBooleanWsAfterLhs(CO_Boolean arg, CO_OptLayout wsAfterLhs);
CO_Boolean CO_setBooleanWsAfterBar(CO_Boolean arg, CO_OptLayout wsAfterBar);
CO_Boolean CO_setBooleanRhs(CO_Boolean arg, CO_Boolean rhs);
CO_Boolean CO_setBooleanWsAfterAmp(CO_Boolean arg, CO_OptLayout wsAfterAmp);
CO_Boolean CO_setBooleanWsAfterNot(CO_Boolean arg, CO_OptLayout wsAfterNot);
CO_Boolean CO_setBooleanWsAfterParenOpen(CO_Boolean arg, CO_OptLayout wsAfterParenOpen);
CO_Boolean CO_setBooleanBoolean(CO_Boolean arg, CO_Boolean Boolean);
CO_Boolean CO_setBooleanWsAfterBoolean(CO_Boolean arg, CO_OptLayout wsAfterBoolean);

/*}}}  */
/*{{{  CO_Normal accessors */

ATbool CO_isValidNormal(CO_Normal arg);
inline ATbool CO_isNormalDefault(CO_Normal arg);
ATbool CO_hasNormalString(CO_Normal arg);
char* CO_getNormalString(CO_Normal arg);
CO_Normal CO_setNormalString(CO_Normal arg, const char* string);

/*}}}  */
/*{{{  CO_Escaped accessors */

ATbool CO_isValidEscaped(CO_Escaped arg);
inline ATbool CO_isEscapedSpecialCharacter(CO_Escaped arg);
inline ATbool CO_isEscapedOctal(CO_Escaped arg);
ATbool CO_hasEscapedString(CO_Escaped arg);
char* CO_getEscapedString(CO_Escaped arg);
CO_Escaped CO_setEscapedString(CO_Escaped arg, const char* string);

/*}}}  */
/*{{{  CO_StrCon accessors */

ATbool CO_isValidStrCon(CO_StrCon arg);
inline ATbool CO_isStrConDefault(CO_StrCon arg);
ATbool CO_hasStrConString(CO_StrCon arg);
char* CO_getStrConString(CO_StrCon arg);
CO_StrCon CO_setStrConString(CO_StrCon arg, const char* string);

/*}}}  */
/*{{{  CO_BoolCon accessors */

ATbool CO_isValidBoolCon(CO_BoolCon arg);
inline ATbool CO_isBoolConTrue(CO_BoolCon arg);
inline ATbool CO_isBoolConFalse(CO_BoolCon arg);

/*}}}  */
/*{{{  CO_NatCon accessors */

ATbool CO_isValidNatCon(CO_NatCon arg);
inline ATbool CO_isNatConDefault(CO_NatCon arg);
ATbool CO_hasNatConString(CO_NatCon arg);
char* CO_getNatConString(CO_NatCon arg);
CO_NatCon CO_setNatConString(CO_NatCon arg, const char* string);

/*}}}  */
/*{{{  CO_Byte accessors */

ATbool CO_isValidByte(CO_Byte arg);
inline ATbool CO_isByteByte(CO_Byte arg);
ATbool CO_hasByteString(CO_Byte arg);
char* CO_getByteString(CO_Byte arg);
CO_Byte CO_setByteString(CO_Byte arg, const char* string);

/*}}}  */
/*{{{  CO_Bytes accessors */

ATbool CO_isValidBytes(CO_Bytes arg);
inline ATbool CO_isBytesBytes(CO_Bytes arg);
ATbool CO_hasBytesString(CO_Bytes arg);
char* CO_getBytesString(CO_Bytes arg);
CO_Bytes CO_setBytesString(CO_Bytes arg, const char* string);

/*}}}  */
/*{{{  CO_Subject accessors */

ATbool CO_isValidSubject(CO_Subject arg);
inline ATbool CO_isSubjectSubject(CO_Subject arg);
inline ATbool CO_isSubjectLocalized(CO_Subject arg);
ATbool CO_hasSubjectWsAfterSubject(CO_Subject arg);
ATbool CO_hasSubjectWsAfterParenOpen(CO_Subject arg);
ATbool CO_hasSubjectDescription(CO_Subject arg);
ATbool CO_hasSubjectWsAfterDescription(CO_Subject arg);
ATbool CO_hasSubjectWsAfterLocalized(CO_Subject arg);
ATbool CO_hasSubjectWsAfterComma(CO_Subject arg);
ATbool CO_hasSubjectLocation(CO_Subject arg);
ATbool CO_hasSubjectWsAfterLocation(CO_Subject arg);
CO_OptLayout CO_getSubjectWsAfterSubject(CO_Subject arg);
CO_OptLayout CO_getSubjectWsAfterParenOpen(CO_Subject arg);
CO_StrCon CO_getSubjectDescription(CO_Subject arg);
CO_OptLayout CO_getSubjectWsAfterDescription(CO_Subject arg);
CO_OptLayout CO_getSubjectWsAfterLocalized(CO_Subject arg);
CO_OptLayout CO_getSubjectWsAfterComma(CO_Subject arg);
CO_Location CO_getSubjectLocation(CO_Subject arg);
CO_OptLayout CO_getSubjectWsAfterLocation(CO_Subject arg);
CO_Subject CO_setSubjectWsAfterSubject(CO_Subject arg, CO_OptLayout wsAfterSubject);
CO_Subject CO_setSubjectWsAfterParenOpen(CO_Subject arg, CO_OptLayout wsAfterParenOpen);
CO_Subject CO_setSubjectDescription(CO_Subject arg, CO_StrCon description);
CO_Subject CO_setSubjectWsAfterDescription(CO_Subject arg, CO_OptLayout wsAfterDescription);
CO_Subject CO_setSubjectWsAfterLocalized(CO_Subject arg, CO_OptLayout wsAfterLocalized);
CO_Subject CO_setSubjectWsAfterComma(CO_Subject arg, CO_OptLayout wsAfterComma);
CO_Subject CO_setSubjectLocation(CO_Subject arg, CO_Location Location);
CO_Subject CO_setSubjectWsAfterLocation(CO_Subject arg, CO_OptLayout wsAfterLocation);

/*}}}  */
/*{{{  CO_Error accessors */

ATbool CO_isValidError(CO_Error arg);
inline ATbool CO_isErrorInfo(CO_Error arg);
inline ATbool CO_isErrorWarning(CO_Error arg);
inline ATbool CO_isErrorError(CO_Error arg);
inline ATbool CO_isErrorFatal(CO_Error arg);
ATbool CO_hasErrorWsAfterInfo(CO_Error arg);
ATbool CO_hasErrorWsAfterParenOpen(CO_Error arg);
ATbool CO_hasErrorDescription(CO_Error arg);
ATbool CO_hasErrorWsAfterDescription(CO_Error arg);
ATbool CO_hasErrorWsAfterComma(CO_Error arg);
ATbool CO_hasErrorWsAfterBracketOpen(CO_Error arg);
ATbool CO_hasErrorList(CO_Error arg);
ATbool CO_hasErrorWsAfterList(CO_Error arg);
ATbool CO_hasErrorWsAfterBracketClose(CO_Error arg);
ATbool CO_hasErrorWsAfterWarning(CO_Error arg);
ATbool CO_hasErrorWsAfterError(CO_Error arg);
ATbool CO_hasErrorWsAfterFatal(CO_Error arg);
CO_OptLayout CO_getErrorWsAfterInfo(CO_Error arg);
CO_OptLayout CO_getErrorWsAfterParenOpen(CO_Error arg);
CO_StrCon CO_getErrorDescription(CO_Error arg);
CO_OptLayout CO_getErrorWsAfterDescription(CO_Error arg);
CO_OptLayout CO_getErrorWsAfterComma(CO_Error arg);
CO_OptLayout CO_getErrorWsAfterBracketOpen(CO_Error arg);
CO_SubjectList CO_getErrorList(CO_Error arg);
CO_OptLayout CO_getErrorWsAfterList(CO_Error arg);
CO_OptLayout CO_getErrorWsAfterBracketClose(CO_Error arg);
CO_OptLayout CO_getErrorWsAfterWarning(CO_Error arg);
CO_OptLayout CO_getErrorWsAfterError(CO_Error arg);
CO_OptLayout CO_getErrorWsAfterFatal(CO_Error arg);
CO_Error CO_setErrorWsAfterInfo(CO_Error arg, CO_OptLayout wsAfterInfo);
CO_Error CO_setErrorWsAfterParenOpen(CO_Error arg, CO_OptLayout wsAfterParenOpen);
CO_Error CO_setErrorDescription(CO_Error arg, CO_StrCon description);
CO_Error CO_setErrorWsAfterDescription(CO_Error arg, CO_OptLayout wsAfterDescription);
CO_Error CO_setErrorWsAfterComma(CO_Error arg, CO_OptLayout wsAfterComma);
CO_Error CO_setErrorWsAfterBracketOpen(CO_Error arg, CO_OptLayout wsAfterBracketOpen);
CO_Error CO_setErrorList(CO_Error arg, CO_SubjectList list);
CO_Error CO_setErrorWsAfterList(CO_Error arg, CO_OptLayout wsAfterList);
CO_Error CO_setErrorWsAfterBracketClose(CO_Error arg, CO_OptLayout wsAfterBracketClose);
CO_Error CO_setErrorWsAfterWarning(CO_Error arg, CO_OptLayout wsAfterWarning);
CO_Error CO_setErrorWsAfterError(CO_Error arg, CO_OptLayout wsAfterError);
CO_Error CO_setErrorWsAfterFatal(CO_Error arg, CO_OptLayout wsAfterFatal);

/*}}}  */
/*{{{  CO_SubjectList accessors */

ATbool CO_isValidSubjectList(CO_SubjectList arg);
inline ATbool CO_isSubjectListEmpty(CO_SubjectList arg);
inline ATbool CO_isSubjectListSingle(CO_SubjectList arg);
inline ATbool CO_isSubjectListMany(CO_SubjectList arg);
ATbool CO_hasSubjectListHead(CO_SubjectList arg);
ATbool CO_hasSubjectListWsAfterHead(CO_SubjectList arg);
ATbool CO_hasSubjectListWsAfterSep(CO_SubjectList arg);
ATbool CO_hasSubjectListTail(CO_SubjectList arg);
CO_SubjectList CO_getSubjectListTail(CO_SubjectList arg);
CO_Subject CO_getSubjectListHead(CO_SubjectList arg);
CO_OptLayout CO_getSubjectListWsAfterHead(CO_SubjectList arg);
CO_OptLayout CO_getSubjectListWsAfterSep(CO_SubjectList arg);
CO_SubjectList CO_setSubjectListHead(CO_SubjectList arg, CO_Subject head);
CO_SubjectList CO_setSubjectListWsAfterHead(CO_SubjectList arg, CO_OptLayout wsAfterHead);
CO_SubjectList CO_setSubjectListWsAfterSep(CO_SubjectList arg, CO_OptLayout wsAfterSep);
CO_SubjectList CO_setSubjectListTail(CO_SubjectList arg, CO_SubjectList tail);

/*}}}  */
/*{{{  CO_Summary accessors */

ATbool CO_isValidSummary(CO_Summary arg);
inline ATbool CO_isSummarySummary(CO_Summary arg);
ATbool CO_hasSummaryWsAfterSummary(CO_Summary arg);
ATbool CO_hasSummaryWsAfterParenOpen(CO_Summary arg);
ATbool CO_hasSummaryProducer(CO_Summary arg);
ATbool CO_hasSummaryWsAfterProducer(CO_Summary arg);
ATbool CO_hasSummaryWsAfterComma(CO_Summary arg);
ATbool CO_hasSummaryId(CO_Summary arg);
ATbool CO_hasSummaryWsAfterId(CO_Summary arg);
ATbool CO_hasSummaryWsAfterComma1(CO_Summary arg);
ATbool CO_hasSummaryWsAfterBracketOpen(CO_Summary arg);
ATbool CO_hasSummaryList(CO_Summary arg);
ATbool CO_hasSummaryWsAfterList(CO_Summary arg);
ATbool CO_hasSummaryWsAfterBracketClose(CO_Summary arg);
CO_OptLayout CO_getSummaryWsAfterSummary(CO_Summary arg);
CO_OptLayout CO_getSummaryWsAfterParenOpen(CO_Summary arg);
CO_StrCon CO_getSummaryProducer(CO_Summary arg);
CO_OptLayout CO_getSummaryWsAfterProducer(CO_Summary arg);
CO_OptLayout CO_getSummaryWsAfterComma(CO_Summary arg);
CO_StrCon CO_getSummaryId(CO_Summary arg);
CO_OptLayout CO_getSummaryWsAfterId(CO_Summary arg);
CO_OptLayout CO_getSummaryWsAfterComma1(CO_Summary arg);
CO_OptLayout CO_getSummaryWsAfterBracketOpen(CO_Summary arg);
CO_ErrorList CO_getSummaryList(CO_Summary arg);
CO_OptLayout CO_getSummaryWsAfterList(CO_Summary arg);
CO_OptLayout CO_getSummaryWsAfterBracketClose(CO_Summary arg);
CO_Summary CO_setSummaryWsAfterSummary(CO_Summary arg, CO_OptLayout wsAfterSummary);
CO_Summary CO_setSummaryWsAfterParenOpen(CO_Summary arg, CO_OptLayout wsAfterParenOpen);
CO_Summary CO_setSummaryProducer(CO_Summary arg, CO_StrCon producer);
CO_Summary CO_setSummaryWsAfterProducer(CO_Summary arg, CO_OptLayout wsAfterProducer);
CO_Summary CO_setSummaryWsAfterComma(CO_Summary arg, CO_OptLayout wsAfterComma);
CO_Summary CO_setSummaryId(CO_Summary arg, CO_StrCon id);
CO_Summary CO_setSummaryWsAfterId(CO_Summary arg, CO_OptLayout wsAfterId);
CO_Summary CO_setSummaryWsAfterComma1(CO_Summary arg, CO_OptLayout wsAfterComma1);
CO_Summary CO_setSummaryWsAfterBracketOpen(CO_Summary arg, CO_OptLayout wsAfterBracketOpen);
CO_Summary CO_setSummaryList(CO_Summary arg, CO_ErrorList list);
CO_Summary CO_setSummaryWsAfterList(CO_Summary arg, CO_OptLayout wsAfterList);
CO_Summary CO_setSummaryWsAfterBracketClose(CO_Summary arg, CO_OptLayout wsAfterBracketClose);

/*}}}  */
/*{{{  CO_ErrorList accessors */

ATbool CO_isValidErrorList(CO_ErrorList arg);
inline ATbool CO_isErrorListEmpty(CO_ErrorList arg);
inline ATbool CO_isErrorListSingle(CO_ErrorList arg);
inline ATbool CO_isErrorListMany(CO_ErrorList arg);
ATbool CO_hasErrorListHead(CO_ErrorList arg);
ATbool CO_hasErrorListWsAfterHead(CO_ErrorList arg);
ATbool CO_hasErrorListWsAfterSep(CO_ErrorList arg);
ATbool CO_hasErrorListTail(CO_ErrorList arg);
CO_ErrorList CO_getErrorListTail(CO_ErrorList arg);
CO_Error CO_getErrorListHead(CO_ErrorList arg);
CO_OptLayout CO_getErrorListWsAfterHead(CO_ErrorList arg);
CO_OptLayout CO_getErrorListWsAfterSep(CO_ErrorList arg);
CO_ErrorList CO_setErrorListHead(CO_ErrorList arg, CO_Error head);
CO_ErrorList CO_setErrorListWsAfterHead(CO_ErrorList arg, CO_OptLayout wsAfterHead);
CO_ErrorList CO_setErrorListWsAfterSep(CO_ErrorList arg, CO_OptLayout wsAfterSep);
CO_ErrorList CO_setErrorListTail(CO_ErrorList arg, CO_ErrorList tail);

/*}}}  */
/*{{{  CO_Location accessors */

ATbool CO_isValidLocation(CO_Location arg);
inline ATbool CO_isLocationFile(CO_Location arg);
inline ATbool CO_isLocationAreaInFile(CO_Location arg);
ATbool CO_hasLocationWsAfterFile(CO_Location arg);
ATbool CO_hasLocationWsAfterParenOpen(CO_Location arg);
ATbool CO_hasLocationFilename(CO_Location arg);
ATbool CO_hasLocationWsAfterFilename(CO_Location arg);
ATbool CO_hasLocationWsAfterAreaInFile(CO_Location arg);
ATbool CO_hasLocationWsAfterComma(CO_Location arg);
ATbool CO_hasLocationArea(CO_Location arg);
ATbool CO_hasLocationWsAfterArea(CO_Location arg);
CO_OptLayout CO_getLocationWsAfterFile(CO_Location arg);
CO_OptLayout CO_getLocationWsAfterParenOpen(CO_Location arg);
CO_StrCon CO_getLocationFilename(CO_Location arg);
CO_OptLayout CO_getLocationWsAfterFilename(CO_Location arg);
CO_OptLayout CO_getLocationWsAfterAreaInFile(CO_Location arg);
CO_OptLayout CO_getLocationWsAfterComma(CO_Location arg);
CO_Area CO_getLocationArea(CO_Location arg);
CO_OptLayout CO_getLocationWsAfterArea(CO_Location arg);
CO_Location CO_setLocationWsAfterFile(CO_Location arg, CO_OptLayout wsAfterFile);
CO_Location CO_setLocationWsAfterParenOpen(CO_Location arg, CO_OptLayout wsAfterParenOpen);
CO_Location CO_setLocationFilename(CO_Location arg, CO_StrCon filename);
CO_Location CO_setLocationWsAfterFilename(CO_Location arg, CO_OptLayout wsAfterFilename);
CO_Location CO_setLocationWsAfterAreaInFile(CO_Location arg, CO_OptLayout wsAfterAreaInFile);
CO_Location CO_setLocationWsAfterComma(CO_Location arg, CO_OptLayout wsAfterComma);
CO_Location CO_setLocationArea(CO_Location arg, CO_Area Area);
CO_Location CO_setLocationWsAfterArea(CO_Location arg, CO_OptLayout wsAfterArea);

/*}}}  */
/*{{{  CO_Area accessors */

ATbool CO_isValidArea(CO_Area arg);
inline ATbool CO_isAreaArea(CO_Area arg);
ATbool CO_hasAreaWsAfterArea(CO_Area arg);
ATbool CO_hasAreaWsAfterParenOpen(CO_Area arg);
ATbool CO_hasAreaBeginLine(CO_Area arg);
ATbool CO_hasAreaWsAfterBeginLine(CO_Area arg);
ATbool CO_hasAreaWsAfterComma(CO_Area arg);
ATbool CO_hasAreaBeginColumn(CO_Area arg);
ATbool CO_hasAreaWsAfterBeginColumn(CO_Area arg);
ATbool CO_hasAreaWsAfterComma1(CO_Area arg);
ATbool CO_hasAreaEndLine(CO_Area arg);
ATbool CO_hasAreaWsAfterEndLine(CO_Area arg);
ATbool CO_hasAreaWsAfterComma2(CO_Area arg);
ATbool CO_hasAreaEndColumn(CO_Area arg);
ATbool CO_hasAreaWsAfterEndColumn(CO_Area arg);
ATbool CO_hasAreaWsAfterComma3(CO_Area arg);
ATbool CO_hasAreaOffset(CO_Area arg);
ATbool CO_hasAreaWsAfterOffset(CO_Area arg);
ATbool CO_hasAreaWsAfterComma4(CO_Area arg);
ATbool CO_hasAreaLength(CO_Area arg);
ATbool CO_hasAreaWsAfterLength(CO_Area arg);
CO_OptLayout CO_getAreaWsAfterArea(CO_Area arg);
CO_OptLayout CO_getAreaWsAfterParenOpen(CO_Area arg);
CO_NatCon CO_getAreaBeginLine(CO_Area arg);
CO_OptLayout CO_getAreaWsAfterBeginLine(CO_Area arg);
CO_OptLayout CO_getAreaWsAfterComma(CO_Area arg);
CO_NatCon CO_getAreaBeginColumn(CO_Area arg);
CO_OptLayout CO_getAreaWsAfterBeginColumn(CO_Area arg);
CO_OptLayout CO_getAreaWsAfterComma1(CO_Area arg);
CO_NatCon CO_getAreaEndLine(CO_Area arg);
CO_OptLayout CO_getAreaWsAfterEndLine(CO_Area arg);
CO_OptLayout CO_getAreaWsAfterComma2(CO_Area arg);
CO_NatCon CO_getAreaEndColumn(CO_Area arg);
CO_OptLayout CO_getAreaWsAfterEndColumn(CO_Area arg);
CO_OptLayout CO_getAreaWsAfterComma3(CO_Area arg);
CO_NatCon CO_getAreaOffset(CO_Area arg);
CO_OptLayout CO_getAreaWsAfterOffset(CO_Area arg);
CO_OptLayout CO_getAreaWsAfterComma4(CO_Area arg);
CO_NatCon CO_getAreaLength(CO_Area arg);
CO_OptLayout CO_getAreaWsAfterLength(CO_Area arg);
CO_Area CO_setAreaWsAfterArea(CO_Area arg, CO_OptLayout wsAfterArea);
CO_Area CO_setAreaWsAfterParenOpen(CO_Area arg, CO_OptLayout wsAfterParenOpen);
CO_Area CO_setAreaBeginLine(CO_Area arg, CO_NatCon beginLine);
CO_Area CO_setAreaWsAfterBeginLine(CO_Area arg, CO_OptLayout wsAfterBeginLine);
CO_Area CO_setAreaWsAfterComma(CO_Area arg, CO_OptLayout wsAfterComma);
CO_Area CO_setAreaBeginColumn(CO_Area arg, CO_NatCon beginColumn);
CO_Area CO_setAreaWsAfterBeginColumn(CO_Area arg, CO_OptLayout wsAfterBeginColumn);
CO_Area CO_setAreaWsAfterComma1(CO_Area arg, CO_OptLayout wsAfterComma1);
CO_Area CO_setAreaEndLine(CO_Area arg, CO_NatCon endLine);
CO_Area CO_setAreaWsAfterEndLine(CO_Area arg, CO_OptLayout wsAfterEndLine);
CO_Area CO_setAreaWsAfterComma2(CO_Area arg, CO_OptLayout wsAfterComma2);
CO_Area CO_setAreaEndColumn(CO_Area arg, CO_NatCon endColumn);
CO_Area CO_setAreaWsAfterEndColumn(CO_Area arg, CO_OptLayout wsAfterEndColumn);
CO_Area CO_setAreaWsAfterComma3(CO_Area arg, CO_OptLayout wsAfterComma3);
CO_Area CO_setAreaOffset(CO_Area arg, CO_NatCon offset);
CO_Area CO_setAreaWsAfterOffset(CO_Area arg, CO_OptLayout wsAfterOffset);
CO_Area CO_setAreaWsAfterComma4(CO_Area arg, CO_OptLayout wsAfterComma4);
CO_Area CO_setAreaLength(CO_Area arg, CO_NatCon length);
CO_Area CO_setAreaWsAfterLength(CO_Area arg, CO_OptLayout wsAfterLength);

/*}}}  */
/*{{{  CO_Read accessors */

ATbool CO_isValidRead(CO_Read arg);
inline ATbool CO_isReadSuccess(CO_Read arg);
inline ATbool CO_isReadFailure(CO_Read arg);
ATbool CO_hasReadWsAfterRead(CO_Read arg);
ATbool CO_hasReadWsAfterParenOpen(CO_Read arg);
ATbool CO_hasReadValue(CO_Read arg);
ATbool CO_hasReadWsAfterValue(CO_Read arg);
ATbool CO_hasReadWsAfterReadError(CO_Read arg);
ATbool CO_hasReadSummary(CO_Read arg);
ATbool CO_hasReadWsAfterSummary(CO_Read arg);
CO_OptLayout CO_getReadWsAfterRead(CO_Read arg);
CO_OptLayout CO_getReadWsAfterParenOpen(CO_Read arg);
CO_Bytes CO_getReadValue(CO_Read arg);
CO_OptLayout CO_getReadWsAfterValue(CO_Read arg);
CO_OptLayout CO_getReadWsAfterReadError(CO_Read arg);
CO_Summary CO_getReadSummary(CO_Read arg);
CO_OptLayout CO_getReadWsAfterSummary(CO_Read arg);
CO_Read CO_setReadWsAfterRead(CO_Read arg, CO_OptLayout wsAfterRead);
CO_Read CO_setReadWsAfterParenOpen(CO_Read arg, CO_OptLayout wsAfterParenOpen);
CO_Read CO_setReadValue(CO_Read arg, CO_Bytes value);
CO_Read CO_setReadWsAfterValue(CO_Read arg, CO_OptLayout wsAfterValue);
CO_Read CO_setReadWsAfterReadError(CO_Read arg, CO_OptLayout wsAfterReadError);
CO_Read CO_setReadSummary(CO_Read arg, CO_Summary Summary);
CO_Read CO_setReadWsAfterSummary(CO_Read arg, CO_OptLayout wsAfterSummary);

/*}}}  */
/*{{{  CO_Write accessors */

ATbool CO_isValidWrite(CO_Write arg);
inline ATbool CO_isWriteSuccess(CO_Write arg);
inline ATbool CO_isWriteFailure(CO_Write arg);
ATbool CO_hasWriteWsAfterWriteError(CO_Write arg);
ATbool CO_hasWriteWsAfterParenOpen(CO_Write arg);
ATbool CO_hasWriteSummary(CO_Write arg);
ATbool CO_hasWriteWsAfterSummary(CO_Write arg);
CO_OptLayout CO_getWriteWsAfterWriteError(CO_Write arg);
CO_OptLayout CO_getWriteWsAfterParenOpen(CO_Write arg);
CO_Summary CO_getWriteSummary(CO_Write arg);
CO_OptLayout CO_getWriteWsAfterSummary(CO_Write arg);
CO_Write CO_setWriteWsAfterWriteError(CO_Write arg, CO_OptLayout wsAfterWriteError);
CO_Write CO_setWriteWsAfterParenOpen(CO_Write arg, CO_OptLayout wsAfterParenOpen);
CO_Write CO_setWriteSummary(CO_Write arg, CO_Summary Summary);
CO_Write CO_setWriteWsAfterSummary(CO_Write arg, CO_OptLayout wsAfterSummary);

/*}}}  */
/*{{{  CO_Parsetree accessors */

ATbool CO_isValidParsetree(CO_Parsetree arg);
inline ATbool CO_isParsetreeSuccess(CO_Parsetree arg);
inline ATbool CO_isParsetreeFailure(CO_Parsetree arg);
ATbool CO_hasParsetreeTreeSort(CO_Parsetree arg);
ATbool CO_hasParsetreeX(CO_Parsetree arg);
ATbool CO_hasParsetreeWsAfterParseTree(CO_Parsetree arg);
ATbool CO_hasParsetreeWsAfterParenOpen(CO_Parsetree arg);
ATbool CO_hasParsetreeLeftLayout(CO_Parsetree arg);
ATbool CO_hasParsetreeWsAfterLeftLayout(CO_Parsetree arg);
ATbool CO_hasParsetreeWsAfterComma(CO_Parsetree arg);
ATbool CO_hasParsetreeTree(CO_Parsetree arg);
ATbool CO_hasParsetreeWsAfterTree(CO_Parsetree arg);
ATbool CO_hasParsetreeWsAfterComma1(CO_Parsetree arg);
ATbool CO_hasParsetreeRightLayout(CO_Parsetree arg);
ATbool CO_hasParsetreeWsAfterRightLayout(CO_Parsetree arg);
ATbool CO_hasParsetreeWsAfterComma2(CO_Parsetree arg);
ATbool CO_hasParsetreeAmbCnt(CO_Parsetree arg);
ATbool CO_hasParsetreeWsAfterAmbCnt(CO_Parsetree arg);
ATbool CO_hasParsetreeWsAfterParseError(CO_Parsetree arg);
ATbool CO_hasParsetreeSummary(CO_Parsetree arg);
ATbool CO_hasParsetreeWsAfterSummary(CO_Parsetree arg);
char* CO_getParsetreeTreeSort(CO_Parsetree arg);
char* CO_getParsetreeX(CO_Parsetree arg);
CO_OptLayout CO_getParsetreeWsAfterParseTree(CO_Parsetree arg);
CO_OptLayout CO_getParsetreeWsAfterParenOpen(CO_Parsetree arg);
CO_Bytes CO_getParsetreeLeftLayout(CO_Parsetree arg);
CO_OptLayout CO_getParsetreeWsAfterLeftLayout(CO_Parsetree arg);
CO_OptLayout CO_getParsetreeWsAfterComma(CO_Parsetree arg);
ATerm CO_getParsetreeTree(CO_Parsetree arg);
CO_OptLayout CO_getParsetreeWsAfterTree(CO_Parsetree arg);
CO_OptLayout CO_getParsetreeWsAfterComma1(CO_Parsetree arg);
CO_Bytes CO_getParsetreeRightLayout(CO_Parsetree arg);
CO_OptLayout CO_getParsetreeWsAfterRightLayout(CO_Parsetree arg);
CO_OptLayout CO_getParsetreeWsAfterComma2(CO_Parsetree arg);
CO_NatCon CO_getParsetreeAmbCnt(CO_Parsetree arg);
CO_OptLayout CO_getParsetreeWsAfterAmbCnt(CO_Parsetree arg);
CO_OptLayout CO_getParsetreeWsAfterParseError(CO_Parsetree arg);
CO_Summary CO_getParsetreeSummary(CO_Parsetree arg);
CO_OptLayout CO_getParsetreeWsAfterSummary(CO_Parsetree arg);
CO_Parsetree CO_setParsetreeTreeSort(CO_Parsetree arg, const char* treeSort);
CO_Parsetree CO_setParsetreeX(CO_Parsetree arg, const char* X);
CO_Parsetree CO_setParsetreeWsAfterParseTree(CO_Parsetree arg, CO_OptLayout wsAfterParseTree);
CO_Parsetree CO_setParsetreeWsAfterParenOpen(CO_Parsetree arg, CO_OptLayout wsAfterParenOpen);
CO_Parsetree CO_setParsetreeLeftLayout(CO_Parsetree arg, CO_Bytes leftLayout);
CO_Parsetree CO_setParsetreeWsAfterLeftLayout(CO_Parsetree arg, CO_OptLayout wsAfterLeftLayout);
CO_Parsetree CO_setParsetreeWsAfterComma(CO_Parsetree arg, CO_OptLayout wsAfterComma);
CO_Parsetree CO_setParsetreeTree(CO_Parsetree arg, ATerm tree);
CO_Parsetree CO_setParsetreeWsAfterTree(CO_Parsetree arg, CO_OptLayout wsAfterTree);
CO_Parsetree CO_setParsetreeWsAfterComma1(CO_Parsetree arg, CO_OptLayout wsAfterComma1);
CO_Parsetree CO_setParsetreeRightLayout(CO_Parsetree arg, CO_Bytes rightLayout);
CO_Parsetree CO_setParsetreeWsAfterRightLayout(CO_Parsetree arg, CO_OptLayout wsAfterRightLayout);
CO_Parsetree CO_setParsetreeWsAfterComma2(CO_Parsetree arg, CO_OptLayout wsAfterComma2);
CO_Parsetree CO_setParsetreeAmbCnt(CO_Parsetree arg, CO_NatCon ambCnt);
CO_Parsetree CO_setParsetreeWsAfterAmbCnt(CO_Parsetree arg, CO_OptLayout wsAfterAmbCnt);
CO_Parsetree CO_setParsetreeWsAfterParseError(CO_Parsetree arg, CO_OptLayout wsAfterParseError);
CO_Parsetree CO_setParsetreeSummary(CO_Parsetree arg, CO_Summary Summary);
CO_Parsetree CO_setParsetreeWsAfterSummary(CO_Parsetree arg, CO_OptLayout wsAfterSummary);

/*}}}  */
/*{{{  CO_OptLayout accessors */

ATbool CO_isValidOptLayout(CO_OptLayout arg);
inline ATbool CO_isOptLayoutAbsent(CO_OptLayout arg);
inline ATbool CO_isOptLayoutPresent(CO_OptLayout arg);
ATbool CO_hasOptLayoutString(CO_OptLayout arg);
char* CO_getOptLayoutString(CO_OptLayout arg);
CO_OptLayout CO_setOptLayoutString(CO_OptLayout arg, const char* string);

/*}}}  */
/*{{{  CO_Start accessors */

ATbool CO_isValidStart(CO_Start arg);
inline ATbool CO_isStartWrite(CO_Start arg);
inline ATbool CO_isStartRead(CO_Start arg);
inline ATbool CO_isStartArea(CO_Start arg);
inline ATbool CO_isStartLocation(CO_Start arg);
inline ATbool CO_isStartSubject(CO_Start arg);
inline ATbool CO_isStartError(CO_Start arg);
inline ATbool CO_isStartSummary(CO_Start arg);
inline ATbool CO_isStartByte(CO_Start arg);
inline ATbool CO_isStartBytes(CO_Start arg);
inline ATbool CO_isStartNatCon(CO_Start arg);
inline ATbool CO_isStartBoolCon(CO_Start arg);
inline ATbool CO_isStartEscaped(CO_Start arg);
inline ATbool CO_isStartNormal(CO_Start arg);
inline ATbool CO_isStartStrCon(CO_Start arg);
inline ATbool CO_isStartBoolean(CO_Start arg);
ATbool CO_hasStartWsBefore(CO_Start arg);
ATbool CO_hasStartTopWrite(CO_Start arg);
ATbool CO_hasStartWsAfter(CO_Start arg);
ATbool CO_hasStartAmbCnt(CO_Start arg);
ATbool CO_hasStartTopRead(CO_Start arg);
ATbool CO_hasStartTopArea(CO_Start arg);
ATbool CO_hasStartTopLocation(CO_Start arg);
ATbool CO_hasStartTopSubject(CO_Start arg);
ATbool CO_hasStartTopError(CO_Start arg);
ATbool CO_hasStartTopSummary(CO_Start arg);
ATbool CO_hasStartTopByte(CO_Start arg);
ATbool CO_hasStartTopBytes(CO_Start arg);
ATbool CO_hasStartTopNatCon(CO_Start arg);
ATbool CO_hasStartTopBoolCon(CO_Start arg);
ATbool CO_hasStartTopEscaped(CO_Start arg);
ATbool CO_hasStartTopNormal(CO_Start arg);
ATbool CO_hasStartTopStrCon(CO_Start arg);
ATbool CO_hasStartTopBoolean(CO_Start arg);
CO_OptLayout CO_getStartWsBefore(CO_Start arg);
CO_Write CO_getStartTopWrite(CO_Start arg);
CO_OptLayout CO_getStartWsAfter(CO_Start arg);
int CO_getStartAmbCnt(CO_Start arg);
CO_Read CO_getStartTopRead(CO_Start arg);
CO_Area CO_getStartTopArea(CO_Start arg);
CO_Location CO_getStartTopLocation(CO_Start arg);
CO_Subject CO_getStartTopSubject(CO_Start arg);
CO_Error CO_getStartTopError(CO_Start arg);
CO_Summary CO_getStartTopSummary(CO_Start arg);
CO_Byte CO_getStartTopByte(CO_Start arg);
CO_Bytes CO_getStartTopBytes(CO_Start arg);
CO_NatCon CO_getStartTopNatCon(CO_Start arg);
CO_BoolCon CO_getStartTopBoolCon(CO_Start arg);
CO_Escaped CO_getStartTopEscaped(CO_Start arg);
CO_Normal CO_getStartTopNormal(CO_Start arg);
CO_StrCon CO_getStartTopStrCon(CO_Start arg);
CO_Boolean CO_getStartTopBoolean(CO_Start arg);
CO_Start CO_setStartWsBefore(CO_Start arg, CO_OptLayout wsBefore);
CO_Start CO_setStartTopWrite(CO_Start arg, CO_Write topWrite);
CO_Start CO_setStartWsAfter(CO_Start arg, CO_OptLayout wsAfter);
CO_Start CO_setStartAmbCnt(CO_Start arg, int ambCnt);
CO_Start CO_setStartTopRead(CO_Start arg, CO_Read topRead);
CO_Start CO_setStartTopArea(CO_Start arg, CO_Area topArea);
CO_Start CO_setStartTopLocation(CO_Start arg, CO_Location topLocation);
CO_Start CO_setStartTopSubject(CO_Start arg, CO_Subject topSubject);
CO_Start CO_setStartTopError(CO_Start arg, CO_Error topError);
CO_Start CO_setStartTopSummary(CO_Start arg, CO_Summary topSummary);
CO_Start CO_setStartTopByte(CO_Start arg, CO_Byte topByte);
CO_Start CO_setStartTopBytes(CO_Start arg, CO_Bytes topBytes);
CO_Start CO_setStartTopNatCon(CO_Start arg, CO_NatCon topNatCon);
CO_Start CO_setStartTopBoolCon(CO_Start arg, CO_BoolCon topBoolCon);
CO_Start CO_setStartTopEscaped(CO_Start arg, CO_Escaped topEscaped);
CO_Start CO_setStartTopNormal(CO_Start arg, CO_Normal topNormal);
CO_Start CO_setStartTopStrCon(CO_Start arg, CO_StrCon topStrCon);
CO_Start CO_setStartTopBoolean(CO_Start arg, CO_Boolean topBoolean);

/*}}}  */
/*{{{  sort visitors */

CO_Boolean CO_visitBoolean(CO_Boolean arg, CO_BoolCon (*acceptBoolCon)(CO_BoolCon), CO_OptLayout (*acceptWsAfterLhs)(CO_OptLayout), CO_OptLayout (*acceptWsAfterBar)(CO_OptLayout), CO_OptLayout (*acceptWsAfterAmp)(CO_OptLayout), CO_OptLayout (*acceptWsAfterNot)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_OptLayout (*acceptWsAfterBoolean)(CO_OptLayout));
CO_Normal CO_visitNormal(CO_Normal arg, char* (*acceptString)(char*));
CO_Escaped CO_visitEscaped(CO_Escaped arg, char* (*acceptString)(char*));
CO_StrCon CO_visitStrCon(CO_StrCon arg, char* (*acceptString)(char*));
CO_BoolCon CO_visitBoolCon(CO_BoolCon arg);
CO_NatCon CO_visitNatCon(CO_NatCon arg, char* (*acceptString)(char*));
CO_Byte CO_visitByte(CO_Byte arg, char* (*acceptString)(char*));
CO_Bytes CO_visitBytes(CO_Bytes arg, char* (*acceptString)(char*));
CO_Subject CO_visitSubject(CO_Subject arg, CO_OptLayout (*acceptWsAfterSubject)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_StrCon (*acceptDescription)(CO_StrCon), CO_OptLayout (*acceptWsAfterDescription)(CO_OptLayout), CO_OptLayout (*acceptWsAfterLocalized)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma)(CO_OptLayout), CO_Location (*acceptLocation)(CO_Location), CO_OptLayout (*acceptWsAfterLocation)(CO_OptLayout));
CO_Error CO_visitError(CO_Error arg, CO_OptLayout (*acceptWsAfterInfo)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_StrCon (*acceptDescription)(CO_StrCon), CO_OptLayout (*acceptWsAfterDescription)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma)(CO_OptLayout), CO_OptLayout (*acceptWsAfterBracketOpen)(CO_OptLayout), CO_SubjectList (*acceptList)(CO_SubjectList), CO_OptLayout (*acceptWsAfterList)(CO_OptLayout), CO_OptLayout (*acceptWsAfterBracketClose)(CO_OptLayout), CO_OptLayout (*acceptWsAfterWarning)(CO_OptLayout), CO_OptLayout (*acceptWsAfterError)(CO_OptLayout), CO_OptLayout (*acceptWsAfterFatal)(CO_OptLayout));
CO_SubjectList CO_visitSubjectList(CO_SubjectList arg, CO_Subject (*acceptHead)(CO_Subject), CO_OptLayout (*acceptWsAfterHead)(CO_OptLayout), CO_OptLayout (*acceptWsAfterSep)(CO_OptLayout));
CO_Summary CO_visitSummary(CO_Summary arg, CO_OptLayout (*acceptWsAfterSummary)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_StrCon (*acceptProducer)(CO_StrCon), CO_OptLayout (*acceptWsAfterProducer)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma)(CO_OptLayout), CO_StrCon (*acceptId)(CO_StrCon), CO_OptLayout (*acceptWsAfterId)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma1)(CO_OptLayout), CO_OptLayout (*acceptWsAfterBracketOpen)(CO_OptLayout), CO_ErrorList (*acceptList)(CO_ErrorList), CO_OptLayout (*acceptWsAfterList)(CO_OptLayout), CO_OptLayout (*acceptWsAfterBracketClose)(CO_OptLayout));
CO_ErrorList CO_visitErrorList(CO_ErrorList arg, CO_Error (*acceptHead)(CO_Error), CO_OptLayout (*acceptWsAfterHead)(CO_OptLayout), CO_OptLayout (*acceptWsAfterSep)(CO_OptLayout));
CO_Location CO_visitLocation(CO_Location arg, CO_OptLayout (*acceptWsAfterFile)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_StrCon (*acceptFilename)(CO_StrCon), CO_OptLayout (*acceptWsAfterFilename)(CO_OptLayout), CO_OptLayout (*acceptWsAfterAreaInFile)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma)(CO_OptLayout), CO_Area (*acceptArea)(CO_Area), CO_OptLayout (*acceptWsAfterArea)(CO_OptLayout));
CO_Area CO_visitArea(CO_Area arg, CO_OptLayout (*acceptWsAfterArea)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_NatCon (*acceptBeginLine)(CO_NatCon), CO_OptLayout (*acceptWsAfterBeginLine)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma)(CO_OptLayout), CO_NatCon (*acceptBeginColumn)(CO_NatCon), CO_OptLayout (*acceptWsAfterBeginColumn)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma1)(CO_OptLayout), CO_NatCon (*acceptEndLine)(CO_NatCon), CO_OptLayout (*acceptWsAfterEndLine)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma2)(CO_OptLayout), CO_NatCon (*acceptEndColumn)(CO_NatCon), CO_OptLayout (*acceptWsAfterEndColumn)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma3)(CO_OptLayout), CO_NatCon (*acceptOffset)(CO_NatCon), CO_OptLayout (*acceptWsAfterOffset)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma4)(CO_OptLayout), CO_NatCon (*acceptLength)(CO_NatCon), CO_OptLayout (*acceptWsAfterLength)(CO_OptLayout));
CO_Read CO_visitRead(CO_Read arg, CO_OptLayout (*acceptWsAfterRead)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_Bytes (*acceptValue)(CO_Bytes), CO_OptLayout (*acceptWsAfterValue)(CO_OptLayout), CO_OptLayout (*acceptWsAfterReadError)(CO_OptLayout), CO_Summary (*acceptSummary)(CO_Summary), CO_OptLayout (*acceptWsAfterSummary)(CO_OptLayout));
CO_Write CO_visitWrite(CO_Write arg, CO_OptLayout (*acceptWsAfterWriteError)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_Summary (*acceptSummary)(CO_Summary), CO_OptLayout (*acceptWsAfterSummary)(CO_OptLayout));
CO_Parsetree CO_visitParsetree(CO_Parsetree arg, char* (*acceptTreeSort)(char*), char* (*acceptX)(char*), CO_OptLayout (*acceptWsAfterParseTree)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_Bytes (*acceptLeftLayout)(CO_Bytes), CO_OptLayout (*acceptWsAfterLeftLayout)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma)(CO_OptLayout), ATerm (*acceptTree)(ATerm), CO_OptLayout (*acceptWsAfterTree)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma1)(CO_OptLayout), CO_Bytes (*acceptRightLayout)(CO_Bytes), CO_OptLayout (*acceptWsAfterRightLayout)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma2)(CO_OptLayout), CO_NatCon (*acceptAmbCnt)(CO_NatCon), CO_OptLayout (*acceptWsAfterAmbCnt)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParseError)(CO_OptLayout), CO_Summary (*acceptSummary)(CO_Summary), CO_OptLayout (*acceptWsAfterSummary)(CO_OptLayout));
CO_OptLayout CO_visitOptLayout(CO_OptLayout arg, char* (*acceptString)(char*));
CO_Start CO_visitStart(CO_Start arg, CO_OptLayout (*acceptWsBefore)(CO_OptLayout), CO_Write (*acceptTopWrite)(CO_Write), CO_OptLayout (*acceptWsAfter)(CO_OptLayout), int (*acceptAmbCnt)(int), CO_Read (*acceptTopRead)(CO_Read), CO_Area (*acceptTopArea)(CO_Area), CO_Location (*acceptTopLocation)(CO_Location), CO_Subject (*acceptTopSubject)(CO_Subject), CO_Error (*acceptTopError)(CO_Error), CO_Summary (*acceptTopSummary)(CO_Summary), CO_Byte (*acceptTopByte)(CO_Byte), CO_Bytes (*acceptTopBytes)(CO_Bytes), CO_NatCon (*acceptTopNatCon)(CO_NatCon), CO_BoolCon (*acceptTopBoolCon)(CO_BoolCon), CO_Escaped (*acceptTopEscaped)(CO_Escaped), CO_Normal (*acceptTopNormal)(CO_Normal), CO_StrCon (*acceptTopStrCon)(CO_StrCon), CO_Boolean (*acceptTopBoolean)(CO_Boolean));

/*}}}  */

#endif /* _LIBRARY_H */
