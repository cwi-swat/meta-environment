/*

    PGEN - the SDF2 parse table generator.
    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, The Netherlands. 

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
#include "asc-support.h"

void register_Basic_Integers() {
}

void resolve_Basic_Integers() {
}

void init_Basic_Integers() {
}

int aterm2int(ATermList arg)
{
  int result = 0;
  while(!ATisEmpty(arg)) {
    ATerm el = ATgetFirst(arg);
    result = 10 * result + (ATgetInt((ATermInt) el)-'0');
    arg = ATgetNext(arg);
  }
  return result;
}

ATermList int2aterm(int value)
{
  ATermList result;
  ATerm ct;
  ct = make_char((value % 10)+'0');
  result = ATmakeList1(ct);
  value = value / 10;
  while (value > 0) {
    ct = make_char((value % 10)+'0');
    result = ATinsert(result,ct);
    value = value / 10;
  }
  return result;
}

