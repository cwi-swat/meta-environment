/**
 * This file is generated by tifstoc. Do not edit!
 * Generated from tifs for tool 'apply-function' (prefix='')
 * Headerfile generated at Tue May 27 17:35:32 2003
 */

#ifndef _APPLY_FUNCTION_H
#define _APPLY_FUNCTION_H

#include <atb-tool.h>

/* Prototypes for functions called from the event handler */
ATerm get_argument_given_nr(int conn, ATerm, int);
ATerm apply_function_to_args(int conn, char *, char *, ATerm);
ATerm equal_trees(int conn, ATerm, ATerm);
void rec_terminate(int conn, ATerm);
extern ATerm apply_function_handler(int conn, ATerm term);
extern ATerm apply_function_checker(int conn, ATerm sigs);

#endif
