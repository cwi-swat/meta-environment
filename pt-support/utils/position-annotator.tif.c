/**
 * This file is generated by tifstoc. Do not edit!
 * Generated from tifs for tool 'position-annotator' (prefix='')
 */

#include "position-annotator.tif.h"

#define NR_SIG_ENTRIES	6

static char *signature[NR_SIG_ENTRIES] = {
  "rec-eval(<position-annotator>,add-posinfo(<str>,<term>))",
  "rec-eval(<position-annotator>,add-posinfo-packed(<str>,<term>))",
  "rec-eval(<position-annotator>,add-posinfo-to-depth(<str>,<term>,<int>))",
  "rec-eval(<position-annotator>,promote-posinfo-to-origin(<term>))",
  "rec-eval(<position-annotator>,get-origin(<term>))",
  "rec-terminate(<position-annotator>,<term>)",
};

/* Event handler for tool 'position-annotator' */
ATerm position_annotator_handler(int conn, ATerm term)
{
  ATerm in, out;
  /* We need some temporary variables during matching */
  int i0;
  char *s0;
  ATerm t0;

  if(ATmatch(term, "rec-eval(add-posinfo-to-depth(<str>,<term>,<int>))", &s0, &t0, &i0)) {
    return add_posinfo_to_depth(conn, s0, t0, i0);
  }
  if(ATmatch(term, "rec-eval(add-posinfo-packed(<str>,<term>))", &s0, &t0)) {
    return add_posinfo_packed(conn, s0, t0);
  }
  if(ATmatch(term, "rec-eval(promote-posinfo-to-origin(<term>))", &t0)) {
    return promote_posinfo_to_origin(conn, t0);
  }
  if(ATmatch(term, "rec-eval(add-posinfo(<str>,<term>))", &s0, &t0)) {
    return add_posinfo(conn, s0, t0);
  }
  if(ATmatch(term, "rec-eval(get-origin(<term>))", &t0)) {
    return get_origin(conn, t0);
  }
  if(ATmatch(term, "rec-terminate(<term>)", &t0)) {
    rec_terminate(conn, t0);
    return NULL;
  }
  if(ATmatch(term, "rec-do(signature(<term>,<term>))", &in, &out)) {
    ATerm result = position_annotator_checker(conn, in);
    if(!ATmatch(result, "[]"))
      ATfprintf(stderr, "warning: not in input signature:\n\t%\n\tl\n", result);
    return NULL;
  }

  ATerror("tool position-annotator cannot handle term %t", term);
  return NULL; /* Silence the compiler */
}

/* Check the signature of the tool 'position-annotator' */
ATerm position_annotator_checker(int conn, ATerm siglist)
{
  return ATBcheckSignature(siglist, signature, NR_SIG_ENTRIES);
}

