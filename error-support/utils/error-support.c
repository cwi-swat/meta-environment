/*{{{  includes */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <aterm2.h>

#include <Error-utils.h>

#include "error-support.tif.h"

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

/*{{{  ATerm lower_summary(int cid, ATerm t) */

ATerm lower_summary(int cid, ATerm t)
{
  PERR_Start startSummary = PERR_StartFromTerm(t);

  if (PERR_isStartSummary(startSummary)) {
    PERR_Summary pSummary = PERR_getStartTopSummary(startSummary);
    t = ERR_SummaryToTerm(PERR_lowerSummary(pSummary));
  }

  return ATmake("snd-value(lowered-summary(<term>))", t);
}

/*}}}  */

/*{{{  ATerm get_summary_producer(int cid, ATerm t) */

ATerm get_summary_producer(int cid, ATerm t)
{
  ERR_Summary summary = ERR_SummaryFromTerm(t);

  return ATmake("snd-value(producer(<str>))", ERR_getSummaryProducer(summary));
}

/*}}}  */
/*{{{  ATerm get_summary_id(int cid, ATerm t) */

ATerm get_summary_id(int cid, ATerm t)
{
  ERR_Summary summary = ERR_SummaryFromTerm(t);

  return ATmake("snd-value(id(<str>))", ERR_getSummaryId(summary));
}

/*}}}  */
/*{{{  ATerm get_summary_errors(int cid, ATerm t) */

ATerm get_summary_errors(int cid, ATerm t)
{
  ERR_Summary summary = ERR_SummaryFromTerm(t);

  return ATmake("snd-value(errors(<term>))",
		ERR_ErrorListToTerm(ERR_getSummaryList(summary)));
}

/*}}}  */
/*{{{  ATerm get_summary_first_error(int cid, ATerm t) */

ATerm get_summary_first_error(int cid, ATerm t)
{
  ERR_Summary summary = ERR_SummaryFromTerm(t);
  ERR_ErrorList errors = ERR_getSummaryList(summary);
  ERR_Error error = ERR_getErrorListHead(errors);

  return ATmake("snd-value(error(<term>))", ERR_ErrorToTerm(error));

}

/*}}}  */

/*{{{  ATerm get_error_first_subject_location(int cid, ATerm t) */

ATerm get_error_first_subject_location(int cid, ATerm t)
{
  ERR_Error error = ERR_ErrorFromTerm(t);
  ERR_SubjectList subjects = ERR_getErrorList(error);
  ERR_Subject subject = ERR_getSubjectListHead(subjects);

  if (ERR_hasSubjectLocation(subject)) {
    ERR_Location location = ERR_getSubjectLocation(subject);

    return ATmake("snd-value(location(<term>))", ERR_LocationToTerm(location));
  }

  ATabort("error-support.c:get_error_first_subject_location: no location!\n");
  return NULL;
}

/*}}}  */

/*{{{  ATerm get_location_filename(int cid, ATerm t) */

ATerm get_location_filename(int cid, ATerm t)
{
  ERR_Location location = ERR_LocationFromTerm(t);
  const char *filename = ERR_getLocationFilename(location);

  return ATmake("snd-value(filename(<str>))", filename);
}

/*}}}  */
/*{{{  ATerm get_location_area_offset(int cid, ATerm t) */

ATerm get_location_area_offset(int cid, ATerm t)
{
  ERR_Location location = ERR_LocationFromTerm(t);
  if (ERR_hasLocationArea(location)) {
    ERR_Area area = ERR_getLocationArea(location);
    int offset = ERR_getAreaOffset(area);

    return ATmake("snd-value(offset(<int>))", offset);
  }

  return ATmake("snd-value(no-offset)");
}

/*}}}  */

/*{{{  void display_summary(int cid, ATerm summary) */

void display_summary(int cid, ATerm summary)
{
  ERR_displaySummary(ERR_SummaryFromTerm(summary));
}

/*}}}  */

/*{{{  int main(int argc, char *argv[]) */

int main(int argc, char *argv[])
{
  int c;
  ATerm bottomOfStack;
  char *inputName = "-";
  char *outputName = "-";
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
    initErrorApi();
    cid = ATBconnect(NULL, NULL, -1, error_support_handler);
    ATBeventloop();
  }
  else
#endif

  {
    extern char *optarg;
    extern int optind;

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
    initErrorApi();

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
        ERR_Error error = PERR_lowerError(PERR_ErrorFromTerm(term));
        ATfprintf(outputFile, "%t", error);
        fclose(outputFile);
     }
    }
  }

  return 0;
}

/*}}}  */
