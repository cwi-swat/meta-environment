#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>

#include "toolbus.h" 
#include "terms.h"
#include "tools.h"
#include "utils.h"
#include "sockets.h"

extern int ntool;
extern int find_tool_index(char *);
extern int connect_tool(int, int, int);

/*{{{  mk_server_ports(TBbool local_port_only) */

int mk_server_ports(TBbool local_port_only)
{
  int lsock, gsock = -1;

  lsock = createWellKnownSocket(NULL, WellKnownSocketPort);
  if(!local_port_only)
    gsock = createWellKnownSocket(this_host, WellKnownSocketPort);
                     
  if(lsock < 0 || (!local_port_only && gsock < 0))
    return TB_ERROR;

  WellKnownLocalSocket = lsock;
  WellKnownGlobalSocket = gsock;

  return TB_OK;
}

/*}}}  */
/*{{{  int accept_client(TBbool local) */

int accept_client(TBbool local)
{
/* SERVER SIDE CONNECT --
   1. accept client on well known socket.
   2. sync.
*/
  int sock = TB_ERROR;
  int nread, n;
  char buf[TB_MAX_HANDSHAKE];
  char tname[256], hname[256];
  int that_tool_id = -1;
  
  if(local)
    sock = accept_in_interval(WellKnownLocalSocket, 0, 0);
  else
    sock = accept_in_interval(WellKnownGlobalSocket, 0, 0);

  if(sock < 0){
    err_sys_warn("Cannot accept on InPort of ToolBus");
    return TB_ERROR;
  }
  if((nread = mread(sock,buf,TB_MAX_HANDSHAKE)) <= 0){
    err_sys_warn("Cannot read toolname");
    close(sock);
    return TB_ERROR;
  }
  if(sscanf(buf, "%s %s %d", tname, hname, &that_tool_id) != 3){
    err_warn("format error in toolname or hostname");
    close(sock);
    return TB_ERROR;
  }
  if(verbose)
    TBmsg("got toolname & host & tool_id: %s, %s, %d\n", 
	  tname, hname, that_tool_id);

  if(that_tool_id < 0)
    that_tool_id = add_tool(tname, hname);

  if(putInt(sock, tname, that_tool_id) <= 0){
    close(sock);
    return TB_ERROR;
  }

  connect_tool(that_tool_id, sock, sock);
  return TB_OK;
}

/*}}}  */
