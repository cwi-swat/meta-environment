#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "ParsedErrorAPI.h"

/*{{{  conversion functions */

ATerm PME_stringToChars(const char *str)
{
  int len = strlen(str);
  int i;
  ATermList result = ATempty;

  for (i = len - 1; i >= 0; i--) {
    result = ATinsert(result, (ATerm) ATmakeInt(str[i]));
  }

  return (ATerm) result;
}

char *PME_charsToString(ATerm arg)
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

typedef struct ATerm _PME_Feedback;
typedef struct ATerm _PME_SubjectList;
typedef struct ATerm _PME_Subject;
typedef struct ATerm _PME_Location;
typedef struct ATerm _PME_Area;
typedef struct ATerm _PME_NatCon;
typedef struct ATerm _PME_String;
typedef struct ATerm _PME_OptLayout;
typedef struct ATerm _PME_Start;

/*}}}  */

/*{{{  void PME_initParsedErrorAPIApi(void) */

void PME_initParsedErrorAPIApi(void)
{
  init_ParsedErrorAPI_dict();
}

/*}}}  */

/*{{{  term conversion functions */

/*{{{  PME_Feedback PME_FeedbackFromTerm(ATerm t) */

PME_Feedback PME_FeedbackFromTerm(ATerm t)
{
  return (PME_Feedback)t;
}

/*}}}  */
/*{{{  ATerm PME_FeedbackToTerm(PME_Feedback arg) */

ATerm PME_FeedbackToTerm(PME_Feedback arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PME_SubjectList PME_SubjectListFromTerm(ATerm t) */

PME_SubjectList PME_SubjectListFromTerm(ATerm t)
{
  return (PME_SubjectList)t;
}

/*}}}  */
/*{{{  ATerm PME_SubjectListToTerm(PME_SubjectList arg) */

ATerm PME_SubjectListToTerm(PME_SubjectList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PME_Subject PME_SubjectFromTerm(ATerm t) */

PME_Subject PME_SubjectFromTerm(ATerm t)
{
  return (PME_Subject)t;
}

/*}}}  */
/*{{{  ATerm PME_SubjectToTerm(PME_Subject arg) */

ATerm PME_SubjectToTerm(PME_Subject arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PME_Location PME_LocationFromTerm(ATerm t) */

PME_Location PME_LocationFromTerm(ATerm t)
{
  return (PME_Location)t;
}

/*}}}  */
/*{{{  ATerm PME_LocationToTerm(PME_Location arg) */

ATerm PME_LocationToTerm(PME_Location arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PME_Area PME_AreaFromTerm(ATerm t) */

PME_Area PME_AreaFromTerm(ATerm t)
{
  return (PME_Area)t;
}

/*}}}  */
/*{{{  ATerm PME_AreaToTerm(PME_Area arg) */

ATerm PME_AreaToTerm(PME_Area arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PME_NatCon PME_NatConFromTerm(ATerm t) */

PME_NatCon PME_NatConFromTerm(ATerm t)
{
  return (PME_NatCon)t;
}

/*}}}  */
/*{{{  ATerm PME_NatConToTerm(PME_NatCon arg) */

ATerm PME_NatConToTerm(PME_NatCon arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PME_String PME_StringFromTerm(ATerm t) */

PME_String PME_StringFromTerm(ATerm t)
{
  return (PME_String)t;
}

/*}}}  */
/*{{{  ATerm PME_StringToTerm(PME_String arg) */

ATerm PME_StringToTerm(PME_String arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PME_OptLayout PME_OptLayoutFromTerm(ATerm t) */

PME_OptLayout PME_OptLayoutFromTerm(ATerm t)
{
  return (PME_OptLayout)t;
}

/*}}}  */
/*{{{  ATerm PME_OptLayoutToTerm(PME_OptLayout arg) */

ATerm PME_OptLayoutToTerm(PME_OptLayout arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PME_Start PME_StartFromTerm(ATerm t) */

PME_Start PME_StartFromTerm(ATerm t)
{
  return (PME_Start)t;
}

/*}}}  */
/*{{{  ATerm PME_StartToTerm(PME_Start arg) */

ATerm PME_StartToTerm(PME_Start arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*}}}  */
/*{{{  list functions */

int PME_getSubjectListLength (PME_SubjectList arg) {
  if (ATisEmpty((ATermList) arg)) {
    return 0;
  }
  return (ATgetLength((ATermList) arg) / 4) + 1;
}
PME_SubjectList reverseSubjectList(PME_SubjectList arg) {
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

  return (PME_SubjectList) result;
}
PME_SubjectList PME_appendSubjectList(PME_SubjectList arg0, PME_OptLayout wsAfterHead, PME_OptLayout wsAfterSep, PME_Subject arg1) {
  return PME_concatSubjectList(arg0, wsAfterHead, wsAfterSep, PME_makeSubjectListSingle(arg1));
}
PME_SubjectList PME_concatSubjectList(PME_SubjectList arg0, PME_OptLayout wsAfterHead, PME_OptLayout wsAfterSep, PME_SubjectList arg1) {
  if (ATisEmpty((ATermList) arg0)) {
    return arg1;
  }
  arg1 = PME_makeSubjectListMany((PME_Subject)ATgetFirst((ATermList) arg0), wsAfterHead, wsAfterSep,  arg1);
  arg1 = (PME_SubjectList) ATgetNext((ATermList) arg1);
  return (PME_SubjectList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
PME_SubjectList PME_sliceSubjectList(PME_SubjectList arg, int start, int end) {
  return (PME_SubjectList) ATgetSlice((ATermList) arg, start * 4, end * 4);
}
PME_Subject PME_getSubjectListSubjectAt(PME_SubjectList arg, int index) {
 return (PME_Subject)ATelementAt((ATermList) arg,index * 4);
}
PME_SubjectList PME_replaceSubjectListSubjectAt(PME_SubjectList arg, PME_Subject elem, int index) {
 return (PME_SubjectList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index * 4);
}
PME_SubjectList PME_makeSubjectList2(PME_OptLayout wsAfterHead, PME_OptLayout wsAfterSep, PME_Subject elem1, PME_Subject elem2) {
  return PME_makeSubjectListMany(elem1, wsAfterHead, wsAfterSep, PME_makeSubjectListSingle(elem2));
}
PME_SubjectList PME_makeSubjectList3(PME_OptLayout wsAfterHead, PME_OptLayout wsAfterSep, PME_Subject elem1, PME_Subject elem2, PME_Subject elem3) {
  return PME_makeSubjectListMany(elem1, wsAfterHead, wsAfterSep, PME_makeSubjectList2(wsAfterHead, wsAfterSep, elem2, elem3));
}
PME_SubjectList PME_makeSubjectList4(PME_OptLayout wsAfterHead, PME_OptLayout wsAfterSep, PME_Subject elem1, PME_Subject elem2, PME_Subject elem3, PME_Subject elem4) {
  return PME_makeSubjectListMany(elem1, wsAfterHead, wsAfterSep, PME_makeSubjectList3(wsAfterHead, wsAfterSep, elem2, elem3, elem4));
}
PME_SubjectList PME_makeSubjectList5(PME_OptLayout wsAfterHead, PME_OptLayout wsAfterSep, PME_Subject elem1, PME_Subject elem2, PME_Subject elem3, PME_Subject elem4, PME_Subject elem5) {
  return PME_makeSubjectListMany(elem1, wsAfterHead, wsAfterSep, PME_makeSubjectList4(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5));
}
PME_SubjectList PME_makeSubjectList6(PME_OptLayout wsAfterHead, PME_OptLayout wsAfterSep, PME_Subject elem1, PME_Subject elem2, PME_Subject elem3, PME_Subject elem4, PME_Subject elem5, PME_Subject elem6) {
  return PME_makeSubjectListMany(elem1, wsAfterHead, wsAfterSep, PME_makeSubjectList5(wsAfterHead, wsAfterSep, elem2, elem3, elem4, elem5, elem6));
}

/*}}}  */
/*{{{  constructors */

/*{{{  PME_Feedback PME_makeFeedbackInfo(PME_OptLayout wsAfterInfo, PME_OptLayout wsAfterParenOpen, PME_String id, PME_OptLayout wsAfterId, PME_OptLayout wsAfterComma, PME_String producerId, PME_OptLayout wsAfterProducerId, PME_OptLayout wsAfterComma1, PME_String producerType, PME_OptLayout wsAfterProducerType, PME_OptLayout wsAfterComma2, PME_String description, PME_OptLayout wsAfterDescription, PME_OptLayout wsAfterComma3, PME_OptLayout wsAfterBracketOpen, PME_SubjectList list, PME_OptLayout wsAfterList, PME_OptLayout wsAfterBracketClose) */

PME_Feedback PME_makeFeedbackInfo(PME_OptLayout wsAfterInfo, PME_OptLayout wsAfterParenOpen, PME_String id, PME_OptLayout wsAfterId, PME_OptLayout wsAfterComma, PME_String producerId, PME_OptLayout wsAfterProducerId, PME_OptLayout wsAfterComma1, PME_String producerType, PME_OptLayout wsAfterProducerType, PME_OptLayout wsAfterComma2, PME_String description, PME_OptLayout wsAfterDescription, PME_OptLayout wsAfterComma3, PME_OptLayout wsAfterBracketOpen, PME_SubjectList list, PME_OptLayout wsAfterList, PME_OptLayout wsAfterBracketClose)
{
  return (PME_Feedback)(ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun3))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun7))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl2(PME_afun8, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun10)), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun12))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun13)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun13)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun13)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun13)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun14))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun15))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun16))), (ATerm)ATmakeAppl1(PME_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl1(PME_afun19, (ATerm)ATmakeAppl0(PME_afun15)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun3))), (ATerm) wsAfterBracketClose), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun7))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl1(PME_afun20, (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl2(PME_afun8, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun10)), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))))), (ATerm) list)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun12))), (ATerm) wsAfterComma3), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm) wsAfterDescription), (ATerm) description), (ATerm) wsAfterComma2), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm) wsAfterProducerType), (ATerm) producerType), (ATerm) wsAfterComma1), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm) wsAfterProducerId), (ATerm) producerId), (ATerm) wsAfterComma), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm) wsAfterId), (ATerm) id), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun14))), (ATerm) wsAfterInfo), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun15))));
}

/*}}}  */
/*{{{  PME_Feedback PME_makeFeedbackWarning(PME_OptLayout wsAfterWarning, PME_OptLayout wsAfterParenOpen, PME_String id, PME_OptLayout wsAfterId, PME_OptLayout wsAfterComma, PME_String producerId, PME_OptLayout wsAfterProducerId, PME_OptLayout wsAfterComma1, PME_String producerType, PME_OptLayout wsAfterProducerType, PME_OptLayout wsAfterComma2, PME_String description, PME_OptLayout wsAfterDescription, PME_OptLayout wsAfterComma3, PME_OptLayout wsAfterBracketOpen, PME_SubjectList list, PME_OptLayout wsAfterList, PME_OptLayout wsAfterBracketClose) */

PME_Feedback PME_makeFeedbackWarning(PME_OptLayout wsAfterWarning, PME_OptLayout wsAfterParenOpen, PME_String id, PME_OptLayout wsAfterId, PME_OptLayout wsAfterComma, PME_String producerId, PME_OptLayout wsAfterProducerId, PME_OptLayout wsAfterComma1, PME_String producerType, PME_OptLayout wsAfterProducerType, PME_OptLayout wsAfterComma2, PME_String description, PME_OptLayout wsAfterDescription, PME_OptLayout wsAfterComma3, PME_OptLayout wsAfterBracketOpen, PME_SubjectList list, PME_OptLayout wsAfterList, PME_OptLayout wsAfterBracketClose)
{
  return (PME_Feedback)(ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun3))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun7))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl2(PME_afun8, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun10)), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun12))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun13)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun13)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun13)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun13)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun14))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun16))), (ATerm)ATmakeAppl1(PME_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl1(PME_afun19, (ATerm)ATmakeAppl0(PME_afun21)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun3))), (ATerm) wsAfterBracketClose), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun7))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl1(PME_afun20, (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl2(PME_afun8, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun10)), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))))), (ATerm) list)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun12))), (ATerm) wsAfterComma3), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm) wsAfterDescription), (ATerm) description), (ATerm) wsAfterComma2), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm) wsAfterProducerType), (ATerm) producerType), (ATerm) wsAfterComma1), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm) wsAfterProducerId), (ATerm) producerId), (ATerm) wsAfterComma), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm) wsAfterId), (ATerm) id), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun14))), (ATerm) wsAfterWarning), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun21))));
}

/*}}}  */
/*{{{  PME_Feedback PME_makeFeedbackError(PME_OptLayout wsAfterError, PME_OptLayout wsAfterParenOpen, PME_String id, PME_OptLayout wsAfterId, PME_OptLayout wsAfterComma, PME_String producerId, PME_OptLayout wsAfterProducerId, PME_OptLayout wsAfterComma1, PME_String producerType, PME_OptLayout wsAfterProducerType, PME_OptLayout wsAfterComma2, PME_String description, PME_OptLayout wsAfterDescription, PME_OptLayout wsAfterComma3, PME_OptLayout wsAfterBracketOpen, PME_SubjectList list, PME_OptLayout wsAfterList, PME_OptLayout wsAfterBracketClose) */

PME_Feedback PME_makeFeedbackError(PME_OptLayout wsAfterError, PME_OptLayout wsAfterParenOpen, PME_String id, PME_OptLayout wsAfterId, PME_OptLayout wsAfterComma, PME_String producerId, PME_OptLayout wsAfterProducerId, PME_OptLayout wsAfterComma1, PME_String producerType, PME_OptLayout wsAfterProducerType, PME_OptLayout wsAfterComma2, PME_String description, PME_OptLayout wsAfterDescription, PME_OptLayout wsAfterComma3, PME_OptLayout wsAfterBracketOpen, PME_SubjectList list, PME_OptLayout wsAfterList, PME_OptLayout wsAfterBracketClose)
{
  return (PME_Feedback)(ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun3))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun7))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl2(PME_afun8, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun10)), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun12))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun13)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun13)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun13)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun13)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun14))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun22))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun16))), (ATerm)ATmakeAppl1(PME_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl1(PME_afun19, (ATerm)ATmakeAppl0(PME_afun22)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun3))), (ATerm) wsAfterBracketClose), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun7))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl1(PME_afun20, (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl2(PME_afun8, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun10)), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))))), (ATerm) list)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun12))), (ATerm) wsAfterComma3), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm) wsAfterDescription), (ATerm) description), (ATerm) wsAfterComma2), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm) wsAfterProducerType), (ATerm) producerType), (ATerm) wsAfterComma1), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm) wsAfterProducerId), (ATerm) producerId), (ATerm) wsAfterComma), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm) wsAfterId), (ATerm) id), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun14))), (ATerm) wsAfterError), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun22))));
}

/*}}}  */
/*{{{  PME_Feedback PME_makeFeedbackFatalError(PME_OptLayout wsAfterFatalError, PME_OptLayout wsAfterParenOpen, PME_String id, PME_OptLayout wsAfterId, PME_OptLayout wsAfterComma, PME_String producerId, PME_OptLayout wsAfterProducerId, PME_OptLayout wsAfterComma1, PME_String producerType, PME_OptLayout wsAfterProducerType, PME_OptLayout wsAfterComma2, PME_String description, PME_OptLayout wsAfterDescription, PME_OptLayout wsAfterComma3, PME_OptLayout wsAfterBracketOpen, PME_SubjectList list, PME_OptLayout wsAfterList, PME_OptLayout wsAfterBracketClose) */

