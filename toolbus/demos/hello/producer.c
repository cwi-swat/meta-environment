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
#include <atb-tool.h>

ATerm *name = NULL;

ATerm producer_handler(int conn, ATerm e)
{
  ATerm tool;

  if(ATmatch(e, "ack-event(<term>)", &tool)){
    return NULL;
  } else {
    ATprintf("producer: wrong event received: %t\n", e);
    return NULL;
  }
}

int main(int argc, char *argv[])
{
  ATerm bottomOfStack;
  int conn;                      /* file descriptor of ToolBus connection */
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
  }

  ATBinit(argc, argv, &bottomOfStack);
  conn = ATBconnect(sname, NULL, -1, producer_handler);
  if(conn < 0){
    fprintf(stderr, "producer: Could not connect to the ToolBus, giving up!\n");
    return -1;
  }
  while(ATtrue){
    sprintf(line, "%s -- %s -- %s -- %s: %d\n", sname, sname, sname, sname, n);
    n++;
    ATBwriteTerm(conn, ATmake("event(<term>,<str>)", name, line));
    if(ATBhandleOne(conn) < 0)
      return -1;
  }
  return 0;
}

