#include <string.h>
#include <stdlib.h>

#include "error.h"
#include "evaluator.h"

#include <aterm2.h>
#include <MEPT-utils.h>

ATerm rewriteError = NULL;

/* Error registration */
/*{{{  void RWclearError() */

void RWclearError()
{
  static ATbool is_protected = ATfalse;

  if (!is_protected) {
    is_protected = ATtrue;
    rewriteError = NULL;
    ATprotect(&rewriteError);
  }

  rewriteError = NULL;
}

/*}}}  */
/*{{{  void RWsetError(const char *message, ATerm subject) */

void RWsetError(const char *message, ATerm subject)
{
  if (rewriteError == NULL) {
    RWclearError();		
    rewriteError = ATmake("[<str>,<term>,<term>])",
			   message, tagCurrentRule,
			   subject);
  }

  aborted = ATtrue;
}

/*}}}  */
/*{{{  ATerm RWgetError() */

ATerm RWgetError()
{
  return rewriteError;
}

/*}}}  */
      
void printErrors(void)
{
  ATerm message, tag, subject;
  char *tagText, *subjectText;
  ATermList error;

  /* The errors are tuples containing a message and a subject */
  error = (ATermList) RWgetError();
  message = ATgetFirst(error);
  tag = ATgetFirst(ATgetNext(error));
  subject = ATgetFirst(ATgetNext(ATgetNext(error)));

  tagText = strdup(PT_yieldTree(PT_makeTreeFromTerm(tag)));
  subjectText = strdup(PT_yieldTree(PT_makeTreeFromTerm(subject)));

  if(tagText != NULL &&
     subjectText != NULL) {
    ATwarning("%t (%s, %s)\n", message, tagText, subjectText);

  }
  else {
    ATwarning("Unable to show error message (no memory).\n");
  }

  free(tagText);
  free(subjectText);
}
