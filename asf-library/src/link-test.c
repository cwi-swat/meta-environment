#include "asf-builtins.h"
#include <stdlib.h>
#include <assert.h>

int main(void)
{
  /* This program does nothing, it is used to test if all built-ins
   * have an implementation by calling the forward function and let the linker
   * throw warnings
   */

  if(fprintf(stderr, "This program does nothing!\n") == 0) {
    forwardBuiltin(NULL,NULL);
  }

  return 1;
}
