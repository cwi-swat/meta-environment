#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "ErrorAPI.h"

/*{{{  conversion functions */

ATerm ME_stringToChars(const char *str)
{
  int len = strlen(str);
  int i;
  ATermList result = ATempty;

  for (i = len - 1; i >= 0; i--) {
    result = ATinsert(result, (ATerm) ATmakeInt(str[i]));
  }

  return (ATerm) result;
}

char *ME_charsToString(ATerm arg)
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

typedef struct ATerm _ME_Feedback;
typedef struct ATerm _ME_SubjectList;
typedef struct ATerm _ME_Subject;
typedef struct ATerm _ME_Location;
typedef struct ATerm _ME_Area;

/*}}}  */

/*{{{  void ME_initErrorAPIApi(void) */

void ME_initErrorAPIApi(void)
{
  init_ErrorAPI_dict();
}

/*}}}  */

/*{{{  term conversion functions */

/*{{{  ME_Feedback ME_FeedbackFromTerm(ATerm t) */

ME_Feedback ME_FeedbackFromTerm(ATerm t)
{
  return (ME_Feedback)t;
}

/*}}}  */
/*{{{  ATerm ME_FeedbackToTerm(ME_Feedback arg) */

ATerm ME_FeedbackToTerm(ME_Feedback arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ME_SubjectList ME_SubjectListFromTerm(ATerm t) */

ME_SubjectList ME_SubjectListFromTerm(ATerm t)
{
  return (ME_SubjectList)t;
}

/*}}}  */
/*{{{  ATerm ME_SubjectListToTerm(ME_SubjectList arg) */

ATerm ME_SubjectListToTerm(ME_SubjectList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ME_Subject ME_SubjectFromTerm(ATerm t) */

ME_Subject ME_SubjectFromTerm(ATerm t)
{
  return (ME_Subject)t;
}

/*}}}  */
/*{{{  ATerm ME_SubjectToTerm(ME_Subject arg) */

ATerm ME_SubjectToTerm(ME_Subject arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ME_Location ME_LocationFromTerm(ATerm t) */

ME_Location ME_LocationFromTerm(ATerm t)
{
  return (ME_Location)t;
}

/*}}}  */
/*{{{  ATerm ME_LocationToTerm(ME_Location arg) */

ATerm ME_LocationToTerm(ME_Location arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ME_Area ME_AreaFromTerm(ATerm t) */

ME_Area ME_AreaFromTerm(ATerm t)
{
  return (ME_Area)t;
}

/*}}}  */
/*{{{  ATerm ME_AreaToTerm(ME_Area arg) */

ATerm ME_AreaToTerm(ME_Area arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*}}}  */
/*{{{  list functions */

int ME_getSubjectListLength (ME_SubjectList arg) {
  return ATgetLength((ATermList) arg);
}
ME_SubjectList ME_reverseSubjectList(ME_SubjectList arg) {
  return (ME_SubjectList) ATreverse((ATermList) arg);
}
ME_SubjectList ME_appendSubjectList(ME_SubjectList arg, ME_Subject elem) {
  return (ME_SubjectList) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}
ME_SubjectList ME_concatSubjectList(ME_SubjectList arg0, ME_SubjectList arg1) {
  return (ME_SubjectList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
ME_SubjectList ME_sliceSubjectList(ME_SubjectList arg, int start, int end) {
  return (ME_SubjectList) ATgetSlice((ATermList) arg, start, end);
}
ME_Subject ME_getSubjectListSubjectAt(ME_SubjectList arg, int index) {
 return (ME_Subject)ATelementAt((ATermList) arg,index);
}
ME_SubjectList ME_replaceSubjectListSubjectAt(ME_SubjectList arg, ME_Subject elem, int index) {
 return (ME_SubjectList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}
ME_SubjectList ME_makeSubjectList2(ME_Subject elem1, ME_Subject elem2) {
  return (ME_SubjectList) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}
ME_SubjectList ME_makeSubjectList3(ME_Subject elem1, ME_Subject elem2, ME_Subject elem3) {
  return (ME_SubjectList) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}
ME_SubjectList ME_makeSubjectList4(ME_Subject elem1, ME_Subject elem2, ME_Subject elem3, ME_Subject elem4) {
  return (ME_SubjectList) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}
ME_SubjectList ME_makeSubjectList5(ME_Subject elem1, ME_Subject elem2, ME_Subject elem3, ME_Subject elem4, ME_Subject elem5) {
  return (ME_SubjectList) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}
ME_SubjectList ME_makeSubjectList6(ME_Subject elem1, ME_Subject elem2, ME_Subject elem3, ME_Subject elem4, ME_Subject elem5, ME_Subject elem6) {
  return (ME_SubjectList) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}

/*}}}  */
/*{{{  constructors */

/*{{{  ME_Feedback ME_makeFeedbackInfo(char* id, char* producerId, char* producerType, char* description, ME_SubjectList list) */

ME_Feedback ME_makeFeedbackInfo(char* id, char* producerId, char* producerType, char* description, ME_SubjectList list)
{
  return (ME_Feedback)(ATerm)ATmakeAppl5(ME_afun0, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(id, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(producerId, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(producerType, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(description, 0, ATtrue)), (ATerm) list);
}

/*}}}  */
/*{{{  ME_Feedback ME_makeFeedbackWarning(char* id, char* producerId, char* producerType, char* description, ME_SubjectList list) */

ME_Feedback ME_makeFeedbackWarning(char* id, char* producerId, char* producerType, char* description, ME_SubjectList list)
{
  return (ME_Feedback)(ATerm)ATmakeAppl5(ME_afun1, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(id, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(producerId, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(producerType, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(description, 0, ATtrue)), (ATerm) list);
}

/*}}}  */
/*{{{  ME_Feedback ME_makeFeedbackError(char* id, char* producerId, char* producerType, char* description, ME_SubjectList list) */

ME_Feedback ME_makeFeedbackError(char* id, char* producerId, char* producerType, char* description, ME_SubjectList list)
{
  return (ME_Feedback)(ATerm)ATmakeAppl5(ME_afun2, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(id, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(producerId, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(producerType, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(description, 0, ATtrue)), (ATerm) list);
}

/*}}}  */
/*{{{  ME_Feedback ME_makeFeedbackFatalError(char* id, char* producerId, char* producerType, char* description, ME_SubjectList list) */

ME_Feedback ME_makeFeedbackFatalError(char* id, char* producerId, char* producerType, char* description, ME_SubjectList list)
{
  return (ME_Feedback)(ATerm)ATmakeAppl5(ME_afun3, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(id, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(producerId, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(producerType, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(description, 0, ATtrue)), (ATerm) list);
}

/*}}}  */
/*{{{  ME_SubjectList ME_makeSubjectListEmpty() */

ME_SubjectList ME_makeSubjectListEmpty()
{
  return (ME_SubjectList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  ME_SubjectList ME_makeSubjectListSingle(ME_Subject head) */

ME_SubjectList ME_makeSubjectListSingle(ME_Subject head)
{
  return (ME_SubjectList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  ME_SubjectList ME_makeSubjectListMany(ME_Subject head, ME_SubjectList tail) */

ME_SubjectList ME_makeSubjectListMany(ME_Subject head, ME_SubjectList tail)
{
  return (ME_SubjectList)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/*}}}  */
/*{{{  ME_Subject ME_makeSubjectLocatable(char* id, ME_Location Location) */

ME_Subject ME_makeSubjectLocatable(char* id, ME_Location Location)
{
  return (ME_Subject)(ATerm)ATmakeAppl2(ME_afun4, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(id, 0, ATtrue)), (ATerm) Location);
}

/*}}}  */
/*{{{  ME_Subject ME_makeSubjectUnlocatable(char* id) */

ME_Subject ME_makeSubjectUnlocatable(char* id)
{
  return (ME_Subject)(ATerm)ATmakeAppl1(ME_afun5, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(id, 0, ATtrue)));
}

/*}}}  */
/*{{{  ME_Location ME_makeLocationLocation(char* filename, ME_Area Area) */

ME_Location ME_makeLocationLocation(char* filename, ME_Area Area)
{
  return (ME_Location)(ATerm)ATmakeAppl2(ME_afun6, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(filename, 0, ATtrue)), (ATerm) Area);
}

/*}}}  */
/*{{{  ME_Area ME_makeAreaArea(int startLine, int startColumn, int endLine, int endColumn, int startOffset, int endOffset) */

ME_Area ME_makeAreaArea(int startLine, int startColumn, int endLine, int endColumn, int startOffset, int endOffset)
{
  return (ME_Area)(ATerm)ATmakeAppl6(ME_afun7, (ATerm) (ATerm) ATmakeInt(startLine), (ATerm) (ATerm) ATmakeInt(startColumn), (ATerm) (ATerm) ATmakeInt(endLine), (ATerm) (ATerm) ATmakeInt(endColumn), (ATerm) (ATerm) ATmakeInt(startOffset), (ATerm) (ATerm) ATmakeInt(endOffset));
}

/*}}}  */
/*{{{  ME_Area ME_makeAreaNoArea() */

ME_Area ME_makeAreaNoArea()
{
  return (ME_Area)(ATerm)ATmakeAppl0(ME_afun8);
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool ME_isEqualFeedback(ME_Feedback arg0, ME_Feedback arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ME_isEqualSubjectList(ME_SubjectList arg0, ME_SubjectList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ME_isEqualSubject(ME_Subject arg0, ME_Subject arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ME_isEqualLocation(ME_Location arg0, ME_Location arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ME_isEqualArea(ME_Area arg0, ME_Area arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  ME_Feedback accessors */

/*{{{  ATbool ME_isValidFeedback(ME_Feedback arg) */

ATbool ME_isValidFeedback(ME_Feedback arg)
{
  if (ME_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (ME_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (ME_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (ME_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ME_isFeedbackInfo(ME_Feedback arg) */

inline ATbool ME_isFeedbackInfo(ME_Feedback arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ME_patternFeedbackInfo, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ME_isFeedbackWarning(ME_Feedback arg) */

inline ATbool ME_isFeedbackWarning(ME_Feedback arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ME_patternFeedbackWarning, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ME_isFeedbackError(ME_Feedback arg) */

inline ATbool ME_isFeedbackError(ME_Feedback arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ME_patternFeedbackError, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ME_isFeedbackFatalError(ME_Feedback arg) */

inline ATbool ME_isFeedbackFatalError(ME_Feedback arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ME_patternFeedbackFatalError, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ME_hasFeedbackId(ME_Feedback arg) */

ATbool ME_hasFeedbackId(ME_Feedback arg)
{
  if (ME_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (ME_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (ME_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (ME_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* ME_getFeedbackId(ME_Feedback arg) */

char* ME_getFeedbackId(ME_Feedback arg)
{
  if (ME_isFeedbackInfo(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
  }
  else if (ME_isFeedbackWarning(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
  }
  else if (ME_isFeedbackError(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
  }
  else 
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  ME_Feedback ME_setFeedbackId(ME_Feedback arg, char* id) */

ME_Feedback ME_setFeedbackId(ME_Feedback arg, char* id)
{
  if (ME_isFeedbackInfo(arg)) {
    return (ME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(id, 0, ATtrue))), 0);
  }
  else if (ME_isFeedbackWarning(arg)) {
    return (ME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(id, 0, ATtrue))), 0);
  }
  else if (ME_isFeedbackError(arg)) {
    return (ME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(id, 0, ATtrue))), 0);
  }
  else if (ME_isFeedbackFatalError(arg)) {
    return (ME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(id, 0, ATtrue))), 0);
  }

  ATabort("Feedback has no Id: %t\n", arg);
  return (ME_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool ME_hasFeedbackProducerId(ME_Feedback arg) */

ATbool ME_hasFeedbackProducerId(ME_Feedback arg)
{
  if (ME_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (ME_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (ME_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (ME_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* ME_getFeedbackProducerId(ME_Feedback arg) */

char* ME_getFeedbackProducerId(ME_Feedback arg)
{
  if (ME_isFeedbackInfo(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
  }
  else if (ME_isFeedbackWarning(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
  }
  else if (ME_isFeedbackError(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
  }
  else 
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  ME_Feedback ME_setFeedbackProducerId(ME_Feedback arg, char* producerId) */

ME_Feedback ME_setFeedbackProducerId(ME_Feedback arg, char* producerId)
{
  if (ME_isFeedbackInfo(arg)) {
    return (ME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(producerId, 0, ATtrue))), 1);
  }
  else if (ME_isFeedbackWarning(arg)) {
    return (ME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(producerId, 0, ATtrue))), 1);
  }
  else if (ME_isFeedbackError(arg)) {
    return (ME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(producerId, 0, ATtrue))), 1);
  }
  else if (ME_isFeedbackFatalError(arg)) {
    return (ME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(producerId, 0, ATtrue))), 1);
  }

  ATabort("Feedback has no ProducerId: %t\n", arg);
  return (ME_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool ME_hasFeedbackProducerType(ME_Feedback arg) */

ATbool ME_hasFeedbackProducerType(ME_Feedback arg)
{
  if (ME_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (ME_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (ME_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (ME_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* ME_getFeedbackProducerType(ME_Feedback arg) */

char* ME_getFeedbackProducerType(ME_Feedback arg)
{
  if (ME_isFeedbackInfo(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 2)));
  }
  else if (ME_isFeedbackWarning(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 2)));
  }
  else if (ME_isFeedbackError(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 2)));
  }
  else 
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 2)));
}

/*}}}  */
/*{{{  ME_Feedback ME_setFeedbackProducerType(ME_Feedback arg, char* producerType) */

ME_Feedback ME_setFeedbackProducerType(ME_Feedback arg, char* producerType)
{
  if (ME_isFeedbackInfo(arg)) {
    return (ME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(producerType, 0, ATtrue))), 2);
  }
  else if (ME_isFeedbackWarning(arg)) {
    return (ME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(producerType, 0, ATtrue))), 2);
  }
  else if (ME_isFeedbackError(arg)) {
    return (ME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(producerType, 0, ATtrue))), 2);
  }
  else if (ME_isFeedbackFatalError(arg)) {
    return (ME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(producerType, 0, ATtrue))), 2);
  }

  ATabort("Feedback has no ProducerType: %t\n", arg);
  return (ME_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool ME_hasFeedbackDescription(ME_Feedback arg) */

ATbool ME_hasFeedbackDescription(ME_Feedback arg)
{
  if (ME_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (ME_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (ME_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (ME_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* ME_getFeedbackDescription(ME_Feedback arg) */

char* ME_getFeedbackDescription(ME_Feedback arg)
{
  if (ME_isFeedbackInfo(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 3)));
  }
  else if (ME_isFeedbackWarning(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 3)));
  }
  else if (ME_isFeedbackError(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 3)));
  }
  else 
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 3)));
}

/*}}}  */
/*{{{  ME_Feedback ME_setFeedbackDescription(ME_Feedback arg, char* description) */

ME_Feedback ME_setFeedbackDescription(ME_Feedback arg, char* description)
{
  if (ME_isFeedbackInfo(arg)) {
    return (ME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(description, 0, ATtrue))), 3);
  }
  else if (ME_isFeedbackWarning(arg)) {
    return (ME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(description, 0, ATtrue))), 3);
  }
  else if (ME_isFeedbackError(arg)) {
    return (ME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(description, 0, ATtrue))), 3);
  }
  else if (ME_isFeedbackFatalError(arg)) {
    return (ME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(description, 0, ATtrue))), 3);
  }

  ATabort("Feedback has no Description: %t\n", arg);
  return (ME_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool ME_hasFeedbackList(ME_Feedback arg) */

ATbool ME_hasFeedbackList(ME_Feedback arg)
{
  if (ME_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (ME_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (ME_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (ME_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ME_SubjectList ME_getFeedbackList(ME_Feedback arg) */

ME_SubjectList ME_getFeedbackList(ME_Feedback arg)
{
  if (ME_isFeedbackInfo(arg)) {
    return (ME_SubjectList)ATgetArgument((ATermAppl)arg, 4);
  }
  else if (ME_isFeedbackWarning(arg)) {
    return (ME_SubjectList)ATgetArgument((ATermAppl)arg, 4);
  }
  else if (ME_isFeedbackError(arg)) {
    return (ME_SubjectList)ATgetArgument((ATermAppl)arg, 4);
  }
  else 
    return (ME_SubjectList)ATgetArgument((ATermAppl)arg, 4);
}

/*}}}  */
/*{{{  ME_Feedback ME_setFeedbackList(ME_Feedback arg, ME_SubjectList list) */

ME_Feedback ME_setFeedbackList(ME_Feedback arg, ME_SubjectList list)
{
  if (ME_isFeedbackInfo(arg)) {
    return (ME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) list), 4);
  }
  else if (ME_isFeedbackWarning(arg)) {
    return (ME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) list), 4);
  }
  else if (ME_isFeedbackError(arg)) {
    return (ME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) list), 4);
  }
  else if (ME_isFeedbackFatalError(arg)) {
    return (ME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) list), 4);
  }

  ATabort("Feedback has no List: %t\n", arg);
  return (ME_Feedback)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ME_SubjectList accessors */

/*{{{  ATbool ME_isValidSubjectList(ME_SubjectList arg) */

ATbool ME_isValidSubjectList(ME_SubjectList arg)
{
  if (ME_isSubjectListEmpty(arg)) {
    return ATtrue;
  }
  else if (ME_isSubjectListSingle(arg)) {
    return ATtrue;
  }
  else if (ME_isSubjectListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ME_isSubjectListEmpty(ME_SubjectList arg) */

inline ATbool ME_isSubjectListEmpty(ME_SubjectList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ME_patternSubjectListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool ME_isSubjectListSingle(ME_SubjectList arg) */

inline ATbool ME_isSubjectListSingle(ME_SubjectList arg)
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
      last_result = ATmatchTerm((ATerm)arg, ME_patternSubjectListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ME_isSubjectListMany(ME_SubjectList arg) */

inline ATbool ME_isSubjectListMany(ME_SubjectList arg)
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
      last_result = ATmatchTerm((ATerm)arg, ME_patternSubjectListMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ME_hasSubjectListHead(ME_SubjectList arg) */

ATbool ME_hasSubjectListHead(ME_SubjectList arg)
{
  if (ME_isSubjectListSingle(arg)) {
    return ATtrue;
  }
  else if (ME_isSubjectListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ME_Subject ME_getSubjectListHead(ME_SubjectList arg) */

ME_Subject ME_getSubjectListHead(ME_SubjectList arg)
{
  if (ME_isSubjectListSingle(arg)) {
    return (ME_Subject)ATgetFirst((ATermList)arg);
  }
  else 
    return (ME_Subject)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  ME_SubjectList ME_setSubjectListHead(ME_SubjectList arg, ME_Subject head) */

ME_SubjectList ME_setSubjectListHead(ME_SubjectList arg, ME_Subject head)
{
  if (ME_isSubjectListSingle(arg)) {
    return (ME_SubjectList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (ME_isSubjectListMany(arg)) {
    return (ME_SubjectList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("SubjectList has no Head: %t\n", arg);
  return (ME_SubjectList)NULL;
}

/*}}}  */
/*{{{  ATbool ME_hasSubjectListTail(ME_SubjectList arg) */

ATbool ME_hasSubjectListTail(ME_SubjectList arg)
{
  if (ME_isSubjectListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ME_SubjectList ME_getSubjectListTail(ME_SubjectList arg) */

ME_SubjectList ME_getSubjectListTail(ME_SubjectList arg)
{
  
    return (ME_SubjectList)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  ME_SubjectList ME_setSubjectListTail(ME_SubjectList arg, ME_SubjectList tail) */

ME_SubjectList ME_setSubjectListTail(ME_SubjectList arg, ME_SubjectList tail)
{
  if (ME_isSubjectListMany(arg)) {
    return (ME_SubjectList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("SubjectList has no Tail: %t\n", arg);
  return (ME_SubjectList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ME_Subject accessors */

/*{{{  ATbool ME_isValidSubject(ME_Subject arg) */

ATbool ME_isValidSubject(ME_Subject arg)
{
  if (ME_isSubjectLocatable(arg)) {
    return ATtrue;
  }
  else if (ME_isSubjectUnlocatable(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ME_isSubjectLocatable(ME_Subject arg) */

inline ATbool ME_isSubjectLocatable(ME_Subject arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ME_patternSubjectLocatable, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ME_isSubjectUnlocatable(ME_Subject arg) */

inline ATbool ME_isSubjectUnlocatable(ME_Subject arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ME_patternSubjectUnlocatable, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ME_hasSubjectId(ME_Subject arg) */

ATbool ME_hasSubjectId(ME_Subject arg)
{
  if (ME_isSubjectLocatable(arg)) {
    return ATtrue;
  }
  else if (ME_isSubjectUnlocatable(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* ME_getSubjectId(ME_Subject arg) */

char* ME_getSubjectId(ME_Subject arg)
{
  if (ME_isSubjectLocatable(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
  }
  else 
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  ME_Subject ME_setSubjectId(ME_Subject arg, char* id) */

ME_Subject ME_setSubjectId(ME_Subject arg, char* id)
{
  if (ME_isSubjectLocatable(arg)) {
    return (ME_Subject)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(id, 0, ATtrue))), 0);
  }
  else if (ME_isSubjectUnlocatable(arg)) {
    return (ME_Subject)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(id, 0, ATtrue))), 0);
  }

  ATabort("Subject has no Id: %t\n", arg);
  return (ME_Subject)NULL;
}

/*}}}  */
/*{{{  ATbool ME_hasSubjectLocation(ME_Subject arg) */

ATbool ME_hasSubjectLocation(ME_Subject arg)
{
  if (ME_isSubjectLocatable(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ME_Location ME_getSubjectLocation(ME_Subject arg) */

ME_Location ME_getSubjectLocation(ME_Subject arg)
{
  
    return (ME_Location)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  ME_Subject ME_setSubjectLocation(ME_Subject arg, ME_Location Location) */

ME_Subject ME_setSubjectLocation(ME_Subject arg, ME_Location Location)
{
  if (ME_isSubjectLocatable(arg)) {
    return (ME_Subject)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) Location), 1);
  }

  ATabort("Subject has no Location: %t\n", arg);
  return (ME_Subject)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ME_Location accessors */

/*{{{  ATbool ME_isValidLocation(ME_Location arg) */

ATbool ME_isValidLocation(ME_Location arg)
{
  if (ME_isLocationLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ME_isLocationLocation(ME_Location arg) */

inline ATbool ME_isLocationLocation(ME_Location arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ME_patternLocationLocation, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool ME_hasLocationFilename(ME_Location arg) */

ATbool ME_hasLocationFilename(ME_Location arg)
{
  if (ME_isLocationLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* ME_getLocationFilename(ME_Location arg) */

char* ME_getLocationFilename(ME_Location arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  ME_Location ME_setLocationFilename(ME_Location arg, char* filename) */

ME_Location ME_setLocationFilename(ME_Location arg, char* filename)
{
  if (ME_isLocationLocation(arg)) {
    return (ME_Location)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(filename, 0, ATtrue))), 0);
  }

  ATabort("Location has no Filename: %t\n", arg);
  return (ME_Location)NULL;
}

/*}}}  */
/*{{{  ATbool ME_hasLocationArea(ME_Location arg) */

ATbool ME_hasLocationArea(ME_Location arg)
{
  if (ME_isLocationLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ME_Area ME_getLocationArea(ME_Location arg) */

ME_Area ME_getLocationArea(ME_Location arg)
{
  
    return (ME_Area)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  ME_Location ME_setLocationArea(ME_Location arg, ME_Area Area) */

ME_Location ME_setLocationArea(ME_Location arg, ME_Area Area)
{
  if (ME_isLocationLocation(arg)) {
    return (ME_Location)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) Area), 1);
  }

  ATabort("Location has no Area: %t\n", arg);
  return (ME_Location)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ME_Area accessors */

/*{{{  ATbool ME_isValidArea(ME_Area arg) */

ATbool ME_isValidArea(ME_Area arg)
{
  if (ME_isAreaArea(arg)) {
    return ATtrue;
  }
  else if (ME_isAreaNoArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ME_isAreaArea(ME_Area arg) */

inline ATbool ME_isAreaArea(ME_Area arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ME_patternAreaArea, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ME_isAreaNoArea(ME_Area arg) */

inline ATbool ME_isAreaNoArea(ME_Area arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ME_patternAreaNoArea);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ME_hasAreaStartLine(ME_Area arg) */

ATbool ME_hasAreaStartLine(ME_Area arg)
{
  if (ME_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int ME_getAreaStartLine(ME_Area arg) */

int ME_getAreaStartLine(ME_Area arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

/*}}}  */
/*{{{  ME_Area ME_setAreaStartLine(ME_Area arg, int startLine) */

ME_Area ME_setAreaStartLine(ME_Area arg, int startLine)
{
  if (ME_isAreaArea(arg)) {
    return (ME_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(startLine)), 0);
  }

  ATabort("Area has no StartLine: %t\n", arg);
  return (ME_Area)NULL;
}

/*}}}  */
/*{{{  ATbool ME_hasAreaStartColumn(ME_Area arg) */

ATbool ME_hasAreaStartColumn(ME_Area arg)
{
  if (ME_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int ME_getAreaStartColumn(ME_Area arg) */

int ME_getAreaStartColumn(ME_Area arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  ME_Area ME_setAreaStartColumn(ME_Area arg, int startColumn) */

ME_Area ME_setAreaStartColumn(ME_Area arg, int startColumn)
{
  if (ME_isAreaArea(arg)) {
    return (ME_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(startColumn)), 1);
  }

  ATabort("Area has no StartColumn: %t\n", arg);
  return (ME_Area)NULL;
}

/*}}}  */
/*{{{  ATbool ME_hasAreaEndLine(ME_Area arg) */

ATbool ME_hasAreaEndLine(ME_Area arg)
{
  if (ME_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int ME_getAreaEndLine(ME_Area arg) */

int ME_getAreaEndLine(ME_Area arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 2));
}

/*}}}  */
/*{{{  ME_Area ME_setAreaEndLine(ME_Area arg, int endLine) */

ME_Area ME_setAreaEndLine(ME_Area arg, int endLine)
{
  if (ME_isAreaArea(arg)) {
    return (ME_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(endLine)), 2);
  }

  ATabort("Area has no EndLine: %t\n", arg);
  return (ME_Area)NULL;
}

/*}}}  */
/*{{{  ATbool ME_hasAreaEndColumn(ME_Area arg) */

ATbool ME_hasAreaEndColumn(ME_Area arg)
{
  if (ME_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int ME_getAreaEndColumn(ME_Area arg) */

int ME_getAreaEndColumn(ME_Area arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 3));
}

/*}}}  */
/*{{{  ME_Area ME_setAreaEndColumn(ME_Area arg, int endColumn) */

ME_Area ME_setAreaEndColumn(ME_Area arg, int endColumn)
{
  if (ME_isAreaArea(arg)) {
    return (ME_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(endColumn)), 3);
  }

  ATabort("Area has no EndColumn: %t\n", arg);
  return (ME_Area)NULL;
}

/*}}}  */
/*{{{  ATbool ME_hasAreaStartOffset(ME_Area arg) */

ATbool ME_hasAreaStartOffset(ME_Area arg)
{
  if (ME_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int ME_getAreaStartOffset(ME_Area arg) */

int ME_getAreaStartOffset(ME_Area arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 4));
}

/*}}}  */
/*{{{  ME_Area ME_setAreaStartOffset(ME_Area arg, int startOffset) */

ME_Area ME_setAreaStartOffset(ME_Area arg, int startOffset)
{
  if (ME_isAreaArea(arg)) {
    return (ME_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(startOffset)), 4);
  }

  ATabort("Area has no StartOffset: %t\n", arg);
  return (ME_Area)NULL;
}

/*}}}  */
/*{{{  ATbool ME_hasAreaEndOffset(ME_Area arg) */

ATbool ME_hasAreaEndOffset(ME_Area arg)
{
  if (ME_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int ME_getAreaEndOffset(ME_Area arg) */

int ME_getAreaEndOffset(ME_Area arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 5));
}

/*}}}  */
/*{{{  ME_Area ME_setAreaEndOffset(ME_Area arg, int endOffset) */

ME_Area ME_setAreaEndOffset(ME_Area arg, int endOffset)
{
  if (ME_isAreaArea(arg)) {
    return (ME_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(endOffset)), 5);
  }

  ATabort("Area has no EndOffset: %t\n", arg);
  return (ME_Area)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  ME_Feedback ME_visitFeedback(ME_Feedback arg, char* (*acceptId)(char*), char* (*acceptProducerId)(char*), char* (*acceptProducerType)(char*), char* (*acceptDescription)(char*), ME_SubjectList (*acceptList)(ME_SubjectList)) */

ME_Feedback ME_visitFeedback(ME_Feedback arg, char* (*acceptId)(char*), char* (*acceptProducerId)(char*), char* (*acceptProducerType)(char*), char* (*acceptDescription)(char*), ME_SubjectList (*acceptList)(ME_SubjectList))
{
  if (ME_isFeedbackInfo(arg)) {
    return ME_makeFeedbackInfo(
        acceptId ? acceptId(ME_getFeedbackId(arg)) : ME_getFeedbackId(arg),
        acceptProducerId ? acceptProducerId(ME_getFeedbackProducerId(arg)) : ME_getFeedbackProducerId(arg),
        acceptProducerType ? acceptProducerType(ME_getFeedbackProducerType(arg)) : ME_getFeedbackProducerType(arg),
        acceptDescription ? acceptDescription(ME_getFeedbackDescription(arg)) : ME_getFeedbackDescription(arg),
        acceptList ? acceptList(ME_getFeedbackList(arg)) : ME_getFeedbackList(arg));
  }
  if (ME_isFeedbackWarning(arg)) {
    return ME_makeFeedbackWarning(
        acceptId ? acceptId(ME_getFeedbackId(arg)) : ME_getFeedbackId(arg),
        acceptProducerId ? acceptProducerId(ME_getFeedbackProducerId(arg)) : ME_getFeedbackProducerId(arg),
        acceptProducerType ? acceptProducerType(ME_getFeedbackProducerType(arg)) : ME_getFeedbackProducerType(arg),
        acceptDescription ? acceptDescription(ME_getFeedbackDescription(arg)) : ME_getFeedbackDescription(arg),
        acceptList ? acceptList(ME_getFeedbackList(arg)) : ME_getFeedbackList(arg));
  }
  if (ME_isFeedbackError(arg)) {
    return ME_makeFeedbackError(
        acceptId ? acceptId(ME_getFeedbackId(arg)) : ME_getFeedbackId(arg),
        acceptProducerId ? acceptProducerId(ME_getFeedbackProducerId(arg)) : ME_getFeedbackProducerId(arg),
        acceptProducerType ? acceptProducerType(ME_getFeedbackProducerType(arg)) : ME_getFeedbackProducerType(arg),
        acceptDescription ? acceptDescription(ME_getFeedbackDescription(arg)) : ME_getFeedbackDescription(arg),
        acceptList ? acceptList(ME_getFeedbackList(arg)) : ME_getFeedbackList(arg));
  }
  if (ME_isFeedbackFatalError(arg)) {
    return ME_makeFeedbackFatalError(
        acceptId ? acceptId(ME_getFeedbackId(arg)) : ME_getFeedbackId(arg),
        acceptProducerId ? acceptProducerId(ME_getFeedbackProducerId(arg)) : ME_getFeedbackProducerId(arg),
        acceptProducerType ? acceptProducerType(ME_getFeedbackProducerType(arg)) : ME_getFeedbackProducerType(arg),
        acceptDescription ? acceptDescription(ME_getFeedbackDescription(arg)) : ME_getFeedbackDescription(arg),
        acceptList ? acceptList(ME_getFeedbackList(arg)) : ME_getFeedbackList(arg));
  }
  ATabort("not a Feedback: %t\n", arg);
  return (ME_Feedback)NULL;
}

/*}}}  */
/*{{{  ME_SubjectList ME_visitSubjectList(ME_SubjectList arg, ME_Subject (*acceptHead)(ME_Subject)) */

ME_SubjectList ME_visitSubjectList(ME_SubjectList arg, ME_Subject (*acceptHead)(ME_Subject))
{
  if (ME_isSubjectListEmpty(arg)) {
    return ME_makeSubjectListEmpty();
  }
  if (ME_isSubjectListSingle(arg)) {
    return ME_makeSubjectListSingle(
        acceptHead ? acceptHead(ME_getSubjectListHead(arg)) : ME_getSubjectListHead(arg));
  }
  if (ME_isSubjectListMany(arg)) {
    return ME_makeSubjectListMany(
        acceptHead ? acceptHead(ME_getSubjectListHead(arg)) : ME_getSubjectListHead(arg),
        ME_visitSubjectList(ME_getSubjectListTail(arg), acceptHead));
  }
  ATabort("not a SubjectList: %t\n", arg);
  return (ME_SubjectList)NULL;
}

/*}}}  */
/*{{{  ME_Subject ME_visitSubject(ME_Subject arg, char* (*acceptId)(char*), ME_Location (*acceptLocation)(ME_Location)) */

ME_Subject ME_visitSubject(ME_Subject arg, char* (*acceptId)(char*), ME_Location (*acceptLocation)(ME_Location))
{
  if (ME_isSubjectLocatable(arg)) {
    return ME_makeSubjectLocatable(
        acceptId ? acceptId(ME_getSubjectId(arg)) : ME_getSubjectId(arg),
        acceptLocation ? acceptLocation(ME_getSubjectLocation(arg)) : ME_getSubjectLocation(arg));
  }
  if (ME_isSubjectUnlocatable(arg)) {
    return ME_makeSubjectUnlocatable(
        acceptId ? acceptId(ME_getSubjectId(arg)) : ME_getSubjectId(arg));
  }
  ATabort("not a Subject: %t\n", arg);
  return (ME_Subject)NULL;
}

/*}}}  */
/*{{{  ME_Location ME_visitLocation(ME_Location arg, char* (*acceptFilename)(char*), ME_Area (*acceptArea)(ME_Area)) */

ME_Location ME_visitLocation(ME_Location arg, char* (*acceptFilename)(char*), ME_Area (*acceptArea)(ME_Area))
{
  if (ME_isLocationLocation(arg)) {
    return ME_makeLocationLocation(
        acceptFilename ? acceptFilename(ME_getLocationFilename(arg)) : ME_getLocationFilename(arg),
        acceptArea ? acceptArea(ME_getLocationArea(arg)) : ME_getLocationArea(arg));
  }
  ATabort("not a Location: %t\n", arg);
  return (ME_Location)NULL;
}

/*}}}  */
/*{{{  ME_Area ME_visitArea(ME_Area arg, int (*acceptStartLine)(int), int (*acceptStartColumn)(int), int (*acceptEndLine)(int), int (*acceptEndColumn)(int), int (*acceptStartOffset)(int), int (*acceptEndOffset)(int)) */

ME_Area ME_visitArea(ME_Area arg, int (*acceptStartLine)(int), int (*acceptStartColumn)(int), int (*acceptEndLine)(int), int (*acceptEndColumn)(int), int (*acceptStartOffset)(int), int (*acceptEndOffset)(int))
{
  if (ME_isAreaArea(arg)) {
    return ME_makeAreaArea(
        acceptStartLine ? acceptStartLine(ME_getAreaStartLine(arg)) : ME_getAreaStartLine(arg),
        acceptStartColumn ? acceptStartColumn(ME_getAreaStartColumn(arg)) : ME_getAreaStartColumn(arg),
        acceptEndLine ? acceptEndLine(ME_getAreaEndLine(arg)) : ME_getAreaEndLine(arg),
        acceptEndColumn ? acceptEndColumn(ME_getAreaEndColumn(arg)) : ME_getAreaEndColumn(arg),
        acceptStartOffset ? acceptStartOffset(ME_getAreaStartOffset(arg)) : ME_getAreaStartOffset(arg),
        acceptEndOffset ? acceptEndOffset(ME_getAreaEndOffset(arg)) : ME_getAreaEndOffset(arg));
  }
  if (ME_isAreaNoArea(arg)) {
    return ME_makeAreaNoArea();
  }
  ATabort("not a Area: %t\n", arg);
  return (ME_Area)NULL;
}

/*}}}  */

/*}}}  */
