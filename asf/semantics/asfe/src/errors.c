/* $Id$ */

#include <string.h>
#include <stdlib.h>

#include "errors.h"
#include "evaluator.h"

#include <aterm2.h>
#include <MEPT-utils.h>
#include <Error-utils.h>

ERR_ErrorList errors = NULL;


void RWclearErrors() {
  static ATbool is_protected = ATfalse;

  if (!is_protected) {
    is_protected = ATtrue;
    errors = NULL;
    ERR_protectErrorList(&errors);
  }

  errors = NULL;
}


ERR_ErrorList RWgetErrors() {
  return errors;
}

int RWgetErrorCount() {
  if (errors != NULL) {
    return ERR_getErrorListLength(errors);
  }
  else {
    return 0;
  }
}


void RWaddError(char *msg, char *subject) {
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


void RWaddLocatedError(char *msg, char *subject, ERR_Location loc) {
  ERR_Subject sub = ERR_makeSubjectLocalized(subject, (ERR_Location) loc); 
  ERR_Error error = ERR_makeErrorError(msg, ERR_makeSubjectListSingle(sub));

  if (errors == NULL) {
    RWclearErrors();
    errors = ERR_makeErrorListSingle(error);
  }
  else {
    errors = ERR_makeErrorListMany(error, errors);
  }
}


void RWaddDoubleLocatedError(char *msg, char *subject1, ERR_Location loc1, char *subject2, ERR_Location loc2) {
  ERR_Subject sub1 = ERR_makeSubjectLocalized(subject1, (ERR_Location) loc1); 
  ERR_Subject sub2 = ERR_makeSubjectLocalized(subject2, (ERR_Location) loc2); 
  ERR_Error error = ERR_makeErrorError(msg, ERR_makeSubjectList2(sub1,sub2));

  if (errors == NULL) {
    RWclearErrors();
    errors = ERR_makeErrorListSingle(error);
  }
  else {
    errors = ERR_makeErrorListMany(error, errors);
  }
}


void printErrors(void) {
  ERR_ErrorList runner = errors;
  ERR_Summary summary = ERR_makeSummarySummary("asfe","cmdline", runner);

  ERR_fdisplaySummary(stderr, summary);
}

