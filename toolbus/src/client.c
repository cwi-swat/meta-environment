#include "toolbus.h" 
#include "terms.h"
#include "tools.h"
#include "utils.h"

#include <sys/socket.h>
#include "sockets.h"

/* --- CLIENT SIDE CONNECT -------------------- */

/* client side mkports --
   1. connect to server
   2. get tool-id from server
 */

int mkports (TBbool local_ports, char *tool, char *tb_host, int *tid, int *tin, int *tout)
{
  int n;
  char buf[TB_MAX_HANDSHAKE];

  int sock = TB_ERROR;
  int get_tid = -1;
  *tin = *tout = TB_ERROR;

  /* TBmsg("mkports(%s,%d)\n", tb_host, *tid); */
  /* 1. connect to well known socket */
  if(streq(tb_host, this_host) || local_ports)
    sock = connectWellKnownSocket(NULL, WellKnownSocketPort);
  else
    sock = connectWellKnownSocket(tb_host, WellKnownSocketPort);

  if (sock < 0)  return TB_ERROR;

  /* client coming from "this_host",  open connection */
  sprintf(buf, "%s %s %d", tool, this_host, *tid);

  if(write(sock, buf, TB_MAX_HANDSHAKE) < 0){
    err_sys_warn("mkports -- can't write");
    close(sock);
    return TB_ERROR;
  }

  /* 2. get tool id from server */
  get_tid = getInt(sock, tool);

  /* sanity check */
  if(get_tid < 0){
    err_fatal("no port assigned by ToolBus");
    close(sock);
    return TB_ERROR;
  }
  if(*tid < 0)
    *tid = get_tid;
  else
    if(*tid != get_tid){
      err_warn("mkports -- tool id out of phase, giving up!"); 
      close(sock);
      return TB_ERROR;
    }

  *tout = sock;
  *tin  = sock;	
  return TB_OK;
}
