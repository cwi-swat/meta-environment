#include <assert.h>

#include <aterm2.h>
#include <deprecated.h>
#include "ParsedErrors.h"

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
typedef struct ATerm _PME_Start;
typedef struct ATerm _PME_OptLayout;

/*}}}  */

/*{{{  void PME_initParsedErrorsApi(void) */

void PME_initParsedErrorsApi(void)
{
  init_ParsedErrors_dict();
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

/*}}}  */
/*{{{  list functions */

int PME_getSubjectSubjectListLength (PME_SubjectSubjectList arg) {
  if (ATisEmpty((ATermList) arg)) {
    return 0;
  }
  return (ATgetLength((ATermList) arg) / 4) + 1;
}
PME_SubjectSubjectList PME_appendSubjectSubjectList(PME_SubjectSubjectList arg0, PME_OptLayout wsAfterFirst, char* sep, PME_OptLayout wsAfterSep, PME_Subject arg1) {
  return PME_concatSubjectSubjectList(arg0, wsAfterFirst, sep, wsAfterSep, PME_makeSubjectSubjectListSingle(arg1));
}
PME_SubjectSubjectList PME_concatSubjectSubjectList(PME_SubjectSubjectList arg0, PME_OptLayout wsAfterFirst, char* sep, PME_OptLayout wsAfterSep, PME_SubjectSubjectList arg1) {
  if (ATisEmpty((ATermList) arg0)) {
    return arg1;
  }
  arg1 = PME_makeSubjectSubjectListMany((PME_Subject)ATgetFirst((ATermList) arg0), wsAfterFirst, sep, wsAfterSep,  arg1);
  arg1 = (PME_SubjectSubjectList) ATgetNext((ATermList) arg1);
  return (PME_SubjectSubjectList) ATconcat((ATermList) arg0, (ATermList) arg1);
}
PME_SubjectSubjectList reverseSubjectSubjectList(PME_SubjectSubjectList arg) {
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

  return (PME_SubjectSubjectList) result;
}

/*}}}  */
/*{{{  constructors */

/*{{{  PME_Feedback PME_makeFeedbackInfo(PME_Info Info) */

PME_Feedback PME_makeFeedbackInfo(PME_Info Info)
{
  return (PME_Feedback)(ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun4)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun5))), (ATerm)ATmakeAppl1(PME_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PME_afun7, (ATerm)ATmakeAppl1(PME_afun8, (ATerm)ATmakeAppl0(PME_afun9)))))), (ATerm)ATmakeList1((ATerm)Info));
}

/*}}}  */
/*{{{  PME_Feedback PME_makeFeedbackWarning(PME_Warning Warning) */

PME_Feedback PME_makeFeedbackWarning(PME_Warning Warning)
{
  return (PME_Feedback)(ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun10)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun5))), (ATerm)ATmakeAppl1(PME_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PME_afun7, (ATerm)ATmakeAppl1(PME_afun8, (ATerm)ATmakeAppl0(PME_afun11)))))), (ATerm)ATmakeList1((ATerm)Warning));
}

/*}}}  */
/*{{{  PME_Feedback PME_makeFeedbackError(PME_Error Error) */

PME_Feedback PME_makeFeedbackError(PME_Error Error)
{
  return (PME_Feedback)(ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun12)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun5))), (ATerm)ATmakeAppl1(PME_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PME_afun7, (ATerm)ATmakeAppl1(PME_afun8, (ATerm)ATmakeAppl0(PME_afun13)))))), (ATerm)ATmakeList1((ATerm)Error));
}

/*}}}  */
/*{{{  PME_Feedback PME_makeFeedbackFatalError(PME_FatalError FatalError) */

PME_Feedback PME_makeFeedbackFatalError(PME_FatalError FatalError)
{
  return (PME_Feedback)(ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun14)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun5))), (ATerm)ATmakeAppl1(PME_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PME_afun7, (ATerm)ATmakeAppl1(PME_afun8, (ATerm)ATmakeAppl0(PME_afun15)))))), (ATerm)ATmakeList1((ATerm)FatalError));
}

/*}}}  */
/*{{{  PME_Information PME_makeInformationInformation(PME_OptLayout wsAfterInformation, PME_OptLayout wsAfterParenOpen, PME_String id, PME_OptLayout wsAfterId, PME_OptLayout wsAfterC1, PME_Producer producer, PME_OptLayout wsAfterProducer, PME_OptLayout wsAfterC2, PME_Description description, PME_OptLayout wsAfterDescription, PME_OptLayout wsAfterC3, PME_Subjects subjects, PME_OptLayout wsAfterSubjects) */

PME_Information PME_makeInformationInformation(PME_OptLayout wsAfterInformation, PME_OptLayout wsAfterParenOpen, PME_String id, PME_OptLayout wsAfterId, PME_OptLayout wsAfterC1, PME_Producer producer, PME_OptLayout wsAfterProducer, PME_OptLayout wsAfterC2, PME_Description description, PME_OptLayout wsAfterDescription, PME_OptLayout wsAfterC3, PME_Subjects subjects, PME_OptLayout wsAfterSubjects)
{
  return (PME_Information)(ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun17))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun20)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun22)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun23)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun24)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun25))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun26))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun27))), (ATerm)ATmakeAppl1(PME_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PME_afun7, (ATerm)ATmakeAppl1(PME_afun8, (ATerm)ATmakeAppl0(PME_afun26)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun17))), (ATerm)wsAfterSubjects), (ATerm)subjects), (ATerm)wsAfterC3), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)wsAfterDescription), (ATerm)description), (ATerm)wsAfterC2), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)wsAfterProducer), (ATerm)producer), (ATerm)wsAfterC1), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)wsAfterId), (ATerm)id), (ATerm)wsAfterParenOpen), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun25))), (ATerm)wsAfterInformation), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun26))));
}

/*}}}  */
/*{{{  PME_Warning PME_makeWarningWarning(PME_OptLayout wsAfterWarning, PME_OptLayout wsAfterParenOpen, PME_String id, PME_OptLayout wsAfterId, PME_OptLayout wsAfterC1, PME_Producer producer, PME_OptLayout wsAfterProducer, PME_OptLayout wsAfterC2, PME_Description description, PME_OptLayout wsAfterDescription, PME_OptLayout wsAfterC3, PME_Subjects subjects, PME_OptLayout wsAfterSubjects) */

PME_Warning PME_makeWarningWarning(PME_OptLayout wsAfterWarning, PME_OptLayout wsAfterParenOpen, PME_String id, PME_OptLayout wsAfterId, PME_OptLayout wsAfterC1, PME_Producer producer, PME_OptLayout wsAfterProducer, PME_OptLayout wsAfterC2, PME_Description description, PME_OptLayout wsAfterDescription, PME_OptLayout wsAfterC3, PME_Subjects subjects, PME_OptLayout wsAfterSubjects)
{
  return (PME_Warning)(ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun17))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun20)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun22)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun23)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun24)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun25))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun11))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun10))), (ATerm)ATmakeAppl1(PME_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PME_afun7, (ATerm)ATmakeAppl1(PME_afun8, (ATerm)ATmakeAppl0(PME_afun11)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun17))), (ATerm)wsAfterSubjects), (ATerm)subjects), (ATerm)wsAfterC3), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)wsAfterDescription), (ATerm)description), (ATerm)wsAfterC2), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)wsAfterProducer), (ATerm)producer), (ATerm)wsAfterC1), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)wsAfterId), (ATerm)id), (ATerm)wsAfterParenOpen), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun25))), (ATerm)wsAfterWarning), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun11))));
}

/*}}}  */
/*{{{  PME_Error PME_makeErrorError(PME_OptLayout wsAfterError, PME_OptLayout wsAfterParenOpen, PME_String id, PME_OptLayout wsAfterId, PME_OptLayout wsAfterC1, PME_Producer producer, PME_OptLayout wsAfterProducer, PME_OptLayout wsAfterC2, PME_Description description, PME_OptLayout wsAfterDescription, PME_OptLayout wsAfterC3, PME_Subjects subjects, PME_OptLayout wsAfterSubjects) */

PME_Error PME_makeErrorError(PME_OptLayout wsAfterError, PME_OptLayout wsAfterParenOpen, PME_String id, PME_OptLayout wsAfterId, PME_OptLayout wsAfterC1, PME_Producer producer, PME_OptLayout wsAfterProducer, PME_OptLayout wsAfterC2, PME_Description description, PME_OptLayout wsAfterDescription, PME_OptLayout wsAfterC3, PME_Subjects subjects, PME_OptLayout wsAfterSubjects)
{
  return (PME_Error)(ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun17))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun20)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun22)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun23)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun24)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun25))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun13))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun12))), (ATerm)ATmakeAppl1(PME_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PME_afun7, (ATerm)ATmakeAppl1(PME_afun8, (ATerm)ATmakeAppl0(PME_afun13)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun17))), (ATerm)wsAfterSubjects), (ATerm)subjects), (ATerm)wsAfterC3), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)wsAfterDescription), (ATerm)description), (ATerm)wsAfterC2), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)wsAfterProducer), (ATerm)producer), (ATerm)wsAfterC1), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)wsAfterId), (ATerm)id), (ATerm)wsAfterParenOpen), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun25))), (ATerm)wsAfterError), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun13))));
}

/*}}}  */
/*{{{  PME_FatalError PME_makeFatalErrorFatalError(PME_OptLayout wsAfterFatalError, PME_OptLayout wsAfterParenOpen, PME_String id, PME_OptLayout wsAfterId, PME_OptLayout wsAfterC1, PME_Producer producer, PME_OptLayout wsAfterProducer, PME_OptLayout wsAfterC2, PME_Description description, PME_OptLayout wsAfterDescription, PME_OptLayout wsAfterC3, PME_Subjects subjects, PME_OptLayout wsAfterSubjects) */

PME_FatalError PME_makeFatalErrorFatalError(PME_OptLayout wsAfterFatalError, PME_OptLayout wsAfterParenOpen, PME_String id, PME_OptLayout wsAfterId, PME_OptLayout wsAfterC1, PME_Producer producer, PME_OptLayout wsAfterProducer, PME_OptLayout wsAfterC2, PME_Description description, PME_OptLayout wsAfterDescription, PME_OptLayout wsAfterC3, PME_Subjects subjects, PME_OptLayout wsAfterSubjects)
{
  return (PME_FatalError)(ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun17))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun20)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun22)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun23)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun24)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun25))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun15))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun14))), (ATerm)ATmakeAppl1(PME_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PME_afun7, (ATerm)ATmakeAppl1(PME_afun8, (ATerm)ATmakeAppl0(PME_afun15)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun17))), (ATerm)wsAfterSubjects), (ATerm)subjects), (ATerm)wsAfterC3), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)wsAfterDescription), (ATerm)description), (ATerm)wsAfterC2), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)wsAfterProducer), (ATerm)producer), (ATerm)wsAfterC1), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)wsAfterId), (ATerm)id), (ATerm)wsAfterParenOpen), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun25))), (ATerm)wsAfterFatalError), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun15))));
}

/*}}}  */
/*{{{  PME_Producer PME_makeProducerProducer(PME_OptLayout wsAfterProducer, PME_OptLayout wsAfterParenOpen, PME_String id, PME_OptLayout wsAfterId, PME_OptLayout wsAfterComma, PME_String type, PME_OptLayout wsAfterType) */

PME_Producer PME_makeProducerProducer(PME_OptLayout wsAfterProducer, PME_OptLayout wsAfterParenOpen, PME_String id, PME_OptLayout wsAfterId, PME_OptLayout wsAfterComma, PME_String type, PME_OptLayout wsAfterType)
{
  return (PME_Producer)(ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun17))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun24)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun24)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun25))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun28))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun23))), (ATerm)ATmakeAppl1(PME_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PME_afun7, (ATerm)ATmakeAppl1(PME_afun8, (ATerm)ATmakeAppl0(PME_afun28)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun17))), (ATerm)wsAfterType), (ATerm)type), (ATerm)wsAfterComma), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)wsAfterId), (ATerm)id), (ATerm)wsAfterParenOpen), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun25))), (ATerm)wsAfterProducer), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun28))));
}

/*}}}  */
/*{{{  PME_Description PME_makeDescriptionDescription(PME_OptLayout wsAfterDescription, PME_OptLayout wsAfterParenOpen, PME_String String, PME_OptLayout wsAfterString) */

PME_Description PME_makeDescriptionDescription(PME_OptLayout wsAfterDescription, PME_OptLayout wsAfterParenOpen, PME_String String, PME_OptLayout wsAfterString)
{
  return (PME_Description)(ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun17))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun24)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun25))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun29))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun22))), (ATerm)ATmakeAppl1(PME_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PME_afun7, (ATerm)ATmakeAppl1(PME_afun8, (ATerm)ATmakeAppl0(PME_afun29)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun17))), (ATerm)wsAfterString), (ATerm)String), (ATerm)wsAfterParenOpen), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun25))), (ATerm)wsAfterDescription), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun29))));
}

/*}}}  */
/*{{{  PME_Subjects PME_makeSubjectsSubjects(PME_OptLayout wsAfterBracketOpen, PME_SubjectSubjectList subjectList, PME_OptLayout wsAfterSubjectList) */

PME_Subjects PME_makeSubjectsSubjects(PME_OptLayout wsAfterBracketOpen, PME_SubjectSubjectList subjectList, PME_OptLayout wsAfterSubjectList)
{
  return (PME_Subjects)(ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun30))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl2(PME_afun31, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun32)), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun33))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun20))), (ATerm)ATmakeAppl1(PME_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PME_afun7, (ATerm)ATmakeAppl1(PME_afun8, (ATerm)ATmakeAppl0(PME_afun34)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun30))), (ATerm)wsAfterSubjectList), (ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl1(PME_afun35, (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl2(PME_afun31, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun32)), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))))), (ATerm)subjectList)), (ATerm)wsAfterBracketOpen), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun33))));
}

/*}}}  */
/*{{{  PME_SubjectSubjectList PME_makeSubjectSubjectListMany(PME_Subject head, PME_OptLayout wsAfterFirst, char* sep, PME_OptLayout wsAfterSep, PME_SubjectSubjectList tail) */

PME_SubjectSubjectList PME_makeSubjectSubjectListMany(PME_Subject head, PME_OptLayout wsAfterFirst, char* sep, PME_OptLayout wsAfterSep, PME_SubjectSubjectList tail)
{
  if (PME_isSubjectSubjectListEmpty(tail)) {
    return PME_makeSubjectSubjectListSingle(head);
  }
  return (PME_SubjectSubjectList)(ATerm)ATinsert(ATinsert(ATinsert(ATinsert((ATermList)tail, (ATerm)wsAfterSep), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)))), (ATerm)wsAfterFirst), (ATerm)head);
}

/*}}}  */
/*{{{  PME_SubjectSubjectList PME_makeSubjectSubjectListEmpty() */

PME_SubjectSubjectList PME_makeSubjectSubjectListEmpty()
{
  return (PME_SubjectSubjectList)(ATerm)ATempty;
}

/*}}}  */
/*{{{  PME_SubjectSubjectList PME_makeSubjectSubjectListSingle(PME_Subject head) */

PME_SubjectSubjectList PME_makeSubjectSubjectListSingle(PME_Subject head)
{
  return (PME_SubjectSubjectList)(ATerm)ATmakeList1((ATerm)head);
}

/*}}}  */
/*{{{  PME_Subject PME_makeSubjectWithoutLocation(PME_OptLayout wsAfterSubject, PME_OptLayout wsAfterParenOpen, PME_String id, PME_OptLayout wsAfterId, PME_OptLayout wsAfterComma, PME_Location location, PME_OptLayout wsAfterLocation) */

PME_Subject PME_makeSubjectWithoutLocation(PME_OptLayout wsAfterSubject, PME_OptLayout wsAfterParenOpen, PME_String id, PME_OptLayout wsAfterId, PME_OptLayout wsAfterComma, PME_Location location, PME_OptLayout wsAfterLocation)
{
  return (PME_Subject)(ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun17))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun36)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun24)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun25))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun37))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun32))), (ATerm)ATmakeAppl1(PME_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PME_afun7, (ATerm)ATmakeAppl1(PME_afun8, (ATerm)ATmakeAppl0(PME_afun38)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun17))), (ATerm)wsAfterLocation), (ATerm)location), (ATerm)wsAfterComma), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)wsAfterId), (ATerm)id), (ATerm)wsAfterParenOpen), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun25))), (ATerm)wsAfterSubject), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun37))));
}

/*}}}  */
/*{{{  PME_Subject PME_makeSubjectWithLocation(PME_OptLayout wsAfterSubject, PME_OptLayout wsAfterParenOpen, PME_String id, PME_OptLayout wsAfterId) */

PME_Subject PME_makeSubjectWithLocation(PME_OptLayout wsAfterSubject, PME_OptLayout wsAfterParenOpen, PME_String id, PME_OptLayout wsAfterId)
{
  return (PME_Subject)(ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun17))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun24)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun25))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun37))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun32))), (ATerm)ATmakeAppl1(PME_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PME_afun7, (ATerm)ATmakeAppl1(PME_afun8, (ATerm)ATmakeAppl0(PME_afun39)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun17))), (ATerm)wsAfterId), (ATerm)id), (ATerm)wsAfterParenOpen), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun25))), (ATerm)wsAfterSubject), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun37))));
}

/*}}}  */
/*{{{  PME_Location PME_makeLocationLocation(PME_OptLayout wsAfterLocation, PME_OptLayout wsAfterParenOpen, PME_String file, PME_OptLayout wsAfterFile, PME_OptLayout wsAfterComma, PME_Area area, PME_OptLayout wsAfterArea) */

