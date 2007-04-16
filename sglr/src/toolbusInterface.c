/*$Id$*/

#include "sglr.h"
#include "sglrInterface.h"
#include "inputStringBuilder.h"
#include "inputString-api.h"
#include "parseTable.h"

#include <assert.h>
#include <MEPT-utils.h>
#include <Error-manager.h>
#include <mainOptions.h>
#include <filterOptions.h>

static const char PARSETABLE_ID[] = "ToolBusParseTable";

int runTool(ATerm *bottomOfStack, int argc, char *argv[]){
  ATBinit(argc, argv, bottomOfStack);
  ATBconnect(NULL, NULL, -1, sglr_handler);
  ATBeventloop();

  return 0;
}

ATerm parse(int conn, const char *input, ATerm packedParseTable, const char *topSort, ATerm heuristics) {
  PT_ParseTree forest = NULL;
  ATerm message;

  PTBL_ParseTable parseTable = PTBL_ParseTableFromTerm(ATBunpack(packedParseTable));

  if (parseTable != NULL) {
    /** \todo Bring these fixed options to the ToolBus interface level */
    PARSER_setAmbiguityErrorFlag(ATtrue);
    MAIN_setParseTableName(PARSETABLE_ID);

    if (ATisEqual(heuristics, ATparse("on"))) {
      FLT_setPreferenceCountFlag(ATtrue);
      FLT_setInjectionCountFlag(ATtrue);
    }
    else {
      FLT_setPreferenceCountFlag(ATfalse);
      FLT_setInjectionCountFlag(ATfalse);
    }

    if (topSort) {
      if (*topSort == '\0') {
        FLT_setSelectTopNonterminalFlag(ATfalse);
      }
      else {
        FLT_setSelectTopNonterminalFlag(ATtrue);
        FLT_setTopNonterminal(topSort);
      }
    }
    else {
      FLT_setSelectTopNonterminalFlag(ATfalse);
    }

    if (SGLR_loadParseTable(PARSETABLE_ID, parseTable)) {
      InputString inputString = IS_createInputStringFromString((const unsigned char *)input);
      forest = SGLR_parse(inputString, PARSETABLE_ID);
      IS_destroyInputString(inputString);
    }

    if (forest != NULL) {
      if (ERR_getManagerCount() > 0) {
        message = ATmake("parse-succeeded(<term>,<term>)", 
            ATBpack((ATerm)forest), ERR_SummaryToTerm(ERR_getManagerSummary()));
      }
      else {
        message = ATmake("parse-succeeded(<term>,<term>)",
            ATBpack((ATerm)forest), ATparse("undefined"));
      }
    }
    else {
      assert(ERR_getManagerCount() > 0  && "no result should imply an error");
      message = ATmake("parse-failed(<term>)", 
          ERR_SummaryToTerm(ERR_getManagerSummary()));
    }
  }
  else {
    message = ATmake("parse-failed(<term>)", 
        ERR_SummaryToTerm(SGLR_PTBL_makeErrorSummary("parse table")));
  }

  return ATmake("snd-value(<term>)", message);
}

void rec_terminate(int conn, ATerm t) {
  exit(0);
}

