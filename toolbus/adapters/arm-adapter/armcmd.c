#line 43 "armcmd.c.nw"
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#include <TB.h>
#include <tool2.h>
#include "armcmd.tif.c"
#line 59 "armcmd.c.nw"
#define MAX_ID_LEN    64

term_list *tasks = NULL;	/* The list of tasks that have to be done */
term *current_task = NULL;	/* The task the interpreter is working on */
char *interpreter = NULL;	/* The arm-interpreter to use */
term_list *search_paths = NULL; /* The list of search paths */
int TBcid;			/* Global ToolBus connection id */

#line 73 "armcmd.c.nw"
void exit_gracefully(int code)
{
  TB_send(TBcid, TB_make("snd-disconnect"));
  exit(code);
}
#line 87 "armcmd.c.nw"
void check_interpreter()
{
  if(!interpreter) {
    fprintf(stderr, "You must select an interpreter first!\n");
    exit_gracefully(1);
  }
  tasks = list_concat_term(tasks, TB_make("is-present(<str>)", interpreter));
}
#line 101 "armcmd.c.nw"
term *make_term(char *t)
{
  FILE *f;

  if(t[0] == '@') {
    f = fopen(&t[1], "r");
    if(!f) {
      fprintf(stderr, "couldn't open file: %s\n", &t[1]);
      exit_gracefully(1);
    }
    return TBreadTerm(f);
  }
  if(streq(t, "-")) {
    return TBreadTerm(stdin);
  }

  return TBmake(t);
}
#line 125 "armcmd.c.nw"
term_list *read_file_list(char *file)
{
  FILE *f;
  char *name[256];
  term_list *result = NULL;

  f = fopen(file, "r");
  if(!f) {
    fprintf(stderr, "couldn't open file: %s\n", file);
    exit_gracefully(1);
  }
  while(fscanf(f, "%s", name) != EOF) {
    result = list_concat_term(result, TB_make("<str>", name));
  }
  return result;
}
#line 147 "armcmd.c.nw"
void value(char *var, term *val)
{
  TBprintf(stdout, "%t\n", val);
}
#line 157 "armcmd.c.nw"
void error(int cid, char *msg)
{
  TBprintf(stderr, "error while processing %t:\n%s\n", current_task, msg);
}
#line 168 "armcmd.c.nw"
void reduction_result(int cid, term *t)
{
  TBprintf(stdout, "%t\n", t);
}

#line 178 "armcmd.c.nw"
void rec_ack_event(int cid, term *ev)
{
  char *interp, *msg;
  term *t, *r, *t2;
  term_list *l;

  if(TB_match(ev, "is-present(<str>,not-present)", &interp)) {
    fprintf(stderr, "interpreter %s not present\n", interp);
    exit_gracefully(1);
  }

  if(TB_match(ev, "match(<str>,term(<term>),term(<term>),<term>)", 
							&interp, &t,&t2,&r)) {
    if(TB_match(r, "ok"))
      printf("match ok\n");
    else
      printf("match failed!\n");
  } 

  if(TB_match(ev, "match(<str>,term(<term>),reduce(<term>),<term>)", 
							&interp, &t,&t2,&r)) {
    if(TB_match(r, "ok"))
      printf("reduce & match ok\n");
    else
      printf("reduce & match failed!\n");
  } 

  if(TB_match(ev, "get-value(<str>,term(<term>),term(<term>))", &interp, &t, &t2)) {
    TBprintf(stdout, "value: %t\n", t2);
  }

  if(TB_match(ev, "query(<list>)", &l)) {
    TBprintf(stdout, "Interpeters: %l\n", l);
  }

  if(TBmatch(ev, "reduce-asfix(%s,%t,%t)", &interp, &t, &r)) {
    if(TBmatch(r, "error(%s)", &msg)) {
      error(-1, msg);
    } else {
      reduction_result(-1, r);
    }
  }

  if(tasks == NULL) {
    /* All chores have been done, we can now leave the ToolBus */
    TB_send(TBcid, TB_make("snd-disconnect"));
    exit(0);
  } else {
    /* There are still some task left, process the next one! */
    current_task = first(tasks);
    tasks = next(tasks);

    TB_send(TBcid, TB_make("snd-event(<term>)", current_task));
  }
}
#line 239 "armcmd.c.nw"
void rec_terminate(int cid, term *arg)
{
  TBprintf(stderr, "rec-terminate called: %t\n", arg);
  exit(1);
}

