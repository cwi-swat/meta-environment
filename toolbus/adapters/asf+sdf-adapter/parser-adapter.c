/* 
 * parser-adapter -- Generic adapter for ToolBus <-> parser connection
 *
 * Synopsis: parser-adapter [-tool-name N] [-cmd P]
 *
 * where N is the toolname to be used (only used by TBmsg)
 * and   P is the default parse command to be invoked.
 *
 * Author: Paul Klint, March/September, 1994.
 *
 * Purpose: Generic adapter for "parser"-like tools, i.e.
 * tools that transform their standard input (ascii text) into
 * a parse tree (usually represented in GEL).

 * Possible incoming requests:
 * (1) rec-eval(parse-cmd,text(S))
 *     use "parse-cmd" to parse text S
 * (2) eval(parser-name,text(S))
 *     use the default parse command P to parse text S
 *
 * Possible results:
 * (1) value(parser-name,parse-cmd,syntax-error(L,P,E))
 *     a syntax error was found
 * (2) value(parser-name,parse-cmd,error(%s))
 *     any other error encountered
 * (3) value(parser,parse-cmd,gel(S))
 *
 * Requirements on parse-cmd:
 * (1) On successfull parse:
 *     (a) gel output written to std output
 *     (b) exit status 0
 *     (c) Optional: the text "done" written on stderr stream.
 * (2) On unsuccessfull parse:
 *     (a) (Partial) gel output written to std output; it is ignored
 *     (b) exit status 1
 *     (c) On stderr stream a text is written that matches:
 *            "syntax error at line %d, pos %d: %[^\n]\n" 
 * Wed May 17 13:12:05 MDT 1995: paulk
 * - Added -help
 */

#include "TB.h"
#include "exec.c"

char **parse_cmd;
char *default_parser_name;

term *handle_input_from_toolbus(term *e)
{
  char *txt, output[10000], *outp, *msg;
  int lino, pos, c;
  FILE *from_parser;
  term *arg, *res;
  int i, n;

  memset((void *)output, 0, sizeof((void *)output));
  outp = output;
  parse_cmd[0] = default_parser_name;

  if(TBmatch(e, "rec-terminate(%t)", &arg)){
    cleanup_cmd();
    exit(0);
  } else if(TBmatch(e, "rec-eval(input(%s))", &txt)){
    exec_cmd(parse_cmd, txt, strlen(txt));
    if((msg = wait_cmd())){ 
      lino = 1;
      pos = 0;
      if(sscanf(msg, "syntax error at line %d, pos %d: %[^\n]\n", &lino, &pos, msg))
	return TBmake("snd-value(syntax-error(%d,%d,%s))", lino, pos, msg);
      else
	return TBmake("snd-value(error(%s))", msg);
    } else {	
      if((from_parser = fopen(cmd_out, "r")) == NULL)
	err_sys_fatal("opening tmp file");
 
      while((c = getc(from_parser)) != EOF)
	*outp++ = c;
      fclose(from_parser);
      n = outp - output;

      return TBmake("snd-value(output(gel(%b)))", output, outp - output);
    }
  } 
  TBmsg("Ignore: %t\n", e);
  return NULL;
}

#include <signal.h>

void interrupt_handler(int sig){
  cleanup_cmd();;
  kill(0, SIGKILL);  /* is this drastic?? */
/*  kill(parser_pid, SIGKILL); */
/*  kill(parser_pid+1, SIGKILL); */
  exit(-1);
}

void help(void)
{
  char * str =
"\n\
Synopsis: parser-adapter [options]\n\
\n\
Options are:\n\
-help                 print this message\n\
-cmd C1 ...           execute C1 ... as parser\n";
  fprintf(stderr, str);
}
void main(int argc, char *argv[])
{
  int i = 1;
  char *name = "parser-adapter";

  parse_cmd = NULL;

  while(i < argc){   
    if(streq(argv[i], "-help")){
      help();
    } else if(streq(argv[i], "-cmd")){
      parse_cmd = &argv[i+1]; i++;
      default_parser_name = parse_cmd[0];
      break;
    }
    i++;
  }
  TBinit(name, argc, argv, handle_input_from_toolbus, NULL);
  if(!parse_cmd)
    err_fatal("parse command missing");

  signal(SIGINT, interrupt_handler);
  signal(SIGKILL, interrupt_handler);
  signal(SIGTERM, interrupt_handler);

  TBeventloop();
}
