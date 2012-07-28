/* $Id$ */

/** \file
 * \ingroup parser
 *
 */

#include <string.h>
#include <rsrc-usage.h>

#include "parserStatistics.h"
#include "parserOptions.h"

ATbool SGLR_STATS_rejects = ATfalse;
ATbool SGLR_STATS_priorities = ATfalse;
ATbool SGLR_STATS_prefers = ATfalse;
ATbool SGLR_STATS_avoids = ATfalse;

int SGLR_STATS_gotos = 0;
int SGLR_STATS_actions = 0;
int SGLR_STATS_states = 0;
int SGLR_STATS_prods = 0;
int SGLR_STATS_actionEntries = 0;
int SGLR_STATS_gotoEntries = 0;

long SGLR_STATS_initialMemAllocated = 0;
long SGLR_STATS_initialMRSS = 0; 
long SGLR_STATS_endMRSS = 0;
long SGLR_STATS_emptyParseTableMemAllocated = 0;
long SGLR_STATS_fullParseTableMemAllocated = 0;
long SGLR_STATS_beforeParseTableCreationMRSS = 0;
long SGLR_STATS_emptyParseTableMRSS = 0;
long SGLR_STATS_fullParseTableMRSS = 0;
long SGLR_STATS_parsingMemAllocated = 0;
long SGLR_STATS_majorPageFaults = 0; 
long SGLR_STATS_minorPageFaults = 0;

int SGLR_STATS_linesParsed = 0;
int SGLR_STATS_charactersParsed = 0;

int SGLR_STATS_rejectedTreesCreated = 0; /* these two are prob the same */
int SGLR_STATS_rejectedEdgesCreated = 0;
int SGLR_STATS_existingEdgesRejected = 0;
int SGLR_STATS_rejectedReductionsDone = 0;
unsigned int SGLR_STATS_nodesNormal = 0;
unsigned int SGLR_STATS_nodesRejected = 0;
unsigned int SGLR_STATS_nodesPartiallyRejected = 0;

long long SGLR_STATS_gssLimitedEdgesTraversed = 0;
long long SGLR_STATS_gssLimitedEdgesSearched = 0;
long long SGLR_STATS_gssEdgesTraversed = 0;
long long SGLR_STATS_gssEdgesSearched = 0;
unsigned int SGLR_STATS_gssEdgesCreated = 0;
unsigned int SGLR_STATS_gssNodesCreated = 0;
unsigned int SGLR_STATS_gssNodesDeleted = 0;

unsigned int SGLR_STATS_shiftsDone = 0;
unsigned int SGLR_STATS_reductionsDone = 0;
unsigned int SGLR_STATS_reductionsLADone = 0;
unsigned int SGLR_STATS_limitedReductionsDone = 0;
unsigned int SGLR_STATS_limitedLAReductionsDone = 0;
int SGLR_STATS_shiftsAddedToShiftQueue = 0;
int SGLR_STATS_maxSizeOfShiftQueue = 0;

int *SGLR_STATS_reductionLengthsDone = NULL;
int *SGLR_STATS_edgeVisitsPerReductionLength = NULL;
/*int *SGLR_STATS_edgeVisitsPerLevel = NULL;
static ATermTable levelsWithEqualEdgeVisits = NULL;*/

/* Tree construction statistics. */
int SGLR_STATS_ambiguityClustersCreated = 0;
int SGLR_STATS_existingAmbiguityClustersFound = 0;
int SGLR_STATS_maxClusterLength = 0; 
int *SGLR_STATS_clusterHistogram = NULL;

unsigned int SGLR_STATS_prodTreeNodesCreated = 0;
int SGLR_STATS_symbolTreeNodesCreated = 0;
int SGLR_STATS_cyclicTreeNodesCreated = 0;
int SGLR_STATS_cyclesDetected = 0;

/* Post parse filtering statistics. */
int SGLR_STATS_treeNodesVisited = 0;
int SGLR_STATS_treesFiltered = 0;
int SGLR_STATS_priorityConflictsFound = 0;
int SGLR_STATS_rejectedTreesFound = 0;
int SGLR_STATS_prodTreeNodesCreatedDuringFiltering = 0;
int SGLR_STATS_ambTreeNodesCreatedDuringFiltering = 0;
int SGLR_STATS_cyclicTreeNodesCreatedDuringFiltering = 0;

