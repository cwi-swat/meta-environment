/*
 * $Id$
 */

/*{{{  standard includes */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/*}}}  */
/*{{{  meta includes */

#include <aterm2.h>
#include <MEPT-utils.h>
#include <ErrorAPI-utils.h>


/*}}}  */
/*{{{  globals */

static char myname[]    = "ambtracker";
static char myversion[] = "2.0";
static char myarguments[] = "ahi:o:V";

/*}}}  */

/*{{{  void usage(void) */

void usage(void)
{
    fprintf(stderr,
        "Usage: %s -ah -i arg -o arg -V . . .\n"
        "Options:\n"
        "\t-a              output in ATerm format\n"
        "\t-h              display help information (usage)\n"
        "\t-i filename     input from file (default stdin)\n"
        "\t-o filename     output to file (default stdout)\n"
        "\t-V              reveal program version (i.e. %s)\n",
        myname, myversion);
}

/*}}}  */

/*{{{  ATerm deslash(ATerm atstr) */

static char* deslash(ATerm atstr)
{
  char *tmp, *str = NULL;
  int i, length, found;

  if(ATmatch(atstr,"<str>", &tmp)) {
    str = strdup(tmp);
    length = strlen(str);

    /* copy string without slashes and quotes, 
     * including the EOS character
     */
    for(found = 0, i = 0; i <= length; i++) {
      switch(str[i]) {
	case '\\':
	  found++;
	  break;
	default:
	    str[i - found] = str[i];
	 break; 
      }	  
    }  
  }

  return str;
}

/*}}}  */

/*{{{  static void prettyPrint(ATerm t, FILE *fp) */

static void prettyPrint(ATerm t, FILE *fp)
{
  int count;
  int i;
  ERR_Feedback feedback = ERR_FeedbackFromTerm(t);

  if (ERR_isFeedbackError(feedback)) {
    ERR_SubjectList subjects = ERR_getFeedbackList(feedback);
    if (ERR_isSubjectListEmpty(subjects)) {
      ATfprintf(fp,"No ambiguities\n");
    }
    else {
      count = ERR_getSubjectListLength(subjects);
      ATfprintf(fp, "%d ambiguity cluster%s:\n\n",count,count > 1 ? "s" : "");
      
      for (i = 1;!ERR_isSubjectListEmpty(subjects); subjects = ERR_getSubjectListTail(subjects), i++) {
	ERR_Subject subject = ERR_getSubjectListHead(subjects);
        ERR_Location location = ERR_getSubjectLocation(subject);
        ERR_Area area = ERR_getLocationArea(location);
        int line = ERR_getAreaBeginLine(area);
        int col = ERR_getAreaBeginColumn(area);
/*
	ATermList productions;
*/

	ATfprintf(fp,"[%d/%d] at (%d:%d):\n", i, count, line, col);
/*
	  for(;!ATisEmpty(productions); productions = ATgetNext(productions)) {
	    char *str = deslash(ATgetFirst(productions));
	    ATfprintf(fp,"  %s\n", str);
	    free(str);
	  }
*/

        ATfprintf(fp,"\n");
      }
    }
  }
  else {
    ATerror("%s: Unexpected term: %t\n", myname,t);
    return;
  }
}

/*}}}  */

/*{{{  int main (int argc, char **argv) */

int main (int argc, char **argv)
{
  int c; 
  ATerm bottomOfStack;
  PT_ParseTree parsetree;
  ATerm ambiguities;
  ATbool atermformat = ATfalse;
  char   *input_file_name  = "-";
  char   *output_file_name = "-";
  
  while ((c = getopt(argc, argv, myarguments)) != EOF)
    switch (c) {
      case 'a':  atermformat = ATtrue;         break;
      case 'h':  usage();                      exit(0);
      case 'i':  input_file_name  = optarg;    break;
      case 'o':  output_file_name = optarg;    break;
      case 'V':  fprintf(stderr, "%s %s\n", myname, myversion);
                                               exit(0);
      default :  usage();                      exit(1);
  }

  ATinit(argc, argv, &bottomOfStack);    /* Initialize Aterm library */
  ERR_initErrorApi();
  PT_initMEPTApi();

  parsetree = PT_ParseTreeFromTerm(ATreadFromNamedFile(input_file_name));

  if(parsetree == NULL) {
    ATerror("%s: could not read term from input file %s\n", 
	    myname, input_file_name);
  }

  ambiguities = PT_reportParseTreeAmbiguities("Unknown", parsetree);

  if(!atermformat) {
    FILE *fp = NULL;

    if(!strcmp(output_file_name, "") || !strcmp(output_file_name,"-")) {
      fp = stdout;
    } else if(!(fp = fopen(output_file_name, "wb"))) {
      ATerror("%s: could not open %s for output.\n", myname, output_file_name);
      return 1;
    }

    prettyPrint(ambiguities,fp);

    fclose(fp);
  } else {
    ATwriteToNamedTextFile(ambiguities, output_file_name);
  }

  return 0;
}

/*}}}  */
