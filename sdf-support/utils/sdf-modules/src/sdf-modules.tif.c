/**
 * This file is generated by tifstoc. Do not edit!
 * Generated from tifs for tool 'sdf-modules' (prefix='')
 * Implementation generated at Mon May 19 14:43:36 2003
 */

#include "sdf-modules.tif.h"

#define NR_SIG_ENTRIES	5

static char *signature[NR_SIG_ENTRIES] = {
  "rec-eval(<sdf-modules>,get-module-id(<term>))",
  "rec-eval(<sdf-modules>,get-all-imports(<list>,<str>))",
  "rec-eval(<sdf-modules>,get-all-depending-modules(<list>,<str>))",
  "rec-eval(<sdf-modules>,get-import-renamings(<term>))",
  "rec-terminate(<sdf-modules>,<term>)",
};

/* Event handler for tool 'sdf-modules' */
ATerm sdf_modules_handler(int conn, ATerm term)
{
  ATerm in, out;
  /* We need some temporary variables during matching */
  char *s0;
  ATerm t0;

  if(ATmatch(term, "rec-eval(get-all-imports(<term>,<str>))", &t0, &s0)) {
    return get_all_imports(conn, t0, s0);
  }
  if(ATmatch(term, "rec-eval(get-all-depending-modules(<term>,<str>))", &t0, &s0)) {
    return get_all_depending_modules(conn, t0, s0);
  }
  if(ATmatch(term, "rec-eval(get-module-id(<term>))", &t0)) {
    return get_module_id(conn, t0);
  }
  if(ATmatch(term, "rec-eval(get-import-renamings(<term>))", &t0)) {
    return get_import_renamings(conn, t0);
  }
  if(ATmatch(term, "rec-terminate(<term>)", &t0)) {
    rec_terminate(conn, t0);
    return NULL;
  }
  if(ATmatch(term, "rec-do(signature(<term>,<term>))", &in, &out)) {
    ATerm result = sdf_modules_checker(conn, in);
    if(!ATmatch(result, "[]"))
      ATfprintf(stderr, "warning: not in input signature:\n\t%\n\tl\n", result);
    return NULL;
  }

  ATerror("tool sdf-modules cannot handle term %t", term);
  return NULL; /* Silence the compiler */
}

/* Check the signature of the tool 'sdf-modules' */
ATerm sdf_modules_checker(int conn, ATerm siglist)
{
  return ATBcheckSignature(siglist, signature, NR_SIG_ENTRIES);
}