int SGLR_STATS_treesDirectPreferenceFiltered = 0;
int SGLR_STATS_treesIndirectPreferenceFiltered = 0;
int SGLR_STATS_treesPreferred = 0;
int SGLR_STATS_treesPreferenceCountFiltered = 0;
int SGLR_STATS_treesInjectionCountFiltered = 0;
int SGLR_STATS_ambiguityPriorityFiltered = 0;
int SGLR_STATS_treesPriorityFiltered = 0;
int SGLR_STATS_treesRejectFiltered = 0;

int SGLR_STATS_ambNodesInFilteredTree = 0;
unsigned int SGLR_STATS_prodNodesInFilteredTree = 0;
int SGLR_STATS_symbolNodesInFilteredTree = 0;
int SGLR_STATS_cyclicNodesInFilteredTree = 0;


int SGLR_STATS_preferenceCount = 0;
int SGLR_STATS_preferenceCountCalls = 0;
int SGLR_STATS_injectionCount = 0;
int SGLR_STATS_injectionCountCalls = 0;
int SGLR_STATS_totalAmbCount = 0; /**< the total number of ambiguities created. */
int SGLR_STATS_ambCallsCount = 0; /**< the number of times a call to 
                                SG_CreateAmbCluster() is done.*/
int SGLR_STATS_clustersVisitedCount = 0;




double SGLR_STATS_parseTableTime = 0.0;
double SGLR_STATS_parsingTime = 0.0;
double SGLR_STATS_flatteningTime = 0.0;
double SGLR_STATS_filteringTime = 0.0;

const char *SGLR_STATS_inputStringFilename;
const char *SGLR_STATS_parseTableFilename;
static int maxReductionLength = 0;
static int inputStringLength = 0;

void SGLR_STATS_initializeHistograms(int length, int inputLength) {
  maxReductionLength = length;
  inputStringLength = inputLength;

  SGLR_STATS_reductionLengthsDone = (int*) calloc(maxReductionLength+1, sizeof(int));
  SGLR_STATS_edgeVisitsPerReductionLength = (int*) calloc(maxReductionLength+1, sizeof(int));
  /* +2 to include the end-of-string and because there are inputStringLength+1 
   * levels in the GSS. */
  /*SGLR_STATS_edgeVisitsPerLevel = (int*) calloc(inputStringLength+2, sizeof(int));
  levelsWithEqualEdgeVisits = ATtableCreate(4096, 75);*/
}

void SGLR_STATS_initializeClusterHistogram(void) {
  SGLR_STATS_clusterHistogram = (int*) calloc(SGLR_STATS_maxClusterLength+1, sizeof(int));
}

