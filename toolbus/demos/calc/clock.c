
#include "clock.tif.c"

#include <time.h>
#include <string.h>

term *readTime()
{  time_t tloc;  
   char *s;  

   time(&tloc);  
   s = ctime(&tloc);
   s[strlen(s)-1] = '\0'; /* remove trailing newline */
   return TBmake("snd-value(%s)", s);
}

void rec_terminate(term *msg)
{
  exit(0);
}

void main(int argc, char *argv[])
{
  TBinit("clock", argc, argv, clock_handler, clock_check_in_sign);
  TBeventloop();
}
