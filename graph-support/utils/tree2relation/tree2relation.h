/**
 * This file is generated by tifstoc. Do not edit!
 * Generated from tifs for tool 'tree2relation' (prefix='')
 */

#ifndef _TREE2RELATION_H
#define _TREE2RELATION_H

#include <atb-tool.h>

/* Prototypes for functions called from the event handler */
void rec_terminate(int conn, ATerm);
ATerm tree2relation(int conn, ATerm, ATerm, ATerm, ATerm);
extern ATerm tree2relation_handler(int conn, ATerm term);
extern ATerm tree2relation_checker(int conn, ATerm sigs);

#endif
