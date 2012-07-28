/**
 * This file is generated by tifstoc. Do not edit!
 * Generated from tifs for tool 'structure-editor' (prefix='')
 */

#include "structure-editor.h"

#define NR_SIG_ENTRIES	18

static char *signature[NR_SIG_ENTRIES] = {
  "rec-terminate(<structure-editor>,<term>)",
  "rec-eval(<structure-editor>,move-selection-down(<term>,<int>))",
  "rec-eval(<structure-editor>,get-sort-at-cursor(<term>))",
  "rec-eval(<structure-editor>,move-selection-left(<term>,<int>))",
  "rec-do(<structure-editor>,set-cursor-at-offset(<term>,<int>))",
  "rec-do(<structure-editor>,set-cursor-at-line-column(<term>,<int>,<int>))",
  "rec-eval(<structure-editor>,get-tree-slices(<term>))",
  "rec-eval(<structure-editor>,get-selected-at-offset-in-tree(<term>,<int>))",
  "rec-eval(<structure-editor>,get-cursor(<term>))",
  "rec-eval(<structure-editor>,slice-tree(<term>))",
  "rec-eval(<structure-editor>,get-focus-at-cursor(<term>))",
  "rec-do(<structure-editor>,delete-editor(<term>))",
  "rec-eval(<structure-editor>,move-selection-right(<term>,<int>))",
  "rec-eval(<structure-editor>,move-selection-up(<term>,<int>))",
  "rec-do(<structure-editor>,move-cursor(<term>,<term>))",
  "rec-eval(<structure-editor>,get-parse-tree(<term>))",
  "rec-do(<structure-editor>,create-editor(<term>,<term>))",
  "rec-do(<structure-editor>,update-editor(<term>,<term>))",
};

/* Event handler for tool 'structure-editor' */
ATerm structure_editor_handler(int conn, ATerm term)
{
  ATerm in, out;
  /* We need some temporary variables during matching */
  int i0, i1;
  ATerm t0, t1;

  if(ATmatch(term, "rec-eval(slice-tree(<term>))", &t0)) {
    return slice_tree(conn, t0);
  }
  if(ATmatch(term, "rec-eval(get-cursor(<term>))", &t0)) {
    return get_cursor(conn, t0);
  }
  if(ATmatch(term, "rec-eval(get-focus-at-cursor(<term>))", &t0)) {
    return get_focus_at_cursor(conn, t0);
  }
  if(ATmatch(term, "rec-eval(get-selected-at-offset-in-tree(<term>,<int>))", &t0, &i0)) {
    return get_selected_at_offset_in_tree(conn, t0, i0);
  }
  if(ATmatch(term, "rec-do(delete-editor(<term>))", &t0)) {
    delete_editor(conn, t0);
    return NULL;
  }
  if(ATmatch(term, "rec-eval(get-tree-slices(<term>))", &t0)) {
    return get_tree_slices(conn, t0);
  }
  if(ATmatch(term, "rec-eval(move-selection-right(<term>,<int>))", &t0, &i0)) {
    return move_selection_right(conn, t0, i0);
  }
  if(ATmatch(term, "rec-do(set-cursor-at-line-column(<term>,<int>,<int>))", &t0, &i0, &i1)) {
    set_cursor_at_line_column(conn, t0, i0, i1);
    return NULL;
  }
  if(ATmatch(term, "rec-eval(move-selection-up(<term>,<int>))", &t0, &i0)) {
    return move_selection_up(conn, t0, i0);
  }
  if(ATmatch(term, "rec-do(set-cursor-at-offset(<term>,<int>))", &t0, &i0)) {
    set_cursor_at_offset(conn, t0, i0);
    return NULL;
  }
  if(ATmatch(term, "rec-do(move-cursor(<term>,<term>))", &t0, &t1)) {
    move_cursor(conn, t0, t1);
    return NULL;
  }
  if(ATmatch(term, "rec-eval(move-selection-left(<term>,<int>))", &t0, &i0)) {
    return move_selection_left(conn, t0, i0);
  }
  if(ATmatch(term, "rec-eval(get-parse-tree(<term>))", &t0)) {
    return get_parse_tree(conn, t0);
  }
  if(ATmatch(term, "rec-eval(get-sort-at-cursor(<term>))", &t0)) {
    return get_sort_at_cursor(conn, t0);
  }
  if(ATmatch(term, "rec-do(create-editor(<term>,<term>))", &t0, &t1)) {
    create_editor(conn, t0, t1);
    return NULL;
  }
  if(ATmatch(term, "rec-eval(move-selection-down(<term>,<int>))", &t0, &i0)) {
    return move_selection_down(conn, t0, i0);
  }
  if(ATmatch(term, "rec-terminate(<term>)", &t0)) {
    rec_terminate(conn, t0);
    return NULL;
  }
  if(ATmatch(term, "rec-do(update-editor(<term>,<term>))", &t0, &t1)) {
    update_editor(conn, t0, t1);
    return NULL;
  }
  if(ATmatch(term, "rec-do(signature(<term>,<term>))", &in, &out)) {
    ATerm result = structure_editor_checker(conn, in);
    if(!ATmatch(result, "[]"))
      ATfprintf(stderr, "warning: not in input signature:\n\t%\n\tl\n", result);
    return NULL;
  }

  ATerror("tool structure-editor cannot handle term %t", term);
  return NULL; /* Silence the compiler */
}

/* Check the signature of the tool 'structure-editor' */
ATerm structure_editor_checker(int conn, ATerm siglist)
{
  return ATBcheckSignature(siglist, signature, NR_SIG_ENTRIES);
}
