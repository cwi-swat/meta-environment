/*  $Id$  */

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include <aterm1.h>
#include <atb-tool.h>
#include <MEPT-utils.h>
#include <Error-utils.h>
#include <Error-manager.h>
#include <rsrc-usage.h>
#include <options.h>
#include <filterOptions.h>

#include "sglrInterface.h"

#include "mem-alloc.h"
#include "parser.h"
#include "parseTableBuilder.h"
#include "parseTableDB.h"
#include "filters.h"
#include "ambi-tables.h"
#include "inputString-api.h"

#include "mainOptions.h"
#include "parserOptions.h"
#include "sglr-termstore.h"
#include "parserStatistics.h"

static ATbool initialized = ATfalse;

void SGLR_initialize() {
  
  if (!initialized) {
    initErrorApi();
    SGLR_PTBL_initErrorList();
    ERR_cleanupErrorManager();  
    ERR_initErrorManager("parser", "sglr");

    PT_initMEPTApi();
    PT_initAsFix2Api();
    PTBL_initPtableApi();

    OPT_initialize(200);
    PARSER_initializeDefaultOptions();
    FLT_initializeDefaultOptions();
    MAIN_initializeDefaultOptions();
    SGLR_TS_create();

    initialized = ATtrue;
  }
}

ATbool SGLR_isInitialized() {
  return initialized;
}

/* Convert an ATerm parse table to the internal format and cache it using the 
 * |parseTableName|.
 */
int SGLR_loadParseTable(const char *parseTableName, PTBL_ParseTable parseTable) {
  ParseTable *internalParseTable = NULL;

  if (MAIN_getStatsFlag) { STATS_Timer(); }
  internalParseTable = SG_BuildParseTable(parseTable, parseTableName);
  if (MAIN_getStatsFlag) { SGLR_STATS_parseTableTime = STATS_Timer(); }

  if (internalParseTable != NULL) {
    SG_CacheParseTable(parseTableName, internalParseTable);
  }

  return internalParseTable ? 1 : 0;
}

/** \todo: write unloadParseTable */

/*static int SG_CountAmbiguities(ERR_Error error)
{
  if (ERR_isErrorError(error)) {
    return ERR_getSubjectListLength(ERR_getErrorList(error));
  } 

  return 0;
}*/

ATbool SGLR_isParseTableLoaded(const char *parseTableName) {
  return SG_LookupParseTable(parseTableName) ? ATtrue : ATfalse;  
}

/** \todo Where is the internal representation of the parse forest freed? */

PT_ParseTree SGLR_parse(InputString inputString, const char *parseTableName) {
  PT_Tree t;
  PT_ParseTree parseTree = NULL;
    
  assert(ATisInitialized() && 
      "ATerm library has not been initialized to be used by SGLR");

  if (MAIN_getStatsFlag) { 
    SGLR_STATS_parseTableFilename = parseTableName; 
    SGLR_STATS_inputStringFilename = IS_getPath(inputString); 
  }

  ParseTable *parseTable = SG_LookupParseTable(parseTableName);  

  assert(parseTable != NULL);

  if (MAIN_getStatsFlag) { 
    SGLR_STATS_initializeHistograms(SGLR_PTBL_getMaxProductionLength(parseTable)); 
    STATS_Timer();
  }
  t = SG_parse(parseTable, inputString);
  if (MAIN_getStatsFlag) { 
    SGLR_STATS_parsingTime = STATS_Timer(); 
    SGLR_STATS_linesParsed = IS_getLinesRead(inputString);
    SGLR_STATS_charactersParsed = IS_getNumberOfTokensRead(inputString);
  }

  if (MAIN_getStatsFlag) { STATS_Timer(); }
  if (t) {
    parseTree = FLT_filter(parseTable, t, inputString);
  }
  if (MAIN_getStatsFlag) { SGLR_STATS_filteringTime = STATS_Timer(); }

  SG_DestroyInputAmbiMap();
  SG_AmbiTablesDestroy();

  /*parseTree = ambiguityDetection(parseTree, parseTable, inputString);*/

  if (parseTree) {
    if (MAIN_getFlattenTreeFlag()) {
      if (PARSER_getVerboseFlag) {
        ATwarning("Flattening lists in parse forest\n");
      }
      
      if (MAIN_getStatsFlag) { STATS_Timer(); }
      parseTree = flattenPT(parseTree);
      if (MAIN_getStatsFlag) { SGLR_STATS_flatteningTime = STATS_Timer(); }
    }
  }
  
  if (MAIN_getStatsFlag) {
    SGLR_STATS_print();
  }

  return parseTree;
}

ERR_Summary SGLR_getErrorSummary() {
  return ERR_getManagerSummary();
}

/** \todo reimplement ambiguity as error flag */
#if 0
static ERR_Error createAmbiguityError(int numberOfAmbiguities, ATerm ambtrack) {
  ERR_Error ambiguities = ERR_ErrorFromTerm(ambtrack);
  /*int nrOfAmbs = SG_CountAmbiguities(ambiguities);
  ATerm result;

  t = (tree) ATmakeAppl2(SG_ParseTree_AFun,
			 (ATerm) t, 
                         (ATerm) SG_GetATint(nrOfAmbs, 0));

  result = (ATerm) ATmakeAppl2(SG_AmbiguousTree_AFun, 
			       (ATerm) t,
			       ERR_ErrorToTerm(ambiguities));*/
  return ambiguities;
}
static PT_ParseTree ambiguityDetection(PT_ParseTree parseTree, ParseTable *parseTable, InputString inputString) {
  ATerm ambtrak = NULL;

  if (parseTree != NULL) {
    ambtrak = PT_reportParseTreeAmbiguities(IS_getPath(inputString),parseTree);
    if (ambtrak) {
      if (PARSER_getAmbiguityErrorFlag()) {  
	//parseTree = NULL;
      }
      /** \todo write error to parse tree */
      createAmbiguityError(FLT_getAmbCount(), ambtrak);
    }
  }

  return parseTree;
}
#endif

