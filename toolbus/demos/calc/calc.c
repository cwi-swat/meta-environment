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
#include "calc.tif.c"

int calculate(term *t)
{ int n;
  char *s;
  term *t1, *t2;

  if(TBmatch(t, "%d", &n))
     return n;
  else if(TBmatch(t, "%s", &s))
	  return atoi(s);
  else if(TBmatch(t, "plus(%t,%t)", &t1, &t2))
	  return calculate(t1) + calculate(t2);
  else if(TBmatch(t, "times(%t,%t)", &t1, &t2))
	  return calculate(t1) * calculate(t2);
  else {
        TBmsg("panic in calculate: %t\n", t);
        return 0;
      }
}

term *expr(char *s)
{ term *trm = TBmake(s);

  if(!trm)
    return TBmake("snd-value(calc-error(%s))", s);
  else
    return TBmake("snd-value(%d)", calculate(trm));
}

void rec_terminate(term *t)
{
  exit(0);
}

int main(int argc, char *argv[])
{
  extern term_list *tool_in_sign, *tool_out_sign;
  term *trm;

  TBinit("calc", argc, argv, calc_handler, calc_check_in_sign);

  TBeventloop();

  return 0;
}
