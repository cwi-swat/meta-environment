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
#include "toolbus.h"
#include "terms.h"
#include "tools.h"
#include "utils.h"
#include "tool.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>
#include "sockets.h"

extern int mkports(TBbool, char *, char *, int *, int *, int *);

static int this_tool_id = -1;      /* tool_id assigned to this tool */

static int ninports = 0;           /* # of connections currently in use */
static inport inportset[TB_MAX_INPORT];

static int toToolBus;       /* port to ToolBus  */
static int fromToolBus;	    /* port from ToolBus */

term_list *tool_in_sign = NULL;  /* used by wish-adapter, etc. */
static term_list *tool_out_sign = NULL;

static term *Snd_Void; /* PROTECTED */

int TBaddTermPort(int in, TBcallbackTerm fun)
{
  int i;

  /* TBmsg("TBaddTermPort(%d,%d), ninports=%d\n", in, fun, ninports); */
  /* First, try to reuse a freed inport */
  for(i=0; i<ninports; i++) {
    if(inportset[i].in == -1) {
      /* Reuse this inport */
      inportset[i].in = in;
      inportset[i].term_port = TBtrue;
      inportset[i].suspended = TBfalse;
      inportset[i].callbackTerm = fun;
      return TB_OK;
    }
  } 
  if(ninports == TB_MAX_INPORT)
    err_fatal("TBaddTermPort -- too many inports");
  inportset[ninports].in = in;
  inportset[ninports].term_port = TBtrue;
  inportset[ninports].callbackTerm = fun;
  ninports++;
  return TB_OK;
}

int TBaddCharPort(int in, TBcallbackChar fun)
{
  int i;

  /* First, try to reuse a freed inport */
  for(i=0; i<ninports; i++) {
    if(inportset[i].in == -1) {
      /* Reuse this inport */
      inportset[i].in = in;
      inportset[i].term_port = TBfalse;
      inportset[i].callbackChar = fun;
      return TB_OK;
    }
  }
 
  if(ninports == TB_MAX_INPORT)
    err_fatal("TBaddCharPort -- too many inports");
  inportset[ninports].in = in;
  inportset[ninports].term_port = TBfalse;
  inportset[ninports].callbackChar = fun;
  ninports++;
  return TB_OK;
}

void TBfreePort(int in)
{
  int i;

  /* Try to find the port to be freed */
  for(i=0; i<ninports; i++) {
    if(inportset[i].in == in)
      inportset[i].in = -1;
  }
} 
    
static void help(void)
{
  char * str =
"\n\
Generic tool options are:\n\
-TB_PORT N            use N as well-known socket of ToolBus\n\
-TB_HOST Name         use the ToolBus running on machine Name\n\
-TB_TOOL_NAME Name    the name of this tool is Name\n\
-TB_TOOL_ID N         the allocated tool id for this tool is N\n\
-TB_SINGLE            stand-alone execution, do connect with ToolBus\n\
\n\n";

  fprintf(stderr, str);
}

