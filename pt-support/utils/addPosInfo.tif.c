/**
 * This file is generated by tifstoc. Do not edit!
 * Generated from tifs for tool 'addPosInfo' (prefix='')
 * Implementation generated at Tue May 27 17:35:32 2003
 */

#include "addPosInfo.tif.h"

#define NR_SIG_ENTRIES	4

static char *signature[NR_SIG_ENTRIES] = {
  "rec-eval(<addPosInfo>,add-posinfo(<str>,<term>))",
  "rec-eval(<addPosInfo>,add-posinfo-packed(<str>,<term>))",
  "rec-eval(<addPosInfo>,add-posinfo-to-depth(<str>,<term>,<int>))",
  "rec-terminate(<addPosInfo>,<term>)",
};

/* Event handler for tool 'addPosInfo' */
ATerm addPosInfo_handler(int conn, ATerm term)
{
  ATerm in, out;
  /* We need some temporary variables during matching */
  int i0;
  char *s0;
  ATerm t0;

  if(ATmatch(term, "rec-eval(add-posinfo-packed(<str>,<term>))", &s0, &t0)) {
    return add_posinfo_packed(conn, s0, t0);
  }
  if(ATmatch(term, "rec-eval(add-posinfo(<str>,<term>))", &s0, &t0)) {
    return add_posinfo(conn, s0, t0);
  }
  if(ATmatch(term, "rec-eval(add-posinfo-to-depth(<str>,<term>,<int>))", &s0, &t0, &i0)) {
    return add_posinfo_to_depth(conn, s0, t0, i0);
  }
  if(ATmatch(term, "rec-terminate(<term>)", &t0)) {
    rec_terminate(conn, t0);
    return NULL;
  }
  if(ATmatch(term, "rec-do(signature(<term>,<term>))", &in, &out)) {
    ATerm result = addPosInfo_checker(conn, in);
    if(!ATmatch(result, "[]"))
      ATfprintf(stderr, "warning: not in input signature:\n\t%\n\tl\n", result);
    return NULL;
  }

  ATerror("tool addPosInfo cannot handle term %t", term);
  return NULL; /* Silence the compiler */
}

/* Check the signature of the tool 'addPosInfo' */
ATerm addPosInfo_checker(int conn, ATerm siglist)
{
  return ATBcheckSignature(siglist, signature, NR_SIG_ENTRIES);
}

