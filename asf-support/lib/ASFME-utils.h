#ifndef ASF_UTILS_H
#define ASF_UTILS_H

#include <ASFME.h>

ATbool ASF_isTreeLexicalConstructorFunction(ASF_Tree tree);
ATbool ASF_isTreeAmbConstructorFunction(ASF_Tree tree);
ATbool ASF_isTreeTraversalFunction(ASF_Tree tree);                              ATbool ASF_isTreeGetterFunction(ASF_Tree tree);

ATbool ASF_isTagDefault(ASF_ASFTag tag);

ASF_ASFConditionalEquationList ASF_unionASFConditionalEquationList(ASF_ASFConditionalEquationList l1, ASF_ASFConditionalEquationList l2);
ASF_ASFConditionalEquationList ASF_makeASFConditionalEquationList(ATermList l);

ASF_OptLayout ASF_makeLayoutEmpty();

ASF_Tree ASF_LexicalConstructorTreeToLexicalTree(ASF_Tree constructor);

ASF_ASFConditionalEquationList ASF_getASFModuleEquationList(ASF_ASFModule module);
ASF_ASFTestEquationTestList ASF_getASFModuleTestList(ASF_ASFModule module);

#endif
