/*
   %% $Id$
   %%
   %% Main program source for the Scannerless Generalized LR Parser SGLR.

   \section{An Application (main.c)}
   \label{main.c}

   In this section we define an application of the parse table and
   parse functions defined in the previous sections. The program can
   run in two modes: (1) As a standalone tool that reads a parse table
   and parses the text in a file given that parse table. (2) Connected
   to the ToolBus. In this mode several parse tables can be read in
   and several strings can be parsed using any of the parse
   tables. This saves the time of loading the parse table for each
   string.

*/

#include <stdio.h>
#include <TB.h>
#include "getopt.h"
#include "bool.h"
#include "parse-table.h"
#include "sglr.tif.c"
#include "stack.h"
#include "parser.h"
#include "tree-to-dot.h"

char *version_string = "$Revision$";
char *program_name   = "sglr";
int   debugflag;
int   verboseflag;
FILE *log = NULL;
char *input_file_name = "-";
char *output_file_name = "-";
int   write_output = TRUE;
char *parse_table_name = NULL;
int   abbreviation_flag = FALSE;
int   show_statistics = FALSE;
int   suppress_lexicals = FALSE;
char *dotoutput = "";
int   generate_dot = FALSE;
int   show_stack = FALSE;
char *stack_dotoutput = "";
int   gc = TRUE;
int   standalone=TRUE;


void batch (int argc, char **argv);
bool called_from_toolbus(int argc, char **argv);
void handle_options (int argc, char **argv);
void term_to_file(term *t, char *L);
FILE *open_file(char *std_error, char *FN);
FILE *open_log(char *FN);
/*
   \subsection{The Main Function}

   If the program is called from the ToolBus, the connection with is
   initialized by |TBinit| and the eventloop subsequently handles
   request from the Bus. The interface functions called by the
   eventloop are defined below. If the program is not called from the
   ToolBus, the function |batch| handles the parse request specified
   on the command line.

*/
int main (int argc, char **argv)
{
  if (called_from_toolbus(argc, argv)) {
    standalone = FALSE;
    TBinit("sglr", argc, argv, sglr_handler, sglr_check_in_sign);
    TBeventloop();
  } else {
    standalone = TRUE;
    batch(argc, argv);
  }
  return(0);
}

/*
  If the program is called from the ToolBus, the option
  |-TB_TOOL_NAME| is always present.
*/
bool called_from_toolbus(int argc, char **argv)
{
  int i;
  for (i = 0; i < argc; i++)
    if (!strcmp("-TB_TOOL_NAME", argv[i]))
      return TRUE;
  return FALSE;
}

/*
  \subsection{Batch Mode}

  In batch mode the program reads a parse table from file and uses
  it to parse a text from the input file. The result is written to
  the specified output file. The filenames should be specified as
  command line options, which are parsed by |handle_options|.

*/
void batch (int argc, char **argv)
{
  term *parse_tree = NULL, *tree;
  int c, line, col, length;

  handle_options(argc, argv);
  init_terms();       /* ToolBus library */
  init_utils();       /* ToolBus library */
  stand_alone = TRUE; /* ToolBus library */

  open_language(parse_table_name, parse_table_name);
  TBcollect();
  parse_tree = parse_file(parse_table_name, input_file_name);
  term_to_file(parse_tree, output_file_name);

  if (TBmatch(parse_tree,
               "parse-error([character(%d), line(%d), col(%d), char(%d)])",
               &c, &line, &col, &length)) {
    if (c == 0)
      fprintf(stderr,
              "(%s) %s: error: end of file unexpected\n",
              parse_table_name, input_file_name);
    else
      fprintf(stderr,
              "(%s) %s: error at line %d, col %d : character `%c' unexpected\n",
              parse_table_name, input_file_name, line, col, c);
    exit(1);
  } else if (! TBmatch(parse_tree, "parsetree(%t, %d)", &tree, &c)) {
      fprintf(stderr,
              "%s: error: result of successful parse is not a parse tree\n"
              "\t(this should never happen)\n", input_file_name);
      exit(1);
  }

  if (generate_dot)
    tree_to_dotfile(dotoutput, parse_tree, suppress_lexicals);

  fprintf(stderr, "%s: parsing succeeded (%i ambiguit%s)\n",
    input_file_name, c, c==1?"y":"ies");

  exit(0);
}

