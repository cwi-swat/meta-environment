#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "Library.h"

/*{{{  conversion functions */

ATerm CO_stringToChars(const char *str)
{
  int len = strlen(str);
  int i;
  ATermList result = ATempty;

  for (i = len - 1; i >= 0; i--) {
    result = ATinsert(result, (ATerm) ATmakeInt(str[i]));
  }

  return (ATerm) result;
}

ATerm CO_byteToChar(char ch)
{
    return (ATerm) ATmakeInt(ch);
}

char *CO_charsToString(ATerm arg)
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

char CO_charToByte(ATerm arg)
{
    return (char) ATgetInt((ATermInt) arg);
}


/*}}}  */

/*{{{  typedefs */

typedef struct ATerm _CO_OptLayout;
typedef struct ATerm _CO_Layout;
typedef struct ATerm _CO_LexLayoutList;
typedef struct ATerm _CO_LexLayout;
typedef struct ATerm _CO_Boolean;
typedef struct ATerm _CO_Start;
typedef struct ATerm _CO_LexStrChar;
typedef struct ATerm _CO_StrChar;
typedef struct ATerm _CO_LexStrCon;
typedef struct ATerm _CO_StrCon;
typedef struct ATerm _CO_LexStrCharLine;
typedef struct ATerm _CO_BoolCon;
typedef struct ATerm _CO_LexNatCon;
typedef struct ATerm _CO_NatCon;
typedef struct ATerm _CO_LexByte;
typedef struct ATerm _CO_Byte;
typedef struct ATerm _CO_LexBytes;
typedef struct ATerm _CO_Bytes;
typedef struct ATerm _CO_LexByteList;
typedef struct ATerm _CO_Subject;
typedef struct ATerm _CO_Error;
typedef struct ATerm _CO_Summary;
typedef struct ATerm _CO_SubjectList;
typedef struct ATerm _CO_ErrorList;
typedef struct ATerm _CO_Location;
typedef struct ATerm _CO_Area;
typedef struct ATerm _CO_Read;
typedef struct ATerm _CO_Write;
typedef struct ATerm _CO_ParsetreeX;
typedef struct ATerm _CO_X;

/*}}}  */

/*{{{  void CO_initLibraryApi(void) */

void CO_initLibraryApi(void)
{
  init_Library_dict();
}

/*}}}  */

/*{{{  protect functions */

void CO_protectOptLayout(CO_OptLayout *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CO_protectLayout(CO_Layout *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CO_protectLexLayoutList(CO_LexLayoutList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CO_protectLexLayout(CO_LexLayout *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CO_protectBoolean(CO_Boolean *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CO_protectStart(CO_Start *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CO_protectLexStrChar(CO_LexStrChar *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CO_protectStrChar(CO_StrChar *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CO_protectLexStrCon(CO_LexStrCon *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CO_protectStrCon(CO_StrCon *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CO_protectLexStrCharLine(CO_LexStrCharLine *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CO_protectBoolCon(CO_BoolCon *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CO_protectLexNatCon(CO_LexNatCon *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CO_protectNatCon(CO_NatCon *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CO_protectLexByte(CO_LexByte *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CO_protectByte(CO_Byte *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CO_protectLexBytes(CO_LexBytes *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CO_protectBytes(CO_Bytes *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CO_protectLexByteList(CO_LexByteList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CO_protectSubject(CO_Subject *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CO_protectError(CO_Error *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CO_protectSummary(CO_Summary *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CO_protectSubjectList(CO_SubjectList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CO_protectErrorList(CO_ErrorList *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CO_protectLocation(CO_Location *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CO_protectArea(CO_Area *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CO_protectRead(CO_Read *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CO_protectWrite(CO_Write *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CO_protectParsetreeX(CO_ParsetreeX *arg)
{
  ATprotect((ATerm*)((void*) arg));
}

void CO_protectX(CO_X *arg)
{
  ATprotect((ATerm*)((void*) arg));
}


/*}}}  */
/*{{{  term conversion functions */

/*{{{  CO_OptLayout CO_OptLayoutFromTerm(ATerm t) */

CO_OptLayout CO_OptLayoutFromTerm(ATerm t)
{
  return (CO_OptLayout)t;
}

/*}}}  */
/*{{{  ATerm CO_OptLayoutToTerm(CO_OptLayout arg) */

ATerm CO_OptLayoutToTerm(CO_OptLayout arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CO_Layout CO_LayoutFromTerm(ATerm t) */

CO_Layout CO_LayoutFromTerm(ATerm t)
{
  return (CO_Layout)t;
}

/*}}}  */
/*{{{  ATerm CO_LayoutToTerm(CO_Layout arg) */

ATerm CO_LayoutToTerm(CO_Layout arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CO_LexLayoutList CO_LexLayoutListFromTerm(ATerm t) */

CO_LexLayoutList CO_LexLayoutListFromTerm(ATerm t)
{
  return (CO_LexLayoutList)t;
}

/*}}}  */
/*{{{  ATerm CO_LexLayoutListToTerm(CO_LexLayoutList arg) */

ATerm CO_LexLayoutListToTerm(CO_LexLayoutList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CO_LexLayout CO_LexLayoutFromTerm(ATerm t) */

CO_LexLayout CO_LexLayoutFromTerm(ATerm t)
{
  return (CO_LexLayout)t;
}

/*}}}  */
/*{{{  ATerm CO_LexLayoutToTerm(CO_LexLayout arg) */

ATerm CO_LexLayoutToTerm(CO_LexLayout arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CO_Boolean CO_BooleanFromTerm(ATerm t) */

CO_Boolean CO_BooleanFromTerm(ATerm t)
{
  return (CO_Boolean)t;
}

/*}}}  */
/*{{{  ATerm CO_BooleanToTerm(CO_Boolean arg) */

ATerm CO_BooleanToTerm(CO_Boolean arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CO_Start CO_StartFromTerm(ATerm t) */

CO_Start CO_StartFromTerm(ATerm t)
{
  return (CO_Start)t;
}

/*}}}  */
/*{{{  ATerm CO_StartToTerm(CO_Start arg) */

ATerm CO_StartToTerm(CO_Start arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CO_LexStrChar CO_LexStrCharFromTerm(ATerm t) */

CO_LexStrChar CO_LexStrCharFromTerm(ATerm t)
{
  return (CO_LexStrChar)t;
}

/*}}}  */
/*{{{  ATerm CO_LexStrCharToTerm(CO_LexStrChar arg) */

ATerm CO_LexStrCharToTerm(CO_LexStrChar arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CO_StrChar CO_StrCharFromTerm(ATerm t) */

CO_StrChar CO_StrCharFromTerm(ATerm t)
{
  return (CO_StrChar)t;
}

/*}}}  */
/*{{{  ATerm CO_StrCharToTerm(CO_StrChar arg) */

ATerm CO_StrCharToTerm(CO_StrChar arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CO_LexStrCon CO_LexStrConFromTerm(ATerm t) */

CO_LexStrCon CO_LexStrConFromTerm(ATerm t)
{
  return (CO_LexStrCon)t;
}

/*}}}  */
/*{{{  ATerm CO_LexStrConToTerm(CO_LexStrCon arg) */

ATerm CO_LexStrConToTerm(CO_LexStrCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CO_StrCon CO_StrConFromTerm(ATerm t) */

CO_StrCon CO_StrConFromTerm(ATerm t)
{
  return (CO_StrCon)t;
}

/*}}}  */
/*{{{  ATerm CO_StrConToTerm(CO_StrCon arg) */

ATerm CO_StrConToTerm(CO_StrCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CO_LexStrCharLine CO_LexStrCharLineFromTerm(ATerm t) */

CO_LexStrCharLine CO_LexStrCharLineFromTerm(ATerm t)
{
  return (CO_LexStrCharLine)t;
}

/*}}}  */
/*{{{  ATerm CO_LexStrCharLineToTerm(CO_LexStrCharLine arg) */

ATerm CO_LexStrCharLineToTerm(CO_LexStrCharLine arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CO_BoolCon CO_BoolConFromTerm(ATerm t) */

CO_BoolCon CO_BoolConFromTerm(ATerm t)
{
  return (CO_BoolCon)t;
}

/*}}}  */
/*{{{  ATerm CO_BoolConToTerm(CO_BoolCon arg) */

ATerm CO_BoolConToTerm(CO_BoolCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CO_LexNatCon CO_LexNatConFromTerm(ATerm t) */

CO_LexNatCon CO_LexNatConFromTerm(ATerm t)
{
  return (CO_LexNatCon)t;
}

/*}}}  */
/*{{{  ATerm CO_LexNatConToTerm(CO_LexNatCon arg) */

ATerm CO_LexNatConToTerm(CO_LexNatCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CO_NatCon CO_NatConFromTerm(ATerm t) */

CO_NatCon CO_NatConFromTerm(ATerm t)
{
  return (CO_NatCon)t;
}

/*}}}  */
/*{{{  ATerm CO_NatConToTerm(CO_NatCon arg) */

ATerm CO_NatConToTerm(CO_NatCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CO_LexByte CO_LexByteFromTerm(ATerm t) */

CO_LexByte CO_LexByteFromTerm(ATerm t)
{
  return (CO_LexByte)t;
}

/*}}}  */
/*{{{  ATerm CO_LexByteToTerm(CO_LexByte arg) */

ATerm CO_LexByteToTerm(CO_LexByte arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CO_Byte CO_ByteFromTerm(ATerm t) */

CO_Byte CO_ByteFromTerm(ATerm t)
{
  return (CO_Byte)t;
}

/*}}}  */
/*{{{  ATerm CO_ByteToTerm(CO_Byte arg) */

ATerm CO_ByteToTerm(CO_Byte arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CO_LexBytes CO_LexBytesFromTerm(ATerm t) */

CO_LexBytes CO_LexBytesFromTerm(ATerm t)
{
  return (CO_LexBytes)t;
}

/*}}}  */
/*{{{  ATerm CO_LexBytesToTerm(CO_LexBytes arg) */

ATerm CO_LexBytesToTerm(CO_LexBytes arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CO_Bytes CO_BytesFromTerm(ATerm t) */

CO_Bytes CO_BytesFromTerm(ATerm t)
{
  return (CO_Bytes)t;
}

/*}}}  */
/*{{{  ATerm CO_BytesToTerm(CO_Bytes arg) */

ATerm CO_BytesToTerm(CO_Bytes arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CO_LexByteList CO_LexByteListFromTerm(ATerm t) */

CO_LexByteList CO_LexByteListFromTerm(ATerm t)
{
  return (CO_LexByteList)t;
}

/*}}}  */
/*{{{  ATerm CO_LexByteListToTerm(CO_LexByteList arg) */

ATerm CO_LexByteListToTerm(CO_LexByteList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CO_Subject CO_SubjectFromTerm(ATerm t) */

CO_Subject CO_SubjectFromTerm(ATerm t)
{
  return (CO_Subject)t;
}

/*}}}  */
/*{{{  ATerm CO_SubjectToTerm(CO_Subject arg) */

ATerm CO_SubjectToTerm(CO_Subject arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CO_Error CO_ErrorFromTerm(ATerm t) */

CO_Error CO_ErrorFromTerm(ATerm t)
{
  return (CO_Error)t;
}

/*}}}  */
/*{{{  ATerm CO_ErrorToTerm(CO_Error arg) */

ATerm CO_ErrorToTerm(CO_Error arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CO_Summary CO_SummaryFromTerm(ATerm t) */

CO_Summary CO_SummaryFromTerm(ATerm t)
{
  return (CO_Summary)t;
}

/*}}}  */
/*{{{  ATerm CO_SummaryToTerm(CO_Summary arg) */

ATerm CO_SummaryToTerm(CO_Summary arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CO_SubjectList CO_SubjectListFromTerm(ATerm t) */

CO_SubjectList CO_SubjectListFromTerm(ATerm t)
{
  return (CO_SubjectList)t;
}

/*}}}  */
/*{{{  ATerm CO_SubjectListToTerm(CO_SubjectList arg) */

ATerm CO_SubjectListToTerm(CO_SubjectList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CO_ErrorList CO_ErrorListFromTerm(ATerm t) */

CO_ErrorList CO_ErrorListFromTerm(ATerm t)
{
  return (CO_ErrorList)t;
}

/*}}}  */
/*{{{  ATerm CO_ErrorListToTerm(CO_ErrorList arg) */

ATerm CO_ErrorListToTerm(CO_ErrorList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CO_Location CO_LocationFromTerm(ATerm t) */

CO_Location CO_LocationFromTerm(ATerm t)
{
  return (CO_Location)t;
}

/*}}}  */
/*{{{  ATerm CO_LocationToTerm(CO_Location arg) */

ATerm CO_LocationToTerm(CO_Location arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CO_Area CO_AreaFromTerm(ATerm t) */

CO_Area CO_AreaFromTerm(ATerm t)
{
  return (CO_Area)t;
}

/*}}}  */
/*{{{  ATerm CO_AreaToTerm(CO_Area arg) */

ATerm CO_AreaToTerm(CO_Area arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CO_Read CO_ReadFromTerm(ATerm t) */

CO_Read CO_ReadFromTerm(ATerm t)
{
  return (CO_Read)t;
}

/*}}}  */
/*{{{  ATerm CO_ReadToTerm(CO_Read arg) */

ATerm CO_ReadToTerm(CO_Read arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CO_Write CO_WriteFromTerm(ATerm t) */

CO_Write CO_WriteFromTerm(ATerm t)
{
  return (CO_Write)t;
}

/*}}}  */
/*{{{  ATerm CO_WriteToTerm(CO_Write arg) */

ATerm CO_WriteToTerm(CO_Write arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CO_ParsetreeX CO_ParsetreeXFromTerm(ATerm t) */

CO_ParsetreeX CO_ParsetreeXFromTerm(ATerm t)
{
  return (CO_ParsetreeX)t;
}

/*}}}  */
/*{{{  ATerm CO_ParsetreeXToTerm(CO_ParsetreeX arg) */

ATerm CO_ParsetreeXToTerm(CO_ParsetreeX arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  CO_X CO_XFromTerm(ATerm t) */

CO_X CO_XFromTerm(ATerm t)
{
  return (CO_X)t;
}

/*}}}  */
/*{{{  ATerm CO_XToTerm(CO_X arg) */

ATerm CO_XToTerm(CO_X arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*}}}  */
/*{{{  list functions */

int CO_getLexLayoutListLength (CO_LexLayoutList arg) {
  return ATgetLength((ATermList) arg);
}
CO_LexLayoutList CO_reverseLexLayoutList(CO_LexLayoutList arg) {
  return (CO_LexLayoutList) ATreverse((ATermList) arg);
}
CO_LexLayoutList CO_appendLexLayoutList(CO_LexLayoutList arg, CO_LexLayout elem) {
  return (CO_LexLayoutList) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}
CO_LexLayoutList CO_concatLexLayoutList(CO_LexLayoutList arg0, CO_LexLayoutList arg1) {
  return (CO_LexLayoutList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
CO_LexLayoutList CO_sliceLexLayoutList(CO_LexLayoutList arg, int start, int end) {
  return (CO_LexLayoutList) ATgetSlice((ATermList) arg, start, end);
}
CO_LexLayout CO_getLexLayoutListLexLayoutAt(CO_LexLayoutList arg, int index) {
 return (CO_LexLayout)ATelementAt((ATermList) arg,index);
}
CO_LexLayoutList CO_replaceLexLayoutListLexLayoutAt(CO_LexLayoutList arg, CO_LexLayout elem, int index) {
 return (CO_LexLayoutList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}
CO_LexLayoutList CO_makeLexLayoutList2(CO_LexLayout elem1, CO_LexLayout elem2) {
  return (CO_LexLayoutList) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}
CO_LexLayoutList CO_makeLexLayoutList3(CO_LexLayout elem1, CO_LexLayout elem2, CO_LexLayout elem3) {
  return (CO_LexLayoutList) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}
CO_LexLayoutList CO_makeLexLayoutList4(CO_LexLayout elem1, CO_LexLayout elem2, CO_LexLayout elem3, CO_LexLayout elem4) {
  return (CO_LexLayoutList) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}
CO_LexLayoutList CO_makeLexLayoutList5(CO_LexLayout elem1, CO_LexLayout elem2, CO_LexLayout elem3, CO_LexLayout elem4, CO_LexLayout elem5) {
  return (CO_LexLayoutList) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}
CO_LexLayoutList CO_makeLexLayoutList6(CO_LexLayout elem1, CO_LexLayout elem2, CO_LexLayout elem3, CO_LexLayout elem4, CO_LexLayout elem5, CO_LexLayout elem6) {
  return (CO_LexLayoutList) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}
int CO_getLexStrCharLineLength (CO_LexStrCharLine arg) {
  return ATgetLength((ATermList) arg);
}
CO_LexStrCharLine CO_reverseLexStrCharLine(CO_LexStrCharLine arg) {
  return (CO_LexStrCharLine) ATreverse((ATermList) arg);
}
CO_LexStrCharLine CO_appendLexStrCharLine(CO_LexStrCharLine arg, CO_LexStrChar elem) {
  return (CO_LexStrCharLine) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}
CO_LexStrCharLine CO_concatLexStrCharLine(CO_LexStrCharLine arg0, CO_LexStrCharLine arg1) {
  return (CO_LexStrCharLine) ATconcat((ATermList) arg0, (ATermList) arg1);
}
CO_LexStrCharLine CO_sliceLexStrCharLine(CO_LexStrCharLine arg, int start, int end) {
  return (CO_LexStrCharLine) ATgetSlice((ATermList) arg, start, end);
}
CO_LexStrChar CO_getLexStrCharLineLexStrCharAt(CO_LexStrCharLine arg, int index) {
 return (CO_LexStrChar)ATelementAt((ATermList) arg,index);
}
CO_LexStrCharLine CO_replaceLexStrCharLineLexStrCharAt(CO_LexStrCharLine arg, CO_LexStrChar elem, int index) {
 return (CO_LexStrCharLine) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}
CO_LexStrCharLine CO_makeLexStrCharLine2(CO_LexStrChar elem1, CO_LexStrChar elem2) {
  return (CO_LexStrCharLine) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}
CO_LexStrCharLine CO_makeLexStrCharLine3(CO_LexStrChar elem1, CO_LexStrChar elem2, CO_LexStrChar elem3) {
  return (CO_LexStrCharLine) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}
CO_LexStrCharLine CO_makeLexStrCharLine4(CO_LexStrChar elem1, CO_LexStrChar elem2, CO_LexStrChar elem3, CO_LexStrChar elem4) {
  return (CO_LexStrCharLine) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}
CO_LexStrCharLine CO_makeLexStrCharLine5(CO_LexStrChar elem1, CO_LexStrChar elem2, CO_LexStrChar elem3, CO_LexStrChar elem4, CO_LexStrChar elem5) {
  return (CO_LexStrCharLine) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}
CO_LexStrCharLine CO_makeLexStrCharLine6(CO_LexStrChar elem1, CO_LexStrChar elem2, CO_LexStrChar elem3, CO_LexStrChar elem4, CO_LexStrChar elem5, CO_LexStrChar elem6) {
  return (CO_LexStrCharLine) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}
int CO_getLexByteListLength (CO_LexByteList arg) {
  return ATgetLength((ATermList) arg);
}
CO_LexByteList CO_reverseLexByteList(CO_LexByteList arg) {
  return (CO_LexByteList) ATreverse((ATermList) arg);
}
CO_LexByteList CO_appendLexByteList(CO_LexByteList arg, CO_LexByte elem) {
  return (CO_LexByteList) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}
CO_LexByteList CO_concatLexByteList(CO_LexByteList arg0, CO_LexByteList arg1) {
  return (CO_LexByteList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
CO_LexByteList CO_sliceLexByteList(CO_LexByteList arg, int start, int end) {
  return (CO_LexByteList) ATgetSlice((ATermList) arg, start, end);
}
CO_LexByte CO_getLexByteListLexByteAt(CO_LexByteList arg, int index) {
 return (CO_LexByte)ATelementAt((ATermList) arg,index);
}
CO_LexByteList CO_replaceLexByteListLexByteAt(CO_LexByteList arg, CO_LexByte elem, int index) {
 return (CO_LexByteList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}
CO_LexByteList CO_makeLexByteList2(CO_LexByte elem1, CO_LexByte elem2) {
  return (CO_LexByteList) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}
CO_LexByteList CO_makeLexByteList3(CO_LexByte elem1, CO_LexByte elem2, CO_LexByte elem3) {
  return (CO_LexByteList) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}
CO_LexByteList CO_makeLexByteList4(CO_LexByte elem1, CO_LexByte elem2, CO_LexByte elem3, CO_LexByte elem4) {
  return (CO_LexByteList) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}
CO_LexByteList CO_makeLexByteList5(CO_LexByte elem1, CO_LexByte elem2, CO_LexByte elem3, CO_LexByte elem4, CO_LexByte elem5) {
  return (CO_LexByteList) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}
CO_LexByteList CO_makeLexByteList6(CO_LexByte elem1, CO_LexByte elem2, CO_LexByte elem3, CO_LexByte elem4, CO_LexByte elem5, CO_LexByte elem6) {
  return (CO_LexByteList) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}
int CO_getSubjectListLength (CO_SubjectList arg) {
  if (ATisEmpty((ATermList) arg)) {
    return 0;
  }
  return (ATgetLength((ATermList) arg) / 4) + 1;
}
CO_SubjectList CO_reverseSubjectList(CO_SubjectList arg) {
  ATermList list = (ATermList) arg;
  ATerm head;
  ATerm sep0;
  ATerm sep1;
  ATerm sep2;
  ATermList result;

 if (ATisEmpty(list) || ATgetLength(list) == 1) {
    return arg;
  }

  result = ATmakeList1(ATgetFirst(list));
      list = ATgetNext(list);
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);

  while (!ATisEmpty(list)) {
    result = ATinsert(result, sep2);
    result = ATinsert(result, sep1);
    result = ATinsert(result, sep0);

   head = ATgetFirst(list);
   result = ATinsert(result, head);
    list = ATgetNext(list);

   if (!ATisEmpty(list)) {
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);
   }
  }

  return (CO_SubjectList) result;
}
CO_SubjectList CO_appendSubjectList(CO_SubjectList arg0, CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Subject arg1) {
  return CO_concatSubjectList(arg0, wsAfterHead, wsAfterSep, CO_makeSubjectListSingle(arg1));
}
CO_SubjectList CO_concatSubjectList(CO_SubjectList arg0, CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_SubjectList arg1) {
  if (ATisEmpty((ATermList) arg0)) {
    return arg1;
  }
  arg1 = CO_makeSubjectListMany((CO_Subject)ATgetFirst((ATermList) arg0), wsAfterHead, wsAfterSep,  arg1);
  arg1 = (CO_SubjectList) ATgetNext((ATermList) arg1);
  return (CO_SubjectList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
CO_SubjectList CO_sliceSubjectList(CO_SubjectList arg, int start, int end) {
  return (CO_SubjectList) ATgetSlice((ATermList) arg, start * 4, end * 4);
}
CO_Subject CO_getSubjectListSubjectAt(CO_SubjectList arg, int index) {
 return (CO_Subject)ATelementAt((ATermList) arg,index * 4);
}
CO_SubjectList CO_replaceSubjectListSubjectAt(CO_SubjectList arg, CO_Subject elem, int index) {
 return (CO_SubjectList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index * 4);
}
CO_SubjectList CO_makeSubjectList2(CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Subject elem1, CO_Subject elem2) {
  return CO_makeSubjectListMany(elem1, wsAfterHead, wsAfterSep, CO_makeSubjectListSingle(elem2));
}
CO_SubjectList CO_makeSubjectList3(CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Subject elem1, CO_Subject elem2, CO_Subject elem3) {
  return CO_makeSubjectListMany(elem1, wsAfterHead, wsAfterSep, CO_makeSubjectList2(wsAfterHead, wsAfterSep, elem2, elem3));
}
CO_SubjectList CO_makeSubjectList4(CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Subject elem1, CO_Subject elem2, CO_Subject elem3, CO_Subject elem4) {
  return CO_makeSubjectListMany(elem1, wsAfterHead, wsAfterSep, CO_makeSubjectList3(wsAfterHead, wsAfterSep, elem2, elem3, elem4));
}
CO_SubjectList CO_makeSubjectList5(CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Subject elem1, CO_Subject elem2, CO_Subject elem3, CO_Subject elem4, CO_Subject elem5) {
  return CO_makeSubjectListMany(elem1, wsAfterHead, wsAfterSep, CO_makeSubjectList4(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5));
}
CO_SubjectList CO_makeSubjectList6(CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Subject elem1, CO_Subject elem2, CO_Subject elem3, CO_Subject elem4, CO_Subject elem5, CO_Subject elem6) {
  return CO_makeSubjectListMany(elem1, wsAfterHead, wsAfterSep, CO_makeSubjectList5(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5, elem6));
}
int CO_getErrorListLength (CO_ErrorList arg) {
  if (ATisEmpty((ATermList) arg)) {
    return 0;
  }
  return (ATgetLength((ATermList) arg) / 4) + 1;
}
CO_ErrorList CO_reverseErrorList(CO_ErrorList arg) {
  ATermList list = (ATermList) arg;
  ATerm head;
  ATerm sep0;
  ATerm sep1;
  ATerm sep2;
  ATermList result;

 if (ATisEmpty(list) || ATgetLength(list) == 1) {
    return arg;
  }

  result = ATmakeList1(ATgetFirst(list));
      list = ATgetNext(list);
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);

  while (!ATisEmpty(list)) {
    result = ATinsert(result, sep2);
    result = ATinsert(result, sep1);
    result = ATinsert(result, sep0);

   head = ATgetFirst(list);
   result = ATinsert(result, head);
    list = ATgetNext(list);

   if (!ATisEmpty(list)) {
  sep0 = ATgetFirst(list);
  list = ATgetNext(list);
  sep1 = ATgetFirst(list);
  list = ATgetNext(list);
  sep2 = ATgetFirst(list);
  list = ATgetNext(list);
   }
  }

  return (CO_ErrorList) result;
}
CO_ErrorList CO_appendErrorList(CO_ErrorList arg0, CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Error arg1) {
  return CO_concatErrorList(arg0, wsAfterHead, wsAfterSep, CO_makeErrorListSingle(arg1));
}
CO_ErrorList CO_concatErrorList(CO_ErrorList arg0, CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_ErrorList arg1) {
  if (ATisEmpty((ATermList) arg0)) {
    return arg1;
  }
  arg1 = CO_makeErrorListMany((CO_Error)ATgetFirst((ATermList) arg0), wsAfterHead, wsAfterSep,  arg1);
  arg1 = (CO_ErrorList) ATgetNext((ATermList) arg1);
  return (CO_ErrorList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
CO_ErrorList CO_sliceErrorList(CO_ErrorList arg, int start, int end) {
  return (CO_ErrorList) ATgetSlice((ATermList) arg, start * 4, end * 4);
}
CO_Error CO_getErrorListErrorAt(CO_ErrorList arg, int index) {
 return (CO_Error)ATelementAt((ATermList) arg,index * 4);
}
CO_ErrorList CO_replaceErrorListErrorAt(CO_ErrorList arg, CO_Error elem, int index) {
 return (CO_ErrorList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index * 4);
}
CO_ErrorList CO_makeErrorList2(CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Error elem1, CO_Error elem2) {
  return CO_makeErrorListMany(elem1, wsAfterHead, wsAfterSep, CO_makeErrorListSingle(elem2));
}
CO_ErrorList CO_makeErrorList3(CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Error elem1, CO_Error elem2, CO_Error elem3) {
  return CO_makeErrorListMany(elem1, wsAfterHead, wsAfterSep, CO_makeErrorList2(wsAfterHead, wsAfterSep, elem2, elem3));
}
CO_ErrorList CO_makeErrorList4(CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Error elem1, CO_Error elem2, CO_Error elem3, CO_Error elem4) {
  return CO_makeErrorListMany(elem1, wsAfterHead, wsAfterSep, CO_makeErrorList3(wsAfterHead, wsAfterSep, elem2, elem3, elem4));
}
CO_ErrorList CO_makeErrorList5(CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Error elem1, CO_Error elem2, CO_Error elem3, CO_Error elem4, CO_Error elem5) {
  return CO_makeErrorListMany(elem1, wsAfterHead, wsAfterSep, CO_makeErrorList4(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5));
}
CO_ErrorList CO_makeErrorList6(CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_Error elem1, CO_Error elem2, CO_Error elem3, CO_Error elem4, CO_Error elem5, CO_Error elem6) {
  return CO_makeErrorListMany(elem1, wsAfterHead, wsAfterSep, CO_makeErrorList5(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5, elem6));
}

/*}}}  */
/*{{{  constructors */

/*{{{  CO_OptLayout CO_makeOptLayoutAbsent(void) */

CO_OptLayout CO_makeOptLayoutAbsent(void)
{
  return (CO_OptLayout)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATempty, (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4))), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATempty);
}

/*}}}  */
/*{{{  CO_OptLayout CO_makeOptLayoutPresent(CO_Layout layout) */

CO_OptLayout CO_makeOptLayoutPresent(CO_Layout layout)
{
  return (CO_OptLayout)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun4))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4))), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm) layout));
}

/*}}}  */
/*{{{  CO_Layout CO_makeLayoutLexToCf(CO_LexLayoutList list) */

CO_Layout CO_makeLayoutLexToCf(CO_LexLayoutList list)
{
  return (CO_Layout)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun7, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl0(CO_afun4)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl1(CO_afun8, (ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun7, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm) list)));
}

/*}}}  */
/*{{{  CO_LexLayoutList CO_makeLexLayoutListEmpty(void) */

CO_LexLayoutList CO_makeLexLayoutListEmpty(void)
{
  return (CO_LexLayoutList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  CO_LexLayoutList CO_makeLexLayoutListSingle(CO_LexLayout head) */

CO_LexLayoutList CO_makeLexLayoutListSingle(CO_LexLayout head)
{
  return (CO_LexLayoutList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  CO_LexLayoutList CO_makeLexLayoutListMany(CO_LexLayout head, CO_LexLayoutList tail) */

CO_LexLayoutList CO_makeLexLayoutListMany(CO_LexLayout head, CO_LexLayoutList tail)
{
  return (CO_LexLayoutList)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/*}}}  */
/*{{{  CO_LexLayout CO_makeLexLayoutWhitespace(char ch) */

CO_LexLayout CO_makeLexLayoutWhitespace(char ch)
{
  return (CO_LexLayout)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(32)), (ATerm)ATmakeInt(13)), (ATerm)ATmakeAppl2(CO_afun10, (ATerm)ATmakeInt(9), (ATerm)ATmakeInt(10))))), (ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl0(CO_afun4)), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun14)))))), (ATerm)ATmakeList1((ATerm) ((ATerm) CO_byteToChar(ch))));
}

/*}}}  */
/*{{{  CO_Boolean CO_makeBooleanConstant(CO_BoolCon BoolCon) */

CO_Boolean CO_makeBooleanConstant(CO_BoolCon BoolCon)
{
  return (CO_Boolean)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun16)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun17))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun18)))))), (ATerm)ATmakeList1((ATerm) BoolCon));
}

/*}}}  */
/*{{{  CO_Boolean CO_makeBooleanOr(CO_Boolean lhs, CO_OptLayout wsAfterLhs, CO_OptLayout wsAfterBar, CO_Boolean rhs) */

CO_Boolean CO_makeBooleanOr(CO_Boolean lhs, CO_OptLayout wsAfterLhs, CO_OptLayout wsAfterBar, CO_Boolean rhs)
{
  return (CO_Boolean)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun17)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun20))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun17)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun17))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun21)))), (ATerm)ATmakeAppl1(CO_afun22, (ATerm)ATmakeAppl0(CO_afun23))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) rhs), (ATerm) wsAfterBar), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(124)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun20)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(124)))), (ATerm) wsAfterLhs), (ATerm) lhs));
}

/*}}}  */
/*{{{  CO_Boolean CO_makeBooleanAnd(CO_Boolean lhs, CO_OptLayout wsAfterLhs, CO_OptLayout wsAfterAmp, CO_Boolean rhs) */

CO_Boolean CO_makeBooleanAnd(CO_Boolean lhs, CO_OptLayout wsAfterLhs, CO_OptLayout wsAfterAmp, CO_Boolean rhs)
{
  return (CO_Boolean)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun17)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun24))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun17)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun17))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun25)))), (ATerm)ATmakeAppl1(CO_afun22, (ATerm)ATmakeAppl0(CO_afun23))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) rhs), (ATerm) wsAfterAmp), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(38)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun24)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(38)))), (ATerm) wsAfterLhs), (ATerm) lhs));
}

/*}}}  */
/*{{{  CO_Boolean CO_makeBooleanNot(CO_OptLayout wsAfterNot, CO_OptLayout wsAfterParenOpen, CO_Boolean Boolean, CO_OptLayout wsAfterBoolean) */

CO_Boolean CO_makeBooleanNot(CO_OptLayout wsAfterNot, CO_OptLayout wsAfterParenOpen, CO_Boolean Boolean, CO_OptLayout wsAfterBoolean)
{
  return (CO_Boolean)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun26))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun17)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun27))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun28))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun17))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun28)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun26)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterBoolean), (ATerm) Boolean), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun27)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterNot), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(110)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun28)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(111)), (ATerm)ATmakeInt(110)))));
}

