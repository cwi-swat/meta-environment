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
#include "TB.h"

FILE *Out;

term *handle_input_from_toolbus(term *e)
{
  char *s1, *s2;

  if(TBmatch(e, "do(store,%s,%s)", &s1, &s2)){
    fprintf(Out, "%s%s", s1, s2);
    return NULL;
  } else {
    TBmsg("wrong event received: %t\n", e);
    return NULL;
  }
}

void main(int argc, char *argv[])
{

  TBinit("store", argc, argv, handle_input_from_toolbus, NULL);
  Out = fopen("store.out", "w");
  TBeventloop();
}