PME_Feedback PME_makeFeedbackFatalError(PME_OptLayout wsAfterFatalError, PME_OptLayout wsAfterParenOpen, PME_String id, PME_OptLayout wsAfterId, PME_OptLayout wsAfterComma, PME_String producerId, PME_OptLayout wsAfterProducerId, PME_OptLayout wsAfterComma1, PME_String producerType, PME_OptLayout wsAfterProducerType, PME_OptLayout wsAfterComma2, PME_String description, PME_OptLayout wsAfterDescription, PME_OptLayout wsAfterComma3, PME_OptLayout wsAfterBracketOpen, PME_SubjectList list, PME_OptLayout wsAfterList, PME_OptLayout wsAfterBracketClose)
{
  return (PME_Feedback)(ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun3))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun7))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl2(PME_afun8, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun10)), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun12))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun13)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun13)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun13)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun13)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun14))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun23))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun16))), (ATerm)ATmakeAppl1(PME_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl1(PME_afun19, (ATerm)ATmakeAppl0(PME_afun23)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun3))), (ATerm) wsAfterBracketClose), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun7))), (ATerm) wsAfterList), (ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl1(PME_afun20, (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl2(PME_afun8, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun10)), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))))), (ATerm) list)), (ATerm) wsAfterBracketOpen), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun12))), (ATerm) wsAfterComma3), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm) wsAfterDescription), (ATerm) description), (ATerm) wsAfterComma2), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm) wsAfterProducerType), (ATerm) producerType), (ATerm) wsAfterComma1), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm) wsAfterProducerId), (ATerm) producerId), (ATerm) wsAfterComma), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm) wsAfterId), (ATerm) id), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun14))), (ATerm) wsAfterFatalError), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun23))));
}

/*}}}  */
/*{{{  PME_SubjectList PME_makeSubjectListEmpty() */

PME_SubjectList PME_makeSubjectListEmpty()
{
  return (PME_SubjectList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  PME_SubjectList PME_makeSubjectListSingle(PME_Subject head) */

PME_SubjectList PME_makeSubjectListSingle(PME_Subject head)
{
  return (PME_SubjectList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  PME_SubjectList PME_makeSubjectListMany(PME_Subject head, PME_OptLayout wsAfterHead, PME_OptLayout wsAfterSep, PME_SubjectList tail) */

PME_SubjectList PME_makeSubjectListMany(PME_Subject head, PME_OptLayout wsAfterHead, PME_OptLayout wsAfterSep, PME_SubjectList tail)
{
  if (PME_isSubjectListEmpty(tail)) {
    return PME_makeSubjectListSingle(head);
  }
  return (PME_SubjectList)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm) wsAfterSep), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm) wsAfterHead), (ATerm) head);
}

/*}}}  */
/*{{{  PME_Subject PME_makeSubjectLocatable(PME_OptLayout wsAfterSubject, PME_OptLayout wsAfterParenOpen, PME_String id, PME_OptLayout wsAfterId, PME_OptLayout wsAfterComma, PME_Location Location, PME_OptLayout wsAfterLocation) */

PME_Subject PME_makeSubjectLocatable(PME_OptLayout wsAfterSubject, PME_OptLayout wsAfterParenOpen, PME_String id, PME_OptLayout wsAfterId, PME_OptLayout wsAfterComma, PME_Location Location, PME_OptLayout wsAfterLocation)
{
  return (PME_Subject)(ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun3))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun24)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun13)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun14))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun25))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun10))), (ATerm)ATmakeAppl1(PME_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl1(PME_afun19, (ATerm)ATmakeAppl0(PME_afun26)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun3))), (ATerm) wsAfterLocation), (ATerm) Location), (ATerm) wsAfterComma), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm) wsAfterId), (ATerm) id), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun14))), (ATerm) wsAfterSubject), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun25))));
}

/*}}}  */
/*{{{  PME_Subject PME_makeSubjectUnlocatable(PME_OptLayout wsAfterSubject, PME_OptLayout wsAfterParenOpen, PME_String id, PME_OptLayout wsAfterId) */

PME_Subject PME_makeSubjectUnlocatable(PME_OptLayout wsAfterSubject, PME_OptLayout wsAfterParenOpen, PME_String id, PME_OptLayout wsAfterId)
{
  return (PME_Subject)(ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun3))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun13)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun14))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun25))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun10))), (ATerm)ATmakeAppl1(PME_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl1(PME_afun19, (ATerm)ATmakeAppl0(PME_afun27)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun3))), (ATerm) wsAfterId), (ATerm) id), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun14))), (ATerm) wsAfterSubject), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun25))));
}

/*}}}  */
/*{{{  PME_Location PME_makeLocationLocation(PME_OptLayout wsAfterLocation, PME_OptLayout wsAfterParenOpen, PME_String filename, PME_OptLayout wsAfterFilename, PME_OptLayout wsAfterComma, PME_Area Area, PME_OptLayout wsAfterArea) */

PME_Location PME_makeLocationLocation(PME_OptLayout wsAfterLocation, PME_OptLayout wsAfterParenOpen, PME_String filename, PME_OptLayout wsAfterFilename, PME_OptLayout wsAfterComma, PME_Area Area, PME_OptLayout wsAfterArea)
{
  return (PME_Location)(ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun3))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun28)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun13)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun14))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun29))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun24))), (ATerm)ATmakeAppl1(PME_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl1(PME_afun19, (ATerm)ATmakeAppl0(PME_afun29)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun3))), (ATerm) wsAfterArea), (ATerm) Area), (ATerm) wsAfterComma), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm) wsAfterFilename), (ATerm) filename), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun14))), (ATerm) wsAfterLocation), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun29))));
}

/*}}}  */
/*{{{  PME_Area PME_makeAreaArea(PME_OptLayout wsAfterArea, PME_OptLayout wsAfterParenOpen, PME_NatCon startLine, PME_OptLayout wsAfterStartLine, PME_OptLayout wsAfterComma, PME_NatCon startColumn, PME_OptLayout wsAfterStartColumn, PME_OptLayout wsAfterComma1, PME_NatCon endLine, PME_OptLayout wsAfterEndLine, PME_OptLayout wsAfterComma2, PME_NatCon endColumn, PME_OptLayout wsAfterEndColumn, PME_OptLayout wsAfterComma3, PME_NatCon startOffset, PME_OptLayout wsAfterStartOffset, PME_OptLayout wsAfterComma4, PME_NatCon endOffset, PME_OptLayout wsAfterEndOffset) */

PME_Area PME_makeAreaArea(PME_OptLayout wsAfterArea, PME_OptLayout wsAfterParenOpen, PME_NatCon startLine, PME_OptLayout wsAfterStartLine, PME_OptLayout wsAfterComma, PME_NatCon startColumn, PME_OptLayout wsAfterStartColumn, PME_OptLayout wsAfterComma1, PME_NatCon endLine, PME_OptLayout wsAfterEndLine, PME_OptLayout wsAfterComma2, PME_NatCon endColumn, PME_OptLayout wsAfterEndColumn, PME_OptLayout wsAfterComma3, PME_NatCon startOffset, PME_OptLayout wsAfterStartOffset, PME_OptLayout wsAfterComma4, PME_NatCon endOffset, PME_OptLayout wsAfterEndOffset)
{
  return (PME_Area)(ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun3))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun30)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun30)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun30)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun30)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun30)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun30)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun14))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun31))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun28))), (ATerm)ATmakeAppl1(PME_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl1(PME_afun19, (ATerm)ATmakeAppl0(PME_afun31)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun3))), (ATerm) wsAfterEndOffset), (ATerm) endOffset), (ATerm) wsAfterComma4), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm) wsAfterStartOffset), (ATerm) startOffset), (ATerm) wsAfterComma3), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm) wsAfterEndColumn), (ATerm) endColumn), (ATerm) wsAfterComma2), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm) wsAfterEndLine), (ATerm) endLine), (ATerm) wsAfterComma1), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm) wsAfterStartColumn), (ATerm) startColumn), (ATerm) wsAfterComma), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm) wsAfterStartLine), (ATerm) startLine), (ATerm) wsAfterParenOpen), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun14))), (ATerm) wsAfterArea), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun31))));
}

/*}}}  */
/*{{{  PME_Area PME_makeAreaNoArea() */

PME_Area PME_makeAreaNoArea()
{
  return (PME_Area)(ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun32))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun28))), (ATerm)ATmakeAppl1(PME_afun17, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl1(PME_afun19, (ATerm)ATmakeAppl0(PME_afun32)))))), (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun32))));
}

/*}}}  */
/*{{{  PME_NatCon PME_makeNatConString(char* string) */

PME_NatCon PME_makeNatConString(char* string)
{
  return (PME_NatCon)(ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PME_afun33, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun30)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun30))), (ATerm)ATmakeAppl0(PME_afun34)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl1(PME_afun20, (ATerm)ATmakeAppl1(PME_afun35, (ATerm)ATmakeAppl1(PME_afun36, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PME_afun37, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255)))))), (ATerm) ((ATerm) PME_stringToChars(string)))));
}

/*}}}  */
/*{{{  PME_String PME_makeStringString(char* string) */

PME_String PME_makeStringString(char* string)
{
  return (PME_String)(ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PME_afun33, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun13)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun13))), (ATerm)ATmakeAppl0(PME_afun34)), (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl1(PME_afun20, (ATerm)ATmakeAppl1(PME_afun35, (ATerm)ATmakeAppl1(PME_afun36, (ATerm)ATmakeList1((ATerm)ATmakeAppl2(PME_afun37, (ATerm)ATmakeInt(0), (ATerm)ATmakeInt(255)))))), (ATerm) ((ATerm) PME_stringToChars(string)))));
}

/*}}}  */
/*{{{  PME_OptLayout PME_makeOptLayoutAbsent() */

PME_OptLayout PME_makeOptLayoutAbsent()
{
  return (PME_OptLayout)(ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATempty, (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6))), (ATerm)ATmakeAppl0(PME_afun34)), (ATerm)ATempty);
}

/*}}}  */
/*{{{  PME_OptLayout PME_makeOptLayoutPresent(char* string) */

PME_OptLayout PME_makeOptLayoutPresent(char* string)
{
  return (PME_OptLayout)(ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl0(PME_afun6))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6))), (ATerm)ATmakeAppl0(PME_afun34)), (ATerm) ((ATerm) PME_stringToChars(string)));
}

/*}}}  */
/*{{{  PME_Start PME_makeStartArea(PME_OptLayout wsBefore, PME_Area topArea, PME_OptLayout wsAfter, int ambCnt) */

PME_Start PME_makeStartArea(PME_OptLayout wsBefore, PME_Area topArea, PME_OptLayout wsAfter, int ambCnt)
{
  return (PME_Start)(ATerm)ATmakeAppl2(PME_afun38, (ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun28)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun39)), (ATerm)ATmakeAppl0(PME_afun34)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topArea), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  PME_Start PME_makeStartLocation(PME_OptLayout wsBefore, PME_Location topLocation, PME_OptLayout wsAfter, int ambCnt) */

PME_Start PME_makeStartLocation(PME_OptLayout wsBefore, PME_Location topLocation, PME_OptLayout wsAfter, int ambCnt)
{
  return (PME_Start)(ATerm)ATmakeAppl2(PME_afun38, (ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun24)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun39)), (ATerm)ATmakeAppl0(PME_afun34)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topLocation), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  PME_Start PME_makeStartSubject(PME_OptLayout wsBefore, PME_Subject topSubject, PME_OptLayout wsAfter, int ambCnt) */

PME_Start PME_makeStartSubject(PME_OptLayout wsBefore, PME_Subject topSubject, PME_OptLayout wsAfter, int ambCnt)
{
  return (PME_Start)(ATerm)ATmakeAppl2(PME_afun38, (ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun10)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun39)), (ATerm)ATmakeAppl0(PME_afun34)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topSubject), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  PME_Start PME_makeStartFeedback(PME_OptLayout wsBefore, PME_Feedback topFeedback, PME_OptLayout wsAfter, int ambCnt) */

