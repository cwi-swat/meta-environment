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

  $Id$

 */

/*}}}  */

/*{{{   includes */

#include <stdlib.h>

#include "se.h"
#include "editor.h"
#include "focus.h"
#include "area.h"

/*}}}  */
/*{{{   globals */

static char myversion[] = "0.1";

/*}}}  */

/*{{{  static ATbool isValidMove(char *move) */

static ATbool
isValidMove(char *move)
{
  return strcmp(move, MOVE_LEFT) == 0
    || strcmp(move, MOVE_RIGHT) == 0
    || strcmp(move, MOVE_UP) == 0 || strcmp(move, MOVE_DOWN) == 0;
}


/*}}}  */

/*{{{  void rec_terminate(int cid, ATerm t) */

void
rec_terminate(int cid, ATerm t)
{
  exit(0);
}

/*}}}  */
/*{{{  ATerm newEditor(int cid, ATerm editorId, char *text) */

ATerm
newEditor(int cid, ATerm editorId, char *text)
{
  ATerm focus, editor;

  editor = newEditorInstanceGivenText(text);
  PutValue(editorInstances, editorId, editor);

  focus = getCurrentFocus(editor);

  return ATmake("snd-value(<term>)", focus);
}

/*}}}  */
/*{{{  ATerm newEditorGivenTree(int cid, ATerm editorId, ATerm tree) */

ATerm
newEditorGivenTree(int cid, ATerm editorId, ATerm tree)
{
  ATerm focus, editor;

  editor = newEditorInstanceGivenTree(tree);
  PutValue(editorInstances, editorId, editor);

  focus = getCurrentFocus(editor);

  return ATmake("snd-value(<term>)", focus);
}

/*}}}  */
/*{{{  void remove_tree(int cid, ATerm editorId) */

void
remove_tree(int cid, ATerm editorId)
{
  RemoveKey(editorInstances, editorId);
}

/*}}}  */
/*{{{  ATerm insertChars(int cid, ATerm editorId, int location, char *text) */

ATerm
insertChars(int cid, ATerm editorId, int location, char *text)
{
  ATerm focus;
  ATerm editor = GetValue(editorInstances, editorId);

  editor = insertCharsAtLocation(editor, location, text);
  PutValue(editorInstances, editorId, editor);

  focus = getCurrentFocus(editor);

  return ATmake("snd-value(<term>)", focus);
}

/*}}}  */
/*{{{  ATerm deleteChars(int cid, ATerm editorId, int location) */

ATerm
deleteChars(int cid, ATerm editorId, int location, int count)
{
  ATerm focus;
  ATerm editor = GetValue(editorInstances, editorId);

  editor = deleteCharsAtLocation(editor, location, count);
  PutValue(editorInstances, editorId, editor);

  focus = getCurrentFocus(editor);

  return ATmake("snd-value(<term>)", focus);
}

/*}}}  */
/*{{{  void replaceFocus(int cid, ATerm editorId, ATerm focus, ATerm tree) */

void
replaceFocus(int cid, ATerm editorId, ATerm focus, ATerm tree)
{
  ATerm editor = GetValue(editorInstances, editorId);

  editor = replaceFocusByTree(editor, focus, tree);
  PutValue(editorInstances, editorId, editor);
}

/*}}}  */
/*{{{  void setMultipleFocus(int cid, ATerm editorId, ATerm focuses) */

void
setMultipleFocus(int cid, ATerm editorId, ATerm focuses)
{
  ATerm editor = GetValue(editorInstances, editorId);

  editor = setFocuses(editor, focuses);
  PutValue(editorInstances, editorId, editor);
}

/*}}}  */
/*{{{  ATerm moveFocus(int cid, ATerm editorId, char *text) */

ATerm
moveFocus(int cid, ATerm editorId, char *text)
{
  ATerm newEditor, focus;
  ATerm editor = GetValue(editorInstances, editorId);

  if (isValidMove(text)) {
    newEditor = moveFocusInEditor(editor, ATparse(text));
  }
  else {
    ATerror("Illegal move requested: %s\n", text);
    newEditor = editor;
  }
  focus = getCurrentFocus(newEditor);

  PutValue(editorInstances, editorId, newEditor);

  return ATmake("snd-value(<term>)", focus);
}

/*}}}  */
/*{{{  ATerm setFocusAtLocation(int cid, ATerm editorId, int location) */

