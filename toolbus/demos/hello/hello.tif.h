/**
 * This file is generated by /ufs/paulk/bin/tifstoc. Do not edit!
 * Generated from tifs for tool 'hello' (prefix='')
 * Headerfile generated at Fri Jun  1 11:17:09 2001
 */

#ifndef _HELLO_H
#define _HELLO_H

#include <atb-tool.h>

/* Prototypes for functions called from the event handler */
ATerm get_text(int conn);
void rec_terminate(int conn, ATerm);
extern ATerm hello_handler(int conn, ATerm term);
extern ATerm hello_checker(int conn, ATerm sigs);

#endif
