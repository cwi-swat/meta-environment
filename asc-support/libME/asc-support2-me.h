#ifndef ASC_SUPPORT2_H
#define ASC_SUPPORT2_H

#include "asc-support-me.h"
#include "asc-apply-me.h"
#include <PT-utils.h>
#include <ASF-utils.h>    

extern ATerm innermost(PT_Tree tree);
extern PT_ParseTree toasfix(ATerm tree);
void ASC_initRunTime(int tableSize);

#endif  /* ASC_SUPPORT2_H */ 
