#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <aterm2.h>

#include <Error-utils.h>

static char myname[] = "display-error";
static char myversion[] = "1.0";
static char myarguments[] = "hi:o:V";

void usage(void) {
  fprintf(stderr,
      "This tool displays errors\n"
      "Usage: %s -h -i arg -o arg -V . . .\n"
      "Options:\n"
      "\t-h              displays help information (usage)\n"
      "\t-i filename     input from file (default stdin)\n"
      "\t-o filename     output to file (default stderr)\n"
      "\t-V              reveal program version (i.e. %s)\n",
      myname, myversion);
}

void version(void) {
  fprintf(stderr, "%s v%s\n", myname, myversion);
}

void display_summary(int cid, ATerm summary) {
  ERR_displaySummary(ERR_SummaryFromTerm(summary));
}

int main(int argc, char *argv[]) {
  int c;
  ATerm bottomOfStack;
  ATerm input = NULL;
  FILE *output = stderr;
  char *input_file_name = "-";
  char *output_file_name = "-";

  ATinit(argc, argv, &bottomOfStack);
  ERR_initErrorApi();

  while((c = getopt(argc, argv, myarguments)) != EOF)
    switch(c) {
      case 'h':  usage();                     exit(0);
      case 'i':  input_file_name  = optarg;   break;
      case 'o':  output_file_name  = optarg;  break;
      case 'V':  fprintf(stderr, "%s %s\n", myname, myversion);
		 exit(0);
      default :  usage();                     exit(1);
    }

  input = ATreadFromNamedFile(input_file_name);

  if (input == NULL) {
    ATerror("%s: could not read term from input file %s\n",
	    myname, input_file_name);
    return 1;
  }

  if (strcmp(output_file_name, "-")) {
    output = fopen(output_file_name, "wb");
  }

  if (output != NULL) {
    ERR_Summary summary = ERR_SummaryFromTerm(input);
    ERR_fdisplaySummary(output, summary);
    fclose(output);
    
    int num_errors, num_warnings, num_infos, num_fatal;
    ERR_countErrors(summary, &num_errors, &num_warnings, &num_infos, &num_fatal);

    if (num_errors + num_fatal > 0) {
      return 1;
    }
  } 
  else {
    fprintf(stderr, "%s: could not open file %s\n", myname, output_file_name);
    return 1;
  }

  return 0;    
}
