
#include <ASFME-utils.h>
#include <PTMEPT-utils.h>

#include <assert.h>

static ASF_OptLayout newline = NULL;
static ASF_OptLayout space = NULL;
/*{{{  static void initLayout() */

static void initLayout()
{
  if (newline == NULL || space == NULL) {
    newline = ASF_makeLayoutNewline();
    ASF_protectOptLayout(&newline);

    space = ASF_makeLayoutSpace();
    ASF_protectOptLayout(&space);
  }
}

/*}}}  */

/* This library lowers the terms in an ASF specification to AsFix level.
 * The idea is that before and after lowering a TYPE CORRECT specification
 * remains. This means that the types of conditions and equations must
 * be adapted to 'Tree'.
 *
 * The inverse operation (lifting) should do the same but in reverse 
 * direction.
 *
 * Most of this algorithm is boring traversal, down to the user-defined
 * syntax, then when we arrive there we call lowerPT, and adapt the types
 * of the equation/condition accordingly.
 */

/*{{{  static ASF_ASFEquation ASF_lowerEquation(ASF_ASFEquation equation) */

static ASF_ASFEquation ASF_lowerEquation(ASF_ASFEquation equation)
{
  ASF_Tree lhs = (ASF_Tree) 
    PTPT_lowerTree((PTPT_Tree) ASF_getASFEquationLhs(equation));
  ASF_Tree rhs = (ASF_Tree) 
    PTPT_lowerTree((PTPT_Tree) ASF_getASFEquationRhs(equation));
  ATerm type = 
      PT_SymbolToTerm(PT_getProductionRhs(PT_getTreeProd((PT_Tree) lhs)));

  if(!ATisEqual(type, PT_getProductionRhs(PT_getTreeProd((PT_Tree) rhs)))) {
    ATwarning("lower: equation not type-preserving\n");
    return equation;
  }

  equation = ASF_makeASFEquationDefault(type,type,lhs,space,space,rhs);

  return equation;
}

/*}}}  */

/*{{{  static ASF_ASFCondition ASF_lowerCondition(ASF_ASFCondition condition) */

static ASF_ASFCondition ASF_lowerCondition(ASF_ASFCondition condition)
{
  ASF_Tree lhs = (ASF_Tree) 
    PTPT_lowerTree((PTPT_Tree) ASF_getASFConditionLhs(condition));
  ASF_Tree rhs = (ASF_Tree) 
    PTPT_lowerTree((PTPT_Tree) ASF_getASFConditionRhs(condition));
  ATerm type = 
    PT_SymbolToTerm(PT_getProductionRhs(PT_getTreeProd((PT_Tree) lhs)));

  if(!ATisEqual(type, PT_getProductionRhs(PT_getTreeProd((PT_Tree) rhs)))) {
    ATwarning("lower: condition not type correct\n");
    return condition;
  }

  /* using the setters, we can abstract from the type of condition */
  condition = ASF_setASFConditionTypeOfLhs(condition, type);
  condition = ASF_setASFConditionTypeOfRhs(condition, type);
  condition = ASF_setASFConditionLhs(condition, lhs);
  condition = ASF_setASFConditionRhs(condition, rhs);

  return condition;
}

/*}}}  */
/*{{{  static ASF_ASFConditions ASF_lowerConditions(ASF_ASFConditions conditions) */

static ASF_ASFConditions ASF_lowerConditions(ASF_ASFConditions conditions)
{
  ASF_ASFConditionList list = ASF_getASFConditionsList(conditions);
  ASF_ASFConditionList result = ASF_makeASFConditionListEmpty();

  for ( ; !ASF_isASFConditionListEmpty(list);
	list = ASF_getASFConditionListTail(list)) {
    ASF_ASFCondition condition = ASF_getASFConditionListHead(list);

    condition = ASF_lowerCondition(condition);

    result = ASF_makeASFConditionListMany(condition,space,newline,result);
  }
  
  return ASF_setASFConditionsList(conditions, result);
}

/*}}}  */

/*{{{  static ASF_ASFTestEquation ASF_lowerTestEquation(ASF_ASFTestEquation test) */

