/*
  $Id$
 */

#ifndef TRAVERSALS_H
#define TRAVERSALS_H
#include <aterm2.h>
#include <MEPT-utils.h>

/* these are argument numbers is asfix appls */
#define ACCUMULATED_ARG_POS    8
#define ACCUMULATED_SYMBOL_POS 8
#define TRAVERSED_ARG_POS      4 
#define TRAVERSED_SYMBOL_POS   4
#define TUPLE_FIRST_POS        2
#define TUPLE_SECOND_POS       6

extern ATbool traversals_on;

typedef enum { UNDEFINED_TYPE = 0, TRANSFORMER = 1, ACCUMULATOR = 2,
               COMBINATION = 3 } TraversalType;

typedef enum { UNDEFINED_STRATEGY = 0, BOTTOMUP = 1, 
               TOPDOWN = 2 } TraversalStrategy;

typedef enum { UNDEFINED_CONTINUATION = 0, CONTINUE = 1, 
               BREAK = 2 } TraversalContinuation;

typedef struct Traversal_tag {
	TraversalType  type;
	TraversalStrategy strategy;
	TraversalContinuation continuation;
	PT_Production  prod;
	PT_Symbols     symbols;
        PT_Symbol      accumulated;
	PT_Symbol      traversed;
	PT_Args        args;
} Traversal;


#define NO_TRAVERSAL NULL

#define selectTraversedArg(args) (selectTree(args, TRAVERSED_ARG_POS))
#define selectAccumulatedArg(args) (selectTree(args, ACCUMULATED_ARG_POS))

/* operations  on Traversals */
Traversal createTraversalPattern(PT_Tree term);
Traversal updateAccumulator(Traversal trav, PT_Tree newarg);
PT_Tree   makeTraversalAppl(PT_Tree trm, Traversal traversal);
PT_Tree   chooseNormalform(PT_Tree term, Traversal trav);
PT_Tree   selectTree(PT_Args args, int pos);
PT_Tree makeTraversalReduct(PT_Tree orig, PT_Tree rhs, Traversal* traversal);

PT_Tree  getTupleFirst(PT_Tree tuple);
PT_Tree  getTupleSecond(PT_Tree tuple);

ATbool isTreeTraversal(PT_Tree trm);

#endif
