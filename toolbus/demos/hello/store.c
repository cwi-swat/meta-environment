#include "TB.h"

FILE *Out;

term *handle_input_from_toolbus(term *e)
{
  char *s1, *s2;

  if(TBmatch(e, "do(store,%s,%s)", &s1, &s2)){
    fprintf(Out, "%s%s", s1, s2);
    return NULL;
  } else {
    TBmsg("wrong event received: %t\n", e);
    return NULL;
  }
}

void main(int argc, char *argv[])
{

  TBinit("store", argc, argv, handle_input_from_toolbus, NULL);
  Out = fopen("store.out", "w");
  TBeventloop();
}
