
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

#ifndef EDITOR_H
#define EDITOR_H

#include <PT.h>

#include "Editor.h"

#define SORT_INVALID "invalid"
#define SORT_TERM    "term"

SE_Editor insertChars(SE_Editor editor, int location, int nr_chars);
SE_Editor deleteChars(SE_Editor editor, int location, int nr_chars);

SE_Editor replaceEditorTreeAtFocus(SE_Editor editor, SE_Focus focus, PT_Tree tree,
				   char *left_layout, char *right_layout);
SE_Editor moveFocus(SE_Editor editor, SE_Move move);
SE_Editor moveFocusToTop(SE_Editor editor);
SE_Focus getFocusAt(PT_ParseTree parse_tree, int location);

SE_Editor newEditorGivenTree(PT_ParseTree parse_tree, char *sort, ATbool dirty);
SE_Editor newEditorGivenText(char *text);
SE_Editor newEditorGivenLength(int length);

#endif /* EDITOR_H */
