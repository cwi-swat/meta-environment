#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "Errors.h"

/*{{{  typedefs */

typedef struct ATerm _ME_Feedback;
typedef struct ATerm _ME_Information;
typedef struct ATerm _ME_Warning;
typedef struct ATerm _ME_Error;
typedef struct ATerm _ME_FatalError;
typedef struct ATerm _ME_Producer;
typedef struct ATerm _ME_Description;
typedef struct ATerm _ME_Subjects;
typedef struct ATerm _ME_SubjectSubjectList;
typedef struct ATerm _ME_Subject;
typedef struct ATerm _ME_Location;
typedef struct ATerm _ME_Area;

/*}}}  */

/*{{{  void ME_initErrorsApi(void) */

void ME_initErrorsApi(void)
{
  init_Errors_dict();
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
/*{{{  ME_Information ME_InformationFromTerm(ATerm t) */

ME_Information ME_InformationFromTerm(ATerm t)
{
  return (ME_Information)t;
}

/*}}}  */
/*{{{  ATerm ME_InformationToTerm(ME_Information arg) */

ATerm ME_InformationToTerm(ME_Information arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ME_Warning ME_WarningFromTerm(ATerm t) */

ME_Warning ME_WarningFromTerm(ATerm t)
{
  return (ME_Warning)t;
}

/*}}}  */
/*{{{  ATerm ME_WarningToTerm(ME_Warning arg) */

ATerm ME_WarningToTerm(ME_Warning arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ME_Error ME_ErrorFromTerm(ATerm t) */

ME_Error ME_ErrorFromTerm(ATerm t)
{
  return (ME_Error)t;
}

/*}}}  */
/*{{{  ATerm ME_ErrorToTerm(ME_Error arg) */

ATerm ME_ErrorToTerm(ME_Error arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ME_FatalError ME_FatalErrorFromTerm(ATerm t) */

ME_FatalError ME_FatalErrorFromTerm(ATerm t)
{
  return (ME_FatalError)t;
}

/*}}}  */
/*{{{  ATerm ME_FatalErrorToTerm(ME_FatalError arg) */

ATerm ME_FatalErrorToTerm(ME_FatalError arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ME_Producer ME_ProducerFromTerm(ATerm t) */

ME_Producer ME_ProducerFromTerm(ATerm t)
{
  return (ME_Producer)t;
}

/*}}}  */
/*{{{  ATerm ME_ProducerToTerm(ME_Producer arg) */

ATerm ME_ProducerToTerm(ME_Producer arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ME_Description ME_DescriptionFromTerm(ATerm t) */

ME_Description ME_DescriptionFromTerm(ATerm t)
{
  return (ME_Description)t;
}

/*}}}  */
/*{{{  ATerm ME_DescriptionToTerm(ME_Description arg) */

ATerm ME_DescriptionToTerm(ME_Description arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ME_Subjects ME_SubjectsFromTerm(ATerm t) */

ME_Subjects ME_SubjectsFromTerm(ATerm t)
{
  return (ME_Subjects)t;
}

/*}}}  */
/*{{{  ATerm ME_SubjectsToTerm(ME_Subjects arg) */

ATerm ME_SubjectsToTerm(ME_Subjects arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  ME_SubjectSubjectList ME_SubjectSubjectListFromTerm(ATerm t) */

ME_SubjectSubjectList ME_SubjectSubjectListFromTerm(ATerm t)
{
  return (ME_SubjectSubjectList)t;
}

/*}}}  */
/*{{{  ATerm ME_SubjectSubjectListToTerm(ME_SubjectSubjectList arg) */

ATerm ME_SubjectSubjectListToTerm(ME_SubjectSubjectList arg)
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

int ME_getSubjectSubjectListLength (ME_SubjectSubjectList arg) {
  return ATgetLength((ATermList) arg);
}
ME_SubjectSubjectList ME_reverseSubjectSubjectList(ME_SubjectSubjectList arg) {
  return (ME_SubjectSubjectList) ATreverse((ATermList) arg);
}
ME_SubjectSubjectList ME_appendSubjectSubjectList(ME_SubjectSubjectList arg, ME_Subject elem) {
  return (ME_SubjectSubjectList) ATappend((ATermList) arg, (ATerm) elem);
}
ME_SubjectSubjectList ME_concatSubjectSubjectList(ME_SubjectSubjectList arg0, ME_SubjectSubjectList arg1) {
  return (ME_SubjectSubjectList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
ME_SubjectSubjectList ME_sliceSubjectSubjectList(ME_SubjectSubjectList arg, int start, int end) {
  return (ME_SubjectSubjectList) ATgetSlice((ATermList) arg, start, end);
}
ME_Subject ME_getSubjectSubjectListSubjectAt(ME_SubjectSubjectList arg, int index) {
 return (ME_Subject) ATelementAt((ATermList) arg, index);
}
ME_SubjectSubjectList ME_replaceSubjectSubjectListSubjectAt(ME_SubjectSubjectList arg, ME_Subject elem, int index) {
 return (ME_SubjectSubjectList) ATreplace((ATermList) arg, (ATerm) elem, index);
}
ME_SubjectSubjectList ME_makeSubjectSubjectList1(ME_Subject elem1) {
  return (ME_SubjectSubjectList) ATmakeList1((ATerm) elem1);
}
ME_SubjectSubjectList ME_makeSubjectSubjectList2(ME_Subject elem1, ME_Subject elem2) {
  return (ME_SubjectSubjectList) ATmakeList2((ATerm) elem1, (ATerm) elem2);
}
ME_SubjectSubjectList ME_makeSubjectSubjectList3(ME_Subject elem1, ME_Subject elem2, ME_Subject elem3) {
  return (ME_SubjectSubjectList) ATmakeList3((ATerm) elem1, (ATerm) elem2, (ATerm) elem3);
}
ME_SubjectSubjectList ME_makeSubjectSubjectList4(ME_Subject elem1, ME_Subject elem2, ME_Subject elem3, ME_Subject elem4) {
  return (ME_SubjectSubjectList) ATmakeList4((ATerm) elem1, (ATerm) elem2, (ATerm) elem3, (ATerm) elem4);
}
ME_SubjectSubjectList ME_makeSubjectSubjectList5(ME_Subject elem1, ME_Subject elem2, ME_Subject elem3, ME_Subject elem4, ME_Subject elem5) {
  return (ME_SubjectSubjectList) ATmakeList5((ATerm) elem1, (ATerm) elem2, (ATerm) elem3, (ATerm) elem4, (ATerm) elem5);
}
ME_SubjectSubjectList ME_makeSubjectSubjectList6(ME_Subject elem1, ME_Subject elem2, ME_Subject elem3, ME_Subject elem4, ME_Subject elem5, ME_Subject elem6) {
  return (ME_SubjectSubjectList) ATmakeList6((ATerm) elem1, (ATerm) elem2, (ATerm) elem3, (ATerm) elem4, (ATerm) elem5, (ATerm) elem6);
}

/*}}}  */
/*{{{  constructors */

/*{{{  ME_Feedback ME_makeFeedbackInfo(ME_Information Information) */

ME_Feedback ME_makeFeedbackInfo(ME_Information Information)
{
  return (ME_Feedback)(ATerm)ATmakeAppl1(ME_afun0, (ATerm)Information);
}

/*}}}  */
/*{{{  ME_Feedback ME_makeFeedbackWarning(ME_Warning Warning) */

ME_Feedback ME_makeFeedbackWarning(ME_Warning Warning)
{
  return (ME_Feedback)(ATerm)ATmakeAppl1(ME_afun1, (ATerm)Warning);
}

/*}}}  */
/*{{{  ME_Feedback ME_makeFeedbackError(ME_Error Error) */

ME_Feedback ME_makeFeedbackError(ME_Error Error)
{
  return (ME_Feedback)(ATerm)ATmakeAppl1(ME_afun2, (ATerm)Error);
}

/*}}}  */
/*{{{  ME_Feedback ME_makeFeedbackFatalError(ME_FatalError FatalError) */

ME_Feedback ME_makeFeedbackFatalError(ME_FatalError FatalError)
{
  return (ME_Feedback)(ATerm)ATmakeAppl1(ME_afun3, (ATerm)FatalError);
}

/*}}}  */
/*{{{  ME_Information ME_makeInformationInformation(char* id, ME_Producer producer, ME_Description description, ME_Subjects subjects) */

ME_Information ME_makeInformationInformation(char* id, ME_Producer producer, ME_Description description, ME_Subjects subjects)
{
  return (ME_Information)(ATerm)ATmakeAppl4(ME_afun4, (ATerm)ATmakeAppl0(ATmakeAFun(id, 0, ATtrue)), (ATerm)producer, (ATerm)description, (ATerm)subjects);
}

/*}}}  */
/*{{{  ME_Warning ME_makeWarningWarning(char* id, ME_Producer producer, ME_Description description, ME_Subjects subjects) */

ME_Warning ME_makeWarningWarning(char* id, ME_Producer producer, ME_Description description, ME_Subjects subjects)
{
  return (ME_Warning)(ATerm)ATmakeAppl4(ME_afun5, (ATerm)ATmakeAppl0(ATmakeAFun(id, 0, ATtrue)), (ATerm)producer, (ATerm)description, (ATerm)subjects);
}

/*}}}  */
/*{{{  ME_Error ME_makeErrorError(char* id, ME_Producer producer, ME_Description description, ME_Subjects subjects) */

ME_Error ME_makeErrorError(char* id, ME_Producer producer, ME_Description description, ME_Subjects subjects)
{
  return (ME_Error)(ATerm)ATmakeAppl4(ME_afun6, (ATerm)ATmakeAppl0(ATmakeAFun(id, 0, ATtrue)), (ATerm)producer, (ATerm)description, (ATerm)subjects);
}

/*}}}  */
/*{{{  ME_FatalError ME_makeFatalErrorFatalError(char* id, ME_Producer producer, ME_Description description, ME_Subjects subjects) */

ME_FatalError ME_makeFatalErrorFatalError(char* id, ME_Producer producer, ME_Description description, ME_Subjects subjects)
{
  return (ME_FatalError)(ATerm)ATmakeAppl4(ME_afun7, (ATerm)ATmakeAppl0(ATmakeAFun(id, 0, ATtrue)), (ATerm)producer, (ATerm)description, (ATerm)subjects);
}

/*}}}  */
/*{{{  ME_Producer ME_makeProducerProducer(char* id, char* type) */

ME_Producer ME_makeProducerProducer(char* id, char* type)
{
  return (ME_Producer)(ATerm)ATmakeAppl2(ME_afun8, (ATerm)ATmakeAppl0(ATmakeAFun(id, 0, ATtrue)), (ATerm)ATmakeAppl0(ATmakeAFun(type, 0, ATtrue)));
}

/*}}}  */
/*{{{  ME_Description ME_makeDescriptionDescription(char* String) */

ME_Description ME_makeDescriptionDescription(char* String)
{
  return (ME_Description)(ATerm)ATmakeAppl1(ME_afun9, (ATerm)ATmakeAppl0(ATmakeAFun(String, 0, ATtrue)));
}

/*}}}  */
/*{{{  ME_Subjects ME_makeSubjectsSubjects(ME_SubjectSubjectList subjectList) */

ME_Subjects ME_makeSubjectsSubjects(ME_SubjectSubjectList subjectList)
{
  return (ME_Subjects)(ATerm)ATmakeAppl1(ME_afun10, (ATerm)subjectList);
}

/*}}}  */
/*{{{  ME_SubjectSubjectList ME_makeSubjectSubjectListMany(ME_Subject head, ME_SubjectSubjectList tail) */

ME_SubjectSubjectList ME_makeSubjectSubjectListMany(ME_Subject head, ME_SubjectSubjectList tail)
{
  return (ME_SubjectSubjectList)(ATerm)ATinsert((ATermList)tail, (ATerm)head);
}

/*}}}  */
/*{{{  ME_SubjectSubjectList ME_makeSubjectSubjectListEmpty() */

ME_SubjectSubjectList ME_makeSubjectSubjectListEmpty()
{
  return (ME_SubjectSubjectList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  ME_Subject ME_makeSubjectWithoutLocation(char* id, ME_Location location) */

ME_Subject ME_makeSubjectWithoutLocation(char* id, ME_Location location)
{
  return (ME_Subject)(ATerm)ATmakeAppl2(ME_afun11, (ATerm)ATmakeAppl0(ATmakeAFun(id, 0, ATtrue)), (ATerm)location);
}

/*}}}  */
/*{{{  ME_Subject ME_makeSubjectWithLocation(char* id) */

ME_Subject ME_makeSubjectWithLocation(char* id)
{
  return (ME_Subject)(ATerm)ATmakeAppl1(ME_afun12, (ATerm)ATmakeAppl0(ATmakeAFun(id, 0, ATtrue)));
}

/*}}}  */
/*{{{  ME_Location ME_makeLocationLocation(char* file, ME_Area area) */

ME_Location ME_makeLocationLocation(char* file, ME_Area area)
{
  return (ME_Location)(ATerm)ATmakeAppl2(ME_afun13, (ATerm)ATmakeAppl0(ATmakeAFun(file, 0, ATtrue)), (ATerm)area);
}

/*}}}  */
/*{{{  ME_Area ME_makeAreaArea(int startLine, int startColumn, int endLine, int endColumn, int startOffset, int endOffset) */

ME_Area ME_makeAreaArea(int startLine, int startColumn, int endLine, int endColumn, int startOffset, int endOffset)
{
  return (ME_Area)(ATerm)ATmakeAppl6(ME_afun14, (ATerm)ATmakeInt(startLine), (ATerm)ATmakeInt(startColumn), (ATerm)ATmakeInt(endLine), (ATerm)ATmakeInt(endColumn), (ATerm)ATmakeInt(startOffset), (ATerm)ATmakeInt(endOffset));
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool ME_isEqualFeedback(ME_Feedback arg0, ME_Feedback arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ME_isEqualInformation(ME_Information arg0, ME_Information arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ME_isEqualWarning(ME_Warning arg0, ME_Warning arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ME_isEqualError(ME_Error arg0, ME_Error arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ME_isEqualFatalError(ME_FatalError arg0, ME_FatalError arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ME_isEqualProducer(ME_Producer arg0, ME_Producer arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ME_isEqualDescription(ME_Description arg0, ME_Description arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ME_isEqualSubjects(ME_Subjects arg0, ME_Subjects arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool ME_isEqualSubjectSubjectList(ME_SubjectSubjectList arg0, ME_SubjectSubjectList arg1)
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
      last_result = ATmatchTerm((ATerm)arg, ME_patternFeedbackInfo, NULL);
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
      last_result = ATmatchTerm((ATerm)arg, ME_patternFeedbackWarning, NULL);
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
      last_result = ATmatchTerm((ATerm)arg, ME_patternFeedbackError, NULL);
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
      last_result = ATmatchTerm((ATerm)arg, ME_patternFeedbackFatalError, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ME_hasFeedbackInformation(ME_Feedback arg) */

ATbool ME_hasFeedbackInformation(ME_Feedback arg)
{
  if (ME_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ME_Information ME_getFeedbackInformation(ME_Feedback arg) */

ME_Information ME_getFeedbackInformation(ME_Feedback arg)
{
  
    return (ME_Information)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  ME_Feedback ME_setFeedbackInformation(ME_Feedback arg, ME_Information Information) */

ME_Feedback ME_setFeedbackInformation(ME_Feedback arg, ME_Information Information)
{
  if (ME_isFeedbackInfo(arg)) {
    return (ME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)Information, 0);
  }

  ATabort("Feedback has no Information: %t\n", arg);
  return (ME_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool ME_hasFeedbackWarning(ME_Feedback arg) */

ATbool ME_hasFeedbackWarning(ME_Feedback arg)
{
  if (ME_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ME_Warning ME_getFeedbackWarning(ME_Feedback arg) */

ME_Warning ME_getFeedbackWarning(ME_Feedback arg)
{
  
    return (ME_Warning)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  ME_Feedback ME_setFeedbackWarning(ME_Feedback arg, ME_Warning Warning) */

ME_Feedback ME_setFeedbackWarning(ME_Feedback arg, ME_Warning Warning)
{
  if (ME_isFeedbackWarning(arg)) {
    return (ME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)Warning, 0);
  }

  ATabort("Feedback has no Warning: %t\n", arg);
  return (ME_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool ME_hasFeedbackError(ME_Feedback arg) */

ATbool ME_hasFeedbackError(ME_Feedback arg)
{
  if (ME_isFeedbackError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ME_Error ME_getFeedbackError(ME_Feedback arg) */

ME_Error ME_getFeedbackError(ME_Feedback arg)
{
  
    return (ME_Error)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  ME_Feedback ME_setFeedbackError(ME_Feedback arg, ME_Error Error) */

ME_Feedback ME_setFeedbackError(ME_Feedback arg, ME_Error Error)
{
  if (ME_isFeedbackError(arg)) {
    return (ME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)Error, 0);
  }

  ATabort("Feedback has no Error: %t\n", arg);
  return (ME_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool ME_hasFeedbackFatalError(ME_Feedback arg) */

ATbool ME_hasFeedbackFatalError(ME_Feedback arg)
{
  if (ME_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ME_FatalError ME_getFeedbackFatalError(ME_Feedback arg) */

ME_FatalError ME_getFeedbackFatalError(ME_Feedback arg)
{
  
    return (ME_FatalError)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  ME_Feedback ME_setFeedbackFatalError(ME_Feedback arg, ME_FatalError FatalError) */

ME_Feedback ME_setFeedbackFatalError(ME_Feedback arg, ME_FatalError FatalError)
{
  if (ME_isFeedbackFatalError(arg)) {
    return (ME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)FatalError, 0);
  }

  ATabort("Feedback has no FatalError: %t\n", arg);
  return (ME_Feedback)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ME_Information accessors */

/*{{{  ATbool ME_isValidInformation(ME_Information arg) */

ATbool ME_isValidInformation(ME_Information arg)
{
  if (ME_isInformationInformation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ME_isInformationInformation(ME_Information arg) */

inline ATbool ME_isInformationInformation(ME_Information arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ME_patternInformationInformation, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool ME_hasInformationId(ME_Information arg) */

ATbool ME_hasInformationId(ME_Information arg)
{
  if (ME_isInformationInformation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* ME_getInformationId(ME_Information arg) */

char* ME_getInformationId(ME_Information arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  ME_Information ME_setInformationId(ME_Information arg, char* id) */

ME_Information ME_setInformationId(ME_Information arg, char* id)
{
  if (ME_isInformationInformation(arg)) {
    return (ME_Information)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(id, 0, ATtrue)), 0);
  }

  ATabort("Information has no Id: %t\n", arg);
  return (ME_Information)NULL;
}

/*}}}  */
/*{{{  ATbool ME_hasInformationProducer(ME_Information arg) */

ATbool ME_hasInformationProducer(ME_Information arg)
{
  if (ME_isInformationInformation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ME_Producer ME_getInformationProducer(ME_Information arg) */

ME_Producer ME_getInformationProducer(ME_Information arg)
{
  
    return (ME_Producer)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  ME_Information ME_setInformationProducer(ME_Information arg, ME_Producer producer) */

ME_Information ME_setInformationProducer(ME_Information arg, ME_Producer producer)
{
  if (ME_isInformationInformation(arg)) {
    return (ME_Information)ATsetArgument((ATermAppl)arg, (ATerm)producer, 1);
  }

  ATabort("Information has no Producer: %t\n", arg);
  return (ME_Information)NULL;
}

/*}}}  */
/*{{{  ATbool ME_hasInformationDescription(ME_Information arg) */

ATbool ME_hasInformationDescription(ME_Information arg)
{
  if (ME_isInformationInformation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ME_Description ME_getInformationDescription(ME_Information arg) */

ME_Description ME_getInformationDescription(ME_Information arg)
{
  
    return (ME_Description)ATgetArgument((ATermAppl)arg, 2);
}

/*}}}  */
/*{{{  ME_Information ME_setInformationDescription(ME_Information arg, ME_Description description) */

ME_Information ME_setInformationDescription(ME_Information arg, ME_Description description)
{
  if (ME_isInformationInformation(arg)) {
    return (ME_Information)ATsetArgument((ATermAppl)arg, (ATerm)description, 2);
  }

  ATabort("Information has no Description: %t\n", arg);
  return (ME_Information)NULL;
}

/*}}}  */
/*{{{  ATbool ME_hasInformationSubjects(ME_Information arg) */

ATbool ME_hasInformationSubjects(ME_Information arg)
{
  if (ME_isInformationInformation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ME_Subjects ME_getInformationSubjects(ME_Information arg) */

ME_Subjects ME_getInformationSubjects(ME_Information arg)
{
  
    return (ME_Subjects)ATgetArgument((ATermAppl)arg, 3);
}

/*}}}  */
/*{{{  ME_Information ME_setInformationSubjects(ME_Information arg, ME_Subjects subjects) */

ME_Information ME_setInformationSubjects(ME_Information arg, ME_Subjects subjects)
{
  if (ME_isInformationInformation(arg)) {
    return (ME_Information)ATsetArgument((ATermAppl)arg, (ATerm)subjects, 3);
  }

  ATabort("Information has no Subjects: %t\n", arg);
  return (ME_Information)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ME_Warning accessors */

/*{{{  ATbool ME_isValidWarning(ME_Warning arg) */

ATbool ME_isValidWarning(ME_Warning arg)
{
  if (ME_isWarningWarning(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ME_isWarningWarning(ME_Warning arg) */

inline ATbool ME_isWarningWarning(ME_Warning arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ME_patternWarningWarning, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool ME_hasWarningId(ME_Warning arg) */

ATbool ME_hasWarningId(ME_Warning arg)
{
  if (ME_isWarningWarning(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* ME_getWarningId(ME_Warning arg) */

char* ME_getWarningId(ME_Warning arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  ME_Warning ME_setWarningId(ME_Warning arg, char* id) */

ME_Warning ME_setWarningId(ME_Warning arg, char* id)
{
  if (ME_isWarningWarning(arg)) {
    return (ME_Warning)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(id, 0, ATtrue)), 0);
  }

  ATabort("Warning has no Id: %t\n", arg);
  return (ME_Warning)NULL;
}

/*}}}  */
/*{{{  ATbool ME_hasWarningProducer(ME_Warning arg) */

ATbool ME_hasWarningProducer(ME_Warning arg)
{
  if (ME_isWarningWarning(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ME_Producer ME_getWarningProducer(ME_Warning arg) */

ME_Producer ME_getWarningProducer(ME_Warning arg)
{
  
    return (ME_Producer)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  ME_Warning ME_setWarningProducer(ME_Warning arg, ME_Producer producer) */

ME_Warning ME_setWarningProducer(ME_Warning arg, ME_Producer producer)
{
  if (ME_isWarningWarning(arg)) {
    return (ME_Warning)ATsetArgument((ATermAppl)arg, (ATerm)producer, 1);
  }

  ATabort("Warning has no Producer: %t\n", arg);
  return (ME_Warning)NULL;
}

/*}}}  */
/*{{{  ATbool ME_hasWarningDescription(ME_Warning arg) */

ATbool ME_hasWarningDescription(ME_Warning arg)
{
  if (ME_isWarningWarning(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ME_Description ME_getWarningDescription(ME_Warning arg) */

ME_Description ME_getWarningDescription(ME_Warning arg)
{
  
    return (ME_Description)ATgetArgument((ATermAppl)arg, 2);
}

/*}}}  */
/*{{{  ME_Warning ME_setWarningDescription(ME_Warning arg, ME_Description description) */

ME_Warning ME_setWarningDescription(ME_Warning arg, ME_Description description)
{
  if (ME_isWarningWarning(arg)) {
    return (ME_Warning)ATsetArgument((ATermAppl)arg, (ATerm)description, 2);
  }

  ATabort("Warning has no Description: %t\n", arg);
  return (ME_Warning)NULL;
}

/*}}}  */
/*{{{  ATbool ME_hasWarningSubjects(ME_Warning arg) */

ATbool ME_hasWarningSubjects(ME_Warning arg)
{
  if (ME_isWarningWarning(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ME_Subjects ME_getWarningSubjects(ME_Warning arg) */

ME_Subjects ME_getWarningSubjects(ME_Warning arg)
{
  
    return (ME_Subjects)ATgetArgument((ATermAppl)arg, 3);
}

/*}}}  */
/*{{{  ME_Warning ME_setWarningSubjects(ME_Warning arg, ME_Subjects subjects) */

ME_Warning ME_setWarningSubjects(ME_Warning arg, ME_Subjects subjects)
{
  if (ME_isWarningWarning(arg)) {
    return (ME_Warning)ATsetArgument((ATermAppl)arg, (ATerm)subjects, 3);
  }

  ATabort("Warning has no Subjects: %t\n", arg);
  return (ME_Warning)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ME_Error accessors */

/*{{{  ATbool ME_isValidError(ME_Error arg) */

ATbool ME_isValidError(ME_Error arg)
{
  if (ME_isErrorError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ME_isErrorError(ME_Error arg) */

inline ATbool ME_isErrorError(ME_Error arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ME_patternErrorError, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool ME_hasErrorId(ME_Error arg) */

ATbool ME_hasErrorId(ME_Error arg)
{
  if (ME_isErrorError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* ME_getErrorId(ME_Error arg) */

char* ME_getErrorId(ME_Error arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  ME_Error ME_setErrorId(ME_Error arg, char* id) */

ME_Error ME_setErrorId(ME_Error arg, char* id)
{
  if (ME_isErrorError(arg)) {
    return (ME_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(id, 0, ATtrue)), 0);
  }

  ATabort("Error has no Id: %t\n", arg);
  return (ME_Error)NULL;
}

/*}}}  */
/*{{{  ATbool ME_hasErrorProducer(ME_Error arg) */

ATbool ME_hasErrorProducer(ME_Error arg)
{
  if (ME_isErrorError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ME_Producer ME_getErrorProducer(ME_Error arg) */

ME_Producer ME_getErrorProducer(ME_Error arg)
{
  
    return (ME_Producer)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  ME_Error ME_setErrorProducer(ME_Error arg, ME_Producer producer) */

ME_Error ME_setErrorProducer(ME_Error arg, ME_Producer producer)
{
  if (ME_isErrorError(arg)) {
    return (ME_Error)ATsetArgument((ATermAppl)arg, (ATerm)producer, 1);
  }

  ATabort("Error has no Producer: %t\n", arg);
  return (ME_Error)NULL;
}

/*}}}  */
/*{{{  ATbool ME_hasErrorDescription(ME_Error arg) */

ATbool ME_hasErrorDescription(ME_Error arg)
{
  if (ME_isErrorError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ME_Description ME_getErrorDescription(ME_Error arg) */

ME_Description ME_getErrorDescription(ME_Error arg)
{
  
    return (ME_Description)ATgetArgument((ATermAppl)arg, 2);
}

/*}}}  */
/*{{{  ME_Error ME_setErrorDescription(ME_Error arg, ME_Description description) */

ME_Error ME_setErrorDescription(ME_Error arg, ME_Description description)
{
  if (ME_isErrorError(arg)) {
    return (ME_Error)ATsetArgument((ATermAppl)arg, (ATerm)description, 2);
  }

  ATabort("Error has no Description: %t\n", arg);
  return (ME_Error)NULL;
}

/*}}}  */
/*{{{  ATbool ME_hasErrorSubjects(ME_Error arg) */

ATbool ME_hasErrorSubjects(ME_Error arg)
{
  if (ME_isErrorError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ME_Subjects ME_getErrorSubjects(ME_Error arg) */

ME_Subjects ME_getErrorSubjects(ME_Error arg)
{
  
    return (ME_Subjects)ATgetArgument((ATermAppl)arg, 3);
}

/*}}}  */
/*{{{  ME_Error ME_setErrorSubjects(ME_Error arg, ME_Subjects subjects) */

ME_Error ME_setErrorSubjects(ME_Error arg, ME_Subjects subjects)
{
  if (ME_isErrorError(arg)) {
    return (ME_Error)ATsetArgument((ATermAppl)arg, (ATerm)subjects, 3);
  }

  ATabort("Error has no Subjects: %t\n", arg);
  return (ME_Error)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ME_FatalError accessors */

/*{{{  ATbool ME_isValidFatalError(ME_FatalError arg) */

ATbool ME_isValidFatalError(ME_FatalError arg)
{
  if (ME_isFatalErrorFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ME_isFatalErrorFatalError(ME_FatalError arg) */

inline ATbool ME_isFatalErrorFatalError(ME_FatalError arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ME_patternFatalErrorFatalError, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool ME_hasFatalErrorId(ME_FatalError arg) */

ATbool ME_hasFatalErrorId(ME_FatalError arg)
{
  if (ME_isFatalErrorFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* ME_getFatalErrorId(ME_FatalError arg) */

char* ME_getFatalErrorId(ME_FatalError arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  ME_FatalError ME_setFatalErrorId(ME_FatalError arg, char* id) */

ME_FatalError ME_setFatalErrorId(ME_FatalError arg, char* id)
{
  if (ME_isFatalErrorFatalError(arg)) {
    return (ME_FatalError)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(id, 0, ATtrue)), 0);
  }

  ATabort("FatalError has no Id: %t\n", arg);
  return (ME_FatalError)NULL;
}

/*}}}  */
/*{{{  ATbool ME_hasFatalErrorProducer(ME_FatalError arg) */

ATbool ME_hasFatalErrorProducer(ME_FatalError arg)
{
  if (ME_isFatalErrorFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ME_Producer ME_getFatalErrorProducer(ME_FatalError arg) */

ME_Producer ME_getFatalErrorProducer(ME_FatalError arg)
{
  
    return (ME_Producer)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  ME_FatalError ME_setFatalErrorProducer(ME_FatalError arg, ME_Producer producer) */

ME_FatalError ME_setFatalErrorProducer(ME_FatalError arg, ME_Producer producer)
{
  if (ME_isFatalErrorFatalError(arg)) {
    return (ME_FatalError)ATsetArgument((ATermAppl)arg, (ATerm)producer, 1);
  }

  ATabort("FatalError has no Producer: %t\n", arg);
  return (ME_FatalError)NULL;
}

/*}}}  */
/*{{{  ATbool ME_hasFatalErrorDescription(ME_FatalError arg) */

ATbool ME_hasFatalErrorDescription(ME_FatalError arg)
{
  if (ME_isFatalErrorFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ME_Description ME_getFatalErrorDescription(ME_FatalError arg) */

ME_Description ME_getFatalErrorDescription(ME_FatalError arg)
{
  
    return (ME_Description)ATgetArgument((ATermAppl)arg, 2);
}

/*}}}  */
/*{{{  ME_FatalError ME_setFatalErrorDescription(ME_FatalError arg, ME_Description description) */

ME_FatalError ME_setFatalErrorDescription(ME_FatalError arg, ME_Description description)
{
  if (ME_isFatalErrorFatalError(arg)) {
    return (ME_FatalError)ATsetArgument((ATermAppl)arg, (ATerm)description, 2);
  }

  ATabort("FatalError has no Description: %t\n", arg);
  return (ME_FatalError)NULL;
}

/*}}}  */
/*{{{  ATbool ME_hasFatalErrorSubjects(ME_FatalError arg) */

ATbool ME_hasFatalErrorSubjects(ME_FatalError arg)
{
  if (ME_isFatalErrorFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ME_Subjects ME_getFatalErrorSubjects(ME_FatalError arg) */

ME_Subjects ME_getFatalErrorSubjects(ME_FatalError arg)
{
  
    return (ME_Subjects)ATgetArgument((ATermAppl)arg, 3);
}

/*}}}  */
/*{{{  ME_FatalError ME_setFatalErrorSubjects(ME_FatalError arg, ME_Subjects subjects) */

ME_FatalError ME_setFatalErrorSubjects(ME_FatalError arg, ME_Subjects subjects)
{
  if (ME_isFatalErrorFatalError(arg)) {
    return (ME_FatalError)ATsetArgument((ATermAppl)arg, (ATerm)subjects, 3);
  }

  ATabort("FatalError has no Subjects: %t\n", arg);
  return (ME_FatalError)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ME_Producer accessors */

/*{{{  ATbool ME_isValidProducer(ME_Producer arg) */

ATbool ME_isValidProducer(ME_Producer arg)
{
  if (ME_isProducerProducer(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ME_isProducerProducer(ME_Producer arg) */

inline ATbool ME_isProducerProducer(ME_Producer arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ME_patternProducerProducer, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool ME_hasProducerId(ME_Producer arg) */

ATbool ME_hasProducerId(ME_Producer arg)
{
  if (ME_isProducerProducer(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* ME_getProducerId(ME_Producer arg) */

char* ME_getProducerId(ME_Producer arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  ME_Producer ME_setProducerId(ME_Producer arg, char* id) */

ME_Producer ME_setProducerId(ME_Producer arg, char* id)
{
  if (ME_isProducerProducer(arg)) {
    return (ME_Producer)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(id, 0, ATtrue)), 0);
  }

  ATabort("Producer has no Id: %t\n", arg);
  return (ME_Producer)NULL;
}

/*}}}  */
/*{{{  ATbool ME_hasProducerType(ME_Producer arg) */

ATbool ME_hasProducerType(ME_Producer arg)
{
  if (ME_isProducerProducer(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* ME_getProducerType(ME_Producer arg) */

char* ME_getProducerType(ME_Producer arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 1)));
}

/*}}}  */
/*{{{  ME_Producer ME_setProducerType(ME_Producer arg, char* type) */

ME_Producer ME_setProducerType(ME_Producer arg, char* type)
{
  if (ME_isProducerProducer(arg)) {
    return (ME_Producer)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(type, 0, ATtrue)), 1);
  }

  ATabort("Producer has no Type: %t\n", arg);
  return (ME_Producer)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ME_Description accessors */

/*{{{  ATbool ME_isValidDescription(ME_Description arg) */

ATbool ME_isValidDescription(ME_Description arg)
{
  if (ME_isDescriptionDescription(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ME_isDescriptionDescription(ME_Description arg) */

inline ATbool ME_isDescriptionDescription(ME_Description arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ME_patternDescriptionDescription, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool ME_hasDescriptionString(ME_Description arg) */

ATbool ME_hasDescriptionString(ME_Description arg)
{
  if (ME_isDescriptionDescription(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* ME_getDescriptionString(ME_Description arg) */

char* ME_getDescriptionString(ME_Description arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  ME_Description ME_setDescriptionString(ME_Description arg, char* String) */

ME_Description ME_setDescriptionString(ME_Description arg, char* String)
{
  if (ME_isDescriptionDescription(arg)) {
    return (ME_Description)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(String, 0, ATtrue)), 0);
  }

  ATabort("Description has no String: %t\n", arg);
  return (ME_Description)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ME_Subjects accessors */

/*{{{  ATbool ME_isValidSubjects(ME_Subjects arg) */

ATbool ME_isValidSubjects(ME_Subjects arg)
{
  if (ME_isSubjectsSubjects(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ME_isSubjectsSubjects(ME_Subjects arg) */

inline ATbool ME_isSubjectsSubjects(ME_Subjects arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ME_patternSubjectsSubjects, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool ME_hasSubjectsSubjectList(ME_Subjects arg) */

ATbool ME_hasSubjectsSubjectList(ME_Subjects arg)
{
  if (ME_isSubjectsSubjects(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ME_SubjectSubjectList ME_getSubjectsSubjectList(ME_Subjects arg) */

ME_SubjectSubjectList ME_getSubjectsSubjectList(ME_Subjects arg)
{
  
    return (ME_SubjectSubjectList)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  ME_Subjects ME_setSubjectsSubjectList(ME_Subjects arg, ME_SubjectSubjectList subjectList) */

ME_Subjects ME_setSubjectsSubjectList(ME_Subjects arg, ME_SubjectSubjectList subjectList)
{
  if (ME_isSubjectsSubjects(arg)) {
    return (ME_Subjects)ATsetArgument((ATermAppl)arg, (ATerm)subjectList, 0);
  }

  ATabort("Subjects has no SubjectList: %t\n", arg);
  return (ME_Subjects)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ME_SubjectSubjectList accessors */

/*{{{  ATbool ME_isValidSubjectSubjectList(ME_SubjectSubjectList arg) */

ATbool ME_isValidSubjectSubjectList(ME_SubjectSubjectList arg)
{
  if (ME_isSubjectSubjectListMany(arg)) {
    return ATtrue;
  }
  else if (ME_isSubjectSubjectListEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ME_isSubjectSubjectListMany(ME_SubjectSubjectList arg) */

inline ATbool ME_isSubjectSubjectListMany(ME_SubjectSubjectList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ME_patternSubjectSubjectListMany, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool ME_isSubjectSubjectListEmpty(ME_SubjectSubjectList arg) */

inline ATbool ME_isSubjectSubjectListEmpty(ME_SubjectSubjectList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ME_patternSubjectSubjectListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool ME_hasSubjectSubjectListHead(ME_SubjectSubjectList arg) */

ATbool ME_hasSubjectSubjectListHead(ME_SubjectSubjectList arg)
{
  if (ME_isSubjectSubjectListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ME_Subject ME_getSubjectSubjectListHead(ME_SubjectSubjectList arg) */

ME_Subject ME_getSubjectSubjectListHead(ME_SubjectSubjectList arg)
{
  
    return (ME_Subject)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  ME_SubjectSubjectList ME_setSubjectSubjectListHead(ME_SubjectSubjectList arg, ME_Subject head) */

ME_SubjectSubjectList ME_setSubjectSubjectListHead(ME_SubjectSubjectList arg, ME_Subject head)
{
  if (ME_isSubjectSubjectListMany(arg)) {
    return (ME_SubjectSubjectList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("SubjectSubjectList has no Head: %t\n", arg);
  return (ME_SubjectSubjectList)NULL;
}

/*}}}  */
/*{{{  ATbool ME_hasSubjectSubjectListTail(ME_SubjectSubjectList arg) */

ATbool ME_hasSubjectSubjectListTail(ME_SubjectSubjectList arg)
{
  if (ME_isSubjectSubjectListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  ME_SubjectSubjectList ME_getSubjectSubjectListTail(ME_SubjectSubjectList arg) */

ME_SubjectSubjectList ME_getSubjectSubjectListTail(ME_SubjectSubjectList arg)
{
  
    return (ME_SubjectSubjectList)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  ME_SubjectSubjectList ME_setSubjectSubjectListTail(ME_SubjectSubjectList arg, ME_SubjectSubjectList tail) */

ME_SubjectSubjectList ME_setSubjectSubjectListTail(ME_SubjectSubjectList arg, ME_SubjectSubjectList tail)
{
  if (ME_isSubjectSubjectListMany(arg)) {
    return (ME_SubjectSubjectList)ATreplaceTail((ATermList)arg, (ATermList)tail, 1);
  }

  ATabort("SubjectSubjectList has no Tail: %t\n", arg);
  return (ME_SubjectSubjectList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  ME_Subject accessors */

/*{{{  ATbool ME_isValidSubject(ME_Subject arg) */

ATbool ME_isValidSubject(ME_Subject arg)
{
  if (ME_isSubjectWithoutLocation(arg)) {
    return ATtrue;
  }
  else if (ME_isSubjectWithLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ME_isSubjectWithoutLocation(ME_Subject arg) */

inline ATbool ME_isSubjectWithoutLocation(ME_Subject arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ME_patternSubjectWithoutLocation, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool ME_isSubjectWithLocation(ME_Subject arg) */

inline ATbool ME_isSubjectWithLocation(ME_Subject arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, ME_patternSubjectWithLocation, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool ME_hasSubjectId(ME_Subject arg) */

ATbool ME_hasSubjectId(ME_Subject arg)
{
  if (ME_isSubjectWithoutLocation(arg)) {
    return ATtrue;
  }
  else if (ME_isSubjectWithLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* ME_getSubjectId(ME_Subject arg) */

char* ME_getSubjectId(ME_Subject arg)
{
  if (ME_isSubjectWithoutLocation(arg)) {
    return (char*)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
  }
  else 
    return (char*)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  ME_Subject ME_setSubjectId(ME_Subject arg, char* id) */

ME_Subject ME_setSubjectId(ME_Subject arg, char* id)
{
  if (ME_isSubjectWithoutLocation(arg)) {
    return (ME_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(id, 0, ATtrue)), 0);
  }
  else if (ME_isSubjectWithLocation(arg)) {
    return (ME_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(id, 0, ATtrue)), 0);
  }

  ATabort("Subject has no Id: %t\n", arg);
  return (ME_Subject)NULL;
}

/*}}}  */
/*{{{  ATbool ME_hasSubjectLocation(ME_Subject arg) */

ATbool ME_hasSubjectLocation(ME_Subject arg)
{
  if (ME_isSubjectWithoutLocation(arg)) {
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
/*{{{  ME_Subject ME_setSubjectLocation(ME_Subject arg, ME_Location location) */

ME_Subject ME_setSubjectLocation(ME_Subject arg, ME_Location location)
{
  if (ME_isSubjectWithoutLocation(arg)) {
    return (ME_Subject)ATsetArgument((ATermAppl)arg, (ATerm)location, 1);
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
/*{{{  ATbool ME_hasLocationFile(ME_Location arg) */

ATbool ME_hasLocationFile(ME_Location arg)
{
  if (ME_isLocationLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* ME_getLocationFile(ME_Location arg) */

char* ME_getLocationFile(ME_Location arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)arg, 0)));
}

/*}}}  */
/*{{{  ME_Location ME_setLocationFile(ME_Location arg, char* file) */

ME_Location ME_setLocationFile(ME_Location arg, char* file)
{
  if (ME_isLocationLocation(arg)) {
    return (ME_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeAppl0(ATmakeAFun(file, 0, ATtrue)), 0);
  }

  ATabort("Location has no File: %t\n", arg);
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
/*{{{  ME_Location ME_setLocationArea(ME_Location arg, ME_Area area) */

ME_Location ME_setLocationArea(ME_Location arg, ME_Area area)
{
  if (ME_isLocationLocation(arg)) {
    return (ME_Location)ATsetArgument((ATermAppl)arg, (ATerm)area, 1);
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
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool ME_isAreaArea(ME_Area arg) */

inline ATbool ME_isAreaArea(ME_Area arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, ME_patternAreaArea, NULL, NULL, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
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
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 0));
}

/*}}}  */
/*{{{  ME_Area ME_setAreaStartLine(ME_Area arg, int startLine) */

ME_Area ME_setAreaStartLine(ME_Area arg, int startLine)
{
  if (ME_isAreaArea(arg)) {
    return (ME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(startLine), 0);
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
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  ME_Area ME_setAreaStartColumn(ME_Area arg, int startColumn) */

ME_Area ME_setAreaStartColumn(ME_Area arg, int startColumn)
{
  if (ME_isAreaArea(arg)) {
    return (ME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(startColumn), 1);
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
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 2));
}

/*}}}  */
/*{{{  ME_Area ME_setAreaEndLine(ME_Area arg, int endLine) */

ME_Area ME_setAreaEndLine(ME_Area arg, int endLine)
{
  if (ME_isAreaArea(arg)) {
    return (ME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(endLine), 2);
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
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 3));
}

/*}}}  */
/*{{{  ME_Area ME_setAreaEndColumn(ME_Area arg, int endColumn) */

ME_Area ME_setAreaEndColumn(ME_Area arg, int endColumn)
{
  if (ME_isAreaArea(arg)) {
    return (ME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(endColumn), 3);
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
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 4));
}

/*}}}  */
/*{{{  ME_Area ME_setAreaStartOffset(ME_Area arg, int startOffset) */

ME_Area ME_setAreaStartOffset(ME_Area arg, int startOffset)
{
  if (ME_isAreaArea(arg)) {
    return (ME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(startOffset), 4);
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
  
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 5));
}

/*}}}  */
/*{{{  ME_Area ME_setAreaEndOffset(ME_Area arg, int endOffset) */

ME_Area ME_setAreaEndOffset(ME_Area arg, int endOffset)
{
  if (ME_isAreaArea(arg)) {
    return (ME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(endOffset), 5);
  }

  ATabort("Area has no EndOffset: %t\n", arg);
  return (ME_Area)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  ME_Feedback ME_visitFeedback(ME_Feedback arg, ME_Information (*acceptInformation)(ME_Information), ME_Warning (*acceptWarning)(ME_Warning), ME_Error (*acceptError)(ME_Error), ME_FatalError (*acceptFatalError)(ME_FatalError)) */

ME_Feedback ME_visitFeedback(ME_Feedback arg, ME_Information (*acceptInformation)(ME_Information), ME_Warning (*acceptWarning)(ME_Warning), ME_Error (*acceptError)(ME_Error), ME_FatalError (*acceptFatalError)(ME_FatalError))
{
  if (ME_isFeedbackInfo(arg)) {
    return ME_makeFeedbackInfo(
        acceptInformation ? acceptInformation(ME_getFeedbackInformation(arg)) : ME_getFeedbackInformation(arg));
  }
  if (ME_isFeedbackWarning(arg)) {
    return ME_makeFeedbackWarning(
        acceptWarning ? acceptWarning(ME_getFeedbackWarning(arg)) : ME_getFeedbackWarning(arg));
  }
  if (ME_isFeedbackError(arg)) {
    return ME_makeFeedbackError(
        acceptError ? acceptError(ME_getFeedbackError(arg)) : ME_getFeedbackError(arg));
  }
  if (ME_isFeedbackFatalError(arg)) {
    return ME_makeFeedbackFatalError(
        acceptFatalError ? acceptFatalError(ME_getFeedbackFatalError(arg)) : ME_getFeedbackFatalError(arg));
  }
  ATabort("not a Feedback: %t\n", arg);
  return (ME_Feedback)NULL;
}

/*}}}  */
/*{{{  ME_Information ME_visitInformation(ME_Information arg, char* (*acceptId)(char*), ME_Producer (*acceptProducer)(ME_Producer), ME_Description (*acceptDescription)(ME_Description), ME_Subjects (*acceptSubjects)(ME_Subjects)) */

ME_Information ME_visitInformation(ME_Information arg, char* (*acceptId)(char*), ME_Producer (*acceptProducer)(ME_Producer), ME_Description (*acceptDescription)(ME_Description), ME_Subjects (*acceptSubjects)(ME_Subjects))
{
  if (ME_isInformationInformation(arg)) {
    return ME_makeInformationInformation(
        acceptId ? acceptId(ME_getInformationId(arg)) : ME_getInformationId(arg),
        acceptProducer ? acceptProducer(ME_getInformationProducer(arg)) : ME_getInformationProducer(arg),
        acceptDescription ? acceptDescription(ME_getInformationDescription(arg)) : ME_getInformationDescription(arg),
        acceptSubjects ? acceptSubjects(ME_getInformationSubjects(arg)) : ME_getInformationSubjects(arg));
  }
  ATabort("not a Information: %t\n", arg);
  return (ME_Information)NULL;
}

/*}}}  */
/*{{{  ME_Warning ME_visitWarning(ME_Warning arg, char* (*acceptId)(char*), ME_Producer (*acceptProducer)(ME_Producer), ME_Description (*acceptDescription)(ME_Description), ME_Subjects (*acceptSubjects)(ME_Subjects)) */

ME_Warning ME_visitWarning(ME_Warning arg, char* (*acceptId)(char*), ME_Producer (*acceptProducer)(ME_Producer), ME_Description (*acceptDescription)(ME_Description), ME_Subjects (*acceptSubjects)(ME_Subjects))
{
  if (ME_isWarningWarning(arg)) {
    return ME_makeWarningWarning(
        acceptId ? acceptId(ME_getWarningId(arg)) : ME_getWarningId(arg),
        acceptProducer ? acceptProducer(ME_getWarningProducer(arg)) : ME_getWarningProducer(arg),
        acceptDescription ? acceptDescription(ME_getWarningDescription(arg)) : ME_getWarningDescription(arg),
        acceptSubjects ? acceptSubjects(ME_getWarningSubjects(arg)) : ME_getWarningSubjects(arg));
  }
  ATabort("not a Warning: %t\n", arg);
  return (ME_Warning)NULL;
}

/*}}}  */
/*{{{  ME_Error ME_visitError(ME_Error arg, char* (*acceptId)(char*), ME_Producer (*acceptProducer)(ME_Producer), ME_Description (*acceptDescription)(ME_Description), ME_Subjects (*acceptSubjects)(ME_Subjects)) */

ME_Error ME_visitError(ME_Error arg, char* (*acceptId)(char*), ME_Producer (*acceptProducer)(ME_Producer), ME_Description (*acceptDescription)(ME_Description), ME_Subjects (*acceptSubjects)(ME_Subjects))
{
  if (ME_isErrorError(arg)) {
    return ME_makeErrorError(
        acceptId ? acceptId(ME_getErrorId(arg)) : ME_getErrorId(arg),
        acceptProducer ? acceptProducer(ME_getErrorProducer(arg)) : ME_getErrorProducer(arg),
        acceptDescription ? acceptDescription(ME_getErrorDescription(arg)) : ME_getErrorDescription(arg),
        acceptSubjects ? acceptSubjects(ME_getErrorSubjects(arg)) : ME_getErrorSubjects(arg));
  }
  ATabort("not a Error: %t\n", arg);
  return (ME_Error)NULL;
}

/*}}}  */
/*{{{  ME_FatalError ME_visitFatalError(ME_FatalError arg, char* (*acceptId)(char*), ME_Producer (*acceptProducer)(ME_Producer), ME_Description (*acceptDescription)(ME_Description), ME_Subjects (*acceptSubjects)(ME_Subjects)) */

ME_FatalError ME_visitFatalError(ME_FatalError arg, char* (*acceptId)(char*), ME_Producer (*acceptProducer)(ME_Producer), ME_Description (*acceptDescription)(ME_Description), ME_Subjects (*acceptSubjects)(ME_Subjects))
{
  if (ME_isFatalErrorFatalError(arg)) {
    return ME_makeFatalErrorFatalError(
        acceptId ? acceptId(ME_getFatalErrorId(arg)) : ME_getFatalErrorId(arg),
        acceptProducer ? acceptProducer(ME_getFatalErrorProducer(arg)) : ME_getFatalErrorProducer(arg),
        acceptDescription ? acceptDescription(ME_getFatalErrorDescription(arg)) : ME_getFatalErrorDescription(arg),
        acceptSubjects ? acceptSubjects(ME_getFatalErrorSubjects(arg)) : ME_getFatalErrorSubjects(arg));
  }
  ATabort("not a FatalError: %t\n", arg);
  return (ME_FatalError)NULL;
}

/*}}}  */
/*{{{  ME_Producer ME_visitProducer(ME_Producer arg, char* (*acceptId)(char*), char* (*acceptType)(char*)) */

ME_Producer ME_visitProducer(ME_Producer arg, char* (*acceptId)(char*), char* (*acceptType)(char*))
{
  if (ME_isProducerProducer(arg)) {
    return ME_makeProducerProducer(
        acceptId ? acceptId(ME_getProducerId(arg)) : ME_getProducerId(arg),
        acceptType ? acceptType(ME_getProducerType(arg)) : ME_getProducerType(arg));
  }
  ATabort("not a Producer: %t\n", arg);
  return (ME_Producer)NULL;
}

/*}}}  */
/*{{{  ME_Description ME_visitDescription(ME_Description arg, char* (*acceptString)(char*)) */

ME_Description ME_visitDescription(ME_Description arg, char* (*acceptString)(char*))
{
  if (ME_isDescriptionDescription(arg)) {
    return ME_makeDescriptionDescription(
        acceptString ? acceptString(ME_getDescriptionString(arg)) : ME_getDescriptionString(arg));
  }
  ATabort("not a Description: %t\n", arg);
  return (ME_Description)NULL;
}

/*}}}  */
/*{{{  ME_Subjects ME_visitSubjects(ME_Subjects arg, ME_SubjectSubjectList (*acceptSubjectList)(ME_SubjectSubjectList)) */

ME_Subjects ME_visitSubjects(ME_Subjects arg, ME_SubjectSubjectList (*acceptSubjectList)(ME_SubjectSubjectList))
{
  if (ME_isSubjectsSubjects(arg)) {
    return ME_makeSubjectsSubjects(
        acceptSubjectList ? acceptSubjectList(ME_getSubjectsSubjectList(arg)) : ME_getSubjectsSubjectList(arg));
  }
  ATabort("not a Subjects: %t\n", arg);
  return (ME_Subjects)NULL;
}

/*}}}  */
/*{{{  ME_SubjectSubjectList ME_visitSubjectSubjectList(ME_SubjectSubjectList arg, ME_Subject (*acceptHead)(ME_Subject)) */

ME_SubjectSubjectList ME_visitSubjectSubjectList(ME_SubjectSubjectList arg, ME_Subject (*acceptHead)(ME_Subject))
{
  if (ME_isSubjectSubjectListMany(arg)) {
    return ME_makeSubjectSubjectListMany(
        acceptHead ? acceptHead(ME_getSubjectSubjectListHead(arg)) : ME_getSubjectSubjectListHead(arg),
        ME_visitSubjectSubjectList(ME_getSubjectSubjectListTail(arg), acceptHead));
  }
  if (ME_isSubjectSubjectListEmpty(arg)) {
    return ME_makeSubjectSubjectListEmpty();
  }
  ATabort("not a SubjectSubjectList: %t\n", arg);
  return (ME_SubjectSubjectList)NULL;
}

/*}}}  */
/*{{{  ME_Subject ME_visitSubject(ME_Subject arg, char* (*acceptId)(char*), ME_Location (*acceptLocation)(ME_Location)) */

ME_Subject ME_visitSubject(ME_Subject arg, char* (*acceptId)(char*), ME_Location (*acceptLocation)(ME_Location))
{
  if (ME_isSubjectWithoutLocation(arg)) {
    return ME_makeSubjectWithoutLocation(
        acceptId ? acceptId(ME_getSubjectId(arg)) : ME_getSubjectId(arg),
        acceptLocation ? acceptLocation(ME_getSubjectLocation(arg)) : ME_getSubjectLocation(arg));
  }
  if (ME_isSubjectWithLocation(arg)) {
    return ME_makeSubjectWithLocation(
        acceptId ? acceptId(ME_getSubjectId(arg)) : ME_getSubjectId(arg));
  }
  ATabort("not a Subject: %t\n", arg);
  return (ME_Subject)NULL;
}

/*}}}  */
/*{{{  ME_Location ME_visitLocation(ME_Location arg, char* (*acceptFile)(char*), ME_Area (*acceptArea)(ME_Area)) */

ME_Location ME_visitLocation(ME_Location arg, char* (*acceptFile)(char*), ME_Area (*acceptArea)(ME_Area))
{
  if (ME_isLocationLocation(arg)) {
    return ME_makeLocationLocation(
        acceptFile ? acceptFile(ME_getLocationFile(arg)) : ME_getLocationFile(arg),
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
  ATabort("not a Area: %t\n", arg);
  return (ME_Area)NULL;
}

/*}}}  */

/*}}}  */
