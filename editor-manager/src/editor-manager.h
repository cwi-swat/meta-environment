/**
 * This file is generated by tifstoc. Do not edit!
 * Generated from tifs for tool 'editor-manager' (prefix='')
 */

#ifndef _EDITOR_MANAGER_H
#define _EDITOR_MANAGER_H

#include <atb-tool.h>

/* Prototypes for functions called from the event handler */
ATerm is_editor_registered(int conn, ATerm, ATerm);
void register_editor(int conn, ATerm, ATerm);
void unregister_editor(int conn, ATerm, ATerm);
ATerm get_moduleid(int conn, ATerm);
ATerm get_sessions_by_moduleid(int conn, ATerm);
ATerm bind_session(int conn, ATerm, ATerm);
ATerm get_session_by_path(int conn, const char *);
ATerm get_path(int conn, ATerm);
void delete_session(int conn, ATerm);
ATerm create_empty_session(int conn);
ATerm request_transaction(int conn, ATerm);
ATerm create_session(int conn, const char *);
void end_transaction(int conn, ATerm);
void rec_terminate(int conn, ATerm);
extern ATerm editor_manager_handler(int conn, ATerm term);
extern ATerm editor_manager_checker(int conn, ATerm sigs);

#endif