#line 251 "armcmd.c.nw"
void task_create_interpreter(char *id)
{
  char *sep, *machine = NULL;
  char this_host[MAXHOSTNAMELEN];

  sep = strchr(id, ':');
  if(sep) {
    *sep = '\0';
    machine = sep+1;
  } else {
    gethostname(this_host, MAXHOSTNAMELEN);
    machine = this_host;
  }
  tasks = list_concat_term(tasks, 
		TB_make("create-interpreter(<str>,<str>)", id, machine));
  interpreter = id;
}
#line 274 "armcmd.c.nw"
void task_clear_arm()
{
  check_interpreter();
  tasks = list_concat_term(tasks, TBmake("clear-arm(%s)", interpreter));
}
#line 285 "armcmd.c.nw"
void task_load_mappings(char *trm)
{
  term *t = make_term(trm);

  check_interpreter();
  tasks = list_concat_term(tasks, TB_make("load-mappings(<str>,<term>)", 
							interpreter, t));
}
#line 299 "armcmd.c.nw"
void task_link_arm()
{
  check_interpreter();
  tasks = list_concat_term(tasks, TBmake("link-arm(%s)", interpreter));
}
#line 310 "armcmd.c.nw"
void task_load_arm_files(term_list *files)
{
  check_interpreter();
  tasks = list_concat_term(tasks, 
		TBmake("load-arm-files(%s,%t,%t)", 
		       interpreter, files, search_paths));
}
#line 323 "armcmd.c.nw"
void task_get_value(char *trm)
{
  term *t = make_term(trm);

  check_interpreter();
  tasks = list_concat_term(tasks, TB_make("get-value(<str>,term(<term>))", 
						interpreter, t));
}
#line 337 "armcmd.c.nw"
void task_match(char *term1, char *term2)
{
  term *t1 = make_term(term1);
  term *t2 = make_term(term2);

  check_interpreter();
  tasks = list_concat_term(tasks, 
	TB_make("match(<str>,term(<term>),term(<term>))", interpreter, t1, t2));
}
#line 367 "armcmd.c.nw"
void task_reduce(char *trm)
{
  term *t;

  t = make_term(trm);
  check_interpreter();
  tasks = list_concat_term(tasks, TB_make("reduce(<str>,term(<term>))", 
							interpreter, t));
}
#line 352 "armcmd.c.nw"
void task_reduce_match(char *term1, char *term2)
{
  term *t1 = make_term(term1);
  term *t2 = make_term(term2);

  check_interpreter();
  tasks = list_concat_term(tasks, 
	TB_make("match(<str>,term(<term>),reduce(<term>))", interpreter, t1, t2));
}
#line 382 "armcmd.c.nw"
void task_apply_reduce(char *func, char *trm)
{
  term *t;

  t = make_term(trm);
  check_interpreter();
  tasks = list_concat_term(tasks, TB_make("reduce(<str>,<appl>)", 
					 interpreter, func, t));
}
#line 397 "armcmd.c.nw"
void task_reduce_asfix_file(char *in)
{
  FILE *ifile;
  term *t;

  check_interpreter();
  if(streq(in, "-"))
    ifile = stdin;
  else {
    ifile = fopen(in, "r");
    if(!ifile) {
      fprintf(stderr, "cannot open input file %s\n", in);
      exit_gracefully(1);
    }
  }

  t = TBreadTerm(ifile);

  tasks = list_concat_term(tasks,
		TBmake("reduce-asfix(%s,%t)", interpreter, t));
}
#line 425 "armcmd.c.nw"
void task_query()
{
  tasks = list_concat_term(tasks, TBmake("query"));
}
#line 435 "armcmd.c.nw"
void task_shutdown()
{
  tasks = list_concat_term(tasks, TBmake("do-shutdown"));
}

