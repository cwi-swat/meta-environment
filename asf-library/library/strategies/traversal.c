#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <MEPT-utils.h>
#include <aterm2.h>

/* note that by using AsFix trees as keys the storing and retrieval
 * of ATerm annotations depends on whitespace!
 */

PT_Tree strategy_all(ATerm builtin, PT_Tree input)
{
  ATwarning("WARNING: all is not implemented yet");
  return input;
}

PT_Tree strategy_some(ATerm builtin, PT_Tree input)
{
  ATwarning("WARNING: all is not implemented yet");

  return input;
}

PT_Tree strategy_one(ATerm builtin, PT_Tree input)
{
  ATwarning("WARNING: one is not implemented yet");
  return input;
}
