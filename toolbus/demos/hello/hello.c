/*  hello.c -- hello tool in C */

#include <stdio.h>
#include <aterm1.h>                   /* ATerms, level 1 interface */
#include <atb-tool.h>                 /* ToolBus tool interface */

ATerm hello_handler(int conn, ATerm inp)      /* Handle input from ToolBus */
{
  ATerm arg, isig, osig;

  if(ATmatch(inp, "rec-eval(get-text)"))
    return ATmake("snd-value(\"Hello World, my first ToolBus tool in C!\n\")");
  if(ATmatch(inp, "rec-terminate(<term>)", &arg))
    exit(0);
  if(ATmatch(inp, "rec-do(signature(<term>,<term>))", &isig, &osig)){
    return NULL;                      /* we are sloppy and don't do a signature check */
  }
  
  ATerror("hello: wrong input %t received\n", inp);
  return NULL;                    /* Return NULL to indicate that no term
                                       has to be sent back to the ToolBus */
}

int main(int argc, char *argv[])   /* main program of hello tool */
{ ATerm bottomOfStack;

  ATBinit(argc, argv, &bottomOfStack);
  if(ATBconnect(NULL, NULL, -1, hello_handler) >= 0){
    ATBeventloop();
  } else {
    fprintf(stderr, "Could not connect to the ToolBus, giving up!\n");
    return -1;
  }
  return 0;
}
