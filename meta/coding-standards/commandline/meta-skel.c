/*

    Meta-Environment - An environment for language prototyping.
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
#include <stdio.h>
#include <unistd.h>

/*
    This is a sample C module, implementing a skeletal main
    routine conforming to Meta-Env argument conventions.

    Note: historic commandline requirements exist for ToolBus
          processes; ToolBus "mode" is detected, and treated
          distinctly.
 */

static char myname[] = "skel";
static char myversion[] = "1.0";

/*
    The argument vector: list of option letters, colons denote option
    arguments.  See Usage function, immediately below, for option
    explanation.
 */

static char myarguments[] = "bhi:o:tvV";

/*
    Usage: displays helpful usage information
 */
void usage(void)
{
    fprintf(stderr,
        "Usage: %s [options]\n"
        "Options:\n"
        "\t-b              output terms in BAF format (default)\n"
        "\t-h              display help information (usage)\n"
        "\t-i filename     input from file (default stdin)\n"
        "\t-o filename     output to file (default stdout)\n"
        "\t-t              output terms in plaintext format\n"
        "\t-v              verbose mode\n"
        "\t-V              reveal program version (i.e. %s)\n",
        myname, myversion);
				exit(1);
}

void version(void)
{
    fprintf(stderr, "%s v%s\n", myname, myversion);
}


int main(int argc, char **argv)
{
    /*  Configuration items  */
    char *input = "-";
    char *output = "-";
    int bafmode=1;
    int verbose=0;
    int proceed=1;

    extern char *optarg;
    extern int   optind;
    int c, toolbus_mode = 0;

    /*  Check whether we're a ToolBus process  */
    for(c=1; !toolbus_mode && c<argc; c++)
      toolbus_mode = !strcmp(argv[c], "-TB_TOOL_NAME");

    if(toolbus_mode) {

        /*  . . .  */

    } else {
    /*
        Option handling can be rather tool-specific, extend/adapt as needed...
     */
        while ((c = getopt(argc, argv, myarguments)) != -1) {
            switch (c) {
                case 'b':  bafmode = 1;                            break;
                case 't':  bafmode = 0;                            break;
                case 'v':  verbose = 1;                            break;
                case 'i':  input=optarg;                           break;
                case 'o':  output=optarg;                          break;
                case 'V':  version(); proceed=0;                   break;

                case 'h':
                default:   usage(); proceed=0;                     break;
            }
        }
        argc -= optind;
        argv += optind;

        if(proceed) {
          /*  . . .  */
        }
    }

    return 0;
}
