#include <stdio.h> 
#include <string.h>
#include <unistd.h>
#include <sys/time.h> 
#include <sys/resource.h>    

#include <aterm1.h> 

#include "statistics.h"

struct rusage rsrc_usage;

double PT_Timer(void)
{
  static double cur = 0;
  double prev;

  prev = cur;
  getrusage(RUSAGE_SELF, &rsrc_usage);

  cur  =  (double) (rsrc_usage.ru_utime.tv_sec) +
    (double) ((rsrc_usage.ru_utime.tv_usec) * 1.0e-06);

  prev = cur - prev;
  return prev > 0 ? prev: 0;
}          

FILE  *PT_Log = NULL;

FILE  *PT_OpenLog(char *prg, char *fnam)
{
  if (PT_Log) {
    return PT_Log;
  }

  if (!fnam || !strcmp(fnam, "")) {
    fnam = "pgen-stats.txt";
  }
  if (!(PT_Log = fopen(fnam, "wb"))) {
    ATerror("%s%sCannot create logfile %s\n",  PT_COND_STRING(prg), prg?": ":"", fnam);
  }
  return PT_Log;
}

FILE  *PT_log(void)
{
  if (PT_Log == NULL) {
    return stderr;
  }
  return PT_Log;
}

void PT_CloseLog(void)
{
  if (PT_Log) {
    fclose(PT_Log);
  }
}
