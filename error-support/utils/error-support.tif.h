/**
 * This file is generated by tifstoc. Do not edit!
 * Generated from tifs for tool 'error-support' (prefix='')
 */

#ifndef _ERROR_SUPPORT_H
#define _ERROR_SUPPORT_H

#include <atb-tool.h>

/* Prototypes for functions called from the event handler */
ATerm get_subject_description(int conn, ATerm);
ATerm has_subject_location(int conn, ATerm);
ATerm get_location_area(int conn, ATerm);
ATerm get_subject_location(int conn, ATerm);
ATerm has_location_area(int conn, ATerm);
ATerm get_error_description(int conn, ATerm);
ATerm get_location_filename(int conn, ATerm);
ATerm get_error_subjects(int conn, ATerm);
ATerm get_area_length(int conn, ATerm);
ATerm get_summary_producer(int conn, ATerm);
ATerm get_area_offset(int conn, ATerm);
ATerm get_summary_id(int conn, ATerm);
ATerm get_area_end_column(int conn, ATerm);
ATerm get_summary_errors(int conn, ATerm);
ATerm get_area_end_line(int conn, ATerm);
ATerm lower_summary(int conn, ATerm);
ATerm get_area_begin_column(int conn, ATerm);
void display_summary(int conn, ATerm);
ATerm get_area_begin_line(int conn, ATerm);
ATerm add_filename_in_error(int conn, const char *, ATerm);
void rec_terminate(int conn, ATerm);
extern ATerm error_support_handler(int conn, ATerm term);
extern ATerm error_support_checker(int conn, ATerm sigs);

#endif
