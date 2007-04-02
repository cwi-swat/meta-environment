/**
 * This file is generated by tifstoc. Do not edit!
 * Generated from tifs for tool 'batch' (prefix='')
 */

#include "batch.tif.h"

#define NR_SIG_ENTRIES	3

static char *signature[NR_SIG_ENTRIES] = {
  "rec-eval(<batch>,fromFile)",
  "rec-do(<batch>,toFile(<str>,<int>))",
  "rec-terminate(<batch>,<term>)",
};

/* Event handler for tool 'batch' */
ATerm batch_handler(int conn, ATerm term)
{
  ATerm in, out;
  /* We need some temporary variables during matching */
  int i0;
  char *s0;
  ATerm t0;

  if(ATmatch(term, "rec-eval(fromFile)")) {
    return fromFile(conn);
  }
  if(ATmatch(term, "rec-do(toFile(<str>,<int>))", &s0, &i0)) {
    toFile(conn, s0, i0);
    return NULL;
  }
  if(ATmatch(term, "rec-terminate(<term>)", &t0)) {
    rec_terminate(conn, t0);
    return NULL;
  }
  if(ATmatch(term, "rec-do(signature(<term>,<term>))", &in, &out)) {
    ATerm result = batch_checker(conn, in);
    if(!ATmatch(result, "[]"))
      ATfprintf(stderr, "warning: not in input signature:\n\t%\n\tl\n", result);
    return NULL;
  }

  ATerror("tool batch cannot handle term %t", term);
  return NULL; /* Silence the compiler */
}

/* Check the signature of the tool 'batch' */
ATerm batch_checker(int conn, ATerm siglist)
{
  return ATBcheckSignature(siglist, signature, NR_SIG_ENTRIES);
}

