/*{{{  includes */

#include "atb-tool.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h> 
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/un.h>
#include <sys/param.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <signal.h>
#include <string.h>

#include <sys/resource.h>

#include <aterm2.h>
#include "safio.h"

/*}}}  */
/*{{{  defines */

#define TB_HOST			 "-TB_HOST"
#define TB_PORT			 "-TB_PORT"
#define TB_TOOL_ID		 "-TB_TOOL_ID"
#define TB_COLLECT_LOOP  "-TB_COLLECT_LOOP"
#define TB_TOOL_NAME	 "-TB_TOOL_NAME"
#define TB_HANDSHAKE_LEN 4096

#define MAX_CONNECT_ATTEMPTS 1024

#define BYTEBUFFERSIZE 32768
#define PACKBUFFERSIZE 65536

#define MAX_NR_QUEUES	64
#define MAX_QUEUE_LEN	128

/* Operation codes. */
/* From Tool to ToolBus. */
#define CONNECT 1
#define DISCONNECT 2
#define EVENT 3
#define VALUE 4
#define ACKDO 5
#define RESPONSE 6
/* From ToolBus to Tool. */
#define ACKEVENT 11
#define EVAL 12
#define DO 13
#define TERMINATE 14
#define REQUEST 15
/* Stats. */
#define PERFORMANCE_STATS 21
#define DEBUG_PERFORMANCE_STATS 22
/* Generic. */
#define END_OPC  127
#define UNDEFINED -1

/*}}}  */
/*{{{  types */

typedef struct
{
  int         tid;	  /* Tool id (assigned by ToolBus)             */
  int         fd;	  /* Filedescriptor of ToolBus connection      */
  FILE       *stream;	  /* The stream associated with fd             */
  int         port;	  /* Well-known ToolBus port (in/out)          */
  char       *toolname;	  /* Tool name (uniquely identifies interface) */
  char       *host;	  /* ToolBus host                              */
  ATBhandler  handler;	  /* Function that handles incoming terms      */
  ATbool      verbose;	  /* Should info be dumped on stderr           */
} Connection;

/*}}}  */
/*{{{  globals */

char atb_tool_id[] = "$Id$";

static char  this_host[MAXHOSTNAMELEN + 1] = "";
static char *default_host = this_host;
static char *default_toolname = NULL;

static int default_port = 4000;
static int default_tid  = -1;
static int default_collect_loop = 0;

static Connection *connections[FD_SETSIZE] = { NULL };

static int nrOfConnectedTools = 0;
 
static AFun symbol_rec_eval;
static AFun symbol_rec_do;
static AFun symbol_rec_ack_event;
static AFun symbol_rec_response;
static AFun symbol_rec_terminate;
static ATerm empty;
static ATerm snd_ack_do;
static ATerm snd_disconnect;

#ifndef NO_SAF_PACKING
	static AFun symbol_saf;
	static ByteBuffer packBuffer;
#endif

/* term buffers */
static char *opcodeWriteBuffer;
static char *lengthWriteBuffer;
static ByteBuffer writeBuffer;

static char *opcodeReadBuffer;
static char *lengthReadBuffer;
static ByteBuffer readBuffer;

static OperationTermPair otp;

/* Static functions */
static OperationTermPair readTerm(int fd);
static int writeTerm(int file_desc, ATerm term, int operation);
static int connect_to_socket(const char *host, int port);
static int mwrite(int fd, char *buf, int len);
static int mread(int fd, char *buf, int len);
static void handshake(Connection *connection, char *toolname, int tid);
/*}}}  */

int ATBgetDescriptors(fd_set *set);

/*{{{  int ATBinitialize(int argc, char *argv[]) */

int ATBinitialize(int argc, char *argv[])
{
  ATerm bottom;

  return ATBinit(argc, argv, &bottom);
}

/*}}}  */


/**
 * Gathers performance stats. 
 */
