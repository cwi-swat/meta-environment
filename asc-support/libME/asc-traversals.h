/*
  $Id$
 */

#ifndef TRAVERSALS_H
#define TRAVERSALS_H
#include <aterm2.h>
#include <MEPT-utils.h>

typedef enum { UNDEFINED_TYPE = 0, TRANSFORMER = 1, ACCUMULATOR = 2,
               COMBINATION = 3 } TraversalType;

#define TRAVERSED_SYMBOL_POS   4
#define GEN_TRAVERSED_SORT    "***TRAVERSED***"

PT_Tree ASC_transformTraversalFunction(PT_Tree tree);

#endif
