#include "sdf-generate.h"
#include "normalize.h"
#include "ksdf2table.h"
#include "characters.h"
#include "item.h"
#include "first.h"
#include "follow.h"
#include "goto.h"
#include "parseTable-data.h"
#include "pgenOptions.h"
#include "parseTable-stats.h"
#include <logging.h>
#include <rsrc-usage.h>

static PTBL_ParseTable generateParseTable() {
  int i;

  ATermList vertex; 

  PTBL_State state;
  PTBL_States statelist = PTBL_makeStatesEmpty();
  PTBL_Gotos gotos; 
  PTBL_Choices actions;

  
  calc_first_table();
  calc_follow_table();
  createDFA();

  for (i = PGEN_getNumberOfStates()-1; i >= 0; i--) {
    vertex = PGEN_getStateOfStateNumber(i);

    gotos = (PTBL_Gotos)PGEN_getGotosOfState(vertex);
    if (!gotos) {
      gotos = PTBL_makeGotosEmpty();
    } 
    else if (PGEN_getStatsFlag) {
      PGEN_STATS_increaseGotos(PTBL_getGotosLength(gotos));
    }

    actions = PGEN_getActionsOfState(vertex);
    if (!actions) {
      actions = PTBL_makeChoicesEmpty();
    }
    else if (PGEN_getStatsFlag) {
      PGEN_STATS_increaseActions(PTBL_getChoicesLength(actions));
    }

    state = PTBL_makeStateDefault(i, gotos, actions);
    statelist = PTBL_makeStatesMany(state, statelist);
  }

  if (PGEN_getStatsFlag) { PGEN_STATS_print(); }

  return PTBL_makeParseTableParseTable(PTBL_makeVersionDefault(), PGEN_getInitialStateNumber(), PGEN_getLabelSection(), statelist, PGEN_getPrioSection());
}

ATerm sdf_generate_table(PT_Tree ksdf) 
{
  ATerm pt;

  PGEN_initTableGen();
  PGEN_processGrammar(ksdf);

  pt = (ATerm) generateParseTable();

  PGEN_destroyTableGen();       

  return pt;
}

ATerm normalize_and_generate_table(const char *name, PT_ParseTree sdf2term) {
  ATerm pt = NULL;
  PT_Tree ksdf;

  if (PGEN_getStatsFlag) { STATS_Timer(); } 

  if (PGEN_getGenerationModeFlag()) {
    ksdf = PT_getParseTreeTree(sdf2term);
  } else {
    ksdf = normalizeGrammar(name, sdf2term); 
  }

  PGEN_STATS_setCount(PGEN_STATS_normalizationTime, STATS_Timer());

  if (PGEN_getNormalizationModeFlag()) {
    return PT_ParseTreeToTerm(PT_makeValidParseTreeFromTree(ksdf));
  }

  if (ksdf)  {
    pt = sdf_generate_table(ksdf);
  }

  PGEN_STATS_setCount(PGEN_STATS_generationTime, STATS_Timer());
  
  return (ATerm)pt;
}

