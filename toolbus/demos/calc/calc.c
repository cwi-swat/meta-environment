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
#include "calc.tif.h"

int calculate(ATerm t)
{ int n;
  char *s;
  ATerm t1, t2;

  if(ATmatch(t, "<int>", &n))
     return n;
  else if(ATmatch(t, "<str>", &s))
	  return atoi(s);
  else if(ATmatch(t, "plus(<term>,<term>)", &t1, &t2))
	  return calculate(t1) + calculate(t2);
  else if(ATmatch(t, "times(<term>,<term>)", &t1, &t2))
	  return calculate(t1) * calculate(t2);
  else {
        ATerror("panic in calculate: %t\n", t);
        return 0;
      }
}

ATerm expr(int conn, const char *s)
{ ATerm trm = ATmake(s);

  if(!trm)
    return ATmake("snd-value(calc-error(<str>))", s);
  else
    return ATmake("snd-value(val(<int>))", calculate(trm));
}

void rec_terminate(int conn, ATerm t)
{
  exit(0);
}

int main(int argc, char *argv[])
{
  /* extern term_list *tool_in_sign, *tool_out_sign;
     term *trm; */
  ATerm bottomOfStack;

  ATBinit(argc, argv, &bottomOfStack);
  if(ATBconnect(NULL, NULL, -1, calc_handler) >= 0){
    ATBeventloop();
  } else {
    fprintf(stderr, "calc: Could not connect to the ToolBus, giving up!\n");
  }

  return 0;
}
