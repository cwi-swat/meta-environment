/**
 * This file is generated by tifstoc. Do not edit!
 * Generated from tifs for tool 'asfoperations' (prefix='')
 */

#include "asfoperations.h"

#define NR_SIG_ENTRIES	4

static char *signature[NR_SIG_ENTRIES] = {
  "rec-terminate(<asfoperations>,<term>)",
  "rec-eval(<asfoperations>,extract-equations(<term>))",
  "rec-eval(<asfoperations>,extract-tests(<term>))",
  "rec-eval(<asfoperations>,normalize-module(<term>))",
};

/* Event handler for tool 'asfoperations' */
ATerm asfoperations_handler(int conn, ATerm term)
{
  ATerm in, out;
  /* We need some temporary variables during matching */
  ATerm t0;

  if(ATmatch(term, "rec-eval(extract-tests(<term>))", &t0)) {
    return extract_tests(conn, t0);
  }
  if(ATmatch(term, "rec-eval(extract-equations(<term>))", &t0)) {
    return extract_equations(conn, t0);
  }
  if(ATmatch(term, "rec-terminate(<term>)", &t0)) {
    rec_terminate(conn, t0);
    return NULL;
  }
  if(ATmatch(term, "rec-eval(normalize-module(<term>))", &t0)) {
    return normalize_module(conn, t0);
  }
  if(ATmatch(term, "rec-do(signature(<term>,<term>))", &in, &out)) {
    ATerm result = asfoperations_checker(conn, in);
    if(!ATmatch(result, "[]"))
      ATfprintf(stderr, "warning: not in input signature:\n\t%\n\tl\n", result);
    return NULL;
  }

  ATerror("tool asfoperations cannot handle term %t", term);
  return NULL; /* Silence the compiler */
}

/* Check the signature of the tool 'asfoperations' */
ATerm asfoperations_checker(int conn, ATerm siglist)
{
  return ATBcheckSignature(siglist, signature, NR_SIG_ENTRIES);
}

