/*

    AsFix -- The AsFix (ASF+SDF Prefix) library
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

   $Id$
*/
/*
The module {\tt asfix2sym} defines functions that transform
asfix productions and iters into symbols. These symbols can
then be used when compiling AsFix to epic/rnx
*/

#include "aterm2.h"
#include <malloc.h>

Symbol AFprod2RNxSymbol(ATerm prod);
Symbol AFiter2RNxSymbol(ATerm iter);
Symbol AFsort2RNxSymbol(ATerm sort);
