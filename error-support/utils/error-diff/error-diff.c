/*
 * $Id$
 */

/*{{{  standard includes */

#include <stdio.h>
#include <unistd.h>
#include <ErrorAPI-utils.h>

#include <aterm2.h>

/*}}}  */

/*{{{  globals */

static char myname[]    = "error-diff";
static char myversion[] = "1.0";
static char myarguments[] = "h1:2:V";

/*}}}  */

/*{{{  void usage(void) */

void usage(void)
{
    fprintf(stderr,
        "Usage: %s <file1> <file2>\n"
        "Options:\n"
        "\t-h              display help information (usage)\n"
        "\t-V              reveal program version (i.e. %s)\n",
        myname, myversion);
}

/*}}}  */

static ATbool ERR_subjectDiff(ERR_Subject subject1, 
                             ERR_Subject subject2)
{
  char *description1 = ERR_getSubjectDescription(subject1);
  char *description2 = ERR_getSubjectDescription(subject2);
  if (strcmp(description1, description2) == 0) {
    ERR_Location location1 = ERR_getSubjectLocation(subject1);
    ERR_Location location2 = ERR_getSubjectLocation(subject2);

    ERR_Area area1 = ERR_getLocationArea(location1);
    ERR_Area area2 = ERR_getLocationArea(location2);

    return ERR_isEqualArea(area1, area2);
  }
  return ATfalse;
}

static ATbool ERR_subjectListDiff(ERR_SubjectList subjectlist1, 
                                  ERR_SubjectList subjectlist2)
{
  if (ERR_isSubjectListEmpty(subjectlist1) &&
      ERR_isSubjectListEmpty(subjectlist2)) {
    return ATtrue;
  }
  else if (!ERR_isSubjectListEmpty(subjectlist1) &&
           !ERR_isSubjectListEmpty(subjectlist2)) {
    ERR_Subject subject1 = ERR_getSubjectListHead(subjectlist1);
    ERR_Subject subject2 = ERR_getSubjectListHead(subjectlist2);

    if (ERR_subjectDiff(subject1, subject2)) {
      subjectlist1 = ERR_getSubjectListTail(subjectlist1);
      subjectlist2 = ERR_getSubjectListTail(subjectlist2);
      
      return ERR_subjectListDiff(subjectlist1, subjectlist2);
    }
  }
  return ATfalse;
}

static ATbool ERR_feedbackDiff(ERR_Feedback feedback1, 
                               ERR_Feedback feedback2)
{
  char *description1 = ERR_getFeedbackDescription(feedback1);
  char *description2 = ERR_getFeedbackDescription(feedback2);

  ERR_SubjectList subjectlist1 = ERR_getFeedbackList(feedback1);
  ERR_SubjectList subjectlist2 = ERR_getFeedbackList(feedback2);

  if (ERR_isFeedbackInfo(feedback1) &&
      ERR_isFeedbackInfo(feedback2)) {
    if (strcmp(description1, description2) == 0) {
      return ERR_subjectListDiff(subjectlist1, subjectlist2);
    }
  }
  else if (ERR_isFeedbackWarning(feedback1) &&
           ERR_isFeedbackWarning(feedback2)) {
    if (strcmp(description1, description2) == 0) {
      return ERR_subjectListDiff(subjectlist1, subjectlist2);
    }
  }
  else if (ERR_isFeedbackError(feedback1) &&
           ERR_isFeedbackError(feedback2)) {
    if (strcmp(description1, description2) == 0) {
      return ERR_subjectListDiff(subjectlist1, subjectlist2);
    }
  }
  else if (ERR_isFeedbackFatalError(feedback1) &&
           ERR_isFeedbackFatalError(feedback2)) {
    if (strcmp(description1, description2) == 0) {
      return ERR_subjectListDiff(subjectlist1, subjectlist2);
    }
  }
  return ATfalse;
}

static ATbool ERR_feedbackListDiff(ERR_FeedbackList feedbacklist1, 
                                ERR_FeedbackList feedbacklist2)
{
  if (ERR_isFeedbackListEmpty(feedbacklist1) &&
      ERR_isFeedbackListEmpty(feedbacklist2)) {
    return ATtrue;
  }
  else if (!ERR_isFeedbackListEmpty(feedbacklist1) &&
           !ERR_isFeedbackListEmpty(feedbacklist2)) {
    ERR_Feedback feedback1 = ERR_getFeedbackListHead(feedbacklist1);
    ERR_Feedback feedback2 = ERR_getFeedbackListHead(feedbacklist2);

    if (ERR_feedbackDiff(feedback1, feedback2)) {
      feedbacklist1 = ERR_getFeedbackListTail(feedbacklist1);
      feedbacklist2 = ERR_getFeedbackListTail(feedbacklist2);
      
      return ERR_feedbackListDiff(feedbacklist1, feedbacklist2);
    }
  }
  return ATfalse;
}

static ATbool ERR_summaryDiff(ERR_Summary sum1, ERR_Summary sum2)
{
  char *producer1 = ERR_getSummaryProducer(sum1);
  char *producer2 = ERR_getSummaryProducer(sum2);

  if (strcmp(producer1, producer2) == 0) {
    ERR_FeedbackList feedbacklist1 = ERR_getSummaryList(sum1);
    ERR_FeedbackList feedbacklist2 = ERR_getSummaryList(sum2);
    return ERR_feedbackListDiff(feedbacklist1, feedbacklist2);
  }
  return ATfalse;
}

/*{{{  int main (int argc, char **argv) */

int main (int argc, char **argv)
{
  int c;
  ATerm bottomOfStack;
  ATerm input1 = NULL;
  ATerm input2 = NULL;
  char   *input_file_name1 = "-";
  char   *input_file_name2 = "-";

  while ((c = getopt(argc, argv, myarguments)) != EOF)
    switch (c) {
      case 'h':  usage();                      exit(0);
      case '1':  input_file_name1 = optarg;    break;
      case '2':  input_file_name2 = optarg;    break;
      case 'V':  fprintf(stderr, "%s %s\n", myname, myversion);
                                               exit(0);
      default :  usage();                      exit(1);
  }

  ATinit(argc, argv, &bottomOfStack);
  ERR_initErrorApi();

  
  input1 = ATreadFromNamedFile(input_file_name1);
  input2 = ATreadFromNamedFile(input_file_name2);

  if (ERR_summaryDiff(ERR_SummaryFromTerm(input1), 
                      ERR_SummaryFromTerm(input2))) {
    return 0;
  }
  else {
    return 1;
  }
}
