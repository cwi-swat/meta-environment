#include "toolbus.h" 
#include "terms.h"
#include "tools.h"
#include "utils.h"

#include <sys/socket.h>
#include "sockets.h"

/* --- CLIENT SIDE CONNECT -------------------- */

/* client side mkports --
   1. connect to server
   2. get port id
   3. mk ports
   4. sync
 */

#define cleanup() \
        if(in >= 0) { close(in); in = TB_ERROR;}\
        if(out >= 0) { close(out); out = TB_ERROR;}\
        if(*tin >= 0) { TBdestroyPort(*tin); *tin = TB_ERROR;}\
        if(*tout >= 0) { TBdestroyPort(*tout); *tout = TB_ERROR; }

int mkports (TBbool local_ports, char *tool, char *tb_host, int *tid, int *tin, int *tout)
{
  int portin, n;
  char buf[TB_MAX_HANDSHAKE];

  int in = TB_ERROR,		/* Input port id  */
  out = TB_ERROR;		/* Output port id */
  int get_tid = -1;

  /* TBmsg("mkports(%s,%d)\n", tb_host, *tid); */
  while(TBtrue){
    in = out = *tin = *tout = portin = TB_ERROR;
    /* 1. connect to well known socket */
    out = 
      connectWellKnownSocket(local_ports ? NULL : tb_host, 
			     WellKnownSocketInPort);
    if (out < 0)  return TB_ERROR;

    /* client coming from "this_host",  open connection */
    sprintf(buf, "%s %s %d", tool, this_host, *tid);

    if(write(out, buf, TB_MAX_HANDSHAKE) < 0){
      err_sys_warn("mkports -- can't write");
      cleanup();
      goto sync;
    }

    /* connect to well known socket */
    in =
      connectWellKnownSocket(local_ports ? NULL : tb_host, 
			     WellKnownSocketOutPort);
    if (in < 0) { cleanup (); goto sync; }  

    /* 2. get port number and tool id from server */
    portin = getInt (in, tool);
    get_tid = getInt(in, tool);

    /* close well known sockets */
    TBdestroyPort (in);  
    TBdestroyPort (out);

    /* sanity check */
    if((portin < 0) || (get_tid < 0)){
      err_fatal("no port assigned by ToolBus");
      cleanup();
      return TB_ERROR;
    }
    if(*tid < 0)
      *tid = get_tid;
    else
      if(*tid != get_tid){
	err_warn("mkports -- tool id out of phase, retrying ..."); 
	goto sync;
      }

    /* 3. make ports (out, in) */
    /* create the read end, connect to write end */
  
    if ((*tout =
	 TBmakeOutPort(streq(this_host,tb_host) ? NULL : tb_host,
		       portin))
	== TB_ERROR){
      cleanup ();
      goto sync;
    }  
  
    if ((*tin =
	 TBmakeInPort(streq(this_host,tb_host) ? NULL : this_host,
		      portin+1))
	== TB_ERROR){
      cleanup ();
      goto sync;
    }  

    /* 4. synchronize with server */
  sync:
    if(*tout >= 0){
      if(putInt (*tout, tool, portin) >= 0){
	if((n = getInt (*tin, tool)) != portin){
	  err_warn("mkports -- got %d should be %d\n", n, portin);
	} else
	  return TB_OK;
      }
    }
    cleanup();
  }
}