PME_Start PME_makeStartFeedback(PME_OptLayout wsBefore, PME_Feedback topFeedback, PME_OptLayout wsAfter, int ambCnt)
{
  return (PME_Start)(ATerm)ATmakeAppl2(PME_afun38, (ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun16)))), (ATerm)ATmakeAppl1(PME_afun4, (ATerm)ATmakeAppl1(PME_afun5, (ATerm)ATmakeAppl0(PME_afun6)))), (ATerm)ATmakeAppl1(PME_afun9, (ATerm)ATmakeAppl0(PME_afun39)), (ATerm)ATmakeAppl0(PME_afun34)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm) wsAfter), (ATerm) topFeedback), (ATerm) wsBefore)), (ATerm) (ATerm) ATmakeInt(ambCnt));
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool PME_isEqualFeedback(PME_Feedback arg0, PME_Feedback arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PME_isEqualSubjectList(PME_SubjectList arg0, PME_SubjectList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PME_isEqualSubject(PME_Subject arg0, PME_Subject arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PME_isEqualLocation(PME_Location arg0, PME_Location arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PME_isEqualArea(PME_Area arg0, PME_Area arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PME_isEqualNatCon(PME_NatCon arg0, PME_NatCon arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PME_isEqualString(PME_String arg0, PME_String arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PME_isEqualOptLayout(PME_OptLayout arg0, PME_OptLayout arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PME_isEqualStart(PME_Start arg0, PME_Start arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  PME_Feedback accessors */

/*{{{  ATbool PME_isValidFeedback(PME_Feedback arg) */

ATbool PME_isValidFeedback(PME_Feedback arg)
{
  if (PME_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PME_isFeedbackInfo(PME_Feedback arg) */

inline ATbool PME_isFeedbackInfo(PME_Feedback arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PME_patternFeedbackInfo, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PME_isFeedbackWarning(PME_Feedback arg) */

inline ATbool PME_isFeedbackWarning(PME_Feedback arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PME_patternFeedbackWarning, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PME_isFeedbackError(PME_Feedback arg) */

inline ATbool PME_isFeedbackError(PME_Feedback arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PME_patternFeedbackError, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PME_isFeedbackFatalError(PME_Feedback arg) */

inline ATbool PME_isFeedbackFatalError(PME_Feedback arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PME_patternFeedbackFatalError, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PME_hasFeedbackWsAfterInfo(PME_Feedback arg) */

ATbool PME_hasFeedbackWsAfterInfo(PME_Feedback arg)
{
  if (PME_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getFeedbackWsAfterInfo(PME_Feedback arg) */

PME_OptLayout PME_getFeedbackWsAfterInfo(PME_Feedback arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PME_Feedback PME_setFeedbackWsAfterInfo(PME_Feedback arg, PME_OptLayout wsAfterInfo) */

PME_Feedback PME_setFeedbackWsAfterInfo(PME_Feedback arg, PME_OptLayout wsAfterInfo)
{
  if (PME_isFeedbackInfo(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterInfo), 1), 1);
  }

  ATabort("Feedback has no WsAfterInfo: %t\n", arg);
  return (PME_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasFeedbackWsAfterParenOpen(PME_Feedback arg) */

ATbool PME_hasFeedbackWsAfterParenOpen(PME_Feedback arg)
{
  if (PME_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getFeedbackWsAfterParenOpen(PME_Feedback arg) */

PME_OptLayout PME_getFeedbackWsAfterParenOpen(PME_Feedback arg)
{
  if (PME_isFeedbackInfo(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (PME_isFeedbackWarning(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else if (PME_isFeedbackError(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  PME_Feedback PME_setFeedbackWsAfterParenOpen(PME_Feedback arg, PME_OptLayout wsAfterParenOpen) */

PME_Feedback PME_setFeedbackWsAfterParenOpen(PME_Feedback arg, PME_OptLayout wsAfterParenOpen)
{
  if (PME_isFeedbackInfo(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PME_isFeedbackWarning(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PME_isFeedbackError(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PME_isFeedbackFatalError(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("Feedback has no WsAfterParenOpen: %t\n", arg);
  return (PME_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasFeedbackId(PME_Feedback arg) */

ATbool PME_hasFeedbackId(PME_Feedback arg)
{
  if (PME_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_String PME_getFeedbackId(PME_Feedback arg) */

PME_String PME_getFeedbackId(PME_Feedback arg)
{
  if (PME_isFeedbackInfo(arg)) {
    return (PME_String)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else if (PME_isFeedbackWarning(arg)) {
    return (PME_String)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else if (PME_isFeedbackError(arg)) {
    return (PME_String)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (PME_String)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PME_Feedback PME_setFeedbackId(PME_Feedback arg, PME_String id) */

PME_Feedback PME_setFeedbackId(PME_Feedback arg, PME_String id)
{
  if (PME_isFeedbackInfo(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) id), 4), 1);
  }
  else if (PME_isFeedbackWarning(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) id), 4), 1);
  }
  else if (PME_isFeedbackError(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) id), 4), 1);
  }
  else if (PME_isFeedbackFatalError(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) id), 4), 1);
  }

  ATabort("Feedback has no Id: %t\n", arg);
  return (PME_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasFeedbackWsAfterId(PME_Feedback arg) */

ATbool PME_hasFeedbackWsAfterId(PME_Feedback arg)
{
  if (PME_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getFeedbackWsAfterId(PME_Feedback arg) */

PME_OptLayout PME_getFeedbackWsAfterId(PME_Feedback arg)
{
  if (PME_isFeedbackInfo(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else if (PME_isFeedbackWarning(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else if (PME_isFeedbackError(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else 
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PME_Feedback PME_setFeedbackWsAfterId(PME_Feedback arg, PME_OptLayout wsAfterId) */

PME_Feedback PME_setFeedbackWsAfterId(PME_Feedback arg, PME_OptLayout wsAfterId)
{
  if (PME_isFeedbackInfo(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterId), 5), 1);
  }
  else if (PME_isFeedbackWarning(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterId), 5), 1);
  }
  else if (PME_isFeedbackError(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterId), 5), 1);
  }
  else if (PME_isFeedbackFatalError(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterId), 5), 1);
  }

  ATabort("Feedback has no WsAfterId: %t\n", arg);
  return (PME_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasFeedbackWsAfterComma(PME_Feedback arg) */

ATbool PME_hasFeedbackWsAfterComma(PME_Feedback arg)
{
  if (PME_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getFeedbackWsAfterComma(PME_Feedback arg) */

PME_OptLayout PME_getFeedbackWsAfterComma(PME_Feedback arg)
{
  if (PME_isFeedbackInfo(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else if (PME_isFeedbackWarning(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else if (PME_isFeedbackError(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
  }
  else 
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  PME_Feedback PME_setFeedbackWsAfterComma(PME_Feedback arg, PME_OptLayout wsAfterComma) */

PME_Feedback PME_setFeedbackWsAfterComma(PME_Feedback arg, PME_OptLayout wsAfterComma)
{
  if (PME_isFeedbackInfo(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }
  else if (PME_isFeedbackWarning(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }
  else if (PME_isFeedbackError(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }
  else if (PME_isFeedbackFatalError(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }

  ATabort("Feedback has no WsAfterComma: %t\n", arg);
  return (PME_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasFeedbackProducerId(PME_Feedback arg) */

ATbool PME_hasFeedbackProducerId(PME_Feedback arg)
{
  if (PME_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_String PME_getFeedbackProducerId(PME_Feedback arg) */

PME_String PME_getFeedbackProducerId(PME_Feedback arg)
{
  if (PME_isFeedbackInfo(arg)) {
    return (PME_String)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
  }
  else if (PME_isFeedbackWarning(arg)) {
    return (PME_String)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
  }
  else if (PME_isFeedbackError(arg)) {
    return (PME_String)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
  }
  else 
    return (PME_String)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/*}}}  */
/*{{{  PME_Feedback PME_setFeedbackProducerId(PME_Feedback arg, PME_String producerId) */

PME_Feedback PME_setFeedbackProducerId(PME_Feedback arg, PME_String producerId)
{
  if (PME_isFeedbackInfo(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) producerId), 8), 1);
  }
  else if (PME_isFeedbackWarning(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) producerId), 8), 1);
  }
  else if (PME_isFeedbackError(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) producerId), 8), 1);
  }
  else if (PME_isFeedbackFatalError(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) producerId), 8), 1);
  }

  ATabort("Feedback has no ProducerId: %t\n", arg);
  return (PME_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasFeedbackWsAfterProducerId(PME_Feedback arg) */

ATbool PME_hasFeedbackWsAfterProducerId(PME_Feedback arg)
{
  if (PME_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getFeedbackWsAfterProducerId(PME_Feedback arg) */

PME_OptLayout PME_getFeedbackWsAfterProducerId(PME_Feedback arg)
{
  if (PME_isFeedbackInfo(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
  }
  else if (PME_isFeedbackWarning(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
  }
  else if (PME_isFeedbackError(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
  }
  else 
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/*}}}  */
/*{{{  PME_Feedback PME_setFeedbackWsAfterProducerId(PME_Feedback arg, PME_OptLayout wsAfterProducerId) */

PME_Feedback PME_setFeedbackWsAfterProducerId(PME_Feedback arg, PME_OptLayout wsAfterProducerId)
{
  if (PME_isFeedbackInfo(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterProducerId), 9), 1);
  }
  else if (PME_isFeedbackWarning(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterProducerId), 9), 1);
  }
  else if (PME_isFeedbackError(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterProducerId), 9), 1);
  }
  else if (PME_isFeedbackFatalError(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterProducerId), 9), 1);
  }

  ATabort("Feedback has no WsAfterProducerId: %t\n", arg);
  return (PME_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasFeedbackWsAfterComma1(PME_Feedback arg) */

ATbool PME_hasFeedbackWsAfterComma1(PME_Feedback arg)
{
  if (PME_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getFeedbackWsAfterComma1(PME_Feedback arg) */

PME_OptLayout PME_getFeedbackWsAfterComma1(PME_Feedback arg)
{
  if (PME_isFeedbackInfo(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 11);
  }
  else if (PME_isFeedbackWarning(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 11);
  }
  else if (PME_isFeedbackError(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 11);
  }
  else 
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 11);
}

/*}}}  */
/*{{{  PME_Feedback PME_setFeedbackWsAfterComma1(PME_Feedback arg, PME_OptLayout wsAfterComma1) */

PME_Feedback PME_setFeedbackWsAfterComma1(PME_Feedback arg, PME_OptLayout wsAfterComma1)
{
  if (PME_isFeedbackInfo(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma1), 11), 1);
  }
  else if (PME_isFeedbackWarning(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma1), 11), 1);
  }
  else if (PME_isFeedbackError(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma1), 11), 1);
  }
  else if (PME_isFeedbackFatalError(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma1), 11), 1);
  }

  ATabort("Feedback has no WsAfterComma1: %t\n", arg);
  return (PME_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasFeedbackProducerType(PME_Feedback arg) */

ATbool PME_hasFeedbackProducerType(PME_Feedback arg)
{
  if (PME_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_String PME_getFeedbackProducerType(PME_Feedback arg) */

PME_String PME_getFeedbackProducerType(PME_Feedback arg)
{
  if (PME_isFeedbackInfo(arg)) {
    return (PME_String)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 12);
  }
  else if (PME_isFeedbackWarning(arg)) {
    return (PME_String)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 12);
  }
  else if (PME_isFeedbackError(arg)) {
    return (PME_String)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 12);
  }
  else 
    return (PME_String)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 12);
}

/*}}}  */
/*{{{  PME_Feedback PME_setFeedbackProducerType(PME_Feedback arg, PME_String producerType) */

PME_Feedback PME_setFeedbackProducerType(PME_Feedback arg, PME_String producerType)
{
  if (PME_isFeedbackInfo(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) producerType), 12), 1);
  }
  else if (PME_isFeedbackWarning(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) producerType), 12), 1);
  }
  else if (PME_isFeedbackError(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) producerType), 12), 1);
  }
  else if (PME_isFeedbackFatalError(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) producerType), 12), 1);
  }

  ATabort("Feedback has no ProducerType: %t\n", arg);
  return (PME_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasFeedbackWsAfterProducerType(PME_Feedback arg) */

ATbool PME_hasFeedbackWsAfterProducerType(PME_Feedback arg)
{
  if (PME_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getFeedbackWsAfterProducerType(PME_Feedback arg) */

PME_OptLayout PME_getFeedbackWsAfterProducerType(PME_Feedback arg)
{
  if (PME_isFeedbackInfo(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 13);
  }
  else if (PME_isFeedbackWarning(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 13);
  }
  else if (PME_isFeedbackError(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 13);
  }
  else 
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 13);
}

/*}}}  */
/*{{{  PME_Feedback PME_setFeedbackWsAfterProducerType(PME_Feedback arg, PME_OptLayout wsAfterProducerType) */

PME_Feedback PME_setFeedbackWsAfterProducerType(PME_Feedback arg, PME_OptLayout wsAfterProducerType)
{
  if (PME_isFeedbackInfo(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterProducerType), 13), 1);
  }
  else if (PME_isFeedbackWarning(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterProducerType), 13), 1);
  }
  else if (PME_isFeedbackError(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterProducerType), 13), 1);
  }
  else if (PME_isFeedbackFatalError(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterProducerType), 13), 1);
  }

  ATabort("Feedback has no WsAfterProducerType: %t\n", arg);
  return (PME_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasFeedbackWsAfterComma2(PME_Feedback arg) */

ATbool PME_hasFeedbackWsAfterComma2(PME_Feedback arg)
{
  if (PME_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getFeedbackWsAfterComma2(PME_Feedback arg) */

PME_OptLayout PME_getFeedbackWsAfterComma2(PME_Feedback arg)
{
  if (PME_isFeedbackInfo(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 15);
  }
  else if (PME_isFeedbackWarning(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 15);
  }
  else if (PME_isFeedbackError(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 15);
  }
  else 
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 15);
}

/*}}}  */
/*{{{  PME_Feedback PME_setFeedbackWsAfterComma2(PME_Feedback arg, PME_OptLayout wsAfterComma2) */

PME_Feedback PME_setFeedbackWsAfterComma2(PME_Feedback arg, PME_OptLayout wsAfterComma2)
{
  if (PME_isFeedbackInfo(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma2), 15), 1);
  }
  else if (PME_isFeedbackWarning(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma2), 15), 1);
  }
  else if (PME_isFeedbackError(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma2), 15), 1);
  }
  else if (PME_isFeedbackFatalError(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma2), 15), 1);
  }

  ATabort("Feedback has no WsAfterComma2: %t\n", arg);
  return (PME_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasFeedbackDescription(PME_Feedback arg) */

ATbool PME_hasFeedbackDescription(PME_Feedback arg)
{
  if (PME_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_String PME_getFeedbackDescription(PME_Feedback arg) */

PME_String PME_getFeedbackDescription(PME_Feedback arg)
{
  if (PME_isFeedbackInfo(arg)) {
    return (PME_String)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 16);
  }
  else if (PME_isFeedbackWarning(arg)) {
    return (PME_String)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 16);
  }
  else if (PME_isFeedbackError(arg)) {
    return (PME_String)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 16);
  }
  else 
    return (PME_String)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 16);
}

/*}}}  */
/*{{{  PME_Feedback PME_setFeedbackDescription(PME_Feedback arg, PME_String description) */

PME_Feedback PME_setFeedbackDescription(PME_Feedback arg, PME_String description)
{
  if (PME_isFeedbackInfo(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) description), 16), 1);
  }
  else if (PME_isFeedbackWarning(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) description), 16), 1);
  }
  else if (PME_isFeedbackError(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) description), 16), 1);
  }
  else if (PME_isFeedbackFatalError(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) description), 16), 1);
  }

  ATabort("Feedback has no Description: %t\n", arg);
  return (PME_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasFeedbackWsAfterDescription(PME_Feedback arg) */

ATbool PME_hasFeedbackWsAfterDescription(PME_Feedback arg)
{
  if (PME_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getFeedbackWsAfterDescription(PME_Feedback arg) */

PME_OptLayout PME_getFeedbackWsAfterDescription(PME_Feedback arg)
{
  if (PME_isFeedbackInfo(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 17);
  }
  else if (PME_isFeedbackWarning(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 17);
  }
  else if (PME_isFeedbackError(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 17);
  }
  else 
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 17);
}

/*}}}  */
/*{{{  PME_Feedback PME_setFeedbackWsAfterDescription(PME_Feedback arg, PME_OptLayout wsAfterDescription) */

PME_Feedback PME_setFeedbackWsAfterDescription(PME_Feedback arg, PME_OptLayout wsAfterDescription)
{
  if (PME_isFeedbackInfo(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterDescription), 17), 1);
  }
  else if (PME_isFeedbackWarning(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterDescription), 17), 1);
  }
  else if (PME_isFeedbackError(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterDescription), 17), 1);
  }
  else if (PME_isFeedbackFatalError(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterDescription), 17), 1);
  }

  ATabort("Feedback has no WsAfterDescription: %t\n", arg);
  return (PME_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasFeedbackWsAfterComma3(PME_Feedback arg) */

ATbool PME_hasFeedbackWsAfterComma3(PME_Feedback arg)
{
  if (PME_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getFeedbackWsAfterComma3(PME_Feedback arg) */

PME_OptLayout PME_getFeedbackWsAfterComma3(PME_Feedback arg)
{
  if (PME_isFeedbackInfo(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 19);
  }
  else if (PME_isFeedbackWarning(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 19);
  }
  else if (PME_isFeedbackError(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 19);
  }
  else 
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 19);
}

/*}}}  */
/*{{{  PME_Feedback PME_setFeedbackWsAfterComma3(PME_Feedback arg, PME_OptLayout wsAfterComma3) */

PME_Feedback PME_setFeedbackWsAfterComma3(PME_Feedback arg, PME_OptLayout wsAfterComma3)
{
  if (PME_isFeedbackInfo(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma3), 19), 1);
  }
  else if (PME_isFeedbackWarning(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma3), 19), 1);
  }
  else if (PME_isFeedbackError(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma3), 19), 1);
  }
  else if (PME_isFeedbackFatalError(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma3), 19), 1);
  }

  ATabort("Feedback has no WsAfterComma3: %t\n", arg);
  return (PME_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasFeedbackWsAfterBracketOpen(PME_Feedback arg) */

ATbool PME_hasFeedbackWsAfterBracketOpen(PME_Feedback arg)
{
  if (PME_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getFeedbackWsAfterBracketOpen(PME_Feedback arg) */

PME_OptLayout PME_getFeedbackWsAfterBracketOpen(PME_Feedback arg)
{
  if (PME_isFeedbackInfo(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 21);
  }
  else if (PME_isFeedbackWarning(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 21);
  }
  else if (PME_isFeedbackError(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 21);
  }
  else 
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 21);
}

/*}}}  */
/*{{{  PME_Feedback PME_setFeedbackWsAfterBracketOpen(PME_Feedback arg, PME_OptLayout wsAfterBracketOpen) */

PME_Feedback PME_setFeedbackWsAfterBracketOpen(PME_Feedback arg, PME_OptLayout wsAfterBracketOpen)
{
  if (PME_isFeedbackInfo(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 21), 1);
  }
  else if (PME_isFeedbackWarning(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 21), 1);
  }
  else if (PME_isFeedbackError(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 21), 1);
  }
  else if (PME_isFeedbackFatalError(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketOpen), 21), 1);
  }

  ATabort("Feedback has no WsAfterBracketOpen: %t\n", arg);
  return (PME_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasFeedbackList(PME_Feedback arg) */

ATbool PME_hasFeedbackList(PME_Feedback arg)
{
  if (PME_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_SubjectList PME_getFeedbackList(PME_Feedback arg) */

PME_SubjectList PME_getFeedbackList(PME_Feedback arg)
{
  if (PME_isFeedbackInfo(arg)) {
    return (PME_SubjectList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 22), 1);
  }
  else if (PME_isFeedbackWarning(arg)) {
    return (PME_SubjectList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 22), 1);
  }
  else if (PME_isFeedbackError(arg)) {
    return (PME_SubjectList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 22), 1);
  }
  else 
    return (PME_SubjectList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 22), 1);
}

/*}}}  */
/*{{{  PME_Feedback PME_setFeedbackList(PME_Feedback arg, PME_SubjectList list) */

