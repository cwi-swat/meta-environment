/**
 * This file is generated by tifstoc. Do not edit!
 * Generated from tifs for tool 'addimports' (prefix='')
 * Headerfile generated at Tue Jan  7 14:40:14 2003
 */

#ifndef _ADDIMPORTS_H
#define _ADDIMPORTS_H

#include <atb-tool.h>

/* Prototypes for functions called from the event handler */
ATerm add_imports(int conn, char *, ATerm);
void rec_terminate(int conn, ATerm);
extern ATerm addimports_handler(int conn, ATerm term);
extern ATerm addimports_checker(int conn, ATerm sigs);

#endif