/*}}}  */
/*{{{  CO_Boolean CO_makeBooleanBracket(CO_OptLayout wsAfterParenOpen, CO_Boolean Boolean, CO_OptLayout wsAfterBoolean) */

CO_Boolean CO_makeBooleanBracket(CO_OptLayout wsAfterParenOpen, CO_Boolean Boolean, CO_OptLayout wsAfterBoolean)
{
  return (CO_Boolean)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun26))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun17)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun27))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun17))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun29)))), (ATerm)ATmakeAppl0(CO_afun30)))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun26)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterBoolean), (ATerm) Boolean), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun27)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))));
}

/*}}}  */
/*{{{  CO_Start CO_makeStartBoolean(CO_OptLayout wsBefore, CO_Boolean topBoolean, CO_OptLayout wsAfter, int ambCnt) */

CO_Start CO_makeStartBoolean(CO_OptLayout wsBefore, CO_Boolean topBoolean, CO_OptLayout wsAfter, int ambCnt)
{
  return (CO_Start)(ATerm)ATmakeAppl2(CO_afun31, (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun17))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun32)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topBoolean), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  CO_Start CO_makeStartStrCon(CO_OptLayout wsBefore, CO_StrCon topStrCon, CO_OptLayout wsAfter, int ambCnt) */

CO_Start CO_makeStartStrCon(CO_OptLayout wsBefore, CO_StrCon topStrCon, CO_OptLayout wsAfter, int ambCnt)
{
  return (CO_Start)(ATerm)ATmakeAppl2(CO_afun31, (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun33))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun32)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topStrCon), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  CO_Start CO_makeStartBoolCon(CO_OptLayout wsBefore, CO_BoolCon topBoolCon, CO_OptLayout wsAfter, int ambCnt) */

CO_Start CO_makeStartBoolCon(CO_OptLayout wsBefore, CO_BoolCon topBoolCon, CO_OptLayout wsAfter, int ambCnt)
{
  return (CO_Start)(ATerm)ATmakeAppl2(CO_afun31, (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun16))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun32)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topBoolCon), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  CO_Start CO_makeStartSummary(CO_OptLayout wsBefore, CO_Summary topSummary, CO_OptLayout wsAfter, int ambCnt) */

CO_Start CO_makeStartSummary(CO_OptLayout wsBefore, CO_Summary topSummary, CO_OptLayout wsAfter, int ambCnt)
{
  return (CO_Start)(ATerm)ATmakeAppl2(CO_afun31, (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun34))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun32)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topSummary), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  CO_Start CO_makeStartError(CO_OptLayout wsBefore, CO_Error topError, CO_OptLayout wsAfter, int ambCnt) */

CO_Start CO_makeStartError(CO_OptLayout wsBefore, CO_Error topError, CO_OptLayout wsAfter, int ambCnt)
{
  return (CO_Start)(ATerm)ATmakeAppl2(CO_afun31, (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun35))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun32)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topError), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  CO_LexStrChar CO_makeLexStrCharNewline(void) */

CO_LexStrChar CO_makeLexStrCharNewline(void)
{
  return (CO_LexStrChar)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun36))), (ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun37))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun38)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(110)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun36)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(110)), (ATerm)ATmakeInt(92)))));
}

/*}}}  */
/*{{{  CO_LexStrChar CO_makeLexStrCharTab(void) */

CO_LexStrChar CO_makeLexStrCharTab(void)
{
  return (CO_LexStrChar)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun39))), (ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun37))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun40)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun39)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(92)))));
}

/*}}}  */
/*{{{  CO_LexStrChar CO_makeLexStrCharQuote(void) */

CO_LexStrChar CO_makeLexStrCharQuote(void)
{
  return (CO_LexStrChar)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun41))), (ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun37))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun42)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(34)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun41)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(34)), (ATerm)ATmakeInt(92)))));
}

/*}}}  */
/*{{{  CO_LexStrChar CO_makeLexStrCharBackslash(void) */

CO_LexStrChar CO_makeLexStrCharBackslash(void)
{
  return (CO_LexStrChar)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun43))), (ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun37))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun44)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun43)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATmakeList1((ATerm)ATmakeInt(92)), (ATerm)ATmakeInt(92)))));
}

/*}}}  */
/*{{{  CO_LexStrChar CO_makeLexStrCharOctal(char a, char b, char c) */

CO_LexStrChar CO_makeLexStrCharOctal(char a, char b, char c)
{
  return (CO_LexStrChar)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(CO_afun10, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(55))))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(CO_afun10, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(55))))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(CO_afun10, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(55))))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun45))), (ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun37))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun46)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm) ((ATerm) CO_byteToChar(c))), (ATerm) ((ATerm) CO_byteToChar(b))), (ATerm) ((ATerm) CO_byteToChar(a))), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun45)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(92)))));
}

/*}}}  */
/*{{{  CO_LexStrChar CO_makeLexStrCharNormal(char ch) */

CO_LexStrChar CO_makeLexStrCharNormal(char ch)
{
  return (CO_LexStrChar)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(CO_afun10, (ATerm)ATmakeInt(93), (ATerm)ATmakeInt(255))), (ATerm)ATmakeAppl2(CO_afun10, (ATerm)ATmakeInt(35), (ATerm)ATmakeInt(91))), (ATerm)ATmakeAppl2(CO_afun10, (ATerm)ATmakeInt(32), (ATerm)ATmakeInt(33))))), (ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun37))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun47)))))), (ATerm)ATmakeList1((ATerm) ((ATerm) CO_byteToChar(ch))));
}

/*}}}  */
/*{{{  CO_StrChar CO_makeStrCharLexToCf(CO_LexStrChar StrChar) */

CO_StrChar CO_makeStrCharLexToCf(CO_LexStrChar StrChar)
{
  return (CO_StrChar)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun37)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun37))), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm) StrChar));
}

/*}}}  */
/*{{{  CO_LexStrCon CO_makeLexStrConDefault(CO_LexStrCharLine line) */

CO_LexStrCon CO_makeLexStrConDefault(CO_LexStrCharLine line)
{
  return (CO_LexStrCon)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(34)))), (ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun48, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun37))))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(34)))), (ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun33))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun49)))))), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(34)), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl1(CO_afun8, (ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun48, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun37))))), (ATerm) line)), (ATerm)ATmakeInt(34)));
}

/*}}}  */
/*{{{  CO_StrCon CO_makeStrConLexToCf(CO_LexStrCon StrCon) */

CO_StrCon CO_makeStrConLexToCf(CO_LexStrCon StrCon)
{
  return (CO_StrCon)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun33)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun33))), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm) StrCon));
}

/*}}}  */
/*{{{  CO_LexStrCharLine CO_makeLexStrCharLineEmpty(void) */

CO_LexStrCharLine CO_makeLexStrCharLineEmpty(void)
{
  return (CO_LexStrCharLine)(ATerm)ATempty;
}

/*}}}  */
/*{{{  CO_LexStrCharLine CO_makeLexStrCharLineSingle(CO_LexStrChar head) */

CO_LexStrCharLine CO_makeLexStrCharLineSingle(CO_LexStrChar head)
{
  return (CO_LexStrCharLine)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  CO_LexStrCharLine CO_makeLexStrCharLineMany(CO_LexStrChar head, CO_LexStrCharLine tail) */

CO_LexStrCharLine CO_makeLexStrCharLineMany(CO_LexStrChar head, CO_LexStrCharLine tail)
{
  return (CO_LexStrCharLine)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/*}}}  */
/*{{{  CO_BoolCon CO_makeBoolConTrue(void) */

CO_BoolCon CO_makeBoolConTrue(void)
{
  return (CO_BoolCon)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun50))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun16))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun50)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(117)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun50)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(117)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(116)))));
}

/*}}}  */
/*{{{  CO_BoolCon CO_makeBoolConFalse(void) */

CO_BoolCon CO_makeBoolConFalse(void)
{
  return (CO_BoolCon)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun51))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun16))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun51)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(102)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun51)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(115)), (ATerm)ATmakeInt(108)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(102)))));
}

/*}}}  */
/*{{{  CO_LexNatCon CO_makeLexNatConDefault(const char* list) */

CO_LexNatCon CO_makeLexNatConDefault(const char* list)
{
  return (CO_LexNatCon)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun7, (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(CO_afun10, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))))))), (ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun52))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun49)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl1(CO_afun8, (ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun7, (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(CO_afun10, (ATerm)ATmakeInt(48), (ATerm)ATmakeInt(57))))))), (ATerm) ((ATerm) CO_stringToChars(list)))));
}

/*}}}  */
/*{{{  CO_NatCon CO_makeNatConLexToCf(CO_LexNatCon NatCon) */

CO_NatCon CO_makeNatConLexToCf(CO_LexNatCon NatCon)
{
  return (CO_NatCon)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun52)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun52))), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm) NatCon));
}

/*}}}  */
/*{{{  CO_LexByte CO_makeLexByteByte(char ch) */

CO_LexByte CO_makeLexByteByte(char ch)
{
  return (CO_LexByte)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(CO_afun10, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255))))), (ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun53))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun54)))))), (ATerm)ATmakeList1((ATerm) ((ATerm) CO_byteToChar(ch))));
}

/*}}}  */
/*{{{  CO_Byte CO_makeByteLexToCf(CO_LexByte Byte) */

CO_Byte CO_makeByteLexToCf(CO_LexByte Byte)
{
  return (CO_Byte)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun53)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun53))), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm) Byte));
}

/*}}}  */
/*{{{  CO_LexBytes CO_makeLexBytesBytes(CO_LexByteList list) */

CO_LexBytes CO_makeLexBytesBytes(CO_LexByteList list)
{
  return (CO_LexBytes)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun48, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun53))))), (ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun55))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun56)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl1(CO_afun8, (ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun48, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun53))))), (ATerm) list)));
}

/*}}}  */
/*{{{  CO_Bytes CO_makeBytesLexToCf(CO_LexBytes Bytes) */

CO_Bytes CO_makeBytesLexToCf(CO_LexBytes Bytes)
{
  return (CO_Bytes)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun6, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun55)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun55))), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm) Bytes));
}

/*}}}  */
/*{{{  CO_LexByteList CO_makeLexByteListEmpty(void) */

CO_LexByteList CO_makeLexByteListEmpty(void)
{
  return (CO_LexByteList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  CO_LexByteList CO_makeLexByteListSingle(CO_LexByte head) */

CO_LexByteList CO_makeLexByteListSingle(CO_LexByte head)
{
  return (CO_LexByteList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  CO_LexByteList CO_makeLexByteListMany(CO_LexByte head, CO_LexByteList tail) */

CO_LexByteList CO_makeLexByteListMany(CO_LexByte head, CO_LexByteList tail)
{
  return (CO_LexByteList)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/*}}}  */
/*{{{  CO_Subject CO_makeSubjectSubject(CO_OptLayout wsAfterSubject, CO_OptLayout wsAfterParenOpen, CO_StrCon description, CO_OptLayout wsAfterDescription) */

CO_Subject CO_makeSubjectSubject(CO_OptLayout wsAfterSubject, CO_OptLayout wsAfterParenOpen, CO_StrCon description, CO_OptLayout wsAfterDescription)
{
  return (CO_Subject)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun26))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun33)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun27))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun57))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun58))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun57)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun26)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterDescription), (ATerm) description), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun27)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterSubject), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(99)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(106)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(98)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(117)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun57)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(99)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(106)), (ATerm)ATmakeInt(98)), (ATerm)ATmakeInt(117)), (ATerm)ATmakeInt(115)))));
}

/*}}}  */
/*{{{  CO_Subject CO_makeSubjectLocalized(CO_OptLayout wsAfterLocalized, CO_OptLayout wsAfterParenOpen, CO_StrCon description, CO_OptLayout wsAfterDescription, CO_OptLayout wsAfterComma, CO_Location Location, CO_OptLayout wsAfterLocation) */

CO_Subject CO_makeSubjectLocalized(CO_OptLayout wsAfterLocalized, CO_OptLayout wsAfterParenOpen, CO_StrCon description, CO_OptLayout wsAfterDescription, CO_OptLayout wsAfterComma, CO_Location Location, CO_OptLayout wsAfterLocation)
{
  return (CO_Subject)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun26))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun59)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun33)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun27))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun61))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun58))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun61)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun26)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterLocation), (ATerm) Location), (ATerm) wsAfterComma), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterDescription), (ATerm) description), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun27)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterLocalized), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(100)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(122)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(99)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun61)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(100)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(122)), (ATerm)ATmakeInt(105)), (ATerm)ATmakeInt(108)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(99)), (ATerm)ATmakeInt(111)), (ATerm)ATmakeInt(108)))));
}

/*}}}  */
/*{{{  CO_Error CO_makeErrorInfo(CO_OptLayout wsAfterInfo, CO_OptLayout wsAfterParenOpen, CO_StrCon description, CO_OptLayout wsAfterDescription, CO_OptLayout wsAfterComma, CO_OptLayout wsAfterBracketOpen, CO_SubjectList list, CO_OptLayout wsAfterList, CO_OptLayout wsAfterBracketClose) */

CO_Error CO_makeErrorInfo(CO_OptLayout wsAfterInfo, CO_OptLayout wsAfterParenOpen, CO_StrCon description, CO_OptLayout wsAfterDescription, CO_OptLayout wsAfterComma, CO_OptLayout wsAfterBracketOpen, CO_SubjectList list, CO_OptLayout wsAfterList, CO_OptLayout wsAfterBracketClose)
{
  return (CO_Error)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun26))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun62))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl2(CO_afun63, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun58)), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60))))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun64))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun33)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun27))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun65))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun35))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun65)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun26)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterBracketClose), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun62)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl1(CO_afun8, (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl2(CO_afun63, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun58)), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60))))), (ATerm) list)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun64)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm) wsAfterComma), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterDescription), (ATerm) description), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun27)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterInfo), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(102)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(110)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun65)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(111)), (ATerm)ATmakeInt(102)), (ATerm)ATmakeInt(110)), (ATerm)ATmakeInt(105)))));
}

/*}}}  */
/*{{{  CO_Error CO_makeErrorWarning(CO_OptLayout wsAfterWarning, CO_OptLayout wsAfterParenOpen, CO_StrCon description, CO_OptLayout wsAfterDescription, CO_OptLayout wsAfterComma, CO_OptLayout wsAfterBracketOpen, CO_SubjectList list, CO_OptLayout wsAfterList, CO_OptLayout wsAfterBracketClose) */

CO_Error CO_makeErrorWarning(CO_OptLayout wsAfterWarning, CO_OptLayout wsAfterParenOpen, CO_StrCon description, CO_OptLayout wsAfterDescription, CO_OptLayout wsAfterComma, CO_OptLayout wsAfterBracketOpen, CO_SubjectList list, CO_OptLayout wsAfterList, CO_OptLayout wsAfterBracketClose)
{
  return (CO_Error)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun26))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun62))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl2(CO_afun63, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun58)), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60))))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun64))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun33)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun27))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun66))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun35))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun66)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun26)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterBracketClose), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun62)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl1(CO_afun8, (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl2(CO_afun63, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun58)), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60))))), (ATerm) list)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun64)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm) wsAfterComma), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterDescription), (ATerm) description), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun27)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterWarning), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(103)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(110)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(110)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(119)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun66)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(103)), (ATerm)ATmakeInt(110)), (ATerm)ATmakeInt(105)), (ATerm)ATmakeInt(110)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(119)))));
}

/*}}}  */
/*{{{  CO_Error CO_makeErrorError(CO_OptLayout wsAfterError, CO_OptLayout wsAfterParenOpen, CO_StrCon description, CO_OptLayout wsAfterDescription, CO_OptLayout wsAfterComma, CO_OptLayout wsAfterBracketOpen, CO_SubjectList list, CO_OptLayout wsAfterList, CO_OptLayout wsAfterBracketClose) */

CO_Error CO_makeErrorError(CO_OptLayout wsAfterError, CO_OptLayout wsAfterParenOpen, CO_StrCon description, CO_OptLayout wsAfterDescription, CO_OptLayout wsAfterComma, CO_OptLayout wsAfterBracketOpen, CO_SubjectList list, CO_OptLayout wsAfterList, CO_OptLayout wsAfterBracketClose)
{
  return (CO_Error)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun26))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun62))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl2(CO_afun63, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun58)), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60))))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun64))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun33)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun27))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun67))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun35))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun67)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun26)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterBracketClose), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun62)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl1(CO_afun8, (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl2(CO_afun63, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun58)), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60))))), (ATerm) list)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun64)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm) wsAfterComma), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterDescription), (ATerm) description), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun27)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterError), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun67)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(111)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(101)))));
}

/*}}}  */
/*{{{  CO_Error CO_makeErrorFatal(CO_OptLayout wsAfterFatal, CO_OptLayout wsAfterParenOpen, CO_StrCon description, CO_OptLayout wsAfterDescription, CO_OptLayout wsAfterComma, CO_OptLayout wsAfterBracketOpen, CO_SubjectList list, CO_OptLayout wsAfterList, CO_OptLayout wsAfterBracketClose) */

CO_Error CO_makeErrorFatal(CO_OptLayout wsAfterFatal, CO_OptLayout wsAfterParenOpen, CO_StrCon description, CO_OptLayout wsAfterDescription, CO_OptLayout wsAfterComma, CO_OptLayout wsAfterBracketOpen, CO_SubjectList list, CO_OptLayout wsAfterList, CO_OptLayout wsAfterBracketClose)
{
  return (CO_Error)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun26))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun62))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl2(CO_afun63, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun58)), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60))))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun64))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun33)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun27))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun68))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun35))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun68)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun26)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterBracketClose), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun62)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl1(CO_afun8, (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl2(CO_afun63, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun58)), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60))))), (ATerm) list)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun64)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm) wsAfterComma), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterDescription), (ATerm) description), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun27)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterFatal), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(102)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun68)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(108)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(102)))));
}

/*}}}  */
/*{{{  CO_Summary CO_makeSummarySummary(CO_OptLayout wsAfterSummary, CO_OptLayout wsAfterParenOpen, CO_StrCon producer, CO_OptLayout wsAfterProducer, CO_OptLayout wsAfterComma, CO_StrCon id, CO_OptLayout wsAfterId, CO_OptLayout wsAfterComma1, CO_OptLayout wsAfterBracketOpen, CO_ErrorList list, CO_OptLayout wsAfterList, CO_OptLayout wsAfterBracketClose) */

CO_Summary CO_makeSummarySummary(CO_OptLayout wsAfterSummary, CO_OptLayout wsAfterParenOpen, CO_StrCon producer, CO_OptLayout wsAfterProducer, CO_OptLayout wsAfterComma, CO_StrCon id, CO_OptLayout wsAfterId, CO_OptLayout wsAfterComma1, CO_OptLayout wsAfterBracketOpen, CO_ErrorList list, CO_OptLayout wsAfterList, CO_OptLayout wsAfterBracketClose)
{
  return (CO_Summary)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun26))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun62))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl2(CO_afun63, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun35)), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60))))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun64))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun33)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun33)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun27))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun69))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun34))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun69)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun26)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterBracketClose), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun62)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(93)))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl1(CO_afun8, (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl2(CO_afun63, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun35)), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60))))), (ATerm) list)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun64)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(91)))), (ATerm) wsAfterComma1), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterId), (ATerm) id), (ATerm) wsAfterComma), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterProducer), (ATerm) producer), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun27)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterSummary), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(121)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(109)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(109)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(117)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun69)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(121)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(109)), (ATerm)ATmakeInt(109)), (ATerm)ATmakeInt(117)), (ATerm)ATmakeInt(115)))));
}

/*}}}  */
/*{{{  CO_SubjectList CO_makeSubjectListEmpty(void) */

CO_SubjectList CO_makeSubjectListEmpty(void)
{
  return (CO_SubjectList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  CO_SubjectList CO_makeSubjectListSingle(CO_Subject head) */

CO_SubjectList CO_makeSubjectListSingle(CO_Subject head)
{
  return (CO_SubjectList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  CO_SubjectList CO_makeSubjectListMany(CO_Subject head, CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_SubjectList tail) */

CO_SubjectList CO_makeSubjectListMany(CO_Subject head, CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_SubjectList tail)
{
  if (CO_isSubjectListEmpty(tail)) {
    return CO_makeSubjectListSingle(head);
  }
  return (CO_SubjectList)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm) wsAfterSep), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterHead), (ATerm) head);
}

/*}}}  */
/*{{{  CO_ErrorList CO_makeErrorListEmpty(void) */

CO_ErrorList CO_makeErrorListEmpty(void)
{
  return (CO_ErrorList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  CO_ErrorList CO_makeErrorListSingle(CO_Error head) */

CO_ErrorList CO_makeErrorListSingle(CO_Error head)
{
  return (CO_ErrorList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  CO_ErrorList CO_makeErrorListMany(CO_Error head, CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_ErrorList tail) */

CO_ErrorList CO_makeErrorListMany(CO_Error head, CO_OptLayout wsAfterHead, CO_OptLayout wsAfterSep, CO_ErrorList tail)
{
  if (CO_isErrorListEmpty(tail)) {
    return CO_makeErrorListSingle(head);
  }
  return (CO_ErrorList)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm) wsAfterSep), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterHead), (ATerm) head);
}

/*}}}  */
/*{{{  CO_Location CO_makeLocationFile(CO_OptLayout wsAfterFile, CO_OptLayout wsAfterParenOpen, CO_StrCon filename, CO_OptLayout wsAfterFilename) */

CO_Location CO_makeLocationFile(CO_OptLayout wsAfterFile, CO_OptLayout wsAfterParenOpen, CO_StrCon filename, CO_OptLayout wsAfterFilename)
{
  return (CO_Location)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun26))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun33)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun27))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun70))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun59))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun70)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun26)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterFilename), (ATerm) filename), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun27)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterFile), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(102)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun70)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(108)), (ATerm)ATmakeInt(105)), (ATerm)ATmakeInt(102)))));
}

/*}}}  */
/*{{{  CO_Location CO_makeLocationArea(CO_OptLayout wsAfterA, CO_OptLayout wsAfterParenOpen, CO_Area Area, CO_OptLayout wsAfterArea) */

CO_Location CO_makeLocationArea(CO_OptLayout wsAfterA, CO_OptLayout wsAfterParenOpen, CO_Area Area, CO_OptLayout wsAfterArea)
{
  return (CO_Location)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun26))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun71)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun27))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun72))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun59))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun72)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun26)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterArea), (ATerm) Area), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun27)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterA), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun72)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(97)))));
}

/*}}}  */
/*{{{  CO_Location CO_makeLocationAreaInFile(CO_OptLayout wsAfterAreaInFile, CO_OptLayout wsAfterParenOpen, CO_StrCon filename, CO_OptLayout wsAfterFilename, CO_OptLayout wsAfterComma, CO_Area Area, CO_OptLayout wsAfterArea) */

CO_Location CO_makeLocationAreaInFile(CO_OptLayout wsAfterAreaInFile, CO_OptLayout wsAfterParenOpen, CO_StrCon filename, CO_OptLayout wsAfterFilename, CO_OptLayout wsAfterComma, CO_Area Area, CO_OptLayout wsAfterArea)
{
  return (CO_Location)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun26))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun71)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun33)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun27))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun73))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun59))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun73)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun26)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterArea), (ATerm) Area), (ATerm) wsAfterComma), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterFilename), (ATerm) filename), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun27)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterAreaInFile), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(108)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(102)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(45)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(110)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(45)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun73)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(108)), (ATerm)ATmakeInt(105)), (ATerm)ATmakeInt(102)), (ATerm)ATmakeInt(45)), (ATerm)ATmakeInt(110)), (ATerm)ATmakeInt(105)), (ATerm)ATmakeInt(45)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(97)))));
}

/*}}}  */
/*{{{  CO_Area CO_makeAreaArea(CO_OptLayout wsAfterArea, CO_OptLayout wsAfterParenOpen, CO_NatCon beginLine, CO_OptLayout wsAfterBeginLine, CO_OptLayout wsAfterComma, CO_NatCon beginColumn, CO_OptLayout wsAfterBeginColumn, CO_OptLayout wsAfterComma1, CO_NatCon endLine, CO_OptLayout wsAfterEndLine, CO_OptLayout wsAfterComma2, CO_NatCon endColumn, CO_OptLayout wsAfterEndColumn, CO_OptLayout wsAfterComma3, CO_NatCon offset, CO_OptLayout wsAfterOffset, CO_OptLayout wsAfterComma4, CO_NatCon length, CO_OptLayout wsAfterLength) */

CO_Area CO_makeAreaArea(CO_OptLayout wsAfterArea, CO_OptLayout wsAfterParenOpen, CO_NatCon beginLine, CO_OptLayout wsAfterBeginLine, CO_OptLayout wsAfterComma, CO_NatCon beginColumn, CO_OptLayout wsAfterBeginColumn, CO_OptLayout wsAfterComma1, CO_NatCon endLine, CO_OptLayout wsAfterEndLine, CO_OptLayout wsAfterComma2, CO_NatCon endColumn, CO_OptLayout wsAfterEndColumn, CO_OptLayout wsAfterComma3, CO_NatCon offset, CO_OptLayout wsAfterOffset, CO_OptLayout wsAfterComma4, CO_NatCon length, CO_OptLayout wsAfterLength)
{
  return (CO_Area)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun26))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun52)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun52)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun52)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun52)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun52)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun52)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun27))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun72))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun71))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun72)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun26)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterLength), (ATerm) length), (ATerm) wsAfterComma4), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterOffset), (ATerm) offset), (ATerm) wsAfterComma3), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterEndColumn), (ATerm) endColumn), (ATerm) wsAfterComma2), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterEndLine), (ATerm) endLine), (ATerm) wsAfterComma1), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterBeginColumn), (ATerm) beginColumn), (ATerm) wsAfterComma), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterBeginLine), (ATerm) beginLine), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun27)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterArea), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun72)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(97)))));
}

/*}}}  */
/*{{{  CO_Read CO_makeReadSuccess(CO_OptLayout wsAfterRead, CO_OptLayout wsAfterParenOpen, CO_Bytes value, CO_OptLayout wsAfterValue) */

CO_Read CO_makeReadSuccess(CO_OptLayout wsAfterRead, CO_OptLayout wsAfterParenOpen, CO_Bytes value, CO_OptLayout wsAfterValue)
{
  return (CO_Read)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun26))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun55)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun27))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun74))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun75))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun76)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun26)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterValue), (ATerm) value), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun27)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterRead), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(100)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun74)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(100)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(114)))));
}

/*}}}  */
/*{{{  CO_Read CO_makeReadFailure(CO_OptLayout wsAfterReadError, CO_OptLayout wsAfterParenOpen, CO_Summary Summary, CO_OptLayout wsAfterSummary) */

CO_Read CO_makeReadFailure(CO_OptLayout wsAfterReadError, CO_OptLayout wsAfterParenOpen, CO_Summary Summary, CO_OptLayout wsAfterSummary)
{
  return (CO_Read)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun26))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun34)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun27))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun77))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun75))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun78)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun26)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterSummary), (ATerm) Summary), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun27)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterReadError), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(45)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(100)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun77)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(111)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(45)), (ATerm)ATmakeInt(100)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(114)))));
}

/*}}}  */
/*{{{  CO_Write CO_makeWriteSuccess(void) */

CO_Write CO_makeWriteSuccess(void)
{
  return (CO_Write)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun79))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun80))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun76)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(110)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(119)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun79)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(110)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(105)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(119)))));
}

/*}}}  */
/*{{{  CO_Write CO_makeWriteFailure(CO_OptLayout wsAfterWriteError, CO_OptLayout wsAfterParenOpen, CO_Summary Summary, CO_OptLayout wsAfterSummary) */

CO_Write CO_makeWriteFailure(CO_OptLayout wsAfterWriteError, CO_OptLayout wsAfterParenOpen, CO_Summary Summary, CO_OptLayout wsAfterSummary)
{
  return (CO_Write)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun26))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun34)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun27))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun81))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun80))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun78)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun26)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterSummary), (ATerm) Summary), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun27)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterWriteError), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(45)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(105)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(119)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun81)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(111)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(45)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(105)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(119)))));
}

/*}}}  */
/*{{{  CO_ParsetreeX CO_makeParsetreeXSuccess(ATerm typeOfTree, ATerm typeOfX, CO_OptLayout wsAfterParseTree, CO_OptLayout wsAfterParenOpen, CO_Bytes leftLayout, CO_OptLayout wsAfterLeftLayout, CO_OptLayout wsAfterComma, CO_X tree, CO_OptLayout wsAfterTree, CO_OptLayout wsAfterComma1, CO_Bytes rightLayout, CO_OptLayout wsAfterRightLayout, CO_OptLayout wsAfterComma2, CO_NatCon ambCnt, CO_OptLayout wsAfterAmbCnt) */

CO_ParsetreeX CO_makeParsetreeXSuccess(ATerm typeOfTree, ATerm typeOfX, CO_OptLayout wsAfterParseTree, CO_OptLayout wsAfterParenOpen, CO_Bytes leftLayout, CO_OptLayout wsAfterLeftLayout, CO_OptLayout wsAfterComma, CO_X tree, CO_OptLayout wsAfterTree, CO_OptLayout wsAfterComma1, CO_Bytes rightLayout, CO_OptLayout wsAfterRightLayout, CO_OptLayout wsAfterComma2, CO_NatCon ambCnt, CO_OptLayout wsAfterAmbCnt)
{
  return (CO_ParsetreeX)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun26))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun52)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun55)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm) typeOfTree), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun55)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun27))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun82))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl2(CO_afun83, (ATerm)ATmakeAppl0(CO_afun84), (ATerm)ATmakeList1((ATerm) typeOfX))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun76)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun26)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterAmbCnt), (ATerm) ambCnt), (ATerm) wsAfterComma2), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterRightLayout), (ATerm) rightLayout), (ATerm) wsAfterComma1), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterTree), (ATerm) tree), (ATerm) wsAfterComma), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun60)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(44)))), (ATerm) wsAfterLeftLayout), (ATerm) leftLayout), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun27)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterParseTree), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(116)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(45)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(112)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun82)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(116)), (ATerm)ATmakeInt(45)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(115)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(112)))));
}

/*}}}  */
/*{{{  CO_ParsetreeX CO_makeParsetreeXFailure(ATerm typeOfX, CO_OptLayout wsAfterParseError, CO_OptLayout wsAfterParenOpen, CO_Summary Summary, CO_OptLayout wsAfterSummary) */

CO_ParsetreeX CO_makeParsetreeXFailure(ATerm typeOfX, CO_OptLayout wsAfterParseError, CO_OptLayout wsAfterParenOpen, CO_Summary Summary, CO_OptLayout wsAfterSummary)
{
  return (CO_ParsetreeX)(ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun26))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun15, (ATerm)ATmakeAppl0(CO_afun34)))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun27))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl1(CO_afun3, (ATerm)ATmakeAppl0(CO_afun4)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun85))), (ATerm)ATmakeAppl1(CO_afun2, (ATerm)ATmakeAppl2(CO_afun83, (ATerm)ATmakeAppl0(CO_afun84), (ATerm)ATmakeList1((ATerm) typeOfX))), (ATerm)ATmakeAppl1(CO_afun11, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun12, (ATerm)ATmakeAppl1(CO_afun13, (ATerm)ATmakeAppl0(CO_afun78)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun26)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(41)))), (ATerm) wsAfterSummary), (ATerm) Summary), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun27)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATmakeList1((ATerm)ATmakeInt(40)))), (ATerm) wsAfterParseError), (ATerm)ATmakeAppl2(CO_afun0, (ATerm)ATmakeAppl3(CO_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(111)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(45)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(101)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(115)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(114)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(97)))), (ATerm)ATmakeAppl1(CO_afun9, (ATerm)ATmakeList1((ATerm)ATmakeInt(112)))), (ATerm)ATmakeAppl1(CO_afun19, (ATerm)ATmakeAppl0(CO_afun85)), (ATerm)ATmakeAppl0(CO_afun5)), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(111)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(45)), (ATerm)ATmakeInt(101)), (ATerm)ATmakeInt(115)), (ATerm)ATmakeInt(114)), (ATerm)ATmakeInt(97)), (ATerm)ATmakeInt(112)))));
}

/*}}}  */
/*{{{  CO_X CO_makeXCast(ATerm X) */

