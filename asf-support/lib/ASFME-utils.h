
#ifndef ASF_UTILS_H
#define ASF_UTILS_H

#include <ASFME.h>

ATbool ASF_isTreeLexicalConstructorFunction(ASF_Tree tree);

ATbool ASF_isTagDefault(ASF_Tag tag);
int    ASF_getCondEquationListLength(ASF_CondEquationList eqs);

ASF_CondEquationList ASF_concatCondEquationList(ASF_CondEquationList l1,
                                                ASF_CondEquationList l2);
ASF_CondEquationList ASF_unionCondEquationList(ASF_CondEquationList l1,
                                               ASF_CondEquationList l2);

int ASF_getCHARListLength(ASF_CHARList list);

ASF_Layout ASF_makeLayoutEmpty();

#endif
