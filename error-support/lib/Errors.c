#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "Errors.h"

/*{{{  typedefs */

typedef struct ATerm _PME_Feedback;
typedef struct ATerm _PME_Information;
typedef struct ATerm _PME_Warning;
typedef struct ATerm _PME_Error;
typedef struct ATerm _PME_FatalError;
typedef struct ATerm _PME_Producer;
typedef struct ATerm _PME_Description;
typedef struct ATerm _PME_Subjects;
typedef struct ATerm _PME_SubjectSubjectList;
typedef struct ATerm _PME_Subject;
typedef struct ATerm _PME_Location;
typedef struct ATerm _PME_Area;

/*}}}  */

/*{{{  void PME_initErrorsApi(void) */

void PME_initErrorsApi(void)
{
  init_Errors_dict();
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
/*{{{  PME_Information PME_InformationFromTerm(ATerm t) */

PME_Information PME_InformationFromTerm(ATerm t)
{
  return (PME_Information)t;
}

/*}}}  */
/*{{{  ATerm PME_InformationToTerm(PME_Information arg) */

ATerm PME_InformationToTerm(PME_Information arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PME_Warning PME_WarningFromTerm(ATerm t) */

PME_Warning PME_WarningFromTerm(ATerm t)
{
  return (PME_Warning)t;
}

/*}}}  */
/*{{{  ATerm PME_WarningToTerm(PME_Warning arg) */

ATerm PME_WarningToTerm(PME_Warning arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PME_Error PME_ErrorFromTerm(ATerm t) */

PME_Error PME_ErrorFromTerm(ATerm t)
{
  return (PME_Error)t;
}

/*}}}  */
/*{{{  ATerm PME_ErrorToTerm(PME_Error arg) */

ATerm PME_ErrorToTerm(PME_Error arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PME_FatalError PME_FatalErrorFromTerm(ATerm t) */

PME_FatalError PME_FatalErrorFromTerm(ATerm t)
{
  return (PME_FatalError)t;
}

/*}}}  */
/*{{{  ATerm PME_FatalErrorToTerm(PME_FatalError arg) */

ATerm PME_FatalErrorToTerm(PME_FatalError arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PME_Producer PME_ProducerFromTerm(ATerm t) */

PME_Producer PME_ProducerFromTerm(ATerm t)
{
  return (PME_Producer)t;
}

/*}}}  */
/*{{{  ATerm PME_ProducerToTerm(PME_Producer arg) */

ATerm PME_ProducerToTerm(PME_Producer arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PME_Description PME_DescriptionFromTerm(ATerm t) */

PME_Description PME_DescriptionFromTerm(ATerm t)
{
  return (PME_Description)t;
}

/*}}}  */
/*{{{  ATerm PME_DescriptionToTerm(PME_Description arg) */

ATerm PME_DescriptionToTerm(PME_Description arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PME_Subjects PME_SubjectsFromTerm(ATerm t) */

PME_Subjects PME_SubjectsFromTerm(ATerm t)
{
  return (PME_Subjects)t;
}

/*}}}  */
/*{{{  ATerm PME_SubjectsToTerm(PME_Subjects arg) */

ATerm PME_SubjectsToTerm(PME_Subjects arg)
{
  return (ATerm)arg;
}

/*}}}  */
/*{{{  PME_SubjectSubjectList PME_SubjectSubjectListFromTerm(ATerm t) */

PME_SubjectSubjectList PME_SubjectSubjectListFromTerm(ATerm t)
{
  return (PME_SubjectSubjectList)t;
}

/*}}}  */
/*{{{  ATerm PME_SubjectSubjectListToTerm(PME_SubjectSubjectList arg) */

ATerm PME_SubjectSubjectListToTerm(PME_SubjectSubjectList arg)
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

/*}}}  */
/*{{{  list functions */

int PME_getSubjectSubjectListLength (PME_SubjectSubjectList arg) {
  return ATgetLength((ATermList) arg);
}
PME_SubjectSubjectList PME_reverseSubjectSubjectList(PME_SubjectSubjectList arg) {
  return (PME_SubjectSubjectList) ATreverse((ATermList) arg);
}
PME_SubjectSubjectList PME_appendSubjectSubjectList(PME_SubjectSubjectList arg, PME_Subject elem) {
  return (PME_SubjectSubjectList) ATappend((ATermList) arg, (ATerm) elem);
}
PME_SubjectSubjectList PME_concatSubjectSubjectList(PME_SubjectSubjectList arg0, PME_SubjectSubjectList arg1) {
  return (PME_SubjectSubjectList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
PME_SubjectSubjectList PME_sliceSubjectSubjectList(PME_SubjectSubjectList arg, int start, int end) {
  return (PME_SubjectSubjectList) ATgetSlice((ATermList) arg, start, end);
}
PME_Subject PME_getSubjectSubjectListSubjectAt(PME_SubjectSubjectList arg, int index) {
 return (PME_Subject) ATelementAt((ATermList) arg, index);
}
PME_SubjectSubjectList PME_replaceSubjectSubjectListSubjectAt(PME_SubjectSubjectList arg, PME_Subject elem, int index) {
 return (PME_SubjectSubjectList) ATreplace((ATermList) arg, (ATerm) elem, index);
}
PME_SubjectSubjectList PME_makeSubjectSubjectList1(PME_Subject elem1) {
  return (PME_SubjectSubjectList) ATmakeList1((ATerm) elem1);
}
PME_SubjectSubjectList PME_makeSubjectSubjectList2(PME_Subject elem1, PME_Subject elem2) {
  return (PME_SubjectSubjectList) ATmakeList2((ATerm) elem1, (ATerm) elem2);
}
PME_SubjectSubjectList PME_makeSubjectSubjectList3(PME_Subject elem1, PME_Subject elem2, PME_Subject elem3) {
  return (PME_SubjectSubjectList) ATmakeList3((ATerm) elem1, (ATerm) elem2, (ATerm) elem3);
}
PME_SubjectSubjectList PME_makeSubjectSubjectList4(PME_Subject elem1, PME_Subject elem2, PME_Subject elem3, PME_Subject elem4) {
  return (PME_SubjectSubjectList) ATmakeList4((ATerm) elem1, (ATerm) elem2, (ATerm) elem3, (ATerm) elem4);
}
PME_SubjectSubjectList PME_makeSubjectSubjectList5(PME_Subject elem1, PME_Subject elem2, PME_Subject elem3, PME_Subject elem4, PME_Subject elem5) {
  return (PME_SubjectSubjectList) ATmakeList5((ATerm) elem1, (ATerm) elem2, (ATerm) elem3, (ATerm) elem4, (ATerm) elem5);
}
PME_SubjectSubjectList PME_makeSubjectSubjectList6(PME_Subject elem1, PME_Subject elem2, PME_Subject elem3, PME_Subject elem4, PME_Subject elem5, PME_Subject elem6) {
  return (PME_SubjectSubjectList) ATmakeList6((ATerm) elem1, (ATerm) elem2, (ATerm) elem3, (ATerm) elem4, (ATerm) elem5, (ATerm) elem6);
}

/*}}}  */
/*{{{  constructors */

/*{{{  PME_Feedback PME_makeFeedbackInfo(PME_Info Info) */

PME_Feedback PME_makeFeedbackInfo(PME_Info Info)
{
  return (PME_Feedback)(ATerm)ATmakeAppl1(PME_afun0, (ATerm)Info);
}

/*}}}  */
/*{{{  PME_Feedback PME_makeFeedbackWarning(PME_Warning Warning) */

PME_Feedback PME_makeFeedbackWarning(PME_Warning Warning)
{
  return (PME_Feedback)(ATerm)ATmakeAppl1(PME_afun1, (ATerm)Warning);
}

/*}}}  */
/*{{{  PME_Feedback PME_makeFeedbackError(PME_Error Error) */

PME_Feedback PME_makeFeedbackError(PME_Error Error)
{
  return (PME_Feedback)(ATerm)ATmakeAppl1(PME_afun2, (ATerm)Error);
}

/*}}}  */
/*{{{  PME_Feedback PME_makeFeedbackFatalError(PME_FatalError FatalError) */

PME_Feedback PME_makeFeedbackFatalError(PME_FatalError FatalError)
{
  return (PME_Feedback)(ATerm)ATmakeAppl1(PME_afun3, (ATerm)FatalError);
}

/*}}}  */
/*{{{  PME_Information PME_makeInformationInformation(PME_String id, PME_Producer producer, PME_Description description, PME_Subjects subjects) */

PME_Information PME_makeInformationInformation(PME_String id, PME_Producer producer, PME_Description description, PME_Subjects subjects)
{
  return (PME_Information)(ATerm)ATmakeAppl4(PME_afun4, (ATerm)id, (ATerm)producer, (ATerm)description, (ATerm)subjects);
}

/*}}}  */
/*{{{  PME_Warning PME_makeWarningWarning(PME_String id, PME_Producer producer, PME_Description description, PME_Subjects subjects) */

PME_Warning PME_makeWarningWarning(PME_String id, PME_Producer producer, PME_Description description, PME_Subjects subjects)
{
  return (PME_Warning)(ATerm)ATmakeAppl4(PME_afun5, (ATerm)id, (ATerm)producer, (ATerm)description, (ATerm)subjects);
}

/*}}}  */
/*{{{  PME_Error PME_makeErrorError(PME_String id, PME_Producer producer, PME_Description description, PME_Subjects subjects) */

PME_Error PME_makeErrorError(PME_String id, PME_Producer producer, PME_Description description, PME_Subjects subjects)
{
  return (PME_Error)(ATerm)ATmakeAppl4(PME_afun6, (ATerm)id, (ATerm)producer, (ATerm)description, (ATerm)subjects);
}

/*}}}  */
/*{{{  PME_FatalError PME_makeFatalErrorFatalError(PME_String id, PME_Producer producer, PME_Description description, PME_Subjects subjects) */

PME_FatalError PME_makeFatalErrorFatalError(PME_String id, PME_Producer producer, PME_Description description, PME_Subjects subjects)
{
  return (PME_FatalError)(ATerm)ATmakeAppl4(PME_afun7, (ATerm)id, (ATerm)producer, (ATerm)description, (ATerm)subjects);
}

/*}}}  */
/*{{{  PME_Producer PME_makeProducerProducer(PME_String id, PME_String type) */

PME_Producer PME_makeProducerProducer(PME_String id, PME_String type)
{
  return (PME_Producer)(ATerm)ATmakeAppl2(PME_afun8, (ATerm)id, (ATerm)type);
}

/*}}}  */
/*{{{  PME_Description PME_makeDescriptionDescription(PME_String String) */

PME_Description PME_makeDescriptionDescription(PME_String String)
{
  return (PME_Description)(ATerm)ATmakeAppl1(PME_afun9, (ATerm)String);
}

/*}}}  */
/*{{{  PME_Subjects PME_makeSubjectsSubjects(PME_SubjectSubjectList subjectList) */

PME_Subjects PME_makeSubjectsSubjects(PME_SubjectSubjectList subjectList)
{
  return (PME_Subjects)(ATerm)ATmakeAppl1(PME_afun10, (ATerm)subjectList);
}

/*}}}  */
/*{{{  PME_SubjectSubjectList PME_makeSubjectSubjectListMany(PME_Subject head, PME_SubjectSubjectList tail) */

PME_SubjectSubjectList PME_makeSubjectSubjectListMany(PME_Subject head, PME_SubjectSubjectList tail)
{
  return (PME_SubjectSubjectList)(ATerm)ATinsert((ATermList)tail, (ATerm)head);
}

/*}}}  */
/*{{{  PME_SubjectSubjectList PME_makeSubjectSubjectListEmpty() */

PME_SubjectSubjectList PME_makeSubjectSubjectListEmpty()
{
  return (PME_SubjectSubjectList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  PME_Subject PME_makeSubjectWithoutLocation(PME_String id, PME_Location location) */

PME_Subject PME_makeSubjectWithoutLocation(PME_String id, PME_Location location)
{
  return (PME_Subject)(ATerm)ATmakeAppl2(PME_afun11, (ATerm)id, (ATerm)location);
}

/*}}}  */
/*{{{  PME_Subject PME_makeSubjectWithLocation(PME_String id) */

PME_Subject PME_makeSubjectWithLocation(PME_String id)
{
  return (PME_Subject)(ATerm)ATmakeAppl1(PME_afun12, (ATerm)id);
}

/*}}}  */
/*{{{  PME_Location PME_makeLocationLocation(PME_String file, PME_Area area) */

PME_Location PME_makeLocationLocation(PME_String file, PME_Area area)
{
  return (PME_Location)(ATerm)ATmakeAppl2(PME_afun13, (ATerm)file, (ATerm)area);
}

/*}}}  */
/*{{{  PME_Area PME_makeAreaArea(PME_NatCon startLine, PME_NatCon startColumn, PME_NatCon endLine, PME_NatCon endColumn, PME_NatCon startOffset, PME_NatCon endOffset) */

PME_Area PME_makeAreaArea(PME_NatCon startLine, PME_NatCon startColumn, PME_NatCon endLine, PME_NatCon endColumn, PME_NatCon startOffset, PME_NatCon endOffset)
{
  return (PME_Area)(ATerm)ATmakeAppl6(PME_afun14, (ATerm)startLine, (ATerm)startColumn, (ATerm)endLine, (ATerm)endColumn, (ATerm)startOffset, (ATerm)endOffset);
}

/*}}}  */

/*}}}  */
/*{{{  equality functions */

ATbool PME_isEqualFeedback(PME_Feedback arg0, PME_Feedback arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PME_isEqualInformation(PME_Information arg0, PME_Information arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PME_isEqualWarning(PME_Warning arg0, PME_Warning arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PME_isEqualError(PME_Error arg0, PME_Error arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PME_isEqualFatalError(PME_FatalError arg0, PME_FatalError arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PME_isEqualProducer(PME_Producer arg0, PME_Producer arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PME_isEqualDescription(PME_Description arg0, PME_Description arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PME_isEqualSubjects(PME_Subjects arg0, PME_Subjects arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PME_isEqualSubjectSubjectList(PME_SubjectSubjectList arg0, PME_SubjectSubjectList arg1)
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
      last_result = ATmatchTerm((ATerm)arg, PME_patternFeedbackInfo, NULL);
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
      last_result = ATmatchTerm((ATerm)arg, PME_patternFeedbackWarning, NULL);
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
      last_result = ATmatchTerm((ATerm)arg, PME_patternFeedbackError, NULL);
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
      last_result = ATmatchTerm((ATerm)arg, PME_patternFeedbackFatalError, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PME_hasFeedbackInfo(PME_Feedback arg) */

ATbool PME_hasFeedbackInfo(PME_Feedback arg)
{
  if (PME_isFeedbackInfo(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_Info PME_getFeedbackInfo(PME_Feedback arg) */

PME_Info PME_getFeedbackInfo(PME_Feedback arg)
{
  
    return (PME_Info)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  PME_Feedback PME_setFeedbackInfo(PME_Feedback arg, PME_Info Info) */

PME_Feedback PME_setFeedbackInfo(PME_Feedback arg, PME_Info Info)
{
  if (PME_isFeedbackInfo(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)Info, 0);
  }

  ATabort("Feedback has no Info: %t\n", arg);
  return (PME_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasFeedbackWarning(PME_Feedback arg) */

ATbool PME_hasFeedbackWarning(PME_Feedback arg)
{
  if (PME_isFeedbackWarning(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_Warning PME_getFeedbackWarning(PME_Feedback arg) */

PME_Warning PME_getFeedbackWarning(PME_Feedback arg)
{
  
    return (PME_Warning)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  PME_Feedback PME_setFeedbackWarning(PME_Feedback arg, PME_Warning Warning) */

PME_Feedback PME_setFeedbackWarning(PME_Feedback arg, PME_Warning Warning)
{
  if (PME_isFeedbackWarning(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)Warning, 0);
  }

  ATabort("Feedback has no Warning: %t\n", arg);
  return (PME_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasFeedbackError(PME_Feedback arg) */

ATbool PME_hasFeedbackError(PME_Feedback arg)
{
  if (PME_isFeedbackError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_Error PME_getFeedbackError(PME_Feedback arg) */

PME_Error PME_getFeedbackError(PME_Feedback arg)
{
  
    return (PME_Error)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  PME_Feedback PME_setFeedbackError(PME_Feedback arg, PME_Error Error) */

PME_Feedback PME_setFeedbackError(PME_Feedback arg, PME_Error Error)
{
  if (PME_isFeedbackError(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)Error, 0);
  }

  ATabort("Feedback has no Error: %t\n", arg);
  return (PME_Feedback)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasFeedbackFatalError(PME_Feedback arg) */

ATbool PME_hasFeedbackFatalError(PME_Feedback arg)
{
  if (PME_isFeedbackFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_FatalError PME_getFeedbackFatalError(PME_Feedback arg) */

PME_FatalError PME_getFeedbackFatalError(PME_Feedback arg)
{
  
    return (PME_FatalError)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  PME_Feedback PME_setFeedbackFatalError(PME_Feedback arg, PME_FatalError FatalError) */

PME_Feedback PME_setFeedbackFatalError(PME_Feedback arg, PME_FatalError FatalError)
{
  if (PME_isFeedbackFatalError(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)FatalError, 0);
  }

  ATabort("Feedback has no FatalError: %t\n", arg);
  return (PME_Feedback)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PME_Information accessors */

/*{{{  ATbool PME_isValidInformation(PME_Information arg) */

ATbool PME_isValidInformation(PME_Information arg)
{
  if (PME_isInformationInformation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PME_isInformationInformation(PME_Information arg) */

inline ATbool PME_isInformationInformation(PME_Information arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PME_patternInformationInformation, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PME_hasInformationId(PME_Information arg) */

ATbool PME_hasInformationId(PME_Information arg)
{
  if (PME_isInformationInformation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_String PME_getInformationId(PME_Information arg) */

PME_String PME_getInformationId(PME_Information arg)
{
  
    return (PME_String)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  PME_Information PME_setInformationId(PME_Information arg, PME_String id) */

PME_Information PME_setInformationId(PME_Information arg, PME_String id)
{
  if (PME_isInformationInformation(arg)) {
    return (PME_Information)ATsetArgument((ATermAppl)arg, (ATerm)id, 0);
  }

  ATabort("Information has no Id: %t\n", arg);
  return (PME_Information)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasInformationProducer(PME_Information arg) */

ATbool PME_hasInformationProducer(PME_Information arg)
{
  if (PME_isInformationInformation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_Producer PME_getInformationProducer(PME_Information arg) */

PME_Producer PME_getInformationProducer(PME_Information arg)
{
  
    return (PME_Producer)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  PME_Information PME_setInformationProducer(PME_Information arg, PME_Producer producer) */

PME_Information PME_setInformationProducer(PME_Information arg, PME_Producer producer)
{
  if (PME_isInformationInformation(arg)) {
    return (PME_Information)ATsetArgument((ATermAppl)arg, (ATerm)producer, 1);
  }

  ATabort("Information has no Producer: %t\n", arg);
  return (PME_Information)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasInformationDescription(PME_Information arg) */

ATbool PME_hasInformationDescription(PME_Information arg)
{
  if (PME_isInformationInformation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_Description PME_getInformationDescription(PME_Information arg) */

PME_Description PME_getInformationDescription(PME_Information arg)
{
  
    return (PME_Description)ATgetArgument((ATermAppl)arg, 2);
}

/*}}}  */
/*{{{  PME_Information PME_setInformationDescription(PME_Information arg, PME_Description description) */

PME_Information PME_setInformationDescription(PME_Information arg, PME_Description description)
{
  if (PME_isInformationInformation(arg)) {
    return (PME_Information)ATsetArgument((ATermAppl)arg, (ATerm)description, 2);
  }

  ATabort("Information has no Description: %t\n", arg);
  return (PME_Information)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasInformationSubjects(PME_Information arg) */

ATbool PME_hasInformationSubjects(PME_Information arg)
{
  if (PME_isInformationInformation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_Subjects PME_getInformationSubjects(PME_Information arg) */

PME_Subjects PME_getInformationSubjects(PME_Information arg)
{
  
    return (PME_Subjects)ATgetArgument((ATermAppl)arg, 3);
}

/*}}}  */
/*{{{  PME_Information PME_setInformationSubjects(PME_Information arg, PME_Subjects subjects) */

PME_Information PME_setInformationSubjects(PME_Information arg, PME_Subjects subjects)
{
  if (PME_isInformationInformation(arg)) {
    return (PME_Information)ATsetArgument((ATermAppl)arg, (ATerm)subjects, 3);
  }

  ATabort("Information has no Subjects: %t\n", arg);
  return (PME_Information)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PME_Warning accessors */

/*{{{  ATbool PME_isValidWarning(PME_Warning arg) */

ATbool PME_isValidWarning(PME_Warning arg)
{
  if (PME_isWarningWarning(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PME_isWarningWarning(PME_Warning arg) */

inline ATbool PME_isWarningWarning(PME_Warning arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PME_patternWarningWarning, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PME_hasWarningId(PME_Warning arg) */

ATbool PME_hasWarningId(PME_Warning arg)
{
  if (PME_isWarningWarning(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_String PME_getWarningId(PME_Warning arg) */

PME_String PME_getWarningId(PME_Warning arg)
{
  
    return (PME_String)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  PME_Warning PME_setWarningId(PME_Warning arg, PME_String id) */

PME_Warning PME_setWarningId(PME_Warning arg, PME_String id)
{
  if (PME_isWarningWarning(arg)) {
    return (PME_Warning)ATsetArgument((ATermAppl)arg, (ATerm)id, 0);
  }

  ATabort("Warning has no Id: %t\n", arg);
  return (PME_Warning)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasWarningProducer(PME_Warning arg) */

ATbool PME_hasWarningProducer(PME_Warning arg)
{
  if (PME_isWarningWarning(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_Producer PME_getWarningProducer(PME_Warning arg) */

PME_Producer PME_getWarningProducer(PME_Warning arg)
{
  
    return (PME_Producer)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  PME_Warning PME_setWarningProducer(PME_Warning arg, PME_Producer producer) */

PME_Warning PME_setWarningProducer(PME_Warning arg, PME_Producer producer)
{
  if (PME_isWarningWarning(arg)) {
    return (PME_Warning)ATsetArgument((ATermAppl)arg, (ATerm)producer, 1);
  }

  ATabort("Warning has no Producer: %t\n", arg);
  return (PME_Warning)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasWarningDescription(PME_Warning arg) */

ATbool PME_hasWarningDescription(PME_Warning arg)
{
  if (PME_isWarningWarning(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_Description PME_getWarningDescription(PME_Warning arg) */

PME_Description PME_getWarningDescription(PME_Warning arg)
{
  
    return (PME_Description)ATgetArgument((ATermAppl)arg, 2);
}

/*}}}  */
/*{{{  PME_Warning PME_setWarningDescription(PME_Warning arg, PME_Description description) */

PME_Warning PME_setWarningDescription(PME_Warning arg, PME_Description description)
{
  if (PME_isWarningWarning(arg)) {
    return (PME_Warning)ATsetArgument((ATermAppl)arg, (ATerm)description, 2);
  }

  ATabort("Warning has no Description: %t\n", arg);
  return (PME_Warning)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasWarningSubjects(PME_Warning arg) */

ATbool PME_hasWarningSubjects(PME_Warning arg)
{
  if (PME_isWarningWarning(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_Subjects PME_getWarningSubjects(PME_Warning arg) */

PME_Subjects PME_getWarningSubjects(PME_Warning arg)
{
  
    return (PME_Subjects)ATgetArgument((ATermAppl)arg, 3);
}

/*}}}  */
/*{{{  PME_Warning PME_setWarningSubjects(PME_Warning arg, PME_Subjects subjects) */

PME_Warning PME_setWarningSubjects(PME_Warning arg, PME_Subjects subjects)
{
  if (PME_isWarningWarning(arg)) {
    return (PME_Warning)ATsetArgument((ATermAppl)arg, (ATerm)subjects, 3);
  }

  ATabort("Warning has no Subjects: %t\n", arg);
  return (PME_Warning)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PME_Error accessors */

/*{{{  ATbool PME_isValidError(PME_Error arg) */

ATbool PME_isValidError(PME_Error arg)
{
  if (PME_isErrorError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PME_isErrorError(PME_Error arg) */

inline ATbool PME_isErrorError(PME_Error arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PME_patternErrorError, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PME_hasErrorId(PME_Error arg) */

ATbool PME_hasErrorId(PME_Error arg)
{
  if (PME_isErrorError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_String PME_getErrorId(PME_Error arg) */

PME_String PME_getErrorId(PME_Error arg)
{
  
    return (PME_String)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  PME_Error PME_setErrorId(PME_Error arg, PME_String id) */

PME_Error PME_setErrorId(PME_Error arg, PME_String id)
{
  if (PME_isErrorError(arg)) {
    return (PME_Error)ATsetArgument((ATermAppl)arg, (ATerm)id, 0);
  }

  ATabort("Error has no Id: %t\n", arg);
  return (PME_Error)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasErrorProducer(PME_Error arg) */

ATbool PME_hasErrorProducer(PME_Error arg)
{
  if (PME_isErrorError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_Producer PME_getErrorProducer(PME_Error arg) */

PME_Producer PME_getErrorProducer(PME_Error arg)
{
  
    return (PME_Producer)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  PME_Error PME_setErrorProducer(PME_Error arg, PME_Producer producer) */

PME_Error PME_setErrorProducer(PME_Error arg, PME_Producer producer)
{
  if (PME_isErrorError(arg)) {
    return (PME_Error)ATsetArgument((ATermAppl)arg, (ATerm)producer, 1);
  }

  ATabort("Error has no Producer: %t\n", arg);
  return (PME_Error)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasErrorDescription(PME_Error arg) */

ATbool PME_hasErrorDescription(PME_Error arg)
{
  if (PME_isErrorError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_Description PME_getErrorDescription(PME_Error arg) */

PME_Description PME_getErrorDescription(PME_Error arg)
{
  
    return (PME_Description)ATgetArgument((ATermAppl)arg, 2);
}

/*}}}  */
/*{{{  PME_Error PME_setErrorDescription(PME_Error arg, PME_Description description) */

PME_Error PME_setErrorDescription(PME_Error arg, PME_Description description)
{
  if (PME_isErrorError(arg)) {
    return (PME_Error)ATsetArgument((ATermAppl)arg, (ATerm)description, 2);
  }

  ATabort("Error has no Description: %t\n", arg);
  return (PME_Error)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasErrorSubjects(PME_Error arg) */

ATbool PME_hasErrorSubjects(PME_Error arg)
{
  if (PME_isErrorError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_Subjects PME_getErrorSubjects(PME_Error arg) */

PME_Subjects PME_getErrorSubjects(PME_Error arg)
{
  
    return (PME_Subjects)ATgetArgument((ATermAppl)arg, 3);
}

/*}}}  */
/*{{{  PME_Error PME_setErrorSubjects(PME_Error arg, PME_Subjects subjects) */

PME_Error PME_setErrorSubjects(PME_Error arg, PME_Subjects subjects)
{
  if (PME_isErrorError(arg)) {
    return (PME_Error)ATsetArgument((ATermAppl)arg, (ATerm)subjects, 3);
  }

  ATabort("Error has no Subjects: %t\n", arg);
  return (PME_Error)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PME_FatalError accessors */

/*{{{  ATbool PME_isValidFatalError(PME_FatalError arg) */

ATbool PME_isValidFatalError(PME_FatalError arg)
{
  if (PME_isFatalErrorFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PME_isFatalErrorFatalError(PME_FatalError arg) */

inline ATbool PME_isFatalErrorFatalError(PME_FatalError arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PME_patternFatalErrorFatalError, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PME_hasFatalErrorId(PME_FatalError arg) */

ATbool PME_hasFatalErrorId(PME_FatalError arg)
{
  if (PME_isFatalErrorFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_String PME_getFatalErrorId(PME_FatalError arg) */

PME_String PME_getFatalErrorId(PME_FatalError arg)
{
  
    return (PME_String)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  PME_FatalError PME_setFatalErrorId(PME_FatalError arg, PME_String id) */

PME_FatalError PME_setFatalErrorId(PME_FatalError arg, PME_String id)
{
  if (PME_isFatalErrorFatalError(arg)) {
    return (PME_FatalError)ATsetArgument((ATermAppl)arg, (ATerm)id, 0);
  }

  ATabort("FatalError has no Id: %t\n", arg);
  return (PME_FatalError)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasFatalErrorProducer(PME_FatalError arg) */

ATbool PME_hasFatalErrorProducer(PME_FatalError arg)
{
  if (PME_isFatalErrorFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_Producer PME_getFatalErrorProducer(PME_FatalError arg) */

PME_Producer PME_getFatalErrorProducer(PME_FatalError arg)
{
  
    return (PME_Producer)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  PME_FatalError PME_setFatalErrorProducer(PME_FatalError arg, PME_Producer producer) */

PME_FatalError PME_setFatalErrorProducer(PME_FatalError arg, PME_Producer producer)
{
  if (PME_isFatalErrorFatalError(arg)) {
    return (PME_FatalError)ATsetArgument((ATermAppl)arg, (ATerm)producer, 1);
  }

  ATabort("FatalError has no Producer: %t\n", arg);
  return (PME_FatalError)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasFatalErrorDescription(PME_FatalError arg) */

ATbool PME_hasFatalErrorDescription(PME_FatalError arg)
{
  if (PME_isFatalErrorFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_Description PME_getFatalErrorDescription(PME_FatalError arg) */

PME_Description PME_getFatalErrorDescription(PME_FatalError arg)
{
  
    return (PME_Description)ATgetArgument((ATermAppl)arg, 2);
}

/*}}}  */
/*{{{  PME_FatalError PME_setFatalErrorDescription(PME_FatalError arg, PME_Description description) */

PME_FatalError PME_setFatalErrorDescription(PME_FatalError arg, PME_Description description)
{
  if (PME_isFatalErrorFatalError(arg)) {
    return (PME_FatalError)ATsetArgument((ATermAppl)arg, (ATerm)description, 2);
  }

  ATabort("FatalError has no Description: %t\n", arg);
  return (PME_FatalError)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasFatalErrorSubjects(PME_FatalError arg) */

ATbool PME_hasFatalErrorSubjects(PME_FatalError arg)
{
  if (PME_isFatalErrorFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_Subjects PME_getFatalErrorSubjects(PME_FatalError arg) */

PME_Subjects PME_getFatalErrorSubjects(PME_FatalError arg)
{
  
    return (PME_Subjects)ATgetArgument((ATermAppl)arg, 3);
}

/*}}}  */
/*{{{  PME_FatalError PME_setFatalErrorSubjects(PME_FatalError arg, PME_Subjects subjects) */

PME_FatalError PME_setFatalErrorSubjects(PME_FatalError arg, PME_Subjects subjects)
{
  if (PME_isFatalErrorFatalError(arg)) {
    return (PME_FatalError)ATsetArgument((ATermAppl)arg, (ATerm)subjects, 3);
  }

  ATabort("FatalError has no Subjects: %t\n", arg);
  return (PME_FatalError)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PME_Producer accessors */

/*{{{  ATbool PME_isValidProducer(PME_Producer arg) */

ATbool PME_isValidProducer(PME_Producer arg)
{
  if (PME_isProducerProducer(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PME_isProducerProducer(PME_Producer arg) */

inline ATbool PME_isProducerProducer(PME_Producer arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PME_patternProducerProducer, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PME_hasProducerId(PME_Producer arg) */

ATbool PME_hasProducerId(PME_Producer arg)
{
  if (PME_isProducerProducer(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_String PME_getProducerId(PME_Producer arg) */

PME_String PME_getProducerId(PME_Producer arg)
{
  
    return (PME_String)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  PME_Producer PME_setProducerId(PME_Producer arg, PME_String id) */

PME_Producer PME_setProducerId(PME_Producer arg, PME_String id)
{
  if (PME_isProducerProducer(arg)) {
    return (PME_Producer)ATsetArgument((ATermAppl)arg, (ATerm)id, 0);
  }

  ATabort("Producer has no Id: %t\n", arg);
  return (PME_Producer)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasProducerType(PME_Producer arg) */

ATbool PME_hasProducerType(PME_Producer arg)
{
  if (PME_isProducerProducer(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_String PME_getProducerType(PME_Producer arg) */

PME_String PME_getProducerType(PME_Producer arg)
{
  
    return (PME_String)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  PME_Producer PME_setProducerType(PME_Producer arg, PME_String type) */

PME_Producer PME_setProducerType(PME_Producer arg, PME_String type)
{
  if (PME_isProducerProducer(arg)) {
    return (PME_Producer)ATsetArgument((ATermAppl)arg, (ATerm)type, 1);
  }

  ATabort("Producer has no Type: %t\n", arg);
  return (PME_Producer)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PME_Description accessors */

/*{{{  ATbool PME_isValidDescription(PME_Description arg) */

ATbool PME_isValidDescription(PME_Description arg)
{
  if (PME_isDescriptionDescription(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PME_isDescriptionDescription(PME_Description arg) */

inline ATbool PME_isDescriptionDescription(PME_Description arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PME_patternDescriptionDescription, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PME_hasDescriptionString(PME_Description arg) */

ATbool PME_hasDescriptionString(PME_Description arg)
{
  if (PME_isDescriptionDescription(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_String PME_getDescriptionString(PME_Description arg) */

PME_String PME_getDescriptionString(PME_Description arg)
{
  
    return (PME_String)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  PME_Description PME_setDescriptionString(PME_Description arg, PME_String String) */

PME_Description PME_setDescriptionString(PME_Description arg, PME_String String)
{
  if (PME_isDescriptionDescription(arg)) {
    return (PME_Description)ATsetArgument((ATermAppl)arg, (ATerm)String, 0);
  }

  ATabort("Description has no String: %t\n", arg);
  return (PME_Description)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PME_Subjects accessors */

/*{{{  ATbool PME_isValidSubjects(PME_Subjects arg) */

ATbool PME_isValidSubjects(PME_Subjects arg)
{
  if (PME_isSubjectsSubjects(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PME_isSubjectsSubjects(PME_Subjects arg) */

inline ATbool PME_isSubjectsSubjects(PME_Subjects arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PME_patternSubjectsSubjects, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PME_hasSubjectsSubjectList(PME_Subjects arg) */

ATbool PME_hasSubjectsSubjectList(PME_Subjects arg)
{
  if (PME_isSubjectsSubjects(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_SubjectSubjectList PME_getSubjectsSubjectList(PME_Subjects arg) */

PME_SubjectSubjectList PME_getSubjectsSubjectList(PME_Subjects arg)
{
  
    return (PME_SubjectSubjectList)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  PME_Subjects PME_setSubjectsSubjectList(PME_Subjects arg, PME_SubjectSubjectList subjectList) */

PME_Subjects PME_setSubjectsSubjectList(PME_Subjects arg, PME_SubjectSubjectList subjectList)
{
  if (PME_isSubjectsSubjects(arg)) {
    return (PME_Subjects)ATsetArgument((ATermAppl)arg, (ATerm)subjectList, 0);
  }

  ATabort("Subjects has no SubjectList: %t\n", arg);
  return (PME_Subjects)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PME_SubjectSubjectList accessors */

/*{{{  ATbool PME_isValidSubjectSubjectList(PME_SubjectSubjectList arg) */

ATbool PME_isValidSubjectSubjectList(PME_SubjectSubjectList arg)
{
  if (PME_isSubjectSubjectListMany(arg)) {
    return ATtrue;
  }
  else if (PME_isSubjectSubjectListEmpty(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PME_isSubjectSubjectListMany(PME_SubjectSubjectList arg) */

inline ATbool PME_isSubjectSubjectListMany(PME_SubjectSubjectList arg)
{
  if (ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PME_patternSubjectSubjectListMany, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  inline ATbool PME_isSubjectSubjectListEmpty(PME_SubjectSubjectList arg) */

inline ATbool PME_isSubjectSubjectListEmpty(PME_SubjectSubjectList arg)
{
  if (!ATisEmpty((ATermList)arg)) {
    return ATfalse;
  }
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PME_patternSubjectSubjectListEmpty));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PME_hasSubjectSubjectListHead(PME_SubjectSubjectList arg) */

ATbool PME_hasSubjectSubjectListHead(PME_SubjectSubjectList arg)
{
  if (PME_isSubjectSubjectListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_Subject PME_getSubjectSubjectListHead(PME_SubjectSubjectList arg) */

PME_Subject PME_getSubjectSubjectListHead(PME_SubjectSubjectList arg)
{
  
    return (PME_Subject)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  PME_SubjectSubjectList PME_setSubjectSubjectListHead(PME_SubjectSubjectList arg, PME_Subject head) */

PME_SubjectSubjectList PME_setSubjectSubjectListHead(PME_SubjectSubjectList arg, PME_Subject head)
{
  if (PME_isSubjectSubjectListMany(arg)) {
    return (PME_SubjectSubjectList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("SubjectSubjectList has no Head: %t\n", arg);
  return (PME_SubjectSubjectList)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasSubjectSubjectListTail(PME_SubjectSubjectList arg) */

ATbool PME_hasSubjectSubjectListTail(PME_SubjectSubjectList arg)
{
  if (PME_isSubjectSubjectListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_SubjectSubjectList PME_getSubjectSubjectListTail(PME_SubjectSubjectList arg) */

PME_SubjectSubjectList PME_getSubjectSubjectListTail(PME_SubjectSubjectList arg)
{
  
    return (PME_SubjectSubjectList)ATgetNext((ATermList)arg);
}

/*}}}  */
/*{{{  PME_SubjectSubjectList PME_setSubjectSubjectListTail(PME_SubjectSubjectList arg, PME_SubjectSubjectList tail) */

PME_SubjectSubjectList PME_setSubjectSubjectListTail(PME_SubjectSubjectList arg, PME_SubjectSubjectList tail)
{
  if (PME_isSubjectSubjectListMany(arg)) {
    return (PME_SubjectSubjectList)ATreplaceTail((ATermList)arg, (ATermList)tail, 1);
  }

  ATabort("SubjectSubjectList has no Tail: %t\n", arg);
  return (PME_SubjectSubjectList)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  PME_Subject accessors */

/*{{{  ATbool PME_isValidSubject(PME_Subject arg) */

ATbool PME_isValidSubject(PME_Subject arg)
{
  if (PME_isSubjectWithoutLocation(arg)) {
    return ATtrue;
  }
  else if (PME_isSubjectWithLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PME_isSubjectWithoutLocation(PME_Subject arg) */

inline ATbool PME_isSubjectWithoutLocation(PME_Subject arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PME_patternSubjectWithoutLocation, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PME_isSubjectWithLocation(PME_Subject arg) */

inline ATbool PME_isSubjectWithLocation(PME_Subject arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PME_patternSubjectWithLocation, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PME_hasSubjectId(PME_Subject arg) */

ATbool PME_hasSubjectId(PME_Subject arg)
{
  if (PME_isSubjectWithoutLocation(arg)) {
    return ATtrue;
  }
  else if (PME_isSubjectWithLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_String PME_getSubjectId(PME_Subject arg) */

PME_String PME_getSubjectId(PME_Subject arg)
{
  if (PME_isSubjectWithoutLocation(arg)) {
    return (PME_String)ATgetArgument((ATermAppl)arg, 0);
  }
  else 
    return (PME_String)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  PME_Subject PME_setSubjectId(PME_Subject arg, PME_String id) */

PME_Subject PME_setSubjectId(PME_Subject arg, PME_String id)
{
  if (PME_isSubjectWithoutLocation(arg)) {
    return (PME_Subject)ATsetArgument((ATermAppl)arg, (ATerm)id, 0);
  }
  else if (PME_isSubjectWithLocation(arg)) {
    return (PME_Subject)ATsetArgument((ATermAppl)arg, (ATerm)id, 0);
  }

  ATabort("Subject has no Id: %t\n", arg);
  return (PME_Subject)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasSubjectLocation(PME_Subject arg) */

ATbool PME_hasSubjectLocation(PME_Subject arg)
{
  if (PME_isSubjectWithoutLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_Location PME_getSubjectLocation(PME_Subject arg) */

PME_Location PME_getSubjectLocation(PME_Subject arg)
{
  
    return (PME_Location)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  PME_Subject PME_setSubjectLocation(PME_Subject arg, PME_Location location) */

PME_Subject PME_setSubjectLocation(PME_Subject arg, PME_Location location)
{
  if (PME_isSubjectWithoutLocation(arg)) {
    return (PME_Subject)ATsetArgument((ATermAppl)arg, (ATerm)location, 1);
  }

  ATabort("Subject has no Location: %t\n", arg);
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
  assert(ATmatchTerm((ATerm)arg, PME_patternLocationLocation, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PME_hasLocationFile(PME_Location arg) */

ATbool PME_hasLocationFile(PME_Location arg)
{
  if (PME_isLocationLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_String PME_getLocationFile(PME_Location arg) */

PME_String PME_getLocationFile(PME_Location arg)
{
  
    return (PME_String)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  PME_Location PME_setLocationFile(PME_Location arg, PME_String file) */

PME_Location PME_setLocationFile(PME_Location arg, PME_String file)
{
  if (PME_isLocationLocation(arg)) {
    return (PME_Location)ATsetArgument((ATermAppl)arg, (ATerm)file, 0);
  }

  ATabort("Location has no File: %t\n", arg);
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
  
    return (PME_Area)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  PME_Location PME_setLocationArea(PME_Location arg, PME_Area area) */

PME_Location PME_setLocationArea(PME_Location arg, PME_Area area)
{
  if (PME_isLocationLocation(arg)) {
    return (PME_Location)ATsetArgument((ATermAppl)arg, (ATerm)area, 1);
  }

  ATabort("Location has no Area: %t\n", arg);
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
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PME_isAreaArea(PME_Area arg) */

inline ATbool PME_isAreaArea(PME_Area arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PME_patternAreaArea, NULL, NULL, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
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
  
    return (PME_NatCon)ATgetArgument((ATermAppl)arg, 0);
}

/*}}}  */
/*{{{  PME_Area PME_setAreaStartLine(PME_Area arg, PME_NatCon startLine) */

PME_Area PME_setAreaStartLine(PME_Area arg, PME_NatCon startLine)
{
  if (PME_isAreaArea(arg)) {
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)startLine, 0);
  }

  ATabort("Area has no StartLine: %t\n", arg);
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
  
    return (PME_NatCon)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  PME_Area PME_setAreaStartColumn(PME_Area arg, PME_NatCon startColumn) */

PME_Area PME_setAreaStartColumn(PME_Area arg, PME_NatCon startColumn)
{
  if (PME_isAreaArea(arg)) {
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)startColumn, 1);
  }

  ATabort("Area has no StartColumn: %t\n", arg);
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
  
    return (PME_NatCon)ATgetArgument((ATermAppl)arg, 2);
}

/*}}}  */
/*{{{  PME_Area PME_setAreaEndLine(PME_Area arg, PME_NatCon endLine) */

PME_Area PME_setAreaEndLine(PME_Area arg, PME_NatCon endLine)
{
  if (PME_isAreaArea(arg)) {
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)endLine, 2);
  }

  ATabort("Area has no EndLine: %t\n", arg);
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
  
    return (PME_NatCon)ATgetArgument((ATermAppl)arg, 3);
}

/*}}}  */
/*{{{  PME_Area PME_setAreaEndColumn(PME_Area arg, PME_NatCon endColumn) */

PME_Area PME_setAreaEndColumn(PME_Area arg, PME_NatCon endColumn)
{
  if (PME_isAreaArea(arg)) {
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)endColumn, 3);
  }

  ATabort("Area has no EndColumn: %t\n", arg);
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
  
    return (PME_NatCon)ATgetArgument((ATermAppl)arg, 4);
}

/*}}}  */
/*{{{  PME_Area PME_setAreaStartOffset(PME_Area arg, PME_NatCon startOffset) */

PME_Area PME_setAreaStartOffset(PME_Area arg, PME_NatCon startOffset)
{
  if (PME_isAreaArea(arg)) {
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)startOffset, 4);
  }

  ATabort("Area has no StartOffset: %t\n", arg);
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
  
    return (PME_NatCon)ATgetArgument((ATermAppl)arg, 5);
}

/*}}}  */
/*{{{  PME_Area PME_setAreaEndOffset(PME_Area arg, PME_NatCon endOffset) */

PME_Area PME_setAreaEndOffset(PME_Area arg, PME_NatCon endOffset)
{
  if (PME_isAreaArea(arg)) {
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)endOffset, 5);
  }

  ATabort("Area has no EndOffset: %t\n", arg);
  return (PME_Area)NULL;
}

/*}}}  */

/*}}}  */
/*{{{  sort visitors */

/*{{{  PME_Feedback PME_visitFeedback(PME_Feedback arg, PME_Info (*acceptInfo)(PME_Info), PME_Warning (*acceptWarning)(PME_Warning), PME_Error (*acceptError)(PME_Error), PME_FatalError (*acceptFatalError)(PME_FatalError)) */

PME_Feedback PME_visitFeedback(PME_Feedback arg, PME_Info (*acceptInfo)(PME_Info), PME_Warning (*acceptWarning)(PME_Warning), PME_Error (*acceptError)(PME_Error), PME_FatalError (*acceptFatalError)(PME_FatalError))
{
  if (PME_isFeedbackInfo(arg)) {
    return PME_makeFeedbackInfo(
        acceptInfo ? acceptInfo(PME_getFeedbackInfo(arg)) : PME_getFeedbackInfo(arg));
  }
  if (PME_isFeedbackWarning(arg)) {
    return PME_makeFeedbackWarning(
        acceptWarning ? acceptWarning(PME_getFeedbackWarning(arg)) : PME_getFeedbackWarning(arg));
  }
  if (PME_isFeedbackError(arg)) {
    return PME_makeFeedbackError(
        acceptError ? acceptError(PME_getFeedbackError(arg)) : PME_getFeedbackError(arg));
  }
  if (PME_isFeedbackFatalError(arg)) {
    return PME_makeFeedbackFatalError(
        acceptFatalError ? acceptFatalError(PME_getFeedbackFatalError(arg)) : PME_getFeedbackFatalError(arg));
  }
  ATabort("not a Feedback: %t\n", arg);
  return (PME_Feedback)NULL;
}

/*}}}  */
/*{{{  PME_Information PME_visitInformation(PME_Information arg, PME_String (*acceptId)(PME_String), PME_Producer (*acceptProducer)(PME_Producer), PME_Description (*acceptDescription)(PME_Description), PME_Subjects (*acceptSubjects)(PME_Subjects)) */

PME_Information PME_visitInformation(PME_Information arg, PME_String (*acceptId)(PME_String), PME_Producer (*acceptProducer)(PME_Producer), PME_Description (*acceptDescription)(PME_Description), PME_Subjects (*acceptSubjects)(PME_Subjects))
{
  if (PME_isInformationInformation(arg)) {
    return PME_makeInformationInformation(
        acceptId ? acceptId(PME_getInformationId(arg)) : PME_getInformationId(arg),
        acceptProducer ? acceptProducer(PME_getInformationProducer(arg)) : PME_getInformationProducer(arg),
        acceptDescription ? acceptDescription(PME_getInformationDescription(arg)) : PME_getInformationDescription(arg),
        acceptSubjects ? acceptSubjects(PME_getInformationSubjects(arg)) : PME_getInformationSubjects(arg));
  }
  ATabort("not a Information: %t\n", arg);
  return (PME_Information)NULL;
}

/*}}}  */
/*{{{  PME_Warning PME_visitWarning(PME_Warning arg, PME_String (*acceptId)(PME_String), PME_Producer (*acceptProducer)(PME_Producer), PME_Description (*acceptDescription)(PME_Description), PME_Subjects (*acceptSubjects)(PME_Subjects)) */

PME_Warning PME_visitWarning(PME_Warning arg, PME_String (*acceptId)(PME_String), PME_Producer (*acceptProducer)(PME_Producer), PME_Description (*acceptDescription)(PME_Description), PME_Subjects (*acceptSubjects)(PME_Subjects))
{
  if (PME_isWarningWarning(arg)) {
    return PME_makeWarningWarning(
        acceptId ? acceptId(PME_getWarningId(arg)) : PME_getWarningId(arg),
        acceptProducer ? acceptProducer(PME_getWarningProducer(arg)) : PME_getWarningProducer(arg),
        acceptDescription ? acceptDescription(PME_getWarningDescription(arg)) : PME_getWarningDescription(arg),
        acceptSubjects ? acceptSubjects(PME_getWarningSubjects(arg)) : PME_getWarningSubjects(arg));
  }
  ATabort("not a Warning: %t\n", arg);
  return (PME_Warning)NULL;
}

/*}}}  */
/*{{{  PME_Error PME_visitError(PME_Error arg, PME_String (*acceptId)(PME_String), PME_Producer (*acceptProducer)(PME_Producer), PME_Description (*acceptDescription)(PME_Description), PME_Subjects (*acceptSubjects)(PME_Subjects)) */

PME_Error PME_visitError(PME_Error arg, PME_String (*acceptId)(PME_String), PME_Producer (*acceptProducer)(PME_Producer), PME_Description (*acceptDescription)(PME_Description), PME_Subjects (*acceptSubjects)(PME_Subjects))
{
  if (PME_isErrorError(arg)) {
    return PME_makeErrorError(
        acceptId ? acceptId(PME_getErrorId(arg)) : PME_getErrorId(arg),
        acceptProducer ? acceptProducer(PME_getErrorProducer(arg)) : PME_getErrorProducer(arg),
        acceptDescription ? acceptDescription(PME_getErrorDescription(arg)) : PME_getErrorDescription(arg),
        acceptSubjects ? acceptSubjects(PME_getErrorSubjects(arg)) : PME_getErrorSubjects(arg));
  }
  ATabort("not a Error: %t\n", arg);
  return (PME_Error)NULL;
}

/*}}}  */
/*{{{  PME_FatalError PME_visitFatalError(PME_FatalError arg, PME_String (*acceptId)(PME_String), PME_Producer (*acceptProducer)(PME_Producer), PME_Description (*acceptDescription)(PME_Description), PME_Subjects (*acceptSubjects)(PME_Subjects)) */

PME_FatalError PME_visitFatalError(PME_FatalError arg, PME_String (*acceptId)(PME_String), PME_Producer (*acceptProducer)(PME_Producer), PME_Description (*acceptDescription)(PME_Description), PME_Subjects (*acceptSubjects)(PME_Subjects))
{
  if (PME_isFatalErrorFatalError(arg)) {
    return PME_makeFatalErrorFatalError(
        acceptId ? acceptId(PME_getFatalErrorId(arg)) : PME_getFatalErrorId(arg),
        acceptProducer ? acceptProducer(PME_getFatalErrorProducer(arg)) : PME_getFatalErrorProducer(arg),
        acceptDescription ? acceptDescription(PME_getFatalErrorDescription(arg)) : PME_getFatalErrorDescription(arg),
        acceptSubjects ? acceptSubjects(PME_getFatalErrorSubjects(arg)) : PME_getFatalErrorSubjects(arg));
  }
  ATabort("not a FatalError: %t\n", arg);
  return (PME_FatalError)NULL;
}

/*}}}  */
/*{{{  PME_Producer PME_visitProducer(PME_Producer arg, PME_String (*acceptId)(PME_String), PME_String (*acceptType)(PME_String)) */

PME_Producer PME_visitProducer(PME_Producer arg, PME_String (*acceptId)(PME_String), PME_String (*acceptType)(PME_String))
{
  if (PME_isProducerProducer(arg)) {
    return PME_makeProducerProducer(
        acceptId ? acceptId(PME_getProducerId(arg)) : PME_getProducerId(arg),
        acceptType ? acceptType(PME_getProducerType(arg)) : PME_getProducerType(arg));
  }
  ATabort("not a Producer: %t\n", arg);
  return (PME_Producer)NULL;
}

/*}}}  */
/*{{{  PME_Description PME_visitDescription(PME_Description arg, PME_String (*acceptString)(PME_String)) */

PME_Description PME_visitDescription(PME_Description arg, PME_String (*acceptString)(PME_String))
{
  if (PME_isDescriptionDescription(arg)) {
    return PME_makeDescriptionDescription(
        acceptString ? acceptString(PME_getDescriptionString(arg)) : PME_getDescriptionString(arg));
  }
  ATabort("not a Description: %t\n", arg);
  return (PME_Description)NULL;
}

/*}}}  */
/*{{{  PME_Subjects PME_visitSubjects(PME_Subjects arg, PME_SubjectSubjectList (*acceptSubjectList)(PME_SubjectSubjectList)) */

PME_Subjects PME_visitSubjects(PME_Subjects arg, PME_SubjectSubjectList (*acceptSubjectList)(PME_SubjectSubjectList))
{
  if (PME_isSubjectsSubjects(arg)) {
    return PME_makeSubjectsSubjects(
        acceptSubjectList ? acceptSubjectList(PME_getSubjectsSubjectList(arg)) : PME_getSubjectsSubjectList(arg));
  }
  ATabort("not a Subjects: %t\n", arg);
  return (PME_Subjects)NULL;
}

/*}}}  */
/*{{{  PME_SubjectSubjectList PME_visitSubjectSubjectList(PME_SubjectSubjectList arg, PME_Subject (*acceptHead)(PME_Subject)) */

PME_SubjectSubjectList PME_visitSubjectSubjectList(PME_SubjectSubjectList arg, PME_Subject (*acceptHead)(PME_Subject))
{
  if (PME_isSubjectSubjectListMany(arg)) {
    return PME_makeSubjectSubjectListMany(
        acceptHead ? acceptHead(PME_getSubjectSubjectListHead(arg)) : PME_getSubjectSubjectListHead(arg),
        PME_visitSubjectSubjectList(PME_getSubjectSubjectListTail(arg), acceptHead));
  }
  if (PME_isSubjectSubjectListEmpty(arg)) {
    return PME_makeSubjectSubjectListEmpty();
  }
  ATabort("not a SubjectSubjectList: %t\n", arg);
  return (PME_SubjectSubjectList)NULL;
}

/*}}}  */
/*{{{  PME_Subject PME_visitSubject(PME_Subject arg, PME_String (*acceptId)(PME_String), PME_Location (*acceptLocation)(PME_Location)) */

PME_Subject PME_visitSubject(PME_Subject arg, PME_String (*acceptId)(PME_String), PME_Location (*acceptLocation)(PME_Location))
{
  if (PME_isSubjectWithoutLocation(arg)) {
    return PME_makeSubjectWithoutLocation(
        acceptId ? acceptId(PME_getSubjectId(arg)) : PME_getSubjectId(arg),
        acceptLocation ? acceptLocation(PME_getSubjectLocation(arg)) : PME_getSubjectLocation(arg));
  }
  if (PME_isSubjectWithLocation(arg)) {
    return PME_makeSubjectWithLocation(
        acceptId ? acceptId(PME_getSubjectId(arg)) : PME_getSubjectId(arg));
  }
  ATabort("not a Subject: %t\n", arg);
  return (PME_Subject)NULL;
}

/*}}}  */
/*{{{  PME_Location PME_visitLocation(PME_Location arg, PME_String (*acceptFile)(PME_String), PME_Area (*acceptArea)(PME_Area)) */

PME_Location PME_visitLocation(PME_Location arg, PME_String (*acceptFile)(PME_String), PME_Area (*acceptArea)(PME_Area))
{
  if (PME_isLocationLocation(arg)) {
    return PME_makeLocationLocation(
        acceptFile ? acceptFile(PME_getLocationFile(arg)) : PME_getLocationFile(arg),
        acceptArea ? acceptArea(PME_getLocationArea(arg)) : PME_getLocationArea(arg));
  }
  ATabort("not a Location: %t\n", arg);
  return (PME_Location)NULL;
}

/*}}}  */
/*{{{  PME_Area PME_visitArea(PME_Area arg, PME_NatCon (*acceptStartLine)(PME_NatCon), PME_NatCon (*acceptStartColumn)(PME_NatCon), PME_NatCon (*acceptEndLine)(PME_NatCon), PME_NatCon (*acceptEndColumn)(PME_NatCon), PME_NatCon (*acceptStartOffset)(PME_NatCon), PME_NatCon (*acceptEndOffset)(PME_NatCon)) */

PME_Area PME_visitArea(PME_Area arg, PME_NatCon (*acceptStartLine)(PME_NatCon), PME_NatCon (*acceptStartColumn)(PME_NatCon), PME_NatCon (*acceptEndLine)(PME_NatCon), PME_NatCon (*acceptEndColumn)(PME_NatCon), PME_NatCon (*acceptStartOffset)(PME_NatCon), PME_NatCon (*acceptEndOffset)(PME_NatCon))
{
  if (PME_isAreaArea(arg)) {
    return PME_makeAreaArea(
        acceptStartLine ? acceptStartLine(PME_getAreaStartLine(arg)) : PME_getAreaStartLine(arg),
        acceptStartColumn ? acceptStartColumn(PME_getAreaStartColumn(arg)) : PME_getAreaStartColumn(arg),
        acceptEndLine ? acceptEndLine(PME_getAreaEndLine(arg)) : PME_getAreaEndLine(arg),
        acceptEndColumn ? acceptEndColumn(PME_getAreaEndColumn(arg)) : PME_getAreaEndColumn(arg),
        acceptStartOffset ? acceptStartOffset(PME_getAreaStartOffset(arg)) : PME_getAreaStartOffset(arg),
        acceptEndOffset ? acceptEndOffset(PME_getAreaEndOffset(arg)) : PME_getAreaEndOffset(arg));
  }
  ATabort("not a Area: %t\n", arg);
  return (PME_Area)NULL;
}

/*}}}  */

/*}}}  */
