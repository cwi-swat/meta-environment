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
#include "log.tif.c"

term *history = NULL;

term *readLog(void){
  TBprintf(stderr, "readLog, history = %t\n", history);
  return TBmake("snd-value(history(%t))", history);
}

void writeLog(char *expr, term *val){
  history = TBmake("[pair(%s,%t),%l])", expr, val, history);
  TBprintf(stderr, "writeLog, history = %t\n", history);
}

void rec_terminate(term *t)
{
  exit(0);
}

void main(int argc, char *argv[])
{
  TBinit("log", argc, argv, log_handler, log_check_in_sign);
  history = TBmake("[]");
  TBprotect(&history);
  TBeventloop();
}
