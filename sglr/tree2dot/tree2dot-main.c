/*
 * $Id$
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#ifndef WIN32
  #include <unistd.h>
#else  /*  For broken platform with limited functionality  */
  #include <getopt.h>
  #include <atb-tool.h>
#endif /*  MS-DOS  */

#include <aterm1.h>
#include <AsFix.h>

#include "tree-to-dot.h"

static char myname[] = "tree2dot";
static char myversion[] = "1.0";

/*
    The argument vector: list of option letters, colons denote option
    arguments.  See Usage function, immediately below, for option
    explanation.
 */

static char myarguments[] = "bD:hi:o:tvVx";


/*
    Usage: displays helpful usage information
 */
void usage(void)
{
    static char *myargumentsexplained = NULL;

    /*  Represent the argument string in a slightly friendlier manner  */
    if(!myargumentsexplained && *myarguments) {
        int  i, hyphen = 0;
        char *ptr0, *ptr1;

        for(ptr0 = myarguments, i=0; *ptr0; ptr0++)
            if(*ptr0 == ':')
                i++;
        ptr1 = myargumentsexplained =
            (char *) malloc(strlen(myarguments) + 7*i + 2);
        for(ptr0 = myarguments; *ptr0; ptr0++)
            if(!*(ptr0+1) || *(ptr0+1) != ':') {
                if(!hyphen++) {
                    *ptr1++ = ' ';
                    *ptr1++ = '-';
                }
                *ptr1++ = *ptr0;
            } else {
                hyphen = 0;
                if(*(ptr1-1) != ' ')
                    *ptr1++ = ' ';
                *ptr1++ = '-'; *ptr1++ = *ptr0++; *ptr1++ = ' ';
                *ptr1++ = 'a'; *ptr1++ = 'r'; *ptr1++ = 'g';
            }
        *ptr1++ = '\0';
    }

    fprintf(stderr,
        "Usage: %s%s . . .\n"
        "Options:\n"
        "\t-b              ignored\n"
        "\t-D filename     output to file (default stdout)\n"
        "\t-h              display help information (usage)\n"
        "\t-i filename     input from file (default stdin)\n"
        "\t-o filename     output to file (default stdout)\n"
        "\t-t              ignored\n"
        "\t-v              ignored\n"
        "\t-V              reveal program version (i.e. %s)\n"
        "\t-x              suppress lexicals               (default: off)\n",
        myname, myargumentsexplained, myversion);
}

int main (int argc, char **argv)
{
  int c; /* option character */
  ATerm bottomOfStack;
  ATerm t;
  char  *ATlibArgv[] = { "", "-silent"};

  char   *input_file_name  = "-";
  char   *output_file_name = "-";
  ATbool suppress_lex = ATfalse;

  while ((c = getopt(argc, argv, "hi:o:D:x")) != EOF)
    switch (c) {
      case 'h':  usage();                      exit(0);
      case 'i':  input_file_name  = optarg;    break;
      case 'o':
      case 'D':  output_file_name = optarg;    break;
      case 'x':  suppress_lex = !suppress_lex; break;

      case 'b':
      case 't':
      case 'v':                                break;
      default :  usage();                      exit(1);
  }
  ATinit(2, ATlibArgv, &bottomOfStack);    /* Initialize Aterm library */

  t = ATreadFromNamedFile(input_file_name);
  if(!t) {
    ATerror("%s: could not read term from input file %s\n", myname, input_file_name);
  }

  SGtreeToDotFile(myname, output_file_name, t, suppress_lex);

  return 0;
}
