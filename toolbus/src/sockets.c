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

int WellKnownLocalSocket = TB_ERROR;
int WellKnownGlobalSocket = TB_ERROR;
int WellKnownSocketPort;

/*{{{  int getInt(int port, const char *tname) */

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

/*}}}  */
/*{{{  int putInt(int port, const char *tname, int n) */

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

/*}}}  */

/*{{{  static void set_connect_options(int sock) */

static void set_connect_options(int sock)
{
  if((setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, (char *)&sock, sizeof sock) < 0) && verbose)
	err_sys_warn("setsockopt TCP_NODELAY");

  if((setsockopt(sock, SOL_SOCKET, SO_SNDBUF, (char *)&buf_size, sizeof(int)) < 0) && verbose)
	err_sys_warn("setsockopt SO_SNDBUF");
}

/*}}}  */
/*{{{  static int connect_unix_socket(int port) */

static int connect_unix_socket(int port)
{
  int sock;
  char name[128];
  struct sockaddr_un usin;
  int attempts = 0;

  while(1) {
    sprintf (name, "/usr/tmp/%d", port);
    if((sock = socket(AF_UNIX,SOCK_STREAM,0)) < 0)
      err_sys_fatal("cannot open socket");

    if(verbose)
      TBmsg("created AF_UNIX socket %d\n", sock);

    /* Initialize the socket address to the server's address. */
    memset((char *) &usin, 0, sizeof(usin));
    usin.sun_family = AF_UNIX;
    strcpy (usin.sun_path, name);

    /* Connect to the server. */
    if(verbose)
      TBmsg("connecting to address %s\n", name);
    if(connect(sock, (struct sockaddr *) &usin,sizeof(usin)) < 0) {
      close(sock);
      if(attempts > 1000)
        err_sys_fatal("cannot connect, giving up"); 
      attempts++;
    } else {
      /* Connection established */
      chmod(name, 0777);
      set_connect_options(sock);
      return sock;
    }
  }
}

/*}}}  */
/*{{{  static int connect_inet_socket(const char *host, int port) */

static int connect_inet_socket(const char *host, int port)
{
  int sock;
  struct sockaddr_in isin;
  struct hostent *hp;
  int isConnected = 0;
  int attempts = 0;

  while(1) {
    if((sock = socket(AF_INET,SOCK_STREAM,0)) < 0)
      err_sys_fatal("cannot open socket");

    if(verbose)
      TBmsg("created AF_INET socket %d\n", sock);

    /* Initialize the socket address to the server's address. */
    memset((char *) &isin, 0, sizeof(isin));
    isin.sin_family = AF_INET;

    /* to get host address */
    hp = gethostbyname(host);
    if(hp == NULL)
      err_sys_fatal("cannot get host name");

    memcpy (&(isin.sin_addr.s_addr), hp->h_addr, hp->h_length);
    isin.sin_port = htons(port);

    /* Connect to the server. */
    if(verbose)
      TBmsg("connecting to INET host %s, port %d\n", host, port);
    if(connect(sock, (struct sockaddr *)&isin, sizeof(isin)) < 0){
      close(sock);
      if(attempts > 1000)
        err_sys_fatal("cannot connect, giving up");
      attempts++;
    } else {
      set_connect_options(sock);
      return sock;
    }
  }
}

/*}}}  */
/*{{{  static int connect_socket (const char *host, int port) */

static int connect_socket (const char *host, int port)
{    
  int sock;
  char name[128];    
  struct sockaddr_un usin;

  if(host == NULL)
    return connect_unix_socket(port);
  else
    return connect_inet_socket(host, port);
}

/*}}}  */

/*{{{  static void set_create_options(int  socket) */

static void set_create_options(int  sock)
{
  int opt = 1;

#ifdef sgi
  /* Solaris doesn't know SO_REUSEPORT */
  if((setsockopt(sock, SOL_SOCKET, SO_REUSEPORT, (char *)&opt, sizeof opt) < 0) && verbose)
    err_sys_warn("setsockopt SO_REUSEPORT");
#endif
  if((setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof opt) < 0) && verbose)
    err_sys_warn("setsockopt SO_REUSEADDR");
  if((setsockopt(sock, SOL_SOCKET, SO_RCVBUF, (char *)&buf_size, sizeof(int)) < 0) && verbose)
     err_sys_warn("setsockopt SO_RCVBUF");
}

/*}}}  */
/*{{{  static int create_unix_socket(int port) */

static int create_unix_socket(int port)
{
  struct sockaddr_un usin;
  char name[128] = "";
  int attempts = 0;
  int sock, length;

  sprintf (name, "/usr/tmp/%d", port);
  unlink (name);

  if((sock=socket(AF_UNIX,SOCK_STREAM,0)) < 0)
    err_sys_fatal("cannot open AF_UNIX stream socket");

  set_create_options(sock);
    
  /* Initialize socket's address structure */
  memset((char *) &usin, 0, sizeof(usin));
  usin.sun_family = AF_UNIX;
  strcpy (usin.sun_path, name);

  /* Assign an address to this socket */
  if(verbose)
    TBmsg("Binding %s\n", name);

  while(bind(sock,(struct sockaddr *)&usin,
    strlen(usin.sun_path)+ sizeof(usin.sun_family)) < 0){
    if(attempts > 1000)
      err_sys_fatal("cannot connect, giving up");
    attempts++;
    chmod (name, 0777);
  }
  return sock; 
}

/*}}}  */
/*{{{  static int create_inet_socket(const char *host, int port) */

static int create_inet_socket(const char *host, int port)
{
  struct sockaddr_in isin;
  int attempts = 0;
  int sock, length;
 
  if((sock=socket(AF_INET,SOCK_STREAM,0)) < 0)
    err_sys_fatal("cannot open stream socket");

  set_create_options(sock);
 
  /* Initialize socket's address structure */
  memset((char *) &isin, 0, sizeof(isin));
  isin.sin_family = AF_INET;
  isin.sin_addr.s_addr = htonl(INADDR_ANY); /* htonl added */
  isin.sin_port = htons(port);

  while (bind (sock,(struct sockaddr *)&isin,sizeof(isin)) < 0){
    if (attempts > 1000)
      err_sys_fatal("cannot connect, giving up");
    attempts++;
  }
  return sock;
}

/*}}}  */
/*{{{  static int create_socket (const char *host, int port) */

static int create_socket (const char *host, int port)
{
  int sock;

  /* Create a socket */
  if (host == NULL)
    sock = create_unix_socket(port);
  else
    sock = create_inet_socket(host, port);

  /* Prepare socket queue for connect requests */
  assert(sock >= 0);
  listen(sock,1);

  return sock;
}

/*}}}  */

/*{{{  void TBdestroyPort (int port) */

void TBdestroyPort (int port)
{
  close (port);
}

/*}}}  */
/*{{{  int createWellKnownSocket(char *host, int port) */

int createWellKnownSocket(char *host, int port)
{
  int sock = create_socket(host, port);
  if(verbose)
    TBmsg("createWellKnownSocket(%s,%d) returns %d\n", host ? host : "NULL", port, sock);
  return sock;
}

/*}}}  */
/*{{{  int connectWellKnownSocket(char *host, int port) */

int connectWellKnownSocket(char *host, int port)
{
  int sock = connect_socket(host, port);
  if(verbose)
    TBmsg("connectWellKnownSocket(%s,%d) returns %d\n", host ? host : "NULL", port, sock);
  return sock;
}

/*}}}  */

/*{{{  int accept_in_interval (int s, struct sockaddr *addr, int *addrlen) */

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

/*}}}  */
