/*
 * bc-adapter -- Generic adapter for ToolBus <-> bc connection
 *
 * Synopsis: bc-adapter [-name N]
 *
 * where N is a toolname (only used by TBmsg)
 *
 * (c) Paul Klint, March, 1994.
 *
 * Purpose: pass term coming from ToolBus to bc, i.e.
 *
 *    eval(calc,"2+3")  ==> 2+3
 *
 * where receiveTB is a function defined in the Tcl script
 * capable of interpreting its argument and executing
 * application dependent tcl functions as needed.
 *
 *
 * Architecture:
 *
 *         ================== ToolBus
 *           |           ^
 *           v           |    (sockets)
 *         +---------------+
 *         |   bc-adapter  |
 *         +---------------+
 *           |           ^
 *           |           |
 *           |  +------+ |
 *           +->|  bc  |-+    (standard input/output)
 *              +------+
 *
 */

#include "TB.h"
#include <unistd.h>

FILE *to_bc;  /* stream connected to std input of bc */
FILE *from_bc; /* stream connected to std ouput of bc */

term *handle_input_from_toolbus(term *e)
{
  char *txt;

  if(TBmatch(e, "eval(calc,%s)", &txt)){       
    TBprintf(to_bc, "%s\n", txt);
    return NULL;
  } else { 
    TBmsg("Ignore: %t\n", e);
    return NULL;
  }
}

term *handle_input_from_bc(int fd)
{
  char line[512], line2[512];
  int res;

  line[0] ='\0'; 

  if(fgets(line, 512, from_bc)){ 
    TBmsg("read from bc: %s (length %d)\n", line, strlen(line));
    if(sscanf(line, "%d", &res))
      return TBmake("value(calc,%d)", res);
    else  if(sscanf(line, "syntax error on line %d", &res))
      return TBmake("value(calc,\"14:syntax \"error\"\")");
    else {
      fgets(line2, 512, from_bc);
      TBmsg("skip from bc: %s (length %d)\n", line2, strlen(line2));
      return TBmake("value(calc,error(%s))", line);
    }
  } else {
    TBmsg("Cannot read\n");
    return NULL;
  }
} 

int bc_pid;   /* process ID of bc process */

void connect_to_bc(TBcallbackChar handler)
{
  int adapter2bc[2];
  int bc2adapter[2];
  int old_stdin, old_stdout, fd_from_bc;

  if(pipe(adapter2bc) < 0 || pipe(bc2adapter) < 0){
    TBmsg("Can't create pipes"); exit(1);
  }
  old_stdin = dup(0);
  old_stdout = dup(1);

  to_bc = fdopen(adapter2bc[1], "w");
  fd_from_bc = bc2adapter[0];
  from_bc = fdopen(fd_from_bc, "r");

  close(0); close(1);

  if(dup(adapter2bc[0]) < 0 || dup(bc2adapter[1]) < 0){
    TBmsg("Can't dup (1)\n"); exit(1);
  }

  if((bc_pid = fork())){
    /* adapter: the parent */
    if(bc_pid < 0){
      TBmsg("Can't fork\n"); exit(1);
    }
    close(0); close(1);
    dup(old_stdin);
    dup(old_stdout);
    close(old_stdin);
    close(old_stdout); 
    TBaddCharPort(fd_from_bc, handler);
  } else {
    /* bc: the child */
    if(execlp("bc", "bc", NULL) < 0){
      TBmsg("Can't execute bc\n");
      exit(1);
    }
  }
}

#include <signal.h>

void interrupt_handler(int sig){ 
  kill(0, SIGKILL);  /* is this drastic?? */
/*  kill(bc_pid, SIGKILL); */
/*  kill(bc_pid+1, SIGKILL); */
  exit(-1);
}

void main(int argc, char *argv[])
{
  int i = 0;
  char *name = "bc-adapter";

  while(i < argc){
    if(streq(argv[i], "-name")){
      name = argv[i+1];
      break;
    }
    i++;
  }
  signal(SIGINT, interrupt_handler);
  signal(SIGKILL, interrupt_handler);
  signal(SIGTERM, interrupt_handler);

  TBinit(name, argc, argv, handle_input_from_toolbus, NULL);
  connect_to_bc(handle_input_from_bc);
  TBeventloop();
}
