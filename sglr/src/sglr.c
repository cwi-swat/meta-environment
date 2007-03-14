/*$Id$*/

#include "sglrInterface.h"
#include "commandLineInterface.h"
#include "toolbusInterface.h"
#include "filters.h"
#include "parserOptions.h" /** \todo Stats maybe go in the main options? */

#include "ptable.h"
#include <aterm1.h>
#include <MEPT-utils.h>
#include <Error-utils.h>
#include <rsrc-usage.h>
#include <logging.h>

int main(int argc, char *argv[]) {
  int result = 0;
  ATerm bottomOfStack;
  char* atargs[5];
  long maxResidentSize = 0L;
  int useToolbus = 0;
  int i = 0;

  atargs[0] = argv[0];
  atargs[1] = "-at-termtable"; 
  atargs[2] = "18";
  atargs[3] = "-at-afuntable";
  atargs[4] = "15";
  atargs[5] = "-at-silent";
  /*atargs[5] = "-at-verbose";*/

  maxResidentSize = STATS_ResidentSetSize();

  ATinit(6, atargs, &bottomOfStack);
  /* Set to debug ATerms.*/
  /*ATsetChecking(ATtrue);*/
  SGLR_initialize();
  
  for (i=1; !useToolbus && i < argc; i++) {
    useToolbus = !strcmp(argv[i], "-TB_TOOL_NAME");
  }

  if (useToolbus) {
    runTool(&bottomOfStack, argc, argv);
  }
  else {
    result =  runCommandLineTool(argc, argv);

    if (PARSER_getStatsFlag() == ATtrue) {
      fprintf(LOG_log(), "[mem] initial ATerm memory: %ld\n",STATS_Allocated());
      if(maxResidentSize) {
	fprintf(LOG_log(), "[mem] ATerm init: %ld before, %ld after\n",
	    maxResidentSize, STATS_ResidentSetSize());
      }
    }
  }

  return result;
}
