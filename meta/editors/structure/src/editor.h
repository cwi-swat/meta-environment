
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

#define MOVE_LEFT      "Left"
#define MOVE_RIGHT     "Right"
#define MOVE_UP        "Up"
#define MOVE_DOWN      "Down"

extern ATermTable editorInstances;

ATerm newEditorInstanceGivenText(char *text);
ATerm newEditorInstanceGivenTree(ATerm tree);
ATerm getTreeInEditor(ATerm editor);
ATerm getFocuses(ATerm editor);
ATerm getCurrentFocus(ATerm editor);
ATerm setCurrentFocus(ATerm editor, ATerm focus);
ATerm setFocuses(ATerm editor, ATerm newFocusList);
ATerm getStartSymbols(ATerm editor);
ATerm putStartSymbols(ATerm editor, ATerm newStartSymbols);
ATerm replaceFocusByTree(ATerm editor, ATerm focus, ATerm tree);
ATerm makeTreeInvalidInEditor(ATerm editor);
ATerm insertCharsAtLocation(ATerm editor, int location, char *text);
ATerm deleteCharsAtLocation(ATerm editor, int location, int count);
ATerm moveFocusInEditor(ATerm editor, ATerm move);
ATerm getFocusGivenLocation(ATerm editorTree, int location);
ATerm getModifiedStatus(ATerm editor);

#endif /* EDITOR_H */
