#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <atb-tool.h>

#include <unistd.h>

#include <aterm1.h>
#include <AsFix.h>

#include "tree-to-dot.h"

#define  program_name  "tree2dot"

char   *input_file_name  = "-";
char   *output_file_name = "-";
ATbool suppress_lex = ATfalse;

void Usage(FILE *stream, ATbool long_message)
{
  const char usage[] =
    "Usage: %s [-i input-file] [(-o|-D) output-file] [-x]\n%s";
  const char long_usage[] =
    "\n"
    "\t-h        : usage information\n"
    "\t-i   file : input from |file|               (default: stdin)\n"
    "\t-o   file : output to |file|                (default: stdout)\n"
    "\t-D   file : output to |file|                (default: stdout)\n"
    "\t-x        : suppress lexicals               (default: off)\n";

  ATfprintf(stream, usage, program_name, long_message?long_usage:"");
}


int main (int argc, char **argv)
{
  int c; /* option character */
  ATerm bottomOfStack;
  ATerm t;
  char  *ATlibArgv[] = { "", "-silent"};
  FILE  *in;


  while ((c = getopt(argc, argv, "hi:o:D:x")) != EOF)
    switch (c) {
      case 'h':  Usage(stdout, ATtrue);        exit(0);
      case 'i':  input_file_name  = optarg;    break;
      case 'o':
      case 'D':  output_file_name = optarg;    break;
      case 'x':  suppress_lex = !suppress_lex; break;
      default :  Usage(stderr, ATfalse);       exit(1);
  }
  ATinit(2, ATlibArgv, &bottomOfStack);    /* Initialize Aterm library */

  if(!strcmp(input_file_name, "-"))
    in = stdin;
  else
    in = fopen(input_file_name, "r");
  if(!in) {
    ATfprintf(stderr, "%s: could not open input file %s",
              program_name, input_file_name);
    return 1;
  }
  t = ATreadFromFile(in);
  if(in != stdin)
    fclose(in);

  SGtreeToDotFile(program_name, output_file_name, t, suppress_lex);

  return 0;
}
