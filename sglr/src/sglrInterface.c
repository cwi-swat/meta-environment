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
#include <logging.h>
#include <rsrc-usage.h>
#include <options.h>
#include <filterOptions.h>

#include "sglrInterface.h"

#include "mem-alloc.h"
#include "parser.h"
#include "parseTableBuilder.h"
#include "parseTableDB.h"
#include "filters.h"
#include "filterStats.h"
#include "ambi-tables.h"
#include "inputString-api.h"

#include "mainOptions.h"
#include "parserOptions.h"
#include "sglr-termstore.h"

static ATbool initialized = ATfalse;
/* Controlling global behaviour: verbosity, debugging mode, dot
 * output of parse forests/parse stacks, and so on.
 */
int _SG_Mode = 0;

void SGLR_initialize() {
  
  if (!initialized) {
    initErrorApi();
    SGLR_PTBL_initErrorList();
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
ATerm SGLR_loadParseTable(const char *parseTableName, PTBL_ParseTable parseTable) {
  ParseTable *internalParseTable = NULL;

  if (PARSER_getStatsFlag() == ATtrue) {
    ATfprintf(LOG_log(), "Language: %t\n", parseTableName); STATS_Timer();
  }

  internalParseTable = SG_BuildParseTable(parseTable, parseTableName);

  if (PARSER_getStatsFlag() == ATtrue) {
    ATfprintf(LOG_log(),
	      "Obtaining parse table for %t took %.6fs\n",
	      parseTableName, STATS_Timer());
  }

  if (internalParseTable != NULL) {
    SG_CacheParseTable(parseTableName, internalParseTable);
  }

  return (ATerm) (internalParseTable ? ATempty : NULL);
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


static PT_ParseTree filterTree(PT_Tree t, ParseTable *parseTable, InputString inputString) {
  PT_ParseTree result = NULL;

  if (t != NULL) { 
    if (PARSER_getStatsFlag() == ATtrue) { 
      STATS_Timer(); 
    }
    
    result = FLT_filter(parseTable, t, inputString);
    
    if (PARSER_getStatsFlag() == ATtrue) { 
      fprintf(LOG_log(), "Filtering took %.6fs\n", STATS_Timer());
    }  
  }

  return result; 
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

/** \todo Where is the internal representation of the parse forest freed? */

PT_ParseTree SGLR_parse(InputString inputString, const char *parseTableName) {
  PT_Tree t;
  PT_ParseTree parseTree;

  assert(ATisInitialized() && 
      "ATerm library has not been initialized to be used by SGLR");

  ERR_cleanupErrorManager();  
  ERR_initErrorManager("parser", "sglr");

  ParseTable *parseTable = SG_LookupParseTable(parseTableName);  

  assert(parseTable != NULL);

  t = SG_parse(parseTable, inputString);

  parseTree = filterTree(t, parseTable, inputString);

  SG_DestroyInputAmbiMap();
  SG_AmbiTablesDestroy();

  /*parseTree = ambiguityDetection(parseTree, parseTable, inputString);*/

  if (parseTree != NULL) {
    if (MAIN_getFlattenTreeFlag()) {
      if (PARSER_getVerboseFlag() == ATtrue) {
        ATwarning("Flattening lists in parse forest\n");
      }
      
      if (PARSER_getStatsFlag() == ATtrue) {
        STATS_Timer();
      }
      
      parseTree = flattenPT(parseTree);
      
      if (PARSER_getStatsFlag() == ATtrue) {
        fprintf(LOG_log(), "Flattening took %.6fs\n", STATS_Timer());
      }
    }
  }
  
  return parseTree;
}

ERR_Summary SGLR_getErrorSummary() {
  return ERR_getManagerSummary();
}
