#include "ErrorAPI.h"
#include "ParsedErrorAPI.h"
#include <stdlib.h>

/*{{{  static char *PERR_lowerStrCon(PERR_StrCon str) */

static char *PERR_lowerStrCon(PERR_StrCon str)
{
  return PERR_getStrConString(str);
}

/*}}}  */
/*{{{  static PERR_NatCon ERR_liftNatCon(int natcon) */

static int PERR_lowerNatCon(PERR_NatCon pNatcon)
{
  return atoi(PERR_getNatConString(pNatcon));
}

/*}}}  */

/*{{{  PERR_Area ERR_liftArea(ERR_Area area) */

ERR_Area PERR_lowerArea(PERR_Area pArea)
{
  int beginLine;
  int beginColumn;
  int endLine;
  int endColumn;
  int offset;
  int length;
  PERR_NatCon pBeginLine;
  PERR_NatCon pBeginColumn;
  PERR_NatCon pEndLine;
  PERR_NatCon pEndColumn;
  PERR_NatCon pOffset;
  PERR_NatCon pLength;

  if (PERR_isAreaArea(pArea)) {
    pBeginLine = PERR_getAreaBeginLine(pArea);
    pBeginColumn = PERR_getAreaBeginColumn(pArea);
    pEndLine = PERR_getAreaEndLine(pArea);
    pEndColumn = PERR_getAreaEndColumn(pArea);
    pOffset = PERR_getAreaOffset(pArea);
    pLength = PERR_getAreaLength(pArea);

    beginLine = PERR_lowerNatCon(pBeginLine);
    beginColumn = PERR_lowerNatCon(pBeginColumn);
    endLine = PERR_lowerNatCon(pEndLine);
    endColumn = PERR_lowerNatCon(pEndColumn);
    offset = PERR_lowerNatCon(pOffset);
    length = PERR_lowerNatCon(pLength);

    return ERR_makeAreaArea(beginLine, beginColumn, endLine, endColumn, offset, length);
  }
  else {
    return ERR_makeAreaNoArea();
  }
}

/*}}}  */
/*{{{  PERR_Location ERR_liftLocation(ERR_Location pLocation) */

ERR_Location PERR_lowerLocation(PERR_Location pLocation)
{
  char *filename;
  ERR_Area area;
  PERR_StrCon pFilename;
  PERR_Area pArea;

  if (PERR_isLocationLocation(pLocation)) {
    pFilename = PERR_getLocationFilename(pLocation);
    pArea = PERR_getLocationArea(pLocation);

    filename = PERR_lowerStrCon(pFilename);
    area = PERR_lowerArea(pArea);

    return ERR_makeLocationLocation(filename, area);
  }
  else {
    return ERR_makeLocationNoLocation();
  }
}

/*}}}  */
/*{{{  ERR_Subject PERR_lowerSubject(PERR_Subject subject) */

ERR_Subject PERR_lowerSubject(PERR_Subject pSubject)
{
  char *description;
  ERR_Location location;
  PERR_StrCon pDescription;
  PERR_Location pLocation;

  pDescription = PERR_getSubjectDescription(pSubject);
  pLocation = PERR_getSubjectLocation(pSubject);
  
  description = PERR_lowerStrCon(pDescription);
  location = PERR_lowerLocation(pLocation);
  
  return ERR_makeSubjectSubject(description, location);
}

/*}}}  */
/*{{{  ERR_SubjectList PERR_lowerSubjects(PERR_SubjectList subjects) */

ERR_SubjectList PERR_lowerSubjects(PERR_SubjectList pSubjects)
{
  ERR_SubjectList subjects = ERR_makeSubjectListEmpty();


  while (!PERR_isSubjectListEmpty(pSubjects)) { 
    PERR_Subject pSubject = PERR_getSubjectListHead(pSubjects);
    ERR_Subject subject = PERR_lowerSubject(pSubject);
    subjects = ERR_makeSubjectListMany(subject, subjects);
    if (PERR_hasSubjectListTail(pSubjects)) {
      pSubjects = PERR_getSubjectListTail(pSubjects);
    }
    else {
      break;
    }
  }

  return subjects;
}

/*}}}  */
/*{{{  PERR_Feedback ERR_liftFeedback(ERR_Feedback feedback) */

ERR_Feedback PERR_lowerFeedback(PERR_Feedback pFeedback)
{
  PERR_StrCon pDescription;
  PERR_SubjectList pSubjects;
  char *description;
  ERR_SubjectList subjects;

  pDescription = PERR_getFeedbackDescription(pFeedback);
  pSubjects = PERR_getFeedbackList(pFeedback);

  description = PERR_lowerStrCon(pDescription);
  subjects = PERR_lowerSubjects(pSubjects);

  if (PERR_isFeedbackInfo(pFeedback)) {
    return ERR_makeFeedbackInfo(description, subjects);
  }
  else if (PERR_isFeedbackWarning(pFeedback)) {
    return ERR_makeFeedbackWarning(description, subjects);
  }
  else if (PERR_isFeedbackError(pFeedback)) {
    return ERR_makeFeedbackError(description, subjects);
  }
  else if (PERR_isFeedbackFatalError(pFeedback)) {
    return ERR_makeFeedbackFatalError(description, subjects);
  }
  else {
    ATerror("unknown feedback type: %t\n", pFeedback);
    return NULL;
  }
}
