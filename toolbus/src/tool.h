#ifndef __TOOL_H__
#define __TOOL_H__

#include <stdio.h>
#include <stdarg.h>

int  TBinit(char *, int, char **, TBcallbackTerm, term *(*sigchk)(term *));
int  TBaddTermPort(int, TBcallbackTerm);
int  TBaddCharPort(int, TBcallbackChar);
int TBfreePort(int port);
void TBsend(term *);
void TBreceive(void);
int TBpeek(void);
void TBeventloop(void);
int mkports(TBbool, char *, int *, int *, int *);


typedef struct inport       /* connection info  */
{                           /* for input ports  */
  int            in;
  TBbool         term_port;
  TBcallbackTerm callbackTerm;
  TBcallbackChar callbackChar;
} inport;

#define TB_MAX_INPORT 10    /* max # of InPorts per tool */

extern int ninports;        /* # of connections currently in use */
extern inport inportset[TB_MAX_INPORT];

#endif /* __TOOL_H__ */
