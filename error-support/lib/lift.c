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
  int startLine;
  int startColumn;
  int endLine;
  int endColumn;
  int startOffset;
  int endOffset;
  PERR_NatCon pStartLine;
  PERR_NatCon pStartColumn;
  PERR_NatCon pEndLine;
  PERR_NatCon pEndColumn;
  PERR_NatCon pStartOffset;
  PERR_NatCon pEndOffset;
  PERR_OptLayout e;

  if (ERR_isAreaArea(area)) {
    startLine = ERR_getAreaStartLine(area);
    startColumn = ERR_getAreaStartColumn(area);
    endLine = ERR_getAreaEndLine(area);
    endColumn = ERR_getAreaEndColumn(area);
    startOffset = ERR_getAreaStartOffset(area);
    endOffset = ERR_getAreaEndOffset(area);

    pStartLine = ERR_liftNatCon(startLine);
    pStartColumn = ERR_liftNatCon(startColumn);
    pEndLine = ERR_liftNatCon(endLine);
    pEndColumn = ERR_liftNatCon(endColumn);
    pStartOffset = ERR_liftNatCon(startOffset);
    pEndOffset = ERR_liftNatCon(endOffset);
    e = PERR_makeOptLayoutAbsent();

    return PERR_makeAreaArea(e,e,
			    pStartLine,
			    e,e,
			    pStartColumn,
			    e,e,
			    pEndLine,
			    e,e,
			    pEndColumn,
			    e,e,
			    pStartOffset,
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
  char *id;
  ERR_Location location;
  PERR_StrCon pId;
  PERR_Location pLocation;
  PERR_OptLayout e = PERR_makeOptLayoutAbsent();

  id = ERR_getSubjectId(subject);
  location = ERR_getSubjectLocation(subject);
  
  pId = ERR_liftStrCon(id);
  pLocation = ERR_liftLocation(location);
  
  return PERR_makeSubjectSubject(e,e,
				 pId,
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
  char *id;
  char *producerId;
  char *producerType;
  char *description;
  ERR_SubjectList subjects;
  PERR_StrCon pId;
  PERR_StrCon pProducerId;
  PERR_StrCon pProducerType;
  PERR_StrCon pDescription;
  PERR_SubjectList pSubjects;
  PERR_OptLayout e;

  id = ERR_getFeedbackId(feedback);
  producerId = ERR_getFeedbackProducerId(feedback);
  producerType = ERR_getFeedbackProducerType(feedback);
  description = ERR_getFeedbackDescription(feedback);
  subjects = ERR_getFeedbackList(feedback);

  pId = ERR_liftStrCon(id);
  pProducerId = ERR_liftStrCon(producerId);
  pProducerType = ERR_liftStrCon(producerType);
  pDescription = ERR_liftStrCon(description);
  pSubjects = ERR_liftSubjects(subjects);
  e = PERR_makeOptLayoutAbsent();

  if (ERR_isFeedbackInfo(feedback)) {
    return PERR_makeFeedbackInfo(e,e,
				pId, 
				e,e,
				pProducerId,
				e,e,
				pProducerType,
				e,e,
				pDescription,
				e,e,e,
				pSubjects,
				e,e);
  }
  else if (ERR_isFeedbackWarning(feedback)) {
    return PERR_makeFeedbackWarning(e,e,
				   pId, 
				   e,e,
				   pProducerId,
				   e,e,
				   pProducerType,
				   e,e,
				   pDescription,
				   e,e,e,
				   pSubjects,
				   e,e);
  }
  else if (ERR_isFeedbackError(feedback)) {
    return PERR_makeFeedbackError(e,e,
				 pId, 
				 e,e,
				 pProducerId,
				 e,e,
				 pProducerType,
				 e,e,
				 pDescription,
				 e,e,e,
				 pSubjects,
				 e,e);
  }
  else if (ERR_isFeedbackFatalError(feedback)) {
    return PERR_makeFeedbackFatalError(e,e,
				      pId, 
				      e,e,
				      pProducerId,
				      e,e,
				      pProducerType,
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
