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
#include <unistd.h>    
#include "batch.tif.h"

FILE *bout;

ATerm fromFile(int conn)
{  int n1, n2, n3;
   char sbuf[128], *sp;

   n1 = rand()%100;
   n2 = rand()%100;
   n3 = rand()%100;
   sleep(rand()%20);

   sp = ATwriteToString(ATmake("times(%d,plus(%d,%d))", n1, n2, n3));
   strcpy(sbuf, sp);
   return ATmake("snd-value(expr(<str>))", sbuf);
 }

void toFile(int conn, const char *expr, int val)
{   ATfprintf(bout, "pair(%s, %d)\n", expr, val);
}

void rec_terminate(int conn, ATerm t)
{
  exit(0);
}
        
int main(int argc, char *argv[])
{
  ATerm bottomOfStack;

  ATBinit(argc, argv,&bottomOfStack);
  bout = fopen("batch.out", "wb");
  if(!bout)
    bout = stdout;
  if(ATBconnect(NULL, NULL, -1, batch_handler) >= 0){
    ATBeventloop();
  } else
    fprintf(stderr, "batch: Could not connect to the ToolBus, giving up!\n");
  return 0;
}

