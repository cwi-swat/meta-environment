/*{{{  header */

/*

    ToolBus -- The ToolBus Application Architecture
    Copyright (C) 1998-2000  Stichting Mathematisch Centrum, Amsterdam, 
                             The  Netherlands.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/

/*}}}  */

/*{{{  includes */

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <ctype.h>

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
#include "sockets.h"

/*}}}  */
/*{{{  defines */

#define MAX_DBG_PROCS 64
#define MAX_PROCNAME_LENGTH 128


/*}}}  */
/*{{{  externs :( */

extern term_list *AllProcesses;

extern tool_inst_list *Tools;
extern TBbool local_ports;
extern void remove_socketfile();
void expand_all_calls();

/*}}}  */

/*{{{  void bus_shutdown(term *arg) */

void bus_shutdown(term *arg)
{
  tool_inst_list *til;
  tool_inst *ti;
  int out;
  term *e = mk_appl1(a_rec_terminate, arg);

  if(arg)
    TBprintf(stderr, "%t", arg);

  for(til = Tools; til; til = next(til)){
    ti = first(til);
    if((out = ti_out(ti)) >= 0){
      TBwrite(out, e);
    }
    destroy_ports_for_tool(ti);
    Tools = list_delete(Tools, ti);
  }
	
	/* Remove sockets that have been made by this toolbus. Defined in sockets.c */
	remove_socketfile();
  fflush(stderr);
  /* kill(0, SIGKILL); */
  exit(0);
}

/*}}}  */
/*{{{  void interrupt_handler(int sig) */

void interrupt_handler(int sig)
{
  bus_shutdown(mk_str("ToolBus interrupted"));
}

/*}}}  */

/*{{{  static void debug_handler(int sig) */

static void debug_handler(int sig)
{
  FILE *f;
  char processes[MAX_DBG_PROCS][MAX_PROCNAME_LENGTH];
  char buf[BUFSIZ];
  int nr_dbg_procs = 0, i;
  proc_inst *ProcInst;
  term_list *Processes;

  fprintf(stderr, "atomic_step_count: %d\n", atomic_step_count);

  f = fopen(".toolbus", "r");
  if (f != NULL) {
    while (fgets(buf, BUFSIZ, f) != NULL) {
      int length = strlen(buf);
      while (isspace(buf[length-1])) {
	buf[--length] = '\0';
      }
      strncpy(processes[nr_dbg_procs], buf, MAX_PROCNAME_LENGTH-1);
      processes[nr_dbg_procs][MAX_PROCNAME_LENGTH-1] = '\0';
      nr_dbg_procs++;
    }
    fclose(f);
  }

  for(Processes = AllProcesses; Processes; Processes = next(Processes)){
    ProcInst = first(Processes);
    if (nr_dbg_procs > 0) {
      char *name = str_val(pi_name(ProcInst));
      TBbool found = TBfalse;
      for (i=0; i<nr_dbg_procs; i++) {
	if (strcmp(name, processes[i]) == 0) {
	  found = TBtrue;
	  break;
	}
      }
      if (!found) {
	continue;
      }
    }
    print_process_snd_msgs_only(ProcInst);
  }
}

/*}}}  */

/*{{{  void usage(char *prg, int is_err) */

void usage(char *prg, int is_err)
{
 fprintf(stderr, "Usage: %s [-help|-version|-verbose] "
	 "[-logger|-viewer|-controller] [-gentifs] "
	 "[-fixed-seed] Script.tb\n", prg);

 exit(is_err);
}

/*}}}  */
/*{{{  void version(void) */

void version(void)
{
  printf("version: ToolBus-%s\n", VERSION);
}

/*}}}  */
/*{{{  void help(void) */

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
-TB_PORT N            use N as well-known socket of ToolBus\n\
Options for the preprocessor are:\n\
-Dmacro               define macro with value 1\n\
-Dmacro=defn          define macro with value defn\n\
-Idir                 search dir for include files\n\n";

  fprintf(stderr, str);
}

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{ 
  int i = 1;
  unsigned int seed = time(NULL);
  char *s;
  char *sname = NULL;
  TBbool gen_tifs = TBfalse;
  term *monitor;
  struct sigaction act;
  struct sigaction act_ignore;
  struct sigaction act_debug;

  extern time_t startup_time;
  extern TBbool parse_script(char *, int, char **);
  extern void chld_handler(int);


  act.sa_handler = interrupt_handler;
  sigemptyset(&act.sa_mask);
  act.sa_flags = SA_RESTART;
  sigaction(SIGINT,  &act, NULL);
  sigaction(SIGTERM, &act, NULL);
  sigaction(SIGHUP,  &act, NULL);
  act.sa_handler = chld_handler;
  sigaction(SIGCHLD, &act, NULL);

  sigemptyset(&act_debug.sa_mask);
  act_debug.sa_flags = SA_RESTART;
  act_debug.sa_handler = debug_handler;
  sigaction(SIGQUIT, &act_debug, NULL);

  act_ignore.sa_handler = SIG_IGN;
  act_ignore.sa_flags = SA_RESTART;
  sigemptyset(&act.sa_mask);
  sigaction(SIGPIPE, &act_ignore, NULL);
  
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
    } else if(streq(argv[i], "-help") || streq(argv[i], "-h")) {
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
    } else if(streq(argv[i], "-TB_USE_SOCKETS")) {
      WellKnownLocalSocket  = atoi(argv[++i]);
      WellKnownGlobalSocket = atoi(argv[++i]);
    } else if(streq(argv[i], "-gentifs")){
      gen_tifs = TBtrue;
    } else if((argv[i][0] == '-') && ((argv[i][1] == 'I') || (argv[i][1] == 'D'))){

    } else if(streq(argv[i], "-fixed-seed")) {
      seed = 0;
    } else if (streq(argv[i], "-seed")) {
      seed = atoi(argv[++i]);
    } else {
      sname = argv[i];
      break;
    }
  }

  srand(seed);

  init_terms();
  init_env();
  init_match();
  init_utils();
  init_procs();
  init_tools();
  init_interpreter();
 
  /* The system module is always present */
  system_init_module(); 
 
  if(argc < 2) {
    usage(argv[0], 1);
  }

  if(parse_script(sname, argc, argv)){
    if (TBverbose) TBmsg("parsing completed\n");
    /* HDJ: Don't init_monitoring() until WellKnownPort has been established!
     * monitor = init_monitoring();
     */
    if(typecheck(sname, gen_tifs)){
 
      if (TBverbose) TBmsg("typechecking completed\n");
      expand_all_calls();
      if(gen_tifs)
	exit(0);
      if (WellKnownGlobalSocket < 0 || WellKnownLocalSocket < 0) {
	if(mk_server_ports(local_ports) < 0) {
	  err_sys_fatal("Cannot create input/output ports of ToolBus");
	}
      }

      monitor = init_monitoring();
      create_toolbus(monitor);
      if (TBverbose) TBmsg("ToolBus created\n");
      interpreter();
    } else
      err_fatal("execution stopped due to the above error(s)");
  } else
    err_fatal("execution stopped due to the above error(s)");
  return 0;
}

/*}}}  */
