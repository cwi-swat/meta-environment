#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "ParsedErrorAPI.h"

/*{{{  conversion functions */

ATerm PERR_stringToChars(const char *str)
{
  int len = strlen(str);
  int i;
  ATermList result = ATempty;

  for (i = len - 1; i >= 0; i--) {
    result = ATinsert(result, (ATerm) ATmakeInt(str[i]));
  }

  return (ATerm) result;
}

char *PERR_charsToString(ATerm arg)
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

typedef struct ATerm _PERR_Feedback;
typedef struct ATerm _PERR_SubjectList;
typedef struct ATerm _PERR_Subject;
typedef struct ATerm _PERR_Location;
typedef struct ATerm _PERR_Area;
typedef struct ATerm _PERR_NatCon;
typedef struct ATerm _PERR_StrCon;
typedef struct ATerm _PERR_OptLayout;
typedef struct ATerm _PERR_Start;

/*}}}  */

/*{{{  void PERR_initParsedErrorAPIApi(void) */

void PERR_initParsedErrorAPIApi(void)
{
  init_ParsedErrorAPI_dict();
}

/*}}}  */

/*{{{  term conversion functions */

/*{{{  PERR_Feedback PERR_FeedbackFromTerm(ATerm t) */

PERR_Feedback PERR_FeedbackFromTerm(ATerm t)
{
  return (PERR_Feedback)t;
}

/*}}}  */
/*{{{  ATerm PERR_FeedbackToTerm(PERR_Feedback arg) */

ATerm PERR_FeedbackToTerm(PERR_Feedback arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PERR_SubjectList PERR_SubjectListFromTerm(ATerm t) */

PERR_SubjectList PERR_SubjectListFromTerm(ATerm t)
{
  return (PERR_SubjectList)t;
}

/*}}}  */
/*{{{  ATerm PERR_SubjectListToTerm(PERR_SubjectList arg) */

ATerm PERR_SubjectListToTerm(PERR_SubjectList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PERR_Subject PERR_SubjectFromTerm(ATerm t) */

PERR_Subject PERR_SubjectFromTerm(ATerm t)
{
  return (PERR_Subject)t;
}

/*}}}  */
/*{{{  ATerm PERR_SubjectToTerm(PERR_Subject arg) */

ATerm PERR_SubjectToTerm(PERR_Subject arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PERR_Location PERR_LocationFromTerm(ATerm t) */

PERR_Location PERR_LocationFromTerm(ATerm t)
{
  return (PERR_Location)t;
}

/*}}}  */
/*{{{  ATerm PERR_LocationToTerm(PERR_Location arg) */

ATerm PERR_LocationToTerm(PERR_Location arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PERR_Area PERR_AreaFromTerm(ATerm t) */

PERR_Area PERR_AreaFromTerm(ATerm t)
{
  return (PERR_Area)t;
}

/*}}}  */
/*{{{  ATerm PERR_AreaToTerm(PERR_Area arg) */

ATerm PERR_AreaToTerm(PERR_Area arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PERR_NatCon PERR_NatConFromTerm(ATerm t) */

PERR_NatCon PERR_NatConFromTerm(ATerm t)
{
  return (PERR_NatCon)t;
}

/*}}}  */
/*{{{  ATerm PERR_NatConToTerm(PERR_NatCon arg) */

ATerm PERR_NatConToTerm(PERR_NatCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PERR_StrCon PERR_StrConFromTerm(ATerm t) */

PERR_StrCon PERR_StrConFromTerm(ATerm t)
{
  return (PERR_StrCon)t;
}

/*}}}  */
/*{{{  ATerm PERR_StrConToTerm(PERR_StrCon arg) */

ATerm PERR_StrConToTerm(PERR_StrCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_OptLayoutFromTerm(ATerm t) */

PERR_OptLayout PERR_OptLayoutFromTerm(ATerm t)
{
  return (PERR_OptLayout)t;
}

/*}}}  */
/*{{{  ATerm PERR_OptLayoutToTerm(PERR_OptLayout arg) */

ATerm PERR_OptLayoutToTerm(PERR_OptLayout arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PERR_Start PERR_StartFromTerm(ATerm t) */

PERR_Start PERR_StartFromTerm(ATerm t)
{
  return (PERR_Start)t;
}

/*}}}  */
/*{{{  ATerm PERR_StartToTerm(PERR_Start arg) */

ATerm PERR_StartToTerm(PERR_Start arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*}}}  */
/*{{{  list functions */

int PERR_getSubjectListLength (PERR_SubjectList arg) {
  if (ATisEmpty((ATermList) arg)) {
    return 0;
  }
  return (ATgetLength((ATermList) arg) / 4) + 1;
}
PERR_SubjectList reverseSubjectList(PERR_SubjectList arg) {
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

  return (PERR_SubjectList) result;
}
PERR_SubjectList PERR_appendSubjectList(PERR_SubjectList arg0, PERR_OptLayout wsAfterHead, PERR_OptLayout wsAfterSep, PERR_Subject arg1) {
  return PERR_concatSubjectList(arg0, wsAfterHead, wsAfterSep, PERR_makeSubjectListSingle(arg1));
}
PERR_SubjectList PERR_concatSubjectList(PERR_SubjectList arg0, PERR_OptLayout wsAfterHead, PERR_OptLayout wsAfterSep, PERR_SubjectList arg1) {
  if (ATisEmpty((ATermList) arg0)) {
    return arg1;
  }
  arg1 = PERR_makeSubjectListMany((PERR_Subject)ATgetFirst((ATermList) arg0), wsAfterHead, wsAfterSep,  arg1);
  arg1 = (PERR_SubjectList) ATgetNext((ATermList) arg1);
  return (PERR_SubjectList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
PERR_SubjectList PERR_sliceSubjectList(PERR_SubjectList arg, int start, int end) {
  return (PERR_SubjectList) ATgetSlice((ATermList) arg, start * 4, end * 4);
}
PERR_Subject PERR_getSubjectListSubjectAt(PERR_SubjectList arg, int index) {
 return (PERR_Subject)ATelementAt((ATermList) arg,index * 4);
}
PERR_SubjectList PERR_replaceSubjectListSubjectAt(PERR_SubjectList arg, PERR_Subject elem, int index) {
 return (PERR_SubjectList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index * 4);
}
PERR_SubjectList PERR_makeSubjectList2(PERR_OptLayout wsAfterHead, PERR_OptLayout wsAfterSep, PERR_Subject elem1, PERR_Subject elem2) {
  return PERR_makeSubjectListMany(elem1, wsAfterHead, wsAfterSep, PERR_makeSubjectListSingle(elem2));
}
PERR_SubjectList PERR_makeSubjectList3(PERR_OptLayout wsAfterHead, PERR_OptLayout wsAfterSep, PERR_Subject elem1, PERR_Subject elem2, PERR_Subject elem3) {
  return PERR_makeSubjectListMany(elem1, wsAfterHead, wsAfterSep, PERR_makeSubjectList2(wsAfterHead, wsAfterSep, elem2, elem3));
}
PERR_SubjectList PERR_makeSubjectList4(PERR_OptLayout wsAfterHead, PERR_OptLayout wsAfterSep, PERR_Subject elem1, PERR_Subject elem2, PERR_Subject elem3, PERR_Subject elem4) {
  return PERR_makeSubjectListMany(elem1, wsAfterHead, wsAfterSep, PERR_makeSubjectList3(wsAfterHead, wsAfterSep, elem2, elem3, elem4));
}
PERR_SubjectList PERR_makeSubjectList5(PERR_OptLayout wsAfterHead, PERR_OptLayout wsAfterSep, PERR_Subject elem1, PERR_Subject elem2, PERR_Subject elem3, PERR_Subject elem4, PERR_Subject elem5) {
  return PERR_makeSubjectListMany(elem1, wsAfterHead, wsAfterSep, PERR_makeSubjectList4(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5));
}
PERR_SubjectList PERR_makeSubjectList6(PERR_OptLayout wsAfterHead, PERR_OptLayout wsAfterSep, PERR_Subject elem1, PERR_Subject elem2, PERR_Subject elem3, PERR_Subject elem4, PERR_Subject elem5, PERR_Subject elem6) {
  return PERR_makeSubjectListMany(elem1, wsAfterHead, wsAfterSep, PERR_makeSubjectList5(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5, elem6));
}

/*}}}  */
/*{{{  constructors */

/*{{{  PERR_Feedback PERR_makeFeedbackInfo(PERR_OptLayout wsAfterInfo, PERR_OptLayout wsAfterParenOpen, PERR_StrCon id, PERR_OptLayout wsAfterId, PERR_OptLayout wsAfterComma, PERR_StrCon producerId, PERR_OptLayout wsAfterProducerId, PERR_OptLayout wsAfterComma1, PERR_StrCon producerType, PERR_OptLayout wsAfterProducerType, PERR_OptLayout wsAfterComma2, PERR_StrCon description, PERR_OptLayout wsAfterDescription, PERR_OptLayout wsAfterComma3, PERR_OptLayout wsAfterBracketOpen, PERR_SubjectList list, PERR_OptLayout wsAfterList, PERR_OptLayout wsAfterBracketClose) */

PERR_Feedback PERR_makeFeedbackInfo(PERR_OptLayout wsAfterInfo, PERR_OptLayout wsAfterParenOpen, PERR_StrCon id, PERR_OptLayout wsAfterId, PERR_OptLayout wsAfterComma, PERR_StrCon producerId, PERR_OptLayout wsAfterProducerId, PERR_OptLayout wsAfterComma1, PERR_StrCon producerType, PERR_OptLayout wsAfterProducerType, PERR_OptLayout wsAfterComma2, PERR_StrCon description, PERR_OptLayout wsAfterDescription, PERR_OptLayout wsAfterComma3, PERR_OptLayout wsAfterBracketOpen, PERR_SubjectList list, PERR_OptLayout wsAfterList, PERR_OptLayout wsAfterBracketClose)
{
  return (PERR_Feedback)(ATerm)ATmakeAppl2(PERR_afun0, (ATerm)ATmakeAppl3(PERR_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun3))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun7))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl2(PERR_afun8, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun10)), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun12))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun13)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun13)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun13)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun13)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun14))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun15))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun16))), (ATerm)ATmakeAppl1(PERR_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PERR_afun18, (ATerm)ATmakeAppl1(PERR_afun19, (ATerm)ATmakeAppl0(PERR_afun15)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun3))), (ATerm) wsAfterBracketClose), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun7))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(PERR_afun0, (ATerm)ATmakeAppl1(PERR_afun20, (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl2(PERR_afun8, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun10)), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))))), (ATerm) list)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun12))), (ATerm) wsAfterComma3), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm) wsAfterDescription), (ATerm) description), (ATerm) wsAfterComma2), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm) wsAfterProducerType), (ATerm) producerType), (ATerm) wsAfterComma1), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm) wsAfterProducerId), (ATerm) producerId), (ATerm) wsAfterComma), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm) wsAfterId), (ATerm) id), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun14))), (ATerm) wsAfterInfo), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun15))));
}

/*}}}  */
/*{{{  PERR_Feedback PERR_makeFeedbackWarning(PERR_OptLayout wsAfterWarning, PERR_OptLayout wsAfterParenOpen, PERR_StrCon id, PERR_OptLayout wsAfterId, PERR_OptLayout wsAfterComma, PERR_StrCon producerId, PERR_OptLayout wsAfterProducerId, PERR_OptLayout wsAfterComma1, PERR_StrCon producerType, PERR_OptLayout wsAfterProducerType, PERR_OptLayout wsAfterComma2, PERR_StrCon description, PERR_OptLayout wsAfterDescription, PERR_OptLayout wsAfterComma3, PERR_OptLayout wsAfterBracketOpen, PERR_SubjectList list, PERR_OptLayout wsAfterList, PERR_OptLayout wsAfterBracketClose) */

PERR_Feedback PERR_makeFeedbackWarning(PERR_OptLayout wsAfterWarning, PERR_OptLayout wsAfterParenOpen, PERR_StrCon id, PERR_OptLayout wsAfterId, PERR_OptLayout wsAfterComma, PERR_StrCon producerId, PERR_OptLayout wsAfterProducerId, PERR_OptLayout wsAfterComma1, PERR_StrCon producerType, PERR_OptLayout wsAfterProducerType, PERR_OptLayout wsAfterComma2, PERR_StrCon description, PERR_OptLayout wsAfterDescription, PERR_OptLayout wsAfterComma3, PERR_OptLayout wsAfterBracketOpen, PERR_SubjectList list, PERR_OptLayout wsAfterList, PERR_OptLayout wsAfterBracketClose)
{
  return (PERR_Feedback)(ATerm)ATmakeAppl2(PERR_afun0, (ATerm)ATmakeAppl3(PERR_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun3))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun7))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl2(PERR_afun8, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun10)), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun12))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun13)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun13)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun13)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun13)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun14))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun21))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun16))), (ATerm)ATmakeAppl1(PERR_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PERR_afun18, (ATerm)ATmakeAppl1(PERR_afun19, (ATerm)ATmakeAppl0(PERR_afun21)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun3))), (ATerm) wsAfterBracketClose), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun7))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(PERR_afun0, (ATerm)ATmakeAppl1(PERR_afun20, (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl2(PERR_afun8, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun10)), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))))), (ATerm) list)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun12))), (ATerm) wsAfterComma3), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm) wsAfterDescription), (ATerm) description), (ATerm) wsAfterComma2), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm) wsAfterProducerType), (ATerm) producerType), (ATerm) wsAfterComma1), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm) wsAfterProducerId), (ATerm) producerId), (ATerm) wsAfterComma), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm) wsAfterId), (ATerm) id), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun14))), (ATerm) wsAfterWarning), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun21))));
}

/*}}}  */
/*{{{  PERR_Feedback PERR_makeFeedbackError(PERR_OptLayout wsAfterError, PERR_OptLayout wsAfterParenOpen, PERR_StrCon id, PERR_OptLayout wsAfterId, PERR_OptLayout wsAfterComma, PERR_StrCon producerId, PERR_OptLayout wsAfterProducerId, PERR_OptLayout wsAfterComma1, PERR_StrCon producerType, PERR_OptLayout wsAfterProducerType, PERR_OptLayout wsAfterComma2, PERR_StrCon description, PERR_OptLayout wsAfterDescription, PERR_OptLayout wsAfterComma3, PERR_OptLayout wsAfterBracketOpen, PERR_SubjectList list, PERR_OptLayout wsAfterList, PERR_OptLayout wsAfterBracketClose) */

PERR_Feedback PERR_makeFeedbackError(PERR_OptLayout wsAfterError, PERR_OptLayout wsAfterParenOpen, PERR_StrCon id, PERR_OptLayout wsAfterId, PERR_OptLayout wsAfterComma, PERR_StrCon producerId, PERR_OptLayout wsAfterProducerId, PERR_OptLayout wsAfterComma1, PERR_StrCon producerType, PERR_OptLayout wsAfterProducerType, PERR_OptLayout wsAfterComma2, PERR_StrCon description, PERR_OptLayout wsAfterDescription, PERR_OptLayout wsAfterComma3, PERR_OptLayout wsAfterBracketOpen, PERR_SubjectList list, PERR_OptLayout wsAfterList, PERR_OptLayout wsAfterBracketClose)
{
  return (PERR_Feedback)(ATerm)ATmakeAppl2(PERR_afun0, (ATerm)ATmakeAppl3(PERR_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun3))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun7))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl2(PERR_afun8, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun10)), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun12))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun13)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun13)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun13)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun13)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun14))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun22))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun16))), (ATerm)ATmakeAppl1(PERR_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PERR_afun18, (ATerm)ATmakeAppl1(PERR_afun19, (ATerm)ATmakeAppl0(PERR_afun22)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun3))), (ATerm) wsAfterBracketClose), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun7))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(PERR_afun0, (ATerm)ATmakeAppl1(PERR_afun20, (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl2(PERR_afun8, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun10)), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))))), (ATerm) list)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun12))), (ATerm) wsAfterComma3), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm) wsAfterDescription), (ATerm) description), (ATerm) wsAfterComma2), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm) wsAfterProducerType), (ATerm) producerType), (ATerm) wsAfterComma1), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm) wsAfterProducerId), (ATerm) producerId), (ATerm) wsAfterComma), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm) wsAfterId), (ATerm) id), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun14))), (ATerm) wsAfterError), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun22))));
}

