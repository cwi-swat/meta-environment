#ifndef EQS_CHECKER_H
#define EQS_CHECKER_H

#include <string.h>
#include <MEPT-utils.h>
#include <ASFME-utils.h>

ATermList checkEquations(ASF_ASFConditionalEquationList eqs);
ATermList checkTests(ASF_ASFTestEquationTestList tests); 
ATermList checkASFConditionalEquationList(ASF_ASFConditionalEquationList condEquationList);

#endif  /* EQS_CHECKER_H */
