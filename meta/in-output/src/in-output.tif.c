/**
 * This file is generated by /home/markvdb/Research/bin/tifstoc. Do not edit!
 * Generated from tifs for tool 'in-output' (prefix='')
 * Implementation generated at Wed Jul  9 12:38:54 2003
 */

#include "in-output.tif.h"

#define NR_SIG_ENTRIES	15

static char *signature[NR_SIG_ENTRIES] = {
  "rec-eval(<in-output>,relative-to-absolute(<list>))",
  "rec-eval(<in-output>,find-file(<list>,<str>,<str>))",
  "rec-do(<in-output>,remove-file(<str>,<str>,<str>))",
  "rec-eval(<in-output>,exists-file(<str>))",
  "rec-eval(<in-output>,write-text-file(<str>,<list>))",
  "rec-eval(<in-output>,pack-term(<term>))",
  "rec-eval(<in-output>,unpack-term(<term>))",
  "rec-eval(<in-output>,write-term-file(<str>,<term>))",
  "rec-eval(<in-output>,write-packed-term-file(<str>,<term>))",
  "rec-eval(<in-output>,read-text-file(<str>))",
  "rec-eval(<in-output>,read-term-file(<str>))",
  "rec-eval(<in-output>,read-packed-term-file(<str>))",
  "rec-eval(<in-output>,compare-files(<str>,<str>))",
  "rec-eval(<in-output>,get-filename(<str>,<str>,<str>))",
  "rec-terminate(<in-output>,<term>)",
};

/* Event handler for tool 'in-output' */
ATerm in_output_handler(int conn, ATerm term)
{
  ATerm in, out;
  /* We need some temporary variables during matching */
  char *s0, *s1, *s2;
  ATerm t0;

  if(ATmatch(term, "rec-eval(unpack-term(<term>))", &t0)) {
    return unpack_term(conn, t0);
  }
  if(ATmatch(term, "rec-eval(write-term-file(<str>,<term>))", &s0, &t0)) {
    return write_term_file(conn, s0, t0);
  }
  if(ATmatch(term, "rec-eval(pack-term(<term>))", &t0)) {
    return pack_term(conn, t0);
  }
  if(ATmatch(term, "rec-eval(write-packed-term-file(<str>,<term>))", &s0, &t0)) {
    return write_packed_term_file(conn, s0, t0);
  }
  if(ATmatch(term, "rec-eval(write-text-file(<str>,<term>))", &s0, &t0)) {
    return write_text_file(conn, s0, t0);
  }
  if(ATmatch(term, "rec-eval(read-text-file(<str>))", &s0)) {
    return read_text_file(conn, s0);
  }
  if(ATmatch(term, "rec-eval(exists-file(<str>))", &s0)) {
    return exists_file(conn, s0);
  }
  if(ATmatch(term, "rec-eval(read-term-file(<str>))", &s0)) {
    return read_term_file(conn, s0);
  }
  if(ATmatch(term, "rec-do(remove-file(<str>,<str>,<str>))", &s0, &s1, &s2)) {
    remove_file(conn, s0, s1, s2);
    return NULL;
  }
  if(ATmatch(term, "rec-eval(read-packed-term-file(<str>))", &s0)) {
    return read_packed_term_file(conn, s0);
  }
  if(ATmatch(term, "rec-eval(find-file(<term>,<str>,<str>))", &t0, &s0, &s1)) {
    return find_file(conn, t0, s0, s1);
  }
  if(ATmatch(term, "rec-eval(compare-files(<str>,<str>))", &s0, &s1)) {
    return compare_files(conn, s0, s1);
  }
  if(ATmatch(term, "rec-eval(relative-to-absolute(<term>))", &t0)) {
    return relative_to_absolute(conn, t0);
  }
  if(ATmatch(term, "rec-eval(get-filename(<str>,<str>,<str>))", &s0, &s1, &s2)) {
    return get_filename(conn, s0, s1, s2);
  }
  if(ATmatch(term, "rec-terminate(<term>)", &t0)) {
    rec_terminate(conn, t0);
    return NULL;
  }
  if(ATmatch(term, "rec-do(signature(<term>,<term>))", &in, &out)) {
    ATerm result = in_output_checker(conn, in);
    if(!ATmatch(result, "[]"))
      ATfprintf(stderr, "warning: not in input signature:\n\t%\n\tl\n", result);
    return NULL;
  }

  ATerror("tool in-output cannot handle term %t", term);
  return NULL; /* Silence the compiler */
}

/* Check the signature of the tool 'in-output' */
ATerm in_output_checker(int conn, ATerm siglist)
{
  return ATBcheckSignature(siglist, signature, NR_SIG_ENTRIES);
}

