/*$Id$*/

/** \file 
 * \ingroup parseTable
 */

#include "parseTableBuilder.h"
#include "ptable.h"
#include "parserOptions.h"
#include "mainOptions.h"
#include "parserStatistics.h"

#include <rsrc-usage.h>
#include <Error-manager.h>

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
  int                nrOfStates;
  ERR_Subject subject;
  static char subjectDescription[1024];
  static char errorDescription[1024];

  if (!PTBL_isValidParseTable(extParseTable)) { 
    if (PARSER_getVerboseFlag) {
      ATwarning("Parse table format error\n");
    }

    sprintf(errorDescription, "Parse table format error");
    sprintf(subjectDescription, "parse table");
    if (!strcmp(path, "ToolBusParseTable")) {
      subject = ERR_makeSubjectSubject(subjectDescription);
    }
    else {
      subject = ERR_makeSubjectLocalized(subjectDescription, ERR_makeLocationFile(path));
    }
    ERR_managerStoreError(errorDescription, ERR_makeSubjectListSingle(subject));

    extParseTable = NULL;
    return NULL;
  }

  version = PTBL_getParseTableVersion(extParseTable);

  if (!PTBL_isValidVersion(version)) {
    if (PARSER_getVerboseFlag) {
      ATwarning("Invalid parse table version\n");
    }

    sprintf(errorDescription, "Invalid parse table version");
    sprintf(subjectDescription, "parse table");
    if (!strcmp(path, "ToolBusParseTable")) {
      subject = ERR_makeSubjectSubject(subjectDescription);
    }
    else {
      subject = ERR_makeSubjectLocalized(subjectDescription, ERR_makeLocationFile(path));
    }
    ERR_managerStoreError(errorDescription, ERR_makeSubjectListSingle(subject));

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
    if (PARSER_getVerboseFlag) {
      ATwarning("No start state defined\n");
    }

    sprintf(errorDescription, "No start state defined");
    sprintf(subjectDescription, "parse table");
    if (!strcmp(path, "ToolBusParseTable")) {
      subject = ERR_makeSubjectSubject(subjectDescription);
    }
    else {
      subject = ERR_makeSubjectLocalized(subjectDescription, ERR_makeLocationFile(path));
    }
    ERR_managerStoreError(errorDescription, ERR_makeSubjectListSingle(subject));
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

    SGLR_STATS_setCount(SGLR_STATS_beforeParseTableCreationMRSS, STATS_ResidentSetSize());
  
    pt = SGLR_PTBL_initializeParseTable(startState, 
        PTBL_getStatesLength(states), 
        PTBL_getLabelsLength(prods), 
        action_entries, 
        goto_entries, 
        path);

    SGLR_STATS_setCount(SGLR_STATS_emptyParseTableMemAllocated, STATS_Allocated());
    SGLR_STATS_setCount(SGLR_STATS_emptyParseTableMRSS, STATS_ResidentSetSize());

    SGLR_PTBL_fillParseTable(pt, states);
    states = NULL;
    SGLR_PTBL_processProductions(pt, prods);
    prods = NULL;
  
    if (!PTBL_isPrioritiesEmpty(prios)) {
      SGLR_PTBL_processPriorities(pt, prios);
      prios = NULL;
    } else {
      if (PARSER_getVerboseFlag) {
        ATwarning("warning: no priority information in parse table\n");
      }
    }

    SGLR_STATS_setCount(SGLR_STATS_rejects, SGLR_PTBL_hasRejects(pt));
    SGLR_STATS_setCount(SGLR_STATS_priorities, SGLR_PTBL_hasPriorities(pt));
    SGLR_STATS_setCount(SGLR_STATS_prefers, SGLR_PTBL_hasPrefers(pt));
    SGLR_STATS_setCount(SGLR_STATS_avoids, SGLR_PTBL_hasAvoids(pt));
    SGLR_STATS_setCount(SGLR_STATS_fullParseTableMemAllocated, STATS_Allocated());
    SGLR_STATS_setCount(SGLR_STATS_fullParseTableMRSS, STATS_ResidentSetSize());

    return pt;
  }
}

