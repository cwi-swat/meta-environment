#include "Errors-utils.h"

void ME_initFullErrorsApi() 
{
  ME_initErrorsApi();
  PME_initParsedErrorsApi();
}
