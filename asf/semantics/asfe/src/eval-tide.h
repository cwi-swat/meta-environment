#ifndef EVAL_TIDE_H
#define EVAL_TIDE_H

#ifdef USE_TIDE

#define TIDE_PORT 9500

#define STATE_STOPPED  0
#define STATE_RUNNING  1

#define PORT_INITIAL      0
#define PORT_STEP         1
#define PORT_LOCATION     2
#define PORT_VAR_ACCESS   3
#define PORT_EXPR_CHANGED 4
#define PORT_METHOD_ENTRY 5
#define PORT_METHOD_EXIT  6
#define PORT_STOPPED      7
#define PORT_STARTED      8
#define PORT_EXCEPTION    9
#define NR_PORT_TYPES     10

void Tide_connect();
void Tide_disconnect();
void Tide_handleOne();
void Tide_activate(int porttype);
void Tide_step(ATerm position, ATerm env, int level);

extern int exec_state;
extern ATerm cpe;

#endif

#endif
