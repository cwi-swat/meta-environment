#include <stdio.h>
#include <aterm2.h>

/*{{{  globals */

int nrEquations;
int nrEquationsWithConditions;
int nrDefaultEquations;
int nrConditions;
int maxNrConditionsPerEquation;
int nrAssignmentConditions;
int nrNonAssignmentConditions;
int nrEqualityConditions;
int nrInequalityConditions;
int nrOutermostFunctions;

ATermIndexedSet outermostFunctions;

/*}}}  */

/*{{{  void printStatistics(void)  */

void printStatistics(void) 
{
  int nrOutermostFunctions = ATgetLength(ATindexedSetElements(outermostFunctions));

  fprintf(stderr, "nrEquations                = %d \n", nrEquations);
  fprintf(stderr, "nrEquationsWithConditions  = %d \n", nrEquationsWithConditions);
  fprintf(stderr, "nrDefaultEquations         = %d \n", nrDefaultEquations);
  fprintf(stderr, "nrConditions               = %d \n", nrConditions);
  fprintf(stderr, "maxNrConditionsPerEquation = %d \n", maxNrConditionsPerEquation);
  fprintf(stderr, "avgNrConditionsPerEquation = %.2f \n", nrEquationsWithConditions != 0 ? ((double) nrConditions) / ((double) nrEquationsWithConditions) : 0.0);
  fprintf(stderr, "nrAssignmentConditions     = %d \n", nrAssignmentConditions);
  fprintf(stderr, "nrNonAssignmentConditions  = %d \n", nrNonAssignmentConditions);
  fprintf(stderr, "nrEqualityConditions       = %d \n", nrEqualityConditions);
  fprintf(stderr, "nrInequalityConditions     = %d \n", nrInequalityConditions);
  fprintf(stderr, "nrOutermostFunctions       = %d \n", nrOutermostFunctions);
  fprintf(stderr, "avgNrEquationsPerFunction  = %.2f \n", nrOutermostFunctions != 0 ? ((double)nrEquations) / ((double)
	  ATgetLength(ATindexedSetElements(outermostFunctions))) : 0.0);
}

/*}}}  */
/*{{{  void initStatistics(void)  */

void initStatistics(void) 
{
  outermostFunctions = ATindexedSetCreate(100,70);

  nrEquations = 0;
  nrEquationsWithConditions = 0;
  nrDefaultEquations = 0;
  nrConditions = 0;
  maxNrConditionsPerEquation = -1;
  nrAssignmentConditions = 0;
  nrNonAssignmentConditions = 0;
  nrEqualityConditions = 0;
  nrInequalityConditions = 0;
  nrOutermostFunctions = 0;
}

/*}}}  */
/*{{{  void cleanStatistics(void)  */

void cleanStatistics(void) 
{
  ATindexedSetDestroy(outermostFunctions);
}

/*}}}  */
