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
extern int find_tool_inport(char *, char *, int *);
extern int connect_tool(int, int, int);

int mk_server_ports(TBbool local_ports)
{
  int in = TB_ERROR,  /* Input port id  */
     out = TB_ERROR;  /* Output port id */

  in = createWellKnownSocket(local_ports ? NULL : this_host,
			     WellKnownSocketInPort);
                            
  if(in < 0)
    return TB_ERROR;
  out = createWellKnownSocket(local_ports ? NULL : this_host,
                             WellKnownSocketOutPort);
  if (out < 0) {
    TBdestroyPort(in);
    return TB_ERROR;
  }
  WellKnownSocketIn = in;
  WellKnownSocketOut = out;
  return TB_OK;
}

#define cleanup() \
        if(msgsock >= 0) close(msgsock); \
        if(outmsg >= 0) close(msgsock); \
        if(in >= 0) TBdestroyPort(in); \
        if(out >= 0) TBdestroyPort(out);

int accept_client(void)
{
/* SERVER SIDE CONNECT --
   1. accept client on well known socket.
   2. send unique port id (counter += 4)
   3. mk ports.
   4. sync.
*/
  int msgsock = TB_ERROR,
       outmsg = TB_ERROR,
           in = TB_ERROR,
          out = TB_ERROR;
  int nread, n, inport;
  char buf[TB_MAX_HANDSHAKE];
  char tname[256], hname[256];
  int that_tool_id = -1;
  
  msgsock = accept_in_interval(WellKnownSocketIn, 0, 0);
  if(msgsock < 0){
    err_sys_warn("Cannot accept on InPort of ToolBus");
    cleanup();
    return TB_ERROR;
  }
  if((nread = mread(msgsock,buf,TB_MAX_HANDSHAKE)) <= 0){
    err_sys_warn("Cannot read toolname");
    cleanup();
    return TB_ERROR;
  }
  if(sscanf(buf, "%s %s %d", tname, hname, &that_tool_id) != 3){
    err_warn("format error in toolname or hostname");
    cleanup();
    return TB_ERROR;
  }
  if(verbose)
    TBmsg("got toolname & host & tool_id: %s, %s, %d\n", 
	  tname, hname, that_tool_id);

  outmsg = msgsock; /* <PO> accept_in_interval(WellKnownSocketOut, 0, 0); */
  if(outmsg < 0){
    cleanup();
    err_sys_warn("Cannot accept on OutPort of ToolBus");
    return TB_ERROR;
  }
  inport = find_tool_inport(tname, hname, &that_tool_id);

  if(putInt(outmsg, tname, inport) <= 0){
    cleanup();
    return TB_ERROR;
  }
  if(putInt(outmsg, tname, that_tool_id) <= 0){
    cleanup();
    return TB_ERROR;
  }

  if(inport < 0){
    cleanup();
    return TB_ERROR;
  }

  if ((in = TBmakeInPort(streq(this_host, hname) ? NULL : this_host,
			 inport))
      == TB_ERROR){
    cleanup ();
    return TB_ERROR;
  } 
  if ((out = TBmakeOutPort(streq(this_host, hname) ? NULL : hname,
                           inport + 1))
      == TB_ERROR){
    cleanup();
    return TB_ERROR;
  } 

  close(msgsock);
  /* <P> close(outmsg); */

  if((n = getInt(in, tname)) != inport){
    err_warn("accept_client: got %d should be %d", n, inport);
    putInt(out, tname, -1);
    cleanup();
    return TB_ERROR;
  }
  if(putInt(out, tname, inport) <= 0){
    cleanup();
    return TB_ERROR;
  }
  connect_tool(that_tool_id, in, out);
  return TB_OK;
}