void SGLR_STATS_destroyHistograms() {
  free(SGLR_STATS_reductionLengthsDone);
  free(SGLR_STATS_edgeVisitsPerReductionLength);
  /*free(SGLR_STATS_edgeVisitsPerLevel);*/
  free(SGLR_STATS_clusterHistogram);
  /*ATtableDestroy(levelsWithEqualEdgeVisits);*/
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

/*static int compareKeys(ATerm a1, ATerm a2) {
  if (ATgetInt(a1) > ATgetInt(a2)) {
    return 1;
  }
  else {
    return 0;
  }
}
*/
void SGLR_STATS_print(void) {
  int i;
  /*ATermList keys;*/
  FILE *logFile;

  if (PARSER_getVerboseFlag) {
    ATwarning("Logging statistics\n");
  }

  logFile = openLog(MAIN_getStatsFileName());

  fprintf(logFile, "\n%%%%---Reading parse table ---\n");
  fprintf(logFile, "str parse-table-name = \"%s\"\n", SGLR_STATS_parseTableFilename);
  fprintf(logFile, "%%%% obtaining-parse-table-time = %.6fs\n", SGLR_STATS_parseTableTime);
  fprintf(logFile, "%%%% %scludes rejects\n", SGLR_STATS_rejects?"in":"ex");
  fprintf(logFile, "%%%% %scludes priorities\n", SGLR_STATS_priorities?"in":"ex");
  fprintf(logFile, "%%%% %scludes prefer actions\n", SGLR_STATS_prefers?"in":"ex");
  fprintf(logFile, "%%%% %scludes avoid actions\n", SGLR_STATS_avoids?"in":"ex");

  fprintf(logFile, "int gotos = %d\n", SGLR_STATS_gotos);
  fprintf(logFile, "int actions = %d\n", SGLR_STATS_actions);

  fprintf(logFile, "int states = %ld\n", (long) SGLR_STATS_states); 
  fprintf(logFile, "int productions = %ld\n", (long) SGLR_STATS_prods);
  fprintf(logFile, "int action-entries = %ld\n", (long) SGLR_STATS_actionEntries);
  fprintf(logFile, "int goto-entries = %ld\n", (long) SGLR_STATS_gotoEntries);

  fprintf(logFile, "int extra-ATerm-memory-allocated-for-empty-table = %ld\n", SGLR_STATS_emptyParseTableMemAllocated);
  fprintf(logFile, "int extra-ATerm-memory-allocated-while-filling-table = %ld\n", SGLR_STATS_fullParseTableMemAllocated);
  fprintf(logFile, "int PT-build-before-table-creation = %ld\n", SGLR_STATS_beforeParseTableCreationMRSS);
  fprintf(logFile, "int PT-build-after-table-creation = %ld\n", SGLR_STATS_emptyParseTableMRSS);
  fprintf(logFile, "int PT-build-before-filling-table = %ld\n", SGLR_STATS_emptyParseTableMRSS);
  fprintf(logFile, "int PT-build-after-filling-table = %ld\n", SGLR_STATS_fullParseTableMRSS);
 
  fprintf(logFile, "\n%%%%--- Parsing ---\n");
  fprintf(logFile, "%%%% parse-time: %.6fs\n", SGLR_STATS_parsingTime);
  fprintf(logFile, "int lines-parsed = %d\n", SGLR_STATS_linesParsed);
  fprintf(logFile, "%%%% characters/second = %.0f\n\n", SGLR_STATS_parsingTime < 1.0e-4 ? 0 : SGLR_STATS_charactersParsed/SGLR_STATS_parsingTime);

  fprintf(logFile, "int total-reductions-done = %d\n", SGLR_STATS_reductionsDone);
  fprintf(logFile, "int multi-symbol-follow-restricted-reductions-done = %d\n", SGLR_STATS_reductionsLADone);
  fprintf(logFile, "int limited-reductions-done = %d\n", SGLR_STATS_limitedReductionsDone);
  fprintf(logFile, "int multi-symbol-follow-restricted-limited-reductions-done = %d\n", SGLR_STATS_limitedLAReductionsDone);
  fprintf(logFile, "int rejected-reductions-done = %d\n", SGLR_STATS_rejectedReductionsDone);
  fprintf(logFile, "%%%% reductions/character: %f\n", (double)SGLR_STATS_reductionsDone/(double)SGLR_STATS_charactersParsed);

  /** \todo probably redundant because it is the same as the number of shifts
   *  added to the shift queue. */
  fprintf(logFile, "int shifts-done = %d\n", SGLR_STATS_shiftsDone);
  fprintf(logFile, "int shifts-added-to-shift-queue = %d\n", SGLR_STATS_shiftsAddedToShiftQueue);
  fprintf(logFile, "int max-size-of-shift-queue = %d\n\n", SGLR_STATS_maxSizeOfShiftQueue);

  fprintf(logFile, "int GSS-nodes-created = %u\n", SGLR_STATS_gssNodesCreated);
  fprintf(logFile, "int GSS-nodes-deleted = %d\n", SGLR_STATS_gssNodesDeleted);
  fprintf(logFile, "int GSS-edges-created = %d\n\n", SGLR_STATS_gssEdgesCreated);

  fprintf(logFile, "int GSS-edges-traversed-for-normal-reductions = %lld\n", SGLR_STATS_gssEdgesTraversed);
  fprintf(logFile, "int GSS-edges-traversed-during-search-for-existing-edge = %lld\n", SGLR_STATS_gssEdgesSearched);
  fprintf(logFile, "int GSS-edges-traversed-for-farshi-reductions = %lld\n", SGLR_STATS_gssLimitedEdgesTraversed);
  fprintf(logFile, "int GSS-edges-traversed-during-farshi-search-for-new-edge-in-level = %lld\n", SGLR_STATS_gssLimitedEdgesSearched);
  fprintf(logFile, "int GSS-total-edges-traversed = %lld\n", (SGLR_STATS_gssLimitedEdgesTraversed+SGLR_STATS_gssEdgesTraversed+SGLR_STATS_gssLimitedEdgesSearched+SGLR_STATS_gssEdgesSearched));
  /* This is the total count of redundant edge traversals. */
  fprintf(logFile, "int GSS-total-edges-traversed-during-search-for-existing-edges = %lld\n\n", (SGLR_STATS_gssLimitedEdgesSearched+SGLR_STATS_gssEdgesSearched));

  /** /todo probably redundant because it is the same as the number of rejected
   * reductions done. */
  fprintf(logFile, "int rejected-trees-created = %d\n", SGLR_STATS_rejectedTreesCreated);
  fprintf(logFile, "int normal-GSS-nodes = %d\n", SGLR_STATS_nodesNormal);
  fprintf(logFile, "int completely-rejected-GSS-nodes = %d\n", SGLR_STATS_nodesRejected);
  fprintf(logFile, "int partially-rejected-GSS-nodes = %d\n", SGLR_STATS_nodesPartiallyRejected);
  fprintf(logFile, "int rejected-edges-created = %d\n", SGLR_STATS_rejectedEdgesCreated);
  fprintf(logFile, "int existing-non-rejected-edges-marked-rejected = %d\n", SGLR_STATS_existingEdgesRejected);


  fprintf(logFile, "int production-tree-node-created = %d\n", SGLR_STATS_prodTreeNodesCreated);
  fprintf(logFile, "int leaf-nodes-created = %d\n", SGLR_STATS_symbolTreeNodesCreated);
  fprintf(logFile, "int cyclic-tree-nodes-detected = %d\n", SGLR_STATS_cyclesDetected);
  fprintf(logFile, "int cyclic-tree-nodes-created = %d\n", SGLR_STATS_cyclicTreeNodesCreated);
 fprintf(logFile, "int ambiguities-created = %d\n", SGLR_STATS_ambiguityClustersCreated);
  fprintf(logFile, "int existing-ambiguities-found = %d\n", SGLR_STATS_existingAmbiguityClustersFound);
  fprintf(logFile, "int max-ambiguity-cluster-length = %d\n", SGLR_STATS_maxClusterLength); 

  fprintf(logFile, "rel[int, int] clusterLengths = \n");
  fprintf(logFile, "{\n");
  fprintf(logFile, "%%%%<cluster-length, times-created>\n");
  for (i = 0; i <= SGLR_STATS_maxClusterLength; i++) {
    fprintf(logFile, "<%d, %d>", i, SGLR_STATS_clusterHistogram[i]);
    if (i < SGLR_STATS_maxClusterLength) {
      fprintf(logFile, ",\n");
    }
  }
  fprintf(logFile, "\n}\n");


  fprintf(logFile, "rel[int, int] reductionLengths = \n");
  fprintf(logFile, "{\n");
  fprintf(logFile, "%%%%<reduction-length, times-reduced>\n");
  for (i = 0; i <= maxReductionLength; i++) {
    fprintf(logFile, "<%d, %d>", i, SGLR_STATS_reductionLengthsDone[i]);
     if (i < maxReductionLength) {
      fprintf(logFile, ",\n");
    }
  }
  fprintf(logFile, "\n}\n");

  fprintf(logFile, "rel[int, int] edgeVisitsPerReduction = \n");
  fprintf(logFile, "{\n");
  fprintf(logFile, "%%%%<reduction-length, edge-visits>\n");
  for (i = 0; i <= maxReductionLength; i++) {
    fprintf(logFile, "<%d, %d>", i, SGLR_STATS_edgeVisitsPerReductionLength[i]);
    if (i < maxReductionLength) {
      fprintf(logFile, ",\n");
    }
  }
  fprintf(logFile, "\n}\n");
/*
  fprintf(logFile, "rel[int, int] edgeVisitsPerLevel = \n");
  fprintf(logFile, "{\n");
  fprintf(logFile, "%%%%<level-number, edge-visits>\n");
  for (i = 0; i < SGLR_STATS_charactersParsed+1; i++) {
    fprintf(logFile, "<%d, %d>", i, SGLR_STATS_edgeVisitsPerLevel[i]);
    if (i < SGLR_STATS_charactersParsed) {
      fprintf(logFile, ",\n");
    }
  }
  fprintf(logFile, "\n}\n");

  for (i = 0; i < SGLR_STATS_charactersParsed+1; i++) {
    int incValue = 0;
    ATerm key = (ATerm)ATmakeInt(SGLR_STATS_edgeVisitsPerLevel[i]);
    ATerm value = ATtableGet(levelsWithEqualEdgeVisits, key);

    if (value) {
      incValue = ATgetInt(value);
    }
    incValue++;
    ATtablePut(levelsWithEqualEdgeVisits, key, (ATerm)ATmakeInt(incValue));
  }

  fprintf(logFile, "rel[int, int] levelsWithSameEdgeVisits = \n");
  fprintf(logFile, "{\n");
  fprintf(logFile, "%%%%<edge-visits, number-of-levels>\n");

  keys = ATtableKeys(levelsWithEqualEdgeVisits);
  keys = ATsort(keys, compareKeys);
  while (!ATisEmpty(keys)) {
    ATerm key = ATgetFirst(keys);
    ATerm value = ATtableGet(levelsWithEqualEdgeVisits, key);

    fprintf(logFile, "<%d, %d>", ATgetInt(key), ATgetInt(value));
    keys = ATgetNext(keys);
    if (!ATisEmpty(keys)) {
      fprintf(logFile, ",\n");
    }
  }
  fprintf(logFile, "\n}\n");
*/
  fprintf(logFile, "int extra-ATerm-memory-allocated-while-parsing = %ld\n", SGLR_STATS_parsingMemAllocated);

  fprintf(logFile, "int minor-page-faults = %ld\n", SGLR_STATS_minorPageFaults);
  fprintf(logFile, "int major-page-faults = %ld\n", SGLR_STATS_majorPageFaults);

  if(SGLR_STATS_minorPageFaults > 0)
    fprintf(logFile, "%%%% characters/minor-fault: %ld\n", SGLR_STATS_charactersParsed/SGLR_STATS_minorPageFaults);


  fprintf(logFile, "\n%%%%--- Filtering ---\n");
  fprintf(logFile, "%%%% filtering-time %.6fs\n", SGLR_STATS_filteringTime);
  fprintf(logFile, "int total-preference-count-comparisons-done = %d\n", SGLR_STATS_preferenceCountCalls);
  fprintf(logFile, "int successful-preference-count-comparisons-done = %d\n", SGLR_STATS_preferenceCount);
  fprintf(logFile, "int total-injection-count-comparisons-done = %d\n", SGLR_STATS_injectionCountCalls);
  fprintf(logFile, "int successful-injection-count-comparisons-done = %d\n", SGLR_STATS_injectionCount);

  fprintf(logFile, "\nint trees-direct-preference-filtered = %d\n", SGLR_STATS_treesDirectPreferenceFiltered);
  fprintf(logFile, "int trees-preferred = %d\n", SGLR_STATS_treesPreferred);
  fprintf(logFile, "int trees-indirect-preference-filtered = %d\n", SGLR_STATS_treesIndirectPreferenceFiltered);
  fprintf(logFile, "int trees-preference-count-filtered = %d\n", SGLR_STATS_treesPreferenceCountFiltered);
  fprintf(logFile, "int trees-injection-count-filtered = %d\n", SGLR_STATS_treesInjectionCountFiltered);
  fprintf(logFile, "int trees-priority-filtered = %d\n", SGLR_STATS_treesPriorityFiltered);
  fprintf(logFile, "int ambiguity-nodes-priority-filtered = %d\n", SGLR_STATS_ambiguityPriorityFiltered);
  fprintf(logFile, "int trees-reject-filtered = %d\n", SGLR_STATS_treesRejectFiltered);


  fprintf(logFile, "\nint prod-nodes-created-during-filtering = %d\n", SGLR_STATS_prodTreeNodesCreatedDuringFiltering);
  fprintf(logFile, "int ambiguity-nodes-created-during-filtering = %d\n", SGLR_STATS_ambTreeNodesCreatedDuringFiltering);
  fprintf(logFile, "int cyclic-nodes-created-during-filtering = %d\n", SGLR_STATS_cyclicTreeNodesCreatedDuringFiltering);

  fprintf(logFile, "\nint prod-nodes-in-filtered-tree = %d\n", SGLR_STATS_prodNodesInFilteredTree);
  fprintf(logFile, "int symbol-nodes-in-filtered-tree = %d\n", SGLR_STATS_symbolNodesInFilteredTree);
  fprintf(logFile, "int ambiguity-nodes-in-filtered-tree = %d\n", SGLR_STATS_ambNodesInFilteredTree);
  fprintf(logFile, "int cyclic-nodes-in-filtered-tree = %d\n", SGLR_STATS_cyclicNodesInFilteredTree);

  fprintf(logFile, "\n%%%%--- Flattening ---\n");
  fprintf(logFile, "%%%% flattening-time = %.6fs\n", SGLR_STATS_flatteningTime);

  fprintf(logFile, "int initial-ATerm-memory = %ld\n", SGLR_STATS_initialMemAllocated);
  fprintf(logFile, "int ATerm-init-before-flattening = %ld\n", SGLR_STATS_initialMRSS);
  fprintf(logFile, "int ATerm-init-after-flattening = %ld\n", SGLR_STATS_endMRSS);

  closeLog(logFile);
}

