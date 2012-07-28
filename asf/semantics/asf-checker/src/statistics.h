#ifndef STATISTICS_H
#define STATISTICS_H

#include <aterm2.h>

void initStatistics(void);
void printStatistics(void);
void cleanStatistics(void); 

extern int nrEquations;
extern int nrEquationsWithConditions;
extern int nrDefaultEquations;
extern int nrConditions;
extern int maxNrConditionsPerEquation;
extern int nrAssignmentConditions;
extern int nrNonAssignmentConditions;
extern int nrEqualityConditions;
extern int nrInequalityConditions;
extern ATermIndexedSet outermostFunctions;


#define SCOUNT(global) (global++)
#define SSUM(global, v) (global = global + v)
#define SMAX(global, v) (global = (global > v ? global : v))
#define SADD(global, v) (ATindexedSetPut(global, (ATerm) v, NULL))

#endif