/*}}}  */
/*{{{  PERR_Feedback PERR_makeFeedbackFatalError(PERR_OptLayout wsAfterFatalError, PERR_OptLayout wsAfterParenOpen, PERR_StrCon id, PERR_OptLayout wsAfterId, PERR_OptLayout wsAfterComma, PERR_StrCon producerId, PERR_OptLayout wsAfterProducerId, PERR_OptLayout wsAfterComma1, PERR_StrCon producerType, PERR_OptLayout wsAfterProducerType, PERR_OptLayout wsAfterComma2, PERR_StrCon description, PERR_OptLayout wsAfterDescription, PERR_OptLayout wsAfterComma3, PERR_OptLayout wsAfterBracketOpen, PERR_SubjectList list, PERR_OptLayout wsAfterList, PERR_OptLayout wsAfterBracketClose) */

PERR_Feedback PERR_makeFeedbackFatalError(PERR_OptLayout wsAfterFatalError, PERR_OptLayout wsAfterParenOpen, PERR_StrCon id, PERR_OptLayout wsAfterId, PERR_OptLayout wsAfterComma, PERR_StrCon producerId, PERR_OptLayout wsAfterProducerId, PERR_OptLayout wsAfterComma1, PERR_StrCon producerType, PERR_OptLayout wsAfterProducerType, PERR_OptLayout wsAfterComma2, PERR_StrCon description, PERR_OptLayout wsAfterDescription, PERR_OptLayout wsAfterComma3, PERR_OptLayout wsAfterBracketOpen, PERR_SubjectList list, PERR_OptLayout wsAfterList, PERR_OptLayout wsAfterBracketClose)
{
  return (PERR_Feedback)(ATerm)ATmakeAppl2(PERR_afun0, (ATerm)ATmakeAppl3(PERR_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun3))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun7))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl2(PERR_afun8, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun10)), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun12))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun13)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun13)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun13)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun13)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun14))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun23))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun16))), (ATerm)ATmakeAppl1(PERR_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PERR_afun18, (ATerm)ATmakeAppl1(PERR_afun19, (ATerm)ATmakeAppl0(PERR_afun23)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun3))), (ATerm) wsAfterBracketClose), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun7))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(PERR_afun0, (ATerm)ATmakeAppl1(PERR_afun20, (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl2(PERR_afun8, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun10)), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))))), (ATerm) list)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun12))), (ATerm) wsAfterComma3), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm) wsAfterDescription), (ATerm) description), (ATerm) wsAfterComma2), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm) wsAfterProducerType), (ATerm) producerType), (ATerm) wsAfterComma1), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm) wsAfterProducerId), (ATerm) producerId), (ATerm) wsAfterComma), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm) wsAfterId), (ATerm) id), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun14))), (ATerm) wsAfterFatalError), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun23))));
}

/*}}}  */
/*{{{  PERR_SubjectList PERR_makeSubjectListEmpty() */

PERR_SubjectList PERR_makeSubjectListEmpty()
{
  return (PERR_SubjectList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  PERR_SubjectList PERR_makeSubjectListSingle(PERR_Subject head) */

PERR_SubjectList PERR_makeSubjectListSingle(PERR_Subject head)
{
  return (PERR_SubjectList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  PERR_SubjectList PERR_makeSubjectListMany(PERR_Subject head, PERR_OptLayout wsAfterHead, PERR_OptLayout wsAfterSep, PERR_SubjectList tail) */

PERR_SubjectList PERR_makeSubjectListMany(PERR_Subject head, PERR_OptLayout wsAfterHead, PERR_OptLayout wsAfterSep, PERR_SubjectList tail)
{
  if (PERR_isSubjectListEmpty(tail)) {
    return PERR_makeSubjectListSingle(head);
  }
  return (PERR_SubjectList)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm) wsAfterSep), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm) wsAfterHead), (ATerm) head);
}

/*}}}  */
/*{{{  PERR_Subject PERR_makeSubjectSubject(PERR_OptLayout wsAfterSubject, PERR_OptLayout wsAfterParenOpen, PERR_StrCon id, PERR_OptLayout wsAfterId, PERR_OptLayout wsAfterComma, PERR_Location Location, PERR_OptLayout wsAfterLocation) */

PERR_Subject PERR_makeSubjectSubject(PERR_OptLayout wsAfterSubject, PERR_OptLayout wsAfterParenOpen, PERR_StrCon id, PERR_OptLayout wsAfterId, PERR_OptLayout wsAfterComma, PERR_Location Location, PERR_OptLayout wsAfterLocation)
{
  return (PERR_Subject)(ATerm)ATmakeAppl2(PERR_afun0, (ATerm)ATmakeAppl3(PERR_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun3))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun24)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun13)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun14))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun25))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun10))), (ATerm)ATmakeAppl1(PERR_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PERR_afun18, (ATerm)ATmakeAppl1(PERR_afun19, (ATerm)ATmakeAppl0(PERR_afun25)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun3))), (ATerm) wsAfterLocation), (ATerm) Location), (ATerm) wsAfterComma), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm) wsAfterId), (ATerm) id), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun14))), (ATerm) wsAfterSubject), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun25))));
}

/*}}}  */
/*{{{  PERR_Location PERR_makeLocationLocation(PERR_OptLayout wsAfterLocation, PERR_OptLayout wsAfterParenOpen, PERR_StrCon filename, PERR_OptLayout wsAfterFilename, PERR_OptLayout wsAfterComma, PERR_Area Area, PERR_OptLayout wsAfterArea) */

PERR_Location PERR_makeLocationLocation(PERR_OptLayout wsAfterLocation, PERR_OptLayout wsAfterParenOpen, PERR_StrCon filename, PERR_OptLayout wsAfterFilename, PERR_OptLayout wsAfterComma, PERR_Area Area, PERR_OptLayout wsAfterArea)
{
  return (PERR_Location)(ATerm)ATmakeAppl2(PERR_afun0, (ATerm)ATmakeAppl3(PERR_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun3))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun26)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun13)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun14))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun27))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun24))), (ATerm)ATmakeAppl1(PERR_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PERR_afun18, (ATerm)ATmakeAppl1(PERR_afun19, (ATerm)ATmakeAppl0(PERR_afun27)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun3))), (ATerm) wsAfterArea), (ATerm) Area), (ATerm) wsAfterComma), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm) wsAfterFilename), (ATerm) filename), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun14))), (ATerm) wsAfterLocation), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun27))));
}

/*}}}  */
/*{{{  PERR_Location PERR_makeLocationNoLocation() */

PERR_Location PERR_makeLocationNoLocation()
{
  return (PERR_Location)(ATerm)ATmakeAppl2(PERR_afun0, (ATerm)ATmakeAppl3(PERR_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun28))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun24))), (ATerm)ATmakeAppl1(PERR_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PERR_afun18, (ATerm)ATmakeAppl1(PERR_afun19, (ATerm)ATmakeAppl0(PERR_afun28)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun28))));
}

/*}}}  */
/*{{{  PERR_Area PERR_makeAreaArea(PERR_OptLayout wsAfterArea, PERR_OptLayout wsAfterParenOpen, PERR_NatCon beginLine, PERR_OptLayout wsAfterBeginLine, PERR_OptLayout wsAfterComma, PERR_NatCon beginColumn, PERR_OptLayout wsAfterBeginColumn, PERR_OptLayout wsAfterComma1, PERR_NatCon endLine, PERR_OptLayout wsAfterEndLine, PERR_OptLayout wsAfterComma2, PERR_NatCon endColumn, PERR_OptLayout wsAfterEndColumn, PERR_OptLayout wsAfterComma3, PERR_NatCon beginOffset, PERR_OptLayout wsAfterBeginOffset, PERR_OptLayout wsAfterComma4, PERR_NatCon endOffset, PERR_OptLayout wsAfterEndOffset) */

PERR_Area PERR_makeAreaArea(PERR_OptLayout wsAfterArea, PERR_OptLayout wsAfterParenOpen, PERR_NatCon beginLine, PERR_OptLayout wsAfterBeginLine, PERR_OptLayout wsAfterComma, PERR_NatCon beginColumn, PERR_OptLayout wsAfterBeginColumn, PERR_OptLayout wsAfterComma1, PERR_NatCon endLine, PERR_OptLayout wsAfterEndLine, PERR_OptLayout wsAfterComma2, PERR_NatCon endColumn, PERR_OptLayout wsAfterEndColumn, PERR_OptLayout wsAfterComma3, PERR_NatCon beginOffset, PERR_OptLayout wsAfterBeginOffset, PERR_OptLayout wsAfterComma4, PERR_NatCon endOffset, PERR_OptLayout wsAfterEndOffset)
{
  return (PERR_Area)(ATerm)ATmakeAppl2(PERR_afun0, (ATerm)ATmakeAppl3(PERR_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun3))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun29)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun29)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun29)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun29)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun29)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun29)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun14))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun30))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun26))), (ATerm)ATmakeAppl1(PERR_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PERR_afun18, (ATerm)ATmakeAppl1(PERR_afun19, (ATerm)ATmakeAppl0(PERR_afun30)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun3))), (ATerm) wsAfterEndOffset), (ATerm) endOffset), (ATerm) wsAfterComma4), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm) wsAfterBeginOffset), (ATerm) beginOffset), (ATerm) wsAfterComma3), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm) wsAfterEndColumn), (ATerm) endColumn), (ATerm) wsAfterComma2), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm) wsAfterEndLine), (ATerm) endLine), (ATerm) wsAfterComma1), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm) wsAfterBeginColumn), (ATerm) beginColumn), (ATerm) wsAfterComma), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun11))), (ATerm) wsAfterBeginLine), (ATerm) beginLine), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun14))), (ATerm) wsAfterArea), (ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun30))));
}

/*}}}  */
/*{{{  PERR_Area PERR_makeAreaNoArea() */

PERR_Area PERR_makeAreaNoArea()
{
  return (PERR_Area)(ATerm)ATmakeAppl2(PERR_afun0, (ATerm)ATmakeAppl3(PERR_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun31))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun26))), (ATerm)ATmakeAppl1(PERR_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PERR_afun18, (ATerm)ATmakeAppl1(PERR_afun19, (ATerm)ATmakeAppl0(PERR_afun31)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PERR_afun2, (ATerm)ATmakeAppl0(PERR_afun31))));
}

/*}}}  */
/*{{{  PERR_NatCon PERR_makeNatConString(char* string) */

PERR_NatCon PERR_makeNatConString(char* string)
{
  return (PERR_NatCon)(ATerm)ATmakeAppl2(PERR_afun0, (ATerm)ATmakeAppl3(PERR_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PERR_afun32, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun29)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun29))), (ATerm)ATmakeAppl0(PERR_afun33)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PERR_afun0, (ATerm)ATmakeAppl1(PERR_afun20, (ATerm)ATmakeAppl1(PERR_afun34, (ATerm)ATmakeAppl1(PERR_afun35, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PERR_afun36, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255)))))), (ATerm) ((ATerm) PERR_stringToChars(string)))));
}

/*}}}  */
/*{{{  PERR_StrCon PERR_makeStrConString(char* string) */

PERR_StrCon PERR_makeStrConString(char* string)
{
  return (PERR_StrCon)(ATerm)ATmakeAppl2(PERR_afun0, (ATerm)ATmakeAppl3(PERR_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PERR_afun32, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun13)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun13))), (ATerm)ATmakeAppl0(PERR_afun33)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PERR_afun0, (ATerm)ATmakeAppl1(PERR_afun20, (ATerm)ATmakeAppl1(PERR_afun34, (ATerm)ATmakeAppl1(PERR_afun35, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PERR_afun36, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255)))))), (ATerm) ((ATerm) PERR_stringToChars(string)))));
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_makeOptLayoutAbsent() */

PERR_OptLayout PERR_makeOptLayoutAbsent()
{
  return (PERR_OptLayout)(ATerm)ATmakeAppl2(PERR_afun0, (ATerm)ATmakeAppl3(PERR_afun1, (ATerm)ATempty, (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6))), (ATerm)ATmakeAppl0(PERR_afun33)), (ATerm)ATempty);
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_makeOptLayoutPresent(char* string) */

PERR_OptLayout PERR_makeOptLayoutPresent(char* string)
{
  return (PERR_OptLayout)(ATerm)ATmakeAppl2(PERR_afun0, (ATerm)ATmakeAppl3(PERR_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl0(PERR_afun6))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6))), (ATerm)ATmakeAppl0(PERR_afun33)), (ATerm) ((ATerm) PERR_stringToChars(string)));
}

/*}}}  */
/*{{{  PERR_Start PERR_makeStartArea(PERR_OptLayout wsBefore, PERR_Area topArea, PERR_OptLayout wsAfter, int ambCnt) */

PERR_Start PERR_makeStartArea(PERR_OptLayout wsBefore, PERR_Area topArea, PERR_OptLayout wsAfter, int ambCnt)
{
  return (PERR_Start)(ATerm)ATmakeAppl2(PERR_afun37, (ATerm)ATmakeAppl2(PERR_afun0, (ATerm)ATmakeAppl3(PERR_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun26)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun38)), (ATerm)ATmakeAppl0(PERR_afun33)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topArea), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  PERR_Start PERR_makeStartLocation(PERR_OptLayout wsBefore, PERR_Location topLocation, PERR_OptLayout wsAfter, int ambCnt) */

PERR_Start PERR_makeStartLocation(PERR_OptLayout wsBefore, PERR_Location topLocation, PERR_OptLayout wsAfter, int ambCnt)
{
  return (PERR_Start)(ATerm)ATmakeAppl2(PERR_afun37, (ATerm)ATmakeAppl2(PERR_afun0, (ATerm)ATmakeAppl3(PERR_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun24)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun38)), (ATerm)ATmakeAppl0(PERR_afun33)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topLocation), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  PERR_Start PERR_makeStartSubject(PERR_OptLayout wsBefore, PERR_Subject topSubject, PERR_OptLayout wsAfter, int ambCnt) */

PERR_Start PERR_makeStartSubject(PERR_OptLayout wsBefore, PERR_Subject topSubject, PERR_OptLayout wsAfter, int ambCnt)
{
  return (PERR_Start)(ATerm)ATmakeAppl2(PERR_afun37, (ATerm)ATmakeAppl2(PERR_afun0, (ATerm)ATmakeAppl3(PERR_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun10)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun38)), (ATerm)ATmakeAppl0(PERR_afun33)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topSubject), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  PERR_Start PERR_makeStartFeedback(PERR_OptLayout wsBefore, PERR_Feedback topFeedback, PERR_OptLayout wsAfter, int ambCnt) */

