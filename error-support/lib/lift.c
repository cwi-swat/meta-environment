#include "ErrorAPI.h"
#include "ParsedErrorAPI.h"

/*{{{  static PME_String ME_liftString(const char *str) */

static PME_String ME_liftString(const char *str)
{
  ATerm quotedAppl = (ATerm) ATmakeAppl0(ATmakeAFun(str, 0, ATtrue));
  return PME_makeStringString(ATwriteToString(quotedAppl));
}

/*}}}  */
/*{{{  static PME_NatCon ME_liftNatCon(int natcon) */

static PME_NatCon ME_liftNatCon(int natcon)
{
  ATerm atint = (ATerm) ATmakeInt(natcon);
  return PME_makeNatConString(ATwriteToString(atint));
}

/*}}}  */

/*{{{  PME_Area ME_liftArea(ME_Area area) */

PME_Area ME_liftArea(ME_Area area)
{
  int startLine;
  int startColumn;
  int endLine;
  int endColumn;
  int startOffset;
  int endOffset;
  PME_NatCon pStartLine;
  PME_NatCon pStartColumn;
  PME_NatCon pEndLine;
  PME_NatCon pEndColumn;
  PME_NatCon pStartOffset;
  PME_NatCon pEndOffset;
  PME_OptLayout e;

  if (ME_isAreaArea(area)) {
    startLine = ME_getAreaStartLine(area);
    startColumn = ME_getAreaStartColumn(area);
    endLine = ME_getAreaEndLine(area);
    endColumn = ME_getAreaEndColumn(area);
    startOffset = ME_getAreaStartOffset(area);
    endOffset = ME_getAreaEndOffset(area);

    pStartLine = ME_liftNatCon(startLine);
    pStartColumn = ME_liftNatCon(startColumn);
    pEndLine = ME_liftNatCon(endLine);
    pEndColumn = ME_liftNatCon(endColumn);
    pStartOffset = ME_liftNatCon(startOffset);
    pEndOffset = ME_liftNatCon(endOffset);
    e = PME_makeOptLayoutAbsent();

    return PME_makeAreaArea(e,e,
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
    return PME_makeAreaNoArea();
  }
}

/*}}}  */
/*{{{  PME_Location ME_liftLocation(ME_Location location) */

PME_Location ME_liftLocation(ME_Location location)
{
  char *filename;
  ME_Area area;
  PME_String pFilename;
  PME_Area pArea;
  PME_OptLayout e;

  filename = ME_getLocationFilename(location);
  area = ME_getLocationArea(location);

  pFilename = ME_liftString(filename);
  pArea = ME_liftArea(area);
  e = PME_makeOptLayoutAbsent();

  return PME_makeLocationLocation(e,e,
				  pFilename,
				  e,e,
				  pArea,
				  e);
  
}

/*}}}  */
/*{{{  PME_Subject ME_liftSubject(ME_Subject subject) */

PME_Subject ME_liftSubject(ME_Subject subject)
{
  char *id;
  ME_Location location;
  PME_String pId;
  PME_Location pLocation;
  PME_OptLayout e = PME_makeOptLayoutAbsent();

  id = ME_getSubjectId(subject);
  pId = ME_liftString(id);

  if (ME_hasSubjectLocation(subject)) {
    location = ME_getSubjectLocation(subject);
    pLocation = ME_liftLocation(location);
    return PME_makeSubjectLocatable(e,e,
				    pId,
				    e,e,
				    pLocation,
				    e);
  }
  else {
    return PME_makeSubjectUnlocatable(e,e,
				      pId,
				      e);
  }
}

/*}}}  */
/*{{{  PME_SubjectList ME_liftSubjects(ME_SubjectList subjects) */

PME_SubjectList ME_liftSubjects(ME_SubjectList subjects)
{
  PME_SubjectList pSubjects = PME_makeSubjectListEmpty();
  PME_OptLayout e = PME_makeOptLayoutAbsent();

  for ( ; !ME_isSubjectListEmpty(subjects); 
	subjects = ME_getSubjectListTail(subjects)) {
    ME_Subject subject = ME_getSubjectListHead(subjects);
    PME_Subject pSubject = ME_liftSubject(subject);
    pSubjects = PME_makeSubjectListMany(pSubject,e,e,pSubjects);
  }

  return pSubjects;
}

/*}}}  */
/*{{{  PME_Feedback ME_liftFeedback(ME_Feedback feedback) */

PME_Feedback ME_liftFeedback(ME_Feedback feedback)
{
  char *id;
  char *producerId;
  char *producerType;
  char *description;
  ME_SubjectList subjects;
  PME_String pId;
  PME_String pProducerId;
  PME_String pProducerType;
  PME_String pDescription;
  PME_SubjectList pSubjects;
  PME_OptLayout e;

  id = ME_getFeedbackId(feedback);
  producerId = ME_getFeedbackProducerId(feedback);
  producerType = ME_getFeedbackProducerType(feedback);
  description = ME_getFeedbackDescription(feedback);
  subjects = ME_getFeedbackList(feedback);

  pId = ME_liftString(id);
  pProducerId = ME_liftString(producerId);
  pProducerType = ME_liftString(producerType);
  pDescription = ME_liftString(description);
  pSubjects = ME_liftSubjects(subjects);
  e = PME_makeOptLayoutAbsent();

  if (ME_isFeedbackInfo(feedback)) {
    return PME_makeFeedbackInfo(e,e,
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
  else if (ME_isFeedbackWarning(feedback)) {
    return PME_makeFeedbackWarning(e,e,
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
  else if (ME_isFeedbackError(feedback)) {
    return PME_makeFeedbackError(e,e,
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
  else if (ME_isFeedbackFatalError(feedback)) {
    return PME_makeFeedbackFatalError(e,e,
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