/*
  \paragraph{Usage}

  The function |usage| writes a short summary of the usage of the program.
  The following options are recognized:
  \begin{itemize}
  \item |-1|       : output AsFix1 format
  \item |-2|       : output AsFix2 format (default)
  \item |-p file|  : use parse table file (obligatory)
  \item |-i file|  : input from file (optional, default is stdin)
  \item |-o file|  : output to file (optional, default is stdout)
  \item |-n|       : don't write tree to output
  \item |-d|       : debugging mode
  \item |-g|       : no garbage collects
  \item |-h|, |-?| : help (print usage information)
  \item |-l]       : suppress lexical information in dot output
  \item |-v|       : verbose mode
  \item |-V|       : print version information
  \item |-a|       : do not abbreviate productions in parse trees
  \item |-s|       : write show statistics to log file
  \item |-S|       : show stacks as dot files
  \item |-D [file]| : draw tree as graph.
  \end{itemize}
*/
void usage(FILE *stream, int long_message)
{
  if( !long_message )
    fprintf (stream,
             "Usage: %s -p file [-i file] [-o file] [-12adDghlnsSvV?]\n",
             program_name);
  else {
    fprintf
(stream,
 "Usage: %s -p file [-i file] [-o file] [-12adDghlnsSvV?]\n"
 "\n"
 "\t-1      : use AsFix1 output format\n"
 "\t-2      : use AsFix2 output format (default)\n"
 "\t-a      : do not abbreviate productions in parse trees\n"
 "\t-d      : debugging mode\n"
 "\t-D file : generate dot output for parse tree\n"
 "\t-g      : no garbage collect\n"
 "\t-h      : help (print usage information)\n"
 "\t-i file : input from |file| (optional, default is stdin)\n"
 "\t-l      : suppress lexical information in dot output\n"
 "\t-n      : don't write tree to output\n"
 "\t-o file : output to |file| (optional, default is stdout)\n"
 "\t-p file : use parse table |file| (obligatory)\n"
 "\t-s      : show statistics\n"
 "\t-S file : show stacks as dot files\n"
 "\t-v      : verbose mode\n"
 "\t-V      : print version information\n"
 "\t-?      : print version information\n"
             , program_name);
  }
}

/*
  \paragraph{Option Parsing}

  To parse the option strings passed to the main program the GNU
  package |getopt| is used. The |longopts| array contains the `long'
  names for the options and the corresponding abbreviations. Long
  options can be called using two hyphens. For instance, |-i file|
  is an abbreviation for |--input file|.
*/
struct option longopts[] =
{
  {"abbreviate",  no_argument,       &abbreviation_flag, FALSE},
  {"asfix1",      no_argument,       NULL,               TRUE},
  {"asfix2",      no_argument,       NULL,               FALSE},
  {"debug",       no_argument,       &debugflag,         TRUE},
  {"dot",         no_argument,       NULL,               'D'},
  {"suppress",    no_argument,       NULL,               'l'},
  {"garbagecollect", no_argument,    &gc,                TRUE},
  {"help",        no_argument,       NULL,               'h'},
  {"input",       required_argument, NULL,               'i'},
/*  {"log",         no_argument,       NULL,               'l'}, */
  {"no-output",   no_argument,       &write_output,      'n'},
  {"output",      required_argument, NULL,               'o'},
  {"parse-table", required_argument, NULL,               'p'},
  {"stack",       required_argument, NULL,               'S'},
  {"statistics",  no_argument,       &show_statistics,   FALSE},
  {"verbose",     no_argument,       &verboseflag,       TRUE},
  {"version",     no_argument,       NULL,               'V'},
  {0, 0, 0, 0}
};

/*
  The actual parsing is done by the function |getopt_long|, which
  returns an option character for each option. The string declares the
  short names of the options. A colon indicates a required argument
  for an option.
*/
void handle_options (int argc, char **argv)
{
  int c; /* option character */
  verboseflag = FALSE;
  debugflag   = FALSE;
  while ((c = getopt_long(argc, argv,
                          "12?adD:ghi:lno:p:sS:vV", longopts, NULL))
         != EOF)
    switch (c) {
    case 0:   break;
    case '1': fprintf(stderr,"%s: AsFix1 output not supported currently\n", program_name);
               break;
    case '2': break;
    case '?': usage(stderr, TRUE); exit(0);
    case 'a': abbreviation_flag = TRUE; break;
    case 'D': dotoutput = optarg; generate_dot = TRUE; break;
    case 'd': debugflag = TRUE; printf("debugging %s\n", debugflag?"on":"off");
               log = open_log(".parse-log"); break;
    case 'g': gc = !gc; break;
    case 'h': usage(stdout, TRUE); exit(0);
    case 'i': input_file_name  = optarg; break;
              break;
    case 'l': suppress_lexicals = TRUE; break;
    case 'n': write_output = FALSE; break;
    case 'o': output_file_name = optarg; break;
    case 'p': parse_table_name = optarg; break;
    case 's': show_statistics = TRUE; log = open_log(".parse-log"); break;
    case 'S': show_stack = TRUE; stack_dotoutput = optarg; break;
    case 'v': verboseflag = TRUE; break;
    case 'V': fprintf(stdout, "%s %s\n", program_name, version_string);
              exit(0);
    default:  usage(stderr, FALSE); exit(1);
    }
}

