#include "common.h"

/*{{{  PT_Tree read_term_from_file(ATerm builtin, PT_Tree input) */

PT_Tree read_term_from_file(ATerm builtin, PT_Tree input)
{
  PT_Tree file_arg = CO_getFunctionArgument(input, 0);
  char *filestr = NULL;
  ATerm term;
  PT_ParseTree pt = NULL;
  PT_Tree tree = NULL;
  PT_Tree result = input;
  PT_Symbol input_rhs, tree_rhs;

  if (PT_hasTreeProd(input)) {
    input_rhs = PT_getProductionRhs(PT_getTreeProd(input));

    filestr = PT_yieldTree(file_arg);

    if (filestr != NULL && strlen(filestr) > 2) {
      filestr[strlen(filestr) - 1] = '\0';
      term = ATreadFromNamedFile(filestr+1);

      if (term != NULL) {
        pt = PT_ParseTreeFromTerm(term);

        if (PT_isValidParseTree(pt)) {
          tree = PT_getParseTreeTree(pt);

          if (PT_hasTreeProd(tree)) {
            tree_rhs = PT_getProductionRhs(PT_getTreeProd(tree));

            if (PT_isEqualSymbol(tree_rhs, input_rhs)) {
              result = tree;
            }
          }
        }
      }
    }
  }

  return result;
}

/*}}}  */
/*{{{  PT_Tree write_term_to_file(ATerm builtin, PT_Tree input) */

PT_Tree write_term_to_file(ATerm builtin, PT_Tree input)
{
  PT_Tree file_arg = CO_getFunctionArgument(input, 0);
  PT_Tree tree_arg = CO_getFunctionArgument(input, 1);
  PT_ParseTree pt = PT_makeValidParseTreeFromTree(tree_arg);
  char *filestr = NULL;

  filestr = PT_yieldTree(file_arg);

  if (filestr != NULL && strlen(filestr) > 2) {
    filestr[strlen(filestr) -1 ] = '\0';
    ATwriteToNamedTextFile(PT_ParseTreeToTerm(pt), filestr+1);
  }

  return tree_arg;
}

/*}}}  */