PERR_Start PERR_makeStartFeedback(PERR_OptLayout wsBefore, PERR_Feedback topFeedback, PERR_OptLayout wsAfter, int ambCnt)
{
  return (PERR_Start)(ATerm)ATmakeAppl2(PERR_afun37, (ATerm)ATmakeAppl2(PERR_afun0, (ATerm)ATmakeAppl3(PERR_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun16)))), (ATerm)ATmakeAppl1(PERR_afun4, (ATerm)ATmakeAppl1(PERR_afun5, (ATerm)ATmakeAppl0(PERR_afun6)))), (ATerm)ATmakeAppl1(PERR_afun9, (ATerm)ATmakeAppl0(PERR_afun38)), (ATerm)ATmakeAppl0(PERR_afun33)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topFeedback), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool PERR_isEqualFeedback(PERR_Feedback arg0, PERR_Feedback arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PERR_isEqualSubjectList(PERR_SubjectList arg0, PERR_SubjectList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PERR_isEqualSubject(PERR_Subject arg0, PERR_Subject arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PERR_isEqualLocation(PERR_Location arg0, PERR_Location arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PERR_isEqualArea(PERR_Area arg0, PERR_Area arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PERR_isEqualNatCon(PERR_NatCon arg0, PERR_NatCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PERR_isEqualStrCon(PERR_StrCon arg0, PERR_StrCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PERR_isEqualOptLayout(PERR_OptLayout arg0, PERR_OptLayout arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PERR_isEqualStart(PERR_Start arg0, PERR_Start arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  PERR_Feedback accessors */

/*{{{  ATbool PERR_isValidFeedback(PERR_Feedback arg) */

ATbool PERR_isValidFeedback(PERR_Feedback arg)
{
  if (PERR_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PERR_isFeedbackInfo(PERR_Feedback arg) */

inline ATbool PERR_isFeedbackInfo(PERR_Feedback arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PERR_patternFeedbackInfo, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PERR_isFeedbackWarning(PERR_Feedback arg) */

inline ATbool PERR_isFeedbackWarning(PERR_Feedback arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PERR_patternFeedbackWarning, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PERR_isFeedbackError(PERR_Feedback arg) */

inline ATbool PERR_isFeedbackError(PERR_Feedback arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PERR_patternFeedbackError, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PERR_isFeedbackFatalError(PERR_Feedback arg) */

inline ATbool PERR_isFeedbackFatalError(PERR_Feedback arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PERR_patternFeedbackFatalError, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PERR_hasFeedbackWsAfterInfo(PERR_Feedback arg) */

ATbool PERR_hasFeedbackWsAfterInfo(PERR_Feedback arg)
{
  if (PERR_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getFeedbackWsAfterInfo(PERR_Feedback arg) */

PERR_OptLayout PERR_getFeedbackWsAfterInfo(PERR_Feedback arg)
{
  
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PERR_Feedback PERR_setFeedbackWsAfterInfo(PERR_Feedback arg, PERR_OptLayout wsAfterInfo) */

PERR_Feedback PERR_setFeedbackWsAfterInfo(PERR_Feedback arg, PERR_OptLayout wsAfterInfo)
{
  if (PERR_isFeedbackInfo(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterInfo), 1), 1);
  }

  ATabort("Feedback has no WsAfterInfo: %t\n", arg);
  return (PERR_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasFeedbackWsAfterParenOpen(PERR_Feedback arg) */

ATbool PERR_hasFeedbackWsAfterParenOpen(PERR_Feedback arg)
{
  if (PERR_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getFeedbackWsAfterParenOpen(PERR_Feedback arg) */

PERR_OptLayout PERR_getFeedbackWsAfterParenOpen(PERR_Feedback arg)
{
  if (PERR_isFeedbackInfo(arg)) {
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (PERR_isFeedbackError(arg)) {
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  PERR_Feedback PERR_setFeedbackWsAfterParenOpen(PERR_Feedback arg, PERR_OptLayout wsAfterParenOpen) */

PERR_Feedback PERR_setFeedbackWsAfterParenOpen(PERR_Feedback arg, PERR_OptLayout wsAfterParenOpen)
{
  if (PERR_isFeedbackInfo(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PERR_isFeedbackError(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PERR_isFeedbackFatalError(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("Feedback has no WsAfterParenOpen: %t\n", arg);
  return (PERR_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasFeedbackId(PERR_Feedback arg) */

ATbool PERR_hasFeedbackId(PERR_Feedback arg)
{
  if (PERR_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_StrCon PERR_getFeedbackId(PERR_Feedback arg) */

PERR_StrCon PERR_getFeedbackId(PERR_Feedback arg)
{
  if (PERR_isFeedbackInfo(arg)) {
    return (PERR_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return (PERR_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else if (PERR_isFeedbackError(arg)) {
    return (PERR_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (PERR_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PERR_Feedback PERR_setFeedbackId(PERR_Feedback arg, PERR_StrCon id) */

PERR_Feedback PERR_setFeedbackId(PERR_Feedback arg, PERR_StrCon id)
{
  if (PERR_isFeedbackInfo(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) id), 4), 1);
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) id), 4), 1);
  }
  else if (PERR_isFeedbackError(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) id), 4), 1);
  }
  else if (PERR_isFeedbackFatalError(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) id), 4), 1);
  }

  ATabort("Feedback has no Id: %t\n", arg);
  return (PERR_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasFeedbackWsAfterId(PERR_Feedback arg) */

ATbool PERR_hasFeedbackWsAfterId(PERR_Feedback arg)
{
  if (PERR_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getFeedbackWsAfterId(PERR_Feedback arg) */

PERR_OptLayout PERR_getFeedbackWsAfterId(PERR_Feedback arg)
{
  if (PERR_isFeedbackInfo(arg)) {
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else if (PERR_isFeedbackError(arg)) {
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else 
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PERR_Feedback PERR_setFeedbackWsAfterId(PERR_Feedback arg, PERR_OptLayout wsAfterId) */

PERR_Feedback PERR_setFeedbackWsAfterId(PERR_Feedback arg, PERR_OptLayout wsAfterId)
{
  if (PERR_isFeedbackInfo(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterId), 5), 1);
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterId), 5), 1);
  }
  else if (PERR_isFeedbackError(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterId), 5), 1);
  }
  else if (PERR_isFeedbackFatalError(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterId), 5), 1);
  }

  ATabort("Feedback has no WsAfterId: %t\n", arg);
  return (PERR_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasFeedbackWsAfterComma(PERR_Feedback arg) */

ATbool PERR_hasFeedbackWsAfterComma(PERR_Feedback arg)
{
  if (PERR_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getFeedbackWsAfterComma(PERR_Feedback arg) */

PERR_OptLayout PERR_getFeedbackWsAfterComma(PERR_Feedback arg)
{
  if (PERR_isFeedbackInfo(arg)) {
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else if (PERR_isFeedbackError(arg)) {
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else 
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  PERR_Feedback PERR_setFeedbackWsAfterComma(PERR_Feedback arg, PERR_OptLayout wsAfterComma) */

PERR_Feedback PERR_setFeedbackWsAfterComma(PERR_Feedback arg, PERR_OptLayout wsAfterComma)
{
  if (PERR_isFeedbackInfo(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }
  else if (PERR_isFeedbackError(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }
  else if (PERR_isFeedbackFatalError(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }

  ATabort("Feedback has no WsAfterComma: %t\n", arg);
  return (PERR_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasFeedbackProducerId(PERR_Feedback arg) */

ATbool PERR_hasFeedbackProducerId(PERR_Feedback arg)
{
  if (PERR_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_StrCon PERR_getFeedbackProducerId(PERR_Feedback arg) */

PERR_StrCon PERR_getFeedbackProducerId(PERR_Feedback arg)
{
  if (PERR_isFeedbackInfo(arg)) {
    return (PERR_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return (PERR_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
  }
  else if (PERR_isFeedbackError(arg)) {
    return (PERR_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
  }
  else 
    return (PERR_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/*}}}  */
/*{{{  PERR_Feedback PERR_setFeedbackProducerId(PERR_Feedback arg, PERR_StrCon producerId) */

PERR_Feedback PERR_setFeedbackProducerId(PERR_Feedback arg, PERR_StrCon producerId)
{
  if (PERR_isFeedbackInfo(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) producerId), 8), 1);
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) producerId), 8), 1);
  }
  else if (PERR_isFeedbackError(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) producerId), 8), 1);
  }
  else if (PERR_isFeedbackFatalError(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) producerId), 8), 1);
  }

  ATabort("Feedback has no ProducerId: %t\n", arg);
  return (PERR_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasFeedbackWsAfterProducerId(PERR_Feedback arg) */

ATbool PERR_hasFeedbackWsAfterProducerId(PERR_Feedback arg)
{
  if (PERR_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getFeedbackWsAfterProducerId(PERR_Feedback arg) */

PERR_OptLayout PERR_getFeedbackWsAfterProducerId(PERR_Feedback arg)
{
  if (PERR_isFeedbackInfo(arg)) {
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
  }
  else if (PERR_isFeedbackError(arg)) {
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
  }
  else 
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/*}}}  */
/*{{{  PERR_Feedback PERR_setFeedbackWsAfterProducerId(PERR_Feedback arg, PERR_OptLayout wsAfterProducerId) */

PERR_Feedback PERR_setFeedbackWsAfterProducerId(PERR_Feedback arg, PERR_OptLayout wsAfterProducerId)
{
  if (PERR_isFeedbackInfo(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterProducerId), 9), 1);
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterProducerId), 9), 1);
  }
  else if (PERR_isFeedbackError(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterProducerId), 9), 1);
  }
  else if (PERR_isFeedbackFatalError(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterProducerId), 9), 1);
  }

  ATabort("Feedback has no WsAfterProducerId: %t\n", arg);
  return (PERR_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasFeedbackWsAfterComma1(PERR_Feedback arg) */

ATbool PERR_hasFeedbackWsAfterComma1(PERR_Feedback arg)
{
  if (PERR_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getFeedbackWsAfterComma1(PERR_Feedback arg) */

PERR_OptLayout PERR_getFeedbackWsAfterComma1(PERR_Feedback arg)
{
  if (PERR_isFeedbackInfo(arg)) {
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 11);
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 11);
  }
  else if (PERR_isFeedbackError(arg)) {
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 11);
  }
  else 
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 11);
}

/*}}}  */
/*{{{  PERR_Feedback PERR_setFeedbackWsAfterComma1(PERR_Feedback arg, PERR_OptLayout wsAfterComma1) */

PERR_Feedback PERR_setFeedbackWsAfterComma1(PERR_Feedback arg, PERR_OptLayout wsAfterComma1)
{
  if (PERR_isFeedbackInfo(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma1), 11), 1);
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma1), 11), 1);
  }
  else if (PERR_isFeedbackError(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma1), 11), 1);
  }
  else if (PERR_isFeedbackFatalError(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma1), 11), 1);
  }

  ATabort("Feedback has no WsAfterComma1: %t\n", arg);
  return (PERR_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasFeedbackProducerType(PERR_Feedback arg) */

ATbool PERR_hasFeedbackProducerType(PERR_Feedback arg)
{
  if (PERR_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_StrCon PERR_getFeedbackProducerType(PERR_Feedback arg) */

PERR_StrCon PERR_getFeedbackProducerType(PERR_Feedback arg)
{
  if (PERR_isFeedbackInfo(arg)) {
    return (PERR_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 12);
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return (PERR_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 12);
  }
  else if (PERR_isFeedbackError(arg)) {
    return (PERR_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 12);
  }
  else 
    return (PERR_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 12);
}

/*}}}  */
/*{{{  PERR_Feedback PERR_setFeedbackProducerType(PERR_Feedback arg, PERR_StrCon producerType) */

PERR_Feedback PERR_setFeedbackProducerType(PERR_Feedback arg, PERR_StrCon producerType)
{
  if (PERR_isFeedbackInfo(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) producerType), 12), 1);
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) producerType), 12), 1);
  }
  else if (PERR_isFeedbackError(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) producerType), 12), 1);
  }
  else if (PERR_isFeedbackFatalError(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) producerType), 12), 1);
  }

  ATabort("Feedback has no ProducerType: %t\n", arg);
  return (PERR_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasFeedbackWsAfterProducerType(PERR_Feedback arg) */

ATbool PERR_hasFeedbackWsAfterProducerType(PERR_Feedback arg)
{
  if (PERR_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getFeedbackWsAfterProducerType(PERR_Feedback arg) */

PERR_OptLayout PERR_getFeedbackWsAfterProducerType(PERR_Feedback arg)
{
  if (PERR_isFeedbackInfo(arg)) {
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 13);
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 13);
  }
  else if (PERR_isFeedbackError(arg)) {
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 13);
  }
  else 
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 13);
}

/*}}}  */
/*{{{  PERR_Feedback PERR_setFeedbackWsAfterProducerType(PERR_Feedback arg, PERR_OptLayout wsAfterProducerType) */

PERR_Feedback PERR_setFeedbackWsAfterProducerType(PERR_Feedback arg, PERR_OptLayout wsAfterProducerType)
{
  if (PERR_isFeedbackInfo(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterProducerType), 13), 1);
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterProducerType), 13), 1);
  }
  else if (PERR_isFeedbackError(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterProducerType), 13), 1);
  }
  else if (PERR_isFeedbackFatalError(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterProducerType), 13), 1);
  }

  ATabort("Feedback has no WsAfterProducerType: %t\n", arg);
  return (PERR_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasFeedbackWsAfterComma2(PERR_Feedback arg) */

ATbool PERR_hasFeedbackWsAfterComma2(PERR_Feedback arg)
{
  if (PERR_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getFeedbackWsAfterComma2(PERR_Feedback arg) */

PERR_OptLayout PERR_getFeedbackWsAfterComma2(PERR_Feedback arg)
{
  if (PERR_isFeedbackInfo(arg)) {
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 15);
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 15);
  }
  else if (PERR_isFeedbackError(arg)) {
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 15);
  }
  else 
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 15);
}

/*}}}  */
/*{{{  PERR_Feedback PERR_setFeedbackWsAfterComma2(PERR_Feedback arg, PERR_OptLayout wsAfterComma2) */

PERR_Feedback PERR_setFeedbackWsAfterComma2(PERR_Feedback arg, PERR_OptLayout wsAfterComma2)
{
  if (PERR_isFeedbackInfo(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma2), 15), 1);
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma2), 15), 1);
  }
  else if (PERR_isFeedbackError(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma2), 15), 1);
  }
  else if (PERR_isFeedbackFatalError(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma2), 15), 1);
  }

  ATabort("Feedback has no WsAfterComma2: %t\n", arg);
  return (PERR_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasFeedbackDescription(PERR_Feedback arg) */

ATbool PERR_hasFeedbackDescription(PERR_Feedback arg)
{
  if (PERR_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_StrCon PERR_getFeedbackDescription(PERR_Feedback arg) */

PERR_StrCon PERR_getFeedbackDescription(PERR_Feedback arg)
{
  if (PERR_isFeedbackInfo(arg)) {
    return (PERR_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 16);
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return (PERR_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 16);
  }
  else if (PERR_isFeedbackError(arg)) {
    return (PERR_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 16);
  }
  else 
    return (PERR_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 16);
}

/*}}}  */
/*{{{  PERR_Feedback PERR_setFeedbackDescription(PERR_Feedback arg, PERR_StrCon description) */

PERR_Feedback PERR_setFeedbackDescription(PERR_Feedback arg, PERR_StrCon description)
{
  if (PERR_isFeedbackInfo(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) description), 16), 1);
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) description), 16), 1);
  }
  else if (PERR_isFeedbackError(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) description), 16), 1);
  }
  else if (PERR_isFeedbackFatalError(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) description), 16), 1);
  }

  ATabort("Feedback has no Description: %t\n", arg);
  return (PERR_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasFeedbackWsAfterDescription(PERR_Feedback arg) */

ATbool PERR_hasFeedbackWsAfterDescription(PERR_Feedback arg)
{
  if (PERR_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getFeedbackWsAfterDescription(PERR_Feedback arg) */

PERR_OptLayout PERR_getFeedbackWsAfterDescription(PERR_Feedback arg)
{
  if (PERR_isFeedbackInfo(arg)) {
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 17);
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 17);
  }
  else if (PERR_isFeedbackError(arg)) {
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 17);
  }
  else 
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 17);
}

/*}}}  */
/*{{{  PERR_Feedback PERR_setFeedbackWsAfterDescription(PERR_Feedback arg, PERR_OptLayout wsAfterDescription) */

PERR_Feedback PERR_setFeedbackWsAfterDescription(PERR_Feedback arg, PERR_OptLayout wsAfterDescription)
{
  if (PERR_isFeedbackInfo(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterDescription), 17), 1);
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterDescription), 17), 1);
  }
  else if (PERR_isFeedbackError(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterDescription), 17), 1);
  }
  else if (PERR_isFeedbackFatalError(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterDescription), 17), 1);
  }

  ATabort("Feedback has no WsAfterDescription: %t\n", arg);
  return (PERR_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasFeedbackWsAfterComma3(PERR_Feedback arg) */

ATbool PERR_hasFeedbackWsAfterComma3(PERR_Feedback arg)
{
  if (PERR_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getFeedbackWsAfterComma3(PERR_Feedback arg) */

PERR_OptLayout PERR_getFeedbackWsAfterComma3(PERR_Feedback arg)
{
  if (PERR_isFeedbackInfo(arg)) {
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 19);
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 19);
  }
  else if (PERR_isFeedbackError(arg)) {
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 19);
  }
  else 
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 19);
}

/*}}}  */
/*{{{  PERR_Feedback PERR_setFeedbackWsAfterComma3(PERR_Feedback arg, PERR_OptLayout wsAfterComma3) */

PERR_Feedback PERR_setFeedbackWsAfterComma3(PERR_Feedback arg, PERR_OptLayout wsAfterComma3)
{
  if (PERR_isFeedbackInfo(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma3), 19), 1);
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma3), 19), 1);
  }
  else if (PERR_isFeedbackError(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma3), 19), 1);
  }
  else if (PERR_isFeedbackFatalError(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma3), 19), 1);
  }

  ATabort("Feedback has no WsAfterComma3: %t\n", arg);
  return (PERR_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasFeedbackWsAfterBracketOpen(PERR_Feedback arg) */

ATbool PERR_hasFeedbackWsAfterBracketOpen(PERR_Feedback arg)
{
  if (PERR_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getFeedbackWsAfterBracketOpen(PERR_Feedback arg) */

PERR_OptLayout PERR_getFeedbackWsAfterBracketOpen(PERR_Feedback arg)
{
  if (PERR_isFeedbackInfo(arg)) {
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 21);
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 21);
  }
  else if (PERR_isFeedbackError(arg)) {
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 21);
  }
  else 
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 21);
}

