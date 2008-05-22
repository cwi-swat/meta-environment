#include <Error-utils.h>

void ERR_countErrors(ERR_Summary summary, int *num_errors, int *num_warnings, int *num_infos, int *num_fatal)
{
  *num_errors = *num_warnings = *num_infos = *num_fatal = 0;

  ERR_ErrorList errors = ERR_getSummaryList(summary);
  
  while (!ERR_isErrorListEmpty(errors)) {
    ERR_Error error = ERR_getErrorListHead(errors);

    if (ERR_isErrorError(error)) {
      (*num_errors)++;
    }
    else if (ERR_isErrorWarning(error)) {
      (*num_warnings)++;
    }
    else if (ERR_isErrorInfo(error)) {
      (*num_infos)++;
    }
    else if (ERR_isErrorFatal(error)) {
      (*num_fatal)++;
    }
    else {
      ATwarning("Unknown type of error: %t\n", error);
    }
    
    errors = ERR_getErrorListTail(errors);
  }
}
