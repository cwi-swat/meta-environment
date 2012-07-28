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
#include <fcntl.h>

/*}}}  */

/*{{{  void write_read(char *name, term *t1) */

void write_read(char *name, term *t1)
{
  int out = creat(name, 0666);
  int in;
  term *t2;

  if(out < 0)
    err_sys_fatal("Can't create %s\n", name);

  TBwrite(out, t1);
  close(out);
  in = open(name, O_RDONLY);

  if(in < 0)
  {
    unlink(name);
    err_sys_fatal("Can't open %s for reading\n", name);
  }

  t2 =TBread(in, TBtrue);
  close(in);
  /*  unlink(name);*/

  if(!t2)
    err_fatal("Parse errors during reading\n");
  else if(!term_equal(t1,t2))
    err_fatal("Terms are unequal\n");
}

/*}}}  */
/*{{{  int main() */

int main()
{
  char cbuf[50000];
  int i;

  init_utils();
  write_read("fa", mk_int(13));
  write_read("fb", mk_str("abc"));
  write_read("fc", mk_appl1(TBlookup("f"), mk_int(13)));
  write_read("fd", mk_str("ab\\\"c"));  
  write_read("fe", mk_str("ab\\\nc")); 
  write_read("ff", mk_str("a\b\f\n\r\vc")); 

  for(i = 0; i < 20000; i++)
    cbuf[i] = i % 256;

  for(i =  9980; i < 10010; i++){
    TBprintf(stderr, "%d ", i);
    write_read("fbin", TBmake(TBtrue, "%b", cbuf, i));
  }

  write_read("blobby", TBmake(TBtrue, "%b", "abc", 4));

  TBprintf(stderr, "Done\n");
  exit(0);
}

/*}}}  */
