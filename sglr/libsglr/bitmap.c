/*

    SGLR - the Scannerless Generalized LR parser.
    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam,
                        The Netherlands.
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
/*
 $Id$
 */   

#include "bitmap.h"
#include <stdlib.h>
#include <stdio.h>

Bitmap BitmapCreate(int size)
{
  Bitmap b;
  if (size <= 0) {
    b = NULL;
  }
  else {
    b = calloc(size, sizeof(int));

    if (b == NULL) {
      ATerror("out of memory in BitmapCreate\n");
    }    
  }
 
  return b;
}

void BitmapDestroy(Bitmap b)
{
  if (b) {
    free(b);
  }
}

Bitmap BitmapSet(Bitmap b, int index)
{
   b[index] = 1;
   
   return b;
}

Bitmap BitmapUnset(Bitmap b, int index)
{
  b[index] = 0;

  return b;
}

int BitmapIsSet(Bitmap b, int index)
{
  return b[index];
}
