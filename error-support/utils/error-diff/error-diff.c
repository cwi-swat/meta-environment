/* $Id$ */

/*{{{  includes */

#include <stdio.h>
#include <unistd.h>
#include <assert.h>

#include <aterm2.h>

#include <Error-utils.h>

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
        "Usage: %s -1 <file1> -2 <file2>\n"
        "Options:\n"
        "\t-h              display help information (usage)\n"
        "\t-V              reveal program version (i.e. %s)\n",
        myname, myversion);
}

/*}}}  */

/*{{{  static ATbool ERR_subjectEqual(ERR_Subject subject1, ERR_Subject subject2) */

static ATbool ERR_subjectEqual(ERR_Subject subject1, ERR_Subject subject2)
{
  char *description1 = ERR_getSubjectDescription(subject1);
  char *description2 = ERR_getSubjectDescription(subject2);

  if (strcmp(description1, description2) == 0) {
    ERR_Location location1 = ERR_getSubjectLocation(subject1);
    ERR_Location location2 = ERR_getSubjectLocation(subject2);

    if (ERR_isLocationAreaInFile(location1) &&
	ERR_isLocationAreaInFile(location2)) {
      ERR_Area area1 = ERR_getLocationArea(location1);
      ERR_Area area2 = ERR_getLocationArea(location2);

      return ERR_isEqualArea(area1, area2);
    }
    else if (ERR_isLocationArea(location1) &&
	ERR_isLocationArea(location2)) {
      ERR_Area area1 = ERR_getLocationArea(location1);
      ERR_Area area2 = ERR_getLocationArea(location2);

      return ERR_isEqualArea(area1, area2);
    }
    else if (ERR_isLocationFile(location1) &&
	     ERR_isLocationFile(location2)) {
      return ATtrue;
    }
  }
  return ATfalse;
}

/*}}}  */
/*{{{  static ATbool ERR_subjectListEqual(ERR_SubjectList subjectlist1,  */

static ATbool ERR_subjectListEqual(ERR_SubjectList subjectlist1, 
                                   ERR_SubjectList subjectlist2)
{
  if (ERR_isSubjectListEmpty(subjectlist1)
      && ERR_isSubjectListEmpty(subjectlist2)) {
    return ATtrue;
  }
  else if (!ERR_isSubjectListEmpty(subjectlist1)
	   && !ERR_isSubjectListEmpty(subjectlist2)) {
    ERR_Subject subject1 = ERR_getSubjectListHead(subjectlist1);
    ERR_Subject subject2 = ERR_getSubjectListHead(subjectlist2);

    if (ERR_subjectEqual(subject1, subject2)) {
      subjectlist1 = ERR_getSubjectListTail(subjectlist1);
      subjectlist2 = ERR_getSubjectListTail(subjectlist2);
      
      return ERR_subjectListEqual(subjectlist1, subjectlist2);
    }
  }
  return ATfalse;
}

/*}}}  */
/*{{{  static ATbool ERR_errorEqual(ERR_Error error1, ERR_Error error2) */

static ATbool ERR_errorEqual(ERR_Error error1, ERR_Error error2)
{
  char *description1 = ERR_getErrorDescription(error1);
  char *description2 = ERR_getErrorDescription(error2);

  ERR_SubjectList subjectlist1 = ERR_getErrorList(error1);
  ERR_SubjectList subjectlist2 = ERR_getErrorList(error2);

  if (ERR_isErrorInfo(error1)
      && ERR_isErrorInfo(error2)) {
    if (strcmp(description1, description2) == 0) {
      return ERR_subjectListEqual(subjectlist1, subjectlist2);
    }
  }
  else if (ERR_isErrorWarning(error1)
	   && ERR_isErrorWarning(error2)) {
    if (strcmp(description1, description2) == 0) {
      return ERR_subjectListEqual(subjectlist1, subjectlist2);
    }
  }
  else if (ERR_isErrorError(error1)
	   && ERR_isErrorError(error2)) {
    if (strcmp(description1, description2) == 0) {
      return ERR_subjectListEqual(subjectlist1, subjectlist2);
    }
  }
  else if (ERR_isErrorFatal(error1)
	   && ERR_isErrorFatal(error2)) {
    if (strcmp(description1, description2) == 0) {
      return ERR_subjectListEqual(subjectlist1, subjectlist2);
    }
  }
  return ATfalse;
}

/*}}}  */

/*{{{  int main (int argc, char *argv[]) */

int main (int argc, char *argv[])
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
  initErrorApi();

  
  input1 = ATreadFromNamedFile(input_file_name1);
  if (input1 == NULL) {
	ATwarning("%s: no input files given\n", myname);
        usage();
	exit(1);
  }

  input2 = ATreadFromNamedFile(input_file_name2);
  if (input2 == NULL) {
	ATwarning("%s: no second input file given\n", myname);
        usage();
	exit(1);
  }

  if (ERR_errorEqual(ERR_ErrorFromTerm(input1), ERR_ErrorFromTerm(input2))) {
    return 0;
  }
  else {
    return 1;
  }
}

/*}}}  */
