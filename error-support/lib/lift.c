#include "Errors.h"
#include "ParsedErrors.h"


/*{{{  PME_Producer ME_liftProducer(ME_Producer producer)  */

PME_Producer ME_liftProducer(ME_Producer producer) 
{
  PME_OptLayout e = PME_makeOptLayoutAbsent();
  char *id = ME_getProducerId(producer);
  char *type = ME_getProducerType(producer);

  return PME_makeProducerProducer(e,e,
				  PME_makeStringString(id),
				  e,e,
				  PME_makeStringString(type),
				  e);
}

/*}}}  */
/*{{{  PME_Description ME_liftDescription(ME_Description description) */

PME_Description ME_liftDescription(ME_Description description)
{
  PME_OptLayout e = PME_makeOptLayoutAbsent();
  char *str = ME_getDescriptionString(description);

  return PME_makeDescriptionDescription(e,e,
					PME_makeStringString(str),
					e);

}

/*}}}  */
/*{{{  PME_Subjects ME_liftSubjects(ME_Subjects subjects) */

PME_Subjects ME_liftSubjects(ME_Subjects subjects)
{
  ATerror("not yet implemented");
}

/*}}}  */

/*{{{  PME_Information ME_liftFeedbackInfo(ME_Information info) */

PME_Information ME_liftFeedbackInfo(ME_Information info)
{
  char *id;
  ME_Producer producer;
  ME_Description description;
  ME_Subjects subjects;
  PME_String pid;
  PME_Producer pproducer;
  PME_Description pdescription;
  PME_Subjects psubjects;
  PME_OptLayout e = PME_makeOptLayoutAbsent();

  id = ME_getInformationId(info);
  producer = ME_getInformationProducer(info);
  description = ME_getInformationDescription(info);
  subjects = ME_getInformationSubjects(info);

  pid = PME_makeStringString(id);
  pproducer = ME_liftProducer(producer);
  pdescription = ME_liftDescription(description);
  psubjects = ME_liftSubjects(subjects);

  return PME_makeInformationInformation(e,e,
					pid,
					e,e,
					pproducer,
					e,e,
					pdescription,
					e,e,
					psubjects,
					e);
}

/*}}}  */
/*{{{  PME_Warning ME_liftFeedbackWarning(ME_Warning warning) */

PME_Warning ME_liftFeedbackWarning(ME_Warning warning)
{
  char *id;
  ME_Producer producer;
  ME_Description description;
  ME_Subjects subjects;
  PME_String pid;
  PME_Producer pproducer;
  PME_Description pdescription;
  PME_Subjects psubjects;
  PME_OptLayout e = PME_makeOptLayoutAbsent();

  id = ME_getWarningId(warning);
  producer = ME_getWarningProducer(warning);
  description = ME_getWarningDescription(warning);
  subjects = ME_getWarningSubjects(warning);

  pid = PME_makeStringString(id);
  pproducer = ME_liftProducer(producer);
  pdescription = ME_liftDescription(description);
  psubjects = ME_liftSubjects(subjects);

  return PME_makeWarningWarning(e,e,
				pid,
				e,e,
				pproducer,
				e,e,
				pdescription,
				e,e,
				psubjects,
				e);
}

/*}}}  */
/*{{{  PME_Error ME_liftFeedbackError(ME_Error error) */

PME_Error ME_liftFeedbackError(ME_Error error)
{
  char *id;
  ME_Producer producer;
  ME_Description description;
  ME_Subjects subjects;
  PME_String pid;
  PME_Producer pproducer;
  PME_Description pdescription;
  PME_Subjects psubjects;
  PME_OptLayout e = PME_makeOptLayoutAbsent();

  id = ME_getErrorId(error);
  producer = ME_getErrorProducer(error);
  description = ME_getErrorDescription(error);
  subjects = ME_getErrorSubjects(error);

  pid = PME_makeStringString(id);
  pproducer = ME_liftProducer(producer);
  pdescription = ME_liftDescription(description);
  psubjects = ME_liftSubjects(subjects);

  return PME_makeErrorError(e,e,
			    pid,
			    e,e,
			    pproducer,
			    e,e,
			    pdescription,
			    e,e,
			    psubjects,
			    e);
}

/*}}}  */
/*{{{  PME_FatalError ME_liftFeedbackFatalError(ME_FatalError fatalError) */

PME_FatalError ME_liftFeedbackFatalError(ME_FatalError fatalError)
{
  char *id;
  ME_Producer producer;
  ME_Description description;
  ME_Subjects subjects;
  PME_String pid;
  PME_Producer pproducer;
  PME_Description pdescription;
  PME_Subjects psubjects;
  PME_OptLayout e = PME_makeOptLayoutAbsent();

  id = ME_getFatalErrorId(fatalError);
  producer = ME_getFatalErrorProducer(fatalError);
  description = ME_getFatalErrorDescription(fatalError);
  subjects = ME_getFatalErrorSubjects(fatalError);

  pid = PME_makeStringString(id);
  pproducer = ME_liftProducer(producer);
  pdescription = ME_liftDescription(description);
  psubjects = ME_liftSubjects(subjects);

  return PME_makeFatalErrorFatalError(e,e,
				      pid,
				      e,e,
				      pproducer,
				      e,e,
				      pdescription,
				      e,e,
				      psubjects,
				      e);
}

/*}}}  */

/*{{{  PME_Feedback ME_liftFeedback(ME_Feedback feedback) */

PME_Feedback ME_liftFeedback(ME_Feedback feedback)
{
  if (ME_isFeedbackInfo(feedback)) {
    ME_Information info = ME_getFeedbackInformation(feedback);
    return PME_makeFeedbackInfo(ME_liftFeedbackInfo(info));
  }
  else if (ME_isFeedbackWarning(feedback)) {
    ME_Warning warning = ME_getFeedbackWarning(feedback);
    return PME_makeFeedbackWarning(ME_liftFeedbackWarning(warning));
  }
  else if (ME_isFeedbackError(feedback)) {
    ME_Error error = ME_getFeedbackError(feedback);
    return PME_makeFeedbackError(ME_liftFeedbackError(error));
  }
  else if (ME_isFeedbackFatalError(feedback)) {
    ME_FatalError fatalError = ME_getFeedbackFatalError(feedback);
    return PME_makeFeedbackFatalError(ME_liftFeedbackFatalError(fatalError));
  }
  else {
    ATerror("unknown feedback type: %t\n", feedback);
    return NULL;
  }
}
