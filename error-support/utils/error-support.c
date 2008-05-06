/**
 * This file is generated by tifstoc. Do not edit!
 * Generated from tifs for tool 'error-support' (prefix='')
 */

#include "error-support.h"

#define NR_SIG_ENTRIES	26

static char *signature[NR_SIG_ENTRIES] = {
  "rec-terminate(<error-support>,<term>)",
  "rec-eval(<error-support>,get-area-begin-column(<area>))",
  "rec-eval(<error-support>,make-summary(<str>,<str>,<list>))",
  "rec-eval(<error-support>,get-location-filename(<term>))",
  "rec-eval(<error-support>,get-area-begin-line(<area>))",
  "rec-eval(<error-support>,get-subject-description(<term>))",
  "rec-eval(<error-support>,make-error(<str>,<list>))",
  "rec-eval(<error-support>,has-subject-location(<term>))",
  "rec-eval(<error-support>,make-localized-subject(<str>,<term>))",
  "rec-eval(<error-support>,get-summary-errors(<summary>))",
  "rec-eval(<error-support>,get-summary-producer(<summary>))",
  "rec-eval(<error-support>,get-area-length(<area>))",
  "rec-eval(<error-support>,get-error-description(<term>))",
  "rec-do(<error-support>,display-summary(<summary>))",
  "rec-eval(<error-support>,get-summary-id(<summary>))",
  "rec-eval(<error-support>,make-subject(<str>))",
  "rec-eval(<error-support>,set-summary-id(<summary>,<str>))",
  "rec-eval(<error-support>,has-location-area(<term>))",
  "rec-eval(<error-support>,get-area-end-line(<area>))",
  "rec-eval(<error-support>,get-area-end-column(<area>))",
  "rec-eval(<error-support>,add-filename-in-error(<str>,<term>))",
  "rec-eval(<error-support>,lower-summary(<term>))",
  "rec-eval(<error-support>,get-area-offset(<area>))",
  "rec-eval(<error-support>,get-location-area(<term>))",
  "rec-eval(<error-support>,get-error-subjects(<term>))",
  "rec-eval(<error-support>,get-subject-location(<term>))",
};

/* Event handler for tool 'error-support' */
ATerm error_support_handler(int conn, ATerm term)
{
  ATerm in, out;
  /* We need some temporary variables during matching */
  char *s0, *s1;
  ATerm t0;

  if(ATmatch(term, "rec-do(display-summary(<term>))", &t0)) {
    display_summary(conn, t0);
    return NULL;
  }
  if(ATmatch(term, "rec-eval(get-error-description(<term>))", &t0)) {
    return get_error_description(conn, t0);
  }
  if(ATmatch(term, "rec-eval(get-summary-id(<term>))", &t0)) {
    return get_summary_id(conn, t0);
  }
  if(ATmatch(term, "rec-eval(get-area-length(<term>))", &t0)) {
    return get_area_length(conn, t0);
  }
  if(ATmatch(term, "rec-eval(make-subject(<str>))", &s0)) {
    return make_subject(conn, s0);
  }
  if(ATmatch(term, "rec-eval(get-summary-producer(<term>))", &t0)) {
    return get_summary_producer(conn, t0);
  }
  if(ATmatch(term, "rec-eval(set-summary-id(<term>,<str>))", &t0, &s0)) {
    return set_summary_id(conn, t0, s0);
  }
  if(ATmatch(term, "rec-eval(get-summary-errors(<term>))", &t0)) {
    return get_summary_errors(conn, t0);
  }
  if(ATmatch(term, "rec-eval(has-location-area(<term>))", &t0)) {
    return has_location_area(conn, t0);
  }
  if(ATmatch(term, "rec-eval(make-localized-subject(<str>,<term>))", &s0, &t0)) {
    return make_localized_subject(conn, s0, t0);
  }
  if(ATmatch(term, "rec-eval(get-area-end-line(<term>))", &t0)) {
    return get_area_end_line(conn, t0);
  }
  if(ATmatch(term, "rec-eval(has-subject-location(<term>))", &t0)) {
    return has_subject_location(conn, t0);
  }
  if(ATmatch(term, "rec-eval(get-area-end-column(<term>))", &t0)) {
    return get_area_end_column(conn, t0);
  }
  if(ATmatch(term, "rec-eval(make-error(<str>,<term>))", &s0, &t0)) {
    return make_error(conn, s0, t0);
  }
  if(ATmatch(term, "rec-eval(add-filename-in-error(<str>,<term>))", &s0, &t0)) {
    return add_filename_in_error(conn, s0, t0);
  }
  if(ATmatch(term, "rec-eval(get-subject-description(<term>))", &t0)) {
    return get_subject_description(conn, t0);
  }
  if(ATmatch(term, "rec-eval(lower-summary(<term>))", &t0)) {
    return lower_summary(conn, t0);
  }
  if(ATmatch(term, "rec-eval(get-area-begin-line(<term>))", &t0)) {
    return get_area_begin_line(conn, t0);
  }
  if(ATmatch(term, "rec-eval(get-area-offset(<term>))", &t0)) {
    return get_area_offset(conn, t0);
  }
  if(ATmatch(term, "rec-eval(get-location-filename(<term>))", &t0)) {
    return get_location_filename(conn, t0);
  }
  if(ATmatch(term, "rec-eval(get-location-area(<term>))", &t0)) {
    return get_location_area(conn, t0);
  }
  if(ATmatch(term, "rec-eval(make-summary(<str>,<str>,<term>))", &s0, &s1, &t0)) {
    return make_summary(conn, s0, s1, t0);
  }
  if(ATmatch(term, "rec-eval(get-error-subjects(<term>))", &t0)) {
    return get_error_subjects(conn, t0);
  }
  if(ATmatch(term, "rec-eval(get-area-begin-column(<term>))", &t0)) {
    return get_area_begin_column(conn, t0);
  }
  if(ATmatch(term, "rec-terminate(<term>)", &t0)) {
    rec_terminate(conn, t0);
    return NULL;
  }
  if(ATmatch(term, "rec-eval(get-subject-location(<term>))", &t0)) {
    return get_subject_location(conn, t0);
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

