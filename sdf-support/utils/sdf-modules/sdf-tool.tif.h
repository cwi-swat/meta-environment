/**
 * This file is generated by tifstoc. Do not edit!
 * Generated from tifs for tool 'sdf-tool' (prefix='')
 * Headerfile generated at Thu May 15 18:20:24 2003
 */

#ifndef _SDF_TOOL_H
#define _SDF_TOOL_H

#include <atb-tool.h>

/* Prototypes for functions called from the event handler */
void rec_terminate(int conn, ATerm);
extern ATerm sdf_tool_handler(int conn, ATerm term);
extern ATerm sdf_tool_checker(int conn, ATerm sigs);

#endif
