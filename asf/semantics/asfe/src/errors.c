#include <string.h>
#include <stdlib.h>

#include "errors.h"
#include "evaluator.h"

#include <aterm2.h>
#include <MEPT-utils.h>
#include <Error.h>

ERR_ErrorList errors = NULL;

/*{{{  void RWclearError() */

void RWclearErrors()
{
  static ATbool is_protected = ATfalse;

  if (!is_protected) {
    is_protected = ATtrue;
    errors = NULL;
    ERR_protectErrorList(&errors);
  }

  errors = NULL;
}

/*}}}  */
/*{{{  ERR_ErrorList RWgetErrors() */

ERR_ErrorList RWgetErrors()
{
  return errors;
}

/*}}}  */
     
/*{{{  void RWaddError(ERR_Feedback error)  */

void RWaddError(char *msg, char *subject)
{
  ERR_Subject sub = ERR_makeSubjectSubject(subject); 
  ERR_Error error = ERR_makeErrorError(msg, ERR_makeSubjectListSingle(sub));

  if (errors == NULL) {
    RWclearErrors();
    errors = ERR_makeErrorListSingle(error);
  }
  else {
    errors = ERR_makeErrorListMany(error, errors);
  }
}

/*}}}  */

/*{{{  void printErrors(void) */

void printErrors(void)
{
  ERR_ErrorList runner = errors;

  while (!ERR_isErrorListEmpty(runner)) {
    ERR_Error error = ERR_getErrorListHead(runner);

    ATwarning("error: %t\n", error);
    runner = ERR_getErrorListTail(runner);
  }

}

/*}}}  */
