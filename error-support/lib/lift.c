#include "ErrorAPI.h"
#include "ParsedErrorAPI.h"

/*{{{  static PERR_StrCon ERR_liftStrCon(const char *str) */

static PERR_StrCon ERR_liftStrCon(const char *str)
{
  ATerm quotedAppl = (ATerm) ATmakeAppl0(ATmakeAFun(str, 0, ATtrue));
  return PERR_makeStrConString(ATwriteToString(quotedAppl));
}

/*}}}  */
/*{{{  static PERR_NatCon ERR_liftNatCon(int natcon) */

static PERR_NatCon ERR_liftNatCon(int natcon)
{
  ATerm atint = (ATerm) ATmakeInt(natcon);
  return PERR_makeNatConString(ATwriteToString(atint));
}

/*}}}  */

/*{{{  PERR_Area ERR_liftArea(ERR_Area area) */

PERR_Area ERR_liftArea(ERR_Area area)
{
  int beginLine;
  int beginColumn;
  int endLine;
  int endColumn;
  int beginOffset;
  int endOffset;
  PERR_NatCon pBeginLine;
  PERR_NatCon pBeginColumn;
  PERR_NatCon pEndLine;
  PERR_NatCon pEndColumn;
  PERR_NatCon pBeginOffset;
  PERR_NatCon pEndOffset;
  PERR_OptLayout e;

  if (ERR_isAreaArea(area)) {
    beginLine = ERR_getAreaBeginLine(area);
    beginColumn = ERR_getAreaBeginColumn(area);
    endLine = ERR_getAreaEndLine(area);
    endColumn = ERR_getAreaEndColumn(area);
    beginOffset = ERR_getAreaBeginOffset(area);
    endOffset = ERR_getAreaEndOffset(area);

    pBeginLine = ERR_liftNatCon(beginLine);
    pBeginColumn = ERR_liftNatCon(beginColumn);
    pEndLine = ERR_liftNatCon(endLine);
    pEndColumn = ERR_liftNatCon(endColumn);
    pBeginOffset = ERR_liftNatCon(beginOffset);
    pEndOffset = ERR_liftNatCon(endOffset);
    e = PERR_makeOptLayoutAbsent();

    return PERR_makeAreaArea(e,e,
			    pBeginLine,
			    e,e,
			    pBeginColumn,
			    e,e,
			    pEndLine,
			    e,e,
			    pEndColumn,
			    e,e,
			    pBeginOffset,
			    e,e,
			    pEndOffset,
			    e);
  }
  else {
    return PERR_makeAreaNoArea();
  }
}

/*}}}  */
/*{{{  PERR_Location ERR_liftLocation(ERR_Location location) */

PERR_Location ERR_liftLocation(ERR_Location location)
{
  char *filename;
  ERR_Area area;
  PERR_StrCon pFilename;
  PERR_Area pArea;
  PERR_OptLayout e;

  if (ERR_isLocationLocation(location)) {
    filename = ERR_getLocationFilename(location);
    area = ERR_getLocationArea(location);

    pFilename = ERR_liftStrCon(filename);
    pArea = ERR_liftArea(area);
    e = PERR_makeOptLayoutAbsent();

    return PERR_makeLocationLocation(e,e,
				     pFilename,
				     e,e,
				     pArea,
				     e);
  }
  else {
    return PERR_makeLocationNoLocation();
  }
}

/*}}}  */
/*{{{  PERR_Subject ERR_liftSubject(ERR_Subject subject) */

PERR_Subject ERR_liftSubject(ERR_Subject subject)
{
  char *description;
  ERR_Location location;
  PERR_StrCon pDescription;
  PERR_Location pLocation;
  PERR_OptLayout e = PERR_makeOptLayoutAbsent();

  description = ERR_getSubjectDescription(subject);
  location = ERR_getSubjectLocation(subject);
  
  pDescription = ERR_liftStrCon(description);
  pLocation = ERR_liftLocation(location);
  
  return PERR_makeSubjectSubject(e,e,
				 pDescription,
				 e,e,
				 pLocation,
				 e);
}

/*}}}  */
/*{{{  PERR_SubjectList ERR_liftSubjects(ERR_SubjectList subjects) */

PERR_SubjectList ERR_liftSubjects(ERR_SubjectList subjects)
{
  PERR_SubjectList pSubjects = PERR_makeSubjectListEmpty();
  PERR_OptLayout e = PERR_makeOptLayoutAbsent();

  for ( ; !ERR_isSubjectListEmpty(subjects); 
	subjects = ERR_getSubjectListTail(subjects)) {
    ERR_Subject subject = ERR_getSubjectListHead(subjects);
    PERR_Subject pSubject = ERR_liftSubject(subject);
    pSubjects = PERR_makeSubjectListMany(pSubject,e,e,pSubjects);
  }

  return pSubjects;
}

/*}}}  */
/*{{{  PERR_Feedback ERR_liftFeedback(ERR_Feedback feedback) */

PERR_Feedback ERR_liftFeedback(ERR_Feedback feedback)
{
  char *producer;
  char *description;
  ERR_SubjectList subjects;
  PERR_StrCon pProducer;
  PERR_StrCon pDescription;
  PERR_SubjectList pSubjects;
  PERR_OptLayout e;

  producer = ERR_getFeedbackProducer(feedback);
  description = ERR_getFeedbackDescription(feedback);
  subjects = ERR_getFeedbackList(feedback);

  pProducer = ERR_liftStrCon(producer);
  pDescription = ERR_liftStrCon(description);
  pSubjects = ERR_liftSubjects(subjects);
  e = PERR_makeOptLayoutAbsent();

  if (ERR_isFeedbackInfo(feedback)) {
    return PERR_makeFeedbackInfo(e,e,
				pProducer,
				e,e,
				pDescription,
				e,e,e,
				pSubjects,
				e,e);
  }
  else if (ERR_isFeedbackWarning(feedback)) {
    return PERR_makeFeedbackWarning(e,e,
				   pProducer,
				   e,e,
				   pDescription,
				   e,e,e,
				   pSubjects,
				   e,e);
  }
  else if (ERR_isFeedbackError(feedback)) {
    return PERR_makeFeedbackError(e,e,
				 pProducer,
				 e,e,
				 pDescription,
				 e,e,e,
				 pSubjects,
				 e,e);
  }
  else if (ERR_isFeedbackFatalError(feedback)) {
    return PERR_makeFeedbackFatalError(e,e,
				      pProducer,
				      e,e,
				      pDescription,
				      e,e,e,
				      pSubjects,
				      e,e);
  }
  else {
    ATerror("unknown feedback type: %t\n", feedback);
    return NULL;
  }
}
