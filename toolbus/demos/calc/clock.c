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


#include <time.h>
#include <string.h>
#include "clock.tif.c"

ATerm readTime(int conn)
{  time_t tloc;  
   char *s;  

   time(&tloc);  
   s = ctime(&tloc);
   s[strlen(s)-1] = '\0'; /* remove trailing newline */
   return ATmake("snd-value(time(<str>))", s);
}

void rec_terminate(int conn, ATerm msg)
{
  exit(0);
}

int main(int argc, char *argv[])
{
  ATerm bottomOfStack;

  ATBinit(argc, argv, &bottomOfStack);
  if(ATBconnect(NULL, NULL, -1, clock_handler) >= 0){
    ATBeventloop();
  } else
    fprintf(stderr, "clock: Could not connect to the ToolBus, giving up!\n");
  return 0;
}