static ASF_ASFTestEquation ASF_lowerTestEquation(ASF_ASFTestEquation test)
{
  if (ASF_hasASFTestEquationASFConditions(test)) {
    test = ASF_setASFTestEquationASFConditions(test, ASF_lowerConditions(ASF_getASFTestEquationASFConditions(test)));
  }

  test = ASF_setASFTestEquationASFCondition(test, ASF_lowerCondition(ASF_getASFTestEquationASFCondition(test)));

  return test;
}

/*}}}  */
/*{{{  static ASF_ASFConditionalEquation ASF_lowerConditionalEquation(ASF_ASFConditionalEquation equation) */

static ASF_ASFConditionalEquation ASF_lowerConditionalEquation(ASF_ASFConditionalEquation equation)
{
  if (ASF_hasASFConditionalEquationASFConditions(equation)) {
    equation = ASF_setASFConditionalEquationASFConditions(equation, ASF_lowerConditions(ASF_getASFConditionalEquationASFConditions(equation)));
  }

  equation = ASF_setASFConditionalEquationASFEquation(equation, ASF_lowerEquation(ASF_getASFConditionalEquationASFEquation(equation)));

  return equation;
}

/*}}}  */
/*{{{  static ASF_ASFTestEquationTestList ASF_lowerTests(ASF_ASFTestEquationTestList list) */

static ASF_ASFTestEquationTestList ASF_lowerTests(ASF_ASFTestEquationTestList list)
{
  ASF_ASFTestEquationTestList result = ASF_makeASFTestEquationTestListEmpty();

  initLayout();

  for ( ; !ASF_isASFTestEquationTestListEmpty(list);
	list = ASF_getASFTestEquationTestListTail(list)) {
    ASF_ASFTestEquation eq = ASF_getASFTestEquationTestListHead(list);

    eq = ASF_lowerTestEquation(eq);

    result = ASF_makeASFTestEquationTestListMany(eq, newline, result);
  }

  return result;
}

/*}}}  */
/*{{{  static ASF_ASFConditionalEquationList ASF_lowerEquations(ASF_ASFConditionalEquationList list) */

ASF_ASFConditionalEquationList ASF_lowerEquations(ASF_ASFConditionalEquationList list)
{
  ASF_ASFConditionalEquationList result = ASF_makeASFConditionalEquationListEmpty();

  initLayout();

  for ( ; !ASF_isASFConditionalEquationListEmpty(list);
	list = ASF_getASFConditionalEquationListTail(list)) {
    ASF_ASFConditionalEquation eq = ASF_getASFConditionalEquationListHead(list);

    eq = ASF_lowerConditionalEquation(eq);

    result = ASF_makeASFConditionalEquationListMany(eq, newline, result);
  }

  return result;
}

/*}}}  */
/*{{{  static ASF_ASFSection ASF_lowerSection(ASF_ASFSection section) */

static ASF_ASFSection ASF_lowerSection(ASF_ASFSection section)
{
  if (ASF_isASFSectionEquations(section)) {
    ASF_ASFConditionalEquationList list = ASF_getASFSectionList(section);

    list = ASF_lowerEquations(list);

    return ASF_setASFSectionList(section, list);
  }
  else if (ASF_isASFSectionTests(section)) {
    ASF_ASFTestEquationTestList list = ASF_getASFSectionTestList(section);

    list = ASF_lowerTests(list);

    return ASF_setASFSectionTestList(section, list);
  }

  ATwarning("unexpected ASF section\n");
  return section;
}

/*}}}  */

/*{{{  ASF_ASFSections ASF_lowerSections(ASF_ASFSection sections) */

ASF_ASFSectionList ASF_lowerSections(ASF_ASFSectionList sections)
{
  ASF_ASFSectionList result = ASF_makeASFSectionListEmpty();

  initLayout();

  for ( ; !ASF_isASFSectionListEmpty(sections); 
	sections = ASF_getASFSectionListTail(sections)) {
    ASF_ASFSection head = ASF_getASFSectionListHead(sections);

    head = ASF_lowerSection(head);

    result = ASF_makeASFSectionListMany(head, newline, result);
  }

  return result;

}

/*}}}  */
/*{{{  ASF_ASFModule ASF_lowerModule(ASF_ASFModule module) */

ASF_ASFModule ASF_lowerModule(ASF_ASFModule module)
{
  ASF_ASFSectionList sections = ASF_getASFModuleList(module);

  sections = ASF_lowerSections(sections);

  return ASF_setASFModuleList(module, sections);
}

/*}}}  */

