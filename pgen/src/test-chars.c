#include <stdio.h>
#include <aterm2.h>
#include <assert.h>

#include "characters.h"

static void test_chars() {
  CC_Class *cc[CC_BITS], *cc_input, *temp, *all;
  ATerm input, output;
  int i;
 
  input = ATparse("char-class([0,range(9,10),12,23,range(30,50),range(128,256)])");
  cc_input = CC_ClassFromTerm(input);

  temp = CC_makeClassEmpty();
  CC_addATermClass(temp, input);
  assert(CC_isEqual(temp, cc_input));
  CC_free(temp);

  temp = CC_makeClassEmpty();
  assert(CC_isEmpty(temp));
  for (i=0; i<CC_BITS; i++) {
    cc[i] = CC_ClassFromInt(i);
    if (i == CC_EOF) {
      assert(CC_isEOF(cc[i]));
    } else {
      assert(!CC_isEOF(cc[i]));
    }
    CC_union(temp, cc[i], temp);
    assert(!CC_isEOF(temp));
  }
  all = CC_makeClassAllChars();
  assert(!CC_isEmpty(all));

  assert(CC_isEqual(temp, all));
  CC_difference(temp, all, temp);
  assert(CC_isEmpty(temp));

  CC_copy(all, temp);
  CC_difference(temp, cc_input, temp);
  CC_complement(temp, temp);
  assert(CC_isEqual(temp, cc_input));


  CC_copy(all, temp);
  CC_difference(temp, cc_input, temp);
  CC_union(temp, cc_input, temp);
  assert(CC_isEqual(temp, all));

  CC_copy(all, temp);
  CC_intersection(temp, cc_input, temp);
  assert(CC_isEqual(temp, cc_input));

  assert(CC_isSubset(cc_input, all));

  output = CC_ClassToTerm(cc_input);
  /*
  ATwarning("input = %t\noutput = %t\n", input, output);
  assert(ATisEqual(output, input));
  */
}

static void test_sets() {
  CC_Set set;
  CC_Class *cc[10];

  CC_initSet(&set);

  cc[0] = CC_addToSet(&set);
  CC_addChar(cc[0], 1);
  CC_addChar(cc[0], 2);
  CC_addChar(cc[0], 3);
  CC_addChar(cc[0], 9);
  CC_addChar(cc[0], 10);
  CC_addChar(cc[0], 11);

  cc[1] = CC_addToSet(&set);
  CC_addChar(cc[1], 3);
  CC_addChar(cc[1], 4);

  cc[2] = CC_addToSet(&set);
  CC_addChar(cc[2], 4);
  CC_addChar(cc[2], 5);
  CC_addChar(cc[2], 6);
  CC_addChar(cc[2], 7);
  CC_addChar(cc[2], 8);

  cc[3] = CC_addToSet(&set);
  CC_addChar(cc[3], 3);
  CC_addChar(cc[3], 8);
  CC_addChar(cc[3], 9);

  CC_partitionSet(&set);

  /*
  printf("partitioned set:\n");
  CC_writeSetToFile(stdout, &set);
  printf("\n");
  */

  CC_flushSet(&set);

  cc[0] = CC_addToSet(&set);
  CC_addATermClass(cc[0], ATparse("char-class([range(65,90)])"));

  cc[1] = CC_addToSet(&set);
  CC_addATermClass(cc[1], ATparse("char-class([range(65,90)])"));

  cc[2] = CC_addToSet(&set);
  CC_addATermClass(cc[2], ATparse("char-class([76])"));

  CC_partitionSet(&set);

  /*
  printf("partitioned set:\n");
  CC_writeSetToFile(stdout, &set);
  printf("\n");
  */
}

int main(int argc, char *argv[]) {
  ATerm bottomOfStack;

  ATinit(argc, argv, &bottomOfStack);
  CC_init();

  test_chars();

  test_sets();

  return 0;
}