static ATerm getPerformanceStats(){
	struct rusage resourceUsage;
	
	// Type stuff
	ATerm remote = (ATerm) ATmakeAppl0(ATmakeAFun("remote", 0, ATtrue));
	ATerm toolType = (ATerm) ATmakeAppl1(ATmakeAFun("type", 1, ATfalse), remote);
	
	ATerm java = (ATerm) ATmakeAppl0(ATmakeAFun("C", 0, ATtrue));
	ATerm toolLanguage = (ATerm) ATmakeAppl1(ATmakeAFun("language", 1, ATfalse), java);
	
	ATerm toolData = (ATerm) ATmakeAppl2(ATmakeAFun("tool", 2, ATfalse), toolType, toolLanguage);
	
	// Memory stuff
	ATerm memory = ATparse("memory-usage(unsupported-operation)");
	
	// Thread stuff
	ATerm threads;
	
	getrusage(RUSAGE_SELF, &resourceUsage);
	
	{
		int userTime = (int) (resourceUsage.ru_utime.tv_sec * 1000) + (resourceUsage.ru_utime.tv_usec / 1000);
		int systemTime = (int) (resourceUsage.ru_stime.tv_sec * 1000) + (resourceUsage.ru_stime.tv_usec / 1000);
		
		ATerm userTimeTerm = (ATerm) ATmakeAppl1(ATmakeAFun("user-time", 1, ATfalse), (ATerm) ATmakeInt(userTime));
		ATerm systemTimeTerm = (ATerm) ATmakeAppl1(ATmakeAFun("system-time", 1, ATfalse), (ATerm) ATmakeInt(systemTime));
		
		ATerm mainThread = (ATerm) ATmakeAppl2(ATmakeAFun("main", 2, ATfalse), userTimeTerm, systemTimeTerm);
		
		ATerm threadsList = (ATerm) ATinsert(ATempty, mainThread);
		threads = (ATerm) ATmakeAppl1(ATmakeAFun("threads", 1, ATfalse), threadsList);
	}
	
	return (ATerm) ATmakeAppl3(ATmakeAFun("performance-stats", 3, ATfalse), toolData, memory, threads);
}

/**
 * Terminate a ToolBus connection
 */
static void closeConnection(int fd){
  /* Abort on illegal filedescriptors */
  assert(fd >= 0 && fd < FD_SETSIZE);

  /* Send the disconnect term */

  /* Close the actual filedescriptor */
  fclose(connections[fd]->stream);

  /* If there was a connection-structure associated with this fd,
   * then clean it up.
   */
  if (connections[fd] != NULL)
  {
    if (connections[fd]->toolname)
      free(connections[fd]->toolname);
    if (connections[fd]->host)
      free(connections[fd]->host);

    free(connections[fd]);
    connections[fd] = NULL;
  }
}

/**
 * Handle a single term from the ToolBus.
 */

int handle(int fd)
{
  ATermAppl tbTerm;
  ATerm result, term;
  int operation;
  
  OperationTermPair otp = readTerm(fd);
  if(otp == NULL) return -1;
  
  operation = otp->operation;
  term = otp->term;

  switch(operation){
    case DO:
      tbTerm = ATmakeAppl1(symbol_rec_do, term);
      connections[fd]->handler(fd, (ATerm) tbTerm);
      return writeTerm(fd, snd_ack_do, ACKDO);
    case EVAL:
      tbTerm = ATmakeAppl1(symbol_rec_eval, term);
      result = connections[fd]->handler(fd, (ATerm) tbTerm);
      result = ATgetArgument((ATermAppl) result, 0);
      return writeTerm(fd, result, VALUE);
    case ACKEVENT:
      /* We are not suppost to receive 'ackevent' stuff here. */
      ATerror("Unexpected ACKEVENT received.");
      return -1;
    case RESPONSE:
      /* We are not suppost to receive 'response' stuff here. */
      ATerror("Unexpected RESPONSE received.");
      return -1;
    case TERMINATE:
      nrOfConnectedTools--;
      writeTerm(fd, empty, END_OPC);
      tbTerm = ATmakeAppl1(symbol_rec_terminate, term);
      connections[fd]->handler(fd, (ATerm) tbTerm);
      return 0;
    case PERFORMANCE_STATS:
      result = getPerformanceStats();
      writeTerm(fd, result, PERFORMANCE_STATS);
      return 0;
    case DEBUG_PERFORMANCE_STATS:
      result = getPerformanceStats();
      writeTerm(fd, result, DEBUG_PERFORMANCE_STATS);
      return 0;
    case END_OPC:
	  nrOfConnectedTools--;
      /* Returning -1 has as result that closeConnection will be called */
      return -1;
    default:
      return -1;
  }
  return -1;
}