ATerm
setFocusAtLocation(int cid, ATerm editorId, int location)
{
  ATerm focus;
  ATerm editor = GetValue(editorInstances, editorId);
  ATerm editorTree = getTreeInEditor(editor);

  focus = getFocusGivenLocation(editorTree, location);

  editor = setCurrentFocus(editor, focus);

  PutValue(editorInstances, editorId, editor);

  return ATmake("snd-value(<term>)", focus);
}

/*}}}  */
/*{{{  ATerm makeTreeInvalid(int cid, ATerm editorId) */

ATerm
makeTreeInvalid(int cid, ATerm editorId)
{
  ATerm editor, focus;

  editor = GetValue(editorInstances, editorId);
  editor = makeTreeInvalidInEditor(editor);
  focus = getCurrentFocus(editor);

  PutValue(editorInstances, editorId, editor);

  return ATmake("snd-value(<term>)", focus);
}

/*}}}  */
/*{{{  ATerm getDirtyFocuses(int cid, ATerm editorId) */

ATerm
getDirtyFocuses(int cid, ATerm editorId)
{
  ATerm editor = GetValue(editorInstances, editorId);

  editor = joinFocuses(editor);
  PutValue(editorInstances, editorId, editor);

  return ATmake("snd-value(<term>)", getFocuses(editor));
}

/*}}}  */
/*{{{  ATerm getTree(int cid, ATerm editorId) */

ATerm
getTree(int cid, ATerm editorId)
{
  ATerm editor = GetValue(editorInstances, editorId);
  ATerm tree = getTreeInEditor(editor);

  return ATmake("snd-value(<term>)", tree);
}

/*}}}  */
/*{{{  ATerm makeFocusSort(int cid, char *nonterminal, ATerm focus) */

ATerm
makeFocusSort(int cid, char *nonterminal, ATerm focus)
{
  char *sortText;
  ATerm sort = getFocusSort(focus);

  if (ATmatch(sort, "sort(<str>)", &sortText)) {
    if (strcmp(sortText, "invalid")) {
      return ATmake("snd-value(<str>)", sortText);
    }
  }
  return ATmake("snd-value(<str>)", nonterminal);
}

/*}}}  */
/*{{{  ATerm calcErrorLocation(int cid, ATerm focus, ATerm error) */

ATerm
calcErrorLocation(int cid, ATerm focus, ATerm error)
{
  int start = getIntStartOfArea(getFocusArea(focus));
  ATerm posTerm = ATelementAt((ATermList) error, 3);

  int errorPos = ATgetInt((ATermInt) ATgetArgument((ATermAppl) posTerm, 0));

  return ATmake("snd-value(<int>)", start + errorPos);
}

/*}}}  */
/*{{{  ATerm registerSymbols(int cid, ATerm editorId, ATerm startSymbols) */

ATerm
registerSymbols(int cid, ATerm editorId, ATerm startSymbols)
{
  ATerm editor = GetValue(editorInstances, editorId);

  editor = putStartSymbols(editor, startSymbols);
  PutValue(editorInstances, editorId, editor);

  return ATmake("snd-value(startsymbols-registered)");
}

/*}}}  */
/*{{{  void usage(char *prg, ATbool is_err) */

void
usage(char *prg, ATbool is_err)
{
  ATwarning("usage: %s [aterm-options] [toolbus-options]\n", prg);
  ATwarning("use '%s -at-help' to get more options.\n", prg);
  ATwarning("This program can only be used as a ToolBus tool!\n");
  exit(is_err ? 1 : 0);
}

/*}}}  */
/*{{{  void version(const char *msg) */

void
version(const char *msg)
{
  ATwarning("%s v%s\n", msg, myversion);
  exit(1);
}

/*}}}  */
/*{{{  int main(int argc, char *argv[]) */

int
main(int argc, char *argv[])
{
  int i, cid;
  ATerm bottomOfStack;

  for (i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-h") == 0) {
      usage(argv[0], ATfalse);
    }
    else if (strcmp(argv[i], "-V") == 0) {
      version(argv[0]);
    }
  }

  ATBinit(argc, argv, &bottomOfStack);
  AFinit(argc, argv, &bottomOfStack);


  cid = ATBconnect(NULL, NULL, -1, se_handler);

  editorInstances = CreateValueStore(100, 75);

  ATBeventloop();

  return 0;
}

/*}}}  */
