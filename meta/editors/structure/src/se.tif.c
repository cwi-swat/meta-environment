/**
 * This file is generated by /ufs/jurgenv/glt/bin/tifstoc. Do not edit!
 * Generated from tifs for tool 'se' (prefix='')
 * Implementation generated at Fri Dec 20 11:27:18 2002
 */

#include "se.tif.h"

#define NR_SIG_ENTRIES	20

static char *signature[NR_SIG_ENTRIES] = {
  "rec-eval(<se>,new-editor-given-text(<term>,<str>))",
  "rec-eval(<se>,new-editor-given-tree(<term>,<term>))",
  "rec-eval(<se>,change-status(<term>))",
  "rec-do(<se>,replace-focus(<term>,<term>,<term>))",
  "rec-do(<se>,set-multiple-focus(<term>,<list>))",
  "rec-eval(<se>,move-focus-to-root(<term>))",
  "rec-eval(<se>,move-focus(<term>,<term>))",
  "rec-eval(<se>,invalidate-tree(<term>))",
  "rec-eval(<se>,set-focus(<term>,<int>))",
  "rec-eval(<se>,get-parse-tree(<term>))",
  "rec-eval(<se>,get-focussed-tree(<term>))",
  "rec-eval(<se>,replace-focussed-tree(<term>,<term>))",
  "rec-eval(<se>,check-tree-sort(<str>,<term>))",
  "rec-eval(<se>,get-focus-sort(<str>,<term>))",
  "rec-eval(<se>,get-dirty-focuses(<term>))",
  "rec-eval(<se>,calc-error-location(<term>,<list>))",
  "rec-do(<se>,remove-tree(<term>))",
  "rec-do(<se>,modify(<term>))",
  "rec-eval(<se>,get-modification-status(<term>))",
  "rec-terminate(<se>,<term>)",
};

/* Event handler for tool 'se' */
ATerm se_handler(int conn, ATerm term)
{
  ATerm in, out;
  /* We need some temporary variables during matching */
  int i0;
  char *s0;
  ATerm t0, t1, t2;

  if(ATmatch(term, "rec-eval(get-parse-tree(<term>))", &t0)) {
    return get_parse_tree(conn, t0);
  }
  if(ATmatch(term, "rec-eval(set-focus(<term>,<int>))", &t0, &i0)) {
    return set_focus(conn, t0, i0);
  }
  if(ATmatch(term, "rec-eval(get-focussed-tree(<term>))", &t0)) {
    return get_focussed_tree(conn, t0);
  }
  if(ATmatch(term, "rec-eval(invalidate-tree(<term>))", &t0)) {
    return invalidate_tree(conn, t0);
  }
  if(ATmatch(term, "rec-eval(replace-focussed-tree(<term>,<term>))", &t0, &t1)) {
    return replace_focussed_tree(conn, t0, t1);
  }
  if(ATmatch(term, "rec-eval(move-focus(<term>,<term>))", &t0, &t1)) {
    return move_focus(conn, t0, t1);
  }
  if(ATmatch(term, "rec-eval(check-tree-sort(<str>,<term>))", &s0, &t0)) {
    return check_tree_sort(conn, s0, t0);
  }
  if(ATmatch(term, "rec-eval(move-focus-to-root(<term>))", &t0)) {
    return move_focus_to_root(conn, t0);
  }
  if(ATmatch(term, "rec-eval(get-focus-sort(<str>,<term>))", &s0, &t0)) {
    return get_focus_sort(conn, s0, t0);
  }
  if(ATmatch(term, "rec-do(set-multiple-focus(<term>,<term>))", &t0, &t1)) {
    set_multiple_focus(conn, t0, t1);
    return NULL;
  }
  if(ATmatch(term, "rec-eval(get-dirty-focuses(<term>))", &t0)) {
    return get_dirty_focuses(conn, t0);
  }
  if(ATmatch(term, "rec-do(replace-focus(<term>,<term>,<term>))", &t0, &t1, &t2)) {
    replace_focus(conn, t0, t1, t2);
    return NULL;
  }
  if(ATmatch(term, "rec-eval(calc-error-location(<term>,<term>))", &t0, &t1)) {
    return calc_error_location(conn, t0, t1);
  }
  if(ATmatch(term, "rec-eval(change-status(<term>))", &t0)) {
    return change_status(conn, t0);
  }
  if(ATmatch(term, "rec-do(remove-tree(<term>))", &t0)) {
    remove_tree(conn, t0);
    return NULL;
  }
  if(ATmatch(term, "rec-eval(new-editor-given-tree(<term>,<term>))", &t0, &t1)) {
    return new_editor_given_tree(conn, t0, t1);
  }
  if(ATmatch(term, "rec-do(modify(<term>))", &t0)) {
    modify(conn, t0);
    return NULL;
  }
  if(ATmatch(term, "rec-eval(new-editor-given-text(<term>,<str>))", &t0, &s0)) {
    return new_editor_given_text(conn, t0, s0);
  }
  if(ATmatch(term, "rec-eval(get-modification-status(<term>))", &t0)) {
    return get_modification_status(conn, t0);
  }
  if(ATmatch(term, "rec-terminate(<term>)", &t0)) {
    rec_terminate(conn, t0);
    return NULL;
  }
  if(ATmatch(term, "rec-do(signature(<term>,<term>))", &in, &out)) {
    ATerm result = se_checker(conn, in);
    if(!ATmatch(result, "[]"))
      ATfprintf(stderr, "warning: not in input signature:\n\t%\n\tl\n", result);
    return NULL;
  }

  ATerror("tool se cannot handle term %t", term);
  return NULL; /* Silence the compiler */
}

/* Check the signature of the tool 'se' */
ATerm se_checker(int conn, ATerm siglist)
{
  return ATBcheckSignature(siglist, signature, NR_SIG_ENTRIES);
}