/*{{{  void disconnectHandler(int sig) */

void disconnectHandler(int sig)
{
  int i;

  for (i = 0; connections[i] != NULL; i++) {
    closeConnection(connections[i]->fd);
  }

  exit(0);
}

/*}}}  */

/**
 * Initialize the ToolBus layer.
 */

/*{{{  int ATBinit(int argc, char *argv[], ATerm *stack_bottom) */
int ATBinit(int argc, char *argv[], ATerm *stack_bottom)
{
  int lcv;

  for (lcv = 1; lcv < argc; lcv++) {
    if (streq(argv[lcv], "-at-help")) {
      fprintf(stderr, "    %-20s: specify toolbus tool name\n", TB_TOOL_NAME);
      fprintf(stderr, "    %-20s: specify toolbus host\n", TB_HOST);
      fprintf(stderr, "    %-20s: specify toolbus port\n", TB_PORT);
      fprintf(stderr, "    %-20s: specify toolbus tool id\n", TB_TOOL_ID);
      fprintf(stderr, "    %-20s: specify garbage collect frequency (0 is never,, N>0 is after every N events\n", TB_COLLECT_LOOP);
    }
  }

  ATinit(argc, argv, stack_bottom);

  /* Parse commandline arguments, set up default values */
  for (lcv = 1; lcv < argc; lcv++)
  {
    if (streq(argv[lcv], TB_TOOL_NAME)) {
      default_toolname = argv[++lcv];
    }else if (streq(argv[lcv], TB_HOST)) {
      default_host = argv[++lcv];
    }else if (streq(argv[lcv], TB_PORT)) {
      default_port = atoi(argv[++lcv]);
    }else if (streq(argv[lcv], TB_TOOL_ID)) {
      default_tid = atoi(argv[++lcv]);
    }else if (streq(argv[lcv], TB_COLLECT_LOOP)) {
      default_collect_loop = atoi(argv[++lcv]);
    }

  }

  /* Build some constants */
  symbol_rec_eval = ATmakeSymbol("rec-eval", 1, ATfalse);
  ATprotectSymbol(symbol_rec_eval);
  symbol_rec_do = ATmakeSymbol("rec-do", 1, ATfalse);
  ATprotectSymbol(symbol_rec_do);
  symbol_rec_ack_event = ATmakeSymbol("rec-ack-event", 1, ATfalse);
  ATprotectSymbol(symbol_rec_ack_event);
  symbol_rec_response = ATmakeSymbol("rec-response", 1, ATfalse);
  ATprotectSymbol(symbol_rec_response);
  symbol_rec_terminate = ATmakeSymbol("rec-terminate", 1, ATfalse);
  ATprotectSymbol(symbol_rec_terminate);
  empty = (ATerm) ATmakeList0();
  snd_ack_do = empty;
  snd_disconnect = empty;
  
  #ifndef NO_SAF_PACKING
	symbol_saf = ATmakeSymbol("saf-encoded", 1, ATfalse);
	ATprotectSymbol(symbol_saf);
    
    packBuffer = ATcreateByteBuffer(PACKBUFFERSIZE);
  #endif
  
  opcodeWriteBuffer = (char*) malloc(sizeof(char));
  lengthWriteBuffer = (char*) malloc(2 * sizeof(char));
  writeBuffer = ATcreateByteBuffer(BYTEBUFFERSIZE * sizeof(char));

  opcodeReadBuffer = (char*) malloc(sizeof(char));
  lengthReadBuffer = (char*) malloc(2 * sizeof(char));
  readBuffer = ATcreateByteBuffer(BYTEBUFFERSIZE * sizeof(char));
  
  otp = (OperationTermPair) malloc(sizeof(struct _OperationTermPair));

  /* Initialize handlers for OS signals */
  {
    struct sigaction disconnect;
    disconnect.sa_handler = disconnectHandler;
    sigemptyset(&disconnect.sa_mask);

    sigaction(SIGTERM, &disconnect, NULL);
    sigaction(SIGQUIT, &disconnect, NULL);
  }

  /* Get hostname of machine that runs this particular tool */
  return gethostname(this_host, MAXHOSTNAMELEN);
}

/*}}}  */

/*{{{  int ATBconnect(char *tool, char *host, int port, handler) */

