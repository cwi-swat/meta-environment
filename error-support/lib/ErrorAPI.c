#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "ErrorAPI.h"

/*{{{  conversion functions */

ATerm ERR_stringToChars(const char *str)
{
  int len = strlen(str);
  int i;
  ATermList result = ATempty;

  for (i = len - 1; i >= 0; i--) {
    result = ATinsert(result, (ATerm) ATmakeInt(str[i]));
  }

  return (ATerm) result;
}

char *ERR_charsToString(ATerm arg)
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

typedef struct ATerm _ERR_Feedback;
typedef struct ATerm _ERR_SubjectList;
typedef struct ATerm _ERR_Subject;
typedef struct ATerm _ERR_Location;
typedef struct ATerm _ERR_Area;

/*}}}  */

/*{{{  void ERR_initErrorAPIApi(void) */

void ERR_initErrorAPIApi(void)
{
  init_ErrorAPI_dict();
}

/*}}}  */

/*{{{  term conversion functions */

/*{{{  ERR_Feedback ERR_FeedbackFromTerm(ATerm t) */

ERR_Feedback ERR_FeedbackFromTerm(ATerm t)
{
  return (ERR_Feedback)t;
}

/*}}}  */
/*{{{  ATerm ERR_FeedbackToTerm(ERR_Feedback arg) */

