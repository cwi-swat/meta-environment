
/*{{{   file header */

/*

    Meta-Environment - An environment for language prototyping.
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

/*
 * The version of se is written by Mark van den Brand. 
 */

/*}}}  */

#ifndef AREA_H
#define AREA_H

ATerm newLength(int length);
ATerm newStart(int start);
ATerm newArea(ATerm start, ATerm length);
ATerm getLengthOfArea(ATerm area);
int getIntLengthOfArea(ATerm area);
ATerm setIntLengthOfArea(ATerm area, int newLength);
int getIntStartOfArea(ATerm area);
ATerm setIntStartOfArea(ATerm area, int newStart);
ATerm createArea(ATerm path, ATerm tree);
ATbool inArea(ATerm area, int loc);
ATbool afterArea(ATerm area, int loc);
int getLength(ATerm atLength);
ATbool beforeArea(ATerm area, int loc);

#endif /* AREA_H */
