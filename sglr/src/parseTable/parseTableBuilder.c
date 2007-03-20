/*$Id$*/

/** \file 
 * \ingroup parseTable
 */

#include "parseTableBuilder.h"
#include "ptable.h"
#include "parserOptions.h"

#include <rsrc-usage.h>
#include <logging.h>

/** 
 * Translate ATerm representation of parse table into internal parse table 
 * data structure.
 */
ParseTable *SG_BuildParseTable(PTBL_ParseTable extParseTable, const char *path) {
  PTBL_Labels          prods;
  PTBL_States          states;
  register PTBL_Priorities prios;
  register PTBL_States sts; 
  int                startState;
  PTBL_Version       version;
  ParseTable         *pt = NULL;
  size_t             goto_entries = 0;
  size_t             action_entries = 0;
  long               maxrss = 0;
  long               allocated;
  int                nrOfStates;

  SGLR_PTBL_initErrorList(); 

  if (!PTBL_isValidParseTable(extParseTable)) { 
    if (PARSER_getVerboseFlag() == ATtrue) {
      ATwarning("Parse table format error\n");
    }
    SGLR_PTBL_addErrorError(path, "Parse table format error");
    extParseTable = NULL;
    return NULL;
  }

  version = PTBL_getParseTableVersion(extParseTable);

  if (!PTBL_isValidVersion(version)) {
    if (PARSER_getVerboseFlag() == ATtrue) {
      ATwarning("Invalid parse table version\n");
    }
    SGLR_PTBL_addErrorError(path, "Invalid parse table version");
    extParseTable = NULL;
    return NULL;
  }

  startState = PTBL_getParseTableInitialState(extParseTable);
  prods         = PTBL_getParseTableLabels(extParseTable);
  states        = PTBL_getParseTableStates(extParseTable);
  prios         = PTBL_getParseTablePriorities(extParseTable);
  extParseTable = NULL;

  nrOfStates = PTBL_getStatesLength(states);

  if (nrOfStates == 2 &&
      PTBL_isChoicesEmpty(PTBL_getStateChoices(PTBL_getStatesHead(states))) &&
      PTBL_isChoicesEmpty(PTBL_getStateChoices(PTBL_getStatesHead(PTBL_getStatesTail(states))))) {
    if (PARSER_getVerboseFlag() == ATtrue) {
      ATwarning("No start state defined\n");
    }
    SGLR_PTBL_addErrorError(path, "No start state defined");
    return NULL;
  }
  else {
    for (sts=states; !PTBL_isStatesEmpty(sts); sts=PTBL_getStatesTail(sts)) {
      PTBL_State curstate = PTBL_getStatesHead(sts);
      if (PTBL_isStateDefault(curstate)) {
        PTBL_Gotos gotos     = PTBL_getStateGotos(curstate);
        PTBL_Choices choices = PTBL_getStateChoices(curstate);

        goto_entries += SGLR_PTBL_countGotos(gotos);
        action_entries += SGLR_PTBL_countChoices(choices);
      }
    }

    /** \todo Stats should be passed on to parseTableBuilder from the parser.*/
    if (PARSER_getStatsFlag() == ATtrue) {
      maxrss = STATS_ResidentSetSize();
    }
  
    pt = SGLR_PTBL_initializeParseTable(startState, 
        PTBL_getStatesLength(states), 
        PTBL_getLabelsLength(prods), 
        action_entries, 
        goto_entries, 
        path);

    if (PARSER_getStatsFlag() == ATtrue) {
      allocated = STATS_Allocated();
      if (allocated > 0) {
        fprintf(LOG_log(), 
		"[mem] extra ATerm memory allocated for empty table: %ld\n",
                allocated);
      }
      if (maxrss) {
        fprintf(LOG_log(), 
		"[mem] PT build: %ld before, %ld after table creation\n",
                maxrss, STATS_ResidentSetSize());
      }
      maxrss = STATS_ResidentSetSize();
    }

    SGLR_PTBL_fillParseTable(pt, states);
    states = NULL;
    SGLR_PTBL_processProductions(pt, prods);
    prods = NULL;
  
    if (!PTBL_isPrioritiesEmpty(prios)) {
      SGLR_PTBL_processPriorities(pt, prios);
      prios = NULL;
    } else {
      if (PARSER_getVerboseFlag() == ATtrue) {
        ATwarning("warning: no priority information in parse table\n");
      }
    }

    if (PARSER_getStatsFlag() == ATtrue) {
      fprintf(LOG_log(), "%scludes rejects\n",
          SGLR_PTBL_hasRejects(pt)?"In":"Ex");
      fprintf(LOG_log(), "%scludes priorities\n",
	      SGLR_PTBL_hasPriorities(pt)?"In":"Ex");
      fprintf(LOG_log(), "%scludes prefer actions\n",
	      SGLR_PTBL_hasPrefers(pt)   ?"In":"Ex");
      fprintf(LOG_log(), "%scludes avoid actions\n",
	      SGLR_PTBL_hasAvoids(pt)    ?"In":"Ex");
      allocated = STATS_Allocated();
      if (allocated > 0) {
        fprintf(LOG_log(), 
		"[mem] extra ATerm memory allocated while filling table: %ld\n",
                allocated);
      }
      if (maxrss) {
        fprintf(LOG_log(), 
		"[mem] PT build: %ld before, %ld after filling table\n",
                maxrss, STATS_ResidentSetSize());
      }
    }

    return pt;
  }
}

