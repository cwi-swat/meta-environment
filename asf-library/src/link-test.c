#include "asf-builtins.h"
#include <stdlib.h>
#include <assert.h>

int main(void)
{
  /* This program does nothing, it is used to test if all built-ins
   * have an implementation by calling the forward function and let the linker
   * throw warnings
   */

  assert(0 && "this program has no functionality");

  forwardBuiltin(NULL,NULL);

  return 0;
}
