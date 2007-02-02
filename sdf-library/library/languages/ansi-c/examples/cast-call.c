#include <stdio.h>

typedef char* print;

int main(void)
{
  (printf)("aap\n"); /* call to printf function */
  (print)("aap\n");  /* cast to print type      */
  return 0;
}
