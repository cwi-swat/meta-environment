#line 5 "dap-admin.c.nw"
#ifndef _DAP_ADMIN_H_
#define _DAP_ADMIN_H_

#include <TB.h>

#define MAX_DAPS	 128
#define MAX_EVENT_RULES 1024
#define MAX_PROCESSES	1024

#define PUF_START	1

#line 183 "dap-admin.c.nw"
#define ES_UNKNOWN		0
#define ES_STOP			0x0001
#define ES_RUN			0x0002
#define ES_SINGLE_STEP		0x0004
#define ES_STEP_OVER		0x0008
#define ES_RUN_UNTIL_PARENT	0x0010
#define ES_HIGH_WATER		0x0020

#define ES_ALL			0x003F
#line 155 "dap-admin.c.nw"
#define PORT_EXEC_STATE		0
#define PORT_ALWAYS		1
#define PORT_LOCATION		2
#define PORT_CALL		3
#define PORT_RETRY		4
#define PORT_FAIL		5
#define PORT_SUCCEED		6
#define PORT_EXCEPTION		7
#define PORT_VARIABLE		8
#define PORT_SEND		11
#define PORT_RECEIVE		12
#define PORT_PROCESS_CREATION	13
#define PORT_PROCESS_DESTRUCTION 14
#define NR_PORT_TYPES		15

#define WHEN_AT		0
#define WHEN_BEFORE	1
#define WHEN_AFTER	2

#define ONE_SHOT	0
#define PERSISTENT	1

#line 120 "dap-admin.c.nw"
typedef struct location
{
  char *module;
  int start_line;
  int start_col;
  int end_line;
  int end_col;
  int when;
} location;
#line 135 "dap-admin.c.nw"
typedef struct port
{
  int type;
  int when;
  union {
    struct location loc;
    char *function;
    char *exception;
    char *var;
    int   exec_state;
    term *msg;
  } u;
} port;
#line 103 "dap-admin.c.nw"
typedef struct event_rule
{ 
  struct event_rule *next;
  int id;
  term *pids;
  port port;
  term *cond;
  term_list *acts;
  int lifetime;
} event_rule;
#line 84 "dap-admin.c.nw"
typedef struct process
{
  int pid;			/* process id of this process */
  char *name;			/* name of this process */
  location cpe;			/* current point of execution */
  int exec_state;		/* execution state */
  int hw_exec_state;		/* execution state when high water reached */
  int stop_level;		/* stop level for ES_STEP_OVER and RUN_UNTIL_PARENT */
  int ruleid;			/* current event rule id */
  term_list *subterms;		/* subterms that matched with placeholders */
  unsigned uflags;		/* user flags */
  void *udata;			/* user data */
} process;
#line 70 "dap-admin.c.nw"
typedef struct dap
{
  int id;
  process    *procs[MAX_PROCESSES];
  event_rule *rules[MAX_EVENT_RULES];
  event_rule *ports[NR_PORT_TYPES];
  term_list *info;
} dap;

#line 25 "dap-admin.c.nw"
/* Debug adapters */
void dap_init();
void dap_dap_connected(term *dap, term_list *info);
void dap_dap_disconnected(term *dap);
dap *dap_get(int dapid);

/* Event rules */
void dap_rule_created(int dapid, int rid, term_list *procs, 
		term *port, term *cond, term *acts, term *lifetime);
void dap_rule_modified(int dapid, int rid, term_list *procs, 
		term *port, term *cond, term *acts, term *lifetime);
void dap_rule_destroyed(int dapid, int rid);
event_rule *dap_get_rule(int dapid, int ruleid);
int dap_id(term *d);
int dap_eventport(term *port);
int dap_eventwhen(term *when);
int dap_eventlife(term *life);
void dap_eventlocation(term *locdata, location *loc);

/* Processes */
void  dap_process_created(int dapid, int pid, char *name, int exec_state);
void  dap_process_destroyed(int dapid, int pid);
process *dap_get_process(int dapid, int pid);
int   dap_get_es(int dapid, int pid);
int   dap_term2es(term *t);
term *dap_es2term(int es);
int   dap_get_stop_level(int dapid, int pid);
int   dap_get_exec_state(int dapid, int pid);
char *dap_get_process_name(int dapid, int pid);
void  dap_set_process_data(int dapid, int pid, void *udata);
void *data_get_user_data(int dapid, int pid);
void  dap_set_process_flags(int dapid, int pid, int uflags);
void  dap_clear_process_flags(int dapid, int pid, int uflags);
unsigned  dap_check_process_flags(int dapid, int pid, int uflags);

/* External callbacks, must be provided by the user */
extern void cbdap_process_created(int dapid, int pid);
extern void cbdap_process_destroyed(int dapid, int pid);

#endif
