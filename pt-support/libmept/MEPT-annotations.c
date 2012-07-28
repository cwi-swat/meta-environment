#include <MEPT.h>

/** 
 * \file
 * Functions that manipulate generic ATerm annotations on parse trees.
 */


ATerm PT_getTreeAnnotations(PT_Tree tree)
{
  return AT_getAnnotations((ATerm) tree);
}


PT_Tree PT_setTreeAnnotations(PT_Tree tree, ATerm annos)
{
  return (PT_Tree)AT_setAnnotations((ATerm) tree, annos);
}

PT_Tree PT_removeTreeAnnotations(PT_Tree arg)
{
  ATerm atArg = PT_TreeToTerm(arg);

  if (AT_getAnnotations(atArg) != NULL) {
    atArg = AT_removeAnnotations(atArg);
  }

  return PT_TreeFromTerm(atArg);
}

PT_Tree PT_removeTreeAnnotationsMemo(PT_Tree arg) 
{
  static ATermTable cache = NULL;
  PT_Tree result = NULL;

  if (cache == NULL) {
    cache = ATtableCreate(1024, 75);
  }

  result = PT_TreeFromTerm(ATtableGet(cache, PT_TreeToTerm(arg)));

  if (result == NULL) {
    result = PT_removeTreeAnnotations(arg);
    ATtablePut(cache, PT_TreeToTerm(arg), PT_TreeToTerm(result));
  }

  return result;
}



ATerm PT_getTreeAnnotation(PT_Tree tree, ATerm key)
{
  ATerm atTree = PT_TreeToTerm(tree);

  return ATgetAnnotation(atTree, key);
}

PT_Tree PT_setTreeAnnotation(PT_Tree tree, ATerm key, ATerm value)
{
  ATerm t = PT_TreeToTerm(tree);

  t = ATsetAnnotation(t, key, value);

  return PT_TreeFromTerm(t);
}


ATerm PT_getParseTreeAnnotation(PT_ParseTree parse_tree, ATerm key)
{
  ATerm atParseTree = PT_ParseTreeToTerm(parse_tree);

  return ATgetAnnotation(atParseTree, key);
}


PT_ParseTree PT_setParseTreeAnnotation(PT_ParseTree parse_tree, ATerm key, ATerm value)
{
  ATerm t = PT_ParseTreeToTerm(parse_tree);

  t = ATsetAnnotation(t, key, value);

  return PT_ParseTreeFromTerm(t);
}


ATerm PT_getParseTreeAnnotations(PT_ParseTree pt)
{
  return AT_getAnnotations((ATerm) pt);
}

