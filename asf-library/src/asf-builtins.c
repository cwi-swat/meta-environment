#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <MEPT-utils.h>
#include <aterm2.h>
#include "asf-builtins.h"

static ATbool initialized = ATfalse;

void initBuiltins(void)
{
  initialized = ATtrue;

  return;
}

PT_Tree shell(ATerm builtin, PT_Tree input)
{
  PT_Tree cmd_arg = PT_getArgsArgumentAt(PT_getTreeArgs(input),4);
  char *cmdline = PT_yieldTree(cmd_arg);
 
  cmdline[strlen(cmdline) - 1] = '\0';

  system(cmdline + 1);

  return input;
}

PT_Tree read_term_from_file(ATerm builtin, PT_Tree input)
{
  PT_Tree file_arg = PT_getArgsArgumentAt(PT_getTreeArgs(input),4);
  char *filestr = NULL;
  ATerm term;
  PT_ParseTree pt = NULL;
  PT_Tree tree = NULL;
  PT_Tree result = input;
  PT_Symbol input_rhs, tree_rhs;
ATwarning("reading: %s\n", PT_yieldTree(input));
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

PT_Tree write_term_to_file(ATerm builtin, PT_Tree input)
{
  PT_Tree file_arg = PT_getArgsArgumentAt(PT_getTreeArgs(input),4);
  PT_Tree tree_arg = PT_getArgsArgumentAt(PT_getTreeArgs(input),8);
  char *filestr = NULL;

  filestr = PT_yieldTree(file_arg);

  if (filestr != NULL && strlen(filestr) > 2) {
    filestr[strlen(filestr) -1 ] = '\0';
    ATwriteToNamedTextFile(PT_TreeToTerm(tree_arg), filestr+1);
  }

  return tree_arg;
}

/* Naive implementation: just do strcmp's until we find the correct
 * function. Idea: use asc-support or similar hashtable implementation.
 */
PT_Tree forwardBuiltin(ATerm builtin, PT_Tree input)
{
  AFun afun;
  char *name = NULL;
  PT_Tree result = input;

  assert(initialized && "builtins are not initialized");
  assert(ATgetType(builtin) == AT_APPL && "builtins should be ATermAppls");

  afun = ATgetAFun(builtin);
  name = ATgetName(afun);

  if (!strcmp(name, "shell")) {
    result = shell(builtin, input);
  }
  if (!strcmp(name, "read-term-from-file")) {
    result = read_term_from_file(builtin, input);
  }
  if (!strcmp(name, "write-term-to-file")) {
    result = write_term_to_file(builtin, input);
  }

  if (result == NULL) {
    ATwarning("WARNING: builtin %s failed to return a valid term\n", name);
    return input;
  }

  return result; 
}