/**
 * Create a new ToolBus connection.
 */

int ATBconnect(char *toolname, char *host, int port, ATBhandler h)
{
  ATerm connectTerm;
  ATermInt toolIDTerm;
  Connection *connection = NULL;
  int fd;
  
  int tid = port < 0 ? default_tid : -1;
  
  toolname = toolname ? toolname : default_toolname;
  host = host ? host : default_host;
  port = port > 0 ? port : default_port;
  
  /* Make new connection */
  fd = connect_to_socket(host, port);

  assert(fd >= 0 && fd <= FD_SETSIZE);

  /* There cannot be another connection with this descriptor */
  if (connections[fd] != NULL) {
    ATerror("ATBconnect: descriptor %d already in use.\n", fd);
  }

  /* Allocate new connection */
  connection = (Connection *) malloc(sizeof(Connection));
  if (connection == NULL) {
    ATerror("ATBconnect: no memory for new connection %d.\n", fd);
  }

  connection->stream = fdopen(fd, "w");
  if(connection->stream == NULL) {
    ATerror("couldn't open stream for connection %d\n", fd);
  }

  /* Initialize connection */
  connection->toolname = strdup(toolname);
  if (connection->toolname == NULL) {
    ATerror("ATBconnect: no memory for toolname.\n");
  }

  connection->host = strdup(host);
  if (connection->host == NULL) {
    ATerror("ATBconnect: no memory for host.\n");
  }

  connection->port     = port;
  connection->handler  = h;
  connection->verbose  = ATfalse;
  connection->tid      = tid;
  connection->fd       = fd;

  /* Link connection in array */
  connections[fd] = connection;

  /* Perform the ToolBus handshake */
  handshake(connection, toolname, tid);
  
  /* Send connect */
  toolIDTerm = ATmakeInt(tid);
  connectTerm = (ATerm) ATmakeAppl1(ATmakeAFun(toolname, 1, ATfalse), (ATerm) toolIDTerm);
  writeTerm(fd, connectTerm, CONNECT);
  
  nrOfConnectedTools++;

  return fd;
}

/*}}}  */
/*{{{  void ATBdisconnect(int fd) */

void ATBdisconnect(int fd)
{
	writeTerm(fd, snd_disconnect, DISCONNECT);
}

/*}}}  */

/*{{{  const char *connect_get_name(int fd) */

const char *connect_get_name(int fd)
{
  return connections[fd]->toolname;
}

/*}}}  */

/*{{{  static void ATBcollect(void)  */

static void ATBcollect(void) 
{
  static int count = 0;
  extern void AT_collect(void);

  if(default_collect_loop > 0) {
    if (++count >= default_collect_loop) {
      count = 0;
      AT_collect();
    }
  }
}

/*}}}  */
/*{{{  int ATBeventloop(void) */

/**
 * Wait for terms coming from the ToolBus and dispatch them to 
 * the appropriate handlers.
 */

int ATBeventloop(void)
{
  int fd;
  while(ATtrue) {
    fd = ATBhandleAny();
    
    if(fd < 0 && nrOfConnectedTools > 0) {
      fprintf(stderr, "warning: connection with ToolBus was lost.\n");
      return -1;
    }
    
    if(nrOfConnectedTools == 0){
    	return -1;
    }
    
    ATBcollect();
  }
}

/**
 * Send a term to the ToolBus.
 */

static int writeTerm(int fd, ATerm term, int operation){
	BinaryWriter binaryWriter = ATcreateBinaryWriter(term);
	
	/* Write opcode. */
	opcodeWriteBuffer[0] = (char) (operation & 0x0000007F);
	if(mwrite(fd, opcodeWriteBuffer, 1) < 1) return -1;
	
	while(!ATisFinishedWriting(binaryWriter)){
		int chunkSize;
		
		ATresetByteBuffer(writeBuffer);
		ATserialize(binaryWriter, writeBuffer);
		
		/* Write chunk size. */
		chunkSize = writeBuffer->limit;
		lengthWriteBuffer[0] = (char) (chunkSize & 0x000000ffU);
		lengthWriteBuffer[1] = (char) ((chunkSize & 0x0000ff00U) >> 8);
		if(mwrite(fd, lengthWriteBuffer, 2) < 2) return -1;
		
		/* Write data. */
		if(mwrite(fd, writeBuffer->buffer, chunkSize) < chunkSize) return -1;
	}
	
	ATdestroyBinaryWriter(binaryWriter);
	
	return 0;
}

