
/* $Id$
 *
 * In this file we test some features of the pt-support library
 */

#include <MEPT-utils.h>
#include <assert.h>

#define test_equal(msg,a,b) (assert(a == b && msg))

void testCompare()
{ 
  

}

int main(int argc, char *argv[])
{
  ATerm bottomOfStack;

  ATinit(argc, argv, &bottomOfStack);
  PT_initMEPTApi();

  testCompare();

  return 0;
}

