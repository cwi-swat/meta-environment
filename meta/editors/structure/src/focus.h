
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

#ifndef FOCUS_H
#define FOCUS_H

ATerm newFocus(ATerm path, ATerm sort, ATerm area);
ATerm setDirty(ATerm focus);
ATerm setClean(ATerm focus);
ATerm newFocusList(ATerm focus);
ATerm setFocusPath(ATerm focus, ATerm path);
ATerm getFocusPath(ATerm focus);
ATerm setFocusSort(ATerm focus, ATerm newSort);
ATerm getFocusSort(ATerm focus);
ATerm setFocusArea(ATerm focus, ATerm newArea);
ATerm getFocusArea(ATerm focus);
ATerm createFocus(ATerm tree, ATerm path);
ATbool inFocusArea(ATerm focus, int loc);
ATbool afterFocusArea(ATerm focus, int loc);
ATerm updateFocus(ATerm tree, ATerm focuses, int location, int length);
ATerm applyMoveToFocus(ATerm editor, ATerm move);
ATerm joinFocuses(ATerm editor);  
ATerm joinDirtyFocuses(ATerm editor);  
ATerm makeEmptyFocus();
ATbool isEmptyFocus(ATerm focus);
ATerm expandFocusToStartSymbol(ATerm editor, ATerm focus);

#endif
