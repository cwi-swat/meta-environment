#include <stdio.h>
#include <stdlib.h>
#include <sys/param.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/un.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <netdb.h>

#include "toolbus.h" 
#include "terms.h"
#include "tools.h"
#include "utils.h"
#include "sockets.h"

int WellKnownSocketIn = TB_ERROR;
int WellKnownSocketOut = TB_ERROR;

int WellKnownSocketInPort;
int WellKnownSocketOutPort;

int getInt(int port, const char *tname)
{
  char buf[TB_MAX_HANDSHAKE], got_tool_name[256];
  int n, nread, nitems;

  if((nread = mread(port, buf, TB_MAX_HANDSHAKE)) < 0){
    err_sys_warn("getInt on port %d", port);
  }
  nitems = sscanf(buf,"%s %d",got_tool_name,&n);
  if(nitems != 2 || streq(tname, got_tool_name) == TBfalse)
    n = -1;
  if(verbose)
    TBmsg("getInt: got \"%s\", return: %d\n", buf, n);
  return n;
}
  
int putInt(int port, const char *tname, int n)
{
  char buf[TB_MAX_HANDSHAKE];
  int res;
  sprintf(buf, "%s %d", tname, n);
  if(verbose)
    TBmsg("putInt(%d, %s, %d)\n", port, tname, n);
  if((res = write(port, buf, TB_MAX_HANDSHAKE)) < 0){
    err_sys_warn("putInt -- write error");
  }
  return res;
}

int connectsocket (const char *host, int port)
{    
  int sock;
  char name[128];    
  struct sockaddr_un usin;
  struct sockaddr_in isin;
  struct hostent *hp;
  int isConnected = 0;
  int attempts = 0;
  
  while (!isConnected){

    if (host == NULL){
      sprintf (name, "/usr/tmp/%d", port);
      if ((sock = socket(AF_UNIX,SOCK_STREAM,0)) < 0)
        err_sys_fatal("cannot open socket");

      /* Initialize the socket address to the server's address. */
      memset((char *) &usin, 0, sizeof(usin));
      usin.sun_family = AF_UNIX;
      strcpy (usin.sun_path, name);

      /* Connect to the server. */
      if (connect(sock, (struct sockaddr *) &usin,sizeof(usin)) < 0){
        close(sock);
        if (attempts > 1000)
          err_sys_fatal("cannot connect, giving up"); 
        attempts++;
      } else {
        isConnected = 1;
      }
      chmod (name, 0777);
    } else {
      if((sock = socket(AF_INET,SOCK_STREAM,0)) < 0)
        err_sys_fatal("cannot open socket");

      /* Initialize the socket address to the server's address. */
      memset((char *) &isin, 0, sizeof(isin));
      isin.sin_family = AF_INET;

      /* to get host address */
      hp = gethostbyname(host);
      if (hp == NULL)
        err_sys_fatal("cannot get host name");

      memcpy (&(isin.sin_addr.s_addr), hp->h_addr, hp->h_length);
      isin.sin_port = htons(port);

      /* Connect to the server. */
      if(connect(sock, (struct sockaddr *)&isin, sizeof(isin)) < 0){
        close(sock);
        if (attempts > 1000)
          err_sys_fatal("cannot connect, giving up");
        attempts++;
      } else {
        isConnected = 1;
      }
    }
  }
  if((setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, (char *)&sock, sizeof sock) < 0) && verbose)
	err_sys_warn("setsockopt TCP_NODELAY");

  if((setsockopt(sock, SOL_SOCKET, SO_SNDBUF, (char *)&buf_size, sizeof(int)) < 0) && verbose)
	err_sys_warn("setsockopt SO_SNDBUF");
  return sock;
}

