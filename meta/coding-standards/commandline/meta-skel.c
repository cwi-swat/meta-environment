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
