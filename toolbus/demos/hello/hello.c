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
#include "TB.h"                     /* Standard header file */

term *hello_handler(term *inp)      /* Handle input from ToolBus */
{
  term *arg;

  if(TBmatch(inp, "rec-eval(get-text)"))
    return TBmake("snd-value(\"Hello World, my first ToolBus tool in C!\n\")");
  if(TBmatch(inp, "rec-terminate(%t)", &arg))
    exit(0);
  else {
    TBprintf(stderr, "hello: wrong input %t received\n", inp);
    return NULL;                    /* Return NULL to indicate that no term
                                       has to be sent back to the ToolBus */
  }
}

void main(int argc, char *argv[])   /* main program of hello tool */
{
  TBinit("hello", argc, argv, hello_handler, NULL);
  TBeventloop();
}