ATerm ERR_FeedbackToTerm(ERR_Feedback arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ERR_SubjectList ERR_SubjectListFromTerm(ATerm t) */

ERR_SubjectList ERR_SubjectListFromTerm(ATerm t)
{
  return (ERR_SubjectList)t;
}

/*}}}  */
/*{{{  ATerm ERR_SubjectListToTerm(ERR_SubjectList arg) */

ATerm ERR_SubjectListToTerm(ERR_SubjectList arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ERR_Subject ERR_SubjectFromTerm(ATerm t) */

ERR_Subject ERR_SubjectFromTerm(ATerm t)
{
  return (ERR_Subject)t;
}

/*}}}  */
/*{{{  ATerm ERR_SubjectToTerm(ERR_Subject arg) */

ATerm ERR_SubjectToTerm(ERR_Subject arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ERR_Location ERR_LocationFromTerm(ATerm t) */

ERR_Location ERR_LocationFromTerm(ATerm t)
{
  return (ERR_Location)t;
}

/*}}}  */
/*{{{  ATerm ERR_LocationToTerm(ERR_Location arg) */

ATerm ERR_LocationToTerm(ERR_Location arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ERR_Area ERR_AreaFromTerm(ATerm t) */

ERR_Area ERR_AreaFromTerm(ATerm t)
{
  return (ERR_Area)t;
}

/*}}}  */
/*{{{  ATerm ERR_AreaToTerm(ERR_Area arg) */

ATerm ERR_AreaToTerm(ERR_Area arg)
{
  return (ATerm)arg;
}

/*}}}  */

/*}}}  */
/*{{{  list functions */

int ERR_getSubjectListLength (ERR_SubjectList arg) {
  return ATgetLength((ATermList) arg);
}
ERR_SubjectList ERR_reverseSubjectList(ERR_SubjectList arg) {
  return (ERR_SubjectList) ATreverse((ATermList) arg);
}
ERR_SubjectList ERR_appendSubjectList(ERR_SubjectList arg, ERR_Subject elem) {
  return (ERR_SubjectList) ATappend((ATermList) arg, (ATerm) ((ATerm) elem));
}
ERR_SubjectList ERR_concatSubjectList(ERR_SubjectList arg0, ERR_SubjectList arg1) {
  return (ERR_SubjectList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
ERR_SubjectList ERR_sliceSubjectList(ERR_SubjectList arg, int start, int end) {
  return (ERR_SubjectList) ATgetSlice((ATermList) arg, start, end);
}
ERR_Subject ERR_getSubjectListSubjectAt(ERR_SubjectList arg, int index) {
 return (ERR_Subject)ATelementAt((ATermList) arg,index);
}
ERR_SubjectList ERR_replaceSubjectListSubjectAt(ERR_SubjectList arg, ERR_Subject elem, int index) {
 return (ERR_SubjectList) ATreplace((ATermList) arg, (ATerm) ((ATerm) elem), index);
}
ERR_SubjectList ERR_makeSubjectList2(ERR_Subject elem1, ERR_Subject elem2) {
  return (ERR_SubjectList) ATmakeList2((ATerm) ((ATerm) elem2), (ATerm) ((ATerm) elem2));
}
ERR_SubjectList ERR_makeSubjectList3(ERR_Subject elem1, ERR_Subject elem2, ERR_Subject elem3) {
  return (ERR_SubjectList) ATmakeList3((ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3), (ATerm) ((ATerm) elem3));
}
ERR_SubjectList ERR_makeSubjectList4(ERR_Subject elem1, ERR_Subject elem2, ERR_Subject elem3, ERR_Subject elem4) {
  return (ERR_SubjectList) ATmakeList4((ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4), (ATerm) ((ATerm) elem4));
}
ERR_SubjectList ERR_makeSubjectList5(ERR_Subject elem1, ERR_Subject elem2, ERR_Subject elem3, ERR_Subject elem4, ERR_Subject elem5) {
  return (ERR_SubjectList) ATmakeList5((ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5), (ATerm) ((ATerm) elem5));
}
ERR_SubjectList ERR_makeSubjectList6(ERR_Subject elem1, ERR_Subject elem2, ERR_Subject elem3, ERR_Subject elem4, ERR_Subject elem5, ERR_Subject elem6) {
  return (ERR_SubjectList) ATmakeList6((ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6), (ATerm) ((ATerm) elem6));
}

/*}}}  */
/*{{{  constructors */

/*{{{  ERR_Feedback ERR_makeFeedbackInfo(char* id, char* producerId, char* producerType, char* description, ERR_SubjectList list) */

ERR_Feedback ERR_makeFeedbackInfo(char* id, char* producerId, char* producerType, char* description, ERR_SubjectList list)
{
  return (ERR_Feedback)(ATerm)ATmakeAppl5(ERR_afun0, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(id, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(producerId, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(producerType, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(description, 0, ATtrue)), (ATerm) list);
}

/*}}}  */
/*{{{  ERR_Feedback ERR_makeFeedbackWarning(char* id, char* producerId, char* producerType, char* description, ERR_SubjectList list) */

ERR_Feedback ERR_makeFeedbackWarning(char* id, char* producerId, char* producerType, char* description, ERR_SubjectList list)
{
  return (ERR_Feedback)(ATerm)ATmakeAppl5(ERR_afun1, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(id, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(producerId, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(producerType, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(description, 0, ATtrue)), (ATerm) list);
}

/*}}}  */
/*{{{  ERR_Feedback ERR_makeFeedbackError(char* id, char* producerId, char* producerType, char* description, ERR_SubjectList list) */

ERR_Feedback ERR_makeFeedbackError(char* id, char* producerId, char* producerType, char* description, ERR_SubjectList list)
{
  return (ERR_Feedback)(ATerm)ATmakeAppl5(ERR_afun2, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(id, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(producerId, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(producerType, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(description, 0, ATtrue)), (ATerm) list);
}

/*}}}  */
/*{{{  ERR_Feedback ERR_makeFeedbackFatalError(char* id, char* producerId, char* producerType, char* description, ERR_SubjectList list) */

ERR_Feedback ERR_makeFeedbackFatalError(char* id, char* producerId, char* producerType, char* description, ERR_SubjectList list)
{
  return (ERR_Feedback)(ATerm)ATmakeAppl5(ERR_afun3, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(id, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(producerId, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(producerType, 0, ATtrue)), (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(description, 0, ATtrue)), (ATerm) list);
}

/*}}}  */
/*{{{  ERR_SubjectList ERR_makeSubjectListEmpty() */

ERR_SubjectList ERR_makeSubjectListEmpty()
{
  return (ERR_SubjectList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  ERR_SubjectList ERR_makeSubjectListSingle(ERR_Subject head) */

ERR_SubjectList ERR_makeSubjectListSingle(ERR_Subject head)
{
  return (ERR_SubjectList)(ATerm)ATmakeList1((ATerm) head);
}

/*}}}  */
/*{{{  ERR_SubjectList ERR_makeSubjectListMany(ERR_Subject head, ERR_SubjectList tail) */

ERR_SubjectList ERR_makeSubjectListMany(ERR_Subject head, ERR_SubjectList tail)
{
  return (ERR_SubjectList)(ATerm)ATinsert((ATermList)tail, (ATerm) head);
}

/*}}}  */
/*{{{  ERR_Subject ERR_makeSubjectSubject(char* id, ERR_Location Location) */

ERR_Subject ERR_makeSubjectSubject(char* id, ERR_Location Location)
{
  return (ERR_Subject)(ATerm)ATmakeAppl2(ERR_afun4, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(id, 0, ATtrue)), (ATerm) Location);
}

/*}}}  */
/*{{{  ERR_Location ERR_makeLocationLocation(char* filename, ERR_Area Area) */

ERR_Location ERR_makeLocationLocation(char* filename, ERR_Area Area)
{
  return (ERR_Location)(ATerm)ATmakeAppl2(ERR_afun5, (ATerm) (ATerm) ATmakeAppl(ATmakeAFun(filename, 0, ATtrue)), (ATerm) Area);
}

/*}}}  */
/*{{{  ERR_Area ERR_makeAreaArea(int startLine, int startColumn, int endLine, int endColumn, int startOffset, int endOffset) */

ERR_Area ERR_makeAreaArea(int startLine, int startColumn, int endLine, int endColumn, int startOffset, int endOffset)
{
  return (ERR_Area)(ATerm)ATmakeAppl6(ERR_afun6, (ATerm) (ATerm) ATmakeInt(startLine), (ATerm) (ATerm) ATmakeInt(startColumn), (ATerm) (ATerm) ATmakeInt(endLine), (ATerm) (ATerm) ATmakeInt(endColumn), (ATerm) (ATerm) ATmakeInt(startOffset), (ATerm) (ATerm) ATmakeInt(endOffset));
}

/*}}}  */
/*{{{  ERR_Area ERR_makeAreaNoArea() */

ERR_Area ERR_makeAreaNoArea()
{
  return (ERR_Area)(ATerm)ATmakeAppl0(ERR_afun7);
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool ERR_isEqualFeedback(ERR_Feedback arg0, ERR_Feedback arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ERR_isEqualSubjectList(ERR_SubjectList arg0, ERR_SubjectList arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ERR_isEqualSubject(ERR_Subject arg0, ERR_Subject arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ERR_isEqualLocation(ERR_Location arg0, ERR_Location arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ERR_isEqualArea(ERR_Area arg0, ERR_Area arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

/*}}}  */
/*{{{  ERR_Feedback accessors */

/*{{{  ATbool ERR_isValidFeedback(ERR_Feedback arg) */

ATbool ERR_isValidFeedback(ERR_Feedback arg)
{
  if (ERR_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (ERR_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (ERR_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (ERR_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ERR_isFeedbackInfo(ERR_Feedback arg) */

inline ATbool ERR_isFeedbackInfo(ERR_Feedback arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ERR_patternFeedbackInfo, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ERR_isFeedbackWarning(ERR_Feedback arg) */

inline ATbool ERR_isFeedbackWarning(ERR_Feedback arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ERR_patternFeedbackWarning, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ERR_isFeedbackError(ERR_Feedback arg) */

inline ATbool ERR_isFeedbackError(ERR_Feedback arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ERR_patternFeedbackError, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ERR_isFeedbackFatalError(ERR_Feedback arg) */

inline ATbool ERR_isFeedbackFatalError(ERR_Feedback arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ERR_patternFeedbackFatalError, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ERR_hasFeedbackId(ERR_Feedback arg) */

ATbool ERR_hasFeedbackId(ERR_Feedback arg)
{
  if (ERR_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (ERR_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (ERR_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (ERR_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* ERR_getFeedbackId(ERR_Feedback arg) */

char* ERR_getFeedbackId(ERR_Feedback arg)
{
  if (ERR_isFeedbackInfo(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
  }
  else if (ERR_isFeedbackWarning(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
  }
  else if (ERR_isFeedbackError(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
  }
  else 
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  ERR_Feedback ERR_setFeedbackId(ERR_Feedback arg, char* id) */

ERR_Feedback ERR_setFeedbackId(ERR_Feedback arg, char* id)
{
  if (ERR_isFeedbackInfo(arg)) {
    return (ERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(id, 0, ATtrue))), 0);
  }
  else if (ERR_isFeedbackWarning(arg)) {
    return (ERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(id, 0, ATtrue))), 0);
  }
  else if (ERR_isFeedbackError(arg)) {
    return (ERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(id, 0, ATtrue))), 0);
  }
  else if (ERR_isFeedbackFatalError(arg)) {
    return (ERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(id, 0, ATtrue))), 0);
  }

  ATabort("Feedback has no Id: %t\n", arg);
  return (ERR_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool ERR_hasFeedbackProducerId(ERR_Feedback arg) */

ATbool ERR_hasFeedbackProducerId(ERR_Feedback arg)
{
  if (ERR_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (ERR_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (ERR_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (ERR_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* ERR_getFeedbackProducerId(ERR_Feedback arg) */

char* ERR_getFeedbackProducerId(ERR_Feedback arg)
{
  if (ERR_isFeedbackInfo(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
  }
  else if (ERR_isFeedbackWarning(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
  }
  else if (ERR_isFeedbackError(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
  }
  else 
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  ERR_Feedback ERR_setFeedbackProducerId(ERR_Feedback arg, char* producerId) */

ERR_Feedback ERR_setFeedbackProducerId(ERR_Feedback arg, char* producerId)
{
  if (ERR_isFeedbackInfo(arg)) {
    return (ERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(producerId, 0, ATtrue))), 1);
  }
  else if (ERR_isFeedbackWarning(arg)) {
    return (ERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(producerId, 0, ATtrue))), 1);
  }
  else if (ERR_isFeedbackError(arg)) {
    return (ERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(producerId, 0, ATtrue))), 1);
  }
  else if (ERR_isFeedbackFatalError(arg)) {
    return (ERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(producerId, 0, ATtrue))), 1);
  }

  ATabort("Feedback has no ProducerId: %t\n", arg);
  return (ERR_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool ERR_hasFeedbackProducerType(ERR_Feedback arg) */

ATbool ERR_hasFeedbackProducerType(ERR_Feedback arg)
{
  if (ERR_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (ERR_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (ERR_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (ERR_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* ERR_getFeedbackProducerType(ERR_Feedback arg) */

char* ERR_getFeedbackProducerType(ERR_Feedback arg)
{
  if (ERR_isFeedbackInfo(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 2)));
  }
  else if (ERR_isFeedbackWarning(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 2)));
  }
  else if (ERR_isFeedbackError(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 2)));
  }
  else 
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 2)));
}

/*}}}  */
/*{{{  ERR_Feedback ERR_setFeedbackProducerType(ERR_Feedback arg, char* producerType) */

ERR_Feedback ERR_setFeedbackProducerType(ERR_Feedback arg, char* producerType)
{
  if (ERR_isFeedbackInfo(arg)) {
    return (ERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(producerType, 0, ATtrue))), 2);
  }
  else if (ERR_isFeedbackWarning(arg)) {
    return (ERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(producerType, 0, ATtrue))), 2);
  }
  else if (ERR_isFeedbackError(arg)) {
    return (ERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(producerType, 0, ATtrue))), 2);
  }
  else if (ERR_isFeedbackFatalError(arg)) {
    return (ERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(producerType, 0, ATtrue))), 2);
  }

  ATabort("Feedback has no ProducerType: %t\n", arg);
  return (ERR_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool ERR_hasFeedbackDescription(ERR_Feedback arg) */

ATbool ERR_hasFeedbackDescription(ERR_Feedback arg)
{
  if (ERR_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (ERR_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (ERR_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (ERR_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* ERR_getFeedbackDescription(ERR_Feedback arg) */

char* ERR_getFeedbackDescription(ERR_Feedback arg)
{
  if (ERR_isFeedbackInfo(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 3)));
  }
  else if (ERR_isFeedbackWarning(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 3)));
  }
  else if (ERR_isFeedbackError(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 3)));
  }
  else 
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 3)));
}

/*}}}  */
/*{{{  ERR_Feedback ERR_setFeedbackDescription(ERR_Feedback arg, char* description) */

ERR_Feedback ERR_setFeedbackDescription(ERR_Feedback arg, char* description)
{
  if (ERR_isFeedbackInfo(arg)) {
    return (ERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(description, 0, ATtrue))), 3);
  }
  else if (ERR_isFeedbackWarning(arg)) {
    return (ERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(description, 0, ATtrue))), 3);
  }
  else if (ERR_isFeedbackError(arg)) {
    return (ERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(description, 0, ATtrue))), 3);
  }
  else if (ERR_isFeedbackFatalError(arg)) {
    return (ERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(description, 0, ATtrue))), 3);
  }

  ATabort("Feedback has no Description: %t\n", arg);
  return (ERR_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool ERR_hasFeedbackList(ERR_Feedback arg) */

ATbool ERR_hasFeedbackList(ERR_Feedback arg)
{
  if (ERR_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  else if (ERR_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  else if (ERR_isFeedbackError(arg)) {
    return ATtrue;
  }
  else if (ERR_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ERR_SubjectList ERR_getFeedbackList(ERR_Feedback arg) */

ERR_SubjectList ERR_getFeedbackList(ERR_Feedback arg)
{
  if (ERR_isFeedbackInfo(arg)) {
    return (ERR_SubjectList)ATgetArgument((ATermAppl)arg, 4);
  }
  else if (ERR_isFeedbackWarning(arg)) {
    return (ERR_SubjectList)ATgetArgument((ATermAppl)arg, 4);
  }
  else if (ERR_isFeedbackError(arg)) {
    return (ERR_SubjectList)ATgetArgument((ATermAppl)arg, 4);
  }
  else 
    return (ERR_SubjectList)ATgetArgument((ATermAppl)arg, 4);
}

/*}}}  */
/*{{{  ERR_Feedback ERR_setFeedbackList(ERR_Feedback arg, ERR_SubjectList list) */

ERR_Feedback ERR_setFeedbackList(ERR_Feedback arg, ERR_SubjectList list)
{
  if (ERR_isFeedbackInfo(arg)) {
    return (ERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) list), 4);
  }
  else if (ERR_isFeedbackWarning(arg)) {
    return (ERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) list), 4);
  }
  else if (ERR_isFeedbackError(arg)) {
    return (ERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) list), 4);
  }
  else if (ERR_isFeedbackFatalError(arg)) {
    return (ERR_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) list), 4);
  }

  ATabort("Feedback has no List: %t\n", arg);
  return (ERR_Feedback)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ERR_SubjectList accessors */

/*{{{  ATbool ERR_isValidSubjectList(ERR_SubjectList arg) */

ATbool ERR_isValidSubjectList(ERR_SubjectList arg)
{
  if (ERR_isSubjectListEmpty(arg)) {
    return ATtrue;
  }
  else if (ERR_isSubjectListSingle(arg)) {
    return ATtrue;
  }
  else if (ERR_isSubjectListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ERR_isSubjectListEmpty(ERR_SubjectList arg) */

inline ATbool ERR_isSubjectListEmpty(ERR_SubjectList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ERR_patternSubjectListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool ERR_isSubjectListSingle(ERR_SubjectList arg) */

inline ATbool ERR_isSubjectListSingle(ERR_SubjectList arg)
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
      last_result = ATmatchTerm((ATerm)arg, ERR_patternSubjectListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ERR_isSubjectListMany(ERR_SubjectList arg) */

inline ATbool ERR_isSubjectListMany(ERR_SubjectList arg)
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
      last_result = ATmatchTerm((ATerm)arg, ERR_patternSubjectListMany, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ERR_hasSubjectListHead(ERR_SubjectList arg) */

ATbool ERR_hasSubjectListHead(ERR_SubjectList arg)
{
  if (ERR_isSubjectListSingle(arg)) {
    return ATtrue;
  }
  else if (ERR_isSubjectListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ERR_Subject ERR_getSubjectListHead(ERR_SubjectList arg) */

ERR_Subject ERR_getSubjectListHead(ERR_SubjectList arg)
{
  if (ERR_isSubjectListSingle(arg)) {
    return (ERR_Subject)ATgetFirst((ATermList)arg);
  }
  else 
    return (ERR_Subject)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  ERR_SubjectList ERR_setSubjectListHead(ERR_SubjectList arg, ERR_Subject head) */

ERR_SubjectList ERR_setSubjectListHead(ERR_SubjectList arg, ERR_Subject head)
{
  if (ERR_isSubjectListSingle(arg)) {
    return (ERR_SubjectList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }
  else if (ERR_isSubjectListMany(arg)) {
    return (ERR_SubjectList)ATreplace((ATermList)arg, (ATerm)((ATerm) head), 0);
  }

  ATabort("SubjectList has no Head: %t\n", arg);
  return (ERR_SubjectList)NULL;
}

/*}}}  */
/*{{{  ATbool ERR_hasSubjectListTail(ERR_SubjectList arg) */

ATbool ERR_hasSubjectListTail(ERR_SubjectList arg)
{
  if (ERR_isSubjectListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ERR_SubjectList ERR_getSubjectListTail(ERR_SubjectList arg) */

ERR_SubjectList ERR_getSubjectListTail(ERR_SubjectList arg)
{
  
    return (ERR_SubjectList)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  ERR_SubjectList ERR_setSubjectListTail(ERR_SubjectList arg, ERR_SubjectList tail) */

ERR_SubjectList ERR_setSubjectListTail(ERR_SubjectList arg, ERR_SubjectList tail)
{
  if (ERR_isSubjectListMany(arg)) {
    return (ERR_SubjectList)ATreplaceTail((ATermList)arg, (ATermList)((ATerm) tail), 1);
  }

  ATabort("SubjectList has no Tail: %t\n", arg);
  return (ERR_SubjectList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ERR_Subject accessors */

/*{{{  ATbool ERR_isValidSubject(ERR_Subject arg) */

ATbool ERR_isValidSubject(ERR_Subject arg)
{
  if (ERR_isSubjectSubject(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ERR_isSubjectSubject(ERR_Subject arg) */

inline ATbool ERR_isSubjectSubject(ERR_Subject arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ERR_patternSubjectSubject, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool ERR_hasSubjectId(ERR_Subject arg) */

ATbool ERR_hasSubjectId(ERR_Subject arg)
{
  if (ERR_isSubjectSubject(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* ERR_getSubjectId(ERR_Subject arg) */

char* ERR_getSubjectId(ERR_Subject arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  ERR_Subject ERR_setSubjectId(ERR_Subject arg, char* id) */

ERR_Subject ERR_setSubjectId(ERR_Subject arg, char* id)
{
  if (ERR_isSubjectSubject(arg)) {
    return (ERR_Subject)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(id, 0, ATtrue))), 0);
  }

  ATabort("Subject has no Id: %t\n", arg);
  return (ERR_Subject)NULL;
}

/*}}}  */
/*{{{  ATbool ERR_hasSubjectLocation(ERR_Subject arg) */

ATbool ERR_hasSubjectLocation(ERR_Subject arg)
{
  if (ERR_isSubjectSubject(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ERR_Location ERR_getSubjectLocation(ERR_Subject arg) */

ERR_Location ERR_getSubjectLocation(ERR_Subject arg)
{
  
    return (ERR_Location)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  ERR_Subject ERR_setSubjectLocation(ERR_Subject arg, ERR_Location Location) */

ERR_Subject ERR_setSubjectLocation(ERR_Subject arg, ERR_Location Location)
{
  if (ERR_isSubjectSubject(arg)) {
    return (ERR_Subject)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) Location), 1);
  }

  ATabort("Subject has no Location: %t\n", arg);
  return (ERR_Subject)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ERR_Location accessors */

/*{{{  ATbool ERR_isValidLocation(ERR_Location arg) */

ATbool ERR_isValidLocation(ERR_Location arg)
{
  if (ERR_isLocationLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ERR_isLocationLocation(ERR_Location arg) */

inline ATbool ERR_isLocationLocation(ERR_Location arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ERR_patternLocationLocation, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool ERR_hasLocationFilename(ERR_Location arg) */

ATbool ERR_hasLocationFilename(ERR_Location arg)
{
  if (ERR_isLocationLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* ERR_getLocationFilename(ERR_Location arg) */

char* ERR_getLocationFilename(ERR_Location arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl) ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  ERR_Location ERR_setLocationFilename(ERR_Location arg, char* filename) */

ERR_Location ERR_setLocationFilename(ERR_Location arg, char* filename)
{
  if (ERR_isLocationLocation(arg)) {
    return (ERR_Location)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeAppl(ATmakeAFun(filename, 0, ATtrue))), 0);
  }

  ATabort("Location has no Filename: %t\n", arg);
  return (ERR_Location)NULL;
}

/*}}}  */
/*{{{  ATbool ERR_hasLocationArea(ERR_Location arg) */

ATbool ERR_hasLocationArea(ERR_Location arg)
{
  if (ERR_isLocationLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ERR_Area ERR_getLocationArea(ERR_Location arg) */

ERR_Area ERR_getLocationArea(ERR_Location arg)
{
  
    return (ERR_Area)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  ERR_Location ERR_setLocationArea(ERR_Location arg, ERR_Area Area) */

ERR_Location ERR_setLocationArea(ERR_Location arg, ERR_Area Area)
{
  if (ERR_isLocationLocation(arg)) {
    return (ERR_Location)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) Area), 1);
  }

  ATabort("Location has no Area: %t\n", arg);
  return (ERR_Location)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ERR_Area accessors */

/*{{{  ATbool ERR_isValidArea(ERR_Area arg) */

ATbool ERR_isValidArea(ERR_Area arg)
{
  if (ERR_isAreaArea(arg)) {
    return ATtrue;
  }
  else if (ERR_isAreaNoArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ERR_isAreaArea(ERR_Area arg) */

inline ATbool ERR_isAreaArea(ERR_Area arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ERR_patternAreaArea, NULL, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ERR_isAreaNoArea(ERR_Area arg) */

inline ATbool ERR_isAreaNoArea(ERR_Area arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ERR_patternAreaNoArea);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ERR_hasAreaStartLine(ERR_Area arg) */

ATbool ERR_hasAreaStartLine(ERR_Area arg)
{
  if (ERR_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int ERR_getAreaStartLine(ERR_Area arg) */

int ERR_getAreaStartLine(ERR_Area arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 0));
}

/*}}}  */
/*{{{  ERR_Area ERR_setAreaStartLine(ERR_Area arg, int startLine) */

ERR_Area ERR_setAreaStartLine(ERR_Area arg, int startLine)
{
  if (ERR_isAreaArea(arg)) {
    return (ERR_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(startLine)), 0);
  }

  ATabort("Area has no StartLine: %t\n", arg);
  return (ERR_Area)NULL;
}

/*}}}  */
/*{{{  ATbool ERR_hasAreaStartColumn(ERR_Area arg) */

ATbool ERR_hasAreaStartColumn(ERR_Area arg)
{
  if (ERR_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int ERR_getAreaStartColumn(ERR_Area arg) */

int ERR_getAreaStartColumn(ERR_Area arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  ERR_Area ERR_setAreaStartColumn(ERR_Area arg, int startColumn) */

ERR_Area ERR_setAreaStartColumn(ERR_Area arg, int startColumn)
{
  if (ERR_isAreaArea(arg)) {
    return (ERR_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(startColumn)), 1);
  }

  ATabort("Area has no StartColumn: %t\n", arg);
  return (ERR_Area)NULL;
}

/*}}}  */
/*{{{  ATbool ERR_hasAreaEndLine(ERR_Area arg) */

ATbool ERR_hasAreaEndLine(ERR_Area arg)
{
  if (ERR_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int ERR_getAreaEndLine(ERR_Area arg) */

int ERR_getAreaEndLine(ERR_Area arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 2));
}

/*}}}  */
/*{{{  ERR_Area ERR_setAreaEndLine(ERR_Area arg, int endLine) */

ERR_Area ERR_setAreaEndLine(ERR_Area arg, int endLine)
{
  if (ERR_isAreaArea(arg)) {
    return (ERR_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(endLine)), 2);
  }

  ATabort("Area has no EndLine: %t\n", arg);
  return (ERR_Area)NULL;
}

/*}}}  */
/*{{{  ATbool ERR_hasAreaEndColumn(ERR_Area arg) */

ATbool ERR_hasAreaEndColumn(ERR_Area arg)
{
  if (ERR_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int ERR_getAreaEndColumn(ERR_Area arg) */

int ERR_getAreaEndColumn(ERR_Area arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 3));
}

/*}}}  */
/*{{{  ERR_Area ERR_setAreaEndColumn(ERR_Area arg, int endColumn) */

ERR_Area ERR_setAreaEndColumn(ERR_Area arg, int endColumn)
{
  if (ERR_isAreaArea(arg)) {
    return (ERR_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(endColumn)), 3);
  }

  ATabort("Area has no EndColumn: %t\n", arg);
  return (ERR_Area)NULL;
}

/*}}}  */
/*{{{  ATbool ERR_hasAreaStartOffset(ERR_Area arg) */

ATbool ERR_hasAreaStartOffset(ERR_Area arg)
{
  if (ERR_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int ERR_getAreaStartOffset(ERR_Area arg) */

int ERR_getAreaStartOffset(ERR_Area arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 4));
}

/*}}}  */
/*{{{  ERR_Area ERR_setAreaStartOffset(ERR_Area arg, int startOffset) */

ERR_Area ERR_setAreaStartOffset(ERR_Area arg, int startOffset)
{
  if (ERR_isAreaArea(arg)) {
    return (ERR_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(startOffset)), 4);
  }

  ATabort("Area has no StartOffset: %t\n", arg);
  return (ERR_Area)NULL;
}

/*}}}  */
/*{{{  ATbool ERR_hasAreaEndOffset(ERR_Area arg) */

ATbool ERR_hasAreaEndOffset(ERR_Area arg)
{
  if (ERR_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int ERR_getAreaEndOffset(ERR_Area arg) */

int ERR_getAreaEndOffset(ERR_Area arg)
{
  
    return (int)ATgetInt((ATermInt) ATgetArgument((ATermAppl)arg, 5));
}

/*}}}  */
/*{{{  ERR_Area ERR_setAreaEndOffset(ERR_Area arg, int endOffset) */

ERR_Area ERR_setAreaEndOffset(ERR_Area arg, int endOffset)
{
  if (ERR_isAreaArea(arg)) {
    return (ERR_Area)ATsetArgument((ATermAppl)arg, (ATerm)((ATerm) (ATerm) ATmakeInt(endOffset)), 5);
  }

  ATabort("Area has no EndOffset: %t\n", arg);
  return (ERR_Area)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  ERR_Feedback ERR_visitFeedback(ERR_Feedback arg, char* (*acceptId)(char*), char* (*acceptProducerId)(char*), char* (*acceptProducerType)(char*), char* (*acceptDescription)(char*), ERR_SubjectList (*acceptList)(ERR_SubjectList)) */

ERR_Feedback ERR_visitFeedback(ERR_Feedback arg, char* (*acceptId)(char*), char* (*acceptProducerId)(char*), char* (*acceptProducerType)(char*), char* (*acceptDescription)(char*), ERR_SubjectList (*acceptList)(ERR_SubjectList))
{
  if (ERR_isFeedbackInfo(arg)) {
    return ERR_makeFeedbackInfo(
        acceptId ? acceptId(ERR_getFeedbackId(arg)) : ERR_getFeedbackId(arg),
        acceptProducerId ? acceptProducerId(ERR_getFeedbackProducerId(arg)) : ERR_getFeedbackProducerId(arg),
        acceptProducerType ? acceptProducerType(ERR_getFeedbackProducerType(arg)) : ERR_getFeedbackProducerType(arg),
        acceptDescription ? acceptDescription(ERR_getFeedbackDescription(arg)) : ERR_getFeedbackDescription(arg),
        acceptList ? acceptList(ERR_getFeedbackList(arg)) : ERR_getFeedbackList(arg));
  }
  if (ERR_isFeedbackWarning(arg)) {
    return ERR_makeFeedbackWarning(
        acceptId ? acceptId(ERR_getFeedbackId(arg)) : ERR_getFeedbackId(arg),
        acceptProducerId ? acceptProducerId(ERR_getFeedbackProducerId(arg)) : ERR_getFeedbackProducerId(arg),
        acceptProducerType ? acceptProducerType(ERR_getFeedbackProducerType(arg)) : ERR_getFeedbackProducerType(arg),
        acceptDescription ? acceptDescription(ERR_getFeedbackDescription(arg)) : ERR_getFeedbackDescription(arg),
        acceptList ? acceptList(ERR_getFeedbackList(arg)) : ERR_getFeedbackList(arg));
  }
  if (ERR_isFeedbackError(arg)) {
    return ERR_makeFeedbackError(
        acceptId ? acceptId(ERR_getFeedbackId(arg)) : ERR_getFeedbackId(arg),
        acceptProducerId ? acceptProducerId(ERR_getFeedbackProducerId(arg)) : ERR_getFeedbackProducerId(arg),
        acceptProducerType ? acceptProducerType(ERR_getFeedbackProducerType(arg)) : ERR_getFeedbackProducerType(arg),
        acceptDescription ? acceptDescription(ERR_getFeedbackDescription(arg)) : ERR_getFeedbackDescription(arg),
        acceptList ? acceptList(ERR_getFeedbackList(arg)) : ERR_getFeedbackList(arg));
  }
  if (ERR_isFeedbackFatalError(arg)) {
    return ERR_makeFeedbackFatalError(
        acceptId ? acceptId(ERR_getFeedbackId(arg)) : ERR_getFeedbackId(arg),
        acceptProducerId ? acceptProducerId(ERR_getFeedbackProducerId(arg)) : ERR_getFeedbackProducerId(arg),
        acceptProducerType ? acceptProducerType(ERR_getFeedbackProducerType(arg)) : ERR_getFeedbackProducerType(arg),
        acceptDescription ? acceptDescription(ERR_getFeedbackDescription(arg)) : ERR_getFeedbackDescription(arg),
        acceptList ? acceptList(ERR_getFeedbackList(arg)) : ERR_getFeedbackList(arg));
  }
  ATabort("not a Feedback: %t\n", arg);
  return (ERR_Feedback)NULL;
}

/*}}}  */
/*{{{  ERR_SubjectList ERR_visitSubjectList(ERR_SubjectList arg, ERR_Subject (*acceptHead)(ERR_Subject)) */

ERR_SubjectList ERR_visitSubjectList(ERR_SubjectList arg, ERR_Subject (*acceptHead)(ERR_Subject))
{
  if (ERR_isSubjectListEmpty(arg)) {
    return ERR_makeSubjectListEmpty();
  }
  if (ERR_isSubjectListSingle(arg)) {
    return ERR_makeSubjectListSingle(
        acceptHead ? acceptHead(ERR_getSubjectListHead(arg)) : ERR_getSubjectListHead(arg));
  }
  if (ERR_isSubjectListMany(arg)) {
    return ERR_makeSubjectListMany(
        acceptHead ? acceptHead(ERR_getSubjectListHead(arg)) : ERR_getSubjectListHead(arg),
        ERR_visitSubjectList(ERR_getSubjectListTail(arg), acceptHead));
  }
  ATabort("not a SubjectList: %t\n", arg);
  return (ERR_SubjectList)NULL;
}

/*}}}  */
/*{{{  ERR_Subject ERR_visitSubject(ERR_Subject arg, char* (*acceptId)(char*), ERR_Location (*acceptLocation)(ERR_Location)) */

ERR_Subject ERR_visitSubject(ERR_Subject arg, char* (*acceptId)(char*), ERR_Location (*acceptLocation)(ERR_Location))
{
  if (ERR_isSubjectSubject(arg)) {
    return ERR_makeSubjectSubject(
        acceptId ? acceptId(ERR_getSubjectId(arg)) : ERR_getSubjectId(arg),
        acceptLocation ? acceptLocation(ERR_getSubjectLocation(arg)) : ERR_getSubjectLocation(arg));
  }
  ATabort("not a Subject: %t\n", arg);
  return (ERR_Subject)NULL;
}

/*}}}  */
/*{{{  ERR_Location ERR_visitLocation(ERR_Location arg, char* (*acceptFilename)(char*), ERR_Area (*acceptArea)(ERR_Area)) */

ERR_Location ERR_visitLocation(ERR_Location arg, char* (*acceptFilename)(char*), ERR_Area (*acceptArea)(ERR_Area))
{
  if (ERR_isLocationLocation(arg)) {
    return ERR_makeLocationLocation(
        acceptFilename ? acceptFilename(ERR_getLocationFilename(arg)) : ERR_getLocationFilename(arg),
        acceptArea ? acceptArea(ERR_getLocationArea(arg)) : ERR_getLocationArea(arg));
  }
  ATabort("not a Location: %t\n", arg);
  return (ERR_Location)NULL;
}

/*}}}  */
/*{{{  ERR_Area ERR_visitArea(ERR_Area arg, int (*acceptStartLine)(int), int (*acceptStartColumn)(int), int (*acceptEndLine)(int), int (*acceptEndColumn)(int), int (*acceptStartOffset)(int), int (*acceptEndOffset)(int)) */

ERR_Area ERR_visitArea(ERR_Area arg, int (*acceptStartLine)(int), int (*acceptStartColumn)(int), int (*acceptEndLine)(int), int (*acceptEndColumn)(int), int (*acceptStartOffset)(int), int (*acceptEndOffset)(int))
{
  if (ERR_isAreaArea(arg)) {
    return ERR_makeAreaArea(
        acceptStartLine ? acceptStartLine(ERR_getAreaStartLine(arg)) : ERR_getAreaStartLine(arg),
        acceptStartColumn ? acceptStartColumn(ERR_getAreaStartColumn(arg)) : ERR_getAreaStartColumn(arg),
        acceptEndLine ? acceptEndLine(ERR_getAreaEndLine(arg)) : ERR_getAreaEndLine(arg),
        acceptEndColumn ? acceptEndColumn(ERR_getAreaEndColumn(arg)) : ERR_getAreaEndColumn(arg),
        acceptStartOffset ? acceptStartOffset(ERR_getAreaStartOffset(arg)) : ERR_getAreaStartOffset(arg),
        acceptEndOffset ? acceptEndOffset(ERR_getAreaEndOffset(arg)) : ERR_getAreaEndOffset(arg));
  }
  if (ERR_isAreaNoArea(arg)) {
    return ERR_makeAreaNoArea();
  }
  ATabort("not a Area: %t\n", arg);
  return (ERR_Area)NULL;
}

/*}}}  */

/*}}}  */
