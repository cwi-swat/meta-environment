/**
 * This file is generated by tifstoc. Do not edit!
 * Generated from tifs for tool 'addeqssyntax' (prefix='')
 * Implementation generated at Wed Oct 16 11:25:23 2002
 */

#include "addeqssyntax.tif.h"

#define NR_SIG_ENTRIES	2

static char *signature[NR_SIG_ENTRIES] = {
  "rec-eval(<addeqssyntax>,add-eqs-syntax(<str>,<term>))",
  "rec-terminate(<addeqssyntax>,<term>)",
};

/* Event handler for tool 'addeqssyntax' */
ATerm addeqssyntax_handler(int conn, ATerm term)
{
  ATerm in, out;
  /* We need some temporary variables during matching */
  char *s0;
  ATerm t0;

  if(ATmatch(term, "rec-eval(add-eqs-syntax(<str>,<term>))", &s0, &t0)) {
    return add_eqs_syntax(conn, s0, t0);
  }
  if(ATmatch(term, "rec-terminate(<term>)", &t0)) {
    rec_terminate(conn, t0);
    return NULL;
  }
  if(ATmatch(term, "rec-do(signature(<term>,<term>))", &in, &out)) {
    ATerm result = addeqssyntax_checker(conn, in);
    if(!ATmatch(result, "[]"))
      ATfprintf(stderr, "warning: not in input signature:\n\t%\n\tl\n", result);
    return NULL;
  }

  ATerror("tool addeqssyntax cannot handle term %t", term);
  return NULL; /* Silence the compiler */
}

/* Check the signature of the tool 'addeqssyntax' */
ATerm addeqssyntax_checker(int conn, ATerm siglist)
{
  return ATBcheckSignature(siglist, signature, NR_SIG_ENTRIES);
}

