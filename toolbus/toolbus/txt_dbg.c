/*{{{  header */

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

/*}}}  */

/*{{{  includes */

#include "TB.h"

/*}}}  */

/*{{{  term *handle_input_from_toolbus(term *e) */

term *handle_input_from_toolbus(term *e)
{
  int pid1, pid2, Lino, Pos;
  term *Env, *Subs, *Notes, *AtArgs, *trm;
  char *AtFun;

  if(TBmatch(e, "break(%d,%f,%t,%d,%d,%t,%t,%t,%d)",
	     &pid1,
	     &AtFun,
	     &AtArgs,
	     &Lino,
	     &Pos,
	     &Env,
	     &Subs,
	     &Notes,
	     &pid2)){
    TBmsg("%t\n", e);
    return TBmakeTerm("continue(%d)", pid1);

  } else if(TBmatch(e, "terminate")){
    exit(0);

  } else if(TBmatch(e, "shutdown(%t)", &trm)){
    TBmsg("%t\n", trm);
    exit(0);

  } else {
    TBmsg("wrong event received: %t\n", e);
    return NULL;
  }
}

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{

  TBinit("txt_dbg", argc, argv, handle_input_from_toolbus, NULL);
  TBput(TBmakeTerm("attach-debugger"));
  TBeventloop();
  exit(0);
}

/*}}}  */