#line 446 "armcmd.c.nw"
void usage(char *prg, int rv)
{
  FILE *f;

  if(rv == 1)
    f = stderr;
  else
    f = stdout;

  fprintf(f, "usage: %s <toolbus-options> [<task>|<interpreter>]*\n", prg);
  fprintf(f, "  <interpreter>               - switch uarm-interpreter to use\n");
  fprintf(f, "tasks:\n");
  fprintf(f, "  -load-mappings <term>       - load a number of mappings\n");
  fprintf(f, "  -create <uarm-id>[:machine] - create new uarm-interpreter\n");
  fprintf(f, "  -load-arm <arm-files>       - load a set of arm files\n");
  fprintf(f, "  -get-var <var-name>         - retrieve the value of a variable\n");
  fprintf(f, "  -set-var <var-name> <term>  - set the value of a variable\n");
  fprintf(f, "  -reduce <term>              - reduce a term\n");
  fprintf(f, "  -apply-reduce <func> <term> - apply func and reduce term\n");
/*  fprintf(f, "  -reduce-asfix-file <term>   - reduce an asfix term from a file\n");
*/
  fprintf(f, "  -path <path>                - add a search path for arm files.\n");
  fprintf(f, "  -clear-paths                - clear all arm search paths\n");
  fprintf(f, "  -query                      - print all the interpreters\n");
  fprintf(f, "  -shutdown                   - kill the resident toolbus\n");
  fprintf(f, "uarm-id    = identifies the uarm-interpreter instance to use\n");
  fprintf(f, "machine    = the machine on which to execute the arm interpreter\n");
  fprintf(f, "arm-files  = a list of arm files (filename may not start with -)\n");
  fprintf(f, "             if one of the entries starts with a @, arm filenames\n");
  fprintf(f, "             are read from file.\n");
  fprintf(f, "var-name   = a variable name\n");
  fprintf(f, "term       = a term, if it starts with a @, it is read from file.\n");
  fprintf(f, "func       = a function symbol (arity=1)\n");
  fprintf(f, "path       = a directory path\n");
  fprintf(f, "in         = input file name\n");
  fprintf(f, "out        = output file name\n");
  fprintf(f, "or: %s -help\n", prg);

  if(rv == 1)
    TBsend(TBmake("snd-disconnect"));
  exit(rv);
}
#line 495 "armcmd.c.nw"
void handle_options(int argc, char *argv[])
{
  int i;
  term_list *arm_files = NULL;

  for(i=1; i<argc; i++) {
    if(streq(argv[i], "-create")) {
      if(!argv[i+1])
        usage(argv[0], 1);
      task_create_interpreter(argv[++i]);
    } else if(streq(argv[i], "-clear-arm")) {
      task_clear_arm();
    } else if(streq(argv[i], "-load-mappings")) {
      task_load_mappings(argv[++i]);
    } else if(streq(argv[i], "-link-arm")) {
      task_link_arm();
    } else if(streq(argv[i], "-load-arm")) {
      arm_files = NULL;
      while(argv[i+1] && argv[i+1][0] != '-') {
        i++;
        if(argv[i][0] == '@') {
          arm_files = list_concat(arm_files, read_file_list(&argv[i][1]));
        } else {
	  arm_files = list_concat_term(arm_files, TBmake("%s", argv[i]));
        }
      }
      task_load_arm_files(arm_files);
    } else if(streq(argv[i], "-get-value")) {
      if(!argv[i+1])
        usage(argv[0], 1);
      task_get_value(argv[++i]);
    } else if(streq(argv[i], "-match")) {
      if(!argv[i+1] || !argv[i+2])
        usage(argv[0], 1);
      task_match(argv[++i], argv[++i]);
    } else if(streq(argv[i], "-reduce")) {
      if(!argv[i+1])
        usage(argv[0], 1);
      task_reduce(argv[++i]);
    } else if(streq(argv[i], "-reduce-match")) {
      if(!argv[i+1] || !argv[i+2])
        usage(argv[0], 1);
      task_reduce_match(argv[++i], argv[++i]);
    } else if(streq(argv[i], "-apply-reduce")) {
      if(!argv[i+1] || !argv[i+1])
        usage(argv[0], 1);
      task_apply_reduce(argv[++i], argv[++i]);
    } else if(streq(argv[i], "-reduce-asfix-file")) {
      if(!argv[i+1])
        usage(argv[0], 1);
      task_reduce_asfix_file(argv[++i]);
    } else if(streq(argv[i], "-path")) {
       if(!argv[i+1])
         usage(argv[0], 1);
       i++;
       if(argv[i][0] == '@') {
          search_paths = list_concat(search_paths, read_file_list(&argv[i][1]));
       } else {
         search_paths = list_concat_term(search_paths, TBmake("%s", argv[i]));
       }
    } else if(streq(argv[i], "-clear-paths")) {
       search_paths = NULL;
    } else if(streq(argv[i], "-query")) {
      task_query();
    } else if(streq(argv[i], "-shutdown")) {
      task_shutdown();
    } else {
      interpreter = argv[i];
    }
  }
}
#line 572 "armcmd.c.nw"
void first_task()
{
  /* Start the ball rolling */
  rec_ack_event(-1, NULL);
}
#line 584 "armcmd.c.nw"
int main(int argc, char *argv[])
{
  if(argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h')
    usage(argv[0], 0);
  if(argc == 3 && argv[2][0] == '-' && argv[2][1] == 'h')
    usage(argv[0], 0);

  TB_init();

  TBcid = TB_parseArgs(argc, argv, armcmd_handler, armcmd_check_in_sign);
  TB_connect(TBcid);

  /* make the current dir. part of the default search path */
  /*search_paths = TBmake("[\".\"]");*/

  TBprotect(&tasks);
  TBprotect(&current_task);
  TBprotect(&search_paths);

  handle_options(argc, argv);
  first_task();

  TB_eventloop();
  return 0;
}
