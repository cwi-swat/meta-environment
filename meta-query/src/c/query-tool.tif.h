/**
 * This file is generated by /ufs/markvdb/Research/bin/tifstoc. Do not edit!
 * Generated from tifs for tool 'query-tool' (prefix='')
 * Headerfile generated at Fri May 23 09:42:58 2003
 */

#ifndef _QUERY_TOOL_H
#define _QUERY_TOOL_H

#include <atb-tool.h>

/* Prototypes for functions called from the event handler */
ATerm query(int conn, char *, ATerm, ATerm);
void rec_terminate(int conn, ATerm);
extern ATerm query_tool_handler(int conn, ATerm term);
extern ATerm query_tool_checker(int conn, ATerm sigs);

#endif
