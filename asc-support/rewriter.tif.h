/**
 * This file is generated by /ufs/js/petr/bin/tifstoc. Do not edit!
 * Generated from tifs for tool 'rewriter'
 * Headerfile generated at Thu Jul 22 15:35:22 1999
 */

#ifndef _REWRITER_H
#define _REWRITER_H

#include <atb-tool.h>

/* Prototypes for functions called from the event handler */
ATerm reduce(int conn, ATerm);
ATerm reduce_and_asource(int conn, ATerm, char *, char *);
void rec_terminate(int conn, ATerm);
ATerm get_name(int conn);
extern ATerm rewriter_handler(int conn, ATerm term);
extern ATerm rewriter_checker(int conn, ATerm sigs);

#endif
