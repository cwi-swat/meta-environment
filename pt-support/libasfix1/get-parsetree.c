#include <stdio.h>
#include <assert.h>
#include "PT.h"

int main(int argc, char *argv[])
{
  ATerm     bottomOfStack;
  ATerm     contents;

  ATinit(argc, argv, &bottomOfStack);
  initPTApi();

  contents = ATreadFromNamedFile(argv[1]);
  assert(contents != NULL);

  ATprintf("%t\n", getAsFixTree(makeAsFixFromTerm(contents)));

  return 0;
}
