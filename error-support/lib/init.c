#include "ErrorAPI-utils.h"
#include "ErrorAPI.h"
#include "ParsedErrorAPI.h"

void ERR_initErrorApi() 
{
  ERR_initErrorAPIApi();
  PERR_initParsedErrorAPIApi();
}