/*}}}  */
/*{{{  PERR_Feedback PERR_setFeedbackWsAfterBracketOpen(PERR_Feedback arg, PERR_OptLayout wsAfterBracketOpen) */

PERR_Feedback PERR_setFeedbackWsAfterBracketOpen(PERR_Feedback arg, PERR_OptLayout wsAfterBracketOpen)
{
  if (PERR_isFeedbackInfo(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 21), 1);
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 21), 1);
  }
  else if (PERR_isFeedbackError(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 21), 1);
  }
  else if (PERR_isFeedbackFatalError(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 21), 1);
  }

  ATabort("Feedback has no WsAfterBracketOpen: %t\n", arg);
  return (PERR_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasFeedbackList(PERR_Feedback arg) */

ATbool PERR_hasFeedbackList(PERR_Feedback arg)
{
  if (PERR_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_SubjectList PERR_getFeedbackList(PERR_Feedback arg) */

PERR_SubjectList PERR_getFeedbackList(PERR_Feedback arg)
{
  if (PERR_isFeedbackInfo(arg)) {
    return (PERR_SubjectList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 22), 1);
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return (PERR_SubjectList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 22), 1);
  }
  else if (PERR_isFeedbackError(arg)) {
    return (PERR_SubjectList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 22), 1);
  }
  else 
    return (PERR_SubjectList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 22), 1);
}

/*}}}  */
/*{{{  PERR_Feedback PERR_setFeedbackList(PERR_Feedback arg, PERR_SubjectList list) */

PERR_Feedback PERR_setFeedbackList(PERR_Feedback arg, PERR_SubjectList list)
{
  if (PERR_isFeedbackInfo(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 22), (ATerm)((ATerm) list), 1), 22), 1);
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 22), (ATerm)((ATerm) list), 1), 22), 1);
  }
  else if (PERR_isFeedbackError(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 22), (ATerm)((ATerm) list), 1), 22), 1);
  }
  else if (PERR_isFeedbackFatalError(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 22), (ATerm)((ATerm) list), 1), 22), 1);
  }

  ATabort("Feedback has no List: %t\n", arg);
  return (PERR_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasFeedbackWsAfterList(PERR_Feedback arg) */

ATbool PERR_hasFeedbackWsAfterList(PERR_Feedback arg)
{
  if (PERR_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getFeedbackWsAfterList(PERR_Feedback arg) */

PERR_OptLayout PERR_getFeedbackWsAfterList(PERR_Feedback arg)
{
  if (PERR_isFeedbackInfo(arg)) {
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 23);
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 23);
  }
  else if (PERR_isFeedbackError(arg)) {
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 23);
  }
  else 
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 23);
}

/*}}}  */
/*{{{  PERR_Feedback PERR_setFeedbackWsAfterList(PERR_Feedback arg, PERR_OptLayout wsAfterList) */

PERR_Feedback PERR_setFeedbackWsAfterList(PERR_Feedback arg, PERR_OptLayout wsAfterList)
{
  if (PERR_isFeedbackInfo(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterList), 23), 1);
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterList), 23), 1);
  }
  else if (PERR_isFeedbackError(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterList), 23), 1);
  }
  else if (PERR_isFeedbackFatalError(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterList), 23), 1);
  }

  ATabort("Feedback has no WsAfterList: %t\n", arg);
  return (PERR_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasFeedbackWsAfterBracketClose(PERR_Feedback arg) */

ATbool PERR_hasFeedbackWsAfterBracketClose(PERR_Feedback arg)
{
  if (PERR_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (PERR_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getFeedbackWsAfterBracketClose(PERR_Feedback arg) */

PERR_OptLayout PERR_getFeedbackWsAfterBracketClose(PERR_Feedback arg)
{
  if (PERR_isFeedbackInfo(arg)) {
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 25);
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 25);
  }
  else if (PERR_isFeedbackError(arg)) {
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 25);
  }
  else 
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 25);
}

/*}}}  */
/*{{{  PERR_Feedback PERR_setFeedbackWsAfterBracketClose(PERR_Feedback arg, PERR_OptLayout wsAfterBracketClose) */