/**
 * Receive a term from the ToolBus.
 */

static OperationTermPair readTerm(int fd){
	int operation;
	
	BinaryReader binaryReader = ATcreateBinaryReader();
	
	/* Read the opcode. */
	if(mread(fd, opcodeReadBuffer, 1) < 1) return NULL;
	operation = (int) opcodeReadBuffer[0];
	
	while(!ATisFinishedReading(binaryReader)){
		int chunkSize;
		
		/* Read chunk size. */
		if(mread(fd, lengthReadBuffer, 2) < 2) return NULL;
		chunkSize = (lengthReadBuffer[0] & 0x000000ffU) | ((lengthReadBuffer[1] & 0x000000ffU) << 8);
		
		/* Read data. */
		ATresetByteBuffer(readBuffer);
		if(mread(fd, readBuffer->currentPos, chunkSize) < chunkSize) return NULL;
		readBuffer->limit = chunkSize;
		ATdeserialize(binaryReader, readBuffer);
	}
	
	otp->operation = operation;
	otp->term = ATgetRoot(binaryReader);
	
	ATdestroyBinaryReader(binaryReader);
	
	return otp;
}

/*}}}  */
/*{{{  void ATBpostEvent(int fd, ATerm event) */

void ATBpostEvent(int fd, ATerm event)
{
	int operation;
	OperationTermPair otp;
	ATermList ackEvent;
	ATerm callbackData;
	ATermAppl tbTerm;
	
    writeTerm(fd, event, EVENT);
    
    otp = readTerm(fd);
  	if(otp == NULL) ATerror("Something went from while reading from a socket.\n");
  
  	operation = otp->operation;
  	if(operation != ACKEVENT) ATerror("Received aterm with op-code: %d, expected ACKEVENT.\n", operation);
  	
  	ackEvent = (ATermList) otp->term;
	callbackData = ATgetFirst(ATgetLast(ackEvent));
	
	tbTerm = ATmakeAppl1(symbol_rec_ack_event, callbackData);
	connections[fd]->handler(fd, (ATerm) tbTerm);
}

/*}}}  */
/*{{{  void ATBpostRequest(int fd, ATerm event) */

ATerm ATBpostRequest(int fd, ATerm request){
	int operation;
	OperationTermPair otp;
	
	writeTerm(fd, request, REQUEST);
	
	otp = readTerm(fd);
  	if(otp == NULL) ATerror("Something went from while reading from a socket.\n");
  
  	operation = otp->operation;
  	if(operation != RESPONSE) ATerror("Received aterm with op-code: %d, expected RESPONSE.\n", operation);
  	
  	return otp->term;
}

/*}}}  */
/*{{{  ATbool ATBpeekOne(int fd) */

/**
 * Check if there is any input waiting on a speficic connection.
 */

ATbool ATBpeekOne(int fd)
{
  fd_set set;
  int count = 0;
  struct timeval t;

  FD_ZERO(&set);
  FD_SET(connections[fd]->fd, &set);
  t.tv_sec = 0;
  t.tv_usec = 0;

  count = select(FD_SETSIZE, &set, NULL, NULL, &t);
  if(count)
    return ATtrue;
  else
    return ATfalse;   
}

/*}}}  */
/*{{{  int ATBpeekAny(void) */

/**
 * Check if there is input pending on any ToolBus connection.
 */

int ATBpeekAny(void)
{
  fd_set set;
  static int last = -1;
  int max, cur, count = 0;
  struct timeval t;

  t.tv_sec = 0;
  t.tv_usec = 0;

  FD_ZERO(&set);
  max = ATBgetDescriptors(&set);

  count = select(max+1, &set, NULL, NULL, &t);
  if(count <= 0)
    return -1;

  cur = last+1;
  while(cur != last) {
    if(connections[cur] && FD_ISSET(connections[cur]->fd, &set)) {
      last = cur;
      return cur;
    }
    cur = (cur+1) % max;
  }
  return -1;
}

/*}}}  */
/*{{{  int ATBhandleOne(int fd) */

int ATBhandleOne(int fd){
	return 0; // No-op.
}

/*}}}  */
/*{{{  int ATBhandleAny(void) */

