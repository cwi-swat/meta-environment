
#ifndef ASF_UTILS_H
#define ASF_UTILS_H

#include <ASF.h>

/* defining a type for visitor functions for ASF_Condition */
typedef ASF_Condition (*ASF_ConditionVisitor)(ASF_Condition cond); 
typedef ASF_CondEquation (*ASF_CondEquationVisitor)(ASF_CondEquation cond); 
                      
ATbool ASF_isTagDefault(ASF_Tag tag);
int    ASF_isgetCondEquationListLength(ASF_CondEquationList eqs);

int ASF_getCHARListLength(ASF_CHARList list);

#endif
