/**
 * This file is generated by tifstoc. Do not edit!
 * Generated from tifs for tool 'structure-editor' (prefix='')
 */

#include "structure-editor.tif.h"

#define NR_SIG_ENTRIES	9

static char *signature[NR_SIG_ENTRIES] = {
  "rec-do(<structure-editor>,create-editor(<term>,<term>))",
  "rec-do(<structure-editor>,update-editor(<term>,<term>))",
  "rec-do(<structure-editor>,delete-editor(<term>))",
  "rec-do(<structure-editor>,set-cursor-at-offset(<term>,<int>))",
  "rec-eval(<structure-editor>,get-cursor(<term>))",
  "rec-eval(<structure-editor>,get-focus-at-cursor(<term>))",
  "rec-eval(<structure-editor>,get-sort-at-cursor(<term>))",
  "rec-do(<structure-editor>,move-cursor(<term>,<term>))",
  "rec-terminate(<structure-editor>,<term>)",
};

/* Event handler for tool 'structure-editor' */
ATerm structure_editor_handler(int conn, ATerm term)
{
  ATerm in, out;
  /* We need some temporary variables during matching */
  int i0;
  ATerm t0, t1;

  if(ATmatch(term, "rec-do(set-cursor-at-offset(<term>,<int>))", &t0, &i0)) {
    set_cursor_at_offset(conn, t0, i0);
    return NULL;
  }
  if(ATmatch(term, "rec-eval(get-cursor(<term>))", &t0)) {
    return get_cursor(conn, t0);
  }
  if(ATmatch(term, "rec-do(delete-editor(<term>))", &t0)) {
    delete_editor(conn, t0);
    return NULL;
  }
  if(ATmatch(term, "rec-eval(get-focus-at-cursor(<term>))", &t0)) {
    return get_focus_at_cursor(conn, t0);
  }
  if(ATmatch(term, "rec-do(update-editor(<term>,<term>))", &t0, &t1)) {
    update_editor(conn, t0, t1);
    return NULL;
  }
  if(ATmatch(term, "rec-eval(get-sort-at-cursor(<term>))", &t0)) {
    return get_sort_at_cursor(conn, t0);
  }
  if(ATmatch(term, "rec-do(create-editor(<term>,<term>))", &t0, &t1)) {
    create_editor(conn, t0, t1);
    return NULL;
  }
  if(ATmatch(term, "rec-do(move-cursor(<term>,<term>))", &t0, &t1)) {
    move_cursor(conn, t0, t1);
    return NULL;
  }
  if(ATmatch(term, "rec-terminate(<term>)", &t0)) {
    rec_terminate(conn, t0);
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

