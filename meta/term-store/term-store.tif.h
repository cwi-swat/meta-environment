/**
 * This file is generated by tifstoc. Do not edit!
 * Generated from tifs for tool 'term-store' (prefix='')
 */

#ifndef _TERM_STORE_H
#define _TERM_STORE_H

#include <atb-tool.h>

/* Prototypes for functions called from the event handler */
ATerm contains_key(int conn, const char *, ATerm);
void remove_value(int conn, const char *, ATerm);
ATerm get_all_keys(int conn, const char *);
ATerm get_term_value(int conn, const char *, ATerm);
ATerm get_key_value_pairs(int conn, const char *);
ATerm get_str_value(int conn, const char *, ATerm);
ATerm filter_keys(int conn, const char *, ATerm);
void put_str_value(int conn, const char *, ATerm, const char *);
ATerm get_all_values(int conn, const char *);
void put_term_value(int conn, const char *, ATerm, ATerm);
ATerm get_values(int conn, const char *, ATerm);
void clear_table(int conn, const char *);
void remove_value_from_all_tables(int conn, ATerm);
void remove_table(int conn, const char *);
ATerm get_snapshot(int conn);
void add_table(int conn, const char *, const char *);
ATerm load_snapshot(int conn, ATerm);
void rec_terminate(int conn, ATerm);
extern ATerm term_store_handler(int conn, ATerm term);
extern ATerm term_store_checker(int conn, ATerm sigs);

#endif
