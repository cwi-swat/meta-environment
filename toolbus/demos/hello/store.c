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

FILE *Out;

ATerm store_handler(int conn, ATerm e)
{
  char *s1, *s2;

  if(ATmatch(e, "do(store,<str>,<str>)", &s1, &s2)){
    fprintf(Out, "%s%s", s1, s2);
    return NULL;
  } else {
    ATerror("store: wrong event received: %t\n", e);
    return NULL;
  }
}

int main(int argc, char *argv[])
{  ATerm bottomOfStack;

  ATBinit(argc, argv, &bottomOfStack);
  Out = fopen("store.out", "wb");
  if(ATBconnect(NULL, NULL, -1, store_handler) >= 0){
    ATBeventloop();
    return 0;
  } else {
    fprintf(stderr, "store: Could not connect to the ToolBus, giving up!\n");
    return -1;
  }
}
