#line 5 "dap.c.nw"
#ifndef __DAP_H__
#define __DAP_H__

#include <TB.h>
#include "dap-admin.h"

#line 34 "dap.c.nw"
typedef struct
{
  char *name;
  int arity;
  TBbool (* eval)(term_list *args, int pid, term **result, char **msg);
  TBbool (* typecheck)(term_list *args, int pid, term **result, char **msg);
  char *doc;
} func_entry;
#line 48 "dap.c.nw"
typedef func_entry *function_table;
#line 65 "dap.c.nw"
typedef struct
{
  char *name;
  int arity;
  TBbool (* execute)(term_list *args, int pid, term **result, char **msg);
  TBbool (* typecheck)(term_list *args, int pid, term **result, char **msg);
  char *doc;
} act_entry;
#line 79 "dap.c.nw"
typedef act_entry *action_table;
#line 93 "dap.c.nw"
extern char *information_table[];
#line 102 "dap.c.nw"
void   dap_init(int cid, char **itable, function_table ftable, action_table atable);
term  *dap_get_info(int cid);
void   dap_rec_ack_event(int cid, term *event);
void   dap_rec_terminate(int cid, term *arg);
void   dap_change_cpe(int cid, term *pids, term *cpe);
int    dap_create_rule(term *procs, term *port, term *cond, term *acts, term *life);
void   dap_destroy_rule(int rid);
void   dap_activate_rules(int pid, term *port);
TBbool dap_evaluate(term *t, int pid, term **result, char **msg); 
TBbool dap_execute(term *t, int pid, term **result, char **msg);

TBbool dap_change_exec_state(int pid, int new_state);

/*TBbool dap_typecheck_expr(term *t, int pid, term **result, char **msg);
TBbool dap_typecheck_action(term *t, int pid, term **result, char **msg);
*/
#line 126 "dap.c.nw"
term *cbdap_supply_info(char *key);
void cbdap_change_exec_state(int pid, int exec_state);
#line 18 "dap.c.nw"
#endif
