/**
 * This file is generated by /ufs/markvdb/Research/bin/tifstoc. Do not edit!
 * Generated from tifs for tool 'editor-hive' (prefix='')
 * Headerfile generated at Wed Jan 28 11:44:55 2004
 */

#ifndef _EDITOR_HIVE_H
#define _EDITOR_HIVE_H

#include <atb-tool.h>

/* Prototypes for functions called from the event handler */
void clear_focus(int conn, ATerm);
void get_contents(int conn, ATerm, ATerm);
void display_message(int conn, ATerm, char *);
void write_contents(int conn, ATerm);
void set_cursor_at_focus(int conn, ATerm, ATerm);
void set_focus(int conn, ATerm, ATerm);
void set_cursor_at_location(int conn, ATerm, ATerm);
void reread_contents(int conn, ATerm);
void set_focus_at_location(int conn, ATerm, ATerm);
void set_actions(int conn, ATerm, ATerm);
void editor_to_front(int conn, ATerm);
void edit_file(int conn, ATerm, char *, char *);
void kill_editor(int conn, ATerm);
void rec_ack_event(int conn, ATerm);
void rec_terminate(int conn, ATerm);
extern ATerm editor_hive_handler(int conn, ATerm term);
extern ATerm editor_hive_checker(int conn, ATerm sigs);

#endif
