/*$Id$*/

#include "sglrInterface.h"
#include "commandLineInterface.h"
#include "toolbusInterface.h"
#include "filters.h"
#include "mainOptions.h" 
#include "parserStatistics.h"

#include "ptable.h"
#include <aterm1.h>
#include <MEPT-utils.h>
#include <Error-utils.h>
#include <rsrc-usage.h>

int main(int argc, char *argv[]) {
  int result = 0;
  ATerm bottomOfStack;
  char* atargs[6];
  int useToolbus = 0;
  int i = 0;

  atargs[0] = argv[0];
  atargs[1] = "-at-termtable"; 
  atargs[2] = "18";
  atargs[3] = "-at-afuntable";
  atargs[4] = "15";
  atargs[5] = "-at-silent";
  /*atargs[5] = "-at-verbose";*/

  /* The main options haven't been set yet so we can't check if we're doing the 
   * stats. */
  SGLR_STATS_initialMRSS = STATS_ResidentSetSize();

  ATinit(6, atargs, &bottomOfStack);
  /* Set to debug ATerms.*/
  /*ATsetChecking(ATtrue);*/
  SGLR_initialize();
  
  SGLR_STATS_setCount(SGLR_STATS_initialMemAllocated, STATS_Allocated());

  for (i=1; !useToolbus && i < argc; i++) {
    useToolbus = !strcmp(argv[i], "-TB_TOOL_NAME");
  }

  if (useToolbus) {
    runTool(&bottomOfStack, argc, argv);
  }
  else {
    result =  runCommandLineTool(argc, argv);
  }

  SGLR_STATS_setCount(SGLR_STATS_endMRSS, STATS_ResidentSetSize());

  return result;
}
