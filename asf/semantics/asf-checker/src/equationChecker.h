#ifndef EQS_CHECKER_H
#define EQS_CHECKER_H

#include <string.h>
#include <MEPT-utils.h>
#include <ASFME-utils.h>
#include <ErrorAPI.h>

ERR_FeedbackList checkEquations(ASF_ASFConditionalEquationList eqs);
ERR_FeedbackList checkTests(ASF_ASFTestEquationTestList tests); 
ERR_FeedbackList checkASFConditionalEquationList(ASF_ASFConditionalEquationList condEquationList);
ERR_Feedback makeMessage(char *msg, ATerm subject);
ERR_FeedbackList makeAmbiguityMessage(void *subject);

#endif  /* EQS_CHECKER_H */
