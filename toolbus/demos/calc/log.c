#include "log.tif.c"

term *history = NULL;

term *readLog(void){
  TBprintf(stderr, "readLog, history = %t\n", history);
  return TBmake("snd-value(history(%t))", history);
}

void writeLog(char *expr, term *val){
  history = TBmake("[pair(%s,%t),%l])", expr, val, history);
  TBprintf(stderr, "writeLog, history = %t\n", history);
}

void rec_terminate(term *t)
{
  exit(0);
}

void main(int argc, char *argv[])
{
  TBinit("log", argc, argv, log_handler, log_check_in_sign);
  history = TBmake("[]");
  TBprotect(&history);
  TBeventloop();
}
