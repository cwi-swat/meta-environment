
#ifndef ASF_UTILS_H
#define ASF_UTILS_H

#include <ASF.h>

/* defining a type for visitor functions for ASF_Condition */
typedef void* ASF_ConditionVisitorData;
typedef ASF_Condition (*ASF_ConditionVisitor)(ASF_Condition cond, 
                      ASF_ConditionVisitorData user_data); 

ATbool ASF_isTagDefault(ASF_Tag tag);
int    ASF_isgetCondEquationListLength(ASF_CondEquationList eqs);

ASF_ConditionList foreachConditionInList(ASF_ConditionList list, 
                                         ASF_ConditionVisitor visitor,
                                         ASF_ConditionVisitorData user_data);
#endif
