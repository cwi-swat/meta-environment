#include "builtin-common.h"

/*{{{  static PT_Tree read_term_from_file(PT_Tree file_arg) */

static PT_Tree read_term_from_file(PT_Tree file_arg)
{
  char *filestr = NULL;
  ATerm term;
  PT_ParseTree pt = NULL;
  PT_Tree result = NULL;

  filestr = PT_yieldTree(file_arg);

  if (filestr != NULL && strlen(filestr) > 2) {
    filestr[strlen(filestr) - 1] = '\0';
    term = ATreadFromNamedFile(filestr+1);

    if (term != NULL) {
      pt = PT_ParseTreeFromTerm(term);

      if (PT_isValidParseTree(pt)) {
	result = PT_getParseTreeTree(pt);
      }
    }
  }

  return result;
}

/*}}}  */
/*{{{  PT_Tree ASF_read_term_from_file(PT_Tree input) */

PT_Tree ASFE_read_term_from_file(PT_Tree input)
{
  PT_Tree file_arg = CO_getFunctionArgument(input, 0);/*{{{*//*}}}*/
  PT_Tree result = NULL;

  result = read_term_from_file(file_arg); 

  return result ? result : input;
}

/*}}}  */
/*{{{  PT_Tree ASC_read_term_from_file(ATerm afile_arg) */

PT_Tree ASC_read_term_from_file(ATerm afile_arg)
{
  PT_Tree file_arg = muASFToTree(afile_arg);
  PT_Tree result = NULL;

  result = read_term_from_file(file_arg);

  return result ? result : PT_makeTreeLit("TODO: make proper normal form");
}

/*}}}  */

/*{{{  static PT_Tree write_term_to_file(PT_Tree input) */

static PT_Tree write_term_to_file(PT_Tree file_arg, PT_Tree tree_arg)
{
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
/*{{{  PT_Tree ASFE_write_term_to_file(PT_Tree input) */

PT_Tree ASFE_write_term_to_file(PT_Tree input)
{
  PT_Tree file_arg = CO_getFunctionArgument(input, 0);
  PT_Tree tree_arg = CO_getFunctionArgument(input, 1);

  return write_term_to_file(file_arg, tree_arg);
}

/*}}}  */
/*{{{  PT_Tree write_term_to_file(PT_Tree input) */

PT_Tree ASC_write_term_to_file(ATerm afile_arg, ATerm atree_arg)
{
  PT_Tree file_arg = muASFToTree(afile_arg);
  PT_Tree tree_arg = muASFToTree(atree_arg);

  return write_term_to_file(file_arg, tree_arg);
}

/*}}}  */
