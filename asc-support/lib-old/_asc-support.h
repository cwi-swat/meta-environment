#ifndef _ASC_SUPPORT_H
#define _ASC_SUPPORT_H

#include "asc-support.h"
#include <PT-utils.h>
#include <ASF-utils.h>    

extern ATerm innermost(PT_Tree tree);
extern PT_ParseTree toasfix(ATerm tree);
void ASC_initRunTime(int tableSize);

#endif  /* _ASC_SUPPORT_H */ 
