/*

    ToolBus -- The ToolBus Application Architecture
    Copyright (C) 1998-2000  Stichting Mathematisch Centrum, Amsterdam, 
                             The  Netherlands.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/
#ifndef __TOOL_H__
#define __TOOL_H__

#include <stdio.h>
#include <stdarg.h>

int  TBinit(char *, int, char **, TBcallbackTerm, term *(*sigchk)(term *));
int  TBconnect(char *, char *, int port, TBcallbackTerm, term *(*sigchk)(term *), int *);
int  TBgetTid();
char *TBgetToolName();
int  TBaddTermPort(int, TBcallbackTerm);
int  TBaddCharPort(int, TBcallbackChar);
void TBfreePort(int port);
void TBsend(term *);
void TBreceive(void);
int  TBpeek(void);
void TBeventloop(void);
void TBmultiloop(void);
void TBsuspend(int inport); /* -1 to suspend input form standard toolbus */
void TBresume(int inport);  /* idem */
int  mkports(TBbool, char *, char *, int *, int *, int *);

typedef struct inport       /* connection info  */
{                           /* for input ports  */
  int            in;
  TBbool         term_port;
  TBbool	 suspended;
  TBcallbackTerm callbackTerm;
  TBcallbackChar callbackChar;
} inport;

#define TB_MAX_INPORT 10    /* max # of InPorts per tool */

#endif /* __TOOL_H__ */