/**
 * Handle a single term coming from any ToolBus connection.
 */

int ATBhandleAny(void)
{
  fd_set set;
  static int last = -1;
  int start, max, cur, count = 0;

  FD_ZERO(&set);
  max = ATBgetDescriptors(&set) + 1;
  if (max <= 1) {
    return -1;
  }

  /* only if the select is interrupted try again */
  errno = 0;
  do {
    count = select(max, &set, NULL, NULL, NULL);
  } while (count <= 0 && errno == EINTR);

  assert(count > 0);

  start = last+1;	
  cur = start;
  do {
    if(connections[cur] && FD_ISSET(cur, &set)) {
      last = cur;
      if(handle(cur) < 0) {
      	closeConnection(cur);
      }
      /* Signal 'activity', even on error! */
      return cur;
    }
    cur = (cur+1) % max;
  } while(cur != start);

  ATerror("ATBhandleAny: bottom\n");
  return -1;
}

/*}}}  */
/*{{{  int ATBgetDescriptors(fd_set *set) */

/**
 * Retrieve a set of descriptors for all connections.
 */

int ATBgetDescriptors(fd_set *set)
{
  int lcv, max = -1;

  for(lcv=0; lcv<FD_SETSIZE; lcv++) {
    if(connections[lcv] != NULL) {
      max = lcv;
      assert(connections[lcv]->fd == lcv);
      FD_SET(lcv, set);
    }
  }
  return max;
}

/*}}}  */

/*{{{  ATermList ATBcheckSignature(ATerm signature, char *sigs[], int nrsigs) */

/**
 * Check a signature.
 */

ATerm ATBcheckSignature(ATerm signature, char *sigs[], int nrsigs)
{
  ATermList list = (ATermList)signature;
  ATermList errors = ATempty;
  
  while(!ATisEmpty(list)) {
    int i;
    
    ATerm entry = ATgetFirst(list);
    list = ATgetNext(list);
	
    for(i=0; i<nrsigs; i++) {
      if(ATisEqual(ATparse(sigs[i]), entry)) break;
    }

    if(i == nrsigs)  errors = ATinsert(errors, entry);				
  }

  return (ATerm)errors;
}

/*}}}  */

/*{{{  static int connect_to_inet_socket(const char *host, int port) */

/**
 * Connect to a AF_INET type socket.
 */

static int connect_to_inet_socket(const char *host, int port)
{
  int sock;
  struct sockaddr_in isin;
  struct hostent *hp;
  int attempt;

  for(attempt=0; attempt<MAX_CONNECT_ATTEMPTS; attempt++) {
    if((sock = socket(AF_INET,SOCK_STREAM,0)) < 0) ATerror("cannot open socket\n");

    /* Initialize the socket address to the server's address. */
    memset((char *) &isin, 0, sizeof(isin));
    isin.sin_family = AF_INET;

    /* to get host address */
    hp = gethostbyname(host);
    if(hp == NULL) ATerror("cannot get hostname\n");

    memcpy (&(isin.sin_addr.s_addr), hp->h_addr, hp->h_length);
    isin.sin_port = htons(port);

    /* Connect to the server. */
    if(connect(sock, (struct sockaddr *)&isin, sizeof(isin)) < 0){
      close(sock);
    } else {
      setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, (char*) &sock, sizeof(sock));
      return sock;
    }
  }
  
  ATerror("connect_to_inet_socket: cannot connect after %d attempts, giving up.\n", attempt);
  
  return -1;
}

/*}}}  */
/*{{{  static int connect_to_socket (const char *host, int port) */

/**
 * Connect to a well-known ToolBus socket.
 */

static int connect_to_socket (const char *host, int port)
{
    return connect_to_inet_socket(host ? host : this_host, port);
}

/*}}}  */

/*{{{  static int mwrite(int fd, char *buf, int len) */

/**
 * Write a buffer to a file descriptor. 
 * Make sure all data has been written.
 */

static int mwrite(int fd, char *buf, int len)
{
  int cnt = 0, n;

  while(cnt < len) {
    if((n = write(fd, &buf[cnt], len-cnt)) <= 0) {
      if(errno != EINTR)
	return n;
    } else
      cnt += n;
  }
  assert(cnt == len);
  return cnt;
}

