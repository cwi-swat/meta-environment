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

term *name = NULL;

term *handle_input_from_toolbus(term *e)
{
  term *tool;

  if(TBmatch(e, "ack-event(%t)", &tool)){
    return NULL;
  } else {
    TBmsg("wrong event received: %t\n", e);
    return NULL;
  }
}

void main(int argc, char *argv[])
{
  char line[128], *sname = NULL;
  int i = 1, n = 1;
  
  while(i < argc){
    if(streq(argv[i], "-name")){
      sname = argv[i+1];
      break;
    }
    i++;
  }

  if(!sname){
    fprintf(stderr, "%s: No -name given\n", argv[0]);
    exit(1);
  } else
    name = TBmakeTerm("%f",sname);
  TBinit(sname, argc, argv, handle_input_from_toolbus, NULL);

  while(TBtrue){
    sprintf(line, "%s -- %s -- %s -- %s: %d\n", sname, sname, sname, sname, n);
    n++;
    TBput(TBmakeTerm("event(%t,%s)", name, line));
    TBget();
  }
  TBeventloop();
}

