#include "TB.h"

term *handle_input_from_toolbus(term *e)
{
  char *text;
  term *arg;
  if(TBmatch(e, "rec-do(print-text(%s))", &text)){
    TBmsg("%s", text);
    return NULL;
  } else
    if(TBmatch(e, "rec-terminate(%t)", &arg)){
      exit(0);
  } else {
    TBmsg("wrong event received: %t\n", e);
    return NULL;
  }
}

void main(int argc, char *argv[])
{

  TBinit("printer", argc, argv, handle_input_from_toolbus, NULL);
  TBeventloop();
}
