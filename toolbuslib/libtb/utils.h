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
#ifndef __UTILS_H__
#define __UTILS_H__

#define TB_INIT_BUFFER 10000  /* maximum buf size for read/write  */
/*
#define TB_MAX_OVERFLOW 5000
*/

#define TB_BUF_INCR    100000  /* increment for buffer extensions */

#define TB_MAX_HANDSHAKE 512 /* size of handshake
                                buffer          */

#define TB_OK         0
#define TB_ERROR      -1

/* Default "Well known" sockets of ToolBus */
/* Allocation of tool ports starts at TB_INPORT+2 */

#define TB_PORT     8999

/* The minimal message size for messages coming over a socket */
#define MIN_MSG_SIZE                128

extern char *tool_name;
extern int buf_size;
/*
extern int overflowPort;
*/
extern TBbool  stand_alone;
extern TBbool  TBverbose;

extern char this_host[MAXHOSTNAMELEN];
extern char single_prompt[];

typedef term *(*TBcallbackTerm)(term *);
typedef term *(*TBcallbackChar)(int);
typedef term *(*TBsigchk)(term *);

term *read_term(tool_id **);
int   read_from_stdin(void);
term *read_and_parse_from_stdin(term *, term *);
term *parse_buffer(void);
int multi_read(int);
int mread(int, char *, int);

void   TBmsg(char *, ...);
void   TBprintf(FILE *, char *, ...);
void   TBvprintf(FILE *, char *, va_list);
char * TBvsprintf(char *fmt, va_list);
void   tbgen_printf(const char *, term_list *);
char   *TBsprintf(char *, ...);
TBbool TBmatch(term *, char *, ...);
term   *TBmake(char *, ...);
void   TBwrite(int, term *);
term   *TBread(int);   /* should become FILE * */
term   *TBreadTerm(FILE *);

int  TBsize(term *t);

void TBexit(int val);
int  TBatexit(void (*f)(void));

#ifndef HAVE_STRERROR
char *strerror(int);
#endif

void err_sys_warn(const char *, ...);
void err_sys_fatal(const char *, ...);
void err_warn(const char *, ...);
void err_fatal(const char *, ...);

void init_utils(void);

#endif /* __UTILS_H__ */
