/*

    SGLR - the Scannerless Generalized LR parser.
    Copyright (C) 2000  Stichting Mathematisch Centrum, Amsterdam, The Netherlands.

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

#include <sglr.h>

/*  ambtrakker uses a few, erm, private sglr functions  */
void SG_InitPTGlobals(void);
ATerm SG_AmbTracker(ATerm t);


static char myname[]    = "ambtracker";
static char myversion[] = "1.2";

/*
    The argument vector: list of option letters, colons denote option
    arguments.  See Usage function, immediately below, for option
    explanation.
 */

static char myarguments[] = "bhi:o:tvVp";


/*
    Usage: displays helpful usage information
 */
void usage(void)
{
    fprintf(stderr,
        "Usage: %s -bh -i arg -o arg -tvVp . . .\n"
        "Options:\n"
        "\t-b              binary output mode (default)\n"
        "\t-h              display help information (usage)\n"
        "\t-i filename     input from file (default stdin)\n"
        "\t-o filename     output to file (default stdout)\n"
        "\t-t              text output mode\n"
        "\t-v              ignored\n"
        "\t-p              pretty printed output\n"
        "\t-V              reveal program version (i.e. %s)\n",
        myname, myversion);
}

ATerm deslash(ATerm atstr)
{
  char *tmp, *str = NULL;
  int i, length, found;
  ATerm result;

  if(ATmatch(atstr,"<str>", &tmp)) {
    str = strdup(tmp);
    length = strlen(str);

    /* copy string without slashes and quotes, 
     * including the EOS character
     */
    for(found = 0, i = 0; i <= length; i++) {
      switch(str[i]) {
	case '\\':
	case '"':
	  found++;
	  break;
	default:
	    str[i - found] = str[i];
	 break; 
      }	  
    }  
  }

  result = ATmake("<str>",str);
  free(str);
 
  return result;
}

int main (int argc, char **argv)
{
  int c; /* option character */
  ATerm bottomOfStack;
  ATerm t;
  ATbool txtout = ATfalse;
  char  *ATlibArgv[] = { "", "-silent"};
  ATbool prettyoutput = ATfalse;

  char   *input_file_name  = "-";
  char   *output_file_name = "-";
  
  while ((c = getopt(argc, argv, myarguments)) != EOF)
    switch (c) {
      case 'h':  usage();                      exit(0);
      case 'i':  input_file_name  = optarg;    break;
      case 'o':  output_file_name = optarg;    break;

      case 'b':  txtout = ATfalse;             break;
      case 't':  txtout = ATtrue;              break;
      case 'p':  prettyoutput = ATtrue;        break; 
      case 'v':                                break;
      case 'V':  fprintf(stdout, "%s %s\n", myname, myversion);
                                               exit(0);
      default :  usage();                      exit(1);
  }
  ATinit(2, ATlibArgv, &bottomOfStack);    /* Initialize Aterm library */

  t = ATreadFromNamedFile(input_file_name);
  if(!t) {
    ATerror("%s: could not read term from input file %s\n", myname, input_file_name);
  }

  SG_InitPTGlobals();
  t = SG_AmbTracker(t);

  if(t == NULL) {
    return 0;
  }

  if(prettyoutput) {
    ATermList ambs;
    ATerm count;
    int i;
    FILE *fp;

    if(!strcmp(output_file_name, "") || !strcmp(output_file_name,"-")) {
      fp = stdout;
    } else if(!(fp = fopen(output_file_name, "w"))) {
      ATerror("%s: could not open %s for output.\n", myname, output_file_name);
      return 1;
    }

    if (ATmatch(t, "ambiguities(<term>,[<list>])", &count, &ambs)) {
      ATfprintf(fp, "Total number of ambiguities: %t\n\n", count);
      
      for(i = 1;!ATisEmpty(ambs); ambs = ATgetNext(ambs), i++) {
        ATerm amb = ATgetFirst(ambs);
        ATermList productions;
        ATerm position, line, col;

        if(ATmatch(amb,"ambiguity(position(line(<term>), col(<term>), character(<term>)),productions([<list>]))",
                   &line, &col, &position, &productions)) {
          
          ATfprintf(fp,"number: %d, line: %t, col: %t productions:\n", i, line, col);
          
          for(;!ATisEmpty(productions); productions = ATgetNext(productions)) {
            ATfprintf(fp,"  %t\n", deslash(ATgetFirst(productions)));
          }

          ATfprintf(fp,"\n");
        } else {
          ATerror("Unexpected term\n");
        }
      }
    } else {
      ATerror("Unexpected term\n");
      return 1;
    }
  } else if(txtout) {
    ATwriteToNamedTextFile(t, output_file_name);
  } else {
    ATwriteToNamedBinaryFile(t, output_file_name);
  }

  return 0;
}
