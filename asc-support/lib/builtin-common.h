#ifndef PREFIX_FUNCTIONS_H
#define PREFIX_FUNCTIONS_H
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <MEPT.h>
#include <MEPT-utils.h>
#include <asc-muasf2pt.h>

/* Very common term and tree manipulations */
PT_Tree CO_getFunctionArgument(PT_Tree function, int i);
ATerm CO_unquoteAppl(ATerm appl); 

#endif
