#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <atb-tool.h>

#include "getopt.h"

#include <aterm1.h>
#include <AsFix.h>

#include "parse-client.tif.c"

char  *program_name   = "parse-client";


/* This is a hack, due to JS */

#include <sys/stat.h>

char  *input_file_name  = "-";
char  *output_file_name = "-";
char  *start_symbol     = NULL;
char  *parse_table_name = NULL;

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
  ATerm t1,t2,t3;
  char *buf;
  size_t size;

  if(ATmatch(t,"open-language(<str>,<str>)",NULL,NULL)) { 
    buf = ReadFile(input_file_name,&size);
    if (buf != NULL) {
      t1 = ATmake("<str>", parse_table_name);
      t2 = ATmake("<str>", start_symbol);
      t3 = ATmake("<str>", buf);
      free(buf); 
      ATBwriteTerm(cid,
                   ATmake("snd-event(parsetext(<term>,<term>,<term>))",
                   t1,t2,t3));
    }
  }
  else if(ATmatch(t,
                  "parsetext(<str>,<str>,<str>,parse-error(<term>))",
                  NULL,NULL,NULL,&message)) {
    WriteFile(output_file_name,ATmake("parse-error(<term>)",message));
    ATBwriteTerm(cid, ATmake("snd-disconnect"));
    exit(1);
  }
  else if(ATmatch(t,
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
  {"input",         required_argument, NULL,               'i'},
  {"output",        required_argument, NULL,               'o'},
  {"parse-table",   required_argument, NULL,               'p'},
  {"start-symbol",  required_argument, NULL,               's'},
  {0, 0, 0, 0}
};

void Usage(FILE *stream, ATbool long_message)
{
  const char usage[] = "Usage: %s [-i file] [-o file]\n";

  ATfprintf(stream, usage, program_name);
  if(long_message) {
    ATfprintf
(stream,
 "\t-i file  : input from |file| (optional, default is stdin)\n"
 "\t-o file  : output to |file| (optional, default is stdout)\n"
             , program_name);
  }
}

void handle_options (int argc, char **argv)
{
  int c; /* option character */

  while ((c = getopt_long(argc, argv,
                          "i:o:p:s:",
                          longopts, NULL))
         != EOF)
    switch (c) {
    case 'i':   input_file_name  = optarg;    break;
    case 'o':   output_file_name = optarg;    break;
    case 'p':   parse_table_name = optarg;    break;
    case 's':   start_symbol     = optarg;    break;
    default:  Usage(stderr, ATfalse);      exit(1);
  }
}

int main (int argc, char **argv)
{
  int i, cid, use_toolbus = 0;
  ATerm bottomOfStack;

  ATerm t;

  for(i=1; !use_toolbus && i<argc; i++)
    if(!strcmp(argv[i], "-TB_TOOL_NAME"))
      use_toolbus = 1;

  if(use_toolbus) {
    ATBinit(argc, argv, &bottomOfStack);    /* Initialize Aterm library */
    cid = ATBconnect(NULL, NULL, -1, parse_client_handler);

    handle_options(argc-2, argv+2);
    t = ATmake("<str>", parse_table_name);
    ATBwriteTerm(cid,ATmake("snd-event(open-language(<term>,<term>))",t,t));
    ATBeventloop();
  }
  return 0;
}


