/* $Id$ */

/*{{{  includes */

#include <stdio.h>
#include <stdlib.h>

#include "structure-editor.tif.h"

/*}}}  */

/*{{{  void create_editor(int cid, ATerm editorId, ATerm parseTree) */

void create_editor(int cid, ATerm editorId, ATerm parseTree)
{
}

/*}}}  */
/*{{{  void update_editor(int cid, ATerm editorId, ATerm parseTree) */

void update_editor(int cid, ATerm editorId, ATerm parseTree)
{
}

/*}}}  */
/*{{{  void delete_editor(int cid, ATerm editorId) */

void delete_editor(int cid, ATerm editorId)
{
}

/*}}}  */
/*{{{  void set_cursor_at_offset(int cid, ATerm editorId, int offset) */

void set_cursor_at_offset(int cid, ATerm editorId, int offset)
{
}

/*}}}  */
/*{{{  ATerm get_focus_at_cursor(int cid, ATerm editorId) */

ATerm get_focus_at_cursor(int cid, ATerm editorId)
{
  return ATmake("snd-value(focus(fix-me))");
}

/*}}}  */
/*{{{  void move_cursor(int cid, ATerm editorId, ATerm direction) */

void move_cursor(int cid, ATerm editorId, ATerm direction)
{
}

/*}}}  */
/*{{{  void rec_terminate(int cid, ATerm message) */

void rec_terminate(int cid, ATerm message)
{
  ATwarning("structure-editor.c:rec_terminate: %t\n", message);
  exit(0);
}

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  ATerm bottomOfStack;

  ATBinit(argc, argv, &bottomOfStack);

  return 0;
}

/*}}}  */