int TBinit(char *tname, int argc, char *argv[],
       TBcallbackTerm fun, term * (check_in_sign)(term *))
{
  char *s;
  char host_toolbus[MAXHOSTNAMELEN];
  int fromToolBus, i = 1;
  TBbool local_ports = TBfalse;
  term *trm;

  tool_name = (tname) ? tname : "anonymous_tool";
  ToolBus = TBfalse;
  init_terms();
  init_utils();

  if(gethostname(this_host, MAXHOSTNAMELEN) < 0)
    err_sys_fatal("TBinit -- can't get host name");

  strcpy(host_toolbus, this_host);
  WellKnownSocketPort = TB_PORT;
  while(i < argc){
    if(streq(argv[i], "-help")){
      help(); exit(0);
    } else if(streq(argv[i], "-verbose")){
      TBverbose = TBtrue;
    } else if(streq(argv[i], "-TB_HOST")){
      i++;
      if(strlen(argv[i]) > MAXHOSTNAMELEN)
        err_fatal("TBinit -- name of ToolBus host too long");
      strcpy(host_toolbus, argv[i]);
      i++;
    } else if(streq(argv[i],"-TB_PORT")){
      i++;
      WellKnownSocketPort = atoi(argv[i++]);
   } else if(streq(argv[i],"-TB_TOOL_ID")){
     i++;
     this_tool_id = atoi(argv[i++]);
   } else if(streq(argv[i], "-TB_TOOL_NAME")){
     tool_name = argv[i+1];
     i += 2;
   } else if(streq(argv[i], "-TB_SINGLE")){
     i++;
     stand_alone = TBtrue;  
   } else if(streq(argv[i],"-TB_LOCAL_PORTS")){
     i++;
     local_ports = TBtrue;
   } else
     i++;
  }

  if((s = getenv("TB_VERBOSE")) && 
     streq(s ,"true"))
    TBverbose = TBtrue;

  if((s = getenv("TB_LOCAL_PORTS")) && 
     streq(s ,"true"))
    local_ports = TBtrue;


  if(stand_alone || !fun){ /* execute stand alone */
    /* TBaddTermPort(0, fun); */
    return TB_OK;
  }

  if(mkports(local_ports, tool_name, host_toolbus, &this_tool_id, &fromToolBus,
             &toToolBus) == TB_ERROR)
    err_fatal("TBinit -- can't connect to ToolBus");


  TBaddTermPort(fromToolBus, fun);

  Snd_Void = TBmake("snd-void()");
  TBprotect(&Snd_Void);

  trm = TBread(fromToolBus); /* obtain the tool signature from the ToolBus */

  if(TBmatch(trm, "rec-do(signature(%t,%t))", &tool_in_sign, &tool_out_sign)){
    TBsend(Snd_Void);
    if(check_in_sign){
      trm = (*check_in_sign)(tool_in_sign);
      if(trm)
	err_fatal("TBinit -- NOT IN INPUT SIGNATURE: %t", trm);
    }
  } else
    err_fatal("signature information garbled: %t", trm);


  return TB_OK;
}

int TBconnect(char *tname, char *host, int port,
	      TBcallbackTerm fun, term *(*check_in_sign)(term *), int *tid)
{
  int to_tb, from_tb;
  int old_port;

  term *tool_in_sign, *trm;

  /* Fool mkports into assuming a different WellKnown port */
  old_port = WellKnownSocketPort;
  WellKnownSocketPort = port;

  if(mkports(TBfalse, tname, host, tid, &from_tb, &to_tb) == TB_ERROR)
    err_fatal("TBconnect -- can't connect to ToolBus");

  /* Restore the old WellKnown port */
  WellKnownSocketPort = old_port;

  TBaddTermPort(from_tb, fun);
  trm = TBread(from_tb); /* obtain the tool signature from the ToolBus */

  if(TBmatch(trm, "rec-do(signature(%t,%t))", &tool_in_sign, &tool_out_sign)){
    TBwrite(to_tb, Snd_Void);
    if(check_in_sign){
      trm = (*check_in_sign)(tool_in_sign);
      if(trm)
	err_fatal("TBconnect -- NOT IN INPUT SIGNATURE: %t", trm);
    }
  } else
    err_fatal("signature information garbled: %t", trm);


  return to_tb;
}

int TBgetTid()
{
  return this_tool_id;
}

char *TBgetToolName()
{
  return tool_name;
}

static int read_from_any_channel(inport **inp)
{
  int i, nelem, error;
  fd_set read_template;

retry:
  FD_ZERO(&read_template);
  for(i = 0; i < ninports; i++){
    if(inportset[i].in >= 0 && !inportset[i].suspended)
      FD_SET(inportset[i].in,&read_template);
  }
  /* TBmsg("read_from_any_channel, before select\n"); */
  if((error = select(FD_SETSIZE, &read_template,
                     NULL, NULL, NULL)) >= 0){

    for(i = 0; i < ninports; i++){
      if(inportset[i].in >= 0 && 
	 FD_ISSET(inportset[i].in,&read_template)) {
	/* TBmsg("read_from_any_channel, data on port %d\n", inportset[i].in); */
        if(inportset[i].in == 0){
          nelem = read_from_stdin();
	} else if(inportset[i].term_port == TBfalse){
	  *inp = &inportset[i];
	  return 0;
        } else {
          nelem = multi_read(inportset[i].in);
	}
        if(nelem == 0){
          err_warn("lost connection with ToolBus");
	  exit(-1);
          }
        if(nelem < 0){
          err_sys_fatal("read failed"); /**************/
          goto retry;
        }
        *inp = &inportset[i];
        return nelem;
      }
    }
  } else {
    if(errno != EINTR)
      err_sys_warn("select failed");
    goto retry;
  }
  return TB_ERROR;
}

