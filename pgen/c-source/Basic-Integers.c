#include "asc-support.h"

void register_Basic_Integers() {
}

void resolve_Basic_Integers() {
}

void init_Basic_Integers() {
}

int aterm2int(ATermList arg)
{
  int result = 0;
  while(!ATisEmpty(arg)) {
    ATerm el = ATgetFirst(arg);
    result = 10 * result + (ATgetInt((ATermInt) el)-'0');
    arg = ATgetNext(arg);
  }
  return result;
}

ATermList int2aterm(int value)
{
  ATermList result;
  ATerm ct;
  ct = make_char((value % 10)+'0');
  result = ATmakeList1(ct);
  value = value / 10;
  while (value > 0) {
    ct = make_char((value % 10)+'0');
    result = ATinsert(result,ct);
    value = value / 10;
  }
  return result;
}

