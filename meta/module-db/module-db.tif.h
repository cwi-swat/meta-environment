/**
 * This file is generated by /ufs/olivierp/Research/software/installed/bin/tifstoc. Do not edit!
 * Generated from tifs for tool 'module-db' (prefix='')
 * Headerfile generated at Wed Jan 15 13:49:47 2003
 */

#ifndef _MODULE_DB_H
#define _MODULE_DB_H

#include <atb-tool.h>

/* Prototypes for functions called from the event handler */
void add_text_eqs_section(int conn, char *, char *, char *, int);
void add_empty_eqs_section(int conn, char *, char *);
ATerm update_eqs_tree(int conn, char *, ATerm);
void add_tree_eqs_section(int conn, char *, char *, ATerm, char *, int);
ATerm update_eqs_text(int conn, char *, char *);
ATerm get_eqs_text(int conn, char *);
ATerm add_parse_table(int conn, ATerm, ATerm, int);
ATerm eqs_not_available_for_modules(int conn, char *);
ATerm get_path(int conn, char *, ATerm);
ATerm copy_module(int conn, char *, char *, char *);
ATerm get_parse_table(int conn, ATerm);
ATerm remove_import(int conn, char *, char *, char *);
ATerm get_all_depending_modules(int conn, char *);
ATerm add_import(int conn, char *, char *, char *);
ATerm get_all_imported_modules(int conn, char *);
ATerm rename_module(int conn, char *, char *, char *);
ATerm get_imported_modules(int conn, char *);
ATerm update_sdf2_module(int conn, char *, ATerm);
ATerm get_all_modules(int conn);
void invalidate_sdf(int conn, char *);
ATerm all_equations_available(int conn, char *);
ATerm add_sdf_module(int conn, char *, char *, ATerm, int);
ATerm get_all_sdf2_definitions(int conn, char *);
ATerm add_empty_module(int conn, char *);
ATerm get_sdf_tree(int conn, char *);
ATerm exists(int conn, char *);
ATerm get_asf_tree(int conn, char *);
ATerm delete_module(int conn, char *);
ATerm get_equations_for_module(int conn, ATerm);
void clear_module_db(int conn);
ATerm get_equations_for_renamed_import(int conn, ATerm, ATerm);
void set_file_extensions(int conn, char *, char *, char *);
void invalidate_parse_tables(int conn, char *);
void create_module_db(int conn);
ATerm get_module_info(int conn, char *);
void rec_terminate(int conn, ATerm);
extern ATerm module_db_handler(int conn, ATerm term);
extern ATerm module_db_checker(int conn, ATerm sigs);

#endif
