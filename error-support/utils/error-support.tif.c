/**
 * This file is generated by tifstoc. Do not edit!
 * Generated from tifs for tool 'error-support' (prefix='')
 */

#include "error-support.tif.h"

#define NR_SIG_ENTRIES	18

static char *signature[NR_SIG_ENTRIES] = {
  "rec-eval(<error-support>,get-area-begin-line(<term>))",
  "rec-eval(<error-support>,get-area-begin-column(<term>))",
  "rec-eval(<error-support>,get-area-end-line(<term>))",
  "rec-eval(<error-support>,get-area-end-column(<term>))",
  "rec-eval(<error-support>,get-area-offset(<term>))",
  "rec-eval(<error-support>,get-area-length(<term>))",
  "rec-eval(<error-support>,get-location-filename(<term>))",
  "rec-eval(<error-support>,has-location-area(<term>))",
  "rec-eval(<error-support>,get-location-area(<term>))",
  "rec-eval(<error-support>,get-subject-description(<term>))",
  "rec-eval(<error-support>,has-subject-location(<term>))",
  "rec-eval(<error-support>,get-subject-location(<term>))",
  "rec-eval(<error-support>,get-summary-producer(<term>))",
  "rec-eval(<error-support>,get-summary-id(<term>))",
  "rec-eval(<error-support>,get-summary-errors(<term>))",
  "rec-eval(<error-support>,lower-summary(<term>))",
  "rec-do(<error-support>,display-summary(<term>))",
  "rec-terminate(<error-support>,<term>)",
};

/* Event handler for tool 'error-support' */
ATerm error_support_handler(int conn, ATerm term)
{
  ATerm in, out;
  /* We need some temporary variables during matching */
  ATerm t0;

  if(ATmatch(term, "rec-eval(get-location-area(<term>))", &t0)) {
    return get_location_area(conn, t0);
  }
  if(ATmatch(term, "rec-eval(has-location-area(<term>))", &t0)) {
    return has_location_area(conn, t0);
  }
  if(ATmatch(term, "rec-eval(get-subject-description(<term>))", &t0)) {
    return get_subject_description(conn, t0);
  }
  if(ATmatch(term, "rec-eval(get-location-filename(<term>))", &t0)) {
    return get_location_filename(conn, t0);
  }
  if(ATmatch(term, "rec-eval(has-subject-location(<term>))", &t0)) {
    return has_subject_location(conn, t0);
  }
  if(ATmatch(term, "rec-eval(get-area-length(<term>))", &t0)) {
    return get_area_length(conn, t0);
  }
  if(ATmatch(term, "rec-eval(get-subject-location(<term>))", &t0)) {
    return get_subject_location(conn, t0);
  }
  if(ATmatch(term, "rec-eval(get-area-offset(<term>))", &t0)) {
    return get_area_offset(conn, t0);
  }
  if(ATmatch(term, "rec-eval(get-summary-producer(<term>))", &t0)) {
    return get_summary_producer(conn, t0);
  }
  if(ATmatch(term, "rec-eval(get-area-end-column(<term>))", &t0)) {
    return get_area_end_column(conn, t0);
  }
  if(ATmatch(term, "rec-eval(get-summary-id(<term>))", &t0)) {
    return get_summary_id(conn, t0);
  }
  if(ATmatch(term, "rec-eval(get-area-end-line(<term>))", &t0)) {
    return get_area_end_line(conn, t0);
  }
  if(ATmatch(term, "rec-eval(get-summary-errors(<term>))", &t0)) {
    return get_summary_errors(conn, t0);
  }
  if(ATmatch(term, "rec-eval(get-area-begin-column(<term>))", &t0)) {
    return get_area_begin_column(conn, t0);
  }
  if(ATmatch(term, "rec-eval(lower-summary(<term>))", &t0)) {
    return lower_summary(conn, t0);
  }
  if(ATmatch(term, "rec-eval(get-area-begin-line(<term>))", &t0)) {
    return get_area_begin_line(conn, t0);
  }
  if(ATmatch(term, "rec-do(display-summary(<term>))", &t0)) {
    display_summary(conn, t0);
    return NULL;
  }
  if(ATmatch(term, "rec-terminate(<term>)", &t0)) {
    rec_terminate(conn, t0);
    return NULL;
  }
  if(ATmatch(term, "rec-do(signature(<term>,<term>))", &in, &out)) {
    ATerm result = error_support_checker(conn, in);
    if(!ATmatch(result, "[]"))
      ATfprintf(stderr, "warning: not in input signature:\n\t%\n\tl\n", result);
    return NULL;
  }

  ATerror("tool error-support cannot handle term %t", term);
  return NULL; /* Silence the compiler */
}

/* Check the signature of the tool 'error-support' */
ATerm error_support_checker(int conn, ATerm siglist)
{
  return ATBcheckSignature(siglist, signature, NR_SIG_ENTRIES);
}

