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
#include "inputStringBuilder.h" /* only used to get time taken */

#include "mainOptions.h"
#include "parserOptions.h"
#include "sglr-termstore.h"
#include "parserStatistics.h"

static ATbool initialized = ATfalse;
static double timeTakenToParse = 0.0;
static double timeTakenToFilter = 0.0;
static double timeTakenToFlatten = 0.0;

void SGLR_initialize() {
  
  if (!initialized) {
    initErrorApi();
    SGLR_PTBL_initErrorList();
    ERR_cleanupErrorManager();  
    ERR_initErrorManager("parser", "sglr");

    PT_initMEPTApi();
    PT_initAsFix2Api();
    PTBL_initPtableApi();

    OPT_initialize();
    PARSER_initializeDefaultOptions();
    FLT_initialize();
    FLT_initializeDefaultOptions();
    MAIN_initializeDefaultOptions();
    SGLR_TS_create();

    initialized = ATtrue;
  }
}

ATbool SGLR_isInitialized() {
  return initialized;
}

/** Convert an ATerm parse table to the internal format and cache it using the 
 * \a parseTableName.
 * \param parseTableName name to use for the new parse table
 * \param parseTable the parse table to cache
 * \return 1 if parse table could be cached, 0 if caching failed
 */
int SGLR_loadParseTable(const char *parseTableName, PTBL_ParseTable parseTable) {
  ParseTable *internalParseTable = NULL;

  if (MAIN_getStatsFlag) { STATS_Timer(); }
  internalParseTable = SG_BuildParseTable(parseTable, parseTableName);
  SGLR_STATS_setCount(SGLR_STATS_parseTableTime, STATS_Timer());

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

  SGLR_STATS_setCount(SGLR_STATS_parseTableFilename, parseTableName); 
  SGLR_STATS_setCount(SGLR_STATS_inputStringFilename, IS_getPath(inputString)); 

  ParseTable *parseTable = SG_LookupParseTable(parseTableName);  

  assert(parseTable != NULL);

  if (MAIN_getStatsFlag) { 
    SGLR_STATS_initializeHistograms(SGLR_PTBL_getMaxProductionLength(parseTable), IS_getLength(inputString)); 
  }

  STATS_Timer();
  t = SG_parse(parseTable, inputString);
  timeTakenToParse = STATS_Timer();
  SGLR_STATS_setCount(SGLR_STATS_parsingTime, timeTakenToParse);
  SGLR_STATS_setCount(SGLR_STATS_linesParsed, IS_getLinesRead(inputString));
  SGLR_STATS_setCount(SGLR_STATS_charactersParsed, IS_getNumberOfTokensRead(inputString));

  if (t) {
    STATS_Timer();
    parseTree = FLT_filter(parseTable, t, inputString);
    timeTakenToFilter = STATS_Timer();
    SGLR_STATS_setCount(SGLR_STATS_filteringTime, timeTakenToFilter);
  }
  SGLR_STATS_initializeClusterHistogram();
  SG_collectAmbiTableStats();

  SG_DestroyInputAmbiMap();
  SG_AmbiTablesDestroy();

  /*parseTree = ambiguityDetection(parseTree, parseTable, inputString);*/

  if (parseTree) {
    if (MAIN_getFlattenTreeFlag()) {
      if (PARSER_getVerboseFlag) {
        ATwarning("sglr: flattening\n");
      }
      
      STATS_Timer();
      parseTree = flattenPT(parseTree);
      timeTakenToFlatten = STATS_Timer();
      SGLR_STATS_setCount(SGLR_STATS_flatteningTime, timeTakenToFlatten);
    }
  }
  
  if (MAIN_getStatsFlag) {
    SGLR_STATS_print();
    SGLR_STATS_destroyHistograms();
  }
  if (PARSER_getVerboseFlag) {
    ATwarning("\ninput string reading and allocation: \t%f\n", IS_getTimeTakenToReadInput());
    ATwarning("parse table reading and allocation: \t%f\n", SG_getTimeTakenToAllocateTable());
    ATwarning("parsing time: \t\t\t\t%f\n", timeTakenToParse);
    ATwarning("filtering time: \t\t\t%f\n", timeTakenToFilter);
    ATwarning("flattening time: \t\t\t%f\n", timeTakenToFlatten);
  }

  return parseTree;
}

ERR_Summary SGLR_getErrorSummary() {
  return ERR_getManagerSummary();
}

void SGLR_resetErrorSummary() {
  ERR_resetErrorManager();
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

