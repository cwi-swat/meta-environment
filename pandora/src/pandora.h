/**
 * This file is generated by tifstoc. Do not edit!
 * Generated from tifs for tool 'pandora' (prefix='')
 */

#ifndef _PANDORA_H
#define _PANDORA_H

#include <atb-tool.h>

/* Prototypes for functions called from the event handler */
ATerm pretty_print(int conn, ATerm);
void rec_terminate(int conn, ATerm);
extern ATerm pandora_handler(int conn, ATerm term);
extern ATerm pandora_checker(int conn, ATerm sigs);

#endif
