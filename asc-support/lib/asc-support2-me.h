#ifndef ASC_SUPPORT2_H
#define ASC_SUPPORT2_H

#include "asc-support-me.h"
#include <MEPT-utils.h>

extern ATerm innermost(PT_Tree tree);
extern PT_ParseTree toasfix(ATerm tree);
extern PT_ParseTree toasfixNoLayout(ATerm tree);
void ASC_initRunTime(int tableSize);

#endif  /* ASC_SUPPORT2_H */ 
