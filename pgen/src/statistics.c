/*

    PGEN - - the SDF2 parse table generator. 
    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam,
                        The Netherlands.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/              
#include <unistd.h>
#include <stdio.h> 
#include <aterm1.h> 
#include <sys/time.h> 
#include <sys/resource.h>    
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
  if (!(PT_Log = fopen(fnam, "w"))) {
    ATerror("%s%sCannot create logfile %s\n",  PT_COND_STRING(prg), prg?": ":"", fnam);
  }
/*
  IF_VERBOSE(ATwarning("%s%slogging to %s\n",  PT_COND_STRING(prg), prg?": ":"", fnam));
*/
  return PT_Log;
}

FILE  *PT_log(void)
{
  return PT_Log;
}

void PT_CloseLog(void)
{
  if (PT_Log) {
    fclose(PT_Log);
  }
}
