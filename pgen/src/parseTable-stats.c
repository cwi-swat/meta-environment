/* $Id$ */

/** \file
 * Statistics logging for parse table generation.
 */
#include <rsrc-usage.h>

#include "parseTable-stats.h"
#include "parseTable-data.h"

unsigned int PGEN_STATS_actions = 0; /**> number of actions in parse table. */
unsigned int PGEN_STATS_gotos = 0;   /**> number of gotos in parse table. */
unsigned int PGEN_STATS_items = 0;   /**> number of items in parse table. */

unsigned int PGEN_STATS_maxActionsInStates = 0; /** max number of actions in 
                                                 * any state. */
unsigned int PGEN_STATS_maxGotosInState = 0; /** max number of gotos in any 
                                              * state. */
unsigned int PGEN_STATS_maxItemsInState = 0; /** max number of items in any 
                                              * state. */
int PGEN_STATS_userRejects = 0;
int PGEN_STATS_userPrefers = 0;
int PGEN_STATS_userAvoids = 0;
int PGEN_STATS_userNoAttributes = 0;

int PGEN_STATS_userProductions = 0;
int PGEN_STATS_kernelProductions = 0;
int PGEN_STATS_maxUserProductionLhsLength = 0;
int PGEN_STATS_maxProductionLhsLength = 0;

int PGEN_STATS_conficts = 0;
unsigned int PGEN_STATS_reductions = 0;
unsigned int PGEN_STATS_shifts = 0;
unsigned int PGEN_STATS_followRestrictedReductions = 0;
int PGEN_STATS_priorities = 0;

double PGEN_STATS_normalizationTime = 0.0;
double PGEN_STATS_generationTime = 0.0;

/** 
 * This is probably not necessary any more.
 */
void PGEN_STATS_initialize(void) {
;
}

static FILE  *openLog(const char *fnam) {
  FILE *log = NULL;

  if (!fnam || !strcmp(fnam, "")) {
    ATerror("Cannot create logfile without a filename\n", fnam);
  }

  if (!(log = fopen(fnam, "wb"))) {
    ATerror("Cannot create logfile %s\n", fnam);
  }

  return log;
}

static void closeLog(FILE *logFile) {
  if(logFile) {
    fclose(logFile);
  }
}


void PGEN_STATS_print(void) {
  FILE *logFile;
  int numberOfStates = PGEN_getNumberOfStates();

  if (PGEN_getVerboseModeFlag) {
    ATwarning("Logging statistics\n");
  }

  logFile = openLog(PGEN_getStatsFileName());
  
  fprintf(logFile, "int user-productions = %d\n", PGEN_STATS_userProductions);
/*  fprintf(logFile, "int conflicts = %d\n", );
  fprintf(logFile, "int reductions = %d\n", );
  fprintf(logFile, "int shifts = %d\n", );
  fprintf(logFile, "int followRestrictedReductions = %d\n", );
*/

  fprintf(logFile, "int user-rejects = %d\n", PGEN_STATS_userRejects);
  fprintf(logFile, "int user-prefers = %d\n", PGEN_STATS_userPrefers);
  fprintf(logFile, "int user-avoids = %d\n", PGEN_STATS_userAvoids);
  fprintf(logFile, "int user-no-attributes = %d\n", PGEN_STATS_userNoAttributes);


  fprintf(logFile, "int states = %u\n", numberOfStates);
  fprintf(logFile, "int items = %u\n", PGEN_STATS_items);
  fprintf(logFile, "int gotos = %u\n", PGEN_STATS_gotos);
  fprintf(logFile, "int actions = %u\n\n", PGEN_STATS_actions);

  fprintf(logFile, "int max-number-of-items-in-states = %u\n", PGEN_STATS_maxItemsInState);
  fprintf(logFile, "int max-number-of-gotos-in-states = %u\n", PGEN_STATS_maxGotosInState);
  fprintf(logFile, "int max-number-of-actions-in-states = %u\n\n", PGEN_STATS_maxActionsInStates);

  fprintf(logFile, "%%%% items/states = %d\n", (PGEN_STATS_items/numberOfStates));
  fprintf(logFile, "%%%% gotos/state = %d\n", (PGEN_STATS_gotos/numberOfStates));
  fprintf(logFile, "%%%% actions/states = %d\n\n", (PGEN_STATS_actions/numberOfStates));

  fprintf(logFile, "%%%% Normalization-to-Kernel-Sdf = %.6fs\n", PGEN_STATS_normalizationTime);
  fprintf(logFile, "%%%% Parse-table-generation = %.6fs\n", PGEN_STATS_generationTime); 
  fprintf(logFile, "int kernel-productions = %d\n", PGEN_STATS_kernelProductions);
  fprintf(logFile, "int max-user-production-left-hand-side-length = %d\n", PGEN_STATS_maxUserProductionLhsLength);
  fprintf(logFile, "int max-production-left-hand-side-length = %d\n", PGEN_STATS_maxProductionLhsLength);
  fprintf(logFile, "%%%% production-lhs-length/kernel-productions = %d\n", (PGEN_STATS_maxProductionLhsLength/PGEN_STATS_kernelProductions));

  fprintf(logFile, "int priorities = %d\n", PGEN_STATS_priorities);

  closeLog(logFile);

}