PME_Location PME_makeLocationLocation(PME_OptLayout wsAfterLocation, PME_OptLayout wsAfterParenOpen, PME_String file, PME_OptLayout wsAfterFile, PME_OptLayout wsAfterComma, PME_Area area, PME_OptLayout wsAfterArea)
{
  return (PME_Location)(ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun17))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun40)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun24)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun25))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun41))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun36))), (ATerm)ATmakeAppl1(PME_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PME_afun7, (ATerm)ATmakeAppl1(PME_afun8, (ATerm)ATmakeAppl0(PME_afun41)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun17))), (ATerm)wsAfterArea), (ATerm)area), (ATerm)wsAfterComma), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)wsAfterFile), (ATerm)file), (ATerm)wsAfterParenOpen), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun25))), (ATerm)wsAfterLocation), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun41))));
}

/*}}}  */
/*{{{  PME_Area PME_makeAreaArea(PME_OptLayout wsAfterArea, PME_OptLayout wsAfterParenOpen, PME_NatCon startLine, PME_OptLayout wsAfterStartLine, PME_OptLayout wsAfterC1, PME_NatCon startColumn, PME_OptLayout wsAfterStartColumn, PME_OptLayout wsAfterC2, PME_NatCon endLine, PME_OptLayout wsAfterEndLine, PME_OptLayout wsAfterC3, PME_NatCon endColumn, PME_OptLayout wsAfterEndColumn, PME_OptLayout wsAfterC4, PME_NatCon startOffset, PME_OptLayout wsAfterStartOffset, PME_OptLayout wsAfterC5, PME_NatCon endOffset, PME_OptLayout wsAfterEndOffset) */

PME_Area PME_makeAreaArea(PME_OptLayout wsAfterArea, PME_OptLayout wsAfterParenOpen, PME_NatCon startLine, PME_OptLayout wsAfterStartLine, PME_OptLayout wsAfterC1, PME_NatCon startColumn, PME_OptLayout wsAfterStartColumn, PME_OptLayout wsAfterC2, PME_NatCon endLine, PME_OptLayout wsAfterEndLine, PME_OptLayout wsAfterC3, PME_NatCon endColumn, PME_OptLayout wsAfterEndColumn, PME_OptLayout wsAfterC4, PME_NatCon startOffset, PME_OptLayout wsAfterStartOffset, PME_OptLayout wsAfterC5, PME_NatCon endOffset, PME_OptLayout wsAfterEndOffset)
{
  return (PME_Area)(ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun17))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun42)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun42)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun42)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun42)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun42)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun42)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun25))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun43))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun40))), (ATerm)ATmakeAppl1(PME_afun6, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PME_afun7, (ATerm)ATmakeAppl1(PME_afun8, (ATerm)ATmakeAppl0(PME_afun43)))))), (ATerm)ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun17))), (ATerm)wsAfterEndOffset), (ATerm)endOffset), (ATerm)wsAfterC5), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)wsAfterStartOffset), (ATerm)startOffset), (ATerm)wsAfterC4), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)wsAfterEndColumn), (ATerm)endColumn), (ATerm)wsAfterC3), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)wsAfterEndLine), (ATerm)endLine), (ATerm)wsAfterC2), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)wsAfterStartColumn), (ATerm)startColumn), (ATerm)wsAfterC1), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun21))), (ATerm)wsAfterStartLine), (ATerm)startLine), (ATerm)wsAfterParenOpen), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun25))), (ATerm)wsAfterArea), (ATerm)ATmakeAppl1(PME_afun16, (ATerm)ATmakeAppl0(PME_afun43))));
}

/*}}}  */
/*{{{  PME_Start PME_makeStartArea(PME_OptLayout wsBefore, PME_Area topArea, PME_OptLayout wsAfter, int ambCnt) */

PME_Start PME_makeStartArea(PME_OptLayout wsBefore, PME_Area topArea, PME_OptLayout wsAfter, int ambCnt)
{
  return (PME_Start)(ATerm)ATmakeAppl2(PME_afun44, (ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun40)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun45)), (ATerm)ATmakeAppl0(PME_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topArea), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  PME_Start PME_makeStartLocation(PME_OptLayout wsBefore, PME_Location topLocation, PME_OptLayout wsAfter, int ambCnt) */

PME_Start PME_makeStartLocation(PME_OptLayout wsBefore, PME_Location topLocation, PME_OptLayout wsAfter, int ambCnt)
{
  return (PME_Start)(ATerm)ATmakeAppl2(PME_afun44, (ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun36)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun45)), (ATerm)ATmakeAppl0(PME_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topLocation), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  PME_Start PME_makeStartFeedback(PME_OptLayout wsBefore, PME_Feedback topFeedback, PME_OptLayout wsAfter, int ambCnt) */

PME_Start PME_makeStartFeedback(PME_OptLayout wsBefore, PME_Feedback topFeedback, PME_OptLayout wsAfter, int ambCnt)
{
  return (PME_Start)(ATerm)ATmakeAppl2(PME_afun44, (ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun5)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun45)), (ATerm)ATmakeAppl0(PME_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topFeedback), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  PME_Start PME_makeStartDescription(PME_OptLayout wsBefore, PME_Description topDescription, PME_OptLayout wsAfter, int ambCnt) */

PME_Start PME_makeStartDescription(PME_OptLayout wsBefore, PME_Description topDescription, PME_OptLayout wsAfter, int ambCnt)
{
  return (PME_Start)(ATerm)ATmakeAppl2(PME_afun44, (ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun22)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun45)), (ATerm)ATmakeAppl0(PME_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topDescription), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  PME_Start PME_makeStartProducer(PME_OptLayout wsBefore, PME_Producer topProducer, PME_OptLayout wsAfter, int ambCnt) */

PME_Start PME_makeStartProducer(PME_OptLayout wsBefore, PME_Producer topProducer, PME_OptLayout wsAfter, int ambCnt)
{
  return (PME_Start)(ATerm)ATmakeAppl2(PME_afun44, (ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun23)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun45)), (ATerm)ATmakeAppl0(PME_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topProducer), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  PME_Start PME_makeStartInformation(PME_OptLayout wsBefore, PME_Information topInformation, PME_OptLayout wsAfter, int ambCnt) */

PME_Start PME_makeStartInformation(PME_OptLayout wsBefore, PME_Information topInformation, PME_OptLayout wsAfter, int ambCnt)
{
  return (PME_Start)(ATerm)ATmakeAppl2(PME_afun44, (ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun27)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun45)), (ATerm)ATmakeAppl0(PME_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topInformation), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  PME_Start PME_makeStartWarning(PME_OptLayout wsBefore, PME_Warning topWarning, PME_OptLayout wsAfter, int ambCnt) */

PME_Start PME_makeStartWarning(PME_OptLayout wsBefore, PME_Warning topWarning, PME_OptLayout wsAfter, int ambCnt)
{
  return (PME_Start)(ATerm)ATmakeAppl2(PME_afun44, (ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun10)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun45)), (ATerm)ATmakeAppl0(PME_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topWarning), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  PME_Start PME_makeStartFatalError(PME_OptLayout wsBefore, PME_FatalError topFatalError, PME_OptLayout wsAfter, int ambCnt) */

PME_Start PME_makeStartFatalError(PME_OptLayout wsBefore, PME_FatalError topFatalError, PME_OptLayout wsAfter, int ambCnt)
{
  return (PME_Start)(ATerm)ATmakeAppl2(PME_afun44, (ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun14)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun45)), (ATerm)ATmakeAppl0(PME_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topFatalError), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  PME_Start PME_makeStartError(PME_OptLayout wsBefore, PME_Error topError, PME_OptLayout wsAfter, int ambCnt) */

PME_Start PME_makeStartError(PME_OptLayout wsBefore, PME_Error topError, PME_OptLayout wsAfter, int ambCnt)
{
  return (PME_Start)(ATerm)ATmakeAppl2(PME_afun44, (ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun12)))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19)))), (ATerm)ATmakeAppl1(PME_afun3, (ATerm)ATmakeAppl0(PME_afun45)), (ATerm)ATmakeAppl0(PME_afun46)), (ATerm)ATinsert(ATinsert(ATmakeList1((ATerm)wsAfter), (ATerm)topError), (ATerm)wsBefore)), (ATerm)ATmakeInt(ambCnt));
}

/*}}}  */
/*{{{  PME_OptLayout PME_makeOptLayoutAbsent() */

PME_OptLayout PME_makeOptLayoutAbsent()
{
  return (PME_OptLayout)(ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATempty, (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19))), (ATerm)ATmakeAppl0(PME_afun46)), (ATerm)ATempty);
}

/*}}}  */
/*{{{  PME_OptLayout PME_makeOptLayoutPresent(PME_CHARLIST chars) */

