/*

    ToolBus -- The ToolBus Application Architecture
    Copyright (C) 1998-2000  Stichting Mathematisch Centrum, Amsterdam, 
                             The  Netherlands.

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

#include <stdlib.h>
#include "log.tif.h"

ATerm history = NULL;

ATerm readLog(int conn){
  ATfprintf(stderr, "readLog, history = %t\n", history);
  return ATmake("snd-value(history(<term>))", history);
}

void writeLog(int conn, const char *expr, ATerm val){
  history = ATmake("[pair(<str>,<term>),<list>])", expr, val, history);
  ATfprintf(stderr, "writeLog, history = %t\n", history);
}

void rec_terminate(int conn, ATerm t)
{
  exit(0);
}

int main(int argc, char *argv[])
{
  ATerm bottomOfStack;

  ATBinit(argc, argv, &bottomOfStack);
  history = ATmake("[]");
  ATprotect(&history);
  if(ATBconnect(NULL, NULL, -1, log_handler) >= 0){
    ATBeventloop();
  } else
    fprintf(stderr, "log: Could not connect to the ToolBus, giving up!\n");
  return 0;
}
