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

/*{{{  ATerm get_area_begin_line(int cid, ATerm t) */

ATerm get_area_begin_line(int cid, ATerm t)
{
  ERR_Area area = ERR_AreaFromTerm(t);
  return ATmake("snd-value(begin-line(<int>))", ERR_getAreaBeginLine(area));
}

/*}}}  */
/*{{{  ATerm get_area_begin_column(int cid, ATerm t) */

ATerm get_area_begin_column(int cid, ATerm t)
{
  ERR_Area area = ERR_AreaFromTerm(t);
  return ATmake("snd-value(begin-column(<int>))", ERR_getAreaBeginColumn(area));
}

/*}}}  */
/*{{{  ATerm get_area_end_line(int cid, ATerm t) */

ATerm get_area_end_line(int cid, ATerm t)
{
  ERR_Area area = ERR_AreaFromTerm(t);
  return ATmake("snd-value(end-line(<int>))", ERR_getAreaEndLine(area));
}

/*}}}  */
/*{{{  ATerm get_area_end_column(int cid, ATerm t) */

ATerm get_area_end_column(int cid, ATerm t)
{
  ERR_Area area = ERR_AreaFromTerm(t);
  return ATmake("snd-value(end-column(<int>))", ERR_getAreaEndColumn(area));
}

/*}}}  */
/*{{{  ATerm get_area_offset(int cid, ATerm t) */

ATerm get_area_offset(int cid, ATerm t)
{
  ERR_Area area = ERR_AreaFromTerm(t);
  return ATmake("snd-value(offset(<int>))", ERR_getAreaOffset(area));
}

/*}}}  */
/*{{{  ATerm get_area_length(int cid, ATerm t) */

ATerm get_area_length(int cid, ATerm t)
{
  ERR_Area area = ERR_AreaFromTerm(t);
  return ATmake("snd-value(length(<int>))", ERR_getAreaLength(area));
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
/*{{{  ATerm has_location_area(int cid, ATerm t) */

ATerm has_location_area(int cid, ATerm t)
{
  ERR_Location location = ERR_LocationFromTerm(t);

  return ATmake("snd-value(has-area(<term>))",
		ATparse(ERR_hasLocationArea(location) ? "true" : "false"));
}

/*}}}  */
/*{{{  ATerm get_location_area(int cid, ATerm t) */

ATerm get_location_area(int cid, ATerm t)
{
  ERR_Location location = ERR_LocationFromTerm(t);
  if (ERR_hasLocationArea(location)) {
    ERR_Area area = ERR_getLocationArea(location);

    return ATmake("snd-value(area(<term>))", area);
  }

  ATabort("error-support.c: no area: %t, use has_location_area\n", location);
  return NULL;
}

/*}}}  */

/*{{{  ATerm get_subject_description(int cid, ATerm t) */

ATerm get_subject_description(int cid, ATerm t)
{
  ERR_Subject subject = ERR_SubjectFromTerm(t);
  const char *description = ERR_getSubjectDescription(subject);

  return ATmake("snd-value(description(<str>))", description);
}

/*}}}  */
/*{{{  ATerm has_subject_location(int cid, ATerm t) */

ATerm has_subject_location(int cid, ATerm t)
{
  ERR_Subject subject = ERR_SubjectFromTerm(t);

  return ATmake("snd-value(has-location(<term>))",
		ATparse(ERR_hasSubjectLocation(subject) ? "true" : "false"));
}

/*}}}  */
/*{{{  ATerm get_subject_location(int cid, ATerm t) */

ATerm get_subject_location(int cid, ATerm t)
{
  ERR_Subject subject = ERR_SubjectFromTerm(t);
  if (ERR_hasSubjectLocation(subject)) {
    ERR_Location location = ERR_getSubjectLocation(subject);
    
    return ATmake("snd-value(location(<term>))", location);
  }

  ATabort("error-support.c: no location: %t, use has_subject_location\n", subject);
  return NULL;
}

/*}}}  */

/*{{{  ATerm get_error_description(int cid, ATerm t) */

ATerm get_error_description(int cid, ATerm t)
{
  ERR_Error error = ERR_ErrorFromTerm(t);
  return ATmake("snd-value(description(<str>)", ERR_getErrorDescription(error));
}

/*}}}  */
/*{{{  ATerm get_error_subjects(int cid, ATerm t) */

ATerm get_error_subjects(int cid, ATerm t)
{
  ERR_Error error = ERR_ErrorFromTerm(t);
  return ATmake("snd-value(subjects(<term>))", ERR_getErrorList(error));
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

  return ATmake("snd-value(errors(<term>))", ERR_getSummaryList(summary));
}

/*}}}  */

/*{{{  ATerm lower_summary(int cid, ATerm t) */

ATerm lower_summary(int cid, ATerm t)
{
  PERR_Start startSummary = PERR_StartFromTerm(ATBunpack(t));

  if (PERR_isStartSummary(startSummary)) {
    PERR_Summary pSummary = PERR_getStartTopSummary(startSummary);
    t = ERR_SummaryToTerm(PERR_lowerSummary(pSummary));
  }

  return ATmake("snd-value(lowered-summary(<term>))", t);
}

/*}}}  */
/*{{{  void display_summary(int cid, ATerm summary) */

void display_summary(int cid, ATerm summary)
{
  ERR_displaySummary(ERR_SummaryFromTerm(summary));
}

/*}}}  */
/*{{{  ATerm add_filename_in_error(int cid, const char *filename, ATerm t) */

ATerm add_filename_in_error(int cid, const char *filename, ATerm t)
{
  ERR_Error error = ERR_ErrorFromTerm(t);
  ERR_SubjectList result = ERR_makeSubjectListEmpty();
  ERR_SubjectList subjects = ERR_getErrorList(error);

  while (!ERR_isSubjectListEmpty(subjects)) {
    ERR_Subject subject = ERR_getSubjectListHead(subjects);
    ERR_Location location;
    if (ERR_isSubjectLocalized(subject)) {
      location = ERR_getSubjectLocation(subject);
      ERR_Area area = ERR_getLocationArea(location);
      location = ERR_makeLocationAreaInFile(filename, area);
      subject = ERR_setSubjectLocation(subject, location);
    }
    else {
      char *description = ERR_getSubjectDescription(subject);
      location = ERR_makeLocationFile(filename);
      subject = ERR_makeSubjectLocalized(description, location);
    }
    result = ERR_makeSubjectListMany(subject, result);
    subjects = ERR_getSubjectListTail(subjects);
  }

  error = ERR_setErrorList(error, ERR_reverseSubjectList(result));

  return ATmake("snd-value(error(<term>))", ERR_ErrorToTerm(error));
}

/*}}}  */
/*{{{  ATerm make_summary(int conn, const char *producer, const char *id, ATerm error) */

ATerm make_summary(int conn, const char *producer, const char *id, ATerm errors)
{
  ERR_ErrorList errorList = ERR_ErrorListFromTerm(errors);
  ERR_Summary summary = ERR_makeSummarySummary(producer, id, errorList);

  return ATmake("snd-value(summary(<term>))", summary);
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
