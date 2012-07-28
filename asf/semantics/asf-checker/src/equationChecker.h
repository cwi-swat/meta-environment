#ifndef EQS_CHECKER_H
#define EQS_CHECKER_H

#include <string.h>
#include <MEPT-utils.h>
#include <ASFME-utils.h>
#include <Error.h>

ERR_ErrorList checkEquations(ASF_ASFConditionalEquationList eqs);
ERR_ErrorList checkTests(ASF_ASFTestEquationTestList tests); 
ERR_ErrorList checkASFConditionalEquationList(ASF_ASFConditionalEquationList condEquationList);
ERR_Error makeMessage(const char *msg, ATerm subject);
ERR_ErrorList makeAmbiguityMessage(void *subject);

#endif  /* EQS_CHECKER_H */