PME_OptLayout PME_makeOptLayoutPresent(PME_CHARLIST chars)
{
  return (PME_OptLayout)(ATerm)ATmakeAppl2(PME_afun0, (ATerm)ATmakeAppl3(PME_afun1, (ATerm)ATmakeList1((ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl0(PME_afun19))), (ATerm)ATmakeAppl1(PME_afun2, (ATerm)ATmakeAppl1(PME_afun18, (ATerm)ATmakeAppl0(PME_afun19))), (ATerm)ATmakeAppl0(PME_afun46)), (ATerm)chars);
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

ATbool PME_isEqualStart(PME_Start arg0, PME_Start arg1)
{
  return ATisEqual((ATerm)arg0, (ATerm)arg1);
}

ATbool PME_isEqualOptLayout(PME_OptLayout arg0, PME_OptLayout arg1)
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
  
    return (PME_Info)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  PME_Feedback PME_setFeedbackInfo(PME_Feedback arg, PME_Info Info) */

PME_Feedback PME_setFeedbackInfo(PME_Feedback arg, PME_Info Info)
{
  if (PME_isFeedbackInfo(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Info, 0), 1);
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
  
    return (PME_Warning)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  PME_Feedback PME_setFeedbackWarning(PME_Feedback arg, PME_Warning Warning) */

PME_Feedback PME_setFeedbackWarning(PME_Feedback arg, PME_Warning Warning)
{
  if (PME_isFeedbackWarning(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Warning, 0), 1);
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
  
    return (PME_Error)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  PME_Feedback PME_setFeedbackError(PME_Feedback arg, PME_Error Error) */

PME_Feedback PME_setFeedbackError(PME_Feedback arg, PME_Error Error)
{
  if (PME_isFeedbackError(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)Error, 0), 1);
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
  
    return (PME_FatalError)ATgetFirst((ATermList)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  PME_Feedback PME_setFeedbackFatalError(PME_Feedback arg, PME_FatalError FatalError) */

PME_Feedback PME_setFeedbackFatalError(PME_Feedback arg, PME_FatalError FatalError)
{
  if (PME_isFeedbackFatalError(arg)) {
    return (PME_Feedback)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)FatalError, 0), 1);
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
  assert(ATmatchTerm((ATerm)arg, PME_patternInformationInformation, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PME_hasInformationWsAfterInformation(PME_Information arg) */

ATbool PME_hasInformationWsAfterInformation(PME_Information arg)
{
  if (PME_isInformationInformation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getInformationWsAfterInformation(PME_Information arg) */

PME_OptLayout PME_getInformationWsAfterInformation(PME_Information arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PME_Information PME_setInformationWsAfterInformation(PME_Information arg, PME_OptLayout wsAfterInformation) */

PME_Information PME_setInformationWsAfterInformation(PME_Information arg, PME_OptLayout wsAfterInformation)
{
  if (PME_isInformationInformation(arg)) {
    return (PME_Information)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterInformation, 1), 1);
  }

  ATabort("Information has no WsAfterInformation: %t\n", arg);
  return (PME_Information)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasInformationWsAfterParenOpen(PME_Information arg) */

ATbool PME_hasInformationWsAfterParenOpen(PME_Information arg)
{
  if (PME_isInformationInformation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getInformationWsAfterParenOpen(PME_Information arg) */

PME_OptLayout PME_getInformationWsAfterParenOpen(PME_Information arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  PME_Information PME_setInformationWsAfterParenOpen(PME_Information arg, PME_OptLayout wsAfterParenOpen) */

PME_Information PME_setInformationWsAfterParenOpen(PME_Information arg, PME_OptLayout wsAfterParenOpen)
{
  if (PME_isInformationInformation(arg)) {
    return (PME_Information)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenOpen, 3), 1);
  }

  ATabort("Information has no WsAfterParenOpen: %t\n", arg);
  return (PME_Information)NULL;
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
  
    return (PME_String)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PME_Information PME_setInformationId(PME_Information arg, PME_String id) */

PME_Information PME_setInformationId(PME_Information arg, PME_String id)
{
  if (PME_isInformationInformation(arg)) {
    return (PME_Information)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)id, 4), 1);
  }

  ATabort("Information has no Id: %t\n", arg);
  return (PME_Information)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasInformationWsAfterId(PME_Information arg) */

ATbool PME_hasInformationWsAfterId(PME_Information arg)
{
  if (PME_isInformationInformation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getInformationWsAfterId(PME_Information arg) */

PME_OptLayout PME_getInformationWsAfterId(PME_Information arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PME_Information PME_setInformationWsAfterId(PME_Information arg, PME_OptLayout wsAfterId) */

PME_Information PME_setInformationWsAfterId(PME_Information arg, PME_OptLayout wsAfterId)
{
  if (PME_isInformationInformation(arg)) {
    return (PME_Information)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterId, 5), 1);
  }

  ATabort("Information has no WsAfterId: %t\n", arg);
  return (PME_Information)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasInformationWsAfterC1(PME_Information arg) */

ATbool PME_hasInformationWsAfterC1(PME_Information arg)
{
  if (PME_isInformationInformation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getInformationWsAfterC1(PME_Information arg) */

PME_OptLayout PME_getInformationWsAfterC1(PME_Information arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  PME_Information PME_setInformationWsAfterC1(PME_Information arg, PME_OptLayout wsAfterC1) */

PME_Information PME_setInformationWsAfterC1(PME_Information arg, PME_OptLayout wsAfterC1)
{
  if (PME_isInformationInformation(arg)) {
    return (PME_Information)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterC1, 7), 1);
  }

  ATabort("Information has no WsAfterC1: %t\n", arg);
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
  
    return (PME_Producer)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/*}}}  */
/*{{{  PME_Information PME_setInformationProducer(PME_Information arg, PME_Producer producer) */

PME_Information PME_setInformationProducer(PME_Information arg, PME_Producer producer)
{
  if (PME_isInformationInformation(arg)) {
    return (PME_Information)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)producer, 8), 1);
  }

  ATabort("Information has no Producer: %t\n", arg);
  return (PME_Information)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasInformationWsAfterProducer(PME_Information arg) */

ATbool PME_hasInformationWsAfterProducer(PME_Information arg)
{
  if (PME_isInformationInformation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getInformationWsAfterProducer(PME_Information arg) */

PME_OptLayout PME_getInformationWsAfterProducer(PME_Information arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/*}}}  */
/*{{{  PME_Information PME_setInformationWsAfterProducer(PME_Information arg, PME_OptLayout wsAfterProducer) */

PME_Information PME_setInformationWsAfterProducer(PME_Information arg, PME_OptLayout wsAfterProducer)
{
  if (PME_isInformationInformation(arg)) {
    return (PME_Information)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterProducer, 9), 1);
  }

  ATabort("Information has no WsAfterProducer: %t\n", arg);
  return (PME_Information)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasInformationWsAfterC2(PME_Information arg) */

ATbool PME_hasInformationWsAfterC2(PME_Information arg)
{
  if (PME_isInformationInformation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getInformationWsAfterC2(PME_Information arg) */

PME_OptLayout PME_getInformationWsAfterC2(PME_Information arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 11);
}

/*}}}  */
/*{{{  PME_Information PME_setInformationWsAfterC2(PME_Information arg, PME_OptLayout wsAfterC2) */

PME_Information PME_setInformationWsAfterC2(PME_Information arg, PME_OptLayout wsAfterC2)
{
  if (PME_isInformationInformation(arg)) {
    return (PME_Information)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterC2, 11), 1);
  }

  ATabort("Information has no WsAfterC2: %t\n", arg);
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
  
    return (PME_Description)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 12);
}

/*}}}  */
/*{{{  PME_Information PME_setInformationDescription(PME_Information arg, PME_Description description) */

PME_Information PME_setInformationDescription(PME_Information arg, PME_Description description)
{
  if (PME_isInformationInformation(arg)) {
    return (PME_Information)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)description, 12), 1);
  }

  ATabort("Information has no Description: %t\n", arg);
  return (PME_Information)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasInformationWsAfterDescription(PME_Information arg) */

ATbool PME_hasInformationWsAfterDescription(PME_Information arg)
{
  if (PME_isInformationInformation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getInformationWsAfterDescription(PME_Information arg) */

PME_OptLayout PME_getInformationWsAfterDescription(PME_Information arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 13);
}

/*}}}  */
/*{{{  PME_Information PME_setInformationWsAfterDescription(PME_Information arg, PME_OptLayout wsAfterDescription) */

PME_Information PME_setInformationWsAfterDescription(PME_Information arg, PME_OptLayout wsAfterDescription)
{
  if (PME_isInformationInformation(arg)) {
    return (PME_Information)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterDescription, 13), 1);
  }

  ATabort("Information has no WsAfterDescription: %t\n", arg);
  return (PME_Information)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasInformationWsAfterC3(PME_Information arg) */

ATbool PME_hasInformationWsAfterC3(PME_Information arg)
{
  if (PME_isInformationInformation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getInformationWsAfterC3(PME_Information arg) */

PME_OptLayout PME_getInformationWsAfterC3(PME_Information arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 15);
}

/*}}}  */
/*{{{  PME_Information PME_setInformationWsAfterC3(PME_Information arg, PME_OptLayout wsAfterC3) */

PME_Information PME_setInformationWsAfterC3(PME_Information arg, PME_OptLayout wsAfterC3)
{
  if (PME_isInformationInformation(arg)) {
    return (PME_Information)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterC3, 15), 1);
  }

  ATabort("Information has no WsAfterC3: %t\n", arg);
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
  
    return (PME_Subjects)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 16);
}

/*}}}  */
/*{{{  PME_Information PME_setInformationSubjects(PME_Information arg, PME_Subjects subjects) */

PME_Information PME_setInformationSubjects(PME_Information arg, PME_Subjects subjects)
{
  if (PME_isInformationInformation(arg)) {
    return (PME_Information)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)subjects, 16), 1);
  }

  ATabort("Information has no Subjects: %t\n", arg);
  return (PME_Information)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasInformationWsAfterSubjects(PME_Information arg) */

ATbool PME_hasInformationWsAfterSubjects(PME_Information arg)
{
  if (PME_isInformationInformation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getInformationWsAfterSubjects(PME_Information arg) */

PME_OptLayout PME_getInformationWsAfterSubjects(PME_Information arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 17);
}

/*}}}  */
/*{{{  PME_Information PME_setInformationWsAfterSubjects(PME_Information arg, PME_OptLayout wsAfterSubjects) */

PME_Information PME_setInformationWsAfterSubjects(PME_Information arg, PME_OptLayout wsAfterSubjects)
{
  if (PME_isInformationInformation(arg)) {
    return (PME_Information)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterSubjects, 17), 1);
  }

  ATabort("Information has no WsAfterSubjects: %t\n", arg);
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
  assert(ATmatchTerm((ATerm)arg, PME_patternWarningWarning, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PME_hasWarningWsAfterWarning(PME_Warning arg) */

ATbool PME_hasWarningWsAfterWarning(PME_Warning arg)
{
  if (PME_isWarningWarning(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getWarningWsAfterWarning(PME_Warning arg) */

PME_OptLayout PME_getWarningWsAfterWarning(PME_Warning arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PME_Warning PME_setWarningWsAfterWarning(PME_Warning arg, PME_OptLayout wsAfterWarning) */

PME_Warning PME_setWarningWsAfterWarning(PME_Warning arg, PME_OptLayout wsAfterWarning)
{
  if (PME_isWarningWarning(arg)) {
    return (PME_Warning)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterWarning, 1), 1);
  }

  ATabort("Warning has no WsAfterWarning: %t\n", arg);
  return (PME_Warning)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasWarningWsAfterParenOpen(PME_Warning arg) */

ATbool PME_hasWarningWsAfterParenOpen(PME_Warning arg)
{
  if (PME_isWarningWarning(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getWarningWsAfterParenOpen(PME_Warning arg) */

PME_OptLayout PME_getWarningWsAfterParenOpen(PME_Warning arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  PME_Warning PME_setWarningWsAfterParenOpen(PME_Warning arg, PME_OptLayout wsAfterParenOpen) */

PME_Warning PME_setWarningWsAfterParenOpen(PME_Warning arg, PME_OptLayout wsAfterParenOpen)
{
  if (PME_isWarningWarning(arg)) {
    return (PME_Warning)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenOpen, 3), 1);
  }

  ATabort("Warning has no WsAfterParenOpen: %t\n", arg);
  return (PME_Warning)NULL;
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
  
    return (PME_String)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PME_Warning PME_setWarningId(PME_Warning arg, PME_String id) */

PME_Warning PME_setWarningId(PME_Warning arg, PME_String id)
{
  if (PME_isWarningWarning(arg)) {
    return (PME_Warning)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)id, 4), 1);
  }

  ATabort("Warning has no Id: %t\n", arg);
  return (PME_Warning)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasWarningWsAfterId(PME_Warning arg) */

ATbool PME_hasWarningWsAfterId(PME_Warning arg)
{
  if (PME_isWarningWarning(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getWarningWsAfterId(PME_Warning arg) */

PME_OptLayout PME_getWarningWsAfterId(PME_Warning arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PME_Warning PME_setWarningWsAfterId(PME_Warning arg, PME_OptLayout wsAfterId) */

PME_Warning PME_setWarningWsAfterId(PME_Warning arg, PME_OptLayout wsAfterId)
{
  if (PME_isWarningWarning(arg)) {
    return (PME_Warning)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterId, 5), 1);
  }

  ATabort("Warning has no WsAfterId: %t\n", arg);
  return (PME_Warning)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasWarningWsAfterC1(PME_Warning arg) */

ATbool PME_hasWarningWsAfterC1(PME_Warning arg)
{
  if (PME_isWarningWarning(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getWarningWsAfterC1(PME_Warning arg) */

PME_OptLayout PME_getWarningWsAfterC1(PME_Warning arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  PME_Warning PME_setWarningWsAfterC1(PME_Warning arg, PME_OptLayout wsAfterC1) */

PME_Warning PME_setWarningWsAfterC1(PME_Warning arg, PME_OptLayout wsAfterC1)
{
  if (PME_isWarningWarning(arg)) {
    return (PME_Warning)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterC1, 7), 1);
  }

  ATabort("Warning has no WsAfterC1: %t\n", arg);
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
  
    return (PME_Producer)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/*}}}  */
/*{{{  PME_Warning PME_setWarningProducer(PME_Warning arg, PME_Producer producer) */

PME_Warning PME_setWarningProducer(PME_Warning arg, PME_Producer producer)
{
  if (PME_isWarningWarning(arg)) {
    return (PME_Warning)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)producer, 8), 1);
  }

  ATabort("Warning has no Producer: %t\n", arg);
  return (PME_Warning)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasWarningWsAfterProducer(PME_Warning arg) */

ATbool PME_hasWarningWsAfterProducer(PME_Warning arg)
{
  if (PME_isWarningWarning(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getWarningWsAfterProducer(PME_Warning arg) */

PME_OptLayout PME_getWarningWsAfterProducer(PME_Warning arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/*}}}  */
/*{{{  PME_Warning PME_setWarningWsAfterProducer(PME_Warning arg, PME_OptLayout wsAfterProducer) */

PME_Warning PME_setWarningWsAfterProducer(PME_Warning arg, PME_OptLayout wsAfterProducer)
{
  if (PME_isWarningWarning(arg)) {
    return (PME_Warning)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterProducer, 9), 1);
  }

  ATabort("Warning has no WsAfterProducer: %t\n", arg);
  return (PME_Warning)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasWarningWsAfterC2(PME_Warning arg) */

ATbool PME_hasWarningWsAfterC2(PME_Warning arg)
{
  if (PME_isWarningWarning(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getWarningWsAfterC2(PME_Warning arg) */

PME_OptLayout PME_getWarningWsAfterC2(PME_Warning arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 11);
}

/*}}}  */
/*{{{  PME_Warning PME_setWarningWsAfterC2(PME_Warning arg, PME_OptLayout wsAfterC2) */

PME_Warning PME_setWarningWsAfterC2(PME_Warning arg, PME_OptLayout wsAfterC2)
{
  if (PME_isWarningWarning(arg)) {
    return (PME_Warning)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterC2, 11), 1);
  }

  ATabort("Warning has no WsAfterC2: %t\n", arg);
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
  
    return (PME_Description)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 12);
}

/*}}}  */
/*{{{  PME_Warning PME_setWarningDescription(PME_Warning arg, PME_Description description) */

PME_Warning PME_setWarningDescription(PME_Warning arg, PME_Description description)
{
  if (PME_isWarningWarning(arg)) {
    return (PME_Warning)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)description, 12), 1);
  }

  ATabort("Warning has no Description: %t\n", arg);
  return (PME_Warning)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasWarningWsAfterDescription(PME_Warning arg) */

ATbool PME_hasWarningWsAfterDescription(PME_Warning arg)
{
  if (PME_isWarningWarning(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getWarningWsAfterDescription(PME_Warning arg) */

PME_OptLayout PME_getWarningWsAfterDescription(PME_Warning arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 13);
}

/*}}}  */
/*{{{  PME_Warning PME_setWarningWsAfterDescription(PME_Warning arg, PME_OptLayout wsAfterDescription) */

PME_Warning PME_setWarningWsAfterDescription(PME_Warning arg, PME_OptLayout wsAfterDescription)
{
  if (PME_isWarningWarning(arg)) {
    return (PME_Warning)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterDescription, 13), 1);
  }

  ATabort("Warning has no WsAfterDescription: %t\n", arg);
  return (PME_Warning)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasWarningWsAfterC3(PME_Warning arg) */

ATbool PME_hasWarningWsAfterC3(PME_Warning arg)
{
  if (PME_isWarningWarning(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getWarningWsAfterC3(PME_Warning arg) */

PME_OptLayout PME_getWarningWsAfterC3(PME_Warning arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 15);
}

/*}}}  */
/*{{{  PME_Warning PME_setWarningWsAfterC3(PME_Warning arg, PME_OptLayout wsAfterC3) */

PME_Warning PME_setWarningWsAfterC3(PME_Warning arg, PME_OptLayout wsAfterC3)
{
  if (PME_isWarningWarning(arg)) {
    return (PME_Warning)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterC3, 15), 1);
  }

  ATabort("Warning has no WsAfterC3: %t\n", arg);
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
  
    return (PME_Subjects)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 16);
}

/*}}}  */
/*{{{  PME_Warning PME_setWarningSubjects(PME_Warning arg, PME_Subjects subjects) */

PME_Warning PME_setWarningSubjects(PME_Warning arg, PME_Subjects subjects)
{
  if (PME_isWarningWarning(arg)) {
    return (PME_Warning)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)subjects, 16), 1);
  }

  ATabort("Warning has no Subjects: %t\n", arg);
  return (PME_Warning)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasWarningWsAfterSubjects(PME_Warning arg) */

ATbool PME_hasWarningWsAfterSubjects(PME_Warning arg)
{
  if (PME_isWarningWarning(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getWarningWsAfterSubjects(PME_Warning arg) */

PME_OptLayout PME_getWarningWsAfterSubjects(PME_Warning arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 17);
}

/*}}}  */
/*{{{  PME_Warning PME_setWarningWsAfterSubjects(PME_Warning arg, PME_OptLayout wsAfterSubjects) */

PME_Warning PME_setWarningWsAfterSubjects(PME_Warning arg, PME_OptLayout wsAfterSubjects)
{
  if (PME_isWarningWarning(arg)) {
    return (PME_Warning)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterSubjects, 17), 1);
  }

  ATabort("Warning has no WsAfterSubjects: %t\n", arg);
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
  assert(ATmatchTerm((ATerm)arg, PME_patternErrorError, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PME_hasErrorWsAfterError(PME_Error arg) */

ATbool PME_hasErrorWsAfterError(PME_Error arg)
{
  if (PME_isErrorError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getErrorWsAfterError(PME_Error arg) */

PME_OptLayout PME_getErrorWsAfterError(PME_Error arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PME_Error PME_setErrorWsAfterError(PME_Error arg, PME_OptLayout wsAfterError) */

PME_Error PME_setErrorWsAfterError(PME_Error arg, PME_OptLayout wsAfterError)
{
  if (PME_isErrorError(arg)) {
    return (PME_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterError, 1), 1);
  }

  ATabort("Error has no WsAfterError: %t\n", arg);
  return (PME_Error)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasErrorWsAfterParenOpen(PME_Error arg) */

ATbool PME_hasErrorWsAfterParenOpen(PME_Error arg)
{
  if (PME_isErrorError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getErrorWsAfterParenOpen(PME_Error arg) */

PME_OptLayout PME_getErrorWsAfterParenOpen(PME_Error arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  PME_Error PME_setErrorWsAfterParenOpen(PME_Error arg, PME_OptLayout wsAfterParenOpen) */

PME_Error PME_setErrorWsAfterParenOpen(PME_Error arg, PME_OptLayout wsAfterParenOpen)
{
  if (PME_isErrorError(arg)) {
    return (PME_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenOpen, 3), 1);
  }

  ATabort("Error has no WsAfterParenOpen: %t\n", arg);
  return (PME_Error)NULL;
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
  
    return (PME_String)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PME_Error PME_setErrorId(PME_Error arg, PME_String id) */

PME_Error PME_setErrorId(PME_Error arg, PME_String id)
{
  if (PME_isErrorError(arg)) {
    return (PME_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)id, 4), 1);
  }

  ATabort("Error has no Id: %t\n", arg);
  return (PME_Error)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasErrorWsAfterId(PME_Error arg) */

ATbool PME_hasErrorWsAfterId(PME_Error arg)
{
  if (PME_isErrorError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getErrorWsAfterId(PME_Error arg) */

PME_OptLayout PME_getErrorWsAfterId(PME_Error arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PME_Error PME_setErrorWsAfterId(PME_Error arg, PME_OptLayout wsAfterId) */

PME_Error PME_setErrorWsAfterId(PME_Error arg, PME_OptLayout wsAfterId)
{
  if (PME_isErrorError(arg)) {
    return (PME_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterId, 5), 1);
  }

  ATabort("Error has no WsAfterId: %t\n", arg);
  return (PME_Error)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasErrorWsAfterC1(PME_Error arg) */

ATbool PME_hasErrorWsAfterC1(PME_Error arg)
{
  if (PME_isErrorError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getErrorWsAfterC1(PME_Error arg) */

PME_OptLayout PME_getErrorWsAfterC1(PME_Error arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  PME_Error PME_setErrorWsAfterC1(PME_Error arg, PME_OptLayout wsAfterC1) */

PME_Error PME_setErrorWsAfterC1(PME_Error arg, PME_OptLayout wsAfterC1)
{
  if (PME_isErrorError(arg)) {
    return (PME_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterC1, 7), 1);
  }

  ATabort("Error has no WsAfterC1: %t\n", arg);
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
  
    return (PME_Producer)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/*}}}  */
/*{{{  PME_Error PME_setErrorProducer(PME_Error arg, PME_Producer producer) */

PME_Error PME_setErrorProducer(PME_Error arg, PME_Producer producer)
{
  if (PME_isErrorError(arg)) {
    return (PME_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)producer, 8), 1);
  }

  ATabort("Error has no Producer: %t\n", arg);
  return (PME_Error)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasErrorWsAfterProducer(PME_Error arg) */

ATbool PME_hasErrorWsAfterProducer(PME_Error arg)
{
  if (PME_isErrorError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getErrorWsAfterProducer(PME_Error arg) */

PME_OptLayout PME_getErrorWsAfterProducer(PME_Error arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/*}}}  */
/*{{{  PME_Error PME_setErrorWsAfterProducer(PME_Error arg, PME_OptLayout wsAfterProducer) */

PME_Error PME_setErrorWsAfterProducer(PME_Error arg, PME_OptLayout wsAfterProducer)
{
  if (PME_isErrorError(arg)) {
    return (PME_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterProducer, 9), 1);
  }

  ATabort("Error has no WsAfterProducer: %t\n", arg);
  return (PME_Error)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasErrorWsAfterC2(PME_Error arg) */

ATbool PME_hasErrorWsAfterC2(PME_Error arg)
{
  if (PME_isErrorError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getErrorWsAfterC2(PME_Error arg) */

PME_OptLayout PME_getErrorWsAfterC2(PME_Error arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 11);
}

/*}}}  */
/*{{{  PME_Error PME_setErrorWsAfterC2(PME_Error arg, PME_OptLayout wsAfterC2) */

PME_Error PME_setErrorWsAfterC2(PME_Error arg, PME_OptLayout wsAfterC2)
{
  if (PME_isErrorError(arg)) {
    return (PME_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterC2, 11), 1);
  }

  ATabort("Error has no WsAfterC2: %t\n", arg);
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
  
    return (PME_Description)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 12);
}

/*}}}  */
/*{{{  PME_Error PME_setErrorDescription(PME_Error arg, PME_Description description) */

PME_Error PME_setErrorDescription(PME_Error arg, PME_Description description)
{
  if (PME_isErrorError(arg)) {
    return (PME_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)description, 12), 1);
  }

  ATabort("Error has no Description: %t\n", arg);
  return (PME_Error)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasErrorWsAfterDescription(PME_Error arg) */

ATbool PME_hasErrorWsAfterDescription(PME_Error arg)
{
  if (PME_isErrorError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getErrorWsAfterDescription(PME_Error arg) */

PME_OptLayout PME_getErrorWsAfterDescription(PME_Error arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 13);
}

/*}}}  */
/*{{{  PME_Error PME_setErrorWsAfterDescription(PME_Error arg, PME_OptLayout wsAfterDescription) */

PME_Error PME_setErrorWsAfterDescription(PME_Error arg, PME_OptLayout wsAfterDescription)
{
  if (PME_isErrorError(arg)) {
    return (PME_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterDescription, 13), 1);
  }

  ATabort("Error has no WsAfterDescription: %t\n", arg);
  return (PME_Error)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasErrorWsAfterC3(PME_Error arg) */

ATbool PME_hasErrorWsAfterC3(PME_Error arg)
{
  if (PME_isErrorError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getErrorWsAfterC3(PME_Error arg) */

PME_OptLayout PME_getErrorWsAfterC3(PME_Error arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 15);
}

/*}}}  */
/*{{{  PME_Error PME_setErrorWsAfterC3(PME_Error arg, PME_OptLayout wsAfterC3) */

PME_Error PME_setErrorWsAfterC3(PME_Error arg, PME_OptLayout wsAfterC3)
{
  if (PME_isErrorError(arg)) {
    return (PME_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterC3, 15), 1);
  }

  ATabort("Error has no WsAfterC3: %t\n", arg);
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
  
    return (PME_Subjects)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 16);
}

/*}}}  */
/*{{{  PME_Error PME_setErrorSubjects(PME_Error arg, PME_Subjects subjects) */

PME_Error PME_setErrorSubjects(PME_Error arg, PME_Subjects subjects)
{
  if (PME_isErrorError(arg)) {
    return (PME_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)subjects, 16), 1);
  }

  ATabort("Error has no Subjects: %t\n", arg);
  return (PME_Error)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasErrorWsAfterSubjects(PME_Error arg) */

ATbool PME_hasErrorWsAfterSubjects(PME_Error arg)
{
  if (PME_isErrorError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getErrorWsAfterSubjects(PME_Error arg) */

PME_OptLayout PME_getErrorWsAfterSubjects(PME_Error arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 17);
}

/*}}}  */
/*{{{  PME_Error PME_setErrorWsAfterSubjects(PME_Error arg, PME_OptLayout wsAfterSubjects) */

PME_Error PME_setErrorWsAfterSubjects(PME_Error arg, PME_OptLayout wsAfterSubjects)
{
  if (PME_isErrorError(arg)) {
    return (PME_Error)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterSubjects, 17), 1);
  }

  ATabort("Error has no WsAfterSubjects: %t\n", arg);
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
  assert(ATmatchTerm((ATerm)arg, PME_patternFatalErrorFatalError, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PME_hasFatalErrorWsAfterFatalError(PME_FatalError arg) */

ATbool PME_hasFatalErrorWsAfterFatalError(PME_FatalError arg)
{
  if (PME_isFatalErrorFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getFatalErrorWsAfterFatalError(PME_FatalError arg) */

PME_OptLayout PME_getFatalErrorWsAfterFatalError(PME_FatalError arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PME_FatalError PME_setFatalErrorWsAfterFatalError(PME_FatalError arg, PME_OptLayout wsAfterFatalError) */

PME_FatalError PME_setFatalErrorWsAfterFatalError(PME_FatalError arg, PME_OptLayout wsAfterFatalError)
{
  if (PME_isFatalErrorFatalError(arg)) {
    return (PME_FatalError)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterFatalError, 1), 1);
  }

  ATabort("FatalError has no WsAfterFatalError: %t\n", arg);
  return (PME_FatalError)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasFatalErrorWsAfterParenOpen(PME_FatalError arg) */

ATbool PME_hasFatalErrorWsAfterParenOpen(PME_FatalError arg)
{
  if (PME_isFatalErrorFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getFatalErrorWsAfterParenOpen(PME_FatalError arg) */

PME_OptLayout PME_getFatalErrorWsAfterParenOpen(PME_FatalError arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  PME_FatalError PME_setFatalErrorWsAfterParenOpen(PME_FatalError arg, PME_OptLayout wsAfterParenOpen) */

PME_FatalError PME_setFatalErrorWsAfterParenOpen(PME_FatalError arg, PME_OptLayout wsAfterParenOpen)
{
  if (PME_isFatalErrorFatalError(arg)) {
    return (PME_FatalError)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenOpen, 3), 1);
  }

  ATabort("FatalError has no WsAfterParenOpen: %t\n", arg);
  return (PME_FatalError)NULL;
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
  
    return (PME_String)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PME_FatalError PME_setFatalErrorId(PME_FatalError arg, PME_String id) */

PME_FatalError PME_setFatalErrorId(PME_FatalError arg, PME_String id)
{
  if (PME_isFatalErrorFatalError(arg)) {
    return (PME_FatalError)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)id, 4), 1);
  }

  ATabort("FatalError has no Id: %t\n", arg);
  return (PME_FatalError)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasFatalErrorWsAfterId(PME_FatalError arg) */

ATbool PME_hasFatalErrorWsAfterId(PME_FatalError arg)
{
  if (PME_isFatalErrorFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getFatalErrorWsAfterId(PME_FatalError arg) */

PME_OptLayout PME_getFatalErrorWsAfterId(PME_FatalError arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PME_FatalError PME_setFatalErrorWsAfterId(PME_FatalError arg, PME_OptLayout wsAfterId) */

PME_FatalError PME_setFatalErrorWsAfterId(PME_FatalError arg, PME_OptLayout wsAfterId)
{
  if (PME_isFatalErrorFatalError(arg)) {
    return (PME_FatalError)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterId, 5), 1);
  }

  ATabort("FatalError has no WsAfterId: %t\n", arg);
  return (PME_FatalError)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasFatalErrorWsAfterC1(PME_FatalError arg) */

ATbool PME_hasFatalErrorWsAfterC1(PME_FatalError arg)
{
  if (PME_isFatalErrorFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getFatalErrorWsAfterC1(PME_FatalError arg) */

PME_OptLayout PME_getFatalErrorWsAfterC1(PME_FatalError arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  PME_FatalError PME_setFatalErrorWsAfterC1(PME_FatalError arg, PME_OptLayout wsAfterC1) */

PME_FatalError PME_setFatalErrorWsAfterC1(PME_FatalError arg, PME_OptLayout wsAfterC1)
{
  if (PME_isFatalErrorFatalError(arg)) {
    return (PME_FatalError)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterC1, 7), 1);
  }

  ATabort("FatalError has no WsAfterC1: %t\n", arg);
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
  
    return (PME_Producer)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/*}}}  */
/*{{{  PME_FatalError PME_setFatalErrorProducer(PME_FatalError arg, PME_Producer producer) */

PME_FatalError PME_setFatalErrorProducer(PME_FatalError arg, PME_Producer producer)
{
  if (PME_isFatalErrorFatalError(arg)) {
    return (PME_FatalError)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)producer, 8), 1);
  }

  ATabort("FatalError has no Producer: %t\n", arg);
  return (PME_FatalError)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasFatalErrorWsAfterProducer(PME_FatalError arg) */

ATbool PME_hasFatalErrorWsAfterProducer(PME_FatalError arg)
{
  if (PME_isFatalErrorFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getFatalErrorWsAfterProducer(PME_FatalError arg) */

PME_OptLayout PME_getFatalErrorWsAfterProducer(PME_FatalError arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/*}}}  */
/*{{{  PME_FatalError PME_setFatalErrorWsAfterProducer(PME_FatalError arg, PME_OptLayout wsAfterProducer) */

PME_FatalError PME_setFatalErrorWsAfterProducer(PME_FatalError arg, PME_OptLayout wsAfterProducer)
{
  if (PME_isFatalErrorFatalError(arg)) {
    return (PME_FatalError)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterProducer, 9), 1);
  }

  ATabort("FatalError has no WsAfterProducer: %t\n", arg);
  return (PME_FatalError)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasFatalErrorWsAfterC2(PME_FatalError arg) */

ATbool PME_hasFatalErrorWsAfterC2(PME_FatalError arg)
{
  if (PME_isFatalErrorFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getFatalErrorWsAfterC2(PME_FatalError arg) */

PME_OptLayout PME_getFatalErrorWsAfterC2(PME_FatalError arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 11);
}

/*}}}  */
/*{{{  PME_FatalError PME_setFatalErrorWsAfterC2(PME_FatalError arg, PME_OptLayout wsAfterC2) */

PME_FatalError PME_setFatalErrorWsAfterC2(PME_FatalError arg, PME_OptLayout wsAfterC2)
{
  if (PME_isFatalErrorFatalError(arg)) {
    return (PME_FatalError)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterC2, 11), 1);
  }

  ATabort("FatalError has no WsAfterC2: %t\n", arg);
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
  
    return (PME_Description)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 12);
}

/*}}}  */
/*{{{  PME_FatalError PME_setFatalErrorDescription(PME_FatalError arg, PME_Description description) */

PME_FatalError PME_setFatalErrorDescription(PME_FatalError arg, PME_Description description)
{
  if (PME_isFatalErrorFatalError(arg)) {
    return (PME_FatalError)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)description, 12), 1);
  }

  ATabort("FatalError has no Description: %t\n", arg);
  return (PME_FatalError)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasFatalErrorWsAfterDescription(PME_FatalError arg) */

ATbool PME_hasFatalErrorWsAfterDescription(PME_FatalError arg)
{
  if (PME_isFatalErrorFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getFatalErrorWsAfterDescription(PME_FatalError arg) */

PME_OptLayout PME_getFatalErrorWsAfterDescription(PME_FatalError arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 13);
}

/*}}}  */
/*{{{  PME_FatalError PME_setFatalErrorWsAfterDescription(PME_FatalError arg, PME_OptLayout wsAfterDescription) */

PME_FatalError PME_setFatalErrorWsAfterDescription(PME_FatalError arg, PME_OptLayout wsAfterDescription)
{
  if (PME_isFatalErrorFatalError(arg)) {
    return (PME_FatalError)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterDescription, 13), 1);
  }

  ATabort("FatalError has no WsAfterDescription: %t\n", arg);
  return (PME_FatalError)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasFatalErrorWsAfterC3(PME_FatalError arg) */

ATbool PME_hasFatalErrorWsAfterC3(PME_FatalError arg)
{
  if (PME_isFatalErrorFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getFatalErrorWsAfterC3(PME_FatalError arg) */

PME_OptLayout PME_getFatalErrorWsAfterC3(PME_FatalError arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 15);
}

/*}}}  */
/*{{{  PME_FatalError PME_setFatalErrorWsAfterC3(PME_FatalError arg, PME_OptLayout wsAfterC3) */

PME_FatalError PME_setFatalErrorWsAfterC3(PME_FatalError arg, PME_OptLayout wsAfterC3)
{
  if (PME_isFatalErrorFatalError(arg)) {
    return (PME_FatalError)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterC3, 15), 1);
  }

  ATabort("FatalError has no WsAfterC3: %t\n", arg);
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
  
    return (PME_Subjects)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 16);
}

/*}}}  */
/*{{{  PME_FatalError PME_setFatalErrorSubjects(PME_FatalError arg, PME_Subjects subjects) */

PME_FatalError PME_setFatalErrorSubjects(PME_FatalError arg, PME_Subjects subjects)
{
  if (PME_isFatalErrorFatalError(arg)) {
    return (PME_FatalError)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)subjects, 16), 1);
  }

  ATabort("FatalError has no Subjects: %t\n", arg);
  return (PME_FatalError)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasFatalErrorWsAfterSubjects(PME_FatalError arg) */

ATbool PME_hasFatalErrorWsAfterSubjects(PME_FatalError arg)
{
  if (PME_isFatalErrorFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getFatalErrorWsAfterSubjects(PME_FatalError arg) */

PME_OptLayout PME_getFatalErrorWsAfterSubjects(PME_FatalError arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 17);
}

/*}}}  */
/*{{{  PME_FatalError PME_setFatalErrorWsAfterSubjects(PME_FatalError arg, PME_OptLayout wsAfterSubjects) */

PME_FatalError PME_setFatalErrorWsAfterSubjects(PME_FatalError arg, PME_OptLayout wsAfterSubjects)
{
  if (PME_isFatalErrorFatalError(arg)) {
    return (PME_FatalError)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterSubjects, 17), 1);
  }

  ATabort("FatalError has no WsAfterSubjects: %t\n", arg);
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
  assert(ATmatchTerm((ATerm)arg, PME_patternProducerProducer, NULL, NULL, NULL, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PME_hasProducerWsAfterProducer(PME_Producer arg) */

ATbool PME_hasProducerWsAfterProducer(PME_Producer arg)
{
  if (PME_isProducerProducer(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getProducerWsAfterProducer(PME_Producer arg) */

PME_OptLayout PME_getProducerWsAfterProducer(PME_Producer arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PME_Producer PME_setProducerWsAfterProducer(PME_Producer arg, PME_OptLayout wsAfterProducer) */

PME_Producer PME_setProducerWsAfterProducer(PME_Producer arg, PME_OptLayout wsAfterProducer)
{
  if (PME_isProducerProducer(arg)) {
    return (PME_Producer)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterProducer, 1), 1);
  }

  ATabort("Producer has no WsAfterProducer: %t\n", arg);
  return (PME_Producer)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasProducerWsAfterParenOpen(PME_Producer arg) */

ATbool PME_hasProducerWsAfterParenOpen(PME_Producer arg)
{
  if (PME_isProducerProducer(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getProducerWsAfterParenOpen(PME_Producer arg) */

PME_OptLayout PME_getProducerWsAfterParenOpen(PME_Producer arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  PME_Producer PME_setProducerWsAfterParenOpen(PME_Producer arg, PME_OptLayout wsAfterParenOpen) */

PME_Producer PME_setProducerWsAfterParenOpen(PME_Producer arg, PME_OptLayout wsAfterParenOpen)
{
  if (PME_isProducerProducer(arg)) {
    return (PME_Producer)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenOpen, 3), 1);
  }

  ATabort("Producer has no WsAfterParenOpen: %t\n", arg);
  return (PME_Producer)NULL;
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
  
    return (PME_String)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PME_Producer PME_setProducerId(PME_Producer arg, PME_String id) */

PME_Producer PME_setProducerId(PME_Producer arg, PME_String id)
{
  if (PME_isProducerProducer(arg)) {
    return (PME_Producer)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)id, 4), 1);
  }

  ATabort("Producer has no Id: %t\n", arg);
  return (PME_Producer)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasProducerWsAfterId(PME_Producer arg) */

ATbool PME_hasProducerWsAfterId(PME_Producer arg)
{
  if (PME_isProducerProducer(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getProducerWsAfterId(PME_Producer arg) */

PME_OptLayout PME_getProducerWsAfterId(PME_Producer arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PME_Producer PME_setProducerWsAfterId(PME_Producer arg, PME_OptLayout wsAfterId) */

PME_Producer PME_setProducerWsAfterId(PME_Producer arg, PME_OptLayout wsAfterId)
{
  if (PME_isProducerProducer(arg)) {
    return (PME_Producer)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterId, 5), 1);
  }

  ATabort("Producer has no WsAfterId: %t\n", arg);
  return (PME_Producer)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasProducerWsAfterComma(PME_Producer arg) */

ATbool PME_hasProducerWsAfterComma(PME_Producer arg)
{
  if (PME_isProducerProducer(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getProducerWsAfterComma(PME_Producer arg) */

PME_OptLayout PME_getProducerWsAfterComma(PME_Producer arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  PME_Producer PME_setProducerWsAfterComma(PME_Producer arg, PME_OptLayout wsAfterComma) */

PME_Producer PME_setProducerWsAfterComma(PME_Producer arg, PME_OptLayout wsAfterComma)
{
  if (PME_isProducerProducer(arg)) {
    return (PME_Producer)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterComma, 7), 1);
  }

  ATabort("Producer has no WsAfterComma: %t\n", arg);
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
  
    return (PME_String)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/*}}}  */
/*{{{  PME_Producer PME_setProducerType(PME_Producer arg, PME_String type) */

PME_Producer PME_setProducerType(PME_Producer arg, PME_String type)
{
  if (PME_isProducerProducer(arg)) {
    return (PME_Producer)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)type, 8), 1);
  }

  ATabort("Producer has no Type: %t\n", arg);
  return (PME_Producer)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasProducerWsAfterType(PME_Producer arg) */

ATbool PME_hasProducerWsAfterType(PME_Producer arg)
{
  if (PME_isProducerProducer(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getProducerWsAfterType(PME_Producer arg) */

PME_OptLayout PME_getProducerWsAfterType(PME_Producer arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 9);
}

/*}}}  */
/*{{{  PME_Producer PME_setProducerWsAfterType(PME_Producer arg, PME_OptLayout wsAfterType) */

PME_Producer PME_setProducerWsAfterType(PME_Producer arg, PME_OptLayout wsAfterType)
{
  if (PME_isProducerProducer(arg)) {
    return (PME_Producer)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterType, 9), 1);
  }

  ATabort("Producer has no WsAfterType: %t\n", arg);
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
  assert(ATmatchTerm((ATerm)arg, PME_patternDescriptionDescription, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PME_hasDescriptionWsAfterDescription(PME_Description arg) */

ATbool PME_hasDescriptionWsAfterDescription(PME_Description arg)
{
  if (PME_isDescriptionDescription(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getDescriptionWsAfterDescription(PME_Description arg) */

PME_OptLayout PME_getDescriptionWsAfterDescription(PME_Description arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PME_Description PME_setDescriptionWsAfterDescription(PME_Description arg, PME_OptLayout wsAfterDescription) */

PME_Description PME_setDescriptionWsAfterDescription(PME_Description arg, PME_OptLayout wsAfterDescription)
{
  if (PME_isDescriptionDescription(arg)) {
    return (PME_Description)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterDescription, 1), 1);
  }

  ATabort("Description has no WsAfterDescription: %t\n", arg);
  return (PME_Description)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasDescriptionWsAfterParenOpen(PME_Description arg) */

ATbool PME_hasDescriptionWsAfterParenOpen(PME_Description arg)
{
  if (PME_isDescriptionDescription(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getDescriptionWsAfterParenOpen(PME_Description arg) */

PME_OptLayout PME_getDescriptionWsAfterParenOpen(PME_Description arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  PME_Description PME_setDescriptionWsAfterParenOpen(PME_Description arg, PME_OptLayout wsAfterParenOpen) */

PME_Description PME_setDescriptionWsAfterParenOpen(PME_Description arg, PME_OptLayout wsAfterParenOpen)
{
  if (PME_isDescriptionDescription(arg)) {
    return (PME_Description)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenOpen, 3), 1);
  }

  ATabort("Description has no WsAfterParenOpen: %t\n", arg);
  return (PME_Description)NULL;
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
  
    return (PME_String)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PME_Description PME_setDescriptionString(PME_Description arg, PME_String String) */

PME_Description PME_setDescriptionString(PME_Description arg, PME_String String)
{
  if (PME_isDescriptionDescription(arg)) {
    return (PME_Description)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)String, 4), 1);
  }

  ATabort("Description has no String: %t\n", arg);
  return (PME_Description)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasDescriptionWsAfterString(PME_Description arg) */

ATbool PME_hasDescriptionWsAfterString(PME_Description arg)
{
  if (PME_isDescriptionDescription(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getDescriptionWsAfterString(PME_Description arg) */

PME_OptLayout PME_getDescriptionWsAfterString(PME_Description arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PME_Description PME_setDescriptionWsAfterString(PME_Description arg, PME_OptLayout wsAfterString) */

PME_Description PME_setDescriptionWsAfterString(PME_Description arg, PME_OptLayout wsAfterString)
{
  if (PME_isDescriptionDescription(arg)) {
    return (PME_Description)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterString, 5), 1);
  }

  ATabort("Description has no WsAfterString: %t\n", arg);
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
  assert(ATmatchTerm((ATerm)arg, PME_patternSubjectsSubjects, NULL, NULL, NULL));
#endif
  return ATtrue;
}

/*}}}  */
/*{{{  ATbool PME_hasSubjectsWsAfterBracketOpen(PME_Subjects arg) */

ATbool PME_hasSubjectsWsAfterBracketOpen(PME_Subjects arg)
{
  if (PME_isSubjectsSubjects(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getSubjectsWsAfterBracketOpen(PME_Subjects arg) */

PME_OptLayout PME_getSubjectsWsAfterBracketOpen(PME_Subjects arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PME_Subjects PME_setSubjectsWsAfterBracketOpen(PME_Subjects arg, PME_OptLayout wsAfterBracketOpen) */

PME_Subjects PME_setSubjectsWsAfterBracketOpen(PME_Subjects arg, PME_OptLayout wsAfterBracketOpen)
{
  if (PME_isSubjectsSubjects(arg)) {
    return (PME_Subjects)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterBracketOpen, 1), 1);
  }

  ATabort("Subjects has no WsAfterBracketOpen: %t\n", arg);
  return (PME_Subjects)NULL;
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
  
    return (PME_SubjectSubjectList)ATgetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), 1);
}

/*}}}  */
/*{{{  PME_Subjects PME_setSubjectsSubjectList(PME_Subjects arg, PME_SubjectSubjectList subjectList) */

PME_Subjects PME_setSubjectsSubjectList(PME_Subjects arg, PME_SubjectSubjectList subjectList)
{
  if (PME_isSubjectsSubjects(arg)) {
    return (PME_Subjects)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 2), (ATerm)subjectList, 1), 2), 1);
  }

  ATabort("Subjects has no SubjectList: %t\n", arg);
  return (PME_Subjects)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasSubjectsWsAfterSubjectList(PME_Subjects arg) */

ATbool PME_hasSubjectsWsAfterSubjectList(PME_Subjects arg)
{
  if (PME_isSubjectsSubjects(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getSubjectsWsAfterSubjectList(PME_Subjects arg) */

PME_OptLayout PME_getSubjectsWsAfterSubjectList(PME_Subjects arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  PME_Subjects PME_setSubjectsWsAfterSubjectList(PME_Subjects arg, PME_OptLayout wsAfterSubjectList) */

PME_Subjects PME_setSubjectsWsAfterSubjectList(PME_Subjects arg, PME_OptLayout wsAfterSubjectList)
{
  if (PME_isSubjectsSubjects(arg)) {
    return (PME_Subjects)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterSubjectList, 3), 1);
  }

  ATabort("Subjects has no WsAfterSubjectList: %t\n", arg);
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
  else if (PME_isSubjectSubjectListSingle(arg)) {
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
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PME_patternSubjectSubjectListMany, NULL, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
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
/*{{{  inline ATbool PME_isSubjectSubjectListSingle(PME_SubjectSubjectList arg) */

inline ATbool PME_isSubjectSubjectListSingle(PME_SubjectSubjectList arg)
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
      last_result = ATmatchTerm((ATerm)arg, PME_patternSubjectSubjectListSingle, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PME_hasSubjectSubjectListHead(PME_SubjectSubjectList arg) */

ATbool PME_hasSubjectSubjectListHead(PME_SubjectSubjectList arg)
{
  if (PME_isSubjectSubjectListMany(arg)) {
    return ATtrue;
  }
  else if (PME_isSubjectSubjectListSingle(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_Subject PME_getSubjectSubjectListHead(PME_SubjectSubjectList arg) */

PME_Subject PME_getSubjectSubjectListHead(PME_SubjectSubjectList arg)
{
  if (PME_isSubjectSubjectListMany(arg)) {
    return (PME_Subject)ATgetFirst((ATermList)arg);
  }
  else 
    return (PME_Subject)ATgetFirst((ATermList)arg);
}

/*}}}  */
/*{{{  PME_SubjectSubjectList PME_setSubjectSubjectListHead(PME_SubjectSubjectList arg, PME_Subject head) */

PME_SubjectSubjectList PME_setSubjectSubjectListHead(PME_SubjectSubjectList arg, PME_Subject head)
{
  if (PME_isSubjectSubjectListMany(arg)) {
    return (PME_SubjectSubjectList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }
  else if (PME_isSubjectSubjectListSingle(arg)) {
    return (PME_SubjectSubjectList)ATreplace((ATermList)arg, (ATerm)head, 0);
  }

  ATabort("SubjectSubjectList has no Head: %t\n", arg);
  return (PME_SubjectSubjectList)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasSubjectSubjectListWsAfterFirst(PME_SubjectSubjectList arg) */

ATbool PME_hasSubjectSubjectListWsAfterFirst(PME_SubjectSubjectList arg)
{
  if (PME_isSubjectSubjectListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getSubjectSubjectListWsAfterFirst(PME_SubjectSubjectList arg) */

PME_OptLayout PME_getSubjectSubjectListWsAfterFirst(PME_SubjectSubjectList arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)arg, 1);
}

/*}}}  */
/*{{{  PME_SubjectSubjectList PME_setSubjectSubjectListWsAfterFirst(PME_SubjectSubjectList arg, PME_OptLayout wsAfterFirst) */

PME_SubjectSubjectList PME_setSubjectSubjectListWsAfterFirst(PME_SubjectSubjectList arg, PME_OptLayout wsAfterFirst)
{
  if (PME_isSubjectSubjectListMany(arg)) {
    return (PME_SubjectSubjectList)ATreplace((ATermList)arg, (ATerm)wsAfterFirst, 1);
  }

  ATabort("SubjectSubjectList has no WsAfterFirst: %t\n", arg);
  return (PME_SubjectSubjectList)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasSubjectSubjectListSep(PME_SubjectSubjectList arg) */

ATbool PME_hasSubjectSubjectListSep(PME_SubjectSubjectList arg)
{
  if (PME_isSubjectSubjectListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  char* PME_getSubjectSubjectListSep(PME_SubjectSubjectList arg) */

char* PME_getSubjectSubjectListSep(PME_SubjectSubjectList arg)
{
  
    return (char*)ATgetName(ATgetAFun((ATermAppl)ATgetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), 0)));
}

/*}}}  */
/*{{{  PME_SubjectSubjectList PME_setSubjectSubjectListSep(PME_SubjectSubjectList arg, char* sep) */

PME_SubjectSubjectList PME_setSubjectSubjectListSep(PME_SubjectSubjectList arg, char* sep)
{
  if (PME_isSubjectSubjectListMany(arg)) {
    return (PME_SubjectSubjectList)ATreplace((ATermList)arg, (ATerm)ATsetArgument((ATermAppl)ATelementAt((ATermList)arg, 2), (ATerm)ATmakeAppl0(ATmakeAFun(sep, 0, ATtrue)), 0), 2);
  }

  ATabort("SubjectSubjectList has no Sep: %t\n", arg);
  return (PME_SubjectSubjectList)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasSubjectSubjectListWsAfterSep(PME_SubjectSubjectList arg) */

ATbool PME_hasSubjectSubjectListWsAfterSep(PME_SubjectSubjectList arg)
{
  if (PME_isSubjectSubjectListMany(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getSubjectSubjectListWsAfterSep(PME_SubjectSubjectList arg) */

PME_OptLayout PME_getSubjectSubjectListWsAfterSep(PME_SubjectSubjectList arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)arg, 3);
}

/*}}}  */
/*{{{  PME_SubjectSubjectList PME_setSubjectSubjectListWsAfterSep(PME_SubjectSubjectList arg, PME_OptLayout wsAfterSep) */

PME_SubjectSubjectList PME_setSubjectSubjectListWsAfterSep(PME_SubjectSubjectList arg, PME_OptLayout wsAfterSep)
{
  if (PME_isSubjectSubjectListMany(arg)) {
    return (PME_SubjectSubjectList)ATreplace((ATermList)arg, (ATerm)wsAfterSep, 3);
  }

  ATabort("SubjectSubjectList has no WsAfterSep: %t\n", arg);
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
  
    return (PME_SubjectSubjectList)ATgetTail((ATermList)arg, 4);
}

/*}}}  */
/*{{{  PME_SubjectSubjectList PME_setSubjectSubjectListTail(PME_SubjectSubjectList arg, PME_SubjectSubjectList tail) */

PME_SubjectSubjectList PME_setSubjectSubjectListTail(PME_SubjectSubjectList arg, PME_SubjectSubjectList tail)
{
  if (PME_isSubjectSubjectListMany(arg)) {
    return (PME_SubjectSubjectList)ATreplaceTail((ATermList)arg, (ATermList)tail, 4);
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
      last_result = ATmatchTerm((ATerm)arg, PME_patternSubjectWithoutLocation, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
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
      last_result = ATmatchTerm((ATerm)arg, PME_patternSubjectWithLocation, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  ATbool PME_hasSubjectWsAfterSubject(PME_Subject arg) */

ATbool PME_hasSubjectWsAfterSubject(PME_Subject arg)
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
/*{{{  PME_OptLayout PME_getSubjectWsAfterSubject(PME_Subject arg) */

PME_OptLayout PME_getSubjectWsAfterSubject(PME_Subject arg)
{
  if (PME_isSubjectWithoutLocation(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
  }
  else 
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 1);
}

/*}}}  */
/*{{{  PME_Subject PME_setSubjectWsAfterSubject(PME_Subject arg, PME_OptLayout wsAfterSubject) */

PME_Subject PME_setSubjectWsAfterSubject(PME_Subject arg, PME_OptLayout wsAfterSubject)
{
  if (PME_isSubjectWithoutLocation(arg)) {
    return (PME_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterSubject, 1), 1);
  }
  else if (PME_isSubjectWithLocation(arg)) {
    return (PME_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterSubject, 1), 1);
  }

  ATabort("Subject has no WsAfterSubject: %t\n", arg);
  return (PME_Subject)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasSubjectWsAfterParenOpen(PME_Subject arg) */

ATbool PME_hasSubjectWsAfterParenOpen(PME_Subject arg)
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
/*{{{  PME_OptLayout PME_getSubjectWsAfterParenOpen(PME_Subject arg) */

PME_OptLayout PME_getSubjectWsAfterParenOpen(PME_Subject arg)
{
  if (PME_isSubjectWithoutLocation(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
  }
  else 
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 3);
}

/*}}}  */
/*{{{  PME_Subject PME_setSubjectWsAfterParenOpen(PME_Subject arg, PME_OptLayout wsAfterParenOpen) */

PME_Subject PME_setSubjectWsAfterParenOpen(PME_Subject arg, PME_OptLayout wsAfterParenOpen)
{
  if (PME_isSubjectWithoutLocation(arg)) {
    return (PME_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenOpen, 3), 1);
  }
  else if (PME_isSubjectWithLocation(arg)) {
    return (PME_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenOpen, 3), 1);
  }

  ATabort("Subject has no WsAfterParenOpen: %t\n", arg);
  return (PME_Subject)NULL;
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
    return (PME_String)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
  }
  else 
    return (PME_String)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PME_Subject PME_setSubjectId(PME_Subject arg, PME_String id) */

PME_Subject PME_setSubjectId(PME_Subject arg, PME_String id)
{
  if (PME_isSubjectWithoutLocation(arg)) {
    return (PME_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)id, 4), 1);
  }
  else if (PME_isSubjectWithLocation(arg)) {
    return (PME_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)id, 4), 1);
  }

  ATabort("Subject has no Id: %t\n", arg);
  return (PME_Subject)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasSubjectWsAfterId(PME_Subject arg) */

ATbool PME_hasSubjectWsAfterId(PME_Subject arg)
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
/*{{{  PME_OptLayout PME_getSubjectWsAfterId(PME_Subject arg) */

PME_OptLayout PME_getSubjectWsAfterId(PME_Subject arg)
{
  if (PME_isSubjectWithoutLocation(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
  }
  else 
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PME_Subject PME_setSubjectWsAfterId(PME_Subject arg, PME_OptLayout wsAfterId) */

PME_Subject PME_setSubjectWsAfterId(PME_Subject arg, PME_OptLayout wsAfterId)
{
  if (PME_isSubjectWithoutLocation(arg)) {
    return (PME_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterId, 5), 1);
  }
  else if (PME_isSubjectWithLocation(arg)) {
    return (PME_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterId, 5), 1);
  }

  ATabort("Subject has no WsAfterId: %t\n", arg);
  return (PME_Subject)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasSubjectWsAfterComma(PME_Subject arg) */

ATbool PME_hasSubjectWsAfterComma(PME_Subject arg)
{
  if (PME_isSubjectWithoutLocation(arg)) {
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
  if (PME_isSubjectWithoutLocation(arg)) {
    return (PME_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterComma, 7), 1);
  }

  ATabort("Subject has no WsAfterComma: %t\n", arg);
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
  
    return (PME_Location)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 8);
}

/*}}}  */
/*{{{  PME_Subject PME_setSubjectLocation(PME_Subject arg, PME_Location location) */

PME_Subject PME_setSubjectLocation(PME_Subject arg, PME_Location location)
{
  if (PME_isSubjectWithoutLocation(arg)) {
    return (PME_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)location, 8), 1);
  }

  ATabort("Subject has no Location: %t\n", arg);
  return (PME_Subject)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasSubjectWsAfterLocation(PME_Subject arg) */

ATbool PME_hasSubjectWsAfterLocation(PME_Subject arg)
{
  if (PME_isSubjectWithoutLocation(arg)) {
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
  if (PME_isSubjectWithoutLocation(arg)) {
    return (PME_Subject)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLocation, 9), 1);
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
    return (PME_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterLocation, 1), 1);
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
    return (PME_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenOpen, 3), 1);
  }

  ATabort("Location has no WsAfterParenOpen: %t\n", arg);
  return (PME_Location)NULL;
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
  
    return (PME_String)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 4);
}

/*}}}  */
/*{{{  PME_Location PME_setLocationFile(PME_Location arg, PME_String file) */

PME_Location PME_setLocationFile(PME_Location arg, PME_String file)
{
  if (PME_isLocationLocation(arg)) {
    return (PME_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)file, 4), 1);
  }

  ATabort("Location has no File: %t\n", arg);
  return (PME_Location)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasLocationWsAfterFile(PME_Location arg) */

ATbool PME_hasLocationWsAfterFile(PME_Location arg)
{
  if (PME_isLocationLocation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getLocationWsAfterFile(PME_Location arg) */

PME_OptLayout PME_getLocationWsAfterFile(PME_Location arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 5);
}

/*}}}  */
/*{{{  PME_Location PME_setLocationWsAfterFile(PME_Location arg, PME_OptLayout wsAfterFile) */

PME_Location PME_setLocationWsAfterFile(PME_Location arg, PME_OptLayout wsAfterFile)
{
  if (PME_isLocationLocation(arg)) {
    return (PME_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterFile, 5), 1);
  }

  ATabort("Location has no WsAfterFile: %t\n", arg);
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
    return (PME_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterComma, 7), 1);
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
/*{{{  PME_Location PME_setLocationArea(PME_Location arg, PME_Area area) */

PME_Location PME_setLocationArea(PME_Location arg, PME_Area area)
{
  if (PME_isLocationLocation(arg)) {
    return (PME_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)area, 8), 1);
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
    return (PME_Location)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterArea, 9), 1);
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
  return ATfalse;
}

/*}}}  */
/*{{{  inline ATbool PME_isAreaArea(PME_Area arg) */

inline ATbool PME_isAreaArea(PME_Area arg)
{
#ifndef DISABLE_DYNAMIC_CHECKING
  assert(arg != NULL);
  assert(ATmatchTerm((ATerm)arg, PME_patternAreaArea, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL));
#endif
  return ATtrue;
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
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterArea, 1), 1);
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
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterParenOpen, 3), 1);
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
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)startLine, 4), 1);
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
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterStartLine, 5), 1);
  }

  ATabort("Area has no WsAfterStartLine: %t\n", arg);
  return (PME_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasAreaWsAfterC1(PME_Area arg) */

ATbool PME_hasAreaWsAfterC1(PME_Area arg)
{
  if (PME_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getAreaWsAfterC1(PME_Area arg) */

PME_OptLayout PME_getAreaWsAfterC1(PME_Area arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 7);
}

/*}}}  */
/*{{{  PME_Area PME_setAreaWsAfterC1(PME_Area arg, PME_OptLayout wsAfterC1) */

PME_Area PME_setAreaWsAfterC1(PME_Area arg, PME_OptLayout wsAfterC1)
{
  if (PME_isAreaArea(arg)) {
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterC1, 7), 1);
  }

  ATabort("Area has no WsAfterC1: %t\n", arg);
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
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)startColumn, 8), 1);
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
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterStartColumn, 9), 1);
  }

  ATabort("Area has no WsAfterStartColumn: %t\n", arg);
  return (PME_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasAreaWsAfterC2(PME_Area arg) */

ATbool PME_hasAreaWsAfterC2(PME_Area arg)
{
  if (PME_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getAreaWsAfterC2(PME_Area arg) */

PME_OptLayout PME_getAreaWsAfterC2(PME_Area arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 11);
}

/*}}}  */
/*{{{  PME_Area PME_setAreaWsAfterC2(PME_Area arg, PME_OptLayout wsAfterC2) */

PME_Area PME_setAreaWsAfterC2(PME_Area arg, PME_OptLayout wsAfterC2)
{
  if (PME_isAreaArea(arg)) {
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterC2, 11), 1);
  }

  ATabort("Area has no WsAfterC2: %t\n", arg);
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
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)endLine, 12), 1);
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
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterEndLine, 13), 1);
  }

  ATabort("Area has no WsAfterEndLine: %t\n", arg);
  return (PME_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasAreaWsAfterC3(PME_Area arg) */

ATbool PME_hasAreaWsAfterC3(PME_Area arg)
{
  if (PME_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getAreaWsAfterC3(PME_Area arg) */

PME_OptLayout PME_getAreaWsAfterC3(PME_Area arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 15);
}

/*}}}  */
/*{{{  PME_Area PME_setAreaWsAfterC3(PME_Area arg, PME_OptLayout wsAfterC3) */

PME_Area PME_setAreaWsAfterC3(PME_Area arg, PME_OptLayout wsAfterC3)
{
  if (PME_isAreaArea(arg)) {
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterC3, 15), 1);
  }

  ATabort("Area has no WsAfterC3: %t\n", arg);
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
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)endColumn, 16), 1);
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
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterEndColumn, 17), 1);
  }

  ATabort("Area has no WsAfterEndColumn: %t\n", arg);
  return (PME_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasAreaWsAfterC4(PME_Area arg) */

ATbool PME_hasAreaWsAfterC4(PME_Area arg)
{
  if (PME_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getAreaWsAfterC4(PME_Area arg) */

PME_OptLayout PME_getAreaWsAfterC4(PME_Area arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 19);
}

/*}}}  */
/*{{{  PME_Area PME_setAreaWsAfterC4(PME_Area arg, PME_OptLayout wsAfterC4) */

PME_Area PME_setAreaWsAfterC4(PME_Area arg, PME_OptLayout wsAfterC4)
{
  if (PME_isAreaArea(arg)) {
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterC4, 19), 1);
  }

  ATabort("Area has no WsAfterC4: %t\n", arg);
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
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)startOffset, 20), 1);
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
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterStartOffset, 21), 1);
  }

  ATabort("Area has no WsAfterStartOffset: %t\n", arg);
  return (PME_Area)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasAreaWsAfterC5(PME_Area arg) */

ATbool PME_hasAreaWsAfterC5(PME_Area arg)
{
  if (PME_isAreaArea(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_OptLayout PME_getAreaWsAfterC5(PME_Area arg) */

PME_OptLayout PME_getAreaWsAfterC5(PME_Area arg)
{
  
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)arg, 1), 23);
}

/*}}}  */
/*{{{  PME_Area PME_setAreaWsAfterC5(PME_Area arg, PME_OptLayout wsAfterC5) */

PME_Area PME_setAreaWsAfterC5(PME_Area arg, PME_OptLayout wsAfterC5)
{
  if (PME_isAreaArea(arg)) {
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterC5, 23), 1);
  }

  ATabort("Area has no WsAfterC5: %t\n", arg);
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
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)endOffset, 24), 1);
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
    return (PME_Area)ATsetArgument((ATermAppl)arg, (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)arg, 1), (ATerm)wsAfterEndOffset, 25), 1);
  }

  ATabort("Area has no WsAfterEndOffset: %t\n", arg);
  return (PME_Area)NULL;
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
  else if (PME_isStartFeedback(arg)) {
    return ATtrue;
  }
  else if (PME_isStartDescription(arg)) {
    return ATtrue;
  }
  else if (PME_isStartProducer(arg)) {
    return ATtrue;
  }
  else if (PME_isStartInformation(arg)) {
    return ATtrue;
  }
  else if (PME_isStartWarning(arg)) {
    return ATtrue;
  }
  else if (PME_isStartFatalError(arg)) {
    return ATtrue;
  }
  else if (PME_isStartError(arg)) {
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
/*{{{  inline ATbool PME_isStartDescription(PME_Start arg) */

inline ATbool PME_isStartDescription(PME_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PME_patternStartDescription, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PME_isStartProducer(PME_Start arg) */

inline ATbool PME_isStartProducer(PME_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PME_patternStartProducer, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PME_isStartInformation(PME_Start arg) */

inline ATbool PME_isStartInformation(PME_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PME_patternStartInformation, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PME_isStartWarning(PME_Start arg) */

inline ATbool PME_isStartWarning(PME_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PME_patternStartWarning, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PME_isStartFatalError(PME_Start arg) */

inline ATbool PME_isStartFatalError(PME_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PME_patternStartFatalError, NULL, NULL, NULL, NULL);
      last_gc = ATgetGCCount();
    }

    return last_result;
  }
}

/*}}}  */
/*{{{  inline ATbool PME_isStartError(PME_Start arg) */

inline ATbool PME_isStartError(PME_Start arg)
{
  {
    static ATerm last_arg = NULL;
    static int last_gc = -1;
    static ATbool last_result;

    assert(arg != NULL);

    if (last_gc != ATgetGCCount() || (ATerm)arg != last_arg) {
      last_arg = (ATerm)arg;
      last_result = ATmatchTerm((ATerm)arg, PME_patternStartError, NULL, NULL, NULL, NULL);
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
  else if (PME_isStartFeedback(arg)) {
    return ATtrue;
  }
  else if (PME_isStartDescription(arg)) {
    return ATtrue;
  }
  else if (PME_isStartProducer(arg)) {
    return ATtrue;
  }
  else if (PME_isStartInformation(arg)) {
    return ATtrue;
  }
  else if (PME_isStartWarning(arg)) {
    return ATtrue;
  }
  else if (PME_isStartFatalError(arg)) {
    return ATtrue;
  }
  else if (PME_isStartError(arg)) {
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
  else if (PME_isStartFeedback(arg)) {
    return (PME_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (PME_isStartDescription(arg)) {
    return (PME_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (PME_isStartProducer(arg)) {
    return (PME_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (PME_isStartInformation(arg)) {
    return (PME_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (PME_isStartWarning(arg)) {
    return (PME_OptLayout)ATgetFirst((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1));
  }
  else if (PME_isStartFatalError(arg)) {
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
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (PME_isStartLocation(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (PME_isStartFeedback(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (PME_isStartDescription(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (PME_isStartProducer(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (PME_isStartInformation(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (PME_isStartWarning(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (PME_isStartFatalError(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
  }
  else if (PME_isStartError(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsBefore, 0), 1), 0);
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
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topArea, 1), 1), 0);
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
  else if (PME_isStartFeedback(arg)) {
    return ATtrue;
  }
  else if (PME_isStartDescription(arg)) {
    return ATtrue;
  }
  else if (PME_isStartProducer(arg)) {
    return ATtrue;
  }
  else if (PME_isStartInformation(arg)) {
    return ATtrue;
  }
  else if (PME_isStartWarning(arg)) {
    return ATtrue;
  }
  else if (PME_isStartFatalError(arg)) {
    return ATtrue;
  }
  else if (PME_isStartError(arg)) {
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
  else if (PME_isStartFeedback(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (PME_isStartDescription(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (PME_isStartProducer(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (PME_isStartInformation(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (PME_isStartWarning(arg)) {
    return (PME_OptLayout)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 2);
  }
  else if (PME_isStartFatalError(arg)) {
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
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (PME_isStartLocation(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (PME_isStartFeedback(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (PME_isStartDescription(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (PME_isStartProducer(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (PME_isStartInformation(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (PME_isStartWarning(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (PME_isStartFatalError(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
  }
  else if (PME_isStartError(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)wsAfter, 2), 1), 0);
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
  else if (PME_isStartFeedback(arg)) {
    return ATtrue;
  }
  else if (PME_isStartDescription(arg)) {
    return ATtrue;
  }
  else if (PME_isStartProducer(arg)) {
    return ATtrue;
  }
  else if (PME_isStartInformation(arg)) {
    return ATtrue;
  }
  else if (PME_isStartWarning(arg)) {
    return ATtrue;
  }
  else if (PME_isStartFatalError(arg)) {
    return ATtrue;
  }
  else if (PME_isStartError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  int PME_getStartAmbCnt(PME_Start arg) */

int PME_getStartAmbCnt(PME_Start arg)
{
  if (PME_isStartArea(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (PME_isStartLocation(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (PME_isStartFeedback(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (PME_isStartDescription(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (PME_isStartProducer(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (PME_isStartInformation(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (PME_isStartWarning(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else if (PME_isStartFatalError(arg)) {
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
  }
  else 
    return (int)ATgetInt((ATermInt)ATgetArgument((ATermAppl)arg, 1));
}

/*}}}  */
/*{{{  PME_Start PME_setStartAmbCnt(PME_Start arg, int ambCnt) */

PME_Start PME_setStartAmbCnt(PME_Start arg, int ambCnt)
{
  if (PME_isStartArea(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (PME_isStartLocation(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (PME_isStartFeedback(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (PME_isStartDescription(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (PME_isStartProducer(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (PME_isStartInformation(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (PME_isStartWarning(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (PME_isStartFatalError(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
  }
  else if (PME_isStartError(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATmakeInt(ambCnt), 1);
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
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topLocation, 1), 1), 0);
  }

  ATabort("Start has no TopLocation: %t\n", arg);
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
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topFeedback, 1), 1), 0);
  }

  ATabort("Start has no TopFeedback: %t\n", arg);
  return (PME_Start)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasStartTopDescription(PME_Start arg) */

ATbool PME_hasStartTopDescription(PME_Start arg)
{
  if (PME_isStartDescription(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_Description PME_getStartTopDescription(PME_Start arg) */

PME_Description PME_getStartTopDescription(PME_Start arg)
{
  
    return (PME_Description)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  PME_Start PME_setStartTopDescription(PME_Start arg, PME_Description topDescription) */

PME_Start PME_setStartTopDescription(PME_Start arg, PME_Description topDescription)
{
  if (PME_isStartDescription(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topDescription, 1), 1), 0);
  }

  ATabort("Start has no TopDescription: %t\n", arg);
  return (PME_Start)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasStartTopProducer(PME_Start arg) */

ATbool PME_hasStartTopProducer(PME_Start arg)
{
  if (PME_isStartProducer(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_Producer PME_getStartTopProducer(PME_Start arg) */

PME_Producer PME_getStartTopProducer(PME_Start arg)
{
  
    return (PME_Producer)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  PME_Start PME_setStartTopProducer(PME_Start arg, PME_Producer topProducer) */

PME_Start PME_setStartTopProducer(PME_Start arg, PME_Producer topProducer)
{
  if (PME_isStartProducer(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topProducer, 1), 1), 0);
  }

  ATabort("Start has no TopProducer: %t\n", arg);
  return (PME_Start)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasStartTopInformation(PME_Start arg) */

ATbool PME_hasStartTopInformation(PME_Start arg)
{
  if (PME_isStartInformation(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_Information PME_getStartTopInformation(PME_Start arg) */

PME_Information PME_getStartTopInformation(PME_Start arg)
{
  
    return (PME_Information)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  PME_Start PME_setStartTopInformation(PME_Start arg, PME_Information topInformation) */

PME_Start PME_setStartTopInformation(PME_Start arg, PME_Information topInformation)
{
  if (PME_isStartInformation(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topInformation, 1), 1), 0);
  }

  ATabort("Start has no TopInformation: %t\n", arg);
  return (PME_Start)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasStartTopWarning(PME_Start arg) */

ATbool PME_hasStartTopWarning(PME_Start arg)
{
  if (PME_isStartWarning(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_Warning PME_getStartTopWarning(PME_Start arg) */

PME_Warning PME_getStartTopWarning(PME_Start arg)
{
  
    return (PME_Warning)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  PME_Start PME_setStartTopWarning(PME_Start arg, PME_Warning topWarning) */

PME_Start PME_setStartTopWarning(PME_Start arg, PME_Warning topWarning)
{
  if (PME_isStartWarning(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topWarning, 1), 1), 0);
  }

  ATabort("Start has no TopWarning: %t\n", arg);
  return (PME_Start)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasStartTopFatalError(PME_Start arg) */

ATbool PME_hasStartTopFatalError(PME_Start arg)
{
  if (PME_isStartFatalError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_FatalError PME_getStartTopFatalError(PME_Start arg) */

PME_FatalError PME_getStartTopFatalError(PME_Start arg)
{
  
    return (PME_FatalError)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  PME_Start PME_setStartTopFatalError(PME_Start arg, PME_FatalError topFatalError) */

PME_Start PME_setStartTopFatalError(PME_Start arg, PME_FatalError topFatalError)
{
  if (PME_isStartFatalError(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topFatalError, 1), 1), 0);
  }

  ATabort("Start has no TopFatalError: %t\n", arg);
  return (PME_Start)NULL;
}

/*}}}  */
/*{{{  ATbool PME_hasStartTopError(PME_Start arg) */

ATbool PME_hasStartTopError(PME_Start arg)
{
  if (PME_isStartError(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_Error PME_getStartTopError(PME_Start arg) */

PME_Error PME_getStartTopError(PME_Start arg)
{
  
    return (PME_Error)ATelementAt((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), 1);
}

/*}}}  */
/*{{{  PME_Start PME_setStartTopError(PME_Start arg, PME_Error topError) */

PME_Start PME_setStartTopError(PME_Start arg, PME_Error topError)
{
  if (PME_isStartError(arg)) {
    return (PME_Start)ATsetArgument((ATermAppl)arg, (ATerm)ATsetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), (ATerm)ATreplace((ATermList)ATgetArgument((ATermAppl)ATgetArgument((ATermAppl)arg, 0), 1), (ATerm)topError, 1), 1), 0);
  }

  ATabort("Start has no TopError: %t\n", arg);
  return (PME_Start)NULL;
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
/*{{{  ATbool PME_hasOptLayoutChars(PME_OptLayout arg) */

ATbool PME_hasOptLayoutChars(PME_OptLayout arg)
{
  if (PME_isOptLayoutPresent(arg)) {
    return ATtrue;
  }
  return ATfalse;
}

/*}}}  */
/*{{{  PME_CHARLIST PME_getOptLayoutChars(PME_OptLayout arg) */

PME_CHARLIST PME_getOptLayoutChars(PME_OptLayout arg)
{
  
    return (PME_CHARLIST)ATgetArgument((ATermAppl)arg, 1);
}

/*}}}  */
/*{{{  PME_OptLayout PME_setOptLayoutChars(PME_OptLayout arg, PME_CHARLIST chars) */

PME_OptLayout PME_setOptLayoutChars(PME_OptLayout arg, PME_CHARLIST chars)
{
  if (PME_isOptLayoutPresent(arg)) {
    return (PME_OptLayout)ATsetArgument((ATermAppl)arg, (ATerm)chars, 1);
  }

  ATabort("OptLayout has no Chars: %t\n", arg);
  return (PME_OptLayout)NULL;
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
/*{{{  PME_Information PME_visitInformation(PME_Information arg, PME_OptLayout (*acceptWsAfterInformation)(PME_OptLayout), PME_OptLayout (*acceptWsAfterParenOpen)(PME_OptLayout), PME_String (*acceptId)(PME_String), PME_OptLayout (*acceptWsAfterId)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC1)(PME_OptLayout), PME_Producer (*acceptProducer)(PME_Producer), PME_OptLayout (*acceptWsAfterProducer)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC2)(PME_OptLayout), PME_Description (*acceptDescription)(PME_Description), PME_OptLayout (*acceptWsAfterDescription)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC3)(PME_OptLayout), PME_Subjects (*acceptSubjects)(PME_Subjects), PME_OptLayout (*acceptWsAfterSubjects)(PME_OptLayout)) */

PME_Information PME_visitInformation(PME_Information arg, PME_OptLayout (*acceptWsAfterInformation)(PME_OptLayout), PME_OptLayout (*acceptWsAfterParenOpen)(PME_OptLayout), PME_String (*acceptId)(PME_String), PME_OptLayout (*acceptWsAfterId)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC1)(PME_OptLayout), PME_Producer (*acceptProducer)(PME_Producer), PME_OptLayout (*acceptWsAfterProducer)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC2)(PME_OptLayout), PME_Description (*acceptDescription)(PME_Description), PME_OptLayout (*acceptWsAfterDescription)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC3)(PME_OptLayout), PME_Subjects (*acceptSubjects)(PME_Subjects), PME_OptLayout (*acceptWsAfterSubjects)(PME_OptLayout))
{
  if (PME_isInformationInformation(arg)) {
    return PME_makeInformationInformation(
        acceptWsAfterInformation ? acceptWsAfterInformation(PME_getInformationWsAfterInformation(arg)) : PME_getInformationWsAfterInformation(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PME_getInformationWsAfterParenOpen(arg)) : PME_getInformationWsAfterParenOpen(arg),
        acceptId ? acceptId(PME_getInformationId(arg)) : PME_getInformationId(arg),
        acceptWsAfterId ? acceptWsAfterId(PME_getInformationWsAfterId(arg)) : PME_getInformationWsAfterId(arg),
        acceptWsAfterC1 ? acceptWsAfterC1(PME_getInformationWsAfterC1(arg)) : PME_getInformationWsAfterC1(arg),
        acceptProducer ? acceptProducer(PME_getInformationProducer(arg)) : PME_getInformationProducer(arg),
        acceptWsAfterProducer ? acceptWsAfterProducer(PME_getInformationWsAfterProducer(arg)) : PME_getInformationWsAfterProducer(arg),
        acceptWsAfterC2 ? acceptWsAfterC2(PME_getInformationWsAfterC2(arg)) : PME_getInformationWsAfterC2(arg),
        acceptDescription ? acceptDescription(PME_getInformationDescription(arg)) : PME_getInformationDescription(arg),
        acceptWsAfterDescription ? acceptWsAfterDescription(PME_getInformationWsAfterDescription(arg)) : PME_getInformationWsAfterDescription(arg),
        acceptWsAfterC3 ? acceptWsAfterC3(PME_getInformationWsAfterC3(arg)) : PME_getInformationWsAfterC3(arg),
        acceptSubjects ? acceptSubjects(PME_getInformationSubjects(arg)) : PME_getInformationSubjects(arg),
        acceptWsAfterSubjects ? acceptWsAfterSubjects(PME_getInformationWsAfterSubjects(arg)) : PME_getInformationWsAfterSubjects(arg));
  }
  ATabort("not a Information: %t\n", arg);
  return (PME_Information)NULL;
}

/*}}}  */
/*{{{  PME_Warning PME_visitWarning(PME_Warning arg, PME_OptLayout (*acceptWsAfterWarning)(PME_OptLayout), PME_OptLayout (*acceptWsAfterParenOpen)(PME_OptLayout), PME_String (*acceptId)(PME_String), PME_OptLayout (*acceptWsAfterId)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC1)(PME_OptLayout), PME_Producer (*acceptProducer)(PME_Producer), PME_OptLayout (*acceptWsAfterProducer)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC2)(PME_OptLayout), PME_Description (*acceptDescription)(PME_Description), PME_OptLayout (*acceptWsAfterDescription)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC3)(PME_OptLayout), PME_Subjects (*acceptSubjects)(PME_Subjects), PME_OptLayout (*acceptWsAfterSubjects)(PME_OptLayout)) */

PME_Warning PME_visitWarning(PME_Warning arg, PME_OptLayout (*acceptWsAfterWarning)(PME_OptLayout), PME_OptLayout (*acceptWsAfterParenOpen)(PME_OptLayout), PME_String (*acceptId)(PME_String), PME_OptLayout (*acceptWsAfterId)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC1)(PME_OptLayout), PME_Producer (*acceptProducer)(PME_Producer), PME_OptLayout (*acceptWsAfterProducer)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC2)(PME_OptLayout), PME_Description (*acceptDescription)(PME_Description), PME_OptLayout (*acceptWsAfterDescription)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC3)(PME_OptLayout), PME_Subjects (*acceptSubjects)(PME_Subjects), PME_OptLayout (*acceptWsAfterSubjects)(PME_OptLayout))
{
  if (PME_isWarningWarning(arg)) {
    return PME_makeWarningWarning(
        acceptWsAfterWarning ? acceptWsAfterWarning(PME_getWarningWsAfterWarning(arg)) : PME_getWarningWsAfterWarning(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PME_getWarningWsAfterParenOpen(arg)) : PME_getWarningWsAfterParenOpen(arg),
        acceptId ? acceptId(PME_getWarningId(arg)) : PME_getWarningId(arg),
        acceptWsAfterId ? acceptWsAfterId(PME_getWarningWsAfterId(arg)) : PME_getWarningWsAfterId(arg),
        acceptWsAfterC1 ? acceptWsAfterC1(PME_getWarningWsAfterC1(arg)) : PME_getWarningWsAfterC1(arg),
        acceptProducer ? acceptProducer(PME_getWarningProducer(arg)) : PME_getWarningProducer(arg),
        acceptWsAfterProducer ? acceptWsAfterProducer(PME_getWarningWsAfterProducer(arg)) : PME_getWarningWsAfterProducer(arg),
        acceptWsAfterC2 ? acceptWsAfterC2(PME_getWarningWsAfterC2(arg)) : PME_getWarningWsAfterC2(arg),
        acceptDescription ? acceptDescription(PME_getWarningDescription(arg)) : PME_getWarningDescription(arg),
        acceptWsAfterDescription ? acceptWsAfterDescription(PME_getWarningWsAfterDescription(arg)) : PME_getWarningWsAfterDescription(arg),
        acceptWsAfterC3 ? acceptWsAfterC3(PME_getWarningWsAfterC3(arg)) : PME_getWarningWsAfterC3(arg),
        acceptSubjects ? acceptSubjects(PME_getWarningSubjects(arg)) : PME_getWarningSubjects(arg),
        acceptWsAfterSubjects ? acceptWsAfterSubjects(PME_getWarningWsAfterSubjects(arg)) : PME_getWarningWsAfterSubjects(arg));
  }
  ATabort("not a Warning: %t\n", arg);
  return (PME_Warning)NULL;
}

/*}}}  */
/*{{{  PME_Error PME_visitError(PME_Error arg, PME_OptLayout (*acceptWsAfterError)(PME_OptLayout), PME_OptLayout (*acceptWsAfterParenOpen)(PME_OptLayout), PME_String (*acceptId)(PME_String), PME_OptLayout (*acceptWsAfterId)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC1)(PME_OptLayout), PME_Producer (*acceptProducer)(PME_Producer), PME_OptLayout (*acceptWsAfterProducer)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC2)(PME_OptLayout), PME_Description (*acceptDescription)(PME_Description), PME_OptLayout (*acceptWsAfterDescription)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC3)(PME_OptLayout), PME_Subjects (*acceptSubjects)(PME_Subjects), PME_OptLayout (*acceptWsAfterSubjects)(PME_OptLayout)) */

PME_Error PME_visitError(PME_Error arg, PME_OptLayout (*acceptWsAfterError)(PME_OptLayout), PME_OptLayout (*acceptWsAfterParenOpen)(PME_OptLayout), PME_String (*acceptId)(PME_String), PME_OptLayout (*acceptWsAfterId)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC1)(PME_OptLayout), PME_Producer (*acceptProducer)(PME_Producer), PME_OptLayout (*acceptWsAfterProducer)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC2)(PME_OptLayout), PME_Description (*acceptDescription)(PME_Description), PME_OptLayout (*acceptWsAfterDescription)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC3)(PME_OptLayout), PME_Subjects (*acceptSubjects)(PME_Subjects), PME_OptLayout (*acceptWsAfterSubjects)(PME_OptLayout))
{
  if (PME_isErrorError(arg)) {
    return PME_makeErrorError(
        acceptWsAfterError ? acceptWsAfterError(PME_getErrorWsAfterError(arg)) : PME_getErrorWsAfterError(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PME_getErrorWsAfterParenOpen(arg)) : PME_getErrorWsAfterParenOpen(arg),
        acceptId ? acceptId(PME_getErrorId(arg)) : PME_getErrorId(arg),
        acceptWsAfterId ? acceptWsAfterId(PME_getErrorWsAfterId(arg)) : PME_getErrorWsAfterId(arg),
        acceptWsAfterC1 ? acceptWsAfterC1(PME_getErrorWsAfterC1(arg)) : PME_getErrorWsAfterC1(arg),
        acceptProducer ? acceptProducer(PME_getErrorProducer(arg)) : PME_getErrorProducer(arg),
        acceptWsAfterProducer ? acceptWsAfterProducer(PME_getErrorWsAfterProducer(arg)) : PME_getErrorWsAfterProducer(arg),
        acceptWsAfterC2 ? acceptWsAfterC2(PME_getErrorWsAfterC2(arg)) : PME_getErrorWsAfterC2(arg),
        acceptDescription ? acceptDescription(PME_getErrorDescription(arg)) : PME_getErrorDescription(arg),
        acceptWsAfterDescription ? acceptWsAfterDescription(PME_getErrorWsAfterDescription(arg)) : PME_getErrorWsAfterDescription(arg),
        acceptWsAfterC3 ? acceptWsAfterC3(PME_getErrorWsAfterC3(arg)) : PME_getErrorWsAfterC3(arg),
        acceptSubjects ? acceptSubjects(PME_getErrorSubjects(arg)) : PME_getErrorSubjects(arg),
        acceptWsAfterSubjects ? acceptWsAfterSubjects(PME_getErrorWsAfterSubjects(arg)) : PME_getErrorWsAfterSubjects(arg));
  }
  ATabort("not a Error: %t\n", arg);
  return (PME_Error)NULL;
}

/*}}}  */
/*{{{  PME_FatalError PME_visitFatalError(PME_FatalError arg, PME_OptLayout (*acceptWsAfterFatalError)(PME_OptLayout), PME_OptLayout (*acceptWsAfterParenOpen)(PME_OptLayout), PME_String (*acceptId)(PME_String), PME_OptLayout (*acceptWsAfterId)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC1)(PME_OptLayout), PME_Producer (*acceptProducer)(PME_Producer), PME_OptLayout (*acceptWsAfterProducer)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC2)(PME_OptLayout), PME_Description (*acceptDescription)(PME_Description), PME_OptLayout (*acceptWsAfterDescription)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC3)(PME_OptLayout), PME_Subjects (*acceptSubjects)(PME_Subjects), PME_OptLayout (*acceptWsAfterSubjects)(PME_OptLayout)) */

PME_FatalError PME_visitFatalError(PME_FatalError arg, PME_OptLayout (*acceptWsAfterFatalError)(PME_OptLayout), PME_OptLayout (*acceptWsAfterParenOpen)(PME_OptLayout), PME_String (*acceptId)(PME_String), PME_OptLayout (*acceptWsAfterId)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC1)(PME_OptLayout), PME_Producer (*acceptProducer)(PME_Producer), PME_OptLayout (*acceptWsAfterProducer)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC2)(PME_OptLayout), PME_Description (*acceptDescription)(PME_Description), PME_OptLayout (*acceptWsAfterDescription)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC3)(PME_OptLayout), PME_Subjects (*acceptSubjects)(PME_Subjects), PME_OptLayout (*acceptWsAfterSubjects)(PME_OptLayout))
{
  if (PME_isFatalErrorFatalError(arg)) {
    return PME_makeFatalErrorFatalError(
        acceptWsAfterFatalError ? acceptWsAfterFatalError(PME_getFatalErrorWsAfterFatalError(arg)) : PME_getFatalErrorWsAfterFatalError(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PME_getFatalErrorWsAfterParenOpen(arg)) : PME_getFatalErrorWsAfterParenOpen(arg),
        acceptId ? acceptId(PME_getFatalErrorId(arg)) : PME_getFatalErrorId(arg),
        acceptWsAfterId ? acceptWsAfterId(PME_getFatalErrorWsAfterId(arg)) : PME_getFatalErrorWsAfterId(arg),
        acceptWsAfterC1 ? acceptWsAfterC1(PME_getFatalErrorWsAfterC1(arg)) : PME_getFatalErrorWsAfterC1(arg),
        acceptProducer ? acceptProducer(PME_getFatalErrorProducer(arg)) : PME_getFatalErrorProducer(arg),
        acceptWsAfterProducer ? acceptWsAfterProducer(PME_getFatalErrorWsAfterProducer(arg)) : PME_getFatalErrorWsAfterProducer(arg),
        acceptWsAfterC2 ? acceptWsAfterC2(PME_getFatalErrorWsAfterC2(arg)) : PME_getFatalErrorWsAfterC2(arg),
        acceptDescription ? acceptDescription(PME_getFatalErrorDescription(arg)) : PME_getFatalErrorDescription(arg),
        acceptWsAfterDescription ? acceptWsAfterDescription(PME_getFatalErrorWsAfterDescription(arg)) : PME_getFatalErrorWsAfterDescription(arg),
        acceptWsAfterC3 ? acceptWsAfterC3(PME_getFatalErrorWsAfterC3(arg)) : PME_getFatalErrorWsAfterC3(arg),
        acceptSubjects ? acceptSubjects(PME_getFatalErrorSubjects(arg)) : PME_getFatalErrorSubjects(arg),
        acceptWsAfterSubjects ? acceptWsAfterSubjects(PME_getFatalErrorWsAfterSubjects(arg)) : PME_getFatalErrorWsAfterSubjects(arg));
  }
  ATabort("not a FatalError: %t\n", arg);
  return (PME_FatalError)NULL;
}

/*}}}  */
/*{{{  PME_Producer PME_visitProducer(PME_Producer arg, PME_OptLayout (*acceptWsAfterProducer)(PME_OptLayout), PME_OptLayout (*acceptWsAfterParenOpen)(PME_OptLayout), PME_String (*acceptId)(PME_String), PME_OptLayout (*acceptWsAfterId)(PME_OptLayout), PME_OptLayout (*acceptWsAfterComma)(PME_OptLayout), PME_String (*acceptType)(PME_String), PME_OptLayout (*acceptWsAfterType)(PME_OptLayout)) */

PME_Producer PME_visitProducer(PME_Producer arg, PME_OptLayout (*acceptWsAfterProducer)(PME_OptLayout), PME_OptLayout (*acceptWsAfterParenOpen)(PME_OptLayout), PME_String (*acceptId)(PME_String), PME_OptLayout (*acceptWsAfterId)(PME_OptLayout), PME_OptLayout (*acceptWsAfterComma)(PME_OptLayout), PME_String (*acceptType)(PME_String), PME_OptLayout (*acceptWsAfterType)(PME_OptLayout))
{
  if (PME_isProducerProducer(arg)) {
    return PME_makeProducerProducer(
        acceptWsAfterProducer ? acceptWsAfterProducer(PME_getProducerWsAfterProducer(arg)) : PME_getProducerWsAfterProducer(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PME_getProducerWsAfterParenOpen(arg)) : PME_getProducerWsAfterParenOpen(arg),
        acceptId ? acceptId(PME_getProducerId(arg)) : PME_getProducerId(arg),
        acceptWsAfterId ? acceptWsAfterId(PME_getProducerWsAfterId(arg)) : PME_getProducerWsAfterId(arg),
        acceptWsAfterComma ? acceptWsAfterComma(PME_getProducerWsAfterComma(arg)) : PME_getProducerWsAfterComma(arg),
        acceptType ? acceptType(PME_getProducerType(arg)) : PME_getProducerType(arg),
        acceptWsAfterType ? acceptWsAfterType(PME_getProducerWsAfterType(arg)) : PME_getProducerWsAfterType(arg));
  }
  ATabort("not a Producer: %t\n", arg);
  return (PME_Producer)NULL;
}

/*}}}  */
/*{{{  PME_Description PME_visitDescription(PME_Description arg, PME_OptLayout (*acceptWsAfterDescription)(PME_OptLayout), PME_OptLayout (*acceptWsAfterParenOpen)(PME_OptLayout), PME_String (*acceptString)(PME_String), PME_OptLayout (*acceptWsAfterString)(PME_OptLayout)) */

PME_Description PME_visitDescription(PME_Description arg, PME_OptLayout (*acceptWsAfterDescription)(PME_OptLayout), PME_OptLayout (*acceptWsAfterParenOpen)(PME_OptLayout), PME_String (*acceptString)(PME_String), PME_OptLayout (*acceptWsAfterString)(PME_OptLayout))
{
  if (PME_isDescriptionDescription(arg)) {
    return PME_makeDescriptionDescription(
        acceptWsAfterDescription ? acceptWsAfterDescription(PME_getDescriptionWsAfterDescription(arg)) : PME_getDescriptionWsAfterDescription(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PME_getDescriptionWsAfterParenOpen(arg)) : PME_getDescriptionWsAfterParenOpen(arg),
        acceptString ? acceptString(PME_getDescriptionString(arg)) : PME_getDescriptionString(arg),
        acceptWsAfterString ? acceptWsAfterString(PME_getDescriptionWsAfterString(arg)) : PME_getDescriptionWsAfterString(arg));
  }
  ATabort("not a Description: %t\n", arg);
  return (PME_Description)NULL;
}

/*}}}  */
/*{{{  PME_Subjects PME_visitSubjects(PME_Subjects arg, PME_OptLayout (*acceptWsAfterBracketOpen)(PME_OptLayout), PME_SubjectSubjectList (*acceptSubjectList)(PME_SubjectSubjectList), PME_OptLayout (*acceptWsAfterSubjectList)(PME_OptLayout)) */

PME_Subjects PME_visitSubjects(PME_Subjects arg, PME_OptLayout (*acceptWsAfterBracketOpen)(PME_OptLayout), PME_SubjectSubjectList (*acceptSubjectList)(PME_SubjectSubjectList), PME_OptLayout (*acceptWsAfterSubjectList)(PME_OptLayout))
{
  if (PME_isSubjectsSubjects(arg)) {
    return PME_makeSubjectsSubjects(
        acceptWsAfterBracketOpen ? acceptWsAfterBracketOpen(PME_getSubjectsWsAfterBracketOpen(arg)) : PME_getSubjectsWsAfterBracketOpen(arg),
        acceptSubjectList ? acceptSubjectList(PME_getSubjectsSubjectList(arg)) : PME_getSubjectsSubjectList(arg),
        acceptWsAfterSubjectList ? acceptWsAfterSubjectList(PME_getSubjectsWsAfterSubjectList(arg)) : PME_getSubjectsWsAfterSubjectList(arg));
  }
  ATabort("not a Subjects: %t\n", arg);
  return (PME_Subjects)NULL;
}

/*}}}  */
/*{{{  PME_SubjectSubjectList PME_visitSubjectSubjectList(PME_SubjectSubjectList arg, PME_Subject (*acceptHead)(PME_Subject), PME_OptLayout (*acceptWsAfterFirst)(PME_OptLayout), char* (*acceptSep)(char*), PME_OptLayout (*acceptWsAfterSep)(PME_OptLayout)) */

PME_SubjectSubjectList PME_visitSubjectSubjectList(PME_SubjectSubjectList arg, PME_Subject (*acceptHead)(PME_Subject), PME_OptLayout (*acceptWsAfterFirst)(PME_OptLayout), char* (*acceptSep)(char*), PME_OptLayout (*acceptWsAfterSep)(PME_OptLayout))
{
  if (PME_isSubjectSubjectListMany(arg)) {
    return PME_makeSubjectSubjectListMany(
        acceptHead ? acceptHead(PME_getSubjectSubjectListHead(arg)) : PME_getSubjectSubjectListHead(arg),
        acceptWsAfterFirst ? acceptWsAfterFirst(PME_getSubjectSubjectListWsAfterFirst(arg)) : PME_getSubjectSubjectListWsAfterFirst(arg),
        acceptSep ? acceptSep(PME_getSubjectSubjectListSep(arg)) : PME_getSubjectSubjectListSep(arg),
        acceptWsAfterSep ? acceptWsAfterSep(PME_getSubjectSubjectListWsAfterSep(arg)) : PME_getSubjectSubjectListWsAfterSep(arg),
        PME_visitSubjectSubjectList(PME_getSubjectSubjectListTail(arg), acceptHead, acceptWsAfterFirst, acceptSep, acceptWsAfterSep));
  }
  if (PME_isSubjectSubjectListEmpty(arg)) {
    return PME_makeSubjectSubjectListEmpty();
  }
  if (PME_isSubjectSubjectListSingle(arg)) {
    return PME_makeSubjectSubjectListSingle(
        acceptHead ? acceptHead(PME_getSubjectSubjectListHead(arg)) : PME_getSubjectSubjectListHead(arg));
  }
  ATabort("not a SubjectSubjectList: %t\n", arg);
  return (PME_SubjectSubjectList)NULL;
}

/*}}}  */
/*{{{  PME_Subject PME_visitSubject(PME_Subject arg, PME_OptLayout (*acceptWsAfterSubject)(PME_OptLayout), PME_OptLayout (*acceptWsAfterParenOpen)(PME_OptLayout), PME_String (*acceptId)(PME_String), PME_OptLayout (*acceptWsAfterId)(PME_OptLayout), PME_OptLayout (*acceptWsAfterComma)(PME_OptLayout), PME_Location (*acceptLocation)(PME_Location), PME_OptLayout (*acceptWsAfterLocation)(PME_OptLayout)) */

PME_Subject PME_visitSubject(PME_Subject arg, PME_OptLayout (*acceptWsAfterSubject)(PME_OptLayout), PME_OptLayout (*acceptWsAfterParenOpen)(PME_OptLayout), PME_String (*acceptId)(PME_String), PME_OptLayout (*acceptWsAfterId)(PME_OptLayout), PME_OptLayout (*acceptWsAfterComma)(PME_OptLayout), PME_Location (*acceptLocation)(PME_Location), PME_OptLayout (*acceptWsAfterLocation)(PME_OptLayout))
{
  if (PME_isSubjectWithoutLocation(arg)) {
    return PME_makeSubjectWithoutLocation(
        acceptWsAfterSubject ? acceptWsAfterSubject(PME_getSubjectWsAfterSubject(arg)) : PME_getSubjectWsAfterSubject(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PME_getSubjectWsAfterParenOpen(arg)) : PME_getSubjectWsAfterParenOpen(arg),
        acceptId ? acceptId(PME_getSubjectId(arg)) : PME_getSubjectId(arg),
        acceptWsAfterId ? acceptWsAfterId(PME_getSubjectWsAfterId(arg)) : PME_getSubjectWsAfterId(arg),
        acceptWsAfterComma ? acceptWsAfterComma(PME_getSubjectWsAfterComma(arg)) : PME_getSubjectWsAfterComma(arg),
        acceptLocation ? acceptLocation(PME_getSubjectLocation(arg)) : PME_getSubjectLocation(arg),
        acceptWsAfterLocation ? acceptWsAfterLocation(PME_getSubjectWsAfterLocation(arg)) : PME_getSubjectWsAfterLocation(arg));
  }
  if (PME_isSubjectWithLocation(arg)) {
    return PME_makeSubjectWithLocation(
        acceptWsAfterSubject ? acceptWsAfterSubject(PME_getSubjectWsAfterSubject(arg)) : PME_getSubjectWsAfterSubject(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PME_getSubjectWsAfterParenOpen(arg)) : PME_getSubjectWsAfterParenOpen(arg),
        acceptId ? acceptId(PME_getSubjectId(arg)) : PME_getSubjectId(arg),
        acceptWsAfterId ? acceptWsAfterId(PME_getSubjectWsAfterId(arg)) : PME_getSubjectWsAfterId(arg));
  }
  ATabort("not a Subject: %t\n", arg);
  return (PME_Subject)NULL;
}

/*}}}  */
/*{{{  PME_Location PME_visitLocation(PME_Location arg, PME_OptLayout (*acceptWsAfterLocation)(PME_OptLayout), PME_OptLayout (*acceptWsAfterParenOpen)(PME_OptLayout), PME_String (*acceptFile)(PME_String), PME_OptLayout (*acceptWsAfterFile)(PME_OptLayout), PME_OptLayout (*acceptWsAfterComma)(PME_OptLayout), PME_Area (*acceptArea)(PME_Area), PME_OptLayout (*acceptWsAfterArea)(PME_OptLayout)) */

PME_Location PME_visitLocation(PME_Location arg, PME_OptLayout (*acceptWsAfterLocation)(PME_OptLayout), PME_OptLayout (*acceptWsAfterParenOpen)(PME_OptLayout), PME_String (*acceptFile)(PME_String), PME_OptLayout (*acceptWsAfterFile)(PME_OptLayout), PME_OptLayout (*acceptWsAfterComma)(PME_OptLayout), PME_Area (*acceptArea)(PME_Area), PME_OptLayout (*acceptWsAfterArea)(PME_OptLayout))
{
  if (PME_isLocationLocation(arg)) {
    return PME_makeLocationLocation(
        acceptWsAfterLocation ? acceptWsAfterLocation(PME_getLocationWsAfterLocation(arg)) : PME_getLocationWsAfterLocation(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PME_getLocationWsAfterParenOpen(arg)) : PME_getLocationWsAfterParenOpen(arg),
        acceptFile ? acceptFile(PME_getLocationFile(arg)) : PME_getLocationFile(arg),
        acceptWsAfterFile ? acceptWsAfterFile(PME_getLocationWsAfterFile(arg)) : PME_getLocationWsAfterFile(arg),
        acceptWsAfterComma ? acceptWsAfterComma(PME_getLocationWsAfterComma(arg)) : PME_getLocationWsAfterComma(arg),
        acceptArea ? acceptArea(PME_getLocationArea(arg)) : PME_getLocationArea(arg),
        acceptWsAfterArea ? acceptWsAfterArea(PME_getLocationWsAfterArea(arg)) : PME_getLocationWsAfterArea(arg));
  }
  ATabort("not a Location: %t\n", arg);
  return (PME_Location)NULL;
}

/*}}}  */
/*{{{  PME_Area PME_visitArea(PME_Area arg, PME_OptLayout (*acceptWsAfterArea)(PME_OptLayout), PME_OptLayout (*acceptWsAfterParenOpen)(PME_OptLayout), PME_NatCon (*acceptStartLine)(PME_NatCon), PME_OptLayout (*acceptWsAfterStartLine)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC1)(PME_OptLayout), PME_NatCon (*acceptStartColumn)(PME_NatCon), PME_OptLayout (*acceptWsAfterStartColumn)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC2)(PME_OptLayout), PME_NatCon (*acceptEndLine)(PME_NatCon), PME_OptLayout (*acceptWsAfterEndLine)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC3)(PME_OptLayout), PME_NatCon (*acceptEndColumn)(PME_NatCon), PME_OptLayout (*acceptWsAfterEndColumn)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC4)(PME_OptLayout), PME_NatCon (*acceptStartOffset)(PME_NatCon), PME_OptLayout (*acceptWsAfterStartOffset)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC5)(PME_OptLayout), PME_NatCon (*acceptEndOffset)(PME_NatCon), PME_OptLayout (*acceptWsAfterEndOffset)(PME_OptLayout)) */

PME_Area PME_visitArea(PME_Area arg, PME_OptLayout (*acceptWsAfterArea)(PME_OptLayout), PME_OptLayout (*acceptWsAfterParenOpen)(PME_OptLayout), PME_NatCon (*acceptStartLine)(PME_NatCon), PME_OptLayout (*acceptWsAfterStartLine)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC1)(PME_OptLayout), PME_NatCon (*acceptStartColumn)(PME_NatCon), PME_OptLayout (*acceptWsAfterStartColumn)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC2)(PME_OptLayout), PME_NatCon (*acceptEndLine)(PME_NatCon), PME_OptLayout (*acceptWsAfterEndLine)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC3)(PME_OptLayout), PME_NatCon (*acceptEndColumn)(PME_NatCon), PME_OptLayout (*acceptWsAfterEndColumn)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC4)(PME_OptLayout), PME_NatCon (*acceptStartOffset)(PME_NatCon), PME_OptLayout (*acceptWsAfterStartOffset)(PME_OptLayout), PME_OptLayout (*acceptWsAfterC5)(PME_OptLayout), PME_NatCon (*acceptEndOffset)(PME_NatCon), PME_OptLayout (*acceptWsAfterEndOffset)(PME_OptLayout))
{
  if (PME_isAreaArea(arg)) {
    return PME_makeAreaArea(
        acceptWsAfterArea ? acceptWsAfterArea(PME_getAreaWsAfterArea(arg)) : PME_getAreaWsAfterArea(arg),
        acceptWsAfterParenOpen ? acceptWsAfterParenOpen(PME_getAreaWsAfterParenOpen(arg)) : PME_getAreaWsAfterParenOpen(arg),
        acceptStartLine ? acceptStartLine(PME_getAreaStartLine(arg)) : PME_getAreaStartLine(arg),
        acceptWsAfterStartLine ? acceptWsAfterStartLine(PME_getAreaWsAfterStartLine(arg)) : PME_getAreaWsAfterStartLine(arg),
        acceptWsAfterC1 ? acceptWsAfterC1(PME_getAreaWsAfterC1(arg)) : PME_getAreaWsAfterC1(arg),
        acceptStartColumn ? acceptStartColumn(PME_getAreaStartColumn(arg)) : PME_getAreaStartColumn(arg),
        acceptWsAfterStartColumn ? acceptWsAfterStartColumn(PME_getAreaWsAfterStartColumn(arg)) : PME_getAreaWsAfterStartColumn(arg),
        acceptWsAfterC2 ? acceptWsAfterC2(PME_getAreaWsAfterC2(arg)) : PME_getAreaWsAfterC2(arg),
        acceptEndLine ? acceptEndLine(PME_getAreaEndLine(arg)) : PME_getAreaEndLine(arg),
        acceptWsAfterEndLine ? acceptWsAfterEndLine(PME_getAreaWsAfterEndLine(arg)) : PME_getAreaWsAfterEndLine(arg),
        acceptWsAfterC3 ? acceptWsAfterC3(PME_getAreaWsAfterC3(arg)) : PME_getAreaWsAfterC3(arg),
        acceptEndColumn ? acceptEndColumn(PME_getAreaEndColumn(arg)) : PME_getAreaEndColumn(arg),
        acceptWsAfterEndColumn ? acceptWsAfterEndColumn(PME_getAreaWsAfterEndColumn(arg)) : PME_getAreaWsAfterEndColumn(arg),
        acceptWsAfterC4 ? acceptWsAfterC4(PME_getAreaWsAfterC4(arg)) : PME_getAreaWsAfterC4(arg),
        acceptStartOffset ? acceptStartOffset(PME_getAreaStartOffset(arg)) : PME_getAreaStartOffset(arg),
        acceptWsAfterStartOffset ? acceptWsAfterStartOffset(PME_getAreaWsAfterStartOffset(arg)) : PME_getAreaWsAfterStartOffset(arg),
        acceptWsAfterC5 ? acceptWsAfterC5(PME_getAreaWsAfterC5(arg)) : PME_getAreaWsAfterC5(arg),
        acceptEndOffset ? acceptEndOffset(PME_getAreaEndOffset(arg)) : PME_getAreaEndOffset(arg),
        acceptWsAfterEndOffset ? acceptWsAfterEndOffset(PME_getAreaWsAfterEndOffset(arg)) : PME_getAreaWsAfterEndOffset(arg));
  }
  ATabort("not a Area: %t\n", arg);
  return (PME_Area)NULL;
}

/*}}}  */
/*{{{  PME_Start PME_visitStart(PME_Start arg, PME_OptLayout (*acceptWsBefore)(PME_OptLayout), PME_Area (*acceptTopArea)(PME_Area), PME_OptLayout (*acceptWsAfter)(PME_OptLayout), int (*acceptAmbCnt)(int), PME_Location (*acceptTopLocation)(PME_Location), PME_Feedback (*acceptTopFeedback)(PME_Feedback), PME_Description (*acceptTopDescription)(PME_Description), PME_Producer (*acceptTopProducer)(PME_Producer), PME_Information (*acceptTopInformation)(PME_Information), PME_Warning (*acceptTopWarning)(PME_Warning), PME_FatalError (*acceptTopFatalError)(PME_FatalError), PME_Error (*acceptTopError)(PME_Error)) */

PME_Start PME_visitStart(PME_Start arg, PME_OptLayout (*acceptWsBefore)(PME_OptLayout), PME_Area (*acceptTopArea)(PME_Area), PME_OptLayout (*acceptWsAfter)(PME_OptLayout), int (*acceptAmbCnt)(int), PME_Location (*acceptTopLocation)(PME_Location), PME_Feedback (*acceptTopFeedback)(PME_Feedback), PME_Description (*acceptTopDescription)(PME_Description), PME_Producer (*acceptTopProducer)(PME_Producer), PME_Information (*acceptTopInformation)(PME_Information), PME_Warning (*acceptTopWarning)(PME_Warning), PME_FatalError (*acceptTopFatalError)(PME_FatalError), PME_Error (*acceptTopError)(PME_Error))
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
  if (PME_isStartFeedback(arg)) {
    return PME_makeStartFeedback(
        acceptWsBefore ? acceptWsBefore(PME_getStartWsBefore(arg)) : PME_getStartWsBefore(arg),
        acceptTopFeedback ? acceptTopFeedback(PME_getStartTopFeedback(arg)) : PME_getStartTopFeedback(arg),
        acceptWsAfter ? acceptWsAfter(PME_getStartWsAfter(arg)) : PME_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(PME_getStartAmbCnt(arg)) : PME_getStartAmbCnt(arg));
  }
  if (PME_isStartDescription(arg)) {
    return PME_makeStartDescription(
        acceptWsBefore ? acceptWsBefore(PME_getStartWsBefore(arg)) : PME_getStartWsBefore(arg),
        acceptTopDescription ? acceptTopDescription(PME_getStartTopDescription(arg)) : PME_getStartTopDescription(arg),
        acceptWsAfter ? acceptWsAfter(PME_getStartWsAfter(arg)) : PME_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(PME_getStartAmbCnt(arg)) : PME_getStartAmbCnt(arg));
  }
  if (PME_isStartProducer(arg)) {
    return PME_makeStartProducer(
        acceptWsBefore ? acceptWsBefore(PME_getStartWsBefore(arg)) : PME_getStartWsBefore(arg),
        acceptTopProducer ? acceptTopProducer(PME_getStartTopProducer(arg)) : PME_getStartTopProducer(arg),
        acceptWsAfter ? acceptWsAfter(PME_getStartWsAfter(arg)) : PME_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(PME_getStartAmbCnt(arg)) : PME_getStartAmbCnt(arg));
  }
  if (PME_isStartInformation(arg)) {
    return PME_makeStartInformation(
        acceptWsBefore ? acceptWsBefore(PME_getStartWsBefore(arg)) : PME_getStartWsBefore(arg),
        acceptTopInformation ? acceptTopInformation(PME_getStartTopInformation(arg)) : PME_getStartTopInformation(arg),
        acceptWsAfter ? acceptWsAfter(PME_getStartWsAfter(arg)) : PME_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(PME_getStartAmbCnt(arg)) : PME_getStartAmbCnt(arg));
  }
  if (PME_isStartWarning(arg)) {
    return PME_makeStartWarning(
        acceptWsBefore ? acceptWsBefore(PME_getStartWsBefore(arg)) : PME_getStartWsBefore(arg),
        acceptTopWarning ? acceptTopWarning(PME_getStartTopWarning(arg)) : PME_getStartTopWarning(arg),
        acceptWsAfter ? acceptWsAfter(PME_getStartWsAfter(arg)) : PME_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(PME_getStartAmbCnt(arg)) : PME_getStartAmbCnt(arg));
  }
  if (PME_isStartFatalError(arg)) {
    return PME_makeStartFatalError(
        acceptWsBefore ? acceptWsBefore(PME_getStartWsBefore(arg)) : PME_getStartWsBefore(arg),
        acceptTopFatalError ? acceptTopFatalError(PME_getStartTopFatalError(arg)) : PME_getStartTopFatalError(arg),
        acceptWsAfter ? acceptWsAfter(PME_getStartWsAfter(arg)) : PME_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(PME_getStartAmbCnt(arg)) : PME_getStartAmbCnt(arg));
  }
  if (PME_isStartError(arg)) {
    return PME_makeStartError(
        acceptWsBefore ? acceptWsBefore(PME_getStartWsBefore(arg)) : PME_getStartWsBefore(arg),
        acceptTopError ? acceptTopError(PME_getStartTopError(arg)) : PME_getStartTopError(arg),
        acceptWsAfter ? acceptWsAfter(PME_getStartWsAfter(arg)) : PME_getStartWsAfter(arg),
        acceptAmbCnt ? acceptAmbCnt(PME_getStartAmbCnt(arg)) : PME_getStartAmbCnt(arg));
  }
  ATabort("not a Start: %t\n", arg);
  return (PME_Start)NULL;
}

/*}}}  */
/*{{{  PME_OptLayout PME_visitOptLayout(PME_OptLayout arg, PME_CHARLIST (*acceptChars)(PME_CHARLIST)) */

PME_OptLayout PME_visitOptLayout(PME_OptLayout arg, PME_CHARLIST (*acceptChars)(PME_CHARLIST))
{
  if (PME_isOptLayoutAbsent(arg)) {
    return PME_makeOptLayoutAbsent();
  }
  if (PME_isOptLayoutPresent(arg)) {
    return PME_makeOptLayoutPresent(
        acceptChars ? acceptChars(PME_getOptLayoutChars(arg)) : PME_getOptLayoutChars(arg));
  }
  ATabort("not a OptLayout: %t\n", arg);
  return (PME_OptLayout)NULL;
}

/*}}}  */

/*}}}  */
