#ifndef ASF_API_H
#define ASF_API_H

#include <MEPT.h>
#include <ASFAPI.h>

ATbool isTreeAPIFunction(PT_Tree in);
PT_Tree interpretAPICall(PT_Tree in);

PT_Tree interpretConstructorCall(PT_Tree in, AA_Calls calls);
AA_Calls getTreeAPICalls(PT_Tree in);

#endif
