#include "batch.tif.c"

FILE *bout;

term *fromFile()
{  int n1, n2, n3;
   char sbuf[128], *sp;
   n1 = rand()%100;
   n2 = rand()%100;
   n3 = rand()%100;
   sleep(rand()%20);

   sp = TBsprintf("times(%d,plus(%d,%d))", n1, n2, n3);
   strcpy(sbuf, sp);
   return TBmake("snd-value(expr(%s))", sbuf);
 }

void toFile(char *expr, int val)
{   TBprintf(bout, "pair(%s, %d)\n", expr, val);
}

void rec_terminate(term *t)
{
  exit(0);
}
        
void main(int argc, char *argv[])
{
  TBinit("batch", argc, argv, batch_handler, batch_check_in_sign);
  bout = fopen("batch.out", "w");
  if(!bout)
    bout = stdout;
  TBeventloop();
}