PERR_Feedback PERR_setFeedbackWsAfterBracketClose(PERR_Feedback arg, PERR_OptLayout wsAfterBracketClose)
{
  if (PERR_isFeedbackInfo(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketClose), 25), 1);
  }
  else if (PERR_isFeedbackWarning(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketClose), 25), 1);
  }
  else if (PERR_isFeedbackError(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketClose), 25), 1);
  }
  else if (PERR_isFeedbackFatalError(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketClose), 25), 1);
  }

  ATabort("Feedback has no WsAfterBracketClose: %t\n", arg);
  return (PERR_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasFeedbackWsAfterWarning(PERR_Feedback arg) */

ATbool PERR_hasFeedbackWsAfterWarning(PERR_Feedback arg)
{
  if (PERR_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getFeedbackWsAfterWarning(PERR_Feedback arg) */

PERR_OptLayout PERR_getFeedbackWsAfterWarning(PERR_Feedback arg)
{
  
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PERR_Feedback PERR_setFeedbackWsAfterWarning(PERR_Feedback arg, PERR_OptLayout wsAfterWarning) */

PERR_Feedback PERR_setFeedbackWsAfterWarning(PERR_Feedback arg, PERR_OptLayout wsAfterWarning)
{
  if (PERR_isFeedbackWarning(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterWarning), 1), 1);
  }

  ATabort("Feedback has no WsAfterWarning: %t\n", arg);
  return (PERR_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasFeedbackWsAfterError(PERR_Feedback arg) */

ATbool PERR_hasFeedbackWsAfterError(PERR_Feedback arg)
{
  if (PERR_isFeedbackError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getFeedbackWsAfterError(PERR_Feedback arg) */

PERR_OptLayout PERR_getFeedbackWsAfterError(PERR_Feedback arg)
{
  
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PERR_Feedback PERR_setFeedbackWsAfterError(PERR_Feedback arg, PERR_OptLayout wsAfterError) */

PERR_Feedback PERR_setFeedbackWsAfterError(PERR_Feedback arg, PERR_OptLayout wsAfterError)
{
  if (PERR_isFeedbackError(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterError), 1), 1);
  }

  ATabort("Feedback has no WsAfterError: %t\n", arg);
  return (PERR_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasFeedbackWsAfterFatalError(PERR_Feedback arg) */

ATbool PERR_hasFeedbackWsAfterFatalError(PERR_Feedback arg)
{
  if (PERR_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getFeedbackWsAfterFatalError(PERR_Feedback arg) */

PERR_OptLayout PERR_getFeedbackWsAfterFatalError(PERR_Feedback arg)
{
  
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PERR_Feedback PERR_setFeedbackWsAfterFatalError(PERR_Feedback arg, PERR_OptLayout wsAfterFatalError) */

PERR_Feedback PERR_setFeedbackWsAfterFatalError(PERR_Feedback arg, PERR_OptLayout wsAfterFatalError)
{
  if (PERR_isFeedbackFatalError(arg)) {
    return (PERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterFatalError), 1), 1);
  }

  ATabort("Feedback has no WsAfterFatalError: %t\n", arg);
  return (PERR_Feedback)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PERR_SubjectList accessors */

/*{{{  ATbool PERR_isValidSubjectList(PERR_SubjectList arg) */

ATbool PERR_isValidSubjectList(PERR_SubjectList arg)
{
  if (PERR_isSubjectListEmpty(arg)) {
    return ATtrue;
  }
  else if (PERR_isSubjectListSingle(arg)) {
    return ATtrue;
  }
  else if (PERR_isSubjectListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PERR_isSubjectListEmpty(PERR_SubjectList arg) */

inline ATbool PERR_isSubjectListEmpty(PERR_SubjectList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PERR_patternSubjectListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool PERR_isSubjectListSingle(PERR_SubjectList arg) */

inline ATbool PERR_isSubjectListSingle(PERR_SubjectList arg)
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
      last_result = ATmatchTerm((ATerm)arg, PERR_patternSubjectListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PERR_isSubjectListMany(PERR_SubjectList arg) */

inline ATbool PERR_isSubjectListMany(PERR_SubjectList arg)
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
      last_result = ATmatchTerm((ATerm)arg, PERR_patternSubjectListMany, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PERR_hasSubjectListHead(PERR_SubjectList arg) */

ATbool PERR_hasSubjectListHead(PERR_SubjectList arg)
{
  if (PERR_isSubjectListSingle(arg)) {
    return ATtrue;
  }
  else if (PERR_isSubjectListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_Subject PERR_getSubjectListHead(PERR_SubjectList arg) */

PERR_Subject PERR_getSubjectListHead(PERR_SubjectList arg)
{
  if (PERR_isSubjectListSingle(arg)) {
    return (PERR_Subject)ATgetFirst((ATermList)arg);
  }
  else 
    return (PERR_Subject)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  PERR_SubjectList PERR_setSubjectListHead(PERR_SubjectList arg, PERR_Subject head) */

PERR_SubjectList PERR_setSubjectListHead(PERR_SubjectList arg, PERR_Subject head)
{
  if (PERR_isSubjectListSingle(arg)) {
    return (PERR_SubjectList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (PERR_isSubjectListMany(arg)) {
    return (PERR_SubjectList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("SubjectList has no Head: %t\n", arg);
  return (PERR_SubjectList)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasSubjectListWsAfterHead(PERR_SubjectList arg) */

ATbool PERR_hasSubjectListWsAfterHead(PERR_SubjectList arg)
{
  if (PERR_isSubjectListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getSubjectListWsAfterHead(PERR_SubjectList arg) */

PERR_OptLayout PERR_getSubjectListWsAfterHead(PERR_SubjectList arg)
{
  
    return (PERR_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  PERR_SubjectList PERR_setSubjectListWsAfterHead(PERR_SubjectList arg, PERR_OptLayout wsAfterHead) */

PERR_SubjectList PERR_setSubjectListWsAfterHead(PERR_SubjectList arg, PERR_OptLayout wsAfterHead)
{
  if (PERR_isSubjectListMany(arg)) {
    return (PERR_SubjectList)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterHead), 1);
  }

  ATabort("SubjectList has no WsAfterHead: %t\n", arg);
  return (PERR_SubjectList)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasSubjectListWsAfterSep(PERR_SubjectList arg) */

ATbool PERR_hasSubjectListWsAfterSep(PERR_SubjectList arg)
{
  if (PERR_isSubjectListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getSubjectListWsAfterSep(PERR_SubjectList arg) */

PERR_OptLayout PERR_getSubjectListWsAfterSep(PERR_SubjectList arg)
{
  
    return (PERR_OptLayout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  PERR_SubjectList PERR_setSubjectListWsAfterSep(PERR_SubjectList arg, PERR_OptLayout wsAfterSep) */

PERR_SubjectList PERR_setSubjectListWsAfterSep(PERR_SubjectList arg, PERR_OptLayout wsAfterSep)
{
  if (PERR_isSubjectListMany(arg)) {
    return (PERR_SubjectList)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterSep), 3);
  }

  ATabort("SubjectList has no WsAfterSep: %t\n", arg);
  return (PERR_SubjectList)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasSubjectListTail(PERR_SubjectList arg) */

ATbool PERR_hasSubjectListTail(PERR_SubjectList arg)
{
  if (PERR_isSubjectListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_SubjectList PERR_getSubjectListTail(PERR_SubjectList arg) */

PERR_SubjectList PERR_getSubjectListTail(PERR_SubjectList arg)
{
  
    return (PERR_SubjectList)ATgetTail((ATermList)arg, 4);
}

/*}}}  */
/*{{{  PERR_SubjectList PERR_setSubjectListTail(PERR_SubjectList arg, PERR_SubjectList tail) */

PERR_SubjectList PERR_setSubjectListTail(PERR_SubjectList arg, PERR_SubjectList tail)
{
  if (PERR_isSubjectListMany(arg)) {
    return (PERR_SubjectList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 4);
  }

  ATabort("SubjectList has no Tail: %t\n", arg);
  return (PERR_SubjectList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PERR_Subject accessors */

/*{{{  ATbool PERR_isValidSubject(PERR_Subject arg) */

ATbool PERR_isValidSubject(PERR_Subject arg)
{
  if (PERR_isSubjectSubject(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PERR_isSubjectSubject(PERR_Subject arg) */

inline ATbool PERR_isSubjectSubject(PERR_Subject arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PERR_patternSubjectSubject, NULL, NULL, NULL, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PERR_hasSubjectWsAfterSubject(PERR_Subject arg) */

ATbool PERR_hasSubjectWsAfterSubject(PERR_Subject arg)
{
  if (PERR_isSubjectSubject(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getSubjectWsAfterSubject(PERR_Subject arg) */

PERR_OptLayout PERR_getSubjectWsAfterSubject(PERR_Subject arg)
{
  
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PERR_Subject PERR_setSubjectWsAfterSubject(PERR_Subject arg, PERR_OptLayout wsAfterSubject) */

PERR_Subject PERR_setSubjectWsAfterSubject(PERR_Subject arg, PERR_OptLayout wsAfterSubject)
{
  if (PERR_isSubjectSubject(arg)) {
    return (PERR_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSubject), 1), 1);
  }

  ATabort("Subject has no WsAfterSubject: %t\n", arg);
  return (PERR_Subject)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasSubjectWsAfterParenOpen(PERR_Subject arg) */

ATbool PERR_hasSubjectWsAfterParenOpen(PERR_Subject arg)
{
  if (PERR_isSubjectSubject(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getSubjectWsAfterParenOpen(PERR_Subject arg) */

PERR_OptLayout PERR_getSubjectWsAfterParenOpen(PERR_Subject arg)
{
  
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  PERR_Subject PERR_setSubjectWsAfterParenOpen(PERR_Subject arg, PERR_OptLayout wsAfterParenOpen) */

PERR_Subject PERR_setSubjectWsAfterParenOpen(PERR_Subject arg, PERR_OptLayout wsAfterParenOpen)
{
  if (PERR_isSubjectSubject(arg)) {
    return (PERR_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("Subject has no WsAfterParenOpen: %t\n", arg);
  return (PERR_Subject)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasSubjectId(PERR_Subject arg) */

ATbool PERR_hasSubjectId(PERR_Subject arg)
{
  if (PERR_isSubjectSubject(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_StrCon PERR_getSubjectId(PERR_Subject arg) */

PERR_StrCon PERR_getSubjectId(PERR_Subject arg)
{
  
    return (PERR_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PERR_Subject PERR_setSubjectId(PERR_Subject arg, PERR_StrCon id) */

PERR_Subject PERR_setSubjectId(PERR_Subject arg, PERR_StrCon id)
{
  if (PERR_isSubjectSubject(arg)) {
    return (PERR_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) id), 4), 1);
  }

  ATabort("Subject has no Id: %t\n", arg);
  return (PERR_Subject)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasSubjectWsAfterId(PERR_Subject arg) */

ATbool PERR_hasSubjectWsAfterId(PERR_Subject arg)
{
  if (PERR_isSubjectSubject(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getSubjectWsAfterId(PERR_Subject arg) */

PERR_OptLayout PERR_getSubjectWsAfterId(PERR_Subject arg)
{
  
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PERR_Subject PERR_setSubjectWsAfterId(PERR_Subject arg, PERR_OptLayout wsAfterId) */

PERR_Subject PERR_setSubjectWsAfterId(PERR_Subject arg, PERR_OptLayout wsAfterId)
{
  if (PERR_isSubjectSubject(arg)) {
    return (PERR_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterId), 5), 1);
  }

  ATabort("Subject has no WsAfterId: %t\n", arg);
  return (PERR_Subject)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasSubjectWsAfterComma(PERR_Subject arg) */

ATbool PERR_hasSubjectWsAfterComma(PERR_Subject arg)
{
  if (PERR_isSubjectSubject(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getSubjectWsAfterComma(PERR_Subject arg) */

PERR_OptLayout PERR_getSubjectWsAfterComma(PERR_Subject arg)
{
  
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  PERR_Subject PERR_setSubjectWsAfterComma(PERR_Subject arg, PERR_OptLayout wsAfterComma) */

PERR_Subject PERR_setSubjectWsAfterComma(PERR_Subject arg, PERR_OptLayout wsAfterComma)
{
  if (PERR_isSubjectSubject(arg)) {
    return (PERR_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }

  ATabort("Subject has no WsAfterComma: %t\n", arg);
  return (PERR_Subject)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasSubjectLocation(PERR_Subject arg) */

ATbool PERR_hasSubjectLocation(PERR_Subject arg)
{
  if (PERR_isSubjectSubject(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_Location PERR_getSubjectLocation(PERR_Subject arg) */

PERR_Location PERR_getSubjectLocation(PERR_Subject arg)
{
  
    return (PERR_Location)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/*}}}  */
/*{{{  PERR_Subject PERR_setSubjectLocation(PERR_Subject arg, PERR_Location Location) */

PERR_Subject PERR_setSubjectLocation(PERR_Subject arg, PERR_Location Location)
{
  if (PERR_isSubjectSubject(arg)) {
    return (PERR_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Location), 8), 1);
  }

  ATabort("Subject has no Location: %t\n", arg);
  return (PERR_Subject)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasSubjectWsAfterLocation(PERR_Subject arg) */

ATbool PERR_hasSubjectWsAfterLocation(PERR_Subject arg)
{
  if (PERR_isSubjectSubject(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getSubjectWsAfterLocation(PERR_Subject arg) */

PERR_OptLayout PERR_getSubjectWsAfterLocation(PERR_Subject arg)
{
  
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/*}}}  */
/*{{{  PERR_Subject PERR_setSubjectWsAfterLocation(PERR_Subject arg, PERR_OptLayout wsAfterLocation) */

PERR_Subject PERR_setSubjectWsAfterLocation(PERR_Subject arg, PERR_OptLayout wsAfterLocation)
{
  if (PERR_isSubjectSubject(arg)) {
    return (PERR_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLocation), 9), 1);
  }

  ATabort("Subject has no WsAfterLocation: %t\n", arg);
  return (PERR_Subject)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PERR_Location accessors */

/*{{{  ATbool PERR_isValidLocation(PERR_Location arg) */

ATbool PERR_isValidLocation(PERR_Location arg)
{
  if (PERR_isLocationLocation(arg)) {
    return ATtrue;
  }
  else if (PERR_isLocationNoLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PERR_isLocationLocation(PERR_Location arg) */

inline ATbool PERR_isLocationLocation(PERR_Location arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PERR_patternLocationLocation, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PERR_isLocationNoLocation(PERR_Location arg) */

inline ATbool PERR_isLocationNoLocation(PERR_Location arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PERR_patternLocationNoLocation);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PERR_hasLocationWsAfterLocation(PERR_Location arg) */

ATbool PERR_hasLocationWsAfterLocation(PERR_Location arg)
{
  if (PERR_isLocationLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getLocationWsAfterLocation(PERR_Location arg) */

PERR_OptLayout PERR_getLocationWsAfterLocation(PERR_Location arg)
{
  
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PERR_Location PERR_setLocationWsAfterLocation(PERR_Location arg, PERR_OptLayout wsAfterLocation) */

PERR_Location PERR_setLocationWsAfterLocation(PERR_Location arg, PERR_OptLayout wsAfterLocation)
{
  if (PERR_isLocationLocation(arg)) {
    return (PERR_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLocation), 1), 1);
  }

  ATabort("Location has no WsAfterLocation: %t\n", arg);
  return (PERR_Location)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasLocationWsAfterParenOpen(PERR_Location arg) */

ATbool PERR_hasLocationWsAfterParenOpen(PERR_Location arg)
{
  if (PERR_isLocationLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getLocationWsAfterParenOpen(PERR_Location arg) */

PERR_OptLayout PERR_getLocationWsAfterParenOpen(PERR_Location arg)
{
  
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  PERR_Location PERR_setLocationWsAfterParenOpen(PERR_Location arg, PERR_OptLayout wsAfterParenOpen) */

PERR_Location PERR_setLocationWsAfterParenOpen(PERR_Location arg, PERR_OptLayout wsAfterParenOpen)
{
  if (PERR_isLocationLocation(arg)) {
    return (PERR_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("Location has no WsAfterParenOpen: %t\n", arg);
  return (PERR_Location)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasLocationFilename(PERR_Location arg) */

ATbool PERR_hasLocationFilename(PERR_Location arg)
{
  if (PERR_isLocationLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_StrCon PERR_getLocationFilename(PERR_Location arg) */

PERR_StrCon PERR_getLocationFilename(PERR_Location arg)
{
  
    return (PERR_StrCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PERR_Location PERR_setLocationFilename(PERR_Location arg, PERR_StrCon filename) */

PERR_Location PERR_setLocationFilename(PERR_Location arg, PERR_StrCon filename)
{
  if (PERR_isLocationLocation(arg)) {
    return (PERR_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) filename), 4), 1);
  }

  ATabort("Location has no Filename: %t\n", arg);
  return (PERR_Location)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasLocationWsAfterFilename(PERR_Location arg) */

ATbool PERR_hasLocationWsAfterFilename(PERR_Location arg)
{
  if (PERR_isLocationLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getLocationWsAfterFilename(PERR_Location arg) */

PERR_OptLayout PERR_getLocationWsAfterFilename(PERR_Location arg)
{
  
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PERR_Location PERR_setLocationWsAfterFilename(PERR_Location arg, PERR_OptLayout wsAfterFilename) */

PERR_Location PERR_setLocationWsAfterFilename(PERR_Location arg, PERR_OptLayout wsAfterFilename)
{
  if (PERR_isLocationLocation(arg)) {
    return (PERR_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterFilename), 5), 1);
  }

  ATabort("Location has no WsAfterFilename: %t\n", arg);
  return (PERR_Location)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasLocationWsAfterComma(PERR_Location arg) */

ATbool PERR_hasLocationWsAfterComma(PERR_Location arg)
{
  if (PERR_isLocationLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getLocationWsAfterComma(PERR_Location arg) */

PERR_OptLayout PERR_getLocationWsAfterComma(PERR_Location arg)
{
  
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  PERR_Location PERR_setLocationWsAfterComma(PERR_Location arg, PERR_OptLayout wsAfterComma) */

PERR_Location PERR_setLocationWsAfterComma(PERR_Location arg, PERR_OptLayout wsAfterComma)
{
  if (PERR_isLocationLocation(arg)) {
    return (PERR_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }

  ATabort("Location has no WsAfterComma: %t\n", arg);
  return (PERR_Location)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasLocationArea(PERR_Location arg) */

ATbool PERR_hasLocationArea(PERR_Location arg)
{
  if (PERR_isLocationLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_Area PERR_getLocationArea(PERR_Location arg) */

PERR_Area PERR_getLocationArea(PERR_Location arg)
{
  
    return (PERR_Area)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/*}}}  */
/*{{{  PERR_Location PERR_setLocationArea(PERR_Location arg, PERR_Area Area) */

PERR_Location PERR_setLocationArea(PERR_Location arg, PERR_Area Area)
{
  if (PERR_isLocationLocation(arg)) {
    return (PERR_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Area), 8), 1);
  }

  ATabort("Location has no Area: %t\n", arg);
  return (PERR_Location)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasLocationWsAfterArea(PERR_Location arg) */

ATbool PERR_hasLocationWsAfterArea(PERR_Location arg)
{
  if (PERR_isLocationLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getLocationWsAfterArea(PERR_Location arg) */

PERR_OptLayout PERR_getLocationWsAfterArea(PERR_Location arg)
{
  
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/*}}}  */
/*{{{  PERR_Location PERR_setLocationWsAfterArea(PERR_Location arg, PERR_OptLayout wsAfterArea) */

PERR_Location PERR_setLocationWsAfterArea(PERR_Location arg, PERR_OptLayout wsAfterArea)
{
  if (PERR_isLocationLocation(arg)) {
    return (PERR_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterArea), 9), 1);
  }

  ATabort("Location has no WsAfterArea: %t\n", arg);
  return (PERR_Location)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PERR_Area accessors */

/*{{{  ATbool PERR_isValidArea(PERR_Area arg) */

ATbool PERR_isValidArea(PERR_Area arg)
{
  if (PERR_isAreaArea(arg)) {
    return ATtrue;
  }
  else if (PERR_isAreaNoArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PERR_isAreaArea(PERR_Area arg) */

inline ATbool PERR_isAreaArea(PERR_Area arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PERR_patternAreaArea, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PERR_isAreaNoArea(PERR_Area arg) */

inline ATbool PERR_isAreaNoArea(PERR_Area arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PERR_patternAreaNoArea);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PERR_hasAreaWsAfterArea(PERR_Area arg) */

ATbool PERR_hasAreaWsAfterArea(PERR_Area arg)
{
  if (PERR_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getAreaWsAfterArea(PERR_Area arg) */

PERR_OptLayout PERR_getAreaWsAfterArea(PERR_Area arg)
{
  
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PERR_Area PERR_setAreaWsAfterArea(PERR_Area arg, PERR_OptLayout wsAfterArea) */

PERR_Area PERR_setAreaWsAfterArea(PERR_Area arg, PERR_OptLayout wsAfterArea)
{
  if (PERR_isAreaArea(arg)) {
    return (PERR_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterArea), 1), 1);
  }

  ATabort("Area has no WsAfterArea: %t\n", arg);
  return (PERR_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasAreaWsAfterParenOpen(PERR_Area arg) */

ATbool PERR_hasAreaWsAfterParenOpen(PERR_Area arg)
{
  if (PERR_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getAreaWsAfterParenOpen(PERR_Area arg) */

PERR_OptLayout PERR_getAreaWsAfterParenOpen(PERR_Area arg)
{
  
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  PERR_Area PERR_setAreaWsAfterParenOpen(PERR_Area arg, PERR_OptLayout wsAfterParenOpen) */

PERR_Area PERR_setAreaWsAfterParenOpen(PERR_Area arg, PERR_OptLayout wsAfterParenOpen)
{
  if (PERR_isAreaArea(arg)) {
    return (PERR_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("Area has no WsAfterParenOpen: %t\n", arg);
  return (PERR_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasAreaBeginLine(PERR_Area arg) */

ATbool PERR_hasAreaBeginLine(PERR_Area arg)
{
  if (PERR_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_NatCon PERR_getAreaBeginLine(PERR_Area arg) */

PERR_NatCon PERR_getAreaBeginLine(PERR_Area arg)
{
  
    return (PERR_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PERR_Area PERR_setAreaBeginLine(PERR_Area arg, PERR_NatCon beginLine) */

PERR_Area PERR_setAreaBeginLine(PERR_Area arg, PERR_NatCon beginLine)
{
  if (PERR_isAreaArea(arg)) {
    return (PERR_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) beginLine), 4), 1);
  }

  ATabort("Area has no BeginLine: %t\n", arg);
  return (PERR_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasAreaWsAfterBeginLine(PERR_Area arg) */

ATbool PERR_hasAreaWsAfterBeginLine(PERR_Area arg)
{
  if (PERR_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getAreaWsAfterBeginLine(PERR_Area arg) */

PERR_OptLayout PERR_getAreaWsAfterBeginLine(PERR_Area arg)
{
  
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PERR_Area PERR_setAreaWsAfterBeginLine(PERR_Area arg, PERR_OptLayout wsAfterBeginLine) */

PERR_Area PERR_setAreaWsAfterBeginLine(PERR_Area arg, PERR_OptLayout wsAfterBeginLine)
{
  if (PERR_isAreaArea(arg)) {
    return (PERR_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBeginLine), 5), 1);
  }

  ATabort("Area has no WsAfterBeginLine: %t\n", arg);
  return (PERR_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasAreaWsAfterComma(PERR_Area arg) */

ATbool PERR_hasAreaWsAfterComma(PERR_Area arg)
{
  if (PERR_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getAreaWsAfterComma(PERR_Area arg) */

PERR_OptLayout PERR_getAreaWsAfterComma(PERR_Area arg)
{
  
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  PERR_Area PERR_setAreaWsAfterComma(PERR_Area arg, PERR_OptLayout wsAfterComma) */

PERR_Area PERR_setAreaWsAfterComma(PERR_Area arg, PERR_OptLayout wsAfterComma)
{
  if (PERR_isAreaArea(arg)) {
    return (PERR_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }

  ATabort("Area has no WsAfterComma: %t\n", arg);
  return (PERR_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasAreaBeginColumn(PERR_Area arg) */

ATbool PERR_hasAreaBeginColumn(PERR_Area arg)
{
  if (PERR_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_NatCon PERR_getAreaBeginColumn(PERR_Area arg) */

PERR_NatCon PERR_getAreaBeginColumn(PERR_Area arg)
{
  
    return (PERR_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/*}}}  */
/*{{{  PERR_Area PERR_setAreaBeginColumn(PERR_Area arg, PERR_NatCon beginColumn) */

PERR_Area PERR_setAreaBeginColumn(PERR_Area arg, PERR_NatCon beginColumn)
{
  if (PERR_isAreaArea(arg)) {
    return (PERR_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) beginColumn), 8), 1);
  }

  ATabort("Area has no BeginColumn: %t\n", arg);
  return (PERR_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasAreaWsAfterBeginColumn(PERR_Area arg) */

ATbool PERR_hasAreaWsAfterBeginColumn(PERR_Area arg)
{
  if (PERR_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getAreaWsAfterBeginColumn(PERR_Area arg) */

PERR_OptLayout PERR_getAreaWsAfterBeginColumn(PERR_Area arg)
{
  
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/*}}}  */
/*{{{  PERR_Area PERR_setAreaWsAfterBeginColumn(PERR_Area arg, PERR_OptLayout wsAfterBeginColumn) */

PERR_Area PERR_setAreaWsAfterBeginColumn(PERR_Area arg, PERR_OptLayout wsAfterBeginColumn)
{
  if (PERR_isAreaArea(arg)) {
    return (PERR_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBeginColumn), 9), 1);
  }

  ATabort("Area has no WsAfterBeginColumn: %t\n", arg);
  return (PERR_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasAreaWsAfterComma1(PERR_Area arg) */

ATbool PERR_hasAreaWsAfterComma1(PERR_Area arg)
{
  if (PERR_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getAreaWsAfterComma1(PERR_Area arg) */

PERR_OptLayout PERR_getAreaWsAfterComma1(PERR_Area arg)
{
  
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 11);
}

/*}}}  */
/*{{{  PERR_Area PERR_setAreaWsAfterComma1(PERR_Area arg, PERR_OptLayout wsAfterComma1) */

PERR_Area PERR_setAreaWsAfterComma1(PERR_Area arg, PERR_OptLayout wsAfterComma1)
{
  if (PERR_isAreaArea(arg)) {
    return (PERR_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma1), 11), 1);
  }

  ATabort("Area has no WsAfterComma1: %t\n", arg);
  return (PERR_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasAreaEndLine(PERR_Area arg) */

ATbool PERR_hasAreaEndLine(PERR_Area arg)
{
  if (PERR_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_NatCon PERR_getAreaEndLine(PERR_Area arg) */

PERR_NatCon PERR_getAreaEndLine(PERR_Area arg)
{
  
    return (PERR_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 12);
}

/*}}}  */
/*{{{  PERR_Area PERR_setAreaEndLine(PERR_Area arg, PERR_NatCon endLine) */

PERR_Area PERR_setAreaEndLine(PERR_Area arg, PERR_NatCon endLine)
{
  if (PERR_isAreaArea(arg)) {
    return (PERR_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) endLine), 12), 1);
  }

  ATabort("Area has no EndLine: %t\n", arg);
  return (PERR_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasAreaWsAfterEndLine(PERR_Area arg) */

ATbool PERR_hasAreaWsAfterEndLine(PERR_Area arg)
{
  if (PERR_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getAreaWsAfterEndLine(PERR_Area arg) */

PERR_OptLayout PERR_getAreaWsAfterEndLine(PERR_Area arg)
{
  
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 13);
}

/*}}}  */
/*{{{  PERR_Area PERR_setAreaWsAfterEndLine(PERR_Area arg, PERR_OptLayout wsAfterEndLine) */

PERR_Area PERR_setAreaWsAfterEndLine(PERR_Area arg, PERR_OptLayout wsAfterEndLine)
{
  if (PERR_isAreaArea(arg)) {
    return (PERR_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterEndLine), 13), 1);
  }

  ATabort("Area has no WsAfterEndLine: %t\n", arg);
  return (PERR_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasAreaWsAfterComma2(PERR_Area arg) */

ATbool PERR_hasAreaWsAfterComma2(PERR_Area arg)
{
  if (PERR_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getAreaWsAfterComma2(PERR_Area arg) */

PERR_OptLayout PERR_getAreaWsAfterComma2(PERR_Area arg)
{
  
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 15);
}

/*}}}  */
/*{{{  PERR_Area PERR_setAreaWsAfterComma2(PERR_Area arg, PERR_OptLayout wsAfterComma2) */

PERR_Area PERR_setAreaWsAfterComma2(PERR_Area arg, PERR_OptLayout wsAfterComma2)
{
  if (PERR_isAreaArea(arg)) {
    return (PERR_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma2), 15), 1);
  }

  ATabort("Area has no WsAfterComma2: %t\n", arg);
  return (PERR_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasAreaEndColumn(PERR_Area arg) */

ATbool PERR_hasAreaEndColumn(PERR_Area arg)
{
  if (PERR_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_NatCon PERR_getAreaEndColumn(PERR_Area arg) */

PERR_NatCon PERR_getAreaEndColumn(PERR_Area arg)
{
  
    return (PERR_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 16);
}

/*}}}  */
/*{{{  PERR_Area PERR_setAreaEndColumn(PERR_Area arg, PERR_NatCon endColumn) */

PERR_Area PERR_setAreaEndColumn(PERR_Area arg, PERR_NatCon endColumn)
{
  if (PERR_isAreaArea(arg)) {
    return (PERR_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) endColumn), 16), 1);
  }

  ATabort("Area has no EndColumn: %t\n", arg);
  return (PERR_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasAreaWsAfterEndColumn(PERR_Area arg) */

ATbool PERR_hasAreaWsAfterEndColumn(PERR_Area arg)
{
  if (PERR_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getAreaWsAfterEndColumn(PERR_Area arg) */

PERR_OptLayout PERR_getAreaWsAfterEndColumn(PERR_Area arg)
{
  
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 17);
}

/*}}}  */
/*{{{  PERR_Area PERR_setAreaWsAfterEndColumn(PERR_Area arg, PERR_OptLayout wsAfterEndColumn) */

PERR_Area PERR_setAreaWsAfterEndColumn(PERR_Area arg, PERR_OptLayout wsAfterEndColumn)
{
  if (PERR_isAreaArea(arg)) {
    return (PERR_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterEndColumn), 17), 1);
  }

  ATabort("Area has no WsAfterEndColumn: %t\n", arg);
  return (PERR_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasAreaWsAfterComma3(PERR_Area arg) */

ATbool PERR_hasAreaWsAfterComma3(PERR_Area arg)
{
  if (PERR_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getAreaWsAfterComma3(PERR_Area arg) */

PERR_OptLayout PERR_getAreaWsAfterComma3(PERR_Area arg)
{
  
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 19);
}

/*}}}  */
/*{{{  PERR_Area PERR_setAreaWsAfterComma3(PERR_Area arg, PERR_OptLayout wsAfterComma3) */

PERR_Area PERR_setAreaWsAfterComma3(PERR_Area arg, PERR_OptLayout wsAfterComma3)
{
  if (PERR_isAreaArea(arg)) {
    return (PERR_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma3), 19), 1);
  }

  ATabort("Area has no WsAfterComma3: %t\n", arg);
  return (PERR_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasAreaBeginOffset(PERR_Area arg) */

ATbool PERR_hasAreaBeginOffset(PERR_Area arg)
{
  if (PERR_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_NatCon PERR_getAreaBeginOffset(PERR_Area arg) */

PERR_NatCon PERR_getAreaBeginOffset(PERR_Area arg)
{
  
    return (PERR_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 20);
}

/*}}}  */
/*{{{  PERR_Area PERR_setAreaBeginOffset(PERR_Area arg, PERR_NatCon beginOffset) */

PERR_Area PERR_setAreaBeginOffset(PERR_Area arg, PERR_NatCon beginOffset)
{
  if (PERR_isAreaArea(arg)) {
    return (PERR_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) beginOffset), 20), 1);
  }

  ATabort("Area has no BeginOffset: %t\n", arg);
  return (PERR_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasAreaWsAfterBeginOffset(PERR_Area arg) */

ATbool PERR_hasAreaWsAfterBeginOffset(PERR_Area arg)
{
  if (PERR_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getAreaWsAfterBeginOffset(PERR_Area arg) */

PERR_OptLayout PERR_getAreaWsAfterBeginOffset(PERR_Area arg)
{
  
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 21);
}

/*}}}  */
/*{{{  PERR_Area PERR_setAreaWsAfterBeginOffset(PERR_Area arg, PERR_OptLayout wsAfterBeginOffset) */

PERR_Area PERR_setAreaWsAfterBeginOffset(PERR_Area arg, PERR_OptLayout wsAfterBeginOffset)
{
  if (PERR_isAreaArea(arg)) {
    return (PERR_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBeginOffset), 21), 1);
  }

  ATabort("Area has no WsAfterBeginOffset: %t\n", arg);
  return (PERR_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasAreaWsAfterComma4(PERR_Area arg) */

ATbool PERR_hasAreaWsAfterComma4(PERR_Area arg)
{
  if (PERR_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getAreaWsAfterComma4(PERR_Area arg) */

PERR_OptLayout PERR_getAreaWsAfterComma4(PERR_Area arg)
{
  
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 23);
}

/*}}}  */
/*{{{  PERR_Area PERR_setAreaWsAfterComma4(PERR_Area arg, PERR_OptLayout wsAfterComma4) */

PERR_Area PERR_setAreaWsAfterComma4(PERR_Area arg, PERR_OptLayout wsAfterComma4)
{
  if (PERR_isAreaArea(arg)) {
    return (PERR_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma4), 23), 1);
  }

  ATabort("Area has no WsAfterComma4: %t\n", arg);
  return (PERR_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasAreaEndOffset(PERR_Area arg) */

ATbool PERR_hasAreaEndOffset(PERR_Area arg)
{
  if (PERR_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_NatCon PERR_getAreaEndOffset(PERR_Area arg) */

PERR_NatCon PERR_getAreaEndOffset(PERR_Area arg)
{
  
    return (PERR_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 24);
}

/*}}}  */
/*{{{  PERR_Area PERR_setAreaEndOffset(PERR_Area arg, PERR_NatCon endOffset) */

PERR_Area PERR_setAreaEndOffset(PERR_Area arg, PERR_NatCon endOffset)
{
  if (PERR_isAreaArea(arg)) {
    return (PERR_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) endOffset), 24), 1);
  }

  ATabort("Area has no EndOffset: %t\n", arg);
  return (PERR_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasAreaWsAfterEndOffset(PERR_Area arg) */

ATbool PERR_hasAreaWsAfterEndOffset(PERR_Area arg)
{
  if (PERR_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getAreaWsAfterEndOffset(PERR_Area arg) */

PERR_OptLayout PERR_getAreaWsAfterEndOffset(PERR_Area arg)
{
  
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 25);
}

/*}}}  */
/*{{{  PERR_Area PERR_setAreaWsAfterEndOffset(PERR_Area arg, PERR_OptLayout wsAfterEndOffset) */

PERR_Area PERR_setAreaWsAfterEndOffset(PERR_Area arg, PERR_OptLayout wsAfterEndOffset)
{
  if (PERR_isAreaArea(arg)) {
    return (PERR_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterEndOffset), 25), 1);
  }

  ATabort("Area has no WsAfterEndOffset: %t\n", arg);
  return (PERR_Area)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PERR_NatCon accessors */

/*{{{  ATbool PERR_isValidNatCon(PERR_NatCon arg) */

ATbool PERR_isValidNatCon(PERR_NatCon arg)
{
  if (PERR_isNatConString(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PERR_isNatConString(PERR_NatCon arg) */

inline ATbool PERR_isNatConString(PERR_NatCon arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PERR_patternNatConString, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PERR_hasNatConString(PERR_NatCon arg) */

ATbool PERR_hasNatConString(PERR_NatCon arg)
{
  if (PERR_isNatConString(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* PERR_getNatConString(PERR_NatCon arg) */

char* PERR_getNatConString(PERR_NatCon arg)
{
  
    return (char*)PERR_charsToString((ATerm)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1));
}

/*}}}  */
/*{{{  PERR_NatCon PERR_setNatConString(PERR_NatCon arg, char* string) */

PERR_NatCon PERR_setNatConString(PERR_NatCon arg, char* string)
{
  if (PERR_isNatConString(arg)) {
    return (PERR_NatCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) ((ATerm) PERR_stringToChars(string))), 1), 0), 1);
  }

  ATabort("NatCon has no String: %t\n", arg);
  return (PERR_NatCon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PERR_StrCon accessors */

/*{{{  ATbool PERR_isValidStrCon(PERR_StrCon arg) */

ATbool PERR_isValidStrCon(PERR_StrCon arg)
{
  if (PERR_isStrConString(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PERR_isStrConString(PERR_StrCon arg) */

inline ATbool PERR_isStrConString(PERR_StrCon arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PERR_patternStrConString, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PERR_hasStrConString(PERR_StrCon arg) */

ATbool PERR_hasStrConString(PERR_StrCon arg)
{
  if (PERR_isStrConString(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* PERR_getStrConString(PERR_StrCon arg) */

char* PERR_getStrConString(PERR_StrCon arg)
{
  
    return (char*)PERR_charsToString((ATerm)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1));
}

/*}}}  */
/*{{{  PERR_StrCon PERR_setStrConString(PERR_StrCon arg, char* string) */

PERR_StrCon PERR_setStrConString(PERR_StrCon arg, char* string)
{
  if (PERR_isStrConString(arg)) {
    return (PERR_StrCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) ((ATerm) PERR_stringToChars(string))), 1), 0), 1);
  }

  ATabort("StrCon has no String: %t\n", arg);
  return (PERR_StrCon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PERR_OptLayout accessors */

/*{{{  ATbool PERR_isValidOptLayout(PERR_OptLayout arg) */

ATbool PERR_isValidOptLayout(PERR_OptLayout arg)
{
  if (PERR_isOptLayoutAbsent(arg)) {
    return ATtrue;
  }
  else if (PERR_isOptLayoutPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PERR_isOptLayoutAbsent(PERR_OptLayout arg) */

inline ATbool PERR_isOptLayoutAbsent(PERR_OptLayout arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PERR_patternOptLayoutAbsent);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PERR_isOptLayoutPresent(PERR_OptLayout arg) */

inline ATbool PERR_isOptLayoutPresent(PERR_OptLayout arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PERR_patternOptLayoutPresent, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PERR_hasOptLayoutString(PERR_OptLayout arg) */

ATbool PERR_hasOptLayoutString(PERR_OptLayout arg)
{
  if (PERR_isOptLayoutPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* PERR_getOptLayoutString(PERR_OptLayout arg) */

char* PERR_getOptLayoutString(PERR_OptLayout arg)
{
  
    return (char*)PERR_charsToString((ATerm)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_setOptLayoutString(PERR_OptLayout arg, char* string) */

PERR_OptLayout PERR_setOptLayoutString(PERR_OptLayout arg, char* string)
{
  if (PERR_isOptLayoutPresent(arg)) {
    return (PERR_OptLayout)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) ((ATerm) PERR_stringToChars(string))), 1);
  }

  ATabort("OptLayout has no String: %t\n", arg);
  return (PERR_OptLayout)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PERR_Start accessors */

/*{{{  ATbool PERR_isValidStart(PERR_Start arg) */

ATbool PERR_isValidStart(PERR_Start arg)
{
  if (PERR_isStartArea(arg)) {
    return ATtrue;
  }
  else if (PERR_isStartLocation(arg)) {
    return ATtrue;
  }
  else if (PERR_isStartSubject(arg)) {
    return ATtrue;
  }
  else if (PERR_isStartFeedback(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PERR_isStartArea(PERR_Start arg) */

inline ATbool PERR_isStartArea(PERR_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PERR_patternStartArea, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PERR_isStartLocation(PERR_Start arg) */

inline ATbool PERR_isStartLocation(PERR_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PERR_patternStartLocation, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PERR_isStartSubject(PERR_Start arg) */

inline ATbool PERR_isStartSubject(PERR_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PERR_patternStartSubject, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PERR_isStartFeedback(PERR_Start arg) */

inline ATbool PERR_isStartFeedback(PERR_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PERR_patternStartFeedback, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PERR_hasStartWsBefore(PERR_Start arg) */

ATbool PERR_hasStartWsBefore(PERR_Start arg)
{
  if (PERR_isStartArea(arg)) {
    return ATtrue;
  }
  else if (PERR_isStartLocation(arg)) {
    return ATtrue;
  }
  else if (PERR_isStartSubject(arg)) {
    return ATtrue;
  }
  else if (PERR_isStartFeedback(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getStartWsBefore(PERR_Start arg) */

PERR_OptLayout PERR_getStartWsBefore(PERR_Start arg)
{
  if (PERR_isStartArea(arg)) {
    return (PERR_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (PERR_isStartLocation(arg)) {
    return (PERR_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (PERR_isStartSubject(arg)) {
    return (PERR_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else 
    return (PERR_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
}

/*}}}  */
/*{{{  PERR_Start PERR_setStartWsBefore(PERR_Start arg, PERR_OptLayout wsBefore) */

PERR_Start PERR_setStartWsBefore(PERR_Start arg, PERR_OptLayout wsBefore)
{
  if (PERR_isStartArea(arg)) {
    return (PERR_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (PERR_isStartLocation(arg)) {
    return (PERR_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (PERR_isStartSubject(arg)) {
    return (PERR_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (PERR_isStartFeedback(arg)) {
    return (PERR_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }

  ATabort("Start has no WsBefore: %t\n", arg);
  return (PERR_Start)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasStartTopArea(PERR_Start arg) */

ATbool PERR_hasStartTopArea(PERR_Start arg)
{
  if (PERR_isStartArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_Area PERR_getStartTopArea(PERR_Start arg) */

PERR_Area PERR_getStartTopArea(PERR_Start arg)
{
  
    return (PERR_Area)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  PERR_Start PERR_setStartTopArea(PERR_Start arg, PERR_Area topArea) */

PERR_Start PERR_setStartTopArea(PERR_Start arg, PERR_Area topArea)
{
  if (PERR_isStartArea(arg)) {
    return (PERR_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topArea), 1), 1), 0);
  }

  ATabort("Start has no TopArea: %t\n", arg);
  return (PERR_Start)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasStartWsAfter(PERR_Start arg) */

ATbool PERR_hasStartWsAfter(PERR_Start arg)
{
  if (PERR_isStartArea(arg)) {
    return ATtrue;
  }
  else if (PERR_isStartLocation(arg)) {
    return ATtrue;
  }
  else if (PERR_isStartSubject(arg)) {
    return ATtrue;
  }
  else if (PERR_isStartFeedback(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_getStartWsAfter(PERR_Start arg) */

PERR_OptLayout PERR_getStartWsAfter(PERR_Start arg)
{
  if (PERR_isStartArea(arg)) {
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (PERR_isStartLocation(arg)) {
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (PERR_isStartSubject(arg)) {
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else 
    return (PERR_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
}

/*}}}  */
/*{{{  PERR_Start PERR_setStartWsAfter(PERR_Start arg, PERR_OptLayout wsAfter) */

PERR_Start PERR_setStartWsAfter(PERR_Start arg, PERR_OptLayout wsAfter)
{
  if (PERR_isStartArea(arg)) {
    return (PERR_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (PERR_isStartLocation(arg)) {
    return (PERR_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (PERR_isStartSubject(arg)) {
    return (PERR_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (PERR_isStartFeedback(arg)) {
    return (PERR_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }

  ATabort("Start has no WsAfter: %t\n", arg);
  return (PERR_Start)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasStartAmbCnt(PERR_Start arg) */

ATbool PERR_hasStartAmbCnt(PERR_Start arg)
{
  if (PERR_isStartArea(arg)) {
    return ATtrue;
  }
  else if (PERR_isStartLocation(arg)) {
    return ATtrue;
  }
  else if (PERR_isStartSubject(arg)) {
    return ATtrue;
  }
  else if (PERR_isStartFeedback(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int PERR_getStartAmbCnt(PERR_Start arg) */

int PERR_getStartAmbCnt(PERR_Start arg)
{
  if (PERR_isStartArea(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else if (PERR_isStartLocation(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else if (PERR_isStartSubject(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  PERR_Start PERR_setStartAmbCnt(PERR_Start arg, int ambCnt) */

PERR_Start PERR_setStartAmbCnt(PERR_Start arg, int ambCnt)
{
  if (PERR_isStartArea(arg)) {
    return (PERR_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (PERR_isStartLocation(arg)) {
    return (PERR_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (PERR_isStartSubject(arg)) {
    return (PERR_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (PERR_isStartFeedback(arg)) {
    return (PERR_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }

  ATabort("Start has no AmbCnt: %t\n", arg);
  return (PERR_Start)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasStartTopLocation(PERR_Start arg) */

ATbool PERR_hasStartTopLocation(PERR_Start arg)
{
  if (PERR_isStartLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_Location PERR_getStartTopLocation(PERR_Start arg) */

PERR_Location PERR_getStartTopLocation(PERR_Start arg)
{
  
    return (PERR_Location)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  PERR_Start PERR_setStartTopLocation(PERR_Start arg, PERR_Location topLocation) */

PERR_Start PERR_setStartTopLocation(PERR_Start arg, PERR_Location topLocation)
{
  if (PERR_isStartLocation(arg)) {
    return (PERR_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topLocation), 1), 1), 0);
  }

  ATabort("Start has no TopLocation: %t\n", arg);
  return (PERR_Start)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasStartTopSubject(PERR_Start arg) */

ATbool PERR_hasStartTopSubject(PERR_Start arg)
{
  if (PERR_isStartSubject(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_Subject PERR_getStartTopSubject(PERR_Start arg) */

PERR_Subject PERR_getStartTopSubject(PERR_Start arg)
{
  
    return (PERR_Subject)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  PERR_Start PERR_setStartTopSubject(PERR_Start arg, PERR_Subject topSubject) */

PERR_Start PERR_setStartTopSubject(PERR_Start arg, PERR_Subject topSubject)
{
  if (PERR_isStartSubject(arg)) {
    return (PERR_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topSubject), 1), 1), 0);
  }

  ATabort("Start has no TopSubject: %t\n", arg);
  return (PERR_Start)NULL;
}

/*}}}  */
/*{{{  ATbool PERR_hasStartTopFeedback(PERR_Start arg) */

ATbool PERR_hasStartTopFeedback(PERR_Start arg)
{
  if (PERR_isStartFeedback(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PERR_Feedback PERR_getStartTopFeedback(PERR_Start arg) */

PERR_Feedback PERR_getStartTopFeedback(PERR_Start arg)
{
  
    return (PERR_Feedback)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  PERR_Start PERR_setStartTopFeedback(PERR_Start arg, PERR_Feedback topFeedback) */

PERR_Start PERR_setStartTopFeedback(PERR_Start arg, PERR_Feedback topFeedback)
{
  if (PERR_isStartFeedback(arg)) {
    return (PERR_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topFeedback), 1), 1), 0);
  }

  ATabort("Start has no TopFeedback: %t\n", arg);
  return (PERR_Start)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  PERR_Feedback PERR_visitFeedback(PERR_Feedback arg, PERR_OptLayout (*acceptWsAfterInfo)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterParenOpen)(PERR_OptLayout), PERR_StrCon (*acceptId)(PERR_StrCon), PERR_OptLayout (*acceptWsAfterId)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterComma)(PERR_OptLayout), PERR_StrCon (*acceptProducerId)(PERR_StrCon), PERR_OptLayout (*acceptWsAfterProducerId)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterComma1)(PERR_OptLayout), PERR_StrCon (*acceptProducerType)(PERR_StrCon), PERR_OptLayout (*acceptWsAfterProducerType)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterComma2)(PERR_OptLayout), PERR_StrCon (*acceptDescription)(PERR_StrCon), PERR_OptLayout (*acceptWsAfterDescription)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterComma3)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterBracketOpen)(PERR_OptLayout), PERR_SubjectList (*acceptList)(PERR_SubjectList), PERR_OptLayout (*acceptWsAfterList)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterBracketClose)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterWarning)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterError)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterFatalError)(PERR_OptLayout)) */

PERR_Feedback PERR_visitFeedback(PERR_Feedback arg, PERR_OptLayout (*acceptWsAfterInfo)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterParenOpen)(PERR_OptLayout), PERR_StrCon (*acceptId)(PERR_StrCon), PERR_OptLayout (*acceptWsAfterId)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterComma)(PERR_OptLayout), PERR_StrCon (*acceptProducerId)(PERR_StrCon), PERR_OptLayout (*acceptWsAfterProducerId)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterComma1)(PERR_OptLayout), PERR_StrCon (*acceptProducerType)(PERR_StrCon), PERR_OptLayout (*acceptWsAfterProducerType)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterComma2)(PERR_OptLayout), PERR_StrCon (*acceptDescription)(PERR_StrCon), PERR_OptLayout (*acceptWsAfterDescription)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterComma3)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterBracketOpen)(PERR_OptLayout), PERR_SubjectList (*acceptList)(PERR_SubjectList), PERR_OptLayout (*acceptWsAfterList)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterBracketClose)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterWarning)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterError)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterFatalError)(PERR_OptLayout))
{
  if (PERR_isFeedbackInfo(arg)) {
    return PERR_makeFeedbackInfo(
        acceptWsAfterInfo ? acceptWsAfterInfo(PERR_getFeedbackWsAfterInfo(arg)) : PERR_getFeedbackWsAfterInfo(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PERR_getFeedbackWsAfterParenOpen(arg)) : PERR_getFeedbackWsAfterParenOpen(arg),
        acceptId ? acceptId(PERR_getFeedbackId(arg)) : PERR_getFeedbackId(arg),
        acceptWsAfterId ? acceptWsAfterId(PERR_getFeedbackWsAfterId(arg)) : PERR_getFeedbackWsAfterId(arg),
        acceptWsAfterComma ? acceptWsAfterComma(PERR_getFeedbackWsAfterComma(arg)) : PERR_getFeedbackWsAfterComma(arg),
        acceptProducerId ? acceptProducerId(PERR_getFeedbackProducerId(arg)) : PERR_getFeedbackProducerId(arg),
        acceptWsAfterProducerId ? acceptWsAfterProducerId(PERR_getFeedbackWsAfterProducerId(arg)) : PERR_getFeedbackWsAfterProducerId(arg),
        acceptWsAfterComma1 ? acceptWsAfterComma1(PERR_getFeedbackWsAfterComma1(arg)) : PERR_getFeedbackWsAfterComma1(arg),
        acceptProducerType ? acceptProducerType(PERR_getFeedbackProducerType(arg)) : PERR_getFeedbackProducerType(arg),
        acceptWsAfterProducerType ? acceptWsAfterProducerType(PERR_getFeedbackWsAfterProducerType(arg)) : PERR_getFeedbackWsAfterProducerType(arg),
        acceptWsAfterComma2 ? acceptWsAfterComma2(PERR_getFeedbackWsAfterComma2(arg)) : PERR_getFeedbackWsAfterComma2(arg),
        acceptDescription ? acceptDescription(PERR_getFeedbackDescription(arg)) : PERR_getFeedbackDescription(arg),
        acceptWsAfterDescription ? acceptWsAfterDescription(PERR_getFeedbackWsAfterDescription(arg)) : PERR_getFeedbackWsAfterDescription(arg),
        acceptWsAfterComma3 ? acceptWsAfterComma3(PERR_getFeedbackWsAfterComma3(arg)) : PERR_getFeedbackWsAfterComma3(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(PERR_getFeedbackWsAfterBracketOpen(arg)) : PERR_getFeedbackWsAfterBracketOpen(arg),
        acceptList ? acceptList(PERR_getFeedbackList(arg)) : PERR_getFeedbackList(arg),
        acceptWsAfterList ? acceptWsAfterList(PERR_getFeedbackWsAfterList(arg)) : PERR_getFeedbackWsAfterList(arg),
        acceptWsAfterBracketClose ? acceptWsAfterBracketClose(PERR_getFeedbackWsAfterBracketClose(arg)) : PERR_getFeedbackWsAfterBracketClose(arg));
  }
  if (PERR_isFeedbackWarning(arg)) {
    return PERR_makeFeedbackWarning(
        acceptWsAfterWarning ? acceptWsAfterWarning(PERR_getFeedbackWsAfterWarning(arg)) : PERR_getFeedbackWsAfterWarning(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PERR_getFeedbackWsAfterParenOpen(arg)) : PERR_getFeedbackWsAfterParenOpen(arg),
        acceptId ? acceptId(PERR_getFeedbackId(arg)) : PERR_getFeedbackId(arg),
        acceptWsAfterId ? acceptWsAfterId(PERR_getFeedbackWsAfterId(arg)) : PERR_getFeedbackWsAfterId(arg),
        acceptWsAfterComma ? acceptWsAfterComma(PERR_getFeedbackWsAfterComma(arg)) : PERR_getFeedbackWsAfterComma(arg),
        acceptProducerId ? acceptProducerId(PERR_getFeedbackProducerId(arg)) : PERR_getFeedbackProducerId(arg),
        acceptWsAfterProducerId ? acceptWsAfterProducerId(PERR_getFeedbackWsAfterProducerId(arg)) : PERR_getFeedbackWsAfterProducerId(arg),
        acceptWsAfterComma1 ? acceptWsAfterComma1(PERR_getFeedbackWsAfterComma1(arg)) : PERR_getFeedbackWsAfterComma1(arg),
        acceptProducerType ? acceptProducerType(PERR_getFeedbackProducerType(arg)) : PERR_getFeedbackProducerType(arg),
        acceptWsAfterProducerType ? acceptWsAfterProducerType(PERR_getFeedbackWsAfterProducerType(arg)) : PERR_getFeedbackWsAfterProducerType(arg),
        acceptWsAfterComma2 ? acceptWsAfterComma2(PERR_getFeedbackWsAfterComma2(arg)) : PERR_getFeedbackWsAfterComma2(arg),
        acceptDescription ? acceptDescription(PERR_getFeedbackDescription(arg)) : PERR_getFeedbackDescription(arg),
        acceptWsAfterDescription ? acceptWsAfterDescription(PERR_getFeedbackWsAfterDescription(arg)) : PERR_getFeedbackWsAfterDescription(arg),
        acceptWsAfterComma3 ? acceptWsAfterComma3(PERR_getFeedbackWsAfterComma3(arg)) : PERR_getFeedbackWsAfterComma3(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(PERR_getFeedbackWsAfterBracketOpen(arg)) : PERR_getFeedbackWsAfterBracketOpen(arg),
        acceptList ? acceptList(PERR_getFeedbackList(arg)) : PERR_getFeedbackList(arg),
        acceptWsAfterList ? acceptWsAfterList(PERR_getFeedbackWsAfterList(arg)) : PERR_getFeedbackWsAfterList(arg),
        acceptWsAfterBracketClose ? acceptWsAfterBracketClose(PERR_getFeedbackWsAfterBracketClose(arg)) : PERR_getFeedbackWsAfterBracketClose(arg));
  }
  if (PERR_isFeedbackError(arg)) {
    return PERR_makeFeedbackError(
        acceptWsAfterError ? acceptWsAfterError(PERR_getFeedbackWsAfterError(arg)) : PERR_getFeedbackWsAfterError(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PERR_getFeedbackWsAfterParenOpen(arg)) : PERR_getFeedbackWsAfterParenOpen(arg),
        acceptId ? acceptId(PERR_getFeedbackId(arg)) : PERR_getFeedbackId(arg),
        acceptWsAfterId ? acceptWsAfterId(PERR_getFeedbackWsAfterId(arg)) : PERR_getFeedbackWsAfterId(arg),
        acceptWsAfterComma ? acceptWsAfterComma(PERR_getFeedbackWsAfterComma(arg)) : PERR_getFeedbackWsAfterComma(arg),
        acceptProducerId ? acceptProducerId(PERR_getFeedbackProducerId(arg)) : PERR_getFeedbackProducerId(arg),
        acceptWsAfterProducerId ? acceptWsAfterProducerId(PERR_getFeedbackWsAfterProducerId(arg)) : PERR_getFeedbackWsAfterProducerId(arg),
        acceptWsAfterComma1 ? acceptWsAfterComma1(PERR_getFeedbackWsAfterComma1(arg)) : PERR_getFeedbackWsAfterComma1(arg),
        acceptProducerType ? acceptProducerType(PERR_getFeedbackProducerType(arg)) : PERR_getFeedbackProducerType(arg),
        acceptWsAfterProducerType ? acceptWsAfterProducerType(PERR_getFeedbackWsAfterProducerType(arg)) : PERR_getFeedbackWsAfterProducerType(arg),
        acceptWsAfterComma2 ? acceptWsAfterComma2(PERR_getFeedbackWsAfterComma2(arg)) : PERR_getFeedbackWsAfterComma2(arg),
        acceptDescription ? acceptDescription(PERR_getFeedbackDescription(arg)) : PERR_getFeedbackDescription(arg),
        acceptWsAfterDescription ? acceptWsAfterDescription(PERR_getFeedbackWsAfterDescription(arg)) : PERR_getFeedbackWsAfterDescription(arg),
        acceptWsAfterComma3 ? acceptWsAfterComma3(PERR_getFeedbackWsAfterComma3(arg)) : PERR_getFeedbackWsAfterComma3(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(PERR_getFeedbackWsAfterBracketOpen(arg)) : PERR_getFeedbackWsAfterBracketOpen(arg),
        acceptList ? acceptList(PERR_getFeedbackList(arg)) : PERR_getFeedbackList(arg),
        acceptWsAfterList ? acceptWsAfterList(PERR_getFeedbackWsAfterList(arg)) : PERR_getFeedbackWsAfterList(arg),
        acceptWsAfterBracketClose ? acceptWsAfterBracketClose(PERR_getFeedbackWsAfterBracketClose(arg)) : PERR_getFeedbackWsAfterBracketClose(arg));
  }
  if (PERR_isFeedbackFatalError(arg)) {
    return PERR_makeFeedbackFatalError(
        acceptWsAfterFatalError ? acceptWsAfterFatalError(PERR_getFeedbackWsAfterFatalError(arg)) : PERR_getFeedbackWsAfterFatalError(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PERR_getFeedbackWsAfterParenOpen(arg)) : PERR_getFeedbackWsAfterParenOpen(arg),
        acceptId ? acceptId(PERR_getFeedbackId(arg)) : PERR_getFeedbackId(arg),
        acceptWsAfterId ? acceptWsAfterId(PERR_getFeedbackWsAfterId(arg)) : PERR_getFeedbackWsAfterId(arg),
        acceptWsAfterComma ? acceptWsAfterComma(PERR_getFeedbackWsAfterComma(arg)) : PERR_getFeedbackWsAfterComma(arg),
        acceptProducerId ? acceptProducerId(PERR_getFeedbackProducerId(arg)) : PERR_getFeedbackProducerId(arg),
        acceptWsAfterProducerId ? acceptWsAfterProducerId(PERR_getFeedbackWsAfterProducerId(arg)) : PERR_getFeedbackWsAfterProducerId(arg),
        acceptWsAfterComma1 ? acceptWsAfterComma1(PERR_getFeedbackWsAfterComma1(arg)) : PERR_getFeedbackWsAfterComma1(arg),
        acceptProducerType ? acceptProducerType(PERR_getFeedbackProducerType(arg)) : PERR_getFeedbackProducerType(arg),
        acceptWsAfterProducerType ? acceptWsAfterProducerType(PERR_getFeedbackWsAfterProducerType(arg)) : PERR_getFeedbackWsAfterProducerType(arg),
        acceptWsAfterComma2 ? acceptWsAfterComma2(PERR_getFeedbackWsAfterComma2(arg)) : PERR_getFeedbackWsAfterComma2(arg),
        acceptDescription ? acceptDescription(PERR_getFeedbackDescription(arg)) : PERR_getFeedbackDescription(arg),
        acceptWsAfterDescription ? acceptWsAfterDescription(PERR_getFeedbackWsAfterDescription(arg)) : PERR_getFeedbackWsAfterDescription(arg),
        acceptWsAfterComma3 ? acceptWsAfterComma3(PERR_getFeedbackWsAfterComma3(arg)) : PERR_getFeedbackWsAfterComma3(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(PERR_getFeedbackWsAfterBracketOpen(arg)) : PERR_getFeedbackWsAfterBracketOpen(arg),
        acceptList ? acceptList(PERR_getFeedbackList(arg)) : PERR_getFeedbackList(arg),
        acceptWsAfterList ? acceptWsAfterList(PERR_getFeedbackWsAfterList(arg)) : PERR_getFeedbackWsAfterList(arg),
        acceptWsAfterBracketClose ? acceptWsAfterBracketClose(PERR_getFeedbackWsAfterBracketClose(arg)) : PERR_getFeedbackWsAfterBracketClose(arg));
  }
  ATabort("not a Feedback: %t\n", arg);
  return (PERR_Feedback)NULL;
}

/*}}}  */
/*{{{  PERR_SubjectList PERR_visitSubjectList(PERR_SubjectList arg, PERR_Subject (*acceptHead)(PERR_Subject), PERR_OptLayout (*acceptWsAfterHead)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterSep)(PERR_OptLayout)) */

PERR_SubjectList PERR_visitSubjectList(PERR_SubjectList arg, PERR_Subject (*acceptHead)(PERR_Subject), PERR_OptLayout (*acceptWsAfterHead)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterSep)(PERR_OptLayout))
{
  if (PERR_isSubjectListEmpty(arg)) {
    return PERR_makeSubjectListEmpty();
  }
  if (PERR_isSubjectListSingle(arg)) {
    return PERR_makeSubjectListSingle(
        acceptHead ? acceptHead(PERR_getSubjectListHead(arg)) : PERR_getSubjectListHead(arg));
  }
  if (PERR_isSubjectListMany(arg)) {
    return PERR_makeSubjectListMany(
        acceptHead ? acceptHead(PERR_getSubjectListHead(arg)) : PERR_getSubjectListHead(arg),
        acceptWsAfterHead ? acceptWsAfterHead(PERR_getSubjectListWsAfterHead(arg)) : PERR_getSubjectListWsAfterHead(arg),
        acceptWsAfterSep ? acceptWsAfterSep(PERR_getSubjectListWsAfterSep(arg)) : PERR_getSubjectListWsAfterSep(arg),
        PERR_visitSubjectList(PERR_getSubjectListTail(arg), acceptHead, acceptWsAfterHead, acceptWsAfterSep));
  }
  ATabort("not a SubjectList: %t\n", arg);
  return (PERR_SubjectList)NULL;
}

/*}}}  */
/*{{{  PERR_Subject PERR_visitSubject(PERR_Subject arg, PERR_OptLayout (*acceptWsAfterSubject)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterParenOpen)(PERR_OptLayout), PERR_StrCon (*acceptId)(PERR_StrCon), PERR_OptLayout (*acceptWsAfterId)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterComma)(PERR_OptLayout), PERR_Location (*acceptLocation)(PERR_Location), PERR_OptLayout (*acceptWsAfterLocation)(PERR_OptLayout)) */

PERR_Subject PERR_visitSubject(PERR_Subject arg, PERR_OptLayout (*acceptWsAfterSubject)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterParenOpen)(PERR_OptLayout), PERR_StrCon (*acceptId)(PERR_StrCon), PERR_OptLayout (*acceptWsAfterId)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterComma)(PERR_OptLayout), PERR_Location (*acceptLocation)(PERR_Location), PERR_OptLayout (*acceptWsAfterLocation)(PERR_OptLayout))
{
  if (PERR_isSubjectSubject(arg)) {
    return PERR_makeSubjectSubject(
        acceptWsAfterSubject ? acceptWsAfterSubject(PERR_getSubjectWsAfterSubject(arg)) : PERR_getSubjectWsAfterSubject(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PERR_getSubjectWsAfterParenOpen(arg)) : PERR_getSubjectWsAfterParenOpen(arg),
        acceptId ? acceptId(PERR_getSubjectId(arg)) : PERR_getSubjectId(arg),
        acceptWsAfterId ? acceptWsAfterId(PERR_getSubjectWsAfterId(arg)) : PERR_getSubjectWsAfterId(arg),
        acceptWsAfterComma ? acceptWsAfterComma(PERR_getSubjectWsAfterComma(arg)) : PERR_getSubjectWsAfterComma(arg),
        acceptLocation ? acceptLocation(PERR_getSubjectLocation(arg)) : PERR_getSubjectLocation(arg),
        acceptWsAfterLocation ? acceptWsAfterLocation(PERR_getSubjectWsAfterLocation(arg)) : PERR_getSubjectWsAfterLocation(arg));
  }
  ATabort("not a Subject: %t\n", arg);
  return (PERR_Subject)NULL;
}

/*}}}  */
/*{{{  PERR_Location PERR_visitLocation(PERR_Location arg, PERR_OptLayout (*acceptWsAfterLocation)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterParenOpen)(PERR_OptLayout), PERR_StrCon (*acceptFilename)(PERR_StrCon), PERR_OptLayout (*acceptWsAfterFilename)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterComma)(PERR_OptLayout), PERR_Area (*acceptArea)(PERR_Area), PERR_OptLayout (*acceptWsAfterArea)(PERR_OptLayout)) */

PERR_Location PERR_visitLocation(PERR_Location arg, PERR_OptLayout (*acceptWsAfterLocation)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterParenOpen)(PERR_OptLayout), PERR_StrCon (*acceptFilename)(PERR_StrCon), PERR_OptLayout (*acceptWsAfterFilename)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterComma)(PERR_OptLayout), PERR_Area (*acceptArea)(PERR_Area), PERR_OptLayout (*acceptWsAfterArea)(PERR_OptLayout))
{
  if (PERR_isLocationLocation(arg)) {
    return PERR_makeLocationLocation(
        acceptWsAfterLocation ? acceptWsAfterLocation(PERR_getLocationWsAfterLocation(arg)) : PERR_getLocationWsAfterLocation(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PERR_getLocationWsAfterParenOpen(arg)) : PERR_getLocationWsAfterParenOpen(arg),
        acceptFilename ? acceptFilename(PERR_getLocationFilename(arg)) : PERR_getLocationFilename(arg),
        acceptWsAfterFilename ? acceptWsAfterFilename(PERR_getLocationWsAfterFilename(arg)) : PERR_getLocationWsAfterFilename(arg),
        acceptWsAfterComma ? acceptWsAfterComma(PERR_getLocationWsAfterComma(arg)) : PERR_getLocationWsAfterComma(arg),
        acceptArea ? acceptArea(PERR_getLocationArea(arg)) : PERR_getLocationArea(arg),
        acceptWsAfterArea ? acceptWsAfterArea(PERR_getLocationWsAfterArea(arg)) : PERR_getLocationWsAfterArea(arg));
  }
  if (PERR_isLocationNoLocation(arg)) {
    return PERR_makeLocationNoLocation();
  }
  ATabort("not a Location: %t\n", arg);
  return (PERR_Location)NULL;
}

/*}}}  */
/*{{{  PERR_Area PERR_visitArea(PERR_Area arg, PERR_OptLayout (*acceptWsAfterArea)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterParenOpen)(PERR_OptLayout), PERR_NatCon (*acceptBeginLine)(PERR_NatCon), PERR_OptLayout (*acceptWsAfterBeginLine)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterComma)(PERR_OptLayout), PERR_NatCon (*acceptBeginColumn)(PERR_NatCon), PERR_OptLayout (*acceptWsAfterBeginColumn)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterComma1)(PERR_OptLayout), PERR_NatCon (*acceptEndLine)(PERR_NatCon), PERR_OptLayout (*acceptWsAfterEndLine)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterComma2)(PERR_OptLayout), PERR_NatCon (*acceptEndColumn)(PERR_NatCon), PERR_OptLayout (*acceptWsAfterEndColumn)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterComma3)(PERR_OptLayout), PERR_NatCon (*acceptBeginOffset)(PERR_NatCon), PERR_OptLayout (*acceptWsAfterBeginOffset)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterComma4)(PERR_OptLayout), PERR_NatCon (*acceptEndOffset)(PERR_NatCon), PERR_OptLayout (*acceptWsAfterEndOffset)(PERR_OptLayout)) */

PERR_Area PERR_visitArea(PERR_Area arg, PERR_OptLayout (*acceptWsAfterArea)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterParenOpen)(PERR_OptLayout), PERR_NatCon (*acceptBeginLine)(PERR_NatCon), PERR_OptLayout (*acceptWsAfterBeginLine)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterComma)(PERR_OptLayout), PERR_NatCon (*acceptBeginColumn)(PERR_NatCon), PERR_OptLayout (*acceptWsAfterBeginColumn)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterComma1)(PERR_OptLayout), PERR_NatCon (*acceptEndLine)(PERR_NatCon), PERR_OptLayout (*acceptWsAfterEndLine)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterComma2)(PERR_OptLayout), PERR_NatCon (*acceptEndColumn)(PERR_NatCon), PERR_OptLayout (*acceptWsAfterEndColumn)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterComma3)(PERR_OptLayout), PERR_NatCon (*acceptBeginOffset)(PERR_NatCon), PERR_OptLayout (*acceptWsAfterBeginOffset)(PERR_OptLayout), PERR_OptLayout (*acceptWsAfterComma4)(PERR_OptLayout), PERR_NatCon (*acceptEndOffset)(PERR_NatCon), PERR_OptLayout (*acceptWsAfterEndOffset)(PERR_OptLayout))
{
  if (PERR_isAreaArea(arg)) {
    return PERR_makeAreaArea(
        acceptWsAfterArea ? acceptWsAfterArea(PERR_getAreaWsAfterArea(arg)) : PERR_getAreaWsAfterArea(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PERR_getAreaWsAfterParenOpen(arg)) : PERR_getAreaWsAfterParenOpen(arg),
        acceptBeginLine ? acceptBeginLine(PERR_getAreaBeginLine(arg)) : PERR_getAreaBeginLine(arg),
        acceptWsAfterBeginLine ? acceptWsAfterBeginLine(PERR_getAreaWsAfterBeginLine(arg)) : PERR_getAreaWsAfterBeginLine(arg),
        acceptWsAfterComma ? acceptWsAfterComma(PERR_getAreaWsAfterComma(arg)) : PERR_getAreaWsAfterComma(arg),
        acceptBeginColumn ? acceptBeginColumn(PERR_getAreaBeginColumn(arg)) : PERR_getAreaBeginColumn(arg),
        acceptWsAfterBeginColumn ? acceptWsAfterBeginColumn(PERR_getAreaWsAfterBeginColumn(arg)) : PERR_getAreaWsAfterBeginColumn(arg),
        acceptWsAfterComma1 ? acceptWsAfterComma1(PERR_getAreaWsAfterComma1(arg)) : PERR_getAreaWsAfterComma1(arg),
        acceptEndLine ? acceptEndLine(PERR_getAreaEndLine(arg)) : PERR_getAreaEndLine(arg),
        acceptWsAfterEndLine ? acceptWsAfterEndLine(PERR_getAreaWsAfterEndLine(arg)) : PERR_getAreaWsAfterEndLine(arg),
        acceptWsAfterComma2 ? acceptWsAfterComma2(PERR_getAreaWsAfterComma2(arg)) : PERR_getAreaWsAfterComma2(arg),
        acceptEndColumn ? acceptEndColumn(PERR_getAreaEndColumn(arg)) : PERR_getAreaEndColumn(arg),
        acceptWsAfterEndColumn ? acceptWsAfterEndColumn(PERR_getAreaWsAfterEndColumn(arg)) : PERR_getAreaWsAfterEndColumn(arg),
        acceptWsAfterComma3 ? acceptWsAfterComma3(PERR_getAreaWsAfterComma3(arg)) : PERR_getAreaWsAfterComma3(arg),
        acceptBeginOffset ? acceptBeginOffset(PERR_getAreaBeginOffset(arg)) : PERR_getAreaBeginOffset(arg),
        acceptWsAfterBeginOffset ? acceptWsAfterBeginOffset(PERR_getAreaWsAfterBeginOffset(arg)) : PERR_getAreaWsAfterBeginOffset(arg),
        acceptWsAfterComma4 ? acceptWsAfterComma4(PERR_getAreaWsAfterComma4(arg)) : PERR_getAreaWsAfterComma4(arg),
        acceptEndOffset ? acceptEndOffset(PERR_getAreaEndOffset(arg)) : PERR_getAreaEndOffset(arg),
        acceptWsAfterEndOffset ? acceptWsAfterEndOffset(PERR_getAreaWsAfterEndOffset(arg)) : PERR_getAreaWsAfterEndOffset(arg));
  }
  if (PERR_isAreaNoArea(arg)) {
    return PERR_makeAreaNoArea();
  }
  ATabort("not a Area: %t\n", arg);
  return (PERR_Area)NULL;
}

/*}}}  */
/*{{{  PERR_NatCon PERR_visitNatCon(PERR_NatCon arg, char* (*acceptString)(char*)) */

PERR_NatCon PERR_visitNatCon(PERR_NatCon arg, char* (*acceptString)(char*))
{
  if (PERR_isNatConString(arg)) {
    return PERR_makeNatConString(
        acceptString ? acceptString(PERR_getNatConString(arg)) : PERR_getNatConString(arg));
  }
  ATabort("not a NatCon: %t\n", arg);
  return (PERR_NatCon)NULL;
}

/*}}}  */
/*{{{  PERR_StrCon PERR_visitStrCon(PERR_StrCon arg, char* (*acceptString)(char*)) */

PERR_StrCon PERR_visitStrCon(PERR_StrCon arg, char* (*acceptString)(char*))
{
  if (PERR_isStrConString(arg)) {
    return PERR_makeStrConString(
        acceptString ? acceptString(PERR_getStrConString(arg)) : PERR_getStrConString(arg));
  }
  ATabort("not a StrCon: %t\n", arg);
  return (PERR_StrCon)NULL;
}

/*}}}  */
/*{{{  PERR_OptLayout PERR_visitOptLayout(PERR_OptLayout arg, char* (*acceptString)(char*)) */

PERR_OptLayout PERR_visitOptLayout(PERR_OptLayout arg, char* (*acceptString)(char*))
{
  if (PERR_isOptLayoutAbsent(arg)) {
    return PERR_makeOptLayoutAbsent();
  }
  if (PERR_isOptLayoutPresent(arg)) {
    return PERR_makeOptLayoutPresent(
        acceptString ? acceptString(PERR_getOptLayoutString(arg)) : PERR_getOptLayoutString(arg));
  }
  ATabort("not a OptLayout: %t\n", arg);
  return (PERR_OptLayout)NULL;
}

/*}}}  */
/*{{{  PERR_Start PERR_visitStart(PERR_Start arg, PERR_OptLayout (*acceptWsBefore)(PERR_OptLayout), PERR_Area (*acceptTopArea)(PERR_Area), PERR_OptLayout (*acceptWsAfter)(PERR_OptLayout), int (*acceptAmbCnt)(int), PERR_Location (*acceptTopLocation)(PERR_Location), PERR_Subject (*acceptTopSubject)(PERR_Subject), PERR_Feedback (*acceptTopFeedback)(PERR_Feedback)) */

PERR_Start PERR_visitStart(PERR_Start arg, PERR_OptLayout (*acceptWsBefore)(PERR_OptLayout), PERR_Area (*acceptTopArea)(PERR_Area), PERR_OptLayout (*acceptWsAfter)(PERR_OptLayout), int (*acceptAmbCnt)(int), PERR_Location (*acceptTopLocation)(PERR_Location), PERR_Subject (*acceptTopSubject)(PERR_Subject), PERR_Feedback (*acceptTopFeedback)(PERR_Feedback))
{
  if (PERR_isStartArea(arg)) {
    return PERR_makeStartArea(
        acceptWsBefore ? acceptWsBefore(PERR_getStartWsBefore(arg)) : PERR_getStartWsBefore(arg),
        acceptTopArea ? acceptTopArea(PERR_getStartTopArea(arg)) : PERR_getStartTopArea(arg),
        acceptWsAfter ? acceptWsAfter(PERR_getStartWsAfter(arg)) : PERR_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(PERR_getStartAmbCnt(arg)) : PERR_getStartAmbCnt(arg));
  }
  if (PERR_isStartLocation(arg)) {
    return PERR_makeStartLocation(
        acceptWsBefore ? acceptWsBefore(PERR_getStartWsBefore(arg)) : PERR_getStartWsBefore(arg),
        acceptTopLocation ? acceptTopLocation(PERR_getStartTopLocation(arg)) : PERR_getStartTopLocation(arg),
        acceptWsAfter ? acceptWsAfter(PERR_getStartWsAfter(arg)) : PERR_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(PERR_getStartAmbCnt(arg)) : PERR_getStartAmbCnt(arg));
  }
  if (PERR_isStartSubject(arg)) {
    return PERR_makeStartSubject(
        acceptWsBefore ? acceptWsBefore(PERR_getStartWsBefore(arg)) : PERR_getStartWsBefore(arg),
        acceptTopSubject ? acceptTopSubject(PERR_getStartTopSubject(arg)) : PERR_getStartTopSubject(arg),
        acceptWsAfter ? acceptWsAfter(PERR_getStartWsAfter(arg)) : PERR_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(PERR_getStartAmbCnt(arg)) : PERR_getStartAmbCnt(arg));
  }
  if (PERR_isStartFeedback(arg)) {
    return PERR_makeStartFeedback(
        acceptWsBefore ? acceptWsBefore(PERR_getStartWsBefore(arg)) : PERR_getStartWsBefore(arg),
        acceptTopFeedback ? acceptTopFeedback(PERR_getStartTopFeedback(arg)) : PERR_getStartTopFeedback(arg),
        acceptWsAfter ? acceptWsAfter(PERR_getStartWsAfter(arg)) : PERR_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(PERR_getStartAmbCnt(arg)) : PERR_getStartAmbCnt(arg));
  }
  ATabort("not a Start: %t\n", arg);
  return (PERR_Start)NULL;
}

/*}}}  */

/*}}}  */
