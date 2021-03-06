/**
 * This file is generated by tifstoc. Do not edit!
 * Generated from tifs for tool 'tree2relation' (prefix='')
 */

#include "tree2relation.h"

#define NR_SIG_ENTRIES	2

static char *signature[NR_SIG_ENTRIES] = {
  "rec-terminate(<tree2relation>,<term>)",
  "rec-eval(<tree2relation>,tree2relation(<term>,<bool>,<bool>,<bool>))",
};

/* Event handler for tool 'tree2relation' */
ATerm tree2relation_handler(int conn, ATerm term)
{
  ATerm in, out;
  /* We need some temporary variables during matching */
  ATerm t0, t1, t2, t3;

  if(ATmatch(term, "rec-terminate(<term>)", &t0)) {
    rec_terminate(conn, t0);
    return NULL;
  }
  if(ATmatch(term, "rec-eval(tree2relation(<term>,<term>,<term>,<term>))", &t0, &t1, &t2, &t3)) {
    return tree2relation(conn, t0, t1, t2, t3);
  }
  if(ATmatch(term, "rec-do(signature(<term>,<term>))", &in, &out)) {
    ATerm result = tree2relation_checker(conn, in);
    if(!ATmatch(result, "[]"))
      ATfprintf(stderr, "warning: not in input signature:\n\t%\n\tl\n", result);
    return NULL;
  }

  ATerror("tool tree2relation cannot handle term %t", term);
  return NULL; /* Silence the compiler */
}

/* Check the signature of the tool 'tree2relation' */
ATerm tree2relation_checker(int conn, ATerm siglist)
{
  return ATBcheckSignature(siglist, signature, NR_SIG_ENTRIES);
}

