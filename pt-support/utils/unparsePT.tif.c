/**
 * This file is generated by tifstoc. Do not edit!
 * Generated from tifs for tool 'unparsePT' (prefix='')
 * Implementation generated at Tue May 27 17:35:32 2003
 */

#include "unparsePT.tif.h"

#define NR_SIG_ENTRIES	2

static char *signature[NR_SIG_ENTRIES] = {
  "rec-eval(<unparsePT>,unparse-asfix(<term>))",
  "rec-terminate(<unparsePT>,<term>)",
};

/* Event handler for tool 'unparsePT' */
ATerm unparsePT_handler(int conn, ATerm term)
{
  ATerm in, out;
  /* We need some temporary variables during matching */
  ATerm t0;

  if(ATmatch(term, "rec-eval(unparse-asfix(<term>))", &t0)) {
    return unparse_asfix(conn, t0);
  }
  if(ATmatch(term, "rec-terminate(<term>)", &t0)) {
    rec_terminate(conn, t0);
    return NULL;
  }
  if(ATmatch(term, "rec-do(signature(<term>,<term>))", &in, &out)) {
    ATerm result = unparsePT_checker(conn, in);
    if(!ATmatch(result, "[]"))
      ATfprintf(stderr, "warning: not in input signature:\n\t%\n\tl\n", result);
    return NULL;
  }

  ATerror("tool unparsePT cannot handle term %t", term);
  return NULL; /* Silence the compiler */
}

/* Check the signature of the tool 'unparsePT' */
ATerm unparsePT_checker(int conn, ATerm siglist)
{
  return ATBcheckSignature(siglist, signature, NR_SIG_ENTRIES);
}

