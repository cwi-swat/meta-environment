
/*{{{  includes */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

#include <atb-tool.h>
#include <aterm2.h>

#include "sockets.h"

#include "toolbus-adapter.tif.h"

/*}}}  */
/*{{{  defines */

#define TB_ERROR -1
#define TB_PORT  8999

#define MAX_ARGS        256
#define MAX_ATTEMPTS	100

/*}}}  */

/*{{{  variables */

static char localhost[BUFSIZ];
static int master_cid = -1;
static int max_cid;

/*}}}  */

/*{{{  void toolbus_stop(int conn, int id) */

void toolbus_stop(int conn, int id)
{
  ATBwriteTerm(id, ATparse("toolbus-stop"));
}

/*}}}  */
/*{{{  ATerm toolbus_start(int conn, const char *script, ATerm args) */

ATerm toolbus_start(int conn, const char *script, ATerm args)
{
  int i, pid, cid;
  char *argv[MAX_ARGS];
  char sockets[2][BUFSIZ];

  WellKnownSocketPort = TB_PORT;
  if (mk_server_ports(0) == TB_ERROR) {
    ATerror("cannot create server ports, giving up!\n");
  } else {
    fprintf(stderr, "server ports created at %d\n", WellKnownSocketPort);
  }

  pid = fork();
  if (pid == -1) {
    ATerror("cannot fork toolbus-adapter, giving up!\n");
  } else if (pid > 0) {
    /* Parent */
    /* connect to child toolbus! */
    int attempts = 0;
    do {
      cid = ATBconnect(NULL, NULL, WellKnownSocketPort,
		       toolbus_adapter_handler);
      if (cid < 0) {
	tb_sleep(0, 500000);
      }
    } while (cid < 0 && attempts++ < MAX_ATTEMPTS);
    if (cid < 0) {
      return ATparse("snd-value(toolbus-error)");
    } else {
      if (cid > max_cid) {
	max_cid = cid;
      }
      return ATmake("snd-value(toolbus-started(<int>))", cid);
    }
  } else {
    /* Child */
    /*{{{  setup arguments */

    int argc = 0;
    ATermList arg_list;

    sprintf(sockets[0], "%d", WellKnownLocalSocket);
    sprintf(sockets[1], "%d", WellKnownGlobalSocket);

    argv[argc++] = TBPROG;
    argv[argc++] = "-TB_USE_SOCKETS";
    argv[argc++] = sockets[0];
    argv[argc++] = sockets[1];

    assert(ATgetType(args) == AT_LIST);
    arg_list = (ATermList)args;

    while (!ATisEmpty(arg_list)) {
      ATerm arg = ATgetFirst(arg_list);
      arg_list = ATgetNext(arg_list);
      if (ATgetType(arg) == AT_APPL) {
	argv[argc++] = ATgetName(ATgetAFun((ATermAppl)arg));
      } else {
	argv[argc] = strdup(ATwriteToString(arg));
	assert(argv[argc]);
	argc++;
      }
    }
    argv[argc++] = script;
    argv[argc] = NULL;

    for (i=0; i<argc; i++) {
      fprintf(stderr, "argv[%d] = %s\n", i, argv[i]);
    }

    /*}}}  */

    if (execv(TBPROG, argv) < 0) {
      perror(TBPROG);
      ATerror("cannot execute toolbus executable, giving up!\n");
    }
  }

  return NULL;
}

/*}}}  */
/*{{{  ATerm toolbus_snd_msg(int conn, int id, ATerm msg) */

ATerm toolbus_snd_msg(int conn, int id, ATerm msg)
{
  if (id >= 0) {
    ATBpostEvent(id, ATmake("toolbus-rec-msg(<term>)", msg));
    return ATparse("snd-value(msg-sent)");
  } else {
    return ATparse("snd-value(toolbus-gone)");
  }
}

/*}}}  */
/*{{{  ATerm toolbus_get_location(int conn, int cid) */

ATerm toolbus_get_location(int conn, int cid)
{
  assert(ATBisValidConnection(cid));

  return ATmake("snd-value(toolbus-location(<str>,<int>))",
		ATBgetHost(cid), ATBgetPort(cid));
}

/*}}}  */
/*{{{  ATerm toolbus_get_instances(int conn) */

ATerm toolbus_get_instances(int conn)
{
  ATermList result = ATempty;
  int cid;

  for (cid=max_cid; cid>=0; cid--) {
    if (ATBisValidConnection(cid)) {
      result = ATinsert(result, (ATerm)ATmakeInt(cid));
    }
  }

  return ATmake("snd-value(toolbus-instances(<term>))", result);
}

/*}}}  */

/*{{{  void rec_ack_event(int conn, ATerm event) */

void rec_ack_event(int conn, ATerm event)
{
}

/*}}}  */
/*{{{  void rec_terminate(int conn, ATerm arg) */

void rec_terminate(int conn, ATerm arg)
{
  int cid;

  ATfprintf(stderr, "rec_terminate %t: conn=%d, master_cid=%d\n",
	    arg, conn, master_cid);
  if (conn == master_cid) {
    for (cid=0; cid<=max_cid; cid++) {
      if (cid != master_cid && ATBisValidConnection(cid)) {
	ATBwriteTerm(cid, ATparse("snd-event(toolbus-stop)"));
      }
    }
    exit(0);
  }
}

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  ATerm bottomOfStack;
  gethostname(localhost, BUFSIZ);

  ATBinit(argc, argv, &bottomOfStack);
  master_cid = ATBconnect(NULL, NULL, -1, toolbus_adapter_handler);
  fprintf(stderr, "master_cid = %d\n", master_cid);
  if (master_cid >= 0) {
    ATBeventloop();
  } else {
    fprintf(stderr, "%s: Could not connect to the ToolBus, giving up!\n",
	    argv[0]);
    return 1;
  }

  return 0;
}

/*}}}  */
