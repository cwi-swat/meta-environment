#ifndef ASF_UTILS_H
#define ASF_UTILS_H

#include <ASFME.h>

ATbool ASF_isTreeLexicalConstructorFunction(ASF_Tree tree);
ATbool ASF_isTreeAmbConstructorFunction(ASF_Tree tree);
ATbool ASF_isTreeTraversalFunction(ASF_Tree tree);                              
ATbool ASF_isTreeGetterFunction(ASF_Tree tree);

ATbool ASF_isTagDefault(ASF_ASFTag tag);

int ASF_getTestEquationListLength(ASF_ASFTestEquationTestList list);
ASF_ASFConditionalEquationList ASF_unionASFConditionalEquationList(ASF_ASFConditionalEquationList l1, 
								   ASF_OptLayout separator,
								   ASF_ASFConditionalEquationList l2);

ASF_ASFConditionalEquationList ASF_makeASFConditionalEquationList(ATermList l);

ASF_OptLayout ASF_makeLayoutEmpty();
ASF_OptLayout ASF_makeLayoutNewline();
ASF_OptLayout ASF_makeLayoutSpace();

ASF_Tree ASF_LexicalConstructorTreeToLexicalTree(ASF_Tree constructor);

ASF_ASFConditionalEquationList ASF_getASFModuleEquationList(ASF_ASFModule module);
ASF_ASFTestEquationTestList ASF_getASFModuleTestList(ASF_ASFModule module);

ASF_ASFTagId ASF_makeTagId(const char* str);

ASF_ASFModule ASF_liftModule(ASF_ASFModule module);
ASF_ASFModule ASF_lowerModule(ASF_ASFModule module);
ASF_ASFSectionList ASF_liftSections(ASF_ASFSectionList module);
ASF_ASFSectionList ASF_lowerSections(ASF_ASFSectionList module);
ASF_ASFConditionalEquationList ASF_liftEquations(ASF_ASFConditionalEquationList list);
ASF_ASFConditionalEquationList ASF_lowerEquations(ASF_ASFConditionalEquationList list);

#endif
