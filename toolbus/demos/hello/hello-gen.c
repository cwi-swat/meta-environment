/*  hello-gen.c  -- hello tool in C using generated interface hello.tif.c */

#include "hello.tif.h"                   /* Include generated tool interface */

ATerm get_text(int conn)                 /* Generate a hello text */
{
  return ATmake("snd-value(\"Hello World, my first ToolBus tool in C!\n\")");
}

void rec_terminate(int conn, ATerm msg)  /* Mandatory function to terminate tool */
{
  exit(0);
}

int main(int argc, char *argv[])         /* main program of hello tool */
{
  ATerm bottomOfStack;

  ATBinit(argc, argv, &bottomOfStack);
  if(ATBconnect(NULL, NULL, -1, hello_handler) >= 0) {
    ATBeventloop();
  } else {
    fprintf(stderr, "Could not connect to the ToolBus, giving up!\n");
    return -1;
  }
  return 0;
  
}