/*
  \subsection{Interface Functions}

  The program provides several functions that form the interface with
  other programs. The most important functions are |open_language| for
  opening and initializing the parse table for some language,
  |parse_string| for parsing a string with one of the open parse
  tables, and |parse_file| for parsing the contents of a named file
  with one of the parse tables.

  \paragraph{The Parser Process}

  The following ToolBus script is an example of the usage of the
  interface functions.

  \input{sglr.tbtx}

  \paragraph{Termination}

  On receipt of a termination request the program exits with code 0.

*/

void rec_terminate(term *t)
{
  exit(0);
}

/*
  \paragraph{Open File}

  The function |open_file| tries to open a named file for reading and
  gives an appropriate error message if this fails.
*/
FILE *open_file(char *std_error, char *FN)
{
  FILE *file;

  if (FN == NULL || strcmp(FN, "") == 0 || strcmp(FN, "-") == 0) {
      if (std_error == NULL) return stdin;
      fprintf(stderr, "%s: %s\n", program_name, std_error);
      usage(stderr, FALSE);
      exit(1);
  } else if ((file = fopen(FN, "r")) == NULL) {
      fprintf(stderr, "%s: cannot open %s\n", program_name, FN);
      usage(stderr, FALSE);
      exit(1);
  } else
    return file;
}

/*
  \paragraph{Open Language}

  The function |open_language| initializes the parse table for language |L|
  from the file |FN|.
*/
term *open_language(char *L, char *FN)
{
  FILE *input_file;
  parse_table *table;

  if (verboseflag && FN != NULL)
    fprintf(stdout, "%s: reading parse table %s\n", program_name, FN);
  input_file = open_file("parse table not specified", FN);
  table = build_parse_table(TBreadTerm(input_file));
  if (table == NULL)
    return TBmake("snd-value(open-language-failed(%s,%s))", L, FN);
  else {
      save_parse_table(L, table);
      return TBmake("snd-value(language-opened(%s,%s))", L, FN);
  }
}

/*
   \paragraph{Parse String}

   The function |parse_string| parses the text in string |S| with the
   parse table for language |L|. The string is saved in the global
   variable |the_text|, which is accessed through the function
   |getchar_from_string|. This the function that is passed to the
   parser. The end of string character |'\0'| is converted into the
   end of file value |EOF|.
*/
static char *the_text;
int text_index;

int getchar_from_string(void)
{
  if (the_text[text_index] == '\0') return EOF;
  return the_text[text_index++];
}

/*
  Because the string passed to |parse_string| might be a string that was
  contained in a term we have to save it from being garbage collected.
  This is done now by making a duplicate of it, which is not efficient
  and clean.
*/
term *parse_string(char *L, char *S)
{
  the_text = strdup(S);
  text_index = 0;
  return TBmake("snd-value(%t)",
                parse(lookup_parse_table(L), getchar_from_string));
}
/*
   \paragraph{Parse File}

   The function |parse_file| parses the text in file |FN| with the
   parse table for language |L|.  The function |getchar_from_input|
   calls |getc|. The function is used to instantiate the buffer
   parameter function for the parser.

*/
FILE *input_file;

int getchar_from_input(void)
{
  return getc(input_file);
}

/*
  If no filename is specified (|FN| is |""|), standard input
  is used.
*/
term *parse_file(char *L, char *FN)
{
  input_file = open_file(NULL, FN);
  if (verboseflag)
    fprintf(stdout, "%s: parsing file %s\n", program_name, FN);
  return parse(lookup_parse_table(L), getchar_from_input);
}

/*
  \paragraph{Term to File}

  Opening a file for writing and writing a term to it.

*/
void term_to_file(term *t, char *FN)
{
  FILE *output_file;
  if (write_output) {
      if (strcmp(FN, "") == 0 || strcmp(FN, "-") == 0) output_file = stdout;
      else if ((output_file = fopen(FN, "w")) == NULL) {
          fprintf(stderr, "%s: cannot create %s\n", program_name, FN);
          exit(1);
      }
      if (verboseflag)
        fprintf(stdout, "%s: writing parse tree to %s\n", program_name, FN);
      TBprintf(output_file, "%t\n", t);
  }
}

/*
  \paragraph{Open Log}
*/
FILE *open_log(char *FN)
{
  FILE *fp;

  if (FN == NULL || strcmp(FN, "") == 0)
    FN = ".parse-log";
  if ((fp = fopen(FN, "w")) == NULL)
  {
    fprintf(stderr, "%s: cannot create logfile %s\n", program_name, FN);
    exit(1);
  }
  fprintf(stdout, "writing log info to %s\n", FN);
  return fp;
}
