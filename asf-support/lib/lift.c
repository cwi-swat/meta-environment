
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

/* This library lifts the terms in an ASF specification to AsFix level.
 * The idea is that before and after lifting a TYPE CORRECT specification
 * remains. This means that the types of conditions and equations must
 * be adapted to 'Tree'.
 *
 * The inverse operation (lowering) should do the same but in reverse 
 * direction.
 *
 * Most of this algorithm is boring traversal, down to the user-defined
 * syntax, then when we arrive there we call liftPT, and adapt the types
 * of the equation/condition accordingly.
 */

/*{{{  static ASF_ASFEquation ASF_liftEquation(ASF_ASFEquation equation) */

static ASF_ASFEquation ASF_liftEquation(ASF_ASFEquation equation)
{
  ASF_Tree lhs = (ASF_Tree) 
    PTPT_liftTree((PT_Tree) ASF_getASFEquationLhs(equation));
  ASF_Tree rhs = (ASF_Tree) 
    PTPT_liftTree((PT_Tree) ASF_getASFEquationRhs(equation));
  ATerm type = PT_SymbolToTerm(PT_makeSymbolCf(PT_makeSymbolSort("Tree")));

  initLayout();

  equation = ASF_makeASFEquationDefault(type,type,lhs,space,space,rhs);

  return equation;
}

/*}}}  */

/*{{{  static ASF_ASFCondition ASF_liftCondition(ASF_ASFCondition condition) */

static ASF_ASFCondition ASF_liftCondition(ASF_ASFCondition condition)
{
  ASF_Tree lhs = (ASF_Tree) 
    PTPT_liftTree((PT_Tree) ASF_getASFConditionLhs(condition));
  ASF_Tree rhs = (ASF_Tree) 
    PTPT_liftTree((PT_Tree) ASF_getASFConditionRhs(condition));
  ATerm type = PT_SymbolToTerm(PT_makeSymbolCf(PT_makeSymbolSort("Tree")));

  initLayout();

  /* using the setters, we can abstract from the type of condition */
  condition = ASF_setASFConditionTypeOfLhs(condition, type);
  condition = ASF_setASFConditionTypeOfRhs(condition, type);
  condition = ASF_setASFConditionLhs(condition, lhs);
  condition = ASF_setASFConditionRhs(condition, rhs);

  return condition;
}

/*}}}  */
/*{{{  static ASF_ASFConditions ASF_liftConditions(ASF_ASFConditions conditions) */

static ASF_ASFConditions ASF_liftConditions(ASF_ASFConditions conditions)
{
  ASF_ASFConditionList list = ASF_getASFConditionsList(conditions);
  ASF_ASFConditionList result = ASF_makeASFConditionListEmpty();

  for ( ; !ASF_isASFConditionListEmpty(list);
	list = ASF_getASFConditionListTail(list)) {
    ASF_ASFCondition condition = ASF_getASFConditionListHead(list);

    condition = ASF_liftCondition(condition);

    result = ASF_makeASFConditionListMany(condition,space,newline,result);
  }
  
  return ASF_setASFConditionsList(conditions, result);
}

/*}}}  */

/*{{{  static ASF_ASFTestEquation ASF_liftTestEquation(ASF_ASFTestEquation test) */

static ASF_ASFTestEquation ASF_liftTestEquation(ASF_ASFTestEquation test)
{
  if (ASF_hasASFTestEquationASFConditions(test)) {
    test = ASF_setASFTestEquationASFConditions(test, ASF_liftConditions(ASF_getASFTestEquationASFConditions(test)));
  }

  test = ASF_setASFTestEquationASFCondition(test, ASF_liftCondition(ASF_getASFTestEquationASFCondition(test)));

  return test;
}

/*}}}  */
/*{{{  static ASF_ASFConditionalEquation ASF_liftConditionalEquation(ASF_ASFConditionalEquation equation) */

static ASF_ASFConditionalEquation ASF_liftConditionalEquation(ASF_ASFConditionalEquation equation)
{
  if (ASF_hasASFConditionalEquationASFConditions(equation)) {
    equation = ASF_setASFConditionalEquationASFConditions(equation, ASF_liftConditions(ASF_getASFConditionalEquationASFConditions(equation)));
  }

  equation = ASF_setASFConditionalEquationASFEquation(equation, ASF_liftEquation(ASF_getASFConditionalEquationASFEquation(equation)));

  return equation;
}

/*}}}  */
/*{{{  static ASF_ASFTestEquationTestList ASF_liftTests(ASF_ASFTestEquationTestList list) */

static ASF_ASFTestEquationTestList ASF_liftTests(ASF_ASFTestEquationTestList list)
{
  ASF_ASFTestEquationTestList result = ASF_makeASFTestEquationTestListEmpty();

  for ( ; !ASF_isASFTestEquationTestListEmpty(list);
	list = ASF_getASFTestEquationTestListTail(list)) {
    ASF_ASFTestEquation eq = ASF_getASFTestEquationTestListHead(list);

    eq = ASF_liftTestEquation(eq);

    result = ASF_makeASFTestEquationTestListMany(eq, newline, result);
  }

  return result;
}

/*}}}  */
/*{{{  static ASF_ASFConditionalEquationList ASF_liftEquations(ASF_ASFConditionalEquationList list) */

ASF_ASFConditionalEquationList ASF_liftEquations(ASF_ASFConditionalEquationList list)
{
  ASF_ASFConditionalEquationList result = ASF_makeASFConditionalEquationListEmpty();

  for ( ; !ASF_isASFConditionalEquationListEmpty(list);
	list = ASF_getASFConditionalEquationListTail(list)) {
    ASF_ASFConditionalEquation eq = ASF_getASFConditionalEquationListHead(list);

    eq = ASF_liftConditionalEquation(eq);

    result = ASF_makeASFConditionalEquationListMany(eq, newline, result);
  }

  return result;
}

/*}}}  */
/*{{{  static ASF_ASFSection ASF_liftSection(ASF_ASFSection section) */

static ASF_ASFSection ASF_liftSection(ASF_ASFSection section)
{
  if (ASF_isASFSectionEquations(section)) {
    ASF_ASFConditionalEquationList list = ASF_getASFSectionList(section);

    list = ASF_liftEquations(list);

    return ASF_setASFSectionList(section, list);
  }
  else if (ASF_isASFSectionTests(section)) {
    ASF_ASFTestEquationTestList list = ASF_getASFSectionTestList(section);

    list = ASF_liftTests(list);

    return ASF_setASFSectionTestList(section, list);
  }

  assert(0 && "unexpected ASF section\n");
  return NULL;
}

/*}}}  */

/*{{{  ASF_ASFSectionList ASF_liftSections(ASF_ASFSectionList sections) */

ASF_ASFSectionList ASF_liftSections(ASF_ASFSectionList sections)
{
  ASF_ASFSectionList result = ASF_makeASFSectionListEmpty();

  initLayout();

  for ( ; !ASF_isASFSectionListEmpty(sections); 
	sections = ASF_getASFSectionListTail(sections)) {
    ASF_ASFSection head = ASF_getASFSectionListHead(sections);

    head = ASF_liftSection(head);

    result = ASF_makeASFSectionListMany(head, newline, result);
  }

  return result;
}

/*}}}  */

/*{{{  ASF_ASFModule ASF_liftModule(ASF_ASFModule module) */

ASF_ASFModule ASF_liftModule(ASF_ASFModule module)
{
  ASF_ASFSectionList sections = ASF_getASFModuleList(module);

  sections = ASF_liftSections(sections);

  return ASF_setASFModuleList(module, sections);
}

/*}}}  */

