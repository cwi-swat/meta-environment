#include "toolbus.h"
#include "terms.h"
#include "env.h"
#include "match.h"
#include "procs.h"
#include "tools.h"

#include "interpreter.h"

#include "utils.h"
#include "monitor.h"
#include "typecheck.h"
#include <sys/socket.h>
#include "sockets.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>

extern tool_inst_list *Tools;
extern TBbool local_ports;

void bus_shutdown(term *arg)
{ tool_inst_list *til;
  tool_inst *ti;
  int out;
  term *e = mk_appl1(a_rec_terminate, arg);

  if(arg)
    TBprintf(stderr, "%t\n", arg);

  for(til = Tools; til; til = next(til)){
    ti = first(til);
    if((out = ti_out(ti)) >= 0){
      TBwrite(out, e);
    }
    destroy_ports_for_tool(ti);
    Tools = list_delete(Tools, ti);
  }
  fflush(stderr);
  /* kill(0, SIGKILL); */
  exit(0);
}

void interrupt_handler(int sig){
  bus_shutdown(mk_str("ToolBus interrupted"));
}

void usage(void)
{
 err_fatal("Usage: toolbus [-help|-version|-verbose] [-logger|-viewer|-controller] [-gentifs] [-fixed-seed] Script.tb");
}

void version(void)
{
  printf("version: ToolBus-%s\n", VERSION);
}

void help(void)
{
  char * str =
"\n\
ToolBus Interpreter\n\
===================\n\n\
Interconnect software tools as described in a ``T script''.\n\
\n\
Synopsis: toolbus [options] script.tb\n\
\n\
Options are:\n\
-help                 print this message and exit\n\
-version              print the version number and exit\n\
-verbose              print internal steps\n\
-logger               attach a logger tool\n\
-viewer               attach a viewer tool\n\
-controller           attach a controller tool\n\
-gentifs              generate tool interfaces, do not execute script\n\
-fixed-seed           use a fixed seed for the random generator\n\
-TB_INPORT N          use N as well-known input socket of ToolBus\n\
-TB_OUTPORT N         use N as well-known output socket of ToolBus\n\
-TB_LOCAL_PORTS       use only local port names\n\n\
Options for the preprocessor are:\n\
-Dmacro               define macro with value 1\n\
-Dmacro=defn          define macro with value defn\n\
-Idir                 search dir for include files\n\n";

  fprintf(stderr, str);
}

/*--- main program -----------------------------*/

int main(int argc, char *argv[])
{ 
  int i = 1;
  char *s;
  char *sname = NULL;
  TBbool gen_tifs = TBfalse;
  term *monitor;
  TBbool fixed_seed = TBfalse;

  extern time_t startup_time;
  extern TBbool parse_script(char *, int, char **);
  extern int mk_server_ports(TBbool);

  if(time(&startup_time) == -1)
    err_sys_fatal("Cannot read current time");

  tool_name = "ToolBus";
  gethostname(this_host, MAXHOSTNAMELEN);
  ToolBus = TBtrue;
  WellKnownSocketPort = TB_PORT;

  if((s = getenv("TB_VERBOSE")) && streq(s ,"true"))
    TBverbose = TBtrue;

  if((s = getenv("TB_LOCAL_PORTS")) && streq(s ,"true"))
    local_ports = TBtrue;

  for(i = 1; i < argc; i++){
    if(streq(argv[i], "-verbose")){
      TBverbose = TBtrue;
    } else if(streq(argv[i], "-help")){
      help(); exit(0);
    } else if(streq(argv[i], "-version")){
      version(); exit(0);
    } else if(streq(argv[i], "-logger")){
      set_monitoring(logger);
    } else if(streq(argv[i], "-viewer")){
      set_monitoring(viewer);
    } else if(streq(argv[i], "-controller")){
      set_monitoring(controller);
    } else if(streq(argv[i],"-TB_SINGLE")){
        stand_alone = TBtrue;
    } else if(streq(argv[i],"-TB_LOCAL_PORTS")){
	local_ports = TBtrue;
    } else if(streq(argv[i],"-TB_PORT")){
      i++;
      WellKnownSocketPort = atoi(argv[i]);
    } else if(streq(argv[i], "-gentifs")){
      gen_tifs = TBtrue;
    } else if((argv[i][0] == '-') && ((argv[i][1] == 'I') || (argv[i][1] == 'D'))){

    } else if(streq(argv[i], "-fixed-seed")) {
      fixed_seed = TBtrue;
    } else {
      sname = argv[i];
      break;
    }
  }
  signal(SIGINT, interrupt_handler);

  srand(fixed_seed ? 0 : time(NULL));

  init_terms();
  init_env();
  init_match();
  init_utils();
  init_procs();
  init_tools();
  init_interpreter();
 
  /* The system module is always present */
  system_init_module(); 

  /* Initialize other modules */
  INIT_MODULES
 
  if(argc < 2)
    usage();

  if(parse_script(sname, argc, argv)){
    if (TBverbose) TBmsg("parsing completed\n");
    monitor = init_monitoring();
    if(typecheck(sname, gen_tifs)){
 
      if (TBverbose) TBmsg("typechecking completed\n");
      expand_all_calls();
      if(gen_tifs)
	exit(0);
      if(mk_server_ports(local_ports) < 0)
	err_sys_fatal("Cannot create input/output ports of ToolBus");

      create_toolbus(monitor);
      if (TBverbose) TBmsg("ToolBus created\n");
      interpreter();
    } else
      err_fatal("execution stopped due to the above error(s)");
  } else
    err_fatal("execution stopped due to the above error(s)");
  return 0;
}

