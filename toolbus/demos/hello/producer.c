#include "TB.h"

term *name = NULL;

term *handle_input_from_toolbus(term *e)
{
  term *tool;

  if(TBmatch(e, "ack-event(%t)", &tool)){
    return NULL;
  } else {
    TBmsg("wrong event received: %t\n", e);
    return NULL;
  }
}

void main(int argc, char *argv[])
{
  char line[128], *sname = NULL;
  int i = 1, n = 1;
  
  while(i < argc){
    if(streq(argv[i], "-name")){
      sname = argv[i+1];
      break;
    }
    i++;
  }

  if(!sname){
    fprintf(stderr, "%s: No -name given\n", argv[0]);
    exit(1);
  } else
    name = TBmakeTerm("%f",sname);
  TBinit(sname, argc, argv, handle_input_from_toolbus, NULL);

  while(TBtrue){
    sprintf(line, "%s -- %s -- %s -- %s: %d\n", sname, sname, sname, sname, n);
    n++;
    TBput(TBmakeTerm("event(%t,%s)", name, line));
    TBget();
  }
  TBeventloop();
}

