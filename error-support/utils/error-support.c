/*{{{  includes */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <aterm2.h>
#include "ErrorAPI-utils.h"

#ifndef WITHOUT_TOOLBUS
#include "error-support.tif.h"
#endif

/*}}}  */
/*{{{  variables */

static char myname[] = "error-support";
static char myversion[] = "1.0";
static char myarguments[] = "hi:o:vV";

/*}}}  */

/*{{{  void usage(void) */

void usage(void)
{
  fprintf(stderr,
          "Yields the string that the input parse tree derives, \n"
          "including each an every whitespace character.\n"
          "This is *not* a pretty-printer, just an unparser.\n\n"
          "Usage: %s [%s]\n"
          "Options:\n"
          "\t-h              display help information (usage)\n"
          "\t-i filename     input from file (default stdin)\n"
          "\t-o filename     output to file (default stdout)\n"
          "\t-v              verbose mode\n"
          "\t-V              reveal program version (i.e. %s)\n",
          myname, myarguments, myversion);
}

/*}}}  */
/*{{{  void version(void) */

void version(void)
{
  fprintf(stderr, "%s v%s\n", myname, myversion);
}

/*}}}  */

/*{{{  void rec_terminate(int cid, ATerm t) */

void rec_terminate(int cid, ATerm t)
{
  exit(0);
}

/*}}}  */

/*{{{  ATerm convert_feedback(int cid, ATerm t) */

ATerm convert_feedback(int cid, ATerm t)
{
  PERR_Start startSummary = PERR_StartFromTerm(t);

  if (PERR_isStartSummary(startSummary)) {
    PERR_Summary pSummary = PERR_getStartTopSummary(startSummary);

    return ATmake("snd-value(new-feedback(<term>))", 
		  ERR_SummaryToTerm(PERR_lowerSummary(pSummary)));
  }
  else {
    return ATmake("snd-value(new-feedback(<term>))", t);
  }
}

/*}}}  */

/*{{{  ATerm get_feedback_producer(int cid, ATerm t) */

ATerm get_feedback_producer(int cid, ATerm t)
{
  ERR_Summary summary = ERR_SummaryFromTerm(t);

  return ATmake("snd-value(producer(<str>))", ERR_getSummaryProducer(summary));
}

/*}}}  */
/*{{{  ATerm get_feedback_identification(int cid, ATerm t) */

ATerm get_feedback_identification(int cid, ATerm t)
{
  ERR_Summary summary = ERR_SummaryFromTerm(t);

  return ATmake("snd-value(identification(<str>))", ERR_getSummaryId(summary));
}

/*}}}  */
/*{{{  ATerm get_feedback_subjects(int cid, ATerm t) */

ATerm get_feedback_subjects(int cid, ATerm t)
{
  ERR_Summary summary = ERR_SummaryFromTerm(t);

  return ATmake("snd-value(subjects(<term>))", ERR_FeedbackListToTerm(
						ERR_getSummaryList(summary)));
}

/*}}}  */
/*{{{  ATerm calc_error_location(int cid, ATerm focus, ATerm error) */

ATerm get_first_error_location(int cid, ATerm error)
{
  ERR_Summary summary = ERR_SummaryFromTerm(error);
  ERR_FeedbackList feedbacks = ERR_getSummaryList(summary);
  ERR_Feedback feedback = ERR_getFeedbackListHead(feedbacks);
  ERR_SubjectList subjects = ERR_getFeedbackList(feedback);
  ERR_Subject subject = ERR_getSubjectListHead(subjects);
  ERR_Location location = ERR_getSubjectLocation(subject);

  return ATmake("snd-value(error-location(<term>))",
                ERR_LocationToTerm(location));
}

/*}}}  */
/*{{{  ATerm calc_error_location(int cid, ATerm focus, ATerm error) */

ATerm get_first_error_description(int cid, ATerm error)
{
  ERR_Summary summary = ERR_SummaryFromTerm(error);
  ERR_FeedbackList feedbacks = ERR_getSummaryList(summary);
  ERR_Feedback feedback = ERR_getFeedbackListHead(feedbacks);
  ERR_SubjectList subjects = ERR_getFeedbackList(feedback);
  ERR_Subject subject = ERR_getSubjectListHead(subjects);
  char *description = ERR_getSubjectDescription(subject);

  return ATmake("snd-value(error-description(<str>))", description);
}

/*}}}  */

void display_feedback(int cid, ATerm summary)
{
  ERR_displayFeedback(ERR_SummaryFromTerm(summary));
}


/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  int c;
  ATerm bottomOfStack;

  /*  Configuration items  */
  char   *inputName = "-";
  char   *outputName = "-";
  FILE *outputFile = NULL;
  ATbool proceed = ATtrue;
  ATbool verbose = ATfalse;
#ifndef WITHOUT_TOOLBUS
  ATbool use_toolbus = ATfalse;
  int i;

  for (i=1; !use_toolbus && i < argc; i++) {
    use_toolbus = !strcmp(argv[i], "-TB_TOOL_NAME");
  }

  if (use_toolbus) {
    int cid;
    ATBinit(argc, argv, &bottomOfStack);
    ERR_initErrorAPIApi();
    PERR_initParsedErrorAPIApi();
    cid = ATBconnect(NULL, NULL, -1, error_support_handler);
    ATBeventloop();
  }
  else
#endif

  {
    extern char *optarg;
    extern int   optind;

    while ((c = getopt(argc, argv, myarguments)) != -1) {
      switch (c) {
        case 'i':
          inputName = optarg;
          break;
        case 'o':
          outputName = optarg;
          break;
        case 'v':
          verbose = ATtrue;
          break;
        case 'V':
          version();
          proceed = ATfalse;
          break;
        case 'h': /* fallthrough intended */
        default:
          usage();
          proceed = ATfalse;
          break;
      }
    }
    argc -= optind;
    argv += optind;

    ATinit(argc, argv, &bottomOfStack);
    ERR_initErrorAPIApi();
    PERR_initParsedErrorAPIApi();

    if (proceed) {
      ATerm term;

      if (!strcmp(outputName, "") || !strcmp(outputName, "-")) {
        outputFile = stdout;
      }
      else if (!(outputFile = fopen(outputName, "wb"))) {
        ATerror("%s: cannot open %s for writing\n", myname, outputName);
      }

      term = ATreadFromNamedFile(inputName);
      if (term == NULL) {
        ATerror("%s: parse error in input term.\n", myname);
      }
      else {
        ERR_Feedback feedback = PERR_lowerFeedback(PERR_FeedbackFromTerm(term));
        ATfprintf(outputFile, "%t", feedback);
        fclose(outputFile);
     }
    }
  }

  return 0;
}

/*}}}  */