static int peek_channels(inport **inp)
{
  int i, error;
  fd_set read_template;
  struct timeval time;

  time.tv_sec = 0;
  time.tv_usec = 0;

retry:
  FD_ZERO(&read_template);
  for(i = 0; i < ninports; i++){
    if(inportset[i].in >= 0 && !inportset[i].suspended)
      FD_SET(inportset[i].in,&read_template);
  }
  if((error = select(FD_SETSIZE, &read_template,
                     NULL, NULL, &time)) >= 0){
    for(i = 0; i < ninports; i++){
      if(inportset[i].in >= 0 && 
	 FD_ISSET(inportset[i].in,&read_template)) {
        *inp = &inportset[i];
        return 1;
      }
    }
    *inp = NULL;
    return 0;
  }
  if(errno != EINTR)
    err_sys_warn("select failed");
  goto retry;
  /* <PO> unreachable code from lcc: return TB_ERROR; */
}

static term *tool_read_term(void)
{
  int nelem;
  term *trm, *rtrm;
  inport *inp;
  TBbool sndvoid = TBfalse;

  while(TBtrue){
    if(stand_alone){
      fprintf(stdout, "%s", single_prompt);
      fflush(stdout);
    }
    inp = NULL;
    nelem = read_from_any_channel(&inp);
    if(nelem < 0){
      err_warn("tool_read_term: cannot find ready input channel");
      continue;
    }
    if(inp && inp->term_port){
      if((trm = parse_buffer())){
	/*TBmsg("tool_read_term: ***%t***\n", trm);*/
	if(streq(get_txt(fun_sym(trm)), "rec-do"))
          sndvoid = TBtrue;
	rtrm = (*inp->callbackTerm)(trm);
	if(sndvoid)
	  return Snd_Void;
	else
	  return rtrm;
      }
    } else {
      if(inp)
	return (*inp->callbackChar)(inp->in);
    } 
  }
  return NULL; /* <PO> missing return from lcc */
}

/*--- TBsend -------------------------------------*/

void TBsend(term *e)
{
  TBwrite(toToolBus, e);
}

/*--- TBreceive ----------------------------------*/

void TBreceive(void)
{ term *e;

      if((e = tool_read_term()))
	TBsend(e);
      TBcollect();
}

/*--- TBpeek -----------------------------------*/

int TBpeek(void)
{
  inport *port;

  return peek_channels(&port);
}

/*--- TBsuspend --------------------------------*/

/* Suspend the input from a certain port.
   inport == -1 to suspend the input from the standard ToolBus input port. */
void TBsuspend(int inport)
{
  int i;

  if(inport == -1)
    inport = fromToolBus;

  for(i=0; i<ninports; i++) {
    if(inportset[i].in == inport) {
      /* Suspend this inport */
      inportset[i].suspended = TBtrue;
    }
  }
}

/*--- TBresume --------------------------------*/

/* Resume the input from a certain port.
   inport == -1 to suspend the input from the standard ToolBus input port. */
void TBresume(int inport)
{
  int i;

  if(inport == -1)
    inport = fromToolBus;

  for(i=0; i<ninports; i++) {
    if(inportset[i].in == inport) {
      /* Resume inpot from this inport */
      inportset[i].suspended = TBfalse;
    }
  }
}

/*--- TBeventloop ------------------------------*/

void TBeventloop(void)
{
  while(TBtrue)
    TBreceive();
}

/*--- TBmultiloop ------------------------------*/

void TBmultiloop(void)
{
  while(TBtrue) {
    tool_read_term();
    TBcollect();
  }
}
