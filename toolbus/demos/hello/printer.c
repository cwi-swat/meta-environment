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
#include "atb-tool.h"

ATerm printer_handler(int conn, ATerm e)
{
  char *text;
  ATerm arg;
  if(ATmatch(e, "rec-do(print-text(<str>))", &text)){
    ATprintf("%s", text);
    return NULL;
  } else
    if(ATmatch(e, "rec-terminate(<term>)", &arg)){
      exit(0);
  } else {
    ATerror("printer: wrong event received: %t\n", e);
    return NULL;
  }
}

int main(int argc, char *argv[])
{
  ATerm bottomOfStack;

  ATBinit(argc, argv, &bottomOfStack);
  if(ATBconnect(NULL, NULL, -1, printer_handler) >= 0){
    ATBeventloop();
  } else {
    fprintf(stderr, "printer: Could not connect to the ToolBus, giving up!\n");
    return -1;
  }
  return 0;
}                    