CO_X CO_makeXCast(ATerm X)
{
  return (CO_X)(ATerm) X;
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool CO_isEqualOptLayout(CO_OptLayout arg0, CO_OptLayout arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CO_isEqualLayout(CO_Layout arg0, CO_Layout arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CO_isEqualLexLayoutList(CO_LexLayoutList arg0, CO_LexLayoutList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CO_isEqualLexLayout(CO_LexLayout arg0, CO_LexLayout arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CO_isEqualBoolean(CO_Boolean arg0, CO_Boolean arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CO_isEqualStart(CO_Start arg0, CO_Start arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CO_isEqualLexStrChar(CO_LexStrChar arg0, CO_LexStrChar arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CO_isEqualStrChar(CO_StrChar arg0, CO_StrChar arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CO_isEqualLexStrCon(CO_LexStrCon arg0, CO_LexStrCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CO_isEqualStrCon(CO_StrCon arg0, CO_StrCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CO_isEqualLexStrCharLine(CO_LexStrCharLine arg0, CO_LexStrCharLine arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CO_isEqualBoolCon(CO_BoolCon arg0, CO_BoolCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CO_isEqualLexNatCon(CO_LexNatCon arg0, CO_LexNatCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CO_isEqualNatCon(CO_NatCon arg0, CO_NatCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CO_isEqualLexByte(CO_LexByte arg0, CO_LexByte arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CO_isEqualByte(CO_Byte arg0, CO_Byte arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CO_isEqualLexBytes(CO_LexBytes arg0, CO_LexBytes arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CO_isEqualBytes(CO_Bytes arg0, CO_Bytes arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CO_isEqualLexByteList(CO_LexByteList arg0, CO_LexByteList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CO_isEqualSubject(CO_Subject arg0, CO_Subject arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CO_isEqualError(CO_Error arg0, CO_Error arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CO_isEqualSummary(CO_Summary arg0, CO_Summary arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CO_isEqualSubjectList(CO_SubjectList arg0, CO_SubjectList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CO_isEqualErrorList(CO_ErrorList arg0, CO_ErrorList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CO_isEqualLocation(CO_Location arg0, CO_Location arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CO_isEqualArea(CO_Area arg0, CO_Area arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CO_isEqualRead(CO_Read arg0, CO_Read arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CO_isEqualWrite(CO_Write arg0, CO_Write arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CO_isEqualParsetreeX(CO_ParsetreeX arg0, CO_ParsetreeX arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool CO_isEqualX(CO_X arg0, CO_X arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  CO_OptLayout accessors */

/*{{{  ATbool CO_isValidOptLayout(CO_OptLayout arg) */

ATbool CO_isValidOptLayout(CO_OptLayout arg)
{
  if (CO_isOptLayoutAbsent(arg)) {
    return ATtrue;
  }
  else if (CO_isOptLayoutPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CO_isOptLayoutAbsent(CO_OptLayout arg) */

inline ATbool CO_isOptLayoutAbsent(CO_OptLayout arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternOptLayoutAbsent);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isOptLayoutPresent(CO_OptLayout arg) */

inline ATbool CO_isOptLayoutPresent(CO_OptLayout arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternOptLayoutPresent, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool CO_hasOptLayoutLayout(CO_OptLayout arg) */

ATbool CO_hasOptLayoutLayout(CO_OptLayout arg)
{
  if (CO_isOptLayoutPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_Layout CO_getOptLayoutLayout(CO_OptLayout arg) */

CO_Layout CO_getOptLayoutLayout(CO_OptLayout arg)
{
  
    return (CO_Layout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  CO_OptLayout CO_setOptLayoutLayout(CO_OptLayout arg, CO_Layout layout) */

CO_OptLayout CO_setOptLayoutLayout(CO_OptLayout arg, CO_Layout layout)
{
  if (CO_isOptLayoutPresent(arg)) {
    return (CO_OptLayout)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) layout), 0), 1);
  }

  ATabort("OptLayout has no Layout: %t\n", arg);
  return (CO_OptLayout)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CO_Layout accessors */

/*{{{  ATbool CO_isValidLayout(CO_Layout arg) */

ATbool CO_isValidLayout(CO_Layout arg)
{
  if (CO_isLayoutLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CO_isLayoutLexToCf(CO_Layout arg) */

inline ATbool CO_isLayoutLexToCf(CO_Layout arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CO_patternLayoutLexToCf, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool CO_hasLayoutList(CO_Layout arg) */

ATbool CO_hasLayoutList(CO_Layout arg)
{
  if (CO_isLayoutLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_LexLayoutList CO_getLayoutList(CO_Layout arg) */

CO_LexLayoutList CO_getLayoutList(CO_Layout arg)
{
  
    return (CO_LexLayoutList)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  CO_Layout CO_setLayoutList(CO_Layout arg, CO_LexLayoutList list) */

CO_Layout CO_setLayoutList(CO_Layout arg, CO_LexLayoutList list)
{
  if (CO_isLayoutLexToCf(arg)) {
    return (CO_Layout)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) list), 1), 0), 1);
  }

  ATabort("Layout has no List: %t\n", arg);
  return (CO_Layout)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CO_LexLayoutList accessors */

/*{{{  ATbool CO_isValidLexLayoutList(CO_LexLayoutList arg) */

ATbool CO_isValidLexLayoutList(CO_LexLayoutList arg)
{
  if (CO_isLexLayoutListEmpty(arg)) {
    return ATtrue;
  }
  else if (CO_isLexLayoutListSingle(arg)) {
    return ATtrue;
  }
  else if (CO_isLexLayoutListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CO_isLexLayoutListEmpty(CO_LexLayoutList arg) */

inline ATbool CO_isLexLayoutListEmpty(CO_LexLayoutList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CO_patternLexLayoutListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool CO_isLexLayoutListSingle(CO_LexLayoutList arg) */

inline ATbool CO_isLexLayoutListSingle(CO_LexLayoutList arg)
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
      last_result = ATmatchTerm((ATerm)arg, CO_patternLexLayoutListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isLexLayoutListMany(CO_LexLayoutList arg) */

inline ATbool CO_isLexLayoutListMany(CO_LexLayoutList arg)
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
      last_result = ATmatchTerm((ATerm)arg, CO_patternLexLayoutListMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool CO_hasLexLayoutListHead(CO_LexLayoutList arg) */

ATbool CO_hasLexLayoutListHead(CO_LexLayoutList arg)
{
  if (CO_isLexLayoutListSingle(arg)) {
    return ATtrue;
  }
  else if (CO_isLexLayoutListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasLexLayoutListTail(CO_LexLayoutList arg) */

ATbool CO_hasLexLayoutListTail(CO_LexLayoutList arg)
{
  if (CO_isLexLayoutListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_LexLayout CO_getLexLayoutListHead(CO_LexLayoutList arg) */

CO_LexLayout CO_getLexLayoutListHead(CO_LexLayoutList arg)
{
  if (CO_isLexLayoutListSingle(arg)) {
    return (CO_LexLayout)ATgetFirst((ATermList)arg);
  }
  else 
    return (CO_LexLayout)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  CO_LexLayoutList CO_getLexLayoutListTail(CO_LexLayoutList arg) */

CO_LexLayoutList CO_getLexLayoutListTail(CO_LexLayoutList arg)
{
  
    return (CO_LexLayoutList)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  CO_LexLayoutList CO_setLexLayoutListHead(CO_LexLayoutList arg, CO_LexLayout head) */

CO_LexLayoutList CO_setLexLayoutListHead(CO_LexLayoutList arg, CO_LexLayout head)
{
  if (CO_isLexLayoutListSingle(arg)) {
    return (CO_LexLayoutList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (CO_isLexLayoutListMany(arg)) {
    return (CO_LexLayoutList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("LexLayoutList has no Head: %t\n", arg);
  return (CO_LexLayoutList)NULL;
}

/*}}}  */
/*{{{  CO_LexLayoutList CO_setLexLayoutListTail(CO_LexLayoutList arg, CO_LexLayoutList tail) */

CO_LexLayoutList CO_setLexLayoutListTail(CO_LexLayoutList arg, CO_LexLayoutList tail)
{
  if (CO_isLexLayoutListMany(arg)) {
    return (CO_LexLayoutList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("LexLayoutList has no Tail: %t\n", arg);
  return (CO_LexLayoutList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CO_LexLayout accessors */

/*{{{  ATbool CO_isValidLexLayout(CO_LexLayout arg) */

ATbool CO_isValidLexLayout(CO_LexLayout arg)
{
  if (CO_isLexLayoutWhitespace(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CO_isLexLayoutWhitespace(CO_LexLayout arg) */

inline ATbool CO_isLexLayoutWhitespace(CO_LexLayout arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CO_patternLexLayoutWhitespace, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool CO_hasLexLayoutCh(CO_LexLayout arg) */

ATbool CO_hasLexLayoutCh(CO_LexLayout arg)
{
  if (CO_isLexLayoutWhitespace(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char CO_getLexLayoutCh(CO_LexLayout arg) */

char CO_getLexLayoutCh(CO_LexLayout arg)
{
  
    return (char)CO_charToByte((ATerm)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  CO_LexLayout CO_setLexLayoutCh(CO_LexLayout arg, char ch) */

CO_LexLayout CO_setLexLayoutCh(CO_LexLayout arg, char ch)
{
  if (CO_isLexLayoutWhitespace(arg)) {
    return (CO_LexLayout)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) CO_byteToChar(ch))), 0), 1);
  }

  ATabort("LexLayout has no Ch: %t\n", arg);
  return (CO_LexLayout)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CO_Boolean accessors */

/*{{{  ATbool CO_isValidBoolean(CO_Boolean arg) */

ATbool CO_isValidBoolean(CO_Boolean arg)
{
  if (CO_isBooleanConstant(arg)) {
    return ATtrue;
  }
  else if (CO_isBooleanOr(arg)) {
    return ATtrue;
  }
  else if (CO_isBooleanAnd(arg)) {
    return ATtrue;
  }
  else if (CO_isBooleanNot(arg)) {
    return ATtrue;
  }
  else if (CO_isBooleanBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CO_isBooleanConstant(CO_Boolean arg) */

inline ATbool CO_isBooleanConstant(CO_Boolean arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternBooleanConstant, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isBooleanOr(CO_Boolean arg) */

inline ATbool CO_isBooleanOr(CO_Boolean arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternBooleanOr, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isBooleanAnd(CO_Boolean arg) */

inline ATbool CO_isBooleanAnd(CO_Boolean arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternBooleanAnd, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isBooleanNot(CO_Boolean arg) */

inline ATbool CO_isBooleanNot(CO_Boolean arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternBooleanNot, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isBooleanBracket(CO_Boolean arg) */

inline ATbool CO_isBooleanBracket(CO_Boolean arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternBooleanBracket, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool CO_hasBooleanBoolCon(CO_Boolean arg) */

ATbool CO_hasBooleanBoolCon(CO_Boolean arg)
{
  if (CO_isBooleanConstant(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasBooleanLhs(CO_Boolean arg) */

ATbool CO_hasBooleanLhs(CO_Boolean arg)
{
  if (CO_isBooleanOr(arg)) {
    return ATtrue;
  }
  else if (CO_isBooleanAnd(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasBooleanWsAfterLhs(CO_Boolean arg) */

ATbool CO_hasBooleanWsAfterLhs(CO_Boolean arg)
{
  if (CO_isBooleanOr(arg)) {
    return ATtrue;
  }
  else if (CO_isBooleanAnd(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasBooleanWsAfterBar(CO_Boolean arg) */

ATbool CO_hasBooleanWsAfterBar(CO_Boolean arg)
{
  if (CO_isBooleanOr(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasBooleanRhs(CO_Boolean arg) */

ATbool CO_hasBooleanRhs(CO_Boolean arg)
{
  if (CO_isBooleanOr(arg)) {
    return ATtrue;
  }
  else if (CO_isBooleanAnd(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasBooleanWsAfterAmp(CO_Boolean arg) */

ATbool CO_hasBooleanWsAfterAmp(CO_Boolean arg)
{
  if (CO_isBooleanAnd(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasBooleanWsAfterNot(CO_Boolean arg) */

ATbool CO_hasBooleanWsAfterNot(CO_Boolean arg)
{
  if (CO_isBooleanNot(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasBooleanWsAfterParenOpen(CO_Boolean arg) */

ATbool CO_hasBooleanWsAfterParenOpen(CO_Boolean arg)
{
  if (CO_isBooleanNot(arg)) {
    return ATtrue;
  }
  else if (CO_isBooleanBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasBooleanBoolean(CO_Boolean arg) */

ATbool CO_hasBooleanBoolean(CO_Boolean arg)
{
  if (CO_isBooleanNot(arg)) {
    return ATtrue;
  }
  else if (CO_isBooleanBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasBooleanWsAfterBoolean(CO_Boolean arg) */

ATbool CO_hasBooleanWsAfterBoolean(CO_Boolean arg)
{
  if (CO_isBooleanNot(arg)) {
    return ATtrue;
  }
  else if (CO_isBooleanBracket(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_BoolCon CO_getBooleanBoolCon(CO_Boolean arg) */

CO_BoolCon CO_getBooleanBoolCon(CO_Boolean arg)
{
  
    return (CO_BoolCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  CO_Boolean CO_getBooleanLhs(CO_Boolean arg) */

CO_Boolean CO_getBooleanLhs(CO_Boolean arg)
{
  if (CO_isBooleanOr(arg)) {
    return (CO_Boolean)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (CO_Boolean)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  CO_OptLayout CO_getBooleanWsAfterLhs(CO_Boolean arg) */

CO_OptLayout CO_getBooleanWsAfterLhs(CO_Boolean arg)
{
  if (CO_isBooleanOr(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getBooleanWsAfterBar(CO_Boolean arg) */

CO_OptLayout CO_getBooleanWsAfterBar(CO_Boolean arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  CO_Boolean CO_getBooleanRhs(CO_Boolean arg) */

CO_Boolean CO_getBooleanRhs(CO_Boolean arg)
{
  if (CO_isBooleanOr(arg)) {
    return (CO_Boolean)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (CO_Boolean)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getBooleanWsAfterAmp(CO_Boolean arg) */

CO_OptLayout CO_getBooleanWsAfterAmp(CO_Boolean arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getBooleanWsAfterNot(CO_Boolean arg) */

CO_OptLayout CO_getBooleanWsAfterNot(CO_Boolean arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getBooleanWsAfterParenOpen(CO_Boolean arg) */

CO_OptLayout CO_getBooleanWsAfterParenOpen(CO_Boolean arg)
{
  if (CO_isBooleanNot(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  CO_Boolean CO_getBooleanBoolean(CO_Boolean arg) */

CO_Boolean CO_getBooleanBoolean(CO_Boolean arg)
{
  if (CO_isBooleanNot(arg)) {
    return (CO_Boolean)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (CO_Boolean)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getBooleanWsAfterBoolean(CO_Boolean arg) */

CO_OptLayout CO_getBooleanWsAfterBoolean(CO_Boolean arg)
{
  if (CO_isBooleanNot(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  CO_Boolean CO_setBooleanBoolCon(CO_Boolean arg, CO_BoolCon BoolCon) */

CO_Boolean CO_setBooleanBoolCon(CO_Boolean arg, CO_BoolCon BoolCon)
{
  if (CO_isBooleanConstant(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) BoolCon), 0), 1);
  }

  ATabort("Boolean has no BoolCon: %t\n", arg);
  return (CO_Boolean)NULL;
}

/*}}}  */
/*{{{  CO_Boolean CO_setBooleanLhs(CO_Boolean arg, CO_Boolean lhs) */

CO_Boolean CO_setBooleanLhs(CO_Boolean arg, CO_Boolean lhs)
{
  if (CO_isBooleanOr(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) lhs), 0), 1);
  }
  else if (CO_isBooleanAnd(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) lhs), 0), 1);
  }

  ATabort("Boolean has no Lhs: %t\n", arg);
  return (CO_Boolean)NULL;
}

/*}}}  */
/*{{{  CO_Boolean CO_setBooleanWsAfterLhs(CO_Boolean arg, CO_OptLayout wsAfterLhs) */

CO_Boolean CO_setBooleanWsAfterLhs(CO_Boolean arg, CO_OptLayout wsAfterLhs)
{
  if (CO_isBooleanOr(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLhs), 1), 1);
  }
  else if (CO_isBooleanAnd(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLhs), 1), 1);
  }

  ATabort("Boolean has no WsAfterLhs: %t\n", arg);
  return (CO_Boolean)NULL;
}

/*}}}  */
/*{{{  CO_Boolean CO_setBooleanWsAfterBar(CO_Boolean arg, CO_OptLayout wsAfterBar) */

CO_Boolean CO_setBooleanWsAfterBar(CO_Boolean arg, CO_OptLayout wsAfterBar)
{
  if (CO_isBooleanOr(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBar), 3), 1);
  }

  ATabort("Boolean has no WsAfterBar: %t\n", arg);
  return (CO_Boolean)NULL;
}

/*}}}  */
/*{{{  CO_Boolean CO_setBooleanRhs(CO_Boolean arg, CO_Boolean rhs) */

CO_Boolean CO_setBooleanRhs(CO_Boolean arg, CO_Boolean rhs)
{
  if (CO_isBooleanOr(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) rhs), 4), 1);
  }
  else if (CO_isBooleanAnd(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) rhs), 4), 1);
  }

  ATabort("Boolean has no Rhs: %t\n", arg);
  return (CO_Boolean)NULL;
}

/*}}}  */
/*{{{  CO_Boolean CO_setBooleanWsAfterAmp(CO_Boolean arg, CO_OptLayout wsAfterAmp) */

CO_Boolean CO_setBooleanWsAfterAmp(CO_Boolean arg, CO_OptLayout wsAfterAmp)
{
  if (CO_isBooleanAnd(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterAmp), 3), 1);
  }

  ATabort("Boolean has no WsAfterAmp: %t\n", arg);
  return (CO_Boolean)NULL;
}

/*}}}  */
/*{{{  CO_Boolean CO_setBooleanWsAfterNot(CO_Boolean arg, CO_OptLayout wsAfterNot) */

CO_Boolean CO_setBooleanWsAfterNot(CO_Boolean arg, CO_OptLayout wsAfterNot)
{
  if (CO_isBooleanNot(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterNot), 1), 1);
  }

  ATabort("Boolean has no WsAfterNot: %t\n", arg);
  return (CO_Boolean)NULL;
}

/*}}}  */
/*{{{  CO_Boolean CO_setBooleanWsAfterParenOpen(CO_Boolean arg, CO_OptLayout wsAfterParenOpen) */

CO_Boolean CO_setBooleanWsAfterParenOpen(CO_Boolean arg, CO_OptLayout wsAfterParenOpen)
{
  if (CO_isBooleanNot(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (CO_isBooleanBracket(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 1), 1);
  }

  ATabort("Boolean has no WsAfterParenOpen: %t\n", arg);
  return (CO_Boolean)NULL;
}

/*}}}  */
/*{{{  CO_Boolean CO_setBooleanBoolean(CO_Boolean arg, CO_Boolean Boolean) */

CO_Boolean CO_setBooleanBoolean(CO_Boolean arg, CO_Boolean Boolean)
{
  if (CO_isBooleanNot(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Boolean), 4), 1);
  }
  else if (CO_isBooleanBracket(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Boolean), 2), 1);
  }

  ATabort("Boolean has no Boolean: %t\n", arg);
  return (CO_Boolean)NULL;
}

/*}}}  */
/*{{{  CO_Boolean CO_setBooleanWsAfterBoolean(CO_Boolean arg, CO_OptLayout wsAfterBoolean) */

CO_Boolean CO_setBooleanWsAfterBoolean(CO_Boolean arg, CO_OptLayout wsAfterBoolean)
{
  if (CO_isBooleanNot(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBoolean), 5), 1);
  }
  else if (CO_isBooleanBracket(arg)) {
    return (CO_Boolean)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBoolean), 3), 1);
  }

  ATabort("Boolean has no WsAfterBoolean: %t\n", arg);
  return (CO_Boolean)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CO_Start accessors */

/*{{{  ATbool CO_isValidStart(CO_Start arg) */

ATbool CO_isValidStart(CO_Start arg)
{
  if (CO_isStartBoolean(arg)) {
    return ATtrue;
  }
  else if (CO_isStartStrCon(arg)) {
    return ATtrue;
  }
  else if (CO_isStartBoolCon(arg)) {
    return ATtrue;
  }
  else if (CO_isStartSummary(arg)) {
    return ATtrue;
  }
  else if (CO_isStartError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CO_isStartBoolean(CO_Start arg) */

inline ATbool CO_isStartBoolean(CO_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternStartBoolean, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isStartStrCon(CO_Start arg) */

inline ATbool CO_isStartStrCon(CO_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternStartStrCon, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isStartBoolCon(CO_Start arg) */

inline ATbool CO_isStartBoolCon(CO_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternStartBoolCon, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isStartSummary(CO_Start arg) */

inline ATbool CO_isStartSummary(CO_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternStartSummary, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isStartError(CO_Start arg) */

inline ATbool CO_isStartError(CO_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternStartError, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool CO_hasStartWsBefore(CO_Start arg) */

ATbool CO_hasStartWsBefore(CO_Start arg)
{
  if (CO_isStartBoolean(arg)) {
    return ATtrue;
  }
  else if (CO_isStartStrCon(arg)) {
    return ATtrue;
  }
  else if (CO_isStartBoolCon(arg)) {
    return ATtrue;
  }
  else if (CO_isStartSummary(arg)) {
    return ATtrue;
  }
  else if (CO_isStartError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasStartTopBoolean(CO_Start arg) */

ATbool CO_hasStartTopBoolean(CO_Start arg)
{
  if (CO_isStartBoolean(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasStartWsAfter(CO_Start arg) */

ATbool CO_hasStartWsAfter(CO_Start arg)
{
  if (CO_isStartBoolean(arg)) {
    return ATtrue;
  }
  else if (CO_isStartStrCon(arg)) {
    return ATtrue;
  }
  else if (CO_isStartBoolCon(arg)) {
    return ATtrue;
  }
  else if (CO_isStartSummary(arg)) {
    return ATtrue;
  }
  else if (CO_isStartError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasStartAmbCnt(CO_Start arg) */

ATbool CO_hasStartAmbCnt(CO_Start arg)
{
  if (CO_isStartBoolean(arg)) {
    return ATtrue;
  }
  else if (CO_isStartStrCon(arg)) {
    return ATtrue;
  }
  else if (CO_isStartBoolCon(arg)) {
    return ATtrue;
  }
  else if (CO_isStartSummary(arg)) {
    return ATtrue;
  }
  else if (CO_isStartError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasStartTopStrCon(CO_Start arg) */

ATbool CO_hasStartTopStrCon(CO_Start arg)
{
  if (CO_isStartStrCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasStartTopBoolCon(CO_Start arg) */

ATbool CO_hasStartTopBoolCon(CO_Start arg)
{
  if (CO_isStartBoolCon(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasStartTopSummary(CO_Start arg) */

ATbool CO_hasStartTopSummary(CO_Start arg)
{
  if (CO_isStartSummary(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasStartTopError(CO_Start arg) */

ATbool CO_hasStartTopError(CO_Start arg)
{
  if (CO_isStartError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_OptLayout CO_getStartWsBefore(CO_Start arg) */

CO_OptLayout CO_getStartWsBefore(CO_Start arg)
{
  if (CO_isStartBoolean(arg)) {
    return (CO_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (CO_isStartStrCon(arg)) {
    return (CO_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (CO_isStartBoolCon(arg)) {
    return (CO_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (CO_isStartSummary(arg)) {
    return (CO_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else 
    return (CO_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
}

/*}}}  */
/*{{{  CO_Boolean CO_getStartTopBoolean(CO_Start arg) */

CO_Boolean CO_getStartTopBoolean(CO_Start arg)
{
  
    return (CO_Boolean)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getStartWsAfter(CO_Start arg) */

CO_OptLayout CO_getStartWsAfter(CO_Start arg)
{
  if (CO_isStartBoolean(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (CO_isStartStrCon(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (CO_isStartBoolCon(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (CO_isStartSummary(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
}

/*}}}  */
/*{{{  int CO_getStartAmbCnt(CO_Start arg) */

int CO_getStartAmbCnt(CO_Start arg)
{
  if (CO_isStartBoolean(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else if (CO_isStartStrCon(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else if (CO_isStartBoolCon(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else if (CO_isStartSummary(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  CO_StrCon CO_getStartTopStrCon(CO_Start arg) */

CO_StrCon CO_getStartTopStrCon(CO_Start arg)
{
  
    return (CO_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  CO_BoolCon CO_getStartTopBoolCon(CO_Start arg) */

CO_BoolCon CO_getStartTopBoolCon(CO_Start arg)
{
  
    return (CO_BoolCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  CO_Summary CO_getStartTopSummary(CO_Start arg) */

CO_Summary CO_getStartTopSummary(CO_Start arg)
{
  
    return (CO_Summary)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  CO_Error CO_getStartTopError(CO_Start arg) */

CO_Error CO_getStartTopError(CO_Start arg)
{
  
    return (CO_Error)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  CO_Start CO_setStartWsBefore(CO_Start arg, CO_OptLayout wsBefore) */

CO_Start CO_setStartWsBefore(CO_Start arg, CO_OptLayout wsBefore)
{
  if (CO_isStartBoolean(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (CO_isStartStrCon(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (CO_isStartBoolCon(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (CO_isStartSummary(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (CO_isStartError(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }

  ATabort("Start has no WsBefore: %t\n", arg);
  return (CO_Start)NULL;
}

/*}}}  */
/*{{{  CO_Start CO_setStartTopBoolean(CO_Start arg, CO_Boolean topBoolean) */

CO_Start CO_setStartTopBoolean(CO_Start arg, CO_Boolean topBoolean)
{
  if (CO_isStartBoolean(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topBoolean), 1), 1), 0);
  }

  ATabort("Start has no TopBoolean: %t\n", arg);
  return (CO_Start)NULL;
}

/*}}}  */
/*{{{  CO_Start CO_setStartWsAfter(CO_Start arg, CO_OptLayout wsAfter) */

CO_Start CO_setStartWsAfter(CO_Start arg, CO_OptLayout wsAfter)
{
  if (CO_isStartBoolean(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (CO_isStartStrCon(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (CO_isStartBoolCon(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (CO_isStartSummary(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (CO_isStartError(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }

  ATabort("Start has no WsAfter: %t\n", arg);
  return (CO_Start)NULL;
}

/*}}}  */
/*{{{  CO_Start CO_setStartAmbCnt(CO_Start arg, int ambCnt) */

CO_Start CO_setStartAmbCnt(CO_Start arg, int ambCnt)
{
  if (CO_isStartBoolean(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (CO_isStartStrCon(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (CO_isStartBoolCon(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (CO_isStartSummary(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (CO_isStartError(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }

  ATabort("Start has no AmbCnt: %t\n", arg);
  return (CO_Start)NULL;
}

/*}}}  */
/*{{{  CO_Start CO_setStartTopStrCon(CO_Start arg, CO_StrCon topStrCon) */

CO_Start CO_setStartTopStrCon(CO_Start arg, CO_StrCon topStrCon)
{
  if (CO_isStartStrCon(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topStrCon), 1), 1), 0);
  }

  ATabort("Start has no TopStrCon: %t\n", arg);
  return (CO_Start)NULL;
}

/*}}}  */
/*{{{  CO_Start CO_setStartTopBoolCon(CO_Start arg, CO_BoolCon topBoolCon) */

CO_Start CO_setStartTopBoolCon(CO_Start arg, CO_BoolCon topBoolCon)
{
  if (CO_isStartBoolCon(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topBoolCon), 1), 1), 0);
  }

  ATabort("Start has no TopBoolCon: %t\n", arg);
  return (CO_Start)NULL;
}

/*}}}  */
/*{{{  CO_Start CO_setStartTopSummary(CO_Start arg, CO_Summary topSummary) */

CO_Start CO_setStartTopSummary(CO_Start arg, CO_Summary topSummary)
{
  if (CO_isStartSummary(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topSummary), 1), 1), 0);
  }

  ATabort("Start has no TopSummary: %t\n", arg);
  return (CO_Start)NULL;
}

/*}}}  */
/*{{{  CO_Start CO_setStartTopError(CO_Start arg, CO_Error topError) */

CO_Start CO_setStartTopError(CO_Start arg, CO_Error topError)
{
  if (CO_isStartError(arg)) {
    return (CO_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topError), 1), 1), 0);
  }

  ATabort("Start has no TopError: %t\n", arg);
  return (CO_Start)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CO_LexStrChar accessors */

/*{{{  ATbool CO_isValidLexStrChar(CO_LexStrChar arg) */

ATbool CO_isValidLexStrChar(CO_LexStrChar arg)
{
  if (CO_isLexStrCharNewline(arg)) {
    return ATtrue;
  }
  else if (CO_isLexStrCharTab(arg)) {
    return ATtrue;
  }
  else if (CO_isLexStrCharQuote(arg)) {
    return ATtrue;
  }
  else if (CO_isLexStrCharBackslash(arg)) {
    return ATtrue;
  }
  else if (CO_isLexStrCharOctal(arg)) {
    return ATtrue;
  }
  else if (CO_isLexStrCharNormal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CO_isLexStrCharNewline(CO_LexStrChar arg) */

inline ATbool CO_isLexStrCharNewline(CO_LexStrChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternLexStrCharNewline);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isLexStrCharTab(CO_LexStrChar arg) */

inline ATbool CO_isLexStrCharTab(CO_LexStrChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternLexStrCharTab);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isLexStrCharQuote(CO_LexStrChar arg) */

inline ATbool CO_isLexStrCharQuote(CO_LexStrChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternLexStrCharQuote);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isLexStrCharBackslash(CO_LexStrChar arg) */

inline ATbool CO_isLexStrCharBackslash(CO_LexStrChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternLexStrCharBackslash);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isLexStrCharOctal(CO_LexStrChar arg) */

inline ATbool CO_isLexStrCharOctal(CO_LexStrChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternLexStrCharOctal, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isLexStrCharNormal(CO_LexStrChar arg) */

inline ATbool CO_isLexStrCharNormal(CO_LexStrChar arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternLexStrCharNormal, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool CO_hasLexStrCharA(CO_LexStrChar arg) */

ATbool CO_hasLexStrCharA(CO_LexStrChar arg)
{
  if (CO_isLexStrCharOctal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasLexStrCharB(CO_LexStrChar arg) */

ATbool CO_hasLexStrCharB(CO_LexStrChar arg)
{
  if (CO_isLexStrCharOctal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasLexStrCharC(CO_LexStrChar arg) */

ATbool CO_hasLexStrCharC(CO_LexStrChar arg)
{
  if (CO_isLexStrCharOctal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasLexStrCharCh(CO_LexStrChar arg) */

ATbool CO_hasLexStrCharCh(CO_LexStrChar arg)
{
  if (CO_isLexStrCharNormal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char CO_getLexStrCharA(CO_LexStrChar arg) */

char CO_getLexStrCharA(CO_LexStrChar arg)
{
  
    return (char)CO_charToByte((ATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1));
}

/*}}}  */
/*{{{  char CO_getLexStrCharB(CO_LexStrChar arg) */

char CO_getLexStrCharB(CO_LexStrChar arg)
{
  
    return (char)CO_charToByte((ATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2));
}

/*}}}  */
/*{{{  char CO_getLexStrCharC(CO_LexStrChar arg) */

char CO_getLexStrCharC(CO_LexStrChar arg)
{
  
    return (char)CO_charToByte((ATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3));
}

/*}}}  */
/*{{{  char CO_getLexStrCharCh(CO_LexStrChar arg) */

char CO_getLexStrCharCh(CO_LexStrChar arg)
{
  
    return (char)CO_charToByte((ATerm)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  CO_LexStrChar CO_setLexStrCharA(CO_LexStrChar arg, char a) */

CO_LexStrChar CO_setLexStrCharA(CO_LexStrChar arg, char a)
{
  if (CO_isLexStrCharOctal(arg)) {
    return (CO_LexStrChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) CO_byteToChar(a))), 1), 1);
  }

  ATabort("LexStrChar has no A: %t\n", arg);
  return (CO_LexStrChar)NULL;
}

/*}}}  */
/*{{{  CO_LexStrChar CO_setLexStrCharB(CO_LexStrChar arg, char b) */

CO_LexStrChar CO_setLexStrCharB(CO_LexStrChar arg, char b)
{
  if (CO_isLexStrCharOctal(arg)) {
    return (CO_LexStrChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) CO_byteToChar(b))), 2), 1);
  }

  ATabort("LexStrChar has no B: %t\n", arg);
  return (CO_LexStrChar)NULL;
}

/*}}}  */
/*{{{  CO_LexStrChar CO_setLexStrCharC(CO_LexStrChar arg, char c) */

CO_LexStrChar CO_setLexStrCharC(CO_LexStrChar arg, char c)
{
  if (CO_isLexStrCharOctal(arg)) {
    return (CO_LexStrChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) CO_byteToChar(c))), 3), 1);
  }

  ATabort("LexStrChar has no C: %t\n", arg);
  return (CO_LexStrChar)NULL;
}

/*}}}  */
/*{{{  CO_LexStrChar CO_setLexStrCharCh(CO_LexStrChar arg, char ch) */

CO_LexStrChar CO_setLexStrCharCh(CO_LexStrChar arg, char ch)
{
  if (CO_isLexStrCharNormal(arg)) {
    return (CO_LexStrChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) CO_byteToChar(ch))), 0), 1);
  }

  ATabort("LexStrChar has no Ch: %t\n", arg);
  return (CO_LexStrChar)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CO_StrChar accessors */

/*{{{  ATbool CO_isValidStrChar(CO_StrChar arg) */

ATbool CO_isValidStrChar(CO_StrChar arg)
{
  if (CO_isStrCharLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CO_isStrCharLexToCf(CO_StrChar arg) */

inline ATbool CO_isStrCharLexToCf(CO_StrChar arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CO_patternStrCharLexToCf, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool CO_hasStrCharStrChar(CO_StrChar arg) */

ATbool CO_hasStrCharStrChar(CO_StrChar arg)
{
  if (CO_isStrCharLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_LexStrChar CO_getStrCharStrChar(CO_StrChar arg) */

CO_LexStrChar CO_getStrCharStrChar(CO_StrChar arg)
{
  
    return (CO_LexStrChar)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  CO_StrChar CO_setStrCharStrChar(CO_StrChar arg, CO_LexStrChar StrChar) */

CO_StrChar CO_setStrCharStrChar(CO_StrChar arg, CO_LexStrChar StrChar)
{
  if (CO_isStrCharLexToCf(arg)) {
    return (CO_StrChar)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) StrChar), 0), 1);
  }

  ATabort("StrChar has no StrChar: %t\n", arg);
  return (CO_StrChar)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CO_LexStrCon accessors */

/*{{{  ATbool CO_isValidLexStrCon(CO_LexStrCon arg) */

ATbool CO_isValidLexStrCon(CO_LexStrCon arg)
{
  if (CO_isLexStrConDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CO_isLexStrConDefault(CO_LexStrCon arg) */

inline ATbool CO_isLexStrConDefault(CO_LexStrCon arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CO_patternLexStrConDefault, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool CO_hasLexStrConLine(CO_LexStrCon arg) */

ATbool CO_hasLexStrConLine(CO_LexStrCon arg)
{
  if (CO_isLexStrConDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_LexStrCharLine CO_getLexStrConLine(CO_LexStrCon arg) */

CO_LexStrCharLine CO_getLexStrConLine(CO_LexStrCon arg)
{
  
    return (CO_LexStrCharLine)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1), 1);
}

/*}}}  */
/*{{{  CO_LexStrCon CO_setLexStrConLine(CO_LexStrCon arg, CO_LexStrCharLine line) */

CO_LexStrCon CO_setLexStrConLine(CO_LexStrCon arg, CO_LexStrCharLine line)
{
  if (CO_isLexStrConDefault(arg)) {
    return (CO_LexStrCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1), (ATerm)((ATerm) line), 1), 1), 1);
  }

  ATabort("LexStrCon has no Line: %t\n", arg);
  return (CO_LexStrCon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CO_StrCon accessors */

/*{{{  ATbool CO_isValidStrCon(CO_StrCon arg) */

ATbool CO_isValidStrCon(CO_StrCon arg)
{
  if (CO_isStrConLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CO_isStrConLexToCf(CO_StrCon arg) */

inline ATbool CO_isStrConLexToCf(CO_StrCon arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CO_patternStrConLexToCf, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool CO_hasStrConStrCon(CO_StrCon arg) */

ATbool CO_hasStrConStrCon(CO_StrCon arg)
{
  if (CO_isStrConLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_LexStrCon CO_getStrConStrCon(CO_StrCon arg) */

CO_LexStrCon CO_getStrConStrCon(CO_StrCon arg)
{
  
    return (CO_LexStrCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  CO_StrCon CO_setStrConStrCon(CO_StrCon arg, CO_LexStrCon StrCon) */

CO_StrCon CO_setStrConStrCon(CO_StrCon arg, CO_LexStrCon StrCon)
{
  if (CO_isStrConLexToCf(arg)) {
    return (CO_StrCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) StrCon), 0), 1);
  }

  ATabort("StrCon has no StrCon: %t\n", arg);
  return (CO_StrCon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CO_LexStrCharLine accessors */

/*{{{  ATbool CO_isValidLexStrCharLine(CO_LexStrCharLine arg) */

ATbool CO_isValidLexStrCharLine(CO_LexStrCharLine arg)
{
  if (CO_isLexStrCharLineEmpty(arg)) {
    return ATtrue;
  }
  else if (CO_isLexStrCharLineSingle(arg)) {
    return ATtrue;
  }
  else if (CO_isLexStrCharLineMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CO_isLexStrCharLineEmpty(CO_LexStrCharLine arg) */

inline ATbool CO_isLexStrCharLineEmpty(CO_LexStrCharLine arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CO_patternLexStrCharLineEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool CO_isLexStrCharLineSingle(CO_LexStrCharLine arg) */

inline ATbool CO_isLexStrCharLineSingle(CO_LexStrCharLine arg)
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
      last_result = ATmatchTerm((ATerm)arg, CO_patternLexStrCharLineSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isLexStrCharLineMany(CO_LexStrCharLine arg) */

inline ATbool CO_isLexStrCharLineMany(CO_LexStrCharLine arg)
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
      last_result = ATmatchTerm((ATerm)arg, CO_patternLexStrCharLineMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool CO_hasLexStrCharLineHead(CO_LexStrCharLine arg) */

ATbool CO_hasLexStrCharLineHead(CO_LexStrCharLine arg)
{
  if (CO_isLexStrCharLineSingle(arg)) {
    return ATtrue;
  }
  else if (CO_isLexStrCharLineMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasLexStrCharLineTail(CO_LexStrCharLine arg) */

ATbool CO_hasLexStrCharLineTail(CO_LexStrCharLine arg)
{
  if (CO_isLexStrCharLineMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_LexStrChar CO_getLexStrCharLineHead(CO_LexStrCharLine arg) */

CO_LexStrChar CO_getLexStrCharLineHead(CO_LexStrCharLine arg)
{
  if (CO_isLexStrCharLineSingle(arg)) {
    return (CO_LexStrChar)ATgetFirst((ATermList)arg);
  }
  else 
    return (CO_LexStrChar)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  CO_LexStrCharLine CO_getLexStrCharLineTail(CO_LexStrCharLine arg) */

CO_LexStrCharLine CO_getLexStrCharLineTail(CO_LexStrCharLine arg)
{
  
    return (CO_LexStrCharLine)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  CO_LexStrCharLine CO_setLexStrCharLineHead(CO_LexStrCharLine arg, CO_LexStrChar head) */

CO_LexStrCharLine CO_setLexStrCharLineHead(CO_LexStrCharLine arg, CO_LexStrChar head)
{
  if (CO_isLexStrCharLineSingle(arg)) {
    return (CO_LexStrCharLine)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (CO_isLexStrCharLineMany(arg)) {
    return (CO_LexStrCharLine)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("LexStrCharLine has no Head: %t\n", arg);
  return (CO_LexStrCharLine)NULL;
}

/*}}}  */
/*{{{  CO_LexStrCharLine CO_setLexStrCharLineTail(CO_LexStrCharLine arg, CO_LexStrCharLine tail) */

CO_LexStrCharLine CO_setLexStrCharLineTail(CO_LexStrCharLine arg, CO_LexStrCharLine tail)
{
  if (CO_isLexStrCharLineMany(arg)) {
    return (CO_LexStrCharLine)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("LexStrCharLine has no Tail: %t\n", arg);
  return (CO_LexStrCharLine)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CO_BoolCon accessors */

/*{{{  ATbool CO_isValidBoolCon(CO_BoolCon arg) */

ATbool CO_isValidBoolCon(CO_BoolCon arg)
{
  if (CO_isBoolConTrue(arg)) {
    return ATtrue;
  }
  else if (CO_isBoolConFalse(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CO_isBoolConTrue(CO_BoolCon arg) */

inline ATbool CO_isBoolConTrue(CO_BoolCon arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternBoolConTrue);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isBoolConFalse(CO_BoolCon arg) */

inline ATbool CO_isBoolConFalse(CO_BoolCon arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternBoolConFalse);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */

/*}}}  */
/*{{{  CO_LexNatCon accessors */

/*{{{  ATbool CO_isValidLexNatCon(CO_LexNatCon arg) */

ATbool CO_isValidLexNatCon(CO_LexNatCon arg)
{
  if (CO_isLexNatConDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CO_isLexNatConDefault(CO_LexNatCon arg) */

inline ATbool CO_isLexNatConDefault(CO_LexNatCon arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CO_patternLexNatConDefault, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool CO_hasLexNatConList(CO_LexNatCon arg) */

ATbool CO_hasLexNatConList(CO_LexNatCon arg)
{
  if (CO_isLexNatConDefault(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* CO_getLexNatConList(CO_LexNatCon arg) */

char* CO_getLexNatConList(CO_LexNatCon arg)
{
  
    return (char*)CO_charsToString((ATerm)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1));
}

/*}}}  */
/*{{{  CO_LexNatCon CO_setLexNatConList(CO_LexNatCon arg, const char* list) */

CO_LexNatCon CO_setLexNatConList(CO_LexNatCon arg, const char* list)
{
  if (CO_isLexNatConDefault(arg)) {
    return (CO_LexNatCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) ((ATerm) CO_stringToChars(list))), 1), 0), 1);
  }

  ATabort("LexNatCon has no List: %t\n", arg);
  return (CO_LexNatCon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CO_NatCon accessors */

/*{{{  ATbool CO_isValidNatCon(CO_NatCon arg) */

ATbool CO_isValidNatCon(CO_NatCon arg)
{
  if (CO_isNatConLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CO_isNatConLexToCf(CO_NatCon arg) */

inline ATbool CO_isNatConLexToCf(CO_NatCon arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CO_patternNatConLexToCf, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool CO_hasNatConNatCon(CO_NatCon arg) */

ATbool CO_hasNatConNatCon(CO_NatCon arg)
{
  if (CO_isNatConLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_LexNatCon CO_getNatConNatCon(CO_NatCon arg) */

CO_LexNatCon CO_getNatConNatCon(CO_NatCon arg)
{
  
    return (CO_LexNatCon)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  CO_NatCon CO_setNatConNatCon(CO_NatCon arg, CO_LexNatCon NatCon) */

CO_NatCon CO_setNatConNatCon(CO_NatCon arg, CO_LexNatCon NatCon)
{
  if (CO_isNatConLexToCf(arg)) {
    return (CO_NatCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) NatCon), 0), 1);
  }

  ATabort("NatCon has no NatCon: %t\n", arg);
  return (CO_NatCon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CO_LexByte accessors */

/*{{{  ATbool CO_isValidLexByte(CO_LexByte arg) */

ATbool CO_isValidLexByte(CO_LexByte arg)
{
  if (CO_isLexByteByte(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CO_isLexByteByte(CO_LexByte arg) */

inline ATbool CO_isLexByteByte(CO_LexByte arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CO_patternLexByteByte, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool CO_hasLexByteCh(CO_LexByte arg) */

ATbool CO_hasLexByteCh(CO_LexByte arg)
{
  if (CO_isLexByteByte(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char CO_getLexByteCh(CO_LexByte arg) */

char CO_getLexByteCh(CO_LexByte arg)
{
  
    return (char)CO_charToByte((ATerm)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  CO_LexByte CO_setLexByteCh(CO_LexByte arg, char ch) */

CO_LexByte CO_setLexByteCh(CO_LexByte arg, char ch)
{
  if (CO_isLexByteByte(arg)) {
    return (CO_LexByte)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ((ATerm) CO_byteToChar(ch))), 0), 1);
  }

  ATabort("LexByte has no Ch: %t\n", arg);
  return (CO_LexByte)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CO_Byte accessors */

/*{{{  ATbool CO_isValidByte(CO_Byte arg) */

ATbool CO_isValidByte(CO_Byte arg)
{
  if (CO_isByteLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CO_isByteLexToCf(CO_Byte arg) */

inline ATbool CO_isByteLexToCf(CO_Byte arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CO_patternByteLexToCf, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool CO_hasByteByte(CO_Byte arg) */

ATbool CO_hasByteByte(CO_Byte arg)
{
  if (CO_isByteLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_LexByte CO_getByteByte(CO_Byte arg) */

CO_LexByte CO_getByteByte(CO_Byte arg)
{
  
    return (CO_LexByte)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  CO_Byte CO_setByteByte(CO_Byte arg, CO_LexByte Byte) */

CO_Byte CO_setByteByte(CO_Byte arg, CO_LexByte Byte)
{
  if (CO_isByteLexToCf(arg)) {
    return (CO_Byte)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Byte), 0), 1);
  }

  ATabort("Byte has no Byte: %t\n", arg);
  return (CO_Byte)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CO_LexBytes accessors */

/*{{{  ATbool CO_isValidLexBytes(CO_LexBytes arg) */

ATbool CO_isValidLexBytes(CO_LexBytes arg)
{
  if (CO_isLexBytesBytes(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CO_isLexBytesBytes(CO_LexBytes arg) */

inline ATbool CO_isLexBytesBytes(CO_LexBytes arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CO_patternLexBytesBytes, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool CO_hasLexBytesList(CO_LexBytes arg) */

ATbool CO_hasLexBytesList(CO_LexBytes arg)
{
  if (CO_isLexBytesBytes(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_LexByteList CO_getLexBytesList(CO_LexBytes arg) */

CO_LexByteList CO_getLexBytesList(CO_LexBytes arg)
{
  
    return (CO_LexByteList)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1);
}

/*}}}  */
/*{{{  CO_LexBytes CO_setLexBytesList(CO_LexBytes arg, CO_LexByteList list) */

CO_LexBytes CO_setLexBytesList(CO_LexBytes arg, CO_LexByteList list)
{
  if (CO_isLexBytesBytes(arg)) {
    return (CO_LexBytes)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) list), 1), 0), 1);
  }

  ATabort("LexBytes has no List: %t\n", arg);
  return (CO_LexBytes)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CO_Bytes accessors */

/*{{{  ATbool CO_isValidBytes(CO_Bytes arg) */

ATbool CO_isValidBytes(CO_Bytes arg)
{
  if (CO_isBytesLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CO_isBytesLexToCf(CO_Bytes arg) */

inline ATbool CO_isBytesLexToCf(CO_Bytes arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CO_patternBytesLexToCf, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool CO_hasBytesBytes(CO_Bytes arg) */

ATbool CO_hasBytesBytes(CO_Bytes arg)
{
  if (CO_isBytesLexToCf(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_LexBytes CO_getBytesBytes(CO_Bytes arg) */

CO_LexBytes CO_getBytesBytes(CO_Bytes arg)
{
  
    return (CO_LexBytes)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  CO_Bytes CO_setBytesBytes(CO_Bytes arg, CO_LexBytes Bytes) */

CO_Bytes CO_setBytesBytes(CO_Bytes arg, CO_LexBytes Bytes)
{
  if (CO_isBytesLexToCf(arg)) {
    return (CO_Bytes)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Bytes), 0), 1);
  }

  ATabort("Bytes has no Bytes: %t\n", arg);
  return (CO_Bytes)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CO_LexByteList accessors */

/*{{{  ATbool CO_isValidLexByteList(CO_LexByteList arg) */

ATbool CO_isValidLexByteList(CO_LexByteList arg)
{
  if (CO_isLexByteListEmpty(arg)) {
    return ATtrue;
  }
  else if (CO_isLexByteListSingle(arg)) {
    return ATtrue;
  }
  else if (CO_isLexByteListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CO_isLexByteListEmpty(CO_LexByteList arg) */

inline ATbool CO_isLexByteListEmpty(CO_LexByteList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CO_patternLexByteListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool CO_isLexByteListSingle(CO_LexByteList arg) */

inline ATbool CO_isLexByteListSingle(CO_LexByteList arg)
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
      last_result = ATmatchTerm((ATerm)arg, CO_patternLexByteListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isLexByteListMany(CO_LexByteList arg) */

inline ATbool CO_isLexByteListMany(CO_LexByteList arg)
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
      last_result = ATmatchTerm((ATerm)arg, CO_patternLexByteListMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool CO_hasLexByteListHead(CO_LexByteList arg) */

ATbool CO_hasLexByteListHead(CO_LexByteList arg)
{
  if (CO_isLexByteListSingle(arg)) {
    return ATtrue;
  }
  else if (CO_isLexByteListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasLexByteListTail(CO_LexByteList arg) */

ATbool CO_hasLexByteListTail(CO_LexByteList arg)
{
  if (CO_isLexByteListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_LexByte CO_getLexByteListHead(CO_LexByteList arg) */

CO_LexByte CO_getLexByteListHead(CO_LexByteList arg)
{
  if (CO_isLexByteListSingle(arg)) {
    return (CO_LexByte)ATgetFirst((ATermList)arg);
  }
  else 
    return (CO_LexByte)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  CO_LexByteList CO_getLexByteListTail(CO_LexByteList arg) */

CO_LexByteList CO_getLexByteListTail(CO_LexByteList arg)
{
  
    return (CO_LexByteList)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  CO_LexByteList CO_setLexByteListHead(CO_LexByteList arg, CO_LexByte head) */

CO_LexByteList CO_setLexByteListHead(CO_LexByteList arg, CO_LexByte head)
{
  if (CO_isLexByteListSingle(arg)) {
    return (CO_LexByteList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (CO_isLexByteListMany(arg)) {
    return (CO_LexByteList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("LexByteList has no Head: %t\n", arg);
  return (CO_LexByteList)NULL;
}

/*}}}  */
/*{{{  CO_LexByteList CO_setLexByteListTail(CO_LexByteList arg, CO_LexByteList tail) */

CO_LexByteList CO_setLexByteListTail(CO_LexByteList arg, CO_LexByteList tail)
{
  if (CO_isLexByteListMany(arg)) {
    return (CO_LexByteList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("LexByteList has no Tail: %t\n", arg);
  return (CO_LexByteList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CO_Subject accessors */

/*{{{  ATbool CO_isValidSubject(CO_Subject arg) */

ATbool CO_isValidSubject(CO_Subject arg)
{
  if (CO_isSubjectSubject(arg)) {
    return ATtrue;
  }
  else if (CO_isSubjectLocalized(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CO_isSubjectSubject(CO_Subject arg) */

inline ATbool CO_isSubjectSubject(CO_Subject arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternSubjectSubject, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isSubjectLocalized(CO_Subject arg) */

inline ATbool CO_isSubjectLocalized(CO_Subject arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternSubjectLocalized, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool CO_hasSubjectWsAfterSubject(CO_Subject arg) */

ATbool CO_hasSubjectWsAfterSubject(CO_Subject arg)
{
  if (CO_isSubjectSubject(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasSubjectWsAfterParenOpen(CO_Subject arg) */

ATbool CO_hasSubjectWsAfterParenOpen(CO_Subject arg)
{
  if (CO_isSubjectSubject(arg)) {
    return ATtrue;
  }
  else if (CO_isSubjectLocalized(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasSubjectDescription(CO_Subject arg) */

ATbool CO_hasSubjectDescription(CO_Subject arg)
{
  if (CO_isSubjectSubject(arg)) {
    return ATtrue;
  }
  else if (CO_isSubjectLocalized(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasSubjectWsAfterDescription(CO_Subject arg) */

ATbool CO_hasSubjectWsAfterDescription(CO_Subject arg)
{
  if (CO_isSubjectSubject(arg)) {
    return ATtrue;
  }
  else if (CO_isSubjectLocalized(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasSubjectWsAfterLocalized(CO_Subject arg) */

ATbool CO_hasSubjectWsAfterLocalized(CO_Subject arg)
{
  if (CO_isSubjectLocalized(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasSubjectWsAfterComma(CO_Subject arg) */

ATbool CO_hasSubjectWsAfterComma(CO_Subject arg)
{
  if (CO_isSubjectLocalized(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasSubjectLocation(CO_Subject arg) */

ATbool CO_hasSubjectLocation(CO_Subject arg)
{
  if (CO_isSubjectLocalized(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasSubjectWsAfterLocation(CO_Subject arg) */

ATbool CO_hasSubjectWsAfterLocation(CO_Subject arg)
{
  if (CO_isSubjectLocalized(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_OptLayout CO_getSubjectWsAfterSubject(CO_Subject arg) */

CO_OptLayout CO_getSubjectWsAfterSubject(CO_Subject arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getSubjectWsAfterParenOpen(CO_Subject arg) */

CO_OptLayout CO_getSubjectWsAfterParenOpen(CO_Subject arg)
{
  if (CO_isSubjectSubject(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  CO_StrCon CO_getSubjectDescription(CO_Subject arg) */

CO_StrCon CO_getSubjectDescription(CO_Subject arg)
{
  if (CO_isSubjectSubject(arg)) {
    return (CO_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (CO_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getSubjectWsAfterDescription(CO_Subject arg) */

CO_OptLayout CO_getSubjectWsAfterDescription(CO_Subject arg)
{
  if (CO_isSubjectSubject(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getSubjectWsAfterLocalized(CO_Subject arg) */

CO_OptLayout CO_getSubjectWsAfterLocalized(CO_Subject arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getSubjectWsAfterComma(CO_Subject arg) */

CO_OptLayout CO_getSubjectWsAfterComma(CO_Subject arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  CO_Location CO_getSubjectLocation(CO_Subject arg) */

CO_Location CO_getSubjectLocation(CO_Subject arg)
{
  
    return (CO_Location)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getSubjectWsAfterLocation(CO_Subject arg) */

CO_OptLayout CO_getSubjectWsAfterLocation(CO_Subject arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/*}}}  */
/*{{{  CO_Subject CO_setSubjectWsAfterSubject(CO_Subject arg, CO_OptLayout wsAfterSubject) */

CO_Subject CO_setSubjectWsAfterSubject(CO_Subject arg, CO_OptLayout wsAfterSubject)
{
  if (CO_isSubjectSubject(arg)) {
    return (CO_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSubject), 1), 1);
  }

  ATabort("Subject has no WsAfterSubject: %t\n", arg);
  return (CO_Subject)NULL;
}

/*}}}  */
/*{{{  CO_Subject CO_setSubjectWsAfterParenOpen(CO_Subject arg, CO_OptLayout wsAfterParenOpen) */

CO_Subject CO_setSubjectWsAfterParenOpen(CO_Subject arg, CO_OptLayout wsAfterParenOpen)
{
  if (CO_isSubjectSubject(arg)) {
    return (CO_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (CO_isSubjectLocalized(arg)) {
    return (CO_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("Subject has no WsAfterParenOpen: %t\n", arg);
  return (CO_Subject)NULL;
}

/*}}}  */
/*{{{  CO_Subject CO_setSubjectDescription(CO_Subject arg, CO_StrCon description) */

CO_Subject CO_setSubjectDescription(CO_Subject arg, CO_StrCon description)
{
  if (CO_isSubjectSubject(arg)) {
    return (CO_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) description), 4), 1);
  }
  else if (CO_isSubjectLocalized(arg)) {
    return (CO_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) description), 4), 1);
  }

  ATabort("Subject has no Description: %t\n", arg);
  return (CO_Subject)NULL;
}

/*}}}  */
/*{{{  CO_Subject CO_setSubjectWsAfterDescription(CO_Subject arg, CO_OptLayout wsAfterDescription) */

CO_Subject CO_setSubjectWsAfterDescription(CO_Subject arg, CO_OptLayout wsAfterDescription)
{
  if (CO_isSubjectSubject(arg)) {
    return (CO_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterDescription), 5), 1);
  }
  else if (CO_isSubjectLocalized(arg)) {
    return (CO_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterDescription), 5), 1);
  }

  ATabort("Subject has no WsAfterDescription: %t\n", arg);
  return (CO_Subject)NULL;
}

/*}}}  */
/*{{{  CO_Subject CO_setSubjectWsAfterLocalized(CO_Subject arg, CO_OptLayout wsAfterLocalized) */

CO_Subject CO_setSubjectWsAfterLocalized(CO_Subject arg, CO_OptLayout wsAfterLocalized)
{
  if (CO_isSubjectLocalized(arg)) {
    return (CO_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLocalized), 1), 1);
  }

  ATabort("Subject has no WsAfterLocalized: %t\n", arg);
  return (CO_Subject)NULL;
}

/*}}}  */
/*{{{  CO_Subject CO_setSubjectWsAfterComma(CO_Subject arg, CO_OptLayout wsAfterComma) */

CO_Subject CO_setSubjectWsAfterComma(CO_Subject arg, CO_OptLayout wsAfterComma)
{
  if (CO_isSubjectLocalized(arg)) {
    return (CO_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }

  ATabort("Subject has no WsAfterComma: %t\n", arg);
  return (CO_Subject)NULL;
}

/*}}}  */
/*{{{  CO_Subject CO_setSubjectLocation(CO_Subject arg, CO_Location Location) */

CO_Subject CO_setSubjectLocation(CO_Subject arg, CO_Location Location)
{
  if (CO_isSubjectLocalized(arg)) {
    return (CO_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Location), 8), 1);
  }

  ATabort("Subject has no Location: %t\n", arg);
  return (CO_Subject)NULL;
}

/*}}}  */
/*{{{  CO_Subject CO_setSubjectWsAfterLocation(CO_Subject arg, CO_OptLayout wsAfterLocation) */

CO_Subject CO_setSubjectWsAfterLocation(CO_Subject arg, CO_OptLayout wsAfterLocation)
{
  if (CO_isSubjectLocalized(arg)) {
    return (CO_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLocation), 9), 1);
  }

  ATabort("Subject has no WsAfterLocation: %t\n", arg);
  return (CO_Subject)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CO_Error accessors */

/*{{{  ATbool CO_isValidError(CO_Error arg) */

ATbool CO_isValidError(CO_Error arg)
{
  if (CO_isErrorInfo(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorWarning(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorError(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorFatal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CO_isErrorInfo(CO_Error arg) */

inline ATbool CO_isErrorInfo(CO_Error arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternErrorInfo, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isErrorWarning(CO_Error arg) */

inline ATbool CO_isErrorWarning(CO_Error arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternErrorWarning, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isErrorError(CO_Error arg) */

inline ATbool CO_isErrorError(CO_Error arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternErrorError, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isErrorFatal(CO_Error arg) */

inline ATbool CO_isErrorFatal(CO_Error arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternErrorFatal, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool CO_hasErrorWsAfterInfo(CO_Error arg) */

ATbool CO_hasErrorWsAfterInfo(CO_Error arg)
{
  if (CO_isErrorInfo(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasErrorWsAfterParenOpen(CO_Error arg) */

ATbool CO_hasErrorWsAfterParenOpen(CO_Error arg)
{
  if (CO_isErrorInfo(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorWarning(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorError(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorFatal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasErrorDescription(CO_Error arg) */

ATbool CO_hasErrorDescription(CO_Error arg)
{
  if (CO_isErrorInfo(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorWarning(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorError(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorFatal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasErrorWsAfterDescription(CO_Error arg) */

ATbool CO_hasErrorWsAfterDescription(CO_Error arg)
{
  if (CO_isErrorInfo(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorWarning(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorError(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorFatal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasErrorWsAfterComma(CO_Error arg) */

ATbool CO_hasErrorWsAfterComma(CO_Error arg)
{
  if (CO_isErrorInfo(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorWarning(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorError(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorFatal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasErrorWsAfterBracketOpen(CO_Error arg) */

ATbool CO_hasErrorWsAfterBracketOpen(CO_Error arg)
{
  if (CO_isErrorInfo(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorWarning(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorError(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorFatal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasErrorList(CO_Error arg) */

ATbool CO_hasErrorList(CO_Error arg)
{
  if (CO_isErrorInfo(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorWarning(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorError(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorFatal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasErrorWsAfterList(CO_Error arg) */

ATbool CO_hasErrorWsAfterList(CO_Error arg)
{
  if (CO_isErrorInfo(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorWarning(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorError(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorFatal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasErrorWsAfterBracketClose(CO_Error arg) */

ATbool CO_hasErrorWsAfterBracketClose(CO_Error arg)
{
  if (CO_isErrorInfo(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorWarning(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorError(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorFatal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasErrorWsAfterWarning(CO_Error arg) */

ATbool CO_hasErrorWsAfterWarning(CO_Error arg)
{
  if (CO_isErrorWarning(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasErrorWsAfterError(CO_Error arg) */

ATbool CO_hasErrorWsAfterError(CO_Error arg)
{
  if (CO_isErrorError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasErrorWsAfterFatal(CO_Error arg) */

ATbool CO_hasErrorWsAfterFatal(CO_Error arg)
{
  if (CO_isErrorFatal(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_OptLayout CO_getErrorWsAfterInfo(CO_Error arg) */

CO_OptLayout CO_getErrorWsAfterInfo(CO_Error arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getErrorWsAfterParenOpen(CO_Error arg) */

CO_OptLayout CO_getErrorWsAfterParenOpen(CO_Error arg)
{
  if (CO_isErrorInfo(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (CO_isErrorWarning(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (CO_isErrorError(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  CO_StrCon CO_getErrorDescription(CO_Error arg) */

CO_StrCon CO_getErrorDescription(CO_Error arg)
{
  if (CO_isErrorInfo(arg)) {
    return (CO_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else if (CO_isErrorWarning(arg)) {
    return (CO_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else if (CO_isErrorError(arg)) {
    return (CO_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (CO_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getErrorWsAfterDescription(CO_Error arg) */

CO_OptLayout CO_getErrorWsAfterDescription(CO_Error arg)
{
  if (CO_isErrorInfo(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else if (CO_isErrorWarning(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else if (CO_isErrorError(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getErrorWsAfterComma(CO_Error arg) */

CO_OptLayout CO_getErrorWsAfterComma(CO_Error arg)
{
  if (CO_isErrorInfo(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else if (CO_isErrorWarning(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else if (CO_isErrorError(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getErrorWsAfterBracketOpen(CO_Error arg) */

CO_OptLayout CO_getErrorWsAfterBracketOpen(CO_Error arg)
{
  if (CO_isErrorInfo(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
  }
  else if (CO_isErrorWarning(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
  }
  else if (CO_isErrorError(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/*}}}  */
/*{{{  CO_SubjectList CO_getErrorList(CO_Error arg) */

CO_SubjectList CO_getErrorList(CO_Error arg)
{
  if (CO_isErrorInfo(arg)) {
    return (CO_SubjectList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 10), 1);
  }
  else if (CO_isErrorWarning(arg)) {
    return (CO_SubjectList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 10), 1);
  }
  else if (CO_isErrorError(arg)) {
    return (CO_SubjectList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 10), 1);
  }
  else 
    return (CO_SubjectList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 10), 1);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getErrorWsAfterList(CO_Error arg) */

CO_OptLayout CO_getErrorWsAfterList(CO_Error arg)
{
  if (CO_isErrorInfo(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 11);
  }
  else if (CO_isErrorWarning(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 11);
  }
  else if (CO_isErrorError(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 11);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 11);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getErrorWsAfterBracketClose(CO_Error arg) */

CO_OptLayout CO_getErrorWsAfterBracketClose(CO_Error arg)
{
  if (CO_isErrorInfo(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 13);
  }
  else if (CO_isErrorWarning(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 13);
  }
  else if (CO_isErrorError(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 13);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 13);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getErrorWsAfterWarning(CO_Error arg) */

CO_OptLayout CO_getErrorWsAfterWarning(CO_Error arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getErrorWsAfterError(CO_Error arg) */

CO_OptLayout CO_getErrorWsAfterError(CO_Error arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getErrorWsAfterFatal(CO_Error arg) */

CO_OptLayout CO_getErrorWsAfterFatal(CO_Error arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  CO_Error CO_setErrorWsAfterInfo(CO_Error arg, CO_OptLayout wsAfterInfo) */

CO_Error CO_setErrorWsAfterInfo(CO_Error arg, CO_OptLayout wsAfterInfo)
{
  if (CO_isErrorInfo(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterInfo), 1), 1);
  }

  ATabort("Error has no WsAfterInfo: %t\n", arg);
  return (CO_Error)NULL;
}

/*}}}  */
/*{{{  CO_Error CO_setErrorWsAfterParenOpen(CO_Error arg, CO_OptLayout wsAfterParenOpen) */

CO_Error CO_setErrorWsAfterParenOpen(CO_Error arg, CO_OptLayout wsAfterParenOpen)
{
  if (CO_isErrorInfo(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (CO_isErrorWarning(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (CO_isErrorError(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (CO_isErrorFatal(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("Error has no WsAfterParenOpen: %t\n", arg);
  return (CO_Error)NULL;
}

/*}}}  */
/*{{{  CO_Error CO_setErrorDescription(CO_Error arg, CO_StrCon description) */

CO_Error CO_setErrorDescription(CO_Error arg, CO_StrCon description)
{
  if (CO_isErrorInfo(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) description), 4), 1);
  }
  else if (CO_isErrorWarning(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) description), 4), 1);
  }
  else if (CO_isErrorError(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) description), 4), 1);
  }
  else if (CO_isErrorFatal(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) description), 4), 1);
  }

  ATabort("Error has no Description: %t\n", arg);
  return (CO_Error)NULL;
}

/*}}}  */
/*{{{  CO_Error CO_setErrorWsAfterDescription(CO_Error arg, CO_OptLayout wsAfterDescription) */

CO_Error CO_setErrorWsAfterDescription(CO_Error arg, CO_OptLayout wsAfterDescription)
{
  if (CO_isErrorInfo(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterDescription), 5), 1);
  }
  else if (CO_isErrorWarning(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterDescription), 5), 1);
  }
  else if (CO_isErrorError(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterDescription), 5), 1);
  }
  else if (CO_isErrorFatal(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterDescription), 5), 1);
  }

  ATabort("Error has no WsAfterDescription: %t\n", arg);
  return (CO_Error)NULL;
}

/*}}}  */
/*{{{  CO_Error CO_setErrorWsAfterComma(CO_Error arg, CO_OptLayout wsAfterComma) */

CO_Error CO_setErrorWsAfterComma(CO_Error arg, CO_OptLayout wsAfterComma)
{
  if (CO_isErrorInfo(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }
  else if (CO_isErrorWarning(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }
  else if (CO_isErrorError(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }
  else if (CO_isErrorFatal(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }

  ATabort("Error has no WsAfterComma: %t\n", arg);
  return (CO_Error)NULL;
}

/*}}}  */
/*{{{  CO_Error CO_setErrorWsAfterBracketOpen(CO_Error arg, CO_OptLayout wsAfterBracketOpen) */

CO_Error CO_setErrorWsAfterBracketOpen(CO_Error arg, CO_OptLayout wsAfterBracketOpen)
{
  if (CO_isErrorInfo(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 9), 1);
  }
  else if (CO_isErrorWarning(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 9), 1);
  }
  else if (CO_isErrorError(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 9), 1);
  }
  else if (CO_isErrorFatal(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 9), 1);
  }

  ATabort("Error has no WsAfterBracketOpen: %t\n", arg);
  return (CO_Error)NULL;
}

/*}}}  */
/*{{{  CO_Error CO_setErrorList(CO_Error arg, CO_SubjectList list) */

CO_Error CO_setErrorList(CO_Error arg, CO_SubjectList list)
{
  if (CO_isErrorInfo(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 10), (ATerm)((ATerm) list), 1), 10), 1);
  }
  else if (CO_isErrorWarning(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 10), (ATerm)((ATerm) list), 1), 10), 1);
  }
  else if (CO_isErrorError(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 10), (ATerm)((ATerm) list), 1), 10), 1);
  }
  else if (CO_isErrorFatal(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 10), (ATerm)((ATerm) list), 1), 10), 1);
  }

  ATabort("Error has no List: %t\n", arg);
  return (CO_Error)NULL;
}

/*}}}  */
/*{{{  CO_Error CO_setErrorWsAfterList(CO_Error arg, CO_OptLayout wsAfterList) */

CO_Error CO_setErrorWsAfterList(CO_Error arg, CO_OptLayout wsAfterList)
{
  if (CO_isErrorInfo(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterList), 11), 1);
  }
  else if (CO_isErrorWarning(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterList), 11), 1);
  }
  else if (CO_isErrorError(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterList), 11), 1);
  }
  else if (CO_isErrorFatal(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterList), 11), 1);
  }

  ATabort("Error has no WsAfterList: %t\n", arg);
  return (CO_Error)NULL;
}

/*}}}  */
/*{{{  CO_Error CO_setErrorWsAfterBracketClose(CO_Error arg, CO_OptLayout wsAfterBracketClose) */

CO_Error CO_setErrorWsAfterBracketClose(CO_Error arg, CO_OptLayout wsAfterBracketClose)
{
  if (CO_isErrorInfo(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketClose), 13), 1);
  }
  else if (CO_isErrorWarning(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketClose), 13), 1);
  }
  else if (CO_isErrorError(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketClose), 13), 1);
  }
  else if (CO_isErrorFatal(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketClose), 13), 1);
  }

  ATabort("Error has no WsAfterBracketClose: %t\n", arg);
  return (CO_Error)NULL;
}

/*}}}  */
/*{{{  CO_Error CO_setErrorWsAfterWarning(CO_Error arg, CO_OptLayout wsAfterWarning) */

CO_Error CO_setErrorWsAfterWarning(CO_Error arg, CO_OptLayout wsAfterWarning)
{
  if (CO_isErrorWarning(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterWarning), 1), 1);
  }

  ATabort("Error has no WsAfterWarning: %t\n", arg);
  return (CO_Error)NULL;
}

/*}}}  */
/*{{{  CO_Error CO_setErrorWsAfterError(CO_Error arg, CO_OptLayout wsAfterError) */

CO_Error CO_setErrorWsAfterError(CO_Error arg, CO_OptLayout wsAfterError)
{
  if (CO_isErrorError(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterError), 1), 1);
  }

  ATabort("Error has no WsAfterError: %t\n", arg);
  return (CO_Error)NULL;
}

/*}}}  */
/*{{{  CO_Error CO_setErrorWsAfterFatal(CO_Error arg, CO_OptLayout wsAfterFatal) */

CO_Error CO_setErrorWsAfterFatal(CO_Error arg, CO_OptLayout wsAfterFatal)
{
  if (CO_isErrorFatal(arg)) {
    return (CO_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterFatal), 1), 1);
  }

  ATabort("Error has no WsAfterFatal: %t\n", arg);
  return (CO_Error)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CO_Summary accessors */

/*{{{  ATbool CO_isValidSummary(CO_Summary arg) */

ATbool CO_isValidSummary(CO_Summary arg)
{
  if (CO_isSummarySummary(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CO_isSummarySummary(CO_Summary arg) */

inline ATbool CO_isSummarySummary(CO_Summary arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CO_patternSummarySummary, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool CO_hasSummaryWsAfterSummary(CO_Summary arg) */

ATbool CO_hasSummaryWsAfterSummary(CO_Summary arg)
{
  if (CO_isSummarySummary(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasSummaryWsAfterParenOpen(CO_Summary arg) */

ATbool CO_hasSummaryWsAfterParenOpen(CO_Summary arg)
{
  if (CO_isSummarySummary(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasSummaryProducer(CO_Summary arg) */

ATbool CO_hasSummaryProducer(CO_Summary arg)
{
  if (CO_isSummarySummary(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasSummaryWsAfterProducer(CO_Summary arg) */

ATbool CO_hasSummaryWsAfterProducer(CO_Summary arg)
{
  if (CO_isSummarySummary(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasSummaryWsAfterComma(CO_Summary arg) */

ATbool CO_hasSummaryWsAfterComma(CO_Summary arg)
{
  if (CO_isSummarySummary(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasSummaryId(CO_Summary arg) */

ATbool CO_hasSummaryId(CO_Summary arg)
{
  if (CO_isSummarySummary(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasSummaryWsAfterId(CO_Summary arg) */

ATbool CO_hasSummaryWsAfterId(CO_Summary arg)
{
  if (CO_isSummarySummary(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasSummaryWsAfterComma1(CO_Summary arg) */

ATbool CO_hasSummaryWsAfterComma1(CO_Summary arg)
{
  if (CO_isSummarySummary(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasSummaryWsAfterBracketOpen(CO_Summary arg) */

ATbool CO_hasSummaryWsAfterBracketOpen(CO_Summary arg)
{
  if (CO_isSummarySummary(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasSummaryList(CO_Summary arg) */

ATbool CO_hasSummaryList(CO_Summary arg)
{
  if (CO_isSummarySummary(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasSummaryWsAfterList(CO_Summary arg) */

ATbool CO_hasSummaryWsAfterList(CO_Summary arg)
{
  if (CO_isSummarySummary(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasSummaryWsAfterBracketClose(CO_Summary arg) */

ATbool CO_hasSummaryWsAfterBracketClose(CO_Summary arg)
{
  if (CO_isSummarySummary(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_OptLayout CO_getSummaryWsAfterSummary(CO_Summary arg) */

CO_OptLayout CO_getSummaryWsAfterSummary(CO_Summary arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getSummaryWsAfterParenOpen(CO_Summary arg) */

CO_OptLayout CO_getSummaryWsAfterParenOpen(CO_Summary arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  CO_StrCon CO_getSummaryProducer(CO_Summary arg) */

CO_StrCon CO_getSummaryProducer(CO_Summary arg)
{
  
    return (CO_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getSummaryWsAfterProducer(CO_Summary arg) */

CO_OptLayout CO_getSummaryWsAfterProducer(CO_Summary arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getSummaryWsAfterComma(CO_Summary arg) */

CO_OptLayout CO_getSummaryWsAfterComma(CO_Summary arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  CO_StrCon CO_getSummaryId(CO_Summary arg) */

CO_StrCon CO_getSummaryId(CO_Summary arg)
{
  
    return (CO_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getSummaryWsAfterId(CO_Summary arg) */

CO_OptLayout CO_getSummaryWsAfterId(CO_Summary arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getSummaryWsAfterComma1(CO_Summary arg) */

CO_OptLayout CO_getSummaryWsAfterComma1(CO_Summary arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 11);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getSummaryWsAfterBracketOpen(CO_Summary arg) */

CO_OptLayout CO_getSummaryWsAfterBracketOpen(CO_Summary arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 13);
}

/*}}}  */
/*{{{  CO_ErrorList CO_getSummaryList(CO_Summary arg) */

CO_ErrorList CO_getSummaryList(CO_Summary arg)
{
  
    return (CO_ErrorList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 14), 1);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getSummaryWsAfterList(CO_Summary arg) */

CO_OptLayout CO_getSummaryWsAfterList(CO_Summary arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 15);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getSummaryWsAfterBracketClose(CO_Summary arg) */

CO_OptLayout CO_getSummaryWsAfterBracketClose(CO_Summary arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 17);
}

/*}}}  */
/*{{{  CO_Summary CO_setSummaryWsAfterSummary(CO_Summary arg, CO_OptLayout wsAfterSummary) */

CO_Summary CO_setSummaryWsAfterSummary(CO_Summary arg, CO_OptLayout wsAfterSummary)
{
  if (CO_isSummarySummary(arg)) {
    return (CO_Summary)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSummary), 1), 1);
  }

  ATabort("Summary has no WsAfterSummary: %t\n", arg);
  return (CO_Summary)NULL;
}

/*}}}  */
/*{{{  CO_Summary CO_setSummaryWsAfterParenOpen(CO_Summary arg, CO_OptLayout wsAfterParenOpen) */

CO_Summary CO_setSummaryWsAfterParenOpen(CO_Summary arg, CO_OptLayout wsAfterParenOpen)
{
  if (CO_isSummarySummary(arg)) {
    return (CO_Summary)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("Summary has no WsAfterParenOpen: %t\n", arg);
  return (CO_Summary)NULL;
}

/*}}}  */
/*{{{  CO_Summary CO_setSummaryProducer(CO_Summary arg, CO_StrCon producer) */

CO_Summary CO_setSummaryProducer(CO_Summary arg, CO_StrCon producer)
{
  if (CO_isSummarySummary(arg)) {
    return (CO_Summary)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) producer), 4), 1);
  }

  ATabort("Summary has no Producer: %t\n", arg);
  return (CO_Summary)NULL;
}

/*}}}  */
/*{{{  CO_Summary CO_setSummaryWsAfterProducer(CO_Summary arg, CO_OptLayout wsAfterProducer) */

CO_Summary CO_setSummaryWsAfterProducer(CO_Summary arg, CO_OptLayout wsAfterProducer)
{
  if (CO_isSummarySummary(arg)) {
    return (CO_Summary)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterProducer), 5), 1);
  }

  ATabort("Summary has no WsAfterProducer: %t\n", arg);
  return (CO_Summary)NULL;
}

/*}}}  */
/*{{{  CO_Summary CO_setSummaryWsAfterComma(CO_Summary arg, CO_OptLayout wsAfterComma) */

CO_Summary CO_setSummaryWsAfterComma(CO_Summary arg, CO_OptLayout wsAfterComma)
{
  if (CO_isSummarySummary(arg)) {
    return (CO_Summary)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }

  ATabort("Summary has no WsAfterComma: %t\n", arg);
  return (CO_Summary)NULL;
}

/*}}}  */
/*{{{  CO_Summary CO_setSummaryId(CO_Summary arg, CO_StrCon id) */

CO_Summary CO_setSummaryId(CO_Summary arg, CO_StrCon id)
{
  if (CO_isSummarySummary(arg)) {
    return (CO_Summary)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) id), 8), 1);
  }

  ATabort("Summary has no Id: %t\n", arg);
  return (CO_Summary)NULL;
}

/*}}}  */
/*{{{  CO_Summary CO_setSummaryWsAfterId(CO_Summary arg, CO_OptLayout wsAfterId) */

CO_Summary CO_setSummaryWsAfterId(CO_Summary arg, CO_OptLayout wsAfterId)
{
  if (CO_isSummarySummary(arg)) {
    return (CO_Summary)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterId), 9), 1);
  }

  ATabort("Summary has no WsAfterId: %t\n", arg);
  return (CO_Summary)NULL;
}

/*}}}  */
/*{{{  CO_Summary CO_setSummaryWsAfterComma1(CO_Summary arg, CO_OptLayout wsAfterComma1) */

CO_Summary CO_setSummaryWsAfterComma1(CO_Summary arg, CO_OptLayout wsAfterComma1)
{
  if (CO_isSummarySummary(arg)) {
    return (CO_Summary)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma1), 11), 1);
  }

  ATabort("Summary has no WsAfterComma1: %t\n", arg);
  return (CO_Summary)NULL;
}

/*}}}  */
/*{{{  CO_Summary CO_setSummaryWsAfterBracketOpen(CO_Summary arg, CO_OptLayout wsAfterBracketOpen) */

CO_Summary CO_setSummaryWsAfterBracketOpen(CO_Summary arg, CO_OptLayout wsAfterBracketOpen)
{
  if (CO_isSummarySummary(arg)) {
    return (CO_Summary)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 13), 1);
  }

  ATabort("Summary has no WsAfterBracketOpen: %t\n", arg);
  return (CO_Summary)NULL;
}

/*}}}  */
/*{{{  CO_Summary CO_setSummaryList(CO_Summary arg, CO_ErrorList list) */

CO_Summary CO_setSummaryList(CO_Summary arg, CO_ErrorList list)
{
  if (CO_isSummarySummary(arg)) {
    return (CO_Summary)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 14), (ATerm)((ATerm) list), 1), 14), 1);
  }

  ATabort("Summary has no List: %t\n", arg);
  return (CO_Summary)NULL;
}

/*}}}  */
/*{{{  CO_Summary CO_setSummaryWsAfterList(CO_Summary arg, CO_OptLayout wsAfterList) */

CO_Summary CO_setSummaryWsAfterList(CO_Summary arg, CO_OptLayout wsAfterList)
{
  if (CO_isSummarySummary(arg)) {
    return (CO_Summary)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterList), 15), 1);
  }

  ATabort("Summary has no WsAfterList: %t\n", arg);
  return (CO_Summary)NULL;
}

/*}}}  */
/*{{{  CO_Summary CO_setSummaryWsAfterBracketClose(CO_Summary arg, CO_OptLayout wsAfterBracketClose) */

CO_Summary CO_setSummaryWsAfterBracketClose(CO_Summary arg, CO_OptLayout wsAfterBracketClose)
{
  if (CO_isSummarySummary(arg)) {
    return (CO_Summary)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketClose), 17), 1);
  }

  ATabort("Summary has no WsAfterBracketClose: %t\n", arg);
  return (CO_Summary)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CO_SubjectList accessors */

/*{{{  ATbool CO_isValidSubjectList(CO_SubjectList arg) */

ATbool CO_isValidSubjectList(CO_SubjectList arg)
{
  if (CO_isSubjectListEmpty(arg)) {
    return ATtrue;
  }
  else if (CO_isSubjectListSingle(arg)) {
    return ATtrue;
  }
  else if (CO_isSubjectListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CO_isSubjectListEmpty(CO_SubjectList arg) */

inline ATbool CO_isSubjectListEmpty(CO_SubjectList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CO_patternSubjectListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool CO_isSubjectListSingle(CO_SubjectList arg) */

inline ATbool CO_isSubjectListSingle(CO_SubjectList arg)
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
      last_result = ATmatchTerm((ATerm)arg, CO_patternSubjectListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isSubjectListMany(CO_SubjectList arg) */

inline ATbool CO_isSubjectListMany(CO_SubjectList arg)
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
      last_result = ATmatchTerm((ATerm)arg, CO_patternSubjectListMany, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool CO_hasSubjectListHead(CO_SubjectList arg) */

ATbool CO_hasSubjectListHead(CO_SubjectList arg)
{
  if (CO_isSubjectListSingle(arg)) {
    return ATtrue;
  }
  else if (CO_isSubjectListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasSubjectListWsAfterHead(CO_SubjectList arg) */

ATbool CO_hasSubjectListWsAfterHead(CO_SubjectList arg)
{
  if (CO_isSubjectListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasSubjectListWsAfterSep(CO_SubjectList arg) */

ATbool CO_hasSubjectListWsAfterSep(CO_SubjectList arg)
{
  if (CO_isSubjectListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasSubjectListTail(CO_SubjectList arg) */

ATbool CO_hasSubjectListTail(CO_SubjectList arg)
{
  if (CO_isSubjectListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_SubjectList CO_getSubjectListTail(CO_SubjectList arg) */

CO_SubjectList CO_getSubjectListTail(CO_SubjectList arg)
{
  assert(!CO_isSubjectListEmpty(arg) && "getTail on an empty list");
  if (CO_isSubjectListSingle(arg)) {
    return (CO_SubjectList) CO_makeSubjectListEmpty();
  }
  else {
  
    return (CO_SubjectList)ATgetTail((ATermList)arg, 4);
  }
}

/*}}}  */
/*{{{  CO_Subject CO_getSubjectListHead(CO_SubjectList arg) */

CO_Subject CO_getSubjectListHead(CO_SubjectList arg)
{
  if (CO_isSubjectListSingle(arg)) {
    return (CO_Subject)ATgetFirst((ATermList)arg);
  }
  else 
    return (CO_Subject)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getSubjectListWsAfterHead(CO_SubjectList arg) */

CO_OptLayout CO_getSubjectListWsAfterHead(CO_SubjectList arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getSubjectListWsAfterSep(CO_SubjectList arg) */

CO_OptLayout CO_getSubjectListWsAfterSep(CO_SubjectList arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  CO_SubjectList CO_setSubjectListHead(CO_SubjectList arg, CO_Subject head) */

CO_SubjectList CO_setSubjectListHead(CO_SubjectList arg, CO_Subject head)
{
  if (CO_isSubjectListSingle(arg)) {
    return (CO_SubjectList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (CO_isSubjectListMany(arg)) {
    return (CO_SubjectList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("SubjectList has no Head: %t\n", arg);
  return (CO_SubjectList)NULL;
}

/*}}}  */
/*{{{  CO_SubjectList CO_setSubjectListWsAfterHead(CO_SubjectList arg, CO_OptLayout wsAfterHead) */

CO_SubjectList CO_setSubjectListWsAfterHead(CO_SubjectList arg, CO_OptLayout wsAfterHead)
{
  if (CO_isSubjectListMany(arg)) {
    return (CO_SubjectList)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterHead), 1);
  }

  ATabort("SubjectList has no WsAfterHead: %t\n", arg);
  return (CO_SubjectList)NULL;
}

/*}}}  */
/*{{{  CO_SubjectList CO_setSubjectListWsAfterSep(CO_SubjectList arg, CO_OptLayout wsAfterSep) */

CO_SubjectList CO_setSubjectListWsAfterSep(CO_SubjectList arg, CO_OptLayout wsAfterSep)
{
  if (CO_isSubjectListMany(arg)) {
    return (CO_SubjectList)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterSep), 3);
  }

  ATabort("SubjectList has no WsAfterSep: %t\n", arg);
  return (CO_SubjectList)NULL;
}

/*}}}  */
/*{{{  CO_SubjectList CO_setSubjectListTail(CO_SubjectList arg, CO_SubjectList tail) */

CO_SubjectList CO_setSubjectListTail(CO_SubjectList arg, CO_SubjectList tail)
{
  if (CO_isSubjectListMany(arg)) {
    return (CO_SubjectList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 4);
  }

  ATabort("SubjectList has no Tail: %t\n", arg);
  return (CO_SubjectList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CO_ErrorList accessors */

/*{{{  ATbool CO_isValidErrorList(CO_ErrorList arg) */

ATbool CO_isValidErrorList(CO_ErrorList arg)
{
  if (CO_isErrorListEmpty(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorListSingle(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CO_isErrorListEmpty(CO_ErrorList arg) */

inline ATbool CO_isErrorListEmpty(CO_ErrorList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CO_patternErrorListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool CO_isErrorListSingle(CO_ErrorList arg) */

inline ATbool CO_isErrorListSingle(CO_ErrorList arg)
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
      last_result = ATmatchTerm((ATerm)arg, CO_patternErrorListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isErrorListMany(CO_ErrorList arg) */

inline ATbool CO_isErrorListMany(CO_ErrorList arg)
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
      last_result = ATmatchTerm((ATerm)arg, CO_patternErrorListMany, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool CO_hasErrorListHead(CO_ErrorList arg) */

ATbool CO_hasErrorListHead(CO_ErrorList arg)
{
  if (CO_isErrorListSingle(arg)) {
    return ATtrue;
  }
  else if (CO_isErrorListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasErrorListWsAfterHead(CO_ErrorList arg) */

ATbool CO_hasErrorListWsAfterHead(CO_ErrorList arg)
{
  if (CO_isErrorListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasErrorListWsAfterSep(CO_ErrorList arg) */

ATbool CO_hasErrorListWsAfterSep(CO_ErrorList arg)
{
  if (CO_isErrorListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasErrorListTail(CO_ErrorList arg) */

ATbool CO_hasErrorListTail(CO_ErrorList arg)
{
  if (CO_isErrorListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_ErrorList CO_getErrorListTail(CO_ErrorList arg) */

CO_ErrorList CO_getErrorListTail(CO_ErrorList arg)
{
  assert(!CO_isErrorListEmpty(arg) && "getTail on an empty list");
  if (CO_isErrorListSingle(arg)) {
    return (CO_ErrorList) CO_makeErrorListEmpty();
  }
  else {
  
    return (CO_ErrorList)ATgetTail((ATermList)arg, 4);
  }
}

/*}}}  */
/*{{{  CO_Error CO_getErrorListHead(CO_ErrorList arg) */

CO_Error CO_getErrorListHead(CO_ErrorList arg)
{
  if (CO_isErrorListSingle(arg)) {
    return (CO_Error)ATgetFirst((ATermList)arg);
  }
  else 
    return (CO_Error)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getErrorListWsAfterHead(CO_ErrorList arg) */

CO_OptLayout CO_getErrorListWsAfterHead(CO_ErrorList arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getErrorListWsAfterSep(CO_ErrorList arg) */

CO_OptLayout CO_getErrorListWsAfterSep(CO_ErrorList arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  CO_ErrorList CO_setErrorListHead(CO_ErrorList arg, CO_Error head) */

CO_ErrorList CO_setErrorListHead(CO_ErrorList arg, CO_Error head)
{
  if (CO_isErrorListSingle(arg)) {
    return (CO_ErrorList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (CO_isErrorListMany(arg)) {
    return (CO_ErrorList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("ErrorList has no Head: %t\n", arg);
  return (CO_ErrorList)NULL;
}

/*}}}  */
/*{{{  CO_ErrorList CO_setErrorListWsAfterHead(CO_ErrorList arg, CO_OptLayout wsAfterHead) */

CO_ErrorList CO_setErrorListWsAfterHead(CO_ErrorList arg, CO_OptLayout wsAfterHead)
{
  if (CO_isErrorListMany(arg)) {
    return (CO_ErrorList)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterHead), 1);
  }

  ATabort("ErrorList has no WsAfterHead: %t\n", arg);
  return (CO_ErrorList)NULL;
}

/*}}}  */
/*{{{  CO_ErrorList CO_setErrorListWsAfterSep(CO_ErrorList arg, CO_OptLayout wsAfterSep) */

CO_ErrorList CO_setErrorListWsAfterSep(CO_ErrorList arg, CO_OptLayout wsAfterSep)
{
  if (CO_isErrorListMany(arg)) {
    return (CO_ErrorList)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterSep), 3);
  }

  ATabort("ErrorList has no WsAfterSep: %t\n", arg);
  return (CO_ErrorList)NULL;
}

/*}}}  */
/*{{{  CO_ErrorList CO_setErrorListTail(CO_ErrorList arg, CO_ErrorList tail) */

CO_ErrorList CO_setErrorListTail(CO_ErrorList arg, CO_ErrorList tail)
{
  if (CO_isErrorListMany(arg)) {
    return (CO_ErrorList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 4);
  }

  ATabort("ErrorList has no Tail: %t\n", arg);
  return (CO_ErrorList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CO_Location accessors */

/*{{{  ATbool CO_isValidLocation(CO_Location arg) */

ATbool CO_isValidLocation(CO_Location arg)
{
  if (CO_isLocationFile(arg)) {
    return ATtrue;
  }
  else if (CO_isLocationArea(arg)) {
    return ATtrue;
  }
  else if (CO_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CO_isLocationFile(CO_Location arg) */

inline ATbool CO_isLocationFile(CO_Location arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternLocationFile, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isLocationArea(CO_Location arg) */

inline ATbool CO_isLocationArea(CO_Location arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternLocationArea, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isLocationAreaInFile(CO_Location arg) */

inline ATbool CO_isLocationAreaInFile(CO_Location arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternLocationAreaInFile, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool CO_hasLocationWsAfterFile(CO_Location arg) */

ATbool CO_hasLocationWsAfterFile(CO_Location arg)
{
  if (CO_isLocationFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasLocationWsAfterParenOpen(CO_Location arg) */

ATbool CO_hasLocationWsAfterParenOpen(CO_Location arg)
{
  if (CO_isLocationFile(arg)) {
    return ATtrue;
  }
  else if (CO_isLocationArea(arg)) {
    return ATtrue;
  }
  else if (CO_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasLocationFilename(CO_Location arg) */

ATbool CO_hasLocationFilename(CO_Location arg)
{
  if (CO_isLocationFile(arg)) {
    return ATtrue;
  }
  else if (CO_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasLocationWsAfterFilename(CO_Location arg) */

ATbool CO_hasLocationWsAfterFilename(CO_Location arg)
{
  if (CO_isLocationFile(arg)) {
    return ATtrue;
  }
  else if (CO_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasLocationWsAfterA(CO_Location arg) */

ATbool CO_hasLocationWsAfterA(CO_Location arg)
{
  if (CO_isLocationArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasLocationArea(CO_Location arg) */

ATbool CO_hasLocationArea(CO_Location arg)
{
  if (CO_isLocationArea(arg)) {
    return ATtrue;
  }
  else if (CO_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasLocationWsAfterArea(CO_Location arg) */

ATbool CO_hasLocationWsAfterArea(CO_Location arg)
{
  if (CO_isLocationArea(arg)) {
    return ATtrue;
  }
  else if (CO_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasLocationWsAfterAreaInFile(CO_Location arg) */

ATbool CO_hasLocationWsAfterAreaInFile(CO_Location arg)
{
  if (CO_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasLocationWsAfterComma(CO_Location arg) */

ATbool CO_hasLocationWsAfterComma(CO_Location arg)
{
  if (CO_isLocationAreaInFile(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_OptLayout CO_getLocationWsAfterFile(CO_Location arg) */

CO_OptLayout CO_getLocationWsAfterFile(CO_Location arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getLocationWsAfterParenOpen(CO_Location arg) */

CO_OptLayout CO_getLocationWsAfterParenOpen(CO_Location arg)
{
  if (CO_isLocationFile(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (CO_isLocationArea(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  CO_StrCon CO_getLocationFilename(CO_Location arg) */

CO_StrCon CO_getLocationFilename(CO_Location arg)
{
  if (CO_isLocationFile(arg)) {
    return (CO_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (CO_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getLocationWsAfterFilename(CO_Location arg) */

CO_OptLayout CO_getLocationWsAfterFilename(CO_Location arg)
{
  if (CO_isLocationFile(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getLocationWsAfterA(CO_Location arg) */

CO_OptLayout CO_getLocationWsAfterA(CO_Location arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  CO_Area CO_getLocationArea(CO_Location arg) */

CO_Area CO_getLocationArea(CO_Location arg)
{
  if (CO_isLocationArea(arg)) {
    return (CO_Area)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (CO_Area)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getLocationWsAfterArea(CO_Location arg) */

CO_OptLayout CO_getLocationWsAfterArea(CO_Location arg)
{
  if (CO_isLocationArea(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getLocationWsAfterAreaInFile(CO_Location arg) */

CO_OptLayout CO_getLocationWsAfterAreaInFile(CO_Location arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getLocationWsAfterComma(CO_Location arg) */

CO_OptLayout CO_getLocationWsAfterComma(CO_Location arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  CO_Location CO_setLocationWsAfterFile(CO_Location arg, CO_OptLayout wsAfterFile) */

CO_Location CO_setLocationWsAfterFile(CO_Location arg, CO_OptLayout wsAfterFile)
{
  if (CO_isLocationFile(arg)) {
    return (CO_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterFile), 1), 1);
  }

  ATabort("Location has no WsAfterFile: %t\n", arg);
  return (CO_Location)NULL;
}

/*}}}  */
/*{{{  CO_Location CO_setLocationWsAfterParenOpen(CO_Location arg, CO_OptLayout wsAfterParenOpen) */

CO_Location CO_setLocationWsAfterParenOpen(CO_Location arg, CO_OptLayout wsAfterParenOpen)
{
  if (CO_isLocationFile(arg)) {
    return (CO_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (CO_isLocationArea(arg)) {
    return (CO_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (CO_isLocationAreaInFile(arg)) {
    return (CO_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("Location has no WsAfterParenOpen: %t\n", arg);
  return (CO_Location)NULL;
}

/*}}}  */
/*{{{  CO_Location CO_setLocationFilename(CO_Location arg, CO_StrCon filename) */

CO_Location CO_setLocationFilename(CO_Location arg, CO_StrCon filename)
{
  if (CO_isLocationFile(arg)) {
    return (CO_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) filename), 4), 1);
  }
  else if (CO_isLocationAreaInFile(arg)) {
    return (CO_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) filename), 4), 1);
  }

  ATabort("Location has no Filename: %t\n", arg);
  return (CO_Location)NULL;
}

/*}}}  */
/*{{{  CO_Location CO_setLocationWsAfterFilename(CO_Location arg, CO_OptLayout wsAfterFilename) */

CO_Location CO_setLocationWsAfterFilename(CO_Location arg, CO_OptLayout wsAfterFilename)
{
  if (CO_isLocationFile(arg)) {
    return (CO_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterFilename), 5), 1);
  }
  else if (CO_isLocationAreaInFile(arg)) {
    return (CO_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterFilename), 5), 1);
  }

  ATabort("Location has no WsAfterFilename: %t\n", arg);
  return (CO_Location)NULL;
}

/*}}}  */
/*{{{  CO_Location CO_setLocationWsAfterA(CO_Location arg, CO_OptLayout wsAfterA) */

CO_Location CO_setLocationWsAfterA(CO_Location arg, CO_OptLayout wsAfterA)
{
  if (CO_isLocationArea(arg)) {
    return (CO_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterA), 1), 1);
  }

  ATabort("Location has no WsAfterA: %t\n", arg);
  return (CO_Location)NULL;
}

/*}}}  */
/*{{{  CO_Location CO_setLocationArea(CO_Location arg, CO_Area Area) */

CO_Location CO_setLocationArea(CO_Location arg, CO_Area Area)
{
  if (CO_isLocationArea(arg)) {
    return (CO_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Area), 4), 1);
  }
  else if (CO_isLocationAreaInFile(arg)) {
    return (CO_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Area), 8), 1);
  }

  ATabort("Location has no Area: %t\n", arg);
  return (CO_Location)NULL;
}

/*}}}  */
/*{{{  CO_Location CO_setLocationWsAfterArea(CO_Location arg, CO_OptLayout wsAfterArea) */

CO_Location CO_setLocationWsAfterArea(CO_Location arg, CO_OptLayout wsAfterArea)
{
  if (CO_isLocationArea(arg)) {
    return (CO_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterArea), 5), 1);
  }
  else if (CO_isLocationAreaInFile(arg)) {
    return (CO_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterArea), 9), 1);
  }

  ATabort("Location has no WsAfterArea: %t\n", arg);
  return (CO_Location)NULL;
}

/*}}}  */
/*{{{  CO_Location CO_setLocationWsAfterAreaInFile(CO_Location arg, CO_OptLayout wsAfterAreaInFile) */

CO_Location CO_setLocationWsAfterAreaInFile(CO_Location arg, CO_OptLayout wsAfterAreaInFile)
{
  if (CO_isLocationAreaInFile(arg)) {
    return (CO_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterAreaInFile), 1), 1);
  }

  ATabort("Location has no WsAfterAreaInFile: %t\n", arg);
  return (CO_Location)NULL;
}

/*}}}  */
/*{{{  CO_Location CO_setLocationWsAfterComma(CO_Location arg, CO_OptLayout wsAfterComma) */

CO_Location CO_setLocationWsAfterComma(CO_Location arg, CO_OptLayout wsAfterComma)
{
  if (CO_isLocationAreaInFile(arg)) {
    return (CO_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }

  ATabort("Location has no WsAfterComma: %t\n", arg);
  return (CO_Location)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CO_Area accessors */

/*{{{  ATbool CO_isValidArea(CO_Area arg) */

ATbool CO_isValidArea(CO_Area arg)
{
  if (CO_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CO_isAreaArea(CO_Area arg) */

inline ATbool CO_isAreaArea(CO_Area arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CO_patternAreaArea, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool CO_hasAreaWsAfterArea(CO_Area arg) */

ATbool CO_hasAreaWsAfterArea(CO_Area arg)
{
  if (CO_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasAreaWsAfterParenOpen(CO_Area arg) */

ATbool CO_hasAreaWsAfterParenOpen(CO_Area arg)
{
  if (CO_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasAreaBeginLine(CO_Area arg) */

ATbool CO_hasAreaBeginLine(CO_Area arg)
{
  if (CO_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasAreaWsAfterBeginLine(CO_Area arg) */

ATbool CO_hasAreaWsAfterBeginLine(CO_Area arg)
{
  if (CO_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasAreaWsAfterComma(CO_Area arg) */

ATbool CO_hasAreaWsAfterComma(CO_Area arg)
{
  if (CO_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasAreaBeginColumn(CO_Area arg) */

ATbool CO_hasAreaBeginColumn(CO_Area arg)
{
  if (CO_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasAreaWsAfterBeginColumn(CO_Area arg) */

ATbool CO_hasAreaWsAfterBeginColumn(CO_Area arg)
{
  if (CO_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasAreaWsAfterComma1(CO_Area arg) */

ATbool CO_hasAreaWsAfterComma1(CO_Area arg)
{
  if (CO_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasAreaEndLine(CO_Area arg) */

ATbool CO_hasAreaEndLine(CO_Area arg)
{
  if (CO_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasAreaWsAfterEndLine(CO_Area arg) */

ATbool CO_hasAreaWsAfterEndLine(CO_Area arg)
{
  if (CO_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasAreaWsAfterComma2(CO_Area arg) */

ATbool CO_hasAreaWsAfterComma2(CO_Area arg)
{
  if (CO_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasAreaEndColumn(CO_Area arg) */

ATbool CO_hasAreaEndColumn(CO_Area arg)
{
  if (CO_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasAreaWsAfterEndColumn(CO_Area arg) */

ATbool CO_hasAreaWsAfterEndColumn(CO_Area arg)
{
  if (CO_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasAreaWsAfterComma3(CO_Area arg) */

ATbool CO_hasAreaWsAfterComma3(CO_Area arg)
{
  if (CO_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasAreaOffset(CO_Area arg) */

ATbool CO_hasAreaOffset(CO_Area arg)
{
  if (CO_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasAreaWsAfterOffset(CO_Area arg) */

ATbool CO_hasAreaWsAfterOffset(CO_Area arg)
{
  if (CO_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasAreaWsAfterComma4(CO_Area arg) */

ATbool CO_hasAreaWsAfterComma4(CO_Area arg)
{
  if (CO_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasAreaLength(CO_Area arg) */

ATbool CO_hasAreaLength(CO_Area arg)
{
  if (CO_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasAreaWsAfterLength(CO_Area arg) */

ATbool CO_hasAreaWsAfterLength(CO_Area arg)
{
  if (CO_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_OptLayout CO_getAreaWsAfterArea(CO_Area arg) */

CO_OptLayout CO_getAreaWsAfterArea(CO_Area arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getAreaWsAfterParenOpen(CO_Area arg) */

CO_OptLayout CO_getAreaWsAfterParenOpen(CO_Area arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  CO_NatCon CO_getAreaBeginLine(CO_Area arg) */

CO_NatCon CO_getAreaBeginLine(CO_Area arg)
{
  
    return (CO_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getAreaWsAfterBeginLine(CO_Area arg) */

CO_OptLayout CO_getAreaWsAfterBeginLine(CO_Area arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getAreaWsAfterComma(CO_Area arg) */

CO_OptLayout CO_getAreaWsAfterComma(CO_Area arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  CO_NatCon CO_getAreaBeginColumn(CO_Area arg) */

CO_NatCon CO_getAreaBeginColumn(CO_Area arg)
{
  
    return (CO_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getAreaWsAfterBeginColumn(CO_Area arg) */

CO_OptLayout CO_getAreaWsAfterBeginColumn(CO_Area arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getAreaWsAfterComma1(CO_Area arg) */

CO_OptLayout CO_getAreaWsAfterComma1(CO_Area arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 11);
}

/*}}}  */
/*{{{  CO_NatCon CO_getAreaEndLine(CO_Area arg) */

CO_NatCon CO_getAreaEndLine(CO_Area arg)
{
  
    return (CO_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 12);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getAreaWsAfterEndLine(CO_Area arg) */

CO_OptLayout CO_getAreaWsAfterEndLine(CO_Area arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 13);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getAreaWsAfterComma2(CO_Area arg) */

CO_OptLayout CO_getAreaWsAfterComma2(CO_Area arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 15);
}

/*}}}  */
/*{{{  CO_NatCon CO_getAreaEndColumn(CO_Area arg) */

CO_NatCon CO_getAreaEndColumn(CO_Area arg)
{
  
    return (CO_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 16);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getAreaWsAfterEndColumn(CO_Area arg) */

CO_OptLayout CO_getAreaWsAfterEndColumn(CO_Area arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 17);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getAreaWsAfterComma3(CO_Area arg) */

CO_OptLayout CO_getAreaWsAfterComma3(CO_Area arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 19);
}

/*}}}  */
/*{{{  CO_NatCon CO_getAreaOffset(CO_Area arg) */

CO_NatCon CO_getAreaOffset(CO_Area arg)
{
  
    return (CO_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 20);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getAreaWsAfterOffset(CO_Area arg) */

CO_OptLayout CO_getAreaWsAfterOffset(CO_Area arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 21);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getAreaWsAfterComma4(CO_Area arg) */

CO_OptLayout CO_getAreaWsAfterComma4(CO_Area arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 23);
}

/*}}}  */
/*{{{  CO_NatCon CO_getAreaLength(CO_Area arg) */

CO_NatCon CO_getAreaLength(CO_Area arg)
{
  
    return (CO_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 24);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getAreaWsAfterLength(CO_Area arg) */

CO_OptLayout CO_getAreaWsAfterLength(CO_Area arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 25);
}

/*}}}  */
/*{{{  CO_Area CO_setAreaWsAfterArea(CO_Area arg, CO_OptLayout wsAfterArea) */

CO_Area CO_setAreaWsAfterArea(CO_Area arg, CO_OptLayout wsAfterArea)
{
  if (CO_isAreaArea(arg)) {
    return (CO_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterArea), 1), 1);
  }

  ATabort("Area has no WsAfterArea: %t\n", arg);
  return (CO_Area)NULL;
}

/*}}}  */
/*{{{  CO_Area CO_setAreaWsAfterParenOpen(CO_Area arg, CO_OptLayout wsAfterParenOpen) */

CO_Area CO_setAreaWsAfterParenOpen(CO_Area arg, CO_OptLayout wsAfterParenOpen)
{
  if (CO_isAreaArea(arg)) {
    return (CO_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("Area has no WsAfterParenOpen: %t\n", arg);
  return (CO_Area)NULL;
}

/*}}}  */
/*{{{  CO_Area CO_setAreaBeginLine(CO_Area arg, CO_NatCon beginLine) */

CO_Area CO_setAreaBeginLine(CO_Area arg, CO_NatCon beginLine)
{
  if (CO_isAreaArea(arg)) {
    return (CO_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) beginLine), 4), 1);
  }

  ATabort("Area has no BeginLine: %t\n", arg);
  return (CO_Area)NULL;
}

/*}}}  */
/*{{{  CO_Area CO_setAreaWsAfterBeginLine(CO_Area arg, CO_OptLayout wsAfterBeginLine) */

CO_Area CO_setAreaWsAfterBeginLine(CO_Area arg, CO_OptLayout wsAfterBeginLine)
{
  if (CO_isAreaArea(arg)) {
    return (CO_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBeginLine), 5), 1);
  }

  ATabort("Area has no WsAfterBeginLine: %t\n", arg);
  return (CO_Area)NULL;
}

/*}}}  */
/*{{{  CO_Area CO_setAreaWsAfterComma(CO_Area arg, CO_OptLayout wsAfterComma) */

CO_Area CO_setAreaWsAfterComma(CO_Area arg, CO_OptLayout wsAfterComma)
{
  if (CO_isAreaArea(arg)) {
    return (CO_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }

  ATabort("Area has no WsAfterComma: %t\n", arg);
  return (CO_Area)NULL;
}

/*}}}  */
/*{{{  CO_Area CO_setAreaBeginColumn(CO_Area arg, CO_NatCon beginColumn) */

CO_Area CO_setAreaBeginColumn(CO_Area arg, CO_NatCon beginColumn)
{
  if (CO_isAreaArea(arg)) {
    return (CO_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) beginColumn), 8), 1);
  }

  ATabort("Area has no BeginColumn: %t\n", arg);
  return (CO_Area)NULL;
}

/*}}}  */
/*{{{  CO_Area CO_setAreaWsAfterBeginColumn(CO_Area arg, CO_OptLayout wsAfterBeginColumn) */

CO_Area CO_setAreaWsAfterBeginColumn(CO_Area arg, CO_OptLayout wsAfterBeginColumn)
{
  if (CO_isAreaArea(arg)) {
    return (CO_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBeginColumn), 9), 1);
  }

  ATabort("Area has no WsAfterBeginColumn: %t\n", arg);
  return (CO_Area)NULL;
}

/*}}}  */
/*{{{  CO_Area CO_setAreaWsAfterComma1(CO_Area arg, CO_OptLayout wsAfterComma1) */

CO_Area CO_setAreaWsAfterComma1(CO_Area arg, CO_OptLayout wsAfterComma1)
{
  if (CO_isAreaArea(arg)) {
    return (CO_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma1), 11), 1);
  }

  ATabort("Area has no WsAfterComma1: %t\n", arg);
  return (CO_Area)NULL;
}

/*}}}  */
/*{{{  CO_Area CO_setAreaEndLine(CO_Area arg, CO_NatCon endLine) */

CO_Area CO_setAreaEndLine(CO_Area arg, CO_NatCon endLine)
{
  if (CO_isAreaArea(arg)) {
    return (CO_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) endLine), 12), 1);
  }

  ATabort("Area has no EndLine: %t\n", arg);
  return (CO_Area)NULL;
}

/*}}}  */
/*{{{  CO_Area CO_setAreaWsAfterEndLine(CO_Area arg, CO_OptLayout wsAfterEndLine) */

CO_Area CO_setAreaWsAfterEndLine(CO_Area arg, CO_OptLayout wsAfterEndLine)
{
  if (CO_isAreaArea(arg)) {
    return (CO_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterEndLine), 13), 1);
  }

  ATabort("Area has no WsAfterEndLine: %t\n", arg);
  return (CO_Area)NULL;
}

/*}}}  */
/*{{{  CO_Area CO_setAreaWsAfterComma2(CO_Area arg, CO_OptLayout wsAfterComma2) */

CO_Area CO_setAreaWsAfterComma2(CO_Area arg, CO_OptLayout wsAfterComma2)
{
  if (CO_isAreaArea(arg)) {
    return (CO_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma2), 15), 1);
  }

  ATabort("Area has no WsAfterComma2: %t\n", arg);
  return (CO_Area)NULL;
}

/*}}}  */
/*{{{  CO_Area CO_setAreaEndColumn(CO_Area arg, CO_NatCon endColumn) */

CO_Area CO_setAreaEndColumn(CO_Area arg, CO_NatCon endColumn)
{
  if (CO_isAreaArea(arg)) {
    return (CO_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) endColumn), 16), 1);
  }

  ATabort("Area has no EndColumn: %t\n", arg);
  return (CO_Area)NULL;
}

/*}}}  */
/*{{{  CO_Area CO_setAreaWsAfterEndColumn(CO_Area arg, CO_OptLayout wsAfterEndColumn) */

CO_Area CO_setAreaWsAfterEndColumn(CO_Area arg, CO_OptLayout wsAfterEndColumn)
{
  if (CO_isAreaArea(arg)) {
    return (CO_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterEndColumn), 17), 1);
  }

  ATabort("Area has no WsAfterEndColumn: %t\n", arg);
  return (CO_Area)NULL;
}

/*}}}  */
/*{{{  CO_Area CO_setAreaWsAfterComma3(CO_Area arg, CO_OptLayout wsAfterComma3) */

CO_Area CO_setAreaWsAfterComma3(CO_Area arg, CO_OptLayout wsAfterComma3)
{
  if (CO_isAreaArea(arg)) {
    return (CO_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma3), 19), 1);
  }

  ATabort("Area has no WsAfterComma3: %t\n", arg);
  return (CO_Area)NULL;
}

/*}}}  */
/*{{{  CO_Area CO_setAreaOffset(CO_Area arg, CO_NatCon offset) */

CO_Area CO_setAreaOffset(CO_Area arg, CO_NatCon offset)
{
  if (CO_isAreaArea(arg)) {
    return (CO_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) offset), 20), 1);
  }

  ATabort("Area has no Offset: %t\n", arg);
  return (CO_Area)NULL;
}

/*}}}  */
/*{{{  CO_Area CO_setAreaWsAfterOffset(CO_Area arg, CO_OptLayout wsAfterOffset) */

CO_Area CO_setAreaWsAfterOffset(CO_Area arg, CO_OptLayout wsAfterOffset)
{
  if (CO_isAreaArea(arg)) {
    return (CO_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterOffset), 21), 1);
  }

  ATabort("Area has no WsAfterOffset: %t\n", arg);
  return (CO_Area)NULL;
}

/*}}}  */
/*{{{  CO_Area CO_setAreaWsAfterComma4(CO_Area arg, CO_OptLayout wsAfterComma4) */

CO_Area CO_setAreaWsAfterComma4(CO_Area arg, CO_OptLayout wsAfterComma4)
{
  if (CO_isAreaArea(arg)) {
    return (CO_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma4), 23), 1);
  }

  ATabort("Area has no WsAfterComma4: %t\n", arg);
  return (CO_Area)NULL;
}

/*}}}  */
/*{{{  CO_Area CO_setAreaLength(CO_Area arg, CO_NatCon length) */

CO_Area CO_setAreaLength(CO_Area arg, CO_NatCon length)
{
  if (CO_isAreaArea(arg)) {
    return (CO_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) length), 24), 1);
  }

  ATabort("Area has no Length: %t\n", arg);
  return (CO_Area)NULL;
}

/*}}}  */
/*{{{  CO_Area CO_setAreaWsAfterLength(CO_Area arg, CO_OptLayout wsAfterLength) */

CO_Area CO_setAreaWsAfterLength(CO_Area arg, CO_OptLayout wsAfterLength)
{
  if (CO_isAreaArea(arg)) {
    return (CO_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLength), 25), 1);
  }

  ATabort("Area has no WsAfterLength: %t\n", arg);
  return (CO_Area)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CO_Read accessors */

/*{{{  ATbool CO_isValidRead(CO_Read arg) */

ATbool CO_isValidRead(CO_Read arg)
{
  if (CO_isReadSuccess(arg)) {
    return ATtrue;
  }
  else if (CO_isReadFailure(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CO_isReadSuccess(CO_Read arg) */

inline ATbool CO_isReadSuccess(CO_Read arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternReadSuccess, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isReadFailure(CO_Read arg) */

inline ATbool CO_isReadFailure(CO_Read arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternReadFailure, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool CO_hasReadWsAfterRead(CO_Read arg) */

ATbool CO_hasReadWsAfterRead(CO_Read arg)
{
  if (CO_isReadSuccess(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasReadWsAfterParenOpen(CO_Read arg) */

ATbool CO_hasReadWsAfterParenOpen(CO_Read arg)
{
  if (CO_isReadSuccess(arg)) {
    return ATtrue;
  }
  else if (CO_isReadFailure(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasReadValue(CO_Read arg) */

ATbool CO_hasReadValue(CO_Read arg)
{
  if (CO_isReadSuccess(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasReadWsAfterValue(CO_Read arg) */

ATbool CO_hasReadWsAfterValue(CO_Read arg)
{
  if (CO_isReadSuccess(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasReadWsAfterReadError(CO_Read arg) */

ATbool CO_hasReadWsAfterReadError(CO_Read arg)
{
  if (CO_isReadFailure(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasReadSummary(CO_Read arg) */

ATbool CO_hasReadSummary(CO_Read arg)
{
  if (CO_isReadFailure(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasReadWsAfterSummary(CO_Read arg) */

ATbool CO_hasReadWsAfterSummary(CO_Read arg)
{
  if (CO_isReadFailure(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_OptLayout CO_getReadWsAfterRead(CO_Read arg) */

CO_OptLayout CO_getReadWsAfterRead(CO_Read arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getReadWsAfterParenOpen(CO_Read arg) */

CO_OptLayout CO_getReadWsAfterParenOpen(CO_Read arg)
{
  if (CO_isReadSuccess(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  CO_Bytes CO_getReadValue(CO_Read arg) */

CO_Bytes CO_getReadValue(CO_Read arg)
{
  
    return (CO_Bytes)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getReadWsAfterValue(CO_Read arg) */

CO_OptLayout CO_getReadWsAfterValue(CO_Read arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getReadWsAfterReadError(CO_Read arg) */

CO_OptLayout CO_getReadWsAfterReadError(CO_Read arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  CO_Summary CO_getReadSummary(CO_Read arg) */

CO_Summary CO_getReadSummary(CO_Read arg)
{
  
    return (CO_Summary)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getReadWsAfterSummary(CO_Read arg) */

CO_OptLayout CO_getReadWsAfterSummary(CO_Read arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  CO_Read CO_setReadWsAfterRead(CO_Read arg, CO_OptLayout wsAfterRead) */

CO_Read CO_setReadWsAfterRead(CO_Read arg, CO_OptLayout wsAfterRead)
{
  if (CO_isReadSuccess(arg)) {
    return (CO_Read)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterRead), 1), 1);
  }

  ATabort("Read has no WsAfterRead: %t\n", arg);
  return (CO_Read)NULL;
}

/*}}}  */
/*{{{  CO_Read CO_setReadWsAfterParenOpen(CO_Read arg, CO_OptLayout wsAfterParenOpen) */

CO_Read CO_setReadWsAfterParenOpen(CO_Read arg, CO_OptLayout wsAfterParenOpen)
{
  if (CO_isReadSuccess(arg)) {
    return (CO_Read)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (CO_isReadFailure(arg)) {
    return (CO_Read)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("Read has no WsAfterParenOpen: %t\n", arg);
  return (CO_Read)NULL;
}

/*}}}  */
/*{{{  CO_Read CO_setReadValue(CO_Read arg, CO_Bytes value) */

CO_Read CO_setReadValue(CO_Read arg, CO_Bytes value)
{
  if (CO_isReadSuccess(arg)) {
    return (CO_Read)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) value), 4), 1);
  }

  ATabort("Read has no Value: %t\n", arg);
  return (CO_Read)NULL;
}

/*}}}  */
/*{{{  CO_Read CO_setReadWsAfterValue(CO_Read arg, CO_OptLayout wsAfterValue) */

CO_Read CO_setReadWsAfterValue(CO_Read arg, CO_OptLayout wsAfterValue)
{
  if (CO_isReadSuccess(arg)) {
    return (CO_Read)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterValue), 5), 1);
  }

  ATabort("Read has no WsAfterValue: %t\n", arg);
  return (CO_Read)NULL;
}

/*}}}  */
/*{{{  CO_Read CO_setReadWsAfterReadError(CO_Read arg, CO_OptLayout wsAfterReadError) */

CO_Read CO_setReadWsAfterReadError(CO_Read arg, CO_OptLayout wsAfterReadError)
{
  if (CO_isReadFailure(arg)) {
    return (CO_Read)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterReadError), 1), 1);
  }

  ATabort("Read has no WsAfterReadError: %t\n", arg);
  return (CO_Read)NULL;
}

/*}}}  */
/*{{{  CO_Read CO_setReadSummary(CO_Read arg, CO_Summary Summary) */

CO_Read CO_setReadSummary(CO_Read arg, CO_Summary Summary)
{
  if (CO_isReadFailure(arg)) {
    return (CO_Read)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Summary), 4), 1);
  }

  ATabort("Read has no Summary: %t\n", arg);
  return (CO_Read)NULL;
}

/*}}}  */
/*{{{  CO_Read CO_setReadWsAfterSummary(CO_Read arg, CO_OptLayout wsAfterSummary) */

CO_Read CO_setReadWsAfterSummary(CO_Read arg, CO_OptLayout wsAfterSummary)
{
  if (CO_isReadFailure(arg)) {
    return (CO_Read)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSummary), 5), 1);
  }

  ATabort("Read has no WsAfterSummary: %t\n", arg);
  return (CO_Read)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CO_Write accessors */

/*{{{  ATbool CO_isValidWrite(CO_Write arg) */

ATbool CO_isValidWrite(CO_Write arg)
{
  if (CO_isWriteSuccess(arg)) {
    return ATtrue;
  }
  else if (CO_isWriteFailure(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CO_isWriteSuccess(CO_Write arg) */

inline ATbool CO_isWriteSuccess(CO_Write arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternWriteSuccess);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isWriteFailure(CO_Write arg) */

inline ATbool CO_isWriteFailure(CO_Write arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternWriteFailure, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool CO_hasWriteWsAfterWriteError(CO_Write arg) */

ATbool CO_hasWriteWsAfterWriteError(CO_Write arg)
{
  if (CO_isWriteFailure(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasWriteWsAfterParenOpen(CO_Write arg) */

ATbool CO_hasWriteWsAfterParenOpen(CO_Write arg)
{
  if (CO_isWriteFailure(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasWriteSummary(CO_Write arg) */

ATbool CO_hasWriteSummary(CO_Write arg)
{
  if (CO_isWriteFailure(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasWriteWsAfterSummary(CO_Write arg) */

ATbool CO_hasWriteWsAfterSummary(CO_Write arg)
{
  if (CO_isWriteFailure(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  CO_OptLayout CO_getWriteWsAfterWriteError(CO_Write arg) */

CO_OptLayout CO_getWriteWsAfterWriteError(CO_Write arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getWriteWsAfterParenOpen(CO_Write arg) */

CO_OptLayout CO_getWriteWsAfterParenOpen(CO_Write arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  CO_Summary CO_getWriteSummary(CO_Write arg) */

CO_Summary CO_getWriteSummary(CO_Write arg)
{
  
    return (CO_Summary)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getWriteWsAfterSummary(CO_Write arg) */

CO_OptLayout CO_getWriteWsAfterSummary(CO_Write arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  CO_Write CO_setWriteWsAfterWriteError(CO_Write arg, CO_OptLayout wsAfterWriteError) */

CO_Write CO_setWriteWsAfterWriteError(CO_Write arg, CO_OptLayout wsAfterWriteError)
{
  if (CO_isWriteFailure(arg)) {
    return (CO_Write)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterWriteError), 1), 1);
  }

  ATabort("Write has no WsAfterWriteError: %t\n", arg);
  return (CO_Write)NULL;
}

/*}}}  */
/*{{{  CO_Write CO_setWriteWsAfterParenOpen(CO_Write arg, CO_OptLayout wsAfterParenOpen) */

CO_Write CO_setWriteWsAfterParenOpen(CO_Write arg, CO_OptLayout wsAfterParenOpen)
{
  if (CO_isWriteFailure(arg)) {
    return (CO_Write)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("Write has no WsAfterParenOpen: %t\n", arg);
  return (CO_Write)NULL;
}

/*}}}  */
/*{{{  CO_Write CO_setWriteSummary(CO_Write arg, CO_Summary Summary) */

CO_Write CO_setWriteSummary(CO_Write arg, CO_Summary Summary)
{
  if (CO_isWriteFailure(arg)) {
    return (CO_Write)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Summary), 4), 1);
  }

  ATabort("Write has no Summary: %t\n", arg);
  return (CO_Write)NULL;
}

/*}}}  */
/*{{{  CO_Write CO_setWriteWsAfterSummary(CO_Write arg, CO_OptLayout wsAfterSummary) */

CO_Write CO_setWriteWsAfterSummary(CO_Write arg, CO_OptLayout wsAfterSummary)
{
  if (CO_isWriteFailure(arg)) {
    return (CO_Write)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSummary), 5), 1);
  }

  ATabort("Write has no WsAfterSummary: %t\n", arg);
  return (CO_Write)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CO_ParsetreeX accessors */

/*{{{  ATbool CO_isValidParsetreeX(CO_ParsetreeX arg) */

ATbool CO_isValidParsetreeX(CO_ParsetreeX arg)
{
  if (CO_isParsetreeXSuccess(arg)) {
    return ATtrue;
  }
  else if (CO_isParsetreeXFailure(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CO_isParsetreeXSuccess(CO_ParsetreeX arg) */

inline ATbool CO_isParsetreeXSuccess(CO_ParsetreeX arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternParsetreeXSuccess, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool CO_isParsetreeXFailure(CO_ParsetreeX arg) */

inline ATbool CO_isParsetreeXFailure(CO_ParsetreeX arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, CO_patternParsetreeXFailure, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool CO_hasParsetreeXTypeOfTree(CO_ParsetreeX arg) */

ATbool CO_hasParsetreeXTypeOfTree(CO_ParsetreeX arg)
{
  if (CO_isParsetreeXSuccess(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasParsetreeXTypeOfX(CO_ParsetreeX arg) */

ATbool CO_hasParsetreeXTypeOfX(CO_ParsetreeX arg)
{
  if (CO_isParsetreeXSuccess(arg)) {
    return ATtrue;
  }
  else if (CO_isParsetreeXFailure(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasParsetreeXWsAfterParseTree(CO_ParsetreeX arg) */

ATbool CO_hasParsetreeXWsAfterParseTree(CO_ParsetreeX arg)
{
  if (CO_isParsetreeXSuccess(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasParsetreeXWsAfterParenOpen(CO_ParsetreeX arg) */

ATbool CO_hasParsetreeXWsAfterParenOpen(CO_ParsetreeX arg)
{
  if (CO_isParsetreeXSuccess(arg)) {
    return ATtrue;
  }
  else if (CO_isParsetreeXFailure(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasParsetreeXLeftLayout(CO_ParsetreeX arg) */

ATbool CO_hasParsetreeXLeftLayout(CO_ParsetreeX arg)
{
  if (CO_isParsetreeXSuccess(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasParsetreeXWsAfterLeftLayout(CO_ParsetreeX arg) */

ATbool CO_hasParsetreeXWsAfterLeftLayout(CO_ParsetreeX arg)
{
  if (CO_isParsetreeXSuccess(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasParsetreeXWsAfterComma(CO_ParsetreeX arg) */

ATbool CO_hasParsetreeXWsAfterComma(CO_ParsetreeX arg)
{
  if (CO_isParsetreeXSuccess(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasParsetreeXTree(CO_ParsetreeX arg) */

ATbool CO_hasParsetreeXTree(CO_ParsetreeX arg)
{
  if (CO_isParsetreeXSuccess(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasParsetreeXWsAfterTree(CO_ParsetreeX arg) */

ATbool CO_hasParsetreeXWsAfterTree(CO_ParsetreeX arg)
{
  if (CO_isParsetreeXSuccess(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasParsetreeXWsAfterComma1(CO_ParsetreeX arg) */

ATbool CO_hasParsetreeXWsAfterComma1(CO_ParsetreeX arg)
{
  if (CO_isParsetreeXSuccess(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasParsetreeXRightLayout(CO_ParsetreeX arg) */

ATbool CO_hasParsetreeXRightLayout(CO_ParsetreeX arg)
{
  if (CO_isParsetreeXSuccess(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasParsetreeXWsAfterRightLayout(CO_ParsetreeX arg) */

ATbool CO_hasParsetreeXWsAfterRightLayout(CO_ParsetreeX arg)
{
  if (CO_isParsetreeXSuccess(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasParsetreeXWsAfterComma2(CO_ParsetreeX arg) */

ATbool CO_hasParsetreeXWsAfterComma2(CO_ParsetreeX arg)
{
  if (CO_isParsetreeXSuccess(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasParsetreeXAmbCnt(CO_ParsetreeX arg) */

ATbool CO_hasParsetreeXAmbCnt(CO_ParsetreeX arg)
{
  if (CO_isParsetreeXSuccess(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasParsetreeXWsAfterAmbCnt(CO_ParsetreeX arg) */

ATbool CO_hasParsetreeXWsAfterAmbCnt(CO_ParsetreeX arg)
{
  if (CO_isParsetreeXSuccess(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasParsetreeXWsAfterParseError(CO_ParsetreeX arg) */

ATbool CO_hasParsetreeXWsAfterParseError(CO_ParsetreeX arg)
{
  if (CO_isParsetreeXFailure(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasParsetreeXSummary(CO_ParsetreeX arg) */

ATbool CO_hasParsetreeXSummary(CO_ParsetreeX arg)
{
  if (CO_isParsetreeXFailure(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATbool CO_hasParsetreeXWsAfterSummary(CO_ParsetreeX arg) */

ATbool CO_hasParsetreeXWsAfterSummary(CO_ParsetreeX arg)
{
  if (CO_isParsetreeXFailure(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATerm CO_getParsetreeXTypeOfTree(CO_ParsetreeX arg) */

ATerm CO_getParsetreeXTypeOfTree(CO_ParsetreeX arg)
{
  
    return (ATerm)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), 8);
}

/*}}}  */
/*{{{  ATerm CO_getParsetreeXTypeOfX(CO_ParsetreeX arg) */

ATerm CO_getParsetreeXTypeOfX(CO_ParsetreeX arg)
{
  if (CO_isParsetreeXSuccess(arg)) {
    return (ATerm)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 0), 1));
  }
  else 
    return (ATerm)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 0), 1));
}

/*}}}  */
/*{{{  CO_OptLayout CO_getParsetreeXWsAfterParseTree(CO_ParsetreeX arg) */

CO_OptLayout CO_getParsetreeXWsAfterParseTree(CO_ParsetreeX arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getParsetreeXWsAfterParenOpen(CO_ParsetreeX arg) */

CO_OptLayout CO_getParsetreeXWsAfterParenOpen(CO_ParsetreeX arg)
{
  if (CO_isParsetreeXSuccess(arg)) {
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  CO_Bytes CO_getParsetreeXLeftLayout(CO_ParsetreeX arg) */

CO_Bytes CO_getParsetreeXLeftLayout(CO_ParsetreeX arg)
{
  
    return (CO_Bytes)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getParsetreeXWsAfterLeftLayout(CO_ParsetreeX arg) */

CO_OptLayout CO_getParsetreeXWsAfterLeftLayout(CO_ParsetreeX arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getParsetreeXWsAfterComma(CO_ParsetreeX arg) */

CO_OptLayout CO_getParsetreeXWsAfterComma(CO_ParsetreeX arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  CO_X CO_getParsetreeXTree(CO_ParsetreeX arg) */

CO_X CO_getParsetreeXTree(CO_ParsetreeX arg)
{
  
    return (CO_X)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getParsetreeXWsAfterTree(CO_ParsetreeX arg) */

CO_OptLayout CO_getParsetreeXWsAfterTree(CO_ParsetreeX arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getParsetreeXWsAfterComma1(CO_ParsetreeX arg) */

CO_OptLayout CO_getParsetreeXWsAfterComma1(CO_ParsetreeX arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 11);
}

/*}}}  */
/*{{{  CO_Bytes CO_getParsetreeXRightLayout(CO_ParsetreeX arg) */

CO_Bytes CO_getParsetreeXRightLayout(CO_ParsetreeX arg)
{
  
    return (CO_Bytes)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 12);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getParsetreeXWsAfterRightLayout(CO_ParsetreeX arg) */

CO_OptLayout CO_getParsetreeXWsAfterRightLayout(CO_ParsetreeX arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 13);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getParsetreeXWsAfterComma2(CO_ParsetreeX arg) */

CO_OptLayout CO_getParsetreeXWsAfterComma2(CO_ParsetreeX arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 15);
}

/*}}}  */
/*{{{  CO_NatCon CO_getParsetreeXAmbCnt(CO_ParsetreeX arg) */

CO_NatCon CO_getParsetreeXAmbCnt(CO_ParsetreeX arg)
{
  
    return (CO_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 16);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getParsetreeXWsAfterAmbCnt(CO_ParsetreeX arg) */

CO_OptLayout CO_getParsetreeXWsAfterAmbCnt(CO_ParsetreeX arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 17);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getParsetreeXWsAfterParseError(CO_ParsetreeX arg) */

CO_OptLayout CO_getParsetreeXWsAfterParseError(CO_ParsetreeX arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  CO_Summary CO_getParsetreeXSummary(CO_ParsetreeX arg) */

CO_Summary CO_getParsetreeXSummary(CO_ParsetreeX arg)
{
  
    return (CO_Summary)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  CO_OptLayout CO_getParsetreeXWsAfterSummary(CO_ParsetreeX arg) */

CO_OptLayout CO_getParsetreeXWsAfterSummary(CO_ParsetreeX arg)
{
  
    return (CO_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  CO_ParsetreeX CO_setParsetreeXTypeOfTree(CO_ParsetreeX arg, ATerm typeOfTree) */

CO_ParsetreeX CO_setParsetreeXTypeOfTree(CO_ParsetreeX arg, ATerm typeOfTree)
{
  if (CO_isParsetreeXSuccess(arg)) {
    return (CO_ParsetreeX)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 0), (ATerm)((ATerm) typeOfTree), 8), 0), 0);
  }

  ATabort("ParsetreeX has no TypeOfTree: %t\n", arg);
  return (CO_ParsetreeX)NULL;
}

/*}}}  */
/*{{{  CO_ParsetreeX CO_setParsetreeXTypeOfX(CO_ParsetreeX arg, ATerm typeOfX) */

CO_ParsetreeX CO_setParsetreeXTypeOfX(CO_ParsetreeX arg, ATerm typeOfX)
{
  if (CO_isParsetreeXSuccess(arg)) {
    return (CO_ParsetreeX)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 0), 1), (ATerm)((ATerm) typeOfX), 0), 1), 0), 1), 0);
  }
  else if (CO_isParsetreeXFailure(arg)) {
    return (CO_ParsetreeX)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 0), 1), (ATerm)((ATerm) typeOfX), 0), 1), 0), 1), 0);
  }

  ATabort("ParsetreeX has no TypeOfX: %t\n", arg);
  return (CO_ParsetreeX)NULL;
}

/*}}}  */
/*{{{  CO_ParsetreeX CO_setParsetreeXWsAfterParseTree(CO_ParsetreeX arg, CO_OptLayout wsAfterParseTree) */

CO_ParsetreeX CO_setParsetreeXWsAfterParseTree(CO_ParsetreeX arg, CO_OptLayout wsAfterParseTree)
{
  if (CO_isParsetreeXSuccess(arg)) {
    return (CO_ParsetreeX)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParseTree), 1), 1);
  }

  ATabort("ParsetreeX has no WsAfterParseTree: %t\n", arg);
  return (CO_ParsetreeX)NULL;
}

/*}}}  */
/*{{{  CO_ParsetreeX CO_setParsetreeXWsAfterParenOpen(CO_ParsetreeX arg, CO_OptLayout wsAfterParenOpen) */

CO_ParsetreeX CO_setParsetreeXWsAfterParenOpen(CO_ParsetreeX arg, CO_OptLayout wsAfterParenOpen)
{
  if (CO_isParsetreeXSuccess(arg)) {
    return (CO_ParsetreeX)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (CO_isParsetreeXFailure(arg)) {
    return (CO_ParsetreeX)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("ParsetreeX has no WsAfterParenOpen: %t\n", arg);
  return (CO_ParsetreeX)NULL;
}

/*}}}  */
/*{{{  CO_ParsetreeX CO_setParsetreeXLeftLayout(CO_ParsetreeX arg, CO_Bytes leftLayout) */

CO_ParsetreeX CO_setParsetreeXLeftLayout(CO_ParsetreeX arg, CO_Bytes leftLayout)
{
  if (CO_isParsetreeXSuccess(arg)) {
    return (CO_ParsetreeX)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) leftLayout), 4), 1);
  }

  ATabort("ParsetreeX has no LeftLayout: %t\n", arg);
  return (CO_ParsetreeX)NULL;
}

/*}}}  */
/*{{{  CO_ParsetreeX CO_setParsetreeXWsAfterLeftLayout(CO_ParsetreeX arg, CO_OptLayout wsAfterLeftLayout) */

CO_ParsetreeX CO_setParsetreeXWsAfterLeftLayout(CO_ParsetreeX arg, CO_OptLayout wsAfterLeftLayout)
{
  if (CO_isParsetreeXSuccess(arg)) {
    return (CO_ParsetreeX)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLeftLayout), 5), 1);
  }

  ATabort("ParsetreeX has no WsAfterLeftLayout: %t\n", arg);
  return (CO_ParsetreeX)NULL;
}

/*}}}  */
/*{{{  CO_ParsetreeX CO_setParsetreeXWsAfterComma(CO_ParsetreeX arg, CO_OptLayout wsAfterComma) */

CO_ParsetreeX CO_setParsetreeXWsAfterComma(CO_ParsetreeX arg, CO_OptLayout wsAfterComma)
{
  if (CO_isParsetreeXSuccess(arg)) {
    return (CO_ParsetreeX)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }

  ATabort("ParsetreeX has no WsAfterComma: %t\n", arg);
  return (CO_ParsetreeX)NULL;
}

/*}}}  */
/*{{{  CO_ParsetreeX CO_setParsetreeXTree(CO_ParsetreeX arg, CO_X tree) */

CO_ParsetreeX CO_setParsetreeXTree(CO_ParsetreeX arg, CO_X tree)
{
  if (CO_isParsetreeXSuccess(arg)) {
    return (CO_ParsetreeX)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) tree), 8), 1);
  }

  ATabort("ParsetreeX has no Tree: %t\n", arg);
  return (CO_ParsetreeX)NULL;
}

/*}}}  */
/*{{{  CO_ParsetreeX CO_setParsetreeXWsAfterTree(CO_ParsetreeX arg, CO_OptLayout wsAfterTree) */

CO_ParsetreeX CO_setParsetreeXWsAfterTree(CO_ParsetreeX arg, CO_OptLayout wsAfterTree)
{
  if (CO_isParsetreeXSuccess(arg)) {
    return (CO_ParsetreeX)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterTree), 9), 1);
  }

  ATabort("ParsetreeX has no WsAfterTree: %t\n", arg);
  return (CO_ParsetreeX)NULL;
}

/*}}}  */
/*{{{  CO_ParsetreeX CO_setParsetreeXWsAfterComma1(CO_ParsetreeX arg, CO_OptLayout wsAfterComma1) */

CO_ParsetreeX CO_setParsetreeXWsAfterComma1(CO_ParsetreeX arg, CO_OptLayout wsAfterComma1)
{
  if (CO_isParsetreeXSuccess(arg)) {
    return (CO_ParsetreeX)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma1), 11), 1);
  }

  ATabort("ParsetreeX has no WsAfterComma1: %t\n", arg);
  return (CO_ParsetreeX)NULL;
}

/*}}}  */
/*{{{  CO_ParsetreeX CO_setParsetreeXRightLayout(CO_ParsetreeX arg, CO_Bytes rightLayout) */

CO_ParsetreeX CO_setParsetreeXRightLayout(CO_ParsetreeX arg, CO_Bytes rightLayout)
{
  if (CO_isParsetreeXSuccess(arg)) {
    return (CO_ParsetreeX)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) rightLayout), 12), 1);
  }

  ATabort("ParsetreeX has no RightLayout: %t\n", arg);
  return (CO_ParsetreeX)NULL;
}

/*}}}  */
/*{{{  CO_ParsetreeX CO_setParsetreeXWsAfterRightLayout(CO_ParsetreeX arg, CO_OptLayout wsAfterRightLayout) */

CO_ParsetreeX CO_setParsetreeXWsAfterRightLayout(CO_ParsetreeX arg, CO_OptLayout wsAfterRightLayout)
{
  if (CO_isParsetreeXSuccess(arg)) {
    return (CO_ParsetreeX)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterRightLayout), 13), 1);
  }

  ATabort("ParsetreeX has no WsAfterRightLayout: %t\n", arg);
  return (CO_ParsetreeX)NULL;
}

/*}}}  */
/*{{{  CO_ParsetreeX CO_setParsetreeXWsAfterComma2(CO_ParsetreeX arg, CO_OptLayout wsAfterComma2) */

CO_ParsetreeX CO_setParsetreeXWsAfterComma2(CO_ParsetreeX arg, CO_OptLayout wsAfterComma2)
{
  if (CO_isParsetreeXSuccess(arg)) {
    return (CO_ParsetreeX)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma2), 15), 1);
  }

  ATabort("ParsetreeX has no WsAfterComma2: %t\n", arg);
  return (CO_ParsetreeX)NULL;
}

/*}}}  */
/*{{{  CO_ParsetreeX CO_setParsetreeXAmbCnt(CO_ParsetreeX arg, CO_NatCon ambCnt) */

CO_ParsetreeX CO_setParsetreeXAmbCnt(CO_ParsetreeX arg, CO_NatCon ambCnt)
{
  if (CO_isParsetreeXSuccess(arg)) {
    return (CO_ParsetreeX)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) ambCnt), 16), 1);
  }

  ATabort("ParsetreeX has no AmbCnt: %t\n", arg);
  return (CO_ParsetreeX)NULL;
}

/*}}}  */
/*{{{  CO_ParsetreeX CO_setParsetreeXWsAfterAmbCnt(CO_ParsetreeX arg, CO_OptLayout wsAfterAmbCnt) */

CO_ParsetreeX CO_setParsetreeXWsAfterAmbCnt(CO_ParsetreeX arg, CO_OptLayout wsAfterAmbCnt)
{
  if (CO_isParsetreeXSuccess(arg)) {
    return (CO_ParsetreeX)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterAmbCnt), 17), 1);
  }

  ATabort("ParsetreeX has no WsAfterAmbCnt: %t\n", arg);
  return (CO_ParsetreeX)NULL;
}

/*}}}  */
/*{{{  CO_ParsetreeX CO_setParsetreeXWsAfterParseError(CO_ParsetreeX arg, CO_OptLayout wsAfterParseError) */

CO_ParsetreeX CO_setParsetreeXWsAfterParseError(CO_ParsetreeX arg, CO_OptLayout wsAfterParseError)
{
  if (CO_isParsetreeXFailure(arg)) {
    return (CO_ParsetreeX)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParseError), 1), 1);
  }

  ATabort("ParsetreeX has no WsAfterParseError: %t\n", arg);
  return (CO_ParsetreeX)NULL;
}

/*}}}  */
/*{{{  CO_ParsetreeX CO_setParsetreeXSummary(CO_ParsetreeX arg, CO_Summary Summary) */

CO_ParsetreeX CO_setParsetreeXSummary(CO_ParsetreeX arg, CO_Summary Summary)
{
  if (CO_isParsetreeXFailure(arg)) {
    return (CO_ParsetreeX)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Summary), 4), 1);
  }

  ATabort("ParsetreeX has no Summary: %t\n", arg);
  return (CO_ParsetreeX)NULL;
}

/*}}}  */
/*{{{  CO_ParsetreeX CO_setParsetreeXWsAfterSummary(CO_ParsetreeX arg, CO_OptLayout wsAfterSummary) */

CO_ParsetreeX CO_setParsetreeXWsAfterSummary(CO_ParsetreeX arg, CO_OptLayout wsAfterSummary)
{
  if (CO_isParsetreeXFailure(arg)) {
    return (CO_ParsetreeX)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSummary), 5), 1);
  }

  ATabort("ParsetreeX has no WsAfterSummary: %t\n", arg);
  return (CO_ParsetreeX)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  CO_X accessors */

/*{{{  ATbool CO_isValidX(CO_X arg) */

ATbool CO_isValidX(CO_X arg)
{
  if (CO_isXCast(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool CO_isXCast(CO_X arg) */

inline ATbool CO_isXCast(CO_X arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, CO_patternXCast, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool CO_hasXX(CO_X arg) */

ATbool CO_hasXX(CO_X arg)
{
  if (CO_isXCast(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ATerm CO_getXX(CO_X arg) */

ATerm CO_getXX(CO_X arg)
{
  
    return (ATerm)arg;
}

/*}}}  */
/*{{{  CO_X CO_setXX(CO_X arg, ATerm X) */

CO_X CO_setXX(CO_X arg, ATerm X)
{
  if (CO_isXCast(arg)) {
    return (CO_X)((ATerm) X);
  }

  ATabort("X has no X: %t\n", arg);
  return (CO_X)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  CO_OptLayout CO_visitOptLayout(CO_OptLayout arg, CO_Layout (*acceptLayout)(CO_Layout)) */

CO_OptLayout CO_visitOptLayout(CO_OptLayout arg, CO_Layout (*acceptLayout)(CO_Layout))
{
  if (CO_isOptLayoutAbsent(arg)) {
    return CO_makeOptLayoutAbsent();
  }
  if (CO_isOptLayoutPresent(arg)) {
    return CO_makeOptLayoutPresent(
        acceptLayout ? acceptLayout(CO_getOptLayoutLayout(arg)) : CO_getOptLayoutLayout(arg));
  }
  ATabort("not a OptLayout: %t\n", arg);
  return (CO_OptLayout)NULL;
}

/*}}}  */
/*{{{  CO_Layout CO_visitLayout(CO_Layout arg, CO_LexLayoutList (*acceptList)(CO_LexLayoutList)) */

CO_Layout CO_visitLayout(CO_Layout arg, CO_LexLayoutList (*acceptList)(CO_LexLayoutList))
{
  if (CO_isLayoutLexToCf(arg)) {
    return CO_makeLayoutLexToCf(
        acceptList ? acceptList(CO_getLayoutList(arg)) : CO_getLayoutList(arg));
  }
  ATabort("not a Layout: %t\n", arg);
  return (CO_Layout)NULL;
}

/*}}}  */
/*{{{  CO_LexLayoutList CO_visitLexLayoutList(CO_LexLayoutList arg, CO_LexLayout (*acceptHead)(CO_LexLayout)) */

CO_LexLayoutList CO_visitLexLayoutList(CO_LexLayoutList arg, CO_LexLayout (*acceptHead)(CO_LexLayout))
{
  if (CO_isLexLayoutListEmpty(arg)) {
    return CO_makeLexLayoutListEmpty();
  }
  if (CO_isLexLayoutListSingle(arg)) {
    return CO_makeLexLayoutListSingle(
        acceptHead ? acceptHead(CO_getLexLayoutListHead(arg)) : CO_getLexLayoutListHead(arg));
  }
  if (CO_isLexLayoutListMany(arg)) {
    return CO_makeLexLayoutListMany(
        acceptHead ? acceptHead(CO_getLexLayoutListHead(arg)) : CO_getLexLayoutListHead(arg),
        CO_visitLexLayoutList(CO_getLexLayoutListTail(arg), acceptHead));
  }
  ATabort("not a LexLayoutList: %t\n", arg);
  return (CO_LexLayoutList)NULL;
}

/*}}}  */
/*{{{  CO_LexLayout CO_visitLexLayout(CO_LexLayout arg, char (*acceptCh)(char)) */

CO_LexLayout CO_visitLexLayout(CO_LexLayout arg, char (*acceptCh)(char))
{
  if (CO_isLexLayoutWhitespace(arg)) {
    return CO_makeLexLayoutWhitespace(
        acceptCh ? acceptCh(CO_getLexLayoutCh(arg)) : CO_getLexLayoutCh(arg));
  }
  ATabort("not a LexLayout: %t\n", arg);
  return (CO_LexLayout)NULL;
}

/*}}}  */
/*{{{  CO_Boolean CO_visitBoolean(CO_Boolean arg, CO_BoolCon (*acceptBoolCon)(CO_BoolCon), CO_OptLayout (*acceptWsAfterLhs)(CO_OptLayout), CO_OptLayout (*acceptWsAfterBar)(CO_OptLayout), CO_OptLayout (*acceptWsAfterAmp)(CO_OptLayout), CO_OptLayout (*acceptWsAfterNot)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_OptLayout (*acceptWsAfterBoolean)(CO_OptLayout)) */

CO_Boolean CO_visitBoolean(CO_Boolean arg, CO_BoolCon (*acceptBoolCon)(CO_BoolCon), CO_OptLayout (*acceptWsAfterLhs)(CO_OptLayout), CO_OptLayout (*acceptWsAfterBar)(CO_OptLayout), CO_OptLayout (*acceptWsAfterAmp)(CO_OptLayout), CO_OptLayout (*acceptWsAfterNot)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_OptLayout (*acceptWsAfterBoolean)(CO_OptLayout))
{
  if (CO_isBooleanConstant(arg)) {
    return CO_makeBooleanConstant(
        acceptBoolCon ? acceptBoolCon(CO_getBooleanBoolCon(arg)) : CO_getBooleanBoolCon(arg));
  }
  if (CO_isBooleanOr(arg)) {
    return CO_makeBooleanOr(
        CO_visitBoolean(CO_getBooleanLhs(arg), acceptBoolCon, acceptWsAfterLhs, acceptWsAfterBar, acceptWsAfterAmp, acceptWsAfterNot, acceptWsAfterParenOpen, acceptWsAfterBoolean),
        acceptWsAfterLhs ? acceptWsAfterLhs(CO_getBooleanWsAfterLhs(arg)) : CO_getBooleanWsAfterLhs(arg),
        acceptWsAfterBar ? acceptWsAfterBar(CO_getBooleanWsAfterBar(arg)) : CO_getBooleanWsAfterBar(arg),
        CO_visitBoolean(CO_getBooleanRhs(arg), acceptBoolCon, acceptWsAfterLhs, acceptWsAfterBar, acceptWsAfterAmp, acceptWsAfterNot, acceptWsAfterParenOpen, acceptWsAfterBoolean));
  }
  if (CO_isBooleanAnd(arg)) {
    return CO_makeBooleanAnd(
        CO_visitBoolean(CO_getBooleanLhs(arg), acceptBoolCon, acceptWsAfterLhs, acceptWsAfterBar, acceptWsAfterAmp, acceptWsAfterNot, acceptWsAfterParenOpen, acceptWsAfterBoolean),
        acceptWsAfterLhs ? acceptWsAfterLhs(CO_getBooleanWsAfterLhs(arg)) : CO_getBooleanWsAfterLhs(arg),
        acceptWsAfterAmp ? acceptWsAfterAmp(CO_getBooleanWsAfterAmp(arg)) : CO_getBooleanWsAfterAmp(arg),
        CO_visitBoolean(CO_getBooleanRhs(arg), acceptBoolCon, acceptWsAfterLhs, acceptWsAfterBar, acceptWsAfterAmp, acceptWsAfterNot, acceptWsAfterParenOpen, acceptWsAfterBoolean));
  }
  if (CO_isBooleanNot(arg)) {
    return CO_makeBooleanNot(
        acceptWsAfterNot ? acceptWsAfterNot(CO_getBooleanWsAfterNot(arg)) : CO_getBooleanWsAfterNot(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(CO_getBooleanWsAfterParenOpen(arg)) : CO_getBooleanWsAfterParenOpen(arg),
        CO_visitBoolean(CO_getBooleanBoolean(arg), acceptBoolCon, acceptWsAfterLhs, acceptWsAfterBar, acceptWsAfterAmp, acceptWsAfterNot, acceptWsAfterParenOpen, acceptWsAfterBoolean),
        acceptWsAfterBoolean ? acceptWsAfterBoolean(CO_getBooleanWsAfterBoolean(arg)) : CO_getBooleanWsAfterBoolean(arg));
  }
  if (CO_isBooleanBracket(arg)) {
    return CO_makeBooleanBracket(
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(CO_getBooleanWsAfterParenOpen(arg)) : CO_getBooleanWsAfterParenOpen(arg),
        CO_visitBoolean(CO_getBooleanBoolean(arg), acceptBoolCon, acceptWsAfterLhs, acceptWsAfterBar, acceptWsAfterAmp, acceptWsAfterNot, acceptWsAfterParenOpen, acceptWsAfterBoolean),
        acceptWsAfterBoolean ? acceptWsAfterBoolean(CO_getBooleanWsAfterBoolean(arg)) : CO_getBooleanWsAfterBoolean(arg));
  }
  ATabort("not a Boolean: %t\n", arg);
  return (CO_Boolean)NULL;
}

/*}}}  */
/*{{{  CO_Start CO_visitStart(CO_Start arg, CO_OptLayout (*acceptWsBefore)(CO_OptLayout), CO_Boolean (*acceptTopBoolean)(CO_Boolean), CO_OptLayout (*acceptWsAfter)(CO_OptLayout), int (*acceptAmbCnt)(int), CO_StrCon (*acceptTopStrCon)(CO_StrCon), CO_BoolCon (*acceptTopBoolCon)(CO_BoolCon), CO_Summary (*acceptTopSummary)(CO_Summary), CO_Error (*acceptTopError)(CO_Error)) */

CO_Start CO_visitStart(CO_Start arg, CO_OptLayout (*acceptWsBefore)(CO_OptLayout), CO_Boolean (*acceptTopBoolean)(CO_Boolean), CO_OptLayout (*acceptWsAfter)(CO_OptLayout), int (*acceptAmbCnt)(int), CO_StrCon (*acceptTopStrCon)(CO_StrCon), CO_BoolCon (*acceptTopBoolCon)(CO_BoolCon), CO_Summary (*acceptTopSummary)(CO_Summary), CO_Error (*acceptTopError)(CO_Error))
{
  if (CO_isStartBoolean(arg)) {
    return CO_makeStartBoolean(
        acceptWsBefore ? acceptWsBefore(CO_getStartWsBefore(arg)) : CO_getStartWsBefore(arg),
        acceptTopBoolean ? acceptTopBoolean(CO_getStartTopBoolean(arg)) : CO_getStartTopBoolean(arg),
        acceptWsAfter ? acceptWsAfter(CO_getStartWsAfter(arg)) : CO_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(CO_getStartAmbCnt(arg)) : CO_getStartAmbCnt(arg));
  }
  if (CO_isStartStrCon(arg)) {
    return CO_makeStartStrCon(
        acceptWsBefore ? acceptWsBefore(CO_getStartWsBefore(arg)) : CO_getStartWsBefore(arg),
        acceptTopStrCon ? acceptTopStrCon(CO_getStartTopStrCon(arg)) : CO_getStartTopStrCon(arg),
        acceptWsAfter ? acceptWsAfter(CO_getStartWsAfter(arg)) : CO_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(CO_getStartAmbCnt(arg)) : CO_getStartAmbCnt(arg));
  }
  if (CO_isStartBoolCon(arg)) {
    return CO_makeStartBoolCon(
        acceptWsBefore ? acceptWsBefore(CO_getStartWsBefore(arg)) : CO_getStartWsBefore(arg),
        acceptTopBoolCon ? acceptTopBoolCon(CO_getStartTopBoolCon(arg)) : CO_getStartTopBoolCon(arg),
        acceptWsAfter ? acceptWsAfter(CO_getStartWsAfter(arg)) : CO_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(CO_getStartAmbCnt(arg)) : CO_getStartAmbCnt(arg));
  }
  if (CO_isStartSummary(arg)) {
    return CO_makeStartSummary(
        acceptWsBefore ? acceptWsBefore(CO_getStartWsBefore(arg)) : CO_getStartWsBefore(arg),
        acceptTopSummary ? acceptTopSummary(CO_getStartTopSummary(arg)) : CO_getStartTopSummary(arg),
        acceptWsAfter ? acceptWsAfter(CO_getStartWsAfter(arg)) : CO_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(CO_getStartAmbCnt(arg)) : CO_getStartAmbCnt(arg));
  }
  if (CO_isStartError(arg)) {
    return CO_makeStartError(
        acceptWsBefore ? acceptWsBefore(CO_getStartWsBefore(arg)) : CO_getStartWsBefore(arg),
        acceptTopError ? acceptTopError(CO_getStartTopError(arg)) : CO_getStartTopError(arg),
        acceptWsAfter ? acceptWsAfter(CO_getStartWsAfter(arg)) : CO_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(CO_getStartAmbCnt(arg)) : CO_getStartAmbCnt(arg));
  }
  ATabort("not a Start: %t\n", arg);
  return (CO_Start)NULL;
}

/*}}}  */
/*{{{  CO_LexStrChar CO_visitLexStrChar(CO_LexStrChar arg, char (*acceptA)(char), char (*acceptB)(char), char (*acceptC)(char), char (*acceptCh)(char)) */

CO_LexStrChar CO_visitLexStrChar(CO_LexStrChar arg, char (*acceptA)(char), char (*acceptB)(char), char (*acceptC)(char), char (*acceptCh)(char))
{
  if (CO_isLexStrCharNewline(arg)) {
    return CO_makeLexStrCharNewline();
  }
  if (CO_isLexStrCharTab(arg)) {
    return CO_makeLexStrCharTab();
  }
  if (CO_isLexStrCharQuote(arg)) {
    return CO_makeLexStrCharQuote();
  }
  if (CO_isLexStrCharBackslash(arg)) {
    return CO_makeLexStrCharBackslash();
  }
  if (CO_isLexStrCharOctal(arg)) {
    return CO_makeLexStrCharOctal(
        acceptA ? acceptA(CO_getLexStrCharA(arg)) : CO_getLexStrCharA(arg),
        acceptB ? acceptB(CO_getLexStrCharB(arg)) : CO_getLexStrCharB(arg),
        acceptC ? acceptC(CO_getLexStrCharC(arg)) : CO_getLexStrCharC(arg));
  }
  if (CO_isLexStrCharNormal(arg)) {
    return CO_makeLexStrCharNormal(
        acceptCh ? acceptCh(CO_getLexStrCharCh(arg)) : CO_getLexStrCharCh(arg));
  }
  ATabort("not a LexStrChar: %t\n", arg);
  return (CO_LexStrChar)NULL;
}

/*}}}  */
/*{{{  CO_StrChar CO_visitStrChar(CO_StrChar arg, CO_LexStrChar (*acceptStrChar)(CO_LexStrChar)) */

CO_StrChar CO_visitStrChar(CO_StrChar arg, CO_LexStrChar (*acceptStrChar)(CO_LexStrChar))
{
  if (CO_isStrCharLexToCf(arg)) {
    return CO_makeStrCharLexToCf(
        acceptStrChar ? acceptStrChar(CO_getStrCharStrChar(arg)) : CO_getStrCharStrChar(arg));
  }
  ATabort("not a StrChar: %t\n", arg);
  return (CO_StrChar)NULL;
}

/*}}}  */
/*{{{  CO_LexStrCon CO_visitLexStrCon(CO_LexStrCon arg, CO_LexStrCharLine (*acceptLine)(CO_LexStrCharLine)) */

CO_LexStrCon CO_visitLexStrCon(CO_LexStrCon arg, CO_LexStrCharLine (*acceptLine)(CO_LexStrCharLine))
{
  if (CO_isLexStrConDefault(arg)) {
    return CO_makeLexStrConDefault(
        acceptLine ? acceptLine(CO_getLexStrConLine(arg)) : CO_getLexStrConLine(arg));
  }
  ATabort("not a LexStrCon: %t\n", arg);
  return (CO_LexStrCon)NULL;
}

/*}}}  */
/*{{{  CO_StrCon CO_visitStrCon(CO_StrCon arg, CO_LexStrCon (*acceptStrCon)(CO_LexStrCon)) */

CO_StrCon CO_visitStrCon(CO_StrCon arg, CO_LexStrCon (*acceptStrCon)(CO_LexStrCon))
{
  if (CO_isStrConLexToCf(arg)) {
    return CO_makeStrConLexToCf(
        acceptStrCon ? acceptStrCon(CO_getStrConStrCon(arg)) : CO_getStrConStrCon(arg));
  }
  ATabort("not a StrCon: %t\n", arg);
  return (CO_StrCon)NULL;
}

/*}}}  */
/*{{{  CO_LexStrCharLine CO_visitLexStrCharLine(CO_LexStrCharLine arg, CO_LexStrChar (*acceptHead)(CO_LexStrChar)) */

CO_LexStrCharLine CO_visitLexStrCharLine(CO_LexStrCharLine arg, CO_LexStrChar (*acceptHead)(CO_LexStrChar))
{
  if (CO_isLexStrCharLineEmpty(arg)) {
    return CO_makeLexStrCharLineEmpty();
  }
  if (CO_isLexStrCharLineSingle(arg)) {
    return CO_makeLexStrCharLineSingle(
        acceptHead ? acceptHead(CO_getLexStrCharLineHead(arg)) : CO_getLexStrCharLineHead(arg));
  }
  if (CO_isLexStrCharLineMany(arg)) {
    return CO_makeLexStrCharLineMany(
        acceptHead ? acceptHead(CO_getLexStrCharLineHead(arg)) : CO_getLexStrCharLineHead(arg),
        CO_visitLexStrCharLine(CO_getLexStrCharLineTail(arg), acceptHead));
  }
  ATabort("not a LexStrCharLine: %t\n", arg);
  return (CO_LexStrCharLine)NULL;
}

/*}}}  */
/*{{{  CO_BoolCon CO_visitBoolCon(CO_BoolCon arg) */

CO_BoolCon CO_visitBoolCon(CO_BoolCon arg)
{
  if (CO_isBoolConTrue(arg)) {
    return CO_makeBoolConTrue();
  }
  if (CO_isBoolConFalse(arg)) {
    return CO_makeBoolConFalse();
  }
  ATabort("not a BoolCon: %t\n", arg);
  return (CO_BoolCon)NULL;
}

/*}}}  */
/*{{{  CO_LexNatCon CO_visitLexNatCon(CO_LexNatCon arg, char* (*acceptList)(char*)) */

CO_LexNatCon CO_visitLexNatCon(CO_LexNatCon arg, char* (*acceptList)(char*))
{
  if (CO_isLexNatConDefault(arg)) {
    return CO_makeLexNatConDefault(
        acceptList ? acceptList(CO_getLexNatConList(arg)) : CO_getLexNatConList(arg));
  }
  ATabort("not a LexNatCon: %t\n", arg);
  return (CO_LexNatCon)NULL;
}

/*}}}  */
/*{{{  CO_NatCon CO_visitNatCon(CO_NatCon arg, CO_LexNatCon (*acceptNatCon)(CO_LexNatCon)) */

CO_NatCon CO_visitNatCon(CO_NatCon arg, CO_LexNatCon (*acceptNatCon)(CO_LexNatCon))
{
  if (CO_isNatConLexToCf(arg)) {
    return CO_makeNatConLexToCf(
        acceptNatCon ? acceptNatCon(CO_getNatConNatCon(arg)) : CO_getNatConNatCon(arg));
  }
  ATabort("not a NatCon: %t\n", arg);
  return (CO_NatCon)NULL;
}

/*}}}  */
/*{{{  CO_LexByte CO_visitLexByte(CO_LexByte arg, char (*acceptCh)(char)) */

CO_LexByte CO_visitLexByte(CO_LexByte arg, char (*acceptCh)(char))
{
  if (CO_isLexByteByte(arg)) {
    return CO_makeLexByteByte(
        acceptCh ? acceptCh(CO_getLexByteCh(arg)) : CO_getLexByteCh(arg));
  }
  ATabort("not a LexByte: %t\n", arg);
  return (CO_LexByte)NULL;
}

/*}}}  */
/*{{{  CO_Byte CO_visitByte(CO_Byte arg, CO_LexByte (*acceptByte)(CO_LexByte)) */

CO_Byte CO_visitByte(CO_Byte arg, CO_LexByte (*acceptByte)(CO_LexByte))
{
  if (CO_isByteLexToCf(arg)) {
    return CO_makeByteLexToCf(
        acceptByte ? acceptByte(CO_getByteByte(arg)) : CO_getByteByte(arg));
  }
  ATabort("not a Byte: %t\n", arg);
  return (CO_Byte)NULL;
}

/*}}}  */
/*{{{  CO_LexBytes CO_visitLexBytes(CO_LexBytes arg, CO_LexByteList (*acceptList)(CO_LexByteList)) */

CO_LexBytes CO_visitLexBytes(CO_LexBytes arg, CO_LexByteList (*acceptList)(CO_LexByteList))
{
  if (CO_isLexBytesBytes(arg)) {
    return CO_makeLexBytesBytes(
        acceptList ? acceptList(CO_getLexBytesList(arg)) : CO_getLexBytesList(arg));
  }
  ATabort("not a LexBytes: %t\n", arg);
  return (CO_LexBytes)NULL;
}

/*}}}  */
/*{{{  CO_Bytes CO_visitBytes(CO_Bytes arg, CO_LexBytes (*acceptBytes)(CO_LexBytes)) */

CO_Bytes CO_visitBytes(CO_Bytes arg, CO_LexBytes (*acceptBytes)(CO_LexBytes))
{
  if (CO_isBytesLexToCf(arg)) {
    return CO_makeBytesLexToCf(
        acceptBytes ? acceptBytes(CO_getBytesBytes(arg)) : CO_getBytesBytes(arg));
  }
  ATabort("not a Bytes: %t\n", arg);
  return (CO_Bytes)NULL;
}

/*}}}  */
/*{{{  CO_LexByteList CO_visitLexByteList(CO_LexByteList arg, CO_LexByte (*acceptHead)(CO_LexByte)) */

CO_LexByteList CO_visitLexByteList(CO_LexByteList arg, CO_LexByte (*acceptHead)(CO_LexByte))
{
  if (CO_isLexByteListEmpty(arg)) {
    return CO_makeLexByteListEmpty();
  }
  if (CO_isLexByteListSingle(arg)) {
    return CO_makeLexByteListSingle(
        acceptHead ? acceptHead(CO_getLexByteListHead(arg)) : CO_getLexByteListHead(arg));
  }
  if (CO_isLexByteListMany(arg)) {
    return CO_makeLexByteListMany(
        acceptHead ? acceptHead(CO_getLexByteListHead(arg)) : CO_getLexByteListHead(arg),
        CO_visitLexByteList(CO_getLexByteListTail(arg), acceptHead));
  }
  ATabort("not a LexByteList: %t\n", arg);
  return (CO_LexByteList)NULL;
}

/*}}}  */
/*{{{  CO_Subject CO_visitSubject(CO_Subject arg, CO_OptLayout (*acceptWsAfterSubject)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_StrCon (*acceptDescription)(CO_StrCon), CO_OptLayout (*acceptWsAfterDescription)(CO_OptLayout), CO_OptLayout (*acceptWsAfterLocalized)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma)(CO_OptLayout), CO_Location (*acceptLocation)(CO_Location), CO_OptLayout (*acceptWsAfterLocation)(CO_OptLayout)) */

CO_Subject CO_visitSubject(CO_Subject arg, CO_OptLayout (*acceptWsAfterSubject)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_StrCon (*acceptDescription)(CO_StrCon), CO_OptLayout (*acceptWsAfterDescription)(CO_OptLayout), CO_OptLayout (*acceptWsAfterLocalized)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma)(CO_OptLayout), CO_Location (*acceptLocation)(CO_Location), CO_OptLayout (*acceptWsAfterLocation)(CO_OptLayout))
{
  if (CO_isSubjectSubject(arg)) {
    return CO_makeSubjectSubject(
        acceptWsAfterSubject ? acceptWsAfterSubject(CO_getSubjectWsAfterSubject(arg)) : CO_getSubjectWsAfterSubject(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(CO_getSubjectWsAfterParenOpen(arg)) : CO_getSubjectWsAfterParenOpen(arg),
        acceptDescription ? acceptDescription(CO_getSubjectDescription(arg)) : CO_getSubjectDescription(arg),
        acceptWsAfterDescription ? acceptWsAfterDescription(CO_getSubjectWsAfterDescription(arg)) : CO_getSubjectWsAfterDescription(arg));
  }
  if (CO_isSubjectLocalized(arg)) {
    return CO_makeSubjectLocalized(
        acceptWsAfterLocalized ? acceptWsAfterLocalized(CO_getSubjectWsAfterLocalized(arg)) : CO_getSubjectWsAfterLocalized(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(CO_getSubjectWsAfterParenOpen(arg)) : CO_getSubjectWsAfterParenOpen(arg),
        acceptDescription ? acceptDescription(CO_getSubjectDescription(arg)) : CO_getSubjectDescription(arg),
        acceptWsAfterDescription ? acceptWsAfterDescription(CO_getSubjectWsAfterDescription(arg)) : CO_getSubjectWsAfterDescription(arg),
        acceptWsAfterComma ? acceptWsAfterComma(CO_getSubjectWsAfterComma(arg)) : CO_getSubjectWsAfterComma(arg),
        acceptLocation ? acceptLocation(CO_getSubjectLocation(arg)) : CO_getSubjectLocation(arg),
        acceptWsAfterLocation ? acceptWsAfterLocation(CO_getSubjectWsAfterLocation(arg)) : CO_getSubjectWsAfterLocation(arg));
  }
  ATabort("not a Subject: %t\n", arg);
  return (CO_Subject)NULL;
}

/*}}}  */
/*{{{  CO_Error CO_visitError(CO_Error arg, CO_OptLayout (*acceptWsAfterInfo)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_StrCon (*acceptDescription)(CO_StrCon), CO_OptLayout (*acceptWsAfterDescription)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma)(CO_OptLayout), CO_OptLayout (*acceptWsAfterBracketOpen)(CO_OptLayout), CO_SubjectList (*acceptList)(CO_SubjectList), CO_OptLayout (*acceptWsAfterList)(CO_OptLayout), CO_OptLayout (*acceptWsAfterBracketClose)(CO_OptLayout), CO_OptLayout (*acceptWsAfterWarning)(CO_OptLayout), CO_OptLayout (*acceptWsAfterError)(CO_OptLayout), CO_OptLayout (*acceptWsAfterFatal)(CO_OptLayout)) */

CO_Error CO_visitError(CO_Error arg, CO_OptLayout (*acceptWsAfterInfo)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_StrCon (*acceptDescription)(CO_StrCon), CO_OptLayout (*acceptWsAfterDescription)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma)(CO_OptLayout), CO_OptLayout (*acceptWsAfterBracketOpen)(CO_OptLayout), CO_SubjectList (*acceptList)(CO_SubjectList), CO_OptLayout (*acceptWsAfterList)(CO_OptLayout), CO_OptLayout (*acceptWsAfterBracketClose)(CO_OptLayout), CO_OptLayout (*acceptWsAfterWarning)(CO_OptLayout), CO_OptLayout (*acceptWsAfterError)(CO_OptLayout), CO_OptLayout (*acceptWsAfterFatal)(CO_OptLayout))
{
  if (CO_isErrorInfo(arg)) {
    return CO_makeErrorInfo(
        acceptWsAfterInfo ? acceptWsAfterInfo(CO_getErrorWsAfterInfo(arg)) : CO_getErrorWsAfterInfo(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(CO_getErrorWsAfterParenOpen(arg)) : CO_getErrorWsAfterParenOpen(arg),
        acceptDescription ? acceptDescription(CO_getErrorDescription(arg)) : CO_getErrorDescription(arg),
        acceptWsAfterDescription ? acceptWsAfterDescription(CO_getErrorWsAfterDescription(arg)) : CO_getErrorWsAfterDescription(arg),
        acceptWsAfterComma ? acceptWsAfterComma(CO_getErrorWsAfterComma(arg)) : CO_getErrorWsAfterComma(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(CO_getErrorWsAfterBracketOpen(arg)) : CO_getErrorWsAfterBracketOpen(arg),
        acceptList ? acceptList(CO_getErrorList(arg)) : CO_getErrorList(arg),
        acceptWsAfterList ? acceptWsAfterList(CO_getErrorWsAfterList(arg)) : CO_getErrorWsAfterList(arg),
        acceptWsAfterBracketClose ? acceptWsAfterBracketClose(CO_getErrorWsAfterBracketClose(arg)) : CO_getErrorWsAfterBracketClose(arg));
  }
  if (CO_isErrorWarning(arg)) {
    return CO_makeErrorWarning(
        acceptWsAfterWarning ? acceptWsAfterWarning(CO_getErrorWsAfterWarning(arg)) : CO_getErrorWsAfterWarning(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(CO_getErrorWsAfterParenOpen(arg)) : CO_getErrorWsAfterParenOpen(arg),
        acceptDescription ? acceptDescription(CO_getErrorDescription(arg)) : CO_getErrorDescription(arg),
        acceptWsAfterDescription ? acceptWsAfterDescription(CO_getErrorWsAfterDescription(arg)) : CO_getErrorWsAfterDescription(arg),
        acceptWsAfterComma ? acceptWsAfterComma(CO_getErrorWsAfterComma(arg)) : CO_getErrorWsAfterComma(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(CO_getErrorWsAfterBracketOpen(arg)) : CO_getErrorWsAfterBracketOpen(arg),
        acceptList ? acceptList(CO_getErrorList(arg)) : CO_getErrorList(arg),
        acceptWsAfterList ? acceptWsAfterList(CO_getErrorWsAfterList(arg)) : CO_getErrorWsAfterList(arg),
        acceptWsAfterBracketClose ? acceptWsAfterBracketClose(CO_getErrorWsAfterBracketClose(arg)) : CO_getErrorWsAfterBracketClose(arg));
  }
  if (CO_isErrorError(arg)) {
    return CO_makeErrorError(
        acceptWsAfterError ? acceptWsAfterError(CO_getErrorWsAfterError(arg)) : CO_getErrorWsAfterError(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(CO_getErrorWsAfterParenOpen(arg)) : CO_getErrorWsAfterParenOpen(arg),
        acceptDescription ? acceptDescription(CO_getErrorDescription(arg)) : CO_getErrorDescription(arg),
        acceptWsAfterDescription ? acceptWsAfterDescription(CO_getErrorWsAfterDescription(arg)) : CO_getErrorWsAfterDescription(arg),
        acceptWsAfterComma ? acceptWsAfterComma(CO_getErrorWsAfterComma(arg)) : CO_getErrorWsAfterComma(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(CO_getErrorWsAfterBracketOpen(arg)) : CO_getErrorWsAfterBracketOpen(arg),
        acceptList ? acceptList(CO_getErrorList(arg)) : CO_getErrorList(arg),
        acceptWsAfterList ? acceptWsAfterList(CO_getErrorWsAfterList(arg)) : CO_getErrorWsAfterList(arg),
        acceptWsAfterBracketClose ? acceptWsAfterBracketClose(CO_getErrorWsAfterBracketClose(arg)) : CO_getErrorWsAfterBracketClose(arg));
  }
  if (CO_isErrorFatal(arg)) {
    return CO_makeErrorFatal(
        acceptWsAfterFatal ? acceptWsAfterFatal(CO_getErrorWsAfterFatal(arg)) : CO_getErrorWsAfterFatal(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(CO_getErrorWsAfterParenOpen(arg)) : CO_getErrorWsAfterParenOpen(arg),
        acceptDescription ? acceptDescription(CO_getErrorDescription(arg)) : CO_getErrorDescription(arg),
        acceptWsAfterDescription ? acceptWsAfterDescription(CO_getErrorWsAfterDescription(arg)) : CO_getErrorWsAfterDescription(arg),
        acceptWsAfterComma ? acceptWsAfterComma(CO_getErrorWsAfterComma(arg)) : CO_getErrorWsAfterComma(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(CO_getErrorWsAfterBracketOpen(arg)) : CO_getErrorWsAfterBracketOpen(arg),
        acceptList ? acceptList(CO_getErrorList(arg)) : CO_getErrorList(arg),
        acceptWsAfterList ? acceptWsAfterList(CO_getErrorWsAfterList(arg)) : CO_getErrorWsAfterList(arg),
        acceptWsAfterBracketClose ? acceptWsAfterBracketClose(CO_getErrorWsAfterBracketClose(arg)) : CO_getErrorWsAfterBracketClose(arg));
  }
  ATabort("not a Error: %t\n", arg);
  return (CO_Error)NULL;
}

/*}}}  */
/*{{{  CO_Summary CO_visitSummary(CO_Summary arg, CO_OptLayout (*acceptWsAfterSummary)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_StrCon (*acceptProducer)(CO_StrCon), CO_OptLayout (*acceptWsAfterProducer)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma)(CO_OptLayout), CO_StrCon (*acceptId)(CO_StrCon), CO_OptLayout (*acceptWsAfterId)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma1)(CO_OptLayout), CO_OptLayout (*acceptWsAfterBracketOpen)(CO_OptLayout), CO_ErrorList (*acceptList)(CO_ErrorList), CO_OptLayout (*acceptWsAfterList)(CO_OptLayout), CO_OptLayout (*acceptWsAfterBracketClose)(CO_OptLayout)) */

CO_Summary CO_visitSummary(CO_Summary arg, CO_OptLayout (*acceptWsAfterSummary)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_StrCon (*acceptProducer)(CO_StrCon), CO_OptLayout (*acceptWsAfterProducer)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma)(CO_OptLayout), CO_StrCon (*acceptId)(CO_StrCon), CO_OptLayout (*acceptWsAfterId)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma1)(CO_OptLayout), CO_OptLayout (*acceptWsAfterBracketOpen)(CO_OptLayout), CO_ErrorList (*acceptList)(CO_ErrorList), CO_OptLayout (*acceptWsAfterList)(CO_OptLayout), CO_OptLayout (*acceptWsAfterBracketClose)(CO_OptLayout))
{
  if (CO_isSummarySummary(arg)) {
    return CO_makeSummarySummary(
        acceptWsAfterSummary ? acceptWsAfterSummary(CO_getSummaryWsAfterSummary(arg)) : CO_getSummaryWsAfterSummary(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(CO_getSummaryWsAfterParenOpen(arg)) : CO_getSummaryWsAfterParenOpen(arg),
        acceptProducer ? acceptProducer(CO_getSummaryProducer(arg)) : CO_getSummaryProducer(arg),
        acceptWsAfterProducer ? acceptWsAfterProducer(CO_getSummaryWsAfterProducer(arg)) : CO_getSummaryWsAfterProducer(arg),
        acceptWsAfterComma ? acceptWsAfterComma(CO_getSummaryWsAfterComma(arg)) : CO_getSummaryWsAfterComma(arg),
        acceptId ? acceptId(CO_getSummaryId(arg)) : CO_getSummaryId(arg),
        acceptWsAfterId ? acceptWsAfterId(CO_getSummaryWsAfterId(arg)) : CO_getSummaryWsAfterId(arg),
        acceptWsAfterComma1 ? acceptWsAfterComma1(CO_getSummaryWsAfterComma1(arg)) : CO_getSummaryWsAfterComma1(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(CO_getSummaryWsAfterBracketOpen(arg)) : CO_getSummaryWsAfterBracketOpen(arg),
        acceptList ? acceptList(CO_getSummaryList(arg)) : CO_getSummaryList(arg),
        acceptWsAfterList ? acceptWsAfterList(CO_getSummaryWsAfterList(arg)) : CO_getSummaryWsAfterList(arg),
        acceptWsAfterBracketClose ? acceptWsAfterBracketClose(CO_getSummaryWsAfterBracketClose(arg)) : CO_getSummaryWsAfterBracketClose(arg));
  }
  ATabort("not a Summary: %t\n", arg);
  return (CO_Summary)NULL;
}

/*}}}  */
/*{{{  CO_SubjectList CO_visitSubjectList(CO_SubjectList arg, CO_Subject (*acceptHead)(CO_Subject), CO_OptLayout (*acceptWsAfterHead)(CO_OptLayout), CO_OptLayout (*acceptWsAfterSep)(CO_OptLayout)) */

CO_SubjectList CO_visitSubjectList(CO_SubjectList arg, CO_Subject (*acceptHead)(CO_Subject), CO_OptLayout (*acceptWsAfterHead)(CO_OptLayout), CO_OptLayout (*acceptWsAfterSep)(CO_OptLayout))
{
  if (CO_isSubjectListEmpty(arg)) {
    return CO_makeSubjectListEmpty();
  }
  if (CO_isSubjectListSingle(arg)) {
    return CO_makeSubjectListSingle(
        acceptHead ? acceptHead(CO_getSubjectListHead(arg)) : CO_getSubjectListHead(arg));
  }
  if (CO_isSubjectListMany(arg)) {
    return CO_makeSubjectListMany(
        acceptHead ? acceptHead(CO_getSubjectListHead(arg)) : CO_getSubjectListHead(arg),
        acceptWsAfterHead ? acceptWsAfterHead(CO_getSubjectListWsAfterHead(arg)) : CO_getSubjectListWsAfterHead(arg),
        acceptWsAfterSep ? acceptWsAfterSep(CO_getSubjectListWsAfterSep(arg)) : CO_getSubjectListWsAfterSep(arg),
        CO_visitSubjectList(CO_getSubjectListTail(arg), acceptHead, acceptWsAfterHead, acceptWsAfterSep));
  }
  ATabort("not a SubjectList: %t\n", arg);
  return (CO_SubjectList)NULL;
}

/*}}}  */
/*{{{  CO_ErrorList CO_visitErrorList(CO_ErrorList arg, CO_Error (*acceptHead)(CO_Error), CO_OptLayout (*acceptWsAfterHead)(CO_OptLayout), CO_OptLayout (*acceptWsAfterSep)(CO_OptLayout)) */

CO_ErrorList CO_visitErrorList(CO_ErrorList arg, CO_Error (*acceptHead)(CO_Error), CO_OptLayout (*acceptWsAfterHead)(CO_OptLayout), CO_OptLayout (*acceptWsAfterSep)(CO_OptLayout))
{
  if (CO_isErrorListEmpty(arg)) {
    return CO_makeErrorListEmpty();
  }
  if (CO_isErrorListSingle(arg)) {
    return CO_makeErrorListSingle(
        acceptHead ? acceptHead(CO_getErrorListHead(arg)) : CO_getErrorListHead(arg));
  }
  if (CO_isErrorListMany(arg)) {
    return CO_makeErrorListMany(
        acceptHead ? acceptHead(CO_getErrorListHead(arg)) : CO_getErrorListHead(arg),
        acceptWsAfterHead ? acceptWsAfterHead(CO_getErrorListWsAfterHead(arg)) : CO_getErrorListWsAfterHead(arg),
        acceptWsAfterSep ? acceptWsAfterSep(CO_getErrorListWsAfterSep(arg)) : CO_getErrorListWsAfterSep(arg),
        CO_visitErrorList(CO_getErrorListTail(arg), acceptHead, acceptWsAfterHead, acceptWsAfterSep));
  }
  ATabort("not a ErrorList: %t\n", arg);
  return (CO_ErrorList)NULL;
}

/*}}}  */
/*{{{  CO_Location CO_visitLocation(CO_Location arg, CO_OptLayout (*acceptWsAfterFile)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_StrCon (*acceptFilename)(CO_StrCon), CO_OptLayout (*acceptWsAfterFilename)(CO_OptLayout), CO_OptLayout (*acceptWsAfterA)(CO_OptLayout), CO_Area (*acceptArea)(CO_Area), CO_OptLayout (*acceptWsAfterArea)(CO_OptLayout), CO_OptLayout (*acceptWsAfterAreaInFile)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma)(CO_OptLayout)) */

CO_Location CO_visitLocation(CO_Location arg, CO_OptLayout (*acceptWsAfterFile)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_StrCon (*acceptFilename)(CO_StrCon), CO_OptLayout (*acceptWsAfterFilename)(CO_OptLayout), CO_OptLayout (*acceptWsAfterA)(CO_OptLayout), CO_Area (*acceptArea)(CO_Area), CO_OptLayout (*acceptWsAfterArea)(CO_OptLayout), CO_OptLayout (*acceptWsAfterAreaInFile)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma)(CO_OptLayout))
{
  if (CO_isLocationFile(arg)) {
    return CO_makeLocationFile(
        acceptWsAfterFile ? acceptWsAfterFile(CO_getLocationWsAfterFile(arg)) : CO_getLocationWsAfterFile(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(CO_getLocationWsAfterParenOpen(arg)) : CO_getLocationWsAfterParenOpen(arg),
        acceptFilename ? acceptFilename(CO_getLocationFilename(arg)) : CO_getLocationFilename(arg),
        acceptWsAfterFilename ? acceptWsAfterFilename(CO_getLocationWsAfterFilename(arg)) : CO_getLocationWsAfterFilename(arg));
  }
  if (CO_isLocationArea(arg)) {
    return CO_makeLocationArea(
        acceptWsAfterA ? acceptWsAfterA(CO_getLocationWsAfterA(arg)) : CO_getLocationWsAfterA(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(CO_getLocationWsAfterParenOpen(arg)) : CO_getLocationWsAfterParenOpen(arg),
        acceptArea ? acceptArea(CO_getLocationArea(arg)) : CO_getLocationArea(arg),
        acceptWsAfterArea ? acceptWsAfterArea(CO_getLocationWsAfterArea(arg)) : CO_getLocationWsAfterArea(arg));
  }
  if (CO_isLocationAreaInFile(arg)) {
    return CO_makeLocationAreaInFile(
        acceptWsAfterAreaInFile ? acceptWsAfterAreaInFile(CO_getLocationWsAfterAreaInFile(arg)) : CO_getLocationWsAfterAreaInFile(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(CO_getLocationWsAfterParenOpen(arg)) : CO_getLocationWsAfterParenOpen(arg),
        acceptFilename ? acceptFilename(CO_getLocationFilename(arg)) : CO_getLocationFilename(arg),
        acceptWsAfterFilename ? acceptWsAfterFilename(CO_getLocationWsAfterFilename(arg)) : CO_getLocationWsAfterFilename(arg),
        acceptWsAfterComma ? acceptWsAfterComma(CO_getLocationWsAfterComma(arg)) : CO_getLocationWsAfterComma(arg),
        acceptArea ? acceptArea(CO_getLocationArea(arg)) : CO_getLocationArea(arg),
        acceptWsAfterArea ? acceptWsAfterArea(CO_getLocationWsAfterArea(arg)) : CO_getLocationWsAfterArea(arg));
  }
  ATabort("not a Location: %t\n", arg);
  return (CO_Location)NULL;
}

/*}}}  */
/*{{{  CO_Area CO_visitArea(CO_Area arg, CO_OptLayout (*acceptWsAfterArea)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_NatCon (*acceptBeginLine)(CO_NatCon), CO_OptLayout (*acceptWsAfterBeginLine)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma)(CO_OptLayout), CO_NatCon (*acceptBeginColumn)(CO_NatCon), CO_OptLayout (*acceptWsAfterBeginColumn)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma1)(CO_OptLayout), CO_NatCon (*acceptEndLine)(CO_NatCon), CO_OptLayout (*acceptWsAfterEndLine)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma2)(CO_OptLayout), CO_NatCon (*acceptEndColumn)(CO_NatCon), CO_OptLayout (*acceptWsAfterEndColumn)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma3)(CO_OptLayout), CO_NatCon (*acceptOffset)(CO_NatCon), CO_OptLayout (*acceptWsAfterOffset)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma4)(CO_OptLayout), CO_NatCon (*acceptLength)(CO_NatCon), CO_OptLayout (*acceptWsAfterLength)(CO_OptLayout)) */

CO_Area CO_visitArea(CO_Area arg, CO_OptLayout (*acceptWsAfterArea)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_NatCon (*acceptBeginLine)(CO_NatCon), CO_OptLayout (*acceptWsAfterBeginLine)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma)(CO_OptLayout), CO_NatCon (*acceptBeginColumn)(CO_NatCon), CO_OptLayout (*acceptWsAfterBeginColumn)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma1)(CO_OptLayout), CO_NatCon (*acceptEndLine)(CO_NatCon), CO_OptLayout (*acceptWsAfterEndLine)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma2)(CO_OptLayout), CO_NatCon (*acceptEndColumn)(CO_NatCon), CO_OptLayout (*acceptWsAfterEndColumn)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma3)(CO_OptLayout), CO_NatCon (*acceptOffset)(CO_NatCon), CO_OptLayout (*acceptWsAfterOffset)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma4)(CO_OptLayout), CO_NatCon (*acceptLength)(CO_NatCon), CO_OptLayout (*acceptWsAfterLength)(CO_OptLayout))
{
  if (CO_isAreaArea(arg)) {
    return CO_makeAreaArea(
        acceptWsAfterArea ? acceptWsAfterArea(CO_getAreaWsAfterArea(arg)) : CO_getAreaWsAfterArea(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(CO_getAreaWsAfterParenOpen(arg)) : CO_getAreaWsAfterParenOpen(arg),
        acceptBeginLine ? acceptBeginLine(CO_getAreaBeginLine(arg)) : CO_getAreaBeginLine(arg),
        acceptWsAfterBeginLine ? acceptWsAfterBeginLine(CO_getAreaWsAfterBeginLine(arg)) : CO_getAreaWsAfterBeginLine(arg),
        acceptWsAfterComma ? acceptWsAfterComma(CO_getAreaWsAfterComma(arg)) : CO_getAreaWsAfterComma(arg),
        acceptBeginColumn ? acceptBeginColumn(CO_getAreaBeginColumn(arg)) : CO_getAreaBeginColumn(arg),
        acceptWsAfterBeginColumn ? acceptWsAfterBeginColumn(CO_getAreaWsAfterBeginColumn(arg)) : CO_getAreaWsAfterBeginColumn(arg),
        acceptWsAfterComma1 ? acceptWsAfterComma1(CO_getAreaWsAfterComma1(arg)) : CO_getAreaWsAfterComma1(arg),
        acceptEndLine ? acceptEndLine(CO_getAreaEndLine(arg)) : CO_getAreaEndLine(arg),
        acceptWsAfterEndLine ? acceptWsAfterEndLine(CO_getAreaWsAfterEndLine(arg)) : CO_getAreaWsAfterEndLine(arg),
        acceptWsAfterComma2 ? acceptWsAfterComma2(CO_getAreaWsAfterComma2(arg)) : CO_getAreaWsAfterComma2(arg),
        acceptEndColumn ? acceptEndColumn(CO_getAreaEndColumn(arg)) : CO_getAreaEndColumn(arg),
        acceptWsAfterEndColumn ? acceptWsAfterEndColumn(CO_getAreaWsAfterEndColumn(arg)) : CO_getAreaWsAfterEndColumn(arg),
        acceptWsAfterComma3 ? acceptWsAfterComma3(CO_getAreaWsAfterComma3(arg)) : CO_getAreaWsAfterComma3(arg),
        acceptOffset ? acceptOffset(CO_getAreaOffset(arg)) : CO_getAreaOffset(arg),
        acceptWsAfterOffset ? acceptWsAfterOffset(CO_getAreaWsAfterOffset(arg)) : CO_getAreaWsAfterOffset(arg),
        acceptWsAfterComma4 ? acceptWsAfterComma4(CO_getAreaWsAfterComma4(arg)) : CO_getAreaWsAfterComma4(arg),
        acceptLength ? acceptLength(CO_getAreaLength(arg)) : CO_getAreaLength(arg),
        acceptWsAfterLength ? acceptWsAfterLength(CO_getAreaWsAfterLength(arg)) : CO_getAreaWsAfterLength(arg));
  }
  ATabort("not a Area: %t\n", arg);
  return (CO_Area)NULL;
}

/*}}}  */
/*{{{  CO_Read CO_visitRead(CO_Read arg, CO_OptLayout (*acceptWsAfterRead)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_Bytes (*acceptValue)(CO_Bytes), CO_OptLayout (*acceptWsAfterValue)(CO_OptLayout), CO_OptLayout (*acceptWsAfterReadError)(CO_OptLayout), CO_Summary (*acceptSummary)(CO_Summary), CO_OptLayout (*acceptWsAfterSummary)(CO_OptLayout)) */

CO_Read CO_visitRead(CO_Read arg, CO_OptLayout (*acceptWsAfterRead)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_Bytes (*acceptValue)(CO_Bytes), CO_OptLayout (*acceptWsAfterValue)(CO_OptLayout), CO_OptLayout (*acceptWsAfterReadError)(CO_OptLayout), CO_Summary (*acceptSummary)(CO_Summary), CO_OptLayout (*acceptWsAfterSummary)(CO_OptLayout))
{
  if (CO_isReadSuccess(arg)) {
    return CO_makeReadSuccess(
        acceptWsAfterRead ? acceptWsAfterRead(CO_getReadWsAfterRead(arg)) : CO_getReadWsAfterRead(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(CO_getReadWsAfterParenOpen(arg)) : CO_getReadWsAfterParenOpen(arg),
        acceptValue ? acceptValue(CO_getReadValue(arg)) : CO_getReadValue(arg),
        acceptWsAfterValue ? acceptWsAfterValue(CO_getReadWsAfterValue(arg)) : CO_getReadWsAfterValue(arg));
  }
  if (CO_isReadFailure(arg)) {
    return CO_makeReadFailure(
        acceptWsAfterReadError ? acceptWsAfterReadError(CO_getReadWsAfterReadError(arg)) : CO_getReadWsAfterReadError(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(CO_getReadWsAfterParenOpen(arg)) : CO_getReadWsAfterParenOpen(arg),
        acceptSummary ? acceptSummary(CO_getReadSummary(arg)) : CO_getReadSummary(arg),
        acceptWsAfterSummary ? acceptWsAfterSummary(CO_getReadWsAfterSummary(arg)) : CO_getReadWsAfterSummary(arg));
  }
  ATabort("not a Read: %t\n", arg);
  return (CO_Read)NULL;
}

/*}}}  */
/*{{{  CO_Write CO_visitWrite(CO_Write arg, CO_OptLayout (*acceptWsAfterWriteError)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_Summary (*acceptSummary)(CO_Summary), CO_OptLayout (*acceptWsAfterSummary)(CO_OptLayout)) */

CO_Write CO_visitWrite(CO_Write arg, CO_OptLayout (*acceptWsAfterWriteError)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_Summary (*acceptSummary)(CO_Summary), CO_OptLayout (*acceptWsAfterSummary)(CO_OptLayout))
{
  if (CO_isWriteSuccess(arg)) {
    return CO_makeWriteSuccess();
  }
  if (CO_isWriteFailure(arg)) {
    return CO_makeWriteFailure(
        acceptWsAfterWriteError ? acceptWsAfterWriteError(CO_getWriteWsAfterWriteError(arg)) : CO_getWriteWsAfterWriteError(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(CO_getWriteWsAfterParenOpen(arg)) : CO_getWriteWsAfterParenOpen(arg),
        acceptSummary ? acceptSummary(CO_getWriteSummary(arg)) : CO_getWriteSummary(arg),
        acceptWsAfterSummary ? acceptWsAfterSummary(CO_getWriteWsAfterSummary(arg)) : CO_getWriteWsAfterSummary(arg));
  }
  ATabort("not a Write: %t\n", arg);
  return (CO_Write)NULL;
}

/*}}}  */
/*{{{  CO_ParsetreeX CO_visitParsetreeX(CO_ParsetreeX arg, ATerm (*acceptTypeOfTree)(ATerm), ATerm (*acceptTypeOfX)(ATerm), CO_OptLayout (*acceptWsAfterParseTree)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_Bytes (*acceptLeftLayout)(CO_Bytes), CO_OptLayout (*acceptWsAfterLeftLayout)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma)(CO_OptLayout), CO_X (*acceptTree)(CO_X), CO_OptLayout (*acceptWsAfterTree)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma1)(CO_OptLayout), CO_Bytes (*acceptRightLayout)(CO_Bytes), CO_OptLayout (*acceptWsAfterRightLayout)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma2)(CO_OptLayout), CO_NatCon (*acceptAmbCnt)(CO_NatCon), CO_OptLayout (*acceptWsAfterAmbCnt)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParseError)(CO_OptLayout), CO_Summary (*acceptSummary)(CO_Summary), CO_OptLayout (*acceptWsAfterSummary)(CO_OptLayout)) */

CO_ParsetreeX CO_visitParsetreeX(CO_ParsetreeX arg, ATerm (*acceptTypeOfTree)(ATerm), ATerm (*acceptTypeOfX)(ATerm), CO_OptLayout (*acceptWsAfterParseTree)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParenOpen)(CO_OptLayout), CO_Bytes (*acceptLeftLayout)(CO_Bytes), CO_OptLayout (*acceptWsAfterLeftLayout)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma)(CO_OptLayout), CO_X (*acceptTree)(CO_X), CO_OptLayout (*acceptWsAfterTree)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma1)(CO_OptLayout), CO_Bytes (*acceptRightLayout)(CO_Bytes), CO_OptLayout (*acceptWsAfterRightLayout)(CO_OptLayout), CO_OptLayout (*acceptWsAfterComma2)(CO_OptLayout), CO_NatCon (*acceptAmbCnt)(CO_NatCon), CO_OptLayout (*acceptWsAfterAmbCnt)(CO_OptLayout), CO_OptLayout (*acceptWsAfterParseError)(CO_OptLayout), CO_Summary (*acceptSummary)(CO_Summary), CO_OptLayout (*acceptWsAfterSummary)(CO_OptLayout))
{
  if (CO_isParsetreeXSuccess(arg)) {
    return CO_makeParsetreeXSuccess(
        acceptTypeOfTree ? acceptTypeOfTree(CO_getParsetreeXTypeOfTree(arg)) : CO_getParsetreeXTypeOfTree(arg),
        acceptTypeOfX ? acceptTypeOfX(CO_getParsetreeXTypeOfX(arg)) : CO_getParsetreeXTypeOfX(arg),
        acceptWsAfterParseTree ? acceptWsAfterParseTree(CO_getParsetreeXWsAfterParseTree(arg)) : CO_getParsetreeXWsAfterParseTree(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(CO_getParsetreeXWsAfterParenOpen(arg)) : CO_getParsetreeXWsAfterParenOpen(arg),
        acceptLeftLayout ? acceptLeftLayout(CO_getParsetreeXLeftLayout(arg)) : CO_getParsetreeXLeftLayout(arg),
        acceptWsAfterLeftLayout ? acceptWsAfterLeftLayout(CO_getParsetreeXWsAfterLeftLayout(arg)) : CO_getParsetreeXWsAfterLeftLayout(arg),
        acceptWsAfterComma ? acceptWsAfterComma(CO_getParsetreeXWsAfterComma(arg)) : CO_getParsetreeXWsAfterComma(arg),
        acceptTree ? acceptTree(CO_getParsetreeXTree(arg)) : CO_getParsetreeXTree(arg),
        acceptWsAfterTree ? acceptWsAfterTree(CO_getParsetreeXWsAfterTree(arg)) : CO_getParsetreeXWsAfterTree(arg),
        acceptWsAfterComma1 ? acceptWsAfterComma1(CO_getParsetreeXWsAfterComma1(arg)) : CO_getParsetreeXWsAfterComma1(arg),
        acceptRightLayout ? acceptRightLayout(CO_getParsetreeXRightLayout(arg)) : CO_getParsetreeXRightLayout(arg),
        acceptWsAfterRightLayout ? acceptWsAfterRightLayout(CO_getParsetreeXWsAfterRightLayout(arg)) : CO_getParsetreeXWsAfterRightLayout(arg),
        acceptWsAfterComma2 ? acceptWsAfterComma2(CO_getParsetreeXWsAfterComma2(arg)) : CO_getParsetreeXWsAfterComma2(arg),
        acceptAmbCnt ? acceptAmbCnt(CO_getParsetreeXAmbCnt(arg)) : CO_getParsetreeXAmbCnt(arg),
        acceptWsAfterAmbCnt ? acceptWsAfterAmbCnt(CO_getParsetreeXWsAfterAmbCnt(arg)) : CO_getParsetreeXWsAfterAmbCnt(arg));
  }
  if (CO_isParsetreeXFailure(arg)) {
    return CO_makeParsetreeXFailure(
        acceptTypeOfX ? acceptTypeOfX(CO_getParsetreeXTypeOfX(arg)) : CO_getParsetreeXTypeOfX(arg),
        acceptWsAfterParseError ? acceptWsAfterParseError(CO_getParsetreeXWsAfterParseError(arg)) : CO_getParsetreeXWsAfterParseError(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(CO_getParsetreeXWsAfterParenOpen(arg)) : CO_getParsetreeXWsAfterParenOpen(arg),
        acceptSummary ? acceptSummary(CO_getParsetreeXSummary(arg)) : CO_getParsetreeXSummary(arg),
        acceptWsAfterSummary ? acceptWsAfterSummary(CO_getParsetreeXWsAfterSummary(arg)) : CO_getParsetreeXWsAfterSummary(arg));
  }
  ATabort("not a ParsetreeX: %t\n", arg);
  return (CO_ParsetreeX)NULL;
}

/*}}}  */
/*{{{  CO_X CO_visitX(CO_X arg, ATerm (*acceptX)(ATerm)) */

CO_X CO_visitX(CO_X arg, ATerm (*acceptX)(ATerm))
{
  if (CO_isXCast(arg)) {
    return CO_makeXCast(
        acceptX ? acceptX(CO_getXX(arg)) : CO_getXX(arg));
  }
  ATabort("not a X: %t\n", arg);
  return (CO_X)NULL;
}

/*}}}  */

/*}}}  */
