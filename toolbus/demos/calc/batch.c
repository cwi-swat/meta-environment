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

