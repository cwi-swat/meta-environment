#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <atb-tool.h>

#include "getopt.h"

#include <aterm1.h>
#include <AsFix.h>

#include "parse-client.tif.c"

#define  program_name  "parse-client"


/* This is a hack, due to JS */

#include <sys/stat.h>

char  *input_file_name  = NULL;
char  *output_file_name = "-";
char  *start_symbol     = NULL;
char  *parse_table_name = NULL;
char  *hostname         = NULL;
char  *port             = NULL;
char  *tool             = program_name;

size_t  FileSize(char *fnam)
{
        struct stat     statbuf;

        if(stat(fnam, &statbuf) < 0) {
                fprintf(stderr, "could not stat() %s\n", fnam);
                return(-1);
        }
        return(statbuf.st_size);
}

char *ReadFile(char *fnam, size_t *size)
{
  char *buf;
  FILE *fd;

  *size = FileSize(fnam);
  if((fd = fopen(fnam, "r")) == NULL) {
    fprintf(stderr, "could not fopen() %s\n", fnam);
    *size = 0;
    return(NULL);
  }
  if((buf = (char *)malloc(*size + 1)) == NULL ) {
    fprintf(stderr, "could not allocate %i bytes for %s\n", *size + 1, fnam);
    fclose(fd);
    *size = 0;
    return(buf);
  }
  if(fread(buf, 1, *size, fd) != *size) {
    fprintf(stderr, "could not fread() %i bytes %s\n", *size, fnam);
    free(buf);
    *size = 0;
    buf = NULL;
  }
  fclose(fd);
  buf[*size] = '\0';      /* Terminate the string :-( */
  return(buf);
}

void WriteFile(char *fnam, ATerm tree)
{
  FILE *fd;

  if(!strcmp("-", fnam)) {
    ATwriteToBinaryFile(tree,stdout);
    return;
  }

  if((fd = fopen(fnam, "w")) == NULL) {
    fprintf(stderr, "could not fopen() %s\n", fnam);
  }
  else {
    ATwriteToBinaryFile(tree,fd);
    fclose(fd);
  }
}

void rec_ack_event(int cid, ATerm t) {
  ATerm tree, message;
  char *buf;
  size_t size;

  if(ATmatch(t,"open-language(<str>,<str>)",NULL,NULL)) { 
    if((buf = ReadFile(input_file_name,&size)) == NULL)
      exit(1);

    ATBwriteTerm(cid,
                 ATmake("snd-event(parsetext(<str>,<str>,<str>))",
                        parse_table_name,
			start_symbol?start_symbol:"",
			buf));
    free(buf); 
  } else if(ATmatch(t,
                  "parsetext(<str>,<str>,<str>,parse-error(<term>))",
                  NULL,NULL,NULL,&message)) {
    WriteFile(output_file_name,ATmake("parse-error(<term>)",message));
    ATBwriteTerm(cid, ATmake("snd-disconnect"));
    exit(1);
  } else if(ATmatch(t,
                  "parsetext(<str>,<str>,<str>,<term>)",
                  NULL,NULL,NULL,&tree)) { 
    WriteFile(output_file_name,tree);
    ATBwriteTerm(cid, ATmake("snd-disconnect"));
    exit(0);
  } 
}

void rec_terminate(int cid, ATerm t) {
  exit(0);
}

struct option longopts[] =
{
  {"help",          no_argument,       NULL,               'h'},
  {"input",         required_argument, NULL,               'i'},
  {"output",        required_argument, NULL,               'o'},
  {"parse-table",   required_argument, NULL,               'p'},
  {"start-symbol",  required_argument, NULL,               's'},
  {"tool",          required_argument, NULL,               'T'},
  {"TB_TOOL_NAME",  required_argument, NULL,               'T'},
  {"host",          required_argument, NULL,               'H'},
  {"TB_HOST",       required_argument, NULL,               'H'},
  {"port",          required_argument, NULL,               'P'},
  {"TB_PORT",       required_argument, NULL,               'P'},
  {0, 0, 0, 0}
};

void Usage(FILE *stream, ATbool long_message)
{
  const char usage[] =
    "Usage: %s -T toolname -i input-file -p parse-table [-o file]  \\\n"
    "       [-H hostname] [-P port] [-s sort]\n%s";
  const char long_usage[] = 
    "\n"
    "\t-h|--help              : usage information\n"
    "\t-i|--input        file : input from |file|                   (*)\n"
    "\t-p|--parse-table  file : use parse table |file|              (*)\n"
    "\t-s|--start-symbol sort : parse over sort |sort|\n"
    "\t-H|--host         host : parse server runs on |host|\n"
    "\t   --TB_HOST      host : ditto  (default: local host)\n"
    "\t-P|--port         port : parse server runs on |port|\n"
    "\t   --TB_PORT      port : ditto  (default: 8999)\n"
    "\t-T|--tool         tool : parse server toolname is |tool|\n"
    "\t   --TB_TOOL_NAME tool : ditto  (default: `"program_name"')\n"
    "\t-o|--output       file : output to |file| (default: stdout)\n"
    "\n"
    "\tItems marked with (*) are mandatory; all others are optional.\n";

  ATfprintf(stream, usage, program_name, long_message?long_usage:"");
}

void handle_options (int argc, char **argv)
{
  int c; /* option character */

  while ((c = getopt_long(argc, argv,
                          "hi:o:p:s:H:P:T:",
                          longopts, NULL))
         != EOF)
    switch (c) {
      case 'h':   Usage(stdout, ATtrue);        exit(0);
      case 'i':   input_file_name  = optarg;    break;
      case 'o':   output_file_name = optarg;    break;
      case 'p':   parse_table_name = optarg;    break;
      case 's':   start_symbol     = optarg;    break;
      case 'H':   hostname         = optarg;    break;
      case 'P':   port             = optarg;    break;
      case 'T':   tool             = optarg;    break;
      default:  Usage(stderr, ATfalse);        exit(1);
  }
  if(!input_file_name || !parse_table_name) {
    Usage(stderr, ATfalse);
    exit(1);
  }
}

int main (int argc, char **argv)
{
  int   cid;
  ATerm bottomOfStack;
  ATerm t;
  char  *ATlibArgv[] = { "", "-silent"};


  handle_options(argc, argv);

  ATBinit(2, ATlibArgv, &bottomOfStack);    /* Initialize Aterm library */
  cid = ATBconnect(tool, hostname?hostname:NULL, port?atoi(port):-1,
                   parse_client_handler);

  t = ATmake("<str>", parse_table_name);
  ATBwriteTerm(cid,ATmake("snd-event(open-language(<term>,<term>))", t, t));
  ATBeventloop();

  return 0;
}
