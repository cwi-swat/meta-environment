#ifndef PREFIX_FUNCTIONS_H
#define PREFIX_FUNCTIONS_H
#include <MEPT.h>
#include <MEPT-utils.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

/* Sneaky global access to interpreter functionality */
extern PT_Tree rewrite(PT_Tree term);

/* Very common term and tree manipulations */
PT_Tree CO_getFunctionArgument(PT_Tree function, int i);
ATerm CO_unquoteAppl(ATerm appl); 

#endif