/*}}}  */
/*{{{  static int mread(int fd, char *buf, int len) */

/**
 * Read len bytes from fd in buf.
 */

static int mread(int fd, char *buf, int len)
{
  int cnt = 0, n;

  while(cnt < len){
    if((n = read(fd, &buf[cnt], len - cnt)) <= 0) {
      if(errno != EINTR)
	return n;
    } else
      cnt += n;
  }
if(cnt != len) fprintf(stderr, "Read %d, should be %d", cnt, len);
  assert(cnt == len);
  return cnt;
}

/*}}}  */

static ATerm readTermFromSocket(int fd, ByteBuffer byteBuffer){
	ATerm result;
	
	BinaryReader binaryReader = ATcreateBinaryReader();
	while(!ATisFinishedReading(binaryReader)){
		int chunkSize;
		
		ATresetByteBuffer(byteBuffer);
		byteBuffer->limit = 2;
		if(mread(fd, byteBuffer->currentPos, byteBuffer->limit) < byteBuffer->limit) return NULL;
		
		chunkSize = ((unsigned char) byteBuffer->buffer[0]) + (((unsigned char) byteBuffer->buffer[1]) << 8);

		ATresetByteBuffer(byteBuffer);
		byteBuffer->limit = chunkSize;
		if(mread(fd, byteBuffer->currentPos, byteBuffer->limit) < byteBuffer->limit) return NULL;
		
		ATdeserialize(binaryReader, byteBuffer);
	}
	
	result = ATgetRoot(binaryReader);
	
	ATdestroyBinaryReader(binaryReader);
	
	return result;
}

static int writeTermToSocket(int fd, ByteBuffer byteBuffer, ATerm aTerm){
	BinaryWriter binaryWriter = ATcreateBinaryWriter(aTerm);
	while(!ATisFinishedWriting(binaryWriter)){
		int chunkSize;
		
		ATresetByteBuffer(byteBuffer);
		byteBuffer->currentPos += 2;
		
		ATserialize(binaryWriter, byteBuffer);
		
		chunkSize = byteBuffer->limit - 2;
		byteBuffer->buffer[0] = (char) (chunkSize & 0x000000FF);
		byteBuffer->buffer[1] = (char) ((chunkSize & 0x0000FF00) >> 8);
		
		if(mwrite(fd, byteBuffer->currentPos, byteBuffer->limit) < byteBuffer->limit) return -1;
	}
	ATdestroyBinaryWriter(binaryWriter);
	
	return 0;
}

/*{{{  static void handshake(Connection *connection) */

/**
 * Execute the ToolBus handshake protocol.
 */

static void handshake(Connection *conn, char *toolname, int tid)
{
	ATerm newToolKey, signature;
	
	int fd = conn->fd;
	
	ByteBuffer handShakeBuffer = ATcreateByteBuffer(TB_HANDSHAKE_LEN);
	
	/* Send the current tool key to the ToolBus. */
	ATerm toolKey = (ATerm) ATmakeAppl(ATmakeAFun(toolname, 1, ATfalse), ATmakeInt(tid));
	
	if(writeTermToSocket(fd, handShakeBuffer, toolKey) < 0) ATerror("Sending tool key failed.\n");
	
	/* Read the signature. */
	signature = readTermFromSocket(fd, handShakeBuffer);
	if(signature == NULL) ATerror("An error occurred while reading the signature.\n");
	/* TODO : check signature? */
	
	ATresetByteBuffer(handShakeBuffer);
	handShakeBuffer->currentPos[0] = (char) 1;
	handShakeBuffer->limit = 1;
	if(mwrite(fd, handShakeBuffer->buffer, 1) < 1) ATerror("Unable to send SIG_OK flag to the ToolBus.\n");

	/* Receive the permanent tool key from the ToolBus. */
	newToolKey = readTermFromSocket(fd, handShakeBuffer);
	if(newToolKey == NULL) ATerror("An error occurred while reading the new tool key.\n");
	
	ATdestroyByteBuffer(handShakeBuffer);
}

/*}}}  */

/*{{{  ATbool ATBisValidConnection(int cid) */

ATbool ATBisValidConnection(int cid)
{
  return connections[cid] == NULL ? ATfalse : ATtrue;
}

/*}}}  */
/*{{{  int ATBgetPort(int cid) */