int createsocket (const char *host, int port)
{
  int sock, msgsock, length;
  struct sockaddr_un usin;
  struct sockaddr_in isin;
  int   opt = 1;
  char name[128] = "";
  int attempts = 0;
 
  /* Create a socket */
  if (host == NULL){
    sprintf (name, "/usr/tmp/%d", port);
    unlink (name);

    if((sock=socket(AF_UNIX,SOCK_STREAM,0)) < 0)
      err_sys_fatal("cannot open stream socket");
    
    /* Initialize socket's address structure */
    memset((char *) &usin, 0, sizeof(usin));
    usin.sun_family = AF_UNIX;
    strcpy (usin.sun_path, name);
  } else {
    if((sock=socket(AF_INET,SOCK_STREAM,0)) < 0)
      err_sys_fatal("cannot open stream socket");
 
    /* Initialize socket's address structure */
    memset((char *) &isin, 0, sizeof(isin));
    isin.sin_family = AF_INET;
    isin.sin_addr.s_addr = htonl(INADDR_ANY); /* htonl added */
    isin.sin_port = htons(port);
  }

#ifdef sgi
  /* Solaris doesn't know SO_REUSEPORT */
  if((setsockopt(sock, SOL_SOCKET, SO_REUSEPORT, (char *)&opt, sizeof opt) < 0) && verbose)
    err_sys_warn("setsockopt SO_REUSEPORT");
#endif
  if((setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof opt) < 0) && verbose)
    err_sys_warn("setsockopt SO_REUSEADDR");
  if((setsockopt(sock, SOL_SOCKET, SO_RCVBUF, (char *)&buf_size, sizeof(int)) < 0) && verbose)
     err_sys_warn("setsockopt SO_RCVBUF");
  /* Assign an address to this socket */
  if(verbose)
    TBmsg("Binding %s\n", name);
  if (host == NULL)
    while(bind(sock,(struct sockaddr *)&usin,
	       strlen(usin.sun_path)+ sizeof(usin.sun_family)) < 0){
      if (attempts > 1000)
        err_sys_fatal("cannot connect, giving up");
      attempts++;
      chmod (name, 0777);
    } 
  else
    while (bind (sock,(struct sockaddr *)&isin,sizeof(isin)) < 0){
      if (attempts > 1000)
        err_sys_fatal("cannot connect, giving up");
      attempts++;
    }
    
  /* Prepare socket queue for connect requests */
  listen(sock,1);

  /* <PO> was: ((port==TB_INPORT) || (port==TB_OUTPORT)) */
  if(ToolBus && ((port==WellKnownSocketInPort) || 
		 (port==WellKnownSocketOutPort)))
    return sock;
  else {
    if (host == NULL){
      length = sizeof(usin);
      msgsock = accept_in_interval(sock, (struct sockaddr *)&usin, &length);
      if (msgsock < 0)
        err_sys_fatal("cannot accept");
    } else {
      length = sizeof(isin);  
      msgsock = accept_in_interval(sock, (struct sockaddr *)&isin, &length);
      if (msgsock < 0)
        err_sys_fatal("cannot accept");
    }
    close (sock);
    return msgsock;
  }
}

/* General wrappers following the DTM model */

int TBmakeInPort (char *host, int port)
{
  int n;
  n = createsocket (host, port);
  if(verbose)
    TBmsg("TBmakeInPort(%s,%d) returns %d\n",  host, port, n);
  return n;
}

int TBmakeOutPort (char *host, int port)
{
  int n;
  n = connectsocket (host, port);
  if(verbose)
    TBmsg("TBmakeOutPort (%s, %d) returns %d\n",  host, port,n);
  return n;
}

void TBdestroyPort (int port)
{
  close (port);
}

int createWellKnownSocket(char *host, int port)
{
  return TBmakeInPort (host, port);
}

int connectWellKnownSocket(char *host, int port)
{
  return TBmakeOutPort(host, port);
}

int accept_in_interval (int s, struct sockaddr *addr, int *addrlen)
{ int error, sock;
  fd_set read_template;
  struct timeval timeout = { 10, 0};

  FD_ZERO(&read_template);
  FD_SET(s,&read_template);
  if(( error = select(FD_SETSIZE, &read_template, NULL, NULL, &timeout)) > 0){
    if((sock = accept(s, addr, addrlen)) < 0){
      err_sys_warn("cannot accept_in_interval");
      return -1;
    } else
      return sock;
  }
  return -1;
}