PME_Feedback PME_setFeedbackList(PME_Feedback arg, PME_SubjectList list)
{
  if (PME_isFeedbackInfo(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 22), (ATerm)((ATerm) list), 1), 22), 1);
  }
  else if (PME_isFeedbackWarning(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 22), (ATerm)((ATerm) list), 1), 22), 1);
  }
  else if (PME_isFeedbackError(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 22), (ATerm)((ATerm) list), 1), 22), 1);
  }
  else if (PME_isFeedbackFatalError(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 22), (ATerm)((ATerm) list), 1), 22), 1);
  }

  ATabort("Feedback has no List: %t\n", arg);
  return (PME_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasFeedbackWsAfterList(PME_Feedback arg) */

ATbool PME_hasFeedbackWsAfterList(PME_Feedback arg)
{
  if (PME_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getFeedbackWsAfterList(PME_Feedback arg) */

PME_OptLayout PME_getFeedbackWsAfterList(PME_Feedback arg)
{
  if (PME_isFeedbackInfo(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 23);
  }
  else if (PME_isFeedbackWarning(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 23);
  }
  else if (PME_isFeedbackError(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 23);
  }
  else 
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 23);
}

/*}}}  */
/*{{{  PME_Feedback PME_setFeedbackWsAfterList(PME_Feedback arg, PME_OptLayout wsAfterList) */

PME_Feedback PME_setFeedbackWsAfterList(PME_Feedback arg, PME_OptLayout wsAfterList)
{
  if (PME_isFeedbackInfo(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterList), 23), 1);
  }
  else if (PME_isFeedbackWarning(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterList), 23), 1);
  }
  else if (PME_isFeedbackError(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterList), 23), 1);
  }
  else if (PME_isFeedbackFatalError(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterList), 23), 1);
  }

  ATabort("Feedback has no WsAfterList: %t\n", arg);
  return (PME_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasFeedbackWsAfterBracketClose(PME_Feedback arg) */

ATbool PME_hasFeedbackWsAfterBracketClose(PME_Feedback arg)
{
  if (PME_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (PME_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getFeedbackWsAfterBracketClose(PME_Feedback arg) */

PME_OptLayout PME_getFeedbackWsAfterBracketClose(PME_Feedback arg)
{
  if (PME_isFeedbackInfo(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 25);
  }
  else if (PME_isFeedbackWarning(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 25);
  }
  else if (PME_isFeedbackError(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 25);
  }
  else 
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 25);
}

/*}}}  */
/*{{{  PME_Feedback PME_setFeedbackWsAfterBracketClose(PME_Feedback arg, PME_OptLayout wsAfterBracketClose) */

PME_Feedback PME_setFeedbackWsAfterBracketClose(PME_Feedback arg, PME_OptLayout wsAfterBracketClose)
{
  if (PME_isFeedbackInfo(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketClose), 25), 1);
  }
  else if (PME_isFeedbackWarning(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketClose), 25), 1);
  }
  else if (PME_isFeedbackError(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketClose), 25), 1);
  }
  else if (PME_isFeedbackFatalError(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterBracketClose), 25), 1);
  }

  ATabort("Feedback has no WsAfterBracketClose: %t\n", arg);
  return (PME_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasFeedbackWsAfterWarning(PME_Feedback arg) */

ATbool PME_hasFeedbackWsAfterWarning(PME_Feedback arg)
{
  if (PME_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getFeedbackWsAfterWarning(PME_Feedback arg) */

PME_OptLayout PME_getFeedbackWsAfterWarning(PME_Feedback arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PME_Feedback PME_setFeedbackWsAfterWarning(PME_Feedback arg, PME_OptLayout wsAfterWarning) */

PME_Feedback PME_setFeedbackWsAfterWarning(PME_Feedback arg, PME_OptLayout wsAfterWarning)
{
  if (PME_isFeedbackWarning(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterWarning), 1), 1);
  }

  ATabort("Feedback has no WsAfterWarning: %t\n", arg);
  return (PME_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasFeedbackWsAfterError(PME_Feedback arg) */

ATbool PME_hasFeedbackWsAfterError(PME_Feedback arg)
{
  if (PME_isFeedbackError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getFeedbackWsAfterError(PME_Feedback arg) */

PME_OptLayout PME_getFeedbackWsAfterError(PME_Feedback arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PME_Feedback PME_setFeedbackWsAfterError(PME_Feedback arg, PME_OptLayout wsAfterError) */

PME_Feedback PME_setFeedbackWsAfterError(PME_Feedback arg, PME_OptLayout wsAfterError)
{
  if (PME_isFeedbackError(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterError), 1), 1);
  }

  ATabort("Feedback has no WsAfterError: %t\n", arg);
  return (PME_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasFeedbackWsAfterFatalError(PME_Feedback arg) */

ATbool PME_hasFeedbackWsAfterFatalError(PME_Feedback arg)
{
  if (PME_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getFeedbackWsAfterFatalError(PME_Feedback arg) */

PME_OptLayout PME_getFeedbackWsAfterFatalError(PME_Feedback arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PME_Feedback PME_setFeedbackWsAfterFatalError(PME_Feedback arg, PME_OptLayout wsAfterFatalError) */

PME_Feedback PME_setFeedbackWsAfterFatalError(PME_Feedback arg, PME_OptLayout wsAfterFatalError)
{
  if (PME_isFeedbackFatalError(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterFatalError), 1), 1);
  }

  ATabort("Feedback has no WsAfterFatalError: %t\n", arg);
  return (PME_Feedback)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PME_SubjectList accessors */

/*{{{  ATbool PME_isValidSubjectList(PME_SubjectList arg) */

ATbool PME_isValidSubjectList(PME_SubjectList arg)
{
  if (PME_isSubjectListEmpty(arg)) {
    return ATtrue;
  }
  else if (PME_isSubjectListSingle(arg)) {
    return ATtrue;
  }
  else if (PME_isSubjectListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PME_isSubjectListEmpty(PME_SubjectList arg) */

inline ATbool PME_isSubjectListEmpty(PME_SubjectList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PME_patternSubjectListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool PME_isSubjectListSingle(PME_SubjectList arg) */

inline ATbool PME_isSubjectListSingle(PME_SubjectList arg)
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
      last_result = ATmatchTerm((ATerm)arg, PME_patternSubjectListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PME_isSubjectListMany(PME_SubjectList arg) */

inline ATbool PME_isSubjectListMany(PME_SubjectList arg)
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
      last_result = ATmatchTerm((ATerm)arg, PME_patternSubjectListMany, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PME_hasSubjectListHead(PME_SubjectList arg) */

ATbool PME_hasSubjectListHead(PME_SubjectList arg)
{
  if (PME_isSubjectListSingle(arg)) {
    return ATtrue;
  }
  else if (PME_isSubjectListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_Subject PME_getSubjectListHead(PME_SubjectList arg) */

PME_Subject PME_getSubjectListHead(PME_SubjectList arg)
{
  if (PME_isSubjectListSingle(arg)) {
    return (PME_Subject)ATgetFirst((ATermList)arg);
  }
  else 
    return (PME_Subject)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  PME_SubjectList PME_setSubjectListHead(PME_SubjectList arg, PME_Subject head) */

PME_SubjectList PME_setSubjectListHead(PME_SubjectList arg, PME_Subject head)
{
  if (PME_isSubjectListSingle(arg)) {
    return (PME_SubjectList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (PME_isSubjectListMany(arg)) {
    return (PME_SubjectList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("SubjectList has no Head: %t\n", arg);
  return (PME_SubjectList)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasSubjectListWsAfterHead(PME_SubjectList arg) */

ATbool PME_hasSubjectListWsAfterHead(PME_SubjectList arg)
{
  if (PME_isSubjectListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getSubjectListWsAfterHead(PME_SubjectList arg) */

PME_OptLayout PME_getSubjectListWsAfterHead(PME_SubjectList arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  PME_SubjectList PME_setSubjectListWsAfterHead(PME_SubjectList arg, PME_OptLayout wsAfterHead) */

PME_SubjectList PME_setSubjectListWsAfterHead(PME_SubjectList arg, PME_OptLayout wsAfterHead)
{
  if (PME_isSubjectListMany(arg)) {
    return (PME_SubjectList)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterHead), 1);
  }

  ATabort("SubjectList has no WsAfterHead: %t\n", arg);
  return (PME_SubjectList)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasSubjectListWsAfterSep(PME_SubjectList arg) */

ATbool PME_hasSubjectListWsAfterSep(PME_SubjectList arg)
{
  if (PME_isSubjectListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getSubjectListWsAfterSep(PME_SubjectList arg) */

PME_OptLayout PME_getSubjectListWsAfterSep(PME_SubjectList arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  PME_SubjectList PME_setSubjectListWsAfterSep(PME_SubjectList arg, PME_OptLayout wsAfterSep) */

PME_SubjectList PME_setSubjectListWsAfterSep(PME_SubjectList arg, PME_OptLayout wsAfterSep)
{
  if (PME_isSubjectListMany(arg)) {
    return (PME_SubjectList)ATreplace((ATermList)arg, (ATerm)((ATerm) wsAfterSep), 3);
  }

  ATabort("SubjectList has no WsAfterSep: %t\n", arg);
  return (PME_SubjectList)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasSubjectListTail(PME_SubjectList arg) */

ATbool PME_hasSubjectListTail(PME_SubjectList arg)
{
  if (PME_isSubjectListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_SubjectList PME_getSubjectListTail(PME_SubjectList arg) */

PME_SubjectList PME_getSubjectListTail(PME_SubjectList arg)
{
  
    return (PME_SubjectList)ATgetTail((ATermList)arg, 4);
}

/*}}}  */
/*{{{  PME_SubjectList PME_setSubjectListTail(PME_SubjectList arg, PME_SubjectList tail) */

PME_SubjectList PME_setSubjectListTail(PME_SubjectList arg, PME_SubjectList tail)
{
  if (PME_isSubjectListMany(arg)) {
    return (PME_SubjectList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 4);
  }

  ATabort("SubjectList has no Tail: %t\n", arg);
  return (PME_SubjectList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PME_Subject accessors */

/*{{{  ATbool PME_isValidSubject(PME_Subject arg) */

ATbool PME_isValidSubject(PME_Subject arg)
{
  if (PME_isSubjectLocatable(arg)) {
    return ATtrue;
  }
  else if (PME_isSubjectUnlocatable(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PME_isSubjectLocatable(PME_Subject arg) */

inline ATbool PME_isSubjectLocatable(PME_Subject arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PME_patternSubjectLocatable, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PME_isSubjectUnlocatable(PME_Subject arg) */

inline ATbool PME_isSubjectUnlocatable(PME_Subject arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PME_patternSubjectUnlocatable, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PME_hasSubjectWsAfterSubject(PME_Subject arg) */

ATbool PME_hasSubjectWsAfterSubject(PME_Subject arg)
{
  if (PME_isSubjectLocatable(arg)) {
    return ATtrue;
  }
  else if (PME_isSubjectUnlocatable(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getSubjectWsAfterSubject(PME_Subject arg) */

PME_OptLayout PME_getSubjectWsAfterSubject(PME_Subject arg)
{
  if (PME_isSubjectLocatable(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else 
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PME_Subject PME_setSubjectWsAfterSubject(PME_Subject arg, PME_OptLayout wsAfterSubject) */

PME_Subject PME_setSubjectWsAfterSubject(PME_Subject arg, PME_OptLayout wsAfterSubject)
{
  if (PME_isSubjectLocatable(arg)) {
    return (PME_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSubject), 1), 1);
  }
  else if (PME_isSubjectUnlocatable(arg)) {
    return (PME_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterSubject), 1), 1);
  }

  ATabort("Subject has no WsAfterSubject: %t\n", arg);
  return (PME_Subject)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasSubjectWsAfterParenOpen(PME_Subject arg) */

ATbool PME_hasSubjectWsAfterParenOpen(PME_Subject arg)
{
  if (PME_isSubjectLocatable(arg)) {
    return ATtrue;
  }
  else if (PME_isSubjectUnlocatable(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getSubjectWsAfterParenOpen(PME_Subject arg) */

PME_OptLayout PME_getSubjectWsAfterParenOpen(PME_Subject arg)
{
  if (PME_isSubjectLocatable(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  PME_Subject PME_setSubjectWsAfterParenOpen(PME_Subject arg, PME_OptLayout wsAfterParenOpen) */

PME_Subject PME_setSubjectWsAfterParenOpen(PME_Subject arg, PME_OptLayout wsAfterParenOpen)
{
  if (PME_isSubjectLocatable(arg)) {
    return (PME_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }
  else if (PME_isSubjectUnlocatable(arg)) {
    return (PME_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("Subject has no WsAfterParenOpen: %t\n", arg);
  return (PME_Subject)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasSubjectId(PME_Subject arg) */

ATbool PME_hasSubjectId(PME_Subject arg)
{
  if (PME_isSubjectLocatable(arg)) {
    return ATtrue;
  }
  else if (PME_isSubjectUnlocatable(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_String PME_getSubjectId(PME_Subject arg) */

PME_String PME_getSubjectId(PME_Subject arg)
{
  if (PME_isSubjectLocatable(arg)) {
    return (PME_String)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (PME_String)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PME_Subject PME_setSubjectId(PME_Subject arg, PME_String id) */

PME_Subject PME_setSubjectId(PME_Subject arg, PME_String id)
{
  if (PME_isSubjectLocatable(arg)) {
    return (PME_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) id), 4), 1);
  }
  else if (PME_isSubjectUnlocatable(arg)) {
    return (PME_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) id), 4), 1);
  }

  ATabort("Subject has no Id: %t\n", arg);
  return (PME_Subject)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasSubjectWsAfterId(PME_Subject arg) */

ATbool PME_hasSubjectWsAfterId(PME_Subject arg)
{
  if (PME_isSubjectLocatable(arg)) {
    return ATtrue;
  }
  else if (PME_isSubjectUnlocatable(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getSubjectWsAfterId(PME_Subject arg) */

PME_OptLayout PME_getSubjectWsAfterId(PME_Subject arg)
{
  if (PME_isSubjectLocatable(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else 
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PME_Subject PME_setSubjectWsAfterId(PME_Subject arg, PME_OptLayout wsAfterId) */

PME_Subject PME_setSubjectWsAfterId(PME_Subject arg, PME_OptLayout wsAfterId)
{
  if (PME_isSubjectLocatable(arg)) {
    return (PME_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterId), 5), 1);
  }
  else if (PME_isSubjectUnlocatable(arg)) {
    return (PME_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterId), 5), 1);
  }

  ATabort("Subject has no WsAfterId: %t\n", arg);
  return (PME_Subject)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasSubjectWsAfterComma(PME_Subject arg) */

ATbool PME_hasSubjectWsAfterComma(PME_Subject arg)
{
  if (PME_isSubjectLocatable(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getSubjectWsAfterComma(PME_Subject arg) */

PME_OptLayout PME_getSubjectWsAfterComma(PME_Subject arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  PME_Subject PME_setSubjectWsAfterComma(PME_Subject arg, PME_OptLayout wsAfterComma) */

PME_Subject PME_setSubjectWsAfterComma(PME_Subject arg, PME_OptLayout wsAfterComma)
{
  if (PME_isSubjectLocatable(arg)) {
    return (PME_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }

  ATabort("Subject has no WsAfterComma: %t\n", arg);
  return (PME_Subject)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasSubjectLocation(PME_Subject arg) */

ATbool PME_hasSubjectLocation(PME_Subject arg)
{
  if (PME_isSubjectLocatable(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_Location PME_getSubjectLocation(PME_Subject arg) */

PME_Location PME_getSubjectLocation(PME_Subject arg)
{
  
    return (PME_Location)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/*}}}  */
/*{{{  PME_Subject PME_setSubjectLocation(PME_Subject arg, PME_Location Location) */

PME_Subject PME_setSubjectLocation(PME_Subject arg, PME_Location Location)
{
  if (PME_isSubjectLocatable(arg)) {
    return (PME_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Location), 8), 1);
  }

  ATabort("Subject has no Location: %t\n", arg);
  return (PME_Subject)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasSubjectWsAfterLocation(PME_Subject arg) */

ATbool PME_hasSubjectWsAfterLocation(PME_Subject arg)
{
  if (PME_isSubjectLocatable(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getSubjectWsAfterLocation(PME_Subject arg) */

PME_OptLayout PME_getSubjectWsAfterLocation(PME_Subject arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/*}}}  */
/*{{{  PME_Subject PME_setSubjectWsAfterLocation(PME_Subject arg, PME_OptLayout wsAfterLocation) */

PME_Subject PME_setSubjectWsAfterLocation(PME_Subject arg, PME_OptLayout wsAfterLocation)
{
  if (PME_isSubjectLocatable(arg)) {
    return (PME_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLocation), 9), 1);
  }

  ATabort("Subject has no WsAfterLocation: %t\n", arg);
  return (PME_Subject)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PME_Location accessors */

/*{{{  ATbool PME_isValidLocation(PME_Location arg) */

ATbool PME_isValidLocation(PME_Location arg)
{
  if (PME_isLocationLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PME_isLocationLocation(PME_Location arg) */

inline ATbool PME_isLocationLocation(PME_Location arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PME_patternLocationLocation, NULL, NULL, NULL, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PME_hasLocationWsAfterLocation(PME_Location arg) */

ATbool PME_hasLocationWsAfterLocation(PME_Location arg)
{
  if (PME_isLocationLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getLocationWsAfterLocation(PME_Location arg) */

PME_OptLayout PME_getLocationWsAfterLocation(PME_Location arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PME_Location PME_setLocationWsAfterLocation(PME_Location arg, PME_OptLayout wsAfterLocation) */

PME_Location PME_setLocationWsAfterLocation(PME_Location arg, PME_OptLayout wsAfterLocation)
{
  if (PME_isLocationLocation(arg)) {
    return (PME_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterLocation), 1), 1);
  }

  ATabort("Location has no WsAfterLocation: %t\n", arg);
  return (PME_Location)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasLocationWsAfterParenOpen(PME_Location arg) */

ATbool PME_hasLocationWsAfterParenOpen(PME_Location arg)
{
  if (PME_isLocationLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getLocationWsAfterParenOpen(PME_Location arg) */

PME_OptLayout PME_getLocationWsAfterParenOpen(PME_Location arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  PME_Location PME_setLocationWsAfterParenOpen(PME_Location arg, PME_OptLayout wsAfterParenOpen) */

PME_Location PME_setLocationWsAfterParenOpen(PME_Location arg, PME_OptLayout wsAfterParenOpen)
{
  if (PME_isLocationLocation(arg)) {
    return (PME_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("Location has no WsAfterParenOpen: %t\n", arg);
  return (PME_Location)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasLocationFilename(PME_Location arg) */

ATbool PME_hasLocationFilename(PME_Location arg)
{
  if (PME_isLocationLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_String PME_getLocationFilename(PME_Location arg) */

PME_String PME_getLocationFilename(PME_Location arg)
{
  
    return (PME_String)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PME_Location PME_setLocationFilename(PME_Location arg, PME_String filename) */

PME_Location PME_setLocationFilename(PME_Location arg, PME_String filename)
{
  if (PME_isLocationLocation(arg)) {
    return (PME_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) filename), 4), 1);
  }

  ATabort("Location has no Filename: %t\n", arg);
  return (PME_Location)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasLocationWsAfterFilename(PME_Location arg) */

ATbool PME_hasLocationWsAfterFilename(PME_Location arg)
{
  if (PME_isLocationLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getLocationWsAfterFilename(PME_Location arg) */

PME_OptLayout PME_getLocationWsAfterFilename(PME_Location arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PME_Location PME_setLocationWsAfterFilename(PME_Location arg, PME_OptLayout wsAfterFilename) */

PME_Location PME_setLocationWsAfterFilename(PME_Location arg, PME_OptLayout wsAfterFilename)
{
  if (PME_isLocationLocation(arg)) {
    return (PME_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterFilename), 5), 1);
  }

  ATabort("Location has no WsAfterFilename: %t\n", arg);
  return (PME_Location)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasLocationWsAfterComma(PME_Location arg) */

ATbool PME_hasLocationWsAfterComma(PME_Location arg)
{
  if (PME_isLocationLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getLocationWsAfterComma(PME_Location arg) */

PME_OptLayout PME_getLocationWsAfterComma(PME_Location arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  PME_Location PME_setLocationWsAfterComma(PME_Location arg, PME_OptLayout wsAfterComma) */

PME_Location PME_setLocationWsAfterComma(PME_Location arg, PME_OptLayout wsAfterComma)
{
  if (PME_isLocationLocation(arg)) {
    return (PME_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }

  ATabort("Location has no WsAfterComma: %t\n", arg);
  return (PME_Location)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasLocationArea(PME_Location arg) */

ATbool PME_hasLocationArea(PME_Location arg)
{
  if (PME_isLocationLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_Area PME_getLocationArea(PME_Location arg) */

PME_Area PME_getLocationArea(PME_Location arg)
{
  
    return (PME_Area)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/*}}}  */
/*{{{  PME_Location PME_setLocationArea(PME_Location arg, PME_Area Area) */

PME_Location PME_setLocationArea(PME_Location arg, PME_Area Area)
{
  if (PME_isLocationLocation(arg)) {
    return (PME_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) Area), 8), 1);
  }

  ATabort("Location has no Area: %t\n", arg);
  return (PME_Location)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasLocationWsAfterArea(PME_Location arg) */

ATbool PME_hasLocationWsAfterArea(PME_Location arg)
{
  if (PME_isLocationLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getLocationWsAfterArea(PME_Location arg) */

PME_OptLayout PME_getLocationWsAfterArea(PME_Location arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/*}}}  */
/*{{{  PME_Location PME_setLocationWsAfterArea(PME_Location arg, PME_OptLayout wsAfterArea) */

PME_Location PME_setLocationWsAfterArea(PME_Location arg, PME_OptLayout wsAfterArea)
{
  if (PME_isLocationLocation(arg)) {
    return (PME_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterArea), 9), 1);
  }

  ATabort("Location has no WsAfterArea: %t\n", arg);
  return (PME_Location)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PME_Area accessors */

/*{{{  ATbool PME_isValidArea(PME_Area arg) */

ATbool PME_isValidArea(PME_Area arg)
{
  if (PME_isAreaArea(arg)) {
    return ATtrue;
  }
  else if (PME_isAreaNoArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PME_isAreaArea(PME_Area arg) */

inline ATbool PME_isAreaArea(PME_Area arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PME_patternAreaArea, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PME_isAreaNoArea(PME_Area arg) */

inline ATbool PME_isAreaNoArea(PME_Area arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PME_patternAreaNoArea);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PME_hasAreaWsAfterArea(PME_Area arg) */

ATbool PME_hasAreaWsAfterArea(PME_Area arg)
{
  if (PME_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getAreaWsAfterArea(PME_Area arg) */

PME_OptLayout PME_getAreaWsAfterArea(PME_Area arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PME_Area PME_setAreaWsAfterArea(PME_Area arg, PME_OptLayout wsAfterArea) */

PME_Area PME_setAreaWsAfterArea(PME_Area arg, PME_OptLayout wsAfterArea)
{
  if (PME_isAreaArea(arg)) {
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterArea), 1), 1);
  }

  ATabort("Area has no WsAfterArea: %t\n", arg);
  return (PME_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasAreaWsAfterParenOpen(PME_Area arg) */

ATbool PME_hasAreaWsAfterParenOpen(PME_Area arg)
{
  if (PME_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getAreaWsAfterParenOpen(PME_Area arg) */

PME_OptLayout PME_getAreaWsAfterParenOpen(PME_Area arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  PME_Area PME_setAreaWsAfterParenOpen(PME_Area arg, PME_OptLayout wsAfterParenOpen) */

PME_Area PME_setAreaWsAfterParenOpen(PME_Area arg, PME_OptLayout wsAfterParenOpen)
{
  if (PME_isAreaArea(arg)) {
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterParenOpen), 3), 1);
  }

  ATabort("Area has no WsAfterParenOpen: %t\n", arg);
  return (PME_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasAreaStartLine(PME_Area arg) */

ATbool PME_hasAreaStartLine(PME_Area arg)
{
  if (PME_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_NatCon PME_getAreaStartLine(PME_Area arg) */

PME_NatCon PME_getAreaStartLine(PME_Area arg)
{
  
    return (PME_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PME_Area PME_setAreaStartLine(PME_Area arg, PME_NatCon startLine) */

PME_Area PME_setAreaStartLine(PME_Area arg, PME_NatCon startLine)
{
  if (PME_isAreaArea(arg)) {
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) startLine), 4), 1);
  }

  ATabort("Area has no StartLine: %t\n", arg);
  return (PME_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasAreaWsAfterStartLine(PME_Area arg) */

ATbool PME_hasAreaWsAfterStartLine(PME_Area arg)
{
  if (PME_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getAreaWsAfterStartLine(PME_Area arg) */

PME_OptLayout PME_getAreaWsAfterStartLine(PME_Area arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PME_Area PME_setAreaWsAfterStartLine(PME_Area arg, PME_OptLayout wsAfterStartLine) */

PME_Area PME_setAreaWsAfterStartLine(PME_Area arg, PME_OptLayout wsAfterStartLine)
{
  if (PME_isAreaArea(arg)) {
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterStartLine), 5), 1);
  }

  ATabort("Area has no WsAfterStartLine: %t\n", arg);
  return (PME_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasAreaWsAfterComma(PME_Area arg) */

ATbool PME_hasAreaWsAfterComma(PME_Area arg)
{
  if (PME_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getAreaWsAfterComma(PME_Area arg) */

PME_OptLayout PME_getAreaWsAfterComma(PME_Area arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  PME_Area PME_setAreaWsAfterComma(PME_Area arg, PME_OptLayout wsAfterComma) */

PME_Area PME_setAreaWsAfterComma(PME_Area arg, PME_OptLayout wsAfterComma)
{
  if (PME_isAreaArea(arg)) {
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma), 7), 1);
  }

  ATabort("Area has no WsAfterComma: %t\n", arg);
  return (PME_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasAreaStartColumn(PME_Area arg) */

ATbool PME_hasAreaStartColumn(PME_Area arg)
{
  if (PME_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_NatCon PME_getAreaStartColumn(PME_Area arg) */

PME_NatCon PME_getAreaStartColumn(PME_Area arg)
{
  
    return (PME_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/*}}}  */
/*{{{  PME_Area PME_setAreaStartColumn(PME_Area arg, PME_NatCon startColumn) */

PME_Area PME_setAreaStartColumn(PME_Area arg, PME_NatCon startColumn)
{
  if (PME_isAreaArea(arg)) {
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) startColumn), 8), 1);
  }

  ATabort("Area has no StartColumn: %t\n", arg);
  return (PME_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasAreaWsAfterStartColumn(PME_Area arg) */

ATbool PME_hasAreaWsAfterStartColumn(PME_Area arg)
{
  if (PME_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getAreaWsAfterStartColumn(PME_Area arg) */

PME_OptLayout PME_getAreaWsAfterStartColumn(PME_Area arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/*}}}  */
/*{{{  PME_Area PME_setAreaWsAfterStartColumn(PME_Area arg, PME_OptLayout wsAfterStartColumn) */

PME_Area PME_setAreaWsAfterStartColumn(PME_Area arg, PME_OptLayout wsAfterStartColumn)
{
  if (PME_isAreaArea(arg)) {
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterStartColumn), 9), 1);
  }

  ATabort("Area has no WsAfterStartColumn: %t\n", arg);
  return (PME_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasAreaWsAfterComma1(PME_Area arg) */

ATbool PME_hasAreaWsAfterComma1(PME_Area arg)
{
  if (PME_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getAreaWsAfterComma1(PME_Area arg) */

PME_OptLayout PME_getAreaWsAfterComma1(PME_Area arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 11);
}

/*}}}  */
/*{{{  PME_Area PME_setAreaWsAfterComma1(PME_Area arg, PME_OptLayout wsAfterComma1) */

PME_Area PME_setAreaWsAfterComma1(PME_Area arg, PME_OptLayout wsAfterComma1)
{
  if (PME_isAreaArea(arg)) {
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma1), 11), 1);
  }

  ATabort("Area has no WsAfterComma1: %t\n", arg);
  return (PME_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasAreaEndLine(PME_Area arg) */

ATbool PME_hasAreaEndLine(PME_Area arg)
{
  if (PME_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_NatCon PME_getAreaEndLine(PME_Area arg) */

PME_NatCon PME_getAreaEndLine(PME_Area arg)
{
  
    return (PME_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 12);
}

/*}}}  */
/*{{{  PME_Area PME_setAreaEndLine(PME_Area arg, PME_NatCon endLine) */

PME_Area PME_setAreaEndLine(PME_Area arg, PME_NatCon endLine)
{
  if (PME_isAreaArea(arg)) {
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) endLine), 12), 1);
  }

  ATabort("Area has no EndLine: %t\n", arg);
  return (PME_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasAreaWsAfterEndLine(PME_Area arg) */

ATbool PME_hasAreaWsAfterEndLine(PME_Area arg)
{
  if (PME_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getAreaWsAfterEndLine(PME_Area arg) */

PME_OptLayout PME_getAreaWsAfterEndLine(PME_Area arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 13);
}

/*}}}  */
/*{{{  PME_Area PME_setAreaWsAfterEndLine(PME_Area arg, PME_OptLayout wsAfterEndLine) */

PME_Area PME_setAreaWsAfterEndLine(PME_Area arg, PME_OptLayout wsAfterEndLine)
{
  if (PME_isAreaArea(arg)) {
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterEndLine), 13), 1);
  }

  ATabort("Area has no WsAfterEndLine: %t\n", arg);
  return (PME_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasAreaWsAfterComma2(PME_Area arg) */

ATbool PME_hasAreaWsAfterComma2(PME_Area arg)
{
  if (PME_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getAreaWsAfterComma2(PME_Area arg) */

PME_OptLayout PME_getAreaWsAfterComma2(PME_Area arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 15);
}

/*}}}  */
/*{{{  PME_Area PME_setAreaWsAfterComma2(PME_Area arg, PME_OptLayout wsAfterComma2) */

PME_Area PME_setAreaWsAfterComma2(PME_Area arg, PME_OptLayout wsAfterComma2)
{
  if (PME_isAreaArea(arg)) {
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma2), 15), 1);
  }

  ATabort("Area has no WsAfterComma2: %t\n", arg);
  return (PME_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasAreaEndColumn(PME_Area arg) */

ATbool PME_hasAreaEndColumn(PME_Area arg)
{
  if (PME_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_NatCon PME_getAreaEndColumn(PME_Area arg) */

PME_NatCon PME_getAreaEndColumn(PME_Area arg)
{
  
    return (PME_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 16);
}

/*}}}  */
/*{{{  PME_Area PME_setAreaEndColumn(PME_Area arg, PME_NatCon endColumn) */

PME_Area PME_setAreaEndColumn(PME_Area arg, PME_NatCon endColumn)
{
  if (PME_isAreaArea(arg)) {
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) endColumn), 16), 1);
  }

  ATabort("Area has no EndColumn: %t\n", arg);
  return (PME_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasAreaWsAfterEndColumn(PME_Area arg) */

ATbool PME_hasAreaWsAfterEndColumn(PME_Area arg)
{
  if (PME_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getAreaWsAfterEndColumn(PME_Area arg) */

PME_OptLayout PME_getAreaWsAfterEndColumn(PME_Area arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 17);
}

/*}}}  */
/*{{{  PME_Area PME_setAreaWsAfterEndColumn(PME_Area arg, PME_OptLayout wsAfterEndColumn) */

PME_Area PME_setAreaWsAfterEndColumn(PME_Area arg, PME_OptLayout wsAfterEndColumn)
{
  if (PME_isAreaArea(arg)) {
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterEndColumn), 17), 1);
  }

  ATabort("Area has no WsAfterEndColumn: %t\n", arg);
  return (PME_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasAreaWsAfterComma3(PME_Area arg) */

ATbool PME_hasAreaWsAfterComma3(PME_Area arg)
{
  if (PME_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getAreaWsAfterComma3(PME_Area arg) */

PME_OptLayout PME_getAreaWsAfterComma3(PME_Area arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 19);
}

/*}}}  */
/*{{{  PME_Area PME_setAreaWsAfterComma3(PME_Area arg, PME_OptLayout wsAfterComma3) */

PME_Area PME_setAreaWsAfterComma3(PME_Area arg, PME_OptLayout wsAfterComma3)
{
  if (PME_isAreaArea(arg)) {
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma3), 19), 1);
  }

  ATabort("Area has no WsAfterComma3: %t\n", arg);
  return (PME_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasAreaStartOffset(PME_Area arg) */

ATbool PME_hasAreaStartOffset(PME_Area arg)
{
  if (PME_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_NatCon PME_getAreaStartOffset(PME_Area arg) */

PME_NatCon PME_getAreaStartOffset(PME_Area arg)
{
  
    return (PME_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 20);
}

/*}}}  */
/*{{{  PME_Area PME_setAreaStartOffset(PME_Area arg, PME_NatCon startOffset) */

PME_Area PME_setAreaStartOffset(PME_Area arg, PME_NatCon startOffset)
{
  if (PME_isAreaArea(arg)) {
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) startOffset), 20), 1);
  }

  ATabort("Area has no StartOffset: %t\n", arg);
  return (PME_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasAreaWsAfterStartOffset(PME_Area arg) */

ATbool PME_hasAreaWsAfterStartOffset(PME_Area arg)
{
  if (PME_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getAreaWsAfterStartOffset(PME_Area arg) */

PME_OptLayout PME_getAreaWsAfterStartOffset(PME_Area arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 21);
}

/*}}}  */
/*{{{  PME_Area PME_setAreaWsAfterStartOffset(PME_Area arg, PME_OptLayout wsAfterStartOffset) */

PME_Area PME_setAreaWsAfterStartOffset(PME_Area arg, PME_OptLayout wsAfterStartOffset)
{
  if (PME_isAreaArea(arg)) {
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterStartOffset), 21), 1);
  }

  ATabort("Area has no WsAfterStartOffset: %t\n", arg);
  return (PME_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasAreaWsAfterComma4(PME_Area arg) */

ATbool PME_hasAreaWsAfterComma4(PME_Area arg)
{
  if (PME_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getAreaWsAfterComma4(PME_Area arg) */

PME_OptLayout PME_getAreaWsAfterComma4(PME_Area arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 23);
}

/*}}}  */
/*{{{  PME_Area PME_setAreaWsAfterComma4(PME_Area arg, PME_OptLayout wsAfterComma4) */

PME_Area PME_setAreaWsAfterComma4(PME_Area arg, PME_OptLayout wsAfterComma4)
{
  if (PME_isAreaArea(arg)) {
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterComma4), 23), 1);
  }

  ATabort("Area has no WsAfterComma4: %t\n", arg);
  return (PME_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasAreaEndOffset(PME_Area arg) */

ATbool PME_hasAreaEndOffset(PME_Area arg)
{
  if (PME_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_NatCon PME_getAreaEndOffset(PME_Area arg) */

PME_NatCon PME_getAreaEndOffset(PME_Area arg)
{
  
    return (PME_NatCon)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 24);
}

/*}}}  */
/*{{{  PME_Area PME_setAreaEndOffset(PME_Area arg, PME_NatCon endOffset) */

PME_Area PME_setAreaEndOffset(PME_Area arg, PME_NatCon endOffset)
{
  if (PME_isAreaArea(arg)) {
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) endOffset), 24), 1);
  }

  ATabort("Area has no EndOffset: %t\n", arg);
  return (PME_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasAreaWsAfterEndOffset(PME_Area arg) */

ATbool PME_hasAreaWsAfterEndOffset(PME_Area arg)
{
  if (PME_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getAreaWsAfterEndOffset(PME_Area arg) */

PME_OptLayout PME_getAreaWsAfterEndOffset(PME_Area arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 25);
}

/*}}}  */
/*{{{  PME_Area PME_setAreaWsAfterEndOffset(PME_Area arg, PME_OptLayout wsAfterEndOffset) */

PME_Area PME_setAreaWsAfterEndOffset(PME_Area arg, PME_OptLayout wsAfterEndOffset)
{
  if (PME_isAreaArea(arg)) {
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)((ATerm) wsAfterEndOffset), 25), 1);
  }

  ATabort("Area has no WsAfterEndOffset: %t\n", arg);
  return (PME_Area)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PME_NatCon accessors */

/*{{{  ATbool PME_isValidNatCon(PME_NatCon arg) */

ATbool PME_isValidNatCon(PME_NatCon arg)
{
  if (PME_isNatConString(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PME_isNatConString(PME_NatCon arg) */

inline ATbool PME_isNatConString(PME_NatCon arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PME_patternNatConString, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PME_hasNatConString(PME_NatCon arg) */

ATbool PME_hasNatConString(PME_NatCon arg)
{
  if (PME_isNatConString(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* PME_getNatConString(PME_NatCon arg) */

char* PME_getNatConString(PME_NatCon arg)
{
  
    return (char*)PME_charsToString((ATerm)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1));
}

/*}}}  */
/*{{{  PME_NatCon PME_setNatConString(PME_NatCon arg, char* string) */

PME_NatCon PME_setNatConString(PME_NatCon arg, char* string)
{
  if (PME_isNatConString(arg)) {
    return (PME_NatCon)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) ((ATerm) PME_stringToChars(string))), 1), 0), 1);
  }

  ATabort("NatCon has no String: %t\n", arg);
  return (PME_NatCon)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PME_String accessors */

/*{{{  ATbool PME_isValidString(PME_String arg) */

ATbool PME_isValidString(PME_String arg)
{
  if (PME_isStringString(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PME_isStringString(PME_String arg) */

inline ATbool PME_isStringString(PME_String arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PME_patternStringString, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PME_hasStringString(PME_String arg) */

ATbool PME_hasStringString(PME_String arg)
{
  if (PME_isStringString(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* PME_getStringString(PME_String arg) */

char* PME_getStringString(PME_String arg)
{
  
    return (char*)PME_charsToString((ATerm)ATgetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), 1));
}

/*}}}  */
/*{{{  PME_String PME_setStringString(PME_String arg, char* string) */

PME_String PME_setStringString(PME_String arg, char* string)
{
  if (PME_isStringString(arg)) {
    return (PME_String)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1)), (ATerm)((ATerm) ((ATerm) PME_stringToChars(string))), 1), 0), 1);
  }

  ATabort("String has no String: %t\n", arg);
  return (PME_String)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PME_OptLayout accessors */

/*{{{  ATbool PME_isValidOptLayout(PME_OptLayout arg) */

ATbool PME_isValidOptLayout(PME_OptLayout arg)
{
  if (PME_isOptLayoutAbsent(arg)) {
    return ATtrue;
  }
  else if (PME_isOptLayoutPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PME_isOptLayoutAbsent(PME_OptLayout arg) */

inline ATbool PME_isOptLayoutAbsent(PME_OptLayout arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PME_patternOptLayoutAbsent);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PME_isOptLayoutPresent(PME_OptLayout arg) */

inline ATbool PME_isOptLayoutPresent(PME_OptLayout arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PME_patternOptLayoutPresent, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PME_hasOptLayoutString(PME_OptLayout arg) */

ATbool PME_hasOptLayoutString(PME_OptLayout arg)
{
  if (PME_isOptLayoutPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* PME_getOptLayoutString(PME_OptLayout arg) */

char* PME_getOptLayoutString(PME_OptLayout arg)
{
  
    return (char*)PME_charsToString((ATerm)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  PME_OptLayout PME_setOptLayoutString(PME_OptLayout arg, char* string) */

PME_OptLayout PME_setOptLayoutString(PME_OptLayout arg, char* string)
{
  if (PME_isOptLayoutPresent(arg)) {
    return (PME_OptLayout)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) ((ATerm) PME_stringToChars(string))), 1);
  }

  ATabort("OptLayout has no String: %t\n", arg);
  return (PME_OptLayout)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PME_Start accessors */

/*{{{  ATbool PME_isValidStart(PME_Start arg) */

ATbool PME_isValidStart(PME_Start arg)
{
  if (PME_isStartArea(arg)) {
    return ATtrue;
  }
  else if (PME_isStartLocation(arg)) {
    return ATtrue;
  }
  else if (PME_isStartSubject(arg)) {
    return ATtrue;
  }
  else if (PME_isStartFeedback(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PME_isStartArea(PME_Start arg) */

inline ATbool PME_isStartArea(PME_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PME_patternStartArea, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PME_isStartLocation(PME_Start arg) */

inline ATbool PME_isStartLocation(PME_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PME_patternStartLocation, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PME_isStartSubject(PME_Start arg) */

inline ATbool PME_isStartSubject(PME_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PME_patternStartSubject, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PME_isStartFeedback(PME_Start arg) */

inline ATbool PME_isStartFeedback(PME_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PME_patternStartFeedback, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PME_hasStartWsBefore(PME_Start arg) */

ATbool PME_hasStartWsBefore(PME_Start arg)
{
  if (PME_isStartArea(arg)) {
    return ATtrue;
  }
  else if (PME_isStartLocation(arg)) {
    return ATtrue;
  }
  else if (PME_isStartSubject(arg)) {
    return ATtrue;
  }
  else if (PME_isStartFeedback(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getStartWsBefore(PME_Start arg) */

PME_OptLayout PME_getStartWsBefore(PME_Start arg)
{
  if (PME_isStartArea(arg)) {
    return (PME_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (PME_isStartLocation(arg)) {
    return (PME_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (PME_isStartSubject(arg)) {
    return (PME_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else 
    return (PME_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
}

/*}}}  */
/*{{{  PME_Start PME_setStartWsBefore(PME_Start arg, PME_OptLayout wsBefore) */

PME_Start PME_setStartWsBefore(PME_Start arg, PME_OptLayout wsBefore)
{
  if (PME_isStartArea(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (PME_isStartLocation(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (PME_isStartSubject(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }
  else if (PME_isStartFeedback(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsBefore), 0), 1), 0);
  }

  ATabort("Start has no WsBefore: %t\n", arg);
  return (PME_Start)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasStartTopArea(PME_Start arg) */

ATbool PME_hasStartTopArea(PME_Start arg)
{
  if (PME_isStartArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_Area PME_getStartTopArea(PME_Start arg) */

PME_Area PME_getStartTopArea(PME_Start arg)
{
  
    return (PME_Area)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  PME_Start PME_setStartTopArea(PME_Start arg, PME_Area topArea) */

PME_Start PME_setStartTopArea(PME_Start arg, PME_Area topArea)
{
  if (PME_isStartArea(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topArea), 1), 1), 0);
  }

  ATabort("Start has no TopArea: %t\n", arg);
  return (PME_Start)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasStartWsAfter(PME_Start arg) */

ATbool PME_hasStartWsAfter(PME_Start arg)
{
  if (PME_isStartArea(arg)) {
    return ATtrue;
  }
  else if (PME_isStartLocation(arg)) {
    return ATtrue;
  }
  else if (PME_isStartSubject(arg)) {
    return ATtrue;
  }
  else if (PME_isStartFeedback(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getStartWsAfter(PME_Start arg) */

PME_OptLayout PME_getStartWsAfter(PME_Start arg)
{
  if (PME_isStartArea(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (PME_isStartLocation(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (PME_isStartSubject(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else 
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
}

/*}}}  */
/*{{{  PME_Start PME_setStartWsAfter(PME_Start arg, PME_OptLayout wsAfter) */

PME_Start PME_setStartWsAfter(PME_Start arg, PME_OptLayout wsAfter)
{
  if (PME_isStartArea(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (PME_isStartLocation(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (PME_isStartSubject(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }
  else if (PME_isStartFeedback(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) wsAfter), 2), 1), 0);
  }

  ATabort("Start has no WsAfter: %t\n", arg);
  return (PME_Start)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasStartAmbCnt(PME_Start arg) */

ATbool PME_hasStartAmbCnt(PME_Start arg)
{
  if (PME_isStartArea(arg)) {
    return ATtrue;
  }
  else if (PME_isStartLocation(arg)) {
    return ATtrue;
  }
  else if (PME_isStartSubject(arg)) {
    return ATtrue;
  }
  else if (PME_isStartFeedback(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int PME_getStartAmbCnt(PME_Start arg) */

int PME_getStartAmbCnt(PME_Start arg)
{
  if (PME_isStartArea(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else if (PME_isStartLocation(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else if (PME_isStartSubject(arg)) {
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  PME_Start PME_setStartAmbCnt(PME_Start arg, int ambCnt) */

PME_Start PME_setStartAmbCnt(PME_Start arg, int ambCnt)
{
  if (PME_isStartArea(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (PME_isStartLocation(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (PME_isStartSubject(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }
  else if (PME_isStartFeedback(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(ambCnt)), 1);
  }

  ATabort("Start has no AmbCnt: %t\n", arg);
  return (PME_Start)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasStartTopLocation(PME_Start arg) */

ATbool PME_hasStartTopLocation(PME_Start arg)
{
  if (PME_isStartLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_Location PME_getStartTopLocation(PME_Start arg) */

PME_Location PME_getStartTopLocation(PME_Start arg)
{
  
    return (PME_Location)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  PME_Start PME_setStartTopLocation(PME_Start arg, PME_Location topLocation) */

PME_Start PME_setStartTopLocation(PME_Start arg, PME_Location topLocation)
{
  if (PME_isStartLocation(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topLocation), 1), 1), 0);
  }

  ATabort("Start has no TopLocation: %t\n", arg);
  return (PME_Start)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasStartTopSubject(PME_Start arg) */

ATbool PME_hasStartTopSubject(PME_Start arg)
{
  if (PME_isStartSubject(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_Subject PME_getStartTopSubject(PME_Start arg) */

PME_Subject PME_getStartTopSubject(PME_Start arg)
{
  
    return (PME_Subject)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  PME_Start PME_setStartTopSubject(PME_Start arg, PME_Subject topSubject) */

PME_Start PME_setStartTopSubject(PME_Start arg, PME_Subject topSubject)
{
  if (PME_isStartSubject(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topSubject), 1), 1), 0);
  }

  ATabort("Start has no TopSubject: %t\n", arg);
  return (PME_Start)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasStartTopFeedback(PME_Start arg) */

ATbool PME_hasStartTopFeedback(PME_Start arg)
{
  if (PME_isStartFeedback(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_Feedback PME_getStartTopFeedback(PME_Start arg) */

PME_Feedback PME_getStartTopFeedback(PME_Start arg)
{
  
    return (PME_Feedback)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  PME_Start PME_setStartTopFeedback(PME_Start arg, PME_Feedback topFeedback) */

PME_Start PME_setStartTopFeedback(PME_Start arg, PME_Feedback topFeedback)
{
  if (PME_isStartFeedback(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)((ATerm) topFeedback), 1), 1), 0);
  }

  ATabort("Start has no TopFeedback: %t\n", arg);
  return (PME_Start)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  PME_Feedback PME_visitFeedback(PME_Feedback arg, PME_OptLayout (*acceptWsAfterInfo)(PME_OptLayout), PME_OptLayout (*acceptWsAfterParenOpen)(PME_OptLayout), PME_String (*acceptId)(PME_String), PME_OptLayout (*acceptWsAfterId)(PME_OptLayout), PME_OptLayout (*acceptWsAfterComma)(PME_OptLayout), PME_String (*acceptProducerId)(PME_String), PME_OptLayout (*acceptWsAfterProducerId)(PME_OptLayout), PME_OptLayout (*acceptWsAfterComma1)(PME_OptLayout), PME_String (*acceptProducerType)(PME_String), PME_OptLayout (*acceptWsAfterProducerType)(PME_OptLayout), PME_OptLayout (*acceptWsAfterComma2)(PME_OptLayout), PME_String (*acceptDescription)(PME_String), PME_OptLayout (*acceptWsAfterDescription)(PME_OptLayout), PME_OptLayout (*acceptWsAfterComma3)(PME_OptLayout), PME_OptLayout (*acceptWsAfterBracketOpen)(PME_OptLayout), PME_SubjectList (*acceptList)(PME_SubjectList), PME_OptLayout (*acceptWsAfterList)(PME_OptLayout), PME_OptLayout (*acceptWsAfterBracketClose)(PME_OptLayout), PME_OptLayout (*acceptWsAfterWarning)(PME_OptLayout), PME_OptLayout (*acceptWsAfterError)(PME_OptLayout), PME_OptLayout (*acceptWsAfterFatalError)(PME_OptLayout)) */

PME_Feedback PME_visitFeedback(PME_Feedback arg, PME_OptLayout (*acceptWsAfterInfo)(PME_OptLayout), PME_OptLayout (*acceptWsAfterParenOpen)(PME_OptLayout), PME_String (*acceptId)(PME_String), PME_OptLayout (*acceptWsAfterId)(PME_OptLayout), PME_OptLayout (*acceptWsAfterComma)(PME_OptLayout), PME_String (*acceptProducerId)(PME_String), PME_OptLayout (*acceptWsAfterProducerId)(PME_OptLayout), PME_OptLayout (*acceptWsAfterComma1)(PME_OptLayout), PME_String (*acceptProducerType)(PME_String), PME_OptLayout (*acceptWsAfterProducerType)(PME_OptLayout), PME_OptLayout (*acceptWsAfterComma2)(PME_OptLayout), PME_String (*acceptDescription)(PME_String), PME_OptLayout (*acceptWsAfterDescription)(PME_OptLayout), PME_OptLayout (*acceptWsAfterComma3)(PME_OptLayout), PME_OptLayout (*acceptWsAfterBracketOpen)(PME_OptLayout), PME_SubjectList (*acceptList)(PME_SubjectList), PME_OptLayout (*acceptWsAfterList)(PME_OptLayout), PME_OptLayout (*acceptWsAfterBracketClose)(PME_OptLayout), PME_OptLayout (*acceptWsAfterWarning)(PME_OptLayout), PME_OptLayout (*acceptWsAfterError)(PME_OptLayout), PME_OptLayout (*acceptWsAfterFatalError)(PME_OptLayout))
{
  if (PME_isFeedbackInfo(arg)) {
    return PME_makeFeedbackInfo(
        acceptWsAfterInfo ? acceptWsAfterInfo(PME_getFeedbackWsAfterInfo(arg)) : PME_getFeedbackWsAfterInfo(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PME_getFeedbackWsAfterParenOpen(arg)) : PME_getFeedbackWsAfterParenOpen(arg),
        acceptId ? acceptId(PME_getFeedbackId(arg)) : PME_getFeedbackId(arg),
        acceptWsAfterId ? acceptWsAfterId(PME_getFeedbackWsAfterId(arg)) : PME_getFeedbackWsAfterId(arg),
        acceptWsAfterComma ? acceptWsAfterComma(PME_getFeedbackWsAfterComma(arg)) : PME_getFeedbackWsAfterComma(arg),
        acceptProducerId ? acceptProducerId(PME_getFeedbackProducerId(arg)) : PME_getFeedbackProducerId(arg),
        acceptWsAfterProducerId ? acceptWsAfterProducerId(PME_getFeedbackWsAfterProducerId(arg)) : PME_getFeedbackWsAfterProducerId(arg),
        acceptWsAfterComma1 ? acceptWsAfterComma1(PME_getFeedbackWsAfterComma1(arg)) : PME_getFeedbackWsAfterComma1(arg),
        acceptProducerType ? acceptProducerType(PME_getFeedbackProducerType(arg)) : PME_getFeedbackProducerType(arg),
        acceptWsAfterProducerType ? acceptWsAfterProducerType(PME_getFeedbackWsAfterProducerType(arg)) : PME_getFeedbackWsAfterProducerType(arg),
        acceptWsAfterComma2 ? acceptWsAfterComma2(PME_getFeedbackWsAfterComma2(arg)) : PME_getFeedbackWsAfterComma2(arg),
        acceptDescription ? acceptDescription(PME_getFeedbackDescription(arg)) : PME_getFeedbackDescription(arg),
        acceptWsAfterDescription ? acceptWsAfterDescription(PME_getFeedbackWsAfterDescription(arg)) : PME_getFeedbackWsAfterDescription(arg),
        acceptWsAfterComma3 ? acceptWsAfterComma3(PME_getFeedbackWsAfterComma3(arg)) : PME_getFeedbackWsAfterComma3(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(PME_getFeedbackWsAfterBracketOpen(arg)) : PME_getFeedbackWsAfterBracketOpen(arg),
        acceptList ? acceptList(PME_getFeedbackList(arg)) : PME_getFeedbackList(arg),
        acceptWsAfterList ? acceptWsAfterList(PME_getFeedbackWsAfterList(arg)) : PME_getFeedbackWsAfterList(arg),
        acceptWsAfterBracketClose ? acceptWsAfterBracketClose(PME_getFeedbackWsAfterBracketClose(arg)) : PME_getFeedbackWsAfterBracketClose(arg));
  }
  if (PME_isFeedbackWarning(arg)) {
    return PME_makeFeedbackWarning(
        acceptWsAfterWarning ? acceptWsAfterWarning(PME_getFeedbackWsAfterWarning(arg)) : PME_getFeedbackWsAfterWarning(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PME_getFeedbackWsAfterParenOpen(arg)) : PME_getFeedbackWsAfterParenOpen(arg),
        acceptId ? acceptId(PME_getFeedbackId(arg)) : PME_getFeedbackId(arg),
        acceptWsAfterId ? acceptWsAfterId(PME_getFeedbackWsAfterId(arg)) : PME_getFeedbackWsAfterId(arg),
        acceptWsAfterComma ? acceptWsAfterComma(PME_getFeedbackWsAfterComma(arg)) : PME_getFeedbackWsAfterComma(arg),
        acceptProducerId ? acceptProducerId(PME_getFeedbackProducerId(arg)) : PME_getFeedbackProducerId(arg),
        acceptWsAfterProducerId ? acceptWsAfterProducerId(PME_getFeedbackWsAfterProducerId(arg)) : PME_getFeedbackWsAfterProducerId(arg),
        acceptWsAfterComma1 ? acceptWsAfterComma1(PME_getFeedbackWsAfterComma1(arg)) : PME_getFeedbackWsAfterComma1(arg),
        acceptProducerType ? acceptProducerType(PME_getFeedbackProducerType(arg)) : PME_getFeedbackProducerType(arg),
        acceptWsAfterProducerType ? acceptWsAfterProducerType(PME_getFeedbackWsAfterProducerType(arg)) : PME_getFeedbackWsAfterProducerType(arg),
        acceptWsAfterComma2 ? acceptWsAfterComma2(PME_getFeedbackWsAfterComma2(arg)) : PME_getFeedbackWsAfterComma2(arg),
        acceptDescription ? acceptDescription(PME_getFeedbackDescription(arg)) : PME_getFeedbackDescription(arg),
        acceptWsAfterDescription ? acceptWsAfterDescription(PME_getFeedbackWsAfterDescription(arg)) : PME_getFeedbackWsAfterDescription(arg),
        acceptWsAfterComma3 ? acceptWsAfterComma3(PME_getFeedbackWsAfterComma3(arg)) : PME_getFeedbackWsAfterComma3(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(PME_getFeedbackWsAfterBracketOpen(arg)) : PME_getFeedbackWsAfterBracketOpen(arg),
        acceptList ? acceptList(PME_getFeedbackList(arg)) : PME_getFeedbackList(arg),
        acceptWsAfterList ? acceptWsAfterList(PME_getFeedbackWsAfterList(arg)) : PME_getFeedbackWsAfterList(arg),
        acceptWsAfterBracketClose ? acceptWsAfterBracketClose(PME_getFeedbackWsAfterBracketClose(arg)) : PME_getFeedbackWsAfterBracketClose(arg));
  }
  if (PME_isFeedbackError(arg)) {
    return PME_makeFeedbackError(
        acceptWsAfterError ? acceptWsAfterError(PME_getFeedbackWsAfterError(arg)) : PME_getFeedbackWsAfterError(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PME_getFeedbackWsAfterParenOpen(arg)) : PME_getFeedbackWsAfterParenOpen(arg),
        acceptId ? acceptId(PME_getFeedbackId(arg)) : PME_getFeedbackId(arg),
        acceptWsAfterId ? acceptWsAfterId(PME_getFeedbackWsAfterId(arg)) : PME_getFeedbackWsAfterId(arg),
        acceptWsAfterComma ? acceptWsAfterComma(PME_getFeedbackWsAfterComma(arg)) : PME_getFeedbackWsAfterComma(arg),
        acceptProducerId ? acceptProducerId(PME_getFeedbackProducerId(arg)) : PME_getFeedbackProducerId(arg),
        acceptWsAfterProducerId ? acceptWsAfterProducerId(PME_getFeedbackWsAfterProducerId(arg)) : PME_getFeedbackWsAfterProducerId(arg),
        acceptWsAfterComma1 ? acceptWsAfterComma1(PME_getFeedbackWsAfterComma1(arg)) : PME_getFeedbackWsAfterComma1(arg),
        acceptProducerType ? acceptProducerType(PME_getFeedbackProducerType(arg)) : PME_getFeedbackProducerType(arg),
        acceptWsAfterProducerType ? acceptWsAfterProducerType(PME_getFeedbackWsAfterProducerType(arg)) : PME_getFeedbackWsAfterProducerType(arg),
        acceptWsAfterComma2 ? acceptWsAfterComma2(PME_getFeedbackWsAfterComma2(arg)) : PME_getFeedbackWsAfterComma2(arg),
        acceptDescription ? acceptDescription(PME_getFeedbackDescription(arg)) : PME_getFeedbackDescription(arg),
        acceptWsAfterDescription ? acceptWsAfterDescription(PME_getFeedbackWsAfterDescription(arg)) : PME_getFeedbackWsAfterDescription(arg),
        acceptWsAfterComma3 ? acceptWsAfterComma3(PME_getFeedbackWsAfterComma3(arg)) : PME_getFeedbackWsAfterComma3(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(PME_getFeedbackWsAfterBracketOpen(arg)) : PME_getFeedbackWsAfterBracketOpen(arg),
        acceptList ? acceptList(PME_getFeedbackList(arg)) : PME_getFeedbackList(arg),
        acceptWsAfterList ? acceptWsAfterList(PME_getFeedbackWsAfterList(arg)) : PME_getFeedbackWsAfterList(arg),
        acceptWsAfterBracketClose ? acceptWsAfterBracketClose(PME_getFeedbackWsAfterBracketClose(arg)) : PME_getFeedbackWsAfterBracketClose(arg));
  }
  if (PME_isFeedbackFatalError(arg)) {
    return PME_makeFeedbackFatalError(
        acceptWsAfterFatalError ? acceptWsAfterFatalError(PME_getFeedbackWsAfterFatalError(arg)) : PME_getFeedbackWsAfterFatalError(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PME_getFeedbackWsAfterParenOpen(arg)) : PME_getFeedbackWsAfterParenOpen(arg),
        acceptId ? acceptId(PME_getFeedbackId(arg)) : PME_getFeedbackId(arg),
        acceptWsAfterId ? acceptWsAfterId(PME_getFeedbackWsAfterId(arg)) : PME_getFeedbackWsAfterId(arg),
        acceptWsAfterComma ? acceptWsAfterComma(PME_getFeedbackWsAfterComma(arg)) : PME_getFeedbackWsAfterComma(arg),
        acceptProducerId ? acceptProducerId(PME_getFeedbackProducerId(arg)) : PME_getFeedbackProducerId(arg),
        acceptWsAfterProducerId ? acceptWsAfterProducerId(PME_getFeedbackWsAfterProducerId(arg)) : PME_getFeedbackWsAfterProducerId(arg),
        acceptWsAfterComma1 ? acceptWsAfterComma1(PME_getFeedbackWsAfterComma1(arg)) : PME_getFeedbackWsAfterComma1(arg),
        acceptProducerType ? acceptProducerType(PME_getFeedbackProducerType(arg)) : PME_getFeedbackProducerType(arg),
        acceptWsAfterProducerType ? acceptWsAfterProducerType(PME_getFeedbackWsAfterProducerType(arg)) : PME_getFeedbackWsAfterProducerType(arg),
        acceptWsAfterComma2 ? acceptWsAfterComma2(PME_getFeedbackWsAfterComma2(arg)) : PME_getFeedbackWsAfterComma2(arg),
        acceptDescription ? acceptDescription(PME_getFeedbackDescription(arg)) : PME_getFeedbackDescription(arg),
        acceptWsAfterDescription ? acceptWsAfterDescription(PME_getFeedbackWsAfterDescription(arg)) : PME_getFeedbackWsAfterDescription(arg),
        acceptWsAfterComma3 ? acceptWsAfterComma3(PME_getFeedbackWsAfterComma3(arg)) : PME_getFeedbackWsAfterComma3(arg),
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(PME_getFeedbackWsAfterBracketOpen(arg)) : PME_getFeedbackWsAfterBracketOpen(arg),
        acceptList ? acceptList(PME_getFeedbackList(arg)) : PME_getFeedbackList(arg),
        acceptWsAfterList ? acceptWsAfterList(PME_getFeedbackWsAfterList(arg)) : PME_getFeedbackWsAfterList(arg),
        acceptWsAfterBracketClose ? acceptWsAfterBracketClose(PME_getFeedbackWsAfterBracketClose(arg)) : PME_getFeedbackWsAfterBracketClose(arg));
  }
  ATabort("not a Feedback: %t\n", arg);
  return (PME_Feedback)NULL;
}

/*}}}  */
/*{{{  PME_SubjectList PME_visitSubjectList(PME_SubjectList arg, PME_Subject (*acceptHead)(PME_Subject), PME_OptLayout (*acceptWsAfterHead)(PME_OptLayout), PME_OptLayout (*acceptWsAfterSep)(PME_OptLayout)) */

PME_SubjectList PME_visitSubjectList(PME_SubjectList arg, PME_Subject (*acceptHead)(PME_Subject), PME_OptLayout (*acceptWsAfterHead)(PME_OptLayout), PME_OptLayout (*acceptWsAfterSep)(PME_OptLayout))
{
  if (PME_isSubjectListEmpty(arg)) {
    return PME_makeSubjectListEmpty();
  }
  if (PME_isSubjectListSingle(arg)) {
    return PME_makeSubjectListSingle(
        acceptHead ? acceptHead(PME_getSubjectListHead(arg)) : PME_getSubjectListHead(arg));
  }
  if (PME_isSubjectListMany(arg)) {
    return PME_makeSubjectListMany(
        acceptHead ? acceptHead(PME_getSubjectListHead(arg)) : PME_getSubjectListHead(arg),
        acceptWsAfterHead ? acceptWsAfterHead(PME_getSubjectListWsAfterHead(arg)) : PME_getSubjectListWsAfterHead(arg),
        acceptWsAfterSep ? acceptWsAfterSep(PME_getSubjectListWsAfterSep(arg)) : PME_getSubjectListWsAfterSep(arg),
        PME_visitSubjectList(PME_getSubjectListTail(arg), acceptHead, acceptWsAfterHead, acceptWsAfterSep));
  }
  ATabort("not a SubjectList: %t\n", arg);
  return (PME_SubjectList)NULL;
}

/*}}}  */
/*{{{  PME_Subject PME_visitSubject(PME_Subject arg, PME_OptLayout (*acceptWsAfterSubject)(PME_OptLayout), PME_OptLayout (*acceptWsAfterParenOpen)(PME_OptLayout), PME_String (*acceptId)(PME_String), PME_OptLayout (*acceptWsAfterId)(PME_OptLayout), PME_OptLayout (*acceptWsAfterComma)(PME_OptLayout), PME_Location (*acceptLocation)(PME_Location), PME_OptLayout (*acceptWsAfterLocation)(PME_OptLayout)) */

PME_Subject PME_visitSubject(PME_Subject arg, PME_OptLayout (*acceptWsAfterSubject)(PME_OptLayout), PME_OptLayout (*acceptWsAfterParenOpen)(PME_OptLayout), PME_String (*acceptId)(PME_String), PME_OptLayout (*acceptWsAfterId)(PME_OptLayout), PME_OptLayout (*acceptWsAfterComma)(PME_OptLayout), PME_Location (*acceptLocation)(PME_Location), PME_OptLayout (*acceptWsAfterLocation)(PME_OptLayout))
{
  if (PME_isSubjectLocatable(arg)) {
    return PME_makeSubjectLocatable(
        acceptWsAfterSubject ? acceptWsAfterSubject(PME_getSubjectWsAfterSubject(arg)) : PME_getSubjectWsAfterSubject(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PME_getSubjectWsAfterParenOpen(arg)) : PME_getSubjectWsAfterParenOpen(arg),
        acceptId ? acceptId(PME_getSubjectId(arg)) : PME_getSubjectId(arg),
        acceptWsAfterId ? acceptWsAfterId(PME_getSubjectWsAfterId(arg)) : PME_getSubjectWsAfterId(arg),
        acceptWsAfterComma ? acceptWsAfterComma(PME_getSubjectWsAfterComma(arg)) : PME_getSubjectWsAfterComma(arg),
        acceptLocation ? acceptLocation(PME_getSubjectLocation(arg)) : PME_getSubjectLocation(arg),
        acceptWsAfterLocation ? acceptWsAfterLocation(PME_getSubjectWsAfterLocation(arg)) : PME_getSubjectWsAfterLocation(arg));
  }
  if (PME_isSubjectUnlocatable(arg)) {
    return PME_makeSubjectUnlocatable(
        acceptWsAfterSubject ? acceptWsAfterSubject(PME_getSubjectWsAfterSubject(arg)) : PME_getSubjectWsAfterSubject(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PME_getSubjectWsAfterParenOpen(arg)) : PME_getSubjectWsAfterParenOpen(arg),
        acceptId ? acceptId(PME_getSubjectId(arg)) : PME_getSubjectId(arg),
        acceptWsAfterId ? acceptWsAfterId(PME_getSubjectWsAfterId(arg)) : PME_getSubjectWsAfterId(arg));
  }
  ATabort("not a Subject: %t\n", arg);
  return (PME_Subject)NULL;
}

/*}}}  */
/*{{{  PME_Location PME_visitLocation(PME_Location arg, PME_OptLayout (*acceptWsAfterLocation)(PME_OptLayout), PME_OptLayout (*acceptWsAfterParenOpen)(PME_OptLayout), PME_String (*acceptFilename)(PME_String), PME_OptLayout (*acceptWsAfterFilename)(PME_OptLayout), PME_OptLayout (*acceptWsAfterComma)(PME_OptLayout), PME_Area (*acceptArea)(PME_Area), PME_OptLayout (*acceptWsAfterArea)(PME_OptLayout)) */

PME_Location PME_visitLocation(PME_Location arg, PME_OptLayout (*acceptWsAfterLocation)(PME_OptLayout), PME_OptLayout (*acceptWsAfterParenOpen)(PME_OptLayout), PME_String (*acceptFilename)(PME_String), PME_OptLayout (*acceptWsAfterFilename)(PME_OptLayout), PME_OptLayout (*acceptWsAfterComma)(PME_OptLayout), PME_Area (*acceptArea)(PME_Area), PME_OptLayout (*acceptWsAfterArea)(PME_OptLayout))
{
  if (PME_isLocationLocation(arg)) {
    return PME_makeLocationLocation(
        acceptWsAfterLocation ? acceptWsAfterLocation(PME_getLocationWsAfterLocation(arg)) : PME_getLocationWsAfterLocation(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PME_getLocationWsAfterParenOpen(arg)) : PME_getLocationWsAfterParenOpen(arg),
        acceptFilename ? acceptFilename(PME_getLocationFilename(arg)) : PME_getLocationFilename(arg),
        acceptWsAfterFilename ? acceptWsAfterFilename(PME_getLocationWsAfterFilename(arg)) : PME_getLocationWsAfterFilename(arg),
        acceptWsAfterComma ? acceptWsAfterComma(PME_getLocationWsAfterComma(arg)) : PME_getLocationWsAfterComma(arg),
        acceptArea ? acceptArea(PME_getLocationArea(arg)) : PME_getLocationArea(arg),
        acceptWsAfterArea ? acceptWsAfterArea(PME_getLocationWsAfterArea(arg)) : PME_getLocationWsAfterArea(arg));
  }
  ATabort("not a Location: %t\n", arg);
  return (PME_Location)NULL;
}

/*}}}  */
/*{{{  PME_Area PME_visitArea(PME_Area arg, PME_OptLayout (*acceptWsAfterArea)(PME_OptLayout), PME_OptLayout (*acceptWsAfterParenOpen)(PME_OptLayout), PME_NatCon (*acceptStartLine)(PME_NatCon), PME_OptLayout (*acceptWsAfterStartLine)(PME_OptLayout), PME_OptLayout (*acceptWsAfterComma)(PME_OptLayout), PME_NatCon (*acceptStartColumn)(PME_NatCon), PME_OptLayout (*acceptWsAfterStartColumn)(PME_OptLayout), PME_OptLayout (*acceptWsAfterComma1)(PME_OptLayout), PME_NatCon (*acceptEndLine)(PME_NatCon), PME_OptLayout (*acceptWsAfterEndLine)(PME_OptLayout), PME_OptLayout (*acceptWsAfterComma2)(PME_OptLayout), PME_NatCon (*acceptEndColumn)(PME_NatCon), PME_OptLayout (*acceptWsAfterEndColumn)(PME_OptLayout), PME_OptLayout (*acceptWsAfterComma3)(PME_OptLayout), PME_NatCon (*acceptStartOffset)(PME_NatCon), PME_OptLayout (*acceptWsAfterStartOffset)(PME_OptLayout), PME_OptLayout (*acceptWsAfterComma4)(PME_OptLayout), PME_NatCon (*acceptEndOffset)(PME_NatCon), PME_OptLayout (*acceptWsAfterEndOffset)(PME_OptLayout)) */

PME_Area PME_visitArea(PME_Area arg, PME_OptLayout (*acceptWsAfterArea)(PME_OptLayout), PME_OptLayout (*acceptWsAfterParenOpen)(PME_OptLayout), PME_NatCon (*acceptStartLine)(PME_NatCon), PME_OptLayout (*acceptWsAfterStartLine)(PME_OptLayout), PME_OptLayout (*acceptWsAfterComma)(PME_OptLayout), PME_NatCon (*acceptStartColumn)(PME_NatCon), PME_OptLayout (*acceptWsAfterStartColumn)(PME_OptLayout), PME_OptLayout (*acceptWsAfterComma1)(PME_OptLayout), PME_NatCon (*acceptEndLine)(PME_NatCon), PME_OptLayout (*acceptWsAfterEndLine)(PME_OptLayout), PME_OptLayout (*acceptWsAfterComma2)(PME_OptLayout), PME_NatCon (*acceptEndColumn)(PME_NatCon), PME_OptLayout (*acceptWsAfterEndColumn)(PME_OptLayout), PME_OptLayout (*acceptWsAfterComma3)(PME_OptLayout), PME_NatCon (*acceptStartOffset)(PME_NatCon), PME_OptLayout (*acceptWsAfterStartOffset)(PME_OptLayout), PME_OptLayout (*acceptWsAfterComma4)(PME_OptLayout), PME_NatCon (*acceptEndOffset)(PME_NatCon), PME_OptLayout (*acceptWsAfterEndOffset)(PME_OptLayout))
{
  if (PME_isAreaArea(arg)) {
    return PME_makeAreaArea(
        acceptWsAfterArea ? acceptWsAfterArea(PME_getAreaWsAfterArea(arg)) : PME_getAreaWsAfterArea(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PME_getAreaWsAfterParenOpen(arg)) : PME_getAreaWsAfterParenOpen(arg),
        acceptStartLine ? acceptStartLine(PME_getAreaStartLine(arg)) : PME_getAreaStartLine(arg),
        acceptWsAfterStartLine ? acceptWsAfterStartLine(PME_getAreaWsAfterStartLine(arg)) : PME_getAreaWsAfterStartLine(arg),
        acceptWsAfterComma ? acceptWsAfterComma(PME_getAreaWsAfterComma(arg)) : PME_getAreaWsAfterComma(arg),
        acceptStartColumn ? acceptStartColumn(PME_getAreaStartColumn(arg)) : PME_getAreaStartColumn(arg),
        acceptWsAfterStartColumn ? acceptWsAfterStartColumn(PME_getAreaWsAfterStartColumn(arg)) : PME_getAreaWsAfterStartColumn(arg),
        acceptWsAfterComma1 ? acceptWsAfterComma1(PME_getAreaWsAfterComma1(arg)) : PME_getAreaWsAfterComma1(arg),
        acceptEndLine ? acceptEndLine(PME_getAreaEndLine(arg)) : PME_getAreaEndLine(arg),
        acceptWsAfterEndLine ? acceptWsAfterEndLine(PME_getAreaWsAfterEndLine(arg)) : PME_getAreaWsAfterEndLine(arg),
        acceptWsAfterComma2 ? acceptWsAfterComma2(PME_getAreaWsAfterComma2(arg)) : PME_getAreaWsAfterComma2(arg),
        acceptEndColumn ? acceptEndColumn(PME_getAreaEndColumn(arg)) : PME_getAreaEndColumn(arg),
        acceptWsAfterEndColumn ? acceptWsAfterEndColumn(PME_getAreaWsAfterEndColumn(arg)) : PME_getAreaWsAfterEndColumn(arg),
        acceptWsAfterComma3 ? acceptWsAfterComma3(PME_getAreaWsAfterComma3(arg)) : PME_getAreaWsAfterComma3(arg),
        acceptStartOffset ? acceptStartOffset(PME_getAreaStartOffset(arg)) : PME_getAreaStartOffset(arg),
        acceptWsAfterStartOffset ? acceptWsAfterStartOffset(PME_getAreaWsAfterStartOffset(arg)) : PME_getAreaWsAfterStartOffset(arg),
        acceptWsAfterComma4 ? acceptWsAfterComma4(PME_getAreaWsAfterComma4(arg)) : PME_getAreaWsAfterComma4(arg),
        acceptEndOffset ? acceptEndOffset(PME_getAreaEndOffset(arg)) : PME_getAreaEndOffset(arg),
        acceptWsAfterEndOffset ? acceptWsAfterEndOffset(PME_getAreaWsAfterEndOffset(arg)) : PME_getAreaWsAfterEndOffset(arg));
  }
  if (PME_isAreaNoArea(arg)) {
    return PME_makeAreaNoArea();
  }
  ATabort("not a Area: %t\n", arg);
  return (PME_Area)NULL;
}

/*}}}  */
/*{{{  PME_NatCon PME_visitNatCon(PME_NatCon arg, char* (*acceptString)(char*)) */

PME_NatCon PME_visitNatCon(PME_NatCon arg, char* (*acceptString)(char*))
{
  if (PME_isNatConString(arg)) {
    return PME_makeNatConString(
        acceptString ? acceptString(PME_getNatConString(arg)) : PME_getNatConString(arg));
  }
  ATabort("not a NatCon: %t\n", arg);
  return (PME_NatCon)NULL;
}

/*}}}  */
/*{{{  PME_String PME_visitString(PME_String arg, char* (*acceptString)(char*)) */

PME_String PME_visitString(PME_String arg, char* (*acceptString)(char*))
{
  if (PME_isStringString(arg)) {
    return PME_makeStringString(
        acceptString ? acceptString(PME_getStringString(arg)) : PME_getStringString(arg));
  }
  ATabort("not a String: %t\n", arg);
  return (PME_String)NULL;
}

/*}}}  */
/*{{{  PME_OptLayout PME_visitOptLayout(PME_OptLayout arg, char* (*acceptString)(char*)) */

PME_OptLayout PME_visitOptLayout(PME_OptLayout arg, char* (*acceptString)(char*))
{
  if (PME_isOptLayoutAbsent(arg)) {
    return PME_makeOptLayoutAbsent();
  }
  if (PME_isOptLayoutPresent(arg)) {
    return PME_makeOptLayoutPresent(
        acceptString ? acceptString(PME_getOptLayoutString(arg)) : PME_getOptLayoutString(arg));
  }
  ATabort("not a OptLayout: %t\n", arg);
  return (PME_OptLayout)NULL;
}

/*}}}  */
/*{{{  PME_Start PME_visitStart(PME_Start arg, PME_OptLayout (*acceptWsBefore)(PME_OptLayout), PME_Area (*acceptTopArea)(PME_Area), PME_OptLayout (*acceptWsAfter)(PME_OptLayout), int (*acceptAmbCnt)(int), PME_Location (*acceptTopLocation)(PME_Location), PME_Subject (*acceptTopSubject)(PME_Subject), PME_Feedback (*acceptTopFeedback)(PME_Feedback)) */

PME_Start PME_visitStart(PME_Start arg, PME_OptLayout (*acceptWsBefore)(PME_OptLayout), PME_Area (*acceptTopArea)(PME_Area), PME_OptLayout (*acceptWsAfter)(PME_OptLayout), int (*acceptAmbCnt)(int), PME_Location (*acceptTopLocation)(PME_Location), PME_Subject (*acceptTopSubject)(PME_Subject), PME_Feedback (*acceptTopFeedback)(PME_Feedback))
{
  if (PME_isStartArea(arg)) {
    return PME_makeStartArea(
        acceptWsBefore ? acceptWsBefore(PME_getStartWsBefore(arg)) : PME_getStartWsBefore(arg),
        acceptTopArea ? acceptTopArea(PME_getStartTopArea(arg)) : PME_getStartTopArea(arg),
        acceptWsAfter ? acceptWsAfter(PME_getStartWsAfter(arg)) : PME_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(PME_getStartAmbCnt(arg)) : PME_getStartAmbCnt(arg));
  }
  if (PME_isStartLocation(arg)) {
    return PME_makeStartLocation(
        acceptWsBefore ? acceptWsBefore(PME_getStartWsBefore(arg)) : PME_getStartWsBefore(arg),
        acceptTopLocation ? acceptTopLocation(PME_getStartTopLocation(arg)) : PME_getStartTopLocation(arg),
        acceptWsAfter ? acceptWsAfter(PME_getStartWsAfter(arg)) : PME_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(PME_getStartAmbCnt(arg)) : PME_getStartAmbCnt(arg));
  }
  if (PME_isStartSubject(arg)) {
    return PME_makeStartSubject(
        acceptWsBefore ? acceptWsBefore(PME_getStartWsBefore(arg)) : PME_getStartWsBefore(arg),
        acceptTopSubject ? acceptTopSubject(PME_getStartTopSubject(arg)) : PME_getStartTopSubject(arg),
        acceptWsAfter ? acceptWsAfter(PME_getStartWsAfter(arg)) : PME_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(PME_getStartAmbCnt(arg)) : PME_getStartAmbCnt(arg));
  }
  if (PME_isStartFeedback(arg)) {
    return PME_makeStartFeedback(
        acceptWsBefore ? acceptWsBefore(PME_getStartWsBefore(arg)) : PME_getStartWsBefore(arg),
        acceptTopFeedback ? acceptTopFeedback(PME_getStartTopFeedback(arg)) : PME_getStartTopFeedback(arg),
        acceptWsAfter ? acceptWsAfter(PME_getStartWsAfter(arg)) : PME_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(PME_getStartAmbCnt(arg)) : PME_getStartAmbCnt(arg));
  }
  ATabort("not a Start: %t\n", arg);
  return (PME_Start)NULL;
}

/*}}}  */

/*}}}  */