int ATBgetPort(int cid)
{
  assert(connections[cid]);

  return connections[cid]->port;
}

/*}}}  */
/*{{{  char *ATBgetHost(int cid) */

char* ATBgetHost(int cid)
{
  assert(connections[cid]);

  return connections[cid]->host;
}

/*}}}  */

/*{{{  ATerm ATBpack(ATerm t) */

#ifndef NO_SAF_PACKING
ATerm ATBpack(ATerm t)
{
	ATermList chunkList = ATmakeList0();
	BinaryWriter binaryWriter = ATcreateBinaryWriter(t);
	do{
		unsigned int size;
		char *data;
		ATermBlob chunk;
		
		ATresetByteBuffer(packBuffer);
		ATserialize(binaryWriter, packBuffer);
		
		size = packBuffer->limit;
		data = (char*) malloc(size * sizeof(char));
		if(data == NULL) ATerror("Out of memory in ATBpack.\n");
		memcpy(data, packBuffer->currentPos, size);
		
		chunk = ATmakeBlob(size, data);
		chunkList = ATinsert(chunkList, (ATerm) chunk);
	}while(ATisFinishedWriting(binaryWriter) == 0);
	ATdestroyBinaryWriter(binaryWriter);
	
	return (ATerm) ATmakeAppl1(symbol_saf, (ATerm) chunkList);
}
#else
ATerm ATBpack(ATerm t)
{
  return t;
}
#endif

/*}}}  */
/*{{{  ATerm ATBunpack(ATerm t) */

#ifndef NO_SAF_PACKING
ATerm ATBunpack(ATerm t)
{
  int i;
  ATerm result, annos;

  annos = AT_getAnnotations(t);
  switch (ATgetType(t)) {
    case AT_INT:
    case AT_REAL:
    case AT_BLOB:
      result = t;
      break;

    case AT_PLACEHOLDER:
      {
	ATerm type = ATgetPlaceholder((ATermPlaceholder)t);
	ATerm unpacked_type = ATBunpack(type);
	if (ATisEqual(unpacked_type, type)) {
	  result = t;
	} else {
	  result = (ATerm)ATmakePlaceholder(unpacked_type);
	}
      }
      break;

    case AT_APPL:
	{
		ATermAppl appl = (ATermAppl)t;
		AFun fun = ATgetAFun(appl);
		if(fun == symbol_saf){
			ATermList chunkList = (ATermList) ATgetArgument(appl, 0);
			int nrOfChunks = ATgetLength(chunkList);
			BinaryReader binaryReader = ATcreateBinaryReader();
			do{
				ATermBlob chunk = (ATermBlob) ATelementAt(chunkList, --nrOfChunks);
				char *data = ATgetBlobData(chunk);
				unsigned int size = ATgetBlobSize(chunk);
				ByteBuffer unpackBuffer = ATwrapBuffer(data, size);
				
				ATdeserialize(binaryReader, unpackBuffer);
				
				unpackBuffer->buffer = NULL;
				ATdestroyByteBuffer(unpackBuffer);
			}while(nrOfChunks > 0);
			
			if(ATisFinishedReading(binaryReader) == 0) ATerror("Unpacked term was incomplete.\n");
			
			result = ATgetRoot(binaryReader);
			
			ATdestroyBinaryReader(binaryReader);
		}else{
		  ATermList unpacked_args = ATempty;
	
		  for (i=ATgetArity(fun)-1; i>=0; i--) {
		    unpacked_args = ATinsert(unpacked_args, ATBunpack(ATgetArgument(appl, i)));
		  }
	
		  result = (ATerm)ATmakeApplList(fun, unpacked_args);
		}
	}
	break;

    case AT_LIST:
      {
	ATermList list = (ATermList)t;
	ATermList unpacked_list = ATempty;

	while (!ATisEmpty(list)) {
	  unpacked_list = ATinsert(unpacked_list, ATBunpack(ATgetFirst(list)));
	  list = ATgetNext(list);
	}

	result = (ATerm)ATreverse(unpacked_list);
      }
      break;

    default:
      abort();
  }

  if (annos != NULL) {
    annos = ATBunpack(annos);
    result = AT_setAnnotations(result, annos);
  }

  return result;
}
#else
ATerm ATBunpack(ATerm t)
{
  return t;
}
#endif
