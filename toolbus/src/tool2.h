
#ifndef __TOOL2_H
#define __TOOL2_H

#include "utils.h"
#include <stdio.h>
#include <stdarg.h>

/* An experimental new ToolBus API */

#define MAX_CONNECTIONS 16
typedef term *(*TBcallback)(int cid, term *);
typedef term *(*TBsigcheck)(int cid, term *);

typedef struct {
  /* These fields have to be filled before calling TB_connect */
  char      *tool_name;
  char      *host;
  int        port;
  TBcallback handler;
  TBsigcheck   sigchecker;
  TBbool     verbose;
  int tid; /* tid may have the value -1, meaning that it is not known yet */

  /* The following fields are filled in by TB_connect */
  int    socket;
  TBbool suspended;
} tb_connection; 

/* Some access functions */
void   TB_setTool(int cid, char *name);
char  *TB_getTool(int cid);
void   TB_setHost(int cid, char *host);
char  *TB_getHost(int cid);
void   TB_setPort(int cid, int port);
int    TB_getPort(int cid);
void   TB_setTid(int cid, int tid);
int    TB_getTid(int cid);
void   TB_setHandler(int cid, TBcallback handler);
TBcallback TB_getHandler(int cid);
int    TB_setSigChecker(int cid, TBsigcheck sigcheck);
TBsigcheck TB_getSigChecker(int cid);
int    TB_setVerbose(int cid, TBbool On);
TBbool TB_getVerbose(int cid);
TBbool TB_validConnection(int cid);
int    TB_getSocket(int cid);
term_list *TB_getConnections();

/* The meat of the functionality is defined here */
int    TB_init();
int    TB_newConnection(char *name, char *host, int port,
				TBcallback handler, TBsigcheck checker);
int    TB_parseArgs(int argc, char *argv[], 
				TBcallback handler, TBsigcheck checker);
int    TB_connect(int cid);
int    TB_send(int cid, term *t);
term  *TB_receive(int cid);
TBbool TB_peek(int cid);
int    TB_peek_next();
int    TB_handle_one(int cid);
int    TB_handle_any();
int    TB_eventloop();

int    TB_setFds(fd_set *set);
int    TB_match(term *trm, char *fmt, ...);
term  *TB_make(char *fmt, ...);
#endif
