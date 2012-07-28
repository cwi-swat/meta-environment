/* $Id$ */


#include <stdio.h>
#include <unistd.h>
#include <assert.h>

#include <aterm2.h>

#include <Error-utils.h>

static char myname[]    = "error-diff";
static char myversion[] = "1.0";
static char myarguments[] = "hV";

void usage(void) {
    fprintf(stderr,
	"Info:  Compares two error summaries, ignoring specific path names\n"
        "Usage: %s [<options>] <file1> <file2>\n"
        "Options:\n"
        "\t-h              display help information (usage)\n"
        "\t-V              reveal program version (i.e. %s)\n",
        myname, myversion);
}

static ATbool ERR_subjectEqual(ERR_Subject subject1, ERR_Subject subject2) {
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

static ATbool ERR_subjectListEqual(ERR_SubjectList subjectlist1, ERR_SubjectList subjectlist2) {
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

static ATbool ERR_errorEqual(ERR_Error error1, ERR_Error error2) {
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

static ATbool ERR_ErrorListEqual(ERR_ErrorList list1, ERR_ErrorList list2) {

	while (!ERR_isErrorListEmpty(list1) && !ERR_isErrorListEmpty(list2)) {
		ERR_Error head1 = ERR_getErrorListHead(list1);
		ERR_Error head2 = ERR_getErrorListHead(list2);

		if (!ERR_errorEqual(head1, head2)) {
			return ATfalse;
		}

		list1 = ERR_getErrorListTail(list1);
		list2 = ERR_getErrorListTail(list2);
	}

	return ERR_isErrorListEmpty(list1) && ERR_isErrorListEmpty(list2);
}

static ATbool ERR_summaryEqual(ERR_Summary summary1, ERR_Summary summary2) {
	char *id1 = ERR_getSummaryId(summary1);
	char *id2 = ERR_getSummaryId(summary2);
	char *producer1 = ERR_getSummaryProducer(summary1);
	char *producer2 = ERR_getSummaryProducer(summary2);
	ERR_ErrorList list1 = ERR_getSummaryList(summary1);
	ERR_ErrorList list2 = ERR_getSummaryList(summary2);

	if (strcmp(id1, id2)) {
		return ATfalse;
	}
	else if (strcmp(producer1, producer2)) {
		return ATfalse;
	}
	else if (!ERR_ErrorListEqual(list1, list2)) {
		return ATfalse;
	}

	return ATtrue;
}

static ATbool isTermSummary(ATerm term) {
  AFun fun;

  if (term == NULL) {
    return ATfalse;
  }

  if (ATgetType(term) != AT_APPL) {
    return ATfalse;
  }

  fun = ATgetAFun((ATermAppl) term);

  if (strcmp(ATgetName(fun), "summary")) {
    return ATfalse;
  }

  return ATtrue;
}

static ATbool isTermError(ATerm term) {
  AFun fun;

  if (term == NULL) {
    return ATfalse;
  }

  if (ATgetType(term) != AT_APPL) {
    return ATfalse;
  }

  fun = ATgetAFun((ATermAppl) term);

  if (strcmp(ATgetName(fun), "error") &&
      strcmp(ATgetName(fun), "warning")) {
    return ATfalse;
  }

  return ATtrue;
}

int main (int argc, char *argv[]) {
  int c;
  ATerm bottomOfStack;
  ATerm input1 = NULL;
  ATerm input2 = NULL;
  char   *input_file_names[2] = { "-", "-" };

  while ((c = getopt(argc, argv, myarguments)) != EOF) {
    switch (c) {
      case 'h':  usage();                      exit(0);
      case 'V':  fprintf(stderr, "%s %s\n", myname, myversion);
                                               exit(0);
      default :  break;
    }
  }

  if (optind < argc) {
	  input_file_names[0] = argv[optind];
	  input_file_names[1] = argv[optind+1];
  }
  else {
	  ATwarning("%s: need exactly two input files\n", myname);
	  usage();
	  exit(1);
  }

  ATinit(argc, argv, &bottomOfStack);
  initErrorApi();

  input1 = ATreadFromNamedFile(input_file_names[0]);
  input2 = ATreadFromNamedFile(input_file_names[1]);

  if (!isTermSummary(input1) || !isTermSummary(input2)) {
    if (!isTermError(input1) || !isTermError(input2)) {
      ATwarning("%s: please provide two Summaries or two Errors, "
		"and nothing else\n", myname);
      usage();
      exit(1);
    }
    else {
      if (ERR_errorEqual(ERR_ErrorFromTerm(input1), 
			 ERR_ErrorFromTerm(input2))) {
	return 0;
      }
      else {
	return 1;
      }
    }
  }
  else {
    if (ERR_summaryEqual(ERR_SummaryFromTerm(input1), 
			 ERR_SummaryFromTerm(input2))) {
      return 0;
    }
    else {
      return 1;
    }
  }
}

