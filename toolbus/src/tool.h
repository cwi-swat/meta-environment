#ifndef __TOOL_H__
#define __TOOL_H__

#include <stdio.h>
#include <stdarg.h>

int  TBinit(char *, int, char **, TBcallbackTerm, term *(*sigchk)(term *));
int  TBconnect(char *, char *, int in, int out, TBcallbackTerm, term *(*sigchk)(term *), int *);
int  TBaddTermPort(int, TBcallbackTerm);
int  TBaddCharPort(int, TBcallbackChar);
int  TBfreePort(int port);
void TBsend(term *);
void TBreceive(void);
int  TBpeek(void);
void TBeventloop(void);
void TBmultiloop(void);
void TBsuspend(int inport); /* -1 to suspend input form standard toolbus */
void TBresume(int inport);  /* idem */
int  mkports(TBbool, char *, char *, int *, int *, int *);

extern term *Snd_Void;

typedef struct inport       /* connection info  */
{                           /* for input ports  */
  int            in;
  TBbool         term_port;
  TBbool	 suspended;
  TBcallbackTerm callbackTerm;
  TBcallbackChar callbackChar;
} inport;

#define TB_MAX_INPORT 10    /* max # of InPorts per tool */

extern int ninports;        /* # of connections currently in use */
extern inport inportset[TB_MAX_INPORT];

#endif /* __TOOL_H__ */
