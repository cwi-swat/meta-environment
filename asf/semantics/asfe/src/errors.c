#include <string.h>
#include <stdlib.h>

#include "errors.h"
#include "evaluator.h"

#include <aterm2.h>
#include <MEPT-utils.h>
#include <ErrorAPI.h>

ERR_FeedbackList errors = NULL;

/*{{{  void RWclearError() */

void RWclearErrors()
{
  static ATbool is_protected = ATfalse;

  if (!is_protected) {
    is_protected = ATtrue;
    errors = NULL;
    ERR_protectFeedbackList(errors);
  }

  errors = NULL;
}

/*}}}  */
/*{{{  ERR_FeedbackList RWgetError() */

ERR_FeedbackList RWgetErrors()
{
  return errors;
}

/*}}}  */
     
/*{{{  void RWaddError(ERR_Feedback error)  */

void RWaddError(char *msg, char *subject)
{
  ERR_Subject sub = ERR_makeSubjectSubject(subject, 
					   ERR_makeLocationNoLocation());
  ERR_Feedback error = ERR_makeFeedbackError(msg,
					     ERR_makeSubjectListSingle(sub));

  if (errors == NULL) {
    RWclearErrors();
    errors = ERR_makeFeedbackListSingle(error);
  }
  else {
    errors = ERR_makeFeedbackListMany(error, errors);
  }
}

/*}}}  */

/*{{{  void printErrors(void) */

void printErrors(void)
{
  ERR_FeedbackList runner = errors;

  for ( ; !ERR_isFeedbackListEmpty(runner); 
	runner = ERR_getFeedbackListTail(runner)) {
    ERR_Feedback error = ERR_getFeedbackListHead(runner);

    ATwarning("error: %t\n", error);
  }

}

/*}}}  */
